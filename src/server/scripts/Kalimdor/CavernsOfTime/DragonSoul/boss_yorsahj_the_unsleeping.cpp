/*
 * Copyright (C) 2022 BfaCore Reforged
 * Copyright (C) 2014-2018 RoG_WoW Source <http://wow.rog.snet>
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

#include "Cell.h"
#include "CreatureTextMgr.h"
#include "Containers.h"
#include "dragon_soul.h"
#include "GridNotifiers.h"
#include "CellImpl.h"
#include "GridNotifiersImpl.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "SpellMgr.h"

enum ScriptedTexts
{
    SAY_AGGRO   = 0,
    SAY_DEATH   = 1,
    SAY_INTRO   = 2,
    SAY_KILL    = 3,
    SAY_SPELL   = 4,
    SAY_AGGRO_1 = 5,
    SAY_DEATH_1 = 6,
    SAY_INTRO_1 = 7,
    SAY_KILL_1  = 8,
    SAY_SPELL_1 = 9,
};

enum Spells
{
    SPELL_BERSERK                   = 26662,
    SPELL_VOID_BOLT                 = 104849,
    SPELL_VOID_BOLT_AOE             = 105416,
    SPELL_SEARING_BLOOD             = 105033,
    SPELL_DEEP_CORRUPTION           = 105171,
    SPELL_DEEP_CORRUPTION_AURA      = 103628,
    SPELL_DEEP_CORRUPTION_DMG       = 105173,
    SPELL_DIGESTIVE_ACID            = 105031,
    SPELL_DIGESTIVE_ACID_DUMMY      = 105562,
    SPELL_DIGESTIVE_ACID_AOE        = 105571,
    SPELL_DIGESTIVE_ACID_DMG        = 105573,
    SPELL_MANA_VOID_SUMMON          = 105034,
    SPELL_MANA_VOID_DUMMY_1         = 105505,
    SPELL_MANA_VOID                 = 105530,
    SPELL_MANA_VOID_DUMMY_2         = 105534,
    SPELL_MANA_VOID_DUMMY_3         = 105536,
    SPELL_MANA_DIFFUSION            = 108228, //105539,
    SPELL_CORRUPTED_MINIONS_AURA    = 105636,
    SPELL_CORRUPTED_MINIONS_SUMMON  = 105637,
    SPELL_PSYCHIC_SLICE             = 105671,

    SPELL_CRIMSON_BLOOD_OF_SHUMA    = 104897,
    SPELL_ACIDIC_BLOOD_OF_SHUMA     = 104898,
    SPELL_GLOWING_BLOOD_OF_SHUMA    = 104901,
    SPELL_BLACK_BLOOD_OF_SHUMA      = 104894,
    SPELL_SHADOWED_BLOOD_OF_SHUMA   = 104896,
    SPELL_COBALT_BLOOD_OF_SHUMA     = 105027, // 104900 ?

    SPELL_FUSING_VAPORS             = 103968,
    SPELL_FUSING_VAPORS_HEAL        = 103635,
    SPELL_FUSING_VAPORS_IMMUNE      = 105904,

    SPELL_COLOR_COMBINATION_1       = 105420, // Purple, Green, Blue : Black
    SPELL_COLOR_COMBINATION_2       = 105435, // Green, Red, Black : Blue
    SPELL_COLOR_COMBINATION_3       = 105436, // Green, Yellow, Red : Black
    SPELL_COLOR_COMBINATION_4       = 105437, // Blue, Purple, Yellow : Green
    SPELL_COLOR_COMBINATION_5       = 105439, // Blue, Black, Yellow : Purple
    SPELL_COLOR_COMBINATION_6       = 105440, // Purple, Red, Black : Yellow

    SPELL_AURA_TALL_BLUE            = 105473,
    SPELL_AURA_TALL_RED             = 105474,
    SPELL_AURA_TALL_GREEN           = 105475,
    SPELL_AURA_TALL_YELLOW          = 105476,
    SPELL_AURA_TALL_PURPLE          = 105477,
    SPELL_AURA_TALL_BLACK           = 105478,

    SPELL_SPAWNING_POOL_1           = 105600,
    SPELL_SPAWNING_POOL_2           = 105601,
    SPELL_SPAWNING_POOL_3           = 105603,

    SPELL_YORSAHJ_WHISPER_INTRO     = 109894,
    SPELL_YORSAHJ_WHISPER_AGGRO     = 109895,
    SPELL_YORSAHJ_WHISPER_DEATH     = 109896,
    SPELL_YORSAHJ_WHISPER_KILL      = 109897,
    SPELL_YORSAHJ_WHISPER_SPELL     = 109898,
};

enum Events
{
    EVENT_BERSERK           = 1,
    EVENT_VOID_BOLT         = 2,
    EVENT_CALL_BLOOD_1      = 3,
    EVENT_CALL_BLOOD_2      = 4, // after teleport
    EVENT_CONTINUE          = 5,
    EVENT_CALL_BLOOD_3      = 6,
    EVENT_SEARING_BLOOD     = 7,
    EVENT_DIGESTIVE_ACID    = 8,
    EVENT_CORRUPTED_MINIONS = 9,
    EVENT_DEEP_CORRUPTION   = 10,
    EVENT_MANA_VOID_1       = 11,
    EVENT_PSYCHIC_SLICE     = 12,
    EVENT_MANA_VOID_2       = 13,
};

enum Adds
{
    NPC_MAW_OF_SHUMA        = 55544,
    NPC_MANA_VOID           = 56231,
    NPC_FORGOTTEN_ONE       = 56265,
    NPC_CRIMSON_GLOBULE     = 55865,
    NPC_ACIDIC_GLOBULE      = 55862,
    NPC_GLOWING_GLOBULE     = 55864,
    NPC_DARK_GLOBULE        = 55867,
    NPC_SHADOWED_GLOBULE    = 55863,
    NPC_COBALT_GLOBULE      = 55866,
};

enum Actions
{
    ACTION_CONTINUE = 1,
    ACTION_RED      = 2,
    ACTION_GREEN    = 3,
    ACTION_YELLOW   = 4,
    ACTION_DARK     = 5,
    ACTION_PURPLE   = 6,
    ACTION_BLUE     = 7,
};

const Position globulesPos[6] =
{
    {-1662.959961f, -2992.280029f, -173.52f, 3.63f}, // Crimson
    {-1723.760010f, -2935.330078f, -174.03f, 4.32f}, // Acidic
    {-1863.989990f, -2993.090088f, -174.12f, 5.86f}, // Glowing
    {-1808.229980f, -3136.739990f, -173.48f, 1.09f}, // Dark
    {-1663.890015f, -3077.129883f, -174.48f, 2.72f}, // Shadowed
    {-1722.599976f, -3137.159912f, -173.39f, 1.93f}  // Cobalt
};

const Position mawofshumaPos = {-1762.56f, -3036.65f, -116.44f, 0.0f};
const Position centerPos = {-1765.66f, -3034.35f, -182.38f, 3.52f};

class boss_yorsahj_the_unsleeping: public CreatureScript
{
    public:
        boss_yorsahj_the_unsleeping() : CreatureScript("boss_yorsahj_the_unsleeping") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new boss_yorsahj_the_unsleepingAI(pCreature);
        }

        struct boss_yorsahj_the_unsleepingAI : public BossAI
        {
            boss_yorsahj_the_unsleepingAI(Creature* pCreature) : BossAI(pCreature, DATA_YORSAHJ)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
                me->setActive(true);
                bIntro = false;
                bShuma = false;
                memset(bAchieve, false, sizeof(bAchieve));
            }

            void InitializeAI() override
            {
                if (!instance || static_cast<InstanceMap*>(me->GetMap())->GetScriptId() != sObjectMgr->GetScriptIdOrAdd(DSScriptName))
                    me->IsAIEnabled = false;
                else if (!me->isDead())
                    Reset();
            }

            void MoveInLineOfSight(Unit* who) override
            {
                if (!bIntro && me->GetDistance(who) <= 70.0f)
                {
                    bIntro = true;
                    Talk(SAY_INTRO);
                    Talk(SAY_INTRO_1);
                    DoCastAOE(SPELL_YORSAHJ_WHISPER_INTRO, true);
                }

                BossAI::MoveInLineOfSight(who);
            }

            void Reset() override
            {
                _Reset();

                bShuma = false;
                bContinue = false;
                corruptedMinion = false;
                _spellId = 0;
                memset(bAchieve, false, sizeof(bAchieve));
                instance->SetBossState(DATA_YORSAHJ, NOT_STARTED);
                me->SetReactState(REACT_AGGRESSIVE);
            }

            void EnterCombat(Unit* /*who*/) override
            {
                if (instance->GetBossState(DATA_MORCHOK) != DONE)
                {
                    EnterEvadeMode();
                    instance->DoNearTeleportPlayers(teleportPos[0]);
                    return;
                }

                Talk(SAY_AGGRO);
                Talk(SAY_AGGRO_1);
                DoCastAOE(SPELL_YORSAHJ_WHISPER_AGGRO, true);

                events.ScheduleEvent(EVENT_BERSERK, 10 * MINUTE * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_VOID_BOLT, 6000);
                events.ScheduleEvent(EVENT_CALL_BLOOD_1, 22000);

                DoZoneInCombat();
                instance->SetBossState(DATA_YORSAHJ, IN_PROGRESS);
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();

                Talk(SAY_DEATH);
                Talk(SAY_DEATH_1);
                DoCastAOE(SPELL_YORSAHJ_WHISPER_DEATH, true);

                if (instance)
                {
                    //instance->DoModifyPlayerCurrenciesIfLevel(395, 7500, 85);
                    if (!IsHeroic())
                    {
                        instance->DoModifyPlayerCurrencies(614, 1);
                        instance->DoModifyPlayerCurrencies(615, 1);
                    }
                    else
                    {
                        instance->DoModifyPlayerCurrencies(614, 2);
                        instance->DoModifyPlayerCurrencies(615, 2);
                    }
                    instance->SetBossState(DATA_YORSAHJ, DONE);
                }

            }

            bool AllowAchieve(uint32 Id)
            {
                return bAchieve[Id];
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim && victim->GetTypeId() == TYPEID_PLAYER)
                {
                    Talk(SAY_KILL);
                    Talk(SAY_KILL_1);
                    DoCastAOE(SPELL_YORSAHJ_WHISPER_KILL, true);
                }
            }

            void DoAction(const int32 action) override
            {
                if (action == ACTION_CONTINUE && !bContinue)
                {
                    bContinue = true;
                    events.ScheduleEvent(EVENT_CONTINUE, 1000);
                }
            }

            void JustSummoned(Creature* summon) override
            {
                BossAI::JustSummoned(summon);
                if (summon->GetEntry() == NPC_MANA_VOID)
                    summon->GetMotionMaster()->MoveRandom(25.0f);
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (me->GetDistance(me->GetHomePosition()) > 150.0f)
                {
                    EnterEvadeMode();
                    return;
                }

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BERSERK:
                            DoCast(me, SPELL_BERSERK);
                            break;
                        case EVENT_VOID_BOLT:
                            if (bShuma)
                                DoCastAOE(SPELL_VOID_BOLT_AOE);
                            else
                                DoCastVictim(SPELL_VOID_BOLT);

                            events.ScheduleEvent(EVENT_VOID_BOLT, (bShuma ? 5000 : 9000));
                            break;
                        case EVENT_CALL_BLOOD_1:
                            events.CancelEvent(EVENT_VOID_BOLT);
                            events.CancelEvent(EVENT_SEARING_BLOOD);
                            events.CancelEvent(EVENT_DIGESTIVE_ACID);
                            events.CancelEvent(EVENT_CORRUPTED_MINIONS);
                            events.CancelEvent(EVENT_DEEP_CORRUPTION);
                            events.CancelEvent(EVENT_MANA_VOID_1);
                            events.CancelEvent(EVENT_MANA_VOID_2);
                            me->RemoveAura(SPELL_CRIMSON_BLOOD_OF_SHUMA);
                            me->RemoveAura(SPELL_ACIDIC_BLOOD_OF_SHUMA);
                            me->RemoveAura(SPELL_GLOWING_BLOOD_OF_SHUMA);
                            me->RemoveAura(SPELL_BLACK_BLOOD_OF_SHUMA);
                            me->RemoveAura(SPELL_SHADOWED_BLOOD_OF_SHUMA);
                            me->RemoveAura(SPELL_COBALT_BLOOD_OF_SHUMA);
                            me->RemoveAura(SPELL_SPAWNING_POOL_1);
                            me->RemoveAura(SPELL_SPAWNING_POOL_2);
                            me->RemoveAura(SPELL_SPAWNING_POOL_3);

                            me->SetReactState(REACT_PASSIVE);
                            me->AttackStop();

                            bContinue = false;
                            bShuma = false;

                            events.ScheduleEvent(EVENT_CALL_BLOOD_2, 1000);

                            me->NearTeleportTo(centerPos.GetPositionX(), centerPos.GetPositionY(), centerPos.GetPositionZ(), centerPos.GetOrientation());
                            break;
                        case EVENT_CALL_BLOOD_2:
                        {
                            Talk(SAY_SPELL);
                            Talk(SAY_SPELL_1);
                            DoCastAOE(SPELL_YORSAHJ_WHISPER_SPELL, true);

                            std::list<uint32> globList;
                            _spellId = 0;
                            uint8 i = 0;
                            SelectRandomGlobules(_spellId, globList);
                            if (globList.empty() || !_spellId)
                                break;

                            for (std::list<uint32>::const_iterator itr = globList.begin(); itr != globList.end(); ++itr)
                            {
                                switch ((*itr))
                                {
                                    case NPC_CRIMSON_GLOBULE: i = 0; break;
                                    case NPC_ACIDIC_GLOBULE: i = 1; break;
                                    case NPC_GLOWING_GLOBULE: i = 2;break;
                                    case NPC_DARK_GLOBULE: i = 3; break;
                                    case NPC_SHADOWED_GLOBULE: i = 4; break;
                                    case NPC_COBALT_GLOBULE: i = 5; break;
                                    default: return;
                                }

                                if (Creature* pGlobule = me->SummonCreature((*itr), globulesPos[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000))
                                {
                                    pGlobule->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                                    pGlobule->SetDisplayId(11686);
                                }
                            }
                            events.ScheduleEvent(EVENT_CALL_BLOOD_3, 1000);
                            break;
                        }
                        case EVENT_CALL_BLOOD_3:
                            DoCast(me, _spellId);
                            break;
                        case EVENT_CONTINUE:
                        {
                            std::list<Creature*> creatures;
                            GlobulesCheck checker;
                            Trinity::CreatureListSearcher<GlobulesCheck> searcher(me, creatures, checker);
                            Cell::VisitGridObjects(me, searcher, 100.0f);

                            if (!creatures.empty())
                            {
                                for (std::list<Creature*>::const_iterator itr = creatures.begin(); itr != creatures.end(); ++itr)
                                {
                                    switch ((*itr)->GetEntry())
                                    {
                                        case NPC_CRIMSON_GLOBULE:
                                            DoCast(me, SPELL_CRIMSON_BLOOD_OF_SHUMA, true);
                                            events.ScheduleEvent(EVENT_SEARING_BLOOD, urand(5000, 7000));
                                            break;
                                        case NPC_ACIDIC_GLOBULE:
                                            me->SummonCreature(NPC_MAW_OF_SHUMA, mawofshumaPos, TEMPSUMMON_TIMED_DESPAWN, 60000);
                                            DoCast(me, SPELL_ACIDIC_BLOOD_OF_SHUMA, true);
                                            DoCast(me, SPELL_DIGESTIVE_ACID_DUMMY, true);
                                            events.ScheduleEvent(EVENT_DIGESTIVE_ACID, urand(7000, 9000));
                                            break;
                                        case NPC_GLOWING_GLOBULE:
                                            bShuma = true;
                                            corruptedMinion = true;
                                            DoCast(me, SPELL_GLOWING_BLOOD_OF_SHUMA, true);
                                            break;
                                        case NPC_DARK_GLOBULE:
                                            DoCast(me, SPELL_BLACK_BLOOD_OF_SHUMA, true);
                                            events.ScheduleEvent(EVENT_CORRUPTED_MINIONS, 1000);
                                            break;
                                        case NPC_SHADOWED_GLOBULE:
                                            DoCast(me, SPELL_SHADOWED_BLOOD_OF_SHUMA, true);
                                            events.ScheduleEvent(EVENT_DEEP_CORRUPTION, urand(3000, 4000));
                                            break;
                                        case NPC_COBALT_GLOBULE:
                                            DoCast(me, SPELL_COBALT_BLOOD_OF_SHUMA, true);
                                            events.ScheduleEvent(EVENT_MANA_VOID_1, urand(2000, 3000));
                                            break;
                                        default: break;
                                    }
                                    (*itr)->DespawnOrUnsummon();
                                }
                            }

                            if (me->HasAura(SPELL_BLACK_BLOOD_OF_SHUMA) && me->HasAura(SPELL_GLOWING_BLOOD_OF_SHUMA))
                                bAchieve[0] = true;
                            else if (me->HasAura(SPELL_CRIMSON_BLOOD_OF_SHUMA) && me->HasAura(SPELL_ACIDIC_BLOOD_OF_SHUMA))
                                bAchieve[1] = true;
                            else if (me->HasAura(SPELL_BLACK_BLOOD_OF_SHUMA) && me->HasAura(SPELL_COBALT_BLOOD_OF_SHUMA))
                                bAchieve[2] = true;
                            else if (me->HasAura(SPELL_SHADOWED_BLOOD_OF_SHUMA) && me->HasAura(SPELL_GLOWING_BLOOD_OF_SHUMA))
                                bAchieve[3] = true;

                            me->SetReactState(REACT_AGGRESSIVE);
                            AttackStart(me->GetVictim());
                            events.ScheduleEvent(EVENT_VOID_BOLT, urand(6000, 7000));
                            events.ScheduleEvent(EVENT_CALL_BLOOD_1, 62000);
                            break;
                        }
                        case EVENT_SEARING_BLOOD:
                            me->CastCustomSpell(SPELL_SEARING_BLOOD, SPELLVALUE_MAX_TARGETS, RAID_MODE(3, 8), me);
                            events.ScheduleEvent(EVENT_SEARING_BLOOD, (bShuma ? 3500 : 6000));
                            break;
                        case EVENT_DIGESTIVE_ACID:
                            DoCast(me, SPELL_DIGESTIVE_ACID);
                            events.ScheduleEvent(EVENT_DIGESTIVE_ACID, (bShuma ? 3500 : 8300));
                            break;
                        case EVENT_CORRUPTED_MINIONS:
                            DoCast(me, SPELL_SPAWNING_POOL_1, true);
                            DoCast(me, SPELL_SPAWNING_POOL_2, true);
                            DoCast(me, SPELL_SPAWNING_POOL_3, true);
                            DoCast(me, SPELL_CORRUPTED_MINIONS_AURA);
                            if (bShuma && corruptedMinion)
                            {
                                corruptedMinion = false;
                                events.ScheduleEvent(EVENT_CORRUPTED_MINIONS, 30000);
                            }
                            break;
                        case EVENT_DEEP_CORRUPTION:
                            DoCastAOE(SPELL_DEEP_CORRUPTION);
                            events.ScheduleEvent(EVENT_DEEP_CORRUPTION, 25000);
                            break;
                        case EVENT_MANA_VOID_1:
                            DoCastAOE(SPELL_MANA_VOID);
                            events.ScheduleEvent(EVENT_MANA_VOID_2, 5000);
                            break;
                        case EVENT_MANA_VOID_2:
                            DoCast(me, SPELL_MANA_VOID_SUMMON);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        private:
            bool bIntro;
            uint32 _spellId;
            bool bContinue;
            bool bShuma;
            bool bAchieve[4];
            bool corruptedMinion;

            // Returns spell for animation
            void SelectRandomGlobules(uint32 &spellId, std::list<uint32> &entryList)
            {
                switch (urand(0, 5))
                {
                    case 0:
                        entryList.push_back(NPC_SHADOWED_GLOBULE);
                        entryList.push_back(NPC_ACIDIC_GLOBULE);
                        entryList.push_back(NPC_COBALT_GLOBULE);
                        if (IsHeroic())
                            entryList.push_back(NPC_DARK_GLOBULE);
                        spellId = SPELL_COLOR_COMBINATION_1;
                        break;
                    case 1:
                        entryList.push_back(NPC_ACIDIC_GLOBULE);
                        entryList.push_back(NPC_CRIMSON_GLOBULE);
                        entryList.push_back(NPC_DARK_GLOBULE);
                        if (IsHeroic())
                            entryList.push_back(NPC_COBALT_GLOBULE);
                        spellId = SPELL_COLOR_COMBINATION_2;
                        break;
                    case 2:
                        entryList.push_back(NPC_ACIDIC_GLOBULE);
                        entryList.push_back(NPC_GLOWING_GLOBULE);
                        entryList.push_back(NPC_CRIMSON_GLOBULE);
                        if (IsHeroic())
                            entryList.push_back(NPC_DARK_GLOBULE);
                        spellId = SPELL_COLOR_COMBINATION_3;
                        break;
                    case 3:
                        entryList.push_back(NPC_COBALT_GLOBULE);
                        entryList.push_back(NPC_SHADOWED_GLOBULE);
                        entryList.push_back(NPC_GLOWING_GLOBULE);
                        if (IsHeroic())
                            entryList.push_back(NPC_ACIDIC_GLOBULE);
                        spellId = SPELL_COLOR_COMBINATION_4;
                        break;
                    case 4:
                        entryList.push_back(NPC_COBALT_GLOBULE);
                        entryList.push_back(NPC_DARK_GLOBULE);
                        entryList.push_back(NPC_GLOWING_GLOBULE);
                        if (IsHeroic())
                            entryList.push_back(NPC_SHADOWED_GLOBULE);
                        spellId = SPELL_COLOR_COMBINATION_5;
                        break;
                    case 5:
                        entryList.push_back(NPC_SHADOWED_GLOBULE);
                        entryList.push_back(NPC_CRIMSON_GLOBULE);
                        entryList.push_back(NPC_DARK_GLOBULE);
                        if (IsHeroic())
                            entryList.push_back(NPC_GLOWING_GLOBULE);
                        spellId = SPELL_COLOR_COMBINATION_6;
                        break;
                    default:
                        break;
                }
            }

            class GlobulesCheck
            {
                public:
                    GlobulesCheck() {}

                    bool operator()(Creature* u)
                    {
                        if ((u->GetEntry() == NPC_CRIMSON_GLOBULE ||
                            u->GetEntry() == NPC_ACIDIC_GLOBULE ||
                            u->GetEntry() == NPC_GLOWING_GLOBULE ||
                            u->GetEntry() == NPC_DARK_GLOBULE ||
                            u->GetEntry() == NPC_SHADOWED_GLOBULE ||
                            u->GetEntry() == NPC_COBALT_GLOBULE) &&
                            u->IsAlive())
                            return true;
                        return false;
                    }
            };
        };
};

