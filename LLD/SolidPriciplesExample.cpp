// QUESTION->A system that processes an order and takes payment using different payment methods (Card, UPI, etc.).
// Rules:
// 1.Order processing logic should not depend on concrete payment types
// 2.Adding a new payment method should not modify existing code
// 3.Each class should have one responsibility


                        //UML->DIAGRAM

//            +------------------+
//            |      Order       |
//            +------------------+
//            | - amount: double |
//            +------------------+
//            | + getAmount()    |
//            +------------------+

//                     |
//                     | uses
//                     ▼

//            +------------------------+
//            |   PaymentProcessor     |
//            +------------------------+
//            | - payment: Payment     |
//            +------------------------+
//            | + processPayment()     |
//            +------------------------+

//                     |
//                     | depends on
//                     ▼

//            <<interface>>
//            +------------------+
//            |     Payment      |
//            +------------------+
//            | + pay(amount)    |
//            +------------------+
//               ▲           ▲
//               |           |
//    +----------------+   +----------------+
//    |  CardPayment   |   |  UPIPayment    |
//    +----------------+   +----------------+
//    | + pay(amount)  |   | + pay(amount)  |
//    +----------------+   +----------------+

// NOTE-> ALWAYS CODE FROM TOP TO BOTTOM:
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
// 7 2
// 1 2 2 3 2 4 10
class Order{
    double amount;
public:
    Order(double amount) : amount(amount) {}
    double getAmount() const {
        return amount;
    }
};
class Payment{
public:
    virtual void pay(double amount)=0;
    virtual ~Payment() {}
};
class CardPayment : public Payment{
public:
    void pay(double amount) override {
        cout<<"payment of amount: "<<amount<<" done through Card"<<endl;
    }
};
class UPIPayment : public Payment{
public:
    void pay(double amount) override {
        cout<<"payment of amount: "<<amount<<" done through UPI"<<endl;
    }
};
class PaymentProcessor{
public:
    // ishko mtlb nhi hai ki kise payemnt hua bs payment hogya isse mtlb hai it will depend on Payment interface rather than concrete classes;
    Payment* p;
    PaymentProcessor(Payment* p) : p(p) {}
    void ProcessPayment(Order* order){
        p->pay(order->getAmount());
    }

};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Order* order=new Order(1500);
    CardPayment* card=new CardPayment();
    PaymentProcessor processor1(card);
    processor1.ProcessPayment(order);
}
