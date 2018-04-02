#ifndef _XYCYCLIC
#define _XYCYCLIC

#include <iostream>
#include <Dense>
#include "XYdata.h"

class XYcyclic:XYdata
{
public:
    XYcyclic(Eigen::ArrayXd xdata, Eigen::ArrayXd ydata);
    XYcyclic();
    ~XYcyclic();

    Eigen::ArrayXd turnID;

private:
    void getTurning();
};

#endif
