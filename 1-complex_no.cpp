#include<iostream>
using namespace std;
class complex{
    public:
    float real;
    float img;
    complex(){
        real=0;
        img=0;
    }
    complex(float r,float i){
        real=r;
        img=i;
    }
    void show(){
        cout<<real<<"+"<<img<<"i"<<endl;
    }
    complex operator+(complex c2){
        complex temp;
        temp.real=real+c2.real;
        temp.img=img+c2.img;
        return temp;
    }
    
};
complex operator*(complex c1,complex c2){
        complex temp;
        temp.real=(c1.real*c2.real)-(c1.img*c2.img);
        temp.img=(c1.real*c2.img)+(c1.img*c2.real);
        return temp;
}
ostream& operator<<(ostream&COUT,complex c1){
    COUT<< c1.real << "+" << c1.img << "i"<<endl;
}
istream& operator>>(istream&CIN,complex& c){
    CIN>> c.real>> c.img;
}
int main(){
    complex z;
    complex z1(2,4);
    
    z.show();
    z1.show();

    complex z2=z+z1;
    z2.show();

    complex z3=z1*z2;
    cout<<z3;

    complex z4;
    cout<<"enter real and imaginary part: ";
    cin>>z4;
    cout<<z4;
    
    return 0;
}