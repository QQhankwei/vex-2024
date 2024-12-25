#include "vex.h"
#include "arm.h"
#include "note.h"


extern vex::color selectedTeamColor;
using namespace vex;
competition Competition;

Drive chassis(

    // Specify your drive setup below. There are seven options:
    // ZERO_TRACKER_NO_ODOM, ZERO_TRACKER_ODOM, TANK_ONE_ENCODER, TANK_ONE_ROTATION, TANK_TWO_ENCODER, TANK_TWO_ROTATION, HOLONOMIC_TWO_ENCODER, and HOLONOMIC_TWO_ROTATION
    // For example, if you are not using odometry, put ZERO_TRACKER_NO_ODOM below:
    ZERO_TRACKER_ODOM,

    // Add the names of your Drive motors into the motor groups below, separated by commas, i.e. motor_group(Motor1,Motor2,Motor3).
    // You will input whatever motor names you chose when you configured your robot using the sidebar configurer, they don't have to be "Motor1" and "Motor2".

    // Left Motors:
    

    motor_group(L1, L2, L3),

    // Right Motors:
    motor_group(R1, R2, R3),
    
    // Specify the PORT NUMBER of your inertial sensor, in PORT format (i.e. "PORT1", not simply "1"):
    PORT5,

    // Input your wheel diameter. (4" omnis are actually closer to 4.125"):
    3.25,

    // 外部齒比，必須以小數形式表示，輸入齒數/輸出齒數格式。
    // 若您的馬達有 84 齒的齒輪，輪子有 60 齒的齒輪，此值將為 1.4。
    // 若馬達直接驅動輪子，則此值為 1：
    0.66666,

    // Gyro scale, this is what your gyro reads when you spin the robot 360 degrees.
    // For most cases 360 will do fine here, but this scale factor can be very helpful when precision is necessary.
    360,

    /*---------------------------------------------------------------------------*/
    /*                                  PAUSE!                                   */
    /*                                                                           */
    /*  The rest of the drive constructor is for robots using POSITION TRACKING. */
    /*  If you are not using position tracking, leave the rest of the values as  */
    /*  they are.                                                                */
    /*---------------------------------------------------------------------------*/

    // If you are using ZERO_TRACKER_ODOM, you ONLY need to adjust the FORWARD TRACKER CENTER DISTANCE.

    // FOR HOLONOMIC DRIVES ONLY: Input your drive motors by position. This is only necessary for holonomic drives, otherwise this section can be left alone.
    // LF:      //RF:
    PORT12, -PORT14,

    // LB:      //RB:
    PORT13, -PORT20,

    // If you are using position tracking, this is the Forward Tracker port (the tracker which runs parallel to the direction of the chassis).
    // If this is a rotation sensor, enter it in "PORT1" format, inputting the port below.
    // If this is an encoder, enter the port as an integer. Triport A will be a "1", Triport B will be a "2", etc.
    5,

    // Input the Forward Tracker diameter (reverse it to make the direction switch):
    -3.25,

    // Input Forward Tracker center distance (a positive distance corresponds to a tracker on the right side of the robot, negative is left.)
    // For a zero tracker tank drive with odom, put the positive distance from the center of the robot to the right side of the drive.
    // This distance is in inches:
    5.2,

    // Input the Sideways Tracker Port, following the same steps as the Forward Tracker Port:
    1,

    // Sideways tracker diameter (reverse to make the direction switch):
    -2.75,

    // Sideways tracker center distance (positive distance is behind the center of the robot, negative is in front):
    5.5

);

int current_auton_selection = 0;
bool auto_started = false;
int air = 0;
int temp = 0;
int option = 0;
int hookcnt = 0;
bool airspace = false ; 
bool ran_auton = false; // 是否已经跑auto模式


