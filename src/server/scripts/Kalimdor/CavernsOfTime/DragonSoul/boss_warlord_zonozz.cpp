/*
 *
 * Copyright (C) 2008-2014 Forgotten Lands <http://www.forgottenlands.eu/>
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

/*
##### Script Info #####
Author: Bennu
Progress: 100%
Website: www.forgottenlands.eu
*/

#include "ScriptMgr.h"
#include "CreatureTextMgr.h"
#include "ScriptedCreature.h"
#include "dragon_soul.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"

enum ScriptedTexts
{
    SAY_AGGRO       = 0,
    SAY_DEATH       = 1,
    SAY_INTRO       = 2,
    SAY_KILL        = 3,
    SAY_PHASE       = 4,
    SAY_SHADOW      = 5,
    SAY_VOID        = 6,
    SAY_AGGRO_1     = 7,
    SAY_DEATH_1     = 8,
    SAY_INTRO_1     = 9,
    SAY_KILL_1      = 10,
    SAY_PHASE_1     = 11,
    SAY_SHADOW_1    = 12,
    SAY_VOID_1      = 13,
};

enum Events
{
    //Zon'Ozz
    EVENT_FOCUSED_ANGER = 1,
    EVENT_PSYCHIC_DRAIN,
    EVENT_DISRUPTING_SHADOWS,
    EVENT_VOID_OF_THE_UNMAKING,
    EVENT_BLACK_PHASE,
    EVENT_PING_PONG,
    EVENT_SUMMON_TENTACLES,
    EVENT_BERSERK,

    //Void of the unmaking
    EVENT_PING,
    EVENT_PONG,
    EVENT_ROTATE,

    // Eyes of Go'rath
    EVENT_SHADOW_GAZE,

    // Flail of Go'rath
    EVENT_SLUDGE_SPEW,
    EVENT_WILD_FLAIL,

    // Claw of Go'rath
    EVENT_MELEE_CHECK,
};

enum Spells
{
    //Zon'Ozz
    SPELL_FOCUSED_ANGER                = 104543,
    SPELL_PSYCHIC_DRAIN                = 104322,
    SPELL_DISRUPTING_SHADOWS           = 103434,
    SPELL_DISRUPTING_SHADOWS_DISPEL    = 103948,
    SPELL_VOID_OF_THE_UNMAKING         = 103946,
    SPELL_VOID_OF_THE_UNMAKING_SUMMON  = 103571,
    SPELL_VOID_OF_THE_UNMAKING_DUMMY   = 105336,
    SPELL_BLACK_BLOOD                  = 104378,
    SPELL_BLACK_BLOOD_ADD              = 104377,
    SPELL_DARKNESS                     = 109413,
    SPELL_BERSERK                      = 26662,

    //Void of the unmaking
    SPELL_VOID_DIFFUSION               = 103527,
    SPELL_DIFFUSION_STACK              = 106836,
    SPELL_VOID_DIFFUSION_DMG           = 104031,
    SPELL_VOID_OF_THE_UNMAKING_VISUAL  = 103521,
    SPELL_BLACK_BLOOD_ERUPTION         = 108799,

    // Eyes of Go'rath
    SPELL_SHADOW_GAZE                  = 104347,

    // Flail of Go'rath
    SPELL_SLUDGE_SPEW                  = 110102,
    SPELL_WILD_FLAIL                   = 109199,

    // Claw of Go'rath
    SPELL_OOZE_SPIT                    = 109396,

    //Zon'Ozz whispers
    SPELL_ZONOZZ_WHISPER_AGGRO         = 109874,
    SPELL_ZONOZZ_WHISPER_DEATH         = 109876,
    SPELL_ZONOZZ_WHISPER_INTRO         = 109875,
    SPELL_ZONOZZ_WHISPER_KILL          = 109877,
    SPELL_ZONOZZ_WHISPER_PHASE         = 109878,
    SPELL_ZONOZZ_WHISPER_VOID          = 109880,
    SPELL_ZONOZZ_WHISPER_SHADOWS       = 109879,
};

