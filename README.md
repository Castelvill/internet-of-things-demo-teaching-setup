# Internet-of-things demo/teaching setup.

▪ Start from RISC-V simple
▪ Add some models of sensors and actuators
▪ Write a physics model for some physical systems (preferably one with feedback effects)
▪ Write a control program that runs on the RISC-V – either on Linux (requires custom driver), bare metal
▪ Simulate the system under various disturbances

Key pieces:
▪ Model a sensor in Simics
▪ Put sensor into memory map
▪ Write code to read-write it
▪ Build a Physics model in Python – run in Simics
▪ Connect sensor model to physics model
▪ Model an actuator
▪ Write control loop code thatreads sensor, drives actuator
▪ ”Kick” the physics model