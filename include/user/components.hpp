#ifndef _COMPONENTS_HPP
#define _COMPONENTS_HPP

#include "api.h"


class Chassis
{
    public:
        Chassis();
        bool is_at_target();
        void move_relative(int, int);
        void set_brake_mode(pros::motor_brake_mode_e_t);
        void set_pos_pid(double, double, double);
        void set_vel_pid(double, double, double);
        void turn_relative(int, int);
};


extern pros::Motor LD_F;
extern pros::Motor RD_F;
extern pros::Motor LD_R;
extern pros::Motor RD_R;

extern Chassis CHASSIS;

extern pros::Motor LIFT;
extern pros::Motor TILTER;
extern pros::Motor INTAKE_L;
extern pros::Motor INTAKE_R;

extern pros::Motor TEST_MOTOR;


extern pros::Controller controller0;
extern pros::Controller controller1;

#endif