/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

/* ScriptData
SDName: Gnomeregan
SD%Complete: Intro
SDComment: Quest Support: 27635, 28169
SDCategory: Gnomeregan
EndScriptData */

#include "Creature.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "Vehicle.h"
#include "MotionMaster.h"
#include "TemporarySummon.h"
#include "GameObject.h"

enum GnomeCreatureIds
{
    NPC_DECONTAMINATION_BUNNY = 46165,
    NPC_CLEAN_CANNON          = 46208,
    NPC_SAFE_TECHNICAN        = 46230,
    NPC_NEVIN_TWISTWRENCH     = 46293,
    NPC_IMUN_AGENT            = 47836
};

enum GnomeSpells
{
    SPELL_CANNON_BURST          = 86080,
    SPELL_DECONTAMINATE_STAGE_1 = 86075,
    SPELL_DECONTAMINATE_STAGE_2 = 86086,
    SPELL_IRRADIATE             = 80653,
    SPELL_EXPLOSION             = 30934
};

enum GnomeQuests
{
    QUEST_DECONTAMINATION              = 27635,
    QUEST_WITHDRAW_TO_THE_LOADING_ROOM = 28169
};

enum GnomeGossips
{
    GOSSIP_TORBEN      = 12104
};

enum GnomeMoves
{
    MOVE_IMUN_AGENT = 4783600
};

Position const SpawnPosition = { -4981.25f, 780.992f, 288.485f, 3.316f };

class npc_nevin_twistwrench : public CreatureScript
{
public:
    npc_nevin_twistwrench() : CreatureScript("npc_nevin_twistwrench") { }

    struct npc_nevin_twistwrenchAI : public ScriptedAI
    {
        npc_nevin_twistwrenchAI(Creature* creature) : ScriptedAI(creature) { }

        void MoveInLineOfSight(Unit * who) override
        {
            if (who->IsPlayer() && who->IsWithinDist(me, 10.f) && !who->HasAura(SPELL_IRRADIATE)
                && who->ToPlayer()->GetQuestStatus(QUEST_DECONTAMINATION) == QUEST_STATUS_NONE)
                who->CastSpell(who, SPELL_IRRADIATE, true);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_nevin_twistwrenchAI(creature);
    }

};

class npc_carvo_blastbolt : public CreatureScript
{
public:
    npc_carvo_blastbolt() : CreatureScript("npc_carvo_blastbolt") { }

    bool OnQuestAccept(Player* player, Creature* /*creature*/, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_WITHDRAW_TO_THE_LOADING_ROOM)
        {
            if (TempSummon* agent = player->SummonCreature(NPC_IMUN_AGENT, SpawnPosition, TEMPSUMMON_TIMED_DESPAWN, 60000, 0, true))
            {
                agent->SetSpeed(MOVE_RUN, 1.0f);
                agent->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_SELECTABLE);
                agent->SetReactState(REACT_PASSIVE);
                agent->AI()->Talk(0, player);
                agent->GetMotionMaster()->MovePath(MOVE_IMUN_AGENT, false);
            }
        }

        return true;
    }
};

