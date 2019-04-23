/*
*
* Copyright (C) 2012-2014 Cerber Project <https://bitbucket.org/mojitoice/>
*
*/

#include "ScriptMgr.h"
#include "deadmines.h"
#include "SpellMgr.h"

enum eSpell
{
    SPELL_WHO_IS_THAT                       = 89339,
    SPELL_SETIATED                          = 89267,
    SPELL_SETIATED_H                        = 92834,
    SPELL_NAUSEATED                         = 89732,
    SPELL_NAUSEATED_H                       = 92066,
    SPELL_ROTTEN_AURA                       = 89734,
    SPELL_ROTTEN_AURA_H                     = 95513,
    SPELL_ROTTEN_AURA_DMG                   = 89734,
    SPELL_ROTTEN_AURA_DMG_H                 = 92065,
    SPELL_CAULDRON                          = 89250,
    SPELL_CAULDRON_VISUAL                   = 89251,
    SPELL_CAULDRON_FIRE                     = 89252,


    SPELL_THROW_FOOD_TARGETING_CORN         = 89268,
    SPELL_THROW_FOOD_TARGETING_ROTTEN_CORN  = 89740,
    SPELL_THROW_FOOD_TARGETING_MELON        = 90561,
    SPELL_THROW_FOOD_TARGETING_ROTTEN_MELON = 90582,
    SPELL_THROW_FOOD_TARGETING_STEAK        = 90562,
    SPELL_THROW_FOOD_TARGETING_ROTTEN_STEAK = 90583,
    SPELL_THROW_FOOD_TARGETING_MYSTERY_MEAT = 90563,
    SPELL_THROW_FOOD_TARGETING_ROTTEN_MM    = 90584,
    SPELL_THROW_FOOD_TARGETING_LOAF         = 90564,
    SPELL_THROW_FOOD_TARGETING_ROTTEN_LOAF  = 90585,
    SPELL_THROW_FOOD_TARGETING_BUN          = 90565,
    SPELL_THROW_FOOD_TARGETING_ROTTEN_BUN   = 90586,


    SPELL_THROW_FOOD                        = 89263,
    SPELL_THROW_FOOD_FORCE                  = 89269,
    SPELL_THROW_FOOD_BACK                   = 89264,
    SPELL_THROW_FOOD_01                     = 90557,
    SPELL_THROW_FOOD_02                     = 90560,
    SPELL_THROW_FOOD_03                     = 90603,
    SPELL_THROW_FOOD_04                     = 89739,
    SPELL_THROW_FOOD_05                     = 90605,
    SPELL_THROW_FOOD_06                     = 90556,
    SPELL_THROW_FOOD_07                     = 90680,
    SPELL_THROW_FOOD_08                     = 90559,
    SPELL_THROW_FOOD_09                     = 90602,
    SPELL_THROW_FOOD_10                     = 89263,
    SPELL_THROW_FOOD_11                     = 90604,
    SPELL_THROW_FOOD_12                     = 90555,
    SPELL_THROW_FOOD_13                     = 90606,
};

enum Adds
{
    NPC_BABY_MURLOC         = 48672,

    NPC_CAULDRON            = 47754,

    NPC_BUN                 = 48301,
    NPC_MISTERY_MEAT        = 48297,
    NPC_BREAD_LOAF          = 48300,
    NPC_STEAK               = 48296,
    NPC_CORN                = 48006,
    NPC_MELON               = 48294,

    NPC_ROTTEN_SNEAK        = 48295,
    NPC_ROTTEN_CORN         = 48276,
    NPC_ROTTEN_LOAF         = 48299,
    NPC_ROTTEN_MELON        = 48293,
    NPC_ROTTEN_MISTERY_MEAT = 48298,
    NPC_ROTTEN_BUN          = 48302,
};

enum Events
{
    EVENT_THROW_FOOD    = 1,
    EVENT_CAULDRON_1    = 2,
    EVENT_CAULDRON_2    = 3,
    EVENT_MOVE          = 4,
};

const uint32 ThrowFoodSpells[12] =
{
    SPELL_THROW_FOOD_TARGETING_CORN,
    SPELL_THROW_FOOD_TARGETING_ROTTEN_CORN,
    SPELL_THROW_FOOD_TARGETING_MELON,
    SPELL_THROW_FOOD_TARGETING_ROTTEN_MELON,
    SPELL_THROW_FOOD_TARGETING_STEAK,
    SPELL_THROW_FOOD_TARGETING_ROTTEN_STEAK,
    SPELL_THROW_FOOD_TARGETING_MYSTERY_MEAT,
    SPELL_THROW_FOOD_TARGETING_ROTTEN_MM,
    SPELL_THROW_FOOD_TARGETING_LOAF,
    SPELL_THROW_FOOD_TARGETING_ROTTEN_LOAF,
    SPELL_THROW_FOOD_TARGETING_BUN,
    SPELL_THROW_FOOD_TARGETING_ROTTEN_BUN
};

