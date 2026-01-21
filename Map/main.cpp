#include <iostream>
#include "map.hpp"
#include <utility>
#include <map>

int main() {

    std::map<int, double> smap;
    smap[5] = 3.5;
    struct mycomp {
        bool operator()(const int& a, const int& b) const {
            return a > b;
        }
    };
    Map<int, double, mycomp> map;
    map.insert(std::pair(1,3.0));
    map.insert(std::pair(2,-4.0));
    map.insert(std::pair(-5,-3.0));
    if(map.contains(1)) {
        std::cout << "yes\n";
    }
    if(map.contains(2)) {
        std::cout << "yes\n";
    }
    if(!map.contains(5)) {
        std::cout << "no\n";
    }
    if(map.contains(-5)) {
        std::cout << "yes\n";
    }
    map.print();
    auto it = map.find(-5);
    std::cout << it->first << " " << it->second << std::endl;
    //at/find/extract/max-size/lower bound/upper bound//merge

    
    return 0;
}