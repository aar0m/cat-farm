Contribute to Animal Farm
=========================

### Coding Conventions
- `using namespace std` in `.cpp` files is OK
- `using namespace std` in `.h` files is **NOT** OK
- Animal Farm uses `cout`, not `printf`
- Sources that contain a `main()` are named `main_someProgram.cpp`
- Messages and exceptions should be pre-pended with `PROGRAM_NAME`
- Hierarchy of messages & error handling
    - DEBUG - Print message only when DEBUG is enabled
    - INFO - Print message for both debug and release code
    - WARN - Print a message
    - ERROR - Print message & throw an exception
        - Use `throw` for issues that we may want to catch, not warnings.  
          See [When to use assertions and when to use exceptions].
    - FATAL - Print message and kill the program
        - Use `assert()` for things that should never happen and we don't 
          really want to catch
- If implementation is present in a '.h' file, it will be documented as a '.cpp' file.
- Methods are normally separated by one line.
- If getters/setters are short enough in header files, I will omit the space between them
  and implement doxygen documentation via '///<'.
  - This rule applies to methods that are closely related (i.e. remove() and removeAll(), etc.).
- I follow suit and also document the one-line description of a function or member in the 
  `.h` file.  Then, I document the narrative/details `@param`, `@returns`, 
  `@throws`, `@todo` and Sample Output in the `.cpp` file.
- When declaring a class, declarations are separated via specific headers 
  in this order (with a fixed width of 80 characters):
    - Includes
    - // ////////////////////////////////////////////////////////////////////////////
    - Defines
    - // ////////////////////////////////////////////////////////////////////////////
    - // className Class ////////////////////////////////////////////////////////////
    - // Friend Classes /////////////////////////////////////////////////////////////
    - // Private members ////////////////////////////////////////////////////////////
    - // Protected members //////////////////////////////////////////////////////////
    - // Public members /////////////////////////////////////////////////////////////
    - // Constructor/destructor methods /////////////////////////////////////////////
    - // Methods ////////////////////////////////////////////////////////////////////
    - Declarations of 'public', 'private', and 'protected' are declared immediately after separator
    - Additional custom separators may be used for further clarity like:
      - Specifying public/private/protected methods
      - Specifying constructors that take different types of arguments

[When to use assertions and when to use exceptions]: https://softwareengineering.stackexchange.com/questions/15515/when-to-use-assertions-and-when-to-use-exceptions
