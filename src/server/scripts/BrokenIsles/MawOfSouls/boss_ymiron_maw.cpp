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

#include "maw_of_souls.h"
#include "GameObject.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum Says
{
    SAY_INTRO = 0,
    SAY_INTRO_2 = 1,
    SAY_AGGRO = 2,
    SAY_SCREAMS = 3,
    SAY_WINDS = 4,
    SAY_BANE = 5,
    SAY_ARISE = 6,
    SAY_DEATH = 7,
};

enum Spells
{
    SPELL_ZERO_REGEN = 118357,
    SPELL_POWER = 167922,
    SPELL_KNEELING_VISUAL = 197227, //State
    SPELL_SOUL_SIPHON = 194665, //Hit Target NPC 102375
    SPELL_DARK_SLASH = 193211,
    SPELL_SCREAMS_OF_DEAD = 193364,
    SPELL_WINDS_OF_NORTHREND = 193977,
    SPELL_BANE = 193460,
    SPELL_BANE_AT = 193465,
    SPELL_BANE_DMG = 193513,
    SPELL_BANE_NOVA = 200194,
    SPELL_ARISE_FALLEN = 193566, //Heroic+
    SPELL_ARISE_FALLEN_SUM = 193594,

    //Trash
    SPELL_STATE = 196025,
    SPELL_INSTAKILL = 117624,

    SPELL_BREAK_CHAINS = 201375,

    SPELL_VIGOR = 203816, //Heroic+
    SPELL_MOD_SCALE = 123978,
};

enum eEvents
{
    EVENT_DARK_SLASH = 1,
    EVENT_SCREAMS_OF_DEAD = 2,
    EVENT_WINDS_OF_NORTHREND = 3,
    EVENT_BANE = 4,
    EVENT_ARISE_FALLEN = 5,
    EVENT_INTRO = 6,

    //Trash
    EVENT_TRASH_INTRO = 1,
    EVENT_TRASH_INTRO_2 = 2,
    EVENT_FRACTURE = 3,
    EVENT_BARBED = 4,
    EVENT_SWIRLING = 5,

    EVENT_1,
    EVENT_2,
};

enum eMisc
{
    DATA_ACHIEVEMENT = 0,
};

Position const trashPos[9] =
{
    {7390.38f, 7285.93f, 43.86f, 0.32f},
    {7381.98f, 7295.84f, 43.85f, 0.21f},
    {7393.05f, 7312.54f, 43.86f, 5.58f},
    {7387.01f, 7299.40f, 43.86f, 5.83f},
    {7393.36f, 7306.04f, 43.91f, 5.58f},
    {7384.61f, 7286.07f, 43.86f, 0.51f},
    {7386.75f, 7292.16f, 43.86f, 0.05f},
    {7386.51f, 7304.95f, 43.92f, 5.69f},
    {7360.30f, 7301.24f, 43.68f, 1.87f}
};

enum Actions
{
    ACTION_1 = 1,
    ACTION_2,
};

//96756
struct boss_ymiron_the_fallen_king : public BossAI
{
    boss_ymiron_the_fallen_king(Creature* creature) : BossAI(creature, DATA_YMIRON)
    {
        for (uint8 i = 0; i < 8; ++i)
            me->SummonCreature(NPC_RUNECARVER_INTRO, trashPos[i]);

        instance->instance->SummonCreature(NPC_SEACURSED_SLAVER, trashPos[8]);
    }

    bool intro = true;
    bool achievement = false;
    uint8 phase = 0;
    uint8 addskilled = 0;
    uint32 timer = 0;

    void Reset() override
    {
        _Reset();
        me->RemoveAurasDueToSpell(SPELL_POWER);
        DoCast(me, SPELL_ZERO_REGEN, true);
        me->SetMaxPower(POWER_MANA, 100);
        me->SetPower(POWER_MANA, 80);
        achievement = false;
        addskilled = 0;
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        Talk(SAY_AGGRO);
        _JustEngagedWith();
        DoCast(me, SPELL_POWER, true);
        events.RescheduleEvent(EVENT_SCREAMS_OF_DEAD, 6000);
        events.RescheduleEvent(EVENT_WINDS_OF_NORTHREND, 16000);
        events.RescheduleEvent(EVENT_BANE, 22000);
        me->SetWalk(false);
        me->RemoveAurasDueToSpell(SPELL_KNEELING_VISUAL);

        if (intro)
        {
            intro = false;
            phase = 7;
            me->SetHomePosition(7396.58f, 7276.02f, 43.79f, 2.3f);
            me->SetReactState(REACT_AGGRESSIVE);
            me->InterruptNonMeleeSpells(false);
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_DEATH);
        _JustDied();

        if (auto go = instance->instance->GetGameObject(instance->GetGuidData(DATA_YMIRON_GORN)))
            go->RemoveFlag(GO_FLAG_NOT_SELECTABLE);

        if (CheckAura())
        {
            instance->DoAddAuraOnPlayers(213441);
            instance->DoRemoveAurasDueToSpellOnPlayers(213407);
        }
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who || !who->IsPlayer() || who->ToPlayer()->IsGameMaster() || me->GetVictim())
            return;

