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

/* Nostalrius (inital version Scriptcraft)
** Name: Boss_Cthun
** Complete: who knows
** Comment: so many things
** Category: Temple of Ahn'Qiraj
** Rewritten by Gemt
*/

#include "scriptPCH.h"
#include "temple_of_ahnqiraj.h"
#include <algorithm>

enum eCreatures {
    EMOTE_WEAKENED                  = -1531011,
    MOB_EYE_TENTACLE                = 15726,
    MOB_CLAW_TENTACLE               = 15725,
    MOB_GIANT_CLAW_TENTACLE         = 15728,
    MOB_GIANT_EYE_TENTACLE          = 15334,
    MOB_FLESH_TENTACLE              = 15802,

    MOB_CTHUN_PORTAL                = 15896,
    MOB_SMALL_PORTAL                = 15904,
    MOB_GIANT_PORTAL                = 15910,

    PUNT_CREATURE                   = 15922, //invisible viscidus trigger, used in stomach
};

// C'Thun hotfixes: http://blue.cardplace.com/cache/wow-general/7950998.htm
enum eSpells {
    // Phase 1 spells
    SPELL_FREEZE_ANIMATION          = 16245, // Dummy spell to avoid the eye gazing around during dark glare
    SPELL_ROTATE_TRIGGER            = 26137,
    SPELL_ROTATE_NEGATIVE_360       = 26136,
    SPELL_ROTATE_POSITIVE_360       = 26009,
    SPELL_DARK_GLARE                = 26029,
    
    // Shared spells
    SPELL_GREEN_EYE_BEAM            = 26134,

    // Mob spells
    SPELL_THRASH                    = 3391,
    SPELL_GROUND_TREMOR             = 6524,
    SPELL_TENTACLE_BIRTH            = 26262,
    SPELL_SUBMERGE_VISUAL           = 26234,
    SPELL_SUBMERGE_EFFECT           = 21859, // Must be removed after re-emerge after a submerge to remove immunity

    // spellid 26100 has a more correct knockback effect for giant tentacles, but wrong dmg values

    //SPELL_PUNT_UPWARD               = 16716, // Used to knock people up from stomach. Remove manually after port as it's the wrong spell and applies slowfall
    SPELL_MASSIVE_GROUND_RUPTURE    = 26100, // currently unused, ~1k physical huge knockback, not sure who should do it, if any
    SPELL_GROUND_RUPTURE_PHYSICAL   = 26139, // used by small tentacles
    SPELL_HAMSTRING                 = 26141, //26211 is in DBC with more correct ID?
    SPELL_MIND_FLAY                 = 26143, 
    SPELL_GROUND_RUPTURE_NATURE     = 26478, //used by giant tentacles
    
    //C'thun spells
    
    SPELL_CARAPACE_OF_CTHUN         = 26156, // Makes C'thun invulnerable
    SPELL_DIGESTIVE_ACID_TELEPORT   = 26220, // Not yet used, seems to port C'thun instead of player no matter what.
    SPELL_TRANSFORM                 = 26232, // Initiates the p1->p2 transform
    SPELL_CTHUN_VULNERABLE          = 26235, // Adds the red color. Does not actually him vulnerable, need to remove carapace for that.
    SPELL_MOUTH_TENTACLE            = 26332, // Spawns the tentacle that "eats" you to stomach and mounts the player on it.
};

static std::vector<uint32> const allTentacleTypes
({ MOB_EYE_TENTACLE, MOB_CLAW_TENTACLE, MOB_GIANT_CLAW_TENTACLE, MOB_GIANT_EYE_TENTACLE, MOB_FLESH_TENTACLE,
    MOB_SMALL_PORTAL, MOB_GIANT_PORTAL});

static constexpr uint32 CANNOT_CAST_SPELL_MASK = (UNIT_FLAG_SILENCED | UNIT_FLAG_PACIFIED | UNIT_FLAG_STUNNED
                                                 | UNIT_FLAG_CONFUSED | UNIT_FLAG_FLEEING);
    
static constexpr float stomachPortPosition[4] =
{
    -8562.0f, 2037.0f, -96.0f, 5.05f
};

static constexpr float fleshTentaclePositions[2][4] =
{
    { -8571.0f, 1990.0f, -98.0f, 1.22f },
    { -8525.0f, 1994.0f, -98.0f, 2.12f }
};


static constexpr float eyeTentaclePositions[8][3] =
{
    { -8547.269531f, 1986.939941f, 100.490351f },
    { -8556.047852f, 2008.144653f, 100.598129f },
    { -8577.246094f, 2016.939941f, 100.320351f },
    { -8598.457031f, 2008.178467f, 100.320351f },
    { -8607.269531f, 1986.987671f, 100.490351f },
    { -8598.525391f, 1965.769043f, 100.490351f },
    { -8577.340820f, 1956.940063f, 100.536636f },
    { -8556.115234f, 1965.667725f, 100.598129f }
};

using SpellTarSelectFunction = std::function<Unit*(Creature*)>;

class SpellTimer {
public:
    SpellTimer(Creature* creature, 
        uint32 spellID, 
        uint32 initialCD, 
        std::function<uint32()> resetCD,
        bool triggeredSpell, 
        SpellTarSelectFunction targetSelectFunc, 
        bool retryOnFail = false) :
        m_creature(creature),
        spellID(spellID),
        cooldown(initialCD),
        resetCD(resetCD),
        triggered(triggeredSpell),
        retryOnFail(retryOnFail),
        timeSinceLast(std::numeric_limits<uint32>::max()),
        targetSelectFunc(targetSelectFunc)
    {}

    virtual void Reset(int custom = -1) {
        if (custom >= 0) {
            cooldown = static_cast<uint32>(custom);
        }
        else {
            if (!resetCD)
                cooldown = 0;
            else
                cooldown = resetCD();
        }
    }

    // Returns true when the cooldown reaches < diff, a cast is attempted, and cooldown is reset
    virtual bool Update(uint32 diff) {
        if (cooldown < diff) {
            Unit* target = targetSelectFunc(m_creature);
            bool didCast = false;
            if (target) {
                if(m_creature->AI()->DoCastSpellIfCan(target, spellID, triggered ? CF_TRIGGERED : 0) == CAST_OK) {
                    didCast = true;
                }
            }
            if (retryOnFail && !didCast) {
                return false;
            }
            else {
                if (!resetCD)
                    cooldown = 0;
                else
                    cooldown = resetCD();
                timeSinceLast = 0;
                return true;
            }
        }
        else {
            cooldown -= diff;
            timeSinceLast += diff;
        }
        return false;
    }

    uint32 TimeSinceLast() {
        return timeSinceLast;
    }

protected:
    Creature* m_creature;
    uint32 spellID;
    uint32 cooldown;
    std::function<uint32()> resetCD;
    bool triggered;
    bool retryOnFail;
    uint32 timeSinceLast;
    SpellTarSelectFunction targetSelectFunc;

};

class OnlyOnceSpellTimer : public SpellTimer {
public:
    OnlyOnceSpellTimer(Creature* creature, uint32 spellID, uint32 initialCD, std::function<uint32()> resetCD,
        bool triggeredSpell, SpellTarSelectFunction targetSelectFunc, bool retryOnFail=false) :
        SpellTimer(creature, spellID, initialCD, resetCD, triggeredSpell, targetSelectFunc, retryOnFail),
        didOnce(false)
        {}

    void Reset(int custom = -1) override {
        SpellTimer::Reset(custom);
        didOnce = false;
    }

    bool Update(uint32 diff) override {
        if (!didOnce) {
            if (SpellTimer::Update(diff)) {
                didOnce = true;
            }
        }
        else {
            timeSinceLast += diff;
        }
        return didOnce;
    }

    bool DidCast() {
        return didOnce;
    }
private:
    bool didOnce;
    
};

