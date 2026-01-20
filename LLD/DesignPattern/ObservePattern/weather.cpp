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
// Push-method;
class WeatherData{
    float temperature;
    float humidity;
public:
    WeatherData(float temp,float humidity){
        this->temperature=temp;
        this->humidity=humidity;
    }
    float getTemperature(){
        return temperature;
    }
    float getHumidity(){
        return humidity;
    }
};
class WeatherObserver{
public:
    virtual void update(WeatherData* d)=0;
};
class WeatherObservable{ // this is an interface;
public:
    virtual void addObserver(WeatherObserver* obs)=0;
    virtual void removeObserver(WeatherObserver* obs)=0;
    virtual void notify()=0;
    virtual void setWeatherReadings(float temp,float humidity)=0;
};
class ConcreteObservable : public WeatherObservable{
    vector<WeatherObserver*> subscribers;
    WeatherData* data;
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
            (it)->update(data);
        }
    }
    void setWeatherReadings(float temp,float humidity) override {
        data=new WeatherData(temp,humidity);
        notify();
    }
};
class concreteObserver : public WeatherObserver{
public:
    void update(WeatherData* d) override {
        // now use a business logic to use the data;
        cout<<"I have got the Weather Data"<<endl;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    WeatherObservable* weatherStation=new ConcreteObservable();
    WeatherObserver* obs1=new concreteObserver();
    WeatherObserver* obs2=new concreteObserver();
    weatherStation->addObserver(obs1);
    weatherStation->addObserver(obs2);
    weatherStation->setWeatherReadings(30.3,65);
    return 0;
}