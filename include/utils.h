//
// Created by feixue on 17-4-6.
//

#ifndef STEREO_SLAM_UTILS_H
#define STEREO_SLAM_UTILS_H

#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void ShowTrajectory(const string& strTrajectory, string& saveFileName, const int& offsetX, const int& offsetY)
{
    cv::Mat mTraj =  cv::Mat::zeros(2000, 2000, CV_8UC3); //imread("kitti-gt00.png"); //

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

        int x = t0 + offsetX;
        int y = t2 + offsetY;

        // 06 [300, 500]
        // [300, 100]
        // circle(mTraj, cv::Point(x, y), 1, CV_RGB(0, 255, 0), 1);
        circle(mTraj, cv::Point(x, y), 1, CV_RGB(255, 0, 0), 1);

        imshow("traj", mTraj);
        waitKey(5);
    }

    imwrite(saveFileName, mTraj);
}

void ShowTrajectoryWithGT(const string& fileGT, const string& strTrajectory,  const string& saveFileName, const int& offsetX, const int& offsetY)
{
    cv::Mat mTraj =  imread(fileGT);
    if (mTraj.empty())
    {
        cout << "Open groundtruth trajectory failed." << endl;
        return;
    }

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

        int x = t0 + 500;
        int y = t2 + 500;

        // 06 [300, 500]
        // [300, 100]
        circle(mTraj, cv::Point(x, y), 1, CV_RGB(0, 255, 0), 1);
        // circle(mTraj, cv::Point(x, y), 1, CV_RGB(255, 0, 0), 1);

        imshow("traj", mTraj);
        waitKey(5);
    }

    imwrite(saveFileName, mTraj);
}

void ShowTrajectory(const std::string& strTrajectory)
{
    cv::Mat mTraj =  cv::Mat::zeros(2000, 2000, CV_8UC3); //imread("kitti-gt00.png"); //

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

        int x = t0 + 500;
        int y = t2 + 500;

        // 06 [300, 500]
        // [300, 100]
        // circle(mTraj, cv::Point(x, y), 1, CV_RGB(0, 255, 0), 1);
        circle(mTraj, cv::Point(x, y), 1, CV_RGB(255, 0, 0), 1);

        imshow("traj", mTraj);
        waitKey(5);
    }

    imwrite("kitti-gt08.png", mTraj);
}

#endif //STEREO_SLAM_UTILS_H
