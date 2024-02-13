# picklist

Simple world-building utility that'll randomly pick X number of lines out of a file(s).   


## Usage

    picklist
    picklist num
    picklist num file1...N
    
### Number 

This is expected to be a positive integer, and controls the number of output lines, which may be greater than the number of input lines.

### ZERO Arguments

Without arguments, picklist will select ONE line out of its standard input.  

### ONE Argument

With one argument, it is expected to be a positive number.  This will select the specified number of lines from the standard input.

### TWO or more Arguments

With two or more arguments, the first argument is expected to be a positive number.  The rest are filenames, that will be loaded.

## Output & Algorithm

Algorithm is simple, iterates, randomly selecting an output line.  There is no collision marking, so a specific input line may be repeated in the output.

## Example

CardSuits.txt

    Hearts
    Diamonds
    Clubs
    Spades
    
picklist 5 CardSuits.txt

    Diamonds
    Hearts
    Clubs
    Diamonds
    Clubs