const Position eyesPos[] =
{
    { -1734.349f, -1983.180f, -221.445f, 2.146f },
    { -1792.199f, -1988.630f, -221.373f, 1.413f },
    { -1834.550f, -1952.280f, -221.380f, 0.628f },
    { -1839.369f, -1895.089f, -221.380f, 5.986f },
    { -1801.839f, -1851.689f, -221.436f, 5.270f },
    { -1745.459f, -1847.310f, -221.436f, 4.433f },
    { -1702.569f, -1884.709f, -221.513f, 3.630f },
    { -1696.037f, -1940.584f, -221.291f, 2.839f },
};

const Position flailPos[] =
{
    { -1795.286f, -1963.363f, -224.926f, 1.079f },
    { -1746.292f, -1871.796f, -224.930f, 4.236f },
    { -1813.624f, -1900.537f, -224.985f, 5.909f },
    { -1719.928f, -1929.560f, -225.278f, 2.838f },
};

const Position clawPos[] =
{
    { -1819.530f, -1923.639f, -225.671f, 0.129f },
    { -1714.399f, -1913.100f, -225.555f, 3.196f },
};

const Position centerPos = { -1769.329f, -1916.869f, -226.270f, 1.291f };

class boss_warlord_zonozz : public CreatureScript
{
public:
    boss_warlord_zonozz() : CreatureScript("boss_warlord_zonozz") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_warlord_zonozzAI(pCreature);
    }

    struct boss_warlord_zonozzAI: public BossAI
    {
        boss_warlord_zonozzAI(Creature* creature) : BossAI(creature, NPC_ZONOZZ)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;
        int32 eye;
        int32 flail;
        int32 claw;
        bool bIntro;
        bool bAchieve;

        void InitializeAI() override
        {
            if (instance->GetBossState(DATA_MORCHOK) == NOT_STARTED)
                me->SetVisible(false);
        }

        void Reset() override
        {
            _Reset();

            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            events.Reset();
            me->RemoveAura(SPELL_FOCUSED_ANGER);

            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_BLACK_BLOOD_ADD);
            instance->SetBossState(DATA_ZONOZZ, NOT_STARTED);
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (!bIntro && me->GetDistance(who) <= 70.0f)
            {
                bIntro = true;
                Talk(SAY_INTRO);
                DoCastAOE(SPELL_ZONOZZ_WHISPER_INTRO, true);
            }

            BossAI::MoveInLineOfSight(who);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();
            Talk(SAY_AGGRO);
            DoCastAOE(SPELL_ZONOZZ_WHISPER_AGGRO, true);

            events.ScheduleEvent(EVENT_BERSERK, 360000);
            events.ScheduleEvent(EVENT_PING_PONG, 1000);
            events.ScheduleEvent(EVENT_VOID_OF_THE_UNMAKING, 4000);

            DoZoneInCombat();
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
            instance->SetBossState(DATA_ZONOZZ, IN_PROGRESS);
        }

        void SpellHit(Unit* /*who*/, const SpellInfo* spellInfo) override
        {
            if (spellInfo->Id == SPELL_VOID_DIFFUSION_DMG) // When the ball hits the boss he will trigger the black phase
            {
                events.CancelEvent(EVENT_FOCUSED_ANGER);
                events.ScheduleEvent(EVENT_BLACK_PHASE, 5000);
            }
        }

        void KilledUnit(Unit* victim) override
        {
            if (victim && victim->GetTypeId() == TYPEID_PLAYER)
            {
                Talk(SAY_KILL);
                DoCastAOE(SPELL_ZONOZZ_WHISPER_KILL, true);
            }
        }

        void UpdateAI(uint32 diff) override

        {
            if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_PING_PONG:
                    Talk(SAY_PHASE);
                    DoCastAOE(SPELL_ZONOZZ_WHISPER_PHASE, true);

                    if (!IsHeroic())
                        summons.DespawnAll();

                    events.ScheduleEvent(EVENT_FOCUSED_ANGER, 5000);
                    events.ScheduleEvent(EVENT_PSYCHIC_DRAIN, 8000);
                    events.ScheduleEvent(EVENT_DISRUPTING_SHADOWS, 19000);

                    instance->SetBossState(NPC_ZONOZZ, IN_PROGRESS);
                    break;

                case EVENT_FOCUSED_ANGER:
                    DoCast(me, SPELL_FOCUSED_ANGER);
                    events.ScheduleEvent(EVENT_FOCUSED_ANGER, 6000);
                    break;

                case EVENT_PSYCHIC_DRAIN:
                    DoCastVictim(SPELL_PSYCHIC_DRAIN);
                    events.ScheduleEvent(EVENT_PSYCHIC_DRAIN, 20000);
                    break;

                case EVENT_DISRUPTING_SHADOWS:
                    if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                       DoCast(target, SPELL_DISRUPTING_SHADOWS);
                    events.ScheduleEvent(EVENT_DISRUPTING_SHADOWS, 25000);
                    break;

                case EVENT_VOID_OF_THE_UNMAKING:
                    Talk(SAY_VOID);
                    DoCastAOE(SPELL_ZONOZZ_WHISPER_VOID, true);

                    DoCast(me, SPELL_VOID_OF_THE_UNMAKING_SUMMON);
                    if (Creature* ball = me->FindNearestCreature(NPC_VOID_OF_THE_UNMAKING, 100.0f, true))
                        DoCast(ball, SPELL_VOID_OF_THE_UNMAKING);

                    events.ScheduleEvent(EVENT_VOID_OF_THE_UNMAKING, 90000);
                    break;
                case EVENT_BLACK_PHASE:
                    if (Aura* voidDiffusion = me->GetAura(SPELL_VOID_DIFFUSION_DMG))
                        if (voidDiffusion->GetStackAmount() >= 10)
                            bAchieve = true;

                    Talk(SAY_SHADOW);
                    DoCastAOE(SPELL_ZONOZZ_WHISPER_SHADOWS, true);

                    me->GetMotionMaster()->MovePoint(0, centerPos);
                    me->AttackStop();
                    DoCast(me, SPELL_DARKNESS);

                    if (!IsHeroic())
                        DoCast(me, SPELL_BLACK_BLOOD);

                    events.ScheduleEvent(EVENT_SUMMON_TENTACLES, 1000);
                    events.ScheduleEvent(EVENT_PING_PONG, 30000); // Ping-pong phase restart

                    events.CancelEvent(EVENT_PSYCHIC_DRAIN);
                    events.CancelEvent(EVENT_DISRUPTING_SHADOWS);
                    break;

                case EVENT_SUMMON_TENTACLES:
                    if (GetDifficulty() == DIFFICULTY_25_N || GetDifficulty() == DIFFICULTY_25_HC)
                    {
                        eye = 7;
                        flail = 3;
                        claw = 1;
                    }
                    else
                    {
                        eye = 4;
                        flail = 1;
                        claw = 0;
                    }

                    for (int32 x = 0; x <= eye; ++x)
                        if (Creature* eye = me->SummonCreature(NPC_EYE_OF_GORATH, eyesPos[x], TEMPSUMMON_MANUAL_DESPAWN))
                            if (IsHeroic())
                                eye->CastSpell(eye, SPELL_BLACK_BLOOD_ADD);

                    if (IsHeroic())
                    {
                        for (int32 x = 0; x <= flail; ++x)
                            if (Creature* flail = me->SummonCreature(NPC_FLAIL_OF_GORATH, flailPos[x], TEMPSUMMON_MANUAL_DESPAWN))
                                flail->CastSpell(flail, SPELL_BLACK_BLOOD_ADD);

                        for (int32 x = 0; x <= claw; ++x)
                            if (Creature* claw = me->SummonCreature(NPC_CLAW_OF_GORATH, clawPos[x], TEMPSUMMON_MANUAL_DESPAWN))
                                claw->CastSpell(claw, SPELL_BLACK_BLOOD_ADD);
                    }
                    break;

                case EVENT_BERSERK:
                    DoCast(me, SPELL_BERSERK);
                    break;
                default:
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }


        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();

            Talk(SAY_DEATH);
            DoCastAOE(SPELL_ZONOZZ_WHISPER_DEATH, true);

            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            instance->SetBossState(DATA_ZONOZZ, DONE);

            if (bAchieve == true)
            {
                Map::PlayerList const& PlayerList = instance->instance->GetPlayers();
                for (Map::PlayerList::const_iterator itr = PlayerList.begin(); itr != PlayerList.end(); ++itr)
                {
                    if (Player* player = itr->GetSource())
                    {
                        player->CompletedAchievement(6128);
                    }
                }
            }
        }
    };
};

