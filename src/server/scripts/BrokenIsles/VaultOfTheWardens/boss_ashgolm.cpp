/*
* Copyright (C) 2021 BfaCore Reforged
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
#include "vault_of_the_wardens.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_LAVA_WREATH = 1,
    SAY_FREEZE = 2,
    SAY_FREEZE_EMOTE = 3,
    SAY_BRITTLE = 4,
    // SAY_AGGRO        = 5   I don`t know where "Fire has a life of its own."
    SAY_DEATH = 6,
    SAY_SYSTEM = 7,
};

enum Spells
{
    SPELL_FROZEN = 200354,
    SPELL_HEAT_UP = 200981,
    SPELL_SMOLDERING = 193209,
    SPELL_VOLCANO = 192622,
    SPELL_LAVA_WREATH = 192631,
    SPELL_LAVA_WREATH_VIS = 193354,
    SPELL_LAVA_WREATH_TRIG = 193353,
    SPELL_LAVA_WREATH_AT = 192571,
    SPELL_FISSURE = 192522,
    SPELL_FISSURE_TRIG = 193355,
    SPELL_SUM_EMBER = 195170,

    //Ember
    SPELL_EMBER_SMOLDERING = 195188,
    SPELL_SEAR = 195332,
    SPELL_FIRED_UP = 202169,
    SPELL_DETONATE = 195187,

    //System security
    SPELL_ACTIVATE_SYSTEM_VIS = 195189,
    SPELL_ACTIVATE_SYSTEM = 195213,
    SPELL_FREEZE_ROOM = 195227,

    SPELL_ACHIEVE = 215478,
};

enum eEvents
{
    EVENT_VOLCANO = 1,
    EVENT_LAVA_WREATH = 2,
    EVENT_FISSURE = 3,
    EVENT_SUM_EMBER = 4,
    EVENT_SYSTEM_SECURITY = 5,
};

Position const centrPos = { 4239.14f, -451.332f, 105.947f };

//95886
class boss_ashgolm : public CreatureScript
{
public:
    boss_ashgolm() : CreatureScript("boss_ashgolm") {}

    struct boss_ashgolmAI : public BossAI
    {
        boss_ashgolmAI(Creature* creature) : BossAI(creature, DATA_ASHGOLM) {}

        void Reset() override
        {
            _Reset();
            me->GetMotionMaster()->MoveTargetedHome();

            if (instance->GetData(DATA_ASHGOLM_SYSTEM) != DONE)
                instance->SetData(DATA_ASHGOLM_SYSTEM, DONE);  // SetVisible(false)

            std::list<GameObject*> volcanoList;
            me->GetGameObjectListWithEntryInGrid(volcanoList, GO_ASHGOLM_VOLCANO, 80.0f);
            for (std::list<GameObject*>::iterator itr = volcanoList.begin(); itr != volcanoList.end(); ++itr)
            {
               // (*itr)->Delete();
            }
        }

        void EnterCombat(Unit* /*who*/) override
            //12:02
        {
            Talk(SAY_AGGRO);
            _EnterCombat();
            DoCast(SPELL_HEAT_UP);

            events.RescheduleEvent(EVENT_VOLCANO, 10000);     //12:12, 12:34
            events.RescheduleEvent(EVENT_LAVA_WREATH, 25000); //12:27, 13:22
            events.RescheduleEvent(EVENT_FISSURE, 40000);     //12:42, 13:29
            events.RescheduleEvent(EVENT_SUM_EMBER, 15000);
            events.RescheduleEvent(EVENT_SYSTEM_SECURITY, 45000);
        }

        void JustReachedHome() override
        {
            DoCast(me, SPELL_FROZEN, true);
        }

        bool checkaura()
        {
            auto const& players = me->GetMap()->GetPlayers();
            if (!players.isEmpty())
            {
                for (auto const& itr : players)
                {
                    if (Player* player = itr.GetSource())
                    {
                        if (player->HasAura(SPELL_ACHIEVE))
                            return true;
                    }
                }
            }
            return false;
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);
            _JustDied();

            if (checkaura())
                instance->DoUpdateAchievementCriteria(CRITERIA_TYPE_BE_SPELL_TARGET, 215472);

        }

        void SpellHit(Unit* caster, const SpellInfo* spell) override
        {
            if (spell->Id == SPELL_HEAT_UP)
                DoCast(me, SPELL_SMOLDERING, true);

            if (spell->Id == 192517)
            {
                Talk(SAY_FREEZE);
                Talk(SAY_FREEZE_EMOTE);
                events.RescheduleEvent(EVENT_SYSTEM_SECURITY, 80000);
            }
        }

        void SpellHitTarget(Unit* target, const SpellInfo* spell) override
        {
            if (spell->Id == SPELL_LAVA_WREATH)
            {
                Talk(SAY_LAVA_WREATH);
                DoCast(target, SPELL_LAVA_WREATH_VIS, true);
                Position pos;
                for (uint8 i = 0; i < 6; i++)
                {
                    target->GetNearPosition(5.0f, i * 1.2);
                    me->CastSpell(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), SPELL_LAVA_WREATH_TRIG, true);
                }
            }
            if (spell->Id == SPELL_FISSURE)
            {
                Position pos;
                float angle = centrPos.GetRelativeAngle(target);
                for (uint8 i = 0; i < 5; i++)
                {
                  //  centrPos.SimplePosXYRelocationByAngle(pos, i * 6, angle);
                    me->CastSpell(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), SPELL_FISSURE_TRIG, true);
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (me->GetDistance(me->GetHomePosition()) > 25.0f)
            {
                EnterEvadeMode();
                return;
            }

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_VOLCANO:
                    DoCast(SPELL_VOLCANO);
                    events.RescheduleEvent(EVENT_VOLCANO, 20000);
                    break;
                case EVENT_LAVA_WREATH:
                    DoCast(SPELL_LAVA_WREATH);
                    events.RescheduleEvent(EVENT_LAVA_WREATH, 55000);
                    break;
                case EVENT_FISSURE:
                    if (me->GetVictim())
                        DoCast(me->GetVictim(), SPELL_FISSURE);
                    events.RescheduleEvent(EVENT_FISSURE, 46000);
                    break;
                case EVENT_SUM_EMBER:
                    if (GameObject* volcano = me->FindNearestGameObject(GO_ASHGOLM_VOLCANO, 60.0f))
                       // me->CastSpell(volcano->GetPositionX(), volcano->GetPositionY(), volcano->GetPositionZ(), SPELL_SUM_EMBER, true);
                    events.RescheduleEvent(EVENT_SUM_EMBER, 15000);
                    break;
                case EVENT_SYSTEM_SECURITY:
                    if (instance->GetData(DATA_ASHGOLM_SYSTEM) != SPECIAL)
                        instance->SetData(DATA_ASHGOLM_SYSTEM, SPECIAL);  // SetVisible(true)
                    Talk(SAY_SYSTEM);
                    break;

                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_ashgolmAI(creature);
    }
};

