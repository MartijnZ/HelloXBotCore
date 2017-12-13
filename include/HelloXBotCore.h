

#ifndef __HELLOXBOTCORE_H__
#define __HELLOXBOTCORE_H__


#include <XCM/XBotControlPlugin.h>

class HelloXBotCore : public XBot::XBotControlPlugin
{

    public: 

        HelloXBotCore();
        
        virtual bool init_control_plugin(XBot::Handle::Ptr handle);

        virtual bool close();

        virtual void on_start(double time);

        virtual void on_stop(double time);

    protected:

        virtual void control_loop(double time, double period);

    private:
        XBot::RobotInterface::Ptr _robot;

};
#endif //__HELLOXBOTCORE_H__
