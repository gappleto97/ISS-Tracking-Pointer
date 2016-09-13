/* Satellite Orbit Tracking Pointer
Grady Hillhouse 2015
Arduino Port:
Gabe Appleton 2016
*/

#include <CurieTime.h>
#include "sgp4io.h"
#include "sgp4coord.h"

//ENTER SITE DETAILS HERE
#define siteLatRad  46.5476 * pi / 180.0  //+North (Marquette)
#define siteLonRad -87.3956 * pi / 180.0  //+East (Marquette)
#define siteAlt     0.193                 //km (Marquette)

//ENTER TWO LINE ELEMENT HERE
#define LINE1 "1 25544U 98067A   16256.70334950  .00008023  00000-0  12970-3 0  9996"
#define LINE2 "2 25544  51.6463 341.3922 0005915 310.8243 146.2499 15.53818115 18600"

// Class for interacting with 28BYJ-48 stepper motors
class stepper {
  private:
    unsigned char pin1, pin2, pin3, pin4;
    unsigned short steps_left = 4095;
    bool direct = 0;
    void step(unsigned short to)  {
      while (steps_left != to) {
        digitalWrite(pin1, ((steps_left + 3) % 8) > 2 ? LOW : HIGH);
        digitalWrite(pin2, ((steps_left + 5) % 8) > 2 ? LOW : HIGH);
        digitalWrite(pin3, ((steps_left + 7) % 8) > 2 ? LOW : HIGH);
        digitalWrite(pin4, ((steps_left + 1) % 8) > 2 ? LOW : HIGH);
        steps_left += 2 * direct - 1;
        steps_left %= 4096;
        delay(1);
      }
    };
  public:
    stepper(unsigned char out1, unsigned char out2, unsigned char out3, unsigned char out4) {
      pin1 = out1;
      pin2 = out2;
      pin3 = out3;
      pin4 = out4;
      pinMode(pin1, OUTPUT);
      pinMode(pin2, OUTPUT);
      pinMode(pin3, OUTPUT);
      pinMode(pin4, OUTPUT);
    };
    inline void toStep(short absPosition)  {
      step(((absPosition % 4096) + 4096) % 4096);  // double modulus allows it to wrap correctly
    };
    inline void goHome()  {
      toStep(0);
    };
    inline void toDegree(double degree)  {
      toStep((short)((512 * degree) / 45.0));
    };
    inline void toRadian(double rad) {
      toStep((short)((2048 * rad) / 3.14159265358979323846));
    }
    inline void reverse()  {
      direct = !direct;
    };
};

stepper *Azimuth = NULL;
stepper *Elevation = NULL;

//SET UP SOME VARIABLES
double ro[3], vo[3], recef[3], vecef[3];
gravconsttype  whichconst;

double jdC;
double latlongh[3]; //lat, long in rad, h in km above ellipsoid
double razel[3], razelrates[3];
elsetrec satrec;
bool isItCalled = false;

void setup()  {

  Azimuth = new stepper(8, 9, 10, 11);
  Elevation = new stepper(4, 5, 6, 7);

  //FREEDOM OF MOVEMENT CHECKS
//
//    Azimuth->toDegree(180);
//    delay(1000);
//    Azimuth->toDegree(0);
//    Azimuth->reverse();
//    delay(1000);
//    Azimuth->toRadian(pi);
//    delay(1000);
//    Azimuth->toRadian(0);
//    Azimuth->reverse();
//
//    Elevation->toRadian(pi);
//    delay(1000);
//    Elevation->toRadian(0);
//    Elevation->reverse();
//    delay(1000);
//    Elevation->toRadian(pi);
//    delay(1000);
//    Elevation->toRadian(0);
//    Elevation->reverse();
    delay(1000);
  Serial.begin(115200);


  setTime(1473759957);

//TWO-LINE ELEMENT
  char line1[] = LINE1;
  char line2[] = LINE2;

  //SET VARIABLES
  double tumin, mu, radiusearthkm, xke, j2, j3, j4, j3oj2, startmfe, stopmfe, deltamin;
  getgravconst( wgs72, tumin, mu, radiusearthkm, xke, j2, j3, j4, j3oj2 );
  twoline2rv(line1, line2, 'c', 'e', 'i', whichconst, startmfe, stopmfe, deltamin, satrec, isItCalled);
  //Call propogator to get initial state vector value
  sgp4(whichconst, satrec, 0.0, ro, vo);
//  Serial.println("twoline2rv function complete...");
//  Serial.println("SGP4 at t = 0 to get initial state vector complete...");

  //BEGIN SATELLITE TRACKING
}

void loop ()   {

  //RUN SGP4 AND COORDINATE TRANSFORMATION COMPUTATIONS
  jdC = getJulianFromUnix(now());
  sgp4(whichconst, satrec, (jdC - satrec.jdsatepoch) * 24.0 * 60.0, ro, vo);
  teme2ecef(ro, vo, jdC, recef, vecef);
  ijk2ll(recef, latlongh);
  rv2azel(ro, vo, siteLatRad, siteLonRad, siteAlt, jdC, razel, razelrates);
//  delay(5000);

  Serial.print("Julian time: ");
  Serial.println(jdC);
  if (isItCalled)
    Serial.println("The code was called!?!?");

  if (satrec.error > 0)
  {
    Serial.println("# *** error: t:= ");
    Serial.println(satrec.t);
    Serial.println(" *** code = ");
    Serial.println(satrec.error);
  }
  else
  {

    Serial.println("azimuth: ");
    Serial.println(razel[1] * 180 / pi + 360.0 * (razel[1] < 0));
    Serial.println("elevation: ");
    Serial.println(razel[2] * 180 / pi + 360.0 * (razel[2] < 0));
    Azimuth->toRadian(razel[1]);

    Elevation->toRadian(razel[2]);
    delay(1000);
  }


} //indefinite loop
