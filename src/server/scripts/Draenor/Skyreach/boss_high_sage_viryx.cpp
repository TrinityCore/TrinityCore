#include "instance_skyreach.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "Vehicle.h"
#include "InstanceScript.h"

class mob_skyreach_shield_construct : public CreatureScript
{
public:
    // Entry: 76292
    mob_skyreach_shield_construct() : CreatureScript("mob_skyreach_shield_construct")  {   }

    enum class Spells : uint32
    {
        Shielding = 158641,
        Submerged = 154163,
    };

    enum class Events : uint32
    {
        Shielding = 1,
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_skyreach_shield_constructAI(creature);
    }

    struct mob_skyreach_shield_constructAI : public ScriptedAI
    {
        mob_skyreach_shield_constructAI(Creature* creature) : ScriptedAI(creature),
            m_Instance(creature->GetInstanceScript()),
            m_events()
        {
        }

        void Reset()
        {
            m_events.Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            me->RemoveAura(uint32(Spells::Submerged));
            m_events.ScheduleEvent(uint32(Events::Shielding), 5000);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            m_events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            switch (m_events.ExecuteEvent())
            {
            case uint32(Events::Shielding):
                m_events.ScheduleEvent(uint32(Events::Shielding), 5000);
                me->CastSpell(me, uint32(Spells::Shielding));
                break;
            default:
                break;
            }

            DoMeleeAttackIfReady();
        }

        InstanceScript* m_Instance;
        EventMap m_events;
    };
};

static const std::size_t k_NumFallPoints = 13;
static const Position k_FallPoints[k_NumFallPoints] =
{
    { 1094.775f, 1715.610f, 275.72f, 0.0f },
    { 1094.993f, 1721.900f, 263.72f, 0.0f },
    { 1104.928f, 1724.705f, 263.72f, 0.0f },
    { 1141.754f, 1729.700f, 263.72f, 0.0f },
    { 1123.270f, 1735.448f, 263.72f, 0.0f },
    { 1132.028f, 1744.517f, 263.72f, 0.0f },
    { 1138.780f, 1753.942f, 263.72f, 0.0f },
    { 1144.525f, 1764.297f, 263.72f, 0.0f },
    { 1147.478f, 1773.486f, 263.72f, 0.0f },
    { 1149.241f, 1785.068f, 263.72f, 0.0f },
    { 1148.452f, 1798.171f, 263.72f, 0.0f },
    { 1146.030f, 1811.055f, 263.72f, 0.0f },
    { 1140.494f, 1822.770f, 263.72f, 0.0f }
};

class mob_solarzealot : public CreatureScript
{
public:
    // Entry: 76267
    mob_solarzealot()  : CreatureScript("mob_solarzealot")  {  }

    enum class Spells : uint32
    {
        JumpChargeDemonCreatorRideMe = 165834,
        ForceDemonCreatorToRideMe = 136522,
    };

    enum class Moves : uint32
    {
        ArrivedAtDestination = 0xBAB,
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_solarzealotAI(creature);
    }

    struct mob_solarzealotAI : public ScriptedAI
    {
        mob_solarzealotAI(Creature* creature) : ScriptedAI(creature),
            m_Reset(false)
        {
            me->SetSpeed(UnitMoveType::MOVE_WALK, 0.3f);
            me->SetSpeed(UnitMoveType::MOVE_RUN, 0.3f);
            me->SetSpeed(UnitMoveType::MOVE_FLIGHT, 0.3f);
        }

        void Reset()
        {
            events.Reset();
            m_Reset = true;
        }

        void EnterCombat(Unit* /*who*/)
        {
        }

        void MovementInform(uint32 p_TypeId, uint32 p_PointId)
        {
            if (p_TypeId == POINT_MOTION_TYPE && p_PointId == uint32(Moves::ArrivedAtDestination))
            {
                if (me->GetVehicle())
                    me->GetVehicle()->RemoveAllPassengers();
                me->DespawnOrUnsummon();
            }
        }

