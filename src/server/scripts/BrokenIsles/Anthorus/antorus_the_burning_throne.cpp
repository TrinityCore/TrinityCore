/*
 * This file is part of the AshamaneCore Project. See AUTHORS file for Copyright information
 * Copyright (C) 2018+ MagicStormProject <https://github.com/MagicStormTeam>
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
#include "GameObject.h"
#include "ScriptedGossip.h"
#include "antorus_the_burning_throne.h"

struct npc_image_of_prophet_velen_125513 : public ScriptedAI
{
    npc_image_of_prophet_velen_125513(Creature* creature) : ScriptedAI(creature) { Initialize(); }

    void Initialize()
    {
        IsLock = false;
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who || !who->IsInWorld() || !me->IsWithinDist(who, 15.0f, false))
            return;

        Player* player = who->GetCharmerOrOwnerPlayerOrPlayerItself();
        if (!player)
            return;
        if (!IsLock)
        {
            IsLock = true;
            me->Say(134681);
            if (Creature* npc = me->FindNearestCreature(125512, 30.0f, true))
            {
                npc->GetScheduler().Schedule(Milliseconds(2000), [](TaskContext context)
                {
                    GetContextCreature()->Yell(134682);
                });

                npc->GetScheduler().Schedule(Milliseconds(4000), [](TaskContext context)
                {
                    GetContextCreature()->Yell(134683);
                });
            }
        }
    }
    uint8 PHASE_01;
    uint8 PHASE_02;
    bool IsLock;
};
enum
{
    SPELL_ANNIHILATION = 245807,
};
struct npc_garothi_annihilator_123398 : public ScriptedAI
{
    npc_garothi_annihilator_123398(Creature* creature) : ScriptedAI(creature) { Initialize(); }

    void Initialize()
    {
        instance = me->GetInstanceScript();
        me->SetHomePosition({ -3297.7f, 9794.95f, -37.613f, 4.687f });
        me->GetMotionMaster()->MoveTargetedHome();
    }

    void EnterCombat(Unit* /*attacker*/) override
    {
        events.ScheduleEvent(SPELL_ANNIHILATION, 5s);
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        if (!UpdateVictim())
            return;
        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;
        switch (events.ExecuteEvent())
        {
        case SPELL_ANNIHILATION:
        {
            DoCast(SPELL_ANNIHILATION);
            events.Repeat(8s, 10s);
            break;
        }
        }
        DoMeleeAttackIfReady();
    }

    void JustDied(Unit* /*killer*/) override
    {
        me->SummonCreature(122450, Position(-3292.458f, 9822.647f, -63.49804f, 4.729585f), TEMPSUMMON_MANUAL_DESPAWN);
    }

private:
    InstanceScript * instance;
};

struct npc_lightforged_teleport_pod_130137 : public ScriptedAI
{
    npc_lightforged_teleport_pod_130137(Creature* creature) : ScriptedAI(creature) { }

    void OnSpellClick(Unit* clicker, bool& /*result*/)
    {
        if (Player* player = clicker->ToPlayer())
        {
        }
    }
};

enum
{
    SPELL_PYROGENICS = 248757,
    SPELL_FEL_FIREBALL = 257802,
    SPELL_SOULBURN = 253599,
};
struct npc_clobex_127732 : public ScriptedAI
{
    npc_clobex_127732(Creature* creature) : ScriptedAI(creature) { Initialize(); }

    void EnterCombat(Unit* /*victim*/) override
    {
        Talk(1);
        events.ScheduleEvent(SPELL_PYROGENICS, 5s);
        events.ScheduleEvent(SPELL_FEL_FIREBALL, 5s);
        events.ScheduleEvent(SPELL_SOULBURN, 5s);
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);
        if (!UpdateVictim())
            return;
        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {

            case SPELL_PYROGENICS:
            {
                DoCast(SPELL_PYROGENICS);
                break;
            }
            case SPELL_FEL_FIREBALL:
            {
                DoCast(SPELL_FEL_FIREBALL);
                events.Repeat(5s);
                break;
            }
            case SPELL_SOULBURN:
            {
                DoCast(SPELL_SOULBURN);
                events.Repeat(5s);
                break;
            }
            }
        }
        DoMeleeAttackIfReady();
    }

    void Initialize()
    {
        IsLock = false;
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who || !who->IsInWorld() || !me->IsWithinDist(who, 35.0f, false))
            return;

        Player* player = who->GetCharmerOrOwnerPlayerOrPlayerItself();
        if (!player)
            return;
        if (!IsLock)
        {
            IsLock = true;
            Talk(0);
        }
    }

    bool IsLock;
};

