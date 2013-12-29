/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "trial_of_the_crusader.h"
#include "Player.h"
#include "GridNotifiers.h"

enum Yells
{
    SAY_KILL_PLAYER     = 6
};

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
    EVENT_HEAL_BARKSKIN                  = 6,
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

class boss_toc_champion_controller : public CreatureScript
{
    public:
        boss_toc_champion_controller() : CreatureScript("boss_toc_champion_controller") { }

        struct boss_toc_champion_controllerAI : public ScriptedAI
        {
            boss_toc_champion_controllerAI(Creature* creature) : ScriptedAI(creature), _summons(me)
            {
                _instance = creature->GetInstanceScript();
            }

            void Reset() OVERRIDE
            {
                _championsNotStarted = 0;
                _championsFailed = 0;
                _championsKilled = 0;
                _inProgress = false;
            }

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
                if (_instance->instance->GetSpawnMode() == RAID_DIFFICULTY_25MAN_NORMAL || _instance->instance->GetSpawnMode() == RAID_DIFFICULTY_25MAN_HEROIC)
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

                if (_instance->instance->GetSpawnMode() == RAID_DIFFICULTY_10MAN_NORMAL || _instance->instance->GetSpawnMode() == RAID_DIFFICULTY_10MAN_HEROIC)
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
                    if (Creature* temp = me->SummonCreature(vChampionEntries[i], vChampionJumpOrigin[urand(0, vChampionJumpOrigin.size()-1)], TEMPSUMMON_MANUAL_DESPAWN))
                    {
                        _summons.Summon(temp);
                        temp->SetReactState(REACT_PASSIVE);
                        temp->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC);
                        if (playerTeam == ALLIANCE)
                        {
                            temp->SetHomePosition(vChampionJumpTarget[pos].GetPositionX(), vChampionJumpTarget[pos].GetPositionY(), vChampionJumpTarget[pos].GetPositionZ(), 0);
                            temp->GetMotionMaster()->MoveJump(vChampionJumpTarget[pos].GetPositionX(), vChampionJumpTarget[pos].GetPositionY(), vChampionJumpTarget[pos].GetPositionZ(), 20.0f, 20.0f);
                            temp->SetOrientation(0);
                        }
                        else
                        {
                            temp->SetHomePosition((ToCCommonLoc[1].GetPositionX()*2)-vChampionJumpTarget[pos].GetPositionX(), vChampionJumpTarget[pos].GetPositionY(), vChampionJumpTarget[pos].GetPositionZ(), 3);
                            temp->GetMotionMaster()->MoveJump((ToCCommonLoc[1].GetPositionX()*2)-vChampionJumpTarget[pos].GetPositionX(), vChampionJumpTarget[pos].GetPositionY(), vChampionJumpTarget[pos].GetPositionZ(), 20.0f, 20.0f);
                            temp->SetOrientation(3);
                        }
                    }
                    vChampionJumpTarget.erase(vChampionJumpTarget.begin()+pos);
                }
            }

            void SetData(uint32 uiType, uint32 uiData) OVERRIDE
            {
                switch (uiType)
                {
                    case 0:
                        SummonChampions((Team)uiData);
                        break;
                    case 1:
                        for (std::list<uint64>::iterator i = _summons.begin(); i != _summons.end(); ++i)
                        {
                            if (Creature* temp = Unit::GetCreature(*me, *i))
                            {
                                temp->SetReactState(REACT_AGGRESSIVE);
                                temp->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC);
                            }
                        }
                        break;
                    case 2:
                        switch (uiData)
                        {
                            case FAIL:
                                _championsFailed++;
                                if (_championsFailed + _championsKilled >= _summons.size())
                                {
                                    _instance->SetBossState(BOSS_CRUSADERS, FAIL);
                                    _summons.DespawnAll();
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
                                    _summons.DoZoneInCombat();
                                    _instance->SetBossState(BOSS_CRUSADERS, IN_PROGRESS);
                                }
                                break;
                            case DONE:
                                _championsKilled++;
                                if (_championsKilled == 1)
                                    _instance->SetBossState(BOSS_CRUSADERS, SPECIAL);
                                else if (_championsKilled >= _summons.size())
                                {
                                    _instance->SetBossState(BOSS_CRUSADERS, DONE);
                                    _summons.DespawnAll();
                                    me->DespawnOrUnsummon();
                                }
                                break;
                            default:
                                break;
                        }
                        break;
                    default:
                        break;
                }
            }
            private:
                InstanceScript* _instance;
                SummonList _summons;
                uint32 _championsNotStarted;
                uint32 _championsFailed;
                uint32 _championsKilled;
                bool   _inProgress;
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return GetInstanceAI<boss_toc_champion_controllerAI>(creature);
        }
};

struct boss_faction_championsAI : public BossAI
{
    boss_faction_championsAI(Creature* creature, uint32 aitype) : BossAI(creature, BOSS_CRUSADERS)
    {
        _aiType = aitype;
    }

    void Reset() OVERRIDE
    {
        _events.ScheduleEvent(EVENT_THREAT, 5*IN_MILLISECONDS);
        if (IsHeroic() && (_aiType != AI_PET))
            _events.ScheduleEvent(EVENT_REMOVE_CC, 5*IN_MILLISECONDS);
    }

    void JustReachedHome() OVERRIDE
    {
        if (instance)
            if (Creature* pChampionController = Unit::GetCreature((*me), instance->GetData64(NPC_CHAMPIONS_CONTROLLER)))
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
        std::list<HostileReference*> const& tList = me->getThreatManager().getThreatList();
        for (std::list<HostileReference*>::const_iterator itr = tList.begin(); itr != tList.end(); ++itr)
        {
            Unit* unit = Unit::GetUnit(*me, (*itr)->getUnitGuid());
            if (unit && me->getThreatManager().getThreat(unit))
            {
                if (unit->GetTypeId() == TYPEID_PLAYER)
                {
                    float threat = CalculateThreat(me->GetDistance2d(unit), (float)unit->GetArmor(), unit->GetHealth());
                    me->getThreatManager().modifyThreatPercent(unit, -100);
                    me->AddThreat(unit, 1000000.0f * threat);
                }
            }
        }
    }

    void UpdatePower()
    {
        if (me->getPowerType() == POWER_MANA)
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

    void JustDied(Unit* /*killer*/) OVERRIDE
    {
        if (_aiType != AI_PET)
            if (instance)
                if (Creature* pChampionController = Unit::GetCreature((*me), instance->GetData64(NPC_CHAMPIONS_CONTROLLER)))
                    pChampionController->AI()->SetData(2, DONE);
    }

    void EnterCombat(Unit* /*who*/) OVERRIDE
    {
        DoCast(me, SPELL_ANTI_AOE, true);
        _EnterCombat();
        if (instance)
            if (Creature* pChampionController = Unit::GetCreature((*me), instance->GetData64(NPC_CHAMPIONS_CONTROLLER)))
                pChampionController->AI()->SetData(2, IN_PROGRESS);
    }

    void KilledUnit(Unit* who) OVERRIDE
    {
        if (who->GetTypeId() == TYPEID_PLAYER)
        {
            Map::PlayerList const &players = me->GetMap()->GetPlayers();
            uint32 TeamInInstance = 0;

            if (!players.isEmpty())
                if (Player* player = players.begin()->GetSource())
                    TeamInInstance = player->GetTeam();

            if (instance)
            {
                if (TeamInInstance == ALLIANCE)
                {
                    if (Creature* temp = Unit::GetCreature(*me, instance->GetData64(NPC_VARIAN)))
                        temp->AI()->Talk(SAY_KILL_PLAYER);
                }
                else
                    if (Creature* temp = Unit::GetCreature(*me, instance->GetData64(NPC_GARROSH)))
                        temp->AI()->Talk(SAY_KILL_PLAYER);


                instance->SetData(DATA_TRIBUTE_TO_IMMORTALITY_ELIGIBLE, 0);
            }
        }
    }

    Creature* SelectRandomFriendlyMissingBuff(uint32 spell)
    {
        std::list<Creature*> lst = DoFindFriendlyMissingBuff(40.0f, spell);
        std::list<Creature*>::const_iterator itr = lst.begin();
        if (lst.empty())
            return NULL;
        advance(itr, rand() % lst.size());
        return (*itr);
    }

    Unit* SelectEnemyCaster(bool /*casting*/)
    {
        std::list<HostileReference*> const& tList = me->getThreatManager().getThreatList();
        std::list<HostileReference*>::const_iterator iter;
        Unit* target;
        for (iter = tList.begin(); iter!=tList.end(); ++iter)
        {
            target = Unit::GetUnit(*me, (*iter)->getUnitGuid());
            if (target && target->getPowerType() == POWER_MANA)
                return target;
        }
        return NULL;
    }

    uint32 EnemiesInRange(float distance)
    {
        std::list<HostileReference*> const& tList = me->getThreatManager().getThreatList();
        std::list<HostileReference*>::const_iterator iter;
        uint32 count = 0;
        Unit* target;
        for (iter = tList.begin(); iter != tList.end(); ++iter)
        {
            target = Unit::GetUnit(*me, (*iter)->getUnitGuid());
                if (target && me->GetDistance2d(target) < distance)
                    ++count;
        }
        return count;
    }

    void AttackStart(Unit* who) OVERRIDE
    {
        if (!who)
            return;

        if (me->Attack(who, true))
        {
            me->AddThreat(who, 10.0f);
            me->SetInCombatWith(who);
            who->SetInCombatWith(me);

            if (_aiType == AI_MELEE || _aiType == AI_PET)
                DoStartMovement(who);
            else
                DoStartMovement(who, 20.0f);
            SetCombatMovement(true);
        }
    }

    void UpdateAI(uint32 diff) OVERRIDE
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_THREAT:
                    UpdatePower();
                    UpdateThreat();
                    _events.ScheduleEvent(EVENT_THREAT, 4*IN_MILLISECONDS);
                    return;
                case EVENT_REMOVE_CC:
                    if (me->HasBreakableByDamageCrowdControlAura())
                    {
                        RemoveCC();
                        _events.RescheduleEvent(EVENT_REMOVE_CC, 2*MINUTE*IN_MILLISECONDS);
                    }
                    else
                        _events.RescheduleEvent(EVENT_REMOVE_CC, 3*IN_MILLISECONDS);
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
        // make sure that every bosses separate events dont mix with these _events
        EventMap _events;
};

/********************************************************************
                            HEALERS
********************************************************************/
class npc_toc_druid : public CreatureScript
{
    public:
        npc_toc_druid() : CreatureScript("npc_toc_druid") { }

