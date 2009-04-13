/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

/* ScriptData
SDName: Boss_Archimonde
SD%Complete: 85
SDComment: Doomfires not completely offlike due to core limitations for random moving. Tyrande and second phase not fully implemented.
SDCategory: Caverns of Time, Mount Hyjal
EndScriptData */

#include "precompiled.h"
#include "def_hyjal.h"
#include "SpellAuras.h"
#include "hyjal_trash.h"

//text id -1534018 are the text used when previous events complete. Not part of this script.
#define SAY_AGGRO                   -1534019
#define SAY_DOOMFIRE1               -1534020
#define SAY_DOOMFIRE2               -1534021
#define SAY_AIR_BURST1              -1534022
#define SAY_AIR_BURST2              -1534023
#define SAY_SLAY1                   -1534024
#define SAY_SLAY2                   -1534025
#define SAY_SLAY3                   -1534026
#define SAY_ENRAGE                  -1534027
#define SAY_DEATH                   -1534028
#define SAY_SOUL_CHARGE1            -1534029
#define SAY_SOUL_CHARGE2            -1534030

#define SPELL_DENOUEMENT_WISP      32124
#define SPELL_ANCIENT_SPARK        39349
#define SPELL_PROTECTION_OF_ELUNE  38528

#define SPELL_DRAIN_WORLD_TREE      39140
#define SPELL_DRAIN_WORLD_TREE_2    39141

#define SPELL_FINGER_OF_DEATH       31984
#define SPELL_HAND_OF_DEATH         35354
#define SPELL_AIR_BURST             32014
#define SPELL_GRIP_OF_THE_LEGION    31972
#define SPELL_DOOMFIRE_STRIKE       31903                   //summons two creatures
#define SPELL_DOOMFIRE_SPAWN        32074
#define SPELL_DOOMFIRE_VISUAL       42344                   // This is actually a Zul'Aman spell, but the proper Doomfire spell sometimes freezes the server if a player stands in it for too long
#define SPELL_DOOMFIRE_DAMAGE       31944
#define SPELL_SOUL_CHARGE_YELLOW    32045
#define SPELL_SOUL_CHARGE_GREEN     32051
#define SPELL_SOUL_CHARGE_RED       32052
#define SPELL_UNLEASH_SOUL_YELLOW   32054
#define SPELL_UNLEASH_SOUL_GREEN    32057
#define SPELL_UNLEASH_SOUL_RED      32053
#define SPELL_FEAR                  31970

#define CREATURE_ARCHIMONDE             17968
#define CREATURE_DOOMFIRE               18095
#define CREATURE_DOOMFIRE_TARGETING     18104
#define CREATURE_ANCIENT_WISP           17946
#define CREATURE_CHANNEL_TARGET         22418

#define NORDRASSIL_X        5503.713
#define NORDRASSIL_Y       -3523.436
#define NORDRASSIL_Z        1608.781

struct mob_ancient_wispAI : public ScriptedAI
{
    mob_ancient_wispAI(Creature* c) : ScriptedAI(c)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
    }

    ScriptedInstance* pInstance;
    uint64 ArchimondeGUID;
    uint32 CheckTimer;

    void Reset()
    {
        ArchimondeGUID = 0;
        CheckTimer = 1000;

        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
    }

    void Aggro(Unit* who) {}

    void DamageTaken(Unit* done_by, uint32 &damage) { damage = 0; }

    void UpdateAI(const uint32 diff)
    {
        if(!ArchimondeGUID)
        {
            if(pInstance)
                ArchimondeGUID = pInstance->GetData64(DATA_ARCHIMONDE);
        }

        if(CheckTimer < diff)
        {
            if(ArchimondeGUID)
            {
                Unit* Archimonde = Unit::GetUnit((*m_creature), ArchimondeGUID);
                if(Archimonde)
                {
                    if((((Archimonde->GetHealth()*100) / Archimonde->GetMaxHealth()) < 2) || !Archimonde->isAlive())
                        DoCast(m_creature, SPELL_DENOUEMENT_WISP);
                    else
                        DoCast(Archimonde, SPELL_ANCIENT_SPARK);
                }
            }
            CheckTimer = 1000;
        }else CheckTimer -= diff;
    }
};

/* This script controls the Doomfire mob. Unlike the other Doomfire mob, this one does not stalk players.
   Instead, this doomfire will simply stand in one place after spawning and deal damage to any players that
   are within 3 yards. Another creature called Doomfire Targetting spawns this creature as well as stalks. */
