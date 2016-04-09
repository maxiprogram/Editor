#ifndef GAMEOBJECT2D_H
#define GAMEOBJECT2D_H

#include <qsystemdetection.h>

#ifdef Q_OS_LINUX
    #include "/home/maxiprogram/Project/ForGit/PacManRun/PacManRun/SRC/Engine/resources.h"
#endif

#ifdef Q_OS_WIN32
    #include "E:\Projects\For_Git\PacManRun\PacManRun\SRC\Engine\resources.h"
#endif

class GameObject2D: public GameObject
{
public:
    GameObject2D();
    ~GameObject2D();
    void Init(QHash<QString, QString> property);
    void Update(float dt);
    void Draw();

private:
    int id_sprite;

};

#endif // GAMEOBJECT2D_H
