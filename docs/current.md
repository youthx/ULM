# ULM VM 
## Documentation

#### Basic stack instructions
* `push`     - Pushes an 8-bit integer to the stack
* `add`      - pops & adds the two latest values from the stack together, and pushes the result
* `excode`   - pops the stack and sets the result as the exit code.
* `halt`     - exits the program

#### Datatypes
* `8bit signed integer` defined as a `int8`, when declared, it must start with a `n` (Ex. `n4`)
* `8bit unsigned integer` defined as a `uint8`, when declared. it must start with a `u` (Ex. `u8`)
 -------------
* `32bit signed integer` defined as a `int32`, when declared, it must start with a `n` (Ex. `n12`)
* `32bit unsigned integer` defined as a `uint32`, when declared. it must start with a `u` (Ex. `u12`)
  