#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

const int MENU_SIZE = 8;

void printMenu(int selectedOption) {
    system("cls");
    for (int i = 0; i < MENU_SIZE; ++i) {
        if (i == selectedOption) {
            cout << "\033[1;37;42m";
        }
        cout << "Item " << i + 1 << "\t";
        if (i == selectedOption) {
            cout << "\033[0m";
        }
        cout << endl;
    }
    cout << "\nPress Enter to select an item or press Esc to exit." << endl;
}

void processSelection(int selectedOption) {
    system("cls");
    if (selectedOption >= 0 && selectedOption < MENU_SIZE) {
        cout << "Price information for Item " << selectedOption + 1 << ": ";
        switch (selectedOption) {
            case 0:
                cout << "The current gold price is $1,500 per ounce" << endl;
                break;
            case 1:
                cout << "Gold is priced at $1,600 per ounce right now" << endl;
                break;
            case 2:
                cout << "The current gold price is $1,700 per ounce" << endl;
                break;
            case 3:
                cout << "Gold is priced at $1,800 per ounce right now" << endl;
                break;
            case 4:
                cout << "The current price of silver is $20 per ounce" << endl;
                break;
            case 5:
                cout << "Silver is priced at $25 per ounce right now" << endl;
                break;
            case 6:
                cout << "The current price of platinum is $900 per ounce" << endl;
                break;
            case 7:
                cout << "Platinum is priced at $1,000 per ounce right now" << endl;
                break;
            default:
                cout << "Invalid option!" << endl;
                break;
        }
    } else {
        cout << "Invalid option!" << endl;
    }
    cout << "\nPress any key to continue..." << endl;
    _getch();
}

int main() {
    int selectedOption = 0;

    while (true) {
        printMenu(selectedOption);

        char key = _getch();
        switch (key) {
            case 13:  
                processSelection(selectedOption);
                break;
            case 27: 
                return 0;  
            case 72:  
                selectedOption = (selectedOption - 1 + MENU_SIZE) % MENU_SIZE;
                break;
            case 80: 
                selectedOption = (selectedOption + 1) % MENU_SIZE;
                break;
            default:
                break;
        }
    }

    return 0;
}
