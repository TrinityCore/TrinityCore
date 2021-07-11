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
SDName: Boss_Gluth
SD%Complete: 
SDComment:
SDCategory: Naxxramas
EndScriptData */

#include "scriptPCH.h"
#include "naxxramas.h"

static float const aZombieSummonLoc[3][3] =
{
    { 3267.9f, -3172.1f, 297.42f },
    { 3253.2f, -3132.3f, 297.42f },
    { 3308.3f, -3185.8f, 297.42f },
};

enum GluthData
{
    EMOTE_FRENZY            = 1191,

    SPELL_DOUBLE_ATTACK     = 19818, // Added on reset in cmangos, not sure why

    SPELL_MORTALWOUND       = 25646,
    SPELL_DECIMATE          = 28374,
    SPELL_DECIMATE_OTHER    = 28375,
    SPELL_FRENZY            = 28371,
    SPELL_BERSERK           = 26662,
    SPELL_TERRIFYING_ROAR   = 29685,

    //SPELL_ZOMBIE_CHOW_SEARCH = 28235, // triggers 28236 every 3 sec, manually implemented instead
    //SPELL_CALL_ALL_ZOMBIE    = 29681, // triggers 29682 every 3 sec, manually implemented instead

    NPC_ZOMBIE_CHOW         = 16360,
    SPELL_INFECTED_WOUND    = 29307
};

enum eGLuthEvents
{
    EVENT_MORTAL_WOUND = 1,
    EVENT_DECIMATE,
    EVENT_FRENZY,
    EVENT_SUMMON,
    EVENT_BERSERK,
    EVENT_TERRIFYING_ROAR,
    EVENT_ZOMBIE_SEARCH,
    EVENT_EVADE_CHECK
};

static constexpr uint32 MORTAL_WOUND_CD  = 10000;   // verified by: https://www.youtube.com/watch?v=RAPiZgo-pNA
static constexpr uint32 DECIMATE_CD      = 105000;  // todo: Might be +- 5 seconds
static constexpr uint32 FRENZY_CD        = 10000;   // verified by: https://www.youtube.com/watch?v=RAPiZgo-pNA
static constexpr uint32 SUMMON_CD        = 6000;    // verified by dbc spell 28216
static constexpr uint32 BERSERK_CD       = 330000;  // todo: verify (15 sec after third decimate)
static constexpr uint32 FEAR_CD          = 20000;   // verified by: https://www.youtube.com/watch?v=RAPiZgo-pNA
static constexpr uint32 ZOMBIE_SEARCH_CD = 3000;    // dbc confirms this one

