#include "define.h"

void rgb2yuv420(unsigned char *r,unsigned char *g,unsigned char *b,unsigned char *y,unsigned char *u,unsigned char *v,Table *ctran);
void init_table(Table * ctran);

int main()
{
	/*---declare dynamic---*/
	unsigned char *r = new unsigned char[wsize*hsize];
	unsigned char *g = new unsigned char[wsize*hsize];
	unsigned char *b = new unsigned char[wsize*hsize];

	unsigned char *y = new unsigned char[wsize*hsize];
	unsigned char *u = new unsigned char[wsize*hsize];
	unsigned char *v = new unsigned char[wsize*hsize];
    	/*--------------------*/

	/*--color table declare & initilization--*/
	Table *ctran=(Table *)malloc(sizeof(Table));
	init_table(ctran); //init_table
	/*---------------------------------------*/
	
	/*--- filename fstream & cv::Mat declare ---*/
	char filename[100];
	cv::Mat dst;
	fstream fin;
	FILE *vout;
	system("sh file.sh"); //create file
	fin.open("new.txt",ios::in); //read file
	vout = fopen("sample_stream.yuv","w"); //read file
	/*-----------------------------------------*/
	
	while(fin.getline(filename,sizeof(filename),'\n'))
	{
		string name(filename);
		//--- read sample to resize ---//
		cv::Mat temp = imread(name,CV_LOAD_IMAGE_UNCHANGED); //read img
		cv::resize(temp,dst,cv::Size(wsize,hsize));
		for(size_t i=0;i<wsize*hsize;i++)//get r,g,b data
		{
			b[i] = dst.data[3*i];//b
			g[i] = dst.data[3*i+1];//g
			r[i] = dst.data[3*i+2];//r
		}

		rgb2yuv420(r,g,b,y,u,v,ctran);

		fwrite(y,1,sizeof(unsigned char)*wsize*hsize,vout);
		fwrite(u,1,sizeof(unsigned char)*wsize*hsize/4,vout);
		fwrite(v,1,sizeof(unsigned char)*wsize*hsize/4,vout);
		//imshow("resize",dst);
		//cvWaitKey(100);
	}
	
	delete [] r,g,b,y,u,v;
	return 0;
}

void rgb2yuv420(unsigned char *r,unsigned char *g,unsigned char *b,unsigned char *y,unsigned char *u,unsigned char *v, Table* ctran)
{
	int idx_y=0,idx_uv=0;
	int yy=0,uu=0,vv=0;
	for(size_t i=0;i<hsize;i++)
		for(size_t j=0;j<wsize;j++)
		{
			idx_y=i*wsize+j;
			idx_uv=(i>>1)*(wsize>>1)+(j>>1);

			yy=(int)(ctran->y.c1[r[idx_y]] + ctran->y.c2[g[idx_y]]+ ctran->y.c3[b[idx_y]]);
			y[idx_y]=yy>255 ? 255:(yy<0 ? 0:yy);

			if(i%2 ==0 && j%2==0)
			{
				uu=(int)(ctran->u.c1[r[idx_y]] + ctran->u.c2[g[idx_y]] + ctran->u.c3[b[idx_y]] + 128);
				u[idx_uv]=uu>255 ? 255:(uu<0 ? 0:uu);

				vv=(int)(ctran->v.c1[r[idx_y]] + ctran->v.c2[g[idx_y]] + ctran->v.c3[b[idx_y]] + 128);
				v[idx_uv]=vv>255 ? 255:(vv<0 ? 0:vv);
			}
		}
}
