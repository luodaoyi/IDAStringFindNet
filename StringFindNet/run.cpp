#include <ida.hpp>
#include <idp.hpp>
#include <loader.hpp>
#include "FindStr.h"

/*
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
*/

struct plugin_ctx_t : public plugmod_t
{
	virtual bool idaapi run(size_t arg) override;
};

//--------------------------------------------------------------------------
static plugmod_t* idaapi init()
{
	return new plugin_ctx_t;
}

bool idaapi plugin_ctx_t::run(size_t)
{
	StringFindNet::FindStr^ win = gcnew StringFindNet::FindStr();
	win->Show();
	return true;  
}


char IDAP_comment[] = "字符串查找工具 VC.NET版";
char IDAP_help[] = "输入Ctrl+Y 启动查找";
char IDAP_name[] = "StringFind.NET";
char IDAP_hotkey[] = "Ctrl-y";

plugin_t PLUGIN =
{
	IDP_INTERFACE_VERSION,
	0,
	init,
	nullptr,
	nullptr,
	IDAP_comment,
	IDAP_help,
	IDAP_name,
	IDAP_hotkey

};