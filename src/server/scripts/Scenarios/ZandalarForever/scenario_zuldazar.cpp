/*
 * Copyright (C) 2022 BfaCore Reforged
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

// #include "Creature.h"
// #include "Player.h"
// #include "ScriptMgr.h"
// #include "ScriptedCreature.h"
// #include "ScriptedGossip.h"
// #include "InstanceScript.h"
// #include "InstanceScenario.h"
// #include "Scenario.h"
// #include "Vehicle.h"
// #include "SpellInfo.h"
// #include "scenario_zuldazar.h"

//135890/king-rastakhan
// struct npc_king_rastakhan_135890 : public ScriptedAI
// {
    // npc_king_rastakhan_135890(Creature* creature) : ScriptedAI(creature) {  }

    // void sGossipSelect(Player* player, uint32 /*menuId*/, uint32 /*gossipListId*/)
    // {
        // player->TeleportTo(1906, Position(61.2f, 627.71f, 119.63f, 6.28179f));
        // CloseGossipMenuFor(player);
    // }
// };

// struct npc_old_kzlotec_134460 : public ScriptedAI
// {
    // npc_old_kzlotec_134460(Creature* creature) : ScriptedAI(creature) { instance = creature->GetInstanceScript(); }

    // bool found = false;

    // void OnSpellClick(Unit* clicker, bool& /*result*/)
    // {
        // if (Player* player = clicker->ToPlayer())
        // {
            // player->CompletedCriteriaTreeId(CRITERIA_TREE_GATHER_YOUR_FORCES_AND_MOUNT_OLD_K_ZLOTEC);
            // me->setFaction(player->getFaction()); 
            // me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
        // }
    // }

    // void PassengerBoarded(Unit* passenger, int8 /*seatId*/, bool apply)
    // {
        // if (passenger->IsPlayer())
        // {
            // passenger->SetDisableGravity(apply);

            // if (!apply)
            // {
                // passenger->ToPlayer()->SetClientControl(passenger, true);
                // me->DespawnOrUnsummon(5000);
            // }
        // }
    // }
// private:
    // InstanceScript* instance;
// };

// struct npc_blood_scenario : public ScriptedAI
// {
    // npc_blood_scenario(Creature* creature) : ScriptedAI(creature) {  }

    // void SpellHit(Unit* caster, SpellInfo const* spell) override
    // {
        // switch (spell->Id)
        // {
        // case 254981:
        // case 254970:
        // case 254971:
            // me->KillSelf();
            // break;
        // default:
            // break;
        // }
    // }
// };

//134493
// struct npc_pa_ku_134493 : public ScriptedAI
// {
    // npc_pa_ku_134493(Creature* creature) : ScriptedAI(creature)
    // {
        // instance = creature->GetInstanceScript();    
    // }

    // Position const Path01[5] =
    // {
        // { -347.22f, 609.57f, 235.73f },
        // { -76.419f, 744.976f, 201.484f },
        // { -185.34f, 1064.44f, 314.87f },
     //   { -673.75f, 701.498f, 270.958f },    
        // { -333.586f, 1166.28f, 343.88f },
        // { -407.2205f, 1189.813f, 327.36f },
    // };
    // using Path01Size = std::extent<decltype(Path01)>;
    // ObjectGuid _guid;

    // void Reset() override
    // {
        // me->SetReactState(REACT_PASSIVE);
        // me->SetCanFly(true);
        // me->SetDisableGravity(true);
        // me->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
    // }

    // void OnSpellClick(Unit* clicker, bool& /*result*/)
    // {
        // if (Player* player = clicker->ToPlayer())
        // {
            // me->RemoveNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
            // player->CastSpell(me, 46598, true);
            // _guid = player->GetGUID();
        // }
    // }

    // void PassengerBoarded(Unit* passenger, int8 /*seatId*/, bool apply)
    // {
        // if (passenger->IsPlayer())
        // {
            // passenger->SetDisableGravity(apply);
            // if (apply)
                // me->GetMotionMaster()->MoveSmoothPath(1, Path01, Path01Size::value, false, true);
        // }
    // }
  //  46598
    // void MovementInform(uint32 type, uint32 id) override
    // {
        // if (type == EFFECT_MOTION_TYPE && id == 1)
        // {
            // if(Player* player= ObjectAccessor::GetPlayer(*me, _guid))
                // player->CompletedCriteriaTreeId(CRITERIA_TREE_RIDE_PA_KU_TO_THE_ZOCALO);
            // me->DespawnOrUnsummon(1000);
        // }
    // }
// private:
    // InstanceScript* instance;
// };


