#include <QtGui/QApplication>
#include "mainwindow.h"

#include <iostream>
#include <vector>
#include<opencv2/opencv.hpp>
#include<opencv2/nonfree/features2d.hpp>
#include <fstream>
#include "matching.h"
using namespace cv;
using namespace std;

//Funciones

#define _SURF_ 1
//#define _SIFT_ 1




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //*****************Proceso de OpenCV


    Mat matchImg;

    matching ClaseEnlace;

    matchImg = ClaseEnlace.ejecutar(2000);

    //mostramos la imagen en la interfaz
    w.cargarImagen(matchImg);
    w.show();

    return a.exec();
}
