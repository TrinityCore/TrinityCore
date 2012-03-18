/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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
SDName: The_Barrens
SD%Complete: 90
SDComment: Quest support: 863, 898, 1719, 2458, 4921, 6981,
SDCategory: Barrens
EndScriptData */

/* ContentData
npc_beaten_corpse
npc_gilthares
npc_sputtervalve
npc_taskmaster_fizzule
npc_twiggy_flathead
npc_wizzlecrank_shredder
EndContentData */

#include "ScriptPCH.h"
#include "ScriptedEscortAI.h"

/*######
## npc_beaten_corpse
######*/

#define GOSSIP_CORPSE "Examine corpse in detail..."

enum eQuests
{
    QUEST_LOST_IN_BATTLE    = 4921
};

class npc_beaten_corpse : public CreatureScript
{
public:
    npc_beaten_corpse() : CreatureScript("npc_beaten_corpse") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        if (action == GOSSIP_ACTION_INFO_DEF +1)
        {
            player->SEND_GOSSIP_MENU(3558, creature->GetGUID());
            player->TalkedToCreature(creature->GetEntry(), creature->GetGUID());
        }
        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (player->GetQuestStatus(QUEST_LOST_IN_BATTLE) == QUEST_STATUS_INCOMPLETE || player->GetQuestStatus(QUEST_LOST_IN_BATTLE) == QUEST_STATUS_COMPLETE)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_CORPSE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        player->SEND_GOSSIP_MENU(3557, creature->GetGUID());
        return true;
    }

};

/*######
# npc_gilthares
######*/

enum eGilthares
{
    SAY_GIL_START               = -1000370,
    SAY_GIL_AT_LAST             = -1000371,
    SAY_GIL_PROCEED             = -1000372,
    SAY_GIL_FREEBOOTERS         = -1000373,
    SAY_GIL_AGGRO_1             = -1000374,
    SAY_GIL_AGGRO_2             = -1000375,
    SAY_GIL_AGGRO_3             = -1000376,
    SAY_GIL_AGGRO_4             = -1000377,
    SAY_GIL_ALMOST              = -1000378,
    SAY_GIL_SWEET               = -1000379,
    SAY_GIL_FREED               = -1000380,

    QUEST_FREE_FROM_HOLD        = 898,
    AREA_MERCHANT_COAST         = 391,
    FACTION_ESCORTEE            = 232                       //guessed, possible not needed for this quest
};

class npc_gilthares : public CreatureScript
{
public:
    npc_gilthares() : CreatureScript("npc_gilthares") { }

    bool OnQuestAccept(Player* player, Creature* creature, const Quest* quest)
    {
        if (quest->GetQuestId() == QUEST_FREE_FROM_HOLD)
        {
            creature->setFaction(FACTION_ESCORTEE);
            creature->SetStandState(UNIT_STAND_STATE_STAND);

            DoScriptText(SAY_GIL_START, creature, player);

            if (npc_giltharesAI* pEscortAI = CAST_AI(npc_gilthares::npc_giltharesAI, creature->AI()))
                pEscortAI->Start(false, false, player->GetGUID(), quest);
        }
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_giltharesAI(creature);
    }

    struct npc_giltharesAI : public npc_escortAI
    {
        npc_giltharesAI(Creature* creature) : npc_escortAI(creature) { }

        void Reset() { }

        void WaypointReached(uint32 uiPointId)
        {
            Player* player = GetPlayerForEscort();

            if (!player)
                return;

            switch (uiPointId)
            {
                case 16:
                    DoScriptText(SAY_GIL_AT_LAST, me, player);
                    break;
                case 17:
                    DoScriptText(SAY_GIL_PROCEED, me, player);
                    break;
                case 18:
                    DoScriptText(SAY_GIL_FREEBOOTERS, me, player);
                    break;
                case 37:
                    DoScriptText(SAY_GIL_ALMOST, me, player);
                    break;
                case 47:
                    DoScriptText(SAY_GIL_SWEET, me, player);
                    break;
                case 53:
                    DoScriptText(SAY_GIL_FREED, me, player);
                    player->GroupEventHappens(QUEST_FREE_FROM_HOLD, me);
                    break;
            }
        }

