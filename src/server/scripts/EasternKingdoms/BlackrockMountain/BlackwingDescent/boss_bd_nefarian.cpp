/*
 * Copyright (C) 2022 BfaCore Reforged
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
#include "blackwing_descent.h"
#include "Vehicle.h"
#include "Unit.h"
#include "Object.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"
#include "Cell.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "CombatAI.h"
#include "PassiveAI.h"
#include "ObjectMgr.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "Vehicle.h"
#include "VehicleDefines.h"
#include "Spell.h"
#include "Player.h"
#include "Map.h"
#include "InstanceScript.h"
#include "Transport.h"
#include "MapManager.h"
#include "UpdateData.h"
#include "WorldPacket.h"
#include "World.h"

enum NefYells
{
/*
20072 - cowards! face the broodmother or face dire consequences!
Phase1
20073 - See how the shadowflame animates the bones? They fight at my command!

Phase2
20082 - Curse you mortals! Such callous disregard for one's possessions must be met with extreme force.
20075 - I hope you can swim... in molten lava! (p2).

Phase 3
20077 - I have tried to be an accomodating host, but you simply will not die. Time to throw all pretense aside and just KILL YOU ALL!

Shadowflame
20074 - Flesh turns to ash!

Killing a player
20079 - It has been a pleasure!
20081 - You really have to want it!

Death
20083 - Defeat has never tasted so bitter...
*/

    // Nefarian
    SAY_AVOID_WIPE                  = 0,
    SAY_AGGRO                       = 1,
    SAY_AIR_PHASE                   = 2,
    SAY_AIR_PHASE_2                 = 3,
    SAY_FINAL_PHASE                 = 4,
    SAY_SHADOWFLAME                 = 5,
    SAY_KILL                        = 6,
    SAY_DEATH                       = 7
};

enum IntroYells
{
/*
Intro
20066 - Ha ha ha ha ha! The heroes have made it to the glorious finale! I take it you are in good spirits? Prepared for the final battle? Then gaze now upon my ultimate creation! RISE, SISTER!
20070 - Behold, the Broodmother... Onyxia... REBORN. Perhaps my finest work.
20071 - My dearest sibling... do you hunger? THEN FEAST UPON OUR ENEMIES!
*/
    SAY_INTRO_1                     = 0,
    SAY_INTRO_2                     = 1,
    SAY_INTRO_3                     = 2,
};

enum Spells
{
    // Children of Deathwing - if < 50y from each other.
    SPELL_CHILDREN_OF_DEATHWING_NEF = 78620,
    SPELL_CHILDREN_OF_DEATHWING_ONY = 78619,

    // Nefarian
        // Ground
    SPELL_ELECTROCUTE          = 81272, // Every 10% of Nef life, on all p, needs radius 100 y. Used by Nefarian's Lightning Machine(51089) actually, but boss can do it just as good.
    SPELL_SHADOWFLAME_BREATH   = 77826, // Does 78122 and animates bone warriors in 60y. Script eff on 3.
    SPELL_ANIMATE_BONES        = 78122, // Not used alone but with sf breath.
    SPELL_HAIL_OF_BONES        = 78679, // Summons a bone warrior plus damage, beginning of p1.
    SPELL_TAIL_LASH            = 77827, // For those standing behind :P
    SPELL_SHADOWBLAZE_SPARK    = 81031, // Last phase, summons npc Shadowblaze Flashpoint.

        // Air
    SPELL_SHADOWFLAME_BARRAGE           = 78621, // While flying, random.
    SPELL_H_EXPLOSIVE_CINDERS_PERIODIC  = 79339, // Only HEROIC! 8 sec.
    SPELL_H_EXPLOSIVE_CINDERS_SUMM_DMG  = 79347, // Only HEROIC! does damage after 8 sec. of periodic, on removal (spell_linked_spell needed).

    SPELL_SHADOW_COWARDICE     = 79353, // If fight resets and people in area -> wipe.

        // Heroic Dominion Mechanic.
    SPELL_DOMINION             = 79318, // Controlled by Nef - grants ability bar.
    SPELL_DOMINION_IMMUN       = 95900, // Immunities.
    SPELL_DOMINION_DUMMY       = 94211, // Faction dummy.

