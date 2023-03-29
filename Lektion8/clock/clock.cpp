// User headers
#include "clock.h"
#include <math.h>


Clock::Clock(float dt, int h, int w):_dt(dt)
{
  _canvas = cv::Mat(cv::Size(w, h), CV_8UC3, cv::Scalar(0, 0, 0));
  int cx = _canvas.cols/2;
  int cy = _canvas.rows/2;
  for(int i =0; i <12; i++){
    cv::line(_canvas, cv::Point(cx+105*cos((M_PI/6)*i), cy+105*sin((M_PI/6)*i)), cv::Point(cx+125*cos((M_PI/6)*i), cy + 125*sin((M_PI/6)*i)), cv::Scalar(255,255,255));
  }
  
}

void Clock::update(){
  // Update the angle of the clock arm, to a time step dt into the future
    _angle += (2*M_PI/60.0)*_dt;
    _angle = fmod(_angle,2*M_PI);
}

void Clock::draw(){
    cv::Mat img;
    _canvas.copyTo(img);
    int cx = _canvas.cols/2;
    int cy = _canvas.rows/2;
    
    // Draw clock arms
    double length = 100;
    cv::line(img, cv::Point(cx, cy), cv::Point(cx+length*cos(_angle), cy + length*sin(_angle)), cv::Scalar(255,255,255));
    cv::circle(_canvas,cv::Point(cx+100*cos(_angle), cy + 100*sin(_angle)),3,cv::Scalar(0, 255, 255),-1);
    

    // Draw clock center
    cv::circle(img, cv::Point(cx, cy), 3, cv::Scalar(0, 255, 0), -1);

    cv::imshow("Image", img);
}

void Clock::simulate(int fps){

    while(1){

        // Compute how many updates to do pr. frame
        float updatesPerSecond = 1.0/_dt;
        float secondsPerFrame = 1.0/float(fps);
        float updatesPerFrame = updatesPerSecond*secondsPerFrame;

        // Update the clock's internal state and draw the frame
        for(int i = 0; i < updatesPerFrame; i++){
          update();
        }
        draw();

        // Wait for the next frame
        float millisecondsPerFrame = 1000.0*secondsPerFrame;
        char key = cv::waitKey(millisecondsPerFrame);
        if(key =='q'){
          break;
        }
    }
}
