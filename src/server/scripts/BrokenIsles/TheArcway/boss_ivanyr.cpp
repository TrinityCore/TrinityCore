#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "the_arcway.h"
#include "AreaTriggerTemplate.h"
#include "G3D/LineSegment.h"

enum Spells
{
    SPELL_OVERCHARGE_MANA   = 196392,
    SPELL_OVERCHARGE        = 196396,
    SPELL_CHARGED_BOLT_AURA = 220581,
    SPELL_CHARGED_BOLT_DMG  = 220597,
    SPELL_CHARGED_BOLT_AREA = 220569,
    SPELL_ARCANE_BLAST      = 196357,
    SPELL_VOLATILE_MAGIC    = 196562,
    SPELL_NETHER_LINK       = 196804,
    SPELL_NETHER_LINK_VISUAL= 196805,
    SPELL_NETHER_LINK_AREA  = 196806,
    SPELL_NETHER_LINK_DMG   = 196824, 
};

enum Events
{
    EVENT_OVERCHARGE_MANA   = 1,
    EVENT_ARCANE_BLAST      = 2,
    EVENT_VOLATILE_MAGIC    = 3,
    EVENT_NETHER_LINK       = 4,
};

enum Says
{
    SAY_INTRO           = 0,
    SAY_AGGRO           = 1,
    SAY_VOLATILE_MAGIC  = 2,
    SAY_KILL            = 3,
    SAY_DEATH           = 4,
    SAY_OVERCHARGUE     = 5,
};

enum Data
{
    DATA_NETHER_LINK_VERTEX_ONE     = 1,
    DATA_NETHER_LINK_VERTEX_TWO     = 2,
    DATA_NETHER_LINK_VERTEX_THREE   = 3,
};

enum Actions
{
    ACTION_INTERRUPT_OVERCHARGE = 1,
    ACTION_CREATE_TRIANGLE      = 2,
};

constexpr uint32 POINT_OVERCHARGE               = 1;
constexpr uint32 NPC_NIGHT_CRYSTAL              = 98734;
constexpr uint32 SPELL_VISUAL_OVERCHARGE        = 51100;

using G3D::Vector2;
using G3D::LineSegment2D;

class boss_ivanyr : public CreatureScript
{
    public:
        boss_ivanyr() : CreatureScript("boss_ivanyr")
        {}

        struct boss_ivanyr_AI : public BossAI
        {
            explicit boss_ivanyr_AI(Creature* creature) : BossAI(creature, DATA_IVANYR)
            {
                _vertexsGuid.fill(ObjectGuid::Empty);
                _vertexs.fill(Vector2(0,0));
            }

            void EnterCombat(Unit* /**/) override
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                me->SetReactState(REACT_AGGRESSIVE);
                Talk(SAY_AGGRO);
                events.ScheduleEvent(EVENT_ARCANE_BLAST, IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_VOLATILE_MAGIC, Seconds(15));
                events.ScheduleEvent(EVENT_NETHER_LINK, Seconds(25));
                events.ScheduleEvent(EVENT_OVERCHARGE_MANA, Seconds(30));
            }

            void JustRegisteredAreaTrigger(AreaTrigger* at) override
            {
                if (!at)
                    return;

             // auto & vertices = at->_polygonVertices;
                uint8 index = 0;

            //  for (auto & it :  vertices)
           //       it = _vertexs.at(index++);
            }

            void SetGUID(ObjectGuid guid, int32 id) override
            {
                switch (id)
                {
                    case DATA_NETHER_LINK_VERTEX_ONE:
                        _vertexsGuid.at(0) = guid;
                        break;
                    
                    case DATA_NETHER_LINK_VERTEX_TWO:
                        _vertexsGuid.at(1) = guid;
                        break;
                    
                    case DATA_NETHER_LINK_VERTEX_THREE:
                        _vertexsGuid.at(2) = guid;
                        break;
                }
            }

            ObjectGuid GetGUID(int32 id) const override
            {
                switch (id)
                {
                    case DATA_NETHER_LINK_VERTEX_ONE:
                        return _vertexsGuid.at(0);
                    
                    case DATA_NETHER_LINK_VERTEX_TWO:
                        return _vertexsGuid.at(1);
                        break;
                    
                    case DATA_NETHER_LINK_VERTEX_THREE:
                        return _vertexsGuid.at(2);

                    default : return ObjectGuid::Empty;
                }
            }

            void JustDied(Unit* /**/) override
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                Creature* crystal = me->FindNearestCreature(NPC_NIGHT_CRYSTAL, 500.f);

                if (crystal)
                {
                    crystal->RemoveAllAuras();
                    crystal->RemoveAllAreaTriggers();
                }
                
