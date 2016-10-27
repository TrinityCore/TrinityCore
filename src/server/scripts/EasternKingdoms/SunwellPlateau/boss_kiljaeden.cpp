/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

/* ScriptData
SDName: Boss_Kiljaeden
SD%Complete: 80
SDComment: Sinister Reflection Model, Armageddon Visual, SAY_KJ_SHADOWSPIKE3, Emote, End Sequence
SDCategory: Sunwell_Plateau
EndScriptData */

/// @todo rewrite Armageddon

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "sunwell_plateau.h"
#include <math.h>
#include "Player.h"

/*** Speech and sounds***/
enum Yells
{
    SAY_KJ_OFFCOMBAT                            = 0,

    SAY_KALECGOS_ENCOURAGE                      = 0,
    SAY_KALECGOS_READY1                         = 1,
    SAY_KALECGOS_READY2                         = 2,
    SAY_KALECGOS_READY3                         = 3,
    SAY_KALECGOS_READY4                         = 4,
    SAY_KALECGOS_AWAKEN                         = 5,
    SAY_KALECGOS_LETGO                          = 6,
    SAY_KALECGOS_FOCUS                          = 7,
    SAY_KALECGOS_FATE                           = 8,
    SAY_KALECGOS_GOODBYE                        = 9,
    SAY_KALECGOS_JOIN                           = 10,

    SAY_KJ_DEATH                                = 0,
    SAY_KJ_SLAY                                 = 1,
    SAY_KJ_REFLECTION                           = 2,
    SAY_KJ_EMERGE                               = 3,
    SAY_KJ_DARKNESS                             = 4,
    SAY_KJ_PHASE3                               = 5,
    SAY_KJ_PHASE4                               = 6,
    SAY_KJ_PHASE5                               = 7,
    EMOTE_KJ_DARKNESS                           = 8,

    SAY_ANVEENA_IMPRISONED                      = 0,
    SAY_ANVEENA_LOST                            = 1,
    SAY_ANVEENA_KALEC                           = 2,
    SAY_ANVEENA_GOODBYE                         = 3
};

/*** Spells used during the encounter ***/
enum Spells
{
    /* Hand of the Deceiver's spells and cosmetics */
    SPELL_SHADOW_BOLT_VOLLEY                    = 45770, // ~30 yard range Shadow Bolt Volley for ~2k(?) damage
    SPELL_SHADOW_INFUSION                       = 45772, // They gain this at 20% - Immunity to Stun/Silence and makes them look angry!
    SPELL_FELFIRE_PORTAL                        = 46875, // Creates a portal that spawns Felfire Fiends (LIVE FOR THE SWARM!1 FOR THE OVERMIND!)
    SPELL_SHADOW_CHANNELING                     = 46757, // Channeling animation out of combat

    /* Volatile Felfire Fiend's spells */
    SPELL_FELFIRE_FISSION                       = 45779, // Felfire Fiends explode when they die or get close to target.

    /* Kil'Jaeden's spells and cosmetics */
    SPELL_TRANS                                 = 23188, // Surprisingly, this seems to be the right spell.. (Where is it used?)
    SPELL_REBIRTH                               = 44200, // Emerge from the Sunwell
    SPELL_SOUL_FLAY                             = 45442, // 9k Shadow damage over 3 seconds. Spammed throughout all the fight.
    SPELL_SOUL_FLAY_SLOW                        = 47106,
    SPELL_LEGION_LIGHTNING                      = 45664, // Chain Lightning, 4 targets, ~3k Shadow damage, 1.5fk mana burn
    SPELL_FIRE_BLOOM                            = 45641, // Places a debuff on 5 raid members, which causes them to deal 2k Fire damage to nearby allies and selves. MIGHT NOT WORK
    SPELL_DESTROY_ALL_DRAKES                    = 46707, // when he use it?

    SPELL_SINISTER_REFLECTION                   = 45785, // Summon shadow copies of 5 raid members that fight against KJ's enemies//dont work
                                                //  45892  // right one for SPELL_SINISTER_REFLECTION but no EffectScriptEffect
    SPELL_COPY_WEAPON                           = 41055, // }
    SPELL_COPY_WEAPON2                          = 41054, // }
    SPELL_COPY_OFFHAND                          = 45206, // }- Spells used in Sinister Reflection creation
    SPELL_COPY_OFFHAND_WEAPON                   = 45205, // }

    SPELL_SHADOW_SPIKE                          = 46680, // Bombard random raid members with Shadow Spikes (Very similar to Void Reaver orbs)
    SPELL_FLAME_DART                            = 45737, // Bombards the raid with flames every 3(?) seconds
    SPELL_DARKNESS_OF_A_THOUSAND_SOULS          = 46605, // Begins a 8-second channeling, after which he will deal 50'000 damage to the raid
    SPELL_DARKNESS_OF_A_THOUSAND_SOULS_DAMAGE   = 45657,

    /* Armageddon spells wrong visual */
    SPELL_ARMAGEDDON_TRIGGER                    = 45909, // Meteor spell trigger missile should cast Creature on himself
    SPELL_ARMAGEDDON_VISUAL                     = 45911, // Does the hellfire visual to indicate where the meteor missle lands
    SPELL_ARMAGEDDON_VISUAL2                    = 45914, // Does the light visual to indicate where the meteor missle lands
    SPELL_ARMAGEDDON_VISUAL3                    = 24207, // This shouldn't correct but same as seen on the movie
    SPELL_ARMAGEDDON_SUMMON_TRIGGER             = 45921, // Summons the triggers that cast the spells on himself need random target select
    SPELL_ARMAGEDDON_DAMAGE                     = 45915, // This does the area damage

    /* Shield Orb Spells*/
    SPELL_SHADOW_BOLT                           = 45680, //45679 would be correct but triggers to often /// @todo fix console error

    /* Anveena's spells and cosmetics (Or, generally, everything that has "Anveena" in name) */
    SPELL_ANVEENA_PRISON                        = 46367, // She hovers locked within a bubble
    SPELL_ANVEENA_ENERGY_DRAIN                  = 46410, // Sunwell energy glow animation (Control mob uses this)
    SPELL_SACRIFICE_OF_ANVEENA                  = 46474, // This is cast on Kil'Jaeden when Anveena sacrifices herself into the Sunwell

