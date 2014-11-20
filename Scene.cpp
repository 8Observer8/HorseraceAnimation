#include "Scene.h"
#include <QDebug>

Scene::Scene( QWidget *parent ) :
    QGLWidget( parent )
{
    this->setFocusPolicy( Qt::StrongFocus );
    connect( &timer, SIGNAL( timeout() ),
             this, SLOT( slotUpdate() ) );
    timer.start( 50 );
}

void Scene::initializeGL()
{
    // Цвет для очистки буфера изображения - будет просто фон окна
    glClearColor( 1.0f, 1.0f, 1.0f, 1.0f );

    // Устанавливает режим проверки глубины пикселей
    glEnable( GL_DEPTH_TEST );

    // Отключает режим сглаживания цветов
    glShadeModel( GL_FLAT );

    // Устанавливаем режим, когда строятся только внешние поверхности
    glEnable( GL_CULL_FACE );

    glEnable( GL_TEXTURE_2D);

    genTextures();

    // Активизация массива вершин
    glEnableClientState( GL_VERTEX_ARRAY );

    // Активизация массива текстурных координат
    glEnableClientState( GL_TEXTURE_COORD_ARRAY );
}

void Scene::paintGL()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    square.draw( textureID );
}

void Scene::resizeGL( int w, int h )
{
    glViewport( 0, 0, w, h );

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();

    int left = -( this->width()/2 );
    int right = this->width()/2;
    int bottom = -( this->height()/2 );
    int top = this->height()/2;

    //glOrtho( left, right, bottom, top, 1, -1 );
    glOrtho( -2, 2, -2, 2, 1, -1);

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
}

void Scene::keyPressEvent( QKeyEvent *event )
{
    switch( event->key() ) {
        case Qt::Key_Up:
            //qDebug() << "key up";
            break;
        case Qt::Key_Left:
            break;
        case Qt::Key_Down:
            break;
        case Qt::Key_Right:
            break;
    }
}

void Scene::genTextures()
{
    genFrames();

    for( size_t i = 0; i < frames.size(); ++i ) {
        textureIdArray.push_back( bindTexture( frames[i], GL_TEXTURE_2D ) );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );
    }

    if ( frames.size() == 15 ) {
        textureID = textureIdArray[0];
    }
}

void Scene::genFrames()
{
    QPixmap pixmap = QPixmap( QString( ":Textures/sprite-horse" ) );
    const unsigned int wStep = pixmap.width() / 4;
    const unsigned int hStep = pixmap.height() / 4;
    QPixmap copyPixmap;
    for ( unsigned int i = 0; i < 4; ++i ) {
        for ( unsigned int j = 0; j < 4; ++j ) {
            copyPixmap = pixmap.copy( j * wStep, i * hStep, wStep, hStep );
            frames.push_back( copyPixmap );
        }
    }
    frames.pop_back();
}

void Scene::slotUpdate()
{
    static int i = 0;

    if ( i == 15 ) {
        i = 0;
    }

    if ( textureIdArray.size() == 15 ) {
        textureID = textureIdArray[i];
    }

    ++i;
    updateGL();
}
