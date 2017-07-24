CXX = g++
CV_INC:=-I/usr/include/opencv2
CV_LIB:=-lopencv_imgproc -lopencv_features2d -lopencv_core -lopencv_highgui
Code := ./src/
transfomat:
	rm -rf Trans SS *.*~ *.o
	$(CXX) -c $(CV_INC) $(Code)TF/*.cpp
	$(CXX) -o Trans *.o $(CV_LIB)
sample_stream:
	rm -rf Trans SS *.*~ *.o
	$(CXX) -c $(CV_INC) $(Code)SS/*.cpp
	$(CXX) -o SS *.o $(CV_LIB)
clean:
	rm -rf Trans SS *.*~ *.o
