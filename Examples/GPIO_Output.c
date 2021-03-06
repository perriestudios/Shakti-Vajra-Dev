#include "platform.h"
#include "gpio.h"

/** @fn void main()
 * @brief Triggering every 4th GPIO Pin On in cycle
 * @details The GPIO's are set high using the first 4 commands inside the while loop and the last command shuts them down.
 */
void main()
{
    //Assume  0 for INPUT and  1 for OUTPUT
    write_word(GPIO_DIRECTION_CNTRL_REG, 0xFFFFFFFF);
    while(1){
    	write_word(GPIO_DATA_REG,0x11111111); //GPIO 0,4,8,12,16,20,24,28 are HIGH
    	delay(100);
    	write_word(GPIO_DATA_REG,0x22222222); //GPIO 1,5,9,13,17,21,25,29 are HIGH
    	delay(100);
    	write_word(GPIO_DATA_REG,0x44444444); //GPIO 2,6,10,14,18,22,26,30 are HIGH
    	delay(100);
    	write_word(GPIO_DATA_REG,0x88888888); //GPIO 3,7,11,15,19,23,27,31 are HIGH
    	delay(100);
	write_word(GPIO_DATA_REG,0x00000000); //All GPIO's are LOW
    	delay(100);
    }
}

