/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

/* ScriptData
SDName: Boss_Chromaggus
SD%Complete: 95
SDComment: Chromatic Mutation disabled due to lack of core support
SDCategory: Blackwing Lair
EndScriptData */

#include "precompiled.h"

enum Emotes
{
    EMOTE_FRENZY                                           = -1469002,
    EMOTE_SHIMMER                                          = -1469003
};

enum Spells
{
    //These spells are actually called elemental shield
    //What they do is decrease all damage by 75% then they increase
    //One school of damage by 1100%
    SPELL_FIRE_VULNERABILITY                               = 22277,
    SPELL_FROST_VULNERABILITY                              = 22278,
    SPELL_SHADOW_VULNERABILITY                             = 22279,
    SPELL_NATURE_VULNERABILITY                             = 22280,
    SPELL_ARCANE_VULNERABILITY                             = 22281,
    //Other spells
    SPELL_INCINERATE                                       = 23308,   //Incinerate 23308,23309
    SPELL_TIMELAPSE                                        = 23310,   //Time lapse 23310, 23311(old threat mod that was removed in 2.01)
    SPELL_CORROSIVEACID                                    = 23313,   //Corrosive Acid 23313, 23314
    SPELL_IGNITEFLESH                                      = 23315,   //Ignite Flesh 23315,23316
    SPELL_FROSTBURN                                        = 23187,   //Frost burn 23187, 23189
    //Brood Affliction 23173 - Scripted Spell that cycles through all targets within 100 yards and has a chance to cast one of the afflictions on them
    //Since Scripted spells arn't coded I'll just write a function that does the same thing
    SPELL_BROODAF_BLUE                                     = 23153,   //Blue affliction 23153
    SPELL_BROODAF_BLACK                                    = 23154,   //Black affliction 23154
    SPELL_BROODAF_RED                                      = 23155,   //Red affliction 23155 (23168 on death)
    SPELL_BROODAF_BRONZE                                   = 23170,   //Bronze Affliction  23170
    SPELL_BROODAF_GREEN                                    = 23169,   //Brood Affliction Green 23169
    SPELL_CHROMATIC_MUT_1                                  = 23174,   //Spell cast on player if they get all 5 debuffs
    SPELL_FRENZY                                           = 28371,   //The frenzy spell may be wrong
    SPELL_ENRAGE                                           = 28747
};

struct TRINITY_DLL_DECL boss_chromaggusAI : public ScriptedAI
{
    boss_chromaggusAI(Creature *c) : ScriptedAI(c)
    {
        //Select the 2 breaths that we are going to use until despawned
        //5 possiblities for the first breath, 4 for the second, 20 total possiblites
        //This way we don't end up casting 2 of the same breath
        //TL TL would be stupid
        switch (urand(0,19))
        {
            //B1 - Incin
            case 0:
                Breath1_Spell = SPELL_INCINERATE;
                Breath2_Spell = SPELL_TIMELAPSE;
                break;
            case 1:
                Breath1_Spell = SPELL_INCINERATE;
                Breath2_Spell = SPELL_CORROSIVEACID;
                break;
            case 2:
                Breath1_Spell = SPELL_INCINERATE;
                Breath2_Spell = SPELL_IGNITEFLESH;
                break;
            case 3:
                Breath1_Spell = SPELL_INCINERATE;
                Breath2_Spell = SPELL_FROSTBURN;
                break;

                //B1 - TL
            case 4:
                Breath1_Spell = SPELL_TIMELAPSE;
                Breath2_Spell = SPELL_INCINERATE;
                break;
            case 5:
                Breath1_Spell = SPELL_TIMELAPSE;
                Breath2_Spell = SPELL_CORROSIVEACID;
                break;
            case 6:
                Breath1_Spell = SPELL_TIMELAPSE;
                Breath2_Spell = SPELL_IGNITEFLESH;
                break;
            case 7:
                Breath1_Spell = SPELL_TIMELAPSE;
                Breath2_Spell = SPELL_FROSTBURN;
                break;

                //B1 - Acid
            case 8:
                Breath1_Spell = SPELL_CORROSIVEACID;
                Breath2_Spell = SPELL_INCINERATE;
                break;
            case 9:
                Breath1_Spell = SPELL_CORROSIVEACID;
                Breath2_Spell = SPELL_TIMELAPSE;
                break;
            case 10:
                Breath1_Spell = SPELL_CORROSIVEACID;
                Breath2_Spell = SPELL_IGNITEFLESH;
                break;
            case 11:
                Breath1_Spell = SPELL_CORROSIVEACID;
                Breath2_Spell = SPELL_FROSTBURN;
                break;

                //B1 - Ignite
            case 12:
                Breath1_Spell = SPELL_IGNITEFLESH;
                Breath2_Spell = SPELL_INCINERATE;
                break;
            case 13:
                Breath1_Spell = SPELL_IGNITEFLESH;
                Breath2_Spell = SPELL_CORROSIVEACID;
                break;
            case 14:
                Breath1_Spell = SPELL_IGNITEFLESH;
                Breath2_Spell = SPELL_TIMELAPSE;
                break;
            case 15:
                Breath1_Spell = SPELL_IGNITEFLESH;
                Breath2_Spell = SPELL_FROSTBURN;
                break;

                //B1 - Frost
            case 16:
                Breath1_Spell = SPELL_FROSTBURN;
                Breath2_Spell = SPELL_INCINERATE;
                break;
            case 17:
                Breath1_Spell = SPELL_FROSTBURN;
                Breath2_Spell = SPELL_TIMELAPSE;
                break;
            case 18:
                Breath1_Spell = SPELL_FROSTBURN;
                Breath2_Spell = SPELL_CORROSIVEACID;
                break;
            case 19:
                Breath1_Spell = SPELL_FROSTBURN;
                Breath2_Spell = SPELL_IGNITEFLESH;
                break;
        };

        EnterEvadeMode();
    }

