/*
 Programmer:§õ¦w¥H
 ¢Òate:4/30
 Instructor:Chow-Sing Lin
 Class:Program Design
 find the other prime number nex to input
 *///
#include <iostream>
using namespace std;
class PrimeNumber {
public:
    void setprime(int prinum) { prime = prinum; };
    int getprime() { return prime; };
    PrimeNumber(int prinum) :prime(prinum) {};
    PrimeNumber() :prime(1) {};
    PrimeNumber operator++();
    PrimeNumber operator--();
    PrimeNumber operator++(int);
    PrimeNumber operator--(int);
private:
    int prime;
};
int main(void) {
    PrimeNumber input;
    int primenumber;
    //input the prime number
    cout << "Enter the prime number : ";
    cin >> primenumber;
    input.setprime(primenumber);
    ++input;
    //output the bigger prime number
    cout << "Next largest : " << input.getprime() << endl;
    --input;
    //output the smaller prime number
    cout << "Next smallest : " << input.getprime() << endl;
    cout << "------------------------------------" << endl;
    input.setprime(primenumber);
    input++;
    cout << "Next largest : " << input.getprime() << endl;
    input--;
    cout << "Next smallest : " << input.getprime() << endl;

    return 0;
}
PrimeNumber PrimeNumber::operator++() {
    //find the bigger one
    while (true) {
        bool op = true;
        prime++;
        for (int i = 2; i < prime; i++) {
            if (prime % i == 0) {
                op = false;
                break;
            }
        }
        if (op == true) {
            break;
        }
    }
    return PrimeNumber(prime);
}
PrimeNumber PrimeNumber::operator--() {
    //find the smaller one
    while (true) {
        bool op = true;
        prime--;
        for (int i = 2; i < prime; i++) {
            if (prime % i == 0) {
                op = false;
                break;
            }
        }
        if (op == true) {
            break;
        }
    }
    return PrimeNumber(prime);
}
PrimeNumber PrimeNumber::operator++(int ignore) {
    while (true) {
        bool op = true;
        prime++;
        for (int i = 2; i < prime; i++) {
            if (prime % i == 0) {
                op = false;
                break;
            }
        }
        if (op == true) {
            break;
        }
    }
    return PrimeNumber(prime);
}
PrimeNumber PrimeNumber::operator--(int ignore) {
    while (true) {
        bool op = true;
        prime--;
        for (int i = 2; i < prime; i++) {
            if (prime % i == 0) {
                op = false;
                break;
            }
        }
        if (op == true) {
            break;
        }
    }
    return PrimeNumber(prime);
}




