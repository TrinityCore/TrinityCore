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
SDName: Boss_Moam
SD%Complete: 90
SDComment: TODO: Adjust timer, correct Stone phase buff
SDCategory: Ruins of Ahn'Qiraj
EndScriptData */

#include "ScriptPCH.h"
#include "ruins_of_ahnqiraj.h"

enum Emotes
{
    EMOTE_AGGRO             = -1509000,
    EMOTE_MANA_FULL         = -1509001
};

enum Spells
{
    SPELL_TRAMPLE           = 15550,
    SPELL_DRAINMANA         = 27256,    //Doesn't exist ?
    SPELL_ARCANEERUPTION    = 25672,
    SPELL_SUMMONMANA        = 25681,    //Summon Mana fiend. It only summons one so exec it three times
    SPELL_GRDRSLEEP         = 24360     //Greater Dreamless Sleep
};

enum Creatures
{
    CREATURE_MANA_FIEND     = 15527
};

enum CombatPhase
{
    NORMAL,
    STONE
};
class boss_moam : public CreatureScript
{
public:
    boss_moam() : CreatureScript("boss_moam") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_moamAI (pCreature);
    }

    struct boss_moamAI : public ScriptedAI
    {
        boss_moamAI(Creature *c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
        }

        uint32 uiTrampleTimer;
        uint32 uiDrainManaTimer;
        uint32 uiPhaseTimer;
        CombatPhase Phase;

        InstanceScript *pInstance;

        void Reset()
        {
            uiTrampleTimer = urand(3000,7000);
            uiDrainManaTimer = urand(3000,7000);
            uiPhaseTimer = 90000;
            Phase = NORMAL;
            me->SetPower(POWER_MANA,0);

            if (pInstance)
                pInstance->SetData(DATA_MOAM_EVENT, NOT_STARTED);
        }

        void EnterCombat(Unit * /*who*/)
        {
            DoScriptText(EMOTE_AGGRO, me);

            if (pInstance)
                pInstance->SetData(DATA_MOAM_EVENT, IN_PROGRESS);
        }

        void JustDied(Unit * /*killer*/)
        {
            if (pInstance)
                pInstance->SetData(DATA_MOAM_EVENT, DONE);
        }

        void DrainMana()
        {
            for (uint8 i=0;i<6;++i)
            {
                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                {
                    pTarget->ModifyPower(POWER_MANA, -500);
                    me->ModifyPower(POWER_MANA, 1000);
                }
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (Phase == NORMAL)
            {
                if (!UpdateVictim())
                    return;

                //If we are 100%MANA cast Arcane Erruption
                if (me->GetPower(POWER_MANA) == me->GetMaxPower(POWER_MANA))
                {
                    DoCast(me->getVictim(), SPELL_ARCANEERUPTION);
                    DoScriptText(EMOTE_MANA_FULL, me);
                    me->SetPower(POWER_MANA,0);
                }

                //Trample Spell
                if (uiTrampleTimer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_TRAMPLE);
                    uiTrampleTimer = urand(3000,7000);
                } else uiTrampleTimer -= diff;

                //Drain Mana
                if (uiDrainManaTimer <= diff)
                {
                    DrainMana();
                    uiDrainManaTimer = urand(3000,7000);
                } else uiDrainManaTimer -= diff;

                DoMeleeAttackIfReady();

                //After 90secs change phase
                if (uiPhaseTimer <= diff)
                {
                    Phase = STONE;
                    DoCast(me, SPELL_SUMMONMANA);
                    DoCast(me, SPELL_SUMMONMANA);
                    DoCast(me, SPELL_SUMMONMANA);
                    DoCast(me, SPELL_GRDRSLEEP);
                } else uiPhaseTimer -= diff;
            }
        }
    };

};


void AddSC_boss_moam()
{
    new boss_moam();
}
