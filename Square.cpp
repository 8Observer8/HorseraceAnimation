#include <QPixmap>
#include <QString>
#include "Square.h"

Square::Square()
{
    init();
}

void Square::draw( unsigned int textureID ) const
{
    glBindTexture( GL_TEXTURE_2D, textureID );

    // Указываем, откуда нужно извлечь данные о массиве вершин
    glVertexPointer( 3, GL_INT, 0, vertices.data() );

    // Указываем, откуда нужно извлечь данные о текстурных координатах
    glTexCoordPointer( 2, GL_FLOAT, 0, textures.data() );

    // Указываем, откуда нужно извлечь данные о массиве цветов вершин
    //glColorPointer( 3, GL_FLOAT, 0, colors.data() );

    // Используя массивы вершин и индексов, строим поверхности
    glDrawElements( GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, indices.data() );
}

void Square::init()
{
    // Первый треугольник
    // 0
    vertices.push_back( -1 );    // X
    vertices.push_back( -1 );    // Y
    vertices.push_back( 0 );     // Z

    // 1
    vertices.push_back( 1 );     // X
    vertices.push_back( -1 );    // Y
    vertices.push_back( 0 );     // Z

    // 2
    vertices.push_back( -1 );    // X
    vertices.push_back( 1 );     // Y
    vertices.push_back( 0 );     // Z

    // Второй треугольник
    // 3
    vertices.push_back( -1 );    // X
    vertices.push_back( 1 );     // Y
    vertices.push_back( 0 );     // Z

    // 4
    vertices.push_back( 1 );     // X
    vertices.push_back( -1 );    // Y
    vertices.push_back( 0 );     // Z

    // 5
    vertices.push_back( 1 );     // X
    vertices.push_back( 1 );     // Y
    vertices.push_back( 0 );     // Z

    for ( unsigned int i = 0; i < 6; ++i ) {
        indices.push_back( i );
    }

    textures.push_back( 0 );    // S
    textures.push_back( 0 );    // T

    textures.push_back( 1 );    // S
    textures.push_back( 0 );    // T

    textures.push_back( 0 );    // S
    textures.push_back( 1 );    // T

    textures.push_back( 0 );    // S
    textures.push_back( 1 );    // T

    textures.push_back( 1 );    // S
    textures.push_back( 0 );    // T

    textures.push_back( 1 );    // S
    textures.push_back( 1 );    // T

//    for ( unsigned int i = 0; i < 6; ++i ) {
//        colors.push_back( 0 );   // R
//        colors.push_back( 1 );   // G
//        colors.push_back( 0 );   // B
//    }
}
