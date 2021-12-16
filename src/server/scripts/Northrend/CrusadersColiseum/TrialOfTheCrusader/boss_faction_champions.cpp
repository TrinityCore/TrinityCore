/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "ScriptMgr.h"
#include "GridNotifiers.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "trial_of_the_crusader.h"

enum AIs
{
    AI_MELEE    = 0,
    AI_RANGED   = 1,
    AI_HEALER   = 2,
    AI_PET      = 3
};

enum Spells
{
    // generic
    SPELL_ANTI_AOE                  = 68595,
    SPELL_PVP_TRINKET               = 65547,

    // druid healer
    SPELL_LIFEBLOOM                 = 66093,
    SPELL_NOURISH                   = 66066,
    SPELL_REGROWTH                  = 66067,
    SPELL_REJUVENATION              = 66065,
    SPELL_TRANQUILITY               = 66086,
    SPELL_BARKSKIN                  = 65860,
    SPELL_THORNS                    = 66068,
    SPELL_NATURE_GRASP              = 66071,

    // shaman healer
    SPELL_HEALING_WAVE              = 66055,
    SPELL_RIPTIDE                   = 66053,
    SPELL_SPIRIT_CLEANSE            = 66056, //friendly only
    SPELL_HEROISM                   = 65983,
    SPELL_BLOODLUST                 = 65980,
    SPELL_HEX                       = 66054,
    SPELL_EARTH_SHIELD              = 66063,
    SPELL_EARTH_SHOCK               = 65973,
    AURA_EXHAUSTION                 = 57723,
    AURA_SATED                      = 57724,

    // paladin healer
    SPELL_HAND_OF_FREEDOM           = 68757,
    SPELL_DIVINE_SHIELD             = 66010,
    SPELL_CLEANSE                   = 66116,
    SPELL_FLASH_OF_LIGHT            = 66113,
    SPELL_HOLY_LIGHT                = 66112,
    SPELL_HOLY_SHOCK                = 66114,
    SPELL_HAND_OF_PROTECTION        = 66009,
    SPELL_HAMMER_OF_JUSTICE         = 66613,
    SPELL_FORBEARANCE               = 25771,

    // priest healer
    SPELL_RENEW                     = 66177,
    SPELL_SHIELD                    = 66099,
    SPELL_FLASH_HEAL                = 66104,
    SPELL_DISPEL                    = 65546,
    SPELL_PSYCHIC_SCREAM            = 65543,
    SPELL_MANA_BURN                 = 66100,
    SPELL_PENANCE                   = 66097,

    // priest dps
    SPELL_SILENCE                   = 65542,
    SPELL_VAMPIRIC_TOUCH            = 65490,
    SPELL_SW_PAIN                   = 65541,
    SPELL_MIND_FLAY                 = 65488,
    SPELL_MIND_BLAST                = 65492,
    SPELL_HORROR                    = 65545,
    SPELL_DISPERSION                = 65544,
    SPELL_SHADOWFORM                = 16592,

    // warlock
    SPELL_HELLFIRE                   = 65816,
    SPELL_CORRUPTION                 = 65810,
    SPELL_CURSE_OF_AGONY             = 65814,
    SPELL_CURSE_OF_EXHAUSTION        = 65815,
    SPELL_FEAR                       = 65809,
    SPELL_SEARING_PAIN               = 65819,
    SPELL_SHADOW_BOLT                = 65821,
    SPELL_UNSTABLE_AFFLICTION        = 65812,
    SPELL_UNSTABLE_AFFLICTION_DISPEL = 65813,
    SPELL_SUMMON_FELHUNTER           = 67514,

    // mage
    SPELL_ARCANE_BARRAGE            = 65799,
    SPELL_ARCANE_BLAST              = 65791,
    SPELL_ARCANE_EXPLOSION          = 65800,
    SPELL_BLINK                     = 65793,
    SPELL_COUNTERSPELL              = 65790,
    SPELL_FROST_NOVA                = 65792,
    SPELL_FROSTBOLT                 = 65807,
    SPELL_ICE_BLOCK                 = 65802,
    SPELL_POLYMORPH                 = 65801,

    // hunter
    SPELL_AIMED_SHOT                = 65883,
    SPELL_DETERRENCE                = 65871,
    SPELL_DISENGAGE                 = 65869,
    SPELL_EXPLOSIVE_SHOT            = 65866,
    SPELL_FROST_TRAP                = 65880,
    SPELL_SHOOT                     = 65868,
    SPELL_STEADY_SHOT               = 65867,
    SPELL_WING_CLIP                 = 66207,
    SPELL_WYVERN_STING              = 65877,
    SPELL_CALL_PET                  = 67777,

    // druid dps
    SPELL_CYCLONE                   = 65859,
    SPELL_ENTANGLING_ROOTS          = 65857,
    SPELL_FAERIE_FIRE               = 65863,
    SPELL_FORCE_OF_NATURE           = 65861,
    SPELL_INSECT_SWARM              = 65855,
    SPELL_MOONFIRE                  = 65856,
    SPELL_STARFIRE                  = 65854,
    SPELL_WRATH                     = 65862,

    // warrior
    SPELL_BLADESTORM                = 65947,
    SPELL_INTIMIDATING_SHOUT        = 65930,
    SPELL_MORTAL_STRIKE             = 65926,
    SPELL_CHARGE                    = 68764,
    SPELL_DISARM                    = 65935,
    SPELL_OVERPOWER                 = 65924,
    SPELL_SUNDER_ARMOR              = 65936,
    SPELL_SHATTERING_THROW          = 65940,
    SPELL_RETALIATION               = 65932,

    // death knight
    SPELL_CHAINS_OF_ICE             = 66020,
    SPELL_DEATH_COIL                = 66019,
    SPELL_DEATH_GRIP                = 66017,
    SPELL_FROST_STRIKE              = 66047,
    SPELL_ICEBOUND_FORTITUDE        = 66023,
    SPELL_ICY_TOUCH                 = 66021,
    SPELL_STRANGULATE               = 66018,
    SPELL_DEATH_GRIP_PULL           = 64431,    // used at spellscript

    // rogue
    SPELL_FAN_OF_KNIVES             = 65955,
    SPELL_BLIND                     = 65960,
    SPELL_CLOAK                     = 65961,
    SPELL_BLADE_FLURRY              = 65956,
    SPELL_SHADOWSTEP                = 66178,
    SPELL_HEMORRHAGE                = 65954,
    SPELL_EVISCERATE                = 65957,
    SPELL_WOUND_POISON              = 65962,

    // shaman dps (some spells taken from shaman healer)
    SPELL_LAVA_LASH                 = 65974,
    SPELL_STORMSTRIKE               = 65970,
    SPELL_WINDFURY                  = 65976,

    // paladin dps
    SPELL_AVENGING_WRATH            = 66011,
    SPELL_CRUSADER_STRIKE           = 66003,
    SPELL_DIVINE_STORM              = 66006,
    SPELL_HAMMER_OF_JUSTICE_RET     = 66007,
    SPELL_JUDGEMENT_OF_COMMAND      = 66005,
    SPELL_REPENTANCE                = 66008,
    SPELL_SEAL_OF_COMMAND           = 66004,

    // warlock pet
    SPELL_DEVOUR_MAGIC              = 67518,
    SPELL_SPELL_LOCK                = 67519,

    // hunter pet
    SPELL_CLAW                      = 67793
};

enum Events
{
    // generic
    EVENT_THREAT                    = 1,
    EVENT_REMOVE_CC                 = 2,

    // druid healer
    EVENT_LIFEBLOOM                 = 1,
    EVENT_NOURISH                   = 2,
    EVENT_REGROWTH                  = 3,
    EVENT_REJUVENATION              = 4,
    EVENT_TRANQUILITY               = 5,
    EVENT_HEAL_BARKSKIN             = 6,
    EVENT_THORNS                    = 7,
    EVENT_NATURE_GRASP              = 8,

    // shaman healer
    EVENT_HEALING_WAVE              = 1,
    EVENT_RIPTIDE                   = 2,
    EVENT_SPIRIT_CLEANSE            = 3,
    EVENT_HEAL_BLOODLUST_HEROISM    = 4,
    EVENT_HEX                       = 5,
    EVENT_EARTH_SHIELD              = 6,
    EVENT_HEAL_EARTH_SHOCK          = 7,

    // paladin healer
    EVENT_HAND_OF_FREEDOM           = 1,
    EVENT_HEAL_DIVINE_SHIELD        = 2,
    EVENT_CLEANSE                   = 3,
    EVENT_FLASH_OF_LIGHT            = 4,
    EVENT_HOLY_LIGHT                = 5,
    EVENT_HOLY_SHOCK                = 6,
    EVENT_HEAL_HAND_OF_PROTECTION   = 7,
    EVENT_HAMMER_OF_JUSTICE         = 8,

    // priest healer
    EVENT_RENEW                     = 1,
    EVENT_SHIELD                    = 2,
    EVENT_FLASH_HEAL                = 3,
    EVENT_HEAL_DISPEL               = 4,
    EVENT_HEAL_PSYCHIC_SCREAM       = 5,
    EVENT_MANA_BURN                 = 6,
    EVENT_PENANCE                   = 7,

    // priest dps
    EVENT_SILENCE                   = 1,
    EVENT_VAMPIRIC_TOUCH            = 2,
    EVENT_SW_PAIN                   = 3,
    EVENT_MIND_BLAST                = 4,
    EVENT_HORROR                    = 5,
    EVENT_DISPERSION                = 6,
    EVENT_DPS_DISPEL                = 7,
    EVENT_DPS_PSYCHIC_SCREAM        = 8,

    // warlock
    EVENT_HELLFIRE                  = 1,
    EVENT_CORRUPTION                = 2,
    EVENT_CURSE_OF_AGONY            = 3,
    EVENT_CURSE_OF_EXHAUSTION       = 4,
    EVENT_FEAR                      = 5,
    EVENT_SEARING_PAIN              = 6,
    EVENT_UNSTABLE_AFFLICTION       = 7,

    // mage
    EVENT_ARCANE_BARRAGE            = 1,
    EVENT_ARCANE_BLAST              = 2,
    EVENT_ARCANE_EXPLOSION          = 3,
    EVENT_BLINK                     = 4,
    EVENT_COUNTERSPELL              = 5,
    EVENT_FROST_NOVA                = 6,
    EVENT_ICE_BLOCK                 = 7,
    EVENT_POLYMORPH                 = 8,

