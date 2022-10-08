#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"

enum eIkIkTheNimbleSpells
{
    SPELL_BANANARANG     = 125311,
    SPELL_GOING_BANANAS  = 125363,
    SPELL_TOSS_FILTH     = 125365,
    SPELL_UNSTABLE_SERUM = 127373
};

enum eIkIkTheNimbleEvents
{
    EVENT_BANANARANG     = 1,
    EVENT_GOING_BANANAS  = 2,
    EVENT_TOSS_FILTH     = 3,
    EVENT_UNSTABLE_SERUM = 4
};

class mob_ik_ik_the_nimble : public CreatureScript
{
    public:
        mob_ik_ik_the_nimble() : CreatureScript("mob_ik_ik_the_nimble")
        {
        }

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_ik_ik_the_nimbleAI(creature);
        }

        struct mob_ik_ik_the_nimbleAI : public ScriptedAI
        {
            mob_ik_ik_the_nimbleAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_BANANARANG, 10000);
                events.ScheduleEvent(EVENT_GOING_BANANAS, 17000);
                events.ScheduleEvent(EVENT_TOSS_FILTH, 22000);
                events.ScheduleEvent(EVENT_UNSTABLE_SERUM, 30000);
            }

            void JustDied(Unit* /*killer*/) override
            {
            }

            void JustSummoned(Creature* summon) override
            {
                summon->DespawnOrUnsummon(15000);
                summon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BANANARANG:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_BANANARANG, false);
                            events.ScheduleEvent(EVENT_BANANARANG, 80000);
                            break;
                        case EVENT_GOING_BANANAS:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_GOING_BANANAS, false);
                            events.ScheduleEvent(EVENT_GOING_BANANAS, 70000);
                            break;
                        case EVENT_TOSS_FILTH:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_TOSS_FILTH, false);
                            events.ScheduleEvent(EVENT_TOSS_FILTH, 40000);
                            break;
                        case EVENT_UNSTABLE_SERUM:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_UNSTABLE_SERUM, false);
                            events.ScheduleEvent(EVENT_UNSTABLE_SERUM, 20000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

enum eAdjunctKreeZotSpells
{
    SPELL_SHA_SPIT             = 126790,
    SPELL_SHA_SPIT_2           = 126792,
    SPELL_SLICING_STRIKE       = 126799,
    SPELL_WRATH_OF_THE_EMPRESS = 128395,
};

enum eAdjunctKreeZotEvents
{
    EVENT_SHA_SPIT             = 1,
    EVENT_SHA_SPIT_2           = 2,
    EVENT_SLICING_STRIKE       = 3,
    EVENT_WRATH_OF_THE_EMPRESS = 4,
};

class mob_adjunct_kree_zot : public CreatureScript
{
    public:
        mob_adjunct_kree_zot() : CreatureScript("mob_adjunct_kree_zot")
        {
        }

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_adjunct_kree_zotAI(creature);
        }

        struct mob_adjunct_kree_zotAI : public ScriptedAI
        {
            mob_adjunct_kree_zotAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_SHA_SPIT, 10000);
                events.ScheduleEvent(EVENT_SHA_SPIT_2, 20000);
                events.ScheduleEvent(EVENT_SLICING_STRIKE, 25000);
                events.ScheduleEvent(EVENT_WRATH_OF_THE_EMPRESS, 35000);
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SHA_SPIT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_SHA_SPIT, false);
                            events.ScheduleEvent(EVENT_SHA_SPIT, 10000);
                            break;
                        case EVENT_SHA_SPIT_2:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_SHA_SPIT_2, false);
                            events.ScheduleEvent(EVENT_SHA_SPIT_2, 25000);
                            break;
                        case EVENT_SLICING_STRIKE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_SLICING_STRIKE, false);
                            events.ScheduleEvent(EVENT_SLICING_STRIKE, 20000);
                            break;
                        case EVENT_WRATH_OF_THE_EMPRESS:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_WRATH_OF_THE_EMPRESS, false);
                            events.ScheduleEvent(EVENT_WRATH_OF_THE_EMPRESS, 30000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

enum eDreadFearbringerEvents
{
    EVENT_UNSTABLE_SERUM_2 = 1,
};

class mob_dread_fearbringer : public CreatureScript
{
    public:
        mob_dread_fearbringer() : CreatureScript("mob_dread_fearbringer")
        {
        }

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_dread_fearbringerAI(creature);
        }

        struct mob_dread_fearbringerAI : public ScriptedAI
        {
            mob_dread_fearbringerAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_UNSTABLE_SERUM_2, 10000);
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_UNSTABLE_SERUM_2:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_UNSTABLE_SERUM, false);
                            events.ScheduleEvent(EVENT_UNSTABLE_SERUM_2, 10000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

enum eDreadKunchongSpells
{
    SPELL_DREAD_SLASH               = 128022,
    SPELL_SEEK_AND_DESTROY          = 127357,
    SPELL_SEEK_AND_DESTROY_2        = 127358,
    SPELL_SEEK_AND_DESTROY_3        = 127359,
    SPELL_SEEK_AND_DESTROY_POWER    = 127859,
    SPELL_SEEK_AND_DESTROY_WISDOM   = 127860,
    SPELL_SEEK_AND_DESTROY_VELOCITY = 127861,

};

enum eDreadKunchongEvents
{
    EVENT_DREAD_SLASH        = 1,
    EVENT_SEEK_AND_DESTROY   = 2,
    EVENT_SEEK_AND_DESTROY_2 = 3,
    EVENT_SEEK_AND_DESTROY_3 = 4,
    EVENT_UNSTABLE_SERUM_3   = 5,
};

class mob_dread_kunchong : public CreatureScript
{
    public:
        mob_dread_kunchong() : CreatureScript("mob_dread_kunchong")
        {
        }

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_dread_kunchongAI(creature);
        }

        struct mob_dread_kunchongAI : public ScriptedAI
        {
            mob_dread_kunchongAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_DREAD_SLASH, 25000);
                events.ScheduleEvent(EVENT_UNSTABLE_SERUM_3, 22000);
            }

            void EnterCombat(Unit* who) override
            {
                Player* player = who->ToPlayer();

                if (!player)
                    return;

                switch (player->GetSpecializationId(player->GetActiveSpec()))
                {
                    case SPEC_MAGE_ARCANE:
                    case SPEC_MAGE_FIRE:
                    case SPEC_MAGE_FROST:
                    case SPEC_PALADIN_HOLY:
                    case SPEC_DRUID_BALANCE:
                    case SPEC_PRIEST_DISCIPLINE:
                    case SPEC_PRIEST_HOLY:
                    case SPEC_PRIEST_SHADOW:
                    case SPEC_DRUID_RESTORATION:
                    case SPEC_SHAMAN_ELEMENTAL:
                    case SPEC_SHAMAN_RESTORATION:
                    case SPEC_WARLOCK_AFFLICTION:
                    case SPEC_WARLOCK_DEMONOLOGY:
                    case SPEC_WARLOCK_DESTRUCTION:
                    case SPEC_MONK_MISTWEAVER:
                        DoCast(me, SPELL_SEEK_AND_DESTROY_2, true);
                        break;
                    case SPEC_DRUID_CAT:
                    case SPEC_DRUID_BEAR:
                    case SPEC_HUNTER_BEASTMASTER:
                    case SPEC_HUNTER_MARKSMAN:
                    case SPEC_HUNTER_SURVIVAL:
                    case SPEC_ROGUE_ASSASSINATION:
                    case SPEC_ROGUE_COMBAT:
                    case SPEC_ROGUE_SUBTLETY:
                    case SPEC_SHAMAN_ENHANCEMENT:
                    case SPEC_MONK_WINDWALKER:
                        DoCast(me, SPELL_SEEK_AND_DESTROY_3, true);
                        break;
                    case SPEC_DK_BLOOD:
                    case SPEC_DK_FROST:
                    case SPEC_DK_UNHOLY:
                    case SPEC_PALADIN_PROTECTION:
                    case SPEC_PALADIN_RETRIBUTION:
                    case SPEC_WARRIOR_ARMS:
                    case SPEC_WARRIOR_FURY:
                    case SPEC_WARRIOR_PROTECTION:
                    case SPEC_MONK_BREWMASTER:
                    default:
                        DoCast(me, SPELL_SEEK_AND_DESTROY, true);
                        break;
                }
            }

            void JustDied(Unit* killer)
            {
                if (me->HasAura(SPELL_SEEK_AND_DESTROY))
                    me->CastSpell(killer, SPELL_SEEK_AND_DESTROY_POWER, true);

                if (me->HasAura(SPELL_SEEK_AND_DESTROY_2))
                    me->CastSpell(killer, SPELL_SEEK_AND_DESTROY_WISDOM, true);

                if (me->HasAura(SPELL_SEEK_AND_DESTROY_3))
                    me->CastSpell(killer, SPELL_SEEK_AND_DESTROY_VELOCITY, true);
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_DREAD_SLASH:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_DREAD_SLASH, false);
                            events.ScheduleEvent(EVENT_DREAD_SLASH, 25000);
                            break;
                        case EVENT_UNSTABLE_SERUM_3:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_UNSTABLE_SERUM, false);
                            events.ScheduleEvent(EVENT_UNSTABLE_SERUM_3, 30000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

enum eDreadMatriarchSpells
{
    SPELL_POUNCE        = 119579,
    SPELL_POUNCE_DAMAGE = 119578,
    SPELL_RAVAGE        = 126799,
};

enum eDreadMatriarchEvents
{
    EVENT_POUNCE           = 1,
    EVENT_RAVAGE           = 2,
    EVENT_UNSTABLE_SERUM_4 = 3,
};

class mob_dread_matriarch : public CreatureScript
{
    public:
        mob_dread_matriarch() : CreatureScript("mob_dread_matriarch")
        {
        }

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_dread_matriarchAI(creature);
        }

        struct mob_dread_matriarchAI : public ScriptedAI
        {
            mob_dread_matriarchAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_POUNCE, 17000);
                events.ScheduleEvent(EVENT_RAVAGE, 23000);
                events.ScheduleEvent(EVENT_UNSTABLE_SERUM_4, 8000);
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_POUNCE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                            {
                                me->CastSpell(target, SPELL_POUNCE, false);
                                me->CastSpell(target, SPELL_POUNCE_DAMAGE, false);
                            }
                            events.ScheduleEvent(EVENT_POUNCE, 20000);
                            break;
                        case EVENT_RAVAGE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_RAVAGE, false);
                            events.ScheduleEvent(EVENT_RAVAGE, 27000);
                            break;
                        case EVENT_UNSTABLE_SERUM_4:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_UNSTABLE_SERUM, false);
                            events.ScheduleEvent(EVENT_UNSTABLE_SERUM_4, 8000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

enum eElderSpindlegrinSpells
{
    SPELL_CHARGE              = 32323,
    SPELL_MONSTROUS_UNDERBITE = 127905,
    SPELL_REND                = 13445,
};

enum eElderSpindlegrinEvents
{
    EVENT_CHARGE_2            = 1,
    EVENT_MONSTROUS_UNDERBITE = 2,
    EVENT_REND                = 3,
    EVENT_UNSTABLE_SERUM_5    = 4,
};

class mob_elder_spindlegrin : public CreatureScript
{
    public:
        mob_elder_spindlegrin() : CreatureScript("mob_elder_spindlegrin")
        {
        }

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_elder_spindlegrinAI(creature);
        }

        struct mob_elder_spindlegrinAI : public ScriptedAI
        {
            mob_elder_spindlegrinAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_CHARGE_2, 17000);
                events.ScheduleEvent(EVENT_MONSTROUS_UNDERBITE, 23000);
                events.ScheduleEvent(EVENT_REND, 8000);
                events.ScheduleEvent(EVENT_UNSTABLE_SERUM_5, 12000);
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CHARGE_2:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_CHARGE, false);
                            events.ScheduleEvent(EVENT_CHARGE_2, 20000);
                            break;
                        case EVENT_MONSTROUS_UNDERBITE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_MONSTROUS_UNDERBITE, false);
                            events.ScheduleEvent(EVENT_MONSTROUS_UNDERBITE, 40000);
                            break;
                        case EVENT_REND:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_REND, false);
                            events.ScheduleEvent(EVENT_REND, 30000);
                            break;
                        case EVENT_UNSTABLE_SERUM_5:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_UNSTABLE_SERUM, false);
                            events.ScheduleEvent(EVENT_UNSTABLE_SERUM_5, 22000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

enum eHulkingKorThikFleshrenderSpells
{
    SPELL_PINCH_LIMB      = 124800,
    SPELL_VICIOUS_STRIKES = 124296,
};

enum eHulkingKorThikFleshrenderEvents
{
    EVENT_PINCH_LIMB       = 1,
    EVENT_VICIOUS_STRIKES  = 2,
    EVENT_UNSTABLE_SERUM_6 = 3,
};

class mob_hulking_kor_thik_fleshrender : public CreatureScript
{
    public:
        mob_hulking_kor_thik_fleshrender() : CreatureScript("mob_hulking_kor_thik_fleshrender")
        {
        }

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_hulking_kor_thik_fleshrenderAI(creature);
        }

        struct mob_hulking_kor_thik_fleshrenderAI : public ScriptedAI
        {
            mob_hulking_kor_thik_fleshrenderAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_PINCH_LIMB, 17000);
                events.ScheduleEvent(EVENT_VICIOUS_STRIKES, 23000);
                events.ScheduleEvent(EVENT_UNSTABLE_SERUM_6, 12000);
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_PINCH_LIMB:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_PINCH_LIMB, false);
                            events.ScheduleEvent(EVENT_PINCH_LIMB, 20000);
                            break;
                        case EVENT_VICIOUS_STRIKES:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_VICIOUS_STRIKES, false);
                            events.ScheduleEvent(EVENT_VICIOUS_STRIKES, 40000);
                            break;
                        case EVENT_UNSTABLE_SERUM_6:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_UNSTABLE_SERUM, false);
                            events.ScheduleEvent(EVENT_UNSTABLE_SERUM_6, 22000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

enum eIkThikAmberstingerSpells
{
    SPELL_CLAW        = 127943,
    SPELL_SONIC_SHOCK = 124734,
    SPELL_TAIL_STRIKE = 127935,
};

enum eIkThikAmberstingerEvents
{
    EVENT_CLAW             = 1,
    EVENT_SONIC_SHOCK      = 2,
    EVENT_TAIL_STRIKE      = 3,
    EVENT_UNSTABLE_SERUM_7 = 4,
};

class mob_ik_thik_amberstinger : public CreatureScript
{
    public:
        mob_ik_thik_amberstinger() : CreatureScript("mob_ik_thik_amberstinger")
        {
        }

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_ik_thik_amberstingerAI(creature);
        }

        struct mob_ik_thik_amberstingerAI : public ScriptedAI
        {
            mob_ik_thik_amberstingerAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_CLAW, 17000);
                events.ScheduleEvent(EVENT_SONIC_SHOCK, 23000);
                events.ScheduleEvent(EVENT_TAIL_STRIKE, 20000);
                events.ScheduleEvent(EVENT_UNSTABLE_SERUM_7, 15000);
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CLAW:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_CLAW, false);
                            events.ScheduleEvent(EVENT_CLAW, 20000);
                            break;
                        case EVENT_SONIC_SHOCK:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_SONIC_SHOCK, false);
                            events.ScheduleEvent(EVENT_SONIC_SHOCK, 40000);
                            break;
                        case EVENT_TAIL_STRIKE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_TAIL_STRIKE, false);
                            events.ScheduleEvent(EVENT_TAIL_STRIKE, 22000);
                            break;
                        case EVENT_UNSTABLE_SERUM_7:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_UNSTABLE_SERUM, false);
                            events.ScheduleEvent(EVENT_UNSTABLE_SERUM_7, 22000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

enum eIkThikKunchongEvents
{
    EVENT_DREAD_SLASH_2    = 1,
    EVENT_UNSTABLE_SERUM_8 = 2,
};

class mob_ik_thik_kunchong : public CreatureScript
{
    public:
        mob_ik_thik_kunchong() : CreatureScript("mob_ik_thik_kunchong")
        {
        }

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_ik_thik_kunchongAI(creature);
        }

        struct mob_ik_thik_kunchongAI : public ScriptedAI
        {
            mob_ik_thik_kunchongAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_DREAD_SLASH_2, 17000);
                events.ScheduleEvent(EVENT_UNSTABLE_SERUM_8, 10000);
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_DREAD_SLASH_2:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_DREAD_SLASH, false);
                            events.ScheduleEvent(EVENT_DREAD_SLASH_2, 10000);
                            break;
                        case EVENT_UNSTABLE_SERUM_8:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_UNSTABLE_SERUM, false);
                            events.ScheduleEvent(EVENT_UNSTABLE_SERUM_8, 15000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

enum eItThikTerrorclawEvents
{
    EVENT_TAIL_STRIKE_2    = 1,
    EVENT_CLAW_2           = 2,
    EVENT_UNSTABLE_SERUM_9 = 3,
};

class mob_ik_thik_terrorclaw : public CreatureScript
{
    public:
        mob_ik_thik_terrorclaw() : CreatureScript("mob_ik_thik_terrorclaw")
        {
        }

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_ik_thik_terrorclawAI(creature);
        }

        struct mob_ik_thik_terrorclawAI : public ScriptedAI
        {
            mob_ik_thik_terrorclawAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_TAIL_STRIKE, 5000);
                events.ScheduleEvent(EVENT_CLAW, 17000);
                events.ScheduleEvent(EVENT_UNSTABLE_SERUM_9, 22000);
            }

            void EnterCombat(Unit* who) override
            {
                Player* player = who->ToPlayer();

                if (!player)
                    return;

                switch (player->GetSpecializationId(player->GetActiveSpec()))
                {
                    case SPEC_MAGE_ARCANE:
                    case SPEC_MAGE_FIRE:
                    case SPEC_MAGE_FROST:
                    case SPEC_PALADIN_HOLY:
                    case SPEC_DRUID_BALANCE:
                    case SPEC_PRIEST_DISCIPLINE:
                    case SPEC_PRIEST_HOLY:
                    case SPEC_PRIEST_SHADOW:
                    case SPEC_DRUID_RESTORATION:
                    case SPEC_SHAMAN_ELEMENTAL:
                    case SPEC_SHAMAN_RESTORATION:
                    case SPEC_WARLOCK_AFFLICTION:
                    case SPEC_WARLOCK_DEMONOLOGY:
                    case SPEC_WARLOCK_DESTRUCTION:
                    case SPEC_MONK_MISTWEAVER:
                        DoCast(me, SPELL_SEEK_AND_DESTROY_2, true);
                        break;
                    case SPEC_DRUID_CAT:
                    case SPEC_DRUID_BEAR:
                    case SPEC_HUNTER_BEASTMASTER:
                    case SPEC_HUNTER_MARKSMAN:
                    case SPEC_HUNTER_SURVIVAL:
                    case SPEC_ROGUE_ASSASSINATION:
                    case SPEC_ROGUE_COMBAT:
                    case SPEC_ROGUE_SUBTLETY:
                    case SPEC_SHAMAN_ENHANCEMENT:
                    case SPEC_MONK_WINDWALKER:
                        DoCast(me, SPELL_SEEK_AND_DESTROY_3, true);
                        break;
                    case SPEC_DK_BLOOD:
                    case SPEC_DK_FROST:
                    case SPEC_DK_UNHOLY:
                    case SPEC_PALADIN_PROTECTION:
                    case SPEC_PALADIN_RETRIBUTION:
                    case SPEC_WARRIOR_ARMS:
                    case SPEC_WARRIOR_FURY:
                    case SPEC_WARRIOR_PROTECTION:
                    case SPEC_MONK_BREWMASTER:
                    default:
                        DoCast(me, SPELL_SEEK_AND_DESTROY, true);
                        break;
                }
            }

            void JustDied(Unit* killer)
            {
                if (me->HasAura(SPELL_SEEK_AND_DESTROY))
                    me->CastSpell(killer, SPELL_SEEK_AND_DESTROY_POWER, true);

                if (me->HasAura(SPELL_SEEK_AND_DESTROY_2))
                    me->CastSpell(killer, SPELL_SEEK_AND_DESTROY_WISDOM, true);

                if (me->HasAura(SPELL_SEEK_AND_DESTROY_3))
                    me->CastSpell(killer, SPELL_SEEK_AND_DESTROY_VELOCITY, true);
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_TAIL_STRIKE_2:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_TAIL_STRIKE, false);
                            events.ScheduleEvent(EVENT_TAIL_STRIKE_2, 25000);
                            break;
                        case EVENT_CLAW_2:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_CLAW, false);
                            events.ScheduleEvent(EVENT_CLAW_2, 30000);
                            break;
                        case EVENT_UNSTABLE_SERUM_9:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_UNSTABLE_SERUM, false);
                            events.ScheduleEvent(EVENT_UNSTABLE_SERUM_9, 30000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

enum eKaranoshSpells
{
    SPELL_CORROSIVE_RESIN = 128425,
};

enum eKaranoshEvents
{
    EVENT_CORROSIVE_RESIN   = 1,
    EVENT_UNSTABLE_SERUM_10 = 2,
};

class mob_karanosh : public CreatureScript
{
    public:
        mob_karanosh() : CreatureScript("mob_karanosh")
        {
        }

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_karanoshAI(creature);
        }

        struct mob_karanoshAI : public ScriptedAI
        {
            mob_karanoshAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_CORROSIVE_RESIN, 17000);
                events.ScheduleEvent(EVENT_UNSTABLE_SERUM_10, 12000);
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CORROSIVE_RESIN:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_CORROSIVE_RESIN, false);
                            events.ScheduleEvent(EVENT_CORROSIVE_RESIN, 20000);
                            break;
                        case EVENT_UNSTABLE_SERUM_10:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_UNSTABLE_SERUM, false);
                            events.ScheduleEvent(EVENT_UNSTABLE_SERUM_10, 14000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

enum eKypaRakSpells
{
    SPELL_BURROW         = 128104,
    SPELL_CRACKING_STONE = 128135,
    SPELL_RAISE_EARTH    = 128107,
};

enum eKypaRakEvents
{
    EVENT_BURROW            = 1,
    EVENT_CRACKING_STONE    = 2,
    EVENT_RAISE_EARTH       = 3,
    EVENT_UNSTABLE_SERUM_11 = 4,
    EVENT_UNAURA_BURROW     = 5,
};

class mob_kypa_rak : public CreatureScript
{
    public:
        mob_kypa_rak() : CreatureScript("mob_kypa_rak")
        {
        }

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_kypa_rakAI(creature);
        }

        struct mob_kypa_rakAI : public ScriptedAI
        {
            mob_kypa_rakAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_BURROW, 8000);
                events.ScheduleEvent(EVENT_RAISE_EARTH, 12000);
                events.ScheduleEvent(EVENT_UNAURA_BURROW, 26000);
                events.ScheduleEvent(EVENT_CRACKING_STONE, 27000);
                events.ScheduleEvent(EVENT_UNSTABLE_SERUM_11, 33000);
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BURROW:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_BURROW, false);
                            events.ScheduleEvent(EVENT_RAISE_EARTH, 23000);
                            events.ScheduleEvent(EVENT_UNAURA_BURROW, 15000);
                            events.ScheduleEvent(EVENT_BURROW, 20000);
                            break;
                        case EVENT_UNAURA_BURROW:
                            me->RemoveAura(SPELL_BURROW);
                            break;
                        case EVENT_CRACKING_STONE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_CRACKING_STONE, false);
                            events.ScheduleEvent(EVENT_CRACKING_STONE, 10000);
                            break;
                        case EVENT_RAISE_EARTH:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_RAISE_EARTH, false);
                            break;
                        case EVENT_UNSTABLE_SERUM_11:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_UNSTABLE_SERUM, false);
                            events.ScheduleEvent(EVENT_UNSTABLE_SERUM_11, 14000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

enum eManifestationOfTerrorSpells
{
    SPELL_DREAD_CLAW       = 128026,
    SPELL_LASH_OUT_IN_FEAR = 131375,
    SPELL_SHA_BOLT         = 131376,
};

enum eManifestationOfTerrorEvents
{
    EVENT_DREAD_CLAW        = 1,
    EVENT_LASH_OUT_IN_FEAR  = 2,
    EVENT_SHA_BOLT          = 3,
    EVENT_UNSTABLE_SERUM_12 = 4,
};

class mob_manifestation_of_terror : public CreatureScript
{
    public:
        mob_manifestation_of_terror() : CreatureScript("mob_manifestation_of_terror")
        {
        }

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_manifestation_of_terrorAI(creature);
        }

        struct mob_manifestation_of_terrorAI : public ScriptedAI
        {
            mob_manifestation_of_terrorAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_DREAD_CLAW, 8000);
                events.ScheduleEvent(EVENT_LASH_OUT_IN_FEAR, 12000);
                events.ScheduleEvent(EVENT_SHA_BOLT, 17000);
                events.ScheduleEvent(EVENT_UNSTABLE_SERUM_12, 25000);
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_DREAD_CLAW:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_DREAD_CLAW, false); // Nonfunctional
                            events.ScheduleEvent(EVENT_DREAD_CLAW, 25000);
                            break;
                        case EVENT_LASH_OUT_IN_FEAR:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_LASH_OUT_IN_FEAR, false);
                            events.ScheduleEvent(EVENT_LASH_OUT_IN_FEAR, 10000);
                            break;
                        case EVENT_SHA_BOLT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_SHA_BOLT, false);
                            events.ScheduleEvent(EVENT_SHA_BOLT, 20000);
                            break;
                        case EVENT_UNSTABLE_SERUM_12:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_UNSTABLE_SERUM, false);
                            events.ScheduleEvent(EVENT_UNSTABLE_SERUM_12, 14000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

enum eShoxTikSpells
{
    SPELL_RAPID_SHOT = 96259,
    SPELL_SHOOT      = 130414,
    SPELL_TOXIC_SHOT = 82844,
};

enum eShoxTikEvents
{
    EVENT_RAPID_SHOT        = 1,
    EVENT_SHOOT             = 2,
    EVENT_TOXIC_SHOT        = 3,
    EVENT_UNSTABLE_SERUM_13 = 4,
};

class mob_shox_tik : public CreatureScript
{
    public:
        mob_shox_tik() : CreatureScript("mob_shox_tik")
        {
        }

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_shox_tikAI(creature);
        }

        struct mob_shox_tikAI : public ScriptedAI
        {
            mob_shox_tikAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_RAPID_SHOT, 8000);
                events.ScheduleEvent(EVENT_SHOOT, 12000);
                events.ScheduleEvent(EVENT_TOXIC_SHOT, 17000);
                events.ScheduleEvent(EVENT_UNSTABLE_SERUM_13, 25000);
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_RAPID_SHOT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_RAPID_SHOT, false); // Nonfunctional
                            events.ScheduleEvent(EVENT_RAPID_SHOT, 25000);
                            break;
                        case EVENT_SHOOT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_SHOOT, false);
                            events.ScheduleEvent(EVENT_SHOOT, 10000);
                            break;
                        case EVENT_TOXIC_SHOT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_TOXIC_SHOT, false);
                            events.ScheduleEvent(EVENT_TOXIC_SHOT, 20000);
                            break;
                        case EVENT_UNSTABLE_SERUM_13:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_UNSTABLE_SERUM, false);
                            events.ScheduleEvent(EVENT_UNSTABLE_SERUM_13, 14000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

enum eWakeOfHorrorSpells
{
    SPELL_SHA_CORRUPTION = 128099,
};

enum eWakeOfHorrorEvents
{
    EVENT_SHA_CORRUPTION    = 1,
    EVENT_UNSTABLE_SERUM_14 = 2,
};

class mob_wake_of_horror : public CreatureScript
{
    public:
        mob_wake_of_horror() : CreatureScript("mob_wake_of_horror")
        {
        }

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_wake_of_horrorAI(creature);
        }

        struct mob_wake_of_horrorAI : public ScriptedAI
        {
            mob_wake_of_horrorAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_SHA_CORRUPTION, 10000);
                events.ScheduleEvent(EVENT_UNSTABLE_SERUM_14, 20000);
            }

            void EnterCombat(Unit* who) override
            {
                Player* player = who->ToPlayer();

                if (!player)
                    return;

                switch (player->GetSpecializationId(player->GetActiveSpec()))
                {
                    case SPEC_MAGE_ARCANE:
                    case SPEC_MAGE_FIRE:
                    case SPEC_MAGE_FROST:
                    case SPEC_PALADIN_HOLY:
                    case SPEC_DRUID_BALANCE:
                    case SPEC_PRIEST_DISCIPLINE:
                    case SPEC_PRIEST_HOLY:
                    case SPEC_PRIEST_SHADOW:
                    case SPEC_DRUID_RESTORATION:
                    case SPEC_SHAMAN_ELEMENTAL:
                    case SPEC_SHAMAN_RESTORATION:
                    case SPEC_WARLOCK_AFFLICTION:
                    case SPEC_WARLOCK_DEMONOLOGY:
                    case SPEC_WARLOCK_DESTRUCTION:
                    case SPEC_MONK_MISTWEAVER:
                        DoCast(me, SPELL_SEEK_AND_DESTROY_2, true);
                        break;
                    case SPEC_DRUID_CAT:
                    case SPEC_DRUID_BEAR:
                    case SPEC_HUNTER_BEASTMASTER:
                    case SPEC_HUNTER_MARKSMAN:
                    case SPEC_HUNTER_SURVIVAL:
                    case SPEC_ROGUE_ASSASSINATION:
                    case SPEC_ROGUE_COMBAT:
                    case SPEC_ROGUE_SUBTLETY:
                    case SPEC_SHAMAN_ENHANCEMENT:
                    case SPEC_MONK_WINDWALKER:
                        DoCast(me, SPELL_SEEK_AND_DESTROY_3, true);
                        break;
                    case SPEC_DK_BLOOD:
                    case SPEC_DK_FROST:
                    case SPEC_DK_UNHOLY:
                    case SPEC_PALADIN_PROTECTION:
                    case SPEC_PALADIN_RETRIBUTION:
                    case SPEC_WARRIOR_ARMS:
                    case SPEC_WARRIOR_FURY:
                    case SPEC_WARRIOR_PROTECTION:
                    case SPEC_MONK_BREWMASTER:
                    default:
                        DoCast(me, SPELL_SEEK_AND_DESTROY, true);
                        break;
                }
            }

            void JustDied(Unit* killer)
            {
                if (me->HasAura(SPELL_SEEK_AND_DESTROY))
                    me->CastSpell(killer, SPELL_SEEK_AND_DESTROY_POWER, true);

                if (me->HasAura(SPELL_SEEK_AND_DESTROY_2))
                    me->CastSpell(killer, SPELL_SEEK_AND_DESTROY_WISDOM, true);

                if (me->HasAura(SPELL_SEEK_AND_DESTROY_3))
                    me->CastSpell(killer, SPELL_SEEK_AND_DESTROY_VELOCITY, true);
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SHA_CORRUPTION:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_SHA_CORRUPTION, false);
                            events.ScheduleEvent(EVENT_SHA_CORRUPTION, 15000);
                            break;
                        case EVENT_UNSTABLE_SERUM_14:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_UNSTABLE_SERUM, false);
                            events.ScheduleEvent(EVENT_UNSTABLE_SERUM_14, 15000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

enum eWarlordGurthanSpells
{
    SPELL_CRUSHING_SHADOWS = 131704,
    SPELL_RUNE_OF_SHADOWS  = 131696,
    SPELL_SHADOW_POWER     = 131698,
};

enum eWarlordGurthanEvents
{
    EVENT_CRUSHING_SHADOWS  = 1,
    EVENT_RUNE_OF_SHADOWS   = 2,
    EVENT_SHADOW_POWER      = 3,
    EVENT_UNSTABLE_SERUM_15 = 4,
};

class mob_warlord_gurthan : public CreatureScript
{
    public:
        mob_warlord_gurthan() : CreatureScript("mob_warlord_gurthan")
        {
        }

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_warlord_gurthanAI(creature);
        }

        struct mob_warlord_gurthanAI : public ScriptedAI
        {
            mob_warlord_gurthanAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_CRUSHING_SHADOWS, 8000);
                events.ScheduleEvent(EVENT_RUNE_OF_SHADOWS, 12000);
                events.ScheduleEvent(EVENT_SHADOW_POWER, 17000);
                events.ScheduleEvent(EVENT_UNSTABLE_SERUM_15, 25000);
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CRUSHING_SHADOWS:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_CRUSHING_SHADOWS, false); // Nonfunctional
                            events.ScheduleEvent(EVENT_CRUSHING_SHADOWS, 25000);
                            break;
                        case EVENT_RUNE_OF_SHADOWS:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_RUNE_OF_SHADOWS, false);
                            events.ScheduleEvent(EVENT_RUNE_OF_SHADOWS, 10000);
                            break;
                        case EVENT_SHADOW_POWER:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_SHADOW_POWER, false);
                            events.ScheduleEvent(EVENT_SHADOW_POWER, 20000);
                            break;
                        case EVENT_UNSTABLE_SERUM_15:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_UNSTABLE_SERUM, false);
                            events.ScheduleEvent(EVENT_UNSTABLE_SERUM_15, 14000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

enum eAiLiSkymirrorSpells
{
    SPELL_CHI_BURST           = 125817,
    SPELL_HEALING_MISTS       = 125802,
    SPELL_SPINNING_CRANE_KICK = 125799,
};

enum eAiLiSkymirrorEvents
{
    EVENT_CHI_BURST           = 1,
    EVENT_HEALING_MISTS       = 2,
    EVENT_SPINNING_CRANE_KICK = 3,
    EVENT_UNSTABLE_SERUM_16   = 4,
};

class mob_ai_li_skymirror : public CreatureScript
{
    public:
        mob_ai_li_skymirror() : CreatureScript("mob_ai_li_skymirror")
        {
        }

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_ai_li_skymirrorAI(creature);
        }

        struct mob_ai_li_skymirrorAI : public ScriptedAI
        {
            mob_ai_li_skymirrorAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_CHI_BURST, 8000);
                events.ScheduleEvent(EVENT_HEALING_MISTS, 12000);
                events.ScheduleEvent(EVENT_SPINNING_CRANE_KICK, 17000);
                events.ScheduleEvent(EVENT_UNSTABLE_SERUM_16, 25000);
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CHI_BURST:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_CHI_BURST, false);
                            events.ScheduleEvent(EVENT_CHI_BURST, 10000);
                            break;
                        case EVENT_HEALING_MISTS:
                            if (SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(me, SPELL_HEALING_MISTS, false);
                            events.ScheduleEvent(EVENT_HEALING_MISTS, 17000);
                            break;
                        case EVENT_SPINNING_CRANE_KICK:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_SPINNING_CRANE_KICK, false);
                            events.ScheduleEvent(EVENT_SPINNING_CRANE_KICK, 21000);
                            break;
                        case EVENT_UNSTABLE_SERUM_16:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_UNSTABLE_SERUM, false);
                            events.ScheduleEvent(EVENT_UNSTABLE_SERUM_16, 25000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

enum eOvergrownSeacarpSpells
{
    SPELL_SNAPJAW = 79442,
};

enum eOvergrownSeacarpEvents
{
    EVENT_SNAPJAW           = 1,
    EVENT_UNSTABLE_SERUM_17 = 2,
};

class mob_overgrown_seacarp : public CreatureScript
{
    public:
        mob_overgrown_seacarp() : CreatureScript("mob_overgrown_seacarp")
        {
        }

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_overgrown_seacarpAI(creature);
        }

        struct mob_overgrown_seacarpAI : public ScriptedAI
        {
            mob_overgrown_seacarpAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_SNAPJAW, 8000);
                events.ScheduleEvent(EVENT_UNSTABLE_SERUM_17, 12000);
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SNAPJAW:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_SNAPJAW, false);
                            events.ScheduleEvent(EVENT_SNAPJAW, 10000);
                            break;
                        case EVENT_UNSTABLE_SERUM_17:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_UNSTABLE_SERUM, false);
                            events.ScheduleEvent(EVENT_UNSTABLE_SERUM_17, 14000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

enum eGarLokSpells
{
    SPELL_WINDSONG    = 125373,
    SPELL_BLADE_FURRY = 125370,
    SPELL_TORNADO     = 125398,
    SPELL_TORNADO_DMG = 131693
};

enum eGarLokEvents
{
    EVENT_SNAPJAW_2         = 1,
    EVENT_UNSTABLE_SERUM_18 = 2,
    EVENT_BLADE_FURRY       = 3,
    EVENT_TORNADO           = 4
};

class mob_gar_lok : public CreatureScript
{
    public:
        mob_gar_lok() : CreatureScript("mob_gar_lok")
        {
        }

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_gar_lokAI(creature);
        }

        struct mob_gar_lokAI : public ScriptedAI
        {
            mob_gar_lokAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_SNAPJAW, 8000);
                events.ScheduleEvent(EVENT_UNSTABLE_SERUM_18, 12000);
                events.ScheduleEvent(EVENT_BLADE_FURRY, 20000);
                events.ScheduleEvent(EVENT_TORNADO, 27000);
            }

            void JustSummoned(Creature* summon) override
            {
                if (summon->GetEntry() == 64267)
                {
                    summon->DespawnOrUnsummon(15000);
                    summon->AddAura(SPELL_TORNADO_DMG, summon);
                    summon->SetReactState(REACT_PASSIVE);
                    summon->GetMotionMaster()->MoveRandom(20.0f);
                }

            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SNAPJAW:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_SNAPJAW, false);
                            events.ScheduleEvent(EVENT_SNAPJAW, 8000);
                            break;
                        case EVENT_UNSTABLE_SERUM_18:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_UNSTABLE_SERUM, false);
                            events.ScheduleEvent(EVENT_UNSTABLE_SERUM_18, 12000);
                            break;
                        case EVENT_BLADE_FURRY:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_BLADE_FURRY, false);
                            events.ScheduleEvent(EVENT_BLADE_FURRY, 20000);
                            break;
                        case EVENT_TORNADO:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_TORNADO, false);
                            events.ScheduleEvent(EVENT_TORNADO, 27000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

enum eDakTheBreakerSpells
{
    SPELL_BELLOWING_RAGE = 124297,
    SPELL_RUSHING_RAGE   = 124302,
    SPELL_YAUNGOL_STOMP  = 124289
};

enum eDakTheBreakerEvents
{
    EVENT_BELLOWING_RAGE    = 1,
    EVENT_UNSTABLE_SERUM_19 = 2,
    EVENT_RUSHING_RAGE      = 3,
    EVENT_YAUNGOL_STOMP     = 4
};

class mob_dak_the_breaker : public CreatureScript
{
    public:
        mob_dak_the_breaker() : CreatureScript("mob_dak_the_breaker")
        { }

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_dak_the_breakerAI(creature);
        }

        struct mob_dak_the_breakerAI : public ScriptedAI
        {
            mob_dak_the_breakerAI(Creature* creature) : ScriptedAI(creature)
            { }

            EventMap events;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_RUSHING_RAGE, 5000);
                events.ScheduleEvent(EVENT_UNSTABLE_SERUM_19, 12000);
                events.ScheduleEvent(EVENT_YAUNGOL_STOMP, 20000);
                events.ScheduleEvent(EVENT_BELLOWING_RAGE, 28000);
            }

            void JustDied(Unit* /*killer*/) override
            { }

            void JustSummoned(Creature* summon) override
            {
                summon->DespawnOrUnsummon(12000);
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);


                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BELLOWING_RAGE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_BELLOWING_RAGE, false);
                            events.ScheduleEvent(EVENT_BELLOWING_RAGE, 25000);
                            break;
                        case EVENT_UNSTABLE_SERUM_19:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_UNSTABLE_SERUM, false);
                            events.ScheduleEvent(EVENT_UNSTABLE_SERUM_19, 12000);
                            break;
                        case EVENT_RUSHING_RAGE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_RUSHING_RAGE, false);
                            events.ScheduleEvent(EVENT_RUSHING_RAGE, 5000);
                            break;
                        case EVENT_YAUNGOL_STOMP:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_YAUNGOL_STOMP, false);
                            events.ScheduleEvent(EVENT_YAUNGOL_STOMP, 15000);
                            break;
                        default:
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        };
};

