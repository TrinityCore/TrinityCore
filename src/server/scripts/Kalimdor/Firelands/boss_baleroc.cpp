/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

/*
***To-do list***
***
***Implement Vital Spark - http://www.wowhead.com/spell=99262
***Implement Vital Flame - http://www.wowhead.com/spell=99263
***
***Redesign achievement data storage system
*/

#include "firelands.h"

enum Spells
{
    SPELL_INFERNO_BLADE             = 99350,
    SPELL_INFERNO_STRIKE            = 99351,
    SPELL_DECIMATION_BLADE          = 99352,
    SPELL_DECIMATION_BLADE_2        = 99405,
    SPELL_DECIMATING_STRIKE         = 99353,

    SPELL_BLAZE_OF_GLORY            = 99252,
    SPELL_INCENDIARY_SOUL           = 99369,

    SPELL_SHARDS_OF_TORMENT         = 99259,
    SPELL_SHARDS_OF_TORMENT_2       = 99260,
    SPELL_TORMENT_COSMETIC_1        = 99258,
    SPELL_TORMENT                   = 99254,
    SPELL_TORMENT_PERIODIC          = 99255,
    SPELL_WAVE_OF_TORMENT           = 99261,
    SPELL_TORMENTED_20              = 99257,
    SPELL_TORMENTED_30              = 99402,
    SPELL_TORMENTED_40              = 99403,
    SPELL_TORMENTED_60              = 99404,

    SPELL_COUNTDOWN                 = 99515,
    SPELL_COUNTDOWN_2               = 99516,
    SPELL_COUNTDOWN_3               = 99517,
    SPELL_COUNTDOWN_4               = 99518,
    SPELL_COUNTDOWN_5               = 99519,

    SPELL_BERSERK                   = 26662,
};

enum Events
{
    EVENT_BLADE                     = 1,
    EVENT_RESTORE_WEAPONS           = 2,
    EVENT_INCENDIARY_SOUL           = 3,
    EVENT_SHARDS_OF_TORMENT         = 4,
    EVENT_COUNTDOWN                 = 5,
    EVENT_BERSERK                   = 6,

    EVENT_SHARD_SPAWN_EFFECT        = 7,
    EVENT_UNLOCK_YELLSPAM           = 8,
};

enum Emotes
{
    EMOTE_AGGRO                     = 0,
    EMOTE_SHARDS_OF_TORMENT         = 1,
    EMOTE_INFERNO_BLADE             = 2,
    EMOTE_DECIMATION_BLADE          = 3,
    EMOTE_KILL                      = 4,
    EMOTE_ENRAGE                    = 5,
    EMOTE_ENRAGE_2                  = 6,
    EMOTE_DEATH                     = 7,
    ABILITY_INFERNO_BLADE           = 8,
    ABILITY_DECIMATION_BLADE        = 9,
};

enum Guids
{
    GUID_TORMENTED    = 1,
};

enum Misc
{
    EQUIP_DECIMATION_BLADE          = 71082,
    EQUIP_INFERNO_BLADE             = 71138,
};

class boss_baleroc : public CreatureScript
{
    public:
        boss_baleroc() : CreatureScript("boss_baleroc") { }

        struct boss_balerocAI : public BossAI
        {
            boss_balerocAI(Creature* creature) : BossAI(creature, DATA_BALEROC)
            {
            }

            bool _canYellKilledPlayer;

            void Reset() OVERRIDE
            {
                _Reset();
                me->SetMaxPower(POWER_RAGE, 0);
                SetEquipmentSlots(true);
                me->SetCanDualWield(true);
            }

            void SpellHit(Unit* /*caster*/, SpellInfo const* spell) OVERRIDE
            {
                switch (spell->Id)
                {
                    case SPELL_INFERNO_BLADE:
                        SetEquipmentSlots(false, EQUIP_INFERNO_BLADE, EQUIP_UNEQUIP);
                        me->SetCanDualWield(false);
                        events.ScheduleEvent(EVENT_RESTORE_WEAPONS, 15*IN_MILLISECONDS);
                        break;
                    case SPELL_DECIMATION_BLADE:
                    case SPELL_DECIMATION_BLADE_2:
                        SetEquipmentSlots(false, EQUIP_DECIMATION_BLADE, EQUIP_UNEQUIP);
                        me->SetCanDualWield(false);
                        events.ScheduleEvent(EVENT_RESTORE_WEAPONS, 15*IN_MILLISECONDS);
                        break;
                    default:
                        break;
                }
            }

