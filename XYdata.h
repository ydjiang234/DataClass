#ifndef _XYDATA
#define _XYDATA

#include <iostream>
#include "Dense"

class XYdata
{
public:
    XYdata(Eigen::ArrayXd xdata, Eigen::ArrayXd ydata);
    XYdata();
    ~XYdata();

    void Initial();
    void getEnergy();
    Eigen::ArrayXd cumsum(Eigen::ArrayXd data);

    Eigen::ArrayXd xdata, ydata, xcum, energy;
    unsigned int num;



};


#endif
