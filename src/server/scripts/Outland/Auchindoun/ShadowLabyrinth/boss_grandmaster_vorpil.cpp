/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

/* ScriptData
SDName: Boss_Grandmaster_Vorpil
SD%Complete: 100
SDComment:
SDCategory: Auchindoun, Shadow Labyrinth
EndScriptData */

#include "ScriptPCH.h"
#include "shadow_labyrinth.h"

#define SAY_INTRO                       -1555028
#define SAY_AGGRO1                      -1555029
#define SAY_AGGRO2                      -1555030
#define SAY_AGGRO3                      -1555031
#define SAY_HELP                        -1555032
#define SAY_SLAY1                       -1555033
#define SAY_SLAY2                       -1555034
#define SAY_DEATH                       -1555035

#define SPELL_RAIN_OF_FIRE          33617
#define H_SPELL_RAIN_OF_FIRE        39363

#define SPELL_DRAW_SHADOWS          33563
#define SPELL_SHADOWBOLT_VOLLEY     33841
#define SPELL_BANISH                38791

#define MOB_VOID_TRAVELER           19226
#define SPELL_SACRIFICE             33587
#define SPELL_SHADOW_NOVA           33846
#define SPELL_EMPOWERING_SHADOWS    33783
#define H_SPELL_EMPOWERING_SHADOWS  39364

#define MOB_VOID_PORTAL             19224
#define SPELL_VOID_PORTAL_VISUAL    33569

float VorpilPosition[3] = {-252.8820f, -264.3030f, 17.1f};

float VoidPortalCoords[5][3] =
{
    {-283.5894f, -239.5718f, 12.7f},
    {-306.5853f, -258.4539f, 12.7f},
    {-295.8789f, -269.0899f, 12.7f},
    {-209.3401f, -262.7564f, 17.1f},
    {-261.4533f, -297.3298f, 17.1f}
};

class mob_voidtraveler : public CreatureScript
{
public:
    mob_voidtraveler() : CreatureScript("mob_voidtraveler") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_voidtravelerAI (pCreature);
    }

    struct mob_voidtravelerAI : public ScriptedAI
    {
        mob_voidtravelerAI(Creature *c) : ScriptedAI(c)
        {
        }

        uint64 VorpilGUID;
        uint32 move;
        bool sacrificed;

        void Reset()
        {
            VorpilGUID = 0;
            move = 0;
            sacrificed = false;
        }

        void EnterCombat(Unit * /*who*/){}

        void UpdateAI(const uint32 diff)
        {
            if (!VorpilGUID)
            {
                me->Kill(me);
                return;
            }
            if (move <= diff)
            {
                Creature *Vorpil = Unit::GetCreature(*me, VorpilGUID);
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
                if (!Vorpil->isInCombat() || Vorpil->isDead())
                {
                    me->Kill(me);
                    return;
                }
                move = 1000;
            } else move -= diff;
        }
    };

};

