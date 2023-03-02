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

#include "ScriptMgr.h"
#include "CreatureTextMgr.h"
#include "Containers.h"
#include "MoveSplineInit.h"
#include "dragon_soul.h"
#include "ObjectMgr.h"
#include "SpellAuras.h"
#include "G3D/Vector3.h"
#include "SpellMgr.h"

enum ScriptedTexts
{
    SAY_AGGRO       = 0,
    SAY_DEATH       = 1,
    SAY_INTRO       = 2,
    SAY_KILL        = 3,
    SAY_SHADOWS     = 4,
    SAY_BLOOD       = 5,
    SAY_VOID        = 6,
    SAY_AGGRO_1     = 7,
    SAY_DEATH_1     = 8,
    SAY_INTRO_1     = 9,
    SAY_KILL_1      = 10,
    SAY_SHADOWS_1   = 11,
    SAY_BLOOD_1     = 12,
    SAY_VOID_1      = 13,
};

enum Spells
{
    SPELL_BERSERK                           = 26662,
    SPELL_FOCUSED_ANGER                     = 104543,
    SPELL_PSYCHIC_DRAIN                     = 104323,
    SPELL_PSYCHIC_DRAIN_DMG                 = 104322,
    SPELL_DISRUPTING_SHADOWS                = 103434,
    SPELL_DISRUPTING_SHADOWS_DMG            = 103948, // on dispel
    SPELL_VOID_OF_THE_UNMAKING_1            = 103521, // on void
    SPELL_VOID_OF_THE_UNMAKING_VISUAL       = 109187, // visual
    SPELL_VOID_OF_THE_UNMAKING_SUMMON_1     = 103571,
    SPELL_VOID_OF_THE_UNMAKING_SUMMON_2     = 110780, // ?
    SPELL_VOID_OF_THE_UNMAKING_PREVENT      = 103627,
    SPELL_VOID_OF_THE_UNMAKING_DUMMY_1      = 103946, // boss casts beam on void
    SPELL_VOID_DIFFUSION_DMG                = 103527,
    SPELL_VOID_DIFFUSION_BUFF               = 106836,
    SPELL_VOID_DIFFUSION_DEBUFF             = 104031, // debuf on boss
    SPELL_BLACK_BLOOD_ERUPTION              = 108799,
    SPELL_BLACK_BLOOD_ERUPTION_DMG          = 108794,
    SPELL_TANTRUM                           = 103953,
    SPELL_DARKNESS                          = 109413,
    SPELL_EYE_OF_GORATH                     = 109190,
    SPELL_CLAW_OF_GORATH                    = 109191,
    SPELL_FLAIL_OF_GORATH                   = 109193,

    SPELL_ZONOZZ_WHISPER_AGGRO              = 109874,
    SPELL_ZONOZZ_WHISPER_INTRO              = 109875,
    SPELL_ZONOZZ_WHISPER_DEATH              = 109876,
    SPELL_ZONOZZ_WHISPER_KILL               = 109877,
    SPELL_ZONOZZ_WHISPER_BLOOD              = 109878,
    SPELL_ZONOZZ_WHISPER_SHADOWS            = 109879,
    SPELL_ZONOZZ_WHISPER_VOID               = 109880,

    SPELL_BLOOD_OF_GORATH_DUMMY             = 103932,
    SPELL_BLACK_BLOOD_OF_GORATH             = 104377, // by tentacles
    SPELL_BLACK_BLOOD_OF_GORATH_25          = 110306,
    SPELL_BLACK_BLOOD_OF_GORATH_SELF        = 104378, // by boss

    SPELL_SLUDGE_SPEW                       = 110297,
    SPELL_WILD_FLAIL                        = 109199,

    SPELL_OOZE_SPIT                         = 109396,

    SPELL_SHADOW_GAZE                       = 104347,
    SPELL_SLUDHE_SPEW2                         = 110102,
};

enum Adds
{
    NPC_VOID_OF_THE_UNMAKING_1  = 55334,
    NPC_VOID_OF_THE_UNMAKING_2  = 58473, // ? second summon spell
    NPC_CLAW_OF_GORATH          = 55418,
    NPC_EYE_OF_GORATH           = 55416,
    NPC_FLAIL_OF_GORATH         = 55417,
};

