#include "vex.h"
#include "note.h"

void driveTime(int ms){
  chassis.drive_with_voltage(12,12);
  wait(ms,msec);
  chassis.DriveL.stop(brake);
  chassis.DriveR.stop(brake);
}

int info(){
  while (1)
  {
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(0, 50, "X: %f", chassis.get_X_position());
    Brain.Screen.printAt(0, 70, "Y: %f", chassis.get_Y_position());
    Brain.Screen.printAt(0, 90, "Heading: %f", chassis.get_absolute_heading());
    Brain.Screen.printAt(0, 110, "ForwardTracker: %f", chassis.get_ForwardTracker_position());
    Brain.Screen.printAt(0, 130, "SidewaysTracker: %f", chassis.get_SidewaysTracker_position());
    task::sleep(20);
  }
  return 1;
}

void RW_right()
{

  vex::color selectedTeamColor = vex::color::red;
 // task info(info);
   chassis.set_drive_constants(12, .5, 0.005, 4, 20);
   chassis.set_heading_constants(12, .25, 0.007, 5, 20);
   chassis.turn_to_angle(312);
  //--------------------------------------------------------
   chassis.set_drive_constants(12, 2.0, 0.005, 5, 5);
   chassis.set_heading_constants(12, 1.5, 0.005, 5, 10); 
   chassis.drive_distance(3,313,10,10);
  //----------------------------------------------------------------------
   hang1.spin(reverse,12,volt);
   hang2.spin(reverse,12,volt);
   hang1.spinToPosition(-280,degrees,50,rpm,true);
   chassis.drive_distance(-3,315,12,12);//微退一點
   //---------------------------------------------------------------------
   chassis.set_drive_constants(12, 1.5, 0.005, 6, 20);
   chassis.set_heading_constants(12, 1.2, 0.007, 6, 20);
   chassis.drive_distance(-24.5,290,12,12);
   //---------------------------------------------------------------
   chassis.set_drive_constants(12, 1, 0.005, 6, 5);
   chassis.set_heading_constants(12, 1, 0.007, 6, 5);
   chassis.drive_distance(-10,290,5,5);
   //---------------------------------------------------
   intakeCylander = true;
   wait(0.4,sec);
   //----------------------------------------------------------------
   chassis.set_drive_constants(12, 1, 0.005, 5, 20);
   chassis.set_heading_constants(12, 1, 0.005, 5, 20);
   chassis.turn_to_angle(190);
   //----------------------------------------------------------------
   intake.spin(forward,12,volt);
   intakedown.spin(reverse,12,volt);
   chassis.drive_distance(19,190,8,8);
   hang1.spin(forward,6,volt);
   hang2.spin(forward,6,volt);
   chassis.turn_to_angle(337);
   //------next---------
   chassis.set_drive_constants(12, 1.2, 0.005, 6, 20);
   chassis.set_heading_constants(12, 1.2, 0.007, 6, 20);
   chassis.drive_distance(33,337,12,12);
   chassis.set_drive_constants(12, 1, 0.005, 6, 5);
   chassis.set_heading_constants(12, 1, 0.007, 6, 5);
   chassis.drive_distance(10,337,5,5);
   chassis.drive_with_voltage(1.5,1.5);
   
   
//--------------------- 排除藍色--------------------------------
bool hasnote = false; 
while (!hasnote) {
  if (Optical.isNearObject()) {
    
    intake.spin(forward,12,volt);
    pushCylinder = 1 ;
    wait(0.5, sec); 
    hasnote = true;
  }
  wait(10, msec); 
}
pushCylinder = 0 ;
chassis.drive_distance(-16,340,12,12); 
wait(0.4,sec);
chassis.turn_to_angle(90) ;
intakedown.stop(brake);
chassis.drive_distance(24,75,12,12);
intake.stop(brake);
hang1.stop(brake);
hang2.stop(brake);
}

