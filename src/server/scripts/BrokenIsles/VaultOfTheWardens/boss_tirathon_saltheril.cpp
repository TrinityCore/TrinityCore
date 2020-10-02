/*
* Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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
#include "vault_of_the_wardens.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"


/*
 TODO: Still in progress.
 Missing sniff for part 2 of boss when he casting other form and some other spells in that form, Vegenance?
 Swoop-> Knockback/Damage everyone in his path from jump.
 Swoop->Throwing his weapons away?
 Swoop->Recalling his weapons after 5s~
 Hatred->Have to igure out how to make spell work, he summuning some npc and should cast on him that laser?
 Hatred->But there is not any waypoint of that npc in sniff?
 Script Polishing
*/
enum SpellEvents
{
    EVENT_NONE = 0,
    EVENT_FEL_MORTAR = 1,
    EVENT_DARKSTRIKE = 2,
    EVENT_SWOOP = 3,
    EVENT_GLAIVE = 4,
    EVENT_METAMORPHOSIS = 5,
    EVENT_HATRED = 6,
    EVENT_HATRED_CASTING = 7,
    EVENT_SUMMON_FEL_FURY = 8,
    EVENT_FEL_FURY_SCORCH = 9,
    EVENT_FEL_FURY_FEL_EMISSION = 10,

};
enum Spells
{
    SPELL_INTRO_JUMP = 199132,

     SPELL_DRELANIM_WHISPERWIND_KNEEL = 194836,

    //Enter Combat 14:56:43.523
    //MainHand/Offhand = 191949
    //MainHand/Offhand = 191948
    //TODO: Boss need to Attack with Both weapons and to use his weapons 
    SPELL_DARKSTRIKES = 191941,
    SPELL_FEL_MORTAR = 202913,
    SPELL_FEL_MORTAR_TRIGGER = 202920,


    // 14:56:56.852
    //191774 knockback effect casted by player so basically player knocking himself?
    SPELL_SWOOP_KNOCK_BACK = 191774, //Casted by a player knockback?
    SPELL_SWOOP_DUMMY = 191765, //dummy
    SPELL_SWOOP_JUMP = 191766, //Jump
    SPELL_SWOOP_DAMAGE = 191767,//Damage & knockback everyone in path from jump to destination.

    //Aura Update 14:56:53.585
    //ID - 191999 Dark Energies
    SPELL_DARK_ENERGIES = 191999,

    // 14:56:56.853 Number: 39408
    // ID - 211057 Throw Glaive
    // Swoop 191765 triggering
    // 14:56:56.877 Number: 39412
    SPELL_THROW_GLAIVE_MAIN_HAND = 211057,
    SPELL_THROW_GLAIVE_OFF_HAND = 211058,

    // ID - 192108 Glaive Damage
    // 14:56:56.964 Number: 39424 again swoop
    SPELL_GLAIVE = 192108, 

    //ID - 211068 Recall Glaive
    //Time : 14:57:01.983
    SPELL_RECALL_GLAIVE = 211068,

    // ID - 191823 Furious Blast
    // 14:56:56.991 Number: 39436
    SPELL_FURIOUS_BLAST = 191823,

    //ID - 191853 Furious Flames
    //14:57:00.983
    SPELL_FURIOUS_FLAMES = 191853,

    //14:57:07.781
    //ID - 192504 Metamorphosis
    SPELL_METAMORPHOSIS = 192504,

    // ID - 212558 Summon Fel Fury
    //4264.336 Y: -431.36285 Z: 259.4851 location
    //4267.597 Y: -433.0495 Z: 259.57462
    // X: 4284.3716 Y: -441.7253 Z: 259.60638 second?>
    /*
        [0] Points: X: 4244.3003 Y: -421.0004 Z: 259.53052
        [1] Points: X: 4264.336 Y: -431.36285 Z: 259.56845
        [2] Points: X: 4284.3716 Y: -441.7253 Z: 259.60638
        [3] Points: X: 4284.3716 Y: -441.7253 Z: 259.60638
    */
    SPELL_SUMMON_FELL_FURY = 212558,
    SPELL_SCORCH = 212541,
    SPELL_SELF_DESTRUCTION = 212551,
    SPELL_FEL_EMISSION = 212547,

    // ID - 202780 Summon Laser Beam Target
    SPELL_LASER_BEAM = 202780,

