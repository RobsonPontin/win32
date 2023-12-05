// dllmain.h : Declaration of module class.

class CATLComProjectModule : public ATL::CAtlDllModuleT< CATLComProjectModule >
{
public :
	DECLARE_LIBID(LIBID_ATLComProjectLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_ATLCOMPROJECT, "{fb3fad2b-ee4b-4599-a2a2-fda2df2ac390}")
};

extern class CATLComProjectModule _AtlModule;
