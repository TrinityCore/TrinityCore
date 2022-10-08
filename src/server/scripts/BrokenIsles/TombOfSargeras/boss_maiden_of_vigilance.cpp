/*
* Copyright (C) 2021 BfaCore Reforged
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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "tomb_of_sargeras.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_INFUSION_START = 1,
    SAY_INFUSION_END = 2,
    SAY_SECOND_PHASE = 3,
    SAY_SECOND_PHASE_LATER = 4,
    SAY_BEFORE_DEATH = 5, // ????????????
    SAY_DEATH = 6,
};

enum Spells
{
    // Global
    SPELL_INFUSION = 235271, //
    SPELL_MASS_INSTABILITY = 235267, // real cast  aura (235117) + 8 //
    SPELL_UNSTABLE_SOUL = 235117, // maybe need it late 243275 //

    // Light Side
    SPELL_LIGHT_INFUSION = 235213, // dmg 235214 //
    SPELL_HAMMER_OF_CREATION = 241635, // Aoe 235569 and tank dmg 241624 //
    SPELL_HAMMER_OF_CREATION_AOE = 235569, //
    SPELL_HAMMER_OF_CREATION_VICT = 241624, //
    SPELL_LIGHT_REMANENCE = 237994, // 119825
    SPELL_LIGHT_REMANENCE_SMALL = 238311, // myth

    // Fel side
    SPELL_FEL_INFUSION = 235240, // dmg 235253 //
    SPELL_HAMMER_OF_OBLITERATION = 241636, // aoe dmg 235573 and tank dmg 241634  + 17 //
    SPELL_HAMMER_OF_OBLITERATION_AOE = 235573, //
    SPELL_HAMMER_OF_OBLITERATION_VICT = 241634, //
    SPELL_FEL_REMANENCE = 238316, // 119826
    SPELL_FEL_REMANENCE_SMALL = 238416, // myth

    // Phase two
    SPELL_MOVE_TO_ANOTHER = 235630,
    SPELL_BLOWBACK = 248812, // by links; can find auras //
    SPELL_TITANIC_BULWARK = 235028, // by links //

    SPELL_WRATH_OF_THE_CREATORS = 234891, // dmg 234896 (holy) and 236432(fel)
    SPELL_WRATH_OF_THE_CREATORS_TICK = 235014, // 
    SPELL_WRATH_OF_THE_CREATORS_TICK_LIGHT = 234917,   //
    SPELL_WRATH_OF_THE_CREATORS_TICK_FEL = 236433, //
    SPELL_WRATH_OF_THE_CREATORS_TICK_LIGHT_DMG = 234896,   //
    SPELL_WRATH_OF_THE_CREATORS_TICK_FEL_DMG = 236432, //
    SPELL_WRATH_OF_THE_CREATORS_BUFF = 237339, // 

    SPELL_EXTINGUISH_LIFE = 238475, // 

    SPELL_ESSENCE_FRAGMENTS = 236061, //
    SPELL_ESSENCE_FRAGMENTS_TICK = 235859, //
    SPELL_CREATE_AT_VISUAL_FEL = 236708, //
    SPELL_CREATE_AT_VISUAL_LIGHT = 236690, //

    SPELL_ESSENCE_HIT_LIGHT = 235554, // visual
    SPELL_ESSENCE_BUFF_LIGHT = 235534, //
    SPELL_ESSENCE_HIT_FEL = 235555, // visual
    SPELL_ESSENCE_BUFF_FEL = 235538, // 

    // myth
    SPELL_FRAGMENT_BURST = 239069,
    SPELL_FRAGMENT_BURST_DEBUFF = 241729,

    SPELL_FRAGMENTING = 239153,
    SPELL_LIGHT_FRAGMENT = 241697,
    SPELL_LIGHT_FRAGMENT_FOCUS = 241713,
    SPELL_FEL_FRAGMENT = 241728,
    SPELL_FEL_FRAGMENT_FOCUS = 241727,

    SPELL_ENRAGE = 64238, //
    SPELL_SHIELD = 241593,

    SPELL_UNKWN = 237856, // also 235859
};

enum eEvents
{
    EVENT_INFUSION = 1,
    EVENT_LIGHT_HAMMER,
    EVENT_FEL_HAMMER,
    EVENT_MASS_INSTABILITY,
    EVENT_SECOND_PHASE,

    EVENT_FRAGMENTS,

};

Position const fragmentsPos[6]
{
    {6375.67f, -789.47f, 2887.84f, 0.0f}, // original right 1
    {6384.21f, -788.24f, 2887.84f, 0.0f}, // original right 2
    {6394.00f, -786.70f, 2887.84f, 0.0f}, // original right 3
    {6376.05f, -799.67f, 2887.84f, 0.0f}, // original left 1
    {6384.74f, -801.70f, 2887.84f, 0.0f}, // original left 2
    {6393.59f, -803.61f, 2887.84f, 0.0f}  // original left 3

    //6319.85 other side
};
/*
// 118289
struct boss_maiden_of_vigilance : BossAI
{
    boss_maiden_of_vigilance(Creature* creature) : BossAI(creature, DATA_MAIDEN_OF_VIGILANCE) {}

    uint32 wrathOfCreatorsCasts;
    uint32 countOfTeleports;

    bool empoweredPhase;
    bool isFelNeed = true;

    void Reset() override
    {
        if (me->isAlive())
            _Reset();

        me->KillAllDelayedEvents();
        wrathOfCreatorsCasts = 0;
        countOfTeleports = 0;
        empoweredPhase = false; // set true on 3 phase (second 1 phase)
        SetCombatMovement(true);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_LIGHT_INFUSION);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_FEL_INFUSION);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SHIELD);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_FRAGMENT_BURST_DEBUFF);
        me->SetReactState(REACT_DEFENSIVE);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_INTERRUPT, false);
    }

    void EnterCombat(Unit* /who/) override
    {
        Talk(SAY_AGGRO);
        _EnterCombat();

        me->AddDelayedEvent(480000, [this]() -> void
        {
            DoCast(me, SPELL_ENRAGE, true);
        });

        if (!IsLfrRaid())
        {
            events.RescheduleEvent(EVENT_INFUSION, 2000);
            events.RescheduleEvent(EVENT_LIGHT_HAMMER, 12000);
            events.RescheduleEvent(EVENT_MASS_INSTABILITY, 21000);
            events.RescheduleEvent(EVENT_SECOND_PHASE, 40000);
            if (IsMythicRaid())
                events.RescheduleEvent(EVENT_FRAGMENTS, 10000);
        }
        else
        {
            events.RescheduleEvent(EVENT_MASS_INSTABILITY, 6000);
            events.RescheduleEvent(EVENT_INFUSION, 40000);
            events.RescheduleEvent(EVENT_SECOND_PHASE, 47000);
        }
    }

    void JustDied(Unit* /killer/) override
    {
        Talk(SAY_DEATH);
        _JustDied();
        Reset();
    }

    void JustSummoned(Creature* creature) override
    {
        BossAI::JustSummoned(creature);

        switch (creature->GetEntry())
        {
        case NPC_REMANENCE_LIGHT:
            if (IsHeroicPlusRaid())
                creature->CastSpell(creature, SPELL_LIGHT_REMANENCE_SMALL);
            break;
        case NPC_REMANENCE_FEL:
            if (IsHeroicPlusRaid())
                creature->CastSpell(creature, SPELL_FEL_REMANENCE_SMALL);
            break;
        }
    }

    void SummonedCreatureDespawn(Creature* creature) override
    {
        if (!IsMythicRaid())
            return;

        switch (creature->GetEntry())
        {
        case NPC_ESSENCE_FEL:
        case NPC_ESSENCE_LIGHT:
            me->CastSpell(me, SPELL_FRAGMENT_BURST, true);
            break;
        }
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        switch (spell->Id)
        {
        case SPELL_HAMMER_OF_CREATION_AOE:
        case SPELL_HAMMER_OF_CREATION_VICT:
            if (target->HasAura(SPELL_FEL_INFUSION))
                DoCast(target, SPELL_UNSTABLE_SOUL, true);
            break;
        case SPELL_HAMMER_OF_OBLITERATION_AOE:
        case SPELL_HAMMER_OF_OBLITERATION_VICT:
            if (target->HasAura(SPELL_LIGHT_INFUSION))
                DoCast(target, SPELL_UNSTABLE_SOUL, true);
            break;
        }
    }

    void SpellFinishCast(SpellInfo const* spell) override
    {
        switch (spell->Id)
        {
        case SPELL_MASS_INSTABILITY:
        {
            uint32 spell = isFelNeed ? SPELL_FEL_INFUSION : SPELL_LIGHT_INFUSION;
            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0,
                [spell](Unit* targett)
            {
                if (!targett->IsPlayer() || !targett->isAlive() || !targett->ToPlayer()->isInTankSpec())
                    return false;

                return targett->HasAura(spell);
            }))
                me->CastSpell(target, SPELL_UNSTABLE_SOUL, false);
            for (uint32 spell : {SPELL_LIGHT_INFUSION, SPELL_FEL_INFUSION})
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0,
                    [spell](Unit* targett)
                {
                    if (!targett->IsPlayer() || !targett->isAlive() || targett->ToPlayer()->isInTankSpec())
                        return false;

                    return targett->HasAura(spell);
                }))
                    me->CastSpell(target, SPELL_UNSTABLE_SOUL, false);
                break;
        }
        case SPELL_WRATH_OF_THE_CREATORS_TICK:
        {
            bool lightOrFel = wrathOfCreatorsCasts++ % 2 == 0;
            me->CastSpell(me, lightOrFel ? SPELL_WRATH_OF_THE_CREATORS_TICK_LIGHT : SPELL_WRATH_OF_THE_CREATORS_TICK_FEL, true);
            instance->instance->ApplyOnEveryPlayer([this, lightOrFel](Player* player)
            {
                me->CastSpell(player, lightOrFel ? SPELL_WRATH_OF_THE_CREATORS_TICK_LIGHT_DMG : SPELL_WRATH_OF_THE_CREATORS_TICK_FEL_DMG, true);
            });

            if (me->GetAuraCount(SPELL_WRATH_OF_THE_CREATORS_BUFF) >= 30)
            {
                //  me->CastStop();
                instance->instance->ApplyOnEveryPlayer([this](Player* player)
                {
                    me->CastSpell(player, SPELL_EXTINGUISH_LIFE, true);
                });
                //  OnInterruptCast(me, NULL, SPELL_WRATH_OF_THE_CREATORS, NULL);
            }
            break;
        }
        case SPELL_ESSENCE_FRAGMENTS_TICK:
            // countOfTeleports % 2 == 1 - other side, == 0 - original side
            for (uint8 i = 0; i < 6; ++i)
            {
                const auto& pos = fragmentsPos[i];
                uint32 spellid = (urand(1, 2) == 1 ? SPELL_CREATE_AT_VISUAL_FEL : SPELL_CREATE_AT_VISUAL_LIGHT);
                me->CastSpell(pos.GetPositionX() - (countOfTeleports % 2 == 1 ? 73.2f : 0), pos.GetPositionY(), pos.GetPositionZ(), spellid, true);
                if (Creature* add = me->SummonCreature((spellid == SPELL_CREATE_AT_VISUAL_FEL ? NPC_ESSENCE_FEL : NPC_ESSENCE_LIGHT), pos.GetPositionX() - (countOfTeleports % 2 == 1 ? 73.2f : 0), pos.GetPositionY(), pos.GetPositionZ(), 0.0f, TEMPSUMMON_TIMED_DESPAWN, 12000))
                {
                    float change_speed = 1.2f * M_PI*add->GetDistance2d(6348.20f, -795.95f) / 45;
                    add->SetSpeed(MOVE_WALK, change_speed, true);
                    add->GetMotionMaster()->MoveCirclePath(6348.20f, -795.95f, add->GetPositionZ(), add->GetDistance2d(6348.20f, -795.95f), (countOfTeleports % 2 == 0 ? i > 2 : i <= 2), 24);
                }
            }
            break;

        case SPELL_HAMMER_OF_CREATION:
        case SPELL_HAMMER_OF_OBLITERATION:
            DoCastTopAggro(spell->Id == SPELL_HAMMER_OF_OBLITERATION ? SPELL_HAMMER_OF_OBLITERATION_VICT : SPELL_HAMMER_OF_CREATION_VICT, true);
            DoCastTopAggro(spell->Id == SPELL_HAMMER_OF_OBLITERATION ? SPELL_HAMMER_OF_OBLITERATION_AOE : SPELL_HAMMER_OF_CREATION_AOE, true);
            if (IsHeroicPlusRaid())
            {
                uint32 spellid = spell->Id == SPELL_HAMMER_OF_CREATION ? SPELL_FEL_INFUSION : SPELL_LIGHT_INFUSION;
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0,
                    [spellid](Unit* targett)
                {
                    if (!targett->IsPlayer() || !targett->isAlive())
                        return false;

                    return targett->HasAura(spellid);
                }))
                    me->CastSpell(target, spell->Id == SPELL_HAMMER_OF_OBLITERATION ? SPELL_FEL_REMANENCE : SPELL_LIGHT_REMANENCE, true);
            }
            break;
        }
    }

    void OnApplyOrRemoveAura(uint32 spellId, AuraRemoveMode /mode/, bool apply) override
    {
        if (spellId != SPELL_BLOWBACK || !me->isInCombat() || !me->isAlive())
            return;

        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_INTERRUPT, apply);
    }

   // void OnInterruptCast(Unit* /caster/, uint32 spellId, uint32 curSpellID, uint32 /schoolMask/) override
    {
        if (curSpellID == SPELL_WRATH_OF_THE_CREATORS)
        {
            empoweredPhase = true;
            me->SetReactState(REACT_DEFENSIVE);
           // if (!IsLfrRaid())
            {
                events.RescheduleEvent(EVENT_INFUSION, 3000);
                events.RescheduleEvent(EVENT_LIGHT_HAMMER, 12000);
                events.RescheduleEvent(EVENT_MASS_INSTABILITY, 21000);
                events.RescheduleEvent(EVENT_SECOND_PHASE, 82000);
                if (IsMythic())
                    events.RescheduleEvent(EVENT_FRAGMENTS, 8000);
            }
            else
            {
                events.RescheduleEvent(EVENT_MASS_INSTABILITY, 8000);
                events.RescheduleEvent(EVENT_INFUSION, 21000);
                events.RescheduleEvent(EVENT_SECOND_PHASE, 67000);
            }
        }
    }

    
    void UpdateAI(uint32 diff) override
    {
        if (me->HasAura(SPELL_WRATH_OF_THE_CREATORS))
        {
            bool needEvade = true;
            auto list = me->getThreatManager().getThreatList();
            for (auto& itr : list)
                if (Unit* target = itr->getTarget())
                    if (target->IsPlayer() && target->IsAlive())
                    {
                        needEvade = false;
                        break;
                    }

            if (needEvade)
                EnterEvadeMode();
            return;
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
            case EVENT_INFUSION:
                me->CastSpell(me, SPELL_INFUSION);
                if (!empoweredPhase)
                    Talk(SAY_INFUSION_START);

                if (empoweredPhase)
                    events.RescheduleEvent(EVENT_INFUSION, 38000);
                break;
            case EVENT_LIGHT_HAMMER:
                DoCast(SPELL_HAMMER_OF_CREATION);
                isFelNeed = false;
                events.RescheduleEvent(EVENT_FEL_HAMMER, 19000);
                break;
            case EVENT_FEL_HAMMER:
                DoCast(SPELL_HAMMER_OF_OBLITERATION);
                isFelNeed = true;
                if (empoweredPhase)
                    events.RescheduleEvent(EVENT_LIGHT_HAMMER, 19000);
                break;
            case EVENT_MASS_INSTABILITY:
                DoCast(SPELL_MASS_INSTABILITY);
                if (empoweredPhase)
                    events.RescheduleEvent(EVENT_MASS_INSTABILITY, 36000);
                break;
            case EVENT_SECOND_PHASE:
                events.Reset();
                Talk(SAY_SECOND_PHASE);
             //   me->AddDelayedEvent(8000, [this]()
                {
                    Talk(SAY_SECOND_PHASE_LATER);
               // });
                wrathOfCreatorsCasts = 0;
                if (++countOfTeleports % 2)
                    me->CastSpell(6310.30f, -795.36f, 2887.84f, SPELL_MOVE_TO_ANOTHER);
                else
                    me->CastSpell(me->GetHomePosition(), SPELL_MOVE_TO_ANOTHER, false);
                SetCombatMovement(false);
                me->SetReactState(REACT_PASSIVE);
                break;
            case EVENT_FRAGMENTS:
            {
                Unit* target = nullptr;
                for (int8 i = 2; i >= 0; i--)
                    if (target = SelectTarget(SELECT_TARGET_RANDOM, i))
                        break;

                if (!target)
                    break;

                DoCast(SPELL_FRAGMENTING);
                bool isFelFragment = target->HasAura(SPELL_LIGHT_INFUSION);
                me->CastSpell(target, (isFelFragment ? SPELL_FEL_FRAGMENT : SPELL_LIGHT_FRAGMENT));
                Position pos(target->GetPosition());
                ObjectGuid guid = target->GetGUID();
              //  me->AddDelayedEvent(3000, [this, guid, isFelFragment, pos]() -> void
                {
                  //  me->SummonCreature((isFelFragment ? NPC_ESSENCE_FEL : NPC_ESSENCE_LIGHT), pos, guid, TEMPSUMMON_TIMED_DESPAWN, 10000);
               // });
                break;
            }
            }
        }
        DoMeleeAttackIfReady();
    }
};*/

