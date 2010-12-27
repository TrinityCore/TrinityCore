/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "icecrown_citadel.h"

enum eTexts
{
    // Blood Queen Lana'Thel
    SAY_INTRO_1                 = 0,
    SAY_INTRO_2                 = 1,

    // Prince Keleseth
    SAY_KELESETH_INVOCATION     = 0,
    EMOTE_KELESETH_INVOCATION   = 1,
    SAY_KELESETH_SPECIAL        = 2,
    SAY_KELESETH_KILL           = 3,
    EMOTE_KELESETH_BERSERK      = 4,
    SAY_KELESETH_DEATH          = 5,

    // Prince Taldaram
    SAY_TALDARAM_INVOCATION     = 0,
    EMOTE_TALDARAM_INVOCATION   = 1,
    SAY_TALDARAM_SPECIAL        = 2,
    EMOTE_TALDARAM_FLAME        = 3,
    SAY_TALDARAM_KILL           = 4,
    EMOTE_TALDARAM_BERSERK      = 5,
    EMOTE_TALDARAM_DEATH        = 6,

    // Prince Valanar
    SAY_VALANAR_INVOCATION      = 0,
    EMOTE_VALANAR_INVOCATION    = 1,
    SAY_VALANAR_SPECIAL         = 2,
    EMOTE_VALANAR_SHOCK_VORTEX  = 3,
    SAY_VALANAR_KILL            = 4,
    SAY_VALANAR_BERSERK         = 5,
    SAY_VALANAR_DEATH           = 6,
};

enum eSpells
{
    SPELL_FEIGN_DEATH                   = 71598,
    SPELL_OOC_INVOCATION_VISUAL         = 70934,
    SPELL_INVOCATION_VISUAL_ACTIVE      = 71596,

    // Heroic mode
    SPELL_SHADOW_PRISON                 = 72998,
    SPELL_SHADOW_PRISON_DAMAGE          = 72999,
    SPELL_SHADOW_PRISON_DUMMY           = 73001,

    // Prince Keleseth
    SPELL_INVOCATION_OF_BLOOD_KELESETH  = 70981,
    SPELL_SHADOW_RESONANCE              = 71943,
    SPELL_SHADOW_LANCE                  = 71405,
    SPELL_EMPOWERED_SHADOW_LANCE        = 71815,

    // Dark Nucleus
    SPELL_SHADOW_RESONANCE_AURA         = 72980,
    SPELL_SHADOW_RESONANCE_RESIST       = 71822,

    // Prince Taldaram
    SPELL_INVOCATION_OF_BLOOD_TALDARAM  = 70982,
    SPELL_GLITTERING_SPARKS             = 71806,
    SPELL_CONJURE_FLAME                 = 71718,
    SPELL_CONJURE_EMPOWERED_FLAME       = 72040,

    // Ball of Flame
    SPELL_FLAME_SPHERE_SPAWN_EFFECT     = 55891, // cast from creature_template_addon (needed cast before entering world)
    SPELL_BALL_OF_FLAMES_VISUAL         = 71706,
    SPELL_BALL_OF_FLAMES                = 71714,
    SPELL_FLAMES                        = 71393,
    SPELL_FLAME_SPHERE_DEATH_EFFECT     = 55947,

    // Ball of Inferno Flame
    SPELL_BALL_OF_FLAMES_PROC           = 71756,
    SPELL_BALL_OF_FLAMES_PERIODIC       = 71709,

    // Prince Valanar
    SPELL_INVOCATION_OF_BLOOD_VALANAR   = 70952,
    SPELL_KINETIC_BOMB_TARGET           = 72053,
    SPELL_KINETIC_BOMB                  = 72080,
    SPELL_SHOCK_VORTEX                  = 72037,
    SPELL_EMPOWERED_SHOCK_VORTEX        = 72039,

    // Kinetic Bomb
    SPELL_UNSTABLE                      = 72059,
    SPELL_KINETIC_BOMB_VISUAL           = 72054,
    SPELL_KINETIC_BOMB_EXPLOSION        = 72052,

    // Shock Vortex
    SPELL_SHOCK_VORTEX_PERIODIC         = 71945,
    SPELL_SHOCK_VORTEX_DUMMY            = 72633,
};

enum eEvents
{
    EVENT_INTRO_1               = 1,
    EVENT_INTRO_2               = 2,

    EVENT_INVOCATION_OF_BLOOD   = 3,
    EVENT_BERSERK               = 4,

    // Keleseth
    EVENT_SHADOW_RESONANCE      = 5,
    EVENT_SHADOW_LANCE          = 6,

    // Taldaram
    EVENT_GLITTERING_SPARKS     = 7,
    EVENT_CONJURE_FLAME         = 8,

    // Valanar
    EVENT_KINETIC_BOMB          = 9,
    EVENT_SHOCK_VORTEX          = 10,
    EVENT_BOMB_DESPAWN          = 11,
    EVENT_CONTINUE_FALLING      = 12,
};

enum eActions
{
    ACTION_STAND_UP             = 1,
    ACTION_CAST_INVOCATION      = 2,
    ACTION_REMOVE_INVOCATION    = 3,
    ACTION_KINETIC_BOMB_JUMP    = 4,
    ACTION_FLAME_BALL_CHASE     = 5,
};

enum ePoints
{
    POINT_INTRO_DESPAWN         = 380040,
    POINT_KINETIC_BOMB_IMPACT   = 384540,
};

enum eDisplays
{
    DISPLAY_KINETIC_BOMB        = 31095,
};

class StandUpEvent : public BasicEvent
{
    public:
        StandUpEvent(Creature& owner) : BasicEvent(), m_owner(owner) { }
        bool Execute(uint64 /*eventTime*/, uint32 /*diff*/)
        {
            m_owner.HandleEmoteCommand(EMOTE_ONESHOT_ROAR);
            return true;
        }

    private:
        Creature& m_owner;
};