class npc_yorsahj_the_unsleeping_globule: public CreatureScript
{
    public:
        npc_yorsahj_the_unsleeping_globule() : CreatureScript("npc_yorsahj_the_unsleeping_globule") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_yorsahj_the_unsleeping_globuleAI(pCreature);
        }

        struct npc_yorsahj_the_unsleeping_globuleAI : public Scripted_NoMovementAI
        {
            npc_yorsahj_the_unsleeping_globuleAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
                me->setActive(true);
                bDespawn = false;
                me->SetReactState(REACT_PASSIVE);
            }

            void Reset() override
            {
                events.Reset();
            }

            void IsSummonedBy(Unit* /*owner*/) override
            {
                switch(me->GetEntry())
                {
                    case NPC_CRIMSON_GLOBULE: DoCast(me, SPELL_AURA_TALL_RED, true); break;
                    case NPC_ACIDIC_GLOBULE: DoCast(me, SPELL_AURA_TALL_GREEN, true); break;
                    case NPC_GLOWING_GLOBULE: DoCast(me, SPELL_AURA_TALL_YELLOW, true); break;
                    case NPC_DARK_GLOBULE: DoCast(me, SPELL_AURA_TALL_BLACK, true); break;
                    case NPC_SHADOWED_GLOBULE: DoCast(me, SPELL_AURA_TALL_PURPLE, true); break;
                    case NPC_COBALT_GLOBULE: DoCast(me, SPELL_AURA_TALL_BLUE, true); break;
                    default: break;
                }
            }

            void SpellHit(Unit* /*who*/, const SpellInfo* spellInfo) override
            {
                if (spellInfo->Id == SPELL_COLOR_COMBINATION_1 ||
                    spellInfo->Id == SPELL_COLOR_COMBINATION_2 ||
                    spellInfo->Id == SPELL_COLOR_COMBINATION_3 ||
                    spellInfo->Id == SPELL_COLOR_COMBINATION_4 ||
                    spellInfo->Id == SPELL_COLOR_COMBINATION_5 ||
                    spellInfo->Id == SPELL_COLOR_COMBINATION_6)
                {
                    events.ScheduleEvent(EVENT_CONTINUE, 2000);
                }
            }

            void JustDied(Unit* /*killer*/) override
            {
                DoCastAOE(SPELL_FUSING_VAPORS_IMMUNE, true);
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (!bDespawn)
                {
                    if (me->isMoving())
                    {
                        float z = me->GetPositionZ();
                        me->UpdateAllowedPositionZ(me->GetPositionX(), me->GetPositionY(), z);
                        me->UpdatePosition(me->GetPositionX(), me->GetPositionY(), z, me->GetOrientation(), false);
                    }
                    if (Creature* pYorsahj = me->FindNearestCreature(NPC_YORSAHJ, 1.0f))
                    {
                        bDespawn = true;
                        pYorsahj->AI()->DoAction(ACTION_CONTINUE);
                        //me->DespawnOrUnsummon(100);
                    }
                }

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CONTINUE:
                            me->SetSpeed(MOVE_RUN, 0.47142876f);
                            me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                            me->SetDisplayId(me->GetNativeDisplayId());
                            DoCast(me, SPELL_FUSING_VAPORS, true);
                            if (Creature* pYorsahj = me->FindNearestCreature(NPC_YORSAHJ, 200.0f))
                                me->GetMotionMaster()->MoveFollow(pYorsahj, 0.0f, 0.0f);
                            break;
                        default:
                            break;
                    }
                }
            }
        private:
            EventMap events;
            bool bDespawn;
        };
};

