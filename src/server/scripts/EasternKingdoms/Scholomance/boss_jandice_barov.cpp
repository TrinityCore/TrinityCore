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
SDName: Boss_jandicebarov
SD%Complete: 100
SDComment:
SDCategory: Scholomance
EndScriptData */

#include "ScriptPCH.h"

#define SPELL_CURSEOFBLOOD          24673
//#define SPELL_ILLUSION              17773

//Spells of Illusion of Jandice Barov
#define SPELL_CLEAVE                15584

class boss_jandice_barov : public CreatureScript
{
public:
    boss_jandice_barov() : CreatureScript("boss_jandice_barov") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_jandicebarovAI (creature);
    }

    struct boss_jandicebarovAI : public ScriptedAI
    {
        boss_jandicebarovAI(Creature* c) : ScriptedAI(c) {}

        uint32 CurseOfBlood_Timer;
        uint32 Illusion_Timer;
        //uint32 Illusioncounter;
        uint32 Invisible_Timer;
        bool Invisible;

        void Reset()
        {
            CurseOfBlood_Timer = 15000;
            Illusion_Timer = 30000;
            Invisible_Timer = 3000;                             //Too much too low?
            Invisible = false;
        }

        void EnterCombat(Unit* /*who*/)
        {
        }

        void SummonIllusions(Unit* victim)
        {
            if (Creature* Illusion = DoSpawnCreature(11439, float(irand(-9, 9)), float(irand(-9, 9)), 0, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 60000))
                Illusion->AI()->AttackStart(victim);
        }

        void UpdateAI(const uint32 diff)
        {
            if (Invisible && Invisible_Timer <= diff)
            {
                //Become visible again
                me->setFaction(14);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->SetDisplayId(11073);     //Jandice Model
                Invisible = false;
            } else if (Invisible)
            {
                Invisible_Timer -= diff;
                //Do nothing while invisible
                return;
            }

            //Return since we have no target
            if (!UpdateVictim())
                return;

            //CurseOfBlood_Timer
            if (CurseOfBlood_Timer <= diff)
            {
                //Cast
                DoCast(me->getVictim(), SPELL_CURSEOFBLOOD);

                //45 seconds
                CurseOfBlood_Timer = 30000;
            } else CurseOfBlood_Timer -= diff;

            //Illusion_Timer
            if (!Invisible && Illusion_Timer <= diff)
            {

                //Interrupt any spell casting
                me->InterruptNonMeleeSpells(false);
                me->setFaction(35);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->SetDisplayId(11686);  // Invisible Model
                DoModifyThreatPercent(me->getVictim(), -99);

                //Summon 10 Illusions attacking random gamers
                Unit* target = NULL;
                for (uint8 i = 0; i < 10; ++i)
                {
                    target = SelectTarget(SELECT_TARGET_RANDOM, 0);
                    if (target)
                        SummonIllusions(target);
                }
                Invisible = true;
                Invisible_Timer = 3000;

                //25 seconds until we should cast this agian
                Illusion_Timer = 25000;
            } else Illusion_Timer -= diff;

            //            //Illusion_Timer
            //            if (Illusion_Timer <= diff)
            //            {
            //                  //Cast
            //                DoCast(me->getVictim(), SPELL_ILLUSION);
            //
            //                  //3 Illusion will be summoned
            //                  if (Illusioncounter < 3)
            //                  {
            //                    Illusion_Timer = 500;
            //                    ++Illusioncounter;
            //                  }
            //                  else {
            //                      //15 seconds until we should cast this again
            //                      Illusion_Timer = 15000;
            //                      Illusioncounter = 0;
            //                  }
            //
            //            } else Illusion_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

// Illusion of Jandice Barov Script

class mob_illusionofjandicebarov : public CreatureScript
{
public:
    mob_illusionofjandicebarov() : CreatureScript("mob_illusionofjandicebarov") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_illusionofjandicebarovAI (creature);
    }

    struct mob_illusionofjandicebarovAI : public ScriptedAI
    {
        mob_illusionofjandicebarovAI(Creature* c) : ScriptedAI(c) {}

        uint32 Cleave_Timer;

        void Reset()
        {
            Cleave_Timer = urand(2000, 8000);
            me->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_MAGIC, true);
        }

        void EnterCombat(Unit* /*who*/)
        {
        }

        void UpdateAI(const uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            //Cleave_Timer
            if (Cleave_Timer <= diff)
            {
                //Cast
                DoCast(me->getVictim(), SPELL_CLEAVE);

                //5-8 seconds
                Cleave_Timer = urand(5000, 8000);
            } else Cleave_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_jandicebarov()
{
    new boss_jandice_barov();
    new mob_illusionofjandicebarov();
}
