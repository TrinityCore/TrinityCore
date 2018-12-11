#include "SearchTraits.h"
#include "advstd.h"
#include "DBCStructure.h"
#include "Log.h"
#include "SpellAccessor.h"
#include <cstring>
#include <sstream>

enum Operators  // we only need positive operators - you can always invert with prefixed !
{               // SEQUENCE         TRUE IFF
    OP_EQUAL,   //  =               val == needle
    OP_BANDEQ,  //  &=              val & needle == needle
    OP_BANDNZ,  //  &               val & needle != 0
    OP_LT,      //  <               val < needle
    OP_GT,      //  >               val > needle
    OP_LEQ,     // <=               val <= needle
    OP_GEQ      // >=               val >= needle
};

template <typename I>
std::enable_if_t<advstd::is_integral_v<I>, bool> IntegralCheckOp(Operators op, I val, I needle)
{
    switch (op)
    {
        case OP_BANDEQ:
            return (val & needle) == needle;
        case OP_BANDNZ:
            return (val & needle) != 0;
        default:
            ASSERT(false);
            return false;
    }
}

template <typename F>
std::enable_if_t<advstd::is_floating_point_v<F>, bool> IntegralCheckOp(Operators, F, F)
{
    ASSERT(false);
    return false;
}

template <typename A>
bool ArithmeticCheckOp(Operators op, A val, A needle)
{
    switch (op)
    {
        case OP_BANDEQ:
        case OP_BANDNZ:
            return IntegralCheckOp<A>(op, val, needle);
        case OP_EQUAL:
            return (val == needle);
        case OP_LT:
            return (val < needle);
        case OP_GT:
            return (val > needle);
        case OP_LEQ:
            return (val <= needle);
        case OP_GEQ:
            return (val >= needle);
        default:
            ASSERT(false);
            return false;
    }
}

struct Operation
{
    Operation(bool invert, Operators op) : Inverted(invert), Operator(op) {}
    bool const Inverted;
    Operators const Operator;
};

template <typename A>
static Operators stripOperator(char const*& needle)
{
    ASSERT(*needle);
    switch (*(needle++))
    {
        case '=':
            return OP_EQUAL;
        case '<':
            if (*needle == '=')
            {
                ++needle;
                return OP_LEQ;
            }
            return OP_LT;
        case '>':
            if (*needle == '=')
            {
                ++needle;
                return OP_GEQ;
            }
            return OP_GT;
        case '&':
            if (advstd::is_integral_v<A>)
            {
                if (*needle == '=')
                {
                    ++needle;
                    return OP_BANDEQ;
                }
                return OP_BANDNZ;
            }
            // no break
        default:
            --needle;
            return OP_EQUAL;
    }
}

template <typename A>
static Operation stripPrefix(char const*& needle)
{
    bool invert;
    if ((invert = (*needle == '!')))
        ++needle;
    return { invert, stripOperator<A>(needle) };
}

template <typename I>
static inline std::enable_if_t<std::is_integral_v<I> && std::is_unsigned_v<I>, bool> parseStringAs(char const* needle, I& value)
{
    char* ptr;
    value = std::strtoumax(needle, &ptr, 0);
    return (ptr != needle);
}

template <typename I>
static inline std::enable_if_t<std::is_integral_v<I> && std::is_signed_v<I>, bool> parseStringAs(char const* needle, I& value)
{
    char* ptr;
    value = std::strtoimax(needle, &ptr, 0);
    return (ptr != needle);
}

template <typename F>
static inline std::enable_if_t<std::is_floating_point_v<F>, bool> parseStringAs(char const* needle, F& value)
{
    char* ptr;
    value = std::strtold(needle, &ptr);
    return (ptr != needle);
}

template <typename A>
static bool ArithmeticCheck(char const* needle, A value)
{
    static_assert(advstd::is_arithmetic_v<A>, "ArithmeticCheck must be passed arithmetic value");

    Operation op = stripPrefix<A>(needle);

    A needleA;
    if (!parseStringAs<A>(needle, needleA))
    {
        TC_LOG_WARN("dbedit", "Invalid search needle '%s' for integral label ignored", needle);
        return false;
    }

    return ArithmeticCheckOp(op.Operator, value, needleA) != op.Inverted;
}

static inline void UnknownLabelWarn(char const* label) { TC_LOG_WARN("Unknown label '%s' ignored", label); }

