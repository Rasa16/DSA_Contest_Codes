//https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/616/week-4-august-22nd-august-28th/3917/

class Solution {
public:
    struct complex{
        int r;
        int img;
        complex(){
            r = 0;
            img = 0;
        }
        complex(int real, int imag){
            r = real;
            img = imag;
        }
    };
    complex multiply(complex n1, complex n2){
        complex c;
        c.r = n1.r*n2.r - n2.img*n1.img;
        c.img = n1.r*n2.img + n2.r*n1.img;
        
        return c;
    }
    complex convert(string s){
        int i = s.find('+');
        int r_no = stoi(s.substr(0, i));
        int i_no = stoi(s.substr(i+1, s.size()-i-2));
        
        complex c(r_no, i_no);
        return c;
        
    }
    string complexNumberMultiply(string num1, string num2) {
        complex a = convert(num1);
        complex b = convert(num2);
        
        complex res = multiply(a, b);
        
        return to_string(res.r) + '+' + to_string(res.img) + 'i';
    }
};
