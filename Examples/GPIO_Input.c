#include "platform.h"
#include "gpio.h"

/** @fn void main()
 * @brief Reads the state across all the GPIO pins in the system
 * @details
 */
unsigned long read_data = 0;
void main()
{
    //Assume  0 for INPUT and  1 for OUTPUT
    write_word(GPIO_DIRECTION_CNTRL_REG, 0x00000000);

    while (1) {
        read_data = read_word(GPIO_DATA_REG); /* Copies the GPIO_DATA_REG Register contents */
        printf("\n 0x%x",read_data);
	delay(50);
    }
}

