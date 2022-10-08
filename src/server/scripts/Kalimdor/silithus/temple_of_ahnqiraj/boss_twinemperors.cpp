/*
 * Copyright (C) 2006-2011 ScriptDev2 <http://www.scriptdev2.com/>
 * Copyright (C) 2010-2011 ScriptDev0 <http://github.com/mangos-zero/scriptdev0>
 *
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
SDName: Boss_Twinemperors
SD%Complete: 
SDComment: uncertain which dialogue should be used on enrage
SDCategory: Temple of Ahn'Qiraj
Rewrtten by Gemt
EndScriptData */

#include "scriptPCH.h"
#include "temple_of_ahnqiraj.h"




enum eSpells {
    SPELL_BERSERK               = 26662,
    
    SPELL_TWIN_TELEPORT_SCRIPT  = 799,   // should have a script effect, dosent seem to have one.
    SPELL_TWIN_TELEPORT_MSG     = 800,   // CTRA watches for this spell to start its teleport timer
    SPELL_TWIN_TELEPORT_VISUAL  = 26638, 

    SPELL_HEAL_BROTHER          = 7393,


    // Vek'nilash
    SPELL_UPPERCUT              = 26007,
    SPELL_UNBALANCING_STRIKE    = 26613,
    SPELL_MUTATE_BUG            = 802,
    SPELL_DOUBLE_ATTACK         = 18943, // 50% chance. Based on sniff provided by Tobschinski (https://github.com/LightsHope/server/pull/1208#issuecomment-356985526)

    // Vek'lor
    SPELL_SHADOWBOLT            = 26006,
    SPELL_BLIZZARD              = 26607,
    SPELL_ARCANEBURST           = 568,
    SPELL_EXPLODEBUG            = 804,

    BUG_TYPE_1                  = 15316,
    BUG_TYPE_2                  = 15317,

    SPELL_PIERCE_ARMOR          = 6016,
    SPELL_ACID_SPIT             = 26050,

    // bugs, seems to be defined in db?
    // Virulet Posion
    // Explode Bug
    // Mute Bugs
};

enum eScriptTexts {
    SAY_VEKLOR_AGGRO_1      = -1531019, // its too late to turn away
    SAY_VEKLOR_AGGRO_2      = -1531020, // prepare to embrace oblivion
    SAY_VEKLOR_AGGRO_3      = -1531021, // like a fly in a web
    SAY_VEKLOR_AGGRO_4      = -1531022, // your brash arrogance
    SAY_VEKLOR_SLAY         = -1531023, // you will not escape death
    SAY_VEKLOR_SPECIAL      = -1531025, // to decorate our halls
                                           
    SAY_VEKNILASH_AGGRO_1   = -1531026, // ah, lambs to the slaughter
    SAY_VEKNILASH_AGGRO_2   = -1531027, // let none survive
    SAY_VEKNILASH_AGGRO_3   = -1531028, // join me brother, there is blood to be shed
    SAY_VEKNILASH_AGGRO_4   = -1531029, // look brother, fresh bloood
    SAY_VEKNILASH_SLAY      = -1531030, // your fate is sealed
    SAY_VEKNILASH_SPECIAL   = -1531032, // Shall be your undoing (wipe?)
                                        
    //death is handled by instance_temple_of_ahnqiraj.cpp
    //NOTE: according to wowwiki, the *_SLAY emotes are used during enrage,
    //      while "Oblivion will engulf you", "Like a fly in a web" and "your brash arrogance" 
    //      is used on killing player. Not been able to confirm this.
};

// Shared constants
static constexpr uint32 PULL_RANGE = 50;
static constexpr uint32 ENRAGE_TIMER                = 60 * 60000;

static constexpr uint32 JUST_TELEPORTED_FREEZE      = 2000;     // Emperor is "frozen", aka not doing anything, for this long after TP
static constexpr uint32 AFTER_TELEPORT_THREAT       = 3000;     // Threat added to nearest player after TP. TODO: correct amount?

static constexpr uint32 TELEPORTTIME_MIN_CD         = 30000;    // Shortest possible cooldown on teleport
static constexpr uint32 TELEPORTTIME_MAX_CD         = 40000;    // Longest possible cooldown on teleport

static constexpr uint32 TRY_HEAL_FREQUENCY          = 0;        // How ofthen will the emperors TRY to heal eachother, 0 for every update
static constexpr uint32 SUCCESS_HEAL_FREQUENCY      = 1500;     // How ofthen will the emperors actually heal, when in range of each other
//static constexpr float  HEAL_BROTHER_AMOUNT         = 30000.0f; // How much do they heal when in heal-range
static constexpr float  HEAL_BROTHER_RANGE          = 60.0f;

