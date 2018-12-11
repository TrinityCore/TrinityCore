#ifndef TRINITY_DBEDIT_SEARCHTRAITS_H
#define TRINITY_DBEDIT_SEARCHTRAITS_H

#include "advstd.h"
#include "Define.h"
#include "SmartEnum.h"
#include "GlobalDBCStores.h"
#include <map>
#include <string>
#include <utility>

struct LabeledSearchTag
{
    LabeledSearchTag(char const* label, char const* needle) : Label(label), LabeledNeedle(needle) {}
    char const* Label;
    char const* LabeledNeedle;
};

struct SpellEntry;
struct SpellRuneCostEntry;

template <typename T, typename D = void> struct SearchTraits;

template <typename T>
struct SearchTraits<T, std::enable_if_t<advstd::is_enum_v<T>>>
{
    using KeyType = std::underlying_type_t<T>;

    static auto Iterate() { return EnumUtils::Iterate<T>(); }
    static std::string GetTitle(T v) { return EnumUtils::ToTitle(v); }
    static bool CheckLabel(T v, char const* label, char const* needle);
    static T FromKey(KeyType k) { return T(k); }
    static KeyType ToKey(T v) { return v; }
};

template <typename T>
struct SearchTraits<T const*, void>
{
    using KeyType = uint32;

    static auto Iterate() { return StaticDBCStore<T>::iterate(); }
    static bool CheckLabel(T const* obj, char const* label, char const* needle);
    static bool CheckLabel(KeyType k, char const* label, char const* needle) { T const* v = FromKey(k); return v && CheckLabel(v, label, needle); }
    static T const* FromKey(KeyType k) { return StaticDBCStore<T>::LookupEntry(k); }
    static KeyType ToKey(T const* v);
    static std::string GetTitle(T const* v);
};

template <>
struct SearchTraits <SpellEntry const*, void>
{
    using KeyType = uint32;
    static Trinity::IteratorPair<std::map<uint32, char const*>::const_iterator> Iterate();
    static bool CheckLabel(SpellEntry const*, char const* label, char const* needle);
    static bool CheckLabel(KeyType k, char const* label, char const* needle);
    static SpellEntry const* FromKey(KeyType k);
};

template <typename T>
bool MatchesLabel(T val, LabeledSearchTag tag)
{
    return SearchTraits<T>::CheckLabel(val, tag.Label, tag.LabeledNeedle);
}

template <typename T>
bool KeyMatchesLabel(typename SearchTraits<T>::KeyType key, LabeledSearchTag tag)
{
    return SearchTraits<T>::CheckLabel(key, tag.Label, tag.LabeledNeedle);
}

template <typename T, typename V>
bool KeyMatchesLabel(std::pair<typename SearchTraits<T>::KeyType, V> const& pair, LabeledSearchTag tag)
{
    return SearchTraits<T>::CheckLabel(pair.first, tag.Label, tag.LabeledNeedle);
}

#endif
