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

// DEFINATION-> Observer design pattern defines one to many relation between objects;
// When one object(Observable) changes its state , all dependent objects(observer) are automatically notified and updated
// For an example:-> Youtube Channel -> subjects 
//                   Subsciber-> obsever
//                   when a new video is uploaded, all subscribers get notified automatically

// 🧠 When to Use Observer Pattern
// Use Observer Pattern when:
// ✔ Many objects depend on one object
// ✔ State change should notify others automatically
// ✔ You want loose coupling (no tight dependency)
// ✔ Event systems, notifications, listeners, UI updates

// TWO MODELS:
// PUSH-> Observable pushes the data it want observer to recieve,so observer do not ask for data it get it automatically

            //     +----------------------+
            //     |      Observable      |
            //     |----------------------|
            //     | +add(Observer)       |
            //     | +remove(Observer)    |
            //     | +notify()            |
            //     | +setState()          |
            //     +----------▲-----------+
            //                |
            //              is-a
            //                |
            //     +----------------------+
            //     | ConcreteObservable   |
            //     |----------------------|
            //     | - observers : List   |
            //     | - data : ObservableData |
            //     |----------------------|
            //     | +add()               |
            //     | +remove()            |
            //     | +notify()            |
            //     | +setState()          |
            //     +----------+-----------+
            //                |
            //       pushes data to
            //                |
            //     +----------▼-----------+
            //     |      Observer        |
            //     |----------------------|
            //     | +update(data)        |
            //     +----------▲-----------+
            //                |
            //              is-a
            //                |
            // +-----------------------------+
            // |     ConcreteObserver        |
            // |-----------------------------|
            // | +update(data)               |
            // +-----------------------------+

            //     +----------------------+
            //     |   ObservableData     |
            //     |----------------------|
            //     | data1                |
            //     | data2                |
            //     +----------------------+
class ObservableData{
public:
    int data1;
    int data2;
    ObservableData(int d1,int d2){
        this->data1=d1;
        this->data2=d2;
    }
};
// Observer Interface
class Observer{
    public:
    virtual void update(ObservableData* data)=0;
    virtual ~Observer() {}
};
//Observable Interface
class Observable{
public:
    virtual void add(Observer* obs)=0;
    virtual void remove(Observer* obs)=0;
    virtual void notify()=0;
    virtual void setData(int d1,int d2)=0;
    virtual ~Observable() {}
};
class ConcreteObservable : public Observable {
    vector<Observer*> subscribers;
    ObservableData* data;
public:
    ConcreteObservable(){
        data=new ObservableData(0,0);
    }
    void add(Observer* obs) override {
        subscribers.push_back(obs);
    }
    void remove(Observer* obs) override {
        for(auto it=subscribers.begin();it!=subscribers.end();it++){
            if(*it==obs){
                subscribers.erase(it);
                break;
            }
        }
    }
    void setData(int d1,int d2) override {
        data->data1=d1;
        data->data2=d2;
        notify();
    }
    void notify() override {
        for(auto it=subscribers.begin();it!=subscribers.end();it++){
            (*it)->update(data);
        }
    }
};
class ConcreteObserver : public Observer {
    string name;
public:
    ConcreteObserver(string name){
        this->name=name;
    }
    void update(ObservableData* d1){
        cout<<name<<" received -> "<< "data1: "<<d1->data1<<", data2: "<<d1->data2<<endl;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ConcreteObservable subject;
    ConcreteObserver obs1("Observer-1");
    ConcreteObserver obs2("Observer-2");
    subject.add(&obs1);
    subject.add(&obs2);
    subject.setData(10, 20);
    subject.setData(50, 100);
    return 0;
}