//99233
class npc_ashgolm_ember : public CreatureScript
{
public:
    npc_ashgolm_ember() : CreatureScript("npc_ashgolm_ember") {}

    struct npc_ashgolm_emberAI : public ScriptedAI
    {
        npc_ashgolm_emberAI(Creature* creature) : ScriptedAI(creature) {}

        EventMap events;

        void Reset() override {}

        void SpellHit(Unit* caster, const SpellInfo* spell) override
        {
            if (spell->Id == SPELL_FIRED_UP)
                events.RescheduleEvent(1, 500);
        }

        void IsSummonedBy(Unit* summoner) override
        {
            DoCast(me, SPELL_EMBER_SMOLDERING, true);
            events.RescheduleEvent(2, 2000);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case 1:
                    DoCast(SPELL_DETONATE);
                    break;
                case 2:
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 80.0f, true))
                        DoCast(pTarget, SPELL_SEAR);
                    events.RescheduleEvent(2, 4000);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_ashgolm_emberAI(creature);
    }
};

//99240
class npc_ashgolm_countermeasures : public CreatureScript
{
public:
    npc_ashgolm_countermeasures() : CreatureScript("npc_ashgolm_countermeasures") {}

    struct npc_ashgolm_countermeasuresAI : public ScriptedAI
    {
        npc_ashgolm_countermeasuresAI(Creature* creature) : ScriptedAI(creature), click(false)
        {
            instance = me->GetInstanceScript();
            me->SetReactState(REACT_PASSIVE);
        }

        InstanceScript* instance;
        bool click;

        void Reset() override {}

        void IsSummonedBy(Unit* summoner) override
        {
            DoCast(me, SPELL_ACTIVATE_SYSTEM_VIS, true);
        }

/*        void OnSpellClick(Unit* clicker) //override
        {
            if (instance->GetBossState(DATA_ASHGOLM) != IN_PROGRESS)
                return;

            if (instance->GetData(DATA_ASHGOLM_SYSTEM) != IN_PROGRESS)
                instance->SetData(DATA_ASHGOLM_SYSTEM, IN_PROGRESS);
        }
*/
        void DoAction(int32 const action) override
            //45
        {
            DoCast(me, SPELL_ACTIVATE_SYSTEM, true);
        }

      /*  void SpellHitTarget(Unit* target, const SpellInfo* spell) override
        {
            if (spell->Id == SPELL_ACTIVATE_SYSTEM)
            {
                target->CastSpell(target, SPELL_FREEZE_ROOM);
                me->SetVisible(false);
            }
        }*/

      //  void UpdateAI(uint32 diff) override {}
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_ashgolm_countermeasuresAI(creature);
    }
};

//200354
class spell_ashgolm_frozen : public SpellScriptLoader
{
public:
    spell_ashgolm_frozen() : SpellScriptLoader("spell_ashgolm_frozen") { }

    class spell_ashgolm_frozen_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_ashgolm_frozen_AuraScript);

        void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
        {
            if (Creature* caster = GetCaster()->ToCreature())
                caster->SetReactState(REACT_PASSIVE);
        }

        void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
        {
            if (Creature* caster = GetCaster()->ToCreature())
                caster->SetReactState(REACT_AGGRESSIVE);
        }

        void Register() override
        {
            OnEffectApply += AuraEffectApplyFn(spell_ashgolm_frozen_AuraScript::OnApply, EFFECT_0, SPELL_AURA_TRANSFORM, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(spell_ashgolm_frozen_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_TRANSFORM, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_ashgolm_frozen_AuraScript();
    }
};

// 192517
class spell_brittle : public SpellScriptLoader
{
public:
    spell_brittle() : SpellScriptLoader("spell_brittle") { }

    class spell_brittle_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_brittle_AuraScript);

        void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
        {
            if (Creature* caster = GetCaster()->ToCreature())
                if (caster->GetEntry() == 95886)
                    caster->AI()->Talk(SAY_BRITTLE);
        }

        void Register() override
        {
            OnEffectRemove += AuraEffectRemoveFn(spell_brittle_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_TRANSFORM, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_brittle_AuraScript();
    }
};

void AddSC_boss_ashgolm()
{
    new boss_ashgolm();
    new npc_ashgolm_ember();
    new npc_ashgolm_countermeasures();
    new spell_ashgolm_frozen();
    new spell_brittle();
}