void R3_right()
//=================================3顆===================================================
{
 
  vex::color selectedTeamColor = vex::color::red;
  //task info(info);
   chassis.set_drive_constants(12, .5, 0.005, 4, 20);
   chassis.set_heading_constants(12, .25, 0.007, 5, 20);
   chassis.turn_to_angle(313);
   //---------------------------------------------------------------------
   chassis.set_drive_constants(10, 1.2, 0.005, 6, 10);
   chassis.set_heading_constants(10, 1.2, 0.007, 6, 10);
   chassis.drive_distance(-34,290,7,7);
   intakeCylander = true;
   wait(0.4,sec);
   //----------------------------------------------------------------
   chassis.set_drive_constants(12, 1, 0.005, 5, 20);
   chassis.set_heading_constants(12, 1, 0.005, 5, 20);
   chassis.turn_to_angle(190);
   //----------------------------------------------------------------
   intake.spin(forward,12,volt);
   intakedown.spin(reverse,12,volt);
   chassis.drive_distance(19,190,8,8);

   chassis.turn_to_angle(337);
   //------next---------
   chassis.set_drive_constants(12, 1.2, 0.005, 6, 20);
   chassis.set_heading_constants(12, 1.2, 0.007, 6, 20);
   chassis.drive_distance(33,337,12,12);
   chassis.set_drive_constants(12, 1, 0.005, 6, 5);
   chassis.set_heading_constants(12, 1, 0.007, 6, 5);
   chassis.drive_distance(10,337,5,5);
   chassis.drive_with_voltage(1.5,1.5);
   
   
//--------------------- 排除藍色--------------------------------
bool hasnote = false; 
while (!hasnote) {
  if (Optical.isNearObject()) {
    
    intake.spin(forward,12,volt);
    pushCylinder = 1 ;
    wait(0.5, sec); 
    hasnote = true;
  }
  wait(10, msec); 
}
chassis.drive_distance(8,340,10,10);
pushCylinder = 0 ;
chassis.drive_distance(-24,340,12,12); 
chassis.turn_to_angle(90) ;
intakedown.stop(brake);
chassis.drive_distance(24,75,12,12);
intake.stop(brake);
  

}
void RW_left(){
   vex::color selectedTeamColor = vex::color::red;
  //task info(info);
   chassis.set_drive_constants(12, .5, 0.005, 4, 20);
   chassis.set_heading_constants(12, .25, 0.007, 5, 20);
   chassis.turn_to_angle(49);
  //--------------------------------------------------------
   chassis.set_drive_constants(12, 2.0, 0.005, 5, 5);
   chassis.set_heading_constants(12, 1.5, 0.005, 5, 10); 
   chassis.drive_distance(3,49,10,10);
  //----------------------------------------------------------------------
   hang1.spin(reverse,12,volt);
   hang1.spinToPosition(-260,degrees,50,rpm,true);
   chassis.drive_distance(-3,45,10,10);//微退一點
   //---------------------------------------------------------------------
   chassis.set_drive_constants(12, 1.2, 0.005, 6, 20);
   chassis.set_heading_constants(12, 1.2, 0.007, 6, 20);
   chassis.drive_distance(-24.5,70,12,12);
   hang1.spin(forward,12,volt);
   hang2.spin(forward,12,volt);
   chassis.set_drive_constants(12, 1, 0.005, 6, 5);
   chassis.set_heading_constants(12, 1, 0.007, 6, 5);
   chassis.drive_distance(-10,70,5,5);
   intakeCylander = true;
   hang1.stop(coast);
   hang2.stop(coast);
   wait(0.4,sec);
   //-----------------------------------------------------------------
   chassis.set_drive_constants(12, 1, 0.005, 5, 20);
   chassis.set_heading_constants(12, 1, 0.005, 5, 20);
   chassis.turn_to_angle(180);
   //----------------------------------------------------------------
   intake.spin(forward,12,volt);
   intakedown.spin(reverse,12,volt);
   chassis.drive_distance(20,180,8,8);
   wait(0.2,sec);
   chassis.drive_distance(-17.5,180,8,8);
   wait(0.2,sec);
   chassis.turn_to_angle(225);
   chassis.set_drive_constants(4, 1, 0.005, 5, 20);
   chassis.set_heading_constants(4, 1, 0.005, 5, 20);
   chassis.drive_distance(13,225,4,4);
   wait(0.3,sec);
   chassis.set_drive_constants(12, 1, 0.005, 5, 20);
   chassis.set_heading_constants(12, 1, 0.005, 5, 20);
   chassis.turn_to_angle(195);
   chassis.set_drive_constants(12, 1.2, 0.005, 5, 20);
   chassis.set_heading_constants(12, 1.2, 0.005, 5, 20);
   chassis.drive_distance(6,195,12,12);
   //--------------eat 2 red----------------
   chassis.set_drive_constants(12, 1.4, 0.005, 5, 35);
   chassis.set_heading_constants(12, 1.4, 0.005, 5, 35);
   chassis.drive_distance(-25,215,12,12);
   chassis.turn_to_angle(38);
   intake.spin(forward,12,volt);
   chassis.drive_distance(8,38,10,10);
   chassis.drive_with_voltage(1.5,1.5);
   //--------------------- 排除藍色--------------------------------
bool hasnote = false; 
while (!hasnote) {
  if (Optical.isNearObject()) {
    
    intake.spin(forward,12,volt);
    pushCylinder = 1 ;
    wait(0.5, sec); 
    hasnote = true;
  }
  wait(10, msec); 
}
chassis.drive_distance(5,38,10,10);
pushCylinder = 0 ;
wait(0.5,sec);
chassis.drive_distance(-18,38,12,12);
chassis.drive_distance(-28,135,12,12);
intake.stop(brake);
intakedown.stop(brake);

}
void R5_left(){
  vex::color selectedTeamColor = vex::color::red;
  //task info(info);
   chassis.set_drive_constants(12, 0.5, 0.005, 4, 20);
   chassis.set_heading_constants(12, 0.25, 0.007, 5, 20);
   chassis.turn_to_angle(47);
   //---------------------------------------------------------------------
   chassis.set_drive_constants(12, 1.2, 0.005, 6, 20);
   chassis.set_heading_constants(12, 1.2, 0.007, 6, 20);
   chassis.drive_distance(-24.5,70,12,12);
   chassis.set_drive_constants(12, 1, 0.005, 6, 5);
   chassis.set_heading_constants(12, 1, 0.007, 6, 5);
   chassis.drive_distance(-10,70,5,5);
   intakeCylander = true;
   wait(0.4,sec);
   //-----------------------------------------------------------------
   chassis.set_drive_constants(12, 1, 0.005, 5, 20);
   chassis.set_heading_constants(12, 1, 0.005, 5, 20);
   chassis.turn_to_angle(180);
   //----------------------------------------------------------------
   intake.spin(forward,12,volt);
   intakedown.spin(reverse,12,volt);
   chassis.drive_distance(20,180,8,8);
   wait(0.2,sec);
   chassis.drive_distance(-17.5,180,8,8);
   wait(0.2,sec);
   chassis.turn_to_angle(225);
   chassis.set_drive_constants(4, 1, 0.005, 5, 20);
   chassis.set_heading_constants(4, 1, 0.005, 5, 20);
   chassis.drive_distance(13,225,4,4);
   wait(0.3,sec);
   chassis.set_drive_constants(12, 1, 0.005, 5, 20);
   chassis.set_heading_constants(12, 1, 0.005, 5, 20);
   chassis.turn_to_angle(195);
   chassis.set_drive_constants(12, 1.2, 0.005, 5, 20);
   chassis.set_heading_constants(12, 1.2, 0.005, 5, 20);
   chassis.drive_distance(6,195,12,12);
   //--------------eat 2 red----------------
   chassis.set_drive_constants(12, 1.4, 0.005, 5, 35);
   chassis.set_heading_constants(12, 1.4, 0.005, 5, 35);
   chassis.drive_distance(-25,215,12,12);
   chassis.turn_to_angle(38);
   intake.spin(forward,12,volt);
   chassis.drive_distance(8,38,10,10);
   chassis.drive_with_voltage(1.5,1.5);
   //--------------------- 排除藍色--------------------------------
bool hasnote = false; 
while (!hasnote) {
  if (Optical.isNearObject()) {
    
    intake.spin(forward,12,volt);
    pushCylinder = 1 ;
    wait(0.5, sec); 
    hasnote = true;
  }
  wait(10, msec); 
}
chassis.drive_distance(5,38,10,10);
pushCylinder = 0 ;
wait(0.5,sec);
chassis.drive_distance(-18,38,12,12);
chassis.drive_distance(-28,135,12,12);
intake.stop(brake);
intakedown.stop(brake);

}
//------------------------------------------------------
void BW_left()
{
  vex::color selectedTeamColor = vex::color::blue;
  //task info(info);
   chassis.set_drive_constants(10, .5, 0.005, 4, 20);
   chassis.set_heading_constants(10, .25, 0.007, 5, 20);
   chassis.turn_to_angle(47.5);
  //--------------------------------------------------------
   chassis.set_drive_constants(12, 2.0, 0.005, 5, 5);
   chassis.set_heading_constants(12, 1.5, 0.005, 5, 10); 
   chassis.drive_distance(3,47.5,10,10);
  //----------------------------------------------------------------------
   
   hang1.spinToPosition(-260,degrees,50,rpm,true);
   chassis.drive_distance(-3,45,10,10);//微退一點
   //---------------------------------------------------------------------
   chassis.set_drive_constants(12, 1.2, 0.005, 6, 20);
   chassis.set_heading_constants(12, 1.2, 0.007, 6, 20);
   chassis.drive_distance(-22.5,70,12,12);
   hang1.spin(forward,12,volt);
   hang2.spin(forward,12,volt);
   chassis.set_drive_constants(12, 1, 0.005, 6, 5);
   chassis.set_heading_constants(12, 1, 0.007, 6, 5);
   chassis.drive_distance(-10,70,5,5);
   intakeCylander = true;
   hang1.stop(coast);
   hang2.stop(coast);
   wait(0.4,sec);
   //-----------------------------------------------------------------
   chassis.set_drive_constants(12, 1, 0.005, 5, 20);
   chassis.set_heading_constants(12, 1, 0.005, 5, 20);
   chassis.turn_to_angle(180);
   //----------------------------------------------------------------
   intake.spin(forward,12,volt);
   intakedown.spin(reverse,12,volt);
   chassis.drive_distance(18,180,8,8);
   chassis.turn_to_angle(23);
   //------next--------------------------------
   chassis.set_drive_constants(12, 1.2, 0.005, 6, 20);
   chassis.set_heading_constants(12, 1.2, 0.007, 6, 20);
   chassis.drive_distance(36,23,12,12);
   chassis.set_drive_constants(12, 1, 0.005, 6, 5);
   chassis.set_heading_constants(12, 1, 0.007, 6, 5);
   chassis.drive_distance(10,23,5,5);
   chassis.drive_with_voltage(1.5,1.5);
   //--------------------- 排除--------------------------------
bool hasnote = false; 
while (!hasnote) {
  if (Optical.isNearObject()) {
    
    intake.spin(forward,12,volt);
    pushCylinder = 1 ;
    wait(0.5, sec); 
    hasnote = true;
  }
  wait(10, msec); 
}
chassis.drive_distance(8,20,10,10);
pushCylinder = 0 ;
chassis.drive_distance(-34,20,12,12); 
chassis.turn_to_angle(135) ;
intakedown.stop(brake);
chassis.drive_distance(-25,135,12,12);
intake.stop(brake);
hang1.stop(brake);
hang2.stop(brake);
}
//--------------------------------------------------------------
void B3_left()
{
  vex::color selectedTeamColor = vex::color::blue;
  //task info(info);
   chassis.set_drive_constants(12, .5, 0.005, 4, 20);
   chassis.set_heading_constants(12, .25, 0.007, 5, 20);
   chassis.turn_to_angle(47);
  //--------------------------------------------------------
   chassis.set_drive_constants(12, 1.2, 0.005, 6, 20);
   chassis.set_heading_constants(12, 1.2, 0.007, 6, 20);
   chassis.drive_distance(-22.5,70,12,12);
   chassis.set_drive_constants(12, 1, 0.005, 6, 5);
   chassis.set_heading_constants(12, 1, 0.007, 6, 5);
   chassis.drive_distance(-10,70,5,5);
   intakeCylander = true;
   wait(1,sec);
   //-----------------------------------------------------------------
   chassis.set_drive_constants(12, 1, 0.005, 5, 20);
   chassis.set_heading_constants(12, 1, 0.005, 5, 20);
   chassis.turn_to_angle(180);
   //----------------------------------------------------------------
   intake.spin(forward,12,volt);
   intakedown.spin(reverse,12,volt);
   chassis.drive_distance(18,180,8,8);
   chassis.turn_to_angle(23);
   //------next--------------------------------
   chassis.set_drive_constants(12, 1.2, 0.005, 6, 20);
   chassis.set_heading_constants(12, 1.2, 0.007, 6, 20);
   chassis.drive_distance(36,23,12,12);
   chassis.set_drive_constants(12, 1, 0.005, 6, 5);
   chassis.set_heading_constants(12, 1, 0.007, 6, 5);
   chassis.drive_distance(10,23,5,5);
   chassis.drive_with_voltage(1.5,1.5);
   //--------------------- 排除--------------------------------
bool hasnote = false; 
while (!hasnote) {
  if (Optical.isNearObject()) {
    
    intake.spin(forward,12,volt);
    pushCylinder = 1 ;
    wait(0.5, sec); 
    hasnote = true;
  }
  wait(10, msec); 
}
chassis.drive_distance(8,20,10,10);
pushCylinder = 0 ;
chassis.drive_distance(-27,20,12,12); 
chassis.turn_to_angle(135) ;
intakedown.stop(brake);
chassis.drive_distance(-26,135,12,12);
intake.stop(brake);
hang1.stop(brake);
hang2.stop(brake);
}
//--------------------------------------------------------------

