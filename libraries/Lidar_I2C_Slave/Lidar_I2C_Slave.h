#ifndef LIDAR_I2C_H
#define LIDAR_I2C_H
#include <stdint.h>



#define LDS_ADDRESS 0x02  

class LidarI2CSlave {
  
 public:
       LidarI2CSlave();
       void readLidarI2C();
	
	uint8_t getErrRoll();
	uint8_t getErrPitch();
	uint8_t getErrYaw();


private :
       uint8_t LDSState;
       uint8_t err_roll;
       uint8_t err_pitch;
       uint8_t err_yaw;



  
  
};












#endif
