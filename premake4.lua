solution "mavis"
	configurations { "debug" }
	
	language "C++"
	includedirs { "mavis/include" }
	
	buildoptions "-std=c++11"

	-- remove ldflags to fix broken dead code elimination stuff
	premake.gcc.platforms.x32.ldflags = nil
	premake.gcc.platforms.x64.ldflags = nil
	
	project "mavis"
		kind "SharedLib"
		files { "mavis/source/**.cpp" }
		
	project "mavis-test"
		kind "ConsoleApp"
		files { "test/**.cpp" }
		links { "mavis" }