    SPELL_SIPHON_POWER         = 79319, // On Abil bar - on cast -> Stolen.
    SPELL_STOLEN_POWER         = 80627, // Buff from Siphon, needs spell_linked_spell on that cast.
    SPELL_FREE_MIND            = 79323, // Works already!

    // Onyxia - Lightning Discharge needs research.
    SPELL_ONYXIA_DISCHARGE_BAR = 78949,
    SPELL_INCREASE_BAR         = 98734, // +1 power on discharge bar.

    SPELL_LIGHTNING_DISCHARGE  = 77944,

    // Anim Bone Warriors
    SPELL_NO_REGEN             = 78725,
    SPELL_NO_REGEN2            = 72242,
    SPELL_EMPOWER              = 79329, // Aura applied on summoned.
    SPELL_HURL_BONE            = 81586,
    SPELL_DIE_VISUAL           = 57626, // Just some die visual spell. They are not actually dead.

    // Chromatic Prototype
    SPELL_NOVA                 = 80734, // Needs interr or wipes raid, periodic trigger aura.

    // Shadowblaze Flashpoint
    SPELL_FIREBRUSH_AURA       = 79396  // Aura on summ, 81007 every sec and 78122, reanimating bone warrs. See SPELL_SHADOWBLAZE_SPARK.
};

enum Phases
{
    PHASE_NULL = 0,
    PHASE_INTRO,
    PHASE_GROUND,
    PHASE_FLIGHT,
    PHASE_FINAL
};

enum Events
{
// Nefarian
    // Intro
    EVENT_INTRO_1 = 1,
    EVENT_INTRO_2,
    EVENT_INTRO_3,
    EVENT_SUMMON_ONYXIA,
    EVENT_SUMMON_NEFARIAN,

    EVENT_INTRO,
    EVENT_INTRO2,
    EVENT_HAIL_OF_BONES,
    EVENT_MOVE,
    EVENT_LANDING,

    EVENT_ELECTROCUTE,

    // Ground phase
    EVENT_SHADOWFLAME_BREATH,
    EVENT_SHADOW_COWARDICE,
    EVENT_TAIL_LASH,

    EVENT_LIFTOFF,
    EVENT_FLIGHT,
    EVENT_AIR,

    // Air phase
    EVENT_SHADOWFLAME_BARRAGE,
    EVENT_SUMMON_CHROMATIC,
    EVENT_LAND,
    EVENT_RETURN,
    EVENT_GROUND,

    // Final phase
    EVENT_SHADOWBLAZE,
    EVENT_REVIVE_SKELETONS,

// Onyxia
   EVENT_SF_BREATH,
   EVENT_LIGHTNING_DISCHARGE,
   EVENT_TAL_LASH,
};

enum Npc
{
    NPC_NEFARIAN_INTRO = 41379,
    NPC_CHROMATIC_PROTO = 41948,
    NPC_ANIM_BONE_WARR = 41918,
    MOB_SHADOWBLAZE = 42596,
};

Position const NefarianPositions[3] =
{
    {-135.795151f, 15.569847f, 73.165909f, 4.646072f}, // Intro
    {-129.176636f, -10.488489f, 73.079071f, 5.631739f}, // Ground
    {-106.186249f, -18.533386f, 72.798332f, 1.555510f}, // Air
};

Position ChromaticPositions[3] =
{
    {-107.213f, -224.62f, 7.70235f, 3.1416f}, // Normal position.
    {-107.213f, -224.62f, -8.32f, 3.1416f}, // Intro position.
    {-107.213f, -224.62f, -6.8679f, 3.1416f}, // Position for p2.
};