static const Position introFinalPos = {4660.490f, 2769.200f, 430.0000f, 0.000000f};
static const Position triggerPos    = {4680.231f, 2769.134f, 379.9256f, 3.121708f};
static const Position triggerEndPos = {4680.180f, 2769.150f, 365.5000f, 3.121708f};

class boss_blood_council_controller : public CreatureScript
{
    public:
        boss_blood_council_controller() : CreatureScript("boss_blood_council_controller") { }

        struct boss_blood_council_controllerAI : public BossAI
        {
            boss_blood_council_controllerAI(Creature* creature) : BossAI(creature, DATA_BLOOD_PRINCE_COUNCIL)
            {
            }

            void InitializeAI()
            {
                if (!instance || static_cast<InstanceMap*>(me->GetMap())->GetScriptId() != GetScriptId(ICCScriptName))
                    me->IsAIEnabled = false;
                else if (!me->isDead())
                    Reset();
            }

            void Reset()
            {
                events.Reset();
                me->SetReactState(REACT_PASSIVE);
                invocationStage = 0;

                instance->SetBossState(DATA_BLOOD_PRINCE_COUNCIL, NOT_STARTED);
            }

            void EnterCombat(Unit* /*who*/)
            {
                instance->SetBossState(DATA_BLOOD_PRINCE_COUNCIL, IN_PROGRESS);

                DoCast(me, SPELL_INVOCATION_OF_BLOOD_VALANAR);

                if (Creature* keleseth = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_PRINCE_KELESETH_GUID)))
                    if (!keleseth->isInCombat())
                        DoZoneInCombat(keleseth);

                if (Creature* taldaram = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_PRINCE_TALDARAM_GUID)))
                    if (!taldaram->isInCombat())
                        DoZoneInCombat(taldaram);

                if (Creature* valanar = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_PRINCE_VALANAR_GUID)))
                    if (!valanar->isInCombat())
                        DoZoneInCombat(valanar);

                events.ScheduleEvent(EVENT_INVOCATION_OF_BLOOD, 30000);

                invocationOrder[0] = InvocationData(instance->GetData64(DATA_PRINCE_VALANAR_GUID), SPELL_INVOCATION_OF_BLOOD_VALANAR, EMOTE_VALANAR_INVOCATION, 71070);
                if (urand(0, 1))
                {
                    invocationOrder[1] = InvocationData(instance->GetData64(DATA_PRINCE_TALDARAM_GUID), SPELL_INVOCATION_OF_BLOOD_TALDARAM, EMOTE_TALDARAM_INVOCATION, 71081);
                    invocationOrder[2] = InvocationData(instance->GetData64(DATA_PRINCE_KELESETH_GUID), SPELL_INVOCATION_OF_BLOOD_KELESETH, EMOTE_KELESETH_INVOCATION, 71080);
                }
                else
                {
                    invocationOrder[1] = InvocationData(instance->GetData64(DATA_PRINCE_KELESETH_GUID), SPELL_INVOCATION_OF_BLOOD_KELESETH, EMOTE_KELESETH_INVOCATION, 71080);
                    invocationOrder[2] = InvocationData(instance->GetData64(DATA_PRINCE_TALDARAM_GUID), SPELL_INVOCATION_OF_BLOOD_TALDARAM, EMOTE_TALDARAM_INVOCATION, 71081);
                }

                if (IsHeroic())
                {
                    Map::PlayerList const &PlList = me->GetMap()->GetPlayers();
                    if (PlList.isEmpty())
                        return;

                    for (Map::PlayerList::const_iterator i = PlList.begin(); i != PlList.end(); ++i)
                    {
                        if (Player* player = i->getSource())
                        {
                            if (player->isGameMaster())
                                continue;

                            if (player->isAlive())
                                player->AddAura(SPELL_SHADOW_PRISON_DUMMY, player);
                        }
                    }
                }
            }

            void JustReachedHome()
            {
                instance->SetBossState(DATA_BLOOD_PRINCE_COUNCIL, FAIL);
            }

            void JustDied(Unit* /*killer*/)
            {
                _JustDied();
                // kill the other 2 princes too
                for (uint8 i = 0; i < 2; ++i)
                {
                    if (++invocationStage == 3)
                        invocationStage = 0;

                    if (Creature* prince = ObjectAccessor::GetCreature(*me, invocationOrder[invocationStage].guid))
                        prince->Kill(prince);
                }
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SHADOW_PRISON_DUMMY);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_INVOCATION_OF_BLOOD:
                        {
                            Creature* oldPrince = ObjectAccessor::GetCreature(*me, invocationOrder[invocationStage].guid);
                            if (++invocationStage == 3)
                                invocationStage = 0;

                            Creature* newPrince = ObjectAccessor::GetCreature(*me, invocationOrder[invocationStage].guid);
                            if (oldPrince)
                            {
                                oldPrince->AI()->DoAction(ACTION_REMOVE_INVOCATION);
                                if (newPrince)
                                    oldPrince->CastSpell(newPrince, invocationOrder[invocationStage].visualSpell, true);
                            }

                            if (newPrince)
                            {
                                newPrince->SetHealth(me->GetHealth());
                                newPrince->AI()->Talk(invocationOrder[invocationStage].textId);
                            }

                            DoCast(me, invocationOrder[invocationStage].spellId);
                            events.ScheduleEvent(EVENT_INVOCATION_OF_BLOOD, 30000);
                            break;
                        }
                        default:
                            break;
                    }
                }
            }

        private:
            struct InvocationData
            {
                uint64 guid;
                uint32 spellId;
                uint8  textId;
                uint32 visualSpell;

                InvocationData(uint64 _guid, uint32 _spellId, int32 _textId, uint32 _visualSpell)
                {
                    guid = _guid;
                    spellId = _spellId;
                    textId = _textId;
                    visualSpell = _visualSpell;
                }

                InvocationData() : guid(0), spellId(0), textId(0), visualSpell(0) { }
            } invocationOrder[3];
            uint8 invocationStage;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_blood_council_controllerAI(creature);
        }
};

class boss_prince_keleseth_icc : public CreatureScript
{
    public:
        boss_prince_keleseth_icc() : CreatureScript("boss_prince_keleseth_icc") { }