        if (!timer && !phase && intro && who->IsPlayer() && me->GetDistance(who) < 60.0f)
        {
            me->SetReactState(REACT_DEFENSIVE);
            me->SetWalk(true);
            timer = 1000;
            return;
        }

        if (!intro)
            BossAI::MoveInLineOfSight(who);
    }

    void DoAction(int32 const action) override
    {
        if (action == ACTION_1)
            events.RescheduleEvent(EVENT_DARK_SLASH, 500);

        if (action == ACTION_2)
        {
            if (++addskilled == 6)
                achievement = true;
        }
    }

    uint32 GetData(uint32 type) const override
    {
        if (type == DATA_ACHIEVEMENT)
            return achievement;

        return 0;
    }

    bool CheckAura()
    {
        bool check = true;

        instance->DoOnPlayers([&](Player* player)
        {
            if (!player->HasAura(213407))
                check = false;
        });

        return check;
    }

    void UpdateAI(uint32 diff) override
    {
        if (timer && phase < 7)
        {
            switch (phase)
            {
            case 0:
                if (timer <= diff)
                {
                    ++phase;
                    timer = 5000;
                    me->GetMotionMaster()->MoveCharge(7406.41f, 7280.58f, 44.26f, 10.0f);
                }
                else timer -= diff;
                break;
            case 1:
                if (timer <= diff)
                {
                    ++phase;
                    timer = 5000;
                    me->GetMotionMaster()->MovePoint(0, 7408.16f, 7293.06f, 43.78f);
                }
                else timer -= diff;
                break;
            case 2:
                if (timer <= diff)
                {
                    ++phase;
                    timer = 5000;
                    me->GetMotionMaster()->MovePoint(0, 7397.77f, 7297.18f, 43.78f);
                }
                else timer -= diff;
                break;
            case 3:
                if (timer <= diff)
                {
                    ++phase;
                    timer = 10000;
                    DoCast(me, SPELL_SOUL_SIPHON, true);
                    Talk(SAY_INTRO);
                }
                else timer -= diff;
                break;
            case 4:
                if (timer <= diff)
                {
                    ++phase;
                    timer = 5000;
                    me->GetMotionMaster()->MovePoint(0, 7396.58f, 7276.02f, 43.79f);
                    Talk(SAY_INTRO_2);
                }
                else timer -= diff;
                break;
            case 5:
                if (timer <= diff)
                {
                    ++phase;
                    timer = 1000;
                    if (auto GO = me->FindNearestGameObject(247041, 30.0f))
                        me->SetFacingToObject(GO);
                    DoCast(SPELL_KNEELING_VISUAL);
                }
                else timer -= diff;
                break;
            case 6:
                if (timer <= diff)
                {
                    ++phase;
                    timer = 0;
                    intro = false;
                    me->SetHomePosition(me->GetPosition());
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->SetWalk(false);
                }
                else timer -= diff;
                break;
            }
        }

        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_DARK_SLASH:
                DoCastVictim(SPELL_DARK_SLASH);
                break;
            case EVENT_SCREAMS_OF_DEAD:
                DoCast(SPELL_SCREAMS_OF_DEAD);
                events.RescheduleEvent(EVENT_SCREAMS_OF_DEAD, 23000);
                Talk(SAY_SCREAMS);
                break;
            case EVENT_WINDS_OF_NORTHREND:
                Talk(SAY_WINDS);
                DoCast(SPELL_WINDS_OF_NORTHREND);
                events.RescheduleEvent(EVENT_WINDS_OF_NORTHREND, 24000);
                break;
            case EVENT_BANE:
                Talk(SAY_BANE);
                DoCast(SPELL_BANE);
                events.RescheduleEvent(EVENT_BANE, 50000);
                break;
            case EVENT_ARISE_FALLEN:
                Talk(SAY_ARISE);
                DoCast(SPELL_ARISE_FALLEN);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

//98246
struct npc_ymiron_risen_warrior : public ScriptedAI
{
    npc_ymiron_risen_warrior(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
    }

    EventMap events;

    void Reset() {}

    void IsSummonedBy(Unit* summoner)
    {
        me->GetScheduler().Schedule(1s, [this](TaskContext /*context*/)
        {
            if (me)
            {
                me->SendPlaySpellVisualKit(2000, 59548, 4);
                DoCast(me, SPELL_MOD_SCALE, true);
            }
        });

        me->GetScheduler().Schedule(3s, [this](TaskContext /*context*/)
        {
            if (me && me->IsAlive() && me->IsInCombat())
            {
                me->SetReactState(REACT_AGGRESSIVE);
                DoZoneInCombat(me, 100.0f);
            }
        });

        events.RescheduleEvent(EVENT_1, 5000);
    }

    void SpellHit(Unit* caster, const SpellInfo* spell) override
    {
        if (spell->Id == 195036)
        {
            if (auto owner = me->GetOwner())
                if (auto boss = owner->ToCreature())
                    boss->AI()->DoAction(ACTION_2);
        }
    }

    void DoAction(int32 const actionId)
    {
        if (me->IsAlive())
            me->Kill(me,me);
    }

    void UpdateAI(uint32 diff)
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_1:
                DoCast(me, SPELL_VIGOR, true);
                events.RescheduleEvent(EVENT_1, 6000);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

//97163
struct npc_ymiron_cursed_falke : public ScriptedAI
{
    npc_ymiron_cursed_falke(Creature* creature) : ScriptedAI(creature) {}

    bool flyEvent = false;

    void Reset()
    {
        if (me->GetDistance(7248.78f, 7287.24f, 25.57f) < 25.0f)
        {
            me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_NPC);
            me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
        }
        else
            flyEvent = true;
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        me->RemoveAurasDueToSpell(SPELL_STATE);
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (id == 1)
            me->DespawnOrUnsummon();
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who->IsPlayer() || who->ToPlayer()->IsGameMaster())
            return;

        if (!flyEvent && me->IsWithinDistInMap(who, 45.0f))
        {
            flyEvent = true;
            me->SetReactState(REACT_PASSIVE);
            me->RemoveAurasDueToSpell(SPELL_STATE);
            me->GetMotionMaster()->MovePoint(1, 7257.08f, 7081.54f, 26.41f);
            return;
        }
        ScriptedAI::MoveInLineOfSight(who);
    }
};

