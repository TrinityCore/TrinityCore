#include "instance_skyreach.h"
#include "Player.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ScriptedGossip.h"
#include "InstanceScript.h"


/*
 TODO: There seems to have other spells to cast here. For example:
 - Magma explosion supreme
 - Sun trinckets <- Need modelid and spell to cast. It's healing normaly.
 - Air trinckets
 - Cyclone trinckets ?
 - Do visual stuff when no one is attacking.
 - Need to see if the timers are good enough.
 */
//84782
class npc_gossip_intro_outro_84782 : public CreatureScript
{
public:
    npc_gossip_intro_outro_84782() : CreatureScript("npc_gossip_intro_outro_84782")    {    }

    enum class Gossip : uint32
    {
        Teleport = 1,
    };

    bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 /*sender*/, uint32 action)
    {
        ClearGossipMenuFor(player);
        switch (action)
        {
        case uint32(Gossip::Teleport):
            // Meeting stone of Skyreach.
            player->TeleportTo(1116, 57.110f, 2527.114f, 79.4f, 0.35f);
            break;
        }
        return true;
    }
};

class mob_grand_defense_construct : public CreatureScript
{
public:
    // Entry: 76145
    mob_grand_defense_construct() : CreatureScript("mob_grand_defense_construct")   {   }

    enum class Spells : uint32
    {
        Smash = 152998,
        Burn = 153001,
    };

    enum class Events : uint32
    {
        Smash = 1,
        Burn = 2,
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_grand_defense_constructAI(creature);
    }

    struct mob_grand_defense_constructAI : public ScriptedAI
    {
        mob_grand_defense_constructAI(Creature* creature) : ScriptedAI(creature),
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
            m_events.ScheduleEvent(uint32(Events::Smash), urand(5000, 7000));
            m_events.ScheduleEvent(uint32(Events::Burn), urand(10000, 12000));
        }

