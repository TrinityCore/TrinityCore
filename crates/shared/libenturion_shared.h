#ifndef libenturion_shared_h
#define libenturion_shared_h

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

typedef struct Config {
  const void *inner;
} Config;

typedef void (*TimerCallback)(void);

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/**
 * Gets the current executable filepath.
 */
const char *GetCurrentExe(void);

/**
 * Load the configuration from files.
 * If load error is not NULL, an error has been raised and the returned value is invalid.
 *
 * # Safety
 * C interface: unsafe function.
 * If an error occurred, the return value is invalid and cannot be used.
 */
struct Config LoadConfig(const char *conf_dir, char **load_error);

/**
 * Gets all the configuration keys.
 * The keys are returned in the keys array (must be passed as pointer). The return value
 * represents the length of the array.
 *
 * # Safety
 * Unsafe: keys array must be freed after use.
 */
uintptr_t Config_GetKeys(const struct Config *self, const char *const **keys);

/**
 * Gets a string configuration value or default.
 *
 * # Safety
 * Unsafe: name is not checked for safety/sanity.
 * Unsafe: returned value must be freed after use.
 */
const char *Config_GetStringDefault(const struct Config *self,
                                    const char *name,
                                    const char *default_);

/**
 * Gets a boolean configuration value.
 *
 * # Safety
 * Unsafe: name is not checked for safety/sanity.
 */
bool Config_GetBoolDefault(const struct Config *self, const char *name, bool default_);

/**
 * Gets an integer configuration value or default.
 *
 * # Safety
 * Unsafe: name is not checked for safety/sanity.
 */
int64_t Config_GetIntDefault(const struct Config *self, const char *name, int64_t default_);

/**
 * Gets a float configuration value or default.
 *
 * # Safety
 * Unsafe: name is not checked for safety/sanity.
 */
double Config_GetFloatDefault(const struct Config *self, const char *name, double default_);

/**
 * De-allocates the current configuration, freeing memory
 */
void Config_Free(struct Config self);

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

#endif /* libenturion_shared_h */