        void EnterCombat(Unit* who)
        {
            //not always use
            if (rand()%4)
                return;

            //only aggro text if not player and only in this area
            if (who->GetTypeId() != TYPEID_PLAYER && me->GetAreaId() == AREA_MERCHANT_COAST)
            {
                //appears to be pretty much random (possible only if escorter not in combat with who yet?)
                DoScriptText(RAND(SAY_GIL_AGGRO_1, SAY_GIL_AGGRO_2, SAY_GIL_AGGRO_3, SAY_GIL_AGGRO_4), me, who);
            }
        }
    };

};

/*######
## npc_sputtervalve
######*/

#define GOSSIP_SPUTTERVALVE "Can you tell me about this shard?"

class npc_sputtervalve : public CreatureScript
{
public:
    npc_sputtervalve() : CreatureScript("npc_sputtervalve") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        if (action == GOSSIP_ACTION_INFO_DEF)
        {
            player->SEND_GOSSIP_MENU(2013, creature->GetGUID());
            player->AreaExploredOrEventHappens(6981);
        }
        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (creature->isQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        if (player->GetQuestStatus(6981) == QUEST_STATUS_INCOMPLETE)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SPUTTERVALVE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);

        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
        return true;
    }

};

/*######
## npc_taskmaster_fizzule
######*/

enum eEnums
{
    FACTION_FRIENDLY_F  = 35,
    SPELL_FLARE         = 10113,
    SPELL_FOLLY         = 10137,
};

class npc_taskmaster_fizzule : public CreatureScript
{
public:
    npc_taskmaster_fizzule() : CreatureScript("npc_taskmaster_fizzule") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_taskmaster_fizzuleAI(creature);
    }

    struct npc_taskmaster_fizzuleAI : public ScriptedAI
    {
        npc_taskmaster_fizzuleAI(Creature* creature) : ScriptedAI(creature)
        {
            factionNorm = creature->getFaction();
        }

        uint32 factionNorm;
        bool IsFriend;
        uint32 Reset_Timer;
        uint8 FlareCount;

        void Reset()
        {
            IsFriend = false;
            Reset_Timer = 120000;
            FlareCount = 0;
            me->setFaction(factionNorm);
        }

        void DoFriend()
        {
            me->RemoveAllAuras();
            me->DeleteThreatList();
            me->CombatStop(true);

            me->StopMoving();
            me->GetMotionMaster()->MoveIdle();

            me->setFaction(FACTION_FRIENDLY_F);
            me->HandleEmoteCommand(EMOTE_ONESHOT_SALUTE);
        }

        void SpellHit(Unit* /*caster*/, const SpellInfo* spell)
        {
            if (spell->Id == SPELL_FLARE || spell->Id == SPELL_FOLLY)
            {
                ++FlareCount;

                if (FlareCount >= 2)
                    IsFriend = true;
            }
        }

        void EnterCombat(Unit* /*who*/) {}

        void UpdateAI(const uint32 diff)
        {
            if (IsFriend)
            {
                if (Reset_Timer <= diff)
                {
                    EnterEvadeMode();
                    return;
                } else Reset_Timer -= diff;
            }

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

        void ReceiveEmote(Player* /*player*/, uint32 emote)
        {
            if (emote == TEXT_EMOTE_SALUTE)
            {
                if (FlareCount >= 2)
                {
                    if (me->getFaction() == FACTION_FRIENDLY_F)
                        return;

                    DoFriend();
                }
            }
        }
    };

};

/*#####
## npc_twiggy_flathead
#####*/

enum eTwiggyFlathead
{
    NPC_BIG_WILL                = 6238,
    NPC_AFFRAY_CHALLENGER       = 6240,

    SAY_BIG_WILL_READY          = -1000123,
    SAY_TWIGGY_FLATHEAD_BEGIN   = -1000124,
    SAY_TWIGGY_FLATHEAD_FRAY    = -1000125,
    SAY_TWIGGY_FLATHEAD_DOWN    = -1000126,
    SAY_TWIGGY_FLATHEAD_OVER    = -1000127,
};

