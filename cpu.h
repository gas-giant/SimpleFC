#include "common.h"
class Cpu {
private:
    /*
        A:  Accumulator
        SP: Stack Pointer (Stack address: 0x0100 - 0x01FF)
        X:  X index register
        Y:  Y index register
        PC: Process Counter
        P:  status register
            [ N V U B D I Z C ]
              7     ...     0
            N:  Negative
            V:  oVerflow
            U:  Unused. Default 1.
            B:  Break flag
            D:  Decimal flag
            I:  IRQ disable
            Z:  Zero
            C:  Carry
     */
    U8 A, SP;
    U8 X, Y;
    U16 PC;
    U8 P;
};