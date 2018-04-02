#ifndef _XYDATA
#define _XYDATA

#include <iostream>
#include "Dense"

class XYdata
{
public:
    XYdata(Eigen::ArrayXd xdata, Eigen::ArrayXd ydata, double threhold=1E-6);
    XYdata();
    ~XYdata();

    void Initial();
    void getEnergy();
    Eigen::ArrayXd cumsum(Eigen::ArrayXd data);
    void remove_Duplicates();

    Eigen::ArrayXd xdata, ydata, xcum, energy;
    unsigned int num;
    double threhold;



};


#endif
