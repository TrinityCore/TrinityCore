/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "hellfire_ramparts.h"

enum Says
{
    SAY_INTRO                     = 0,

    SAY_WIPE                      = 0,
    SAY_AGGRO                     = 1,
    SAY_KILL                      = 2,
    SAY_DIE                       = 3,

    EMOTE                         = 0
};

enum Spells
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
    SPELL_FIRE_NOVA_VISUAL        = 19823
};

const float VazrudenMiddle[3] = { -1406.5f, 1746.5f, 81.2f };

const float VazrudenRing[2][3] =
{
    { -1430.0f, 1705.0f, 112.0f },
    { -1377.0f, 1760.0f, 112.0f }
};

class boss_nazan : public CreatureScript
{
    public:
        boss_nazan() : CreatureScript("boss_nazan") { }

        struct boss_nazanAI : public BossAI
        {
            boss_nazanAI(Creature* creature) : BossAI(creature, DATA_NAZAN)
            {
                VazrudenGUID = 0;
                flight = true;
            }

            void Reset() OVERRIDE
            {
                Fireball_Timer = 4000;
                Fly_Timer = 45000;
                Turn_Timer = 0;
            }

            void EnterCombat(Unit* /*who*/) OVERRIDE { }

            void IsSummonedBy(Unit* summoner) OVERRIDE
            {
                if (summoner->GetEntry() == NPC_VAZRUDEN_HERALD)
                    VazrudenGUID = summoner->GetGUID();
            }

            void JustSummoned(Creature* summoned) OVERRIDE
            {
                if (summoned && summoned->GetEntry() == NPC_LIQUID_FIRE)
                {
                    summoned->SetLevel(me->getLevel());
                    summoned->setFaction(me->getFaction());
                    summoned->CastSpell(summoned, DUNGEON_MODE(SPELL_SUMMON_LIQUID_FIRE, SPELL_SUMMON_LIQUID_FIRE_H), true);
                    summoned->CastSpell(summoned, SPELL_FIRE_NOVA_VISUAL, true);
                }
            }

            void SpellHitTarget(Unit* target, const SpellInfo* entry) OVERRIDE
            {
                if (target && entry->Id == uint32(SPELL_FIREBALL))
                    me->SummonCreature(NPC_LIQUID_FIRE, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), target->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 30000);
            }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                if (!UpdateVictim())
                    return;

