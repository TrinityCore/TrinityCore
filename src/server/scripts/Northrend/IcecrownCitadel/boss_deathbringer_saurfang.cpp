/*
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "ScriptPCH.h"
#include "icecrown_citadel.h"

enum eScriptTexts
{
    SAY_INTRO_ALLIANCE_1            = -1631029,
    SAY_INTRO_ALLIANCE_2            = -1631030,
    SAY_INTRO_ALLIANCE_3            = -1631031,
    SAY_INTRO_ALLIANCE_4            = -1631032,
    SAY_INTRO_ALLIANCE_5            = -1631033,
    SAY_INTRO_ALLIANCE_6            = -1631034,
    SAY_INTRO_ALLIANCE_7            = -1631035,

    SAY_INTRO_HORDE_1               = -1631036,
    SAY_INTRO_HORDE_2               = -1631037,
    SAY_INTRO_HORDE_3               = -1631038,
    SAY_INTRO_HORDE_4               = -1631039,
    SAY_INTRO_HORDE_5               = -1631040,
    SAY_INTRO_HORDE_6               = -1631041,
    SAY_INTRO_HORDE_7               = -1631042,
    SAY_INTRO_HORDE_8               = -1631043,
    SAY_INTRO_HORDE_9               = -1631044,

    SAY_AGGRO                       = -1631045,
    SAY_MARK_OF_THE_FALLEN_CHAMPION = -1631046,
    SAY_BLOOD_BEASTS                = -1631047,
    SAY_KILL_1                      = -1631048,
    SAY_KILL_2                      = -1631049,
    SAY_FRENZY                      = -1631050,
    SAY_BERSERK                     = -1631051,
    SAY_DEATH                       = -1631052,

    SAY_OUTRO_ALLIANCE_1            = -1631053, // TODO ALLIANCE OUTRO
    SAY_OUTRO_ALLIANCE_2            = -1631054,
    SAY_OUTRO_ALLIANCE_3            = -1631055,
    SAY_OUTRO_ALLIANCE_4            = -1631056,
    SAY_OUTRO_ALLIANCE_5            = -1631057,
    SAY_OUTRO_ALLIANCE_6            = -1631058,
    SAY_OUTRO_ALLIANCE_7            = -1631059,
    SAY_OUTRO_ALLIANCE_8            = -1631060,
    SAY_OUTRO_ALLIANCE_9            = -1631061,
    SAY_OUTRO_ALLIANCE_10           = -1631062,
    SAY_OUTRO_ALLIANCE_11           = -1631063,
    SAY_OUTRO_ALLIANCE_12           = -1631064, // kneel after WP reached
    SAY_OUTRO_ALLIANCE_13           = -1631065,
    SAY_OUTRO_ALLIANCE_14           = -1631066,
    SAY_OUTRO_ALLIANCE_15           = -1631067,
    SAY_OUTRO_ALLIANCE_16           = -1631068,
    SAY_OUTRO_ALLIANCE_17           = -1631069,
    SAY_OUTRO_ALLIANCE_18           = -1631070,
    SAY_OUTRO_ALLIANCE_19           = -1631071,
    SAY_OUTRO_ALLIANCE_20           = -1631072,
    SAY_OUTRO_ALLIANCE_21           = -1631073,

    SAY_OUTRO_HORDE_1               = -1631074,
    SAY_OUTRO_HORDE_2               = -1631075,
    SAY_OUTRO_HORDE_3               = -1631076,
    SAY_OUTRO_HORDE_4               = -1631077
};

enum eSpells
{
    // Deathbringer Saurfang
    SPELL_ZERO_POWER                    = 72242,
    SPELL_GRIP_OF_AGONY                 = 70572, // Intro
    SPELL_BLOOD_LINK                    = 72178,
    SPELL_MARK_OF_THE_FALLEN_CHAMPION_S = 72256,
    SPELL_RUNE_OF_BLOOD_S               = 72408,

    SPELL_SUMMON_BLOOD_BEAST            = 72172,
    SPELL_SUMMON_BLOOD_BEAST_25_MAN     = 72356, // Additional cast, does not replace
    SPELL_FRENZY                        = 72737,
    SPELL_BLOOD_NOVA_TRIGGER            = 72378,
    SPELL_BLOOD_NOVA                    = 72380,
    SPELL_BLOOD_POWER                   = 72371,
    SPELL_BLOOD_LINK_POWER              = 72195,
    SPELL_BLOOD_LINK_DUMMY              = 72202,
    SPELL_MARK_OF_THE_FALLEN_CHAMPION   = 72293,
    SPELL_BOILING_BLOOD                 = 72385,
    SPELL_RUNE_OF_BLOOD                 = 72410,

    // Blood Beast
    SPELL_BLOOD_LINK_BEAST              = 72176,
    SPELL_RESISTANT_SKIN                = 72723,
    SPELL_SCENT_OF_BLOOD                = 72769, // Heroic only

    SPELL_RIDE_VEHICLE                  = 70640, // Outro
    SPELL_ACHIEVEMENT                   = 72928
};

// Helper to get id of the aura on different modes (HasAura(baseId) wont work)
#define BOILING_BLOOD_HELPER RAID_MODE(72385,72441,72442,72443)

enum eEvents
{
    EVENT_INTRO_ALLIANCE_1      = 1,
    EVENT_INTRO_ALLIANCE_2      = 2,
    EVENT_INTRO_ALLIANCE_3      = 3,
    EVENT_INTRO_ALLIANCE_4      = 4,
    EVENT_INTRO_ALLIANCE_5      = 5,
    EVENT_INTRO_ALLIANCE_6      = 6,
    EVENT_INTRO_ALLIANCE_7      = 7,

    EVENT_INTRO_HORDE_1         = 8,
    EVENT_INTRO_HORDE_2         = 9,
    EVENT_INTRO_HORDE_3         = 10,
    EVENT_INTRO_HORDE_4         = 11,
    EVENT_INTRO_HORDE_5         = 12,
    EVENT_INTRO_HORDE_6         = 13,
    EVENT_INTRO_HORDE_7         = 14,
    EVENT_INTRO_HORDE_8         = 15,
    EVENT_INTRO_HORDE_9         = 16,

    EVENT_INTRO_FINISH          = 17,

    EVENT_BERSERK               = 18,
    EVENT_SUMMON_BLOOD_BEAST    = 19,
    EVENT_BOILING_BLOOD         = 20,
    EVENT_BLOOD_NOVA            = 21,
    EVENT_RUNE_OF_BLOOD         = 22,

    EVENT_OUTRO_ALLIANCE_1      = 23,
    EVENT_OUTRO_ALLIANCE_2      = 24,
    EVENT_OUTRO_ALLIANCE_3      = 25,
    EVENT_OUTRO_ALLIANCE_4      = 26,
    EVENT_OUTRO_ALLIANCE_5      = 27,
    EVENT_OUTRO_ALLIANCE_6      = 28,
    EVENT_OUTRO_ALLIANCE_7      = 29,
    EVENT_OUTRO_ALLIANCE_8      = 30,
    EVENT_OUTRO_ALLIANCE_9      = 31,
    EVENT_OUTRO_ALLIANCE_10     = 32,
    EVENT_OUTRO_ALLIANCE_11     = 33,
    EVENT_OUTRO_ALLIANCE_12     = 34,
    EVENT_OUTRO_ALLIANCE_13     = 35,
    EVENT_OUTRO_ALLIANCE_14     = 36,
    EVENT_OUTRO_ALLIANCE_15     = 37,
    EVENT_OUTRO_ALLIANCE_16     = 38,
    EVENT_OUTRO_ALLIANCE_17     = 39,
    EVENT_OUTRO_ALLIANCE_18     = 40,
    EVENT_OUTRO_ALLIANCE_19     = 41,
    EVENT_OUTRO_ALLIANCE_20     = 42,
    EVENT_OUTRO_ALLIANCE_21     = 43,

    EVENT_OUTRO_HORDE_1         = 44,
    EVENT_OUTRO_HORDE_2         = 45,
    EVENT_OUTRO_HORDE_3         = 46,
    EVENT_OUTRO_HORDE_4         = 47,
    EVENT_OUTRO_HORDE_5         = 48,
    EVENT_OUTRO_HORDE_6         = 49,
    EVENT_OUTRO_HORDE_7         = 50,
    EVENT_OUTRO_HORDE_8         = 51
};

enum ePhases
{
    PHASE_INTRO_A       = 1,
    PHASE_INTRO_H       = 2,
    PHASE_COMBAT        = 3,

    PHASE_INTRO_MASK    = (1 << PHASE_INTRO_A) | (1 << PHASE_INTRO_H),
};

enum eActions
{
    ACTION_START_EVENT                  = -3781300,
    ACTION_CONTINUE_INTRO               = -3781301,
    ACTION_CHARGE                       = -3781302,
    ACTION_START_OUTRO                  = -3781303,
    ACTION_DESPAWN                      = -3781304,
    ACTION_MARK_OF_THE_FALLEN_CHAMPION  = -72293,
};

#define DATA_MADE_A_MESS 45374613 // 4537, 4613 are achievement IDs

enum eMovePoints
{
    POINT_SAURFANG          = 3781300,
    POINT_FIRST_STEP        = 3781301,
    POINT_CHARGE            = 3781302,
    POINT_CHOKE             = 3781303,
    POINT_CORPSE            = 3781304,
    POINT_FINAL             = 3781305
};

static const Position deathbringerPos = {-496.3542f, 2211.33f, 541.1138f, 0.0f};
static const Position firstStepPos = {-541.3177f, 2211.365f, 539.2921f, 0.0f};

static const Position chargePos[6] =
{
    {-509.6505f, 2211.377f, 539.2872f, 0.0f}, // High Overlord Saurfang/Muradin Bronzebeard
    {-508.7480f, 2211.897f, 539.2870f, 0.0f}, // front left
    {-509.2929f, 2211.411f, 539.2870f, 0.0f}, // front right
    {-506.6607f, 2211.367f, 539.2870f, 0.0f}, // back middle
    {-506.1137f, 2213.306f, 539.2870f, 0.0f}, // back left
    {-509.0040f, 2211.743f, 539.2870f, 0.0f}  // back right
};

static const Position chokePos[6] =
{
    {-514.4834f, 2211.334f, 549.2887f, 0.0f}, // High Overlord Saurfang/Muradin Bronzebeard
    {-510.1081f, 2211.592f, 546.3773f, 0.0f}, // front left
    {-513.3210f, 2211.396f, 551.2882f, 0.0f}, // front right
    {-507.3684f, 2210.353f, 545.7497f, 0.0f}, // back middle
    {-507.0486f, 2212.999f, 545.5512f, 0.0f}, // back left
    {-510.7041f, 2211.069f, 546.5298f, 0.0f}  // back right
};

static const Position finalPos = {-563.7552f, 2211.328f, 538.7848f, 0.0f};

class boss_deathbringer_saurfang : public CreatureScript
{
    public:
        boss_deathbringer_saurfang() : CreatureScript("boss_deathbringer_saurfang") { }

        struct boss_deathbringer_saurfangAI : public ScriptedAI
        {
            boss_deathbringer_saurfangAI(Creature* pCreature) : ScriptedAI(pCreature), summons(pCreature)
            {
                ASSERT(pCreature->GetVehicleKit()); // we dont actually use it, just check if exists
                pInstance = pCreature->GetInstanceScript();
                bIntroDone = false;
                uiFallenChampionCount = 0;
            }

            void Reset()
            {
                events.Reset();
                events.SetPhase(PHASE_COMBAT);
                bFrenzy = false;
                me->SetPower(POWER_ENERGY, 0);
                DoCast(me, SPELL_ZERO_POWER, true);
                DoCast(me, SPELL_BLOOD_LINK, true);
                DoCast(me, SPELL_MARK_OF_THE_FALLEN_CHAMPION_S, true);
                DoCast(me, SPELL_RUNE_OF_BLOOD_S, true);
                me->RemoveAurasDueToSpell(SPELL_BERSERK);
                me->RemoveAurasDueToSpell(SPELL_FRENZY);
                me->RemoveAurasDueToSpell(SPELL_BLOOD_POWER);
                uiFallenChampionCount = 0;
                summons.DespawnAll();
                if (pInstance)
                    pInstance->SetData(DATA_DEATHBRINGER_SAURFANG, NOT_STARTED);
            }

            void EnterCombat(Unit* /*who*/)
            {
                DoScriptText(SAY_AGGRO, me);
                events.ScheduleEvent(EVENT_SUMMON_BLOOD_BEAST, 30000, 0, PHASE_COMBAT);
                events.ScheduleEvent(EVENT_BERSERK, 480000, 0, PHASE_COMBAT);
                events.ScheduleEvent(EVENT_BOILING_BLOOD, 15500, 0, PHASE_COMBAT);
                events.ScheduleEvent(EVENT_BLOOD_NOVA, 17000, 0, PHASE_COMBAT);
                events.ScheduleEvent(EVENT_RUNE_OF_BLOOD, 20000, 0, PHASE_COMBAT);

                if (pInstance)
                    pInstance->SetData(DATA_DEATHBRINGER_SAURFANG, IN_PROGRESS);
            }

            void JustDied(Unit* /*killer*/)
            {
                DoCastAOE(SPELL_ACHIEVEMENT, true);
                DoScriptText(SAY_DEATH, me);

                if (pInstance)
                {
                    pInstance->SetData(DATA_DEATHBRINGER_SAURFANG, DONE);
                    if (Creature* creature = ObjectAccessor::GetCreature(*me, pInstance->GetData64(DATA_SAURFANG_EVENT_NPC)))
                        creature->AI()->DoAction(ACTION_START_OUTRO);
                }
            }

            void MoveInLineOfSight(Unit* /*who*/)
            {
                // not calling CreatureAI::MoveInLineOfSight to prevent entering combat
            }

            void AttackStart(Unit* victim)
            {
                if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE))
                    return;

                ScriptedAI::AttackStart(victim);
            }

            void EnterEvadeMode()
            {
                ScriptedAI::EnterEvadeMode();
                if (bIntroDone)
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
            }

            void JustReachedHome()
            {
                if(pInstance)
                    pInstance->SetData(DATA_DEATHBRINGER_SAURFANG, FAIL);
            }

            void KilledUnit(Unit *victim)
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    DoScriptText(RAND(SAY_KILL_1, SAY_KILL_2), me);
            }

            void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/)
            {
                if (!bFrenzy && HealthBelowPct(31)) // AT 30%, not below
                {
                    bFrenzy = true;
                    DoCast(me, SPELL_FRENZY);
                    DoScriptText(SAY_FRENZY, me);
                }
            }

            void JustSummoned(Creature* summon)
            {
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 1))
                    summon->AI()->AttackStart(pTarget);

                if (IsHeroic())
                    DoCast(summon, SPELL_SCENT_OF_BLOOD);

                summon->AI()->DoCast(summon, SPELL_BLOOD_LINK_BEAST, true);
                summon->AI()->DoCast(summon, SPELL_RESISTANT_SKIN, true);
                summons.Summon(summon);
            }

            void SummonedCreatureDespawn(Creature* summon)
            {
                summons.Despawn(summon);
            }

            void MovementInform(uint32 type, uint32 id)
            {
                if (type != POINT_MOTION_TYPE && id != POINT_SAURFANG)
                    return;

                if (pInstance)
                    pInstance->HandleGameObject(pInstance->GetData64(DATA_SAURFANG_DOOR), false);
            }

            void SpellHitTarget(Unit* target, const SpellEntry* spell)
            {
                switch (spell->Id)
                {
                    case SPELL_MARK_OF_THE_FALLEN_CHAMPION:
                        DoScriptText(SAY_MARK_OF_THE_FALLEN_CHAMPION, me);
                        break;
                    case 72255: // Mark of the Fallen Champion, triggered id
                    case 72444:
                    case 72445:
                    case 72446:
                        if (me->GetPower(POWER_ENERGY) != me->GetMaxPower(POWER_ENERGY))
                            target->CastCustomSpell(SPELL_BLOOD_LINK_DUMMY, SPELLVALUE_BASE_POINT0, 1, me, true);
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim() && !(events.GetPhaseMask() & PHASE_INTRO_MASK))
                    return;

                events.Update(diff);

                if (me->hasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_INTRO_ALLIANCE_2:
                            DoScriptText(SAY_INTRO_ALLIANCE_2, me);
                            break;
                        case EVENT_INTRO_ALLIANCE_3:
                            DoScriptText(SAY_INTRO_ALLIANCE_3, me);
                            break;
                        case EVENT_INTRO_ALLIANCE_6:
                            DoScriptText(SAY_INTRO_ALLIANCE_6, me);
                            DoScriptText(SAY_INTRO_ALLIANCE_7, me);
                            DoCast(me, SPELL_GRIP_OF_AGONY);
                            break;
                        case EVENT_INTRO_HORDE_2:
                            DoScriptText(SAY_INTRO_HORDE_2, me);
                            break;
                        case EVENT_INTRO_HORDE_4:
                            DoScriptText(SAY_INTRO_HORDE_4, me);
                            break;
                        case EVENT_INTRO_HORDE_9:
                            DoCast(me, SPELL_GRIP_OF_AGONY);
                            DoScriptText(SAY_INTRO_HORDE_9, me);
                            break;
                        case EVENT_INTRO_FINISH:
                            events.SetPhase(PHASE_COMBAT);
                            bIntroDone = true;
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
                            break;
                        case EVENT_SUMMON_BLOOD_BEAST:
                            for (uint8 i10 = 0; i10 < 2; ++i10)
                                DoCast(me, SPELL_SUMMON_BLOOD_BEAST+i10);
                            if (Is25ManRaid())
                                for (uint8 i25 = 0; i25 < 3; ++i25)
                                    DoCast(me, SPELL_SUMMON_BLOOD_BEAST_25_MAN+i25);
                            DoScriptText(SAY_BLOOD_BEASTS, me);
                            events.ScheduleEvent(EVENT_SUMMON_BLOOD_BEAST, 40000, 0, PHASE_COMBAT);
                            break;
                        case EVENT_BLOOD_NOVA:
                        {
                            // select at range only
                            Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, -10.0f, true);
                            if (!target)
                                target = SelectTarget(SELECT_TARGET_RANDOM, 1, 10.0f, true);    // noone? select melee
                            if (target)
                                DoCast(target, SPELL_BLOOD_NOVA_TRIGGER);
                            events.ScheduleEvent(EVENT_BLOOD_NOVA, urand(20000, 25000), 0, PHASE_COMBAT);
                            break;
                        }
                        case EVENT_RUNE_OF_BLOOD:
                            DoCastVictim(SPELL_RUNE_OF_BLOOD);
                            events.ScheduleEvent(EVENT_RUNE_OF_BLOOD, urand(20000, 25000), 0, PHASE_COMBAT);
                            break;
                        case EVENT_BOILING_BLOOD:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true, -BOILING_BLOOD_HELPER))
                                DoCast(target, SPELL_BOILING_BLOOD);
                            events.ScheduleEvent(EVENT_BOILING_BLOOD, urand(15000, 20000), 0, PHASE_COMBAT);
                            break;
                        case EVENT_BERSERK:
                            DoCast(me, SPELL_BERSERK);
                            DoScriptText(SAY_BERSERK, me);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

            uint32 GetData(uint32 type)
            {
                if (type == DATA_MADE_A_MESS)
                    if (uiFallenChampionCount < RAID_MODE<uint32>(3, 5, 3, 5))
                        return 1;

                return 0;
            }

            // intro setup
            void DoAction(const int32 action)
            {
                if (action == PHASE_INTRO_A || action == PHASE_INTRO_H)
                {
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    // controls what events will execute
                    events.SetPhase(uint32(action));

                    me->SetHomePosition(deathbringerPos.GetPositionX(), deathbringerPos.GetPositionY(), deathbringerPos.GetPositionZ(), me->GetOrientation());
                    me->GetMotionMaster()->MovePoint(POINT_SAURFANG, deathbringerPos.GetPositionX(), deathbringerPos.GetPositionY(), deathbringerPos.GetPositionZ());

                    events.ScheduleEvent(EVENT_INTRO_ALLIANCE_2, 2500, 0, PHASE_INTRO_A);
                    events.ScheduleEvent(EVENT_INTRO_ALLIANCE_3, 20000, 0, PHASE_INTRO_A);

                    events.ScheduleEvent(EVENT_INTRO_HORDE_2, 5000, 0, PHASE_INTRO_H);
                }
                else if (action == ACTION_CONTINUE_INTRO)
                {
                    events.ScheduleEvent(EVENT_INTRO_ALLIANCE_6, 6500+500, 0, PHASE_INTRO_A);
                    events.ScheduleEvent(EVENT_INTRO_FINISH, 8000, 0, PHASE_INTRO_A);

                    events.ScheduleEvent(EVENT_INTRO_HORDE_4, 6500, 0, PHASE_INTRO_H);
                    events.ScheduleEvent(EVENT_INTRO_HORDE_9, 46700+1000+500, 0, PHASE_INTRO_H);
                    events.ScheduleEvent(EVENT_INTRO_FINISH,  46700+1000+8000, 0, PHASE_INTRO_H);
                }
                else if (action == ACTION_MARK_OF_THE_FALLEN_CHAMPION)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true, -SPELL_MARK_OF_THE_FALLEN_CHAMPION))
                    {
                        ++uiFallenChampionCount;
                        me->RemoveAurasDueToSpell(SPELL_BLOOD_POWER);
                        DoCast(target, SPELL_MARK_OF_THE_FALLEN_CHAMPION);
                        me->SetPower(POWER_ENERGY, 0);
                    }
                }
                else
                    ASSERT(false);
            }

        private:
            EventMap events;
            InstanceScript* pInstance;
            SummonList summons;
            bool bIntroDone;
            bool bFrenzy;   // faster than iterating all auras to find Frenzy
            uint32 uiFallenChampionCount;
        };

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new boss_deathbringer_saurfangAI(pCreature);
        }
};

