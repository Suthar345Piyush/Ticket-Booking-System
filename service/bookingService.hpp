#pragma once 

#include<iostream>
#include "../entities/user.hpp"
#include "../entities/vehicle.hpp"
#include "../entities/train.hpp"
#include  "fileIO.cpp"

// this  header file for manipulating the time and date stuff  in application 

#include<ctime>


using namespace std;

// applying generics template functions

template <typename T>
class BookingService {
   
    public :
      void book(string entityId , string userId , string name , string source , string destination);
      void cancelBooking(string entityId , string userId);
      void printBooking(string entityId , string userId);


    private : 
       void saveBooking(T entity){
         FileIO<T> file;
         file.saveToFile(entity);
       }
};


// template for specifically vehicles 

template <>
void BookingService<Vehicle>::saveBooking(Vehicle entity);

// template for trains 

template <>
void BookingService<Train>::saveBooking(Train entity);



