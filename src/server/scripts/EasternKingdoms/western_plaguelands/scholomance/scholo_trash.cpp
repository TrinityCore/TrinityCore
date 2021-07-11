#include "scriptPCH.h"

enum
{
    SPELL_DARK_PLAGUE_AURA  = 12038,    // procs 18270
    SPELL_EXPLOSION         = 17689,
   //SPELL_FEIGN_DEATH       = 19822,
};

/*
-- fix dark plague proc rate and debuff stacking
DELETE FROM spell_proc_event WHERE entry = 12038;
INSERT INTO `spell_proc_event` (`entry`, `ppmRate`) VALUES ('12038', '3');
DELETE FROM spell_mod WHERE Id = 18270;
INSERT INTO `spell_mod` (`Id`, `Custom`, `Comment`) VALUES ('18270', '1', 'Scholomance: Dark Plague - Debuff stack between mobs');
*/

/*######
## npc_unstable_corpse
######*/

struct npc_unstable_corpseAI : public ScriptedAI
{
    npc_unstable_corpseAI(Creature* pCreature) : ScriptedAI(pCreature) {}

    void Reset() override {}

    void Aggro(Unit* /*pWho*/) override
    {
        DoCastSpellIfCan(m_creature, SPELL_DARK_PLAGUE_AURA, CF_TRIGGERED | CF_AURA_NOT_PRESENT);        
    }

    void JustDied(Unit* pKiller) override
    {
        m_creature->CastSpell(m_creature, SPELL_EXPLOSION, true);
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_unstable_corpse(Creature* pCreature)
{
    return new npc_unstable_corpseAI(pCreature);
}

/*######
## npc_reanimated_corpse
######*/

struct npc_reanimated_corpseAI : public ScriptedAI
{
    npc_reanimated_corpseAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 m_uiHealTimer;
    bool m_bHasRessed;

    void Reset() override
    {
        m_uiHealTimer = 0;
        m_bHasRessed = false;
        Resurrect();
    }

    void Aggro(Unit* /*pWho*/) override
    {
        DoCastSpellIfCan(m_creature, SPELL_DARK_PLAGUE_AURA, CF_TRIGGERED | CF_AURA_NOT_PRESENT);        
    }

    void Resurrect()
    {
        m_creature->SetHealth(m_creature->GetMaxHealth());
        m_creature->SetStandState(UNIT_STAND_STATE_STAND);
        m_creature->RemoveFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_DEAD);
        m_creature->AttackStop();
    }

    void DamageTaken(Unit* done_by, uint32& damage) override
    {
        if (damage < m_creature->GetHealth())
            return;

        if (!m_bHasRessed)
        {
            damage = 0;
            if (!m_uiHealTimer)
            {
                m_creature->SetHealth(0);
                m_creature->GetMotionMaster()->Clear();
                m_creature->GetMotionMaster()->MoveIdle();
                m_creature->SetStandState(UNIT_STAND_STATE_DEAD);
                m_creature->SetFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_DEAD);
                m_uiHealTimer = 10000;
            }
        }
    }

    void UpdateAI(uint32 const diff) override
    {
        if (m_uiHealTimer)
        {
            if (m_uiHealTimer <= diff)
            {
                Resurrect();
                m_bHasRessed = true;
                m_uiHealTimer = 0;
            }
            else
            {
                m_uiHealTimer -= diff;
                return;
            }
        }

        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_reanimated_corpse(Creature* pCreature)
{
    return new npc_reanimated_corpseAI(pCreature);
}


enum
{
    NPC_SPECTRAL_PROJECTION = 11263,

    SPELL_MANA_BURN         = 17630,
    SPELL_SILENCE           = 12528,
    SPELL_IMAGE_PROJECTION  = 17651,
    SPELL_PROJECTION_LEECH  = 17652,
    SPELL_SUMMON_PROJECTION = 17653
};

struct npc_spectral_projectionAI : public ScriptedAI
{
    npc_spectral_projectionAI(Creature* pCreature) : ScriptedAI(pCreature) { npc_spectral_projectionAI::Reset(); }

    void Reset() override
    {

    }

    void SpellHit(Unit* pCaster, SpellEntry const* pSpell) override
    {
        if (pSpell->Id == SPELL_PROJECTION_LEECH)
        {
            // hack life leech effect
            pCaster->SetHealth(pCaster->GetHealth() + 1000.0f);
            // remove from world, or projections will respawn 
            m_creature->RemoveFromWorld();
        }
    }
};

CreatureAI* GetAI_npc_spectral_projection(Creature* pCreature)
{
    return new npc_spectral_projectionAI(pCreature);
}

void AddSC_scholo_trash()
{
    Script* script;

    script = new Script;
    script->Name = "npc_unstable_corpse";
    script->GetAI = &GetAI_npc_unstable_corpse;
    script->RegisterSelf();

    script = new Script;
    script->Name = "npc_reanimated_corpse";
    script->GetAI = &GetAI_npc_reanimated_corpse;
    script->RegisterSelf();

    script = new Script;
    script->Name = "npc_spectral_projection";
    script->GetAI = &GetAI_npc_spectral_projection;
    script->RegisterSelf();
}
