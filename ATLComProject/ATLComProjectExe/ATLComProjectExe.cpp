// ATLComProjectExe.cpp : Implementation of WinMain


#include "pch.h"
#include "framework.h"
#include "resource.h"
#include "ATLComProjectExe_i.h"


using namespace ATL;


class CATLComProjectExeModule : public ATL::CAtlExeModuleT< CATLComProjectExeModule >
{
public :
	DECLARE_LIBID(LIBID_ATLComProjectExeLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_ATLCOMPROJECTEXE, "{c4a503dc-3770-4de2-8c69-3f39f7859ca6}")
};

CATLComProjectExeModule _AtlModule;



//
extern "C" int WINAPI _tWinMain(HINSTANCE /*hInstance*/, HINSTANCE /*hPrevInstance*/,
								LPTSTR /*lpCmdLine*/, int nShowCmd)
{
	return _AtlModule.WinMain(nShowCmd);
}