//97043
struct npc_ymiron_seacursed_slaver : public ScriptedAI
{
    npc_ymiron_seacursed_slaver(Creature* creature) : ScriptedAI(creature)
    {
        instance = me->GetInstanceScript();

        if (me->GetDistance(7272.66f, 7307.91f, 30.79f) < 1.0f)
        {
            trashIntro = true;
            if (auto shieldmaiden = me->SummonCreature(NPC_SHIELDMAIDEN, 7266.52f, 7283.81f, 27.31f, 1.75f))
            {
                shieldmaiden->SetReactState(REACT_PASSIVE);
                shieldmaiden->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_NPC);
                shieldmaiden->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
                shieldmaiden->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
                prisonerGUID = shieldmaiden->GetGUID();
            }
        }

        if (me->GetDistance(trashPos[8]) < 1.0f)
        {
            trashIntro = true;
            if (auto runecarver = me->SummonCreature(NPC_RUNECARVER, 7355.52f, 7315.79f, 48.0f, 4.29f))
            {
                runecarver->SetReactState(REACT_PASSIVE);
                runecarver->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_NPC);
                runecarver->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
                runecarver->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
                prisonerGUID = runecarver->GetGUID();
            }
        }
    }

    InstanceScript* instance;
    EventMap _events;
    bool trashIntro = false;
    ObjectGuid prisonerGUID;

    void Reset() override
    {
        _events.Reset();
        me->SetReactState(REACT_AGGRESSIVE);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.RescheduleEvent(EVENT_FRACTURE, 4000);
        //_events.RescheduleEvent(EVENT_BARBED, 6000); //Crash
        _events.RescheduleEvent(EVENT_SWIRLING, 15000);
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who || !who->IsPlayer() || who->ToPlayer()->IsGameMaster())
            return;

        if (trashIntro && me->IsWithinDistInMap(who, 25.0f))
        {
            trashIntro = false;

            if (auto prisoner = Creature::GetCreature(*me, prisonerGUID))
            {
                if (prisoner->IsAlive() && !prisoner->IsInCombat() && me->GetDistance(prisoner) < 30.0f)
                {
                    Talk(1);
                    me->AttackStop();
                    me->StopMoving();
                    me->SetFacingToObject(prisoner);
                    DoCast(prisoner, SPELL_BREAK_CHAINS, true);

                    me->GetScheduler().Schedule(2s, [this](TaskContext /*context*/)
                    {
                        if (me && me->IsAlive())
                        {
                            me->SetReactState(REACT_AGGRESSIVE);
                            me->AI()->DoZoneInCombat(me, 30.0f);
                        }

                    });

                    if (prisoner && prisoner->IsAlive() && !prisoner->IsInCombat())
                    {
                        if (auto go = prisoner->FindNearestGameObject(245064, 20.0f))
                            go->SetGoState(GO_STATE_ACTIVE);
                        prisoner->SetHomePosition(7265.72f, 7287.86f, 26.69f, 1.69f);
                        prisoner->GetMotionMaster()->MovePoint(1, 7265.72f, 7287.86f, 26.69f);
                        prisoner->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
                        prisoner->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                        prisoner->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                        prisoner->SetReactState(REACT_AGGRESSIVE);
                        prisoner->AI()->DoZoneInCombat(prisoner, 30.0f);
                    }

                    return;
                }
            }
        }
        ScriptedAI::MoveInLineOfSight(who);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_FRACTURE:
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                {
                    _events.DelayEvents(4000);
                    me->AttackStop();
                    me->SetReactState(REACT_AGGRESSIVE);
                    DoCast(target, 198752);
                }
                _events.RescheduleEvent(EVENT_FRACTURE, 16000);
                break;
            }
            case EVENT_BARBED:
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 10.0f, true))
                {
                    _events.DelayEvents(2000);
                    me->CastSpell(target, 191972, true);
                    me->CastSpell(target, 191960, true);
                    target->CastSpell(me, 191980, true);
                    me->CastSpell(me, 194674);
                    _events.RescheduleEvent(EVENT_BARBED, urandms(10, 12));
                }
                else
                    _events.RescheduleEvent(EVENT_BARBED, 1000);
                break;
            }
            case EVENT_SWIRLING:
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                {
                    _events.DelayEvents(2500);
                    me->AttackStop();
                    me->SetReactState(REACT_AGGRESSIVE);
                    DoCast(target, 201567);
                }
                _events.RescheduleEvent(EVENT_SWIRLING, 15000);
                break;
            }
            }
        }
        DoMeleeAttackIfReady();
    }
};

