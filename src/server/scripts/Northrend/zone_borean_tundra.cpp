/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
npc_nerubar_victim
npc_keristrasza
npc_nesingwary_trapper
npc_lurgglbr
npc_nexus_drake_hatchling
EndContentData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"
#include "ScriptedFollowerAI.h"
#include "Player.h"
#include "SpellInfo.h"
#include "WorldSession.h"

/*######
## npc_sinkhole_kill_credit
######*/

enum Sinkhole
{
    GO_EXPLOSIVES_CART            = 188160,
    NPC_SCOURGED_BURROWER         = 26250,
    QUEST_PLUG_THE_SINKHOLES      = 11897,
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
        npc_sinkhole_kill_creditAI(Creature* creature) : ScriptedAI(creature){ }

        uint32 phaseTimer;
        uint8  phase;
        uint64 casterGuid;

        void Reset() OVERRIDE
        {
            phaseTimer = 500;
            phase = 0;
            casterGuid = 0;
        }

        void SpellHit(Unit* caster, const SpellInfo* spell) OVERRIDE
        {
            if (phase || spell->Id != SPELL_SET_CART)
                return;

            Player* player = caster->ToPlayer();
            if (player && player->GetQuestStatus(QUEST_PLUG_THE_SINKHOLES) == QUEST_STATUS_INCOMPLETE)
            {
                phase = 1;
                casterGuid = caster->GetGUID();
            }
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE { }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!phase)
                return;

            if (phaseTimer <= diff)
            {
                switch (phase)
                {
                    case 1:
                        DoCast(me, SPELL_EXPLODE_CART, true);
                        DoCast(me, SPELL_SUMMON_CART, true);
                        if (GameObject* cart = me->FindNearestGameObject(GO_EXPLOSIVES_CART, 3.0f))
                            cart->SetUInt32Value(GAMEOBJECT_FACTION, 14);
                        phaseTimer = 3000;
                        phase = 2;
                        break;
                    case 2:
                        if (GameObject* cart = me->FindNearestGameObject(GO_EXPLOSIVES_CART, 3.0f))
                            cart->UseDoorOrButton();
                        DoCast(me, SPELL_EXPLODE_CART, true);
                        phaseTimer = 3000;
                        phase = 3;
                        break;
                    case 3:
                        DoCast(me, SPELL_EXPLODE_CART, true);
                        phaseTimer = 2000;
                        phase = 5; // @fixme: phase 4 is missing...
                        break;
                    case 5:
                        DoCast(me, SPELL_SUMMON_WORM, true);
                        if (Unit* worm = me->FindNearestCreature(NPC_SCOURGED_BURROWER, 3.0f))
                        {
                            worm->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                            worm->HandleEmoteCommand(EMOTE_ONESHOT_EMERGE);
                        }
                        phaseTimer = 1000;
                        phase = 6;
                        break;
                    case 6:
                        DoCast(me, SPELL_EXPLODE_CART, true);
                        if (Unit* worm = me->FindNearestCreature(NPC_SCOURGED_BURROWER, 3.0f))
                        {
                            me->Kill(worm);
                            worm->RemoveFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
                        }
                        phaseTimer = 2000;
                        phase = 7;
                        break;
                    case 7:
                        DoCast(me, SPELL_EXPLODE_CART, true);
                        if (Player* caster = ObjectAccessor::GetPlayer(*me, casterGuid))
                            caster->KilledMonster(me->GetCreatureTemplate(), me->GetGUID());
                        phaseTimer = 5000;
                        phase = 8;
                        break;
                    case 8:
                        EnterEvadeMode();
                        break;
                }
            } else phaseTimer -= diff;

        }

    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_sinkhole_kill_creditAI(creature);
    }
};

/*######
## npc_khunok_the_behemoth
######*/

enum Khunok
{
    NPC_ORPHANED_MAMMOTH_CALF        = 25861,
    SPELL_MAMMOTH_CALF_ESCORT_CREDIT = 46231
};

class npc_khunok_the_behemoth : public CreatureScript
{
public:
    npc_khunok_the_behemoth() : CreatureScript("npc_khunok_the_behemoth") { }

    struct npc_khunok_the_behemothAI : public ScriptedAI
    {
        npc_khunok_the_behemothAI(Creature* creature) : ScriptedAI(creature) { }

        void MoveInLineOfSight(Unit* who) OVERRIDE

