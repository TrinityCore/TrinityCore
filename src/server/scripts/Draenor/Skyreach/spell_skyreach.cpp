#include "instance_skyreach.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "ScriptMgr.h"
#include "Spell.h"
#include "SpellScript.h"
#include "SpellMgr.h"
#include "SpellAuraEffects.h"

// Summon Quills - 159381
class spell_quills_159381 : public SpellScriptLoader
{
public:
    spell_quills_159381() : SpellScriptLoader("spell_quills_159381") {   }

    enum class Spells : uint32
    {
        Quills = 156742,
    };

    class spell_quills_159381SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_quills_159381SpellScript)

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            Unit* l_Caster = GetCaster();
            if (l_Caster)
                l_Caster->CastSpell(l_Caster, uint32(Spells::Quills), true);
        }

        /// This method is used to filter the targets that are behind the big pillar, in the Rukhran event, when
        /// Rukhran is casting Quills (player should go behind the big pillar at the center of the platform to hide).
        void CheckTarget(std::list<WorldObject*>& p_UnitList)
        {
            p_UnitList.remove_if([this](WorldObject* p_Object)
            {
                /// p_Ref and p_Point should be vectors.
                auto l_IsToTheRightFromRef = [](Position const& p_Ref, Position const& p_Point) -> bool {
                    return p_Point.m_positionX * p_Ref.m_positionY - p_Point.m_positionY * p_Ref.m_positionX > 0;
                };

                /// Those both position are the extreme position of the pillar.
                /// The three position refers to those points. We want to check if the player
                /// is inside and far from the target for a certain distance.
                /// O---------------- L
                ///  \
                ///   \        Player
                ///    \      x
                ///     \
                ///      \
                ///       \
                ///        R
                static const Position s_OriginPosition = { 918.919f, 1913.459f, 213.0f, 0.0f };
                static const Position s_RightPosition = { 936.999f, 1872.137f, 213.0f, 0.0f };
                static const Position s_LeftPosition = { 951.305f, 1882.338f, 213.0f, 0.0f };

                Position l_RefLeftVect;// = s_LeftPosition. - s_OriginPosition;
                l_RefLeftVect = Position(s_LeftPosition.GetPositionX() - s_OriginPosition.GetPositionX(), s_LeftPosition.GetPositionY() - s_OriginPosition.GetPositionY(), s_LeftPosition.GetPositionZ() - s_OriginPosition.GetPositionZ());

                Position l_RefRightVect;// = s_RightPosition - s_OriginPosition;
                l_RefRightVect = Position(s_RightPosition.GetPositionX() - s_OriginPosition.GetPositionX(), s_RightPosition.GetPositionY() - s_OriginPosition.GetPositionY(), s_RightPosition.GetPositionZ() - s_OriginPosition.GetPositionZ());

                Position l_PlayerVect;// = *p_Object - s_OriginPosition;
                if (Unit* unit = p_Object->ToUnit())
                    l_PlayerVect = Position(unit->GetPosition().GetPositionX() - s_OriginPosition.GetPositionX(), unit->GetPosition().GetPositionY() - s_OriginPosition.GetPositionY(), unit->GetPosition().GetPositionZ() - s_OriginPosition.GetPositionZ());


                if (!l_IsToTheRightFromRef(l_RefLeftVect, l_PlayerVect) || l_IsToTheRightFromRef(l_RefRightVect, l_PlayerVect))
                    return false;

                if (GetCaster()->GetExactDist2d(p_Object) < 30.0f)
                    return false;

                return true;
            });
        }

        void Register()
        {
            OnEffectLaunch += SpellEffectFn(spell_quills_159381SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_quills_159381SpellScript::CheckTarget, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_quills_159381SpellScript();
    }
};

// Summon Cast Down - 165845
class spell_cast_down_165845 : public SpellScriptLoader
{
public:
    spell_cast_down_165845() : SpellScriptLoader("spell_cast_down_165845")  {  }

    enum class Spells : uint32
    {
        CastDown = 153955,
    };

    class spell_cast_down_165845SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_cast_down_165845SpellScript)

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (GetCaster() && GetHitUnit())
            {
                GetHitUnit()->CastSpell(GetHitUnit(), uint32(Spells::CastDown), true);
            }
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_cast_down_165845SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_cast_down_165845SpellScript();
    }
};

// AreaTriggers 1641 for spells: 154044
class at_lens_flare : public AreaTriggerEntityScript
{
    enum class Spells : uint32
    {
        LensFlare_Dmg = 154043,
    };

public:
    at_lens_flare() : AreaTriggerEntityScript("at_lens_flare") { }

    struct at_lens_flare_AI : public AreaTriggerAI
    {
        explicit at_lens_flare_AI(AreaTrigger* at) : AreaTriggerAI(at)
        {
            m_Targets.clear();
        }

        std::list<ObjectGuid> m_Targets;

        void OnRemove() override
        {
            for (auto l_Guid : m_Targets)
            {
                Unit* l_Target = ObjectAccessor::GetUnit(*at, l_Guid);
                if (l_Target && l_Target->HasAura(uint32(Spells::LensFlare_Dmg)))
                    l_Target->RemoveAura(uint32(Spells::LensFlare_Dmg));
            }
        }

        void OnUpdate(uint32 diff) override
        {
            std::list<Creature*> l_TargetList;
            float l_Radius = 3.5f;

            l_TargetList = at->FindAllUnfriendlyCreaturesInRange(l_Radius);

            std::list<ObjectGuid> l_ToRemove; // We need to do it in two phase, otherwise it will break iterators.
            for (auto l_Guid : m_Targets)
            {
                Unit* l_Target = ObjectAccessor::GetUnit(*at, l_Guid);
                if (l_Target && l_Target->GetExactDist2d(at) > l_Radius)
                {
                    if (l_Target->HasAura(uint32(Spells::LensFlare_Dmg)))
                    {
                        l_ToRemove.emplace_front(l_Guid);
                        l_Target->RemoveAura(uint32(Spells::LensFlare_Dmg));
                    }
                }
            }

            for (auto l_Guid : l_ToRemove)
            {
                m_Targets.remove(l_Guid);
            }

            for (Unit* l_Unit : l_TargetList)
            {
                if (!l_Unit || l_Unit->GetExactDist2d(at) > l_Radius || l_Unit->HasAura(uint32(Spells::LensFlare_Dmg)))
                    continue;

                at->GetCaster()->CastSpell(l_Unit, uint32(Spells::LensFlare_Dmg), true);
                m_Targets.emplace_front(l_Unit->GetGUID());

                // Achievement handling.
                if (Player* l_Plr = l_Unit->ToPlayer())
                {
                    // We check if the caster is Ranjit.
                    if (at->GetInstanceScript() && at->GetCaster()->GetEntry() == BossEntries::RANJIT)
                        at->GetInstanceScript()->SetGuidData(Data::PlayerIsHittedByRanjitSpells, l_Plr->GetGUID());
                }
            }
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* at) const override
    {
        return new at_lens_flare_AI(at);
    }
};

// AreaTriggers 1567  for spells: 152973
class at_protective_barrier : public AreaTriggerEntityScript
{
    enum class Spells : uint32
    {
        ProtectiveBarrier = 152975,
        ProtectiveBarrier_at = 152973,
    };