        struct boss_prince_kelesethAI : public BossAI
        {
            boss_prince_kelesethAI(Creature* creature) : BossAI(creature, DATA_BLOOD_PRINCE_COUNCIL)
            {
                isEmpowered = false;
                spawnHealth = creature->GetMaxHealth();
            }

            void InitializeAI()
            {
                if (CreatureData const* data = sObjectMgr->GetCreatureData(me->GetDBTableGUIDLow()))
                    if (data->curhealth)
                        spawnHealth = data->curhealth;

                if (!instance || static_cast<InstanceMap*>(me->GetMap())->GetScriptId() != GetScriptId(ICCScriptName))
                    me->IsAIEnabled = false;
                else if (!me->isDead())
                    JustRespawned();

                me->SetReactState(REACT_DEFENSIVE);
            }

            void Reset()
            {
                events.Reset();
                summons.DespawnAll();

                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
                isEmpowered = false;
                me->SetHealth(spawnHealth);
                instance->SetData(DATA_ORB_WHISPERER_ACHIEVEMENT, uint32(true));
                me->SetReactState(REACT_DEFENSIVE);
                if (IsHeroic())
                    DoCast(me, SPELL_SHADOW_PRISON);
            }

            void MoveInLineOfSight(Unit* /*who*/)
            {
            }

            void EnterCombat(Unit* /*who*/)
            {
                if (Creature* controller = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_BLOOD_PRINCES_CONTROL)))
                    if (!controller->isInCombat())
                        DoZoneInCombat(controller);

                events.ScheduleEvent(EVENT_BERSERK, 600000);
                events.ScheduleEvent(EVENT_SHADOW_RESONANCE, urand(10000, 15000));
                events.ScheduleEvent(EVENT_SHADOW_LANCE, 2000);
            }

            void JustDied(Unit* /*killer*/)
            {
                Talk(SAY_KELESETH_DEATH);
            }

            void JustReachedHome()
            {
                me->SetHealth(spawnHealth);
                isEmpowered = false;
            }

            void JustRespawned()
            {
                DoCast(me, SPELL_FEIGN_DEATH);
                me->SetHealth(spawnHealth);
            }

            void SpellHit(Unit* /*caster*/, SpellEntry const* spell)
            {
                if (spell->Id == SPELL_INVOCATION_OF_BLOOD_KELESETH)
                    DoAction(ACTION_CAST_INVOCATION);
            }

            void JustSummoned(Creature* summon)
            {
                summons.Summon(summon);
            }

            void DamageDealt(Unit* /*target*/, uint32& damage, DamageEffectType damageType)
            {
                if (damageType != SPELL_DIRECT_DAMAGE)
                    return;

                if (damage > RAID_MODE<uint32>(23000, 25000, 23000, 25000))
                    instance->SetData(DATA_ORB_WHISPERER_ACHIEVEMENT, uint32(false));
            }

            void DamageTaken(Unit* attacker, uint32& damage)
            {
                if (!isEmpowered)
                {
                    me->AddThreat(attacker, float(damage));
                    damage = 0;
                }
            }

            void KilledUnit(Unit* victim)
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_KELESETH_KILL);
            }

            void DoAction(const int32 action)
            {
                switch (action)
                {
                    case ACTION_STAND_UP:
                        me->RemoveAurasDueToSpell(SPELL_FEIGN_DEATH);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_OOC_NOT_ATTACKABLE);
                        me->RemoveFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_DEAD);
                        me->RemoveFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_FEIGN_DEATH);
                        me->ForceValuesUpdateAtIndex(UNIT_NPC_FLAGS);   // was in sniff. don't ask why
                        me->m_Events.AddEvent(new StandUpEvent(*me), me->m_Events.CalculateTime(1000));
                        break;
                    case ACTION_CAST_INVOCATION:
                        Talk(SAY_KELESETH_INVOCATION);
                        DoCast(me, SPELL_INVOCATION_VISUAL_ACTIVE, true);
                        isEmpowered = true;
                        break;
                    case ACTION_REMOVE_INVOCATION:
                        me->SetHealth(spawnHealth);
                        me->RemoveAurasDueToSpell(SPELL_INVOCATION_VISUAL_ACTIVE);
                        me->RemoveAurasDueToSpell(SPELL_INVOCATION_OF_BLOOD_KELESETH);
                        isEmpowered = false;
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim() || !CheckInRoom())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BERSERK:
                            DoCast(me, SPELL_BERSERK);
                            Talk(EMOTE_KELESETH_BERSERK);
                            break;
                        case EVENT_SHADOW_RESONANCE:
                            Talk(SAY_KELESETH_SPECIAL);
                            DoCast(me, SPELL_SHADOW_RESONANCE);
                            events.ScheduleEvent(EVENT_SHADOW_RESONANCE, urand(10000, 15000));
                            break;
                        case EVENT_SHADOW_LANCE:
                            if (isEmpowered)
                                DoCastVictim(SPELL_EMPOWERED_SHADOW_LANCE);
                            else
                                DoCastVictim(SPELL_SHADOW_LANCE);
                            events.ScheduleEvent(EVENT_SHADOW_LANCE, 2000);
                            break;
                        default:
                            break;
                    }
                }

                // does not melee
            }

        private:
            bool isEmpowered;  // bool check faster than map lookup
            uint32 spawnHealth;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_prince_kelesethAI(creature);
        }
};

class boss_prince_taldaram_icc : public CreatureScript
{
    public:
        boss_prince_taldaram_icc() : CreatureScript("boss_prince_taldaram_icc") { }

        struct boss_prince_taldaramAI : public BossAI
        {
            boss_prince_taldaramAI(Creature* creature) : BossAI(creature, DATA_BLOOD_PRINCE_COUNCIL)
            {
                isEmpowered = false;
                spawnHealth = creature->GetMaxHealth();
            }

