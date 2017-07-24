CXX = g++
CV_INC:=-I/usr/include/opencv2
CV_LIB:=-lopencv_imgproc -lopencv_features2d -lopencv_core -lopencv_highgui
Code := ./src/
transfomat:
	rm -rf Trans *.*~ *.o
	$(CXX) -c $(CV_INC) $(Code)*.cpp
	$(CXX) -o Trans *.o $(CV_LIB)
clean:
	rm -rf Trans *.*~ *.o
