# Simplified Logic Circuit Simulator 
The goal of this school project was to write a simplified logic simulater using C++.
Files with .cir extension give us the specification of the components used in the logic circtuit that we want to simulate.
Among the components we can find:
* AND gates
* OR gates
* XOR gates
* NOT gates
* Input
* Output
* Net

An example of .cir files for the circuit_4

![cir](https://github.com/ahmetkurklu/oop-logic-sim/assets/24780090/e1d747d4-73bd-413d-acdb-d2122c8a6b30)

This circuit represent this :

![circuit](https://github.com/ahmetkurklu/oop-logic-sim/assets/24780090/0d4e451d-6bef-4223-a614-d7c4ab59de8c)

Each input has a .stm extension file that give us the values of the input that are High "-" or Low "_" each caractere represent an event.
Example of event for IN_A:

![in a stm](https://github.com/ahmetkurklu/oop-logic-sim/assets/24780090/a0060c9e-4fd3-42c6-a9bc-9f1a84eb028d)

For the main program, we first start by reading the .cir files and create the circuit by linking each components togheter. Then for each input we read the corresponding .stm files and create events for each High or Low state. The simulation then start, in which we propagate the signals from the input to the output. For the propagation using the same circuit presented previously :
* The input read the first event in his list an put the value on his ouput net.
* The component linked to this net read the value and then apply the modification in this case High become Low because with have a NOT gate.
* The component then create a new sub event with the new value on his output net.
* When a signal reach the ouput the propagation end and the value is saved in a file.

At the end of the simulation we get a chronograme that looks like this:

![chrono](https://github.com/ahmetkurklu/oop-logic-sim/assets/24780090/290dbcaf-6388-4c0f-8bc0-517325870029)

On 11 circuits our code was able to correctly simulate 10 circuits. 
