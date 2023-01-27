/* This file is part of the ScriptDev2 Project. See AUTHORS file for Copyright information
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
SDName: Boss_Thaddius
SD%Complete: 
SDComment: 
SDCategory: 
EndScriptData */

/* ContentData
boss_thaddius
npc_tesla_coil
boss_stalagg
boss_feugen
EndContentData */

#include "scriptPCH.h"
#include "naxxramas.h"
#include <random>
#include <algorithm>

enum eStalaggFeugen
{
    // Stalagg
    SAY_STAL_AGGRO          = 13083,
    SAY_STAL_SLAY           = 13085,
    SAY_STAL_DEATH          = 13084,

    // Feugen
    SAY_FEUG_AGGRO          = 13023,
    SAY_FEUG_SLAY           = 13025,
    SAY_FEUG_DEATH          = 13024,

    SPELL_WARSTOMP          = 28125,
    SPELL_FLASH             = 28127, // TODO: stun spell supposedly used by feugen? Cant find any sources for it
    SPELL_POWERSURGE        = 28134,
    SPELL_STATIC_FIELD      = 28135,
    SPELL_MAGNETIC_PULL     = 28337
};

enum addEvents
{
    EVENT_WARSTOMP = 1,
    EVENT_STATIC_FIELD,
    EVENT_POWERSURGE,
    EVENT_MAGNETIC_PULL
};

enum eThaddius
{
    SAY_AGGRO_1 = 13086,
    SAY_AGGRO_2 = 13087,
    SAY_AGGRO_3 = 13088,

    SAY_SLAY    = 13096,
    SAY_ELECT   = 13090,
    SAY_DEATH   = 13089,

    SPELL_THADIUS_SPAWN             = 28160,
    SPELL_THADIUS_LIGHTNING_VISUAL  = 28136,
    SPELL_BALL_LIGHTNING            = 28299,
    SPELL_CHAIN_LIGHTNING           = 28167,
    SPELL_BESERK                    = 27680,

    SPELL_POLARITY_SHIFT            = 28089,

    SPELL_POSITIVE_CHARGE_APPLY     = 28059,
    SPELL_POSITIVE_CHARGE_TICK      = 28062,
    SPELL_POSITIVE_CHARGE_AMP       = 29659,

    SPELL_NEGATIVE_CHARGE_APPLY     = 28084,
    SPELL_NEGATIVE_CHARGE_TICK      = 28085,
    SPELL_NEGATIVE_CHARGE_AMP       = 29660
};  

enum eCoils
{
    EMOTE_LOSING_LINK = 12156, // not sure if existed in vanilla
    EMOTE_TESLA_OVERLOAD = 12178, // confirmed existed in vanilla

    SPELL_FEUGEN_CHAIN = 28111,
    SPELL_STALAGG_CHAIN = 28096,
    SPELL_FEUGEN_TESLA_PASSIVE = 28109,
    SPELL_STALAGG_TESLA_PASSIVE = 28097,
    SPELL_SHOCK_OVERLOAD = 28159,
    SPELL_SHOCK = 28099
};

enum eStalagFeugen
{
    eSTALAGG = 0,
    eFEUGEN = 1
};

enum ThaddiusPhase
{
    THAD_NOT_STARTED,
    THAD_PHASE1,
    THAD_TRANSITION,
    THAD_PHASE2
};

enum thaddiusEvents
{
    EVENT_SHIFT = 1,                // polarity shift
    EVENT_SHIFT_TALK,               // polarity shift yell (hack? couldn't find any event for cast finish)
    EVENT_CHAIN,                    // chain lightning
    EVENT_BERSERK,                  // enrage timer
    EVENT_REVIVE_FEUGEN,            // timer until feugen is revived (if stalagg still lives)
    EVENT_REVIVE_STALAGG,           // timer until stalagg is revived (if feugen still lives)
    EVENT_TRANSITION_1,             // timer until overload emote
    EVENT_TRANSITION_2,             // timer until thaddius gets zapped by the coils
    EVENT_TRANSITION_3,             // timer until thaddius engages
    EVENT_ENABLE_BALL_LIGHTNING,    // grace period after thaddius aggro after which he starts being a baller (e.g. tossing ball lightning at out of range targets)

    EVENT_POLARITY_CHANGE
};

//static constexpr uint32 ADDS_RESPAWN_TIMER = 5000;      // adds respawn after 5 sec if not both area killed in that window.

static constexpr uint32 ENRAGE_TIMER = 1000 * 60 * 5;   // 5 min enrage once p2 starts

                                                        // Initial polarity shift is 10s, after that every 30 sec
static uint32 PolarityShiftTimer(bool initial = false) { return initial ? 1000 * 10 : 1000 * 30; }

                                                        // Chain lightning timer. TODO: confirm timers. Atm is guess
static uint32 ChainLightningTimer() { return urand(5000, 7000); } 

