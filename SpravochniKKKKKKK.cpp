#include "Spravochnik.h" // Assuming the class is defined in Spravochnik.h
#include <conio.h>

int main() {
    Spravochnik spravochnik;
    char choice;
    int menuOption = 1; // Track the currently selected menu option

    do {
        system("cls"); // Clear screen for better visualization
        cout << "Menu:" << endl;
        cout << (menuOption == 1 ? "* " : "  ") << "1. Search by firm" << endl;
        cout << (menuOption == 2 ? "* " : "  ") << "2. Search by name" << endl;
        cout << (menuOption == 3 ? "* " : "  ") << "3. Search by phone number" << endl;
        cout << (menuOption == 4 ? "* " : "  ") << "4. Search by occupation" << endl;
        cout << (menuOption == 5 ? "* " : "  ") << "5. Add user" << endl;
        cout << (menuOption == 6 ? "* " : "  ") << "6. Print all contacts" << endl;
        cout << (menuOption == 7 ? "* " : "  ") << "7. Exit" << endl;

        choice = _getch(); // Get character input without waiting for enter key

        switch (choice) {
        case 72: // Up arrow key
            menuOption = (menuOption == 1) ? 7 : menuOption - 1;
            break;
        case 80: // Down arrow key
            menuOption = (menuOption == 7) ? 1 : menuOption + 1;
            break;
        case 13: // Enter key
            switch (menuOption) {
            case 1: {
                string firm;
                cout << "Enter firm name to search: ";
                cin >> firm;
                spravochnik.searchbyfirm(firm);
                break;
            }
            case 2: {
                string name;
                cout << "Enter name to search: ";
                cin >> name;
                spravochnik.searchbyname(name);
                break;
            }
            case 3: {
                int number;
                cout << "Enter phone number to search: ";
                cin >> number;
                spravochnik.searchbynumber(number);
                break;
            }
            case 4: {
                string occupation;
                cout << "Enter occupation to search: ";
                cin >> occupation;
                spravochnik.searchbyrod(occupation);
                break;
            }
            case 5: {
                int count;
                cout << "Enter number of users to add: ";
                cin >> count;
                spravochnik.adduser(count);
                break;
            }
            case 6: {
                spravochnik.printall();
                break;
            }
            case 7: {
                cout << "Exiting..." << endl;
                break;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
            }
            cout << "Press any key to continue...";
            _getch(); // Wait for any key press before continuing
            break;
        default: // Handle other keys
            break;
        }
    } while (choice != '7');

    return 0;
}
