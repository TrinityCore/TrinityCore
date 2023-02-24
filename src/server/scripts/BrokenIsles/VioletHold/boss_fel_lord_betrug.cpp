/*
 * Copyright 2023 AzgathCore
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

#include "violet_hold_assault.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "LFGMgr.h"
#include "Group.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum Says
{
    SAY_START = 0,
    SAY_AGGRO = 1,
    SAY_EVADE = 2,
    SAY_EXECUTION = 3,
    SAY_EXECUTION_EMOTE = 4,
    SAY_DEATH = 5,
};

enum Spells
{
    SPELL_ARMED = 179670,
    SPELL_CHAOTIC_ENGERY = 203622,
    SPELL_FEL_SLASH = 203637,
    SPELL_MIGHTY_SMASH = 202328,
    SPELL_MIGHTY_SMASH_JUMP_1 = 202339, //Прыгает босс
    SPELL_MIGHTY_SMASH_JUMP_2 = 202340, //Прыгают все игроки, кроме одного.
    SPELL_MIGHTY_SMASH_JUMP_3 = 202343, //Прыгает один игрок
    SPELL_EXECUTION = 202361,
    SPELL_EXECUTION_ROOT_PLR = 205233,
    SPELL_STASIS_CRYSTAL_SUM = 205230,
    SPELL_STASIS_CRYSTAL_VIS = 205225,

    //Heroic+
    SPELL_SEED_OF_DESTRUCTION = 210879,
    SPELL_WAKE_OF_DESTRUCTION_AT = 210913, //210916 dmg
};

enum eEvents
{
    EVENT_PRE_FIGHT = 1,
    EVENT_CHAOTIC_ENGERY = 2,
    EVENT_FEL_SLASH = 3,
    EVENT_MIGHTY_SMASH = 4,
    EVENT_EXECUTION = 5,
    EVENT_SEED_OF_DESTRUCTION = 6,

    ACTION_CRYSTAL_DESTROYED
};

Position const jumpPos[4] =
{
    {4679.24f, 4014.53f, 91.75f},
    {4634.82f, 3965.24f, 86.98f},
    {4596.65f, 4015.52f, 83.31f},
    {4623.35f, 4058.62f, 82.64f},
};

//102446
class boss_fel_lord_betrug : public CreatureScript
{
public:
    boss_fel_lord_betrug() : CreatureScript("boss_fel_lord_betrug") { }

    struct boss_fel_lord_betrugAI : public BossAI
    {
        boss_fel_lord_betrugAI(Creature* creature) : BossAI(creature, DATA_BETRUG), readyFight(false), crystalDestroyed(false)
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->SetVisible(false);
        }

        bool readyFight;
        bool crystalDestroyed;

        void Reset() override
        {
            _Reset();
            DespawnTrashAndRemoveBuff();

            DoCast(me, SPELL_ARMED, true);

            if (instance->GetData(DATA_MAIN_EVENT_PHASE) == IN_PROGRESS)
                me->SetReactState(REACT_DEFENSIVE);
            else
                readyFight = false;
        }

        void JustEngagedWith(Unit* /*who*/) override
            //18:37
        {
            Talk(SAY_AGGRO);
            _JustEngagedWith();

            events.RescheduleEvent(EVENT_CHAOTIC_ENGERY, 6000); //18:43, 18:56, 19:35, 19:46
            events.RescheduleEvent(EVENT_FEL_SLASH, 12000); //18:49, 19:05, 20:01
            events.RescheduleEvent(EVENT_MIGHTY_SMASH, 32000); //19:09, 20:04, 20:58

            if (me->GetMap()->GetDifficultyID() != DIFFICULTY_NORMAL)
                events.RescheduleEvent(EVENT_SEED_OF_DESTRUCTION, 16000);
        }

        void EnterEvadeMode(EvadeReason w) 
        {
            Talk(SAY_EVADE);
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);
            _JustDied();
            DespawnTrashAndRemoveBuff();

            Map::PlayerList const& players = me->GetMap()->GetPlayers();
            if (!players.isEmpty())
            {
                Player* pPlayer = players.begin()->GetSource();
                if (pPlayer && pPlayer->GetGroup())
                {
                    if (me->GetMap()->GetDifficultyID() == DIFFICULTY_NORMAL)
                        sLFGMgr->FinishDungeon(pPlayer->GetGroup()->GetGUID(), 1208, me->GetMap());
                    if (me->GetMap()->GetDifficultyID() == DIFFICULTY_HEROIC)
                        sLFGMgr->FinishDungeon(pPlayer->GetGroup()->GetGUID(), 1209, me->GetMap());
                }
            }
        }

        void DoAction(int32 const action) override
        {
            if (instance->GetData(DATA_MAIN_EVENT_PHASE) != IN_PROGRESS)
                return;

            if (action == 1)
            {
                me->SetVisible(true);
                me->GetMotionMaster()->MoveJump(saboFightPos.GetPositionX(), saboFightPos.GetPositionY(), saboFightPos.GetPositionZ(), 20.0f, 20.0f, 10);
                me->SetHomePosition(saboFightPos);
            }

            if (action == ACTION_CRYSTAL_DESTROYED)
            {
                if (crystalDestroyed)
                {
                    me->RemoveAurasDueToSpell(SPELL_EXECUTION);
                    instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_EXECUTION_ROOT_PLR);
                }
                crystalDestroyed = true;
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type != EFFECT_MOTION_TYPE)
                return;

            if (id == 10)
            {
                Talk(SAY_START);
                events.RescheduleEvent(EVENT_PRE_FIGHT, 1000);
            }

            if (id == SPELL_MIGHTY_SMASH_JUMP_1)
            {
                if (Creature* trigger = me->FindNearestCreature(92879, 15.0f))
                    me->SetFacingTo(trigger->GetOrientation());
                events.RescheduleEvent(EVENT_EXECUTION, 500);
            }
        }

        void DespawnTrashAndRemoveBuff()
        {
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_EXECUTION_ROOT_PLR);

            std::list<Creature*> creList;
            GetCreatureListWithEntryInGrid(creList, me, NPC_STASIS_CRYSTAL, 120.0f);
            for (auto const& crystal : creList)
                crystal->DespawnOrUnsummon();
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim() && readyFight)
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_PRE_FIGHT:
                    readyFight = true;
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                    me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                    break;
                case EVENT_CHAOTIC_ENGERY:
                    DoCast(me, SPELL_CHAOTIC_ENGERY, true);
                    events.RescheduleEvent(EVENT_CHAOTIC_ENGERY, 12000);
                    break;
                case EVENT_FEL_SLASH:
                    DoCast(SPELL_FEL_SLASH);
                    events.RescheduleEvent(EVENT_FEL_SLASH, 16000);
                    break;
                case EVENT_MIGHTY_SMASH:
                    crystalDestroyed = false;
                    DoCast(SPELL_MIGHTY_SMASH);
                    events.RescheduleEvent(EVENT_MIGHTY_SMASH, 54000);
                    break;
                case EVENT_EXECUTION:
                    DoCast(SPELL_EXECUTION);
                    Talk(SAY_EXECUTION);
                    Talk(SAY_EXECUTION_EMOTE);
                    break;
                case EVENT_SEED_OF_DESTRUCTION:
                    DoCast(SPELL_SEED_OF_DESTRUCTION);
                    events.RescheduleEvent(EVENT_SEED_OF_DESTRUCTION, 22000);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_fel_lord_betrugAI(creature);
    }
};