static constexpr float addPositions[2][4] =
{
    { 3449.03f, -2934.74f, 312.18f, 5.41f },
    { 3508.85f, -2994.08f, 312.18f, 2.33f },
};
static constexpr float teslaCoilPositions[2][3] =
{
    //{ 3487.76f, -2911.2f, 319.406f },
    { 3487.10f, -2911.50f, 319.526f },
    { 3527.81f, -2952.38f, 319.526f }
};

struct npc_tesla_coilAI : public Scripted_NoMovementAI
{
    npc_tesla_coilAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
    {
        m_pInstance = (instance_naxxramas*)pCreature->GetInstanceData();
        Reset();
    }

    instance_naxxramas* m_pInstance;
    bool m_bToFeugen;
    ObjectGuid m_guid;
    uint32 shockTimer;
    bool hadLink;

    void Reset() override
    {
        m_creature->SetWanderDistance(0.01f);
        m_creature->SetDefaultMovementType(RANDOM_MOTION_TYPE);
        m_creature->GetMotionMaster()->Initialize();
        shockTimer = 0;
        hadLink = true;
    }

    void MoveInLineOfSight(Unit* /*pWho*/) override { }

    void Aggro(Unit* /*pWho*/) override
    {
        //m_creature->SetInCombatWithZone();
    }

    void ReApplyChain(uint32 uiEntry, ObjectGuid guid)
    {
        m_guid = guid;
        if (uiEntry == NPC_FEUGEN)
            m_bToFeugen = true;
        else if (uiEntry == NPC_STALAGG)
            m_bToFeugen = false;
        else
            sLog.outError("npc_tesla_coilAI::ReApplyChain got entry which was not stalagg or feugen.");

        DoCastSpellIfCan(m_creature, m_bToFeugen ? SPELL_FEUGEN_CHAIN : SPELL_STALAGG_CHAIN);
    }
 
    void UpdateAI(uint32 const uiDiff) override
    {
        if (Creature* add = m_pInstance->GetCreature(m_guid))
        {
            if (add->IsInCombat() && !m_creature->IsInCombat())
            {
                m_creature->SetInCombatWithZone();
            }

            if (m_creature->GetDistance2d(add) > 60.0f)
            {
                m_creature->InterruptNonMeleeSpells(true);
                //if (add->HasAura(m_bToFeugen ? SPELL_FEUGEN_CHAIN : SPELL_STALAGG_CHAIN))
                if(hadLink)
                    DoScriptText(EMOTE_LOSING_LINK, m_creature);
                hadLink = false;

                if (shockTimer < uiDiff)
                {
                    shockTimer = 1500;
                    // todo: not sure if should target nearest or random target
                    if (Unit* shockTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_NEAREST, 0, nullptr, SELECT_FLAG_PLAYER))
                    {
                        m_creature->CastSpell(shockTarget, SPELL_SHOCK, true);
                    }
                }
                else
                    shockTimer -= uiDiff;
            }
            else
            {
                shockTimer = 0;
                if (!m_creature->IsNonMeleeSpellCasted(true))
                    DoCastSpellIfCan(m_creature, m_bToFeugen ? SPELL_FEUGEN_CHAIN : SPELL_STALAGG_CHAIN);
                hadLink = true;
            }
        }
    }
};

struct boss_thaddiusAddsAI : public ScriptedAI
{
    boss_thaddiusAddsAI(Creature* pCreature, eStalagFeugen sOrF) : ScriptedAI(pCreature), m_SorF(sOrF)
    {
        m_pInstance = (instance_naxxramas*)pCreature->GetInstanceData();
        Reset();
    }

    instance_naxxramas* m_pInstance;
    eStalagFeugen m_SorF;
    bool m_bFakeDeath;
    uint32 fakeDeathTimer;
    bool bothDeath;
    uint32 timeSincePull;
    EventMap m_events;
    ObjectGuid otherAdd;

    void Reset() override
    {
        m_events.Reset();
        timeSincePull = 0;
        fakeDeathTimer = 0;
        m_bFakeDeath = false;
        bothDeath = false;

        // We might Reset while faking death, so undo this
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        m_creature->SetHealth(m_creature->GetMaxHealth());
        m_creature->SetStandState(UNIT_STAND_STATE_STAND);
    }

    uint32 WarstompTimer()
    {
        // best guess timer based on 
        // https://www.youtube.com/watch?v=GmE5JufAcT0
        // and https://www.youtube.com/watch?v=3hen_d6cb-Y
        return urand(15000, 20000);
    }
    uint32 PowerSurgeTimer()
    {
        // https://www.youtube.com/watch?v=3hen_d6cb-Y
        // Timer seems correct based on above video
        return urand(25000, 30000);
    }
    uint32 MagneticPullTimer()
    {
        // Every 20 seconds, but from videos can be seen to drift a tiny bit. 
        // guides mention 20.5sec, so lets just make it that.
        return 20500; 
    }
    uint32 StaticFiledTimer()
    {
        //https://www.youtube.com/watch?v=GmE5JufAcT0
        // animation can be seen in video, pretty much exactly every 6 seconds
        return 6000;
    }

