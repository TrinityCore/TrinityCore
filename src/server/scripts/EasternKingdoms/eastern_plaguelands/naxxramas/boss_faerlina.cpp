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

enum FaerlinaData
{
    SAY_PULL                    = 12856, // slay them in the masters name
    SAY_ENRAGE1                 = 12857, // you cannot hide from me!
    SAY_ENRAGE2                 = 12858, // kneel before me, worm!
    SAY_ENRAGE3                 = 12859, // Run while you can!
    SAY_SLAY1                   = 12854, // You have failed!
    SAY_SLAY2                   = 12855, // Pathethic Wretch
    SAY_DEATH                   = 12853, // the master... will avenge me!

    SPELL_POSIONBOLT_VOLLEY     = 28796,
    SPELL_ENRAGE                = 28798, 

    SPELL_RAINOFFIRE            = 28794,    //Not sure if targeted AoEs work if casted directly upon a pPlayer

    SPELL_WIDOWS_EMBRACE        = 28732,    // Used by worshippers. ToDo: Spell does NOT add the attackspeed reduction, or is it just castspeed?

    MOB_FOLLOWER                = 16505,    // TODO: should aoe silence (small range, 8-10yd)
    MOB_WORSHIPPER              = 16506
};

/*
https://www.youtube.com/watch?v=pVjB7pCX3XM
https://www.youtube.com/watch?v=iTUc8xUeLgw
^ Around 7-10sec cooldown. Times she's not casting it for 30+sec she is silenced by worshipper sacrifice.
  Might be fixed 8sec cast, but slightly delayed sometimes due to rain of fire or other reasons.
*/

static uint32 POSIONBOLT_VOLLEY_CD() { return urand(10000, 12000); }
static uint32 const INITIAL_POISONBOLT_VOLLEY_CD = 8000;

/*
https://www.youtube.com/watch?v=pVjB7pCX3XM
https://www.youtube.com/watch?v=iTUc8xUeLgw
^ in both videos, happens somewhere between 8 and 20 seconds, though mostly between 8 and 12.
  possibly a rain we dont see when it happens after 20sec

  Initial cd seems to be around 16sec
*/

static uint32 RAINOFFIRE_CD() { return urand(8000, 12000); }
static uint32 const RAINOFFIRE_INITIAL_CD = 16000;

static float const ADD_DESPAWN_TIME = 20000;
static float const followerPos[2][4] =
{
    { 3359.75f, -3621.77f, 261.18f, 4.54f },
    {3346.29f, -3619.32f, 261.18f, 4.61f }
};

static float const worshipPos[4][4] =
{
    {3350.61f, -3619.74f, 261.18f, 4.65f},
    {3341.36f, -3619.35f, 261.18f, 4.68f},
    {3356.69f, -3621.17f, 261.18f, 4.38f},
    {3364.08f, -3622.85f, 261.18f, 4.35f}
};

