/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

//TODO: Harpoon event is automated needs to be checked

/* ScriptData
SDName: Razorscale
SDAuthor: PrinceCreed
SD%Complete: 100
EndScriptData */

#include "ScriptPCH.h"
#include "ulduar.h"

enum Says
{
    SAY_GREET                       = -1603260,
    SAY_GROUND_PHASE                = -1603261,
    SAY_AGGRO_1                     = -1603262,
    SAY_AGGRO_2                     = -1603263,
    SAY_AGGRO_3                     = -1603264,
    SAY_TURRETS                     = -1603265,
    EMOTE_HARPOON                   = -1603266,
    EMOTE_BREATH                    = -1603267,
    EMOTE_PERMA                     = -1603268,
};

#define GOSSIP_ITEM_1 "Activate Harpoones!"

enum Spells
{
    SPELL_FLAMEBUFFET               = 64016,
    SPELL_FIREBALL                  = 62796,
    SPELL_FLAME_GROUND              = 64709,
    SPELL_WINGBUFFET                = 62666,
    SPELL_FLAMEBREATH               = 63317,
    SPELL_FUSEARMOR                 = 64771,
    SPELL_DEVOURING_FLAME           = 63236,
    SPELL_HARPOON                   = 54933,
    SPELL_FLAMED                    = 62696,
    SPELL_STUN                      = 9032,
    SPELL_BERSERK                   = 47008
};

const Position PosHarpoon[4] =
{
{594.317f, -136.953f, 391.517f, 4.544f},
{577.449f, -136.953f, 391.517f, 4.877f},
{607.726f, -146.857f, 391.517f, 4.041f},
{561.449f, -146.857f, 391.517f, 5.426f}
};

const Position PosEngSpawn = {591.951f, -95.968f, 391.517f, 0};

const Position PosEngRepair[4] =
{
{590.442f, -130.550f, 391.517f, 4.789f},
{574.850f, -133.687f, 391.517f, 4.252f},
{606.567f, -143.369f, 391.517f, 4.434f},
{560.609f, -142.967f, 391.517f, 5.074f}
};

const Position PosDefSpawn[4] =
{
{600.75f, -104.850f, 391.517f, 0},
{596.38f, -110.262f, 391.517f, 0},
{566.47f, -103.633f, 391.517f, 0},
{570.41f, -108.791f, 391.517f, 0}
};

const Position PosDefCombat[4] =
{
{614.975f, -155.138f, 391.517f, 4.154f},
{609.814f, -204.968f, 391.517f, 5.385f},
{563.531f, -201.557f, 391.517f, 4.108f},
{560.231f, -153.677f, 391.517f, 5.403f}
};

const Position RazorFlight = {588.050f, -251.191f, 470.536f, 1.605f};
const Position RazorGround = {586.966f, -175.534f, 391.517f, 1.692f};

enum Mobs
{
    RAZORSCALE                      = 33186,// ?? why not use instance?
    NPC_DARK_RUNE_GUARDIAN          = 33388,
    NPC_DARK_RUNE_SENTINEL          = 33846,
    NPC_DARK_RUNE_WATCHER           = 33453,
    MOLE_MACHINE_TRIGGER            = 33245,
    NPC_COMMANDER                   = 33210,
    NPC_ENGINEER                    = 33287,
    NPC_DEFENDER                    = 33816,
    NPC_HARPOON                     = 33184,
    GOB_MOLE_MACHINE                = 194316
};

enum DarkRuneSpells
{
    // Dark Rune Watcher
    SPELL_CHAIN_LIGHTNING           = 64758,
    SPELL_LIGHTNING_BOLT            = 63809,

    // Dark Rune Guardian
    SPELL_STORMSTRIKE               = 64757,

    // Dark Rune Sentinel
    SPELL_BATTLE_SHOUT              = 46763,
    SPELL_HEROIC_STRIKE             = 45026,
    SPELL_WHIRLWIND                 = 63807,
};

#define ACHIEVEMENT_QUICK_SHAVE     RAID_MODE(2919, 2921)

#define ACTION_EVENT_START          1
#define ACTION_GROUND_PHASE         2

enum Phases
{
    PHASE_NULL,
    PHASE_PERMAGROUND,
    PHASE_GROUND,
    PHASE_FLIGHT
};

