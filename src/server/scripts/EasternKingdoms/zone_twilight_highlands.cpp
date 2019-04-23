/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"
#include "Player.h"
#include "SpellInfo.h"

/*####
## npc_gurgthock_cata |
####*/

enum Gurgthock
{
    QUEST_THE_CRUCIBLE_OF_CARNAGE_THEBLOODEYE_BRUISER   = 27863,
    QUEST_THE_CRUCIBLE_OF_CARNAGE_SPECIAL_H             = 27865, // second quest
    QUEST_THE_CRUCIBLE_OF_CARNAGE_SPECIAL_A             = 27864, // second quest
    QUEST_THE_CRUCIBLE_OF_CARNAGE_CALDERS_CREATION      = 27866,
    QUEST_THE_CRUCIBLE_OF_CARNAGE_THE_EARL_OF_EVIS      = 27867,
    QUEST_THE_CRUCIBLE_OF_CARNAGE_THE_TWILIGHT_TERROR   = 27868,

    NPC_HURP_DERP                                       = 46944,
    NPC_SULLY_KNEECAPPER                                = 46946, // Horde Quest Boss
    NPC_TORG_DRAKEFLAYER                                = 46945, // Ally Quest Boss
    NPC_CADAVER_COLLAGE                                 = 46947,
    NPC_LORD_GEOFFERY_TULVAN                            = 46948,
    NPC_EMBERSCAR_THE_DEVOURER                          = 46949,

    // Trash
    NPC_GLOOMWING                                       = 47476,

    SAY_QUEST_ACCEPT_BLOODEYE                           = 0,
};

Position const CenterPos  = {-4190.416f, -5145.781f, -7.7363f, 2.070863f}; // CENTER

Position const SpawnPosition[] =
{
    {-4182.385f, -5111.955f, -7.7334f, 4.479527f}, // general spawnpos
    {-4194.154f, -5139.351f, -7.7364f, 1.865049f}, // direct center pos
    {-4108.251f, -5221.142f, -9.5933f, 2.296299f}, // outside arena
    {-4187.152f, -5157.176f, 8.42034f, 1.428060f} // gloomwing fly pos
};

class npc_gurgthock_cata : public CreatureScript
{
public:
    npc_gurgthock_cata() : CreatureScript("npc_gurgthock_cata") { }

    struct npc_gurgthock_cataAI : public ScriptedAI
    {
        npc_gurgthock_cataAI(Creature* creature) : ScriptedAI(creature) { }

        ObjectGuid SummonGUID;
        ObjectGuid uiPlayerGUID;

        uint32 uiTimer;
        uint32 uiPhase;
        uint32 uiRemoveFlagTimer;
        uint32 uiQuest;

        bool bRemoveFlag;

        void Reset() override
        {
            me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
            uiTimer = 0;
            uiPhase = 0;
            uiQuest = 0;
            uiRemoveFlagTimer = 5000;

            bRemoveFlag = false;
        }

        void SetGUID(ObjectGuid guid, int32 /*id*/) override
        {
            uiPlayerGUID = guid;
        }

        void SetData(uint32 uiId, uint32 uiValue) override
        {
            bRemoveFlag = true;
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);

            switch (uiId)
            {
                case 1:
                    switch (uiValue)
                    {
                        case QUEST_THE_CRUCIBLE_OF_CARNAGE_THEBLOODEYE_BRUISER:
                            uiPhase = 1;
                            uiTimer = 4000;
                            break;
                        case QUEST_THE_CRUCIBLE_OF_CARNAGE_SPECIAL_H:
                        case QUEST_THE_CRUCIBLE_OF_CARNAGE_SPECIAL_A:
                            uiPhase = 3;
                            uiTimer = 3000;
                            break;
                        case QUEST_THE_CRUCIBLE_OF_CARNAGE_CALDERS_CREATION:
                            uiPhase = 6;
                            uiTimer = 3000;
                            break;
                        case QUEST_THE_CRUCIBLE_OF_CARNAGE_THE_EARL_OF_EVIS:
                            uiPhase = 8;
                            uiTimer = 3000;
                            break;
                        case QUEST_THE_CRUCIBLE_OF_CARNAGE_THE_TWILIGHT_TERROR:
                            uiPhase = 10;
                            uiTimer = 3000;
                            break;
                    }
                        break;
            }
        }