struct boss_faerlinaAI : public ScriptedAI
{
    boss_faerlinaAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (instance_naxxramas*)pCreature->GetInstanceData();
        if (!m_pInstance)
            sLog.outError("boss_faerlinaAI::ctor failed to cast instanceData to instance_naxxramas");
        CheckRespawnAdds();
        Reset();
    }

    instance_naxxramas* m_pInstance;

    uint32 m_uiPoisonBoltVolleyTimer;
    uint32 m_uiRainOfFireTimer;
    uint32 m_uiEnrageTimer;

    ObjectGuid followers[2] = { 0,0 };
    ObjectGuid worshippers[4] = { 0,0,0,0 };

    void Reset() override
    {
        m_uiPoisonBoltVolleyTimer   = INITIAL_POISONBOLT_VOLLEY_CD;
        m_uiRainOfFireTimer         = RAINOFFIRE_INITIAL_CD;
        m_uiEnrageTimer             = 60000;
    }

    void SpellHit(Unit* pWho, SpellEntry const* pSpell) override 
    {
        /*
        note from wowhead:
        --
        Note: You must sacrifice the worshiper AFTER she enrages if you want to stop her for the full 60 seconds. 
        If you sacrifice the Worshiper before the enrage, it will merely delay the enrage for 30 seconds.
        -- 
        Above note makes it seem that if she is not already enraged when widows embrace hits, we should do enrageTimer+=30000;
        while if she is enraged we set the timer to 60000 again.
        */
        if (pSpell->Id == SPELL_WIDOWS_EMBRACE)
        {
            m_uiEnrageTimer = std::max(m_uiEnrageTimer, (uint32)30000);
            m_creature->RemoveAurasDueToSpell(SPELL_ENRAGE);
            pWho->Kill(pWho, nullptr);
        }
    }

    void CheckRespawnAdds()
    {
        if (m_pInstance && m_pInstance->GetData(TYPE_FAERLINA) == DONE)
            return;
        // 2 Followers.
        for (int i = 0; i < 2; i++) 
        {
            if (followers[i].IsEmpty()) 
            {
                if (Creature* c = m_creature->SummonCreature(MOB_FOLLOWER, followerPos[i][0], followerPos[i][1], followerPos[i][2], followerPos[i][3],
                    TEMPSUMMON_CORPSE_TIMED_DESPAWN, ADD_DESPAWN_TIME))
                {
                    followers[i] = c->GetObjectGuid();
                }
                else
                {
                    sLog.outError("boss_faerlinaAI::CheckRespawnAdds failed to spawn naxxramas follower");
                }
            }
        }

        // 4 Worshipers
        for (int i = 0; i < 4; i++)
        {
            if (worshippers[i].IsEmpty())
            {
                if (Creature* c = m_creature->SummonCreature(MOB_WORSHIPPER, worshipPos[i][0], worshipPos[i][1], worshipPos[i][2], worshipPos[i][3],
                    TEMPSUMMON_CORPSE_TIMED_DESPAWN, ADD_DESPAWN_TIME))
                {
                    worshippers[i] = c->GetObjectGuid();
                }
                else
                {
                    sLog.outError("boss_faerlinaAI::CheckRespawnAdds failed to spawn naxxramas worshipper");
                }
            }
        }
    }

    void SummonedCreatureJustDied(Creature* pSummoned) override
    {
        switch (pSummoned->GetEntry())
        {
            case MOB_FOLLOWER:
                for (auto& follower : followers)
                {
                    if (follower == pSummoned->GetObjectGuid())
                    {
                        follower = 0;
                        break;
                    }
                }
                break;
            case MOB_WORSHIPPER:
                for (auto& worshipper : worshippers)
                {
                    if (worshipper == pSummoned->GetObjectGuid())
                    {
                        worshipper = 0;
                        break;
                    }
                }
                break;
        }
    }

    void JustReachedHome() override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_FAERLINA, FAIL);
        CheckRespawnAdds();
    }

    void Aggro(Unit* pWho) override
    {
        DoScriptText(SAY_PULL, m_creature);

        if (m_pInstance)
            m_pInstance->SetData(TYPE_FAERLINA, IN_PROGRESS);

        for (const auto& follower : followers)
        {
            if (Creature* c = m_pInstance->GetCreature(follower))
                c->AI()->AttackStart(pWho);
        }

        for (const auto& worshipper : worshippers)
        {
            if (Creature* c = m_pInstance->GetCreature(worshipper))
                c->AI()->AttackStart(pWho);
        }
    }

    void MoveInLineOfSight(Unit* pWho) override
    {
        //todo aggro range
        if (m_creature->IsWithinDistInMap(pWho, 60.0f)) { }

        ScriptedAI::MoveInLineOfSight(pWho);
    }

    void KilledUnit(Unit* pVictim) override
    {
        if (pVictim->GetTypeId() != TYPEID_PLAYER)
            return;

        DoScriptText(urand(0, 1) ? SAY_SLAY1 : SAY_SLAY2, m_creature);
    }

    void JustDied(Unit* pKiller) override
    {
        DoScriptText(SAY_DEATH, m_creature);

        if (m_pInstance)
            m_pInstance->SetData(TYPE_FAERLINA, DONE);
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (!m_pInstance->HandleEvadeOutOfHome(m_creature))
        {
            std::list<Creature*> creatures;
            GetCreatureListWithEntryInGrid(creatures, m_creature, { NPC_NaxxramasFollower, NPC_NaxxramasWorshipper}, 150.0f);
            for (Creature* pCreature : creatures)
            {
                pCreature->AI()->EnterEvadeMode();
            }
            return;
        }

        // Poison Bolt Volley
        if (m_uiPoisonBoltVolleyTimer < uiDiff)
        {
            if (m_creature->HasAura(SPELL_WIDOWS_EMBRACE))
            {
                m_uiPoisonBoltVolleyTimer = 2500; // retrying in 2.5sec
            }
            else 
            {
                if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_POSIONBOLT_VOLLEY) == CanCastResult::CAST_OK)
                {
                    m_uiPoisonBoltVolleyTimer = POSIONBOLT_VOLLEY_CD();
                }
            }
        }
        else
            m_uiPoisonBoltVolleyTimer -= uiDiff;

        // Rain Of Fire
        if (m_uiRainOfFireTimer < uiDiff)
        {
            if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
            {
                if (DoCastSpellIfCan(pTarget, SPELL_RAINOFFIRE) == CanCastResult::CAST_OK)
                {
                    m_uiRainOfFireTimer = RAINOFFIRE_CD();
                }
            }
        }
        else
            m_uiRainOfFireTimer -= uiDiff;

        //Enrage_Timer
        if (m_uiEnrageTimer < uiDiff)
        {
            // widows embrace can be used as a preventive method rather than dispelling method for the enrage as well,
            // but then it only prevents the enrage for the duration of the debuff.
            if (!m_creature->HasAura(SPELL_WIDOWS_EMBRACE))
            {
                if (DoCastSpellIfCan(m_creature, SPELL_ENRAGE) == CanCastResult::CAST_OK)
                {
                    m_uiEnrageTimer = 60000;
                    DoScriptText(urand(SAY_ENRAGE1, SAY_ENRAGE3), m_creature);
                }
            }
        }
        else
            m_uiEnrageTimer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

