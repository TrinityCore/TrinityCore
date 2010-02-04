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

/* Script Data Start
SDName: boss_amanitar
SDAuthor: WarHead
SD%Complete: 80%
SDComment:  Find correct mushrooms spell to make them visible - buffs of the mushrooms not ever applied to the users...
SDCategory: Ahn'kahet
Script Data End */

#include "ScriptedPch.h"
#include "ahnkahet.h"

enum Spells
{
    SPELL_BASH                             = 57094, // Victim
    SPELL_ENTANGLING_ROOTS                 = 57095, // Random Victim 100Y
    SPELL_MINI                             = 57055, // Self
    SPELL_VENOM_BOLT_VOLLEY                = 57088, // Random Victim 100Y
    
    HEALTHY_MUSHROOM_SPELL_POTENT_FUNGUS    = 56648, // Killer 3Y
    
    POISONOUS_MUSHROOM_SPELL_POISON_CLOUD   = 57061, // Self - Duration 8 Sec
    POISONOUS_MUSHROOM_SPELL_VISUAL_AREA    = 61566, // Self
    POISONOUS_MUSHROOM_SPELL_VISUAL_AURA    = 56741, // Self
    
    SPELL_PUTRID_MUSHROOM                   = 31690, // To make the mushrooms visible
};

enum Creatures
{
#define NPC_HEALTHY_MUSHROOM     30391
#define NPC_POISONOUS_MUSHROOM   30435
};

struct boss_amanitarAI : public ScriptedAI
{
    boss_amanitarAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
        FirstTime = true;
    }

    ScriptedInstance* pInstance;

    uint32 roottimer,
        bashtimer,
        bolttimer,
        spawntimer;

    bool FirstTime;

    void Reset()
    {
        roottimer = urand(5000,9000);
        bashtimer = urand(10000,14000);
        bolttimer = urand(15000,30000);
        spawntimer = 0;

        m_creature->SetMeleeDamageSchool(SPELL_SCHOOL_NATURE);
        m_creature->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_NATURE, true);

        if (pInstance)
        {
            pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_MINI);
            if (!FirstTime)
            {
                pInstance->SetData(DATA_AMANITAR_EVENT, FAIL);
            }
            else FirstTime = false;
        }
    }

    void JustDied(Unit *Killer)
    {
        if (pInstance)
        {
            pInstance->SetData(DATA_AMANITAR_EVENT, DONE);
            pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_MINI);
        }
    }

    void EnterCombat(Unit *who)
    {
        if (pInstance)
            pInstance->SetData(DATA_AMANITAR_EVENT, IN_PROGRESS);

        DoCast(m_creature, SPELL_MINI, false);
    }

    void SpawnAdds()
    {
        for (uint8 i = 0; i < 30; ++i)
        {
            Unit* victim = SelectUnit(SELECT_TARGET_RANDOM, 0);

            if (victim)
            {
                Position pos;
                victim->GetPosition(&pos);
                m_creature->GetRandomNearPosition(pos, float(urand(5,80)));
                m_creature->SummonCreature(NPC_POISONOUS_MUSHROOM, pos, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 30000);
                m_creature->GetRandomNearPosition(pos, float(urand(5,80)));
                m_creature->SummonCreature(NPC_HEALTHY_MUSHROOM, pos, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 30000);
            }
        }
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        if (spawntimer <= diff)
        {
            SpawnAdds();
            spawntimer = urand(35000,40000);
        } else spawntimer -= diff;

        if (roottimer <= diff)
        {
            if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                DoCast(pTarget, SPELL_ENTANGLING_ROOTS);
            roottimer = urand(15000,30000);
        }

        if (bashtimer <= diff)
        {
            DoCastVictim(SPELL_BASH);
            bashtimer = urand(15000,30000);
        } else bashtimer -= diff;

        if (bolttimer <= diff)
        {
            if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                DoCast(pTarget, SPELL_VENOM_BOLT_VOLLEY);
            bolttimer = urand(15000,30000);
        } else bolttimer -= diff;

        DoMeleeAttackIfReady();
    }
};

struct mob_amanitar_mushroomsAI : public Scripted_NoMovementAI
{
    mob_amanitar_mushroomsAI(Creature* c) : Scripted_NoMovementAI(c)
    {
        c->SetUInt32Value(UNIT_FIELD_DISPLAYID, 26981); // Unsichtbar...
    }

    uint32 auratimer,
        deathtimer; // Without not all will despawn after 30000! :-(

    void Reset()
    {
        DoCast(m_creature, SPELL_PUTRID_MUSHROOM, true); // Hack, to make the mushrooms visible, can't find orig. spell...

        if (m_creature->GetEntry() == NPC_POISONOUS_MUSHROOM)
            DoCast(m_creature, POISONOUS_MUSHROOM_SPELL_VISUAL_AURA, true);

        auratimer = 0;
        deathtimer = 30000;
    }

    void JustDied(Unit *killer)
    {
        if (!killer)
            return;

        if (m_creature->GetEntry() == NPC_HEALTHY_MUSHROOM && killer->GetTypeId() == TYPEID_PLAYER)
        {
            m_creature->InterruptNonMeleeSpells(false);
            DoCast(killer, HEALTHY_MUSHROOM_SPELL_POTENT_FUNGUS, false);
        }
    }

    void EnterCombat(Unit *who) {}
    void AttackStart(Unit *victim) {}

    void UpdateAI(const uint32 diff)
    {
        if (m_creature->GetEntry() == NPC_POISONOUS_MUSHROOM)
        {
            if (auratimer <= diff)
            {
                DoCast(m_creature, POISONOUS_MUSHROOM_SPELL_VISUAL_AREA, true);
                DoCast(m_creature, POISONOUS_MUSHROOM_SPELL_POISON_CLOUD, false);
                auratimer = 7000;
            } else auratimer -= diff;
        }
        if (deathtimer <= diff)
        {
            m_creature->DisappearAndDie();
        } else deathtimer -= diff;
    }
};

CreatureAI* GetAI_boss_amanitar(Creature* pCreature)
{
    return new boss_amanitarAI (pCreature);
}

CreatureAI* GetAI_mob_amanitar_mushrooms(Creature *pCreature)
{
    return new mob_amanitar_mushroomsAI (pCreature);
}

void AddSC_boss_amanitar()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_amanitar";
    newscript->GetAI = &GetAI_boss_amanitar;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_amanitar_mushrooms";
    newscript->GetAI = &GetAI_mob_amanitar_mushrooms;
    newscript->RegisterSelf();
}
