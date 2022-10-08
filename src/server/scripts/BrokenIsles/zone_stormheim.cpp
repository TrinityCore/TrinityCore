/*
* Copyright (C) 2021 BfaCore Reforged
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
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"
#include "SpellScript.h"
#include "SpellMgr.h"
#include "Player.h"
#include "QuestPackets.h"
#include "ScenePackets.h"
#include "GameObjectAI.h"
#include "ObjectAccessor.h"
#include "SpellAuras.h"
#include "LFGMgr.h"
#include "MotionMaster.h"
#include "ObjectMgr.h"

// 240600 - Volatile Barrel
class go_volatile_barrel_stormheim : public GameObjectScript
{
public:
    go_volatile_barrel_stormheim() : GameObjectScript("go_volatile_barrel_stormheim") { }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(181981);

        player->SetPower(POWER_ALTERNATE_POWER, player->GetPower(POWER_ALTERNATE_POWER) + spellInfo->GetEffect(EFFECT_0)->BasePoints);

        for (int32 i = 0; i < spellInfo->GetEffect(EFFECT_0)->BasePoints; ++i)
            player->KilledMonsterCredit(91693, ObjectGuid::Empty);

        if (player->GetPower(POWER_ALTERNATE_POWER) >= 100)
            player->CastSpell(player, 181981, true);

        return true;
    }
};

class npc_grapple_point : public CreatureScript
{
public:
    npc_grapple_point() : CreatureScript("npc_grapple_point") { }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (player->GetQuestStatus(38613) == QUEST_STATUS_INCOMPLETE)
        {
            player->CastSpell(creature, 182467, true);
            player->GetMotionMaster()->MoveJump(creature->GetPosition(), 15.0f, 15.0f, 0, false);
            player->KilledMonsterCredit(91484, ObjectGuid::Empty);
        }
        return true;
    }
};

// 181981
class spell_pump : public SpellScriptLoader
{
public:
    spell_pump() : SpellScriptLoader("spell_pump") { }

    class spell_pump_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pump_SpellScript);

        void HandleEnergize(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
            {
                caster->EnergizeBySpell(caster, GetSpellInfo()->Id, GetSpellInfo()->GetEffect(EFFECT_0)->BasePoints, POWER_ALTERNATE_POWER);
                if (Quest const* quest = sObjectMgr->GetQuestTemplate(38358))
                    for (QuestObjective const& obj : quest->GetObjectives())
                        if (obj.ObjectID == 91590)
                        {
                            caster->ToPlayer()->SetQuestObjectiveData(obj, 1);
                            caster->ToPlayer()->SendQuestUpdateAddCredit(quest, ObjectGuid::Empty, obj, 1);
                        }

                if (caster->GetPower(POWER_ALTERNATE_POWER) >= 100)
                    caster->ToPlayer()->KilledMonsterCredit(91590, ObjectGuid::Empty);

                if (caster->ToPlayer()->CanCompleteQuest(38358))
                    caster->ToPlayer()->CompleteQuest(38358);
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_pump_SpellScript::HandleEnergize, EFFECT_0, SPELL_EFFECT_KILL_CREDIT);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pump_SpellScript();
    }
};

struct npc_apothecary_withers_91590 : public ScriptedAI
{
    npc_apothecary_withers_91590(Creature* creature) : ScriptedAI(creature) { }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == 38358)
            player->CastSpell(player, 181970, true);
    }

    void sQuestReward(Player* player, Quest const* quest, uint32 /*opt*/)  override
    {
        if (quest->GetQuestId() == 38358)
            player->RemoveAurasDueToSpell(181970);
    }
};

// 180645/transponder_pack
class spell_transponder_pack_180645 : public SpellScriptLoader
{
public:
    spell_transponder_pack_180645() : SpellScriptLoader("spell_transponder_pack_180645") { }

    class spell_transponder_pack_180645_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_transponder_pack_180645_AuraScript);

        void OnPeriodic(AuraEffect const* aurEff)
        {
            if (Unit* caster = GetCaster())
            {
                if (caster->ToPlayer()->GetQuestStatus(38058) == QUEST_STATUS_INCOMPLETE)
                {
                    if (caster->GetPower(POWER_ALTERNATE_POWER) > caster->ToPlayer()->GetQuestObjectiveData(38058, 1))
                        for (int32 i = 0; i < (std::min(caster->GetPower(POWER_ALTERNATE_POWER), 100) - caster->ToPlayer()->GetQuestObjectiveData(38058, 1)); ++i)
                            caster->ToPlayer()->KilledMonsterCredit(90903, ObjectGuid::Empty);

                    if (caster->GetPower(POWER_ALTERNATE_POWER) >= 100)
                        caster->ToPlayer()->KilledMonsterCredit(90866, ObjectGuid::Empty);

                    if (caster->ToPlayer()->CanCompleteQuest(38058))
                    {
                        caster->ToPlayer()->CompleteQuest(38058);
                        caster->ToPlayer()->SetPower(POWER_ALTERNATE_POWER, 0);
                    }
                }
            }
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_transponder_pack_180645_AuraScript::OnPeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_transponder_pack_180645_AuraScript();
    }
};

