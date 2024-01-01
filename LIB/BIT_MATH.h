#define GET_BIT(reg,bitNum)  	reg & (1<<bitNum)
#define SET_BIT(reg,bitNum)  	reg|=(1<<bitNum)
#define CLR_BIT(reg,bitNum)  	reg&=~(1<<bitNum)
#define TOGGLE_BIT(reg,bitNum)  reg ^=(1<<bitNum)
