#include "Menu.h"
#include <iostream>
#include <sstream>
#include "Root.h"
#include <string>
#include <exception>

Object* ClonAble::dirType = 0;
Object* ClonAble::fileType = 0;
vector<string>split(string str, char delimiter) {
    vector<string> internal;
    stringstream ss(str); // Turn the string into a stream.
    string tok;

    while(getline(ss, tok, delimiter)) {
        internal.push_back(tok);
    }

    return internal;
}
Object* findObj(string path,Dir Root){
    Object* toReturn = NULL;
    Object* temp = &Root;
    int pIndex = 0;
    vector<string>pathList = split(path, '/');
    string final = pathList[pathList.size()-1];
    string search = pathList[pIndex];
    vector<Object*>list = temp->getContent();
    bool found = false;
    while (!found) {
        if (search == temp->getName()) {
            if (temp->getName() == final) {
                toReturn = temp;
                cout<<"object found\n";
                return toReturn;
            }
            search = pathList[++pIndex];
            list = temp->getContent();
            for (int i =0; i<(temp->getContent()).size(); i++) {
                if (search == list[i]->getName()) {
                    temp = list[i];
                    found = false;
                    break;
                }
                found = true;
            }
        }
        else{
            break;
        }
    }
    return toReturn;
}


void Menu::setInSystem(bool inSystem) {
    this->inSystem = inSystem;
}
Menu::Menu() {
    setInSystem(true);
}

//program main function. the whole menu will run here
void Menu::program() {
    Dir root = Root::getInstance();
    ClonAble::initialize();
    ObjDirector* director = NULL;
    Object* temp = NULL;

    while(inSystem){
        printMenu();
        cin >>choice;
        switch(choice){
            case '1': {
                cout << "Bye...\n";
                inSystem = false;
                break;
                case '2':
                    temp = NULL;
                cout << "Please write location to create directory or leave empty\n";
                cin >> location;
                if (location != "\"\"" && location != "" && location != "ROOT") {
                    temp = findObj(location, root);
                    if (temp == NULL) {
                        cout << "directory not found\n";
                    }
                    else {
                        try {
                            Dir *tempFolder = dynamic_cast<Dir *>(temp);
                            DirBuilder *dirBuilder = new (DirBuilder);
                            director = new ObjDirector(dirBuilder);
                            if (!(tempFolder->setContent(director->getObj()))) {
                                cout << "problem  while creating\n";
                            }
                            else {
                                cout << "success\n";
                            }
                        } catch (exception) {
                            cout << "problem  while creating\n";
                        }
                    }
                }
                else {
                    DirBuilder *dirBuilder = new (DirBuilder);
                    director = new ObjDirector(dirBuilder);
                    root.setContent(director->getObj());
                }
                cin.clear();
                cin.ignore();
                break;
            }
            case '3': {
                temp = NULL;
                cout << "Please write location to create directory or leave empty\n";
                cin >> location;
                if (location != "\"\"" && location != "" && location != "ROOT") {
                    temp = findObj(location, root);
                    if (temp == NULL) {
                        cout << "directory not found\n";
                    }
                    else {
                        try {
                            Dir *tempFolder = dynamic_cast<Dir *>(temp);
                            FileBuilder *fileBuilder = new (FileBuilder);
                            director = new ObjDirector(fileBuilder);
                            if (!(tempFolder->setContent(director->getObj()))) {
                                cout << "problem  while creating\n";
                            }
                            else {
                                cout << "success\n";
                            }
                        } catch (exception) {
                            cout << "problem  while creating\n";
                        }
                    }
                }
                else {
                    FileBuilder *fileBuilder = new (FileBuilder);
                    director = new ObjDirector(fileBuilder);
                    root.setContent(director->getObj());
                }
                cin.clear();
                cin.ignore();
                break;
            }
            case '4': {
                temp = NULL;
                Object *tempFather = NULL;
                cout << "enter object to copy:";
                cin >> location;
                vector<string> fatherFolderVector;
                string fatherFolderString;
                //copy files to same location
                temp = findObj(location, root);
                if (temp != NULL) {
                    fatherFolderVector = split(location, '/');
                    fatherFolderVector.pop_back();
                    Dir *fatherFolder;
                    for (int i = 0; i < fatherFolderVector.size(); i++) {
                        //fatherFolderString = fatherFolderString + fatherFolderVector[i];
                    }
                    tempFather = findObj(fatherFolderString, root);
                    if (fatherFolderString == "ROOT") {
                        root.setContent(temp->makeCopy());
                    }
                    else {
                        fatherFolder = dynamic_cast<Dir *>(tempFather);
                        fatherFolder->setContent(temp->makeCopy());
                    }
                }
                else {
                    cout << "object not found";
                }
                //add obj pointer to file/dir name
                cin.clear();
                cin.ignore();
                break;
            }
            case '5': {
                temp = NULL;
                cout << "write location:";
                cin >> location;
                if (location != "\"\"" && location != "" && location != "ROOT") {
                    temp = findObj(location, root);
                    if (temp == NULL) {
                        cout << "directory not found\n";
                    }else {
                        cout << temp->getName() << " is deleted\n";
                        temp->deleteObj();
                    }
                }else {
                    cout << root.getName() << " is deleted\n";
                    root.deleteObj();
                }
                cin.clear();
                cin.ignore();
                break;
                case '6':
                    temp = NULL;
                    cout << "write location:";
                    cin >> location;
                    if (location != "\"\"" && location != "" && location != "ROOT") {
                        temp = findObj(location, root);
                        if (temp == NULL) {
                            cout << "directory not found\n";
                        }else{
                            temp->showContent(0);
                        }
                    }else {
                        root.showContent(0);
                    }
                    cin.clear();
                    cin.ignore();
                    break;
            }
            case '7': {
                root.printToFile(myFile, 0);
                break;
            }
            default:
            {
                cout << "Not a Valid Choice. \n" << "Choose again.\n";
                cin.clear();
                cin.ignore();
                break;
            }
        }
    }
}
Menu::~Menu(){
}

void Menu::printMenu() {
        cout << "*******************************\n";
        cout << "Hello!\n";
        cout << " 1 - close system.\n";
        cout << " 2 - create directory.\n";
        cout << " 3 - create file.\n";
        cout << " 4 - clone object.\n";
        cout << " 5 - delete object.\n";
        cout << " 6 - print object content.\n";
        cout << " 7 - print root and children's content to file.\n";
        cout << "what do you wish to do?\n";
}
