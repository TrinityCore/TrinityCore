/*
 * Copyright (C) 2017-2019 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2016 Firestorm Servers <https://firestorm-servers.com>
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

#include "Creature.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "SpellScript.h"
#include "ScriptMgr.h"
#include "TemporarySummon.h"
#include "Vehicle.h"

enum eBosses
{
    BOSS_GALION
};

enum eSpells
{
    SPELL_FIRE_SHOT     = 121673,
    SPELL_STOMP         = 121787,

    SPELL_CANON_1       = 121577,
    SPELL_CANON_2       = 121605,
    SPELL_CANON_3       = 121607,
    SPELL_CANON_4       = 121608,
    SPELL_CANON_5       = 121609,
    SPELL_CANON_6       = 121610,
    SPELL_CANON_7       = 121611,
    SPELL_CANON_8       = 121613,
    SPELL_CANON_DMG     = 121600,

    SPELL_IMPALING_PULL = 121747,
    SPELL_GRIP_TARGET   = 75686,

    SPELL_GALLEON_BONUS = 132206
};

uint32 const CanonSpells[8] = { SPELL_CANON_1, SPELL_CANON_2, SPELL_CANON_3, SPELL_CANON_4, SPELL_CANON_5, SPELL_CANON_6, SPELL_CANON_7, SPELL_CANON_8 };

enum eEvents
{
    EVENT_FIRE_SHOT = 1,
    EVENT_WARN_STOMP,
    EVENT_STOMP,
    EVENT_CANON_BARRAGE,
    EVENT_WARMONGER,
    EVENT_IMPALING_PULL
};

enum eCreatures
{
    NPC_GALLEON             = 62351,
    NPC_GALLEON_CANON       = 62355,
    NPC_SALYIN_WARMONGER    = 62351,
    NPC_CHIEF_SALYIS        = 62352     // Seat ID: 2
};

enum eSays
{
    TALK_SPAWN,     // Chief Salyis yells: Loot and pillage, bwahahaha!
    TALK_AGGRO,     // Chief Salyis yells: Bring me their corpses!
    TALK_CANON,     // Chief Salyis yells: Arm the cannons! Ready! Aim! FIRE!
    TALK_SLAY,      // Chief Salyis yells: They are soft, weak!
    TALK_DEATH      // Chief Salyis yells: Retreat to the hills!
};

enum eActions
{
    ACTION_TALK_INTRO
};

// Galleon - 62346
class boss_galion : public CreatureScript
{
    public:
        boss_galion() : CreatureScript("boss_galion") { }

        struct boss_galion_AI : public BossAI
        {
            boss_galion_AI(Creature* p_Creature) : BossAI(p_Creature, BOSS_GALION)
            {
                ASSERT(me->GetVehicleKit());
            }

            EventMap m_Events;
            uint32 m_CheckVehicleTimer;
            uint8 m_CanonReady;
            std::list<ObjectGuid> m_LootersGuids;

            void CheckVehicleAccessories()
            {
                Unit* l_ChiefSalyis = me->GetVehicleKit()->GetPassenger(2);
                Position l_Pos = me->GetPosition();

                if (!l_ChiefSalyis)
                    l_ChiefSalyis = me->SummonCreature(NPC_CHIEF_SALYIS, l_Pos);

                l_ChiefSalyis->EnterVehicle(me, 2);
                l_ChiefSalyis->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                l_ChiefSalyis->ToCreature()->AI()->DoAction(ACTION_TALK_INTRO);

                std::list<Creature*> l_Canons;
                me->GetCreatureListWithEntryInGrid(l_Canons, NPC_GALLEON_CANON, 100.0f);
                if (l_Canons.size() != 2)
                {
                    for (Creature* l_Canon : l_Canons)
                        summons.Despawn(l_Canon);

                    for (uint8 l_Index = 0; l_Index < 2; ++l_Index)
                    {
                        if (TempSummon* l_NewCanon = me->SummonCreature(NPC_GALLEON_CANON, l_Pos))
                        {
                            l_NewCanon->EnterVehicle(me, l_Index);
                            l_NewCanon->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                            l_NewCanon->SetReactState(REACT_PASSIVE);
                        }
                    }
                }

                std::list<Creature*> l_Warmongers;
                me->GetCreatureListWithEntryInGrid(l_Warmongers, NPC_SALYIN_WARMONGER, 200.0f);
                if (l_Warmongers.size() != 2)
                {
                    for (Creature* l_Warmonger : l_Warmongers)
                        summons.Despawn(l_Warmonger);

                    for (uint8 l_Index = 3; l_Index < 7; ++l_Index)
                    {
                        if (TempSummon* l_Warmonger = me->SummonCreature(NPC_SALYIN_WARMONGER, l_Pos))
                        {
                            l_Warmonger->EnterVehicle(me, l_Index);
                            l_Warmonger->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                        }
                    }
                }
            }

            void Reset() override
            {
                m_Events.Reset();

                _Reset();

                summons.DespawnAll();

                m_CheckVehicleTimer = 2000;
                m_CanonReady        = 0;

                m_LootersGuids.clear();
            }

            void JustSummoned(Creature* p_Summon) override
            {
                summons.Summon(p_Summon);
                p_Summon->setActive(true);
            }

            void JustDied(Unit* /*killer*/) override
            {
                if (Unit* l_ChiefSalyis = me->GetVehicleKit()->GetPassenger(2))
                    l_ChiefSalyis->ToCreature()->AI()->Talk(TALK_DEATH);

                summons.DespawnAll();

                for (ObjectGuid l_Guid : m_LootersGuids)
                {
                    if (Player* l_Player = ObjectAccessor::GetPlayer(*me, l_Guid))
                        me->CastSpell(l_Player, SPELL_GALLEON_BONUS, true);
                }
            }

            void KilledUnit(Unit* killer) override
            {
                if (killer->ToPlayer())
                {
                    if (Unit* l_ChiefSalyis = me->GetVehicleKit()->GetPassenger(2))
                        l_ChiefSalyis->ToCreature()->AI()->Talk(TALK_SLAY);
                }
            }

            void EnterCombat(Unit* attacker) override
            {
                m_Events.ScheduleEvent(EVENT_WARN_STOMP, 47000);
                m_Events.ScheduleEvent(EVENT_STOMP, 50000);
                m_Events.ScheduleEvent(EVENT_CANON_BARRAGE, 24000);

                if (Unit* l_ChiefSalyis = me->GetVehicleKit()->GetPassenger(2))
                    l_ChiefSalyis->ToCreature()->AI()->Talk(TALK_AGGRO);

                for (uint8 l_Index = 3; l_Index < 7; ++l_Index)
                {
                    if (Unit* l_Warmonger = me->GetVehicleKit()->GetPassenger(l_Index))
                        l_Warmonger->ToCreature()->AI()->AttackStart(attacker);
                }
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage) override
            {
                if (damage >= me->GetHealth())
                {
                    for (auto hostileReference : me->GetThreatManager().getThreatList())
                        if (Player* l_Player = ObjectAccessor::GetPlayer(*me, hostileReference->getUnitGuid()))
                            m_LootersGuids.push_back(l_Player->GetGUID());
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (m_CheckVehicleTimer)
                {
                    if (m_CheckVehicleTimer <= diff)
                    {
                        CheckVehicleAccessories();
                        m_CheckVehicleTimer = 0;
                    }
                    else
                        m_CheckVehicleTimer -= diff;
                }

                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                m_Events.Update(diff);

                switch (m_Events.ExecuteEvent())
                {
                    case EVENT_WARN_STOMP:
                        //me->TextEmote("Galleon is about to |cFFFF0000|Hspell:121787|h[Stomp]|h|r !", 0, true);
                        break;
                    case EVENT_STOMP:
                        me->CastSpell(me, SPELL_STOMP, false);
                        m_Events.ScheduleEvent(EVENT_WARN_STOMP, 57000);
                        m_Events.ScheduleEvent(EVENT_STOMP, 60000);
                        m_Events.ScheduleEvent(EVENT_WARMONGER, 10000);
                        break;
                    case EVENT_CANON_BARRAGE:
                    {
                        if (!m_CanonReady)
                        {
                            //me->TextEmote("Galleon prepares to unleash |cFFFF0000|Hspell:121600|h[Canon Barrage]|h|r !", 0, true);

                            if (Unit* l_ChiefSalyis = me->GetVehicleKit()->GetPassenger(2))
                                l_ChiefSalyis->ToCreature()->AI()->Talk(TALK_CANON);
                        }

                        if (m_CanonReady % 2)
                        {
                            if (Unit* l_Canon = me->GetVehicleKit()->GetPassenger(0))
                                l_Canon->CastSpell(l_Canon, CanonSpells[m_CanonReady], true);
                        }
                        else
                        {
                            if (Unit* l_Canon = me->GetVehicleKit()->GetPassenger(1))
                                l_Canon->CastSpell(l_Canon, CanonSpells[m_CanonReady], true);
                        }

                        ++m_CanonReady;

                        if (m_CanonReady < 8)
                            m_Events.ScheduleEvent(EVENT_CANON_BARRAGE, 1000);
                        else
                        {
                            m_CanonReady = 0;
                            m_Events.ScheduleEvent(EVENT_CANON_BARRAGE, 52000);
                        }

                        break;
                    }
                    case EVENT_WARMONGER:
                    {
                        for (uint8 l_Index = 0; l_Index < 6; ++l_Index)
                            me->SummonCreature(NPC_SALYIN_WARMONGER, me->GetPosition());

                        break;
                    }
                    default:
                        break;
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* p_Creature) const override
        {
            return new boss_galion_AI(p_Creature);
        }
};

// Chief Salyis - 62352
class npc_chief_salyis : public CreatureScript
{
    public:
        npc_chief_salyis() : CreatureScript("npc_chief_salyis") { }

        struct npc_chief_salyisAI : public ScriptedAI
        {
            npc_chief_salyisAI(Creature* p_Creature) : ScriptedAI(p_Creature) { }

            bool m_IntroDone;

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                m_IntroDone = false;
            }

            void DoAction(int32 const action) override
            {
                if (action == ACTION_TALK_INTRO && !m_IntroDone)
                {
                    m_IntroDone = true;
                    Talk(TALK_SPAWN);
                }
            }

            void UpdateAI(uint32 /*diff*/) override {}
        };

        CreatureAI* GetAI(Creature* p_Creature) const override
        {
            return new npc_chief_salyisAI(p_Creature);
        }
};