void BW_right(){
   vex::color selectedTeamColor = vex::color::blue;
  //task info(info);
   chassis.set_drive_constants(10, .5, 0.005, 4, 20);
   chassis.set_heading_constants(10, .25, 0.007, 5, 20);
   chassis.turn_to_angle(316);
  //--------------------------------------------------------
   chassis.set_drive_constants(12, 2.0, 0.005, 5, 5);
   chassis.set_heading_constants(12, 1.5, 0.005, 5, 10); 
   chassis.drive_distance(3,316,10,10);
  //----------------------------------------------------------------------
   hang1.spin(reverse,12,volt);
   hang1.spinToPosition(-260,degrees,50,rpm,true);
   chassis.drive_distance(-3,315,10,10);//微退一點
   //---------------------------------------------------------------------
   chassis.set_drive_constants(12, 1.2, 0.005, 6, 20);
   chassis.set_heading_constants(12, 1.2, 0.007, 6, 20);
   chassis.drive_distance(-24.5,290,12,12);
   hang1.spin(forward,12,volt);
   hang2.spin(forward,12,volt);
   chassis.set_drive_constants(12, 1, 0.005, 6, 5);
   chassis.set_heading_constants(12, 1, 0.007, 6, 5);
   chassis.drive_distance(-10,290,5,5);
   intakeCylander = true;
   hang1.stop(coast);
   hang2.stop(coast);
   wait(0.4,sec);
   //-----------------------------------------------------------------
   chassis.set_drive_constants(12, 1, 0.005, 5, 20);
   chassis.set_heading_constants(12, 1, 0.005, 5, 20);
   chassis.turn_to_angle(180);
   //----------------------------------------------------------------
   intake.spin(forward,12,volt);
   intakedown.spin(reverse,12,volt);
   chassis.drive_distance(20,180,8,8);
   wait(0.2,sec);
   chassis.drive_distance(-19.5,180,8,8);
   wait(0.2,sec);
   chassis.turn_to_angle(135);
   chassis.set_drive_constants(4, 1, 0.005, 5, 20);
   chassis.set_heading_constants(4, 1, 0.005, 5, 20);
   chassis.drive_distance(14,135,4,4);
   wait(0.3,sec);
   chassis.set_drive_constants(12, 1, 0.005, 5, 20);
   chassis.set_heading_constants(12, 1, 0.005, 5, 20);
   chassis.turn_to_angle(165);
   chassis.set_drive_constants(12, 1.2, 0.005, 5, 20);
   chassis.set_heading_constants(12, 1.2, 0.005, 5, 20);
   chassis.drive_distance(6,165,12,12);
   //--------------eat 2 red----------------
   chassis.set_drive_constants(12, 1.4, 0.005, 5, 35);
   chassis.set_heading_constants(12, 1.4, 0.005, 5, 35);
   chassis.drive_distance(-20,145,12,12);
   chassis.turn_to_angle(322);
   intake.spin(forward,12,volt);
   chassis.drive_distance(9,322,10,10);
   chassis.drive_with_voltage(1.5,1.5);
   //--------------------- 排除藍色--------------------------------
bool hasnote = false; 
while (!hasnote) {
  if (Optical.isNearObject()) {
    
    intake.spin(forward,12,volt);
    pushCylinder = 1 ;
    wait(0.5, sec); 
    hasnote = true;
  }
  wait(10, msec); 
}
chassis.drive_distance(5,322,12,12);
pushCylinder = 0 ;
chassis.drive_distance(-18,322,12,12);
chassis.drive_distance(-28,225,12,12);
intake.stop(brake);
intakedown.stop(brake);
}
 //--------------------------------------------------------------
