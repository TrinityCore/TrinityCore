/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2010 - 2012 ProjectSkyfire <http://www.projectskyfire.org/>
 *
 * Copyright (C) 2011 - 2012 ArkCORE <http://www.arkania.net/>
 * Copyright (C) 2008 - 2012 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#include "InstanceScript.h"
#include "ScriptedGossip.h"
#include "ScriptMgr.h"
#include "the_vortex_pinnacle.h"

#define NB_STARS 8
#define NPC_STAR 45932 // 45981
#define UNDER_MAP_ARRIVAL 42

class npc_slipstream : public CreatureScript
{
public:
    npc_slipstream() : CreatureScript("npc_slipstream") { }

    bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 Sender, uint32 action) override
    {
        player->PlayerTalkClass->ClearMenus();

        if (Sender != GOSSIP_SENDER_MAIN)
            return true;
        if (!player->getAttackers().empty())
            return true;

        switch (action)
        {
            case GOSSIP_ACTION_INFO_DEF+1:
                player->TeleportTo(657, -914.87f, -190.27f, 664.50f, 2.43f);
            break;
        }
        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        //InstanceScript* instance = creature->GetInstanceScript();

        //if (instance && instance->GetData(DATA_GRAND_VIZIER_ERTAN)==DONE)
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Teleport me to the first platform", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        SendGossipMenuFor(player, 2475, creature->GetGUID());
        return true;
    }
};

class npc_slipstream_two : public CreatureScript
{
public:
    npc_slipstream_two() : CreatureScript("npc_slipstream_two") { }

    bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 Sender, uint32 action) override
    {
        player->PlayerTalkClass->ClearMenus();

        if (Sender != GOSSIP_SENDER_MAIN)
            return true;
        if (!player->getAttackers().empty())
            return true;

        switch (action)
        {
            case GOSSIP_ACTION_INFO_DEF+1:
                player->RemoveAurasDueToSpell(88244);
                player->RemoveAurasDueToSpell(88282);
                player->RemoveAurasDueToSpell(88286);
                player->TeleportTo(657, -1188.86f, 475.83f, 635.59f, 0.54f);
            break;
        }
        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        //InstanceScript* instance = creature->GetInstanceScript();

        //if (instance && instance->GetData(DATA_ALTAIRUS)==DONE)
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Teleport me to the second platform", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        SendGossipMenuFor(player, 2475, creature->GetGUID());
        return true;
    }
};