class npc_void_of_the_unmaking : public CreatureScript
{
public:
    npc_void_of_the_unmaking() : CreatureScript("npc_void_of_the_unmaking") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_void_of_the_unmakingAI(pCreature);
    }

    struct npc_void_of_the_unmakingAI : public ScriptedAI
    {
        npc_void_of_the_unmakingAI(Creature* pCreature) : ScriptedAI(pCreature)
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
            me->SetReactState(REACT_PASSIVE);
        }

        void Reset() override
        {
            events.Reset();
        }

        void IsSummonedBy(Unit* /*owner*/) override
        {
            dir = me->GetOrientation();
            DoCast(me, SPELL_VOID_OF_THE_UNMAKING_VISUAL);
        }

        void SpellHit(Unit* /*who*/, const SpellInfo* spellInfo) override
        {
            if (spellInfo->Id == SPELL_VOID_OF_THE_UNMAKING_VISUAL)
            {
                me->SetDisplayId(39108);
                events.ScheduleEvent(EVENT_PING, 3000);
                events.ScheduleEvent(EVENT_PONG, 1000);
            }
        }

        void UpdateAI(uint32 diff) override

        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_PING:
                    {
                        float X = me->GetPositionX()+ 100 * cos(dir);
                        float Y = me->GetPositionY()+ 100 * sin(dir);
                        DoCast(me, SPELL_VOID_OF_THE_UNMAKING_DUMMY);
                        me->SetSpeed(MOVE_WALK, 0.8f);
                        me->SetSpeed(MOVE_RUN, 0.8f);
                        me->GetMotionMaster()->MovePoint(0, X, Y, me->GetPositionZ());
                        events.ScheduleEvent(EVENT_PING, 500);
                    }
                    break;

                case EVENT_PONG:
                    if (Unit* target = SelectTarget(SELECT_TARGET_NEAREST, 0, 3.0f, true))
                    {
                        ori = me->GetOrientation();
                        me->StopMoving();
                        DoCast(me, SPELL_VOID_DIFFUSION);
                        me->GetMotionMaster()->Clear();

                        events.CancelEvent(EVENT_PING);
                        events.ScheduleEvent(EVENT_PING, 200);
                        events.ScheduleEvent(EVENT_PONG, 2000);
                        events.ScheduleEvent(EVENT_ROTATE, 100);
                    }
                    else if (Creature* zonozz = me->FindNearestCreature(NPC_ZONOZZ, 5.0f, true))
                    {
                        DoCast(zonozz, SPELL_VOID_DIFFUSION_DMG);
                        me->DespawnOrUnsummon();
                    }
                    else if (me->GetExactDist2d(centerPos.GetPositionX(), centerPos.GetPositionY()) > 115.0f)
                    {
                        events.CancelEvent(EVENT_PONG);
                        DoCast(me, SPELL_BLACK_BLOOD_ERUPTION);
                        me->DespawnOrUnsummon(5000);
                    }
                    else
                        events.ScheduleEvent(EVENT_PONG, 800);
                    break;

                case EVENT_ROTATE:
                    dir = ori + float(M_PI);
                    if (dir >= 2 * float(M_PI))
                        dir-= 2 * float(M_PI);
                    events.ScheduleEvent(EVENT_ROTATE, 100);
                    break;
                default:
                    break;
                }
            }
        }
    private:
        EventMap events;
        float ori;
        float dir;
    };
};

