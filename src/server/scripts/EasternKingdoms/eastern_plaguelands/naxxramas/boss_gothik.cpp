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
SDName: Boss_Gothik
SD%Complete: 60
SDComment: Only base implemented. Todo: control adds at summon. Handle case of raid not splitted in two sides
SDCategory: Naxxramas
EndScriptData */

#include "scriptPCH.h"
#include "naxxramas.h"

enum GothikData
{
    SAY_SPEECH_1                = 13029,
    SAY_SPEECH_2                = 13031,
    SAY_SPEECH_3                = 13032,
    SAY_SPEECH_4                = 13033,

    SAY_KILL                    = 13027,
    SAY_DEATH                   = 13026,
    SAY_TELEPORT                = 13028,

    EMOTE_TO_FRAY               = -1533138, // bct need!
    EMOTE_GATE                  = -1533139, // bct need!

    PHASE_SPEECH                = 0,
    PHASE_BALCONY               = 1,
    PHASE_GROUND                = 2,

    MAX_WAVES                   = 18,

    SPELL_TELEPORT_LEFT         = 28025,                    // guesswork
    SPELL_TELEPORT_RIGHT        = 28026,                    // could be defined as dead or live side, left or right facing north

    SPELL_HARVESTSOUL           = 28679,
    SPELL_SHADOWBOLT            = 29317,

    SPELL_IMMUNE_ALL            = 29230,
    TELEPORT_PACIFY_TIMER       = 1200
};

enum eSpellDummy
{
    SPELL_A_TO_ANCHOR_1     = 27892,
    SPELL_B_TO_ANCHOR_1     = 27928,
    SPELL_C_TO_ANCHOR_1     = 27935,

    SPELL_A_TO_ANCHOR_2     = 27893,
    SPELL_B_TO_ANCHOR_2     = 27929,
    SPELL_C_TO_ANCHOR_2     = 27936,

    SPELL_A_TO_SKULL        = 27915,
    SPELL_B_TO_SKULL        = 27931,
    SPELL_C_TO_SKULL        = 27937
};

