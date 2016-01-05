/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"
#include "Player.h"
#include "SpellInfo.h"

/*######
## npc_beaten_corpse
######*/

#define GOSSIP_CORPSE "Examine corpse in detail..."

enum BeatenCorpse
{
    QUEST_LOST_IN_BATTLE    = 4921
};

class npc_beaten_corpse : public CreatureScript
{
public:
    npc_beaten_corpse() : CreatureScript("npc_beaten_corpse") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        player->PlayerTalkClass->ClearMenus();
        if (action == GOSSIP_ACTION_INFO_DEF +1)
        {
            player->SEND_GOSSIP_MENU(3558, creature->GetGUID());
            player->TalkedToCreature(creature->GetEntry(), creature->GetGUID());
        }
        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature) override
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

enum Gilthares
{
    SAY_GIL_START               = 0,
    SAY_GIL_AT_LAST             = 1,
    SAY_GIL_PROCEED             = 2,
    SAY_GIL_FREEBOOTERS         = 3,
    SAY_GIL_AGGRO               = 4,
    SAY_GIL_ALMOST              = 5,
    SAY_GIL_SWEET               = 6,
    SAY_GIL_FREED               = 7,

    QUEST_FREE_FROM_HOLD        = 898,
    AREA_MERCHANT_COAST         = 391,
    FACTION_ESCORTEE            = 232                       //guessed, possible not needed for this quest
};

class npc_gilthares : public CreatureScript
{
public:
    npc_gilthares() : CreatureScript("npc_gilthares") { }

    bool OnQuestAccept(Player* player, Creature* creature, const Quest* quest) override
    {
        if (quest->GetQuestId() == QUEST_FREE_FROM_HOLD)
        {
            creature->setFaction(FACTION_ESCORTEE);
            creature->SetStandState(UNIT_STAND_STATE_STAND);

            creature->AI()->Talk(SAY_GIL_START, player);

            if (npc_giltharesAI* pEscortAI = CAST_AI(npc_gilthares::npc_giltharesAI, creature->AI()))
                pEscortAI->Start(false, false, player->GetGUID(), quest);
        }
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_giltharesAI(creature);
    }

    struct npc_giltharesAI : public npc_escortAI
    {
        npc_giltharesAI(Creature* creature) : npc_escortAI(creature) { }

        void Reset() override { }

        void WaypointReached(uint32 waypointId) override
        {
            Player* player = GetPlayerForEscort();
            if (!player)
                return;

            switch (waypointId)
            {
                case 16:
                    Talk(SAY_GIL_AT_LAST, player);
                    break;
                case 17:
                    Talk(SAY_GIL_PROCEED, player);
                    break;
                case 18:
                    Talk(SAY_GIL_FREEBOOTERS, player);
                    break;
                case 37:
                    Talk(SAY_GIL_ALMOST, player);
                    break;
                case 47:
                    Talk(SAY_GIL_SWEET, player);
                    break;
                case 53:
                    Talk(SAY_GIL_FREED, player);
                    player->GroupEventHappens(QUEST_FREE_FROM_HOLD, me);
                    break;
            }
        }

        void EnterCombat(Unit* who) override
        {
            //not always use
            if (rand32() % 4)
                return;

            //only aggro text if not player and only in this area
            if (who->GetTypeId() != TYPEID_PLAYER && me->GetAreaId() == AREA_MERCHANT_COAST)
            {
                //appears to be pretty much random (possible only if escorter not in combat with who yet?)
                Talk(SAY_GIL_AGGRO, who);
            }
        }
    };

};

/*######
## npc_taskmaster_fizzule
######*/

enum TaskmasterFizzule
{
    FACTION_FRIENDLY_F  = 35,
    SPELL_FLARE         = 10113,
    SPELL_FOLLY         = 10137,
};

