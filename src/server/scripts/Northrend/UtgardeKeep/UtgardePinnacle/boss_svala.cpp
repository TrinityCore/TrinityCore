/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "utgarde_pinnacle.h"

enum Spells
{
    SPELL_SVALA_TRANSFORMING1                     = 54140,
    SPELL_SVALA_TRANSFORMING2                     = 54205,
    SPELL_TRANSFORMING_CHANNEL                    = 54142,

    SPELL_CALL_FLAMES                             = 48258, // caster effect only, triggers event 17841
    SPELL_SINSTER_STRIKE                          = 15667,
    H_SPELL_SINSTER_STRIKE                        = 59409,

    SPELL_RITUAL_PREPARATION                      = 48267,
    SPELL_RITUAL_OF_THE_SWORD                     = 48276,
    SPELL_RITUAL_STRIKE_TRIGGER                   = 48331, // triggers 48277 & 59930, needs NPC_RITUAL_TARGET as spell_script_target
    SPELL_RITUAL_DISARM                           = 54159,
    SPELL_RITUAL_STRIKE_EFF_1                     = 48277,
    SPELL_RITUAL_STRIKE_EFF_2                     = 59930,

    SPELL_SUMMONED_VIS                            = 64446,
    SPELL_RITUAL_CHANNELER_1                      = 48271,
    SPELL_RITUAL_CHANNELER_2                      = 48274,
    SPELL_RITUAL_CHANNELER_3                      = 48275,

    // Ritual Channeler spells
    SPELL_PARALYZE                                = 48278,
    SPELL_SHADOWS_IN_THE_DARK                     = 59407,

    // Scourge Hulk spells
    SPELL_MIGHTY_BLOW                             = 48697,
    SPELL_VOLATILE_INFECTION                      = 56785,
    H_SPELL_VOLATILE_INFECTION                    = 59228
};

enum Yells
{
    // Svala
    SAY_SVALA_INTRO_0                             = 0,

    // Svala Sorrowgrave
    SAY_SVALA_INTRO_1                             = 0,
    SAY_SVALA_INTRO_2                             = 1,
    SAY_AGGRO                                     = 2,
    SAY_SLAY                                      = 3,
    SAY_DEATH                                     = 4,
    SAY_SACRIFICE_PLAYER                          = 5,

    // Image of Arthas
    SAY_DIALOG_OF_ARTHAS_1                        = 0,
    SAY_DIALOG_OF_ARTHAS_2                        = 1
};

enum Creatures
{
    NPC_ARTHAS                                      = 29280, // Image of Arthas
    NPC_RITUAL_CHANNELER                            = 27281,
    NPC_SPECTATOR                                   = 26667,
    NPC_RITUAL_TARGET                               = 27327,
    NPC_FLAME_BRAZIER                               = 27273,
    NPC_SCOURGE_HULK                                = 26555
};

enum Phases
{
    IDLE        = 1,
    INTRO,
    NORMAL,
    SACRIFICING,
    SVALADEAD
};

enum Events
{
    //INTRO
    EVENT_INTRO_SVALA_TALK_0    = 1,
    EVENT_INTRO_ARTHAS_TALK_0,
    EVENT_INTRO_TRANSFORM_0,
    EVENT_INTRO_TRANSFORM_1,
    EVENT_INTRO_TRANSFORM_2,
    EVENT_INTRO_SVALA_TALK_1,
    EVENT_INTRO_ARTHAS_TALK_1,
    EVENT_INTRO_SVALA_TALK_2,
    EVENT_INTRO_RELOCATE_SVALA,
    EVENT_INTRO_DESPAWN_ARTHAS,

    //NORMAL
    EVENT_SINISTER_STRIKE,
    EVENT_CALL_FLAMES,
    EVENT_RITUAL_PREPARATION,

    //SACRIFICING
    EVENT_SPAWN_RITUAL_CHANNELERS,
    EVENT_RITUAL_STRIKE,
    EVENT_RITUAL_DISARM
};

enum Misc
{
    DATA_INCREDIBLE_HULK        = 2043
};

Position const spectatorWP[2] =
{
    {296.95f, -312.76f, 86.36f, 0.0f },
    {297.69f, -275.81f, 86.36f, 0.0f }
};