    std::list<ObjectGuid> m_Targets;

public:
    at_protective_barrier() : AreaTriggerEntityScript("at_protective_barrier"), m_Targets() {  }

    struct at_protective_barrier_AI : public AreaTriggerAI
    {
        explicit at_protective_barrier_AI(AreaTrigger* at) : AreaTriggerAI(at)
        {
            m_Targets.clear();
        }

        std::list<ObjectGuid> m_Targets;

        void OnRemove() override
        {
            for (auto l_Guid : m_Targets)
            {
                Unit* l_Target = ObjectAccessor::GetUnit(*at, l_Guid);
                if (l_Target && l_Target->HasAura(uint32(Spells::ProtectiveBarrier)))
                    l_Target->RemoveAura(uint32(Spells::ProtectiveBarrier));
            }
        }

        void OnUpdate(uint32 diff) override
        {
            std::list<Unit*> l_TargetList;
            float l_Radius = 30.0f;

            if (Unit* unit = at->GetCaster()->ToUnit())
                unit->GetFriendlyUnitListInRange(l_TargetList, l_Radius, true);

            std::list<ObjectGuid> l_ToRemove; // We need to do it in two phase, otherwise it will break iterators.
            for (auto l_Guid : m_Targets)
            {
                Unit* l_Target = ObjectAccessor::GetUnit(*at, l_Guid);
                if (l_Target && l_Target->GetExactDist2d(at) > l_Radius)
                {
                    if (l_Target->HasAura(uint32(Spells::ProtectiveBarrier)))
                    {
                        l_ToRemove.emplace_front(l_Guid);
                        l_Target->RemoveAura(uint32(Spells::ProtectiveBarrier));
                    }
                }
            }

            for (auto l_Guid : l_ToRemove)
            {
                m_Targets.remove(l_Guid);
            }

            for (Unit* l_Unit : l_TargetList)
            {
                if (!l_Unit
                    || l_Unit->GetExactDist2d(at) > l_Radius
                    || l_Unit->HasAura(uint32(Spells::ProtectiveBarrier))
                    || l_Unit->HasAura(uint32(Spells::ProtectiveBarrier_at)))
                    continue;

                at->GetCaster()->CastSpell(l_Unit, uint32(Spells::ProtectiveBarrier), true);
                m_Targets.emplace_front(l_Unit->GetGUID());
            }
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* at) const override
    {
        return new at_protective_barrier_AI(at);
    }
};

// AreaTriggers 1978 for spells: 154110
class at_smash : public AreaTriggerEntityScript
{
    enum class Spells : uint32
    {
        SMASH = 154110,
        SMASH_2 = 154113,
        SMASH_DMG = 154132,
    };

public:
    at_smash() : AreaTriggerEntityScript("at_smash") { }

    struct at_smash_AI : public AreaTriggerAI
    {
        explicit at_smash_AI(AreaTrigger* at) : AreaTriggerAI(at) { }

        void OnUpdate(uint32 diff) override
        {
            std::list<Creature*> l_TargetList;
            static const float k_Radius = 10.0f;
            static const float k_RadiusFromLine = 3.0f;

            l_TargetList = at->FindAllUnfriendlyCreaturesInRange(k_Radius);

            Position l_Pos;
            l_Pos = at->GetPosition();
            l_Pos.m_positionX += k_Radius * cos(at->GetOrientation());
            l_Pos.m_positionY += k_Radius * sin(at->GetOrientation());

            for (auto l_Target : l_TargetList)
            {
                if (l_Target && at->GetCaster()->isInFront(l_Target) && l_Target->GetExactDist2d(at) < k_Radius)//&& p_AreaTrigger->HasInLine(l_Pos, l_Target->GetObjectSize(), k_RadiusFromLine) && DistanceFromLine(*p_AreaTrigger, l_Pos, *l_Target) < k_RadiusFromLine
                {
                    if (at->GetCaster())
                        at->GetCaster()->CastSpell(l_Target, uint32(Spells::SMASH_DMG), true);
                }
            }
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* at) const override
    {
        return new at_smash_AI(at);
    }
};

// Visual Energize - 154177
class spell_visual_energize_154177 : public SpellScriptLoader
{
public:
    spell_visual_energize_154177() : SpellScriptLoader("spell_visual_energize_154177") {  }

    class spell_visual_energize_154177_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_visual_energize_154177_SpellScript)

        void CheckTarget(std::list<WorldObject*>& unitList)
        {
            Unit* l_Caster = GetCaster();
            unitList.remove_if([l_Caster](WorldObject* p_Obj) {
                if (!p_Obj->ToCreature())
                    return true;

                if (l_Caster->GetEntry() == 77543)
                    return p_Obj->ToCreature()->GetEntry() != 76367;
                else
                    return p_Obj->ToCreature()->GetEntry() != 76142;
            });
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_visual_energize_154177_SpellScript::CheckTarget, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_visual_energize_154177_SpellScript();
    }
};

// Visual Energize - 154159
class spell_visual_energize_154159 : public SpellScriptLoader
{
public:
    spell_visual_energize_154159() : SpellScriptLoader("spell_visual_energize_154159") {   }

    class spell_visual_energize_154159_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_visual_energize_154159_SpellScript)

