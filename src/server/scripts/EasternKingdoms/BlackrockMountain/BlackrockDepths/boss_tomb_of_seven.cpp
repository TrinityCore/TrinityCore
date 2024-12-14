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

#include "ScriptMgr.h"
#include "blackrock_depths.h"
#include "InstanceScript.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"

enum Spells
{
    SPELL_SMELT_DARK_IRON       = 14891,
    SPELL_LEARN_SMELT           = 14894,
};

enum Quests
{
    QUEST_SPECTRAL_CHALICE      = 4083
};

enum Misc
{
    DATA_SKILLPOINT_MIN         = 230
};

enum Phases
{
    PHASE_ONE                   = 1,
    PHASE_TWO                   = 2
};

#define GOSSIP_ITEM_TEACH_1 "Teach me the art of smelting dark iron"
#define GOSSIP_ITEM_TEACH_2 "Continue..."
#define GOSSIP_ITEM_TEACH_3 "[PH] Continue..."
#define GOSSIP_ITEM_TRIBUTE "I want to pay tribute"

class boss_gloomrel : public CreatureScript
{
    public:
        boss_gloomrel() : CreatureScript("boss_gloomrel") { }

        struct boss_gloomrelAI : public ScriptedAI
        {
            boss_gloomrelAI(Creature* creature) : ScriptedAI(creature), instance(creature->GetInstanceScript()) { }

            InstanceScript* instance;

            bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
            {
                uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
                ClearGossipMenuFor(player);
                switch (action)
                {
                    case GOSSIP_ACTION_INFO_DEF + 1:
                        AddGossipItemFor(player, GossipOptionNpc::None, GOSSIP_ITEM_TEACH_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11);
                        SendGossipMenuFor(player, 2606, me->GetGUID());
                        break;
                    case GOSSIP_ACTION_INFO_DEF + 11:
                        CloseGossipMenuFor(player);
                        player->CastSpell(player, SPELL_LEARN_SMELT, false);
                        break;
                    case GOSSIP_ACTION_INFO_DEF + 2:
                        AddGossipItemFor(player, GossipOptionNpc::None, GOSSIP_ITEM_TEACH_3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 22);
                        SendGossipMenuFor(player, 2604, me->GetGUID());
                        break;
                    case GOSSIP_ACTION_INFO_DEF + 22:
                        CloseGossipMenuFor(player);
                        //are 5 minutes expected? go template may have data to despawn when used at quest
                        instance->DoRespawnGameObject(instance->GetGuidData(DATA_GO_CHALICE), 5min);
                        break;
                }
                return true;
            }

            bool OnGossipHello(Player* player) override
            {
                if (player->GetQuestRewardStatus(QUEST_SPECTRAL_CHALICE) == 1 && player->GetSkillValue(SKILL_MINING) >= DATA_SKILLPOINT_MIN && !player->HasSpell(SPELL_SMELT_DARK_IRON))
                    AddGossipItemFor(player, GossipOptionNpc::None, GOSSIP_ITEM_TEACH_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

                if (player->GetQuestRewardStatus(QUEST_SPECTRAL_CHALICE) == 0 && player->GetSkillValue(SKILL_MINING) >= DATA_SKILLPOINT_MIN)
                    AddGossipItemFor(player, GossipOptionNpc::None, GOSSIP_ITEM_TRIBUTE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);

                SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());
                return true;
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetBlackrockDepthsAI<boss_gloomrelAI>(creature);
        }
};

enum DoomrelSpells
{
    SPELL_SHADOWBOLTVOLLEY                                 = 15245,
    SPELL_IMMOLATE                                         = 12742,
    SPELL_CURSEOFWEAKNESS                                  = 12493,
    SPELL_DEMONARMOR                                       = 13787,
    SPELL_SUMMON_VOIDWALKERS                               = 15092
};
enum DoomrelText
{
    GOSSIP_SELECT_DOOMREL                                  = 1828,
    GOSSIP_MENU_ID_CONTINUE                                = 1,

    GOSSIP_MENU_CHALLENGE                                  = 1947,
    GOSSIP_MENU_ID_CHALLENGE                               = 0
};
enum DoomrelEvents
{
    EVENT_SHADOW_BOLT_VOLLEY                               = 1,
    EVENT_IMMOLATE                                         = 2,
    EVENT_CURSE_OF_WEAKNESS                                = 3,
    EVENT_DEMONARMOR                                       = 4,
    EVENT_SUMMON_VOIDWALKERS                               = 5
};

class boss_doomrel : public CreatureScript
{
    public:
        boss_doomrel() : CreatureScript("boss_doomrel") { }