enum Events
{
    EVENT_BERSERK               = 1,
    EVENT_FOCUSED_ANGER         = 2,
    EVENT_PSYCHIC_DRAIN         = 3,
    EVENT_DISRUPTING_SHADOWS    = 4,
    EVENT_VOID_OF_THE_UNMAKING  = 5,
    EVENT_CHECK_DISTANCE        = 6,
    EVENT_CONTINUE              = 7,
    EVENT_UPDATE_AURA           = 8,
    EVENT_TANTRUM_1             = 9,
    EVENT_TANTRUM_2             = 10,
    EVENT_TANTRUM_3             = 11,
    EVENT_END_TANTRUM_1         = 12,
    EVENT_END_TANTRUM_2         = 13,
    EVENT_SLUDGE_SPEW           = 14,
    EVENT_WILD_FLAIL            = 15,
    EVENT_OOZE_SPIT             = 16,
    EVENT_SHADOW_GAZE           = 17,
};

enum MiscData
{
    POINT_VOID          = 1,
    DATA_ACHIEVE        = 2,
    DATA_PHASE_COUNT    = 3,
    DATA_VOID           = 4,
};

const Position centerPos = {-1769.329956f, -1916.869995f, -226.28f, 0.0f};
const Position tentaclePos[14] =
{
    {-1702.57f, -1884.71f, -221.513f, 3.63029f},
    {-1801.84f, -1851.69f, -221.436f, 5.2709f},
    {-1792.2f, -1988.63f, -221.373f, 1.41372f},
    {-1834.55f, -1952.28f, -221.38f, 0.628318f},
    {-1734.35f, -1983.18f, -221.445f, 2.14675f},
    {-1745.46f, -1847.31f, -221.437f, 4.43314f},
    {-1839.37f, -1895.09f, -221.381f, 5.98648f},
    {-1696.95f, -1941.09f, -221.292f, 1.90241f},

    {-1739.246826f, -1885.623047f, -226.28f, 4.44f},
    {-1791.315552f, -1885.340820f, -226.06f, 4.94f},
    {-1801.412476f, -1939.772217f, -226.13f, 0.84f},
    {-1759.518921f, -1957.948853f, -226.00f, 1.67f},

    {-1774.998413f, -1937.956299f, -226.35f, 1.30f},
    {-1748.312256f, -1901.348877f, -226.17f, 3.87f}
};

Position posPlayer;

