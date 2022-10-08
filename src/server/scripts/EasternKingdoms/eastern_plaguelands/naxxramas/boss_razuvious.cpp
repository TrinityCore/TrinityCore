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
SDName: Boss_Razuvious
SD%Complete: 99%
SDComment: TODO: Timers and sounds need confirmation
SDCategory: Naxxramas
EndScriptData */

#include "scriptPCH.h"
#include "naxxramas.h"

enum RazuviousData
{
    SAY_AGGRO1               = 13072,
    SAY_AGGRO2               = 13073,
    SAY_AGGRO3               = 13074,
    SAY_SLAY1                = 13080,
    SAY_SLAY2                = 13081,
    SAY_COMMAND1             = 13075,
    SAY_COMMAND2             = 13076,
    SAY_COMMAND3             = 13077,
    SAY_COMMAND4             = 13078,
    SAY_DEATH                = 13079,

    EMOTE_SHOUT              = 13082,

    SPELL_UNBALANCING_STRIKE = 26613,
    SPELL_DISRUPTING_SHOUT   = 29107,
    SPELL_HOPELESS           = 29125,

    NPC_DK_UNDERSTUDY   = 16803
};

static constexpr float addPositions[4][4] =
{
    {2757.48f, -3111.52f, 267.768f, 3.92699f },
    {2762.05f, -3084.47f, 267.768f, 2.1293f  },
    {2778.91f, -3114.14f, 267.768f, 5.28835f },
    {2781.87f, -3088.19f, 267.768f, 0.907571f},
};

enum Events
{
    EVENT_UNBALANCING_STRIKE = 1,
    EVENT_DISRUPTING_SHOUT,
    EVENT_COMMAND,

    // out of combat rp
    EVENT_TURN_TO_TRAINEE,
    EVENT_EMOTE_SHOUT,
    EVENT_ADD_TURN_RAZUV,
    EVENT_ADD_TALK,
    EVENT_ADD_SALUTE,
    EVENT_ADD_TURN_BACK,
    EVENT_ADD_ATTACK
};

struct mob_deathknightUnderstudyAI : public ScriptedAI
{
    mob_deathknightUnderstudyAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (instance_naxxramas*)pCreature->GetInstanceData();
        Reset();
    }

    instance_naxxramas* m_pInstance;

    uint32 attackTimer;
    bool runAttack;

    void Reset() override
    {
        m_creature->HandleEmote(EMOTE_STATE_READY1H);
        attackTimer = urand(5000, 10000);
        runAttack = true;
    }

    void Aggro(Unit*) override
    {
        runAttack = false;
        m_creature->CallForHelp(30.0f);
    }

    void UpdateAI(uint32 const diff) override
    {
        if (runAttack)
        {
            if (attackTimer < diff)
            {
                m_creature->HandleEmote(EMOTE_ONESHOT_ATTACK1H);
                attackTimer = urand(5000, 10000);
            }
            else
                attackTimer -= diff;
        }

        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        DoMeleeAttackIfReady();
    }
};

