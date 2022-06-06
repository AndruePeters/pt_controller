#pragma once

template<class DerivedImpl>
class MotorController {
    public:
    void panLeft()
    {
        static_cast<DerivedImpl*>(this)->panLeftImpl();
    }

    void panRight()
    {
        static_cast<DerivedImpl*>(this)->panRightImpl();
    }

    void tiltUp()
    {
        static_cast<DerivedImpl*>(this)->tiltUpImpl();
    }

    void tiltDown()
    {
        static_cast<DerivedImpl*>(this)->tiltDownImpl();
    }

    /// \p At the time of writing speed should be [0-100] as a percentage of the motors capable speed
    void setSpeed(int speed)
    {
        static_cast<DerivedImpl*>(this)->setSpeedImpl(speed);
    }
};