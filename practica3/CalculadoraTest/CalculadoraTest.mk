##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=CalculadoraTest
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/diego/Documents/programacion1/practica3
ProjectPath            :=C:/Users/diego/Documents/programacion1/practica3/CalculadoraTest
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=diego
Date                   :=17/12/2018
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
ObjectsFileList        :="CalculadoraTest.txt"
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
Objects0=$(IntermediateDirectory)/up_up_Biblioteca_calculos.cpp$(ObjectSuffix) $(IntermediateDirectory)/testCalculadora.cc$(ObjectSuffix) $(IntermediateDirectory)/testCalculadora.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/up_up_Biblioteca_calculos.cpp$(ObjectSuffix): ../../Biblioteca/calculos.cpp $(IntermediateDirectory)/up_up_Biblioteca_calculos.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/diego/Documents/Programacion1/Biblioteca/calculos.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_Biblioteca_calculos.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_Biblioteca_calculos.cpp$(DependSuffix): ../../Biblioteca/calculos.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_Biblioteca_calculos.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_Biblioteca_calculos.cpp$(DependSuffix) -MM ../../Biblioteca/calculos.cpp

$(IntermediateDirectory)/up_up_Biblioteca_calculos.cpp$(PreprocessSuffix): ../../Biblioteca/calculos.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_Biblioteca_calculos.cpp$(PreprocessSuffix) ../../Biblioteca/calculos.cpp

$(IntermediateDirectory)/testCalculadora.cc$(ObjectSuffix): testCalculadora.cc $(IntermediateDirectory)/testCalculadora.cc$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/diego/Documents/programacion1/practica3/CalculadoraTest/testCalculadora.cc" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/testCalculadora.cc$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/testCalculadora.cc$(DependSuffix): testCalculadora.cc
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/testCalculadora.cc$(ObjectSuffix) -MF$(IntermediateDirectory)/testCalculadora.cc$(DependSuffix) -MM testCalculadora.cc

$(IntermediateDirectory)/testCalculadora.cc$(PreprocessSuffix): testCalculadora.cc
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/testCalculadora.cc$(PreprocessSuffix) testCalculadora.cc

$(IntermediateDirectory)/testCalculadora.cpp$(ObjectSuffix): testCalculadora.cpp $(IntermediateDirectory)/testCalculadora.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/diego/Documents/programacion1/practica3/CalculadoraTest/testCalculadora.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/testCalculadora.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/testCalculadora.cpp$(DependSuffix): testCalculadora.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/testCalculadora.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/testCalculadora.cpp$(DependSuffix) -MM testCalculadora.cpp

$(IntermediateDirectory)/testCalculadora.cpp$(PreprocessSuffix): testCalculadora.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/testCalculadora.cpp$(PreprocessSuffix) testCalculadora.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/