            void EnterCombat(Unit* target) OVERRIDE
            {
                _EnterCombat();
                Talk(EMOTE_AGGRO);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                events.ScheduleEvent(EVENT_INCENDIARY_SOUL, 8.5*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_SHARDS_OF_TORMENT, 5*IN_MILLISECONDS);
                if (me->GetMap()->IsHeroic())
                    events.ScheduleEvent(EVENT_COUNTDOWN, 26*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_BLADE, 30.5*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_BERSERK, 6*MINUTE*IN_MILLISECONDS);

                //Reset our achievement list. We do this here and not in reset, as the debuff may have been spread after the boss has reset.
                for (int i = 0; i < 25; i++)
                {
                    _sharedThePain[i].player = 0;
                    _sharedThePain[i].tormented = 0;
                }
            }

            void KilledUnit(Unit* who) OVERRIDE
            {
                if (who->GetTypeId() == TYPEID_PLAYER && _canYellKilledPlayer)
                {
                    _canYellKilledPlayer = false;
                    events.ScheduleEvent(EVENT_UNLOCK_YELLSPAM, 8000);
                    Talk(EMOTE_KILL);
                }
            }

            void JustDied(Unit* /*killer*/) OVERRIDE
            {
                _JustDied();
                Talk(EMOTE_DEATH);
                SetEquipmentSlots(true);
                me->SetCanDualWield(true);;
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                if (Map* map = me->GetMap())
                {
                    Map::PlayerList const &PlayerList = map->GetPlayers();
                    if (!PlayerList.isEmpty())
                        for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                            if (i->GetSource()->ToPlayer()->HasQuestForItem(69848))
                            {
                                DoCast(101093);
                                break;
                            }
                }
            }

