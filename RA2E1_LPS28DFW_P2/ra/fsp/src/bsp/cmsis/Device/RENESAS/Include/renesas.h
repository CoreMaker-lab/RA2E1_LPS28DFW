/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/* Ensure Renesas MCU variation definitions are included to ensure MCU
 * specific register variations are handled correctly. */
#ifndef BSP_FEATURE_H
 #error "INTERNAL ERROR: bsp_feature.h must be included before renesas.h."
#endif

/** @addtogroup Renesas
 * @{
 */

/** @addtogroup RA
 * @{
 */

#ifndef RA_H
 #define RA_H

 #ifdef __cplusplus
extern "C" {
 #endif

 #include "cmsis_compiler.h"

/** @addtogroup Configuration_of_CMSIS
 * @{
 */

/* =========================================================================================================================== */
/* ================                                Interrupt Number Definition                                ================ */
/* =========================================================================================================================== */
/* IRQn_Type is provided in bsp_exceptions.h. Vectors generated by the FSP Configuration tool are in vector_data.h */

/** @} */ /* End of group Configuration_of_CMSIS */

/* =========================================================================================================================== */
/* ================                           Processor and Core Peripheral Section                           ================ */
/* =========================================================================================================================== */

 #if BSP_MCU_GROUP_RA0E1
  #include "R7FA0E107.h"
 #elif BSP_MCU_GROUP_RA2A1
  #include "R7FA2A1AB.h"
 #elif BSP_MCU_GROUP_RA2A2
  #include "R7FA2A2AD.h"
 #elif BSP_MCU_GROUP_RA2E1
  #include "R7FA2E1A9.h"
 #elif BSP_MCU_GROUP_RA2E2
  #include "R7FA2E2A7.h"
 #elif BSP_MCU_GROUP_RA2E3
  #include "R7FA2E307.h"
 #elif BSP_MCU_GROUP_RA2L1
  #include "R7FA2L1AB.h"
 #elif BSP_MCU_GROUP_RA4E1
  #include "R7FA4E10D.h"
 #elif BSP_MCU_GROUP_RA4E2
  #include "R7FA4E2B9.h"
 #elif BSP_MCU_GROUP_RA4M1
  #include "R7FA4M1AB.h"
 #elif BSP_MCU_GROUP_RA4M2
  #include "R7FA4M2AD.h"
 #elif BSP_MCU_GROUP_RA4M3
  #include "R7FA4M3AF.h"
 #elif BSP_MCU_GROUP_RA4T1
  #include "R7FA4T1BB.h"
 #elif BSP_MCU_GROUP_RA4W1
  #include "R7FA4W1AD.h"
 #elif BSP_MCU_GROUP_RA6E1
  #include "R7FA6E10F.h"
 #elif BSP_MCU_GROUP_RA6E2
  #include "R7FA6E2BB.h"
 #elif BSP_MCU_GROUP_RA6M1
  #include "R7FA6M1AD.h"
 #elif BSP_MCU_GROUP_RA6M2
  #include "R7FA6M2AF.h"
 #elif BSP_MCU_GROUP_RA6M3
  #include "R7FA6M3AH.h"
 #elif BSP_MCU_GROUP_RA6M4
  #include "R7FA6M4AF.h"
 #elif BSP_MCU_GROUP_RA6M5
  #include "R7FA6M5BH.h"
 #elif BSP_MCU_GROUP_RA6T1
  #include "R7FA6T1AD.h"
 #elif BSP_MCU_GROUP_RA6T2
  #include "R7FA6T2BD.h"
 #elif BSP_MCU_GROUP_RA6T3
  #include "R7FA6T3BB.h"
 #elif BSP_MCU_GROUP_RA8M1
  #include "R7FA8M1AH.h"
 #elif BSP_MCU_GROUP_RA8D1
  #include "R7FA8D1BH.h"
 #elif BSP_MCU_GROUP_RA8T1
  #include "R7FA8T1AH.h"
 #else
  #if __has_include("renesas_internal.h")
   #include "renesas_internal.h"
  #else
   #warning "Unsupported MCU"
  #endif
 #endif

/*
 * ARM has advised to no longer use the __ARM_ARCH_8_1M_MAIN__ type macro and to instead use the __ARM_ARCH and __ARM_ARCH_ISA_THUMB
 * macros for differentiating architectures. However, with all of our toolchains, neither paradigm is being correctly produced for Cortex-M85
 * and thus we still need a workaround. Below is a summary of the current macros produced by each toolchain for CM85:
 *
 * | Toolchain | __ARM_ARCH |     _ARM_ARCH_xx__     |
 * |-----------|------------|------------------------|
 * |   GCC     |      8     | __ARM_ARCH_8M_MAIN__   |
 * |   LLVM    |      8     | __ARM_ARCH_8_1M_MAIN__ |
 * |   AC6     |      8     | __ARM_ARCH_8_1M_MAIN__ |
 * |   IAR     |     801    | __ARM_ARCH_8M_MAIN__   |
 *
 * The expected output for CM85 should be __ARM_ARCH == 801, __ARM_ARCH_ISA_THUMB == 2, and __ARM_ARCH_8_1M_MAIN__
 *
 * IAR is currently the only toolchain producing the correct __ARM_ARCH value.
 *
 *- See https://github.com/ARM-software/CMSIS_6/issues/159
 */
 #if BSP_CFG_MCU_PART_SERIES == 8 && !defined(__ICCARM__) && BSP_CFG_CPU_CORE != 1
  #undef __ARM_ARCH
  #define __ARM_ARCH    801
 #endif

 #if   (__ARM_ARCH == 7) && (__ARM_ARCH_ISA_THUMB == 2)
  #define RENESAS_CORTEX_M4
 #elif (__ARM_ARCH == 8) && (__ARM_ARCH_ISA_THUMB == 1)
  #define RENESAS_CORTEX_M23
 #elif (__ARM_ARCH == 8) && (__ARM_ARCH_ISA_THUMB == 2)
  #define RENESAS_CORTEX_M33
 #elif (__ARM_ARCH == 801) && (__ARM_ARCH_ISA_THUMB == 2)
  #define RENESAS_CORTEX_M85
 #else
  #warning Unsupported Architecture
 #endif

 #ifdef __cplusplus
}
 #endif

#endif                                 /* RA_H */

/** @} */ /* End of group RA */

/** @} */ /* End of group Renesas */
