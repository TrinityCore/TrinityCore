/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "Vehicle.h"
#include "SpellScript.h"
#include "Player.h"

/*######
##Quest 5441: Lazy Peons
##npc_lazy_peon
######*/

enum LazyPeonYells
{
    SAY_SPELL_HIT                                 = 0
};

enum LazyPeon
{
    QUEST_LAZY_PEONS                              = 5441,
    GO_LUMBERPILE                                 = 175784,
    SPELL_BUFF_SLEEP                              = 17743,
    SPELL_AWAKEN_PEON                             = 19938
};

class npc_lazy_peon : public CreatureScript
{
public:
    npc_lazy_peon() : CreatureScript("npc_lazy_peon") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_lazy_peonAI(creature);
    }

    struct npc_lazy_peonAI : public ScriptedAI
    {
        npc_lazy_peonAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            RebuffTimer = 0;
            work = false;
        }

        uint32 RebuffTimer;
        bool work;

        void Reset() override
        {
            Initialize();
        }

        void MovementInform(uint32 /*type*/, uint32 id) override
        {
            if (id == 1)
                work = true;
        }

        void SpellHit(Unit* caster, const SpellInfo* spell) override
        {
            if (spell->Id != SPELL_AWAKEN_PEON)
                return;

            Player* player = caster->ToPlayer();
            if (player && player->GetQuestStatus(QUEST_LAZY_PEONS) == QUEST_STATUS_INCOMPLETE)
            {
                player->KilledMonsterCredit(me->GetEntry(), me->GetGUID());
                Talk(SAY_SPELL_HIT, caster);
                me->RemoveAllAuras();
                if (GameObject* Lumberpile = me->FindNearestGameObject(GO_LUMBERPILE, 20))
                    me->GetMotionMaster()->MovePoint(1, Lumberpile->GetPositionX()-1, Lumberpile->GetPositionY(), Lumberpile->GetPositionZ());
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (work == true)
                me->HandleEmoteCommand(EMOTE_ONESHOT_WORK_CHOPWOOD);
            if (RebuffTimer <= diff)
            {
                DoCast(me, SPELL_BUFF_SLEEP);
                RebuffTimer = 300000;                 //Rebuff agian in 5 minutes
            }
            else
                RebuffTimer -= diff;
            if (!UpdateVictim())
                return;
            DoMeleeAttackIfReady();
        }
    };
};

enum Texts
{
    // Tiger Matriarch Credit
    SAY_MATRIARCH_AGGRO     = 0,

    // Troll Volunteer
    SAY_VOLUNTEER_START     = 0,
    SAY_VOLUNTEER_END       = 1,
};

enum Spells
{
    // Tiger Matriarch Credit
    SPELL_SUMMON_MATRIARCH              = 75187,
    SPELL_NO_SUMMON_AURA                = 75213,
    SPELL_DETECT_INVIS                  = 75180,
    SPELL_SUMMON_ZENTABRA_TRIGGER       = 75212,

    // Tiger Matriarch
    SPELL_POUNCE                        = 61184,
    SPELL_FURIOUS_BITE                  = 75164,
    SPELL_SUMMON_ZENTABRA               = 75181,
    SPELL_SPIRIT_OF_THE_TIGER_RIDER     = 75166,
    SPELL_EJECT_PASSENGERS              = 50630,

    // Troll Volunteer
    SPELL_VOLUNTEER_AURA                = 75076,
    SPELL_PETACT_AURA                   = 74071,
    SPELL_QUEST_CREDIT                  = 75106,
    SPELL_MOUNTING_CHECK                = 75420,
    SPELL_TURNIN                        = 73953,
    SPELL_AOE_TURNIN                    = 75107,

    // Vol'jin War Drums
    SPELL_MOTIVATE_1                    = 75088,
    SPELL_MOTIVATE_2                    = 75086,
};

enum Creatures
{
    // Tiger Matriarch Credit
    NPC_TIGER_VEHICLE                   = 40305,

    // Troll Volunteer
    NPC_URUZIN                          = 40253,
    NPC_VOLUNTEER_1                     = 40264,
    NPC_VOLUNTEER_2                     = 40260,

    // Vol'jin War Drums
    NPC_CITIZEN_1                       = 40256,
    NPC_CITIZEN_2                       = 40257,
};

