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
SDName: Boss_Vectus
SD%Complete: 95
SDComment: event gambit de l'aube : Chakor
SDCategory: Scholomance
EndScriptData */

#include "scriptPCH.h"
#include "CreatureGroups.h"
#include "scholomance.h"

enum
{
    //EMOTE_GENERIC_FRENZY_KILL   = 7797,

    NPC_STUDENT                                     = 10475,
    NPC_MARDUK_BLACKPOOL                            = 10433,

    VECTUS_SPEECH_GAMBIT_EVENT_START                = 6883,

    FACTION_MONSTER                                 = 16,

    GO_DAWN_S_GAMBIT                                = 177304,

    SPELL_VIEWING_ROOM_STUDENT_TRANSFORM_EFFECT     = 18115,    //spell qui transforme les étudiants élites en squelettes
    SPELL_FLAMESTRIKE                               = 18399,
    SPELL_BLAST_WAVE                                = 16046
  //SPELL_FRENZY                                    = 28371     //spell is used by Gluth, confirm this is for this boss too
  //SPELL_FIRE_SHIELD                               = 0         //should supposedly have some aura, but proper spell not found
};

struct boss_vectusAI : public ScriptedAI
{
    boss_vectusAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_bStartedDialogue      = false;
        eventGambitDone         = false;
        eventGambitStart        = false;
        findGambit              = false;
        m_uiGambitEvent_Timer   = 0;
        pGambit     = nullptr;
        Reset();
    }

    uint32 m_uiFlameStrike_Timer;
    uint32 m_uiBlastWave_Timer;
    uint32 m_uiFrenzy_Timer;
    uint32 m_uiGambitEvent_Timer;
    bool   _fullAggroDone;
    bool   eventGambitDone;
    bool   eventGambitStart;
    bool   findGambit;
    GameObject* pGambit;

    bool m_bStartedDialogue;

    void Reset() override
    {
        m_uiFlameStrike_Timer   = 2000;
        m_uiBlastWave_Timer     = 14000;
        m_uiFrenzy_Timer        = 0;
        _fullAggroDone          = false;
    }

    void MoveInLineOfSight(Unit* pWho) override
    {        
        if (!m_bStartedDialogue)
        {
            if (pWho->IsPlayer() && m_creature->IsWithinDistInMap(pWho, 32.0f) && m_creature->IsWithinLOSInMap(pWho))
            {
                m_creature->SetDefaultMovementType(WAYPOINT_MOTION_TYPE);
                m_creature->GetMotionMaster()->Initialize();
                m_bStartedDialogue = true;
            }
        }

        ScriptedAI::MoveInLineOfSight(pWho);
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        // Chakor@Nostalrius : Event Du Gambit
        if (!eventGambitDone)
        {
            if (m_uiGambitEvent_Timer < uiDiff)
            {
                if (!eventGambitStart)
                {
                    if (!findGambit)
                    {
                        if (pGambit = GetClosestGameObjectWithEntry(m_creature, GO_DAWN_S_GAMBIT, 100.0f))
                        {
                            m_uiGambitEvent_Timer = 2000;
                            findGambit = true;
                        }
                    }
                    else
                    {
                        pGambit->Delete();
                        m_uiGambitEvent_Timer = 12000;
                        eventGambitStart = true;
                    }
                }
                else
                {
                    Creature* Marduck = m_creature->FindNearestCreature(NPC_MARDUK_BLACKPOOL, 100.0f);
                    if (Marduck)
                    {
                        Marduck->SetFactionTemplateId(FACTION_MONSTER);
                        Marduck->SetReactState(REACT_AGGRESSIVE);
                        Marduck->AIM_Initialize();
                    }

                    std::list<Creature*> creatures;
                    m_creature->GetCreatureListWithEntryInGrid(creatures, NPC_STUDENT, 100.0f);
                    for (const auto& creature : creatures)
                    {
                        creature->CastSpell(creature, SPELL_VIEWING_ROOM_STUDENT_TRANSFORM_EFFECT, true);
                        if (CreatureGroup* myGroup = creature->GetCreatureGroup())
                        {
                            myGroup->RemoveMember(creature->GetGUID());
                            creature->SetCreatureGroup(nullptr);
                        }

                        creature->SetFactionTemplateId(FACTION_MONSTER);
                        creature->SetReactState(REACT_AGGRESSIVE);
                        creature->AIM_Initialize();
                    }

                    m_creature->MonsterYell(VECTUS_SPEECH_GAMBIT_EVENT_START, 0, 0);
                    m_creature->SetFactionTemplateId(FACTION_MONSTER);
                    m_creature->SetReactState(REACT_AGGRESSIVE);
                    m_creature->AIM_Initialize();

                    eventGambitDone = true;
                }
            }
            else
                m_uiGambitEvent_Timer -= uiDiff;
        }

        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        // NOSTALRIUS: Aggro toute la salle lorsqu'il est pull.
        if (!_fullAggroDone)
        {
            std::list<Creature*> creatures;
            m_creature->GetCreatureListWithEntryInGrid(creatures, NPC_STUDENT, 100.0f);
            for (const auto& creature : creatures)
            {
                creature->SetFactionTemplateId(FACTION_MONSTER);
                creature->AI()->AttackStart(m_creature->GetVictim());
            }
            _fullAggroDone = true;
        }

        //m_uiFlameStrike_Timer
        if (m_uiFlameStrike_Timer < uiDiff)
        {
            DoCastSpellIfCan(m_creature, SPELL_FLAMESTRIKE);
            m_uiFlameStrike_Timer = 30000;
        }
        else
            m_uiFlameStrike_Timer -= uiDiff;

        //BlastWave_Timer
        if (m_uiBlastWave_Timer < uiDiff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_BLAST_WAVE);
            m_uiBlastWave_Timer = 12000;
        }
        else
            m_uiBlastWave_Timer -= uiDiff;

        //Frenzy_Timer
        /*if (m_creature->GetHealthPercent() < 25.0f)
        {
            if (m_uiFrenzy_Timer < uiDiff)
            {
                DoCastSpellIfCan(m_creature, SPELL_FRENZY);
                DoScriptText(EMOTE_GENERIC_FRENZY_KILL, m_creature);
                m_uiFrenzy_Timer = 24000;
            }
            else
                m_uiFrenzy_Timer -= uiDiff;
        }*/

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_vectus(Creature* pCreature)
{
    return new boss_vectusAI(pCreature);
}

