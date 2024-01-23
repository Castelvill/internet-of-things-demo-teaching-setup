#include <stdio.h>
#include <stdint.h>

// Address of the simulated device's register bank in physical memory
#define DEVICE_REGISTER_ADDRESS 0x1000 // Replace with the actual physical address

// Register wrapper
typedef struct {
    volatile uint32_t *reg; // Pointer to the register in physical memory
} RegisterWrapper;

// Function to read from the register
uint32_t read_register(RegisterWrapper *r) {
    return *(r->reg);
}

// Function to write to the register
void write_register(RegisterWrapper *r, uint32_t data) {
    *(r->reg) = data;
}

int main() {
    // Pointer to the register bank in physical memory
    volatile uint32_t *device_register_bank = (volatile uint32_t *)DEVICE_REGISTER_ADDRESS;

    // Create a register wrapper for register 0
    RegisterWrapper r;
    r.reg = &(device_register_bank[0]); // Pointer to register 0

    // Test reading from the register
    uint32_t read_value = read_register(&r);
    printf("Initial Read Value: %u\n", read_value);

    // Write a value to the register
    write_register(&r, 0x4711);

    // Test reading after writing to the register
    read_value = read_register(&r);
    printf("Value after Write: %u\n", read_value);

    // Even after writing, confirm that the register still holds the initial value (read_value)
    read_value = read_register(&r);
    printf("Final Read Value: %u\n", read_value);

    return 0;
}