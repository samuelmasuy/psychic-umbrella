*Implementation of the Dice in d20 game*

Submited by: Samuel RRJ Masuy - 26590624.

*I certify that this submission is my original work and meets the Faculty's
Expectations of Originality*

### Dice Rule

1. User input a string matching the following pattern: **xdy[+z]**.

	* Where **x** is the number of times the dice has to be rolled.
	* **d** is a constant,
	* **y** is the kind of dice (number of sides on dice).
	* **+/-** is the operation of the modifier.
	* And **z** is a modifier to be applied, once all dice are rolled.

2. **x** number of dice get created.

3. All dice get rolled and produce a result of random(1, **y**).

4. Then, depending on the operation, we add or substract **z**.

For example, **2d4[+5]** would result into: *random(1, 4) + random(1, 4) + 5*

### Design

* **NOTE:** All Code is formated according to [Google C++ style guide](https://google.github.io/styleguide/cppguide.html).

* **NOTE:** We have never been provided with documented *doxygen* tests.
  Therefore, I did my best to come up with tests, and provide the appropriate
  documentation. It might not exactly reflect what is expected.

I have decided to create a class,  (**DiceRoller**), that parse the user input,
and create the dices that will be rolled during the game.

Once the **Dice** are created, the **DiceRoller** rolls them all, and finally
add or substract the modifier to output the result.

### Run

The main program, is in **RunApp.cpp**.

In the main program, we first execute the test suite, and then we execute, a
sample program that goes over the main feature of this Implementation.