class boss_bd_nefarian : public CreatureScript
{
public:
    boss_bd_nefarian() : CreatureScript("boss_bd_nefarian") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_bd_nefarianAI (creature);
    }

    struct boss_bd_nefarianAI : public BossAI
    {
        boss_bd_nefarianAI(Creature* creature) : BossAI(creature, DATA_NEFARIAN)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        Phases phase;
        uint32 m_uiOnyxiaCheckTimer;
        uint32 m_uiDistanceCheckTimer;
        uint32 m_uiChromaticCheckTimer;
        bool onyxiaAlive, electrocute, said, secondPhase, finalPhase;

        void Reset() override
        {
            events.Reset();
            phase = PHASE_NULL;
            onyxiaAlive = true;
            said = false;
            electrocute = false;
            secondPhase = false;
            finalPhase = false;

            me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);

            if (instance)
                instance->SetBossState(DATA_NEFARIAN, NOT_STARTED);

            _Reset();
        }

        void IsSummonedBy(Unit* /*summoner*/) override
        {
            DoZoneInCombat();
            if(Creature* Onyxia = me->FindNearestCreature(NPC_ONYXIA, 150.0f, true))
                Onyxia->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            Reset();

            me->DespawnOrUnsummon(1000);
            me->SummonCreature(NPC_NEFARIAN_INTRO, -167.093f, -224.479f, 40.399f, 6.278f, TEMPSUMMON_MANUAL_DESPAWN);

            if (instance)
            {
                instance->SetBossState(DATA_NEFARIAN, FAIL);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me); // Remove
            }

            _EnterEvadeMode();
        }

        void EnterCombat(Unit* /*pWho*/) override
        {
            EnterPhaseIntro();

            if (instance)
            {
                instance->SetBossState(DATA_NEFARIAN, IN_PROGRESS);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me); // Add
            }

            _EnterCombat();
        }

        void JustDied(Unit* /*killer*/) override
        {
            me->RemoveAllAuras();

            if (instance)
            {
                instance->SetBossState(DATA_NEFARIAN, DONE);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me); // Remove
            }

            Talk(SAY_DEATH);

            _JustDied();
        }

        void KilledUnit(Unit* /*victim*/) override
        {
            Talk(SAY_KILL-urand(0,1));
        }

        void DamageTaken(Unit* /*who*/, uint32& damage) override
        {
            if(me->HealthBelowPctDamaged(90, damage) || me->HealthBelowPctDamaged(80, damage)  || me->HealthBelowPctDamaged(70, damage) || me->HealthBelowPctDamaged(60, damage) ||
            me->HealthBelowPctDamaged(50, damage) || me->HealthBelowPctDamaged(40, damage)  || me->HealthBelowPctDamaged(30, damage) || me->HealthBelowPctDamaged(20, damage) || me->HealthBelowPctDamaged(10, damage))
            {
                electrocute = true;
                events.ScheduleEvent(EVENT_ELECTROCUTE, 100);
            }
        }

        void EnterPhaseIntro()
        {
            phase = PHASE_INTRO;
            events.SetPhase(PHASE_INTRO);
            initIntroEvents();
        }

        void EnterPhaseGround()
        {
            phase = PHASE_GROUND;
            events.SetPhase(PHASE_GROUND);
            initEvents(true);
            m_uiOnyxiaCheckTimer = 5000;
            m_uiDistanceCheckTimer = 5000;
        }

        void EnterPhaseAir()
        {
            phase = PHASE_FLIGHT;
            events.SetPhase(PHASE_FLIGHT);
            initEvents(false);
            m_uiChromaticCheckTimer = 5000;
        }

        void EnterPhaseFinal()
        {
            phase = PHASE_FINAL;
            events.SetPhase(PHASE_FINAL);
            initFinalEvents();
        }

        void initEvents(bool onGround = true)
        {
            events.Reset();

            if(onGround)
            {
                events.ScheduleEvent(EVENT_SHADOWFLAME_BREATH, 5000, PHASE_GROUND);
                events.ScheduleEvent(EVENT_SHADOW_COWARDICE, 20000, PHASE_GROUND);
            }else
            {
                events.ScheduleEvent(EVENT_SHADOWFLAME_BARRAGE, 4000, PHASE_FLIGHT);
                events.ScheduleEvent(EVENT_SUMMON_CHROMATIC, 500, PHASE_FLIGHT);
            }
        }

        void initIntroEvents()
        {
            events.Reset();

            events.ScheduleEvent(EVENT_INTRO, 100);
            events.ScheduleEvent(EVENT_INTRO2, 9900);
            events.ScheduleEvent(EVENT_MOVE, 34000);
        }

        void initFinalEvents()
        {
            events.Reset();

            events.ScheduleEvent(EVENT_TAIL_LASH, 4000, PHASE_FINAL);
            events.ScheduleEvent(EVENT_SHADOWFLAME_BREATH, 5000, PHASE_FINAL);
            events.ScheduleEvent(EVENT_SHADOWBLAZE, 9000, PHASE_FINAL);
            events.ScheduleEvent(EVENT_REVIVE_SKELETONS, 1000, PHASE_FINAL);
        }

        void JustSummoned(Creature* summon) override
        {
            summon->AI()->DoZoneInCombat();

            //if(summon->GetEntry() == NPC_ROARING_FLAME_TARGET)
            //{
            //    summon->SetSpeed(MOVE_WALK, 0.8f);
            //    summon->SetSpeed(MOVE_RUN, 0.8f);
            //    if(Unit* target = SelectTarget(SELECT_TARGET_NEAREST, 0, 50.0f, true))
            //    summon->CastSpell(summon, SPELL_SONAR_PULSE_H, true); // add aura
            //    summon->GetMotionMaster()->MoveChase(target);
            //}
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (Creature* Onyxia = me->FindNearestCreature(NPC_ONYXIA, 150.0f, true))
                if (Onyxia && !Onyxia->IsInCombat() && said == false)
                {
                    Talk(SAY_AVOID_WIPE);
                    said = true;
                }

            if (phase == PHASE_GROUND && m_uiDistanceCheckTimer <= diff)
            {
                if (me->FindNearestCreature(NPC_ONYXIA, 50.0f, true) && onyxiaAlive && !me->HasAura(SPELL_CHILDREN_OF_DEATHWING_ONY))
                    me->AddAura(SPELL_CHILDREN_OF_DEATHWING_ONY, me);
                else if (!me->FindNearestCreature(NPC_ONYXIA, 50.0f, true) && onyxiaAlive)
                    if(me->HasAura(SPELL_CHILDREN_OF_DEATHWING_ONY))
                       me->RemoveAura(SPELL_CHILDREN_OF_DEATHWING_ONY);

                m_uiDistanceCheckTimer = 5000;
            }
            else m_uiDistanceCheckTimer -= diff;

            if (phase == PHASE_GROUND && m_uiOnyxiaCheckTimer <= diff && !secondPhase)
            {
                if (me->FindNearestCreature(NPC_ONYXIA, 150.0f, true))
                    onyxiaAlive = true;
                else
                {
                    onyxiaAlive = false;
                    Talk(SAY_AIR_PHASE);
                    if(me->HasAura(SPELL_CHILDREN_OF_DEATHWING_ONY))
                       me->RemoveAura(SPELL_CHILDREN_OF_DEATHWING_ONY);
                    events.ScheduleEvent(EVENT_LIFTOFF, 5000, PHASE_GROUND);
                    secondPhase = true;
                }

                m_uiOnyxiaCheckTimer = 5000;
            }
            else m_uiOnyxiaCheckTimer -= diff;

            if (phase == PHASE_FLIGHT && m_uiChromaticCheckTimer <= diff && !finalPhase)
            {
                if (!me->FindNearestCreature(NPC_CHROMATIC_PROTO, 150.0f, true))
                    events.ScheduleEvent(EVENT_LAND, 2000, PHASE_FLIGHT);
                finalPhase = true;

                m_uiChromaticCheckTimer = 5000;
            }
            else m_uiChromaticCheckTimer -= diff;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_ELECTROCUTE:
                        if(electrocute == true)
                        {
                            DoCast(me, SPELL_ELECTROCUTE);
                            electrocute = false;
                        }
                        break;

                    case EVENT_INTRO:
                        me->HandleEmoteCommand(EMOTE_ONESHOT_LIFTOFF);
                        me->SetDisableGravity(true);
                        me->SetAnimTier(UNIT_BYTE1_FLAG_HOVER, true);
                        me->GetMotionMaster()->MovePoint(1, -126.518f, -233.342f, 36.358f); // Position on top of raid.
                        break;

                    case EVENT_INTRO2:
                        Talk(SAY_AGGRO);
                        events.ScheduleEvent(EVENT_HAIL_OF_BONES, 100);
                        break;

                    case EVENT_HAIL_OF_BONES:
                        DoCast(me, SPELL_HAIL_OF_BONES);
                        break;

                    case EVENT_MOVE:
                        me->GetMotionMaster()->MovePoint(1, -100.123f, -221.522f, 7.156f); // Move down.
                        events.ScheduleEvent(EVENT_LANDING, 8000);
                        break;

                    case EVENT_LANDING:
                        me->HandleEmoteCommand(EMOTE_ONESHOT_LAND);
                        me->SetAnimTier(UNIT_BYTE1_FLAG_NONE, true);
                        me->SetDisableGravity(false);
                        EnterPhaseGround();
                        me->GetMotionMaster()->MoveChase(me->GetVictim());
                        me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                        break;

                    case EVENT_SHADOWFLAME_BREATH:
                        Talk(SAY_SHADOWFLAME);
                        DoCastVictim(SPELL_SHADOWFLAME_BREATH);
                        events.ScheduleEvent(EVENT_SHADOWFLAME_BREATH, urand(10000, 12000));
                        break;

                    case EVENT_SHADOW_COWARDICE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                            DoCast(target, SPELL_SHADOW_COWARDICE);
                        events.ScheduleEvent(EVENT_SHADOW_COWARDICE, urand(9000, 10000));
                        break;

                    case EVENT_LIFTOFF:
                        Talk(SAY_AIR_PHASE_2);
                        if(GameObject* elevator = me->FindNearestGameObject(207834, 200.0f))
                            elevator->SetGoState(GO_STATE_READY);

                        me->HandleEmoteCommand(EMOTE_ONESHOT_LIFTOFF);
                        me->SetAnimTier(UNIT_BYTE1_FLAG_HOVER, true);
                        me->SetDisableGravity(true);
                        events.ScheduleEvent(EVENT_FLIGHT, 1500);
                        events.ScheduleEvent(EVENT_AIR, 2000);
                        break;

                    case EVENT_FLIGHT:
                        me->SetReactState(REACT_PASSIVE);
                        me->AttackStop();
                        me->GetMotionMaster()->MovePoint(1, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 30.0f);
                        break;

                    case EVENT_AIR:
                        EnterPhaseAir();
                        break;

                    case EVENT_SUMMON_CHROMATIC:
                        me->SummonCreature(NPC_CHROMATIC_PROTO, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);
                        break;

                    case EVENT_SHADOWFLAME_BARRAGE:
                        if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 200.0f, true))
                            DoCast(target, SPELL_SHADOWFLAME_BARRAGE);
                        events.ScheduleEvent(EVENT_SHADOWFLAME_BARRAGE, urand(8000, 11000));
                        break;

                    case EVENT_LAND:
                        me->HandleEmoteCommand(EMOTE_ONESHOT_LAND);
                        me->SetDisableGravity(false);
                        me->SetAnimTier(UNIT_BYTE1_FLAG_NONE, true);
                        events.ScheduleEvent(EVENT_RETURN, 1000);
                        events.ScheduleEvent(EVENT_GROUND, 1500);
                        break;

                    case EVENT_RETURN:
                        me->SetReactState(REACT_PASSIVE);
                        me->AttackStop();
                        me->GetMotionMaster()->MovePoint(1, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() - 30.0f);
                        break;

                    case EVENT_GROUND:
                        EnterPhaseFinal();
                        me->SetReactState(REACT_AGGRESSIVE);
                        AttackStart(me->GetVictim());
                        me->GetMotionMaster()->MoveChase(me->GetVictim());
                        if(GameObject* elevator = me->FindNearestGameObject(207834, 200.0f))
                            elevator->SetGoState(GO_STATE_ACTIVE);

                        Talk(SAY_FINAL_PHASE);
                        break;

                    case EVENT_TAIL_LASH:
                        DoCast(me, SPELL_TAIL_LASH);
                        events.ScheduleEvent(EVENT_TAIL_LASH, urand(8000, 11000));
                        break;

                    case EVENT_SHADOWBLAZE:
                        if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 200.0f, true))
                            DoCast(target, SPELL_SHADOWBLAZE_SPARK);
                        events.ScheduleEvent(EVENT_TAIL_LASH, urand(18000, 21000));
                        break;

                    case EVENT_REVIVE_SKELETONS:
                    {
                        std::list<Creature*> creatures;
                        GetCreatureListWithEntryInGrid(creatures, me, 41918, 200.0f);

                        if (!creatures.empty())
                        for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
                        {
                            DoCast((*iter), SPELL_ANIMATE_BONES, true);
                            (*iter)->SetReactState(REACT_AGGRESSIVE);
                            (*iter)->RemoveAura(SPELL_DIE_VISUAL);
                        }
                    }
                        break;
                }
            }

            if (phase == PHASE_GROUND || phase == PHASE_FINAL)
                DoMeleeAttackIfReady();
        }
    private:
    };
};