static constexpr uint32 RESPAWN_BUG_FREQUENCY       = 10000;    // How often do we try to respawn a dead bug
//static constexpr float  RESPAWN_BUG_DISTANCE        = 50.0f;    // How far away do we look for dead bugs for respawning
static constexpr float  BUG_SPELL_MAX_DIST          = 20.0f;    // Max distance a bug can be for the twin to choose it

// Vek'nilash constants
static constexpr uint32 UPPERCUT_MIN_CD             = 14000;
static constexpr uint32 UPPERCUT_MAX_CD             = 29000;
static constexpr uint32 UNBALANCING_STRIKE_MIN_CD   = 8000;
static constexpr uint32 UNBALANCING_STRIKE_MAX_CD   = 18000;
static constexpr uint32 MUTATE_BUG_MIN_CD           = 10000;
static constexpr uint32 MUTATE_BUG_MAX_CD           = 15000;

// Vek'lor constants
static constexpr float  ARCANE_BURST_RANGE          = 10.0f;    // How close must a player be if VL should cast AB
static constexpr uint32 ARCANE_BURST_MIN_CD         = 5000;     
static constexpr uint32 ARCANE_BURST_MAX_CD         = 10000;
static constexpr uint32 BLIZZARD_MIN_CD             = 15000;    // todo: no source on blizzard cooldown. Duration is 10s
static constexpr uint32 BLIZZARD_MAX_CD             = 20000;
static constexpr uint32 VEKLOR_DIST                 = 20;       // Vek'lor chase to this distance
static constexpr uint32 SHADOWBOLT_RANGED_MIN_CD    = 1800;     
static constexpr uint32 SHADOWBOLT_RANGED_MAX_CD    = 2500;     
static constexpr uint32 SHADOWBOLT_MELEE_MIN_CD     = 2000;     
static constexpr uint32 SHADOWBOLT_MELEE_MAX_CD     = 10000;    
static constexpr uint32 VEKLOR_PULL_YELL_DELAY      = 3000;     // Vek'lors pull yell happens after Vek'nilash
static constexpr uint32 EXPLODE_BUG_MIN_CD          = 7000;
static constexpr uint32 EXPLODE_BUG_MAX_CD          = 10000;


struct mob_TwinsBug : public ScriptedAI {
    mob_TwinsBug(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 pierceArmorTimer;
    uint32 acidSpitTimer;

    void GoBeBadBug(uint32 whatKindOfbad)
    {
        m_creature->AddAura(whatKindOfbad);
        m_creature->SetFactionTemplateId(14);
        m_creature->SetInCombatWithZone();
        if (whatKindOfbad == SPELL_MUTATE_BUG) {
            m_creature->SetFullHealth();
        }
    }

    void JustDied(Unit* Killer) override
    {
        m_creature->SetFactionTemplateId(7);
        m_creature->RemoveAllAuras();
    }

    void Reset() override
    {
        m_creature->SetFactionTemplateId(7);
        m_creature->RemoveAllAuras();
        pierceArmorTimer = 5000;
        acidSpitTimer = 6000;

    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;
        
        if (pierceArmorTimer < diff) {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_PIERCE_ARMOR) == CAST_OK)
                pierceArmorTimer = urand(5000, 9000);
        }
        else
            pierceArmorTimer -= diff;

        if (acidSpitTimer < diff) {
            if(DoCastSpellIfCan(m_creature->GetVictim(), SPELL_ACID_SPIT) == CAST_OK)
                acidSpitTimer = urand(6000, 12000);
        }
        else 
            acidSpitTimer -= diff;

        DoMeleeAttackIfReady();
    }
};

struct boss_twinemperorsAI : public ScriptedAI
{
    instance_temple_of_ahnqiraj* m_pInstance;
    uint32 EnrageTimer;
    
    uint32 justTeleportedTimer;
    bool justTeleported;    
    bool didPullDialogue;
    
    uint32 bugMutationTimer;
    uint32 respawnBugTimer;

    uint32 killSayCooldown;

    virtual uint32  GetBugSpellCooldown() = 0;
    virtual uint32  GetBugSpell() = 0;
    virtual void    OnEndTeleportVirtual() = 0;
    virtual void    UpdateEmperor(uint32) = 0;

    // Only one of the twins should implement these functions
    virtual void UpdateTeleportToMyBrother(uint32) {}
    virtual void TryHealBrother(uint32 diff) {}

    ObjectGuid closestTargetAfterTP;

