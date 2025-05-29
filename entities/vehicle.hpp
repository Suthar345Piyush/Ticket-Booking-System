#include<iostream>
#include<time.h>
#include<vector>
#include "../entities/train.hpp"
#include "../entities/user.hpp"
using namespace std;


struct Vehicle {
     string vehicleId;
     string name;
     string source;
     string destination;
     time_t time;
     vector<vector<User>> seats;
};


Train convert(Vehicle vehicle){
      struct Train train;
      train.trainId = vehicle.vehicleId;
      train.name = vehicle.name;
      train.source = vehicle.source;
      train.destination = vehicle.destination;
      train.time = vehicle.time;
      train.seats = vehicle.seats;


      return train;

};


