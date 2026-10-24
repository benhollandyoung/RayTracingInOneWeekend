#include <iostream>
#include <cstdlib>>
#include <fstream>

int main() {
    // Image 
    int image_width = 3;
    int image_height = 2;

    //Instead of doing this one can route from the std out to a file using > in the terminal. 
    std::ofstream filePPM("out.ppm", std::ios::out);

    // Start Rendering

    filePPM << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    // j = row, i = column
    for (int j = 0; j < image_height; j++) {
        for (int i = 0; i < image_width; i++) {

            auto r = rand() % 256;
            auto g = rand() % 256;
            auto b = rand() % 256;


            filePPM << r << ' ' << g << ' ' << b << "\n";
        }
        filePPM << '\n';
    }
    return 0;
}