Position const ArthasPos = { 295.81f, -366.16f, 92.57f, 1.58f };

class boss_svala : public CreatureScript
{
    public:
        boss_svala() : CreatureScript("boss_svala") { }

        struct boss_svalaAI : public BossAI
        {
            boss_svalaAI(Creature* creature) : BossAI(creature, DATA_SVALA_SORROWGRAVE)
            {
                Initialize();
                _introCompleted = false;
            }

            void Initialize()
            {
                _arthasGUID.Clear();
                _sacrificed = false;
            }

            void Reset() override
            {
                _Reset();

                SetCombatMovement(true);

                if (_introCompleted)
                    events.SetPhase(NORMAL);
                else
                    events.SetPhase(IDLE);

                me->SetDisableGravity(events.IsInPhase(NORMAL));

                Initialize();

                instance->SetGuidData(DATA_SACRIFICED_PLAYER, ObjectGuid::Empty);
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _EnterCombat();
                Talk(SAY_AGGRO);
            }

            void JustSummoned(Creature* summon) override
            {
                if (summon->GetEntry() == NPC_RITUAL_CHANNELER)
                    summon->CastSpell(summon, SPELL_SUMMONED_VIS, true);
                summons.Summon(summon);
            }

            void MoveInLineOfSight(Unit* who) override
            {
                if (!who)
                    return;

                if (events.IsInPhase(IDLE) && me->IsValidAttackTarget(who) && me->IsWithinDistInMap(who, 40))
                {
                    events.SetPhase(INTRO);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

                    if (GameObject* mirror = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(DATA_UTGARDE_MIRROR)))
                        mirror->SetGoState(GO_STATE_READY);

                    if (Creature* arthas = me->SummonCreature(NPC_ARTHAS, ArthasPos, TEMPSUMMON_MANUAL_DESPAWN))
                    {
                        arthas->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                        _arthasGUID = arthas->GetGUID();
                    }
                    events.ScheduleEvent(EVENT_INTRO_SVALA_TALK_0, 1 * IN_MILLISECONDS, 0, INTRO);
                }
            }

