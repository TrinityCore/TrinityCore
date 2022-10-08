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

/*
Full rewrite by Gemt

Current semi-unknowns:
The aoe manaburn; not seen it used in videos, despite all original vanilla guides mentioning it.
Probably because its pretty much a wipe if ranged/healers are hit by it. 
While Decrepit fever is very aggressive on its cooldown after a dance phase, the mana burn does not seem to be,
so we should give "plenty" of time for casters to get to the platform, and tank to move the boss away.

Chain pull radius for adds in encounter gauntlet is a bit of a guesswork with some hacks to override
the default, static, callForHelp radius.

*/

#include "scriptPCH.h"
#include "naxxramas.h"

enum HeiganData
{
    PHASE_GROUND            = 1,
    PHASE_PLATFORM          = 2,

    SAY_AGGRO1              = 13041,
    SAY_AGGRO2              = 13042,
    SAY_AGGRO3              = 13043,
    SAY_SLAY                = 13045,
    
    SAY_TAUNT1              = 13046,
    SAY_TAUNT2              = 13047,
    SAY_TAUNT3              = 13048,
    SAY_TAUNT4              = 13050,
    SAY_CHANNELING          = 13049,
    SAY_DEATH               = -1533118, // need find correct bct id!

    EMOTE_TELEPORT          = -1533136, // need find correct bct id!
    EMOTE_RETURN            = -1533137, // need find correct bct id!

    SPELL_ERUPTION          = 29371,

    //Spells by boss
    SPELL_DECREPIT_FEVER    = 29998,
    SPELL_PLAGUE_CLOUD      = 29350,
    SPELL_TELEPORT_SELF     = 30211,
    SPELL_MANABURN          = 29310,

    NPC_PLAGUE_FISSURE      = 533001,
    NPC_PLAGUE_CLOUD        = 533002
};

enum Events
{
    EVENT_FEVER = 1,
    EVENT_ERUPT,
    EVENT_DANCE,
    EVENT_DANCE_END,
    EVENT_TAUNT,
    EVENT_DOOR_CLOSE,
    EVENT_MANABURN,
    EVENT_PORT_PLAYER
};

enum Phases
{
    PHASE_FIGHT = 1,
    PHASE_DANCE
};

//static uint32 const firstEruptionDBGUID = 533048;
static uint8 const numSections = 4;
/*static uint8 const numEruptions[numSections] = { // count of sequential GO DBGUIDs in the respective section of the room
    15,
    25,
    23,
    13
};*/

// in tunnel
static constexpr float safespotFissures[3][3] = 
{   
    {2747.0f, -3754.0f, 274.0f},
    {2805.8f, -3695.88f, 273.61f},
    {2812.95f, -3703.52f, 273.61f},
};

static constexpr float sect1SafeSpot[3][3] = 
{
    { 2799.5f, -3691.0f, 273.62f },
    { 2810.67f, -3706.06f, 275.0f },
    { 2803.51f, -3697.42f, 274.1f }
};

static constexpr float sect2SafeSpot[3] = { 2790.51f, -3690.45f, 273.622f };
static constexpr float sect3SafeSpot[3] = { 2778.40f, -3702.645f, 273.621f };
static constexpr float sect4SafeSpot[3][3] = 
{
    { 2777.2f, -3712.41f, 273.63f },
    { 2783.06f, -3717.7f, 273.63f },
    { 2791.62f, -3726.04f, 273.63f },
};