    // hunter
    EVENT_AIMED_SHOT                = 1,
    EVENT_DETERRENCE                = 2,
    EVENT_DISENGAGE                 = 3,
    EVENT_EXPLOSIVE_SHOT            = 4,
    EVENT_FROST_TRAP                = 5,
    EVENT_STEADY_SHOT               = 6,
    EVENT_WING_CLIP                 = 7,
    EVENT_WYVERN_STING              = 8,

    // druid dps
    EVENT_CYCLONE                   = 1,
    EVENT_ENTANGLING_ROOTS          = 2,
    EVENT_FAERIE_FIRE               = 3,
    EVENT_FORCE_OF_NATURE           = 4,
    EVENT_INSECT_SWARM              = 5,
    EVENT_MOONFIRE                  = 6,
    EVENT_STARFIRE                  = 7,
    EVENT_DPS_BARKSKIN              = 8,

    // warrior
    EVENT_BLADESTORM                = 1,
    EVENT_INTIMIDATING_SHOUT        = 2,
    EVENT_MORTAL_STRIKE             = 3,
    EVENT_WARR_CHARGE               = 4,
    EVENT_DISARM                    = 5,
    EVENT_OVERPOWER                 = 6,
    EVENT_SUNDER_ARMOR              = 7,
    EVENT_SHATTERING_THROW          = 8,
    EVENT_RETALIATION               = 9,

    // death knight
    EVENT_CHAINS_OF_ICE             = 1,
    EVENT_DEATH_COIL                = 2,
    EVENT_DEATH_GRIP                = 3,
    EVENT_FROST_STRIKE              = 4,
    EVENT_ICEBOUND_FORTITUDE        = 5,
    EVENT_ICY_TOUCH                 = 6,
    EVENT_STRANGULATE               = 7,

    // rogue
    EVENT_FAN_OF_KNIVES             = 1,
    EVENT_BLIND                     = 2,
    EVENT_CLOAK                     = 3,
    EVENT_BLADE_FLURRY              = 4,
    EVENT_SHADOWSTEP                = 5,
    EVENT_HEMORRHAGE                = 6,
    EVENT_EVISCERATE                = 7,
    EVENT_WOUND_POISON              = 8,

    // shaman dps
    EVENT_DPS_EARTH_SHOCK           = 1,
    EVENT_LAVA_LASH                 = 2,
    EVENT_STORMSTRIKE               = 3,
    EVENT_DPS_BLOODLUST_HEROISM     = 4,
    EVENT_DEPLOY_TOTEM              = 5,
    EVENT_WINDFURY                  = 6,

    // paladin dps
    EVENT_AVENGING_WRATH            = 1,
    EVENT_CRUSADER_STRIKE           = 2,
    EVENT_DIVINE_STORM              = 3,
    EVENT_HAMMER_OF_JUSTICE_RET     = 4,
    EVENT_JUDGEMENT_OF_COMMAND      = 5,
    EVENT_REPENTANCE                = 6,
    EVENT_DPS_HAND_OF_PROTECTION    = 7,
    EVENT_DPS_DIVINE_SHIELD         = 8,

    // warlock pet
    EVENT_DEVOUR_MAGIC              = 1,
    EVENT_SPELL_LOCK                = 2
};

Position const FactionChampionLoc[] =
{
    { 514.231f, 105.569f, 418.234f, 0 },               //  0 - Horde Initial Pos 0
    { 508.334f, 115.377f, 418.234f, 0 },               //  1 - Horde Initial Pos 1
    { 506.454f, 126.291f, 418.234f, 0 },               //  2 - Horde Initial Pos 2
    { 506.243f, 106.596f, 421.592f, 0 },               //  3 - Horde Initial Pos 3
    { 499.885f, 117.717f, 421.557f, 0 },               //  4 - Horde Initial Pos 4

    { 613.127f, 100.443f, 419.74f, 0 },                //  5 - Ally Initial Pos 0
    { 621.126f, 128.042f, 418.231f, 0 },               //  6 - Ally Initial Pos 1
    { 618.829f, 113.606f, 418.232f, 0 },               //  7 - Ally Initial Pos 2
    { 625.845f, 112.914f, 421.575f, 0 },               //  8 - Ally Initial Pos 3
    { 615.566f, 109.653f, 418.234f, 0 },               //  9 - Ally Initial Pos 4

    { 535.469f, 113.012f, 394.66f, 0 },                // 10 - Horde Final Pos 0
    { 526.417f, 137.465f, 394.749f, 0 },               // 11 - Horde Final Pos 1
    { 528.108f, 111.057f, 395.289f, 0 },               // 12 - Horde Final Pos 2
    { 519.92f, 134.285f, 395.289f, 0 },                // 13 - Horde Final Pos 3
    { 533.648f, 119.148f, 394.646f, 0 },               // 14 - Horde Final Pos 4
    { 531.399f, 125.63f, 394.708f, 0 },                // 15 - Horde Final Pos 5
    { 528.958f, 131.47f, 394.73f, 0 },                 // 16 - Horde Final Pos 6
    { 526.309f, 116.667f, 394.833f, 0 },               // 17 - Horde Final Pos 7
    { 524.238f, 122.411f, 394.819f, 0 },               // 18 - Horde Final Pos 8
    { 521.901f, 128.488f, 394.832f, 0 }                // 19 - Horde Final Pos 9
};

struct boss_toc_champion_controller : public BossAI
{
    boss_toc_champion_controller(Creature* creature) : BossAI(creature, DATA_FACTION_CRUSADERS)
    {
        Initialize();
    }

    void Initialize()
    {
        _championsNotStarted = 0;
        _championsFailed = 0;
        _championsKilled = 0;
        _inProgress = false;
    }

    void Reset() override
    {
        Initialize();
    }

    void JustSummoned(Creature* /*summon*/) override { }

    std::vector<uint32> SelectChampions(Team playerTeam)
    {
        std::vector<uint32> vHealersEntries;
        vHealersEntries.clear();
        vHealersEntries.push_back(playerTeam == ALLIANCE ? NPC_HORDE_DRUID_RESTORATION : NPC_ALLIANCE_DRUID_RESTORATION);
        vHealersEntries.push_back(playerTeam == ALLIANCE ? NPC_HORDE_PALADIN_HOLY : NPC_ALLIANCE_PALADIN_HOLY);
        vHealersEntries.push_back(playerTeam == ALLIANCE ? NPC_HORDE_PRIEST_DISCIPLINE : NPC_ALLIANCE_PRIEST_DISCIPLINE);
        vHealersEntries.push_back(playerTeam == ALLIANCE ? NPC_HORDE_SHAMAN_RESTORATION : NPC_ALLIANCE_SHAMAN_RESTORATION);

        std::vector<uint32> vOtherEntries;
        vOtherEntries.clear();
        vOtherEntries.push_back(playerTeam == ALLIANCE ? NPC_HORDE_DEATH_KNIGHT : NPC_ALLIANCE_DEATH_KNIGHT);
        vOtherEntries.push_back(playerTeam == ALLIANCE ? NPC_HORDE_HUNTER : NPC_ALLIANCE_HUNTER);
        vOtherEntries.push_back(playerTeam == ALLIANCE ? NPC_HORDE_MAGE : NPC_ALLIANCE_MAGE);
        vOtherEntries.push_back(playerTeam == ALLIANCE ? NPC_HORDE_ROGUE : NPC_ALLIANCE_ROGUE);
        vOtherEntries.push_back(playerTeam == ALLIANCE ? NPC_HORDE_WARLOCK : NPC_ALLIANCE_WARLOCK);
        vOtherEntries.push_back(playerTeam == ALLIANCE ? NPC_HORDE_WARRIOR : NPC_ALLIANCE_WARRIOR);

        uint8 healersSubtracted = 2;
        if (instance->instance->GetSpawnMode() == RAID_DIFFICULTY_25MAN_NORMAL || instance->instance->GetSpawnMode() == RAID_DIFFICULTY_25MAN_HEROIC)
            healersSubtracted = 1;
        for (uint8 i = 0; i < healersSubtracted; ++i)
        {
            uint8 pos = urand(0, vHealersEntries.size() - 1);
            switch (vHealersEntries[pos])
            {
                case NPC_ALLIANCE_DRUID_RESTORATION:
                    vOtherEntries.push_back(NPC_ALLIANCE_DRUID_BALANCE);
                    break;
                case NPC_HORDE_DRUID_RESTORATION:
                    vOtherEntries.push_back(NPC_HORDE_DRUID_BALANCE);
                    break;
                case NPC_ALLIANCE_PALADIN_HOLY:
                    vOtherEntries.push_back(NPC_ALLIANCE_PALADIN_RETRIBUTION);
                    break;
                case NPC_HORDE_PALADIN_HOLY:
                    vOtherEntries.push_back(NPC_HORDE_PALADIN_RETRIBUTION);
                    break;
                case NPC_ALLIANCE_PRIEST_DISCIPLINE:
                    vOtherEntries.push_back(NPC_ALLIANCE_PRIEST_SHADOW);
                    break;
                case NPC_HORDE_PRIEST_DISCIPLINE:
                    vOtherEntries.push_back(NPC_HORDE_PRIEST_SHADOW);
                    break;
                case NPC_ALLIANCE_SHAMAN_RESTORATION:
                    vOtherEntries.push_back(NPC_ALLIANCE_SHAMAN_ENHANCEMENT);
                    break;
                case NPC_HORDE_SHAMAN_RESTORATION:
                    vOtherEntries.push_back(NPC_HORDE_SHAMAN_ENHANCEMENT);
                    break;
                default:
                    break;
            }
            vHealersEntries.erase(vHealersEntries.begin() + pos);
        }

        if (instance->instance->GetSpawnMode() == RAID_DIFFICULTY_10MAN_NORMAL || instance->instance->GetSpawnMode() == RAID_DIFFICULTY_10MAN_HEROIC)
            for (uint8 i = 0; i < 4; ++i)
                vOtherEntries.erase(vOtherEntries.begin() + urand(0, vOtherEntries.size() - 1));

        std::vector<uint32> vChampionEntries;
        vChampionEntries.clear();
        for (uint8 i = 0; i < vHealersEntries.size(); ++i)
            vChampionEntries.push_back(vHealersEntries[i]);
        for (uint8 i = 0; i < vOtherEntries.size(); ++i)
            vChampionEntries.push_back(vOtherEntries[i]);

        return vChampionEntries;
    }

