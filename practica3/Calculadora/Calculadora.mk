##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Calculadora
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/diego/Documents/programacion1/practica3
ProjectPath            :=C:/Users/diego/Documents/programacion1/practica3/Calculadora
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
ObjectsFileList        :="Calculadora.txt"
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
Objects0=$(IntermediateDirectory)/calculadora-enteros.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_Biblioteca_Calculos_calculos.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/calculadora-enteros.cpp$(ObjectSuffix): calculadora-enteros.cpp $(IntermediateDirectory)/calculadora-enteros.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/diego/Documents/programacion1/practica3/Calculadora/calculadora-enteros.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/calculadora-enteros.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/calculadora-enteros.cpp$(DependSuffix): calculadora-enteros.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/calculadora-enteros.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/calculadora-enteros.cpp$(DependSuffix) -MM calculadora-enteros.cpp

$(IntermediateDirectory)/calculadora-enteros.cpp$(PreprocessSuffix): calculadora-enteros.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/calculadora-enteros.cpp$(PreprocessSuffix) calculadora-enteros.cpp

$(IntermediateDirectory)/up_up_Biblioteca_Calculos_calculos.cpp$(ObjectSuffix): ../../Biblioteca/Calculos/calculos.cpp $(IntermediateDirectory)/up_up_Biblioteca_Calculos_calculos.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/diego/Documents/programacion1/Biblioteca/Calculos/calculos.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_Biblioteca_Calculos_calculos.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_Biblioteca_Calculos_calculos.cpp$(DependSuffix): ../../Biblioteca/Calculos/calculos.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_Biblioteca_Calculos_calculos.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_Biblioteca_Calculos_calculos.cpp$(DependSuffix) -MM ../../Biblioteca/Calculos/calculos.cpp

$(IntermediateDirectory)/up_up_Biblioteca_Calculos_calculos.cpp$(PreprocessSuffix): ../../Biblioteca/Calculos/calculos.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_Biblioteca_Calculos_calculos.cpp$(PreprocessSuffix) ../../Biblioteca/Calculos/calculos.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