class npc_taskmaster_fizzule : public CreatureScript
{
public:
    npc_taskmaster_fizzule() : CreatureScript("npc_taskmaster_fizzule") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_taskmaster_fizzuleAI(creature);
    }

    struct npc_taskmaster_fizzuleAI : public ScriptedAI
    {
        npc_taskmaster_fizzuleAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            factionNorm = creature->getFaction();
        }

        void Initialize()
        {
            IsFriend = false;
            ResetTimer = 120000;
            FlareCount = 0;
        }

        uint32 factionNorm;
        bool IsFriend;
        uint32 ResetTimer;
        uint8 FlareCount;

        void Reset() override
        {
            Initialize();
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

        void SpellHit(Unit* /*caster*/, const SpellInfo* spell) override
        {
            if (spell->Id == SPELL_FLARE || spell->Id == SPELL_FOLLY)
            {
                ++FlareCount;

                if (FlareCount >= 2)
                    IsFriend = true;
            }
        }

        void EnterCombat(Unit* /*who*/) override { }

        void UpdateAI(uint32 diff) override
        {
            if (IsFriend)
            {
                if (ResetTimer <= diff)
                {
                    EnterEvadeMode();
                    return;
                } else ResetTimer -= diff;
            }

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

        void ReceiveEmote(Player* /*player*/, uint32 emote) override
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

enum TwiggyFlathead
{
    NPC_BIG_WILL                = 6238,
    NPC_AFFRAY_CHALLENGER       = 6240,

    SAY_BIG_WILL_READY          = 0,
    SAY_TWIGGY_FLATHEAD_BEGIN   = 0,
    SAY_TWIGGY_FLATHEAD_FRAY    = 1,
    SAY_TWIGGY_FLATHEAD_DOWN    = 2,
    SAY_TWIGGY_FLATHEAD_OVER    = 3
};

Position const AffrayChallengerLoc[6] =
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

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_twiggy_flatheadAI(creature);
    }

    struct npc_twiggy_flatheadAI : public ScriptedAI
    {
        npc_twiggy_flatheadAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            EventInProgress = false;
            EventGrate = false;
            EventBigWill = false;
            WaveTimer = 600000;
            ChallengerChecker = 0;
            Wave = 0;
            PlayerGUID.Clear();

            for (uint8 i = 0; i < 6; ++i)
            {
                AffrayChallenger[i].Clear();
                ChallengerDown[i] = false;
            }
            BigWill.Clear();
        }

        bool EventInProgress;
        bool EventGrate;
        bool EventBigWill;
        bool ChallengerDown[6];
        uint8 Wave;
        uint32 WaveTimer;
        uint32 ChallengerChecker;
        ObjectGuid PlayerGUID;
        ObjectGuid AffrayChallenger[6];
        ObjectGuid BigWill;

        void Reset() override
        {
            Initialize();
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (!who || !who->IsAlive() || EventInProgress)
                return;

            if (who->GetTypeId() == TYPEID_PLAYER && me->IsWithinDistInMap(who, 10.0f))
                if (Player* player = who->ToPlayer())
                    if (player->GetQuestStatus(1719) == QUEST_STATUS_INCOMPLETE)
                    {
                        PlayerGUID = who->GetGUID();
                        EventInProgress = true;
                    }
        }

        void UpdateAI(uint32 diff) override
        {
            if (EventInProgress)
            {
                Player* warrior = NULL;

                if (PlayerGUID)
                    warrior = ObjectAccessor::GetPlayer(*me, PlayerGUID);

                if (!warrior)
                    return;

                if (!warrior->IsAlive() && warrior->GetQuestStatus(1719) == QUEST_STATUS_INCOMPLETE)
                {
                    Talk(SAY_TWIGGY_FLATHEAD_DOWN);
                    warrior->FailQuest(1719);

                    for (uint8 i = 0; i < 6; ++i) // unsummon challengers
                    {
                        if (AffrayChallenger[i])
                        {
                            Creature* creature = ObjectAccessor::GetCreature((*me), AffrayChallenger[i]);
                            if (creature && creature->IsAlive())
                                creature->DisappearAndDie();
                        }
                    }

                    if (BigWill) // unsummon bigWill
                    {
                        Creature* creature = ObjectAccessor::GetCreature((*me), BigWill);
                        if (creature && creature->IsAlive())
                            creature->DisappearAndDie();
                    }
                    Reset();
                }

                if (!EventGrate && EventInProgress)
                {
                    float x, y, z;
                    warrior->GetPosition(x, y, z);

                    if (x >= -1684 && x <= -1674 && y >= -4334 && y <= -4324)
                    {
                        warrior->AreaExploredOrEventHappens(1719);
                        Talk(SAY_TWIGGY_FLATHEAD_BEGIN, warrior);

                        for (uint8 i = 0; i < 6; ++i)
                        {
                            Creature* creature = me->SummonCreature(NPC_AFFRAY_CHALLENGER, AffrayChallengerLoc[i], TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 600000);
                            if (!creature)
                                continue;
                            creature->setFaction(35);
                            creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                            creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            creature->HandleEmoteCommand(EMOTE_ONESHOT_ROAR);
                            AffrayChallenger[i] = creature->GetGUID();
                        }
                        WaveTimer = 5000;
                        ChallengerChecker = 1000;
                        EventGrate = true;
                    }
                }
                else if (EventInProgress)
                {
                    if (ChallengerChecker <= diff)
                    {
                        for (uint8 i = 0; i < 6; ++i)
                        {
                            if (AffrayChallenger[i])
                            {
                                Creature* creature = ObjectAccessor::GetCreature((*me), AffrayChallenger[i]);
                                if ((!creature || (!creature->IsAlive())) && !ChallengerDown[i])
                                {
                                    Talk(SAY_TWIGGY_FLATHEAD_DOWN);
                                    ChallengerDown[i] = true;
                                }
                            }
                        }
                        ChallengerChecker = 1000;
                    } else ChallengerChecker -= diff;

                    if (WaveTimer <= diff)
                    {
                        if (Wave < 6 && AffrayChallenger[Wave] && !EventBigWill)
                        {
                            Talk(SAY_TWIGGY_FLATHEAD_FRAY);
                            Creature* creature = ObjectAccessor::GetCreature(*me, AffrayChallenger[Wave]);
                            if (creature && (creature->IsAlive()))
                            {
                                creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                                creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                                creature->HandleEmoteCommand(EMOTE_ONESHOT_ROAR);
                                creature->setFaction(14);
                                creature->AI()->AttackStart(warrior);
                                ++Wave;
                                WaveTimer = 20000;
                            }
                        }
                        else if (Wave >= 6 && !EventBigWill)
                        {
                            if (Creature* creature = me->SummonCreature(NPC_BIG_WILL, -1722, -4341, 6.12f, 6.26f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 480000))
                            {
                                BigWill = creature->GetGUID();
                                //creature->GetMotionMaster()->MovePoint(0, -1693, -4343, 4.32f);
                                //creature->GetMotionMaster()->MovePoint(1, -1684, -4333, 2.78f);
                                creature->GetMotionMaster()->MovePoint(2, -1682, -4329, 2.79f);
                                creature->HandleEmoteCommand(EMOTE_STATE_READY_UNARMED);
                                EventBigWill = true;
                                WaveTimer = 1000;
                            }
                        }
                        else if (Wave >= 6 && EventBigWill && BigWill)
                        {
                            Creature* creature = ObjectAccessor::GetCreature(*me, BigWill);
                            if (!creature || !creature->IsAlive())
                            {
                                Talk(SAY_TWIGGY_FLATHEAD_OVER);
                                Reset();
                            }
                            else if (creature) // Makes BIG WILL attackable.
                            {
                                creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                                creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                                creature->HandleEmoteCommand(EMOTE_ONESHOT_ROAR);
                                creature->setFaction(14);
                                creature->AI()->AttackStart(warrior);
                            }
                        }
                    } else WaveTimer -= diff;
                }
            }
        }
    };

};

