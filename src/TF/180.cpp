#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <math.h>
#include <time.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace std;
using namespace cv;

int main()
{
	fstream fn;
	Mat nimg;
	char filename[100];
	string poi=".";

	system("sh file.sh");	
	fn.open("new.txt",ios::in);
	//--------------------------------//
	size_t process_num=0;
	while(fn.getline(filename,sizeof(filename),'\n'))
	{
		//fn.getline(filename,sizeof(filename),'\n');
		string name(filename);
		//--- create rotate 180 image ---//
		cv::Mat temp = imread(name,CV_LOAD_IMAGE_UNCHANGED); //read img
		//imshow("pic",temp);
		cout<<"/-------------------------------/"<<endl;			
		cout<<"source name:"<<name<<endl;
		flip(temp,nimg,1);//right left change
		//imshow("picre",nimg);
		if(cvWaitKey(500)>=0) break;
		size_t pos = name.find(poi);//reflash name
		//cout<<pos<<endl;
		name.insert(pos,"mir");
		cout<<"new name:"<<name<<endl;
		cout<<"Prosess count:"<<++process_num<<endl;
		cout<<"/-------------------------------/\n"<<endl;
		cv::imwrite(name,nimg);//output new file
		//-------------------------------//
	}
	
	std::cout<<"fucking good!!"<<std::endl;
	fn.close();
	return 0;
}