//103672
class npc_betrug_stasis_crystal : public CreatureScript
{
public:
    npc_betrug_stasis_crystal() : CreatureScript("npc_betrug_stasis_crystal") {}

    bool OnGossipHello(Player* clicker, Creature* me)
    {
        if (clicker->HasAura(SPELL_EXECUTION_ROOT_PLR))
            return false;

        clicker->CastSpell(me, 205227, true);
        return true;
    }

    struct npc_betrug_stasis_crystalAI : public ScriptedAI
    {
        npc_betrug_stasis_crystalAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = me->GetInstanceScript();
            me->SetReactState(REACT_PASSIVE);
            destroyed = false;
        }

        InstanceScript* instance;
        bool destroyed;

        void Reset() override {}

        void IsSummonedBy(Unit* summoner) override
        {
            me->SetNpcFlags(UNIT_NPC_FLAG_SPELLCLICK);
            DoCast(me, SPELL_STASIS_CRYSTAL_VIS, true);
            DoCast(summoner, 205226, true);
        }

        void SpellHit(Unit* caster, const SpellInfo* spell) override
        {
            if (destroyed)
                return;

            if (spell->Id == 205227)
            {
                if (Creature* betrug = instance->instance->GetCreature(instance->GetGuidData(DATA_BETRUG)))
                    betrug->AI()->DoAction(ACTION_CRYSTAL_DESTROYED);

                destroyed = true;
                me->RemoveNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
                me->RemoveAllAuras();
                me->DespawnOrUnsummon(2000);
            }
        }

        void UpdateAI(uint32 diff) override {}
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_betrug_stasis_crystalAI(creature);
    }
};

