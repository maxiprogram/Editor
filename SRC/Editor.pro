#-------------------------------------------------
#
# Project created by QtCreator 2016-04-05T12:55:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets opengl

TARGET = Editor
TEMPLATE = app


SOURCES += main.cpp\
        mainform.cpp \
    testgl.cpp \
    ../../../PacManRun/PacManRun/SRC/Engine/camera.cpp \
    ../../../PacManRun/PacManRun/SRC/Engine/creatorgameobject.cpp \
    ../../../PacManRun/PacManRun/SRC/Engine/font.cpp \
    ../../../PacManRun/PacManRun/SRC/Engine/fps.cpp \
    ../../../PacManRun/PacManRun/SRC/Engine/gameobject.cpp \
    ../../../PacManRun/PacManRun/SRC/Engine/gamescene.cpp \
    ../../../PacManRun/PacManRun/SRC/Engine/geometry.cpp \
    ../../../PacManRun/PacManRun/SRC/Engine/layer.cpp \
    ../../../PacManRun/PacManRun/SRC/Engine/managercamera.cpp \
    ../../../PacManRun/PacManRun/SRC/Engine/managerfont.cpp \
    ../../../PacManRun/PacManRun/SRC/Engine/managergameobject.cpp \
    ../../../PacManRun/PacManRun/SRC/Engine/managergamescene.cpp \
    ../../../PacManRun/PacManRun/SRC/Engine/managerkeyboard.cpp \
    ../../../PacManRun/PacManRun/SRC/Engine/managermesh.cpp \
    ../../../PacManRun/PacManRun/SRC/Engine/managermouse.cpp \
    ../../../PacManRun/PacManRun/SRC/Engine/managershader.cpp \
    ../../../PacManRun/PacManRun/SRC/Engine/managersprite.cpp \
    ../../../PacManRun/PacManRun/SRC/Engine/managertexture.cpp \
    ../../../PacManRun/PacManRun/SRC/Engine/managertilemap.cpp \
    ../../../PacManRun/PacManRun/SRC/Engine/mesh.cpp \
    ../../../PacManRun/PacManRun/SRC/Engine/object3d.cpp \
    ../../../PacManRun/PacManRun/SRC/Engine/resources.cpp \
    ../../../PacManRun/PacManRun/SRC/Engine/setting.cpp \
    ../../../PacManRun/PacManRun/SRC/Engine/shader.cpp \
    ../../../PacManRun/PacManRun/SRC/Engine/sprite.cpp \
    ../../../PacManRun/PacManRun/SRC/Engine/texture.cpp \
    ../../../PacManRun/PacManRun/SRC/Engine/tilemap.cpp \
    ../../../PacManRun/PacManRun/SRC/Engine/transformer.cpp \
    previewtextureform.cpp \
    previewshaderform.cpp \
    previewmeshform.cpp \
    addspriteform.cpp

HEADERS  += mainform.h \
    testgl.h \
    ../../../PacManRun/PacManRun/SRC/Engine/camera.h \
    ../../../PacManRun/PacManRun/SRC/Engine/creatorgameobject.h \
    ../../../PacManRun/PacManRun/SRC/Engine/engine.h \
    ../../../PacManRun/PacManRun/SRC/Engine/font.h \
    ../../../PacManRun/PacManRun/SRC/Engine/fps.h \
    ../../../PacManRun/PacManRun/SRC/Engine/gameobject.h \
    ../../../PacManRun/PacManRun/SRC/Engine/gamescene.h \
    ../../../PacManRun/PacManRun/SRC/Engine/geometry.h \
    ../../../PacManRun/PacManRun/SRC/Engine/layer.h \
    ../../../PacManRun/PacManRun/SRC/Engine/managercamera.h \
    ../../../PacManRun/PacManRun/SRC/Engine/managerfont.h \
    ../../../PacManRun/PacManRun/SRC/Engine/managergameobject.h \
    ../../../PacManRun/PacManRun/SRC/Engine/managergamescene.h \
    ../../../PacManRun/PacManRun/SRC/Engine/managerkeyboard.h \
    ../../../PacManRun/PacManRun/SRC/Engine/managermesh.h \
    ../../../PacManRun/PacManRun/SRC/Engine/managermouse.h \
    ../../../PacManRun/PacManRun/SRC/Engine/managershader.h \
    ../../../PacManRun/PacManRun/SRC/Engine/managersprite.h \
    ../../../PacManRun/PacManRun/SRC/Engine/managertexture.h \
    ../../../PacManRun/PacManRun/SRC/Engine/managertilemap.h \
    ../../../PacManRun/PacManRun/SRC/Engine/mesh.h \
    ../../../PacManRun/PacManRun/SRC/Engine/object3d.h \
    ../../../PacManRun/PacManRun/SRC/Engine/resources.h \
    ../../../PacManRun/PacManRun/SRC/Engine/setting.h \
    ../../../PacManRun/PacManRun/SRC/Engine/shader.h \
    ../../../PacManRun/PacManRun/SRC/Engine/sprite.h \
    ../../../PacManRun/PacManRun/SRC/Engine/texture.h \
    ../../../PacManRun/PacManRun/SRC/Engine/tilemap.h \
    ../../../PacManRun/PacManRun/SRC/Engine/transformer.h \
    previewtextureform.h \
    previewshaderform.h \
    previewmeshform.h \
    addspriteform.h

FORMS    += mainform.ui \
    previewtextureform.ui \
    previewshaderform.ui \
    previewmeshform.ui \
    addspriteform.ui