enum Events
{
    // Tiger Matriarch Credit
    EVENT_CHECK_SUMMON_AURA             = 1,

    // Tiger Matriarch
    EVENT_POUNCE                        = 2,
    EVENT_NOSUMMON                      = 3,
};

enum Points
{
    POINT_URUZIN                        = 4026400,
};

class npc_tiger_matriarch_credit : public CreatureScript
{
    public:
        npc_tiger_matriarch_credit() : CreatureScript("npc_tiger_matriarch_credit") { }

        struct npc_tiger_matriarch_creditAI : public ScriptedAI
        {
           npc_tiger_matriarch_creditAI(Creature* creature) : ScriptedAI(creature)
           {
               SetCombatMovement(false);
               events.ScheduleEvent(EVENT_CHECK_SUMMON_AURA, 2000);
           }

            void UpdateAI(uint32 diff) override
            {
                events.Update(diff);

                if (events.ExecuteEvent() == EVENT_CHECK_SUMMON_AURA)
                {
                    std::list<Creature*> tigers;
                    GetCreatureListWithEntryInGrid(tigers, me, NPC_TIGER_VEHICLE, 15.0f);
                    if (!tigers.empty())
                    {
                        for (std::list<Creature*>::iterator itr = tigers.begin(); itr != tigers.end(); ++itr)
                        {
                            if (!(*itr)->IsSummon())
                                continue;

                            if (Unit* summoner = (*itr)->ToTempSummon()->GetSummoner())
                                if (!summoner->HasAura(SPELL_NO_SUMMON_AURA) && !summoner->HasAura(SPELL_SUMMON_ZENTABRA_TRIGGER)
                                    && !summoner->IsInCombat())
                                {
                                    me->AddAura(SPELL_NO_SUMMON_AURA, summoner);
                                    me->AddAura(SPELL_DETECT_INVIS, summoner);
                                    summoner->CastSpell(summoner, SPELL_SUMMON_MATRIARCH, true);
                                    Talk(SAY_MATRIARCH_AGGRO, summoner);
                                }
                        }
                    }

                    events.ScheduleEvent(EVENT_CHECK_SUMMON_AURA, 5000);
                }
            }

        private:
            EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_tiger_matriarch_creditAI(creature);
        }
};

class npc_tiger_matriarch : public CreatureScript
{
    public:
        npc_tiger_matriarch() : CreatureScript("npc_tiger_matriarch") { }

        struct npc_tiger_matriarchAI : public ScriptedAI
        {
            npc_tiger_matriarchAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            void EnterCombat(Unit* /*target*/) override
            {
                _events.Reset();
                _events.ScheduleEvent(EVENT_POUNCE, 100);
                _events.ScheduleEvent(EVENT_NOSUMMON, 50000);
            }

            void IsSummonedBy(Unit* summoner) override
            {
                if (summoner->GetTypeId() != TYPEID_PLAYER || !summoner->GetVehicle())
                    return;

                _tigerGuid = summoner->GetVehicle()->GetBase()->GetGUID();
                if (Unit* tiger = ObjectAccessor::GetUnit(*me, _tigerGuid))
                {
                    me->AddThreat(tiger, 500000.0f);
                    DoCast(me, SPELL_FURIOUS_BITE);
                }
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim->GetTypeId() != TYPEID_UNIT || !victim->IsSummon())
                    return;

                if (Unit* vehSummoner = victim->ToTempSummon()->GetSummoner())
                {
                    vehSummoner->RemoveAurasDueToSpell(SPELL_NO_SUMMON_AURA);
                    vehSummoner->RemoveAurasDueToSpell(SPELL_DETECT_INVIS);
                    vehSummoner->RemoveAurasDueToSpell(SPELL_SPIRIT_OF_THE_TIGER_RIDER);
                    vehSummoner->RemoveAurasDueToSpell(SPELL_SUMMON_ZENTABRA_TRIGGER);
                }
                me->DespawnOrUnsummon();
            }

