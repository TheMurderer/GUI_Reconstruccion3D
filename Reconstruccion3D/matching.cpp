#include "matching.h"


#define _SURF_ 1
//#define _SIFT_ 1



matching::matching()
{ }



    // Código de ayuda para el uso de los detectores SURF o SIFT
    void matching::surf(Mat& img1, vector<KeyPoint>& keypoints,unsigned int minHessian){
            #if  _SURF_
            //int minHessian = 5000; // valor de unbral para la deteccion de puntos, cambiar si es necesario
            SurfFeatureDetector detector( minHessian );
            detector.detect(img1, keypoints);
            #else if _SIFT_
            double sigma=1;
            int puntos=1000;
            SiftFeatureDetector detector(puntos,3,0.06,10,sigma);
            detector.detect(img1, keypoints);
            #endif
    }

    void matching::computeMatching(Mat& img1, Mat& img2,vector<KeyPoint>& keypoints1,vector<KeyPoint>& keypoints2, vector<DMatch>& matches ){
            // computing descriptors
            #if _SURF_
            SurfDescriptorExtractor extractor;
            #else if _SIFT_
            SiftDescriptorExtractor extractor;
            #endif
            Mat descriptors1, descriptors2;
            extractor.compute(img1, keypoints1, descriptors1);
            extractor.compute(img2, keypoints2, descriptors2);

            // matching descriptors
            bool crossCheck=1;

            //BFMatcher match;
            BFMatcher matcher(NORM_L2,crossCheck);
            matcher.match(descriptors1, descriptors2, matches);
    }

    void matching::imprimirKeipoints(vector<KeyPoint> puntos){
        for(unsigned int i = 0; i < puntos.size(); i++){
            cout << "("  << puntos[i].pt.x << " , " << puntos[i].pt.y << ")" << endl;
        }
    }

    Mat matching::procesoMatch(unsigned int minHessian){

        // Obtenemos los puntos en correspondencias de forma automática usando SURF
        vector<KeyPoint> keypoints1, keypoints2;
        vector<DMatch> matches;

        surf(img1Canny, keypoints1,minHessian);
        surf(img2Canny, keypoints2,minHessian);

        //Hacemos el matching de los puntos encontrados en las imagenes
        computeMatching(img1Canny, img2Canny, keypoints1, keypoints2, matches);

        Mat matchImg;
        drawMatches(img1Canny,keypoints1,img2Canny,keypoints2,matches,matchImg);

        //Decolvemos la matriz de la imagen resultado del match
        return matchImg;
    }

    Mat matching::ejecutar(int value){
        //-- Leemos las imagenes - convirtiendolas en estala de grises
        Mat img1 = imread("Imagenes/img1.bmp",CV_LOAD_IMAGE_GRAYSCALE);
        Mat img2 = imread("Imagenes/img2.bmp",CV_LOAD_IMAGE_GRAYSCALE);

        //Aplicacmos Canny  -- Detección de bordes
        //(así desminuimos la cantidad de puntos a detectar)

        Canny(img1,img1Canny,50,200,3);
        Canny(img1,img2Canny,50,200,3);

        Mat matchImg;
        matchImg = procesoMatch(value);
        return matchImg;

    }



