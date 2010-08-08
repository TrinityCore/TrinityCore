/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_kazrogalAI (pCreature);
    }

    struct boss_kazrogalAI : public hyjal_trashAI
    {
        boss_kazrogalAI(Creature *c) : hyjal_trashAI(c)
        {
            pInstance = c->GetInstanceScript();
            pGo = false;
            pos = 0;
            SpellEntry *TempSpell = GET_SPELL(SPELL_MARK);
            if (TempSpell && TempSpell->EffectImplicitTargetA[0] != 1)
            {
                TempSpell->EffectImplicitTargetA[0] = 1;
                TempSpell->EffectImplicitTargetB[0] = 0;
            }
        }

        uint32 CleaveTimer;
        uint32 WarStompTimer;
        uint32 MarkTimer;
        uint32 MarkTimerBase;
        bool pGo;
        uint32 pos;

        void Reset()
        {
            damageTaken = 0;
            CleaveTimer = 5000;
            WarStompTimer = 15000;
            MarkTimer = 45000;
            MarkTimerBase = 45000;

            if (pInstance && IsEvent)
                pInstance->SetData(DATA_KAZROGALEVENT, NOT_STARTED);
        }

        void EnterCombat(Unit * /*who*/)
        {
            if (pInstance && IsEvent)
                pInstance->SetData(DATA_KAZROGALEVENT, IN_PROGRESS);
            DoPlaySoundToSet(me, SOUND_ONAGGRO);
            me->MonsterYell(SAY_ONAGGRO, LANG_UNIVERSAL, NULL);
        }

        void KilledUnit(Unit * /*victim*/)
        {
            switch (urand(0,2))
            {
                case 0:
                    DoPlaySoundToSet(me, SOUND_ONSLAY1);
                    me->MonsterYell(SAY_ONSLAY1, LANG_UNIVERSAL, NULL);
                    break;
                case 1:
                    DoPlaySoundToSet(me, SOUND_ONSLAY2);
                    me->MonsterYell(SAY_ONSLAY2, LANG_UNIVERSAL, NULL);
                    break;
                case 2:
                    DoPlaySoundToSet(me, SOUND_ONSLAY3);
                    me->MonsterYell(SAY_ONSLAY3, LANG_UNIVERSAL, NULL);
                    break;
            }
        }

        void WaypointReached(uint32 i)
        {
            pos = i;
            if (i == 7 && pInstance)
            {
                Unit *pTarget = Unit::GetUnit((*me), pInstance->GetData64(DATA_THRALL));
                if (pTarget && pTarget->isAlive())
                    me->AddThreat(pTarget,0.0);
            }
        }

        void JustDied(Unit *victim)
        {
            hyjal_trashAI::JustDied(victim);
            if (pInstance && IsEvent)
                pInstance->SetData(DATA_KAZROGALEVENT, DONE);
            DoPlaySoundToSet(me, SOUND_ONDEATH);
        }

        void UpdateAI(const uint32 diff)
        {
            if (IsEvent)
            {
                //Must update npc_escortAI
                npc_escortAI::UpdateAI(diff);
                if (!pGo)
                {
                    pGo = true;
                    if (pInstance)
                    {
                        AddWaypoint(0, 5492.91,    -2404.61,    1462.63);
                        AddWaypoint(1, 5531.76,    -2460.87,    1469.55);
                        AddWaypoint(2, 5554.58,    -2514.66,    1476.12);
                        AddWaypoint(3, 5554.16,    -2567.23,    1479.90);
                        AddWaypoint(4, 5540.67,    -2625.99,    1480.89);
                        AddWaypoint(5, 5508.16,    -2659.2,    1480.15);
                        AddWaypoint(6, 5489.62,    -2704.05,    1482.18);
                        AddWaypoint(7, 5457.04,    -2726.26,    1485.10);
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

                std::list<HostileReference *> t_list = me->getThreatManager().getThreatList();
                for (std::list<HostileReference *>::const_iterator itr = t_list.begin(); itr!= t_list.end(); ++itr)
                {
                    Unit *pTarget = Unit::GetUnit(*me, (*itr)->getUnitGuid());
                    if (pTarget && pTarget->GetTypeId() == TYPEID_PLAYER && pTarget->getPowerType() == POWER_MANA)
                    {
                        pTarget->CastSpell(pTarget, SPELL_MARK,true);//only cast on mana users
                    }
                }
                MarkTimerBase -= 5000;
                if (MarkTimerBase < 5500)
                    MarkTimerBase = 5500;
                MarkTimer = MarkTimerBase;
                switch (urand(0,2))
                {
                    case 0:
                        DoPlaySoundToSet(me, SOUND_MARK1);
                        me->MonsterYell(SAY_MARK1, LANG_UNIVERSAL, NULL);
                        break;
                    case 1:
                        DoPlaySoundToSet(me, SOUND_MARK2);
                        me->MonsterYell(SAY_MARK2, LANG_UNIVERSAL, NULL);
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
