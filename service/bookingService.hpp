#include<iostream>
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