class boss_bd_onyxia : public CreatureScript
{
public:
    boss_bd_onyxia() : CreatureScript("boss_bd_onyxia") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_bd_onyxiaAI (creature);
    }

    struct boss_bd_onyxiaAI : public ScriptedAI
    {
        boss_bd_onyxiaAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;
        uint32 m_uiDistancesCheckTimer;
        uint32 m_uiPowerTimer;

        void Reset() override
        {
            events.Reset();
            me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
            me->SetReactState(REACT_DEFENSIVE);
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            me->DespawnOrUnsummon(100);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (m_uiDistancesCheckTimer <= diff)
            {
                if (me->FindNearestCreature(BOSS_NEFARIAN, 50.0f, true) && !me->HasAura(SPELL_CHILDREN_OF_DEATHWING_ONY))
                    me->AddAura(SPELL_CHILDREN_OF_DEATHWING_NEF, me);
                else if (!me->FindNearestCreature(BOSS_NEFARIAN, 50.0f, true))
                    if(me->HasAura(SPELL_CHILDREN_OF_DEATHWING_NEF))
                       me->RemoveAura(SPELL_CHILDREN_OF_DEATHWING_NEF);

                m_uiDistancesCheckTimer = 5000;
            }
            else m_uiDistancesCheckTimer -= diff;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SF_BREATH:
                    DoCastVictim(SPELL_SHADOWFLAME_BREATH);
                    events.ScheduleEvent(EVENT_SF_BREATH, urand(13000, 17000));
                    break;

                    case EVENT_LIGHTNING_DISCHARGE:
                    DoCast(me, SPELL_LIGHTNING_DISCHARGE);
                    events.ScheduleEvent(EVENT_LIGHTNING_DISCHARGE, urand(25000, 30000));
                    break;

                    case EVENT_TAL_LASH:
                    DoCast(me, SPELL_TAIL_LASH);
                    events.ScheduleEvent(EVENT_TAL_LASH, urand(8000, 11000));
                    break;

                    default:
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

class npc_nefarian_intro : public CreatureScript // 41379
{
public:
    npc_nefarian_intro() : CreatureScript("npc_nefarian_intro") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_nefarian_introAI (creature);
    }

    struct npc_nefarian_introAI : public ScriptedAI
    {
        npc_nefarian_introAI(Creature* creature) : ScriptedAI(creature) { instance = creature->GetInstanceScript(); }

        InstanceScript* instance;
        EventMap events;
        bool introDone;

        void Reset() override
        {
            if (GameObject* elevator = me->FindNearestGameObject(207834, 200.0f))
                elevator->SetGoState(GO_STATE_READY);

            /*
            events.Reset();
            introDone = false;
            //me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);*/
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_INTRO_1, 2000);
            me->SetReactState(REACT_PASSIVE);
        }

        void JustSummoned(Creature* summon) override
        {
            if(summon->GetEntry() == BOSS_NEFARIAN)
            {
                  summon->AI()->DoZoneInCombat();
            }
        }

        void UpdateAI(uint32 diff) override
        {
            //if(instance->GetBossState(BOSS_CHIMAERON) == DONE)
            //    me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_INTRO_1:
                        Talk(SAY_INTRO_1);
                        if(GameObject* elevator = me->FindNearestGameObject(207834, 200.0f))
                            elevator->SetGoState(GO_STATE_ACTIVE);

                        events.ScheduleEvent(EVENT_SUMMON_ONYXIA, 14000);
                        events.ScheduleEvent(EVENT_INTRO_2, 15000);
                        return;

                    case EVENT_SUMMON_ONYXIA:
                        me->SummonCreature(NPC_ONYXIA, -104.713f, -225.264f, 7.156f, 3.122f, TEMPSUMMON_MANUAL_DESPAWN);
                        return;

                    case EVENT_INTRO_2:
                        Talk(SAY_INTRO_2);
                        events.ScheduleEvent(EVENT_INTRO_3, 10000);
                        return;

                    case EVENT_INTRO_3:
                        Talk(SAY_INTRO_3);
                        introDone = true;
                        events.ScheduleEvent(EVENT_SUMMON_NEFARIAN, 7500);
                        me->DespawnOrUnsummon(8000);
                        return;

                    case EVENT_SUMMON_NEFARIAN:
                        me->SummonCreature(BOSS_NEFARIAN, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);
                        return;
                }
            }
        }

        void DamageTaken(Unit* /*who*/, uint32& /*damage*/) override
        {
            me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
            me->AddUnitFlag(UNIT_FLAG_REMOVE_CLIENT_CONTROL);
            me->SetReactState(REACT_PASSIVE);
            me->AttackStop();
        }
    };
};

