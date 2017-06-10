//
// Created by feixue on 17-6-9.
//

#include <Monitor.h>

#include <glog/logging.h>

namespace Stereo_SLAM
{
    Monitor::Monitor() {}
    Monitor::~Monitor() {}

    void Monitor::DrawMatchesBetweenStereoFrame(const cv::Mat mLeft, const cv::Mat &mRight,
                                                const std::vector<cv::KeyPoint> &vPointsLeft,
                                                const std::vector<cv::KeyPoint> &vPointsRight, cv::Mat &out)
    {
        if (mLeft.empty() || mRight.empty())
            LOG(INFO) << "The input image is empty, please check.";

        const int w = mLeft.cols;
        const int h = mLeft.rows;

        out = cv::Mat(h, w * 2, mLeft.type());
        mLeft.copyTo(out.rowRange(0, h).colRange(0, w));
        mRight.copyTo(out.rowRange(0, h).colRange(w, w * 2));

        for(int i = 0, iend = vPointsLeft.size(); i < iend; ++i)
        {
            cv::Point p1 = vPointsLeft[i].pt;
            cv::Point p2 = vPointsRight[i].pt;
            p2.x += w;

            cv::circle(out, p1, CIRCLE_RADIUS, cv::Scalar(0, 0, 255), CIRCLE_THICKNESS);
            cv::circle(out, p1, CIRCLE_RADIUS, cv::Scalar(0, 0, 255), CIRCLE_THICKNESS);

            cv::line(out, p1, p2, cv::Scalar(0, 255, 0), LINE_THICKNESS);
        }
    }

    void Monitor::RecordFeatureFlow(const cv::Mat &mLeft, const cv::Mat &mRight,
                                    const std::vector<std::vector<cv::KeyPoint> >& vFeatureFlowLeft,
                                    const std::vector<std::vector<cv::KeyPoint> >& vFeatureFlowRight,
                                    cv::Mat &out)
    {
        if (mLeft.empty() || mRight.empty())
            LOG(INFO) << "The input image is empty, please check.";

        const int w = mLeft.cols;
        const int h = mLeft.rows;

        out = cv::Mat(h, w * 2, mLeft.type());
        mLeft.copyTo(out.rowRange(0, h).colRange(0, w));
        mRight.copyTo(out.rowRange(0, h).colRange(w, w * 2));

        cv::Point2f preP1;
        cv::Point2f preP2;

        for (int i = 0, iend = vFeatureFlowLeft.size(); i < iend; ++i)
        {
            bool bFirst = true;
            // Number of points tracked in current feature flow.
            int nP = vFeatureFlowLeft[i].size();

            for (int j = 0; j < nP; ++j)
            {
                const cv::Point2f p1 = vFeatureFlowLeft[i][j].pt;
                cv::Point2f p2 = vFeatureFlowRight[i][j].pt;
                p2.x += w;

                cv::circle(out, p1, CIRCLE_RADIUS, cv::Scalar(0, 0, 255), CIRCLE_THICKNESS);
                cv::circle(out, p1, CIRCLE_RADIUS, cv::Scalar(0, 0, 255), CIRCLE_THICKNESS);

                if (bFirst)
                {
                    bFirst = false;
                    preP1 = p1;
                    preP2 = p2;

                    continue;
                }

                cv::line(out, preP1, p1, cv::Scalar(0, 255, 0), LINE_THICKNESS);
                cv::line(out, preP2, p2, cv::Scalar(0, 255, 0), LINE_THICKNESS);
            }
        }
    }


}