#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <iterator>

std::string getCmdOption(char ** begin, char ** end, const std::string & option)
{
    char ** itr = std::find(begin, end, option);
    if (itr != end && ++itr != end)
    {
        return std::string(*itr);
    }
    return "";
}

int main(int argc, char* argv[]) {
    std::vector<std::string> args(argv, argv + argc);
    std::string delimiter = getCmdOption(argv, argv + argc, "--delimiter");

    if (delimiter.empty()) {
        delimiter = " "; // default delimiter is space
    }

    std::string decimal(std::istreambuf_iterator<char>(std::cin), {});

    if (!decimal.empty()) {
        size_t pos = 0;
        std::string token;
        while ((pos = decimal.find(delimiter)) != std::string::npos) {
            token = decimal.substr(0, pos);
            std::cout << static_cast<char>(std::stoi(token));
            decimal.erase(0, pos + delimiter.length());
        }
        std::cout << static_cast<char>(std::stoi(decimal));
    } else {
        std::cout << "No decimal representation was given." << std::endl;
    }

    return 0;
}

/*
To compile this program, you can use the g++ compiler. Here's the command:
g++ -o program source.cpp

This will compile the source.cpp file and create an executable named 'program'.

If you don't have the g++ compiler installed, you can install it on Debian with the following command:
sudo apt-get install build-essential

The 'build-essential' package includes the g++ compiler along with other tools necessary for building software.
*/