// 118640 light  118643 fel
struct npc_tos_essences : ScriptedAI
{
    npc_tos_essences(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
        SetCanSeeEvenInPassiveMode(true);
        me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC));
       // me->m_RateUpdateTimer = 50; // next will * 5
    }

    bool justDoIt = false;
    uint32 updateTimer = 200;

    void IsSummonedBy(Unit* cre) override
    {
      //  if (me->GetTargetGUID().IsEmpty())
     //       return;

      //  Unit* unit = me->GetTargetUnit();
       // if (!unit || !unit->isAlive())
         //   unit = me->FindNearestPlayer(60, true);

        //if (unit)
       //     me->GetMotionMaster()->MoveFollow(unit, 0, 0);
    }

    void UpdateAI(uint32 diff) override
    {
        if (justDoIt)
            return;

        if (updateTimer <= diff)
        {
            Map::PlayerList const& players = me->GetMap()->GetPlayers();
            for (const auto& itr : players)
            {
                Player* who = itr.GetSource();
                if (!who->IsAlive())
                    continue;

                if (me->GetDistance(who) < 0.22f && !justDoIt)
                {
                    justDoIt = true;

                    me->CastSpell(who, me->GetEntry() == NPC_ESSENCE_FEL ? SPELL_ESSENCE_HIT_FEL : SPELL_ESSENCE_HIT_LIGHT);

                    if (who->HasAura(SPELL_LIGHT_INFUSION) && me->GetEntry() == NPC_ESSENCE_LIGHT)
                    {
                        for (const auto& itr : players)
                            if (Player* temp = itr.GetSource())
                                if ((temp == who || temp->GetDistance(who) <= 10.0f) && temp->HasAura(SPELL_LIGHT_INFUSION))
                                    temp->CastSpell(temp, SPELL_ESSENCE_BUFF_LIGHT);
                    }
                    else if (who->HasAura(SPELL_FEL_INFUSION) && me->GetEntry() == NPC_ESSENCE_FEL)
                    {
                        for (const auto& itr : players)
                            if (Player* temp = itr.GetSource())
                                if ((temp == who || temp->GetDistance(who) <= 10.0f) && temp->HasAura(SPELL_FEL_INFUSION))
                                    temp->CastSpell(temp, SPELL_ESSENCE_BUFF_FEL);
                    }
                    else
                        who->CastSpell(who, SPELL_UNSTABLE_SOUL);

                    if (TempSummon* tempSum = me->ToTempSummon()) // we need it for disabling call SummonedCreatureDespawn
                        tempSum->SetSummonerGUID(ObjectGuid::Empty);

                    me->DespawnOrUnsummon(100);
                    break;
                }
            }
            updateTimer = 200;
        }
        else
            updateTimer -= diff;
    }
};

