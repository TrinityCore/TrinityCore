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
SDName: Boss_Maexxna
SD%Complete:
SDComment: 
SDCategory: Naxxramas
EndScriptData */

#include "scriptPCH.h"
#include "naxxramas.h"
#include <random>
#include <algorithm>
#include <array>

enum MaexxnaData
{
    EMOTE_BOSS_GENERIC_ENRAGE   = 2384,

    SPELL_WEBWRAP               = 28622,    

    SPELL_WEBSPRAY              = 29484,
    SPELL_POISONSHOCK           = 28741,
    SPELL_NECROTICPOISON        = 28776,    // 90% reduced healing. Dispelllable
    SPELL_ENRAGE                = 28747,    // 30% enrage

    SPELL_SUMMON_SPIDERLING     = 29434,

    SPELL_DOUBLE_ATTACK = 19818,            // seems it adds an aura, must be removed manually?

    //SPELL_WEBWRAP = 28622,
    SPELL_WEBWRAP_2 = 28673,                // does an attack animation, purpose unknown

    NPC_WEB_WRAP = 16486,
    NPC_SPIDERLING = 17055,

    // SPELL_SUMMON_SPIDERLING_1 = 29434,                   // works.
    // SPELL_SUMMON_SPIDERLING_2 = 30076,                   // works

    SPELL_SUMMON_WEB_WRAP     = 28627,
    /*
    SPELL_WEB_WRAP_UNKNOWN   = 28617,
    SPELL_WEB_WRAP_1         = 28618,
    SPELL_WEB_WRAP_2         = 28619,
    SPELL_WEB_WRAP_3         = 28620,
    SPELL_WEB_WRAP_4         = 28621,
    SPELL_WEB_WRAP_TRIGGERED = 28622, //triggered by SPELL_WEB_WRAP_1-4
    SPELL_CLEAR_WEB_WRAP     = 28628,
    SPELL_CLEAR_WEB_WRAP     = 28629,
    */

    MAX_SPIDERLINGS         = 10, // 8 in cmangos, should be 10 
    MAX_WEB_WRAP_POSITIONS  = 3
};

static float WebWrapCooldown(bool initial = false)            { return initial ? 20000 : 40000; }
static float SummonSpiderlingsCooldown(bool initial = false)  { return initial ? 30000 : 40000; }
static float WebSprayCooldown(bool initial = false)           { return initial ? 40000 : 40000; }
static float PoisonShockCooldown(bool initial = false)        { return urand(9000,11000); }
static float NecroticPoisonCooldown(bool initial = false)     { return initial ? 15000 : urand(5000, 10000); } 

struct mob_webwrapAI : public ScriptedAI
{
    mob_webwrapAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset(); 
    }

    ObjectGuid m_victimGuid;
    uint32 m_uiWebWrapTimer;
    bool webWrapDone;

    void Reset() override
    {
        m_uiWebWrapTimer = 0;
        webWrapDone = false;
    }

    void MoveInLineOfSight(Unit* /*pWho*/) override { }
    void AttackStart(Unit* /*pWho*/) override { }

    void SetVictim(Unit* pVictim)
    {
        if (!pVictim || pVictim->GetTypeId() != TYPEID_PLAYER)
        {
            sLog.outError("mob_webwrapAI::SetVictim called for non-player");
            return;
        }

        pVictim->AddAura(SPELL_SUMMON_WEB_WRAP);
        m_victimGuid = pVictim->GetObjectGuid();
        m_creature->GetMotionMaster()->MovePoint(0, pVictim->GetPositionX(), pVictim->GetPositionY(), pVictim->GetPositionZ(),
            MOVE_FLY_MODE | MOVE_CYCLIC, 0.0f, 0);
    }

    void JustDied(Unit* /*pKiller*/) override
    {
        if (m_victimGuid)
        {
            if (Player* pVictim = m_creature->GetMap()->GetPlayer(m_victimGuid))
            {
                if (pVictim->IsAlive())
                {
                    pVictim->RemoveAurasDueToSpell(SPELL_WEBWRAP);
                    pVictim->RemoveAurasDueToSpell(SPELL_SUMMON_WEB_WRAP);
                }
            }
        }
        ((TemporarySummon*)m_creature)->UnSummon();
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_victimGuid)
            return;

        Player* pVictim = m_creature->GetMap()->GetPlayer(m_victimGuid);
        if (!pVictim || pVictim->IsDead())
        {
            m_creature->Kill(m_creature, nullptr);
            // ((TemporarySummon*)m_creature)->UnSummon();
            return;
        }
        // todo: can this be removed? We set MovePoint in SetVictim
        /*
        m_creature->GetMotionMaster()->MovePoint(0, pVictim->GetPositionX(), pVictim->GetPositionY(), pVictim->GetPositionZ(),
            MOVE_FLY_MODE|MOVE_CYCLIC, 0.0f, 0);
        */
    }
};

