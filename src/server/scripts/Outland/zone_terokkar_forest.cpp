/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDComment: Quest support: 9889, 10009, 10873, 10896, 10898, 11096, 10052, 10051. Skettis->Ogri'la Flight
SDCategory: Terokkar Forest
EndScriptData */

/* ContentData
npc_unkor_the_ruthless
npc_infested_root_walker
npc_rotting_forest_rager
npc_floon
npc_isla_starmane
npc_slim
EndContentData */

#include "ScriptMgr.h"
#include "GameObject.h"
#include "Group.h"
#include "Player.h"
#include "ScriptedEscortAI.h"
#include "ScriptedGossip.h"
#include "WorldSession.h"

/*######
## npc_unkor_the_ruthless
######*/

enum UnkorTheRuthless
{
    SAY_SUBMIT              = 0,
    REQUIRED_KILL_COUNT     = 10,
    FACTION_FRIENDLY        = 35,
    FACTION_HOSTILE         = 45,
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
            me->setFaction(FACTION_HOSTILE);
        }

        void EnterCombat(Unit* /*who*/) override { }

        void DoNice()
        {
            Talk(SAY_SUBMIT);
            me->setFaction(FACTION_FRIENDLY);
            me->SetStandState(UNIT_STAND_STATE_SIT);
            me->RemoveAllAuras();
            me->DeleteThreatList();
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
                    for (GroupReference* itr = group->GetFirstMember(); itr != NULL; itr = itr->next())
                    {
                        Player* groupie = itr->GetSource();
                        if (groupie &&
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
## npc_infested_root_walker
######*/

enum InfestedRootWalker
{
    SPELL_SUMMON_WOOD_MITES = 39130
};

class npc_infested_root_walker : public CreatureScript
{
public:
    npc_infested_root_walker() : CreatureScript("npc_infested_root_walker") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_infested_root_walkerAI(creature);
    }

    struct npc_infested_root_walkerAI : public ScriptedAI
    {
        npc_infested_root_walkerAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override { }
        void EnterCombat(Unit* /*who*/) override { }

        void DamageTaken(Unit* done_by, uint32 &damage) override
        {
            if (done_by && done_by->GetTypeId() == TYPEID_PLAYER)
                if (me->GetHealth() <= damage)
                    if (rand32() % 100 < 75)
                        //Summon Wood Mites
                        DoCast(me, SPELL_SUMMON_WOOD_MITES, true);
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

    struct npc_skywingAI : public npc_escortAI
    {
    public:
        npc_skywingAI(Creature* creature) : npc_escortAI(creature) { }

        void WaypointReached(uint32 waypointId) override
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

        void EnterCombat(Unit* /*who*/) override { }

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
            npc_escortAI::UpdateAI(diff);
        }
    };
};

/*######
## npc_rotting_forest_rager
######*/

enum RottingForestRager
{
    SPELL_SUMMON_LOTS_OF_WOOD_MITES = 39134
};

class npc_rotting_forest_rager : public CreatureScript
{
public:
    npc_rotting_forest_rager() : CreatureScript("npc_rotting_forest_rager") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_rotting_forest_ragerAI(creature);
    }

    struct npc_rotting_forest_ragerAI : public ScriptedAI
    {
        npc_rotting_forest_ragerAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override { }
        void EnterCombat(Unit* /*who*/) override { }

        void DamageTaken(Unit* done_by, uint32 &damage) override
        {
            if (done_by->GetTypeId() == TYPEID_PLAYER)
                if (me->GetHealth() <= damage)
                    if (rand32() % 100 < 75)
                        //Summon Lots of Wood Mites
                        DoCast(me, SPELL_SUMMON_LOTS_OF_WOOD_MITES, true);
        }
    };
};

/*######
## npc_floon
######*/

enum Floon
{
    SAY_FLOON_ATTACK            = 0,
    OPTION_ID_PAY_UP_OR_DIE     = 0,
    OPTION_ID_COLLECT_A_DEBT    = 0,
    FACTION_HOSTILE_FLOON       = 1738,
    MENU_ID_PAY_UP_OR_DIE       = 7731,
    MENU_ID_COLLECT_A_DEBT      = 7732,
    GOSSIP_FLOON_STRANGE_SOUNDS = 9442,
    GOSSIP_HE_ALREADY_KILLED_ME = 9443,

    SPELL_SILENCE               = 6726,
    SPELL_FROSTBOLT             = 9672,
    SPELL_FROST_NOVA            = 11831,

    QUEST_CRACKIN_SOME_SKULLS   = 10009
};

class npc_floon : public CreatureScript
{
public:
    npc_floon() : CreatureScript("npc_floon") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        ClearGossipMenuFor(player);
        if (action == GOSSIP_ACTION_INFO_DEF)
        {
            AddGossipItemFor(player, MENU_ID_PAY_UP_OR_DIE, OPTION_ID_PAY_UP_OR_DIE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
            SendGossipMenuFor(player, GOSSIP_HE_ALREADY_KILLED_ME, creature->GetGUID());
        }
        if (action == GOSSIP_ACTION_INFO_DEF+1)
        {
            CloseGossipMenuFor(player);
            creature->setFaction(FACTION_HOSTILE_FLOON);
            creature->AI()->Talk(SAY_FLOON_ATTACK, player);
            creature->AI()->AttackStart(player);
        }
        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (player->GetQuestStatus(QUEST_CRACKIN_SOME_SKULLS) == QUEST_STATUS_INCOMPLETE)
            AddGossipItemFor(player, MENU_ID_COLLECT_A_DEBT, OPTION_ID_COLLECT_A_DEBT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);

        SendGossipMenuFor(player, GOSSIP_FLOON_STRANGE_SOUNDS, creature->GetGUID());
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_floonAI(creature);
    }

    struct npc_floonAI : public ScriptedAI
    {
        npc_floonAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            m_uiNormFaction = creature->getFaction();
        }

        void Initialize()
        {
            Silence_Timer = 2000;
            Frostbolt_Timer = 4000;
            FrostNova_Timer = 9000;
        }

        uint32 m_uiNormFaction;
        uint32 Silence_Timer;
        uint32 Frostbolt_Timer;
        uint32 FrostNova_Timer;

        void Reset() override
        {
            Initialize();
            if (me->getFaction() != m_uiNormFaction)
                me->setFaction(m_uiNormFaction);
        }

        void EnterCombat(Unit* /*who*/) override { }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (Silence_Timer <= diff)
            {
                DoCastVictim(SPELL_SILENCE);
                Silence_Timer = 30000;
            } else Silence_Timer -= diff;

            if (FrostNova_Timer <= diff)
            {
                DoCast(me, SPELL_FROST_NOVA);
                FrostNova_Timer = 20000;
            } else FrostNova_Timer -= diff;

            if (Frostbolt_Timer <= diff)
            {
                DoCastVictim(SPELL_FROSTBOLT);
                Frostbolt_Timer = 5000;
            } else Frostbolt_Timer -= diff;

            DoMeleeAttackIfReady();
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
    FACTION_ESCORTEE             = 113,
    ESCAPE_FROM_FIREWING_POINT_A = 10051,
    ESCAPE_FROM_FIREWING_POINT_H = 10052,
    SPELL_TRAVEL_FORM_CAT        = 32447,
    GO_CAGE                      = 182794
};

class npc_isla_starmane : public CreatureScript
{
public:
    npc_isla_starmane() : CreatureScript("npc_isla_starmane") { }

    struct npc_isla_starmaneAI : public npc_escortAI
    {
        npc_isla_starmaneAI(Creature* creature) : npc_escortAI(creature) { }

        void WaypointReached(uint32 waypointId) override
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
                    me->SetInFront(player);
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
    };

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest) override
    {
        if (quest->GetQuestId() == ESCAPE_FROM_FIREWING_POINT_H || quest->GetQuestId() == ESCAPE_FROM_FIREWING_POINT_A)
        {
            ENSURE_AI(npc_escortAI, (creature->AI()))->Start(true, false, player->GetGUID());
            creature->setFaction(FACTION_ESCORTEE);
        }
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_isla_starmaneAI(creature);
    }
};

/*######
## go_skull_pile
######*/

enum SkullPile
{
    OPTION_ID_GEZZARAK_THE_HUNTRESS = 0,
    OPTION_ID_DARKSCREECHER_AKKARAI = 1,
    OPTION_ID_KARROG                = 2,
    OPTION_ID_VAKKIZ_THE_WINDRAGER  = 3,
    GOSSIP_MENU_ID_SKULL_PILE       = 8660,
    ADVERSARIAL_BLOOD               = 11885,
    SUMMON_GEZZARAK_THE_HUNTRESS    = 40632,
    SUMMON_KARROG                   = 40640,
    SUMMON_DARKSCREECHER_AKKARAI    = 40642,
    SUMMON_VAKKIZ_THE_WINDRAGER     = 40644
};

class go_skull_pile : public GameObjectScript
{
public:
    go_skull_pile() : GameObjectScript("go_skull_pile") { }

    bool OnGossipSelect(Player* player, GameObject* go, uint32 sender, uint32 action) override
    {
        ClearGossipMenuFor(player);
        switch (sender)
        {
            case GOSSIP_SENDER_MAIN:    SendActionMenu(player, go, action); break;
        }
        return true;
    }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        if ((player->GetQuestStatus(ADVERSARIAL_BLOOD) == QUEST_STATUS_INCOMPLETE) || player->GetQuestRewardStatus(ADVERSARIAL_BLOOD))
        {
            AddGossipItemFor(player, GOSSIP_MENU_ID_SKULL_PILE, OPTION_ID_GEZZARAK_THE_HUNTRESS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            AddGossipItemFor(player, GOSSIP_MENU_ID_SKULL_PILE, OPTION_ID_DARKSCREECHER_AKKARAI, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
            AddGossipItemFor(player, GOSSIP_MENU_ID_SKULL_PILE, OPTION_ID_KARROG,                GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
            AddGossipItemFor(player, GOSSIP_MENU_ID_SKULL_PILE, OPTION_ID_VAKKIZ_THE_WINDRAGER,  GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
        }

        SendGossipMenuFor(player, go->GetGOInfo()->questgiver.gossipID, go->GetGUID());
        return true;
    }

    void SendActionMenu(Player* player, GameObject* /*go*/, uint32 action)
    {
        switch (action)
        {
            case GOSSIP_ACTION_INFO_DEF + 1:
                  player->CastSpell(player, SUMMON_GEZZARAK_THE_HUNTRESS, false);
                break;
            case GOSSIP_ACTION_INFO_DEF + 2:
                  player->CastSpell(player, SUMMON_DARKSCREECHER_AKKARAI, false);
                break;
            case GOSSIP_ACTION_INFO_DEF + 3:
                  player->CastSpell(player, SUMMON_KARROG, false);
                break;
            case GOSSIP_ACTION_INFO_DEF + 4:
                  player->CastSpell(player, SUMMON_VAKKIZ_THE_WINDRAGER, false);
                break;
        }
    }
};

/*######
## npc_slim
######*/

enum Slim
{
    FACTION_CONSORTIUM  = 933,
    NPC_TEXT_NEITHER_SLIM_NOR_SHADY = 9895,
    NPC_TEXT_I_SEE_YOU_ARE_A_FRIEND = 9896
};

class npc_slim : public CreatureScript
{
public:
    npc_slim() : CreatureScript("npc_slim") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        ClearGossipMenuFor(player);
        if (action == GOSSIP_ACTION_TRADE)
            player->GetSession()->SendListInventory(creature->GetGUID());

        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (creature->IsVendor() && player->GetReputationRank(FACTION_CONSORTIUM) >= REP_FRIENDLY)
        {
            AddGossipItemFor(player, GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);
            SendGossipMenuFor(player, NPC_TEXT_I_SEE_YOU_ARE_A_FRIEND, creature->GetGUID());
        }
        else
            SendGossipMenuFor(player, NPC_TEXT_NEITHER_SLIM_NOR_SHADY, creature->GetGUID());

        return true;
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

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_ESCAPING_THE_TOMB)
        {
            if (npc_akunoAI* pEscortAI = CAST_AI(npc_akuno::npc_akunoAI, creature->AI()))
                pEscortAI->Start(false, false, player->GetGUID());

            if (player->GetTeamId() == TEAM_ALLIANCE)
                creature->setFaction(FACTION_ESCORT_A_NEUTRAL_PASSIVE);
            else
                creature->setFaction(FACTION_ESCORT_H_NEUTRAL_PASSIVE);
        }
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_akunoAI(creature);
    }

    struct npc_akunoAI : public npc_escortAI
    {
        npc_akunoAI(Creature* creature) : npc_escortAI(creature) { }

        void WaypointReached(uint32 waypointId) override
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
    };
};

void AddSC_terokkar_forest()
{
    new npc_unkor_the_ruthless();
    new npc_infested_root_walker();
    new npc_rotting_forest_rager();
    new npc_floon();
    new npc_isla_starmane();
    new go_skull_pile();
    new npc_skywing();
    new npc_slim();
    new npc_akuno();
}
