from django.urls import path
from .views import create_contact, list_contacts

urlpatterns = [
    path('contacts/', create_contact),
    path('contacts/list/', list_contacts),
]