// Salyin Warmonger - 62351
class npc_salyin_warmonger : public CreatureScript
{
    public:
        npc_salyin_warmonger() : CreatureScript("npc_salyin_warmonger") { }

        struct npc_salyin_warmongerAI : public ScriptedAI
        {
            npc_salyin_warmongerAI(Creature* p_Creature) : ScriptedAI(p_Creature) { }

            EventMap m_Events;
            bool m_IsInCombat;

            void Reset() override
            {
                m_Events.Reset();

                m_IsInCombat = false;
            }

            void EnterCombat(Unit* /*attacker*/) override
            {
                if (me->IsOnVehicle())
                    m_Events.ScheduleEvent(EVENT_FIRE_SHOT, urand(5000, 10000));
                else
                    m_Events.ScheduleEvent(EVENT_IMPALING_PULL, 20000);

                m_IsInCombat = true;
            }

            void UpdateAI(uint32 diff) override
            {
                if (!m_IsInCombat)
                    return;

                if (!UpdateVictim() && !me->IsOnVehicle())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING) && !me->IsOnVehicle())
                    return;

                m_Events.Update(diff);

                switch (m_Events.ExecuteEvent())
                {
                    case EVENT_FIRE_SHOT:
                        me->CastSpell(me, SPELL_FIRE_SHOT, false);
                        m_Events.ScheduleEvent(EVENT_FIRE_SHOT, urand(5000, 10000));
                        break;
                    case EVENT_IMPALING_PULL:
                        if (Unit* l_Target = SelectTarget(SELECT_TARGET_RANDOM))
                            me->CastSpell(l_Target, SPELL_IMPALING_PULL, false);
                        m_Events.ScheduleEvent(EVENT_IMPALING_PULL, 20000);
                        break;
                    default:
                        break;
                }

                if (!me->IsOnVehicle())
                    DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* p_Creature) const override
        {
            return new npc_salyin_warmongerAI(p_Creature);
        }
};

// Impaling Pull - 121754
class spell_impaling_pull: public SpellScriptLoader
{
    public:
        spell_impaling_pull() : SpellScriptLoader("spell_impaling_pull") { }

        class spell_impaling_pull_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_impaling_pull_SpellScript);

            void HandleDummy(SpellEffIndex /*p_EffIndex*/)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                GetHitUnit()->CastSpell(GetCaster(), SPELL_GRIP_TARGET, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_impaling_pull_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_impaling_pull_SpellScript();
        }
};

void AddSC_boss_galion()
{
    new boss_galion();
    new npc_salyin_warmonger();
    new spell_impaling_pull();
}
