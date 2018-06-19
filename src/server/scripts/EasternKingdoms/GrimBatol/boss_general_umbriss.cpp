/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2010-2011 Project Trinity <http://www.projecttrinity.org/>
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
#include "grim_batol.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"

enum Texts
{
    SAY_BOMBING_1,
    SAY_BOMBING_2,
    SAY_SUMMON,
    SAY_KILL_1,
    SAY_KILL_2,
    EMOTE_BLITZ = 6,
    EMOTE_GROUND_SIEGE,
    EMOTE_FRENZY
};

enum Creatures
{
    NPC_UMBRISS         = 39625,
    NPC_MALIGNANT_TROGG = 39984,
    NPC_TROGG_DWELLER   = 45467,
    NPC_TRIGGER_BLITZ = 40040,
};

enum Spells
{
    BLEEDING_WOUND          = 74846,
    BLEEDING_WOUND_H        = 91937,
    GROUND_SIEGE            = 74634,
    GROUND_SIEGE_H          = 90249,

    BLITZ_TRIGGER           = 74668,

    BLITZ                   = 74670,
    BLITZ_H                 = 90250,
    FRENZY                  = 74853,
    //Adds
    CLAW_PUNCTURE           = 76507,
    CLAW_PUNCTURE_H         = 90212,
    MODGUD_MALICE           = 74699,
    MODGUD_MALICE_H         = 90169,
};

struct Locations
{
    float x, y, z, o;
};

static Locations SpawnPosition[]=
{
    {-722.15f, -442.53f, 268.77f, 0.54f},
    {-702.22f, -450.9f, 268.77f, 1.34f}
};

class boss_general_umbriss : public CreatureScript
{
    public:

        boss_general_umbriss() : CreatureScript("boss_general_umbriss")
        {
        }

        struct boss_general_umbrissAI : public ScriptedAI
        {
            boss_general_umbrissAI(Creature *c) : ScriptedAI(c)
            {
                pInstance = c->GetInstanceScript();
            }

            void Reset() override
            {
                woundTimer = 12000;
                groundTimer = 30000;
                blitzTimer = 25000;
                addTimer = 18000;
                groundTimer2 = 300000;
                tempGUID = ObjectGuid::Empty;
                isMalignantSpawn = false;
                enrage = false;
                me->RemoveAurasDueToSpell(DUNGEON_MODE(MODGUD_MALICE,MODGUD_MALICE_H));
                me->RemoveAurasDueToSpell(FRENZY);
                me->AddUnitState(UNIT_STATE_IGNORE_PATHFINDING);
            }

            void EnterCombat(Unit* /*pWho*/) override
            {
                Talk(0);
            }

            void JustDied(Unit* /*pKiller*/) override
            {
                Talk(2);
                if (pInstance)
                {
                    pInstance->SetData(DATA_GENERAL_UMBRISS_EVENT, DONE);
                    if (IsHeroic() && me->HasAura(MODGUD_MALICE_H))
                        pInstance->DoCompleteAchievement(ACHIEV_UMBRAGE_FOR_UMBRISS);
                }
            }

            void KilledUnit(Unit* /*victim*/) override
            {
                Talk(RAND(SAY_KILL_1, SAY_KILL_2));
            }

            void UpdateAI(uint32 uiDiff) override
            {
                if (!UpdateVictim())
                    return;

                if (woundTimer <= uiDiff)
                {
                    DoCastVictim(DUNGEON_MODE(BLEEDING_WOUND,BLEEDING_WOUND_H));
                    woundTimer = 25000;
                }else woundTimer -= uiDiff;

                if (groundTimer <= uiDiff)
                {
                    if (Unit* unit = SelectTarget(SELECT_TARGET_RANDOM, 1))
                    {
                        Position pos = unit->GetPosition();
                        if (Creature* temp = me->SummonCreature(40030, pos, TEMPSUMMON_TIMED_DESPAWN, 5000))
                        {
                            tempGUID = temp->GetGUID();
                            DoCast(me, DUNGEON_MODE(GROUND_SIEGE,GROUND_SIEGE_H));
                            groundTimer2 = 500;
                        }
                    }
                    groundTimer = 30000;
                }else groundTimer -= uiDiff;

                if (groundTimer2 <= uiDiff)
                {
                    if (Creature* temp = ObjectAccessor::GetCreature(*me, tempGUID))
                        me->SetFacingToObject(temp);
                    me->AttackStop();
                    Talk(EMOTE_GROUND_SIEGE);
                    groundTimer2 = 300000;
                }
                else groundTimer2 -= uiDiff;

                if (blitzTimer <= uiDiff)
                {
                    if (Unit* unit = SelectTarget(SELECT_TARGET_RANDOM, 0, NonTankTargetSelector(me)))
                    {
                        Talk(EMOTE_BLITZ, unit);
                        if (Creature *c = me->SummonCreature(NPC_TRIGGER_BLITZ, unit->GetPositionX(), unit->GetPositionY(), unit->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 5000))
                            me->CastSpell(c, DUNGEON_MODE(74670, 90250), false);
                    }
                    blitzTimer = 25000;
                }else blitzTimer -= uiDiff;

                if(!enrage)
                {
                    if(addTimer <= uiDiff)
                    {
                        Talk(SAY_SUMMON);
                        SpawnMalignant();
                        SpawnAdd();
                        addTimer = 60000;

                    } else addTimer -= uiDiff;

                    if (HealthBelowPct(30))
                    {
                        enrage = true;
                        Talk(EMOTE_FRENZY);
                        DoCast(FRENZY);
                    }
                }

                DoMeleeAttackIfReady();
            }

