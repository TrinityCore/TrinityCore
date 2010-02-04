/*
 * Copyright (C) 2009 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

/* Script Data Start
SDName: Boss hadronox
SDAuthor: WarHead
SD%Complete: 50
SDComment: No Waves atm and the doors spells are crazy...
SDCategory:
Script Data End */

//Phase 0 => Gauntlet Event described below
//Phase 1 => Boss Encounter

/*When your group enters the main room (the one after the bridge), you will notice a group of 3 Nerubians.
When you engage them, 2 more groups like this one spawn behind the first one - it is important to pull the first group back,
so you don't aggro all 3. Hadronox will be under you, fighting Nerubians.

This is the timed gauntlet - waves of non-elite spiders
 will spawn from the 3 doors located a little above the main room, and will then head down to fight Hadronox. After clearing the
 main room, it is recommended to just stay in it, kill the occasional non-elites that will attack you instead of the boss, and wait for
 Hadronox to make his way to you. When Hadronox enters the main room, she will web the doors, and no more non-elites will spawn.*/

#include "ScriptedPch.h"
#include "azjol_nerub.h"

#define SPELL_ACID_CLOUD        53400 // Victim
#define SPELL_LEECH_POISON      53030 // Victim
#define SPELL_PIERCE_ARMOR      53418 // Victim
#define SPELL_WEB_GRAB          57731 // Victim
#define SPELL_WEB_FRONT_DOORS   53177 // Self
#define SPELL_WEB_SIDE_DOORS    53185 // Self

#define SPELL_ACID_CLOUD_H      59419
#define SPELL_LEECH_POISON_H    59417
#define SPELL_WEB_GRAB_H        59421

struct boss_hadronoxAI : public ScriptedAI
{
    boss_hadronoxAI(Creature* c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
        MaxDistance = 50.0f;
        FirstTime = true;
    }

    ScriptedInstance* pInstance;

    uint32 acidtimer,
        leechtimer,
        piercetimer,
        grabtimer,
        doorstimer,
        CheckDistanceTimer;

    bool FirstTime;

    float MaxDistance;

    void Reset()
    {
        m_creature->SetFloatValue(UNIT_FIELD_BOUNDINGRADIUS, 9.0f);
        m_creature->SetFloatValue(UNIT_FIELD_COMBATREACH, 9.0f);

        acidtimer = urand(10000,14000);
        leechtimer = urand(3000,9000);
        piercetimer = urand(1000,3000);
        grabtimer = urand(15000,19000);
        doorstimer = urand(20000,30000);

        CheckDistanceTimer = 2000;

        if (pInstance && (pInstance->GetData(DATA_HADRONOX_EVENT) != DONE && !FirstTime))
            pInstance->SetData(DATA_HADRONOX_EVENT, FAIL);

        FirstTime = false;
    }

    //when Hadronox kills any enemy (that includes a party member) she will regain 10% of her HP if the target had Leech Poison on
    void KilledUnit(Unit* Victim)
    {
        // not sure if this aura check is correct, I think it is though
        if (!Victim || !Victim->HasAura(DUNGEON_MODE(SPELL_LEECH_POISON, SPELL_LEECH_POISON_H)) || !m_creature->isAlive())
            return;

        uint32 health = (m_creature->GetMaxHealth()/100)*10;

        if ((m_creature->GetHealth()+health) >= m_creature->GetMaxHealth())
            m_creature->SetHealth(m_creature->GetMaxHealth());
        else
            m_creature->SetHealth(m_creature->GetHealth()+health);
    }

    void JustDied(Unit* Killer)
    {
        if (pInstance)
            pInstance->SetData(DATA_HADRONOX_EVENT, DONE);
    }

    void EnterCombat(Unit* who)
    {
        if (pInstance)
            pInstance->SetData(DATA_HADRONOX_EVENT, IN_PROGRESS);
        m_creature->SetInCombatWithZone();
    }

    void CheckDistance(float dist, const uint32 uiDiff)
    {
        if (!m_creature->isInCombat())
            return;

        float x=0.0f, y=0.0f, z=0.0f;
        m_creature->GetRespawnCoord(x,y,z);

        if (CheckDistanceTimer <= uiDiff)
            CheckDistanceTimer = 5000;
        else
        {
            CheckDistanceTimer -= uiDiff;
            return;
        }
        if (m_creature->IsInEvadeMode() || !m_creature->getVictim())
            return;
        if (m_creature->GetDistance(x,y,z) > dist)
            EnterEvadeMode();
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim()) return;

        // Without he comes up through the air to players on the bridge after krikthir if players crossing this bridge!
        CheckDistance(MaxDistance, diff);

        if (m_creature->HasAura(SPELL_WEB_FRONT_DOORS) || m_creature->HasAura(SPELL_WEB_SIDE_DOORS))
        {
            if (IsCombatMovement())
                SetCombatMovement(false);
        }
        else if (!IsCombatMovement())
            SetCombatMovement(true);

        if (piercetimer <= diff)
        {
            DoCast(m_creature->getVictim(), SPELL_PIERCE_ARMOR);
            piercetimer = 8000;
        } else piercetimer -= diff;

        if (acidtimer <= diff)
        {
            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                DoCast(pTarget, DUNGEON_MODE(SPELL_ACID_CLOUD, SPELL_ACID_CLOUD_H));

            acidtimer = urand(20000,30000);
        } else acidtimer -= diff;

        if (leechtimer <= diff)
        {
            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                DoCast(pTarget, DUNGEON_MODE(SPELL_LEECH_POISON, SPELL_LEECH_POISON_H));

            leechtimer = urand(11000,14000);
        } else leechtimer -= diff;

        if (grabtimer <= diff)
        {
            if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0)) // Draws all players (and attacking Mobs) to itself.
                DoCast(pTarget, DUNGEON_MODE(SPELL_WEB_GRAB, SPELL_WEB_GRAB_H));

            grabtimer = urand(15000,30000);
        } else grabtimer -= diff;

        if (doorstimer <= diff)
        {/* Debuff bleibt auf den Spielern bis zum Tod...
            DoCast(m_creature, RAND(SPELL_WEB_FRONT_DOORS, SPELL_WEB_SIDE_DOORS));
            */
            doorstimer = urand(30000,60000);
        } else doorstimer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_hadronox(Creature* pCreature)
{
    return new boss_hadronoxAI (pCreature);
}

void AddSC_boss_hadronox()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_hadronox";
    newscript->GetAI = &GetAI_boss_hadronox;
    newscript->RegisterSelf();
}