            void EnterEvadeMode() OVERRIDE
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_BLAZE_OF_GLORY);
                me->GetMotionMaster()->MoveTargetedHome();
                summons.DespawnAll();
                _DespawnAtEvade();
            }

            void DoMeleeAttackIfReady() OVERRIDE
            {
                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                Unit* victim = me->GetVictim();
                if (me->isAttackReady(BASE_ATTACK) && me->IsWithinMeleeRange(victim))
                {
                    if (me->HasAura(SPELL_DECIMATION_BLADE) || me->HasAura(SPELL_DECIMATION_BLADE_2))
                    {
                        me->CastSpell(me->GetVictim(), SPELL_DECIMATING_STRIKE, false);
                        me->resetAttackTimer(BASE_ATTACK);
                    }
                    else if (me->HasAura(SPELL_INFERNO_BLADE))
                    {
                        me->CastSpell(me->GetVictim(), SPELL_INFERNO_STRIKE, false);
                        me->AttackerStateUpdate(victim);
                        me->resetAttackTimer(BASE_ATTACK);
                    }
                    else
                    {
                        me->AttackerStateUpdate(victim);
                        me->resetAttackTimer(BASE_ATTACK);
                    }
                }
                if (me->haveOffhandWeapon() && me->isAttackReady(OFF_ATTACK) && me->IsWithinMeleeRange(victim))
                {
                    me->AttackerStateUpdate(victim, OFF_ATTACK);
                    me->resetAttackTimer(OFF_ATTACK);
                }
            }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                if (me->IsAlive())
                    if (!UpdateVictim())
                        return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BLADE:
                            switch (urand(1, 2))
                            {
                                case 1:
                                    DoCast(SPELL_INFERNO_BLADE);
                                    Talk(EMOTE_INFERNO_BLADE);
                                    Talk(ABILITY_INFERNO_BLADE);
                                    break;
                                case 2:
                                    DoCast(SPELL_DECIMATION_BLADE);
                                    Talk(EMOTE_DECIMATION_BLADE);
                                    Talk(ABILITY_DECIMATION_BLADE);
                                    break;
                            }
                            events.ScheduleEvent(EVENT_BLADE, 47*IN_MILLISECONDS);
                            break;
                        case EVENT_RESTORE_WEAPONS:
                            SetEquipmentSlots(true);
                            me->SetCanDualWield(true);
                            break;
                        case EVENT_INCENDIARY_SOUL:
                            if (me->GetVictim())
                            {
                                DoCast(me->GetVictim(), SPELL_BLAZE_OF_GLORY, false);
                                DoCast(SPELL_INCENDIARY_SOUL);
                            }
                            events.ScheduleEvent(EVENT_INCENDIARY_SOUL, 11.5*IN_MILLISECONDS);
                            break;
                        case EVENT_SHARDS_OF_TORMENT:
                            Talk(EMOTE_SHARDS_OF_TORMENT);
                            DoCast(SPELL_SHARDS_OF_TORMENT);
                            events.ScheduleEvent(EVENT_SHARDS_OF_TORMENT, 34*IN_MILLISECONDS);
                            break;
                        case EVENT_COUNTDOWN:
                            DoCast(SPELL_COUNTDOWN);
                            events.ScheduleEvent(EVENT_COUNTDOWN, 48*IN_MILLISECONDS);
                            break;
                        case EVENT_BERSERK:
                            DoCast(SPELL_BERSERK);
                            Talk(EMOTE_ENRAGE);
                            Talk(EMOTE_ENRAGE_2);
                            break;
                        case EVENT_UNLOCK_YELLSPAM:
                            _canYellKilledPlayer = true;
                            break;
                        default:
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }

            void SetGUID(uint64 guid, int32 type = 0) OVERRIDE
            {
                switch (type)
                {
                    case GUID_TORMENTED:
                        for (int i = 0; i < 25; i++)
                        {
                            if (_sharedThePain[i].player == guid)
                            {
                                _sharedThePain[i].tormented++;
                                break;
                            }
                            else if (_sharedThePain[i].player == 0)
                            {
                                _sharedThePain[i].player = guid;
                                _sharedThePain[i].tormented++;
                                break;
                            }
                        }
                        break;
                    default:
                        break;
                }
            }

            bool SharedThePain()
            {
                for (int i = 0; _sharedThePain[i].player != 0; i++)
                    if (_sharedThePain[i].tormented > 3)
                        return false;
                return true;
            }

            private:
                struct _sharedThePain
                {
                    uint64 player;
                    uint32 tormented;
                }
                _sharedThePain[25];
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return GetFirelandsAI<boss_balerocAI>(creature);
        }
};

//Used for achievements
typedef boss_baleroc::boss_balerocAI BalerocAI;

class npc_shard_of_torment : public CreatureScript
{
    public:
        npc_shard_of_torment() : CreatureScript("npc_shard_of_torment") { }

        struct npc_shard_of_tormentAI : public ScriptedAI
        {
            npc_shard_of_tormentAI(Creature* creature) : ScriptedAI(creature)
            {
                me->SetReactState(REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                me->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_DISABLE_TURN);
                me->SetDisplayId(me->GetCreatureTemplate()->Modelid2);
                _instance = creature->GetInstanceScript();
            }

            void IsSummonedBy(Unit* summoner) OVERRIDE
            {
                if (summoner->GetEntry() == NPC_BALEROC)
                {
                    if (_instance->GetBossState(DATA_BALEROC) != IN_PROGRESS)
                        me->DespawnOrUnsummon();
                    DoCast(SPELL_TORMENT_COSMETIC_1);
                    _events.ScheduleEvent(EVENT_SHARD_SPAWN_EFFECT, 5000);
                    me->SetInCombatWithZone();
                    _baleroc = summoner->ToCreature();
                }
                else
                    me->DespawnOrUnsummon();
            }

            void KilledUnit(Unit* who) OVERRIDE
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                    if (_baleroc)
                        _baleroc->AI()->KilledUnit(who);
            }

