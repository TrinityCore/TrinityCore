/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 *
 * Copyright (C) 2008-2014 Forgotten Lands <http://www.forgottenlands.eu/>
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
SDName: boss_echo_of_baine
SD%Complete:
SDComment:
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "end_time.h"
#include "SpellInfo.h"
#include "GameObject.h"
#include "PassiveAI.h"

enum Spells
{
    SPELL_THROW_TOTEM               = 101615,
    SPELL_PULVERIZE                 = 101625,
    SPELL_DESTROY_PLATFORM          = 101627,
    SPELL_MOLTEN_AXE_CHECK          = 101834,
    SPELL_MOLTEN_AXE                = 101836,

    SPELL_THROW_TOTEM_BACK_AIM      = 101601,
    SPELL_THROW_TOTEM_BACK          = 101603,
    SPELL_MOLTEN_BLAST              = 101840,

    SPELL_MOLTEN_FISTS              = 101866,
    SPELL_MAGMA                     = 101819,



};

enum Events
{
    EVENT_THROW_TOTEM = 1,
    EVENT_PULVERIZE,
    EVENT_DESTROY_PLATFORM
};

enum Misc
{
    NPC_ROCK_ISLAND = 54496
};

class boss_echo_of_baine : public CreatureScript
{
    public:
        boss_echo_of_baine() : CreatureScript("boss_echo_of_baine") { }

        struct boss_echo_of_baineAI : public BossAI
        {
            boss_echo_of_baineAI(Creature* creature) : BossAI(creature, DATA_BAINE), Summons(me)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;
            EventMap events;
            SummonList Summons;

            bool lavaContact;
            uint32 moltenBlastTimer;

            void Reset() override
            {
                lavaContact = false;
                moltenBlastTimer = 1000;

                _Reset();
                events.Reset();

                Summons.DespawnAll();

                std::list<GameObject*> platformList;
                Trinity::GameObjectInRangeCheck check(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 100.0f);
                Trinity::GameObjectListSearcher<Trinity::GameObjectInRangeCheck> searcher(me, platformList, check);
                Cell::VisitGridObjects(me, searcher, 100.0f);
                for (std::list<GameObject*>::const_iterator itr = platformList.begin(); itr != platformList.end(); ++itr)
                {
                    if ((*itr)->GetDestructibleState() == GO_DESTRUCTIBLE_DESTROYED)
                        (*itr)->SetDestructibleState(GO_DESTRUCTIBLE_REBUILDING);
                }
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _EnterCombat();
                me->SetSpeed(MOVE_WALK, 2.0f);
                me->SetSpeed(MOVE_RUN, 2.0f);

                DoZoneInCombat();
                DoCast(me, SPELL_MOLTEN_AXE_CHECK);

                events.ScheduleEvent(EVENT_PULVERIZE, 30000);
                events.ScheduleEvent(EVENT_THROW_TOTEM, 10000);
            }

            void KilledUnit(Unit* /*victim*/) override
            {
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                instance->SetData(DATA_BOSS_COUNT, 1);
            }

            void JustSummoned(Creature* summon) override
            {
                Summons.Summon(summon);
            }

            void UpdateAI(uint32 diff) override

            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_THROW_TOTEM:
                            if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            {
                                Summons.DespawnAll();
                                DoCast(target, SPELL_THROW_TOTEM);
                                events.ScheduleEvent(EVENT_THROW_TOTEM, 25000);
                            }
                            break;
                        case EVENT_PULVERIZE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_FARTHEST, 0))
                            {
                                DoCast(target, SPELL_PULVERIZE);
                                events.ScheduleEvent(EVENT_PULVERIZE, 40000);
                                events.ScheduleEvent(EVENT_DESTROY_PLATFORM, 3000);
                            }
                            break;
                        case EVENT_DESTROY_PLATFORM:
                            me->CastSpell(me, SPELL_DESTROY_PLATFORM, false);
                            break;
                    }
                }

                DoMeleeAttackIfReady();

                if (me->GetDistance(me->GetHomePosition()) > 82.0f)
                    EnterEvadeMode();

                if (GameObject* platform = me->FindNearestGameObjectOfType(GAMEOBJECT_TYPE_DESTRUCTIBLE_BUILDING, 50.0f))
                {
                    if (me->GetPositionZ() < 129.932f || me->GetDistance2d(platform) > 6.0f)
                        lavaContact = true;
                    else
                        lavaContact = false;
                }

                if (lavaContact && !me->HasUnitState(UNIT_STATE_STUNNED))
                {
                    if (moltenBlastTimer < diff)
                    {
                        DoCastVictim(SPELL_MOLTEN_BLAST);
                        moltenBlastTimer = 2500;
                    }
                    else
                        moltenBlastTimer -= diff;
                }

                if (Map* map = me->GetMap())
                {
                    std::list<Player*> PlayerList;
                    Map::PlayerList const& Players = map->GetPlayers();
                    for (Map::PlayerList::const_iterator itr = Players.begin(); itr != Players.end(); ++itr)
                    {
                        if (Player* player = itr->GetSource())
                        {
                            if (player->HasAura(SPELL_MAGMA) && !player->HasAura(SPELL_MOLTEN_FISTS))
                                player->AddAura(SPELL_MOLTEN_FISTS, player);
                        }
                    }
                }


            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_echo_of_baineAI(creature);
        }
};

class DistanceCheck
{
    public:
        explicit DistanceCheck(Unit* _caster) : caster(_caster) { }

        bool operator() (WorldObject* unit) const
        {
            if (caster->GetExactDist2d(unit) <= 20.0f || !unit->ToPlayer())
                return true;
            return false;
        }

        Unit* caster;
};

class spell_pulverize : public SpellScriptLoader
{
    public:
        spell_pulverize() : SpellScriptLoader("spell_pulverize") { }

        class spell_pulverize_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pulverize_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if(Unit* caster = GetCaster())
                {
                    targets.remove_if(DistanceCheck(caster));
                    if (!targets.empty())
                        Trinity::Containers::SelectRandomContainerElement(targets);
                }
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_pulverize_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_pulverize_SpellScript();
        }
};

class npc_baine_totem : public CreatureScript
{
    public:
        npc_baine_totem() : CreatureScript("npc_baine_totem") { }

        struct npc_baine_totemAI : public PassiveAI
        {
            npc_baine_totemAI(Creature* creature) : PassiveAI(creature) { }

            void OnSpellClick(Unit* clicker, bool& /*result*/) override
            {
                if (Creature* baine = GetClosestCreatureWithEntry(me, 54431, 75.0f))
                    clicker->CastSpell(baine, 101603, true);

                me->DespawnOrUnsummon();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_baine_totemAI(creature);
        }
};

void AddSC_boss_echo_of_baine()
{
    new boss_echo_of_baine();
    new spell_pulverize();
    new npc_baine_totem();
}