    //14:57:25.567 
    //ID - 190830 Hatred First Target Himself ?
    //ID - 190833 Hatred Target Summuned NPC?
    //Entry: 96241
    SPELL_HATRED = 190830, //SELF TARGET
    SPELL_HATRED_TARGET = 190833, //UNIT LASER?
    SPELL_HATRED_DAMAGE = 190836, //Damage if u get in AT
    //SpellID: 202780 (Summon Laser Beam Target)
    SPELL_SUMMON_LASER_BEAM_TARGET = 202780,
    //BONUS ROLL 226649
};
enum Talk
{
    TALK_ENTER_COMBAT = 0,
    TALK_EMPOWER_DARKSTRIKE = 1,
    TALK_EMPOWER_DARKSTRIKE_HIT = 2,
    //icon + Text: I will cast you all aside...
    TALK_FURIOUS_BLAST_TO_PLAYER = 3,
    TALK_FURIOUS_BLAST = 4,
    //Text: Anger, hate, rage! These will fuel me with the power I crave!
    TALK_METAMORPHOSIS = 6,
    TALK_DEATH = 8,
};
enum Data
{
    DATA_JUMP = 1
};

enum Actions
{
    ACTION_METAMORPHOSIS = 1,
    ACTION_SUMMON_FEL_FURY = 2,
};
const Position jumpPos = { 4284.973, -451.2752, 259.66946, 3.123 };
const Position spawnFury[4] = {
    { 4244.3003, -421.0004,  259.53052},
    { 4264.336,  -431.36285, 259.56845},
    { 4284.3716, -441.7253 , 259.60638},
    { 4284.3716, -441.7253 , 259.60638},
};
//After boss jump he need to jump on his position
//So some set/get things, didn't figure out
struct npc_drelanim_whisperwind : public ScriptedAI
{
    npc_drelanim_whisperwind(Creature* creature) : ScriptedAI(creature)
    {

    }
    void SetData(uint32 type, uint32 data) override
    {
        UnitAI::SetData(type, data);
        if (type == DATA_JUMP && data == 0)
        {
            me->GetMotionMaster()->MoveJump(jumpLoc, 20, 0);
            me->CastSpell(nullptr, SPELL_DRELANIM_WHISPERWIND_KNEEL);
        }
    }
    const Position jumpLoc = { 4229.3887,-449.48373, 266.80066, 3.123 };
};
struct boss_tirathon_saltheril: public BossAI
{
    boss_tirathon_saltheril(Creature* creature) : BossAI(creature, 0)
    {
        Init();
    }
    void Init()
    {

        me->SetCanDualWield(true);
    }
    void Reset()override
    {
        me->RemoveAreaTrigger(SPELL_FURIOUS_BLAST);
        me->RemoveAreaTrigger(SPELL_THROW_GLAIVE_MAIN_HAND);
        me->RemoveAreaTrigger(SPELL_FEL_MORTAR_TRIGGER);
        me->SetHomePosition(jumpPos);
        _Reset();
        m_casted = false;
    }
    void JustDied(Unit* /*killer*/) override
    {
        Talk(TALK_DEATH);
        me->SetHomePosition(jumpPos);
    }
    void MoveInLineOfSight(Unit* who) override
    {
       if (Player* target = GetPlayerAtMinimumRange(65))
           if (!me->IsInCombat() && !m_jumped)
           {
               DoCastSelf(SPELL_INTRO_JUMP);
               SetData(DATA_JUMP, 0);
               m_jumped = true;
               //Some of this Flags making boss to jump to his position?
               //So script LoS is not required ?
               me->SetUnitFlags(UnitFlags(UNIT_FLAG_UNK_6 | UNIT_FLAG_PET_IN_COMBAT | UNIT_FLAG_UNK_15 | UNIT_FLAG_IN_COMBAT));
           }
       if (me->HasReactState(REACT_AGGRESSIVE) && me->CanStartAttack(who, false))
           me->EngageWithTarget(who);
    }
    void DoAction(const int32 action)override
    {
        if (action == ACTION_METAMORPHOSIS && !m_casted)
        {
            DoCast(SPELL_METAMORPHOSIS);
            Talk(TALK_METAMORPHOSIS);
            m_casted = true;
        }
    }
    void EnterCombat(Unit* /*who*/)override
    {
        Talk(TALK_ENTER_COMBAT);
        me->SetReactState(REACT_AGGRESSIVE);
        _EnterCombat();
    }
    void ScheduleTasks() override
    {
          events.ScheduleEvent(EVENT_FEL_MORTAR, Milliseconds(4000), Milliseconds(6000), 0, 0);
          events.ScheduleEvent(EVENT_DARKSTRIKE, Milliseconds(10000), Milliseconds(14000), 0, 0);
          events.ScheduleEvent(EVENT_SWOOP, Milliseconds(20000), Milliseconds(24000), 0, 0);
          events.ScheduleEvent(EVENT_METAMORPHOSIS, Milliseconds(75000), Milliseconds(80000), 1, 0);
       // events.ScheduleEvent(EVENT_SUMMON_FEL_FURY, Milliseconds(60000), Milliseconds(65000), 1, 0);
    }
    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

      
        switch (events.ExecuteEvent())
        {
        case EVENT_FEL_MORTAR:
            DoCast(SPELL_FEL_MORTAR);
            events.Repeat(25s);
            break;
        case EVENT_DARKSTRIKE:
            DoCast(SPELL_DARKSTRIKES);
            Talk(TALK_EMPOWER_DARKSTRIKE, me->GetVictim());
            Talk(TALK_EMPOWER_DARKSTRIKE_HIT);
            events.Repeat(30s);
            break;
        case EVENT_SWOOP:
            DoCast(SPELL_SWOOP_DUMMY);
            Talk(TALK_FURIOUS_BLAST);
            Talk(TALK_FURIOUS_BLAST_TO_PLAYER,me->GetVictim());
            events.Repeat(40s);
            events.ScheduleEvent(EVENT_GLAIVE, Milliseconds(3000), Milliseconds(5000), 0, 0);
            break;
        case EVENT_GLAIVE:
            DoCast(SPELL_RECALL_GLAIVE);
            events.CancelEvent(EVENT_GLAIVE);
            break;
        case EVENT_METAMORPHOSIS:
            if (!m_casted)
            {
                DoCast(SPELL_METAMORPHOSIS);
                Talk(TALK_METAMORPHOSIS);
                m_casted = true;
            }
            events.CancelEvent(EVENT_METAMORPHOSIS);
            events.ScheduleEvent(EVENT_SUMMON_FEL_FURY, Milliseconds(5000), Milliseconds(8000));
            events.ScheduleEvent(EVENT_HATRED, Milliseconds(40000), Milliseconds(45000), 1, 0);
            events.SetPhase(1);
            me->PlayDirectSound(55409);
            break;
        case EVENT_SUMMON_FEL_FURY:
            if (m_ctr--)
            {
                me->SummonCreature(107101, spawnFury[urand(0,3)]);
                me->SummonCreature(107101, spawnFury[urand(1,2)]);
                events.Repeat(25s);
            }
            else
            {
                events.CancelEvent(EVENT_SUMMON_FEL_FURY);
            }
            break;
        case EVENT_HATRED:
            if (Unit* target= SelectTarget(SELECT_TARGET_RANDOM))
            {
                const SpellCastTargets spltarg();
                me->CastSpell(target, SPELL_SUMMON_LASER_BEAM_TARGET);
                DoCastSelf(SPELL_HATRED);
            }
            events.Repeat(45s);
            events.ScheduleEvent(EVENT_HATRED_CASTING, 2s);
            break;
        case EVENT_HATRED_CASTING:
            DoCastSelf(SPELL_HATRED_TARGET);
            events.CancelEvent(EVENT_HATRED_CASTING);
            break;
        }
        if (me->HealthBelowPct(50))
        {
            DoAction(ACTION_METAMORPHOSIS);
        }
        DoMeleeAttackIfReady();
    }