        void JustDied(Unit*)
        {
            // Monomania Achievement.
            if (IsHeroic() && m_Instance)
                m_Instance->SetData(Data::MonomaniaAchievementFail, 0);
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
            case uint32(Events::Smash):
                m_events.ScheduleEvent(uint32(Events::Smash), 16000);
                me->CastSpell(me->GetVictim(), uint32(Spells::Smash));
                break;
            case uint32(Events::Burn):
                m_events.ScheduleEvent(uint32(Events::Burn), 18000);
                me->CastSpell(me->GetVictim(), uint32(Spells::Burn));
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

class mob_young_kaliri : public CreatureScript
{
public:
    // Entry: 76121
    mob_young_kaliri() : CreatureScript("mob_young_kaliri")   {   }

    enum class Spells : uint32
    {
        Pierce = 153563,
    };

    enum class Events : uint32
    {
        Pierce = 1,
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_young_kaliriAI(creature);
    }

    struct mob_young_kaliriAI : public ScriptedAI
    {
        mob_young_kaliriAI(Creature* creature) : ScriptedAI(creature),
            m_Instance(creature->GetInstanceScript()),
            m_events(),
            m_Pos(),
            m_Home(),
            m_TargetGuid(ObjectGuid::Empty)
        {
            m_Pos = me->GetPosition();
            m_Home = me->GetPosition();
            me->SetSpeed(MOVE_FLIGHT, 5.0f);
            m_Pos.m_positionX += 13.0f * cos(me->GetOrientation());
            m_Pos.m_positionY += 13.0f * sin(me->GetOrientation());
        }

        void Reset()
        {
            m_events.Reset();
            m_events.ScheduleEvent(uint32(Events::Pierce), 500);
        }

        void EnterCombat(Unit* /*who*/)
        {
        }

        void MovementInform(uint32 /*p_TypeId*/, uint32 p_PointId)
        {
            switch (p_PointId)
            {
            case 0:
                me->SetSpeed(MOVE_FLIGHT, 1.0f);
                me->GetMotionMaster()->MoveBackward(1, m_Home.GetPositionX(), m_Home.GetPositionY(), m_Home.GetPositionZ(), 0.5f);
                if (Player* player = ObjectAccessor::GetPlayer(*me, m_TargetGuid))
                    me->CastSpell(player, uint32(Spells::Pierce));
                m_TargetGuid = ObjectGuid::Empty;
                break;
            case 1:
                me->SetSpeed(MOVE_FLIGHT, 5.0f);
                me->SetOrientation(m_Home.GetOrientation());
                m_events.ScheduleEvent(uint32(Events::Pierce), 500);
                break;
            }
        }

        void UpdateAI(const uint32 diff)
        {
            m_events.Update(diff);

            switch (m_events.ExecuteEvent())
            {
            case uint32(Events::Pierce):
                if (Player* player = me->SelectNearestPlayer(15.0f))
                {
                    if (me->isInFront(player, float(M_PI) / 6))
                    {
                        m_TargetGuid = player->GetGUID();
                        me->GetMotionMaster()->MovePoint(0, m_Pos);
                    }
                    else
                        m_events.ScheduleEvent(uint32(Events::Pierce), 500);
                }
                else
                    m_events.ScheduleEvent(uint32(Events::Pierce), 500);
                break;
            default:
                break;
            }
        }

        InstanceScript* m_Instance;
        EventMap m_events;
        Position m_Pos;
        Position m_Home;
        ObjectGuid m_TargetGuid;
    };
};

class mob_radiant_supernova : public CreatureScript
{
public:
    // Entry: 79463
    mob_radiant_supernova()  : CreatureScript("mob_radiant_supernova")    {    }

    enum class Spells : uint32
    {
        SolarWrath = 157020,
        SolarDetonation = 160303,
    };

    enum class Events : uint32
    {
        SolarWrath = 1,
        SolarDetonation = 2,
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_radiant_supernovaAI(creature);
    }

    struct mob_radiant_supernovaAI : public ScriptedAI
    {
        mob_radiant_supernovaAI(Creature* creature) : ScriptedAI(creature),
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
            m_events.ScheduleEvent(uint32(Events::SolarWrath), urand(1000, 2000));
            m_events.ScheduleEvent(uint32(Events::SolarDetonation), urand(5000, 7000));
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
            case uint32(Events::SolarWrath):
                m_events.ScheduleEvent(uint32(Events::SolarWrath), urand(1500, 2500));
                me->CastSpell(me->GetVictim(), uint32(Spells::SolarWrath));
                break;
            case uint32(Events::SolarDetonation):
                m_events.ScheduleEvent(uint32(Events::SolarDetonation), urand(5000, 7000));

                if (m_Instance)
                {
                    Map::PlayerList const& playerList = instance->instance->GetPlayers();
                    for (Map::PlayerList::const_iterator itr = playerList.begin(); itr != playerList.end(); ++itr)
                    {
                        if (Player* player = itr->GetSource())
                            player->CastSpell(player, uint32(Spells::SolarDetonation));
                    }
                }
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

class mob_defense_construct : public CreatureScript
{
public:
    // Entry: 76087
    mob_defense_construct() : CreatureScript("mob_defense_construct")    {    }

    enum class Spells : uint32
    {
        Submerge = 169084,
        ProtectiveBarrier = 152973,
        SelfDestruct = 158644,
    };

    enum class Events : uint32
    {
        ProtectiveBarrier = 2,
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_defense_constructAI(creature);
    }

    struct mob_defense_constructAI : public ScriptedAI
    {
        mob_defense_constructAI(Creature* creature) : ScriptedAI(creature),
            m_Instance(creature->GetInstanceScript()),
            m_events()
        {
        }

        void Reset()
        {
            m_events.Reset();

            me->AddAura(uint32(Spells::Submerge), me);
        }

        void EnterCombat(Unit* /*who*/)
        {
            me->RemoveAura(uint32(Spells::Submerge));
            m_events.ScheduleEvent(uint32(Events::ProtectiveBarrier), urand(5000, 7000));
        }

        void JustDied(Unit*)
        {
            me->CastSpell(me, RandomSpells::DespawnAreaTriggers, true);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            m_events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (me->GetHealthPct() < 10.0f)
            {
                me->CastSpell(me, uint32(Spells::SelfDestruct));
                return;
            }

            switch (m_events.ExecuteEvent())
            {
            case uint32(Events::ProtectiveBarrier):
                me->CastSpell(me, uint32(Spells::ProtectiveBarrier));
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

class mob_solar_magnifier : public CreatureScript
{
public:
    // Entry: 77559
    mob_solar_magnifier()  : CreatureScript("mob_solar_magnifier")    {    }

    enum class Spells : uint32
    {
        Submerge = 169084,
        Empower = 152917,
        SolarPulse = 174489,
        SelfDestruct = 158644,
    };

    enum class Events : uint32
    {
        Submerge = 1,
        Empower = 2,
        SolarPulse = 3,
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_solar_magnifierAI(creature);
    }

    struct mob_solar_magnifierAI : public ScriptedAI
    {
        mob_solar_magnifierAI(Creature* creature) : ScriptedAI(creature),
            m_Instance(creature->GetInstanceScript()),
            m_events()
        {
        }

        void Reset()
        {
            m_events.Reset();

            me->AddAura(uint32(Spells::Submerge), me);
        }

        void EnterCombat(Unit* /*who*/)
        {
            me->RemoveAura(uint32(Spells::Submerge));
            m_events.ScheduleEvent(uint32(Events::Empower), urand(4000, 5000));
            m_events.ScheduleEvent(uint32(Events::SolarPulse), urand(1500, 2000));
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            m_events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (me->GetHealthPct() < 10.0f)
            {
                me->CastSpell(me, uint32(Spells::SelfDestruct));
                return;
            }

            switch (m_events.ExecuteEvent())
            {
            case uint32(Events::Empower):
                m_events.ScheduleEvent(uint32(Events::Empower), urand(6000, 8000));

                if (Unit* l_Friend = me->SelectNearestPlayer(10.0f))
                {
                    if (l_Friend->GetEntry() != me->GetEntry())
                        me->CastSpell(l_Friend, uint32(Spells::Empower));
                }
                break;
            case uint32(Events::SolarPulse):
                m_events.ScheduleEvent(uint32(Events::SolarPulse), urand(2000, 3000));

                if (Player* player = me->SelectRandomPlayerInRange(20.0f,true))
                    me->CastSpell(player, uint32(Spells::SolarPulse));
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

class mob_dread_raven_hatchling : public CreatureScript
{
public:
    // Entry: 76253
    mob_dread_raven_hatchling() : CreatureScript("mob_dread_raven_hatchling")    {    }

    enum class Spells : uint32
    {
        EXCITED = 157259,
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_dread_raven_hatchlingAI(creature);
    }

    struct mob_dread_raven_hatchlingAI : public ScriptedAI
    {
        mob_dread_raven_hatchlingAI(Creature* creature) : ScriptedAI(creature),
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
        }

        void SpellHit(Unit* /*caster*/, SpellInfo const* p_Spell)
        {
            if (p_Spell->Id == uint32(Spells::EXCITED))
            {
                if (Player* player = me->SelectRandomPlayerInRange(50.0f, true))
                {
                    me->AddThreat(player, 10000.0f);
                    me->Attack(player, true);
                }
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            m_events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            DoMeleeAttackIfReady();
        }

        InstanceScript* m_Instance;
        EventMap m_events;
    };
};

class mob_skyreach_sun_talon : public CreatureScript
{
public:
    // Entry: 79093
    mob_skyreach_sun_talon() : CreatureScript("mob_skyreach_sun_talon")    {    }

    enum class Spells : uint32
    {
        EXPOSE_WEAKNESS = 152982,
        INVISIBILITY_DETECTION = 141048,
        FIXATED = 152838,
    };

    enum class Events : uint32
    {
        CHANGE_TARGET = 1, // Every 6 seconds.
        EXPOSE_WEAKNESS = 2, // Every 10 seconds.
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_skyreach_sun_talonAI(creature);
    }

    struct mob_skyreach_sun_talonAI : public ScriptedAI
    {
        mob_skyreach_sun_talonAI(Creature* creature) : ScriptedAI(creature),
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
            m_events.ScheduleEvent(uint32(Events::CHANGE_TARGET), 6000);
            m_events.ScheduleEvent(uint32(Events::EXPOSE_WEAKNESS), 10000);
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
            case uint32(Events::CHANGE_TARGET):
                m_events.ScheduleEvent(uint32(Events::CHANGE_TARGET), 6000);
                me->CastSpell(me, uint32(Spells::INVISIBILITY_DETECTION), true);
                me->CastSpell(me->GetVictim(), uint32(Spells::FIXATED), true);
                me->getThreatManager().resetAllAggro();

                if (Player* player = me->SelectRandomPlayerInRange(30.0f, true))
                {
                    me->getThreatManager().addThreat(player, 1000.0f);
                    me->Attack(player, true);
                }
                break;
            case uint32(Events::EXPOSE_WEAKNESS):
                m_events.ScheduleEvent(uint32(Events::EXPOSE_WEAKNESS), 10000);
                me->CastSpell(me->GetVictim(), uint32(Spells::EXPOSE_WEAKNESS));
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

class mob_adorned_bladetalon : public CreatureScript
{
public:
    // Entry: 79303
    mob_adorned_bladetalon() : CreatureScript("mob_adorned_bladetalon")   {   }

    enum class Spells : uint32
    {
        SLASH = 158083,
        PIERCING_RUSH = 138175,
    };

    enum class Events : uint32
    {
        SLASH = 1, // Every 2 to 5 seconds.
        PIERCING_RUSH = 2, // Every 2 to 5 seconds.
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_adorned_bladetalonAI(creature);
    }

    struct mob_adorned_bladetalonAI : public ScriptedAI
    {
        mob_adorned_bladetalonAI(Creature* creature) : ScriptedAI(creature),
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
            m_events.ScheduleEvent(uint32(Events::SLASH), urand(0, 4000));
            m_events.ScheduleEvent(uint32(Events::PIERCING_RUSH), urand(5000, 7000));
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
            case uint32(Events::SLASH):
                m_events.ScheduleEvent(uint32(Events::SLASH), urand(2500, 5000));
                me->CastSpell(me->GetVictim(), uint32(Spells::SLASH));
                break;
            case uint32(Events::PIERCING_RUSH):
                m_events.ScheduleEvent(uint32(Events::PIERCING_RUSH), urand(2500, 5000));

                if (Player* player = me->SelectRandomPlayerInRange(20.0f, true))
                    me->CastSpell(player, uint32(Spells::PIERCING_RUSH));
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

class mob_driving_gale_caller : public CreatureScript
{
public:
    // Entry: 78932
    mob_driving_gale_caller() : CreatureScript("mob_driving_gale_caller")    {    }

    enum class Spells : uint32
    {
        DERVISH = 153905,
    };

    enum class Events : uint32
    {
        DERVISH = 1, // 20 seconds duration so heavy respawn.
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_driving_gale_callerAI(creature);
    }

    struct mob_driving_gale_callerAI : public ScriptedAI
    {
        mob_driving_gale_callerAI(Creature* creature) : ScriptedAI(creature),
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
            m_events.ScheduleEvent(uint32(Events::DERVISH), urand(5000, 7000));
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
            case uint32(Events::DERVISH):
                m_events.ScheduleEvent(uint32(Events::DERVISH), urand(5000, 7000));
                me->CastSpell(me->GetVictim(), uint32(Spells::DERVISH));
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

class mob_adept_of_the_dawn : public CreatureScript
{
public:
    // Entry: 79467
    mob_adept_of_the_dawn() : CreatureScript("mob_adept_of_the_dawn")    {    }

    enum class Spells : uint32
    {
        CRAFT_SUN_TRINCKET = 153521,
        FLASH_HEAL = 152894,
    };

    enum class Events : uint32
    {
        CRAFT_SUN_TRINCKET = 1, // 20 seconds duration so heavy respawn.
        FLASH_HEAL = 2          // Every 2 to 5 seconds.
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_adept_of_the_dawnAI(creature);
    }

    struct mob_adept_of_the_dawnAI : public ScriptedAI
    {
        mob_adept_of_the_dawnAI(Creature* creature) : ScriptedAI(creature),
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
            // FIXME: Script Sun trinket.
            //m_events.ScheduleEvent(uint32(Events::CRAFT_SUN_TRINCKET), urand(3000, 5000));
            m_events.ScheduleEvent(uint32(Events::FLASH_HEAL), urand(5000, 8000));
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
            case uint32(Events::CRAFT_SUN_TRINCKET):
                m_events.ScheduleEvent(uint32(Events::CRAFT_SUN_TRINCKET), urand(20000, 25000));
                me->CastSpell(me, uint32(Spells::CRAFT_SUN_TRINCKET));
                break;
            case uint32(Events::FLASH_HEAL):
                m_events.ScheduleEvent(uint32(Events::FLASH_HEAL), urand(5000, 8000));
                me->CastSpell(me, uint32(Spells::FLASH_HEAL));
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

class mob_sky_reach_overlord : public CreatureScript
{
public:
    // Entry: 75975
    mob_sky_reach_overlord() : CreatureScript("mob_sky_reach_overlord")    {    }

    enum class Spells : uint32
    {
        TORN_FEATHERS = 153178,
        BEAT_LOW_BORN_DNT = 178635, // Visual when not attacking.
    };

    enum class Events : uint32
    {
        TORN_FEATHERS = 1,
        BEAT_LOW_BORN_DNT = 2
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_sky_reach_overlordAI(creature);
    }

    struct mob_sky_reach_overlordAI : public ScriptedAI
    {
        mob_sky_reach_overlordAI(Creature* creature) : ScriptedAI(creature),
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
            m_events.ScheduleEvent(uint32(Events::TORN_FEATHERS), urand(1000, 3000));
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
            case uint32(Events::TORN_FEATHERS):
                m_events.ScheduleEvent(uint32(Events::TORN_FEATHERS), 125000);
                me->CastSpell(me, uint32(Spells::TORN_FEATHERS));
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

class mob_wind_familiar : public CreatureScript
{
public:
    // Entry: 76102
    mob_wind_familiar() : CreatureScript("mob_wind_familiar")    {    }

    enum class Spells : uint32
    {
        SERENE = 153716,
        WIND_BURST = 157352,
    };

    enum class Events : uint32
    {
        WIND_BURST = 1,
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_wind_familiarAI(creature);
    }

    struct mob_wind_familiarAI : public ScriptedAI
    {
        mob_wind_familiarAI(Creature* creature) : ScriptedAI(creature),
            m_Instance(creature->GetInstanceScript()),
            m_events()
        {
        }

        void Reset()
        {
            m_events.Reset();
        }

        void JustDied(Unit* /*p_Killer*/)
        {
            // When dying, Serene aura release all the nearby friends from crowd-control.
            std::list<Unit*> l_TargetList;
            float l_Radius = 10.0f;

            me->GetFriendlyUnitListInRange(l_TargetList, l_Radius, true);
            for (Unit* l_Unit : l_TargetList)
            {
                if (l_Unit)
                    l_Unit->RemoveCharmAuras();
            }
        }

        void EnterCombat(Unit* /*who*/)
        {
            m_events.ScheduleEvent(uint32(Events::WIND_BURST), urand(4000, 6000));
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
            case uint32(Events::WIND_BURST):
                m_events.ScheduleEvent(uint32(Events::WIND_BURST), urand(4000, 6000));
                me->CastSpell(me->GetVictim(), uint32(Spells::WIND_BURST));
                break;
            default:
                break;
            }
        }

        InstanceScript* m_Instance;
        EventMap m_events;
    };
};

class mob_solar_familiar : public CreatureScript
{
public:
    // Entry: 76097
    mob_solar_familiar() : CreatureScript("mob_solar_familiar")    {    }

    enum class Spells : uint32
    {
        EMPOWER = 159290,   // 2:40:45 - 2:40:52
        FLASH_BANG = 152953, // Something like every 10 seconds and when it dies.
    };

    enum class Events : uint32
    {
        EMPOWER = 1,
        FLASH_BANG = 2
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_solar_familiarAI(creature);
    }

    struct mob_solar_familiarAI : public ScriptedAI
    {
        mob_solar_familiarAI(Creature* creature) : ScriptedAI(creature),
            m_Instance(creature->GetInstanceScript()),
            m_events()
        {
        }

        void Reset()
        {
            m_events.Reset();
        }

        void JustDied(Unit* /*p_Killer*/)
        {
            // When Familiar dies, Flash Bang occures once again.
            me->CastSpell(me, uint32(Spells::FLASH_BANG));
        }

        void EnterCombat(Unit* /*who*/)
        {
            m_events.ScheduleEvent(uint32(Events::EMPOWER), urand(5000, 7000));
            m_events.ScheduleEvent(uint32(Events::FLASH_BANG), urand(5000, 8000));
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
            case uint32(Events::FLASH_BANG):
                m_events.ScheduleEvent(uint32(Events::FLASH_BANG), urand(5000, 8000));
                me->CastSpell(me, uint32(Spells::FLASH_BANG));
                break;
            case uint32(Events::EMPOWER):
                m_events.ScheduleEvent(uint32(Events::EMPOWER), urand(5000, 7000));               
                if (Unit* l_Unit = me->SelectNearestPlayer(30.0f))
                    me->CastSpell(l_Unit, uint32(Spells::EMPOWER));
                break;
            default:
                break;
            }
        }

        InstanceScript* m_Instance;
        EventMap m_events;
    };
};

class mob_soaring_chrakram_master : public CreatureScript
{
public:
    // Entry: 76132
    mob_soaring_chrakram_master() : CreatureScript("mob_soaring_chrakram_master")    {    }

    enum class Spells : uint32
    {
        THROW_CHAKRAM_YELLOW = 169689,  // 2:40:57 - 2:40:58 2:41:00 - 2:41:06
        THROW_CHAKRAM_WHITE = 169690,   // 2:40:48 - 2:40:52 - 2:40:56 - 2:40:57
        THROW_CHAKRAM_2 = 169687,       // Launched with the two previous ones.
        THROW_CHAKRAM_DNT = 178612,
        SPINNING_BLADE = 153544,    // 2:40:16 - 2:40:35
        BLADE_DANCE = 153581,       // 2:40:56 - 2:41:17
    };

    enum class Events : uint32
    {
        THROW_CHAKRAM = 1,
        SPINNING_BLADE = 2,
        BLADE_DANCE = 3,
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_soaring_chrakram_masterAI(creature);
    }

    struct mob_soaring_chrakram_masterAI : public ScriptedAI
    {
        mob_soaring_chrakram_masterAI(Creature* creature) : ScriptedAI(creature),
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
            m_events.ScheduleEvent(uint32(Events::THROW_CHAKRAM), urand(2000, 3000));
            m_events.ScheduleEvent(uint32(Events::SPINNING_BLADE), urand(8000, 10000));
            m_events.ScheduleEvent(uint32(Events::BLADE_DANCE), urand(17000, 25000));
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
            case uint32(Events::THROW_CHAKRAM):
                m_events.ScheduleEvent(uint32(Events::THROW_CHAKRAM), urand(2000, 3000));

                if (urand(0, 1) == 0)
                {
                    
                    if (Player* player = me->SelectRandomPlayerInRange(5.0f, true))
                        me->CastSpell(player, uint32(Spells::THROW_CHAKRAM_YELLOW));
                }
                else
                {
                    if (Player* player = me->SelectRandomPlayerInRange(5.0f, true))
                        me->CastSpell(player, uint32(Spells::THROW_CHAKRAM_WHITE));
                }
                me->CastSpell(me->GetVictim(), uint32(Spells::THROW_CHAKRAM_2)); // Always launched with the two others.
                break;
            case uint32(Events::SPINNING_BLADE):
                m_events.ScheduleEvent(uint32(Events::SPINNING_BLADE), urand(8000, 10000));
                if (Player* player = me->SelectRandomPlayerInRange(45.0f, true))
                    me->CastSpell(player, uint32(Spells::SPINNING_BLADE));
                break;
            case uint32(Events::BLADE_DANCE):
                m_events.ScheduleEvent(uint32(Events::BLADE_DANCE), urand(17000, 25000));
                me->CastSpell(me->GetVictim(), uint32(Spells::BLADE_DANCE));
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

class mob_herald_of_sunrise : public CreatureScript
{
public:
    // Entry: 78933
    mob_herald_of_sunrise() : CreatureScript("mob_herald_of_sunrise")  {    }

    enum class Spells : uint32
    {
        SOLAR_ZONE = 163330,    // 2:40:57 - 2:41:11
        MAGMA_EXPLOSION_SUPREME = 152864, // -FIXME: NOT WORKING
        SOLAR_HEAL = 152893,    // 2:41:08
        FLASH_HEAL = 152894,
    };

    enum class Events : uint32
    {
        SOLAR_ZONE = 1,
        SOLAR_HEAL = 2,
        FLASH_HEAL = 3
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_herald_of_sunriseAI(creature);
    }

    struct mob_herald_of_sunriseAI : public ScriptedAI
    {
        mob_herald_of_sunriseAI(Creature* creature) : ScriptedAI(creature),
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
            m_events.ScheduleEvent(uint32(Events::SOLAR_ZONE), urand(14500, 17000));
            m_events.ScheduleEvent(uint32(Events::SOLAR_HEAL), urand(5500, 7000));
            m_events.ScheduleEvent(uint32(Events::FLASH_HEAL), urand(5500, 7000));
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
            case uint32(Events::SOLAR_ZONE):
                m_events.ScheduleEvent(uint32(Events::SOLAR_ZONE), urand(14500, 17000));
                if (Unit* l_Unit = me->SelectNearestPlayer(30.0f))
                    me->CastSpell(l_Unit, uint32(Spells::SOLAR_ZONE));
                break;
            case uint32(Events::SOLAR_HEAL):
                m_events.ScheduleEvent(uint32(Events::SOLAR_HEAL), urand(5500, 7000));
                if (Unit* l_Unit = me->SelectNearestPlayer(30.0f))
                    me->CastSpell(l_Unit, uint32(Spells::SOLAR_HEAL));
                break;
            case uint32(Events::FLASH_HEAL):
                m_events.ScheduleEvent(uint32(Events::FLASH_HEAL), urand(5500, 7000));
                me->CastSpell(me, uint32(Spells::FLASH_HEAL));
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

class mob_whirling_dervish_77605 : public CreatureScript
{
public:
    // Entry: 77605
    mob_whirling_dervish_77605() : CreatureScript("mob_whirling_dervish_77605")  {   }

    enum class Spells : uint32
    {
        STORM = 156515,
        DERVISH = 153905,
    };

    enum class Events : uint32
    {
        STORM = 1,
        DERVISH = 2
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_whirling_dervish_77605AI(creature);
    }

    struct mob_whirling_dervish_77605AI : public ScriptedAI
    {
        mob_whirling_dervish_77605AI(Creature* creature) : ScriptedAI(creature),
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
            m_events.ScheduleEvent(uint32(Events::STORM), urand(8000, 13000));
            m_events.ScheduleEvent(uint32(Events::DERVISH), urand(5500, 7000));
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
            case uint32(Events::STORM):
                m_events.ScheduleEvent(uint32(Events::STORM), urand(8000, 13000));
                me->CastSpell(me, uint32(Spells::STORM));
                break;
            case uint32(Events::DERVISH):
                m_events.ScheduleEvent(uint32(Events::DERVISH), urand(5500, 7000));
                me->CastSpell(me, uint32(Spells::DERVISH));
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

class mob_blooded_blade_feather : public CreatureScript
{
public:
    // Entry: 76205
    mob_blooded_blade_feather() : CreatureScript("mob_blooded_blade_feather")  {   }

    enum class Spells : uint32
    {
        PIERCING_RUSH = 165731,
        DESPAWN_AREA_TRIGGERS = 138175,
    };

    enum class Events : uint32
    {
        PIERCING_RUSH = 1
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_blooded_blade_featherAI(creature);
    }

    struct mob_blooded_blade_featherAI : public ScriptedAI
    {
        mob_blooded_blade_featherAI(Creature* creature) : ScriptedAI(creature),
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
            m_events.ScheduleEvent(uint32(Events::PIERCING_RUSH), urand(5000, 13000));
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
            case uint32(Events::PIERCING_RUSH):
                m_events.ScheduleEvent(uint32(Events::PIERCING_RUSH), urand(5000, 13000));
                me->CastSpell(me->GetVictim(), uint32(Spells::PIERCING_RUSH));
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

class mob_initiate_of_the_rising_sun : public CreatureScript
{
public:
    // Entry: 79466
    mob_initiate_of_the_rising_sun() : CreatureScript("mob_initiate_of_the_rising_sun")  {  }

    enum class Spells : uint32
    {
        MAGMA_EXPLOSION_SUPREME = 152864, // FIXME: NOT WORKING, Didn't see it in the sniffs.
        SOLAR_SHOWER = 160274,          // Around 10 seconds.
        FLASH_HEAL = 152894,            // Around 6 seconds.
        CONJURE_SUN_ORB_DNT = 178618, // Visual to do when closed to sun orbs.
    };

    enum class Events : uint32
    {
        SOLAR_SHOWER = 1,
        FLASH_HEAL = 2
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_initiate_of_the_rising_sunAI(creature);
    }

    struct mob_initiate_of_the_rising_sunAI : public ScriptedAI
    {
        mob_initiate_of_the_rising_sunAI(Creature* creature) : ScriptedAI(creature),
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
            m_events.ScheduleEvent(uint32(Events::SOLAR_SHOWER), urand(8000, 13000));
            m_events.ScheduleEvent(uint32(Events::FLASH_HEAL), urand(5500, 7000));
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
            case uint32(Events::SOLAR_SHOWER):
                m_events.ScheduleEvent(uint32(Events::SOLAR_SHOWER), urand(8000, 13000));
                me->CastSpell(me, uint32(Spells::SOLAR_SHOWER));
                break;
            case uint32(Events::FLASH_HEAL):
                m_events.ScheduleEvent(uint32(Events::FLASH_HEAL), urand(5500, 7000));
                me->CastSpell(me, uint32(Spells::FLASH_HEAL));
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

class mob_diving_chakram_spinner : public CreatureScript
{
public:
    // Entry: 76116
    mob_diving_chakram_spinner() : CreatureScript("mob_diving_chakram_spinner") {  }

    enum class Spells : uint32
    {
        THROW_CHAKRAM_YELLOW = 169689,  // 2:40:57 - 2:40:58 2:41:00 - 2:41:06
        THROW_CHAKRAM_WHITE = 169690,   // 2:40:48 - 2:40:52 - 2:40:56 - 2:40:57
        THROW_CHAKRAM_2 = 169687,       // Launched with the two previous ones.
        THROW_CHAKRAM_DNT = 178612,
        SPINNING_BLADE = 153544,    // 2:40:16 - 2:40:35
    };

    enum class Events : uint32
    {
        THROW_CHAKRAM = 1,
        SPINNING_BLADE = 2
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_diving_chakram_spinnerAI(creature);
    }

    struct mob_diving_chakram_spinnerAI : public ScriptedAI
    {
        mob_diving_chakram_spinnerAI(Creature* creature) : ScriptedAI(creature),
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
            m_events.ScheduleEvent(uint32(Events::THROW_CHAKRAM), urand(2000, 3000));
            m_events.ScheduleEvent(uint32(Events::SPINNING_BLADE), urand(8000, 10000));
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
            case uint32(Events::THROW_CHAKRAM):
                m_events.ScheduleEvent(uint32(Events::THROW_CHAKRAM), urand(2000, 3000));

                if (urand(0, 1) == 0)
                {
                    if (Player* player = me->SelectRandomPlayerInRange(5.0f, true))
                        me->CastSpell(player, uint32(Spells::THROW_CHAKRAM_YELLOW));
                }
                else
                {
                    if (Player* player = me->SelectRandomPlayerInRange(5.0f, true))
                        me->CastSpell(player, uint32(Spells::THROW_CHAKRAM_WHITE));
                }
                me->CastSpell(me->GetVictim(), uint32(Spells::THROW_CHAKRAM_2)); // Always launched with the two others.
                break;
            case uint32(Events::SPINNING_BLADE):
                m_events.ScheduleEvent(uint32(Events::SPINNING_BLADE), urand(8000, 10000));
                if (Player* player = me->SelectRandomPlayerInRange(45.0f, true))
                    me->CastSpell(player, uint32(Spells::SPINNING_BLADE));
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

class mob_blinding_solar_fare : public CreatureScript
{
public:
    // Entry: 79462
    mob_blinding_solar_fare() : CreatureScript("mob_blinding_solar_fare")  {  }

    enum class Spells : uint32
    {
        SOLAR_WRATH = 157020,           // 2:40:56 - 2:41:00 - 2:41:05 - 2:41:08
        SOLAR_DETONATION_2 = 160282,      // 2:41:05
        SOLAR_DETONATION = 160288,    // 2:40:59 - 2:41:12
    };

    enum class Texts : int32
    {
        SOLAR_DETONATION = 14061,
    };

    enum class Events : uint32
    {
        SOLAR_WRATH = 1,
        SOLAR_DETONATION = 2
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_blinding_solar_fareAI(creature);
    }

    struct mob_blinding_solar_fareAI : public ScriptedAI
    {
        mob_blinding_solar_fareAI(Creature* creature) : ScriptedAI(creature),
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
            m_events.ScheduleEvent(uint32(Events::SOLAR_WRATH), urand(3000, 5000));
            m_events.ScheduleEvent(uint32(Events::SOLAR_DETONATION), urand(10000, 14000));
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
            case uint32(Events::SOLAR_WRATH):
                m_events.ScheduleEvent(uint32(Events::SOLAR_WRATH), urand(3000, 5000));
                me->CastSpell(me->GetVictim(), uint32(Spells::SOLAR_WRATH));
                break;
            case uint32(Events::SOLAR_DETONATION):
                m_events.ScheduleEvent(uint32(Events::SOLAR_DETONATION), urand(10000, 14000));
                if (Player* player = me->SelectRandomPlayerInRange(45.0f, true))
                {
                    me->CastSpell(player, uint32(Spells::SOLAR_DETONATION));
                    player->Whisper(int32(Texts::SOLAR_DETONATION), player, true);
                }
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

void AddSC_mob_instance_skyreach()
{
    // Mobs.
    new mob_blinding_solar_fare();
    new mob_diving_chakram_spinner();
    new mob_initiate_of_the_rising_sun();
    new mob_whirling_dervish_77605();
    new mob_blooded_blade_feather();
    new mob_herald_of_sunrise();
    new mob_soaring_chrakram_master();
    new mob_solar_familiar();
    new mob_sky_reach_overlord();
    new mob_adept_of_the_dawn();
    new mob_wind_familiar();
    new mob_driving_gale_caller();
    new mob_adorned_bladetalon();
    new mob_skyreach_sun_talon();
    new mob_dread_raven_hatchling();
    new mob_solar_magnifier();
    new mob_defense_construct();
    new mob_radiant_supernova();
    new mob_young_kaliri();
    new mob_grand_defense_construct();
    new npc_gossip_intro_outro_84782();
}
