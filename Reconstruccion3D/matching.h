#ifndef MATCHING_H
#define MATCHING_H

#include <iostream>
#include <vector>
#include<opencv2/opencv.hpp>
#include<opencv2/nonfree/features2d.hpp>
#include <fstream>

using namespace cv;
using namespace std;


class matching
{
public:

    Mat img1Canny,img2Canny;

    matching();
    void surf(Mat& img1, vector<KeyPoint>& keypoints,unsigned int minHessian);
    void computeMatching(Mat& img1, Mat& img2,vector<KeyPoint>& keypoints1,vector<KeyPoint>& keypoints2, vector<DMatch>& matches );
    void imprimirKeipoints(vector<KeyPoint> puntos);
    Mat procesoMatch(unsigned int minHessian);
    Mat ejecutar(int value);
};

#endif // MATCHING_H