    /* Sinister Reflection Spells */
    SPELL_SR_CURSE_OF_AGONY                     = 46190,
    SPELL_SR_SHADOW_BOLT                        = 47076,

    SPELL_SR_EARTH_SHOCK                        = 47071,

    SPELL_SR_FIREBALL                           = 47074,

    SPELL_SR_HEMORRHAGE                         = 45897,

    SPELL_SR_HOLY_SHOCK                         = 38921,
    SPELL_SR_HAMMER_OF_JUSTICE                  = 37369,

    SPELL_SR_HOLY_SMITE                         = 47077,
    SPELL_SR_RENEW                              = 47079,

    SPELL_SR_SHOOT                              = 16496,
    SPELL_SR_MULTI_SHOT                         = 48098,
    SPELL_SR_WING_CLIP                          = 40652,

    SPELL_SR_WHIRLWIND                          = 17207,

    SPELL_SR_MOONFIRE                           = 47072,
    //SPELL_SR_PLAGU STRIKE                       = 58843, Dk Spell!

    /*** Other Spells (used by players, etc) ***/
    SPELL_VENGEANCE_OF_THE_BLUE_FLIGHT          = 45839, // Possess the blue dragon from the orb to help the raid.
    SPELL_ENTROPIUS_BODY                        = 46819, // Visual for Entropius at the Epilogue
    SPELL_RING_OF_BLUE_FLAMES                   = 45825  //Cast this spell when the go is activated
};

/*** Others ***/
#define SHIELD_ORB_Z    45.000f

enum Phase
{
    PHASE_DECEIVERS     = 1, // Fight 3 adds
    PHASE_NORMAL        = 2, // Kil'Jaeden emerges from the sunwell
    PHASE_DARKNESS      = 3, // At 85%, he gains few abilities; Kalecgos joins the fight
    PHASE_ARMAGEDDON    = 4, // At 55%, he gains even more abilities
    PHASE_SACRIFICE     = 5  // At 25%, Anveena sacrifices herself into the Sunwell; at this point he becomes enraged and has *significally* shorter cooldowns.
};

//Timers
enum KilJaedenTimers
{
    TIMER_SPEECH           = 0,

    //Phase 2 Timer
    TIMER_SOUL_FLAY        = 1,
    TIMER_LEGION_LIGHTNING = 2,
    TIMER_FIRE_BLOOM       = 3,
    TIMER_SUMMON_SHILEDORB = 4,

    //Phase 3 Timer
    TIMER_SHADOW_SPIKE     = 5,
    TIMER_FLAME_DART       = 6,
    TIMER_DARKNESS         = 7,
    TIMER_ORBS_EMPOWER     = 8,

    //Phase 4 Timer
    TIMER_ARMAGEDDON       = 9
};

// Locations of the Hand of Deceiver adds
Position DeceiverLocations[3]=
{
    {1682.045f, 631.299f, 5.936f, 0.0f},
    {1684.099f, 618.848f, 0.589f, 0.0f},
    {1694.170f, 612.272f, 1.416f, 0.0f}
};

// Locations, where Shield Orbs will spawn
float ShieldOrbLocations[4][2]=
{
    {1698.900f, 627.870f},    // middle pont of Sunwell
    {12, 3.14f},             // First one spawns northeast of KJ
    {12, 3.14f/0.7f},         // Second one spawns southeast
    {12, 3.14f*3.8f}          // Third one spawns (?)
};

struct Speech
{
    int32 textid;
    uint32 creature, timer;
};

// Timers
static Speech Speeches[]=
{
    //Kil Phase 1 -> Phase 2
    {SAY_KJ_EMERGE,             DATA_KILJAEDEN,     0},
    {SAY_KALECGOS_JOIN,         DATA_KALECGOS_KJ,   26000},
    //Kil Phase 2 -> Phase 3
    {SAY_KALECGOS_AWAKEN,       DATA_KALECGOS_KJ,   10000},
    {SAY_ANVEENA_IMPRISONED,    DATA_ANVEENA,       5000},
    {SAY_KJ_PHASE3,             DATA_KILJAEDEN,     5000},
    //Kil Phase 3 -> Phase 4
    {SAY_KALECGOS_LETGO,        DATA_KALECGOS_KJ,   10000},
    {SAY_ANVEENA_LOST,          DATA_ANVEENA,       8000},
    {SAY_KJ_PHASE4,             DATA_KILJAEDEN,     7000},
    //Kil Phase 4 -> Phase 5
    {SAY_KALECGOS_FOCUS,        DATA_KALECGOS_KJ,   4000},
    {SAY_ANVEENA_KALEC,         DATA_ANVEENA,       11000},
    {SAY_KALECGOS_FATE,         DATA_KALECGOS_KJ,   2000},
    {SAY_ANVEENA_GOODBYE,       DATA_ANVEENA,       6000},
    {SAY_KJ_PHASE5,             DATA_KILJAEDEN,     5500},

    // use in End sequence?
    {SAY_KALECGOS_GOODBYE,      DATA_KALECGOS_KJ,   12000}
};

