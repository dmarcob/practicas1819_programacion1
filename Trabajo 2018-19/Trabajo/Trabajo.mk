##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Trabajo
ConfigurationName      :=Debug
WorkspacePath          :="C:/Users/diego/Documents/Programacion1/Trabajo 2018-19"
ProjectPath            :="C:/Users/diego/Documents/Programacion1/Trabajo 2018-19/Trabajo"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=diego
Date                   :=17/01/2019
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/TDM-GCC-64/bin/g++.exe
SharedObjectLinkerName :=C:/TDM-GCC-64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Trabajo.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/TDM-GCC-64/bin/ar.exe rcu
CXX      := C:/TDM-GCC-64/bin/g++.exe
CC       := C:/TDM-GCC-64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/up_up_Biblioteca_bizi-estacion.cpp$(ObjectSuffix) $(IntermediateDirectory)/Trabajo.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_Biblioteca_ordenes.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_Biblioteca_bizi-usuario.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_Biblioteca_bizi-usos.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/up_up_Biblioteca_bizi-estacion.cpp$(ObjectSuffix): ../../Biblioteca/bizi-estacion.cpp $(IntermediateDirectory)/up_up_Biblioteca_bizi-estacion.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/diego/Documents/Programacion1/Biblioteca/bizi-estacion.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_Biblioteca_bizi-estacion.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_Biblioteca_bizi-estacion.cpp$(DependSuffix): ../../Biblioteca/bizi-estacion.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_Biblioteca_bizi-estacion.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_Biblioteca_bizi-estacion.cpp$(DependSuffix) -MM ../../Biblioteca/bizi-estacion.cpp

$(IntermediateDirectory)/up_up_Biblioteca_bizi-estacion.cpp$(PreprocessSuffix): ../../Biblioteca/bizi-estacion.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_Biblioteca_bizi-estacion.cpp$(PreprocessSuffix) ../../Biblioteca/bizi-estacion.cpp

$(IntermediateDirectory)/Trabajo.cpp$(ObjectSuffix): Trabajo.cpp $(IntermediateDirectory)/Trabajo.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/diego/Documents/Programacion1/Trabajo 2018-19/Trabajo/Trabajo.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Trabajo.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Trabajo.cpp$(DependSuffix): Trabajo.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Trabajo.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Trabajo.cpp$(DependSuffix) -MM Trabajo.cpp

$(IntermediateDirectory)/Trabajo.cpp$(PreprocessSuffix): Trabajo.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Trabajo.cpp$(PreprocessSuffix) Trabajo.cpp

$(IntermediateDirectory)/up_up_Biblioteca_ordenes.cpp$(ObjectSuffix): ../../Biblioteca/ordenes.cpp $(IntermediateDirectory)/up_up_Biblioteca_ordenes.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/diego/Documents/Programacion1/Biblioteca/ordenes.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_Biblioteca_ordenes.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_Biblioteca_ordenes.cpp$(DependSuffix): ../../Biblioteca/ordenes.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_Biblioteca_ordenes.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_Biblioteca_ordenes.cpp$(DependSuffix) -MM ../../Biblioteca/ordenes.cpp

$(IntermediateDirectory)/up_up_Biblioteca_ordenes.cpp$(PreprocessSuffix): ../../Biblioteca/ordenes.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_Biblioteca_ordenes.cpp$(PreprocessSuffix) ../../Biblioteca/ordenes.cpp

$(IntermediateDirectory)/up_up_Biblioteca_bizi-usuario.cpp$(ObjectSuffix): ../../Biblioteca/bizi-usuario.cpp $(IntermediateDirectory)/up_up_Biblioteca_bizi-usuario.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/diego/Documents/Programacion1/Biblioteca/bizi-usuario.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_Biblioteca_bizi-usuario.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_Biblioteca_bizi-usuario.cpp$(DependSuffix): ../../Biblioteca/bizi-usuario.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_Biblioteca_bizi-usuario.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_Biblioteca_bizi-usuario.cpp$(DependSuffix) -MM ../../Biblioteca/bizi-usuario.cpp

$(IntermediateDirectory)/up_up_Biblioteca_bizi-usuario.cpp$(PreprocessSuffix): ../../Biblioteca/bizi-usuario.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_Biblioteca_bizi-usuario.cpp$(PreprocessSuffix) ../../Biblioteca/bizi-usuario.cpp

$(IntermediateDirectory)/up_up_Biblioteca_bizi-usos.cpp$(ObjectSuffix): ../../Biblioteca/bizi-usos.cpp $(IntermediateDirectory)/up_up_Biblioteca_bizi-usos.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/diego/Documents/Programacion1/Biblioteca/bizi-usos.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_Biblioteca_bizi-usos.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_Biblioteca_bizi-usos.cpp$(DependSuffix): ../../Biblioteca/bizi-usos.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_Biblioteca_bizi-usos.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_Biblioteca_bizi-usos.cpp$(DependSuffix) -MM ../../Biblioteca/bizi-usos.cpp

$(IntermediateDirectory)/up_up_Biblioteca_bizi-usos.cpp$(PreprocessSuffix): ../../Biblioteca/bizi-usos.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_Biblioteca_bizi-usos.cpp$(PreprocessSuffix) ../../Biblioteca/bizi-usos.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