static Player* SelectRandomAliveNotStomach(instance_temple_of_ahnqiraj* instance)
{
    if (!instance) return nullptr;
    std::list<Player*> temp;
    std::list<Player*>::iterator j;
    Map::PlayerList const& PlayerList = instance->GetMap()->GetPlayers();

    if (!PlayerList.isEmpty())
    {
        for (const auto& itr : PlayerList)
        {
            if (Player* player = itr.getSource())
            {
                if (!player->IsDead() && !player->IsGameMaster() && player->IsInCombat() && !instance->PlayerInStomach(player)) {
                    temp.push_back(player);
                }
            }
        }
    }

    if (temp.empty())
        return nullptr;

    j = temp.begin();

    if (temp.size() > 1) {
        advance(j, urand(0, temp.size() - 1));
    }

    return (*j);
}

// Helper functions for SpellTimer users
static Unit* selectSelfFunc(Creature* c) {
    return c;
}
static Unit* selectTargetFunc(Creature* c) {
    return c->GetVictim();
}

// ================== PHASE 1 CONSTANTS ==================
static constexpr uint32 P1_EYE_TENTACLE_RESPAWN_TIMER   = 45000;
static constexpr uint32 SPELL_ROTATE_TRIGGER_CASTTIME   = 3000;
static constexpr uint32 GREEN_BEAM_PHASE_DURATION       = 45000;
static constexpr uint32 DARK_GLARE_PHASE_DURATION       = 38000; 
static constexpr uint32 DARK_GLARE_COOLING_DOWN         = 1000;
//static constexpr int32  MAX_INITIAL_PULLER_HITS       = 3;     // How many times will c'thun target the initial 
                                                                 // puller with green beam before random target.
static constexpr int32  P1_GREEN_BEAM_COOLDOWN          = 3000;  // Green beam has a 2 sec cast time. If this number is > 2000, 
                                                                 // the cooldown will be P1_GREEN_BEAM_COOLDOWN - 2000
static uint32 const P1_CLAW_TENTACLE_RESPAWN_TIMER      = 5000;  // checked against old footage & current fight
// =======================================================

// ================= TRANSITION CONSTANTS ================
static constexpr uint32 EYE_DEAD_TO_BODY_EMERGE_DELAY   = 4000;
static constexpr uint32 CTHUN_EMERGE_ANIM_DURATION      = 8000;
// =======================================================

// ================== PHASE 2 CONSTANTS ==================
static constexpr uint32 P2_EYE_TENTACLE_RESPAWN_TIMER   = 30000;
static constexpr uint32 GIANT_CLAW_RESPAWN_TIMER        = 60000;
static constexpr uint32 STOMACH_GRAB_COOLDOWN           = 10000;
static constexpr uint32 GIANT_EYE_RESPAWN_TIMER         = 60000;
static constexpr uint32 STOMACH_GRAB_DURATION           = 3250;
static constexpr uint32 WEAKNESS_DURATION               = 45000;
static constexpr uint32 P2_FIRST_GIANT_CLAW_SPAWN       = 8000;
static constexpr uint32 P2_FIRST_EYE_TENTACLE_SPAWN     = 38000;
static constexpr uint32 P2_FIRST_GIANT_EYE_SPAWN        = 38000;
static constexpr uint32 P2_FIRST_STOMACH_GRAB           = 18000 - STOMACH_GRAB_DURATION;
// =======================================================

// ======================= MISC ==========================
static constexpr uint32 GROUND_RUPTURE_DELAY                   = 0;             // ms after spawn that the ground rupture will be cast
static constexpr uint32 HAMSTRING_INITIAL_COOLDOWN             = 2000;          // Claw tentacle hamstring cooldown after spawn/tp
static uint32 hamstringResetCooldownFunc()               { return 5000; } // Claw tentacle hamstring cooldown after use
static uint32 trashResetCooldownFunc()                   { return urand(6000, 12000); }
static uint32 groundTremorResetCooldownFunc()            { return urand(6000, 12000); }
//static constexpr uint32 CLAW_TENTACLE_FIRST_MELEE_DELAY      = 1000; // Earliest possible point for a claw tentacle to melee after spawn/tp
static constexpr uint32 CLAW_TENTACLE_EVADE_PORT_COOLDOWN      = 5000; // How long does a claw tentacle evade before TPing to new target

static constexpr uint32 TENTACLE_BIRTH_DURATION                = 3000; // Duration of birth animation and /afk before tentacles start doing stuff

static constexpr uint32 GIANT_EYE_BEAM_COOLDOWN                = 2500; // How often will giant eye tentacles cast green beam
static constexpr uint32 GIANT_EYE_INITIAL_GREEN_BEAM_COOLDOWN  = 0;    // How long will giant eye wait after spawn before casting UPDATE: use TENTACLE_BIRTH_DURATION 
static constexpr uint32 MIND_FLAY_COOLDOWN_ON_RESIST           = 1500; // How long do we wait if Eye Tentacle MF resists before retrying cast
static constexpr uint32 MIND_FLAY_INITIAL_WAIT_DURATION        = 0;    // How long do we wait after Eye tentacle has spawned until first MF UPDATE: use TENTACLE_BIRTH_DURATION 
static constexpr uint32 TELEPORT_BURIED_DURATION               = 1000; // How long will a claw tentacle say underground before re-emerging on teleport.
// =======================================================

// ================== THE PULL ===========================
/* if defined, the encounter does not pull all players in combat on aggro, but
*  rather aggros the initial puller and then places everyone else in combat 
*  12 seconds later. Sources: https://pastebin.com/BiC33bU5
*  
*  If not defined, the current logic is to target the intial puller 3 times with the 
*  beam before going on a random target. More research should be done to better understand
*  how the pull worked *after* the later nerfs, and also when it was implemented.
*  
*  The one thing that is certain is that in all kills with videos around the time it first became
*  "killable" (april 24th 2006), the 12seconds delayed combat was how it worked.
*  In later kills, towards the end of 2006, people were put in combat as soon as the first beam *hit*
*  the initial puller, but how many times it would hit the initial puller is currently unknown.
*
*  A suggested way to make the pull slightly more challenging is tuning DELAYED_COMBAT_DURATION to 
*  somewhere between 6 and 9 seconds.
*/
#define USE_POSTFIX_PRENERF_PULL_LOGIC
#ifdef USE_POSTFIX_PRENERF_PULL_LOGIC
static constexpr uint32 DELAYED_COMBAT_DURATION = 9000;
#endif
// =======================================================

static constexpr TempSummonType TENTACLE_DESPAWN_FLAG = TEMPSUMMON_CORPSE_TIMED_DESPAWN;

struct cthunTentacle : public ScriptedAI
{
    instance_temple_of_ahnqiraj* m_pInstance;
    float defaultOrientation;

    cthunTentacle(Creature* pCreature) :
        ScriptedAI(pCreature)
    {
        m_pInstance = dynamic_cast<instance_temple_of_ahnqiraj*>(pCreature->GetInstanceData());
        if (!m_pInstance)
            sLog.outError("C'thun tentacle could not find it's instance");

        SetCombatMovement(false);
        defaultOrientation = m_creature->GetOrientation();
    }

    void Reset() override
    {
        m_creature->AddUnitState(UNIT_STAT_ROOT);
        m_creature->StopMoving();
        m_creature->SetRooted(true);
        m_creature->SetInCombatWithZone();
    }

    void Aggro(Unit* pWho) override
    {
        ScriptedAI::Aggro(pWho);
        m_creature->SetInCombatWithZone();
    }

    bool UpdateCthunTentacle(uint32 diff)
    {
        if (!m_pInstance) return false;

        if (!m_pInstance->GetPlayerInMap(true, false)) {
            if (TemporarySummon* tmpS = dynamic_cast<TemporarySummon*>(m_creature)) {
                tmpS->UnSummon();
            }
            else {
                sLog.outError("CThunTentacle could not cast creature to TemporarySummon*");
            }
            //EnterEvadeMode();
            //m_creature->OnLeaveCombat();
            //Reset();
            return false;
        }

        // This makes the mob behave like frostnovaed mobs etc, that is,
        // retargetting another top-threat target if current leaves melee range
        m_creature->AddUnitState(UNIT_STAT_ROOT);
        m_creature->StopMoving();
        m_creature->SetRooted(true);
        return true;
    }
    
    bool UpdateMelee(bool resetOrientation)
    {
        if (!SelectHostileTargetMelee()) {
            DoStopAttack();
            if(resetOrientation)
                m_creature->SetOrientation(defaultOrientation);
            return false;
        }
        else {
            DoMeleeAttackIfReady();
            return true;
        }
    }

