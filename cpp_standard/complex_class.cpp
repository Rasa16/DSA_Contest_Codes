#include <iostream>

using namespace std;

class Complex{
    public:
    int real;
    int img;
    
    Complex(){
        real = 0;
        img = 0;
    }
    
    Complex(int r, int i){
        real = r;
        img = i;
    }
};

Complex sum(Complex a, Complex b){
    Complex c;
    c.real =  a.real + b.real;
    c.img = a.img + b.img;
    
    return c;
}

Complex difference(Complex a, Complex b){
    Complex c;
    c.real =  a.real - b.real;
    c.img = a.img - b.img;
    
    return c;
}

Complex pro(Complex a, Complex b){
    Complex c;
    c.real =  a.real * b.img - b.real*a.img;
    c.img = a.real * b.img + b.real*a.img;
    
    return c;
}
int main()
{
   cout<<"Enter first complex number"<<endl;
   int x, y;
   cin>>x>>y;
   
   cout<<"Enter second complex number"<<endl;
   int c, d;
   cin>>c>>d;
   
   Complex first(x, y);
   Complex second(c, d);
   
   cout<<"sum: "<<sum(first, second).real<<'+'<<sum(first, second).img<<'i'<<endl;
   cout<<"difeerenec: "<<difference(first, second).real<<'+'<<difference(first, second).img<<'i'<<endl;
   cout<<"pro: "<<pro(first, second).real<<'+'<<pro(first, second).img<<'i'<<endl;
   
   return 0;
}