class boss_grandmaster_vorpil : public CreatureScript
{
public:
    boss_grandmaster_vorpil() : CreatureScript("boss_grandmaster_vorpil") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_grandmaster_vorpilAI (pCreature);
    }

    struct boss_grandmaster_vorpilAI : public ScriptedAI
    {
        boss_grandmaster_vorpilAI(Creature *c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
            Intro = false;
        }

        InstanceScript *pInstance;
        bool Intro, HelpYell;
        bool sumportals;

        uint32 ShadowBoltVolley_Timer;
        uint32 DrawShadows_Timer;
        uint32 summonTraveler_Timer;
        uint32 banish_Timer;
        uint64 PortalsGuid[5];

        void Reset()
        {
            ShadowBoltVolley_Timer = 7000 + rand()%7000;
            DrawShadows_Timer = 45000;
            summonTraveler_Timer = 90000;
            banish_Timer = 17000;
            HelpYell = false;
            destroyPortals();

            if (pInstance)
                pInstance->SetData(DATA_GRANDMASTERVORPILEVENT, NOT_STARTED);
        }

        void summonPortals()
        {
            if (!sumportals)
            {
                for (uint8 i = 0; i < 5; ++i)
                {
                    Creature *Portal = NULL;
                    Portal = me->SummonCreature(MOB_VOID_PORTAL, VoidPortalCoords[i][0], VoidPortalCoords[i][1], VoidPortalCoords[i][2], 0, TEMPSUMMON_CORPSE_DESPAWN, 3000000);
                    if (Portal)
                    {
                        PortalsGuid[i] = Portal->GetGUID();
                        Portal->CastSpell(Portal, SPELL_VOID_PORTAL_VISUAL, false);
                    }
                }
                sumportals = true;
                summonTraveler_Timer = 5000;
            }
        }

        void destroyPortals()
        {
            if (sumportals)
            {
                for (uint8 i = 0; i < 5; ++i)
                {
                    Unit *Portal = Unit::GetUnit((*me), PortalsGuid[i]);
                    if (Portal && Portal->isAlive())
                        Portal->DealDamage(Portal, Portal->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                    PortalsGuid[i] = 0;
                }
                sumportals = false;
            }
        }

        void spawnVoidTraveler()
        {
            int pos = urand(0, 4);
            me->SummonCreature(MOB_VOID_TRAVELER, VoidPortalCoords[pos][0], VoidPortalCoords[pos][1], VoidPortalCoords[pos][2], 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
            if (!HelpYell)
            {
                DoScriptText(SAY_HELP, me);
                HelpYell = true;
            }
        }

        void JustSummoned(Creature *summoned)
        {
            if (summoned && summoned->GetEntry() == MOB_VOID_TRAVELER)
                CAST_AI(mob_voidtraveler::mob_voidtravelerAI, summoned->AI())->VorpilGUID = me->GetGUID();
        }

        void KilledUnit(Unit * /*victim*/)
        {
            DoScriptText(RAND(SAY_SLAY1, SAY_SLAY2), me);
        }

        void JustDied(Unit * /*victim*/)
        {
            DoScriptText(SAY_DEATH, me);
            destroyPortals();

            if (pInstance)
                pInstance->SetData(DATA_GRANDMASTERVORPILEVENT, DONE);
        }

        void EnterCombat(Unit * /*who*/)
        {
            DoScriptText(RAND(SAY_AGGRO1, SAY_AGGRO2, SAY_AGGRO3), me);
            summonPortals();

            if (pInstance)
                pInstance->SetData(DATA_GRANDMASTERVORPILEVENT, IN_PROGRESS);
        }

        void MoveInLineOfSight(Unit *who)
        {
            ScriptedAI::MoveInLineOfSight(who);

            if (!Intro && me->IsWithinLOSInMap(who)&& me->IsWithinDistInMap(who, 100) && me->IsHostileTo(who))
            {
                DoScriptText(SAY_INTRO, me);
                Intro = true;
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (ShadowBoltVolley_Timer <= diff)
            {
                DoCast(me, SPELL_SHADOWBOLT_VOLLEY);
                ShadowBoltVolley_Timer = 15000 + rand()%15000;
            } else ShadowBoltVolley_Timer -= diff;

            if (IsHeroic() && banish_Timer <= diff)
            {
                Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 30, false);
                if (pTarget)
                {
                    DoCast(pTarget, SPELL_BANISH);
                    banish_Timer = 16000;
                }
            } else banish_Timer -= diff;

            if (DrawShadows_Timer <= diff)
            {
                Map* pMap = me->GetMap();
                Map::PlayerList const &PlayerList = pMap->GetPlayers();
                for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                    if (Player* i_pl = i->getSource())
                        if (i_pl->isAlive() && !i_pl->HasAura(SPELL_BANISH))
                            i_pl->TeleportTo(me->GetMapId(), VorpilPosition[0], VorpilPosition[1], VorpilPosition[2], 0, TELE_TO_NOT_LEAVE_COMBAT);

                me->GetMap()->CreatureRelocation(me, VorpilPosition[0], VorpilPosition[1], VorpilPosition[2], 0.0f);
                DoCast(me, SPELL_DRAW_SHADOWS, true);

                DoCast(me, SPELL_RAIN_OF_FIRE);

                ShadowBoltVolley_Timer = 6000;
                DrawShadows_Timer = 30000;
            } else DrawShadows_Timer -= diff;

            if (summonTraveler_Timer <= diff)
            {
                spawnVoidTraveler();
                summonTraveler_Timer = 10000;
                //enrage at 20%
                if (HealthBelowPct(20))
                    summonTraveler_Timer = 5000;
            } else summonTraveler_Timer -=diff;

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_grandmaster_vorpil()
{
    new boss_grandmaster_vorpil();
    new mob_voidtraveler();
}
