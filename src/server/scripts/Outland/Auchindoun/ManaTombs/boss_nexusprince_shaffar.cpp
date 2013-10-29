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

/* ScriptData
SDName: Boss_NexusPrince_Shaffar
SD%Complete: 80
SDComment: Need more tuning of spell timers, it should not be as linear fight as current. Also should possibly find a better way to deal with his three initial beacons to make sure all aggro.
SDCategory: Auchindoun, Mana Tombs
EndScriptData */

/* ContentData
boss_nexusprince_shaffar
npc_ethereal_beacon
EndContentData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"

enum Yells
{
    SAY_INTRO                       = 0,
    SAY_AGGRO                       = 1,
    SAY_SLAY                        = 2,
    SAY_SUMMON                      = 3,
    SAY_DEAD                        = 4,
};

enum Spells
{
    SPELL_BLINK                     = 34605,
    SPELL_FROSTBOLT                 = 32364,
    SPELL_FIREBALL                  = 32363,
    SPELL_FROSTNOVA                 = 32365,

    SPELL_ETHEREAL_BEACON           = 32371,                // Summons NPC_BEACON
    SPELL_ETHEREAL_BEACON_VISUAL    = 32368,

    // Ethereal Beacon
    SPELL_ARCANE_BOLT               = 15254,
    SPELL_ETHEREAL_APPRENTICE       = 32372                 // Summon 18430
};

enum Creatures
{
    NPC_BEACON                      = 18431,
    NPC_SHAFFAR                     = 18344
};

enum Misc
{
    NR_INITIAL_BEACONS              = 3
};

class boss_nexusprince_shaffar : public CreatureScript
{
public:
    boss_nexusprince_shaffar() : CreatureScript("boss_nexusprince_shaffar") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new boss_nexusprince_shaffarAI(creature);
    }

    struct boss_nexusprince_shaffarAI : public ScriptedAI
    {
        boss_nexusprince_shaffarAI(Creature* creature) : ScriptedAI(creature), summons(me) { HasTaunted = false; }

        uint32 Blink_Timer;
        uint32 Beacon_Timer;
        uint32 FireBall_Timer;
        uint32 Frostbolt_Timer;
        uint32 FrostNova_Timer;

        SummonList summons;

        bool HasTaunted;
        bool CanBlink;

        void Reset() OVERRIDE
        {
            Blink_Timer = 1500;
            Beacon_Timer = 10000;
            FireBall_Timer = 8000;
            Frostbolt_Timer = 4000;
            FrostNova_Timer = 15000;

            CanBlink = false;

            float dist = 8.0f;
            float posX, posY, posZ, angle;
            me->GetHomePosition(posX, posY, posZ, angle);

            me->SummonCreature(NPC_BEACON, posX - dist, posY - dist, posZ, angle, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 7200000);
            me->SummonCreature(NPC_BEACON, posX - dist, posY + dist, posZ, angle, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 7200000);
            me->SummonCreature(NPC_BEACON, posX + dist, posY, posZ, angle, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 7200000);
        }

        void EnterEvadeMode() OVERRIDE
        {
            summons.DespawnAll();
            ScriptedAI::EnterEvadeMode();
        }

        void MoveInLineOfSight(Unit* who) OVERRIDE

        {
            if (!HasTaunted && who->GetTypeId() == TYPEID_PLAYER && me->IsWithinDistInMap(who, 100.0f))
            {
                Talk(SAY_INTRO);
                HasTaunted = true;
            }
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            Talk(SAY_AGGRO);

            DoZoneInCombat();
            summons.DoZoneInCombat();
        }

        void JustSummoned(Creature* summoned) OVERRIDE
        {
            if (summoned->GetEntry() == NPC_BEACON)
            {
                summoned->CastSpell(summoned, SPELL_ETHEREAL_BEACON_VISUAL, false);

                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    summoned->AI()->AttackStart(target);
            }

            summons.Summon(summoned);
        }

        void SummonedCreatureDespawn(Creature* summon) OVERRIDE
        {
            summons.Despawn(summon);
        }

        void KilledUnit(Unit* /*victim*/) OVERRIDE
        {
            Talk(SAY_SLAY);
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            Talk(SAY_DEAD);
            summons.DespawnAll();
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!UpdateVictim())
                return;

            if (FrostNova_Timer <= diff)
            {
                if (me->IsNonMeleeSpellCasted(false))
                    me->InterruptNonMeleeSpells(true);

                DoCast(me, SPELL_FROSTNOVA);
                FrostNova_Timer  = urand(17500, 25000);
                CanBlink = true;
            } else FrostNova_Timer -= diff;

            if (Frostbolt_Timer <= diff)
            {
                DoCastVictim(SPELL_FROSTBOLT);
                Frostbolt_Timer = urand(4500, 6000);
            } else Frostbolt_Timer -= diff;

            if (FireBall_Timer <= diff)
            {
                DoCastVictim(SPELL_FIREBALL);
                FireBall_Timer = urand(4500, 6000);
            } else FireBall_Timer -= diff;

            if (CanBlink)
            {
                if (Blink_Timer <= diff)
                {
                    if (me->IsNonMeleeSpellCasted(false))
                        me->InterruptNonMeleeSpells(true);

                    //expire movement, will prevent from running right back to victim after cast
                    //(but should MoveChase be used again at a certain time or should he not move?)
                    if (me->GetMotionMaster()->GetCurrentMovementGeneratorType() == CHASE_MOTION_TYPE)
                        me->GetMotionMaster()->MovementExpired();

                    DoCast(me, SPELL_BLINK);
                    Blink_Timer = urand(1000, 2500);
                    CanBlink = false;
                } else Blink_Timer -= diff;
            }

            if (Beacon_Timer <= diff)
            {
                if (me->IsNonMeleeSpellCasted(false))
                    me->InterruptNonMeleeSpells(true);

                if (!urand(0, 3))
                    Talk(SAY_SUMMON);

                DoCast(me, SPELL_ETHEREAL_BEACON, true);

                Beacon_Timer = 10000;
            } else Beacon_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

