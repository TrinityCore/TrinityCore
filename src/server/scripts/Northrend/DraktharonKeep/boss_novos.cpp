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
#include "SpellScript.h"
#include "ScriptedCreature.h"
#include "drak_tharon_keep.h"

enum Yells
{
    SAY_AGGRO                       = 0,
    SAY_KILL                        = 1,
    SAY_DEATH                       = 2,
    SAY_SUMMONING_ADDS              = 3, // unused
    SAY_ARCANE_FIELD                = 4,
    EMOTE_SUMMONING_ADDS            = 5  // unused
};

enum Spells
{
    SPELL_BEAM_CHANNEL              = 52106,
    SPELL_ARCANE_FIELD              = 47346,

    SPELL_SUMMON_RISEN_SHADOWCASTER = 49105,
    SPELL_SUMMON_FETID_TROLL_CORPSE = 49103,
    SPELL_SUMMON_HULKING_CORPSE     = 49104,
    SPELL_SUMMON_CRYSTAL_HANDLER    = 49179,
    SPELL_SUMMON_COPY_OF_MINIONS    = 59933,

    SPELL_ARCANE_BLAST              = 49198,
    SPELL_BLIZZARD                  = 49034,
    SPELL_FROSTBOLT                 = 49037,
    SPELL_WRATH_OF_MISERY           = 50089,
    SPELL_SUMMON_MINIONS            = 59910
};

enum Misc
{
    ACTION_RESET_CRYSTALS,
    ACTION_ACTIVATE_CRYSTAL,
    ACTION_DEACTIVATE,
    EVENT_ATTACK,
    EVENT_SUMMON_MINIONS,
    DATA_NOVOS_ACHIEV
};

struct SummonerInfo
{
    uint32 data, spell, timer;
};

const SummonerInfo summoners[] =
{
    { DATA_NOVOS_SUMMONER_1, SPELL_SUMMON_RISEN_SHADOWCASTER, 15000 },
    { DATA_NOVOS_SUMMONER_2, SPELL_SUMMON_FETID_TROLL_CORPSE, 5000 },
    { DATA_NOVOS_SUMMONER_3, SPELL_SUMMON_HULKING_CORPSE, 30000 },
    { DATA_NOVOS_SUMMONER_4, SPELL_SUMMON_CRYSTAL_HANDLER, 30000 }
};

#define MAX_Y_COORD_OH_NOVOS        -771.95f

class boss_novos : public CreatureScript
{
public:
    boss_novos() : CreatureScript("boss_novos") { }

    struct boss_novosAI : public BossAI
    {
        boss_novosAI(Creature* creature) : BossAI(creature, DATA_NOVOS)
        {
            Initialize();
            _bubbled = false;
        }

        void Initialize()
        {
            _ohNovos = true;
            _crystalHandlerCount = 0;
        }

        void Reset() override
        {
            _Reset();

            Initialize();
            SetCrystalsStatus(false);
            SetSummonerStatus(false);
            SetBubbled(false);
        }

        void EnterCombat(Unit* /* victim */) override
        {
            _EnterCombat();
            Talk(SAY_AGGRO);

            SetCrystalsStatus(true);
            SetSummonerStatus(true);
            SetBubbled(true);
        }

        void AttackStart(Unit* target) override
        {
            if (!target)
                return;

            if (me->Attack(target, true))
                DoStartNoMovement(target);
        }

