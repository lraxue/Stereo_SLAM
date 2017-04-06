//
// Created by feixue on 17-4-6.
//

#ifndef STEREO_SLAM_UTILS_H
#define STEREO_SLAM_UTILS_H

#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void ShowTrajectory(const std::string& strTrajectory)
{
    cv::Mat mTraj = imread("kitti-gt00.png"); // cv::Mat::zeros(600, 600, CV_8UC3); //

    string line;
    ifstream file(strTrajectory.c_str());
    if (!file.is_open())
        cout << "Open trajectory file " << strTrajectory << " error." << endl;
    float t0, t1, t2;
    float R00, R01, R02, R10, R11, R12, R20, R21, R22;
    while ((getline(file, line)))
    {
        istringstream value(line);
        value >> R00 >> R01 >> R02 >> t0 >> R10 >> R11 >> R12 >> t1 >> R20 >> R21 >> R22 >> t2;

        int x = t0 + 300;
        int y = t2 + 100;
        circle(mTraj, cv::Point(x, y), 1, CV_RGB(255, 0, 0), 1);

        imshow("traj", mTraj);
        waitKey(10);
    }

    imwrite("kitti00.png", mTraj);
}

#endif //STEREO_SLAM_UTILS_H
