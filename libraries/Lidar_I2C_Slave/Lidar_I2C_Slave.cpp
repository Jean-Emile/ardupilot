
#include "Lidar_I2C_Slave.h"

#include <I2C.h>
LidarI2CSlave::LidarI2CSlave(){
  
   I2c.begin();
  LDSState = 1; 
}


uint8_t LidarI2CSlave::getErrRoll(){
return err_roll;
}
uint8_t LidarI2CSlave::getErrPitch(){
return err_pitch;
}

uint8_t LidarI2CSlave::getErrYaw(){
return err_yaw;
}
void LidarI2CSlave::readLidarI2C()
{

	if(LDSState==1)	// New Read request
	{
		I2c.requestFrom(0x02 ,3);
		LDSState++;	// new state expects data
	}



	if (LDSState>=2)	// Waiting for first Data byte from a previous read request
	{

		LDSState++;	// new state reading data
		if( I2c.available())    	// if 4 bytes were received
		{

			err_roll = I2c.receive();  		
			err_pitch = I2c.receive();  	
		        err_yaw = I2c.receive();  		
					
			LDSState = 1;			
		}

		if (LDSState>=10) 		// Waited too long for data	
			LDSState = 1;			// back to ready to Read state

	}

}