class npc_high_overlord_saurfang_icc : public CreatureScript
{
    public:
        npc_high_overlord_saurfang_icc() : CreatureScript("npc_high_overlord_saurfang_icc") { }

        struct npc_high_overlord_saurfangAI : public ScriptedAI
        {
            npc_high_overlord_saurfangAI(Creature* pCreature) : ScriptedAI(pCreature), vehicle(pCreature->GetVehicleKit())
            {
                ASSERT(vehicle);
                pInstance = me->GetInstanceScript();
            }

            void Reset()
            {
                events.Reset();
            }

            void DoAction(const int32 action)
            {
                if (action == ACTION_START_EVENT)
                {
                    GetCreatureListWithEntryInGrid(guardList, me, NPC_SE_KOR_KRON_REAVER, 20.0f);
                    guardList.sort(Trinity::ObjectDistanceOrderPred(me));
                    uint32 x = 1;
                    for (std::list<Creature*>::iterator itr = guardList.begin(); itr != guardList.end(); ++x, ++itr)
                        (*itr)->AI()->SetData(0, x);

                    me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    DoScriptText(SAY_INTRO_HORDE_1, me);
                    events.SetPhase(PHASE_INTRO_H);
                    events.ScheduleEvent(EVENT_INTRO_HORDE_3, 18500, 0, PHASE_INTRO_H);
                    if (pInstance)
                    {
                        uiDeathbringerSaurfangGUID = pInstance->GetData64(DATA_DEATHBRINGER_SAURFANG);
                        pInstance->HandleGameObject(pInstance->GetData64(DATA_SAURFANG_DOOR), true);
                    }
                    if (Creature* deathbringer = ObjectAccessor::GetCreature(*me, uiDeathbringerSaurfangGUID))
                        deathbringer->AI()->DoAction(PHASE_INTRO_H);
                }
                else if (action == ACTION_START_OUTRO)
                {
                    me->RemoveAurasDueToSpell(SPELL_GRIP_OF_AGONY);
                    DoScriptText(SAY_OUTRO_HORDE_1, me);
                    events.ScheduleEvent(EVENT_OUTRO_HORDE_2, 10000);   // say
                    events.ScheduleEvent(EVENT_OUTRO_HORDE_3, 18000);   // say
                    events.ScheduleEvent(EVENT_OUTRO_HORDE_4, 24000);   // cast
                    events.ScheduleEvent(EVENT_OUTRO_HORDE_5, 30000);   // move
                    me->RemoveUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                    me->SendMovementFlagUpdate();
                    me->Relocate(me->GetPositionX(), me->GetPositionY(), 539.2917f);
                    me->SendMonsterMove(me->GetPositionX(), me->GetPositionY(), 539.2917f, SPLINEFLAG_FALLING, 0, 0.0f);
                    for (std::list<Creature*>::iterator itr = guardList.begin(); itr != guardList.end(); ++itr)
                        (*itr)->AI()->DoAction(ACTION_DESPAWN);
                }
            }

