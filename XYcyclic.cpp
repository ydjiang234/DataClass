#include "XYcyclic.h"

XYcyclic::XYcyclic(Eigen::ArrayXd xdata, Eigen::ArrayXd ydata):
          XYdata(xdata, ydata)
{
    this->getTurning();
}

XYcyclic::XYcyclic():XYdata() {}

XYcyclic::~XYcyclic() {}

void XYcyclic::getTurning()
{
    Eigen::ArrayXd dx;
    dx = this->xdata.tail(this->num-1) - this->xdata.head(this->num-1);
    std::cout<<dx<<std::endl;
    /*
    double pre_dx, cur_dx;
    unsigned int i, len;
    i = 2;
    len = dx.size();
    pre_dx = dx[0];
    while (i<len-2) {
        if (pre_dx != 0.0) {
            cur_dx = x;
        }
    }
    */
}