        void UpdateAI(const uint32 diff)
        {
            events.Update(diff);

            if (m_Reset)
            {
                m_Reset = false;
                me->CastSpell(me->GetCharmerOrOwner(), uint32(Spells::JumpChargeDemonCreatorRideMe), true);
                if (me->ToTempSummon() && me->ToTempSummon()->GetSummoner())
                    me->ToTempSummon()->GetSummoner()->EnterVehicle(me, 0);

                int l_ClosestPoint = 0;
                float l_ClosestDistance = k_FallPoints[0].GetExactDist2d(me);
                for (int i = 1; i < k_NumFallPoints; i++)
                {
                    if (k_FallPoints[i].GetExactDist2d(me) < l_ClosestDistance)
                    {
                        l_ClosestDistance = k_FallPoints[i].GetExactDist2d(me);
                        l_ClosestPoint = i;
                    }
                }

                me->GetMotionMaster()->MovePoint(uint32(Moves::ArrivedAtDestination), k_FallPoints[l_ClosestPoint]);
            }
        }

        bool m_Reset;
    };
};

class mob_arakkoa_magnifying_glass_focus : public CreatureScript
{
public:
    // Entry: 76083
    mob_arakkoa_magnifying_glass_focus() : CreatureScript("mob_arakkoa_magnifying_glass_focus")  {  }

    enum class Spells : uint32
    {
        LensFlare = 154044,
    };

    enum class Events : uint32
    {
        LensFlare = 1,
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_arakkoa_magnifying_glass_focusI(creature);
    }

    struct mob_arakkoa_magnifying_glass_focusI : public ScriptedAI
    {
        mob_arakkoa_magnifying_glass_focusI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetSpeed(UnitMoveType::MOVE_WALK, 0.9f);
            me->SetSpeed(UnitMoveType::MOVE_RUN, 0.9f);
            me->SetSpeed(UnitMoveType::MOVE_FLIGHT, 0.9f);
        }

        void Reset()
        {
            events.Reset();
            events.ScheduleEvent(uint32(Events::LensFlare), 100);

            if (me->GetInstanceScript())
                me->GetInstanceScript()->SetData(Data::StartingLensFlare, 0);
        }

        void UpdateAI(const uint32 diff)
        {
            events.Update(diff);

            if (events.ExecuteEvent() == uint32(Events::LensFlare))
            {
                if (me->ToTempSummon())
                {
                    if (me->ToTempSummon()->GetSummoner())
                    {
                        Position l_Pos;
                        l_Pos = me->ToTempSummon()->GetSummoner()->GetPosition();
                        l_Pos.m_positionZ -= 1.5f;
                        me->GetMotionMaster()->MovePoint(0, l_Pos);
                    }
                }
                events.ScheduleEvent(uint32(Events::LensFlare), 500);
            }
        }

        bool m_Reset;
    };
};

class boss_highsageviryx : public CreatureScript
{
public:
    // Entry: 76266
    boss_highsageviryx() : CreatureScript("boss_highsageviryx")  {  }

    enum class Spells : uint32
    {
        CastDown = 156789,
        CastDown_Summon = 153955,
        CastDown_Visual = 165845,
        CastDown_2 = 153954,
        LensFlare = 154029,
        LensFlare_At = 154044,
        LensFlare_Dmg = 154043,
        SolarBurst = 154396,
        CallAdds = 154049,
    };

    enum class Texts : int8
    {
        CombatStart = 0,
        JustDied = 5,
        SpellCastDown = 2,
        SpellCallAdds = 3,
        SpellLensFlare = 1,
        KilledUnitA = 4,
        KilledUnitB = 6,
        Victory = 5,
    };

    enum class Events : uint32
    {
        LensFlare = 1,
        CastDown = 2,
        SolarBurst = 3,
        CallAdds = 4,
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_highsageviryxAI(creature);
    }

