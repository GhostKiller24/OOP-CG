#include<iostream>
using namespace std;
class publication{
    protected:
        string title;
        float price;
    public:
        publication(){
            title="";
            price=0.0;
        }
        publication(string t,float p){
            title=t;
            price=p;
        }
};
class book:public publication{
    private:
        int pages;
    public:
        book():publication(){
            pages=0;
        }
        book(string t,float p,int pg):publication(t,p){
            if(pg>0&&p>0.0){
                pages=pg;
            }
            else{
                throw(0);
            }
        }
        void display(){
            cout<<title<<"-"<<price<<"-"<<pages<<endl; 
        }
};
class tape:public publication{
    private:
        float mins;
    public:
        tape(){
            mins=0;
        }
        tape(string t,float p,float m):publication(t,p){
            if(m>0&&p>0.0){
                mins=m;
            }
            else{
                throw(0);
            }
        }
        void display_tape(){
            cout<<title<<"-"<<price<<"-"<<mins<<endl; 
        }

};
int main(){
    int pages;
    float price;
    string title;
    cout<<"Enter Book Details: Title | Price | Pages"<<endl;
    cin>>title>>price>>pages;

    float min,pri;
    string t;
    cout<<"Enter Tape Details: Title | Price | Minutes"<<endl;
    cin>>t>>pri>>min;
    book b;
    tape t1;
    try{
        b=book(title,price,pages);
        t1=tape(t,pri,min);
    }
    catch(...){
        b.display();
        t1.display_tape();
        b=book("",0,0);
        t1=tape("",0,0);
    }
    b.display();
    t1.display_tape();
    return 0;
}