            void UpdateAI(uint32 diff)
            {
                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SHARD_SPAWN_EFFECT:
                            me->RemoveAurasDueToSpell(SPELL_TORMENT_COSMETIC_1);
                            DoCast(SPELL_TORMENT);
                            break;
                        default:
                            break;
                    }
                }
            }

            private:
                InstanceScript* _instance;
                EventMap _events;
                Creature* _baleroc;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_shard_of_tormentAI(creature);
        }
};

class spell_countdown_p1 : public SpellScriptLoader
{
    public:
        spell_countdown_p1() : SpellScriptLoader("spell_countdown_p1") { }

        class spell_countdown_p1_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_countdown_p1_SpellScript);

            bool Load()
            {
                return GetCaster()->GetTypeId() == TYPEID_UNIT;
            }

            void CastSpellLink()
            {
                if (target1->ToPlayer() && target2->ToPlayer())
                    target1->ToPlayer()->CastSpell(target2->ToPlayer(), SPELL_COUNTDOWN_5, true);
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (Unit* target = GetHitUnit())
                    GetCaster()->CastSpell(target, SPELL_COUNTDOWN_2, false);
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {

                //Remove current tank if we have one
                if (GetCaster()->GetVictim())
                    targets.remove(GetCaster()->ToCreature()->GetVictim());

                if (targets.size() < 2)
                {
                    FinishCast(SPELL_FAILED_NO_VALID_TARGETS);
                    return;
                }

                Trinity::Containers::RandomResizeList(targets, 2);

                std::list<WorldObject*>::const_iterator itr = targets.begin();
                target1 = (*itr);
                itr++;
                target2 = (*itr);
            }

            void Register() OVERRIDE
            {
                AfterCast += SpellCastFn(spell_countdown_p1_SpellScript::CastSpellLink);
                OnEffectHitTarget += SpellEffectFn(spell_countdown_p1_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_countdown_p1_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
            
            WorldObject* target1;
            WorldObject* target2;
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_countdown_p1_SpellScript();
        }
};

class spell_countdown_p2 : public SpellScriptLoader
{
    public:
        spell_countdown_p2() : SpellScriptLoader("spell_countdown_p2") { }

        class spell_countdown_p2_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_countdown_p2_AuraScript);

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
                    GetTarget()->CastSpell((Unit*)NULL, SPELL_COUNTDOWN_4, true);
                GetTarget()->ToPlayer()->RemoveAurasDueToSpell(SPELL_COUNTDOWN_5);
            }

            void Register() OVERRIDE
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_countdown_p2_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_countdown_p2_AuraScript();
        }
};

class spell_countdown_p3 : public SpellScriptLoader
{
    public:
        spell_countdown_p3() : SpellScriptLoader("spell_countdown_p3") { }

        class spell_countdown_p3_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_countdown_p3_SpellScript);

            bool Load()
            {
                return GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if(Trinity::UnitAuraCheck(false, SPELL_COUNTDOWN_2));
                targets.remove(GetCaster());

                if (targets.empty())
                    return;

                for (std::list<WorldObject*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                {
                    (*itr)->ToPlayer()->RemoveAurasDueToSpell(SPELL_COUNTDOWN_2);
                    (*itr)->ToPlayer()->RemoveAurasDueToSpell(SPELL_COUNTDOWN_5);
                }

                GetCaster()->RemoveAurasDueToSpell(SPELL_COUNTDOWN_2);
                GetCaster()->RemoveAurasDueToSpell(SPELL_COUNTDOWN_5);
            }

            void Register() OVERRIDE
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_countdown_p3_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_countdown_p3_SpellScript();
        }
};

class spell_decimating_strike : public SpellScriptLoader
{
    public:
        spell_decimating_strike() : SpellScriptLoader("spell_decimating_strike") { }

