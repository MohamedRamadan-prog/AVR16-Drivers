/*
 * SPI_Cfg.h
 *
 * Created: 25/09/2017 11:33:30 م
 *  Author: SHIKO
 */ 


#ifndef SPI_CFG_H_
#define SPI_CFG_H_

void MasterMode_SPI_Inti ();
void SlaveMode_SPI_Inti  ();
void SPI_Send (uint8_t Data);
uint8_t SPI_Received (); 
#endif /* SPI_CFG_H_ */