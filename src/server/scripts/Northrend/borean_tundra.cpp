/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
SDName: Borean_Tundra
SD%Complete: 100
SDComment: Quest support: 11708. Taxi vendors.
SDCategory: Borean Tundra
EndScriptData */

/* ContentData
npc_iruk
npc_corastrasza
npc_jenny
npc_sinkhole_kill_credit
npc_khunok_the_behemoth
npc_scourge_prisoner
mob_nerubar_victim
npc_keristrasza
npc_nesingwary_trapper
npc_lurgglbr
npc_nexus_drake_hatchling
EndContentData */

#include "ScriptPCH.h"
#include "ScriptedEscortAI.h"
#include "ScriptedFollowerAI.h"

/*######
## npc_sinkhole_kill_credit
######*/

enum eSinkhole
{
    SPELL_SET_CART                = 46797,
    SPELL_EXPLODE_CART            = 46799,
    SPELL_SUMMON_CART             = 46798,
    SPELL_SUMMON_WORM             = 46800,
};

class npc_sinkhole_kill_credit : public CreatureScript
{
public:
    npc_sinkhole_kill_credit() : CreatureScript("npc_sinkhole_kill_credit") { }

    struct npc_sinkhole_kill_creditAI : public ScriptedAI
    {
        npc_sinkhole_kill_creditAI(Creature* c) : ScriptedAI(c){}

        uint32 uiPhaseTimer;
        uint8  Phase;
        uint64 casterGuid;

        void Reset()
        {
            uiPhaseTimer = 500;
            Phase = 0;
            casterGuid = 0;
        }

        void SpellHit(Unit *caster, const SpellEntry *spell)
        {
            if (Phase)
                return;

            if (spell->Id == SPELL_SET_CART && caster->GetTypeId() == TYPEID_PLAYER
                && CAST_PLR(caster)->GetQuestStatus(11897) == QUEST_STATUS_INCOMPLETE)
            {
                Phase = 1;
                casterGuid = caster->GetGUID();
            }
        }

        void EnterCombat(Unit* /*who*/){}

        void UpdateAI(const uint32 diff)
        {
            if (!Phase)
                return;

            if (uiPhaseTimer <= diff)
            {
                switch (Phase)
                {
                    case 1:
                        DoCast(me, SPELL_EXPLODE_CART, true);
                        DoCast(me, SPELL_SUMMON_CART, true);
                        if (GameObject* cart = me->FindNearestGameObject(188160, 3))
                            cart->SetUInt32Value(GAMEOBJECT_FACTION, 14);
                        uiPhaseTimer = 3000;
                        Phase = 2;
                        break;
                    case 2:
                        if (GameObject* cart = me->FindNearestGameObject(188160, 3))
                            cart->UseDoorOrButton();
                        DoCast(me, SPELL_EXPLODE_CART, true);
                        uiPhaseTimer = 3000;
                        Phase = 3;
                        break;
                    case 3:
                        DoCast(me, SPELL_EXPLODE_CART, true);
                        uiPhaseTimer = 2000;
                        Phase = 4;
                    case 5:
                        DoCast(me, SPELL_SUMMON_WORM, true);
                        if (Unit* worm = me->FindNearestCreature(26250, 3))
                        {
                            worm->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                            worm->HandleEmoteCommand(EMOTE_ONESHOT_EMERGE);
                        }
                        uiPhaseTimer = 1000;
                        Phase = 6;
                        break;
                    case 6:
                        DoCast(me, SPELL_EXPLODE_CART, true);
                        if (Unit* worm = me->FindNearestCreature(26250, 3))
                        {
                            me->Kill(worm);
                            worm->RemoveFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
                        }
                        uiPhaseTimer = 2000;
                        Phase = 7;
                        break;
                    case 7:
                        DoCast(me, SPELL_EXPLODE_CART, true);
                        if (Player *caster = Unit::GetPlayer(*me, casterGuid))
                            caster->KilledMonster(me->GetCreatureInfo(), me->GetGUID());
                        uiPhaseTimer = 5000;
                        Phase = 8;
                        break;
                    case 8:
                        EnterEvadeMode();
                        break;
                }
            } else uiPhaseTimer -= diff;

        }

    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_sinkhole_kill_creditAI(creature);
    }
};

/*######
## npc_khunok_the_behemoth
######*/

class npc_khunok_the_behemoth : public CreatureScript
{
public:
    npc_khunok_the_behemoth() : CreatureScript("npc_khunok_the_behemoth") { }

    struct npc_khunok_the_behemothAI : public ScriptedAI
    {
        npc_khunok_the_behemothAI(Creature *c) : ScriptedAI(c) {}

        void MoveInLineOfSight(Unit *who)
        {
            ScriptedAI::MoveInLineOfSight(who);

            if (who->GetTypeId() != TYPEID_UNIT)
                return;

            if (who->GetEntry() == 25861 && me->IsWithinDistInMap(who, 10.0f))
            {
                if (Unit *owner = who->GetOwner())
                {
                    if (owner->GetTypeId() == TYPEID_PLAYER)
                    {
                        owner->CastSpell(owner, 46231, true);
                        CAST_CRE(who)->ForcedDespawn();
                    }
                }
            }
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_khunok_the_behemothAI(creature);
    }
};

/*######
## npc_keristrasza
######*/

enum eKeristrasza
{
    SPELL_TELEPORT_TO_SARAGOSA = 46772
};

#define GOSSIP_HELLO_KERI   "I am prepared to face Saragosa!"

class npc_keristrasza : public CreatureScript
{
public:
    npc_keristrasza() : CreatureScript("npc_keristrasza") { }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pCreature->isQuestGiver())
            pPlayer->PrepareQuestMenu(pCreature->GetGUID());

        if (pPlayer->GetQuestStatus(11957) == QUEST_STATUS_INCOMPLETE)
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_KERI, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player* pPlayer, Creature* /*pCreature*/, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        if (uiAction == GOSSIP_ACTION_INFO_DEF + 1)
        {
            pPlayer->CLOSE_GOSSIP_MENU();
            pPlayer->CastSpell(pPlayer, SPELL_TELEPORT_TO_SARAGOSA, true);
        }

        return true;
    }
};

/*######
## npc_corastrasza
######*/

#define GOSSIP_ITEM_C_1 "I... I think so..."

enum eCorastrasza
{
    SPELL_SUMMON_WYRMREST_SKYTALON               = 61240,
    SPELL_WYRMREST_SKYTALON_RIDE_PERIODIC        = 61244,

    QUEST_ACES_HIGH_DAILY                        = 13414,
    QUEST_ACES_HIGH                              = 13413
};

class npc_corastrasza : public CreatureScript
{
public:
    npc_corastrasza() : CreatureScript("npc_corastrasza") { }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pCreature->isQuestGiver())
            pPlayer->PrepareQuestMenu(pCreature->GetGUID());

        if (pPlayer->GetQuestStatus(QUEST_ACES_HIGH) == QUEST_STATUS_INCOMPLETE || pPlayer->GetQuestStatus(QUEST_ACES_HIGH_DAILY) == QUEST_STATUS_INCOMPLETE) //It's the same dragon for both quests.
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_C_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* pPlayer, Creature* /*pCreature*/, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
        {
            pPlayer->CLOSE_GOSSIP_MENU();

            pPlayer->CastSpell(pPlayer, SPELL_SUMMON_WYRMREST_SKYTALON, true);
            pPlayer->CastSpell(pPlayer, SPELL_WYRMREST_SKYTALON_RIDE_PERIODIC, true);

        }

        return true;
    }
};

/*######
## npc_iruk
######*/

#define GOSSIP_ITEM_I  "<Search corpse for Issliruk's Totem.>"

enum eIruk
{
    QUEST_SPIRITS_WATCH_OVER_US             = 11961,
    SPELL_CREATURE_TOTEM_OF_ISSLIRUK        = 46816,
    GOSSIP_TEXT_I                           = 12585
};

class npc_iruk : public CreatureScript
{
public:
    npc_iruk() : CreatureScript("npc_iruk") { }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {

        if (pPlayer->GetQuestStatus(QUEST_SPIRITS_WATCH_OVER_US) == QUEST_STATUS_INCOMPLETE)
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_I, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        pPlayer->PlayerTalkClass->SendGossipMenu(GOSSIP_TEXT_I, pCreature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* pPlayer, Creature* /*pCreature*/, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        switch (uiAction)
        {
            case GOSSIP_ACTION_INFO_DEF+1:
                pPlayer->CastSpell(pPlayer, SPELL_CREATURE_TOTEM_OF_ISSLIRUK, true);
                pPlayer->CLOSE_GOSSIP_MENU();
                break;

        }
        return true;
    }
};

/*######
## mob_nerubar_victim
######*/

#define WARSONG_PEON        25270

const uint32 nerubarVictims[3] =
{
    45526, 45527, 45514
};

class mob_nerubar_victim : public CreatureScript
{
public:
    mob_nerubar_victim() : CreatureScript("mob_nerubar_victim") { }

    struct mob_nerubar_victimAI : public ScriptedAI
    {
        mob_nerubar_victimAI(Creature *c) : ScriptedAI(c) {}

        void Reset() {}
        void EnterCombat(Unit * /*who*/) {}
        void MoveInLineOfSight(Unit * /*who*/) {}

