#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d/nonfree.hpp>

#define CV_VERSION_ID       CVAUX_STR(CV_MAJOR_VERSION) CVAUX_STR(CV_MINOR_VERSION) CVAUX_STR(CV_SUBMINOR_VERSION)

#ifdef _DEBUG
#define cvLIB(name) "opencv_" name CV_VERSION_ID "d"
//debug的时候 采用全部的一个world的包来开发 比较方便
//#pragma comment(lib,cvLIB("world"))
#pragma comment(lib,cvLIB("core"))
#pragma comment(lib,cvLIB("imgproc"))
#pragma comment(lib,cvLIB("highgui"))
#pragma comment(lib,cvLIB("imgcodecs"))
#pragma comment(lib,cvLIB("dnn"))
#pragma comment(lib,cvLIB("features2d"))
#pragma comment(lib,cvLIB("xfeatures2d"))
#pragma comment(lib,cvLIB("ml"))
#pragma comment(lib,cvLIB("objdetect"))
#pragma comment(lib,cvLIB("calib3d"))
#pragma comment(lib,cvLIB("video"))
#pragma comment(lib,cvLIB("videoio"))
#pragma comment(lib,cvLIB("videostab"))
#pragma comment(lib,cvLIB("flann"))
#else
#define cvLIB(name) "opencv_" name CV_VERSION_ID
//release的时候 静态包来加载 这样方便现场 不需要再加载各种库


#pragma comment(lib,cvLIB("core"))
#pragma comment(lib,cvLIB("imgproc"))
#pragma comment(lib,cvLIB("highgui"))
#pragma comment(lib,cvLIB("imgcodecs"))
#pragma comment(lib,cvLIB("dnn"))
#pragma comment(lib,cvLIB("features2d"))
#pragma comment(lib,cvLIB("xfeatures2d"))
#pragma comment(lib,cvLIB("ml"))
#pragma comment(lib,cvLIB("objdetect"))
#pragma comment(lib,cvLIB("calib3d"))
#pragma comment(lib,cvLIB("video"))
#pragma comment(lib,cvLIB("videoio"))
#pragma comment(lib,cvLIB("videostab"))
#pragma comment(lib,cvLIB("flann"))

#pragma comment(lib,"IlmImf.LIB")
#pragma comment(lib,"ippicvmt.LIB")
#pragma comment(lib,"ippiw.LIB")
#pragma comment(lib,"ittnotify.LIB")
#pragma comment(lib,"libjasper.LIB")
#pragma comment(lib,"libjpeg-turbo.LIB")
#pragma comment(lib,"libpng.LIB")
#pragma comment(lib,"libprotobuf.LIB")
#pragma comment(lib,"libtiff.LIB")
#pragma comment(lib,"libwebp.LIB")
#pragma comment(lib,"zlib.LIB")

#endif