//202328
class spell_betrug_mighty_smash : public SpellScriptLoader
{
public:
    spell_betrug_mighty_smash() : SpellScriptLoader("spell_betrug_mighty_smash") { }

    class spell_betrug_mighty_smash_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_betrug_mighty_smash_SpellScript);

        uint8 bPos, pPos;
        uint8 targetHit = 0;
        uint8 targetHitCount = 0;

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            std::list<WorldObject*> tempList;
            for (auto const& player : targets)
            {
                if (player->GetTypeId() != TYPEID_PLAYER)
                    continue;

                tempList.push_back(player);
            }

            if (tempList.size() > 0)
                targetHit = urand(1, tempList.size());

            targets = tempList;
        }

        void HandleOnCast()
        {
            if (!GetCaster())
                return;

            if (Creature* trigger = GetCaster()->FindNearestCreature(92879, 70.0f))
            {
                for (uint8 i = 0; i < 4; i++)
                    if (trigger->GetDistance(jumpPos[i]) < 20.0f)
                        bPos = i;

                if (bPos > 1)
                    pPos = bPos - 2;
                else
                    pPos = bPos + 2;

                GetCaster()->CastSpell(trigger, SPELL_MIGHTY_SMASH_JUMP_1, true);
            }
        }

        void HandleOnHit()
        {
            if (!GetCaster() || !GetHitUnit() || !targetHit)
                return;

            targetHitCount++;

            if (targetHit != targetHitCount)
            {
                //GetHitUnit()->CastSpell(jumpPos[pPos], SPELL_MIGHTY_SMASH_JUMP_2, true);
                GetHitUnit()->GetMotionMaster()->MoveJump(Position(jumpPos[pPos].GetPositionX(), jumpPos[pPos].GetPositionY(), jumpPos[pPos].GetPositionZ()), 30.0f, 15.0f);
            }
            else
            {
                //GetHitUnit()->CastSpell(jumpPos[bPos], SPELL_MIGHTY_SMASH_JUMP_3, true);
                GetHitUnit()->GetMotionMaster()->MoveJump(Position(jumpPos[bPos].GetPositionX(), jumpPos[bPos].GetPositionY(), jumpPos[bPos].GetPositionZ()), 30.0f, 15.0f);
                if (Creature* trigger = GetCaster()->FindNearestCreature(92879, 50.0f))
                {
                    Position posLeft, posRight;
                    trigger->GetNearPosition(7.0f, -0.7f);
                    trigger->GetNearPosition(7.0f, 0.7f);
                    GetHitUnit()->CastSpell(posLeft.GetPositionX(), posLeft.GetPositionY(), posLeft.GetPositionZ(), SPELL_STASIS_CRYSTAL_SUM, true);
                    GetHitUnit()->CastSpell(posRight.GetPositionX(), posRight.GetPositionY(), posRight.GetPositionZ(), SPELL_STASIS_CRYSTAL_SUM, true);
                    GetHitUnit()->CastSpell(GetHitUnit(), SPELL_EXECUTION_ROOT_PLR, true);
                }
            }
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_betrug_mighty_smash_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            OnCast += SpellCastFn(spell_betrug_mighty_smash_SpellScript::HandleOnCast);
            OnHit += SpellHitFn(spell_betrug_mighty_smash_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_betrug_mighty_smash_SpellScript();
    }
};

//210879
class spell_betrug_seed_of_destruction : public SpellScriptLoader
{
public:
    spell_betrug_seed_of_destruction() : SpellScriptLoader("spell_betrug_seed_of_destruction") { }

    class spell_betrug_seed_of_destruction_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_betrug_seed_of_destruction_AuraScript);

        void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
        {
            AuraRemoveMode removeMode = GetTargetApplication()->GetRemoveMode();

            if (!GetCaster() || !GetTarget() || !GetCaster()->IsInCombat() || removeMode != AURA_REMOVE_BY_EXPIRE)
                return;

            Position pos;
            float angle = 0.0f;
            for (uint8 i = 0; i < 4; i++)
            {
                GetTarget()->GetNearPosition(5.0f, angle);
                GetTarget()->CastSpell(pos, SPELL_WAKE_OF_DESTRUCTION_AT, GetCaster()->GetGUID());
                angle += 1.57f;
            }
        }

        void Register() override
        {
            OnEffectRemove += AuraEffectRemoveFn(spell_betrug_seed_of_destruction_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_betrug_seed_of_destruction_AuraScript();
    }
};

void AddSC_boss_fel_lord_betrug()
{
    new boss_fel_lord_betrug();
    new npc_betrug_stasis_crystal();
    new spell_betrug_mighty_smash();
    new spell_betrug_seed_of_destruction();
}
