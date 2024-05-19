/*
 Programmer:§õ¦w¥H
 ¢Òate:4/29
 Instructor:Chow-Sing Lin
 Class:Program Design
 seperate the integer
 *///
#include <cmath>
#include <iostream>
using namespace std;
class MyInteger {
public:
    void setnumber(int num) { number = num; };
    int getnumber() { return number; };
    int operator[](int index);
private:
    int number;
};
int main(void) {
    MyInteger enter;
    int number;
    //input the number
    cout << "Enter the integer : ";
    cin >> number;
    enter.setnumber(number);
    //seperate
    int index = -1;
    do {
        index++;
        //output
        cout << number << "[" << index << "] = " << enter[index] << endl;
    } while (enter[index] != -1);


    return 0;
}
int MyInteger::operator[](int index) {
    int digit;
    int math;
    math = pow(10, index);
    //seperate
    digit = number / math;
    digit = digit % 10;
    if (math > number) {
        return -1;
    }
    else {
        return digit;
    }
}