private:
    bool m_jumped = false;
    bool m_casted = false;
    int8 m_ctr = 5;
};
//107101
struct npc_fel_fury : public ScriptedAI
{
    npc_fel_fury(Creature* creature) : ScriptedAI(creature)
    {
        Init();
    }
    void Init()
    {
        me->SetFaction(16);
    }
    void EnterCombat(Unit* /*victim*/) override
    {
        m_Events.ScheduleEvent(EVENT_FEL_FURY_SCORCH, Milliseconds(4000), (6000));
        m_Events.ScheduleEvent(EVENT_FEL_FURY_FEL_EMISSION,Milliseconds(10000),(12000));
    }
    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        m_Events.Update(diff);
        switch (m_Events.ExecuteEvent())
        {
        case EVENT_FEL_FURY_SCORCH:
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
            {
                me->CastSpell(target, SPELL_SCORCH);
            }
            m_Events.ScheduleEvent(EVENT_FEL_FURY_SCORCH, Milliseconds(6000), (9000));
            break;
        case EVENT_FEL_FURY_FEL_EMISSION:
            DoCast(SPELL_FEL_EMISSION);
            m_Events.Repeat(Seconds(urand(16, 20)));
            break;
        default:
            break;
        }
        if (me->GetAuraCount(SPELL_SCORCH) >= 10)
        {
          DoCast(SPELL_SELF_DESTRUCTION);
        }
        DoMeleeAttackIfReady();
    }
    void JustDied(Unit* /*killer*/) override
    {
        me->DespawnOrUnsummon(10000);
    }
    EventMap m_Events;
    int16 m_ctrSpell;
};