enum eNalashVerdantisSpells
{
    SPELL_RAIN_DANCE = 124860,
    SPELL_TORRENT    = 124935,
    SPELL_WATER_BOLT = 124854
};

enum eNalashVerdantisEvents
{
    EVENT_UNSTABLE_SERUM_20 = 1,
    EVENT_RAIN_DANCE        = 2,
    EVENT_TORRENT           = 3,
    EVENT_WATER_BOLT        = 4
};

class mob_nalash_verdantis : public CreatureScript
{
    public:
        mob_nalash_verdantis() : CreatureScript("mob_nalash_verdantis")
        {
        }

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_nalash_verdantisAI(creature);
        }

        struct mob_nalash_verdantisAI : public ScriptedAI
        {
            mob_nalash_verdantisAI(Creature* creature) : ScriptedAI(creature)
            { }

            EventMap events;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_RUSHING_RAGE, 5000);
                events.ScheduleEvent(EVENT_UNSTABLE_SERUM_20, 12000);
                events.ScheduleEvent(EVENT_YAUNGOL_STOMP, 20000);
                events.ScheduleEvent(EVENT_BELLOWING_RAGE, 28000);
            }

            void JustDied(Unit* /*killer*/) override
            {
            }

            void JustSummoned(Creature* summon) override
            {
                summon->DespawnOrUnsummon(12000);
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_UNSTABLE_SERUM_20:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_UNSTABLE_SERUM, false);
                            events.ScheduleEvent(EVENT_UNSTABLE_SERUM_20, 12000);
                            break;
                        case EVENT_RAIN_DANCE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_RAIN_DANCE, false);
                            events.ScheduleEvent(EVENT_RAIN_DANCE, 5000);
                            break;
                        case EVENT_TORRENT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_TORRENT, false);
                            events.ScheduleEvent(EVENT_TORRENT, 15000);
                            break;
                        case EVENT_WATER_BOLT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_WATER_BOLT, false);
                            events.ScheduleEvent(EVENT_WATER_BOLT, 25000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

class mob_hisek_the_swarmkeeper : public CreatureScript
{
    public:
        mob_hisek_the_swarmkeeper() : CreatureScript("mob_hisek_the_swarmkeeper") { }

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_hisek_the_swarmkeeperAI(creature);
        }

        struct mob_hisek_the_swarmkeeperAI : public ScriptedAI
        {
            mob_hisek_the_swarmkeeperAI(Creature* creature) : ScriptedAI(creature) { }

            void UpdateAI(const uint32 /*diff*/)
            {
                std::list<Player*> playerList;
                playerList.clear();
                GetPlayerListInGrid(playerList, me, 5.0f);

                for (auto player : playerList)
                    if (player->GetQuestStatus(31439) == QUEST_STATUS_INCOMPLETE)
                        player->KilledMonsterCredit(64645);
            }
        };
};

