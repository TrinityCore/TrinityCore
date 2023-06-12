#ifndef libenturion_authserver_h
#define libenturion_authserver_h

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef void (*TickCallback)(void);

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

extern void AbortHandler(void);

void AuthServerRsInit(void);

void AuthServerRsMain(TickCallback tick_callback);

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#endif /* libenturion_authserver_h */
