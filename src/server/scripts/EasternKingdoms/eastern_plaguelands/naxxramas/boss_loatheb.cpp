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

#include "scriptPCH.h"
#include "naxxramas.h"

enum LoathebData
{
    SPELL_CORRUPTED_MIND  = 29201, // this triggers the following spells on targets (based on class): 29185, 29194, 29196, 29198
    SPELL_POISON_AURA     = 29865,
    SPELL_INEVITABLE_DOOM = 29204,
    SPELL_REMOVE_CURSE    = 30281, // He periodically removes all curses on himself

    NPC_SPORE             = 16286
};

enum Events
{
    EVENT_SUMMON_SPORE = 1,
    EVENT_CORRUPTED_MIND,
    EVENT_POISON_AURA,
    EVENT_INEVITABLE_DOOM,
    EVENT_REMOVE_CURSE
};

// Can't really see much of a system in where the spores spawn.
// In guides it say "oposite side of where the majority of the raid stands".
// Unless this is a snapshot check by the boss on pull, which it dosent seem to be based on videos,
// it simply seems like one of 2 (potentially 4) location is chosed at random on pull, after that it's
// constantly spawning there throughout the fight.
// Presumably spell 29234 was used, it has a radius of 70yd. Can't figure out exactly how it would have been used though.
static constexpr float SporeLocs[2][3] = 
{
    {2951.0f, -4016.0f, 274.0f},
    {2870.0f, -3978.0f, 274.0f}
};

static constexpr uint8 MAX_STALKS_UP = 6;
struct EyeStalkInfo
{
    enum eState
    {
        COOLDOWN,
        UP
    };
    eState currentState;
    uint32 timer;
    ObjectGuid guid;
    uint8 myIndex;
};

struct mob_rottingMaggotAI : public ScriptedAI
{
    mob_rottingMaggotAI(Creature* pCreature, bool isDiseased) :
        ScriptedAI(pCreature),
        isDiseased(isDiseased)
    {
        m_creature->SetNoCallAssistance(true);
        Reset();
    }

    bool const isDiseased;
    WorldLocation aggroPossition;
    static constexpr uint32 SPELL_RETCHING_PLAGUE = 30079;

    void Reset() override { }

    void MoveInLineOfSight(Unit* pWho) override
    {
        // Custom, tiny aggro radius
        if (!m_creature->IsWithinDistInMap(pWho, 1.5f))
            return;

        if (m_creature->CanInitiateAttack() && pWho->IsTargetable(true, false) && m_creature->IsHostileTo(pWho))
        {
            if (pWho->IsInAccessablePlaceFor(m_creature) && m_creature->IsWithinLOSInMap(pWho))
            {
                m_creature->SetNoCallAssistance(true);

                if (!m_creature->GetVictim())
                    AttackStart(pWho);
                else if (m_creature->GetMap()->IsDungeon())
                {
                    pWho->SetInCombatWith(m_creature);
                    m_creature->AddThreat(pWho);
                }
            }
        }
    }

    void Aggro(Unit*) override
    {
        m_creature->SetNoCallAssistance(true);
        m_creature->GetPosition(aggroPossition);
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;
        if (isDiseased)
        {
            if (!m_creature->HasAura(SPELL_RETCHING_PLAGUE))
                m_creature->CastSpell(m_creature, SPELL_RETCHING_PLAGUE, true);
        }
        if (m_creature->GetDistance(aggroPossition) > 40.0f)
        {
            EnterEvadeMode();
        }
        else
        {
            DoMeleeAttackIfReady();
        }
    }
};

struct mob_eyeStalkAI : public ScriptedAI
{
    mob_eyeStalkAI(Creature* pCreature) :
        ScriptedAI(pCreature)
    {
        m_creature->SetNoCallAssistance(true);
        SetCombatMovement(false);
        timeSinceSpawn = 0;
        haveSubmerged = false;
        haveCastSubmerge = false;
    }

