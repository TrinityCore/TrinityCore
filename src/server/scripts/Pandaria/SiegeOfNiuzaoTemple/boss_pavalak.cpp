//
//#include "ObjectMgr.h"
//#include "Player.h"
//#include "ScriptMgr.h"
//#include "ScriptedCreature.h"
//#include "siege_of_the_niuzoa_temple.h"
//#include "AchievementMgr.h"
//
//enum Achievements
//{
//	ACHIEVEMENT_RETURN_TO_SENDER = 6485,
//};
//
//enum Yells
//{
//	SAY_INTRO,
//	SAY_AGGRO,
//	SAY_GROUND_ASSAULT,
//	SAY_KILL,
//	SAY_DEATH
//};
//
//enum Spells
//{
//	// Boss General Pa'valak spells
//	SPELL_BLADE_RUSH_THROW = 124283,// 
//	SPELL_BLADE_RUSH_IMPACT = 124317,
//	SPELL_BLADE_RUSH_CHARGE = 128239,
//	SPELL_BLADE_RUSH_SUMMON = 124277,
//	SPELL_BLADE_RUSH_DAMAGE = 124290,
//	SPELL_TEMPEST = 119875,
//	SPELL_BULWARK = 119476,
//
//	// NPC spells entry 63720
//	SPELL_SIEGE_EXPLOSIVE_PULSE = 124288,
//	SPELL_SIEGE_EXPLOSIVE_SWARD = 124307,
//	SPELL_SIEGE_EXPLOSIVE_THROW = 119388,
//	// NPC value 61452 for bomb or pick bomb script. It detonates after 6 secnds with visual alert for 4
//	SPELL_SIEGE_EXPLOSIVE_SUMMON = 119377, // When NPC reach the land cast this spell and add script explode or despawn if player picks me
//	SPELL_SIEGE_EXPLOSIVE_VISUAL = 119380,
//	SPELL_SIEGE_EXPLOSIVE_DETONATE = 119393  // 119395 parrent spell
//
//};
//
//enum Events
//{
//	// Boss General Pa'valak
//	EVENT_BLADE_RUSH = 1, // 14 sec
//	EVENT_TEMPEST = 2, // 28 sec
//	EVENT_SIEGE_EXPLOSIVE_SUMMON = 3,  // 3 sec
//	EVENT_BULWARK = 4,
//	EVENT_OTHER_STUFF = 5,
//	EVENT_EXPLOSION = 6,
//	EVENT_BLADE_RUSH_COSMETIC = 7,
//	EVENT_BLADE_RUSH_COSMETIC_2 = 8,
//	EVENT_AURA_REMOVE = 9,
//	EVENT_MOVE_FIX = 10,
//};
//
//enum NpcSikthikSoldier
//{
//	NPC_SIKTHIK_SOLDIER = 62348,
//	NPC_SIEGE_EXPLOSIVE = 61452,
//	NPC_BLADE_RUSH = 63720
//};
//
//Position const BulckPosition = { 1717.95f, 5244.31f, 124.16f, 1.48f };
//Position const SikthikSoldierPosition[10] =
//{
//	{ 1716.36f, 5291.29f, 127.311f, 4.62629f },
//	{ 1721.45f, 5291.00f, 127.162f, 4.57917f },
//	{ 1725.68f, 5290.45f, 126.976f, 4.56739f },
//	{ 1724.18f, 5296.57f, 128.179f, 4.60273f },
//	{ 1719.31f, 5297.09f, 128.345f, 4.62629f },
//	{ 1717.52f, 5300.64f, 128.867f, 4.62629f },
//	{ 1722.17f, 5300.24f, 128.734f, 4.61451f },
//	{ 1727.29f, 5299.42f, 128.653f, 4.49278f },
//	{ 1725.47f, 5303.87f, 129.532f, 4.49278f },
//	{ 1720.80f, 5304.91f, 129.603f, 4.49278f },
//};
//
//
//class boss_general_pavalak : public CreatureScript
//{
//public:
//	boss_general_pavalak() : CreatureScript("boss_general_pavalak") { }
//
//	struct boss_general_pavalakAI : public BossAI
//	{
//		boss_general_pavalakAI(Creature* creature) : BossAI(creature, DATA_PAVALAK)
//		{}
//
//		InstanceScript* instance;
//		Unit* bladenpc;
//
//		bool hasstarted65healthevent;
//		bool hasstarted35healthevent;
//		bool bulwarkisdonegonormal;
//		bool haswipe;
//		void Reset()
//		{
//			_Reset();
//	
//			bladenpc = NULL;
//			if (IsHeroic())
//			{
//				me->SetHealth(27403480);
//				me->SetMaxHealth(27403480);
//				me->SetLevel(93);
//			}
//			else
//			{
//				me->SetHealth(22414260);
//				me->SetMaxHealth(22414260);
//				me->SetLevel(91);
//			}
//			haswipe = true;
//			bulwarkisdonegonormal = false;
//
//			if (!me->isInCombat())
//			hasstarted65healthevent = true;
//			hasstarted35healthevent = true;
//		}
//
//		void EnterCombat(Unit* /*who*/)
//		{
//			_EnterCombat();
//			Talk(SAY_AGGRO);
//
//			haswipe = false;
//			events.ScheduleEvent(EVENT_BLADE_RUSH, urand(13000, 15000));
//			events.ScheduleEvent(EVENT_TEMPEST, urand(24000, 27000));
//		}
//
//		void MoveInLineOfSight(Unit* who)
//		{
//			if (bladenpc)
//			{
//				if (me->IsWithinDist(bladenpc, 1.0f, true))
//				{
//					bladenpc->CastSpell(bladenpc, SPELL_BLADE_RUSH_DAMAGE, true);
//					bladenpc->RemoveAurasDueToSpell(SPELL_SIEGE_EXPLOSIVE_SWARD);
//				}
//			}
//		}
//
//		void JustReachedHome()
//		{
//			//instance->SetBossState(DATA_PAVALAK, FAIL);
//			summons.DespawnAll();
//		}
//		void SpellHitTarget(Unit* target, SpellInfo const* spell)
//		{
//			if (spell->Id == SPELL_BLADE_RUSH_THROW)
//			{
//				bladenpc->CastSpell(bladenpc, SPELL_SIEGE_EXPLOSIVE_SWARD, true);
//				bladenpc->CastSpell(bladenpc, SPELL_BLADE_RUSH_DAMAGE, true);
//				me->CastSpell(bladenpc, SPELL_BLADE_RUSH_CHARGE, true);
//			}
//		}
//		void UpdateAI(uint32 const diff)
//		{
//			events.Update(diff);
//
//
//			if (!haswipe)
//			{
//				Map::PlayerList const& players = me->GetMap()->GetPlayers();
//				if (players.isEmpty())
//				{
//					if (Creature* Boss = me->FindNearestCreature(61485, 400.0f, true))
//					{
//						Boss->DespawnOrUnsummon(50);
//						summons.DespawnAll();
//					}
//					events.Reset();
//				}
//				
//				for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
//				{
//					if (InstanceScript* instance = me->GetInstanceScript())
//					{
//						if (Player* dead_first = players.getFirst()->getSource())
//						{
//							if (Player* dead_last = players.getLast()->getSource())
//							{
//								if (dead_first->isDead() || !dead_first && dead_last->isDead() || !dead_last)
//								{
//									if (Creature* Boss = me->FindNearestCreature(61485, 400.0f, true))
//									{
//										Boss->DespawnOrUnsummon(50);
//										summons.DespawnAll();
//										dead_last->SummonCreature(61485, 1738.895264f, 5209.634766f, 123.783379f, 4.43109f,TEMPSUMMON_CORPSE_DESPAWN, 0);
//									}
//									events.Reset();
//								}
//							}
//						}
//					}
//				}
//				
//			}
//			if (UpdateVictim())
//			{
//				if (me->GetHealthPct() <= 65 && hasstarted65healthevent)
//				{
//					hasstarted65healthevent = false;
//					// react
//					me->SetReactState(REACT_PASSIVE);
//
//					if (MotionMaster* motion = me->GetMotionMaster())
//					{
//						motion->MovePoint(1, BulckPosition);
//
//						events.CancelEvent(EVENT_TEMPEST);
//						events.CancelEvent(EVENT_BLADE_RUSH);
//						events.ScheduleEvent(EVENT_BULWARK, 12000);
//						events.ScheduleEvent(EVENT_EXPLOSION, 9000);
//						events.ScheduleEvent(EVENT_OTHER_STUFF, 8000);
//					}
//				}
//				if (me->GetHealthPct() <= 35 && hasstarted35healthevent)
//				{
//					hasstarted35healthevent = false;
//					// react
//					me->SetReactState(REACT_PASSIVE);
//
//					if (MotionMaster* motion = me->GetMotionMaster())
//					{
//						motion->MovePoint(1, BulckPosition);
//
//						events.CancelEvent(EVENT_MOVE_FIX);
//						events.CancelEvent(EVENT_TEMPEST);
//						events.CancelEvent(EVENT_BLADE_RUSH);
//						events.ScheduleEvent(EVENT_BULWARK, 12000);
//						events.ScheduleEvent(EVENT_EXPLOSION, 9000);
//						events.ScheduleEvent(EVENT_OTHER_STUFF, 8000);
//					}
//				}
//				if (me->HasAura(SPELL_BULWARK) && !bulwarkisdonegonormal)
//				{
//					bulwarkisdonegonormal = true;
//					me->SetSpeed(MOVE_RUN, 0.0F, true);
//					me->AddUnitState(UNIT_STATE_CANNOT_AUTOATTACK);
//				}	
//				if (!me->HasAura(SPELL_BULWARK) && bulwarkisdonegonormal)
//				{
//					if (MotionMaster* motion = me->GetMotionMaster())
//					{
//						motion->Clear(true);
//					}
//					events.ScheduleEvent(EVENT_MOVE_FIX, 1000);
//					events.CancelEvent(EVENT_EXPLOSION);
//					me->SetReactState(REACT_AGGRESSIVE);
//					events.CancelEvent(EVENT_BLADE_RUSH);
//					events.ScheduleEvent(EVENT_BLADE_RUSH, urand(13000, 15000));
//					events.ScheduleEvent(EVENT_TEMPEST, urand(27000, 29000));
//					bulwarkisdonegonormal = false;
//					me->SetSpeed(MOVE_RUN, 1.2F, true);
//					me->ClearUnitState(UNIT_STATE_CANNOT_AUTOATTACK);
//					events.ScheduleEvent(EVENT_AURA_REMOVE, 8000);
//				}
//				if (!me->HasAura(SPELL_BULWARK))
//				{
//					if (Unit* victim = me->getVictim())
//					{
//						if (!me->IsWithinDistInMap(victim, 2.0f))
//						{
//							events.ScheduleEvent(EVENT_MOVE_FIX, 1000);
//						}
//					}
//				}
//				while (uint32 eventId = events.ExecuteEvent())
//				{
//					switch (eventId)
//					{
//					case EVENT_BLADE_RUSH:
//					{
//						if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50, true))
//						{
//							bladenpc = NULL;
//							bladenpc = me->SummonCreature(NPC_BLADE_RUSH, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0, TEMPSUMMON_MANUAL_DESPAWN, 3000);
//							DoCast(bladenpc, SPELL_BLADE_RUSH_THROW);
//							events.ScheduleEvent(EVENT_BLADE_RUSH, 13000);
//							events.ScheduleEvent(EVENT_BLADE_RUSH_COSMETIC, 3000);							
//							break;
//						}
//					}
//					case EVENT_BLADE_RUSH_COSMETIC:
//						if (bladenpc)
//						{
//							bladenpc->AddAura(124307, bladenpc);
//							events.ScheduleEvent(EVENT_BLADE_RUSH_COSMETIC_2, 2000);
//						}
//						break;
//					case EVENT_BLADE_RUSH_COSMETIC_2:
//						if (bladenpc)
//						{
//							me->CastSpell(bladenpc, 128239);
//						}
//						break;
//					case EVENT_TEMPEST:
//					{
//						if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50, true))
//						{
//							DoCastAOE(SPELL_TEMPEST);
//							events.ScheduleEvent(EVENT_TEMPEST, urand(27000, 29000));
//							break;
//						}
//					}
//					case EVENT_BULWARK:			
//						bulwarkisdonegonormal = false;
//						DoCastAOE(SPELL_BULWARK, false);
//						break;
//					case EVENT_OTHER_STUFF:
//						Talk(SAY_GROUND_ASSAULT);
//						SummonSikthikSoldier();
//						break;
//					case EVENT_EXPLOSION:
//						me->CastSpell(me, 119376, true);
//						if (me->HasAura(SPELL_BULWARK))
//						events.ScheduleEvent(EVENT_EXPLOSION, 15000);
//						break;
//					case EVENT_MOVE_FIX:
//						if (Unit* victim = me->getVictim())
//						{
//							if (!me->IsWithinDistInMap(victim, 2.0f))
//							{
//								if (MotionMaster* motion = me->GetMotionMaster())
//								{
//									motion->MovePoint(1, victim->GetPositionX(), victim->GetPositionY(), victim->GetPositionZ());
//								}
//								events.ScheduleEvent(EVENT_MOVE_FIX, 2000);
//							}
//						}
//						break;
//					}
//				}
//			}
//			DoMeleeAttackIfReady();
//		}
//
//		void JustDied(Unit* /*killer*/)
//		{
//			Talk(SAY_DEATH);
//			_JustDied();
//
//			if (IsHeroic() && me->HasAura(SPELL_SIEGE_EXPLOSIVE_DETONATE))
//			{
//				AuraPtr detonateStacks = me->GetAura(SPELL_SIEGE_EXPLOSIVE_DETONATE);
//
//				if (!detonateStacks) // Not needed but safty first :)
//					return;
//
//				if (detonateStacks->GetStackAmount() >= 10)
//				{
//					Map::PlayerList const &PlList = me->GetMap()->GetPlayers();
//					if (PlList.isEmpty())
//						return;
//					AchievementEntry const* achievementEntry = sAchievementMgr->GetAchievement(ACHIEVEMENT_RETURN_TO_SENDER);
//					for (Map::PlayerList::const_iterator i = PlList.begin(); i != PlList.end(); ++i)
//						if (Player* player = i->getSource())
//							player->CompletedAchievement(achievementEntry);
//				}
//			}
//		}
//
//		void KilledUnit(Unit* victim)
//		{
//			if (victim->GetTypeId() == TYPEID_PLAYER)
//				Talk(SAY_KILL);
//		}
//
//		void JustSummoned(Creature* summon)
//		{
//			switch (summon->GetEntry())
//			{
//			case NPC_SIKTHIK_SOLDIER:
//				summon->AI()->DoZoneInCombat(summon);
//				break;
//			case NPC_BLADE_RUSH:
//				summon->AI()->DoCast(SPELL_SIEGE_EXPLOSIVE_PULSE);
//				break;
//			}
//		}
//
//		void SummonSikthikSoldier()
//		{
//			for (uint8 i = 0; i < 10; ++i)
//				me->SummonCreature(NPC_SIKTHIK_SOLDIER, SikthikSoldierPosition[i], TEMPSUMMON_CORPSE_DESPAWN, 1000);
//			
//		}
//
//	};
//
//	CreatureAI* GetAI(Creature* creature) const
//	{
//		return new boss_general_pavalakAI(creature);
//	}
//};
//// NPC value 61452 needs to be .6 or .5 scaled to be blizzlike or so
//class npc_siege_explosive : public CreatureScript
//{
//public:
//	npc_siege_explosive() : CreatureScript("npc_siege_explosive") { }
//
//	bool OnGossipHello(Player* player, Creature* creature)
//	{
//		player->CLOSE_GOSSIP_MENU();
//		player->CastSpell(player, SPELL_SIEGE_EXPLOSIVE_THROW, true);
//		creature->DespawnOrUnsummon(1000);
//		return false;
//	}
//
//	struct npc_siege_explosiveAI : public ScriptedAI
//	{
//		npc_siege_explosiveAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript())
//		{
//			uiDetonate = 6000;
//			bomb = 3000;
//			me->CastSpell(me, SPELL_SIEGE_EXPLOSIVE_VISUAL, true);
//			isDetonateing = false;
//			SetCombatMovement(false);
//		}
//
//		uint32 uiDetonate, bomb;
//		bool isDetonateing;
//
//		void UpdateAI(uint32 const diff)
//		{
//			if (!isDetonateing && uiDetonate <= diff)
//			{
//				isDetonateing = true;
//				me->setFaction(14);
//				DoCastAOE(SPELL_SIEGE_EXPLOSIVE_DETONATE, true);
//				me->DespawnOrUnsummon(1000);
//
//			}
//			else uiDetonate -= diff;
//
//			if (!isDetonateing && bomb <= diff)
//			{
//				bomb = 3000;
//				DoCastAOE(SPELL_SIEGE_EXPLOSIVE_SUMMON, true);
//			}
//			else bomb -= diff;
//		}
//
//	private:
//		InstanceScript* _instance;
//	};
//
//	CreatureAI* GetAI(Creature *creature) const
//	{
//		return new npc_siege_explosiveAI(creature);
//	}
//};
//
//enum SikthikSoldierSpells
//{
//	SPELL_SERRATED_BLADE = 88080,
//};
//
//enum SikthikSoldierEvents
//{
//	EVENT_SERRATED_BLADE = 1,
//};
//
//// NPC value 62348
//class npc_sikthik_soldier : public CreatureScript
//{
//public:
//	npc_sikthik_soldier() : CreatureScript("npc_sikthik_soldier") { }
//
//	CreatureAI* GetAI(Creature* creature) const
//	{
//		return new npc_sikthik_soldierAI(creature);
//	}
//
//	struct npc_sikthik_soldierAI : public ScriptedAI
//	{
//		npc_sikthik_soldierAI(Creature* creature) : ScriptedAI(creature)
//		{
//			instance = creature->GetInstanceScript();
//		}
//
//		InstanceScript* instance;
//		EventMap events;
//
//		void Reset()
//		{
//			events.Reset();
//			if (MotionMaster* motion = me->GetMotionMaster())
//			{
//				if (Creature* boss = me->FindNearestCreature(61485, 100.0f, true))
//				motion->MovePoint(1, boss->GetPositionX(), boss->GetPositionY(), boss->GetPositionZ());
//			}
//		}
//
//		void EnterCombat(Unit* /*target*/)
//		{
//			events.ScheduleEvent(EVENT_SERRATED_BLADE, urand(1000, 8000));
//		}
//
//		void UpdateAI(uint32 const diff)
//		{
//			if (!UpdateVictim())
//				return;
//
//			events.Update(diff);
//
//			if (me->HasUnitState(UNIT_STATE_CASTING))
//				return;
//
//			while (uint32 eventId = events.ExecuteEvent())
//			{
//				switch (eventId)
//				{
//				case EVENT_SERRATED_BLADE:
//					DoCastVictim(SPELL_SERRATED_BLADE);
//					events.ScheduleEvent(EVENT_SERRATED_BLADE, urand(8000, 13000));
//					break;
//				default:
//					break;
//
//				
//				}
//			}
//			DoMeleeAttackIfReady();
//		}
//	};
//};
//
//
//// Id: 119377
//// Name: Siege Explosive
//class spell_siege_explosive : public SpellScriptLoader
//{
//public:
//	spell_siege_explosive() : SpellScriptLoader("spell_siege_explosive") {}
//
//	class spell_siege_explosive_SpellScript : public SpellScript
//	{
//		PrepareSpellScript(spell_siege_explosive_SpellScript);
//
//
//		void HandleSummon(SpellEffIndex effIndex)
//		{
//			PreventHitDefaultEffect(effIndex);
//			Unit* caster = GetOriginalCaster();
//			if (!caster)
//				return;
//
//			InstanceScript* instance = caster->GetInstanceScript();
//			if (!instance)
//				return;
//
//			uint32 bomb = uint32(GetSpellInfo()->Effects[effIndex].MiscValue);
//			SummonPropertiesEntry const* properties = sSummonPropertiesStore.LookupEntry(uint32(GetSpellInfo()->Effects[effIndex].MiscValueB));
//			uint32 duration = uint32(GetSpellInfo()->GetDuration());
//
//			Position pos;
//			if (Unit* boss = caster->FindNearestCreature(61485, 100, true))
//			{
//				boss->GetRandomNearPosition(pos, frand(25.f, 30.f));
//				caster->GetMap()->SummonCreature(bomb, pos, properties, duration, caster, GetSpellInfo()->Id);
//			}
//			
//		}
//
//		void Register()
//		{
//			OnEffectHit += SpellEffectFn(spell_siege_explosive_SpellScript::HandleSummon, EFFECT_0, SPELL_EFFECT_SUMMON);
//		}
//	};
//
//	SpellScript* GetSpellScript() const
//	{
//		return new spell_siege_explosive_SpellScript();
//	}
//};
//
//
//// Id: 123032
//// Name: Carrying Caustic Tar
//class spell_carrying_explosives : public SpellScriptLoader
//{
//public:
//	spell_carrying_explosives() : SpellScriptLoader("spell_carrying_explosives") { }
//
//	class spell_carrying_caustic_tar_AuraScript : public AuraScript
//	{
//		PrepareAuraScript(spell_carrying_caustic_tar_AuraScript);
//
//		void OnApply(constAuraEffectPtr /*aurEff*/, AuraEffectHandleModes /*mode*/)
//		{
//			if (GetCaster()->GetTypeId() != TYPEID_PLAYER)
//				return;
//
//			if (!GetTarget()->HasSpell(119388))
//				GetTarget()->ToPlayer()->learnSpell(119388, false);
//		}
//		void OnRemove(constAuraEffectPtr /*aurEff*/, AuraEffectHandleModes /*mode*/)
//		{
//			if (GetCaster()->GetTypeId() != TYPEID_PLAYER)
//				return;
//
//			if (GetTarget()->HasSpell(119388))
//				GetTarget()->ToPlayer()->removeSpell(119388);
//		}
//
//		void Register()
//		{
//			AfterEffectApply += AuraEffectApplyFn(spell_carrying_caustic_tar_AuraScript::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
//			AfterEffectRemove += AuraEffectRemoveFn(spell_carrying_caustic_tar_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
//		}
//	};
//
//	AuraScript* GetAuraScript() const
//	{
//		return new spell_carrying_caustic_tar_AuraScript();
//	}
//};
//class spell_explosives : public SpellScriptLoader
//{
//public:
//	spell_explosives() : SpellScriptLoader("spell_explosives") {}
//
//	class spell_player_throw_barrel_SpellScript : public SpellScript
//	{
//		PrepareSpellScript(spell_player_throw_barrel_SpellScript);
//
//		void HandleAfterCast()
//		{
//			if (!GetCaster())
//				return;
//
//			Unit* caster = GetCaster();
//
//			if (caster->GetTypeId() != TYPEID_PLAYER)
//				return;
//
//			if (SpellInfo const* spell = GetSpellInfo())
//			{
//				if (spell->Id == 119393)
//				{
//					if (caster->HasAura(119388))
//					{
//						caster->RemoveAura(119388);
//					}
//					if (caster->HasAura(119386))
//					{
//						caster->RemoveAura(119386);
//					}
//				}
//			}
//		}
//
//		void Register()
//		{
//			AfterCast += SpellCastFn(spell_player_throw_barrel_SpellScript::HandleAfterCast);
//		}
//	};
//
//	SpellScript* GetSpellScript() const
//	{
//		return new spell_player_throw_barrel_SpellScript();
//	}
//};
//void AddSC_boss_general_pavalak()
//{
//	// Boss scripts
//	new boss_general_pavalak();
//
//	// Npc scripts
//	new npc_siege_explosive();
//	new npc_sikthik_soldier();
//
//	// Spell scripts
//	new spell_siege_explosive();
//	new spell_explosives();
//	new spell_carrying_explosives();
//}
//
///******* SQL *******
//-- Texts Boss General Pa'valak
//DELETE FROM `creature_text` WHERE `entry` =61485;
//INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) values
//('61485','0','0','Niuzao\'s forces attack from the rear!','14','0','100','0','0','30279','General Pa\'valak Intro'),
//('61485','1','0','The temple will fall! You cannot stop my forces!','14','0','100','0','0','30277','General Pa\'valak Aggro'),
//('61485','2','0','My army will crush you!','14','0','100','0','0','30278','General Pa\'valak Ground Assault'),
//('61485','2','1','Stop them! Mantid attack!','14','0','100','0','0','30280','General Pa\'valak Ground Assault'),
//('61485','2','2','Put down your weapons or die!','14','0','100','0','0','30283','General Pa\'valak Ground Assault'),
//('61485','3','0','The empress demands it!','14','0','100','0','0','30285','General Pa\'valak Killing a player'),
//('61485','3','1','The forces of Niuzao are weak!','14','0','100','0','0','30286','General Pa\'valak Killing a player'),
//('61485','4','0','I have failed you, empress...','14','0','100','0','0','30284','General Pa\'valak Death');
//
//
//UPDATE `creature_template` SET `ScriptName`='npc_siege_explosive', `npcflag`='1', `flags_extra`='1', `modelid1`='15435', `scale`='0.6' WHERE (`entry`='61452');
//UPDATE `creature_template` SET `ScriptName`='npc_sikthik_soldier', `flags_extra`='1' WHERE (`entry`='62348');
//UPDATE `creature_template` SET `ScriptName`='boss_general_pavalak', `flags_extra`='1' WHERE (`entry`='61485');
//
//-- Id: 119377
//-- Name: Player Throw Barrel
//DELETE FROM `spell_script_names` WHERE `spell_id` IN (119377);
//INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
//('119377', 'spell_siege_explosive');
//*/
