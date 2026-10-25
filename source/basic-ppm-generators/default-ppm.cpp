#include <iostream>
#include <fstream>

#include "color.h"
#include "vec3.h"

int defaultPPM(int width, int height) {
    // Image 
    int image_width = width;
    int image_height = height;

    //Instead of doing this one can route from the std out to a file using > in the terminal. 
    // std::ofstream filePPM("out.ppm", std::ios::out);

    // Start Rendering

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    // j = row, i = column
    for (int j = 0; j < image_height; j++) {
        std::clog << "\rScanlines remaining: " << (image_height-j) << ' ' << std::flush;
        for (int i = 0; i < image_width; i++) {

            auto r = double(i) / (image_width -1);
            auto g = double(j) / (image_height -1);
            auto b = 0.0;

            auto pixel_color = color(r, g, b);

            write_color(std::cout, pixel_color);
        }
    }

    std::clog << "\rDone        \n";
    return 0;

}