    boss_twinemperorsAI(Creature* pCreature) : 
        ScriptedAI(pCreature)
    {

        instance_temple_of_ahnqiraj* tmpPTr = dynamic_cast<instance_temple_of_ahnqiraj*>(pCreature->GetInstanceData());
        if (!tmpPTr) {
            sLog.outError("boss_twinemperorsAI attempted to cast instance to type instance_temple_of_ahnqiraj, but failed.");
            m_pInstance = nullptr;
        }
        else {
            m_pInstance = (instance_temple_of_ahnqiraj*)pCreature->GetInstanceData();

            //If the encounter has not been started yet this ID they should be kneeling to the eye.
            if (!m_pInstance->TwinsDialogueStartedOrDone()) {
                m_creature->SetStandState(UNIT_STAND_STATE_KNEEL);
            }
        }
        //Reset(); reset is called by child class
    }

    void SharedReset()
    {
        respawnBugTimer = RESPAWN_BUG_FREQUENCY;
        EnrageTimer     = ENRAGE_TIMER;
        justTeleported  = false;
        didPullDialogue = false;
        killSayCooldown = 0;
        m_creature->ClearUnitState(UNIT_STAT_STUNNED);
    }

    void MoveInLineOfSight(Unit *who) override
    {
        // Only want to run this if we are not in combat
        if (!who || m_creature->GetVictim() || m_creature->IsInCombat())
            return;

        if (who->IsTargetable(true, false) && who->IsInAccessablePlaceFor(m_creature) && m_creature->IsHostileTo(who))
        {
            float attackRadius = m_creature->GetAttackDistance(who);
            if (attackRadius < PULL_RANGE)
                attackRadius = PULL_RANGE;

            // CREATURE_Z_ATTACK_RANGE there are stairs
            if (m_creature->IsWithinDistInMap(who, attackRadius, true, false) && m_creature->GetDistanceZ(who) <= 7)
                AttackStart(who);
        }
    }

    void AttackedBy(Unit* attacker) override
    {
        // Preventing the emperors to start attacking target
        // during the teleport-idle period
        if (!justTeleported)
        {
            ScriptedAI::AttackedBy(attacker);
        }
    }

    void DamageTaken(Unit *done_by, uint32 &damage) override
    {
        if (!m_pInstance)
            return;

        if (Creature* pTwin = GetOtherBoss())
        {
            float fDamPercent = ((float)damage) / ((float)m_creature->GetMaxHealth());
            uint32 uiTwinDamage = (uint32)(fDamPercent * ((float)pTwin->GetMaxHealth()));
            uint32 uiTwinHealth = pTwin->GetHealth() - std::min(uiTwinDamage, pTwin->GetHealth());
            pTwin->SetHealth(std::max((uint32)0, uiTwinHealth));
            
            // Possibly needed to make sure the damage dealth through setHealth is counted 
            pTwin->CountDamageTaken(uiTwinDamage, true);
        }
    }

    void JustDied(Unit* Killer) override
    {
        // Only need one of them to kill the other and update instance data
        if (m_pInstance) {
            if (m_pInstance->GetData(TYPE_TWINS) == DONE) {
                return;
            }
            else {
                m_pInstance->SetData(TYPE_TWINS, DONE);
            }
        }

        if (Creature* pOtherBoss = GetOtherBoss())
        {
            Killer->Kill(pOtherBoss, nullptr, false);
        }

        // Death text script-text is handled by instance upon receiving DONE data
    }

    void Aggro(Unit* pWho) override
    {
        if (m_pInstance) 
        {
            if (m_pInstance->GetData(TYPE_TWINS) == IN_PROGRESS) {
                return;
            }
            m_pInstance->SetData(TYPE_TWINS, IN_PROGRESS);
        }
        bool bOpenEntrance = false;
        std::list<Creature*> lst;
        GetCreatureListWithEntryInGrid(lst, m_creature, NPC_ANUBISATH_DEFENDER, 800);
        for (const auto pCreature : lst)
        {
            if (pCreature->IsDead()) continue;
            pCreature->SetActiveObjectState(true);
            pCreature->SetInCombatWithZone();
            pCreature->AI()->AttackStart(pWho);
            bOpenEntrance = true;
        }
        
        if (m_pInstance && !bOpenEntrance)
            if (GameObject* pGo = m_pInstance->GetSingleGameObjectFromStorage(GO_TWINS_ENTER_DOOR))
                m_pInstance->DoResetDoor(pGo->GetGUID());

        m_creature->SetInCombatWithZone();

        Creature *pOtherBoss = GetOtherBoss();
        if (pOtherBoss)
        {
            // The "other boss" will start running to the same initial puller.
            pOtherBoss->AI()->AttackStart(pWho);
            pOtherBoss->SetInCombatWithZone();
        }
    }

