#-------------------------------------------------
#
# Project created by QtCreator 2016-04-05T12:55:10
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Editor
TEMPLATE = app


SOURCES += main.cpp\
        mainform.cpp \
    previewtextureform.cpp \
    previewshaderform.cpp \
    previewmeshform.cpp \
    addspriteform.cpp \
    scene.cpp \
    setprojectionform.cpp \
    creategameobject2dform.cpp \
    gameobject2d.cpp \
    Engine/camera.cpp \
    Engine/creatorgameobject.cpp \
    Engine/font.cpp \
    Engine/fps.cpp \
    Engine/gameobject.cpp \
    Engine/gamescene.cpp \
    Engine/geometry.cpp \
    Engine/layer.cpp \
    Engine/managercamera.cpp \
    Engine/managerfont.cpp \
    Engine/managergameobject.cpp \
    Engine/managergamescene.cpp \
    Engine/managerkeyboard.cpp \
    Engine/managermesh.cpp \
    Engine/managermouse.cpp \
    Engine/managershader.cpp \
    Engine/managersprite.cpp \
    Engine/managertexture.cpp \
    Engine/managertilemap.cpp \
    Engine/mesh.cpp \
    Engine/object3d.cpp \
    Engine/resources.cpp \
    Engine/setting.cpp \
    Engine/shader.cpp \
    Engine/sprite.cpp \
    Engine/texture.cpp \
    Engine/tilemap.cpp \
    Engine/transformer.cpp

HEADERS  += mainform.h \
    previewtextureform.h \
    previewshaderform.h \
    previewmeshform.h \
    addspriteform.h \
    scene.h \
    setprojectionform.h \
    creategameobject2dform.h \
    gameobject2d.h \
    Engine/camera.h \
    Engine/creatorgameobject.h \
    Engine/engine.h \
    Engine/font.h \
    Engine/fps.h \
    Engine/gameobject.h \
    Engine/gamescene.h \
    Engine/geometry.h \
    Engine/layer.h \
    Engine/managercamera.h \
    Engine/managerfont.h \
    Engine/managergameobject.h \
    Engine/managergamescene.h \
    Engine/managerkeyboard.h \
    Engine/managermesh.h \
    Engine/managermouse.h \
    Engine/managershader.h \
    Engine/managersprite.h \
    Engine/managertexture.h \
    Engine/managertilemap.h \
    Engine/mesh.h \
    Engine/object3d.h \
    Engine/resources.h \
    Engine/setting.h \
    Engine/shader.h \
    Engine/sprite.h \
    Engine/texture.h \
    Engine/tilemap.h \
    Engine/transformer.h

FORMS    += mainform.ui \
    previewtextureform.ui \
    previewshaderform.ui \
    previewmeshform.ui \
    addspriteform.ui \
    setprojectionform.ui \
    creategameobject2dform.ui