struct boss_gluthAI : public ScriptedAI
{
    boss_gluthAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (instance_naxxramas*)pCreature->GetInstanceData();
        Reset();
        five_percent = uint32(m_creature->GetMaxHealth() * 0.05f);
    }

    instance_naxxramas* m_pInstance;
    EventMap m_events;

    uint32 five_percent;
    
    void Reset() override
    {
        m_events.Reset();

        DespawnAllZombiess();
    }

    void DespawnAllZombiess()
    {
        std::list<Creature*> zombies;
        GetCreatureListWithEntryInGrid(zombies, m_creature, NPC_ZOMBIE_CHOW, 200.0f);
        for (Creature* c : zombies)
            c->DeleteLater();
    }

    void JustDied(Unit* pKiller) override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_GLUTH, DONE);
        DespawnAllZombiess();
    }

    void MoveInLineOfSight(Unit* pWho) override
    {
        // He should aggro just at the edge of the sewer pipe players jump from 
        if (pWho->GetTypeId() == TYPEID_PLAYER 
            && !m_creature->IsInCombat() 
            && m_creature->IsWithinDistInMap(pWho, 49.0f) 
            && !pWho->HasAuraType(SPELL_AURA_FEIGN_DEATH))
        {
            AttackStart(pWho);
        }
        ScriptedAI::MoveInLineOfSight(pWho);
    }

    void Aggro(Unit* pWho) override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_GLUTH, IN_PROGRESS);
        
        m_events.ScheduleEvent(EVENT_MORTAL_WOUND,    MORTAL_WOUND_CD);
        m_events.ScheduleEvent(EVENT_DECIMATE,        DECIMATE_CD);
        m_events.ScheduleEvent(EVENT_FRENZY,          FRENZY_CD);
        m_events.ScheduleEvent(EVENT_SUMMON,          SUMMON_CD);
        m_events.ScheduleEvent(EVENT_BERSERK,         BERSERK_CD);
        m_events.ScheduleEvent(EVENT_TERRIFYING_ROAR, FEAR_CD);
        m_events.ScheduleEvent(EVENT_ZOMBIE_SEARCH,   ZOMBIE_SEARCH_CD);
        m_events.ScheduleEvent(EVENT_EVADE_CHECK,     Seconds(5));
    }

    void JustReachedHome() override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_GLUTH, FAIL);
    }

    void SpellHit(Unit*, SpellEntry const* pSpell) override
    {
        // only want to do these calculations inside naxx
        if (m_pInstance->GetMap()->GetId() != 533)
            return;

        if (pSpell->Id == SPELL_DECIMATE)
        {
            Map::PlayerList const& pList = m_pInstance->GetMap()->GetPlayers();
            for (const auto& it : pList)
            {
                Player* pPlayer = it.getSource();
                if (!pPlayer) continue;
                if (pPlayer->IsDead()) continue;
                DoCastSpellIfCan(pPlayer, SPELL_DECIMATE_OTHER, CF_TRIGGERED);
            }
        }
    }

    void UpdateAI(uint32 const uiDiff)  override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        m_events.Update(uiDiff);
        while (auto l_EventId = m_events.ExecuteEvent())
        {
            switch (l_EventId)
            {
                case EVENT_MORTAL_WOUND:
                {
                    // mortal wound current target every
                    if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_MORTALWOUND) == CAST_OK)
                        m_events.Repeat(MORTAL_WOUND_CD);
                    else
                        m_events.Repeat(100);
                    break;
                }
                case EVENT_DECIMATE:
                {
                    // decimate every DECIMATE_CD ms
                    // all the decimate logic is handled in SpellHit, so we dont put any players on
                    // 5% hp until we know the boss has received his stun etc
                    if (DoCastSpellIfCan(m_creature, SPELL_DECIMATE) == CAST_OK)
                        m_events.Repeat(DECIMATE_CD);
                    else
                        m_events.Repeat(100);
                    break;
                }
                case EVENT_FRENZY:
                {
                    // Frenzy every FRENZY_CD ms
                    if (DoCastSpellIfCan(m_creature, SPELL_FRENZY) == CAST_OK)
                    {
                        m_events.Repeat(FRENZY_CD);
                        DoScriptText(EMOTE_FRENZY, m_creature);
                    }
                    else
                        m_events.Repeat(100);
                    break;
                }
                case EVENT_SUMMON:
                    // Summon an add every SUMMON_CD ms
                    SummonAdd();
                    m_events.Repeat(SUMMON_CD);
                    break;
                case EVENT_BERSERK:
                {
                    // berserk after BERSERK_CD ms
                    if (DoCastSpellIfCan(m_creature, SPELL_BERSERK) == CAST_OK)
                        m_events.Repeat(300000); // duration of berserk
                    else
                        m_events.Repeat(100);
                    break;
                }
                case EVENT_TERRIFYING_ROAR:
                {
                    // fear every FEAR_CD ms
                    if (DoCastSpellIfCan(m_creature, SPELL_TERRIFYING_ROAR) == CAST_OK)
                        m_events.Repeat(FEAR_CD);
                    else
                        m_events.Repeat(100);
                    break;
                }
                case EVENT_ZOMBIE_SEARCH:
                {
                    // every ZOMBIE_SEARCH_CD ms he checks if any zombies are close enough to eat
                    DoSearchZombieChow();
                    m_events.Repeat(ZOMBIE_SEARCH_CD);
                    break;
                }
                case EVENT_EVADE_CHECK:
                {
                    m_events.Repeat(Seconds(5));
                    float curZ = m_creature->GetPositionZ();
                    if (curZ < 293.0f && curZ > 300.0f) // avoid getting stuck in wall on pull
                    {
                        EnterEvadeMode();
                    }
                    else
                    {
                        if (m_creature->GetDistance2d(m_creature->GetHomePosition()) > 150.0f)
                        {
                            EnterEvadeMode();
                        }
                    }
                    break;
                }
            }
        }

        DoMeleeAttackIfReady();
    }

    // Spell 28236 could be used instead, but frankly this is more reliable and simple
    // the way the core is
    void DoSearchZombieChow()
    {
        std::list<Creature*> chowableZombies;
        GetCreatureListWithEntryInGrid(chowableZombies, m_creature, NPC_ZOMBIE_CHOW, 15.0f);
        if (chowableZombies.empty())
            return;

        for (const auto& chowableZombie : chowableZombies)
        {
            if (!chowableZombie->IsAlive())
                continue;

            // Using 2d distance, should do fine
            if (chowableZombie->GetDistance2d(m_creature) < 15.0f) // distance based on dbc for spellid 289236
            {
                m_creature->SetFacingToObject(chowableZombie);
                m_creature->DealDamage(chowableZombie, chowableZombie->GetHealth(), nullptr, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, nullptr, false);

                // heals gluth for 5%. SetHealth truncates to maxhealth internally
                m_creature->SetHealth(m_creature->GetHealth() + five_percent);
            }
        }
    }

    void SummonAdd()
    {
        int idx = urand(0, 2);
        float x = aZombieSummonLoc[idx][0] + frand(-7.0f, 7.0f);
        float y = aZombieSummonLoc[idx][1] + frand(-7.0f, 7.0f);
        float z = aZombieSummonLoc[idx][2];// +frand(-7.0f, 7.0f);

        //todo: don't know if we should summon 1, 2 or 3 zombies each time.
        if (Creature* pZombie = m_creature->SummonCreature(NPC_ZOMBIE_CHOW, x, y, z, 0.0f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 300000))
        {
            pZombie->SetInCombatWithZone();
            if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
                pZombie->AI()->AttackStart(pTarget);
        }
    }
};