    void JustReachedHome() override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_TWINS, FAIL);
    }

    // Workaround for the shared health pool
    void HealedBy(Unit* pHealer, uint32& uiHealedAmount) override
    {
        if (!m_pInstance)
            return;

        if (Creature* pTwin = GetOtherBoss())
        {
            float fHealPercent = ((float)uiHealedAmount) / ((float)m_creature->GetMaxHealth());
            uint32 uiTwinHeal = (uint32)(fHealPercent * ((float)pTwin->GetMaxHealth()));
            uint32 uiTwinHealth = pTwin->GetHealth() + uiTwinHeal;
            pTwin->SetHealth(uiTwinHealth < pTwin->GetMaxHealth() ? uiTwinHealth : pTwin->GetMaxHealth());
        }
    }

    void UpdateAI(uint32 const diff) override
    {
        // The rest of this script requires an instance, less managment and code duplication, and a bit of lazyness
        if (!m_pInstance)
            return;
      
        if (justTeleported) {

            // Delaying selection of new closest player until first update after TP
            // to be sure we will actually select a target on the new location.
            // (in other words, do it here instead of in OnStartTeleport())
            if (closestTargetAfterTP.IsEmpty()) {
                //Making sure everyone is contained in threatlist
                m_creature->SetInCombatWithZone();
                //todo: any potential issues with using GetNearestVictimInRange and 300 maxrange?
                if (Unit* closestPlayer = m_creature->GetNearestVictimInRange(0, 300.0f)) {
                    closestTargetAfterTP = closestPlayer->GetGUID();
                    m_creature->GetThreatManager().addThreat(closestPlayer, AFTER_TELEPORT_THREAT);
                }
                else {
                    sLog.outBasic("Twins unable to select closest target during TP stun");
                }
            }

            if (justTeleportedTimer <= diff) {
                OnEndTeleport();
            }
            else {
                justTeleportedTimer -= diff;
            }
        }
        else {
            // Not attempting to get a hostile target during teleport-idle
            if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim()) {
                return;
            }
        }

        if (killSayCooldown > 0) {
            killSayCooldown -= diff;
        }

        // We keep calling all of these updates also when TP-stunned,
        // but the functions themself will delay the actual spells until
        // they are no longer TP-stunned
        CheckEnrage(diff);
        UpdateTeleportToMyBrother(diff);
        HandleBugSpell(diff);
        TryHealBrother(diff);
        //HandleDeadBugs(diff); // they respawn by themself...
        
        // We skip updating emperor-specific spells during teleport stun
        if (!justTeleported) {
            UpdateEmperor(diff);
        }

        // Evade in case starts running after someone outside their room
        if (m_creature->GetPositionZ() > -95.0f) {
            if(Creature* pOther = GetOtherBoss())
                pOther->AI()->EnterEvadeMode();
            EnterEvadeMode();
        }
    }

    Creature* GetOtherBoss()
    {
        if (m_pInstance) 
            return m_pInstance->GetSingleCreatureFromStorage(m_creature->GetEntry() == NPC_VEKLOR ? NPC_VEKNILASH : NPC_VEKLOR);
        return nullptr;
    }

    // Called as teleport happens
    void OnStartTeleport(float x, float y, float z, float o)
    {
        justTeleported = true;
        justTeleportedTimer = JUST_TELEPORTED_FREEZE;
        m_creature->InterruptNonMeleeSpells(true);
        DoStopAttack();
        DoResetThreat();
        m_creature->StopMoving();
        m_creature->NearTeleportTo(x, y, z, o);
        closestTargetAfterTP = 0;
        m_creature->CastSpell(m_creature, SPELL_TWIN_TELEPORT_MSG, true);
        m_creature->CastSpell(m_creature, SPELL_TWIN_TELEPORT_VISUAL, true);
    }

    // Called JUST_TELEPORTED_FREEZE after teleport happened
    void OnEndTeleport()
    {
        justTeleported = false;
        
        if (Player* closestPlayer = m_pInstance->GetMap()->GetPlayer(closestTargetAfterTP)) {
            closestTargetAfterTP = closestPlayer->GetGUID();
            AttackStart(closestPlayer);
        }
        else {
            sLog.outBasic("Twins unable to select closest target after TP stun end");
        }
        

        OnEndTeleportVirtual();
    }

    void HandleBugSpell(uint32 diff)
    {
        if (bugMutationTimer < diff) {
            
            // Wait with doing stuff until after idle
            if (justTeleported) return;

            std::list<Creature*> lUnitList;
            GetCreatureListWithEntryInGrid(lUnitList, m_creature, { BUG_TYPE_1 , BUG_TYPE_2 }, BUG_SPELL_MAX_DIST);

            std::list<Creature*>::iterator iter;
            for (iter = lUnitList.begin(); iter != lUnitList.end();) {
                if ((*iter)->IsDead()) {
                    iter = lUnitList.erase(iter);
                }
                // Ignoring bugs that has already been affected by a spell
                else if ((*iter)->HasAura(SPELL_MUTATE_BUG) || (*iter)->HasAura(SPELL_EXPLODEBUG)) {
                    iter = lUnitList.erase(iter);
                }
                else {
                    ++iter;
                }
            }

            if (lUnitList.empty())
                return;

            iter = lUnitList.begin();

            std::advance(iter, urand(0, lUnitList.size() - 1));
            Creature* c = *iter;
            mob_TwinsBug* bugAI = dynamic_cast<mob_TwinsBug*>(c->AI());
            if (bugAI) {
                bugAI->GoBeBadBug(GetBugSpell());
            }
            bugMutationTimer = GetBugSpellCooldown();
        }
        else {
            bugMutationTimer -= diff;
        }
    }
    
    void CheckEnrage(uint32 diff)
    {
        if (EnrageTimer < diff && !m_creature->HasAura(SPELL_BERSERK))
        {
            // Wait with casting enrage until after TP idle
            if (justTeleported) return;

            // just force-apply berserk if it's time. No dilly-dally. 
            m_creature->CastSpell(m_creature, SPELL_BERSERK, true);
            EnrageTimer = 60000 * 5; // resetting to duration of enrage
        }
        else 
        {
            EnrageTimer -= diff;
        }
    }

    // Get players in given range, optionally skip topaggro. Used where
    // we dont want to compare distance + bounding radius etc, but rather
    // simply center-to-center
    Player* GetPlayerInP2PRange(float min, float max, bool skipTopAggro)
    {
        ThreatList const& tList = m_creature->GetThreatManager().getThreatList();

        if (tList.empty())
            return nullptr;

        std::list<Player*> candidates;
        ThreatList::const_iterator i = tList.begin();

        // skipping top-aggro if there are more than 1 person on threat list
        if (tList.size() > 1 && skipTopAggro)
            ++i;

        for (i; i != tList.end(); ++i) {
            Player* pPlayer = m_creature->GetMap()->GetPlayer((*i)->getUnitGuid());
            if (!pPlayer) continue;

            if (m_creature->IsInRange(pPlayer, min, max)) {
                candidates.push_back(pPlayer);
            }
        }

        if (candidates.empty())
            return nullptr;

        auto candIt = candidates.begin();
        std::advance(candIt, urand(0, candidates.size() - 1));
        return *candIt;
    }
};

