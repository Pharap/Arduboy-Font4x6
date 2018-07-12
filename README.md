# Arduboy Font4x6
A modified version of @filmote's Font4x6.
The original can be found [here](https://github.com/filmote/Font4x6).

Changes include:
* Added licence header
* Changed formatting to Allman style
* Reorganised class declaration
* Removed unnecessary `const` qualifiers
* Replaced `setHeight` with `setLineSpacing`
* Changed internal type of text colour to `uint8_t`
* Removed americanised spellings of colour
* Introduced getter functions for all properties
* Introduced additional setter functions for other properties
* Removed the parameterised constructor
* Introduced an explicitly defaulted constructor
* Added default member initialisers for all member variables
* Replaced all non-conditional macros with `constexpr` variables
* Added conditional compilation option for using `SpritesB` 