                Talk(SAY_DEATH);
                _JustDied();
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim && victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_KILL);
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type == POINT_MOTION_TYPE && id == POINT_OVERCHARGE)
                {
                    Talk(SAY_OVERCHARGUE);
                    Creature* crystal = me->FindNearestCreature(NPC_NIGHT_CRYSTAL, 500.f);
                    
                    if (crystal)
                    {
                        me->SetFacingToObject(crystal);
                        me->CastSpell(crystal, SPELL_OVERCHARGE_MANA, false);
                    }
                }
            }

            void DoAction(int32 action) override
            {
                if (action == ACTION_INTERRUPT_OVERCHARGE)
                {
                    events.ScheduleEvent(EVENT_ARCANE_BLAST, IN_MILLISECONDS);
                    events.ScheduleEvent(EVENT_VOLATILE_MAGIC, Seconds(15));
                    events.ScheduleEvent(EVENT_NETHER_LINK, Seconds(18));
                }
                else if (action == ACTION_CREATE_TRIANGLE && !_triangleCreated)
                {
                    _triangleCreated = true;

                    Player* targetOne = ObjectAccessor::GetPlayer(*me, _vertexsGuid.at(0));
                    Player* targetTwo = ObjectAccessor::GetPlayer(*me, _vertexsGuid.at(1));
                    Player* targetThree = ObjectAccessor::GetPlayer(*me, _vertexsGuid.at(2));

                    if (!targetOne || !targetTwo || !targetThree)
                        return;
                    
                    G3D::Vector2 v1 = { targetOne->GetPositionX(),  targetOne->GetPositionY()};
                    G3D::Vector2 v2 = { targetTwo->GetPositionX(),  targetTwo->GetPositionY()};
                    G3D::Vector2 v3 = { targetThree->GetPositionX(), targetThree->GetPositionY()};
                    G3D::Vector2 mid_1 = (v1 + v2)/2;
                    Vector2 mid_two = (v1 + v3)/2;
                    Vector2 mid_three = (v2 + v3)/2;

                    LineSegment2D median_1 = LineSegment2D::fromTwoPoints(mid_1, v3);
                    LineSegment2D median_2 = LineSegment2D::fromTwoPoints(mid_two, v2);
                    LineSegment2D median_3 = LineSegment2D::fromTwoPoints(mid_three, v1);

                    Vector2 interPoint_1 = median_1.intersection(median_2);


                    auto & center = interPoint_1;
                    _vertexs.at(0) = v3 - center;
                    _vertexs.at(1) = v2 - center;
                    _vertexs.at(2) = v3 - center;

                    me->CastSpell(center.x, center.y, me->GetPositionZ(), SPELL_NETHER_LINK_AREA, true);

                }
            }

            void SpellHit(Unit* /**/, SpellInfo const* spell) override
            {
                if (!spell)
                    return;
                
                if (spell->HasEffect(SPELL_EFFECT_INTERRUPT_CAST))
                {
                    Spell* currSpell = me->GetCurrentSpell(CURRENT_CHANNELED_SPELL);

                 // if (currSpell && currSpell->GetSpellInfo()->Id == SPELL_OVERCHARGE_MANA)
                    {
                        me->CastStop();
                        DoAction(ACTION_INTERRUPT_OVERCHARGE);
                    }
                }
            }

            void EnterEvadeMode(EvadeReason why) override
            {
                Creature* crystal = me->FindNearestCreature(NPC_NIGHT_CRYSTAL, 500.f);

                if (crystal)
                {
                    crystal->RemoveAllAuras();
                    crystal->RemoveAllAreaTriggers();
                }
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                CreatureAI::EnterEvadeMode();
            }

            void ExecuteEvent(uint32 eventId) override
            {
           //   me->GetSpellHistory()->ResetAllCooldowns();
                switch (eventId)
                {
                    case EVENT_ARCANE_BLAST:
                    {
                        DoCastVictim(SPELL_ARCANE_BLAST);
                        events.ScheduleEvent(EVENT_ARCANE_BLAST, 2 * IN_MILLISECONDS);
                        break;
                    }

                    case EVENT_NETHER_LINK:
                    {
                        _triangleCreated = false;
                        DoCast(me, SPELL_NETHER_LINK);
                        events.ScheduleEvent(EVENT_NETHER_LINK, Seconds(30));
                        break;
                    }

                    case EVENT_OVERCHARGE_MANA:
                    {
                        events.DelayEvents(Seconds(5));
                        me->GetMotionMaster()->MovePoint(POINT_OVERCHARGE, me->GetHomePosition());
                        events.ScheduleEvent(EVENT_OVERCHARGE_MANA, Seconds(45));
                        break;
                    }

                    case EVENT_VOLATILE_MAGIC:
                    {
                        Talk(SAY_VOLATILE_MAGIC);
                        DoCast(me, SPELL_VOLATILE_MAGIC);
                        events.ScheduleEvent(EVENT_VOLATILE_MAGIC, Seconds(30));
                        break;
                    }
                    
                }
            }

            private:
                std::array<Vector2, 3> _vertexs;
                std::array<ObjectGuid, 3> _vertexsGuid;
                bool _triangleCreated;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_ivanyr_AI(creature);
        }
};