struct mob_zombieChow : public ScriptedAI
{
    mob_zombieChow(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (instance_naxxramas*)pCreature->GetInstanceData();
        Reset();
    }

    instance_naxxramas* m_pInstance;
    bool isHitByDecimate;

    void Reset() override
    {
        isHitByDecimate = false;
        m_creature->CastSpell(m_creature, SPELL_INFECTED_WOUND, true);
    }

    bool ChaseGluth()
    {
        if (Creature* pGluth = m_pInstance->GetSingleCreatureFromStorage(NPC_GLUTH))
        {
            m_creature->GetMotionMaster()->Clear();
            m_creature->GetMotionMaster()->MoveFollow(pGluth, ATTACK_DISTANCE, 0.0f);
            m_creature->SetTargetGuid(0);
            return true;
        }
        return false;
    }

    void SpellHit(Unit* pWho, SpellEntry const* pSpell) override
    {
        ScriptedAI::SpellHit(pWho, pSpell);
        if (pWho->GetEntry() == NPC_GLUTH && pSpell->Id == SPELL_DECIMATE)
        {
            if (ChaseGluth())
            {
                DoCastSpellIfCan(m_creature, SPELL_DECIMATE_OTHER, CF_TRIGGERED);
                isHitByDecimate = true;
            }
        }
    }

    void AttackStart(Unit* pWho) override
    {
        if (isHitByDecimate)
            return;
        ScriptedAI::AttackStart(pWho);
    }

    void UpdateAI(uint32 const diff) override
    {
        if (isHitByDecimate)
        {
            if (m_creature->GetMotionMaster()->GetCurrentMovementGeneratorType() != CHASE_MOTION_TYPE)
            {
                ChaseGluth();
            }
            return;
        }

        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_gluth(Creature* pCreature)
{
    return new boss_gluthAI(pCreature);
}

CreatureAI* GetAI_mob_zombieChow(Creature* pCreature)
{
    return new mob_zombieChow(pCreature);
}

void AddSC_boss_gluth()
{
    Script* NewScript;
    NewScript = new Script;
    NewScript->Name = "boss_gluth";
    NewScript->GetAI = &GetAI_boss_gluth;
    NewScript->RegisterSelf();

    NewScript = new Script;
    NewScript->Name = "mob_zombie_chow";
    NewScript->GetAI = &GetAI_mob_zombieChow;
    NewScript->RegisterSelf();
}
