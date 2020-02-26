#include "main.h"


namespace Shishir{
    namespace Hot{
        /*Controller*/
        okapi::Controller CONTROLLER_A( okapi::ControllerId::master );
        okapi::Controller CONTROLLER_B( okapi::ControllerId::partner );


        /*Motors*/
        okapi::MotorGroup LD( {okapi::Motor(PORT_LD_F, false, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees), okapi::Motor(PORT_LD_R, true, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees)} );
        okapi::MotorGroup RD( {okapi::Motor(PORT_RD_F, true, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees), okapi::Motor(PORT_RD_R, false, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees)} );

        okapi::Motor LIFT(PORT_LIFT, false, okapi::AbstractMotor::gearset::red, okapi::AbstractMotor::encoderUnits::degrees);
        okapi::Motor TILTER(PORT_TILTER, false, okapi::AbstractMotor::gearset::red, okapi::AbstractMotor::encoderUnits::degrees);

        okapi::MotorGroup INTAKE( {okapi::Motor(PORT_INTAKE_L, true, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees), okapi::Motor(PORT_INTAKE_R, false, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees)} );


        /*Chassis*/
        okapi::ChassisScales HydraChassisScale({okapi::QLength(CHASSIS_WHEEL_DIAMETER), okapi::QLength(CHASSIS_WHEEL_TRACK)}, okapi::imev5GreenTPR * CHASSIS_GEAR_RASIO);

        std::shared_ptr<okapi::ChassisController> Chassis_Controller_Pointer = okapi::ChassisControllerBuilder()
            .withMotors(LD, RD)
            .withDimensions(okapi::AbstractMotor::gearset::green, HydraChassisScale)
            .build();

        std::shared_ptr<okapi::ChassisModel> CHASSIS = (*Chassis_Controller_Pointer).getModel();


        /*Motion Profiler*/
        std::shared_ptr<okapi::AsyncMotionProfileController> MOTION_PROFILER =
            okapi::AsyncMotionProfileControllerBuilder()
            .withLimits({0.5, 0.2, 10.0})
            .withOutput(Chassis_Controller_Pointer)
            .buildMotionProfileController();


        /*Timer*/
        okapi::Rate TIMER;
    }
}
