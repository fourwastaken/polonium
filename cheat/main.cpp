#include "gui.h"
#include "hacks.h"
#include "globals.h"

#include <thread>

int __stdcall wWinMain(
	HINSTANCE instance,
	HINSTANCE previousInstance,
	PWSTR arguments,
	int commandShow)
{
	Memory mem{ "csgo.exe" };

	globals::clientAddress = mem.GetModuleAddress("client.dll");
	globals::engineAddress = mem.GetModuleAddress("engine.dll");

	std::thread(hacks::ESPThread, mem).detach();
	std::thread(hacks::RadarThread, mem).detach();
	std::thread(hacks::BHopThread, mem).detach();
	std::thread(hacks::AimbotThread, mem).detach();
	std::thread(hacks::RecoilThread, mem).detach();

	// create gui
	gui::CreateHWindow("Polonium Cheat v0.3");
	gui::CreateDevice();
	gui::CreateImGui();

	while (gui::isRunning)
	{
		gui::BeginRender();
		gui::Render();
		gui::EndRender();

		std::this_thread::sleep_for(std::chrono::milliseconds(5));
	}

	// destroy gui
	gui::DestroyImGui();
	gui::DestroyDevice();
	gui::DestroyHWindow();

	return EXIT_SUCCESS;
}
