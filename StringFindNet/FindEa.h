#pragma once

#include<vcclr.h>
#include <bytes.hpp>
#include <ida.hpp>
#include <idp.hpp>
#include <loader.hpp>

using namespace System;

public ref class FindEa
{
public:
	String ^ Text;
	String ^ TextLen;
	ea_t Address;
	Boolean IsRef;
	String ^CodeHex;

public: virtual String^  ToString(void) override
	{
			 return "0x" + Convert::ToString((int)Address, 16) + "\t" + TextLen + "\t" + Text + "\t" + CodeHex + "\tRef:" + (IsRef==true?"ÊÇ":"·ñ");

	}
	
public:
	FindEa();


};