        void CheckTarget(std::list<WorldObject*>& unitList)
        {
            Unit* l_Caster = GetCaster();
            unitList.remove_if([l_Caster](WorldObject* p_Obj) {
                return !(p_Obj->ToCreature()
                    && p_Obj->ToCreature()->GetEntry() == 76142
                    && p_Obj->ToCreature()->GetCurrentSpell(CURRENT_CHANNELED_SPELL));
            });
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_visual_energize_154159_SpellScript::CheckTarget, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_visual_energize_154159_SpellScript();
    }
};

// Flash Bang - 160066
class spell_flash_bang : public SpellScriptLoader
{
public:
    spell_flash_bang() : SpellScriptLoader("spell_flash_bang") {  }

    enum class Spells : uint32
    {
    };

    class spell_flash_bangSpellScript : public SpellScript
    {
        PrepareSpellScript(spell_flash_bangSpellScript)

        void CheckTarget(std::list<WorldObject*>& unitList)
        {
            Unit* l_Caster = GetCaster();
            unitList.remove_if([l_Caster](WorldObject* p_Obj) {
                return !p_Obj->isInFront(l_Caster);
            });
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_flash_bangSpellScript::CheckTarget, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_flash_bangSpellScript::CheckTarget, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_flash_bangSpellScript::CheckTarget, EFFECT_2, TARGET_UNIT_SRC_AREA_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_flash_bangSpellScript();
    }
};

// Sunstrike - 153828
class spell_sunstrike : public SpellScriptLoader
{
public:
    spell_sunstrike() : SpellScriptLoader("spell_sunstrike") {  }

    class spell_sunstrikeSpellScript : public SpellScript
    {
        PrepareSpellScript(spell_sunstrikeSpellScript)

        void CheckTargetIn(std::list<WorldObject*>& unitList)
        {
            Unit* l_Caster = GetCaster();
            unitList.remove_if([l_Caster](WorldObject* p_Obj) {
                return p_Obj->GetExactDist2d(l_Caster) > 10.0f;
            });
        }

        void CheckTargetOut(std::list<WorldObject*>& unitList)
        {
            Unit* l_Caster = GetCaster();
            unitList.remove_if([l_Caster](WorldObject* p_Obj) {
                return p_Obj->GetExactDist2d(l_Caster) < 10.0f;
            });
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sunstrikeSpellScript::CheckTargetIn, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sunstrikeSpellScript::CheckTargetOut, EFFECT_2, TARGET_UNIT_DEST_AREA_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_sunstrikeSpellScript();
    }
};

// Summon Solar Flare - 153827
class spell_summon_solar_flare : public SpellScriptLoader
{
public:
    spell_summon_solar_flare() : SpellScriptLoader("spell_summon_solar_flare") {  }

    class spell_summon_solar_flareSpellScript : public SpellScript
    {
        PrepareSpellScript(spell_summon_solar_flareSpellScript)

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (GetCaster())
            {
                Position l_Position;
                l_Position = GetSpell()->m_targets.GetObjectTarget()->GetPosition();
                GetCaster()->SummonCreature(MobEntries::SOLAR_FLARE, l_Position);
            }
        }

        void Register()
        {
            OnEffectHit += SpellEffectFn(spell_summon_solar_flareSpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_summon_solar_flareSpellScript();
    }
};

// Energize 154140
class spell_energize : public SpellScriptLoader
{
public:
    spell_energize() : SpellScriptLoader("spell_energize") {  }

    enum class Spells : uint32
    {
        ENERGIZE = 154139, // During 12 seconds, restart after 3 seconds.
        ENERGIZE_HEAL = 154149,
        ENERGIZE_DMG = 154150,
        ENERGIZE_VISUAL_1 = 154179,
    };

    class spell_energizeSpellScript : public SpellScript
    {
        PrepareSpellScript(spell_energizeSpellScript)

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (Unit* l_Caster = GetCaster())
                l_Caster->CastSpell(l_Caster, uint32(Spells::ENERGIZE_HEAL));
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_energizeSpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_energizeSpellScript();
    }
};

// AreaTriggers 2144 for spells: 159221
class at_solar_storm : public AreaTriggerEntityScript
{
    enum class Spells : uint32
    {
        SOLAR_STORM_DMG = 159226,
    };

public:
    at_solar_storm() : AreaTriggerEntityScript("at_solar_storm") {  }

    struct at_solar_storm_AI : public AreaTriggerAI
    {
        explicit at_solar_storm_AI(AreaTrigger* at) : AreaTriggerAI(at)
        {
            m_Targets.clear();
        }

        std::list<ObjectGuid> m_Targets;

        void OnRemove() override
        {
            for (auto l_Guid : m_Targets)
            {
                Unit* l_Target = ObjectAccessor::GetUnit(*at, l_Guid);
                if (l_Target && l_Target->HasAura(uint32(Spells::SOLAR_STORM_DMG)))
                    l_Target->RemoveAura(uint32(Spells::SOLAR_STORM_DMG));
            }
        }

        void OnUpdate(uint32 diff) override
        {
            std::list<Creature*> l_TargetList;
            float l_Radius = 4.0f;

            l_TargetList = at->FindAllUnfriendlyCreaturesInRange(l_Radius);


            std::list<ObjectGuid> l_ToRemove; // We need to do it in two phase, otherwise it will break iterators.
            for (auto l_Guid : m_Targets)
            {
                Unit* l_Target = ObjectAccessor::GetUnit(*at, l_Guid);
                if (l_Target && l_Target->GetExactDist2d(at) > l_Radius)
                {
                    if (l_Target->HasAura(uint32(Spells::SOLAR_STORM_DMG)))
                    {
                        l_ToRemove.emplace_front(l_Guid);
                        l_Target->RemoveAura(uint32(Spells::SOLAR_STORM_DMG));
                    }
                }
            }

            for (auto l_Guid : l_ToRemove)
            {
                m_Targets.remove(l_Guid);
            }

            for (Unit* l_Unit : l_TargetList)
            {
                if (!l_Unit || l_Unit->GetExactDist2d(at) > l_Radius || l_Unit->HasAura(uint32(Spells::SOLAR_STORM_DMG)))
                    continue;

                at->GetCaster()->CastSpell(l_Unit, uint32(Spells::SOLAR_STORM_DMG), true);
                m_Targets.emplace_front(l_Unit->GetGUID());
            }
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* at) const override
    {
        return new at_solar_storm_AI(at);
    }
};

// Solar storm - 159215
class spell_solar_storm : public SpellScriptLoader
{
public:
    spell_solar_storm() : SpellScriptLoader("spell_solar_storm") {  }