            void InitializeAI()
            {
                if (CreatureData const* data = sObjectMgr->GetCreatureData(me->GetDBTableGUIDLow()))
                    if (data->curhealth)
                        spawnHealth = data->curhealth;

                if (!instance || static_cast<InstanceMap*>(me->GetMap())->GetScriptId() != GetScriptId(ICCScriptName))
                    me->IsAIEnabled = false;
                else if (!me->isDead())
                    JustRespawned();

                me->SetReactState(REACT_DEFENSIVE);
            }

            void Reset()
            {
                events.Reset();
                summons.DespawnAll();

                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
                isEmpowered = false;
                me->SetHealth(spawnHealth);
                instance->SetData(DATA_ORB_WHISPERER_ACHIEVEMENT, uint32(true));
                me->SetReactState(REACT_DEFENSIVE);
                if (IsHeroic())
                    DoCast(me, SPELL_SHADOW_PRISON);
            }

            void MoveInLineOfSight(Unit* /*who*/)
            {
            }

            void EnterCombat(Unit* /*who*/)
            {
                if (Creature* controller = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_BLOOD_PRINCES_CONTROL)))
                    if (!controller->isInCombat())
                        DoZoneInCombat(controller);

                events.ScheduleEvent(EVENT_BERSERK, 600000);
                events.ScheduleEvent(EVENT_GLITTERING_SPARKS, urand(12000,15000));
                events.ScheduleEvent(EVENT_CONJURE_FLAME, 20000);
            }

            void JustDied(Unit* /*killer*/)
            {
                Talk(EMOTE_TALDARAM_DEATH);
            }

            void JustReachedHome()
            {
                me->SetHealth(spawnHealth);
                isEmpowered = false;
            }

            void JustRespawned()
            {
                DoCast(me, SPELL_FEIGN_DEATH);
                me->SetHealth(spawnHealth);
            }

            void SpellHit(Unit* /*caster*/, SpellEntry const* spell)
            {
                if (spell->Id == SPELL_INVOCATION_OF_BLOOD_TALDARAM)
                    DoAction(ACTION_CAST_INVOCATION);
            }

            void JustSummoned(Creature* summon)
            {
                summons.Summon(summon);
                Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, -10.0f, true); // first try at distance
                if (!target)
                    target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true);     // too bad for you raiders, its going to boom

                if (summon->GetEntry() == NPC_BALL_OF_INFERNO_FLAME && target)
                    Talk(EMOTE_TALDARAM_FLAME, target->GetGUID());

                if (target)
                    summon->AI()->SetGUID(target->GetGUID());
            }

            void DamageDealt(Unit* /*target*/, uint32& damage, DamageEffectType damageType)
            {
                if (damageType != SPELL_DIRECT_DAMAGE)
                    return;

                if (damage > RAID_MODE<uint32>(23000, 25000, 23000, 25000))
                    instance->SetData(DATA_ORB_WHISPERER_ACHIEVEMENT, uint32(false));
            }

            void DamageTaken(Unit* attacker, uint32& damage)
            {
                if (!isEmpowered)
                {
                    me->AddThreat(attacker, float(damage));
                    damage = 0;
                }
            }

            void KilledUnit(Unit* victim)
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_TALDARAM_KILL);
            }

            void DoAction(const int32 action)
            {
                switch (action)
                {
                    case ACTION_STAND_UP:
                        me->RemoveAurasDueToSpell(SPELL_FEIGN_DEATH);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_OOC_NOT_ATTACKABLE);
                        me->RemoveFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_DEAD);
                        me->RemoveFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_FEIGN_DEATH);
                        me->ForceValuesUpdateAtIndex(UNIT_NPC_FLAGS);   // was in sniff. don't ask why
                        me->m_Events.AddEvent(new StandUpEvent(*me), me->m_Events.CalculateTime(1000));
                        break;
                    case ACTION_CAST_INVOCATION:
                        Talk(SAY_TALDARAM_INVOCATION);
                        DoCast(me, SPELL_INVOCATION_VISUAL_ACTIVE, true);
                        isEmpowered = true;
                        break;
                    case ACTION_REMOVE_INVOCATION:
                        me->SetHealth(spawnHealth);
                        me->RemoveAurasDueToSpell(SPELL_INVOCATION_VISUAL_ACTIVE);
                        me->RemoveAurasDueToSpell(SPELL_INVOCATION_OF_BLOOD_TALDARAM);
                        isEmpowered = false;
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim() || !CheckInRoom())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BERSERK:
                            DoCast(me, SPELL_BERSERK);
                            Talk(EMOTE_TALDARAM_BERSERK);
                            break;
                        case EVENT_GLITTERING_SPARKS:
                            DoCastVictim(SPELL_GLITTERING_SPARKS);
                            events.ScheduleEvent(EVENT_GLITTERING_SPARKS, urand(15000, 50000));
                            break;
                        case EVENT_CONJURE_FLAME:
                            if (isEmpowered)
                            {
                                DoCast(me, SPELL_CONJURE_EMPOWERED_FLAME);
                                events.ScheduleEvent(EVENT_CONJURE_FLAME, urand(15000, 25000));
                            }
                            else
                            {
                                DoCast(me, SPELL_CONJURE_FLAME);
                                events.ScheduleEvent(EVENT_CONJURE_FLAME, urand(20000, 30000));
                            }
                            Talk(SAY_TALDARAM_SPECIAL);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            uint32 spawnHealth;
            bool isEmpowered;  // bool check faster than map lookup
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_prince_taldaramAI(creature);
        }
};

class boss_prince_valanar_icc : public CreatureScript
{
    public:
        boss_prince_valanar_icc() : CreatureScript("boss_prince_valanar_icc") { }

        struct boss_prince_valanarAI : public BossAI
        {
            boss_prince_valanarAI(Creature* creature) : BossAI(creature, DATA_BLOOD_PRINCE_COUNCIL)
            {
                isEmpowered = false;
                spawnHealth = creature->GetMaxHealth();
            }

