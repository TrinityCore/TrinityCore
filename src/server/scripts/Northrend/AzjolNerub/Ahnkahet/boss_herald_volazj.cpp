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

#include "ahnkahet.h"
#include "DB2Stores.h"
#include "InstanceScript.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "SpellInfo.h"
#include "TemporarySummon.h"

enum VolazjTexts
{
    SAY_AGGRO = 0,
    SAY_INSANITY = 1,
    SAY_SLAY_1 = 2,
    SAY_SLAY_2 = 3,
    SAY_SLAY_3 = 4,
    SAY_DEATH_1 = 5,
    SAY_DEATH_2 = 6,

    WHISPER_AGGRO = 7,
    WHISPER_INSANITY = 8,
    WHISPER_SLAY_1 = 9,
    WHISPER_SLAY_2 = 10,
    WHISPER_SLAY_3 = 11,
    WHISPER_DEATH_1 = 12,
    WHISPER_DEATH_2 = 13
};

enum VolazjSpells
{
    SPELL_INSANITY = 57496, // Dummy
    INSANITY_VISUAL = 57561,
    SPELL_INSANITY_TARGET = 57508,
    SPELL_MIND_FLAY = 57941,
    SPELL_SHADOW_BOLT_VOLLEY = 57942,
    SPELL_SHIVER = 57949,
    SPELL_CLONE_PLAYER = 57507, // cast on player during insanity
    SPELL_INSANITY_PHASING_1 = 57508,
    SPELL_INSANITY_PHASING_2 = 57509,
    SPELL_INSANITY_PHASING_3 = 57510,
    SPELL_INSANITY_PHASING_4 = 57511,
    SPELL_INSANITY_PHASING_5 = 57512,

    SPELL_WHISPER_AGGRO = 60291,
    SPELL_WHISPER_INSANITY = 60292,
    SPELL_WHISPER_SLAY_1 = 60293,
    SPELL_WHISPER_SLAY_2 = 60294,
    SPELL_WHISPER_SLAY_3 = 60295,
    SPELL_WHISPER_DEATH_1 = 60296,
    SPELL_WHISPER_DEATH_2 = 60297,

    SPELL_TWISTED_VISAGE_VISUAL = 57551,
    SPELL_TWISTED_VISAGE_DEATH = 57555,

    // Death Knight
    SPELL_TWISTED_VISAGE_DEATH_GRIP = 57602,
    SPELL_TWISTED_VISAGE_PLAGUE_STRIKE = 57599,
    // Druid
    SPELL_TWISTED_VISAGE_WRATH = 57648,
    SPELL_TWISTED_VISAGE_MOONFIRE = 57647,
    SPELL_TWISTED_VISAGE_LIFEBLOOM = 57762,
    SPELL_TWISTED_VISAGE_CAT_FORM = 57655,
    SPELL_TWISTED_VISAGE_MANGLE = 57657,
    SPELL_TWISTED_VISAGE_RIP = 57661,
    SPELL_TWISTED_VISAGE_NOURISH = 57765,
    // Hunter
    SPELL_TWISTED_VISAGE_SHOOT = 57589,
    SPELL_TWISTED_VISAGE_DISENGAGE = 57635,
    // Mage
    SPELL_TWISTED_VISAGE_FIREBALL = 57628,
    SPELL_TWISTED_VISAGE_FROST_NOVA = 57629,
    // Paladin
    SPELL_TWISTED_VISAGE_CONSECRATION = 57798,
    SPELL_TWISTED_VISAGE_AVENGER__S_SHIELD = 57799,
    SPELL_TWISTED_VISAGE_SEAL_OF_COMMAND = 57769,
    SPELL_TWISTED_VISAGE_JUDGEMENT_OF_LIGHT = 57774,
    // Priest
    SPELL_TWISTED_VISAGE_GREATER_HEAL = 57775,
    SPELL_TWISTED_VISAGE_RENEW = 57777,
    SPELL_TWISTED_VISAGE_SHADOW_WORD_PAIN = 57778,
    SPELL_TWISTED_VISAGE_MIND_FLAY = 57779,
    // Rogue
    SPELL_TWISTED_VISAGE_EVISCERATE = 57641,
    SPELL_TWISTED_VISAGE_SINISTER_STRIKE = 57640,
    // Shaman
    SPELL_TWISTED_VISAGE_EARTH_SHOCK = 57783,
    SPELL_TWISTED_VISAGE_LIGHTNING_BOLT = 57781,
    SPELL_TWISTED_VISAGE_EARTH_SHIELD = 57802,
    SPELL_TWISTED_VISAGE_HEALING_WEAVE = 57785,
    SPELL_TWISTED_VISAGE_THUNDERSTORM = 57784,
    // Warlock
    SPELL_TWISTED_VISAGE_CORRUPTION = 57645,
    SPELL_TWISTED_VISAGE_SHADOW_BOLT = 57644,
    // Warrior
    SPELL_TWISTED_VISAGE_THUNDER_CLAP = 57832,
    SPELL_TWISTED_VISAGE_DEVASTATE = 57795,
    SPELL_TWISTED_VISAGE_MORTAL_STRIKE = 57789,
    SPELL_TWISTED_VISAGE_INTERCEPT = 61490,
    SPELL_TWISTED_VISAGE_HAMSTRING = 9080,
    SPELL_TWISTED_VISAGE_BLOODTHIRST = 57790,
};

