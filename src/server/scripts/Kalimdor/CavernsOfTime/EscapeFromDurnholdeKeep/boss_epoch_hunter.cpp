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
SDName: Boss_Epoch_Hunter
SD%Complete: 60
SDComment: Missing spawns pre-event, missing speech to be coordinated with rest of escort event.
SDCategory: Caverns of Time, Old Hillsbrad Foothills
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "old_hillsbrad.h"

/*###################
# boss_epoch_hunter #
####################*/

enum EpochHunter
{
    SAY_ENTER                   = 0,
    SAY_AGGRO                   = 1,
    SAY_SLAY                    = 2,
    SAY_BREATH                  = 3,
    SAY_DEATH                   = 4,

    SPELL_SAND_BREATH           = 31914,
    SPELL_IMPENDING_DEATH       = 31916,
    SPELL_MAGIC_DISRUPTION_AURA = 33834,
    SPELL_WING_BUFFET           = 31475
};

class boss_epoch_hunter : public CreatureScript
{
public:
    boss_epoch_hunter() : CreatureScript("boss_epoch_hunter") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<boss_epoch_hunterAI>(creature);
    }

    struct boss_epoch_hunterAI : public ScriptedAI
    {
        boss_epoch_hunterAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        uint32 SandBreath_Timer;
        uint32 ImpendingDeath_Timer;
        uint32 WingBuffet_Timer;
        uint32 Mda_Timer;

        void Reset() override
        {
            SandBreath_Timer = urand(8000, 16000);
            ImpendingDeath_Timer = urand(25000, 30000);
            WingBuffet_Timer = 35000;
            Mda_Timer = 40000;
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO);
        }

        void KilledUnit(Unit* /*victim*/) override
        {
            Talk(SAY_SLAY);
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);

            if (instance->GetData(TYPE_THRALL_EVENT) == IN_PROGRESS)
                instance->SetData(TYPE_THRALL_PART4, DONE);
        }

        void UpdateAI(uint32 diff) override
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            //Sand Breath
            if (SandBreath_Timer <= diff)
            {
                if (me->IsNonMeleeSpellCast(false))
                    me->InterruptNonMeleeSpells(false);

                DoCastVictim(SPELL_SAND_BREATH);

                Talk(SAY_BREATH);

                SandBreath_Timer = urand(10000, 20000);
            } else SandBreath_Timer -= diff;

            if (ImpendingDeath_Timer <= diff)
            {
                DoCastVictim(SPELL_IMPENDING_DEATH);
                ImpendingDeath_Timer = 25000+rand()%5000;
            } else ImpendingDeath_Timer -= diff;

            if (WingBuffet_Timer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_WING_BUFFET);
                WingBuffet_Timer = 25000+rand()%10000;
            } else WingBuffet_Timer -= diff;

            if (Mda_Timer <= diff)
            {
                DoCast(me, SPELL_MAGIC_DISRUPTION_AURA);
                Mda_Timer = 15000;
            } else Mda_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_epoch_hunter()
{
    new boss_epoch_hunter();
}