            void InitializeAI()
            {
                if (CreatureData const* data = sObjectMgr->GetCreatureData(me->GetDBTableGUIDLow()))
                    if (data->curhealth)
                        spawnHealth = data->curhealth;

                if (!instance || static_cast<InstanceMap*>(me->GetMap())->GetScriptId() != GetScriptId(ICCScriptName))
                    me->IsAIEnabled = false;
                else if (!me->isDead())
                    JustRespawned();

                me->SetReactState(REACT_DEFENSIVE);
            }

            void Reset()
            {
                events.Reset();
                summons.DespawnAll();

                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
                isEmpowered = false;
                me->SetHealth(me->GetMaxHealth());
                instance->SetData(DATA_ORB_WHISPERER_ACHIEVEMENT, uint32(true));
                me->SetReactState(REACT_DEFENSIVE);
                if (IsHeroic())
                    DoCast(me, SPELL_SHADOW_PRISON);
            }

            void MoveInLineOfSight(Unit* /*who*/)
            {
            }

            void EnterCombat(Unit* /*who*/)
            {
                if (Creature* controller = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_BLOOD_PRINCES_CONTROL)))
                    if (!controller->isInCombat())
                        DoZoneInCombat(controller);

                events.ScheduleEvent(EVENT_BERSERK, 600000);
                events.ScheduleEvent(EVENT_KINETIC_BOMB, urand(18000, 24000));
                events.ScheduleEvent(EVENT_SHOCK_VORTEX, urand(15000, 20000));
            }

            void JustDied(Unit* /*killer*/)
            {
                Talk(SAY_VALANAR_DEATH);
            }

            void JustReachedHome()
            {
                me->SetHealth(me->GetMaxHealth());
                isEmpowered = false;
            }

            void JustRespawned()
            {
                DoCast(me, SPELL_FEIGN_DEATH);
                me->SetHealth(spawnHealth);
            }

            void JustSummoned(Creature* summon)
            {
                switch (summon->GetEntry())
                {
                    case NPC_KINETIC_BOMB_TARGET:
                        summon->SetReactState(REACT_PASSIVE);
                        summon->CastSpell(summon, SPELL_KINETIC_BOMB, true, NULL, NULL, me->GetGUID());
                        break;
                    case NPC_KINETIC_BOMB:
                    {
                        float x, y, z;
                        summon->GetPosition(x, y, z);
                        float ground_Z = summon->GetMap()->GetHeight(x, y, z, true, 500.0f);
                        summon->GetMotionMaster()->MovePoint(POINT_KINETIC_BOMB_IMPACT, x, y, ground_Z);
                        break;
                    }
                    case NPC_SHOCK_VORTEX:
                        summon->CastSpell(summon, SPELL_SHOCK_VORTEX_DUMMY, true);
                        summon->CastSpell(summon, SPELL_SHOCK_VORTEX_PERIODIC, true);
                        break;
                    default:
                        break;
                }
                summons.Summon(summon);
                if (me->isInCombat())
                    DoZoneInCombat(summon);
            }

            void SpellHit(Unit* /*caster*/, SpellEntry const* spell)
            {
                if (spell->Id == SPELL_INVOCATION_OF_BLOOD_VALANAR)
                    DoAction(ACTION_CAST_INVOCATION);
            }

            void DamageDealt(Unit* /*target*/, uint32& damage, DamageEffectType damageType)
            {
                if (damageType != SPELL_DIRECT_DAMAGE)
                    return;

                if (damage > RAID_MODE<uint32>(23000, 25000, 23000, 25000))
                    instance->SetData(DATA_ORB_WHISPERER_ACHIEVEMENT, uint32(false));
            }

            void DamageTaken(Unit* attacker, uint32& damage)
            {
                if (!isEmpowered)
                {
                    me->AddThreat(attacker, float(damage));
                    damage = 0;
                }
            }

            void KilledUnit(Unit* victim)
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_VALANAR_KILL);
            }

            void DoAction(const int32 action)
            {
                switch (action)
                {
                    case ACTION_STAND_UP:
                        me->RemoveAurasDueToSpell(SPELL_FEIGN_DEATH);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_OOC_NOT_ATTACKABLE);
                        me->RemoveFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_DEAD);
                        me->RemoveFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_FEIGN_DEATH);
                        me->ForceValuesUpdateAtIndex(UNIT_NPC_FLAGS);   // was in sniff. don't ask why
                        me->m_Events.AddEvent(new StandUpEvent(*me), me->m_Events.CalculateTime(1000));
                        break;
                    case ACTION_CAST_INVOCATION:
                        Talk(SAY_VALANAR_INVOCATION);
                        DoCast(me, SPELL_INVOCATION_VISUAL_ACTIVE, true);
                        isEmpowered = true;
                        break;
                    case ACTION_REMOVE_INVOCATION:
                        me->SetHealth(spawnHealth);
                        me->RemoveAurasDueToSpell(SPELL_INVOCATION_VISUAL_ACTIVE);
                        me->RemoveAurasDueToSpell(SPELL_INVOCATION_OF_BLOOD_VALANAR);
                        isEmpowered = false;
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim() || !CheckInRoom())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BERSERK:
                            DoCast(me, SPELL_BERSERK);
                            Talk(SAY_VALANAR_BERSERK);
                            break;
                        case EVENT_KINETIC_BOMB:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true))
                            {
                                DoCast(target, SPELL_KINETIC_BOMB_TARGET);
                                Talk(SAY_VALANAR_SPECIAL);
                            }
                            events.ScheduleEvent(EVENT_KINETIC_BOMB, urand(18000, 24000));
                            break;
                        case EVENT_SHOCK_VORTEX:
                            if (isEmpowered)
                            {
                                DoCast(me, SPELL_EMPOWERED_SHOCK_VORTEX);
                                Talk(EMOTE_VALANAR_SHOCK_VORTEX);
                                events.ScheduleEvent(EVENT_SHOCK_VORTEX, 30000);
                            }
                            else
                            {
                                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true))
                                    DoCast(target, SPELL_SHOCK_VORTEX);
                                events.ScheduleEvent(EVENT_SHOCK_VORTEX, urand(18000, 23000));
                            }
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            uint32 spawnHealth;
            bool isEmpowered;  // bool check faster than map lookup
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_prince_valanarAI(creature);
        }
};

