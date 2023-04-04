#pragma once
#include <cstdint>
#include <cstddef>

namespace globals
{
	inline std::uintptr_t clientAddress = 0;

	inline bool glow = false;
	inline float glowColor[] = { 1.f, 0.f, 0.f, 1.f };

	inline bool radar = false;

	inline bool bhop = false;
}

namespace offsets
{
	constexpr ::std::ptrdiff_t dwLocalPlayer = 0xDEA964;
	constexpr ::std::ptrdiff_t dwGlowObjectManager = 0x535AA70;
	constexpr ::std::ptrdiff_t dwEntityList = 0x4DFFFC4;
	constexpr ::std::ptrdiff_t dwForceJump = 0x52BBD50;

	constexpr ::std::ptrdiff_t m_iTeamNum = 0xF4;
	constexpr ::std::ptrdiff_t m_lifeState = 0x25F;
	constexpr ::std::ptrdiff_t m_iGlowIndex = 0x10488;
	constexpr ::std::ptrdiff_t m_bSpotted = 0x93D;
	constexpr ::std::ptrdiff_t m_fFlags = 0x104;
}