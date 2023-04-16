#pragma once
#include "memory.h"

namespace hacks
{
	void ESPThread(const Memory& mem) noexcept;

	void RadarThread(const Memory& mem) noexcept;

	void BHopThread(const Memory& mem) noexcept;

	void AimbotThread(const Memory& mem) noexcept;

	void RecoilThread(const Memory& mem) noexcept;
}