struct npc_titan_console_96139 : public ScriptedAI
{
    npc_titan_console_96139(Creature* creature) : ScriptedAI(creature) {  }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(player, 15.0f, false))
            {
                if (!IsLock && player->HasQuest(39592) && player->GetQuestStatus(39592) == QUEST_STATUS_INCOMPLETE)
                {
                    IsLock = true;
                    Talk(0);
                    me->GetScheduler().Schedule(Milliseconds(5000), [this, player](TaskContext context)
                    {
                        Talk(1);
                    });
                    SetUnlock(120000);
                }
            }
        }
    }
};
//96122
//243802 Powered Console
class go_powered_console_stormheim_243802 : public GameObjectScript
{
public:
    go_powered_console_stormheim_243802() : GameObjectScript("go_powered_console_stormheim_243802") { }
    bool OnGossipHello(Player* player, GameObject* go) override
    {
        if (Creature* drugen = player->SummonCreature(96067, Position(3333.486f, 2230.95f, 315.7818f, 4.712389f), TEMPSUMMON_MANUAL_DESPAWN))
        {
            if (Creature* npc = player->SummonCreature(96144, Position(3333.486f, 2230.95f, 315.7818f, 4.712389f), TEMPSUMMON_MANUAL_DESPAWN))
            {
                drugen->AddAura(190758);
                drugen->AddAura(190549);

                npc->CastSpell(npc, 190715, true);
                drugen->DespawnOrUnsummon(30000);
                npc->DespawnOrUnsummon(30000);
            }
        }

        player->CastSpell(player, 197658, true);
        player->GetScheduler().Schedule(Milliseconds(5000), [player](TaskContext context)
        {
            player->CastSpell(player, 197659, true);
        });
        player->GetScheduler().Schedule(Milliseconds(10000), [player](TaskContext context)
        {
            player->CastSpell(player, 197660, true);
        });
        player->GetScheduler().Schedule(Milliseconds(15000), [player](TaskContext context)
        {
            player->CastSpell(player, 197661, true);
        });
        player->GetScheduler().Schedule(Milliseconds(20000), [player](TaskContext context)
        {
            player->CastSpell(player, 197662, true);
        });
        player->GetScheduler().Schedule(Milliseconds(25000), [player](TaskContext context)
        {
            player->CastSpell(player, 197663, true);
        });
        return true;
    }
};
//243817
class go_powered_console_stormheim_243817 : public GameObjectScript
{
public:
    go_powered_console_stormheim_243817() : GameObjectScript("go_powered_console_stormheim_243817") { }
    bool OnGossipHello(Player* player, GameObject* go) override
    {
        if (Creature* npc = player->SummonCreature(96176, Position(3546.223f, 2163.617f, 233.61f, 3.11f), TEMPSUMMON_MANUAL_DESPAWN))
        {
            npc->AI()->Talk(0);
            npc->DespawnOrUnsummon(30000);
        }
        if (Creature* yotnar = player->FindNearestCreature(96175, 100.0f, true))
        {
            player->GetScheduler().Schedule(Milliseconds(5000), [yotnar](TaskContext context)
            {
                yotnar->AI()->Talk(0);
            });
            player->GetScheduler().Schedule(Milliseconds(10000), [yotnar](TaskContext context)
            {
                yotnar->AI()->Talk(1);
            });
            player->GetScheduler().Schedule(Milliseconds(15000), [yotnar, player](TaskContext context)
            {
                yotnar->AI()->Talk(2);
                player->CastSpell(player, 190908, true);

                yotnar->SetReactState(REACT_AGGRESSIVE);
                yotnar->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC));
            });
        }
        return true;
    }
};

struct npc_yotnar_96258 : public ScriptedAI
{
    npc_yotnar_96258(Creature* creature) : ScriptedAI(creature) { }

    void sGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId)
    {
        CloseGossipMenuFor(player);
        player->TalkedToCreature(me->GetEntry(), me->GetGUID());

        if (player->HasQuest(39597))
        {
            player->KilledMonsterCredit(96285);
            Talk(2);
            player->GetScheduler().Schedule(Milliseconds(5000), [this](TaskContext context)
            {
                Talk(3);
            });
        }
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(player, 25.0f, false))
            {
                if (!IsLock && player->HasQuest(39594) && player->GetQuestStatus(39594) == QUEST_STATUS_COMPLETE)
                {
                    IsLock = true;
                    Talk(0);
                    player->GetScheduler().Schedule(Milliseconds(5000), [this](TaskContext context)
                    {
                        Talk(1);
                    });
                    SetUnlock(60000);
                }
            }
        }
    }
};