class boss_warlord_zonozz: public CreatureScript
{
    public:
        boss_warlord_zonozz() : CreatureScript("boss_warlord_zonozz") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new boss_warlord_zonozzAI(pCreature);
        }

        struct boss_warlord_zonozzAI : public BossAI
        {
            boss_warlord_zonozzAI(Creature* pCreature) : BossAI(pCreature, DATA_ZONOZZ)
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
                phaseCount = 0;
            }

            void InitializeAI() override
            {
                if (!instance || static_cast<InstanceMap*>(me->GetMap())->GetScriptId() != sObjectMgr->GetScriptIdOrAdd(DSScriptName))
                    me->IsAIEnabled = false;
                else if (!me->isDead())
                    Reset();
            }

            void Reset() override
            {
                _Reset();

                me->SetReactState(REACT_AGGRESSIVE);

                bAchieve = false;
                phaseCount = 0;
                instance->SetBossState(DATA_ZONOZZ, NOT_STARTED);
                instance->DoRemoveAurasDueToSpellOnPlayers(RAID_MODE(SPELL_BLACK_BLOOD_OF_GORATH, SPELL_BLACK_BLOOD_OF_GORATH_25));
            }

            void MoveInLineOfSight(Unit* who) override
            {
                if (!bIntro && me->GetDistance(who) <= 70.0f)
                {
                    bIntro = true;
                    Talk(SAY_INTRO);
                    //DoCastAOE(SPELL_ZONOZZ_WHISPER_INTRO, true);
                    Talk(SAY_INTRO_1);
                }

                BossAI::MoveInLineOfSight(who);
            }

            void EnterCombat(Unit* /*who*/) override
            {
                if (instance->GetBossState(DATA_MORCHOK) != DONE)
                {
                    EnterEvadeMode();
                    instance->DoNearTeleportPlayers(teleportPos[0]);
                    return;
                }

                bAchieve = false;
                phaseCount = 0;

                me->SetReactState(REACT_AGGRESSIVE);

                Talk(SAY_AGGRO);
                //DoCastAOE(SPELL_ZONOZZ_WHISPER_AGGRO, true);
                Talk(SAY_AGGRO_1);

                events.ScheduleEvent(EVENT_CHECK_DISTANCE, 5000);
                events.ScheduleEvent(EVENT_BERSERK, 6 * MINUTE * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_PSYCHIC_DRAIN, 13000);
                events.ScheduleEvent(EVENT_FOCUSED_ANGER, 10500);
                events.ScheduleEvent(EVENT_DISRUPTING_SHADOWS, urand(25000, 30000));
                events.ScheduleEvent(EVENT_VOID_OF_THE_UNMAKING, 5500);

                instance->DoRemoveAurasDueToSpellOnPlayers(RAID_MODE(SPELL_BLACK_BLOOD_OF_GORATH, SPELL_BLACK_BLOOD_OF_GORATH_25));

                DoZoneInCombat();
                instance->SetBossState(DATA_ZONOZZ, IN_PROGRESS);
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();

                Talk(SAY_DEATH);
                //DoCastAOE(SPELL_ZONOZZ_WHISPER_DEATH, true);
                Talk(SAY_DEATH_1);
                instance->SetBossState(DATA_ZONOZZ, DONE);
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
                    instance->DoRemoveAurasDueToSpellOnPlayers(RAID_MODE(SPELL_BLACK_BLOOD_OF_GORATH, SPELL_BLACK_BLOOD_OF_GORATH_25));
                }
            }

            void JustSummoned(Creature* summon) override
            {
                BossAI::JustSummoned(summon);

                switch (summon->GetEntry())
                {
                    case NPC_VOID_OF_THE_UNMAKING_1:
                        summon->SetOrientation(me->GetOrientation());
                        if (Unit* target = SelectTarget(SELECT_TARGET_FARTHEST, 0, 120.0f, true)) //Agrega estos
                            posPlayer = target->GetPosition(); //Agrega esto
                        DoCast(summon, SPELL_VOID_OF_THE_UNMAKING_DUMMY_1);
                        break;
                    case NPC_EYE_OF_GORATH:
                        if (!IsHeroic())
                            summon->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                        // no break
                    case NPC_CLAW_OF_GORATH:
                    case NPC_FLAIL_OF_GORATH:
                        if (IsHeroic())
                            DoCastAOE(SPELL_BLACK_BLOOD_OF_GORATH, true);
                        break;
                    default:
                        break;
                }
            }

            void SummonedCreatureDies(Creature* summon, Unit* killer) override
            {
                BossAI::SummonedCreatureDies(summon, killer);

                switch (summon->GetEntry())
                {
                    case NPC_VOID_OF_THE_UNMAKING_1:
                    case NPC_EYE_OF_GORATH:
                    case NPC_CLAW_OF_GORATH:
                    case NPC_FLAIL_OF_GORATH:
                        instance->DoRemoveAurasDueToSpellOnPlayers(RAID_MODE(SPELL_BLACK_BLOOD_OF_GORATH, SPELL_BLACK_BLOOD_OF_GORATH_25));
                        break;
                    default:
                        break;
                }
            }

            void SetData(uint32 type, uint32 data) override
            {
                if (type == DATA_ACHIEVE)
                    bAchieve = (bool)data;
                else if (type == DATA_VOID)
                {
                    me->CastCustomSpell(SPELL_VOID_DIFFUSION_DEBUFF, SPELLVALUE_AURA_STACK, data, me, true);
                    me->RemoveAura(SPELL_FOCUSED_ANGER);
                    events.CancelEvent(EVENT_DISRUPTING_SHADOWS);
                    events.CancelEvent(EVENT_PSYCHIC_DRAIN);
                    events.CancelEvent(EVENT_FOCUSED_ANGER);
                    events.CancelEvent(EVENT_VOID_OF_THE_UNMAKING);
                    events.ScheduleEvent(EVENT_TANTRUM_1, 1500);
                    phaseCount++;
                }
            }

            bool AllowAchieve()
            {
                return bAchieve;
            }

            uint32 GetData(uint32 type) const override
            {
                if (type == DATA_PHASE_COUNT)
                    return phaseCount;
                return 0;
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim && victim->GetTypeId() == TYPEID_PLAYER)
                {
                    Talk(SAY_KILL);
                    //DoCastAOE(SPELL_ZONOZZ_WHISPER_KILL, true);
                    Talk(SAY_KILL_1);
                }
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
                        case EVENT_CHECK_DISTANCE:
                            if (me->GetDistance(me->GetHomePosition()) > 150.0f)
                            {
                                events.Reset();
                                EnterEvadeMode();
                                return;
                            }
                            events.ScheduleEvent(EVENT_CHECK_DISTANCE, 5000);
                            break;
                        case EVENT_BERSERK:
                            DoCast(me, SPELL_BERSERK);
                            break;
                        case EVENT_FOCUSED_ANGER:
                            DoCast(me, SPELL_FOCUSED_ANGER);
                            events.ScheduleEvent(EVENT_FOCUSED_ANGER, 6500);
                            break;
                        case EVENT_PSYCHIC_DRAIN:
                            DoCastVictim(SPELL_PSYCHIC_DRAIN);
                            events.ScheduleEvent(EVENT_PSYCHIC_DRAIN, urand(20000, 25000));
                            break;
                        case EVENT_DISRUPTING_SHADOWS:
                            Talk(SAY_SHADOWS);
                            Talk(SAY_SHADOWS_1);
                            me->CastCustomSpell(SPELL_DISRUPTING_SHADOWS, SPELLVALUE_MAX_TARGETS, RAID_MODE(3, 8, 3, 8), me);
                            events.ScheduleEvent(EVENT_DISRUPTING_SHADOWS, urand(25000, 30000));
                            break;
                        case EVENT_VOID_OF_THE_UNMAKING:
                            summons.DespawnEntry(NPC_VOID_OF_THE_UNMAKING_1);
                            Talk(SAY_VOID);
                            Talk(SAY_VOID_1);
                            DoCast(me, SPELL_VOID_OF_THE_UNMAKING_SUMMON_1);
                            events.ScheduleEvent(EVENT_VOID_OF_THE_UNMAKING, 90300);
                            break;
                        case EVENT_TANTRUM_1:
                            me->SetReactState(REACT_PASSIVE);
                            me->AttackStop();
                            me->NearTeleportTo(centerPos.GetPositionX(), centerPos.GetPositionY(), centerPos.GetPositionZ(), centerPos.GetOrientation());
                            events.ScheduleEvent(EVENT_TANTRUM_2, 3000);
                            break;
                        case EVENT_TANTRUM_2:
                            Talk(SAY_BLOOD);
                            Talk(SAY_BLOOD_1);
                            DoCast(me, SPELL_DARKNESS, true);
                            if (!IsHeroic())
                                DoCast(me, SPELL_BLACK_BLOOD_OF_GORATH_SELF, true);
                            DoCast(me, SPELL_TANTRUM);
                            switch (GetDifficulty())
                            {
                                case DIFFICULTY_10_N:
                                    SpawnRandomTentacles(4, 0, 0);
                                    break;
                                case DIFFICULTY_25_N:
                                    SpawnRandomTentacles(8, 0, 0);
                                    break;
                                case DIFFICULTY_10_HC:
                                    SpawnRandomTentacles(4, 2, 1);
                                    break;
                                case DIFFICULTY_25_HC:
                                    SpawnRandomTentacles(8, 4, 2);
                                    break;
                                default:
                                    break;
                            }
                            events.ScheduleEvent(EVENT_END_TANTRUM_1, 11000);
                            events.ScheduleEvent(EVENT_END_TANTRUM_2, 30000);
                            break;
                        case EVENT_END_TANTRUM_1:
                            me->SetReactState(REACT_AGGRESSIVE);
                            AttackStart(me->GetVictim());
                            break;
                        case EVENT_END_TANTRUM_2:
                            if (!IsHeroic())
                                summons.DespawnEntry(NPC_EYE_OF_GORATH);
                            me->RemoveAura(SPELL_VOID_OF_THE_UNMAKING_PREVENT);
                            events.ScheduleEvent(EVENT_VOID_OF_THE_UNMAKING, urand(13000, 14000));
                            events.ScheduleEvent(EVENT_FOCUSED_ANGER, 6000);
                            events.ScheduleEvent(EVENT_DISRUPTING_SHADOWS, 6000);
                            events.ScheduleEvent(EVENT_PSYCHIC_DRAIN, 21000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            bool bIntro;
            bool bAchieve;
            uint32 phaseCount;

            void SpawnRandomTentacles(uint32 max_eyes, uint32 max_flails, uint32 max_claws)
            {
                if (max_eyes > 8)
                    max_eyes = 8;
                if (max_flails > 4)
                    max_flails = 4;
                if (max_claws > 2)
                    max_claws = 2;

                for (uint8 i = 0; i < max_eyes; ++i)
                    me->SummonCreature(NPC_EYE_OF_GORATH, tentaclePos[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);

                for (uint8 i = 8; i < (8 + max_flails); ++i)
                    me->SummonCreature(NPC_FLAIL_OF_GORATH, tentaclePos[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);

                for (uint8 i = 12; i < (12 + max_claws); ++i)
                    me->SummonCreature(NPC_CLAW_OF_GORATH, tentaclePos[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);
            }
        };
};


class npc_warlord_zonozz_void_of_the_unmaking : public CreatureScript
{
    public:
        npc_warlord_zonozz_void_of_the_unmaking() : CreatureScript("npc_warlord_zonozz_void_of_the_unmaking") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_warlord_zonozz_void_of_the_unmakingAI (pCreature);
        }

        struct npc_warlord_zonozz_void_of_the_unmakingAI : public Scripted_NoMovementAI
        {
            npc_warlord_zonozz_void_of_the_unmakingAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
            {
                me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                me->SetReactState(REACT_PASSIVE);
                me->SetCanFly(true);
            }

            void IsSummonedBy(Unit* /*owner*/) override
            {
                me->SetDisableGravity(true);
                targetPlayer = false;
                bAura = false;
                bExplode = false;
                targetPlayer = false;
                me->SetSpeed(MOVE_RUN, 0.6f);
                me->SetSpeed(MOVE_WALK, 0.6f);
                me->SetSpeed(MOVE_FLIGHT, 0.6f);
                events.ScheduleEvent(EVENT_CONTINUE, 5000);
            }

            void UpdateAI(uint32 const diff) override
            {

                if (!UpdateVictim())
                    return;

                if (!bExplode)
                {
                    if (centerPos.GetExactDist2d(me->GetPositionX(), me->GetPositionY()) > 95.0f)
                    {
                        bExplode = true;
                        events.Reset();
                        me->StopMoving();
                        DoCastAOE(SPELL_BLACK_BLOOD_ERUPTION);
                        me->DespawnOrUnsummon(500);
                        return;
                    }
                }

                if (targetBoss)
                {
                    if (Creature* pZonozz = me->FindNearestCreature(NPC_ZONOZZ, 2.0f))
                    {
                        uint8 stacks = 1;
                        if (Aura const* aur = me->GetAura(SPELL_VOID_DIFFUSION_BUFF))
                            stacks = aur->GetStackAmount();
                        targetBoss = false;
                        pZonozz->AI()->SetData(DATA_VOID, stacks);
                        events.Reset();
                        me->StopMoving();
                        me->DespawnOrUnsummon(500);
                        return;
                    }
                }

                if (bAura && !targetPlayer)
                {
                    if (me->SelectNearestPlayer(2.0f) != nullptr)
                    {
                        if (Aura const* aur = me->GetAura(SPELL_VOID_DIFFUSION_BUFF))
                        {
                            if (aur->GetStackAmount() >= 9)
                            if (Creature* pZonozz = pInstance->GetCreature(DATA_ZONOZZ))
                                pZonozz->AI()->SetData(DATA_ACHIEVE, 1);
                        }

                        me->RemoveAura(SPELL_VOID_OF_THE_UNMAKING_VISUAL);
                        bAura = false;
                        targetBoss = true;
                        targetPlayer = true;
                        DoCastAOE(SPELL_VOID_DIFFUSION_DMG);
                        me->StopMoving();
                        //float ang = me->GetAngle(pPlayer->GetPositionX(), pPlayer->GetPositionY());
                        if (Creature* pZonozz = pInstance->GetCreature(DATA_ZONOZZ))
                            posZonozz = pZonozz->GetPosition();
                        //if (me->NormalizeOrientation(me->GetOrientation() - ang) < (M_PI / 4.0f))
                            //ang = me->GetOrientation();
                       me->GetMotionMaster()->MovePoint(1, posZonozz);


                        //if (Creature* pZonozz = pInstance->GetCreature(DATA_ZONOZZ))
                        //_MovePosition(me->GetDistance(pZonozz), ang + M_PI);

                        events.ScheduleEvent(EVENT_UPDATE_AURA, 500);
                        events.ScheduleEvent(EVENT_CHECK_DISTANCE, 2000);
                    }
                }

                events.Update(diff);

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CONTINUE:
                        {
                            DoCast(me, SPELL_VOID_OF_THE_UNMAKING_VISUAL, true);
                            bAura = true;
                            //_MovePosition(200.0f, me->GetOrientation());
                            me->GetMotionMaster()->MovePoint(1, posPlayer);

                            //me->GetMotionMaster()->MovePoint(POINT_VOID, pos);
                            break;
                        }
                        case EVENT_CHECK_DISTANCE:
                        {
                          if (targetPlayer)
                           targetPlayer = false;
                        }
                            break;
                        case EVENT_UPDATE_AURA:
                            if (!me->HasAura(SPELL_VOID_OF_THE_UNMAKING_VISUAL))
                            {
                                DoCast(me, SPELL_VOID_OF_THE_UNMAKING_VISUAL, true);
                                bAura = true;
                            }
                            break;
                        default:
                            break;
                    }
                }
            }

        private:
            EventMap events;
            bool bAura;
            bool bExplode;
            bool targetBoss;
            bool targetPlayer;
            Position posZonozz;
            InstanceScript* pInstance = me->GetInstanceScript();

            void _MovePosition(float dist, float angle)
            {
                angle = me->NormalizeOrientation(angle);

                float cur_dist = 5.0f;
                Movement::MoveSplineInit init(me);
                bool bPassed = false;

                while (!bPassed)
                {
                    float x = me->GetPositionX() + (cur_dist * std::cos(angle));
                    float y = me->GetPositionY() + (cur_dist * std::sin(angle));
                    float z = me->GetPositionZ();
                    float center_dist = centerPos.GetExactDist2d(x, y);
                    if (center_dist > 100.0f || cur_dist > dist)
                        bPassed = true;
                    else
                    {
                        G3D::Vector3 point;
                        point.x = x;
                        point.y = y;
                        if (center_dist > 40.0f)
                            z = -225.0f + ((center_dist - 40.0f) * 0.1333f);
                        else
                            z = -225.0f;

                        point.z =  z;
                        init.Path().push_back(point);
                        cur_dist += 5.0f;
                    }
                }

                if (!init.Path().empty())
                {
                    init.SetWalk(false);
                    init.Launch();
                }
            }
        };
};