        class spell_decimating_strike_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_decimating_strike_SpellScript);

            bool Load()
            {
                if (GetCaster()->GetTypeId() != TYPEID_UNIT)
                    return false;
                return true;
            }

            bool Validate(SpellInfo const* /*spellInfo*/)
            {	
                if (!sSpellMgr->GetSpellInfo(SPELL_DECIMATING_STRIKE))
                    return false;
                return true;
            }

            void ChangeDamage()
            {
                if (GetCaster()->GetVictim())
                {
                    uint32 health = GetCaster()->GetVictim()->GetMaxHealth();
                    if (health*0.9 < 250000)
                        SetHitDamage(uint32(250000));
                    else
                        SetHitDamage(uint32(health*0.9));
                }
                else
                    SetHitDamage(uint32(250000));
            }

            void Register()
            {
                OnHit += SpellHitFn(spell_decimating_strike_SpellScript::ChangeDamage);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_decimating_strike_SpellScript();
        }
};

class spell_shards_of_torment : public SpellScriptLoader
{
    public:
        spell_shards_of_torment() : SpellScriptLoader("spell_shards_of_torment") { }

        class spell_shards_of_torment_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_shards_of_torment_SpellScript);

            bool Load()
            {
                return GetCaster()->GetTypeId() == TYPEID_UNIT;
            }

            void HandleScript(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                GetCaster()->CastSpell(GetHitUnit(), SPELL_SHARDS_OF_TORMENT_2, true);
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                uint8 numtargets;
                if (GetCaster()->GetMap()->Is25ManRaid())
                    numtargets = 2;
                else
                    numtargets = 1;

                while(targets.size() < numtargets)
                    numtargets--;

                
                if ((targets.size() > numtargets) && GetCaster()->GetVictim())
                    targets.remove(GetCaster()->ToCreature()->GetVictim()); //Safe to remove tank from list

                Trinity::Containers::RandomResizeList(targets, numtargets);
            }

            void Register() OVERRIDE
            {
                OnEffectHitTarget += SpellEffectFn(spell_shards_of_torment_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_shards_of_torment_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_shards_of_torment_SpellScript();
        }
};

class PlayerCheck
{
    public:
        bool operator()(WorldObject* object) const
        {
            if (object->GetTypeId() != TYPEID_PLAYER)
                if (!object->ToPlayer()->IsAlive())
                    if (object->ToPlayer()->IsGameMaster())
                        return true;

            return false;
        }
};

class spell_baleroc_torment : public SpellScriptLoader
{
    public:
        spell_baleroc_torment() : SpellScriptLoader("spell_baleroc_torment") { }

        class spell_baleroc_torment_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_baleroc_torment_SpellScript);

            bool Load()
            {
                return GetCaster()->GetTypeId() == TYPEID_UNIT;
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if(PlayerCheck());

                if (targets.empty())
                {
                    //No targets found, start pulsating immediately.
                    GetCaster()->ToCreature()->AI()->DoCast(SPELL_WAVE_OF_TORMENT);
                    return;
                }

                targets.sort(Trinity::ObjectDistanceOrderPred(GetCaster(), true));
                targets.resize(1);

                if ((*targets.begin())->GetDistance2d(GetCaster()) > 15.0f)
                    GetCaster()->ToCreature()->AI()->DoCast(SPELL_WAVE_OF_TORMENT);
                else
                {
                    if ((*targets.begin())->ToPlayer()->GetAura(SPELL_TORMENT_PERIODIC))
                        if ((*targets.begin())->ToPlayer()->GetAura(SPELL_TORMENT_PERIODIC)->GetCaster() != GetCaster())
                            GetCaster()->CastSpell((*targets.begin())->ToPlayer(), SPELL_TORMENT_PERIODIC, false);
                        else{
                        }
                    else
                        GetCaster()->CastSpell((*targets.begin())->ToPlayer(), SPELL_TORMENT_PERIODIC, false);
                }
            }

            void Register() OVERRIDE
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_baleroc_torment_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_baleroc_torment_SpellScript();
        }
};

class spell_baleroc_tormented : public SpellScriptLoader
{
    public:
        spell_baleroc_tormented() : SpellScriptLoader("spell_baleroc_tormented") { }