class npc_yorsahj_the_unsleeping_forgotten_one: public CreatureScript
{
    public:
        npc_yorsahj_the_unsleeping_forgotten_one() : CreatureScript("npc_yorsahj_the_unsleeping_forgotten_one") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_yorsahj_the_unsleeping_forgotten_oneAI(pCreature);
        }

        struct npc_yorsahj_the_unsleeping_forgotten_oneAI : public ScriptedAI
        {
            npc_yorsahj_the_unsleeping_forgotten_oneAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, true);
                me->setActive(true);
                me->SetReactState(REACT_PASSIVE);
            }

            void Reset() override
            {
                events.Reset();
            }

            void IsSummonedBy(Unit* /*owner*/) override
            {
                events.ScheduleEvent(EVENT_CONTINUE, 1000);
            }

            void JustDied(Unit* /*killer*/) override
            {
                me->DespawnOrUnsummon(3000);
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CONTINUE:
                            me->SetReactState(REACT_AGGRESSIVE);
                            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                            {
                                me->AddThreat(pTarget, 1000000.0f);
                                AttackStart(pTarget);
                                events.ScheduleEvent(EVENT_PSYCHIC_SLICE, urand(6000, 20000));
                            }
                            break;
                        case EVENT_PSYCHIC_SLICE:
                            DoCastVictim(SPELL_PSYCHIC_SLICE);
                            events.ScheduleEvent(EVENT_PSYCHIC_SLICE, urand(15000, 20000));
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        private:
            EventMap events;
        };
};