        void JustDied(Unit* Killer)
        {
            if (Killer->GetTypeId() == TYPEID_PLAYER)
            {
                if (CAST_PLR(Killer)->GetQuestStatus(11611) == QUEST_STATUS_INCOMPLETE)
                {
                    uint8 uiRand = urand(0, 99);
                    if (uiRand < 25)
                    {
                        Killer->CastSpell(me, 45532, true);
                        CAST_PLR(Killer)->KilledMonsterCredit(WARSONG_PEON, 0);
                    }
                    else if (uiRand < 75)
                        Killer->CastSpell(me, nerubarVictims[urand(0, 2)], true);
                }
            }
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new mob_nerubar_victimAI(creature);
    }
};

/*######
## npc_scourge_prisoner
######*/

enum eScourgePrisoner
{
    GO_SCOURGE_CAGE = 187867
};

class npc_scourge_prisoner : public CreatureScript
{
public:
    npc_scourge_prisoner() : CreatureScript("npc_scourge_prisoner") { }

    struct npc_scourge_prisonerAI : public ScriptedAI
    {
        npc_scourge_prisonerAI(Creature* pCreature) : ScriptedAI (pCreature){}

        void Reset()
        {
            me->SetReactState(REACT_PASSIVE);

            if (GameObject* pGO = me->FindNearestGameObject(GO_SCOURGE_CAGE, 5.0f))
                if (pGO->GetGoState() == GO_STATE_ACTIVE)
                    pGO->SetGoState(GO_STATE_READY);
        }

    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_scourge_prisonerAI(creature);
    }
};

/*######
## npc_jenny
######*/

enum eJenny
{
    QUEST_LOADER_UP             = 11881,

    NPC_FEZZIX_GEARTWIST        = 25849,
    NPC_JENNY                   = 25969,

    SPELL_GIVE_JENNY_CREDIT     = 46358,
    SPELL_CRATES_CARRIED        = 46340,
    SPELL_DROP_CRATE            = 46342
};

class npc_jenny : public CreatureScript
{
public:
    npc_jenny() : CreatureScript("npc_jenny") { }

    struct npc_jennyAI : public ScriptedAI
    {
        npc_jennyAI(Creature* pCreature) : ScriptedAI(pCreature) {}

        bool setCrateNumber;

        void Reset()
        {
            if (!setCrateNumber)
                setCrateNumber = true;

            me->SetReactState(REACT_PASSIVE);

            switch (CAST_PLR(me->GetOwner())->GetTeamId())
            {
                case TEAM_ALLIANCE:
                    me->setFaction(FACTION_ESCORT_A_NEUTRAL_ACTIVE);
                    break;
                default:
                case TEAM_HORDE:
                    me->setFaction(FACTION_ESCORT_H_NEUTRAL_ACTIVE);
                    break;
            }
        }

        void DamageTaken(Unit* /*pDone_by*/, uint32& /*uiDamage*/)
        {
            DoCast(me, SPELL_DROP_CRATE, true);
        }

        void UpdateAI(const uint32 /*diff*/)
        {
            if (setCrateNumber)
            {
                me->AddAura(SPELL_CRATES_CARRIED, me);
                setCrateNumber = false;
            }

            if (!setCrateNumber && !me->HasAura(SPELL_CRATES_CARRIED))
                me->DisappearAndDie();

            if (!UpdateVictim())
                return;
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_jennyAI (creature);
    }
};

/*######
## npc_fezzix_geartwist
######*/

class npc_fezzix_geartwist : public CreatureScript
{
public:
    npc_fezzix_geartwist() : CreatureScript("npc_fezzix_geartwist") { }

    struct npc_fezzix_geartwistAI : public ScriptedAI
    {
        npc_fezzix_geartwistAI(Creature* pCreature) : ScriptedAI(pCreature) {}

        void MoveInLineOfSight(Unit* pWho)
        {
            ScriptedAI::MoveInLineOfSight(pWho);

            if (pWho->GetTypeId() != TYPEID_UNIT)
                return;

            if (pWho->GetEntry() == NPC_JENNY && me->IsWithinDistInMap(pWho, 10.0f))
            {
                if (Unit* pOwner = pWho->GetOwner())
                {
                    if (pOwner->GetTypeId() == TYPEID_PLAYER)
                    {
                        if (pWho->HasAura(SPELL_CRATES_CARRIED))
                        {
                            pOwner->CastSpell(pOwner, SPELL_GIVE_JENNY_CREDIT, true); // Maybe is not working.
                            CAST_PLR(pOwner)->CompleteQuest(QUEST_LOADER_UP);
                            CAST_CRE(pWho)->DisappearAndDie();
                        }
                    }
                }
            }
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_fezzix_geartwistAI(creature);
    }
};

/*######
## npc_nesingwary_trapper
######*/

enum eNesingwaryTrapper
{
    GO_HIGH_QUALITY_FUR = 187983,

    GO_CARIBOU_TRAP_1   = 187982,
    GO_CARIBOU_TRAP_2   = 187995,
    GO_CARIBOU_TRAP_3   = 187996,
    GO_CARIBOU_TRAP_4   = 187997,
    GO_CARIBOU_TRAP_5   = 187998,
    GO_CARIBOU_TRAP_6   = 187999,
    GO_CARIBOU_TRAP_7   = 188000,
    GO_CARIBOU_TRAP_8   = 188001,
    GO_CARIBOU_TRAP_9   = 188002,
    GO_CARIBOU_TRAP_10  = 188003,
    GO_CARIBOU_TRAP_11  = 188004,
    GO_CARIBOU_TRAP_12  = 188005,
    GO_CARIBOU_TRAP_13  = 188006,
    GO_CARIBOU_TRAP_14  = 188007,
    GO_CARIBOU_TRAP_15  = 188008,

    SPELL_TRAPPED       = 46104,
};

#define CaribouTrapsNum 15
const uint32 CaribouTraps[CaribouTrapsNum] =
{
    GO_CARIBOU_TRAP_1, GO_CARIBOU_TRAP_2, GO_CARIBOU_TRAP_3, GO_CARIBOU_TRAP_4, GO_CARIBOU_TRAP_5,
    GO_CARIBOU_TRAP_6, GO_CARIBOU_TRAP_7, GO_CARIBOU_TRAP_8, GO_CARIBOU_TRAP_9, GO_CARIBOU_TRAP_10,
    GO_CARIBOU_TRAP_11, GO_CARIBOU_TRAP_12, GO_CARIBOU_TRAP_13, GO_CARIBOU_TRAP_14, GO_CARIBOU_TRAP_15,
};

class npc_nesingwary_trapper : public CreatureScript
{
public:
    npc_nesingwary_trapper() : CreatureScript("npc_nesingwary_trapper") { }

    struct npc_nesingwary_trapperAI : public ScriptedAI
    {
        npc_nesingwary_trapperAI(Creature *c) : ScriptedAI(c) { c->SetVisible(false); }

        uint64 go_caribouGUID;
        uint8  Phase;
        uint32 uiPhaseTimer;

        void Reset()
        {
            me->SetVisible(false);
            uiPhaseTimer = 2500;
            Phase = 1;
            go_caribouGUID = 0;
        }
        void EnterCombat(Unit * /*who*/) {}
        void MoveInLineOfSight(Unit * /*who*/) {}

        void JustDied(Unit * /*who*/)
        {
            if (GameObject *go_caribou = me->GetMap()->GetGameObject(go_caribouGUID))
                go_caribou->SetLootState(GO_JUST_DEACTIVATED);

            if (TempSummon *summon = me->ToTempSummon())
                if (summon->isSummon())
                    if (Unit *pTemp = summon->GetSummoner())
                        if (pTemp->GetTypeId() == TYPEID_PLAYER)
                            CAST_PLR(pTemp)->KilledMonsterCredit(me->GetEntry(), 0);

            if (GameObject *go_caribou = me->GetMap()->GetGameObject(go_caribouGUID))
                go_caribou->SetGoState(GO_STATE_READY);
        }

        void UpdateAI(const uint32 diff)
        {
            if (uiPhaseTimer <= diff)
            {
                switch (Phase)
                {
                    case 1:
                        me->SetVisible(true);
                        uiPhaseTimer = 2000;
                        Phase = 2;
                        break;

                    case 2:
                        if (GameObject *go_fur = me->FindNearestGameObject(GO_HIGH_QUALITY_FUR, 11.0f))
                            me->GetMotionMaster()->MovePoint(0, go_fur->GetPositionX(), go_fur->GetPositionY(), go_fur->GetPositionZ());
                        uiPhaseTimer = 1500;
                        Phase = 3;
                        break;
                    case 3:
                        //DoScriptText(SAY_NESINGWARY_1, me);
                        uiPhaseTimer = 2000;
                        Phase = 4;
                        break;
                    case 4:
                        me->HandleEmoteCommand(EMOTE_ONESHOT_LOOT);
                        uiPhaseTimer = 1000;
                        Phase = 5;
                        break;
                    case 5:
                        me->HandleEmoteCommand(EMOTE_ONESHOT_NONE);
                        uiPhaseTimer = 500;
                        Phase = 6;
                        break;
                    case 6:
                        if (GameObject *go_fur = me->FindNearestGameObject(GO_HIGH_QUALITY_FUR, 11.0f))
                            go_fur->Delete();
                        uiPhaseTimer = 500;
                        Phase = 7;
                        break;

                    case 7:
                    {
                        GameObject *go_caribou = NULL;
                        for (uint8 i = 0; i < CaribouTrapsNum; ++i)
                        {
                            go_caribou = me->FindNearestGameObject(CaribouTraps[i], 5.0f);
                            if (go_caribou)
                            {
                                go_caribou->SetGoState(GO_STATE_ACTIVE);
                                go_caribouGUID = go_caribou->GetGUID();
                                break;
                            }
                        }
                        Phase = 8;
                        uiPhaseTimer = 1000;
                    }
                        break;
                    case 8:
                        DoCast(me, SPELL_TRAPPED, true);
                        Phase = 0;
                        break;
                }
            } else uiPhaseTimer -= diff;
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_nesingwary_trapperAI(creature);
    }
};

/*######
## npc_lurgglbr
######*/

enum eLurgglbr
{
    QUEST_ESCAPE_WINTERFIN_CAVERNS      = 11570,

