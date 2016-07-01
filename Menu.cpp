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
Object* findObjFather(string path,Dir Root){
    Object* toReturn = NULL;
    Object* temp = &Root;
    int pIndex = 0;
    vector<string>pathList = split(path, '/');
    pathList.pop_back();
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
    int choice = 0;
    Dir root = Root::getInstance();
    
    ClonAble::initialize();
    ObjDirector* director = NULL;

    while(inSystem){
        printMenu();
        cin >> choice;
        switch(choice){
            case 0:
                cout<<"Bye...\n";
                inSystem=false;
                cin.clear();
                cin.ignore();
                
                break;
            case 1:{
                Object* temp = NULL;
                cout<< "Please write location to create directory or leave empty\n";
                cin>>location;
                if(location != "\"\"" && location != "" && location != "ROOT") {
                    temp = findObj(location,root);
                    if (temp == NULL) {
                        cout <<"directory not found";
                    }
                    //if exist
                    //send to create dir
                    else{

                        try {
                            Dir* tempFolder = dynamic_cast<Dir*>(temp);
                            if (tempFolder == NULL) {
                                throw exception();
                            }
                            else{
                                DirBuilder* dirBuilder = new (DirBuilder);
                                director = new ObjDirector(dirBuilder);
                                if (!(tempFolder->setContent(director->getObj()))){
                                    cout<<"problem  while creating\n";
                                }
                                else{
                                    cout<<"success\n";
                                }
                            }
                        } catch (exception) {
                            cout<<"problem  while creating\n";
                        }

                    }
                }
                else{
                    DirBuilder* dirBuilder = new (DirBuilder);
                    director = new ObjDirector(dirBuilder);
                    root.setContent(director->getObj());
                }
                cin.clear();
                cin.ignore();
                break;

            }
            case 2:{
                Object* temp = NULL;
                cout<< "Please write location to create directory or leave empty\n";
                cin>>location;
                if(location != "\"\"" && location !="" && location != "ROOT") {
                    temp = findObj(location,root);
                    if (temp == NULL) {
                        cout <<"directory not found";
                    }
                    //if exist
                    //send to create dir
                    else{

                        try {
                            Dir* tempFolder = dynamic_cast<Dir*>(temp);
                            if (tempFolder == NULL) {
                                throw exception();
                            }
                            else{
                                FileBuilder* fileBuilder = new (FileBuilder);
                                director = new ObjDirector(fileBuilder);
                                if (!(tempFolder->setContent(director->getObj()))){
                                    cout<<"problem  while creating\n";
                                }
                                else{
                                    cout<<"success\n";
                                }
                            }
                        } catch (exception) {
                            cout<<"problem  while creating\n";
                        }

                    }
                }
                else{
                    FileBuilder* fileBuilder = new (FileBuilder);
                    director = new ObjDirector(fileBuilder);
                    root.setContent(director->getObj());
                }
                cin.clear();
                cin.ignore();
                break;
            }
            case 3:{
                Object* temp = NULL;
                Object* tempFather = NULL;
                cout<<"enter object to copy:";
                cin>>location;
                vector<string> fatherFolderVector;
                fatherFolderVector  = split(location, '/');
                fatherFolderVector.pop_back();
                //copy files to same location
                temp = findObj(location, root);
                if (temp != NULL) {
                    Dir* fatherFolder;
                   tempFather = findObjFather(location, root);
                
                    if( fatherFolderVector[fatherFolderVector.size()-1] == "ROOT"){
                        root.setContent(temp->makeCopy());
                    }
                    else{
                        fatherFolder=dynamic_cast<Dir*>(tempFather);
                        fatherFolder->setContent(temp->makeCopy());
                    }
                }
                else{
                    cout <<"object not found";
                }
                //add obj pointer to file/dir name
                cin.clear();
                cin.ignore();
                break;
            }
            case 4:{
                cout<< "Please write location to delete with the file/dir name at the end";
                cin>>location;
                //if exist
                //delete file/dir
                cin.clear();
                cin.ignore();
                break;
            case 5:
                cout<< "Please write the location of the dir you want to print it's content or leave empty to print the content of the root:\n";
                cin>>location;
                root.showContent(0);
                cin.clear();
                cin.ignore();
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
}
Menu::~Menu(){
    delete ClonAble::getDirType();
    delete ClonAble::getFileType();
    
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
