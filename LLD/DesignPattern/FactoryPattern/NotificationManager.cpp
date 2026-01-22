#include <iostream>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define ll long long
class Notification {
public:
    virtual void send(string msg)=0;
    virtual ~Notification() {}
};
class EmailNotification : public Notification {
public:
    void send(string msg) override {
        cout<<"Email Sent: "<<msg<<endl;
    }
};
class SMSNotification : public Notification {
public:
    void send(string msg) override {
        cout<<"SMS Sent: "<<msg<<endl;
    }
};
class PushNotification : public Notification {
public:
    void send(string msg) override {
        cout<<"Push Message Sent: "<<msg<<endl;
    }
};
class NotificationFactory{
public:
    Notification* createMessage(string type){
        if(type=="Email"){
            return new EmailNotification();
        }
        else if(type=="SMS"){
            return new SMSNotification();
        }
        else if(type=="push"){
            return new PushNotification();
        }
        else return NULL;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // client side code;   
    NotificationFactory Factory;
    Notification* n1=Factory.createMessage("Email");
    Notification* n2=Factory.createMessage("SMS");  
    n1->send("Welcome Utkarsh");
    return 0;                                                                                      
}
