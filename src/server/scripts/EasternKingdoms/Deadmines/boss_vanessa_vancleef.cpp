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
#include "deadmines.h"
#include "Vehicle.h"
#include "GameObject.h"
#include "ScriptedGossip.h"

enum Spells
{
    SPELL_BACKSLASH             = 92619,
    SPELL_DEFLECTION            = 92614,
    SPELL_DEADLY_BLADES         = 92622,
    SPELL_VENGEANCE             = 95542,
    SPELL_POWDER_EXP            = 96283,
    SPELL_FIERY_BLAZE           = 93484,
    SPELL_FIERY_BLAZE_DMG       = 93485,
    SPELL_CLICK_ME              = 95527,
    // misc
    SPELL_EVASION               = 90958,
    SPELL_SHADOWSTEP            = 90956,
    SPELL_SINISTER              = 90951,
    SPELL_BLADES                = 90960,
    SPELL_CHARGE                = 90928,
    SPELL_RECKLESSNESS          = 90929,
    SPELL_BLOODBATH             = 90925,
    SPELL_MOTIVATE              = 91036,
    SPELL_THREATENING           = 91034,
    SPELL_UPPERCUT              = 91045,
    SPELL_AXE_HEAD              = 90098,
    SPELL_ENRAGE                = 8599,
    SPELL_BLOODBOLT             = 90938,
    SPELL_BLOODWASH             = 90946,
    SPELL_RAGEZONE              = 90932,
    //envocer
    SPELL_HOLY_FIRE             = 91004,
    SPELL_RENEGADE              = 90047,
    SPELL_SHIELD                = 92001,
    // Vanessa event
    SPELL_SITTING               = 89279,
    SPELL_NOXIOUS_CONCOCTION    = 92100,
    SPELL_BLACKOUT              = 92120,
    SPELL_RIDE_VEHICLE          = 46598,

    //1 Nightmare
    SPELL_EFFECT_1              = 92563,
    SPELL_ICYCLE                = 92189,
    SPELL_SPIRIT_STRIKE         = 59304,
    SPELL_SPRINT                = 92604
};

enum eAchievementMisc
{
    ACHIEVEMENT_VIGOROUS_VANCLEEF_VINDICATOR = 5371,
    NPC_ACHIEVEMENT_CONTROLLER               = 51624,
    START_TIMER_ACHIEVEMENT                  = 1,
    ACHIEVEMENT_READY_GET                    = 2,
};

enum Events
{
    EVENT_BACKSLASH = 1,
    EVENT_VENGEANCE,
    EVENT_DEFLECTION,
    EVENT_DEADLY_BLADES,
    EVENT_POWDER_EXP,
    EVENT_FIERY_BLAZE,
    EVENT_SHADOWGUARD,
    EVENT_SUMMON_ROPE,
    EVENT_ROPE_READY,
    EVENT_DISSAPEAR,
    EVENT_FIRE_BOOM,
    EVENT_CLEAR_SHIP,
    EVENT_SUMMON_ADD_1,
    EVENT_SUMMON_ADD_2,
    EVENT_SUMMON_ADD_3,
    EVENT_FINAL_TIMER,
    EVENT_ICYCLE_AOE = 1,
    EVENT_SPIRIT_STRIKE,
    EVENT_SPIDERS = 1,
};

enum Actions
{
    ACTION_EJECT_ALL
};

Position const Shadowspawn[] =
{
    {-74.61f, -822.91f, 40.22f, 6.24f},
    {-74.98f, -816.88f, 40.18f, 6.24f},
    {-76.12f, -819.95f, 40.08f, 6.24f},
};

Position const VanessaSpawn       ={-75.58507f, -819.9636f, 47.06727f, 6.178465f};
Position const VanessaNightmare1  ={-230.717f, -563.0139f, 51.31293f, 1.047198f};
Position const GlubtokNightmare1  ={-229.3403f, -560.3629f, 51.31293f, 5.742133f};

Position const ElectricSpark[] =
{
    {-101.4959f, -648.5552f, 8.121676f, 0.04567058f},
    {-120.96f, -638.3806f, 13.38522f, 6.237791f},
    {-135.365f, -623.0541f, 15.48179f, 6.237976f},
    {-120.1277f, -617.6179f, 15.28394f, 0.04498905f},
    {-136.7082f, -604.6687f, 16.56965f, 6.2384f},
    {-130.45f, -586.5038f, 19.61726f, 6.238641f},
    {-142.9731f, -574.9221f, 20.18317f, 6.238891f},
};

Position const FieryBlaze[] =
{
    {-178.2031f, -594.9965f, 40.6501f, 4.415683f},
    {-220.625f, -577.9618f, 21.06016f, 2.513274f},
    {-205.3056f, -563.6285f, 21.06016f, 5.25344f},
    {-214.8958f, -546.7136f, 19.3898f, 4.712389f},
    {-207.8004f, -570.6441f, 21.06016f, 1.762783f},
    {-221.4653f, -549.9358f, 19.3898f, 3.211406f},
    {-229.9635f, -559.2552f, 19.3898f, 0},
    {-216.8438f, -568.9011f, 21.06016f, 3.909538f},
    {-235.9045f, -563.3906f, 19.3898f, 0},
    {-226.6736f, -580.8316f, 20.43056f, 2.775074f},
    {-227.5226f, -595.1979f, 20.42358f, 4.206244f},
    {-215.0399f, -576.3941f, 21.06016f, 3.735005f},
    {-210.592f, -583.4739f, 21.06016f, 0},
    {-216.5399f, -602.6528f, 24.88029f, 2.687807f},
    {-220.4879f, -596.382f, 21.95116f, 0},
    {-190.4774f, -552.2778f, 51.31293f, 5.305801f},
    {-195.6267f, -550.4393f, 51.31293f, 3.752458f},
    {-209.7257f, -557.1042f, 51.31293f, 3.525565f},
    {-187.9531f, -567.0469f, 51.31293f, 5.305801f},
    {-192.2031f, -595.9636f, 36.37407f, 2.80998f},
    {-183.4236f, -577.2674f, 46.87183f, 3.944444f},
    {-184.6528f, -572.3663f, 49.27317f, 3.159046f},
    {-187.3333f, -550.8143f, 19.3898f, 3.385939f},
    {-185.2083f, -562.4844f, 19.3898f, 0.9599311f},
    {-228.592f, -553.1684f, 19.3898f, 5.550147f},
    {-210.7431f, -603.2813f, 27.17259f, 4.904375f},
    {-194.1302f, -548.3055f, 19.3898f, 4.153883f},
    {-181.2379f, -555.3177f, 19.3898f, 0.3141593f},
    {-191.2205f, -581.4965f, 21.06015f, 2.007129f},
    {-198.4653f, -580.757f, 21.06015f, 0.8901179f},
    {-196.5504f, -587.7031f, 21.06015f, 1.27409f},
    {-241.5938f, -578.6858f, 19.3898f, 2.775074f},
    {-226.1615f, -573.8021f, 20.40991f, 5.218534f},
    {-186.9792f, -556.8472f, 19.3898f, 4.153883f},
    {-201.224f, -570.6788f, 21.06016f, 3.577925f},
    {-196.8767f, -574.9688f, 21.06016f, 4.29351f},
    {-225.6962f, -601.3871f, 21.82762f, 4.555309f},
    {-215.7205f, -608.4722f, 25.87703f, 2.530727f},
    {-197.1007f, -609.7257f, 32.38494f, 0},
    {-221.8629f, -607.2205f, 23.7542f, 4.939282f},
    {-201.9757f, -611.8663f, 30.62297f, 2.897247f},
};

Position const FamilySpawn[] =
{
    {-98.63194f, -721.6268f, 8.547067f, 1.53589f},  // Emme Harrington
    {5.239583f, -763.0868f, 9.800426f, 2.007129f}, // Erik Harrington
    {-83.86406f, -775.2837f, 28.37906f, 1.710423f}, // Calissa Harrington
    {-83.16319f, -774.9636f, 26.90351f, 1.710423f}, // James Harrington veh
};

