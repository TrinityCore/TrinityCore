/*
 * Copyright (C) 2017-2019 AshamaneProject <https://github.com/AshamaneProject>
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
#include "GameObject.h"
#include "SpellAuras.h"
#include "ScriptedGossip.h"
#include "ScriptedCreature.h"
#include "karazhan_legion.h"

constexpr uint32 SPELL_MEDIVH_ECHO          = 229074;
constexpr uint32 SPELL_MEDIVH_PRESSENCE     = 229077;
constexpr uint32 NIGHTBANE_ACHIEVEMENT      = 11430;

enum Actions
{
    ACTION_SUMMON_NIGHTBANE                 = 1,
    ACTION_REPLY_ARCHANAGOS                 = 2,
    ACTION_REPLY_2_ARCHANAGOS               = 3,
    ACTION_REPLY_3_ARCHANAGOS               = 4
};

class npc_kara_image_of_medivh : public CreatureScript
{
    public:
        npc_kara_image_of_medivh() : CreatureScript("npc_kara_image_of_medivh") { }

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            if (!player || !creature)
                return false;

            player->PrepareGossipMenu(creature, creature->GetCreatureTemplate()->GossipMenuId, false);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Summon Nightbane", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
            return true;
        }

        bool OnGossipSelect(Player* player, Creature* me, uint32 /*sender*/, uint32 action) override
        {
            ClearGossipMenuFor(player);
            CloseGossipMenuFor(player);

            if (me->GetInstanceScript()->GetData(DATA_NIGHTBANE_TIMER) == 2)
            {
                Aura* echo = player->GetAura(SPELL_MEDIVH_PRESSENCE);
                if (echo)
                    me->GetAI()->DoAction(ACTION_SUMMON_NIGHTBANE);
            }

            return true;
        }

        struct npc_kara_image_of_medivh_AI : public ScriptedAI
        {
            explicit npc_kara_image_of_medivh_AI(Creature* me) : ScriptedAI(me) { }

            void Reset()
            {
                if (me->GetInstanceScript()->GetData(DATA_NIGHTBANE_EVENT) == DONE)
                    _intro = true;
            }
            void DoAction(int32 action) override
            {
                if (action == ACTION_SUMMON_NIGHTBANE)
                {
                    if (_intro)
                        return;

                    _intro = true;
                    Creature* nightbane = me->FindNearestCreature(BOSS_NIGHTBANE, 250.f, true);

                    if (nightbane)
                        nightbane->GetAI()->DoAction(1); // Action NightBane Ready

                    me->GetInstanceScript()->SetData(DATA_NIGHTBANE_EVENT, DONE);

                    const auto & players = me->GetMap()->GetPlayers();
                    for (auto & it : players)
                    {
                        if (Player* ptr = it.GetSource())
                        {
                            if (AchievementEntry const* achievementEntry = sAchievementStore.LookupEntry(NIGHTBANE_ACHIEVEMENT))
                                ptr->CompletedAchievement(achievementEntry);
                        }
                    }
                    me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                }
            }

            private:
                bool _intro;
        };

        CreatureAI* GetAI(Creature* me) const override
        {
            return new npc_kara_image_of_medivh_AI(me);
        }
};

class go_door_entrance : public GameObjectScript
{
    public:
        go_door_entrance() : GameObjectScript("go_door_entrance") { }

        bool OnGossipHello(Player* /*player*/, GameObject* go) override
        {
            if (!go)
                return false;

            if (go->GetInstanceScript()->GetData(DATA_NIGHTBANE_EVENT) == NOT_STARTED)
                go->GetInstanceScript()->SetData(DATA_NIGHTBANE_EVENT, IN_PROGRESS);

            if (go->GetGoState() == GO_STATE_ACTIVE)
                go->SetGoState(GO_STATE_READY);
            else
                go->SetGoState(GO_STATE_ACTIVE);

            return true;
        }
};

class npc_kara_soul_fragment : public CreatureScript
{
    public:
        npc_kara_soul_fragment() : CreatureScript("npc_kara_soul_fragment") { }

        struct npc_kara_soul_fragment_AI : public ScriptedAI
        {
            explicit npc_kara_soul_fragment_AI(Creature* me) : ScriptedAI(me) { }

            void OnSpellClick(Unit* /*clicker*/, bool& /*result*/)
            {
                for (auto & it : me->GetMap()->GetPlayers())
                {
                    if (Player* player = it.GetSource())
                    {
                        if (Aura* echo = player->GetAura(SPELL_MEDIVH_ECHO))
                        {
                            if (echo->GetStackAmount() == 4)
                                player->CastSpell(player, SPELL_MEDIVH_PRESSENCE, true);
                            else
                            {
                                echo->ModStackAmount(1);
                                echo->SetDuration(echo->GetDuration() + echo->GetMaxDuration());
                            }
                        }
                        else
                            DoCast(player, SPELL_MEDIVH_ECHO, true);
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* me) const override
        {
            return new npc_kara_soul_fragment_AI(me);
        }
};

void AddSC_karazhan_legion()
{
    new npc_kara_image_of_medivh();
    new npc_kara_soul_fragment();
    new go_door_entrance();
};