void cylinderSwitch()
{
  intakeCylander = !intakeCylander;
}
void intakecylanderon(){
  airspace=!airspace;
  intakeCylander = airspace;
}
void intakecylanderoff(){
  intakeCylander = false;
}
void hookSwitch()
{
  if(hookcnt<999) hookCylinder = !hookCylinder;
  hookcnt++;
}
void hang()   // 預留吊掛
{
  pushCylinder = !pushCylinder;
  intake.stop(brake);

}

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  default_constants();
  Inertial.calibrate();
  while (Inertial.isCalibrating()) {
    // 等待慣性測量單元校準完成
     whitelight = 1 ;
     wait(0.05,sec);
     whitelight = 0 ;
     wait(0.05,sec);

  };
  Controller1.Screen.print("ok");
  redlight = 1 ;
  whitelight = 1 ;

  // 定義顏色
  vex::color red = vex::color::red;
  vex::color blue = vex::color::blue;
  vex::color white = vex::color::white;

  // 畫面刷新標記
  int previous_selection = -1;

  // 設定畫布區域
  const int usable_height = 240;   // 螢幕的有效高度
  const int row_height = usable_height / 2;  // 每行的高度
  const int col_width = 480 / 5;             // 每列的寬度

  // 修改紅色區域的高度，讓紅色區域略多
  const int red_height = row_height + 6;  // 調整紅色區域的高度
  const int blue_height = row_height - 6; // 調整藍色區域的高度

  while (!auto_started) { 
    // 每次只更新選擇的格子
    if (current_auton_selection != previous_selection) {
      previous_selection = current_auton_selection;

      for (int i = 0; i < 10; i++) {
        int x = (i % 5) * col_width;        // 計算格子的 x 座標
        int y = (i < 5) ? 0 : red_height;   // 計算格子的 y 座標，前5個為紅色區域，後5個為藍色區域
        vex::color fillColor = (current_auton_selection == i) ? white : (i < 5 ? red : blue);

        // 畫格子背景
        Brain.Screen.setFillColor(fillColor);
        Brain.Screen.drawRectangle(x, y, col_width, (i < 5 ? red_height : blue_height));

        // 畫文字
        Brain.Screen.setFont(vex::fontType::mono20);
        Brain.Screen.setPenColor((current_auton_selection == i) ? red : white);

        if (i == 0) Brain.Screen.printAt(x + 10, y + 60, "RW_right ");
        if (i == 1) Brain.Screen.printAt(x + 10, y + 60, "R3_right ");
        if (i == 2) Brain.Screen.printAt(x + 10, y + 60, "RW_left");
        if (i == 3) Brain.Screen.printAt(x + 10, y + 60, "R5_left");
        if (i == 4) Brain.Screen.printAt(x + 10, y + 60, "skills9");
        if (i == 5) Brain.Screen.printAt(x + 10, y + 60, "BW_left");
        if (i == 6) Brain.Screen.printAt(x + 10, y + 60, "B3_left");
        if (i == 7) Brain.Screen.printAt(x + 10, y + 60, "BW_right");
        if (i == 8) Brain.Screen.printAt(x + 10, y + 60, "B5_right");
        if (i == 9) Brain.Screen.printAt(x + 10, y + 60, "   ");
      }
    }

    // 檢查觸控範圍
    if (Brain.Screen.pressing()) {
      int touchX = Brain.Screen.xPosition();
      int touchY = Brain.Screen.yPosition();

      // 判斷觸控的是哪個格子
      int col = touchX / col_width;   // 每列寬度為 col_width
      int row = (touchY - 0) / row_height;   // 計算行數，從紅色區域開始

      // 更新選擇的格子
      if (row >= 0 && row < 2) {  // 確保觸控在有效範圍內
        current_auton_selection = col + row * 5;
      }

      wait(0.3, sec);  // 防止重複觸發
    }

    wait(20, msec);  // 確保程式執行穩定
  }
}

void autonomous(void) {
  auto_started = true;
  ran_auton = true;
    // 根據選擇的自動任務來決定隊伍顏色
  if (current_auton_selection >= 0 && current_auton_selection <= 4) {
    selectedTeamColor = vex::color::red; // 紅隊
  } else if (current_auton_selection >= 5 && current_auton_selection <= 9) {
    selectedTeamColor = vex::color::blue; // 藍隊
  } else {
    selectedTeamColor = vex::color::black; // 預設為黑隊
  }
  switch (current_auton_selection) {
   
  case 0:
    RW_right();
    break;
  case 1:
    R3_right();
    break;
  case 2:
    RW_left();
    break;
  case 3:
    R5_left();
    break;
  case 4:
    skills();
    break;
  case 5:
    BW_left();
    break;
  case 6:
    B3_left();
    break;
  case 7:
    BW_right();
    break;
  case 8:
    B5_right();
    break;
  case 9:
    holonomic_odom_test();
    break;
  }
  airspace = true; // 确保 airspace 被设置为 true
}