class npc_yorsahj_the_unsleeping_mana_void: public CreatureScript
{
    public:
        npc_yorsahj_the_unsleeping_mana_void() : CreatureScript("npc_yorsahj_the_unsleeping_mana_void") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_yorsahj_the_unsleeping_mana_voidAI(pCreature);
        }

        struct npc_yorsahj_the_unsleeping_mana_voidAI : public Scripted_NoMovementAI
        {
            npc_yorsahj_the_unsleeping_mana_voidAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
                me->setActive(true);
                me->SetReactState(REACT_PASSIVE);
            }

            void JustDied(Unit* /*killer*/) override
            {
                DoCastAOE(SPELL_MANA_DIFFUSION, true);
                me->DespawnOrUnsummon(1000);
            }
        };
};

class spell_yorsahj_the_unsleeping_deep_corruption : public SpellScriptLoader
{
    public:
        spell_yorsahj_the_unsleeping_deep_corruption() : SpellScriptLoader("spell_yorsahj_the_unsleeping_deep_corruption") { }

        class spell_yorsahj_the_unsleeping_deep_corruption_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_yorsahj_the_unsleeping_deep_corruption_AuraScript);

            void HandlePeriodicTick(AuraEffect const* /*aurEff*/)
            {
                if (!GetUnitOwner())
                    return;

                if (Aura* aur = GetAura())
                {
                    if (aur->GetStackAmount() >= 5)
                    {
                        uint32 spellId = SPELL_DEEP_CORRUPTION_DMG;
                        GetUnitOwner()->CastSpell(GetUnitOwner(), spellId, true);
                        aur->Remove();
                    }
                }
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_yorsahj_the_unsleeping_deep_corruption_AuraScript::HandlePeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_yorsahj_the_unsleeping_deep_corruption_AuraScript();
        }
};

