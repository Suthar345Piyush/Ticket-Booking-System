#include<iostream>
#include "../entities/user.hpp"
#include "../entities/vehicle.hpp"
#include "../entities/train.hpp"
#include "fileIO.cpp"





using namespace std;

// applying generics template functions

template <typename T>
class BookingService {
   
    public :
      void book(string entityId , string userId);
      void cancelBooking(string entityId , string userId);
      void printBooking(string entityId , string userId);


    private : 
       void saveBooking(T entity);

};