    void SummonChampions(Team playerTeam)
    {
        std::vector<Position> vChampionJumpOrigin;
        if (playerTeam == ALLIANCE)
            for (uint8 i = 0; i < 5; i++)
                vChampionJumpOrigin.push_back(FactionChampionLoc[i]);
        else
            for (uint8 i = 5; i < 10; i++)
                vChampionJumpOrigin.push_back(FactionChampionLoc[i]);

        std::vector<Position> vChampionJumpTarget;
        for (uint8 i = 10; i < 20; i++)
            vChampionJumpTarget.push_back(FactionChampionLoc[i]);
        std::vector<uint32> vChampionEntries = SelectChampions(playerTeam);

        for (uint8 i = 0; i < vChampionEntries.size(); ++i)
        {
            uint8 pos = urand(0, vChampionJumpTarget.size()-1);
            if (Creature* champion = me->SummonCreature(vChampionEntries[i], vChampionJumpOrigin[urand(0, vChampionJumpOrigin.size()-1)], TEMPSUMMON_MANUAL_DESPAWN))
            {
                summons.Summon(champion);
                champion->SetReactState(REACT_PASSIVE);
                champion->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                champion->SetImmuneToPC(false);
                if (playerTeam == ALLIANCE)
                {
                    champion->SetHomePosition(vChampionJumpTarget[pos].GetPositionX(), vChampionJumpTarget[pos].GetPositionY(), vChampionJumpTarget[pos].GetPositionZ(), 0);
                    champion->GetMotionMaster()->MoveJump(vChampionJumpTarget[pos], 20.0f, 20.0f);
                    champion->SetOrientation(0);
                }
                else
                {
                    champion->SetHomePosition((ToCCommonLoc[1].GetPositionX()*2)-vChampionJumpTarget[pos].GetPositionX(), vChampionJumpTarget[pos].GetPositionY(), vChampionJumpTarget[pos].GetPositionZ(), 3);
                    champion->GetMotionMaster()->MoveJump((ToCCommonLoc[1].GetPositionX() * 2) - vChampionJumpTarget[pos].GetPositionX(), vChampionJumpTarget[pos].GetPositionY(), vChampionJumpTarget[pos].GetPositionZ(), vChampionJumpTarget[pos].GetOrientation(), 20.0f, 20.0f);
                    champion->SetOrientation(3);
                }
            }
            vChampionJumpTarget.erase(vChampionJumpTarget.begin()+pos);
        }
    }

    void SetData(uint32 uiType, uint32 uiData) override
    {
        switch (uiType)
        {
            case 0:
                SummonChampions((Team)uiData);
                break;
            case 1:
                for (SummonList::iterator i = summons.begin(); i != summons.end(); ++i)
                {
                    if (Creature* summon = ObjectAccessor::GetCreature(*me, *i))
                    {
                        summon->SetReactState(REACT_AGGRESSIVE);
                        summon->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        summon->SetImmuneToPC(false);
                    }
                }
                break;
            case 2:
                switch (uiData)
                {
                    case FAIL:
                        _championsFailed++;
                        if (_championsFailed + _championsKilled >= summons.size())
                        {
                            instance->SetBossState(DATA_FACTION_CRUSADERS, FAIL);
                            summons.DespawnAll();
                            me->DespawnOrUnsummon();
                        }
                        break;
                    case IN_PROGRESS:
                        if (!_inProgress)
                        {
                            _championsNotStarted = 0;
                            _championsFailed = 0;
                            _championsKilled = 0;
                            _inProgress = true;
                            summons.DoZoneInCombat();
                            instance->SetBossState(DATA_FACTION_CRUSADERS, IN_PROGRESS);
                        }
                        break;
                    case DONE:
                    {
                        _championsKilled++;
                        if (_championsKilled == 1)
                            instance->SetData(DATA_FACTION_CRUSADERS, 0); // Used in Resilience will Fix Achievement
                        else if (_championsKilled >= summons.size())
                        {
                            instance->SetBossState(DATA_FACTION_CRUSADERS, DONE);
                            summons.DespawnAll();
                            me->DespawnOrUnsummon();
                        }
                        break;
                    }
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }
    private:
        uint32 _championsNotStarted;
        uint32 _championsFailed;
        uint32 _championsKilled;
        bool   _inProgress;
};

struct boss_faction_championsAI : public BossAI
{
    boss_faction_championsAI(Creature* creature, uint32 aitype) : BossAI(creature, DATA_FACTION_CHAMPIONS), _teamInstance(0)
    {
        _aiType = aitype;
        SetBoundary(instance->GetBossBoundary(DATA_FACTION_CRUSADERS));
    }

    void Reset() override
    {
        _teamInstance = instance->GetData(DATA_TEAM);
        _events.ScheduleEvent(EVENT_THREAT, 5s);
        if (IsHeroic() && (_aiType != AI_PET))
            _events.ScheduleEvent(EVENT_REMOVE_CC, 5s);
    }

    void JustReachedHome() override
    {
        if (Creature* pChampionController = instance->GetCreature(DATA_FACTION_CRUSADERS))
            pChampionController->AI()->SetData(2, FAIL);
        me->DespawnOrUnsummon();
    }

    float CalculateThreat(float distance, float armor, uint32 health)
    {
        float dist_mod = (_aiType == AI_MELEE || _aiType == AI_PET) ? 15.0f / (15.0f + distance) : 1.0f;
        float armor_mod = (_aiType == AI_MELEE || _aiType == AI_PET) ? armor / 16635.0f : 0.0f;
        float eh = (health + 1) * (1.0f + armor_mod);
        return dist_mod * 30000.0f / eh;
    }

    void UpdateThreat()
    {
        for (ThreatReference* ref : me->GetThreatManager().GetModifiableThreatList())
            if (Player* victim = ref->GetVictim()->ToPlayer())
            {
                ref->ScaleThreat(0.0f);
                ref->AddThreat(1000000.0f * CalculateThreat(me->GetDistance2d(victim), victim->GetArmor(), victim->GetHealth()));
            }
    }

    void UpdatePower()
    {
        if (me->GetPowerType() == POWER_MANA)
            me->ModifyPower(POWER_MANA, me->GetMaxPower(POWER_MANA) / 3);
    }

    void RemoveCC()
    {
        me->RemoveAurasByType(SPELL_AURA_MOD_STUN);
        me->RemoveAurasByType(SPELL_AURA_MOD_FEAR);
        me->RemoveAurasByType(SPELL_AURA_MOD_ROOT);
        me->RemoveAurasByType(SPELL_AURA_MOD_PACIFY);
        me->RemoveAurasByType(SPELL_AURA_MOD_CONFUSE);
        //DoCast(me, SPELL_PVP_TRINKET);
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (_aiType != AI_PET)
            if (Creature* pChampionController = instance->GetCreature(DATA_FACTION_CRUSADERS))
                pChampionController->AI()->SetData(2, DONE);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        DoCast(me, SPELL_ANTI_AOE, true);
        me->SetCombatPulseDelay(5);
        me->setActive(true);
        DoZoneInCombat();
        if (Creature* pChampionController = instance->GetCreature(DATA_FACTION_CRUSADERS))
            pChampionController->AI()->SetData(2, IN_PROGRESS);
    }

    void KilledUnit(Unit* who) override
    {
        if (who->GetTypeId() == TYPEID_PLAYER)
        {
            if (_teamInstance == ALLIANCE)
            {
                if (Creature* varian = instance->GetCreature(DATA_VARIAN))
                    varian->AI()->DoAction(ACTION_SAY_KILLED_PLAYER);
            }
            else if (Creature* garrosh = instance->GetCreature(DATA_GARROSH))
                garrosh->AI()->DoAction(ACTION_SAY_KILLED_PLAYER);
        }
    }

    Creature* SelectRandomFriendlyMissingBuff(uint32 spell)
    {
        std::list<Creature*> lst = DoFindFriendlyMissingBuff(40.0f, spell);
        std::list<Creature*>::const_iterator itr = lst.begin();
        if (lst.empty())
            return nullptr;
        advance(itr, rand32() % lst.size());
        return (*itr);
    }

    Unit* SelectEnemyCaster(bool /*casting*/)
    {
        for (auto const& pair : me->GetCombatManager().GetPvECombatRefs())
            if (Player* player = pair.second->GetOther(me)->ToPlayer())
                if (player->GetPowerType() == POWER_MANA)
                    return player;
        return nullptr;
    }

    uint32 EnemiesInRange(float distance)
    {
        uint32 count = 0;
        for (ThreatReference const* ref : me->GetThreatManager().GetUnsortedThreatList())
            if (me->GetDistance2d(ref->GetVictim()) < distance)
                ++count;
        return count;
    }

    void AttackStart(Unit* who) override
    {
        if (!who)
            return;

        if (me->Attack(who, true))
        {
            AddThreat(who, 10.0f);

            if (_aiType == AI_MELEE || _aiType == AI_PET)
                DoStartMovement(who);
            else
                DoStartMovement(who, 20.0f);
            SetCombatMovement(true);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_THREAT:
                    UpdatePower();
                    UpdateThreat();
                    _events.ScheduleEvent(EVENT_THREAT, 4s);
                    return;
                case EVENT_REMOVE_CC:
                    if (me->HasBreakableByDamageCrowdControlAura())
                    {
                        RemoveCC();
                        _events.RescheduleEvent(EVENT_REMOVE_CC, 2min);
                    }
                    else
                        _events.RescheduleEvent(EVENT_REMOVE_CC, 3s);
                    return;
                default:
                    return;
            }
        }

        if (_aiType == AI_MELEE || _aiType == AI_PET)
            DoMeleeAttackIfReady();
    }

    private:
        uint32 _aiType;
        uint32 _teamInstance;
        // make sure that every bosses separate events dont mix with these _events
        EventMap _events;
};

/********************************************************************
                            HEALERS
********************************************************************/
struct npc_toc_druid : public boss_faction_championsAI
{
    npc_toc_druid(Creature* creature) : boss_faction_championsAI(creature, AI_HEALER) { }

