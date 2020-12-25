################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../GPIO.c \
../OSC.c \
../config_set.c \
../main.c 

OBJS += \
./GPIO.o \
./OSC.o \
./config_set.o \
./main.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo '正在构建文件： $<'
	@echo '正在调用： C Compiler Debug'
	kf8cc_debug.exe -c --no-peep -pKF8A200GQV -I"C:\ChipONCC\include" -o"$@" "$<"
	@echo '已结束构建： $<'
	@echo ' '