struct boss_maexxnaAI : public ScriptedAI
{
    boss_maexxnaAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (instance_naxxramas*)pCreature->GetInstanceData();
        Reset();
    }
    instance_naxxramas* m_pInstance;

    uint32 m_uiWebWrapTimer;
    uint32 m_uiWebSprayTimer;
    uint32 m_uiPoisonShockTimer;
    uint32 m_uiNecroticPoisonTimer;
    uint32 m_uiSummonSpiderlingTimer;
    bool m_bEnraged;
    std::random_device m_randDevice;
    std::mt19937 m_random { m_randDevice() };

    std::vector<std::pair<uint32, ObjectGuid>> wraps;
    std::vector<std::pair<uint32, ObjectGuid>> wraps2;

    // todo: only aproximate coordinates. Might be good enough,
    // but should be double-checked.
    std::vector<std::array<float,3>> wepWrapLoc =
    {
        {3562.40f, -3890.35f, 314.30f},
        {3560.78f, -3878.10f, 316.18f},
        {3554.95f, -3863.24f, 314.46f},
        {3549.02f, -3855.07f, 311.58f},
        {3538.34f, -3844.68f, 314.21f},
        {3526.43f, -3838.73f, 317.10f},
        {3507.84f, -3832.71f, 319.00f},
        {3493.35f, -3834.06f, 318.71f}
    };

    void Reset() override
    {
        m_uiWebWrapTimer = WebWrapCooldown(true);
        m_uiWebSprayTimer = WebSprayCooldown(true);
        m_uiPoisonShockTimer = PoisonShockCooldown(true);
        m_uiNecroticPoisonTimer = NecroticPoisonCooldown(true);
        m_uiSummonSpiderlingTimer = SummonSpiderlingsCooldown(true);
        m_bEnraged = false;
        wraps.clear();
        wraps2.clear();
    }

    void Aggro(Unit* pWho) override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_MAEXXNA, IN_PROGRESS);
    }

    void JustDied(Unit* pKiller) override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_MAEXXNA, DONE);
    }

    void MoveInLineOfSight(Unit* pWho) override 
    {
        if (!m_creature->IsWithinDistInMap(pWho, 40.0f))
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
    
    void JustReachedHome() override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_MAEXXNA, FAIL);
        std::list<Creature*> spiderlings;
        GetCreatureListWithEntryInGrid(spiderlings, m_creature, NPC_SPIDERLING, 100.0f);
        for (Creature* pSpider : spiderlings)
            pSpider->DeleteLater();
    }
    
    bool DoCastWebWrap()
    {
        ThreatList const& tList = m_creature->GetThreatManager().getThreatList();
        if (tList.size() < 2)
            return false;

        std::list<Player*> candidates;
        ThreatList::const_iterator it = tList.begin();
        ++it;
        for (it; it != tList.end(); ++it)
        {
            Player* pPlayer = m_creature->GetMap()->GetPlayer((*it)->getUnitGuid());
            if (!pPlayer) continue;

            // todo: verify that IsWithinLOSInMap does not screw anyting up. Afaik there should be nowhere
            // to los in maexxnas room, so would only stop us from selecting players outside the room, which is good.
            if (pPlayer->IsAlive() && !pPlayer->IsGameMaster()
                && m_creature->IsWithinLOSInMap(pPlayer)        // Only players in the room
                && !pPlayer->HasAura(SPELL_WEBWRAP))            // Don't retarget players who are still wrapped
            {
                candidates.push_back(pPlayer);
            }
        }

        if (candidates.empty())
            return false;

        std::shuffle(wepWrapLoc.begin(), wepWrapLoc.end(), m_random);

        for (int i = 0; i < 3; i++)
        {
            if (candidates.empty())
                break;
            auto candIt = candidates.begin();

            if(candidates.size() > 1)
                std::advance(candIt, urand(0, candidates.size() - 1));

            Unit* pTarget = *candIt;
            candIt = candidates.erase(candIt);

            float dx = pTarget->GetPositionX() - wepWrapLoc[i][0];
            float dy = pTarget->GetPositionY() - wepWrapLoc[i][1];
            float dist = sqrt((dx * dx) + (dy * dy));
            float yDist = wepWrapLoc[i][2] - pTarget->GetPositionZ();

            // todo: to avoid ever hitting the overhanging ceiling we would need to adjust the horizontal
            // velocity based on how close we are to it. If we are close initially, reduce the travel-time
            // by increasing horizontal velocity, in which case we won't need as much vertical velocity, thus
            // won't hit the ceiling.
            //s=ut+(0.5a*t^2) || s = vertical speed, u = initial up velocity, a = gravity factor(negative), t = time of flight
            // sadly this only aproximates some parts of this formula
            float horizontalSpeed = dist/1.5f;
            float verticalSpeed = 20.0f + (yDist*0.5f);
            float angle = pTarget->GetAngle(wepWrapLoc[i][0], wepWrapLoc[i][1]);

            // set immune anticheat and calculate speed
            if (Player* plr = pTarget->ToPlayer())
            {
                plr->SetLaunched(true);
                plr->SetXYSpeed(horizontalSpeed);
            }

            pTarget->KnockBack(angle, horizontalSpeed, verticalSpeed);
            wraps.push_back(std::make_pair(uint32(2000), pTarget->GetObjectGuid()));
        }

        return true;
    }

    void JustSummoned(Creature* pSummoned) override
    {
        if (pSummoned->GetEntry() == NPC_SPIDERLING)
        {
            if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
            {
                pSummoned->AddThreat(pTarget, 100);
                pSummoned->AI()->AttackStart(pTarget);
            }
        }
    }

    void UpdateWraps(uint32 const uiDiff)
    {
        bool wdone = false;
        for (auto& p : wraps2)
        {
            if (p.first < uiDiff)
            {
                if (Player* pl = m_pInstance->GetMap()->GetPlayer(p.second))
                {
                    if (Creature* pC = pl->SummonCreature(NPC_WEB_WRAP, pl->GetPositionX(), pl->GetPositionY(), pl->GetPositionZ(), 0, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 57000))
                    {
                        if (mob_webwrapAI* pcAI = (mob_webwrapAI*)pC->AI())
                        {
                            pcAI->SetVictim(pl);
                        }
                    }
                }
                wdone = true;
            }
            else
                p.first -= uiDiff;
        }

        if (wdone)
            wraps2.clear();

        wdone = false;
        for (auto& p : wraps)
        {
            if (p.first < uiDiff)
            {
                if (Player* pl = m_pInstance->GetMap()->GetPlayer(p.second))
                {
                    pl->CastSpell(pl, 28622, true);
                    wraps2.push_back(std::make_pair(3000, p.second));
                }
                wdone = true;
            }
            else
                p.first -= uiDiff;
        }
        if (wdone)
            wraps.clear();
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        UpdateWraps(uiDiff);

        // Web Wrap
        if (m_uiWebWrapTimer < uiDiff)
        {
            DoCastWebWrap();    // probably no point checking if successfull.*
            m_uiWebWrapTimer = WebWrapCooldown();
        }
        else
            m_uiWebWrapTimer -= uiDiff;
        
        // Web Spray
        if (m_uiWebSprayTimer < uiDiff)
        {
            if(DoCastSpellIfCan(m_creature->GetVictim(), SPELL_WEBSPRAY) == CAST_OK)
                m_uiWebSprayTimer = WebSprayCooldown();
        }
        else
            m_uiWebSprayTimer -= uiDiff;

        // Poison Shock
        if (m_uiPoisonShockTimer < uiDiff)
        {
            if(DoCastSpellIfCan(m_creature->GetVictim(), SPELL_POISONSHOCK) == CAST_OK)
                m_uiPoisonShockTimer = PoisonShockCooldown();
        }
        else
            m_uiPoisonShockTimer -= uiDiff;

        // Necrotic Poison
        if (m_uiNecroticPoisonTimer < uiDiff)
        {
            if(DoCastSpellIfCan(m_creature->GetVictim(), SPELL_NECROTICPOISON) == CAST_OK)
                m_uiNecroticPoisonTimer = NecroticPoisonCooldown();
        }
        else
            m_uiNecroticPoisonTimer -= uiDiff;

        // Summon Spiderling
        if (m_uiSummonSpiderlingTimer < uiDiff)
        {
            if(DoCastSpellIfCan(m_creature, SPELL_SUMMON_SPIDERLING) == CAST_OK)
                m_uiSummonSpiderlingTimer = SummonSpiderlingsCooldown();
        }
        else
            m_uiSummonSpiderlingTimer -= uiDiff;

        //Enrage if not already enraged and below 30%
        if (!m_bEnraged && m_creature->GetHealthPercent() < 30.0f)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_ENRAGE) == CAST_OK)
            {
                m_bEnraged = true;
                DoScriptText(EMOTE_BOSS_GENERIC_ENRAGE, m_creature);
            }
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_mob_webwrap(Creature* pCreature)
{
    return new mob_webwrapAI(pCreature);
}

CreatureAI* GetAI_boss_maexxna(Creature* pCreature)
{
    return new boss_maexxnaAI(pCreature);
}

void AddSC_boss_maexxna()
{
    Script* NewScript;

    NewScript = new Script;
    NewScript->Name = "boss_maexxna";
    NewScript->GetAI = &GetAI_boss_maexxna;
    NewScript->RegisterSelf();

    NewScript = new Script;
    NewScript->Name = "mob_webwrap";
    NewScript->GetAI = &GetAI_mob_webwrap;
    NewScript->RegisterSelf();
}
