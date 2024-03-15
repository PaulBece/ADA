#include <iostream>

// Code B
// User type to simplify the declaration

float Addition(float a, float b){
    return a+b;
}
float Subtraction(float a, float b){
    return a-b;
}
float Multiplication(float a, float b){
    return a*b;
}
float Division(float a, float b){
    if (b==0) {
        return 0;
    }
    return a/b;
}

typedef float (*lpfnOperation)(float, float);
// CVector of pointer to functions
lpfnOperation vpf[4] = {&::Addition, &::Subtraction,
&::Multiplication, &::Division};
float a, b, c; 
int opt;

int main(){
std::cout<< "enter the operands\n";
std::cin >> a >> b;
std::cout<< "enter the operation 0-Addition, 1-Subtraction, 2-Multiplication, 3-Division\n";
std::cin >> opt;
// The next line replaces the switch and replaces the whole switch
c = (*vpf[opt])(a, b);

std::cout<<"result "<<c<<"\n";

return 0;
}