//97200
struct npc_mos_seacursed_soulkeeper : public ScriptedAI
{
    npc_mos_seacursed_soulkeeper(Creature* creature) : ScriptedAI(creature) {}

    EventMap events;

    void Reset() override
    {
        events.Reset();
        me->SetReactState(REACT_AGGRESSIVE);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        events.RescheduleEvent(EVENT_1, urandms(3, 4));
        events.RescheduleEvent(EVENT_2, urandms(9, 10));
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_1:
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                    DoCast(target, 200208);
                events.RescheduleEvent(EVENT_1, urandms(13, 15));
                break;
            case EVENT_2:
            {
                me->AttackStop();
                me->SetReactState(REACT_AGGRESSIVE);
                me->CastSpell(me, 195031);
                events.RescheduleEvent(EVENT_1, 8000);
                Talk(0);
                events.RescheduleEvent(EVENT_2, urandms(23, 25));
                break;
            }
            }
        }
        DoMeleeAttackIfReady();
    }
};

//102375
struct npc_mos_runecarver_slave : public ScriptedAI
{
    npc_mos_runecarver_slave(Creature* creature) : ScriptedAI(creature) {}

    EventMap events;

    void Reset() override
    {
        events.Reset();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        events.RescheduleEvent(EVENT_1, urandms(1, 2));
        events.RescheduleEvent(EVENT_2, urandms(9, 10));
    }

