#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <QGLWidget>
#include <QKeyEvent>
#include <QTimer>
#include "Square.h"

class Scene : public QGLWidget
{
    Q_OBJECT

public:
    Scene( QWidget *parent = 0 );

private slots:
    void slotUpdate();

private:
    void initializeGL();
    void paintGL();
    void resizeGL( int w, int h );

    void keyPressEvent( QKeyEvent *event );
    void genTextures();
    void genFrames();

private:
    Square square;
    unsigned int textureID;
    std::vector<unsigned int> textureIdArray;
    std::vector<QPixmap> frames;
    QTimer timer;
};

#endif // SCENE_H
