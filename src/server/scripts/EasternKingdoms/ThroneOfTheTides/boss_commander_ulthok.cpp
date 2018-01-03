/*
 * Copyright (C) 2011-2012 Project SkyFire <http://www.projectskyfire.org/>
* Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
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
#include "throne_of_the_tides.h"
#include "SpellAuras.h"
#include "SpellScript.h"

enum eUlthokYells
{
    SAY_AGGRO                   = 0,
    SAY_AGGRO_WHISP             = 1,
    SAY_DEATH                   = 2,
    SAY_DEATH_WHISP             = 3,
};

enum eUlthokSpells
{
    SPELL_CURSE_OF_FATIGUE      = 76094,
    // Normal
    SPELL_DARK_FISSURE          = 76047,
    SPELL_ENRAGE                = 76100,
    SPELL_SQUEEZE               = 76026,
    // Heroic
    SPELL_SQUEEZE_H             = 91484,
    SPELL_DARK_FISSURE_H        = 96311,
    // Needs implementation
    SPELL_SQUEEZE_VEHICLE       = 76038,
};

class boss_commander_ulthok : public CreatureScript
{
public:
    boss_commander_ulthok() : CreatureScript("boss_commander_ulthok") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_commander_ulthokAI (creature);
    }

    struct boss_commander_ulthokAI : public ScriptedAI
    {
        boss_commander_ulthokAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
            if (instance)
                if (instance->GetData(DATA_LADY_NAZJAR_EVENT) == DONE)
                    return;

            creature->SetVisible(false);
            creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
            creature->SetReactState(REACT_PASSIVE);
        }

        InstanceScript* instance;

        uint32 DarkFissureTimer;
        uint32 CurseOfFatigueTimer;
        uint32 EnrageTimer;
        uint32 SqueezeTimer;

        void Reset() override
        {
            DarkFissureTimer = urand(10000, 15000);
            CurseOfFatigueTimer = urand(10000, 15000);
            EnrageTimer = urand(12000, 18000);
            SqueezeTimer = urand(10000, 15000);

            if (instance)
                instance->SetData(DATA_COMMANDER_ULTHOK_EVENT, NOT_STARTED);

            RespawnVoidZones();
        }

        void JustReachedHome() override
        {
            if (instance)
            {
                instance->HandleGameObject(instance->GetGuidData(GO_LADY_NAZJAR_DOOR), true);
                instance->HandleGameObject(instance->GetGuidData(GO_COMMANDER_ULTHOK_DOOR), true);
            }
        }

        void JustDied(Unit* who) override
        {
            Talk(SAY_DEATH);
            if (who && who->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_DEATH_WHISP);

            RespawnVoidZones();

            if (instance)
            {
                instance->HandleGameObject(instance->GetGuidData(GO_LADY_NAZJAR_DOOR), true);
                instance->HandleGameObject(instance->GetGuidData(GO_COMMANDER_ULTHOK_DOOR), true);
                instance->SetData(DATA_COMMANDER_ULTHOK_EVENT, DONE);
            }
        }

        void EnterCombat(Unit* Ent) override
        {
            Talk(SAY_AGGRO);
            if (Ent && Ent->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_AGGRO_WHISP);

            if (instance)
            {
                instance->HandleGameObject(instance->GetGuidData(GO_LADY_NAZJAR_DOOR), false);
                instance->HandleGameObject(instance->GetGuidData(GO_COMMANDER_ULTHOK_DOOR), false);
                instance->SetData(DATA_COMMANDER_ULTHOK_EVENT, IN_PROGRESS);
            }
        }

        void RespawnVoidZones()
        {
            // Respawn all voids
            std::list<Creature*> voids;
            GetCreatureListWithEntryInGrid(voids, me, NPC_ULTHOK_VOID, 100.0f);
            if (!voids.empty())
                for(std::list<Creature*>::iterator itr = voids.begin(); itr != voids.end(); ++itr)
                    (*itr)->DespawnOrUnsummon();
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (DarkFissureTimer <= diff)
            {
                if (me->IsNonMeleeSpellCast(false))
                    return;

                DoCastVictim(SPELL_DARK_FISSURE);

                DarkFissureTimer = urand(10000, 15000);
            }
            else
                DarkFissureTimer -= diff;

            if (CurseOfFatigueTimer <= diff)
            {
                if (me->IsNonMeleeSpellCast(false))
                    return;

                if (Unit * pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    DoCast(pTarget, SPELL_CURSE_OF_FATIGUE);

                CurseOfFatigueTimer = urand(10000, 15000);
            }
            else
                CurseOfFatigueTimer -= diff;

            if (EnrageTimer <= diff)
            {
                if (me->IsNonMeleeSpellCast(false))
                    return;

                DoCast(me, SPELL_ENRAGE);

                EnrageTimer = urand(12000, 18000);
            }
            else
                EnrageTimer -= diff;

            if (SqueezeTimer <= diff)
            {
                if (me->IsNonMeleeSpellCast(false))
                    return;

                if (Unit * pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    DoCast(pTarget, IsHeroic() ? SPELL_SQUEEZE_H : SPELL_SQUEEZE);

                SqueezeTimer = urand(10000, 15000);
            }
            else
                SqueezeTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

class spell_ulthok_dark_fissure : public SpellScriptLoader
{
    public:
        spell_ulthok_dark_fissure() : SpellScriptLoader("spell_ulthok_dark_fissure") { }

        class spell_ulthok_dark_fissureSpellScript : public SpellScript
        {
            PrepareSpellScript(spell_ulthok_dark_fissureSpellScript);

            void FilterTargets(std::list<WorldObject*>& targetList)
            {
                if(Unit* caster = GetCaster())
                {
                    if(Aura* aura = caster->GetAura(91375))
                    {
                        uint8 stacks = aura->GetStackAmount();

                        std::list<WorldObject*>::iterator itr = targetList.begin();
                        while (itr != targetList.end())
                        {
                            if (*itr && ((*itr)->GetDistance(caster) > (int(3+ stacks * 0.35))))
                                targetList.erase(itr++);
                            else
                                ++itr;
                        }
                    }
                }
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_ulthok_dark_fissureSpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_ulthok_dark_fissureSpellScript();
        }
};

void AddSC_boss_ulthok()
{
    new boss_commander_ulthok();
    new spell_ulthok_dark_fissure();
}
