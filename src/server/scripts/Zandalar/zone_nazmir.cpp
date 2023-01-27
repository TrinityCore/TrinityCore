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

#include "ScriptedCreature.h"

enum Quests
{
    QUEST_ITS_ALIVE = 54213,
    QUEST_WE_HAVE_THEM_CONCERNED = 54244,
    QUEST_PARTING_MISTS = 54275,
    QUEST_FLY_OUT_TO_MEET_THEM = 54280,
};

enum Creatures
{
    NPC_RIDE_ROBOT_VEHICLE = 147313,
    NPC_RIDING_RAPTOR_VEHICLE = 147318,
    NPC_PTERRODAX_VEHICLE = 143701,
};

enum Scenes
{
    SCENE_ZULDAZAR_ATTACK = 2415,
};

//146921
struct npc_princess_talanji_146921 : public ScriptedAI
{
    npc_princess_talanji_146921(Creature* c) : ScriptedAI(c) { }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->ID == QUEST_WE_HAVE_THEM_CONCERNED)
            player->SummonCreature(NPC_RIDING_RAPTOR_VEHICLE, me->GetPosition());
    }

    void sGossipSelect(Player* player, uint32 /*menuId*/, uint32 /*gossipListId*/) override
    {
        if (!player->GetQuestObjectiveData(QUEST_ITS_ALIVE, 0))
        {
            me->AI()->Talk(0);
            player->KilledMonsterCredit(146921);
            player->GetScheduler().Schedule(5s, [this, player](TaskContext context)
            {
                me->SummonCreature(NPC_RIDE_ROBOT_VEHICLE, player->GetPosition(), TEMPSUMMON_TIMED_DESPAWN, 90000);
            });
        }
        if (player->HasQuest(QUEST_PARTING_MISTS) && !player->GetQuestObjectiveData(QUEST_PARTING_MISTS, 2))
        {
            player->KilledMonsterCredit(148888);
            player->GetScheduler().Schedule(5s, [this, player](TaskContext context)
            {
                player->GetSceneMgr().PlaySceneByPackageId(SCENE_ZULDAZAR_ATTACK);
            });
        }
    } 
};

//147318
struct npc_riding_raptor_147318 : public ScriptedAI
{
    npc_riding_raptor_147318(Creature* c) : ScriptedAI(c) { Vehicle* vehicle = me->GetVehicleKit(); }

    void IsSummonedBy(Unit* summoner) override
    {
        if (Player* player = summoner->ToPlayer())
        {
            if (player->HasQuest(QUEST_WE_HAVE_THEM_CONCERNED))
            {
                me->SetWalk(false);
                player->EnterVehicle(me);
                me->GetMotionMaster()->MovePoint(1, 1705.989f, 1806.780f, 12.516f, true);
                player->KilledMonsterCredit(me->GetEntry());
            }
            if (player->HasQuest(QUEST_PARTING_MISTS))
            {
                me->SetWalk(false);
                player->EnterVehicle(me);
                me->GetMotionMaster()->MovePoint(2, 2429.223f, 1762.098f, 0.265f, true);
                player->KilledMonsterCredit(147686);
            }
        }
    }

    void MovementInform(uint32 type, uint32 point) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (point == 1)
            me->DespawnOrUnsummon();

        if (point == 2)
            me->DespawnOrUnsummon();
    }
};

//147233
struct npc_rokhan_147233 : public ScriptedAI
{
    npc_rokhan_147233(Creature* c) : ScriptedAI(c) { }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->ID == QUEST_PARTING_MISTS)
        {
            player->KilledMonsterCredit(147669);
            player->NearTeleportTo(1884.685f, 1775.752f, -0.199f, false);
            player->GetScheduler().Schedule(5s, [this, player](TaskContext context)
            {
                player->SummonCreature(NPC_RIDING_RAPTOR_VEHICLE, me->GetPosition());
            });
        }
    }
};

//147075
struct npc_general_rakera_147075 : public ScriptedAI
{
    npc_general_rakera_147075(Creature* c) : ScriptedAI(c) { }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->ID == QUEST_FLY_OUT_TO_MEET_THEM)
            player->SummonCreature(NPC_PTERRODAX_VEHICLE, me->GetPosition());
    }
};

//143701
struct npc_pterrodax_143701 : public ScriptedAI
{
    npc_pterrodax_143701(Creature* c) : ScriptedAI(c) { }

    void IsSummonedBy(Unit* summoner) override
    {
        if (Player* player = summoner->ToPlayer())
        {
            if (player->HasQuest(QUEST_FLY_OUT_TO_MEET_THEM))
            {
                Vehicle* vehicle = me->GetVehicleKit();
                player->EnterVehicle(me);
                me->GetMotionMaster()->MovePoint(1, -349.566f, 1171.464f, 316.705f, true);
                player->KilledMonsterCredit(147707);
            }
        }
    }

    void MovementInform(uint32 type, uint32 point) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (point == 1)
            me->DespawnOrUnsummon();
    }
};

//257255
class spell_play_chapter_1 : public AuraScript
{
    PrepareAuraScript(spell_play_chapter_1);

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->CastSpell(caster, 242682);
        if (Creature* tzena = caster->FindNearestCreature(121530, 5))
        {
            caster->CastSpell(tzena, 46598);
        }
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_play_chapter_1::OnRemove, EFFECT_2, SPELL_AURA_PLAY_SCENE, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_zone_nazmir()
{
    RegisterCreatureAI(npc_princess_talanji_146921);
    RegisterCreatureAI(npc_riding_raptor_147318);
    RegisterCreatureAI(npc_rokhan_147233);
    RegisterCreatureAI(npc_general_rakera_147075);
    RegisterCreatureAI(npc_pterrodax_143701);
    RegisterAuraScript(spell_play_chapter_1);
}