#define POINT_MOVE  1

const Position movePos =
{-71.292213f, -819.792297f, 40.51f, 0.04f};

const Position CookiesPos[2] =
{
    {-67.435249f, -822.357178f, 40.861347f, 0.0f},
    {-64.2552f, -820.245f, 41.17154f, 0.0f}
};

const Position notePos =
{-74.3611f, -820.014f, 40.3714f, 0.0f};

class boss_captain_cookie : public CreatureScript
{
public:
    boss_captain_cookie() : CreatureScript("boss_captain_cookie") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new boss_captain_cookieAI(pCreature);
    }

    struct boss_captain_cookieAI : public BossAI
    {
        boss_captain_cookieAI(Creature* pCreature) : BossAI(pCreature, DATA_COOKIE)
        {
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
            me->setActive(true);
        }

        void Reset() override
        {
            _Reset();
            me->SetReactState(REACT_AGGRESSIVE);
            DoCast(SPELL_WHO_IS_THAT);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (instance->GetBossState(DATA_RIPSNARL) != DONE)
                return;

            if (me->GetDistance(who) > 5.0f)
                return;

            BossAI::MoveInLineOfSight(who);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            me->RemoveAura(SPELL_WHO_IS_THAT);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->AttackStop();
            me->SetReactState(REACT_PASSIVE);

            events.ScheduleEvent(EVENT_MOVE, 1000);

            DoZoneInCombat();
            instance->SetBossState(DATA_COOKIE, IN_PROGRESS);
        }

        void MovementInform(uint32 type, uint32 data) override
        {
            if (type == POINT_MOTION_TYPE)
                if (data == POINT_MOVE)
                    events.ScheduleEvent(EVENT_CAULDRON_1, 2000);
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();

            if (IsHeroic())
                me->SummonCreature(NPC_VANESSA_NOTE, notePos);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_MOVE:
                        me->GetMotionMaster()->MovePoint(POINT_MOVE, movePos);
                        break;
                    case EVENT_CAULDRON_1:
                        me->CastSpell(CookiesPos[0].GetPositionX(), CookiesPos[0].GetPositionY(), CookiesPos[0].GetPositionZ(), SPELL_CAULDRON, true);
                        events.ScheduleEvent(EVENT_CAULDRON_2, 2000);
                        break;
                    case EVENT_CAULDRON_2:
                    {
                        if (Creature* pCauldron = me->FindNearestCreature(NPC_CAULDRON, 20.0f))
                            me->GetMotionMaster()->MoveJump(pCauldron->GetPositionX(), pCauldron->GetPositionY(), pCauldron->GetPositionZ(), 0.0f, 5, 10);
                        events.ScheduleEvent(EVENT_THROW_FOOD, 3000);
                        break;
                    }
                    case EVENT_THROW_FOOD:
                        DoCastAOE(ThrowFoodSpells[urand(0, 11)]);
                        events.ScheduleEvent(EVENT_THROW_FOOD, 4000);
                        break;
                }
            }
        }
    };
};

class npc_captain_cookie_cauldron : public CreatureScript
{
public:
    npc_captain_cookie_cauldron() : CreatureScript("npc_captain_cookie_cauldron") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_captain_cookie_cauldronAI(creature);
    }

    struct npc_captain_cookie_cauldronAI : public ScriptedAI
    {
        npc_captain_cookie_cauldronAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        }

        void Reset() override
        {
            DoCast(me, SPELL_CAULDRON_VISUAL, true);
            DoCast(me, SPELL_CAULDRON_FIRE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);
        }
    };
};

class npc_captain_cookie_good_food : public CreatureScript
{
public:
    npc_captain_cookie_good_food() : CreatureScript("npc_captain_cookie_good_food") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_captain_cookie_good_foodAI(pCreature);
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature) override
    {
        InstanceScript* pInstance = pCreature->GetInstanceScript();
        if (!pInstance)
            return true;
        if (pInstance->GetBossState(DATA_COOKIE) != IN_PROGRESS)
            return true;

        pPlayer->CastSpell(pPlayer, ( pPlayer->GetMap()->IsHeroic() ? SPELL_SETIATED_H : SPELL_SETIATED ), true);

        pCreature->DespawnOrUnsummon();
        return true;
    }

    struct npc_captain_cookie_good_foodAI : public ScriptedAI
    {
        npc_captain_cookie_good_foodAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            pInstance = pCreature->GetInstanceScript();
        }

        void JustDied(Unit* /*killer*/) override
        {
            me->DespawnOrUnsummon();
        }

        void UpdateAI(uint32 /*diff*/) override
        {
            if (!pInstance)
                return;

            if (pInstance->GetBossState(DATA_COOKIE) != IN_PROGRESS)
                me->DespawnOrUnsummon();
        }

    private:
        InstanceScript* pInstance;

    };
};