struct mob_faerlina_rp : public ScriptedAI
{
    enum eEvents
    {
        EVENT_KNEEL = 1,
        EVENT_CAST,
        EVENT_STAND,
        EVENT_UNAURA
    };

    EventMap events;

    mob_faerlina_rp(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    void Reset() override
    {
        events.Reset();
        events.ScheduleEvent(EVENT_KNEEL, Seconds(urand(5, 10)));
    }

    std::list<Creature*> getGroup()
    {
        std::list<Creature*> creatures;
        GetCreatureListWithEntryInGrid(creatures, m_creature, { NPC_NaxxramasAcolyte, NPC_NaxxramasCultist }, 11.0f);
        return creatures;
    }

    void UpdateAI(uint32 const diff) override
    {
        events.Update(diff);
        while (uint32 eventId = events.ExecuteEvent())
        {
            std::list<Creature*> creatures = getGroup();
            if (creatures.empty())
            {
                Reset();
                break;
            }
            if ((*creatures.begin())->IsInCombat())
            {
                Reset();
                break;
            }

            for (auto it = creatures.begin(); it != creatures.end();)
            {
                if ((*it)->IsDead())
                    it = creatures.erase(it);
                else
                    ++it;
            }

            switch (eventId)
            {
            case EVENT_KNEEL:
                for (Creature* pC : creatures)
                    pC->SetStandState(UNIT_STAND_STATE_KNEEL);
                events.ScheduleEvent(EVENT_CAST, Seconds(urand(10, 90)));
                break;
            case EVENT_CAST:
                for (Creature* pC : creatures)
                    pC->CastSpell(pC, 21157, true);
                events.ScheduleEvent(EVENT_STAND, Seconds(1));
                break;
            case EVENT_STAND:
                for (Creature* pC : creatures)
                    pC->SetStandState(UNIT_STAND_STATE_STAND);
                events.ScheduleEvent(EVENT_UNAURA, Seconds(urand(10, 30)));
                break;
            case EVENT_UNAURA:
                for (Creature* pC : creatures)
                    pC->RemoveAurasDueToSpell(21157);
                events.ScheduleEvent(EVENT_KNEEL, Seconds(urand(2, 10)));
                break;
            }
        }
    }
};

CreatureAI* GetAI_boss_faerlina(Creature* pCreature)
{
    return new boss_faerlinaAI(pCreature);
}

CreatureAI* GetAI_mob_faerlina_rp(Creature* pCreature)
{
    return new mob_faerlina_rp(pCreature);
}

void AddSC_boss_faerlina()
{
    Script* NewScript;
    NewScript = new Script;
    NewScript->Name = "boss_faerlina";
    NewScript->GetAI = &GetAI_boss_faerlina;
    NewScript->RegisterSelf();

    NewScript = new Script;
    NewScript->Name = "mob_faerlina_rp";
    NewScript->GetAI = &GetAI_mob_faerlina_rp;
    NewScript->RegisterSelf();
}
