/**
 * =============================================================================
 * NIFLHEIMR.DEV (EQUILIBRIUM) XTOOLS CLDLL
 * Copyright (C) 2018 - 2024 .knHz, Astarion.
 * Special thanks : 
 * All rights reserved.
 * =============================================================================
 **/
#pragma once

#ifndef _CLDLL_L4DINTERFACES_H_
#define _CLDLL_L4DINTERFACES_H_

class IFace
{
public:
	IFace() noexcept
	{
		/* exemple */
		_cvar			= GetInterface<ICvar>("vstdlib.dll", CVAR_INTERFACE_VERSION); // VEngineCvar007
	}

	~IFace() noexcept
	{
	}

	bool CheckIfaces() noexcept
	{
		if (!_cvar)
			return false;

		return true;
	}

	/**
	 * Get Interface Function
	 **/
	template <class Type>
	Type* GetInterface(const char* library, const char* name)
	{
		const auto handle = GetModuleHandleA(library);

		if (!handle)
			return nullptr;

		const auto functionAddress = GetProcAddress(handle, "CreateInterface");

		if(!functionAddress)
			return nullptr;

		using Fn = Type* (*)(const char*, int*);
		const auto FnCreateInterface = reinterpret_cast<Fn>(functionAddress);

		return FnCreateInterface(name, nullptr);
	}
	/**
	 * Get clinet mode
	 **/
	IClientMode* GetClientMode(void)
	{
		const auto functionAddress = /* Your utils findpattern -> cl.dll (sig, mask) */
		
		if (!functionAddress)
			return nullptr;

		using Fn = IClientMode* (*)();
		const auto ClientMode = reinterpret_cast<Fn>(functionAddress);

		return ClientMode();
	}
private:
	ICvar*			_cvar = nullptr;
};
#endif /* !_CLDLL_L4DINTERFACES_H_ */