//AI for Kalecgos
class boss_kalecgos_kj : public CreatureScript
{
public:
    boss_kalecgos_kj() : CreatureScript("boss_kalecgos_kj") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<boss_kalecgos_kjAI>(creature);
    }

    struct boss_kalecgos_kjAI : public ScriptedAI
    {
        boss_kalecgos_kjAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            instance = creature->GetInstanceScript();
        }

        void Initialize()
        {
            OrbsEmpowered = 0;
            EmpowerCount = 0;
        }

        InstanceScript* instance;
        uint8 OrbsEmpowered;
        uint8 EmpowerCount;

        void Reset() override
        {
            Initialize();
            me->SetDisableGravity(true);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->setActive(true);

            for (uint8 i = 0; i < 4; ++i)
                if (GameObject* pOrb = GetOrb(i))
                    pOrb->SetGoType(GAMEOBJECT_TYPE_BUTTON);
        }

        GameObject* GetOrb(int32 index)
        {
            switch (index)
            {
                case 0:
                    return ObjectAccessor::GetGameObject(*me, instance->GetGuidData(DATA_ORB_OF_THE_BLUE_DRAGONFLIGHT_1));
                case 1:
                    return ObjectAccessor::GetGameObject(*me, instance->GetGuidData(DATA_ORB_OF_THE_BLUE_DRAGONFLIGHT_2));
                case 2:
                    return ObjectAccessor::GetGameObject(*me, instance->GetGuidData(DATA_ORB_OF_THE_BLUE_DRAGONFLIGHT_3));
                case 3:
                    return ObjectAccessor::GetGameObject(*me, instance->GetGuidData(DATA_ORB_OF_THE_BLUE_DRAGONFLIGHT_4));
            }

            return NULL;
        }

        void ResetOrbs()
        {
            me->RemoveDynObject(SPELL_RING_OF_BLUE_FLAMES);
            for (uint8 i = 0; i < 4; ++i)
                if (GameObject* pOrb = GetOrb(i))
                    pOrb->SetUInt32Value(GAMEOBJECT_FACTION, 0);
        }

        void EmpowerOrb(bool all)
        {
            GameObject* pOrbEmpowered = GetOrb(OrbsEmpowered);
            if (!pOrbEmpowered)
                return;

            if (all)
            {
                me->RemoveDynObject(SPELL_RING_OF_BLUE_FLAMES);
                for (uint8 i = 0; i < 4; ++i)
                {
                    if (GameObject* pOrb = GetOrb(i))
                    {
                        pOrb->CastSpell(me, SPELL_RING_OF_BLUE_FLAMES);
                        pOrb->SetUInt32Value(GAMEOBJECT_FACTION, 35);
                        pOrb->setActive(true);
                        pOrb->Refresh();
                    }
                }
                Talk(SAY_KALECGOS_ENCOURAGE);
            }
            else
            {
                if (GameObject* pOrb = GetOrb(urand(0, 3)))
                {
                    pOrb->CastSpell(me, SPELL_RING_OF_BLUE_FLAMES);
                    pOrb->SetUInt32Value(GAMEOBJECT_FACTION, 35);
                    pOrb->setActive(true);
                    pOrb->Refresh();

                    OrbsEmpowered = (OrbsEmpowered+1)%4;

                    ++EmpowerCount;
                    switch (EmpowerCount)
                    {
                        case 1: Talk(SAY_KALECGOS_READY1); break;
                        case 2: Talk(SAY_KALECGOS_READY2); break;
                        case 3: Talk(SAY_KALECGOS_READY3); break;
                        case 4: Talk(SAY_KALECGOS_READY4); break;
                    }
                }
            }
        }

        void UpdateAI(uint32 /*diff*/) override
        {
        }

        void SetRingOfBlueFlames()
        {
            me->RemoveDynObject(SPELL_RING_OF_BLUE_FLAMES);
            for (uint8 i = 0; i < 4; ++i)
            {
                if (GameObject* pOrb = GetOrb(i))
                {
                    if (pOrb->GetUInt32Value(GAMEOBJECT_FACTION) == 35)
                    {
                        pOrb->CastSpell(me, SPELL_RING_OF_BLUE_FLAMES);
                        pOrb->setActive(true);
                        pOrb->Refresh();
                    }
                }
            }
        }
    };
};

class go_orb_of_the_blue_flight : public GameObjectScript
{
public:
    go_orb_of_the_blue_flight() : GameObjectScript("go_orb_of_the_blue_flight") { }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        if (go->GetUInt32Value(GAMEOBJECT_FACTION) == 35)
        {
            InstanceScript* instance = go->GetInstanceScript();
            player->SummonCreature(NPC_POWER_OF_THE_BLUE_DRAGONFLIGHT, player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(), 0.0f, TEMPSUMMON_TIMED_DESPAWN, 121000);
            player->CastSpell(player, SPELL_VENGEANCE_OF_THE_BLUE_FLIGHT, false);
            go->SetUInt32Value(GAMEOBJECT_FACTION, 0);

            if (Creature* pKalec = ObjectAccessor::GetCreature(*player, instance->GetGuidData(DATA_KALECGOS_KJ)))
                ENSURE_AI(boss_kalecgos_kj::boss_kalecgos_kjAI, pKalec->AI())->SetRingOfBlueFlames();

            go->Refresh();
        }
        return true;
    }
};

//AI for Kil'jaeden Event Controller
class npc_kiljaeden_controller : public CreatureScript
{
public:
    npc_kiljaeden_controller() : CreatureScript("npc_kiljaeden_controller") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<npc_kiljaeden_controllerAI>(creature);
    }

    struct npc_kiljaeden_controllerAI : public ScriptedAI
    {
        npc_kiljaeden_controllerAI(Creature* creature) : ScriptedAI(creature), summons(me)
        {
            Initialize();
            instance = creature->GetInstanceScript();

            SetCombatMovement(false);
        }

        void Initialize()
        {
            phase = PHASE_DECEIVERS;
            deceiverDeathCount = 0;
            bSummonedDeceivers = false;
            bKiljaedenDeath = false;
            uiRandomSayTimer = 30000;
        }

        InstanceScript* instance;
        SummonList summons;

        bool bSummonedDeceivers;
        bool bKiljaedenDeath;

        uint32 uiRandomSayTimer;
        uint32 phase;
        uint8 deceiverDeathCount;

        void InitializeAI() override
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->AddUnitState(UNIT_STATE_STUNNED);

            ScriptedAI::InitializeAI();
        }

        void Reset() override
        {
            Initialize();

            if (Creature* pKalecKJ = ObjectAccessor::GetCreature((*me), instance->GetGuidData(DATA_KALECGOS_KJ)))
                ENSURE_AI(boss_kalecgos_kj::boss_kalecgos_kjAI, pKalecKJ->AI())->ResetOrbs();
            summons.DespawnAll();
        }

        void JustSummoned(Creature* summoned) override
        {
            switch (summoned->GetEntry())
            {
                case NPC_HAND_OF_THE_DECEIVER:
                    summoned->CastSpell(summoned, SPELL_SHADOW_CHANNELING, false);
                    break;
                case NPC_ANVEENA:
                    summoned->SetDisableGravity(true);
                    summoned->CastSpell(summoned, SPELL_ANVEENA_PRISON, true);
                    summoned->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    break;
                case NPC_KILJAEDEN:
                    summoned->CastSpell(summoned, SPELL_REBIRTH, false);
                    summoned->AddThreat(me->GetVictim(), 1.0f);
                    break;
            }
            summons.Summon(summoned);
        }

        void UpdateAI(uint32 diff) override
        {
            if (uiRandomSayTimer < diff)
            {
                if (instance->GetBossState(DATA_MURU) != DONE && instance->GetBossState(DATA_KILJAEDEN) == NOT_STARTED)
                    Talk(SAY_KJ_OFFCOMBAT);
                uiRandomSayTimer = 30000;
            } else uiRandomSayTimer -= diff;

            if (!bSummonedDeceivers)
            {
                for (uint8 i = 0; i < 3; ++i)
                    me->SummonCreature(NPC_HAND_OF_THE_DECEIVER, DeceiverLocations[i], TEMPSUMMON_DEAD_DESPAWN, 0);

                DoSpawnCreature(NPC_ANVEENA,  0, 0, 40, 0, TEMPSUMMON_DEAD_DESPAWN, 0);
                DoCast(me, SPELL_ANVEENA_ENERGY_DRAIN);
                bSummonedDeceivers = true;
            }

            if (deceiverDeathCount > 2 && phase == PHASE_DECEIVERS)
            {
                me->RemoveAurasDueToSpell(SPELL_ANVEENA_ENERGY_DRAIN);
                phase = PHASE_NORMAL;
                DoSpawnCreature(NPC_KILJAEDEN, 0, 0, 0, 0, TEMPSUMMON_MANUAL_DESPAWN, 0);
            }
        }
    };
};

