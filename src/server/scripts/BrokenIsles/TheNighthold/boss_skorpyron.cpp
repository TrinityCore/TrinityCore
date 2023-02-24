/*
 * Copyright 2023 AzgathCore
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

#include "thenighthold.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum eSpells
{
    SPELL_ENERGIZE = 204277,
    SPELL_FOCUSED_BLAST = 204468,
    SPELL_FOCUSED_BLAST_AT = 204471,
    SPELL_CALL_SCORPID = 204371,
    SPELL_SHOCKWAVE = 204316,
    SPELL_EXOSKELETON = 204448,
    SPELL_EXOSKELETAL_VULNERABILITY = 204459,
    SPELL_INFUSED_EXOSKELETON = 205947,
    SPELL_ARCANOSLASH_DUMMY = 205200,
    SPELL_FRAGMENTS_FILTER = 209696,
    SPELL_CRYSTALL_FRAGMENTS = 204509,
    SPELL_VOLATILE_FRAGMENTS = 214663,
    SPELL_ACIDIC_FRAGMENTS = 214657,
    SPELL_REMOVE_ACIDIC = 204381,
    SPELL_VOLATILE_RESONANCE = 226229, //Mythic

    SPELL_BLUE_TRANSFORM = 215055,
    SPELL_RED_TRANSFORM = 214800,
    SPELL_GREEN_TRANSFORM = 215042,

    SPELL_ARCANE_TETHER = 204378,
    SPELL_ARCANE_TETHER_AURA = 204531,

    //Summons
    SPELL_AVAILABLE = 228943,
    SPELL_SHROUDED = 205900,
    SPELL_BURROW = 204732,
    SPELL_ENERGY_SURGE = 204766,
    SPELL_BOON_SCORPID = 205289,
    SPELL_SCORPID_SWARM_AT = 204697,
    SPELL_VOLATILE_CHITIN_VIS = 210165,
    SPELL_VOLATILE_CHITIN_DMG = 204733,
    SPELL_TOXIC_CHITIN = 204748,
    SPELL_TOXIC_CHITIN_AT = 204742,

    SPELL_BROKEN_SHARD = 204284,
    SPELL_LOS_BLOCKER = 204289,
    SPELL_CRYSTALL_FRAGMENTS_AT = 204306,
    SPELL_VOLATILE_FRAGMENTS_AT = 214661,
    SPELL_ACIDIC_FRAGMENTS_AT = 214652,
    SPELL_ACIDIC_FRAGMENTS_AURA = 214718,
};

enum eEvents
{
    EVENT_FOCUSED_BLAST = 1,
    EVENT_CALL_SCORPID = 2,
    EVENT_VULNERABILITY = 3,
    EVENT_ARCANOSLASH = 4,
};

enum eSpellVisual
{
    VISUAL_BLAST_1 = 53760,
    VISUAL_BLAST_2 = 53762,
    VISUAL_BLAST_3 = 53763,
    VISUAL_BLAST_4 = 53780,

    VISUAL_KIT_BLAST = 67693
};

enum eColor
{
    BLUE_MODE = 1,
    RED_MODE,
    GREEN_MODE
};

enum eText
{
    SAY_BLAST = 0,
    SAY_SHOCKWAVE = 1,

    EVENT_1,
    EVENT_2,
    EVENT_3,

    ACTION_1,
    ACTION_2,
};

//102263
struct boss_skorpyron : BossAI
{
    explicit boss_skorpyron(Creature* creature) : BossAI(creature, DATA_SKORPYRON), colorMod(0), healthPctMythic(0), dmgCounter(0)
    {
        healthLimit = me->GetMaxHealth() * 0.025;
        _introDone1 = false;
        _introDone2 = false;
        me->m_SightDistance = 130.0f;
    }

    uint8 colorMod;
    uint8 healthPctMythic;
    uint32 dmgCounter;
    uint64 healthLimit;

    bool _introDone1, _introDone2;

    void Reset() override
    {
        _Reset();
        me->SetReactState(REACT_AGGRESSIVE);
        me->SetPower(POWER_ENERGY, 0);
        dmgCounter = 0;
        healthPctMythic = 91;
        colorMod = BLUE_MODE;
    }

    void JustEngagedWith(Unit* /*who*/) override //37:22
    {
        _JustEngagedWith();
        DoCast(me, SPELL_ENERGIZE, true);
        DoCast(me, SPELL_EXOSKELETON, true);
        CallScorpions(true, 0);

        events.RescheduleEvent(EVENT_FOCUSED_BLAST, 13000);
        events.RescheduleEvent(EVENT_CALL_SCORPID, 22000);
        events.RescheduleEvent(EVENT_ARCANOSLASH, 6000);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        RemoveAuras();

        if (Creature* talysra = me->GetMap()->GetCreature(instance->GetGuidData(NPC_TALYSRA)))
        {
            talysra->AI()->Talk(1);
            talysra->AI()->DoAction(ACTION_MOVE_AFTER_FIRST_BOSS);
        }
    }

    void EnterEvadeMode(EvadeReason w)
    {
        me->RemoveAllAuras();
        RemoveAuras();
        BossAI::EnterEvadeMode();
    }

    void RemoveAuras()
    {
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_ARCANE_TETHER_AURA);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_ACIDIC_FRAGMENTS_AURA);
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (who->GetTypeId() == TYPEID_PLAYER && !_introDone1 && me->IsWithinDistInMap(who, 130.0f))
        {
            _introDone1 = true;
            if (Creature* talysra = me->GetMap()->GetCreature(instance->GetGuidData(NPC_TALYSRA)))
                talysra->AI()->DoAction(ACTION_MOVE_FIRST_POINT);
        }
        if (who->GetTypeId() == TYPEID_PLAYER && !_introDone2 && me->IsWithinDistInMap(who, 60.0f))
        {
            _introDone2 = true;
            if (Creature* talysra = me->GetMap()->GetCreature(instance->GetGuidData(NPC_TALYSRA)))
                talysra->AI()->DoAction(ACTION_MOVE_FIRST_BOSS);
        }

        if (me->GetVictim())
            return;

        if (me->IsWithinDistInMap(who, 6.0f))
        {
            if (me->CanStartAttack(who, false))
                AttackStart(who);
        }
    }

    void SetData(uint32 type, uint32 data) override
    {
        if (type == DATA_SKORPYRON_PATH)
            CallScorpions(false, data);
    }

    void CallScorpions(bool all, uint32 path)
    {
        uint32 entry = 0;

        if (all)
        {
            for (uint8 i = 0; i < 32; i++)
            {
                if (IsHeroicPlusRaid() && (i == 0 || i == 8 || i == 16 || i == 24))
                    entry = NPC_VOLATILE_SCORPID;
                else if (IsMythicRaid() && (i == 4 || i == 12 || i == 20 || i == 28))
                    entry = NPC_ACIDMAW_SCORPID;
                else
                    entry = NPC_CRYSTALLINE_SCORPID;

                if (Creature* scrop = me->SummonCreature(entry, 121.33f + frand(-0.3f, 0.3f), 3418.02f + frand(-0.3f, 0.3f), -250.12f, 2.36f))
                {
                    scrop->GetMotionMaster()->MovePath(10226300 + i, false);
                    scrop->AI()->SetData(DATA_SKORPYRON_PATH, 10226300 + i);
                }
            }
        }
        else
        {
            if (IsHeroicPlusRaid() && (path == 10226300 || path == 10226308 || path == 10226316 || path == 10226324))
                entry = NPC_VOLATILE_SCORPID;
            else if (IsMythicRaid() && (path == 10226304 || path == 102263012 || path == 10226320 || path == 10226328))
                entry = NPC_ACIDMAW_SCORPID;
            else
                entry = NPC_CRYSTALLINE_SCORPID;

            if (me->IsAlive() && me->IsInCombat())
                if (Creature* scrop = me->SummonCreature(entry, 121.33f + frand(-0.3f, 0.3f), 3418.02f + frand(-0.3f, 0.3f), -250.12f, 2.36f))
                {
                    scrop->GetMotionMaster()->MovePath(path, false);
                    scrop->AI()->SetData(DATA_SKORPYRON_PATH, path);
                }
        }
    }

    void SpellHitTarget(Unit* target, const SpellInfo* spell) override
    {
        if (spell->Id == SPELL_FOCUSED_BLAST)
        {
            Talk(SAY_BLAST);
            me->SetFacingToObject(target);
            me->CastSpell(me, SPELL_FOCUSED_BLAST_AT, false);
            me->SetReactState(REACT_AGGRESSIVE);
        }

        if (spell->Id == SPELL_FRAGMENTS_FILTER)
        {
            Position pos;
            target->GetRandomNearPosition(6.0f);
            if (colorMod == RED_MODE)
                me->CastSpell(pos, SPELL_VOLATILE_FRAGMENTS, true);
            else if (colorMod == GREEN_MODE)
                me->CastSpell(pos, SPELL_ACIDIC_FRAGMENTS, true);
            else
                me->CastSpell(pos, SPELL_CRYSTALL_FRAGMENTS, true);
        }
    }

    void SpellFinishCast(const SpellInfo* spell)
    {
        if (spell->Id == SPELL_FOCUSED_BLAST_AT)
        {
            me->SendPlaySpellVisualKit(0, VISUAL_KIT_BLAST, 100);

            float z = me->GetPositionZ();
            float lineDistance = 2.5f;
            uint8 countLine = 24;
            uint8 countPointInLine = 2;
            Position firstPos;

            for (uint8 i = 1; i <= countLine; i++)
            {
                me->GetNearPosition(i * 2.5f, 0.0f);
                //SendVisual(firstPos.GetPositionX(), firstPos.GetPositionY(), firstPos.GetPositionZ(), i);

                for (uint8 j = 1; j <= countPointInLine; j++)
                {
                    float xLeft = firstPos.GetPositionX() + j * lineDistance * std::cos(me->GetOrientation() + 1.5f);
                    float yLeft = firstPos.GetPositionY() + j * lineDistance * std::sin(me->GetOrientation() + 1.5f);
                    Trinity::NormalizeMapCoord(xLeft);
                    Trinity::NormalizeMapCoord(yLeft);
                    //SendVisual(xLeft, yLeft, z, i);
                    float xRight = firstPos.GetPositionX() + j * lineDistance * std::cos(me->GetOrientation() - 1.5f);
                    float yRight = firstPos.GetPositionY() + j * lineDistance * std::sin(me->GetOrientation() - 1.5f);
                    Trinity::NormalizeMapCoord(xRight);
                    Trinity::NormalizeMapCoord(yRight);
                    //SendVisual(xRight, yRight, z, i);
                }
            }
        }

        if (spell->Id == SPELL_SHOCKWAVE)
        {
            summons.DespawnEntry(NPC_CRYSTALLINE_SHARD);
            if (IsMythicRaid())
            {
                EntryCheckPredicate pred(NPC_VOLATILE_SHARD);
                summons.DoAction(true, pred); //Explosion cast
                summons.DespawnEntry(NPC_ACIDIC_SHARD);
                DoCast(me, SPELL_REMOVE_ACIDIC, true);
            }
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage)
    {
        if (IsMythicRaid() && me->HealthBelowPct(healthPctMythic))
        {
            switch (healthPctMythic)
            {
            case 91: //Red
            case 61: //Red
            case 31: //Red
                me->RemoveAurasDueToSpell(SPELL_BLUE_TRANSFORM);
                DoCast(me, SPELL_RED_TRANSFORM, true);
                colorMod = RED_MODE;
                break;
            case 81: //Green
            case 51: //Green
            case 21: //Green
                summons.DespawnEntry(NPC_VOLATILE_SHARD);
                me->RemoveAurasDueToSpell(SPELL_RED_TRANSFORM);
                DoCast(me, SPELL_GREEN_TRANSFORM, true);
                colorMod = GREEN_MODE;
                break;
            default: //blue
                me->RemoveAurasDueToSpell(SPELL_GREEN_TRANSFORM);
                DoCast(me, SPELL_BLUE_TRANSFORM, true);
                colorMod = BLUE_MODE;
                break;
            }
            healthPctMythic -= 10;
        }

        if (me->HasAura(SPELL_EXOSKELETON))
        {
            //Fragment events
            dmgCounter += damage;

            if (dmgCounter >= healthLimit)
            {
                dmgCounter = 0;
                DoCast(me, SPELL_FRAGMENTS_FILTER, true);
            }
        }
    }

    void DoAction(int32 const action) override
    {
        if (action == ACTION_1)
        {
            me->RemoveAurasDueToSpell(SPELL_ARCANOSLASH_DUMMY);
            events.RescheduleEvent(EVENT_VULNERABILITY, 100);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING | UNIT_STATE_STUNNED))
            return;

 

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_FOCUSED_BLAST:
                events.DelayEvents(1000);
                me->RemoveAurasDueToSpell(SPELL_ARCANOSLASH_DUMMY);
                me->AttackStop();
                DoCast(me, SPELL_FOCUSED_BLAST, true);
                events.RescheduleEvent(EVENT_FOCUSED_BLAST, 33000);
                break;
            case EVENT_CALL_SCORPID:
                DoCast(me, SPELL_CALL_SCORPID, true);
                events.RescheduleEvent(EVENT_CALL_SCORPID, 20000);
                break;
            case EVENT_VULNERABILITY:
                DoCast(SPELL_EXOSKELETAL_VULNERABILITY);
                break;
            case EVENT_ARCANOSLASH:
                DoCast(me, SPELL_ARCANOSLASH_DUMMY, true);
                events.RescheduleEvent(EVENT_ARCANOSLASH, 10000);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

//103217, 103224, 103225
struct npc_skorpyron_generic_scorp : public ScriptedAI
{
    explicit npc_skorpyron_generic_scorp(Creature* creature) : ScriptedAI(creature), dataPath(0), active(false)
    {
        me->SetReactState(REACT_PASSIVE);
        me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_NPC);
        me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
    }

    EventMap events;
    bool active = false;
    uint16 checkNearPlayersTimer = 0;
    uint32 dataPath = 0;

    void Reset() override {}

    void IsSummonedBy(Unit* summoner) override
    {
        active = false;
        checkNearPlayersTimer = urand(1000, 3000);
        DoCast(me, SPELL_SHROUDED, true);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        switch (me->GetEntry())
        {
        case NPC_CRYSTALLINE_SCORPID:
            events.RescheduleEvent(EVENT_1, 5000);
            break;
        case NPC_VOLATILE_SCORPID:
            DoCast(me, SPELL_VOLATILE_CHITIN_VIS, true);
            DoCast(me, SPELL_SCORPID_SWARM_AT, true);
            break;
        case NPC_ACIDMAW_SCORPID:
            events.RescheduleEvent(EVENT_3, 6000);
            break;
        }
        events.RescheduleEvent(EVENT_2, 12000);
    }

    void JustDied(Unit* /*killer*/) override
    {
        switch (me->GetEntry())
        {
        case NPC_VOLATILE_SCORPID:
            DoCast(me, SPELL_VOLATILE_CHITIN_DMG, true);
            break;
        case NPC_ACIDMAW_SCORPID:
            if (Unit* owner = me->GetOwner())
                me->CastSpell(me, SPELL_TOXIC_CHITIN_AT, true);
            break;
        }
    }

    void LastWPReached()
    {
        switch (dataPath)
        {
        case 10226300:
        case 10226304:
        case 10226308:
        case 10226312:
        case 10226316:
        case 10226320:
        case 10226324:
            DoCast(me, SPELL_AVAILABLE, true);
            break;
        }
    }

    void SetData(uint32 type, uint32 data) override
    {
        if (type == DATA_SKORPYRON_PATH)
            dataPath = data;
    }

    void SpellHit(Unit* caster, const SpellInfo* spell) override
    {
        if (spell->Id == 210172)
            ScorpActive();
    }

    void DoAction(int32 const action) override
    {
        if (action == ACTION_1 && !active)
        {
            active = true;

            if (Creature* owner = me->GetOwner()->ToCreature())
                owner->AI()->SetData(DATA_SKORPYRON_PATH, dataPath);

            DoCast(me, SPELL_BURROW, true);
            //>>>Hack
            me->AddUnitState(UNIT_STATE_STUNNED);
            if (me && me->IsAlive())
                me->ClearUnitState(UNIT_STATE_STUNNED);
            //<<<Hack
            me->RemoveAurasDueToSpell(SPELL_SHROUDED);
            me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
            me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
            me->SetReactState(REACT_AGGRESSIVE);
            DoZoneInCombat(me, 100.0f);
        }
    }

    void ScorpActive()
    {
        checkNearPlayersTimer = 0;
        me->RemoveAurasDueToSpell(SPELL_AVAILABLE);

        std::list<Creature*> creatureList;
        me->GetCreatureListWithEntryInGrid(creatureList, NPC_VOLATILE_SCORPID, 15.0f);
        me->GetCreatureListWithEntryInGrid(creatureList, NPC_ACIDMAW_SCORPID, 15.0f);
        me->GetCreatureListWithEntryInGrid(creatureList, NPC_CRYSTALLINE_SCORPID, 15.0f);

        if (creatureList.size() > 5)
        {
            creatureList.resize(5);
        }

        for (auto const& scorp : creatureList)
            scorp->AI()->DoAction(ACTION_1);
    }

    void UpdateAI(uint32 diff) override
    {
        if (checkNearPlayersTimer)
        {
            if (checkNearPlayersTimer <= diff)
            {
                checkNearPlayersTimer = 1000;

                if (!active)
                {
                    if (me->SelectNearestPlayer(5.0f))
                        ScorpActive();
                }
            }
            else
                checkNearPlayersTimer -= diff;
        }

        if (!UpdateVictim() || !active)
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_1:
                DoCastVictim(SPELL_ENERGY_SURGE);
                events.RescheduleEvent(EVENT_1, 5000);
                break;
            case EVENT_2:
                DoCast(me, SPELL_BOON_SCORPID, true);
                events.RescheduleEvent(EVENT_2, 10000);
                break;
            case EVENT_3:
                if (Unit* owner = me->GetOwner())
                    me->CastSpell(me, SPELL_TOXIC_CHITIN, true);
                events.RescheduleEvent(EVENT_3, 10000);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

//103209, 108132, 108131
struct npc_skorpyron_crystalline_fragments : public Scripted_NoMovementAI
{
    explicit npc_skorpyron_crystalline_fragments(Creature* creature) : Scripted_NoMovementAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void Reset() override {}

    void IsSummonedBy(Unit* summoner) override
    {
        DoCast(me, SPELL_LOS_BLOCKER, true);

        switch (me->GetEntry())
        {
        case NPC_CRYSTALLINE_SHARD:
            DoCast(me, SPELL_CRYSTALL_FRAGMENTS_AT, true);
            break;
        case NPC_VOLATILE_SHARD:
            DoCast(me, SPELL_VOLATILE_FRAGMENTS_AT, true);
            break;
        case NPC_ACIDIC_SHARD:
            DoCast(me, SPELL_ACIDIC_FRAGMENTS_AT, true);
            DoCast(me, SPELL_ACIDIC_FRAGMENTS_AURA, true);
            break;
        }
    }

    void DoAction(int32 const action) override
    {
        if (action == ACTION_1)
        {
            DoCast(SPELL_VOLATILE_RESONANCE);
        }
    }

    void UpdateAI(uint32 diff) override {}
};

//103682
struct npc_skorpyron_arcane_tether : public Scripted_NoMovementAI
{
    explicit npc_skorpyron_arcane_tether(Creature* creature) : Scripted_NoMovementAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
        instance = me->GetInstanceScript();
    }

    InstanceScript* instance;
    EventMap events;
    bool despawn = false;
    bool applyAura = false;

    void Reset() override {}

    void IsSummonedBy(Unit* summoner) override
    {
        despawn = false;
        applyAura = false;
        DoCast(me, 204373, true);
        events.RescheduleEvent(EVENT_1, 1000);
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_1:
                if (instance->GetBossState(DATA_SKORPYRON) != IN_PROGRESS)
                    despawn = true;
                if (Unit* owner = me->GetOwner())
                {
                    if (applyAura && owner->GetDistance(me) > 10.0f)
                    {
                        if (Aura* aura = owner->GetAura(SPELL_ARCANE_TETHER_AURA))
                        {
                            aura->ModStackAmount(-1);
                            applyAura = false;
                        }
                        if (IsMythicRaid())
                            events.RescheduleEvent(EVENT_2, 15000);
                        else
                            despawn = true;
                    }
                    else if (!applyAura && owner->GetDistance(me) <= 10.0f)
                    {
                        applyAura = true;
                        owner->CastSpell(owner, SPELL_ARCANE_TETHER_AURA, true);
                        if (IsMythicRaid())
                            events.CancelEvent(EVENT_2);
                    }
                    if (despawn)
                    {
                        me->DespawnOrUnsummon(100);
                        break;
                    }
                }
                events.RescheduleEvent(EVENT_1, 1000);
                break;
            case EVENT_2:
                despawn = true;
                break;
            }
        }
    }
};