void B5_right(){
 vex::color selectedTeamColor = vex::color::blue;
  //task info(info);
   chassis.set_drive_constants(12, .5, 0.005, 4, 20);
   chassis.set_heading_constants(12, .25, 0.007, 5, 20);
   chassis.turn_to_angle(313);
   //---------------------------------------------------------------------
   chassis.set_drive_constants(12, 1.2, 0.005, 6, 20);
   chassis.set_heading_constants(12, 1.2, 0.007, 6, 20);
   chassis.drive_distance(-24.5,290,12,12);
   chassis.set_drive_constants(12, 1, 0.005, 6, 5);
   chassis.set_heading_constants(12, 1, 0.007, 6, 5);
   chassis.drive_distance(-10,290,5,5);
   intakeCylander = true;
   wait(0.4,sec);
   //-----------------------------------------------------------------
   chassis.set_drive_constants(12, 1, 0.005, 5, 20);
   chassis.set_heading_constants(12, 1, 0.005, 5, 20);
   chassis.turn_to_angle(180);
   //----------------------------------------------------------------
   intake.spin(forward,12,volt);
   intakedown.spin(reverse,12,volt);
   chassis.drive_distance(20,180,8,8);
   wait(0.2,sec);
   chassis.drive_distance(-19.5,180,8,8);
   wait(0.2,sec);
   chassis.turn_to_angle(135);
   chassis.set_drive_constants(4, 1, 0.005, 5, 20);
   chassis.set_heading_constants(4, 1, 0.005, 5, 20);
   chassis.drive_distance(14,135,4,4);
   wait(0.3,sec);
   chassis.set_drive_constants(12, 1, 0.005, 5, 20);
   chassis.set_heading_constants(12, 1, 0.005, 5, 20);
   chassis.turn_to_angle(165);
   chassis.set_drive_constants(12, 1.2, 0.005, 5, 20);
   chassis.set_heading_constants(12, 1.2, 0.005, 5, 20);
   chassis.drive_distance(6,165,12,12);
   //--------------eat 2 red----------------
   chassis.set_drive_constants(12, 1.4, 0.005, 5, 35);
   chassis.set_heading_constants(12, 1.4, 0.005, 5, 35);
   chassis.drive_distance(-20,145,12,12);
   chassis.turn_to_angle(322);
   intake.spin(forward,12,volt);
   chassis.drive_distance(9,322,10,10);
   chassis.drive_with_voltage(1.5,1.5);
   //--------------------- 排除藍色--------------------------------
bool hasnote = false; 
while (!hasnote) {
  if (Optical.isNearObject()) {
    
    intake.spin(forward,12,volt);
    pushCylinder = 1 ;
    wait(0.5, sec); 
    hasnote = true;
  }
  wait(10, msec); 
}
chassis.drive_distance(5,322,12,12);
pushCylinder = 0 ;
chassis.drive_distance(-18,322,12,12);
chassis.drive_distance(-28,225,12,12);
intake.stop(brake);
intakedown.stop(brake);
}
 //--------------------------------------------------------------


