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
Name: Boss_Vazruden_the_Herald
%Complete: 90
Comment:
Category: Hellfire Citadel, Hellfire Ramparts
EndScriptData */

#include "ScriptPCH.h"

enum eSpells
{
    SPELL_FIREBALL                = 34653,
    SPELL_FIREBALL_H              = 36920,
    SPELL_CONE_OF_FIRE            = 30926,
    SPELL_CONE_OF_FIRE_H          = 36921,
    SPELL_SUMMON_LIQUID_FIRE      = 23971,
    SPELL_SUMMON_LIQUID_FIRE_H    = 30928,
    SPELL_BELLOWING_ROAR          = 39427,
    SPELL_REVENGE                 = 19130,
    SPELL_REVENGE_H               = 40392,
    SPELL_KIDNEY_SHOT             = 30621,
    SPELL_FIRE_NOVA_VISUAL        = 19823,
};

enum eUnits
{
    ENTRY_HELLFIRE_SENTRY             = 17517,
    ENTRY_VAZRUDEN_HERALD             = 17307,
    ENTRY_VAZRUDEN                    = 17537,
    ENTRY_NAZAN                       = 17536,
    ENTRY_LIQUID_FIRE                 = 22515,
    ENTRY_REINFORCED_FEL_IRON_CHEST   = 185168,
    ENTRY_REINFORCED_FEL_IRON_CHEST_H = 185169,
};

enum eSays
{
    SAY_INTRO                     = -1543017,
    SAY_WIPE                      = -1543018,
    SAY_AGGRO_1                   = -1543019,
    SAY_AGGRO_2                   = -1543020,
    SAY_AGGRO_3                   = -1543021,
    SAY_KILL_1                    = -1543022,
    SAY_KILL_2                    = -1543023,
    SAY_DIE                       = -1543024,
    EMOTE                         = -1543025,
};

const float VazrudenMiddle[3] = {-1406.5f, 1746.5f, 81.2f};
const float VazrudenRing[2][3] =
{
    {-1430, 1705, 112},
    {-1377, 1760, 112}
};

class boss_nazan : public CreatureScript
{
    public:

        boss_nazan()
            : CreatureScript("boss_nazan")
        {
        }

        struct boss_nazanAI : public ScriptedAI
        {
            boss_nazanAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                VazrudenGUID = 0;
                flight = true;
            }

            uint32 Fireball_Timer;
            uint32 ConeOfFire_Timer;
            uint32 BellowingRoar_Timer;
            uint32 Fly_Timer;
            uint32 Turn_Timer;
            bool flight;
            uint64 VazrudenGUID;
            SpellEntry *liquid_fire;

            void Reset()
            {
                Fireball_Timer = 4000;
                Fly_Timer = 45000;
                Turn_Timer = 0;
            }

            void EnterCombat(Unit* /*who*/) {}

            void JustSummoned(Creature *summoned)
            {
                if (summoned && summoned->GetEntry() == ENTRY_LIQUID_FIRE)
                {
                    summoned->SetLevel(me->getLevel());
                    summoned->setFaction(me->getFaction());
                    summoned->CastSpell(summoned, DUNGEON_MODE(SPELL_SUMMON_LIQUID_FIRE, SPELL_SUMMON_LIQUID_FIRE_H), true);
                    summoned->CastSpell(summoned, SPELL_FIRE_NOVA_VISUAL, true);
                }
            }

            void SpellHitTarget(Unit *pTarget, const SpellEntry* entry)
            {
                if (pTarget && entry->Id == uint32(SPELL_FIREBALL))
                    me->SummonCreature(ENTRY_LIQUID_FIRE, pTarget->GetPositionX(), pTarget->GetPositionY(), pTarget->GetPositionZ(), pTarget->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 30000);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (Fireball_Timer <= diff)
                {
                    if (Unit* pVictim = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(pVictim, DUNGEON_MODE(SPELL_FIREBALL, SPELL_FIREBALL_H), true);
                    Fireball_Timer = urand(4000, 7000);
                }
                else
                    Fireball_Timer -= diff;

                if (flight) // phase 1 - the flight
                {
                    Creature *Vazruden = Unit::GetCreature(*me, VazrudenGUID);
                    if (Fly_Timer < diff || !(Vazruden && Vazruden->isAlive() && Vazruden->HealthAbovePct(20)))
                    {
                        flight = false;
                        BellowingRoar_Timer = 6000;
                        ConeOfFire_Timer = 12000;
                        me->RemoveUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                        me->AddUnitMovementFlag(MOVEMENTFLAG_WALKING);
                        me->GetMotionMaster()->Clear();
                        if (Unit* pVictim = SelectTarget(SELECT_TARGET_NEAREST, 0))
                            me->AI()->AttackStart(pVictim);
                        DoStartMovement(me->getVictim());
                        DoScriptText(EMOTE, me);
                        return;
                    }
                    else
                        Fly_Timer -= diff;

                    if (Turn_Timer <= diff)
                    {
                        uint32 waypoint = (Fly_Timer/10000)%2;
                        if (!me->IsWithinDist3d(VazrudenRing[waypoint][0], VazrudenRing[waypoint][1], VazrudenRing[waypoint][2], 5))
                            me->GetMotionMaster()->MovePoint(0, VazrudenRing[waypoint][0], VazrudenRing[waypoint][1], VazrudenRing[waypoint][2]);
                        Turn_Timer = 10000;
                    }
                    else
                        Turn_Timer -= diff;
                }
                else // phase 2 - land fight
                {
                    if (ConeOfFire_Timer <= diff)
                    {
                        DoCast(me, DUNGEON_MODE(SPELL_CONE_OF_FIRE, SPELL_CONE_OF_FIRE_H));
                        ConeOfFire_Timer = 12000;
                        Fireball_Timer = 4000;
                    }
                    else
                        ConeOfFire_Timer -= diff;

                    if (IsHeroic())
                    {
                        if (BellowingRoar_Timer <= diff)
                        {
                            DoCast(me, SPELL_BELLOWING_ROAR);
                            BellowingRoar_Timer = 45000;
                        }
                        else
                            BellowingRoar_Timer -= diff;
                    }

                    DoMeleeAttackIfReady();
                }
            }
        };