enum VolazjAchievements
{
    ACHIEV_QUICK_DEMISE_START_EVENT = 20382,
};

enum VolazjMisc
{
    DATA_TWISTED_VISAGE_PLAYER_CLASS = 1,
    DATA_TWISTED_VISAGE_PLAYER_SPEC = 2,
};

struct boss_volazj : public BossAI
{
    boss_volazj(Creature* creature) : BossAI(creature, DATA_HERALD_VOLAZJ)
    {
        Initialize();
    }

    void Reset() override
    {
        BossAI::Reset();

        Initialize();

        // Visible for all players in insanity
        for (uint32 i = 173; i <= 177; ++i)
            PhasingHandler::AddPhase(me, i, false);
        PhasingHandler::AddPhase(me, 169, true);

        ResetPlayersPhaseMask();

        // Cleanup
        me->SetUninteractible(false);
        me->SetControlled(false, UNIT_STATE_STUNNED);
    }

    void Initialize()
    {
        // Used for Insanity handling
        _insanityHandled = 0;
    }

    void ScheduleTasks() override
    {
        scheduler.Schedule(8s, [this](TaskContext task)
        {
            DoCastVictim(SPELL_MIND_FLAY);
            task.Repeat(20s);
        })
        .Schedule(5s, [this](TaskContext task)
        {
            DoCastVictim(SPELL_SHADOW_BOLT_VOLLEY);
            task.Repeat();
        })
        .Schedule(15s, [this](TaskContext task)
        {
            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                DoCast(target, SPELL_SHIVER);
            task.Repeat();
        });
    }

    // returns the percentage of health after taking the given damage.
    uint32 GetHealthPct(uint32 damage)
    {
        if (damage > me->GetHealth())
            return 0;
        return 100*(me->GetHealth()-damage)/me->GetMaxHealth();
    }

