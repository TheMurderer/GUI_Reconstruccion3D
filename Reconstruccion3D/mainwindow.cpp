#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "matching.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->SliderHessian->setMaximum(10000);
    ui->SliderHessian->setMinimum(100);
}

/*Procedimiento para carga una imagen en un label*/
void MainWindow::cargarImagen(Mat &img){
    Mat temp;

    switch (img.type()) {
       case CV_8UC1:
           cvtColor(img,temp, CV_GRAY2RGB);
           break;
       case CV_8UC3:
           cvtColor(img,temp, CV_BGR2RGB);
           break;
    }

    QImage qimg = QImage(temp.data,temp.cols,temp.rows,temp.cols*3, QImage::Format_RGB888);
    ui->Imagen->setPixmap(QPixmap::fromImage(qimg));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_SliderHessian_sliderMoved(int position)
{

}

void MainWindow::on_SliderHessian_valueChanged(int value)
{
    Mat matchImg;
    matching ma;

    // Ejecutamos el calculo del matching entre las imagenes
    matchImg = ma.ejecutar(value);

    this->cargarImagen(matchImg);
    this->show();
    this->repaint();
    this->updateGeometry();
    this->update();
}