    uint32 timeSinceSpawn;
    bool haveSubmerged;
    bool haveCastSubmerge;
    static constexpr uint32 SPELL_MIND_FLAY = 29407;

    void Reset() override
    {
        m_creature->AddUnitState(UNIT_STAT_ROOT);
        m_creature->StopMoving();
        m_creature->SetRooted(true);
        m_creature->SetNoCallAssistance(true);
    }

    void MoveInLineOfSight(Unit* pWho) override
    {
        if (timeSinceSpawn < 3000)
            return;

        if (!m_creature->IsWithinDistInMap(pWho, 19.0f))
            return;

        if (m_creature->CanInitiateAttack() && pWho->IsTargetable(true, false) && m_creature->IsHostileTo(pWho))
        {
            if (pWho->IsInAccessablePlaceFor(m_creature) && m_creature->IsWithinLOSInMap(pWho))
            {
                m_creature->SetNoCallAssistance(true);
                if (!m_creature->GetVictim())
                    AttackStart(pWho);
                else if (m_creature->GetMap()->IsDungeon())
                {
                    pWho->SetInCombatWith(m_creature);
                    m_creature->AddThreat(pWho);
                }
            }
        }
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        m_creature->SetNoCallAssistance(true);
        timeSinceSpawn += std::min(uiDiff, std::numeric_limits<uint32>::max() - timeSinceSpawn);

        if (haveSubmerged)
        {
            if (!haveCastSubmerge)
            {
                haveCastSubmerge = true;
                m_creature->CastSpell(m_creature, 26234, false);
            }
            return;
        }

        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (!m_creature->IsNonMeleeSpellCasted())
        {
            if (m_creature->GetDistance(m_creature->GetVictim()) < 35.0f)
                DoCastSpellIfCan(m_creature->GetVictim(), SPELL_MIND_FLAY);
            else
                DoStopAttack();
        }

        DoMeleeAttackIfReady();
    }
};

struct boss_loathebAI : public ScriptedAI
{
    boss_loathebAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        int randLoc = urand(0, 1);
        for (int i = 0; i < 3; i++)
            SporeLoc[i] = SporeLocs[randLoc][i];

        m_pInstance = (instance_naxxramas*)pCreature->GetInstanceData();
        Reset();

