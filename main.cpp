//
// Created by jonel on 9/19/2023.
//
#include <iostream>
#include "string.h"


int main(){
    ion::string s = "Syntax:<nominal resistance> <measured resistance> \nInput nominal resistance and measured resistance, input -1 to quit:";
    std::cout<<s<<std::endl;
    double nominalResistance, measuredResistance;
    while(1) {
        std::cin >> nominalResistance;
        if(nominalResistance ==-1){
            break;
        }
        std::cin >> measuredResistance;
        if(measuredResistance == -1){
            break;
        }
        std::cout << (ion::abs(nominalResistance - measuredResistance) / nominalResistance) * 100 << std::endl;

    }
    ion::vector<double> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    std::cout << v[1] << std::endl<<v.size()<<std::endl;

    return 0;
}