struct boss_veklorAI : public boss_twinemperorsAI
{
    boss_veklorAI(Creature* pCreature) : boss_twinemperorsAI(pCreature)
    {
        Reset();

        // Making sure we have the correct range values
        shadowboltRange = 45.0f;
        if (const SpellRangeEntry* sre = sSpellRangeStore.LookupEntry(SPELL_SHADOWBOLT))
            shadowboltRange = sre->maxRange;
        blizzardRange = 45.0f;
        if (const SpellRangeEntry* sre = sSpellRangeStore.LookupEntry(SPELL_BLIZZARD))
            blizzardRange = sre->maxRange;
    }

    float shadowboltRange;
    float blizzardRange;

    uint32 shadowBoltTimer;
    uint32 blizzardTimer;
    uint32 arcaneBurstTimer;

    uint32 pullDialogueTimer;

    uint32 teleportTimer;
    uint32 healTimer;
    uint32 timeSinceLastSB;

    void Reset() override
    {
        SharedReset();
        shadowBoltTimer     = 0; // No cooldown on pull
        arcaneBurstTimer    = 0; // No cooldown on pull
        bugMutationTimer    = boss_veklorAI::GetBugSpellCooldown();
        blizzardTimer       = urand(BLIZZARD_MIN_CD, BLIZZARD_MAX_CD);
        teleportTimer       = urand(TELEPORTTIME_MIN_CD, TELEPORTTIME_MAX_CD);
        healTimer           = TRY_HEAL_FREQUENCY;
        pullDialogueTimer   = VEKLOR_PULL_YELL_DELAY;
        timeSinceLastSB     = SHADOWBOLT_RANGED_MIN_CD;

        // Can be removed if its included in DB.
        m_creature->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, true);
    }

    void AttackStart(Unit* who) override
    {
        float dist = m_creature->GetDistance3dToCenter(who);
        if (dist <= VEKLOR_DIST) {
            // if he is <= VEKLOR_DIST he should not start chasing again until
            // target is further away than shadowboltRange
            m_creature->SetCasterChaseDistance(shadowboltRange);
        }
        else if (dist > shadowboltRange) {
            // if he is further away than shadowboltRange we set
            // chase distance to VEKLOR_DIST
            m_creature->SetCasterChaseDistance(VEKLOR_DIST);
        }
        ScriptedAI::AttackStart(who);
    }

    void KilledUnit(Unit*) override
    {
        if (killSayCooldown == 0) {
            DoScriptText(SAY_VEKLOR_SLAY, m_creature);
            killSayCooldown = urand(5000, 10000);
        }
    }

    uint32 GetBugSpellCooldown() override
    {
        return urand(EXPLODE_BUG_MIN_CD, EXPLODE_BUG_MAX_CD);
    }

    uint32 GetBugSpell() override
    {
        return SPELL_EXPLODEBUG;
    }

    void UpdateTeleportToMyBrother(uint32 diff) override
    {
        // Updating time and returning if it's not yet time to teleport
        if (teleportTimer >= diff) {
            teleportTimer -= diff;
            return;
        }
        teleportTimer = urand(TELEPORTTIME_MIN_CD, TELEPORTTIME_MAX_CD);

        // If he is attacked during this periode he will instantly engage
        // If noone attacked during that periode, he start attacking after the period.

        Creature *pOtherBoss = GetOtherBoss();
        if (!pOtherBoss) return; // Well, that was too bad...

        float other_x = pOtherBoss->GetPositionX();
        float other_y = pOtherBoss->GetPositionY();
        float other_z = pOtherBoss->GetPositionZ();
        float other_o = pOtherBoss->GetOrientation();
        float me_x = m_creature->GetPositionX();
        float me_y = m_creature->GetPositionY();
        float me_z = m_creature->GetPositionZ();
        float me_o = m_creature->GetOrientation();

        OnStartTeleport(other_x, other_y, other_z, me_o);
        if (boss_twinemperorsAI* pOtherAI = dynamic_cast<boss_twinemperorsAI*>(pOtherBoss->AI())) {
            pOtherAI->OnStartTeleport(me_x, me_y, me_z, other_o);
        }
    }

    void TryHealBrother(uint32 diff) override
    {
        // Cant heal while tp-idle, but since the "stun" effect isent really working properly we return manually
        // https://www.youtube.com/watch?v=8mGchbCF1Lw
        if (justTeleported) {
            healTimer -= std::min(diff, healTimer);
            return;
        }

        if (healTimer < diff) {
            Unit *pOtherBoss = GetOtherBoss();
            if (pOtherBoss && pOtherBoss->IsWithinDist(m_creature, HEAL_BROTHER_RANGE))
            {
                if (DoCastSpellIfCan(pOtherBoss, SPELL_HEAL_BROTHER) == CAST_OK) {
                    // triggered-cast from brother on me if we successfully healed the other way
                    pOtherBoss->CastSpell(m_creature, SPELL_HEAL_BROTHER, true);
                    healTimer = SUCCESS_HEAL_FREQUENCY;
                }
            }
            else {
                healTimer = TRY_HEAL_FREQUENCY;
            }
        }
        else {
            healTimer -= diff;
        }
    }

    void OnEndTeleportVirtual() override
    {
        // Seems rather random if he starts with an AB instantly or delays it 
        // when looking at vanilla videos, so possibly because the timer is not reset?
        //arcaneBurstTimer = ARCANE_BURST_TP_CD;

        shadowBoltTimer = 0; 
    }

    void UpdateBlizzard(uint32 diff)
    {
        if (blizzardTimer < diff) {
            if (Player* p = GetPlayerInP2PRange(0, blizzardRange, true)) {
                if (DoCastSpellIfCan(p, SPELL_BLIZZARD) == CAST_OK) {
                    blizzardTimer = urand(BLIZZARD_MIN_CD, BLIZZARD_MAX_CD);
                }
            }
        }
        else {
            blizzardTimer -= diff;
        }
    }

    void updateArcaneBurst(uint32 diff)
    {
        if (arcaneBurstTimer < diff) {
            if (Unit* mvic = GetPlayerInP2PRange(0, ARCANE_BURST_RANGE, false)) {
                if (DoCastSpellIfCan(mvic, SPELL_ARCANEBURST) == CAST_OK)
                    arcaneBurstTimer = urand(ARCANE_BURST_MIN_CD, ARCANE_BURST_MAX_CD);
            }
        }
        else {
            arcaneBurstTimer -= diff;
        }
    }
    
    void UpdateEmperor(uint32 diff) override
    {
        // Vek'lor does his yell second, so we wait out pullDialogueTimer before yelling
        if (!didPullDialogue) 
        {
            if (pullDialogueTimer < diff) 
            {
                didPullDialogue = true;
                DoScriptText(irand(SAY_VEKLOR_AGGRO_4, SAY_VEKLOR_AGGRO_1), m_creature);
            }
            else 
            {
                pullDialogueTimer -= diff;
            }
        }

        // Always update blizzard and arcane burst, regardless of melee or not
        UpdateBlizzard(diff);
        updateArcaneBurst(diff);
   
        Unit* victim = m_creature->GetVictim();
        if (!victim) 
            return;

        bool isMelee = m_creature->CanReachWithMeleeAutoAttack(victim);
        bool isInLos = m_creature->IsWithinLOSInMap(victim);
        
        // Overriding shadowboltTimer if we're not in melee and we have not casted
        // shadowbolt in at least SHADOWBOLT_RANGED_CD time. This will mostly be the 
        // case if target was in melee, but then moved out, in which case we should 
        // instantly re-cast a new shadowbolt unless it was just casted.
        if (!isMelee && timeSinceLastSB > SHADOWBOLT_RANGED_MAX_CD) 
        {
            shadowBoltTimer = 0;
        }

        // If we're in los and melee range and melee attack succeeded we wait one update before
        // doing the shadowbolt.
        if (isMelee && isInLos && !m_creature->IsNonMeleeSpellCasted() && DoMeleeAttackIfReady())
        {
            shadowBoltTimer -= std::min(diff, shadowBoltTimer);
        }
        else if (!m_creature->IsMoving())
        {
            if(m_creature->GetStandState() != UNIT_STAND_STATE_STAND)
                m_creature->SetStandState(UNIT_STAND_STATE_STAND);
            if (shadowBoltTimer < diff) 
            {
                if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_SHADOWBOLT) == CAST_OK) 
                {
                    timeSinceLastSB = 0;
                    if (isMelee) 
                    {
                        // Looks like VL should prioritize shadowbolt differently if
                        // target is in melee range. He seems to get a random cooldown on it, and meleeing when he can.
                        // https://www.youtube.com/watch?v=SNOmg7kE68U&t=53s
                        // https://www.youtube.com/watch?v=dCrDisOWOjU
                        // This may just be some bugged/different behaviour in blizzards spell-priority system, 
                        // but I believe the effect should be the same by adding a random cooldown.
                        shadowBoltTimer = urand(SHADOWBOLT_MELEE_MIN_CD, SHADOWBOLT_MELEE_MAX_CD);
                    }
                    else 
                    {
                        // When not in melee range, there is only a ~2 sec cooldown on shadowbolt, even though
                        // the cast-time is only 1.5 seconds.
                        // https://www.youtube.com/watch?v=nHXfSDVX_ZA
                        shadowBoltTimer = urand(SHADOWBOLT_RANGED_MIN_CD, SHADOWBOLT_RANGED_MAX_CD);
                    }
                }
            }
            else 
            {
                shadowBoltTimer -= diff;
            }
        }

        timeSinceLastSB += diff;
    }
};