enum eVengefulSpiritEvents
{
    EVENT_UNSTABLE_SERUM_21 = 1,
    EVENT_RAIN_DANCE_2      = 2
};

class mob_vengeful_spirit : public CreatureScript
{
    public:
        mob_vengeful_spirit() : CreatureScript("mob_vengeful_spirit")
        {
        }

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_vengeful_spiritAI(creature);
        }

        struct mob_vengeful_spiritAI : public ScriptedAI
        {
            mob_vengeful_spiritAI(Creature* creature) : ScriptedAI(creature)
            { }

            EventMap events;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_RAIN_DANCE_2, 5000);
                events.ScheduleEvent(EVENT_UNSTABLE_SERUM_21, 12000);
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_UNSTABLE_SERUM_21:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_UNSTABLE_SERUM, false);
                            events.ScheduleEvent(EVENT_UNSTABLE_SERUM_21, 15000);
                            break;
                        case EVENT_RAIN_DANCE_2:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_RAIN_DANCE, false);
                            events.ScheduleEvent(EVENT_RAIN_DANCE_2, 15000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

// Adjunct Zet'uk (65478) - Sha Eruption (130061)

enum
{
    SPELL_SHA_ERUPTION_SUMMON      = 130062,
    SPELL_SHA_ERUPTION_SUMMON_FIRE = 130065, // NYI target type 138
    SPELL_SHA_ERUPTION_PERIODIC    = 130063,
    SPELL_SHA_ERUPTION_DAMAGE      = 130066,

    NPC_SHA_ERUPTION_FIRE = 66146
};

// Sha Eruption targeting 130061
class spell_zet_uk_sha_eruption : public SpellScriptLoader
{
    public:
        spell_zet_uk_sha_eruption() : SpellScriptLoader("spell_zet_uk_sha_eruption") {}

        class spell_zet_uk_sha_eruption_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_zet_uk_sha_eruption_SpellScript);

            void ResizeTargets(std::list<WorldObject*>& targets)
            {
                if (targets.size() > 1)
                    MoPCore::Containers::RandomResizeList(targets, 1);
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                if (Unit* target = GetHitUnit())
                {
                    caster->SetFacingToObject(target);
                    caster->SetOrientation(caster->GetAngle(target));
                    caster->CastSpell(caster, SPELL_SHA_ERUPTION_SUMMON, false);
                }
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_zet_uk_sha_eruption_SpellScript::ResizeTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_zet_uk_sha_eruption_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_zet_uk_sha_eruption_SpellScript();
        }
};