class spell_yorsahj_the_unsleeping_digestive_acid_aoe : public SpellScriptLoader
{
    public:
        spell_yorsahj_the_unsleeping_digestive_acid_aoe() : SpellScriptLoader("spell_yorsahj_the_unsleeping_digestive_acid_aoe") { }

        class spell_yorsahj_the_unsleeping_digestive_acid_aoe_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_yorsahj_the_unsleeping_digestive_acid_aoe_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (!GetCaster())
                    return;

                if (targets.empty())
                    return;

                if (Creature* pYorsahj = GetCaster()->FindNearestCreature(NPC_YORSAHJ, 200.0f))
                    if (Unit* pTank = pYorsahj->GetVictim())
                        targets.remove(pTank);

                uint32 max_targets = (GetCaster()->GetMap()->Is25ManRaid() ? 8 : 4);
                Trinity::Containers::RandomResize(targets, max_targets);
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                GetCaster()->CastSpell(GetHitUnit(), SPELL_DIGESTIVE_ACID_DMG, true);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_yorsahj_the_unsleeping_digestive_acid_aoe_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_yorsahj_the_unsleeping_digestive_acid_aoe_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_yorsahj_the_unsleeping_digestive_acid_aoe_SpellScript();
        }
};

//Digestive Acid Dmg 105573
class spell_yorsahj_the_unsleeping_digestive_acid_dmg : public SpellScriptLoader
{
public:
    spell_yorsahj_the_unsleeping_digestive_acid_dmg() : SpellScriptLoader("spell_yorsahj_the_unsleeping_digestive_acid_dmg") { }

