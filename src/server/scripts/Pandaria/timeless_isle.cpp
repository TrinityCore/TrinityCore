///*
// * Copyright (C) 2017-2019 AshamaneProject <https://github.com/AshamaneProject>
// * Copyright (C) 2016 Firestorm Servers <https://firestorm-servers.com>
// *
// * This program is free software; you can redistribute it and/or modify it
// * under the terms of the GNU General Public License as published by the
// * Free Software Foundation; either version 2 of the License, or (at your
// * option) any later version.
// *
// * This program is distributed in the hope that it will be useful, but WITHOUT
// * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
// * more details.
// *
// * You should have received a copy of the GNU General Public License along
// * with this program. If not, see <http://www.gnu.org/licenses/>.
// */
//
//#include "ScriptMgr.h"
//#include "ScriptedCreature.h"
//#include "ScriptedGossip.h"
//#include "ScriptedEscortAI.h"
//#include "timeless_isle.h"
//
//// Anduin Wrynn - 73061
//class npc_prince_anduin : public CreatureScript
//{
//    public:
//        npc_prince_anduin() : CreatureScript("npc_prince_anduin") {}
//
//        struct npc_prince_anduinAI : public ScriptedAI
//        {
//            npc_prince_anduinAI(Creature* creature) : ScriptedAI(creature) {}
//
//            EventMap events;
//
//            void DoAction(int32 action) override
//            {
//                switch (action)
//                {
//                    case ACTION_PRINCE_TALK_1:
//                        Talk(0);
//                        break;
//                    case ACTION_PRINCE_TALK_2:
//                        Talk(1);
//                        break;
//                    case ACTION_PRINCE_TALK_3:
//                        Talk(2);
//                        break;
//                    case ACTION_PRINCE_TALK_4:
//                        Talk(3);
//                        break;
//                    case ACTION_PRINCE_TALK_5:
//                        Talk(4);
//                        break;
//                    default:
//                        break;
//                }
//            }
//        	if (used == false)
//        	{
//                go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_INTERACT_COND);
//
//            	used = true;
//
//        		Choice = urand(1, 5);
//        	}
//
//        	if (player->HasAura(SPELL_FORTITUDE_OF_NIUZAO))
//        		player->RemoveAurasDueToSpell(SPELL_FORTITUDE_OF_NIUZAO);
//
//        	if (player->HasAura(SPELL_WISDOM_OF_YULON))
//            	player->RemoveAurasDueToSpell(SPELL_WISDOM_OF_YULON);
//
//        	if (player->HasAura(SPELL_CHI_JIS_HOPE))
//            	player->RemoveAurasDueToSpell(SPELL_CHI_JIS_HOPE);
//
//        	if (player->HasAura(SPELL_XUENS_STRENGTH))
//            	player->RemoveAurasDueToSpell(SPELL_XUENS_STRENGTH);
//
//        	Creature* trigger = go->FindNearestCreature(NPC_TIME_LOST_SHRINE_TRIGGER, 5.0f); // An npc needs to be spawned in the same coordinates for the shrine
//
///*       	if (Choice == 1)
//            {
//            	go->CastSpell(player, SPELL_FORTITUDE_OF_NIUZAO);
//            	trigger->AI()->Talk(SAY_BLESSING_NIUZAO, player->GetGUID());
//            }
//
//        	if (Choice == 2)
//        	{
//            	go->CastSpell(player, SPELL_WISDOM_OF_YULON);
//            	trigger->AI()->Talk(SAY_BLESSING_YULON, player->GetGUID());
//            }
//
//            if (Choice == 3)
//            {
//            	go->CastSpell(player, SPELL_CHI_JIS_HOPE);
//            	trigger->AI()->Talk(SAY_BLESSING_CHI_JI, player->GetGUID());
//        	}
//
//        	if (Choice == 4)
//        	{
//        		go->CastSpell(player, SPELL_XUENS_STRENGTH);
//        		trigger->AI()->Talk(SAY_BLESSING_XUEN, player->GetGUID());
//        	}
//
//        	if (Choice == 5)
//        	{
//            	go->CastSpell(player, SPELL_ORDOS_BURNING_SACRIFICE);
//            	trigger->AI()->Talk(SAY_CORRUPTION_ORDOS, player->GetGUID());
//            }
//*/
////            BackToUse = 300000;
//
//            return true;
//        }
//
//		void UpdateAI(uint32 diff)
//        {
//            if (used == false)
//                return;
//
//            if (BackToUse <= diff)
//            {
//               	go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_INTERACT_COND);
//                used = false; // this will stop/prevent it from updating it
//            }
//
//            else
//            	BackToUse -= diff;
//        }
//
//    private:
//    	uint32 BackToUse;
//
//    	uint8 Choice;
//
//    	bool used;
//    };
//
//	GameObjectAI* GetAI(GameObject* go) const 
//    {
//        return new go_time_lost_shrine_tiAI(go);
//    }
//};
//
//class go_gleaming_crane_statue_ti : public GameObjectScript
//{
//public:
//    go_gleaming_crane_statue_ti() : GameObjectScript("go_gleaming_crane_statue_ti") { }
//
//    struct go_gleaming_crane_statue_tiAI : public GameObjectAI
//    {
//        go_gleaming_crane_statue_tiAI(GameObject* go) : GameObjectAI(go) { }
//
//        uint64 playerGUID;
//        uint32 WingsTimer;
//
//		bool OnGossipHello(Player* player, GameObject* go)
//        {
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Touch the statue.", GOSSIP_SENDER_MAIN, 1);
//
//            player->SEND_GOSSIP_MENU(player->GetGossipTextId(go), go->GetGUID());
//
//            return true;
//        }
//
//		bool OnGossipSelect(Player* player, GameObject* go, uint32 /*sender*/, uint32 action)
//        {
//        	player->PlayerTalkClass->ClearMenus();
//        	player->CLOSE_GOSSIP_MENU();
//
//        	switch (action)
//        	{
//        		case 1:
//        			player->CastSpell(player* player, 144387, true); // knockback in the air
//        			playerGUID = player->GetGUID();
//        			used = true;
//        			WingsTimer = 6000;
//        			break;
//        		default:
//        			break;
//        	}
//
//        	return true;
//        }
//
//		void UpdateAI(uint32 diff)
//        {
//            if (used == false)
//            	return;
//
//            if (WingsTimer <= diff)
//            {
//                if (Player* player = ObjectAccessor::GetPlayer(*go, playerGUID))
//                {
//                	player->CastSpell(player, 144385, true);
//                	used = false;
//                }
//            }
//
//            else 
//                WingsTimer -= diff;
//        }
//
//    private:
//        bool used;
//    };
//
//	GameObjectAI* GetAI(GameObject* go) const 
//    {
//        return new go_gleaming_crane_statue_tiAI(go);
//    }
//};
//
//class spell_timeless_isle_crane_wings : public SpellScriptLoader
//{
//public:
//    spell_timeless_isle_crane_wings() : SpellScriptLoader("spell_timeless_isle_crane_wings") { }
//
//    class spell_timeless_isle_crane_wings_AuraScript : public AuraScript
//    {
//        PrepareAuraScript(spell_timeless_isle_crane_wings_AuraScript);
//
//        void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
//        {
//            if (Unit* caster = GetCaster())
//             	caster->CastSpell(caster, 144391, true);
//        }
//
//        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
//        {
//            if (Unit* caster = GetCaster())
//            	caster->CastSpell(caster, 148162, true);
//        }
//
//		void Register()
//        {
//            OnEffectApply += AuraEffectApplyFn(spell_timeless_isle_crane_wings_AuraScript::OnApply, EFFECT_0, SPELL_AURA_FEATHER_FALL, AURA_EFFECT_HANDLE_REAL);
//            OnEffectRemove += AuraEffectRemoveFn(spell_timeless_isle_crane_wings_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
//        }
//    };
//
//	AuraScript* GetAuraScript() const 
//    {
//        return new spell_timeless_isle_crane_wings_AuraScript();
//    }
//};
//
//class spell_timeless_isle_cauterize : public SpellScriptLoader
//{
//public:
//    spell_timeless_isle_cauterize() : SpellScriptLoader("spell_timeless_isle_cauterize") { }
//
//    class spell_timeless_isle_cauterize_AuraScript : public AuraScript
//    {
//        PrepareAuraScript(spell_timeless_isle_cauterize_AuraScript);
//
//        void OnPeriodic(AuraEffect const* /*aurEff*/)
//        {
//            GetCaster()->SetMaxHealth(GetCaster()->GetHealthPct() - 1.0f);
//        }
//
//		void Register()
//        {
//            OnEffectPeriodic += AuraEffectPeriodicFn(spell_timeless_isle_cauterize_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
//        }
//    };
//
//	AuraScript* GetAuraScript() const 
//    {
//        return new spell_timeless_isle_cauterize_AuraScript();
//    }
//};
//
//class spell_timeless_isle_burning_fury : public SpellScriptLoader
//{
//public:
//    spell_timeless_isle_burning_fury() : SpellScriptLoader("spell_timeless_isle_burning_fury") { }
//
//    class spell_timeless_isle_burning_fury_AuraScript : public AuraScript
//    {
//        PrepareAuraScript(spell_timeless_isle_burning_fury_AuraScript);
//
//        void OnPeriodic(AuraEffect const* /*aurEff*/)
//        {
//            GetCaster()->DealDamage(GetCaster(), 50000, NULL, SELF_DAMAGE, SPELL_SCHOOL_MASK_FIRE);
//        }
//
//		void Register()
//        {
//            OnEffectPeriodic += AuraEffectPeriodicFn(spell_timeless_isle_burning_fury_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
//        }
//    };
//
//	AuraScript* GetAuraScript() const 
//    {
//        return new spell_timeless_isle_burning_fury_AuraScript();
//    }
//};
//
//enum EmperorEvent
//{
//    EVENT_EMPEROR_ARRANGE_BOSS = 1
//};
//
//// Emperor Shaohao #73303#
//class npc_emperor_shaohao : public CreatureScript
//{
//public:
//    npc_emperor_shaohao() : CreatureScript("npc_emperor_shaohao") { }
//
//    CreatureAI* GetAI(Creature* creature) const
//    {
//        return new npc_emperor_shaohaoAI(creature);
//    }
//
//    struct npc_emperor_shaohaoAI : public ScriptedAI
//    {
//        npc_emperor_shaohaoAI(Creature* creature) : ScriptedAI(creature) { }
//
//        void Reset()
//        {
//            me->setActive(true);
//            events.Reset();
//            _yulon = true;
//            _xuen = false;
//            _chiji = false;
//            _niuzao = false;
//            events.ScheduleEvent(EVENT_EMPEROR_ARRANGE_BOSS, 5000);
//        }
//
//        void DoAction(const int32 action)
//        {
//            switch (action)
//            {
//                case ACTION_XUEN:
//                    _xuen = true;
//                    break;
//                case ACTION_CHIJI:
//                    _chiji = true;
//                    break;
//                case ACTION_NIUZAO:
//                    _niuzao = true;
//                    break;
//                case ACTION_YULON:
//                    _yulon = true;
//                    break;
//            }
//
//            events.ScheduleEvent(EVENT_EMPEROR_ARRANGE_BOSS, 8500);
//        }
//
//        void UpdateAI(const uint32 diff)
//        {
//            events.Update(diff);
//
//            switch (events.ExecuteEvent())
//            {
//                case EVENT_EMPEROR_ARRANGE_BOSS:
//                {
//                    if (_yulon)
//                    {
//                        if (Creature* yulon = me->FindNearestCreature(BOSS_YU_LON, 300.0f, true))
//                        {
//                            yulon->GetMotionMaster()->MovePoint(1, _timelessIsleMiddle);
//                            me->AI()->Talk(EMPEROR_TALK_INTRO_YULON);
//                        }
//                        else
//                            _xuen = true;
//
//                        _yulon = false;
//                    }
//                    if (_xuen)
//                    {
//                        if (Creature* xuen = me->FindNearestCreature(BOSS_XUEN, 300.0f, true))
//                        {
//                            xuen->GetMotionMaster()->MovePoint(1, _timelessIsleMiddle);
//                            me->AI()->Talk(EMPEROR_TALK_INTRO_XUEN);
//                        }
//                        else
//                            _chiji = true;
//
//                        _xuen = false;
//                    }
//                    if (_chiji)
//                    {
//                        if (Creature* chiji = me->FindNearestCreature(BOSS_CHI_JI, 300.0f, true))
//                        {
//                            chiji->GetMotionMaster()->MovePoint(1, _timelessIsleMiddle);
//                            me->AI()->Talk(EMPEROR_TALK_INTRO_CHIJI);
//                        }
//                        else
//                            _niuzao = true;
//
//                        _chiji = false;
//                    }
//                    if (_niuzao)
//                    {
//                        if (Creature* niuzao = me->FindNearestCreature(BOSS_NIUZAO, 300.0f, true))
//                        {
//                            niuzao->GetMotionMaster()->MovePoint(1, _timelessIsleMiddle);
//                            me->AI()->Talk(EMPEROR_TALK_INTRO_NIUZAO);
//                        }
//                        else
//                            _yulon = true;
//
//                        _niuzao = false;
//                    }
//
//                    events.ScheduleEvent(EVENT_EMPEROR_ARRANGE_BOSS, 5000);
//                    break;
//                }
//                default:
//                    break;
//            }
//        }
//
//            void UpdateAI(uint32 /*diff*/) override
//            {
//            }
//        };
//
//        CreatureAI* GetAI(Creature* creature) const override
//        {
//            return new npc_prince_anduinAI(creature);
//        }
//};
//
//// Kairoz - 72870
//class npc_kairoz : public CreatureScript
//{
//    public:
//        npc_kairoz() : CreatureScript("npc_kairoz") {}
//
//        bool OnQuestReward(Player* player, Creature* creature, Quest const* quest, uint32 /*opt*/) override
//        {
//            if (quest->GetQuestId() == QUEST_TIME_KEEPER_KAIROZ_H || quest->GetQuestId() == QUEST_TIME_KEEPER_KAIROZ_A)
//            {
//                if (creature->IsQuestGiver() && creature->AI())
//                {
//                    creature->AI()->SetGUID(player ? player->GetGUID() : ObjectGuid::Empty);
//                    creature->AI()->DoAction(ACTION_CONVERSATION);
//                }
//            }
//            return true;
//        }
//
//        struct npc_kairozAI : public ScriptedAI
//        {
//            npc_kairozAI(Creature* creature) : ScriptedAI(creature) {}
//
//            EventMap events;
//            ObjectGuid playerGUID;
//            bool conversationEngaged;
//
//            void Reset() override
//            {
//                playerGUID = ObjectGuid::Empty;
//                conversationEngaged = false;
//            }
//
//            void SetGUID(ObjectGuid guid, int32 /*id*/ /*= 0*/) override
//            {
//                playerGUID = guid;
//            }
//
//            void DoAction(int32 action) override
//            {
//                switch (action)
//                {
//                    case ACTION_KAIROZ_TALK_1:
//                        Talk(0);
//                        break;
//                    case ACTION_KAIROZ_TALK_2:
//                        Talk(1);
//                        break;
//                    case ACTION_KAIROZ_TALK_3:
//                        Talk(2);
//                        break;
//                    case ACTION_KAIROZ_TALK_4:
//                        Talk(3);
//                        break;
//                    case ACTION_KAIROZ_TALK_5:
//                        Talk(4);
//                        break;
//                    case ACTION_CONVERSATION:
//                        if (!conversationEngaged)
//                        {
//                            conversationEngaged = true;
//                            events.ScheduleEvent(EVENT_PRINCE_TALK_1, 3000);
//                            events.ScheduleEvent(EVENT_KAIROZ_TALK_1, 6000);
//                            events.ScheduleEvent(EVENT_PRINCE_TALK_2, 11000);
//                            events.ScheduleEvent(EVENT_KAIROZ_TALK_2, 18000);
//                            events.ScheduleEvent(EVENT_PRINCE_TALK_3, 25000);
//                            events.ScheduleEvent(EVENT_KAIROZ_TALK_3, 32000);
//                            events.ScheduleEvent(EVENT_PRINCE_TALK_4, 39000);
//                            events.ScheduleEvent(EVENT_KAIROZ_TALK_4, 46000);
//                            events.ScheduleEvent(EVENT_KAIROZ_TALK_5, 54000);
//                            events.ScheduleEvent(EVENT_PRINCE_TALK_5, 60000);
//                        }
//                        break;
//                    default:
//                        break;
//                }
//            }
//
//            void UpdateAI(uint32 diff) override
//            {
//                events.Update(diff);
//
//                std::list<Creature*> princeAnduinList;
//                GetCreatureListWithEntryInGrid(princeAnduinList, me, NPC_PRINCE_ANDUIN, 7.0f);
//
//                while (uint32 eventId = events.ExecuteEvent())
//                {
//                    switch (eventId)
//                    {
//                        case EVENT_PRINCE_TALK_1:
//                            if (!princeAnduinList.empty())
//                                for (auto princeAnduin : princeAnduinList)
//                                    princeAnduin->AI()->DoAction(ACTION_PRINCE_TALK_1);
//                            break;
//                        case EVENT_KAIROZ_TALK_1:
//                            DoAction(ACTION_KAIROZ_TALK_1);
//                            break;
//                        case EVENT_PRINCE_TALK_2:
//                            if (!princeAnduinList.empty())
//                                for (auto princeAnduin : princeAnduinList)
//                                    princeAnduin->AI()->DoAction(ACTION_PRINCE_TALK_2);
//                            break;
//                        case EVENT_KAIROZ_TALK_2:
//                            DoAction(ACTION_KAIROZ_TALK_2);
//                            break;
//                        case EVENT_PRINCE_TALK_3:
//                            if (!princeAnduinList.empty())
//                                for (auto princeAnduin : princeAnduinList)
//                                    princeAnduin->AI()->DoAction(ACTION_PRINCE_TALK_3);
//                            break;
//                        case EVENT_KAIROZ_TALK_3:
//                            DoAction(ACTION_KAIROZ_TALK_3);
//                            break;
//                        case EVENT_PRINCE_TALK_4:
//                            if (!princeAnduinList.empty())
//                                for (auto princeAnduin : princeAnduinList)
//                                    princeAnduin->AI()->DoAction(ACTION_PRINCE_TALK_4);
//                            break;
//                        case EVENT_KAIROZ_TALK_4:
//                            DoAction(ACTION_KAIROZ_TALK_4);
//                            break;
//                        case EVENT_KAIROZ_TALK_5:
//                            DoAction(ACTION_KAIROZ_TALK_5);
//                            break;
//                        case EVENT_PRINCE_TALK_5:
//                            if (!princeAnduinList.empty())
//                                for (auto princeAnduin : princeAnduinList)
//                                {
//                                    princeAnduin->AI()->DoAction(ACTION_PRINCE_TALK_5);
//                                    conversationEngaged = false;
//                                }
//                            break;
//                        default:
//                            break;
//                    }
//                }
//            }
//        };
//
//        CreatureAI* GetAI(Creature* creature) const override
//        {
//            return new npc_kairozAI(creature);
//        }
//};
//
//void AddSC_timeless_isle()
//{
//    new npc_prince_anduin();
//    new npc_kairoz();
//}
