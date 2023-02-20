@echo off
:loop
    datamaker.exe > data.in
    std.exe < data.in > std.out
    code.exe < data.in > code.out
    fc std.out code.out
    if not errorlevel 1 goto loop
pause
goto loop