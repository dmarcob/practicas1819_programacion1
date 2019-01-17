##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=NaturalesGrandesTest
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/diego/Documents/Programacion1/Practica4
ProjectPath            :=C:/Users/diego/Documents/Programacion1/Practica4/NaturalesGrandesTest
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=diego
Date                   :=18/12/2018
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
ObjectsFileList        :="NaturalesGrandesTest.txt"
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
Objects0=$(IntermediateDirectory)/naturales-grandes-test-main.cpp$(ObjectSuffix) $(IntermediateDirectory)/naturales-grandes.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_Biblioteca_naturales-grandes-test.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/naturales-grandes-test-main.cpp$(ObjectSuffix): naturales-grandes-test-main.cpp $(IntermediateDirectory)/naturales-grandes-test-main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/diego/Documents/Programacion1/Practica4/NaturalesGrandesTest/naturales-grandes-test-main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/naturales-grandes-test-main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/naturales-grandes-test-main.cpp$(DependSuffix): naturales-grandes-test-main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/naturales-grandes-test-main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/naturales-grandes-test-main.cpp$(DependSuffix) -MM naturales-grandes-test-main.cpp

$(IntermediateDirectory)/naturales-grandes-test-main.cpp$(PreprocessSuffix): naturales-grandes-test-main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/naturales-grandes-test-main.cpp$(PreprocessSuffix) naturales-grandes-test-main.cpp

$(IntermediateDirectory)/naturales-grandes.cpp$(ObjectSuffix): naturales-grandes.cpp $(IntermediateDirectory)/naturales-grandes.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/diego/Documents/Programacion1/Practica4/NaturalesGrandesTest/naturales-grandes.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/naturales-grandes.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/naturales-grandes.cpp$(DependSuffix): naturales-grandes.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/naturales-grandes.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/naturales-grandes.cpp$(DependSuffix) -MM naturales-grandes.cpp

$(IntermediateDirectory)/naturales-grandes.cpp$(PreprocessSuffix): naturales-grandes.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/naturales-grandes.cpp$(PreprocessSuffix) naturales-grandes.cpp

$(IntermediateDirectory)/up_up_Biblioteca_naturales-grandes-test.cpp$(ObjectSuffix): ../../Biblioteca/naturales-grandes-test.cpp $(IntermediateDirectory)/up_up_Biblioteca_naturales-grandes-test.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/diego/Documents/Programacion1/Biblioteca/naturales-grandes-test.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_Biblioteca_naturales-grandes-test.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_Biblioteca_naturales-grandes-test.cpp$(DependSuffix): ../../Biblioteca/naturales-grandes-test.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_Biblioteca_naturales-grandes-test.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_Biblioteca_naturales-grandes-test.cpp$(DependSuffix) -MM ../../Biblioteca/naturales-grandes-test.cpp

$(IntermediateDirectory)/up_up_Biblioteca_naturales-grandes-test.cpp$(PreprocessSuffix): ../../Biblioteca/naturales-grandes-test.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_Biblioteca_naturales-grandes-test.cpp$(PreprocessSuffix) ../../Biblioteca/naturales-grandes-test.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


