##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Estaciones
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/diego/Documents/Programacion1/practica6
ProjectPath            :=C:/Users/diego/Documents/Programacion1/practica6/Estaciones
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=diego
Date                   :=31/12/2018
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
ObjectsFileList        :="Estaciones.txt"
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
Objects0=$(IntermediateDirectory)/estaciones.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_Biblioteca_bizi-estaciones.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/estaciones.cpp$(ObjectSuffix): estaciones.cpp $(IntermediateDirectory)/estaciones.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/diego/Documents/Programacion1/practica6/Estaciones/estaciones.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/estaciones.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/estaciones.cpp$(DependSuffix): estaciones.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/estaciones.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/estaciones.cpp$(DependSuffix) -MM estaciones.cpp

$(IntermediateDirectory)/estaciones.cpp$(PreprocessSuffix): estaciones.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/estaciones.cpp$(PreprocessSuffix) estaciones.cpp

$(IntermediateDirectory)/up_up_Biblioteca_bizi-estaciones.cpp$(ObjectSuffix): ../../Biblioteca/bizi-estaciones.cpp $(IntermediateDirectory)/up_up_Biblioteca_bizi-estaciones.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/diego/Documents/Programacion1/Biblioteca/bizi-estaciones.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_Biblioteca_bizi-estaciones.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_Biblioteca_bizi-estaciones.cpp$(DependSuffix): ../../Biblioteca/bizi-estaciones.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_Biblioteca_bizi-estaciones.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_Biblioteca_bizi-estaciones.cpp$(DependSuffix) -MM ../../Biblioteca/bizi-estaciones.cpp

$(IntermediateDirectory)/up_up_Biblioteca_bizi-estaciones.cpp$(PreprocessSuffix): ../../Biblioteca/bizi-estaciones.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_Biblioteca_bizi-estaciones.cpp$(PreprocessSuffix) ../../Biblioteca/bizi-estaciones.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


