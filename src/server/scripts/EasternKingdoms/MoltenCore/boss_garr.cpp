/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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
SDName: Boss_Garr
SD%Complete: 50
SDComment: Adds NYI
SDCategory: Molten Core
EndScriptData */

#include "ScriptPCH.h"

// Garr spells
#define SPELL_ANTIMAGICPULSE        19492
#define SPELL_MAGMASHACKLES         19496
#define SPELL_ENRAGE                19516                   //Stacking enrage (stacks to 10 times)

//Add spells
#define SPELL_ERUPTION              19497
#define SPELL_IMMOLATE              20294
class boss_garr : public CreatureScript
{
public:
    boss_garr() : CreatureScript("boss_garr") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_garrAI (pCreature);
    }

    struct boss_garrAI : public ScriptedAI
    {
        boss_garrAI(Creature *c) : ScriptedAI(c) {}

        uint32 AntiMagicPulse_Timer;
        uint32 MagmaShackles_Timer;
        uint32 CheckAdds_Timer;
        uint64 Add[8];
        bool Enraged[8];

        void Reset()
        {
            AntiMagicPulse_Timer = 25000;                       //These times are probably wrong
            MagmaShackles_Timer = 15000;
            CheckAdds_Timer = 2000;
        }

        void EnterCombat(Unit * /*who*/)
        {
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            //AntiMagicPulse_Timer
            if (AntiMagicPulse_Timer <= diff)
            {
                DoCast(me, SPELL_ANTIMAGICPULSE);
                AntiMagicPulse_Timer = 10000 + rand()%5000;
            } else AntiMagicPulse_Timer -= diff;

            //MagmaShackles_Timer
            if (MagmaShackles_Timer <= diff)
            {
                DoCast(me, SPELL_MAGMASHACKLES);
                MagmaShackles_Timer = 8000 + rand()%4000;
            } else MagmaShackles_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};
class mob_firesworn : public CreatureScript
{
public:
    mob_firesworn() : CreatureScript("mob_firesworn") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_fireswornAI (pCreature);
    }

    struct mob_fireswornAI : public ScriptedAI
    {
        mob_fireswornAI(Creature *c) : ScriptedAI(c) {}

        uint32 Immolate_Timer;

        void Reset()
        {
            Immolate_Timer = 4000;                              //These times are probably wrong
        }

        void EnterCombat(Unit * /*who*/)
        {
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            //Immolate_Timer
            if (Immolate_Timer <= diff)
            {
                 if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM,0))
                    DoCast(pTarget, SPELL_IMMOLATE);

                Immolate_Timer = urand(5000,10000);
            } else Immolate_Timer -= diff;

            //Cast Erruption and let them die
            if (me->GetHealth() <= me->GetMaxHealth() * 0.10)
            {
                DoCast(me->getVictim(), SPELL_ERUPTION);
                me->setDeathState(JUST_DIED);
                me->RemoveCorpse();
            }

            DoMeleeAttackIfReady();
        }
    };

};


void AddSC_boss_garr()
{
    new boss_garr();
    new mob_firesworn();
}
