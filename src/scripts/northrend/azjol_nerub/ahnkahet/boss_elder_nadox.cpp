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

#include "ScriptedPch.h"
#include "ahnkahet.h"

bool DeadAhnkaharGuardian; // needed for achievement: Respect Your Elders(2038)

enum Achievements
{
    ACHIEV_RESPECT_YOUR_ELDERS                    = 2038
};

//not in db
enum Yells
{
    SAY_AGGRO                                     = -1619014,
    SAY_SLAY_1                                    = -1619015,
    SAY_SLAY_2                                    = -1619016,
    SAY_SLAY_3                                    = -1619017,
    SAY_DEATH                                     = -1619018,
    SAY_EGG_SAC_1                                 = -1619019,
    SAY_EGG_SAC_2                                 = -1619020
};

enum Spells
{
    SPELL_BROOD_PLAGUE                            = 56130,
    H_SPELL_BROOD_PLAGUE                          = 59467,
    H_SPELL_BROOD_RAGE                            = 59465,
    SPELL_ENRAGE                                  = 26662 // Enraged if too far away from home
};

enum Creatures
{
    MOB_AHNKAHAR_SWARMER                          = 30178,
    MOB_AHNKAHAR_GUARDIAN_ENTRY                   = 30176
};

enum CreatureSpells
{
    SPELL_SUMMON_SWARMERS                         = 56119, //2x 30178  -- 2x every 10secs
    SPELL_SUMMON_SWARM_GUARD                      = 56120, //1x 30176  -- every 25secs
    SPELL_GUARDIAN_AURA                           = 56151
};

#define EMOTE_HATCHES                       "An Ahn'kahar Guardian hatches!"

struct boss_elder_nadoxAI : public ScriptedAI
{
    boss_elder_nadoxAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    uint32 plague_Timer;
    uint32 rage_Timer;

    uint32 swarmer_spawn_Timer;
    uint32 guard_spawn_Timer;
    uint32 enrage_Timer;
    
    bool GuardSpawned;

    ScriptedInstance *pInstance;

    void Reset()
    {
        plague_Timer = 13000;
        rage_Timer = 20000;

        swarmer_spawn_Timer = 10000;
        guard_spawn_Timer = 25000;

        enrage_Timer = 5000;

        DeadAhnkaharGuardian = false;
        GuardSpawned = false;

        if (pInstance)
            pInstance->SetData(DATA_ELDER_NADOX_EVENT, NOT_STARTED);
    }

    void EnterCombat(Unit *who)
    {
        DoScriptText(SAY_DEATH,m_creature);

        if (pInstance)
            pInstance->SetData(DATA_ELDER_NADOX_EVENT, IN_PROGRESS);
    }

    void KilledUnit(Unit *victim)
    {
        if (victim == m_creature)
            return;
        DoScriptText(RAND(SAY_SLAY_1,SAY_SLAY_2,SAY_SLAY_3), m_creature);
    }