    Creature* GetOtherAdd()
    {
        if (!m_pInstance) return nullptr;
        return m_pInstance->GetCreature(otherAdd);
    }

    void Aggro(Unit* pWho) override
    {
        if (m_bFakeDeath)
            return;

        if (!m_pInstance)
            return;

        m_creature->SetInCombatWithZone();
        m_pInstance->SetData(TYPE_THADDIUS, IN_PROGRESS);

        if (Creature* pOtherAdd = GetOtherAdd())
        {
            if (!pOtherAdd->IsInCombat())
                pOtherAdd->AI()->AttackStart(pWho);
        }
    }

    void JustRespawned() override
    {
        Reset();                                            // Needed to reset the flags properly
    }

    void JustReachedHome() override
    {
        if (!m_pInstance)
            return;
        m_events.Reset();
        m_pInstance->SetData(TYPE_THADDIUS, FAIL);
    }

    bool HandleMagneticPull()
    {
        if (m_bFakeDeath)
            return false;

        Unit* myVictim = m_creature->GetVictim();

        if (!myVictim)
            return false;

        Creature* otherAdd = GetOtherAdd();

        if (!otherAdd)
            return false;

        if (boss_thaddiusAddsAI* otherAI = static_cast<boss_thaddiusAddsAI*>(otherAdd->AI()))
        {
            if (otherAI->m_bFakeDeath) return false; // can, presumably, only do it when both are alive
        }
        Unit* otherVictim = otherAdd->GetVictim();

        if (!otherVictim)
            return false;

        ThreatManager& myThreat = m_creature->GetThreatManager();
        ThreatManager& otherThreat = otherAdd->GetThreatManager();

        float myTankThreat = myThreat.getThreat(myVictim);
        float myOtherTankThreat = myThreat.getThreat(otherVictim);

        float otherTankThreat = otherThreat.getThreat(otherVictim);
        float otherAddMyVictimThreat = otherThreat.getThreat(myVictim);
        //todo: VERIFY NEGATIVE THREAT OK
        // set the two entries in feugen's threat table to be equal to the ones in stalagg's
        myThreat.addThreat(otherVictim, otherTankThreat - myOtherTankThreat);
        myThreat.addThreat(myVictim, otherAddMyVictimThreat - myTankThreat);

        // set the two entries in stalagg's threat table to be equal to the ones in feugen's
        otherThreat.addThreat(myVictim, myTankThreat - otherAddMyVictimThreat);
        otherThreat.addThreat(otherVictim, myOtherTankThreat - otherTankThreat);

        m_creature->InterruptNonMeleeSpells(true);
        m_creature->CastSpell(otherVictim, SPELL_MAGNETIC_PULL, true);
        otherAdd->InterruptNonMeleeSpells(true);
        otherAdd->CastSpell(myVictim, SPELL_MAGNETIC_PULL, true);

        // @hack prevent mmaps clusterfucks from breaking tesla while tanks are midair
        // feugen->AddAura(SPELL_ROOT_SELF, feugen);
        // stalagg->AddAura(SPELL_ROOT_SELF, stalagg);

        // and make both attack their respective new tanks
        AttackStart(otherVictim);
        otherAdd->AI()->AttackStart(myVictim);
        return true;
    }

