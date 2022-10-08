/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Boss_Hakkar
SD%Complete: 95
SDComment: Blood siphon spell buggy cause of Core Issue.
SDCategory: Zul'Gurub
EndScriptData */

#include "scriptPCH.h"
#include "zulgurub.h"

enum
{
    // Datas :
    // NPC_HAKKAR                  = 14834,

    // Emotes
    // ------

    SAY_AGGRO                   = -1309020,
    SAY_FLEEING                 = -1309021,
    SAY_MINION_DESTROY          = -1309022,                //where does it belong?
    SAY_PROTECT_ALTAR           = -1309023,                //where does it belong?
    /*
    /run PlaySoundFile("SOUND\\CREATURE\\HAKKAR\\VO_ZG2_HAKKAR_DEFEAT_01.ogg");
    /run PlaySoundFile("SOUND\\CREATURE\\HAKKAR\\VO_ZG2_HAKKAR_DEFEAT_02.ogg");
    /run PlaySoundFile("SOUND\\CREATURE\\HAKKAR\\VO_ZG2_HAKKAR_EVENT_BREAK_CHAIN.ogg");
    /run PlaySoundFile("SOUND\\CREATURE\\HAKKAR\\VO_ZG2_HAKKAR_EVENT_START.ogg");
    */

    // Hakkar's spells
    // ---------------

    SPELL_BLOODSIPHON_STUN       = 24324, // Joueur assomme
    SPELL_BLOODSIPHON_DAMAGE     = 24323, // "Votre sang est empoisonne"
    SPELL_BLOODSIPHON_HEAL       = 24322, // "Inflige 200 points de dégâts par seconde. Donne à Hakkar 1000 points de vie par seconde." -> Rend de la vie aux joueurs ...
    SPELL_CORRUPTEDBLOOD         = 24328,
    SPELL_CAUSEINSANITY          = 24327,
    SPELL_WILLOFHAKKAR           = 24178,
    // SPELL_ENRAGE                 = 24318,
    SPELL_BERSERK                = 27680,

    // Aspects of High Priests
    // -----------------------

    SPELL_ASPECT_OF_JEKLIK       = 24687, // silence 4 sec
    SPELL_ASPECT_OF_VENOXIS      = 24688, // poison
    SPELL_ASPECT_OF_MARLI        = 24686, // étourdi 5 sec
    SPELL_ASPECT_OF_THEKAL       = 24689, // enrage qqs sec
    SPELL_ASPECT_OF_ARLOKK       = 24690, // vanish qqs secs

    // Other spells
    // ------------
    SPELL_POISONOUS_BLOOD        = 24321
};

