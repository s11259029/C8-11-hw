/*
 Programmer:§õ¦w¥H
 ¢Òate:5/18
 Instructor:Chow-Sing Lin
 Class:Program Design
 television type
 *///
#include <string>
#include <iostream>
using namespace std;
class Television {
public:
    Television(string displayType, double dimension, string* connectivitySupport) :displayType(displayType), dimension(dimension), connectivitySupport(connectivitySupport) {};
    Television() :displayType(""), dimension(0), connectivitySupport(NULL) {};
    void setdisplayType(string type);
    void setdimension(double volume);
    void setconnectivitySupport(string* connect);
    string getdisplayType() { return displayType; }
    double getdimension() { return dimension; }
    string* getconnectivitySupport() { return connectivitySupport; }
    Television& operator=(const Television& other);
    ~Television();
private:
    string displayType;
    double dimension;
    string* connectivitySupport;
};
void input(Television&);
void clear();
int main(void) {
    Television Default;
    input(Default);
    cout << "---------------------------------" << endl;
    int number;
    //first television
    cout << "The number of television : ";
    cin >> number;
    //new one
    Television* televisions;
    televisions = new Television[number];
    for (int i = 0; i < number; i++) {
        televisions[i] = Default;
    }
    //keep input
    for (int i = 0; i < number; i++) {
        getchar();
        cout << "\nTelevision " << i + 1 << " : " << endl;
        cout << "Do you want customization (y/n)  : ";
        if (getchar() == 'n') {
            continue;
        }
        input(televisions[i]);
    }


}
void Television::setdisplayType(string type) {
    displayType = type;
}
void Television::setdimension(double volume) {
    dimension = volume;
}
void Television::setconnectivitySupport(string* connect) {
    connectivitySupport = connect;
}
Television::~Television() {
    //delete
    if (connectivitySupport) {
        delete[]connectivitySupport;
        connectivitySupport = NULL;
    }
}
Television& Television::operator=(const Television& other) {
    //copy
    if (this == &other) {
        return *this;
    }
    displayType = other.displayType;
    dimension = other.dimension;
    connectivitySupport = other.connectivitySupport;
    /*delete[]connectivitySupport;
    connectivitySupport = NULL;
    connectivitySupport = new string[num];
    for (int i = 0;i < num;i++) {
        connectivitySupport[i] = other.connectivitySupport[i];
    }*/
    return *this;
}
void input(Television& t1) {
    //input the information
    string type;
    cout << "Enter the display type : ";
    cin >> type;
    t1.setdisplayType(type);
    double inches;
    cout << "Enter the dimension in inches : ";
    cin >> inches;
    t1.setdimension(inches);
    //input the mode
    const int max = 10;
    int num = 0;
    string support[max];
    cout << "Enter the different connectivity modes : " << endl;
    while (num < max) {
        cout << num + 1 << ". connectivity mode : ";
        cin >> support[num];
        //other
        clear();
        cout << "Any other connectivity modes (y/n) : ";
        if (getchar() == 'n') {
            clear();
            break;
        }
        clear();
        num++;
    }
    string* supportPtr = new string[num + 1];
    for (int i = 0; i <= num; i++) {
        supportPtr[i] = support[i];
    }
    t1.setconnectivitySupport(supportPtr);
}
void clear() {
    do {
        if (getchar() == '\n') { break; }
    } while (true);
}
