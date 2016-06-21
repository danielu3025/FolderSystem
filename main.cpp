// make type in objects for copying

#include <iostream>
#include "Menu.h"
#include <sstream>

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

int main(int argc, const char * argv[]) {
    
     
    Dir root = Root::getInstance();
    ClonAble::initialize();
    /*
    Object* obj = ClonAble::getDirType();
    Dir* home = dynamic_cast<Dir*>(obj);
    home->setName("home");
    
    File hello; hello.setName("hello.txt");
    
    root.setContent(home);
    home->setContent(&hello);
    
    root.showContent();
    
    Object* user; user = home->makeCopy();
    user->setName("user");
    
    root.setContent(user);
    root.showContent();
    
    FileBuilder* doc = new (FileBuilder);
    ObjDirector* manger =new ObjDirector(doc);
    
    Object* realFolder = manger->getObj();
    
    realFolder->setName("mydoc");
     
    */
    
    Dir* user= new Dir;
    Dir* doc= new Dir;
    Dir* publicf= new Dir;


    user->setName("user");
    doc->setName("doc");
    publicf->setName("public");

    root.setContent(publicf);
    root.setContent(user);
    user->setContent(doc);
    string path = "ROOT/user/doc";
    Object* test = findObj(path, root);
    if (!(test == nullptr)) {
        cout<<test->getName()<<endl;
    }
    else{
        cout<<"object not found\n";
    }

    
    
    return 0;
}
