
/*
 Programmer:§õ¦w¥H
 ¢Òate:4/29
 Instructor:Chow-Sing Lin
 Class:Program Design
 channel list of subscriber
 *///
#include <string>
#include <iostream>
using namespace std;
class Subscriber {
public:
    Subscriber(string Name, int num, string* list) :name(Name), numChannels(num), channelList(list) {};
    void input();
    void output();
    Subscriber() :name(""), numChannels(0), channelList(NULL) {};
    void reset();
    Subscriber& operator=(const Subscriber& other);
    ~Subscriber();
    void setname(string name);
    void setnumChannels(int num);
    void setchannelList(string* list);
    string getname() { return name; }
    int getnumChannels() { return numChannels; }
    string* getchannnelList() { return channelList; }
private:
    string name;
    int numChannels;
    string* channelList;
};
int main(void) {
    //teo users
    Subscriber user1;
    Subscriber user2("Cathy", 3, new string[3]{ "channel-a","channe-b","channel-c" });
    //input the information of the user 1
    cout << "User 1 : " << endl;
    user1.input();
    cout << "------------------------" << endl;
    //output the name and channel list of the user 1
    user1.output();
    cout << "------------------------" << endl;
    //output the name and the channel list of the user 2
    cout << "User 2 : " << endl;
    user2.output();
    cout << "------------------------" << endl;
    //copy the channel list
    cout << "Copy user 2 to user 1 " << endl;
    cout << "User 1 : " << endl;
    user1 = user2;
    //output the copy channel list
    user1.output();
    cout << "------------------------" << endl;
    //reset the channel list
    cout << "Reset user 2" << endl;
    user2.reset();
    user2.output();


    return 0;
}
void Subscriber::input() {
    //input name
    cout << "Enter the name : ";
    cin >> name;
    //input number of channels
    cout << "Enter the number of the channel you subscribe : ";
    cin >> numChannels;
    delete[] channelList;
    channelList = NULL;
    channelList = new string[numChannels];
    //input channel name
    cout << "Enter the names of chnnels : " << endl;
    for (int i = 0; i < numChannels; i++) {
        cout << i + 1 << "-";
        cin >> channelList[i];
    }
}
void Subscriber::output() {
    //output
    cout << "Name : " << name << endl;
    cout << "Channels : \n";
    for (int i = 0; i < numChannels; i++) {
        cout << i + 1 << "-" << channelList[i] << endl;
    }
}
void Subscriber::reset() {
    //reset
    numChannels = 0;
    delete[]channelList;
    channelList = NULL;
}
Subscriber& Subscriber::operator=(const Subscriber& user1) {
    //define the operator = to copy
    if (this == &user1) {
        return *this;
    }
    //name=user1.name;
    numChannels = user1.numChannels;
    delete[]channelList;
    channelList = NULL;
    channelList = new string[numChannels];
    for (int i = 0; i < numChannels; i++) {
        channelList[i] = user1.channelList[i];
    }
    return *this;
}
Subscriber::~Subscriber() {
    //destrutor
    delete[]channelList;
    channelList = NULL;
}
void Subscriber::setname(string name) {
    this->name = name;
}
void Subscriber::setnumChannels(int num) {
    numChannels = num;
}
void Subscriber::setchannelList(string* list) {
    channelList = list;
}

