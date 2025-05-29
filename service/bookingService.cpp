#include "bookingService.hpp";
#include "../entities/vehicle.hpp"
#include "../entities/train.hpp"
#include "../entities/user.hpp"
#include <fileIO.cpp>




template <typename T>
void BookingService<T>::book(string entityId , User user , string name , string source , string destination){
        

         struct Vehicle vehicle;
         vehicle.vehicleId = entityId;
         vehicle.name = name;
         vehicle.source = source;
         vehicle.destination = destination;
         vehicle.time = time(NULL);
         vehicle.seats = {{user}};


         saveBooking(vehicle);
}

template <typename T>
void saveBooking(T entity){
   FileIO file;
   file.saveToFile(entity);
}



