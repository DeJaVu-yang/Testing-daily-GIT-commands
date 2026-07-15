#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <algorithm>
int main() {
   std::vector<int> v;
   v.push_back(1);
   v.push_back(2);
   v.push_back(3);
   v.push_back(3);
   v.push_back(25);
   for (size_t i = 0; i < v.size(); i++) {
    std::cout<<v[i]<<" ";
   }
 auto it = find(v.begin(), v.end(), 3);
 std::cout<<"find: "<<*it<<std::endl;
 v.erase(it);
 std::cout<<"after erase: ";

 for (size_t i = 0; i < v.size(); i++) {
    std::cout<<v[i]<<" ";
 }
 std::cout<<std::endl;

}