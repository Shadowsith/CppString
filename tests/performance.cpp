#include "./../String.h"
#include <chrono>
#include <iostream>
#include <fstream>
#include <streambuf>
using namespace std::chrono;

std::vector<std::string> split(std::string s, std::string delimiter){
    std::vector<std::string> parts;
    std::size_t pos = 0;
    std::string token;
    while((pos = s.find(delimiter)) != std::string::npos){
        token = s.substr(0,pos);
        parts.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    parts.push_back(s);
    return parts;
}


int main(int argc, char *argv[])
{
    std::ifstream file("./lorem_ipsum.txt");
    std::string str((std::istreambuf_iterator<char>(file)),
        std::istreambuf_iterator<char>());

    std::cout << "Split test:" << std::endl << std::endl;
    for(int i = 0; i < 10; i++) {
    auto start = high_resolution_clock::now();
    str::String s(str); 
    std::vector<str::String> vec0 = s.split(" ");
    auto stop = high_resolution_clock::now();
    auto dur1 = duration_cast<microseconds>(stop - start);

    start = high_resolution_clock::now();
    std::vector<std::string> vec1 = split(str, " ");
    stop = high_resolution_clock::now();
    auto dur2 = duration_cast<microseconds>(stop - start);

    std::cout << "String: " <<  dur1.count() << "mics" << std::endl;
    std::cout << "std::string " << dur2.count() << "mics" << std::endl;
    std::cout << "Lost: " << dur1.count()*100/dur2.count()-100 << "%" << std::endl;
    }


    return 0;
}