class npc_ethereal_beacon : public CreatureScript
{
public:
    npc_ethereal_beacon() : CreatureScript("npc_ethereal_beacon") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_ethereal_beaconAI(creature);
    }

    struct npc_ethereal_beaconAI : public ScriptedAI
    {
        npc_ethereal_beaconAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        uint32 Apprentice_Timer;
        uint32 ArcaneBolt_Timer;
        uint32 Check_Timer;

        void KillSelf()
        {
            me->Kill(me);
        }

        void Reset() OVERRIDE
        {
            Apprentice_Timer = DUNGEON_MODE(20000, 10000);
            ArcaneBolt_Timer = 1000;
            Check_Timer = 1000;
        }

        void EnterCombat(Unit* who) OVERRIDE
        {
            // Send Shaffar to fight
            Creature* Shaffar = me->FindNearestCreature(NPC_SHAFFAR, 100);
            if (!Shaffar || Shaffar->isDead())
            {
                KillSelf();
                return;
            }
            if (!Shaffar->IsInCombat())
                Shaffar->AI()->AttackStart(who);
        }

        void JustSummoned(Creature* summoned) OVERRIDE
        {
            summoned->AI()->AttackStart(me->GetVictim());
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!UpdateVictim())
                return;

            if (Check_Timer <= diff)
            {
                Creature* Shaffar = me->FindNearestCreature(NPC_SHAFFAR, 100);
                if (!Shaffar || Shaffar->isDead() || !Shaffar->IsInCombat())
                {
                    KillSelf();
                    return;
                }
                Check_Timer = 1000;
            } else Check_Timer -= diff;

            if (ArcaneBolt_Timer <= diff)
            {
                DoCastVictim(SPELL_ARCANE_BOLT);
                ArcaneBolt_Timer = urand(2000, 4500);
            } else ArcaneBolt_Timer -= diff;

            if (Apprentice_Timer <= diff)
            {
                if (me->IsNonMeleeSpellCasted(false))
                    me->InterruptNonMeleeSpells(true);

                DoCast(me, SPELL_ETHEREAL_APPRENTICE, true);
                me->DespawnOrUnsummon();
                return;
            } else Apprentice_Timer -= diff;
        }
    };

};

enum Ethereal
{
    SPELL_ETHEREAL_APPRENTICE_FIREBOLT          = 32369,
    SPELL_ETHEREAL_APPRENTICE_FROSTBOLT         = 32370
};

class npc_ethereal_apprentice : public CreatureScript
{
public:
    npc_ethereal_apprentice() : CreatureScript("npc_ethereal_apprentice") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_ethereal_apprenticeAI(creature);
    }

    struct npc_ethereal_apprenticeAI : public ScriptedAI
    {
        npc_ethereal_apprenticeAI(Creature* creature) : ScriptedAI(creature) { }

        uint32 Cast_Timer;

        bool isFireboltTurn;

        void Reset() OVERRIDE
        {
            Cast_Timer = 3000;
            isFireboltTurn = true;
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!UpdateVictim())
                return;

            if (Cast_Timer <= diff)
            {
                if (isFireboltTurn)
                {
                    DoCastVictim(SPELL_ETHEREAL_APPRENTICE_FIREBOLT, true);
                    isFireboltTurn = false;
                }else{
                    DoCastVictim(SPELL_ETHEREAL_APPRENTICE_FROSTBOLT, true);
                    isFireboltTurn = true;
                }
                Cast_Timer = 3000;
            } else Cast_Timer -= diff;
        }
    };

};

enum Yor
{
    SPELL_DOUBLE_BREATH          = 38361,
    EVENT_DOUBLE_BREATH          = 1
};

class npc_yor : public CreatureScript
{
public:
    npc_yor() : CreatureScript("npc_yor") { }

    struct npc_yorAI : public ScriptedAI
    {
        npc_yorAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() OVERRIDE { }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            events.ScheduleEvent(EVENT_DOUBLE_BREATH, urand(6000,9000));
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_DOUBLE_BREATH:
                        if (me->IsWithinDist(me->GetVictim(), ATTACK_DISTANCE))
                            DoCastVictim(SPELL_DOUBLE_BREATH);
                        events.ScheduleEvent(EVENT_DOUBLE_BREATH, urand(6000,9000));
                        break;
                    default:
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }

        private:
            EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_yorAI(creature);
    }
};

void AddSC_boss_nexusprince_shaffar()
{
    new boss_nexusprince_shaffar();
    new npc_ethereal_beacon();
    new npc_ethereal_apprentice();
    new npc_yor();
}
