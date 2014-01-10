/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "hyjal.h"
#include "hyjal_trash.h"

enum Spells
{
    SPELL_RAIN_OF_FIRE          = 31340,
    SPELL_DOOM                  = 31347,
    SPELL_HOWL_OF_AZGALOR       = 31344,
    SPELL_CLEAVE                = 31345,
    SPELL_BERSERK               = 26662,

    SPELL_THRASH                = 12787,
    SPELL_CRIPPLE               = 31406,
    SPELL_WARSTOMP              = 31408,
};

enum Texts
{
    SAY_ONDEATH             = 0,
    SAY_ONSLAY              = 1,
    SAY_DOOM                = 2, // Not used?
    SAY_ONAGGRO             = 3,
};

class boss_azgalor : public CreatureScript
{
public:
    boss_azgalor() : CreatureScript("boss_azgalor") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return GetInstanceAI<boss_azgalorAI>(creature);
    }

    struct boss_azgalorAI : public hyjal_trashAI
    {
        boss_azgalorAI(Creature* creature) : hyjal_trashAI(creature)
        {
            instance = creature->GetInstanceScript();
            go = false;
        }

        uint32 RainTimer;
        uint32 DoomTimer;
        uint32 HowlTimer;
        uint32 CleaveTimer;
        uint32 EnrageTimer;
        bool enraged;

        bool go;

        void Reset() OVERRIDE
        {
            damageTaken = 0;
            RainTimer = 20000;
            DoomTimer = 50000;
            HowlTimer = 30000;
            CleaveTimer = 10000;
            EnrageTimer = 600000;
            enraged = false;

            if (instance && IsEvent)
                instance->SetData(DATA_AZGALOREVENT, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            if (instance && IsEvent)
                instance->SetData(DATA_AZGALOREVENT, IN_PROGRESS);
            Talk(SAY_ONAGGRO);
        }

        void KilledUnit(Unit* /*victim*/) OVERRIDE
        {
            Talk(SAY_ONSLAY);
        }

        void WaypointReached(uint32 waypointId) OVERRIDE
        {
            if (waypointId == 7 && instance)
            {
                Unit* target = Unit::GetUnit(*me, instance->GetData64(DATA_THRALL));
                if (target && target->IsAlive())
                    me->AddThreat(target, 0.0f);
            }
        }

        void JustDied(Unit* killer) OVERRIDE
        {
            hyjal_trashAI::JustDied(killer);
            if (instance && IsEvent)
                instance->SetData(DATA_AZGALOREVENT, DONE);
            Talk(SAY_ONDEATH);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (IsEvent)
            {
                //Must update npc_escortAI
                npc_escortAI::UpdateAI(diff);
                if (!go)
                {
                    go = true;
                    AddWaypoint(0, 5492.91f,    -2404.61f,    1462.63f);
                    AddWaypoint(1, 5531.76f,    -2460.87f,    1469.55f);
                    AddWaypoint(2, 5554.58f,    -2514.66f,    1476.12f);
                    AddWaypoint(3, 5554.16f,    -2567.23f,    1479.90f);
                    AddWaypoint(4, 5540.67f,    -2625.99f,    1480.89f);
                    AddWaypoint(5, 5508.16f,    -2659.2f,    1480.15f);
                    AddWaypoint(6, 5489.62f,    -2704.05f,    1482.18f);
                    AddWaypoint(7, 5457.04f,    -2726.26f,    1485.10f);
                    Start(false, true);
                    SetDespawnAtEnd(false);
                }
            }

            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (RainTimer <= diff)
            {
                DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0, 30, true), SPELL_RAIN_OF_FIRE);
                RainTimer = 20000+rand()%15000;
            } else RainTimer -= diff;

            if (DoomTimer <= diff)
            {
                DoCast(SelectTarget(SELECT_TARGET_RANDOM, 1, 100, true), SPELL_DOOM);//never on tank
                DoomTimer = 45000+rand()%5000;
            } else DoomTimer -= diff;

            if (HowlTimer <= diff)
            {
                DoCast(me, SPELL_HOWL_OF_AZGALOR);
                HowlTimer = 30000;
            } else HowlTimer -= diff;

            if (CleaveTimer <= diff)
            {
                DoCastVictim(SPELL_CLEAVE);
                CleaveTimer = 10000+rand()%5000;
            } else CleaveTimer -= diff;

            if (EnrageTimer < diff && !enraged)
            {
                me->InterruptNonMeleeSpells(false);
                DoCast(me, SPELL_BERSERK, true);
                enraged = true;
                EnrageTimer = 600000;
            } else EnrageTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

class npc_lesser_doomguard : public CreatureScript
{
public:
    npc_lesser_doomguard() : CreatureScript("npc_lesser_doomguard") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return GetInstanceAI<npc_lesser_doomguardAI>(creature);
    }

    struct npc_lesser_doomguardAI : public hyjal_trashAI
    {
        npc_lesser_doomguardAI(Creature* creature) : hyjal_trashAI(creature)
        {
            instance = creature->GetInstanceScript();
            AzgalorGUID = instance->GetData64(DATA_AZGALOR);
        }

        uint32 CrippleTimer;
        uint32 WarstompTimer;
        uint32 CheckTimer;
        uint64 AzgalorGUID;
        InstanceScript* instance;

        void Reset() OVERRIDE
        {
            CrippleTimer = 50000;
            WarstompTimer = 10000;
            DoCast(me, SPELL_THRASH);
            CheckTimer = 5000;
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
        }

        void KilledUnit(Unit* /*victim*/) OVERRIDE
        {
        }

        void WaypointReached(uint32 /*waypointId*/) OVERRIDE
        {
        }

        void MoveInLineOfSight(Unit* who) OVERRIDE

        {
            if (me->IsWithinDist(who, 50) && !me->IsInCombat() && me->IsValidAttackTarget(who))
                AttackStart(who);
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (CheckTimer <= diff)
            {
                if (AzgalorGUID)
                {
                    Creature* boss = Unit::GetCreature((*me), AzgalorGUID);
                    if (!boss || (boss && boss->isDead()))
                    {
                        me->setDeathState(JUST_DIED);
                        me->RemoveCorpse();
                        return;
                    }
                }
                CheckTimer = 5000;
            } else CheckTimer -= diff;

            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (WarstompTimer <= diff)
            {
                DoCast(me, SPELL_WARSTOMP);
                WarstompTimer = 10000+rand()%5000;
            } else WarstompTimer -= diff;

            if (CrippleTimer <= diff)
            {
                DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true), SPELL_CRIPPLE);
                CrippleTimer = 25000+rand()%5000;
            } else CrippleTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_azgalor()
{
    new boss_azgalor();
    new npc_lesser_doomguard();
}