struct TRINITY_DLL_DECL mob_doomfireAI : public ScriptedAI
{
    mob_doomfireAI(Creature* c) : ScriptedAI(c) {}

    uint32 CheckTimer;
    uint32 RefreshTimer;

    bool TargetSelected;

    uint64 ArchimondeGUID;
    uint64 TargetGUID;

    void Reset()
    {
        CheckTimer = 5000;
        RefreshTimer = 0;

        TargetSelected = false;

        ArchimondeGUID = 0;
        TargetGUID = 0;
    }

    void DamageTaken(Unit *done_by, uint32 &damage) { damage = 0; }

    void Aggro(Unit* who) { }

    void MoveInLineOfSight(Unit* who)
    {
        // Do not do anything if who does not exist, or we are refreshing our timer, or who is Doomfire, Archimonde or Doomfire targetting
        if(!who || who == m_creature || RefreshTimer || who->GetEntry() == CREATURE_ANCIENT_WISP ||
            who->GetEntry() == CREATURE_ARCHIMONDE || who->GetEntry() == CREATURE_DOOMFIRE ||
            who->GetEntry() == CREATURE_DOOMFIRE_TARGETING || !who->isTargetableForAttack())
            return;

        if(m_creature->IsWithinDistInMap(who, 3))
        {
            TargetSelected = true;
            TargetGUID = who->GetGUID();
            RefreshTimer = 2000;
        }
    }