/* Npc ID 55417 */
class npc_scourge_of_gorath : public CreatureScript
{
public:
    npc_scourge_of_gorath() : CreatureScript("npc_scourge_of_gorath") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_scourge_of_gorathAI(creature);
    }

    struct npc_scourge_of_gorathAI : public ScriptedAI
    {
        npc_scourge_of_gorathAI(Creature* creature) : ScriptedAI(creature)
        {
            me->AddUnitFlag(UNIT_FLAG_REMOVE_CLIENT_CONTROL);
            me->AddUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
        }

        EventMap events;

        void Reset() override
        {
            events.Reset();
            me->AddUnitFlag(UNIT_FLAG_REMOVE_CLIENT_CONTROL);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_SLUDGE_SPEW, 5000);
            events.ScheduleEvent(EVENT_WILD_FLAIL, urand(1500, 15000));
        }

        void UpdateAI(uint32 const diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_SLUDGE_SPEW:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                        DoCast(target, SPELL_SLUDHE_SPEW2);
                    events.ScheduleEvent(EVENT_SHADOW_GAZE, urand(5000, 15000));
                    break;
                case EVENT_WILD_FLAIL:
                    DoCast(SPELL_WILD_FLAIL);
                    events.ScheduleEvent(EVENT_WILD_FLAIL, urand(2500, 7500));
                    break;
                }
            }
        }
    };
};