    struct boss_highsageviryxAI : public BossAI
    {
        boss_highsageviryxAI(Creature* creature) : BossAI(creature, Data::HighSageViryx)
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
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SNARE, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
        }

        void Reset()
        {
            _Reset();
        }

        void JustReachedHome()
        {
            _JustReachedHome();

            Talk(int8(Texts::Victory));
            if (instance)
            {
                instance->SetBossState(Data::HighSageViryx, FAIL);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            }
        }

        void JustDied(Unit* /*killer*/)
        {
            _JustDied();

            me->CastSpell(me, RandomSpells::DespawnAreaTriggers, true);

            Talk(int8(Texts::JustDied));
            if (instance)
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                Map::PlayerList const &PlayerList = instance->instance->GetPlayers();
                for (Map::PlayerList::const_iterator it = PlayerList.begin(); it != PlayerList.end(); ++it)
                {
                    if (Player* player = it->GetSource())
                        player->RemoveAura(uint32(Spells::LensFlare_Dmg));
                }
            
            }
              
        }

        void KilledUnit(Unit* /*victim*/)
        {
            if (urand(0, 1))
                Talk(int8(Texts::KilledUnitA), me);
            else
                Talk(int8(Texts::KilledUnitB), me);
        }

        void EnterCombat(Unit* /*who*/)
        {
            _EnterCombat();

            Talk(int8(Texts::CombatStart));
            events.ScheduleEvent(uint32(Events::SolarBurst), 5000);
            events.ScheduleEvent(uint32(Events::CastDown), 11000);
            events.ScheduleEvent(uint32(Events::LensFlare), 27000);
            events.ScheduleEvent(uint32(Events::CallAdds), 29000);

            if (instance)
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            switch (events.ExecuteEvent())
            {
            case uint32(Events::CastDown):
                events.ScheduleEvent(uint32(Events::CastDown), 35000);
                if (Player* player = me->SelectRandomPlayerInRange(80.0f,true))
                {
                    Talk(int8(Texts::SpellCastDown), me);
                    me->CastSpell(player, uint32(Spells::CastDown));
                }
                break;
            case uint32(Events::LensFlare):
                if (Player* player = me->SelectRandomPlayerInRange(80.0f, true))
                {
                    player->CastSpell(player, uint32(Spells::LensFlare), true);
                    Talk(int8(Texts::SpellLensFlare), me);
                }
                events.ScheduleEvent(uint32(Events::LensFlare), 27000);
                break;
            case uint32(Events::SolarBurst):
                me->CastSpell(me->GetVictim(), uint32(Spells::SolarBurst));
                events.ScheduleEvent(uint32(Events::SolarBurst), 21000);
                break;
            case uint32(Events::CallAdds):
                Talk(int8(Texts::SpellCallAdds), me);
                me->CastSpell(me, uint32(Spells::CallAdds), false);
                if (Creature* mobs = me->SummonCreature(76292, Position(1077.0f, 1790.5f, 262.173f, 5.7237f), TEMPSUMMON_MANUAL_DESPAWN))
                    if (Player* player = me->SelectRandomPlayerInRange(80.0f, true))
                        mobs->CombatStart(player, true);
                if (Creature* mobs = me->SummonCreature(76267, Position(1077.0f, 1790.5f, 262.173f, 5.7237f), TEMPSUMMON_MANUAL_DESPAWN))
                    if (Player* player = me->SelectRandomPlayerInRange(80.0f, true))
                        mobs->CombatStart(player, true);                
                events.ScheduleEvent(uint32(Events::CallAdds), 60000);
                break;
            default:
                break;
            }

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_high_save_viryx()
{
    new boss_highsageviryx();
    new mob_solarzealot();
    new mob_arakkoa_magnifying_glass_focus();
    new mob_skyreach_shield_construct();
}

