##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Valorar
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/diego/Documents/Programacion1/practica5
ProjectPath            :=C:/Users/diego/Documents/Programacion1/practica5/Valorar
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=diego
Date                   :=24/12/2018
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
ObjectsFileList        :="Valorar.txt"
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
Objects0=$(IntermediateDirectory)/valorar.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_Biblioteca_nombres.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/valorar.cpp$(ObjectSuffix): valorar.cpp $(IntermediateDirectory)/valorar.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/diego/Documents/Programacion1/practica5/Valorar/valorar.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/valorar.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/valorar.cpp$(DependSuffix): valorar.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/valorar.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/valorar.cpp$(DependSuffix) -MM valorar.cpp

$(IntermediateDirectory)/valorar.cpp$(PreprocessSuffix): valorar.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/valorar.cpp$(PreprocessSuffix) valorar.cpp

$(IntermediateDirectory)/up_up_Biblioteca_nombres.cpp$(ObjectSuffix): ../../Biblioteca/nombres.cpp $(IntermediateDirectory)/up_up_Biblioteca_nombres.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/diego/Documents/Programacion1/Biblioteca/nombres.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_Biblioteca_nombres.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_Biblioteca_nombres.cpp$(DependSuffix): ../../Biblioteca/nombres.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_Biblioteca_nombres.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_Biblioteca_nombres.cpp$(DependSuffix) -MM ../../Biblioteca/nombres.cpp

$(IntermediateDirectory)/up_up_Biblioteca_nombres.cpp$(PreprocessSuffix): ../../Biblioteca/nombres.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_Biblioteca_nombres.cpp$(PreprocessSuffix) ../../Biblioteca/nombres.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


