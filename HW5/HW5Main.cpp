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
  string lon;
  string lat;
  int temp;
  while(file.good()){
    getline(file, line);
    temp = line.find_first_of(" ");
    name = line.substr(0,temp);
    temps = line.substr(temp);
    lon=temps.substr(0, temps.find_first_of(" ")-1);
    lat=temps.substr(temps.find_first_of(" "));
    // p1=(lon, lat);
    // a[name]=p1;
    cout<< name << endl<< lon<< " "<< lat<< endl;
  }
  file.close();
}