    enum class Spells : uint32
    {
        SOLAR_STORM = 159215, // FIXME.
        SOLAR_STORM_1 = 159216,
        SOLAR_STORM_2 = 159218,
        SOLAR_STORM_3 = 159221,
        SOLAR_STORM_4 = 159226,
    };

    class spell_solar_storm_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_solar_storm_SpellScript)

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (GetHitUnit() && GetCaster())
                GetCaster()->CastSpell(GetHitUnit(), uint32(Spells::SOLAR_STORM_1), true);
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_solar_storm_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_solar_storm_SpellScript();
    }
};

// AreaTriggers 1881,1883 for spells: 156634, 156636
class at_four_winds : public AreaTriggerEntityScript
{
    enum class Spells : uint32
    {
        // Four winds. Arrived after 2 or 3 instances of WindWall.
        FOUR_WINDS = 156793,
        FOUR_WINDS_DMG = 153139,
        FOUR_WINDS_AT_1 = 156634,
        FOUR_WINDS_AT_2 = 156636,
        FOUR_WINDS_VISUAL_1 = 166623,
        FOUR_WINDS_VISUAL_2 = 166664
    };
public:
    at_four_winds() : AreaTriggerEntityScript("at_four_winds") {  }

    struct at_four_winds_AI : public AreaTriggerAI
    {
        explicit at_four_winds_AI(AreaTrigger* at) : AreaTriggerAI(at)
        {
            m_targets.clear();
            m_angle = 0;
            m_Last = 60000;
            m_IsSpellAt2 = 0;
        }

        float m_angle;
        std::list<ObjectGuid> m_targets;
        uint32 m_Last;
        uint32 m_IsSpellAt2;

        bool IsInWind(Unit const* p_Unit, AreaTrigger const* p_Area) const
        {
            static const float k_Radius = 3.0f;

            float l_x1 = p_Area->GetPositionX() + cos(m_angle);
            float l_x2 = p_Area->GetPositionX() + cos(m_angle - M_PI);
            float l_y1 = p_Area->GetPositionY() + sin(m_angle);
            float l_y2 = p_Area->GetPositionY() + sin(m_angle - M_PI);

            float l_dx = l_x2 - l_x1;
            float l_dy = l_y2 - l_y1;

            bool l_b1 = std::abs(l_dy * p_Unit->GetPositionX() - l_dx * p_Unit->GetPositionY() - l_x1 * l_y2 + l_x2 * l_y1) / std::sqrt(l_dx * l_dx + l_dy * l_dy) < k_Radius;

            l_x1 = p_Area->GetPositionX() + cos(m_angle + M_PI / 2);
            l_x2 = p_Area->GetPositionX() + cos(m_angle - M_PI / 2);
            l_y1 = p_Area->GetPositionY() + sin(m_angle + M_PI / 2);
            l_y2 = p_Area->GetPositionY() + sin(m_angle - M_PI / 2);

            l_dx = l_x2 - l_x1;
            l_dy = l_y2 - l_y1;

            bool l_b2 = std::abs(l_dy * p_Unit->GetPositionX() - l_dx * p_Unit->GetPositionY() - l_x1 * l_y2 + l_x2 * l_y1) / std::sqrt(l_dx * l_dx + l_dy * l_dy) < k_Radius;

            return l_b1 || l_b2;
        }

        void OnRemove() override
        {
            for (auto l_Guid : m_targets)
            {
                Unit* l_Target = ObjectAccessor::GetUnit(*at, l_Guid);
                if (l_Target && l_Target->HasAura(uint32(Spells::FOUR_WINDS_DMG)))
                {
                    l_Target->RemoveAura(uint32(Spells::FOUR_WINDS_DMG));
                }
            }
        }

        void OnCreate() override
        {
            m_IsSpellAt2 = at->GetSpellId() == uint32(Spells::FOUR_WINDS_AT_2);
            m_angle = (m_IsSpellAt2 ? M_PI / +72 : M_PI / 7) + (m_IsSpellAt2 ? M_PI / 36 : -M_PI / 72); // Magic values ! Taken from tests IG.}
        }

        void OnUpdate(uint32 diff) override
        {
            static const float k_RotSpeed[2] =
            {
                0.014f,
                0.014f
            };
            static const float k_dist = 45.0f;

            // Update targets.
            std::list<Creature*> l_TargetList;
            at->FindAllUnfriendlyCreaturesInRange(k_dist);

            std::list<ObjectGuid> l_ToRemove; // We need to do it in two phase, otherwise it will break iterators.
            for (auto l_Guid : m_targets)
            {
                Unit* l_Target = ObjectAccessor::GetUnit(*at, l_Guid);
                if (l_Target && (l_Target->GetExactDist2d(at) > k_dist || !IsInWind(l_Target, at)))
                {
                    if (l_Target->HasAura(uint32(Spells::FOUR_WINDS_DMG)))
                    {
                        l_ToRemove.emplace_front(l_Guid);
                        l_Target->RemoveAura(uint32(Spells::FOUR_WINDS_DMG));
                    }
                }
            }

            for (auto l_Guid : l_ToRemove)
            {
                m_targets.remove(l_Guid);
            }

            for (Unit* l_Unit : l_TargetList)
            {
                if (!l_Unit
                    || l_Unit->GetExactDist2d(at) > k_dist
                    || l_Unit->HasAura(uint32(Spells::FOUR_WINDS_DMG))
                    || !IsInWind(l_Unit, at))
                    continue;

                at->GetCaster()->CastSpell(l_Unit, uint32(Spells::FOUR_WINDS_DMG), true);
                m_targets.emplace_front(l_Unit->GetGUID());

                // Achievement handling.
                if (Player* l_Plr = l_Unit->ToPlayer())
                {
                    // We check if the caster is Ranjit.
                    if (at->GetInstanceScript() && at->GetCaster()->GetEntry() == BossEntries::RANJIT)
                        at->GetInstanceScript()->SetGuidData(Data::PlayerIsHittedByRanjitSpells, l_Plr->GetGUID());
                }
            }

            // Update rotation.
            if ((m_Last - at->GetDuration() < 100))
                return;

            if (m_IsSpellAt2)
                m_angle -= k_RotSpeed[m_IsSpellAt2];
            else
                m_angle += k_RotSpeed[m_IsSpellAt2];

            // We are staying in [0, 2pi]
            if (m_angle > 2 * float(M_PI))
                m_angle -= 2 * float(M_PI);
            if (m_angle < 0)
                m_angle += 2 * float(M_PI);

            m_Last = at->GetDuration();
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* at) const override
    {
        return new at_four_winds_AI(at);
    }
};

// Four wind - 156793
class spell_four_wind_156793 : public SpellScriptLoader
{
public:
    spell_four_wind_156793() : SpellScriptLoader("spell_four_wind_156793") {  }