    void KilledUnit(Unit* victim)
    {
        bool suicide = true;
        if(ArchimondeGUID)
        {
            Creature* Archimonde = (Unit::GetCreature((*m_creature), ArchimondeGUID));
            if(Archimonde && Archimonde->isAlive())
            {
                suicide = false;
                Archimonde->AI()->KilledUnit(victim);
            }
        }

        if(suicide)
            m_creature->DealDamage(m_creature, m_creature->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
    }

    void UpdateAI(const uint32 diff)
    {
        if(RefreshTimer < diff)
            RefreshTimer = 0;
        else RefreshTimer -= diff;

        if(TargetSelected && TargetGUID)
        {
            Unit* target = Unit::GetUnit((*m_creature), TargetGUID);
            if(target && target->isAlive())
            {
                target->CastSpell(target, SPELL_DOOMFIRE_DAMAGE, true);
                TargetGUID = 0;
                TargetSelected = false;
            }
        }

        if(CheckTimer < diff)
        {
            if(ArchimondeGUID)
            {
                Unit* Archimonde = Unit::GetUnit((*m_creature), ArchimondeGUID);
                if(!Archimonde || !Archimonde->isAlive())
                    m_creature->DealDamage(m_creature, m_creature->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                CheckTimer = 5000;
            }
            else m_creature->DealDamage(m_creature, m_creature->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
        }else CheckTimer -= diff;
    }
};

/* This is the script for the Doomfire Targetting Mob. This mob simply follows players and/or travels in random directions and spawns the actual Doomfire which does damage to anyone that moves close.  */
struct TRINITY_DLL_DECL mob_doomfire_targettingAI : public ScriptedAI
{
    mob_doomfire_targettingAI(Creature* c) : ScriptedAI(c) {}

    uint32 ChangeTargetTimer;
    uint32 SummonTimer;                                     // This timer will serve as both a summon timer for the doomfire that does damage as well as to check on Archionde

    uint64 ArchimondeGUID;

    void Reset()
    {
        ChangeTargetTimer = 5000;
        SummonTimer = 1000;

        ArchimondeGUID = 0;
    }

    void Aggro(Unit* who) {}

    void MoveInLineOfSight(Unit* who)
    {
        // Do not do anything if who does not exist, or who is Doomfire, Archimonde or Doomfire targetting
        if(!who || who == m_creature || who->GetEntry() == CREATURE_ARCHIMONDE
            || who->GetEntry() == CREATURE_DOOMFIRE || who->GetEntry() == CREATURE_DOOMFIRE_TARGETING || !who->isTargetableForAttack())
            return;

        m_creature->AddThreat(who, 0.0f);
    }

    void DamageTaken(Unit *done_by, uint32 &damage) { damage = 0; }

    void UpdateAI(const uint32 diff)
    {
        if(!UpdateVictim())
            return;

        if(SummonTimer < diff)
        {
            if(ArchimondeGUID)
            {
                Unit* Archimonde = Unit::GetUnit((*m_creature), ArchimondeGUID);
                if(Archimonde && Archimonde->isAlive())
                {
                    Creature* Doomfire = DoSpawnCreature(CREATURE_DOOMFIRE, 0, 0, 2, 0, TEMPSUMMON_TIMED_DESPAWN, 30000);
                    if(Doomfire)
                    {
                        Doomfire->CastSpell(Doomfire, SPELL_DOOMFIRE_VISUAL, true);
                        ((mob_doomfireAI*)Doomfire->AI())->ArchimondeGUID = ArchimondeGUID;
                        Doomfire->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    }
                    SummonTimer = 500;
                }
                else
                    m_creature->DealDamage(m_creature, m_creature->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
            }
            else
                m_creature->DealDamage(m_creature, m_creature->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
        }else SummonTimer -= diff;

        if(ChangeTargetTimer < diff)
        {
            Unit* target = NULL;
            switch(rand()%2)
            {
                case 0:                                     // stalk player
                    target = SelectUnit(SELECT_TARGET_RANDOM, 1);
                    if(target && target->isAlive())
                    {
                        m_creature->AddThreat(target, DoGetThreat(m_creature->getVictim()));
                        m_creature->GetMotionMaster()->MoveChase(target);
                    }
                    break;

                case 1:                                     // random location
                    float x = 0;
                    float y = 0;
                    float z = 0;
                    m_creature->GetRandomPoint(m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ(), 40, x, y, z);
                    m_creature->GetMotionMaster()->MovePoint(0, x, y, z);
                    break;
            }
            ChangeTargetTimer = 5000;
        }else ChangeTargetTimer -= diff;
    }

};

/* Finally, Archimonde's script. His script isn't extremely complex, most are simply spells on timers.
   The only complicated aspect of the battle is Finger of Death and Doomfire, with Doomfire being the
   hardest bit to code. Finger of Death is simply a distance check - if no one is in melee range, then
   select a random target and cast the spell on them. However, if someone IS in melee range, and this
   is NOT the main tank (creature's victim), then we aggro that player and they become the new victim.
   For Doomfire, we summon a mob (Doomfire Targetting) that summons another mob (Doomfire every second)
   Doomfire Targetting 'stalks' players whilst Doomfire damages player that are within range. */

// This is used to sort by distance in order to see who is the closest target, when checking for Finger of Death
struct TargetDistanceOrder : public std::binary_function<const Unit, const Unit, bool>
{
    const Unit* MainTarget;
    TargetDistanceOrder(const Unit* Target) : MainTarget(Target) {};
    // functor for operator "<"
    bool operator()(const Unit* _Left, const Unit* _Right) const
    {
        return (MainTarget->GetDistance(_Left) < MainTarget->GetDistance(_Right));
    }
};

struct TRINITY_DLL_DECL boss_archimondeAI : public hyjal_trashAI
{
    boss_archimondeAI(Creature *c) : hyjal_trashAI(c)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
    }

    ScriptedInstance* pInstance;

    uint32 DrainNordrassilTimer;
    uint32 FearTimer;
    uint32 AirBurstTimer;
    uint32 GripOfTheLegionTimer;
    uint32 DoomfireTimer;
    uint32 SoulChargeTimer;
    uint32 SoulChargeCount;
    uint32 MeleeRangeCheckTimer;
    uint32 HandOfDeathTimer;
    uint32 SummonWispTimer;
    uint32 WispCount;
    uint32 EnrageTimer;
    uint32 CheckDistanceTimer;

    bool Enraged;
    bool BelowTenPercent;
    bool HasProtected;
    bool IsChanneling;

    void Reset()
    {
        if(pInstance)
            pInstance->SetData(DATA_ARCHIMONDEEVENT, NOT_STARTED);

        damageTaken = 0;
        DrainNordrassilTimer = 0;
        FearTimer = 42000;
        AirBurstTimer = 30000;
        GripOfTheLegionTimer = 5000 + rand()%20000;
        DoomfireTimer = 20000;
        SoulChargeTimer = 2000 + rand()%27000;
        SoulChargeCount = 0;
        MeleeRangeCheckTimer = 15000;
        HandOfDeathTimer = 2000;
        WispCount = 0;                                      // When ~30 wisps are summoned, Archimonde dies
        EnrageTimer = 600000;                               // 10 minutes
        CheckDistanceTimer = 30000;                         // This checks if he's too close to the World Tree (75 yards from a point on the tree), if true then he will enrage
        SummonWispTimer = 0;

        Enraged = false;
        BelowTenPercent = false;
        HasProtected = false;
        IsChanneling = false;
    }

    void Aggro(Unit *who)
    {
        m_creature->InterruptSpell(CURRENT_CHANNELED_SPELL);
        DoScriptText(SAY_AGGRO, m_creature);
        DoZoneInCombat();

        if(pInstance)
            pInstance->SetData(DATA_ARCHIMONDEEVENT, IN_PROGRESS);
    }

    void KilledUnit(Unit *victim)
    {
        switch(rand()%2)
        {
        case 0: DoScriptText(SAY_SLAY1, m_creature); break;
        case 1: DoScriptText(SAY_SLAY2, m_creature); break;
        case 2: DoScriptText(SAY_SLAY3, m_creature); break;
        }

        if(victim && (victim->GetTypeId() == TYPEID_PLAYER))
            GainSoulCharge(((Player*)victim));
    }

    void GainSoulCharge(Player* victim)
    {
        switch(victim->getClass())
        {
            case CLASS_PRIEST:
            case CLASS_PALADIN:
            case CLASS_WARLOCK:
                victim->CastSpell(m_creature, SPELL_SOUL_CHARGE_RED, true);
                break;
            case CLASS_MAGE:
            case CLASS_ROGUE:
            case CLASS_WARRIOR:
                victim->CastSpell(m_creature, SPELL_SOUL_CHARGE_YELLOW, true);
                break;
            case CLASS_DRUID:
            case CLASS_SHAMAN:
            case CLASS_HUNTER:
                victim->CastSpell(m_creature, SPELL_SOUL_CHARGE_GREEN, true);
                break;
        }

        SoulChargeTimer = 2000 + rand()%28000;
        ++SoulChargeCount;
    }

    void JustDied(Unit *victim)
    {
        hyjal_trashAI::JustDied(victim);
        DoScriptText(SAY_DEATH, m_creature);

        if(pInstance)
            pInstance->SetData(DATA_ARCHIMONDEEVENT, DONE);
    }

    bool CanUseFingerOfDeath()
    {
        // First we check if our current victim is in melee range or not.
        Unit* victim = m_creature->getVictim();
        if(victim && m_creature->IsWithinDistInMap(victim, m_creature->GetAttackDistance(victim)))
            return false;

        std::list<HostilReference*>& m_threatlist = m_creature->getThreatManager().getThreatList();
        if(m_threatlist.empty())
            return false;

        std::list<Unit*> targets;
        std::list<HostilReference*>::iterator itr = m_threatlist.begin();
        for( ; itr != m_threatlist.end(); ++itr)
        {
            Unit* pUnit = Unit::GetUnit((*m_creature), (*itr)->getUnitGuid());
            if(pUnit && pUnit->isAlive())
                targets.push_back(pUnit);
        }

        if(targets.empty())
            return false;

        targets.sort(TargetDistanceOrder(m_creature));
        Unit* target = targets.front();
        if(target)
        {
            if(!m_creature->IsWithinDistInMap(target, m_creature->GetAttackDistance(target)))
                return true;                                // Cast Finger of Death
            else                                            // This target is closest, he is our new tank
                m_creature->AddThreat(target, DoGetThreat(m_creature->getVictim()));
        }

        return false;
    }

    void SummonDoomfire(Unit* target)
    {
        Creature* Doomfire = DoSpawnCreature(CREATURE_DOOMFIRE_TARGETING, rand()%30, rand()%30, 0, 0, TEMPSUMMON_TIMED_DESPAWN, 30000);
        if(Doomfire)
        {
            ((mob_doomfire_targettingAI*)Doomfire->AI())->ArchimondeGUID = m_creature->GetGUID();
            Doomfire->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            // Give Doomfire a taste of everyone in the threatlist = more targets to chase.
            std::list<HostilReference*>::iterator itr;
            for(itr = m_creature->getThreatManager().getThreatList().begin(); itr != m_creature->getThreatManager().getThreatList().end(); ++itr)
                Doomfire->AddThreat(Unit::GetUnit(*m_creature, (*itr)->getUnitGuid()), 1.0f);
            Doomfire->setFaction(m_creature->getFaction());
            DoCast(Doomfire, SPELL_DOOMFIRE_SPAWN);
            Doomfire->CastSpell(Doomfire, SPELL_DOOMFIRE_VISUAL, true);
            if(target)
                Doomfire->AI()->AttackStart(target);

            if(rand()%2 == 0)
                DoScriptText(SAY_DOOMFIRE1, m_creature);
            else
                DoScriptText(SAY_DOOMFIRE2, m_creature);
        }
    }

    void UnleashSoulCharge()
    {
        m_creature->InterruptNonMeleeSpells(false);
        bool HasCast = false;
        uint32 chargeSpell = 0;
        uint32 unleashSpell = 0;
        switch(rand()%3)
        {
            case 0:
                chargeSpell = SPELL_SOUL_CHARGE_RED;
                unleashSpell = SPELL_UNLEASH_SOUL_RED;
                break;
            case 1:
                chargeSpell = SPELL_SOUL_CHARGE_YELLOW;
                unleashSpell = SPELL_UNLEASH_SOUL_YELLOW;
                break;
            case 2:
                chargeSpell = SPELL_SOUL_CHARGE_GREEN;
                unleashSpell = SPELL_UNLEASH_SOUL_GREEN;
                break;
        }
        if(m_creature->HasAura(chargeSpell, 0))
        {
            m_creature->RemoveSingleAuraFromStack(chargeSpell, 0);
            DoCast(m_creature->getVictim(), unleashSpell);
            HasCast = true;
            SoulChargeCount--;
        }
        if(HasCast)
            SoulChargeTimer = 2000 + rand()%28000;
    }

    void UpdateAI(const uint32 diff)
    {
        if(!InCombat)
        {
            if(pInstance)
            {
                // Do not let the raid skip straight to Archimonde. Visible and hostile ONLY if Azagalor is finished.
                if((pInstance->GetData(DATA_AZGALOREVENT) < DONE) && ((m_creature->GetVisibility() != VISIBILITY_OFF) || (m_creature->getFaction() != 35)))
                {
                    m_creature->SetVisibility(VISIBILITY_OFF);
                    m_creature->setFaction(35);
                }
                else if((pInstance->GetData(DATA_AZGALOREVENT) >= DONE) && ((m_creature->GetVisibility() != VISIBILITY_ON) || (m_creature->getFaction() == 35)))
                {
                    m_creature->setFaction(1720);
                    m_creature->SetVisibility(VISIBILITY_ON);
                }
            }

            if(DrainNordrassilTimer < diff)
            {
                if(!IsChanneling)
                {
                    Creature* Nordrassil = m_creature->SummonCreature(CREATURE_CHANNEL_TARGET, NORDRASSIL_X, NORDRASSIL_Y, NORDRASSIL_Z, 0, TEMPSUMMON_TIMED_DESPAWN, 1200000);
                    if(Nordrassil)
                    {
                        Nordrassil->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        Nordrassil->SetUInt32Value(UNIT_FIELD_DISPLAYID, 11686);
                        DoCast(Nordrassil, SPELL_DRAIN_WORLD_TREE);
                        IsChanneling = true;
                    }
                }
                Creature* Nordrassil = m_creature->SummonCreature(CREATURE_CHANNEL_TARGET, NORDRASSIL_X, NORDRASSIL_Y, NORDRASSIL_Z, 0, TEMPSUMMON_TIMED_DESPAWN, 5000);
                if(Nordrassil)
                {
                    Nordrassil->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    Nordrassil->SetUInt32Value(UNIT_FIELD_DISPLAYID, 11686);
                    Nordrassil->CastSpell(m_creature, SPELL_DRAIN_WORLD_TREE_2, true);
                    DrainNordrassilTimer = 1000;
                }
            }else DrainNordrassilTimer -= diff;
        }

        if(!UpdateVictim())
            return;

        if(((m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) < 10) && !BelowTenPercent && !Enraged)
            BelowTenPercent = true;

        if(!Enraged)
        {
            if(EnrageTimer < diff)
            {
                if((m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) > 10)
                {
                    m_creature->GetMotionMaster()->Clear(false);
                    m_creature->GetMotionMaster()->MoveIdle();
                    Enraged = true;
                    DoScriptText(SAY_ENRAGE, m_creature);
                }
            }else EnrageTimer -= diff;

            if(CheckDistanceTimer < diff)
            {
                // To simplify the check, we simply summon a creature in the location and then check how far we are from the creature
                Creature* Check = m_creature->SummonCreature(CREATURE_CHANNEL_TARGET, NORDRASSIL_X, NORDRASSIL_Y, NORDRASSIL_Z, 0, TEMPSUMMON_TIMED_DESPAWN, 2000);
                if(Check)
                {
                    Check->SetVisibility(VISIBILITY_OFF);
                    if(m_creature->IsWithinDistInMap(Check, 75))
                    {
                        m_creature->GetMotionMaster()->Clear(false);
                        m_creature->GetMotionMaster()->MoveIdle();
                        Enraged = true;
                        DoScriptText(SAY_ENRAGE, m_creature);
                    }
                }
                CheckDistanceTimer = 5000;
            }else CheckDistanceTimer -= diff;
        }

        if(BelowTenPercent)
        {
            if(!HasProtected)
            {
                m_creature->GetMotionMaster()->Clear(false);
                m_creature->GetMotionMaster()->MoveIdle();
                //all members of raid must get this buff
                DoCast(m_creature->getVictim(), SPELL_PROTECTION_OF_ELUNE);
                HasProtected = true;
                Enraged = true;
            }

            if(SummonWispTimer < diff)
            {
                Creature* Wisp = DoSpawnCreature(CREATURE_ANCIENT_WISP, rand()%40, rand()%40, 0, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 15000);
                if(Wisp)
                {
                    Wisp->AI()->AttackStart(m_creature);
                    ((mob_ancient_wispAI*)Wisp->AI())->ArchimondeGUID = m_creature->GetGUID();
                }
                SummonWispTimer = 1500;
                ++WispCount;
            }else SummonWispTimer -= diff;

            if(WispCount >= 30)
                m_creature->DealDamage(m_creature, m_creature->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
        }

        if(Enraged)
        {
            if(HandOfDeathTimer < diff)
            {
                DoCast(m_creature->getVictim(), SPELL_HAND_OF_DEATH);
                HandOfDeathTimer = 2000;
            }else HandOfDeathTimer -= diff;
            return;                                         // Don't do anything after this point.
        }

        if(SoulChargeCount)
        {
            if(SoulChargeTimer < diff)
                UnleashSoulCharge();
            else SoulChargeTimer -= diff;
        }

        if(GripOfTheLegionTimer < diff)
        {
            DoCast(SelectUnit(SELECT_TARGET_RANDOM, 0), SPELL_GRIP_OF_THE_LEGION);
            GripOfTheLegionTimer = 5000 + rand()%20000;
        }else GripOfTheLegionTimer -= diff;

        if(AirBurstTimer < diff)
        {
            if(rand()%2 == 0)
                DoScriptText(SAY_AIR_BURST1, m_creature);
            else
                DoScriptText(SAY_AIR_BURST2, m_creature);


            DoCast(SelectUnit(SELECT_TARGET_RANDOM, 1), SPELL_AIR_BURST);//not on tank
            AirBurstTimer = 25000 + rand()%15000;
        }else AirBurstTimer -= diff;

        if(FearTimer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_FEAR);
            FearTimer = 42000;
        }else FearTimer -= diff;

        if(DoomfireTimer < diff)
        {
            SummonDoomfire(SelectUnit(SELECT_TARGET_RANDOM, 1));
            DoomfireTimer = 40000;
        }else DoomfireTimer -= diff;

        if(MeleeRangeCheckTimer < diff)
        {
            if(CanUseFingerOfDeath())
            {
                DoCast(SelectUnit(SELECT_TARGET_RANDOM, 0), SPELL_FINGER_OF_DEATH);
                MeleeRangeCheckTimer = 1000;
            }

            MeleeRangeCheckTimer = 5000;
        }else MeleeRangeCheckTimer -= diff;

        DoMeleeAttackIfReady();
    }
    void WaypointReached(uint32 i){}
};

CreatureAI* GetAI_boss_archimonde(Creature *_Creature)
{
    return new boss_archimondeAI (_Creature);
}

CreatureAI* GetAI_mob_doomfire(Creature* _Creature)
{
    return new mob_doomfireAI(_Creature);
}

CreatureAI* GetAI_mob_doomfire_targetting(Creature* _Creature)
{
    return new mob_doomfire_targettingAI(_Creature);
}

CreatureAI* GetAI_mob_ancient_wisp(Creature* _Creature)
{
    return new mob_ancient_wispAI(_Creature);
}

void AddSC_boss_archimonde()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_archimonde";
    newscript->GetAI = &GetAI_boss_archimonde;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_doomfire";
    newscript->GetAI = &GetAI_mob_doomfire;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_doomfire_targetting";
    newscript->GetAI = &GetAI_mob_doomfire_targetting;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_ancient_wisp";
    newscript->GetAI = &GetAI_mob_ancient_wisp;
    newscript->RegisterSelf();
}

