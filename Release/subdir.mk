################################################################################
# �Զ����ɵ��ļ�����Ҫ�༭��
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../GPIO.c \
../Led.c \
../OSC.c \
../SoftSpi.c \
../Work.c \
../config_set.c \
../main.c 

OBJS += \
./GPIO.o \
./Led.o \
./OSC.o \
./SoftSpi.o \
./Work.o \
./config_set.o \
./main.o 

C_DEPS += \
./GPIO.dep \
./Led.dep \
./OSC.dep \
./SoftSpi.dep \
./Work.dep \
./config_set.dep \
./main.dep 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo '���ڹ����ļ��� $<'
	@echo '���ڵ��ã� C Compiler'
	kf8cc -c -pKF8A200GQS -I"E:\KungFuIDE\include" -I"C:\Users\Rick\Desktop\EF5B\EF5B����\EF5B-2" -o"$@" "$<"
	@echo '�ѽ��������� $<'
	@echo ' '