// 120132, 120131
struct npc_tos_essences_intro : ScriptedAI
{
    npc_tos_essences_intro(Creature* creature) : ScriptedAI(creature)
    {
        SetCanSeeEvenInPassiveMode(true);
    }

    std::set<ObjectGuid> players{};
    uint32 timer = 500;

    void UpdateAI(uint32 diff) override
    {
        if (timer <= diff)
        {
            Map::PlayerList const& pPlayers = me->GetMap()->GetPlayers();
            for (const auto& itr : pPlayers)
            {
                Player* who = itr.GetSource();
                if (me->GetDistance(who) < 1.0f)
                {
                    if (players.find(who->GetGUID()) != players.end())
                        return;

                    players.insert(who->GetGUID());

                    uint32 enemySpell = (me->GetEntry() == 120132 ? 239408 : 239407);
                    if (who->HasAura(enemySpell))
                        who->CastSpell(who, 239409);
                    else
                        who->CastSpell(who, (me->GetEntry() != 120132 ? 239408 : 239407));
                }
            }

            timer = 500;
        }
        else
            timer -= diff;
    }
};

// 235271
class spell_tos_infusion : public SpellScript
{
    PrepareSpellScript(spell_tos_infusion);

    std::vector<uint32> spellsForTank{ SPELL_LIGHT_INFUSION, SPELL_FEL_INFUSION };

