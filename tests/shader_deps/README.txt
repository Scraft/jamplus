shaders_deps
------------

Demonstrates a problem where shaders aren't correctly compiled in conjunction with the C.Lump rule.


reproduction steps
------------------

Create workspace, edit workspace, select 'Build -> Rebuild solution'.


workarounds
-----------

If you select 'Build -> Rebuild solution' a second time, it'll work correctly.


Issolation of problem
---------------------

You can note that it will work correctly if you comment out:

Source\App\Jamfile.jam(15) : C.Lump $(PROJECT_NAME) : SRCS : $(PROJECT_NAME)_Lump.cpp ;
