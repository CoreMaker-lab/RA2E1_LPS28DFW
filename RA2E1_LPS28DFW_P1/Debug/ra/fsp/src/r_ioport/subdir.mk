################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ra/fsp/src/r_ioport/r_ioport.c 

C_DEPS += \
./ra/fsp/src/r_ioport/r_ioport.d 

OBJS += \
./ra/fsp/src/r_ioport/r_ioport.o 

SREC += \
RA2E1_LPS28DFW_P1.srec 

MAP += \
RA2E1_LPS28DFW_P1.map 


# Each subdirectory must supply rules for building sources it contributes
ra/fsp/src/r_ioport/%.o: ../ra/fsp/src/r_ioport/%.c
	$(file > $@.in,-mcpu=cortex-m23 -mthumb -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-strict-aliasing -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal -g -D_RENESAS_RA_ -D_RA_CORE=CM23 -D_RA_ORDINAL=1 -I"C:/Users/a8456/e2_studio/workspace_5.5/RA2E1_LPS28DFW_P1/src" -I"." -I"C:/Users/a8456/e2_studio/workspace_5.5/RA2E1_LPS28DFW_P1/ra/fsp/inc" -I"C:/Users/a8456/e2_studio/workspace_5.5/RA2E1_LPS28DFW_P1/ra/fsp/inc/api" -I"C:/Users/a8456/e2_studio/workspace_5.5/RA2E1_LPS28DFW_P1/ra/fsp/inc/instances" -I"C:/Users/a8456/e2_studio/workspace_5.5/RA2E1_LPS28DFW_P1/ra/arm/CMSIS_6/CMSIS/Core/Include" -I"C:/Users/a8456/e2_studio/workspace_5.5/RA2E1_LPS28DFW_P1/ra_gen" -I"C:/Users/a8456/e2_studio/workspace_5.5/RA2E1_LPS28DFW_P1/ra_cfg/fsp_cfg/bsp" -I"C:/Users/a8456/e2_studio/workspace_5.5/RA2E1_LPS28DFW_P1/ra_cfg/fsp_cfg" -std=c99 -Wno-stringop-overflow -Wno-format-truncation --param=min-pagesize=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

