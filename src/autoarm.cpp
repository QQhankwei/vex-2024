#include "vex.h"
using namespace vex;
void autoarm(){
  hang1.setTimeout(2, seconds);                       // 設定 2 秒超時
  hang1.spinToPosition(-280, degrees, 50, rpm, true); // 等待完成或超時
  if (hang1.isSpinning())
  {
    // 如果超時未完成，執行補救邏輯
    hang1.stop(brake);
  }
} 