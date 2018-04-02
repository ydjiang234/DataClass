#ifndef _XYCYCLIC
#define _XYCYCLIC

#include <iostream>
#include <Dense>
#include "XYdata.h"

class XYcyclic: public XYdata
{
public:
    XYcyclic(Eigen::ArrayXd xdata, Eigen::ArrayXd ydata, double threhold=1E-6);
    XYcyclic();
    ~XYcyclic();

    Eigen::ArrayXd turnX, turnY, halfCycleEnergy;
    Eigen::ArrayXi turnID;

    void getTurning();
    void getHalfCycleEnergy();
};

#endif