///
struct npc_jump_pad_124962 : public ScriptedAI
{
    npc_jump_pad_124962(Creature* creature) : ScriptedAI(creature) { }
    virtual Position const* GetPos() const = 0;
    void MoveInLineOfSight(Unit* who) override
    {
        if (!who || !who->IsInWorld() || !me->IsWithinDist(who, 1.0f, false))
            return;

        Player* player = who->GetCharmerOrOwnerPlayerOrPlayerItself();
        if (!player)
            return;
        player->GetMotionMaster()->MoveJump(GetPos()->GetPosition(), 28.0f, 10.0f);
    }
};

struct npc_jump_pad_124962_1 : public npc_jump_pad_124962
{
    npc_jump_pad_124962_1(Creature* creature) : npc_jump_pad_124962(creature) { }
    Position const pos[1] = { { -3885.5869f, -10852.441f, 706.56286f, 1.3896f } };
    Position const* GetPos() const override { return pos; }
};

struct npc_jump_pad_124962_2 : public npc_jump_pad_124962
{
    npc_jump_pad_124962_2(Creature* creature) : npc_jump_pad_124962(creature) { }
    Position const pos[1] = { { -3957.057f, -10829.2f, 684.7495f, 3.3688f } };
    Position const* GetPos() const override { return pos; }
};

struct npc_jump_pad_124962_3 : public npc_jump_pad_124962
{
    npc_jump_pad_124962_3(Creature* creature) : npc_jump_pad_124962(creature) { }
    Position const pos[1] = { { -3977.3f, -10765.454f, 696.6635f, 1.6082f } };
    Position const* GetPos() const override { return pos; }
};

struct npc_jump_pad_124962_4 : public npc_jump_pad_124962
{
    npc_jump_pad_124962_4(Creature* creature) : npc_jump_pad_124962(creature) { }
    Position const pos[1] = { { -3908.056f, -10892.754f, 686.1674f, 4.7786f } };
    Position const* GetPos() const override { return pos; }
};

struct npc_jump_pad_124962_5 : public npc_jump_pad_124962
{
    npc_jump_pad_124962_5(Creature* creature) : npc_jump_pad_124962(creature) { }
    Position const pos[1] = { { -3956.8322f, -10829.5f, 684.749f, 5.1114f } };
    Position const* GetPos() const override { return pos; }
};

struct npc_jump_pad_124962_6 : public npc_jump_pad_124962
{
    npc_jump_pad_124962_6(Creature* creature) : npc_jump_pad_124962(creature) { }
    Position const pos[1] = { { -3891.4465f, -10754.1748f, 738.597f, 1.311f } };
    Position const* GetPos() const override { return pos; }
};

struct npc_jump_pad_124962_7 : public npc_jump_pad_124962
{
    npc_jump_pad_124962_7(Creature* creature) : npc_jump_pad_124962(creature) { }
    Position const pos[1] = { { -3860.5068f,-10699.1748f, 725.831f, 0.222f } };
    Position const* GetPos() const override { return pos; }
};
//Boss 6 Door and more
struct npc_lightforged_beacon_128303 : public ScriptedAI
{
    npc_lightforged_beacon_128303(Creature* creature) : ScriptedAI(creature) { }

    bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId)
    {
        CloseGossipMenuFor(player);
        //player->AddDelayedConversation(5000, 5743);
        player->NearTeleportTo(Position(-12634.0f, -3359.89f, 2513.82f, 1.573414f));
        return false;
    }
};

struct npc_lightforged_beacon_128304 : public ScriptedAI
{
    npc_lightforged_beacon_128304(Creature* creature) : ScriptedAI(creature) { }

    bool GossipHello(Player* player) override
    {
        CloseGossipMenuFor(player);
        player->NearTeleportTo({ -10574.6f, 8783.08f, 1871.48f, 4.71183f });
        return false;
    }
};

struct npc_lightforged_beacon_129449 : public ScriptedAI
{
    npc_lightforged_beacon_129449(Creature* creature) : ScriptedAI(creature) { }