class npc_animated_bone_warrior : public CreatureScript
{
public:
    npc_animated_bone_warrior() : CreatureScript("npc_animated_bone_warrior") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_animated_bone_warriorAI (creature);
    }

    struct npc_animated_bone_warriorAI : public ScriptedAI
    {
        npc_animated_bone_warriorAI(Creature* creature) : ScriptedAI(creature)
        {
            ASSERT(creature->GetVehicleKit()); // get and set power type.
            creature->SetPower(POWER_ENERGY, 100);
            creature->SetMaxPower(POWER_ENERGY, 100);
        }

        uint32 timerHurlBone;

        void EnterCombat(Unit* /*who*/) override
        {
            timerHurlBone = urand(4000, 9000);
            me->AddAura(SPELL_NO_REGEN, me);
            me->AddAura(SPELL_NO_REGEN2, me);
            DoCast(me, SPELL_ANIMATE_BONES);
            DoCast(me, SPELL_EMPOWER);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (me->GetPower(POWER_ENERGY) == 0)
            {
                me->SetReactState(REACT_PASSIVE);
                me->RemoveAura(SPELL_ANIMATE_BONES);
                DoCast(me, SPELL_DIE_VISUAL);
                me->SetPower(POWER_ENERGY, 0);
            }

            if (timerHurlBone <= diff)
            {
                DoCastVictim(SPELL_HURL_BONE);
                timerHurlBone = urand(8000, 14000);
            } else timerHurlBone -= diff;

            if(me->HasAura(SPELL_ANIMATE_BONES))
            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/) override
        {
            me->DespawnOrUnsummon(100);
        }
    };
};