        void UpdateAI(uint32 uiDiff) override
        {
            ScriptedAI::UpdateAI(uiDiff);

            if (bRemoveFlag)
            {
                if (uiRemoveFlagTimer <= uiDiff)
                {
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                    bRemoveFlag = false;

                    uiRemoveFlagTimer = 10000;
                } else uiRemoveFlagTimer -= uiDiff;
            }

            if (uiPhase)
            {
                Player* player = ObjectAccessor::GetPlayer(*me, uiPlayerGUID);

                if (uiTimer <= uiDiff)
                {
                    switch (uiPhase)
                    {
                        case 1:
                            if (Creature* summon = me->SummonCreature(NPC_HURP_DERP, SpawnPosition[0], TEMPSUMMON_CORPSE_DESPAWN, 5000))
                                SummonGUID = summon->GetGUID();
                            uiPhase = 2;
                            uiTimer = 4000;
                            break;
                         case 2:
                            if (Creature* summon = ObjectAccessor::GetCreature(*me, SummonGUID))
                                summon->GetMotionMaster()->MovePoint(0, CenterPos);
                            uiPhase = 0;
                            SummonGUID = ObjectGuid::Empty;
                            break;
                        case 3:
                            uiTimer = 3000;
                            uiPhase = 4;
                            break;
                        case 4:
                            if (player->GetTeamId() == TEAM_ALLIANCE)
                            {
                                if (Creature* summon = me->SummonCreature(NPC_TORG_DRAKEFLAYER, SpawnPosition[1], TEMPSUMMON_CORPSE_DESPAWN, 5000))
                                    SummonGUID = summon->GetGUID();
                            }
                            else
                            if (player->GetTeamId() == TEAM_HORDE)
                            {
                                if (Creature* summon = me->SummonCreature(NPC_SULLY_KNEECAPPER, SpawnPosition[1], TEMPSUMMON_CORPSE_DESPAWN, 5000))
                                    SummonGUID = summon->GetGUID();
                            }
                            uiTimer = 3000;
                            uiPhase = 0;
                            break;
                        case 6:
                            if (Creature* summon = me->SummonCreature(NPC_CADAVER_COLLAGE, SpawnPosition[0], TEMPSUMMON_CORPSE_DESPAWN, 5000))
                                SummonGUID = summon->GetGUID();
                            uiPhase = 7;
                            uiTimer = 4000;
                            break;
                         case 7:
                            if (Creature* summon = ObjectAccessor::GetCreature(*me, SummonGUID))
                                summon->GetMotionMaster()->MovePoint(0, CenterPos);
                            uiPhase = 0;
                            SummonGUID = ObjectGuid::Empty;
                            break;
                        case 8:
                            if (Creature* summon = me->SummonCreature(NPC_LORD_GEOFFERY_TULVAN, SpawnPosition[2], TEMPSUMMON_CORPSE_DESPAWN, 5000))
                                SummonGUID = summon->GetGUID();
                            uiPhase = 9;
                            uiTimer = 4000;
                            break;
                         case 9:
                            if (Creature* summon = ObjectAccessor::GetCreature(*me, SummonGUID))
                                summon->GetMotionMaster()->MovePoint(0, CenterPos);
                            uiPhase = 0;
                            SummonGUID = ObjectGuid::Empty;
                            break;
                        case 10:
                            if (Creature* summon = me->SummonCreature(NPC_EMBERSCAR_THE_DEVOURER, SpawnPosition[1], TEMPSUMMON_CORPSE_DESPAWN, 5000))
                                SummonGUID = summon->GetGUID();
                            uiPhase = 11;
                            uiTimer = 4000;
                            break;
                         case 11:
                            if (Creature* summon = ObjectAccessor::GetCreature(*me, SummonGUID))
                                summon->GetMotionMaster()->MovePoint(0, CenterPos);
                            uiPhase = 0;
                            SummonGUID = ObjectGuid::Empty;
                            break;
                    }
                }else uiTimer -= uiDiff;
            }
        }
    };

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest) override
    {
        switch (quest->GetQuestId())
        {
            case QUEST_THE_CRUCIBLE_OF_CARNAGE_THEBLOODEYE_BRUISER:
                creature->AI()->SetData(1, quest->GetQuestId());
                break;
            case QUEST_THE_CRUCIBLE_OF_CARNAGE_SPECIAL_H:
            case QUEST_THE_CRUCIBLE_OF_CARNAGE_SPECIAL_A:
                creature->AI()->SetData(1, quest->GetQuestId());
                break;
            case QUEST_THE_CRUCIBLE_OF_CARNAGE_CALDERS_CREATION:
                creature->AI()->SetData(1, quest->GetQuestId());
                break;
            case QUEST_THE_CRUCIBLE_OF_CARNAGE_THE_EARL_OF_EVIS:
                creature->AI()->SetData(1, quest->GetQuestId());
                break;
            case QUEST_THE_CRUCIBLE_OF_CARNAGE_THE_TWILIGHT_TERROR:
                creature->AI()->SetData(1, quest->GetQuestId());
                break;
        }

        creature->AI()->SetGUID(player->GetGUID());

        return false;
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_gurgthock_cataAI(creature);
    }
};

