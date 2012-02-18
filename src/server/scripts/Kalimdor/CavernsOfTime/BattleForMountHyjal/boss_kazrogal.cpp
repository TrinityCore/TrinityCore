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

#define SPELL_CLEAVE 31436
#define SPELL_WARSTOMP 31480
#define SPELL_MARK 31447

#define SOUND_ONDEATH 11018

#define SAY_ONSLAY1 "Shaza-Kiel!"
#define SAY_ONSLAY2 "You... are nothing!"
#define SAY_ONSLAY3 "Miserable nuisance!"
#define SOUND_ONSLAY1 11017
#define SOUND_ONSLAY2 11053
#define SOUND_ONSLAY3 11054

#define SAY_MARK1 "Your death will be a painful one."
#define SAY_MARK2 "You... are marked."
#define SOUND_MARK1 11016
#define SOUND_MARK2 11052

#define SAY_ONAGGRO "Cry for mercy! Your meaningless lives will soon be forfeit."
#define SOUND_ONAGGRO 11015

class boss_kazrogal : public CreatureScript
{
public:
    boss_kazrogal() : CreatureScript("boss_kazrogal") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_kazrogalAI (creature);
    }

    struct boss_kazrogalAI : public hyjal_trashAI
    {
        boss_kazrogalAI(Creature* c) : hyjal_trashAI(c)
        {
            instance = c->GetInstanceScript();
            go = false;
            pos = 0;
        }

        uint32 CleaveTimer;
        uint32 WarStompTimer;
        uint32 MarkTimer;
        uint32 MarkTimerBase;
        bool go;
        uint32 pos;

        void Reset()
        {
            damageTaken = 0;
            CleaveTimer = 5000;
            WarStompTimer = 15000;
            MarkTimer = 45000;
            MarkTimerBase = 45000;

            if (instance && IsEvent)
                instance->SetData(DATA_KAZROGALEVENT, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/)
        {
            if (instance && IsEvent)
                instance->SetData(DATA_KAZROGALEVENT, IN_PROGRESS);
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
                Unit* target = Unit::GetUnit((*me), instance->GetData64(DATA_THRALL));
                if (target && target->isAlive())
                    me->AddThreat(target, 0.0f);
            }
        }

        void JustDied(Unit* victim)
        {
            hyjal_trashAI::JustDied(victim);
            if (instance && IsEvent)
                instance->SetData(DATA_KAZROGALEVENT, DONE);
            DoPlaySoundToSet(me, SOUND_ONDEATH);
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
            }

            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (CleaveTimer <= diff)
            {
                DoCast(me, SPELL_CLEAVE);
                CleaveTimer = 6000+rand()%15000;
            } else CleaveTimer -= diff;

            if (WarStompTimer <= diff)
            {
                DoCast(me, SPELL_WARSTOMP);
                WarStompTimer = 60000;
            } else WarStompTimer -= diff;

            if (me->HasAura(SPELL_MARK))
                me->RemoveAurasDueToSpell(SPELL_MARK);
            if (MarkTimer <= diff)
            {
                //cast dummy, useful for bos addons
                me->CastCustomSpell(me, SPELL_MARK, NULL, NULL, NULL, false, NULL, NULL, me->GetGUID());

                std::list<HostileReference*> t_list = me->getThreatManager().getThreatList();
                for (std::list<HostileReference*>::const_iterator itr = t_list.begin(); itr!= t_list.end(); ++itr)
                {
                    Unit* target = Unit::GetUnit(*me, (*itr)->getUnitGuid());
                    if (target && target->GetTypeId() == TYPEID_PLAYER && target->getPowerType() == POWER_MANA)
                    {
                        target->CastSpell(target, SPELL_MARK, true);//only cast on mana users
                    }
                }
                MarkTimerBase -= 5000;
                if (MarkTimerBase < 5500)
                    MarkTimerBase = 5500;
                MarkTimer = MarkTimerBase;
                switch (urand(0, 2))
                {
                    case 0:
                        DoPlaySoundToSet(me, SOUND_MARK1);
                        me->MonsterYell(SAY_MARK1, LANG_UNIVERSAL, 0);
                        break;
                    case 1:
                        DoPlaySoundToSet(me, SOUND_MARK2);
                        me->MonsterYell(SAY_MARK2, LANG_UNIVERSAL, 0);
                        break;
                }
            } else MarkTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_kazrogal()
{
    new boss_kazrogal();
}