class npc_sanitron_5000 : public CreatureScript
{
public:
    npc_sanitron_5000() : CreatureScript("npc_sanitron_5000") { }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (player->GetQuestStatus(QUEST_DECONTAMINATION) == QUEST_STATUS_INCOMPLETE)
        {
            player->HandleEmoteCommand(0);
            creature->GetVehicleKit();
            player->EnterVehicle(creature->ToUnit(), 0);
            creature->AI()->Talk(0);
        }
        return true;
    }

    struct npc_sanitron_5000AI : public ScriptedAI
    {
        npc_sanitron_5000AI(Creature* creature) : ScriptedAI(creature), _vehicle(creature->GetVehicleKit())
        {
            ASSERT(_vehicle); // we dont actually use it, just check if exists
        }

        void Reset() override
        {
            uiTimer = 0;
            uiRespawnTimer = 6000;
            uiPhase = 0;
        }

        void GetTargets()
        {
            std::list<Creature*> targets = me->FindAllCreaturesInRange(100.0f);

            for (auto itr : targets)
            {
                switch (itr->GetEntry())
                {
                    case NPC_SAFE_TECHNICAN:
                        if (itr->GetDistance2d(-5165.209961f, 713.809021f) <= 1)
                            TechnicianGUID = itr->GetGUID();
                        break;
                    case NPC_DECONTAMINATION_BUNNY:
                        if (itr->GetDistance2d(-5164.919922f, 723.890991f) <= 1)
                            BunnyGUID[0] = itr->GetGUID();
                        if (itr->GetDistance2d(-5182.560059f, 726.656982f) <= 1)
                            BunnyGUID[1] = itr->GetGUID();
                        if (itr->GetDistance2d(-5166.350098f, 706.336975f) <= 1)
                            BunnyGUID[2] = itr->GetGUID();
                        if (itr->GetDistance2d(-5184.040039f, 708.405029f) <= 1)
                            BunnyGUID[3] = itr->GetGUID();
                        break;
                    case NPC_CLEAN_CANNON:
                        if (itr->GetDistance2d(-5164.209961f, 719.267029f) <= 1)
                            CannonGUID[0] = itr->GetGUID();
                        if (itr->GetDistance2d(-5165.000000f, 709.453979f) <= 1)
                            CannonGUID[1] = itr->GetGUID();
                        if (itr->GetDistance2d(-5183.830078f, 722.093994f) <= 1)
                            CannonGUID[2] = itr->GetGUID();
                        if (itr->GetDistance2d(-5184.470215f, 712.554993f) <= 1)
                            CannonGUID[3] = itr->GetGUID();
                        break;
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (_vehicle->HasEmptySeat(0))
                return;

            if (uiTimer <= diff)
            {
                if (Unit* passenger = _vehicle->GetPassenger(0))
                {
                    if (Player* player = passenger->ToPlayer())
                    {
                        switch (uiPhase)
                        {
                            case 0:
                                ++uiPhase;
                                uiTimer = 2500;
                                break;
                            case 1:
                                me->GetMotionMaster()->MovePoint(1, -5173.34f, 730.11f, 294.25f);
                                GetTargets();
                                ++uiPhase;
                                uiTimer = 3000;
                                break;
                            case 2:
                                for (uint8 i = 0; i < 2; ++i)
                                    if (Creature* bunny = ObjectAccessor::GetCreature(*me, BunnyGUID[i]))
                                        bunny->CastSpell(player, SPELL_DECONTAMINATE_STAGE_1, true);

                                ++uiPhase;
                                uiTimer = 1500;
                                break;
                            case 3:
                                me->GetMotionMaster()->MovePoint(2, -5173.72f, 725.7f, 294.03f);
                                ++uiPhase;
                                uiTimer = 500;
                                break;
                            case 4:
                                me->GetMotionMaster()->MovePoint(3, -5174.57f, 716.45f, 289.53f);
                                ++uiPhase;
                                uiTimer = 3000;
                                break;
                            case 5:
                                for (uint8 i = 0; i < 4; ++i)
                                    if (Creature* cannon = ObjectAccessor::GetCreature(*me, CannonGUID[i]))
                                        cannon->CastSpell(player, SPELL_CANNON_BURST, true);

                                ++uiPhase;
                                uiTimer = 4000;
                                break;
                            case 6:
                                if (Creature* technician = ObjectAccessor::GetCreature(*me, TechnicianGUID))
                                    technician->AI()->Talk(0);
                                me->GetMotionMaster()->MovePoint(4, -5175.04f, 707.2f, 294.4f);
                                ++uiPhase;
                                uiTimer = 4000;
                                break;
                            case 7:
                                for (uint8 i = 2; i < 4; ++i)
                                    if (Creature* bunny = ObjectAccessor::GetCreature(*me, BunnyGUID[i]))
                                        bunny->CastSpell(player, SPELL_DECONTAMINATE_STAGE_2, true);

                                player->RemoveAurasDueToSpell(SPELL_IRRADIATE);
                                ++uiPhase;
                                uiTimer = 1000;
                                break;
                            case 8:
                                player->CompleteQuest(QUEST_DECONTAMINATION);
                                Talk(1);
                                me->GetMotionMaster()->MovePoint(5, -5175.61f, 700.38f, 290.89f);
                                ++uiPhase;
                                uiTimer = 3000;
                                break;
                            case 9:
                                Talk(2);
                                me->CastSpell(me, SPELL_EXPLOSION);
                                ++uiPhase;
                                uiTimer = 1000;
                                break;
                            case 10:
                                _vehicle->RemoveAllPassengers();
                                me->setDeathState(JUST_DIED);
                                ++uiPhase;
                                uiTimer = 0;
                                break;
                        }
                    }
                }

            }
            else uiTimer -= diff;
        }

    private:
        Vehicle* _vehicle;

        ObjectGuid TechnicianGUID;
        ObjectGuid BunnyGUID[4] = {};
        ObjectGuid CannonGUID[4] = {};

        uint32 uiTimer;
        uint32 uiRespawnTimer;
        uint8 uiPhase;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_sanitron_5000AI(creature);
    }
};

class npc_gnomeregan_torben : public CreatureScript
{
public:
    npc_gnomeregan_torben() : CreatureScript("npc_gnomeregan_torben") { }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        AddGossipItemFor(player, GOSSIP_TORBEN, 1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        SendGossipMenuFor(player, player->GetGossipTextId(creature), creature->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 /*sender*/, uint32 action) override
    {
        ClearGossipMenuFor(player);
        if (action == GOSSIP_ACTION_INFO_DEF + 1)
        {
            player->KilledMonsterCredit(NPC_NEVIN_TWISTWRENCH);
            player->TeleportTo(0, -5201.58f, 477.98f, 388.47f, 5.13f);
            CloseGossipMenuFor(player);
        }
        return true;
    }
};

struct npc_multi_bot : public ScriptedAI
{
    npc_multi_bot(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        me->GetScheduler().Schedule(2s, [this](TaskContext context)
        {
            if (GameObject* gobject = me->FindNearestGameObject(203975, 5))
            {
                if (Player* owner = me->GetOwner()->ToPlayer())
                {
                    Talk(0);
                    gobject->SetGoState(GO_STATE_ACTIVE);
                    me->CastSpell(me, 79424, true);
                    me->CastSpell(me, 79422, true);
                }
            }
            
            context.Repeat();
        });
    }
};

void AddSC_zone_gnomeregan()
{
    new npc_nevin_twistwrench();
    new npc_carvo_blastbolt();
    new npc_sanitron_5000();
    new npc_gnomeregan_torben();
    RegisterCreatureAI(npc_multi_bot);
}

