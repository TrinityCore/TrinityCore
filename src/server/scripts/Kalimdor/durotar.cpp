/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"

/*######
##Quest 5441: Lazy Peons
##npc_lazy_peon
######*/

enum LazyPeonYells
{
    SAY_SPELL_HIT                                 = -1000600   //Ow! OK, I''ll get back to work, $N!'
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

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_lazy_peonAI(pCreature);
    }

    struct npc_lazy_peonAI : public ScriptedAI
    {
        npc_lazy_peonAI(Creature *c) : ScriptedAI(c) {}

        uint64 uiPlayerGUID;

        uint32 m_uiRebuffTimer;
        bool work;

        void Reset ()
        {
            uiPlayerGUID = 0;
            m_uiRebuffTimer = 0;
            work = false;
        }

        void MovementInform(uint32 /*type*/, uint32 id)
        {
            if (id == 1)
                work = true;
        }

        void SpellHit(Unit* caster, const SpellEntry * spell)
        {
            if (spell->Id == SPELL_AWAKEN_PEON && caster->GetTypeId() == TYPEID_PLAYER
                && CAST_PLR(caster)->GetQuestStatus(QUEST_LAZY_PEONS) == QUEST_STATUS_INCOMPLETE)
            {
                caster->ToPlayer()->KilledMonsterCredit(me->GetEntry(),me->GetGUID());
                DoScriptText(SAY_SPELL_HIT, me, caster);
                me->RemoveAllAuras();
                if (GameObject* Lumberpile = me->FindNearestGameObject(GO_LUMBERPILE, 20))
                    me->GetMotionMaster()->MovePoint(1,Lumberpile->GetPositionX()-1,Lumberpile->GetPositionY(),Lumberpile->GetPositionZ());
            }
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (work == true)
                me->HandleEmoteCommand(466);
            if (m_uiRebuffTimer <= uiDiff)
            {
                DoCast(me, SPELL_BUFF_SLEEP);
                m_uiRebuffTimer = 300000;                 //Rebuff agian in 5 minutes
            }
            else
                m_uiRebuffTimer -= uiDiff;
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
        npc_tiger_matriarch_credit() : CreatureScript("npc_tiger_matriarch_credit"){}

        struct npc_tiger_matriarch_creditAI : public Scripted_NoMovementAI
        {
           npc_tiger_matriarch_creditAI(Creature* creature) : Scripted_NoMovementAI(creature)
           {
               events.ScheduleEvent(EVENT_CHECK_SUMMON_AURA, 2000);
           }

            void UpdateAI(const uint32 diff)
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
                            if (Unit* summoner = CAST_SUM(*itr)->GetSummoner())
                                if (!summoner->HasAura(SPELL_NO_SUMMON_AURA) && !summoner->HasAura(SPELL_SUMMON_ZENTABRA_TRIGGER)
                                    && !summoner->isInCombat())
                                {
                                    me->AddAura(SPELL_NO_SUMMON_AURA, summoner);
                                    me->AddAura(SPELL_DETECT_INVIS, summoner);
                                    summoner->CastSpell(summoner, SPELL_SUMMON_MATRIARCH, true);
                                    Talk(SAY_MATRIARCH_AGGRO, summoner->GetGUID());
                                }
                        }
                    }

                    events.ScheduleEvent(EVENT_CHECK_SUMMON_AURA, 5000);
                }
            }

        private:
            EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_tiger_matriarch_creditAI(creature);
        }
};

class npc_tiger_matriarch : public CreatureScript
{
    public:
        npc_tiger_matriarch() : CreatureScript("npc_tiger_matriarch"){}

        struct npc_tiger_matriarchAI : public ScriptedAI
        {
            npc_tiger_matriarchAI(Creature* creature) : ScriptedAI(creature) {}

            void IsSummonedBy(Unit* summoner)
            {
                if (summoner->GetTypeId() != TYPEID_PLAYER)
                    return;

                _tiger = summoner->GetVehicle()->GetBase();
                if (_tiger)
                {
                    me->AddThreat(_tiger, 500000.0f);
                    DoCast(me, SPELL_FURIOUS_BITE);
                    events.ScheduleEvent(EVENT_POUNCE, 100);
                    events.ScheduleEvent(EVENT_NOSUMMON, 50000);
                }
            }

            void KilledUnit(Unit* victim)
            {
                if (victim->GetTypeId() != TYPEID_UNIT)
                    return;

                if (Unit* vehSummoner = CAST_SUM(victim)->GetSummoner())
                {
                    vehSummoner->RemoveAurasDueToSpell(SPELL_NO_SUMMON_AURA);
                    vehSummoner->RemoveAurasDueToSpell(SPELL_DETECT_INVIS);
                    vehSummoner->RemoveAurasDueToSpell(SPELL_SPIRIT_OF_THE_TIGER_RIDER);
                    vehSummoner->RemoveAurasDueToSpell(SPELL_SUMMON_ZENTABRA_TRIGGER);
                }
                me->ForcedDespawn();
            }

