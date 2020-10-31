#include<iostream>
#include<fstream>
#include<string>
#include<bits/stdc++.h>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
  map<string,string>mp;
  ifstream ip("test1.csv");
  if(!ip.is_open()) std::cout<<"Error: File Open" <<'\n';
  string time_stamp;
  string info;
  while(ip.good()){
    getline(ip,time_stamp,',');
    getline(ip,info,'\n');
    mp[time_stamp]=info;
  }
  int len=mp.size();
  std::cout<<len<<endl;
  ifstream ip1("test2.csv");
  if(!ip1.is_open()) std::cout<<"Error: File Open"<<endl;
  string time_stamp1;
  string info1;
  while(ip1.good()){
    getline(ip1,time_stamp1,',');
    getline(ip1,info1,'\n');
    if(mp.find(time_stamp1)!=mp.end()){
      mp[time_stamp1]=mp[time_stamp1]+" "+info1;
    }
    else{
      mp[time_stamp1]=info1;
    }
  }
  int newLen=mp.size();
  std::cout<<newLen<<endl;
  std::cout<<"Result after merging two csv files based on common key(time_stamp)...."<<endl;
  std::cout<<"......................................"<<endl;
  int g=0;
  ///Final step to store the result into csv file...
  std::ofstream myFile("result.csv");
  for(auto itr : mp){
      if(g>0 && g<newLen-2){
        std::cout<<itr.first<<" "<<itr.second<<endl;
      //  myFile << itr.first;
        myFile << itr.first <<","<<itr.second <<endl;
      }
      g++;
  }
  myFile.close();
  ip1.close();
  ip1.close();
  return 0;
}