Position const EnragedWorgen_1[] =
{
    {-97.79166f, -717.8542f, 8.668088f, 4.520403f},
    {-94.40278f, -719.7274f, 8.598646f, 3.560472f},
    {-101.9167f, -718.7552f, 8.726379f, 5.51524f},
};

Position const EnragedWorgen_2[] =
{
    {3.137153f, -760.0313f, 9.725998f, 5.393067f},
    {8.798013f, -762.2252f, 9.625132f, 3.379143f},
    {4.232807f, -766.6125f, 9.804724f, 1.292649f},
};

Position const NightmareSpidersSpawn[] =
{
    {-185.03f, -579.83f, -20.63f, 3.19f},
    {-186.59f, -573.01f, -20.95f, 5.61f},
    {-176.38f, -565.76f, -19.30f, 5.03f},
    {-181.68f, -566.33f, -51.11f, 5.15f},
};

#define COMBAT_START           "I will not share my father''s fate!  Your tale ends here!"
#define FOOLS_BOMB             "Fools! This entire ship is rigged with explosives! Enjoy your fiery deaths!"
#define HUGH_BOMB              "Vanessa pulls out a final barrel of mining powder and ignites it! RUN!"
#define VANESSA_DETONATE       "Vannesa has detonated charges on the ship! Get to the ropes at the side of the boat!"
#define TEXT_INFO              "A shadowy figure appears in the ship's cabine!"
#define TEXT_INFO_1            "You hear a voice from above the cabin door"!
#define TEXT_INFO_2            "Vanessa injects you with the Nightmare Elixir!"
#define TEXT_INFO_3            "Active the steam valves to free yourself!"
#define TEXT_INFO_4            "The Nightmare Elixir takes hold!"
#define TEXT_INFO_5            "You have entered Glubtok's Nightmare!"
#define VANESSA_SAY_1          "I've been waiting a long time for this you know."
#define VANESSA_SAY_2          "Biding my time , building my forces, studing the minds of my enemies."
#define VANESSA_SAY_3          "I was never very good at hand-to-hand combat, you know. Not like my father."
#define VANESSA_SAY_4          "But I always excelled at poison."
#define VANESSA_SAY_5          "Especially venoms that affect the mind."
#define INTRUDER_SAY           "Continue reading... <Note: This will alert Vanessa to your presence!>"
#define VANESSA_GLUB_1         "Poor Glubtok. When his powers manifested his own ogre mound was the first to burn."
#define VANESSA_GLUB_2         "Deep within his soul the thing he feared most of all was.. himself!"
#define VANESSA_HELIX_1        "Most rogues prefer to cloak themselves in the shadows, but not Helix."
#define VANESSA_HELIX_2        "You never know what skitters in the darkness."
#define VANESSA_MECHANICAL_1   "Can you imagine the life of a machine?"
#define VANESSA_MECHANICAL_2   "A simple spark can mean the difference between life... and death."
#define VANESSA_RIPSNARL_1     "Ripsnarl wasn't always a bloodthirsty savage. Once, he even had a family."
#define VANESSA_RIPSNARL_2     "He was called James Harringtion. A tragedy in three parts."

#define VANESSA_NIGHTMARE_1    "You hear a voice from above the cabin door."
#define VANESSA_NIGHTMARE_2    "Vanessa injects you with the Nightmare Elixir!"
#define VANESSA_NIGHTMARE_3    "You have entered Glubtok's Nightmare!"
#define VANESSA_NIGHTMARE_4    "Get back to the ship!"
#define VANESSA_NIGHTMARE_5    "You have entered Helix's nightmare!"
#define VANESSA_NIGHTMARE_6    "The Nightmare Elixir takes hold!"
#define VANESSA_NIGHTMARE_7    "Nightmare spiders appear in the darkness! Kill Helix before his nightmare overhelms you!"
#define VANESSA_NIGHTMARE_8    "You have entered the mechanical nightmare!"
#define VANESSA_NIGHTMARE_9    "You have entered Ripsnarl's nightmare!"
#define VANESSA_NIGHTMARE_10   "Save Emme Harrington!"
#define VANESSA_NIGHTMARE_11   "Save Erik Harrington!"
#define VANESSA_NIGHTMARE_12   "Save Calissa Harrington!"
#define VANESSA_NIGHTMARE_13   "The Nightmare Elixir wears off!"
#define VANESSA_NIGHTMARE_14   "The nightmare shifts!"

Position const RopeSpawn[] =
{
    {-64.01f, -839.84f, 41.22f, 0},
    {-66.82f, -839.92f, 40.97f, 0},
    {-69.75f, -839.87f, 40.71f, 0},
    {-72.32f, -839.71f, 40.48f, 0},
    {-75.76f, -839.33f, 40.18f, 0},
};