/*######
## npc_scholomance_student
######*/

struct npc_scholomance_studentAI : public ScriptedAI
{
    npc_scholomance_studentAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*) pCreature->GetInstanceData();
        isTransformed = false;
        Reset();
    }
    ScriptedInstance* m_pInstance;
    bool isTransformed;

    void Reset() override {}

    void SpellHit(Unit *pCaster, SpellEntry const* pSpell) override
    {
        if (pSpell->Id == SPELL_VIEWING_ROOM_STUDENT_TRANSFORM_EFFECT)
        {
            isTransformed = true;

            if (m_creature->GetGUIDLow() == 48949)
            {
                m_creature->ForcedDespawn();
                m_creature->Respawn();
            }
        }
    }

    void Aggro(Unit* /*pWho*/) override
    {
        // set the viewing room and Marduk and Vectus to hostile on aggro
        std::list<Creature*> creatures;
        m_creature->GetCreatureListWithEntryInGrid(creatures, NPC_STUDENT, 100.0f);
        for (const auto& creature : creatures)
            creature->SetFactionTemplateId(FACTION_MONSTER);

        if (Creature* pMarduck = m_creature->FindNearestCreature(NPC_MARDUK_BLACKPOOL, 100.0f))
            pMarduck->SetFactionTemplateId(FACTION_MONSTER);

        if (Creature* pVectus = m_creature->FindNearestCreature(NPC_VECTUS, 100.0f))
            pVectus->SetFactionTemplateId(FACTION_MONSTER);
    }

    void JustDied(Unit* Killer) override
    {
        if (isTransformed)
        {
            if(!m_creature->FindNearestCreature(NPC_STUDENT, 100.0f, true) && m_pInstance)
            {
                //delink les deux boss
                Creature * Vectus = (Creature*) m_creature->GetMap()->GetUnit(m_pInstance->GetData64(DATA_VECTUS));
                Creature * Marduke = (Creature*) m_creature->GetMap()->GetUnit(m_pInstance->GetData64(DATA_MARDUKE));
                if ( Vectus && Marduke )
                {
                    if (CreatureGroup* myGroup = Vectus->GetCreatureGroup())
                    {
                        if(myGroup == Marduke->GetCreatureGroup())
                        {
                            myGroup->RemoveMember(Vectus->GetGUID());
                            myGroup->RemoveMember(Marduke->GetGUID());
                            Vectus->SetCreatureGroup(nullptr);
                            Marduke->SetCreatureGroup(nullptr);
                        }
                    }
                }
            }

            //this was already there
            m_creature->ForcedDespawn();
        }
    }

    void JustRespawned() override
    {
        if (isTransformed)
            m_creature->AddAura(SPELL_VIEWING_ROOM_STUDENT_TRANSFORM_EFFECT, ADD_AURA_NO_OPTION, m_creature);

        Reset();
    }

    void EnterEvadeMode() override
    {
        m_creature->RemoveAllAuras();
        m_creature->DeleteThreatList();
        m_creature->CombatStop(true);
        m_creature->LoadCreatureAddon(true);

        if (isTransformed)
            m_creature->AddAura(SPELL_VIEWING_ROOM_STUDENT_TRANSFORM_EFFECT, ADD_AURA_NO_OPTION, m_creature);

        if (m_creature->IsAlive())
            m_creature->GetMotionMaster()->MoveTargetedHome();

        m_creature->SetLootRecipient(nullptr);

        Reset();
    }
};

CreatureAI* GetAI_npc_scholomance_student(Creature* pCreature)
{
    return new npc_scholomance_studentAI(pCreature);
}

void AddSC_boss_vectus()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "boss_vectus";
    newscript->GetAI = &GetAI_boss_vectus;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_scholomance_student";
    newscript->GetAI = &GetAI_npc_scholomance_student;
    newscript->RegisterSelf();
}