        for (auto& eyeStalk : eyeStalks)
        {
            eyeStalk.currentState = EyeStalkInfo::COOLDOWN;
            eyeStalk.timer = urand(0, 10000);
            eyeStalk.guid = 0;
        }
        availableEyeLocs.clear();
        for (uint8 i = 0; i < max_stalks; i++)
            availableEyeLocs.push_back(i);
    }

    instance_naxxramas* m_pInstance;

    uint32 m_uiSummonTimer;

    EventMap events;
    uint32 numDooms;
    float SporeLoc[3];

    uint32 stalkSpawnCooldowns[20];
    std::vector<uint8> availableEyeLocs;
    EyeStalkInfo eyeStalks[MAX_STALKS_UP];

    void Reset() override
    {
        events.Reset();
        numDooms = 0;
    }

    void Aggro(Unit* pWho) override
    {
        numDooms = 0;
        events.ScheduleEvent(EVENT_SUMMON_SPORE,    Seconds(13));
        events.ScheduleEvent(EVENT_CORRUPTED_MIND,  Seconds(5));
        events.ScheduleEvent(EVENT_POISON_AURA,     Seconds(5));
        events.ScheduleEvent(EVENT_INEVITABLE_DOOM, Minutes(2));
        events.ScheduleEvent(EVENT_REMOVE_CURSE,    Seconds(5));
        if (m_pInstance)
            m_pInstance->SetData(TYPE_LOATHEB, IN_PROGRESS);
    }

    void JustDied(Unit* pKiller) override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_LOATHEB, DONE);
    }

    void JustReachedHome() override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_LOATHEB, FAIL);
    }

    /*
    10 stalks
    rand 10-20 up
    rand 10-20 down
    avg 15 up, avg 15 down
    avg 5 up at any given time
    when killed, down time becomes rand 10-20 + additional 10 seconds

    we want an eyestalk to submerge and a new one to pop up every 4sec on avg.
    That means we need all 20 to have an average cd of 80sec.
    We also want, when no stalks are killed, on average
    when an eyestalk comes off coldown, it forces the oldest alive eyestalk to die, then summons itself. The dead eye stalk gets a 60-90sec cooldown
    with 20 stalks, and an avg cd of 75sec, this means one eye stalk switches with another one every 3.75 seconds on avg.
    */

    void WhackAStalk(uint32 diff)
    {
        for (auto& eyeStalk : eyeStalks)
        {
            if (eyeStalk.timer >= diff)
                eyeStalk.timer -= diff;

            switch (eyeStalk.currentState)
            {
                case EyeStalkInfo::COOLDOWN:
                {
                    // Summoning a new eye
                    if (eyeStalk.timer < diff)
                    {
                        if (availableEyeLocs.empty())
                        {
                            sLog.outError("boss_loatheb.cpp - availableEyeLocs size 0, should not happen!");
                            return;
                        }
                        uint8 availableIndex = urand(0, availableEyeLocs.size() - 1);
                        uint8 newEyeIdx = availableEyeLocs[availableIndex];
                        availableEyeLocs.erase(availableEyeLocs.begin() + availableIndex);

                        eyeStalk.myIndex = newEyeIdx;
                        float const* pos = eyeStalkPossitions[newEyeIdx];

                        Creature* pStalk = m_creature->SummonCreature(NPC_EyeStalk, pos[0], pos[1], pos[2], pos[3], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                        if (!pStalk)
                        {
                            sLog.outError("Heigans WhackAStalk failed to summon eye stalk");
                            return;
                        }
                        eyeStalk.guid = pStalk->GetObjectGuid();
                        eyeStalk.currentState = EyeStalkInfo::UP;
                        eyeStalk.timer = urand(15000, 20000);
                    }
                    break;
                }
                case EyeStalkInfo::UP:
                    // Initiating unsummon
                    if (eyeStalk.timer < diff)
                    {
                        if (Creature* pCreature = m_pInstance->GetCreature(eyeStalk.guid))
                        {
                            // If the eye is currently channeling mind flay we wait with unsummoning it
                            if (!pCreature->IsNonMeleeSpellCasted())
                            {
                                mob_eyeStalkAI* ai = static_cast<mob_eyeStalkAI*>(pCreature->AI());
                                if (!ai->haveSubmerged)
                                {
                                    ai->haveSubmerged = true;
                                    if (TemporarySummon* ts = static_cast<TemporarySummon*>(pCreature))
                                        ts->UnSummon(1100);
                                }
                            }
                        }
                    }
                    break;
            }
        }
    }

    void SummonedCreatureDespawn(Creature* pCreature) override
    {
        if (pCreature->GetEntry() == NPC_EyeStalk)
        {
            for (auto& eyeStalk : eyeStalks)
            {
                if (eyeStalk.guid == pCreature->GetObjectGuid())
                {
                    // if currentState already is COOLDOWN it means it was killed
                    if (eyeStalk.currentState != EyeStalkInfo::COOLDOWN)
                    {
                        eyeStalk.currentState = EyeStalkInfo::COOLDOWN;
                        eyeStalk.timer = urand(1000, 5000);
                    }

                    eyeStalk.guid = 0;
                    availableEyeLocs.push_back(eyeStalk.myIndex);
                    break;
                }
            }
        }
    }

    void SummonedCreatureJustDied(Creature* pCreature) override
    {
        if (pCreature->GetEntry() == NPC_EyeStalk)
        {
            // was killed, so it receives an additional 10 seconds cooldown
            for (auto& eyeStalk : eyeStalks)
            {
                if (eyeStalk.guid == pCreature->GetObjectGuid())
                {
                    eyeStalk.currentState = EyeStalkInfo::COOLDOWN;
                    eyeStalk.timer = urand(1000, 5000) + 20000;
                    break;
                }
            }
        }
    }

    void SpellHit(Unit*, SpellEntry const* pSpell) override 
    {
        if (pSpell->Id == 15286) // vamperic embrace
        {
            DoCastSpellIfCan(m_creature, SPELL_REMOVE_CURSE);
        }
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        WhackAStalk(uiDiff);

        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;
        
        if (!m_pInstance->HandleEvadeOutOfHome(m_creature))
            return;

        events.Update(uiDiff);
        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SUMMON_SPORE:
                    if (Creature* pSpore = m_creature->SummonCreature(NPC_SPORE, SporeLoc[0], SporeLoc[1], SporeLoc[2], 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000))
                    {
                        if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
                            pSpore->AddThreat(pTarget);
                    }
                    events.Repeat(Seconds(13));
                    break;
                case EVENT_CORRUPTED_MIND:
                    // https://www.youtube.com/watch?v=a0z9qjLxD98&list=PLYsWP02PY54A3RkEJv_VaT-0ZhfMs5zxN&index=4
                    // shows it refreshing every ~10 sec
                    if (DoCastSpellIfCan(m_creature, SPELL_CORRUPTED_MIND) == CAST_OK)
                        events.Repeat(Seconds(10));
                    else
                        events.Repeat(Milliseconds(100));
                    break;
                case EVENT_POISON_AURA:
                    if (DoCastSpellIfCan(m_creature, SPELL_POISON_AURA) == CAST_OK)
                        events.Repeat(Seconds(12));
                    else
                        events.Repeat(Milliseconds(100));
                    break;
                case EVENT_INEVITABLE_DOOM:
                    if (DoCastSpellIfCan(m_creature, SPELL_INEVITABLE_DOOM) == CAST_OK)
                    {
                        ++numDooms;
                        // 2, 2:30, 3, 3:30, 4, 4:30, 5
                        // after 7 dooms, or 5 minutes into the fight,
                        // the doom timer becomes 15 instead of 30 seconds.
                        if (numDooms > 6)
                            events.Repeat(Seconds(15));
                        else
                            events.Repeat(Seconds(30));
                    }
                    else
                        events.Repeat(Milliseconds(100));
                    break;
                case EVENT_REMOVE_CURSE:
                    if (DoCastSpellIfCan(m_creature, SPELL_REMOVE_CURSE) == CAST_OK)
                        events.Repeat(Seconds(30));
                    else
                        events.Repeat(100);
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_loatheb(Creature* pCreature)
{
    return new boss_loathebAI(pCreature);
}

CreatureAI* GetAI_mob_rottingMaggot(Creature* pCreature)
{
    return new mob_rottingMaggotAI(pCreature, false);
}

CreatureAI* GetAI_mob_diseasedMaggot(Creature* pCreature)
{
    return new mob_rottingMaggotAI(pCreature, true);
}

CreatureAI* GetAI_mob_eyeStalk(Creature* pCreature)
{
    return new mob_eyeStalkAI(pCreature);
}

void AddSC_boss_loatheb()
{
    Script* NewScript;
    NewScript = new Script;
    NewScript->Name = "boss_loatheb";
    NewScript->GetAI = &GetAI_boss_loatheb;
    NewScript->RegisterSelf();

    NewScript = new Script;
    NewScript->Name = "mob_rotting_maggot";
    NewScript->GetAI = &GetAI_mob_rottingMaggot;
    NewScript->RegisterSelf();

    NewScript = new Script;
    NewScript->Name = "mob_diseased_maggot";
    NewScript->GetAI = &GetAI_mob_diseasedMaggot;
    NewScript->RegisterSelf();

    NewScript = new Script;
    NewScript->Name = "mob_eye_stalk";
    NewScript->GetAI = &GetAI_mob_eyeStalk;
    NewScript->RegisterSelf();
}
