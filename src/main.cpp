#include <istream>
#include <stdint.h>
#include <vector>

#include <fstream>
#include <iostream>

template <typename T>
struct Point {
        using value_t = T;
        value_t x;
        value_t y;
};

template <typename T>
struct Shape {
        using coordinate_t = T;
        using point_t = Point<coordinate_t>;

        std::vector<point_t> vertices;
};

struct IReader {
};


struct PlainTextReader : IReader {
        template <typename T>
        Shape<T> extract(std::istream& stream) {
                Shape<T> ret;
                while(!stream.eof() && stream.good()) {
                        T x{0};
                        T y{0};
                        stream >> x >> y;
                        Point<T> point{x, y};
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
        const auto external_shape = reader.extract<std::uint32_t>(file);
        for(auto&& point : external_shape.vertices)
                std::cout << point.x << ' ' << point.y << '\n';

        return 0;
}