    void DamageTaken(Unit* /*pAttacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (me->IsUninteractible())
            damage = 0;

        if ((GetHealthPct(0) >= 66 && GetHealthPct(damage) < 66) || (GetHealthPct(0) >= 33 && GetHealthPct(damage) < 33))
        {
            me->InterruptNonMeleeSpells(false);
            DoCast(me, SPELL_INSANITY, false);
        }
    }

    void JustSummoned(Creature* summon) override
    {
        summon->SetReactState(REACT_PASSIVE);
        summons.Summon(summon);
    }

    void SpellHitTarget(WorldObject* target, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_INSANITY)
        {
            // Not good target or too many players
            if (target->GetTypeId() != TYPEID_PLAYER || _insanityHandled > 4)
                return;
            // First target - start channel visual and set self as unnattackable
            if (!_insanityHandled)
            {
                // Channel visual
                DoCast(me, INSANITY_VISUAL, true);
                Talk(SAY_INSANITY);
                DoCastSelf(SPELL_WHISPER_INSANITY, true);
                // Unattackable
                me->SetUninteractible(true);
                me->SetControlled(true, UNIT_STATE_STUNNED);
            }
            // phase mask
            target->CastSpell(target, SPELL_INSANITY_TARGET + _insanityHandled, true);
            // summon twisted party members for this target
            Map::PlayerList const& players = me->GetMap()->GetPlayers();
            for (auto i = players.begin(); i != players.end(); ++i)
            {
                Player* player = i->GetSource();
                if (!player || !player->IsAlive())
                    continue;
                // Summon clone
                if (TempSummon* summon = me->SummonCreature(NPC_TWISTED_VISAGE, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_CORPSE_DESPAWN))
                {
                    // clone
                    player->CastSpell(summon, SPELL_CLONE_PLAYER, true);
                    summon->GetAI()->SetData(DATA_TWISTED_VISAGE_PLAYER_CLASS, player->GetClass());
                    summon->GetAI()->SetData(DATA_TWISTED_VISAGE_PLAYER_SPEC, AsUnderlyingType(player->GetPrimarySpecialization()));
                    summon->SetReactState(REACT_AGGRESSIVE);
                    DoZoneInCombat(summon);
                    // set phase
                    PhasingHandler::AddPhase(summon, 173 + _insanityHandled, true);
                }
            }
            ++_insanityHandled;
        }
    }

    void ResetPlayersPhaseMask()
    {
        Map::PlayerList const& players = me->GetMap()->GetPlayers();
        for (auto i = players.begin(); i != players.end(); ++i)
        {
            Player* player = i->GetSource();
            for (uint32 index = 0; index <= 4; ++index)
                player->RemoveAurasDueToSpell(SPELL_INSANITY_TARGET + index);
        }
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);
        DoCastSelf(SPELL_WHISPER_AGGRO);

        instance->TriggerGameEvent(ACHIEV_QUICK_DEMISE_START_EVENT);
    }

    uint32 GetSpellForPhaseMask(uint32 phase)
    {
        uint32 spell = 0;
        switch (phase)
        {
            case 173:
                spell = SPELL_INSANITY_PHASING_1;
                break;
            case 174:
                spell = SPELL_INSANITY_PHASING_2;
                break;
            case 175:
                spell = SPELL_INSANITY_PHASING_3;
                break;
            case 176:
                spell = SPELL_INSANITY_PHASING_4;
                break;
            case 177:
                spell = SPELL_INSANITY_PHASING_5;
                break;
        }
        return spell;
    }

    void SummonedCreatureDespawn(Creature* summon) override
    {
        BossAI::SummonedCreatureDespawn(summon);

        uint32 phase = !summon->GetPhaseShift().GetPhases().empty() ? summon->GetPhaseShift().GetPhases().begin()->Id : 0;
        uint32 nextPhase = 0;

        // Check if all summons in this phase killed
        for (SummonList::const_iterator iter = summons.begin(); iter != summons.end(); ++iter)
        {
            if (Creature* visage = ObjectAccessor::GetCreature(*me, *iter))
            {
                // Not all are dead
                if (visage->InSamePhase(summon))
                    return;
                else if (!visage->GetPhaseShift().GetPhases().empty())
                {
                    nextPhase = visage->GetPhaseShift().GetPhases().begin()->Id;
                    break;
                }
            }
        }

        // Roll Insanity
        uint32 spell = GetSpellForPhaseMask(phase);
        uint32 spell2 = GetSpellForPhaseMask(nextPhase);
        Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
        for (auto itr = playerList.begin(); itr != playerList.end(); ++itr)
        {
            if (Player* player = itr->GetSource())
            {
                if (player->HasAura(spell))
                {
                    player->RemoveAurasDueToSpell(spell);
                    if (spell2) // if there is still some different mask cast spell for it
                        player->CastSpell(player, spell2, true);
                }
            }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        if (_insanityHandled)
        {
            if (!summons.empty())
                return;

            _insanityHandled = 0;
            me->SetUninteractible(false);
            me->SetControlled(false, UNIT_STATE_STUNNED);
            me->RemoveAurasDueToSpell(INSANITY_VISUAL);
        }

        scheduler.Update(diff);
    }

    void JustDied(Unit* killer) override
    {
        BossAI::JustDied(killer);
        ResetPlayersPhaseMask();

        switch (urand(0, 1))
        {
            case 0:
                Talk(SAY_DEATH_1);
                DoCastSelf(SPELL_WHISPER_DEATH_1, true);
                break;
            case 1:
                Talk(SAY_DEATH_2);
                DoCastSelf(SPELL_WHISPER_DEATH_2, true);
                break;
        }
    }

    void KilledUnit(Unit* who) override
    {
        if (who->GetTypeId() != TYPEID_PLAYER)
            return;

        switch (urand(0, 2))
        {
            case 0:
                Talk(SAY_SLAY_1);
                DoCastSelf(SPELL_WHISPER_SLAY_1);
                break;
            case 1:
                Talk(SAY_SLAY_2);
                DoCastSelf(SPELL_WHISPER_SLAY_2);
                break;
            case 2:
                Talk(SAY_SLAY_3);
                DoCastSelf(SPELL_WHISPER_SLAY_3);
                break;
        }
    }

private:
    uint32 _insanityHandled;
};

struct npc_twisted_visage : public ScriptedAI
{
    npc_twisted_visage(Creature* creature) : ScriptedAI(creature), _playerClass(CLASS_NONE), _playerSpec(0) { }

    void Reset() override
    {
        DoCastSelf(SPELL_TWISTED_VISAGE_VISUAL, true);

        _scheduler.SetValidator([this]
        {
            return !me->HasUnitState(UNIT_STATE_CASTING);
        });
    }

    void AttackStart(Unit* who) override
    {
        ChrSpecializationEntry const* chrSpecialization = sChrSpecializationStore.LookupEntry(_playerSpec);
        if (chrSpecialization && chrSpecialization->GetFlags().HasFlag(ChrSpecializationFlag::Ranged))
            ScriptedAI::AttackStartCaster(who, 25.0f);
        else
            ScriptedAI::AttackStart(who);
    }

    void SetData(uint32 type, uint32 data) override
    {
        if (type == DATA_TWISTED_VISAGE_PLAYER_CLASS)
        {
            if (data > CLASS_NONE && data < MAX_CLASSES)
                _playerClass = data;
        }
        else if (type == DATA_TWISTED_VISAGE_PLAYER_SPEC && _playerClass != CLASS_NONE)
        {
            if (data < 3)
                _playerSpec = data;

            switch (_playerClass)
            {
                case CLASS_WARRIOR:
                    switch (ChrSpecialization(data))
                    {
                        case ChrSpecialization::WarriorArms:
                            _scheduler.Schedule(3s, [this](TaskContext mortalStrike)
                            {
                                DoCastVictim(SPELL_TWISTED_VISAGE_MORTAL_STRIKE);
                                mortalStrike.Repeat(3s, 5s);
                            }).Schedule(5s, [this](TaskContext harmstring)
                            {
                                DoCastVictim(SPELL_TWISTED_VISAGE_HAMSTRING);
                                harmstring.Repeat(5s, 10s);
                            });
                            break;
                        default:
                        case ChrSpecialization::WarriorFury:
                            _scheduler.Schedule(2s, [this](TaskContext intercept)
                            {
                                if (!me->IsWithinCombatRange(me->GetVictim(), 8.0f))
                                {
                                    DoCastVictim(SPELL_TWISTED_VISAGE_INTERCEPT);
                                    intercept.Repeat(12s);
                                }
                                else
                                    intercept.Repeat(1s);
                            }).Schedule(3s, [this](TaskContext bloodthirst)
                            {
                                DoCastVictim(SPELL_TWISTED_VISAGE_BLOODTHIRST);
                                bloodthirst.Repeat(3s, 5s);
                            });
                            break;
                        case ChrSpecialization::WarriorProtection:
                            _scheduler.Schedule(5s, [this](TaskContext thunderClap)
                            {
                                DoCastSelf(SPELL_TWISTED_VISAGE_THUNDER_CLAP);
                                thunderClap.Repeat(5s, 10s);
                            }).Schedule(3s, [this](TaskContext devastate)
                            {
                                DoCastVictim(SPELL_TWISTED_VISAGE_DEVASTATE);
                                devastate.Repeat(3s, 5s);
                            });
                            break;
                    }
                    break;
                case CLASS_PALADIN:
                    switch (ChrSpecialization(data))
                    {
                        case ChrSpecialization::PaladinProtection:
                            _scheduler.Schedule(5s, [this](TaskContext consecration)
                            {
                                DoCastSelf(SPELL_TWISTED_VISAGE_CONSECRATION);
                                consecration.Repeat(5s, 10s);
                            }).Schedule(2s, [this](TaskContext avengersShield)
                            {
                                DoCastVictim(SPELL_TWISTED_VISAGE_AVENGER__S_SHIELD);
                                avengersShield.Repeat(5s, 10s);
                            });
                            break;
                        default:
                        case ChrSpecialization::PaladinRetribution:
                            _scheduler.Schedule(5s, [this](TaskContext consecration)
                            {
                                DoCastSelf(SPELL_TWISTED_VISAGE_CONSECRATION);
                                consecration.Repeat(5s, 10s);
                            }).Schedule(2s, [this](TaskContext /*sealCommand*/)
                            {
                                DoCastSelf(SPELL_TWISTED_VISAGE_SEAL_OF_COMMAND);
                            }).Schedule(3s, [this](TaskContext judgementLight)
                            {
                                DoCastVictim(SPELL_TWISTED_VISAGE_JUDGEMENT_OF_LIGHT);
                                judgementLight.Repeat(3s, 5s);
                            });
                            break;
                    }
                    break;
                case CLASS_HUNTER:
                    _scheduler.Schedule(2s, [this](TaskContext shoot)
                    {
                        DoCastVictim(SPELL_TWISTED_VISAGE_SHOOT);
                        shoot.Repeat(1s, 4s);
                    }).Schedule(5s, [this](TaskContext disengage)
                    {
                        if (me->IsWithinCombatRange(me->GetVictim(), 4.0f))
                        {
                            DoCastVictim(SPELL_TWISTED_VISAGE_DISENGAGE);
                            disengage.Repeat(10s, 20s);
                        }
                        else
                            disengage.Repeat(1s);
                    });
                    break;
                case CLASS_ROGUE:
                    me->SetCanDualWield(true);
                    _scheduler.Schedule(5s, [this](TaskContext eviscerate)
                    {
                        DoCastVictim(SPELL_TWISTED_VISAGE_EVISCERATE);
                        eviscerate.Repeat(5s, 10s);
                    }).Schedule(2s, [this](TaskContext sinisterStrike)
                    {
                        DoCastVictim(SPELL_TWISTED_VISAGE_SINISTER_STRIKE);
                        sinisterStrike.Repeat(3s, 5s);
                    });
                    break;
                case CLASS_PRIEST:
                    switch (ChrSpecialization(data))
                    {
                        case ChrSpecialization::PriestShadow:
                            _scheduler.Schedule(5s, [this](TaskContext shadowWordPain)
                            {
                                DoCastVictim(SPELL_TWISTED_VISAGE_SHADOW_WORD_PAIN);
                                shadowWordPain.Repeat(5s, 10s);
                            }).Schedule(2s, [this](TaskContext mindFlay)
                            {
                                DoCastVictim(SPELL_TWISTED_VISAGE_MIND_FLAY);
                                mindFlay.Repeat(3s, 5s);
                            });
                            break;
                        default:
                            _scheduler.Schedule(2s, [this](TaskContext renew)
                            {
                                if (Unit* target = DoSelectLowestHpFriendly(40.f))
                                {
                                    DoCast(target, SPELL_TWISTED_VISAGE_RENEW);
                                    renew.Repeat(2s, 5s);
                                }
                                else
                                    renew.Repeat(1s);
                            }).Schedule(4s, [this](TaskContext greaterHeal)
                            {
                                if (Unit* target = DoSelectLowestHpFriendly(40.f))
                                {
                                    DoCast(target, SPELL_TWISTED_VISAGE_GREATER_HEAL);
                                    greaterHeal.Repeat(4s, 6s);
                                }
                                else
                                    greaterHeal.Repeat(1s);
                            });
                            break;
                    }
                    break;
                case CLASS_DEATH_KNIGHT:
                    _scheduler.Schedule(5s, [this](TaskContext deathGrip)
                    {
                        if (!me->IsWithinCombatRange(me->GetVictim(), 3.0f))
                        {
                            DoCastVictim(SPELL_TWISTED_VISAGE_DEATH_GRIP);
                            deathGrip.Repeat(12s);
                        }
                        else
                            deathGrip.Repeat(1s);
                    }).Schedule(2s, [this](TaskContext plagueStrike)
                    {
                        DoCastVictim(SPELL_TWISTED_VISAGE_PLAGUE_STRIKE);
                        plagueStrike.Repeat(3s, 5s);
                    });
                    break;
                case CLASS_SHAMAN:
                    switch (ChrSpecialization(data))
                    {
                        default:
                        case ChrSpecialization::ShamanElemental:
                            _scheduler.Schedule(5s, [this](TaskContext thunderstorm)
                            {
                                DoCastSelf(SPELL_TWISTED_VISAGE_THUNDERSTORM);
                                thunderstorm.Repeat(5s, 10s);
                            }).Schedule(2s, [this](TaskContext lightningBolt)
                            {
                                DoCastVictim(SPELL_TWISTED_VISAGE_LIGHTNING_BOLT);
                                lightningBolt.Repeat(3s, 5s);
                            });
                            break;
                        case ChrSpecialization::ShamanEnhancement:
                            _scheduler.Schedule(2s, [this](TaskContext earthShock)
                            {
                                DoCastVictim(SPELL_TWISTED_VISAGE_EARTH_SHOCK);
                                earthShock.Repeat(3s, 5s);
                            });
                            break;
                        case ChrSpecialization::ShamanRestoration:
                            _scheduler.Schedule(2s, [this](TaskContext earthShield)
                            {
                                if (Unit* target = DoSelectLowestHpFriendly(40.f))
                                {
                                    DoCast(target, SPELL_TWISTED_VISAGE_EARTH_SHIELD);
                                    earthShield.Repeat(4s, 6s);
                                }
                                else
                                    earthShield.Repeat(1s);
                            }).Schedule(4s, [this](TaskContext healingWave)
                            {
                                if (Unit* target = DoSelectLowestHpFriendly(40.f))
                                {
                                    DoCast(target, SPELL_TWISTED_VISAGE_HEALING_WEAVE);
                                    healingWave.Repeat(4s, 6s);
                                }
                                else
                                    healingWave.Repeat(1s);
                            });
                            break;
                    }
                    break;
                case CLASS_MAGE:
                    _scheduler.Schedule(5s, [this](TaskContext frostNova)
                    {
                        DoCastSelf(SPELL_TWISTED_VISAGE_FROST_NOVA);
                        frostNova.Repeat(5s, 10s);
                    }).Schedule(2s, [this](TaskContext fireball)
                    {
                        DoCastVictim(SPELL_TWISTED_VISAGE_FIREBALL);
                        fireball.Repeat(3s, 5s);
                    });
                    break;
                case CLASS_WARLOCK:
                    _scheduler.Schedule(2s, [this](TaskContext corruption)
                    {
                        DoCastVictim(SPELL_TWISTED_VISAGE_CORRUPTION);
                        corruption.Repeat(6s, 10s);
                    }).Schedule(3s, [this](TaskContext shadowBolt)
                    {
                        DoCastVictim(SPELL_TWISTED_VISAGE_SHADOW_BOLT);
                        shadowBolt.Repeat(3s, 5s);
                    });
                    break;
                case CLASS_DRUID:
                    switch (ChrSpecialization(data))
                    {
                        case ChrSpecialization::DruidBalance:
                            _scheduler.Schedule(2s, [this](TaskContext moonfire)
                            {
                                DoCastVictim(SPELL_TWISTED_VISAGE_MOONFIRE);
                                moonfire.Repeat(3s, 5s);
                            }).Schedule(3s, [this](TaskContext wrath)
                            {
                                DoCastVictim(SPELL_TWISTED_VISAGE_WRATH);
                                wrath.Repeat(3s, 5s);
                            });
                            break;
                        case ChrSpecialization::DruidGuardian:
                        case ChrSpecialization::DruidFeral:
                            _scheduler.Schedule(1ms, [this](TaskContext /*catForm*/)
                            {
                                DoCastSelf(SPELL_TWISTED_VISAGE_CAT_FORM);
                            }).Schedule(2s, [this](TaskContext mangle)
                            {
                                DoCastVictim(SPELL_TWISTED_VISAGE_MANGLE);
                                mangle.Repeat(3s, 5s);
                            }).Schedule(3s, [this](TaskContext rip)
                            {
                                DoCastVictim(SPELL_TWISTED_VISAGE_RIP);
                                rip.Repeat(3s, 5s);
                            });
                            break;
                        default:
                        case ChrSpecialization::DruidRestoration:
                            _scheduler.Schedule(2s, [this](TaskContext lifebloom)
                            {
                                if (Unit* target = DoSelectLowestHpFriendly(40.f))
                                {
                                    DoCast(target, SPELL_TWISTED_VISAGE_LIFEBLOOM);
                                    lifebloom.Repeat(4s, 6s);
                                }
                                else
                                    lifebloom.Repeat(1s);
                            }).Schedule(4s, [this](TaskContext nourish)
                            {
                                if (Unit* target = DoSelectLowestHpFriendly(40.f))
                                {
                                    DoCast(target, SPELL_TWISTED_VISAGE_NOURISH);
                                    nourish.Repeat(4s, 6s);
                                }
                                else
                                    nourish.Repeat(1s);
                            });
                            break;
                    }
                    break;
                default:
                    break;
            }
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        DoCastSelf(SPELL_TWISTED_VISAGE_DEATH, true);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
    uint32 _playerClass;
    uint32 _playerSpec;
};

