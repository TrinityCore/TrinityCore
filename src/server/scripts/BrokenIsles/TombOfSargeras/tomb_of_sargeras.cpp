/*
* Copyright (C) 2021 BfaCore Reforged
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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "tomb_of_sargeras.h"
#include "WaypointManager.h"
#include "GameObjectAI.h"

Position const InfernalsPos[3] =
{
    { 6130.221f, -801.1302f, 2971.544f, 2.807055f },
    { 6086.503f, -816.4011f, 2971.721f, 2.965497f },
    { 6064.199f, -782.8004f, 2971.544f, 2.827615f },
};

// 121605
struct npc_tos_breach : ScriptedAI
{
    explicit npc_tos_breach(Creature* creature) : ScriptedAI(creature) { }

    void DoAction(int32 const actionID) override
    {
        me->SetVisible(true);

        switch (actionID)
        {
        case 1:
            for (uint8 i = 0; i < 3; ++i)
            {
               // me->AddDelayedEvent(100 + 600 * i, [this, i]() -> void
              //  {
                    me->CastSpell(InfernalsPos[i], 242915, false);
              //  });
            }
            break;
        default:
            break;
        }
    }
};

uint32 const introEntries[4]
{
    NPC_VELEN,
    NPC_ILLIDAN,
    NPC_MAEIV,
    NPC_DURGAN
};

Position const introPositions[5]
{
    { 5986.409f, -795.8195f, 2978.126f, 6.269365f },
    { 5978.724f, -801.1215f, 2978.127f, 0.1859942f },
    { 5993.796f, -789.9375f, 2976.677f, 5.799626f },
    { 5990.001f, -801.5347f, 2977.88f, 0.3382317f },
    { 5980.707f, -790.559f, 2978.127f, 6.063946f }
};
/*
// 119726
struct npc_tos_kadghar_1 : ScriptedAI
{
    explicit npc_tos_kadghar_1(Creature* creature) : ScriptedAI(creature)
    {
        if (me->GetMapId() == 1676)
        {
            instance = me->GetInstanceScript();
            IntroDone = false;
            outroDone = false;
        }
        else
        {
            IntroDone = true;
            outroDone = false;
        }


        SetCanSeeEvenInPassiveMode(true);
    }

    InstanceScript* instance;
    bool IntroDone, outroDone;

    void DoAction(int32 const actionID) override
    {
        me->GetMotionMaster()->MovePoint(0, 6087.42f, -796.14f, 2971.72f);
        for (uint8 i = 0; i < 4; ++i)
            if (auto add = me->GetMap()->GetCreature(instance->GetGuidData(introEntries[i])))
                add->GetMotionMaster()->MovePoint(0, 6087.42f, -796.14f, 2971.72f);


    //    me->AddDelayedEvent(8500, [this]() -> void
        {
            me->GetMotionMaster()->Clear();
            me->GetMotionMaster()->MovePoint(0, introPositions[0].GetPositionX() + 217.0f, introPositions[0].GetPositionY(), introPositions[0].GetPositionZ());
            for (uint8 i = 0; i < 4; ++i)
                if (auto add = me->GetMap()->GetCreature(instance->GetGuidData(introEntries[i])))
                {
                    add->GetMotionMaster()->Clear();
                    add->GetMotionMaster()->MovePoint(0, introPositions[i + 1].GetPositionX() + 217.0f, introPositions[i + 1].GetPositionY(), introPositions[i + 1].GetPositionZ());
                }
      //  });

      //  me->AddDelayedEvent(25000, [this]() -> void
        {
            if (Creature* egvin = me->SummonCreature(NPC_EGVIN, 6213.44f, -795.67f, 2975.00, 3.18f))
            {
                egvin->CastSpell(egvin, 241351);
                egvin->CastSpell(me, 245480); //  me->CreateConversation(4951);

                egvin->AddDelayedEvent(600, [egvin] {
                    egvin->SetWalk(true);
                    egvin->GetMotionMaster()->MovePoint(0, 6209.66f, -795.69f, 2974.36f);
                });
            }
        });
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who->IsPlayer())
            return;

        if (!IntroDone && instance->GetBossState(DATA_GOROTH) == DONE)
        {
            IntroDone = true;
            me->CastStop();
            me->CastSpell(introPositions[0], SPELL_INTRO_TELEPORT, false);
            me->AddDelayedEvent(1000, [this] {me->SetFacingTo(6.25f); });

            for (uint8 i = 0; i < 4; ++i)
                if (auto add = me->GetMap()->GetCreature(instance->GetGuidData(introEntries[i])))
                {
                    if (i == 0)
                    {
                        add->RemoveAurasDueToSpell(241186);
                        add->CastStop();
                    }

                    add->CombatStop();
                    add->CastSpell(introPositions[i + 1], SPELL_INTRO_TELEPORT, false);
                    add->SetUInt32Value(UNIT_FIELD_EMOTE_STATE, EMOTE_ONESHOT_NONE);
                    add->AddDelayedEvent(1000, [add] {add->SetFacingTo(6.25f); });
                }

            if (auto visual_boss = me->GetMap()->GetCreature(instance->GetGuidData(NPC_ATRIGAN_MISC)))
                visual_boss->DespawnOrUnsummon();

        }

        if (IntroDone)
            return;

        if (!instance)
            return;

        if (me->GetDistance(who) < 100.0f && !IntroDone)
        {
            IntroDone = true;

            for (auto goid : { GO_INTRODESTROY_1, GO_INTRODESTROY_2, GO_INTRODESTROY_3 })
                if (GameObject* go = me->GetMap()->GetGameObject(instance->GetGuidData(goid)))
                    go->SetByteValue(GAMEOBJECT_FIELD_BYTES_1, 0, 0);

            if (GameObject* go = me->GetMap()->GetGameObject(instance->GetGuidData(GO_GOROTH_GATES)))
                go->SetByteValue(GAMEOBJECT_FIELD_BYTES_1, 0, 1);


            me->AddDelayedEvent(2000, [this]() -> void
            {
                Talk(1);
                me->CastStop();
                me->CastSpell(introPositions[0], SPELL_INTRO_TELEPORT, false);
                me->AddDelayedEvent(1000, [this] {me->SetFacingTo(6.25f); });

                for (uint8 i = 0; i < 4; ++i)
                    if (auto add = me->GetMap()->GetCreature(instance->GetGuidData(introEntries[i])))
                    {
                        if (i == 0)
                        {
                            add->RemoveAurasDueToSpell(241186);
                            add->CastStop();
                        }

                        add->CombatStop();
                        add->CastSpell(introPositions[i + 1], SPELL_INTRO_TELEPORT, false);
                        add->SetUInt32Value(UNIT_FIELD_EMOTE_STATE, EMOTE_ONESHOT_NONE);
                        add->AddDelayedEvent(1000, [add] {add->SetFacingTo(6.25f); });
                    }

                instance->SetData(1, 1);

                if (GameObject* go = me->GetMap()->GetGameObject(instance->GetGuidData(GO_INQUISITION_DOOR_INTRO)))
                {
                    go->SetByteValue(GAMEOBJECT_FIELD_BYTES_1, 0, 0);
                    go->AddDelayedEvent(4000, [go] {
                        go->SetByteValue(GAMEOBJECT_FIELD_BYTES_1, 0, 1);
                    });
                }

                if (auto visual_boss = me->GetMap()->GetCreature(instance->GetGuidData(NPC_ATRIGAN_MISC)))
                {
                    visual_boss->RemoveAllAuras();
                    visual_boss->GetMotionMaster()->MovePoint(0, 6370.82f, -795.00f, 3011.62f);
                    visual_boss->DespawnOrUnsummon(5000);
                }
            });



            me->AddDelayedEvent(7000, [this]() -> void
            {
                if (auto boss = me->GetMap()->GetCreature(instance->GetGuidData(DATA_GOROTH)))
                {
                    boss->SetVisible(true);
                    boss->SetReactState(REACT_DEFENSIVE);
                    boss->GetMotionMaster()->MovePath(25759848, false);
                    boss->AI()->Talk(10);
                  //  boss->AddDelayedEvent(4000, [boss]() -> void
                    {
                        boss->AI()->Talk(0);
                        boss->SetHomePosition(boss->GetPosition());
                   // });
                }

             //   me->AddDelayedEvent(1000, [this]() -> void {
                    if (auto summoner = me->GetMap()->GetCreature(instance->GetGuidData(NPC_BREACH_IN_WINDOW)))
                        summoner->AI()->DoAction(1);
             //   });

       //     });

        }

       // if (me->GetDistance(who) < 20.0f && !outroDone)
        {
            bool canUseIt = true;
            for (uint8 i = 0; i < DATA_MAIDEN_OF_VIGILANCE; ++i)
                if (instance->GetBossState(i) != DONE)
                    canUseIt = false;

            if (!canUseIt)
                return;

            outroDone = true;
            Creature* egvin = me->FindNearestCreature(NPC_EGVIN, 40.0f, true);
            if (!egvin)
                egvin = me->SummonCreature(NPC_EGVIN, 6213.44f, -795.67f, 2975.00, 3.18f);

            if (!egvin)
                return; // it's unreal

            egvin->CastSpell(egvin, 240060);
        }
    }
};*/

