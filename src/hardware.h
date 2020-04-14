# ifndef hardware_H
# define hardware_H

# include <stdint.h>

	void pinMode( uint8_t, uint8_t );    

	int  digitalRead( int );

	int i2cReadRegister( int registerAddress);

    void write_lcd( uint8_t );

# endif // hardware_H
