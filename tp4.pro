QT += network

INCLUDEPATH += $$PWD
SOURCES += $$PWD/openglwindow.cpp \
    particules.cpp \
    point.cpp \
    trianglewindow.cpp \
    filemanager.cpp \
    ply.cpp \
    face.cpp
HEADERS += $$PWD/openglwindow.h \
    particules.h \
    point.h \
    trianglewindow.h \
    filemanager.h \
    ply.h \
    face.h

SOURCES += \
    main.cpp

target.path = $$[QT_INSTALL_EXAMPLES]/gui/openglwindow
INSTALLS += target
QMAKE_MAC_SDK = macosx10.11

RESOURCES += \
    gestionnaire.qrc