            void SpellHit(Unit* /*caster*/, SpellEntry const* spell)
            {
                if (spell->Id == SPELL_GRIP_OF_AGONY)
                {
                    me->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                    me->GetMotionMaster()->MovePoint(POINT_CHOKE, chokePos[0]);
                }
            }

            void MovementInform(uint32 type, uint32 id)
            {
                if (type != POINT_MOTION_TYPE)
                    return;

                if (id == POINT_FIRST_STEP)
                {
                    me->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
                    DoScriptText(SAY_INTRO_HORDE_3, me);
                    events.ScheduleEvent(EVENT_INTRO_HORDE_5, 15500, 0, PHASE_INTRO_H);
                    events.ScheduleEvent(EVENT_INTRO_HORDE_6, 29500, 0, PHASE_INTRO_H);
                    events.ScheduleEvent(EVENT_INTRO_HORDE_7, 43800, 0, PHASE_INTRO_H);
                    events.ScheduleEvent(EVENT_INTRO_HORDE_8, 47000, 0, PHASE_INTRO_H);
                    if (Creature* deathbringer = ObjectAccessor::GetCreature(*me, uiDeathbringerSaurfangGUID))
                        deathbringer->AI()->DoAction(ACTION_CONTINUE_INTRO);
                }
                //else if (id == EVENT_FALL_GROUND)
                //    me->RemoveUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                else if (id == POINT_CORPSE)
                {
                    if (Creature* deathbringer = ObjectAccessor::GetCreature(*me, uiDeathbringerSaurfangGUID))
                    {
                        deathbringer->CastSpell(me, SPELL_RIDE_VEHICLE, true);  // for the packet logs.
                        deathbringer->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        deathbringer->setDeathState(ALIVE);
                        deathbringer->EnterVehicle(vehicle, 0);
                    }
                    events.ScheduleEvent(EVENT_OUTRO_HORDE_5, 1000);    // move
                    events.ScheduleEvent(EVENT_OUTRO_HORDE_6, 4000);    // say
                }
                else if (id == POINT_FINAL)
                {
                    if (Creature* deathbringer = ObjectAccessor::GetCreature(*me, uiDeathbringerSaurfangGUID))
                        deathbringer->ForcedDespawn();
                    me->ForcedDespawn();
                }
            }

