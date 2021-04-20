/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
SDName: Terokkar_Forest
SD%Complete: 85
SDComment: Quest support: 9889, 10898, 10052, 10051.
SDCategory: Terokkar Forest
EndScriptData */

/* ContentData
npc_unkor_the_ruthless
npc_isla_starmane
npc_skywing
npc_akuno
EndContentData */

#include "ScriptMgr.h"
#include "GameObject.h"
#include "Group.h"
#include "Player.h"
#include "ScriptedEscortAI.h"
#include "WorldSession.h"

/*######
## npc_unkor_the_ruthless
######*/

enum UnkorTheRuthless
{
    SAY_SUBMIT              = 0,
    REQUIRED_KILL_COUNT     = 10,
    SPELL_PULVERIZE         = 2676,
    QUEST_DONTKILLTHEFATONE = 9889,
    NPC_BOULDERFIST_INVADER = 18260
};

class npc_unkor_the_ruthless : public CreatureScript
{
public:
    npc_unkor_the_ruthless() : CreatureScript("npc_unkor_the_ruthless") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_unkor_the_ruthlessAI(creature);
    }

    struct npc_unkor_the_ruthlessAI : public ScriptedAI
    {
        npc_unkor_the_ruthlessAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            CanDoQuest = false;
            UnkorUnfriendly_Timer = 0;
            Pulverize_Timer = 3000;
        }

        bool CanDoQuest;
        uint32 UnkorUnfriendly_Timer;
        uint32 Pulverize_Timer;

        void Reset() override
        {
            Initialize();
            me->SetStandState(UNIT_STAND_STATE_STAND);
            me->SetFaction(FACTION_OGRE);
        }

        void JustEngagedWith(Unit* /*who*/) override { }

        void DoNice()
        {
            Talk(SAY_SUBMIT);
            me->SetFaction(FACTION_FRIENDLY);
            me->SetStandState(UNIT_STAND_STATE_SIT);
            me->RemoveAllAuras();
            me->GetThreatManager().ClearAllThreat();
            me->CombatStop(true);
            UnkorUnfriendly_Timer = 60000;
        }

        void DamageTaken(Unit* done_by, uint32 &damage) override
        {
            Player* player = done_by->ToPlayer();

            if (player && me->HealthBelowPctDamaged(30, damage))
            {
                if (Group* group = player->GetGroup())
                {
                    for (GroupReference* itr = group->GetFirstMember(); itr != nullptr; itr = itr->next())
                    {
                        Player* groupie = itr->GetSource();
                        if (groupie && groupie->IsInMap(player) &&
                            groupie->GetQuestStatus(QUEST_DONTKILLTHEFATONE) == QUEST_STATUS_INCOMPLETE &&
                            groupie->GetReqKillOrCastCurrentCount(QUEST_DONTKILLTHEFATONE, NPC_BOULDERFIST_INVADER) == REQUIRED_KILL_COUNT)
                        {
                            groupie->AreaExploredOrEventHappens(QUEST_DONTKILLTHEFATONE);
                            if (!CanDoQuest)
                                CanDoQuest = true;
                        }
                    }
                }
                else if (player->GetQuestStatus(QUEST_DONTKILLTHEFATONE) == QUEST_STATUS_INCOMPLETE &&
                    player->GetReqKillOrCastCurrentCount(QUEST_DONTKILLTHEFATONE, NPC_BOULDERFIST_INVADER) == REQUIRED_KILL_COUNT)
                {
                    player->AreaExploredOrEventHappens(QUEST_DONTKILLTHEFATONE);
                    CanDoQuest = true;
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (CanDoQuest)
            {
                if (!UnkorUnfriendly_Timer)
                {
                    //DoCast(me, SPELL_QUID9889);        //not using spell for now
                    DoNice();
                }
                else
                {
                    if (UnkorUnfriendly_Timer <= diff)
                    {
                        EnterEvadeMode();
                        return;
                    } else UnkorUnfriendly_Timer -= diff;
                }
            }

            if (!UpdateVictim())
                return;

            if (Pulverize_Timer <= diff)
            {
                DoCast(me, SPELL_PULVERIZE);
                Pulverize_Timer = 9000;
            } else Pulverize_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

/*######
## npc_skywing
######*/

enum Skywing
{
    QUEST_SKYWING = 10898
};

class npc_skywing : public CreatureScript
{
public:
    npc_skywing() : CreatureScript("npc_skywing") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_skywingAI(creature);
    }

    struct npc_skywingAI : public EscortAI
    {
    public:
        npc_skywingAI(Creature* creature) : EscortAI(creature) { }

        void WaypointReached(uint32 waypointId, uint32 /*pathId*/) override
        {
            Player* player = GetPlayerForEscort();
            if (!player)
                return;

            switch (waypointId)
            {
                case 8:
                    player->AreaExploredOrEventHappens(QUEST_SKYWING);
                    break;
            }
        }

        void JustEngagedWith(Unit* /*who*/) override { }

        void MoveInLineOfSight(Unit* who) override

        {
            if (HasEscortState(STATE_ESCORT_ESCORTING))
                return;

            Player* player = who->ToPlayer();
            if (player && player->GetQuestStatus(QUEST_SKYWING) == QUEST_STATUS_INCOMPLETE)
                if (me->IsWithinDistInMap(who, 10.0f))
                    Start(false, false, who->GetGUID());
        }

        void Reset() override { }

        void UpdateAI(uint32 diff) override
        {
            EscortAI::UpdateAI(diff);
        }
    };
};

/*######
## npc_isla_starmane
######*/
enum IslaStarmaneData
{
    SAY_PROGRESS_1               = 0,
    SAY_PROGRESS_2               = 1,
    SAY_PROGRESS_3               = 2,
    SAY_PROGRESS_4               = 3,
    GO_DISTANCE                  = 10,
    ESCAPE_FROM_FIREWING_POINT_A = 10051,
    ESCAPE_FROM_FIREWING_POINT_H = 10052,
    SPELL_TRAVEL_FORM_CAT        = 32447,
    GO_CAGE                      = 182794
};

class npc_isla_starmane : public CreatureScript
{
public:
    npc_isla_starmane() : CreatureScript("npc_isla_starmane") { }

    struct npc_isla_starmaneAI : public EscortAI
    {
        npc_isla_starmaneAI(Creature* creature) : EscortAI(creature) { }

        void WaypointReached(uint32 waypointId, uint32 /*pathId*/) override
        {
            Player* player = GetPlayerForEscort();
            if (!player)
                return;

            switch (waypointId)
            {
                case 0:
                    if (GameObject* Cage = me->FindNearestGameObject(GO_CAGE, GO_DISTANCE))
                        Cage->SetGoState(GO_STATE_ACTIVE);
                    break;
                case 2:
                    Talk(SAY_PROGRESS_1, player);
                    break;
                case 5:
                    Talk(SAY_PROGRESS_2, player);
                    break;
                case 6:
                    Talk(SAY_PROGRESS_3, player);
                    break;
                case 29:
                    Talk(SAY_PROGRESS_4, player);
                    if (player->GetTeam() == ALLIANCE)
                        player->GroupEventHappens(ESCAPE_FROM_FIREWING_POINT_A, me);
                    else if (player->GetTeam() == HORDE)
                        player->GroupEventHappens(ESCAPE_FROM_FIREWING_POINT_H, me);
                    me->SetFacingToObject(player);
                    break;
                case 30:
                    me->HandleEmoteCommand(EMOTE_ONESHOT_WAVE);
                    break;
                case 31:
                    DoCast(me, SPELL_TRAVEL_FORM_CAT);
                    me->SetWalk(false);
                    break;
            }
        }

        void Reset() override
        {
            me->RestoreFaction();
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (Player* player = GetPlayerForEscort())
            {
                if (player->GetTeam() == ALLIANCE)
                    player->FailQuest(ESCAPE_FROM_FIREWING_POINT_A);
                else if (player->GetTeam() == HORDE)
                    player->FailQuest(ESCAPE_FROM_FIREWING_POINT_H);
            }
        }

        void QuestAccept(Player* player, Quest const* quest) override
        {
            if (quest->GetQuestId() == ESCAPE_FROM_FIREWING_POINT_H || quest->GetQuestId() == ESCAPE_FROM_FIREWING_POINT_A)
            {
                Start(true, false, player->GetGUID());
                me->SetFaction(FACTION_ESCORTEE_N_NEUTRAL_PASSIVE);
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_isla_starmaneAI(creature);
    }
};

/*########
####npc_akuno
#####*/

enum Akuno
{
    QUEST_ESCAPING_THE_TOMB = 10887,
    NPC_CABAL_SKRIMISHER    = 21661
};

class npc_akuno : public CreatureScript
{
public:
    npc_akuno() : CreatureScript("npc_akuno") { }

    struct npc_akunoAI : public EscortAI
    {
        npc_akunoAI(Creature* creature) : EscortAI(creature) { }

        void WaypointReached(uint32 waypointId, uint32 /*pathId*/) override
        {
            Player* player = GetPlayerForEscort();
            if (!player)
                return;

            switch (waypointId)
            {
                case 3:
                    me->SummonCreature(NPC_CABAL_SKRIMISHER, -2795.99f, 5420.33f, -34.53f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                    me->SummonCreature(NPC_CABAL_SKRIMISHER, -2793.55f, 5412.79f, -34.53f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                    break;
                case 11:
                    if (player->GetTypeId() == TYPEID_PLAYER)
                        player->GroupEventHappens(QUEST_ESCAPING_THE_TOMB, me);
                    break;
            }
        }

        void JustSummoned(Creature* summon) override
        {
            summon->AI()->AttackStart(me);
        }

        void QuestAccept(Player* player, Quest const* quest) override
        {
            if (quest->GetQuestId() == QUEST_ESCAPING_THE_TOMB)
            {
                Start(false, false, player->GetGUID());

                if (player->GetTeamId() == TEAM_ALLIANCE)
                    me->SetFaction(FACTION_ESCORTEE_A_NEUTRAL_PASSIVE);
                else
                    me->SetFaction(FACTION_ESCORTEE_H_NEUTRAL_PASSIVE);
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_akunoAI(creature);
    }
};

void AddSC_terokkar_forest()
{
    new npc_unkor_the_ruthless();
    new npc_isla_starmane();
    new npc_skywing();
    new npc_akuno();
}
