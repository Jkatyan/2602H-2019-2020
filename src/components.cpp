#include "main.h"
#include "user/components.hpp"


Motor LD_F(PORT_LD_F, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
Motor RD_F(PORT_RD_F, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
Motor LD_R(PORT_LD_R, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
Motor RD_R(PORT_RD_R, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);

Motor LIFT(PORT_LIFT, E_MOTOR_GEARSET_36, true, E_MOTOR_ENCODER_DEGREES);
Motor TILTER(PORT_TILTER, E_MOTOR_GEARSET_36, false, E_MOTOR_ENCODER_DEGREES);
Motor INTAKE_L(PORT_INTAKE_L, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
Motor INTAKE_R(PORT_INTAKE_R, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);

Motor TEST_MOTOR(PORT_TEST_MOTOR, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);


Controller controller0(E_CONTROLLER_MASTER);
Controller controller1(E_CONTROLLER_PARTNER);

Imu imu0(PORT_IMU);