    void Reset() override
    {
        boss_faction_championsAI::Reset();
        events.ScheduleEvent(EVENT_LIFEBLOOM, 5s, 15s);
        events.ScheduleEvent(EVENT_NOURISH, 5s, 15s);
        events.ScheduleEvent(EVENT_REGROWTH, 5s, 15s);
        events.ScheduleEvent(EVENT_REJUVENATION, 5s, 15s);
        events.ScheduleEvent(EVENT_TRANQUILITY, 5s, 20s);
        events.ScheduleEvent(EVENT_HEAL_BARKSKIN, 15s, 25s);
        events.ScheduleEvent(EVENT_THORNS, 2s);
        events.ScheduleEvent(EVENT_NATURE_GRASP, 3s, 20s);
        SetEquipmentSlots(false, 51799, EQUIP_NO_CHANGE, EQUIP_NO_CHANGE);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);
        boss_faction_championsAI::UpdateAI(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_LIFEBLOOM:
                    if (Unit* target = DoSelectLowestHpFriendly(40.0f))
                        DoCast(target, SPELL_LIFEBLOOM);
                    events.ScheduleEvent(EVENT_LIFEBLOOM, 5s, 15s);
                    return;
                case EVENT_NOURISH:
                    if (Unit* target = DoSelectLowestHpFriendly(40.0f))
                        DoCast(target, SPELL_NOURISH);
                    events.ScheduleEvent(EVENT_NOURISH, 5s, 15s);
                    return;
                case EVENT_REGROWTH:
                    if (Unit* target = DoSelectLowestHpFriendly(40.0f))
                        DoCast(target, SPELL_REGROWTH);
                    events.ScheduleEvent(EVENT_REGROWTH, 5s, 15s);
                    return;
                case EVENT_REJUVENATION:
                    if (Unit* target = DoSelectLowestHpFriendly(40.0f))
                        DoCast(target, SPELL_REJUVENATION);
                    events.ScheduleEvent(EVENT_REJUVENATION, 5s, 15s);
                    return;
                case EVENT_TRANQUILITY:
                    DoCastAOE(SPELL_TRANQUILITY);
                    events.ScheduleEvent(EVENT_TRANQUILITY, 15s, 40s);
                    return;
                case EVENT_HEAL_BARKSKIN:
                    if (HealthBelowPct(30))
                    {
                        DoCast(me, SPELL_BARKSKIN);
                        events.RescheduleEvent(EVENT_HEAL_BARKSKIN, 60s);
                    }
                    else
                        events.RescheduleEvent(EVENT_HEAL_BARKSKIN, 3s);
                    return;
                case EVENT_THORNS:
                    if (Creature* target = SelectRandomFriendlyMissingBuff(SPELL_THORNS))
                        DoCast(target, SPELL_THORNS);
                    events.ScheduleEvent(EVENT_THORNS, 25s, 40s);
                    return;
                case EVENT_NATURE_GRASP:
                    DoCast(me, SPELL_NATURE_GRASP);
                    events.ScheduleEvent(EVENT_NATURE_GRASP, 1min);
                    return;
                default:
                    return;
            }
        }
    }
};

struct npc_toc_shaman : public boss_faction_championsAI
{
    npc_toc_shaman(Creature* creature) : boss_faction_championsAI(creature, AI_HEALER) { }

    void Reset() override
    {
        boss_faction_championsAI::Reset();
        events.ScheduleEvent(EVENT_HEALING_WAVE, 5s, 10s);
        events.ScheduleEvent(EVENT_RIPTIDE, 5s, 20s);
        events.ScheduleEvent(EVENT_SPIRIT_CLEANSE, 15s, 25s);
        events.ScheduleEvent(EVENT_HEAL_BLOODLUST_HEROISM, 20s);
        events.ScheduleEvent(EVENT_HEX, 5s, 30s);
        events.ScheduleEvent(EVENT_EARTH_SHIELD, 1s);
        events.ScheduleEvent(EVENT_HEAL_EARTH_SHOCK, 5s, 30s);
        SetEquipmentSlots(false, 49992, EQUIP_NO_CHANGE, EQUIP_NO_CHANGE);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);
        boss_faction_championsAI::UpdateAI(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_HEALING_WAVE:
                    if (Unit* target = DoSelectLowestHpFriendly(40.0f))
                        DoCast(target, SPELL_HEALING_WAVE);
                    events.ScheduleEvent(EVENT_HEALING_WAVE, 3s, 5s);
                    return;
                case EVENT_RIPTIDE:
                    if (Unit* target = DoSelectLowestHpFriendly(40.0f))
                        DoCast(target, SPELL_RIPTIDE);
                    events.ScheduleEvent(EVENT_RIPTIDE, 5s, 15s);
                    return;
                case EVENT_SPIRIT_CLEANSE:
                    if (Unit* target = DoSelectLowestHpFriendly(40.0f))
                        DoCast(target, SPELL_SPIRIT_CLEANSE);
                    events.ScheduleEvent(EVENT_SPIRIT_CLEANSE, 15s, 35s);
                    return;
                case EVENT_HEAL_BLOODLUST_HEROISM:
                    if (me->GetFaction()) // alliance = 1
                    {
                        if (!me->HasAura(AURA_EXHAUSTION))
                            DoCastAOE(SPELL_HEROISM);
                    }
                    else
                    {
                        if (!me->HasAura(AURA_SATED))
                            DoCastAOE(SPELL_BLOODLUST);
                    }
                    events.ScheduleEvent(EVENT_HEAL_BLOODLUST_HEROISM, 5min);
                    return;
                case EVENT_HEX:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, NonTankTargetSelector(me)))
                        DoCast(target, SPELL_HEX);
                    events.ScheduleEvent(EVENT_HEX, 15s, 30s);
                    return;
                case EVENT_EARTH_SHIELD:
                    if (Creature* target = SelectRandomFriendlyMissingBuff(SPELL_EARTH_SHIELD))
                        DoCast(target, SPELL_EARTH_SHIELD);
                    events.ScheduleEvent(EVENT_EARTH_SHIELD, 15s, 30s);
                    return;
                case EVENT_HEAL_EARTH_SHOCK:
                    if (Unit* target = SelectEnemyCaster(true))
                        DoCast(target, SPELL_EARTH_SHOCK);
                    events.ScheduleEvent(EVENT_HEAL_EARTH_SHOCK, 10s, 20s);
                    return;
                default:
                    return;
            }
        }
    }
};

struct npc_toc_paladin : public boss_faction_championsAI
{
    npc_toc_paladin(Creature* creature) : boss_faction_championsAI(creature, AI_HEALER) { }

    void Reset() override
    {
        boss_faction_championsAI::Reset();
        events.ScheduleEvent(EVENT_HAND_OF_FREEDOM, 10s, 20s);
        events.ScheduleEvent(EVENT_HEAL_DIVINE_SHIELD, 20s);
        events.ScheduleEvent(EVENT_CLEANSE, 20s, 30s);
        events.ScheduleEvent(EVENT_FLASH_OF_LIGHT, 5s, 10s);
        events.ScheduleEvent(EVENT_HOLY_LIGHT, 10s, 15s);
        events.ScheduleEvent(EVENT_HOLY_SHOCK, 10s, 15s);
        events.ScheduleEvent(EVENT_HEAL_HAND_OF_PROTECTION, 30s, 60s);
        events.ScheduleEvent(EVENT_HAMMER_OF_JUSTICE, 10s, 30s);
        SetEquipmentSlots(false, 50771, 47079, EQUIP_NO_CHANGE);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);
        boss_faction_championsAI::UpdateAI(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_HAND_OF_FREEDOM:
                    if (Unit* target = SelectRandomFriendlyMissingBuff(SPELL_HAND_OF_FREEDOM))
                        DoCast(target, SPELL_HAND_OF_FREEDOM);
                    events.ScheduleEvent(EVENT_HAND_OF_FREEDOM, 15s, 35s);
                    return;
                case EVENT_HEAL_DIVINE_SHIELD:
                    if (HealthBelowPct(30) && !me->HasAura(SPELL_FORBEARANCE))
                    {
                        DoCast(me, SPELL_DIVINE_SHIELD);
                        events.RescheduleEvent(EVENT_HEAL_DIVINE_SHIELD, 5min);
                    }
                    else
                        events.RescheduleEvent(EVENT_HEAL_DIVINE_SHIELD, 5s);
                    return;
                case EVENT_CLEANSE:
                    if (Unit* target = DoSelectLowestHpFriendly(40.0f))
                        DoCast(target, SPELL_CLEANSE);
                    events.ScheduleEvent(EVENT_CLEANSE, 10s, 30s);
                    return;
                case EVENT_FLASH_OF_LIGHT:
                    if (Unit* target = DoSelectLowestHpFriendly(40.0f))
                        DoCast(target, SPELL_FLASH_OF_LIGHT);
                    events.ScheduleEvent(EVENT_FLASH_OF_LIGHT, 3s, 5s);
                    return;
                case EVENT_HOLY_LIGHT:
                    if (Unit* target = DoSelectLowestHpFriendly(40.0f))
                        DoCast(target, SPELL_HOLY_LIGHT);
                    events.ScheduleEvent(EVENT_HOLY_LIGHT, 5s, 10s);
                    return;
                case EVENT_HOLY_SHOCK:
                    if (Unit* target = DoSelectLowestHpFriendly(40.0f))
                        DoCast(target, SPELL_HOLY_SHOCK);
                    events.ScheduleEvent(EVENT_HOLY_SHOCK, 10s, 15s);
                    return;
                case EVENT_HEAL_HAND_OF_PROTECTION:
                    if (Unit* target = DoSelectLowestHpFriendly(30.0f))
                    {
                        if (!target->HasAura(SPELL_FORBEARANCE))
                        {
                            DoCast(target, SPELL_HAND_OF_PROTECTION);
                            events.RescheduleEvent(EVENT_HEAL_HAND_OF_PROTECTION, 5min);
                        }
                        else
                            events.RescheduleEvent(EVENT_HEAL_HAND_OF_PROTECTION, 3s);
                    }
                    else
                        events.RescheduleEvent(EVENT_HEAL_HAND_OF_PROTECTION, 10s);
                    return;
                case EVENT_HAMMER_OF_JUSTICE:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 15.0f, true))
                        DoCast(target, SPELL_HAMMER_OF_JUSTICE);
                    events.ScheduleEvent(EVENT_HAMMER_OF_JUSTICE, 40s);
                    return;
                default:
                    return;
            }
        }
    }
};

struct npc_toc_priest : public boss_faction_championsAI
{
    npc_toc_priest(Creature* creature) : boss_faction_championsAI(creature, AI_HEALER) { }

