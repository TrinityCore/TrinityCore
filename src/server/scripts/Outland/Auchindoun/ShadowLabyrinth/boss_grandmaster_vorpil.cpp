/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

/*
Name: Boss_Grandmaster_Vorpil
%Complete: 100
Category: Auchindoun, Shadow Labyrinth
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "shadow_labyrinth.h"
#include "Player.h"

enum GrandmasterVorpil
{
    SAY_INTRO                   = 0,
    SAY_AGGRO                   = 1,
    SAY_HELP                    = 2,
    SAY_SLAY                    = 3,
    SAY_DEATH                   = 4,

    SPELL_RAIN_OF_FIRE          = 33617,
    H_SPELL_RAIN_OF_FIRE        = 39363,

    SPELL_DRAW_SHADOWS          = 33563,
    SPELL_SHADOWBOLT_VOLLEY     = 33841,
    SPELL_BANISH                = 38791,

    NPC_VOID_TRAVELER           = 19226,
    SPELL_SACRIFICE             = 33587,
    SPELL_SHADOW_NOVA           = 33846,
    SPELL_EMPOWERING_SHADOWS    = 33783,
    H_SPELL_EMPOWERING_SHADOWS  = 39364,

    NPC_VOID_PORTAL             = 19224,
    SPELL_VOID_PORTAL_VISUAL    = 33569
};

float VorpilPosition[3] = {-252.8820f, -264.3030f, 17.1f};

float VoidPortalCoords[5][3] =
{
    {-283.5894f, -239.5718f, 12.7f},
    {-306.5853f, -258.4539f, 12.7f},
    {-295.8789f, -269.0899f, 12.7f},
    {-209.3401f, -262.7564f, 17.1f},
    {-261.4533f, -297.3298f, 17.1f}
};

enum Events
{
    EVENT_SHADOWBOLT_VOLLEY     = 1,
    EVENT_BANISH                = 2,
    EVENT_DRAW_SHADOWS          = 3,
    EVENT_SUMMON_TRAVELER       = 4
};

class npc_voidtraveler : public CreatureScript
{
public:
    npc_voidtraveler() : CreatureScript("npc_voidtraveler") { }

    struct npc_voidtravelerAI : public ScriptedAI
    {
        npc_voidtravelerAI(Creature* creature) : ScriptedAI(creature) {}

        uint64 VorpilGUID;
        uint32 move;
        bool sacrificed;

        void Reset()
        {
            VorpilGUID = 0;
            move = 0;
            sacrificed = false;
        }

        void EnterCombat(Unit* /*who*/){}

        void UpdateAI(uint32 diff)
        {
            if (!VorpilGUID)
            {
                me->Kill(me);
                return;
            }
            if (move <= diff)
            {
                Creature* Vorpil = Unit::GetCreature(*me, VorpilGUID);
                if (!Vorpil)
                {
                    VorpilGUID = 0;
                    return;
                }

                if (sacrificed)
                {
                    me->AddAura(DUNGEON_MODE(SPELL_EMPOWERING_SHADOWS, H_SPELL_EMPOWERING_SHADOWS), Vorpil);
                    Vorpil->ModifyHealth(int32(Vorpil->CountPctFromMaxHealth(4)));
                    DoCast(me, SPELL_SHADOW_NOVA, true);
                    me->Kill(me);
                    return;
                }
                me->GetMotionMaster()->MoveFollow(Vorpil, 0, 0);
                if (me->IsWithinDist(Vorpil, 3))
                {
                    DoCast(me, SPELL_SACRIFICE, false);
                    sacrificed = true;
                    move = 500;
                    return;
                }
                if (!Vorpil->IsInCombat() || Vorpil->isDead())
                {
                    me->Kill(me);
                    return;
                }
                move = 1000;
            } else move -= diff;
        }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_voidtravelerAI (creature);
        }
    };

};

class boss_grandmaster_vorpil : public CreatureScript
{
public:
    boss_grandmaster_vorpil() : CreatureScript("boss_grandmaster_vorpil") { }

    struct boss_grandmaster_vorpilAI : public BossAI
    {
        boss_grandmaster_vorpilAI(Creature* creature) : BossAI(creature, DATA_GRANDMASTERVORPIL)
        {
            Intro = false;
        }

        void Reset()
        {
            HelpYell = false;
            sumportals = false;
            destroyPortals();

            if (instance)
                instance->SetData(DATA_GRANDMASTERVORPILEVENT, NOT_STARTED);
        }

