// // This is the main file of the project for the c++ module for CSE 312

#include <iostream>
#include <vector>
#include <string>

// Define a Contact class to represent individual contacts.
class Contact {
public:
    std::string name;
    std::string phoneNumber;
    std::string email;

    // Constructor to initialize contact details.
    Contact(const std::string& n, const std::string& phone, const std::string& e)
        : name(n), phoneNumber(phone), email(e) {}
};

// Function to display a contact's details.
void displayContact(const Contact& contact) {
    std::cout << "Name: " << contact.name << std::endl;
    std::cout << "Phone Number: " << contact.phoneNumber << std::endl;
    std::cout << "Email: " << contact.email << std::endl;
}

// Function to delete a contact.
void deleteContact(std::vector<Contact>& addressBook) {
    std::cout << "Enter the name of the contact to delete: ";
    std::string searchName;
    std::cin.ignore();
    std::getline(std::cin, searchName);

    // Use an iterator to find the contact by name.
    auto it = addressBook.begin();
    bool contactFound = false;

    while (it != addressBook.end()) {
        if (it->name == searchName) {
            it = addressBook.erase(it); // Remove the contact from the vector.
            std::cout << "Contact deleted successfully." << std::endl;
            contactFound = true;
            break; // Exit the loop since the contact was found and deleted.
        }
        else {
            ++it;
        }
    }
    if (!contactFound) {
        std::cout << "Contact not found." << std::endl;
    }
}

// Function to edit contact
void editContact(std::vector<Contact>& addressBook) {
    std::cout << "Enter the name of the contact to edit: ";
    std::string searchName;
    std::cin.ignore();
    std::getline(std::cin, searchName);

    bool contactFound = false;
    // Search for the contact by name.
    for (Contact& contact : addressBook) {
        if (contact.name == searchName) {
            std::cout << "Enter new phone number: ";
            std::cin >> contact.phoneNumber;
            std::cout << "Enter new email: ";
            std::cin >> contact.email;
            std::cout << "Contact updated successfully." << std::endl;
            contactFound = true;
            break; // Exit the loop since the contact was found and edited.
        }
    }


    if (!contactFound) {
        std::cout << "Contact not found." << std::endl;
    }
}

int main() {
    std::vector<Contact> addressBook; // Store contacts in a vector.

    while (true) {
        // Display menu options.
        std::cout << "\nAddress Book Menu:" << std::endl;
        std::cout << "1. Add Contact" << std::endl;
        std::cout << "2. View Contacts" << std::endl;
        std::cout << "3. Edit Contact" << std::endl;
        std::cout << "4. Delete Contact" << std::endl;
        std::cout << "5. Exit" << std::endl;

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
        {// Add Contact
            std::string name, phone, email;
            std::cout << "Enter Name: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            std::cout << "Enter Phone Number: ";
            std::cin >> phone;
            std::cout << "Enter Email: ";
            std::cin >> email;
            addressBook.push_back(Contact(name, phone, email));
            std::cout << "Contact added successfully." << std::endl;
            break;
        }

        case 2: { // View Contacts
            std::cout << "\nContacts:\n";
            for (const Contact& contact : addressBook) {
                displayContact(contact);
                std::cout << "-----------------------" << std::endl;
            }
            break;
        }
        case 3: {// Edit Contact
            editContact(addressBook);
            break;
        }
        case 4: { // Delete Contact
            deleteContact(addressBook);
            break;
        }
        case 5: { // Exit
            std::cout << "Exiting the Address Book. Goodbye!" << std::endl;
            return 0;
        }
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
    }

    return 0;
}