    enum class Spells : uint32
    {
        // Four winds. Arrived after 2 or 3 instances of WindWall.
        FOUR_WINDS = 156793,
        FOUR_WINDS_DMG = 153139,
        FOUR_WINDS_AT_1 = 156634,
        FOUR_WINDS_AT_2 = 156636,
        FOUR_WINDS_VISUAL_1 = 166623,
        FOUR_WINDS_VISUAL_2 = 166664
    };

    class spell_four_wind_156793_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_four_wind_156793_SpellScript)

        void HandleTriggerMissible(SpellEffIndex /*effIndex*/)
        {
            static const uint32 k_spells1[2] =
            {
                uint32(Spells::FOUR_WINDS_AT_1),
                uint32(Spells::FOUR_WINDS_VISUAL_1)
            };
            static const uint32 k_spells2[2] =
            {
                uint32(Spells::FOUR_WINDS_AT_2),
                uint32(Spells::FOUR_WINDS_VISUAL_2)
            };
            if (Unit* caster = GetCaster())
            {
                std::list<Creature*> l_Target;
                caster->GetCreatureListWithEntryInGrid(l_Target, MobEntries::ArakkoaPincerBirdsController, 40.0f);
                if (l_Target.empty())
                    return;

                uint32 l_Random = urand(0, 1);
                uint32 i = 0;
                for (Creature* l_Trigger : l_Target)
                {
                    l_Trigger->SetOrientation(0);
                    if (l_Random == 0)
                        l_Trigger->CastSpell(l_Trigger, k_spells1[i], true);
                    else
                        l_Trigger->CastSpell(l_Trigger, k_spells2[i], true);
                    ++i;
                }
            }
        }

        void Register()
        {
            OnEffectHit += SpellEffectFn(spell_four_wind_156793_SpellScript::HandleTriggerMissible, EFFECT_0, SPELL_EFFECT_TRIGGER_MISSILE);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_four_wind_156793_SpellScript();
    }
};

// AreaTriggers 1590,3684,3683 1591,3686,3685 for spells: 153311, 153314
class at_wind_wall : public AreaTriggerEntityScript
{
    enum class Spells : uint32
    {
        WINDWALL_DMG = 153759,
        WINDWALL_AT_1 = 153311,
        WINDWALL_AT_2 = 153314,
    };
public:
    at_wind_wall() : AreaTriggerEntityScript("at_wind_wall") {  }

    struct at_wind_wall_AI : public AreaTriggerAI
    {
        explicit at_wind_wall_AI(AreaTrigger* at) : AreaTriggerAI(at)
        {
            m_targets.clear();
            m_angle = 0;
            m_Last = 60000;
            m_IsSpellAt2 = 0;
        }

        float m_angle;
        std::list<ObjectGuid> m_targets;
        uint32 m_Last;
        uint32 m_IsSpellAt2;


        bool IsInWind(Unit const* p_Unit, AreaTrigger const* p_Area) const
        {
            static const float k_Radius = 2.0f;

            float l_x1 = p_Area->GetPositionX() + cos(m_angle);
            float l_x2 = p_Area->GetPositionX() + cos(m_angle - M_PI);
            float l_y1 = p_Area->GetPositionY() + sin(m_angle);
            float l_y2 = p_Area->GetPositionY() + sin(m_angle - M_PI);

            float l_dx = l_x2 - l_x1;
            float l_dy = l_y2 - l_y1;

            return std::abs(l_dy * p_Unit->GetPositionX() - l_dx * p_Unit->GetPositionY() - l_x1 * l_y2 + l_x2 * l_y1) / std::sqrt(l_dx * l_dx + l_dy * l_dy) < k_Radius;
        }

        void OnRemove() override
        {
            for (auto l_Guid : m_targets)
            {
                Unit* l_Target = ObjectAccessor::GetUnit(*at, l_Guid);
                if (l_Target && l_Target->HasAura(uint32(Spells::WINDWALL_DMG)))
                {
                    l_Target->RemoveAura(uint32(Spells::WINDWALL_DMG));
                }
            }
        }