        CreatureAI* GetAI(Creature* Creature) const
        {
            return new boss_nazanAI (Creature);
        }
};

class boss_vazruden : public CreatureScript
{
    public:

        boss_vazruden()
            : CreatureScript("boss_vazruden")
        {
        }
        struct boss_vazrudenAI : public ScriptedAI
        {
            boss_vazrudenAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
            }

            uint32 Revenge_Timer;
            bool WipeSaid;
            uint32 UnsummonCheck;

            void Reset()
            {
                Revenge_Timer = 4000;
                UnsummonCheck = 2000;
                WipeSaid = false;
            }

            void EnterCombat(Unit * /*who*/)
            {
                DoScriptText(RAND(SAY_AGGRO_1, SAY_AGGRO_2, SAY_AGGRO_3), me);
            }

            void KilledUnit(Unit* who)
            {
                if (who && who->GetEntry() != ENTRY_VAZRUDEN)
                    DoScriptText(RAND(SAY_KILL_1, SAY_KILL_2), me);
            }

            void JustDied(Unit* who)
            {
                if (who && who != me)
                    DoScriptText(SAY_DIE, me);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                {
                    if (UnsummonCheck < diff && me->isAlive())
                    {
                        if (!WipeSaid)
                        {
                            DoScriptText(SAY_WIPE, me);
                            WipeSaid = true;
                        }
                        me->DisappearAndDie();
                    }
                    else
                        UnsummonCheck -= diff;
                    return;
                }

                if (Revenge_Timer <= diff)
                {
                    if (Unit *victim = me->getVictim())
                        DoCast(victim, DUNGEON_MODE(SPELL_REVENGE, SPELL_REVENGE_H));
                    Revenge_Timer = 5000;
                }
                else
                    Revenge_Timer -= diff;

                DoMeleeAttackIfReady();
            }
        };
        CreatureAI* GetAI(Creature* Creature) const
        {
            return new boss_vazrudenAI (Creature);
        }
};

class boss_vazruden_the_herald : public CreatureScript
{
    public:

        boss_vazruden_the_herald()
            : CreatureScript("boss_vazruden_the_herald")
        {
        }

        struct boss_vazruden_the_heraldAI : public ScriptedAI
        {
            boss_vazruden_the_heraldAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                summoned = false;
                sentryDown = false;
                lootSpawned = false;
                NazanGUID = 0;
                VazrudenGUID = 0;
            }

            uint32 phase;
            uint32 waypoint;
            uint32 check;
            bool sentryDown;
            uint64 NazanGUID;
            uint64 VazrudenGUID;
            bool summoned;
            bool lootSpawned;

            void Reset()
            {
                phase = 0;
                waypoint = 0;
                check = 0;
                UnsummonAdds();
            }

            void UnsummonAdds()
            {
                if (summoned)
                {
                    Creature *Nazan = Unit::GetCreature(*me, NazanGUID);
                    if (!Nazan)
                        Nazan = me->FindNearestCreature(ENTRY_NAZAN, 5000);
                    if (Nazan)
                    {
                        Nazan->DisappearAndDie();
                        NazanGUID = 0;
                    }

                    Creature *Vazruden = Unit::GetCreature(*me, VazrudenGUID);
                    if (!Vazruden)
                        Vazruden = me->FindNearestCreature(ENTRY_VAZRUDEN, 5000);
                    if (Vazruden)
                    {
                        Vazruden->DisappearAndDie();
                        VazrudenGUID = 0;
                    }
                    summoned = false;
                    me->ClearUnitState(UNIT_STAT_ROOT);
                    me->SetVisible(true);
                }
            }