            void KilledUnit(Unit* who) override
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_SLAY);
            }

            void JustDied(Unit* /*killer*/) override
            {
                if (events.IsInPhase(SACRIFICING))
                    SetEquipmentSlots(false, EQUIP_UNEQUIP, EQUIP_NO_CHANGE, EQUIP_NO_CHANGE);
                me->HandleEmoteCommand(EMOTE_ONESHOT_FLYDEATH);
                _JustDied();
                Talk(SAY_DEATH);
            }

            void SpellHitTarget(Unit* /*target*/, SpellInfo const* spellInfo) override
            {
                if (spellInfo->Id == SPELL_RITUAL_STRIKE_EFF_1 && !events.IsInPhase(NORMAL) && !events.IsInPhase(SVALADEAD))
                {
                    events.SetPhase(NORMAL);
                    events.ScheduleEvent(EVENT_SINISTER_STRIKE, 7 * IN_MILLISECONDS, 0, NORMAL);
                    events.ScheduleEvent(EVENT_CALL_FLAMES, urand(10 * IN_MILLISECONDS, 20 * IN_MILLISECONDS), 0, NORMAL);
                    SetCombatMovement(true);

                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 300.0f, true))
                        me->GetMotionMaster()->MoveChase(target);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (events.IsInPhase(IDLE))
                    return;

                if (events.IsInPhase(NORMAL) && !UpdateVictim())
                    return;

                events.Update(diff);

                if (!_sacrificed && HealthBelowPct(50))
                {
                    _sacrificed = true;
                    events.SetPhase(SACRIFICING);
                    events.ScheduleEvent(EVENT_RITUAL_PREPARATION, 0, 0, SACRIFICING);
                }

                if (events.IsInPhase(NORMAL))
                    DoMeleeAttackIfReady();

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_INTRO_SVALA_TALK_0:
                            Talk(SAY_SVALA_INTRO_0);
                            events.ScheduleEvent(EVENT_INTRO_ARTHAS_TALK_0, 8.1 * IN_MILLISECONDS, 0, INTRO);
                            break;
                        case EVENT_INTRO_ARTHAS_TALK_0:
                            if (Creature* arthas = ObjectAccessor::GetCreature(*me, _arthasGUID))
                                arthas->AI()->Talk(SAY_DIALOG_OF_ARTHAS_1);
                            events.ScheduleEvent(EVENT_INTRO_TRANSFORM_0, 10 * IN_MILLISECONDS, 0, INTRO);
                            break;
                        case EVENT_INTRO_TRANSFORM_0:
                        {
                            if (Creature* arthas = ObjectAccessor::GetCreature(*me, _arthasGUID))
                                arthas->CastSpell(me, SPELL_TRANSFORMING_CHANNEL, true);
                            Position pos;
                            pos.Relocate(me);
                            pos.m_positionZ += 8.0f;
                            me->GetMotionMaster()->MoveTakeoff(0, pos);
                            // spectators flee event
                            std::list<Creature*> lspectatorList;
                            GetCreatureListWithEntryInGrid(lspectatorList, me, NPC_SPECTATOR, 100.0f);
                            for (std::list<Creature*>::iterator itr = lspectatorList.begin(); itr != lspectatorList.end(); ++itr)
                            {
                                if ((*itr)->IsAlive())
                                {
                                    (*itr)->SetStandState(UNIT_STAND_STATE_STAND);
                                    (*itr)->SetWalk(false);
                                    (*itr)->GetMotionMaster()->MovePoint(1, spectatorWP[0]);
                                }
                            }
                            events.ScheduleEvent(EVENT_INTRO_TRANSFORM_1, 4.2 * IN_MILLISECONDS, 0, INTRO);
                            break;
                        }
                        case EVENT_INTRO_TRANSFORM_1:
                            me->CastSpell(me, SPELL_SVALA_TRANSFORMING1, false);
                            events.ScheduleEvent(EVENT_INTRO_TRANSFORM_2, 6.2 * IN_MILLISECONDS, 0, INTRO);
                            break;
                        case EVENT_INTRO_TRANSFORM_2:
                            me->CastSpell(me, SPELL_SVALA_TRANSFORMING2, false);
                            if (Creature* arthas = ObjectAccessor::GetCreature(*me, _arthasGUID))
                            {
                                arthas->InterruptNonMeleeSpells(true);
                                me->SetFacingToObject(arthas);
                            }
                            me->RemoveAllAuras();
                            me->UpdateEntry(NPC_SVALA_SORROWGRAVE);
                            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            events.ScheduleEvent(EVENT_INTRO_SVALA_TALK_1, 10 * IN_MILLISECONDS, 0, INTRO);
                            break;
                        case EVENT_INTRO_SVALA_TALK_1:
                            Talk(SAY_SVALA_INTRO_1);
                            events.ScheduleEvent(EVENT_INTRO_ARTHAS_TALK_1, 3.2 * IN_MILLISECONDS, 0, INTRO);
                            break;
                        case EVENT_INTRO_ARTHAS_TALK_1:
                            if (Creature* arthas = ObjectAccessor::GetCreature(*me, _arthasGUID))
                                arthas->AI()->Talk(SAY_DIALOG_OF_ARTHAS_2);
                            events.ScheduleEvent(EVENT_INTRO_SVALA_TALK_2, 7.2 * IN_MILLISECONDS, 0, INTRO);
                            break;
                        case EVENT_INTRO_SVALA_TALK_2:
                            Talk(SAY_SVALA_INTRO_2);
                            me->SetFacingTo(1.58f);
                            if (Creature* arthas = ObjectAccessor::GetCreature(*me, _arthasGUID))
                                arthas->SetVisible(false);
                            events.ScheduleEvent(EVENT_INTRO_RELOCATE_SVALA, 13.8 * IN_MILLISECONDS, 0, INTRO);
                            break;
                        case EVENT_INTRO_RELOCATE_SVALA:
                        {
                            Position pos;
                            pos.Relocate(me);
                            pos.m_positionX = me->GetHomePosition().GetPositionX();
                            pos.m_positionY = me->GetHomePosition().GetPositionY();
                            pos.m_positionZ = 90.6065f;
                            me->GetMotionMaster()->MoveLand(0, pos);
                            me->SetDisableGravity(false, true);
                            me->SetHover(true);
                            events.ScheduleEvent(EVENT_INTRO_DESPAWN_ARTHAS, 3 * IN_MILLISECONDS, 0, INTRO);
                            break;
                        }
                        case EVENT_INTRO_DESPAWN_ARTHAS:
                            if (GameObject* mirror = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(DATA_UTGARDE_MIRROR)))
                                mirror->SetGoState(GO_STATE_ACTIVE);
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            if (Creature* arthas = ObjectAccessor::GetCreature(*me, _arthasGUID))
                                arthas->DespawnOrUnsummon();
                            _arthasGUID.Clear();
                            events.SetPhase(NORMAL);
                            _introCompleted = true;
                            events.ScheduleEvent(EVENT_SINISTER_STRIKE, 7 * IN_MILLISECONDS, 0, NORMAL);
                            events.ScheduleEvent(EVENT_CALL_FLAMES, urand(10 * IN_MILLISECONDS, 20 * IN_MILLISECONDS), 0, NORMAL);
                            break;
                        case EVENT_SINISTER_STRIKE:
                            DoCastVictim(SPELL_SINSTER_STRIKE);
                            events.ScheduleEvent(EVENT_SINISTER_STRIKE, urand(5 * IN_MILLISECONDS, 9 * IN_MILLISECONDS), 0, NORMAL);
                            break;
                        case EVENT_CALL_FLAMES:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                                DoCast(target, SPELL_CALL_FLAMES);
                            events.ScheduleEvent(EVENT_CALL_FLAMES, urand(10 * IN_MILLISECONDS, 20 * IN_MILLISECONDS), 0, NORMAL);
                            break;
                        case EVENT_RITUAL_PREPARATION:
                            if (Unit* sacrificeTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 80.0f, true))
                            {
                                instance->SetGuidData(DATA_SACRIFICED_PLAYER, sacrificeTarget->GetGUID());
                                Talk(SAY_SACRIFICE_PLAYER);
                                DoCast(sacrificeTarget, SPELL_RITUAL_PREPARATION);
                                SetCombatMovement(false);
                                DoCast(me, SPELL_RITUAL_OF_THE_SWORD);
                            }
                            events.ScheduleEvent(EVENT_SPAWN_RITUAL_CHANNELERS, 1 * IN_MILLISECONDS, 0, SACRIFICING);
                            break;
                        case EVENT_SPAWN_RITUAL_CHANNELERS:
                            DoCast(me, SPELL_RITUAL_CHANNELER_1, true);
                            DoCast(me, SPELL_RITUAL_CHANNELER_2, true);
                            DoCast(me, SPELL_RITUAL_CHANNELER_3, true);
                            events.ScheduleEvent(EVENT_RITUAL_STRIKE, 2 * IN_MILLISECONDS, 0, SACRIFICING);
                            break;
                        case EVENT_RITUAL_STRIKE:
                            me->StopMoving();
                            me->GetMotionMaster()->MoveIdle();
                            me->InterruptNonMeleeSpells(true);
                            DoCast(me, SPELL_RITUAL_STRIKE_TRIGGER, true);
                            events.ScheduleEvent(EVENT_RITUAL_DISARM, 200, 0, SACRIFICING);
                            break;
                        case EVENT_RITUAL_DISARM:
                            DoCast(me, SPELL_RITUAL_DISARM);
                            break;
                        default:
                            break;
                    }
                }
            }

        private:
            ObjectGuid _arthasGUID;
            bool _sacrificed;
            bool _introCompleted;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUtgardePinnacleAI<boss_svalaAI>(creature);
        }
};