//AI for Kil'jaeden
class boss_kiljaeden : public CreatureScript
{
public:
    boss_kiljaeden() : CreatureScript("boss_kiljaeden") { }

    struct boss_kiljaedenAI : public ScriptedAI
    {
        boss_kiljaedenAI(Creature* creature) : ScriptedAI(creature), summons(me)
        {
            Initialize();
            instance = creature->GetInstanceScript();
            speechPhaseEnd = 0;

            SetCombatMovement(false);
        }

        void Initialize()
        {
            TimerIsDeactivated[TIMER_SPEECH] = false;
            Timer[TIMER_SPEECH] = 0;

            //Phase 2 Timer
            Timer[TIMER_SOUL_FLAY] = 11000;
            Timer[TIMER_LEGION_LIGHTNING] = 30000;
            Timer[TIMER_FIRE_BLOOM] = 20000;
            Timer[TIMER_SUMMON_SHILEDORB] = 35000;

            //Phase 3 Timer
            Timer[TIMER_SHADOW_SPIKE] = 4000;
            Timer[TIMER_FLAME_DART] = 3000;
            Timer[TIMER_DARKNESS] = 45000;
            Timer[TIMER_ORBS_EMPOWER] = 35000;

            //Phase 4 Timer
            Timer[TIMER_ARMAGEDDON] = 2000;

            ActiveTimers = 5;
            WaitTimer = 0;
            speechCount = 0;
            SpeechTimer = 0;

            Phase = PHASE_NORMAL;

            IsInDarkness = false;
            IsWaiting = false;
            OrbActivated = false;
            SpeechBegins = true;

            ChangeTimers(false, 0);
        }

        InstanceScript* instance;
        SummonList summons;

        uint8 Phase;
        uint8 ActiveTimers;
        uint32 SpeechTimer;

        uint32 Timer[10];
        uint32 WaitTimer;
        uint8 speechCount;
        uint8 speechPhaseEnd;

        /* Boolean */
        bool IsInDarkness;
        bool TimerIsDeactivated[10];
        bool IsWaiting;
        bool OrbActivated;
        bool SpeechBegins;

        void InitializeAI() override
        {
            // Scripted_NoMovementAI::InitializeAI();
        }

        void Reset() override
        {
            Initialize();

            if (Creature* pKalec = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_KALECGOS_KJ)))
                pKalec->RemoveDynObject(SPELL_RING_OF_BLUE_FLAMES);