            void DamageTaken(Unit* attacker, uint32& damage)
            {
               if (HealthBelowPct(20))
               {
                    damage = 0;
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    if (Unit* vehSummoner = CAST_SUM(attacker)->GetSummoner())
                    {
                        vehSummoner->AddAura(SPELL_SUMMON_ZENTABRA_TRIGGER, vehSummoner);
                        vehSummoner->CastSpell(vehSummoner, SPELL_SUMMON_ZENTABRA, true);
                        attacker->CastSpell(attacker, SPELL_EJECT_PASSENGERS, true);
                        vehSummoner->RemoveAurasDueToSpell(SPELL_NO_SUMMON_AURA);
                        vehSummoner->RemoveAurasDueToSpell(SPELL_DETECT_INVIS);
                        vehSummoner->RemoveAurasDueToSpell(SPELL_SPIRIT_OF_THE_TIGER_RIDER);
                        vehSummoner->RemoveAurasDueToSpell(SPELL_SUMMON_ZENTABRA_TRIGGER);
                    }
                    me->ForcedDespawn();
                }
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (!_tiger)
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_POUNCE:
                            DoCastVictim(SPELL_POUNCE);
                            events.ScheduleEvent(EVENT_POUNCE, 30000);
                            break;
                        case EVENT_NOSUMMON: // Reapply SPELL_NO_SUMMON_AURA
                            if (Unit* vehSummoner = CAST_SUM(_tiger)->GetSummoner())
                                me->AddAura(SPELL_NO_SUMMON_AURA, vehSummoner);
                            events.ScheduleEvent(EVENT_NOSUMMON, 50000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap events;
            Unit* _tiger;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_tiger_matriarchAI(creature);
        }
};

// These models was found in sniff.
// TODO: generalize these models with race from dbc
uint32 const trollmodel[] =
{11665,11734,11750,12037,12038,12042,12049,12849,13529,14759,15570,15701,
15702,1882,1897,1976,2025,27286,2734,2735,4084,4085,4087,4089,4231,4357,
4358,4360,4361,4362,4363,4370,4532,4537,4540,4610,6839,7037,9767,9768};

class npc_troll_volunteer : public CreatureScript
{
    public:
        npc_troll_volunteer() : CreatureScript("npc_troll_volunteer") { }

        struct npc_troll_volunteerAI : public ScriptedAI
        {
            npc_troll_volunteerAI(Creature* creature) : ScriptedAI(creature)
            {
                Reset();
                Player* player = me->GetOwner()->ToPlayer();

                switch (urand(1,4))
                {
                    case 1:
                        _mountModel = 6471;
                        break;
                    case 2:
                        _mountModel = 6473;
                        break;
                    case 3:
                        _mountModel = 6469;
                        break;
                    case 4:
                        _mountModel = 6472;
                        break;
                }
                me->SetDisplayId(trollmodel[urand(0, 39)]);
                if (player)
                    me->GetMotionMaster()->MoveFollow(player, 5.0f, urand(120, 240));
            }

            void Reset()
            {
                _complete = false;
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

            void MovementInform(uint32 type, uint32 id)
            {
                if (type != POINT_MOTION_TYPE)
                    return;
                if (id == POINT_URUZIN)
                    me->DespawnOrUnsummon();
            }

            void SpellHit(Unit* caster, SpellEntry const* spell)
            {
                if (spell->Id == SPELL_AOE_TURNIN && caster->GetEntry() == NPC_URUZIN && !_complete)
                {
                    _complete = true;    // Preventing from giving credit twice
                    DoCast(me, SPELL_TURNIN);
                    DoCast(me, SPELL_QUEST_CREDIT);
                    me->RemoveAurasDueToSpell(SPELL_MOUNTING_CHECK);
                    me->Unmount();
                    Talk(SAY_VOLUNTEER_END);
                    me->GetMotionMaster()->MovePoint(POINT_URUZIN, caster->GetPositionX(), caster->GetPositionY(), caster->GetPositionZ());
                }
            }

        private:
            uint32 _mountModel;
            bool _complete;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_troll_volunteerAI(creature);
        }
};

class spell_mount_check : public SpellScriptLoader
{
    public:
        spell_mount_check() : SpellScriptLoader("spell_mount_check") {}

        class spell_mount_check_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mount_check_AuraScript)
            bool Validate(SpellEntry const * /*spellEntry*/)
            {
                if (!sSpellStore.LookupEntry(SPELL_MOUNTING_CHECK))
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
                    if (Creature* volunteer = target->ToCreature())
                        if (uint32 mountid = CAST_AI(npc_troll_volunteer::npc_troll_volunteerAI, volunteer->AI())->GetMountId())
                            target->Mount(mountid);
                }
                else if (!owner->IsMounted() && target->IsMounted())
                    target->Unmount();

                target->SetSpeed(MOVE_RUN, owner->GetSpeedRate(MOVE_RUN));
                target->SetSpeed(MOVE_WALK, owner->GetSpeedRate(MOVE_WALK));
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_mount_check_AuraScript::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_mount_check_AuraScript();
        }
};

class spell_voljin_war_drums : public SpellScriptLoader
{
    public:
        spell_voljin_war_drums() : SpellScriptLoader("spell_voljin_war_drums") {}

        class spell_voljin_war_drums_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_voljin_war_drums_SpellScript)
            bool Validate(SpellEntry const * /*spellEntry*/)
            {
                if (!sSpellStore.LookupEntry(SPELL_MOTIVATE_1))
                    return false;
                if (!sSpellStore.LookupEntry(SPELL_MOTIVATE_2))
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
                        caster->CastSpell(target, motivate, true, NULL, NULL, caster->GetGUID());
                }
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_voljin_war_drums_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_voljin_war_drums_SpellScript();
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
}