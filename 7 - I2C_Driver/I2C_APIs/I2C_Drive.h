/*
 * I2C_Drive.h
 *
 * Created: 26/09/2017 12:16:00 ص
 *  Author: SHIKO
 */ 


#ifndef I2C_DRIVE_H_
#define I2C_DRIVE_H_

void I2C_Init ();
void I2c_Start ();
void I2C_Write(uint8_t Data);
uint8_t I2C_Read();


#endif /* I2C_DRIVE_H_ */