class npc_ritual_channeler : public CreatureScript
{
    public:
        npc_ritual_channeler() : CreatureScript("npc_ritual_channeler") { }

        struct npc_ritual_channelerAI : public ScriptedAI
        {
            npc_ritual_channelerAI(Creature* creature) : ScriptedAI(creature)
            {
                Initialize();
                instance = creature->GetInstanceScript();

                SetCombatMovement(false);
            }

            void Initialize()
            {
                paralyzeTimer = 1600;
            }

            InstanceScript* instance;
            uint32 paralyzeTimer;

            void Reset() override
            {
                Initialize();

                if (IsHeroic())
                    DoCast(me, SPELL_SHADOWS_IN_THE_DARK);
            }

            void UpdateAI(uint32 diff) override
            {
                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (paralyzeTimer <= diff)
                {
                    if (Unit* victim = ObjectAccessor::GetUnit(*me, instance->GetGuidData(DATA_SACRIFICED_PLAYER)))
                        DoCast(victim, SPELL_PARALYZE, false);

                    paralyzeTimer = 200;
                }
                else
                    paralyzeTimer -= diff;
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUtgardePinnacleAI<npc_ritual_channelerAI>(creature);
        }
};

class npc_spectator : public CreatureScript
{
    public:
        npc_spectator() : CreatureScript("npc_spectator") { }