class boss_vanessa_vancleef : public CreatureScript
{
public:
    boss_vanessa_vancleef() : CreatureScript("boss_vanessa_vancleef") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_vanessa_vancleefAI(creature);
    }

    struct boss_vanessa_vancleefAI : public BossAI
    {
        boss_vanessa_vancleefAI(Creature* creature) : BossAI(creature, DATA_VANESSA), ropeList(creature) { }

        bool Under;
        bool Under2;
        bool Killed;
        SummonList ropeList;

        uint32 RemoveAurasTimer;

        ObjectGuid PlayerGUID;

        void Reset() override
        {
            Under = false;
            Under2 = false;
            Killed = false;
            _Reset();
            RemoveAurasTimer = 0;
            PlayerGUID = ObjectGuid::Empty;
            me->SetReactState(REACT_PASSIVE);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            if (Creature* controller_achi = me->FindNearestCreature(NPC_ACHIEVEMENT_CONTROLLER, 300.0f))
            {
                controller_achi->AI()->SetData(0, ACHIEVEMENT_READY_GET);
            }

            events.ScheduleEvent(EVENT_DEADLY_BLADES, 12000);
            events.ScheduleEvent(EVENT_DEFLECTION, 10000);
            events.ScheduleEvent(EVENT_SUMMON_ADD_1, 9000);
            events.ScheduleEvent(EVENT_BACKSLASH, 15000);

            me->GetMotionMaster()->MoveJump(-65.585f, -820.742f, 41.022f, 0.0f, 10.0f, 5.0f);
            me->SetReactState(REACT_AGGRESSIVE);
            me->Yell(COMBAT_START, LANG_UNIVERSAL);

            DoZoneInCombat();
            _EnterCombat();
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            summons.DespawnAll();
            ropeList.DespawnAll();
        }

        void JustSummoned(Creature* summon) override
        {
            switch (summon->GetEntry())
            {
                case NPC_ROPE:
                    ropeList.Summon(summon);
                    summon->SummonCreature(NPC_ROPE_ANCHOR, summon->GetPositionX(), summon->GetPositionY(), summon->GetPositionZ() + 40.0f, 0, TEMPSUMMON_TIMED_DESPAWN, 10000);
                    break;
            }
            summons.Summon(summon);
        }

        void SummonedCreatureDespawn(Creature* summon) override
        {
            switch (summon->GetEntry())
            {
                case NPC_ROPE:
                    ropeList.Despawn(summon);
                    break;
            }
            summons.Despawn(summon);
        }

        void MovementInform(uint32 /*type*/, uint32 id) override
        {
            if (id == 0)
            {
                DoCast(me, 18373);
            }
        }

        void FieryBoom()
        {
            std::list<Creature*> fiery;
            me->GetCreatureListWithEntryInGrid(fiery, NPC_GENERAL_PURPOSE_BUNNY_JMF2, 150.0f);
            fiery.sort(Trinity::ObjectDistanceOrderPred(me));
            for (std::list<Creature*>::iterator itr = fiery.begin(); itr != fiery.end(); ++itr)
            {
                if (( *itr )->IsAlive() && ( *itr )->GetTypeId() == TYPEID_UNIT)
                {
                    ( *itr )->CastSpell(( *itr ), SPELL_FIERY_BLAZE, true);
                }
            }
        }

        void RemoveFiresFromShip()
        {
            std::list<Creature*> fiery;
            me->GetCreatureListWithEntryInGrid(fiery, NPC_GENERAL_PURPOSE_BUNNY_JMF2, 150.0f);
            fiery.sort(Trinity::ObjectDistanceOrderPred(me));
            for (std::list<Creature*>::iterator itr = fiery.begin(); itr != fiery.end(); ++itr)
            {
                if (( *itr )->IsAlive() && ( *itr )->GetTypeId() == TYPEID_UNIT)
                {
                    ( *itr )->RemoveAurasDueToSpell(SPELL_FIERY_BLAZE);
                }
            }
        }

        void DamageTaken(Unit* done_by, uint32& damage) override
        {
            if (PlayerGUID.IsEmpty())
            {
                if (Player* player = done_by->ToPlayer())
                {
                    PlayerGUID = player->GetGUID();
                }
            }

            if (me->GetHealth() <= damage)
            {
                damage = me->GetHealth() - 1;

                if (!Killed)
                {
                    events.ScheduleEvent(EVENT_FINAL_TIMER, 5000);
                    me->TextEmote(HUGH_BOMB, ObjectAccessor::FindPlayer(PlayerGUID), true);
                    me->RemoveAllAuras();
                    me->AttackStop();
                    me->ClearAllReactives();
                    me->CastSpell(me, 18373, true);

                }
                Killed = true;
            } else if (me->HealthBelowPctDamaged(25, damage))
            {
                events.ScheduleEvent(EVENT_VENGEANCE, 4000);
            }
            if (!Under2 && me->HealthBelowPctDamaged(26, damage))
            {
                events.ScheduleEvent(EVENT_DISSAPEAR, 1000);
                Under2 = true;
            } else if (!Under && me->HealthBelowPctDamaged(51, damage))
            {
                events.ScheduleEvent(EVENT_DISSAPEAR, 1000);
                Under = true;
            }
        }

        void SummonThreatController()
        {
            if (Creature* bunny = me->SummonCreature(NPC_GENERAL_PURPOSE_BUNNY_JMF, -52.31f, -820.18f, 51.91f, 3.32963f))
            {
                bunny->AddUnitFlag(UNIT_FLAG_STUNNED);
                bunny->AddUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                bunny->SetReactState(REACT_AGGRESSIVE);
                bunny->SetFaction(18);
                bunny->Attack(me, true);
                me->AddThreat(bunny, 200000.0f);
                me->SetInCombatWith(bunny);
            }
            me->SetInCombatWithZone();
        }

        void SummonRopes()
        {
            for (uint8 i = 0; i < 5; ++i)
            {
                me->SummonCreature(NPC_ROPE, RopeSpawn[i], TEMPSUMMON_MANUAL_DESPAWN, 0);
            }
        }

        void RopeReady()
        {
            me->Whisper(VANESSA_DETONATE, LANG_UNIVERSAL, ObjectAccessor::FindPlayer(PlayerGUID), true);

            for (SummonList::const_iterator iter = ropeList.begin(); iter != ropeList.end(); ++iter)
            {
                if (Creature* rope = ObjectAccessor::GetCreature(*me, *iter))
                {
                    if (rope->IsAlive())
                    {
                        rope->AddAura(SPELL_CLICK_ME, rope);
                        SummonThreatController();
                    }
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_DEFLECTION:
                        if (HealthAbovePct(25))
                        {
                            DoCast(me, SPELL_DEFLECTION);
                            events.ScheduleEvent(EVENT_DEFLECTION, 50000);
                        }break;
                    case EVENT_SUMMON_ADD_1:
                        if (( me->GetHealth() * 100 ) / me->GetMaxHealth() > 50)
                        {
                            me->SummonCreature(NPC_DEFIAS_ENFORCER, Shadowspawn[1], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000);
                            events.ScheduleEvent(EVENT_SUMMON_ADD_2, 15000);
                        }
                        break;
                    case EVENT_SUMMON_ADD_2:
                        if (( me->GetHealth() * 100 ) / me->GetMaxHealth() > 50)
                        {
                            me->SummonCreature(NPC_DEFIAS_SHADOWGUARD, Shadowspawn[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000);
                            events.ScheduleEvent(EVENT_SUMMON_ADD_3, 15000);
                        }
                        break;
                    case EVENT_SUMMON_ADD_3:
                        if (( me->GetHealth() * 100 ) / me->GetMaxHealth() > 50)
                        {
                            me->SummonCreature(NPC_DEFIAS_BLOODWIZARD, Shadowspawn[2], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000);
                            events.ScheduleEvent(EVENT_SUMMON_ADD_1, 15000);
                        }
                        break;
                    case EVENT_DEADLY_BLADES:
                        DoCast(me, SPELL_DEADLY_BLADES);
                        events.ScheduleEvent(EVENT_DEADLY_BLADES, 35000);
                        break;
                    case EVENT_BACKSLASH:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                            DoCast(target, SPELL_BACKSLASH);
                        events.ScheduleEvent(EVENT_BACKSLASH, 17000);
                        break;
                    case EVENT_VENGEANCE:
                        me->AddAura(SPELL_VENGEANCE, me);
                        break;

                    case EVENT_DISSAPEAR:
                        me->Yell(FOOLS_BOMB, LANG_UNIVERSAL);
                        me->RemoveAllAuras();
                        me->GetMotionMaster()->MovePoint(0, -52.31f, -820.18f, 51.91f);
                        me->SetVisible(false);
                        summons.DespawnAll();
                        events.ScheduleEvent(EVENT_SUMMON_ROPE, 2000);
                        break;
                    case EVENT_SUMMON_ROPE:
                        SummonRopes();
                        events.ScheduleEvent(EVENT_ROPE_READY, 1000);
                        break;
                    case EVENT_ROPE_READY:
                        RopeReady();
                        events.CancelEvent(EVENT_SHADOWGUARD);
                        events.ScheduleEvent(EVENT_FIRE_BOOM, 3000);
                        break;
                    case EVENT_FIRE_BOOM:
                        FieryBoom();
                        events.ScheduleEvent(EVENT_CLEAR_SHIP, 2500);
                        break;
                    case EVENT_CLEAR_SHIP:
                        RemoveFiresFromShip();
                        me->SetVisible(true);
                        me->GetMotionMaster()->MoveJump(-65.93f, -820.33f, 40.98f, 0.0f, 10.0f, 8.0f);
                        me->RemoveAllAuras();
                        events.ScheduleEvent(EVENT_SHADOWGUARD, 27000);

                        if (Creature* bunny = me->FindNearestCreature(NPC_GENERAL_PURPOSE_BUNNY_JMF, 150.0f, true))
                            bunny->DespawnOrUnsummon(2000);

                        break;
                    case EVENT_FINAL_TIMER:
                        me->CastSpell(me, SPELL_POWDER_EXP, true);
                        me->AttackStop();
                        me->ClearAllReactives();
                        me->Kill(me, false);
                        return;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

class npc_rope_ship : public CreatureScript
{
public:
    npc_rope_ship() : CreatureScript("npc_rope_ship") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_rope_shipAI(creature);
    }

    struct npc_rope_shipAI : public ScriptedAI
    {
        npc_rope_shipAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            if (me->IsSummon())
                if (Unit* summoner = me->ToTempSummon()->GetSummoner())
                    if (summoner)
                        me->CastSpell(summoner, 43785, true);
        }
    };
};

class npc_defias_shadowguard : public CreatureScript
{
public:
    npc_defias_shadowguard() : CreatureScript("npc_defias_shadowguard") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_defias_shadowguardAI(creature);
    }

    struct npc_defias_shadowguardAI : public ScriptedAI
    {
        npc_defias_shadowguardAI(Creature* creature) : ScriptedAI(creature) { }

        uint32 SinisterTimer;
        uint32 WhirlingBladesTimer;
        uint32 ShadowstepTimer;

        bool Below;

        void Reset() override
        {
            SinisterTimer = 2000;
            WhirlingBladesTimer = 6400;
            ShadowstepTimer = 6000;
            Below = false;
            me->SetPower(POWER_ENERGY, 100);
            me->SetMaxPower(POWER_ENERGY, 100);
            me->SetPowerType(POWER_ENERGY);
        }

        void UpdateAI(uint32 diff) override
        {
            if (SinisterTimer <= diff)
            {
                DoCastVictim(SPELL_SINISTER);
                SinisterTimer = urand(5000, 7000);
            } else SinisterTimer -= diff;

            if (WhirlingBladesTimer <= diff)
            {
                DoCast(me, SPELL_BLADES);
                WhirlingBladesTimer = urand(6400, 8200);
            } else WhirlingBladesTimer -= diff;

            if (HealthBelowPct(35) && !Below)
            {
                DoCast(me, SPELL_EVASION);
                Below = true;
            }
            if (ShadowstepTimer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    DoCast(target, SPELL_SHADOWSTEP);
                ShadowstepTimer = urand(6400, 8200);
            } else ShadowstepTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

class npc_defias_enforcer : public CreatureScript
{
public:
    npc_defias_enforcer() : CreatureScript("npc_defias_enforcer") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_defias_enforcerAI(creature);
    }

    struct npc_defias_enforcerAI : public ScriptedAI
    {
        npc_defias_enforcerAI(Creature* creature) : ScriptedAI(creature) { }

        uint32 BloodBathTimer;
        uint32 RecklessnessTimer;

        void Reset() override
        {
            BloodBathTimer = 8000;
            RecklessnessTimer = 13000;
        }

        void EnterCombat(Unit* /*who*/) override
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                DoCast(target, SPELL_CHARGE);
        }

        void UpdateAI(uint32 diff) override
        {
            if (BloodBathTimer <= diff)
            {
                DoCastVictim(SPELL_BLOODBATH);
                BloodBathTimer = urand(8000, 11000);
            } else BloodBathTimer -= diff;

            if (RecklessnessTimer <= diff)
            {
                DoCast(me, SPELL_BLOODBATH);
                RecklessnessTimer = 20000;
            } else RecklessnessTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

class npc_defias_envoker : public CreatureScript
{
public:
    npc_defias_envoker() : CreatureScript("npc_defias_envoker") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_defias_envokerAI(creature);
    }

    struct npc_defias_envokerAI : public ScriptedAI
    {
        npc_defias_envokerAI(Creature* creature) : ScriptedAI(creature) { }

        uint32 HolyfireTimer;
        uint32 ShieldTimer;

        void Reset() override
        {
            HolyfireTimer = 4000;
            ShieldTimer = 8000;
        }

        void UpdateAI(uint32 diff) override
        {
            if (HolyfireTimer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    DoCast(target, SPELL_HOLY_FIRE);
                HolyfireTimer = urand(8000, 11000);
            } else HolyfireTimer -= diff;

            if (ShieldTimer <= diff)
            {
                if (IsHeroic())
                {
                    DoCast(me, SPELL_SHIELD);
                    ShieldTimer = urand(18000, 20000);
                }
            } else ShieldTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

class npc_goblin_overseer : public CreatureScript
{
public:
    npc_goblin_overseer() : CreatureScript("npc_goblin_overseer") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_goblin_overseerAI(creature);
    }

    struct npc_goblin_overseerAI : public ScriptedAI
    {
        npc_goblin_overseerAI(Creature* creature) : ScriptedAI(creature) { }

        uint32 MotivateTimer;

        bool threat;

        void Reset() override
        {
            MotivateTimer = 4000;
            threat = true;
        }

        void UpdateAI(uint32 diff) override
        {
            if (MotivateTimer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    DoCast(target, SPELL_MOTIVATE);
                MotivateTimer = urand(8000, 11000);
            } else MotivateTimer -= diff;

            if (HealthBelowPct(50) && !threat)
            {
                DoCast(me, SPELL_THREATENING);
                threat = true;
            }

            DoMeleeAttackIfReady();
        }
    };
};

class npc_ogre_henchman : public CreatureScript
{
public:
    npc_ogre_henchman() : CreatureScript("npc_ogre_henchman") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_ogre_henchmanAI(creature);
    }

    struct npc_ogre_henchmanAI : public ScriptedAI
    {
        npc_ogre_henchmanAI(Creature* creature) : ScriptedAI(creature) { }

        uint32 UppercutTimer;

        void Reset() override
        {
            UppercutTimer = 4000;
        }

        void UpdateAI(uint32 diff) override
        {
            if (UppercutTimer <= diff)
            {
                DoCastVictim(SPELL_UPPERCUT);
                UppercutTimer = urand(8000, 11000);
            } else UppercutTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

class npc_oaf_lackey : public CreatureScript
{
public:
    npc_oaf_lackey() : CreatureScript("npc_oaf_lackey") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_oaf_lackeyAI(creature);
    }

    struct npc_oaf_lackeyAI : public ScriptedAI
    {
        npc_oaf_lackeyAI(Creature* creature) : ScriptedAI(creature) { }

        uint32 AxeHeadTimer;

        bool below;

        void Reset() override
        {
            AxeHeadTimer = 4000;
            below = true;
        }

        void UpdateAI(uint32 diff) override
        {
            if (AxeHeadTimer <= diff)
            {
                DoCastVictim(SPELL_AXE_HEAD);
                AxeHeadTimer = urand(18000, 21000);
            } else AxeHeadTimer -= diff;

            if (HealthBelowPct(35) && !below)
            {
                DoCast(me, SPELL_ENRAGE);
                below = true;
            }

            DoMeleeAttackIfReady();
        }
    };
};

class npc_defias_bloodwizard : public CreatureScript
{
public:
    npc_defias_bloodwizard() : CreatureScript("npc_defias_bloodwizard") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_defias_bloodwizardAI(creature);
    }

    struct npc_defias_bloodwizardAI : public ScriptedAI
    {
        npc_defias_bloodwizardAI(Creature* creature) : ScriptedAI(creature) { }

        uint32 BloodboltTimer;
        uint32 BloodWashTimer;
        uint32 RagezoneTimer;

        void Reset() override
        {
            BloodboltTimer = 3500;
            BloodWashTimer = 10000;
            RagezoneTimer = urand(7000, 9000);
        }

        void UpdateAI(uint32 diff) override
        {
            if (BloodboltTimer <= diff)
            {
                DoCastVictim(SPELL_BLOODBOLT);
                BloodboltTimer = urand(6400, 8000);
            } else BloodboltTimer -= diff;

            if (BloodWashTimer <= diff)
            {
                if (Creature* Enforcer = me->FindNearestCreature(NPC_DEFIAS_SHADOWGUARD, 100.0f, true))
                    DoCast(Enforcer, SPELL_BLOODWASH);
                BloodWashTimer = urand(15000, 21000);
            } else BloodWashTimer -= diff;

            if (RagezoneTimer <= diff)
            {
                DoCastVictim(SPELL_RAGEZONE);
                RagezoneTimer = urand(11000, 15000);
            } else RagezoneTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

class npc_vanessa_intro : public CreatureScript
{
public:
    npc_vanessa_intro() : CreatureScript("npc_vanessa_intro") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_vanessa_introAI(creature);
    }

    struct npc_vanessa_introAI : public BossAI
    {
        npc_vanessa_introAI(Creature* creature) : BossAI(creature, DATA_VANNESSA_NIGHTMARE) { }

        bool EventStarted;

        uint8 Phase;
        uint32 PongTimer;

        void Reset() override
        {
            if (!me)
                return;

            EventStarted = true;
            Phase = 0;
            PongTimer = 2000;

            me->AddAura(SPELL_SITTING, me);
            me->SetSpeed(MOVE_WALK, 1.0f);
            me->AddUnitMovementFlag(MOVEMENTFLAG_WALKING);
        }

        void UpdateAI(uint32 diff) override
        {
            if (EventStarted)
            {
                if (PongTimer <= diff)
                {
                    switch (Phase)
                    {
                        case 0:
                            me->TextEmote(VANESSA_NIGHTMARE_1, 0, true);
                            me->RemoveAurasDueToSpell(SPELL_SITTING);
                            PongTimer = 2000;
                            Phase++;
                            break;
                        case 1:
                            me->GetMotionMaster()->MoveJump(-65.93f, -820.33f, 40.98f, 0.0f, 10.0f, 8.0f);
                            me->Say(VANESSA_SAY_1, LANG_UNIVERSAL);
                            PongTimer = 6000;
                            Phase++;
                            break;
                        case 2:
                            me->GetMotionMaster()->MovePoint(0, -65.41f, -838.43f, 41.10f);
                            me->Say(VANESSA_SAY_2, LANG_UNIVERSAL);
                            PongTimer = 8000;
                            Phase++;
                            break;
                        case 3:
                            me->Say(VANESSA_SAY_3, LANG_UNIVERSAL);
                            PongTimer = 4000;
                            Phase++;
                            break;
                        case 4:
                            me->Say(VANESSA_SAY_4, LANG_UNIVERSAL);
                            me->SetFacingTo(1.57f);
                            PongTimer = 3000;
                            Phase++;
                            break;
                        case 5:
                        {
                            std::list<Player*> players;
                            me->GetPlayerListInGrid(players, 150.0f);

                            for (std::list<Player*>::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                                me->CastSpell(( *itr ), SPELL_NOXIOUS_CONCOCTION, true);

                            PongTimer = 2000;
                            Phase++;
                        }
                            break;
                        case 6:
                            me->Say(VANESSA_SAY_5, LANG_UNIVERSAL);
                            PongTimer = 4000;
                            Phase++;
                            break;
                        case 7:
                        {
                            std::list<Player*> players;
                            me->GetPlayerListInGrid(players, 150.0f);

                            if (Creature *controller_achi = me->FindNearestCreature(NPC_ACHIEVEMENT_CONTROLLER, 300.0f))
                            {
                                controller_achi->AI()->SetData(0, START_TIMER_ACHIEVEMENT);
                            }

                            for (std::list<Player*>::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                            {
                                me->CastSpell(( *itr ), SPELL_NIGHTMARE_ELIXIR, true);
                                me->CastSpell(( *itr ), SPELL_BLACKOUT, true);

                            }
                            me->TextEmote(VANESSA_NIGHTMARE_2, 0, true);
                            PongTimer = 4100;
                            Phase++;
                        }
                            break;
                        case 8:
                        {
                            std::list<Player*> players;
                            me->GetPlayerListInGrid(players, 150.0f);

                            for (std::list<Player*>::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                                me->CastSpell(( *itr ), SPELL_BLACKOUT, true);

                            me->SummonCreature(NPC_TRAP_BUNNY, -65.93f, -820.33f, 40.98f, 0, TEMPSUMMON_MANUAL_DESPAWN, 0);

                            PongTimer = 4000;
                            Phase++;
                        }
                            break;
                        case 9:
                        {
                            me->DespawnOrUnsummon(3000);
                        }
                            break;
                        default:
                            break;
                    }
                } else PongTimer -= diff;
            }
        }
    };
};

class npc_magma_pull : public CreatureScript
{
public:
    npc_magma_pull() : CreatureScript("npc_magma_pull") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_magma_pullAI(creature);
    }

    struct npc_magma_pullAI : public ScriptedAI
    {
        npc_magma_pullAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        bool Pullplayers, Csummon;
        ObjectGuid PlayerGUID;
        uint32 PongTimer;

        void Reset() override
        {
            Pullplayers = true;
            Csummon = true;
            PlayerGUID = ObjectGuid::Empty;
            PongTimer = 2000;
        }

        void AfterTeleportPlayer(Player* player)
        {
            PlayerGUID = player->GetGUID();
        }

        void UpdateAI(uint32 diff) override
        {
            if (PongTimer <= diff)
            {
                if (Pullplayers)
                {
                    std::list<Player*> players;
                    me->GetPlayerListInGrid(players, 150.0f);

                    for (std::list<Player*>::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                    {
                        ( *itr )->AddAura(SPELL_EFFECT_1, ( *itr ));
                        ( *itr )->NearTeleportTo(-205.7569f, -579.0972f, 42.98623f, 2.3f);
                    }

                    me->Whisper(VANESSA_NIGHTMARE_6, LANG_UNIVERSAL, ObjectAccessor::FindPlayer(PlayerGUID), true);
                    me->DespawnOrUnsummon(3000);

                    if (!me->SelectNearestPlayer(50))
                        Pullplayers = false;

                }
                if (Csummon)
                {
                    me->SummonCreature(NPC_VANESSA_NIGHTMARE, VanessaNightmare1, TEMPSUMMON_MANUAL_DESPAWN, 0);
                    me->SummonCreature(NPC_GLUBTOK_NIGHTMARE, GlubtokNightmare1, TEMPSUMMON_MANUAL_DESPAWN, 0);
                    Csummon = false;
                }

            } else PongTimer -= diff;
        }
    };
};

class npc_note : public CreatureScript
{
public:
    npc_note() : CreatureScript("npc_note") { }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (player)
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, INTRUDER_SAY, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

        SendGossipMenuFor(player, player->GetGossipTextId(creature), creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        player->PlayerTalkClass->ClearMenus();

        if (action == GOSSIP_ACTION_INFO_DEF + 1)
        {
            creature->SummonCreature(NPC_VANESSA_VANCLEEF, VanessaSpawn, TEMPSUMMON_MANUAL_DESPAWN, 0);
            creature->TextEmote(TEXT_INFO, 0, true);
            creature->DespawnOrUnsummon();
            CloseGossipMenuFor(player);
        }

        return true;
    }
};

class npc_vanessa_nightmare : public CreatureScript
{
public:
    npc_vanessa_nightmare() : CreatureScript("npc_vanessa_nightmare") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_vanessa_nightmareAI(creature);
    }

    struct npc_vanessa_nightmareAI : public ScriptedAI
    {
        npc_vanessa_nightmareAI(Creature* creature) : ScriptedAI(creature), summons(me)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        bool Nightmare;
        bool ShiftToTwo;
        bool ShiftToThree;
        bool ShiftToFour;

        uint8 Phase;
        uint8 NightmareCount;
        uint8 WorgenCount;
        uint32 NightmareTimer;

        SummonList summons;

        void Reset() override
        {
            me->Say(VANESSA_GLUB_1, LANG_UNIVERSAL);
            Nightmare = true;
            ShiftToTwo = false;
            ShiftToThree = false;
            ShiftToFour = false;
            NightmareCount = 0;
            WorgenCount = 0;
            Phase = 0;
            NightmareTimer = 3500;
            summons.DespawnAll();
            me->SetSpeed(MOVE_RUN, 5.0f);
        }

        void NightmarePass()
        {
            NightmareCount++;

            if (NightmareCount == 1)
            {
                summons.DespawnAll();
                ShiftToTwo = true;
                Phase = 4;
                NightmareTimer = 3500;
            }

            if (NightmareCount == 2)
            {
                summons.DespawnAll();
                ShiftToThree = true;
                Phase = 9;
                NightmareTimer = 3500;
            }

            if (NightmareCount == 3)
            {
                summons.DespawnAll();
                ShiftToFour = true;
                Phase = 13;
                NightmareTimer = 3500;
            }
        }

        void WorgenKilled()
        {
            WorgenCount++;

            if (WorgenCount == 3)
                Phase = 18;

            if (WorgenCount == 6)
                Phase = 20;

            if (WorgenCount == 7)
                Phase = 23;
        }

        void JustSummoned(Creature* summoned) override
        {
            summons.Summon(summoned);
        }

        void SummonedCreatureDespawn(Creature* summon) override
        {
            summons.Despawn(summon);
        }

        void SummonAllFires()
        {
            for (uint8 i = 0; i < 4/*1*/; ++i)
                if (Creature* saFires = me->SummonCreature(NPC_FIRE_BUNNY, FieryBlaze[i], TEMPSUMMON_MANUAL_DESPAWN, 0))
                    saFires->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_REMOVE_CLIENT_CONTROL | UNIT_FLAG_NOT_SELECTABLE));
        }

        void SummonSparks()
        {
            for (uint8 i = 0; i < 7; ++i)
                if (Creature* sSp = me->SummonCreature(NPC_SPARK, ElectricSpark[i], TEMPSUMMON_MANUAL_DESPAWN, 0))
                    sSp->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_REMOVE_CLIENT_CONTROL | UNIT_FLAG_NOT_SELECTABLE));
        }

        void SummonWorgen_1()
        {
            for (uint8 i = 0; i < 3; ++i)
            me->SummonCreature(NPC_ENRAGED_WORGEN, EnragedWorgen_1[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000);
        }

        void SummonWorgen_2()
        {
            for (uint8 i = 0; i < 3; ++i)
             me->SummonCreature(NPC_ENRAGED_WORGEN, EnragedWorgen_2[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000);
        }

        void UpdateAI(uint32 diff) override
        {
            if (Nightmare)
            {
                if (NightmareTimer <= diff)
                {
                    switch (Phase)
                    {
                        case 0:
                            SummonAllFires();
                            me->Say(VANESSA_GLUB_2, LANG_UNIVERSAL);
                            NightmareTimer = 3000;
                            Phase++;
                            break;
                        case 1:
                        {
                            me->TextEmote(VANESSA_NIGHTMARE_3, 0, true);
                            NightmareTimer = 4000;
                            Phase++;
                        }
                            break;
                        case 2:
                        {
                            if (Creature* Glubtok = me->FindNearestCreature(NPC_GLUBTOK_NIGHTMARE, 200.0f, true))
                            {
                                Glubtok->SetVisible(false);
                                Glubtok->GetMotionMaster()->MoveCharge(-174.85f, -579.76f, 19.31f, 10.0f);
                            }

                            me->TextEmote(VANESSA_NIGHTMARE_4, 0, true);
                            NightmareTimer = 2000;
                            Phase++;
                        }
                            break;
                        case 3:
                            Nightmare = false;
                            me->SetVisible(false);
                            me->GetMotionMaster()->MovePoint(0, -178.85f, -585.76f, 19.31f);
                            break;
                    }
                } else NightmareTimer -= diff;
            }

            if (ShiftToTwo)
            {
                if (NightmareTimer <= diff)
                {
                    switch (Phase)
                    {
                        case 4:
                            me->SetVisible(true); me->Say(VANESSA_HELIX_1, LANG_UNIVERSAL);
                            me->SummonCreature(NPC_HELIX_NIGHTMARE, -174.85f, -579.76f, 19.31f, 3.14f, TEMPSUMMON_MANUAL_DESPAWN, 0);
                            NightmareTimer = 3000;
                            Phase++;
                            break;
                        case 5:
                            me->Say(VANESSA_HELIX_2, LANG_UNIVERSAL);
                            NightmareTimer = 10000;
                            Phase++;
                            break;
                        case 6:
                            me->TextEmote(VANESSA_NIGHTMARE_5, 0, true);
                            NightmareTimer = 1000;
                            Phase++;
                            break;
                        case 7:
                            me->TextEmote(VANESSA_NIGHTMARE_7, 0, true);
                            me->SetVisible(false);
                            NightmareTimer = 2000;
                            Phase++;
                            break;
                        case 8:
                            ShiftToTwo = false;
                            me->GetMotionMaster()->MovePoint(1, -150.96f, -579.99f, 19.31f);
                            break;
                        default:
                            break;
                    }
                } else NightmareTimer -= diff;
            }

            if (ShiftToThree)
            {
                if (NightmareTimer <= diff)
                {
                    switch (Phase)
                    {
                        case 9:
                        {
                            SummonSparks();
                            me->SetVisible(true);
                            instance->SetData(DATA_NIGHTMARE_HELIX, DONE);
                            me->Say(VANESSA_MECHANICAL_1, LANG_UNIVERSAL);
                            me->SummonCreature(NPC_MECHANICAL_NIGHTMARE, -101.4549f, -663.6493f, 7.505813f, 1.85f, TEMPSUMMON_MANUAL_DESPAWN, 0);
                            NightmareTimer = 4000;
                            Phase++;
                        }
                            break;
                        case 10:
                            me->Say(VANESSA_MECHANICAL_2, LANG_UNIVERSAL);
                            NightmareTimer = 3000;
                            Phase++;
                            break;
                        case 11:
                            me->TextEmote(VANESSA_NIGHTMARE_8, 0, true);
                            NightmareTimer = 3000;
                            Phase++;
                            break;
                        case 12:
                            ShiftToThree = false;
                            me->SetVisible(false);
                            me->GetMotionMaster()->MovePoint(2, -96.46f, -660.42f, 7.41f);
                            break;
                    }
                } else NightmareTimer -= diff;
            }

            if (ShiftToFour)
            {
                if (NightmareTimer <= diff)
                {
                    switch (Phase)
                    {
                        case 13:
                            me->SetVisible(true);
                            me->Say(VANESSA_RIPSNARL_1, LANG_UNIVERSAL);
                            NightmareTimer = 4000;
                            Phase++;
                            break;
                        case 14:
                            me->Say(VANESSA_RIPSNARL_2, LANG_UNIVERSAL);
                            NightmareTimer = 6000;
                            Phase++;
                            break;
                        case 15:
                            me->TextEmote(VANESSA_NIGHTMARE_9, 0, true);
                            instance->SetData(DATA_NIGHTMARE_MECHANICAL, DONE);
                            NightmareTimer = 2000;
                            Phase++;
                            break;
                        case 16:
                        {
                            std::list<Player*> players;
                            me->GetPlayerListInGrid(players, 150.0f);

                            for (std::list<Player*>::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                                me->CastSpell(( *itr ), SPELL_SPRINT, true);

                            me->SummonCreature(NPC_EMME_HARRINGTON, FamilySpawn[0], TEMPSUMMON_MANUAL_DESPAWN, 0);
                            me->TextEmote(VANESSA_NIGHTMARE_10, 0, true);
                            SummonWorgen_1();

                            me->SetVisible(false);
                            me->GetMotionMaster()->MovePoint(3, -103.72f, -724.06f, 8.47f);
                            Phase++;
                            NightmareTimer = 1000;

                        }
                            break;
                        case 17:
                            break;
                        case 18:
                        {
                            std::list<Player*> players;
                            me->GetPlayerListInGrid(players, 150.0f);

                            for (std::list<Player*>::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                            {
                                ( *itr )->TextEmote(VANESSA_NIGHTMARE_11, 0, true);
                                me->CastSpell(( *itr ), SPELL_SPRINT, true);
                            }

                            me->SummonCreature(NPC_ERIK_HARRINGTON, FamilySpawn[1], TEMPSUMMON_MANUAL_DESPAWN, 0);
                            SummonWorgen_2();

                            me->GetMotionMaster()->MovePoint(4, 2.56f, -776.13f, 9.52f);
                            Phase++;
                            NightmareTimer = 3000;

                        }
                            break;
                        case 19:
                            break;
                        case 20:
                        {
                            std::list<Player*> players;
                            me->GetPlayerListInGrid(players, 150.0f);

                            for (std::list<Player*>::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                            {
                                me->CastSpell(( *itr ), SPELL_SPRINT, true);
                                ( *itr )->TextEmote(VANESSA_NIGHTMARE_12, 0, true);
                            }

                            me->GetMotionMaster()->MovePoint(5, -83.16319f, -774.9636f, 26.90351f);
                            me->SummonCreature(NPC_JAMES_HARRINGTON, FamilySpawn[3], TEMPSUMMON_MANUAL_DESPAWN, 0);
                            NightmareTimer = 5000;
                            Phase++;

                        }
                            break;
                        case 21:
                            NightmareTimer = 1000;
                            Phase++;
                            break;
                        case 22:
                            break;
                        case 23:
                        {
                            std::list<Player*> players;
                            me->GetPlayerListInGrid(players, 150.0f);

                            for (std::list<Player*>::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                            {
                                ( *itr )->RemoveAurasDueToSpell(SPELL_NIGHTMARE_ELIXIR);
                                ( *itr )->RemoveAurasDueToSpell(SPELL_EFFECT_1);
                                ( *itr )->TextEmote(VANESSA_NIGHTMARE_13, 0, true);
                            }
                            me->SummonCreature(NPC_VANESSA_BOSS, -79.44965f, -819.8351f, 39.89838f, 0.01745329f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 120000);
                            if (Creature* note = me->FindNearestCreature(NPC_VANESSA_NOTE, 300.0f))
                                note->DespawnOrUnsummon(3000);
                            NightmareTimer = 1000;
                            Phase++;
                        }
                            break;
                        case 24:
                            break;
                        default:
                            break;
                    }
                } else NightmareTimer -= diff;
            }
        }
    };
};

class npc_icycle_dm : public CreatureScript
{
public:
    npc_icycle_dm() : CreatureScript("npc_icycle_dm") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_icycle_dmAI(creature);
    }

    struct npc_icycle_dmAI : public Scripted_NoMovementAI
    {
        npc_icycle_dmAI(Creature* creature) : Scripted_NoMovementAI(creature)
        {
            me->AddUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_PACIFIED));
            me->SetReactState(REACT_PASSIVE);
            me->SetDisplayId(28470);
        }

        uint32 HitTimer;

        void Reset() override
        {
            HitTimer = 2500;
        }

        void UpdateAI(uint32 diff) override
        {
            if (HitTimer <= diff)
            {
                DoCast(me, 92201);
                DoCast(me, 62453);
            } else HitTimer -= diff;
        }
    };
};

class npc_glubtok_dm : public CreatureScript
{
public:
    npc_glubtok_dm() : CreatureScript("npc_glubtok_dm") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_glubtok_dmAI(creature);
    }

    struct npc_glubtok_dmAI : public BossAI
    {
        npc_glubtok_dmAI(Creature* creature) : BossAI(creature, DATA_NIGHTMARE_MECHANICAL) { }

        uint32 FlagResetTimer;

        void Reset() override
        {
            _Reset();
            FlagResetTimer = 10000;
            events.ScheduleEvent(EVENT_ICYCLE_AOE, urand(11000, 15000));
            if (!me->GetMap()->IsHeroic() && me->FindNearestCreature(43778, 45.0f, true))
                me->DespawnOrUnsummon();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();
            events.RescheduleEvent(EVENT_ICYCLE_AOE, urand(6000, 8000));
            events.ScheduleEvent(EVENT_SPIRIT_STRIKE, 6000);
        }

        void JustDied(Unit* /*who*/) override
        {
            std::list<Player*> players;
            me->GetPlayerListInGrid(players, 150.0f);

            for (std::list<Player*>::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                ( *itr )->AddAura(SPELL_EFFECT_1, ( *itr ));

            me->TextEmote(VANESSA_NIGHTMARE_14, 0, true);

            if (Creature* Vanessa = me->FindNearestCreature(NPC_VANESSA_NIGHTMARE, 500, true))
                if (npc_vanessa_nightmare::npc_vanessa_nightmareAI* pAI = CAST_AI(npc_vanessa_nightmare::npc_vanessa_nightmareAI, Vanessa->AI()))
                    pAI->NightmarePass();

            _JustDied();

        }
        void UpdateAI(uint32 diff) override
        {
            if (FlagResetTimer <= diff)
            {
                me->SetVisible(true);
                me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC));
            } else FlagResetTimer -= diff;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_ICYCLE_AOE:
                        if (Player* pPlayer = me->SelectNearestPlayer(200.0f))
                            DoCast(pPlayer, SPELL_ICYCLE);
                        events.ScheduleEvent(EVENT_ICYCLE_AOE, urand(6000, 8000));
                        break;
                    case EVENT_SPIRIT_STRIKE:
                        DoCastVictim(SPELL_SPIRIT_STRIKE);
                        events.ScheduleEvent(EVENT_SPIRIT_STRIKE, urand(5000, 7000));
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

class npc_helix_dm : public CreatureScript
{
public:
    npc_helix_dm() : CreatureScript("npc_helix_dm") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_helix_dmAI(creature);
    }

    struct npc_helix_dmAI : public BossAI
    {
        npc_helix_dmAI(Creature* creature) : BossAI(creature, DATA_NIGHTMARE_HELIX) { }

        uint32 FlagResetTimer;

        void Reset() override
        {
            _Reset();
            FlagResetTimer = 15000;
            instance->SetData(DATA_NIGHTMARE_HELIX, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();
            events.ScheduleEvent(EVENT_SPIRIT_STRIKE, 6000);
            events.ScheduleEvent(EVENT_SPIDERS, 2000);

            me->SummonCreature(NPC_MAIN_SPIDER, NightmareSpidersSpawn[3], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000);
        }

        void JustSummoned(Creature* summoned) override
        {
            switch (summoned->GetEntry())
            {
                case NPC_NIGHTMARE_SPIDER:
                case NPC_MAIN_SPIDER:
                case NPC_CHATTERING_HORROR:
                {
                    summoned->AI()->AttackStart(me->GetVictim());
                    break;
                }
            }
            summons.Summon(summoned);
        }

        void JustDied(Unit* /*killer*/) override
        {
            std::list<Player*> players;
            me->GetPlayerListInGrid(players, 150.0f);

            for (std::list<Player*>::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                ( *itr )->AddAura(SPELL_EFFECT_1, ( *itr ));

            me->TextEmote(VANESSA_NIGHTMARE_14, 0, true);

            if (Creature *Vanessa = me->FindNearestCreature(NPC_VANESSA_NIGHTMARE, 500, true))
                if (npc_vanessa_nightmare::npc_vanessa_nightmareAI* pAI = CAST_AI(npc_vanessa_nightmare::npc_vanessa_nightmareAI, Vanessa->AI()))
                    pAI->NightmarePass();

            _JustDied();
        }

        void SummonSpiders()
        {
            for (uint8 i = 0; i < 3; ++i)
            {
                me->SummonCreature(NPC_NIGHTMARE_SPIDER, NightmareSpidersSpawn[i], TEMPSUMMON_MANUAL_DESPAWN, 0);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (FlagResetTimer <= diff)
            {
                me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC));
            } else FlagResetTimer -= diff;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SPIRIT_STRIKE:
                        DoCastVictim(SPELL_SPIRIT_STRIKE);
                        events.ScheduleEvent(EVENT_SPIRIT_STRIKE, urand(5000, 7000));
                        break;
                    case EVENT_SPIDERS:
                        SummonSpiders();
                        events.ScheduleEvent(EVENT_SPIDERS, urand(3000, 4000));
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

class npc_mechanical_dm : public CreatureScript
{
public:
    npc_mechanical_dm() : CreatureScript("npc_mechanical_dm") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_mechanical_dmAI(creature);
    }

    struct npc_mechanical_dmAI : public ScriptedAI
    {
        npc_mechanical_dmAI(Creature* creature) : ScriptedAI(creature) { }

        EventMap events;

        void Reset() override
        {
            events.Reset();
            if (!me->GetMap()->IsHeroic())
                me->DespawnOrUnsummon();
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (me->IsWithinDistInMap(who, 10) && me->IsWithinLOSInMap(who))
                EnterCombat(who);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            DoZoneInCombat();
            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC));
            me->RemoveAurasDueToSpell(SPELL_OFFLINE);
            events.ScheduleEvent(EVENT_SPIRIT_STRIKE, 6000);
        }

        void JustDied(Unit* /*killer*/) override
        {
            std::list<Player*> players;
            me->GetPlayerListInGrid(players, 150.0f);

            for (std::list<Player*>::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                ( *itr )->AddAura(SPELL_EFFECT_1, ( *itr ));

            me->TextEmote(VANESSA_NIGHTMARE_14, 0, true);

            if (Creature* Vanessa = me->FindNearestCreature(NPC_VANESSA_NIGHTMARE, 500, true))
                if (npc_vanessa_nightmare::npc_vanessa_nightmareAI* pAI = CAST_AI(npc_vanessa_nightmare::npc_vanessa_nightmareAI, Vanessa->AI()))
                    pAI->NightmarePass();
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SPIRIT_STRIKE:
                        DoCastVictim(SPELL_SPIRIT_STRIKE);
                        events.ScheduleEvent(EVENT_SPIRIT_STRIKE, urand(5000, 7000));
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

class npc_enraged_worgen_dm : public CreatureScript
{
public:
    npc_enraged_worgen_dm() : CreatureScript("npc_enraged_worgen_dm") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_enraged_worgen_dmAI(creature);
    }

    struct npc_enraged_worgen_dmAI : public ScriptedAI
    {
        npc_enraged_worgen_dmAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            if (!me->GetMap()->IsHeroic())
                me->DespawnOrUnsummon();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            DoZoneInCombat();
        }

        void JustDied(Unit* /*who*/) override
        {
            if (Creature* Vanessa = me->FindNearestCreature(NPC_VANESSA_NIGHTMARE, 500, true))
                if (npc_vanessa_nightmare::npc_vanessa_nightmareAI* pAI = CAST_AI(npc_vanessa_nightmare::npc_vanessa_nightmareAI, Vanessa->AI()))
                    pAI->WorgenKilled();
        }
    };
};

class npc_james_dm : public CreatureScript
{
public:
    npc_james_dm() : CreatureScript("npc_james_dm") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_james_dmAI(creature);
    }

    struct npc_james_dmAI : public ScriptedAI
    {
        npc_james_dmAI(Creature* creature) : ScriptedAI(creature) { }

        void JustDied(Unit* /*who*/) override
        {
            if (Creature* Vanessa = me->FindNearestCreature(NPC_VANESSA_NIGHTMARE, 500, true))
                if (npc_vanessa_nightmare::npc_vanessa_nightmareAI* pAI = CAST_AI(npc_vanessa_nightmare::npc_vanessa_nightmareAI, Vanessa->AI()))
                    pAI->WorgenKilled();

        }

        void UpdateAI(uint32 /*diff*/) override
        {
            if (!me->GetVehicleKit())
                return;

            if (Unit* Calissa = me->GetVehicleKit()->GetPassenger(0))
            {
                Calissa->CombatStart(me, true);
                Calissa->AddThreat(me, 100000.0f);
                DoZoneInCombat();
            }
        }
    };
};

class npc_lightning_orbs : public CreatureScript
{
public:
    npc_lightning_orbs() : CreatureScript("npc_lightning_orbs") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_lightning_orbsAI(creature);
    }

    struct npc_lightning_orbsAI : public Scripted_NoMovementAI
    {
        npc_lightning_orbsAI(Creature* creature) : Scripted_NoMovementAI(creature) { }

        void Reset() override
        {
            TurnTimer = 100;

            if (Vehicle* vehicle = me->GetVehicleKit())
            {
                for (uint8 i = 0; i < 8; i++)
                {
                    if (vehicle->HasEmptySeat(i))
                    {
                        if (Creature* pas = me->SummonCreature(49521, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ()))
                        {
                            pas->EnterVehicle(me, i);
                            //pas->ClearUnitState(UNIT_STATE_ON_VEHICLE);
                        }
                    }
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (TurnTimer <= diff)
            {
                me->SetFacingTo(me->GetOrientation() + 0.05233f);
                TurnTimer = 100;
            } else TurnTimer -= diff;
        }

    private:
        uint32 TurnTimer;
    };
};

class npc_rope_away : public CreatureScript
{
public:
    npc_rope_away() : CreatureScript("npc_rope_away") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_rope_awayAI(creature);
    }

    struct npc_rope_awayAI : public ScriptedAI
    {
        npc_rope_awayAI(Creature* creature) : ScriptedAI(creature)
        {
            me->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
        }

        void Reset() override
        {
            Phase = 0;
            MoveTimer = 500;
            RunAway = false;
            me->SetSpeed(MOVE_FLIGHT, 3.0f);
        }

        void MovementInform(uint32 /*type*/, uint32 id) override
        {
            if (id == 1)
                if (Unit* passenger = me->GetVehicleKit()->GetPassenger(0))
                    passenger->ExitVehicle();
        }

        void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
            {
                if (apply)
                {
                    RunAway = true;
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (RunAway)
            {
                if (MoveTimer <= diff)
                {
                    switch (Phase)
                    {
                        case 0:
                            me->GetMotionMaster()->MovePoint(0, -77.97f, -877.09f, 49.44f);
                            MoveTimer = 2500;
                            Phase++;
                            break;
                        case 1:
                            me->GetMotionMaster()->MovePoint(1, -64.02f, -839.84f, 41.22f);
                            MoveTimer = 3000;
                            Phase++;
                            break;
                        case 2:
                            break;
                    }
                } else MoveTimer -= diff;
            }
        }

    private:
        bool RunAway;
        uint8 Phase;
        uint32 MoveTimer;
    };
};

class npc_vanessa_anchor_bunny : public CreatureScript
{
public:
    npc_vanessa_anchor_bunny() : CreatureScript("npc_vanessa_anchor_bunny") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_vanessa_anchor_bunnyAI(creature);
    }

    struct npc_vanessa_anchor_bunnyAI : public ScriptedAI
    {
        npc_vanessa_anchor_bunnyAI(Creature* creature) : ScriptedAI(creature) { }

        uint32 achievementTimer;
        bool startTimerAchievement;
        bool getAchievementPlayers;

        void Reset() override
        {
            startTimerAchievement = false;
            getAchievementPlayers = true;
            achievementTimer = 300000;
        }

        void SetData(uint32 /*uiI*/, uint32 uiValue) override
        {
            if (uiValue == START_TIMER_ACHIEVEMENT && startTimerAchievement == false)
            {
                startTimerAchievement = true;
            }
            if (uiValue == ACHIEVEMENT_READY_GET && getAchievementPlayers == true && startTimerAchievement == true)
            {
                Map* map = me->GetMap();
                AchievementEntry const* vigorous_vancleef_vindicator = sAchievementStore.LookupEntry(ACHIEVEMENT_VIGOROUS_VANCLEEF_VINDICATOR);

                if (map && map->IsDungeon() && map->GetDifficultyID() == DIFFICULTY_HEROIC)
                {
                    Map::PlayerList const& players = map->GetPlayers();
                    if (!players.isEmpty())
                    {
                        for (Map::PlayerList::const_iterator i = players.begin(); i != players.end(); ++i)
                        {
                            if (Player* player = i->GetSource())
                            {
                                if (player->GetDistance(me) < 200.0f)
                                {
                                    player->CompletedAchievement(vigorous_vancleef_vindicator);
                                }
                            }
                        }
                    }
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (startTimerAchievement == true && getAchievementPlayers == true)
            {
                if (achievementTimer <= diff)
                {
                    getAchievementPlayers = false;
                } else achievementTimer -= diff;
            }
        }
    };
};

void AddSC_boss_vanessa_vancleef()
{
    new boss_vanessa_vancleef();
    new npc_rope_ship();
    new npc_vanessa_intro();
    new npc_note();
    new npc_magma_pull();
    new npc_vanessa_nightmare();
    new npc_icycle_dm();
    new npc_glubtok_dm();
    new npc_helix_dm();
    new npc_mechanical_dm();
    new npc_enraged_worgen_dm();
    new npc_james_dm();
    new npc_rope_away();
    new npc_defias_shadowguard();
    new npc_defias_enforcer();
    new npc_defias_bloodwizard();
    new npc_defias_envoker();
    new npc_oaf_lackey();
    new npc_goblin_overseer();
    new npc_ogre_henchman();
    new npc_lightning_orbs();
    new npc_vanessa_anchor_bunny();
}