    void JustDied(Unit* killer)
    {
        DoScriptText(SAY_SLAY_3,m_creature); //SAY_SLAY_3 on death?

        if (pInstance)
        {
            pInstance->SetData(DATA_ELDER_NADOX_EVENT, DONE);
            if (IsHeroic() && !DeadAhnkaharGuardian)
                pInstance->DoCompleteAchievement(ACHIEV_RESPECT_YOUR_ELDERS);
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        if (plague_Timer <= diff)
        {
            DoCast(m_creature->getVictim(), DUNGEON_MODE(SPELL_BROOD_PLAGUE, H_SPELL_BROOD_PLAGUE));
            plague_Timer = 15000;
        } else plague_Timer -= diff;

        if (IsHeroic())
            if (rage_Timer <= diff)
            {
                Unit* Swarmer = m_creature->FindNearestCreature(MOB_AHNKAHAR_SWARMER, 35);

                if (Swarmer)
                {
                    DoCast(Swarmer, H_SPELL_BROOD_RAGE, true);
                    rage_Timer = 15000;
                }
            } else rage_Timer -= diff;

        if (swarmer_spawn_Timer <= diff)
        {
            DoCast(m_creature, SPELL_SUMMON_SWARMERS, true);
            DoCast(m_creature, SPELL_SUMMON_SWARMERS);
            if (urand(1,3) == 3) // 33% chance of dialog
                DoScriptText(RAND(SAY_EGG_SAC_1,SAY_EGG_SAC_2), m_creature);

            swarmer_spawn_Timer = 10000;
        } else swarmer_spawn_Timer -= diff;

        if (!GuardSpawned && guard_spawn_Timer <= diff)
        {
            m_creature->MonsterTextEmote(EMOTE_HATCHES,m_creature->GetGUID(),true);
            DoCast(m_creature, SPELL_SUMMON_SWARM_GUARD);
            GuardSpawned = true; 
        } else guard_spawn_Timer -= diff;

        if (enrage_Timer <= diff)
        {
            if (m_creature->HasAura(SPELL_ENRAGE,0))
                return;

            float x, y, z, o;
            m_creature->GetHomePosition(x, y, z, o);
            if (z < 24)
                if (!m_creature->IsNonMeleeSpellCasted(false))
                    DoCast(m_creature, SPELL_ENRAGE, true);

            enrage_Timer = 5000;
        } else enrage_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_elder_nadox(Creature* pCreature)
{
    return new boss_elder_nadoxAI(pCreature);
}

#define SPELL_SPRINT            56354

struct mob_ahnkahar_nerubianAI : public ScriptedAI
{
    mob_ahnkahar_nerubianAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    ScriptedInstance *pInstance;
    uint32 sprint_Timer;

    void Reset()
    {
        if (m_creature->GetEntry() == 30176) //magic numbers are bad!
            DoCast(m_creature, SPELL_GUARDIAN_AURA, true);
        sprint_Timer = 10000;
    }

    void JustDied(Unit *killer)
    {
        if (m_creature->GetEntry() == MOB_AHNKAHAR_GUARDIAN_ENTRY)
            DeadAhnkaharGuardian = true;
    }

    void EnterCombat(Unit *who){}

    void UpdateAI(const uint32 diff)
    {
        if (m_creature->GetEntry() == 30176) //magic numbers are bad!
            m_creature->RemoveAurasDueToSpell(SPELL_GUARDIAN_AURA);

        if (pInstance)
        {
            if (pInstance->GetData(DATA_ELDER_NADOX_EVENT) != IN_PROGRESS)
            {
                m_creature->DisappearAndDie();
            }
        }

        if (!UpdateVictim())
            return;

        if (sprint_Timer <= diff)
        {
            DoCast(m_creature, SPELL_SPRINT);
            sprint_Timer = 25000;
        } else sprint_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

struct mob_nadox_eggsAI : public Scripted_NoMovementAI
{
    mob_nadox_eggsAI(Creature* c) : Scripted_NoMovementAI(c)
    {
        c->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
        c->UpdateAllStats();
    }
    void Reset() {}
    void EnterCombat(Unit* who) {}
    void AttackStart(Unit* victim) {}
    void MoveInLineOfSight(Unit* who) {}
    void UpdateAI(const uint32 diff) {}
};

CreatureAI* GetAI_mob_ahnkahar_nerubian(Creature* pCreature)
{
    return new mob_ahnkahar_nerubianAI(pCreature);
}

CreatureAI* GetAI_mob_nadox_eggs(Creature* _Creature)
{
    return new mob_nadox_eggsAI(_Creature);
}

void AddSC_boss_elder_nadox()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_elder_nadox";
    newscript->GetAI = &GetAI_boss_elder_nadox;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_ahnkahar_nerubian";
    newscript->GetAI = &GetAI_mob_ahnkahar_nerubian;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_nadox_eggs";
    newscript->GetAI = &GetAI_mob_nadox_eggs;
    newscript->RegisterSelf();
}