        void OnUpdate(uint32 diff) override
        {
            static const float k_RotSpeed[2] =
            {
                0.015f,
                0.022f
            };
            static const int32 k_Start[2] =
            {
                55000,
                37000
            };
            static const float k_dist = 10.0f;

            // Update targets.
            std::list<Creature*> l_TargetList;
            l_TargetList = at->FindAllUnfriendlyCreaturesInRange(k_dist);

            std::list<ObjectGuid> l_ToRemove; // We need to do it in two phase, otherwise it will break iterators.
            for (auto l_Guid : m_targets)
            {
                Unit* l_Target = ObjectAccessor::GetUnit(*at, l_Guid);
                if (l_Target && (l_Target->GetExactDist2d(at) > k_dist || !IsInWind(l_Target, at)))
                {
                    if (l_Target->HasAura(uint32(Spells::WINDWALL_DMG)))
                    {
                        l_ToRemove.emplace_front(l_Guid);
                        l_Target->RemoveAura(uint32(Spells::WINDWALL_DMG));
                    }
                }
            }

            for (auto l_Guid : l_ToRemove)
            {
                m_targets.remove(l_Guid);
            }

            for (Unit* l_Unit : l_TargetList)
            {
                if (!l_Unit
                    || l_Unit->GetExactDist2d(at) > k_dist
                    || l_Unit->HasAura(uint32(Spells::WINDWALL_DMG))
                    || !IsInWind(l_Unit, at))
                    continue;

                at->GetCaster()->CastSpell(l_Unit, uint32(Spells::WINDWALL_DMG), true);
                m_targets.emplace_front(l_Unit->GetGUID());

                // Achievement handling.
                if (Player* l_Plr = l_Unit->ToPlayer())
                {
                    // We check if the caster is Ranjit.
                    if (at->GetInstanceScript() && at->GetCaster()->GetEntry() == BossEntries::RANJIT)
                        at->GetInstanceScript()->SetGuidData(Data::PlayerIsHittedByRanjitSpells, l_Plr->GetGUID());
                }
            }

            // Update rotation.
            if (at->GetDuration() > k_Start[m_IsSpellAt2] || (m_Last - at->GetDuration() < 100))
                return;

            if (m_IsSpellAt2)
                m_angle += k_RotSpeed[m_IsSpellAt2];
            else
                m_angle -= k_RotSpeed[m_IsSpellAt2];

            // We are staying in [0, 2pi]
            if (m_angle > 2 * float(M_PI))
                m_angle -= 2 * float(M_PI);
            if (m_angle < 0)
                m_angle += 2 * float(M_PI);

            m_Last = at->GetDuration();
        }

        void OnCreate() override
        {
            m_angle = at->GetOrientation();
            m_IsSpellAt2 = at->GetSpellId() == uint32(Spells::WINDWALL_AT_2);
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* at) const override
    {
        return new at_wind_wall_AI(at);
    }
};

// Windwall - 153315
class spell_windwall_153315 : public SpellScriptLoader
{
public:
    spell_windwall_153315() : SpellScriptLoader("spell_windwall_153315") {   }

    enum class Spells : uint32
    {
        // Clock and counter clock windwalls.
        WINDWALL_1 = 153593,
        WINDWALL_2 = 153594,
    };

    class spell_windwall_153315_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_windwall_153315_SpellScript)

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (GetCaster())
            {
                Unit* l_Target = nullptr;
                if ((l_Target = GetCaster()->SelectRandomPlayerInRange(30.0f, true)))
                {
                    uint32 l_Random = urand(0, 1);
                    if (l_Random == 0)
                        GetCaster()->CastSpell(l_Target, uint32(Spells::WINDWALL_1));
                    else
                        GetCaster()->CastSpell(l_Target, uint32(Spells::WINDWALL_2));
                }
            }
        }

        void Register()
        {
            OnEffectHit += SpellEffectFn(spell_windwall_153315_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_windwall_153315_SpellScript();
    }
};

// AreaTriggers 1880,1879,1878,1877,1873,1876,1871,1878 for spells: 153535, 153536, 153537, 153538, 153583, 153584, 153585,153586, 153587, 153588
class at_spinning_blade : public AreaTriggerEntityScript
{
    enum class Spells : uint32
    {
        SPINNING_BLADE_DMG = 153123,
    };

public:
    at_spinning_blade() : AreaTriggerEntityScript("at_spinning_blade") {  }

    struct at_spinning_blade_AI : public AreaTriggerAI
    {
        explicit at_spinning_blade_AI(AreaTrigger* at) : AreaTriggerAI(at)
        {
            m_targets.clear();
        }

        std::list<ObjectGuid> m_targets;

        void OnRemove() override
        {
            for (auto l_Guid : m_targets)
            {
                Unit* l_Target = ObjectAccessor::GetUnit(*at, l_Guid);
                if (l_Target && l_Target->HasAura(uint32(Spells::SPINNING_BLADE_DMG)))
                {
                    l_Target->RemoveAura(uint32(Spells::SPINNING_BLADE_DMG));
                }
            }
        }

        void OnUpdate(uint32 diff) override
        {
            std::list<Creature*> l_TargetList;
            float l_Radius = 4.0f;

            l_TargetList = at->FindAllUnfriendlyCreaturesInRange(l_Radius);

            std::list<ObjectGuid> l_ToRemove; // We need to do it in two phase, otherwise it will break iterators.
            for (auto l_Guid : m_targets)
            {
                Unit* l_Target = ObjectAccessor::GetUnit(*at, l_Guid);
                if (l_Target && l_Target->GetExactDist2d(at) > l_Radius)
                {
                    if (l_Target->HasAura(uint32(Spells::SPINNING_BLADE_DMG)))
                    {
                        l_ToRemove.emplace_front(l_Guid);
                        l_Target->RemoveAura(uint32(Spells::SPINNING_BLADE_DMG));
                    }
                }
            }

            for (auto l_Guid : l_ToRemove)
            {
                m_targets.remove(l_Guid);
            }

            for (Unit* l_Unit : l_TargetList)
            {
                if (!l_Unit || l_Unit->GetExactDist2d(at) > l_Radius || l_Unit->HasAura(uint32(Spells::SPINNING_BLADE_DMG)))
                    continue;

                at->GetCaster()->CastSpell(l_Unit, uint32(Spells::SPINNING_BLADE_DMG), true);
                m_targets.emplace_front(l_Unit->GetGUID());

                // Achievement handling.
                if (Player* l_Plr = l_Unit->ToPlayer())
                {
                    // We check if the caster is Ranjit.
                    if (at->GetInstanceScript() && at->GetCaster()->GetEntry() == BossEntries::RANJIT)
                        at->GetInstanceScript()->SetGuidData(Data::PlayerIsHittedByRanjitSpells, l_Plr->GetGUID());
                }
            }
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* at) const override
    {
        return new at_spinning_blade_AI(at);
    }
};

// AreaTriggers 2206 for spells: 160935
class at_solar_zone : public AreaTriggerEntityScript
{
    enum class SolarHealSpells : uint32
    {
        SOLAR_ZONE_1 = 160935,
        SOLAR_ZONE_HEAL = 160281,
        SOLAR_ZONE_DMG = 158441,
    };

public:
    at_solar_zone() : AreaTriggerEntityScript("at_solar_zone") {   }

    struct at_solar_zone_AI : public AreaTriggerAI
    {
        explicit at_solar_zone_AI(AreaTrigger* at) : AreaTriggerAI(at)
        {
            m_Targets.clear();
        }

