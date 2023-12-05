#pragma once

#include "MainWindow.g.h"

namespace winrt::WinUiApp::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

        double FavoriteNumber()
        {
            return m_favNumberFromCom;
        }

        winrt::Windows::Foundation::IAsyncAction myButton_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);

    private:
        double m_favNumberFromCom{ 0.0 };
    };
}

namespace winrt::WinUiApp::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
