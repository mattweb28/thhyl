# Microsoft Developer Studio Project File - Name="thhyl" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=thhyl - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "thhyl.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "thhyl.mak" CFG="thhyl - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "thhyl - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "thhyl - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "thhyl - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GR /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_UNICODE" /D "UNICODE" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 shlwapi.lib /nologo /entry:"wWinMainCRTStartup" /subsystem:windows /machine:I386 /OPT:NOWIN98
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "thhyl - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "UNICODE" /D "_UNICODE" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 Shlwapi.lib /nologo /entry:"wWinMainCRTStartup" /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "thhyl - Win32 Release"
# Name "thhyl - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\cfgfile.cpp
# End Source File
# Begin Source File

SOURCE=.\clipboard.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\CommonDlgWZ.cpp
# End Source File
# Begin Source File

SOURCE=.\cpconv.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\DlgAbout.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgBaseWZ.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgComment.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgOption.cpp
# End Source File
# Begin Source File

SOURCE=.\FileListWindow.cpp
# End Source File
# Begin Source File

SOURCE=.\filepath_utils.cpp
# End Source File
# Begin Source File

SOURCE=.\FileStatusWZ.cpp
# End Source File
# Begin Source File

SOURCE=.\global.cpp
# End Source File
# Begin Source File

SOURCE=.\globalxp.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\OSVer.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\Registry.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\RPYAnalyzer.cpp
# End Source File
# Begin Source File

SOURCE=.\RPYAnalyzer_formatter.cpp
# End Source File
# Begin Source File

SOURCE=.\RPYAnalyzer_userblock.cpp
# End Source File
# Begin Source File

SOURCE=.\SaveRawDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\thcommon.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\thdecode1.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\thdecode2.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\thhyl.cpp
# End Source File
# Begin Source File

SOURCE=.\thhyl.rc
# End Source File
# Begin Source File

SOURCE=.\thhylDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\thuserblock.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\WindowGluer.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\cfgfile.h
# End Source File
# Begin Source File

SOURCE=.\clipboard.h
# End Source File
# Begin Source File

SOURCE=.\CommonDlgWZ.h
# End Source File
# Begin Source File

SOURCE=.\cpconv.h
# End Source File
# Begin Source File

SOURCE=.\DlgAbout.h
# End Source File
# Begin Source File

SOURCE=.\DlgBaseWZ.h
# End Source File
# Begin Source File

SOURCE=.\DlgComment.h
# End Source File
# Begin Source File

SOURCE=.\DlgOption.h
# End Source File
# Begin Source File

SOURCE=.\FileListWindow.h
# End Source File
# Begin Source File

SOURCE=.\filepath_utils.h
# End Source File
# Begin Source File

SOURCE=.\FileStatusWZ.h
# End Source File
# Begin Source File

SOURCE=.\global.h
# End Source File
# Begin Source File

SOURCE=.\globalxp.h
# End Source File
# Begin Source File

SOURCE=.\OSVer.h
# End Source File
# Begin Source File

SOURCE=.\Registry.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\RPYAnalyzer.h
# End Source File
# Begin Source File

SOURCE=.\RPYAnalyzer_common.h
# End Source File
# Begin Source File

SOURCE=.\RPYAnalyzer_formatter.h
# End Source File
# Begin Source File

SOURCE=.\RPYAnalyzer_userblock.h
# End Source File
# Begin Source File

SOURCE=.\SaveRawDlg.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\thcommon.h
# End Source File
# Begin Source File

SOURCE=.\thdecode1.h
# End Source File
# Begin Source File

SOURCE=.\thdecode2.h
# End Source File
# Begin Source File

SOURCE=.\thhyl.h
# End Source File
# Begin Source File

SOURCE=.\thhylDlg.h
# End Source File
# Begin Source File

SOURCE=.\thuserblock.h
# End Source File
# Begin Source File

SOURCE=.\WindowGluer.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\manifest.bin
# End Source File
# Begin Source File

SOURCE=.\res\thhyl.ico
# End Source File
# Begin Source File

SOURCE=.\res\thhyl.rc2
# End Source File
# Begin Source File

SOURCE=.\res\thhylrpy.ico
# End Source File
# Begin Source File

SOURCE=.\res\yx.ico
# End Source File
# End Group
# Begin Source File

SOURCE=".\!COMPILE.txt"
# End Source File
# Begin Source File

SOURCE=".\!FILELIST.txt"
# End Source File
# Begin Source File

SOURCE=".\!THANKS.txt"
# End Source File
# Begin Source File

SOURCE=.\res\pldead00.wav
# End Source File
# End Target
# End Project
