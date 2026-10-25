#include <iostream>
#include <fstream>

#include "color.h"
#include "vec3.h"
#include <cmath>

bool onLine(point3 current, point3 p1, point3 p2);

int textGenerator(int width, int height, char letter) {
     // Image 
    int image_width = width;
    int image_height = height;

    //Instead of doing this one can route from the std out to a file using > in the terminal. 
    std::ofstream filePPM("out.ppm", std::ios::out);

    // Start Rendering

    filePPM << "P3\n" << image_width << ' ' << image_height << "\n255\n";
    point3 p1{0.1 * width, height * 0.5, 0};
    point3 p2{0.9 * width, height * 0.5, 0};
    point3 p3{0.5 * width, height * 0.1, 0};
    point3 p4{0.1 * width, height * 0.9, 0};
    point3 p5{0.9 * width, height * 0.9, 0};

    for (int j = 0; j < image_height; j++) {
        for (int i = 0; i < image_width; i++) {

            point3 current{double(i),double(j),0};
            if (onLine(current, p1, p2) or onLine(current, p3, p4) or onLine(current, p3, p5) ) {
                auto r = 0;
                auto g = 0;
                auto b = 0;
                auto pixel_color = color(r, g, b);
                write_color(filePPM, pixel_color);
            } else {
                auto r = 255;
                auto g = 255;
                auto b = 255;
                auto pixel_color = color(r, g, b);
                write_color(filePPM, pixel_color);
            }

    
            
        }
        filePPM << '\n';
    }
    return 0;
}

bool onLine(point3 current, point3 p1, point3 p2) {
    double v1 = (current.y() - p1.y())/(current.x() - p1.x());
    double v2 = (current.y() - p2.y())/(current.x() - p2.x());

    double xmin{std::min(p1.x(), p2.x())};
    double xmax{std::max(p1.x(), p2.x())};

    double ymin{std::min(p1.y(), p2.y())};
    double ymax{std::max(p1.y(), p2.y())};

    bool inXrange{current.x() >= xmin and current.x() <= xmax};

    bool inYrange{current.y() >= ymin and current.y() <= ymax};

    if ((abs((v1-v2)) < 0.1) and inXrange and inYrange) {
        return true;
    } else {
        return false;
    }

    
}