    void Reset() override
    {
        boss_faction_championsAI::Reset();
        events.ScheduleEvent(EVENT_RENEW, 3s, 10s);
        events.ScheduleEvent(EVENT_SHIELD, 5s, 15s);
        events.ScheduleEvent(EVENT_FLASH_HEAL, 5s, 10s);
        events.ScheduleEvent(EVENT_HEAL_DISPEL, 10s, 20s);
        events.ScheduleEvent(EVENT_HEAL_PSYCHIC_SCREAM, 10s, 30s);
        events.ScheduleEvent(EVENT_MANA_BURN, 15s, 30s);
        events.ScheduleEvent(EVENT_PENANCE, 10s, 20s);
        SetEquipmentSlots(false, 49992, EQUIP_NO_CHANGE, EQUIP_NO_CHANGE);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);
        boss_faction_championsAI::UpdateAI(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_RENEW:
                    if (Unit* target = DoSelectLowestHpFriendly(40.0f))
                        DoCast(target, SPELL_RENEW);
                    events.ScheduleEvent(EVENT_RENEW, 3s, 5s);
                    return;
                case EVENT_SHIELD:
                    if (Unit* target = DoSelectLowestHpFriendly(40.0f))
                        DoCast(target, SPELL_SHIELD);
                    events.ScheduleEvent(EVENT_SHIELD, 15s, 35s);
                    return;
                case EVENT_FLASH_HEAL:
                    if (Unit* target = DoSelectLowestHpFriendly(40.0f))
                        DoCast(target, SPELL_FLASH_HEAL);
                    events.ScheduleEvent(EVENT_FLASH_HEAL, 3s, 5s);
                    return;
                case EVENT_HEAL_DISPEL:
                    if (Unit* target = urand(0, 1) ? SelectTarget(SelectTargetMethod::Random, 0, 30.0f, true) : DoSelectLowestHpFriendly(40.0f))
                        DoCast(target, SPELL_DISPEL);
                    events.ScheduleEvent(EVENT_HEAL_DISPEL, 10s, 20s);
                    return;
                case EVENT_HEAL_PSYCHIC_SCREAM:
                    if (EnemiesInRange(10.0f) >= 2)
                        DoCastAOE(SPELL_PSYCHIC_SCREAM);
                    events.ScheduleEvent(EVENT_HEAL_PSYCHIC_SCREAM, 10s, 25s);
                    return;
                case EVENT_MANA_BURN:
                    if (Unit* target = SelectEnemyCaster(false))
                        DoCast(target, SPELL_MANA_BURN);
                    events.ScheduleEvent(EVENT_MANA_BURN, 15s, 30s);
                    return;
                case EVENT_PENANCE:
                    if (Unit* target = DoSelectLowestHpFriendly(40.0f))
                        DoCast(target, SPELL_PENANCE);
                    events.ScheduleEvent(EVENT_PENANCE, 10s, 20s);
                    return;
                default:
                    return;
            }
        }
    }
};

/********************************************************************
                            RANGED
********************************************************************/
struct npc_toc_shadow_priest : public boss_faction_championsAI
{
    npc_toc_shadow_priest(Creature* creature) : boss_faction_championsAI(creature, AI_RANGED) { }

    void Reset() override
    {
        boss_faction_championsAI::Reset();
        events.ScheduleEvent(EVENT_SILENCE, 10s, 25s);
        events.ScheduleEvent(EVENT_VAMPIRIC_TOUCH, 5s, 15s);
        events.ScheduleEvent(EVENT_SW_PAIN, 3s, 10s);
        events.ScheduleEvent(EVENT_MIND_BLAST, 5s, 15s);
        events.ScheduleEvent(EVENT_HORROR, 10s, 25s);
        events.ScheduleEvent(EVENT_DISPERSION, 20s, 40s);
        events.ScheduleEvent(EVENT_DPS_DISPEL, 10s, 20s);
        events.ScheduleEvent(EVENT_DPS_PSYCHIC_SCREAM, 10s, 30s);
        SetEquipmentSlots(false, 50040, EQUIP_NO_CHANGE, EQUIP_NO_CHANGE);
        DoCast(me, SPELL_SHADOWFORM);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);
        boss_faction_championsAI::UpdateAI(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SILENCE:
                    if (Unit* target = SelectEnemyCaster(true))
                        DoCast(target, SPELL_SILENCE);
                    events.ScheduleEvent(EVENT_SILENCE, 10s, 25s);
                    return;
                case EVENT_VAMPIRIC_TOUCH:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 30.0f, true))
                        DoCast(target, SPELL_VAMPIRIC_TOUCH);
                    events.ScheduleEvent(EVENT_VAMPIRIC_TOUCH, 10s, 35s);
                    return;
                case EVENT_SW_PAIN:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 40.0f, true))
                        DoCast(target, SPELL_SW_PAIN);
                    events.ScheduleEvent(EVENT_SW_PAIN, 10s, 35s);
                    return;
                case EVENT_MIND_BLAST:
                    DoCastVictim(SPELL_MIND_BLAST);
                    events.ScheduleEvent(EVENT_MIND_BLAST, 10s, 20s);
                    return;
                case EVENT_HORROR:
                    DoCastVictim(SPELL_HORROR);
                    events.ScheduleEvent(EVENT_HORROR, 15s, 35s);
                    return;
                case EVENT_DISPERSION:
                    if (HealthBelowPct(40))
                    {
                        DoCast(me, SPELL_DISPERSION);
                        events.RescheduleEvent(EVENT_DISPERSION, 180s);
                    }
                    else
                        events.RescheduleEvent(EVENT_DISPERSION, 5s);
                    return;
                case EVENT_DPS_DISPEL:
                    if (Unit* target = urand(0, 1) ? SelectTarget(SelectTargetMethod::Random, 0, 30.0f, true) : DoSelectLowestHpFriendly(40.0f))
                        DoCast(target, SPELL_DISPEL);
                    events.ScheduleEvent(EVENT_DPS_DISPEL, 10s, 20s);
                    return;
                case EVENT_DPS_PSYCHIC_SCREAM:
                    if (EnemiesInRange(10.0f) >= 2)
                        DoCastAOE(SPELL_PSYCHIC_SCREAM);
                    events.ScheduleEvent(EVENT_DPS_PSYCHIC_SCREAM, 10s, 25s);
                    return;
                default:
                    return;
            }
        }
        DoSpellAttackIfReady(SPELL_MIND_FLAY);
    }
};

struct npc_toc_warlock : public boss_faction_championsAI
{
    npc_toc_warlock(Creature* creature) : boss_faction_championsAI(creature, AI_RANGED) { }

    void Reset() override
    {
        boss_faction_championsAI::Reset();
        events.ScheduleEvent(EVENT_HELLFIRE, 10s, 30s);
        events.ScheduleEvent(EVENT_CORRUPTION, 2s, 5s);
        events.ScheduleEvent(EVENT_CURSE_OF_AGONY, 5s, 10s);
        events.ScheduleEvent(EVENT_CURSE_OF_EXHAUSTION, 5s, 10s);
        events.ScheduleEvent(EVENT_FEAR, 5s, 15s);
        events.ScheduleEvent(EVENT_SEARING_PAIN, 5s, 12s);
        events.ScheduleEvent(EVENT_UNSTABLE_AFFLICTION, 7s, 15s);
        SetEquipmentSlots(false, 49992, EQUIP_NO_CHANGE, EQUIP_NO_CHANGE);
    }

    void JustEngagedWith(Unit* who) override
    {
        boss_faction_championsAI::JustEngagedWith(who);
        DoCast(SPELL_SUMMON_FELHUNTER);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);
        boss_faction_championsAI::UpdateAI(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_HELLFIRE:
                    if (EnemiesInRange(10.0f) >= 2)
                        DoCastAOE(SPELL_HELLFIRE);
                    events.ScheduleEvent(EVENT_HELLFIRE, 10s, 30s);
                    return;
                case EVENT_CORRUPTION:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 30.0f))
                        DoCast(target, SPELL_CORRUPTION);
                    events.ScheduleEvent(EVENT_CORRUPTION, 15s, 25s);
                    return;
                case EVENT_CURSE_OF_AGONY:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 30.0f))
                        DoCast(target, SPELL_CURSE_OF_AGONY);
                    events.ScheduleEvent(EVENT_CURSE_OF_AGONY, 20s, 35s);
                    return;
                case EVENT_CURSE_OF_EXHAUSTION:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 30.0f))
                        DoCast(target, SPELL_CURSE_OF_EXHAUSTION);
                    events.ScheduleEvent(EVENT_CURSE_OF_EXHAUSTION, 20s, 35s);
                    return;
                case EVENT_FEAR:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 20.0f, true))
                        DoCast(target, SPELL_FEAR);
                    events.ScheduleEvent(EVENT_FEAR, 5s, 20s);
                    return;
                case EVENT_SEARING_PAIN:
                    DoCastVictim(SPELL_SEARING_PAIN);
                    events.ScheduleEvent(EVENT_SEARING_PAIN, 10s, 25s);
                    return;
                case EVENT_UNSTABLE_AFFLICTION:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 30.0f, true))
                        DoCast(target, SPELL_UNSTABLE_AFFLICTION);
                    events.ScheduleEvent(EVENT_UNSTABLE_AFFLICTION, 10s, 25s);
                    return;
                default:
                    return;
            }
        }
        DoSpellAttackIfReady(SPELL_SHADOW_BOLT);
    }
};

struct npc_toc_mage : public boss_faction_championsAI
{
    npc_toc_mage(Creature* creature) : boss_faction_championsAI(creature, AI_RANGED) { }

    void Reset() override
    {
        boss_faction_championsAI::Reset();
        events.ScheduleEvent(EVENT_ARCANE_BARRAGE, 1s, 5s);
        events.ScheduleEvent(EVENT_ARCANE_BLAST, 3s, 5s);
        events.ScheduleEvent(EVENT_ARCANE_EXPLOSION, 5s, 15s);
        events.ScheduleEvent(EVENT_BLINK, 15s, 20s);
        events.ScheduleEvent(EVENT_COUNTERSPELL, 10s, 20s);
        events.ScheduleEvent(EVENT_FROST_NOVA, 5s, 20s);
        events.ScheduleEvent(EVENT_ICE_BLOCK, 10s, 20s);
        events.ScheduleEvent(EVENT_POLYMORPH, 5s, 15s);
        SetEquipmentSlots(false, 47524, EQUIP_NO_CHANGE, EQUIP_NO_CHANGE);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);
        boss_faction_championsAI::UpdateAI(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_ARCANE_BARRAGE:
                    DoCastVictim(SPELL_ARCANE_BARRAGE);
                    events.ScheduleEvent(EVENT_ARCANE_BARRAGE, 5s, 7s);
                    return;
                case EVENT_ARCANE_BLAST:
                    DoCastVictim(SPELL_ARCANE_BLAST);
                    events.ScheduleEvent(EVENT_ARCANE_BLAST, 5s, 15s);
                    return;
                case EVENT_ARCANE_EXPLOSION:
                    if (EnemiesInRange(10.0f) >= 2)
                        DoCastAOE(SPELL_ARCANE_EXPLOSION);
                    events.ScheduleEvent(EVENT_ARCANE_EXPLOSION, 10s, 30s);
                    return;
                case EVENT_BLINK:
                    if (EnemiesInRange(10.0f) >= 2)
                        DoCast(SPELL_BLINK);
                    events.ScheduleEvent(EVENT_BLINK, 10s, 30s);
                    return;
                case EVENT_COUNTERSPELL:
                    if (Unit* target = SelectEnemyCaster(true))
                        DoCast(target, SPELL_COUNTERSPELL);
                    events.ScheduleEvent(EVENT_COUNTERSPELL, 24s);
                    return;
                case EVENT_FROST_NOVA:
                    if (EnemiesInRange(10.0f) >= 2)
                        DoCastAOE(SPELL_FROST_NOVA);
                    events.ScheduleEvent(EVENT_FROST_NOVA, 25s);
                    return;
                case EVENT_ICE_BLOCK:
                    if (HealthBelowPct(30))
                    {
                        DoCast(SPELL_ICE_BLOCK);
                        events.RescheduleEvent(EVENT_ICE_BLOCK, 5min);
                    }
                    else
                        events.RescheduleEvent(EVENT_ICE_BLOCK, 5s);
                    return;
                case EVENT_POLYMORPH:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, NonTankTargetSelector(me)))
                        DoCast(target, SPELL_POLYMORPH);
                    events.ScheduleEvent(EVENT_POLYMORPH, 10s, 30s);
                    return;
                default:
                    return;
            }
        }
        DoSpellAttackIfReady(SPELL_FROSTBOLT);
    }
};

