#include "particle_system.h"
#include <cmath>
#include <vector>

ParticleSystem::ParticleSystem(float _dt, int h, int w) : dt(_dt)
{
    canvas = cv::Mat(cv::Size(w, h), CV_8UC3, cv::Scalar(0, 0, 0));
}

Matrix ParticleSystem::calcForce(Particle p1, particle p2)
{
    Matrix dp = p2 - p1;
    float r = sqrt(pow((p2(1, 1) - p2(1, 1)), 2) + pow((p2(2, 1) - p1(2, 1)), 2));
    Matrix f = dp * ((p2.m * p1.m) / pow(r, 2));

    return f;
}

void ParticleSystem::addParticle(Particle p)
{
    particels.push_back(p);
}

void ParticleSystem::update()
{
    for (int i = 0; i < particles.size(); i++)
    {
        Matrix sum;
        for (int j = 0; j < particles.size(); j++)
        {
            if (i != j)
            {
                sum += calcForce(particles[i], particles[j]);
            }
        }
        particles[i].setForce(sum);
    }
}

void ParticleSystem::draw(){
    cv::Mat img;
    canvas.copyTo(img);

    for(int i = 0; i < particles.size(); i ++){
        cv::circle(canvas, cv::Point(particles[i].at(1,1), particles[i].at(2,1)),cv::Scalar(255,255,255),-1);
        cv::circle(img, cv::Point(particles[i].at(1,1), particles[i].at(2,1)),5,cv::Scalar(0,255,0),-1);
    }
    cv::imshow("Image", img);
}

void ParticleSystem::simulate(int fps){
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