/*NPC ID 55416*/
class npc_eye_of_gorath : public CreatureScript
{
public:
    npc_eye_of_gorath() : CreatureScript("npc_eye_of_gorath") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_eye_of_gorathAI(creature);
    }

    struct npc_eye_of_gorathAI : public ScriptedAI
    {
        npc_eye_of_gorathAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_SHADOW_GAZE, 1000);
            me->AddUnitFlag(UNIT_FLAG_REMOVE_CLIENT_CONTROL);
            me->AddUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
        }

        void UpdateAI(uint32 const diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_SHADOW_GAZE:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                        DoCast(target, SPELL_SHADOW_GAZE, false);
                    events.ScheduleEvent(EVENT_SHADOW_GAZE, 3100);
                    break;
                }
            }
        }
    };
};

class npc_warlord_zonozz_tentacle : public CreatureScript
{
    public:
        npc_warlord_zonozz_tentacle() : CreatureScript("npc_warlord_zonozz_tentacle") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_warlord_zonozz_tentacleAI (pCreature);
        }

        struct npc_warlord_zonozz_tentacleAI : public Scripted_NoMovementAI
        {
            npc_warlord_zonozz_tentacleAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
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
            }

            void Reset() override
            {
                events.Reset();
                me->AddUnitFlag(UNIT_FLAG_REMOVE_CLIENT_CONTROL);
                me->AddUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
            }

            void EnterCombat(Unit* /*who*/) override
            {
                switch (me->GetEntry())
                {
                    case NPC_FLAIL_OF_GORATH:
                        events.ScheduleEvent(EVENT_SLUDGE_SPEW, urand(10000, 15000));
                        events.ScheduleEvent(EVENT_WILD_FLAIL, 15000);
                        break;
                    case NPC_CLAW_OF_GORATH:
                        events.ScheduleEvent(EVENT_OOZE_SPIT, 8000);
                        break;
                    case NPC_EYE_OF_GORATH:
                        events.ScheduleEvent(EVENT_SHADOW_GAZE, urand(3000, 15000));
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 const diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SLUDGE_SPEW:
                            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                                DoCast(pTarget, SPELL_SLUDGE_SPEW);
                            events.ScheduleEvent(EVENT_SLUDGE_SPEW, urand(12000, 20000));
                            break;
                        case EVENT_WILD_FLAIL:
                            DoCastAOE(SPELL_WILD_FLAIL);
                            events.ScheduleEvent(EVENT_WILD_FLAIL, urand(7000, 10000));
                            break;
                        case EVENT_OOZE_SPIT:
                            if (!me->IsWithinMeleeRange(me->GetVictim()))
                                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                                    DoCast(pTarget, SPELL_OOZE_SPIT);
                            events.ScheduleEvent(EVENT_OOZE_SPIT, 6000);
                            break;
                        case EVENT_SHADOW_GAZE:
                            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true, -int32((SPELL_SHADOW_GAZE))))
                                DoCast(pTarget, SPELL_SHADOW_GAZE);
                            events.ScheduleEvent(EVENT_SHADOW_GAZE, urand(8000, 15000));
                            break;
                        default:
                            break;
                    }
                }

                if (me->GetEntry() != NPC_EYE_OF_GORATH)
                    DoMeleeAttackIfReady();
            }

        private:
            EventMap events;
        };
};