                if (Fireball_Timer <= diff)
                {
                    if (Unit* victim = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(victim, DUNGEON_MODE(SPELL_FIREBALL, SPELL_FIREBALL_H), true);
                    Fireball_Timer = urand(4000, 7000);
                }
                else
                    Fireball_Timer -= diff;

                if (flight) // phase 1 - the flight
                {
                    Creature* Vazruden = Unit::GetCreature(*me, VazrudenGUID);
                    if (Fly_Timer < diff || !(Vazruden && Vazruden->IsAlive() && Vazruden->HealthAbovePct(20)))
                    {
                        flight = false;
                        BellowingRoar_Timer = 6000;
                        ConeOfFire_Timer = 12000;
                        me->SetDisableGravity(false);
                        me->SetWalk(true);
                        me->GetMotionMaster()->Clear();
                        if (Unit* victim = SelectTarget(SELECT_TARGET_NEAREST, 0))
                            me->AI()->AttackStart(victim);
                        DoStartMovement(me->GetVictim());
                        Talk(EMOTE);
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

            private:
                uint32 Fireball_Timer;
                uint32 ConeOfFire_Timer;
                uint32 BellowingRoar_Timer;
                uint32 Fly_Timer;
                uint32 Turn_Timer;
                bool flight;
                uint64 VazrudenGUID;
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return new boss_nazanAI(creature);
        }
};

class boss_vazruden : public CreatureScript
{
    public:
        boss_vazruden() : CreatureScript("boss_vazruden") { }

        struct boss_vazrudenAI : public BossAI
        {
            boss_vazrudenAI(Creature* creature) : BossAI(creature, DATA_VAZRUDEN) { }

            void Reset() OVERRIDE
            {
                Revenge_Timer = 4000;
                UnsummonCheck = 2000;
                WipeSaid = false;
                _Reset();
            }

            void EnterCombat(Unit* /*who*/) OVERRIDE
            {
                Talk(SAY_AGGRO);
                _EnterCombat();
            }

            void KilledUnit(Unit* who) OVERRIDE
            {
                if (who && who->GetEntry() != NPC_VAZRUDEN)
                    Talk(SAY_KILL);
            }

            void JustDied(Unit* killer) OVERRIDE
            {
                if (killer && killer != me)
                    Talk(SAY_DIE);
                _JustDied();
            }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                if (!UpdateVictim())
                {
                    if (UnsummonCheck < diff && me->IsAlive())
                    {
                        if (!WipeSaid)
                        {
                            Talk(SAY_WIPE);
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
                    if (Unit* victim = me->GetVictim())
                        DoCast(victim, DUNGEON_MODE(SPELL_REVENGE, SPELL_REVENGE_H));
                    Revenge_Timer = 5000;
                }
                else
                    Revenge_Timer -= diff;

                DoMeleeAttackIfReady();
            }

            private:
                uint32 Revenge_Timer;
                bool WipeSaid;
                uint32 UnsummonCheck;
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return new boss_vazrudenAI(creature);
        }
};

class boss_vazruden_the_herald : public CreatureScript
{
    public:
        boss_vazruden_the_herald() : CreatureScript("boss_vazruden_the_herald") { }

        struct boss_vazruden_the_heraldAI : public ScriptedAI
        {
            boss_vazruden_the_heraldAI(Creature* creature) : ScriptedAI(creature)
            {
                summoned = false;
                sentryDown = false;
                lootSpawned = false;
                NazanGUID = 0;
                VazrudenGUID = 0;
            }

            void Reset() OVERRIDE
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
                    Creature* Nazan = Unit::GetCreature(*me, NazanGUID);
                    if (!Nazan)
                        Nazan = me->FindNearestCreature(NPC_NAZAN, 5000);
                    if (Nazan)
                    {
                        Nazan->DisappearAndDie();
                        NazanGUID = 0;
                    }

                    Creature* Vazruden = Unit::GetCreature(*me, VazrudenGUID);
                    if (!Vazruden)
                        Vazruden = me->FindNearestCreature(NPC_VAZRUDEN, 5000);
                    if (Vazruden)
                    {
                        Vazruden->DisappearAndDie();
                        VazrudenGUID = 0;
                    }
                    summoned = false;
                    me->ClearUnitState(UNIT_STATE_ROOT);
                    me->SetVisible(true);
                }
            }

            void SummonAdds()
            {
                if (!summoned)
                {
                    if (Creature* Vazruden = me->SummonCreature(NPC_VAZRUDEN, VazrudenMiddle[0], VazrudenMiddle[1], VazrudenMiddle[2], 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 6000000))
                        VazrudenGUID = Vazruden->GetGUID();
                    if (Creature* Nazan = me->SummonCreature(NPC_NAZAN, VazrudenMiddle[0], VazrudenMiddle[1], VazrudenMiddle[2], 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 6000000))
                        NazanGUID = Nazan->GetGUID();
                    summoned = true;
                    me->SetVisible(false);
                    me->AddUnitState(UNIT_STATE_ROOT);
                }
            }

            void EnterCombat(Unit* /*who*/) OVERRIDE
            {
                if (phase == 0)
                {
                    phase = 1;
                    check = 0;
                    Talk(SAY_INTRO);
                }
            }

            void JustSummoned(Creature* summoned) OVERRIDE
            {
                if (!summoned)
                    return;
                Unit* victim = me->GetVictim();
                if (summoned->GetEntry() == NPC_NAZAN)
                {
                    summoned->SetDisableGravity(true);
                    summoned->SetSpeed(MOVE_FLIGHT, 2.5f);
                    if (victim)
                        AttackStartNoMove(victim);
                }
                else
                    if (victim)
                        summoned->AI()->AttackStart(victim);
            }

            void SentryDownBy(Unit* killer)
            {
                if (sentryDown)
                {
                    AttackStartNoMove(killer);
                    sentryDown = false;
                }
                else
                    sentryDown = true;
            }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                switch (phase)
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
                        Creature* Nazan = Unit::GetCreature(*me, NazanGUID);
                        Creature* Vazruden = Unit::GetCreature(*me, VazrudenGUID);
                        if ((Nazan && Nazan->IsAlive()) || (Vazruden && Vazruden->IsAlive()))
                        {
                            if ((Nazan && Nazan->GetVictim()) || (Vazruden && Vazruden->GetVictim()))
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
                            me->SummonGameObject(DUNGEON_MODE(GO_FEL_IRON_CHEST_NORMAL, GO_FEL_IRON_CHECT_HEROIC), VazrudenMiddle[0], VazrudenMiddle[1], VazrudenMiddle[2], 0, 0, 0, 0, 0, 0);
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

            private:
                uint32 phase;
                uint32 waypoint;
                uint32 check;
                bool sentryDown;
                uint64 NazanGUID;
                uint64 VazrudenGUID;
                bool summoned;
                bool lootSpawned;
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return new boss_vazruden_the_heraldAI(creature);
        }
};

class npc_hellfire_sentry : public CreatureScript
{
    public:
        npc_hellfire_sentry() : CreatureScript("npc_hellfire_sentry") { }

        struct npc_hellfire_sentryAI : public ScriptedAI
        {
            npc_hellfire_sentryAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset() OVERRIDE
            {
                KidneyShot_Timer = urand(3000, 7000);
            }

            void EnterCombat(Unit* /*who*/) OVERRIDE { }

            void JustDied(Unit* killer) OVERRIDE
            {
                if (Creature* herald = me->FindNearestCreature(NPC_VAZRUDEN_HERALD, 150))
                    CAST_AI(boss_vazruden_the_herald::boss_vazruden_the_heraldAI, herald->AI())->SentryDownBy(killer);
            }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                if (!UpdateVictim())
                    return;

                if (KidneyShot_Timer <= diff)
                {
                    if (Unit* victim = me->GetVictim())
                        DoCast(victim, SPELL_KIDNEY_SHOT);
                    KidneyShot_Timer = 20000;
                }
                else
                    KidneyShot_Timer -= diff;

                DoMeleeAttackIfReady();
            }

            private:
                uint32 KidneyShot_Timer;
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return new npc_hellfire_sentryAI(creature);
        }
};
void AddSC_boss_vazruden_the_herald()
{
    new boss_vazruden_the_herald();
    new boss_vazruden();
    new boss_nazan();
    new npc_hellfire_sentry();
}