class npc_eye_of_gorath : public CreatureScript
{
public:
    npc_eye_of_gorath() : CreatureScript("npc_eye_of_gorath") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_eye_of_gorathAI(pCreature);
    }

    struct npc_eye_of_gorathAI : public Scripted_NoMovementAI
    {
        npc_eye_of_gorathAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
        {
            instance = pCreature->GetInstanceScript();
        }

        EventMap events;
        InstanceScript* instance;
        uint32 amount;

        void Reset() override
        {
            events.Reset();
        }

        void IsSummonedBy(Unit* /*owner*/) override
        {
            me->SetReactState(REACT_AGGRESSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL);

            if (!IsHeroic())
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);

            events.ScheduleEvent(EVENT_SHADOW_GAZE, 3000);
        }

        void JustDied(Unit* /*killer*/) override
        {
            std::list<Player*> targets;
            me->GetPlayerListInGrid(targets, 500.0f);

            for (std::list<Player*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
            {
                if (Aura* blood = (*itr)->GetAura(SPELL_BLACK_BLOOD_ADD))
                    amount = blood->GetStackAmount();

                if (amount == 1)
                    (*itr)->RemoveAura(SPELL_BLACK_BLOOD_ADD);
                else
                    (*itr)->SetAuraStack(SPELL_BLACK_BLOOD_ADD, (*itr), amount - 1);
            }
        }

        void UpdateAI(uint32 diff) override

        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_SHADOW_GAZE:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 200.0f, true))
                        DoCast(target, SPELL_SHADOW_GAZE);

                    events.ScheduleEvent(EVENT_SHADOW_GAZE, urand(3000, 4000));
                    break;
                default:
                    break;
                }
            }
        }
    };
};

