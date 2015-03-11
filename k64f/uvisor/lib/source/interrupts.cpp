/***************************************************************
 * This confidential and  proprietary  software may be used only
 * as authorised  by  a licensing  agreement  from  ARM  Limited
 *
 *             (C) COPYRIGHT 2013-2014 ARM Limited
 *                      ALL RIGHTS RESERVED
 *
 *  The entire notice above must be reproduced on all authorised
 *  copies and copies  may only be made to the  extent permitted
 *  by a licensing agreement from ARM Limited.
 *
 ***************************************************************/
#include <mbed/mbed.h>
#include <uvisor-lib/uvisor-lib.h>

void __uvisor_set_isr(uint32_t irqn, uint32_t vector, uint32_t flag)
{
    register uint32_t __r0 __asm__("r0") = irqn;
    register uint32_t __r1 __asm__("r1") = vector;
    register uint32_t __r2 __asm__("r2") = flag;
    __asm__ volatile(
        "svc %[svc_id]\n"
        :
        : [r0]     "r" (__r0),
          [r1]     "r" (__r1),
          [r2]     "r" (__r2),
          [svc_id] "i" (UVISOR_SVC_ID_SET_ISR)
    );
}

uint32_t __uvisor_get_isr(uint32_t irqn)
{
    register uint32_t __r0  __asm__("r0") = irqn;
    register uint32_t __res __asm__("r0");
    __asm__ volatile(
        "svc %[svc_id]\n"
        : [res]    "=r" (__res)
        : [r0]     "r"  (__r0),
          [svc_id] "i"  (UVISOR_SVC_ID_GET_ISR)
    );
    return __res;
}

void __uvisor_let_isr(uint32_t irqn)
{
    register uint32_t __r0  __asm__("r0") = irqn;
    __asm__ volatile(
        "svc %[svc_id]\n"
        :
        : [r0]     "r"  (__r0),
          [svc_id] "i"  (UVISOR_SVC_ID_LET_ISR)
    );
}

void __uvisor_ena_irq(uint32_t irqn)
{
    register uint32_t __r0 __asm__("r0") = irqn;
    __asm__ volatile(
        "svc %[svc_id]\n"
        :
        : [r0]     "r" (__r0),
          [svc_id] "i" (UVISOR_SVC_ID_ENA_IRQ)
    );
}

void __uvisor_dis_irq(uint32_t irqn)
{
    register uint32_t __r0 __asm__("r0") = irqn;
    __asm__ volatile(
        "svc %[svc_id]\n"
        :
        : [r0]     "r" (__r0),
          [svc_id] "i" (UVISOR_SVC_ID_DIS_IRQ)
    );
}

void __uvisor_set_ena_isr(uint32_t irqn, uint32_t vector, uint32_t flag)
{
    register uint32_t __r0 __asm__("r0") = irqn;
    register uint32_t __r1 __asm__("r1") = vector;
    register uint32_t __r2 __asm__("r2") = flag;
    __asm__ volatile(
        "svc %[svc_id]\n"
        :
        : [r0]     "r" (__r0),
          [r1]     "r" (__r1),
          [r2]     "r" (__r2),
          [svc_id] "i" (UVISOR_SVC_ID_SET_ENA_ISR)
    );
}

void __uvisor_dis_let_isr(uint32_t irqn)
{
    register uint32_t __r0  __asm__("r0") = irqn;
    __asm__ volatile(
        "svc %[svc_id]\n"
        :
        : [r0]     "r"  (__r0),
          [svc_id] "i"  (UVISOR_SVC_ID_DIS_LET_ISR)
    );
}
