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
// Decorator Pattern allows you to add new behavior to an object dynamically without changing its original class.
// 📌 In short:
// Add features
// Without modifying existing code
// Without creating many subclasses

// BASE OBJECT + BASE FEATURES -> Now we add feature 1 so BASE OBJECT + BASE FEATURES + FEATURE 1 now we add feature 2 so BASE OBJECT + BASE FEATURES + FEATURE 1 + FEATURE 2 and so on..

class BasePizza{
public:
    virtual string getDescription()=0;
    virtual double getCost()=0;
};
class PlainPizza : public BasePizza {
public:
    string getDescription() override {
        return "Plain Pizaa";
    }
    double getCost() override {
        return 200.00;
    }
};
class FarmHouse : public BasePizza {
public:
    string getDescription() override {
        return "FarmHouse Pizaa";
    }
    double getCost() override {
        return 250.00;
    }
};
class TopingDecorator : public BasePizza {
protected:
    BasePizza* pizza;
public:
    TopingDecorator(BasePizza* pizza){
        this->pizza=pizza;
    }
};
class CheeseTopping : public TopingDecorator {
public:
    CheeseTopping(BasePizza* pizza) : TopingDecorator(pizza) {}
    string getDescription() override {
        return pizza->getDescription()+" +Extra Cheese";
    }
    double getCost() override {
        return pizza->getCost()+20;
    }
};
class MushroomTopping : public TopingDecorator {
public:
    MushroomTopping(BasePizza* pizza) : TopingDecorator(pizza) {}
    string getDescription() override {
        return pizza->getDescription()+" +Mushroom";
    }
    double getCost() override {
        return pizza->getCost()+50;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    BasePizza* p1=new PlainPizza();
    cout<<p1->getDescription()<<endl;
    BasePizza* p2=new CheeseTopping(p1);
    cout<<p2->getDescription()<<endl;
    cout<<p2->getCost()<<endl;
    BasePizza* p3=new MushroomTopping(p2);
    cout<<p3->getDescription()<<endl;
    cout<<p3->getCost()<<endl;
    return 0;
}