struct npc_yotnar_96175 : public ScriptedAI
{
    npc_yotnar_96175(Creature* creature) : ScriptedAI(creature) { }

    enum yotnar_96175_Spells
    {
        SPELL_ACTIVATE_GUARDIAN_ORB = 195765,
        SPELL_LIGHTFORGED_DEFENSE_MATRIX = 195799,
    };

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);
        me->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC));
    }

    void DamageTaken(Unit* done_by, uint32 &damage) override
    {
        if (me->HealthWillBeBelowPctDamaged(10, damage))
        {
            damage = 0;
            me->SetHealth(me->GetMaxHealth());
            me->AttackStop();
            events.Reset();
            me->SetReactState(REACT_PASSIVE);
            me->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC));
            Talk(3);
            me->GetMotionMaster()->MoveTargetedHome();
            me->GetScheduler().Schedule(Milliseconds(5000), [this](TaskContext context)
            {
                Talk(4);
            });
            me->GetScheduler().Schedule(Milliseconds(10000), [this](TaskContext context)
            {
                Talk(5);
            });

            std::list<Player*> list;
            me->GetPlayerListInGrid(list, 100.0f);
            if (!list.empty())
                for (Player* player : list)
                    player->KilledMonsterCredit(me->GetEntry());
        }
    }

    void EnterCombat(Unit* /*attacker*/) override
    {
        events.ScheduleEvent(SPELL_ACTIVATE_GUARDIAN_ORB, 5s);
        events.ScheduleEvent(SPELL_LIGHTFORGED_DEFENSE_MATRIX, 5s);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;
        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;
        events.Update(diff);
        switch (events.ExecuteEvent())
        {
        case SPELL_ACTIVATE_GUARDIAN_ORB:
        {
            DoCast(SPELL_ACTIVATE_GUARDIAN_ORB);
            events.Repeat(15s);
            break;
        }
        case SPELL_LIGHTFORGED_DEFENSE_MATRIX:
        {
            DoCast(SPELL_LIGHTFORGED_DEFENSE_MATRIX);
            events.Repeat(15s);
            break;
        }
        }
        DoMeleeAttackIfReady();
    }
};

struct npc_vault_guardian_96282 : public ScriptedAI
{
    npc_vault_guardian_96282(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        SetCombatMovement(false);
        me->SetReactState(REACT_PASSIVE);
        me->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC));
        me->AddUnitState(UNIT_STATE_CANNOT_TURN);
    }
};

class stormheimOnCastSpellByPlayers : public PlayerScript
{
public:
    stormheimOnCastSpellByPlayers() : PlayerScript("stormheimOnCastSpellByPlayers") { }

    void OnSpellCast(Player* player, Spell* spell, bool /*skipCheck*/) override
    {
        //printf("spell = %d\n", spell->GetSpellInfo()->Id);
    }

    void OnQuestAccept(Player* player, Quest const* quest)
    {
        if (quest->ID == 38612)
            player->ForceCompleteQuest(38612);
    }
};

struct npc_grapple_point_92017 : public ScriptedAI
{
    npc_grapple_point_92017(Creature* creature) : ScriptedAI(creature) {  }

    void Reset() override
    {
        me->SetDisplayId(62719);
        me->AddUnitFlag(UnitFlags(UNIT_NPC_FLAG_SPELLCLICK));
        me->setActive(true);
    }

    void OnSpellClick(Unit* clicker, bool& /*result*/)
    {
        if (Player* player = clicker->ToPlayer())
        {
            player->SetFacingToObject(me);
            if (player->HasQuest(38613))
                player->KilledMonsterCredit(91484);
            if (player->HasQuest(38618) || player->HasQuest(38412))
                player->KilledMonsterCredit(91728);
            player->CastSpell(player, 182546, true);
            me->GetScheduler().Schedule(Milliseconds(2000), [this, player](TaskContext context)
            {
                player->CastSpell(me, 182549, true);
                player->GetMotionMaster()->MoveJump(me->GetPosition(), 20.0f, 20.0f);
            });
        }
    }
};

struct npc_dread_rider_cullen_92566 : public ScriptedAI
{
    npc_dread_rider_cullen_92566(Creature* creature) : ScriptedAI(creature) {  }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(player, 15.0f, false))
            {
                if (!IsLock && player->HasQuest(38612))
                {
                    IsLock = true;
                    Talk(0);
                    SetUnlock(120000);
                }
            }
        }
    }
};

struct npc_vethir_91249 : public ScriptedAI
{
    npc_vethir_91249(Creature* creature) : ScriptedAI(creature) {  }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(player, 15.0f, false))
            {
                if (player->HasQuest(38618) || player->HasQuest(38412))
                    player->KilledMonsterCredit(91729);
            }
        }
    }
};

struct npc_vethir_96465 : public ScriptedAI
{
    npc_vethir_96465(Creature* creature) : ScriptedAI(creature) {  }

