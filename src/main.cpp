#include <istream>
#include <stdint.h>
#include <vector>

#include <fstream>
#include <iostream>

using Coordinate_t = std::uint32_t;
using Rotate_t = float;


struct Point {
        Coordinate_t x;
        Coordinate_t y;
};


struct Shape {
        std::vector<Point> vertices;
};


struct Object {
        Shape shape;
        Rotate_t tilt;
        Point position;
};

struct IReader {
};


struct PlainTextReader : IReader {
        Shape extract(std::istream& stream) {
                Shape ret;
                while(!stream.eof() && stream.good()) {
                        Coordinate_t x{0};
                        Coordinate_t y{0};
                        stream >> x >> y;
                        Point point{x, y};
                        ret.vertices.push_back(point);
                }
                return ret;
        }
};

int main() {
        std::fstream file("external_shape_01.txt", std::ios_base::in);
        if (!file.is_open()) {
                std::cout << "Cannot open file!\n";
                return 1;
        }

        PlainTextReader reader;
        const auto external_shape = reader.extract(file);
        for(auto&& point : external_shape.vertices)
                std::cout << point.x << ' ' << point.y << '\n';

        return 0;
}
