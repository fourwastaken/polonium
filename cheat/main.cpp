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

	std::thread(hacks::VisualsThread, mem).detach();

	// create gui
	gui::CreateHWindow("Polonium Cheat v0.1");
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