struct boss_gothikAI : public ScriptedAI
{
    boss_gothikAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (instance_naxxramas*)pCreature->GetInstanceData();
        Reset();
    }

    instance_naxxramas* m_pInstance;

    uint8 m_uiPhase;

    uint8 m_uiSpeechCount;
    uint32 m_uiSpeechTimer;

    uint8 m_uiSummonCount;
    uint32 m_uiSummonTimer;

    uint32 m_uiTeleportTimer;
    uint32 m_uiTeleportCastDelay;
    uint32 m_uiShadowboltTimer;
    uint32 m_uiHarvestSoulTimer;
    uint32 m_uiNumTP;
    uint32 m_checkAllPlayersOneSideTimer;

    bool gatesOpened;
    bool m_bRightSide;
    bool m_bJustTeleported;

    void Reset() override
    {
        m_uiPhase = PHASE_SPEECH;

        m_uiSpeechCount = 0;
        m_uiSpeechTimer = 5000;

        m_uiSummonCount = 0;
        m_uiSummonTimer = 4000;

        m_uiTeleportTimer = 15000;
        m_uiShadowboltTimer = 1000;
        m_uiHarvestSoulTimer = 1000;
        m_checkAllPlayersOneSideTimer = 1000;
        m_uiTeleportCastDelay = 0;
        m_uiNumTP = 0;
        gatesOpened = false;
        m_bRightSide = false;
        m_bJustTeleported = false;

        std::list<Creature*> creaturesToDespawn;
        GetCreatureListWithEntryInGrid(creaturesToDespawn, m_creature, 
        { NPC_UNREL_TRAINEE, NPC_UNREL_DEATH_KNIGHT, NPC_UNREL_RIDER, NPC_SPECT_TRAINEE, NPC_SPECT_DEATH_KNIGTH, NPC_SPECT_RIDER, NPC_SPECT_HORSE }, 
            1000.0f);
        for (Creature* pC : creaturesToDespawn)
        {
            pC->DeleteLater();
        }
        m_creature->SetCasterChaseDistance(40);
    }

    void Aggro(Unit* pWho) override
    {
        m_creature->SetInCombatWithZone();

        DoScriptText(SAY_SPEECH_1, m_creature);

        if (!m_pInstance)
            return;

        m_pInstance->SetData(TYPE_GOTHIK, IN_PROGRESS);

        m_pInstance->SetGothTriggers();

        m_creature->GetMotionMaster()->MoveIdle();
        DoStopAttack();
        if(!m_creature->HasAura(SPELL_IMMUNE_ALL))
            m_creature->CastSpell(m_creature, SPELL_IMMUNE_ALL, true);
    }

    void AttackStart(Unit* pWho) override
    {
        if (!m_creature->HasAura(SPELL_IMMUNE_ALL))
            ScriptedAI::AttackStart(pWho);
    }

    void EnterEvadeMode() override
    {
        ScriptedAI::EnterEvadeMode();
        m_creature->Respawn();
        m_creature->NearTeleportTo(m_creature->GetHomePosition());
    }

    void KilledUnit(Unit* pVictim) override
    {
        if (pVictim->GetTypeId() == TYPEID_PLAYER)
            DoScriptText(SAY_KILL, m_creature);
    }

    void JustDied(Unit* pKiller) override
    {
        DoScriptText(SAY_DEATH, m_creature);
        OpenTheGate();
        if (m_pInstance)
            m_pInstance->SetData(TYPE_GOTHIK, DONE);
    }

    void JustReachedHome() override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_GOTHIK, FAIL);
    }

    void SummonAdd(uint32 entry, float x, float y, float z, float o)
    {
        if (!m_creature->IsInCombat() && !m_creature->IsDead())
            return;

        if (Creature *pCreature = m_creature->SummonCreature(entry, x, y, z, o, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 420000))
        {
            pCreature->SetCorpseDelay(10);
            if (gatesOpened)
            {
                pCreature->SetInCombatWithZone();
                return;
            }

            MapRefManager const&  lPlayers = m_pInstance->GetMap()->GetPlayers();
            for (auto& playerRef : lPlayers)
            {
                Player* p = playerRef.getSource();
                {
                    bool isRightSide = m_pInstance->IsInRightSideGothArea(p);
                    switch (entry)
                    {
                        case NPC_UNREL_RIDER:
                        case NPC_UNREL_DEATH_KNIGHT:
                        case NPC_UNREL_TRAINEE:
                            if (isRightSide)
                            {
                                pCreature->SetInCombatWith(p);
                                pCreature->AddThreat(p, 100);
                            }
                            break;
                        case NPC_SPECT_DEATH_KNIGTH:
                        case NPC_SPECT_HORSE:
                        case NPC_SPECT_RIDER:
                        case NPC_SPECT_TRAINEE:
                            if (!isRightSide)
                            {
                                pCreature->SetInCombatWith(p);
                                pCreature->AddThreat(p, 100);
                            }
                            break;
                    }
                }
            }

            if (Unit* pTar = pCreature->SelectAttackingTarget(ATTACKING_TARGET_NEAREST, 0))
            {
                pCreature->AI()->AttackStart(pTar);
            }
        }
    }

    void SummonAdds(bool bRightSide, uint32 uiSummonEntry)
    {
        std::list<Creature*> lSummonList;
        m_pInstance->GetGothSummonPointCreatures(lSummonList, bRightSide);

        if (lSummonList.empty())
            return;

        lSummonList.sort(ObjectDistanceOrder(m_creature));
        std::list<Creature*>::iterator itr = lSummonList.begin();

        switch (uiSummonEntry)
        {
            case NPC_UNREL_DEATH_KNIGHT:
                SummonAdd(uiSummonEntry, (*itr)->GetPositionX(), (*itr)->GetPositionY(), (*itr)->GetPositionZ(), (*itr)->GetOrientation());
                itr = lSummonList.end();--itr;
                SummonAdd(uiSummonEntry, (*itr)->GetPositionX(), (*itr)->GetPositionY(), (*itr)->GetPositionZ(), (*itr)->GetOrientation());
                break;
            case NPC_UNREL_TRAINEE:
                SummonAdd(uiSummonEntry, (*itr)->GetPositionX(), (*itr)->GetPositionY(), (*itr)->GetPositionZ(), (*itr)->GetOrientation());
                ++itr;
                SummonAdd(uiSummonEntry, (*itr)->GetPositionX(), (*itr)->GetPositionY(), (*itr)->GetPositionZ(), (*itr)->GetOrientation());
                ++itr;
                ++itr;
                SummonAdd(uiSummonEntry, (*itr)->GetPositionX(), (*itr)->GetPositionY(), (*itr)->GetPositionZ(), (*itr)->GetOrientation());
                break;
            case NPC_UNREL_RIDER:
                ++itr;
                SummonAdd(uiSummonEntry, (*itr)->GetPositionX(), (*itr)->GetPositionY(), (*itr)->GetPositionZ(), (*itr)->GetOrientation());
                break;
        }
    }

    void SummonedCreatureJustDied(Creature* pSummoned) override
    {
        if (!m_pInstance)
            return;

        switch (pSummoned->GetEntry())
        {
            case NPC_SPECT_DEATH_KNIGTH:
            case NPC_SPECT_HORSE:
            case NPC_SPECT_RIDER:
            case NPC_SPECT_TRAINEE:
                return;
        }

        Creature* pAnchor = m_pInstance->GetClosestAnchorForGoth(pSummoned, true);

        if (!pAnchor)
            return;

        Creature* pTempTrigger = m_creature->SummonCreature(
            NPC_SUB_BOSS_TRIGGER,
            pSummoned->GetPositionX(),
            pSummoned->GetPositionY(),
            pSummoned->GetPositionZ(),
            pSummoned->GetOrientation(),
            TEMPSUMMON_TIMED_DESPAWN,
            15000);

        if (!pTempTrigger)
            return;

        // Wrong caster, it expected to be pSummoned.
        // Mangos deletes the spell event at caster death, so for delayed spell like this
        // it's just a workaround. Does not affect other than the visual though (+ spell takes longer to "travel")
        // Elysium: we use a temp creature to handle this issue
        switch (pSummoned->GetEntry())
        {
            case NPC_UNREL_TRAINEE:
                pTempTrigger->CastSpell(pAnchor, SPELL_A_TO_ANCHOR_1, true, nullptr, nullptr, pSummoned->GetGUID());
                break;
            case NPC_UNREL_DEATH_KNIGHT:
                pTempTrigger->CastSpell(pAnchor, SPELL_B_TO_ANCHOR_1, true, nullptr, nullptr, pSummoned->GetGUID());
                break;
            case NPC_UNREL_RIDER:
                pTempTrigger->CastSpell(pAnchor, SPELL_C_TO_ANCHOR_1, true, nullptr, nullptr, pSummoned->GetGUID());
                break;
        }
    }

    void OpenTheGate()
    {
        if (gatesOpened) return;

        DoScriptText(EMOTE_GATE, m_creature);

        gatesOpened = true;
        if (GameObject* pGO = m_pInstance->GetSingleGameObjectFromStorage(GO_MILI_GOTH_COMBAT_GATE))
            pGO->SetGoState(GO_STATE_ACTIVE);
        
        std::list<Creature*> allAdds;
        GetCreatureListWithEntryInGrid(allAdds, m_creature,
        { NPC_UNREL_TRAINEE, NPC_UNREL_DEATH_KNIGHT, NPC_UNREL_RIDER, NPC_SPECT_TRAINEE, NPC_SPECT_DEATH_KNIGTH, NPC_SPECT_RIDER, NPC_SPECT_HORSE },
            300.0f);
        for (Creature* pC : allAdds)
        {
            pC->SetInCombatWithZone();
        }
    }

    bool IsAllPlayersOneSide()
    {
        MapRefManager const&  lPlayers = m_pInstance->GetMap()->GetPlayers();
        uint32 num_left = 0;
        uint32 num_right = 0;
        for (auto& playerRef : lPlayers)
        {
            if (Player const* p = playerRef.getSource())
            {
                // Don't count dead players, except those feigned
                if (p->IsDead() && !p->HasAura(SPELL_AURA_FEIGN_DEATH))
                    continue;

                if(m_pInstance->IsInRightSideGothArea(p))
                    ++num_right;
                else
                    ++num_left;
            }
        }
        // if there are less than 10 people on one of the sides we consider it as
        // "everyone is on the same side". That to avoid the whole raid afking on spectral
        // side, waiting for gothik to TP down, in which case they have 40 sec to kill him
        // before the gates would ordinarily open.
        return (num_left < 1 || num_right < 1);
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if(!m_creature->HasAura(SPELL_IMMUNE_ALL))
        {
            if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
                return;
            if (!m_pInstance->HandleEvadeOutOfHome(m_creature))
                return;
        }
        else
        {
            if (m_creature->GetThreatManager().isThreatListEmpty())
            {
                EnterEvadeMode();
            }
        }

        switch (m_uiPhase)
        {
            case PHASE_SPEECH:
            {
                if (m_uiSpeechTimer < uiDiff)
                {
                    m_uiSpeechTimer = 5000;
                    ++m_uiSpeechCount;

                    switch (m_uiSpeechCount)
                    {
                        case 1:
                            DoScriptText(SAY_SPEECH_2, m_creature);
                            break;
                        case 2:
                            DoScriptText(SAY_SPEECH_3, m_creature);
                            break;
                        case 3:
                            DoScriptText(SAY_SPEECH_4, m_creature);
                            break;
                        case 4:
                            m_uiPhase = PHASE_BALCONY;
                            break;
                    }
                }
                else
                    m_uiSpeechTimer -= uiDiff;

                break;
            }
            case PHASE_BALCONY:
            {
                if (m_uiSummonTimer < uiDiff)
                {
                    if (m_uiSummonCount >= MAX_WAVES)
                    {
                        DoScriptText(SAY_TELEPORT, m_creature);
                        DoScriptText(EMOTE_TO_FRAY, m_creature);
                        DoCastSpellIfCan(m_creature, SPELL_TELEPORT_RIGHT);

                        m_bJustTeleported = true;
                        m_creature->SetTempPacified(TELEPORT_PACIFY_TIMER);

                        // opening the gates when TPing down if all players are considered on the same side
                        if (!gatesOpened && IsAllPlayersOneSide())
                            OpenTheGate();

                        if (m_creature->HasAura(SPELL_IMMUNE_ALL))
                            m_creature->RemoveAurasDueToSpell(SPELL_IMMUNE_ALL);
                        m_uiPhase = PHASE_GROUND;
                        return;
                    }

                    // npc, npc, npc, timer
                    static uint32 const auiSummonData[MAX_WAVES][4] =
                    {
                        {NPC_UNREL_TRAINEE, 0, 0, 20000},
                        {NPC_UNREL_TRAINEE, 0, 0, 20000},
                        {NPC_UNREL_TRAINEE, 0, 0, 10000},
                        {NPC_UNREL_DEATH_KNIGHT, 0, 0, 10000},
                        {NPC_UNREL_TRAINEE, 0, 0, 15000},
                        {NPC_UNREL_DEATH_KNIGHT, 0, 0, 5000},
                        {NPC_UNREL_TRAINEE, 0, 0, 20000},
                        {NPC_UNREL_DEATH_KNIGHT, NPC_UNREL_TRAINEE, 0, 10000},
                        {NPC_UNREL_RIDER, 0, 0, 10000},
                        {NPC_UNREL_TRAINEE, 0, 0, 5000},
                        {NPC_UNREL_DEATH_KNIGHT, 0, 0, 15000},
                        {NPC_UNREL_TRAINEE, NPC_UNREL_RIDER, 0, 10000},
                        {NPC_UNREL_DEATH_KNIGHT, 0, 0, 10000},
                        {NPC_UNREL_TRAINEE, 0, 0, 10000},
                        {NPC_UNREL_RIDER, 0, 0, 5000},
                        {NPC_UNREL_DEATH_KNIGHT, 0, 0, 5000},
                        {NPC_UNREL_TRAINEE, 0, 0, 20000},
                        {NPC_UNREL_RIDER, NPC_UNREL_DEATH_KNIGHT, NPC_UNREL_TRAINEE, 50000},
                    };

                    SummonAdds(true, auiSummonData[m_uiSummonCount][0]);

                    if (auiSummonData[m_uiSummonCount][1])
                        SummonAdds(true, auiSummonData[m_uiSummonCount][1]);

                    if (auiSummonData[m_uiSummonCount][2])
                        SummonAdds(true, auiSummonData[m_uiSummonCount][2]);

                    m_uiSummonTimer += auiSummonData[m_uiSummonCount][3] - uiDiff;
                    ++m_uiSummonCount;
                }
                else
                    m_uiSummonTimer -= uiDiff;

                break;
            }
            case PHASE_GROUND:
            {
                // If we just teleported
                if (m_bJustTeleported)
                {
                    m_bRightSide = m_pInstance->IsInRightSideGothArea(m_creature);
                    ResetThreatAndAttackNearestTarget();
                    m_bJustTeleported = false;
                }

                // Prevent units in the other side of the room getting aggro from dots
                if (!gatesOpened)
                {
                    if (Unit* victim = m_creature->GetVictim())
                    {
                        bool unitIsRight = m_pInstance->IsInRightSideGothArea(victim);
                        if ((m_bRightSide && !unitIsRight) || (!m_bRightSide && unitIsRight))
                        {
                            m_creature->GetThreatManager().modifyThreatPercent(victim, -100);
                            m_creature->SelectHostileTarget();
                        }
                    }
                }

                if (!gatesOpened && m_creature->GetHealthPercent() < 30.0f)
                {
                    OpenTheGate();
                }

                // We check if a side has wiped every 1 sec. If it's the case, we open the gates
                if (!gatesOpened && m_checkAllPlayersOneSideTimer < uiDiff)
                {
                    if(IsAllPlayersOneSide())
                        OpenTheGate();
                    m_checkAllPlayersOneSideTimer = 1000;
                }
                else
                    m_checkAllPlayersOneSideTimer -= uiDiff;

                if (m_uiTeleportTimer < uiDiff && !gatesOpened) // stop teleporting after gates open
                {
                    uint32 uiTeleportSpell = m_bRightSide ? SPELL_TELEPORT_LEFT : SPELL_TELEPORT_RIGHT;
                        
                    if (DoCastSpellIfCan(m_creature, uiTeleportSpell) == CAST_OK)
                    {
                        m_uiTeleportTimer = urand(15000, 20000);
                        m_uiShadowboltTimer = 1000;
                        m_uiTeleportCastDelay = 300; // delay spell timers for ~2s after teleport (inc pacify)
                        if (++m_uiNumTP >= 4 && !gatesOpened)
                            OpenTheGate();

                        // Clear the target and temporarily pacify after the teleport
                        m_creature->ClearTarget();
                        m_creature->StopMoving();
                        m_creature->GetMotionMaster()->Clear();
                        m_creature->SetTempPacified(TELEPORT_PACIFY_TIMER);
                        m_bJustTeleported = true;
                        return;
                    }
                }
                else 
                {
                    m_uiTeleportTimer -= std::min(m_uiTeleportTimer, uiDiff);
                }

                // Delay any other casts if they will occur within 3 seconds of the teleport.
                // We need this to avoid a client issue where the teleport animation will
                // break and Gothik will slow walk to the teleport location. This is in place
                // of having proper recovery times on spells to prevent casts occuring too
                // close to one another
                if (!gatesOpened && m_uiTeleportTimer <= 3000)
                    m_uiTeleportCastDelay = 3000;

                if (m_uiTeleportCastDelay <= uiDiff)
                {
                    if (m_uiShadowboltTimer <= uiDiff)
                    {
                        if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0, SPELL_SHADOWBOLT, SELECT_FLAG_IN_LOS))
                        {
                            if (DoCastSpellIfCan(pTarget, SPELL_SHADOWBOLT) == CAST_OK)
                            {
                                m_uiShadowboltTimer = urand(1600, 2000);
                            }
                        }
                    }
                    else
                        m_uiShadowboltTimer -= uiDiff;

                    if (m_uiHarvestSoulTimer <= uiDiff)
                    {
                        if (DoCastSpellIfCan(m_creature, SPELL_HARVESTSOUL) == CAST_OK)
                        {
                            m_uiHarvestSoulTimer = 20000;
                            if (m_uiTeleportTimer <= 1000)
                                m_uiTeleportTimer += 1200;
                        }
                    }
                    else
                        m_uiHarvestSoulTimer -= uiDiff;
                }
                else
                    m_uiTeleportCastDelay -= uiDiff;

                DoMeleeAttackIfReady();
                break;
            }
        }
    }

    void ResetThreatAndAttackNearestTarget()
    {
        DoResetThreat();
        if (Unit* pNearest = m_creature->SelectAttackingTarget(ATTACKING_TARGET_NEAREST, 0, nullptr, SELECT_FLAG_IN_LOS))
        {
            AttackStart(pNearest);
            m_creature->AddThreat(pNearest, 300.0f);
        }
    }
};