class npc_captain_cookie_bad_food : public CreatureScript
{
public:
    npc_captain_cookie_bad_food() : CreatureScript("npc_captain_cookie_bad_food") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_captain_cookie_bad_foodAI(pCreature);
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature) override
    {
        InstanceScript* pInstance = pCreature->GetInstanceScript();
        if (!pInstance)
            return true;
        if (pInstance->GetBossState(DATA_COOKIE) != IN_PROGRESS)
            return true;

        pPlayer->CastSpell(pPlayer, ( pPlayer->GetMap()->IsHeroic() ? SPELL_NAUSEATED_H : SPELL_NAUSEATED ), true);

        pCreature->DespawnOrUnsummon();
        return true;
    }

    struct npc_captain_cookie_bad_foodAI : public ScriptedAI
    {
        npc_captain_cookie_bad_foodAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            pInstance = pCreature->GetInstanceScript();
        }

        void JustDied(Unit* /*killer*/) override
        {
            me->DespawnOrUnsummon();
        }

        void UpdateAI(uint32 /*diff*/) override
        {
            if (!pInstance)
                return;

            if (pInstance->GetBossState(DATA_COOKIE) != IN_PROGRESS)
                me->DespawnOrUnsummon();
        }
    private:
        InstanceScript* pInstance;
    };
};

class spell_captain_cookie_setiated : public SpellScriptLoader
{
public:
    spell_captain_cookie_setiated() : SpellScriptLoader("spell_captain_cookie_setiated") { }


    class spell_captain_cookie_setiated_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_captain_cookie_setiated_SpellScript);


        void HandleScript(SpellEffIndex /*effIndex*/)
        {
            if (!GetCaster() || !GetHitUnit())
                return;
            GetHitUnit()->RemoveAuraFromStack(SPELL_NAUSEATED);
            GetHitUnit()->RemoveAuraFromStack(SPELL_NAUSEATED_H);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_captain_cookie_setiated_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_captain_cookie_setiated_SpellScript();
    }
};

class spell_captain_cookie_nauseated : public SpellScriptLoader
{
public:
    spell_captain_cookie_nauseated() : SpellScriptLoader("spell_captain_cookie_nauseated") { }


    class spell_captain_cookie_nauseated_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_captain_cookie_nauseated_SpellScript);


        void HandleScript(SpellEffIndex /*effIndex*/)
        {
            if (!GetCaster() || !GetHitUnit())
                return;

            GetHitUnit()->RemoveAuraFromStack(SPELL_SETIATED);
            GetHitUnit()->RemoveAuraFromStack(SPELL_SETIATED_H);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_captain_cookie_nauseated_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_captain_cookie_nauseated_SpellScript();
    }
};

class spell_captain_cookie_throw_food_targeting : public SpellScriptLoader
{
public:
    spell_captain_cookie_throw_food_targeting() : SpellScriptLoader("spell_captain_cookie_throw_food_targeting") { }

    class spell_captain_cookie_throw_food_targeting_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_captain_cookie_throw_food_targeting_SpellScript);

        void HandleAfterHit()
        {
            if (!GetCaster() || !GetHitUnit())
                return;

            uint32 spellId = 0;

            if (SpellInfo const* spellInfo = GetSpellInfo())
                spellId = spellInfo->GetEffect(EFFECT_0)->BasePoints;

            if (!sSpellMgr->GetSpellInfo(spellId))
                return;

            GetCaster()->CastSpell(GetHitUnit(), spellId);
        }

        void Register() override
        {
            AfterHit += SpellHitFn(spell_captain_cookie_throw_food_targeting_SpellScript::HandleAfterHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_captain_cookie_throw_food_targeting_SpellScript();
    }
};

void AddSC_boss_captain_cookie()
{
    new boss_captain_cookie();
    new npc_captain_cookie_cauldron();
    new npc_captain_cookie_good_food();
    new npc_captain_cookie_bad_food();
    new spell_captain_cookie_setiated();
    new spell_captain_cookie_nauseated();
    new spell_captain_cookie_throw_food_targeting();
}