    // Custom targetting function.
    // Will only target hostile players/pets that are in melee range.
    // If current target leaves melee range, his threat is reset.
    // IF there are no targets in melee range, the creature will
    // not target anyone.
    // Returns true when the creature has a target.
    bool SelectHostileTargetMelee()
    {
        if (!m_creature->IsAlive())
            return false;

        // If we're casting something its sort-of counter intuitive to return true,
        // but it also means we do have a valid target already, even if it's not melee.
        // DoMeleeAttack, which is typically called on true return, will check
        // m_creature->IsNonMeleeSpellCasted(false) internally anyway.
        if (m_creature->IsNonMeleeSpellCasted(false)) {
            return true;
        }

        Unit* oldTarget = m_creature->GetVictim();
        Unit* target = nullptr;

        // First checking if we have some taunt on us
        Unit::AuraList const& tauntAuras = m_creature->GetAurasByType(SPELL_AURA_MOD_TAUNT);
        for (auto it = tauntAuras.crbegin(); it != tauntAuras.crend(); it++) {
            Unit* caster = (*it)->GetCaster();
            if (!caster) continue;

            if (caster->IsInMap(m_creature) && caster->IsTargetable(true, false) && m_creature->CanReachWithMeleeAutoAttack(caster))
            {
                target = caster;
                break;
            }
            else // Target is not in melee and reset his threat    
                m_creature->GetThreatManager().modifyThreatPercent(caster, -100);
        }
        // So far so good. If we have a target after this loop it means we have a valid target in melee range.

        // If we dont have a target we need to keep searching through the threatlist
        if (!target)
        {
            Unit* tmpTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0, nullptr, SELECT_FLAG_IN_MELEE_RANGE);

            // Resetting threat of old target if it has left melee range
            if (oldTarget && tmpTarget != oldTarget && !oldTarget->CanReachWithMeleeAutoAttack(m_creature))
                m_creature->GetThreatManager().modifyThreatPercent(oldTarget, -100);

            // Need to call getHostileTarget to force an update of the threatlist, bleh
            if (tmpTarget)
                target = m_creature->GetThreatManager().getHostileTarget();
        }

        if (target)
        {
            // Nostalrius : Correction bug sheep/fear
            if (!m_creature->HasUnitState(UNIT_STAT_STUNNED | UNIT_STAT_PENDING_STUNNED | UNIT_STAT_FEIGN_DEATH | UNIT_STAT_CONFUSED | UNIT_STAT_FLEEING) 
                && (!m_creature->HasAuraType(SPELL_AURA_MOD_FEAR) || m_creature->HasAuraType(SPELL_AURA_PREVENTS_FLEEING)) && !m_creature->HasAuraType(SPELL_AURA_MOD_CONFUSE))
            {
                m_creature->SetInFront(target);
                AttackStart(target);
            }
            return true;
        }
        return false;
    }
};

struct cthunPortalTentacle : public cthunTentacle
{
private:
    uint32 birthTimer;
public:
    ObjectGuid portalGuid;
    OnlyOnceSpellTimer groundRuptureTimer;

    cthunPortalTentacle(Creature* pCreature, uint32 groundRuptSpellId, uint32 portalId) :
        cthunTentacle(pCreature),
        groundRuptureTimer(pCreature, groundRuptSpellId, GROUND_RUPTURE_DELAY, 0, true, selectSelfFunc)
    {
        Creature* pPortal = DoSpawnCreature(portalId, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 500); //TEMPSUMMON_DEAD_DESPAWN, 120000
        if (pPortal) {
            pPortal->SetInCombatWithZone();
            portalGuid = pPortal->GetGUID();
            FixPortalPosition();
        }
        else {
            sLog.outError("cthunPortalTentacle failed to spawn portal with entry %d", portalId);
        }
    }

    void DespawnPortal() {
        if (Creature* pCreature = m_creature->GetMap()->GetCreature(portalGuid)) {
            if (TemporarySummon* ts = dynamic_cast<TemporarySummon*>(pCreature)) {
                ts->UnSummon();
                portalGuid = 0;
            }
            else {
                sLog.outError("Unable to despawn cthunPortalTentacle portal, could not cast to temporarySummon*");
            }
        }
    }

    void Reset() override
    {
        cthunTentacle::Reset();
        groundRuptureTimer.Reset();
        birthTimer = TENTACLE_BIRTH_DURATION;
        m_creature->AttackStop(true);
        //DoStopAttack(true);
    }

    void JustDied(Unit*) override
    {
        DespawnPortal();
    }

    bool UpdatePortalTentacle(uint32 diff)
    {
        if (!cthunTentacle::UpdateCthunTentacle(diff)) {
            DespawnPortal();
            //m_creature->ForcedDespawn(500);
            return false;
        }

        if (groundRuptureTimer.Update(diff)) {
            if (birthTimer > diff) {
                // Only want to cast it once, and it cant be done in ctor because groundRupture interrupts the animation.
                if (birthTimer == TENTACLE_BIRTH_DURATION) {
                    DoCastSpellIfCan(m_creature, SPELL_TENTACLE_BIRTH);
                }
                birthTimer -= diff;
            }
        }
        return birthTimer <= diff;
    }

    void FixPortalPosition() {
        Unit* pPortal = nullptr;
        if (portalGuid && m_pInstance)
            pPortal = m_pInstance->GetCreature(portalGuid);
        if (!pPortal)
            return;
        uint32 portalEntry = pPortal->GetEntry();
        float radius;
        switch (portalEntry) {
        case MOB_SMALL_PORTAL: radius = 3.0f; break;
        case MOB_GIANT_PORTAL: radius = 8.0f; break;
        default:
            radius = 3.0f;
            sLog.outError("C'thun FixPortalPosition unknown portalID %d", portalEntry);
        }
        //Searching for best z-coordinate to place the portal
        float centerX = m_creature->GetPositionX();
        float centerY = m_creature->GetPositionY();
        float useZ = m_creature->GetPositionZ();
        float angle = 360.0f / 8.0f;
        float highZ = useZ;
        float avg_height = 0.0f;
        uint8 inliers = 0;
        for (uint8 i = 0; i < 8; i++)
        {
            float x = centerX + cos(((float)i * angle) * (3.14f / 180.0f)) * radius;
            float y = centerY + sin(((float)i * angle) * (3.14f / 180.0f)) * radius;
            float z = m_creature->GetMap()->GetHeight(x, y, useZ);
            float deviation = abs(useZ - z);
            // Any deviation >= 0.5 we consider outliers as we dont want to handle sloped terrain
            if (deviation < 0.5f) {
                if (z > highZ)
                    highZ = z;
                avg_height += z;
                inliers++;
            }
        }
        avg_height /= inliers;
        // Only move portal up if the average height is higher than the creatures height
        if (avg_height > useZ) {
            useZ = highZ;
        }
        pPortal->NearLandTo(m_creature->GetPositionX(), m_creature->GetPositionY(), useZ, 0);
    }

};

struct clawTentacle : public cthunPortalTentacle
{
    uint32 EvadeTimer;
    SpellTimer hamstringTimer;
    uint32 teleportBuriedTimer;
    uint32 feignDeathTimer;

    enum eClawState {
        NORMAL,
        FEIGN_IN_PROCES,
        BURRIED,
    };
    eClawState clawState;

    clawTentacle(Creature* pCreature, uint32 groundRuptSpellId, uint32 portalId) :
        cthunPortalTentacle(pCreature, groundRuptSpellId, portalId),
        EvadeTimer(0),
        hamstringTimer(pCreature, SPELL_HAMSTRING, HAMSTRING_INITIAL_COOLDOWN, hamstringResetCooldownFunc, false, selectTargetFunc, true)
    {
    }

    void Reset() override
    {
        cthunPortalTentacle::Reset();
        hamstringTimer.Reset(HAMSTRING_INITIAL_COOLDOWN);
        EvadeTimer = CLAW_TENTACLE_EVADE_PORT_COOLDOWN;
        teleportBuriedTimer = 0;

        // If reset is called after a teleport, it regains full HP.
        // Todo: Should we also clear any debuffs?
        m_creature->SetFullHealth();

        clawState = eClawState::NORMAL;
        feignDeathTimer = 0;
    }

