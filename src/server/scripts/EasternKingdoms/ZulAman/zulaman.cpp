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
SDName: Zulaman
SD%Complete: 90
SDComment: Forest Frog will turn into different NPC's. Workaround to prevent new entry from running this script
SDCategory: Zul'Aman
EndScriptData */

/* ContentData
EndContentData */

#include "ScriptMgr.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "zulaman.h"

/*######
## npc_zulaman_hostage
######*/

static uint32 const HostageEntry[] = {23790, 23999, 24024, 24001};
static uint32 const ChestEntry[] = {186648, 187021, 186672, 186667};

enum Npcs
{
    NPC_TANZAR                = 23790,
    NPC_HARKOR                = 23999,
    NPC_ASHLI                 = 24001,
    NPC_KRAZ                  = 24024
};

enum Gossips
{
    GOSSIP_MENU_TANZAR        = 8799,
    GOSSIP_MENU_HARKOR        = 8874,
    GOSSIP_MENU_ASHLI         = 8927,
    GOSSIP_MENU_KRAZ          = 8881,
    GOSSIP_OPTION_HOSTAGE     = 0
};

class npc_zulaman_hostage : public CreatureScript
{
    public:
        npc_zulaman_hostage() : CreatureScript("npc_zulaman_hostage") { }

        struct npc_zulaman_hostageAI : public ScriptedAI
        {
            npc_zulaman_hostageAI(Creature* creature) : ScriptedAI(creature), instance(creature->GetInstanceScript()) { }

            InstanceScript* instance;