class npc_blood_queen_lana_thel : public CreatureScript
{
    public:
        npc_blood_queen_lana_thel() : CreatureScript("npc_blood_queen_lana_thel") { }

        struct npc_blood_queen_lana_thelAI : public ScriptedAI
        {
            npc_blood_queen_lana_thelAI(Creature* creature) : ScriptedAI(creature)
            {
                introDone = false;
                instance = creature->GetInstanceScript();
            }

            void InitializeAI()
            {
                if (!instance || static_cast<InstanceMap*>(me->GetMap())->GetScriptId() != GetScriptId(ICCScriptName))
                    me->IsAIEnabled = false;
                else if (!me->isDead())
                    Reset();
            }

            void Reset()
            {
                events.Reset();
                me->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                if (instance->GetBossState(DATA_BLOOD_PRINCE_COUNCIL) == DONE)
                {
                    me->SetVisible(false);
                    introDone = true;
                }
                else
                    me->SetVisible(true);
            }

            void MoveInLineOfSight(Unit* who)
            {
                if (introDone)
                    return;

                if (!me->IsWithinDistInMap(who, 35.0f))
                    return;

                introDone = true;
                Talk(SAY_INTRO_1);
                events.SetPhase(1);
                events.ScheduleEvent(EVENT_INTRO_1, 14000);
                // summon a visual trigger
                if (Creature* summon = DoSummon(NPC_FLOATING_TRIGGER, triggerPos, 15000, TEMPSUMMON_TIMED_DESPAWN))
                {
                    summon->CastSpell(summon, SPELL_OOC_INVOCATION_VISUAL, true);
                    summon->SetSpeed(MOVE_FLIGHT, 0.15f, true);
                    summon->GetMotionMaster()->MovePoint(0, triggerEndPos);
                }
            }

            void MovementInform(uint32 type, uint32 id)
            {
                if (type == POINT_MOTION_TYPE && id == POINT_INTRO_DESPAWN)
                    me->SetVisible(false);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!events.GetPhaseMask())
                    return;

                events.Update(diff);

                if (events.ExecuteEvent() == EVENT_INTRO_1)
                {
                    Talk(SAY_INTRO_2);
                    me->GetMotionMaster()->MovePoint(POINT_INTRO_DESPAWN, introFinalPos);
                    events.Reset();

                    // remove Feign Death from princes
                    if (Creature* keleseth = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_PRINCE_KELESETH_GUID)))
                        keleseth->AI()->DoAction(ACTION_STAND_UP);

                    if (Creature* taldaram = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_PRINCE_TALDARAM_GUID)))
                        taldaram->AI()->DoAction(ACTION_STAND_UP);

                    if (Creature* valanar = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_PRINCE_VALANAR_GUID)))
                    {
                        valanar->AI()->DoAction(ACTION_STAND_UP);
                        valanar->SetHealth(valanar->GetMaxHealth());
                    }
                }
            }

        private:
            EventMap events;
            InstanceScript* instance;
            bool introDone;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_blood_queen_lana_thelAI(creature);
        }
};

class npc_ball_of_flame : public CreatureScript
{
    public:
        npc_ball_of_flame() : CreatureScript("npc_ball_of_flame") { }

        struct npc_ball_of_flameAI : public ScriptedAI
        {
            npc_ball_of_flameAI(Creature* creature) : ScriptedAI(creature)
            {
                despawnTimer = 0;
            }

            void Reset()
            {
                me->CastSpell(me, SPELL_BALL_OF_FLAMES_VISUAL, true);
                if (me->GetEntry() == NPC_BALL_OF_INFERNO_FLAME)
                {
                    me->CastSpell(me, SPELL_BALL_OF_FLAMES_PROC, true);
                    me->CastSpell(me, SPELL_BALL_OF_FLAMES_PERIODIC, true);
                }
            }

            void MovementInform(uint32 type, uint32 id)
            {
                if (type == TARGETED_MOTION_TYPE && id == GUID_LOPART(chaseGUID) && chaseGUID)
                {
                    me->RemoveAurasDueToSpell(SPELL_BALL_OF_FLAMES_PERIODIC);
                    DoCastAOE(SPELL_FLAMES);
                    despawnTimer = 1000;
                    chaseGUID = 0;
                }
            }

            void SetGUID(const uint64& guid, int32 /*type*/)
            {
                chaseGUID = guid;
            }

            void DoAction(const int32 action)
            {
                if (action == ACTION_FLAME_BALL_CHASE)
                    if (Player* target = ObjectAccessor::GetPlayer(*me, chaseGUID))
                    {
                        // need to clear states now because this call is before AuraEffect is fully removed
                        me->ClearUnitState(UNIT_STAT_CASTING | UNIT_STAT_STUNNED);
                        if (target && me->Attack(target, true))
                            me->GetMotionMaster()->MoveChase(target, 1.0f);
                    }
            }

            void UpdateAI(const uint32 diff)
            {
                if (!despawnTimer)
                    return;

                if (despawnTimer <= diff)
                {
                    despawnTimer = 0;
                    DoCast(me, SPELL_FLAME_SPHERE_DEATH_EFFECT);
                }
                else
                    despawnTimer -= diff;
            }

        private:
            uint64 chaseGUID;
            uint32 despawnTimer;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_ball_of_flameAI(creature);
        }
};

class npc_kinetic_bomb : public CreatureScript
{
    public:
        npc_kinetic_bomb() : CreatureScript("npc_kinetic_bomb") { }

        struct npc_kinetic_bombAI : public ScriptedAI
        {
            npc_kinetic_bombAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset()
            {
                events.Reset();
                me->SetDisplayId(DISPLAY_KINETIC_BOMB);
                me->CastSpell(me, SPELL_UNSTABLE, true);
                me->CastCustomSpell(SPELL_KINETIC_BOMB_VISUAL, SPELLVALUE_BASE_POINT0, 0x7FFFFFFF, me, true);
                me->SetReactState(REACT_PASSIVE);
                me->SetSpeed(MOVE_FLIGHT, IsHeroic() ? 0.3f : 0.15f, true);
                me->GetPosition(x, y, groundZ);
                groundZ = me->GetMap()->GetHeight(x, y, groundZ, true, 500.0f);
            }

