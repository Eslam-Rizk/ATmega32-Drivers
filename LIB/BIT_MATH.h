// Macro to retrieve the value of a specific bit within a register
#define GET_BIT(reg, bitNum)  	reg & (1<<bitNum)

// Macro to set a specific bit within a register to 1
#define SET_BIT(reg, bitNum)  	reg |= (1<<bitNum)

// Macro to clear (set to 0) a specific bit within a register
#define CLR_BIT(reg, bitNum)  	reg &= ~(1<<bitNum)

// Macro to toggle the value of a specific bit within a register
#define TOGGLE_BIT(reg, bitNum)  reg ^= (1<<bitNum)