enum Events
{
    EVENT_NONE,
    EVENT_BERSERK,
    EVENT_BREATH,
    EVENT_BUFFET,
    EVENT_HARPOON,
    EVENT_FIREBALL,
    EVENT_FLIGHT,
    EVENT_DEVOURING,
    EVENT_FLAME,
    EVENT_LAND,
    EVENT_GROUND,
    EVENT_FUSE,
    EVENT_SUMMON
};

class boss_razorscale : public CreatureScript
{
public:
    boss_razorscale() : CreatureScript("boss_razorscale") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_razorscaleAI (pCreature);
    }

    struct boss_razorscaleAI : public BossAI
    {
        boss_razorscaleAI(Creature *pCreature) : BossAI(pCreature, TYPE_RAZORSCALE), phase(PHASE_NULL)
        {
            // Do not let Razorscale be affected by Battle Shout buff
            me->ApplySpellImmune(0, IMMUNITY_ID, (SPELL_BATTLE_SHOUT), true);
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            me->ApplySpellImmune(0, IMMUNITY_ID, 49560, true);  // Death Grip
        }

        Phases phase;

        uint32 EnrageTimer;
        uint32 FlyCount;

        Creature* Harpoon[4];
        bool PermaGround;
        bool Enraged;

        void Reset()
        {
            _Reset();
            me->SetFlying(true);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
            me->SetReactState(REACT_PASSIVE);
            PermaGround = false;
        }

        void EnterCombat(Unit* /*who*/)
        {
            _EnterCombat();
            for (uint8 n = 0; n < RAID_MODE(2,4); ++n)
                Harpoon[n] = me->SummonCreature(NPC_HARPOON, PosHarpoon[n], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 0);
            me->SetSpeed(MOVE_FLIGHT, 3.0f, true);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->SetReactState(REACT_PASSIVE);
            phase = PHASE_GROUND;
            events.SetPhase(PHASE_GROUND);
            FlyCount = 0;
            EnrageTimer = 15*60*1000;   // Enrage in 15 min
            Enraged = false;
            events.ScheduleEvent(EVENT_FLIGHT, 0, 0, PHASE_GROUND);
        }

        void JustDied(Unit* /*Killer*/)
        {
            _JustDied();

            if (instance)
            {
                // A Quick Shave
                if (FlyCount <= 2)
                    instance->DoCompleteAchievement(ACHIEVEMENT_QUICK_SHAVE);
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (me->getVictim() && !me->getVictim()->GetCharmerOrOwnerPlayerOrPlayerItself())
                me->Kill(me->getVictim());

            events.Update(diff);

            if (HealthBelowPct(50) && !PermaGround)
                EnterPermaGround();

            if (EnrageTimer <= diff && !Enraged)
            {
                DoCast(me, SPELL_BERSERK);
                Enraged = true;
            }
            else EnrageTimer -= diff;

            if (phase == PHASE_GROUND)
            {
                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch(eventId)
                    {
                        case EVENT_FLIGHT:
                            phase = PHASE_FLIGHT;
                            events.SetPhase(PHASE_FLIGHT);
                            me->SetFlying(true);
                            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            me->SetReactState(REACT_PASSIVE);
                            me->AttackStop();
                            me->RemoveAllAuras();
                            me->GetMotionMaster()->MovePoint(0,RazorFlight);
                            events.ScheduleEvent(EVENT_FIREBALL, 7000, 0, PHASE_FLIGHT);
                            events.ScheduleEvent(EVENT_DEVOURING, 10000, 0, PHASE_FLIGHT);
                            events.ScheduleEvent(EVENT_SUMMON, 5000, 0, PHASE_FLIGHT);
                            events.ScheduleEvent(EVENT_GROUND, 75000, 0, PHASE_FLIGHT);
                            ++FlyCount;
                            return;
                        case EVENT_LAND:
                            me->SetFlying(false);
                            me->NearTeleportTo(586.966f, -175.534f, 391.517f, 1.692f);
                            DoCast(me, SPELL_STUN, true);
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            if (Creature *pCommander = me->GetCreature(*me, instance->GetData64(DATA_EXP_COMMANDER)))
                                pCommander->AI()->DoAction(ACTION_GROUND_PHASE);
                            events.ScheduleEvent(EVENT_HARPOON, 0, 0, PHASE_GROUND);
                            events.ScheduleEvent(EVENT_BREATH, 30000, 0, PHASE_GROUND);
                            events.ScheduleEvent(EVENT_BUFFET, 33000, 0, PHASE_GROUND);
                            events.ScheduleEvent(EVENT_FLIGHT, 35000, 0, PHASE_GROUND);
                            return;
                        case EVENT_HARPOON:
                            for (uint8 n = 0; n < RAID_MODE(2,4); ++n)
                                if (Harpoon[n])
                                    Harpoon[n]->CastSpell(me, SPELL_HARPOON, true);
                            events.ScheduleEvent(EVENT_HARPOON, 1500, 0, PHASE_GROUND);
                            return;
                        case EVENT_BREATH:
                            me->MonsterTextEmote(EMOTE_BREATH, 0, true);
                            DoCastAOE(SPELL_FLAMEBREATH);
                            events.CancelEvent(EVENT_HARPOON);
                            events.CancelEvent(EVENT_BREATH);
                            return;
                        case EVENT_BUFFET:
                            DoCastAOE(SPELL_WINGBUFFET);
                            for (uint8 n = 0; n < RAID_MODE(2,4); ++n)
                                if (Harpoon[n])
                                    Harpoon[n]->CastSpell(Harpoon[n], SPELL_FLAMED, true);
                            events.CancelEvent(EVENT_BUFFET);
                            return;
                    }
                }
            }
            if (phase == PHASE_PERMAGROUND)
            {
                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch(eventId)
                    {
                        case EVENT_FLAME:
                            DoCastAOE(SPELL_FLAMEBUFFET);
                            events.ScheduleEvent(EVENT_FLAME, 10000, 0, PHASE_PERMAGROUND);
                            return;
                        case EVENT_BREATH:
                            me->MonsterTextEmote(EMOTE_BREATH, 0, true);
                            DoCastVictim(SPELL_FLAMEBREATH);
                            events.ScheduleEvent(EVENT_BREATH, 20000, 0, PHASE_PERMAGROUND);
                            return;
                        case EVENT_FIREBALL:
                            if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 200, true))
                                DoCast(pTarget, SPELL_FIREBALL);
                            events.ScheduleEvent(EVENT_FIREBALL, 3000, 0, PHASE_PERMAGROUND);
                            return;
                        case EVENT_DEVOURING:
                            if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 200, true))
                                DoCast(pTarget, SPELL_DEVOURING_FLAME);
                            events.ScheduleEvent(EVENT_DEVOURING, 10000, 0, PHASE_PERMAGROUND);
                            return;
                        case EVENT_BUFFET:
                            DoCastAOE(SPELL_WINGBUFFET);
                            events.CancelEvent(EVENT_BUFFET);
                            return;
                        case EVENT_FUSE:
                            DoCastVictim(SPELL_FUSEARMOR);
                            events.ScheduleEvent(EVENT_FUSE, 10000, 0, PHASE_PERMAGROUND);
                            return;
                    }
                }

                DoMeleeAttackIfReady();
            }
            else
            {
                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch(eventId)
                    {
                        case EVENT_GROUND:
                            phase = PHASE_GROUND;
                            events.SetPhase(PHASE_GROUND);
                            if (Harpoon[0])
                                Harpoon[0]->MonsterTextEmote(EMOTE_HARPOON, 0, true);
                            me->GetMotionMaster()->MovePoint(0,RazorGround);
                            events.ScheduleEvent(EVENT_LAND, 5500, 0, PHASE_GROUND);
                            return;
                        case EVENT_FIREBALL:
                            if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 200, true))
                                DoCast(pTarget, SPELL_FIREBALL);
                            events.ScheduleEvent(EVENT_FIREBALL, 3000, 0, PHASE_FLIGHT);
                            return;
                        case EVENT_DEVOURING:
                            if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 200, true))
                                DoCast(pTarget, SPELL_DEVOURING_FLAME);
                            events.ScheduleEvent(EVENT_DEVOURING, 10000, 0, PHASE_FLIGHT);
                            return;
                        case EVENT_SUMMON:
                            SummonAdds();
                            events.ScheduleEvent(EVENT_SUMMON, 45000, 0, PHASE_FLIGHT);
                            return;
                    }
                }
            }
        }

        void EnterPermaGround()
        {
            me->MonsterTextEmote(EMOTE_PERMA, 0, true);
            phase = PHASE_PERMAGROUND;
            events.SetPhase(PHASE_PERMAGROUND);
            me->SetFlying(false);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->SetReactState(REACT_AGGRESSIVE);
            me->RemoveAurasDueToSpell(SPELL_STUN);
            me->SetSpeed(MOVE_FLIGHT, 1.0f, true);
            PermaGround = true;
            DoCastAOE(SPELL_FLAMEBREATH);
            events.ScheduleEvent(EVENT_FLAME, 15000, 0, PHASE_PERMAGROUND);
            events.RescheduleEvent(EVENT_DEVOURING, 15000, 0, PHASE_PERMAGROUND);
            events.RescheduleEvent(EVENT_BREATH, 20000, 0, PHASE_PERMAGROUND);
            events.RescheduleEvent(EVENT_FIREBALL, 3000, 0, PHASE_PERMAGROUND);
            events.RescheduleEvent(EVENT_DEVOURING, 6000, 0, PHASE_PERMAGROUND);
            events.RescheduleEvent(EVENT_BUFFET, 2500, 0, PHASE_PERMAGROUND);
            events.RescheduleEvent(EVENT_FUSE, 5000, 0, PHASE_PERMAGROUND);
        }

        void SummonAdds()
        {
            // Adds will come in waves from mole machines. One mole can spawn a Dark Rune Watcher
            // with 1-2 Guardians, or a lone Sentinel. Up to 4 mole machines can spawn adds at any given time.
            uint8 random = urand(1,4);
            for (uint8 i = 0; i < random; ++i)
            {
                float x = float(irand(540, 640));       // Safe range is between 500 and 650
                float y = float(irand(-230, -195));     // Safe range is between -235 and -145
                float z = 391.5f;                       // Ground level
                me->SummonCreature(MOLE_MACHINE_TRIGGER, x, y, z, 0, TEMPSUMMON_TIMED_DESPAWN, 10000);
            }
        }

        void DoAction(const int32 action)
        {
            switch(action)
            {
                case ACTION_EVENT_START:
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                    me->SetReactState(REACT_AGGRESSIVE);
                    DoZoneInCombat();
                    break;
            }
        }
    };

};

