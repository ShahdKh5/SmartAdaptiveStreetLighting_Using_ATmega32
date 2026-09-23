#ifndef TIMER1_INTERFACE_H
#define TIMER1_INTERFACE_H

#include "../00-LIB/STD_TYPES.h"

#define TIMER1_ICU_FALLING_EDGE 0
#define TIMER1_ICU_RISING_EDGE  1

/* تهيئة التايمر (Prescaler 8) */
void TIMER1_voidInit(void);

/* تحديد نوع الحافة (صاعدة أو هابطة) */
void TIMER1_voidSetICUEdgeTrigger(u8 Copy_u8Edge);

/* مسح علم الـ ICU */
void TIMER1_voidClearICUFlag(void);

/* قراءة حالة علم الـ ICU (هل التقط الإشارة أم لا؟) */
u8 TIMER1_u8GetICUFlag(void);

/* قراءة الزمن المحفوظ */
u16 TIMER1_u16GetICUValue(void);

/* تصفير العداد */
void TIMER1_voidSetTimerValue(u16 Copy_u16Value);

/* إيقاف التايمر تماماً */
void TIMER1_voidStop(void);

#endif
