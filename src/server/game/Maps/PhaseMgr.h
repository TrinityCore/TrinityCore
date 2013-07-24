/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

#ifndef TRINITY_PHASEMGR_H
#define TRINITY_PHASEMGR_H

#include "SharedDefines.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "ConditionMgr.h"

class ObjectMgr;
class Player;

// Phasing (visibility)
enum PhasingFlags
{
    PHASE_FLAG_OVERWRITE_EXISTING           = 0x01,       // don't stack with existing phases, overwrites existing phases
    PHASE_FLAG_NO_MORE_PHASES               = 0x02,       // stop calculating phases after this phase was applied (no more phases will be applied)
    PHASE_FLAG_NEGATE_PHASE                 = 0x04        // negate instead to add the phasemask
};

enum PhaseUpdateFlag
{
    PHASE_UPDATE_FLAG_ZONE_UPDATE           = 0x01,
    PHASE_UPDATE_FLAG_AREA_UPDATE           = 0x02,

    // Internal flags
    PHASE_UPDATE_FLAG_CLIENTSIDE_CHANGED    = 0x08,
    PHASE_UPDATE_FLAG_SERVERSIDE_CHANGED    = 0x10,
};

struct PhaseDefinition
{
    uint32 zoneId;
    uint32 entry;
    uint32 phasemask;
    uint32 phaseId;
    uint32 terrainswapmap;
    uint8 flags;

    bool IsOverwritingExistingPhases() const { return flags & PHASE_FLAG_OVERWRITE_EXISTING; }
    bool IsLastDefinition() const { return flags & PHASE_FLAG_NO_MORE_PHASES; }
    bool IsNegatingPhasemask() const { return flags & PHASE_FLAG_NEGATE_PHASE; }
};

typedef std::list<PhaseDefinition> PhaseDefinitionContainer;
typedef UNORDERED_MAP<uint32 /*zoneId*/, PhaseDefinitionContainer> PhaseDefinitionStore;

struct SpellPhaseInfo
{
    uint32 spellId;
    uint32 phasemask;
    uint32 terrainswapmap;
};

typedef UNORDERED_MAP<uint32 /*spellId*/, SpellPhaseInfo> SpellPhaseStore;

struct PhaseInfo
{
    PhaseInfo() : phasemask(0), terrainswapmap(0), phaseId(0) {}

    uint32 phasemask;
    uint32 terrainswapmap;
    uint32 phaseId;

    bool NeedsServerSideUpdate() const { return phasemask; }
    bool NeedsClientSideUpdate() const { return terrainswapmap || phaseId; }
};

typedef UNORDERED_MAP<uint32 /*spellId*/, PhaseInfo> PhaseInfoContainer;

struct PhaseData
{
    PhaseData(Player* _player) : _PhasemaskThroughDefinitions(0), _PhasemaskThroughAuras(0), _CustomPhasemask(0), player(_player) {}

    uint32 _PhasemaskThroughDefinitions;
    uint32 _PhasemaskThroughAuras;
    uint32 _CustomPhasemask;

    uint32 GetCurrentPhasemask() const;
    inline uint32 GetPhaseMaskForSpawn() const;

    void ResetDefinitions() { _PhasemaskThroughDefinitions = 0; activePhaseDefinitions.clear(); }
    void AddPhaseDefinition(PhaseDefinition const* phaseDefinition);
    bool HasActiveDefinitions() const { return !activePhaseDefinitions.empty(); }

    void AddAuraInfo(uint32 spellId, PhaseInfo const& phaseInfo);
    uint32 RemoveAuraInfo(uint32 spellId);

    void SendPhaseMaskToPlayer();
    void SendPhaseshiftToPlayer();

private:
    Player* player;
    std::list<PhaseDefinition const*> activePhaseDefinitions;
    PhaseInfoContainer spellPhaseInfo;
};

struct PhaseUpdateData
{
    PhaseUpdateData(): _conditionTypeFlags(0), _questId(0) { }
    void AddConditionType(ConditionTypes const conditionType) { _conditionTypeFlags |= (1 << conditionType); }
    void AddQuestUpdate(uint32 const questId);

    bool IsConditionRelated(Condition const* condition) const;

private:
    uint32 _conditionTypeFlags;
    uint32 _questId;
};

class PhaseMgr
{
public:
    PhaseMgr(Player* _player);
    ~PhaseMgr() {}

    uint32 GetCurrentPhasemask() { return phaseData.GetCurrentPhasemask(); };
    inline uint32 GetPhaseMaskForSpawn() { return phaseData.GetCurrentPhasemask(); }

    // Phase definitions update handling
    void NotifyConditionChanged(PhaseUpdateData const& updateData);
    void NotifyStoresReloaded() { Recalculate(); Update(); }

    void Update();

    // Aura phase effects
    void RegisterPhasingAuraEffect(AuraEffect const* auraEffect);
    void UnRegisterPhasingAuraEffect(AuraEffect const* auraEffect);

    // Update flags (delayed phasing)
    void AddUpdateFlag(PhaseUpdateFlag updateFlag) { _UpdateFlags |= updateFlag; }
    void RemoveUpdateFlag(PhaseUpdateFlag updateFlag);

    // Needed for modify phase command
    void SetCustomPhase(uint32 phaseMask);

    // Debug
    void SendDebugReportToPlayer(Player* const debugger);

    static bool IsConditionTypeSupported(ConditionTypes conditionType);

private:
    void Recalculate();

    inline bool CheckDefinition(PhaseDefinition const* phaseDefinition);

    bool NeedsPhaseUpdateWithData(PhaseUpdateData const& updateData) const;

    inline bool IsUpdateInProgress() const { return (_UpdateFlags & PHASE_UPDATE_FLAG_ZONE_UPDATE) || (_UpdateFlags & PHASE_UPDATE_FLAG_AREA_UPDATE); }

    PhaseDefinitionStore const* _PhaseDefinitionStore;
    SpellPhaseStore const* _SpellPhaseStore;

    Player* player;
    PhaseData phaseData;
    uint8 _UpdateFlags;
};

#endif