struct boss_veknilashAI : public boss_twinemperorsAI
{
    boss_veknilashAI(Creature* pCreature) : boss_twinemperorsAI(pCreature)
    {
        Reset();
    }

    uint32 UpperCut_Timer;
    uint32 UnbalancingStrike_Timer;
    uint32 Scarabs_Timer;
    
    void Reset() override
    {
        SharedReset();
        bugMutationTimer        = boss_veknilashAI::GetBugSpellCooldown();
        UpperCut_Timer          = urand(UPPERCUT_MIN_CD, UPPERCUT_MAX_CD);
        UnbalancingStrike_Timer = urand(UNBALANCING_STRIKE_MIN_CD, UNBALANCING_STRIKE_MAX_CD);

        //Added. Can be removed if its included in DB.
        m_creature->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_SPELL, true);
    }

    void OnEndTeleportVirtual() override
    {
        //todo: anything that needs doing?
    }

    uint32 GetBugSpellCooldown() override
    {
        return urand(MUTATE_BUG_MIN_CD, MUTATE_BUG_MAX_CD);
    }

    uint32 GetBugSpell() override
    {
        return SPELL_MUTATE_BUG;
    }

    Unit *GetPlayerInMeleeRange()
    {
        std::list<HostileReference*> candidates;

        ThreatList const& tList = m_creature->GetThreatManager().getThreatList();
        if (tList.empty())
            return nullptr;

        for (const auto i : tList) {
            Unit* pUnit = m_creature->GetMap()->GetUnit(i->getUnitGuid());
            if (!pUnit) continue;

            if (m_creature->CanReachWithMeleeAutoAttack(pUnit)) {
                candidates.push_back(i);
            }
        }

        if (candidates.empty())
            return nullptr;

        auto it = candidates.begin();
        std::advance(it, candidates.size() - 1);
        return m_creature->GetMap()->GetUnit((*it)->getUnitGuid());
    }
    
    void UpdateEmperor(uint32 diff) override
    {       
        // Vek'nilash goes first, instantly does his yell when we are in combat. 
        if (!didPullDialogue) {
            didPullDialogue = true;
            DoScriptText(irand(SAY_VEKNILASH_AGGRO_4, SAY_VEKNILASH_AGGRO_1), m_creature);
        }

        if(!m_creature->HasAura(SPELL_DOUBLE_ATTACK))
            m_creature->CastSpell(m_creature, SPELL_DOUBLE_ATTACK, true);

        //UnbalancingStrike_Timer
        if (UnbalancingStrike_Timer < diff) {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_UNBALANCING_STRIKE) == CAST_OK) {
                UnbalancingStrike_Timer = urand(UNBALANCING_STRIKE_MIN_CD, UNBALANCING_STRIKE_MAX_CD);
            }
        }
        else {
            UnbalancingStrike_Timer -= diff;
        }

        if (UpperCut_Timer < diff) {
            if (Unit* randomMelee = GetPlayerInMeleeRange()) {
                if (DoCastSpellIfCan(randomMelee, SPELL_UPPERCUT) == CAST_OK) {
                    UpperCut_Timer = urand(UPPERCUT_MIN_CD, UPPERCUT_MAX_CD);
                }
            }
        }
        else {
            UpperCut_Timer -= diff;
        }

        DoMeleeAttackIfReady();
    }

    void KilledUnit(Unit*) override
    {
        if (killSayCooldown == 0) {
            DoScriptText(SAY_VEKNILASH_SLAY, m_creature);
            killSayCooldown = urand(5000, 10000);
        }
    }

    void AttackStart(Unit* who) override
    {
        ScriptedAI::AttackStart(who);
    }
};