            void UpdateAI(const uint32 diff)
            {
                events.Update(diff);
                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_INTRO_HORDE_3:
                            me->AddUnitMovementFlag(MOVEMENTFLAG_WALKING);
                            me->GetMotionMaster()->MovePoint(POINT_FIRST_STEP, firstStepPos.GetPositionX(), firstStepPos.GetPositionY(), firstStepPos.GetPositionZ());
                            break;
                        case EVENT_INTRO_HORDE_5:
                            DoScriptText(SAY_INTRO_HORDE_5, me);
                            break;
                        case EVENT_INTRO_HORDE_6:
                            DoScriptText(SAY_INTRO_HORDE_6, me);
                            break;
                        case EVENT_INTRO_HORDE_7:
                            DoScriptText(SAY_INTRO_HORDE_7, me);
                            break;
                        case EVENT_INTRO_HORDE_8:
                            DoScriptText(SAY_INTRO_HORDE_8, me);
                            for (std::list<Creature*>::iterator itr = guardList.begin(); itr != guardList.end(); ++itr)
                                (*itr)->AI()->DoAction(ACTION_CHARGE);
                            me->GetMotionMaster()->MoveCharge(chargePos[0].GetPositionX(), chargePos[0].GetPositionY(), chargePos[0].GetPositionZ(), 8.5f, POINT_CHARGE);
                            break;
                        case EVENT_OUTRO_HORDE_2:   // say
                            if (Creature* deathbringer = ObjectAccessor::GetCreature(*me, uiDeathbringerSaurfangGUID))
                                me->SetFacingToObject(deathbringer);
                            DoScriptText(SAY_OUTRO_HORDE_2, me);
                            break;
                        case EVENT_OUTRO_HORDE_3:   // say
                            DoScriptText(SAY_OUTRO_HORDE_3, me);
                            break;
                        case EVENT_OUTRO_HORDE_4:   // move
                            if (Creature* deathbringer = ObjectAccessor::GetCreature(*me, uiDeathbringerSaurfangGUID))
                            {
                                float x, y, z;
                                deathbringer->GetClosePoint(x, y, z, deathbringer->GetObjectSize());
                                me->AddUnitMovementFlag(MOVEMENTFLAG_WALKING);
                                me->GetMotionMaster()->MovePoint(POINT_CORPSE ,x, y, z);
                            }
                            break;
                        case EVENT_OUTRO_HORDE_5:   // move
                            me->GetMotionMaster()->MovePoint(POINT_FINAL, finalPos);
                            break;
                        case EVENT_OUTRO_HORDE_6:   // say
                            DoScriptText(SAY_OUTRO_HORDE_4, me);
                            break;
                    }
                }
            }

        private:
            EventMap events;
            InstanceScript* pInstance;
            Vehicle* vehicle;
            uint64 uiDeathbringerSaurfangGUID;
            std::list<Creature*> guardList;
        };

        bool OnGossipHello(Player* pPlayer, Creature* pCreature)
        {
            if (pCreature->GetPositionZ() < 530.0f)
                return false;

            InstanceScript* pInstance = pCreature->GetInstanceScript();
            if (pInstance && pInstance->GetData(DATA_DEATHBRINGER_SAURFANG) != DONE)
            {
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Let it begin...", 631, -ACTION_START_EVENT);
                pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, pCreature->GetGUID());
            }

            return true;
        }

        bool OnGossipSelect(Player* /*pPlayer*/, Creature* pCreature, uint32 /*sender*/, uint32 action)
        {
            if (action == -ACTION_START_EVENT)
                pCreature->AI()->DoAction(ACTION_START_EVENT);

            return true;
        }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_high_overlord_saurfangAI(pCreature);
        }
};