    GO_CAGE                             = 187369,

    FACTION_ESCORTEE_A                  = 774,
    FACTION_ESCORTEE_H                  = 775,
};

/*#define SAY_WP_1_LUR_START  -1571004
#define SAY_WP_1_LUR_END    -1571005
#define SAY_WP_41_LUR_START -1571006
#define SAY_WP_41_LUR_END   -1571007*/

class npc_lurgglbr : public CreatureScript
{
public:
    npc_lurgglbr() : CreatureScript("npc_lurgglbr") { }

    struct npc_lurgglbrAI : public npc_escortAI
    {
        npc_lurgglbrAI(Creature* pCreature) : npc_escortAI(pCreature){}

        uint32 IntroTimer;
        uint32 IntroPhase;

        void Reset()
        {
            if (!HasEscortState(STATE_ESCORT_ESCORTING))
            {
                IntroTimer = 0;
                IntroPhase = 0;
            }
        }

        void WaypointReached(uint32 i)
        {
            switch (i)
            {
                case 0:
                    IntroPhase = 1;
                    IntroTimer = 2000;
                    break;
                case 41:
                    IntroPhase = 4;
                    IntroTimer = 2000;
                    break;
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (IntroPhase)
            {
                if (IntroTimer <= diff)
                {
                    switch(IntroPhase)
                    {
                        case 1:
                            //DoScriptText(SAY_WP_1_LUR_START, me);
                            IntroPhase = 2;
                            IntroTimer = 7500;
                            break;
                        case 2:
                            //DoScriptText(SAY_WP_1_LUR_END, me);
                            IntroPhase = 3;
                            IntroTimer = 7500;
                            break;
                        case 3:
                            me->SetReactState(REACT_AGGRESSIVE);
                            IntroPhase = 0;
                            IntroTimer = 0;
                            break;
                        case 4:
                            //DoScriptText(SAY_WP_41_LUR_START, me);
                            IntroPhase = 5;
                            IntroTimer = 8000;
                            break;
                        case 5:
                            //DoScriptText(SAY_WP_41_LUR_END, me);
                            IntroPhase = 6;
                            IntroTimer = 2500;
                            break;

                        case 6:
                            if (Player* pPlayer = GetPlayerForEscort())
                                pPlayer->AreaExploredOrEventHappens(QUEST_ESCAPE_WINTERFIN_CAVERNS);
                            IntroPhase = 7;
                            IntroTimer = 2500;
                            break;

                        case 7:
                            me->DespawnOrUnsummon();
                            IntroPhase = 0;
                            IntroTimer = 0;
                            break;
                    }
                } else IntroTimer -= diff;
            }
            npc_escortAI::UpdateAI(diff);

            if (!UpdateVictim())
                return;
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_lurgglbrAI(creature);
    }

    bool OnQuestAccept(Player* pPlayer, Creature* pCreature, Quest const *pQuest)
    {
        if (pQuest->GetQuestId() == QUEST_ESCAPE_WINTERFIN_CAVERNS)
        {
            if (GameObject* pGo = pCreature->FindNearestGameObject(GO_CAGE, 5.0f))
            {
                pGo->SetRespawnTime(0);
                pGo->SetGoType(GAMEOBJECT_TYPE_BUTTON);
                pGo->UseDoorOrButton(20);
            }

            if (npc_escortAI* pEscortAI = CAST_AI(npc_lurgglbr::npc_lurgglbrAI, pCreature->AI()))
                pEscortAI->Start(true, false, pPlayer->GetGUID());

            switch (pPlayer->GetTeam())
            {
                case ALLIANCE:
                    pCreature->setFaction(FACTION_ESCORTEE_A);
                    break;
                default:
                case HORDE:
                    pCreature->setFaction(FACTION_ESCORTEE_H);
                    break;
            }

            return true;
        }
        return false;
    }
};

/*######
## npc_nexus_drake_hatchling
######*/

enum eNexusDrakeHatchling
{
    SPELL_DRAKE_HARPOON             = 46607,
    SPELL_RED_DRAGONBLOOD           = 46620,
    SPELL_DRAKE_HATCHLING_SUBDUED   = 46691,
    SPELL_SUBDUED                   = 46675,

    NPC_RAELORASZ                   = 26117,

    QUEST_DRAKE_HUNT                = 11919,
    QUEST_DRAKE_HUNT_D              = 11940
};

class npc_nexus_drake_hatchling : public CreatureScript
{
public:
    npc_nexus_drake_hatchling() : CreatureScript("npc_nexus_drake_hatchling") { }

    struct npc_nexus_drake_hatchlingAI : public FollowerAI //The spell who makes the npc follow the player is missing, also we can use FollowerAI!
    {
        npc_nexus_drake_hatchlingAI(Creature *c) : FollowerAI(c) {}

        uint64 HarpoonerGUID;
        bool WithRedDragonBlood;

        void Reset()
        {
           WithRedDragonBlood = false;
           HarpoonerGUID = 0;
        }

        void EnterCombat(Unit* pWho)
        {
            if (me->canAttack(pWho))
                AttackStart(pWho);
        }

        void SpellHit(Unit *caster, const SpellEntry *spell)
        {
            if (spell->Id == SPELL_DRAKE_HARPOON && caster->GetTypeId() == TYPEID_PLAYER)
            {
                HarpoonerGUID = caster->GetGUID();
                DoCast(me, SPELL_RED_DRAGONBLOOD, true);
            }
            WithRedDragonBlood = true;
        }

        void MoveInLineOfSight(Unit *pWho)
        {
            FollowerAI::MoveInLineOfSight(pWho);

            if (!HarpoonerGUID)
                return;

            if (me->HasAura(SPELL_SUBDUED) && pWho->GetEntry() == NPC_RAELORASZ)
            {
                if (me->IsWithinDistInMap(pWho, INTERACTION_DISTANCE))
                {
                    if (Player *pHarpooner = Unit::GetPlayer(*me, HarpoonerGUID))
                    {
                        pHarpooner->KilledMonsterCredit(26175, 0);
                        pHarpooner->RemoveAura(SPELL_DRAKE_HATCHLING_SUBDUED);
                        SetFollowComplete();
                        HarpoonerGUID = 0;
                        me->DisappearAndDie();
                    }
                }
            }
        }

        void UpdateAI(const uint32 /*diff*/)
        {
            if (WithRedDragonBlood && HarpoonerGUID && !me->HasAura(SPELL_RED_DRAGONBLOOD))
            {
                if (Player *pHarpooner = Unit::GetPlayer(*me, HarpoonerGUID))
                {
                    EnterEvadeMode();
                    StartFollow(pHarpooner, 35, NULL);

                    DoCast(me, SPELL_SUBDUED, true);
                    pHarpooner->CastSpell(pHarpooner, SPELL_DRAKE_HATCHLING_SUBDUED, true);

                    me->AttackStop();
                    WithRedDragonBlood = false;
                }
            }

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_nexus_drake_hatchlingAI(creature);
    }
};

/*######
## npc_thassarian
######*/

enum eThassarian
{
    QUEST_LAST_RITES        = 12019,

    SPELL_TRANSFORM_VALANAR = 46753,
    SPELL_STUN              = 46957,
    SPELL_SHADOW_BOLT       = 15537,

    NPC_IMAGE_LICH_KING     = 26203,
    NPC_COUNSELOR_TALBOT    = 25301,
    NPC_PRINCE_VALANAR      = 28189,
    NPC_GENERAL_ARLOS       = 25250,
    NPC_LERYSSA             = 25251,

    SAY_TALBOT_1            = -1571004,
    SAY_LICH_1              = -1571005,
    SAY_TALBOT_2            = -1571006,
    SAY_THASSARIAN_1        = -1571007,
    SAY_THASSARIAN_2        = -1571008,
    SAY_LICH_2              = -1571009,
    SAY_THASSARIAN_3        = -1571010,
    SAY_TALBOT_3            = -1571011,
    SAY_LICH_3              = -1571012,
    SAY_TALBOT_4            = -1571013,
    SAY_ARLOS_1             = -1571014,
    SAY_ARLOS_2             = -1571015,
    SAY_LERYSSA_1           = -1571016,
    SAY_THASSARIAN_4        = -1571017,
    SAY_LERYSSA_2           = -1571018,
    SAY_THASSARIAN_5        = -1571019,
    SAY_LERYSSA_3           = -1571020,
    SAY_THASSARIAN_6        = -1571021,
    SAY_LERYSSA_4           = -1571022,
    SAY_THASSARIAN_7        = -1571023,
};

#define GOSSIP_ITEM_T   "Let's do this, Thassarian. It's now or never."

class npc_thassarian : public CreatureScript
{
public:
    npc_thassarian() : CreatureScript("npc_thassarian") { }

    struct npc_thassarianAI : public npc_escortAI
    {
        npc_thassarianAI(Creature* pCreature) : npc_escortAI(pCreature)
        {
        }

        uint64 uiArthas;
        uint64 uiTalbot;
        uint64 uiLeryssa;
        uint64 uiArlos;

        bool bArthasInPosition;
        bool bArlosInPosition;
        bool bLeryssaInPosition;
        bool bTalbotInPosition;

        uint32 uiPhase;
        uint32 uiPhaseTimer;

        void Reset()
        {
            me->RestoreFaction();
            me->RemoveStandFlags(UNIT_STAND_STATE_SIT);

            uiArthas = 0;
            uiTalbot = 0;
            uiLeryssa = 0;
            uiArlos = 0;

            bArthasInPosition           = false;
            bArlosInPosition            = false;
            bLeryssaInPosition          = false;
            bTalbotInPosition           = false;

            uiPhase = 0;
            uiPhaseTimer = 0;
        }

