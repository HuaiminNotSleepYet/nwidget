cmake_minimum_required(VERSION 3.5)

project(length_calculator VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

set(NWIDGET_SOURCES
    nwidget/abstractbutton.h
    nwidget/abstractitemview.h
    nwidget/abstractscrollarea.h
    nwidget/abstractslider.h
    nwidget/abstractspinbox.h
    nwidget/action.h
    nwidget/boxlayout.h
    nwidget/checkbox.h
    nwidget/combobox.h
    nwidget/commandlinkbutton.h
    nwidget/datetimeedit.h
    nwidget/dial.h
    nwidget/dialogbuttonbox.h
    nwidget/formlayout.h
    nwidget/frame.h
    nwidget/gridlayout.h
    nwidget/groupbox.h
    nwidget/label.h
    nwidget/layout.h
    nwidget/lineedit.h
    nwidget/listview.h
    nwidget/menu.h
    nwidget/menubar.h
    nwidget/object.h
    nwidget/plaintextedit.h
    nwidget/progressbar.h
    nwidget/pushbutton.h
    nwidget/radiobutton.h
    nwidget/scrollbar.h
    nwidget/slider.h
    nwidget/spinbox.h
    nwidget/splitter.h
    nwidget/stackedlayout.h
    nwidget/tabbar.h
    nwidget/tableview.h
    nwidget/tablewidget.h
    nwidget/tabwidget.h
    nwidget/textbrowser.h
    nwidget/textedit.h
    nwidget/toolbox.h
    nwidget/toolbutton.h
    nwidget/treeview.h
    nwidget/widget.h
)

add_executable(length_calculator
    ${NWIDGET_SOURCES}
    units.h
    mainwindow.h mainwindow.cpp
    main.cpp
)

target_link_libraries(length_calculator PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)

include(GNUInstallDirs)
install(TARGETS length_calculator
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
