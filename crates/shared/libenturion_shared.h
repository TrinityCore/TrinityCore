#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

enum DbcFieldFormat
#ifdef __cplusplus
  : uint8_t
#endif // __cplusplus
 {
  FT_NA = 120,
  FT_NA_BYTE = 88,
  FT_STRING = 115,
  FT_FLOAT = 102,
  FT_INT = 105,
  FT_BYTE = 98,
  FT_SORT = 100,
  FT_IND = 110,
  FT_LOGIC = 108,
  FT_SQL_PRESENT = 112,
  FT_SQL_ABSENT = 97,
};
#ifndef __cplusplus
typedef uint8_t DbcFieldFormat;
#endif // __cplusplus

typedef void (*TimerCallback)(void);

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

void LoadConfig(void);

/**
 * # Safety
 * C++ Interface. Do conversions from unsafe structs to safe ones and back.
 * Asserts that the format pointer is non-null.
 */
uintptr_t DBCFileLoader_GetFormatRecordSize(const char *format, int32_t *index_pos);

void CreateTimer(uint64_t interval_seconds, TimerCallback callback);

#if defined(_WIN32)
bool WinServiceInstall(const char *service_name, const char *service_description);
#endif

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus
