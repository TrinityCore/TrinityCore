/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/* ScriptData
SDName: Boss_Archimonde
SD%Complete: 85
SDComment: Doomfires not completely offlike due to core limitations for random moving. Tyrande and second phase not fully implemented.
SDCategory: Caverns of Time, Mount Hyjal
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "hyjal.h"
#include "SpellAuras.h"
#include "hyjal_trash.h"
#include "Player.h"

enum Texts
{
    SAY_AGGRO       = 1,
    SAY_DOOMFIRE    = 2,
    SAY_AIR_BURST   = 3,
    SAY_SLAY        = 4,
    SAY_ENRAGE      = 5,
    SAY_DEATH       = 6,
    SAY_SOUL_CHARGE = 7,
};

enum Spells
{
    SPELL_DENOUEMENT_WISP       = 32124,
    SPELL_ANCIENT_SPARK         = 39349,
    SPELL_PROTECTION_OF_ELUNE   = 38528,

    SPELL_DRAIN_WORLD_TREE      = 39140,
    SPELL_DRAIN_WORLD_TREE_2    = 39141,

    SPELL_FINGER_OF_DEATH       = 31984,
    SPELL_HAND_OF_DEATH         = 35354,
    SPELL_AIR_BURST             = 32014,
    SPELL_GRIP_OF_THE_LEGION    = 31972,
    SPELL_DOOMFIRE_STRIKE       = 31903,    //summons two creatures
    SPELL_DOOMFIRE_SPAWN        = 32074,
    SPELL_DOOMFIRE              = 31945,
    SPELL_SOUL_CHARGE_YELLOW    = 32045,
    SPELL_SOUL_CHARGE_GREEN     = 32051,
    SPELL_SOUL_CHARGE_RED       = 32052,
    SPELL_UNLEASH_SOUL_YELLOW   = 32054,
    SPELL_UNLEASH_SOUL_GREEN    = 32057,
    SPELL_UNLEASH_SOUL_RED      = 32053,
    SPELL_FEAR                  = 31970,
};

enum Summons
{
    CREATURE_DOOMFIRE               = 18095,
    CREATURE_DOOMFIRE_SPIRIT        = 18104,
    CREATURE_ANCIENT_WISP           = 17946,
    CREATURE_CHANNEL_TARGET         = 22418,
};

Position const NordrassilLoc = {5503.713f, -3523.436f, 1608.781f, 0.0f};

class mob_ancient_wisp : public CreatureScript
{
public:
    mob_ancient_wisp() : CreatureScript("mob_ancient_wisp") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_ancient_wispAI(creature);
    }

    struct mob_ancient_wispAI : public ScriptedAI
    {
        mob_ancient_wispAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
            ArchimondeGUID = 0;
        }

        InstanceScript* instance;
        uint64 ArchimondeGUID;
        uint32 CheckTimer;

        void Reset()
        {
            CheckTimer = 1000;

            if (instance)
                ArchimondeGUID = instance->GetData64(DATA_ARCHIMONDE);

            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        }

        void EnterCombat(Unit* /*who*/) {}

        void DamageTaken(Unit* /*done_by*/, uint32 &damage)
        {
            damage = 0;
        }

        void UpdateAI(uint32 diff)
        {
            if (CheckTimer <= diff)
            {
                if (Unit* Archimonde = Unit::GetUnit(*me, ArchimondeGUID))
                {
                    if (Archimonde->HealthBelowPct(2) || !Archimonde->IsAlive())
                        DoCast(me, SPELL_DENOUEMENT_WISP);
                    else
                        DoCast(Archimonde, SPELL_ANCIENT_SPARK);
                }
                CheckTimer = 1000;
            } else CheckTimer -= diff;
        }
    };
};

/* This script is merely a placeholder for the Doomfire that triggers Doomfire spell. It will
   MoveChase the Doomfire Spirit always, until despawn (AttackStart is called upon it's spawn) */
