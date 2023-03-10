//? class diagram:= structure of every class and flow

//? access mutators:= getters and setters of a variable

#include <bits/stdc++.h>
using namespace std;
enum RideStatus {
     IDLE, CREATED, WITHDRAWN, COMPLETED
};
class Ride {
public:
     static const int AMT_PER_KM = 20; //? static for only one copy
     Ride();
     int calculateFare(bool);
     void setDest(int dest);
     int getId() const;
     void setId(int id);
     void setOrigin(int origin);
     RideStatus getRideStatus() const;

     void setRideStatus(RideStatus rideStatus);
     void setSeats(int seats);

private:
     int id;
     int origin, dest;
     int seats;
     RideStatus rideStatus;
};
class Person {
public:
     string name;
};
class Rider: private Person { // inherits all the//?public property of class
     // Person as private property
     // createRide(){};
     // updateRide(){};
     // withdrawRide(){};
     // closeRide(){};
     // currentRide Ride;
private:
     vector<Ride> allRides;
     // Ride currentRide;

public:
     Rider(string);
     void createRide(int, int, int, int);
     void updateRide(int, int, int, int);
     void withdrawRide(int);
     int closeRide(int);
     Ride* findRide(int);
};

class Driver: private Person {
public:
     int k;
     Driver(string name); // parameterized constructor
};
Ride::Ride() {
     id = origin = dest = seats = 0;
     rideStatus = RideStatus::IDLE;
}
Driver::Driver(string name) {
     this->name = name;
}
Rider::Rider(string name) {
     this->name = name;
}
Ride* Rider::findRide(int id) {
     auto itr = allRides.rbegin();
     for (;itr!=allRides.rend();itr++) {
          if (itr->getId()==id) {
               return &*itr; //!couldnt return just  itr as it's an iterator not a pointer
          }
     }
     return nullptr;
}
void Rider::createRide(int id, int origin, int dest, int seats) {
     // if (currentRide.getRideStatus()==RideStatus::CREATED) {
     //      cout<<"Can't allow multiple ride at a time\n";
     //      return;
     // }
     if (origin >= dest) {
          cout << "Wrong values of origin and destination: " << origin << " "
               << dest << endl;
          return;
     }
     Ride currentRide;
     currentRide.setId(id);
     currentRide.setOrigin(origin);
     currentRide.setDest(dest);
     currentRide.setSeats(seats);
     currentRide.setRideStatus(RideStatus::CREATED);
     allRides.push_back(currentRide);
     cout<<"Ride created/updated successfully\n";
}
void Rider::updateRide(int id, int origin, int dest, int seats) {
     Ride* currentRide = findRide(id);
     if (currentRide==nullptr) {
          cout<<"Can't find the ride with given id\n";
          return;
     }
     if (currentRide->getRideStatus() == RideStatus::COMPLETED) {
          cout << "Can't update completed ride\n";
          return;
     }
     if (currentRide->getRideStatus() == RideStatus::WITHDRAWN) {
          cout << "Can't update withdrawn ride\n";
          return;
     }
     cout<<"Updating ride...\n";
     currentRide->setOrigin(origin);
     currentRide->setDest(dest);
     currentRide->setSeats(seats);
}
void Rider::withdrawRide(int id) {
     Ride* currentRide = findRide(id);
     if (currentRide==nullptr) {
          cout<<"Can't find the ride with given id\n";
          return;
     }
     if (currentRide->getId() != id) {
          cout << "Wrong id in input\n";
          return;
     }
     if (currentRide->getRideStatus() != RideStatus::CREATED) {
          cout << "Ride is not in progress\n";
          return;
     }
     currentRide->setRideStatus(RideStatus::WITHDRAWN);
     cout<<"Ride withdrawn\n";
}
int Rider::closeRide(int id) {
     Ride* currentRide = findRide(id);
     if (currentRide==nullptr) {
          cout<<"Can't find the ride with given id to close\n";
          return 0;
     }
     if (currentRide->getRideStatus() != RideStatus::CREATED) {
          cout << "Ride is not in progress. Can't close the ride\n";
          return 0;
     }
     currentRide->setRideStatus(RideStatus::COMPLETED);
     // allRides.push_back(*currentRide);
     return currentRide->calculateFare(allRides.size()>=2);
}
int Ride::calculateFare(bool isPriority = false) {
     int dist = dest - origin;
     if (seats < 2) {
          return dist * AMT_PER_KM * (isPriority ? 0.75 : 1);
     }
     return dist * seats * AMT_PER_KM * (isPriority ? 0.5 : 0.75);
}
int main() {
     cout<<"Hello World\n";
     // Rider* rider = new Rider("Satyam");
     // Rider rider = Rider("Satyam");
     Rider rider("Satyam"); //? all three will work
     Driver driver = Driver("Kundan");


     rider.createRide(1, 50, 60, 1);
     rider.createRide(1, 60, 70, 2);
     cout<<rider.closeRide(1)<<endl;
     rider.updateRide(1, 60, 70, 2);
     cout<<rider.closeRide(1)<<endl;
     rider.createRide(1, 60, 70, 2);
     rider.updateRide(1, 70, 80, 2); //? this creates a bug where user can create a ride and keep updating it and pays only for the last ride
     rider.updateRide(4, 70, 80, 2);
     cout<<rider.closeRide(1)<<endl;

     cout<<"*********************************************\n";


     rider.createRide(1, 50, 60, 1);
     rider.withdrawRide(1);
     rider.updateRide(1, 50, 60, 2);
     cout<<rider.closeRide(1)<<endl;

     return 0;
}

void Ride::setDest(int dest) {
     this->dest = dest;
}

int Ride::getId() const {
     return id;
}

void Ride::setId(int id) {
     this->id = id;
}

void Ride::setOrigin(int origin) {
     this->origin = origin;
}

RideStatus Ride::getRideStatus() const {
     return rideStatus;
}

void Ride::setRideStatus(RideStatus rideStatus) {
     this->rideStatus = rideStatus;
}

void Ride::setSeats(int seats) {
     this->seats = seats;
}