class npc_flail_of_gorath : public CreatureScript
{
public:
    npc_flail_of_gorath() : CreatureScript("npc_flail_of_gorath") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_flail_of_gorathAI(pCreature);
    }

    struct npc_flail_of_gorathAI : public Scripted_NoMovementAI
    {
        npc_flail_of_gorathAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
        {
            instance = pCreature->GetInstanceScript();
        }

        EventMap events;
        InstanceScript* instance;
        uint32 amount;

        void Reset() override
        {
            events.Reset();
        }

        void IsSummonedBy(Unit* /*owner*/) override
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL);
            events.ScheduleEvent(EVENT_SLUDGE_SPEW, 6000);
            events.ScheduleEvent(EVENT_WILD_FLAIL, 5000);
        }

        void JustDied(Unit* /*killer*/) override
        {
            std::list<Player*> targets;
            me->GetPlayerListInGrid(targets, 500.0f);

            for (std::list<Player*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
            {
                if (Aura* blood = (*itr)->GetAura(SPELL_BLACK_BLOOD_ADD))
                    amount = blood->GetStackAmount();

                if (amount == 1)
                    (*itr)->RemoveAura(SPELL_BLACK_BLOOD_ADD);
                else
                    (*itr)->SetAuraStack(SPELL_BLACK_BLOOD_ADD, (*itr), amount - 1);
            }
        }

        void UpdateAI(uint32 diff) override

        {

            events.Update(diff);

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_SLUDGE_SPEW:
                    DoCastVictim(SPELL_SLUDGE_SPEW);

                    events.ScheduleEvent(EVENT_SLUDGE_SPEW, 6000);
                    break;

                case EVENT_WILD_FLAIL:
                    DoCast(me, SPELL_WILD_FLAIL);

                    events.ScheduleEvent(EVENT_WILD_FLAIL, 5000);
                    break;
                default:
                    break;
                }
            }
        }
    };
};

