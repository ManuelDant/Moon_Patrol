
set solution_dir=%~1
set config=%~2
set target_dir=%~3

CD %target_dir%
MKDIR res

CD res

MKDIR textures

XCOPY /e /v /y "%solution_dir%Moon_Patrol_EnzoColetta\res\textures\"  "%target_dir%res\textures"