/*####
## npc_hurp_derp
####*/

enum HurpSpells
{
    SPELL_INTIMIDATING_ROAR        = 91933,
    SPELL_OVERHEAD_SMASH           = 88482,
    SPELL_WHIRLWIND                = 83016
};

enum HurpEvents
{
    EVENT_INTIMIDATING_ROAR        = 1,
    EVENT_OVERHEAD_SMASH,
    EVENT_WHIRLWIND
};

class npc_hurp_derp : public CreatureScript
{
public:
    npc_hurp_derp() : CreatureScript("npc_hurp_derp") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_hurp_derpAI (creature);
    }

    struct npc_hurp_derpAI : public ScriptedAI
    {
        npc_hurp_derpAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override { }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            me->DespawnOrUnsummon(3000);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_INTIMIDATING_ROAR, 10000);
            events.ScheduleEvent(EVENT_OVERHEAD_SMASH, 5000);
            events.ScheduleEvent(EVENT_WHIRLWIND, 15000);
        }

        void JustDied(Unit* killer) override
        {
            if (Player* player = killer->GetCharmerOrOwnerPlayerOrPlayerItself())
            {
                player->GroupEventHappens(QUEST_THE_CRUCIBLE_OF_CARNAGE_THEBLOODEYE_BRUISER, killer);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if(!UpdateVictim())
                return;

            events.Update(diff);

            if(me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if(uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                case EVENT_INTIMIDATING_ROAR:
                    DoCastVictim(SPELL_INTIMIDATING_ROAR);
                    events.ScheduleEvent(EVENT_INTIMIDATING_ROAR, urand(15*IN_MILLISECONDS, 25*IN_MILLISECONDS));
                    break;
                case EVENT_OVERHEAD_SMASH:
                    DoCastVictim(SPELL_OVERHEAD_SMASH);
                    events.ScheduleEvent(EVENT_OVERHEAD_SMASH, urand(20*IN_MILLISECONDS, 30*IN_MILLISECONDS));
                    break;
                case EVENT_WHIRLWIND:
                     if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0))
                     {
                         DoCast(target, SPELL_WHIRLWIND, true);
                     }
                    events.ScheduleEvent(EVENT_WHIRLWIND, urand(15*IN_MILLISECONDS, 25*IN_MILLISECONDS));
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    private:
        EventMap events;
    };
};

/*####
## npc_sully_kneecapper // npc_trog_drakeflayer
####*/

enum SullySpells
{
    SPELL_CHARGE             = 88288,
    SPELL_UPPERCUT           = 80182
};

enum SullyEvents
{
    EVENT_S_CHARGE           = 1,
    EVENT_UPPERCUT,
};