    void CorrectTargets(std::list<WorldObject*>& targets)
    {
        if (!GetCaster())
            return;

        auto caster = GetCaster();

        if (caster->IsCreature())
            caster->ToCreature()->AI()->Talk(SAY_INFUSION_END);

        targets.remove_if([](WorldObject* target)
        {
            return !target->IsPlayer();
        });

        for (auto itr = targets.begin(); itr != targets.end(); )
        {
            Unit* target = (*itr)->ToUnit();
            if (!target->IsPlayer())
            {
                ++itr;
                continue;
            }

            for (auto spell : { SPELL_LIGHT_INFUSION, SPELL_FEL_INFUSION })
                target->ToUnit()->RemoveAurasDueToSpell(spell);

            if (Player* player = target->ToPlayer())
               // if (ROLES_TANK == player->GetSpecializationRole() && !spellsForTank.empty()) // tanks have are different buffs
                {
                    caster->CastSpell(player, spellsForTank.back(), true);
                    spellsForTank.pop_back();
                    itr = targets.erase(itr);
                    continue;
                }

            ++itr;
        }

        uint8 i = 0;
        for (auto target : targets)
        {
            if (!target->IsPlayer())
                continue;

            for (auto spell : { SPELL_LIGHT_INFUSION, SPELL_FEL_INFUSION })
                target->ToUnit()->RemoveAurasDueToSpell(spell);

            if (++i <= (targets.size() / 2))
                caster->CastSpell(target->ToUnit(), SPELL_LIGHT_INFUSION, true);
            else
                caster->CastSpell(target->ToUnit(), SPELL_FEL_INFUSION, true);
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_tos_infusion::CorrectTargets, SpellEffIndex::EFFECT_0, Targets::TARGET_UNIT_DEST_AREA_ENEMY);
    }
};