//204277
class spell_skorpyron_periodic_energize : public AuraScript
{
    PrepareAuraScript(spell_skorpyron_periodic_energize);

    uint8 powerCount = 0;
    uint8 counter = 0;

    void OnTick(AuraEffect const* aurEff)
    {
        Creature* caster = GetCaster()->ToCreature();
        if (!caster || !caster->IsInCombat())
            return;

        powerCount = caster->GetPower(POWER_ENERGY);

        if (powerCount < 100)
        {
            caster->SetPower(POWER_ENERGY, powerCount + (counter ? 2 : 1));
            counter < 4 ? counter++ : counter = 0;
        }
        else if (!caster->HasUnitState(UNIT_STATE_CASTING | UNIT_STATE_STUNNED))
        {
            caster->CastSpell(caster, SPELL_SHOCKWAVE);
            caster->AI()->Talk(SAY_SHOCKWAVE);
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_skorpyron_periodic_energize::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

//204448
class spell_skorpyron_chitinous_exoskeleton : public AuraScript
{
    PrepareAuraScript(spell_skorpyron_chitinous_exoskeleton);

    int8 stack = 0;
    uint8 healthPct = 100;
    uint8 healthLimit;
    uint16 m_checkTimer = 1000;

    void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        if (!GetCaster())
            return;

        if (Aura* aura = aurEff->GetBase())
            aura->SetStackAmount(GetSpellInfo()->GetEffect(EFFECT_1)->BasePoints);

        if (uint8(ceilf(GetCaster()->GetHealthPct())) > 74)
            healthLimit = 100;
        else if (uint8(ceilf(GetCaster()->GetHealthPct())) > 49)
            healthLimit = 75;
        else if (uint8(ceilf(GetCaster()->GetHealthPct())) > 24)
            healthLimit = 50;
        else if (uint8(ceilf(GetCaster()->GetHealthPct())) > 0)
            healthLimit = 25;

        if (healthLimit != 100)
            GetCaster()->CastSpell(GetCaster(), SPELL_INFUSED_EXOSKELETON, true);
    }

    void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        if (Creature* caster = GetCaster()->ToCreature())
            caster->AI()->DoAction(true);
    }

    void OnUpdate(AuraEffect const* aurEff)
    {

        Creature* caster = GetCaster()->ToCreature();
        if (!caster || !caster->IsInCombat())
            return;

        if (uint8(ceilf(caster->GetHealthPct())) < healthPct)
        {
            if (Aura* aura = aurEff->GetBase())
            {
                healthPct = uint8(ceilf(caster->GetHealthPct()));
                stack = 25 - (healthLimit - uint8(ceilf(caster->GetHealthPct())));

                if (stack > 0)
                    aura->SetStackAmount(stack);
                else
                    aurEff->GetBase()->Remove();
            }
        }

    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_skorpyron_chitinous_exoskeleton::OnApply, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectApplyFn(spell_skorpyron_chitinous_exoskeleton::OnRemove, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, AURA_EFFECT_HANDLE_REAL);
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_skorpyron_chitinous_exoskeleton::OnUpdate, EFFECT_1, SPELL_AURA_DUMMY);
    }
};