struct mob_mastersEye : public ScriptedAI {
    mob_mastersEye(Creature* pCreature) : ScriptedAI(pCreature)
    {
        sLog.outBasic("Masters Eye ctor!");
        Reset();
    }
    
    instance_temple_of_ahnqiraj* m_pInstance;
    uint32 flightUpdate;

    void Reset() override
    {
        instance_temple_of_ahnqiraj* tmpPTr = dynamic_cast<instance_temple_of_ahnqiraj*>(m_creature->GetInstanceData());
        if (!tmpPTr) {
            sLog.outError("boss_twinemperorsAI attempted to cast instance to type instance_temple_of_ahnqiraj, but failed.");
            m_pInstance = nullptr;
        }
        else {
            m_pInstance = (instance_temple_of_ahnqiraj*)m_creature->GetInstanceData();
        }
        flightUpdate = 0;
    }

    void UpdateAI(uint32 const diff) override
    {
        if (m_creature->IsDespawned() || m_pInstance->TwinsDialogueStartedOrDone())
            return;
        if (flightUpdate < diff) {
            m_creature->CastSpell(m_creature, 17131, true); // Start flying 
            m_creature->GetMotionMaster()->MovePoint(0, -8952.7f, 1235.39f, -102.0f, MOVE_FLY_MODE, 0.0f, 4.896f);
            flightUpdate = 5000;
        }
        else {
            flightUpdate -= diff;
        }
    }
};

CreatureAI* GetAI_boss_veknilash(Creature* pCreature)
{
    return new boss_veknilashAI(pCreature);
}

CreatureAI* GetAI_boss_veklor(Creature* pCreature)
{
    return new boss_veklorAI(pCreature);
}

CreatureAI* GetAI_masters_eye(Creature* pCreature)
{
    return new mob_mastersEye(pCreature);
}

CreatureAI* GetAI_twinsBug(Creature* pCreature)
{
    return new mob_TwinsBug(pCreature);
}

void AddSC_boss_twinemperors()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "boss_veknilash";
    newscript->GetAI = &GetAI_boss_veknilash;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "boss_veklor";
    newscript->GetAI = &GetAI_boss_veklor;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_masters_eye";
    newscript->GetAI = &GetAI_masters_eye;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_twins_bug";
    newscript->GetAI = &GetAI_twinsBug;
    newscript->RegisterSelf();
}