/*====================================================================================
====================================================================================*/

class npc_expedition_commander : public CreatureScript
{
public:
    npc_expedition_commander() : CreatureScript("npc_expedition_commander") { }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        switch(uiAction)
        {
            case GOSSIP_ACTION_INFO_DEF:
                if (pPlayer)
                    pPlayer->CLOSE_GOSSIP_MENU();
                CAST_AI(npc_expedition_commanderAI, (pCreature->AI()))->uiPhase = 1;
                break;
        }
        return true;
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        InstanceScript* pInstance = pCreature->GetInstanceScript();
        if (pInstance && pInstance->GetBossState(TYPE_RAZORSCALE) == NOT_STARTED && pPlayer)
        {
            pPlayer->PrepareGossipMenu(pCreature);

            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT,GOSSIP_ITEM_1,GOSSIP_SENDER_MAIN,GOSSIP_ACTION_INFO_DEF);
            pPlayer->SEND_GOSSIP_MENU(13853, pCreature->GetGUID());
        }
        else pPlayer->SEND_GOSSIP_MENU(13910, pCreature->GetGUID());

        return true;
    }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_expedition_commanderAI (pCreature);
    }

    struct npc_expedition_commanderAI : public ScriptedAI
    {
        npc_expedition_commanderAI(Creature* pCreature) : ScriptedAI(pCreature), summons(me)
        {
            pInstance = pCreature->GetInstanceScript();
            greet = false;
        }

        InstanceScript* pInstance;
        SummonList summons;

        bool greet;
        uint32 uiTimer;
        uint8  uiPhase;
        Creature* engineer[4];
        Creature* defender[4];

        void Reset()
        {
            uiTimer = 0;
            uiPhase = 0;
            greet = false;
        }

        void MoveInLineOfSight(Unit *who)
        {
            if (!greet && me->IsWithinDistInMap(who, 10.0f) && who->GetTypeId() == TYPEID_PLAYER)
            {
                DoScriptText(SAY_GREET, me);
                greet = true;
            }
        }

        void JustSummoned(Creature *summon)
        {
            summons.Summon(summon);
        }

        void DoAction(const int32 action)
        {
            switch(action)
            {
                case ACTION_GROUND_PHASE:
                    DoScriptText(SAY_GROUND_PHASE, me);
                    break;
            }
        }

        void UpdateAI(const uint32 uiDiff)
        {
            ScriptedAI::UpdateAI(uiDiff);
            if (uiTimer <= uiDiff)
            {
                switch(uiPhase)
                {
                    case 1:
                        pInstance->SetBossState(TYPE_RAZORSCALE, IN_PROGRESS);
                        summons.DespawnAll();
                        uiTimer = 1000;
                        uiPhase = 2;
                        break;
                    case 2:
                        for (uint8 n = 0; n < RAID_MODE(2,4); ++n)
                        {
                            engineer[n] = me->SummonCreature(NPC_ENGINEER, PosEngSpawn, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);
                            engineer[n]->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
                            engineer[n]->SetSpeed(MOVE_RUN, 0.5f);
                            engineer[n]->SetHomePosition(PosEngRepair[n]);
                            engineer[n]->GetMotionMaster()->MoveTargetedHome();
                        }
                        engineer[0]->MonsterYell(SAY_AGGRO_3, LANG_UNIVERSAL, 0);
                        uiPhase = 3;
                        uiTimer = 14000;
                        break;
                    case 3:
                        for (uint8 n = 0; n < 4; ++n)
                        {
                            defender[n] = me->SummonCreature(NPC_DEFENDER, PosDefSpawn[n], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);
                            defender[n] ->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
                            defender[n] ->SetHomePosition(PosDefCombat[n]);
                            defender[n] ->GetMotionMaster()->MoveTargetedHome();
                        }
                        uiPhase = 4;
                        break;
                    case 4:
                        for (uint8 n = 0; n < RAID_MODE(2,4); ++n)
                            engineer[n]->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_USESTANDING);
                        for (uint8 n = 0; n < 4; ++n)
                            defender[n]->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY2H);
                        me->MonsterYell(SAY_AGGRO_2, LANG_UNIVERSAL, 0);
                        uiTimer = 16000;
                        uiPhase = 5;
                        break;
                    case 5:
                        if (Creature *pRazorscale = me->GetCreature(*me, pInstance->GetData64(TYPE_RAZORSCALE)))
                            pRazorscale->AI()->DoAction(ACTION_EVENT_START);
                        engineer[0]->MonsterYell(SAY_AGGRO_1, LANG_UNIVERSAL, 0);
                        uiPhase = 6;
                        break;
                }
            }
            else uiTimer -= uiDiff;
        }
    };

};

