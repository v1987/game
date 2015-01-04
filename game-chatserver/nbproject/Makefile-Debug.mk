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
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-Wl,-rpath,../game-engine/engine-file/dist/Debug/GNU-Linux-x86 -L../game-engine/engine-file/dist/Debug/GNU-Linux-x86 -lengine-file -Wl,-rpath,../game-engine/engine-ini/dist/Debug/GNU-Linux-x86 -L../game-engine/engine-ini/dist/Debug/GNU-Linux-x86 -lengine-ini -Wl,-rpath,../game-engine/engine-io/dist/Debug/GNU-Linux-x86 -L../game-engine/engine-io/dist/Debug/GNU-Linux-x86 -lengine-io -Wl,-rpath,../game-engine/engine-log/dist/Debug/GNU-Linux-x86 -L../game-engine/engine-log/dist/Debug/GNU-Linux-x86 -lengine-log -Wl,-rpath,../game-engine/engine-memory/dist/Debug/GNU-Linux-x86 -L../game-engine/engine-memory/dist/Debug/GNU-Linux-x86 -lengine-memory -Wl,-rpath,../game-engine/engine-socket/dist/Debug/GNU-Linux-x86 -L../game-engine/engine-socket/dist/Debug/GNU-Linux-x86 -lengine-socket -Wl,-rpath,../game-engine/engine-thread/dist/Debug/GNU-Linux-x86 -L../game-engine/engine-thread/dist/Debug/GNU-Linux-x86 -lengine-thread -Wl,-rpath,../game-engine/engine-timer/dist/Debug/GNU-Linux-x86 -L../game-engine/engine-timer/dist/Debug/GNU-Linux-x86 -lengine-timer -Wl,-rpath,../game-engine/engine-utils/dist/Debug/GNU-Linux-x86 -L../game-engine/engine-utils/dist/Debug/GNU-Linux-x86 -lengine-utils ../game-engine/engine-common/dist/Debug/GNU-Linux-x86/libengine-common.a

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/game-chatserver

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/game-chatserver: ../game-engine/engine-file/dist/Debug/GNU-Linux-x86/libengine-file.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/game-chatserver: ../game-engine/engine-ini/dist/Debug/GNU-Linux-x86/libengine-ini.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/game-chatserver: ../game-engine/engine-io/dist/Debug/GNU-Linux-x86/libengine-io.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/game-chatserver: ../game-engine/engine-log/dist/Debug/GNU-Linux-x86/libengine-log.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/game-chatserver: ../game-engine/engine-memory/dist/Debug/GNU-Linux-x86/libengine-memory.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/game-chatserver: ../game-engine/engine-socket/dist/Debug/GNU-Linux-x86/libengine-socket.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/game-chatserver: ../game-engine/engine-thread/dist/Debug/GNU-Linux-x86/libengine-thread.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/game-chatserver: ../game-engine/engine-timer/dist/Debug/GNU-Linux-x86/libengine-timer.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/game-chatserver: ../game-engine/engine-utils/dist/Debug/GNU-Linux-x86/libengine-utils.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/game-chatserver: ../game-engine/engine-common/dist/Debug/GNU-Linux-x86/libengine-common.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/game-chatserver: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/game-chatserver ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:
	cd ../game-engine/engine-file && ${MAKE}  -f Makefile CONF=Debug
	cd ../game-engine/engine-ini && ${MAKE}  -f Makefile CONF=Debug
	cd ../game-engine/engine-io && ${MAKE}  -f Makefile CONF=Debug
	cd ../game-engine/engine-log && ${MAKE}  -f Makefile CONF=Debug
	cd ../game-engine/engine-memory && ${MAKE}  -f Makefile CONF=Debug
	cd ../game-engine/engine-socket && ${MAKE}  -f Makefile CONF=Debug
	cd ../game-engine/engine-thread && ${MAKE}  -f Makefile CONF=Debug
	cd ../game-engine/engine-timer && ${MAKE}  -f Makefile CONF=Debug
	cd ../game-engine/engine-utils && ${MAKE}  -f Makefile CONF=Debug
	cd ../game-engine/engine-common && ${MAKE}  -f Makefile CONF=Debug

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/game-chatserver

# Subprojects
.clean-subprojects:
	cd ../game-engine/engine-file && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../game-engine/engine-ini && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../game-engine/engine-io && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../game-engine/engine-log && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../game-engine/engine-memory && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../game-engine/engine-socket && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../game-engine/engine-thread && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../game-engine/engine-timer && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../game-engine/engine-utils && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../game-engine/engine-common && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
