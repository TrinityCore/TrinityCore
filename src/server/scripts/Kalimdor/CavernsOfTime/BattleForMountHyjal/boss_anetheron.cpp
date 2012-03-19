/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "hyjal.h"
#include "hyjal_trash.h"

#define SPELL_CARRION_SWARM 31306
#define SPELL_SLEEP 31298
#define SPELL_VAMPIRIC_AURA 38196
#define SPELL_INFERNO 31299

#define SAY_ONDEATH "The clock... is still... ticking."
#define SOUND_ONDEATH 10982

#define SAY_ONSLAY1 "Your hopes are lost!"
#define SAY_ONSLAY2 "Scream for me!"
#define SAY_ONSLAY3 "Pity, no time for a slow death!"
#define SOUND_ONSLAY1 10981
#define SOUND_ONSLAY2 11038
#define SOUND_ONSLAY3 11039

#define SAY_SWARM1 "The swarm is eager to feed!"
#define SAY_SWARM2 "Pestilence upon you!"
#define SOUND_SWARM1 10979
#define SOUND_SWARM2 11037

#define SAY_SLEEP1 "You look tired..."
#define SAY_SLEEP2 "Sweet dreams..."
#define SOUND_SLEEP1 10978
#define SOUND_SLEEP2 11545

#define SAY_INFERNO1 "Let fire rain from above!"
#define SAY_INFERNO2 "Earth and sky shall burn!"
#define SOUND_INFERNO1 10980
#define SOUND_INFERNO2 11036

#define SAY_ONAGGRO "You are defenders of a doomed world! Flee here, and perhaps you will prolong your pathetic lives!"
#define SOUND_ONAGGRO 10977

class boss_anetheron : public CreatureScript
{
public:
    boss_anetheron() : CreatureScript("boss_anetheron") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_anetheronAI (creature);
    }

    struct boss_anetheronAI : public hyjal_trashAI
    {
        boss_anetheronAI(Creature* c) : hyjal_trashAI(c)
        {
            instance = c->GetInstanceScript();
            go = false;
            pos = 0;
        }

        uint32 SwarmTimer;
        uint32 SleepTimer;
        uint32 AuraTimer;
        uint32 InfernoTimer;
        bool go;
        uint32 pos;

        void Reset()
        {
            damageTaken = 0;
            SwarmTimer = 45000;
            SleepTimer = 60000;
            AuraTimer = 5000;
            InfernoTimer = 45000;

            if (instance && IsEvent)
                instance->SetData(DATA_ANETHERONEVENT, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/)
        {
            if (instance && IsEvent)
                instance->SetData(DATA_ANETHERONEVENT, IN_PROGRESS);
            DoPlaySoundToSet(me, SOUND_ONAGGRO);
            me->MonsterYell(SAY_ONAGGRO, LANG_UNIVERSAL, 0);
        }

        void KilledUnit(Unit* /*victim*/)
        {
            switch (urand(0, 2))
            {
                case 0:
                    DoPlaySoundToSet(me, SOUND_ONSLAY1);
                    me->MonsterYell(SAY_ONSLAY1, LANG_UNIVERSAL, 0);
                    break;
                case 1:
                    DoPlaySoundToSet(me, SOUND_ONSLAY2);
                    me->MonsterYell(SAY_ONSLAY2, LANG_UNIVERSAL, 0);
                    break;
                case 2:
                    DoPlaySoundToSet(me, SOUND_ONSLAY3);
                    me->MonsterYell(SAY_ONSLAY3, LANG_UNIVERSAL, 0);
                    break;
            }
        }

        void WaypointReached(uint32 i)
        {
            pos = i;
            if (i == 7 && instance)
            {
                Unit* target = Unit::GetUnit((*me), instance->GetData64(DATA_JAINAPROUDMOORE));
                if (target && target->isAlive())
                    me->AddThreat(target, 0.0f);
            }
        }

        void JustDied(Unit* victim)
        {
            hyjal_trashAI::JustDied(victim);
            if (instance && IsEvent)
                instance->SetData(DATA_ANETHERONEVENT, DONE);
            DoPlaySoundToSet(me, SOUND_ONDEATH);
            me->MonsterYell(SAY_ONDEATH, LANG_UNIVERSAL, 0);
        }

        void UpdateAI(const uint32 diff)
        {
            if (IsEvent)
            {
                //Must update npc_escortAI
                npc_escortAI::UpdateAI(diff);
                if (!go)
                {
                    go = true;
                    if (instance)
                    {
                        AddWaypoint(0, 4896.08f,    -1576.35f,    1333.65f);
                        AddWaypoint(1, 4898.68f,    -1615.02f,    1329.48f);
                        AddWaypoint(2, 4907.12f,    -1667.08f,    1321.00f);
                        AddWaypoint(3, 4963.18f,    -1699.35f,    1340.51f);
                        AddWaypoint(4, 4989.16f,    -1716.67f,    1335.74f);
                        AddWaypoint(5, 5026.27f,    -1736.89f,    1323.02f);
                        AddWaypoint(6, 5037.77f,    -1770.56f,    1324.36f);
                        AddWaypoint(7, 5067.23f,    -1789.95f,    1321.17f);
                        Start(false, true);
                        SetDespawnAtEnd(false);
                    }
                }
            }

            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (SwarmTimer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    DoCast(target, SPELL_CARRION_SWARM);

                SwarmTimer = urand(45000, 60000);
                switch (urand(0, 1))
                {
                    case 0:
                        DoPlaySoundToSet(me, SOUND_SWARM1);
                        me->MonsterYell(SAY_SWARM1, LANG_UNIVERSAL, 0);
                        break;
                    case 1:
                        DoPlaySoundToSet(me, SOUND_SWARM2);
                        me->MonsterYell(SAY_SWARM2, LANG_UNIVERSAL, 0);
                        break;
                }
            } else SwarmTimer -= diff;

            if (SleepTimer <= diff)
            {
                for (uint8 i = 0; i < 3; ++i)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                        target->CastSpell(target, SPELL_SLEEP, true);
                }
                SleepTimer = 60000;
                switch (urand(0, 1))
                {
                    case 0:
                        DoPlaySoundToSet(me, SOUND_SLEEP1);
                        me->MonsterYell(SAY_SLEEP1, LANG_UNIVERSAL, 0);
                        break;
                    case 1:
                        DoPlaySoundToSet(me, SOUND_SLEEP2);
                        me->MonsterYell(SAY_SLEEP2, LANG_UNIVERSAL, 0);
                        break;
                }
            } else SleepTimer -= diff;
            if (AuraTimer <= diff)
            {
                DoCast(me, SPELL_VAMPIRIC_AURA, true);
                AuraTimer = urand(10000, 20000);
            } else AuraTimer -= diff;
            if (InfernoTimer <= diff)
            {
                DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true), SPELL_INFERNO);
                InfernoTimer = 45000;
                switch (urand(0, 1))
                {
                    case 0:
                        DoPlaySoundToSet(me, SOUND_INFERNO1);
                        me->MonsterYell(SAY_INFERNO1, LANG_UNIVERSAL, 0);
                        break;
                    case 1:
                        DoPlaySoundToSet(me, SOUND_INFERNO2);
                        me->MonsterYell(SAY_INFERNO2, LANG_UNIVERSAL, 0);
                        break;
                }
            } else InfernoTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