class npc_chromatic_prototype : public CreatureScript
{
public:
    npc_chromatic_prototype() : CreatureScript("npc_chromatic_prototype") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_chromatic_prototypeAI (creature);
    }

    struct npc_chromatic_prototypeAI : public ScriptedAI
    {
        npc_chromatic_prototypeAI(Creature* creature) : ScriptedAI(creature) { }

        void EnterCombat(Unit* /*who*/) override
        {
            me->AddAura(SPELL_NOVA, me);
            me->SetReactState(REACT_PASSIVE);
        }

        void UpdateAI(uint32 /*diff*/) override { }

        void JustDied(Unit* /*killer*/) override { }
    };
};

class npc_shadowflame_flashfire : public CreatureScript
{
public:
    npc_shadowflame_flashfire() : CreatureScript("npc_shadowflame_flashfire") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_shadowflame_flashfireAI (creature);
    }

    struct npc_shadowflame_flashfireAI : public ScriptedAI
    {
        npc_shadowflame_flashfireAI(Creature* creature) : ScriptedAI(creature)
        {
            timerMove = 500;
            timerDespawn = 20000;
            timerSpawn = 1500;
            creature->SetReactState(REACT_PASSIVE);
        }

        uint32 timerMove;
        uint32 timerDespawn;
        uint32 timerSpawn;

        void UpdateAI(uint32 diff) override
        {
            if (timerMove <= diff) // move forward
            {
                me->SetSpeed(MOVE_WALK, 0.8f);
                me->SetSpeed(MOVE_RUN, 0.8f);
                float x, y, z;
                me->GetClosePoint(x, y, z, me->GetObjectSize() / 3, 50.0f);
                me->GetMotionMaster()->MovePoint(1, x, y, z);
            } else timerMove -= diff;

            if (timerDespawn <= diff)
            {
                me->DespawnOrUnsummon();
            } else timerDespawn -= diff;

            if (timerSpawn <= diff)
            {
                me->SummonCreature(MOB_SHADOWBLAZE, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 3000);
            } else timerDespawn -= diff;
        }
    };
};

