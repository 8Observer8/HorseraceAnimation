#ifndef SQUARE_H
#define SQUARE_H

#include <vector>
#include <GL/gl.h>

class Square
{
public:
    Square();
    void draw( unsigned int textureID ) const;
    void init();

    std::vector<int> vertices;
    std::vector<unsigned int> indices;
    //std::vector<float> colors;
    std::vector<float> textures;
};

#endif // SQUARE_H