// 269783
struct go_tos_tele_to_kiljedan : GameObjectAI
{
    explicit go_tos_tele_to_kiljedan(GameObject* gameobject) : GameObjectAI(gameobject)
    {
    //    instance = go->GetInstanceScript();
    }

    InstanceScript* instance;
    uint32 timer = 1000;

    void UpdateAI(uint32 diff) override
    {
        if (timer <= diff)
        {
            if (!instance || instance->GetBossState(DATA_FALLEN_AVATAR) != DONE)
                return;

            const auto& players = instance->instance->GetPlayers();
            for (auto& pitr : players)
            {
                Player* who = pitr.GetSource();
                if (who->IsBeingTeleported())
                    return;

             //   if (go->GetDistance(who) < 13)
                    who->NearTeleportTo(4499.94f, -1072.47f, 5335.96f, 4.70f);
            }
            timer = 1000;
        }
        else
            timer -= diff;
    }
};

class spell_vantus_rune_tomb_of_sargeras : public SpellScriptLoader
{
public:
    spell_vantus_rune_tomb_of_sargeras() : SpellScriptLoader("spell_vantus_rune_tomb_of_sargeras") {}

    class spell_vantus_rune_tomb_of_sargeras_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_vantus_rune_tomb_of_sargeras_AuraScript);

        uint16 checkOnProc;
        uint16 checkOnRemove;

        bool Load()
        {
            checkOnProc = 1000;
            checkOnRemove = 1000;
            return true;
        }

        void OnUpdate(uint32 diff, AuraEffect* /*aurEff*/)
        {
            Unit* player = GetCaster();
            if (!player)
                return;

            InstanceScript* instance = player->GetInstanceScript();
            if (!instance)
                return;

            if (checkOnProc <= diff)
            {
                if (instance->GetBossState(DATA_FALLEN_AVATAR) == IN_PROGRESS)
                {
                    if (!player->HasAura(237795) && player->HasAura(237820))
                    {
                        player->CastSpell(player, 237795, false);
                    }
                }
                if (instance->GetBossState(DATA_GOROTH) == IN_PROGRESS)
                {
                    if (!player->HasAura(237796) && player->HasAura(237821))
                    {
                        player->CastSpell(player, 237796, false);
                    }
                }
                if (instance->GetBossState(DATA_SISTERS_OF_THEMOON) == IN_PROGRESS)
                {
                    if (!player->HasAura(237797) && player->HasAura(237822))
                    {
                        player->CastSpell(player, 237797, false);
                    }
                }
                if (instance->GetBossState(DATA_MAIDEN_OF_VIGILANCE) == IN_PROGRESS)
                {
                    if (!player->HasAura(237798) && player->HasAura(237823))
                    {
                        player->CastSpell(player, 237798, false);
                    }
                }
                if (instance->GetBossState(DATA_HARJATAN) == IN_PROGRESS)
                {
                    if (!player->HasAura(237799) && player->HasAura(237824))
                    {
                        player->CastSpell(player, 237799, false);
                    }
                }
                if (instance->GetBossState(DATA_KILJAEDEN) == IN_PROGRESS)
                {
                    if (!player->HasAura(237800) && player->HasAura(237825))
                    {
                        player->CastSpell(player, 237800, false);
                    }
                }
                if (instance->GetBossState(DATA_MISTRESS_SASSZINE) == IN_PROGRESS)
                {
                    if (!player->HasAura(237801) && player->HasAura(237826))
                    {
                        player->CastSpell(player, 237801, false);
                    }
                }
                if (instance->GetBossState(DATA_THE_DESOLATE_HOST) == IN_PROGRESS)
                {
                    if (!player->HasAura(237802) && player->HasAura(237827))
                    {
                        player->CastSpell(player, 237802, false);
                    }
                }
                if (instance->GetBossState(DATA_DEMONIC_INQUISITION) == IN_PROGRESS)
                {
                    if (!player->HasAura(237803) && player->HasAura(237828))
                    {
                        player->CastSpell(player, 237803, false);
                    }
                }
            }
            else checkOnProc -= diff;

            if (checkOnRemove <= diff)
            {
                if (player->HasAura(237795) && player->HasAura(237820))
                {
                    if (instance->GetBossState(DATA_FALLEN_AVATAR) == DONE || instance->GetBossState(DATA_FALLEN_AVATAR) == NOT_STARTED)
                    {
                        player->RemoveAura(237795);
                        checkOnProc = 1000;
                        checkOnRemove = 1000;
                    }
                }
                if (player->HasAura(237796) && player->HasAura(237821))
                {
                    if (instance->GetBossState(DATA_GOROTH) == DONE || instance->GetBossState(DATA_GOROTH) == NOT_STARTED)
                    {
                        player->RemoveAura(237796);
                        checkOnProc = 1000;
                        checkOnRemove = 1000;
                    }
                }
                if (player->HasAura(237797) && player->HasAura(237822))
                {
                    if (instance->GetBossState(DATA_SISTERS_OF_THEMOON) == DONE || instance->GetBossState(DATA_SISTERS_OF_THEMOON) == NOT_STARTED)
                    {
                        player->RemoveAura(237797);
                        checkOnProc = 1000;
                        checkOnRemove = 1000;
                    }
                }
                if (player->HasAura(237798) && player->HasAura(237823))
                {
                    if (instance->GetBossState(DATA_MAIDEN_OF_VIGILANCE) == DONE || instance->GetBossState(DATA_MAIDEN_OF_VIGILANCE) == NOT_STARTED)
                    {
                        player->RemoveAura(237798);
                        checkOnProc = 1000;
                        checkOnRemove = 1000;
                    }
                }
                if (player->HasAura(237799) && player->HasAura(237824))
                {
                    if (instance->GetBossState(DATA_HARJATAN) == DONE || instance->GetBossState(DATA_HARJATAN) == NOT_STARTED)
                    {
                        player->RemoveAura(237799);
                        checkOnProc = 1000;
                        checkOnRemove = 1000;
                    }
                }
                if (player->HasAura(237800) && player->HasAura(237825))
                {
                    if (instance->GetBossState(DATA_KILJAEDEN) == DONE || instance->GetBossState(DATA_KILJAEDEN) == NOT_STARTED)
                    {
                        player->RemoveAura(237800);
                        checkOnProc = 1000;
                        checkOnRemove = 1000;
                    }
                }
                if (player->HasAura(237801) && player->HasAura(237826))
                {
                    if (instance->GetBossState(DATA_MISTRESS_SASSZINE) == DONE || instance->GetBossState(DATA_MISTRESS_SASSZINE) == NOT_STARTED)
                    {
                        player->RemoveAura(237801);
                        checkOnProc = 1000;
                        checkOnRemove = 1000;
                    }
                }
                if (player->HasAura(237802) && player->HasAura(237827))
                {
                    if (instance->GetBossState(DATA_THE_DESOLATE_HOST) == DONE || instance->GetBossState(DATA_THE_DESOLATE_HOST) == NOT_STARTED)
                    {
                        player->RemoveAura(237802);
                        checkOnProc = 1000;
                        checkOnRemove = 1000;
                    }
                }
                if (player->HasAura(237803) && player->HasAura(237828))
                {
                    if (instance->GetBossState(DATA_DEMONIC_INQUISITION) == DONE || instance->GetBossState(DATA_DEMONIC_INQUISITION) == NOT_STARTED)
                    {
                        player->RemoveAura(237803);
                        checkOnProc = 1000;
                        checkOnRemove = 1000;
                    }
                }
            }
            else checkOnRemove -= diff;
        }

        void Register() override
        {
          //  OnEffectUpdate += AuraEffectUpdateFn(spell_vantus_rune_tomb_of_sargeras_AuraScript::OnUpdate, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_vantus_rune_tomb_of_sargeras_AuraScript();
    }

    class spell_vantus_rune_tomb_of_sargeras_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_vantus_rune_tomb_of_sargeras_SpellScript);

        SpellCastResult CheckCast()
        {
            Unit* caster = GetCaster();
            if (Player* player = caster->ToPlayer())
            {
                if (!player->GetQuestRewardStatus(39695))
                    return SPELL_CAST_OK;
            }
            SetCustomCastResultMessage(SPELL_CUSTOM_ERROR_YOU_ALREADY_USED_VANTUS_RUNE);
            return SPELL_FAILED_CUSTOM_ERROR;
        }

        void HandleOnHit()
        {
            if (!GetCaster())
                return;

            if (Player* player = GetCaster()->ToPlayer())
            {
                uint32 questId = 39695;
                if (questId)
                {
                //    Quest const* quest = sQuestDataStore->GetQuestTemplate(questId);
                 //   if (!quest)
                        return;

                  //  if (player->CanTakeQuest(quest, false))
                        player->CompleteQuest(questId);
                }
            }
        }

        void Register() override
        {
            OnCheckCast += SpellCheckCastFn(spell_vantus_rune_tomb_of_sargeras_SpellScript::CheckCast);
            OnHit += SpellHitFn(spell_vantus_rune_tomb_of_sargeras_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_vantus_rune_tomb_of_sargeras_SpellScript();
    }
};

void AddSC_tomb_of_sargeras()
{
    RegisterCreatureAI(npc_tos_breach);
    //RegisterCreatureAI(npc_tos_kadghar_1);
    RegisterGameObjectAI(go_tos_tele_to_kiljedan);
    new spell_vantus_rune_tomb_of_sargeras();
}
