#include <iostream>
#include <cmath>
#include <vector>
#include <array>
#include <fstream>


struct Point {
    float x, y, z;
};

struct Triangle {
    Point a, b, c;
};



// size = 6

// traingles = 6 
// vertices = traingles * 9 ; 


// size = 4 
// traingles = 2 
// vertices = 2 * 9 





template<int size>
std::array<float, size * 9   >  makeVertices(float cx, float cy, float R)
{
    constexpr double PI = 3.14159265358979323846;
    std::vector<Point> vert;
    //static float vertices[9 * size ]; 

    std::array<float, 9 * size > vertices;

    for (int i = 0; i < size; ++i) {
        double theta = i * (2 * PI) / size;  // 45° steps
        float x = cx + R * std::cos(theta);
        float y = cy + R * std::sin(theta);
        vert.push_back({ x, y, 0.0f });
    }
    int idx = 0;
    // Form 8 triangles (center + two consecutive vertices)
    for (int i = 0; i < size; ++i) {
        Point a = { cx, cy, 0.0f };
        Point b = vert[i];
        Point c = vert[(i + 1) % size];

        vertices[idx++] = a.x; vertices[idx++] = a.y; vertices[idx++] = a.z;
        vertices[idx++] = b.x; vertices[idx++] = b.y; vertices[idx++] = b.z;
        vertices[idx++] = c.x; vertices[idx++] = c.y; vertices[idx++] = c.z;
    }

    // Debug print

    std::ofstream outf("C:/CS/WEC/WECGL/src/numbers.txt", std::ios::app);

    if (!outf)
    {
        std::cerr << "Cannot write to the file ";
    }

    for (int j = 0; j < size * 9; ++j)
    {
        outf << j << ": " << vertices[j] << (j % 3 == 2 ? "\n" : " ");
        std::cout << j << ": " << vertices[j] << (j % 3 == 2 ? "\n" : " ");
    }

    return vertices;
}


//float* makeHexagonTriangles(float cx, float cy, float R) {
//    std::vector<Point> vert;
//    constexpr double PI = 3.14159265358979323846;
//    static float vertices[54];
//
//    // Compute 6 vertices of the hexagon
//    for (int i = 0; i < 6; ++i) {
//        double theta = i * PI / 3.0;  // 60° steps
//        float x = cx + R * std::cos(theta);
//        float y = cy + R * std::sin(theta);
//        float z = 0.0f;
//
//        vert.push_back({ x, y, z });
//    }
//
//
//    int idx = 0;
//    // Form 6 triangles using (center, vertex[i], vertex[i+1])
//    for (int i = 0; i < 6; ++i) {
//        Point a = { cx, cy, 0.0f };
//        Point b = vert[i];
//        Point c = vert[(i + 1) % 6];
//
//        vertices[idx++] = a.x; vertices[idx++] = a.y; vertices[idx++] = a.z; 
//        vertices[idx++] = b.x; vertices[idx++] = b.y; vertices[idx++] = b.z; 
//        vertices[idx++] = c.x; vertices[idx++] = c.y; vertices[idx++]  = c.z;
//        
//    }
//
//    // Each triangle has 3 vertices × 3 coords = 9 floats → 6 triangles × 9 = 54 floats
//
//    // Print all 54 floats
//    std::ofstream outf("C:/CS/WEC/WECGL/src/numbers.txt", std::ios::app);
//
//    if (!outf)
//    {
//        std::cerr << "Cannot write to the file ";
//    }
//
//    for (int j = 0; j < 54 ; ++j)
//    {
//        outf << j << ": " << vertices[j] << (j % 3 == 2 ? "\n" : " ");
//        std::cout << j << ": " << vertices[j] << (j % 3 == 2 ? "\n" : " ");
//    }
//
//    return vertices;
//}


//float* makeOctagonTriangle(float cx, float cy, float R) {
//    constexpr double PI = 3.14159265358979323846;
//    std::vector<Point> vert;
//    static float vertices[72]; // 8 triangles * 3 vertices * 3 components
//
//    // Compute 8 vertices of the octagon
//    for (int i = 0; i < 8; ++i) {
//        double theta = i * PI / 4.0;  // 45° steps
//        float x = cx + R * std::cos(theta);
//        float y = cy + R * std::sin(theta);
//        vert.push_back({ x, y, 0.0f });
//    }
//
//    int idx = 0;
//    // Form 8 triangles (center + two consecutive vertices)
//    for (int i = 0; i < 8; ++i) {
//        Point a = { cx, cy, 0.0f };
//        Point b = vert[i];
//        Point c = vert[(i + 1) % 8];
//
//        vertices[idx++] = a.x; vertices[idx++] = a.y; vertices[idx++] = a.z;
//        vertices[idx++] = b.x; vertices[idx++] = b.y; vertices[idx++] = b.z;
//        vertices[idx++] = c.x; vertices[idx++] = c.y; vertices[idx++] = c.z;
//    }
//
//    // Debug print
//    std::ofstream outf("C:/CS/WEC/WECGL/src/numbers.txt", std::ios::app);
//
//    if (!outf)
//    {
//        std::cerr << "Cannot write to the file ";
//    }
//
//    for (int j = 0; j < 72 ; ++j)
//    {
//        outf << j << ": " << vertices[j] << (j % 3 == 2 ? "\n" : " ");
//        std::cout << j << ": " << vertices[j] << (j % 3 == 2 ? "\n" : " ");
//    }
//
//    return vertices;
//}

// size == 72 
// triangles == 8 
// 360/8 = 45 

// size = 54 
// traingles == 6 
// 360 / 6 = 60 