    bool UpdateClawTentacle(uint32 diff)
    {
        if (!cthunPortalTentacle::UpdatePortalTentacle(diff))
            return false;

        switch (clawState) {
        case NORMAL:
            updateNormal(diff);
            return true;
            break;
        case FEIGN_IN_PROCES:
            updateFeign(diff);
            return false;
            break;
        case BURRIED:
            updateBurried(diff);
            return false;
            break;
        default:
            sLog.outError("Unknown UpdateClawTentacle state.");
            return false;
        }
    }

private:
    void updateNormal(uint32 diff) {

        if (UpdateMelee(false)) {
            EvadeTimer = CLAW_TENTACLE_EVADE_PORT_COOLDOWN;
            hamstringTimer.Update(diff);
        }
        else {
            if (EvadeTimer < diff) {
                clawState = eClawState::FEIGN_IN_PROCES;
                feignDeathTimer = 1000;
                m_creature->CastSpell(m_creature, SPELL_SUBMERGE_VISUAL, false);
            }
            else {
                EvadeTimer -= diff;
            }
        }
        /*
        if (Unit* uP = CheckForMelee()) {
            EvadeTimer = CLAW_TENTACLE_EVADE_PORT_COOLDOWN;
        }
        else {
            // Initiate submerge->teleport->birth sequence if it's time
            if (EvadeTimer < diff) {
                DoStopAttack(); // Added after testing
                clawState = eClawState::FEIGN_IN_PROCES;
                feignDeathTimer = 1000;
                m_creature->CastSpell(m_creature, SPELL_SUBMERGE_VISUAL, false);
            }
            else {
                EvadeTimer -= diff;
            }
        }
        */
    }

    void updateFeign(uint32 diff) {
        if (feignDeathTimer < diff) {
            clawState = eClawState::BURRIED;
            teleportBuriedTimer = TELEPORT_BURIED_DURATION;
            setVisibility(false);
        }
        else {
            feignDeathTimer -= diff;
        }
    }

    void updateBurried(uint32 diff) {
        if (teleportBuriedTimer < diff) {
            // Done being burried, time to teleport on a new target.
            // If we're successfull in selecting a new target, reset will reset
            // all necessary cooldowns, including setting the correct clawState (NORMAL)
            if (TeleportOnNewRandomTarget()) {
                DoResetThreat();
                m_creature->RemoveAurasDueToSpell(SPELL_SUBMERGE_VISUAL);
                setVisibility(true);
                m_creature->RemoveAurasDueToSpell(SPELL_SUBMERGE_EFFECT);
                Reset();
            }
        }
        else {
            teleportBuriedTimer -= diff;
        }
    }

    bool TeleportOnNewRandomTarget()
    {
        if (Player* target = SelectRandomAliveNotStomach(m_pInstance))
        {
            float x;
            float y;
            float z;
            m_creature->GetRandomPoint(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0.5f, x, y, z);
            m_creature->NearTeleportTo(x, y, z, 0);

            if (Creature* pCreature = m_creature->GetMap()->GetCreature(portalGuid)) {
                FixPortalPosition();
            }
            return true;
        }
        return false;
    }

    void setVisibility(bool visiblityOn) {
        Creature* pCreature = m_creature->GetMap()->GetCreature(portalGuid);
        if (visiblityOn) {
            m_creature->SetVisibility(VISIBILITY_ON);
            if (pCreature)
                pCreature->SetVisibility(VISIBILITY_ON);
        }
        else {
            m_creature->SetVisibility(VISIBILITY_OFF);
            if (pCreature)
                pCreature->SetVisibility(VISIBILITY_OFF);
        }
    }
};
    
struct eye_tentacleAI : public cthunPortalTentacle
{
    uint32 nextMFAttempt;
    ObjectGuid currentMFTarget;

    eye_tentacleAI(Creature* pCreature) :
        cthunPortalTentacle(pCreature, SPELL_GROUND_RUPTURE_PHYSICAL, MOB_SMALL_PORTAL)
    {
        eye_tentacleAI::Reset();
    }

    void Reset() override
    {
        cthunPortalTentacle::Reset();
        nextMFAttempt = MIND_FLAY_INITIAL_WAIT_DURATION;
        currentMFTarget = 0;
    }

    void AttackStart(Unit* who) override
    {
        // Prevents AttacStart from stopping the cast animation
        if (!m_creature->IsNonMeleeSpellCasted(false)) {
            ScriptedAI::AttackStart(who);
        }
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!cthunPortalTentacle::UpdatePortalTentacle(diff))
            return;

        if (nextMFAttempt > diff) {
            nextMFAttempt -= diff;
        }
        else {
            nextMFAttempt = 0;
        }

        // If we are not already casting, try to start casting
        if (!m_creature->GetCurrentSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL))
        {
            currentMFTarget = 0;
            bool didCast = false;
            // Rough check against common auras that prevent the creature from casting,
            // before getting a random target etc
            if (!m_creature->HasFlag(UNIT_FIELD_FLAGS, CANNOT_CAST_SPELL_MASK)) {
                // nextMFAttempt acts as a fake gcd in case of resist
                if (nextMFAttempt == 0) {
                    if (Player* target = SelectRandomAliveNotStomach(m_pInstance))
                    {
                        if (DoCastSpellIfCan(target, SPELL_MIND_FLAY) == CAST_OK) {
                            currentMFTarget = target->GetGUID();
                            m_creature->SetFacingToObject(target);
                            m_creature->SetTargetGuid(currentMFTarget);
                            didCast = true;
                            nextMFAttempt = MIND_FLAY_COOLDOWN_ON_RESIST;
                        }
                    }

                }
            }
            if (!didCast) {
                UpdateMelee(false);
            }

        }
        else {
            // Stop casting on current target if it's been ported to stomach
            if (Unit* currentCastTarget = m_creature->GetMap()->GetPlayer(currentMFTarget)) {
                if (m_pInstance->PlayerInStomach(currentCastTarget)) {
                    m_creature->InterruptSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
                }
            }
        }
    }
};

struct claw_tentacleAI : public clawTentacle
{
    claw_tentacleAI(Creature* pCreature) :
        clawTentacle(pCreature, SPELL_GROUND_RUPTURE_PHYSICAL, MOB_SMALL_PORTAL)
    {
        claw_tentacleAI::Reset();
    }

    void Reset() override
    {
        clawTentacle::Reset();
    }

    void UpdateAI(uint32 const diff) override
    {
        clawTentacle::UpdateClawTentacle(diff);
    }
};

struct giant_claw_tentacleAI : public clawTentacle
{
    SpellTimer groundTremorTimer;
    SpellTimer trashTimer;

    giant_claw_tentacleAI(Creature* pCreature) :
        clawTentacle(pCreature, SPELL_GROUND_RUPTURE_NATURE, MOB_GIANT_PORTAL),
        groundTremorTimer(pCreature, SPELL_GROUND_TREMOR, groundTremorResetCooldownFunc(), groundTremorResetCooldownFunc, true, selectTargetFunc, true),
        trashTimer(pCreature, eSpells::SPELL_THRASH, trashResetCooldownFunc(), trashResetCooldownFunc, false, selectTargetFunc, true)
    {
        giant_claw_tentacleAI::Reset();
    }

    void Reset() override
    {
        clawTentacle::Reset();
        groundTremorTimer.Reset();
        trashTimer.Reset();
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!clawTentacle::UpdateClawTentacle(diff))
            return;

        groundTremorTimer.Update(diff);
        trashTimer.Update(diff);
    }
};

struct giant_eye_tentacleAI : public cthunPortalTentacle
{
    uint32 BeamTimer;
    ObjectGuid beamTargetGuid;
    bool isCasting;
    giant_eye_tentacleAI(Creature* pCreature) :
        cthunPortalTentacle(pCreature, SPELL_GROUND_RUPTURE_NATURE, MOB_GIANT_PORTAL)
    {
        giant_eye_tentacleAI::Reset();
    }
    void Reset() override
    {
        cthunPortalTentacle::Reset();
        BeamTimer = GIANT_EYE_INITIAL_GREEN_BEAM_COOLDOWN;
        isCasting = false;
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!isCasting)
        {
            if (!cthunPortalTentacle::UpdatePortalTentacle(diff))
                return;
        }