//ID - 191948 & 191949  Darkstrike
class spell_dark_strikes : public SpellScript
{
    PrepareSpellScript(spell_dark_strikes);

  
    void OnHitCheck()
    {
        if (!GetCaster())
            return;
        //if target don't have some of this auras, boss getting shield
        //TODO: Need to check right auras. (Active Mitigation Spells)
        if (Unit* target = GetCaster()->GetVictim())
        {
            if (target->HasAura(192081) || target->HasAura(132404) || target->HasAura(115308) || target->HasAura(53600) || target->HasAura(77513) || target->HasAura(49998) || target->HasAura(2565) || target->HasAura(203720))
                return;
            else
            {
                CustomSpellValues custom;
                custom.AddSpellMod(SPELLVALUE_BASE_POINT0, GetHitDamage() / 1.1);
                GetCaster()->CastCustomSpell(SPELL_DARK_ENERGIES, custom, GetCaster());
            }
        }
                   
    }
    void Register() override
    {
        OnHit += SpellHitFn(spell_dark_strikes::OnHitCheck);
    }
    
};

// ID - 191765 Swoop
class spell_swoop: public SpellScript
{
     PrepareSpellScript(spell_swoop);


        void HandleCast(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetCaster()->GetAI()->SelectTarget(SELECT_TARGET_RANDOM);
            if (!caster || !target)
                return;
            //Jumping to the target 
            caster->CastSpell(target, SPELL_SWOOP_JUMP, true);

            //Wait until boss get player position so he can cast Furious Blast
            //TODO: Implement This to cast only after he land/reach position
            caster->CastSpell(nullptr, SPELL_FURIOUS_BLAST);

            //AT : 9596 9595
            caster->CastSpell(target, SPELL_THROW_GLAIVE_MAIN_HAND);
            caster->CastSpell(target, SPELL_THROW_GLAIVE_OFF_HAND);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_swoop::HandleCast, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    
};
//202913
class spell_fel_mortar : public SpellScript
{
    PrepareSpellScript(spell_fel_mortar);

    void HandleCast(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetCaster()->GetAI()->SelectTarget(SELECT_TARGET_RANDOM);
        if (!caster || !target)
            return;
        caster->CastSpell(target, SPELL_FEL_MORTAR_TRIGGER, true);
    }
    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_fel_mortar::HandleCast, EFFECT_0, SPELL_EFFECT_DUMMY);
    }

};

//AT : 9596 9595
class at_glaive_damage : public AreaTriggerAI
{
public:
    at_glaive_damage(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (Unit* caster = at->GetCaster())
            caster->CastSpell(unit, SPELL_GLAIVE);
    }

    void OnUnitExit(Unit* unit) override
    {
        unit->RemoveAurasDueToSpell(SPELL_GLAIVE);
    }
};
//10572
class at_hatred_damage : public AreaTriggerAI
{
public:
    at_hatred_damage(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }
    void OnCreate()override
    {

    }

    void OnUnitEnter(Unit* unit) override
    {
        if (Unit* caster = at->GetCaster())
            caster->CastSpell(unit, SPELL_HATRED_DAMAGE);

    }

    void OnUnitExit(Unit* unit) override
    {
        unit->RemoveAurasDueToSpell(SPELL_HATRED_DAMAGE);
    }
};
//SPELL_FURIOUS_BLAST = 191823 
//AT-9573
class at_furious_flames : public AreaTriggerAI
{
public:
    at_furious_flames(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

 
    void OnUnitEnter(Unit* unit) override
    {
        if (Unit* caster = at->GetCaster())
            caster->CastSpell(unit, SPELL_FURIOUS_FLAMES);
    }

    void OnUnitExit(Unit* unit) override
    {
        unit->RemoveAurasDueToSpell(SPELL_FURIOUS_FLAMES);
    }
};
//ID - 191766 Swoop
class spell_swoop_jump : public SpellScript
{
    PrepareSpellScript(spell_swoop_jump);
    //TODO: Need to be scripted to boss knocking back and damaging everyone who have collision with him from jump to dest.
};
//199132
class spell_intro_jump : public SpellScript
{
    PrepareSpellScript(spell_intro_jump);

    void HandleJumpDest(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
        Position const jumpPos = { 4284.973, -451.2752, 259.66946 };
        GetCaster()->GetMotionMaster()->MoveJump(jumpPos, 100, 0);
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_intro_jump::HandleJumpDest, EFFECT_0, SPELL_EFFECT_JUMP_DEST);
    }
};

void AddSC_boss_tirathon_saltheril()
{
    RegisterCreatureAI(boss_tirathon_saltheril);
    RegisterCreatureAI(npc_drelanim_whisperwind);
    RegisterCreatureAI(npc_fel_fury);
    RegisterSpellScript(spell_dark_strikes);
    RegisterSpellScript(spell_swoop);
    RegisterSpellScript(spell_intro_jump);
    RegisterSpellScript(spell_fel_mortar);
    RegisterAreaTriggerAI(at_glaive_damage);
    RegisterAreaTriggerAI(at_furious_flames);
   // RegisterAreaTriggerAI(at_hatred_damage);
}
