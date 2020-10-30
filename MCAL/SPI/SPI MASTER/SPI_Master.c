/*

 * SPI.c
 *
 * Created: 2/8/2020 10:15:20 PM
 * Author : EbrahimOseif
 */
#include "SPI_Master.h"
#include  "../../../Infrastructure/registers.h"

extern ST_SPI_Configuration SPI_Config ;
extern volatile uint8_t u8_DATA;

void SPI_Init()
{

	 ST_SPI_Configuration *gConfig = & SPI_Config;

	/********************Enable SPI Interrupt ******************/

	//SPCR = SPCR | (SPI_INT_ENABLE<<SPIE);
	SPCR = gConfig->MASTER_SLAVE_MODE | gConfig->DATA_ORDER
			  | gConfig->OPERATING_LEVEL | gConfig->PRESCALAR
			 | gConfig->SAMPLING_EDGE | gConfig ->INT_ENABLE;

	SPSR |= gConfig->DOUBLE_SPEED;
DIO_init(&SPI_Slave_Config);
DIO_init(&SPI_Slave_Config1);
		SPCR |=  gConfig->ENABLE;



}
void SPI_Transciever_INT(void)
{
	SPDR=u8_DATA;
}
void  SPI_Send(uint8_t u8_data)
{
     /* Start transmission */
     SPDR = u8_data;
    if (!(READBIT(SPCR,SPIE)))
    {
	 	/* Wait for transmission complete */
     while(!(SPSR & (1<<SPIF)));
		}
}


uint8_t spi_INT_CALLED(void){
	return SPDR;
}

uint8_t  SPI_Receive(void)
{
	if (!(READBIT(SPCR,SPIE)))
	{
		/* Wait for transmission complete */
		while(!(SPSR & (1<<SPIF)));
		//return SPDR ; // Received data
	}
	return SPDR;
}


 uint8_t SPI_Checks_for_collision(void)
{
	 return READBIT(SPSR, WCOL);
}

void SPI_De_Init(void)
{
SPCR=0;
}
void spi_send_first(uint8_t data)
{
SPDR=data;
}