        if (!m_creature->GetCurrentSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL)) {
            beamTargetGuid = 0;
            isCasting = false;
        }

        if (BeamTimer < diff) {
            // Rough check against common auras that prevent the creature from casting,
            // before getting a random target etc
            if (!m_creature->HasFlag(UNIT_FIELD_FLAGS, CANNOT_CAST_SPELL_MASK)) {
                if (Player* target = SelectRandomAliveNotStomach(m_pInstance)) {
                    // need to check if we can cast before doing so, because if we update target
                    // after initiating the cast, the cast animation dissapear for some reason
                    if (CanCastSpell(target, sSpellMgr.GetSpellEntry(SPELL_GREEN_EYE_BEAM), false) == CanCastResult::CAST_OK) {
                        beamTargetGuid = target->GetObjectGuid();
                        m_creature->SetTargetGuid(target->GetObjectGuid());
                        m_creature->SetFacingToObject(target);
                        m_creature->CastSpell(target, SPELL_GREEN_EYE_BEAM, false);
                        isCasting = true;
                        BeamTimer = GIANT_EYE_BEAM_COOLDOWN;
                    }
                }
            }
        }
        else {
            BeamTimer -= diff;
            if (m_creature->GetCurrentSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL)) {
                // Stop casting on current target if it's been ported to stomach
                // and immediately start casting on a new target
                if (Unit* currentCastTarget = m_creature->GetMap()->GetPlayer(beamTargetGuid)) {
                    if (m_pInstance->PlayerInStomach(currentCastTarget)) {
                        m_creature->InterruptNonMeleeSpells(false);
                        BeamTimer = 0;
                    }
                }
            }
        }
        if (!isCasting)
        {
            UpdateMelee(false);
        }
    }
};

struct flesh_tentacleAI : public cthunTentacle
{
    ScriptedInstance* m_pInstance;

    flesh_tentacleAI(Creature* pCreature) : cthunTentacle(pCreature)
    {
        flesh_tentacleAI::Reset();
    }
    
    void Reset()  override
    {
        cthunTentacle::Reset();
    }

    void UpdateAI(uint32 const diff)  override
    {
        UpdateMelee(true);
    }
};

struct eye_of_cthunAI : public ScriptedAI
{
    // The eye phases can be a bit difficult to decode due to cast time and "cooling down" duration 
    // of red beam.
    // There should be 45 seconds of "green beam phase"
    // cast time of dark glare is 3 seconds
    // once dark glare is up, boss rotates and keeps dark glare up for 38 seconds
    // after 38 seconds he stops rotating and removes dark glare from himself, this is a 1 second period where nothing happens
    // he then starts a new 45 seconds of green beam
    // Dark glare should start casting every 86 seconds
    // 45 sec green beam
    // 3 sec cast dark glare
    // 38 sec dark glare
    // 1 sec "cooling down"
    // = 86 seconds
    instance_temple_of_ahnqiraj* m_pInstance;

    bool IsAlreadyPulled;

    uint32 eyeBeamCooldown;
    uint32 eyeBeamCastCount;
    //uint32 eyeBeamPhaseDuration;
    //uint32 darkGlarePhaseDuration;
    
    ObjectGuid initialPullerGuid;
    enum CthunEyePhase {
        GREEN_BEAM,
        DARK_GLARE_CAST,
        DARK_GLARE,
        DARK_GLARE_COOLING
    };
    CthunEyePhase currentPhase;

    uint32 greenBeamPhaseTimer;
    uint32 darkGlareCastTimer;
    uint32 darkGlareTimer;
    uint32 darkGlareCoolingTimer;

    eye_of_cthunAI(Creature* pCreature) :
        ScriptedAI(pCreature)
    {
        SetCombatMovement(false);

        m_pInstance = dynamic_cast<instance_temple_of_ahnqiraj*>(pCreature->GetInstanceData());
        if (!m_pInstance)
            sLog.outError("SD0: No Instance eye_of_cthunAI");

        Reset();
    }

    void Pull(Unit* puller) {

        m_creature->SetFactionTemporary(14);

        initialPullerGuid = puller->GetObjectGuid();
        CastGreenBeam(puller);
        
        IsAlreadyPulled = true;
    }

    void Aggro(Unit* puller) override
    {
        // Just in case someone manages to get through the AggroRadius logic in C'thuns AI
        // we make sure the proper pull-sequence is initiated by calling C'thuns attackstart.
        if (!m_creature->IsInCombat()) {
            if (Creature* pCthun = m_pInstance->GetSingleCreatureFromStorage(NPC_CTHUN)) {
                pCthun->AI()->AttackStart(puller);
            }
        }
    }

    void Reset() override
    {
        currentPhase = GREEN_BEAM;
        initialPullerGuid = 0;
        eyeBeamCastCount = 0;
        eyeBeamCooldown = P1_GREEN_BEAM_COOLDOWN;
        greenBeamPhaseTimer = GREEN_BEAM_PHASE_DURATION;

        IsAlreadyPulled = false;

        if (m_creature) {
            m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            // need to reset the orientation in case of wipe during glare phase
            m_creature->SetOrientation(3.44f);
            RemoveGlarePhaseSpells();
        }
        else {
            sLog.outError("eye_of_cthunAI: Reset called, but m_creature does not exist.");
        }
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_pInstance)
            return;

        if (!IsAlreadyPulled) {
            m_creature->SetTargetGuid(0);
            return;
        }

        // No combat reset managment. C'thuns body will reset this creature when needed.
        
        // Yes, could easily make all these different timers into just two, but
        // this approach is much easier to understand, debug and tune.
        switch (currentPhase) {
        case GREEN_BEAM:
            if (greenBeamPhaseTimer < diff) {
                if (EnterDarkGlarePhase()) {
                    darkGlareCastTimer = SPELL_ROTATE_TRIGGER_CASTTIME;
                    currentPhase = DARK_GLARE_CAST;
                }
            }
            else {
                greenBeamPhaseTimer -= diff;
                UpdateGreenBeamPhase(diff);
            }
            break;
        case DARK_GLARE_CAST:
            if (darkGlareCastTimer < diff) {
                currentPhase = DARK_GLARE;
                darkGlareTimer = DARK_GLARE_PHASE_DURATION;
            }
            else {
                darkGlareCastTimer -= diff;
            }
            break;
        case DARK_GLARE:
            if (darkGlareTimer < diff) {
                RemoveGlarePhaseSpells();
                currentPhase = DARK_GLARE_COOLING;
                darkGlareCoolingTimer = DARK_GLARE_COOLING_DOWN;
            }
            else {
                darkGlareTimer -= diff;
            }
            break;
        case DARK_GLARE_COOLING:
            if (darkGlareCoolingTimer < diff) {
                currentPhase = GREEN_BEAM;
                greenBeamPhaseTimer = GREEN_BEAM_PHASE_DURATION;
                eyeBeamCooldown = 0;
            }
            else {
                darkGlareCoolingTimer -= diff;
            }
            break;
        default:
            sLog.outError("CThun eye update called with incorrect state: %d", currentPhase);
        }
    }
    
    void UpdateGreenBeamPhase(uint32 diff)
    {
        if (m_creature->HasAura(SPELL_FREEZE_ANIMATION))
            m_creature->RemoveAurasDueToSpell(SPELL_FREEZE_ANIMATION);

        if (eyeBeamCooldown < diff) {
            Unit* target = nullptr;

#ifdef USE_POSTFIX_PRENERF_PULL_LOGIC
            target = SelectRandomAliveNotStomach(m_pInstance);
#else 
            // We force the initial puller as the target for MAX_INITIAL_PULLER_HITS
            if (eyeBeamCastCount < MAX_INITIAL_PULLER_HITS) {
                target = m_pInstance->GetMap()->GetPlayer(initialPullerGuid);
            }
            else {
                target = SelectRandomAliveNotStomach(m_pInstance);
            }
#endif
            if (target) {
                CastGreenBeam(target);
            }
        }
        else {
            eyeBeamCooldown -= diff;
        }
    }

    void AttackStart(Unit* pUnit) override
    {
        // dont do nothin'
    }

    bool EnterDarkGlarePhase()
    {
        m_creature->InterruptNonMeleeSpells(false);
        //Select random target for dark beam to start on and start the trigger
        if (Unit* target = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0)) {
            // Remove the target focus but allow the boss to face the current victim
            DoStopAttack();
            m_creature->SetFacingToObject(target);
            if (DoCastSpellIfCan(m_creature, SPELL_ROTATE_TRIGGER) == CAST_OK) {
                if (!m_creature->HasAura(SPELL_FREEZE_ANIMATION)) {
                    m_creature->CastSpell(m_creature, SPELL_FREEZE_ANIMATION, true);
                }
                m_creature->SetTargetGuid(ObjectGuid());
                return true;
            }
        }
        return false;
    }
    
    void RemoveGlarePhaseSpells() {
        if (m_creature->HasAura(SPELL_ROTATE_NEGATIVE_360)) {
            m_creature->RemoveAurasDueToSpell(SPELL_ROTATE_NEGATIVE_360);
        }
        else if (m_creature->HasAura(SPELL_ROTATE_POSITIVE_360)) {
            m_creature->RemoveAurasDueToSpell(SPELL_ROTATE_POSITIVE_360);
        }
    }

    bool CastGreenBeam(Unit* target)
    {
        if (DoCastSpellIfCan(target, SPELL_GREEN_EYE_BEAM) == CAST_OK) {
            m_creature->SetTargetGuid(target->GetObjectGuid());
            ++eyeBeamCastCount;
            eyeBeamCooldown = P1_GREEN_BEAM_COOLDOWN;
            return true;
        }
        return false;
    }
};