CreatureAI* GetAI_boss_gothik(Creature* pCreature)
{
    return new boss_gothikAI(pCreature);
}

bool EffectDummyCreature_spell_anchor(WorldObject* /*pCaster*/, uint32 uiSpellId, SpellEffectIndex uiEffIndex, Creature* pCreatureTarget)
{
    if (uiEffIndex != EFFECT_INDEX_0 || pCreatureTarget->GetEntry() != NPC_SUB_BOSS_TRIGGER)
        return true;

    instance_naxxramas* pInstance = (instance_naxxramas*)pCreatureTarget->GetInstanceData();

    if (!pInstance)
        return true;

    switch (uiSpellId)
    {
        case SPELL_A_TO_ANCHOR_1:                           // trigger mobs at high right side
        case SPELL_B_TO_ANCHOR_1:
        case SPELL_C_TO_ANCHOR_1:
        {
            if (Creature* pAnchor2 = pInstance->GetClosestAnchorForGoth(pCreatureTarget, false))
            {
                uint32 uiTriggered = SPELL_A_TO_ANCHOR_2;

                if (uiSpellId == SPELL_B_TO_ANCHOR_1)
                    uiTriggered = SPELL_B_TO_ANCHOR_2;
                else if (uiSpellId == SPELL_C_TO_ANCHOR_1)
                    uiTriggered = SPELL_C_TO_ANCHOR_2;

                pCreatureTarget->CastSpell(pAnchor2, uiTriggered, true);
            }

            return true;
        }
        case SPELL_A_TO_ANCHOR_2:                           // trigger mobs at high left side
        case SPELL_B_TO_ANCHOR_2:
        case SPELL_C_TO_ANCHOR_2:
        {
            std::list<Creature*> lTargets;
            pInstance->GetGothSummonPointCreatures(lTargets, false);

            if (!lTargets.empty())
            {
                std::list<Creature*>::iterator itr = lTargets.begin();
                uint32 uiPosition = urand(0, lTargets.size() - 1);
                advance(itr, uiPosition);

                if (Creature* pTarget = (*itr))
                {
                    uint32 uiTriggered = SPELL_A_TO_SKULL;

                    if (uiSpellId == SPELL_B_TO_ANCHOR_2)
                        uiTriggered = SPELL_B_TO_SKULL;
                    else if (uiSpellId == SPELL_C_TO_ANCHOR_2)
                        uiTriggered = SPELL_C_TO_SKULL;

                    pCreatureTarget->CastSpell(pTarget, uiTriggered, true);
                }
            }
            return true;
        }
        case SPELL_A_TO_SKULL:                              // final destination trigger mob
        case SPELL_B_TO_SKULL:
        case SPELL_C_TO_SKULL:
        {
            if (Creature* pGoth = pInstance->GetSingleCreatureFromStorage(NPC_GOTHIK))
            {
                uint32 uiNpcEntry = NPC_SPECT_TRAINEE;

                if (uiSpellId == SPELL_B_TO_SKULL)
                    uiNpcEntry = NPC_SPECT_DEATH_KNIGTH;
                else if (uiSpellId == SPELL_C_TO_SKULL)
                    uiNpcEntry = NPC_SPECT_RIDER;

                ((boss_gothikAI*)pGoth->AI())->SummonAdd(uiNpcEntry, pCreatureTarget->GetPositionX(), pCreatureTarget->GetPositionY(), pCreatureTarget->GetPositionZ(), pCreatureTarget->GetOrientation());

                if (uiNpcEntry == NPC_SPECT_RIDER)
                    ((boss_gothikAI*)pGoth->AI())->SummonAdd(NPC_SPECT_HORSE, pCreatureTarget->GetPositionX(), pCreatureTarget->GetPositionY(), pCreatureTarget->GetPositionZ(), pCreatureTarget->GetOrientation());
            }
            return true;
        }
    }

    return true;
};

struct gothikTriggerAI : public ScriptedAI
{
    gothikTriggerAI(Creature* pCreature) : ScriptedAI(pCreature) { }

    void Reset() override 
    {
        m_creature->SetWanderDistance(0.01f);
        m_creature->SetDefaultMovementType(RANDOM_MOTION_TYPE);
        m_creature->GetMotionMaster()->Initialize();
    }

    void MoveInLineOfSight(Unit*) override { }
    void Aggro(Unit*) override { }
    void AttackStart(Unit*) override { }
    void UpdateAI(uint32 const diff) override { }
};

CreatureAI* GetAI_GothikTrigger(Creature* pCreature)
{
    return new gothikTriggerAI(pCreature);
}

void AddSC_boss_gothik()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "boss_gothik";
    newscript->GetAI = &GetAI_boss_gothik;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "spell_anchor";
    newscript->pEffectDummyCreature = &EffectDummyCreature_spell_anchor;
    newscript->GetAI = &GetAI_GothikTrigger;

    newscript->RegisterSelf();
}