class npc_shadowblaze : public CreatureScript
{
public:
    npc_shadowblaze() : CreatureScript("npc_shadowblaze") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_shadowblazeAI (creature);
    }

    struct npc_shadowblazeAI : public ScriptedAI
    {
        npc_shadowblazeAI(Creature* creature) : ScriptedAI(creature) { }

        uint32 timerCheckskeleton;
        uint32 timerDespawn;

        void IsSummonedBy(Unit* /*summoner*/) override
        {
            timerCheckskeleton = 100;
            timerDespawn = 6100;
            me->AddAura(SPELL_FIREBRUSH_AURA, me);
        }

        void UpdateAI(uint32 diff) override
        {
            if (timerCheckskeleton <= diff)
            {
                if (Unit* skeleton = me->FindNearestCreature(NPC_ANIM_BONE_WARR, 4.0f, true))
                    skeleton->CastSpell(skeleton, SPELL_ANIMATE_BONES, true); // revive skeletons hit.
                timerCheckskeleton = 980; // 20 x 5 equals to first check diff.
            } else timerCheckskeleton -= diff;

            if (timerDespawn <= diff)
            {
                me->DespawnOrUnsummon();
            } else timerDespawn -= diff;
        }

        void JustDied(Unit* /*killer*/) override { }
    };
};

