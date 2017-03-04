// 8 bin mau he mau GRAYSCALE
#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
using namespace cv;
using namespace std;
int main(int argc, char *argv[])
{
	Mat input_img;
	input_img = imread(argv[1], IMREAD_GRAYSCALE);
	if (input_img.empty())
	{
		cerr << "Couldn't open image . Exit program...........";
		return -1;
	}
	//----------------------------------------------------------------------------------------
	vector<vector<uchar>> pixel(input_img.rows, vector<uchar>(input_img.cols));
	vector<int> bin(8, 0);
	int numPixels{ input_img.cols * input_img.rows };
	for (int i{}; i < input_img.rows; i++)
		for (int j{}; j < input_img.cols; j++)
		{
			pixel[i][j] = input_img.at<uchar>(i, j);
			bin[(unsigned int)(pixel[i][j] / 32)]++;
		}
	for (int i{}; i < 8; i++)
	{
		cout << "color bin " << i << ":  " << bin[i] << "/" << numPixels << endl;
	}
	//-----------------------------------------------------------------------------------------
	namedWindow(argv[1], WINDOW_AUTOSIZE);
	imshow(argv[1], input_img);
	waitKey();
	return 0;
}
