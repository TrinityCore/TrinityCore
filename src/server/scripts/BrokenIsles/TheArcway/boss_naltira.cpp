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

#include "the_arcway.h"

enum Spells
{
    //Intro
    SPELL_WEB_BEAM_BOSS = 209833,
    SPELL_WEB_BEAM_TRASH = 209834,

    SPELL_BLINK_STRIKES_VISUAL = 199864,
    SPELL_BLINK_STRIKES_SEARCH = 199809,
    SPELL_BLINK_STRIKES_TP = 199810,
    SPELL_BLINK_STRIKES_DMG = 199811,
    SPELL_NETHER_VENOM = 199956,
    SPELL_TANGLED_WEB = 200227,
    SPELL_TANGLED_WEB_JUMP = 200230,
    SPELL_TANGLED_WEB_DMG = 200284,
    SPELL_TANGLED_BEAM = 200237,

    //Trash
    SPELL_DEVOUR = 211543,
};

enum eEvents
{
    EVENT_BLINK_STRIKES_1 = 1,
    EVENT_BLINK_STRIKES_2 = 2,
    EVENT_NETHER_VENOM = 3,
    EVENT_TANGLED_WEB = 4,
    EVENT_SUM_MANAFANG = 5,
    EVENT_1,
};

Position const spiderPos[21] =
{
    {3163.41f, 4665.23f, 574.34f, 0.56f},
    {3178.14f, 4667.58f, 574.34f, 0.18f},
    {3182.06f, 4650.01f, 574.34f, 5.93f},
    {3169.97f, 4640.99f, 574.34f, 5.17f},
    {3150.47f, 4692.17f, 574.34f, 2.30f},
    {3141.19f, 4699.91f, 574.34f, 2.03f},
    {3156.49f, 4687.44f, 574.34f, 1.01f},
    {3128.86f, 4684.70f, 574.34f, 3.09f},
    {3163.68f, 4633.81f, 574.34f, 3.96f},
    {3156.48f, 4641.36f, 574.34f, 3.21f},
    {3132.53f, 4679.60f, 574.34f, 1.01f},
    {3154.51f, 4632.66f, 574.34f, 0.92f},
    {3125.42f, 4657.03f, 574.34f, 1.26f},
    {3145.54f, 4680.42f, 574.34f, 4.54f},
    {3120.70f, 4661.97f, 574.34f, 5.98f},
    {3120.99f, 4666.23f, 574.34f, 1.57f},
    {3125.56f, 4689.92f, 574.34f, 4.71f},
    {3132.43f, 4637.73f, 574.34f, 0.56f},
    {3124.91f, 4628.75f, 574.34f, 4.66f},
    {3105.72f, 4651.09f, 574.34f, 3.28f},
    {3120.08f, 4643.58f, 574.34f, 3.07f}
};

//98207
class boss_naltira : public CreatureScript
{
public:
    boss_naltira() : CreatureScript("boss_naltira") {}

    struct boss_naltiraAI : public BossAI
    {
        boss_naltiraAI(Creature* creature) : BossAI(creature, DATA_NALTIRA)
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_NPC);
            me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
            me->SetUnitFlags(UNIT_FLAG_NOT_ATTACKABLE_1);