class spell_nefarian_tail_lash : public SpellScriptLoader
{
    public:
        spell_nefarian_tail_lash() : SpellScriptLoader("spell_nefarian_tail_lash") { }

        class spell_nefarian_tail_lash_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_nefarian_tail_lash_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                if (Unit* owner = GetCaster())
                    targets.remove(owner);

                for (std::list<WorldObject*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                    if (!(*itr)->isInBack(GetCaster(), 2.5f))
                        targets.remove((*itr));
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_nefarian_tail_lash_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_CONE_ENEMY_104);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_nefarian_tail_lash_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_CONE_ENEMY_104);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_nefarian_tail_lash_SpellScript();
        }
};

class spell_onyxia_lightning_discharge : public SpellScriptLoader
{
    public:
        spell_onyxia_lightning_discharge() : SpellScriptLoader("spell_onyxia_lightning_discharge") { }

        class spell_onyxia_lightning_discharge_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_onyxia_lightning_discharge_SpellScript);

             void CalculateDamage(SpellEffIndex /*effIndex*/)
             {
                if (!GetHitUnit())
                    return;

                if (GetHitUnit()->isInFront(GetCaster(), GetCaster()->GetObjectSize() / 3) || GetHitUnit()->isInBack(GetCaster(), GetCaster()->GetObjectSize() / 3))
                    SetHitDamage(0);
             }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_onyxia_lightning_discharge_SpellScript::CalculateDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_onyxia_lightning_discharge_SpellScript();
        }
};

void AddSC_boss_bd_nefarian()
{
    new boss_bd_nefarian();
    new boss_bd_onyxia();
    new npc_nefarian_intro();
    new npc_animated_bone_warrior();
    new npc_chromatic_prototype();
    new npc_shadowflame_flashfire();
    new npc_shadowblaze();
    new spell_nefarian_tail_lash();
    new spell_onyxia_lightning_discharge();
}