class mob_doomfire : public CreatureScript
{
public:
    mob_doomfire() : CreatureScript("mob_doomfire") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_doomfireAI(creature);
    }

    struct mob_doomfireAI : public ScriptedAI
    {
        mob_doomfireAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() { }

        void MoveInLineOfSight(Unit* /*who*/) {}
        void EnterCombat(Unit* /*who*/) {}

        void DamageTaken(Unit* /*done_by*/, uint32 &damage)
        {
            damage = 0;
        }
    };
};

/* This is the script for the Doomfire Spirit Mob. This mob simply follow players or
   travels in random directions if target cannot be found. */
class mob_doomfire_targetting : public CreatureScript
{
public:
    mob_doomfire_targetting() : CreatureScript("mob_doomfire_targetting") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_doomfire_targettingAI(creature);
    }

    struct mob_doomfire_targettingAI : public ScriptedAI
    {
        mob_doomfire_targettingAI(Creature* creature) : ScriptedAI(creature) {}

        uint64 TargetGUID;
        uint32 ChangeTargetTimer;

        void Reset()
        {
            TargetGUID = 0;
            ChangeTargetTimer = 5000;
        }

        void MoveInLineOfSight(Unit* who)
        {
            //will update once TargetGUID is 0. In case noone actually moves(not likely) and this is 0
            //when UpdateAI needs it, it will be forced to select randomPoint
            if (!TargetGUID && who->GetTypeId() == TYPEID_PLAYER)
                TargetGUID = who->GetGUID();
        }

        void EnterCombat(Unit* /*who*/) {}

        void DamageTaken(Unit* /*done_by*/, uint32 &damage)
        {
            damage = 0;
        }

        void UpdateAI(uint32 diff)
        {
            if (ChangeTargetTimer <= diff)
            {
                if (Unit* temp = Unit::GetUnit(*me, TargetGUID))
                {
                    me->GetMotionMaster()->MoveFollow(temp, 0.0f, 0.0f);
                    TargetGUID = 0;
                }
                else
                {
                    Position pos;
                    me->GetRandomNearPosition(pos, 40);
                    me->GetMotionMaster()->MovePoint(0, pos.m_positionX, pos.m_positionY, pos.m_positionZ);
                }

                ChangeTargetTimer = 5000;
            } else ChangeTargetTimer -= diff;
        }
    };
};

/* Finally, Archimonde's script. His script isn't extremely complex, most are simply spells on timers.
   The only complicated aspect of the battle is Finger of Death and Doomfire, with Doomfire being the
   hardest bit to code. Finger of Death is simply a distance check - if no one is in melee range, then
   select a random target and cast the spell on them. However, if someone IS in melee range, and this
   is NOT the main tank (creature's victim), then we aggro that player and they become the new victim.
   For Doomfire, we summon a mob (Doomfire Spirit) for the Doomfire mob to follow. It's spirit will
   randomly select it's target to follow and then we create the random movement making it unpredictable. */

