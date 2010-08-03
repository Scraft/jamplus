@ECHO OFF
PUSHD %~dp0
jam --workspace -gen=vs2005 -compiler=vs2005 -config=GenerateWorkSpaceVs2005.config Source/Jamfile.jam Build
if "%ERRORLEVEL%" == "0" (
ECHO %~dp0Build\_workspace.vs2005_\precompiled_header_deps.sln > %~dp0\EditWorkSpaceVs2005.bat
) else (
pause
)
POPD