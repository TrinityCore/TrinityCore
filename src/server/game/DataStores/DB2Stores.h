/*
 * Copyright (C) 2011 TrintiyCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TRINITY_DB2STORES_H
#define TRINITY_DB2STORES_H

#include "DB2Store.h"
#include "DB2Structure.h"
#include <string>
#include <map>

extern DB2Storage<HolidaysEntry>                sHolidaysStore;
extern DB2Storage<ItemEntry>                    sItemStore;
extern DB2Storage<ItemAppearanceEntry>          sItemAppearanceStore;
extern DB2Storage<ItemCurrencyCostEntry>        sItemCurrencyCostStore;
extern DB2Storage<ItemExtendedCostEntry>        sItemExtendedCostStore;
extern DB2Storage<ItemEffectEntry>              sItemEffectStore;
extern DB2Storage<ItemSparseEntry>              sItemSparseStore;
extern DB2Storage<KeyChainEntry>                sKeyChainStore;
extern DB2Storage<OverrideSpellDataEntry>       sOverrideSpellDataStore;
extern DB2Storage<PhaseGroupEntry>              sPhaseGroupStore;
extern DB2Storage<SpellAuraRestrictionsEntry>   sSpellAuraRestrictionsStore;
extern DB2Storage<SpellCastingRequirementsEntry> sSpellCastingRequirementsStore;
extern DB2Storage<SpellClassOptionsEntry>       sSpellClassOptionsStore;
extern DB2Storage<SpellMiscEntry>               sSpellMiscStore;
extern DB2Storage<SpellPowerEntry>              sSpellPowerStore;
extern SpellPowerBySpellIDMap                   sSpellPowerBySpellIDStore;
extern DB2Storage<SpellReagentsEntry>           sSpellReagentsStore;
extern DB2Storage<SpellRuneCostEntry>           sSpellRuneCostStore;
extern DB2Storage<SpellTotemsEntry>             sSpellTotemsStore;
extern DB2Storage<TaxiNodesEntry>               sTaxiNodesStore;
extern DB2Storage<TaxiPathEntry>                sTaxiPathStore;
extern DB2Storage<TaxiPathNodeEntry>            sTaxiPathNodeStore;
extern TaxiMask                                 sTaxiNodesMask;
extern TaxiMask                                 sOldContinentsNodesMask;
extern TaxiMask                                 sHordeTaxiNodesMask;
extern TaxiMask                                 sAllianceTaxiNodesMask;
extern TaxiMask                                 sDeathKnightTaxiNodesMask;
extern TaxiPathSetBySource                      sTaxiPathSetBySource;
extern TaxiPathNodesByPath                      sTaxiPathNodesByPath;

void LoadDB2Stores(std::string const& dataPath);

DB2StorageBase const* GetDB2Storage(uint32 type);

std::set<uint32> const& GetPhasesForGroup(uint32 group);

#endif
