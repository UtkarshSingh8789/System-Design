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

// first i will create the interface
class DriveStrategy{
public:
    virtual void drive()=0;
    virtual ~DriveStrategy() {}
};
class NormalDrive : public DriveStrategy {
public:
    void drive() override {
        cout<<"you are using a normal drive strategy"<<endl;
    }
};
class SportsDrive : public DriveStrategy {
public:
    void drive() override {
        cout<<"you are using a sports drive strategy"<<endl;
    }
};
// main class that will communicate with interface:
class Vehicle{
public:
    DriveStrategy* d;
    Vehicle(DriveStrategy* d) : d(d) {}
    void drive(){
        d->drive();
    }
};
class GoodsVehicle: public Vehicle{
public:
    GoodsVehicle(DriveStrategy* d) : Vehicle(d) {}

};
class SportsVehicle: public Vehicle{
public:
    SportsVehicle(DriveStrategy* d) : Vehicle(d) {}
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    GoodsVehicle truck(new NormalDrive());
    truck.drive();
}


// UML DIAGRAM

//                     <<interface>>
//                  +------------------+
//                  |  DriveStrategy   |
//                  +------------------+
//                  | + drive()        |
//                  +------------------+
//                        ▲
//           -------------------------------
//           |                             |
// +--------------------+       +--------------------+
// |   NormalDrive      |       |   SportsDrive      |
// +--------------------+       +--------------------+
// | + drive()          |       | + drive()          |
// +--------------------+       +--------------------+

//                  (has-a)
//                     |
//                     ▼
//               +------------------+
//               |     Vehicle      |
//               +------------------+
//               | - d: DriveStrategy|
//               +------------------+
//               | + drive()        |
//               +------------------+
//                     ▲
//         -------------------------
//         |                       |
// +------------------+   +------------------+
// |  GoodsVehicle    |   |  SportsVehicle   |
// +------------------+   +------------------+
// | (inherits)       |   | (inherits)       |
// +------------------+   +------------------+