struct cthunAI : public ScriptedAI
{
    enum CThunPhase
    {
        PHASE_EYE_NORMAL = 0,
        PHASE_EYE_DARK_GLARE = 1,
        PHASE_PRE_TRANSITION = 2,
        PHASE_TRANSITION = 3,
        PHASE_CTHUN_INVULNERABLE = 4,
        PHASE_CTHUN_WEAKENED = 5,
        PHASE_CTHUN_DONE = 6,
    };

    instance_temple_of_ahnqiraj* m_pInstance;

    bool inProgress;
    CThunPhase currentPhase;

    // P1 timers
    uint32 eyeTentacleTimer_p1;
    uint32 clawTentacleTimer_p1;

    // P2 timers
    uint32 weaknessTimer;
    uint32 eyeTentacleTimer;
    uint32 cthunEmergeTimer;
    uint32 giantEyeTentacleTimer;
    uint32 stomachEnterPortTimer;
    uint32 giantClawTentacleTimer;
    uint32 nextStomachEnterGrabTimer;

#ifdef USE_POSTFIX_PRENERF_PULL_LOGIC
    uint32 delayedCombatEntryTimer;
    bool isInCombatWithZone;
#endif

    ObjectGuid eyeGuid;
    ObjectGuid puntCreatureGuid;
    ObjectGuid StomachEnterTargetGUID;

    std::vector<ObjectGuid> fleshTentacles;

    uint32 wipeRespawnEyeTimer;

    cthunAI(Creature* pCreature) : 
        ScriptedAI(pCreature),
        wipeRespawnEyeTimer(0)
    {
        SetCombatMovement(false);

        m_pInstance = (instance_temple_of_ahnqiraj*)pCreature->GetInstanceData();
        if (!m_pInstance)
            sLog.outError("SD0: No Instance for cthunAI");

        if (Creature* pPortal = DoSpawnCreature(MOB_CTHUN_PORTAL, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_CORPSE_DESPAWN, 0)) {
            pPortal->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
        }

        Reset();
    }

    void AttackStart(Unit* who) override
    {
        if (!m_creature->IsInCombat()) {
            Creature* pEye = m_pInstance->GetCreature(eyeGuid);
            if (!pEye) {
                sLog.outError("cthunAI::AggroRadius could not find pEye");
                return;
            }
            eye_of_cthunAI* eyeAI = (eye_of_cthunAI*)pEye->AI();
            eyeAI->Pull(who);
#ifdef USE_POSTFIX_PRENERF_PULL_LOGIC
            m_creature->SetInCombatWith(who);
            pEye->SetInCombatWith(who);
#else
            m_creature->SetInCombatWithZone();
            pEye->SetInCombatWithZone();
#endif
            if (m_pInstance) {
                m_pInstance->SetData(TYPE_CTHUN, IN_PROGRESS);
            }
        }
        else {
            ScriptedAI::AttackStart(who);
        }
    }
   
    void JustReachedHome() override
    {
        if(m_pInstance)
            m_pInstance->SetData(TYPE_CTHUN, FAIL);
    }

    void Reset() override
    {
#ifdef USE_POSTFIX_PRENERF_PULL_LOGIC
        delayedCombatEntryTimer = DELAYED_COMBAT_DURATION;
        isInCombatWithZone = false;
#endif
        inProgress = false;
        currentPhase = PHASE_EYE_NORMAL;
        if (!m_pInstance)
            return;
        
        cthunEmergeTimer        = CTHUN_EMERGE_ANIM_DURATION;
        clawTentacleTimer_p1    = P1_CLAW_TENTACLE_RESPAWN_TIMER;
        eyeTentacleTimer_p1     = P1_EYE_TENTACLE_RESPAWN_TIMER;

        ResetartUnvulnerablePhase(false);

        // Reset visibility
        m_creature->SetVisibility(VISIBILITY_OFF);
        m_creature->InterruptNonMeleeSpells(false);
        if (m_creature->HasAura(SPELL_CTHUN_VULNERABLE)) {
            m_creature->RemoveAurasDueToSpell(SPELL_CTHUN_VULNERABLE);
        }
        // Demorph should set C'thuns modelId back to burrowed. 
        // Also removing SPELL_TRANSFORM in case of reset just as he was casting that.
        m_creature->RemoveAurasDueToSpell(SPELL_TRANSFORM);
        m_creature->DeMorph();

        m_creature->SetVisibility(VISIBILITY_ON);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                
        
        // Hack to allow eye-respawning with .respawn chat-command. 
        // On regular wipe in p2 it's respawned from UpdateAI()
        if (!wipeRespawnEyeTimer) {
            CheckRespawnEye();
        }

        // Force despawn any tentacles or portals alive. 
        std::list<Creature*> creaturesToDespawn;
        GetCreatureListWithEntryInGrid(creaturesToDespawn, m_creature, allTentacleTypes, 2000.0f);
        for (const auto it : creaturesToDespawn) {
            if (cthunPortalTentacle* cpt = dynamic_cast<cthunPortalTentacle*>(it->AI())) {
                cpt->DespawnPortal();
            }
            if (TemporarySummon* ts = dynamic_cast<TemporarySummon*>(it)) {
                ts->UnSummon();
            }
        }
        
        //if (m_pInstance && m_creature->IsAlive())
        //    m_pInstance->SetData(TYPE_CTHUN, NOT_STARTED);
    }

    void CheckRespawnEye()
    {
        Creature* pEye = nullptr;
        if (m_creature->IsDead()) {
            // Despawning the eye if something weird has happened and C'thun is dead.
            if (pEye = m_pInstance->GetCreature(eyeGuid)) {
                pEye->ForcedDespawn();
            }
        }
        else {
            // Respawning eye if it exists, but is dead.
            // Otherwise attempting to spawn a new eye
            if (pEye = m_pInstance->GetCreature(eyeGuid)) {
                eye_of_cthunAI* eyeAI = (eye_of_cthunAI*)pEye->AI();
                if (!pEye->IsAlive()) {
                    pEye->Respawn();
                    eyeAI->Reset(); // todo: remove if we KNOW that creature::respawn() calls Reset()
                }
                else {
                    eyeAI->EnterEvadeMode();
                }
            }
            else if (pEye = DoSpawnCreature(NPC_EYE_OF_C_THUN, 0, 0, 0, 3.44f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, EYE_DEAD_TO_BODY_EMERGE_DELAY)) {
                eyeGuid = pEye->GetGUID();
            }
            else {
                sLog.outError("C'thun was unable to summon it's eye");
            }
        }
    }

