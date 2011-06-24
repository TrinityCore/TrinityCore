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
#include "gundrak.h"

enum eSpells
{
    SPELL_DETERMINED_STAB                         = 55104,
    SPELL_GROUND_TREMOR                           = 55142,
    SPELL_NUMBING_SHOUT                           = 55106,
    SPELL_DETERMINED_GORE                         = 55102,
    H_SPELL_DETERMINED_GORE                       = 59444,
    SPELL_QUAKE                                   = 55101,
    SPELL_NUMBING_ROAR                            = 55100,
    SPELL_MOJO_FRENZY                             = 55163,
    SPELL_TRANSFORMATION                          = 55098, //Periodic, The caster transforms into a powerful mammoth, increasing Physical damage done by 25% and granting immunity to Stun effects.
};

enum eSays
{
    SAY_AGGRO                                     = -1604010,
    //SAY_SLAY_1                                  = -1604011, // not in db
    SAY_SLAY_2                                    = -1604012,
    SAY_SLAY_3                                    = -1604013,
    SAY_DEATH                                     = -1604014,
    SAY_TRANSFORM                                 = -1604015,
    SAY_QUAKE                                     = -1604016,
    EMOTE_TRANSFORM                               = -1604017
};

#define DATA_LESS_RABI                            1

class boss_moorabi : public CreatureScript
{
public:
    boss_moorabi() : CreatureScript("boss_moorabi") { }

    CreatureAI* GetAI(Creature *pCreature) const
    {
        return new boss_moorabiAI(pCreature);
    }

    struct boss_moorabiAI : public ScriptedAI
    {
        boss_moorabiAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            pInstance = pCreature->GetInstanceScript();
        }

        InstanceScript* pInstance;

        bool bPhase;

        uint32 uiNumblingShoutTimer;
        uint32 uiGroundTremorTimer;
        uint32 uiDeterminedStabTimer;
        uint32 uiTransformationTImer;

        void Reset()
        {
            uiGroundTremorTimer = 18*IN_MILLISECONDS;
            uiNumblingShoutTimer =  10*IN_MILLISECONDS;
            uiDeterminedStabTimer = 20*IN_MILLISECONDS;
            uiTransformationTImer = 12*IN_MILLISECONDS;
            bPhase = false;

            if (pInstance)
                pInstance->SetData(DATA_MOORABI_EVENT, NOT_STARTED);
        }

        void EnterCombat(Unit* /*pWho*/)
        {
            DoScriptText(SAY_AGGRO, me);
            DoCast(me, SPELL_MOJO_FRENZY, true);

            if (pInstance)
                pInstance->SetData(DATA_MOORABI_EVENT, IN_PROGRESS);
        }

        void UpdateAI(const uint32 uiDiff)
        {
            //Return since we have no target
             if (!UpdateVictim())
                 return;

            if (!bPhase && me->HasAura(SPELL_TRANSFORMATION))
            {
                bPhase = true;
                me->RemoveAura(SPELL_MOJO_FRENZY);
            }

            if (uiGroundTremorTimer <= uiDiff)
            {
                DoScriptText(SAY_QUAKE, me);
                if (bPhase)
                    DoCast(me->getVictim(), SPELL_QUAKE, true);
                else
                    DoCast(me->getVictim(), SPELL_GROUND_TREMOR, true);
                uiGroundTremorTimer = 10*IN_MILLISECONDS;
            } else uiGroundTremorTimer -= uiDiff;

            if (uiNumblingShoutTimer <= uiDiff)
            {
                if (bPhase)
                    DoCast(me->getVictim(), SPELL_NUMBING_ROAR, true);
                else
                    DoCast(me->getVictim(), SPELL_NUMBING_SHOUT, true);
                uiNumblingShoutTimer = 10*IN_MILLISECONDS;
            } else uiNumblingShoutTimer -=uiDiff;

            if (uiDeterminedStabTimer <= uiDiff)
            {
                if (bPhase)
                    DoCast(me->getVictim(), SPELL_DETERMINED_GORE);
                else
                    DoCast(me->getVictim(), SPELL_DETERMINED_STAB, true);
                uiDeterminedStabTimer = 8*IN_MILLISECONDS;
            } else uiDeterminedStabTimer -=uiDiff;

            if (!bPhase && uiTransformationTImer <= uiDiff)
            {
                DoScriptText(EMOTE_TRANSFORM, me);
                DoScriptText(SAY_TRANSFORM, me);
                DoCast(me, SPELL_TRANSFORMATION, false);
                uiTransformationTImer = 10*IN_MILLISECONDS;
            } else uiTransformationTImer -= uiDiff;

            DoMeleeAttackIfReady();
         }

        uint32 GetData(uint32 type)
        {
            if (type == DATA_LESS_RABI)
                return bPhase ? 0 : 1;

            return 0;
        }

         void JustDied(Unit* /*pKiller*/)
         {
            DoScriptText(SAY_DEATH, me);

            if (pInstance)
                pInstance->SetData(DATA_MOORABI_EVENT, DONE);
        }

        void KilledUnit(Unit* pVictim)
        {
            if (pVictim == me)
                return;

            DoScriptText(RAND(SAY_SLAY_2, SAY_SLAY_3), me);
        }
    };

};

class achievement_less_rabi : public AchievementCriteriaScript
{
    public:
        achievement_less_rabi() : AchievementCriteriaScript("achievement_less_rabi")
        {
        }

        bool OnCheck(Player* /*player*/, Unit* target)
        {
            if (Creature* Moorabi = target->ToCreature())
                if (Moorabi->AI()->GetData(DATA_LESS_RABI))
                    return true;

            return false;
        }
};

void AddSC_boss_moorabi()
{
    new boss_moorabi();
    new achievement_less_rabi();
}