    Position const Path01[4] =
    {
        { -3102.9594f, 10468.2958f, -104.983f },
        { -3123.475f, 10420.74f, -86.1347f },
        { -3167.0f, 10370.857f, -99.4f },
        { -3192.083f, 10337.01f, -111.0f, 4.1174f }
    };
    using Path01Size = std::extent<decltype(Path01)>;

    void IsSummonedBy(Unit* summoner) override
    {
        me->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
    }

    void OnSpellClick(Unit* clicker, bool& /*result*/)
    {
        if (Player* player = clicker->ToPlayer())
        {
            player->CastSpell(player, 253773, true);
            player->GetMotionMaster()->MoveSmoothPath(1, Path01, Path01Size::value, false, true);
        }
    }
};

struct npc_lightforged_beacon_125720 : public ScriptedAI
{
    npc_lightforged_beacon_125720(Creature* creature) : ScriptedAI(creature) { }

    bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId)
    {
        CloseGossipMenuFor(player);
        player->RemoveAurasDueToSpell(253936);
        player->SetSpeed(UnitMoveType::MOVE_RUN, 10.0f);
        //???
        player->NearTeleportTo(Position(-10574.71f, 8754.888f, 1871.554f, 4.720208f));
        return false;
    }
};

struct npc_lightforged_warframe_127963 : public ScriptedAI
{
    npc_lightforged_warframe_127963(Creature* creature) : ScriptedAI(creature) { }

    Position const Path01[4] =
    {
        { -3153.58f, 10103.6f, -54.15482f },
        { -3262.094f, 10011.0f, -137.796f },
        { -3374.076f, 10051.61f, -145.1721f },
        { -3390.729f, 10135.46f, -151.1184f }
    };
    using Path01Size = std::extent<decltype(Path01)>;

    bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId)
    {
        CloseGossipMenuFor(player);
        player->CastSpell(player, 253936, true);
        float speed = player->GetSpeed(UnitMoveType::MOVE_RUN);
        player->SetSpeed(UnitMoveType::MOVE_RUN, 25.0f);
        me->GetScheduler().Schedule(Milliseconds(2000), [this, player](TaskContext context)
        {
            player->GetMotionMaster()->MoveSmoothPath(1, Path01, Path01Size::value, false, true);
        });
        me->GetScheduler().Schedule(Milliseconds(15000), [this, player, speed](TaskContext context)
        {
            player->RemoveAurasDueToSpell(253936);
            player->SetSpeed(UnitMoveType::MOVE_RUN, speed);
        });
        return false;
    }
};

struct npc_magni_bronzebeard_125584 : public ScriptedAI
{
    npc_magni_bronzebeard_125584(Creature* creature) : ScriptedAI(creature) { }

    void MoveInLineOfSight(Unit* who) override
    {
        if (who->IsPlayer() && me->IsWithinDist(who, 40.0f, false) && !IsLock)
        {
            /*IsLock = true;
            if (me->FindNearestCreature(125720, 50.0f, true))
                //who->ToPlayer()->AddDelayedConversation(500, 5572);
            if (me->FindNearestGameObject(277474, 50.0f))
                who->ToPlayer()->AddDelayedConversation(500, 5528);*/
        }
    }

    bool IsLock;
};

void AddSC_antorus_the_burning_throne()
{
    RegisterCreatureAI(npc_image_of_prophet_velen_125513);
    RegisterCreatureAI(npc_garothi_annihilator_123398);
    RegisterCreatureAI(npc_lightforged_teleport_pod_130137);
    RegisterCreatureAI(npc_clobex_127732);
    RegisterCreatureAI(npc_jump_pad_124962_1);
    RegisterCreatureAI(npc_jump_pad_124962_2);
    RegisterCreatureAI(npc_jump_pad_124962_3);
    RegisterCreatureAI(npc_jump_pad_124962_4);
    RegisterCreatureAI(npc_jump_pad_124962_5);
    RegisterCreatureAI(npc_jump_pad_124962_6);
    RegisterCreatureAI(npc_jump_pad_124962_7);
    RegisterCreatureAI(npc_lightforged_beacon_128303);
    RegisterCreatureAI(npc_lightforged_beacon_128304);
    RegisterCreatureAI(npc_lightforged_beacon_129449);
    RegisterCreatureAI(npc_lightforged_beacon_125720);
    RegisterCreatureAI(npc_lightforged_warframe_127963);
    RegisterCreatureAI(npc_magni_bronzebeard_125584);
}
