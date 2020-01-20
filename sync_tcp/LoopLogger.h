
class LoopLogger
{
private:
    const unsigned long period_;
    unsigned long prevTimeLogged_;
    unsigned int steps_;
    bool timeToLog()
    {
        return (millis() - prevTimeLogged_) >= period_;
    }
public:
    LoopLogger(unsigned long period)
    : period_{period}, prevTimeLogged_{0}, steps_{0}
    {}
    void step()
    {
        steps_++;
        if (timeToLog())
        {
            Serial.printf("[%lu] loop: %u \n\r", millis(), steps_);
            prevTimeLogged_ = millis();
        }
    }
};