    class spell_yorsahj_the_unsleeping_digestive_acid_dmg_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_yorsahj_the_unsleeping_digestive_acid_dmg_SpellScript);

        bool Load() override
        {
            // This script should execute only in Dragon Soul
            if (InstanceMap* instance = GetCaster()->GetMap()->ToInstanceMap())
            if (instance->GetInstanceScript())
            if (instance->GetScriptId() == sObjectMgr->GetScriptIdOrAdd(DSScriptName))
                return true;

            return false;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {

            PreventHitDamage();

            if (!GetHitUnit()->IsAlive() || !GetCaster())
                return;

            if (Creature* creature = GetCaster()->ToCreature())
            {
                if (Unit* target = GetHitUnit())
                {
                    if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(SPELL_DIGESTIVE_ACID_DMG))
                    {
                        uint32 damage = (uint32(GetEffectValue()));
                        SpellNonMeleeDamage damageInfo(creature, target, SPELL_DIGESTIVE_ACID_DMG, spellInfo->GetSpellXSpellVisualId(), spellInfo->SchoolMask);
                        damageInfo.damage = damage;
                        creature->SendSpellNonMeleeDamageLog(&damageInfo);
                        creature->DealSpellDamage(&damageInfo, false);
                    }
                }
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_yorsahj_the_unsleeping_digestive_acid_dmg_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_yorsahj_the_unsleeping_digestive_acid_dmg_SpellScript();
    }
};