            if (Creature* beamTarget = me->SummonCreature(68553, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 50.0f))
            {
                beamTarget->CastSpell(me, SPELL_WEB_BEAM_BOSS, true);
                me->SetDisableGravity(true);
                me->GetMotionMaster()->MoveTakeoff(1, me->GetPosition());
            }
            for (uint8 i = 0; i < 21; ++i)
                me->SummonCreature(NPC_ENCHANTED_BROODLING_I, spiderPos[i]);
        }

        bool blinkEvent = false;
        bool checkWebPlayer = false;
        uint8 DiedSpidersCount = 0;
        Unit* plrWebTarget = nullptr;

        void Reset() override
        {
            _Reset();
            blinkEvent = false;

            if (DiedSpidersCount >= 21)
                me->SetReactState(REACT_AGGRESSIVE);
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            _JustEngagedWith();

            events.RescheduleEvent(EVENT_BLINK_STRIKES_1, 15000);
            events.RescheduleEvent(EVENT_NETHER_VENOM, 26000);
            events.RescheduleEvent(EVENT_TANGLED_WEB, 32000);

            if (me->GetMap()->GetDifficultyID() != DIFFICULTY_NORMAL)
                events.RescheduleEvent(EVENT_SUM_MANAFANG, 25000);
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();
        }

        void SpellHitTarget(Unit* target, const SpellInfo* spell) override
        {
            switch (spell->Id)
            {
            case SPELL_BLINK_STRIKES_TP:
                me->GetMotionMaster()->Clear();
                events.RescheduleEvent(EVENT_BLINK_STRIKES_2, 500);
                break;
            case SPELL_TANGLED_WEB_DMG:
                if (checkWebPlayer)
                {
                    checkWebPlayer = false;
                    plrWebTarget = target;
                }
                else
                    target->CastSpell(plrWebTarget, SPELL_TANGLED_BEAM, true);
                break;
            }
        }

        void SummonedCreatureDies(Creature* summon, Unit* /*killer*/)
        {
            if (summon->GetEntry() == NPC_ENCHANTED_BROODLING_I || summon->GetEntry() == NPC_VICIOUS_MANAFANG_I)
            {
                if (DiedSpidersCount > 32)
                    return;

                switch (DiedSpidersCount)
                {
                case 6:
                case 23:
                case 27:
                {
                    uint8 count = 3;
                    if (DiedSpidersCount == 23)
                        count = 4;
                    else if (DiedSpidersCount == 27)
                        count = 5;

                    float x, y, z;
                    float angle = frand(0.0f, 6.28f);
                    float radius = (count == 3 ? 5.0f : 18.0f);
                    for (uint8 i = 0; i < count; ++i)
                    {
                        me->GetClosePoint(x, y, z, me->GetObjectSize(), radius, angle);
                        angle += frand(0.6f, 1.2f);

                        me->SummonCreature(NPC_VICIOUS_MANAFANG_I, x, y, z + 30.0f);
                    }
                    break;
                }
                case 32:
                    me->GetMotionMaster()->MoveTakeoff(2, me->GetPosition());
                    break;
                }
                ++DiedSpidersCount;
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type != EFFECT_MOTION_TYPE)
                return;

            if (id == 2)
            {
                me->SetDisableGravity(false);
                me->RemoveAurasDueToSpell(SPELL_WEB_BEAM_BOSS);
                me->SetReactState(REACT_AGGRESSIVE);
                me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
                me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                me->RemoveUnitFlag(UNIT_FLAG_NOT_ATTACKABLE_1);
            }
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
                case EVENT_BLINK_STRIKES_1:
                    me->AttackStop();
                    DoCast(me, SPELL_BLINK_STRIKES_SEARCH, true);
                    if (!blinkEvent)
                    {
                        blinkEvent = true;
                        DoCast(me, SPELL_BLINK_STRIKES_VISUAL, true);
                        events.RescheduleEvent(EVENT_BLINK_STRIKES_1, 3000);
                    }
                    else
                    {
                        blinkEvent = false;
                        me->SetReactState(REACT_AGGRESSIVE);
                        events.RescheduleEvent(EVENT_BLINK_STRIKES_1, 30000);
                    }
                    break;
                case EVENT_BLINK_STRIKES_2:
                    DoCast(me, SPELL_BLINK_STRIKES_DMG, true);
                    break;
                case EVENT_NETHER_VENOM:
                    DoCast(SPELL_NETHER_VENOM);
                    events.RescheduleEvent(EVENT_NETHER_VENOM, 30000);
                    break;
                case EVENT_TANGLED_WEB:
                    plrWebTarget = nullptr;
                    checkWebPlayer = true;
                    DoCast(SPELL_TANGLED_WEB);
                    Talk(0);
                    events.RescheduleEvent(EVENT_TANGLED_WEB, 22000);
                    break;
                case EVENT_SUM_MANAFANG:
                    Position pos;
                    me->GetRandomNearPosition(30.0f);
                    me->SummonCreature(NPC_VICIOUS_MANAFANG, pos);
                    events.RescheduleEvent(EVENT_SUM_MANAFANG, 22000);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_naltiraAI(creature);
    }
};

//110966
class npc_naltira_vicious_manafang : public CreatureScript
{
public:
    npc_naltira_vicious_manafang() : CreatureScript("npc_naltira_vicious_manafang") {}

    struct npc_naltira_vicious_manafangAI : public ScriptedAI
    {
        npc_naltira_vicious_manafangAI(Creature* creature) : ScriptedAI(creature) {}

        EventMap events;
        ObjectGuid playerGUID;
        int32 health;

        void Reset() override
        {
            events.Reset();
        }

        void IsSummonedBy(Unit* summoner) override
        {
            health = 0;
            DoZoneInCombat(me, 100.0f);
            events.RescheduleEvent(EVENT_1, urand(10, 15) * IN_MILLISECONDS);
        }

        void JustDied(Unit* /*killer*/) override
        {
            RemoveDevour();
        }

