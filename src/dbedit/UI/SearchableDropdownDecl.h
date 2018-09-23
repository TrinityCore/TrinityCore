#ifndef TRINITY_DBEDIT_SEARCHABLEDROPDOWNDECL_H
#define TRINITY_DBEDIT_SEARCHABLEDROPDOWNDECL_H

#include "SearchTraits.h"

template <typename C, typename T = SearchTraits<C>>
class SearchableDropdown;

enum Powers : int8;
enum SpellDmgClass;
enum SpellEffects;
enum SpellFamilyNames;
enum SpellPreventionType;
struct SpellCastTimesEntry;
struct SpellRuneCostEntry;

typedef SearchableDropdown<Powers> PowerTypeDropdown;
typedef SearchableDropdown<SpellDmgClass> SpellDamageClassDropdown;
typedef SearchableDropdown<SpellEffects> SpellEffectsDropdown;
typedef SearchableDropdown<SpellFamilyNames> SpellFamilyDropdown;
typedef SearchableDropdown<SpellPreventionType> SpellPreventionTypeDropdown;
typedef SearchableDropdown<SpellCastTimesEntry const*> SpellCastTimeDropdown;
typedef SearchableDropdown<SpellRuneCostEntry const*> RuneCostDropdown;

#endif