            bool OnGossipHello(Player* player) override
            {
                switch (me->GetEntry())
                {
                    case NPC_TANZAR:
                        InitGossipMenuFor(player, GOSSIP_MENU_TANZAR);
                        AddGossipItemFor(player, GOSSIP_MENU_TANZAR, GOSSIP_OPTION_HOSTAGE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                        break;
                    case NPC_HARKOR:
                        InitGossipMenuFor(player, GOSSIP_MENU_HARKOR);
                        AddGossipItemFor(player, GOSSIP_MENU_HARKOR, GOSSIP_OPTION_HOSTAGE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                        break;
                    case NPC_ASHLI:
                        InitGossipMenuFor(player, GOSSIP_MENU_ASHLI);
                        AddGossipItemFor(player, GOSSIP_MENU_ASHLI, GOSSIP_OPTION_HOSTAGE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                        break;
                    case NPC_KRAZ:
                        InitGossipMenuFor(player, GOSSIP_MENU_KRAZ);
                        AddGossipItemFor(player, GOSSIP_MENU_KRAZ, GOSSIP_OPTION_HOSTAGE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                        break;
                }
                SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());
                return true;
            }

            bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
            {
                uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
                ClearGossipMenuFor(player);

                if (action == GOSSIP_ACTION_INFO_DEF + 1)
                    CloseGossipMenuFor(player);

                if (!me->HasNpcFlag(UNIT_NPC_FLAG_GOSSIP))
                    return true;

                me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);

                //uint8 progress = instance->GetData(DATA_CHESTLOOTED);
                instance->SetData(DATA_CHESTLOOTED, 0);
                float x, y, z;
                me->GetPosition(x, y, z);
                uint32 entry = me->GetEntry();
                for (uint8 i = 0; i < 4; ++i)
                {
                    if (HostageEntry[i] == entry)
                    {
                        me->SummonGameObject(ChestEntry[i], Position(x - 2, y, z, 0.f), QuaternionData(), 0s);
                        break;
                    }
                }
                return true;
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetZulAmanAI<npc_zulaman_hostageAI>(creature);
        }
};

/*######
## npc_harrison_jones
######*/

enum Says
{
    SAY_HARRISON_0                    = 0,
    SAY_HARRISON_1                    = 1,
    SAY_HARRISON_2                    = 0,
    SAY_HARRISON_3                    = 1
};

enum Spells
{
    SPELL_BANGING_THE_GONG            = 45225,
    SPELL_STEALTH                     = 34189,
    SPELL_COSMETIC_SPEAR_THROW        = 43647
};

enum Events
{
    GONG_EVENT_1                      = 1,
    GONG_EVENT_2                      = 2,
    GONG_EVENT_3                      = 3,
    GONG_EVENT_4                      = 4,
    GONG_EVENT_5                      = 5,
    GONG_EVENT_6                      = 6,
    GONG_EVENT_7                      = 7,
    GONG_EVENT_8                      = 8,
    GONG_EVENT_9                      = 9,
    GONG_EVENT_10                     = 10,
    GONG_EVENT_11                     = 11
};

enum Waypoints
{
    HARRISON_MOVE_1                   = 860440,
    HARRISON_MOVE_2                   = 860441,
    HARRISON_MOVE_3                   = 860442
};

enum DisplayIds
{
    MODEL_HARRISON_JONES_0              = 22340,
    MODEL_HARRISON_JONES_1              = 22354,
    MODEL_HARRISON_JONES_2              = 22347
};

enum EntryIds
{
    NPC_HARRISON_JONES_1                = 24375,
    NPC_HARRISON_JONES_2                = 24365,
    NPC_AMANISHI_GUARDIAN               = 23597,
};

enum Weapons
{
    WEAPON_MACE                         = 5301,
    WEAPON_SPEAR                        = 13631
};

class npc_harrison_jones : public CreatureScript
{
    public:

        npc_harrison_jones() : CreatureScript("npc_harrison_jones") { }

        struct npc_harrison_jonesAI : public ScriptedAI
        {
            npc_harrison_jonesAI(Creature* creature) : ScriptedAI(creature)
            {
                Initialize();
                instance = creature->GetInstanceScript();
            }

            void Initialize()
            {
                _gongEvent = 0;
                _gongTimer = 0;
            }

            InstanceScript* instance;

            uint8 _gongEvent;
            uint32 _gongTimer;

            void Reset() override
            {
                Initialize();
            }

            void JustEngagedWith(Unit* /*who*/) override { }

            bool OnGossipSelect(Player* player, uint32 menuId, uint32 gossipListId) override
            {
               if (me->GetCreatureTemplate()->GossipMenuId == menuId && !gossipListId)
               {
                    CloseGossipMenuFor(player);
                    me->SetFacingToObject(player);
                    me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                    Talk(SAY_HARRISON_0);
                    _gongEvent = GONG_EVENT_1;
                    _gongTimer = 4000;
               }
               return false;
            }

            void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
            {
                if (spellInfo->Id == SPELL_COSMETIC_SPEAR_THROW)
                {
                    me->RemoveAllAuras();
                    me->SetEntry(NPC_HARRISON_JONES_2);
                    me->SetDisplayId(MODEL_HARRISON_JONES_2);
                    me->SetTarget(ObjectGuid::Empty);
                    me->SetStandState(UNIT_STAND_STATE_DEAD);
                    me->SetDynamicFlag(UNIT_DYNFLAG_DEAD);
                    instance->SetData(DATA_GONGEVENT, DONE);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (_gongEvent)
                {
                    if (_gongTimer <= diff)
                    {
                        switch (_gongEvent)
                        {
                            case GONG_EVENT_1:
                                me->GetMotionMaster()->MovePath(HARRISON_MOVE_1, false);
                                _gongEvent = GONG_EVENT_2;
                                _gongTimer = 12000;
                                break;
                            case GONG_EVENT_2:
                                me->SetFacingTo(6.235659f);
                                Talk(SAY_HARRISON_1);
                                DoCast(me, SPELL_BANGING_THE_GONG);
                                me->SetVirtualItem(0, uint32(WEAPON_MACE));
                                me->SetSheath(SHEATH_STATE_MELEE);
                                _gongEvent = GONG_EVENT_3;
                                _gongTimer = 4000;
                                break;
                            case GONG_EVENT_3:
                                if (GameObject* gong = instance->GetGameObject(GO_STRANGE_GONG))
                                    gong->RemoveFlag(GO_FLAG_NOT_SELECTABLE);
                                _gongEvent = GONG_EVENT_4;
                                _gongTimer = 105000;
                                break;
                            case GONG_EVENT_4:
                                me->RemoveAura(SPELL_BANGING_THE_GONG);
                                if (GameObject* gong = instance->GetGameObject(GO_STRANGE_GONG))
                                    gong->SetFlag(GO_FLAG_NOT_SELECTABLE);

                                // trigger or gong will need to be scripted to set IN_PROGRESS after enough hits.
                                // This is temp workaround.
                                instance->SetData(DATA_GONGEVENT, IN_PROGRESS); // to be removed.

                                if (instance->GetData(DATA_GONGEVENT) == IN_PROGRESS)
                                {
                                    // Players are Now Saved to instance at SPECIAL (Player should be notified?)
                                    me->GetMotionMaster()->MovePath(HARRISON_MOVE_2, false);
                                    _gongEvent = GONG_EVENT_5;
                                    _gongTimer = 5000;
                                }
                                else
                                {
                                    _gongTimer = 1000;
                                    _gongEvent = GONG_EVENT_9;
                                }
                                break;
                            case GONG_EVENT_5:
                                me->SetEntry(NPC_HARRISON_JONES_1);
                                me->SetDisplayId(MODEL_HARRISON_JONES_1);
                                Talk(SAY_HARRISON_2);
                                _gongTimer = 12000;
                                _gongEvent = GONG_EVENT_6;
                                break;
                            case GONG_EVENT_6:
                                me->SetEmoteState(EMOTE_STATE_USE_STANDING);
                                Talk(SAY_HARRISON_3);
                                _gongTimer = 7000;
                                _gongEvent = GONG_EVENT_7;
                                break;
                            case GONG_EVENT_7:
                            {
                                std::vector<Creature*> targetList;
                                GetCreatureListWithEntryInGrid(targetList, me, NPC_AMANISHI_GUARDIAN, 26.0f);
                                for (Creature* target : targetList)
                                {
                                    if (target->GetPositionX() > 120)
                                    {
                                        target->SetVirtualItem(0, uint32(WEAPON_SPEAR));
                                        target->SetImmuneToPC(true);
                                        target->SetReactState(REACT_PASSIVE);
                                        target->AI()->SetData(0, 1);
                                    }
                                    else
                                    {
                                        target->SetImmuneToPC(true);
                                        target->SetReactState(REACT_PASSIVE);
                                        target->AI()->SetData(0, 2);
                                    }
                                }

                                if (GameObject* gate = instance->GetGameObject(GO_MASSIVE_GATE))
                                    gate->SetGoState(GO_STATE_ACTIVE);
                                _gongTimer = 2000;
                                _gongEvent = GONG_EVENT_8;
                                break;
                            }
                            case GONG_EVENT_8:
                                DoCast(me, SPELL_STEALTH);
                                me->SetVirtualItem(0, uint32(0));
                                me->SetEmoteState(EMOTE_ONESHOT_NONE);
                                me->GetMotionMaster()->MovePath(HARRISON_MOVE_3, false);
                                _gongTimer = 1000;
                                _gongEvent = 0;
                                break;
                            case GONG_EVENT_9:
                                me->GetMotionMaster()->MovePoint(0, 120.687f, 1674.0f, 42.0217f);
                                _gongTimer = 12000;
                                _gongEvent = GONG_EVENT_10;
                                break;
                            case GONG_EVENT_10:
                                me->SetFacingTo(1.59044f);
                                _gongEvent = 11;
                                _gongTimer = 6000;
                                break;
                            case GONG_EVENT_11:
                                me->SetNpcFlag(UNIT_NPC_FLAG_GOSSIP);

                                instance->SetData(DATA_GONGEVENT, NOT_STARTED);
                                _gongEvent = 0;
                                _gongTimer = 1000;
                                break;
                        }
                    }
                    else
                        _gongTimer -= diff;
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetZulAmanAI<npc_harrison_jonesAI>(creature);
        }
};

void AddSC_zulaman()
{
    new npc_zulaman_hostage();
    new npc_harrison_jones();
}