//204275
class spell_skorpyron_arcanoslash : public SpellScript
{
    PrepareSpellScript(spell_skorpyron_arcanoslash);

    void HandleOnHit()
    {
        if (!GetCaster() || !GetHitUnit())
            return;

        if (Player* player = GetHitUnit()->ToPlayer())
            player->CastSpell(player, SPELL_ARCANE_TETHER, true);
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_skorpyron_arcanoslash::HandleOnHit);
    }
};

//211659
class spell_skorpyron_arcane_tether : public SpellScript
{
    PrepareSpellScript(spell_skorpyron_arcane_tether);

    void HandleDamage(SpellEffIndex /*effIndex*/)
    {
        if (!GetHitUnit())
            return;

        if (Aura* aura = GetHitUnit()->GetAura(SPELL_ARCANE_TETHER_AURA))
        {
            if (aura->GetStackAmount() > 0)
                SetHitDamage(GetHitDamage() * aura->GetStackAmount());
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_skorpyron_arcane_tether::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

void AddSC_boss_skorpyron()
{
    RegisterCreatureAI(boss_skorpyron);
    RegisterCreatureAI(npc_skorpyron_generic_scorp);
    RegisterCreatureAI(npc_skorpyron_crystalline_fragments);
    RegisterCreatureAI(npc_skorpyron_arcane_tether);
    RegisterAuraScript(spell_skorpyron_periodic_energize);
    RegisterAuraScript(spell_skorpyron_chitinous_exoskeleton);
    RegisterSpellScript(spell_skorpyron_arcanoslash);
    RegisterSpellScript(spell_skorpyron_arcane_tether);
}