bool SearchTraits<SpellEntry const*, void>::CheckLabel(SpellEntry const* obj, char const* label, char const* needle)
{
    ASSERT(obj && needle);
    if (!label)
        return StringContainsStringI(obj->SpellName[0], needle);

    if (!stricmp(label, "id"))
        return ArithmeticCheck(needle, obj->Id);
    if (!stricmp(label, "powertype"))
        return StringContainsStringI(EnumUtils::ToTitle(Powers(obj->powerType)), needle);

    UnknownLabelWarn(label);
    return false;
}

bool SearchTraits<SpellEntry const*, void>::CheckLabel(uint32 spellId, char const* label, char const* needle)
{
    if (SpellEntry const* entry = SpellAccessor::GetDBSpellEntry(spellId))
        if (CheckLabel(entry, label, needle))
            return true;
    if (SpellEntry const* entry = SpellAccessor::GetDBCSpellEntry(spellId))
        if (CheckLabel(entry, label, needle))
            return true;
    return false;
}

bool SearchTraits<SpellFamilyNames, void>::CheckLabel(SpellFamilyNames v, char const* label, char const* needle)
{
    ASSERT(needle);
    if (!label)
        return StringContainsStringI(EnumUtils::ToTitle(v), needle);

    UnknownLabelWarn(label);
    return false;
}

bool SearchTraits<Powers, void>::CheckLabel(Powers v, char const* label, char const* needle)
{
    if (!label)
        return StringContainsStringI(EnumUtils::ToTitle(v), needle);

    UnknownLabelWarn(label);
    return false;
}

bool SearchTraits<SpellDmgClass, void>::CheckLabel(SpellDmgClass v, char const* label, char const* needle)
{
    if (!label)
        return true;

    UnknownLabelWarn(label);
    return false;
}

bool SearchTraits<SpellPreventionType, void>::CheckLabel(SpellPreventionType v, char const* label, char const* needle)
{
    if (!label)
        return true;

    UnknownLabelWarn(label);
    return false;
}

uint32 SearchTraits<SpellRuneCostEntry const*, void>::ToKey(SpellRuneCostEntry const* entry) { return entry->ID; }
std::string SearchTraits<SpellRuneCostEntry const*, void>::GetTitle(SpellRuneCostEntry const* entry)
{
    if (!entry)
        return "<none>";
    std::stringstream v;
    if (entry->NoRuneCost())
        v << "<no runes>";
    else
    {
        if (uint32 blood = entry->RuneCost[0])
            v << blood << " blood, ";
        if (uint32 frost = entry->RuneCost[1])
            v << frost << " frost, ";
        if (uint32 unholy = entry->RuneCost[2])
            v << unholy << " unholy, ";
        v.seekp(-2, std::ios_base::end); // overwrite trailing ', '
    }

    v << " (+" << entry->runePowerGain << " RP)";
    return v.str();
}
bool SearchTraits<SpellRuneCostEntry const*, void>::CheckLabel(SpellRuneCostEntry const* entry, char const* label, char const* needle)
{
    if (!label)
        return StringContainsStringI(GetTitle(entry), needle);
    if (*label == 'b' || *label == 'B')
        return ArithmeticCheck(needle, entry->RuneCost[0]);
    if (*label == 'f' || *label == 'F')
        return ArithmeticCheck(needle, entry->RuneCost[1]);
    if (*label == 'u' || *label == 'U')
        return ArithmeticCheck(needle, entry->RuneCost[2]);
    if (*label == 'r' || *label == 'R')
        return ArithmeticCheck(needle, entry->runePowerGain);

    UnknownLabelWarn(label);
    return false;
}

uint32 SearchTraits<SpellCastTimesEntry const*, void>::ToKey(SpellCastTimesEntry const* entry) { return entry->ID; }
std::string SearchTraits<SpellCastTimesEntry const*, void>::GetTitle(SpellCastTimesEntry const* entry) { return Trinity::StringFormat("%.3f seconds", double(entry->CastTime)/1000); }
bool SearchTraits<SpellCastTimesEntry const*, void>::CheckLabel(SpellCastTimesEntry const* entry, char const* label, char const* needle)
{
    if (!label)
        return ArithmeticCheck(needle, double(entry->CastTime)/1000);

    UnknownLabelWarn(label);
    return false;
}

bool SearchTraits<SpellEffects, void>::CheckLabel(SpellEffects e, char const* label, char const* needle) { return false; }