class npc_muradin_bronzebeard_icc : public CreatureScript
{
    public:
        npc_muradin_bronzebeard_icc() : CreatureScript("npc_muradin_bronzebeard_icc") { }

        struct npc_muradin_bronzebeard_iccAI : public ScriptedAI
        {
            npc_muradin_bronzebeard_iccAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                pInstance = me->GetInstanceScript();
            }

            void Reset()
            {
                events.Reset();
            }

            void DoAction(const int32 action)
            {
                if (action == ACTION_START_EVENT)
                {
                    GetCreatureListWithEntryInGrid(guardList, me, NPC_SE_SKYBREAKER_MARINE, 20.0f);
                    guardList.sort(Trinity::ObjectDistanceOrderPred(me));
                    uint32 x = 1;
                    for (std::list<Creature*>::iterator itr = guardList.begin(); itr != guardList.end(); ++x, ++itr)
                        (*itr)->AI()->SetData(0, x);

                    me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    DoScriptText(SAY_INTRO_ALLIANCE_1, me);
                    events.ScheduleEvent(EVENT_INTRO_ALLIANCE_4, 2500+17500+9500, 0, PHASE_INTRO_A);
                    events.SetPhase(PHASE_INTRO_A);
                    if (pInstance)
                    {
                        uiDeathbringerSaurfangGUID = pInstance->GetData64(DATA_DEATHBRINGER_SAURFANG);
                        pInstance->HandleGameObject(pInstance->GetData64(DATA_SAURFANG_DOOR), true);
                    }
                    if (Creature* deathbringer = ObjectAccessor::GetCreature(*me, uiDeathbringerSaurfangGUID))
                        deathbringer->AI()->DoAction(PHASE_INTRO_A);
                }
                else if (action == ACTION_START_OUTRO)
                {
                    me->RemoveAurasDueToSpell(SPELL_GRIP_OF_AGONY);
                    DoScriptText(SAY_OUTRO_ALLIANCE_1, me);
                    me->RemoveUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                    me->SendMovementFlagUpdate();
                    me->Relocate(me->GetPositionX(), me->GetPositionY(), 539.2917f);
                    me->SendMonsterMove(me->GetPositionX(), me->GetPositionY(), 539.2917f, SPLINEFLAG_FALLING, 0, 0.0f);
                    for (std::list<Creature*>::iterator itr = guardList.begin(); itr != guardList.end(); ++itr)
                        (*itr)->AI()->DoAction(ACTION_DESPAWN);
                }
            }