struct boss_hakkarAI : public ScriptedAI
{
    boss_hakkarAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
    }

    ScriptedInstance* m_pInstance;

    uint32 BloodSiphon_Timer;
    uint32 CorruptedBlood_Timer;
    uint32 CauseInsanity_Timer;
    uint64 InsanePlayerGuid;
    float InsanePlayerAggro;
    uint32 Berserk_Timer;
    uint32 CCDelayInsanity_Timer;

    uint32 AspectOfJeklik_Timer;
    uint32 AspectOfVenoxis_Timer;
    uint32 AspectOfMarli_Timer;
    uint32 AspectOfThekal_Timer;
    uint32 AspectOfArlokk_Timer;

    bool Enraged;

    void Reset() override
    {
        BloodSiphon_Timer = 90000;
        CorruptedBlood_Timer = 15000;
        CauseInsanity_Timer = 17000;
        InsanePlayerGuid = 0;
        InsanePlayerAggro = 0;
        Berserk_Timer = 600000;
        CCDelayInsanity_Timer = 4000;

        AspectOfJeklik_Timer = 4000;
        AspectOfVenoxis_Timer = 7000;
        AspectOfMarli_Timer = 12000;
        AspectOfThekal_Timer = 8000;
        AspectOfArlokk_Timer = 18000;

        Enraged = false;

        if (m_pInstance)
            m_pInstance->SetData(TYPE_HAKKAR, NOT_STARTED);
    }

    void Aggro(Unit *who) override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_HAKKAR, IN_PROGRESS);
        DoScriptText(SAY_AGGRO, m_creature);

        ScriptedAI::Aggro(who);
    }

    void JustDied(Unit* Killer) override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_HAKKAR, DONE);
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_pInstance || !m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        /** Prevent exploit */
        if (m_creature->GetPositionZ() > 57.28f || m_creature->GetPositionZ() < 45.8f)
        {
            EnterEvadeMode();
            return;
        }

        if (CCDelayInsanity_Timer < diff)
        {
            if (InsanePlayerGuid)
            {
                if (Unit* pTarget = m_creature->GetMap()->GetPlayer(InsanePlayerGuid))
                {
                    if (!pTarget->HasAura(SPELL_CAUSEINSANITY))
                    {
                        m_creature->GetThreatManager().modifyThreatPercent(pTarget, -100);
                        m_creature->GetThreatManager().addThreatDirectly(pTarget, InsanePlayerAggro);

                        InsanePlayerGuid = 0;
                        InsanePlayerAggro = 0;
                    }
                }
                else
                {
                    InsanePlayerGuid = 0;
                    InsanePlayerAggro = 0;
                }
            }
        }
        else
            CCDelayInsanity_Timer -= diff;


        if (m_creature->IsNonMeleeSpellCasted(false))
            return;

        // BLOODSIPHON
        if (BloodSiphon_Timer < diff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_BLOODSIPHON_STUN) == CAST_OK)
                BloodSiphon_Timer = 90000;
        }
        else
            BloodSiphon_Timer -= diff;

        // CORRUPTEDBLOOD
        if (CorruptedBlood_Timer < diff)
        {
            if (Unit* target = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
            {
                if (DoCastSpellIfCan(target, SPELL_CORRUPTEDBLOOD) == CAST_OK)
                    CorruptedBlood_Timer = urand(14000, 16000);
            }

        }
        else
            CorruptedBlood_Timer -= diff;

        // CAUSEINSANITY
        if (CauseInsanity_Timer < diff)
        {
            if (Unit* pTarget = m_creature->GetVictim())
            {
                InsanePlayerGuid = pTarget->GetGUID();
                InsanePlayerAggro = m_creature->GetThreatManager().getThreat(pTarget);

                if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_CAUSEINSANITY) == CAST_OK)
                {
                    CCDelayInsanity_Timer = 4000;
                    //DoScriptText(SAY_FLEEING, m_creature);
                    CauseInsanity_Timer = urand(20000, 25000);
                }
            }
        }
        else
            CauseInsanity_Timer -= diff;

        // BERSERK
        // if ((Berserk_Timer < diff) || (m_creature->GetHealthPercent() < 5.0f))
        if (Berserk_Timer < diff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_BERSERK, CF_AURA_NOT_PRESENT) == CAST_OK)
                Berserk_Timer = 2000;
        }
        else
            Berserk_Timer -= diff;

        //Checking if Jeklik is dead. If not we cast her Aspect
        if (m_pInstance->GetData(TYPE_JEKLIK) != DONE)
        {
            if (AspectOfJeklik_Timer < diff)
            {
                if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_ASPECT_OF_JEKLIK) == CAST_OK)
                    AspectOfJeklik_Timer = urand(10000, 14000);
            }
            else
                AspectOfJeklik_Timer -= diff;
        }

        //Checking if Venoxis is dead. If not we cast his Aspect
        if (m_pInstance->GetData(TYPE_VENOXIS) != DONE)
        {
            if (AspectOfVenoxis_Timer < diff)
            {
                if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_ASPECT_OF_VENOXIS) == CAST_OK)
                    AspectOfVenoxis_Timer = 8000;
            }
            else
                AspectOfVenoxis_Timer -= diff;
        }

        //Checking if Marli is dead. If not we cast her Aspect
        if (m_pInstance->GetData(TYPE_MARLI) != DONE)
        {
            if (AspectOfMarli_Timer < diff)
            {
                if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_ASPECT_OF_MARLI) == CAST_OK)
                    AspectOfMarli_Timer = 10000;
            }
            else
                AspectOfMarli_Timer -= diff;
        }

        //Checking if Thekal is dead. If not we cast his Aspect
        if (m_pInstance->GetData(TYPE_THEKAL) != DONE)
        {
            if (AspectOfThekal_Timer < diff)
            {
                if (DoCastSpellIfCan(m_creature, SPELL_ASPECT_OF_THEKAL) == CAST_OK)
                    AspectOfThekal_Timer = 15000;
            }
            else
                AspectOfThekal_Timer -= diff;
        }

        //Checking if Arlokk is dead. If not we cast her Aspect
        if (m_pInstance->GetData(TYPE_ARLOKK) != DONE)
        {
            if (AspectOfArlokk_Timer < diff)
            {
                if (DoCastSpellIfCan(m_creature, SPELL_ASPECT_OF_ARLOKK) == CAST_OK)
                {
                    DoResetThreat();
                    AspectOfArlokk_Timer = urand(10000, 15000);
                }
            }
            else
                AspectOfArlokk_Timer -= diff;
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_hakkar(Creature* pCreature)
{
    return new boss_hakkarAI(pCreature);
}

void AddSC_boss_hakkar()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "boss_hakkar";
    newscript->GetAI = &GetAI_boss_hakkar;
    newscript->RegisterSelf();
}
