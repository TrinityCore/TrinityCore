/*
    Dungeon : Mogu'shan palace 87-89
    Xin the weaponmaster
    Jade servers
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "mogu_shan_palace.h"

class boss_xin_the_weaponmaster : public CreatureScript
{
    public:
        boss_xin_the_weaponmaster() : CreatureScript("boss_xin_the_weaponmaster") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_xin_the_weaponmaster_AI(creature);
        }

        enum eEvents
        {
            EVENT_RING_OF_FIRE          = 1,
            EVENT_HEURT                 = 2,
            EVENT_INCITING_ROAR         = 3,
            EVENT_SWORD_THROWER         = 4,
            EVENT_SWORD_THROWER_STOP    = 5,
            EVENT_AXES_ACTIVATE         = 6,
            EVENT_AXES_DESACTIVATE      = 7
        };

        enum eSpells
        {
            SPELL_HEURT         = 119684,
            SPELL_INCITING_ROAR = 122959,
        };

        struct boss_xin_the_weaponmaster_AI : public BossAI
        {
            boss_xin_the_weaponmaster_AI(Creature* creature) : BossAI(creature, DATA_XIN_THE_WEAPONMASTER)
            {
                pInstance = creature->GetInstanceScript();
            }

            InstanceScript* pInstance;

            void Reset()
            {
                if (pInstance)
                {
                    pInstance->SetData(TYPE_ACTIVATE_SWORD, 0);
                    pInstance->SetData(TYPE_ACTIVATE_ANIMATED_AXE, 0);
                    pInstance->SetData(TYPE_ACTIVATE_ANIMATED_STAFF, 0);
                }

                events.Reset();
            }

            void JustDied(Unit* who)
            {
                if (pInstance)
                {
                    pInstance->SetData(TYPE_ACTIVATE_ANIMATED_AXE, 0);
                    pInstance->SetData(TYPE_ACTIVATE_SWORD, 0);
                    pInstance->SetData(TYPE_ACTIVATE_ANIMATED_STAFF, 0);
                    events.Reset();
                }
            }

            void EnterCombat(Unit* who)
            {
                events.ScheduleEvent(EVENT_RING_OF_FIRE, 3000);
                events.ScheduleEvent(EVENT_HEURT, urand(10000, 15000));
                events.ScheduleEvent(EVENT_INCITING_ROAR, urand(15000, 25000));
                events.ScheduleEvent(EVENT_SWORD_THROWER, 30000);
                events.ScheduleEvent(EVENT_AXES_ACTIVATE, 15000);
            }

            void UpdateAI(uint32 diff)
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
                        case EVENT_RING_OF_FIRE:
                            if (pInstance)
                                pInstance->SetData(TYPE_ACTIVATE_ANIMATED_STAFF, 0);
                            events.ScheduleEvent(EVENT_RING_OF_FIRE, 20000);
                            break;
                        case EVENT_HEURT:
                            me->CastSpell(me, SPELL_HEURT, false);
                            events.ScheduleEvent(EVENT_HEURT, urand(10000, 15000));
                            break;
                        case EVENT_INCITING_ROAR:
                            me->CastSpell(me, SPELL_INCITING_ROAR, false);
                            events.ScheduleEvent(EVENT_INCITING_ROAR, 30000);
                            break;
                        case EVENT_SWORD_THROWER:
                            if (pInstance)
                                pInstance->SetData(TYPE_ACTIVATE_SWORD, 1);
                            events.ScheduleEvent(EVENT_SWORD_THROWER_STOP, 10000);
                            break;
                        case EVENT_SWORD_THROWER_STOP:
                            if (pInstance)
                                pInstance->SetData(TYPE_ACTIVATE_SWORD, 0);
                            events.ScheduleEvent(EVENT_SWORD_THROWER, 20000);
                            break;
                        case EVENT_AXES_ACTIVATE:
                            if (pInstance)
                                pInstance->SetData(TYPE_ACTIVATE_ANIMATED_AXE, 1);

                            events.ScheduleEvent(EVENT_AXES_DESACTIVATE, 10000);
                            break;
                        case EVENT_AXES_DESACTIVATE:
                            if (pInstance)
                                pInstance->SetData(TYPE_ACTIVATE_ANIMATED_AXE, 0);

                            events.ScheduleEvent(EVENT_AXES_ACTIVATE, 15000);
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

class mob_animated_staff : public CreatureScript
{
    public:
        mob_animated_staff() : CreatureScript("mob_animated_staff") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_animated_staff_AI(creature);
        }

        enum eSpells
        {
            SPELL_RING_OF_FIRE_0 = 119544,
            SPELL_RING_OF_FIRE_1 = 119590,
        };

        enum eActions
        {
            ACTION_ACTIVATE,
        };

        enum eEvents
        {
            EVENT_SUMMON_RING_OF_FIRE = 1,
            EVENT_UNSUMMON = 2,
            EVENT_SUMMON_RING_TRIGGER = 3,
        };

        enum eCreatures
        {
            CREATURE_RING_OF_FIRE = 61499,
        };

        struct mob_animated_staff_AI : public ScriptedAI
        {
            mob_animated_staff_AI(Creature* creature) : ScriptedAI(creature)
            {
                me->SetDisplayId(42195);
                me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID, 76364);
                me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
            }

            EventMap events;
            float _x;
            float _y;
            float point;

            void Reset()
            {
                _x = 0.f;
                _y = 0.f;
                point = 0.f;

                me->AddAura(SPELL_PERMANENT_FEIGN_DEATH, me);

                Position home = me->GetHomePosition();
                me->GetMotionMaster()->MovePoint(0, home);
            }

            void EnterCombat(Unit* unit)
            {
            }

            void DoAction(int32 action)
            {
                switch (action)
                {
                    case ACTION_ACTIVATE:
                        me->RemoveAura(SPELL_PERMANENT_FEIGN_DEATH);
                        events.ScheduleEvent(EVENT_SUMMON_RING_OF_FIRE, 500);
                        break;
                }
            }

            void JustSummoned(Creature* summoned)
            {
                if (summoned->GetEntry() == CREATURE_RING_OF_FIRE)
                {
                    summoned->setFaction(14);
                    summoned->SetReactState(REACT_PASSIVE);
                    summoned->AddAura(SPELL_RING_OF_FIRE_0, summoned);
                }
            }

            void UpdateAI(uint32 diff)
            {
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SUMMON_RING_OF_FIRE:
                        {
                            events.ScheduleEvent(EVENT_UNSUMMON, 9000);
                            Unit* target = nullptr;
                            std::list<Unit*> units;

                            Map::PlayerList const& PlayerList = me->GetMap()->GetPlayers();
                            if (!PlayerList.isEmpty())
                                for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                                    if (Player* plr = i->GetSource())
                                        if (plr->IsAlive() && !plr->IsGameMaster())
                                            units.push_back(plr);

                            if (units.empty())
                                return;

                            target = Trinity::Containers::SelectRandomContainerElement(units);
                            if (!target)
                                return;

                            me->GetMotionMaster()->MovePoint(0, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ());
                            point = 0.0f;
                            _x = target->GetPositionX();
                            _y = target->GetPositionY();
                            events.ScheduleEvent(EVENT_SUMMON_RING_TRIGGER, 100);
                            break;
                        }
                        case EVENT_UNSUMMON:
                            Reset();
                            break;
                        case EVENT_SUMMON_RING_TRIGGER:
                        {
                            if (point >= 11)
                            {
                                if (TempSummon* tmp = me->SummonCreature(CREATURE_RING_OF_FIRE, _x, _y, me->GetMap()->GetHeight(0, _x, _y, me->GetPositionZ()), 0.0f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 10000))
                                {
                                    tmp->RemoveAura(SPELL_RING_OF_FIRE_0);
                                    tmp->CastSpell(tmp, SPELL_RING_OF_FIRE_1, false);
                                }
                                return;
                            }

                            float x = _x + 5.0f * cos(point * M_PI / 5);
                            float y = _y + 5.0f * sin(point * M_PI / 5);
                            me->SummonCreature(CREATURE_RING_OF_FIRE, x, y, me->GetMap()->GetHeight(0, x, y, me->GetPositionZ()), 0.0f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 10000);
                            ++point;
                            events.ScheduleEvent(EVENT_SUMMON_RING_TRIGGER, 400);
                            break;
                        }
                    }
                }
            }
        };
};

class OnlyTriggerInFrontPredicate
{
    public:
        OnlyTriggerInFrontPredicate(Unit* caster) : _caster(caster) {}

        bool operator()(WorldObject* target)
        {
            return target->GetEntry() != 59481 || !_caster->isInFront(target, M_PI / 5) || target->GetGUID() == _caster->GetGUID();
        }

    private:
        Unit* _caster;
};

class spell_dart : public SpellScriptLoader
{
    public:
        spell_dart() : SpellScriptLoader("spell_dart") { }

        class spell_dart_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dart_SpellScript);

            bool Validate(SpellInfo const* spell)
            {
                return true;
            }

            // set up initial variables and check if caster is creature
            // this will let use safely use ToCreature() casts in entire script
            bool Load()
            {
                return true;
            }

            void SelectTarget(std::list<WorldObject*>& targetList)
            {
                if (!GetCaster())
                    return;

                if (targetList.empty())
                {
                    FinishCast(SPELL_FAILED_NO_VALID_TARGETS);
                    return;
                }

                //Select the two targets.
                std::list<WorldObject*> targets = targetList;
                targetList.remove_if(OnlyTriggerInFrontPredicate(GetCaster()));

                //See if we intersect with any players.
                for (auto object : targets)
                    if (object->GetTypeId() == TYPEID_PLAYER)
                        for (auto trigger : targetList)
                            if (object->IsInBetween(GetCaster(), trigger, 2.0f))
                            {
                                const SpellInfo* damageSpell = sSpellMgr->GetSpellInfo(SPELL_THROW_DAMAGE);
                                GetCaster()->DealDamage(object->ToPlayer(), damageSpell->GetEffect(EFFECT_0)->BasePoints, 0, SPELL_DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, damageSpell);
                            }
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dart_SpellScript::SelectTarget, EFFECT_0, TARGET_SRC_CASTER);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dart_SpellScript::SelectTarget, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dart_SpellScript::SelectTarget, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dart_SpellScript::SelectTarget, EFFECT_0, TARGET_UNIT_CONE_ENEMY_104);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_dart_SpellScript();
        }
};

void AddSC_boss_xin_the_weaponmaster()
{
    new boss_xin_the_weaponmaster();
    new mob_animated_staff();
    new spell_dart();
}