class npc_sully_kneecapper : public CreatureScript
{
public:
    npc_sully_kneecapper() : CreatureScript("npc_sully_kneecapper") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_sully_kneecapperAI (creature);
    }

    struct npc_sully_kneecapperAI : public ScriptedAI
    {
        npc_sully_kneecapperAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            DespawnCreatures(47476);
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            me->DespawnOrUnsummon(3000);
            DespawnCreatures(47476);
        }

        void DespawnCreatures(uint32 entry)
        {
            std::list<Creature*> creatures;
            GetCreatureListWithEntryInGrid(creatures, me, entry, 1000.0f);
            if (creatures.empty())
                return;
            for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
                (*iter)->DespawnOrUnsummon();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_S_CHARGE, 10000);
            events.ScheduleEvent(EVENT_UPPERCUT, 5000);

            me->SummonCreature(NPC_GLOOMWING, SpawnPosition[3], TEMPSUMMON_CORPSE_DESPAWN, 5000);
        }

        void JustDied(Unit* killer) override
        {
            if (Player* player = killer->GetCharmerOrOwnerPlayerOrPlayerItself())
            {
                player->GroupEventHappens(QUEST_THE_CRUCIBLE_OF_CARNAGE_SPECIAL_H, killer);
            }
            DespawnCreatures(47476);
        }

        void UpdateAI(uint32 diff) override
        {
            if(!UpdateVictim())
                return;

            events.Update(diff);

            if(me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if(uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                case EVENT_S_CHARGE:
                    DoCastRandom(SPELL_CHARGE, 150.0f);
                    events.ScheduleEvent(EVENT_S_CHARGE, urand(10*IN_MILLISECONDS, 20*IN_MILLISECONDS));
                    break;
                case EVENT_UPPERCUT:
                    DoCastVictim(SPELL_UPPERCUT);
                    events.ScheduleEvent(EVENT_UPPERCUT, urand(15*IN_MILLISECONDS, 25*IN_MILLISECONDS));
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    private:
        EventMap events;
    };
};

class npc_torg_drakeflayer : public CreatureScript
{
public:
    npc_torg_drakeflayer() : CreatureScript("npc_torg_drakeflayer") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_torg_drakeflayerAI (creature);
    }

    struct npc_torg_drakeflayerAI : public ScriptedAI
    {
        npc_torg_drakeflayerAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            DespawnCreatures(47476);
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            me->DespawnOrUnsummon(3000);
            DespawnCreatures(47476);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_S_CHARGE, 10000);
            events.ScheduleEvent(EVENT_UPPERCUT, 5000);

            me->SummonCreature(NPC_GLOOMWING, SpawnPosition[3], TEMPSUMMON_CORPSE_DESPAWN, 5000);
        }

        void DespawnCreatures(uint32 entry)
        {
            std::list<Creature*> creatures;
            GetCreatureListWithEntryInGrid(creatures, me, entry, 1000.0f);
            if (creatures.empty())
                return;
            for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
                (*iter)->DespawnOrUnsummon();
        }

        void JustDied(Unit* killer) override
        {
            if (Player* player = killer->GetCharmerOrOwnerPlayerOrPlayerItself())
            {
                player->GroupEventHappens(QUEST_THE_CRUCIBLE_OF_CARNAGE_SPECIAL_A, killer);
            }
            DespawnCreatures(47476);
        }

        void UpdateAI(uint32 diff) override
        {
            if(!UpdateVictim())
                return;

            events.Update(diff);

            if(me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if(uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                case EVENT_S_CHARGE:
                    DoCastRandom(SPELL_CHARGE, 150.0f);
                    events.ScheduleEvent(EVENT_S_CHARGE, urand(10*IN_MILLISECONDS, 20*IN_MILLISECONDS));
                    break;
                case EVENT_UPPERCUT:
                    DoCastVictim(SPELL_UPPERCUT);
                    events.ScheduleEvent(EVENT_UPPERCUT, urand(15*IN_MILLISECONDS, 25*IN_MILLISECONDS));
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    private:
        EventMap events;
    };
};

/*####
## npc_cadaver_collage
####*/

enum CadaverSpells
{
    SPELL_BELCH                    = 88607,
    SPELL_INHALE                   = 88615,
    SPELL_PLAGUE_EXPLOSION         = 88614,
    SPELL_POISON_CLOUD             = 90447,
    SPELL_REPULSIVE_KICK           = 88605,
    SPELL_CADAVER_HOVER            = 95868
};

enum CadaverEvents
{
    EVENT_BELCH                    = 1,
    EVENT_INHALE,
    EVENT_PLAGUE_EXPLOSION,
    EVENT_POISON_CLOUD,
    EVENT_REPULSIVE_KICK,
    EVENT_BELOW5,
    EVENT_TAKEOFF,
    EVENT_EXPLODE
};

class npc_cadaver_collage : public CreatureScript
{
public:
    npc_cadaver_collage() : CreatureScript("npc_cadaver_collage") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_cadaver_collageAI (creature);
    }

    struct npc_cadaver_collageAI : public ScriptedAI
    {
        npc_cadaver_collageAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            DespawnTriggers(48591);
            inhaled = false;
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_BELCH, 15000);
            events.ScheduleEvent(EVENT_POISON_CLOUD, 10000);
            events.ScheduleEvent(EVENT_REPULSIVE_KICK, 8000);
        }

        void DamageTaken(Unit* attacker, uint32& /*damage*/) override
        {
            if(!inhaled && !me->IsNonMeleeSpellCast(false) && HealthBelowPct(20))
            {
                if (Player* player = attacker->GetCharmerOrOwnerPlayerOrPlayerItself())
                {
                    player->GroupEventHappens(QUEST_THE_CRUCIBLE_OF_CARNAGE_CALDERS_CREATION, attacker);
                }

                inhaled = true;
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->RemoveAllAuras();
                me->SetReactState(REACT_PASSIVE);
                me->AttackStop();
                DoCast(SPELL_INHALE);
                events.CancelEvent(EVENT_BELCH); // just to be sure
                events.CancelEvent(EVENT_POISON_CLOUD);
                events.CancelEvent(EVENT_REPULSIVE_KICK);
                events.ScheduleEvent(EVENT_BELOW5, 6000);
            }
        }

        void DespawnTriggers(uint32 entry)
        {
            std::list<Creature*> creatures;
            GetCreatureListWithEntryInGrid(creatures, me, entry, 1000.0f);
            if (creatures.empty())
                return;
            for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
                (*iter)->DespawnOrUnsummon();
        }

        void JustDied(Unit* /*killer*/) override { }

        void UpdateAI(uint32 diff) override
        {
            if(!UpdateVictim())
                return;

            events.Update(diff);

            if(me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if(uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                case EVENT_BELCH:
                    DoCastVictim(SPELL_BELCH);
                    events.ScheduleEvent(EVENT_BELCH, urand(15*IN_MILLISECONDS, 20*IN_MILLISECONDS));
                    break;
                case EVENT_POISON_CLOUD:
                    DoCast(SPELL_POISON_CLOUD);
                    events.ScheduleEvent(EVENT_POISON_CLOUD, urand(10*IN_MILLISECONDS, 15*IN_MILLISECONDS));
                    break;
                case EVENT_REPULSIVE_KICK:
                    DoCastVictim(SPELL_REPULSIVE_KICK);
                    events.ScheduleEvent(EVENT_REPULSIVE_KICK, urand(10*IN_MILLISECONDS, 15*IN_MILLISECONDS));
                    break;
                case EVENT_BELOW5:
                    me->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_FEIGN_DEATH);
                    me->AddAura(SPELL_CADAVER_HOVER, me);
                    events.ScheduleEvent(EVENT_TAKEOFF, 5200);
                    break;
                case EVENT_TAKEOFF:
                    me->SetCanFly(true);
//                    me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
                    me->SetDisableGravity(true);
                    me->SetSpeed(MOVE_FLIGHT, 0.5f);
                    me->GetMotionMaster()->MovePoint(0, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ()+20.0f);
                    events.ScheduleEvent(EVENT_EXPLODE, 5600);
                    break;
                case EVENT_EXPLODE:
                    DoCast(SPELL_PLAGUE_EXPLOSION);
                    me->DespawnOrUnsummon(700);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    private:
        EventMap events;
        bool inhaled;
    };
};

