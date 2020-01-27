#include <ros/ros.h>
#include "std_msgs/String.h"
#include "sun_pneumatic_gripper_common/ActivateSucker.h"
#include "serial/serial.h"
#include "std_srvs/Empty.h"

#define ERROR_COLOR     "\033[1m\033[31m"      /* Bold Red */
#define WARN_COLOR      "\033[1m\033[33m"      /* Bold Yellow */
#define SUCCESS_COLOR   "\033[1m\033[32m"      /* Bold Green */
#define CRESET          "\033[0m"

using namespace std;


//------------------------------------------------------------------------
// Global variables
//------------------------------------------------------------------------


//------------------------------------------------------------------------
// Function implementation
//------------------------------------------------------------------------



bool activate_suckerSrv(sun_pneumatic_gripper_common::ActivateSucker::Request &req, sun_pneumatic_gripper_common::ActivateSucker::Response &res){

if(req.sucker1 && (req.sucker2_3 || !req.sucker2_3)){
//attiva sucker1
ROS_INFO("SUCKER 1 ON");
} 
else {
//disattiva sucker1
ROS_INFO("SUCKER 1 OFF");
}

if ((req.sucker1 || !req.sucker1) && req.sucker2_3){
//attiva sucker2 e sucker3
ROS_INFO("SUCKER 2-3 ON");
}
else {
//disattiva sucker2 e sucker3
ROS_INFO("SUCKER 2-3 OFF");
}


return true;
}


/**
 * The main function
 */

int main( int argc, char **argv )
{

ros::init(argc, argv, "pneumatic_gripper");
ros::NodeHandle nh;

// Connect to device using serial port

/***** CHECK PARAMS ****/
/*string serial_port = string("");
nh.param("serial_port" , serial_port, string("/dev/ttyUSB0") );
string str_baud = string("");
nh.param("baud_rate" , str_baud, string("500000") );
sscanf(str_baud.c_str(), "%lu", &baud);
int serialTimeout = 0;
nh.param("serial_timeout" , serialTimeout, 1000 );*/


/*** INIT SERIAL ****/	
//serial::Serial my_serial(serial_port, baud, serial::Timeout::simpleTimeout(serialTimeout));

/*** CHECK ***/
/*if(!my_serial.isOpen()){
   cout << ERROR_COLOR << "ERROR - SERIAL PORT " << WARN_COLOR << serial_port << ERROR_COLOR << " is not open!" << CRESET <<endl;
   exit(-1);
}
cout << SUCCESS_COLOR << "SERIAL PORT " << WARN_COLOR << serial_port << SUCCESS_COLOR << " OPEN - OK" << CRESET << endl;*/


// Services
ros::ServiceServer activate_suckerSS;

activate_suckerSS=nh.advertiseService("activate_sucker",activate_suckerSrv);

//**** ROS MAIN LOOP  ***//
while(ros::ok()){
  
//my_serial.write(b2write,1);

ros::spinOnce();
}

}
