
 #ifndef BIT_MATH_H_
 #define BIT_MATH_H_

 #define NULL 0x0

 #define SET_BIT(REG , BITNUM) REG |= 1U<<BITNUM
 #define CLR_BIT(REG , BITNUM) REG &= ~(1U<<BITNUM)
 #define TOG_BIT(REG , BITNUM) REG ^= 1U<<BITNUM
 #define GET_BIT(REG , BITNUM) ( (REG >> BITNUM) & 1U )

 #endif /* BIT_MATH_H_ */