/* 60291 - Volazj Whisper: Aggro
   60292 - Volazj Whisper: Insanity
   60293 - Volazj Whisper: Slay 01
   60294 - Volazj Whisper: Slay 02
   60295 - Volazj Whisper: Slay 03
   60296 - Volazj Whisper: Death 01
   60297 - Volazj Whisper: Death 02 */
class spell_volazj_whisper : public SpellScript
{
    void HandleScriptEffect(SpellEffIndex /* effIndex */)
    {
        Player* target = GetHitPlayer();
        Creature* caster = GetCaster()->ToCreature();
        if (!target || !caster)
            return;

        uint32 text = 0;
        switch (GetSpellInfo()->Id)
        {
            case SPELL_WHISPER_AGGRO:    text = WHISPER_AGGRO;    break;
            case SPELL_WHISPER_INSANITY: text = WHISPER_INSANITY; break;
            case SPELL_WHISPER_SLAY_1:   text = WHISPER_SLAY_1;   break;
            case SPELL_WHISPER_SLAY_2:   text = WHISPER_SLAY_2;   break;
            case SPELL_WHISPER_SLAY_3:   text = WHISPER_SLAY_3;   break;
            case SPELL_WHISPER_DEATH_1:  text = WHISPER_DEATH_1;  break;
            case SPELL_WHISPER_DEATH_2:  text = WHISPER_DEATH_2;  break;
            default: return;
        }
        caster->AI()->Talk(text, target);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_volazj_whisper::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

void AddSC_boss_volazj()
{
    RegisterAhnKahetCreatureAI(boss_volazj);
    RegisterAhnKahetCreatureAI(npc_twisted_visage);
    RegisterSpellScript(spell_volazj_whisper);
}
