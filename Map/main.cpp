#include <iostream>
#include "map.hpp"
#include <utility>
#include <map>
int main() {
    Map<int, double> map;
    map.insert(std::pair(1,3.0));
    map.insert(std::pair(2,-4.0));
    map.insert(std::pair(-5,-3.0));
    map.print();
    std::map<int, double> map2;
    //at/find/extract/max-size/lower bound/upper bound/key comp.valuecomp/merge
    
    return 0;
}