#include <map>
#include <iostream>

int main() {
    std::map<int, double> map;
    map[1] = 2.5;
    map[3] = 3;
    std::cout <<map.count(1) << std::endl; 
    return 0;
}