// Sha Eruption Periodic trigger - 130063
class spell_zet_uk_sha_eruption_periodic_summon : public SpellScriptLoader
{
    public:
        spell_zet_uk_sha_eruption_periodic_summon() : SpellScriptLoader("spell_zet_uk_sha_eruption_periodic_summon") {}

        class spell_zet_uk_sha_eruption_periodic_summon_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_zet_uk_sha_eruption_periodic_summon_AuraScript);

            void HandleEffectPeriodic(constAuraEffectPtr aurEff)
            {
                Unit * caster = GetCaster();
                if (!caster)
                    return;

                float dist = (float)aurEff->GetTickNumber() * 6.0f; // radius of damage spell * 2
                Position pos;
                caster->GetNearPosition(pos, dist, 0.0f);
                if (Creature * summon = caster->SummonCreature(NPC_SHA_ERUPTION_FIRE, pos, TEMPSUMMON_TIMED_DESPAWN, 20000)) // Summon spell target type NYI (138)
                    summon->CastSpell(summon, SPELL_SHA_ERUPTION_DAMAGE, true);
            }

            void OnRemove(constAuraEffectPtr /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (!GetCaster())
                    return;

                if (TempSummon * casterTrigger = GetCaster()->ToTempSummon())
                    casterTrigger->DespawnOrUnsummon(0);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_zet_uk_sha_eruption_periodic_summon_AuraScript::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
                AfterEffectRemove += AuraEffectRemoveFn(spell_zet_uk_sha_eruption_periodic_summon_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_zet_uk_sha_eruption_periodic_summon_AuraScript();
        }
};

