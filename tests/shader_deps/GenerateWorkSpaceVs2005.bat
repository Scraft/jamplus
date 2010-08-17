@ECHO OFF
PUSHD %~dp0
jam --workspace -gen=vs2005 -compiler=vs2005 Source/App/Jamfile.jam Build
if "%ERRORLEVEL%" == "0" (
ECHO %~dp0Build\_workspace.vs2005_\JamTest.sln > %~dp0\EditWorkSpaceVs2005.bat
)
POPD