float AffrayChallengerLoc[6][4]=
{
    {-1683.0f, -4326.0f, 2.79f, 0.0f},
    {-1682.0f, -4329.0f, 2.79f, 0.0f},
    {-1683.0f, -4330.0f, 2.79f, 0.0f},
    {-1680.0f, -4334.0f, 2.79f, 1.49f},
    {-1674.0f, -4326.0f, 2.79f, 3.49f},
    {-1677.0f, -4334.0f, 2.79f, 1.66f}
};

class npc_twiggy_flathead : public CreatureScript
{
public:
    npc_twiggy_flathead() : CreatureScript("npc_twiggy_flathead") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_twiggy_flatheadAI (creature);
    }

    struct npc_twiggy_flatheadAI : public ScriptedAI
    {
        npc_twiggy_flatheadAI(Creature* creature) : ScriptedAI(creature) {}

        bool EventInProgress;
        bool EventGrate;
        bool EventBigWill;
        bool Challenger_down[6];
        uint32 Wave;
        uint32 Wave_Timer;
        uint32 Challenger_checker;
        uint64 PlayerGUID;
        uint64 AffrayChallenger[6];
        uint64 BigWill;

        void Reset()
        {
            EventInProgress = false;
            EventGrate = false;
            EventBigWill = false;
            Wave_Timer = 600000;
            Challenger_checker = 0;
            Wave = 0;
            PlayerGUID = 0;

            for (uint8 i = 0; i < 6; ++i)
            {
                AffrayChallenger[i] = 0;
                Challenger_down[i] = false;
            }
            BigWill = 0;
        }

        void EnterCombat(Unit* /*who*/) { }

        void MoveInLineOfSight(Unit* who)
        {
            if (!who || (!who->isAlive()))
                return;

            if (me->IsWithinDistInMap(who, 10.0f) && (who->GetTypeId() == TYPEID_PLAYER) && CAST_PLR(who)->GetQuestStatus(1719) == QUEST_STATUS_INCOMPLETE && !EventInProgress)
            {
                PlayerGUID = who->GetGUID();
                EventInProgress = true;
            }
        }

        void KilledUnit(Unit* /*victim*/) { }

        void UpdateAI(const uint32 diff)
        {
            if (EventInProgress) {
                Player* pWarrior = NULL;

                if (PlayerGUID)
                    pWarrior = Unit::GetPlayer(*me, PlayerGUID);

                if (!pWarrior)
                    return;

                if (!pWarrior->isAlive() && pWarrior->GetQuestStatus(1719) == QUEST_STATUS_INCOMPLETE) {
                    EventInProgress = false;
                    DoScriptText(SAY_TWIGGY_FLATHEAD_DOWN, me);
                    pWarrior->FailQuest(1719);

                    for (uint8 i = 0; i < 6; ++i)
                    {
                        if (AffrayChallenger[i])
                        {
                            Creature* creature = Unit::GetCreature((*me), AffrayChallenger[i]);
                            if (creature) {
                                if (creature->isAlive())
                                {
                                    creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IN_COMBAT);
                                    creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                                    creature->setDeathState(JUST_DIED);
                                }
                            }
                        }
                        AffrayChallenger[i] = 0;
                        Challenger_down[i] = false;
                    }

                    if (BigWill)
                    {
                        Creature* creature = Unit::GetCreature((*me), BigWill);
                        if (creature)
                        {
                            if (creature->isAlive())
                            {
                                creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IN_COMBAT);
                                creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                                creature->setDeathState(JUST_DIED);
                            }
                        }
                    }
                    BigWill = 0;
                }

                if (!EventGrate && EventInProgress)
                {
                    float x, y, z;
                    pWarrior->GetPosition(x, y, z);

                    if (x >= -1684 && x <= -1674 && y >= -4334 && y <= -4324) {
                        pWarrior->AreaExploredOrEventHappens(1719);
                        DoScriptText(SAY_TWIGGY_FLATHEAD_BEGIN, me);

                        for (uint8 i = 0; i < 6; ++i)
                        {
                            Creature* creature = me->SummonCreature(NPC_AFFRAY_CHALLENGER, AffrayChallengerLoc[i][0], AffrayChallengerLoc[i][1], AffrayChallengerLoc[i][2], AffrayChallengerLoc[i][3], TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 600000);
                            if (!creature)
                                continue;
                            creature->setFaction(35);
                            creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                            creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            creature->HandleEmoteCommand(EMOTE_ONESHOT_ROAR);
                            AffrayChallenger[i] = creature->GetGUID();
                        }
                        Wave_Timer = 5000;
                        Challenger_checker = 1000;
                        EventGrate = true;
                    }
                }
                else if (EventInProgress)
                {
                    if (Challenger_checker <= diff)
                    {
                        for (uint8 i = 0; i < 6; ++i)
                        {
                            if (AffrayChallenger[i])
                            {
                                Creature* creature = Unit::GetCreature((*me), AffrayChallenger[i]);
                                if ((!creature || (!creature->isAlive())) && !Challenger_down[i])
                                {
                                    DoScriptText(SAY_TWIGGY_FLATHEAD_DOWN, me);
                                    Challenger_down[i] = true;
                                }
                            }
                        }
                        Challenger_checker = 1000;
                    } else Challenger_checker -= diff;

                    if (Wave_Timer <= diff)
                    {
                        if (Wave < 6 && AffrayChallenger[Wave] && !EventBigWill)
                        {
                            DoScriptText(SAY_TWIGGY_FLATHEAD_FRAY, me);
                            Creature* creature = Unit::GetCreature((*me), AffrayChallenger[Wave]);
                            if (creature && (creature->isAlive()))
                            {
                                creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                                creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                                creature->HandleEmoteCommand(EMOTE_ONESHOT_ROAR);
                                creature->setFaction(14);
                                creature->AI()->AttackStart(pWarrior);
                                ++Wave;
                                Wave_Timer = 20000;
                            }
                        }
                        else if (Wave >= 6 && !EventBigWill) {
                            if (Creature* creature = me->SummonCreature(NPC_BIG_WILL, -1722, -4341, 6.12f, 6.26f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 480000))
                            {
                                BigWill = creature->GetGUID();
                                //creature->GetMotionMaster()->MovePoint(0, -1693, -4343, 4.32f);
                                //creature->GetMotionMaster()->MovePoint(1, -1684, -4333, 2.78f);
                                creature->GetMotionMaster()->MovePoint(2, -1682, -4329, 2.79f);
                                creature->HandleEmoteCommand(EMOTE_STATE_READY_UNARMED);
                                EventBigWill = true;
                                Wave_Timer = 1000;
                            }
                        }
                        else if (Wave >= 6 && EventBigWill && BigWill)
                        {
                            Creature* creature = Unit::GetCreature((*me), BigWill);
                            if (!creature || !creature->isAlive())
                            {
                                DoScriptText(SAY_TWIGGY_FLATHEAD_OVER, me);
                                EventInProgress = false;
                                EventBigWill = false;
                                EventGrate = false;
                                PlayerGUID = 0;
                                Wave = 0;
                            }
                        }
                    } else Wave_Timer -= diff;
                }
            }
        }
    };

};