            void SpawnAdd()
            {
                for(int i = 0; i < 3; i ++)
                    SummonCreatureWithRandomTarget(NPC_TROGG_DWELLER, SpawnPosition[0].x,SpawnPosition[0].y,SpawnPosition[0].z,SpawnPosition[0].o);
            }

            void SpawnMalignant()
            {
                if (!isMalignantSpawn && !enrage)
                {
                    SummonCreatureWithRandomTarget(NPC_MALIGNANT_TROGG, SpawnPosition[1].x,SpawnPosition[1].y,SpawnPosition[1].z,SpawnPosition[1].o);
                    isMalignantSpawn = true;
                }
            }

            void SummonCreatureWithRandomTarget(uint32 creatureId, float x, float y, float z, float o)
            {
                Creature* Summoned = me->SummonCreature(creatureId, x, y, z, o, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 5000);
                if (Summoned)
                {
                    Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                    if (pTarget)
                    {
                        Summoned->AddThreat(pTarget, 1.0f);
                        Summoned->AI()->AttackStart(pTarget);
                    }
                }
            }


            bool isMalignantSpawn;
        private :
            uint32 blitzTimer;
            uint32 groundTimer;
            uint32 groundTimer2;
            uint32 woundTimer;
            uint32 addTimer;
            bool enrage;
            ObjectGuid tempGUID;
            InstanceScript* pInstance;
        };

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new boss_general_umbrissAI(pCreature);
        }
};

class npc_malignant : public CreatureScript
{
    public:

        npc_malignant() : CreatureScript("npc_malignant")
        {
        }

        struct npc_malignantAI : public ScriptedAI
        {
            npc_malignantAI(Creature *c) : ScriptedAI(c)
            {
                me->AddAura(DUNGEON_MODE(MODGUD_MALICE,MODGUD_MALICE_H), me);
                die = false;
            }

            bool die;

            void DamageTaken(Unit* /*done_by*/, uint32& damage) override
            {
                if(die)
                {
                    damage = 0;
                    return;
                }

                if(damage >= me->GetHealth())
                {
                    die = true;
                    damage = 0;
                    if(Creature* umbriss = me->FindNearestCreature(NPC_UMBRISS,100.0f))
                    {
                        std::list<Creature*> troggList;
                        GetCreatureListWithEntryInGrid(troggList, me, NPC_TROGG_DWELLER, 8.0f);

                        if (!troggList.empty())
                        {
                            for (std::list<Creature*>::const_iterator itr = troggList.begin(); itr != troggList.end(); ++itr)
                            {
                                if (Creature* trog = *itr)
                                {
                                    CAST_AI(boss_general_umbriss::boss_general_umbrissAI, umbriss->AI())->SummonCreatureWithRandomTarget(NPC_MALIGNANT_TROGG, trog->GetPositionX(), trog->GetPositionY(), trog->GetPositionZ(), 0);
                                    trog->DespawnOrUnsummon();
                                }
                            }
                        }

                        if (me->GetDistance2d(umbriss->GetPositionX(), umbriss->GetPositionY()) < 8.0f)
                            me->AddAura(DUNGEON_MODE(MODGUD_MALICE,MODGUD_MALICE_H), umbriss);

                        CAST_AI(boss_general_umbriss::boss_general_umbrissAI, umbriss->AI())->isMalignantSpawn = false;
                        CAST_AI(boss_general_umbriss::boss_general_umbrissAI, umbriss->AI())->SpawnMalignant();
                    }

                    me->DespawnOrUnsummon();
                }
            }

            void UpdateAI(uint32 /*uiDiff*/) override
            {
                if (!UpdateVictim())
                    return;

                DoSpellAttackIfReady(DUNGEON_MODE(CLAW_PUNCTURE,CLAW_PUNCTURE_H));
            }
        };

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_malignantAI(pCreature);
        }
};

class npc_trogg_dweller : public CreatureScript
{
    public:

        npc_trogg_dweller() : CreatureScript("npc_trogg_dweller")
        {
        }

        struct npc_trogg_dwellerAI : public ScriptedAI
        {
            npc_trogg_dwellerAI(Creature *c) : ScriptedAI(c) {}

            void UpdateAI(uint32 /*uiDiff*/) override
            {
                if (!UpdateVictim())
                    return;

                DoSpellAttackIfReady(DUNGEON_MODE(CLAW_PUNCTURE,CLAW_PUNCTURE_H));
            }
        };

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_trogg_dwellerAI(pCreature);
        }
};

class spell_bleeding_wound : public SpellScriptLoader
{
public:
    spell_bleeding_wound() : SpellScriptLoader("spell_bleeding_wound") { }

    class spell_bleeding_wound_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_bleeding_wound_AuraScript);

        void HandlePeriodic(AuraEffect const* /*aurEff*/)
        {
            if (GetUnitOwner()->HealthAbovePct(90))
            {
                PreventDefaultAction();
                Remove(AURA_REMOVE_BY_ENEMY_SPELL);
            }
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_bleeding_wound_AuraScript::HandlePeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DAMAGE);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_bleeding_wound_AuraScript();
    }
};

class spell_ground_siege : public SpellScriptLoader
{
public:
    spell_ground_siege() : SpellScriptLoader("spell_ground_siege") { }

    class spell_ground_siege_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_ground_siege_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return false;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_ground_siege_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_ground_siege_SpellScript();
    }
};

void AddSC_boss_general_umbriss()
{
    new boss_general_umbriss();
    new npc_malignant();
    new npc_trogg_dweller();
    new spell_bleeding_wound();
    new spell_ground_siege();
}
