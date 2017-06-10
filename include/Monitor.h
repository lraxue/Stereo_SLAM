//
// Created by feixue on 17-6-9.
//

#ifndef STEREO_SLAM_MONITOR_H
#define STEREO_SLAM_MONITOR_H

#include <opencv2/opencv.hpp>

namespace Stereo_SLAM
{

#define CIRCLE_RADIUS       10
#define CIRCLE_THICKNESS    2
#define LINE_THICKNESS      2
    class Monitor
    {
    public:
        Monitor();
        ~Monitor();

    public:
        void DrawMatchesBetweenStereoFrame(const cv::Mat mLeft, const cv::Mat& mRight,
                                           const std::vector<cv::KeyPoint>& vPointsLeft,
                                           const std::vector<cv::KeyPoint>& vPointsRight, cv::Mat& out);

        void RecordFeatureFlow(const cv::Mat& mLeft, const cv::Mat& mRight,
                               const std::vector<std::vector<cv::KeyPoint> >& vFeatureFlowLeft,
                               const std::vector<std::vector<cv::KeyPoint> >& vFeatureFlowRight,
                               cv::Mat& out);

    };
}

#endif //STEREO_SLAM_MONITOR_H
