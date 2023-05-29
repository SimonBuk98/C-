#include "particle_system.h"


ParticleSystem::ParticleSystem(float _dt, int h, int w){
    canvas = cv::Mat(cv::Size(w, h), CV_8UC3, cv::Scalar(0, 0, 0));
    dt = _dt;
}

Matrix ParticleSystem::calcForce(Particle p1, Particle p2){
    int dp = p2-p1;
    int r = sqrt(pow(dp[0],2) + pow(dp[1],2))

    Matrix f = dp*(getMass(p1)*getMass(p2))/pow(r,2);

    return f;
}

void ParticleSystem::addParticle(Particle p){
    particles.push_back(p);
}

void ParticleSystem::update(){
    Matrix sum;
    for(int i=0 ; i<particles.size() ; i++){
        for(int j=0 ; j<particles.size() ; j++){
            if(i != j){
            sum += calcForce(paricles[i],particles[j])
            }
        }
        particles[i].setForce(sum);
    }

    for(int i ; i<particles.size() ; i++){
        update();
    }
}

void ParticleSystem::draw(){
    cv::Mat img;
    canvas.copyTo(img);

    // Draw clock center
    for(int i=0 ; i<particles.size() ; i++){
    cv::circle(img, cv::Point(particles[0].getPosition, particles[1].getPosition), 3, cv::Scalar(255, 0, 0), -1);

    cv::circle(canvas, cv::Point(particles[0].getPosition, particles[1].getPosition), 3, cv::Scalar(0, 255, 0), -1);
    
    }
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


