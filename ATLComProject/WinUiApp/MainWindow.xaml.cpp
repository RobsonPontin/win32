#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

#include <atlbase.h>
#include <atlcom.h>

using namespace winrt;
using namespace Microsoft::UI::Xaml;


namespace winrt::WinUiApp::implementation
{
    /* COM interface definitions from ATLComProject. */
    MIDL_INTERFACE("835ff4ef-aa54-4be6-9464-a4979891bce8")
        IATLSimpleObject : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Start(void) = 0;
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Stop(void) = 0;
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FavoriteNumber(
            /* [retval][out] */ long* favNumber) = 0;
    };

    class DECLSPEC_UUID("78dfdea1-1ccf-4c14-b149-b6a5b04c835e")
        ATLSimpleObject;

    winrt::Windows::Foundation::IAsyncAction MainWindow::btnComCallInprocServer32_Click(IInspectable const&, RoutedEventArgs const&)
    {
        CComPtr<IATLSimpleObject> atlSimpleObject;
        HRESULT hr = atlSimpleObject.CoCreateInstance(__uuidof(ATLSimpleObject));
        if (SUCCEEDED(hr))
        {
            hstring strDialogContent = L"";
            long favNumber;

            auto result = atlSimpleObject->get_FavoriteNumber(&favNumber);
            if (result == S_OK)
            {
                m_favNumberFromCom = static_cast<double>(favNumber);

                strDialogContent = L"My Favorite number is: " + winrt::to_hstring(m_favNumberFromCom);
            }
            else
            {
                strDialogContent = L"COM call failed.";
            }

            winrt::Microsoft::UI::Xaml::Controls::ContentDialog dialog;
            dialog.PrimaryButtonText(L"Ok");
            dialog.Title(winrt::box_value(L"COM Result"));
            dialog.Content(winrt::box_value(strDialogContent));
            dialog.XamlRoot(this->Content().XamlRoot());

            co_await dialog.ShowAsync();
        }
    }

    /* COM interface definitions from ATLComProjectExe. */
    MIDL_INTERFACE("71e73e98-121c-4f56-ab54-46124a746c02")
        IATLSimpleObjectExe : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FavoriteNumber(
            /* [retval][out] */ long* favNumber) = 0;

    };

    class DECLSPEC_UUID("a75eccf5-4cab-4726-9136-06129c42f144")
        ATLSimpleObjectExe;

    winrt::Windows::Foundation::IAsyncAction winrt::WinUiApp::implementation::MainWindow::btnComCallLocalServer32_Click(IInspectable const&, RoutedEventArgs const&)
    {
        CComPtr<IATLSimpleObjectExe> atlSimpleObjectExe;
        HRESULT hr = atlSimpleObjectExe.CoCreateInstance(__uuidof(ATLSimpleObjectExe));
        if (SUCCEEDED(hr))
        {
            hstring strDialogContent = L"";
            long favNumber;

            auto result = atlSimpleObjectExe->get_FavoriteNumber(&favNumber);
            if (result == S_OK)
            {
                m_favNumberFromCom = static_cast<double>(favNumber);

                strDialogContent = L"My Favorite number is: " + winrt::to_hstring(m_favNumberFromCom);
            }
            else
            {
                strDialogContent = L"COM call failed.";
            }

            winrt::Microsoft::UI::Xaml::Controls::ContentDialog dialog;
            dialog.PrimaryButtonText(L"Ok");
            dialog.Title(winrt::box_value(L"COM Result"));
            dialog.Content(winrt::box_value(strDialogContent));
            dialog.XamlRoot(this->Content().XamlRoot());

            co_await dialog.ShowAsync();
        }
    }
}
