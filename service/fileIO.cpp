#include<iostream>
#include "../external/json.hpp"
#include "../entities/vehicle.hpp"
#include<fstream>






using namespace std;

// json file decleration 

using json = nlohmann::json;

template <typename T>
class FileIO {
   private:  
      const string filename = "db.json";



  public:
    void saveToFile(T entity){
       json j;
       ifstream file(filename);


       if(file.is_open()){
         file >> j;
         file.close();
       }

       json entityJson = {
         {"trainId" , entity.vehicleId},
         {"name" , entity.name},
         {"source" , entity.source},
         {"destination" , entity.destination},
         {"time" , entity.time},
         {"seats" , entity.seats}
       };

     j.push_back(entityJson);


     ofstream outFile(filename);
     outFile << j.dump(4);
     outFile.close();
    }


    vector<T> readFromFile() {
       vector<T> entities;
       ifstream file(filename);


       if(!file.is_open()){
         return entities;
       }


       json j;
       file >> j;
       file.close();


       for(const auto& item : j){
         T entity;
         entity.vehicleId = item["vehicleId"];
         entity.name = item["name"];
         entity.source = item["source"];
         entity.destination = item["destination"];
         entity.time = item["time"];
         entity.seats = item["seats"].get<vector<vector<int>>>();
         entities.push_back(entity);
       }
       return entities;
    }
       
};


