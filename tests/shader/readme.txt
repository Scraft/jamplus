This is an example of how a shader compiler can be hooked up into JamPlus in such a way that it could compile
a shader file into a header file, and then have the header file included into the source files.

JamPlus will know whether it needs to recompile the shaders and generate new headers based on if there is a
change to the the hlsl files, or any files included by the hlsl files. It will also know it needs to compile
and generate the headers if the headers are currently missing.

For the sake of making a 'complete' sample, the project is setup as three components in the Source directory:

App		- builds the application, links against the 'Lib' project, and also relies on 'Shaders'
Lib		- builds a static library, relies on 'Shaders'
Shaders		- Phony target, has information about building the shaders, these will only get compiled
		  when required though (by App/Lib #including a file generated from the shaders).

There is also the GenerateWorkSpaceVs2005.bat file provided to generate a VS2005 workspace.