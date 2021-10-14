#pragma once
#include<vcclr.h>
#include <bytes.hpp>
#include <ida.hpp>
#include <idp.hpp>
#include <loader.hpp>


using namespace System;
namespace StringFindNet {
public	ref class FindNext
	{
	public:
		ea_t minEa;
		ea_t maxEa;
		unsigned char* dsc;
		int lengt;

	public:
		Object ^ win;
		array<unsigned char>^ StrBytes;
	public:
		FindNext();
	};

}