class spell_yorsahj_the_unsleeping_mana_void : public SpellScriptLoader
{
    public:
        spell_yorsahj_the_unsleeping_mana_void() : SpellScriptLoader("spell_yorsahj_the_unsleeping_mana_void") { }

        class spell_yorsahj_the_unsleeping_mana_void_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_yorsahj_the_unsleeping_mana_void_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (!GetCaster())
                    return;

                if (targets.empty())
                    return;

                targets.remove_if(ManaCheck());
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_yorsahj_the_unsleeping_mana_void_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_yorsahj_the_unsleeping_mana_void_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
            }

        private:
            class ManaCheck
            {
                public:
                    ManaCheck() {}

                    bool operator()(WorldObject* unit)
                    {
                        if (unit->GetTypeId() != TYPEID_PLAYER)
                            return true;
                        return (unit->ToPlayer()->GetPowerType() != POWER_MANA);
                    }
            };

        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_yorsahj_the_unsleeping_mana_void_SpellScript();
        }
};

class spell_yorsahj_the_unsleeping_deep_corruption_aoe : public SpellScriptLoader
{
public:
    spell_yorsahj_the_unsleeping_deep_corruption_aoe() : SpellScriptLoader("spell_yorsahj_the_unsleeping_deep_corruption_aoe") {}

