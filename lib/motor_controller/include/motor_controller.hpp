#pragma once

template<class DerivedImpl>
class MotorController {
    public:
    void panLeftStart()
    {
        static_cast<DerivedImpl*>(this)->panLeftStartImpl();
    }

    void panLeftStop()
    {
        static_cast<DerivedImpl*>(this)->panLeftStopImpl();
    }

    void panRightStart()
    {
        static_cast<DerivedImpl*>(this)->panRightStartImpl();
    }

    void panRightStop()
    {
        static_cast<DerivedImpl*>(this)->panRightStopImpl();
    }

    void tiltUpStart()
    {
        static_cast<DerivedImpl*>(this)->tiltUpStartImpl();
    }

    void tiltUpStop()
    {
        static_cast<DerivedImpl*>(this)->tiltUpStopImpl();
    }

    void tiltDownStart()
    {
        static_cast<DerivedImpl*>(this)->tiltDownStartImpl();
    }

    void tiltDownStop()
    {
        static_cast<DerivedImpl*>(this)->tiltDownStopImpl();
    }

    /// \p At the time of writing speed should be [0-100] as a percentage of the motors capable speed
    void setSpeed(int speed)
    {
        static_cast<DerivedImpl*>(this)->setSpeedImpl(speed);
    }
};