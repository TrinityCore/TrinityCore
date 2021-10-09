/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
#include "hyjal.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"

enum Texts
{
    SAY_AGGRO       = 1,
    SAY_DOOMFIRE    = 2,
    SAY_AIR_BURST   = 3,
    SAY_SLAY        = 4,
    SAY_ENRAGE      = 5,
    SAY_DEATH       = 6,
    SAY_SOUL_CHARGE = 7,
    // YELL_ARCHIMONDE_INTRO = 8
};

enum Spells
{
    SPELL_DENOUEMENT_WISP            = 32124,
    SPELL_ANCIENT_SPARK              = 39349,
    SPELL_PROTECTION_OF_ELUNE        = 38528,

    SPELL_DRAIN_WORLD_TREE           = 39140,
    SPELL_DRAIN_WORLD_TREE_TRIGGERED = 39141,

    SPELL_FINGER_OF_DEATH            = 31984,
    SPELL_HAND_OF_DEATH              = 35354,
    SPELL_AIR_BURST                  = 32014,
    SPELL_GRIP_OF_THE_LEGION         = 31972,
    SPELL_DOOMFIRE_STRIKE            = 31903, // summons two creatures
    SPELL_DOOMFIRE_SPAWN             = 32074,
    SPELL_DOOMFIRE                   = 31945,
    SPELL_SOUL_CHARGE_YELLOW         = 32045,
    SPELL_SOUL_CHARGE_GREEN          = 32051,
    SPELL_SOUL_CHARGE_RED            = 32052,
    SPELL_UNLEASH_SOUL_YELLOW        = 32054,
    SPELL_UNLEASH_SOUL_GREEN         = 32057,
    SPELL_UNLEASH_SOUL_RED           = 32053,
    SPELL_FEAR                       = 31970
};

enum Events
{
    EVENT_HAND_OF_DEATH = 1,        // Raid wiper
    EVENT_UNLEASH_SOUL_CHARGE,
    EVENT_FINGER_OF_DEATH,
    EVENT_GRIP_OF_THE_LEGION,
    EVENT_FEAR,
    EVENT_AIR_BURST,
    EVENT_DOOMFIRE,
    EVENT_DISTANCE_CHECK,           // This checks if he's too close to the World Tree (75 yards from a point on the tree), if true then he will enrage
    EVENT_SUMMON_WHISP
};

enum Summons
{
    NPC_DOOMFIRE               = 18095,
    NPC_DOOMFIRE_SPIRIT        = 18104,
    NPC_ANCIENT_WISP           = 17946
};

enum Actions
{
    ACTION_ENRAGE,
    ACTION_CHANNEL_WORLD_TREE
};

