#include "opencv2/imgcodecs/imgcodecs.hpp"
#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdio.h>

using namespace std;
using namespace cv;


int main( int argc, char** argv )
{
    Mat im_left=imread("/media/ankushbraj/02810E551F2735A4/ubuntu desktop/qt creater/im0.ppm");
    Mat im_right=imread("/media/ankushbraj/02810E551F2735A4/ubuntu desktop/qt creater/im1.ppm");
    cv::Size imagesize = im_left.size();
    cv::Mat disparity_left=cv::Mat(imagesize.height,imagesize.width,CV_16S);
    cv::Mat g1,g2,disp1,disp2;
    cv::cvtColor(im_left,g1,cv::COLOR_BGR2GRAY);
    cv::cvtColor(im_right,g2,cv::COLOR_BGR2GRAY);


    cv::Ptr<cv::StereoBM> sbm = cv::StereoBM::create(64,31);
    sbm->setDisp12MaxDiff(-1);
    sbm->setSpeckleRange(0);
    sbm->setSpeckleWindowSize(0);
    sbm->setUniquenessRatio(15);
    sbm->setTextureThreshold(10);
    sbm->setMinDisparity(0);
    sbm->setPreFilterCap(31);
    sbm->setPreFilterSize(41);
    sbm->compute(g1,g2,disparity_left);
    normalize(disparity_left, disp1, 0, 255, CV_MINMAX, CV_8U);

    cv::Ptr<cv::StereoSGBM> sgbm = cv::StereoSGBM::create(0,64,31);
    sgbm->setP1(100);
    sgbm->setP2(1000);
    sgbm->setMinDisparity(0);
    sgbm->setUniquenessRatio(15);
    sgbm->setSpeckleWindowSize(0);
    sgbm->setSpeckleRange(0);
    sgbm->setDisp12MaxDiff(-1);
    sgbm->compute(g1,g2,disparity_left);
    normalize(disparity_left, disp2, 0, 255, CV_MINMAX, CV_8U);

    cv::namedWindow("Left",CV_WINDOW_FREERATIO);
    cv::imshow("Left", im_left);
    cv::namedWindow("Right",CV_WINDOW_FREERATIO);
    cv::imshow("Right", im_right);
    cv::namedWindow("StereoBM",CV_WINDOW_FREERATIO);
    cv::imshow("StereoBM", disp1);
    cv::imwrite( "/media/ankushbraj/02810E551F2735A4/ubuntu desktop/qt creater/out1.jpg", disp1);
    cv::namedWindow("StereoSGBM",CV_WINDOW_FREERATIO);
    cv::imshow("StereoSGBM", disp2);
    cv::imwrite( "/media/ankushbraj/02810E551F2735A4/ubuntu desktop/qt creater/out2.jpg", disp2);
    cv::waitKey(0);
    return 0;
}