class spell_ivanyr_nether_link : public SpellScriptLoader
{
    public:
        spell_ivanyr_nether_link() : SpellScriptLoader("spell_ivanyr_nether_link")
        {}

        class spell_nether_link_SpellScript : public SpellScript
        {
            public:
                PrepareSpellScript(spell_nether_link_SpellScript);

                bool Load() override
                {
                    _playerCounter = 0;
                    return true;
                }

                void HandleOnCast()
                {
                    std::list<ObjectGuid> _guids;
                    std::list<Player*> players;
                    
                    GetCaster()->GetPlayerListInGrid(players, 250.f);

                    if (!players.empty())
                    {
                        for (auto & it : players)
                        {
                            if (_guids.size() >= 3)
                                break;

                            if (it)
                                _guids.push_back(it->GetGUID());
                        }
                    }

                    for (auto & it : _guids)
                    {
                        Player* ptr = ObjectAccessor::GetPlayer(*GetCaster(), it);
                        
                        if (!ptr)
                            continue;
                            
                        GetCaster()->AddAura(SPELL_NETHER_LINK_VISUAL, ptr);
                        G3D::Vector3 pos = { ptr->GetPositionX(), ptr->GetPositionY(), ptr->GetPositionZ() };
                     // ptr->SendPlaySpellVisual(pos, 39597, 0, 0, 34, false);

                        switch (_playerCounter++)
                        {
                            case 0:
                                GetCaster()->GetAI()->SetGUID(ptr->GetGUID(), DATA_NETHER_LINK_VERTEX_ONE);
                                break;
                            
                            case 1:
                                GetCaster()->GetAI()->SetGUID(ptr->GetGUID(), DATA_NETHER_LINK_VERTEX_TWO);
                                break;
                            
                            case 2:
                                GetCaster()->GetAI()->SetGUID(ptr->GetGUID(), DATA_NETHER_LINK_VERTEX_THREE);
                                break;

                            default : break;
                        }

                        if (_playerCounter >= 3)
                            break;
                    }

                }

                void Register() override
                {
                    OnCast += SpellCastFn(spell_nether_link_SpellScript::HandleOnCast);
                }

                private:
                    uint8 _playerCounter;
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_nether_link_SpellScript();
        }
};

class spell_ivanyr_nether_link_dmg : public SpellScriptLoader
{
    public:
        spell_ivanyr_nether_link_dmg() : SpellScriptLoader("spell_ivanyr_nether_link_dmg")
        {}
        
        class spell_nether_link_dmg_AuraScript : public AuraScript
        {
            public:
                PrepareAuraScript(spell_nether_link_dmg_AuraScript);

                void HandleOnRemove(AuraEffect const* /**/, AuraEffectHandleModes /**/)
                {
                    if (GetCaster()->GetTypeId() != TYPEID_PLAYER)
                        GetCaster()->GetAI()->DoAction(ACTION_CREATE_TRIANGLE);
                }

                void Register() override
                {
                    OnEffectRemove += AuraEffectRemoveFn(spell_nether_link_dmg_AuraScript::HandleOnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
                }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_nether_link_dmg_AuraScript();
        }
};

class spell_ivanyr_overcharge_mana : public SpellScriptLoader
{
    public:
        spell_ivanyr_overcharge_mana() : SpellScriptLoader("spell_ivanyr_overcharge_mana")
        {}

        class spell_overcharge_mana_AuraScript : public AuraScript
        {
            public:
                PrepareAuraScript(spell_overcharge_mana_AuraScript);

                void HandlePeriodic(AuraEffect const* /**/)
                {
                    GetUnitOwner()->SendPlaySpellVisual(GetCaster()->GetGUID(), SPELL_VISUAL_OVERCHARGE, 0, 0, 1, true);
                    GetCaster()->CastSpell(GetCaster(), SPELL_OVERCHARGE, true);
                }

                void HandleOnRemove(AuraEffect const* /**/, AuraEffectHandleModes /**/)
                {
                    if (!GetUnitOwner())
                        return;

                    if (AuraEffect* auraEff = GetUnitOwner()->GetAuraEffect(SPELL_CHARGED_BOLT_AURA, EFFECT_0))
                  //    auraEff->SetPeriodicTimer(auraEff->GetPeriodicTimer() > 250 ? auraEff->GetPeriodicTimer() - 250 : 250);
                  //else
                        GetUnitOwner()->CastSpell(GetUnitOwner(), SPELL_CHARGED_BOLT_AURA, true);

                    if (auto* ptr = GetCaster()->ToCreature())
                        ptr->GetAI()->DoAction(ACTION_INTERRUPT_OVERCHARGE);
                }