/*####
## npc_lord_geoffery | TODO: Vehicle Transport npcs: wagen = 47523 ,pferd = 47522 ,anhenker = 47521
####*/

enum GeofferySpells
{
    SPELL_DEATH_BY_PEASANT        = 88619,
    SPELL_UNDYING_FRENZY           = 88616,
    SPELL_GEOF_UCUT                = 80182,
    SPELL_TRANSFORM_VISUAL         = 24085
};

enum GeofferyMisc
{
    DISPLAY_GEOF_WORGEN            = 34367
};

enum GeofferyEvents
{
    EVENT_DEATH_BY_PEASANT         = 1,
    EVENT_UNDYING_FRENZY,
    EVENT_GEOF_UCUT,
    EVENT_TRANSFORM
};

class npc_lord_geoffery : public CreatureScript
{
public:
    npc_lord_geoffery() : CreatureScript("npc_lord_geoffery") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_lord_geofferyAI (creature);
    }

    struct npc_lord_geofferyAI : public ScriptedAI
    {
        npc_lord_geofferyAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            transformed = false;
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            me->DespawnOrUnsummon(3000);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_DEATH_BY_PEASANT, 15000);
            events.ScheduleEvent(EVENT_GEOF_UCUT, 5000);
        }

        void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/) override
        {
            if(!transformed && !me->IsNonMeleeSpellCast(false) && HealthBelowPct(20))
            {
               transformed = true;
               DoCast(me, SPELL_TRANSFORM_VISUAL);
               me->SetDisplayId(DISPLAY_GEOF_WORGEN);
               me->SetSpeed(MOVE_RUN, 2.5f); // his speed changes when transforming (Retail 1.5 | PWS: 2.5)
               events.ScheduleEvent(EVENT_UNDYING_FRENZY, 2000);
            }
        }

        void JustDied(Unit* killer) override
        {
            if (Player* player = killer->GetCharmerOrOwnerPlayerOrPlayerItself())
            {
                player->GroupEventHappens(QUEST_THE_CRUCIBLE_OF_CARNAGE_THE_EARL_OF_EVIS, killer);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if(!UpdateVictim())
                return;

            events.Update(diff);

            if(me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if(uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                case EVENT_DEATH_BY_PEASANT:
                    DoCast(SPELL_DEATH_BY_PEASANT);
                    events.ScheduleEvent(EVENT_DEATH_BY_PEASANT, urand(30*IN_MILLISECONDS, 40*IN_MILLISECONDS));
                    break;
                case EVENT_UNDYING_FRENZY: // execute this event at 20% (needs retail info)
                    DoCastVictim(SPELL_UNDYING_FRENZY);
                    events.ScheduleEvent(EVENT_UNDYING_FRENZY, urand(10*IN_MILLISECONDS, 15*IN_MILLISECONDS));
                    break;
                case EVENT_GEOF_UCUT:
                    DoCastVictim(SPELL_UPPERCUT);
                    events.ScheduleEvent(EVENT_GEOF_UCUT, urand(15*IN_MILLISECONDS, 20*IN_MILLISECONDS));
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    private:
        EventMap events;
        bool transformed;
    };
};

/*####
## npc_emberscar_devourer
####*/

enum EmberSpells
{
    SPELL_ACTIVATE_POOLS           = 90409,
    SPELL_FIREBALL                 = 90446,
    SPELL_MAGMATIC_FAULT           = 90333
};

enum EmberEvents
{
    EVENT_ACTIVATE_POOLS           = 1,
    EVENT_FIREBALL,
    EVENT_MAG_FAULT
};

class npc_emberscar_devourer : public CreatureScript
{
public:
    npc_emberscar_devourer() : CreatureScript("npc_emberscar_devourer") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_emberscar_devourerAI (creature);
    }

    struct npc_emberscar_devourerAI : public ScriptedAI
    {
        npc_emberscar_devourerAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override { }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            me->DespawnOrUnsummon(3000);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_FIREBALL, 1000);
        }

        void JustDied(Unit* killer) override
        {
            if (Player* player = killer->GetCharmerOrOwnerPlayerOrPlayerItself())
            {
                player->GroupEventHappens(QUEST_THE_CRUCIBLE_OF_CARNAGE_THE_TWILIGHT_TERROR, killer);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if(!UpdateVictim())
                return;

            events.Update(diff);

            if(me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if(uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                case EVENT_FIREBALL:
                    DoCastVictim(SPELL_FIREBALL);
                    events.ScheduleEvent(EVENT_FIREBALL, 4000);
                    break;
                }
            }
        }
    private:
        EventMap events;
    };
};