            void DamageTaken(Unit* attacker, uint32& damage) override
            {
                if (!attacker->IsSummon())
                    return;

                if (HealthBelowPct(20))
                {
                    damage = 0;
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    if (Unit* vehSummoner = attacker->ToTempSummon()->GetSummoner())
                    {
                        vehSummoner->AddAura(SPELL_SUMMON_ZENTABRA_TRIGGER, vehSummoner);
                        vehSummoner->CastSpell(vehSummoner, SPELL_SUMMON_ZENTABRA, true);
                        attacker->CastSpell(attacker, SPELL_EJECT_PASSENGERS, true);
                        vehSummoner->RemoveAurasDueToSpell(SPELL_NO_SUMMON_AURA);
                        vehSummoner->RemoveAurasDueToSpell(SPELL_DETECT_INVIS);
                        vehSummoner->RemoveAurasDueToSpell(SPELL_SPIRIT_OF_THE_TIGER_RIDER);
                        vehSummoner->RemoveAurasDueToSpell(SPELL_SUMMON_ZENTABRA_TRIGGER);
                    }

                    me->DespawnOrUnsummon();
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (!_tigerGuid)
                    return;

                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_POUNCE:
                            DoCastVictim(SPELL_POUNCE);
                            _events.ScheduleEvent(EVENT_POUNCE, 30000);
                            break;
                        case EVENT_NOSUMMON: // Reapply SPELL_NO_SUMMON_AURA
                            if (Unit* tiger = ObjectAccessor::GetUnit(*me, _tigerGuid))
                            {
                                if (tiger->IsSummon())
                                    if (Unit* vehSummoner = tiger->ToTempSummon()->GetSummoner())
                                        me->AddAura(SPELL_NO_SUMMON_AURA, vehSummoner);
                            }
                            _events.ScheduleEvent(EVENT_NOSUMMON, 50000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap _events;
            ObjectGuid _tigerGuid;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_tiger_matriarchAI(creature);
        }
};

// These models was found in sniff.
/// @todo generalize these models with race from dbc
uint32 const trollmodel[] =
{11665, 11734, 11750, 12037, 12038, 12042, 12049, 12849, 13529, 14759, 15570, 15701,
15702, 1882, 1897, 1976, 2025, 27286, 2734, 2735, 4084, 4085, 4087, 4089, 4231, 4357,
4358, 4360, 4361, 4362, 4363, 4370, 4532, 4537, 4540, 4610, 6839, 7037, 9767, 9768};

class npc_troll_volunteer : public CreatureScript
{
    public:
        npc_troll_volunteer() : CreatureScript("npc_troll_volunteer") { }

        struct npc_troll_volunteerAI : public ScriptedAI
        {
            npc_troll_volunteerAI(Creature* creature) : ScriptedAI(creature)
            {
                Initialize();
                _mountModel = 0;
            }

            void Initialize()
            {
                _complete = false;
            }

            void InitializeAI() override
            {
                if (me->isDead() || !me->GetOwner())
                    return;

                Reset();

                switch (urand(0, 3))
                {
                    case 0:
                        _mountModel = 6471;
                        break;
                    case 1:
                        _mountModel = 6473;
                        break;
                    case 2:
                        _mountModel = 6469;
                        break;
                    default:
                        _mountModel = 6472;
                        break;
                }
                me->SetDisplayId(trollmodel[urand(0, 39)]);
                if (Player* player = me->GetOwner()->ToPlayer())
                    me->GetMotionMaster()->MoveFollow(player, 5.0f, float(rand_norm() + 1.0f) * float(M_PI) / 3.0f * 4.0f);
            }

            void Reset() override
            {
                Initialize();
                me->AddAura(SPELL_VOLUNTEER_AURA, me);
                me->AddAura(SPELL_MOUNTING_CHECK, me);
                DoCast(me, SPELL_PETACT_AURA);
                me->SetReactState(REACT_PASSIVE);
                Talk(SAY_VOLUNTEER_START);
            }

            // This is needed for mount check aura to know what mountmodel the npc got stored
            uint32 GetMountId()
            {
                return _mountModel;
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type != POINT_MOTION_TYPE)
                    return;
                if (id == POINT_URUZIN)
                    me->DespawnOrUnsummon();
            }

            void SpellHit(Unit* caster, SpellInfo const* spell) override
            {
                if (spell->Id == SPELL_AOE_TURNIN && caster->GetEntry() == NPC_URUZIN && !_complete)
                {
                    _complete = true;    // Preventing from giving credit twice
                    DoCast(me, SPELL_TURNIN);
                    DoCast(me, SPELL_QUEST_CREDIT);
                    me->RemoveAurasDueToSpell(SPELL_MOUNTING_CHECK);
                    me->Dismount();
                    Talk(SAY_VOLUNTEER_END);
                    me->GetMotionMaster()->MovePoint(POINT_URUZIN, caster->GetPositionX(), caster->GetPositionY(), caster->GetPositionZ());
                }
            }

        private:
            uint32 _mountModel;
            bool _complete;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_troll_volunteerAI(creature);
        }
};

typedef npc_troll_volunteer::npc_troll_volunteerAI VolunteerAI;

class spell_mount_check : public SpellScriptLoader
{
    public:
        spell_mount_check() : SpellScriptLoader("spell_mount_check") { }

