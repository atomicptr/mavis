solution "mavis"
    configurations { "debug" }

    language "C++"
    includedirs { "mavis/include" }

    buildoptions { "-std=c++11" }

    -- remove ldflags to fix broken dead code elimination stuff
    premake.gcc.platforms.ldflags = nil

    project "mavis"
        kind "SharedLib"
        files { "mavis/source/**.cpp" }