/*####
## Arena Trash // Spellscripts
####*/

enum TrashSpells
{
    SPELL_GLOOM_BALL        = 88515,
};

enum TrashEvents
{
    EVENT_GLOOM_BALL        = 1,
};

class npc_gloomwing : public CreatureScript
{
public:
    npc_gloomwing() : CreatureScript("npc_gloomwing") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_gloomwingAI (creature);
    }

    struct npc_gloomwingAI : public ScriptedAI
    {
        npc_gloomwingAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE|UNIT_FLAG_NON_ATTACKABLE);
            me->SetHover(true);
            me->SetCanFly(true);
        }

        void Reset() override
        {
            if (Unit* playersearch = me->SelectNearestPlayer(300.0f))
                AttackStartNoMove(playersearch);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_GLOOM_BALL, 2000);
        }

        void AttackStart(Unit* who) override
        {
            if (!who)
                return;

            AttackStartNoMove(who);
        }

        void UpdateAI(uint32 diff) override
        {
            if(!UpdateVictim())
                return;

            events.Update(diff);

            if(me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if(uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                case EVENT_GLOOM_BALL:
                    DoCast(SPELL_GLOOM_BALL);
                    events.ScheduleEvent(EVENT_GLOOM_BALL, urand(3*IN_MILLISECONDS, 6*IN_MILLISECONDS));
                    break;
                }
            }
        }
    private:
        EventMap events;
    };
};

void AddSC_twilight_highlands()
{
    new npc_gurgthock_cata;
    new npc_hurp_derp;
    new npc_sully_kneecapper;
    new npc_torg_drakeflayer;
    new npc_cadaver_collage;
    new npc_lord_geoffery;
    new npc_emberscar_devourer;
    new npc_gloomwing();
}
