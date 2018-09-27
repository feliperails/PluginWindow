@echo off
REM This command file lets you add any third party libraries or special configuration
REM parameters to the Visual Studio solution associated to your plugin.
REM You can edit this file.

REM Pre-defined Paths to the third parties libraries used by the Developer Kit
REM Please, do not modify these values

REM Boost
set BOOSTDIR=C:\Program Files\Paradigm\SKUA-GOCAD-18\Toolkits\Boost

REM Qt
set QTDIR=C:\Program Files\Paradigm\SKUA-GOCAD-18\Toolkits\Qt

REM HDF5
set HDF5DIR=C:\Program Files\Paradigm\SKUA-GOCAD-18\Toolkits\HDF5
set INCLUDE=%INCLUDE%;%HDF5DIR%\include
set LIB=%LIB%;%HDF5DIR%\dll

REM XERCES
set XERCESDIR=C:\Program Files\Paradigm\SKUA-GOCAD-18\Toolkits\Xerces
set INCLUDE=%INCLUDE%;%XERCESDIR%\include
set LIB=%LIB%;%XERCESDIR%\lib

REM Paradigm Shared Components
set PDGMSCDIR=C:\Program Files\Paradigm\SKUA-GOCAD-18\Toolkits\PdgmSC
set PATH=%PATH%;%PDGMSCDIR%\bin
set INCLUDE=%INCLUDE%;%PDGMSCDIR%\include
set LIB=%LIB%;%PDGMSCDIR%\lib

REM Qt Plugin Paths
set QT_PLUGIN_PATH=C:\Program Files\Paradigm\SKUA-GOCAD-18\Toolkits\Qt\plugins;C:\Program Files\Paradigm\SKUA-GOCAD-18\Toolkits\PdgmSC\lib\plugins

REM End Pre-defined Paths

REM You can add you own paths to third parties libraries below


