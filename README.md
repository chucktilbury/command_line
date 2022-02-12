# Command Line
Simple robust command line parser for C.

This is a library routine that implements a command line parser that is similar to Python's ```argparse``` library. It supports
three types of command parameter and also an arbitrary list of names.

##### Data types
* string
  As the name implies this is a simple string as one would expect.
* num
  These are signed integers. A ```-``` at the start of a number is accepted and arithmetically negates the value.
* bool
  These are true and false parameters that require a value. Acceptable values are '1', '0', 'true', and 'false',
* none
  These are toggle boolean values. The default value is false and if the switch appears on the command line, then the value becomes true.

##### Generic use

Look at the header for more information.

1. Create the command line parser.
2. Add parameters.
3. Parse the command line.
4. Get the values. 


##### Desirable features that are not supported
* Options that are mutually exclusive.
* Options that are mutually required.
* Options that have a set of acceptable values.

These can all be implemented by the application that is using the library, but I have not found a clean way to implement them
in a generic manner without doing a lot of work that is of questionable value.
