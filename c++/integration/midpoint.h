#ifndef MID_POINT_H_
#define MID_POINT_H_

template <class T>
class MathFunction;

class MidPointIntegration{
public:
    MidPointIntegration(MathFunction<double> &f);
    MidPointIntegration(const MidPointIntegration &p);
    ~MidPointIntegration();
    MidPointIntegration &operator=(MidPointIntegration &p);

    void setNumIntervals(int n);
    double getIntegral(double a, double b);

private:
    MathFunction<double> &p;
    int m_numIntervals;
};

#endif // MID_POINT_H_