            void SpellHit(Unit* /*caster*/, SpellEntry const* spell)
            {
                if (spell->Id == SPELL_GRIP_OF_AGONY)
                {
                    me->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                    me->GetMotionMaster()->MovePoint(POINT_CHOKE, chokePos[0]);
                }
            }

            void MovementInform(uint32 type, uint32 id)
            {
                if (type != POINT_MOTION_TYPE || id != POINT_FIRST_STEP)
                    return;

                me->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
                DoScriptText(SAY_INTRO_ALLIANCE_4, me);
                events.ScheduleEvent(EVENT_INTRO_ALLIANCE_5, 5000, 0, PHASE_INTRO_A);
                if (Creature* deathbringer = ObjectAccessor::GetCreature(*me, uiDeathbringerSaurfangGUID))
                    deathbringer->AI()->DoAction(ACTION_CONTINUE_INTRO);
            }

            void UpdateAI(const uint32 diff)
            {
                events.Update(diff);
                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_INTRO_ALLIANCE_4:
                            me->AddUnitMovementFlag(MOVEMENTFLAG_WALKING);
                            me->GetMotionMaster()->MovePoint(POINT_FIRST_STEP, firstStepPos.GetPositionX(), firstStepPos.GetPositionY(), firstStepPos.GetPositionZ());
                            break;
                        case EVENT_INTRO_ALLIANCE_5:
                            DoScriptText(SAY_INTRO_ALLIANCE_5, me);
                            for (std::list<Creature*>::iterator itr = guardList.begin(); itr != guardList.end(); ++itr)
                                (*itr)->AI()->DoAction(ACTION_CHARGE);
                            me->GetMotionMaster()->MoveCharge(chargePos[0].GetPositionX(), chargePos[0].GetPositionY(), chargePos[0].GetPositionZ(), 8.5f, POINT_CHARGE);
                            break;
                    }
                }
            }

        private:
            EventMap events;
            InstanceScript* pInstance;
            uint64 uiDeathbringerSaurfangGUID;
            std::list<Creature*> guardList;
        };

        bool OnGossipHello(Player* pPlayer, Creature* pCreature)
        {
            if (pCreature->GetPositionZ() < 530.0f)
                return false;

            InstanceScript* pInstance = pCreature->GetInstanceScript();
            if (pInstance && pInstance->GetData(DATA_DEATHBRINGER_SAURFANG) != DONE)
            {
                pPlayer->ADD_GOSSIP_ITEM(0, "Let it begin...", 631, -ACTION_START_EVENT+1);
                pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, pCreature->GetGUID());
            }

            return true;
        }

        bool OnGossipSelect(Player* /*pPlayer*/, Creature* pCreature, uint32 /*sender*/, uint32 action)
        {
            if (action == -ACTION_START_EVENT+1)
                pCreature->AI()->DoAction(ACTION_START_EVENT);

            return true;
        }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_muradin_bronzebeard_iccAI(pCreature);
        }
};

