#include "particle_system.h"
#include <cmath>
#include <vector>

ParticleSystem::ParticleSystem(float _dt, int h, int w)
{
    dt = _dt;
    canvas = cv::Mat(cv::Size(w, h), CV_8UC3, cv::Scalar(0, 0, 0));
}

Matrix ParticleSystem::calcForce(Particle p1, Particle p2)
{
    Matrix dp = p2.getPosition() + p1.getPosition() * (-1);
    float r = sqrt(pow(dp(0, 0), 2) + pow(dp(1, 0), 2));
    return dp * ((p2.getMass() * p1.getMass()) / pow(r, 2));
}

void ParticleSystem::addParticle(Particle p)
{
    particles.push_back(p);
}

void ParticleSystem::update()
{
    for (int i = 0; i < particles.size(); i++)
    {
        Matrix sum(2, 1);
        for (int j = 0; j < particles.size(); j++)
        {
            if (i != j)
            {
                sum = sum + calcForce(particles[i], particles[j]);
            }
            particles[i].setForce(sum);
        }
    }
    for (int i = 0; i < particles.size(); i++)
    {
        particles[i].update(dt);
    }
}

void ParticleSystem::draw()
{
    cv::Mat img;
    canvas.copyTo(img);

    for (int i = 0; i < particles.size(); i++)
    {
        cv::circle(canvas, cv::Point(particles[i].getPosition()(0, 0), particles[i].getPosition()(1, 0)), 1, cv::Scalar(255, 255, 255), -1);
        cv::circle(img, cv::Point(particles[i].getPosition()(0, 0), particles[i].getPosition()(1, 0)), 5, cv::Scalar(0, 255, 0), -1);
    }
    cv::imshow("Image", canvas);
    cv::imshow("Image", img);
}

void ParticleSystem::simulate(int fps)
{
    float updatesPerSecond = 1.0 / dt;
    float secondsPerFrame = 1.0 / float(fps);
    float updatesPerFrame = updatesPerSecond * secondsPerFrame;

    while (1)
    {

        for (int i = 0; i < updatesPerFrame; i++)
        {
            update();
        }
        draw();

        float millisecondsPerFrame = 1000.0 * secondsPerFrame;
        char key = cv::waitKey(millisecondsPerFrame);
        if (key == 'q')
        {
            break;
        }
    }
}