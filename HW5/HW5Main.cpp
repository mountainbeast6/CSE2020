#include <iostream>
#include<fstream>
#include "Map.h"
#include "Pair.h"
#include "Vector.h"
using namespace std;
int main(){
  ifstream file;
  Map<string, Pair<double, double> > a;
  file.open("latitudes.txt");
  string line;
  string name;
  string temps;
  Pair<double, double> p1;
  double lon;
  double lat;
  int temp;
  bool loop = true;
  string enetered1;
  string enetered2;
  for(getline(file, line);file.good();getline(file, line)){
    temp = line.find_first_of(" ")+1;
    name = line.substr(0,temp);
    temps = line.substr(temp);
    lon=stod(temps.substr(0, temps.find_first_of(" ")));
    lat=stod(temps.substr(temps.find_first_of(" ")));
    p1.first=lon;
    p1.second=lat;
    a[name]=p1;
    cout<< name << endl;
  }
  file.close();
  while(loop){
    cout<<"Hi there! Please Choose One of the Listed World Capitals! "<< endl;
    cin>>enetered1;
    cout<<"Alright now pick another! "<< endl;
    cin>> entered2;

  }
  return 0;
}
double Haversine(double lon1, double lon2, double lat1, double lat2){
  return 0.0;
}
