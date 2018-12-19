##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=practica3
ConfigurationName      :=Debug
WorkspacePath          := "/home/a755232/programacion1/biblioteca/pruebas unix"
ProjectPath            := "/home/a755232/programacion1/biblioteca/pruebas unix/practica3"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Diego Marco Beisty
Date                   :=04/16/18
CodeLitePath           :="/home/a755232/.codelite"
LinkerName             :=/usr/bin/clang++ 
SharedObjectLinkerName :=/usr/bin/clang++ -shared -fPIC
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
ObjectsFileList        :="practica3.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
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
AR       := /usr/bin/llvm-ar rcu
CXX      := /usr/bin/clang++ 
CC       := /usr/bin/clang 
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/llvm-as 


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/fecha.cc$(ObjectSuffix) $(IntermediateDirectory)/nif.cc$(ObjectSuffix) $(IntermediateDirectory)/persona.cc$(ObjectSuffix) $(IntermediateDirectory)/pueba1.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/fecha.cc$(ObjectSuffix): fecha.cc $(IntermediateDirectory)/fecha.cc$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/a755232/programacion1/biblioteca/pruebas unix/practica3/fecha.cc" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/fecha.cc$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/fecha.cc$(DependSuffix): fecha.cc
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/fecha.cc$(ObjectSuffix) -MF$(IntermediateDirectory)/fecha.cc$(DependSuffix) -MM "fecha.cc"

$(IntermediateDirectory)/fecha.cc$(PreprocessSuffix): fecha.cc
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/fecha.cc$(PreprocessSuffix) "fecha.cc"

$(IntermediateDirectory)/nif.cc$(ObjectSuffix): nif.cc $(IntermediateDirectory)/nif.cc$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/a755232/programacion1/biblioteca/pruebas unix/practica3/nif.cc" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/nif.cc$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/nif.cc$(DependSuffix): nif.cc
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/nif.cc$(ObjectSuffix) -MF$(IntermediateDirectory)/nif.cc$(DependSuffix) -MM "nif.cc"

$(IntermediateDirectory)/nif.cc$(PreprocessSuffix): nif.cc
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/nif.cc$(PreprocessSuffix) "nif.cc"

$(IntermediateDirectory)/persona.cc$(ObjectSuffix): persona.cc $(IntermediateDirectory)/persona.cc$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/a755232/programacion1/biblioteca/pruebas unix/practica3/persona.cc" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/persona.cc$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/persona.cc$(DependSuffix): persona.cc
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/persona.cc$(ObjectSuffix) -MF$(IntermediateDirectory)/persona.cc$(DependSuffix) -MM "persona.cc"

$(IntermediateDirectory)/persona.cc$(PreprocessSuffix): persona.cc
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/persona.cc$(PreprocessSuffix) "persona.cc"

$(IntermediateDirectory)/pueba1.cpp$(ObjectSuffix): pueba1.cpp $(IntermediateDirectory)/pueba1.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/a755232/programacion1/biblioteca/pruebas unix/practica3/pueba1.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/pueba1.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/pueba1.cpp$(DependSuffix): pueba1.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/pueba1.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/pueba1.cpp$(DependSuffix) -MM "pueba1.cpp"

$(IntermediateDirectory)/pueba1.cpp$(PreprocessSuffix): pueba1.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/pueba1.cpp$(PreprocessSuffix) "pueba1.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) ./Debug/*$(ObjectSuffix)
	$(RM) ./Debug/*$(DependSuffix)
	$(RM) $(OutputFile)
	$(RM) "../.build-debug/practica3"