    void SpellHitTarget(Unit* target, const SpellInfo* spell) override
    {
        if (spell->Id == 202408)
        {
            Position pos;
            target->GetRandomNearPosition(5.0f);
            for (uint8 itr = 0; itr < 8; ++itr)
                me->CastSpell(pos, 199087, true);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_1:
                DoCastVictim(202365);
                events.RescheduleEvent(EVENT_1, urandms(9, 10));
                break;
            case EVENT_2:
                DoCast(202408);
                events.RescheduleEvent(EVENT_2, urandms(9, 11));
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

//167922
class spell_ymiron_power_regen : public AuraScript
{
    PrepareAuraScript(spell_ymiron_power_regen);

        uint8 powerCounter = 0;

    void OnPeriodic(AuraEffect const* aurEff)
    {
        if (auto ymiron = GetCaster()->ToCreature())
        {
            uint8 power = ymiron->GetPower(POWER_MANA);

            if (power < 100)
            {
                if (powerCounter < 2)
                {
                    powerCounter++;
                    ymiron->SetPower(POWER_MANA, power + 7);
                }
                else
                {
                    powerCounter = 0;
                    ymiron->SetPower(POWER_MANA, power + 6);
                }
            }
            else
            {
                ymiron->SetPower(POWER_MANA, 0);
                ymiron->AI()->DoAction(ACTION_1); //EVENT_DARK_SLASH
            }
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_ymiron_power_regen::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

//193460
class spell_ymiron_bane : public AuraScript
{
    PrepareAuraScript(spell_ymiron_bane);

        void OnPereodic(AuraEffect const* aurEff)
    {
        PreventDefaultAction();

        if (!GetCaster())
            return;

        Position pos;

        if (aurEff->GetTickNumber() == 1)
        {
            for (int8 i = 0; i < 4; ++i)
            {
                GetCaster()->GetNearPosition(frand(20.0f, 40.0f), frand(0.0f, 6.28f));
                GetCaster()->CastSpell(pos, GetSpellInfo()->GetEffect(EFFECT_0)->TriggerSpell, true);
            }
        }
        else
        {
            GetCaster()->GetNearPosition(frand(20.0f, 40.0f), frand(0.0f, 6.28f));
            GetCaster()->CastSpell(pos, GetSpellInfo()->GetEffect(EFFECT_0)->TriggerSpell, true);
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_ymiron_bane::OnPereodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

//191560
class spell_ymiron_helheim_teleport : public SpellScript
{
    PrepareSpellScript(spell_ymiron_helheim_teleport);

    void HandleOnHit()
    {
        if (auto player = GetHitUnit()->ToPlayer())
        {
            player->TeleportTo(1492, 2931.86f, 870.70f, 517.5f, 4.73f);

            if (player->GetMap()->GetDifficultyID() != DIFFICULTY_MYTHIC_KEYSTONE)
                player->CastSpell(player, 191559, false);
        }
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_ymiron_helheim_teleport::HandleOnHit);
    }
};

//194640
class spell_mos_curse_of_hope : public AuraScript
{
    PrepareAuraScript(spell_mos_curse_of_hope);

    void OnPereodic(AuraEffect const* aurEff)
    {
        if (!GetCaster())
            return;

        if (auto _aurEff = GetAura()->GetEffect(EFFECT_0))
            _aurEff->ChangeAmount(100 - GetCaster()->GetHealthPct());
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_mos_curse_of_hope::OnPereodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
    }
};

//195031
class spell_mos_defiant_strike : public AuraScript
{
    PrepareAuraScript(spell_mos_defiant_strike);

        bool cast = true;

    void OnPereodic(AuraEffect const* aurEff)
    {
        if (!GetCaster())
            return;

        if (cast)
        {
            GetCaster()->CastSpell(GetCaster(), 195033, true);
            GetCaster()->CastSpell(GetCaster(), 195035, true);
            GetCaster()->CastSpell(GetCaster(), 195038, true);
            GetCaster()->CastSpell(GetCaster(), 195036, false);
            cast = false;
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_mos_defiant_strike::OnPereodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
    }
};

//29680
class achievement_instant_karma : public AchievementCriteriaScript
{
public:
    achievement_instant_karma() : AchievementCriteriaScript("achievement_instant_karma") { }

    bool OnCheck(Player* /*player*/, Unit* target) override
    {
        if (!target)
            return false;

        if (auto boss = target->ToCreature())
            if (boss->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC || boss->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC_KEYSTONE)
                if (boss->GetAI()->GetData(DATA_ACHIEVEMENT))
                    return true;

        return false;
    }
};

void AddSC_boss_ymiron_maw()
{
    RegisterCreatureAI(boss_ymiron_the_fallen_king);
    RegisterCreatureAI(npc_ymiron_risen_warrior);
    RegisterCreatureAI(npc_ymiron_cursed_falke);
    RegisterCreatureAI(npc_ymiron_seacursed_slaver);
    RegisterCreatureAI(npc_mos_seacursed_soulkeeper);
    RegisterCreatureAI(npc_mos_runecarver_slave);
    RegisterAuraScript(spell_ymiron_power_regen);
    RegisterAuraScript(spell_ymiron_bane);
    RegisterSpellScript(spell_ymiron_helheim_teleport);
    RegisterAuraScript(spell_mos_curse_of_hope);
    RegisterAuraScript(spell_mos_defiant_strike);
    new achievement_instant_karma();
}