            me->SetFloatValue(UNIT_FIELD_COMBATREACH, 12);
            summons.DespawnAll();
        }

        void ChangeTimers(bool status, uint32 WTimer)
        {
            for (uint8 i = 1; i < ActiveTimers; ++i)
                TimerIsDeactivated[i] = status;

            if (WTimer > 0)
            {
                IsWaiting = true;
                WaitTimer = WTimer;
            }

            if (OrbActivated)
                TimerIsDeactivated[TIMER_ORBS_EMPOWER] = true;
            if (Timer[TIMER_SHADOW_SPIKE] == 0)
                TimerIsDeactivated[TIMER_SHADOW_SPIKE] = true;
            if (Phase == PHASE_SACRIFICE)
                TimerIsDeactivated[TIMER_SUMMON_SHILEDORB] = true;
        }

        void JustSummoned(Creature* summoned) override
        {
            if (summoned->GetEntry() == NPC_ARMAGEDDON_TARGET)
            {
                summoned->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                summoned->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        //      summoned->SetVisibility(VISIBILITY_OFF);  //with this we cant see the armageddon visuals
            }
            else
                summoned->SetLevel(me->getLevel());

            summoned->setFaction(me->getFaction());
            summons.Summon(summoned);
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_KJ_DEATH);
            summons.DespawnAll();
            instance->SetBossState(DATA_KILJAEDEN, DONE);
        }

        void KilledUnit(Unit* /*victim*/) override
        {
            Talk(SAY_KJ_SLAY);
        }

        void EnterEvadeMode(EvadeReason why) override
        {
            ScriptedAI::EnterEvadeMode(why);

            summons.DespawnAll();

            // Reset the controller
            if (Creature* pControl = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_KILJAEDEN_CONTROLLER)))
                ENSURE_AI(npc_kiljaeden_controller::npc_kiljaeden_controllerAI, pControl->AI())->Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            DoZoneInCombat();
        }

        void EnterNextPhase()
        {
            SpeechBegins  = true;
            OrbActivated  = false;
            ChangeTimers(true, 0);//stop every cast Shadow spike will reactivate em all
            TimerIsDeactivated[TIMER_SHADOW_SPIKE] = false;
            Timer[TIMER_SHADOW_SPIKE]     = 100;
            // empowered orbs before darkness
            Timer[TIMER_DARKNESS] = (Phase == PHASE_SACRIFICE) ? 15000 : urand(10000, 40000);
            Timer[TIMER_ORBS_EMPOWER] = (Phase == PHASE_SACRIFICE) ? 10000 : 5000;
        }

        void CastSinisterReflection()
        {
            Talk(SAY_KJ_REFLECTION);
            for (uint8 i = 0; i < 4; ++i)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true, -SPELL_VENGEANCE_OF_THE_BLUE_FLIGHT))
                {
                    float x, y, z;
                    target->GetPosition(x, y, z);
                    if (Creature* pSinisterReflection = me->SummonCreature(NPC_SINISTER_REFLECTION, x, y, z, 0, TEMPSUMMON_CORPSE_DESPAWN, 0))
                    {
                        pSinisterReflection->SetDisplayId(target->GetDisplayId());
                        pSinisterReflection->AI()->AttackStart(target);
                    }
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim() || Phase < PHASE_NORMAL)
                return;

            if (IsWaiting)
            {
                if (WaitTimer <= diff)
                {
                    IsWaiting = false;
                    ChangeTimers(false, 0);
                } else WaitTimer -= diff;
            }

            for (uint8 t = 0; t < ActiveTimers; ++t)
            {
                if (Timer[t] < diff && !TimerIsDeactivated[t])
                {
                    switch (t)
                    {
                        case TIMER_SPEECH:
                            if (SpeechBegins)
                            {
                                SpeechBegins=false;
                                switch (Phase)
                                {
                                    case PHASE_NORMAL:
                                        speechPhaseEnd=1;
                                        break;
                                    case PHASE_DARKNESS:
                                        speechPhaseEnd=4;
                                        break;
                                    case PHASE_ARMAGEDDON:
                                        speechPhaseEnd=7;
                                        break;
                                    case PHASE_SACRIFICE:
                                        speechPhaseEnd=12;
                                        break;
                                }
                            }
                            if (Speeches[speechCount].timer < SpeechTimer)
                            {
                                SpeechTimer = 0;
                                if (Creature* speechCreature = ObjectAccessor::GetCreature(*me, instance->GetGuidData(Speeches[speechCount].creature)))
                                    speechCreature->AI()->Talk(Speeches[speechCount].textid);
                                if (speechCount == 12)
                                    if (Creature* pAnveena =  ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_ANVEENA)))
                                        pAnveena->CastSpell(me, SPELL_SACRIFICE_OF_ANVEENA, false);
                                //   ChangeTimers(true, 10000); // Kil should do an emote while screaming without attacking for 10 seconds
                                if (speechCount == speechPhaseEnd)
                                    TimerIsDeactivated[TIMER_SPEECH]=true;
                                speechCount++;
                            }
                            SpeechTimer += diff;
                            break;
                        case TIMER_SOUL_FLAY:
                            if (!me->IsNonMeleeSpellCast(false))
                            {
                                DoCastVictim(SPELL_SOUL_FLAY_SLOW, false);
                                DoCastVictim(SPELL_SOUL_FLAY, false);
                                Timer[TIMER_SOUL_FLAY] = 3500;
                            }
                            break;
                        case TIMER_LEGION_LIGHTNING:
                            if (!me->IsNonMeleeSpellCast(false))
                            {
                                Unit* pRandomPlayer = NULL;

                                me->RemoveAurasDueToSpell(SPELL_SOUL_FLAY);
                                for (uint8 z = 0; z < 6; ++z)
                                {
                                    pRandomPlayer = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true);
                                    if (!pRandomPlayer || !pRandomPlayer->HasAura(SPELL_VENGEANCE_OF_THE_BLUE_FLIGHT))
                                        break;
                                }

                                if (pRandomPlayer)
                                    DoCast(pRandomPlayer, SPELL_LEGION_LIGHTNING, false);
                                else
                                    TC_LOG_ERROR("scripts", "try to cast SPELL_LEGION_LIGHTNING on invalid target");

                                Timer[TIMER_LEGION_LIGHTNING] = (Phase == PHASE_SACRIFICE) ? 18000 : 30000; // 18 seconds in PHASE_SACRIFICE
                                Timer[TIMER_SOUL_FLAY] = 2500;
                            }
                            break;
                        case TIMER_FIRE_BLOOM:
                            if (!me->IsNonMeleeSpellCast(false))
                            {
                                me->RemoveAurasDueToSpell(SPELL_SOUL_FLAY);
                                DoCastAOE(SPELL_FIRE_BLOOM, false);
                                Timer[TIMER_FIRE_BLOOM] = (Phase == PHASE_SACRIFICE) ? 25000 : 40000; // 25 seconds in PHASE_SACRIFICE
                                Timer[TIMER_SOUL_FLAY] = 1000;
                            }
                            break;
                        case TIMER_SUMMON_SHILEDORB:
                            for (uint8 i = 1; i < Phase; ++i)
                            {
                                float sx, sy;
                                sx = ShieldOrbLocations[0][0] + std::sin(ShieldOrbLocations[i][0]);
                                sy = ShieldOrbLocations[0][1] + std::sin(ShieldOrbLocations[i][1]);
                                me->SummonCreature(NPC_SHIELD_ORB, sx, sy, SHIELD_ORB_Z, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 45000);
                            }
                            Timer[TIMER_SUMMON_SHILEDORB] = urand(30000, 60000); // 30-60seconds cooldown
                            Timer[TIMER_SOUL_FLAY] = 2000;
                            break;
                        case TIMER_SHADOW_SPIKE: //Phase 3
                            if (!me->IsNonMeleeSpellCast(false))
                            {
                                CastSinisterReflection();
                                DoCastAOE(SPELL_SHADOW_SPIKE, false);
                                ChangeTimers(true, 30000);
                                Timer[TIMER_SHADOW_SPIKE] = 0;
                                TimerIsDeactivated[TIMER_SPEECH] = false;
                            }
                            break;
                        case TIMER_FLAME_DART: //Phase 3
                            DoCastAOE(SPELL_FLAME_DART, false);
                            Timer[TIMER_FLAME_DART] = 3000; /// @todo Timer
                            break;
                        case TIMER_DARKNESS: //Phase 3
                            if (!me->IsNonMeleeSpellCast(false))
                            {
                                // Begins to channel for 8 seconds, then deals 50'000 damage to all raid members.
                                if (!IsInDarkness)
                                {
                                    Talk(EMOTE_KJ_DARKNESS);
                                    DoCastAOE(SPELL_DARKNESS_OF_A_THOUSAND_SOULS, false);
                                    ChangeTimers(true, 9000);
                                    Timer[TIMER_DARKNESS] = 8750;
                                    TimerIsDeactivated[TIMER_DARKNESS] = false;
                                    if (Phase == PHASE_SACRIFICE)
                                        TimerIsDeactivated[TIMER_ARMAGEDDON] = false;
                                    IsInDarkness = true;
                                }
                                else
                                {
                                    Timer[TIMER_DARKNESS] = (Phase == PHASE_SACRIFICE) ? 15000 : urand(40000, 70000);
                                    IsInDarkness = false;
                                    DoCastAOE(SPELL_DARKNESS_OF_A_THOUSAND_SOULS_DAMAGE);
                                    Talk(SAY_KJ_DARKNESS);
                                }
                                Timer[TIMER_SOUL_FLAY] = 9000;
                            }
                            break;
                        case TIMER_ORBS_EMPOWER: //Phase 3
                            if (Creature* pKalec = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_KALECGOS_KJ)))
                            {
                                switch (Phase)
                                {
                                    case PHASE_SACRIFICE:
                                        ENSURE_AI(boss_kalecgos_kj::boss_kalecgos_kjAI, pKalec->AI())->EmpowerOrb(true);
                                        break;
                                    default:
                                        ENSURE_AI(boss_kalecgos_kj::boss_kalecgos_kjAI, pKalec->AI())->EmpowerOrb(false);
                                        break;
                                }
                            }
                            OrbActivated = true;
                            TimerIsDeactivated[TIMER_ORBS_EMPOWER] = true;
                            break;
                        case TIMER_ARMAGEDDON: //Phase 4
                            Unit* target = NULL;
                            for (uint8 z = 0; z < 6; ++z)
                            {
                                target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true);
                                if (!target || !target->HasAura(SPELL_VENGEANCE_OF_THE_BLUE_FLIGHT)) break;
                            }
                            if (target)
                            {
                                float x, y, z;
                                target->GetPosition(x, y, z);
                                me->SummonCreature(NPC_ARMAGEDDON_TARGET, x, y, z, 0, TEMPSUMMON_TIMED_DESPAWN, 15000);
                            }
                            Timer[TIMER_ARMAGEDDON] = 2000; // No, I'm not kidding
                            break;
                     }
                }
            }
            DoMeleeAttackIfReady();
            //Time runs over!
            for (uint8 i = 0; i < ActiveTimers; ++i)
                if (!TimerIsDeactivated[i])
                {
                    Timer[i] -= diff;
                    if (((int32)Timer[i]) < 0) Timer[i] = 0;
                }

            //Phase 3
            if (Phase <= PHASE_NORMAL && !IsInDarkness)
            {
                if (Phase == PHASE_NORMAL && HealthBelowPct(85))
                {
                    Phase = PHASE_DARKNESS;
                    ActiveTimers = 9;
                    EnterNextPhase();
                }
                else return;
            }

            //Phase 4
            if (Phase <= PHASE_DARKNESS && !IsInDarkness)
            {
                if (Phase == PHASE_DARKNESS && HealthBelowPct(55))
                {
                    Phase = PHASE_ARMAGEDDON;
                    ActiveTimers = 10;
                    EnterNextPhase();
                }
                else return;
            }

            //Phase 5 specific spells all we can
            if (Phase <= PHASE_ARMAGEDDON && !IsInDarkness)
            {
                if (Phase == PHASE_ARMAGEDDON && HealthBelowPct(25))
                {
                    Phase = PHASE_SACRIFICE;
                    EnterNextPhase();
                }
                else return;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetSunwellPlateauAI<boss_kiljaedenAI>(creature);
    }
};

