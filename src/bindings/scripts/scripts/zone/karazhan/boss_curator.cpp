/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/* ScriptData
SDName: Boss_Curator
SD%Complete: 100
SDComment: Evocation may cause client crash (Core related)
SDCategory: Karazhan
EndScriptData */

#include "precompiled.h"

#define SAY_AGGRO           "The Menagerie is for guests only."
#define SOUND_AGGRO         9183

#define SAY_SUMMON1         "Gallery rules will be strictly enforced."
#define SOUND_SUMMON1       9188

#define SAY_SUMMON2         "This curator is equipped for gallery protection."
#define SOUND_SUMMON2       9309

#define SAY_EVOCATE         "Your request cannot be processed."
#define SOUND_EVOCATE       9186

#define SAY_ENRAGE          "Failure to comply will result in offensive action."
#define SOUND_ENRAGE        9185

#define SAY_KILL1           "Do not touch the displays."
#define SOUND_KILL1         9187

#define SAY_KILL2           "You are not a guest."
#define SOUND_KILL2         9308

#define SAY_DEATH           "This Curator is no longer op... er... ation... al."
#define SOUND_DEATH         9184

//Flare spell info
#define SPELL_ASTRAL_FLARE_PASSIVE      30234
#define SPELL_ASTRAL_FLARE_NE           30236
#define SPELL_ASTRAL_FLARE_NW           30239
#define SPELL_ASTRAL_FLARE_SE           30240
#define SPELL_ASTRAL_FLARE_SW           30241

//Curator spell info
#define SPELL_HATEFUL_BOLT              30383
#define SPELL_EVOCATION                 30254
#define SPELL_ENRAGE                    28131
#define SPELL_BERSERK                   26662

struct MANGOS_DLL_DECL boss_curatorAI : public ScriptedAI
{
    boss_curatorAI(Creature *c) : ScriptedAI(c) {Reset();}

    uint32 AddTimer;
    uint32 HatefulBoltTimer;
    uint32 BerserkTimer;

    bool Enraged;
    bool Evocating;

    void Reset()
    {
        AddTimer = 10000;
        HatefulBoltTimer = 15000;                           // This time is probably wrong
        BerserkTimer = 720000;                              //12 minutes
        Enraged = false;
        Evocating = false;
    }

    void KilledUnit(Unit *victim)
    {
        switch(rand()%2)
        {
            case 0:
                DoYell(SAY_KILL1, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(victim, SOUND_KILL1);
                break;
            case 1:
                DoYell(SAY_KILL2, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(victim, SOUND_KILL2);
                break;
        }
    }

    void JustDied(Unit *victim)
    {
        DoYell(SAY_DEATH, LANG_UNIVERSAL, NULL);
        DoPlaySoundToSet(NULL, SOUND_DEATH);
    }

    void Aggro(Unit *who)
    {
        DoYell(SAY_AGGRO, LANG_UNIVERSAL, NULL);
        DoPlaySoundToSet(m_creature, SOUND_AGGRO);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim() )
            return;

        if (Evocating && !m_creature->HasAura(SPELL_EVOCATION, 0))
            Evocating = false;

        if(m_creature->GetPower(POWER_MANA) <= 1000 && !Evocating)
        {
            DoYell(SAY_EVOCATE, LANG_UNIVERSAL, NULL);
            DoPlaySoundToSet(m_creature, SOUND_EVOCATE);
            m_creature->InterruptNonMeleeSpells(false);
            DoCast(m_creature, SPELL_EVOCATION);
            Evocating = true;
        }

        if(!Enraged && !Evocating)
        {
            if(AddTimer < diff)
            {
                //Summon Astral Flare
                Creature* AstralFlare = DoSpawnCreature(17096, 0, 0, 0, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                Unit* target = NULL;
                target = SelectUnit(SELECT_TARGET_RANDOM, 0);

                if (AstralFlare && target)
                {
                    AstralFlare->CastSpell(AstralFlare, SPELL_ASTRAL_FLARE_PASSIVE, false);
                    AstralFlare->AI()->AttackStart(target);
                }

                //Reduce Mana by 10%
                int32 mana = (int32)(0.1f*(m_creature->GetMaxPower(POWER_MANA)));
                m_creature->ModifyPower(POWER_MANA, -mana);
                switch(rand()%4)
                {
                    case 0:
                        DoYell(SAY_SUMMON1, LANG_UNIVERSAL, NULL);
                        DoPlaySoundToSet(m_creature, SOUND_SUMMON1);
                        break;
                    case 1:
                        DoYell(SAY_SUMMON2, LANG_UNIVERSAL, NULL);
                        DoPlaySoundToSet(m_creature, SOUND_SUMMON2);
                        break;
                }
                AddTimer = 10000;
            }else AddTimer -= diff;

            if(HatefulBoltTimer < diff)
            {
                Unit* target = NULL;
                target = SelectUnit(SELECT_TARGET_TOPAGGRO, 1);
                DoCast(target, SPELL_HATEFUL_BOLT);

                HatefulBoltTimer = 15000;
            }else HatefulBoltTimer -= diff;

            if(m_creature->GetHealth()*100 / m_creature->GetMaxHealth() < 15)
            {
                Enraged = true;
                DoCast(m_creature, SPELL_ENRAGE);
                DoYell(SAY_ENRAGE, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(m_creature, SOUND_ENRAGE);
            }
        }

        if(BerserkTimer < diff)
        {
            DoCast(m_creature, SPELL_BERSERK);
            DoYell(SAY_ENRAGE, LANG_UNIVERSAL, NULL);
            DoPlaySoundToSet(m_creature, SOUND_ENRAGE);
        }else BerserkTimer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_curator(Creature *_Creature)
{
    return new boss_curatorAI (_Creature);
}

void AddSC_boss_curator()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_curator";
    newscript->GetAI = GetAI_boss_curator;
    m_scripts[nrscripts++] = newscript;
}