                void Register() override
                {
                    OnEffectRemove += AuraEffectRemoveFn(spell_overcharge_mana_AuraScript::HandleOnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
                    OnEffectPeriodic += AuraEffectPeriodicFn(spell_overcharge_mana_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
                }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_overcharge_mana_AuraScript();
        }
};

class spell_ivanyr_charged_bolt : public SpellScriptLoader
{
    public:
        spell_ivanyr_charged_bolt() : SpellScriptLoader("spell_ivanyr_charged_bolt")
        {}

        class spell_charged_bolt_AuraScript : public AuraScript
        {
            public:
                PrepareAuraScript(spell_charged_bolt_AuraScript);

                void HandlePeriodic(AuraEffect const* /**/)
                {
                    GetCaster()->CastSpell(GetCaster(), SPELL_CHARGED_BOLT_AREA, true);
                }

                void Register() override
                {
                    OnEffectPeriodic += AuraEffectPeriodicFn(spell_charged_bolt_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
                }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_charged_bolt_AuraScript();
        }
};

class at_arc_charged_bolt : public AreaTriggerEntityScript
{
    public:
        at_arc_charged_bolt() : AreaTriggerEntityScript("at_arc_charged_bolt")
        {}

        struct at_arc_charged_bolt_AI : public AreaTriggerAI
        {
            explicit at_arc_charged_bolt_AI(AreaTrigger* at) : AreaTriggerAI(at)
            {}

            void SetupSpline()
            {
                if (!at->GetCaster())
                    return;

                std::vector<G3D::Vector3> points;
                float dist = 100.f;

                G3D::Vector3 src = { at->GetPositionX(), at->GetPositionY(), at->GetPositionZ() };
                G3D::Vector3 tgt;

                tgt.x = src.x + (dist * cosf(frand(3.93f, 6.20f)));
                tgt.y = src.y + (dist * sinf(frand(3.93f, 6.20f)));
                tgt.z = src.z;

                float dx = (tgt.x - src.x);
                float dy = (tgt.y - src.y);
                float dz = (tgt.z - src.z);

                for (uint32 i = 0; i < 100; ++i)
                {
                    src.x += (dx/dist);
                    src.y += (dy/dist);

                    points.push_back(src);
                }

                at->InitSplines(points, at->GetDuration());
            }

            void OnInitialize() override
            {
                SetupSpline();
            }

            void OnUnitEnter(Unit* target) override
            {
                if (!target)
                    return;
                
                if (target->GetTypeId() != TYPEID_PLAYER)
                    return;
                
                target->CastSpell(target, SPELL_CHARGED_BOLT_DMG, true);
            }

            void OnUnitExit(Unit* target) override
            {
                if (!target)
                    return;
                
                if (target->GetTypeId() != TYPEID_PLAYER)
                    return;
                
                target->RemoveAurasDueToSpell(SPELL_CHARGED_BOLT_DMG);
            }
        };

        AreaTriggerAI* GetAI(AreaTrigger* at) const override
        {
            return new at_arc_charged_bolt_AI(at);
        }
};

class at_arc_nether_link : public AreaTriggerEntityScript
{
    public:
        at_arc_nether_link() : AreaTriggerEntityScript("at_arc_nether_link")
        {}

        struct at_arc_nether_link_AI : public AreaTriggerAI
        {
            explicit at_arc_nether_link_AI(AreaTrigger* at) : AreaTriggerAI(at)
            {}

            void OnUnitEnter(Unit* target) override
            {
                if (target && target->GetTypeId() == TYPEID_PLAYER)
                    target->CastSpell(target, SPELL_NETHER_LINK_DMG, true);
            }

            void OnUnitExit(Unit* target) override
            {
                if (target && target->GetTypeId() == TYPEID_PLAYER)
                    target->RemoveAurasDueToSpell(SPELL_NETHER_LINK_DMG);
            }
        };

        AreaTriggerAI* GetAI(AreaTrigger* at) const override
        {
            return new at_arc_nether_link_AI(at);
        }
};

void AddSC_boss_ivanyr()
{
    new boss_ivanyr();
    new spell_ivanyr_charged_bolt();
    new spell_ivanyr_overcharge_mana();
    new spell_ivanyr_nether_link();
    new spell_ivanyr_nether_link_dmg();
    new at_arc_charged_bolt();
    new at_arc_nether_link();
}