            void DoAction(const int32 action)
            {
                if (action == SPELL_KINETIC_BOMB_EXPLOSION)
                    events.ScheduleEvent(EVENT_BOMB_DESPAWN, 1000);
                else if (action == ACTION_KINETIC_BOMB_JUMP)
                {
                    me->GetMotionMaster()->Clear();
                    me->GetMotionMaster()->MoveJump(x, y, me->GetPositionZ()+7.0f, 1.0f, 7.0f);
                    events.ScheduleEvent(EVENT_CONTINUE_FALLING, 700);
                }
            }

            void UpdateAI(const uint32 diff)
            {
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BOMB_DESPAWN:
                            me->SetVisible(false);
                            break;
                        case EVENT_CONTINUE_FALLING:
                            me->GetMotionMaster()->Clear();
                            me->GetMotionMaster()->MovePoint(POINT_KINETIC_BOMB_IMPACT, x, y, groundZ);
                            break;
                        default:
                            break;
                    }
                }
            }

        private:
            EventMap events;
            float x, y, groundZ;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_kinetic_bombAI(creature);
        }
};

class npc_dark_nucleus : public CreatureScript
{
    public:
        npc_dark_nucleus() : CreatureScript("npc_dark_nucleus") { }

        struct npc_dark_nucleusAI : public ScriptedAI
        {
            npc_dark_nucleusAI(Creature* creature) : ScriptedAI(creature)
            {
                lockedTarget = false;
                targetAuraCheck = 0;
            }

            void Reset()
            {
                me->SetReactState(REACT_PASSIVE);
                me->CastSpell(me, SPELL_SHADOW_RESONANCE_AURA, true);
            }

            void EnterCombat(Unit* who)
            {
                targetAuraCheck = 1000;
                if (me->GetDistance(who) >= 15.0f)
                {
                    DoStartMovement(who);
                    return;
                }

                DoCast(who, SPELL_SHADOW_RESONANCE_RESIST);
                me->ClearUnitState(UNIT_STAT_CASTING);
            }

            void MoveInLineOfSight(Unit* who)
            {
                if (me->GetDistance(who) >= 15.0f)
                    return;

                ScriptedAI::MoveInLineOfSight(who);
            }

            void DamageTaken(Unit* attacker, uint32& /*damage*/)
            {
                if (attacker == me)
                    return;

                if (!lockedTarget)
                    if (me->getVictim() == attacker)
                        lockedTarget = true;
            }

            void UpdateAI(const uint32 diff)
            {
                if (!me->isInCombat())
                    return;

                if (targetAuraCheck <= diff)
                {
                    targetAuraCheck = 1000;
                    if (Unit* victim = me->getVictim())
                        if (me->GetDistance(victim) < 15.0f &&
                            !victim->HasAura(SPELL_SHADOW_RESONANCE_RESIST, me->GetGUID()))
                        {
                            DoCast(victim, SPELL_SHADOW_RESONANCE_RESIST);
                            me->ClearUnitState(UNIT_STAT_CASTING);
                        }
                }
                else
                    targetAuraCheck -= diff;

                if (!lockedTarget)
                {
                    if (Unit* victim = me->SelectVictim())
                    {
                        if (me->getVictim() && me->getVictim() != victim)
                        {
                            me->getVictim()->RemoveAurasDueToSpell(SPELL_SHADOW_RESONANCE_RESIST, me->GetGUID());
                            lockedTarget = true;
                        }

                        lockedTarget = true;
                        AttackStart(victim);
                        DoCast(victim, SPELL_SHADOW_RESONANCE_RESIST);
                        me->ClearUnitState(UNIT_STAT_CASTING);
                    }
                }
            }

        private:
            uint32 targetAuraCheck; // no point for EventMap with only one timer
            bool lockedTarget;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_dark_nucleusAI(creature);
        }
};

class spell_taldaram_glittering_sparks : public SpellScriptLoader
{
    public:
        spell_taldaram_glittering_sparks() : SpellScriptLoader("spell_taldaram_glittering_sparks") { }

        class spell_taldaram_glittering_sparks_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_taldaram_glittering_sparks_SpellScript);

            void HandleScript(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                GetCaster()->CastSpell(GetCaster(), uint32(GetEffectValue()), true);
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_taldaram_glittering_sparks_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_taldaram_glittering_sparks_SpellScript();
        }
};

class spell_taldaram_summon_flame_ball : public SpellScriptLoader
{
    public:
        spell_taldaram_summon_flame_ball() : SpellScriptLoader("spell_taldaram_summon_flame_ball") { }

        class spell_taldaram_summon_flame_ball_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_taldaram_summon_flame_ball_SpellScript);

            void HandleScript(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                GetCaster()->CastSpell(GetCaster(), uint32(GetEffectValue()), true);
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_taldaram_summon_flame_ball_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_taldaram_summon_flame_ball_SpellScript();
        }
};

class spell_taldaram_flame_ball_visual : public SpellScriptLoader
{
    public:
        spell_taldaram_flame_ball_visual() : SpellScriptLoader("spell_taldaram_flame_ball_visual") { }

        class spell_flame_ball_visual_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_flame_ball_visual_AuraScript);

            bool Load()
            {
                if (GetCaster()->GetEntry() == NPC_BALL_OF_FLAME || GetCaster()->GetEntry() == NPC_BALL_OF_INFERNO_FLAME)
                    return true;
                return false;
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Creature* target = GetTarget()->ToCreature();
                if (!target)
                    return;

                // SPELL_FLAME_SPHERE_SPAWN_EFFECT
                if (GetSpellProto()->Id == SPELL_FLAME_SPHERE_SPAWN_EFFECT)
                {
                    target->CastSpell(target, SPELL_BALL_OF_FLAMES, true);
                    target->AI()->DoAction(ACTION_FLAME_BALL_CHASE);
                }
                else // SPELL_FLAME_SPHERE_DEATH_EFFECT
                {
                    if (TempSummon* summ = target->ToTempSummon())
                        summ->UnSummon();
                    else
                        target->ForcedDespawn();
                }
            }

            void Register()
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_flame_ball_visual_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_flame_ball_visual_AuraScript();
        }
};

