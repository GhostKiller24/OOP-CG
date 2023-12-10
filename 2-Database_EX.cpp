#include<iostream>
using namespace std;
class student;
class person{
    private:
        string name,blo,addr,telep,dlo,dob;
    public:
        friend class student;
        person(){
            name="",blo="",addr="",telep="",dlo="",dob="";
        }
        person(const person &p,string name){
            this->name=name;
            name=p.name;
            blo=p.blo;
            addr=p.addr;
            telep=p.telep;
            dlo=p.dlo;
            dob=p.dob;
        }
};
class student{
    private:
        int roll;
        string cln;
        char *div;
        char d;
    public:
        static int count;
        student(){
            roll=0;
            cln="";
            div=NULL;
            count++;
        }
        void acceptStudent(person &p){
            cout<<"Enter name: "<<endl;
            cin>>p.name;
            cout<<"Enter blood group: "<<endl;
            cin>>p.blo;
            cout<<"Enter Address: "<<endl;
            cin>>p.addr;
            cout<<"Enter driving liscense no: "<<endl;
            cin>>p.dlo;
            cout<<"Enter date of birth: "<<endl;
            cin>>p.dob;
            cout<<"Enter Roll No: "<<endl;
            cin>>roll;
            cout<<"ENter class name: "<<endl;
            cin>>cln;
            cout<<"Enter division: "<<endl;
            cin>>d;
            div=&d;
        }
        inline void displayStudent(person &p){
            cout<<"Name: "<<p.name<<endl;
            cout<<"Blood Group: "<<p.blo<<endl;
            cout<<"Address: "<<p.addr<<endl;
            cout<<"Phone: "<<p.telep<<endl;
            cout<<"Driving license: "<<p.dlo<<endl;
            cout<<"BirthDate: "<<p.dob<<endl;
            cout<<"Roll No: "<<roll<<endl;
            cout<<"Div: "<<div<<endl;
            cout<<"Class Name: "<<cln<<endl;
        }
        student(const student &s1){

        }
        ~student(){
            delete(div);
        }
        static int get(){
            return count;
        }
};
int student::count=0;
int main(){
    // cout<<student::get()<<endl;
    // student s1=student();
    // cout<<student::get()<<endl;
    // student s2=student();
    // cout<<student::get()<<endl;
    // student s3=student();
    // cout<<student::get()<<endl;
    person *p[10];
    student *s[10];
    int f=0;
    while(1){
        int ch;
        cout<<"Type 1 For Enter student details | Type 2 For Display current student details | 0 For Exit"<<endl;
        cin>>ch;
        if(ch==1){
            s[f]=new student();
            p[f]=new person();
            s[f]->acceptStudent(*p[f]);
            f++;
        }
        else if(ch==2){
            for(int i=0;i<f;i++){
                s[i]->displayStudent(*p[i]);
            }
            
        }
        else if(ch==0){
            cout<<"exited"<<endl;
            break;
        }
    }
    
    
    return 0;
}