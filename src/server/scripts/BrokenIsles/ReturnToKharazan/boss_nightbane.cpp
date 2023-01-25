#include "new_karazhan.h"
#include "Group.h"

enum eSpells
{
    // ground
    SPELL_CINDER_BREATH = 228785,  // 30?
    SPELL_TAIL_SWIPE = 228786,  // 12 ?
    SPELL_CHARRED_GROUND_AT = 228806,  // 16 ?   // damage 228808
    SPELL_CHARRED_GROUND_TICK = 228863,
    SPELL_BURNING_BONES = 228829, // 18 ?
    SPELL_IGNITE_SOUL = 228796, // 26 ?
    SPELL_REVERBERATING_SHADOWS = 229307,

    // power-auras
    SPELL_INFERNAL_POWER = 228792, //107 ?
    SPELL_CONCENTRATED_POWER = 228790, // 107 ?    

    // fly
    SPELL_RAIN_OF_BONES = 228839, // summon

    // add on the second ground
    SPELL_BELLOWING_ROAR = 228837,

};

enum eEvents
{
    EVENT_CINDER_BREATH = 1,
    EVENT_IGNITE_SOUL = 2,
    EVENT_REVERBERATING_SHADOWS = 3,
    EVENT_CHARRED_GROUND = 4,
    EVENT_BURNING = 5,
    EVENT_TAIL = 6,
    EVENT_POWER_1 = 7,
    EVENT_POWER = 8,
    EVENT_ROAR = 9,

};

enum eText
{
    SAY_AGGRO = 2,
    SAY_SOUL = 3,
    SAY_SOUL_1 = 4,
    SAY_FLY = 5,
    SAY_GROUND = 6,
    SAY_ROAR = 7,
    SAY_BURNING = 8,
    SAY_DEATH = 9
};

// 114895
class boss_rtk_nightbane : public CreatureScript
{
public:
    boss_rtk_nightbane() : CreatureScript("boss_rtk_nightbane") {}

    struct boss_rtk_nightbaneAI : public BossAI
    {
        boss_rtk_nightbaneAI(Creature* creature) : BossAI(creature, DATA_NIGHTBANE) {}

        bool flyphase;
        void Reset() override
        {
            _Reset();
            flyphase = false;

            events.Reset();
            me->SetCanFly(false);
            me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
            me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
            me->RemoveUnitFlag(UNIT_FLAG_NOT_ATTACKABLE_1);
            me->SetReactState(REACT_AGGRESSIVE);
            instance->DoRemoveAurasDueToSpellOnPlayers(228834);
            me->RemoveAllAreaObjects();
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO);
            _JustEngagedWith();

            DefaultEvents(1);
            flyphase = false;
        }

        void EnterEvadeMode(EvadeReason w)
        {
            BossAI::EnterEvadeMode();
            instance->SetBossState(DATA_NIGHTBANE, SPECIAL);
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();
            Talk(SAY_DEATH);
            instance->DoRemoveAurasDueToSpellOnPlayers(228834);
            me->RemoveAllAreaObjects();
        }

        void DefaultEvents(uint8 phase)
        {
            switch (phase)
            {
            case 2:
                events.RescheduleEvent(EVENT_ROAR, 20000);
                // no break
            case 1:
                events.RescheduleEvent(EVENT_CINDER_BREATH, 8000);
                events.RescheduleEvent(EVENT_IGNITE_SOUL, 20000);
                events.RescheduleEvent(EVENT_REVERBERATING_SHADOWS, 17000);
                events.RescheduleEvent(EVENT_CHARRED_GROUND, 3000);
                events.RescheduleEvent(EVENT_BURNING, 19000);
                events.RescheduleEvent(EVENT_TAIL, 12000);

                events.RescheduleEvent(EVENT_POWER, 30000);
                events.RescheduleEvent(EVENT_POWER_1, 53000);
                break;
            }
        }

        void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
        {
            if (summon->GetEntry() != 114903)
                return;

            me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
            me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
            me->RemoveUnitFlag(UNIT_FLAG_NOT_ATTACKABLE_1);
            me->SetReactState(REACT_AGGRESSIVE);
            DefaultEvents(2);
            Talk(SAY_GROUND);
            me->SetCanFly(false);
            me->GetMotionMaster()->MovePoint(0, me->GetPositionX(), me->GetPositionY(), 91.4f);
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage)
        {
            if (!flyphase && me->HealthBelowPct(50))
            {
                flyphase = true;
                events.Reset();
                Talk(SAY_FLY);
                me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
                me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_NPC);
                me->SetUnitFlags(UNIT_FLAG_NOT_ATTACKABLE_1);
                me->SetCanFly(true);
                me->SetReactState(REACT_PASSIVE);
                me->GetMotionMaster()->MovePoint(1, me->GetPositionX(), me->GetPositionY(), 111.0f);
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == POINT_MOTION_TYPE && id == 1)
                DoCast(SPELL_RAIN_OF_BONES);
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
                case EVENT_CINDER_BREATH:
                    DoCast(SPELL_CINDER_BREATH);
                    events.RescheduleEvent(EVENT_CINDER_BREATH, 20000);
                    break;
                case EVENT_IGNITE_SOUL:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 70.0f, true))
                    {
                        me->CastSpell(target, SPELL_IGNITE_SOUL);
                        Talk(SAY_SOUL, target);
                        Talk(SAY_SOUL_1);
                    }
                    events.RescheduleEvent(EVENT_IGNITE_SOUL, 25000);
                    break;
                case EVENT_REVERBERATING_SHADOWS:
                    DoCast(SPELL_REVERBERATING_SHADOWS);
                    events.RescheduleEvent(EVENT_REVERBERATING_SHADOWS, 13000);
                    break;
                case EVENT_BURNING:
                    DoCast(SPELL_BURNING_BONES);
                    Talk(SAY_BURNING);
                    events.RescheduleEvent(EVENT_BURNING, 18000);
                    break;
                case EVENT_TAIL:
                    DoCast(SPELL_TAIL_SWIPE);
                    events.RescheduleEvent(EVENT_TAIL, 12000);
                    break;
                case EVENT_CHARRED_GROUND:
                    DoCast(SPELL_CHARRED_GROUND_TICK);
                    break;
                case EVENT_ROAR:
                    DoCast(SPELL_BELLOWING_ROAR);
                    Talk(SAY_ROAR);
                    events.RescheduleEvent(EVENT_ROAR, 42000);
                    break;

                case EVENT_POWER:
                    DoCast(SPELL_CONCENTRATED_POWER);
                    break;
                case EVENT_POWER_1:
                    DoCast(SPELL_INFERNAL_POWER);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_rtk_nightbaneAI(creature);
    }
};