        {
            ScriptedAI::MoveInLineOfSight(who);

            if (who->GetTypeId() != TYPEID_UNIT)
                return;

            if (who->GetEntry() == NPC_ORPHANED_MAMMOTH_CALF && me->IsWithinDistInMap(who, 10.0f))
            {
                if (Unit* owner = who->GetOwner())
                {
                    if (owner->GetTypeId() == TYPEID_PLAYER)
                    {
                        owner->CastSpell(owner, SPELL_MAMMOTH_CALF_ESCORT_CREDIT, true);
                        who->ToCreature()->DespawnOrUnsummon();
                    }
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_khunok_the_behemothAI(creature);
    }
};

/*######
## npc_keristrasza
######*/

enum Keristrasza
{
    SPELL_TELEPORT_TO_SARAGOSA = 46772
};

#define GOSSIP_HELLO_KERI   "I am prepared to face Saragosa!"

class npc_keristrasza : public CreatureScript
{
public:
    npc_keristrasza() : CreatureScript("npc_keristrasza") { }

    bool OnGossipHello(Player* player, Creature* creature) OVERRIDE
    {
        if (creature->IsQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        if (player->GetQuestStatus(11957) == QUEST_STATUS_INCOMPLETE)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_KERI, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 /*sender*/, uint32 action) OVERRIDE
    {
        player->PlayerTalkClass->ClearMenus();
        if (action == GOSSIP_ACTION_INFO_DEF + 1)
        {
            player->CLOSE_GOSSIP_MENU();
            player->CastSpell(player, SPELL_TELEPORT_TO_SARAGOSA, true);
        }

        return true;
    }
};

/*######
## npc_corastrasza
######*/

#define GOSSIP_ITEM_C_1 "I... I think so..."

enum Corastrasza
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

    bool OnGossipHello(Player* player, Creature* creature) OVERRIDE
    {
        if (creature->IsQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        if (player->GetQuestStatus(QUEST_ACES_HIGH) == QUEST_STATUS_INCOMPLETE || player->GetQuestStatus(QUEST_ACES_HIGH_DAILY) == QUEST_STATUS_INCOMPLETE) //It's the same dragon for both quests.
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_C_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 /*sender*/, uint32 action) OVERRIDE
    {
        player->PlayerTalkClass->ClearMenus();
        if (action == GOSSIP_ACTION_INFO_DEF+1)
        {
            player->CLOSE_GOSSIP_MENU();

            player->CastSpell(player, SPELL_SUMMON_WYRMREST_SKYTALON, true);
            player->CastSpell(player, SPELL_WYRMREST_SKYTALON_RIDE_PERIODIC, true);

        }

        return true;
    }
};

/*######
## npc_iruk
######*/

#define GOSSIP_ITEM_I  "<Search corpse for Issliruk's Totem.>"

enum Iruk
{
    QUEST_SPIRITS_WATCH_OVER_US             = 11961,
    SPELL_CREATURE_TOTEM_OF_ISSLIRUK        = 46816,
    GOSSIP_TEXT_I                           = 12585
};

class npc_iruk : public CreatureScript
{
public:
    npc_iruk() : CreatureScript("npc_iruk") { }

    bool OnGossipHello(Player* player, Creature* creature) OVERRIDE
    {
        if (player->GetQuestStatus(QUEST_SPIRITS_WATCH_OVER_US) == QUEST_STATUS_INCOMPLETE)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_I, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        player->PlayerTalkClass->SendGossipMenu(GOSSIP_TEXT_I, creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 /*sender*/, uint32 action) OVERRIDE
    {
        player->PlayerTalkClass->ClearMenus();
        switch (action)
        {
            case GOSSIP_ACTION_INFO_DEF+1:
                player->CastSpell(player, SPELL_CREATURE_TOTEM_OF_ISSLIRUK, true);
                player->CLOSE_GOSSIP_MENU();
                break;

        }
        return true;
    }
};

/*######
## npc_nerubar_victim
######*/

enum Nerubar
{
    NPC_WARSONG_PEON                        = 25270,
    QUEST_TAKEN_BY_THE_SCOURGE              = 11611,
    SPELL_FREED_WARSONG_MAGE                = 45526,
    SPELL_FREED_WARSONG_SHAMAN              = 45527,
    SPELL_FREED_WARSONG_WARRIOR             = 45514,
    SPELL_FREED_WARSONG_PEON                = 45532
};

const uint32 nerubarVictims[3] =
{
    SPELL_FREED_WARSONG_MAGE, SPELL_FREED_WARSONG_SHAMAN, SPELL_FREED_WARSONG_WARRIOR
};

class npc_nerubar_victim : public CreatureScript
{
public:
    npc_nerubar_victim() : CreatureScript("npc_nerubar_victim") { }

    struct npc_nerubar_victimAI : public ScriptedAI
    {
        npc_nerubar_victimAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() OVERRIDE { }
        void EnterCombat(Unit* /*who*/) OVERRIDE { }
        void MoveInLineOfSight(Unit* /*who*/) OVERRIDE { }


        void JustDied(Unit* killer) OVERRIDE
        {
            Player* player = killer->ToPlayer();
            if (!player)
                return;

            if (player->GetQuestStatus(QUEST_TAKEN_BY_THE_SCOURGE) == QUEST_STATUS_INCOMPLETE)
            {
                uint8 uiRand = urand(0, 99);
                if (uiRand < 25)
                {
                    player->CastSpell(me, SPELL_FREED_WARSONG_PEON, true);
                    player->KilledMonsterCredit(NPC_WARSONG_PEON, 0);
                }
                else if (uiRand < 75)
                    player->CastSpell(me, nerubarVictims[urand(0, 2)], true);
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_nerubar_victimAI(creature);
    }
};

/*######
## npc_jenny
######*/

enum Jenny
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
        npc_jennyAI(Creature* creature) : ScriptedAI(creature)
        {
            setCrateNumber = false;
        }

        bool setCrateNumber;

        void Reset() OVERRIDE
        {
            if (!setCrateNumber)
                setCrateNumber = true;

            me->SetReactState(REACT_PASSIVE);

            if (!me->GetOwner())
                return;

            switch (me->GetOwner()->ToPlayer()->GetTeamId())
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

        void DamageTaken(Unit* /*pDone_by*/, uint32& /*uiDamage*/) OVERRIDE
        {
            DoCast(me, SPELL_DROP_CRATE, true);
        }

        void UpdateAI(uint32 /*diff*/) OVERRIDE
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

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_jennyAI(creature);
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
        npc_fezzix_geartwistAI(Creature* creature) : ScriptedAI(creature) { }

        void MoveInLineOfSight(Unit* who) OVERRIDE

        {
            ScriptedAI::MoveInLineOfSight(who);

            if (who->GetEntry() != NPC_JENNY || !who->HasAura(SPELL_CRATES_CARRIED))
                return;

            Unit* owner = who->GetOwner();
            if (!owner || !me->IsWithinDistInMap(who, 10.0f))
                return;

            if (Player* player = owner->ToPlayer())
            {
                owner->CastSpell(owner, SPELL_GIVE_JENNY_CREDIT, true); // Maybe is not working.
                player->CompleteQuest(QUEST_LOADER_UP);
                who->ToCreature()->DisappearAndDie();
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_fezzix_geartwistAI(creature);
    }
};

/*######
## npc_nesingwary_trapper
######*/

enum NesingwaryTrapper
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
        npc_nesingwary_trapperAI(Creature* creature) : ScriptedAI(creature) { creature->SetVisible(false); }

        uint64 go_caribouGUID;
        uint8  phase;
        uint32 phaseTimer;

        void Reset() OVERRIDE
        {
            me->SetVisible(false);
            phaseTimer = 2500;
            phase = 1;
            go_caribouGUID = 0;
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE { }
        void MoveInLineOfSight(Unit* /*who*/) OVERRIDE { }


        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            if (GameObject* go_caribou = me->GetMap()->GetGameObject(go_caribouGUID))
                go_caribou->SetLootState(GO_JUST_DEACTIVATED);

            if (TempSummon* summon = me->ToTempSummon())
                if (summon->IsSummon())
                    if (Unit* temp = summon->GetSummoner())
                        if (Player* player = temp->ToPlayer())
                            player->KilledMonsterCredit(me->GetEntry(), 0);

            if (GameObject* go_caribou = me->GetMap()->GetGameObject(go_caribouGUID))
                go_caribou->SetGoState(GO_STATE_READY);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (phaseTimer <= diff)
            {
                switch (phase)
                {
                    case 1:
                        me->SetVisible(true);
                        phaseTimer = 2000;
                        phase = 2;
                        break;
                    case 2:
                        if (GameObject* go_fur = me->FindNearestGameObject(GO_HIGH_QUALITY_FUR, 11.0f))
                            me->GetMotionMaster()->MovePoint(0, go_fur->GetPositionX(), go_fur->GetPositionY(), go_fur->GetPositionZ());
                        phaseTimer = 1500;
                        phase = 3;
                        break;
                    case 3:
                        //Talk(SAY_NESINGWARY_1);
                        phaseTimer = 2000;
                        phase = 4;
                        break;
                    case 4:
                        me->HandleEmoteCommand(EMOTE_ONESHOT_LOOT);
                        phaseTimer = 1000;
                        phase = 5;
                        break;
                    case 5:
                        me->HandleEmoteCommand(EMOTE_ONESHOT_NONE);
                        phaseTimer = 500;
                        phase = 6;
                        break;
                    case 6:
                        if (GameObject* go_fur = me->FindNearestGameObject(GO_HIGH_QUALITY_FUR, 11.0f))
                            go_fur->Delete();
                        phaseTimer = 500;
                        phase = 7;
                        break;
                    case 7:
                    {
                        GameObject* go_caribou = NULL;
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
                        phase = 8;
                        phaseTimer = 1000;
                    }
                    break;
                    case 8:
                        DoCast(me, SPELL_TRAPPED, true);
                        phase = 0;
                        break;
                }
            } else phaseTimer -= diff;
        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_nesingwary_trapperAI(creature);
    }
};

/*######
## npc_lurgglbr
######*/

enum Lurgglbr
{
    QUEST_ESCAPE_WINTERFIN_CAVERNS      = 11570,

    GO_CAGE                             = 187369,

    FACTION_ESCORTEE_A                  = 774,
    FACTION_ESCORTEE_H                  = 775,

    SAY_START_1                         = 0,
    SAY_START_2                         = 1,
    SAY_END_1                           = 2,
    SAY_END_2                           = 3
};

class npc_lurgglbr : public CreatureScript
{
public:
    npc_lurgglbr() : CreatureScript("npc_lurgglbr") { }

    struct npc_lurgglbrAI : public npc_escortAI
    {
        npc_lurgglbrAI(Creature* creature) : npc_escortAI(creature){ }

        uint32 IntroTimer;
        uint32 IntroPhase;

        void Reset() OVERRIDE
        {
            if (!HasEscortState(STATE_ESCORT_ESCORTING))
            {
                IntroTimer = 0;
                IntroPhase = 0;
            }
        }

        void WaypointReached(uint32 waypointId) OVERRIDE
        {
            switch (waypointId)
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

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (IntroPhase)
            {
                if (IntroTimer <= diff)
                {
                    switch (IntroPhase)
                    {
                        case 1:
                            Talk(SAY_START_1);
                            IntroPhase = 2;
                            IntroTimer = 7500;
                            break;
                        case 2:
                            Talk(SAY_END_1);
                            IntroPhase = 3;
                            IntroTimer = 7500;
                            break;
                        case 3:
                            me->SetReactState(REACT_AGGRESSIVE);
                            IntroPhase = 0;
                            IntroTimer = 0;
                            break;
                        case 4:
                            Talk(SAY_START_2);
                            IntroPhase = 5;
                            IntroTimer = 8000;
                            break;
                        case 5:
                            Talk(SAY_END_2);
                            IntroPhase = 6;
                            IntroTimer = 2500;
                            break;

                        case 6:
                            if (Player* player = GetPlayerForEscort())
                                player->AreaExploredOrEventHappens(QUEST_ESCAPE_WINTERFIN_CAVERNS);
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

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_lurgglbrAI(creature);
    }

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest) OVERRIDE
    {
        if (quest->GetQuestId() == QUEST_ESCAPE_WINTERFIN_CAVERNS)
        {
            if (GameObject* go = creature->FindNearestGameObject(GO_CAGE, 5.0f))
            {
                go->SetRespawnTime(0);
                go->SetGoType(GAMEOBJECT_TYPE_BUTTON);
                go->UseDoorOrButton(20);
            }

            if (npc_escortAI* pEscortAI = CAST_AI(npc_lurgglbr::npc_lurgglbrAI, creature->AI()))
                pEscortAI->Start(true, false, player->GetGUID());

            switch (player->GetTeam())
            {
                case ALLIANCE:
                    creature->setFaction(FACTION_ESCORTEE_A);
                    break;
                default:
                case HORDE:
                    creature->setFaction(FACTION_ESCORTEE_H);
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

enum NexusDrakeHatchling
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
        npc_nexus_drake_hatchlingAI(Creature* creature) : FollowerAI(creature)
        {
            HarpoonerGUID = 0;
        }

        uint64 HarpoonerGUID;
        bool WithRedDragonBlood;

        void Reset() OVERRIDE
        {
           WithRedDragonBlood = false;
        }

        void EnterCombat(Unit* who) OVERRIDE
        {
            if (me->IsValidAttackTarget(who))
                AttackStart(who);
        }

        void SpellHit(Unit* caster, const SpellInfo* spell) OVERRIDE
        {
            if (spell->Id == SPELL_DRAKE_HARPOON && caster->GetTypeId() == TYPEID_PLAYER)
            {
                HarpoonerGUID = caster->GetGUID();
                DoCast(me, SPELL_RED_DRAGONBLOOD, true);
            }
            WithRedDragonBlood = true;
        }

        void MoveInLineOfSight(Unit* who) OVERRIDE

        {
            FollowerAI::MoveInLineOfSight(who);

            if (!HarpoonerGUID)
                return;

            if (me->HasAura(SPELL_SUBDUED) && who->GetEntry() == NPC_RAELORASZ)
            {
                if (me->IsWithinDistInMap(who, INTERACTION_DISTANCE))
                {
                    if (Player* pHarpooner = ObjectAccessor::GetPlayer(*me, HarpoonerGUID))
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

        void UpdateAI(uint32 /*diff*/) OVERRIDE
        {
            if (WithRedDragonBlood && HarpoonerGUID && !me->HasAura(SPELL_RED_DRAGONBLOOD))
            {
                if (Player* pHarpooner = ObjectAccessor::GetPlayer(*me, HarpoonerGUID))
                {
                    EnterEvadeMode();
                    StartFollow(pHarpooner, 35, NULL);

                    DoCast(me, SPELL_SUBDUED, true);
                    pHarpooner->CastSpell(pHarpooner, SPELL_DRAKE_HATCHLING_SUBDUED, true);

                    me->AttackStop();
                    WithRedDragonBlood = false;
                }
            }

            if ((me->getFaction() == 35) && (!me->HasAura(SPELL_SUBDUED)))
            {
                HarpoonerGUID = 0;
                me->DisappearAndDie();
            }

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_nexus_drake_hatchlingAI(creature);
    }
};

/*######
## npc_thassarian
######*/

enum Thassarian
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

    SAY_THASSARIAN_1        = 0,
    SAY_THASSARIAN_2        = 1,
    SAY_THASSARIAN_3        = 2,
    SAY_THASSARIAN_4        = 3,
    SAY_THASSARIAN_5        = 4,
    SAY_THASSARIAN_6        = 5,
    SAY_THASSARIAN_7        = 6,

    SAY_TALBOT_1            = 0,
    SAY_TALBOT_2            = 1,
    SAY_TALBOT_3            = 2,
    SAY_TALBOT_4            = 3,

    SAY_LICH_1              = 0,
    SAY_LICH_2              = 1,
    SAY_LICH_3              = 2,

    SAY_ARLOS_1             = 0,
    SAY_ARLOS_2             = 1,

    SAY_LERYSSA_1           = 0,
    SAY_LERYSSA_2           = 1,
    SAY_LERYSSA_3           = 2,
    SAY_LERYSSA_4           = 3
};

#define GOSSIP_ITEM_T   "Let's do this, Thassarian. It's now or never."

class npc_thassarian : public CreatureScript
{
public:
    npc_thassarian() : CreatureScript("npc_thassarian") { }

    struct npc_thassarianAI : public npc_escortAI
    {
        npc_thassarianAI(Creature* creature) : npc_escortAI(creature) { }

        uint64 arthasGUID;
        uint64 talbotGUID;
        uint64 leryssaGUID;
        uint64 arlosGUID;

        bool arthasInPosition;
        bool arlosInPosition;
        bool leryssaInPosition;
        bool talbotInPosition;

        uint32 phase;
        uint32 phaseTimer;

        void Reset() OVERRIDE
        {
            me->RestoreFaction();
            me->RemoveStandFlags(UNIT_STAND_STATE_SIT);

            arthasGUID = 0;
            talbotGUID = 0;
            leryssaGUID = 0;
            arlosGUID = 0;

            arthasInPosition = false;
            arlosInPosition = false;
            leryssaInPosition = false;
            talbotInPosition = false;

            phase = 0;
            phaseTimer = 0;
        }

        void WaypointReached(uint32 waypointId) OVERRIDE
        {
            Player* player = GetPlayerForEscort();
            if (!player)
                return;

            switch (waypointId)
            {
                case 3:
                    SetEscortPaused(true);
                    if (Creature* arthas = me->SummonCreature(NPC_IMAGE_LICH_KING, 3730.313f, 3518.689f, 473.324f, 1.562f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 120000))
                    {
                        arthasGUID = arthas->GetGUID();
                        arthas->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        arthas->SetReactState(REACT_PASSIVE);
                        arthas->SetWalk(true);
                        arthas->GetMotionMaster()->MovePoint(0, 3737.374756f, 3564.841309f, 477.433014f);
                    }
                    if (Creature* talbot = me->SummonCreature(NPC_COUNSELOR_TALBOT, 3747.23f, 3614.936f, 473.321f, 4.462012f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 120000))
                    {
                        talbotGUID = talbot->GetGUID();
                        talbot->SetWalk(true);
                        talbot->GetMotionMaster()->MovePoint(0, 3738.000977f, 3568.882080f, 477.433014f);
                    }
                    me->SetWalk(false);
                    break;
                case 4:
                    SetEscortPaused(true);
                    phase = 7;
                    break;
            }
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            npc_escortAI::UpdateAI(diff);

            if (arthasInPosition && talbotInPosition)
            {
                phase = 1;
                arthasInPosition = false;
                talbotInPosition = false;
            }

            if (arlosInPosition && leryssaInPosition)
            {
                arlosInPosition   = false;
                leryssaInPosition = false;
                Talk(SAY_THASSARIAN_1);
                SetEscortPaused(false);
            }

            if (phaseTimer <= diff)
            {
                Creature* talbot = me->GetCreature(*me, talbotGUID);
                Creature* arthas = me->GetCreature(*me, arthasGUID);
                switch (phase)
                {
                    case 1:
                        if (talbot)
                            talbot->SetStandState(UNIT_STAND_STATE_KNEEL);
                        phaseTimer = 3000;
                        ++phase;
                        break;

                    case 2:
                        if (talbot)
                        {
                            talbot->UpdateEntry(NPC_PRINCE_VALANAR, ALLIANCE);
                            talbot->setFaction(14);
                            talbot->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            talbot->SetReactState(REACT_PASSIVE);
                        }
                        phaseTimer = 5000;
                        ++phase;
                        break;

                    case 3:
                        if (talbot)
                            talbot->AI()->Talk(SAY_TALBOT_1);
                        phaseTimer = 5000;
                        ++phase;
                        break;

                    case 4:
                        if (arthas)
                            arthas->AI()->Talk(SAY_LICH_1);
                        phaseTimer = 5000;
                        ++phase;
                        break;

                    case 5:
                        if (talbot)
                            talbot->AI()->Talk(SAY_TALBOT_2);
                        phaseTimer = 5000;
                        ++phase;
                        break;

                    case 6:
                        if (Creature* arlos = me->SummonCreature(NPC_GENERAL_ARLOS, 3745.527100f, 3615.655029f, 473.321533f, 4.447805f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 120000))
                        {
                            arlosGUID = arlos->GetGUID();
                            arlos->SetWalk(true);
                            arlos->GetMotionMaster()->MovePoint(0, 3735.570068f, 3572.419922f, 477.441010f);
                        }
                        if (Creature* leryssa = me->SummonCreature(NPC_LERYSSA, 3749.654541f, 3614.959717f, 473.323486f, 4.524959f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 120000))
                        {
                            leryssaGUID = leryssa->GetGUID();
                            leryssa->SetWalk(false);
                            leryssa->SetReactState(REACT_PASSIVE);
                            leryssa->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            leryssa->GetMotionMaster()->MovePoint(0, 3741.969971f, 3571.439941f, 477.441010f);
                        }
                        phaseTimer = 2000;
                        phase = 0;
                        break;

                    case 7:
                        Talk(SAY_THASSARIAN_2);
                        phaseTimer = 5000;
                        ++phase;
                        break;

                    case 8:
                        if (arthas && talbot)
                        {
                            arthas->SetInFront(me); //The client doesen't update with the new orientation :l
                            talbot->SetStandState(UNIT_STAND_STATE_STAND);
                            arthas->AI()->Talk(SAY_LICH_2);
                        }
                        phaseTimer = 5000;
                        phase = 9;
                        break;

                   case 9:
                        Talk(SAY_THASSARIAN_3);
                        phaseTimer = 5000;
                        phase = 10;
                        break;

                   case 10:
                        if (talbot)
                            talbot->AI()->Talk(SAY_TALBOT_3);
                        phaseTimer = 5000;
                        phase = 11;
                        break;

                   case 11:
                        if (arthas)
                            arthas->AI()->Talk(SAY_LICH_3);
                        phaseTimer = 5000;
                        phase = 12;
                        break;

                    case 12:
                        if (talbot)
                            talbot->AI()->Talk(SAY_TALBOT_4);
                        phaseTimer = 2000;
                        phase = 13;
                        break;

                    case 13:
                        if (arthas)
                            arthas->RemoveFromWorld();
                        ++phase;
                        break;

                    case 14:
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        if (talbot)
                        {
                            talbot->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            talbot->SetReactState(REACT_AGGRESSIVE);
                            talbot->CastSpell(me, SPELL_SHADOW_BOLT, false);
                        }
                        phaseTimer = 1500;
                        ++phase;
                        break;

                    case 15:
                        me->SetReactState(REACT_AGGRESSIVE);
                        AttackStart(talbot);
                        phase = 0;
                        break;

                    case 16:
                        me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                        phaseTimer = 20000;
                        ++phase;
                        break;

                   case 17:
                        if (Creature* leryssa = me->GetCreature(*me, leryssaGUID))
                            leryssa->RemoveFromWorld();
                        if (Creature* arlos= me->GetCreature(*me, arlosGUID))
                            arlos->RemoveFromWorld();
                        if (talbot)
                            talbot->RemoveFromWorld();
                        me->RemoveStandFlags(UNIT_STAND_STATE_SIT);
                        SetEscortPaused(false);
                        phaseTimer = 0;
                        phase = 0;
                }
            } else phaseTimer -= diff;

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            if (Creature* talbot = me->GetCreature(*me, talbotGUID))
                talbot->RemoveFromWorld();

            if (Creature* leryssa = me->GetCreature(*me, leryssaGUID))
                leryssa->RemoveFromWorld();

            if (Creature* arlos = me->GetCreature(*me, arlosGUID))
                arlos->RemoveFromWorld();

            if (Creature* arthas = me->GetCreature(*me, arthasGUID))
                arthas->RemoveFromWorld();
        }
    };

    bool OnGossipHello(Player* player, Creature* creature) OVERRIDE
    {
        if (creature->IsQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        if (player->GetQuestStatus(QUEST_LAST_RITES) == QUEST_STATUS_INCOMPLETE && creature->GetAreaId() == 4128)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_T, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) OVERRIDE
    {
        player->PlayerTalkClass->ClearMenus();
        switch (action)
        {
            case GOSSIP_ACTION_INFO_DEF+1:
                CAST_AI(npc_escortAI, (creature->AI()))->Start(true, false, player->GetGUID());
                CAST_AI(npc_escortAI, (creature->AI()))->SetMaxPlayerDistance(200.0f);
                break;
        }
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
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
        npc_image_lich_kingAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() OVERRIDE
        {
            me->RestoreFaction();
        }

        void MovementInform(uint32 uiType, uint32 /*uiId*/) OVERRIDE
        {
            if (uiType != POINT_MOTION_TYPE)
                return;

            if (me->IsSummon())
                if (Unit* summoner = me->ToTempSummon()->GetSummoner())
                    CAST_AI(npc_thassarian::npc_thassarianAI, summoner->ToCreature()->AI())->arthasInPosition = true;
        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
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
        npc_general_arlosAI(Creature* creature) : ScriptedAI(creature) { }

        void MovementInform(uint32 uiType, uint32 /*uiId*/) OVERRIDE
        {
            if (uiType != POINT_MOTION_TYPE)
                return;

            me->AddUnitState(UNIT_STATE_STUNNED);
            me->CastSpell(me, SPELL_STUN, true);
            if (me->IsSummon())
                if (Unit* summoner = me->ToTempSummon()->GetSummoner())
                    CAST_AI(npc_thassarian::npc_thassarianAI, summoner->ToCreature()->AI())->arlosInPosition = true;
        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_general_arlosAI(creature);
    }
};

/*######
## npc_counselor_talbot
######*/

enum CounselorTalbot
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
        npc_counselor_talbotAI(Creature* creature) : ScriptedAI(creature) { }

        uint64 leryssaGUID;
        uint64 arlosGUID;

        bool bCheck;

        uint32 shadowBoltTimer;
        uint32 deflectionTimer;
        uint32 soulBlastTimer;

        void Reset() OVERRIDE
        {
            leryssaGUID         = 0;
            arlosGUID           = 0;
            bCheck              = false;
            shadowBoltTimer   = urand(5000, 12000);
            deflectionTimer   = urand(20000, 25000);
            soulBlastTimer    = urand(12000, 18000);
        }
        void MovementInform(uint32 uiType, uint32 /*uiId*/) OVERRIDE
        {
            if (uiType != POINT_MOTION_TYPE)
                return;

            if (me->IsSummon())
                if (Unit* summoner = me->ToTempSummon()->GetSummoner())
                    CAST_AI(npc_thassarian::npc_thassarianAI, summoner->ToCreature()->AI())->talbotInPosition = true;
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (bCheck)
            {
                if (Creature* leryssa = me->FindNearestCreature(NPC_LERYSSA, 50.0f, true))
                    leryssaGUID = leryssa->GetGUID();
                if (Creature* arlos = me->FindNearestCreature(NPC_GENERAL_ARLOS, 50.0f, true))
                    arlosGUID = arlos->GetGUID();
                bCheck = false;
            }

            if (!UpdateVictim())
                return;

            if (me->GetAreaId() == 4125)
            {
                if (shadowBoltTimer <= diff)
                {
                    DoCastVictim(SPELL_SHADOW_BOLT);
                    shadowBoltTimer = urand(5000, 12000);
                } else shadowBoltTimer -= diff;

                if (deflectionTimer <= diff)
                {
                    DoCastVictim(SPELL_DEFLECTION);
                    deflectionTimer = urand(20000, 25000);
                } else deflectionTimer -= diff;

                if (soulBlastTimer <= diff)
                {
                    DoCastVictim(SPELL_SOUL_BLAST);
                    soulBlastTimer  = urand(12000, 18000);
                } else soulBlastTimer -= diff;
            }

            DoMeleeAttackIfReady();
       }

       void JustDied(Unit* killer) OVERRIDE
       {
            if (!leryssaGUID || !arlosGUID)
                return;

            Creature* leryssa = Unit::GetCreature(*me, leryssaGUID);
            Creature* arlos = Unit::GetCreature(*me, arlosGUID);
            if (!leryssa || !arlos)
                return;

            arlos->AI()->Talk(SAY_ARLOS_1);
            arlos->AI()->Talk(SAY_ARLOS_2);
            leryssa->AI()->Talk(SAY_LERYSSA_1);
            arlos->Kill(arlos, false);
            leryssa->RemoveAura(SPELL_STUN);
            leryssa->ClearUnitState(UNIT_STATE_STUNNED);
            leryssa->SetWalk(false);
            leryssa->GetMotionMaster()->MovePoint(0, 3722.114502f, 3564.201660f, 477.441437f);

            if (Player* player = killer->ToPlayer())
                player->RewardPlayerAndGroupAtEvent(NPC_PRINCE_VALANAR, 0);
        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
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
        npc_leryssaAI(Creature* creature) : ScriptedAI(creature)
        {
            bDone = false;
            phase = 0;
            phaseTimer = 0;

            creature->RemoveStandFlags(UNIT_STAND_STATE_SIT);
        }

        bool bDone;

        uint32 phase;
        uint32 phaseTimer;

        void MovementInform(uint32 type, uint32 /*uiId*/) OVERRIDE
        {
            if (type != POINT_MOTION_TYPE)
                return;

            if (!bDone)
            {
                if (Creature* talbot = me->FindNearestCreature(NPC_PRINCE_VALANAR, 50.0f, true))
                    CAST_AI(npc_counselor_talbot::npc_counselor_talbotAI, talbot->GetAI())->bCheck = true;

                me->AddUnitState(UNIT_STATE_STUNNED);
                me->CastSpell(me, SPELL_STUN, true);

                if (me->IsSummon())
                    if (Unit* summoner = me->ToTempSummon()->GetSummoner())
                        CAST_AI(npc_thassarian::npc_thassarianAI, summoner->GetAI())->leryssaInPosition = true;
                bDone = true;
            }
            else
            {
                me->SetStandState(UNIT_STAND_STATE_SIT);
                if (me->IsSummon())
                    if (Unit* summoner = me->ToTempSummon()->GetSummoner())
                    summoner->SetStandState(UNIT_STAND_STATE_SIT);
                phaseTimer = 1500;
                phase = 1;
            }
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            ScriptedAI::UpdateAI(diff);

            if (phaseTimer <= diff)
            {
                switch (phase)
                {
                    case 1:
                        if (me->IsSummon())
                            if (Unit* summoner = me->ToTempSummon()->GetSummoner())
                                if (Creature* thassarian = summoner->ToCreature())
                                    thassarian->AI()->Talk(SAY_THASSARIAN_4);
                        phaseTimer = 5000;
                        ++phase;
                        break;
                    case 2:
                        Talk(SAY_LERYSSA_2);
                        phaseTimer = 5000;
                        ++phase;
                        break;
                    case 3:
                        if (me->IsSummon())
                            if (Unit* summoner = me->ToTempSummon()->GetSummoner())
                                if (Creature* thassarian = summoner->ToCreature())
                                    thassarian->AI()->Talk(SAY_THASSARIAN_5);
                        phaseTimer = 5000;
                        ++phase;
                        break;
                    case 4:
                        Talk(SAY_LERYSSA_3);
                        phaseTimer = 5000;
                        ++phase;
                        break;
                    case 5:
                        if (me->IsSummon())
                            if (Unit* summoner = me->ToTempSummon()->GetSummoner())
                                if (Creature* thassarian = summoner->ToCreature())
                                    thassarian->AI()->Talk(SAY_THASSARIAN_6);
                        phaseTimer = 5000;
                        ++phase;
                        break;

                    case 6:
                        Talk(SAY_LERYSSA_4);
                        phaseTimer = 5000;
                        ++phase;
                        break;
                    case 7:
                        if (me->IsSummon())
                            if (Unit* summoner = me->ToTempSummon()->GetSummoner())
                                if (Creature* thassarian = summoner->ToCreature())
                                {
                                    thassarian->AI()->Talk(SAY_THASSARIAN_7);
                                    CAST_AI(npc_thassarian::npc_thassarianAI, thassarian->GetAI())->phase = 16;
                                }
                        phaseTimer = 5000;
                        phase = 0;
                        break;
                }
            } else phaseTimer -= diff;

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_leryssaAI(creature);
    }
};

/*######
## npc_beryl_sorcerer
######*/

enum BerylSorcerer
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
        npc_beryl_sorcererAI(Creature* creature) : FollowerAI(creature) { }

        bool bEnslaved;

        void Reset() OVERRIDE
        {
            me->SetReactState(REACT_AGGRESSIVE);
            bEnslaved = false;
        }

        void EnterCombat(Unit* who) OVERRIDE
        {
            if (me->IsValidAttackTarget(who))
                AttackStart(who);
        }

        void SpellHit(Unit* pCaster, const SpellInfo* pSpell) OVERRIDE
        {
            if (pSpell->Id == SPELL_ARCANE_CHAINS && pCaster->GetTypeId() == TYPEID_PLAYER && !HealthAbovePct(50) && !bEnslaved)
            {
                EnterEvadeMode(); //We make sure that the npc is not attacking the player!
                me->SetReactState(REACT_PASSIVE);
                StartFollow(pCaster->ToPlayer(), 0, NULL);
                me->UpdateEntry(NPC_CAPTURED_BERLY_SORCERER, TEAM_NEUTRAL);
                DoCast(me, SPELL_COSMETIC_ENSLAVE_CHAINS_SELF, true);

                if (Player* player = pCaster->ToPlayer())
                    player->KilledMonsterCredit(NPC_CAPTURED_BERLY_SORCERER, 0);

                bEnslaved = true;
            }
        }

        void MoveInLineOfSight(Unit* who) OVERRIDE

        {
            FollowerAI::MoveInLineOfSight(who);

            if (who->GetEntry() == NPC_LIBRARIAN_DONATHAN && me->IsWithinDistInMap(who, INTERACTION_DISTANCE))
            {
                SetFollowComplete();
                me->DisappearAndDie();
            }
        }

        void UpdateAI(uint32 /*diff*/) OVERRIDE
        {
            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_beryl_sorcererAI(creature);
    }
};

/*######
## npc_imprisoned_beryl_sorcerer
######*/
enum ImprisionedBerylSorcerer
{
    SPELL_NEURAL_NEEDLE             = 45634,

    NPC_IMPRISONED_BERYL_SORCERER   = 25478,

    SAY_IMPRISIONED_BERYL_1         = 0,
    SAY_IMPRISIONED_BERYL_2         = 1,
    SAY_IMPRISIONED_BERYL_3         = 2,
    SAY_IMPRISIONED_BERYL_4         = 3,
    SAY_IMPRISIONED_BERYL_5         = 4,
    SAY_IMPRISIONED_BERYL_6         = 5,
    SAY_IMPRISIONED_BERYL_7         = 6
};

class npc_imprisoned_beryl_sorcerer : public CreatureScript
{
public:
    npc_imprisoned_beryl_sorcerer() : CreatureScript("npc_imprisoned_beryl_sorcerer") { }

    struct npc_imprisoned_beryl_sorcererAI : public ScriptedAI
    {
        npc_imprisoned_beryl_sorcererAI(Creature* creature) : ScriptedAI(creature) { }

        uint32 rebuff;

        void Reset() OVERRIDE
        {
            if (me->GetReactState() != REACT_PASSIVE)
                me->SetReactState(REACT_PASSIVE);

            rebuff = 0;
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            UpdateVictim();

            if (rebuff <= diff)
            {
                if (!me->HasAura(SPELL_COSMETIC_ENSLAVE_CHAINS_SELF))
                {
                    DoCast(me, SPELL_COSMETIC_ENSLAVE_CHAINS_SELF);
                }
                rebuff = 180000;
            }
            else
                rebuff -= diff;

            DoMeleeAttackIfReady();
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
        }

        void SpellHit(Unit* unit, const SpellInfo* spell) OVERRIDE
        {
            if (spell->Id == SPELL_NEURAL_NEEDLE && unit->GetTypeId() == TYPEID_PLAYER)
            {
                if (Player* player = unit->ToPlayer())
                {
                    GotStinged(player->GetGUID());
                }
            }
        }

        void GotStinged(uint64 casterGUID)
        {
            if (Player* caster = ObjectAccessor::GetPlayer(*me, casterGUID))
            {
                uint32 step = caster->GetAuraCount(SPELL_NEURAL_NEEDLE) + 1;
                switch (step)
                {
                    case 1:
                        Talk(SAY_IMPRISIONED_BERYL_1);
                        break;
                    case 2:
                        Talk(SAY_IMPRISIONED_BERYL_2, caster);
                        break;
                    case 3:
                        Talk(SAY_IMPRISIONED_BERYL_3);
                        break;
                    case 4:
                        Talk(SAY_IMPRISIONED_BERYL_4);
                        break;
                    case 5:
                        Talk(SAY_IMPRISIONED_BERYL_5);
                        break;
                    case 6:
                        Talk(SAY_IMPRISIONED_BERYL_6, caster);
                        break;
                    case 7:
                        Talk(SAY_IMPRISIONED_BERYL_7);
                        caster->KilledMonsterCredit(NPC_IMPRISONED_BERYL_SORCERER, 0);
                        break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_imprisoned_beryl_sorcererAI(creature);
    }
};

/*######
## npc_mootoo_the_younger
######*/
enum MootooTheYounger
{
    SAY_1                       = 0,
    SAY_2                       = 1,
    SAY_3                       = 2,
    SAY_4                       = 3,
    SAY_5                       = 4,

    NPC_MOOTOO_THE_YOUNGER      = 25504,
    QUEST_ESCAPING_THE_MIST     = 11664
};

class npc_mootoo_the_younger : public CreatureScript
{
public:
    npc_mootoo_the_younger() : CreatureScript("npc_mootoo_the_younger") { }

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest) OVERRIDE
    {
        if (quest->GetQuestId() == QUEST_ESCAPING_THE_MIST)
        {
            switch (player->GetTeam())
            {
            case ALLIANCE:
                creature->setFaction(FACTION_ESCORTEE_A);
                break;
            case HORDE:
                creature->setFaction(FACTION_ESCORTEE_H);
                break;
            }
            creature->SetStandState(UNIT_STAND_STATE_STAND);
            creature->AI()->Talk(SAY_1);
            CAST_AI(npc_escortAI, (creature->AI()))->Start(true, false, player->GetGUID());
        }
        return true;
    }

    struct npc_mootoo_the_youngerAI : public npc_escortAI
    {
        npc_mootoo_the_youngerAI(Creature* creature) : npc_escortAI(creature) { }

        void Reset() OVERRIDE
        {
            SetDespawnAtFar(false);
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            if (Player* player=GetPlayerForEscort())
                player->FailQuest(QUEST_ESCAPING_THE_MIST);
        }

        void WaypointReached(uint32 waypointId) OVERRIDE
        {
            Player* player = GetPlayerForEscort();
            if (!player)
                return;

            switch (waypointId)
            {
                case 10:
                    me->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
                    Talk(SAY_2);
                    break;
                case 12:
                    Talk(SAY_3);
                    me->HandleEmoteCommand(EMOTE_ONESHOT_LOOT);
                    break;
                case 16:
                    Talk(SAY_4);
                    me->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
                    break;
                case 20:
                    me->SetPhaseMask(1, true);
                    Talk(SAY_5);
                    me->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
                    player->GroupEventHappens(QUEST_ESCAPING_THE_MIST, me);
                    SetRun(true);
                    break;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_mootoo_the_youngerAI(creature);
    }
};

/*######
## npc_bonker_togglevolt
######*/

enum BonkerTogglevolt
{
    NPC_BONKER_TOGGLEVOLT   = 25589,
    QUEST_GET_ME_OUTA_HERE  = 11673,

    SAY_BONKER_1            = 0,
    SAY_BONKER_2            = 1
};

class npc_bonker_togglevolt : public CreatureScript
{
public:
    npc_bonker_togglevolt() : CreatureScript("npc_bonker_togglevolt") { }

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest) OVERRIDE
    {
        if (quest->GetQuestId() == QUEST_GET_ME_OUTA_HERE)
        {
            creature->SetStandState(UNIT_STAND_STATE_STAND);
            creature->AI()->Talk(SAY_BONKER_2, player);
            CAST_AI(npc_escortAI, (creature->AI()))->Start(true, true, player->GetGUID());
        }
        return true;
    }

    struct npc_bonker_togglevoltAI : public npc_escortAI
    {
        npc_bonker_togglevoltAI(Creature* creature) : npc_escortAI(creature) { }
        uint32 Bonker_agro;

        void Reset() OVERRIDE
        {
            Bonker_agro=0;
            SetDespawnAtFar(false);
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            if (Player* player = GetPlayerForEscort())
                player->FailQuest(QUEST_GET_ME_OUTA_HERE);
        }

        void UpdateEscortAI(const uint32 /*diff*/) OVERRIDE
        {
            if (GetAttack() && UpdateVictim())
            {
                if (Bonker_agro == 0)
                {
                    Talk(SAY_BONKER_1);
                    Bonker_agro++;
                }
                DoMeleeAttackIfReady();
            }
            else Bonker_agro=0;
        }

        void WaypointReached(uint32 waypointId) OVERRIDE
        {
            Player* player = GetPlayerForEscort();
            if (!player)
                return;

            switch (waypointId)
            {
                case 29:
                    player->GroupEventHappens(QUEST_GET_ME_OUTA_HERE, me);
                    break;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_bonker_togglevoltAI(creature);
    }
};

/*######
## Help Those That Cannot Help Themselves, Quest 11876
######*/

enum HelpThemselves
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
        npc_trapped_mammoth_calfAI(Creature* creature) : ScriptedAI(creature) { }

        uint32 uiTimer;
        bool bStarted;

        void Reset() OVERRIDE
        {
            uiTimer = 1500;
            bStarted = false;

            GameObject* pTrap = NULL;
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

        void UpdateAI(uint32 diff) OVERRIDE
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

        void DoAction(int32 param) OVERRIDE
        {
            if (param == 1)
                bStarted = true;
        }

        void MovementInform(uint32 uiType, uint32 /*uiId*/) OVERRIDE
        {
            if (uiType != POINT_MOTION_TYPE)
                return;

            me->DisappearAndDie();

            GameObject* pTrap = NULL;
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

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_trapped_mammoth_calfAI(creature);
    }
};

/*######
## Quest 11653: Hah... You're Not So Big Now!
######*/

enum NotSoBig
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
        npc_magmoth_crusherAI(Creature* creature) : ScriptedAI(creature) { }

        void JustDied(Unit* killer) OVERRIDE
        {
            Player* player = killer->ToPlayer();
            if (!player)
                return;

            if (player->GetQuestStatus(QUEST_YOU_RE_NOT_SO_BIG_NOW) == QUEST_STATUS_INCOMPLETE &&
                (me->HasAura(SPELL_AURA_NOTSOBIG_1) || me->HasAura(SPELL_AURA_NOTSOBIG_2) ||
                me->HasAura(SPELL_AURA_NOTSOBIG_3) || me->HasAura(SPELL_AURA_NOTSOBIG_4)))
            {
                Quest const* qInfo = sObjectMgr->GetQuestTemplate(QUEST_YOU_RE_NOT_SO_BIG_NOW);
                if (qInfo)
                    player->KilledMonsterCredit(qInfo->RequiredNpcOrGo[0], 0);
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_magmoth_crusherAI(creature);
    }
};

/*######
## Quest 11608: Bury Those Cockroaches!
######*/

enum BuryThoseCockroaches
{
    // Quest
    QUEST_BURY_THOSE_COCKROACHES            = 11608,

    // Spells
    SPELL_SEAFORIUM_DEPTH_CHARGE_EXPLOSION  = 45502

};

class npc_seaforium_depth_charge : public CreatureScript
{
public:
    npc_seaforium_depth_charge() : CreatureScript("npc_seaforium_depth_charge") { }

    struct npc_seaforium_depth_chargeAI : public ScriptedAI
    {
        npc_seaforium_depth_chargeAI(Creature* creature) : ScriptedAI(creature) { }

        uint32 uiExplosionTimer;

        void Reset() OVERRIDE
        {
            uiExplosionTimer = urand(5000, 10000);
        }

        void UpdateAI(uint32 diff) OVERRIDE
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
                            Player* owner = uOwner->ToPlayer();
                            if (owner && owner->GetQuestStatus(QUEST_BURY_THOSE_COCKROACHES) == QUEST_STATUS_INCOMPLETE)
                                owner->KilledMonsterCredit(cCredit->GetEntry(), cCredit->GetGUID());
                        }
                    }
                }
                me->Kill(me);
                return;
            } else uiExplosionTimer -= diff;
        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_seaforium_depth_chargeAI(creature);
    }
};

/*######
## Help Those That Cannot Help Themselves, Quest 11876
######*/

enum Valiancekeepcannons
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
        npc_valiance_keep_cannoneerAI(Creature* creature) : ScriptedAI(creature) { }

        uint32 uiTimer;

        void Reset() OVERRIDE
        {
            uiTimer = urand(13000, 18000);
        }

        void UpdateAI(uint32 diff) OVERRIDE
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

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
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

    struct npc_warmage_coldarraAI : public ScriptedAI
    {
        npc_warmage_coldarraAI(Creature* creature) : ScriptedAI(creature) { }

        uint32 m_uiTimer;                 //Timer until recast

        void Reset() OVERRIDE
        {
            m_uiTimer = 0;
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE { }

        void AttackStart(Unit* /*who*/) OVERRIDE { }

        void UpdateAI(uint32 uiDiff) OVERRIDE
        {
            if (m_uiTimer <= uiDiff)
            {
                std::list<Creature*> orbList;
                GetCreatureListWithEntryInGrid(orbList, me, NPC_TRANSITUS_SHIELD_DUMMY, 32.0f);

                switch (me->GetEntry())
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

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_warmage_coldarraAI(creature);
    }
};

/*######
## npc_hidden_cultist
######*/

enum HiddenCultist
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

    SAY_HIDDEN_CULTIST_1                        = 0,
    SAY_HIDDEN_CULTIST_2                        = 1,
    SAY_HIDDEN_CULTIST_3                        = 2,
    SAY_HIDDEN_CULTIST_4                        = 3
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
        npc_hidden_cultistAI(Creature* creature) : ScriptedAI(creature)
        {
           uiEmoteState = creature->GetUInt32Value(UNIT_NPC_EMOTESTATE);
           uiNpcFlags = creature->GetUInt32Value(UNIT_NPC_FLAGS);
        }

        uint32 uiEmoteState;
        uint32 uiNpcFlags;

        uint32 uiEventTimer;
        uint8 uiEventPhase;

        uint64 uiPlayerGUID;

        void Reset() OVERRIDE
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

        void DoAction(int32 /*iParam*/) OVERRIDE
        {
            me->StopMoving();
            me->SetUInt32Value(UNIT_NPC_FLAGS, 0);
            if (Player* player = ObjectAccessor::GetPlayer(*me, uiPlayerGUID))
                me->SetFacingToObject(player);
            uiEventTimer = 3000;
            uiEventPhase = 1;
        }

        void SetGUID(uint64 uiGuid, int32 /*iId*/) OVERRIDE
        {
            uiPlayerGUID = uiGuid;
        }

        void AttackPlayer()
        {
            me->setFaction(14);
            if (Player* player = ObjectAccessor::GetPlayer(*me, uiPlayerGUID))
                me->AI()->AttackStart(player);
        }

        void UpdateAI(uint32 uiDiff) OVERRIDE
        {
            if (uiEventTimer && uiEventTimer <= uiDiff)
            {
                switch (uiEventPhase)
                {
                    case 1:
                        switch (me->GetEntry())
                        {
                            case NPC_SALTY_JOHN_THORPE:
                                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);
                                Talk(SAY_HIDDEN_CULTIST_1);
                                uiEventTimer = 5000;
                                uiEventPhase = 2;
                                break;
                            case NPC_GUARD_MITCHELLS:
                                Talk(SAY_HIDDEN_CULTIST_2);
                                uiEventTimer = 5000;
                                uiEventPhase = 2;
                                break;
                            case NPC_TOM_HEGGER:
                                Talk(SAY_HIDDEN_CULTIST_3);
                                uiEventTimer = 5000;
                                uiEventPhase = 2;
                                break;
                        }
                        break;
                    case 2:
                        switch (me->GetEntry())
                        {
                            case NPC_SALTY_JOHN_THORPE:
                                Talk(SAY_HIDDEN_CULTIST_4);
                                if (Player* player = ObjectAccessor::GetPlayer(*me, uiPlayerGUID))
                                    me->SetFacingToObject(player);
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

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_hidden_cultistAI(creature);
    }

    bool OnGossipHello(Player* player, Creature* creature) OVERRIDE
    {
        uint32 uiGossipText = 0;
        const char* charGossipItem;

        switch (creature->GetEntry())
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

        if (player->HasAura(SPELL_RIGHTEOUS_VISION) && player->GetQuestStatus(QUEST_THE_HUNT_IS_ON) == QUEST_STATUS_INCOMPLETE)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, charGossipItem, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        if (creature->IsVendor())
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);

        player->SEND_GOSSIP_MENU(uiGossipText, creature->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) OVERRIDE
    {
        player->PlayerTalkClass->ClearMenus();

        if (action == GOSSIP_ACTION_INFO_DEF+1)
        {
            player->CLOSE_GOSSIP_MENU();
            creature->AI()->SetGUID(player->GetGUID());
            creature->AI()->DoAction(1);
        }

        if (action == GOSSIP_ACTION_TRADE)
            player->GetSession()->SendListInventory(creature->GetGUID());

        return true;
    }

};

enum WindsoulTotemAura
{
    SPELL_WINDSOUL_CREDT = 46378
};

class spell_windsoul_totem_aura : public SpellScriptLoader
{
public:
    spell_windsoul_totem_aura() : SpellScriptLoader("spell_windsoul_totem_aura") { }

    class spell_windsoul_totem_aura_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_windsoul_totem_aura_AuraScript);

        void OnRemove(AuraEffect const*, AuraEffectHandleModes)
        {
            if (GetTarget()->isDead())
                if (Unit* caster = GetCaster())
                    caster->CastSpell(NULL, SPELL_WINDSOUL_CREDT);
        }

        void Register() OVERRIDE
        {
            OnEffectRemove += AuraEffectRemoveFn(spell_windsoul_totem_aura_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const OVERRIDE
    {
        return new spell_windsoul_totem_aura_AuraScript();
    }
};

void AddSC_borean_tundra()
{
    new npc_sinkhole_kill_credit();
    new npc_khunok_the_behemoth();
    new npc_keristrasza();
    new npc_corastrasza();
    new npc_iruk();
    new npc_nerubar_victim();
    new npc_jenny();
    new npc_fezzix_geartwist();
    new npc_nesingwary_trapper();
    new npc_lurgglbr();
    new npc_nexus_drake_hatchling();
    new npc_thassarian();
    new npc_image_lich_king();
    new npc_counselor_talbot();
    new npc_leryssa();
    new npc_general_arlos();
    new npc_beryl_sorcerer();
    new npc_imprisoned_beryl_sorcerer();
    new npc_mootoo_the_younger();
    new npc_bonker_togglevolt();
    new npc_trapped_mammoth_calf();
    new npc_magmoth_crusher();
    new npc_seaforium_depth_charge();
    new npc_valiance_keep_cannoneer();
    new npc_warmage_coldarra();
    new npc_hidden_cultist();
    new spell_windsoul_totem_aura();
}
