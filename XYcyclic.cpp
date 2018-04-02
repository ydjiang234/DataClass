#include "XYcyclic.h"

XYcyclic::XYcyclic(Eigen::ArrayXd xdata, Eigen::ArrayXd ydata, double threhold):
          XYdata(xdata, ydata, threhold)
{
    this->getTurning();
    this->getHalfCycleEnergy();
}

XYcyclic::XYcyclic():XYdata() {}

XYcyclic::~XYcyclic() {}

void XYcyclic::getTurning()
{
    //variable to use
    Eigen::ArrayXd dx, ddx, turn;
    unsigned int len_dx, len_ddx, len_turn, j;
    //
    dx = this->xdata.tail(this->num-1) - this->xdata.head(this->num-1);
    len_dx = dx.size();
    ddx = dx.tail(len_dx-1) * dx.head(len_dx-1);
    len_ddx = ddx.size();
    //Get number of turning
    len_turn = (ddx<0.0).count();
    //Iter along the ddx to get the turning
    this->turnID = Eigen::ArrayXi::Zero(len_turn+2);
    this->turnX = Eigen::ArrayXd::Zero(len_turn+2);
    this->turnY = Eigen::ArrayXd::Zero(len_turn+2);

    this->turnX[0] = this->xdata[0];
    this->turnY[0] = this->ydata[0];

    this->turnID[len_turn+1] = this->num-1;
    this->turnX[len_turn+1] = this->xdata[this->num-1];
    this->turnY[len_turn+1] = this->ydata[this->num-1];

    j = 1;
    for (unsigned int i=0; i<len_ddx; i++) {
        if (ddx[i]<0.0) {
            this->turnID[j] = i + 1;//Be carefull, it should be i+1 insead of i+2!!
            this->turnX[j] = this->xdata[i+1];
            this->turnY[j] = this->ydata[i+1];
            j++;
        }
    }

}

void XYcyclic::getHalfCycleEnergy()
{
    unsigned int len_turn = this->turnID.size();
    this->halfCycleEnergy = Eigen::ArrayXd::Zero(len_turn - 1);
    for (unsigned int i=1; i<len_turn; i++) {
        this->halfCycleEnergy[i-1] = this->energy[this->turnID[i]] - this->energy[this->turnID[i-1]];
    }
}
