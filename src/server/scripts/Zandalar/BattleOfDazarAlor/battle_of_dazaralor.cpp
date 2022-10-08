#include "battle_of_dazaralor.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "CombatAI.h"
#include "ScriptedEscortAI.h"

//147383, 147367, 147372, 147370
struct npc_generic_horde_bod_story : public CombatAI
{
    npc_generic_horde_bod_story(Creature* creature) : CombatAI(creature) { chargolm, (false); }

    void Reset() override
    {
        CombatAI::Reset();
        me->SetReactState(REACT_AGGRESSIVE);
    }

    void UpdateAI(uint32 diff) override
    {
        scheduler.Update(diff);

        if (auto* c_chargolm = me->FindNearestCreature(NPC_CHARGOLM, 25.0f, false && !chargolm && me->GetEntry() == NPC_PRINCESS_TALANJI))
        {
            chargolm = true;

            switch (me->GetEntry())
            {
            case NPC_PRINCESS_TALANJI:
                me->SetWalk(false);
                me->GetMotionMaster()->MovePoint(1, -591.007f, 1134.283f, 320.614f, true);
                break;

            case NPC_NATHANOS_BRIGHTCALLER:
                me->SetWalk(false);
                me->GetMotionMaster()->MovePoint(1, -595.284f, 1134.815f, 320.604f, true);
                break;

            case NPC_ROKHAN:
                me->SetWalk(false);
                me->GetMotionMaster()->MovePoint(1, -587.798f, 1128.786f, 320.808f, true);
                break;

            case NPC_BLADEGUARD_KAJA:
                me->SetWalk(false);
                me->GetMotionMaster()->MovePoint(1, -585.672f, 1136.053f, 320.624f, true);
                break;
            }
        }
    }

    void MovementInform(uint32 type, uint32 point) override
    {
        if (type != POINT_MOTION_TYPE || point != 2)
            return;

        if (point == 2)
        {
            switch (me->GetEntry())
            {
            case NPC_NATHANOS_BRIGHTCALLER:
                if (Creature* zandalariWArr = me->FindNearestCreature(147601, 50.0f, true && me->GetEntry() == NPC_NATHANOS_BRIGHTCALLER && !pre_grong))
                {
                    pre_grong = true;
                    me->AI()->Talk(0);
                    break;
                }
            }
        }
    }

private:
    TaskScheduler scheduler;
    bool chargolm;
    bool pre_grong = false;
};

//149039
class npc_riding_pterrordax : public npc_escortAI
{
public:
    npc_riding_pterrordax(Creature* creature) : npc_escortAI(creature)
    {
        me->SetCanFly(true);
    }

    void IsSummonedBy(Unit* summoner) override
    {
        Start(false, true, summoner->GetGUID());
    }
};

//148372
struct npc_otoye : public ScriptedAI
{
    npc_otoye(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        ScriptedAI::Reset();
        me->SetReactState(REACT_PASSIVE);
        tell_story = false;
    }

    Position tell_story_horde_pos = { -1526.760f, 804.864f, 119.06f, 3.131f };

    void MoveInLineOfSight(Unit* unit) override
    {
        if (me->GetDistance2d(unit) < 15.0f && unit->IsPlayer() && !tell_story && instance->GetBossState(DATA_OPULENCE) == DONE)
        {
            tell_story = true;
            if (tell_story)
                Talk(0);
        }
    }

    void sGossipSelect(Player* player, uint32 /*menuId*/, uint32 /*gossipListId*/)
    {
        if (player->IsInCombat())
            return;

        me->GetScheduler().Schedule(5s, [this](TaskContext context)
        {
            instance->DoNearTeleportPlayers(tell_story_horde_pos, false);
        });
    }

private:
    bool tell_story;
};

//148629
struct npc_master_mathias_shaw_148629 : public ScriptedAI
{
    npc_master_mathias_shaw_148629(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        ScriptedAI::Reset();
        me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
    }

    Position rastakhan_floor_pos = { -1153.958f, 690.000f, 318.403f };

    void sGossipSelect(Player* player, uint32 /*menuId*/, uint32 /*gossipListId*/)
    {
        if (player->IsInCombat())
            return;

       instance->DoNearTeleportPlayers(rastakhan_floor_pos, false);
    }
};

//149050
struct npc_riding_gryphon : public ScriptedAI
{
    npc_riding_gryphon(Creature* creature) : ScriptedAI(creature) { }

private:
    Vehicle* vehicle;

    void Reset() override
    {
        ScriptedAI::Reset();
        me->GetVehicleKit();
        me->CanFly();
        me->SetFlying(true);
    }

    void OnSpellClick(Unit* clicker, bool& result) override
    {
        if (Player* player = clicker->ToPlayer())
            me->SummonCreature(me->GetEntry(), me->GetPosition(), TEMPSUMMON_TIMED_DESPAWN, 20000);
    }

    void IsSummonedBy(Unit* summoner) override
    {
        if (summoner->IsPlayer() && me->GetMapId() == 2070)
        {   
            summoner->EnterVehicle(me);
            me->GetMotionMaster()->MovePoint(1, -1461.164f, 805.806f, 135.850f, true);
        }
    }
};

class death_in_the_water : public PlayerScript
{
public:
    death_in_the_water() : PlayerScript("death_in_the_water") { }

    uint32 checkTimer = 1000;

    void OnUpdate(Player* player, uint32 diff) override
    {
        if (player->GetAreaId() != 10368)
            return;

        if (checkTimer <= diff && player->GetAreaId() == 10368 && player->IsInWater())
        {
            if (player->IsInWater())
                player->KillSelf(true);

            checkTimer = 1000;
        }
        else checkTimer -= diff;
    }
};

//149506
struct npc_nathanos_blightcaller_149506 : public ScriptedAI
{
    npc_nathanos_blightcaller_149506(Creature* c) : ScriptedAI(c) { }

    void MovementInform(uint32 type, uint32 point) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (point == 1)
        {
            Talk(2);
            me->AddNpcFlag(UNIT_NPC_FLAG_GOSSIP);
        }
    }

    void sGossipSelect(Player* player, uint32 /*menuId*/, uint32 /*gossipListId*/)
    {
        if (player->IsInCombat())
            return;

        switch (player->GetTeam())
        {
        case ALLIANCE:
            player->TeleportTo(1643, 904.163f, -528.769f, 7.323f, 2.790f);
            break;

        case HORDE:
            player->TeleportTo(1642, -299.768f, 1119.268f, 314.790f, 0.448f);
            break;
        }
    }
};

void AddSC_battle_of_dazaralor()
{
    RegisterCreatureAI(npc_generic_horde_bod_story);
    RegisterCreatureAI(npc_riding_pterrordax);
    RegisterCreatureAI(npc_otoye);
    RegisterCreatureAI(npc_master_mathias_shaw_148629);
    RegisterCreatureAI(npc_riding_gryphon);
    RegisterPlayerScript(death_in_the_water);
    RegisterCreatureAI(npc_nathanos_blightcaller_149506);
}