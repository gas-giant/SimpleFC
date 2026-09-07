#include "cpu.h"

void Cpu::ADC(U8 value) {
    U16 temp = this->A + value + (this->P & 0x01); // Add value and carry flag to accumulator
    // C
    if (temp > 0xFF) {
        this->P |= 0x01; // Set Carry flag
    } else {
        this->P &= ~0x01; // Clear Carry flag
    }
    // Z
    if ((temp & 0xFF) == 0) {
        this->P |= 0x02; // Set Zero flag
    } else {
        this->P &= ~0x02; // Clear Zero flag
    }
    // N
    if (temp & 0x80) {
        this->P |= 0x80; // Set Negative flag
    } else {
        this->P &= ~0x80; // Clear Negative flag
    }
    // V
    if ((temp ^ this->A) & (temp ^ value) & 0x80) {
        this->P |= 0x40; // Set Overflow flag
    } else {
        this->P &= ~0x40; // Clear Overflow flag
    }
    this->A = temp & 0xFF; // Store the result in accumulator
}

void Cpu::AND(U8 value) {
    value &= this->A; // AND operation with accumulator
    if (value == 0) {
        this->P |= 0x02; // Set Zero flag
    } else {
        this->P &= ~0x02; // Clear Zero flag
    }
    if (value & 0x80) {
        this->P |= 0x80; // Set Negative flag
    } else {
        this->P &= ~0x80; // Clear Negative flag
    }
    this->A = value; // Store the result in accumulator
}

void Cpu::ASL(U8& value) {
    if (value & 0x80) {
        this->P |= 0x01; // Set Carry flag
    } else {
        this->P &= ~0x01; // Clear Carry flag
    }
    value <<= 1; // Shift left by 1
    if (value == 0) {
        this->P |= 0x02; // Set Zero flag
    } else {
        this->P &= ~0x02; // Clear Zero flag
    }
    if (value & 0x80) {
        this->P |= 0x80; // Set Negative flag
    } else {
        this->P &= ~0x80; // Clear Negative flag
    }
}