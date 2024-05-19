/*
 Programmer:§õ¦w¥H
 ¢Òate:4/30
 Instructor:Chow-Sing Lin
 Class:Program Design
 chenge four letter word to LOVE
 *///
#include <string>
#include <cctype>
#include <iostream>
using namespace std;
int main(void) {
    while (true) {
        string message;
        //input the message
        cout << "Enter the message : ";
        getline(cin, message);
        int letter = 0;
        int number = 0;
        //int index
        //count the number of the word that four letter
        while (true) {
            if (isalpha(message[letter])) {
                number++;
            }
            else {
                if (number == 4) {
                    //change it to LOVE
                    if (isupper(message[letter - 4])) {
                        message[letter - 4] = 'L';
                    }
                    else {
                        message[letter - 4] = 'l';
                    }
                    message[letter - 3] = 'o';
                    message[letter - 2] = 'v';
                    message[letter - 1] = 'e';
                }
                number = 0;
            }

            if (letter == message.length() - 1) {
                if (number == 4) {
                    //recongnize the first letter
                    if (isupper(message[letter - 4])) {
                        message[letter - 3] = 'L';
                    }
                    else {
                        message[letter - 3] = 'l';
                    }
                    message[letter - 2] = 'o';
                    message[letter - 1] = 'v';
                    message[letter] = 'e';
                }
                break;
            }
            letter++;
        }
        cout << message << endl;
        //do it again or not
        cout << "Again ? (y/n) : ";
        if (getchar() == 'n') {
            break;
        }
        else {
            getchar();
        }
    }
    return 0;
}

