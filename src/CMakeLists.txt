cmake_minimum_required(VERSION 3.16)

project(queenss VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appqueenss
    main.cpp
)

set_source_files_properties(Colors.qml PROPERTIES QT_QML_SINGLETON_TYPE TRUE)

qt_add_qml_module(appqueenss
    URI queenss
    QML_FILES
        Main.qml
        RESOURCES
        QML_FILES ApplicationFlow.qml
        QML_FILES ApplicationFlowForm.ui.qml
        QML_FILES Colors.qml
        QML_FILES CustomToolBar.qml
        QML_FILES CustomToolBarForm.ui.qml
        RESOURCES
        QML_FILES
        QML_FILES Home.qml
        QML_FILES HomeForm.ui.qml
        QML_FILES CustomButton.qml
        QML_FILES CustomButtonForm.ui.qml
        RESOURCES
        RESOURCES Resources/images/icons/light_mode_black_24dp.svg
        RESOURCES Resources/images/icons/keyboard_backspace_white_right.svg
        RESOURCES Resources/images/icons/keyboard_backspace_white_left.svg
        RESOURCES Resources/images/icons/keyboard_backspace_black_right.svg
        RESOURCES Resources/images/icons/keyboard_backspace_black_left.svg
        RESOURCES Resources/images/icons/keyboard_backspace_black.svg
        RESOURCES Resources/images/icons/dark_mode_black_24dp.svg
        RESOURCES Resources/images/boards/home.png Resources/images/boards/rule1.png Resources/images/boards/rule2.png Resources/images/boards/rule3.png Resources/images/boards/rule4.png
        RESOURCES Resources/images/icons/logo.png
        QML_FILES HowToPlay.qml
        QML_FILES HowToPlayForm.ui.qml
        QML_FILES InputScreen.qml
        QML_FILES InputScreenForm.ui.qml
        QML_FILES SolvingScreen.qml
        QML_FILES ResultsScreen.qml
        QML_FILES ResultsScreenForm.ui.qml
        QML_FILES SolvingScreenForm.ui.qml
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appqueenss PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appqueenss
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appqueenss
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appqueenss
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
