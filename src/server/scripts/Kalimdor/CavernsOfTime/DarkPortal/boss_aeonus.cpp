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
SDName: Boss_Aeonus
SD%Complete: 80
SDComment: Some spells not implemented
SDCategory: Caverns of Time, The Dark Portal
EndScriptData */

#include "ScriptPCH.h"
#include "dark_portal.h"

enum eEnums
{
    SAY_ENTER           = -1269012,
    SAY_AGGRO           = -1269013,
    SAY_BANISH          = -1269014,
    SAY_SLAY1           = -1269015,
    SAY_SLAY2           = -1269016,
    SAY_DEATH           = -1269017,
    EMOTE_FRENZY        = -1269018,

    SPELL_CLEAVE        = 40504,
    SPELL_TIME_STOP     = 31422,
    SPELL_ENRAGE        = 37605,
    SPELL_SAND_BREATH   = 31473,
    H_SPELL_SAND_BREATH = 39049
};

class boss_aeonus : public CreatureScript
{
public:
    boss_aeonus() : CreatureScript("boss_aeonus") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_aeonusAI (creature);
    }

    struct boss_aeonusAI : public ScriptedAI
    {
        boss_aeonusAI(Creature* c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
        }

        InstanceScript* pInstance;

        uint32 SandBreath_Timer;
        uint32 TimeStop_Timer;
        uint32 Frenzy_Timer;

        void Reset()
        {
            SandBreath_Timer = 15000+rand()%15000;
            TimeStop_Timer = 10000+rand()%5000;
            Frenzy_Timer = 30000+rand()%15000;
        }

        void EnterCombat(Unit* /*who*/)
        {
            DoScriptText(SAY_AGGRO, me);
        }

        void MoveInLineOfSight(Unit* who)
        {
            //Despawn Time Keeper
            if (who->GetTypeId() == TYPEID_UNIT && who->GetEntry() == C_TIME_KEEPER)
            {
                if (me->IsWithinDistInMap(who, 20.0f))
                {
                    DoScriptText(SAY_BANISH, me);
                    me->DealDamage(who, who->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                }
            }

            ScriptedAI::MoveInLineOfSight(who);
        }

        void JustDied(Unit* /*victim*/)
        {
            DoScriptText(SAY_DEATH, me);

             if (pInstance)
             {
                 pInstance->SetData(TYPE_RIFT, DONE);
                 pInstance->SetData(TYPE_MEDIVH, DONE);//FIXME: later should be removed
             }
        }

        void KilledUnit(Unit* /*victim*/)
        {
            DoScriptText(RAND(SAY_SLAY1, SAY_SLAY2), me);
        }

        void UpdateAI(const uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            //Sand Breath
            if (SandBreath_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_SAND_BREATH);
                SandBreath_Timer = 15000+rand()%10000;
            } else SandBreath_Timer -= diff;

            //Time Stop
            if (TimeStop_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_TIME_STOP);
                TimeStop_Timer = 20000+rand()%15000;
            } else TimeStop_Timer -= diff;

            //Frenzy
            if (Frenzy_Timer <= diff)
            {
                DoScriptText(EMOTE_FRENZY, me);
                DoCast(me, SPELL_ENRAGE);
                Frenzy_Timer = 20000+rand()%15000;
            } else Frenzy_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_aeonus()
{
    new boss_aeonus();
}