    void SummonedCreatureJustDied(Creature* pCreature) override
    {
        if (pCreature->GetEntry() == MOB_FLESH_TENTACLE) {
            auto it = std::find(fleshTentacles.begin(), fleshTentacles.end(), pCreature->GetObjectGuid());
            if (it != fleshTentacles.end())
                fleshTentacles.erase(it);

        }
        else if (pCreature->GetEntry() == NPC_EYE_OF_C_THUN) {
            currentPhase = PHASE_PRE_TRANSITION;
        }
    }

    void JustSummoned(Creature* pCreature) override
    {
        if (pCreature->GetEntry() == MOB_FLESH_TENTACLE) {
            if (fleshTentacles.size() > 1) {
                sLog.outError("Flesh tentacle summoned, but there are already %i tentacles up.", fleshTentacles.size());
            }
            fleshTentacles.push_back(pCreature->GetGUID());
        }
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_pInstance)
            return;

        // Delaying respawn of eye if it was a wipe so we get the re-emerge animation before spawn
        if (wipeRespawnEyeTimer > 0) {
            wipeRespawnEyeTimer -= std::min(diff, wipeRespawnEyeTimer);
            if (wipeRespawnEyeTimer < diff) {
                CheckRespawnEye();
                wipeRespawnEyeTimer = 0;
            }
        }

        if (!inProgress) {
            // Wait with calling aggroRadius until eye has respawned
            if (!wipeRespawnEyeTimer && AggroRadius()) {
                inProgress = true;
            }
            else {
                return;
            }
        }
        // Not resetting during transition phase, just wait until it's over, then we reset.
        else if (!m_pInstance->GetPlayerInMap(true, false) && currentPhase != PHASE_TRANSITION && currentPhase != PHASE_PRE_TRANSITION) {
            inProgress = false;
            wipeRespawnEyeTimer = 5000; 
            EnterEvadeMode();
            // C'thuns eye will enter evade mode through C'thuns Reset() call
        }

#ifdef USE_POSTFIX_PRENERF_PULL_LOGIC
        if (!isInCombatWithZone) {
            if (delayedCombatEntryTimer < diff) {
                isInCombatWithZone = true;
                m_creature->SetInCombatWithZone();
                if (Creature* pEye = m_pInstance->GetCreature(eyeGuid)) {
                    pEye->SetInCombatWithZone();
                }
            }
            else {
                delayedCombatEntryTimer -= diff;
            }
        }
#endif

        m_creature->SetTargetGuid(0);

