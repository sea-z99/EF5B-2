################################################################################
# �Զ����ɵ��ļ�����Ҫ�༭��
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
	@echo '���ڹ����ļ��� $<'
	@echo '���ڵ��ã� C Compiler Debug'
	kf8cc_debug.exe -c --no-peep -pKF8A200GQV -I"C:\ChipONCC\include" -o"$@" "$<"
	@echo '�ѽ��������� $<'
	@echo ' '