        class spell_baleroc_tormented_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_baleroc_tormented_SpellScript);
            
            void ChangeDamage()
            {
                //SetHitDamage(GetHitDamage()*GetHitUnit()->GetAuraCount(m_scriptSpellId));

                //The above example seems wrong, wowhead say the damage is 3000 per tick on normal, and 4250 on heroic,
                //while logs from retail say its 4000 normal, and 5000 heroic.
                if (GetHitUnit()->GetMap()->IsHeroic())
                {
                    float damageMultiplier = 1.0f+((GetHitDamage()-4250)/4250);
                    SetHitDamage((5000*GetHitUnit()->GetAuraCount(m_scriptSpellId))*damageMultiplier);
                }
                else
                {
                    float damageMultiplier = 1.0f+((GetHitDamage()-3000)/3000);
                    SetHitDamage((4000*GetHitUnit()->GetAuraCount(m_scriptSpellId))*damageMultiplier);
                }
            }

            void Register()
            {
                OnHit += SpellHitFn(spell_baleroc_tormented_SpellScript::ChangeDamage);
            }

        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_baleroc_tormented_SpellScript();
        }

        class spell_baleroc_tormented_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_baleroc_tormented_AuraScript);

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_DEATH)
                {
                    if (GetTarget()->GetMap()->IsHeroic())
                        GetTarget()->CastSpell(GetTarget(), SPELL_TORMENTED_40, true);
                    else
                        GetTarget()->CastSpell(GetTarget(), SPELL_TORMENTED_20, true);
                }
            }

            void Register() OVERRIDE
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_baleroc_tormented_AuraScript::OnRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_baleroc_tormented_AuraScript();
        }
};

class spell_baleroc_tormented_debuff : public SpellScriptLoader
{
    public:
        spell_baleroc_tormented_debuff() : SpellScriptLoader("spell_baleroc_tormented_debuff") { }

        class spell_baleroc_tormented_debuff_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_baleroc_tormented_debuff_AuraScript);

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (InstanceScript* instance = GetTarget()->GetInstanceScript())
                    if (Creature* baleroc = ObjectAccessor::GetCreature(*GetTarget(), instance->GetData64(DATA_BALEROC)))
                        baleroc->AI()->SetGUID(GetTarget()->GetGUID(), GUID_TORMENTED);
            }

            void Register() OVERRIDE
            {
                OnEffectApply += AuraEffectApplyFn(spell_baleroc_tormented_debuff_AuraScript::OnApply, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_baleroc_tormented_debuff_AuraScript();
        }
};

class spell_baleroc_tormented_heroic : public SpellScriptLoader
{
    public:
        spell_baleroc_tormented_heroic() : SpellScriptLoader("spell_baleroc_tormented_heroic") { }

        class spell_baleroc_tormented_heroic_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_baleroc_tormented_heroic_SpellScript);

            bool Load()
            {
                return GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }

            void HandleScript(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                if (GetCaster()->GetMap()->IsHeroic())
                    GetHitUnit()->CastSpell(GetHitUnit(), SPELL_TORMENTED_40, true);
            }

            void Register() OVERRIDE
            {
                OnEffectHitTarget += SpellEffectFn(spell_baleroc_tormented_heroic_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_baleroc_tormented_heroic_SpellScript();
        }
};

class achievement_share_the_pain : public AchievementCriteriaScript
{
    public:
        achievement_share_the_pain() : AchievementCriteriaScript("achievement_share_the_pain") { }

        bool OnCheck(Player* /*source*/, Unit* target) OVERRIDE
        {
            if (!target)
                return false;

            if (BalerocAI* balerocAI = CAST_AI(BalerocAI, target->GetAI()))
                return balerocAI->SharedThePain();

            return false;
        }
};

void AddSC_boss_baleroc()
{
    new boss_baleroc();

    new npc_shard_of_torment();

    new spell_countdown_p1();
    new spell_countdown_p2();
    new spell_countdown_p3();

    new spell_decimating_strike();

    new spell_shards_of_torment();
    new spell_baleroc_torment();
    new spell_baleroc_tormented();
    new spell_baleroc_tormented_heroic();
    new spell_baleroc_tormented_debuff();

    new achievement_share_the_pain();
};