/*#####
## npc_wizzlecrank_shredder
#####*/

enum Wizzlecrank
{
    SAY_MERCENARY       = 0,
    SAY_START           = 0,
    SAY_STARTUP1        = 1,
    SAY_STARTUP2        = 2,
    SAY_PROGRESS_1      = 3,
    SAY_PROGRESS_2      = 4,
    SAY_PROGRESS_3      = 5,
    SAY_END             = 6,

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
            IsPostEvent = false;
            PostEventTimer = 1000;
            PostEventCount = 0;
        }

        bool IsPostEvent;
        uint32 PostEventTimer;
        uint32 PostEventCount;

        void Reset() override
        {
            if (!HasEscortState(STATE_ESCORT_ESCORTING))
            {
                if (me->getStandState() == UNIT_STAND_STATE_DEAD)
                     me->SetStandState(UNIT_STAND_STATE_STAND);

                IsPostEvent = false;
                PostEventTimer = 1000;
                PostEventCount = 0;
            }
        }

        void WaypointReached(uint32 waypointId) override
        {
            switch (waypointId)
            {
                case 0:
                    Talk(SAY_STARTUP1);
                    break;
                case 9:
                    SetRun(false);
                    break;
                case 17:
                    if (Creature* temp = me->SummonCreature(NPC_MERCENARY, 1128.489f, -3037.611f, 92.701f, 1.472f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 120000))
                    {
                        temp->AI()->Talk(SAY_MERCENARY);
                        me->SummonCreature(NPC_MERCENARY, 1160.172f, -2980.168f, 97.313f, 3.690f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 120000);
                    }
                    break;
                case 24:
                    IsPostEvent = true;
                    break;
            }
        }

        void WaypointStart(uint32 PointId) override
        {
            Player* player = GetPlayerForEscort();

            if (!player)
                return;

            switch (PointId)
            {
                case 9:
                    Talk(SAY_STARTUP2, player);
                    break;
                case 18:
                    Talk(SAY_PROGRESS_1, player);
                    SetRun();
                    break;
            }
        }

        void JustSummoned(Creature* summoned) override
        {
            if (summoned->GetEntry() == NPC_PILOT_WIZZ)
                me->SetStandState(UNIT_STAND_STATE_DEAD);

            if (summoned->GetEntry() == NPC_MERCENARY)
                summoned->AI()->AttackStart(me);
        }

        void UpdateEscortAI(uint32 Diff) override
        {
            if (!UpdateVictim())
            {
                if (IsPostEvent)
                {
                    if (PostEventTimer <= Diff)
                    {
                        switch (PostEventCount)
                        {
                            case 0:
                                Talk(SAY_PROGRESS_2);
                                break;
                            case 1:
                                Talk(SAY_PROGRESS_3);
                                break;
                            case 2:
                                Talk(SAY_END);
                                break;
                            case 3:
                                if (Player* player = GetPlayerForEscort())
                                {
                                    player->GroupEventHappens(QUEST_ESCAPE, me);
                                    me->SummonCreature(NPC_PILOT_WIZZ, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN, 180000);
                                }
                                break;
                        }

                        ++PostEventCount;
                        PostEventTimer = 5000;
                    }
                    else
                        PostEventTimer -= Diff;
                }

                return;
            }

            DoMeleeAttackIfReady();
        }
    };

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_ESCAPE)
        {
            creature->setFaction(FACTION_RATCHET);
            creature->AI()->Talk(SAY_START);
            if (npc_escortAI* pEscortAI = CAST_AI(npc_wizzlecrank_shredder::npc_wizzlecrank_shredderAI, creature->AI()))
                pEscortAI->Start(true, false, player->GetGUID());
        }
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_wizzlecrank_shredderAI(creature);
    }

};

void AddSC_the_barrens()
{
    new npc_beaten_corpse();
    new npc_gilthares();
    new npc_taskmaster_fizzule();
    new npc_twiggy_flathead();
    new npc_wizzlecrank_shredder();
}
