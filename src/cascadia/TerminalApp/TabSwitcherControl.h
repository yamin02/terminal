// Copyright (c) Microsoft Corporation.
// Licensed under the MIT license.

#pragma once

#include "winrt/Microsoft.UI.Xaml.Controls.h"
#include "winrt/Windows.UI.Xaml.Interop.h"

#include "TabSwitcherControl.g.h"
#include "../../cascadia/inc/cppwinrt_utils.h"

namespace winrt::TerminalApp::implementation
{
    struct TabSwitcherControl : TabSwitcherControlT<TabSwitcherControl>
    {
        TabSwitcherControl();

        //Windows::Foundation::Collections::IObservableVector<TerminalApp::Tab> FilteredActions();
        //void SetActions(Windows::Foundation::Collections::IVector<TerminalApp::Tab> const& actions);
        void ToggleVisibility();

        // TabSource dependency property
        winrt::Windows::Foundation::Collections::IObservableVector<TerminalApp::Tab> TabSource()
        {
            return winrt::unbox_value<winrt::Windows::Foundation::Collections::IObservableVector<TerminalApp::Tab>>(GetValue(_TabSourceProperty));
        }

        void TabSource(winrt::Windows::Foundation::Collections::IObservableVector<TerminalApp::Tab> const& value)
        {
            SetValue(_TabSourceProperty, winrt::box_value(value));
        }

        static Windows::UI::Xaml::DependencyProperty TabSourceProperty() { return _TabSourceProperty; }

        static void OnTabSourceChanged(Windows::UI::Xaml::DependencyObject const&, Windows::UI::Xaml::DependencyPropertyChangedEventArgs const&);

        DECLARE_EVENT_WITH_TYPED_EVENT_HANDLER(Closed, _closeHandlers, TerminalApp::TabSwitcherControl, winrt::Windows::UI::Xaml::RoutedEventArgs);

    private:
        friend struct TabSwitcherControlT<TabSwitcherControl>; // for Xaml to bind events

       /* Windows::Foundation::Collections::IObservableVector<TerminalApp::Tab> _filteredActions{ nullptr };
        Windows::Foundation::Collections::IVector<TerminalApp::Tab> _allActions{ nullptr };

        void _filterTextChanged(Windows::Foundation::IInspectable const& sender,
                                Windows::UI::Xaml::RoutedEventArgs const& args);
        void _keyDownHandler(Windows::Foundation::IInspectable const& sender,
                             Windows::UI::Xaml::Input::KeyRoutedEventArgs const& e);

        void _selectNextItem(const bool moveDown);

        void _updateFilteredActions();
        static bool _filterMatchesName(const winrt::hstring& searchText, const winrt::hstring& name);
        static int _getWeight(const winrt::hstring& searchText, const winrt::hstring& name);*/

        void _close();

        static Windows::UI::Xaml::DependencyProperty _TabSourceProperty;
    };
}

namespace winrt::TerminalApp::factory_implementation
{
    struct TabSwitcherControl : TabSwitcherControlT<TabSwitcherControl, implementation::TabSwitcherControl>
    {
    };
}
