#include "Menu.h"
#include <iostream>
#include <sstream>
#include "Root.h"
#include <string>
#include <exception>
#include "PrototypeMaker.h"


ClonAble* PrototypeMaker::dirPrototype=0;
ClonAble* PrototypeMaker::filePrototype=0;

Menu* System::sys =0;
Menu System::getInstance(){
    if (!sys) {
        sys = new Menu();
        
    }
    return *sys;
}

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
    masterRoot = new Root();
    masterRoot->setName("ROOT");
}
//program main function. the whole menu will run here
void Menu::program() {

    string location;
    ofstream myFile;
    Dir* root  = masterRoot;
    PrototypeMaker::initialize();
    Object* prototype = NULL;
    Object* temp = NULL;
    while((this->inSystem)){
        printMenu();
        cin >>choice;
        switch(choice){
            case '1': {
                cout << "Bye...\n";
                inSystem = true;
                cin.clear();
                cin.ignore();
                break;
            }
            case '2':{
                temp = NULL;
                cout << "Please write location to create directory or leave empty\n";
                cin >>location;
                if (location != "\"\"" && location != "" && location != "ROOT") {
                    temp = findObj(location, *root);
                    if (temp == NULL) {
                        cout << "directory not found\n";
                    }
                    else {
                        try {
                            Dir *tempFolder = dynamic_cast<Dir *>(temp);
                            prototype = (Object*)PrototypeMaker::getDirType();
                            if (!tempFolder->setContent(prototype)) {
                                cout << "problem  while creating\n";
                            }
                            else {
                                cout<< "enter folderName:";
                                cin>>prototype->name ;
                                cout << "success\n";
                            }
                        }
                        catch (exception) {
                            cout << "problem  while creating\n";
                        }
                    }
                }
                else {
                    prototype = (Object*)PrototypeMaker::getDirType();
                    root->setContent(prototype);
                    cout<< "enter folderName:";
                    cin>>prototype->name ;
                    cout << "success\n";
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
                    temp = findObj(location, *root);
                    if (temp == NULL) {
                        cout << "directory not found\n";
                    }
                    else {
                        try {
                            Dir *tempFolder = dynamic_cast<Dir *>(temp);
                            prototype = (Object*)PrototypeMaker::getFileType();
                            if (!tempFolder->setContent(prototype)) {
                                cout << "problem  while creating\n";
                            }
                            else {
                                cout<< "enter file name:";
                                cin>>prototype->name ;
                                cout << "success\n";
                            }
                        }
                        catch (exception) {
                            cout << "problem  while creating\n";
                        }
                    }
                }
                else {
                    prototype = (Object*)PrototypeMaker::getFileType();
                    root->setContent(prototype);
                    cout<< "enter folder name:";
                    cin>>prototype->name ;
                    cout << "success\n";
                }
                cin.clear();
                cin.ignore();
                break;
            }
            case '4': {
                temp = NULL;
                Object* tempFather = NULL;
                cout<<"enter object to copy:";
                cin>>location;
                vector<string> fatherFolderVector;
                fatherFolderVector  = split(location, '/');
                fatherFolderVector.pop_back();
                //copy files to same location
                temp = findObj(location, *root);
                if (temp != NULL) {
                    Dir* fatherFolder;
                    tempFather = findObjFather(location, *root);
                    if( fatherFolderVector[fatherFolderVector.size()-1] == "ROOT"){
                        prototype = ((Object*)temp->clon());
                        root->setContent(prototype);
                        cout<< "enter object name:";
                        cin>>prototype->name ;
                        cout << "success\n";
                    }
                    else{
                        prototype = ((Object*)temp->clon());
                        fatherFolder=dynamic_cast<Dir*>(tempFather);
                        fatherFolder->setContent(prototype);
                        cout<< "enter object name:";
                        cin>>prototype->name ;
                        cout << "success\n";
                    }
                }
                else{
                    cout <<"object not found\n";
                }
                //add obj pointer to file/dir name
                cin.clear();
                cin.ignore();
                break;
            }
            case '5': {
                Dir *tempFather = NULL;
                vector<Object*> t;
                temp = NULL;
                cout << "write location:";
                cin >> location;
                if (location != "\"\"" && location != "" && location != "ROOT") {
                    //what happen if written wrong location
                    tempFather = (Dir*)findObjFather(location, *root);
                    temp = findObj(location, *root);
                    t=tempFather->getContent();
                    if (temp == NULL) {
                        cout << "directory not found\n";
                    } else {
                        for (int i = 0; i < t.size(); i++) {
                            if (t.at(i) == temp) {
                                if(i == t.size()-1){
                                    t.pop_back();
                                    tempFather->replaceVec(t);
                                }
                                else{
                                    Object* replace = tempFather->getContent().at(i);
                                    t.at(i) = t.at(t.size()-1);
                                    t.at(t.size()-1) = replace;
                                    t.pop_back();
                                    tempFather->replaceVec(t);
                                }
                            }
                        }
                        cout << temp->getName() << " is deleted\n";
                        temp->deleteObj();
                    }
                } else {
                    cout << root->getName() << " is deleted\n";
                    root->deleteObj();
                }
                cin.clear();
                cin.ignore();
                break;
            }
                case '6':{
                    temp = NULL;
                    cout << "write location:";
                    cin >> location;
                    if (location != "\"\"" && location != "" && location != "ROOT") {
                        temp = findObj(location, *root);
                        if (temp == NULL) {
                            cout << "directory not found\n";
                        }else{
                            temp->showContent(0);
                        }
                    }else {
                        root->showContent(0);
                    }
                    cin.clear();
                    cin.ignore();
                    break;
            }
            case '7': {
                myFile.open("systemContent.txt",myFile.trunc);
                myFile.close();
                root->printToFile(myFile, 0);
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



System::~System(){
    
}
System::System(){
}