int momogoTask(){
  while (true)
  {
    Optical_go.setLightPower(100,percent);
    if (airspace == 1){
          Vision1.setLedColor(255,0,0);
          Vision2.setLedColor(255,0,0);
    }
    else if (Optical_go.isNearObject()) 
    {
    Vision1.setLedColor(255,255,255);
    Vision2.setLedColor(255,255,255);
    wait(0.1,sec);
    Vision1.setLedColor(0,0,0);
    Vision2.setLedColor(0,0,0);
    wait(0.1,sec);
    }
    else {
    Vision1.setLedColor(0,255,0);
    Vision2.setLedColor(0,255,0);
    }
  
  }
  
}

int intakeControlTask() {
    while (true) {
        // ================================手動控制次優先級===============================

        if (Controller1.ButtonR1.pressing()) 
        {
            intake.spin(forward, 12, volt);
            intakedown.spin(reverse, 12, volt);
        } 
        else if (Controller1.ButtonR2.pressing()) 
        {
            intake.spin(reverse, 12, volt);
            intakedown.spin(forward, 12, volt);
        } 
        // ==================================停止操作=====================================
        else 
        {
            intake.stop(coast);
            intakedown.stop(coast);
        }

        wait(20, msec);  
    }
    return 0;
}

//=======================================================手臂動作============================================================================
// int hangControlTask() {
//     while (true) {

//         // ================================按下 ButtonL1：低速反轉================================================
//         if (Controller1.ButtonL1.pressing()) {
//           hang1.setMaxTorque(100,percent);
//             hang1.spin(reverse, 6, volt);
            
//         }
//         // =================================按下 ButtonA：高速正轉=================================================
//         else if (Controller1.ButtonA.pressing()) {
//             hang1.spin(forward, 6, volt);
//             hang1.resetPosition() ;
//         }
//         else if (Controller1.ButtonX.pressing()) {
//             hang1.spin(forward, 12, volt);
//             wait(0.4,sec);
//             hang1.setMaxTorque(30,percent);
//             hang1.spin(forward, 5, volt);
//             wait(0.3,sec);
//             hang1.stop(hold);
//             hang1.resetPosition() ;
//             wait(0.1,sec);
//             hang1.setMaxTorque(100,percent);
//             hang1.spinToPosition(-50, degrees, 35, rpm, true);
//             Controller1.rumble("...");
//         }
//         // =================================按下 ButtonB：執行特定動作=============================================
//         else if (Controller1.ButtonB.pressing()) {
           

//         // =======================安全檢查：當前位置超過目標位置，避免反轉損壞馬達====================================
        
//             if (hang1.position(degrees) > -50) {
//                 hang1.spinToPosition(-50, degrees, 35, rpm, true);  // 正向調整到目標
                
//             } else {
//                 // 當位置已低於目標，停止馬達以避免無效反轉
//                 hang1.stop(hold);
                
//             }
//         }
//         // =============================沒有按下按鈕：停止馬達並保持位置===========================================
//         else {
//            hang1.setMaxTorque(100,percent);
//             hang1.stop(hold);
//         }

//         // 確保迴圈穩定運行
//         wait(20, msec);
//     }
//     return 0; 
// }



//===========================================================================================================================================
void usercontrol(void)
{
  if (!ran_auton) 
  {
    intakeCylander = 0;  
    airspace = false;  
    hang1.spin(forward, 6, volt);
    wait(0.2,sec);
    hang1.stop(hold);
    wait(0.05,sec);
    hang1.resetPosition();
  
  }
  else 
  {
    intakeCylander = 1;  
    airspace = true;
    hang1.resetPosition();
  }


  task notetask(autonoteTask,0);
  //---------------------------------------------------
  task momogo(momogoTask,0);
  //-----------------------------------------------------
  task intake(intakeControlTask, 0);
  //-----------------------------------------------------
  task hangTask(hangControlTask,0);
  //-----------------------------------------------------
  Controller1.ButtonY.pressed(hookSwitch);
  //-----------------------------------------------------
  Controller1.ButtonL2.pressed(intakecylanderon);
  //-----------------------------------------------------
  Controller1.ButtonUp.pressed(hang); // 吊掛
  //-----------------------------------------------------
  while(1)
  {
    chassis.control_tank(100); //底盤控制
  }   
  wait(20, msec); 
  
}
int main()
{
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true)
  {
    wait(100, msec);
  }
}