struct npc_toc_hunter : public boss_faction_championsAI
{
    npc_toc_hunter(Creature* creature) : boss_faction_championsAI(creature, AI_RANGED) { }

    void Reset() override
    {
        boss_faction_championsAI::Reset();
        events.ScheduleEvent(EVENT_AIMED_SHOT, 5s, 10s);
        events.ScheduleEvent(EVENT_DETERRENCE, 10s, 20s);
        events.ScheduleEvent(EVENT_DISENGAGE, 10s, 20s);
        events.ScheduleEvent(EVENT_EXPLOSIVE_SHOT, 3s, 5s);
        events.ScheduleEvent(EVENT_FROST_TRAP, 10s, 20s);
        events.ScheduleEvent(EVENT_STEADY_SHOT, 5s, 10s);
        events.ScheduleEvent(EVENT_WING_CLIP, 10s, 20s);
        events.ScheduleEvent(EVENT_WYVERN_STING, 10s, 25s);
        SetEquipmentSlots(false, 47156, EQUIP_NO_CHANGE, 48711);
    }

    void JustEngagedWith(Unit* who) override
    {
        boss_faction_championsAI::JustEngagedWith(who);
        DoCast(SPELL_CALL_PET);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);
        boss_faction_championsAI::UpdateAI(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_AIMED_SHOT:
                    DoCastVictim(SPELL_AIMED_SHOT);
                    events.ScheduleEvent(EVENT_AIMED_SHOT, 10s, 15s);
                    return;
                case EVENT_DETERRENCE:
                    if (HealthBelowPct(30))
                    {
                        DoCast(SPELL_DETERRENCE);
                        events.RescheduleEvent(EVENT_DETERRENCE, 150s);
                    }
                    else
                        events.RescheduleEvent(EVENT_DETERRENCE, 10s);
                    return;
                case EVENT_DISENGAGE:
                    if (EnemiesInRange(10.0f) >= 2)
                        DoCast(SPELL_DISENGAGE);
                    events.ScheduleEvent(EVENT_DISENGAGE, 30s);
                    return;
                case EVENT_EXPLOSIVE_SHOT:
                    DoCastVictim(SPELL_EXPLOSIVE_SHOT);
                    events.ScheduleEvent(EVENT_EXPLOSIVE_SHOT, 6s, 10s);
                    return;
                case EVENT_FROST_TRAP:
                    if (EnemiesInRange(10.0f) >= 2)
                        DoCastAOE(SPELL_FROST_TRAP);
                    events.ScheduleEvent(EVENT_FROST_TRAP, 30s);
                    return;
                case EVENT_STEADY_SHOT:
                    DoCastVictim(SPELL_STEADY_SHOT);
                    events.ScheduleEvent(EVENT_STEADY_SHOT, 5s, 15s);
                    return;
                case EVENT_WING_CLIP:
                    if (Unit* target = me->GetVictim())
                    {
                        if (me->GetDistance2d(target) < 6.0f)
                            DoCast(target, SPELL_WING_CLIP);
                    }
                    events.ScheduleEvent(EVENT_WING_CLIP, 15s, 25s);
                    return;
                case EVENT_WYVERN_STING:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, NonTankTargetSelector(me)))
                        DoCast(target, SPELL_WYVERN_STING);
                    events.ScheduleEvent(EVENT_WYVERN_STING, 10s, 30s);
                    return;
                default:
                    return;
            }
        }
        DoSpellAttackIfReady(SPELL_SHOOT);
    }
};

struct npc_toc_boomkin : public boss_faction_championsAI
{
    npc_toc_boomkin(Creature* creature) : boss_faction_championsAI(creature, AI_RANGED) { }

    void Reset() override
    {
        boss_faction_championsAI::Reset();
        events.ScheduleEvent(EVENT_CYCLONE, 10s, 20s);
        events.ScheduleEvent(EVENT_ENTANGLING_ROOTS, 10s, 20s);
        events.ScheduleEvent(EVENT_FAERIE_FIRE, 2s, 5s);
        events.ScheduleEvent(EVENT_FORCE_OF_NATURE, 20s, 30s);
        events.ScheduleEvent(EVENT_INSECT_SWARM, 5s, 10s);
        events.ScheduleEvent(EVENT_MOONFIRE, 10s, 20s);
        events.ScheduleEvent(EVENT_STARFIRE, 10s, 20s);
        events.ScheduleEvent(EVENT_DPS_BARKSKIN, 20s, 30s);

        SetEquipmentSlots(false, 50966, EQUIP_NO_CHANGE, EQUIP_NO_CHANGE);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);
        boss_faction_championsAI::UpdateAI(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_CYCLONE:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, NonTankTargetSelector(me)))
                        DoCast(target, SPELL_CYCLONE);
                    events.ScheduleEvent(EVENT_CYCLONE, 10s, 20s);
                    return;
                case EVENT_ENTANGLING_ROOTS:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 30.0f, true))
                        DoCast(target, SPELL_ENTANGLING_ROOTS);
                    events.ScheduleEvent(EVENT_ENTANGLING_ROOTS, 10s, 20s);
                    return;
                case EVENT_FAERIE_FIRE:
                    DoCastVictim(SPELL_FAERIE_FIRE);
                    events.ScheduleEvent(EVENT_FAERIE_FIRE, 30s, 40s);
                    return;
                case EVENT_FORCE_OF_NATURE:
                    DoCastVictim(SPELL_FORCE_OF_NATURE);
                    events.ScheduleEvent(EVENT_FORCE_OF_NATURE, 2min);
                    return;
                case EVENT_INSECT_SWARM:
                    DoCastVictim(SPELL_INSECT_SWARM);
                    events.ScheduleEvent(EVENT_INSECT_SWARM, 15s, 25s);
                    return;
                case EVENT_MOONFIRE:
                    DoCastVictim(SPELL_MOONFIRE);
                    events.ScheduleEvent(EVENT_MOONFIRE, 15s, 30s);
                    return;
                case EVENT_STARFIRE:
                    DoCastVictim(SPELL_STARFIRE);
                    events.ScheduleEvent(EVENT_STARFIRE, 15s, 30s);
                    return;
                case EVENT_DPS_BARKSKIN:
                    if (HealthBelowPct(30))
                    {
                        DoCast(me, SPELL_BARKSKIN);
                        events.RescheduleEvent(EVENT_DPS_BARKSKIN, 60s);
                    }
                    else
                        events.RescheduleEvent(EVENT_DPS_BARKSKIN, 5s);
                    return;
                default:
                    return;
            }
        }
        DoSpellAttackIfReady(SPELL_WRATH);
    }
};

/********************************************************************
                            MELEE
********************************************************************/
struct npc_toc_warrior : public boss_faction_championsAI
{
    npc_toc_warrior(Creature* creature) : boss_faction_championsAI(creature, AI_MELEE) { }

    void Reset() override
    {
        boss_faction_championsAI::Reset();
        events.ScheduleEvent(EVENT_BLADESTORM, 10s, 15s);
        events.ScheduleEvent(EVENT_INTIMIDATING_SHOUT, 20s, 25s);
        events.ScheduleEvent(EVENT_MORTAL_STRIKE, 5s, 20s);
        events.ScheduleEvent(EVENT_WARR_CHARGE, 1s);
        events.ScheduleEvent(EVENT_DISARM, 5s, 20s);
        events.ScheduleEvent(EVENT_OVERPOWER, 10s, 20s);
        events.ScheduleEvent(EVENT_SUNDER_ARMOR, 5s, 10s);
        events.ScheduleEvent(EVENT_SHATTERING_THROW, 20s, 40s);
        events.ScheduleEvent(EVENT_RETALIATION, 5s, 20s);
        SetEquipmentSlots(false, 47427, 46964, EQUIP_NO_CHANGE);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);
        boss_faction_championsAI::UpdateAI(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_BLADESTORM:
                    DoCastVictim(SPELL_BLADESTORM);
                    events.ScheduleEvent(EVENT_BLADESTORM, 150s);
                    return;
                case EVENT_INTIMIDATING_SHOUT:
                    DoCastAOE(SPELL_INTIMIDATING_SHOUT);
                    events.ScheduleEvent(EVENT_INTIMIDATING_SHOUT, 120s);
                    return;
                case EVENT_MORTAL_STRIKE:
                    DoCastVictim(SPELL_MORTAL_STRIKE);
                    events.ScheduleEvent(EVENT_MORTAL_STRIKE, 10s, 25s);
                    return;
                case EVENT_WARR_CHARGE:
                    DoCastVictim(SPELL_CHARGE);
                    events.ScheduleEvent(EVENT_WARR_CHARGE, 10s, 20s);
                    return;
                case EVENT_DISARM:
                    DoCastVictim(SPELL_DISARM);
                    events.ScheduleEvent(EVENT_DISARM, 15s, 35s);
                    return;
                case EVENT_OVERPOWER:
                    DoCastVictim(SPELL_OVERPOWER);
                    events.ScheduleEvent(EVENT_OVERPOWER, 20s, 40s);
                    return;
                case EVENT_SUNDER_ARMOR:
                    DoCastVictim(SPELL_SUNDER_ARMOR);
                    events.ScheduleEvent(EVENT_SUNDER_ARMOR, 2s, 5s);
                    return;
                case EVENT_SHATTERING_THROW:
                    if (Unit* target = me->GetVictim())
                    {
                        if (target->HasAuraWithMechanic(1 << MECHANIC_IMMUNE_SHIELD))
                        {
                            DoCast(target, SPELL_SHATTERING_THROW);
                            events.RescheduleEvent(EVENT_SHATTERING_THROW, 5min);
                            return;
                        }
                    }
                    events.RescheduleEvent(EVENT_SHATTERING_THROW, 3s);
                    return;
                case EVENT_RETALIATION:
                    if (HealthBelowPct(50))
                    {
                        DoCast(SPELL_RETALIATION);
                        events.RescheduleEvent(EVENT_RETALIATION, 5min);
                    }
                    else
                        events.RescheduleEvent(EVENT_RETALIATION, 5s);
                    return;
                default:
                    return;
            }
        }
    }
};

