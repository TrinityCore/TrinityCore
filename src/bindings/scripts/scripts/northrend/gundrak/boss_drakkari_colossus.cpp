/* Script Data Start
SDName: Boss Drakkari Colossus
SDAuthor: Manuel
SD%Complete: 95 %
SDComment: The event with the Living Mojos is not implemented, just is done that when one of the mojos around the boss take damage will make that the boss enter in combat!
SDCategory:
Script Data End */

#include "precompiled.h"
#include "def_gundrak.h"

enum Spells
{
    SPELL_EMERGE        = 54850,
    SPELL_EMERGE_2      = 54851,

    SPELL_MIGHTY_BLOW   = 54719,

    SPELL_MERGE         = 54878,
    SPELL_SURGE         = 54801,

    SPELL_FREEZE_ANIM   = 16245
};

enum Entrys
{
    DRAKKARI_COLOSSUS   = 29307,
    DRAKKARI_ELEMENTAL  = 29573
};

struct TRINITY_DLL_DECL boss_drakkari_colossusAI : public ScriptedAI
{
    boss_drakkari_colossusAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    ScriptedInstance* pInstance;

    bool Summoned;

    uint32 Summon_Timer;
    uint32 MightyBlowTimer;

    void Reset()
    {
        if (pInstance)
            pInstance->SetData(DATA_DRAKKARI_COLOSSUS_EVENT, NOT_STARTED);


        m_creature->clearUnitState(UNIT_STAT_STUNNED);
        m_creature->SetReactState(REACT_PASSIVE);

        Summoned = false;

        MightyBlowTimer = 10000;
    }

    void EnterCombat(Unit* who)
    {
        if (pInstance)
            pInstance->SetData(DATA_DRAKKARI_COLOSSUS_EVENT, IN_PROGRESS);
    }

    void PrepareToSummonElemental()
    {
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        m_creature->addUnitState(UNIT_STAT_STUNNED);
        m_creature->CastSpell(m_creature,SPELL_EMERGE,false);
    }
    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        if(Summoned == false && m_creature->GetHealth()*100 / m_creature->GetMaxHealth() <= 50 && m_creature->GetHealth()*100 / m_creature->GetMaxHealth() > 6)
        {
            PrepareToSummonElemental();
            m_creature->CastSpell(m_creature->getVictim(), SPELL_EMERGE_2, true);
            Summoned = true;
        }

        if(Summoned == true && m_creature->GetHealth()*100 / m_creature->GetMaxHealth() <= 5)
        {
            m_creature->RemoveAllAuras();
            m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            m_creature->addUnitState(UNIT_STAT_STUNNED);
            m_creature->RemoveAllAuras();

            Summoned = false;
        }

        if (MightyBlowTimer < diff)
        {
            if(!m_creature->hasUnitState(UNIT_STAT_STUNNED))
            {
                m_creature->CastSpell(m_creature->getVictim(),SPELL_MIGHTY_BLOW,true);
            }

            MightyBlowTimer = 10000;
        }else MightyBlowTimer -= diff;

        if(!m_creature->hasUnitState(UNIT_STAT_STUNNED))
        {
            DoMeleeAttackIfReady();
        }
    }

    void JustDied(Unit* killer)
    {
        if (pInstance)
            pInstance->SetData(DATA_DRAKKARI_COLOSSUS_EVENT, DONE);
    }

    void JustSummoned(Creature* summoned)
    {
        summoned->AI()->AttackStart(m_creature->getVictim());
    }
};

struct TRINITY_DLL_DECL boss_drakkari_elementalAI : public ScriptedAI
{
    boss_drakkari_elementalAI(Creature *c) : ScriptedAI(c)
    {
        Colossus  = c->FindNearestCreature(DRAKKARI_COLOSSUS, 30.0f, true);
    }

    Creature* Colossus;

    uint32 SurgeTimer;

    bool PreparationDone;
    bool GoToColossus;
    bool Checked;

    void Reset()
    {
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        m_creature->clearUnitState(UNIT_STAT_STUNNED);

        SurgeTimer = 7000;

        GoToColossus = false;
        PreparationDone = false;
        Checked = false;
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if(!UpdateVictim())
            return;

            if(GoToColossus == false && m_creature->GetHealth()*100 / m_creature->GetMaxHealth() <= 50)
            {
                m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                m_creature->CastSpell(Colossus ,SPELL_MERGE,true);

                GoToColossus = true;
                PreparationDone = true;
            }

            if(GoToColossus == true && PreparationDone == true)
            {
                m_creature->addUnitState(UNIT_STAT_STUNNED);
                m_creature->SetVisibility(VISIBILITY_OFF);
                m_creature->CastSpell(Colossus ,SPELL_MERGE,true);

                PreparationDone = false;

                Colossus->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                Colossus->clearUnitState(UNIT_STAT_STUNNED);
            }

            if (SurgeTimer < diff)
            {
                if(m_creature->GetVisibility() == VISIBILITY_ON)
                {
                    Unit* target = SelectUnit(SELECT_TARGET_RANDOM, 0);

                    m_creature->CastSpell(target,SPELL_SURGE,false);
                }

                SurgeTimer = 7000;
            }else SurgeTimer -= diff;

            if(Checked == false && Colossus->GetHealth()*100 / Colossus->GetMaxHealth() <= 5)
            {
                m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                m_creature->clearUnitState(UNIT_STAT_STUNNED);
                m_creature->SetVisibility(VISIBILITY_ON);
                Checked = true;
            }

        //prevent do melee if is invisible
        if(m_creature->GetVisibility() == VISIBILITY_ON)
        {
            DoMeleeAttackIfReady();
        }
    }

   void JustDied(Unit* killer)
    {
        Colossus->Kill(Colossus);
    }
};

struct TRINITY_DLL_DECL npc_living_mojoAI : public ScriptedAI
{
    npc_living_mojoAI(Creature *c) : ScriptedAI(c) {}

    void Reset()
    {
        if(m_creature->IsInRange3d(1672.959,743.487,143.337,0.0f,17.0f))
        {
            m_creature->SetReactState(REACT_PASSIVE);

        }else

        m_creature->SetReactState(REACT_AGGRESSIVE);
    }

    void DamageTaken(Unit* pDone_by, uint32& uiDamage)
    {
        if(m_creature->HasReactState(REACT_PASSIVE))
        {
            if(Creature* Colossus = m_creature->FindNearestCreature(DRAKKARI_COLOSSUS, 30.0f, true))
            {
                Colossus->RemoveAura(SPELL_FREEZE_ANIM);
                Colossus->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
                Colossus->SetReactState(REACT_AGGRESSIVE);
            }

        }
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if(!UpdateVictim())
            return;

            DoMeleeAttackIfReady();
    }

};

CreatureAI* GetAI_boss_drakkari_colossus(Creature* pCreature)
{
    return new boss_drakkari_colossusAI (pCreature);
}

CreatureAI* GetAI_boss_drakkari_elemental(Creature* pCreature)
{
    return new boss_drakkari_elementalAI (pCreature);
}

CreatureAI* GetAI_npc_living_mojo(Creature* pCreature)
{
    return new npc_living_mojoAI (pCreature);
}

void AddSC_boss_drakkari_colossus()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_drakkari_colossus";
    newscript->GetAI = &GetAI_boss_drakkari_colossus;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="boss_drakkari_elemental";
    newscript->GetAI = &GetAI_boss_drakkari_elemental;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_living_mojo";
    newscript->GetAI = &GetAI_npc_living_mojo;
    newscript->RegisterSelf();
}