    Position const Path01[3] =
    {
        { 1977.46f, 2551.438f, 499.0977f },
        { 2007.181f, 2538.161f, 505.5903f },
        { 2080.953f, 2639.094f, 676.9411f },
    };
    using Path01Size = std::extent<decltype(Path01)>;

    void sGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId)
    {
        CloseGossipMenuFor(player);
        player->TalkedToCreature(me->GetEntry(), me->GetGUID());
        if (player->HasQuest(39652) || player->GetQuestStatus(39652) == QUEST_STATUS_REWARDED)
        {
            player->SummonCreature(96465, me->GetPosition());
            player->GetScheduler().Schedule(Milliseconds(18000), [this, player](TaskContext context)
            {
                player->RemoveAurasDueToSpell(46598);
                player->KilledMonsterCredit(96466);
                player->ExitVehicle();
            });
        }
    }

    void PassengerBoarded(Unit* who, int8 seatId, bool apply) override
    {
        if (apply)
        {
            me->SetCanFly(true);
            me->SetFlying(true);
            me->SetWalk(false);
            me->SetSpeed(MOVE_FLIGHT, 25);
            me->GetMotionMaster()->MoveSmoothPath(1, Path01, Path01Size::value, false, true);
            me->DespawnOrUnsummon(20000);
        }
    }

    void IsSummonedBy(Unit* summoner) override
    {
        if (summoner)
            summoner->CastSpell(me, 46598);
    }
};

struct npc_thrymjaris_97061 : public ScriptedAI
{
    npc_thrymjaris_97061(Creature* creature) : ScriptedAI(creature) {  }

    void sGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId)
    {
        CloseGossipMenuFor(player);
        player->TalkedToCreature(me->GetEntry(), me->GetGUID());
        if (player->HasQuest(39652))
        {
            Talk(0);
            me->GetScheduler().Schedule(Milliseconds(5000), [this, player](TaskContext context)
            {
                Talk(1);
            });
            me->GetScheduler().Schedule(Milliseconds(10000), [this, player](TaskContext context)
            {
                Talk(2);
                player->KilledMonsterCredit(96467);
            });
        }
    }
};
//92218  
struct npc_thrymjaris_92218 : public ScriptedAI
{
    npc_thrymjaris_92218(Creature* creature) : ScriptedAI(creature) {  }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == 38624)
            Talk(0);
    }
};

struct npc_vethir_92302 : public ScriptedAI
{
    npc_vethir_92302(Creature* creature) : ScriptedAI(creature) {  }

    Position const Path_92302[3] =
    {
        { 2140.182f, 2582.83f, 650.22f },
        { 2447.208f, 2420.543f, 330.0511f },
        { 2740.932f, 2588.307f, 293.2005f },
    };
    using Path_92302Size = std::extent<decltype(Path_92302)>;

    Position const Path02[4] =
    {
        { 3077.25f, 2280.743f, 226.4515f },
        { 3077.25f, 2280.743f, 226.4515f },
        { 3077.25f, 2280.743f, 236.4515f },
        { 3052.059f, 2302.337f, 263.388f },
    };
    using Path02Size = std::extent<decltype(Path02)>;

    void Reset() override
    {
        _playerGuid = ObjectGuid::Empty;
    }

