# Disparity estimation using OpenCV
This is a assignment from Fraunhofer IOSB
## Disparity
The amount to which a single pixel is displaced in the two images(stereo) is called disparity. A pixel’s disparity is inversely proportional to its depth in the scene.
![disparity1](.gif)
The disparity of each pixel is encoded by a gray value. Light gray values represent high disparities, denoting greater motion and lesser distance and dark gray values small disparities. The resulting image is called disparity map. This  disparity map contains sufficient information for generating a 3D model.

![disparity](.png)
The following image represent stereo arrangement (O and O') to find the depth of a point X, z. So, it can be seen that the depth is inversely proportional to disparity.

## Disparity Estimation using StereoBM and StereoSGBM
The matching process is performed for every pixel in the left image, finding its match in the right image frame and computing the distance between them which results in an image where every pixel contains the distance/disparity value for that pixel in the left image. For example, given a left image ![im0](.ppm) and right image ![im1](.ppm) results in disparity images ![out1](.jpg) using Stereo Block Matching Algorithm(SBM) and ![out2](.jpg) using Stereo Semi Block Matching Algorithm(SGBM).

## Dependencies
This project has the following dependencies: 
```
QT Creator
C++
OpenCV 3.4.4
```


## Data used
```
http://vision.middlebury.edu/stereo/data/scenes2001/data/tsukuba/

```

## Usage
```
Once Qt 5 and OpenCV installed, clone this repo, open the .pro file, it should launch the project in Qt 5 and you will be able to run the program, and modify it.

```
