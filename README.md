# ISS-Tracking-Pointer
ISS Orbit Tracking Pointer

See YouTube video linked below for more information about this project. This branch compiles onto the Arduino 101. It can probably be used on any Arduino board by replacing the `Curie` libraries with their standard complements.

This specific branch is designed for use with the 28BYJ-48 stepper motors. You can find these on Amazon [here](https://smile.amazon.com/gp/product/B01CP18J4A/ref=oh_aui_detailpage_o06_s00?ie=UTF8&psc=1). It may be cheaper in other places, but it's hard to complain about $3 per motor.

Next Steps:
* Make stepper motors move more efficiently
* Prevent stepper motors from tangling their wires

Stretch Goals:
* Add switching setup to find correct starting orientation
* Trim code a bit more to allow for future improvements
* Automatically detect whether you're compiling for Curie-based systems or not
 
After these are done I will work on improving the Nucleo F401RE side of things.

<a href="https://www.youtube.com/watch?v=sIE0mcOGnms" target="_blank"><img src="http://img.youtube.com/vi/sIE0mcOGnms/0.jpg" 
alt="ISS ORBIT TRACKING POINTER" width="480" height="360" border="10" /></a>

Copyright (c) 2015 Grady Hillhouse

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