    class spell_yorsahj_the_unsleeping_deep_corruption_aoe_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_yorsahj_the_unsleeping_deep_corruption_aoe_AuraScript);

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* owner = GetUnitOwner();
            if (owner)
            if (owner->HasAura(SPELL_DEEP_CORRUPTION_AURA))
                owner->RemoveAura(SPELL_DEEP_CORRUPTION_AURA);
        }

        void Register() override
        {
            AfterEffectRemove += AuraEffectRemoveFn(spell_yorsahj_the_unsleeping_deep_corruption_aoe_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_yorsahj_the_unsleeping_deep_corruption_aoe_AuraScript();
    }
};

typedef boss_yorsahj_the_unsleeping::boss_yorsahj_the_unsleepingAI YorsahjAI;

class achievement_taste_the_rainbow : public AchievementCriteriaScript
{
    public:
        achievement_taste_the_rainbow(char const* scriptName, uint32 Id) : AchievementCriteriaScript(scriptName), _Id(Id) { }

        bool OnCheck(Player* /*source*/, Unit* target) override
        {
            if (!target)
                return false;

            if (YorsahjAI* jorsahjAI = CAST_AI(YorsahjAI, target->GetAI()))
                return jorsahjAI->AllowAchieve(_Id);

            return false;
        }

    private:
        uint32 _Id;
};

void AddSC_boss_yorsahj_the_unsleeping()
{
    new boss_yorsahj_the_unsleeping();
    new npc_yorsahj_the_unsleeping_globule();
    new npc_yorsahj_the_unsleeping_forgotten_one();
    new npc_yorsahj_the_unsleeping_mana_void();
    new spell_yorsahj_the_unsleeping_deep_corruption();
    new spell_yorsahj_the_unsleeping_digestive_acid_aoe();
    new spell_yorsahj_the_unsleeping_digestive_acid_dmg();
    new spell_yorsahj_the_unsleeping_mana_void();
    new spell_yorsahj_the_unsleeping_deep_corruption_aoe();
    new achievement_taste_the_rainbow("achievement_taste_the_rainbow_BY", 0);
    new achievement_taste_the_rainbow("achievement_taste_the_rainbow_RG", 1);
    new achievement_taste_the_rainbow("achievement_taste_the_rainbow_BB", 2);
    new achievement_taste_the_rainbow("achievement_taste_the_rainbow_PY", 3);
}