//AI for Hand of the Deceiver
class npc_hand_of_the_deceiver : public CreatureScript
{
public:
    npc_hand_of_the_deceiver() : CreatureScript("npc_hand_of_the_deceiver") { }

    struct npc_hand_of_the_deceiverAI : public ScriptedAI
    {
        npc_hand_of_the_deceiverAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            instance = creature->GetInstanceScript();
        }

        void Initialize()
        {
            /// @todo Timers!
            ShadowBoltVolleyTimer = urand(8000, 14000); // So they don't all cast it in the same moment.
            FelfirePortalTimer = 20000;
        }

        InstanceScript* instance;

        uint32 ShadowBoltVolleyTimer;
        uint32 FelfirePortalTimer;

        void Reset() override
        {
            Initialize();
            instance->SetBossState(DATA_KILJAEDEN, NOT_STARTED);
        }

        void JustSummoned(Creature* summoned) override
        {
            summoned->setFaction(me->getFaction());
            summoned->SetLevel(me->getLevel());
        }

        void EnterCombat(Unit* who) override
        {
            instance->SetBossState(DATA_KILJAEDEN, IN_PROGRESS);
            if (Creature* pControl = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_KILJAEDEN_CONTROLLER)))
                pControl->AddThreat(who, 1.0f);

            me->InterruptNonMeleeSpells(true);
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (Creature* pControl = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_KILJAEDEN_CONTROLLER)))
                ++(ENSURE_AI(npc_kiljaeden_controller::npc_kiljaeden_controllerAI, pControl->AI())->deceiverDeathCount);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!me->IsInCombat())
                DoCast(me, SPELL_SHADOW_CHANNELING);

            if (!UpdateVictim())
                return;

            // Gain Shadow Infusion at 20% health
            if (HealthBelowPct(20) && !me->HasAura(SPELL_SHADOW_INFUSION))
                DoCast(me, SPELL_SHADOW_INFUSION, true);

            // Shadow Bolt Volley - Shoots Shadow Bolts at all enemies within 30 yards, for ~2k Shadow damage.
            if (ShadowBoltVolleyTimer <= diff)
            {
                DoCastVictim(SPELL_SHADOW_BOLT_VOLLEY);
                ShadowBoltVolleyTimer = 12000;
            }
            else
                ShadowBoltVolleyTimer -= diff;

            // Felfire Portal - Creatres a portal, that spawns Volatile Felfire Fiends, which do suicide bombing.
            if (FelfirePortalTimer <= diff)
            {
                if (Creature* pPortal = DoSpawnCreature(NPC_FELFIRE_PORTAL, 0, 0, 0, 0, TEMPSUMMON_TIMED_DESPAWN, 20000))
                {
                    ThreatContainer::StorageType const &threatlist = me->getThreatManager().getThreatList();
                    for (ThreatContainer::StorageType::const_iterator itr = threatlist.begin(); itr != threatlist.end(); ++itr)
                    {
                        Unit* unit = ObjectAccessor::GetUnit(*me, (*itr)->getUnitGuid());
                        if (unit)
                            pPortal->AddThreat(unit, 1.0f);
                    }
                }
                FelfirePortalTimer = 20000;
            } else FelfirePortalTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetSunwellPlateauAI<npc_hand_of_the_deceiverAI>(creature);
    }
};