// 115013, 115101, 115105, 115113, 115103
class npc_karazhan_part_of_soul : public CreatureScript
{
public:
    npc_karazhan_part_of_soul() : CreatureScript("npc_karazhan_part_of_soul") {}

    bool OnGossipHello(Player* clicker, Creature* me)
    {
        if (!clicker->IsPlayer())
            return false;

        me->RemoveNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);

        if (InstanceScript* instance = me->GetInstanceScript())
        {
            if (instance->GetData(DATA_TIMER_BONUS_BOSS) > 0)
            {
                instance->SetData(DATA_TIMER_BONUS_BOSS, 0);

                Map::PlayerList const& PlList = me->GetMap()->GetPlayers();
                if (PlList.getSize())
                {
                    for (Map::PlayerList::const_iterator i = PlList.begin(); i != PlList.end(); ++i)
                        if (Player* player = i->GetSource())
                        {
                            player->CastSpell(player, 229074, true);
                            if (player->GetAuraCount(229074) >= 5)
                                player->CastSpell(player, 229077, true);
                        }
                }
            }
        }
        return true;
    }
};

// 115038
class npc_karazhan_nighbane_starter : public CreatureScript
{
public:
    npc_karazhan_nighbane_starter() : CreatureScript("npc_karazhan_nighbane_starter") {}

    struct npc_karazhan_nighbane_starterAI : public ScriptedAI
    {
        npc_karazhan_nighbane_starterAI(Creature* creature) : ScriptedAI(creature) {}

        EventMap events;

        bool GossipSelect(Player* player, uint32 sender, uint32 action) override
        {
            if (!player->HasAura(229077))
                return true;

            if (player->GetGroup() && !player->GetGroup()->IsLeader(player->GetGUID()))
                return true;

            if (me->GetMap()->GetDifficultyID() != DIFFICULTY_MYTHIC)
                return true;

            Map::PlayerList const& PlList = me->GetMap()->GetPlayers();

            if (PlList.isEmpty())
                return true;

            for (Map::PlayerList::const_iterator i = PlList.begin(); i != PlList.end(); ++i)
                if (Player* pPlayer = i->GetSource())
                    pPlayer->CastSpell(pPlayer, 232663); // achieve

            me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
            if (Creature* nightbane = me->SummonCreature(115213, -11170.30f, -1868.32f, 106.51f, 5.37f, TEMPSUMMON_DEAD_DESPAWN))
            {
                nightbane->SetCanFly(true);
                nightbane->AI()->Talk(0);
                Talk(1);
                nightbane->AI()->Talk(1);
                Talk(2);
                nightbane->AI()->Talk(2);
                Talk(3);
                nightbane->AI()->Talk(3);

                me->CastSpell(nightbane, 30971);
                nightbane->CastSpell(nightbane, 30969);

                nightbane->CastSpell(me, 30971);
                me->CastSpell(me, 30973);
                nightbane->CastSpell(me, 30930);
                me->CastSpell(me, 15041);


                me->CastSpell(me, 30972);
                Talk(4);

                me->RemoveAura(30972);
                me->CastSpell(nightbane, 30977);
                nightbane->AI()->Talk(4);
                nightbane->GetMotionMaster()->MovePoint(0, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ());

                me->SetWalk(true);
                me->GetMotionMaster()->MovePoint(0, -11115.24f, -1885.48f, 91.47f);
                me->DespawnOrUnsummon(4000);

                nightbane->CastSpell(nightbane, 229226);
                nightbane->DespawnOrUnsummon(3000);

                nightbane->CastSpell(nightbane, 229226);
                nightbane->DespawnOrUnsummon(3000);

            }

            return true;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_karazhan_nighbane_starterAI(creature);
    }
};

// 228800
class spell_nightbane_ignite_soul : public SpellScriptLoader
{
public:
    spell_nightbane_ignite_soul() : SpellScriptLoader("spell_nightbane_ignite_soul") { }

    class spell_nightbane_ignite_soul_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_nightbane_ignite_soul_SpellScript);

        void HandleDamage(SpellEffIndex /*effIndex*/)
        {
            if (GetExplTargetUnit())
                SetHitDamage(GetExplTargetUnit()->GetHealth());
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_nightbane_ignite_soul_SpellScript::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_nightbane_ignite_soul_SpellScript();
    }
};

void AddSC_boss_nightbane_new()
{
    new boss_rtk_nightbane();
    new npc_karazhan_part_of_soul();
    new npc_karazhan_nighbane_starter();
    new spell_nightbane_ignite_soul();
};