            void SummonAdds()
            {
                if (!summoned)
                {
                    if (Creature* Vazruden = me->SummonCreature(ENTRY_VAZRUDEN, VazrudenMiddle[0], VazrudenMiddle[1], VazrudenMiddle[2], 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 6000000))
                        VazrudenGUID = Vazruden->GetGUID();
                    if (Creature* Nazan = me->SummonCreature(ENTRY_NAZAN, VazrudenMiddle[0], VazrudenMiddle[1], VazrudenMiddle[2], 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 6000000))
                        NazanGUID = Nazan->GetGUID();
                    summoned = true;
                    me->SetVisible(false);
                    me->AddUnitState(UNIT_STAT_ROOT);
                }
            }

            void EnterCombat(Unit* /*who*/)
            {
                if (phase == 0)
                {
                    phase = 1;
                    check = 0;
                    DoScriptText(SAY_INTRO, me);
                }
            }

            void JustSummoned(Creature* pSummoned)
            {
                if (!pSummoned)
                    return;
                Unit* pVictim = me->getVictim();
                if (pSummoned->GetEntry() == ENTRY_NAZAN)
                {
                    CAST_AI(boss_nazan::boss_nazanAI, pSummoned->AI())->VazrudenGUID = VazrudenGUID;
                    pSummoned->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                    pSummoned->SetSpeed(MOVE_FLIGHT, 2.5f);
                    if (pVictim)
                        AttackStartNoMove(pVictim);
                }
                else
                    if (pVictim)
                        pSummoned->AI()->AttackStart(pVictim);
            }

            void SentryDownBy(Unit* pKiller)
            {
                if (sentryDown)
                {
                    AttackStartNoMove(pKiller);
                    sentryDown = false;
                }
                else
                    sentryDown = true;
            }

            void UpdateAI(const uint32 diff)
            {
                switch(phase)
                {
                case 0: // circle around the platform
                    return;
                    break;
                case 1: // go to the middle and begin the fight
                    if (check <= diff)
                    {
                        if (!me->IsWithinDist3d(VazrudenMiddle[0], VazrudenMiddle[1], VazrudenMiddle[2], 5))
                        {
                            me->GetMotionMaster()->Clear();
                            me->GetMotionMaster()->MovePoint(0, VazrudenMiddle[0], VazrudenMiddle[1], VazrudenMiddle[2]);
                            check = 1000;
                        }
                        else
                        {
                            SummonAdds();
                            phase = 2;
                            return;
                        }
                    }
                    else
                        check -= diff;
                    break;
                default: // adds do the job now
                    if (check <= diff)
                    {
                        Creature *Nazan = Unit::GetCreature(*me, NazanGUID);
                        Creature *Vazruden = Unit::GetCreature(*me, VazrudenGUID);
                        if ((Nazan && Nazan->isAlive()) || (Vazruden && Vazruden->isAlive()))
                        {
                            if ((Nazan && Nazan->getVictim()) || (Vazruden && Vazruden->getVictim()))
                                return;
                            else
                            {
                                UnsummonAdds();
                                EnterEvadeMode();
                                return;
                            }
                        }
                        else if (!lootSpawned)
                        {
                            me->SummonGameObject(DUNGEON_MODE(ENTRY_REINFORCED_FEL_IRON_CHEST, ENTRY_REINFORCED_FEL_IRON_CHEST_H), VazrudenMiddle[0], VazrudenMiddle[1], VazrudenMiddle[2], 0, 0, 0, 0, 0, 0);
                            me->SetLootRecipient(NULL); // don't think this is necessary..
                            //me->Kill(me);
                            lootSpawned = true;
                        }
                        check = 2000;
                    }
                    else
                        check -= diff;
                    break;
                }
            }
        };

        CreatureAI* GetAI(Creature* Creature) const
        {
            return new boss_vazruden_the_heraldAI (Creature);
        }
};

class mob_hellfire_sentry : public CreatureScript
{
    public:

        mob_hellfire_sentry()
            : CreatureScript("mob_hellfire_sentry")
        {
        }
        struct mob_hellfire_sentryAI : public ScriptedAI
        {
            mob_hellfire_sentryAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 KidneyShot_Timer;

            void Reset()
            {
                KidneyShot_Timer = urand(3000, 7000);
            }

            void EnterCombat(Unit* /*who*/) {}

            void JustDied(Unit* who)
            {
                if (Creature *herald = me->FindNearestCreature(ENTRY_VAZRUDEN_HERALD, 150))
                    CAST_AI(boss_vazruden_the_herald::boss_vazruden_the_heraldAI, herald->AI())->SentryDownBy(who);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (KidneyShot_Timer <= diff)
                {
                    if (Unit *victim = me->getVictim())
                        DoCast(victim, SPELL_KIDNEY_SHOT);
                    KidneyShot_Timer = 20000;
                }
                else
                    KidneyShot_Timer -= diff;

                DoMeleeAttackIfReady();
            }
        };
        CreatureAI* GetAI(Creature* Creature) const
        {
            return new mob_hellfire_sentryAI (Creature);
        }
};
void AddSC_boss_vazruden_the_herald()
{
    new boss_vazruden_the_herald();
    new boss_vazruden();
    new boss_nazan();
    new mob_hellfire_sentry();
}

