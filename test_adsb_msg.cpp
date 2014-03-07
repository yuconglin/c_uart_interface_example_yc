#include "common/mavlink.h"
#include "pixhawk/mavlink_msg_marker.h"
#include "mavlink_helpers.h"
//standard includes
#include <iostream>
#include <cmath>

void test_encode_decode()
{
   char buf[300];
   mavlink_message_t message;
   mavlink_adsb_msg_t adsb_msg;
   
   //set components of adsb_msg
   adsb_msg.latitude=33.418422; ///< Latitude
   adsb_msg.longitude=-111.928573; ///< Longitude
   adsb_msg.altitude= 6; ///< Altitude:actual= ddd*25-1000
   adsb_msg.h_velocity= 6; ///< Horizontal velocity in knots
   adsb_msg.v_velocity= 6; ///< Vertical velocity in 64fpm
   adsb_msg.traffic_alert_status=1; ///< Traffic Alert Status.1:active
   adsb_msg.address_type=0; ///< Address Type
   adsb_msg.address[0]=4;
   adsb_msg.address[1]=2;
   adsb_msg.address[2]=3;///< Participant Addrss
   adsb_msg.misc_indicator=1; ///< Miscellaneous Indicator
   adsb_msg.NIC=2; ///< Navigation Integrity Category
   adsb_msg.NACp=2; ///< Navigation Accuracy Category for Position
   adsb_msg.heading=4; ///< Track/Heading in 360/128 degree,0=North,128=South
   
   //send from system id and component id
   mavlink_msg_adsb_msg_encode(200, 0, &message, &adsb_msg);
   unsigned len= mavlink_msg_to_send_buffer((uint8_t*)buf, &message);
   //test decode
   static mavlink_status_t status;
   mavlink_message_t msg;
   uint8_t chan= 0;
   for(int i=0;i!= len;++i)
   {
      if (mavlink_parse_char(chan, buf[i], &msg, &status)) 
         std::cout<<"there is hope."<< std::endl;
   }//for ends
   
   //for quad
   mavlink_set_quad_swarm_roll_pitch_yaw_thrust_t sp;

   sp.group = 0;
   
   /* set rate mode, set zero rates and 20% throttle */
   sp.mode = 2;

   sp.roll[0] = 1;
   sp.pitch[0] = 1;
   sp.yaw[0] = 1;
   sp.thrust[0] = 0.5;

   /* send from system 200 and component 0 */
   mavlink_msg_set_quad_swarm_roll_pitch_yaw_thrust_encode(200, 0, &message, &sp);

   memset(buf,0,sizeof(buf) );
   len = mavlink_msg_to_send_buffer((uint8_t*)buf, &message);
   for(int i=0;i!= len;++i)
   {
      if (mavlink_parse_char(chan, buf[i], &msg, &status)) 
         std::cout<<"there is hope, quad"<< std::endl;
   }//for ends
   
   //for a simple test message
   mavlink_yc_test_msg_t test_msg;
   test_msg.data= 2;
   mavlink_msg_yc_test_msg_encode(200,0,&message, &test_msg);
   memset(buf,0,sizeof(buf) );
   len = mavlink_msg_to_send_buffer((uint8_t*)buf, &message);
   for(int i=0;i!= len;++i)
   {
      if (mavlink_parse_char(chan, buf[i], &msg, &status)) 
         std::cout<<"there is hope, test"<< std::endl;
   }//for ends

   //for testing pixhawk
   mavlink_marker_t marker_msg;
   marker_msg.x=1;
   marker_msg.y=2;
   marker_msg.z=3;
   marker_msg.roll=1;
   marker_msg.pitch=2;
   marker_msg.yaw=3;
   marker_msg.id =4;
   mavlink_msg_marker_encode(200,0,&message, &marker_msg);
   memset(buf,0,sizeof(buf) );
   len = mavlink_msg_to_send_buffer((uint8_t*)buf, &message);
   for(int i=0;i!= len;++i)
   {
      if (mavlink_parse_char(chan, buf[i], &msg, &status)) 
         std::cout<<"there is hope, pixhawk marker"<< std::endl;
   }//for ends


}//test_encode_decode ends

int main(int argc, char** argv)
{
   test_encode_decode();
   return 0;
}//main ends