        class spell_mount_check_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mount_check_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_MOUNTING_CHECK))
                    return false;
                return true;
            }

            void HandleEffectPeriodic(AuraEffect const* /*aurEff*/)
            {
                Unit* target = GetTarget();
                Unit* owner = target->GetOwner();

                if (!owner)
                    return;

                if (owner->IsMounted() && !target->IsMounted())
                {
                    if (VolunteerAI* volunteerAI = CAST_AI(VolunteerAI, target->GetAI()))
                        target->Mount(volunteerAI->GetMountId());
                }
                else if (!owner->IsMounted() && target->IsMounted())
                    target->Dismount();

                target->SetSpeed(MOVE_RUN, owner->GetSpeedRate(MOVE_RUN));
                target->SetSpeed(MOVE_WALK, owner->GetSpeedRate(MOVE_WALK));
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_mount_check_AuraScript::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_mount_check_AuraScript();
        }
};

class spell_voljin_war_drums : public SpellScriptLoader
{
    public:
        spell_voljin_war_drums() : SpellScriptLoader("spell_voljin_war_drums") { }

        class spell_voljin_war_drums_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_voljin_war_drums_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_MOTIVATE_1))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_MOTIVATE_2))
                    return false;
               return true;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                if (Unit* target = GetHitUnit())
                {
                    uint32 motivate = 0;
                    if (target->GetEntry() == NPC_CITIZEN_1)
                        motivate = SPELL_MOTIVATE_1;
                    else if (target->GetEntry() == NPC_CITIZEN_2)
                        motivate = SPELL_MOTIVATE_2;
                    if (motivate)
                        caster->CastSpell(target, motivate, false);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_voljin_war_drums_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_voljin_war_drums_SpellScript();
        }
};

enum VoodooSpells
{
    SPELL_BREW      = 16712, // Special Brew
    SPELL_GHOSTLY   = 16713, // Ghostly
    SPELL_HEX1      = 16707, // Hex
    SPELL_HEX2      = 16708, // Hex
    SPELL_HEX3      = 16709, // Hex
    SPELL_GROW      = 16711, // Grow
    SPELL_LAUNCH    = 16716, // Launch (Whee!)
};

// 17009
class spell_voodoo : public SpellScriptLoader
{
    public:
        spell_voodoo() : SpellScriptLoader("spell_voodoo") { }

        class spell_voodoo_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_voodoo_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_BREW) || !sSpellMgr->GetSpellInfo(SPELL_GHOSTLY) ||
                    !sSpellMgr->GetSpellInfo(SPELL_HEX1) || !sSpellMgr->GetSpellInfo(SPELL_HEX2) ||
                    !sSpellMgr->GetSpellInfo(SPELL_HEX3) || !sSpellMgr->GetSpellInfo(SPELL_GROW) ||
                    !sSpellMgr->GetSpellInfo(SPELL_LAUNCH))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                uint32 spellid = RAND(SPELL_BREW, SPELL_GHOSTLY, RAND(SPELL_HEX1, SPELL_HEX2, SPELL_HEX3), SPELL_GROW, SPELL_LAUNCH);
                if (Unit* target = GetHitUnit())
                    GetCaster()->CastSpell(target, spellid, false);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_voodoo_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_voodoo_SpellScript();
        }
};

void AddSC_durotar()
{
    new npc_lazy_peon();
    new npc_tiger_matriarch_credit();
    new npc_tiger_matriarch();
    new npc_troll_volunteer();
    new spell_mount_check();
    new spell_voljin_war_drums();
    new spell_voodoo();
}
