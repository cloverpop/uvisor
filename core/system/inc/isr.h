#ifndef __ISR_H__
#define __ISR_H__

#define IRQn_OFFSET             16
#define MAX_ISR_VECTORS         (IRQn_OFFSET+38)
#define ISR_SET(irqn, handler)         g_isr_vector[IRQn_OFFSET + irqn] = handler;

typedef void (*TIsrVector)(void);
EXTERN TIsrVector g_isr_vector[MAX_ISR_VECTORS];
EXTERN void main_entry(void);

typedef uint32_t (*LibInitFunc)(void);
extern uint32_t __lib_init_start__;
extern uint32_t __lib_init_end__;

#endif/*__ISR_H__*/