class npc_claw_of_gorath : public CreatureScript
{
public:
    npc_claw_of_gorath() : CreatureScript("npc_claw_of_gorath") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_claw_of_gorathAI(pCreature);
    }

    struct npc_claw_of_gorathAI : public Scripted_NoMovementAI
    {
        npc_claw_of_gorathAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
        {
            instance = pCreature->GetInstanceScript();
        }

        EventMap events;
        InstanceScript* instance;
        uint32 amount;

        void Reset() override
        {
            events.Reset();
        }

        void JustDied(Unit* /*killer*/) override
        {
            std::list<Player*> targets;
            me->GetPlayerListInGrid(targets, 500.0f);

            for (std::list<Player*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
            {
                if (Aura* blood = (*itr)->GetAura(SPELL_BLACK_BLOOD_ADD))
                    amount = blood->GetStackAmount();

                if (amount == 1)
                    (*itr)->RemoveAura(SPELL_BLACK_BLOOD_ADD);
                else
                    (*itr)->SetAuraStack(SPELL_BLACK_BLOOD_ADD, (*itr), amount - 1);
            }
        }

        void IsSummonedBy(Unit* /*owner*/) override
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL);
            events.ScheduleEvent(EVENT_MELEE_CHECK, 5000);
        }

        void UpdateAI(uint32 diff) override

        {

            events.Update(diff);

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_MELEE_CHECK:
                    if (me->IsWithinMeleeRange(me->GetVictim()))
                        events.ScheduleEvent(EVENT_MELEE_CHECK, 1000);
                    else
                    {
                        DoCastVictim(SPELL_OOZE_SPIT);
                        events.ScheduleEvent(EVENT_MELEE_CHECK, 2000);
                    }
                    break;
                default:
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

class spell_void_diffusion : public SpellScriptLoader
{
public:
    spell_void_diffusion() : SpellScriptLoader("spell_void_diffusion") { }

    class spell_void_diffusion_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_void_diffusion_SpellScript);

        void HandleScript(SpellEffIndex /*effIndex*/)
        {
            if (!GetCaster() || !GetHitUnit())
                return;

            if(Unit* caster = GetCaster())
            {
                if (Unit* target = GetHitUnit())
                {
                    if (Aura* diffusion = caster->GetAura(SPELL_DIFFUSION_STACK))
                        diffstack = diffusion->GetStackAmount();

                    if (Aura* dmg = target->GetAura(SPELL_VOID_DIFFUSION_DMG))
                        dmgstack = dmg->GetStackAmount();

                    totalstack = diffstack + dmgstack - 1;
                    target->SetAuraStack(SPELL_VOID_DIFFUSION_DMG, target, totalstack);
                }
            }
        }
    private:
        uint32 diffstack;
        uint32 dmgstack;
        uint32 totalstack;

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_void_diffusion_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_void_diffusion_SpellScript();
    }
};

class spell_zonozz_whisper : public SpellScriptLoader
{
public:
    spell_zonozz_whisper() : SpellScriptLoader("spell_zonozz_whisper") { }

    class spell_zonozz_whisper_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_zonozz_whisper_SpellScript);

        void HandleScript(SpellEffIndex /*effIndex*/)
        {
            if (!GetCaster() || !GetHitUnit())
                return;

            if (!GetCaster()->ToCreature() || !GetHitUnit()->ToPlayer())
                return;

            uint32 textId = 0;

            switch (GetSpellInfo()->Id)
            {
            case SPELL_ZONOZZ_WHISPER_AGGRO:   textId = SAY_AGGRO_1; break;
            case SPELL_ZONOZZ_WHISPER_DEATH:   textId = SAY_DEATH_1; break;
            case SPELL_ZONOZZ_WHISPER_INTRO:   textId = SAY_INTRO_1; break;
            case SPELL_ZONOZZ_WHISPER_KILL:    textId = SAY_KILL_1;  break;
            case SPELL_ZONOZZ_WHISPER_PHASE:   textId = SAY_PHASE_1; break;
            case SPELL_ZONOZZ_WHISPER_VOID:    textId = SAY_VOID_1;  break;
            case SPELL_ZONOZZ_WHISPER_SHADOWS: textId = SAY_SHADOW_1; break;
            default: return;
            }

            sCreatureTextMgr->SendChat(GetCaster()->ToCreature(), textId, GetExplTargetUnit(), CHAT_MSG_MONSTER_WHISPER, LANG_ADDON, TEXT_RANGE_AREA);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_zonozz_whisper_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_zonozz_whisper_SpellScript();
    }
};

class spell_disrupting_shadows : public SpellScriptLoader
{
    public:
        spell_disrupting_shadows() : SpellScriptLoader("spell_disrupting_shadows") { }

        class spell_disrupting_shadows_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_disrupting_shadows_AuraScript);

            void HandleRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
            {
                if(Unit* owner = GetUnitOwner())
                    if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_ENEMY_SPELL)
                        owner->CastSpell(owner, SPELL_DISRUPTING_SHADOWS_DISPEL, false);
            }

            void Register() override
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_disrupting_shadows_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_disrupting_shadows_AuraScript();
        }
};

void AddSC_boss_warlord_zonozz()
{
    new boss_warlord_zonozz();
    new npc_void_of_the_unmaking();
    new npc_eye_of_gorath();
    new npc_flail_of_gorath();
    new npc_claw_of_gorath();
    new spell_void_diffusion();
    new spell_zonozz_whisper();
    new spell_disrupting_shadows();
}