    void IsSummonedBy(Unit* summoner) override
    {
        if (summoner)
        {
            _playerGuid = summoner->ToPlayer()->GetGUID();
            me->SetCanFly(true);
            me->SetFlying(true);
            me->SetWalk(false);
            //summoner->CastSpell(me, 46598);
            me->SetSpeed(MOVE_FLIGHT, 25);
            me->GetMotionMaster()->Clear();
            Talk(1);
            if (summoner->ToPlayer()->HasQuest(38624) || summoner->ToPlayer()->HasQuest(41950) || summoner->ToPlayer()->HasQuest(41451))
            {
                me->GetMotionMaster()->MoveSmoothPath(1, Path_92302, Path_92302Size::value, false, true);
                summoner->EnterVehicle(me, 0);
                summoner->GetScheduler().Schedule(Milliseconds(30000), [this, summoner](TaskContext context)
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGuid))
                    {
                        if (!player->IsInWorld())
                            return;

                        if (player->HasQuest(38624) && player->GetQuestObjectiveData(38624, 3) == 150)
                        {
                            player->KilledMonsterCredit(91768);
                            Talk(2);
                            events.Reset();
                            context.CancelAll();
                            summoner->GetScheduler().CancelAll();
                            me->GetMotionMaster()->Clear();
                            me->GetMotionMaster()->MoveSmoothPath(99, Path02, Path02Size::value, false, true);
                            return;
                        }
                        else if (player->HasQuest(41950) && player->GetQuestObjectiveData(41950, 3) == 50)
                        {
                            player->KilledMonsterCredit(91768);
                            Talk(2);
                            events.Reset();
                            context.CancelAll();
                            me->GetMotionMaster()->Clear();
                            me->GetMotionMaster()->MoveSmoothPath(99, Path02, Path02Size::value, false, true);
                            return;
                        }
                        else if (player->HasQuest(41451) && player->GetQuestObjectiveData(41451, 0) == 15 && player->GetQuestObjectiveData(41451, 2) == 4)
                        {
                            events.Reset();
                            context.CancelAll();
                            me->GetMotionMaster()->Clear();
                            me->GetMotionMaster()->MoveSmoothPath(99, Path02, Path02Size::value, false, true);
                            return;
                        }

                        if (player->HasQuest(38624) && player->GetQuestObjectiveData(38624, 3) < 150)
                        {
                            Talk(1);
                            me->SetCanFly(true);
                            me->SetFlying(true);
                            me->SetWalk(false);
                            me->GetMotionMaster()->Clear();
                            me->GetMotionMaster()->MoveSmoothPath(1, Path_92302, Path_92302Size::value, false, true);
                        }
                        else if (player->HasQuest(41950) && player->GetQuestObjectiveData(41950, 3) < 50)
                        {
                            Talk(1);
                            me->SetCanFly(true);
                            me->SetFlying(true);
                            me->SetWalk(false);
                            me->GetMotionMaster()->Clear();
                            me->GetMotionMaster()->MoveSmoothPath(1, Path_92302, Path_92302Size::value, false, true);
                        }
                        else if (player->HasQuest(41451) && player->GetQuestObjectiveData(41451, 0) != 15 && player->GetQuestObjectiveData(41451, 2) != 4)
                        {
                            Talk(1);
                            me->SetCanFly(true);
                            me->SetFlying(true);
                            me->SetWalk(false);
                            me->GetMotionMaster()->Clear();
                            me->GetMotionMaster()->MoveSmoothPath(1, Path_92302, Path_92302Size::value, false, true);
                        }
                    }
                    context.Repeat(Milliseconds(25000));
                });
            }
            else
            {
                me->SetSpeed(MOVE_FLIGHT, 36);
                me->GetMotionMaster()->Clear();
                me->GetMotionMaster()->MoveSmoothPath(99, Path02, Path02Size::value, false, true);
                summoner->EnterVehicle(me, 0);
                me->DespawnOrUnsummon(40000);
                Talk(2);
            }

        }
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player1 = who->ToPlayer())
        {
            if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGuid))
            {
                if (me->GetDistance2d(player) > 15.0f)
                {
                    player->GetScheduler().CancelAll();
                    me->DespawnOrUnsummon();
                }
            }
        }
    }
    ObjectGuid _playerGuid;
};

struct npc_vethir_91767 : public ScriptedAI
{
    npc_vethir_91767(Creature* creature) : ScriptedAI(creature) {  }

    void OnSpellClick(Unit* clicker, bool& /*result*/)
    {
        if (Player* player = clicker->ToPlayer())
        {
            if (player->GetQuestStatus(38624) == QUEST_STATUS_INCOMPLETE || player->GetQuestStatus(41950) == QUEST_STATUS_INCOMPLETE)
            {
                player->TalkedToCreature(me->GetEntry(), me->GetGUID());
                player->KilledMonsterCredit(me->GetEntry());
                player->KilledMonsterCredit(105490);
            }
        }
    }
};
//251257 Tideskorn Harpoon Launcher kill 113891
class go_tideskorn_harpoon_launcher_251257 : public GameObjectScript
{
public:
    go_tideskorn_harpoon_launcher_251257() : GameObjectScript("go_tideskorn_harpoon_launcher_251257") { }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        if (!player || !go)
            return false;

        if (player->HasQuest(41451))
            player->KilledMonsterCredit(113891);
        return false;
    }
};

struct npc_havi_92539 : public ScriptedAI
{
    npc_havi_92539(Creature* creature) : ScriptedAI(creature) {  }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == 39804)
        {
            Talk(0);
            me->GetScheduler().Schedule(Milliseconds(5000), [this](TaskContext context)
            {
                Talk(1);
            });
            me->GetScheduler().Schedule(Milliseconds(10000), [this](TaskContext context)
            {
                Talk(2);
            });
            me->GetScheduler().Schedule(Milliseconds(15000), [this](TaskContext context)
            {
                Talk(3);
            });
        }
        if (quest->GetQuestId() == 40078)
        {
            Talk(4);
            me->GetScheduler().Schedule(Milliseconds(5000), [this](TaskContext context)
            {
                Talk(5);
            });
            me->GetScheduler().Schedule(Milliseconds(10000), [this](TaskContext context)
            {
                Talk(6);
            });
        }
    }

    void sQuestReward(Player* player, Quest const* quest, uint32 /*opt*/)  override
    {
        if (quest->GetQuestId() == 40078)
            Talk(7);
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(player, 15.0f, false))
            {
                if (!IsLock && player->HasQuest(39803))
                {
                    IsLock = true;
                    me->Say(98439);
                    me->GetScheduler().Schedule(Milliseconds(5000), [this](TaskContext context)
                    {
                        me->Say(98440);
                    });
                    me->GetScheduler().Schedule(Milliseconds(10000), [this](TaskContext context)
                    {
                        me->Say(98441);
                    });
                    me->GetScheduler().Schedule(Milliseconds(15000), [this](TaskContext context)
                    {
                        me->Say(98442);
                    });
                    SetUnlock(120000);
                }
            }
        }
    }
};

