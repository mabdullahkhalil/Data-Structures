
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include "bst.cpp"

using namespace std;

int main(){
    vector<int> keys;
    vector<string> values;
    bst<int>* Bst_tree=new bst<int>();
    keys.resize(1000000);
    values.resize(1000000);
    
    string filename;
   
    int key;
    int rand;
    
    
    cout<<"please enter the filename. "<<endl;
    cin>>filename;
    ifstream file;
    file.open(filename);
    
    if(file.fail()){
        
        cout<<"NO FILE"<<endl;
    }
    int j=0;
    startTimer();
    cout<<"time starting "<<endl;
    while (!file.eof()) {
        char line[50];
        string value;
        string tempkey;
        file.getline(line,50);
        int i=0;
        while (line[i] != '~') {
            value=value+line[i];
            rand=i;
            i++;
        }
        i=i+1;
        while (line[i]!=NULL) {
            tempkey=tempkey+line[i];
            i++;
        }
        key=stoi(tempkey);
       // cout<<"key : "<<key<<endl;
        Bst_tree->insert(value, key);
        j++;
    }
    stopTimer();
    cout<<"the number of items loaded are "<<j<<endl;
    
    int input;
    while (true) {
        
    cout<<"Press 1 to Insert another key/value Pair"<<endl;
    cout<<"Press 2 to search for a value using its key"<<endl;
    cout<<"Press 3 to delete a key/value pair"<<endl;
    cout<<"Press 4 to update the key of an existing value"<<endl;
    cout<<"Press 5 to see the current height of the Tree"<<endl;
        cin>>input;
    
            if (input==1){
            string v;
            int k;
            cout<<"give a key: ";cin>>k;
            cout<<"gve a value: ";cin>>v;
            Bst_tree->insert(v, k);
            }
         
           else if (input==2) {
                int k;
                cout<<"enter key: ";cin>>k;
               startTimer();
                bst_node<int>* node= Bst_tree->search(k);
               
                stopTimer();
               cout<<"the value is :"<<node->value<<endl;
            }
           else if (input==3){
               int k;
               cout<<"enter key: "; cin>>k;
               Bst_tree->delete_node(k);
           }
           else if (input==4){
               int ok,nk;
               cout<<"enter old key : "; cin>>ok;
               cout<<"enter new key: "; cin>>nk;
               Bst_tree->replace(ok, nk);
           }
           else if (input==5){
               cout<<"the height of the tree is: "<<Bst_tree->height(Bst_tree->getroot())<<endl;
           }
    
}

           
            
    
    
  
    
    
    
    
    
    
    file.close();
    
}

