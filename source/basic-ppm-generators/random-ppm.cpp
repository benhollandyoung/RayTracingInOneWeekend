#include <iostream>
#include <cstdlib>
#include <fstream>

#include "color.h"
#include "vec3.h"

int randomPPM(int width, int height) {
     // Image 
    int image_width = width;
    int image_height = height;

    //Instead of doing this one can route from the std out to a file using > in the terminal. 
    std::ofstream filePPM("out.ppm", std::ios::out);

    // Start Rendering

    filePPM << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; j++) {
        for (int i = 0; i < image_width; i++) {

    
            auto r = rand() % 256;
            auto g = rand() % 256;
            auto b = rand() % 256;
            auto pixel_color = color(r, g, b);


            write_color(filePPM, pixel_color);
        }
        filePPM << '\n';
    }
    return 0;
}
    
