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

/*** SQL START ***
update creature_template set scriptname = 'boss_amanitar' where entry = '30258';
UPDATE `creature_template` SET `ScriptName`='mob_amanitar_mushrooms' WHERE `entry` IN ('30435','30391');
*** SQL END ***/

#include "precompiled.h"
#include "def_ahnkahet.h"

#define SPELL_BASH              57094 // Victim
#define SPELL_ENTANGLING_ROOTS  57095 // Random Victim 100Y
#define SPELL_MINI              57055 // Self
#define SPELL_VENOM_BOLT_VOLLEY 57088 // Random Victim 100Y

#define HEALTHY_MUSHROOM_SPELL_POTENT_FUNGUS    56648 // Killer 3Y

#define POISONOUS_MUSHROOM_SPELL_POISON_CLOUD   57061 // Self - Duration 8 Sec
#define POISONOUS_MUSHROOM_SPELL_VISUAL_AREA    61566 // Self
#define POISONOUS_MUSHROOM_SPELL_VISUAL_AURA    56741 // Self

#define SPELL_PUTRID_MUSHROOM   31690 // To make the mushrooms visible

#define HealthyMushroom     30391
#define PoisonousMushroom   30435

struct MANGOS_DLL_DECL boss_amanitarAI : public ScriptedAI
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

    void Reset()
    {
        roottimer = urand(5000,9000);
        bashtimer = urand(10000,14000);
        bolttimer = urand(15000,30000);
        spawntimer = 0;

        m_creature->SetMeleeDamageSchool(SPELL_SCHOOL_NATURE);
        m_creature->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_NATURE, true);

        if (pInstance && !FirstTime) pInstance->SetData(DATA_AMANITAR, FAIL);

        FirstTime = false;

        if (pInstance) pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_MINI);
    }

    void JustDied(Unit *Killer)
    {
        if (pInstance)
        {
            pInstance->SetData(DATA_AMANITAR, DONE);
            pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_MINI);
        }
    }

    void EnterCombat(Unit *who)
    {
        m_creature->SetInCombatWithZone();

        if (pInstance) pInstance->SetData(DATA_AMANITAR, IN_PROGRESS);

        m_creature->CastSpell(m_creature, SPELL_MINI, false);
    }

    void SpawnAdds()
    {
        uint32 DSpwTime = 30000;
        float x = 0.0f, y = 0.0f, z = 0.0f;
        TempSummonType DSpwType = TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN;

        for (uint8 i = 0; i < 30; ++i)
        {
            Unit* victim = SelectUnit(SELECT_TARGET_RANDOM, 0);

            if (victim)
            {
                Position pos;
                m_creature->GetRandomNearPosition(pos, float(urand(5,80)));
                m_creature->SummonCreature(PoisonousMushroom, pos, DSpwType, DSpwTime);
                m_creature->GetRandomNearPosition(pos, float(urand(5,80)));
                m_creature->SummonCreature(HealthyMushroom, pos, DSpwType, DSpwTime);
            }
        }
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim()) return;

        if (spawntimer < diff)
        {
            SpawnAdds();
            spawntimer = urand(35000,40000);
        } else spawntimer -= diff;

        if (roottimer < diff)
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                m_creature->CastSpell(target, SPELL_ENTANGLING_ROOTS, false);
            roottimer = urand(15000,30000);
        }

        if (bashtimer < diff)
        {
            m_creature->CastSpell(m_creature->getVictim(), SPELL_BASH, false);
            bashtimer = urand(15000,30000);
        } else bashtimer -= diff;

        if (bolttimer < diff)
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                m_creature->CastSpell(target, SPELL_VENOM_BOLT_VOLLEY, false);
            bolttimer = urand(15000,30000);
        } else bolttimer -= diff;

        DoMeleeAttackIfReady();
    }
};

struct MANGOS_DLL_DECL mob_amanitar_mushroomsAI : public Scripted_NoMovementAI
{
    mob_amanitar_mushroomsAI(Creature* c) : Scripted_NoMovementAI(c)
    {
        c->SetUInt32Value(UNIT_FIELD_DISPLAYID, 26981); // Unsichtbar...
    }

    uint32 auratimer,
        deathtimer; // Without not all will despawn after 30000! :-(

    void Reset()
    {
        m_creature->CastSpell(m_creature, SPELL_PUTRID_MUSHROOM, true); // Hack, to make the mushrooms visible, can't find orig. spell...

        if (m_creature->GetEntry() == PoisonousMushroom) m_creature->CastSpell(m_creature, POISONOUS_MUSHROOM_SPELL_VISUAL_AURA, true);

        auratimer = 0;
        deathtimer = 30000;
    }

    void DamageTaken(Unit *killer, uint32 &damage)
    {
        if (!killer || !damage) return;

        if (m_creature->GetEntry() == HealthyMushroom && damage >= m_creature->GetHealth())
        {
            if (killer->GetTypeId() == TYPEID_PLAYER && m_creature->GetDistance(killer) <= 3.0f)
            {
                m_creature->InterruptNonMeleeSpells(false);
                m_creature->CastSpell(killer, HEALTHY_MUSHROOM_SPELL_POTENT_FUNGUS, false);
            }
        }
    }

    void EnterCombat(Unit *who) { }
    void AttackStart(Unit *victim) { }

    void UpdateAI(const uint32 diff)
    {
        if (m_creature->GetEntry() == PoisonousMushroom)
        {
            if (auratimer < diff)
            {
                m_creature->CastSpell(m_creature, POISONOUS_MUSHROOM_SPELL_VISUAL_AREA, true);
                m_creature->CastSpell(m_creature, POISONOUS_MUSHROOM_SPELL_POISON_CLOUD, false);
                auratimer = 7000;
            } else auratimer -= diff;
        }
        if (deathtimer < diff)
        {
            m_creature->setDeathState(JUST_DIED);
            m_creature->RemoveCorpse();
            deathtimer = 30000;
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
    newscript->Name="boss_amanitar";
    newscript->GetAI = &GetAI_boss_amanitar;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_amanitar_mushrooms";
    newscript->GetAI = &GetAI_mob_amanitar_mushrooms;
    newscript->RegisterSelf();
}