        std::list<ObjectGuid> m_Targets;

        void OnRemove() override
        {
            for (auto l_Guid : m_Targets)
            {
                Unit* l_Target = ObjectAccessor::GetUnit(*at, l_Guid);
                if (l_Target && l_Target->HasAura(uint32(SolarHealSpells::SOLAR_ZONE_HEAL)))
                    l_Target->RemoveAura(uint32(SolarHealSpells::SOLAR_ZONE_HEAL));

                if (l_Target && l_Target->HasAura(uint32(SolarHealSpells::SOLAR_ZONE_DMG)))
                    l_Target->RemoveAura(uint32(SolarHealSpells::SOLAR_ZONE_DMG));
            }
        }

        void OnUpdate(uint32 diff) override
        {
            std::list<Creature*> l_TargetList;
            float l_Radius = 6.0f;

            at->GetCreatureListInGrid(l_TargetList, l_Radius);

            std::list<ObjectGuid> l_ToRemove; // We need to do it in two phase, otherwise it will break iterators.
            for (auto l_Unit : l_TargetList)
            {
                ObjectGuid l_Guid = l_Unit->GetGUID();
                Unit* l_Target = ObjectAccessor::GetUnit(*at, l_Guid);
                if (l_Target && l_Target->GetExactDist2d(at) > l_Radius)
                {
                    if (l_Target->HasAura(uint32(SolarHealSpells::SOLAR_ZONE_HEAL)))
                    {
                        l_ToRemove.emplace_front(l_Guid);
                        l_Target->RemoveAura(uint32(SolarHealSpells::SOLAR_ZONE_HEAL));
                    }
                    if (l_Target->HasAura(uint32(SolarHealSpells::SOLAR_ZONE_DMG)))
                    {
                        l_ToRemove.emplace_front(l_Guid);
                        l_Target->RemoveAura(uint32(SolarHealSpells::SOLAR_ZONE_DMG));
                    }
                }
            }

            for (auto l_Guid : l_ToRemove)
            {
                m_Targets.remove(l_Guid);
            }

            for (Unit* l_Unit : l_TargetList)
            {
                if (!l_Unit || l_Unit->GetExactDist2d(at) > l_Radius)
                    continue;

                if (l_Unit->IsFriendlyTo(at->GetCaster()) && !l_Unit->HasAura(uint32(SolarHealSpells::SOLAR_ZONE_HEAL)))
                {
                    at->GetCaster()->CastSpell(l_Unit, uint32(SolarHealSpells::SOLAR_ZONE_HEAL), true);
                    m_Targets.emplace_front(l_Unit->GetGUID());
                }
                else if (!l_Unit->IsFriendlyTo(at->GetCaster()) && !l_Unit->HasAura(uint32(SolarHealSpells::SOLAR_ZONE_DMG)))
                {
                    at->GetCaster()->CastSpell(l_Unit, uint32(SolarHealSpells::SOLAR_ZONE_DMG), true);
                    m_Targets.emplace_front(l_Unit->GetGUID());
                }
            }
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* at) const override
    {
        return new at_solar_zone_AI(at);
    }
};

// AreaTriggers 1901 for spells: 156840
class at_storm_zone : public AreaTriggerEntityScript
{
    enum class Spells : uint32
    {
        TWISTER_DNT = 178617,
        STORM = 156515,
        STORM_AT = 156840,
        STORM_DMG = 156841,
    };

public:
    at_storm_zone() : AreaTriggerEntityScript("at_storm_zone") {   }

    struct at_storm_zone_AI : public AreaTriggerAI
    {
        explicit at_storm_zone_AI(AreaTrigger* at) : AreaTriggerAI(at)
        {
            m_Targets.clear();
        }

        std::list<ObjectGuid> m_Targets;

        void OnRemove() override
        {
            for (auto l_Guid : m_Targets)
            {
                Unit* l_Target = ObjectAccessor::GetUnit(*at, l_Guid);
                if (l_Target && l_Target->HasAura(uint32(Spells::STORM_DMG)))
                    l_Target->RemoveAura(uint32(Spells::STORM_DMG));
            }
        }

        void OnUpdate(uint32 diff) override
        {
            std::list<Creature*> l_TargetList;
            float l_Radius = 4.0f;
            Unit* l_Caster = at->GetCaster();

            l_TargetList = at->FindAllUnfriendlyCreaturesInRange(l_Radius);

            std::list<ObjectGuid> l_ToRemove; // We need to do it in two phase, otherwise it will break iterators.
            for (auto l_Unit : l_TargetList)
            {
                ObjectGuid l_Guid = l_Unit->GetGUID();
                Unit* l_Target = ObjectAccessor::GetUnit(*at, l_Guid);
                if (l_Target && l_Target->GetExactDist2d(at) > l_Radius)
                {
                    if (l_Target->HasAura(uint32(Spells::STORM_DMG)))
                    {
                        l_ToRemove.emplace_front(l_Guid);
                        l_Target->RemoveAura(uint32(Spells::STORM_DMG));
                    }
                }
            }

            for (auto l_Guid : l_ToRemove)
            {
                m_Targets.remove(l_Guid);
            }

            for (Unit* l_Unit : l_TargetList)
            {
                if (!l_Unit || l_Unit->GetExactDist2d(at) > l_Radius)
                    continue;

                if (!l_Unit->HasAura(uint32(Spells::STORM_DMG)))
                {
                    at->GetCaster()->AddAura(uint32(Spells::STORM_DMG), l_Unit);
                    m_Targets.emplace_front(l_Unit->GetGUID());
                }
            }
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* at) const override
    {
        return new at_storm_zone_AI(at);
    }
};

// AreaTriggers 1631 for spells: 153905
class at_dervish : public AreaTriggerEntityScript
{
    enum class Spells : uint32
    {
        DERVISH = 153905,
        DERVISH_DMG = 153907,
    };

public:
    at_dervish() : AreaTriggerEntityScript("at_dervish") {  }

    struct at_dervish_AI : public AreaTriggerAI
    {
        explicit at_dervish_AI(AreaTrigger* at) : AreaTriggerAI(at)
        {
            m_Targets.clear();
        }

        std::list<ObjectGuid> m_Targets;