        void SpellHitTarget(Unit* target, const SpellInfo* spell) override
        {
            if (spell->Id == SPELL_DEVOUR)
            {
                me->EnterVehicle(target);
                health = me->GetMaxHealth() - me->CountPctFromMaxHealth(70);
                playerGUID = target->GetGUID();
            }
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage)
        {
            if (health)
            {
                health -= damage;

                if (health <= 0)
                {
                    health = 0;
                    RemoveDevour();
                }
            }
        }

        void RemoveDevour()
        {
            if (Player* player = ObjectAccessor::GetPlayer(*me, playerGUID))
            {
                if (player->IsAlive() && player->HasAura(SPELL_DEVOUR, me->GetGUID()))
                {
                    playerGUID = ObjectGuid::Empty;
                    player->RemoveAurasDueToSpell(SPELL_DEVOUR, me->GetGUID());
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

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_1:
                    DoCast(SPELL_DEVOUR);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_naltira_vicious_manafangAI(creature);
    }
};

//105876
class npc_naltira_vicious_manafang_intro : public CreatureScript
{
public:
    npc_naltira_vicious_manafang_intro() : CreatureScript("npc_naltira_vicious_manafang_intro") {}

    struct npc_naltira_vicious_manafang_introAI : public ScriptedAI
    {
        npc_naltira_vicious_manafang_introAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_NPC);
            me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
            me->SetUnitFlags(UNIT_FLAG_NOT_ATTACKABLE_1);
        }

        EventMap events;

        void Reset() override
        {
            events.Reset();
        }

        void IsSummonedBy(Unit* summoner) override
        {
            me->SetCanFly(true);

            if (Creature* beamTarget = summoner->SummonCreature(68553, me->GetPosition()))
                beamTarget->CastSpell(me, SPELL_WEB_BEAM_TRASH, true);

        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type != EFFECT_MOTION_TYPE)
                return;

            if (id == 1)
            {

                me->SetCanFly(false);
                me->RemoveAurasDueToSpell(SPELL_WEB_BEAM_TRASH);
                me->SetHomePosition(*me);
                me->SetReactState(REACT_AGGRESSIVE);
                me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
                me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                me->RemoveUnitFlag(UNIT_FLAG_NOT_ATTACKABLE_1);
            }
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
                case EVENT_1:
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_naltira_vicious_manafang_introAI(creature);
    }
};

//200227
class spell_naltira_tangled_web : public SpellScriptLoader
{
public:
    spell_naltira_tangled_web() : SpellScriptLoader("spell_naltira_tangled_web") {}

    class spell_naltira_tangled_web_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_naltira_tangled_web_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            if (!GetCaster())
                return;

            std::list<WorldObject*> tempTargets;

            for (auto const& target : targets)
                if (target && target->ToPlayer() && target->ToPlayer()->IsAlive())
                    tempTargets.push_back(target);

            targets = tempTargets;

            if (targets.size() < 2)
                targets.clear();
        }

        void HandleOnHit()
        {
            if (!GetCaster() || !GetHitUnit())
                return;

            GetHitUnit()->CastSpell(GetCaster(), SPELL_TANGLED_WEB_JUMP, true);
            GetCaster()->CastSpell(GetHitUnit(), SPELL_TANGLED_WEB_DMG, true);
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_naltira_tangled_web_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            OnHit += SpellHitFn(spell_naltira_tangled_web_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_naltira_tangled_web_SpellScript();
    }
};

//200251
class spell_naltira_tangled_web_check_dist : public SpellScriptLoader
{
public:
    spell_naltira_tangled_web_check_dist() : SpellScriptLoader("spell_naltira_tangled_web_check_dist") { }

    class spell_naltira_tangled_web_check_dist_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_naltira_tangled_web_check_dist_SpellScript);

        void HandleOnHit()
        {
            if (!GetCaster() || !GetHitUnit())
                return;

            if (GetCaster()->GetDistance(GetHitUnit()) >= 30.0f)
            {
                GetCaster()->RemoveAurasDueToSpell(SPELL_TANGLED_WEB_DMG);
                GetHitUnit()->RemoveAurasDueToSpell(SPELL_TANGLED_WEB_DMG);
                GetHitUnit()->RemoveAurasDueToSpell(SPELL_TANGLED_BEAM);
            }
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_naltira_tangled_web_check_dist_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_naltira_tangled_web_check_dist_SpellScript();
    }
};

void AddSC_boss_naltira()
{
    new boss_naltira();
    new npc_naltira_vicious_manafang();
    new npc_naltira_vicious_manafang_intro();
    new spell_naltira_tangled_web();
    new spell_naltira_tangled_web_check_dist();
}
