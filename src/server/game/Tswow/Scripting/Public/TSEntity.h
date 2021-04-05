#pragma once

#include <memory>

#include "TSString.h"
#include "TSBase.h"

// Could be a base class, but would have to track the pointer

#define TS_ENTITY_DATA_DECL(CLS)                                                                                                 \
    template <typename T>                                                                                                  \
    std::shared_ptr<T> SetObject(uint32_t modid, TSString key, std::shared_ptr<T> item)                                    \
    {                                                                                                                      \
        return GetData()->SetObject(modid, key, item);                                                                     \
    }                                                                                                                      \
                                                                                                                           \
    template <typename T>                                                                                                  \
    std::shared_ptr<T> GetObject(uint32_t modid, TSString key, std::function<std::shared_ptr<T>()> defaultValue = nullptr) \
    {                                                                                                                      \
        return GetData()->GetObject(modid, key, defaultValue);                                                             \
    }                                                                                                                      \
                                                                                                                           \
    int32_t SetInt(TSString key, int32_t value);                                                                           \
    bool HasInt(TSString key);                                                                                             \
    int32 GetInt(TSString key, int32_t def = 0);                                                                           \
                                                                                                                           \
    uint32_t SetUInt(TSString key, uint32_t value);                                                                        \
    bool HasUInt(TSString key);                                                                                            \
    uint32 GetUInt(TSString key, uint32_t def = 0);                                                                        \
                                                                                                                           \
    TSString SetString(TSString key, TSString value);                                                                      \
    bool HasString(TSString key);                                                                                          \
    TSString GetString(TSString key, TSString def = JSTR(""));                                                             \
                                                                                                                           \
    double SetFloat(TSString key, double value);                                                                           \
    bool HasFloat(TSString key);                                                                                           \
    double GetFloat(TSString key, double def = 0);                                                                         \

#define TS_ENTITY_TIMER_DECL(CLS) \
    void RemoveTimer(TSString name);                                                                                       \
    void AddTimer(uint32_t modid, TSString name, uint32_t time, uint32_t repeats, TimerCallback(CLS) callback);

#define TS_ENTITY_DATA_IMPL(CLS)                                                                                                                                                                 \
    int32_t CLS::SetInt(TSString key, int32_t value) { return GetData()->SetInt(key, value); }                                                                                             \
    bool CLS::HasInt(TSString key) { return GetData()->HasInt(key); }                                                                                                                      \
    int32 CLS::GetInt(TSString key, int32 def) { return GetData()->GetInt(key, def); };                                                                                                    \
                                                                                                                                                                                           \
    uint32_t CLS::SetUInt(TSString key, uint32_t value) { return GetData()->SetUInt(key, value); }                                                                                         \
    bool CLS::HasUInt(TSString key) { return GetData()->HasUInt(key); }                                                                                                                    \
    uint32 CLS::GetUInt(TSString key, uint32 def) { return GetData()->GetUInt(key, def); };                                                                                                \
                                                                                                                                                                                           \
    TSString CLS::SetString(TSString key, TSString value) { return GetData()->SetString(key, value); };                                                                                    \
    bool CLS::HasString(TSString key) { return GetData()->HasString(key); };                                                                                                               \
    TSString CLS::GetString(TSString key, TSString def) { return GetData()->GetString(key, def); };                                                                                        \
                                                                                                                                                                                           \
    double CLS::SetFloat(TSString key, double value) { return GetData()->SetFloat(key, value); };                                                                                          \
    bool CLS::HasFloat(TSString key) { return GetData()->HasFloat(key); };                                                                                                                 \
    double CLS::GetFloat(TSString key, double def) { return GetData()->GetFloat(key, def); };                                                                                              \

#define TS_ENTITY_TIMER_IMPL(CLS) \
    void CLS::AddTimer(uint32_t modid, TSString name, uint32_t time, uint32_t repeats, TimerCallback(CLS) callback) { return GetTasks()->AddTimer(modid, name, time, repeats, callback); } \
    void CLS::RemoveTimer(TSString name) { return GetTasks()->RemoveTimer(name); }
