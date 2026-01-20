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


// In a pull method observer holds the refrence of the observable

//                         UML for Pull Model
// ────────────────────────────────────────────────────────────────-----------------------------
//         ┌────────────────────────┐        has-a        ┌───────────────────┐
//         │        Observable      │───────────────────▶│     Observer      │
//         ├────────────────────────┤                    ├───────────────────┤
//         │ + add(Observer)        │                    │ + update()        │
//         │ + remove(Observer)     │                    └───────────────────┘
//         │ + notify()             │                           ▲
//         │ + setState()           │                           │ is-a
//         └────────────────────────┘                           │
//                   ▲                               ┌────────────────────────┐
//                   │ is-a                          │   Concrete Observer 1  │
//                   │                               ├────────────────────────┤
//         ┌────────────────────────┐                │ - Observable obj       │
//         │   ConcreteObservable   │                │ + update(){...}        │
//         ├────────────────────────┤                └────────────────────────┘
//         │ - List<Observer>       │                           ▲
//         │ - ObservableData       │                           │ is-a
//         │ + add(Observer){...}   │                ┌────────────────────────┐
//         │ + remove(Observer){...}│                │   Concrete Observer 2  │
//         │ + notify(){...}        │                ├────────────────────────┤
//         │ + setState(){...}      │                │ - Observable obj       │
//         └────────────────────────┘                │ + update(){...}        │
//                  │                                └────────────────────────┘
//                  └──────────── has-a ───────────────────────────▶ Observer
class WeatherObserver{
public:
    virtual void update()=0;
};
class WeatherObservable{
public:
    virtual void addObserver(WeatherObserver* obs)=0;
    virtual void removeObserver(WeatherObserver* obs)=0;
    virtual void notify()=0;
    virtual void setWeatherReadings(float temp,float humidity)=0;
};
class ConcreteObservable : public WeatherObservable {
    vector<WeatherObserver*> subscribers;
    float temperature;
    float humidity;
public:
    void addObserver(WeatherObserver* obs) override {
        subscribers.push_back(obs);
    }
    void removeObserver(WeatherObserver* obs) override {
        for(auto it=subscribers.begin();it!=subscribers.end();it++){
            if(*it==obs){
                subscribers.erase(it);
                break;
            }
        }
    }
    void notify() override {
        for(auto it:subscribers){
            it->update(); // the  main difference is that here we are not passing any data to update;
            // we just notify the subscribers that update has come;
        }
    }
    void setWeatherReadings(float temp,float hum) override {
        this->temperature=temp;
        this->humidity=hum;
        notify();
    }
};
class ConcreteObserver : public WeatherObserver {
    WeatherObservable* channels;
    public:
    ConcreteObserver(WeatherObservable* channels){
        this->channels=channels;
        channels->addObserver(this); // observer subscribes itself;
    }
    void update() override {
        // use the business logic;
        cout<<"Got the update from the channel"<<endl;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    WeatherObservable* weatherStation=new ConcreteObservable();
    WeatherObserver* obs1=new ConcreteObserver(weatherStation);
    weatherStation->setWeatherReadings(10,15.5);
}