class npc_ancient_wisp : public CreatureScript
{
public:
    npc_ancient_wisp() : CreatureScript("npc_ancient_wisp") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetHyjalAI<npc_ancient_wispAI>(creature);
    }

    struct npc_ancient_wispAI : public ScriptedAI
    {
        npc_ancient_wispAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            instance = creature->GetInstanceScript();
        }

        void Initialize()
        {
            CheckTimer = 1000;
            ArchimondeGUID.Clear();
        }

        InstanceScript* instance;
        ObjectGuid ArchimondeGUID;
        uint32 CheckTimer;

        void Reset() override
        {
            Initialize();

            ArchimondeGUID = instance->GetGuidData(DATA_ARCHIMONDE);

            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        }

        void JustEngagedWith(Unit* /*who*/) override { }

        void DamageTaken(Unit* /*done_by*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
        {
            damage = 0;
        }

        void UpdateAI(uint32 diff) override
        {
            if (CheckTimer <= diff)
            {
                if (Creature* Archimonde = ObjectAccessor::GetCreature(*me, ArchimondeGUID))
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
class npc_doomfire : public CreatureScript
{
public:
    npc_doomfire() : CreatureScript("npc_doomfire") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetHyjalAI<npc_doomfireAI>(creature);
    }

    struct npc_doomfireAI : public ScriptedAI
    {
        npc_doomfireAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override { }

        void MoveInLineOfSight(Unit* /*who*/) override { }

        void JustEngagedWith(Unit* /*who*/) override { }

        void DamageTaken(Unit* /*done_by*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
        {
            damage = 0;
        }
    };
};

/* This is the script for the Doomfire Spirit Mob. This mob simply follow players or
   travels in random directions if target cannot be found. */
class npc_doomfire_targetting : public CreatureScript
{
public:
    npc_doomfire_targetting() : CreatureScript("npc_doomfire_targetting") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetHyjalAI<npc_doomfire_targettingAI>(creature);
    }

    struct npc_doomfire_targettingAI : public ScriptedAI
    {
        npc_doomfire_targettingAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            TargetGUID.Clear();
            ChangeTargetTimer = 5000;
        }

        ObjectGuid TargetGUID;
        uint32 ChangeTargetTimer;

        void Reset() override
        {
            Initialize();
        }

        void MoveInLineOfSight(Unit* who) override
        {
            //will update once TargetGUID is 0. In case noone actually moves(not likely) and this is 0
            //when UpdateAI needs it, it will be forced to select randomPoint
            if (!TargetGUID && who->GetTypeId() == TYPEID_PLAYER)
                TargetGUID = who->GetGUID();
        }

        void JustEngagedWith(Unit* /*who*/) override { }

        void DamageTaken(Unit* /*done_by*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
        {
            damage = 0;
        }

        void UpdateAI(uint32 diff) override
        {
            if (ChangeTargetTimer <= diff)
            {
                if (Unit* temp = ObjectAccessor::GetUnit(*me, TargetGUID))
                {
                    me->GetMotionMaster()->MoveFollow(temp, 0.0f, 0.0f);
                    TargetGUID.Clear();
                }
                else
                {
                    Position pos = me->GetRandomNearPosition(40);
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

    struct boss_archimondeAI : public BossAI
    {
        boss_archimondeAI(Creature* creature) : BossAI(creature, DATA_ARCHIMONDE)
        {
            Initialize();
        }

        void Initialize()
        {
            DoomfireSpiritGUID.Clear();

            SoulChargeCount = 0;
            WispCount = 0;                                      // When ~30 wisps are summoned, Archimonde dies
            _unleashSpell = 0;
            _chargeSpell = 0;

            Enraged = false;
            HasProtected = false;
        }

        void InitializeAI() override
        {
            BossAI::InitializeAI();
            DoAction(ACTION_CHANNEL_WORLD_TREE);
        }

        void Reset() override
        {
            Initialize();
            _Reset();
            me->RemoveAllAuras();                              // Reset Soul Charge auras.
        }

        void JustEngagedWith(Unit* who) override
        {
            Talk(SAY_AGGRO);
            BossAI::JustEngagedWith(who);
            events.ScheduleEvent(EVENT_FEAR, 42s);
            events.ScheduleEvent(EVENT_AIR_BURST, 30s);
            events.ScheduleEvent(EVENT_GRIP_OF_THE_LEGION, 5s, 25s);
            events.ScheduleEvent(EVENT_DOOMFIRE, 20s);
            events.ScheduleEvent(EVENT_UNLEASH_SOUL_CHARGE, 2s, 30s);
            events.ScheduleEvent(EVENT_FINGER_OF_DEATH, 15s);
            events.ScheduleEvent(EVENT_HAND_OF_DEATH, 10min);
            events.ScheduleEvent(EVENT_DISTANCE_CHECK, 30s);
        }

        void ExecuteEvent(uint32 eventId) override
        {
            switch (eventId)
            {
                case EVENT_HAND_OF_DEATH:
                    DoCastAOE(SPELL_HAND_OF_DEATH);
                    events.ScheduleEvent(EVENT_HAND_OF_DEATH, 2s);
                    break;
                case EVENT_UNLEASH_SOUL_CHARGE:
                    _chargeSpell = 0;
                    _unleashSpell = 0;
                    me->InterruptNonMeleeSpells(false);
                    switch (urand(0, 2))
                    {
                        case 0:
                            _chargeSpell = SPELL_SOUL_CHARGE_RED;
                            _unleashSpell = SPELL_UNLEASH_SOUL_RED;
                            break;
                        case 1:
                            _chargeSpell = SPELL_SOUL_CHARGE_YELLOW;
                            _unleashSpell = SPELL_UNLEASH_SOUL_YELLOW;
                            break;
                        case 2:
                            _chargeSpell = SPELL_SOUL_CHARGE_GREEN;
                            _unleashSpell = SPELL_UNLEASH_SOUL_GREEN;
                            break;
                    }

                    if (me->HasAura(_chargeSpell))
                    {
                        me->RemoveAuraFromStack(_chargeSpell);
                        DoCastVictim(_unleashSpell);
                        SoulChargeCount--;
                        events.ScheduleEvent(EVENT_UNLEASH_SOUL_CHARGE, 2s, 30s);
                    }
                    break;
                case EVENT_FINGER_OF_DEATH:
                    if (!SelectTarget(SelectTargetMethod::Random, 0, 5.0f)) // Checks if there are no targets in melee range
                    {
                        DoCast(SelectTarget(SelectTargetMethod::Random, 0), SPELL_FINGER_OF_DEATH);
                        events.ScheduleEvent(EVENT_FINGER_OF_DEATH, 1s);
                    }
                    else
                        events.ScheduleEvent(EVENT_FINGER_OF_DEATH, 5s);
                    break;
                case EVENT_GRIP_OF_THE_LEGION:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, SPELL_GRIP_OF_THE_LEGION);
                    events.ScheduleEvent(EVENT_GRIP_OF_THE_LEGION, 5s, 25s);
                    break;
                case EVENT_AIR_BURST:
                    Talk(SAY_AIR_BURST);
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 1))
                        DoCast(target, SPELL_AIR_BURST); //not on tank
                    events.ScheduleEvent(EVENT_AIR_BURST, 25s, 40s);
                    break;
                case EVENT_FEAR:
                    DoCastAOE(SPELL_FEAR);
                    events.ScheduleEvent(EVENT_FEAR, 42s);
                    break;
                case EVENT_DOOMFIRE:
                    Talk(SAY_DOOMFIRE);
                    if (Unit* temp = SelectTarget(SelectTargetMethod::Random, 1))
                        SummonDoomfire(temp);
                    else
                        SummonDoomfire(me->GetVictim());
                    events.ScheduleEvent(EVENT_DOOMFIRE, 20s);
                    break;
                case EVENT_DISTANCE_CHECK:
                    if (Creature* channelTrigger = instance->GetCreature(DATA_CHANNEL_TARGET))
                        if (me->IsWithinDistInMap(channelTrigger, 75.0f))
                            DoAction(ACTION_ENRAGE);
                    events.ScheduleEvent(EVENT_DISTANCE_CHECK, 5s);
                    break;
                case EVENT_SUMMON_WHISP:
                    DoSpawnCreature(NPC_ANCIENT_WISP, float(rand32() % 40), float(rand32() % 40), 0, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 15s);
                    ++WispCount;
                    if (WispCount >= 30)
                        me->KillSelf();
                    events.ScheduleEvent(EVENT_SUMMON_WHISP, 1500ms);
                    break;
                default:
                    break;
            }
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
        {
            if (me->HealthBelowPctDamaged(10, damage))
            {
                if (!Enraged)
                    DoAction(ACTION_ENRAGE);

                if (!HasProtected)
                {
                    me->GetMotionMaster()->Clear();
                    me->GetMotionMaster()->MoveIdle();

                    // All members of raid must get this buff
                    DoCastAOE(SPELL_PROTECTION_OF_ELUNE, true);
                    HasProtected = true;
                    events.ScheduleEvent(EVENT_SUMMON_WHISP, 1500ms);
                }
            }
        }

        void KilledUnit(Unit* victim) override
        {
            Talk(SAY_SLAY);

            if (victim->GetTypeId() == TYPEID_PLAYER)
            {
                switch (victim->GetClass())
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

                events.ScheduleEvent(EVENT_UNLEASH_SOUL_CHARGE, 2s, 30s);
                ++SoulChargeCount;
            }
        }

        void JustReachedHome() override
        {
            DoAction(ACTION_CHANNEL_WORLD_TREE);
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);
            _JustDied();
            // @todo: remove this when instance script gets updated, kept for compatibility only
            instance->SetData(DATA_ARCHIMONDE, DONE);
        }

        void JustSummoned(Creature* summoned) override
        {
            switch (summoned->GetEntry())
            {
                case NPC_ANCIENT_WISP:
                    summoned->AI()->AttackStart(me);
                    break;
                case NPC_DOOMFIRE_SPIRIT:
                    DoomfireSpiritGUID = summoned->GetGUID();
                    break;
                case NPC_DOOMFIRE:
                {
                    summoned->CastSpell(summoned, SPELL_DOOMFIRE_SPAWN, false);

                    summoned->CastSpell(summoned, SPELL_DOOMFIRE, me->GetGUID());

                    if (Unit* DoomfireSpirit = ObjectAccessor::GetUnit(*me, DoomfireSpiritGUID))
                    {
                        summoned->GetMotionMaster()->MoveFollow(DoomfireSpirit, 0.0f, 0.0f);
                        DoomfireSpiritGUID.Clear();
                    }
                    break;
                }
                default:
                    break;
            }
        }

        void DoAction(int32 actionId) override
        {
            switch (actionId)
            {
                case ACTION_ENRAGE:
                    me->GetMotionMaster()->Clear();
                    me->GetMotionMaster()->MoveIdle();
                    Enraged = true;
                    Talk(SAY_ENRAGE);
                    break;
                case ACTION_CHANNEL_WORLD_TREE:
                    DoCastAOE(SPELL_DRAIN_WORLD_TREE, true);
                    break;
                default:
                    break;
            }
        }

        //this is code doing close to what the summoning spell would do (spell 31903)
        void SummonDoomfire(Unit* target)
        {
            if (!target)
                return;

            me->SummonCreature(NPC_DOOMFIRE_SPIRIT,
                target->GetPositionX()+15.0f, target->GetPositionY()+15.0f, target->GetPositionZ(), 0,
                TEMPSUMMON_TIMED_DESPAWN, 27s);

            me->SummonCreature(NPC_DOOMFIRE,
                target->GetPositionX()-15.0f, target->GetPositionY()-15.0f, target->GetPositionZ(), 0,
                TEMPSUMMON_TIMED_DESPAWN, 27s);
        }

    private:
        ObjectGuid DoomfireSpiritGUID;
        uint8 SoulChargeCount;
        uint8 WispCount;
        uint32 _chargeSpell;
        uint32 _unleashSpell;
        bool Enraged;
        bool HasProtected;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetHyjalAI<boss_archimondeAI>(creature);
    }
};

// 39142 - Drain World Tree Dummy
class spell_archimonde_drain_world_tree_dummy : public SpellScriptLoader
{
    public:
        spell_archimonde_drain_world_tree_dummy() : SpellScriptLoader("spell_archimonde_drain_world_tree_dummy") { }

        class spell_archimonde_drain_world_tree_dummy_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_archimonde_drain_world_tree_dummy_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_DRAIN_WORLD_TREE_TRIGGERED });
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (Unit* target = GetHitUnit())
                    target->CastSpell(GetCaster(), SPELL_DRAIN_WORLD_TREE_TRIGGERED, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_archimonde_drain_world_tree_dummy_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_archimonde_drain_world_tree_dummy_SpellScript();
        }
};

void AddSC_boss_archimonde()
{
    new boss_archimonde();
    new npc_doomfire();
    new npc_doomfire_targetting();
    new npc_ancient_wisp();
    new spell_archimonde_drain_world_tree_dummy();
}
