################################################################################
# 自动生成的文件。不要编辑！
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# 所有目标
all: 01-\ GPIO_Sample.hex

# 工具调用
01-\ GPIO_Sample.hex: $(OBJS) $(USER_RELS)
	@echo '正在构建目标： $@'
	@echo '正在调用： C Linker Debug'
	kf8link_debug.exe -O3 KF8A200GQV_monitor.lib libkf8v4.lib KF8A200GQV.lib KF8_Touch_Fun.lib -s"C:/ChipONCC/kfl/KF8A200GQV.kfl" -o "01- GPIO_Sample.hex" $(OBJS) $(USER_RELS) $(LIBS)
	@echo '已结束构建目标： $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# 其他目标
clean:
	-$(RM) $(OBJS)$(EXECUTABLES) "01- GPIO_Sample.hex"
	-@echo ' '

post-build:
	-kf8exec_debug.exe 01- GPIO_Sample
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