    void HandleReviveEvent()
    {
        Reset();
        DoResetThreat();

        if (Unit* nearestTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_NEAREST, 0))
        {
            Aggro(nearestTarget);
        }
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (m_bFakeDeath)
        {
            if (fakeDeathTimer < uiDiff)
            {
                if(!bothDeath)
                    HandleReviveEvent();
            }
            else
                fakeDeathTimer -= uiDiff;
            return;
        }

        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        timeSincePull += uiDiff;
        m_events.Update(uiDiff);
        while (auto l_EventId = m_events.ExecuteEvent())
        {
            switch (l_EventId)
            {
                case EVENT_WARSTOMP:
                    // need to delay warstomp if we have just done the pull. If warstomp hits midair the
                    // pull effect is cancelled and tanks fall down
                    if (timeSincePull < 5000)
                    {
                        m_events.Repeat(5000 - timeSincePull);
                    }
                    else
                    {
                        if (DoCastSpellIfCan(m_creature, SPELL_WARSTOMP) == CAST_OK)
                            m_events.Repeat(WarstompTimer());
                        else
                            m_events.Repeat(100);
                    }
                    break;
                case EVENT_STATIC_FIELD:
                    if (DoCastSpellIfCan(m_creature, SPELL_STATIC_FIELD) == CAST_OK)
                        m_events.Repeat(StaticFiledTimer());
                    else
                        m_events.Repeat(100);
                    break;  
                case EVENT_POWERSURGE:
                    if (DoCastSpellIfCan(m_creature, SPELL_POWERSURGE) == CAST_OK)
                        m_events.Repeat(PowerSurgeTimer());
                    else
                        m_events.Repeat(100);
                    break;
                case EVENT_MAGNETIC_PULL:
                    if (HandleMagneticPull())
                    {
                        m_events.Repeat(MagneticPullTimer());
                        timeSincePull = 0;
                    }
                    else
                        m_events.Repeat(100);
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

    void AttackStart(Unit* pWho) override
    {
        if (m_bFakeDeath)
            return;
        ScriptedAI::AttackStart(pWho);
    }

    void DamageTaken(Unit* pKiller, uint32& uiDamage) override
    {
        if (uiDamage < m_creature->GetHealth())
            return;

        // Prevent glitch if in fake death
        if (m_bFakeDeath)
        {
            uiDamage = 0;
            return;
        }

        if (Creature* otherAdd = GetOtherAdd())
        {
            if (boss_thaddiusAddsAI* otherAI = static_cast<boss_thaddiusAddsAI*>(otherAdd->AI()))
            {
                if (otherAI->m_bFakeDeath)
                {
                    otherAI->bothDeath = true;
                    bothDeath = true;
                    if (m_pInstance)
                        m_pInstance->SetData(TYPE_THADDIUS, SPECIAL);
                }
            }
        }

        if (m_SorF == eSTALAGG)
            DoScriptText(SAY_STAL_DEATH, m_creature);
        else
            DoScriptText(SAY_FEUG_DEATH, m_creature);

        uiDamage = 0;

        fakeDeathTimer = 5000;
        m_bFakeDeath = true;
        m_creature->InterruptNonMeleeSpells(false);
        m_creature->SetHealth(0);
        m_creature->StopMoving();
        m_creature->ClearComboPointHolders();
        m_creature->RemoveAllAurasOnDeath(); // todo: will this remove the chain?
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        m_creature->ClearAllReactives();
        m_creature->GetMotionMaster()->Clear();
        m_creature->GetMotionMaster()->MoveIdle();
        m_creature->SetStandState(UNIT_STAND_STATE_DEAD);
        m_creature->AttackStop();
    }
};

struct boss_thaddiusAI : public ScriptedAI
{
    boss_thaddiusAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (instance_naxxramas*)pCreature->GetInstanceData();
        Reset();

        if (m_pInstance)
        {
            CheckSpawnAdds();
        }

        // Apply the "stun" aura again, which makes him darker and not moving
        if (!m_creature->HasAura(SPELL_THADIUS_SPAWN))
            m_creature->CastSpell(m_creature, SPELL_THADIUS_SPAWN, true);

        // He is not targetable other than in p2
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
    }

    instance_naxxramas* m_pInstance;

    uint32 m_uiBallLightningTimer;

    ThaddiusPhase m_Phase;
    ObjectGuid addGuids[2];
    ObjectGuid coilGuids[2];
    ObjectGuid stalaggChainCreature;
    ObjectGuid feugenChainCreature;

    EventMap m_events;

    std::random_device m_randDevice;
    std::mt19937 m_random{ m_randDevice() };
    uint32 killSayCooldown;

    // Helper for CheckSpawnAdds
    void HandleCheckSpawnAdd(eStalagFeugen whichAdd)
    {
        // Respawn or revive the add itself
        Creature* addCreature = m_pInstance->GetCreature(addGuids[whichAdd]);
        Creature* coilCreature = m_pInstance->GetCreature(coilGuids[whichAdd]);
        uint32 addEntry = whichAdd == eSTALAGG ? NPC_STALAGG : NPC_FEUGEN;

        // Simply unsummoning the add and the coil creature if they still exist
        if(addCreature)
        { 
            if (TemporarySummon* tmpSumm = static_cast<TemporarySummon*>(addCreature))
                tmpSumm->UnSummon();
            else
                sLog.outError("Thaddius: HandleCheckSpawnAdd addCreature was not temp summon");
            addCreature = nullptr;
        }
        if(!addCreature)
        {
            // Summonming a new add
            if (Creature* pC = m_creature->SummonCreature(addEntry, addPositions[whichAdd][0], addPositions[whichAdd][1], addPositions[whichAdd][2], addPositions[whichAdd][3],
                TEMPSUMMON_MANUAL_DESPAWN))
            {
                addCreature = pC;
                addGuids[whichAdd] = pC->GetObjectGuid();
            }
            else
                sLog.outError("Thaddius: failed spawning add %d", whichAdd);
        }

        if (coilCreature)
        {
            if (TemporarySummon* tmpSumm = static_cast<TemporarySummon*>(coilCreature))
                tmpSumm->UnSummon();
            else
                sLog.outError("Thaddius: HandleCheckSpawnAdd coilCreature was not temp summon");
        }
        // Summoning a new coil
        if (Creature* tc = m_creature->SummonCreature(NPC_TESLA_COIL, teslaCoilPositions[whichAdd][0], teslaCoilPositions[whichAdd][1], teslaCoilPositions[whichAdd][2], 0, TEMPSUMMON_MANUAL_DESPAWN))
        {
            coilGuids[whichAdd] = tc->GetObjectGuid();
            if (npc_tesla_coilAI* pTeslaAI = dynamic_cast<npc_tesla_coilAI*>(tc->AI()))
                pTeslaAI->ReApplyChain(addEntry, addGuids[whichAdd]);
            else
                sLog.outError("boss_thaddiusAddsAI::EstablishLink failed to cast tesla coil to npc_tesla_coilAI*");
        }
        else
            sLog.outError("boss_thaddiusAddsAI::EstablishLink failed to spawn teslaCoil");

        // Making sure the coil GO does its animation
        uint32 coilGOEntry = whichAdd == eSTALAGG ? GO_CONS_NOX_TESLA_STALAGG : GO_CONS_NOX_TESLA_FEUGEN;
        if (GameObject* tc = m_pInstance->GetSingleGameObjectFromStorage(coilGOEntry))
            tc->SetGoState(GO_STATE_ACTIVE);
    }

    // Respawn stalagg and feugen and the tesla coils corresponding to them. Activates the tesla coil GO and sets the chain
    void CheckSpawnAdds()
    {
        if (m_pInstance)
            if (m_pInstance->GetData(TYPE_THADDIUS) == DONE)
                return;

        HandleCheckSpawnAdd(eStalagFeugen::eSTALAGG);
        HandleCheckSpawnAdd(eStalagFeugen::eFEUGEN);
        if (Creature* pFeugen = m_pInstance->GetCreature(addGuids[eFEUGEN]))
        {
            if (boss_thaddiusAddsAI* addAI = static_cast<boss_thaddiusAddsAI*>(pFeugen->AI()))
                addAI->otherAdd = addGuids[eSTALAGG];
        }
        if (Creature* pStalagg = m_pInstance->GetCreature(addGuids[eSTALAGG]))
        {
            if (boss_thaddiusAddsAI* addAI = static_cast<boss_thaddiusAddsAI*>(pStalagg->AI()))
                addAI->otherAdd = addGuids[eFEUGEN];
        }
    }

    // Unsummons the tesla coil creature and stops animation of the coil GO
    void HandleUnsummonCoil(eStalagFeugen which)
    {
        // Unsummon the tesla coil creature
        if (Creature* tc = m_pInstance->GetCreature(coilGuids[which]))
        {
            if (TemporarySummon* tmpSumm = static_cast<TemporarySummon*>(tc))
            {
                tmpSumm->UnSummon();
            }
        }
        coilGuids[which] = 0;

        // Make the tesla coil game object stop animating
        uint32 goEntry = which == eSTALAGG ? GO_CONS_NOX_TESLA_STALAGG : GO_CONS_NOX_TESLA_FEUGEN;

        if (GameObject* pG = m_pInstance->GetSingleGameObjectFromStorage(goEntry))
        {
            pG->SetGoState(GO_STATE_READY);
        }
    }

    void HandleUnsummonAdd(eStalagFeugen which)
    {
        if (Creature* add = m_pInstance->GetCreature(addGuids[which]))
        {
            if (TemporarySummon* tmpSumm = static_cast<TemporarySummon*>(add))
            {
                tmpSumm->UnSummon();
            }
        }
        addGuids[which] = 0;
    }

    void SummonedCreatureDespawn(Creature* pC) override 
    {
        if (!m_pInstance)
            return;
        /*
        // Unsummoning the tesla coils when stalagg and feugen despawns
        if (pC->GetObjectGuid() == addGuids[eSTALAGG])
            HandleUnsummonCoil(eSTALAGG);
        else if(pC->GetObjectGuid() == addGuids[eFEUGEN])
            HandleUnsummonCoil(eFEUGEN);
        */
    }

    void Reset() override
    {
        m_events.Reset();
        m_uiBallLightningTimer = 1000;      
        m_Phase = THAD_NOT_STARTED;
        killSayCooldown = 0;
    }

    void Aggro(Unit* /*pWho*/) override
    {
        /*
        switch (urand(0, 2))
        {
        case 0: DoScriptText(SAY_AGGRO_1, m_creature); break;
        case 1: DoScriptText(SAY_AGGRO_2, m_creature); break;
        case 2: DoScriptText(SAY_AGGRO_3, m_creature); break;
        }
        // Make Attackable
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        */
    }

    void JustReachedHome() override
    {
        if (m_pInstance)
        {
            m_pInstance->SetData(TYPE_THADDIUS, FAIL);
            CheckSpawnAdds();
        }

        // Apply the "stun" aura again, which makes him darker and not moving
        if (!m_creature->HasAura(SPELL_THADIUS_SPAWN))
            m_creature->CastSpell(m_creature, SPELL_THADIUS_SPAWN, true);

        // He is not targetable other than in p2
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
    }

    void KilledUnit(Unit* pVictim) override
    {
        if (pVictim->GetTypeId() != TYPEID_PLAYER)
            return;

        if (!killSayCooldown)
        {
            DoScriptText(SAY_SLAY, m_creature);
            killSayCooldown = 5000;
        }
    }

    void JustDied(Unit* /*pKiller*/) override
    {
        DoScriptText(SAY_DEATH, m_creature);

        if (m_pInstance)
        {
            m_pInstance->SetData(TYPE_THADDIUS, DONE);
            
            //they will despawn themself.
            // Make them TEMPSUMMON_TIMED_DEAD_DESPAWN with 10-20sec despawn time,
            /*
            // Force Despawn of Adds
            Creature* pFeugen = m_pInstance->GetSingleCreatureFromStorage(NPC_FEUGEN);
            Creature* pStalagg = m_pInstance->GetSingleCreatureFromStorage(NPC_STALAGG);

            if (pFeugen)
                pFeugen->ForcedDespawn();
            if (pStalagg)
                pStalagg->ForcedDespawn();
            */
        }
    }

    void TransitionToPhase(ThaddiusPhase newPhase)
    {
        m_Phase = newPhase;
        switch (m_Phase)
        {
            case ThaddiusPhase::THAD_NOT_STARTED:
                m_creature->OnLeaveCombat();
                break;
            case ThaddiusPhase::THAD_PHASE1:
                m_creature->SetInCombatWithZone();
                break;
            case ThaddiusPhase::THAD_TRANSITION:
                // Source: https://www.youtube.com/watch?v=GmE5JufAcT0
                // 3:18     adds dead
                // 3:28 +10 tesla coil overloads emote (link dissapears, GO still animating)
                // 3:31 +3  tesla coils shoots beam thing at thaddius. SPELL_THADIUS_SPAWN removed
                // 3:33 +2  thaddius engage. GO stops animating
                m_events.ScheduleEvent(EVENT_TRANSITION_1, 10000);
                m_events.ScheduleEvent(EVENT_TRANSITION_2, 13000);
                m_events.ScheduleEvent(EVENT_TRANSITION_3, 14000);
                break;
            case ThaddiusPhase::THAD_PHASE2:
                DoResetThreat();
                if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_NEAREST, 0))
                {
                    AttackStart(pTarget);
                }
                m_events.ScheduleEvent(EVENT_BERSERK, ENRAGE_TIMER);
                m_events.ScheduleEvent(EVENT_SHIFT, PolarityShiftTimer(true));
                m_events.ScheduleEvent(EVENT_CHAIN, ChainLightningTimer());
                break;
            default:
                sLog.outError("boss_thaddiusAI in undefined phase-state");
        }
    }

    void UpdateTransitionPhase(uint32 const diff)
    {
        m_events.Update(diff);
        while (auto l_EventId = m_events.ExecuteEvent())
        {
            switch (l_EventId)
            {
                case EVENT_TRANSITION_1:
                    // stop link to adds, coils do overload emote
                    HandleUnsummonAdd(eSTALAGG);
                    HandleUnsummonAdd(eFEUGEN);
                    if (Creature* coil = m_pInstance->GetCreature(coilGuids[0]))
                    {
                        DoScriptText(EMOTE_TESLA_OVERLOAD, coil);
                    }
                    if (Creature* coil = m_pInstance->GetCreature(coilGuids[1]))
                    {
                        DoScriptText(EMOTE_TESLA_OVERLOAD, coil);
                    }
                    break;
                case EVENT_TRANSITION_2:
                    // coils shoot beam at thaddius. SPELL_THADIUS_SPAWN removed
                    if (Creature* coil = m_pInstance->GetCreature(coilGuids[0]))
                    {
                        coil->CastSpell(m_creature, SPELL_SHOCK_OVERLOAD, true);
                    }
                    if (Creature* coil = m_pInstance->GetCreature(coilGuids[1]))
                    {
                        coil->CastSpell(m_creature, SPELL_SHOCK_OVERLOAD, true);
                    }
                    m_creature->RemoveAurasDueToSpell(SPELL_THADIUS_SPAWN);
                    m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    m_creature->CastSpell(m_creature, SPELL_THADIUS_LIGHTNING_VISUAL, true);
                    break;
                case EVENT_TRANSITION_3:
                    HandleUnsummonCoil(eSTALAGG);
                    HandleUnsummonCoil(eFEUGEN);
                    /*
                    // Thaddius engage. GOs stops animating
                    if (GameObject* pG = m_pInstance->GetSingleGameObjectFromStorage(GO_CONS_NOX_TESLA_FEUGEN))
                        pG->SetGoState(GO_STATE_READY);
                    if (GameObject* pG = m_pInstance->GetSingleGameObjectFromStorage(GO_CONS_NOX_TESLA_STALAGG))
                        pG->SetGoState(GO_STATE_READY);
                    */
                    TransitionToPhase(THAD_PHASE2);
                    break;
            }
        }
    }

    void RemoveDebuffsFromPlayer(Player* pPlayer)
    {
        pPlayer->RemoveAurasDueToSpell(SPELL_POSITIVE_CHARGE_AMP);
        pPlayer->RemoveAurasDueToSpell(SPELL_POSITIVE_CHARGE_APPLY);
        pPlayer->RemoveAurasDueToSpell(SPELL_POSITIVE_CHARGE_TICK);
        pPlayer->RemoveAurasDueToSpell(SPELL_NEGATIVE_CHARGE_AMP);
        pPlayer->RemoveAurasDueToSpell(SPELL_NEGATIVE_CHARGE_APPLY);
        pPlayer->RemoveAurasDueToSpell(SPELL_NEGATIVE_CHARGE_TICK);
    }

    void DoPolarityShift()
    {
        DoScriptText(SAY_ELECT, m_creature);

        // this is kinda ugly :/
        Map::PlayerList const& lPlayers = m_pInstance->GetMap()->GetPlayers();
        std::vector<Player*> playerVec;
        for (auto& p : lPlayers)
        {
            Player* pPlayer = p.getSource();
            if (pPlayer->IsDead())
                continue;

            playerVec.push_back(p.getSource());
        }
        std::shuffle(playerVec.begin(), playerVec.end(), m_random);
        int i = 0;
        int firstHalf = playerVec.size() / 2;
        for (i; i < firstHalf; i++)
        {
            Player* pPlayer = playerVec[i];
            RemoveDebuffsFromPlayer(pPlayer);
            pPlayer->CastSpell(pPlayer, SPELL_POSITIVE_CHARGE_APPLY, true);
        }
        for (i; i < playerVec.size(); i++)
        {
            Player* pPlayer = playerVec[i];
            RemoveDebuffsFromPlayer(pPlayer);
            pPlayer->CastSpell(pPlayer, SPELL_NEGATIVE_CHARGE_APPLY, true);
        }
    }

    void DoSpellChain()
    {
        Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0);
        if (!pTarget || DoCastSpellIfCan(pTarget, SPELL_CHAIN_LIGHTNING) != CAST_OK)
            m_events.Repeat(100);
        else
            m_events.Repeat(ChainLightningTimer());
    }

    void UpdateP2(uint32 const diff)
    {
        if (!m_pInstance)
            return;

        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        m_events.Update(diff);
        while (auto l_EventId = m_events.ExecuteEvent())
        {
            switch (l_EventId)
            {
                case EVENT_SHIFT:
                    if (DoCastSpellIfCan(m_creature, SPELL_POLARITY_SHIFT, CF_INTERRUPT_PREVIOUS) == CAST_OK)
                    {
                        m_events.Repeat(30000);
                        m_events.ScheduleEvent(EVENT_POLARITY_CHANGE, 3000);
                    }
                    else
                        m_events.Repeat(100);
                    /*
                    if (DoPolarityShift())
                        m_events.Repeat(30000);
                    else
                        m_events.Repeat(100);
                    */
                    break;
                case EVENT_CHAIN:
                    DoSpellChain();
                    break;
                case EVENT_BERSERK:
                    if (DoCastSpellIfCan(m_creature, SPELL_BESERK) != CAST_OK)
                        m_events.Repeat(100);
                    break;
                case EVENT_POLARITY_CHANGE:
                    DoPolarityShift();
                    break;
            }
        }
        
        // m_uiBallLightningTimer reinitialized to 1sec after a successfull melee attack, and only negated if target is oor. 
        // This will prevent the boss from starting to spam balls of lightning if the boss is being moved with lag or something
        if (!DoMeleeAttackIfReady())
        {
            if (!m_creature->CanReachWithMeleeAutoAttack(m_creature->GetVictim()))
            {
                m_uiBallLightningTimer -= std::min(diff, m_uiBallLightningTimer);
            }
            else
            {
                m_uiBallLightningTimer = 1000;
            }
        }
        else
        {
            m_uiBallLightningTimer = 1000; 
        }

        // If we did not perform a melee attack, but MH or OH attack was ready, and we were not in melee range,
        // it's time to start hurl some balls of lightning
        if (m_uiBallLightningTimer < diff && !m_creature->IsNonMeleeSpellCasted())
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_BALL_LIGHTNING) == CAST_OK)
                m_uiBallLightningTimer = 1500;
        }
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        //return; // xxx debugging adds

        if (!m_pInstance)
            return;

        if (m_Phase != THAD_NOT_STARTED)
        {
            if (m_creature->GetThreatManager().isThreatListEmpty())
            {
                TransitionToPhase(THAD_NOT_STARTED);
            }
        }
        else
        {
            // He can act a bit weird if you stand next to him on server startup :/
            if (m_creature->IsInCombat())
                TransitionToPhase(THAD_NOT_STARTED);
        }

        killSayCooldown -= std::min(killSayCooldown, uiDiff);

        switch (m_Phase)
        {
            case ThaddiusPhase::THAD_NOT_STARTED:
                // IN_PROGRESS is set by the adds when pulled
                if (m_pInstance->GetData(TYPE_THADDIUS) == IN_PROGRESS)
                    TransitionToPhase(THAD_PHASE1);
                break;
            case ThaddiusPhase::THAD_PHASE1:
                // if wipe during add-phase the adds will set FAIL
                if (m_pInstance->GetData(TYPE_THADDIUS) == FAIL)
                {
                    TransitionToPhase(THAD_NOT_STARTED);
                }
                // if adds are successfully killed, they set SPECIAL
                else if (m_pInstance->GetData(TYPE_THADDIUS) == SPECIAL)
                {
                    TransitionToPhase(THAD_TRANSITION);
                }
                break;
            case ThaddiusPhase::THAD_TRANSITION:
                UpdateTransitionPhase(uiDiff);
                break;
            case ThaddiusPhase::THAD_PHASE2:
                UpdateP2(uiDiff);
                break;
            default:
                sLog.outError("boss_thaddiusAI in undefined phase-state");
        }
    }
};