class mob_vortex_wind_rotation_manager : public CreatureScript
{
public:
    mob_vortex_wind_rotation_manager() : CreatureScript("mob_vortex_wind_rotation_manager") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new mob_vortex_wind_rotation_managerAI(pCreature);
    }

    struct mob_vortex_wind_rotation_managerAI : public ScriptedAI
    {
        mob_vortex_wind_rotation_managerAI(Creature* pCreature) : ScriptedAI(pCreature),  Summons(me)
        {
            instance = pCreature->GetInstanceScript();
        }

        void Reset() override
        {
            m_timer = 0;
            radius = 14;
            own_stars.clear();
            orient = 0.0f;
            Summons.DespawnAll();
            for (int i = 0; i < NB_STARS; i++)
            {
                orient += 2.0f * float(M_PI) / NB_STARS;
                float x, y;
                me->GetNearPoint2D(x, y, radius, orient);
                me->SummonCreature(NPC_STAR, x, y, me->GetPositionZ(), 0.0f, TEMPSUMMON_MANUAL_DESPAWN);
            }
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
            start = false;
        }

        void JustDied(Unit* /*who*/) override
        {
            Summons.DespawnAll();
        }

        void DamageTaken(Unit* /*pDone_by*/, uint32& uiDamage) override
        {
            uiDamage = 0;
        }

        void AttackStart(Unit* /*who*/) override
        {
        }

        void JustSummoned(Creature* summoned) override
        {
            own_stars.push_back(summoned->GetGUID());
            Summons.Summon(summoned);
        }

        void checkForDespawn(const uint32 diff)
        {
            if (mui_timer_despawn <= diff)
            {
                bool despawn = true;
                for (std::list<ObjectGuid >::iterator itr = own_stars.begin(); itr != own_stars.end(); itr++)
                    if (Creature *vortex = ObjectAccessor::GetCreature(*me, (*itr)))
                        if (vortex->IsAlive())
                        {
                            despawn = false;
                            break;
                        }
                if (despawn)
                    me->DespawnOrUnsummon();
                mui_timer_despawn = 1000;
            }
            else
                mui_timer_despawn -= diff;
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (me->GetDistance2d(who) < 25.0f)
                start = true;
        }

        void UpdateAI(uint32 uiDiff) override
        {
            if (!start)
                return;

            checkForDespawn(uiDiff);

            if (m_timer <= uiDiff)
            {
                orient = fmod(orient + 0.1f, 2.0f * static_cast<float >(M_PI));
                for (std::list<ObjectGuid>::iterator itr = own_stars.begin(); itr != own_stars.end(); itr++)
                {
                    if (Creature *vortex = ObjectAccessor::GetCreature(*me, (*itr)))
                    {
                        float x,y;
                        orient += 2.0f * float(M_PI) / NB_STARS;
                        me->GetNearPoint2D(x, y, radius, orient);
                        vortex->GetMotionMaster()->Clear();
                        vortex->GetMotionMaster()->MovePoint(0, x, y,  me->GetPositionZ());
                    }
                }
                m_timer = 200;
            }
            else m_timer -= uiDiff;
        }

    private :
        InstanceScript* instance;
        SummonList Summons;
        std::list<ObjectGuid> own_stars;

        uint32 m_timer;
        uint32 radius;
        uint32 mui_timer_despawn;

        float orient;

        bool start;
    };
};

class mob_wild_vortex : public CreatureScript
{
public:
    mob_wild_vortex() : CreatureScript("mob_wild_vortex") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new mob_wild_vortexAI(pCreature);
    }

    struct mob_wild_vortexAI : public ScriptedAI
    {
       mob_wild_vortexAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            instance = pCreature->GetInstanceScript();
        }

        void Reset() override
        {
            m_timer = 0;
            m_timer1 = 2000;
            m_timer2 = 4000;
        }

        void UpdateAI(uint32 uiDiff) override
        {
            if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (m_timer <= uiDiff)
            {
                DoCastVictim(88032);
                m_timer = urand(2000, 4000);
            }
            else m_timer -= uiDiff;


            if (m_timer1 <= uiDiff)
            {
                DoCastRandom(88029, 0.0f);
                m_timer1 = urand(5000, 6000);
            }
            else m_timer1 -= uiDiff;


            if (m_timer2 <= uiDiff)
            {
                if (Unit* unit = SelectTarget(SELECT_TARGET_RANDOM, 0, NonTankTargetSelector(me)))
                    me->CastSpell(unit, 88010);
                m_timer2 = urand(3000, 10000);
            }
            else m_timer2 -= uiDiff;

            DoMeleeAttackIfReady();
        }

    private :
        InstanceScript* instance;
        uint32 m_timer;
        uint32 m_timer1;
        uint32 m_timer2;
    };
};

class mob_golden_orb : public CreatureScript
{
public:
    mob_golden_orb() : CreatureScript("mob_golden_orb") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new mob_golden_orbAI(pCreature);
    }

    struct mob_golden_orbAI : public ScriptedAI
    {
        mob_golden_orbAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            instance = pCreature->GetInstanceScript();
        }

        void Reset() override
        {
            updateAch = false;
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (updateAch || !IsHeroic() || me->GetDistance2d(who) > 1.0f)
                return;
            instance->SetData(DATA_GOLDEN_ORB, DONE);
            me->DespawnOrUnsummon();
            updateAch = true;
        }

        void UpdateAI(uint32 /*uiDiff*/) override
        {
        }

    private :
        InstanceScript* instance;
        bool updateAch;
    };
};


void AddSC_vortex_pinnacle()
{
    new npc_slipstream();
    new npc_slipstream_two();
    new mob_vortex_wind_rotation_manager();
    new mob_wild_vortex();
    new mob_golden_orb();
}