class npc_saurfang_event : public CreatureScript
{
    public:
        npc_saurfang_event() : CreatureScript("npc_saurfang_event") { }

        struct npc_saurfang_eventAI : public ScriptedAI
        {
            npc_saurfang_eventAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                uiNPCindex = 0;
            }

            void SetData(uint32 type, uint32 data)
            {
                ASSERT(!type && data && data < 6);
                uiNPCindex = data;
            }

            void SpellHit(Unit* /*caster*/, SpellEntry const* spell)
            {
                if (spell->Id == SPELL_GRIP_OF_AGONY)
                {
                    me->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                    me->GetMotionMaster()->MovePoint(POINT_CHOKE, chokePos[uiNPCindex]);
                }
            }

            void DoAction(const int32 action)
            {
                if (action == ACTION_CHARGE && uiNPCindex)
                    me->GetMotionMaster()->MoveCharge(chargePos[uiNPCindex].GetPositionX(), chargePos[uiNPCindex].GetPositionY(), chargePos[uiNPCindex].GetPositionZ(), 13.0f, POINT_CHARGE);
                else if (action == ACTION_DESPAWN)
                    me->ForcedDespawn();
            }

        private:
            EventMap events;
            uint32 uiNPCindex;
        };

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_saurfang_eventAI(pCreature);
        }
};

class spell_deathbringer_blood_link : public SpellScriptLoader
{
    public:
        spell_deathbringer_blood_link() : SpellScriptLoader("spell_deathbringer_blood_link") { }

        class spell_deathbringer_blood_link_SpellScript : public SpellScript
        {
            bool Validate(SpellEntry const* /*spellInfo*/)
            {
                if (!sSpellStore.LookupEntry(SPELL_BLOOD_LINK_POWER))
                    return false;
                if (!sSpellStore.LookupEntry(SPELL_BLOOD_POWER))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                GetHitUnit()->CastCustomSpell(SPELL_BLOOD_LINK_POWER, SPELLVALUE_BASE_POINT0, GetEffectValue(), GetHitUnit(), true);
                if (!GetHitUnit()->HasAura(SPELL_BLOOD_POWER))
                    GetHitUnit()->CastSpell(GetHitUnit(), SPELL_BLOOD_POWER, true);
                else if (Aura* bloodPower = GetHitUnit()->GetAura(SPELL_BLOOD_POWER))
                    bloodPower->RecalculateAmountOfEffects();
                PreventHitDefaultEffect(EFFECT_0);
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_deathbringer_blood_link_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }

            bool Load()
            {
                if (GetSpellInfo()->Id != SPELL_BLOOD_LINK_DUMMY)
                    return false;
                return true;
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_deathbringer_blood_link_SpellScript();
        }
};

class spell_deathbringer_blood_link_aura : public SpellScriptLoader
{
    public:
        spell_deathbringer_blood_link_aura() : SpellScriptLoader("spell_deathbringer_blood_link_aura") { }

