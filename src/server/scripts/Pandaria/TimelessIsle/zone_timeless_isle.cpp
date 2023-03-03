///*
// * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
//#include "ObjectMgr.h"
//#include "ScriptMgr.h"
//#include "Object.h"
//#include "Player.h"
//#include "GameObject.h"
//#include "GameObjectAI.h"
//#include "Unit.h"
//#include "UnitAI.h"
//#include "ScriptedGossip.h"
//#include "GossipDef.h"
//#include "timeless_isle.h"
//
//enum TimeLostShrine
//{
//    // Says
//    SAY_BLESSING_NIUZAO                 = 0,
//    SAY_BLESSING_YULON                  = 1,
//    SAY_BLESSING_CHI_JI                 = 2,
//    SAY_BLESSING_XUEN                   = 3,
//    SAY_CORRUPTION_ORDOS                = 4,
//
//    // Spells
//    SPELL_FORTITUDE_OF_NIUZAO           = 147281,
//    SPELL_WISDOM_OF_YULON               = 147282,
//    SPELL_CHI_JIS_HOPE                  = 147283,
//    SPELL_XUENS_STRENGTH                = 147284,
//    SPELL_ORDOS_BURNING_SACRIFICE       = 147285,
//};
//
//class npc_eternal_kiln : public CreatureScript
//{
//public:
//    npc_eternal_kiln() : CreatureScript("npc_eternal_kiln") { }
//
//    struct npc_eternal_kilnAI : public ScriptedAI
//    {
//        npc_eternal_kilnAI(Creature* creature) : ScriptedAI(creature) { }
//
//		void JustDied(Unit* /*killer*/) override
//        {
//            me->DespawnOrUnsummon();
//        }
//
//		void IsSummonedBy(Unit* summoner) override
//        {
//            switch (summoner->GetEntry())
//            {
//                case RARE_ARCHIEREUS_OF_FLAME:
//                case RARE_ARCHIEREUS_OF_FLAME_CLOAK:
//                case RARE_FLINTLORD_GAIRAN:
//                case NPC_ETERNAL_KILNMASTER:
//                case NPC_HIGH_PRIEST_OF_ORDOS:
//                    DoCast(summoner, SPELL_KILNFIRE);
//                    me->SetReactState(REACT_PASSIVE);
//                    break;
//                default:
//                    break;
//            }
//        }
//    };
//
//	CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new npc_eternal_kilnAI(creature);
//    }
//};
//
//class npc_flarecore_golem : public CreatureScript
//{
//public:
//    npc_flarecore_golem() : CreatureScript("npc_flarecore_golem") { }
//
//    struct npc_flarecore_golemAI : public ScriptedAI
//    {
//        npc_flarecore_golemAI(Creature* creature) : ScriptedAI(creature) { }
//
//		void JustDied(Unit* /*killer*/) override
//        {
//            me->DespawnOrUnsummon();
//        }
//
//		void IsSummonedBy(Unit* summoner) override
//        {
//            switch (summoner->GetEntry())
//            {
//                case RARE_ARCHIEREUS_OF_FLAME:
//                case RARE_ARCHIEREUS_OF_FLAME_CLOAK:
//                case RARE_URDUR_THE_CAUTERIZER:
//                case NPC_BLAZEBOUND_CHANTER:
//                case NPC_HIGH_PRIEST_OF_ORDOS:
//                    me->SetWalk(true);
//                    me->GetMotionMaster()->MoveChase(summoner->getVictim(), 0.0f, 0.0f);
//					me->SetInCombatWith(summoner->getVictim());
//                    me->SetReactState(REACT_AGGRESSIVE);
//                    break;
//                default:
//                    break;
//            }
//        }
//    };
//
//	CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new npc_flarecore_golemAI(creature);
//    }
//};
//
//class go_time_lost_shrine_ti : public GameObjectScript
//{
//public:
//	go_time_lost_shrine_ti() : GameObjectScript("go_time_lost_shrine_ssti") { }//disabled for now
//
//	struct go_time_lost_shrine_tiAI : public GameObjectAI
//	{
//		go_time_lost_shrine_tiAI(GameObject* go) : GameObjectAI(go) { }
//
//		bool onclick(Player* player, GameObject* go) 
//		{
//			
//
//			if (used == false)
//			{
//				go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_INTERACT_COND);
//
//				used = true;
//
//				Choice = urand(1, 5);
//			}
//
//			if (player->HasAura(SPELL_FORTITUDE_OF_NIUZAO))
//				player->RemoveAurasDueToSpell(SPELL_FORTITUDE_OF_NIUZAO);
//
//			if (player->HasAura(SPELL_WISDOM_OF_YULON))
//				player->RemoveAurasDueToSpell(SPELL_WISDOM_OF_YULON);
//
//			if (player->HasAura(SPELL_CHI_JIS_HOPE))
//				player->RemoveAurasDueToSpell(SPELL_CHI_JIS_HOPE);
//
//			if (player->HasAura(SPELL_XUENS_STRENGTH))
//				player->RemoveAurasDueToSpell(SPELL_XUENS_STRENGTH);
//
//			Creature* trigger = go->FindNearestCreature(NPC_TIME_LOST_SHRINE_TRIGGER, 5.0f); // An npc needs to be spawned in the same coordinates for the shrine
//
//			if (Choice == 1)
//			{
//				player->CastSpell(player, SPELL_FORTITUDE_OF_NIUZAO, true);
//				trigger->AI()->Talk(SAY_BLESSING_NIUZAO, player->GetGUID());
//			}
//
//			if (Choice == 2)
//			{
//				player->CastSpell(player, SPELL_WISDOM_OF_YULON, true);
//				trigger->AI()->Talk(SAY_BLESSING_YULON, player->GetGUID());
//			}
//
//			if (Choice == 3)
//			{
//				player->CastSpell(player, SPELL_CHI_JIS_HOPE, true);
//				trigger->AI()->Talk(SAY_BLESSING_CHI_JI, player->GetGUID());
//			}
//
//			if (Choice == 4)
//			{
//				player->CastSpell(player, SPELL_XUENS_STRENGTH, true);
//				trigger->AI()->Talk(SAY_BLESSING_XUEN, player->GetGUID());
//			}
//
//			if (Choice == 5)
//			{
//				player->CastSpell(player, SPELL_ORDOS_BURNING_SACRIFICE, true);
//				trigger->AI()->Talk(SAY_CORRUPTION_ORDOS, player->GetGUID());
//			}
//
//			BackToUse = 300000;
//
//			return true;
//		}
//
//		void UpdateAI(uint32 diff) override
//		{
//			if (used == false)
//			return;
//
//			if (BackToUse <= diff)
//			{
//				go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_INTERACT_COND);
//				used = false; // this will stop/prevent it from updating it
//			}
//
//			else
//				BackToUse -= diff;
//		}
//
//	private:
//		uint32 BackToUse;
//
//		uint8 Choice;
//
//		bool used;
//	};
//
//	GameObjectAI* GetAI(GameObject* go) const 
//	{
//		return new go_time_lost_shrine_tiAI(go);
//	}
//};
//
//
//class go_timelost_test : public GameObjectScript
//{
//public:
//	go_timelost_test() : GameObjectScript("go_time_lost_shrine_ti") { }
//
//	bool OnGossipHello(Player* player, GameObject* go)
//	{
//
//		
//			Choice = urand(1, 5);
//		
//		if (player->HasAura(SPELL_FORTITUDE_OF_NIUZAO))
//			player->RemoveAurasDueToSpell(SPELL_FORTITUDE_OF_NIUZAO);
//
//		if (player->HasAura(SPELL_WISDOM_OF_YULON))
//			player->RemoveAurasDueToSpell(SPELL_WISDOM_OF_YULON);
//
//		if (player->HasAura(SPELL_CHI_JIS_HOPE))
//			player->RemoveAurasDueToSpell(SPELL_CHI_JIS_HOPE);
//
//		if (player->HasAura(SPELL_XUENS_STRENGTH))
//			player->RemoveAurasDueToSpell(SPELL_XUENS_STRENGTH);
//
//		//return false; stops the code bellow from functioning.
//		//Creature* trigger = player->FindNearestCreature(NPC_TIME_LOST_SHRINE_TRIGGER, 5.0f); // An npc needs to be spawned in the same coordinates for the shrine
//
//		
//		if (Choice == 1)
//		{
//			player->CastSpell(player, SPELL_FORTITUDE_OF_NIUZAO, true);
//			//trigger->AI()->Talk(SAY_BLESSING_NIUZAO, player->GetGUID());
//		}
//
//		if (Choice == 2)
//		{
//			player->CastSpell(player, SPELL_WISDOM_OF_YULON, true);
//			//trigger->AI()->Talk(SAY_BLESSING_YULON, player->GetGUID());
//		}
//
//		if (Choice == 3)
//		{
//			player->CastSpell(player, SPELL_CHI_JIS_HOPE, true);
//			//trigger->AI()->Talk(SAY_BLESSING_CHI_JI, player->GetGUID());
//		}
//
//		if (Choice == 4)
//		{
//			player->CastSpell(player, SPELL_XUENS_STRENGTH, true);
//			//trigger->AI()->Talk(SAY_BLESSING_XUEN, player->GetGUID());
//		}
//
//		if (Choice == 5)
//		{
//			player->CastSpell(player, SPELL_ORDOS_BURNING_SACRIFICE, true);
//			//trigger->AI()->Talk(SAY_CORRUPTION_ORDOS, player->GetGUID());
//		}
//
//
//		return true;
//
//	}
//
//private:
//
//
//	uint8 Choice;
//
//	bool used;
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
//        			player->CastSpell(player, 144387, true); // knockback in the air
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
//		void UpdateAI(uint32 diff) override
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
//
//
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
//	GameObjectAI* GetAI(GameObject* go) const override
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
//		void OnApply(constAuraEffectPtr /*aurEff*/, AuraEffectHandleModes /*mode*/)
//        {
//            if (Unit* caster = GetCaster())
//             	caster->CastSpell(caster, 144391, true);
//        }
//
//		void OnRemove(constAuraEffectPtr /*aurEff*/, AuraEffectHandleModes /*mode*/)
//        {
//            if (Unit* caster = GetCaster())
//            	caster->CastSpell(caster, 148162, true);
//        }
//
//		void Register() override
//        {
//            OnEffectApply += AuraEffectApplyFn(spell_timeless_isle_crane_wings_AuraScript::OnApply, EFFECT_0, SPELL_AURA_FEATHER_FALL, AURA_EFFECT_HANDLE_REAL);
//            OnEffectRemove += AuraEffectRemoveFn(spell_timeless_isle_crane_wings_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
//        }
//    };
//
//	AuraScript* GetAuraScript() const override
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
//		void OnPeriodic(constAuraEffectPtr /*aurEff*/)
//        {
//            GetCaster()->SetMaxHealth(GetCaster()->GetHealthPct() - 1.0f);
//        }
//
//		void Register() override
//        {
//            OnEffectPeriodic += AuraEffectPeriodicFn(spell_timeless_isle_cauterize_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
//        }
//    };
//
//	AuraScript* GetAuraScript() const override
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
//		void OnPeriodic(constAuraEffectPtr /*aurEff*/)
//        {
//            GetCaster()->DealDamage(GetCaster(), 50000, NULL, SELF_DAMAGE, SPELL_SCHOOL_MASK_FIRE);
//        }
//
//		void Register() override
//        {
//            OnEffectPeriodic += AuraEffectPeriodicFn(spell_timeless_isle_burning_fury_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
//        }
//    };
//
//	AuraScript* GetAuraScript() const override
//    {
//        return new spell_timeless_isle_burning_fury_AuraScript();
//    }
//};
//
//void AddSC_zone_timeless_isle()
//{
//    new npc_eternal_kiln();
//    new npc_flarecore_golem();
//    new go_time_lost_shrine_ti();
//    new go_gleaming_crane_statue_ti();
//    new spell_timeless_isle_crane_wings();
//    new spell_timeless_isle_cauterize();
//    new spell_timeless_isle_burning_fury();
//	new go_timelost_test();
//	
//}
