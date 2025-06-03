#pragma once

#include<iostream>
#include<string>
#include<vector> 

using namespace std;

struct User {
   string userId;
   string name;
   string aadharCard;
   vector<Vehicle*> vehicles;
};