struct boss_heiganAI : public ScriptedAI
{
    boss_heiganAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (instance_naxxramas*)pCreature->GetInstanceData();
        Reset();
    }
    instance_naxxramas* m_pInstance;

    Phases currentPhase;
    EventMap m_events;
    uint8 eruptionPhase;
    std::vector<ObjectGuid> _eruptTiles[numSections];
    uint32 killCooldown;
    std::vector<ObjectGuid> portedPlayersThisPhase;

    void Reset() override
    {
        portedPlayersThisPhase.clear();

        m_events.Reset();
        killCooldown = 10000;
        currentPhase = PHASE_FIGHT;
    }

    void Aggro(Unit* pWho) override
    {
        m_creature->SetInCombatWithZone();

        eruptionPhase = 0;
        currentPhase = PHASE_FIGHT;
        m_events.ScheduleEvent(EVENT_FEVER,      Seconds(30), 0, PHASE_FIGHT);
        m_events.ScheduleEvent(EVENT_DANCE,      Seconds(90), 0, PHASE_FIGHT);
        m_events.ScheduleEvent(EVENT_ERUPT,      Seconds(15), 0, PHASE_FIGHT);
        m_events.ScheduleEvent(EVENT_MANABURN,   Seconds(15), 0, PHASE_FIGHT);
        m_events.ScheduleEvent(EVENT_TAUNT,      randtime(Seconds(20), Seconds(70)));
        m_events.ScheduleEvent(EVENT_DOOR_CLOSE, Seconds(15));
        m_events.ScheduleEvent(EVENT_PORT_PLAYER,Seconds(40));

        DoScriptText(urand(SAY_AGGRO1, SAY_AGGRO3), m_creature);

        if (m_pInstance)
            m_pInstance->SetData(TYPE_HEIGAN, IN_PROGRESS);
    }

    void MoveInLineOfSight(Unit* pWho) override
    {
        if (currentPhase == PHASE_DANCE)
            return;
        else
        {
            if (pWho->GetPositionX() > 2825.0f)
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
    }

    void AttackStart(Unit* pWho) override
    {
        if (currentPhase == PHASE_DANCE)
            return;
        else
            ScriptedAI::AttackStart(pWho);
    }

    void KilledUnit(Unit* pVictim) override
    {
        if(!killCooldown)
            DoScriptText(SAY_SLAY, m_creature);
    }

    void JustDied(Unit* pKiller) override
    {
        DoScriptText(SAY_DEATH, m_creature);

        if (m_pInstance)
        {
            m_pInstance->SetData(TYPE_HEIGAN, DONE);
            m_pInstance->UpdateAutomaticBossEntranceDoor(GO_PLAG_HEIG_ENTRY_DOOR, DONE);
        }
    }

    void JustReachedHome() override
    {
        if (m_pInstance)
        {
            m_pInstance->SetData(TYPE_HEIGAN, FAIL);
            m_pInstance->UpdateAutomaticBossEntranceDoor(GO_PLAG_HEIG_ENTRY_DOOR, FAIL);
        }
    }

    void SendEruptCustomLocation(float x, float y, float z)
    {
        if (Creature* fissureCreature = m_creature->SummonCreature(NPC_PLAGUE_FISSURE, x, y, z, 0, TEMPSUMMON_TIMED_DESPAWN, 50))
        {
            fissureCreature->CastSpell(fissureCreature, SPELL_ERUPTION, true);
        }
    }

    void UpdateEruption()
    {
        if (!m_pInstance)
            return;
        Creature* fissureCreature = m_creature->SummonCreature(NPC_PLAGUE_FISSURE, 2773.0f, -3684.0f, 292.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN, 1000);
        if (!fissureCreature)
        {
            sLog.outError("Heigan: failed spawning fissure creature");
            return;
        }

        for (uint8 uiArea = 0; uiArea < 4; ++uiArea)
        {
            // Actually this is correct :P
            if (uiArea == (eruptionPhase % 6) || uiArea == 6 - (eruptionPhase % 6))
                continue;

            for (const auto& guid : m_pInstance->m_alHeiganTrapGuids[uiArea])
            {
                if (GameObject* pTrap = m_pInstance->GetGameObject(guid))
                {
                    pTrap->Use(fissureCreature);
                    pTrap->SendGameObjectCustomAnim();
                }
            }

            switch (uiArea)
            {
                case 0:
                    for (const auto& i : sect1SafeSpot)
                        SendEruptCustomLocation(i[0], i[1], i[2]);
                    break;
                case 1:
                    SendEruptCustomLocation(sect2SafeSpot[0], sect2SafeSpot[1], sect2SafeSpot[2]);
                    break;
                case 2:
                    SendEruptCustomLocation(sect3SafeSpot[0], sect3SafeSpot[1], sect3SafeSpot[2]);
                    break;
                case 3:
                    for (const auto& i : sect4SafeSpot)
                        SendEruptCustomLocation(i[0], i[1], i[2]);
                    break;
            }
        }

        // safespot avoidance in tunnel
        if (currentPhase == PHASE_DANCE)
        {
            for (const auto& safespotFissure : safespotFissures)
                SendEruptCustomLocation(safespotFissure[0], safespotFissure[1], safespotFissure[2]);
        }

        ++eruptionPhase;
    }

    void SummmonPlagueCloud(float x, float y, float z, float o)
    {
        if (Creature* pCloud = m_creature->SummonCreature(NPC_PLAGUE_CLOUD, x, y, z, o,
            TEMPSUMMON_TIMED_DESPAWN, 45000))
        {
            pCloud->CastSpell((Unit*)nullptr, SPELL_PLAGUE_CLOUD, true);
        }
    }

    void EventStartDance()
    {
        portedPlayersThisPhase.clear();

        if (DoCastSpellIfCan(m_creature, SPELL_TELEPORT_SELF, CF_TRIGGERED) != CAST_OK)
        {
            return;
        }
        currentPhase = PHASE_DANCE;

        m_creature->SetReactState(REACT_PASSIVE);
        m_creature->AttackStop();
        m_creature->StopMoving();
        m_creature->GetMotionMaster()->MoveIdle();
        DoStopAttack();
        DoCastAOE(SPELL_PLAGUE_CLOUD);

        uint32 tauntStash = m_events.GetTimeUntilEvent(EVENT_TAUNT);
        m_events.Reset();
        m_events.ScheduleEvent(EVENT_TAUNT, tauntStash);
        m_events.ScheduleEvent(EVENT_DANCE_END, Seconds(45), 0, PHASE_DANCE);
        m_events.ScheduleEvent(EVENT_ERUPT, Seconds(4));

        // the regular ones
        for (const auto& eyeStalkPossition : eyeStalkPossitions)
        {
            SummmonPlagueCloud(eyeStalkPossition[0], eyeStalkPossition[1], eyeStalkPossition[2], eyeStalkPossition[3]);
        }

        DoScriptText(SAY_CHANNELING, m_creature);
        eruptionPhase = 0;
    }

    void EventDanceEnd()
    {
        currentPhase = PHASE_FIGHT;

        uint32 tauntStash = m_events.GetTimeUntilEvent(EVENT_TAUNT);
        m_events.Reset();
        m_events.ScheduleEvent(EVENT_TAUNT,     tauntStash);
        m_events.ScheduleEvent(EVENT_FEVER,     Seconds(5)); // videos confirm this, unless raid moves perfectly, more or less everyone is hit.
        m_events.ScheduleEvent(EVENT_DANCE,     Seconds(90));
        m_events.ScheduleEvent(EVENT_ERUPT,     Seconds(10));
        m_events.ScheduleEvent(EVENT_MANABURN,  Seconds(10));
        m_events.ScheduleEvent(EVENT_PORT_PLAYER, Seconds(18));
        m_events.ScheduleEvent(EVENT_PORT_PLAYER, Seconds(48));
        m_creature->CastStop();
        m_creature->SetReactState(REACT_AGGRESSIVE);
        eruptionPhase = 0;

        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;
        m_creature->GetMotionMaster()->MoveChase(m_creature->GetVictim());
    }

    void EventPortPlayer()
    {
        const ThreatList& tl = m_creature->GetThreatManager().getThreatList();
        std::vector<Unit*> candidates;
        auto it = tl.begin();
        ++it; // skip the tank
        for (it; it != tl.end(); it++)
        {
            if (Unit* pUnit = m_creature->GetMap()->GetUnit((*it)->getUnitGuid()))
            {
                // Candidates are only alive players who have not yet been ported during this phase rotation
                if (pUnit->IsPlayer() && pUnit->IsAlive()
                    && std::find(portedPlayersThisPhase.begin(), portedPlayersThisPhase.end(), pUnit->GetObjectGuid()) == portedPlayersThisPhase.end())
                {
                    candidates.push_back(pUnit);
                }
            }
        }

        for (int i = 0; i < 3; i++)
        {
            if (candidates.empty())
                break;

            uint32 idx = urand(0, candidates.size() - 1);
            Unit* target = candidates[idx];
            candidates.erase(candidates.begin() + idx);
            portedPlayersThisPhase.push_back(target->GetObjectGuid());
            // getting the spell visual to show both where you were TPed from and where you are TPed too
            if (Creature* pCreature = m_creature->SummonCreature(NPC_PLAGUE_FISSURE, 
                target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), target->GetOrientation(),
                TEMPSUMMON_TIMED_DESPAWN, 2000))
            {
                pCreature->SendSpellGo(pCreature, 30211);
            }
            target->SendSpellGo(target, 30211);
            target->NearTeleportTo(2917.43f, -3769.18f, 273.62f, 3.1415f);
        }
    }

    void EventTaunt()
    {
        // Taunt
        DoScriptText(PickRandomValue(SAY_TAUNT1, SAY_TAUNT2, SAY_TAUNT3, SAY_TAUNT4), m_creature);
        m_events.Repeat(randtime(Seconds(20), Seconds(70)));
    }

    void CheckManausersAndRepeat()
    {
        // Looking for anyone with a manabar, currently excluded pets and totems
        // within 25yd range (radius of SPELL_MANABURN). If there is one we cast SPELL_MANABURN
        const auto& tl = m_creature->GetThreatManager().getThreatList();
        bool found_mana_in_range = false;
        for (const auto it : tl)
        {
            if (Unit* pTarget = m_creature->GetMap()->GetUnit(it->getUnitGuid()))
            {
                if (pTarget->GetPowerType() == POWER_MANA && pTarget->GetTypeId() == TYPEID_PLAYER && pTarget->IsAlive())
                {
                    if (m_creature->GetDistance3dToCenter(it->getTarget()) < 28.0f)
                    {
                        found_mana_in_range = true;
                        break;
                    }
                }
            }
        }

        if (found_mana_in_range && DoCastSpellIfCan(m_creature, SPELL_MANABURN) == CAST_OK)
            m_events.Repeat(Seconds(3));
        else
            m_events.Repeat(Seconds(1));
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        // This will avoid him running off the platform during dance phase.
        if (currentPhase == PHASE_FIGHT)
        {
            if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
                return;
            if (!m_pInstance->HandleEvadeOutOfHome(m_creature))
                return;
        }
        else
        {
            // If wipe, we force the dance phase to end so above code runs and he evades.
            if (m_creature->GetThreatManager().isThreatListEmpty())
                EventDanceEnd();
        }

        m_events.Update(uiDiff);
        while (uint32 eventId = m_events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_FEVER:
                    DoCastAOE(SPELL_DECREPIT_FEVER);
                    m_events.Repeat(randtime(Seconds(20), Seconds(25)));
                    break;
                case EVENT_DANCE:
                    EventStartDance();
                    break;
                case EVENT_DANCE_END:
                    EventDanceEnd();
                    break;
                case EVENT_ERUPT:
                    UpdateEruption();
                    m_events.Repeat(currentPhase == PHASE_DANCE ? Seconds(3) : Seconds(10));
                    break;
                case EVENT_TAUNT:
                    EventTaunt();
                    break;
                case EVENT_DOOR_CLOSE:
                    if(m_pInstance)
                        m_pInstance->UpdateAutomaticBossEntranceDoor(GO_PLAG_HEIG_ENTRY_DOOR, IN_PROGRESS);
                    break;
                case EVENT_MANABURN:
                    CheckManausersAndRepeat();
                    break;
                case EVENT_PORT_PLAYER:
                    EventPortPlayer();
                    break;
            }
        }

        if (killCooldown < uiDiff)
            killCooldown = 0;
        else
            killCooldown -= uiDiff;

        if (currentPhase == PHASE_FIGHT)
            DoMeleeAttackIfReady();
    }
};

struct mob_plague_cloudAI : public ScriptedAI
{
    mob_plague_cloudAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    void Reset() override
    {
        m_creature->AddUnitState(UNIT_STAT_ROOT);
        m_creature->StopMoving();
        m_creature->SetRooted(true);
    }

    void AttackStart(Unit*) override { }
    void MoveInLineOfSight(Unit*) override { }
    void UpdateAI(uint32 const) override { }
};

CreatureAI* GetAI_boss_heigan(Creature* pCreature)
{
    return new boss_heiganAI(pCreature);
}

CreatureAI* GetAI_mob_plagueCloud(Creature* pCreature)
{
    return new mob_plague_cloudAI(pCreature);
}

void AddSC_boss_heigan()
{
    Script* NewScript;
    NewScript = new Script;
    NewScript->Name = "boss_heigan";
    NewScript->GetAI = &GetAI_boss_heigan;
    NewScript->RegisterSelf();

    NewScript = new Script;
    NewScript->Name = "mob_plague_cloud";
    NewScript->GetAI = &GetAI_mob_plagueCloud;
    NewScript->RegisterSelf();
}
