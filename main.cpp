#include <iostream>
#include <fstream>

#include "color.h"
#include "vec3.h"

int main() {

    // Image
    std::ofstream os{ "result.ppm" };
    int image_width = 256;
    int image_height = 256;

    // Render

    os << "P3\n" << image_width << ' ' << image_height << "\n255\n";
    for (int j = 0; j < image_height; j++) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; i++) {
            auto pixel_color = color(
                double(i) / (image_width - 1),
                double(j) / (image_height - 1),
                0
            );

            write_color(os, pixel_color);
        }
    }

    std::clog << "\rDone.                 \n";
}