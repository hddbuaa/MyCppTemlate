#ifndef DRIVER_TEST_H
#define DRIVER_TEST_H

class DriverTest {
public:
    DriverTest() : value_(0.0) {}
    ~DriverTest() {}
    void Output();

private:
    double value_;
};

#endif