class spell_taldaram_ball_of_inferno_flame : public SpellScriptLoader
{
    public:
        spell_taldaram_ball_of_inferno_flame() : SpellScriptLoader("spell_taldaram_ball_of_inferno_flame") { }

        class spell_taldaram_ball_of_inferno_flame_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_taldaram_ball_of_inferno_flame_SpellScript);

            void ModAuraStack()
            {
                if (Aura* aur = GetHitAura())
                    aur->SetStackAmount(uint8(GetSpellInfo()->StackAmount));
            }

            void Register()
            {
                AfterHit += SpellHitFn(spell_taldaram_ball_of_inferno_flame_SpellScript::ModAuraStack);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_taldaram_ball_of_inferno_flame_SpellScript();
        }
};

class spell_valanar_kinetic_bomb : public SpellScriptLoader
{
    public:
        spell_valanar_kinetic_bomb() : SpellScriptLoader("spell_valanar_kinetic_bomb") { }

        class spell_valanar_kinetic_bomb_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_valanar_kinetic_bomb_SpellScript);

            void ChangeSummonPos(SpellEffIndex /*effIndex*/)
            {
                WorldLocation* summonPos = GetTargetDest();
                Position offset = {0.0f, 0.0f, 20.0f, 0.0f};
                summonPos->RelocateOffset(offset);  // +20 in height
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_valanar_kinetic_bomb_SpellScript::ChangeSummonPos, EFFECT_0, SPELL_EFFECT_SUMMON);
            }
        };

        class spell_valanar_kinetic_bomb_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_valanar_kinetic_bomb_AuraScript);

            void HandleDummyTick(AuraEffect const* /*aurEff*/)
            {
                Unit* target = GetTarget();
                if (target->GetTypeId() != TYPEID_UNIT)
                    return;

                if (Creature* bomb = target->FindNearestCreature(NPC_KINETIC_BOMB, 1.0f, true))
                {
                    bomb->CastSpell(bomb, SPELL_KINETIC_BOMB_EXPLOSION, true);
                    bomb->RemoveAurasDueToSpell(SPELL_KINETIC_BOMB_VISUAL);
                    target->RemoveAura(GetAura());
                    bomb->AI()->DoAction(SPELL_KINETIC_BOMB_EXPLOSION);
                }
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_valanar_kinetic_bomb_AuraScript::HandleDummyTick, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_valanar_kinetic_bomb_SpellScript();
        }

        AuraScript* GetAuraScript() const
        {
            return new spell_valanar_kinetic_bomb_AuraScript();
        }
};

class spell_valanar_kinetic_bomb_knockback : public SpellScriptLoader
{
    public:
        spell_valanar_kinetic_bomb_knockback() : SpellScriptLoader("spell_valanar_kinetic_bomb_knockback") { }

        class spell_valanar_kinetic_bomb_knockback_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_valanar_kinetic_bomb_knockback_SpellScript);

            void KnockIntoAir()
            {
                if (Creature* target = GetHitCreature())
                    target->AI()->DoAction(ACTION_KINETIC_BOMB_JUMP);
            }

            void Register()
            {
                AfterHit += SpellHitFn(spell_valanar_kinetic_bomb_knockback_SpellScript::KnockIntoAir);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_valanar_kinetic_bomb_knockback_SpellScript();
        }
};

class spell_blood_council_shadow_prison : public SpellScriptLoader
{
    public:
        spell_blood_council_shadow_prison() : SpellScriptLoader("spell_blood_council_shadow_prison") { }

        class spell_blood_council_shadow_prison_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_blood_council_shadow_prison_AuraScript);

            void HandleDummyTick(AuraEffect const* aurEff)
            {
                if (GetTarget()->isMoving())
                    GetTarget()->CastSpell(GetTarget(), SPELL_SHADOW_PRISON_DAMAGE, true, NULL, aurEff);
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_blood_council_shadow_prison_AuraScript::HandleDummyTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_blood_council_shadow_prison_AuraScript();
        }
};

class spell_blood_council_shadow_prison_damage : public SpellScriptLoader
{
    public:
        spell_blood_council_shadow_prison_damage() : SpellScriptLoader("spell_blood_council_shadow_prison_damage") { }

        class spell_blood_council_shadow_prison_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_blood_council_shadow_prison_SpellScript);

            void AddExtraDamage()
            {
                if (Aura* aur = GetHitUnit()->GetAura(GetSpellInfo()->Id))
                    if (AuraEffect const* eff = aur->GetEffect(1))
                        SetHitDamage(GetHitDamage()+eff->GetAmount());
            }

            void Register()
            {
                OnHit += SpellHitFn(spell_blood_council_shadow_prison_SpellScript::AddExtraDamage);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_blood_council_shadow_prison_SpellScript();
        }
};

void AddSC_boss_blood_prince_council()
{
    new boss_blood_council_controller();
    new boss_prince_keleseth_icc();
    new boss_prince_taldaram_icc();
    new boss_prince_valanar_icc();
    new npc_blood_queen_lana_thel();
    new npc_ball_of_flame();
    new npc_kinetic_bomb();
    new npc_dark_nucleus();
    new spell_taldaram_glittering_sparks();
    new spell_taldaram_summon_flame_ball();
    new spell_taldaram_flame_ball_visual();
    new spell_taldaram_ball_of_inferno_flame();
    new spell_valanar_kinetic_bomb();
    new spell_valanar_kinetic_bomb_knockback();
    new spell_blood_council_shadow_prison();
    new spell_blood_council_shadow_prison_damage();
}
