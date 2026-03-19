#include "pthread.h"
#include "FreeRTOS.h"
#include "task.h"

#ifdef __cplusplus
extern "C" {
#endif

int pthread_once(pthread_once_t *once_control, void (*init_routine)(void))
{
	taskENTER_CRITICAL();
	if (once_control->state == PTHREAD_NEEDS_INIT) {
		once_control->state = PTHREAD_DONE_INIT;
	    taskEXIT_CRITICAL();

        init_routine();
	} else {
	    taskEXIT_CRITICAL();
    }

	return (0);
}


#ifdef __cplusplus
}
#endif