class AreaTrigger_at_q_wood_and_shade : public AreaTriggerScript
{
    public:
        AreaTrigger_at_q_wood_and_shade() : AreaTriggerScript("at_q_wood_and_shade") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* trigger)
        {
            if (trigger->id == 8124)
                player->KilledMonsterCredit(62955);
            else
                player->KilledMonsterCredit(62956);
            return true;
        }
};

// On the Crab quest
class go_full_crab_pot : public GameObjectScript
{
    public:
        go_full_crab_pot() : GameObjectScript("go_full_crab_pot") { }

        bool OnGossipHello(Player* player, GameObject* go)
        {
            if (player->GetQuestStatus(31187) == QUEST_STATUS_INCOMPLETE)
            {
                /*player->CastSpell(player, 89404, true);
                player->TeleportTo(player->GetMapId(), -9207.99f, -1560.32f, 65.46f, 0.82f);*/
                player->KilledMonsterCredit(64006);
                Position pos;
                go->GetPosition(&pos);
                if (auto crabTrap = player->SummonCreature(64009, pos, TEMPSUMMON_TIMED_DESPAWN, 10000))
                {
                    crabTrap->CastSpell(crabTrap, 124959, true);
                    pos.m_positionZ = pos.m_positionZ + 20;
                    crabTrap->GetMotionMaster()->MovePoint(1, pos);
                }
                go->SetRespawnTime(60);
            }
            return false;
        }
};

