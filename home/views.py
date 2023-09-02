from rest_framework.decorators import api_view
from rest_framework.response import Response
from django.core.cache import cache
from .models import Contact
from .serializers import ContactSerializer

@api_view(['POST'])
def create_contact(request):
    serializer = ContactSerializer(data=request.data)
    if serializer.is_valid():
        contact = serializer.save()
        cache.set(f'contact_{contact.id}', contact)
        return Response(serializer.data, status=201)
    return Response(serializer.errors, status=400)

@api_view(['GET'])
def list_contacts(request):
    contacts = cache.get('all_contacts')
    if not contacts:
        contacts = Contact.objects.all()
        cache.set('all_contacts', contacts)
    serializer = ContactSerializer(contacts, many=True)
    return Response(serializer.data)