//136355,136356,136357,136358,136359,136360,136367,136368,136369,136370,136371,136372,142818
// struct npc_scenario_civilians_resued : public ScriptedAI
// {
    // npc_scenario_civilians_resued(Creature* creature) : ScriptedAI(creature) { instance = creature->GetInstanceScript(); }

    // void Reset() override
    // {
    // }

    // void sGossipSelect(Player* player, uint32 /*menuId*/, uint32 /*gossipListId*/)
    // {
        // CloseGossipMenuFor(player);
        // if (!isResued)
        // {
            // isResued = true;
            // if (instance)
                // instance->SetData(SCENARIO_EVENT_CIVILIANS_RESCUED, 1);
            // me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
            // me->DespawnOrUnsummon();
        // }

        // return;
    // }

// private:
    // InstanceScript* instance;
    // bool isResued = false;
// };

// struct npc_gonk_134492 : public ScriptedAI
// {
    // npc_gonk_134492(Creature* creature) : ScriptedAI(creature)
    // {
        // instance = creature->GetInstanceScript();
        // IsLock = false;
    // }

    // void MoveInLineOfSight(Unit* who) override
    // {
        // if (Player* player = who->ToPlayer())
        // {
            // if (me->IsWithinDist(player, 15.0f, false) && !IsLock)
            // {
                // IsLock = true;
               
                // player->CompletedCriteriaTreeId(CRITERIA_TREE_JOIN_GONK_AND_HIS_PACK_AT_THE_BRIDGE_TO_DAZAR_ALOR);

                // if (instance)
                // {
                    // instance->DoPlayScenePackageIdOnPlayers(SCENE_3);
                    // instance->DoSendScenarioEventByType(CRITERIA_TYPE_KILL_CREATURE, me->GetEntry(), 1);
                // }
            // }
        // }
    // }
// private:
    // InstanceScript* instance;
// };


// struct npc_king_rastakhan_136324 : public ScriptedAI
// {
    // npc_king_rastakhan_136324(Creature* creature) : ScriptedAI(creature)
    // {
        // instance = creature->GetInstanceScript();
        // IsLock = false;
    // }

    // enum king_rastakhan_Spells
    // {
        // SPELL_LOA_STRIKE = 272826,
    // };
    // void EnterCombat(Unit* /*victim*/) override
    // {
        // events.ScheduleEvent(SPELL_LOA_STRIKE, 5s);
    // }

    // void UpdateAI(uint32 diff) override
    // {
        // if (!UpdateVictim())
            // return;
        // if (me->HasUnitState(UNIT_STATE_CASTING))
            // return;
        // events.Update(diff);
        // switch (events.ExecuteEvent())
        // {
        // case SPELL_LOA_STRIKE:
        // {
            // DoCast(SPELL_LOA_STRIKE);
            // events.Repeat(6s);
            // break;
        // }
        // }
        // DoMeleeAttackIfReady();
    // }

    // void MoveInLineOfSight(Unit* who) override
    // {
        // if (Player* player = who->ToPlayer())
        // {
            // if (me->IsWithinDist(player, 15.0f, false) && !IsLock)
            // {
                // IsLock = true;
                // if (instance)
                // {
                    // instance->DoPlayConversation(7434);
                    // instance->DoSendScenarioEvent(SCENARIO_EVENT_FIND_KING_RASTAKHAN_AT_THE_ENTRANCE_TO_DAZAR_ALOR);
                    // player->CompletedCriteriaTreeId(CRITERIA_TREE_FIND_KING_RASTAKHAN_AT_THE_ENTRANCE_TO_DAZAR_ALOR);
                // }
                // me->GetScheduler().Schedule(10s, [=](TaskContext /*context*/)
                // {
                    // me->SetHomePosition(Position(-825.56f, 970.363f, 320.82f, 0.8f));
                    // me->GetMotionMaster()->MovePoint(1, Position(-825.56f, 970.363f, 320.82f, 0.8f), true);
                // });
            // }
        // }
    // }
// private:
    // InstanceScript* instance;
// };