struct npc_ironhorn_buck_98230 : public ScriptedAI
{
    npc_ironhorn_buck_98230(Creature* creature) : ScriptedAI(creature) {  }

    void Reset() override
    {
        me->AddUnitFlag(UnitFlags(UNIT_NPC_FLAG_SPELLCLICK));
    }

    void OnSpellClick(Unit* clicker, bool& /*result*/)
    {
        if (Player* player = clicker->ToPlayer())
            if (player->GetQuestStatus(39804) == QUEST_STATUS_INCOMPLETE)
                player->KilledMonsterCredit(97340);
    }
};

struct npc_vydhar_93231 : public ScriptedAI
{
    npc_vydhar_93231(Creature* creature) : ScriptedAI(creature) {  }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(player, 15.0f, false))
            {
                if (!IsLock && player->HasQuest(39796))
                {
                    IsLock = true;
                    Talk(0);
                    SetUnlock(120000);
                }
            }
        }
    }
};

struct npc_runestone_93343 : public ScriptedAI
{
    npc_runestone_93343(Creature* creature) : ScriptedAI(creature) {  }

    void Reset() override
    {
        me->AddUnitFlag(UnitFlags(UNIT_NPC_FLAG_SPELLCLICK));
    }

    void OnSpellClick(Unit* clicker, bool& /*result*/)
    {
        if (Player* player = clicker->ToPlayer())
        {
            if (player->GetQuestStatus(38778) == QUEST_STATUS_INCOMPLETE)
            {
                player->KilledMonsterCredit(93196);
                switch (me->GetEntry())
                {
                case 93182:
                    player->KilledMonsterCredit(93185);
                    break;
                case 93343:
                    player->KilledMonsterCredit(93341);
                    break;
                case 93342:
                    player->KilledMonsterCredit(93340);
                    break;
                default:
                    break;
                }
            }
        }
    }
};
//191993/returning-spirit
class spell_returning_spirit_quest_39791 : public SpellScript
{
    PrepareSpellScript(spell_returning_spirit_quest_39791);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
            if (Unit* target = GetExplTargetUnit())
                if (target->GetEntry() == 93094)
                {
                    target->RemoveAura(191995);
                    caster->ToPlayer()->KilledMonsterCredit(97254);
                    target->KillSelf();
                }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_returning_spirit_quest_39791::HandleDummy, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
    }
};
//244450 Rune of Reformation
class go_rune_of_reformation_244450 : public GameObjectScript
{
public:
    go_rune_of_reformation_244450() : GameObjectScript("go_rune_of_reformation_244450") { }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        if (!player || !go)
            return false;

        if (player->HasQuest(38815))
            player->KilledMonsterCredit(97281);
        return false;
    }
};

struct npc_lady_sylvanas_windrunner_97695 : public ScriptedAI
{
    npc_lady_sylvanas_windrunner_97695(Creature* creature) : ScriptedAI(creature) {  }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(player, 15.0f, false))
            {
                if (!IsLock && player->HasQuest(39848))
                {
                    IsLock = true;
                    player->KilledMonsterCredit(97696);
                    Talk(0);
                    me->GetScheduler().Schedule(Milliseconds(5000), [this, player](TaskContext context)
                    {
                        Talk(1);
                    });
                    me->GetScheduler().Schedule(Milliseconds(10000), [this, player](TaskContext context)
                    {
                        Talk(2);
                    });
                    SetUnlock(120000);
                }

                if (!IsLock && player->HasQuest(38882))
                {
                    IsLock = true;
                    player->KilledMonsterCredit(94915);
                    player->CastSpell(player, 205552, true);

                    player->AddMovieDelayedAction(495, [player]
                    {
                        player->CastSpell(player, 205553, true);
                    });
                    player->CastSpell(player, 205551, true);//495
                    SetUnlock(120000);
                }
            }
        }
    }
};
//244559 Helya's Altar    98487
class go_helyas_altar_244559 : public GameObjectScript
{
public:
    go_helyas_altar_244559() : GameObjectScript("go_helyas_altar_244559") { }