        void KilledUnit(Unit* who) override
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_KILL);
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();
            Talk(SAY_DEATH);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim() || _bubbled)
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SUMMON_MINIONS:
                        DoCast(SPELL_SUMMON_MINIONS);
                        events.ScheduleEvent(EVENT_SUMMON_MINIONS, 15000);
                        break;
                    case EVENT_ATTACK:
                        if (Unit* victim = SelectTarget(SELECT_TARGET_RANDOM))
                            DoCast(victim, RAND(SPELL_ARCANE_BLAST, SPELL_BLIZZARD, SPELL_FROSTBOLT, SPELL_WRATH_OF_MISERY));
                        events.ScheduleEvent(EVENT_ATTACK, 3000);
                        break;
                    default:
                        break;
                }
            }
        }

        void DoAction(int32 action) override
        {
            if (action == ACTION_CRYSTAL_HANDLER_DIED)
                CrystalHandlerDied();
        }

        void MoveInLineOfSight(Unit* who) override
        {
            BossAI::MoveInLineOfSight(who);

            if (!_ohNovos || !who || who->GetTypeId() != TYPEID_UNIT || who->GetPositionY() > MAX_Y_COORD_OH_NOVOS)
                return;

            uint32 entry = who->GetEntry();
            if (entry == NPC_HULKING_CORPSE || entry == NPC_RISEN_SHADOWCASTER || entry == NPC_FETID_TROLL_CORPSE)
                _ohNovos = false;
        }

        uint32 GetData(uint32 type) const override
        {
            return type == DATA_NOVOS_ACHIEV && _ohNovos ? 1 : 0;
        }

        void JustSummoned(Creature* summon) override
        {
            summons.Summon(summon);
        }

    private:
        void SetBubbled(bool state)
        {
            _bubbled = state;
            if (!state)
            {
                if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC))
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                if (me->HasUnitState(UNIT_STATE_CASTING))
                    me->CastStop();
            }
            else
            {
                if (!me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                if (!me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC))
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                DoCast(SPELL_ARCANE_FIELD);
            }
        }

        void SetSummonerStatus(bool active)
        {
            for (uint8 i = 0; i < 4; i++)
                if (uint64 guid = instance->GetGuidData(summoners[i].data))
                    if (Creature* crystalChannelTarget = ObjectAccessor::GetCreature(*me, guid))
                    {
                        if (active)
                            crystalChannelTarget->AI()->SetData(summoners[i].spell, summoners[i].timer);
                        else
                            crystalChannelTarget->AI()->Reset();
                    }
        }

        void SetCrystalsStatus(bool active)
        {
            for (uint8 i = 0; i < 4; i++)
                if (uint64 guid = instance->GetGuidData(DATA_NOVOS_CRYSTAL_1 + i))
                    if (GameObject* crystal = ObjectAccessor::GetGameObject(*me, guid))
                        SetCrystalStatus(crystal, active);
        }

        void SetCrystalStatus(GameObject* crystal, bool active)
        {
            crystal->SetGoState(active ? GO_STATE_ACTIVE : GO_STATE_READY);
            if (Creature* crystalChannelTarget = crystal->FindNearestCreature(NPC_CRYSTAL_CHANNEL_TARGET, 5.0f))
            {
                if (active)
                    crystalChannelTarget->CastSpell((Unit*)NULL, SPELL_BEAM_CHANNEL);
                else if (crystalChannelTarget->HasUnitState(UNIT_STATE_CASTING))
                    crystalChannelTarget->CastStop();
            }
        }

        void CrystalHandlerDied()
        {
            for (uint8 i = 0; i < 4; i++)
                if (uint64 guid = instance->GetGuidData(DATA_NOVOS_CRYSTAL_1 + i))
                    if (GameObject* crystal = ObjectAccessor::GetGameObject(*me, guid))
                        if (crystal->GetGoState() == GO_STATE_ACTIVE)
                        {
                            SetCrystalStatus(crystal, false);
                            break;
                        }

            if (++_crystalHandlerCount >= 4)
            {
                Talk(SAY_ARCANE_FIELD);
                SetSummonerStatus(false);
                SetBubbled(false);
                events.ScheduleEvent(EVENT_ATTACK, 3000);
                if (IsHeroic())
                    events.ScheduleEvent(EVENT_SUMMON_MINIONS, 15000);
            }
            else if (uint64 guid = instance->GetGuidData(DATA_NOVOS_SUMMONER_4))
                if (Creature* crystalChannelTarget = ObjectAccessor::GetCreature(*me, guid))
                    crystalChannelTarget->AI()->SetData(SPELL_SUMMON_CRYSTAL_HANDLER, 15000);
        }

        uint8 _crystalHandlerCount;
        bool _ohNovos;
        bool _bubbled;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetDrakTharonKeepAI<boss_novosAI>(creature);
    }
};

class npc_crystal_channel_target : public CreatureScript
{
public:
    npc_crystal_channel_target() : CreatureScript("npc_crystal_channel_target") { }

    struct npc_crystal_channel_targetAI : public ScriptedAI
    {
        npc_crystal_channel_targetAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            _spell = 0;
            _timer = 0;
            _temp = 0;
        }

        void Reset() override
        {
            Initialize();
        }

        void UpdateAI(uint32 diff) override
        {
            if (_spell)
            {
                if (_temp <= diff)
                {
                    DoCast(_spell);
                    _temp = _timer;
                }
                else
                    _temp -= diff;
            }
        }

        void SetData(uint32 id, uint32 value) override
        {
            _spell = id;
            _timer = value;
            _temp = value;
        }

        void JustSummoned(Creature* summon) override
        {
            if (InstanceScript* instance = me->GetInstanceScript())
                if (uint64 guid = instance->GetGuidData(DATA_NOVOS))
                    if (Creature* novos = ObjectAccessor::GetCreature(*me, guid))
                        novos->AI()->JustSummoned(summon);

            if (summon)
                summon->GetMotionMaster()->MovePath(summon->GetEntry() * 100, false);

            if (_spell == SPELL_SUMMON_CRYSTAL_HANDLER)
                Reset();
        }

    private:
        uint32 _spell;
        uint32 _timer;
        uint32 _temp;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetDrakTharonKeepAI<npc_crystal_channel_targetAI>(creature);
    }
};

class achievement_oh_novos : public AchievementCriteriaScript
{
public:
    achievement_oh_novos() : AchievementCriteriaScript("achievement_oh_novos") { }

    bool OnCheck(Player* /*player*/, Unit* target) override
    {
        return target && target->GetTypeId() == TYPEID_UNIT && target->ToCreature()->AI()->GetData(DATA_NOVOS_ACHIEV);
    }
};

class spell_novos_summon_minions : public SpellScriptLoader
{
    public:
        spell_novos_summon_minions() : SpellScriptLoader("spell_novos_summon_minions") { }

        class spell_novos_summon_minions_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_novos_summon_minions_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SUMMON_COPY_OF_MINIONS))
                    return false;
                return true;
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                for (uint8 i = 0; i < 2; ++i)
                    GetCaster()->CastSpell((Unit*)NULL, SPELL_SUMMON_COPY_OF_MINIONS, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_novos_summon_minions_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_novos_summon_minions_SpellScript();
        }
};

void AddSC_boss_novos()
{
    new boss_novos();
    new npc_crystal_channel_target();
    new spell_novos_summon_minions();
    new achievement_oh_novos();
}
