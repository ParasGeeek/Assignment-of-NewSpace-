#include<iostream>
#include<fstream>
#include<string>
#include<bits/stdc++.h>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
  vector<string>vect;
  ifstream ip("test.csv");
  if(!ip.is_open()) std::cout<<"Error: File Open" <<'\n';
  string userid;
  string msgCount;
  while(ip.good()){
    getline(ip,userid,',');
    getline(ip,msgCount,'\n');
    vect.push_back(userid);
    vect.push_back(msgCount);
  }
  for(int i=0;i<vect.size();i++){
    std::cout<<vect[i]<<" ";
  }
  std::cout<<endl;
  int len=vect.size()-2;
  vector<pair<string,string>>newvect;
  for(int i=0;i<len;i+=2){
    newvect.push_back(make_pair(vect[i],vect[i+1]));
  }
  std::cout<<"This is content of queue"<<endl;
  for(int j=0;j<(len/2);j++){
    std::cout<<newvect[j].first<<" "<<newvect[j].second<<endl;
  }
  queue<pair<string,string>>qp;
  //****************************
  //qp.push(make_pair(newvect[0].first,newvect[0].second));
  for(int j=0;j<(len/2);j++){
    qp.push(make_pair(newvect[j].first,newvect[j].second));
  }
  vector<string>ans;
  while(!qp.empty()){
    pair<string,string> temp=qp.front();
    qp.pop();
    //std::cout<<temp.first<<" "<<temp.second<<endl;
    int t=stoi(temp.second);
    ans.push_back(temp.first);
    t--;
    if(t!=0){
      temp.second=std::to_string(t);
      qp.push(temp);
    }
  }
  std::cout<<"The uniform scheduling vai cpu..."<<endl;
  for(int i=0;i<ans.size();i++){
    std::cout<<ans[i];
  }
  std::cout<<endl;
  ip.close();
  return 0;
}