        void WaypointReached(uint32 uiPointId)
        {
            Player* pPlayer = GetPlayerForEscort();

            if (!pPlayer)
                return;

            switch(uiPointId)
            {
                case 3:
                    SetEscortPaused(true);
                    if (Creature *pArthas = me->SummonCreature(NPC_IMAGE_LICH_KING, 3730.313f, 3518.689f, 473.324f, 1.562f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 120000))
                    {
                        uiArthas = pArthas->GetGUID();
                        pArthas->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        pArthas->SetReactState(REACT_PASSIVE);
                        pArthas->AddUnitMovementFlag(MOVEMENTFLAG_WALKING);
                        pArthas->GetMotionMaster()->MovePoint(0, 3737.374756f, 3564.841309f, 477.433014f);
                    }
                    if (Creature *pTalbot = me->SummonCreature(NPC_COUNSELOR_TALBOT, 3747.23f, 3614.936f, 473.321f, 4.462012f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 120000))
                    {
                        uiTalbot = pTalbot->GetGUID();
                        pTalbot->AddUnitMovementFlag(MOVEMENTFLAG_WALKING);
                        pTalbot->GetMotionMaster()->MovePoint(0, 3738.000977f, 3568.882080f, 477.433014f);
                    }
                    me->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
                    break;

                case 4:
                    SetEscortPaused(true);
                    uiPhase = 7;
                    break;
            }
        }

        void UpdateAI(const uint32 uiDiff)
        {
            npc_escortAI::UpdateAI(uiDiff);

            if (bArthasInPosition && bTalbotInPosition)
            {
                uiPhase = 1;
                bArthasInPosition = false;
                bTalbotInPosition = false;
            }

            if (bArlosInPosition && bLeryssaInPosition)
            {
                bArlosInPosition   = false;
                bLeryssaInPosition = false;
                DoScriptText(SAY_THASSARIAN_1, me);
                SetEscortPaused(false);
            }

            if (uiPhaseTimer <= uiDiff)
            {
                Creature* pTalbot = me->GetCreature(*me, uiTalbot);
                Creature* pArthas = me->GetCreature(*me, uiArthas);
                switch (uiPhase)
                {
                    case 1:
                        if (pTalbot)
                            pTalbot->SetStandState(UNIT_STAND_STATE_KNEEL);
                        uiPhaseTimer = 3000;
                        ++uiPhase;
                        break;

                    case 2:
                        if (pTalbot)
                        {
                            pTalbot->UpdateEntry(NPC_PRINCE_VALANAR, ALLIANCE);
                            pTalbot->setFaction(14);
                            pTalbot->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            pTalbot->SetReactState(REACT_PASSIVE);
                        }
                        uiPhaseTimer = 5000;
                        ++uiPhase;
                        break;

                    case 3:
                        if (pTalbot)
                            DoScriptText(SAY_TALBOT_1, pTalbot);
                        uiPhaseTimer = 5000;
                        ++uiPhase;
                        break;

                    case 4:
                        if (pArthas)
                            DoScriptText(SAY_LICH_1, pArthas);
                        uiPhaseTimer = 5000;
                        ++uiPhase;
                        break;

                    case 5:
                        if (pTalbot)
                            DoScriptText(SAY_TALBOT_2, pTalbot);
                        uiPhaseTimer = 5000;
                        ++uiPhase;
                        break;

                    case 6:
                        if (Creature* pArlos = me->SummonCreature(NPC_GENERAL_ARLOS, 3745.527100f, 3615.655029f, 473.321533f, 4.447805f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 120000))
                        {
                            uiArlos = pArlos->GetGUID();
                            pArlos->AddUnitMovementFlag(MOVEMENTFLAG_WALKING);
                            pArlos->GetMotionMaster()->MovePoint(0, 3735.570068f, 3572.419922f, 477.441010f);
                        }
                        if (Creature *pLeryssa = me->SummonCreature(NPC_LERYSSA, 3749.654541f, 3614.959717f, 473.323486f, 4.524959f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 120000))
                        {
                            uiLeryssa = pLeryssa->GetGUID();
                            pLeryssa->AddUnitMovementFlag(MOVEMENTFLAG_WALKING);
                            pLeryssa->SetReactState(REACT_PASSIVE);
                            pLeryssa->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            pLeryssa->GetMotionMaster()->MovePoint(0, 3741.969971f, 3571.439941f, 477.441010f);
                        }
                        uiPhaseTimer = 2000;
                        uiPhase = 0;
                        break;

                    case 7:
                        DoScriptText(SAY_THASSARIAN_2, me);
                        uiPhaseTimer = 5000;
                        ++uiPhase;
                        break;

                    case 8:
                        if (pArthas && pTalbot)
                        {
                            pArthas->SetInFront(me); //The client doesen't update with the new orientation :l
                            pTalbot->SetStandState(UNIT_STAND_STATE_STAND);
                            DoScriptText(SAY_LICH_2, pArthas);
                        }
                        uiPhaseTimer = 5000;
                        uiPhase = 9;
                        break;

                   case 9:
                        DoScriptText(SAY_THASSARIAN_3, me);
                        uiPhaseTimer = 5000;
                        uiPhase = 10;
                        break;

                   case 10:
                        if (pTalbot)
                            DoScriptText(SAY_TALBOT_3, pTalbot);
                        uiPhaseTimer = 5000;
                        uiPhase = 11;
                        break;

                   case 11:
                        if (pArthas)
                            DoScriptText(SAY_LICH_3, pArthas);
                        uiPhaseTimer = 5000;
                        uiPhase = 12;
                        break;

                    case 12:
                        if (pTalbot)
                            DoScriptText(SAY_TALBOT_4, pTalbot);
                        uiPhaseTimer = 2000;
                        uiPhase = 13;
                        break;

                    case 13:
                        if (pArthas)
                            pArthas->RemoveFromWorld();
                        ++uiPhase;
                        break;

                    case 14:
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        if (pTalbot)
                        {
                            pTalbot->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            pTalbot->SetReactState(REACT_AGGRESSIVE);
                            pTalbot->CastSpell(me, SPELL_SHADOW_BOLT, false);
                        }
                        uiPhaseTimer = 1500;
                        ++uiPhase;
                        break;

                    case 15:
                        me->SetReactState(REACT_AGGRESSIVE);
                        AttackStart(pTalbot);
                        uiPhase = 0;
                        break;

                    case 16:
                        me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                        uiPhaseTimer = 20000;
                        ++uiPhase;
                        break;

                   case 17:
                        if (Creature* pLeryssa = me->GetCreature(*me, uiLeryssa))
                            pLeryssa->RemoveFromWorld();
                        if (Creature* pArlos= me->GetCreature(*me, uiArlos))
                            pArlos->RemoveFromWorld();
                        if (pTalbot)
                            pTalbot->RemoveFromWorld();
                        me->RemoveStandFlags(UNIT_STAND_STATE_SIT);
                        SetEscortPaused(false);
                        uiPhaseTimer = 0;
                        uiPhase = 0;
                }
            } else uiPhaseTimer -= uiDiff;

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*pKiller*/)
        {
            if (Creature* pTalbot = me->GetCreature(*me, uiTalbot))
                pTalbot->RemoveFromWorld();

            if (Creature* pLeryssa = me->GetCreature(*me, uiLeryssa))
                pLeryssa->RemoveFromWorld();

            if (Creature* pArlos = me->GetCreature(*me, uiArlos))
                pArlos->RemoveFromWorld();

            if (Creature* pArthas = me->GetCreature(*me, uiArthas))
                pArthas->RemoveFromWorld();
        }
    };

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pCreature->isQuestGiver())
            pPlayer->PrepareQuestMenu(pCreature->GetGUID());

        if (pPlayer->GetQuestStatus(QUEST_LAST_RITES) == QUEST_STATUS_INCOMPLETE && pCreature->GetAreaId() == 4128)
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_T, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        switch (uiAction)
        {
            case GOSSIP_ACTION_INFO_DEF+1:
                CAST_AI(npc_escortAI, (pCreature->AI()))->Start(true, false, pPlayer->GetGUID());
                CAST_AI(npc_escortAI, (pCreature->AI()))->SetMaxPlayerDistance(200.0f);
                break;
        }
        return true;
    }

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_thassarianAI(creature);
    }
};

/*######
## npc_image_lich_king
######*/

class npc_image_lich_king : public CreatureScript
{
public:
    npc_image_lich_king() : CreatureScript("npc_image_lich_king") { }

    struct npc_image_lich_kingAI : public ScriptedAI
    {
        npc_image_lich_kingAI(Creature* pCreature) : ScriptedAI(pCreature) {}

        void Reset()
        {
            me->RestoreFaction();
        }

        void MovementInform(uint32 uiType, uint32 /*uiId*/)
        {
            if (uiType != POINT_MOTION_TYPE)
                return;

            if (me->isSummon())
                if (Unit* pSummoner = me->ToTempSummon()->GetSummoner())
                    CAST_AI(npc_thassarian::npc_thassarianAI, CAST_CRE(pSummoner)->AI())->bArthasInPosition = true;
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_image_lich_kingAI(creature);
    }
};

/*######
## npc_general_arlos
######*/

class npc_general_arlos : public CreatureScript
{
public:
    npc_general_arlos() : CreatureScript("npc_general_arlos") { }

    struct npc_general_arlosAI : public ScriptedAI
    {
        npc_general_arlosAI(Creature* pCreature) : ScriptedAI(pCreature) {}