void skills(){
   
  //--------------------------------------------------------
   chassis.set_drive_constants(12, 2.0, 0.005, 5, 5);
   chassis.set_heading_constants(12, 1.5, 0.005, 5, 10); 
   chassis.drive_distance(20,270,12,12);//微退一點
   /*/-----------------------------------------------
   chassis.set_drive_constants(12, 0.8, 0.005, 5, 5);
   chassis.set_heading_constants(12, 0.8, 0.005, 5, 10); 
   chassis.turn_to_angle(90);
   /
   //---------------------------------------------------------------------
   chassis.set_drive_constants(5, 1.2, 0.005, 6, 20);
   chassis.set_heading_constants(5, 1.2, 0.007, 6, 20);
   chassis.drive_distance(-20,90,5,5);
   intakeCylander = true;
   wait(0.3,sec);
   chassis.turn_to_angle(225);
   //-----------------------------------------------------------
   chassis.set_drive_constants(12, 2.0, 0.005, 5, 5);
   chassis.set_heading_constants(12, 1.5, 0.005, 5, 10); 
   intake.spin(forward,12,volt);
   intakedown.spin(reverse,12,volt);
   chassis.drive_distance(35,225,12,12);
   chassis.turn_to_angle(180);
   chassis.set_drive_constants(6.5, 1.2, 0.005, 6, 20);
   chassis.set_heading_constants(6.5, 1.2, 0.007, 6, 20);
   intake.stop(coast);
   chassis.drive_distance(18,180,6.5,6.5);
   // -------------------------------------
            hang1.spin(forward, 12, volt);
            wait(0.4,sec);
            hang1.setMaxTorque(20,percent);
            hang1.spin(forward, 5, volt);
            wait(0.4,sec);
            hang1.resetPosition() ;
            wait(0.1,sec);
            hang1.setMaxTorque(100,percent);
            hang1.spinToPosition(-58, degrees, 35, rpm, true);
  chassis.turn_to_angle(270);
  intake.spin(forward,12,volt);
  intakedown.stop(coast);
  chassis.drive_distance(12,270,12,12);
*/

}