    uint32 Breath1_Spell;
    uint32 Breath2_Spell;
    uint32 CurrentVurln_Spell;

    uint32 Shimmer_Timer;
    uint32 Breath1_Timer;
    uint32 Breath2_Timer;
    uint32 Affliction_Timer;
    uint32 Frenzy_Timer;
    bool Enraged;

    void Reset()
    {
        CurrentVurln_Spell = 0;                             //We use this to store our last vulnerabilty spell so we can remove it later

        Shimmer_Timer = 0;                                  //Time till we change vurlnerabilites
        Breath1_Timer = 30000;                              //First breath is 30 seconds
        Breath2_Timer = 60000;                              //Second is 1 minute so that we can alternate
        Affliction_Timer = 10000;                           //This is special - 5 seconds means that we cast this on 1 player every 5 sconds
        Frenzy_Timer = 15000;

        Enraged = false;
    }

    void EnterCombat(Unit *who)
    {
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        //Shimmer_Timer Timer
        if (Shimmer_Timer <= diff)
        {
            //Remove old vulnerabilty spell
            if (CurrentVurln_Spell)
                m_creature->RemoveAurasDueToSpell(CurrentVurln_Spell);

            //Cast new random vulnerabilty on self
            uint32 spell = RAND(SPELL_FIRE_VULNERABILITY, SPELL_FROST_VULNERABILITY,
                SPELL_SHADOW_VULNERABILITY, SPELL_NATURE_VULNERABILITY, SPELL_ARCANE_VULNERABILITY);

            DoCast(m_creature, spell);
            CurrentVurln_Spell = spell;

            DoScriptText(EMOTE_SHIMMER, m_creature);
            Shimmer_Timer = 45000;
        } else Shimmer_Timer -= diff;

        //Breath1_Timer
        if (Breath1_Timer <= diff)
        {
            DoCast(m_creature->getVictim(), Breath1_Spell);
            Breath1_Timer = 60000;
        } else Breath1_Timer -= diff;

        //Breath2_Timer
        if (Breath2_Timer <= diff)
        {
            DoCast(m_creature->getVictim(), Breath2_Spell);
            Breath2_Timer = 60000;
        } else Breath2_Timer -= diff;

        //Affliction_Timer
        if (Affliction_Timer <= diff)
        {
            for (std::list<HostilReference*>::iterator i = m_creature->getThreatManager().getThreatList().begin(); i != m_creature->getThreatManager().getThreatList().end(); ++i)
            {
                Unit* pUnit;
                if ((*i)->getSource())
                {
                    pUnit = Unit::GetUnit((*m_creature), (*i)->getUnitGuid());
                    if (pUnit)
                    {
                        //Cast affliction
                        DoCast(pUnit, RAND(SPELL_BROODAF_BLUE, SPELL_BROODAF_BLACK,
                                           SPELL_BROODAF_RED, SPELL_BROODAF_BRONZE, SPELL_BROODAF_GREEN), true);

                        //Chromatic mutation if target is effected by all afflictions
                        if (pUnit->HasAura(SPELL_BROODAF_BLUE)
                            && pUnit->HasAura(SPELL_BROODAF_BLACK)
                            && pUnit->HasAura(SPELL_BROODAF_RED)
                            && pUnit->HasAura(SPELL_BROODAF_BRONZE)
                            && pUnit->HasAura(SPELL_BROODAF_GREEN))
                        {
                            //pTarget->RemoveAllAuras();
                            //DoCast(pTarget, SPELL_CHROMATIC_MUT_1);

                            //Chromatic mutation is causing issues
                            //Assuming it is caused by a lack of core support for Charm
                            //So instead we instant kill our target

                            //WORKAROUND
                            if (pUnit->GetTypeId() == TYPEID_PLAYER)
                                pUnit->CastSpell(pUnit, 5, false);
                        }
                    }
                }
            }

            Affliction_Timer = 10000;
        } else Affliction_Timer -= diff;

        //Frenzy_Timer
        if (Frenzy_Timer <= diff)
        {
            DoCast(m_creature, SPELL_FRENZY);
            DoScriptText(EMOTE_FRENZY, m_creature);
            Frenzy_Timer = urand(10000,15000);
        } else Frenzy_Timer -= diff;

        //Enrage if not already enraged and below 20%
        if (!Enraged && (m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) < 20)
        {
            DoCast(m_creature, SPELL_ENRAGE);
            Enraged = true;
        }

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_chromaggus(Creature* pCreature)
{
    return new boss_chromaggusAI (pCreature);
}

void AddSC_boss_chromaggus()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_chromaggus";
    newscript->GetAI = &GetAI_boss_chromaggus;
    newscript->RegisterSelf();
}