// Living Amber quest
class spell_item_living_amber : public SpellScriptLoader
{
    public:
        spell_item_living_amber() : SpellScriptLoader("spell_item_living_amber") {}

        class spell_item_living_amber_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_item_living_amber_SpellScript);

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                auto target = GetHitUnit();
                if (!target || target->GetTypeId() != TYPEID_UNIT || GetCaster()->GetTypeId() != TYPEID_PLAYER)
                    return;

                auto player = GetCaster()->ToPlayer();
                if (player->GetQuestStatus(31021) == QUEST_STATUS_INCOMPLETE)
                {
                    uint16 questProgress = player->GetQuestSlotCounter(player->FindQuestSlot(31021), 0);
                    target->ToCreature()->AI()->Talk(questProgress);
                    player->KilledMonsterCredit(63204);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_item_living_amber_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_item_living_amber_SpellScript();
        }
};

class npc_hisek_the_swarmkeeper : public CreatureScript
{
    public:
        npc_hisek_the_swarmkeeper() : CreatureScript("npc_hisek_the_swarmkeeper") { }

        bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest)
        {
            if (quest->GetQuestId() == 31441)
            {
                Position pos;
                creature->GetPosition(&pos);
                uint64 playerGUID = player->GetGUID();
                if (auto qgiver = creature->SummonCreature(64705, pos))
                {
                    qgiver->setExplicitSeerGuid(playerGUID);
                    qgiver->AI()->SetGUID(playerGUID);
                }
            }

            return true;
        }
};

