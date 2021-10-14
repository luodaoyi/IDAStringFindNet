#include <ida.hpp>
#include <idp.hpp>
#include <loader.hpp>
#include "FindStr.h"


int idaapi   IDAP_init(void)
{


	return PLUGIN_KEEP;


}


void idaapi IDAP_term(void)
{
	return;
}


void idaapi  IDAP_run(int arg)
{
	StringFindNet::FindStr ^ win = gcnew StringFindNet::FindStr();
	win->Show();


	return;
}


char IDAP_comment[] = "�ַ������ҹ��� VC.NET��";
char IDAP_help[] = "����Ctrl+Y ��������";
char IDAP_name[] = "StringFind.NET";
char IDAP_hotkey[] = "Ctrl-y";

plugin_t PLUGIN =
{
	IDP_INTERFACE_VERSION,
	0,
	IDAP_init,
	IDAP_term,
	IDAP_run,
	IDAP_comment,
	IDAP_help,
	IDAP_name,
	IDAP_hotkey

};