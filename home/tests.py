from django.test import TestCase

# Create your tests here.from django.test import TestCase, Client
from django.urls import reverse
from .models import Contact

class ContactTestCase(TestCase):
    def setUp(self):
        self.client = Client()
        self.url = reverse('create_contact')
        self.data = {
            'name': 'John Doe',
            'email': 'johndoe@example.com',
            'message': 'This is a test message.'
        }

    def test_create_contact(self):
        response = self.client.post(self.url, self.data)
        self.assertEqual(response.status_code, 201)
        self.assertEqual(Contact.objects.count(), 1)
        contact = Contact.objects.first()
        self.assertEqual(contact.name, self.data['name'])
        self.assertEqual(contact.email, self.data['email'])
        self.assertEqual(contact.message, self.data['message'])

    def test_list_contacts(self):
        response = self.client.get(reverse('list_contacts'))
        self.assertEqual(response.status_code, 200)
        self.assertEqual(len(response.data), Contact.objects.count())
