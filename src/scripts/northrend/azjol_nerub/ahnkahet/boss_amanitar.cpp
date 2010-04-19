/*
* Copyright (C) 2009 - 2010 TrinityCore <http://www.trinitycore.org/>
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

/*
 * Comment:  Find correct mushrooms spell to make them visible - buffs of the mushrooms not ever applied to the users...
 */

#include "ScriptedPch.h"
#include "ahnkahet.h"

enum Spells
{
    SPELL_BASH                                    = 57094, // Victim
    SPELL_ENTANGLING_ROOTS                        = 57095, // Random Victim 100Y
    SPELL_MINI                                    = 57055, // Self
    SPELL_VENOM_BOLT_VOLLEY                       = 57088, // Random Victim 100Y
    SPELL_HEALTHY_MUSHROOM_POTENT_FUNGUS          = 56648, // Killer 3Y
    SPELL_POISONOUS_MUSHROOM_POISON_CLOUD         = 57061, // Self - Duration 8 Sec
    SPELL_POISONOUS_MUSHROOM_VISUAL_AREA          = 61566, // Self
    SPELL_POISONOUS_MUSHROOM_VISUAL_AURA          = 56741, // Self
    SPELL_PUTRID_MUSHROOM                         = 31690, // To make the mushrooms visible
};

enum Creatures
{
    NPC_HEALTHY_MUSHROOM                          = 30391,
    NPC_POISONOUS_MUSHROOM                        = 30435
};

struct boss_amanitarAI : public ScriptedAI
{
    boss_amanitarAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
        bFirstTime = true;
    }

    ScriptedInstance* pInstance;

    uint32 uiRootTimer;
    uint32 uiBashTimer;
    uint32 uiBoltTimer;
    uint32 uiSpawnTimer;

    bool bFirstTime;

    void Reset()
    {
        uiRootTimer = urand(5*IN_MILISECONDS,9*IN_MILISECONDS);
        uiBashTimer = urand(10*IN_MILISECONDS,14*IN_MILISECONDS);
        uiBoltTimer = urand(15*IN_MILISECONDS,30*IN_MILISECONDS);
        uiSpawnTimer = 0;

        me->SetMeleeDamageSchool(SPELL_SCHOOL_NATURE);
        me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_NATURE, true);

        if (pInstance)
        {
            pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_MINI);
            if (!bFirstTime)
                pInstance->SetData(DATA_AMANITAR_EVENT, FAIL);
            else
                bFirstTime = false;
        }
    }

    void JustDied(Unit * /*Killer*/)
    {
        if (pInstance)
        {
            pInstance->SetData(DATA_AMANITAR_EVENT, DONE);
            pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_MINI);
        }
    }

    void EnterCombat(Unit * /*who*/)
    {
        if (pInstance)
            pInstance->SetData(DATA_AMANITAR_EVENT, IN_PROGRESS);

        DoCast(me, SPELL_MINI, false);
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
                me->GetRandomNearPosition(pos, float(urand(5,80)));
                me->SummonCreature(NPC_POISONOUS_MUSHROOM, pos, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 30*IN_MILISECONDS);
                me->GetRandomNearPosition(pos, float(urand(5,80)));
                me->SummonCreature(NPC_HEALTHY_MUSHROOM, pos, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 30*IN_MILISECONDS);
            }
        }
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        if (uiSpawnTimer <= diff)
        {
            SpawnAdds();
            uiSpawnTimer = urand(35*IN_MILISECONDS,40*IN_MILISECONDS);
        } else uiSpawnTimer -= diff;

        if (uiRootTimer <= diff)
        {
            if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                DoCast(pTarget, SPELL_ENTANGLING_ROOTS);
            uiRootTimer = urand(15*IN_MILISECONDS,30*IN_MILISECONDS);
        } else uiRootTimer -= diff;

        if (uiBashTimer <= diff)
        {
            DoCastVictim(SPELL_BASH);
            uiBashTimer = urand(15*IN_MILISECONDS,30*IN_MILISECONDS);
        } else uiBashTimer -= diff;

        if (uiBoltTimer <= diff)
        {
            if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                DoCast(pTarget, SPELL_VENOM_BOLT_VOLLEY);
            uiBoltTimer = urand(15*IN_MILISECONDS,30*IN_MILISECONDS);
        } else uiBoltTimer -= diff;

        DoMeleeAttackIfReady();
    }
};

struct mob_amanitar_mushroomsAI : public Scripted_NoMovementAI
{
    mob_amanitar_mushroomsAI(Creature* c) : Scripted_NoMovementAI(c) {}

    uint32 uiAuraTimer;
    uint32 uiDeathTimer;

    void Reset()
    {
        DoCast(me, SPELL_PUTRID_MUSHROOM, true); // Hack, to make the mushrooms visible, can't find orig. spell...

        if (me->GetEntry() == NPC_POISONOUS_MUSHROOM)
            DoCast(me, SPELL_POISONOUS_MUSHROOM_VISUAL_AURA, true);

        uiAuraTimer = 0;
        uiDeathTimer = 30*IN_MILISECONDS;
    }

    void JustDied(Unit *killer)
    {
        if (!killer)
            return;

        if (me->GetEntry() == NPC_HEALTHY_MUSHROOM && killer->GetTypeId() == TYPEID_PLAYER)
        {
            me->InterruptNonMeleeSpells(false);
            DoCast(killer, SPELL_HEALTHY_MUSHROOM_POTENT_FUNGUS, false);
        }
    }

    void EnterCombat(Unit * /*who*/) {}
    void AttackStart(Unit * /*victim*/) {}

    void UpdateAI(const uint32 diff)
    {
        if (me->GetEntry() == NPC_POISONOUS_MUSHROOM)
        {
            if (uiAuraTimer <= diff)
            {
                DoCast(me, SPELL_POISONOUS_MUSHROOM_VISUAL_AREA, true);
                DoCast(me, SPELL_POISONOUS_MUSHROOM_POISON_CLOUD, false);
                uiAuraTimer = 7*IN_MILISECONDS;
            } else uiAuraTimer -= diff;
        }
        if (uiDeathTimer <= diff)
            me->DisappearAndDie();
        else uiDeathTimer -= diff;
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