class spell_warlord_zonozz_disrupting_shadows : public SpellScriptLoader
{
    public:
        spell_warlord_zonozz_disrupting_shadows() : SpellScriptLoader("spell_warlord_zonozz_disrupting_shadows") { }

        class spell_warlord_zonozz_disrupting_shadows_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_warlord_zonozz_disrupting_shadows_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (!GetCaster())
                    return;

                if (targets.size() <= 1)
                    return;

                if (Creature* pZonozz = GetCaster()->ToCreature())
                    if (Unit* pTank = pZonozz->GetVictim())
                        targets.remove(pTank);

                uint32 max_targets = (GetCaster()->GetMap()->Is25ManRaid() ? 5 : 2);
                Trinity::Containers::RandomResize(targets, max_targets);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_warlord_zonozz_disrupting_shadows_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_warlord_zonozz_disrupting_shadows_SpellScript();
        }
};

//Void Diffusion Damage 103527
class spell_warlord_zonozz_void_diffusion_dmg : public SpellScriptLoader
{
public:
    spell_warlord_zonozz_void_diffusion_dmg() : SpellScriptLoader("spell_warlord_zonozz_void_diffusion_dmg") { }

    class spell_warlord_zonozz_void_diffusion_dmg_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_warlord_zonozz_void_diffusion_dmg_SpellScript);

        bool Load() override
        {
            _targetCount = 0;

            return true;
        }

        void CountTargets(std::list<WorldObject*>& targets)
        {
            _targetCount = targets.size();
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            PreventHitDamage();

            if (!GetCaster())
                return;

            if (!GetHitUnit()->IsAlive() || !_targetCount)
                return;

            if (Creature* creature = GetCaster()->ToCreature())
            {
                if (Unit* target = GetHitUnit())
                {
                    if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(SPELL_VOID_DIFFUSION_DMG))
                    {
                        uint32 damage = (uint32(GetEffectValue()/_targetCount));
                        SpellNonMeleeDamage damageInfo(creature, target, SPELL_VOID_DIFFUSION_DMG, spellInfo->GetSpellXSpellVisualId(), spellInfo->SchoolMask);
                        damageInfo.damage = damage;
                        creature->SendSpellNonMeleeDamageLog(&damageInfo);
                        creature->DealSpellDamage(&damageInfo, false);
                    }
                }
            }
        }

        uint32 _targetCount;

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_warlord_zonozz_void_diffusion_dmg_SpellScript::CountTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            OnEffectHitTarget += SpellEffectFn(spell_warlord_zonozz_void_diffusion_dmg_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_warlord_zonozz_void_diffusion_dmg_SpellScript();
    }
};

