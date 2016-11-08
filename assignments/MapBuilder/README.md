*Implementation of the Map Builder for the d20 game*

Submited by: Samuel RRJ Masuy - 26590624.

*I certify that this submission is my original work and meets the Faculty's
Expectations of Originality*

### Design

* **NOTE:** All Code is formated according to [Google C++ style guide](https://google.github.io/styleguide/cppguide.html).

I have decided to create a class,  (**FileMapBuilder**), and (**InteractiveMapBuilder**).
The File Map builder reads a file and fill up a map.
While, the Interactive Map builder reads a file, and take a level as input.
It adapts the map with more chests and enemies according to the level specified

Once the **Dice** are created, the **DiceRoller** rolls them all, and finally
add or substract the modifier to output the result.

### Run

The main program, is in **RunApp.cpp**.

In the main program, we first execute the test suite, and then we execute, a
sample program that goes over the main feature of this Implementation.

### Warning

Please make sure that `map.txt` is included in the project, so that you can run
the tests.