        void MovementInform(uint32 uiType, uint32 /*uiId*/)
        {
            if (uiType != POINT_MOTION_TYPE)
                return;

            me->AddUnitState(UNIT_STAT_STUNNED);
            me->CastSpell(me, SPELL_STUN, true);
            if (me->isSummon())
                if (Unit* pSummoner = me->ToTempSummon()->GetSummoner())
                    CAST_AI(npc_thassarian::npc_thassarianAI, CAST_CRE(pSummoner)->AI())->bArlosInPosition = true;
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_general_arlosAI(creature);
    }
};

/*######
## npc_counselor_talbot
######*/

enum eCounselorTalbot
{
    SPELL_DEFLECTION    = 51009,
    SPELL_SOUL_BLAST    = 50992,
};

class npc_counselor_talbot : public CreatureScript
{
public:
    npc_counselor_talbot() : CreatureScript("npc_counselor_talbot") { }

    struct npc_counselor_talbotAI : public ScriptedAI
    {
        npc_counselor_talbotAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            pCreature->RestoreFaction();
        }

        uint64 LeryssaGUID;
        uint64 ArlosGUID;

        bool bCheck;

        uint32 uiShadowBoltTimer;
        uint32 uiDeflectionTimer;
        uint32 uiSoulBlastTimer;

        void Reset()
        {
            LeryssaGUID         = 0;
            ArlosGUID           = 0;
            bCheck              = false;
            uiShadowBoltTimer   = urand(5000, 12000);
            uiDeflectionTimer   = urand(20000, 25000);
            uiSoulBlastTimer    = urand (12000, 18000);
        }
        void MovementInform(uint32 uiType, uint32 /*uiId*/)
        {
            if (uiType != POINT_MOTION_TYPE)
                return;

            if (me->isSummon())
                if (Unit* pSummoner = me->ToTempSummon()->GetSummoner())
                    CAST_AI(npc_thassarian::npc_thassarianAI, CAST_CRE(pSummoner)->AI())->bTalbotInPosition = true;
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (bCheck)
            {
                if (Creature *pLeryssa = me->FindNearestCreature(NPC_LERYSSA, 50.0f, true))
                    LeryssaGUID = pLeryssa->GetGUID();
                if (Creature *pArlos = me->FindNearestCreature(NPC_GENERAL_ARLOS, 50.0f, true))
                    ArlosGUID = pArlos->GetGUID();
                bCheck = false;
            }

            if (!UpdateVictim())
                return;

            if (me->GetAreaId() == 4125)
            {
                if (uiShadowBoltTimer <= uiDiff)
                {
                    DoCast(me->getVictim(), SPELL_SHADOW_BOLT);
                    uiShadowBoltTimer = urand(5000, 12000);
                } else uiShadowBoltTimer -= uiDiff;

                if (uiDeflectionTimer <= uiDiff)
                {
                    DoCast(me->getVictim(), SPELL_DEFLECTION);
                    uiDeflectionTimer = urand(20000, 25000);
                } else uiDeflectionTimer -= uiDiff;

                if (uiSoulBlastTimer <= uiDiff)
                {
                    DoCast(me->getVictim(), SPELL_SOUL_BLAST);
                    uiSoulBlastTimer  = urand (12000, 18000);
                } else uiSoulBlastTimer -= uiDiff;
            }

            DoMeleeAttackIfReady();
       }

       void JustDied(Unit* pKiller)
       {
            if (!LeryssaGUID || !ArlosGUID)
                return;

            Creature *pLeryssa = Unit::GetCreature(*me, LeryssaGUID);
            Creature *pArlos = Unit::GetCreature(*me, ArlosGUID);
            if (!pLeryssa || !pArlos)
                return;

            DoScriptText(SAY_ARLOS_1, pArlos);
            DoScriptText(SAY_ARLOS_2, pArlos);
            DoScriptText(SAY_LERYSSA_1, pLeryssa);
            pArlos->Kill(pArlos, false);
            pLeryssa->RemoveAura(SPELL_STUN);
            pLeryssa->ClearUnitState(UNIT_STAT_STUNNED);
            pLeryssa->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
            pLeryssa->GetMotionMaster()->MovePoint(0, 3722.114502f, 3564.201660f, 477.441437f);

            if (pKiller->GetTypeId() == TYPEID_PLAYER)
                CAST_PLR(pKiller)->RewardPlayerAndGroupAtEvent(NPC_PRINCE_VALANAR, 0);
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_counselor_talbotAI(creature);
    }
};

/*######
## npc_leryssa
######*/

class npc_leryssa : public CreatureScript
{
public:
    npc_leryssa() : CreatureScript("npc_leryssa") { }

    struct npc_leryssaAI : public ScriptedAI
    {
        npc_leryssaAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            bDone = false;
            Phase = 0;
            uiPhaseTimer = 0;

            pCreature->RemoveStandFlags(UNIT_STAND_STATE_SIT);
        }

        bool bDone;

        uint32 Phase;
        uint32 uiPhaseTimer;

        void MovementInform(uint32 uiType, uint32 /*uiId*/)
        {
            if (uiType != POINT_MOTION_TYPE)
                return;

            if (!bDone)
            {
                if (Creature* pTalbot = me->FindNearestCreature(NPC_PRINCE_VALANAR, 50.0f, true))
                    CAST_AI(npc_counselor_talbot::npc_counselor_talbotAI, pTalbot->GetAI())->bCheck = true;

                me->AddUnitState(UNIT_STAT_STUNNED);
                me->CastSpell(me, SPELL_STUN, true);

                if (me->isSummon())
                    if (Unit* pSummoner = me->ToTempSummon()->GetSummoner())
                        CAST_AI(npc_thassarian::npc_thassarianAI, pSummoner->GetAI())->bLeryssaInPosition = true;
                bDone = true;
            }
            else
            {
                me->SetStandState(UNIT_STAND_STATE_SIT);
                if (me->isSummon())
                    if (Unit* pSummoner = me->ToTempSummon()->GetSummoner())
                    pSummoner->SetStandState(UNIT_STAND_STATE_SIT);
                uiPhaseTimer = 1500;
                Phase = 1;
            }
        }

        void UpdateAI(const uint32 uiDiff)
        {
            ScriptedAI::UpdateAI(uiDiff);

            if (uiPhaseTimer <= uiDiff)
            {
                switch (Phase)
                {
                    case 1:
                        if (me->isSummon())
                            if (Unit* pThassarian = me->ToTempSummon()->GetSummoner())
                                DoScriptText(SAY_THASSARIAN_4, pThassarian);
                        uiPhaseTimer = 5000;
                        ++Phase;
                        break;
                    case 2:
                        DoScriptText(SAY_LERYSSA_2, me);
                        uiPhaseTimer = 5000;
                        ++Phase;
                        break;
                    case 3:
                        if (me->isSummon())
                            if (Unit* pThassarian = me->ToTempSummon()->GetSummoner())
                                DoScriptText(SAY_THASSARIAN_5, pThassarian);
                        uiPhaseTimer = 5000;
                        ++Phase;
                        break;
                    case 4:
                        DoScriptText(SAY_LERYSSA_3, me);
                        uiPhaseTimer = 5000;
                        ++Phase;
                        break;
                    case 5:
                        if (me->isSummon())
                            if (Unit* pThassarian = me->ToTempSummon()->GetSummoner())
                        DoScriptText(SAY_THASSARIAN_6, pThassarian);
                        uiPhaseTimer = 5000;
                        ++Phase;
                        break;

                    case 6:
                        DoScriptText(SAY_LERYSSA_4, me);
                        uiPhaseTimer = 5000;
                        ++Phase;
                        break;
                    case 7:
                        if (me->isSummon())
                            if (Unit* pThassarian = me->ToTempSummon()->GetSummoner())
                            {
                                DoScriptText(SAY_THASSARIAN_7, pThassarian);
                                CAST_AI(npc_thassarian::npc_thassarianAI, pThassarian->GetAI())->uiPhase = 16;
                            }
                        uiPhaseTimer = 5000;
                        Phase = 0;
                        break;
                }
            } else uiPhaseTimer -= uiDiff;

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_leryssaAI(creature);
    }
};

/*######
## npc_beryl_sorcerer
######*/

enum eBerylSorcerer
{
    NPC_CAPTURED_BERLY_SORCERER         = 25474,
    NPC_LIBRARIAN_DONATHAN              = 25262,

    SPELL_ARCANE_CHAINS                 = 45611,
    SPELL_COSMETIC_CHAINS               = 54324,
    SPELL_COSMETIC_ENSLAVE_CHAINS_SELF  = 45631
};

class npc_beryl_sorcerer : public CreatureScript
{
public:
    npc_beryl_sorcerer() : CreatureScript("npc_beryl_sorcerer") { }

    struct npc_beryl_sorcererAI : public FollowerAI
    {
        npc_beryl_sorcererAI(Creature* pCreature) : FollowerAI(pCreature) {}

        bool bEnslaved;

        void Reset()
        {
            me->SetReactState(REACT_AGGRESSIVE);
            bEnslaved = false;
        }

        void EnterCombat(Unit* pWho)
        {
            if (me->canAttack(pWho))
                AttackStart(pWho);
        }

        void SpellHit(Unit* pCaster, const SpellEntry* pSpell)
        {
            if (pSpell->Id == SPELL_ARCANE_CHAINS && pCaster->GetTypeId() == TYPEID_PLAYER && !HealthAbovePct(50) && !bEnslaved)
            {
                EnterEvadeMode(); //We make sure that the npc is not attacking the player!
                me->SetReactState(REACT_PASSIVE);
                StartFollow(pCaster->ToPlayer(), 0, NULL);
                me->UpdateEntry(NPC_CAPTURED_BERLY_SORCERER, TEAM_NEUTRAL);
                DoCast(me, SPELL_COSMETIC_ENSLAVE_CHAINS_SELF, true);
                CAST_PLR(pCaster)->KilledMonsterCredit(NPC_CAPTURED_BERLY_SORCERER, 0);
                bEnslaved = true;
            }
        }