        struct npc_toc_druidAI : public boss_faction_championsAI
        {
            npc_toc_druidAI(Creature* creature) : boss_faction_championsAI(creature, AI_HEALER) { }

            void Reset() OVERRIDE
            {
                boss_faction_championsAI::Reset();
                events.ScheduleEvent(EVENT_LIFEBLOOM, urand(5*IN_MILLISECONDS, 15*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_NOURISH, urand(5*IN_MILLISECONDS, 15*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_REGROWTH, urand(5*IN_MILLISECONDS, 15*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_REJUVENATION, urand(5*IN_MILLISECONDS, 15*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_TRANQUILITY, urand(5*IN_MILLISECONDS, 20*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_HEAL_BARKSKIN, urand(15*IN_MILLISECONDS, 25*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_THORNS, 2*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_NATURE_GRASP, urand(3*IN_MILLISECONDS, 20*IN_MILLISECONDS));
                SetEquipmentSlots(false, 51799, EQUIP_NO_CHANGE, EQUIP_NO_CHANGE);
            }

            void UpdateAI(uint32 diff) OVERRIDE
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
                            events.ScheduleEvent(EVENT_LIFEBLOOM, urand(5*IN_MILLISECONDS, 15*IN_MILLISECONDS));
                            return;
                        case EVENT_NOURISH:
                            if (Unit* target = DoSelectLowestHpFriendly(40.0f))
                                DoCast(target, SPELL_NOURISH);
                            events.ScheduleEvent(EVENT_NOURISH, urand(5*IN_MILLISECONDS, 15*IN_MILLISECONDS));
                            return;
                        case EVENT_REGROWTH:
                            if (Unit* target = DoSelectLowestHpFriendly(40.0f))
                                DoCast(target, SPELL_REGROWTH);
                            events.ScheduleEvent(EVENT_REGROWTH, urand(5*IN_MILLISECONDS, 15*IN_MILLISECONDS));
                            return;
                        case EVENT_REJUVENATION:
                            if (Unit* target = DoSelectLowestHpFriendly(40.0f))
                                DoCast(target, SPELL_REJUVENATION);
                            events.ScheduleEvent(EVENT_REJUVENATION, urand(5*IN_MILLISECONDS, 15*IN_MILLISECONDS));
                            return;
                        case EVENT_TRANQUILITY:
                            DoCastAOE(SPELL_TRANQUILITY);
                            events.ScheduleEvent(EVENT_TRANQUILITY, urand(15*IN_MILLISECONDS, 40*IN_MILLISECONDS));
                            return;
                        case EVENT_HEAL_BARKSKIN:
                            if (HealthBelowPct(30))
                            {
                                DoCast(me, SPELL_BARKSKIN);
                                events.RescheduleEvent(EVENT_HEAL_BARKSKIN, 60*IN_MILLISECONDS);
                            }
                            else
                                events.RescheduleEvent(EVENT_HEAL_BARKSKIN, 3*IN_MILLISECONDS);
                            return;
                        case EVENT_THORNS:
                            if (Creature* target = SelectRandomFriendlyMissingBuff(SPELL_THORNS))
                                DoCast(target, SPELL_THORNS);
                            events.ScheduleEvent(EVENT_THORNS, urand(25*IN_MILLISECONDS, 40*IN_MILLISECONDS));
                            return;
                        case EVENT_NATURE_GRASP:
                            DoCast(me, SPELL_NATURE_GRASP);
                            events.ScheduleEvent(EVENT_NATURE_GRASP, 60*IN_MILLISECONDS);
                            return;
                        default:
                            return;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return GetInstanceAI<npc_toc_druidAI>(creature);
        }
};

class npc_toc_shaman : public CreatureScript
{
    public:
        npc_toc_shaman() : CreatureScript("npc_toc_shaman") { }

        struct npc_toc_shamanAI : public boss_faction_championsAI
        {
            npc_toc_shamanAI(Creature* creature) : boss_faction_championsAI(creature, AI_HEALER) { }

            void Reset() OVERRIDE
            {
                boss_faction_championsAI::Reset();
                events.ScheduleEvent(EVENT_HEALING_WAVE, urand(5*IN_MILLISECONDS, 10*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_RIPTIDE, urand(5*IN_MILLISECONDS, 20*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_SPIRIT_CLEANSE, urand(15*IN_MILLISECONDS, 25*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_HEAL_BLOODLUST_HEROISM, 20*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_HEX, urand(5*IN_MILLISECONDS, 30*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_EARTH_SHIELD, 1*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_HEAL_EARTH_SHOCK, urand(5*IN_MILLISECONDS, 30*IN_MILLISECONDS));
                SetEquipmentSlots(false, 49992, EQUIP_NO_CHANGE, EQUIP_NO_CHANGE);
            }

            void UpdateAI(uint32 diff) OVERRIDE
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
                            events.ScheduleEvent(EVENT_HEALING_WAVE, urand(3*IN_MILLISECONDS, 5*IN_MILLISECONDS));
                            return;
                        case EVENT_RIPTIDE:
                            if (Unit* target = DoSelectLowestHpFriendly(40.0f))
                                DoCast(target, SPELL_RIPTIDE);
                            events.ScheduleEvent(EVENT_RIPTIDE, urand(5*IN_MILLISECONDS, 15*IN_MILLISECONDS));
                            return;
                        case EVENT_SPIRIT_CLEANSE:
                            if (Unit* target = DoSelectLowestHpFriendly(40.0f))
                                DoCast(target, SPELL_SPIRIT_CLEANSE);
                            events.ScheduleEvent(EVENT_SPIRIT_CLEANSE, urand(15*IN_MILLISECONDS, 35*IN_MILLISECONDS));
                            return;
                        case EVENT_HEAL_BLOODLUST_HEROISM:
                            if (me->getFaction()) // alliance = 1
                            {
                                if (!me->HasAura(AURA_EXHAUSTION))
                                    DoCastAOE(SPELL_HEROISM);
                            }
                            else
                            {
                                if (!me->HasAura(AURA_SATED))
                                    DoCastAOE(SPELL_BLOODLUST);
                            }
                            events.ScheduleEvent(EVENT_HEAL_BLOODLUST_HEROISM, 5*MINUTE*IN_MILLISECONDS);
                            return;
                        case EVENT_HEX:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, NonTankTargetSelector(me)))
                                DoCast(target, SPELL_HEX);
                            events.ScheduleEvent(EVENT_HEX, urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS));
                            return;
                        case EVENT_EARTH_SHIELD:
                            if (Creature* target = SelectRandomFriendlyMissingBuff(SPELL_EARTH_SHIELD))
                                DoCast(target, SPELL_EARTH_SHIELD);
                            events.ScheduleEvent(EVENT_EARTH_SHIELD, urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS));
                            return;
                        case EVENT_HEAL_EARTH_SHOCK:
                            if (Unit* target = SelectEnemyCaster(true))
                                DoCast(target, SPELL_EARTH_SHOCK);
                            events.ScheduleEvent(EVENT_HEAL_EARTH_SHOCK, urand(10*IN_MILLISECONDS, 20*IN_MILLISECONDS));
                            return;
                        default:
                            return;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return GetInstanceAI<npc_toc_shamanAI>(creature);
        }
};

class npc_toc_paladin : public CreatureScript
{
    public:
        npc_toc_paladin() : CreatureScript("npc_toc_paladin") { }

        struct npc_toc_paladinAI : public boss_faction_championsAI
        {
            npc_toc_paladinAI(Creature* creature) : boss_faction_championsAI(creature, AI_HEALER) { }

            void Reset() OVERRIDE
            {
                boss_faction_championsAI::Reset();
                events.ScheduleEvent(EVENT_HAND_OF_FREEDOM, urand(10*IN_MILLISECONDS, 20*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_HEAL_DIVINE_SHIELD, 20*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_CLEANSE, urand(20*IN_MILLISECONDS, 30*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_FLASH_OF_LIGHT, urand(5*IN_MILLISECONDS, 10*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_HOLY_LIGHT, urand(10*IN_MILLISECONDS, 15*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_HOLY_SHOCK, urand(10*IN_MILLISECONDS, 15*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_HEAL_HAND_OF_PROTECTION, urand(30*IN_MILLISECONDS, 60*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_HAMMER_OF_JUSTICE, urand(10*IN_MILLISECONDS, 30*IN_MILLISECONDS));
                SetEquipmentSlots(false, 50771, 47079, EQUIP_NO_CHANGE);
            }

            void UpdateAI(uint32 diff) OVERRIDE
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
                            events.ScheduleEvent(EVENT_HAND_OF_FREEDOM, urand(15*IN_MILLISECONDS, 35*IN_MILLISECONDS));
                            return;
                        case EVENT_HEAL_DIVINE_SHIELD:
                            if (HealthBelowPct(30) && !me->HasAura(SPELL_FORBEARANCE))
                            {
                                DoCast(me, SPELL_DIVINE_SHIELD);
                                events.RescheduleEvent(EVENT_HEAL_DIVINE_SHIELD, 5*MINUTE*IN_MILLISECONDS);
                            }
                            else
                                events.RescheduleEvent(EVENT_HEAL_DIVINE_SHIELD, 5*IN_MILLISECONDS);
                            return;
                        case EVENT_CLEANSE:
                            if (Unit* target = DoSelectLowestHpFriendly(40.0f))
                                DoCast(target, SPELL_CLEANSE);
                            events.ScheduleEvent(EVENT_CLEANSE, urand(10*IN_MILLISECONDS, 30*IN_MILLISECONDS));
                            return;
                        case EVENT_FLASH_OF_LIGHT:
                            if (Unit* target = DoSelectLowestHpFriendly(40.0f))
                                DoCast(target, SPELL_FLASH_OF_LIGHT);
                            events.ScheduleEvent(EVENT_FLASH_OF_LIGHT, urand(3*IN_MILLISECONDS, 5*IN_MILLISECONDS));
                            return;
                        case EVENT_HOLY_LIGHT:
                            if (Unit* target = DoSelectLowestHpFriendly(40.0f))
                                DoCast(target, SPELL_HOLY_LIGHT);
                            events.ScheduleEvent(EVENT_HOLY_LIGHT, urand(5*IN_MILLISECONDS, 10*IN_MILLISECONDS));
                            return;
                        case EVENT_HOLY_SHOCK:
                            if (Unit* target = DoSelectLowestHpFriendly(40.0f))
                                DoCast(target, SPELL_HOLY_SHOCK);
                            events.ScheduleEvent(EVENT_HOLY_SHOCK, urand(10*IN_MILLISECONDS, 15*IN_MILLISECONDS));
                            return;
                        case EVENT_HEAL_HAND_OF_PROTECTION:
                            if (Unit* target = DoSelectLowestHpFriendly(30.0f))
                            {
                                if (!target->HasAura(SPELL_FORBEARANCE))
                                {
                                    DoCast(target, SPELL_HAND_OF_PROTECTION);
                                    events.RescheduleEvent(EVENT_HEAL_HAND_OF_PROTECTION, 5*MINUTE*IN_MILLISECONDS);
                                }
                                else
                                    events.RescheduleEvent(EVENT_HEAL_HAND_OF_PROTECTION, 3*IN_MILLISECONDS);
                            }
                            else
                                events.RescheduleEvent(EVENT_HEAL_HAND_OF_PROTECTION, 10*IN_MILLISECONDS);
                            return;
                        case EVENT_HAMMER_OF_JUSTICE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 15.0f, true))
                                DoCast(target, SPELL_HAMMER_OF_JUSTICE);
                            events.ScheduleEvent(EVENT_HAMMER_OF_JUSTICE, 40*IN_MILLISECONDS);
                            return;
                        default:
                            return;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return GetInstanceAI<npc_toc_paladinAI>(creature);
        }
};

class npc_toc_priest : public CreatureScript
{
    public:
        npc_toc_priest() : CreatureScript("npc_toc_priest") { }

        struct npc_toc_priestAI : public boss_faction_championsAI
        {
            npc_toc_priestAI(Creature* creature) : boss_faction_championsAI(creature, AI_HEALER) { }

            void Reset() OVERRIDE
            {
                boss_faction_championsAI::Reset();
                events.ScheduleEvent(EVENT_RENEW, urand(3*IN_MILLISECONDS, 10*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_SHIELD, urand(5*IN_MILLISECONDS, 15*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_FLASH_HEAL, urand(5*IN_MILLISECONDS, 10*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_HEAL_DISPEL, urand(10*IN_MILLISECONDS, 20*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_HEAL_PSYCHIC_SCREAM, urand(10*IN_MILLISECONDS, 30*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_MANA_BURN, urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_PENANCE, urand(10*IN_MILLISECONDS, 20*IN_MILLISECONDS));
                SetEquipmentSlots(false, 49992, EQUIP_NO_CHANGE, EQUIP_NO_CHANGE);
            }

            void UpdateAI(uint32 diff) OVERRIDE
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
                            events.ScheduleEvent(EVENT_RENEW, urand(3*IN_MILLISECONDS, 5*IN_MILLISECONDS));
                            return;
                        case EVENT_SHIELD:
                            if (Unit* target = DoSelectLowestHpFriendly(40.0f))
                                DoCast(target, SPELL_SHIELD);
                            events.ScheduleEvent(EVENT_SHIELD, urand(15*IN_MILLISECONDS, 35*IN_MILLISECONDS));
                            return;
                        case EVENT_FLASH_HEAL:
                            if (Unit* target = DoSelectLowestHpFriendly(40.0f))
                                DoCast(target, SPELL_FLASH_HEAL);
                            events.ScheduleEvent(EVENT_FLASH_HEAL, urand(3*IN_MILLISECONDS, 5*IN_MILLISECONDS));
                            return;
                        case EVENT_HEAL_DISPEL:
                            if (Unit* target = urand(0, 1) ? SelectTarget(SELECT_TARGET_RANDOM, 0, 30.0f, true) : DoSelectLowestHpFriendly(40.0f))
                                DoCast(target, SPELL_DISPEL);
                            events.ScheduleEvent(EVENT_HEAL_DISPEL, urand(10*IN_MILLISECONDS, 20*IN_MILLISECONDS));
                            return;
                        case EVENT_HEAL_PSYCHIC_SCREAM:
                            if (EnemiesInRange(10.0f) >= 2)
                                DoCastAOE(SPELL_PSYCHIC_SCREAM);
                            events.ScheduleEvent(EVENT_HEAL_PSYCHIC_SCREAM, urand(10*IN_MILLISECONDS, 25*IN_MILLISECONDS));
                            return;
                        case EVENT_MANA_BURN:
                            if (Unit* target = SelectEnemyCaster(false))
                                DoCast(target, SPELL_MANA_BURN);
                            events.ScheduleEvent(EVENT_MANA_BURN, urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS));
                            return;
                        case EVENT_PENANCE:
                            if (Unit* target = DoSelectLowestHpFriendly(40.0f))
                                DoCast(target, SPELL_PENANCE);
                            events.ScheduleEvent(EVENT_PENANCE, urand(10*IN_MILLISECONDS, 20*IN_MILLISECONDS));
                            return;
                        default:
                            return;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return GetInstanceAI<npc_toc_priestAI>(creature);
        }
};

/********************************************************************
                            RANGED
********************************************************************/
class npc_toc_shadow_priest : public CreatureScript
{
    public:
        npc_toc_shadow_priest() : CreatureScript("npc_toc_shadow_priest") { }

        struct npc_toc_shadow_priestAI : public boss_faction_championsAI
        {
            npc_toc_shadow_priestAI(Creature* creature) : boss_faction_championsAI(creature, AI_RANGED) { }

            void Reset() OVERRIDE
            {
                boss_faction_championsAI::Reset();
                events.ScheduleEvent(EVENT_SILENCE, urand(10*IN_MILLISECONDS, 25*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_VAMPIRIC_TOUCH, urand(5*IN_MILLISECONDS, 15*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_SW_PAIN, urand(3*IN_MILLISECONDS, 10*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_MIND_BLAST, urand(5*IN_MILLISECONDS, 15*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_HORROR, urand(10*IN_MILLISECONDS, 25*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_DISPERSION, urand(20*IN_MILLISECONDS, 40*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_DPS_DISPEL, urand(10*IN_MILLISECONDS, 20*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_DPS_PSYCHIC_SCREAM, urand(10*IN_MILLISECONDS, 30*IN_MILLISECONDS));
                SetEquipmentSlots(false, 50040, EQUIP_NO_CHANGE, EQUIP_NO_CHANGE);
                DoCast(me, SPELL_SHADOWFORM);
            }

            void UpdateAI(uint32 diff) OVERRIDE
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
                            events.ScheduleEvent(EVENT_SILENCE, urand(10*IN_MILLISECONDS, 25*IN_MILLISECONDS));
                            return;
                        case EVENT_VAMPIRIC_TOUCH:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 30.0f, true))
                                DoCast(target, SPELL_VAMPIRIC_TOUCH);
                            events.ScheduleEvent(EVENT_VAMPIRIC_TOUCH, urand(10*IN_MILLISECONDS, 35*IN_MILLISECONDS));
                            return;
                        case EVENT_SW_PAIN:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 40.0f, true))
                                DoCast(target, SPELL_SW_PAIN);
                            events.ScheduleEvent(EVENT_SW_PAIN, urand(10*IN_MILLISECONDS, 35*IN_MILLISECONDS));
                            return;
                        case EVENT_MIND_BLAST:
                            DoCastVictim(SPELL_MIND_BLAST);
                            events.ScheduleEvent(EVENT_MIND_BLAST, urand(10*IN_MILLISECONDS, 20*IN_MILLISECONDS));
                            return;
                        case EVENT_HORROR:
                            DoCastVictim(SPELL_HORROR);
                            events.ScheduleEvent(EVENT_HORROR, urand(15*IN_MILLISECONDS, 35*IN_MILLISECONDS));
                            return;
                        case EVENT_DISPERSION:
                            if (HealthBelowPct(40))
                            {
                                DoCast(me, SPELL_DISPERSION);
                                events.RescheduleEvent(EVENT_DISPERSION, 180*IN_MILLISECONDS);
                            }
                            else
                                events.RescheduleEvent(EVENT_DISPERSION, 5*IN_MILLISECONDS);
                            return;
                        case EVENT_DPS_DISPEL:
                            if (Unit* target = urand(0, 1) ? SelectTarget(SELECT_TARGET_RANDOM, 0, 30.0f, true) : DoSelectLowestHpFriendly(40.0f))
                                DoCast(target, SPELL_DISPEL);
                            events.ScheduleEvent(EVENT_DPS_DISPEL, urand(10*IN_MILLISECONDS, 20*IN_MILLISECONDS));
                            return;
                        case EVENT_DPS_PSYCHIC_SCREAM:
                            if (EnemiesInRange(10.0f) >= 2)
                                DoCastAOE(SPELL_PSYCHIC_SCREAM);
                            events.ScheduleEvent(EVENT_DPS_PSYCHIC_SCREAM, urand(10*IN_MILLISECONDS, 25*IN_MILLISECONDS));
                            return;
                        default:
                            return;
                    }
                }
                DoSpellAttackIfReady(SPELL_MIND_FLAY);
            }
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return GetInstanceAI<npc_toc_shadow_priestAI>(creature);
        }
};

class npc_toc_warlock : public CreatureScript
{
    public:
        npc_toc_warlock() : CreatureScript("npc_toc_warlock") { }

        struct npc_toc_warlockAI : public boss_faction_championsAI
        {
            npc_toc_warlockAI(Creature* creature) : boss_faction_championsAI(creature, AI_RANGED) { }

            void Reset() OVERRIDE
            {
                boss_faction_championsAI::Reset();
                events.ScheduleEvent(EVENT_HELLFIRE, urand(10*IN_MILLISECONDS, 30*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_CORRUPTION, urand(2*IN_MILLISECONDS, 5*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_CURSE_OF_AGONY, urand(5*IN_MILLISECONDS, 10*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_CURSE_OF_EXHAUSTION, urand(5*IN_MILLISECONDS, 10*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_FEAR, urand(5*IN_MILLISECONDS, 15*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_SEARING_PAIN, urand(5*IN_MILLISECONDS, 12*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_UNSTABLE_AFFLICTION, urand(7*IN_MILLISECONDS, 15*IN_MILLISECONDS));
                SetEquipmentSlots(false, 49992, EQUIP_NO_CHANGE, EQUIP_NO_CHANGE);
            }

            void EnterCombat(Unit* who) OVERRIDE
            {
                boss_faction_championsAI::EnterCombat(who);
                DoCast(SPELL_SUMMON_FELHUNTER);
            }

            void UpdateAI(uint32 diff) OVERRIDE
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
                            events.ScheduleEvent(EVENT_HELLFIRE, urand(10*IN_MILLISECONDS, 30*IN_MILLISECONDS));
                            return;
                        case EVENT_CORRUPTION:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 30.0f))
                                DoCast(target, SPELL_CORRUPTION);
                            events.ScheduleEvent(EVENT_CORRUPTION, urand(15*IN_MILLISECONDS, 25*IN_MILLISECONDS));
                            return;
                        case EVENT_CURSE_OF_AGONY:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 30.0f))
                                DoCast(target, SPELL_CURSE_OF_AGONY);
                            events.ScheduleEvent(EVENT_CURSE_OF_AGONY, urand(20*IN_MILLISECONDS, 35*IN_MILLISECONDS));
                            return;
                        case EVENT_CURSE_OF_EXHAUSTION:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 30.0f))
                                DoCast(target, SPELL_CURSE_OF_EXHAUSTION);
                            events.ScheduleEvent(EVENT_CURSE_OF_EXHAUSTION, urand(20*IN_MILLISECONDS, 35*IN_MILLISECONDS));
                            return;
                        case EVENT_FEAR:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 20.0f, true))
                                DoCast(target, SPELL_FEAR);
                            events.ScheduleEvent(EVENT_FEAR, urand(5*IN_MILLISECONDS, 20*IN_MILLISECONDS));
                            return;
                        case EVENT_SEARING_PAIN:
                            DoCastVictim(SPELL_SEARING_PAIN);
                            events.ScheduleEvent(EVENT_SEARING_PAIN, urand(10*IN_MILLISECONDS, 25*IN_MILLISECONDS));
                            return;
                        case EVENT_UNSTABLE_AFFLICTION:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 30.0f, true))
                                DoCast(target, SPELL_UNSTABLE_AFFLICTION);
                            events.ScheduleEvent(EVENT_UNSTABLE_AFFLICTION, urand(10*IN_MILLISECONDS, 25*IN_MILLISECONDS));
                            return;
                        default:
                            return;
                    }
                }
                DoSpellAttackIfReady(SPELL_SHADOW_BOLT);
            }
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return GetInstanceAI<npc_toc_warlockAI>(creature);
        }
};

class npc_toc_mage : public CreatureScript
{
    public:
        npc_toc_mage() : CreatureScript("npc_toc_mage") { }

        struct npc_toc_mageAI : public boss_faction_championsAI
        {
            npc_toc_mageAI(Creature* creature) : boss_faction_championsAI(creature, AI_RANGED) { }

            void Reset() OVERRIDE
            {
                boss_faction_championsAI::Reset();
                events.ScheduleEvent(EVENT_ARCANE_BARRAGE, urand(1*IN_MILLISECONDS, 5*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_ARCANE_BLAST, urand(3*IN_MILLISECONDS, 5*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_ARCANE_EXPLOSION, urand(5*IN_MILLISECONDS, 15*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_BLINK, urand(15*IN_MILLISECONDS, 20*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_COUNTERSPELL, urand(10*IN_MILLISECONDS, 20*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_FROST_NOVA, urand(5*IN_MILLISECONDS, 20*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_ICE_BLOCK, urand(10*IN_MILLISECONDS, 20*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_POLYMORPH, urand(5*IN_MILLISECONDS, 15*IN_MILLISECONDS));
                SetEquipmentSlots(false, 47524, EQUIP_NO_CHANGE, EQUIP_NO_CHANGE);
            }

            void UpdateAI(uint32 diff) OVERRIDE
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
                            events.ScheduleEvent(EVENT_ARCANE_BARRAGE, urand(5*IN_MILLISECONDS, 7*IN_MILLISECONDS));
                            return;
                        case EVENT_ARCANE_BLAST:
                            DoCastVictim(SPELL_ARCANE_BLAST);
                            events.ScheduleEvent(EVENT_ARCANE_BLAST, urand(5*IN_MILLISECONDS, 15*IN_MILLISECONDS));
                            return;
                        case EVENT_ARCANE_EXPLOSION:
                            if (EnemiesInRange(10.0f) >= 2)
                                DoCastAOE(SPELL_ARCANE_EXPLOSION);
                            events.ScheduleEvent(EVENT_ARCANE_EXPLOSION, urand(10*IN_MILLISECONDS, 30*IN_MILLISECONDS));
                            return;
                        case EVENT_BLINK:
                            if (EnemiesInRange(10.0f) >= 2)
                                DoCast(SPELL_BLINK);
                            events.ScheduleEvent(EVENT_BLINK, urand(10*IN_MILLISECONDS, 30*IN_MILLISECONDS));
                            return;
                        case EVENT_COUNTERSPELL:
                            if (Unit* target = SelectEnemyCaster(true))
                                DoCast(target, SPELL_COUNTERSPELL);
                            events.ScheduleEvent(EVENT_COUNTERSPELL, 24*IN_MILLISECONDS);
                            return;
                        case EVENT_FROST_NOVA:
                            if (EnemiesInRange(10.0f) >= 2)
                                DoCastAOE(SPELL_FROST_NOVA);
                            events.ScheduleEvent(EVENT_FROST_NOVA, 25*IN_MILLISECONDS);
                            return;
                        case EVENT_ICE_BLOCK:
                            if (HealthBelowPct(30))
                            {
                                DoCast(SPELL_ICE_BLOCK);
                                events.RescheduleEvent(EVENT_ICE_BLOCK, 5*MINUTE*IN_MILLISECONDS);
                            }
                            else
                                events.RescheduleEvent(EVENT_ICE_BLOCK, 5*IN_MILLISECONDS);
                            return;
                        case EVENT_POLYMORPH:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, NonTankTargetSelector(me)))
                                DoCast(target, SPELL_POLYMORPH);
                            events.ScheduleEvent(EVENT_POLYMORPH, urand(10*IN_MILLISECONDS, 30*IN_MILLISECONDS));
                            return;
                        default:
                            return;
                    }
                }
                DoSpellAttackIfReady(SPELL_FROSTBOLT);
            }
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return GetInstanceAI<npc_toc_mageAI>(creature);
        }
};

class npc_toc_hunter : public CreatureScript
{
    public:
        npc_toc_hunter() : CreatureScript("npc_toc_hunter") { }

        struct npc_toc_hunterAI : public boss_faction_championsAI
        {
            npc_toc_hunterAI(Creature* creature) : boss_faction_championsAI(creature, AI_RANGED) { }

            void Reset() OVERRIDE
            {
                boss_faction_championsAI::Reset();
                events.ScheduleEvent(EVENT_AIMED_SHOT, urand(5*IN_MILLISECONDS, 10*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_DETERRENCE, urand(10*IN_MILLISECONDS, 20*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_DISENGAGE, urand(10*IN_MILLISECONDS, 20*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_EXPLOSIVE_SHOT, urand(3*IN_MILLISECONDS, 5*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_FROST_TRAP, urand(10*IN_MILLISECONDS, 20*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_STEADY_SHOT, urand(5*IN_MILLISECONDS, 10*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_WING_CLIP, urand(10*IN_MILLISECONDS, 20*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_WYVERN_STING, urand(10*IN_MILLISECONDS, 25*IN_MILLISECONDS));
                SetEquipmentSlots(false, 47156, EQUIP_NO_CHANGE, 48711);
            }

            void EnterCombat(Unit* who) OVERRIDE
            {
                boss_faction_championsAI::EnterCombat(who);
                DoCast(SPELL_CALL_PET);
            }

            void UpdateAI(uint32 diff) OVERRIDE
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
                            events.ScheduleEvent(EVENT_AIMED_SHOT, urand(10*IN_MILLISECONDS, 15*IN_MILLISECONDS));
                            return;
                        case EVENT_DETERRENCE:
                            if (HealthBelowPct(30))
                            {
                                DoCast(SPELL_DETERRENCE);
                                events.RescheduleEvent(EVENT_DETERRENCE, 150*IN_MILLISECONDS);
                            }
                            else
                                events.RescheduleEvent(EVENT_DETERRENCE, 10*IN_MILLISECONDS);
                            return;
                        case EVENT_DISENGAGE:
                            if (EnemiesInRange(10.0f) >= 2)
                                DoCast(SPELL_DISENGAGE);
                            events.ScheduleEvent(EVENT_DISENGAGE, 30*IN_MILLISECONDS);
                            return;
                        case EVENT_EXPLOSIVE_SHOT:
                            DoCastVictim(SPELL_EXPLOSIVE_SHOT);
                            events.ScheduleEvent(EVENT_EXPLOSIVE_SHOT, urand(6*IN_MILLISECONDS, 10*IN_MILLISECONDS));
                            return;
                        case EVENT_FROST_TRAP:
                            if (EnemiesInRange(10.0f) >= 2)
                                DoCastAOE(SPELL_FROST_TRAP);
                            events.ScheduleEvent(EVENT_FROST_TRAP, 30*IN_MILLISECONDS);
                            return;
                        case EVENT_STEADY_SHOT:
                            DoCastVictim(SPELL_STEADY_SHOT);
                            events.ScheduleEvent(EVENT_STEADY_SHOT, urand(5*IN_MILLISECONDS, 15*IN_MILLISECONDS));
                            return;
                        case EVENT_WING_CLIP:
                            if (Unit* target = me->GetVictim())
                            {
                                if (me->GetDistance2d(target) < 6.0f)
                                    DoCast(target, SPELL_WING_CLIP);
                            }
                            events.ScheduleEvent(EVENT_WING_CLIP, urand(15*IN_MILLISECONDS, 25*IN_MILLISECONDS));
                            return;
                        case EVENT_WYVERN_STING:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, NonTankTargetSelector(me)))
                                DoCast(target, SPELL_WYVERN_STING);
                            events.ScheduleEvent(EVENT_WYVERN_STING, urand(10*IN_MILLISECONDS, 30*IN_MILLISECONDS));
                            return;
                        default:
                            return;
                    }
                }
                DoSpellAttackIfReady(SPELL_SHOOT);
            }
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return GetInstanceAI<npc_toc_hunterAI>(creature);
        }
};

class npc_toc_boomkin : public CreatureScript
{
    public:
        npc_toc_boomkin() : CreatureScript("npc_toc_boomkin") { }

        struct npc_toc_boomkinAI : public boss_faction_championsAI
        {
            npc_toc_boomkinAI(Creature* creature) : boss_faction_championsAI(creature, AI_RANGED) { }

            void Reset() OVERRIDE
            {
                boss_faction_championsAI::Reset();
                events.ScheduleEvent(EVENT_CYCLONE, urand(10*IN_MILLISECONDS, 20*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_ENTANGLING_ROOTS, urand(10*IN_MILLISECONDS, 20*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_FAERIE_FIRE, urand(2*IN_MILLISECONDS, 5*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_FORCE_OF_NATURE, urand(20*IN_MILLISECONDS, 30*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_INSECT_SWARM, urand(5*IN_MILLISECONDS, 10*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_MOONFIRE, urand(10*IN_MILLISECONDS, 20*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_STARFIRE, urand(10*IN_MILLISECONDS, 20*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_DPS_BARKSKIN, urand(20*IN_MILLISECONDS, 30*IN_MILLISECONDS));

                SetEquipmentSlots(false, 50966, EQUIP_NO_CHANGE, EQUIP_NO_CHANGE);
            }

            void UpdateAI(uint32 diff) OVERRIDE
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
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, NonTankTargetSelector(me)))
                                DoCast(target, SPELL_CYCLONE);
                            events.ScheduleEvent(EVENT_CYCLONE, urand(10*IN_MILLISECONDS, 20*IN_MILLISECONDS));
                            return;
                        case EVENT_ENTANGLING_ROOTS:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 30.0f, true))
                                DoCast(target, SPELL_ENTANGLING_ROOTS);
                            events.ScheduleEvent(EVENT_ENTANGLING_ROOTS, urand(10*IN_MILLISECONDS, 20*IN_MILLISECONDS));
                            return;
                        case EVENT_FAERIE_FIRE:
                            DoCastVictim(SPELL_FAERIE_FIRE);
                            events.ScheduleEvent(EVENT_FAERIE_FIRE, urand(30*IN_MILLISECONDS, 40*IN_MILLISECONDS));
                            return;
                        case EVENT_FORCE_OF_NATURE:
                            DoCastVictim(SPELL_FORCE_OF_NATURE);
                            events.ScheduleEvent(EVENT_FORCE_OF_NATURE, 180*IN_MILLISECONDS);
                            return;
                        case EVENT_INSECT_SWARM:
                            DoCastVictim(SPELL_INSECT_SWARM);
                            events.ScheduleEvent(EVENT_INSECT_SWARM, urand(15*IN_MILLISECONDS, 25*IN_MILLISECONDS));
                            return;
                        case EVENT_MOONFIRE:
                            DoCastVictim(SPELL_MOONFIRE);
                            events.ScheduleEvent(EVENT_MOONFIRE, urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS));
                            return;
                        case EVENT_STARFIRE:
                            DoCastVictim(SPELL_STARFIRE);
                            events.ScheduleEvent(EVENT_STARFIRE, urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS));
                            return;
                        case EVENT_DPS_BARKSKIN:
                            if (HealthBelowPct(30))
                            {
                                DoCast(me, SPELL_BARKSKIN);
                                events.RescheduleEvent(EVENT_DPS_BARKSKIN, 60*IN_MILLISECONDS);
                            }
                            else
                                events.RescheduleEvent(EVENT_DPS_BARKSKIN, 5*IN_MILLISECONDS);
                            return;
                        default:
                            return;
                    }
                }
                DoSpellAttackIfReady(SPELL_WRATH);
            }
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return GetInstanceAI<npc_toc_boomkinAI>(creature);
        }
};

/********************************************************************
                            MELEE
********************************************************************/
class npc_toc_warrior : public CreatureScript
{
    public:
        npc_toc_warrior() : CreatureScript("npc_toc_warrior") { }

        struct npc_toc_warriorAI : public boss_faction_championsAI
        {
            npc_toc_warriorAI(Creature* creature) : boss_faction_championsAI(creature, AI_MELEE) { }

            void Reset() OVERRIDE
            {
                boss_faction_championsAI::Reset();
                events.ScheduleEvent(EVENT_BLADESTORM, urand(10*IN_MILLISECONDS, 15*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_INTIMIDATING_SHOUT, urand(20*IN_MILLISECONDS, 25*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_MORTAL_STRIKE, urand(5*IN_MILLISECONDS, 20*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_WARR_CHARGE, 1*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_DISARM, urand(5*IN_MILLISECONDS, 20*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_OVERPOWER, urand(10*IN_MILLISECONDS, 20*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_SUNDER_ARMOR, urand(5*IN_MILLISECONDS, 10*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_SHATTERING_THROW, urand(20*IN_MILLISECONDS, 40*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_RETALIATION, urand(5*IN_MILLISECONDS, 20*IN_MILLISECONDS));
                SetEquipmentSlots(false, 47427, 46964, EQUIP_NO_CHANGE);
            }

            void UpdateAI(uint32 diff) OVERRIDE
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
                            events.ScheduleEvent(EVENT_BLADESTORM, 150*IN_MILLISECONDS);
                            return;
                        case EVENT_INTIMIDATING_SHOUT:
                            DoCastAOE(SPELL_INTIMIDATING_SHOUT);
                            events.ScheduleEvent(EVENT_INTIMIDATING_SHOUT, 120*IN_MILLISECONDS);
                            return;
                        case EVENT_MORTAL_STRIKE:
                            DoCastVictim(SPELL_MORTAL_STRIKE);
                            events.ScheduleEvent(EVENT_MORTAL_STRIKE, urand(10*IN_MILLISECONDS, 25*IN_MILLISECONDS));
                            return;
                        case EVENT_WARR_CHARGE:
                            DoCastVictim(SPELL_CHARGE);
                            events.ScheduleEvent(EVENT_WARR_CHARGE, urand(10*IN_MILLISECONDS, 20*IN_MILLISECONDS));
                            return;
                        case EVENT_DISARM:
                            DoCastVictim(SPELL_DISARM);
                            events.ScheduleEvent(EVENT_DISARM, urand(15*IN_MILLISECONDS, 35*IN_MILLISECONDS));
                            return;
                        case EVENT_OVERPOWER:
                            DoCastVictim(SPELL_OVERPOWER);
                            events.ScheduleEvent(EVENT_OVERPOWER, urand(20*IN_MILLISECONDS, 40*IN_MILLISECONDS));
                            return;
                        case EVENT_SUNDER_ARMOR:
                            DoCastVictim(SPELL_SUNDER_ARMOR);
                            events.ScheduleEvent(EVENT_SUNDER_ARMOR, urand(2*IN_MILLISECONDS, 5*IN_MILLISECONDS));
                            return;
                        case EVENT_SHATTERING_THROW:
                            if (Unit* target = me->GetVictim())
                            {
                                if (target->HasAuraWithMechanic(1 << MECHANIC_IMMUNE_SHIELD))
                                {
                                    DoCast(target, SPELL_SHATTERING_THROW);
                                    events.RescheduleEvent(EVENT_SHATTERING_THROW, 5*MINUTE*IN_MILLISECONDS);
                                    return;
                                }
                            }
                            events.RescheduleEvent(EVENT_SHATTERING_THROW, 3*IN_MILLISECONDS);
                            return;
                        case EVENT_RETALIATION:
                            if (HealthBelowPct(50))
                            {
                                DoCast(SPELL_RETALIATION);
                                events.RescheduleEvent(EVENT_RETALIATION, 5*MINUTE*IN_MILLISECONDS);
                            }
                            else
                                events.RescheduleEvent(EVENT_RETALIATION, 5*IN_MILLISECONDS);
                            return;
                        default:
                            return;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return GetInstanceAI<npc_toc_warriorAI>(creature);
        }
};

class npc_toc_dk : public CreatureScript
{
    public:
        npc_toc_dk() : CreatureScript("npc_toc_dk") { }

        struct npc_toc_dkAI : public boss_faction_championsAI
        {
            npc_toc_dkAI(Creature* creature) : boss_faction_championsAI(creature, AI_MELEE) { }

            void Reset() OVERRIDE
            {
                boss_faction_championsAI::Reset();
                events.ScheduleEvent(EVENT_CHAINS_OF_ICE, urand(5*IN_MILLISECONDS, 15*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_DEATH_COIL, urand(10*IN_MILLISECONDS, 20*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_DEATH_GRIP, urand(15*IN_MILLISECONDS, 25*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_FROST_STRIKE, urand(5*IN_MILLISECONDS, 10*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_ICEBOUND_FORTITUDE, urand(25*IN_MILLISECONDS, 35*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_ICY_TOUCH, urand(10*IN_MILLISECONDS, 20*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_STRANGULATE, urand(5*IN_MILLISECONDS, 25*IN_MILLISECONDS));
                SetEquipmentSlots(false, 47518, 51021, EQUIP_NO_CHANGE);
            }

            void UpdateAI(uint32 diff) OVERRIDE
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
                            events.ScheduleEvent(EVENT_CHAINS_OF_ICE, urand(15*IN_MILLISECONDS, 25*IN_MILLISECONDS));
                            return;
                        case EVENT_DEATH_COIL:
                            DoCastVictim(SPELL_DEATH_COIL);
                            events.ScheduleEvent(EVENT_DEATH_COIL, urand(5*IN_MILLISECONDS, 15*IN_MILLISECONDS));
                            return;
                        case EVENT_DEATH_GRIP:
                            if (Unit* target = me->GetVictim())
                            {
                                if (me->IsInRange(target, 5.0f, 30.0f, false))
                                {
                                    DoCast(target, SPELL_DEATH_GRIP);
                                    events.RescheduleEvent(EVENT_DEATH_GRIP, 35*IN_MILLISECONDS);
                                    return;
                                }
                            }
                            events.RescheduleEvent(EVENT_DEATH_GRIP, 3*IN_MILLISECONDS);
                            return;
                        case EVENT_FROST_STRIKE:
                            DoCastVictim(SPELL_FROST_STRIKE);
                            events.ScheduleEvent(EVENT_FROST_STRIKE, urand(6*IN_MILLISECONDS, 10*IN_MILLISECONDS));
                            return;
                        case EVENT_ICEBOUND_FORTITUDE:
                            if (HealthBelowPct(50))
                            {
                                DoCast(SPELL_ICEBOUND_FORTITUDE);
                                events.RescheduleEvent(EVENT_ICEBOUND_FORTITUDE, 60*IN_MILLISECONDS);
                            }
                            else
                                events.RescheduleEvent(EVENT_ICEBOUND_FORTITUDE, 5*IN_MILLISECONDS);
                            return;
                        case EVENT_ICY_TOUCH:
                            DoCastVictim(SPELL_ICY_TOUCH);
                            events.ScheduleEvent(EVENT_ICY_TOUCH, urand(10*IN_MILLISECONDS, 15*IN_MILLISECONDS));
                            return;
                        case EVENT_STRANGULATE:
                            if (Unit* target = SelectEnemyCaster(false))
                            {
                                DoCast(target, SPELL_STRANGULATE);
                                events.RescheduleEvent(EVENT_STRANGULATE, 120*IN_MILLISECONDS);
                            }
                            else
                                events.RescheduleEvent(EVENT_STRANGULATE, 5*IN_MILLISECONDS);
                            return;
                        default:
                            return;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return GetInstanceAI<npc_toc_dkAI>(creature);
        }
};

class npc_toc_rogue : public CreatureScript
{
    public:
        npc_toc_rogue() : CreatureScript("npc_toc_rogue") { }

        struct npc_toc_rogueAI : public boss_faction_championsAI
        {
            npc_toc_rogueAI(Creature* creature) : boss_faction_championsAI(creature, AI_MELEE) { }

            void Reset() OVERRIDE
            {
                boss_faction_championsAI::Reset();
                events.ScheduleEvent(EVENT_FAN_OF_KNIVES, urand(5*IN_MILLISECONDS, 10*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_BLIND, urand(10*IN_MILLISECONDS, 20*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_CLOAK, urand(20*IN_MILLISECONDS, 30*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_BLADE_FLURRY, urand(10*IN_MILLISECONDS, 20*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_SHADOWSTEP, urand(20*IN_MILLISECONDS, 30*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_HEMORRHAGE, urand(3*IN_MILLISECONDS, 10*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_EVISCERATE, urand(20*IN_MILLISECONDS, 40*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_WOUND_POISON, urand(5*IN_MILLISECONDS, 10*IN_MILLISECONDS));
                SetEquipmentSlots(false, 47422, 49982, EQUIP_NO_CHANGE);
                me->setPowerType(POWER_ENERGY);
                me->SetMaxPower(POWER_ENERGY, 100);
            }

            void UpdateAI(uint32 diff) OVERRIDE
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
                            events.ScheduleEvent(EVENT_FAN_OF_KNIVES, urand(10*IN_MILLISECONDS, 20*IN_MILLISECONDS));
                            return;
                        case EVENT_BLIND:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, NonTankTargetSelector(me)))
                                DoCast(target, SPELL_BLIND);
                            events.ScheduleEvent(EVENT_BLIND, urand(10*IN_MILLISECONDS, 30*IN_MILLISECONDS));
                            return;
                        case EVENT_CLOAK:
                            if (HealthBelowPct(50))
                            {
                                DoCast(SPELL_CLOAK);
                                events.RescheduleEvent(EVENT_CLOAK, 90*IN_MILLISECONDS);
                            }
                            else
                                events.RescheduleEvent(EVENT_CLOAK, 5*IN_MILLISECONDS);
                            return;
                        case EVENT_BLADE_FLURRY:
                            if (EnemiesInRange(10.0f) >= 2)
                            {
                                DoCast(SPELL_BLADE_FLURRY);
                                events.RescheduleEvent(EVENT_BLADE_FLURRY, 120*IN_MILLISECONDS);
                            }
                            else
                                events.RescheduleEvent(EVENT_BLADE_FLURRY, 5*IN_MILLISECONDS);
                            return;
                        case EVENT_SHADOWSTEP:
                            if (Unit* target = me->GetVictim())
                            {
                                if (me->IsInRange(target, 10.0f, 40.0f, false))
                                {
                                    DoCast(target, SPELL_SHADOWSTEP);
                                    events.RescheduleEvent(EVENT_SHADOWSTEP, 30*IN_MILLISECONDS);
                                    return;
                                }
                            }
                            events.RescheduleEvent(EVENT_SHADOWSTEP, 5*IN_MILLISECONDS);
                            return;
                        case EVENT_HEMORRHAGE:
                            DoCastVictim(SPELL_HEMORRHAGE);
                            events.ScheduleEvent(EVENT_HEMORRHAGE, urand(3*IN_MILLISECONDS, 10*IN_MILLISECONDS));
                            return;
                        case EVENT_EVISCERATE:
                            DoCastVictim(SPELL_EVISCERATE);
                            events.ScheduleEvent(EVENT_EVISCERATE, urand(30*IN_MILLISECONDS, 40*IN_MILLISECONDS));
                            return;
                        case EVENT_WOUND_POISON:
                            DoCastVictim(SPELL_WOUND_POISON);
                            events.ScheduleEvent(EVENT_WOUND_POISON, urand(10*IN_MILLISECONDS, 20*IN_MILLISECONDS));
                            return;
                        default:
                            return;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return GetInstanceAI<npc_toc_rogueAI>(creature);
        }
};

class npc_toc_enh_shaman : public CreatureScript
{
    public:
        npc_toc_enh_shaman() : CreatureScript("npc_toc_enh_shaman") { }

        struct npc_toc_enh_shamanAI : public boss_faction_championsAI
        {
            npc_toc_enh_shamanAI(Creature* creature) : boss_faction_championsAI(creature, AI_MELEE) { }

            void Reset() OVERRIDE
            {
                boss_faction_championsAI::Reset();
                events.ScheduleEvent(EVENT_DPS_EARTH_SHOCK, urand(5*IN_MILLISECONDS, 10*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_LAVA_LASH, urand(3*IN_MILLISECONDS, 5*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_STORMSTRIKE, urand(2*IN_MILLISECONDS, 5*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_DPS_BLOODLUST_HEROISM, 20*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_DEPLOY_TOTEM, 1*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_WINDFURY, urand(20*IN_MILLISECONDS, 50*IN_MILLISECONDS));

                _totemCount = 0;
                _totemOldCenterX = me->GetPositionX();
                _totemOldCenterY = me->GetPositionY();
                SetEquipmentSlots(false, 51803, 48013, EQUIP_NO_CHANGE);
                summons.DespawnAll();
            }

            void JustSummoned(Creature* summoned) OVERRIDE
            {
                summons.Summon(summoned);
            }

            void SummonedCreatureDespawn(Creature* /*pSummoned*/) OVERRIDE
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

            void JustDied(Unit* killer) OVERRIDE
            {
                boss_faction_championsAI::JustDied(killer);
                summons.DespawnAll();
            }

            void UpdateAI(uint32 diff) OVERRIDE
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
                            events.ScheduleEvent(EVENT_DPS_EARTH_SHOCK, urand(10*IN_MILLISECONDS, 15*IN_MILLISECONDS));
                            return;
                        case EVENT_LAVA_LASH:
                            DoCastVictim(SPELL_LAVA_LASH);
                            events.ScheduleEvent(EVENT_LAVA_LASH, urand(5*IN_MILLISECONDS, 15*IN_MILLISECONDS));
                            return;
                        case EVENT_STORMSTRIKE:
                            DoCastVictim(SPELL_STORMSTRIKE);
                            events.ScheduleEvent(EVENT_STORMSTRIKE, urand(8*IN_MILLISECONDS, 10*IN_MILLISECONDS));
                            return;
                        case EVENT_DPS_BLOODLUST_HEROISM:
                            if (me->getFaction()) //Am i alliance?
                            {
                                if (!me->HasAura(AURA_EXHAUSTION))
                                    DoCastAOE(SPELL_HEROISM);
                            }
                            else
                            {
                                if (!me->HasAura(AURA_SATED))
                                    DoCastAOE(SPELL_BLOODLUST);
                            }
                            events.ScheduleEvent(EVENT_DPS_BLOODLUST_HEROISM, 5*MINUTE*IN_MILLISECONDS);
                            return;
                        case EVENT_DEPLOY_TOTEM:
                            if (_totemCount < 4 || me->GetDistance2d(_totemOldCenterX, _totemOldCenterY) > 20.0f)
                                DeployTotem();
                            events.ScheduleEvent(EVENT_DEPLOY_TOTEM, 1*IN_MILLISECONDS);
                            return;
                        case EVENT_WINDFURY:
                            DoCastVictim(SPELL_WINDFURY);
                            events.ScheduleEvent(EVENT_WINDFURY, urand(20*IN_MILLISECONDS, 60*IN_MILLISECONDS));
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

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return GetInstanceAI<npc_toc_enh_shamanAI>(creature);
        }
};

class npc_toc_retro_paladin : public CreatureScript
{
    public:
        npc_toc_retro_paladin() : CreatureScript("npc_toc_retro_paladin") { }

        struct npc_toc_retro_paladinAI : public boss_faction_championsAI
        {
            npc_toc_retro_paladinAI(Creature* creature) : boss_faction_championsAI(creature, AI_MELEE) { }

            void Reset() OVERRIDE
            {
                boss_faction_championsAI::Reset();
                events.ScheduleEvent(EVENT_AVENGING_WRATH, urand(25*IN_MILLISECONDS, 35*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_CRUSADER_STRIKE, urand(5*IN_MILLISECONDS, 10*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_DIVINE_STORM, urand(10*IN_MILLISECONDS, 20*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_HAMMER_OF_JUSTICE_RET, urand(10*IN_MILLISECONDS, 30*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_JUDGEMENT_OF_COMMAND, urand(5*IN_MILLISECONDS, 15*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_REPENTANCE, urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_DPS_HAND_OF_PROTECTION, urand(20*IN_MILLISECONDS, 30*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_DPS_DIVINE_SHIELD, urand(20*IN_MILLISECONDS, 30*IN_MILLISECONDS));
                SetEquipmentSlots(false, 47519, EQUIP_NO_CHANGE, EQUIP_NO_CHANGE);
            }

            void EnterCombat(Unit* who) OVERRIDE
            {
                boss_faction_championsAI::EnterCombat(who);
                DoCast(SPELL_SEAL_OF_COMMAND);
            }

            void UpdateAI(uint32 diff) OVERRIDE
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
                            events.ScheduleEvent(EVENT_AVENGING_WRATH, 180*IN_MILLISECONDS);
                            return;
                        case EVENT_CRUSADER_STRIKE:
                            DoCastVictim(SPELL_CRUSADER_STRIKE);
                            events.ScheduleEvent(EVENT_CRUSADER_STRIKE, urand(10*IN_MILLISECONDS, 15*IN_MILLISECONDS));
                            return;
                        case EVENT_DIVINE_STORM:
                            if (EnemiesInRange(10.0f) >= 2)
                                DoCast(SPELL_DIVINE_STORM);
                            events.ScheduleEvent(EVENT_DIVINE_STORM, urand(10*IN_MILLISECONDS, 20*IN_MILLISECONDS));
                            return;
                        case EVENT_HAMMER_OF_JUSTICE_RET:
                            DoCastVictim(SPELL_HAMMER_OF_JUSTICE_RET);
                            events.ScheduleEvent(EVENT_HAMMER_OF_JUSTICE_RET, 40*IN_MILLISECONDS);
                            return;
                        case EVENT_JUDGEMENT_OF_COMMAND:
                            DoCastVictim(SPELL_JUDGEMENT_OF_COMMAND);
                            events.ScheduleEvent(EVENT_JUDGEMENT_OF_COMMAND, urand(10*IN_MILLISECONDS, 15*IN_MILLISECONDS));
                            return;
                        case EVENT_REPENTANCE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, NonTankTargetSelector(me)))
                                DoCast(target, SPELL_REPENTANCE);
                            events.ScheduleEvent(EVENT_REPENTANCE, 60*IN_MILLISECONDS);
                            return;
                        case EVENT_DPS_HAND_OF_PROTECTION:
                            if (Unit* target = DoSelectLowestHpFriendly(30.0f))
                            {
                                if (!target->HasAura(SPELL_FORBEARANCE))
                                {
                                    DoCast(target, SPELL_HAND_OF_PROTECTION);
                                    events.RescheduleEvent(EVENT_DPS_HAND_OF_PROTECTION, 5*MINUTE*IN_MILLISECONDS);
                                }
                                else
                                    events.RescheduleEvent(EVENT_DPS_HAND_OF_PROTECTION, 5*IN_MILLISECONDS);
                            }
                            else
                                events.RescheduleEvent(EVENT_DPS_HAND_OF_PROTECTION, 5*IN_MILLISECONDS);
                            return;
                        case EVENT_DPS_DIVINE_SHIELD:
                            if (HealthBelowPct(30) && !me->HasAura(SPELL_FORBEARANCE))
                            {
                                DoCast(me, SPELL_DIVINE_SHIELD);
                                events.RescheduleEvent(EVENT_DPS_DIVINE_SHIELD, 5*MINUTE*IN_MILLISECONDS);
                            }
                            else
                                events.RescheduleEvent(EVENT_DPS_DIVINE_SHIELD, 5*IN_MILLISECONDS);
                            return;
                        default:
                            return;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return GetInstanceAI<npc_toc_retro_paladinAI>(creature);
        }
};

class npc_toc_pet_warlock : public CreatureScript
{
    public:
        npc_toc_pet_warlock() : CreatureScript("npc_toc_pet_warlock") { }

        struct npc_toc_pet_warlockAI : public boss_faction_championsAI
        {
            npc_toc_pet_warlockAI(Creature* creature) : boss_faction_championsAI(creature, AI_PET) { }

            void Reset() OVERRIDE
            {
                boss_faction_championsAI::Reset();
                events.ScheduleEvent(EVENT_DEVOUR_MAGIC, urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_SPELL_LOCK, urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS));
            }

            void UpdateAI(uint32 diff) OVERRIDE
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
                            events.ScheduleEvent(EVENT_DEVOUR_MAGIC, urand(8*IN_MILLISECONDS, 10*IN_MILLISECONDS));
                            return;
                        case EVENT_SPELL_LOCK:
                            DoCast(SPELL_SPELL_LOCK);
                            events.ScheduleEvent(EVENT_SPELL_LOCK, urand(24*IN_MILLISECONDS, 30*IN_MILLISECONDS));
                            return;
                        default:
                            return;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return GetInstanceAI<npc_toc_pet_warlockAI>(creature);
        }
};

class npc_toc_pet_hunter : public CreatureScript
{
    public:
        npc_toc_pet_hunter() : CreatureScript("npc_toc_pet_hunter") { }

        struct npc_toc_pet_hunterAI : public boss_faction_championsAI
        {
            npc_toc_pet_hunterAI(Creature* creature) : boss_faction_championsAI(creature, AI_PET) { }

            void Reset() OVERRIDE
            {
                boss_faction_championsAI::Reset();
                _clawTimer = urand(5*IN_MILLISECONDS, 10*IN_MILLISECONDS);
            }

            void UpdateAI(uint32 diff) OVERRIDE
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

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return GetInstanceAI<npc_toc_pet_hunterAI>(creature);
        }
};

class spell_faction_champion_warl_unstable_affliction : public SpellScriptLoader
{
    public:
        spell_faction_champion_warl_unstable_affliction() : SpellScriptLoader("spell_faction_champion_warl_unstable_affliction") { }

        class spell_faction_champion_warl_unstable_affliction_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_faction_champion_warl_unstable_affliction_AuraScript);

            bool Validate(SpellInfo const* /*spell*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_UNSTABLE_AFFLICTION_DISPEL))
                    return false;
                return true;
            }

            void HandleDispel(DispelInfo* dispelInfo)
            {
                if (Unit* caster = GetCaster())
                    caster->CastSpell(dispelInfo->GetDispeller(), SPELL_UNSTABLE_AFFLICTION_DISPEL, true, NULL, GetEffect(EFFECT_0));
            }

            void Register() OVERRIDE
            {
                AfterDispel += AuraDispelFn(spell_faction_champion_warl_unstable_affliction_AuraScript::HandleDispel);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_faction_champion_warl_unstable_affliction_AuraScript();
        }
};

class spell_faction_champion_death_grip : public SpellScriptLoader
{
    public:
        spell_faction_champion_death_grip() : SpellScriptLoader("spell_faction_champion_death_grip") { }

        class spell_faction_champion_death_grip_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_faction_champion_death_grip_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DEATH_GRIP_PULL))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                if (Unit* target = GetHitUnit())
                {
                    if (Unit* caster = GetCaster())
                        target->CastSpell(caster, SPELL_DEATH_GRIP_PULL);
                }
            }

            void Register() OVERRIDE
            {
                OnEffectHitTarget += SpellEffectFn(spell_faction_champion_death_grip_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }

        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_faction_champion_death_grip_SpellScript();
        }
};

class spell_toc_bloodlust : public SpellScriptLoader
{
    public:
        spell_toc_bloodlust() : SpellScriptLoader("spell_toc_bloodlust") { }

        class spell_toc_bloodlust_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_toc_bloodlust_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(AURA_SATED))
                    return false;
                return true;
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

            void Register() OVERRIDE
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_toc_bloodlust_SpellScript::RemoveInvalidTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_toc_bloodlust_SpellScript::RemoveInvalidTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ALLY);
                AfterHit += SpellHitFn(spell_toc_bloodlust_SpellScript::ApplyDebuff);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_toc_bloodlust_SpellScript();
        }
};

class spell_toc_heroism : public SpellScriptLoader
{
    public:
        spell_toc_heroism() : SpellScriptLoader("spell_toc_heroism") { }

        class spell_toc_heroism_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_toc_heroism_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(AURA_EXHAUSTION))
                    return false;
                return true;
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

            void Register() OVERRIDE
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_toc_heroism_SpellScript::RemoveInvalidTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_toc_heroism_SpellScript::RemoveInvalidTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ALLY);
                AfterHit += SpellHitFn(spell_toc_heroism_SpellScript::ApplyDebuff);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_toc_heroism_SpellScript();
        }
};

void AddSC_boss_faction_champions()
{
    new boss_toc_champion_controller();
    new npc_toc_druid();
    new npc_toc_shaman();
    new npc_toc_paladin();
    new npc_toc_priest();
    new npc_toc_shadow_priest();
    new npc_toc_mage();
    new npc_toc_warlock();
    new npc_toc_hunter();
    new npc_toc_boomkin();
    new npc_toc_warrior();
    new npc_toc_dk();
    new npc_toc_rogue();
    new npc_toc_enh_shaman();
    new npc_toc_retro_paladin();
    new npc_toc_pet_warlock();
    new npc_toc_pet_hunter();

    new spell_faction_champion_warl_unstable_affliction();
    new spell_faction_champion_death_grip();
    new spell_toc_bloodlust();
    new spell_toc_heroism();
}