        void OnRemove() override
        {
            for (auto l_Guid : m_Targets)
            {
                Unit* l_Target = ObjectAccessor::GetUnit(*at, l_Guid);
                if (l_Target && l_Target->HasAura(uint32(Spells::DERVISH_DMG)))
                    l_Target->RemoveAura(uint32(Spells::DERVISH_DMG));
            }
        }

        void OnUpdate(uint32 diff) override
        {
            std::list<Creature*> l_TargetList;
            float l_Radius = 4.0f;
            Unit* l_Caster = at->GetCaster();

            l_TargetList = at->FindAllUnfriendlyCreaturesInRange(l_Radius);

            std::list<ObjectGuid> l_ToRemove; // We need to do it in two phase, otherwise it will break iterators.
            for (auto l_Unit : l_TargetList)
            {
                ObjectGuid l_Guid = l_Unit->GetGUID();
                Unit* l_Target = ObjectAccessor::GetUnit(*at, l_Guid);
                if (l_Target && l_Target->GetExactDist2d(at) > l_Radius)
                {
                    if (l_Target->HasAura(uint32(Spells::DERVISH_DMG)))
                    {
                        l_ToRemove.emplace_front(l_Guid);
                        l_Target->RemoveAura(uint32(Spells::DERVISH_DMG));
                    }
                }
            }

            for (auto l_Guid : l_ToRemove)
            {
                m_Targets.remove(l_Guid);
            }

            for (Unit* l_Unit : l_TargetList)
            {
                if (!l_Unit || l_Unit->GetExactDist2d(at) > l_Radius)
                    continue;

                if (!l_Unit->HasAura(uint32(Spells::DERVISH_DMG)))
                {
                    at->GetCaster()->AddAura(uint32(Spells::DERVISH_DMG), l_Unit);
                    m_Targets.emplace_front(l_Unit->GetGUID());
                }
            }
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* at) const override
    {
        return new at_dervish_AI(at);
    }
};

// Spinning Blade - 153544
class spell_spinning_blade : public SpellScriptLoader
{
public:
    spell_spinning_blade() : SpellScriptLoader("spell_spinning_blade") {  }

    enum class Spells : uint32
    {
        // Those are for Spinning Blade
        SPINNING_BLADE_9 = 153583,
        SPINNING_BLADE_11 = 153584,
        SPINNING_BLADE_10 = 153585,
        SPINNING_BLADE_3 = 153586,
        SPINNING_BLADE_12 = 153587,
        SPINNING_BLADE_8 = 153588,
    };

    class spell_spinning_blade_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_spinning_blade_SpellScript)

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            static const Spells k_Spells[] = {
                Spells::SPINNING_BLADE_9,
                Spells::SPINNING_BLADE_11,
                Spells::SPINNING_BLADE_10,
                Spells::SPINNING_BLADE_3,
                Spells::SPINNING_BLADE_12,
                Spells::SPINNING_BLADE_8,
            };

            if (GetCaster() && GetHitUnit())
            {
                // Spinning Blade AreaTrigger
                uint32 l_Random = urand(0, 5);
                uint32 l_SpellToCast = uint32(k_Spells[l_Random]);
                GetCaster()->CastSpell(GetHitUnit(), l_SpellToCast, true);
            }
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_spinning_blade_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_spinning_blade_SpellScript();
    }
};

// Blade Dance - 153581
class spell_blade_dance : public SpellScriptLoader
{
public:
    spell_blade_dance() : SpellScriptLoader("spell_blade_dance") {  }

    enum class Spells : uint32
    {
        // Those are for Blade Dance
        SPINNING_BLADE_4 = 153535,
        SPINNING_BLADE_5 = 153536,
        SPINNING_BLADE_6 = 153537,
        SPINNING_BLADE_7 = 153538,
    };

    class spell_blade_dance_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_blade_dance_SpellScript)

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (GetCaster() && GetHitUnit())
            {
                GetCaster()->CastSpell(GetHitUnit(), uint32(Spells::SPINNING_BLADE_4), true);
                GetCaster()->SetOrientation(GetCaster()->GetOrientation() + M_PI / 2);
                GetCaster()->CastSpell(GetHitUnit(), uint32(Spells::SPINNING_BLADE_5), true);
                GetCaster()->SetOrientation(GetCaster()->GetOrientation() + M_PI / 2);
                GetCaster()->CastSpell(GetHitUnit(), uint32(Spells::SPINNING_BLADE_6), true);
                GetCaster()->SetOrientation(GetCaster()->GetOrientation() + M_PI / 2);
                GetCaster()->CastSpell(GetHitUnit(), uint32(Spells::SPINNING_BLADE_7), true);
                GetCaster()->SetOrientation(GetCaster()->GetOrientation() + M_PI / 2);
            }
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_blade_dance_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_blade_dance_SpellScript();
    }
};

// Storm - 156515
class spell_storm_156515 : public SpellScriptLoader
{
public:
    spell_storm_156515() : SpellScriptLoader("spell_storm_156515") {  }

    enum class Spells : uint32
    {
        STORM = 156515,
        STORM_AT = 156840,
        STORM_DMG = 156841,
    };

    class spell_storm_156515_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_storm_156515_SpellScript)

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (GetCaster() && GetHitUnit())
                GetCaster()->CastSpell(GetHitUnit(), uint32(Spells::STORM_AT), true);
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_storm_156515_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_storm_156515_SpellScript();
    }
};

void AddSC_spell_instance_skyreach()
{
    // Spells.
    new at_solar_zone();
    new at_spinning_blade();
    new spell_spinning_blade();
    new spell_storm_156515();
    new at_storm_zone();
    new at_dervish();
    new spell_blade_dance();
    new spell_solar_storm();
    new at_solar_storm();
    new spell_flash_bang();
    new at_protective_barrier();

    // Boss Ranjit.
    new at_wind_wall();
    new spell_windwall_153315();
    new spell_four_wind_156793();
    new at_four_winds();

    // Boss Araknath.
    new spell_energize();
    new spell_visual_energize_154159();
    new spell_visual_energize_154177();
    new at_smash();

    // Boss Rukhran.
    new spell_summon_solar_flare();
    new spell_sunstrike();
    new spell_quills_159381();

    // Boss High Save Viryx.
    new at_lens_flare();
    new spell_cast_down_165845();
}
