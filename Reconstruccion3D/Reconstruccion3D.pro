#-------------------------------------------------
#
# Project created by QtCreator 2013-02-24T12:12:15
#
#-------------------------------------------------

QT       += core gui

TARGET = Reconstruccion3D
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    matching.cpp

HEADERS  += mainwindow.h \
    matching.h

FORMS    += mainwindow.ui

INCLUDEPATH += /usr/local/include/
INCLUDEPATH += /usr/include/pcl-1.6/
INCLUDEPATH += /usr/include/boost
INCLUDEPATH += /usr/include/eigen3/Eigen

LIBS += -L/usr/local/lib \
-lopencv_core \
-lopencv_imgproc \
-lopencv_highgui \
-lopencv_ml \
-lopencv_video \
-lopencv_features2d \
-lopencv_calib3d \
-lopencv_objdetect \
-lopencv_contrib \
-lopencv_legacy \
-lopencv_nonfree \
-lopencv_flann

CONFIG += link_pkgconfig
PKGCONFIG += pcl_registration-1.6
PKGCONFIG += pcl_geometry-1.6
PKGCONFIG += pcl_features-1.6
PKGCONFIG += pcl_search-1.6
PKGCONFIG += pcl_kdtree-1.6
PKGCONFIG += pcl_filters-1.6
PKGCONFIG += pcl_surface-1.6
PKGCONFIG += pcl_octree-1.6
PKGCONFIG += pcl_sample_consensus-1.6
PKGCONFIG += pcl_segmentation-1.6
PKGCONFIG += pcl_visualization-1.6
PKGCONFIG += pcl_io-1.6
PKGCONFIG += pcl_apps-1.6
PKGCONFIG += pcl_keypoints-1.6
PKGCONFIG += pcl_tracking-1.6
