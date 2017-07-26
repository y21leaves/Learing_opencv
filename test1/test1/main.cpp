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
	// ����һ��ͼƬ����Ϸԭ����  
	Mat image = imread("pic.jpg");
	// ����һ����Ϊ "��Ϸԭ��"����  
	salt(image,12000);



	namedWindow("��Ϸԭ��");
	// �ڴ�������ʾ��Ϸԭ��  
	imshow("��Ϸԭ��", image);
	// �ȴ�6000 ms�󴰿��Զ��ر�  
	waitKey(10000);
}