        void summonPortals()
        {
            if (!sumportals)
            {
                for (uint8 i = 0; i < 5; ++i)
                {
                    Creature* Portal = NULL;
                    Portal = me->SummonCreature(NPC_VOID_PORTAL, VoidPortalCoords[i][0], VoidPortalCoords[i][1], VoidPortalCoords[i][2], 0, TEMPSUMMON_CORPSE_DESPAWN, 3000000);
                    if (Portal)
                    {
                        PortalsGuid[i] = Portal->GetGUID();
                        Portal->CastSpell(Portal, SPELL_VOID_PORTAL_VISUAL, false);
                    }
                }
                sumportals = true;
                events.ScheduleEvent(EVENT_SUMMON_TRAVELER, 5000);
            }
        }

        void destroyPortals()
        {
            if (sumportals)
            {
                for (uint8 i = 0; i < 5; ++i)
                {
                    Unit* Portal = Unit::GetUnit(*me, PortalsGuid[i]);
                    if (Portal && Portal->IsAlive())
                        Portal->DealDamage(Portal, Portal->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                    PortalsGuid[i] = 0;
                }
                sumportals = false;
            }
        }

        void spawnVoidTraveler()
        {
            int pos = urand(0, 4);
            me->SummonCreature(NPC_VOID_TRAVELER, VoidPortalCoords[pos][0], VoidPortalCoords[pos][1], VoidPortalCoords[pos][2], 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
            if (!HelpYell)
            {
                Talk(SAY_HELP);
                HelpYell = true;
            }
        }

        void JustSummoned(Creature* summoned)
        {
            if (summoned && summoned->GetEntry() == NPC_VOID_TRAVELER)
                CAST_AI(npc_voidtraveler::npc_voidtravelerAI, summoned->AI())->VorpilGUID = me->GetGUID();
        }

        void KilledUnit(Unit* /*victim*/)
        {
            Talk(SAY_SLAY);
        }

        void JustDied(Unit* /*killer*/)
        {
            Talk(SAY_DEATH);
            destroyPortals();

            if (instance)
                instance->SetData(DATA_GRANDMASTERVORPILEVENT, DONE);
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_SHADOWBOLT_VOLLEY, urand(7000, 14000));
            if (IsHeroic())
                events.ScheduleEvent(EVENT_BANISH, 17000);
            events.ScheduleEvent(EVENT_DRAW_SHADOWS, 45000);
            events.ScheduleEvent(EVENT_SUMMON_TRAVELER, 90000);

            Talk(SAY_AGGRO);
            summonPortals();

            if (instance)
                instance->SetData(DATA_GRANDMASTERVORPILEVENT, IN_PROGRESS);
            _EnterCombat();
        }

        void MoveInLineOfSight(Unit* who)
        {
            ScriptedAI::MoveInLineOfSight(who);

            if (!Intro && me->IsWithinLOSInMap(who)&& me->IsWithinDistInMap(who, 100) && me->IsValidAttackTarget(who))
            {
                Talk(SAY_INTRO);
                Intro = true;
            }
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

                events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SHADOWBOLT_VOLLEY:
                        DoCast(me, SPELL_SHADOWBOLT_VOLLEY);
                        events.ScheduleEvent(EVENT_SHADOWBOLT_VOLLEY, urand(15000, 30000));
                        break;
                    case EVENT_BANISH:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 30, false))
                             DoCast(target, SPELL_BANISH);
                        events.ScheduleEvent(EVENT_BANISH, 16000);
                        break;
                    case EVENT_DRAW_SHADOWS:
                        {
                            Map* map = me->GetMap();
                            Map::PlayerList const &PlayerList = map->GetPlayers();
                            for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                                if (Player* i_pl = i->GetSource())
                                    if (i_pl->IsAlive() && !i_pl->HasAura(SPELL_BANISH))
                                        i_pl->TeleportTo(me->GetMapId(), VorpilPosition[0], VorpilPosition[1], VorpilPosition[2], 0, TELE_TO_NOT_LEAVE_COMBAT);

                            me->SetPosition(VorpilPosition[0], VorpilPosition[1], VorpilPosition[2], 0.0f);
                            DoCast(me, SPELL_DRAW_SHADOWS, true);
                            DoCast(me, SPELL_RAIN_OF_FIRE);
                            events.ScheduleEvent(EVENT_SHADOWBOLT_VOLLEY, 6000);
                            events.ScheduleEvent(EVENT_DRAW_SHADOWS, 30000);
                            break;
                        }
                    case EVENT_SUMMON_TRAVELER:
                        spawnVoidTraveler();
                        events.ScheduleEvent(EVENT_SUMMON_TRAVELER, 10000);
                        //enrage at 20%
                        if (HealthBelowPct(20))
                            events.ScheduleEvent(EVENT_SUMMON_TRAVELER, 5000);
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }

        private:
            bool Intro, HelpYell;
            bool sumportals;
            uint64 PortalsGuid[5];

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_grandmaster_vorpilAI (creature);
        }
    };

};

void AddSC_boss_grandmaster_vorpil()
{
    new boss_grandmaster_vorpil();
    new npc_voidtraveler();
}
