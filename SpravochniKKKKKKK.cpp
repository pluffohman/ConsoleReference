#include "Spravochnik.h"


int main() {
    Spravochnik spr;
    char ch;
    int menwovop = 1;

   while(true) {
        system("cls");
        cout << "Menu:" << endl;
        cout << (menwovop == 1 ? "* " : "  ") << "1. Search by firm" << endl;
        cout << (menwovop == 2 ? "* " : "  ") << "2. Search by name" << endl;
        cout << (menwovop == 3 ? "* " : "  ") << "3. Search by phone number" << endl;
        cout << (menwovop == 4 ? "* " : "  ") << "4. Search by occupation" << endl;
        cout << (menwovop == 5 ? "* " : "  ") << "5. Add user" << endl;
        cout << (menwovop == 6 ? "* " : "  ") << "6. Print all contacts" << endl;
        cout << (menwovop == 7 ? "* " : "  ") << "7. Exit" << endl;

        ch = _getch(); //ждем кнопочку

        switch (ch) {
        case 72: //ловим стрелку вверх
            menwovop = (menwovop == 1) ? 7 : menwovop - 1;
            break;
        case 80: //ловим стрелку вниз
            menwovop = (menwovop == 7) ? 1 : menwovop + 1;
            break;
        case 13: //ловим пробел
            switch (menwovop) {
            case 1: {
                string firm;
                cout << "Firm: ";
                cin >> firm;
                spr.searchbyfirm(firm);
                break;
                    }
            case 2: {
                string name;
                cout << "Name: ";
                cin >> name;
                spr.searchbyname(name);
                break;
                    }
            case 3: {
                int number;
                cout << "Phone number: ";
                cin >> number;
                spr.searchbynumber(number);
                break;
                    }
            case 4: {
                string occupation;
                cout << "Job: ";
                cin >> occupation;
                spr.searchbyrod(occupation);
                break;
                    }
            case 5: {
                int count;
                cout << "Quantity: ";
                cin >> count;
                spr.adduser(count);
                break;
                    }
            case 6: {
                spr.printall();
                break;
                    }
            case 7: {
                cout << "ExXXIT, NIGGA" << endl;
                return 0;
                    }
            }
            cout << "----------click smth pls----------";
            _getch(); //опять ждем кнопочку
        }
    }
}