void odom_test()
{
  
}

void PIDtest() {
 
}




void default_constants()
{
  chassis.set_drive_constants(12, .5, 0.004, 5, 20);
  chassis.set_heading_constants(12, .25, 0.007, 5, 40);
  chassis.set_turn_constants(12, .35, .001, 3, 90);
  chassis.set_swing_constants(12, .5, .001, 2, 15);
  chassis.set_drive_exit_conditions(.5, 0, 2000);
  chassis.set_turn_exit_conditions(4, 0, 3000);
  chassis.set_swing_exit_conditions(10, 0, 3000);
}

void odom_constants()
{
  default_constants();
  chassis.drive_max_voltage = 12;
  chassis.drive_settle_error = 3;
}

void drive_test()
{
  chassis.turn_to_angle(45);
  chassis.drive_distance(30);
  chassis.turn_to_angle(270);
  chassis.drive_distance(20);
  chassis.turn_to_angle(135);
  chassis.drive_distance(30);
  chassis.turn_to_angle(270);
  chassis.drive_distance(20);
  chassis.turn_to_angle(0);
}

void turn_test()
{
  chassis.turn_to_angle(5);
  chassis.turn_to_angle(30);
  chassis.turn_to_angle(90);
  chassis.turn_to_angle(225);
  chassis.turn_to_angle(0);
}

void swing_test()
{
  chassis.left_swing_to_angle(90);
  chassis.right_swing_to_angle(0);
}

void full_test()
{
  chassis.drive_distance(24);
  chassis.turn_to_angle(-45);
  chassis.drive_distance(-36);
  chassis.right_swing_to_angle(-90);
  chassis.drive_distance(24);
  chassis.turn_to_angle(0);
}

void tank_odom_test()
{
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.turn_to_point(24, 24);
  chassis.drive_to_point(24, 24);
  chassis.drive_to_point(0, 0);
  chassis.turn_to_angle(0);
}

void holonomic_odom_test()
{
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.holonomic_drive_to_point(0, 18, 90);
  chassis.holonomic_drive_to_point(18, 0, 180);
  chassis.holonomic_drive_to_point(0, 18, 270);
  chassis.holonomic_drive_to_point(0, 0, 0);
}