class npc_mole_machine_trigger : public CreatureScript
{
public:
    npc_mole_machine_trigger() : CreatureScript("npc_mole_machine_trigger") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_mole_machine_triggerAI (pCreature);
    }

    struct npc_mole_machine_triggerAI : public Scripted_NoMovementAI
    {
        npc_mole_machine_triggerAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_PACIFIED);
            me->SetVisible(false);
        }

        GameObject* MoleMachine;
        uint32 SummonTimer;

        void Reset()
        {
            MoleMachine = me->SummonGameObject(GOB_MOLE_MACHINE, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(),
                float(urand(0, 6)), 0, 0, 0, 0, 300);
            if (MoleMachine)
                MoleMachine->SetGoState(GO_STATE_ACTIVE);
            SummonTimer = 6000;
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            if (SummonTimer <= uiDiff)
            {
                float x = me->GetPositionX();
                float y = me->GetPositionY();
                float z = me->GetPositionZ();

                // One mole can spawn a Dark Rune Watcher with 1-2 Guardians, or a lone Sentinel
                if (!(rand()%2))
                {
                    me->SummonCreature(NPC_DARK_RUNE_WATCHER, x, y, z, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 3000);
                    uint8 random = urand(1,2);
                    for (uint8 i = 0; i < random; ++i)
                        me->SummonCreature(NPC_DARK_RUNE_GUARDIAN, x, y, z, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 3000);
                }
                else me->SummonCreature(NPC_DARK_RUNE_SENTINEL, x, y, z, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 3000);

                SummonTimer = 15000;
            }
            else SummonTimer -= uiDiff;
        }

        void JustSummoned(Creature *summon)
        {
            summon->AI()->DoZoneInCombat();
        }
    };

};