/*#####
## npc_wizzlecrank_shredder
#####*/

enum eEnums_Wizzlecrank
{
    SAY_START           = -1000298,
    SAY_STARTUP1        = -1000299,
    SAY_STARTUP2        = -1000300,
    SAY_MERCENARY       = -1000301,
    SAY_PROGRESS_1      = -1000302,
    SAY_PROGRESS_2      = -1000303,
    SAY_PROGRESS_3      = -1000304,
    SAY_END             = -1000305,

    QUEST_ESCAPE        = 863,
    FACTION_RATCHET     = 637,
    NPC_PILOT_WIZZ      = 3451,
    NPC_MERCENARY       = 3282,
};

class npc_wizzlecrank_shredder : public CreatureScript
{
public:
    npc_wizzlecrank_shredder() : CreatureScript("npc_wizzlecrank_shredder") { }

    struct npc_wizzlecrank_shredderAI : public npc_escortAI
    {
        npc_wizzlecrank_shredderAI(Creature* creature) : npc_escortAI(creature)
        {
            m_bIsPostEvent = false;
            m_uiPostEventTimer = 1000;
            m_uiPostEventCount = 0;
        }

        bool m_bIsPostEvent;
        uint32 m_uiPostEventTimer;
        uint32 m_uiPostEventCount;

