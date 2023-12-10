#include<iostream>
#include<fstream>
using namespace std;
int main(){
    //ofstream out;
    fstream f;
    f.open("temp.txt",ios::app);
    string s;
    while(1){
        cout<<"enter 1 for text |  enter 0 for exit:"<<endl;
        int ch;
        cin>>ch;
        if(ch==1){
            cout<<"Enter text: "<<endl;
            cin.get();
            getline(cin,s);
            f<<s<<endl;
        }
        else if(ch==0){
            cout<<"exited"<<endl;
            break;
        }
    }
    f.close();
    //ifstream infile;
    f.open("temp.txt",ios::in);
    cout<<"file contents are : "<<endl;
    while(!f.eof()){
        getline(f,s);
        cout<<s<<endl;
    }
    return 0;
}