# ISS-Tracking-Pointer
ISS Orbit Tracking Pointer

See YouTube video linked below for more information about this project. This branch compiles onto the Arduino 101. It can probably be used on any Arduino board by replacing the `Curie` libraries with their standard complements.

This specific branch is designed for use with the 28BYJ-48 stepper motors. You can find these on Amazon [here](https://smile.amazon.com/gp/product/B01CP18J4A/ref=oh_aui_detailpage_o06_s00?ie=UTF8&psc=1). It may be cheaper in other places, but it's hard to complain about $3 per motor.

Stretch Goals:
* Add switching setup to find correct starting orientation
* Trim code a bit more to allow for future improvements and more 101 features (may be near minimum already)
 
After these are done I will work on improving the Nucleo F401RE side of things.

Table of supported Arduino models:

|             Feature             |  101  | Mega (1280) | Mega (2560) | Mega (ADK) |  Due  | Zero  | MKR1000 | Others? |
| :------------------------------ | :---: | :---------: | :---------: | :--------: | :---: | :---: | :-----: | :-----: |
| Basic                           | x     | x           | x           | x          | x     | x     | x       | ?       |
| No Slip Ring                    | x     | x           | x           | x          | x     | x     | x       | ?       |
| Debug                           | x     | x           | x           | x          | x     | x     | x       | ?       |
| GPS                             | x     | x           | x           | x          | x     | x     | x       | ?       |
| Ethernet                        | x     | x           | x           | x          | x     | x     | x       | ?       |
| GPS + Debug                     | x     | x           | x           | x          | x     | x     | x       | ?       |
| Ethernet + Debug                | x     | x           | x           | x          | x     | x     | x       | ?       |
| GPS + Ethernet                  | x     | x           | x           | x          | x     | x     | x       | ?       |
| GPS + Ethernet + Debug          |       | x           | x           | x          | x     | x     | x       | ?       |
| GPS + Ethernet + No Slip Ring   | x     | x           | x           | x          | x     | x     | x       | ?       |
| GPS + Debug + No Slip Ring      | x     | x           | x           | x          | x     | x     | x       | ?       |
| Ethernet + Debug + No Slip Ring | x     | x           | x           | x          | x     | x     | x       | ?       |
| All                             |       | x           | x           | x          | x     | x     | x       | ?       |

Note: The Mega, Zero, Due, and MKR1000 listings are theoretical. I have no device to test this on, but it *should* work. You may need to change some pin constants though. I'm perfectly happy to add some pre-processor changes to automate this if they are brought to my attention.

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
