// all header files are in this header file 
#include "fileIO.hpp"

// template for vehicles 

template <>
void FileIO<Vehicle>::saveToFile(Vehicle entity){
    json j;
    ifstream file(filename);



    if(file.is_open()){
       file >> j;
       file.close();
    }

    // seats  in serial form 

    json seatsJson = json::array();

    for(const auto& row : entity.seats){
      // according to rows 
      json rowJson = json::array();

      for(const auto& user : row){
        // structure of the user things in json format 
         json userJson = {
                {"userID" , user.userId},
                {"name" , user.name},
                {"aadharCard" , user.aadharCard}
         };

         rowJson.push_back(userJson);
      }
      seatsJson.push_back(rowJson);
    }

    // structure of the entity in json format 

  json entityJson = {
   {"VehicleID" , entity.vehicleId},
   {"name" , entity.name},
   {"source" , entity.source},
   {"destination" , entity.destination},
   {"time" , entity.time},
   {"seats" , seatsJson}
};

    j.push_back(entityJson);

     ofstream outFile(filename);
      outFile << j.dump(4);
       outFile.close();
};


template <>
vector<Vehicle> FileIO<Vehicle>::readFromFile() {
    vector<Vehicle> entities;

    ifstream file(filename);



    if(!file.is_open()){
      return entities;
    }

    json j;
    file >> j;
    file.close();


    for(const auto& item : j){
      Vehicle entity;
      entity.vehicleId = item["vehicleId"];
      entity.name = item["name"];
      entity.soure = item["source"];
      entity.destination = item["destination"];
      entity.time = item["time"];


      // seats back to json 

      entity.seats.clear();
      for(const auto& rowJson : item["seats"]) {
         vector<User> row;
          for(const auto& userJson : rowJson){
             User user;
             user.userId = userJson["userId"];
             user.name = userJson["name"];
             user.aadharCard = userJson["aadharCard"];
             row.push_back(user);
          }
          entity.seats.push_back(row);
      }
      entities.push_back(entity);
    }
    return entities;
}


// template for train 

template  <>
void FileIO<Train>::saveToFile(Train entity) {
   json j;
   ifstream file(filename);


   if(file.is_open()){
    file >> j;
    file.close();
   }


   // seats into serial format 

   json seatsJson = json::array();
   for(const auto& row : entity.seats){
     json rowJson = json::array();
     for(const auto& user : row){
       json userJson = {
         {"userId" , user.userId},
         {"name" , user.name},
         {"aadharCard" , user.aadharCard}
       };
       rowJson.push_back(userJson);
     }
     seatsJson.push_back(rowJson);
   } 

   json entityJson = {
      {"trainId" , entity.trainId},
      {"name" , entity.name},
      {"source" , entity.source},
      {"destination" , entity.destination},
      {"time" , entity.time},
      {"seats" , seatsJson}
   };

   j.push_back(entityJson);

   ofstream outFile(filename);
   outFile << j.dump(4);
   outFile.close();
}


template <>
vector<Train> FileIO<Train>::readFromFile(){
  vector<Train> entities;
  ifstream file(filename);


  if(!file.is_open()){
     return entities;
  }

  json << j;
  file >> j;
  file.close();


  for(const auto& item : j){
     Train entity;
     entity.trainId = item["trainId"];
     entity.name = item["name"];
     entity.source = item["source"];
     entity.destination = item["destination"];
     entity.time = item["time"];


     // json to seats converting  

     entity.seats.clear();

     for(const auto& rowJson : item["seats"]) {
        vector<User> row;
        for(const auto& userJson : rowJson){
           User user;
           user.userId = userJson["userId"];
           user.name = userJson["name"];
           user.aadharCard = userJson["aadharCard"];
           row.push_back(user);
        }
        entity.seats.push_back(row);
     }
    entities.push_back(entity);
  }
  return entities;
}

// initializing the templates  explicitly 


template class FileIO<Vehicle>;
template class FileIO<Train>;