class npc_hisek_the_swarmkeeper_summon : public CreatureScript
{
    public:
        npc_hisek_the_swarmkeeper_summon() : CreatureScript("npc_hisek_the_swarmkeeper_summon") { }

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_hisek_the_swarmkeeper_summonAI(creature);
        }

        struct npc_hisek_the_swarmkeeper_summonAI : public ScriptedAI
        {
            npc_hisek_the_swarmkeeper_summonAI(Creature* creature) : ScriptedAI(creature) {}

            uint8 phase;
            uint32 phaseTimer;
            uint64 playerGUID;
            uint64 traitorGUID;

            void Reset() override
            {
                phase = 0;
                phaseTimer = 500;
                traitorGUID = 0;
                playerGUID = 0;
            }

            void SetGUID(uint64 guid, int32 /*type*/)
            {
                playerGUID = guid;
            }

            void UpdateAI(uint32 const diff)
            {
                if (playerGUID && phaseTimer <= diff)
                {
                    if (phase == 0)
                    {
                        Talk(0);
                        phaseTimer = 2000;
                    }
                    else if (phase == 1)
                    {
                        if (auto traitor = me->SummonCreature(64813, -572.95f, 3015.31f, 181.15f, 2.17f))
                        {
                            traitorGUID = traitor->GetGUID();
                            me->GetMotionMaster()->MovePoint(1, -577.2f, 3021.62f, 183.7f);
                            traitor->setExplicitSeerGuid(playerGUID);
                            traitor->AI()->Talk(0);
                        }
                        phaseTimer = 4000;
                    }
                    else if (phase == 2)
                    {
                        Talk(1);
                        phaseTimer = 5000;
                    }
                    else if (phase == 3 || phase == 4)
                    {
                        if (auto traitor = me->GetCreature(*me, traitorGUID))
                            traitor->AI()->Talk(phase == 3 ? 1 : 2);
                        phaseTimer = 6000;
                    }
                    else if (phase == 5 || phase == 6)
                    {
                        Talk(phase == 5 ? 2 : 3);
                        phaseTimer = 6000;
                    }
                    else if (phase == 7)
                    {
                        if (auto traitor = me->GetCreature(*me, traitorGUID))
                            traitor->AI()->Talk(3);
                        phaseTimer = 4000;
                    }
                    else if (phase == 8)
                    {
                        if (auto traitor = me->GetCreature(*me, traitorGUID))
                        {
                            traitor->AI()->Talk(4);
                            traitor->UpdateEntry(64583);
                            AttackStart(traitor);
                            playerGUID = 0;
                        }
                    }

                    phase++;
                }
                else
                    phaseTimer -= diff;

                if (me->getVictim())
                    DoMeleeAttackIfReady();
            }
        };
};