//Disrupting Shadows Damage 103948
class spell_warlord_zonozz_disrupting_shadows_dmg : public SpellScriptLoader
{
public:
    spell_warlord_zonozz_disrupting_shadows_dmg() : SpellScriptLoader("spell_warlord_zonozz_disrupting_shadows_dmg") { }

    class spell_warlord_zonozz_disrupting_shadows_dmg_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_warlord_zonozz_disrupting_shadows_dmg_SpellScript);

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            PreventHitDamage();

            if (!GetHitUnit()->IsAlive() || !GetCaster())
                return;

            if (Player* player = GetCaster()->ToPlayer())
            {
                if (Unit* target = GetHitUnit())
                {
                    if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(SPELL_DISRUPTING_SHADOWS_DMG))
                    {
                        uint32 damage = (uint32(GetEffectValue()));
                        SpellNonMeleeDamage damageInfo(player, target, SPELL_DISRUPTING_SHADOWS_DMG, spellInfo->GetSpellXSpellVisualId(), spellInfo->SchoolMask);
                        damageInfo.damage = damage;
                        player->SendSpellNonMeleeDamageLog(&damageInfo);
                        player->DealSpellDamage(&damageInfo, false);
                    }
                }
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_warlord_zonozz_disrupting_shadows_dmg_SpellScript::HandleDummy, EFFECT_1, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_warlord_zonozz_disrupting_shadows_dmg_SpellScript();
    }
};

