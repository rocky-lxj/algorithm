@echo off
set num = 0
For /r  . %%i in (*.cpp) do (
set /a num += 1
echo %%i
call echo idx %%num%% ok
ren %%i *.md) 
echo tot%num%oked
pause>nul
