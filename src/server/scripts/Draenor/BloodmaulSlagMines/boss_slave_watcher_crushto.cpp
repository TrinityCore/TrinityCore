/*
* Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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

#include "instance_bloodmaul.h"

namespace Instances
{
    namespace Bloodmaul
    {
        /// Slave Watcher Crushto <Bloodmaul Slave Traders> - 74787
        class boss_SlaveWatcherCrushto : public CreatureScript
        {
            public:
                boss_SlaveWatcherCrushto() : CreatureScript("boss_SlaveWatcherCrushto") { }

                enum class Spells : uint32
                {
                    EarthCrush          = 153735,   ///< Summon.
                    EarthCrush2         = 153732,   ///< Useless, no visual.
                    EarthCrush3         = 153679,   ///< Visual foot kick in the rock.
                    EarthCrush4         = 167246,
                    FerociousYell       = 150759,
                    RaiseTheMiners      = 150801,
                    WildSlam            = 150753,
                    CrushingLeap        = 150746,   ///< Jump
                    CrushingLeap2       = 150745,   ///< Dummy
                    CrushingLeap3       = 150751,   ///< Effect.
                    SlayerOfTheSlayer   = 163577,   ///< Apply when boss dies.
                    Fear                = 38154,
                    WeakenedWill        = 150811
                };

                enum class Events : uint32
                {
                    EarthCrush      = 1,
                    FerociousYell   = 2,
                    RaiseTheMiners  = 3,
                    WildSlam        = 4,
                    CrushingLeap    = 5
                };

                enum eTalks
                {
                    TalkAggro = 1,
                    TalkMiner,
                    TalkFerociousYell,
                    TalkSlay,
                    TalkDeath
                };

                CreatureAI* GetAI(Creature* creature) const override
                {
                    return new boss_AI(creature);
                }

                struct boss_AI : public BossAI
                {
                    boss_AI(Creature* creature) : BossAI(creature, BossIds::BossSlaveWatcherCrushto),
                    m_LastEarthCrushStalkerPosition()
                    {
                        if (instance)
                            instance->SetBossState(BossIds::BossSlaveWatcherCrushto, EncounterState::TO_BE_DECIDED);
                    }

                    void Reset() override
                    {
                        _Reset();
                    }

                    void JustReachedHome() override
                    {
                        _JustReachedHome();

                        if (instance)
                        {
                            instance->SetBossState(BossIds::BossSlaveWatcherCrushto, FAIL);
                            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                        }
                    }

                    void JustDied(Unit*) override
                    {
                        _JustDied();

                        Talk(eTalks::TalkDeath);

                        if (instance)
                            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                    }

                    void KilledUnit(Unit* p_Who) override
                    {
                        if (p_Who->GetTypeId() == TypeID::TYPEID_PLAYER)
                            Talk(eTalks::TalkSlay);
                    }

                    void EnterCombat(Unit*) override
                    {
                        _EnterCombat();

                        Talk(eTalks::TalkAggro);

                        events.ScheduleEvent(uint32(Events::EarthCrush), 5000);
                        events.ScheduleEvent(uint32(Events::FerociousYell), 10000);
                        events.ScheduleEvent(uint32(Events::RaiseTheMiners), 16000);
                        events.ScheduleEvent(uint32(Events::CrushingLeap), 23000);
                        events.ScheduleEvent(uint32(Events::WildSlam), 27000);

                        if (instance)
                            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                    }

                    void MovementInform(uint32 p_Type, uint32 p_Id) override
                    {
                        switch (p_Type)
                        {
                            case EFFECT_MOTION_TYPE:
                                if (Player* l_Plr = ObjectAccessor::FindPlayer(m_TargetGUID))
                                {
                                    me->CastSpell(l_Plr, uint32(Spells::CrushingLeap3));
                                    m_TargetGUID = ObjectGuid::Empty;
                                    if (instance)
                                        instance->SetGuidData(uint32(Data::RaiseTheMinersChangeTarget), l_Plr->GetGUID());
                                }
                                break;
                        }
                    }

                    void SpellHitTarget(Unit* p_Target, SpellInfo const* p_SpellInfo) override
                    {
                        if (p_Target == nullptr)
                            return;

                        /// Handling Earth Crush damages.
                        if (p_SpellInfo->Id == uint32(Spells::EarthCrush3) && p_Target->GetEntry() == uint32(MobEntries::EarthCrushStalker))
                        {
                            /*MS::ScriptUtils::ApplyOnEveryPlayer(me, [&](Unit* p_Me, Player* p_Plr)
                            {
                                /// We check if players are in not behind the boss and if they are in the line.
                                if (p_Me->isInFront(p_Plr) && DistanceFromLine(*p_Me, m_LastEarthCrushStalkerPosition, *p_Plr) < 2.0f && p_Me->GetExactDist2d(p_Plr) < 40.0f)
                                    p_Me->CastSpell(p_Plr, uint32(Spells::EarthCrush3), true);
                            });*/
                        }

                        /// Handling fear after Ferocious Yell.
                        if (p_SpellInfo->Id == uint32(Spells::FerociousYell))
                        {
                            if (p_Target->GetAuraCount(uint32(Spells::WeakenedWill)) == 3)
                            {
                                p_Target->RemoveAura(uint32(Spells::WeakenedWill));
                                me->AddAura(uint32(Spells::Fear), p_Target);
                            }
                            else
                            {
                                if (Unit* l_Target = me->GetVictim())
                                    p_Target->AddThreat(l_Target, 10000.0f);
                            }
                        }
                    }

                    void UpdateAI(const uint32 p_Diff) override
                    {
                        if (!UpdateVictim())
                            return;

                        events.Update(p_Diff);

                        if (me->HasUnitState(UNIT_STATE_CASTING))
                            return;

                        switch (events.ExecuteEvent())
                        {
                            case uint32(Events::EarthCrush):
                            {
                                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 40.0f))
                                {
                                    Position l_SummonPos;
                                    GetPositionWithDistInOrientation(me, 4.0f, me->GetAngle(target), l_SummonPos);
                                    m_LastEarthCrushStalkerPosition = l_SummonPos;

                                    /// We summon the rock.
                                    TempSummon* l_Summon = me->SummonCreature(uint32(MobEntries::EarthCrushStalker), l_SummonPos, TempSummonType::TEMPSUMMON_TIMED_DESPAWN, 4000);
                                    if (l_Summon != nullptr)
                                    {
                                        l_Summon->SetFacingToObject(target);
                                        l_Summon->CastSpell(l_Summon, uint32(Spells::EarthCrush4), true);

                                        /// We launch foot kick.
                                        me->SetFacingToObject(target);
                                        me->CastSpell(l_Summon, uint32(Spells::EarthCrush3), false);

                                        l_Summon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                                    }
                                }
                                events.ScheduleEvent(uint32(Events::EarthCrush), urand(20000, 25000));
                                break;
                            }
                            case uint32(Events::FerociousYell):
                            {
                                Talk(eTalks::TalkFerociousYell);
                                me->CastSpell(me, uint32(Spells::FerociousYell));
                                events.ScheduleEvent(uint32(Events::FerociousYell), urand(10000, 12000));
                                break;
                            }
                            case uint32(Events::RaiseTheMiners):
                            {
                                Talk(eTalks::TalkMiner);
                                me->CastSpell(me, uint32(Spells::RaiseTheMiners));
                                events.ScheduleEvent(uint32(Events::RaiseTheMiners), urand(25000, 29000));
                                break;
                            }
                            case uint32(Events::WildSlam):
                            {
                                me->CastSpell(me->GetVictim(), uint32(Spells::WildSlam));
                                events.ScheduleEvent(uint32(Events::WildSlam), urand(20000, 27000));
                                break;
                            }
                            case uint32(Events::CrushingLeap):
                            {
                                /*if (Player* l_Plr = MS::ScriptUtils::SelectFarEnoughPlayerIncludedTank(me, 8.0f))
                                {
                                    m_TargetGUID = l_Plr->GetGUID();
                                    me->CastSpell(l_Plr, uint32(Spells::CrushingLeap));
                                }*/
                                events.ScheduleEvent(uint32(Events::CrushingLeap), urand(20000, 23000));
                                break;
                            }
                            default:
                                break;
                        }

                        DoMeleeAttackIfReady();
                    }

                    Position m_LastEarthCrushStalkerPosition;
                    ObjectGuid m_TargetGUID;
                };
        };

        /// Trois mobs de l'event : 74355, 74356,74357
        class mob_crushto_captured_miner : public CreatureScript
        {
        public:
            mob_crushto_captured_miner() : CreatureScript("mob_crushto_captured_miner") { }

            struct mob_AI : public ScriptedAI
            {
                mob_AI(Creature* p_Creature) : ScriptedAI(p_Creature) { }
            };

            CreatureAI* GetAI(Creature* p_Creature) const override
            {
                return new mob_AI(p_Creature);
            }
        };
    }
}

void AddSC_boss_SlaveWatcherCrushto()
{
    new Instances::Bloodmaul::boss_SlaveWatcherCrushto();
    new Instances::Bloodmaul::mob_crushto_captured_miner();
}