// struct npc_warlord_kara_na_131018 : public ScriptedAI
// {
    // npc_warlord_kara_na_131018(Creature* creature) : ScriptedAI(creature) { instance = creature->GetInstanceScript(); }

    // enum warlord_kara_na_Spells
    // {
        // SPELL_DEVASTATING_SLAM = 224664,
        // SPELL_HEAD_TAKER = 260065,
        // SPELL_IMBUE_LIGHTNING = 269234,
    // };

    // void EnterCombat(Unit* /*victim*/) override
    // {
        // events.ScheduleEvent(SPELL_DEVASTATING_SLAM, 5s);
        // events.ScheduleEvent(SPELL_HEAD_TAKER, 10s);
        // events.ScheduleEvent(SPELL_IMBUE_LIGHTNING, 15s);
    // }

    // void UpdateAI(uint32 diff) override
    // {
        // if (!UpdateVictim())
            // return;
        // if (me->HasUnitState(UNIT_STATE_CASTING))
            // return;
        // events.Update(diff);
        // switch (events.ExecuteEvent())
        // {

        // case SPELL_DEVASTATING_SLAM:
        // {
            // DoCast(SPELL_DEVASTATING_SLAM);
            // events.Repeat(12s);
            // break;
        // }
        // case SPELL_HEAD_TAKER:
        // {
            // DoCast(SPELL_HEAD_TAKER);
            // events.Repeat(11s);
            // break;
        // }
        // case SPELL_IMBUE_LIGHTNING:
        // {
            // DoCast(SPELL_IMBUE_LIGHTNING);
            // events.Repeat(12s);
            // break;
        // }
        // }
        // DoMeleeAttackIfReady();
    // }

    // void JustDied(Unit* /*killer*/) override
    // {
        // Talk(0);
    // }

// private:
    // InstanceScript* instance;
// };

// struct npc_mada_renkala_142765 : public ScriptedAI
// {
    // npc_mada_renkala_142765(Creature* creature) : ScriptedAI(creature) { instance = creature->GetInstanceScript(); }

    // enum mada_renkala_Spells
    // {
        // SPELL_GURGLING_BLOOD = 278781,
        // SPELL_GURGLING_BLOOD_AT = 278783,
        // SPELL_GURGLING_BLOOD_DMG = 278788,
        // SPELL_SANGUINE_ERUPTION = 278853,
        // SPELL_SIPHON_BLOOD = 255220,
    // };

    // void EnterCombat(Unit* /*victim*/) override
    // {
        // Talk(0);
        // events.ScheduleEvent(SPELL_SIPHON_BLOOD, 5s);
        // events.ScheduleEvent(SPELL_GURGLING_BLOOD, 10s);
        // events.ScheduleEvent(SPELL_SANGUINE_ERUPTION, 15s);    
    // }

    // void UpdateAI(uint32 diff) override
    // {
        // if (!UpdateVictim())
            // return;
        // if (me->HasUnitState(UNIT_STATE_CASTING))
            // return;
        // events.Update(diff);
        // switch (events.ExecuteEvent())
        // {
        // case SPELL_SIPHON_BLOOD:
        // {
            // DoCast(SPELL_SIPHON_BLOOD);
            // events.Repeat(17s);
            // break;
        // }
        // case SPELL_GURGLING_BLOOD:
        // {
            // DoCast(SPELL_GURGLING_BLOOD);
            // events.Repeat(16s);
            // break;
        // }
        // case SPELL_SANGUINE_ERUPTION:
        // {
            // DoCast(SPELL_SANGUINE_ERUPTION);
            // events.Repeat(18s);
            // break;
        // }
        // }
        // DoMeleeAttackIfReady();
    // }

    // void JustDied(Unit* /*killer*/) override
    // {
        // instance->DoOnPlayers([](Player* player)
        // {
            // player->CompletedCriteriaTreeId(CRITERIA_TREE_ASSAULT_DAZAR_ALOR_TO_REACH_ZUL_BEFORE_HE_CAN_DESTROY_THE_PYRAMID);
        // });
    // }

// private:
    // InstanceScript* instance;
// };
//278857 Sanguine Eruption ->278848 Sanguine Eruption

// struct npc_rastari_spirit_136384 : public ScriptedAI
// {
    // npc_rastari_spirit_136384(Creature* creature) : ScriptedAI(creature) { }

    // bool isSaved = false;

    // void Reset() override
    // {
        // if (isSaved)
            // me->RemoveAurasDueToSpell(257852);
    // }

    // void SetData(uint32 /*id*/, uint32 /*value*/) override
    // {
        // isSaved = true;
        // me->RemoveAurasDueToSpell(257852);
        // me->SetHomePosition(Position(-825.56f, 970.363f, 320.82f, 0.8f));
        // me->GetMotionMaster()->MovePoint(1, Position(-825.56f, 970.363f, 320.82f, 0.8f), true);
    // }
// };
// void AddSC_scenario_zuldazar()
// {
    // RegisterCreatureAI(npc_king_rastakhan_135890);
    // RegisterCreatureAI(npc_old_kzlotec_134460);
    // RegisterCreatureAI(npc_blood_scenario);
    // RegisterCreatureAI(npc_pa_ku_134493);
    // RegisterCreatureAI(npc_scenario_civilians_resued);
    // RegisterCreatureAI(npc_gonk_134492);
    // RegisterCreatureAI(npc_king_rastakhan_136324);
    // RegisterCreatureAI(npc_warlord_kara_na_131018);
    // RegisterCreatureAI(npc_mada_renkala_142765);
    // RegisterCreatureAI(npc_rastari_spirit_136384);
// }