//AI for Felfire Portal
class npc_felfire_portal : public CreatureScript
{
public:
    npc_felfire_portal() : CreatureScript("npc_felfire_portal") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_felfire_portalAI(creature);
    }

    struct npc_felfire_portalAI : public ScriptedAI
    {
        npc_felfire_portalAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            SetCombatMovement(false);
        }

        void Initialize()
        {
            uiSpawnFiendTimer = 5000;
        }

        uint32 uiSpawnFiendTimer;

        void Reset() override
        {
            Initialize();
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE|UNIT_FLAG_NON_ATTACKABLE);
        }

        void JustSummoned(Creature* summoned) override
        {
            summoned->setFaction(me->getFaction());
            summoned->SetLevel(me->getLevel());
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (uiSpawnFiendTimer <= diff)
            {
                if (Creature* pFiend = DoSpawnCreature(NPC_VOLATILE_FELFIRE_FIEND, 0, 0, 0, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 20000))
                    pFiend->AddThreat(SelectTarget(SELECT_TARGET_RANDOM, 0), 100000.0f);
                uiSpawnFiendTimer = urand(4000, 8000);
            } else uiSpawnFiendTimer -= diff;
        }
    };
};

//AI for Felfire Fiend
class npc_volatile_felfire_fiend : public CreatureScript
{
public:
    npc_volatile_felfire_fiend() : CreatureScript("npc_volatile_felfire_fiend") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_volatile_felfire_fiendAI(creature);
    }

    struct npc_volatile_felfire_fiendAI : public ScriptedAI
    {
        npc_volatile_felfire_fiendAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            uiExplodeTimer = 2000;
            bLockedTarget = false;
        }

        uint32 uiExplodeTimer;

        bool bLockedTarget;

        void Reset() override
        {
            Initialize();
        }

        void DamageTaken(Unit* /*done_by*/, uint32 &damage) override
        {
            if (damage > me->GetHealth())
                DoCast(me, SPELL_FELFIRE_FISSION, true);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (!bLockedTarget)
            {
                me->AddThreat(me->GetVictim(), 10000000.0f);
                bLockedTarget = true;
            }

            if (uiExplodeTimer)
            {
                if (uiExplodeTimer <= diff)
                    uiExplodeTimer = 0;
                else uiExplodeTimer -= diff;
            }
            else if (me->IsWithinDistInMap(me->GetVictim(), 3)) // Explode if it's close enough to it's target
            {
                DoCastVictim(SPELL_FELFIRE_FISSION);
                me->KillSelf();
            }
        }
    };
};

//AI for Armageddon target
class npc_armageddon : public CreatureScript
{
public:
    npc_armageddon() : CreatureScript("npc_armageddon") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_armageddonAI(creature);
    }

    struct npc_armageddonAI : public ScriptedAI
    {
        npc_armageddonAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            SetCombatMovement(false);
        }

        void Initialize()
        {
            spell = 0;
            uiTimer = 0;
        }

        uint8 spell;
        uint32 uiTimer;

        void Reset() override
        {
            Initialize();
        }

        void UpdateAI(uint32 diff) override
        {
            if (uiTimer <= diff)
            {
                switch (spell)
                {
                    case 0:
                        DoCast(me, SPELL_ARMAGEDDON_VISUAL, true);
                        ++spell;
                        break;
                    case 1:
                        DoCast(me, SPELL_ARMAGEDDON_VISUAL2, true);
                        uiTimer = 9000;
                        ++spell;
                        break;
                    case 2:
                        DoCast(me, SPELL_ARMAGEDDON_TRIGGER, true);
                        ++spell;
                        uiTimer = 5000;
                        break;
                    case 3:
                        me->KillSelf();
                        me->RemoveCorpse();
                        break;
                }
            } else uiTimer -=diff;
        }
    };
};

//AI for Shield Orbs
class npc_shield_orb : public CreatureScript
{
public:
    npc_shield_orb() : CreatureScript("npc_shield_orb") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<npc_shield_orbAI>(creature);
    }

    struct npc_shield_orbAI : public ScriptedAI
    {
        npc_shield_orbAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            instance = creature->GetInstanceScript();
            x = 0.f;
            y = 0.f;
        }

        void Initialize()
        {
            bPointReached = true;
            uiTimer = urand(500, 1000);
            uiCheckTimer = 1000;
            r = 17;
            c = 0;
            mx = ShieldOrbLocations[0][0];
            my = ShieldOrbLocations[0][1];
            bClockwise = roll_chance_i(50);
        }

        InstanceScript* instance;

        bool bPointReached;
        bool bClockwise;
        uint32 uiTimer;
        uint32 uiCheckTimer;
        float x, y, r, c, mx, my;

        void Reset() override
        {
            me->SetDisableGravity(true);
            Initialize();
        }

        void UpdateAI(uint32 diff) override
        {
            if (bPointReached)
            {
                if (bClockwise)
                {
                    y = my - r * std::sin(c);
                    x = mx - r * std::cos(c);
                }
                else
                {
                    y = my + r * std::sin(c);
                    x = mx + r * std::cos(c);
                }
                bPointReached = false;
                uiCheckTimer = 1000;
                me->GetMotionMaster()->MovePoint(1, x, y, SHIELD_ORB_Z);
                c += float(M_PI)/32;
                if (c >= 2 * float(M_PI)) c = 0;
            }
            else
            {
                if (uiCheckTimer <= diff)
                {
                    DoTeleportTo(x, y, SHIELD_ORB_Z);
                    bPointReached = true;
                }
                else uiCheckTimer -= diff;
            }

            if (uiTimer <= diff)
            {
                if (Unit* random = ObjectAccessor::GetPlayer(*me, instance->GetGuidData(DATA_PLAYER_GUID)))
                    DoCast(random, SPELL_SHADOW_BOLT, false);
                uiTimer = urand(500, 1000);
            } else uiTimer -= diff;
        }

        void MovementInform(uint32 type, uint32 /*id*/) override
        {
            if (type != POINT_MOTION_TYPE)
                return;

            bPointReached = true;
        }
    };
};

