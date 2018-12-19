##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=GestionGrupos
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/diego/Documents/programacion1/biblioteca
ProjectPath            :=C:/Users/diego/Documents/programacion1/biblioteca/GestionGrupos
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=diego
Date                   :=12/01/2018
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
ObjectsFileList        :="GestionGrupos.txt"
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
Objects0=$(IntermediateDirectory)/generarFicheroNotas.cpp$(ObjectSuffix) $(IntermediateDirectory)/grupo.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/generarFicheroNotas.cpp$(ObjectSuffix): generarFicheroNotas.cpp $(IntermediateDirectory)/generarFicheroNotas.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/diego/Documents/programacion1/biblioteca/GestionGrupos/generarFicheroNotas.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/generarFicheroNotas.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/generarFicheroNotas.cpp$(DependSuffix): generarFicheroNotas.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/generarFicheroNotas.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/generarFicheroNotas.cpp$(DependSuffix) -MM generarFicheroNotas.cpp

$(IntermediateDirectory)/generarFicheroNotas.cpp$(PreprocessSuffix): generarFicheroNotas.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/generarFicheroNotas.cpp$(PreprocessSuffix) generarFicheroNotas.cpp

$(IntermediateDirectory)/grupo.cpp$(ObjectSuffix): grupo.cpp $(IntermediateDirectory)/grupo.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/diego/Documents/programacion1/biblioteca/GestionGrupos/grupo.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/grupo.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/grupo.cpp$(DependSuffix): grupo.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/grupo.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/grupo.cpp$(DependSuffix) -MM grupo.cpp

$(IntermediateDirectory)/grupo.cpp$(PreprocessSuffix): grupo.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/grupo.cpp$(PreprocessSuffix) grupo.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


