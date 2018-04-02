#include "XYdata.h"

XYdata::XYdata(Eigen::ArrayXd xdata, Eigen::ArrayXd ydata)
{
    this->xdata = xdata;
    this->ydata = ydata;
    this->Initial();
}
XYdata::XYdata() {}

XYdata::~XYdata() {}

void XYdata::Initial()
{
    this->num = this->xdata.size();
    this->getEnergy();
}

void XYdata::getEnergy()
{
    Eigen::ArrayXd dx, avgy;
    dx = this->xdata.tail(this->num-1) - this->xdata.head(this->num-1);
    avgy = (this->ydata.tail(this->num-1) + this->ydata.head(this->num-1)) / 2.0;
    this->xcum = this->cumsum(dx.abs());
    this->energy = this->cumsum(avgy * dx);
}

Eigen::ArrayXd XYdata::cumsum(Eigen::ArrayXd data)
{
    unsigned int len;
    len = data.size();
    Eigen::ArrayXd out = Eigen::ArrayXd::Zero(len);
    for (int i=0;i<len;i++) {
        out[i] = data.head(i+1).sum();
    }
    return out;
}