class npc_devouring_flame : public CreatureScript
{
public:
    npc_devouring_flame() : CreatureScript("npc_devouring_flame") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_devouring_flameAI (pCreature);
    }

    struct npc_devouring_flameAI : public Scripted_NoMovementAI
    {
        npc_devouring_flameAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_PACIFIED);
            me->SetDisplayId(11686);
        }

        void Reset()
        {
            DoCast(me, SPELL_FLAME_GROUND);
        }
    };

};

class npc_darkrune_watcher : public CreatureScript
{
public:
    npc_darkrune_watcher() : CreatureScript("npc_darkrune_watcher") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_darkrune_watcherAI (pCreature);
    }

    struct npc_darkrune_watcherAI : public ScriptedAI
    {
        npc_darkrune_watcherAI(Creature *pCreature) : ScriptedAI(pCreature)
        {
            pInstance = pCreature->GetInstanceScript();
        }

        InstanceScript *pInstance;

        uint32 ChainTimer;
        uint32 LightTimer;

        void Reset()
        {
            ChainTimer = urand(10000, 15000);
            LightTimer = urand(1000, 3000);
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            if (ChainTimer <= uiDiff)
            {
                DoCastVictim(SPELL_CHAIN_LIGHTNING);
                ChainTimer = urand(10000, 15000);
            }
            else ChainTimer -= uiDiff;

            if (LightTimer <= uiDiff)
            {
                DoCastVictim(SPELL_LIGHTNING_BOLT);
                LightTimer = urand(5000, 7000);
            }
            else LightTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }
    };

};

