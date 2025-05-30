#include<bits/stdc++.h>
#include "entities/vehicle.hpp"
#include "entities/user.hpp"
#include "service/bookingService.hpp"







using namespace std;




int main(){
   string userId;
   string name;
   string aadharCard;


   cout << "Enter UserId: ";
   cin >> userId;

   cout << "Enter Name: ";
   cin >> name;

   cout << "Enter Aadhar Card Number: ";
   cin >> aadharCard;

     vector<Vehicle> vehicles;

     cout << "Enter the option: " << endl;
     cout << "Enter 1 to book thet train" << endl;

     int option;
     cin >> option;

     switch(option){
       case 1:  {
          string trainId , trainName , source , destination;

          cout << "Enter Train Id: ";
          cin >> trainId;

          cout << "Enter the Train Name: ";
          cin >> trainName;

          cout << "Enter the Source Station: ";
          cin >> source;

          cout << "Enter the Destination Station: ";
          cin >> destination; 


          User user = {userId , name , aadharCard , vehicles};
          BookingService<Vehicles> bookingService;
          bookingService.book(trainId , userId , trainName , source , destination);

          cout << "Train booking Completed!" << endl;
          break; 
       }

       default :
        cout << "Invalid option" << endl;
        break;
     }


   return 0;
}