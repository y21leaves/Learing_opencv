#include<iostream>  
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  


using namespace cv;

void salt(Mat &image, int n)
{
	std::cout << image.rows << std::endl;
	std::cout << image.cols<<std::endl;
	for (int k = 1; k <= n; k++)
	{
		int i = rand() % image.rows;
		int j = rand() % image.cols;
		//std::cout <<i<<std::endl;
		//std::cout <<j << std::endl;

		if (image.channels() == 1){
			//image.at<uchar>(j, i) = 255;
		}
		else if (image.channels() == 3){
			image.at<Vec3b>(i,j)[0] = 255;
			image.at<Vec3b>(i,j)[1] = 255;
			image.at<Vec3b>(i,j)[2] = 255;
		}
	}

}


int main()
{
	//Mat image(240, 320, CV_8U, cv::Scalar(100));
	// 读入一张图片（游戏原画）  
	Mat image = imread("pic.jpg");
	// 创建一个名为 "游戏原画"窗口  
	salt(image,12000);



	namedWindow("游戏原画");
	// 在窗口中显示游戏原画  
	imshow("游戏原画", image);
	// 等待6000 ms后窗口自动关闭  
	waitKey(10000);
}