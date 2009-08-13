/*
 * Copyright (C) 2009 Trinity <http://www.trinitycore.org/>
 *
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

#include "precompiled.h"

/*####
## npc_drakuru_shackles
####*/

enum
{
    SPELL_LEFT_CHAIN           = 59951,
    SPELL_RIGHT_CHAIN          = 59952,
    SPELL_UNLOCK_SHACKLE       = 55083,
    SPELL_FREE_RAGECLAW        = 55223,

    NPC_RAGECLAW               = 29686
};

struct TRINITY_DLL_DECL npc_drakuru_shacklesAI : public ScriptedAI
{
    npc_drakuru_shacklesAI(Creature *c) : ScriptedAI(c) {}

    Unit* Rageclaw;
    
    void Reset()
    {
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        float x, y, z;
        Rageclaw = NULL;
        m_creature->GetClosePoint(x, y, z, m_creature->GetObjectSize()/3,0.1);
        if (Unit* summon = m_creature->SummonCreature(NPC_RAGECLAW,x,y,z,0,TEMPSUMMON_DEAD_DESPAWN,1000))
            DoActionOnRageclaw(true,summon);
    }

    void DoActionOnRageclaw(bool locking, Unit *who)
    {
        if (!who)
            return;

        if (locking)
        {
            if (who)
            {
                Rageclaw = who;

                m_creature->SetInFront(Rageclaw);
                Rageclaw->SetInFront(m_creature);

                m_creature->CastSpell(Rageclaw, SPELL_LEFT_CHAIN, true);
                m_creature->CastSpell(Rageclaw, SPELL_RIGHT_CHAIN, true);
            }
        }
        else
        {
            DoCast(Rageclaw, SPELL_FREE_RAGECLAW, true);
            CAST_PLR(who)->KilledMonsterCredit(NPC_RAGECLAW, Rageclaw->GetGUID());
            m_creature->setDeathState(DEAD);
        }
    }

    void SpellHit(Unit *caster, const SpellEntry *spell)
    {
        if (spell->Id == SPELL_UNLOCK_SHACKLE)
        {
            if (Rageclaw)
                DoActionOnRageclaw(false,caster);
            else
                m_creature->setDeathState(JUST_DIED);

        }
    }
};

CreatureAI* GetAI_npc_drakuru_shackles(Creature* pCreature)
{
    return new npc_drakuru_shacklesAI (pCreature);
}


/*####
## npc_captured_rageclaw
####*/

enum
{
    SPELL_UNSHACKLED           = 55085,
    SPELL_KNEEL                = 39656
};

const char * SAY_RAGECLAW_1 =      "I poop on you, trollses!";
const char * SAY_RAGECLAW_2 =      "ARRRROOOOGGGGAAAA!";
const char * SAY_RAGECLAW_3 =      "No more mister nice wolvar!";
#define SAY_RAGECLAW RAND(SAY_RAGECLAW_1,SAY_RAGECLAW_2,SAY_RAGECLAW_3)

struct TRINITY_DLL_DECL npc_captured_rageclawAI : public ScriptedAI
{
    npc_captured_rageclawAI(Creature *c) : ScriptedAI(c) {}

    uint32 DespawnTimer;
    bool Despawn;

    void Reset()
    {
        Despawn = false;
        DespawnTimer = 0;
        m_creature->setFaction(35);
        m_creature->CastSpell(m_creature, SPELL_KNEEL, true); // Little Hack for kneel - Thanks Illy :P
    }

    void MoveInLineOfSight(Unit *who){}
    
    void SpellHit(Unit *caster, const SpellEntry *spell)
    {
        if (spell->Id == SPELL_FREE_RAGECLAW)
        {
            m_creature->RemoveAurasDueToSpell(SPELL_LEFT_CHAIN);

            m_creature->RemoveAurasDueToSpell(SPELL_RIGHT_CHAIN);

            m_creature->RemoveAurasDueToSpell(SPELL_KNEEL);

            m_creature->setFaction(m_creature->GetCreatureInfo()->faction_H);

            DoCast(m_creature, SPELL_UNSHACKLED, true);
            DoSay(SAY_RAGECLAW, LANG_UNIVERSAL, NULL);
            m_creature->GetMotionMaster()->MoveRandom(10);

            DespawnTimer = 10000;
            Despawn = true;
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if (m_creature->getVictim())
        {
            DoMeleeAttackIfReady();
            return;
        }

        if (!Despawn)
            return;
        
        if (DespawnTimer < diff)
            m_creature->setDeathState(JUST_DIED);
        else DespawnTimer-=diff;
   }
};

CreatureAI* GetAI_npc_captured_rageclaw(Creature* pCreature)
{
    return new npc_captured_rageclawAI (pCreature);
}

void AddSC_zuldrak()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="npc_drakuru_shackles";
    newscript->GetAI = &GetAI_npc_drakuru_shackles;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_captured_rageclaw";
    newscript->GetAI = &GetAI_npc_captured_rageclaw;
    newscript->RegisterSelf();
}