struct boss_razuviousAI : public ScriptedAI
{
    boss_razuviousAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (instance_naxxramas*)pCreature->GetInstanceData();
        Reset();
        RespawnAdds();
    }

    instance_naxxramas* m_pInstance;
    std::vector<ObjectGuid> summonedAdds;
    EventMap events;

    EventMap rpEvents;
    ObjectGuid rpBuddy;

    void Reset() override
    {
        events.Reset();
    }

    void MoveInLineOfSight(Unit* pWho) override
    {
        if (!m_creature->IsWithinDistInMap(pWho, 33.0f))
            return;

        if (m_creature->CanInitiateAttack() && pWho->IsTargetable(true, false) && m_creature->IsHostileTo(pWho))
        {
            if (pWho->IsInAccessablePlaceFor(m_creature) && m_creature->IsWithinLOSInMap(pWho))
            {
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

    void RespawnAdds()
    {
        if (m_pInstance && m_pInstance->GetData(TYPE_RAZUVIOUS) == DONE)
            return;

        // start by despawning any adds that may still be around
        for (auto it = summonedAdds.begin(); it != summonedAdds.end();)
        {
            if (Creature* cg = m_pInstance->GetCreature((*it)))
            {
                if (TemporarySummon* tmpSumm = static_cast<TemporarySummon*>(cg)) {
                    tmpSumm->UnSummon();
                }
            }
            it = summonedAdds.erase(it);
        }

        // respawn all 4 adds
        for (int i = 0; i < 4; i++)
        {
            if (Creature* pAdd = m_creature->SummonCreature(NPC_DK_UNDERSTUDY, addPositions[i][0], addPositions[i][1], addPositions[i][2], addPositions[i][3],
                TEMPSUMMON_CORPSE_TIMED_DESPAWN, 60000))
            {
                if (i == 1)
                    rpBuddy = pAdd->GetObjectGuid();
                summonedAdds.push_back(pAdd->GetObjectGuid());
                pAdd->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY1H);
            }
        }
    }

    void JustReachedHome() override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_RAZUVIOUS, FAIL);

        RespawnAdds();
    }

    void KilledUnit(Unit* Victim) override
    {
        if (urand(0, 3))
            return;
        DoScriptText(urand(SAY_SLAY1, SAY_SLAY2), m_creature);
    }

    void JustDied(Unit* pKiller) override
    {
        DoScriptText(SAY_DEATH, m_creature);
        DoCastSpellIfCan(m_creature, SPELL_HOPELESS, CF_TRIGGERED);
        if (m_pInstance)
            m_pInstance->SetData(TYPE_RAZUVIOUS, DONE);
    }

    void Aggro(Unit* pWho) override
    {
        DoScriptText(urand(SAY_AGGRO1, SAY_AGGRO3), m_creature);

        if (m_pInstance)
            m_pInstance->SetData(TYPE_RAZUVIOUS, IN_PROGRESS);

        events.Reset();
        rpEvents.Reset();
        m_creature->CallForHelp(30.0f);

        events.ScheduleEvent(EVENT_UNBALANCING_STRIKE, Seconds(30));
        events.ScheduleEvent(EVENT_DISRUPTING_SHOUT, Seconds(15));
        events.ScheduleEvent(EVENT_COMMAND, Seconds(40));
    }

    void MovementInform(uint32 movementType, uint32 id) override
    {
        if (movementType != WAYPOINT_MOTION_TYPE)
            return;

        if (id == 6)
        {
            rpEvents.Reset();
            rpEvents.ScheduleEvent(EVENT_TURN_TO_TRAINEE, Seconds(0));
            rpEvents.ScheduleEvent(EVENT_EMOTE_SHOUT, Seconds(1));
            rpEvents.ScheduleEvent(EVENT_ADD_TURN_RAZUV, Milliseconds(1750));
            rpEvents.ScheduleEvent(EVENT_ADD_TALK, Milliseconds(3500));
            rpEvents.ScheduleEvent(EVENT_ADD_SALUTE, Seconds(8));
            rpEvents.ScheduleEvent(EVENT_ADD_TURN_BACK, Seconds(12));
            rpEvents.ScheduleEvent(EVENT_ADD_ATTACK, Milliseconds(12500));
        }
    }

    Creature* getRPBuddy()
    {
        return m_pInstance->GetCreature(rpBuddy);
    }

    void UpdateRP(uint32 diff)
    {
        rpEvents.Update(diff);
        while (uint32 eventId = rpEvents.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_TURN_TO_TRAINEE:
                    if (Creature* b = getRPBuddy())
                        m_creature->SetFacingToObject(b);
                    break;
                case EVENT_EMOTE_SHOUT:
                    m_creature->HandleEmote(EMOTE_ONESHOT_EXCLAMATION);
                    break;
                case EVENT_ADD_TURN_RAZUV:
                    if (Creature* b = getRPBuddy())
                    {
                        if (mob_deathknightUnderstudyAI* ai = (mob_deathknightUnderstudyAI*)b->AI())
                        {
                            ai->attackTimer = 0;
                            ai->runAttack = false;
                        }
                        b->SetFacingToObject(m_creature);
                        b->HandleEmote(EMOTE_STATE_STAND);
                    }
                    break;
                case EVENT_ADD_TALK:
                    if (Creature* b = getRPBuddy())
                        b->HandleEmote(EMOTE_ONESHOT_TALK);
                    break;
                case EVENT_ADD_SALUTE:
                    if (Creature* b = getRPBuddy())
                        b->HandleEmote(EMOTE_ONESHOT_SALUTE);
                    break;
                case EVENT_ADD_TURN_BACK:
                    if (Creature* b = getRPBuddy())
                    {
                        std::list<Creature*> lst;
                        GetCreatureListWithEntryInGrid(lst, b, 16211, 5.0f);
                        if (!lst.empty())
                            b->SetFacingToObject((*lst.begin()));
                    }
                    break;
                case EVENT_ADD_ATTACK:
                    if (Creature* b = getRPBuddy())
                    {
                        b->HandleEmote(EMOTE_STATE_READY1H);
                        if (mob_deathknightUnderstudyAI* ai = (mob_deathknightUnderstudyAI*)b->AI())
                        {
                            ai->attackTimer = 500;
                            ai->runAttack = true;
                        }
                    }
                    break;
            }
        }
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->IsInCombat())
            UpdateRP(uiDiff);

        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (!m_pInstance->HandleEvadeOutOfHome(m_creature))
            return;

        events.Update(uiDiff);
        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_UNBALANCING_STRIKE:
                    DoCastSpellIfCan(m_creature->GetVictim(), SPELL_UNBALANCING_STRIKE);
                    events.Repeat(Seconds(30));
                    break;
                case EVENT_DISRUPTING_SHOUT:
                    DoCastSpellIfCan(m_creature->GetVictim(), SPELL_DISRUPTING_SHOUT);
                    DoScriptText(EMOTE_SHOUT, m_creature);
                    events.Repeat(Seconds(25));
                    break;
                case EVENT_COMMAND:
                    DoScriptText(urand(SAY_COMMAND1, SAY_COMMAND4), m_creature);
                    events.Repeat(Seconds(urand(30,60)));
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_razuvious(Creature* pCreature)
{
    return new boss_razuviousAI(pCreature);
}

CreatureAI* GetAI_mob_deathknightUnderstudy(Creature* pCreature)
{
    return new mob_deathknightUnderstudyAI(pCreature);
}

void AddSC_boss_razuvious()
{
    Script* NewScript;
    NewScript = new Script;
    NewScript->Name = "boss_razuvious";
    NewScript->GetAI = &GetAI_boss_razuvious;
    NewScript->RegisterSelf();

    NewScript = new Script;
    NewScript->Name = "deathknight_understudy_ai";
    NewScript->GetAI = &GetAI_mob_deathknightUnderstudy;
    NewScript->RegisterSelf();
}