    bool OnGossipSelect(Player* player, GameObject* go, uint32 /*sender*/, uint32 /*action*/) override
    {
        if (!player || !go)
            return false;

        if (player->HasQuest(39848))
        {
            if (Creature* helyas = player->FindNearestCreature(91387, 200.0f, true))
                helyas->Say(98487);
            player->KilledMonsterCredit(97479);
        }

        if (player->HasQuest(39855))
        {
            if (Creature* ashildir = player->FindNearestCreature(97664, 200.0f, true))
            {
                ashildir->AI()->Talk(0);
                ashildir->GetScheduler().Schedule(Milliseconds(5000), [this, player, ashildir](TaskContext context)
                {
                    ashildir->AI()->Talk(1);
                });
                ashildir->GetScheduler().Schedule(Milliseconds(10000), [this, player, ashildir](TaskContext context)
                {
                    ashildir->AI()->Talk(2);
                });
                ashildir->GetScheduler().Schedule(Milliseconds(15000), [this, player](TaskContext context)
                {
                    player->CastSpell(player, 212919, true);
                    player->KilledMonsterCredit(97487);
                });
                ashildir->GetScheduler().Schedule(Milliseconds(17000), [this, player](TaskContext context)
                {
                    player->CastSpell(player, 192669, true);
                });
                ashildir->GetScheduler().Schedule(Milliseconds(18000), [this, player](TaskContext context)
                {
                    player->CastSpell(player, 192670, true);
                });
            }
        }

        return false;
    }

    bool OnQuestAccept(Player* player, GameObject* /*go*/, Quest const* quest) override
    {
        if (quest->ID == 39857)
            if (Creature* helyas = player->FindNearestCreature(91387, 200.0f, true))
                helyas->Say(98489);
        return false;
    }
};
//97480 97558
struct npc_ashildir_97480 : public ScriptedAI
{
    npc_ashildir_97480(Creature* creature) : ScriptedAI(creature) {  }

    void sQuestReward(Player* player, Quest const* quest, uint32 /*opt*/)  override
    {
        if (quest->GetQuestId() == 39853)
            me->Say(98494);
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(player, 15.0f, false))
            {
                if (!IsLock && player->HasQuest(39857) && me->GetEntry() == 97480)
                {
                    IsLock = true;
                    Talk(0);
                    SetUnlock(120000);
                }
            }
        }
    }
};

struct npc_drowning_valkyra_97469 : public ScriptedAI
{
    npc_drowning_valkyra_97469(Creature* creature) : ScriptedAI(creature) {  }

    void Reset() override
    {
        me->AddUnitFlag(UnitFlags(UNIT_NPC_FLAG_SPELLCLICK));
    }

    void OnSpellClick(Unit* clicker, bool& /*result*/)
    {
        if (Player* player = clicker->ToPlayer())
        {
            if (player->GetQuestStatus(39851) == QUEST_STATUS_INCOMPLETE)
            {
                if (me->HasAura(192388))
                    me->RemoveAurasDueToSpell(192388);
                player->KilledMonsterCredit(97472);

                Talk(0);
                me->GetScheduler().Schedule(Milliseconds(5000), [this](TaskContext context)
                {
                    Talk(1);
                });
                me->GetScheduler().Schedule(Milliseconds(10000), [this](TaskContext context)
                {
                    Talk(2);
                    me->GetMotionMaster()->MoveAwayAndDespawn(20.0f, 10000);
                });
            }
        }
    }
};

struct npc_forsaken_catapult_95212 : public ScriptedAI
{
    npc_forsaken_catapult_95212(Creature* creature) : ScriptedAI(creature) {  }

    void Reset() override
    {
        me->AddUnitFlag(UnitFlags(UNIT_NPC_FLAG_SPELLCLICK));
    }

    void OnSpellClick(Unit* clicker, bool& /*result*/)
    {
        if (Player* player = clicker->ToPlayer())
            player->CastSpell(player, 189100, true);
    }
};

struct npc_lady_sylvanas_windrunner_94227 : public ScriptedAI
{
    npc_lady_sylvanas_windrunner_94227(Creature* creature) : ScriptedAI(creature) { }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(player, 15.0f, false))
            {
                if (!IsLock && player->HasQuest(39154))
                {
                    IsLock = true;
                    if (Creature* areiel = player->FindNearestCreature(92803, 50.0f, true))
                    {
                        me->Say(97224);
                        me->GetScheduler().Schedule(Milliseconds(5000), [this, areiel](TaskContext context)
                        {
                            areiel->Say(97225);
                        });
                        me->GetScheduler().Schedule(Milliseconds(10000), [this, areiel](TaskContext context)
                        {
                            me->Say(97226);
                        });
                        me->GetScheduler().Schedule(Milliseconds(15000), [this, areiel](TaskContext context)
                        {
                            areiel->Say(97227);
                        });
                    }
                    SetUnlock(120000);
                }
            }
        }
    }
};

//251561,251560,251559,251558,251557,242673
class go_engraved_shield_quest_38878 : public GameObjectScript
{
public:
    go_engraved_shield_quest_38878() : GameObjectScript("go_engraved_shield_quest_38878") { }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        if (player->HasQuest(38878))
            player->KilledMonsterCredit(109346);
        return false;
    }
};

