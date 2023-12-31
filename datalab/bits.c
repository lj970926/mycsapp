/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  int all_ones = x & y;
  int n_x = ~x;
  int n_y = ~y;
  int all_zeros = n_x & n_y;
  return (~all_ones) & (~all_zeros);
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {

  return 1 << 31;

}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  int plus_one = x + 0x1;
  int all_change = !(~(x ^ plus_one));
  int plus_one_is_zero = !plus_one;
  return all_change & !plus_one_is_zero;
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  int mask = 0;
  int pattern = 0xAA;
  mask = mask | pattern;
  pattern = pattern << 8;
  mask = mask | pattern;
  pattern = pattern << 8;
  mask = mask | pattern;
  pattern = pattern << 8;
  mask = mask | pattern;
  return !((~x) & mask);

}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return (~x) + 0x1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  int msb = 0x1 << 31;
  int left_bound = 0x30;
  int right_bound = 0x3a;
  int neg_left = (~left_bound) + 1;
  int neg_right = (~right_bound) + 1;
  int check_left = x + neg_left;
  int check_right = x + neg_right;
  return !(check_left & msb) & !!(check_right & msb);
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  int is_zero = !x;
  int neg_one = (~1) + 1;
  int mask = is_zero + neg_one;
  int inv_mask = ~mask;
  return (y & mask) | (z & inv_mask);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  int msb_mask = 0x1 << 31;
  int neg_x = (~x) + 1;
  int res = y + neg_x;
  int is_res_pos = !(res & msb_mask);
  int is_pos_x = !(x & msb_mask);
  int is_pos_y = !(y & msb_mask);
  int x_neg_y_pos = (!is_pos_x) & is_pos_y;
  int x_pos_y_neg = is_pos_x & (!is_pos_y);
  return (is_res_pos | x_neg_y_pos) & !x_pos_y_neg;
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  int neg_one = (~1) + 1;
  int x_minus_one = x + neg_one;
  int lsb_mask = 0x1;
  int s_x = (x >> 31) & lsb_mask;
  int s_x_one = (x_minus_one >> 31) & lsb_mask;
  return (s_x ^ s_x_one) & (s_x ^ 0x1);
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  int zero = 0;
  int neg_one = (~1) + 1;
  int shift_len = 16;

  int shifted_x = x >> shift_len;
  int not_enough = !(!(shifted_x ^ zero) | !(shifted_x ^ neg_one));
  int xor_mask = not_enough + neg_one;
  shift_len  = shift_len + ((8 ^ xor_mask) + !(not_enough));

  shifted_x = x >> shift_len;
  not_enough = !(!(shifted_x ^ zero) | !(shifted_x ^ neg_one));
  xor_mask = not_enough + neg_one;
  shift_len  = shift_len + ((4 ^ xor_mask) + !(not_enough)); 

  shifted_x = x >> shift_len;
  not_enough = !(!(shifted_x ^ zero) | !(shifted_x ^ neg_one));
  xor_mask = not_enough + neg_one;
  shift_len  = shift_len + ((2 ^ xor_mask) + !(not_enough));

  shifted_x = x >> shift_len; 
  not_enough = !(!(shifted_x ^ zero) | !(shifted_x ^ neg_one));
  xor_mask = not_enough + neg_one;
  shift_len  = shift_len + ((1 ^ xor_mask) + !(not_enough)); 

  shifted_x = x >> shift_len;
  not_enough = !(!(shifted_x ^ zero) | !(shifted_x ^ neg_one));
  shift_len = shift_len + not_enough; 

  return (shift_len & (!(x ^ zero) + neg_one) & (!(x ^ neg_one) + neg_one)) + 1;
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  unsigned exponent = (uf >> 23) & 0xff;
  unsigned mantissa = uf & 0x7fffff;
  unsigned sign = uf >> 31;
  unsigned res = 0;
  unsigned tmp = 0;
  if (exponent == 255) {
    return uf;
  } else if (exponent == 254) {
    mantissa = 0;
  } else if (exponent == 0) {
    tmp = mantissa << 1;
    if ((tmp >> 23) == 0) {
      mantissa = tmp;
      exponent = exponent - 1;
    } else {
      mantissa = tmp & 0x7fffff;
    }
  }
  exponent = exponent + 1;
  return (res | (sign << 31) | (exponent << 23)) + mantissa;
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  int exponent = (uf >> 23) & 0xff;
  int mantissa = uf & 0x7fffff;
  int sign = uf >> 31;
  int res = 0;

  exponent = exponent - 127;
  if (exponent < 0) {
    return 0;
  }
  if (exponent >= 31) {
    return 0x80000000u;
  }
  if (exponent <= 23) {
    mantissa = mantissa >> (23 - exponent);
  } else {
    mantissa = mantissa << (exponent - 23);
  }
  res =  (1 << exponent) + mantissa;
  if (sign == 1) {
    res = -res;
  }
  return res;

}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
    int exponent = 0;
    int mantissa = 0;
    int res = 0;
    if (x >= 128) {
      exponent = 255;
    } else if (x < -149) {
      exponent = 0;
    } else if (x < -126) {
      mantissa = 1 << (x + 149);
      exponent = 0;
    } else {
      exponent = x + 127;
    }
    res =  (exponent << 23) + mantissa;
    return res;
}