        void MoveInLineOfSight(Unit* pWho)
        {
            FollowerAI::MoveInLineOfSight(pWho);

            if (pWho->GetEntry() == NPC_LIBRARIAN_DONATHAN && me->IsWithinDistInMap(pWho, INTERACTION_DISTANCE))
            {
                SetFollowComplete();
                me->DisappearAndDie();
            }
        }

        void UpdateAI(const uint32 /*uiDiff*/)
        {
            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_beryl_sorcererAI(creature);
    }
};

/*######
## npc_imprisoned_beryl_sorcerer
######*/

enum eImprisionedBerylSorcerer
{
    SPELL_NEURAL_NEEDLE             = 45634,

    NPC_IMPRISONED_BERYL_SORCERER   = 25478,

    SAY_IMPRISIONED_BERYL_1         = -1571024,
    SAY_IMPRISIONED_BERYL_2         = -1571025,
    SAY_IMPRISIONED_BERYL_3         = -1571026,
    SAY_IMPRISIONED_BERYL_4         = -1571027,
    SAY_IMPRISIONED_BERYL_5         = -1571028,
    SAY_IMPRISIONED_BERYL_6         = -1571029,
    SAY_IMPRISIONED_BERYL_7         = -1571030,
};

class npc_imprisoned_beryl_sorcerer : public CreatureScript
{
public:
    npc_imprisoned_beryl_sorcerer() : CreatureScript("npc_imprisoned_beryl_sorcerer") { }

    struct npc_imprisoned_beryl_sorcererAI : public ScriptedAI
    {
        npc_imprisoned_beryl_sorcererAI(Creature* pCreature) : ScriptedAI(pCreature) {}

        uint64 CasterGUID;

        uint32  uiStep;
        uint32  uiPhase;

        void Reset()
        {
            uiStep = 1;
            uiPhase = 0;
            CasterGUID = 0;
        }

        void EnterCombat(Unit* /*pWho*/)
        {
        }

        void SpellHit(Unit* pUnit, const SpellEntry* pSpell)
        {
            if (pSpell->Id == SPELL_NEURAL_NEEDLE && pUnit->GetTypeId() == TYPEID_PLAYER)
            {
                ++uiPhase;
                CasterGUID = pUnit->GetGUID();
            }
        }

        void UpdateAI(const uint32 uiDiff)
        {
            ScriptedAI::UpdateAI(uiDiff);

            if (!me->HasAura(SPELL_COSMETIC_ENSLAVE_CHAINS_SELF))
                DoCast(me, SPELL_COSMETIC_ENSLAVE_CHAINS_SELF);

            if (me->GetReactState() != REACT_PASSIVE)
                me->SetReactState(REACT_PASSIVE);

            switch (uiPhase)
            {
                case 1:
                    if (uiStep == 1)
                    {
                        DoScriptText(SAY_IMPRISIONED_BERYL_1, me);
                        uiStep = 2;
                    }
                    break;

                case 2:
                    if (uiStep == 2)
                    {
                        DoScriptText(SAY_IMPRISIONED_BERYL_2, me);
                        uiStep = 3;
                    }
                    break;

                case 3:
                    if (uiStep == 3)
                    {
                        DoScriptText(SAY_IMPRISIONED_BERYL_3, me);
                        uiStep = 4;
                    }
                    break;

                case 4:
                    if (uiStep == 4)
                    {
                        DoScriptText(SAY_IMPRISIONED_BERYL_4, me);
                        uiStep = 5;
                    }
                    break;

                case 5:
                    if (uiStep == 5)
                    {
                        if (Player *pCaster = Unit::GetPlayer(*me, CasterGUID))
                        {
                            DoScriptText(SAY_IMPRISIONED_BERYL_5, me);
                            pCaster->KilledMonsterCredit(25478, 0);
                            uiStep = 6;
                        }
                    }
                    break;

                case 6:
                    if (uiStep == 6)
                    {
                        DoScriptText(SAY_IMPRISIONED_BERYL_6, me);
                        uiStep = 7;
                    }
                    break;

                case 7:
                    if (uiStep == 7)
                    {
                        DoScriptText(SAY_IMPRISIONED_BERYL_7, me);
                        uiStep  = 1;
                        uiPhase = 0;
                    }
                    break;
            }
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_imprisoned_beryl_sorcererAI(creature);
    }
};

/*######
## npc_mootoo_the_younger
######*/
enum Script_Texts_Mootoo_the_Younger
{
    SAY_1                    =-1750040,
    SAY_2                    =-1750041,
    SAY_3                    =-1750042,
    SAY_4                    =-1750043,
    SAY_5                    =-1750044
};
enum Mootoo_the_Younger_Entries
{
    NPC_MOOTOO_THE_YOUNGER          =25504,
    QUEST_ESCAPING_THE_MIST         =11664
};

class npc_mootoo_the_younger : public CreatureScript
{
public:
    npc_mootoo_the_younger() : CreatureScript("npc_mootoo_the_younger") { }

    bool OnQuestAccept(Player* pPlayer, Creature* pCreature, Quest const* quest)
    {
        if (quest->GetQuestId() == QUEST_ESCAPING_THE_MIST)
        {
            switch (pPlayer->GetTeam())
            {
            case ALLIANCE:
                pCreature->setFaction(FACTION_ESCORTEE_A);
                break;
            case HORDE:
                pCreature->setFaction(FACTION_ESCORTEE_H);
                break;
            }
            DoScriptText(SAY_1, pCreature);
            CAST_AI(npc_escortAI, (pCreature->AI()))->Start(true, false, pPlayer->GetGUID());
        }
        return true;
    }

    struct npc_mootoo_the_youngerAI : public npc_escortAI
    {
        npc_mootoo_the_youngerAI(Creature *c) : npc_escortAI(c) {}

        void Reset()
        {
            SetDespawnAtFar(false);
        }

        void JustDied(Unit* /*killer*/)
        {
            if (Player* pPlayer=GetPlayerForEscort())
                pPlayer->FailQuest(QUEST_ESCAPING_THE_MIST);
        }

        void WaypointReached(uint32 i)
        {
            Player* pPlayer = GetPlayerForEscort();

            if (!pPlayer)
                return;

            switch(i)
            {
            case 10:
                me->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
                DoScriptText(SAY_2, me);
                break;
            case 12:
                DoScriptText(SAY_3, me);
                me->HandleEmoteCommand(EMOTE_ONESHOT_LOOT);
                break;
            case 16:
                DoScriptText(SAY_4, me);
                me->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
                break;
            case 20:
                me->SetPhaseMask(1, true);
                DoScriptText(SAY_5, me);
                me->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
                if (pPlayer)
                    pPlayer->GroupEventHappens(QUEST_ESCAPING_THE_MIST, me);
                SetRun(true);
                break;
            }
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_mootoo_the_youngerAI(creature);
    }
};

/*######
## npc_bonker_togglevolt
######*/

enum Bonker_Togglevolt_Entries
{
    NPC_BONKER_TOGGLEVOLT           =25589,
    QUEST_GET_ME_OUTA_HERE          =11673
};
enum Script_Texts_Bonker_Togglevolt
{
    SAY_bonker_1                    =-1700002,
    SAY_bonker_2                    =-1700003
};

class npc_bonker_togglevolt : public CreatureScript
{
public:
    npc_bonker_togglevolt() : CreatureScript("npc_bonker_togglevolt") { }

    bool OnQuestAccept(Player* pPlayer, Creature* pCreature, Quest const* quest)
    {
        if (quest->GetQuestId() == QUEST_GET_ME_OUTA_HERE)
        {
            switch (pPlayer->GetTeam())
            {
            case ALLIANCE:
                    pCreature->setFaction(FACTION_ESCORTEE_A);
                    break;
            case HORDE:
                    pCreature->setFaction(FACTION_ESCORTEE_H);
                    break;
            }
            DoScriptText(SAY_bonker_2, pCreature, pPlayer);
            CAST_AI(npc_escortAI, (pCreature->AI()))->Start(true, true, pPlayer->GetGUID());
        }
        return true;
    }

    struct npc_bonker_togglevoltAI : public npc_escortAI
    {
        npc_bonker_togglevoltAI(Creature *c) : npc_escortAI(c) {}
        uint32 Bonker_agro;

        void Reset()
        {
        Bonker_agro=0;
        SetDespawnAtFar(false);
        }

        void JustDied(Unit* /*killer*/)
        {
            if (Player* pPlayer = GetPlayerForEscort())
                pPlayer->FailQuest(QUEST_GET_ME_OUTA_HERE);
        }

        void UpdateEscortAI(const uint32 /*diff*/)
        {
            if (GetAttack() && UpdateVictim())
            {
                if (Bonker_agro == 0)
                {
                    DoScriptText(SAY_bonker_1, me);
                    Bonker_agro++;
                }
                DoMeleeAttackIfReady();
            }
            else Bonker_agro=0;
        }