struct npc_statue_94393 : public ScriptedAI
{
    npc_statue_94393(Creature* creature) : ScriptedAI(creature) {  }

    void sGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId)
    {
        CloseGossipMenuFor(player);
        player->TalkedToCreature(me->GetEntry(), me->GetGUID());
        if (player->HasQuest(39155))
        {
            player->CastSpell(player, 187829, true);
            me->CastSpell(me, 187830, true);
            //187830 94764
            if (Creature* ashildir = player->FindNearestCreature(94764, 50.0f, true))
            {
                ashildir->AI()->Talk(0, player);
                ashildir->GetScheduler().Schedule(Milliseconds(5000), [this, player, ashildir](TaskContext context)
                {
                    ashildir->AI()->Talk(1, player);
                });
                ashildir->GetScheduler().Schedule(Milliseconds(10000), [this, player, ashildir](TaskContext context)
                {
                    ashildir->AI()->Talk(2, player);
                });
                ashildir->GetScheduler().Schedule(Milliseconds(15000), [this, player, ashildir](TaskContext context)
                {
                    ashildir->AI()->Talk(3, player);
                    player->KilledMonsterCredit(94477);
                });
                ashildir->GetScheduler().Schedule(Milliseconds(20000), [this, player, ashildir](TaskContext context)
                {
                    ashildir->DespawnOrUnsummon();
                });
            }
            //187860 94769
        }
    }
};

struct npc_vethir_97979 : public ScriptedAI
{
    npc_vethir_97979(Creature* creature) : ScriptedAI(creature) { }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
            if (me->IsWithinDist(player, 15.0f, false))
                if (player->HasQuest(40002) && player->HasItemCount(129106, 1))
                    player->KilledMonsterCredit(97981);
    }
};

struct npc_vethir_97986 : public ScriptedAI
{
    npc_vethir_97986(Creature* creature) : ScriptedAI(creature) {  }

    void sGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId)
    {
        CloseGossipMenuFor(player);
        player->TalkedToCreature(me->GetEntry(), me->GetGUID());
        player->TeleportTo(1220, Position(2479.33f, 951.14f, 596.141f, 3.905f));
    }
};

struct npc_vethir_98190 : public ScriptedAI
{
    npc_vethir_98190(Creature* creature) : ScriptedAI(creature) {  }

    void sGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId)
    {
        CloseGossipMenuFor(player);
        player->TalkedToCreature(me->GetEntry(), me->GetGUID());
        player->TeleportTo(1220, Position(2518.36f, 977.15f, 233.274f, 3.97f));
    }
};

void AddSC_stormheim()
{
    new go_volatile_barrel_stormheim();
    new npc_grapple_point();
    new spell_pump();
    
    RegisterCreatureAI(npc_apothecary_withers_91590);
    new spell_transponder_pack_180645();

    RegisterCreatureAI(npc_titan_console_96139);
    new go_powered_console_stormheim_243802();
    new go_powered_console_stormheim_243817();
    RegisterCreatureAI(npc_yotnar_96258);
    RegisterCreatureAI(npc_yotnar_96175);

    RegisterCreatureAI(npc_vault_guardian_96282);
    new stormheimOnCastSpellByPlayers();
    RegisterCreatureAI(npc_grapple_point_92017);
    RegisterCreatureAI(npc_dread_rider_cullen_92566);
    RegisterCreatureAI(npc_vethir_91249);
    RegisterCreatureAI(npc_vethir_96465);
    RegisterCreatureAI(npc_thrymjaris_97061);
    RegisterCreatureAI(npc_thrymjaris_92218);
    RegisterCreatureAI(npc_vethir_92302);
    RegisterCreatureAI(npc_vethir_91767);
    new go_tideskorn_harpoon_launcher_251257();
    RegisterCreatureAI(npc_havi_92539);
    RegisterCreatureAI(npc_ironhorn_buck_98230);
    RegisterCreatureAI(npc_vydhar_93231);
    RegisterCreatureAI(npc_runestone_93343);
    RegisterSpellScript(spell_returning_spirit_quest_39791);
    new go_rune_of_reformation_244450();
    RegisterCreatureAI(npc_lady_sylvanas_windrunner_97695);
    new go_helyas_altar_244559();
    RegisterCreatureAI(npc_ashildir_97480);
    RegisterCreatureAI(npc_drowning_valkyra_97469);
    RegisterCreatureAI(npc_forsaken_catapult_95212);
    RegisterCreatureAI(npc_lady_sylvanas_windrunner_94227);
    new go_engraved_shield_quest_38878();
    RegisterCreatureAI(npc_statue_94393);
    RegisterCreatureAI(npc_vethir_97979);

    RegisterCreatureAI(npc_vethir_97986);
    RegisterCreatureAI(npc_vethir_98190);
}
