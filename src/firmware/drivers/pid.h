#ifndef _PID_H_
#define _PID_H_

#include <stdint.h>

typedef float pid_t;

class PID
{
  private:
    pid_t e0, e1, x0, x1, x2;
    pid_t k0, k1, kd;
    pid_t limit;
    pid_t u;

  public:
    PID(pid_t kp = 0.0, pid_t ki = 0.0, pid_t kd = 0.0, pid_t limit = 1.0);
    virtual ~PID();

    void init(pid_t kp, pid_t ki, pid_t kd, pid_t limit);

    pid_t process(pid_t error, pid_t plant_output);
    pid_t process(pid_t error);

    void reset();
};

#endif
