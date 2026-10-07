#include <iostream>
#include "common_code.hpp"
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

cv::Mat
fsiv_convert_bgr_to_hsv(const cv::Mat &img)
{
    CV_Assert(img.channels() == 3);
    cv::Mat out;
    cvtColor(img, out, cv::COLOR_BGR2HSV);
    CV_Assert(out.channels() == 3);
    return out;
}

cv::Mat
fsiv_combine_images(const cv::Mat &img1, const cv::Mat &img2,
                    const cv::Mat &mask)
{
    CV_Assert(img2.size() == img1.size());
    CV_Assert(img2.type() == img1.type());
    CV_Assert(mask.size() == img1.size());
    cv::Mat output;
    img2.copyTo(output);
    img1.copyTo(output, mask);
    CV_Assert(output.size() == img1.size());
    CV_Assert(output.type() == img1.type());
    return output;
}

cv::Mat
fsiv_compute_chroma_key_mask(const cv::Mat &bgr_img,
                             int chroma_key,
                             int sensitivity)
{
    CV_Assert(bgr_img.type() == CV_8UC3);
    cv::Mat mask;
    mask = fsiv_convert_bgr_to_hsv(bgr_img);

    cv::Scalar lower(chroma_key - sensitivity, 0, 0);
    cv::Scalar upper(chroma_key + sensitivity, 255, 255);

    inRange(mask, lower, upper, mask);
    return mask;
}

cv::Mat
fsiv_apply_chroma_key(const cv::Mat &foreg, const cv::Mat &backg, int hue,
                      int sensitivity, cv::Mat *mask_out)
{
    cv::Mat out;
    cv::Scalar lower_b, upper_b; // HSV range.
    cv::Mat mask = fsiv_compute_chroma_key_mask(foreg, hue, sensitivity);
    
    if(backg.size() != foreg.size())
    {
        resize(backg, out, foreg.size());
    }
    else
    {
        backg.copyTo(out);
    }

    out = fsiv_combine_images(out, foreg, mask);

    if(mask_out != nullptr)
    {
        mask.copyTo(*mask_out);
    }
    CV_Assert(out.size() == foreg.size());
    CV_Assert(out.type() == foreg.type());
    return out;
}