        switch (currentPhase) {
        case PHASE_EYE_NORMAL:
            UpdateTentaclesP1(diff);
            break;
        case PHASE_EYE_DARK_GLARE:
            UpdateTentaclesP1(diff);
            break;
        case PHASE_PRE_TRANSITION:
            // We just wait for eye to death animation before it's despawwn will trigger PHASE_TRANSITION
            break;
        case PHASE_TRANSITION:
            UpdateTransitionPhase(diff);
            
            break;
        case PHASE_CTHUN_INVULNERABLE:
            UpdateInvulnerablePhase(diff);
            CheckIfAllDead();
            
            break;
        case PHASE_CTHUN_WEAKENED:
            UpdateWeakenedPhase(diff);
            CheckIfAllDead();

            break;
        case PHASE_CTHUN_DONE:

            break;
        default:
            sLog.outError("C'Thun in bugged state: %i", currentPhase);
        }
    }
    
    void SummonedCreatureDespawn(Creature* pCreature) override
    {
        // Despawn will happen EYE_DEAD_TO_BODY_EMERGE_DELAY time after eye death
        if (pCreature->GetEntry() == NPC_EYE_OF_C_THUN) {
            currentPhase = PHASE_TRANSITION;

            ResetartUnvulnerablePhase();

            m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            m_creature->SetVisibility(VISIBILITY_OFF);
            m_creature->CastSpell(m_creature, SPELL_TRANSFORM, true);
            m_creature->SetVisibility(VISIBILITY_ON);
            m_creature->CastSpell(m_creature, SPELL_TRANSFORM, true);
        }
        else if (pCreature->GetEntry() == MOB_FLESH_TENTACLE) {
            auto it = std::find(fleshTentacles.begin(), fleshTentacles.end(), pCreature->GetObjectGuid());
            if (it != fleshTentacles.end())
                fleshTentacles.erase(it);
        }
    }

    void JustDied(Unit* pKiller) override
    {
        if (m_pInstance) {
            currentPhase = PHASE_CTHUN_DONE;
            m_pInstance->SetData(TYPE_CTHUN, DONE);
            std::list<Creature*> creaturesToDespawn;
            GetCreatureListWithEntryInGrid(creaturesToDespawn, m_creature, MOB_FLESH_TENTACLE, 2000.0f);
            for (const auto it : creaturesToDespawn) {
                if (TemporarySummon* ts = dynamic_cast<TemporarySummon*>(it)) {
                    ts->UnSummon();
                }
            }

        }
    }

    void ResetartUnvulnerablePhase(bool spawnFleshTentacles = true) {
        giantClawTentacleTimer = P2_FIRST_GIANT_CLAW_SPAWN;
        eyeTentacleTimer = P2_FIRST_EYE_TENTACLE_SPAWN;
        giantEyeTentacleTimer = P2_FIRST_GIANT_EYE_SPAWN;

        StomachEnterTargetGUID = 0;
        stomachEnterPortTimer = 0;
        nextStomachEnterGrabTimer = P2_FIRST_STOMACH_GRAB;

        weaknessTimer = 0;
        if (spawnFleshTentacles)
            SpawnFleshTentacles();
        m_creature->CastSpell(m_creature, SPELL_CARAPACE_OF_CTHUN, true);
    }

    bool UnitShouldPull(Unit* unit)
    {
        float distToCthun = unit->GetDistance3dToCenter(m_creature);
        //float distToCthun = pPlayer->GetDistance(m_creature);
        float zDist = abs(unit->GetPositionZ() - 100.0f);
        // If we're at the same Z axis of cthun, or within the maximum possible pull distance
        if (zDist < 10.0f && distToCthun < 95.0f && unit->IsWithinLOSInMap(m_creature))
        {
            //xxx: it will still be possible to hide behind one of the pillars in the room to avoid pulling, 
            //but I don't think it's really something to take advantage of anyway
            return true;
        }
        return false;
    }

    bool AggroRadius()
    {
        // Large aggro radius
        Map::PlayerList const &PlayerList = m_creature->GetMap()->GetPlayers();
        for (const auto& itr : PlayerList)
        {
            Player* pPlayer = itr.getSource();
            if (pPlayer && pPlayer->IsAlive() && !pPlayer->IsGameMaster())
            {
                if (UnitShouldPull(pPlayer)) {
                    AttackStart(pPlayer);
                    return true;
                }
                else if (Pet* pPet = pPlayer->GetPet())
                {
                    if (UnitShouldPull(pPet)) {
                        AttackStart(pPlayer); //screw the pet, go straight for the head!
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool CheckIfAllDead() {
        if (!SelectRandomAliveNotStomach(m_pInstance)) {
            if (m_pInstance->KillPlayersInStomach()) {
                m_creature->OnLeaveCombat();
                return true;
            }
        }
        return false;
    }

    void UpdateTentaclesP1(uint32 diff) {
        if (SpawnTentacleIfReady(diff, clawTentacleTimer_p1, 0, MOB_CLAW_TENTACLE)) {
            clawTentacleTimer_p1 = P1_CLAW_TENTACLE_RESPAWN_TIMER;
        }

        if (eyeTentacleTimer_p1 < diff) {
            SpawnEyeTentacles();
            eyeTentacleTimer_p1 = P1_EYE_TENTACLE_RESPAWN_TIMER;
        }
        else {
            eyeTentacleTimer_p1 -= diff;
        }
    }

    void UpdateTransitionPhase(uint32 diff)
    {
        UpdateTentaclesP2(diff);
        UpdateStomachGrab(diff);

        if (cthunEmergeTimer < diff) {
            m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            m_creature->SetInCombatWithZone();

            currentPhase = PHASE_CTHUN_INVULNERABLE;
        }
        else {
            cthunEmergeTimer -= diff;
        }
    }

    void UpdateInvulnerablePhase(uint32 diff)
    {
        // Weaken if both Flesh Tentacles are killed
        if (fleshTentacles.empty()) {
            weaknessTimer = WEAKNESS_DURATION;

            DoScriptText(EMOTE_WEAKENED, m_creature);
            // If there is a grabbed player, release him. 
            if (!StomachEnterTargetGUID.IsEmpty()) {
                if (Player* pPlayer = m_creature->GetMap()->GetPlayer(StomachEnterTargetGUID)) {
                    pPlayer->RemoveAurasDueToSpell(SPELL_MOUTH_TENTACLE);
                }
            }

            //Remove the damage reduction aura
            m_creature->CastSpell(m_creature, SPELL_CTHUN_VULNERABLE, true);
            //Make him glow all red and nice
            m_creature->RemoveAurasDueToSpell(SPELL_CARAPACE_OF_CTHUN);
            
            currentPhase = PHASE_CTHUN_WEAKENED;
        }
        else {
            UpdateTentaclesP2(diff);

            UpdateStomachGrab(diff);
        }
    }

    void UpdateWeakenedPhase(uint32 diff)
    {
        // If weakend runs out
        if (weaknessTimer < diff) {
            ResetartUnvulnerablePhase();
            //note: can set visibility off and on again after removing vulnerable spell, 
            // if it does not visually dissapear
            m_creature->RemoveAurasDueToSpell(SPELL_CTHUN_VULNERABLE);
            
            currentPhase = PHASE_CTHUN_INVULNERABLE;
        }
        else {
            weaknessTimer -= diff;
        }
    }
    
    void SpawnFleshTentacles() {

        if (!fleshTentacles.empty()) {
            sLog.outError("SpawnFleshTentacles() called, but there are already %i tentacles up.", fleshTentacles.size());
        }
        //Spawn 2 flesh tentacles in C'thun stomach
        for (const auto& fleshTentaclePosition : fleshTentaclePositions)
        {
            m_creature->SummonCreature(MOB_FLESH_TENTACLE,
                                       fleshTentaclePosition[0],
                                       fleshTentaclePosition[1],
                                       fleshTentaclePosition[2],
                                       fleshTentaclePosition[3],
                                       TENTACLE_DESPAWN_FLAG, 1500);
        }
        
    }
    
    void UpdateStomachGrab(uint32 diff) {
        if (!StomachEnterTargetGUID.IsEmpty()) {
            if (stomachEnterPortTimer < diff) {
                if (Player* pPlayer = m_creature->GetMap()->GetPlayer(StomachEnterTargetGUID)) {

                    DoTeleportPlayer(pPlayer, stomachPortPosition[0], stomachPortPosition[1], stomachPortPosition[2], stomachPortPosition[3]);
                    pPlayer->RemoveAurasDueToSpell(SPELL_MOUTH_TENTACLE);
                    if (m_pInstance) {
                        m_pInstance->AddPlayerToStomach(pPlayer);
                    }
                }

                StomachEnterTargetGUID = 0;
                stomachEnterPortTimer = 0;
            }
            else {
                stomachEnterPortTimer -= diff;
            }
        }

        if (nextStomachEnterGrabTimer < diff) {
            if (Player* target = SelectRandomAliveNotStomach(m_pInstance)) {
                target->InterruptNonMeleeSpells(false);
                target->CastSpell(target, SPELL_MOUTH_TENTACLE, true, nullptr, nullptr, m_creature->GetObjectGuid());
                stomachEnterPortTimer = STOMACH_GRAB_DURATION;
                StomachEnterTargetGUID = target->GetObjectGuid();
            }
            nextStomachEnterGrabTimer = STOMACH_GRAB_COOLDOWN;
        }
        else {
            nextStomachEnterGrabTimer -= diff;
        }

    }

    void UpdateTentaclesP2(uint32 diff)
    {
        SpawnTentacleIfReady(diff, giantClawTentacleTimer, GIANT_CLAW_RESPAWN_TIMER, MOB_GIANT_CLAW_TENTACLE);
        SpawnTentacleIfReady(diff, giantEyeTentacleTimer, GIANT_EYE_RESPAWN_TIMER, MOB_GIANT_EYE_TENTACLE);
        
        if (eyeTentacleTimer < diff) {
            SpawnEyeTentacles();
            eyeTentacleTimer = P2_EYE_TENTACLE_RESPAWN_TIMER;
        }
        else {
            eyeTentacleTimer -= diff;
        }
    }

    void SpawnEyeTentacles()
    {

        //float centerX = relToThisCreature->GetPositionX();
        //float centerY = relToThisCreature->GetPositionY();
        //float radius = 30.0f;
        //float angle = 360.0f / 8.0f;

        for (const auto& eyeTentaclePosition : eyeTentaclePositions)
        {
            //float x = centerX + cos(((float)i * angle) * (3.14f / 180.0f)) * radius;
            //float y = centerY + sin(((float)i * angle) * (3.14f / 180.0f)) * radius;
            //float z = relToThisCreature->GetMap()->GetHeight(x, y, relToThisCreature->GetPositionZ()) + 0.1f;
            //sLog.outBasic("{%.6f, %.6f, %.6f},", x, y, z);

            float x = eyeTentaclePosition[0];
            float y = eyeTentaclePosition[1];
            float z = eyeTentaclePosition[2];
            if (Creature* Spawned = m_creature->SummonCreature(MOB_EYE_TENTACLE, x, y, z, 0,
                TENTACLE_DESPAWN_FLAG, 1500))
                //TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1500))
            {
                Spawned->SetInCombatWithZone();
            }
        }
    }

    bool SpawnTentacleIfReady(uint32 diff, uint32& timer, uint32 resetTo, uint32 id)
    {
        if (timer < diff) {
            if (Unit* target = SelectRandomAliveNotStomach(m_pInstance))
            {
                if (target->GetPositionZ() < -30.0f) {
                    sLog.outError("Cthun trying to spawn %i <-30.0f", id);
                }
                float x;
                float y;
                float z;
                m_creature->GetRandomPoint(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0.5f, x, y, z);
                if (Creature* Spawned = m_creature->SummonCreature(id, x, y, z, 0, 
                    TENTACLE_DESPAWN_FLAG, 1500))
                {
                    Spawned->AI()->AttackStart(target);
                }
                timer = resetTo;
                return true;
            }
        }
        else {
            timer -= diff;
        }
        return false;
    }
};

//GetAIs
CreatureAI* GetAI_eye_of_cthun(Creature* pCreature)
{
    return new eye_of_cthunAI(pCreature);
}

CreatureAI* GetAI_cthun(Creature* pCreature)
{
    return new cthunAI(pCreature);
}

CreatureAI* GetAI_eye_tentacle(Creature* pCreature)
{
    return new eye_tentacleAI(pCreature);
}

CreatureAI* GetAI_claw_tentacle(Creature* pCreature)
{
    return new claw_tentacleAI(pCreature);
}

CreatureAI* GetAI_giant_claw_tentacle(Creature* pCreature)
{
    return new giant_claw_tentacleAI(pCreature);
}

CreatureAI* GetAI_giant_eye_tentacle(Creature* pCreature)
{
    return new giant_eye_tentacleAI(pCreature);
}

CreatureAI* GetAI_flesh_tentacle(Creature* pCreature)
{
    return new flesh_tentacleAI(pCreature);
}

void AddSC_boss_cthun()
{
    Script* newscript;

    //Eye
    newscript = new Script;
    newscript->Name = "boss_eye_of_cthun";
    newscript->GetAI = &GetAI_eye_of_cthun;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "boss_cthun";
    newscript->GetAI = &GetAI_cthun;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_eye_tentacle";
    newscript->GetAI = &GetAI_eye_tentacle;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_claw_tentacle";
    newscript->GetAI = &GetAI_claw_tentacle;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_giant_claw_tentacle";
    newscript->GetAI = &GetAI_giant_claw_tentacle;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_giant_eye_tentacle";
    newscript->GetAI = &GetAI_giant_eye_tentacle;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_giant_flesh_tentacle";
    newscript->GetAI = &GetAI_flesh_tentacle;
    newscript->RegisterSelf();
}
