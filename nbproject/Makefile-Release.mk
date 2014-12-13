#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/GUI/Counter.o \
	${OBJECTDIR}/src/GUI/GameData.o \
	${OBJECTDIR}/src/GUI/Interface.o \
	${OBJECTDIR}/src/GUI/Language.o \
	${OBJECTDIR}/src/GUI/Node.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-m64 -Wfatal-errors -Wall -Wextra -pedantic -Winit-self -Wmissing-include-dirs -Wswitch-default -Wswitch-enum -Wswitch-default -Wfloat-equal -Wshadow -Wcast-qual -Wcast-align -Wwrite-strings -Wconversion -Wsign-conversion -Wlogical-op -Wmissing-declarations -Wmissing-noreturn -Wmissing-format-attribute -Wpacked -Wredundant-decls -Wunreachable-code -Winline -Winvalid-pch -Wvolatile-register-var -Wdisabled-optimization -Wstack-protector
CXXFLAGS=-m64 -Wfatal-errors -Wall -Wextra -pedantic -Winit-self -Wmissing-include-dirs -Wswitch-default -Wswitch-enum -Wswitch-default -Wfloat-equal -Wshadow -Wcast-qual -Wcast-align -Wwrite-strings -Wconversion -Wsign-conversion -Wlogical-op -Wmissing-declarations -Wmissing-noreturn -Wmissing-format-attribute -Wpacked -Wredundant-decls -Wunreachable-code -Winline -Winvalid-pch -Wvolatile-register-var -Wdisabled-optimization -Wstack-protector

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblibgui.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblibgui.a: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblibgui.a
	${AR} -rv ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblibgui.a ${OBJECTFILES} 
	$(RANLIB) ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblibgui.a

${OBJECTDIR}/src/GUI/Counter.o: src/GUI/Counter.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/GUI
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Wall -s -DGLEW_STATIC -I../../../../../lib/freetype-2.5.3/include -I../../../../../lib/glew-1.11.0/include -I../libcsv/src -I../libfont/src -I../libgltools/src -I../libmatrix/src -I../libtools/src -I../libvector/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/GUI/Counter.o src/GUI/Counter.cpp

${OBJECTDIR}/src/GUI/GameData.o: src/GUI/GameData.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/GUI
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Wall -s -DGLEW_STATIC -I../../../../../lib/freetype-2.5.3/include -I../../../../../lib/glew-1.11.0/include -I../libcsv/src -I../libfont/src -I../libgltools/src -I../libmatrix/src -I../libtools/src -I../libvector/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/GUI/GameData.o src/GUI/GameData.cpp

${OBJECTDIR}/src/GUI/Interface.o: src/GUI/Interface.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/GUI
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Wall -s -DGLEW_STATIC -I../../../../../lib/freetype-2.5.3/include -I../../../../../lib/glew-1.11.0/include -I../libcsv/src -I../libfont/src -I../libgltools/src -I../libmatrix/src -I../libtools/src -I../libvector/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/GUI/Interface.o src/GUI/Interface.cpp

${OBJECTDIR}/src/GUI/Language.o: src/GUI/Language.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/GUI
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Wall -s -DGLEW_STATIC -I../../../../../lib/freetype-2.5.3/include -I../../../../../lib/glew-1.11.0/include -I../libcsv/src -I../libfont/src -I../libgltools/src -I../libmatrix/src -I../libtools/src -I../libvector/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/GUI/Language.o src/GUI/Language.cpp

${OBJECTDIR}/src/GUI/Node.o: src/GUI/Node.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/GUI
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Wall -s -DGLEW_STATIC -I../../../../../lib/freetype-2.5.3/include -I../../../../../lib/glew-1.11.0/include -I../libcsv/src -I../libfont/src -I../libgltools/src -I../libmatrix/src -I../libtools/src -I../libvector/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/GUI/Node.o src/GUI/Node.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblibgui.a

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
