#include <iostream>
#include <cstdlib>
#include <fstream>
#include <random-ppm.h>
#include <default-ppm.h>
#include <text-generator-ppm.h>


int main(int argc, char *argv[]) {
    if (argc == 1) {
        std::cerr << "Too few arguments" << std::endl;
        return 1; //returning 1 means it fails, 0 means success
    } else if (argc > 2) {
        std::cerr << "Too many arguments" << std::endl;
        return 1;
    }

    
    std::string flag {argv[1]};
    if (flag == "-d") {
        defaultPPM(256,256);
    } else if (flag == "-c") {

        int choice;
        std::cout << "Choose your PPM generator\n 0: Random Generator\n 1: Default generator.\n";
        std::cin >> choice;
        int width;
        int height;
        std::cout << "Width: ";
        std::cin >> width;
        std::cout << "Height: ";
        std::cin >> height;



        if (choice == 0) {
            randomPPM(width, height);
        } else if (choice == 1) {
            defaultPPM(width, height);
        } else {
            std::cerr << "Unexpected input.";
        }
        std::cout << std::endl;
    } else if (flag == "-a") {
        textGenerator(256, 256, 'A');
    }
    
    return 0;
}