        struct boss_doomrelAI : public ScriptedAI
        {
            boss_doomrelAI(Creature* creature) : ScriptedAI(creature)
            {
                Initialize();
                _instance = creature->GetInstanceScript();
            }

            void Initialize()
            {
                _voidwalkers = false;
            }

            void Reset() override
            {
                Initialize();

                me->SetFaction(FACTION_FRIENDLY);

                // was set before event start, so set again
                me->SetImmuneToPC(true);

                if (_instance->GetData(DATA_GHOSTKILL) >= 7)
                    me->ReplaceAllNpcFlags(UNIT_NPC_FLAG_NONE);
                else
                    me->ReplaceAllNpcFlags(UNIT_NPC_FLAG_GOSSIP);
            }

            void JustEngagedWith(Unit* /*who*/) override
            {
                _events.ScheduleEvent(EVENT_SHADOW_BOLT_VOLLEY, 10s);
                _events.ScheduleEvent(EVENT_IMMOLATE, 18s);
                _events.ScheduleEvent(EVENT_CURSE_OF_WEAKNESS, 5s);
                _events.ScheduleEvent(EVENT_DEMONARMOR, 16s);
            }

            void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
            {
                if (!_voidwalkers && !HealthAbovePct(50))
                {
                    DoCastVictim(SPELL_SUMMON_VOIDWALKERS, true);
                    _voidwalkers = true;
                }
            }

            void EnterEvadeMode(EvadeReason why) override
            {
                ScriptedAI::EnterEvadeMode(why);

                _instance->SetGuidData(DATA_EVENSTARTER, ObjectGuid::Empty);
            }

            void JustDied(Unit* /*killer*/) override
            {
                _instance->SetData(DATA_GHOSTKILL, 1);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SHADOW_BOLT_VOLLEY:
                            DoCastVictim(SPELL_SHADOWBOLTVOLLEY);
                            _events.ScheduleEvent(EVENT_SHADOW_BOLT_VOLLEY, 12s);
                            break;
                        case EVENT_IMMOLATE:
                            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100.0f, true))
                                DoCast(target, SPELL_IMMOLATE);
                            _events.ScheduleEvent(EVENT_IMMOLATE, 25s);
                            break;
                        case EVENT_CURSE_OF_WEAKNESS:
                            DoCastVictim(SPELL_CURSEOFWEAKNESS);
                            _events.ScheduleEvent(EVENT_CURSE_OF_WEAKNESS, 45s);
                            break;
                        case EVENT_DEMONARMOR:
                            DoCast(me, SPELL_DEMONARMOR);
                            _events.ScheduleEvent(EVENT_DEMONARMOR, 5min);
                            break;
                        default:
                            break;
                    }
                }
            }

            bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
            {
                uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
                ClearGossipMenuFor(player);

                switch (action)
                {
                    case GOSSIP_ACTION_INFO_DEF + 1:
                        InitGossipMenuFor(player, GOSSIP_SELECT_DOOMREL);
                        AddGossipItemFor(player, GOSSIP_SELECT_DOOMREL, GOSSIP_MENU_ID_CONTINUE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                        SendGossipMenuFor(player, 2605, me->GetGUID());
                        break;
                    case GOSSIP_ACTION_INFO_DEF + 2:
                        CloseGossipMenuFor(player);
                        //start event here
                        me->SetFaction(FACTION_DARK_IRON_DWARVES);
                        me->SetImmuneToPC(false);
                        me->AI()->AttackStart(player);

                        _instance->SetGuidData(DATA_EVENSTARTER, player->GetGUID());
                        break;
                }
                return true;
            }

            bool OnGossipHello(Player* player) override
            {
                InitGossipMenuFor(player, GOSSIP_MENU_CHALLENGE);
                AddGossipItemFor(player, GOSSIP_MENU_CHALLENGE, GOSSIP_MENU_ID_CHALLENGE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                SendGossipMenuFor(player, 2601, me->GetGUID());

                return true;
            }

        private:
            InstanceScript* _instance;
            EventMap _events;
            bool _voidwalkers;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetBlackrockDepthsAI<boss_doomrelAI>(creature);
        }
};

void AddSC_boss_tomb_of_seven()
{
    new boss_gloomrel();
    new boss_doomrel();
}