        void WaypointReached(uint32 i)
        {
            Player* pPlayer = GetPlayerForEscort();

            if (!pPlayer)
                return;

            switch(i)
            {
            case 29:
                if (pPlayer)
                    pPlayer->GroupEventHappens(QUEST_GET_ME_OUTA_HERE, me);
                break;
            }
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_bonker_togglevoltAI(creature);
    }
};

/*######
## Help Those That Cannot Help Themselves, Quest 11876
######*/

enum eHelpThemselves
{
    QUEST_CANNOT_HELP_THEMSELVES                  =  11876,
    GO_MAMMOTH_TRAP_1                             = 188022,
    GO_MAMMOTH_TRAP_2                             = 188024,
    GO_MAMMOTH_TRAP_3                             = 188025,
    GO_MAMMOTH_TRAP_4                             = 188026,
    GO_MAMMOTH_TRAP_5                             = 188027,
    GO_MAMMOTH_TRAP_6                             = 188028,
    GO_MAMMOTH_TRAP_7                             = 188029,
    GO_MAMMOTH_TRAP_8                             = 188030,
    GO_MAMMOTH_TRAP_9                             = 188031,
    GO_MAMMOTH_TRAP_10                            = 188032,
    GO_MAMMOTH_TRAP_11                            = 188033,
    GO_MAMMOTH_TRAP_12                            = 188034,
    GO_MAMMOTH_TRAP_13                            = 188035,
    GO_MAMMOTH_TRAP_14                            = 188036,
    GO_MAMMOTH_TRAP_15                            = 188037,
    GO_MAMMOTH_TRAP_16                            = 188038,
    GO_MAMMOTH_TRAP_17                            = 188039,
    GO_MAMMOTH_TRAP_18                            = 188040,
    GO_MAMMOTH_TRAP_19                            = 188041,
    GO_MAMMOTH_TRAP_20                            = 188042,
    GO_MAMMOTH_TRAP_21                            = 188043,
    GO_MAMMOTH_TRAP_22                            = 188044,
};

#define MammothTrapsNum 22
const uint32 MammothTraps[MammothTrapsNum] =
{
    GO_MAMMOTH_TRAP_1, GO_MAMMOTH_TRAP_2, GO_MAMMOTH_TRAP_3, GO_MAMMOTH_TRAP_4, GO_MAMMOTH_TRAP_5,
    GO_MAMMOTH_TRAP_6, GO_MAMMOTH_TRAP_7, GO_MAMMOTH_TRAP_8, GO_MAMMOTH_TRAP_9, GO_MAMMOTH_TRAP_10,
    GO_MAMMOTH_TRAP_11, GO_MAMMOTH_TRAP_12, GO_MAMMOTH_TRAP_13, GO_MAMMOTH_TRAP_14, GO_MAMMOTH_TRAP_15,
    GO_MAMMOTH_TRAP_16, GO_MAMMOTH_TRAP_17, GO_MAMMOTH_TRAP_18, GO_MAMMOTH_TRAP_19, GO_MAMMOTH_TRAP_20,
    GO_MAMMOTH_TRAP_21, GO_MAMMOTH_TRAP_22
};

class npc_trapped_mammoth_calf : public CreatureScript
{
public:
    npc_trapped_mammoth_calf() : CreatureScript("npc_trapped_mammoth_calf") { }

    struct npc_trapped_mammoth_calfAI : public ScriptedAI
    {
        npc_trapped_mammoth_calfAI(Creature* c) : ScriptedAI(c) {}

        uint32 uiTimer;
        bool bStarted;

        void Reset()
        {
            uiTimer = 1500;
            bStarted = false;

            GameObject* pTrap;
            for (uint8 i = 0; i < MammothTrapsNum; ++i)
            {
                pTrap = me->FindNearestGameObject(MammothTraps[i], 11.0f);
                if (pTrap)
                {
                    pTrap->SetGoState(GO_STATE_ACTIVE);
                    return;
                }
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (bStarted)
            {
                if (uiTimer <= diff)
                {
                    Position pos;
                    me->GetRandomNearPosition(pos, 10.0f);
                    me->GetMotionMaster()->MovePoint(0, pos);
                    bStarted = false;
                }
                else uiTimer -= diff;
            }
        }

        void DoAction(const int32 param)
        {
            if (param == 1)
                bStarted = true;
        }

        void MovementInform(uint32 uiType, uint32 /*uiId*/)
        {

            if (uiType != POINT_MOTION_TYPE)
                return;
            me->DisappearAndDie();
            GameObject* pTrap;
            for (uint8 i = 0; i < MammothTrapsNum; ++i)
            {
                pTrap = me->FindNearestGameObject(MammothTraps[i], 11.0f);
                if (pTrap)
                {
                    pTrap->SetLootState(GO_JUST_DEACTIVATED);
                    return;
                }
            }
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_trapped_mammoth_calfAI(creature);
    }
};

/*######
## Quest 11653: Hah... You're Not So Big Now!
######*/

enum eNotSoBig
{
    QUEST_YOU_RE_NOT_SO_BIG_NOW                   = 11653,
    SPELL_AURA_NOTSOBIG_1                         = 45672,
    SPELL_AURA_NOTSOBIG_2                         = 45673,
    SPELL_AURA_NOTSOBIG_3                         = 45677,
    SPELL_AURA_NOTSOBIG_4                         = 45681
};

class npc_magmoth_crusher : public CreatureScript
{
public:
    npc_magmoth_crusher() : CreatureScript("npc_magmoth_crusher") { }

    struct npc_magmoth_crusherAI : public ScriptedAI
    {
        npc_magmoth_crusherAI(Creature* c) : ScriptedAI(c) {}

        void JustDied(Unit *pKiller)
        {
            if (pKiller->GetTypeId() == TYPEID_PLAYER &&
                CAST_PLR(pKiller)->GetQuestStatus(QUEST_YOU_RE_NOT_SO_BIG_NOW) == QUEST_STATUS_INCOMPLETE &&
                (me->HasAura(SPELL_AURA_NOTSOBIG_1) || me->HasAura(SPELL_AURA_NOTSOBIG_2) ||
                me->HasAura(SPELL_AURA_NOTSOBIG_3) || me->HasAura(SPELL_AURA_NOTSOBIG_4)))
            {
                Quest const* qInfo = sObjectMgr->GetQuestTemplate(QUEST_YOU_RE_NOT_SO_BIG_NOW);
                if (qInfo)
                    CAST_PLR(pKiller)->KilledMonsterCredit(qInfo->ReqCreatureOrGOId[0], 0);
            }
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_magmoth_crusherAI(creature);
    }
};

/*######
## Quest 11608: Bury Those Cockroaches!
######*/

#define QUEST_BURY_THOSE_COCKROACHES            11608
#define SPELL_SEAFORIUM_DEPTH_CHARGE_EXPLOSION  45502

class npc_seaforium_depth_charge : public CreatureScript
{
public:
    npc_seaforium_depth_charge() : CreatureScript("npc_seaforium_depth_charge") { }

    struct npc_seaforium_depth_chargeAI : public ScriptedAI
    {
        npc_seaforium_depth_chargeAI(Creature *c) : ScriptedAI(c) {}

        uint32 uiExplosionTimer;
        void Reset()
        {
            uiExplosionTimer = urand(5000, 10000);
        }
        void UpdateAI(const uint32 diff)
        {
            if (uiExplosionTimer < diff)
            {
                DoCast(SPELL_SEAFORIUM_DEPTH_CHARGE_EXPLOSION);
                for (uint8 i = 0; i < 4; ++i)
                {
                    if (Creature* cCredit = me->FindNearestCreature(25402 + i, 10.0f))//25402-25405 credit markers
                    {
                        if (Unit* uOwner = me->GetOwner())
                        {
                            Player* pOwner = uOwner->ToPlayer();
                            if (pOwner && pOwner->GetQuestStatus(QUEST_BURY_THOSE_COCKROACHES) == QUEST_STATUS_INCOMPLETE)
                                pOwner->KilledMonsterCredit(cCredit->GetEntry(), cCredit->GetGUID());
                        }
                    }
                }
                me->Kill(me);
                return;
            } else uiExplosionTimer -= diff;
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_seaforium_depth_chargeAI(creature);
    }
};

/*######
## Help Those That Cannot Help Themselves, Quest 11876
######*/

enum eValiancekeepcannons
{
    GO_VALIANCE_KEEP_CANNON_1                     = 187560,
    GO_VALIANCE_KEEP_CANNON_2                     = 188692
};

class npc_valiance_keep_cannoneer : public CreatureScript
{
public:
    npc_valiance_keep_cannoneer() : CreatureScript("npc_valiance_keep_cannoneer") { }

    struct npc_valiance_keep_cannoneerAI : public ScriptedAI
    {
        npc_valiance_keep_cannoneerAI(Creature* c) : ScriptedAI(c) {}

        uint32 uiTimer;

        void Reset()
        {
            uiTimer = urand(13000, 18000);
        }

        void UpdateAI(const uint32 diff)
        {
            if (uiTimer <= diff)
            {
                me->HandleEmoteCommand(EMOTE_ONESHOT_KNEEL);
                GameObject* pCannon = me->FindNearestGameObject(GO_VALIANCE_KEEP_CANNON_1, 10);
                if (!pCannon)
                    pCannon = me->FindNearestGameObject(GO_VALIANCE_KEEP_CANNON_2, 10);
                if (pCannon)
                    pCannon->Use(me);
                uiTimer = urand(13000, 18000);
            }
            else uiTimer -= diff;

            if (!UpdateVictim())
                return;
        }

    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_valiance_keep_cannoneerAI(creature);
    }
};

/*******************************************************
 * npc_warmage_coldarra
 *******************************************************/

enum Spells
{
    SPELL_TRANSITUS_SHIELD_BEAM = 48310
};

enum NPCs
{
    NPC_TRANSITUS_SHIELD_DUMMY   = 27306,
    NPC_WARMAGE_HOLLISTER        = 27906,
    NPC_WARMAGE_CALANDRA         = 27173,
    NPC_WARMAGE_WATKINS          = 27904
};

class npc_warmage_coldarra : public CreatureScript
{
public:
    npc_warmage_coldarra() : CreatureScript("npc_warmage_coldarra") { }

    struct npc_warmage_coldarraAI : public Scripted_NoMovementAI
    {
        npc_warmage_coldarraAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature){}

        uint32 m_uiTimer;                 //Timer until recast

        void Reset()
        {
            m_uiTimer = 0;
        }

        void EnterCombat(Unit* /*pWho*/) {}

        void AttackStart(Unit* /*pWho*/) {}

