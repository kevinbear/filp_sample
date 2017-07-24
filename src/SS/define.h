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
#define wsize 40
#define hsize 120

typedef struct table
{
	float c1[256];
	float c2[256];
	float c3[256];
}coefficient;

typedef struct tr
{
	coefficient y;	
	coefficient u;
	coefficient v;
	coefficient r;
	coefficient g;
	coefficient b;
}Table;

extern void rgb2yuv420(unsigned char *,unsigned char *,unsigned char *,unsigned char *,unsigned char *,unsigned char *,Table *);
extern void init_table(Table *);
