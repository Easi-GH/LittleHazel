-- premake5.lua
workspace "LittleHazel"
	architecture "x64"
	configurations {
		"Debug",
		"Release",
		"Dist" 
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "LittleHazel"
	location"LittleHazel"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin_int/" .. outputdir .. "/%{prj.name}")

	files { 
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/src"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"LH_PLATFORM_WINDOWS",
			"LH_BUILD_DLL"
		}

		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "LH_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "LH_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "LH_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin_int/" .. outputdir .. "/%{prj.name}")

	files { 
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"LittleHazel/vendor/spdlog/include",
		"LittleHazel/src"
	}

	links {
		"LittleHazel"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"LH_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "LH_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "LH_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "LH_DIST"
		optimize "On"