struct npc_toc_dk : public boss_faction_championsAI
{
    npc_toc_dk(Creature* creature) : boss_faction_championsAI(creature, AI_MELEE) { }

    void Reset() override
    {
        boss_faction_championsAI::Reset();
        events.ScheduleEvent(EVENT_CHAINS_OF_ICE, 5s, 15s);
        events.ScheduleEvent(EVENT_DEATH_COIL, 10s, 20s);
        events.ScheduleEvent(EVENT_DEATH_GRIP, 15s, 25s);
        events.ScheduleEvent(EVENT_FROST_STRIKE, 5s, 10s);
        events.ScheduleEvent(EVENT_ICEBOUND_FORTITUDE, 25s, 35s);
        events.ScheduleEvent(EVENT_ICY_TOUCH, 10s, 20s);
        events.ScheduleEvent(EVENT_STRANGULATE, 5s, 25s);
        SetEquipmentSlots(false, 47518, 51021, EQUIP_NO_CHANGE);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);
        boss_faction_championsAI::UpdateAI(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_CHAINS_OF_ICE:
                    DoCastVictim(SPELL_CHAINS_OF_ICE);
                    events.ScheduleEvent(EVENT_CHAINS_OF_ICE, 15s, 25s);
                    return;
                case EVENT_DEATH_COIL:
                    DoCastVictim(SPELL_DEATH_COIL);
                    events.ScheduleEvent(EVENT_DEATH_COIL, 5s, 15s);
                    return;
                case EVENT_DEATH_GRIP:
                    if (Unit* target = me->GetVictim())
                    {
                        if (me->IsInRange(target, 5.0f, 30.0f, false))
                        {
                            DoCast(target, SPELL_DEATH_GRIP);
                            events.RescheduleEvent(EVENT_DEATH_GRIP, 35s);
                            return;
                        }
                    }
                    events.RescheduleEvent(EVENT_DEATH_GRIP, 3s);
                    return;
                case EVENT_FROST_STRIKE:
                    DoCastVictim(SPELL_FROST_STRIKE);
                    events.ScheduleEvent(EVENT_FROST_STRIKE, 6s, 10s);
                    return;
                case EVENT_ICEBOUND_FORTITUDE:
                    if (HealthBelowPct(50))
                    {
                        DoCast(SPELL_ICEBOUND_FORTITUDE);
                        events.RescheduleEvent(EVENT_ICEBOUND_FORTITUDE, 60s);
                    }
                    else
                        events.RescheduleEvent(EVENT_ICEBOUND_FORTITUDE, 5s);
                    return;
                case EVENT_ICY_TOUCH:
                    DoCastVictim(SPELL_ICY_TOUCH);
                    events.ScheduleEvent(EVENT_ICY_TOUCH, 10s, 15s);
                    return;
                case EVENT_STRANGULATE:
                    if (Unit* target = SelectEnemyCaster(false))
                    {
                        DoCast(target, SPELL_STRANGULATE);
                        events.RescheduleEvent(EVENT_STRANGULATE, 120s);
                    }
                    else
                        events.RescheduleEvent(EVENT_STRANGULATE, 5s);
                    return;
                default:
                    return;
            }
        }
    }
};

struct npc_toc_rogue : public boss_faction_championsAI
{
    npc_toc_rogue(Creature* creature) : boss_faction_championsAI(creature, AI_MELEE) { }

    void Reset() override
    {
        boss_faction_championsAI::Reset();
        events.ScheduleEvent(EVENT_FAN_OF_KNIVES, 5s, 10s);
        events.ScheduleEvent(EVENT_BLIND, 10s, 20s);
        events.ScheduleEvent(EVENT_CLOAK, 20s, 30s);
        events.ScheduleEvent(EVENT_BLADE_FLURRY, 10s, 20s);
        events.ScheduleEvent(EVENT_SHADOWSTEP, 20s, 30s);
        events.ScheduleEvent(EVENT_HEMORRHAGE, 3s, 10s);
        events.ScheduleEvent(EVENT_EVISCERATE, 20s, 40s);
        events.ScheduleEvent(EVENT_WOUND_POISON, 5s, 10s);
        SetEquipmentSlots(false, 47422, 49982, EQUIP_NO_CHANGE);
        me->SetPowerType(POWER_ENERGY);
        me->SetFullPower(POWER_ENERGY);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);
        boss_faction_championsAI::UpdateAI(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_FAN_OF_KNIVES:
                    if (EnemiesInRange(10.0f) >= 2)
                        DoCastAOE(SPELL_FAN_OF_KNIVES);
                    events.ScheduleEvent(EVENT_FAN_OF_KNIVES, 10s, 20s);
                    return;
                case EVENT_BLIND:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, NonTankTargetSelector(me)))
                        DoCast(target, SPELL_BLIND);
                    events.ScheduleEvent(EVENT_BLIND, 10s, 30s);
                    return;
                case EVENT_CLOAK:
                    if (HealthBelowPct(50))
                    {
                        DoCast(SPELL_CLOAK);
                        events.RescheduleEvent(EVENT_CLOAK, 90s);
                    }
                    else
                        events.RescheduleEvent(EVENT_CLOAK, 5s);
                    return;
                case EVENT_BLADE_FLURRY:
                    if (EnemiesInRange(10.0f) >= 2)
                    {
                        DoCast(SPELL_BLADE_FLURRY);
                        events.RescheduleEvent(EVENT_BLADE_FLURRY, 120s);
                    }
                    else
                        events.RescheduleEvent(EVENT_BLADE_FLURRY, 5s);
                    return;
                case EVENT_SHADOWSTEP:
                    if (Unit* target = me->GetVictim())
                    {
                        if (me->IsInRange(target, 10.0f, 40.0f, false))
                        {
                            DoCast(target, SPELL_SHADOWSTEP);
                            events.RescheduleEvent(EVENT_SHADOWSTEP, 30s);
                            return;
                        }
                    }
                    events.RescheduleEvent(EVENT_SHADOWSTEP, 5s);
                    return;
                case EVENT_HEMORRHAGE:
                    DoCastVictim(SPELL_HEMORRHAGE);
                    events.ScheduleEvent(EVENT_HEMORRHAGE, 3s, 10s);
                    return;
                case EVENT_EVISCERATE:
                    DoCastVictim(SPELL_EVISCERATE);
                    events.ScheduleEvent(EVENT_EVISCERATE, 30s, 40s);
                    return;
                case EVENT_WOUND_POISON:
                    DoCastVictim(SPELL_WOUND_POISON);
                    events.ScheduleEvent(EVENT_WOUND_POISON, 10s, 20s);
                    return;
                default:
                    return;
            }
        }
    }
};

struct npc_toc_enh_shaman : public boss_faction_championsAI
{
    npc_toc_enh_shaman(Creature* creature) : boss_faction_championsAI(creature, AI_MELEE)
    {
        Initialize();
    }

    void Initialize()
    {
        _totemCount = 0;
        _totemOldCenterX = me->GetPositionX();
        _totemOldCenterY = me->GetPositionY();
    }

    void Reset() override
    {
        boss_faction_championsAI::Reset();
        events.ScheduleEvent(EVENT_DPS_EARTH_SHOCK, 5s, 10s);
        events.ScheduleEvent(EVENT_LAVA_LASH, 3s, 5s);
        events.ScheduleEvent(EVENT_STORMSTRIKE, 2s, 5s);
        events.ScheduleEvent(EVENT_DPS_BLOODLUST_HEROISM, 20s);
        events.ScheduleEvent(EVENT_DEPLOY_TOTEM, 1s);
        events.ScheduleEvent(EVENT_WINDFURY, 20s, 50s);

        Initialize();
        SetEquipmentSlots(false, 51803, 48013, EQUIP_NO_CHANGE);
        summons.DespawnAll();
    }

    void JustSummoned(Creature* summoned) override
    {
        summons.Summon(summoned);
    }

    void SummonedCreatureDespawn(Creature* /*pSummoned*/) override
    {
        --_totemCount;
    }

    void DeployTotem()
    {
        _totemCount = 4;
        _totemOldCenterX = me->GetPositionX();
        _totemOldCenterY = me->GetPositionY();
        /*
        -Windfury (16% melee haste)
        -Grounding (redirects one harmful magic spell to the totem)

        -Healing Stream (unable to find amount of healing in our logs)

        -Tremor (prevents fear effects)
        -Strength of Earth (155 strength and agil for the opposing team)

        -Searing (average ~3500 damage on a random target every ~3.5 seconds)
        */
    }

    void JustDied(Unit* killer) override
    {
        boss_faction_championsAI::JustDied(killer);
        summons.DespawnAll();
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);
        boss_faction_championsAI::UpdateAI(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_DPS_EARTH_SHOCK:
                    if (Unit* target = SelectEnemyCaster(true))
                        DoCast(target, SPELL_EARTH_SHOCK);
                    events.ScheduleEvent(EVENT_DPS_EARTH_SHOCK, 10s, 15s);
                    return;
                case EVENT_LAVA_LASH:
                    DoCastVictim(SPELL_LAVA_LASH);
                    events.ScheduleEvent(EVENT_LAVA_LASH, 5s, 15s);
                    return;
                case EVENT_STORMSTRIKE:
                    DoCastVictim(SPELL_STORMSTRIKE);
                    events.ScheduleEvent(EVENT_STORMSTRIKE, 8s, 10s);
                    return;
                case EVENT_DPS_BLOODLUST_HEROISM:
                    if (me->GetFaction()) //Am i alliance?
                    {
                        if (!me->HasAura(AURA_EXHAUSTION))
                            DoCastAOE(SPELL_HEROISM);
                    }
                    else
                    {
                        if (!me->HasAura(AURA_SATED))
                            DoCastAOE(SPELL_BLOODLUST);
                    }
                    events.ScheduleEvent(EVENT_DPS_BLOODLUST_HEROISM, 5min);
                    return;
                case EVENT_DEPLOY_TOTEM:
                    if (_totemCount < 4 || me->GetDistance2d(_totemOldCenterX, _totemOldCenterY) > 20.0f)
                        DeployTotem();
                    events.ScheduleEvent(EVENT_DEPLOY_TOTEM, 1s);
                    return;
                case EVENT_WINDFURY:
                    DoCastVictim(SPELL_WINDFURY);
                    events.ScheduleEvent(EVENT_WINDFURY, 20s, 60s);
                    return;
                default:
                    return;
            }
        }
    }
    private:
        uint8  _totemCount;
        float  _totemOldCenterX, _totemOldCenterY;
};