struct boss_stalaggAI : public boss_thaddiusAddsAI
{
    boss_stalaggAI(Creature* pCreature) : boss_thaddiusAddsAI(pCreature, eSTALAGG)
    {
        Reset();
    }

    void Aggro(Unit* pWho) override
    {
        DoScriptText(SAY_STAL_AGGRO, m_creature);
        m_events.ScheduleEvent(EVENT_WARSTOMP, WarstompTimer());
        m_events.ScheduleEvent(EVENT_POWERSURGE, PowerSurgeTimer());
        m_events.ScheduleEvent(EVENT_MAGNETIC_PULL, MagneticPullTimer());
        boss_thaddiusAddsAI::Aggro(pWho);
    }

    void JustDied(Unit* /*pKiller*/) override
    {
        if (bothDeath && m_pInstance && m_pInstance->GetData(TYPE_THADDIUS) != SPECIAL)
            m_pInstance->SetData(TYPE_THADDIUS, SPECIAL);
    }

    void KilledUnit(Unit* pVictim) override
    {
        if (pVictim->GetTypeId() == TYPEID_PLAYER)
            DoScriptText(SAY_STAL_SLAY, m_creature);
    }
};

struct boss_feugenAI : public boss_thaddiusAddsAI
{
    boss_feugenAI(Creature* pCreature) : boss_thaddiusAddsAI(pCreature, eFEUGEN)
    {
        Reset();
    }

