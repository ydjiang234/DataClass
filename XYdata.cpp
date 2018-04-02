#include "XYdata.h"

XYdata::XYdata(Eigen::ArrayXd xdata, Eigen::ArrayXd ydata, double threhold)
{
    this->xdata = xdata;
    this->ydata = ydata;
    this->threhold = threhold;
    this->Initial();
}
XYdata::XYdata() {}

XYdata::~XYdata() {}

void XYdata::Initial()
{
    this->num = this->xdata.size();
    this->remove_Duplicates();
    this->getEnergy();
}

void XYdata::getEnergy()
{
    Eigen::ArrayXd dx, avgy;
    dx = this->xdata.tail(this->num-1) - this->xdata.head(this->num-1);
    avgy = (this->ydata.tail(this->num-1) + this->ydata.head(this->num-1)) / 2.0;
    this->xcum = Eigen::ArrayXd::Zero(this->num);
    this->energy = Eigen::ArrayXd::Zero(this->num);
    this->xcum.tail(this->num-1) = this->cumsum(dx.abs());
    this->energy.tail(this->num-1) = this->cumsum(avgy * dx);
}

void XYdata::remove_Duplicates()
{
    Eigen::ArrayXd tempX, tempY, dx;
    unsigned int len_remove, j;
    dx = this->xdata.tail(this->num-1) - this->xdata.head(this->num-1);
    len_remove = (dx.abs() < this->threhold).count();
    tempX = Eigen::ArrayXd::Zero(this->num - len_remove);
    tempY = Eigen::ArrayXd::Zero(this->num - len_remove);
    tempX[0] = this->xdata[0];
    tempY[0] = this->ydata[0];
    j = 1;
    for (unsigned int i=0; i<dx.size(); i++) {
        if (abs(dx[i]) >= this->threhold) {
            tempX[j] = this->xdata[i+1];
            tempY[j] = this->ydata[i+1];
            j++;
        }
    }
    this->xdata = tempX;
    this->ydata = tempY;
    this->num = this->xdata.size();
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
