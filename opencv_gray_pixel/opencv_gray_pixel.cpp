#include <opencv2/opencv.hpp>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
using namespace cv;
using namespace std;
int main(int argc, char *argv[])
{
	Mat input_img;
	input_img = imread(argv[1], IMREAD_GRAYSCALE);
	if (input_img.empty())
	{
		cerr << "Couldn't open image . Exit program...........";
		return 1;
	}
	//--------------------------------------------------------------------------
	vector<vector<uchar>> pixel(input_img.rows, vector<uchar>(input_img.cols));
	vector<int> countPixel(256, 0);
	int totalNumPixels{input_img.rows*input_img.cols};
	for (int i{}; i < input_img.rows; i++)
		for (int j{}; j < input_img.cols; j++)
		{
			pixel[i][j] = input_img.at<uchar>(i, j);
			countPixel[(unsigned int)pixel[i][j]]++;
		}
	for (int i{}; i < 256; i++)
	{
		cout << left << setw(6) << "Value " << setw(3) << i << ": " << setw(5) << countPixel[i] << "/" << setw(8) << totalNumPixels << "| ";
		if (i % 6 == 0) cout << endl;
	}
	//--------------------------------------------------------------------------
	namedWindow(argv[1], WINDOW_AUTOSIZE);
	imshow(argv[1], input_img);
	waitKey();
	system("cls");
	return 0;
}