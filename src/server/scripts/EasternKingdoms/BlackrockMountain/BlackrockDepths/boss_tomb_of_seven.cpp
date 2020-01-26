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

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        ClearGossipMenuFor(player);
        switch (action)
        {
            case GOSSIP_ACTION_INFO_DEF+1:
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_ITEM_TEACH_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11);
                SendGossipMenuFor(player, 2606, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+11:
                CloseGossipMenuFor(player);
                player->CastSpell(player, SPELL_LEARN_SMELT, false);
                break;
            case GOSSIP_ACTION_INFO_DEF+2:
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_ITEM_TEACH_3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 22);
                SendGossipMenuFor(player, 2604, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+22:
                CloseGossipMenuFor(player);
                if (InstanceScript* instance = creature->GetInstanceScript())
                {
                    //are 5 minutes expected? go template may have data to despawn when used at quest
                    instance->DoRespawnGameObject(instance->GetGuidData(DATA_GO_CHALICE), MINUTE*5);
                }
                break;
        }
        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (player->GetQuestRewardStatus(QUEST_SPECTRAL_CHALICE) == 1 && player->GetSkillValue(SKILL_MINING) >= DATA_SKILLPOINT_MIN && !player->HasSpell(SPELL_SMELT_DARK_IRON))
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_ITEM_TEACH_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

        if (player->GetQuestRewardStatus(QUEST_SPECTRAL_CHALICE) == 0 && player->GetSkillValue(SKILL_MINING) >= DATA_SKILLPOINT_MIN)
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_ITEM_TRIBUTE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);

        SendGossipMenuFor(player, player->GetGossipTextId(creature), creature->GetGUID());
        return true;
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

enum DoomrelEvents
{
    EVENT_SHADOW_BOLT_VOLLEY                               = 1,
    EVENT_IMMOLATE                                         = 2,
    EVENT_CURSE_OF_WEAKNESS                                = 3,
    EVENT_DEMONARMOR                                       = 4,
    EVENT_SUMMON_VOIDWALKERS                               = 5
};

#define GOSSIP_ITEM_CHALLENGE   "Your bondage is at an end, Doom'rel. I challenge you!"
#define GOSSIP_SELECT_DOOMREL   "[PH] Continue..."

class boss_doomrel : public CreatureScript
{
    public:
        boss_doomrel() : CreatureScript("boss_doomrel") { }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
        {
            ClearGossipMenuFor(player);
            switch (action)
            {
                case GOSSIP_ACTION_INFO_DEF+1:
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_SELECT_DOOMREL, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                    SendGossipMenuFor(player, 2605, creature->GetGUID());
                    break;
                case GOSSIP_ACTION_INFO_DEF+2:
                    CloseGossipMenuFor(player);
                    //start event here
                    creature->setFaction(FACTION_HOSTILE);
                    creature->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                    creature->AI()->AttackStart(player);
                    InstanceScript* instance = creature->GetInstanceScript();
                    if (instance)
                        instance->SetGuidData(DATA_EVENSTARTER, player->GetGUID());
                    break;
            }
            return true;
        }

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_ITEM_CHALLENGE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            SendGossipMenuFor(player, 2601, creature->GetGUID());

            return true;
        }

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

                me->setFaction(FACTION_FRIEND);

                // was set before event start, so set again
                me->AddUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);

                if (_instance->GetData(DATA_GHOSTKILL) >= 7)
                    me->SetNpcFlags(UNIT_NPC_FLAG_NONE);
                else
                    me->SetNpcFlags(UNIT_NPC_FLAG_GOSSIP);
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _events.ScheduleEvent(EVENT_SHADOW_BOLT_VOLLEY, 10000);
                _events.ScheduleEvent(EVENT_IMMOLATE, 18000);
                _events.ScheduleEvent(EVENT_CURSE_OF_WEAKNESS, 5000);
                _events.ScheduleEvent(EVENT_DEMONARMOR, 16000);
            }

            void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/) override
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
                            _events.ScheduleEvent(EVENT_SHADOW_BOLT_VOLLEY, 12000);
                            break;
                        case EVENT_IMMOLATE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                                DoCast(target, SPELL_IMMOLATE);
                            _events.ScheduleEvent(EVENT_IMMOLATE, 25000);
                            break;
                        case EVENT_CURSE_OF_WEAKNESS:
                            DoCastVictim(SPELL_CURSEOFWEAKNESS);
                            _events.ScheduleEvent(EVENT_CURSE_OF_WEAKNESS, 45000);
                            break;
                        case EVENT_DEMONARMOR:
                            DoCast(me, SPELL_DEMONARMOR);
                            _events.ScheduleEvent(EVENT_DEMONARMOR, 300000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
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