        struct npc_spectatorAI : public ScriptedAI
        {
            npc_spectatorAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset() override { }

            void MovementInform(uint32 motionType, uint32 pointId) override
            {
                if (motionType == POINT_MOTION_TYPE)
                {
                    if (pointId == 1)
                        me->GetMotionMaster()->MovePoint(2, spectatorWP[1]);
                    else if (pointId == 2)
                        me->DespawnOrUnsummon(1000);
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUtgardePinnacleAI<npc_spectatorAI>(creature);
        }
};

class RitualTargetCheck
{
    public:
        explicit RitualTargetCheck() { }

        bool operator() (WorldObject* obj) const
        {
            if (InstanceScript* instance = obj->GetInstanceScript())
                if (instance->GetGuidData(DATA_SACRIFICED_PLAYER) == obj->GetGUID())
                    return false;

            return true;
        }
};

class spell_paralyze_pinnacle : public SpellScriptLoader
{
    public:
        spell_paralyze_pinnacle() : SpellScriptLoader("spell_paralyze_pinnacle") { }

        class spell_paralyze_pinnacle_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_paralyze_pinnacle_SpellScript);

            void FilterTargets(std::list<WorldObject*>& unitList)
            {
                unitList.remove_if(RitualTargetCheck());
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_paralyze_pinnacle_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_paralyze_pinnacle_SpellScript();
        }
};

class npc_scourge_hulk : public CreatureScript
{
    public:
        npc_scourge_hulk() : CreatureScript("npc_scourge_hulk") { }

        struct npc_scourge_hulkAI : public ScriptedAI
        {
            npc_scourge_hulkAI(Creature* creature) : ScriptedAI(creature)
            {
                Initialize();
            }

            void Initialize()
            {
                mightyBlow = urand(4000, 9000);
                volatileInfection = urand(10000, 14000);
                killedByRitualStrike = false;
            }

            uint32 mightyBlow;
            uint32 volatileInfection;

            void Reset() override
            {
                Initialize();
            }

            uint32 GetData(uint32 type) const override
            {
                return type == DATA_INCREDIBLE_HULK ? killedByRitualStrike : 0;
            }

            void DamageTaken(Unit* attacker, uint32 &damage) override
            {
                if (damage >= me->GetHealth() && attacker->GetEntry() == NPC_SVALA_SORROWGRAVE)
                    killedByRitualStrike = true;
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (mightyBlow <= diff)
                {
                    if (Unit* victim = me->GetVictim())
                        if (!victim->HasUnitState(UNIT_STATE_STUNNED))    // Prevent knocking back a ritual player
                            DoCast(victim, SPELL_MIGHTY_BLOW);
                    mightyBlow = urand(12000, 17000);
                }
                else
                    mightyBlow -= diff;

                if (volatileInfection <= diff)
                {
                    DoCastVictim(SPELL_VOLATILE_INFECTION);
                    volatileInfection = urand(13000, 17000);
                }
                else
                    volatileInfection -= diff;

                DoMeleeAttackIfReady();
            }

        private:
            bool killedByRitualStrike;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUtgardePinnacleAI<npc_scourge_hulkAI>(creature);
        }
};

class achievement_incredible_hulk : public AchievementCriteriaScript
{
    public:
        achievement_incredible_hulk() : AchievementCriteriaScript("achievement_incredible_hulk") { }

        bool OnCheck(Player* /*player*/, Unit* target) override
        {
            return target && target->IsAIEnabled && target->GetAI()->GetData(DATA_INCREDIBLE_HULK);
        }
};

void AddSC_boss_svala()
{
    new boss_svala();
    new npc_ritual_channeler();
    new npc_spectator();
    new spell_paralyze_pinnacle();
    new npc_scourge_hulk();
    new achievement_incredible_hulk();
}
