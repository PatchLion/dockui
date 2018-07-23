echo off
::注意，生成的VS工程是32位还是64位，跟Qt库下的qmake版本是多少位的有关
::C:\Qt\Qt5.9.4\5.9.4\msvc2015\bin\qmake.exe -spec win32-msvc -r -tp vc QtFlex.pro   ::生成32位工程
::C:\Qt\Qt5.9.4\5.9.4\msvc2015_64\bin\qmake.exe -spec win32-msvc -r -tp vc QtFlex.pro   ::生成64位工程
cls
qmake.exe -spec win32-msvc -r -tp vc DockUI.pro
pause