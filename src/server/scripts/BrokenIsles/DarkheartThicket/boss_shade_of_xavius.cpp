#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "darkheart_thicket.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_DEATH = 1,
    SAY_END = 0,
};

enum Spells
{
    SPELL_SHADE_VISUAL = 195106,
    SPELL_FESTERING_RIP = 200182,
    SPELL_NIGHTMARE_BOLT = 204808,
    SPELL_FEED_ON_THE_WEAK = 200238,
    SPELL_INDUCED_PARANOIA = 200359,
    SPELL_COWARDICE = 200273,

    //Final Phase 50%HP
    SPELL_PHASE_CHANGE_CONVERSATION = 199857, //deprecated
    SPELL_APOCOLYPTIC_NIGHTMARE = 200050,
    SPELL_DRAIN_ESSENCE = 199837, //deprecated

    //Cage
    SPELL_NIGHTMARE_SHIELD = 204511,
    SPELL_NIGHTMARE_BINDINGS = 199752,

    //Malfurion
    SPELL_NATURE_RECOVERY = 204680,
    SPELL_ESCAPES_CONVERSATION = 199912,
    SPELL_NATURE_DOMINANCE = 199922, //deprecated
};

enum eEvents
{
    EVENT_FESTERING_RIP = 1,
    EVENT_NIGHTMARE_BOLT = 2,
    EVENT_FEED_ON_THE_WEAK = 3,
    EVENT_INDUCED_PARANOIA = 4,
    EVENT_FINAL_PHASE = 5,
};

enum Misc
{
    DATA_STACKS = 221315,
    EVENT_1,
    ACTION_1, 
};

//99192
class boss_shade_of_xavius : public CreatureScript
{
public:
    boss_shade_of_xavius() : CreatureScript("boss_shade_of_xavius") {}

    struct boss_shade_of_xaviusAI : public BossAI
    {
        boss_shade_of_xaviusAI(Creature* creature) : BossAI(creature, DATA_XAVIUS), summons(me) {}

        SummonList summons;
        bool finalPhase;
        bool _stacked = false;

        void Reset() override
        {
            _Reset();
            summons.DespawnAll();
            if (Creature* malfurion = instance->instance->GetCreature(instance->GetGuidData(NPC_MALFURION_STORMRAGE)))
                malfurion->DespawnOrUnsummon();
            finalPhase = false;
            DoCast(me, SPELL_SHADE_VISUAL, true);
            me->SummonCreature(NPC_NIGHTMARE_BINDINGS, 2689.05f, 1297.46f, 128.40f);
            _stacked = false;
        }

        void JustEngagedWith(Unit* /*who*/) override
            //49:53
        {
            Talk(SAY_AGGRO);
            _JustEngagedWith();
            events.RescheduleEvent(EVENT_FESTERING_RIP, 3000);  //49:56, 50:13
            events.RescheduleEvent(EVENT_NIGHTMARE_BOLT, 9000);  //50:02, 50:19
            events.RescheduleEvent(EVENT_FEED_ON_THE_WEAK, 14000); //50:07, 51:01, 51:30, 52:00
            events.RescheduleEvent(EVENT_INDUCED_PARANOIA, 21000); //50:14, 51:00, 51:21, 51:42
        }

        uint32 GetData(uint32 type) const override
        {
            switch (type)
            {
            case DATA_STACKS:
                return _stacked ? 1 : 0;
            }

            return 0;
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);
            _JustDied();
            summons.DespawnAll();
            if (Creature* malfurion = instance->instance->GetCreature(instance->GetGuidData(NPC_MALFURION_STORMRAGE)))
                malfurion->AI()->DoAction(ACTION_1);
        }

