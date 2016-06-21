#include "Menu.h"

void Menu::setInSystem(bool inSystem) {
    this->inSystem = inSystem;
}


Menu::Menu() {
    setInSystem(true);
}

//program main function. the whole menu will run here
void Menu::program() {
    while(inSystem){
        printMenu();
        cin >> choice;
        switch(choice){
            case 0:
                cout<< "Bye...";
                inSystem=false;
                break;
            case 1:
                cout<< "Please write location to create directory or leave empty";
                cin>>location;
                //if exist
                //send to create dir
                break;
            case 2:
                cout<< "Please write location to create file or leave empty";
                cin>>location;
                //if exist
                //send to create file
                break;
            case 3:
                //copy files to same location
                //add obj pointer to file/dir name
                break;
            case 4:
                cout<< "Please write location to delete with the file/dir name at the end";
                cin>>location;
                //if exist
                //delete file/dir
                break;
            case 5:
                cout<< "Please write the location of the dir you want to print it's content or leave empty to print the content of the root";
                cin>>location;
                //if exist
                //print content
                break;
            case 6:
                //print all content of the root and children's to file
                break;
            default:
                cin.clear();
                cin.ignore();
                cout << "Not a Valid Choice. \n" << "Choose again.\n";
                break;
        }
    }
}

void Menu::printMenu() {
        cout << "*******************************\n";
        cout << "Hello!\n";
        cout << " 0 - close system.\n";
        cout << " 1 - create directory.\n";
        cout << " 2 - create file.\n";
        cout << " 3 - clone object.\n";
        cout << " 4 - delete object.\n";
        cout << " 5 - print object content.\n";
        cout << " 6 - print root and children's content to file.\n";
        cout << "what do you wish to do?\n";
}