        class spell_deathbringer_blood_link_AuraScript : public AuraScript
        {
            bool Validate(SpellEntry const* /*spellInfo*/)
            {
                if (!sSpellStore.LookupEntry(SPELL_MARK_OF_THE_FALLEN_CHAMPION))
                    return false;
                return true;
            }

            void HandlePeriodicTick(AuraEffect const * /*aurEff*/, AuraApplication const * /*aurApp*/)
            {
                if (GetUnitOwner()->getPowerType() == POWER_ENERGY && GetUnitOwner()->GetPower(POWER_ENERGY) == GetUnitOwner()->GetMaxPower(POWER_ENERGY))
                    if (Creature* saurfang = GetUnitOwner()->ToCreature())
                        saurfang->AI()->DoAction(ACTION_MARK_OF_THE_FALLEN_CHAMPION);
            }

            void Register()
            {
                PreventDefaultEffect(EFFECT_1);
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_deathbringer_blood_link_AuraScript::HandlePeriodicTick, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
            }

            bool Load()
            {
                if (GetSpellProto()->Id != SPELL_BLOOD_LINK)
                    return false;
                return true;
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_deathbringer_blood_link_AuraScript();
        }
};

class spell_deathbringer_blood_power : public SpellScriptLoader
{
    public:
        spell_deathbringer_blood_power() : SpellScriptLoader("spell_deathbringer_blood_power") { }

        class spell_deathbringer_blood_power_SpellScript : public SpellScript
        {
            void ModAuraValue()
            {
                if (Aura* aura = GetHitAura())
                    aura->RecalculateAmountOfEffects();
            }

            void Register()
            {
                AfterHit += SpellHitFn(spell_deathbringer_blood_power_SpellScript::ModAuraValue);
            }
        };

        class spell_deathbringer_blood_power_AuraScript : public AuraScript
        {
            void RecalculateHook(AuraEffect const* /*aurEffect*/, int32& amount, bool& canBeRecalculated)
            {
                amount = GetUnitOwner()->GetPower(POWER_ENERGY);
                canBeRecalculated = true;
            }

            void Register()
            {
                OnEffectCalcAmount += AuraEffectCalcAmountFn(spell_deathbringer_blood_power_AuraScript::RecalculateHook, EFFECT_0, SPELL_AURA_MOD_SCALE);
                OnEffectCalcAmount += AuraEffectCalcAmountFn(spell_deathbringer_blood_power_AuraScript::RecalculateHook, EFFECT_1, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE);
            }

            bool Load()
            {
                if (GetUnitOwner()->getPowerType() != POWER_ENERGY)
                    return false;
                return true;
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_deathbringer_blood_power_SpellScript();
        }

        AuraScript* GetAuraScript() const
        {
            return new spell_deathbringer_blood_power_AuraScript();
        }
};

class spell_deathbringer_rune_of_blood : public SpellScriptLoader
{
    public:
        spell_deathbringer_rune_of_blood() : SpellScriptLoader("spell_deathbringer_rune_of_blood") { }

        class spell_deathbringer_rune_of_blood_SpellScript : public SpellScript
        {
            bool Validate(SpellEntry const* /*spellInfo*/)
            {
                if (!sSpellStore.LookupEntry(SPELL_BLOOD_LINK_DUMMY))
                    return false;
                return true;
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                PreventHitDefaultEffect(EFFECT_1);  // make this the default handler
                if (GetCaster()->GetPower(POWER_ENERGY) != GetCaster()->GetMaxPower(POWER_ENERGY))
                    GetHitUnit()->CastCustomSpell(SPELL_BLOOD_LINK_DUMMY, SPELLVALUE_BASE_POINT0, 1, GetCaster(), true);
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_deathbringer_rune_of_blood_SpellScript::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_deathbringer_rune_of_blood_SpellScript();
        }
};

class spell_deathbringer_blood_nova : public SpellScriptLoader
{
    public:
        spell_deathbringer_blood_nova() : SpellScriptLoader("spell_deathbringer_blood_nova") { }

        class spell_deathbringer_blood_nova_SpellScript : public SpellScript
        {
            bool Validate(SpellEntry const* /*spellInfo*/)
            {
                if (!sSpellStore.LookupEntry(SPELL_BLOOD_LINK_DUMMY))
                    return false;
                return true;
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                PreventHitDefaultEffect(EFFECT_1);  // make this the default handler
                if (GetCaster()->GetPower(POWER_ENERGY) != GetCaster()->GetMaxPower(POWER_ENERGY))
                    GetHitUnit()->CastCustomSpell(SPELL_BLOOD_LINK_DUMMY, SPELLVALUE_BASE_POINT0, 2, GetCaster(), true);
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_deathbringer_blood_nova_SpellScript::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_deathbringer_blood_nova_SpellScript();
        }
};

class achievement_ive_gone_and_made_a_mess : public AchievementCriteriaScript
{
    public:
        achievement_ive_gone_and_made_a_mess() : AchievementCriteriaScript("achievement_ive_gone_and_made_a_mess") { }

        bool OnCheck(Player* /*source*/, Unit* target)
        {
            if (Creature* saurfang = target->ToCreature())
                if (saurfang->AI()->GetData(DATA_MADE_A_MESS))
                    return true;

            return false;
        }
};

void AddSC_boss_deathbringer_saurfang()
{
    new boss_deathbringer_saurfang();
    new npc_high_overlord_saurfang_icc();
    new npc_muradin_bronzebeard_icc();
    new npc_saurfang_event();
    new spell_deathbringer_blood_link();
    new spell_deathbringer_blood_link_aura();
    new spell_deathbringer_blood_power();
    new spell_deathbringer_rune_of_blood();
    new spell_deathbringer_blood_nova();
    new achievement_ive_gone_and_made_a_mess();
}
