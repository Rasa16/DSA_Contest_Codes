/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

class employee{
    public:
    string name;
    int yoj;
    string add;
    
    employee(string n, int y, string a){
        name = n;
        yoj = y;
        add = a;
    }
    
    void print_details(){
        cout<<name<<" "<<yoj<<" "<<add<<endl;
    }
};

int main()
{
    employee e1("robert", 1994, "wallstreet");
    employee e2("sam", 2000, "urban");
    employee e3("jon", 1999, "wallstreet");
    
    cout<<"Name "<<"Year of joining "<<"address"<<endl;
    
    e1.print_details();
    e2.print_details();
    e3.print_details();

    return 0;
}