void AddSC_dread_wastes()
{
    //Rare Mobs
    new mob_ik_ik_the_nimble();
    new mob_ai_li_skymirror();
    new mob_gar_lok();
    new mob_dak_the_breaker();
    new mob_nalash_verdantis();
    //Elite Mobs
    new mob_adjunct_kree_zot();
    new mob_dread_fearbringer();
    new mob_dread_kunchong();
    new mob_dread_matriarch();
    new mob_elder_spindlegrin();
    new mob_hulking_kor_thik_fleshrender();
    new mob_ik_thik_amberstinger();
    new mob_ik_thik_kunchong();
    new mob_ik_thik_terrorclaw();
    new mob_karanosh();
    new mob_kypa_rak();
    new mob_manifestation_of_terror();
    new mob_shox_tik();
    new mob_wake_of_horror();
    new mob_warlord_gurthan();
    new mob_vengeful_spirit();
    //Standard Mobs
    new mob_overgrown_seacarp();
    new mob_hisek_the_swarmkeeper();
    //Extending the Vocerage
    new spell_zet_uk_sha_eruption();
    new spell_zet_uk_sha_eruption_periodic_summon();
    //Quest scripts
    new AreaTrigger_at_q_wood_and_shade();
    new go_full_crab_pot();
    new spell_item_living_amber();
    new npc_hisek_the_swarmkeeper();
    new npc_hisek_the_swarmkeeper_summon();
}
