/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
SDName: Zulaman
SD%Complete: 90
SDComment: Forest Frog will turn into different NPC's. Workaround to prevent new entry from running this script
SDCategory: Zul'Aman
EndScriptData */

/* ContentData
npc_forest_frog
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
## npc_forest_frog
######*/

enum ForestFrog
{
    // Spells
    SPELL_REMOVE_AMANI_CURSE   = 43732,
    SPELL_PUSH_MOJO            = 43923,

    // Creatures
    NPC_FOREST_FROG             = 24396

};

class npc_forest_frog : public CreatureScript
{
    public:

        npc_forest_frog() : CreatureScript("npc_forest_frog") { }

        struct npc_forest_frogAI : public ScriptedAI
        {
            npc_forest_frogAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;

            void Reset() override { }

            void JustEngagedWith(Unit* /*who*/) override { }

            void DoSpawnRandom() const
            {
                uint32 cEntry = RAND(
                    24397,     //Mannuth
                    24403,     //Deez
                    24404,     //Galathryn
                    24405,     //Adarrah
                    24406,     //Fudgerick
                    24407,     //Darwen
                    24445,     //Mitzi
                    24448,     //Christian
                    24453,     //Brennan
                    24455);    //Hollee

                if (!instance->GetData(TYPE_RAND_VENDOR_1))
                {
                    if (roll_chance_i(10))
                    {
                        cEntry = 24408;      //Gunter
                        instance->SetData(TYPE_RAND_VENDOR_1, DONE);
                    }
                }
                else if (!instance->GetData(TYPE_RAND_VENDOR_2))
                {
                    if (roll_chance_i(10))
                    {
                        cEntry = 24409;      //Kyren
                        instance->SetData(TYPE_RAND_VENDOR_2, DONE);
                    }
                }

                me->UpdateEntry(cEntry);
            }

            void SpellHit(Unit* caster, SpellInfo const* spell) override
            {
                if (spell->Id == SPELL_REMOVE_AMANI_CURSE && caster->GetTypeId() == TYPEID_PLAYER && me->GetEntry() == NPC_FOREST_FROG)
                {
                    //increase or decrease chance of mojo?
                    if (roll_chance_i(1))
                        DoCast(caster, SPELL_PUSH_MOJO, true);
                    else
                        DoSpawnRandom();
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetZulAmanAI<npc_forest_frogAI>(creature);
        }
};

/*######
## npc_zulaman_hostage
######*/

#define GOSSIP_HOSTAGE1        "I am glad to help you."

static uint32 const HostageEntry[] = {23790, 23999, 24024, 24001};
static uint32 const ChestEntry[] = {186648, 187021, 186672, 186667};

class npc_zulaman_hostage : public CreatureScript
{
    public:
        npc_zulaman_hostage() : CreatureScript("npc_zulaman_hostage") { }

        struct npc_zulaman_hostageAI : public ScriptedAI
        {
            npc_zulaman_hostageAI(Creature* creature) : ScriptedAI(creature), instance(creature->GetInstanceScript()) { }

            InstanceScript* instance;

            bool GossipHello(Player* player) override
            {
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_HOSTAGE1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());
                return true;
            }

            bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
            {
                uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
                ClearGossipMenuFor(player);

                if (action == GOSSIP_ACTION_INFO_DEF + 1)
                    CloseGossipMenuFor(player);

                if (!me->HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP))
                    return true;

                me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

                //uint8 progress = instance->GetData(DATA_CHESTLOOTED);
                instance->SetData(DATA_CHESTLOOTED, 0);
                float x, y, z;
                me->GetPosition(x, y, z);
                uint32 entry = me->GetEntry();
                for (uint8 i = 0; i < 4; ++i)
                {
                    if (HostageEntry[i] == entry)
                    {
                        me->SummonGameObject(ChestEntry[i], Position(x - 2, y, z, 0.f), QuaternionData(), 0);
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

            bool GossipSelect(Player* player, uint32 menuId, uint32 gossipListId) override
            {
               if (me->GetCreatureTemplate()->GossipMenuId == menuId && !gossipListId)
               {
                    CloseGossipMenuFor(player);
                    me->SetFacingToObject(player);
                    me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    Talk(SAY_HARRISON_0);
                    _gongEvent = GONG_EVENT_1;
                    _gongTimer = 4000;
               }
               return false;
            }

            void SpellHit(Unit*, SpellInfo const* spell) override
            {
                if (spell->Id == SPELL_COSMETIC_SPEAR_THROW)
                {
                    me->RemoveAllAuras();
                    me->SetEntry(NPC_HARRISON_JONES_2);
                    me->SetDisplayId(MODEL_HARRISON_JONES_2);
                    me->SetTarget(ObjectGuid::Empty);
                    me->SetByteValue(UNIT_FIELD_BYTES_1, 0, UNIT_STAND_STATE_DEAD);
                    me->SetFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_DEAD);
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
                                me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 0, uint32(WEAPON_MACE));
                                me->SetSheath(SHEATH_STATE_MELEE);
                                _gongEvent = GONG_EVENT_3;
                                _gongTimer = 4000;
                                break;
                            case GONG_EVENT_3:
                                if (GameObject* gong = instance->GetGameObject(GO_STRANGE_GONG))
                                    gong->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                                _gongEvent = GONG_EVENT_4;
                                _gongTimer = 105000;
                                break;
                            case GONG_EVENT_4:
                                me->RemoveAura(SPELL_BANGING_THE_GONG);
                                if (GameObject* gong = instance->GetGameObject(GO_STRANGE_GONG))
                                    gong->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);

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
                                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_USE_STANDING);
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
                                        target->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 0, uint32(WEAPON_SPEAR));
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
                                me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 0, uint32(0));
                                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE);
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
                                me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

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

class spell_banging_the_gong : public SpellScriptLoader
{
    public:
        spell_banging_the_gong() : SpellScriptLoader("spell_banging_the_gong") { }

        class spell_banging_the_gong_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_banging_the_gong_SpellScript);

            void Activate(SpellEffIndex index)
            {
                PreventHitDefaultEffect(index);
                GetHitGObj()->SendCustomAnim(0);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_banging_the_gong_SpellScript::Activate, EFFECT_1, SPELL_EFFECT_ACTIVATE_OBJECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_banging_the_gong_SpellScript();
        }
};


void AddSC_zulaman()
{
    new npc_forest_frog();
    new npc_zulaman_hostage();
    new npc_harrison_jones();
    new spell_banging_the_gong();
}
