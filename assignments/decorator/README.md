*Implementation of the Decorator pattern for DND game*

Submited by: Samuel RRJ Masuy - 26590624.

*I certify that this submission is my original work and meets the Faculty's
Expectations of Originality*

### Rule

1. Character can only wear one type of item.
2. Character can remove one of its item.
3. Character can wear many items.

### Design

* **NOTE:** All Code is formated according to [Google C++ style guide](https://google.github.io/styleguide/cppguide.html).

It has been quite a challenge to come up with this architecture.
It would seem that the *Decorator pattern* might not be fully appropriate for
the situation.
The main problem came with the *remove()* method. This method implies that the
decorator keeps track of its states.
But after a lot of research, I concluded that the *Decorator pattern* is not
supposed to store any intermediate state.
I still have implemented the *remove()* method, but it didn't feel like right,
and it seemed that I was fighting against the wall.

Anyway, a good learning experience!

### Run

The main program, is in **main.cpp**.

In the main program, we first execute the test suite, and then we execute, a
sample program that goes over the main feature of this Implementation.

### Libraries

Other than, **cppunit**, I am not using any other external libraries.

As part of my design, I am using **exception**. Maybe in the future, I will
change the exception to *error codes* instead. I have read that *exception* are
not the best design in C++.
