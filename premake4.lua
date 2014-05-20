solution "mavis"
	configurations { "debug" }
	
	language "C++"
	includedirs { "mavis/include" }
	
	buildoptions "-std=c++11"
	
	project "mavis"
		kind "SharedLib"
		files { "mavis/**.cpp" }
		
	project "mavis-test"
		kind "ConsoleApp"
		files { "test/**.cpp" }
		links { "mavis" }