#define SPELL_IMMOLATION     31303
#define SPELL_INFERNO_EFFECT 31302

class mob_towering_infernal : public CreatureScript
{
public:
    mob_towering_infernal() : CreatureScript("mob_towering_infernal") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_towering_infernalAI (creature);
    }

    struct mob_towering_infernalAI : public ScriptedAI
    {
        mob_towering_infernalAI(Creature* c) : ScriptedAI(c)
        {
            instance = c->GetInstanceScript();
            if (instance)
                AnetheronGUID = instance->GetData64(DATA_ANETHERON);
        }

        uint32 ImmolationTimer;
        uint32 CheckTimer;
        uint64 AnetheronGUID;
        InstanceScript* instance;

        void Reset()
        {
            DoCast(me, SPELL_INFERNO_EFFECT);
            ImmolationTimer = 5000;
            CheckTimer = 5000;
        }

        void EnterCombat(Unit* /*who*/)
        {
        }

        void KilledUnit(Unit* /*victim*/)
        {
        }

        void JustDied(Unit* /*victim*/)
        {
        }

        void MoveInLineOfSight(Unit* who)
        {
            if (me->IsWithinDist(who, 50) && !me->isInCombat() && me->IsValidAttackTarget(who))
                AttackStart(who);
        }

        void UpdateAI(const uint32 diff)
        {
            if (CheckTimer <= diff)
            {
                if (AnetheronGUID)
                {
                    Creature* boss = Unit::GetCreature((*me), AnetheronGUID);
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

            if (ImmolationTimer <= diff)
            {
                DoCast(me, SPELL_IMMOLATION);
                ImmolationTimer = 5000;
            } else ImmolationTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_anetheron()
{
    new boss_anetheron();
    new mob_towering_infernal();
}