// 248812
class spell_tos_blowback : public AuraScript
{
    PrepareAuraScript(spell_tos_blowback);

    void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        if (!GetCaster() || !GetTarget())
            return;

        if (GetCaster()->GetDistance2d(GetTarget()) >= 60.0f)
            SetDuration(10);
        else
            SetDuration(1000 * (60 - GetCaster()->GetDistance2d(GetTarget())) * 12.0f / 60.0f);
    }

    void Register()
    {
        OnEffectApply += AuraEffectApplyFn(spell_tos_blowback::OnApply, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
    }
};

// 234896, 236432
class spell_tos_wrath_of_the_creators : public SpellScript
{
    PrepareSpellScript(spell_tos_wrath_of_the_creators);

    void HandleDamage(SpellEffIndex /*effectIndex*/)
    {
        if (!GetCaster())
            return;

        if (auto caster = GetCaster())
        {
            uint32 count = caster->GetAuraCount(SPELL_WRATH_OF_THE_CREATORS_BUFF);

            SetHitDamage(GetHitDamage() * (1 + 0.05*count));
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_tos_wrath_of_the_creators::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 235117
class spell_tos_unstable_soul : public AuraScript
{
    PrepareAuraScript(spell_tos_unstable_soul);

    void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        if (!GetTarget())
            return;
        Unit* target = GetTarget();

        if (target->GetAuraCount(235117) <= 1)
        {
            target->CastSpell(target, 249912);
            return;
        }

        Aura* aura = GetAura();

      //  if (target->GetMap()->IsMythic())
      //  {
           // target->RemoveAppliedAuras(235117, [aura](AuraApplicationPtr const aplication) -> bool
        //    {
             //   Aura const* curAura = aplication->GetBase();
              //  return curAura != aura;
          //  }, AURA_REMOVE_BY_EXPIRE);
       //     target->CastSpell(target, 249912);
       // }
     //   else
            target->RemoveAura(aura);
    }

    void Register()
    {
        OnEffectApply += AuraEffectApplyFn(spell_tos_unstable_soul::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

// 235213 235240
class spell_tos_infusions : public AuraScript
{
    PrepareAuraScript(spell_tos_infusions);

    bool isFirstTick = true;

    void OnTick(AuraEffect const* /*aurEff*/)
    {
        Unit* target = GetTarget();
        if (!target)
            return;


        if (isFirstTick)
        {
            isFirstTick = false;
            return;
        }
        else
        {
            target->RemoveAurasDueToSpell(GetSpellInfo()->Id == SPELL_FEL_INFUSION ? 241316 : 241315);
            if (target->IsAlive())
                target->CastSpell(target, GetSpellInfo()->Id == SPELL_FEL_INFUSION ? 241316 : 241315, true);
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_tos_infusions::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_tos_infusions::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

// 241593
class spell_egvin_levitation : public AuraScript
{
    PrepareAuraScript(spell_egvin_levitation);

    void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        if (!GetTarget())
            return;
        Unit* target = GetTarget();

        if (!target->GetMap()->IsHeroic())
            target->CastSpell(target, 241565, true);
    }

    void Register()
    {
        OnEffectApply += AuraEffectApplyFn(spell_egvin_levitation::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_boss_maiden_of_vigilance()
{
  //  RegisterCreatureAI(boss_maiden_of_vigilance);
    RegisterCreatureAI(npc_tos_essences);
    RegisterCreatureAI(npc_tos_essences_intro);
    RegisterSpellScript(spell_tos_infusion);
    RegisterAuraScript(spell_tos_blowback);
    RegisterSpellScript(spell_tos_wrath_of_the_creators);
    RegisterAuraScript(spell_tos_unstable_soul);
    //RegisterAuraScript(spell_tos_infusions);
    RegisterAuraScript(spell_egvin_levitation);
}