        void UpdateAI(const uint32 uiDiff)
        {
            if (m_uiTimer <= uiDiff)
            {
                std::list<Creature*> orbList;
                GetCreatureListWithEntryInGrid(orbList, me, NPC_TRANSITUS_SHIELD_DUMMY, 32.0f);

                switch(me->GetEntry())
                {
                    case NPC_WARMAGE_HOLLISTER:
                    {
                        if (!orbList.empty())
                        {
                            for (std::list<Creature*>::const_iterator itr = orbList.begin(); itr != orbList.end(); ++itr)
                            {
                                if (Creature* pOrb = *itr)
                                    if (pOrb->GetPositionY() > 6680)
                                        DoCast(pOrb, SPELL_TRANSITUS_SHIELD_BEAM);
                            }
                        }
                        m_uiTimer = urand(90000, 120000);
                    }
                        break;
                    case NPC_WARMAGE_CALANDRA:
                    {
                        if (!orbList.empty())
                        {
                            for (std::list<Creature*>::const_iterator itr = orbList.begin(); itr != orbList.end(); ++itr)
                            {
                                if (Creature* pOrb = *itr)
                                    if ((pOrb->GetPositionY() < 6680) && (pOrb->GetPositionY() > 6630))
                                        DoCast(pOrb, SPELL_TRANSITUS_SHIELD_BEAM);
                            }
                        }
                        m_uiTimer = urand(90000, 120000);
                    }
                        break;
                    case NPC_WARMAGE_WATKINS:
                    {
                        if (!orbList.empty())
                        {
                            for (std::list<Creature*>::const_iterator itr = orbList.begin(); itr != orbList.end(); ++itr)
                            {
                                if (Creature* pOrb = *itr)
                                    if (pOrb->GetPositionY() < 6630)
                                        DoCast(pOrb, SPELL_TRANSITUS_SHIELD_BEAM);
                            }
                        }
                        m_uiTimer = urand(90000, 120000);
                    }
                        break;
                }
            }
            else m_uiTimer -= uiDiff;

            ScriptedAI::UpdateAI(uiDiff);

            if (!UpdateVictim())
                return;
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_warmage_coldarraAI(creature);
    }
};

/*######
## npc_hidden_cultist
######*/

enum eHiddenCultist
{
    SPELL_SHROUD_OF_THE_DEATH_CULTIST           = 46077, //not working
    SPELL_RIGHTEOUS_VISION                      = 46078, //player aura

    QUEST_THE_HUNT_IS_ON                        = 11794,

    GOSSIP_TEXT_SALTY_JOHN_THORPE               = 12529,
    GOSSIP_TEXT_GUARD_MITCHELSS                 = 12530,
    GOSSIP_TEXT_TOM_HEGGER                      = 12528,

    NPC_TOM_HEGGER                              = 25827,
    NPC_SALTY_JOHN_THORPE                       = 25248,
    NPC_GUARD_MITCHELLS                         = 25828,

    SAY_HIDDEN_CULTIST_1                        = -1571044,
    SAY_HIDDEN_CULTIST_2                        = -1571045,
    SAY_HIDDEN_CULTIST_3                        = -1571046,
    SAY_HIDDEN_CULTIST_4                        = -1571047
};

const char* GOSSIP_ITEM_TOM_HEGGER = "What do you know about the Cult of the Damned?";
const char* GOSSIP_ITEM_GUARD_MITCHELLS = "How long have you worked for the Cult of the Damned?";
const char* GOSSIP_ITEM_SALTY_JOHN_THORPE = "I have a reason to believe you're involved in the cultist activity";

class npc_hidden_cultist : public CreatureScript
{
public:
    npc_hidden_cultist() : CreatureScript("npc_hidden_cultist") { }

    struct npc_hidden_cultistAI : public ScriptedAI
    {
        npc_hidden_cultistAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
           uiEmoteState = pCreature->GetUInt32Value(UNIT_NPC_EMOTESTATE);
           uiNpcFlags = pCreature->GetUInt32Value(UNIT_NPC_FLAGS);
        }

        uint32 uiEmoteState;
        uint32 uiNpcFlags;

        uint32 uiEventTimer;
        uint8 uiEventPhase;

        uint64 uiPlayerGUID;

        void Reset()
        {
            if (uiEmoteState)
                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, uiEmoteState);

            if (uiNpcFlags)
                me->SetUInt32Value(UNIT_NPC_FLAGS, uiNpcFlags);

            uiEventTimer = 0;
            uiEventPhase = 0;

            uiPlayerGUID = 0;

            DoCast(SPELL_SHROUD_OF_THE_DEATH_CULTIST);

            me->RestoreFaction();
        }

        void DoAction(const int32 /*iParam*/)
        {
            me->StopMoving();
            me->SetUInt32Value(UNIT_NPC_FLAGS, 0);
            if (Player* pPlayer = me->GetPlayer(*me, uiPlayerGUID))
            {
                me->SetInFront(pPlayer);
                me->SendMovementFlagUpdate();
            }
            uiEventTimer = 3000;
            uiEventPhase = 1;
        }

        void SetGUID(const uint64 &uiGuid, int32 /*iId*/)
        {
            uiPlayerGUID = uiGuid;
        }

        void AttackPlayer()
        {
            me->setFaction(14);
            if (Player* pPlayer = me->GetPlayer(*me, uiPlayerGUID))
                me->AI()->AttackStart(pPlayer);
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (uiEventTimer && uiEventTimer <= uiDiff)
            {
                switch(uiEventPhase)
                {
                    case 1:
                        switch(me->GetEntry())
                        {
                            case NPC_SALTY_JOHN_THORPE:
                                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);
                                DoScriptText(SAY_HIDDEN_CULTIST_1, me);
                                uiEventTimer = 5000;
                                uiEventPhase = 2;
                                break;
                            case NPC_GUARD_MITCHELLS:
                                DoScriptText(SAY_HIDDEN_CULTIST_2, me);
                                uiEventTimer = 5000;
                                uiEventPhase = 2;
                                break;
                            case NPC_TOM_HEGGER:
                                DoScriptText(SAY_HIDDEN_CULTIST_3, me);
                                uiEventTimer = 5000;
                                uiEventPhase = 2;
                                break;
                        }
                        break;
                    case 2:
                        switch(me->GetEntry())
                        {
                            case NPC_SALTY_JOHN_THORPE:
                                DoScriptText(SAY_HIDDEN_CULTIST_4, me);
                                if (Player* pPlayer = me->GetPlayer(*me, uiPlayerGUID))
                                {
                                    me->SetInFront(pPlayer);
                                    me->SendMovementFlagUpdate();
                                }
                                uiEventTimer = 3000;
                                uiEventPhase = 3;
                                break;
                            case NPC_GUARD_MITCHELLS:
                            case NPC_TOM_HEGGER:
                                AttackPlayer();
                                uiEventPhase = 0;
                                break;
                        }
                        break;
                    case 3:
                        if (me->GetEntry() == NPC_SALTY_JOHN_THORPE)
                        {
                            AttackPlayer();
                            uiEventPhase = 0;
                        }
                        break;
                }
            }else uiEventTimer -= uiDiff;

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_hidden_cultistAI(pCreature);
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        uint32 uiGossipText = 0;
        const char* charGossipItem;

        switch(pCreature->GetEntry())
        {
            case NPC_TOM_HEGGER:
                uiGossipText = GOSSIP_TEXT_TOM_HEGGER;
                charGossipItem = GOSSIP_ITEM_TOM_HEGGER;
                break;
            case NPC_SALTY_JOHN_THORPE:
                uiGossipText = GOSSIP_TEXT_SALTY_JOHN_THORPE;
                charGossipItem = GOSSIP_ITEM_SALTY_JOHN_THORPE;
                break;
            case NPC_GUARD_MITCHELLS:
                uiGossipText = GOSSIP_TEXT_GUARD_MITCHELSS;
                charGossipItem = GOSSIP_ITEM_GUARD_MITCHELLS;
                break;
            default:
                charGossipItem = "";
                return false;
        }

        if (pPlayer->HasAura(SPELL_RIGHTEOUS_VISION) && pPlayer->GetQuestStatus(QUEST_THE_HUNT_IS_ON) == QUEST_STATUS_INCOMPLETE)
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, charGossipItem, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        if (pCreature->isVendor())
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);

        pPlayer->SEND_GOSSIP_MENU(uiGossipText, pCreature->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();

        if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
        {
            pPlayer->CLOSE_GOSSIP_MENU();
            pCreature->AI()->SetGUID(pPlayer->GetGUID());
            pCreature->AI()->DoAction(1);
        }

        if (uiAction == GOSSIP_ACTION_TRADE)
            pPlayer->SEND_VENDORLIST(pCreature->GetGUID());

        return true;
    }

};

void AddSC_borean_tundra()
{
    new npc_sinkhole_kill_credit;
    new npc_khunok_the_behemoth;
    new npc_keristrasza;
    new npc_corastrasza;
    new npc_iruk;
    new mob_nerubar_victim;
    new npc_scourge_prisoner;
    new npc_jenny;
    new npc_fezzix_geartwist;
    new npc_nesingwary_trapper;
    new npc_lurgglbr;
    new npc_nexus_drake_hatchling;
    new npc_thassarian;
    new npc_image_lich_king;
    new npc_counselor_talbot;
    new npc_leryssa;
    new npc_general_arlos;
    new npc_beryl_sorcerer;
    new npc_imprisoned_beryl_sorcerer;
    new npc_mootoo_the_younger;
    new npc_bonker_togglevolt;
    new npc_trapped_mammoth_calf;
    new npc_magmoth_crusher;
    new npc_seaforium_depth_charge;
    new npc_valiance_keep_cannoneer;
    new npc_warmage_coldarra;
    new npc_hidden_cultist;
}