//Disrupting Shadows Aura 103434
class spell_warlord_zonozz_disrupting_shadows_aura : public SpellScriptLoader
{
public:
    spell_warlord_zonozz_disrupting_shadows_aura() : SpellScriptLoader("spell_warlord_zonozz_disrupting_shadows_aura") { }

    class spell_warlord_zonozz_disrupting_shadows_aura_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_warlord_zonozz_disrupting_shadows_aura_AuraScript);

        void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* owner = GetUnitOwner())
            {
                AuraRemoveMode removeMode = GetTargetApplication()->GetRemoveMode();
                if (removeMode == AURA_REMOVE_BY_ENEMY_SPELL)
                    owner->CastSpell(owner, SPELL_DISRUPTING_SHADOWS_DMG, true);
            }
        }

        void Register() override
        {
            AfterEffectRemove += AuraEffectRemoveFn(spell_warlord_zonozz_disrupting_shadows_aura_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_warlord_zonozz_disrupting_shadows_aura_AuraScript();
    }
};

typedef boss_warlord_zonozz::boss_warlord_zonozzAI ZonozzAI;

class achievement_ping_pong_champion : public AchievementCriteriaScript
{
    public:
        achievement_ping_pong_champion() : AchievementCriteriaScript("achievement_ping_pong_champion") { }

        bool OnCheck(Player* /*source*/, Unit* target) override
        {
            if (!target)
                return false;

            if (ZonozzAI* zonozzAI = CAST_AI(ZonozzAI, target->GetAI()))
                return zonozzAI->AllowAchieve();

            return false;
        }
};

void AddSC_boss_warlord_zonozz()
{
    new boss_warlord_zonozz();
    new npc_warlord_zonozz_void_of_the_unmaking();
    new npc_warlord_zonozz_tentacle();
    new npc_eye_of_gorath();
    new npc_scourge_of_gorath();
    new spell_warlord_zonozz_disrupting_shadows();
    new spell_warlord_zonozz_void_diffusion_dmg();
    new spell_warlord_zonozz_disrupting_shadows_dmg();
    new spell_warlord_zonozz_disrupting_shadows_aura();
    new achievement_ping_pong_champion();
}