class boss_archimonde : public CreatureScript
{
public:
    boss_archimonde() : CreatureScript("boss_archimonde") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_archimondeAI (creature);
    }

    struct boss_archimondeAI : public hyjal_trashAI
    {
        boss_archimondeAI(Creature* creature) : hyjal_trashAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        uint64 DoomfireSpiritGUID;
        uint64 WorldTreeGUID;

        uint32 DrainNordrassilTimer;
        uint32 FearTimer;
        uint32 AirBurstTimer;
        uint32 GripOfTheLegionTimer;
        uint32 DoomfireTimer;
        uint32 SoulChargeTimer;
        uint8 SoulChargeCount;
        uint32 MeleeRangeCheckTimer;
        uint32 HandOfDeathTimer;
        uint32 SummonWispTimer;
        uint8 WispCount;
        uint32 EnrageTimer;
        uint32 CheckDistanceTimer;

        bool Enraged;
        bool BelowTenPercent;
        bool HasProtected;
        bool IsChanneling;

        void Reset()
        {
            if (instance)
                instance->SetData(DATA_ARCHIMONDEEVENT, NOT_STARTED);

            DoomfireSpiritGUID = 0;
            damageTaken = 0;
            WorldTreeGUID = 0;

            DrainNordrassilTimer = 0;
            FearTimer = 42000;
            AirBurstTimer = 30000;
            GripOfTheLegionTimer = urand(5000, 25000);
            DoomfireTimer = 20000;
            SoulChargeTimer = urand(2000, 30000);
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

        void EnterCombat(Unit* /*who*/)
        {
            me->InterruptSpell(CURRENT_CHANNELED_SPELL);
            Talk(SAY_AGGRO);
            DoZoneInCombat();

            if (instance)
                instance->SetData(DATA_ARCHIMONDEEVENT, IN_PROGRESS);
        }

        void KilledUnit(Unit* victim)
        {
            Talk(SAY_SLAY);

            if (victim && victim->GetTypeId() == TYPEID_PLAYER)
                GainSoulCharge(victim->ToPlayer());
        }

        void GainSoulCharge(Player* victim)
        {
            switch (victim->getClass())
            {
                case CLASS_PRIEST:
                case CLASS_PALADIN:
                case CLASS_WARLOCK:
                    victim->CastSpell(me, SPELL_SOUL_CHARGE_RED, true);
                    break;
                case CLASS_MAGE:
                case CLASS_ROGUE:
                case CLASS_WARRIOR:
                    victim->CastSpell(me, SPELL_SOUL_CHARGE_YELLOW, true);
                    break;
                case CLASS_DRUID:
                case CLASS_SHAMAN:
                case CLASS_HUNTER:
                    victim->CastSpell(me, SPELL_SOUL_CHARGE_GREEN, true);
                    break;
            }

            SoulChargeTimer = urand(2000, 30000);
            ++SoulChargeCount;
        }

        void JustDied(Unit* killer)
        {
            hyjal_trashAI::JustDied(killer);
            Talk(SAY_DEATH);

            if (instance)
                instance->SetData(DATA_ARCHIMONDEEVENT, DONE);
        }

        bool CanUseFingerOfDeath()
        {
            // First we check if our current victim is in melee range or not.
            Unit* victim = me->GetVictim();
            if (victim && me->IsWithinDistInMap(victim, me->GetAttackDistance(victim)))
                return false;

            ThreatContainer::StorageType const &threatlist = me->getThreatManager().getThreatList();
            if (threatlist.empty())
                return false;

            std::list<Unit*> targets;
            ThreatContainer::StorageType::const_iterator itr = threatlist.begin();
            for (; itr != threatlist.end(); ++itr)
            {
                Unit* unit = Unit::GetUnit(*me, (*itr)->getUnitGuid());
                if (unit && unit->IsAlive())
                    targets.push_back(unit);
            }

            if (targets.empty())
                return false;

            targets.sort(Trinity::ObjectDistanceOrderPred(me));
            Unit* target = targets.front();
            if (target)
            {
                if (!me->IsWithinDistInMap(target, me->GetAttackDistance(target)))
                    return true;                                // Cast Finger of Death
                else                                            // This target is closest, he is our new tank
                    me->AddThreat(target, me->getThreatManager().getThreat(me->GetVictim()));
            }

            return false;
        }

        void JustSummoned(Creature* summoned)
        {
            if (summoned->GetEntry() == CREATURE_ANCIENT_WISP)
                summoned->AI()->AttackStart(me);
            else
            {
                summoned->setFaction(me->getFaction());
                summoned->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                summoned->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            }

            if (summoned->GetEntry() == CREATURE_DOOMFIRE_SPIRIT)
            {
                DoomfireSpiritGUID = summoned->GetGUID();
            }

            if (summoned->GetEntry() == CREATURE_DOOMFIRE)
            {
                summoned->CastSpell(summoned, SPELL_DOOMFIRE_SPAWN, false);
                summoned->CastSpell(summoned, SPELL_DOOMFIRE, true, 0, 0, me->GetGUID());

                if (Unit* DoomfireSpirit = Unit::GetUnit(*me, DoomfireSpiritGUID))
                {
                    summoned->GetMotionMaster()->MoveFollow(DoomfireSpirit, 0.0f, 0.0f);
                    DoomfireSpiritGUID = 0;
                }
            }
        }

        //this is code doing close to what the summoning spell would do (spell 31903)
        void SummonDoomfire(Unit* target)
        {
            me->SummonCreature(CREATURE_DOOMFIRE_SPIRIT,
                target->GetPositionX()+15.0f, target->GetPositionY()+15.0f, target->GetPositionZ(), 0,
                TEMPSUMMON_TIMED_DESPAWN, 27000);

            me->SummonCreature(CREATURE_DOOMFIRE,
                target->GetPositionX()-15.0f, target->GetPositionY()-15.0f, target->GetPositionZ(), 0,
                TEMPSUMMON_TIMED_DESPAWN, 27000);
        }

        void UnleashSoulCharge()
        {
            me->InterruptNonMeleeSpells(false);

            bool HasCast = false;
            uint32 chargeSpell = 0;
            uint32 unleashSpell = 0;

            switch (urand(0, 2))
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

            if (me->HasAura(chargeSpell))
            {
                me->RemoveAuraFromStack(chargeSpell);
                DoCastVictim(unleashSpell);
                HasCast = true;
                SoulChargeCount--;
            }

            if (HasCast)
                SoulChargeTimer = urand(2000, 30000);
        }

        void UpdateAI(uint32 diff)
        {
            if (!me->IsInCombat())
            {
                if (instance)
                {
                    // Do not let the raid skip straight to Archimonde. Visible and hostile ONLY if Azagalor is finished.
                    if ((instance->GetData(DATA_AZGALOREVENT) < DONE) && (me->IsVisible() || (me->getFaction() != 35)))
                    {
                        me->SetVisible(false);
                        me->setFaction(35);
                    }
                    else if ((instance->GetData(DATA_AZGALOREVENT) >= DONE) && (!me->IsVisible() || (me->getFaction() == 35)))
                    {
                        me->setFaction(1720);
                        me->SetVisible(true);
                    }
                }

                if (DrainNordrassilTimer <= diff)
                {
                    if (!IsChanneling)
                    {
                        Creature* temp = me->SummonCreature(CREATURE_CHANNEL_TARGET, NordrassilLoc, TEMPSUMMON_TIMED_DESPAWN, 1200000);

                        if (temp)
                            WorldTreeGUID = temp->GetGUID();

                        if (Unit* Nordrassil = Unit::GetUnit(*me, WorldTreeGUID))
                        {
                            Nordrassil->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                            Nordrassil->SetDisplayId(11686);
                            DoCast(Nordrassil, SPELL_DRAIN_WORLD_TREE);
                            IsChanneling = true;
                        }
                    }

                    if (Unit* Nordrassil = Unit::GetUnit(*me, WorldTreeGUID))
                    {
                        Nordrassil->CastSpell(me, SPELL_DRAIN_WORLD_TREE_2, true);
                        DrainNordrassilTimer = 1000;
                    }
                } else DrainNordrassilTimer -= diff;
            }

            if (!UpdateVictim())
                return;

            if (me->HealthBelowPct(10) && !BelowTenPercent && !Enraged)
                BelowTenPercent = true;

            if (!Enraged)
            {
                if (EnrageTimer <= diff)
                {
                    if (HealthAbovePct(10))
                    {
                        me->GetMotionMaster()->Clear(false);
                        me->GetMotionMaster()->MoveIdle();
                        Enraged = true;
                        Talk(SAY_ENRAGE);
                    }
                } else EnrageTimer -= diff;

                if (CheckDistanceTimer <= diff)
                {
                    // To simplify the check, we simply summon a Creature in the location and then check how far we are from the creature
                    Creature* Check = me->SummonCreature(CREATURE_CHANNEL_TARGET, NordrassilLoc, TEMPSUMMON_TIMED_DESPAWN, 2000);
                    if (Check)
                    {
                        Check->SetVisible(false);

                        if (me->IsWithinDistInMap(Check, 75))
                        {
                            me->GetMotionMaster()->Clear(false);
                            me->GetMotionMaster()->MoveIdle();
                            Enraged = true;
                            Talk(SAY_ENRAGE);
                        }
                    }
                    CheckDistanceTimer = 5000;
                } else CheckDistanceTimer -= diff;
            }

            if (BelowTenPercent)
            {
                if (!HasProtected)
                {
                    me->GetMotionMaster()->Clear(false);
                    me->GetMotionMaster()->MoveIdle();

                    //all members of raid must get this buff
                    DoCastVictim(SPELL_PROTECTION_OF_ELUNE, true);
                    HasProtected = true;
                    Enraged = true;
                }

                if (SummonWispTimer <= diff)
                {
                    DoSpawnCreature(CREATURE_ANCIENT_WISP, float(rand()%40), float(rand()%40), 0, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 15000);
                    SummonWispTimer = 1500;
                    ++WispCount;
                } else SummonWispTimer -= diff;

                if (WispCount >= 30)
                    me->DealDamage(me, me->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
            }

            if (Enraged)
            {
                if (HandOfDeathTimer <= diff)
                {
                    DoCastVictim(SPELL_HAND_OF_DEATH);
                    HandOfDeathTimer = 2000;
                } else HandOfDeathTimer -= diff;
                return;                                         // Don't do anything after this point.
            }

            if (SoulChargeCount)
            {
                if (SoulChargeTimer <= diff)
                    UnleashSoulCharge();
                else SoulChargeTimer -= diff;
            }

            if (GripOfTheLegionTimer <= diff)
            {
                DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0), SPELL_GRIP_OF_THE_LEGION);
                GripOfTheLegionTimer = urand(5000, 25000);
            } else GripOfTheLegionTimer -= diff;

            if (AirBurstTimer <= diff)
            {
                Talk(SAY_AIR_BURST);
                DoCast(SelectTarget(SELECT_TARGET_RANDOM, 1), SPELL_AIR_BURST);//not on tank
                AirBurstTimer = urand(25000, 40000);
            } else AirBurstTimer -= diff;

            if (FearTimer <= diff)
            {
                DoCastVictim(SPELL_FEAR);
                FearTimer = 42000;
            } else FearTimer -= diff;

            if (DoomfireTimer <= diff)
            {
                Talk(SAY_DOOMFIRE);
                Unit* temp = SelectTarget(SELECT_TARGET_RANDOM, 1);
                if (!temp)
                    temp = me->GetVictim();

                //replace with spell cast 31903 once implicitTarget 73 implemented
                SummonDoomfire(temp);

                //supposedly three doomfire can be up at the same time
                DoomfireTimer = 20000;
            } else DoomfireTimer -= diff;

            if (MeleeRangeCheckTimer <= diff)
            {
                if (CanUseFingerOfDeath())
                {
                    DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0), SPELL_FINGER_OF_DEATH);
                    MeleeRangeCheckTimer = 1000;
                }

                MeleeRangeCheckTimer = 5000;
            } else MeleeRangeCheckTimer -= diff;

            DoMeleeAttackIfReady();
        }
        void WaypointReached(uint32 /*waypointId*/) { }
    };
};

void AddSC_boss_archimonde()
{
    new boss_archimonde();
    new mob_doomfire();
    new mob_doomfire_targetting();
    new mob_ancient_wisp();
}