        void JustSummoned(Creature* summon) override
        {
            summons.Summon(summon);

            if (summon->GetEntry() == NPC_NIGHTMARE_BINDINGS)
            {
                summon->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
                summon->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
                summon->SetReactState(REACT_PASSIVE);
                summon->CastSpell(summon, SPELL_NIGHTMARE_SHIELD, true);
                summon->CastSpell(summon, SPELL_NIGHTMARE_BINDINGS, true);
            }
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage)
        {
            if (HealthBelowPct(51) && !finalPhase)
            {
                finalPhase = true;
                events.RescheduleEvent(EVENT_FINAL_PHASE, 1000);
            }
            if (damage >= me->GetHealth())
            {
                if (Aura const* aura = me->GetAura(221315))
                {
                    if (aura->GetStackAmount() >= 10)
                        _stacked = true;
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
                case EVENT_FESTERING_RIP:
                    DoCastVictim(SPELL_FESTERING_RIP);
                    events.RescheduleEvent(EVENT_FESTERING_RIP, 17000);
                    break;
                case EVENT_NIGHTMARE_BOLT:
                    DoCast(SPELL_NIGHTMARE_BOLT);
                    events.RescheduleEvent(EVENT_NIGHTMARE_BOLT, 17000);
                    break;
                case EVENT_FEED_ON_THE_WEAK:
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f, true))
                        DoCast(pTarget, SPELL_FEED_ON_THE_WEAK);
                    events.RescheduleEvent(EVENT_FEED_ON_THE_WEAK, 30000);
                    break;
                case EVENT_INDUCED_PARANOIA:
                    DoCast(SPELL_INDUCED_PARANOIA);
                    events.RescheduleEvent(EVENT_INDUCED_PARANOIA, 21000);
                    break;
                case EVENT_FINAL_PHASE:
                    DoCast(SPELL_APOCOLYPTIC_NIGHTMARE);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }

    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_shade_of_xaviusAI(creature);
    }
};

//100652
class npc_xavius_malfurion_stormrage : public CreatureScript
{
public:
    npc_xavius_malfurion_stormrage() : CreatureScript("npc_xavius_malfurion_stormrage") { }

    struct npc_xavius_malfurion_stormrageAI : public ScriptedAI
    {
        npc_xavius_malfurion_stormrageAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = me->GetInstanceScript();
            me->SetReactState(REACT_PASSIVE);
        }

        InstanceScript* instance;
        EventMap events;

        void Reset() override {}

        void DoAction(int32 const action) override
        {
            if (action == ACTION_1)
                me->GetMotionMaster()->MoveCharge(1302.77f, 128.36f, me->GetPositionZ(), 10.0f);
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type != EFFECT_MOTION_TYPE)
                return;

            events.RescheduleEvent(EVENT_1, 3000);
        }

        bool GossipSelect(Player* player, uint32 sender, uint32 action) override
        {
            player->TeleportTo(1466, 3248.16f, 1829.34f, 236.84f, 0.1f);

            return true;
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_1:
                    Talk(SAY_END);
                    me->GetMotionMaster()->MovePoint(1, 2711.70f, 1322.85f, 128.36f);
                    break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_xavius_malfurion_stormrageAI(creature);
    }
};

//200243
class spell_xavius_waking_nightmare : public SpellScriptLoader
{
public:
    spell_xavius_waking_nightmare() : SpellScriptLoader("spell_xavius_waking_nightmare") { }

    class spell_xavius_waking_nightmare_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_xavius_waking_nightmare_AuraScript);

        uint16 m_checkTimer = 1000;

        void OnUpdate(AuraEffect const* aurEff)
        {
            std::list<Player*> playersList;
            GetPlayerListInGrid(playersList, GetCaster(), 5.0f);
            if (playersList.size() > 1)
            {
                if (GetCaster()->HasAura(SPELL_COWARDICE))
                    GetCaster()->RemoveAurasDueToSpell(SPELL_COWARDICE);
            }
            else
            {
                if (!GetCaster()->HasAura(SPELL_COWARDICE))
                    GetCaster()->CastSpell(GetCaster(), SPELL_COWARDICE, true);
            }
        }

        void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
        {
            if (GetCaster())
                GetCaster()->RemoveAurasDueToSpell(SPELL_COWARDICE);
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_xavius_waking_nightmare_AuraScript::OnUpdate, EFFECT_0, SPELL_AURA_AREA_TRIGGER);
            OnEffectRemove += AuraEffectRemoveFn(spell_xavius_waking_nightmare_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_AREA_TRIGGER, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_xavius_waking_nightmare_AuraScript();
    }
};

class achievement_burning_down_the_house : public AchievementCriteriaScript
{
public:
    achievement_burning_down_the_house() : AchievementCriteriaScript("achievement_burning_down_the_house") { }

    bool OnCheck(Player* /*player*/, Unit* target) override
    {
        if (!target)
            return false;

        if (Creature* Xav = target->ToCreature())
            if (Xav->IsAIEnabled && (Xav->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC || Xav->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC_KEYSTONE))
                if (Xav->AI()->GetData(DATA_STACKS))
                    return true;

        return false;
    }
};

void AddSC_boss_shade_of_xavius()
{
    new boss_shade_of_xavius();
    new npc_xavius_malfurion_stormrage();
    new spell_xavius_waking_nightmare();
    new achievement_burning_down_the_house();
}