    void Aggro(Unit* pWho) override
    {
        DoScriptText(SAY_FEUG_AGGRO, m_creature);

        m_events.ScheduleEvent(EVENT_WARSTOMP, WarstompTimer());
        m_events.ScheduleEvent(EVENT_STATIC_FIELD, StaticFiledTimer());

        boss_thaddiusAddsAI::Aggro(pWho);
    }

    void JustDied(Unit* /*pKiller*/) override
    {
        if (bothDeath && m_pInstance && m_pInstance->GetData(TYPE_THADDIUS) != SPECIAL)
            m_pInstance->SetData(TYPE_THADDIUS, SPECIAL);
    }

    void KilledUnit(Unit* pVictim) override
    {
        if (pVictim->GetTypeId() == TYPEID_PLAYER)
            DoScriptText(SAY_FEUG_SLAY, m_creature);
    }
};

CreatureAI* GetAI_boss_feugen(Creature* pCreature)
{
    return new boss_feugenAI(pCreature);
}

CreatureAI* GetAI_boss_stalagg(Creature* pCreature)
{
    return new boss_stalaggAI(pCreature);
}

CreatureAI* GetAI_npc_tesla_coil(Creature* pCreature)
{
    return new npc_tesla_coilAI(pCreature);
}

CreatureAI* GetAI_boss_thaddius(Creature* pCreature)
{
    return new boss_thaddiusAI(pCreature);
}

void AddSC_boss_thaddius()
{
    Script* pNewScript;

    pNewScript = new Script;
    pNewScript->Name = "boss_thaddius";
    pNewScript->GetAI = &GetAI_boss_thaddius;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "boss_stalagg";
    pNewScript->GetAI = &GetAI_boss_stalagg;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "boss_feugen";
    pNewScript->GetAI = &GetAI_boss_feugen;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "npc_tesla_coil";
    pNewScript->GetAI = &GetAI_npc_tesla_coil;
    pNewScript->RegisterSelf();
}