        void Reset()
        {
            if (!HasEscortState(STATE_ESCORT_ESCORTING))
            {
                if (me->getStandState() == UNIT_STAND_STATE_DEAD)
                     me->SetStandState(UNIT_STAND_STATE_STAND);

                m_bIsPostEvent = false;
                m_uiPostEventTimer = 1000;
                m_uiPostEventCount = 0;
            }
        }

        void WaypointReached(uint32 uiPointId)
        {
            Player* player = GetPlayerForEscort();

            if (!player)
                return;

            switch (uiPointId)
            {
            case 0:
                DoScriptText(SAY_STARTUP1, me);
                break;
            case 9:
                SetRun(false);
                break;
            case 17:
                if (Creature* temp = me->SummonCreature(NPC_MERCENARY, 1128.489f, -3037.611f, 92.701f, 1.472f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 120000))
                {
                    DoScriptText(SAY_MERCENARY, temp);
                    me->SummonCreature(NPC_MERCENARY, 1160.172f, -2980.168f, 97.313f, 3.690f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 120000);
                }
                break;
            case 24:
                m_bIsPostEvent = true;
                break;
            }
        }

        void WaypointStart(uint32 uiPointId)
        {
            Player* player = GetPlayerForEscort();

            if (!player)
                return;

            switch (uiPointId)
            {
                case 9:
                    DoScriptText(SAY_STARTUP2, me, player);
                    break;
                case 18:
                    DoScriptText(SAY_PROGRESS_1, me, player);
                    SetRun();
                    break;
            }
        }

        void JustSummoned(Creature* summoned)
        {
            if (summoned->GetEntry() == NPC_PILOT_WIZZ)
                me->SetStandState(UNIT_STAND_STATE_DEAD);

            if (summoned->GetEntry() == NPC_MERCENARY)
                summoned->AI()->AttackStart(me);
        }

        void UpdateEscortAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
            {
                if (m_bIsPostEvent)
                {
                    if (m_uiPostEventTimer <= uiDiff)
                    {
                        switch (m_uiPostEventCount)
                        {
                            case 0:
                                DoScriptText(SAY_PROGRESS_2, me);
                                break;
                            case 1:
                                DoScriptText(SAY_PROGRESS_3, me);
                                break;
                            case 2:
                                DoScriptText(SAY_END, me);
                                break;
                            case 3:
                                if (Player* player = GetPlayerForEscort())
                                {
                                    player->GroupEventHappens(QUEST_ESCAPE, me);
                                    me->SummonCreature(NPC_PILOT_WIZZ, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN, 180000);
                                }
                                break;
                        }

                        ++m_uiPostEventCount;
                        m_uiPostEventTimer = 5000;
                    }
                    else
                        m_uiPostEventTimer -= uiDiff;
                }

                return;
            }

            DoMeleeAttackIfReady();
        }
    };

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest)
    {
        if (quest->GetQuestId() == QUEST_ESCAPE)
        {
            creature->setFaction(FACTION_RATCHET);
            if (npc_escortAI* pEscortAI = CAST_AI(npc_wizzlecrank_shredder::npc_wizzlecrank_shredderAI, creature->AI()))
                pEscortAI->Start(true, false, player->GetGUID());
        }
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_wizzlecrank_shredderAI(creature);
    }

};

void AddSC_the_barrens()
{
    new npc_beaten_corpse();
    new npc_gilthares();
    new npc_sputtervalve();
    new npc_taskmaster_fizzule();
    new npc_twiggy_flathead();
    new npc_wizzlecrank_shredder();
}