//AI for Sinister Reflection
class npc_sinster_reflection : public CreatureScript
{
public:
    npc_sinster_reflection() : CreatureScript("npc_sinster_reflection") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_sinster_reflectionAI(creature);
    }

    struct npc_sinster_reflectionAI : public ScriptedAI
    {
        npc_sinster_reflectionAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            uiTimer[0] = 0;
            uiTimer[1] = 0;
            uiTimer[2] = 0;
            victimClass = 0;
        }

        uint8 victimClass;
        uint32 uiTimer[3];

        void Reset() override
        {
            Initialize();
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if ((victimClass == 0) && me->GetVictim())
            {
                victimClass = me->EnsureVictim()->getClass();
                switch (victimClass)
                {
                    case CLASS_DRUID:
                        break;
                    case CLASS_HUNTER:
                        break;
                    case CLASS_MAGE:
                        break;
                    case CLASS_WARLOCK:
                        break;
                    case CLASS_WARRIOR:
                        me->SetCanDualWield(true);
                        break;
                    case CLASS_PALADIN:
                        break;
                    case CLASS_PRIEST:
                        break;
                    case CLASS_SHAMAN:
                        me->SetCanDualWield(true);
                        break;
                    case CLASS_ROGUE:
                        me->SetCanDualWield(true);
                        break;
                }
            }

            switch (victimClass)
            {
                case CLASS_DRUID:
                    if (uiTimer[1] <= diff)
                    {
                        DoCastVictim(SPELL_SR_MOONFIRE, false);
                        uiTimer[1] = urand(2000, 4000);
                    }
                    DoMeleeAttackIfReady();
                    break;
                case CLASS_HUNTER:
                    if (uiTimer[1] <= diff)
                    {
                        DoCastVictim(SPELL_SR_MULTI_SHOT, false);
                        uiTimer[1] = urand(8000, 10000);
                    }
                    if (uiTimer[2] <= diff)
                    {
                        DoCastVictim(SPELL_SR_SHOOT, false);
                        uiTimer[2] = urand(4000, 6000);
                    }
                    if (me->IsWithinMeleeRange(me->GetVictim()))
                    {
                        if (uiTimer[0] <= diff)
                        {
                            DoCastVictim(SPELL_SR_MULTI_SHOT, false);
                            uiTimer[0] = urand(6000, 8000);
                        }
                        DoMeleeAttackIfReady();
                    }
                    break;
                case CLASS_MAGE:
                    if (uiTimer[1] <= diff)
                    {
                        DoCastVictim(SPELL_SR_FIREBALL, false);
                        uiTimer[1] = urand(2000, 4000);
                    }
                    DoMeleeAttackIfReady();
                    break;
                case CLASS_WARLOCK:
                    if (uiTimer[1] <= diff)
                    {
                        DoCastVictim(SPELL_SR_SHADOW_BOLT, false);
                        uiTimer[1] = urand(3000, 5000);
                    }
                    if (uiTimer[2] <= diff)
                    {
                        DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true), SPELL_SR_CURSE_OF_AGONY, true);
                        uiTimer[2] = urand(2000, 4000);
                    }
                    DoMeleeAttackIfReady();
                    break;
                case CLASS_WARRIOR:
                    if (uiTimer[1] <= diff)
                    {
                        DoCastVictim(SPELL_SR_WHIRLWIND, false);
                        uiTimer[1] = urand(9000, 11000);
                    }
                    DoMeleeAttackIfReady();
                    break;
                case CLASS_PALADIN:
                    if (uiTimer[1] <= diff)
                    {
                        DoCastVictim(SPELL_SR_HAMMER_OF_JUSTICE, false);
                        uiTimer[1] = urand(6000, 8000);
                    }
                    if (uiTimer[2] <= diff)
                    {
                        DoCastVictim(SPELL_SR_HOLY_SHOCK, false);
                        uiTimer[2] = urand(2000, 4000);
                    }
                    DoMeleeAttackIfReady();
                    break;
                case CLASS_PRIEST:
                    if (uiTimer[1] <= diff)
                    {
                        DoCastVictim(SPELL_SR_HOLY_SMITE, false);
                        uiTimer[1] = urand(4000, 6000);
                    }
                    if (uiTimer[2] <= diff)
                    {
                        DoCast(me, SPELL_SR_RENEW, false);
                        uiTimer[2] = urand(6000, 8000);
                    }
                    DoMeleeAttackIfReady();
                    break;
                case CLASS_SHAMAN:
                    if (uiTimer[1] <= diff)
                    {
                        DoCastVictim(SPELL_SR_EARTH_SHOCK, false);
                        uiTimer[1] = urand(4000, 6000);
                    }
                    DoMeleeAttackIfReady();
                    break;
                case CLASS_ROGUE:
                    if (uiTimer[1] <= diff)
                    {
                        DoCastVictim(SPELL_SR_HEMORRHAGE, true);
                        uiTimer[1] = urand(4000, 6000);
                    }
                    DoMeleeAttackIfReady();
                    break;
            }
            TC_LOG_DEBUG("scripts", "Sinister-Timer");
            for (uint8 i = 0; i < 3; ++i)
                uiTimer[i] -= diff;
        }
    };
};

void AddSC_boss_kiljaeden()
{
    new go_orb_of_the_blue_flight();
    new boss_kalecgos_kj();
    new boss_kiljaeden();
    new npc_kiljaeden_controller();
    new npc_hand_of_the_deceiver();
    new npc_felfire_portal();
    new npc_volatile_felfire_fiend();
    new npc_armageddon();
    new npc_shield_orb();
    new npc_sinster_reflection();
}
