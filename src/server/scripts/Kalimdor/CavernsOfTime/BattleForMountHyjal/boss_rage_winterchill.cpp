/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#define SPELL_FROST_ARMOR 31256
#define SPELL_DEATH_AND_DECAY 31258

#define SPELL_FROST_NOVA 31250
#define SPELL_ICEBOLT 31249

#define SAY_ONDEATH "You have won this battle, but not... the... war"
#define SOUND_ONDEATH 11026

#define SAY_ONSLAY1 "All life must perish!"
#define SAY_ONSLAY2 "Victory to the Legion!"
#define SOUND_ONSLAY1 11025
#define SOUND_ONSLAY2 11057

#define SAY_DECAY1 "Crumble and rot!"
#define SAY_DECAY2 "Ashes to ashes, dust to dust"
#define SOUND_DECAY1 11023
#define SOUND_DECAY2 11055

#define SAY_NOVA1 "Succumb to the icy chill... of death!"
#define SAY_NOVA2 "It will be much colder in your grave"
#define SOUND_NOVA1 11024
#define SOUND_NOVA2 11058

#define SAY_ONAGGRO "The Legion's final conquest has begun! Once again the subjugation of this world is within our grasp. Let none survive!"
#define SOUND_ONAGGRO 11022

class boss_rage_winterchill : public CreatureScript
{
public:
    boss_rage_winterchill() : CreatureScript("boss_rage_winterchill") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_rage_winterchillAI (pCreature);
    }

    struct boss_rage_winterchillAI : public hyjal_trashAI
    {
        boss_rage_winterchillAI(Creature* c) : hyjal_trashAI(c)
        {
            pInstance = c->GetInstanceScript();
            pGo = false;
            pos = 0;
        }

        uint32 FrostArmorTimer;
        uint32 DecayTimer;
        uint32 NovaTimer;
        uint32 IceboltTimer;
        bool pGo;
        uint32 pos;

        void Reset()
        {
            damageTaken = 0;
            FrostArmorTimer = 37000;
            DecayTimer = 45000;
            NovaTimer = 15000;
            IceboltTimer = 10000;

            if (pInstance && IsEvent)
                pInstance->SetData(DATA_RAGEWINTERCHILLEVENT, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/)
        {
            if (pInstance && IsEvent)
                pInstance->SetData(DATA_RAGEWINTERCHILLEVENT, IN_PROGRESS);
            DoPlaySoundToSet(me, SOUND_ONAGGRO);
            me->MonsterYell(SAY_ONAGGRO, LANG_UNIVERSAL, 0);
        }

        void KilledUnit(Unit* /*victim*/)
        {
            switch (urand(0, 1))
            {
                case 0:
                    DoPlaySoundToSet(me, SOUND_ONSLAY1);
                    me->MonsterYell(SAY_ONSLAY1, LANG_UNIVERSAL, 0);
                    break;
                case 1:
                    DoPlaySoundToSet(me, SOUND_ONSLAY2);
                    me->MonsterYell(SAY_ONSLAY2, LANG_UNIVERSAL, 0);
                    break;
            }
        }

        void WaypointReached(uint32 i)
        {
            pos = i;
            if (i == 7 && pInstance)
            {
                Unit* pTarget = Unit::GetUnit((*me), pInstance->GetData64(DATA_JAINAPROUDMOORE));
                if (pTarget && pTarget->isAlive())
                    me->AddThreat(pTarget, 0.0f);
            }
        }

        void JustDied(Unit* victim)
        {
            hyjal_trashAI::JustDied(victim);
            if (pInstance && IsEvent)
                pInstance->SetData(DATA_RAGEWINTERCHILLEVENT, DONE);
            DoPlaySoundToSet(me, SOUND_ONDEATH);
            me->MonsterYell(SAY_ONDEATH, LANG_UNIVERSAL, 0);
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

            if (FrostArmorTimer <= diff)
            {
                DoCast(me, SPELL_FROST_ARMOR);
                FrostArmorTimer = 40000+rand()%20000;
            } else FrostArmorTimer -= diff;
            if (DecayTimer <= diff)
            {
                DoCast(me->getVictim(), SPELL_DEATH_AND_DECAY);
                DecayTimer = 60000+rand()%20000;
                switch (urand(0, 1))
                {
                    case 0:
                        DoPlaySoundToSet(me, SOUND_DECAY1);
                        me->MonsterYell(SAY_DECAY1, LANG_UNIVERSAL, 0);
                        break;
                    case 1:
                        DoPlaySoundToSet(me, SOUND_DECAY2);
                        me->MonsterYell(SAY_DECAY2, LANG_UNIVERSAL, 0);
                        break;
                }
            } else DecayTimer -= diff;
            if (NovaTimer <= diff)
            {
                DoCast(me->getVictim(), SPELL_FROST_NOVA);
                NovaTimer = 30000+rand()%15000;
                switch (urand(0, 1))
                {
                    case 0:
                        DoPlaySoundToSet(me, SOUND_NOVA1);
                        me->MonsterYell(SAY_NOVA1, LANG_UNIVERSAL, 0);
                        break;
                    case 1:
                        DoPlaySoundToSet(me, SOUND_NOVA2);
                        me->MonsterYell(SAY_NOVA2, LANG_UNIVERSAL, 0);
                        break;
                }
            } else NovaTimer -= diff;
            if (IceboltTimer <= diff)
            {
                DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0, 40, true), SPELL_ICEBOLT);
                IceboltTimer = 11000+rand()%20000;
            } else IceboltTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_rage_winterchill()
{
    new boss_rage_winterchill();
}
