################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Applicazione.cpp \
../src/Bcol.cpp \
../src/Bgui.cpp \
../src/Bottone.cpp \
../src/ConsoleDebug.cpp \
../src/FileLog.cpp \
../src/Game.cpp \
../src/HardDisk.cpp \
../src/Intro.cpp \
../src/Level0.cpp \
../src/Libreria.cpp \
../src/MenuPrincipale.cpp \
../src/Mondo.cpp \
../src/MotorePhi.cpp \
../src/MyFont.cpp \
../src/MyRect.cpp \
../src/MySurface.cpp \
../src/MyVector.cpp \
../src/Opzioni.cpp \
../src/OutSound.cpp \
../src/OutVideo.cpp \
../src/Picture.cpp \
../src/Player.cpp \
../src/SDL_collide.cpp \
../src/Scripts.cpp \
../src/Sound.cpp \
../src/Sp_Ball.cpp \
../src/Sp_Enemy.cpp \
../src/Sprite.cpp \
../src/Super_FootBall_Reload.cpp \
../src/SysEvent.cpp \
../src/Tastiera.cpp \
../src/Testo.cpp 

OBJS += \
./src/Applicazione.o \
./src/Bcol.o \
./src/Bgui.o \
./src/Bottone.o \
./src/ConsoleDebug.o \
./src/FileLog.o \
./src/Game.o \
./src/HardDisk.o \
./src/Intro.o \
./src/Level0.o \
./src/Libreria.o \
./src/MenuPrincipale.o \
./src/Mondo.o \
./src/MotorePhi.o \
./src/MyFont.o \
./src/MyRect.o \
./src/MySurface.o \
./src/MyVector.o \
./src/Opzioni.o \
./src/OutSound.o \
./src/OutVideo.o \
./src/Picture.o \
./src/Player.o \
./src/SDL_collide.o \
./src/Scripts.o \
./src/Sound.o \
./src/Sp_Ball.o \
./src/Sp_Enemy.o \
./src/Sprite.o \
./src/Super_FootBall_Reload.o \
./src/SysEvent.o \
./src/Tastiera.o \
./src/Testo.o 

CPP_DEPS += \
./src/Applicazione.d \
./src/Bcol.d \
./src/Bgui.d \
./src/Bottone.d \
./src/ConsoleDebug.d \
./src/FileLog.d \
./src/Game.d \
./src/HardDisk.d \
./src/Intro.d \
./src/Level0.d \
./src/Libreria.d \
./src/MenuPrincipale.d \
./src/Mondo.d \
./src/MotorePhi.d \
./src/MyFont.d \
./src/MyRect.d \
./src/MySurface.d \
./src/MyVector.d \
./src/Opzioni.d \
./src/OutSound.d \
./src/OutVideo.d \
./src/Picture.d \
./src/Player.d \
./src/SDL_collide.d \
./src/Scripts.d \
./src/Sound.d \
./src/Sp_Ball.d \
./src/Sp_Enemy.d \
./src/Sprite.d \
./src/Super_FootBall_Reload.d \
./src/SysEvent.d \
./src/Tastiera.d \
./src/Testo.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D_DEBUG -I"/home/biagio/Repository/Super-FootBall-Reload/include" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


