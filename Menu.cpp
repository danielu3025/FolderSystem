#include "Menu.h"
#include <iostream>
#include <sstream>
#include "Root.h"

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
    Object* toRetun = nullptr;
    Object* temp = &Root;
    int pIndex = 0;
    vector<string>pathList = split(path, '/');
    string finel = pathList[pathList.size()-1];
    string serch = pathList[pIndex];
    vector<Object*>list = temp->getContent();
    bool found = false;
    while (!found) {
        if (serch == temp->getName()) {
            if (temp->getName() == finel) {
                toRetun = temp;
                cout<<"object found\n";
                break;
            }
            serch = pathList[++pIndex];
            list = temp->getContent();
            for (int i =0; i<(temp->getContent()).size(); i++) {
                if (serch == list[i]->getName()) {
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
    return toRetun;
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
    FileBuilder* fileBuilder = new (FileBuilder);
    DirBuilder* dirBuilder = new (DirBuilder);
    ObjDirector* director = nullptr;
    while(inSystem){
        printMenu();
        cin >> choice;
        switch(choice){
            case 0:
                cout<<"Bye...\n";
                inSystem=false;
                break;
            case 1:{
                Object* temp = nullptr;
                cout<< "Please write location to create directory or leave empty";
                cin>>location;
                temp = findObj(location,root);
                if (temp == nullptr) {
                    cout <<"drictory not found";
                }
                //if exist
                //send to create dir
                else{
                    
                    Dir* tempFolder  = nullptr;
                    try {
                        /*
                        
                         */
                        tempFolder = dynamic_cast<Dir*>(temp);
                        if (tempFolder == nullptr) {
                            throw exception_ptr();
                        }
                        else{
                            director = new ObjDirector(dirBuilder);
                            if (!(tempFolder->setContent(director->getObj()))){
                                cout<<"problem  while creating\n";
                            }
                            else{
                                cout<<"sucsess\n";
                            }
                        }
                    } catch (exception_ptr) {
                        cout<<"problem  while creating\n";
                    }
                
                }
                break;
            }
            case 2:{
                Object* temp = nullptr;
                cout<< "Please write location to create file or leave empty";
                cin>>location;
                temp = findObj(location,root);
                if (temp == nullptr) {
                    cout <<"drictory not found";
                }
                //if exist
                //send to create dir
                else{
                    Dir* tempFolder  = nullptr;
                    try {
                        tempFolder = dynamic_cast<Dir*>(temp);
                        if (tempFolder == nullptr) {
                            throw exception_ptr();
                        }
                        else{
                            director = new ObjDirector(fileBuilder);
                            if (!(tempFolder->setContent(director->getObj()))){
                                cout<<"problem  while creating\n";
                            }
                            else{
                                cout<<"sucsess\n";
                            }
                        }
                    } catch (exception_ptr) {
                        cout<<"problem  while creating\n";
                    }
                }
                //if exist
                //send to create file
                break;
            }
            case 3:{
                Object* temp = nullptr;
                Object* tempFather = nullptr;
                cout<<"enter object to copy:";
                cin>>location;
                vector<string> fatherFolderVector;
                string fatherFolderString;
                //copy files to same location
                temp = findObj(location, root);
                if (temp != nullptr) {
                    fatherFolderVector = split(location, '/');
                    fatherFolderVector.pop_back() ;
                    Dir* fatherFolder;
                    for (int i =0; i<fatherFolderVector.size(); i++) {
                        fatherFolderString = fatherFolderString + fatherFolderVector[i];
                    }
                   tempFather = findObj(fatherFolderString, root);
                    fatherFolder->setContent(temp->makeCopy());
                    
                }
                else{
                    cout <<"object not found";
                }
                //add obj pointer to file/dir name
                break;
            }
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
