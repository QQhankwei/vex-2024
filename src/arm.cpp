#include "vex.h"
using namespace vex;

int hangControlTask() {
    while (true) {

        // ================================按下 ButtonL1：低速反轉================================================
        if (Controller1.ButtonL1.pressing()) {
          hang1.setMaxTorque(100,percent);
            hang1.spin(reverse, 6, volt);
            
        }
        // =================================按下 ButtonA：高速正轉=================================================
        else if (Controller1.ButtonA.pressing()) {
            hang1.spin(forward, 6, volt);
            hang1.resetPosition() ;
        }
        else if (Controller1.ButtonX.pressing()) {
            hang1.spin(forward, 12, volt);
            wait(0.4,sec);
            hang1.setMaxTorque(30,percent);
            hang1.spin(forward, 5, volt);
            wait(0.3,sec);
            hang1.stop(hold);
            hang1.resetPosition() ;
            wait(0.1,sec);
            hang1.setMaxTorque(100,percent);
            hang1.spinToPosition(-50, degrees, 35, rpm, true);
            Controller1.rumble("...");
        }
        // =================================按下 ButtonB：執行特定動作=============================================
        else if (Controller1.ButtonB.pressing()) {
           

        // =======================安全檢查：當前位置超過目標位置，避免反轉損壞馬達====================================
        
            if (hang1.position(degrees) > -50) {
                hang1.spinToPosition(-50, degrees, 35, rpm, true);  // 正向調整到目標
                
            } else {
                // 當位置已低於目標，停止馬達以避免無效反轉
                hang1.stop(hold);
                
            }
        }
        // =============================沒有按下按鈕：停止馬達並保持位置===========================================
        else {
           hang1.setMaxTorque(100,percent);
            hang1.stop(hold);
        }

        // 確保迴圈穩定運行
        wait(20, msec);
    }
    return 0; 
}