struct npc_toc_retro_paladin : public boss_faction_championsAI
{
    npc_toc_retro_paladin(Creature* creature) : boss_faction_championsAI(creature, AI_MELEE) { }

    void Reset() override
    {
        boss_faction_championsAI::Reset();
        events.ScheduleEvent(EVENT_AVENGING_WRATH, 25s, 35s);
        events.ScheduleEvent(EVENT_CRUSADER_STRIKE, 5s, 10s);
        events.ScheduleEvent(EVENT_DIVINE_STORM, 10s, 20s);
        events.ScheduleEvent(EVENT_HAMMER_OF_JUSTICE_RET, 10s, 30s);
        events.ScheduleEvent(EVENT_JUDGEMENT_OF_COMMAND, 5s, 15s);
        events.ScheduleEvent(EVENT_REPENTANCE, 15s, 30s);
        events.ScheduleEvent(EVENT_DPS_HAND_OF_PROTECTION, 20s, 30s);
        events.ScheduleEvent(EVENT_DPS_DIVINE_SHIELD, 20s, 30s);
        SetEquipmentSlots(false, 47519, EQUIP_NO_CHANGE, EQUIP_NO_CHANGE);
    }

    void JustEngagedWith(Unit* who) override
    {
        boss_faction_championsAI::JustEngagedWith(who);
        DoCast(SPELL_SEAL_OF_COMMAND);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);
        boss_faction_championsAI::UpdateAI(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_AVENGING_WRATH:
                    DoCast(SPELL_AVENGING_WRATH);
                    events.ScheduleEvent(EVENT_AVENGING_WRATH, 2min);
                    return;
                case EVENT_CRUSADER_STRIKE:
                    DoCastVictim(SPELL_CRUSADER_STRIKE);
                    events.ScheduleEvent(EVENT_CRUSADER_STRIKE, 10s, 15s);
                    return;
                case EVENT_DIVINE_STORM:
                    if (EnemiesInRange(10.0f) >= 2)
                        DoCast(SPELL_DIVINE_STORM);
                    events.ScheduleEvent(EVENT_DIVINE_STORM, 10s, 20s);
                    return;
                case EVENT_HAMMER_OF_JUSTICE_RET:
                    DoCastVictim(SPELL_HAMMER_OF_JUSTICE_RET);
                    events.ScheduleEvent(EVENT_HAMMER_OF_JUSTICE_RET, 40s);
                    return;
                case EVENT_JUDGEMENT_OF_COMMAND:
                    DoCastVictim(SPELL_JUDGEMENT_OF_COMMAND);
                    events.ScheduleEvent(EVENT_JUDGEMENT_OF_COMMAND, 10s, 15s);
                    return;
                case EVENT_REPENTANCE:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, NonTankTargetSelector(me)))
                        DoCast(target, SPELL_REPENTANCE);
                    events.ScheduleEvent(EVENT_REPENTANCE, 1min);
                    return;
                case EVENT_DPS_HAND_OF_PROTECTION:
                    if (Unit* target = DoSelectLowestHpFriendly(30.0f))
                    {
                        if (!target->HasAura(SPELL_FORBEARANCE))
                        {
                            DoCast(target, SPELL_HAND_OF_PROTECTION);
                            events.RescheduleEvent(EVENT_DPS_HAND_OF_PROTECTION, 5min);
                        }
                        else
                            events.RescheduleEvent(EVENT_DPS_HAND_OF_PROTECTION, 5s);
                    }
                    else
                        events.RescheduleEvent(EVENT_DPS_HAND_OF_PROTECTION, 5s);
                    return;
                case EVENT_DPS_DIVINE_SHIELD:
                    if (HealthBelowPct(30) && !me->HasAura(SPELL_FORBEARANCE))
                    {
                        DoCast(me, SPELL_DIVINE_SHIELD);
                        events.RescheduleEvent(EVENT_DPS_DIVINE_SHIELD, 5min);
                    }
                    else
                        events.RescheduleEvent(EVENT_DPS_DIVINE_SHIELD, 5s);
                    return;
                default:
                    return;
            }
        }
    }
};

struct npc_toc_pet_warlock : public boss_faction_championsAI
{
    npc_toc_pet_warlock(Creature* creature) : boss_faction_championsAI(creature, AI_PET) { }

    void Reset() override
    {
        boss_faction_championsAI::Reset();
        events.ScheduleEvent(EVENT_DEVOUR_MAGIC, 15s, 30s);
        events.ScheduleEvent(EVENT_SPELL_LOCK, 15s, 30s);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);
        boss_faction_championsAI::UpdateAI(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_DEVOUR_MAGIC:
                    DoCastVictim(SPELL_DEVOUR_MAGIC);
                    events.ScheduleEvent(EVENT_DEVOUR_MAGIC, 8s, 10s);
                    return;
                case EVENT_SPELL_LOCK:
                    DoCast(SPELL_SPELL_LOCK);
                    events.ScheduleEvent(EVENT_SPELL_LOCK, 24s, 30s);
                    return;
                default:
                    return;
            }
        }
    }
};

struct npc_toc_pet_hunter : public boss_faction_championsAI
{
    npc_toc_pet_hunter(Creature* creature) : boss_faction_championsAI(creature, AI_PET)
    {
        Initialize();
    }

    void Initialize()
    {
        _clawTimer = urand(5 * IN_MILLISECONDS, 10 * IN_MILLISECONDS);
    }

    void Reset() override
    {
        boss_faction_championsAI::Reset();
        Initialize();
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        boss_faction_championsAI::UpdateAI(diff);

        if (_clawTimer <= diff)
        {
            DoCastVictim(SPELL_CLAW);
            _clawTimer = urand(5*IN_MILLISECONDS, 10*IN_MILLISECONDS);
        }
        else
            _clawTimer -= diff;
    }
    private:
        uint32 _clawTimer;
};

// 65812, 68154, 68155, 68156 - Unstable Affliction
class spell_faction_champion_warl_unstable_affliction : public AuraScript
{
    PrepareAuraScript(spell_faction_champion_warl_unstable_affliction);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_UNSTABLE_AFFLICTION_DISPEL });
    }

    void HandleDispel(DispelInfo* dispelInfo)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(dispelInfo->GetDispeller(), SPELL_UNSTABLE_AFFLICTION_DISPEL, GetEffect(EFFECT_0));
    }

    void Register() override
    {
        AfterDispel += AuraDispelFn(spell_faction_champion_warl_unstable_affliction::HandleDispel);
    }
};

// 66017, 68753, 68754, 68755 - Death Grip
class spell_faction_champion_death_grip : public SpellScript
{
    PrepareSpellScript(spell_faction_champion_death_grip);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_DEATH_GRIP_PULL });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (Unit* target = GetHitUnit())
        {
            if (Unit* caster = GetCaster())
                target->CastSpell(caster, SPELL_DEATH_GRIP_PULL);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_faction_champion_death_grip::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 65980 - Bloodlust
class spell_toc_bloodlust : public SpellScript
{
    PrepareSpellScript(spell_toc_bloodlust);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ AURA_SATED });
    }

    void RemoveInvalidTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if(Trinity::UnitAuraCheck(true, AURA_SATED));
    }

    void ApplyDebuff()
    {
        if (Unit* target = GetHitUnit())
            target->CastSpell(target, AURA_SATED, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_toc_bloodlust::RemoveInvalidTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_toc_bloodlust::RemoveInvalidTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ALLY);
        AfterHit += SpellHitFn(spell_toc_bloodlust::ApplyDebuff);
    }
};

// 65983 - Heroism
class spell_toc_heroism : public SpellScript
{
    PrepareSpellScript(spell_toc_heroism);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ AURA_EXHAUSTION });
    }

    void RemoveInvalidTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if(Trinity::UnitAuraCheck(true, AURA_EXHAUSTION));
    }

    void ApplyDebuff()
    {
        if (Unit* target = GetHitUnit())
            target->CastSpell(target, AURA_EXHAUSTION, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_toc_heroism::RemoveInvalidTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_toc_heroism::RemoveInvalidTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ALLY);
        AfterHit += SpellHitFn(spell_toc_heroism::ApplyDebuff);
    }
};

void AddSC_boss_faction_champions()
{
    RegisterTrialOfTheCrusaderCreatureAI(boss_toc_champion_controller);
    RegisterTrialOfTheCrusaderCreatureAI(npc_toc_druid);
    RegisterTrialOfTheCrusaderCreatureAI(npc_toc_shaman);
    RegisterTrialOfTheCrusaderCreatureAI(npc_toc_paladin);
    RegisterTrialOfTheCrusaderCreatureAI(npc_toc_priest);
    RegisterTrialOfTheCrusaderCreatureAI(npc_toc_shadow_priest);
    RegisterTrialOfTheCrusaderCreatureAI(npc_toc_mage);
    RegisterTrialOfTheCrusaderCreatureAI(npc_toc_warlock);
    RegisterTrialOfTheCrusaderCreatureAI(npc_toc_hunter);
    RegisterTrialOfTheCrusaderCreatureAI(npc_toc_boomkin);
    RegisterTrialOfTheCrusaderCreatureAI(npc_toc_warrior);
    RegisterTrialOfTheCrusaderCreatureAI(npc_toc_dk);
    RegisterTrialOfTheCrusaderCreatureAI(npc_toc_rogue);
    RegisterTrialOfTheCrusaderCreatureAI(npc_toc_enh_shaman);
    RegisterTrialOfTheCrusaderCreatureAI(npc_toc_retro_paladin);
    RegisterTrialOfTheCrusaderCreatureAI(npc_toc_pet_warlock);
    RegisterTrialOfTheCrusaderCreatureAI(npc_toc_pet_hunter);

    RegisterSpellScript(spell_faction_champion_warl_unstable_affliction);
    RegisterSpellScript(spell_faction_champion_death_grip);
    RegisterSpellScript(spell_toc_bloodlust);
    RegisterSpellScript(spell_toc_heroism);
}