class npc_darkrune_guardian : public CreatureScript
{
public:
    npc_darkrune_guardian() : CreatureScript("npc_darkrune_guardian") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_darkrune_guardianAI (pCreature);
    }

    struct npc_darkrune_guardianAI : public ScriptedAI
    {
        npc_darkrune_guardianAI(Creature *pCreature) : ScriptedAI(pCreature)
        {
            pInstance = pCreature->GetInstanceScript();
        }

        InstanceScript *pInstance;

        uint32 StormTimer;

        void Reset()
        {
            StormTimer = urand(3000, 6000);
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            if (StormTimer <= uiDiff)
            {
                DoCastVictim(SPELL_STORMSTRIKE);
                StormTimer = urand(4000, 8000);
            }
            else StormTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }
    };

};

class npc_darkrune_sentinel : public CreatureScript
{
public:
    npc_darkrune_sentinel() : CreatureScript("npc_darkrune_sentinel") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_darkrune_sentinelAI (pCreature);
    }

    struct npc_darkrune_sentinelAI : public ScriptedAI
    {
        npc_darkrune_sentinelAI(Creature *pCreature) : ScriptedAI(pCreature)
        {
            pInstance = pCreature->GetInstanceScript();
        }

        InstanceScript *pInstance;

        uint32 HeroicTimer;
        uint32 WhirlTimer;
        uint32 ShoutTimer;

        void Reset()
        {
            HeroicTimer = urand(4000, 8000);
            WhirlTimer = urand(20000, 25000);
            ShoutTimer = urand(15000, 30000);
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            if (HeroicTimer <= uiDiff)
            {
                DoCastVictim(SPELL_HEROIC_STRIKE);
                HeroicTimer = urand(4000, 6000);
            }
            else HeroicTimer -= uiDiff;

            if (WhirlTimer <= uiDiff)
            {
                DoCastVictim(SPELL_WHIRLWIND);
                WhirlTimer = urand(20000, 25000);
            }
            else WhirlTimer -= uiDiff;

            if (ShoutTimer <= uiDiff)
            {
                DoCast(me, SPELL_BATTLE_SHOUT);
                ShoutTimer = urand(30000, 40000);
            }
            else ShoutTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_razorscale()
{
    new boss_razorscale();
    new npc_expedition_commander();
    new npc_mole_machine_trigger();
    new npc_devouring_flame();
    new npc_darkrune_watcher();
    new npc_darkrune_guardian();
    new npc_darkrune_sentinel();
}