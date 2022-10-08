/*
 * Copyright (C) 2022 BfaCore Reforged
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

#include "Conversation.h"
#include "ScriptMgr.h"
#include "emerald_nightmare.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_FOCUSED_GAZE_EMOTE = 1,
    SAY_FOCUSED_GAZE = 2,
    SAY_CACOPHONY = 3,
    SAY_DEATH = 4,
    SAY_BLOOD_FRENZY = 5,
};

enum Spells
{
    SPELL_EMPTY_ENERGY = 205270,
    SPELL_FEROCIOUS_YELL = 204990,
    SPELL_ENERGIZE = 205272, //2.941176470588235
    SPELL_BERSERK = 26662,
    SPELL_OVERWHELM_AURA = 197946,
    SPELL_OVERWHELM_DUMMY = 197947,
    SPELL_OVERWHELM_DMG = 197943,
    SPELL_REND_FLESH_AURA = 197948,
    SPELL_REND_FLESH_DUMMY = 197949,
    SPELL_REND_FLESH_DMG = 197942,
    SPELL_FOCUSED_GAZE = 198006,
    SPELL_BARRELING_MOMENTUM = 198002,
    SPELL_B_MOMENTUM_FILTER = 198004,
    SPELL_B_MOMENTUM_PING = 198007,
    SPELL_B_MOMENTUM_CHARGE = 198009,
    SPELL_B_MOMENTUM_AT = 198093,
    SPELL_B_MOMENTUM_DMG = 198099,
    SPELL_B_MOMENTUM_AOE = 198109,
    SPELL_B_MOMENTUM_DUMMY = 198102,
    SPELL_MOMENTUM_DEBUFF = 198108,
    SPELL_TRAMPLING_SLAM = 199237,
    SPELL_BLOOD_FRENZY = 198388,
    SPELL_ROARING_CACOPHONY_AURA = 197986,
    SPELL_ROARING_CACOPHONY_DUMMY_1 = 197988,
    SPELL_ROARING_CACOPHONY_DUMMY_2 = 197989,
    SPELL_ROARING_CACOPHONY_DMG = 197969,
    SPELL_ECHOING_DISCHORD = 198392,

    //Heroic+
    SPELL_ROARING_CACOPHONY_SUM = 197982, //Sum NPC: 100576
    SPELL_NIGHTMARISH_CACOPHONY = 197980,
    SPELL_NIGHTMARE_IMAGE_AT = 197960, //DMG: 205611
    SPELL_NIGHTMARE_IMAGE_MORPH = 204969,
};

enum eEvents
{
    EVENT_FOCUSED_GAZE = 1,
    EVENT_REND_FLESH = 2,
    EVENT_OVERWHELM = 3,
    EVENT_ROARING_CACOPHONY = 4,
    EVENT_ROARING_CACOPHONY_2 = 5,

    EVENT_ACTIVATE_IMAGE, //Mythic
    ACTION_BARRELING_MOMENTUM,
};

enum eOther
{
    DATA_PLAYER_HITCOUNT = 1,
    DATA_MOMENTUM_TARGET = 2,
};

//100497
struct boss_ursoc : public BossAI
{
    boss_ursoc(Creature* creature) : BossAI(creature, DATA_URSOC) {}

    bool introDone = false;
    bool focused = false;
    bool lowHp = false;
    uint8 playerHitCount = 0;
    uint32 berserkTimer = 0;
    ObjectGuid m_TargetGUID;

    void Reset() override
    {
        _Reset();
        summons.DespawnAll();
        me->SetPower(POWER_ENERGY, 100);
        DoCast(me, SPELL_EMPTY_ENERGY, true);
        focused = false;
        lowHp = false;
    }

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();
        DoCast(me, SPELL_FEROCIOUS_YELL, true);
        DoCast(me, SPELL_ENERGIZE, true);

        berserkTimer = 5 * MINUTE * IN_MILLISECONDS;
        events.RescheduleEvent(EVENT_OVERWHELM, 10000);
        events.RescheduleEvent(EVENT_REND_FLESH, 13000);
        events.RescheduleEvent(EVENT_ROARING_CACOPHONY, 18000);
        Talk(SAY_AGGRO);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who->IsPlayer())
            return;

        if (!introDone && me->IsWithinDistInMap(who, 100.0f))
        {
            introDone = true;
           // Conversation* conversation = new Conversation;
          //  if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), 3605, who, nullptr, who->GetPosition()))
           //     delete conversation;
        }
        BossAI::MoveInLineOfSight(who);
    }

    void SpellHit(Unit* caster, const SpellInfo* spell) override
    {
        if (!me->IsInCombat())
            return;

        switch (spell->Id)
        {
        case SPELL_OVERWHELM_DUMMY:
            DoCastVictim(SPELL_OVERWHELM_DMG, true);
            break;
        case SPELL_REND_FLESH_DUMMY:
            DoCastVictim(SPELL_REND_FLESH_DMG);
            break;
        case SPELL_ROARING_CACOPHONY_DUMMY_2:
            Talk(SAY_CACOPHONY);
            me->CastSpell(me, SPELL_ROARING_CACOPHONY_DMG);
            if (IsHeroic())
            {
               // DoActionSummon(NPC_NIGHTMARE_IMAGE, 1);
                Position pos;
                me->GetFirstCollisionPosition(0.0f, 0.0f);
                me->CastSpell(pos, SPELL_ROARING_CACOPHONY_SUM, true);
            }
            break;
        case SPELL_B_MOMENTUM_PING:
            playerHitCount = 0;
            DoCast(me, SPELL_B_MOMENTUM_AT, true);
            DoCast(caster, SPELL_TRAMPLING_SLAM, true);
            DoCast(caster, SPELL_B_MOMENTUM_CHARGE);
            //>Hack
            me->SetPower(POWER_ENERGY, 0);
            //me->GetMotionMaster()->MoveCharge(caster->GetPosition(), 40.0f, SPELL_B_MOMENTUM_CHARGE);
            //<
            focused = false;
            break;
        }
    }

    void SpellHitTarget(Unit* target, const SpellInfo* spell) override
    {
        if (!me->IsInCombat())
            return;

        switch (spell->Id)
        {
        case SPELL_B_MOMENTUM_FILTER:
            m_TargetGUID = target->GetGUID();
            DoCast(target, SPELL_FOCUSED_GAZE, true);
            DoCast(target, SPELL_B_MOMENTUM_DUMMY, true);
            Talk(SAY_FOCUSED_GAZE_EMOTE); //, //target->GetGUID());
            Talk(SAY_FOCUSED_GAZE);
            break;
        }
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type == POINT_MOTION_TYPE)
            if (id == SPELL_B_MOMENTUM_CHARGE)
                DoCast(me, SPELL_B_MOMENTUM_AOE, true);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (me->HealthBelowPct(31) && !lowHp)
        {
            lowHp = true;
            DoCast(me, SPELL_BLOOD_FRENZY, true);
            Talk(SAY_BLOOD_FRENZY);
        }
    }

    void DoAction(int32 const action) override
    {
        if (action == ACTION_BARRELING_MOMENTUM && !focused)
        {
            focused = true;
            events.RescheduleEvent(EVENT_FOCUSED_GAZE, 500);
        }
    }

    uint32 GetData(uint32 type) const override
    {
        switch (type)
        {
        case DATA_PLAYER_HITCOUNT:
            return playerHitCount;
        }
        return 0;
    }

    void SetData(uint32 type, uint32 data) override
    {
        switch (type)
        {
        case DATA_PLAYER_HITCOUNT:
            ++playerHitCount;
            break;
        default:
            break;
        }
    }

 //   ObjectGuid GetGUID(int32 type) override
//    {
//        switch (type)
  //      {
  //      case DATA_MOMENTUM_TARGET:
  //          return m_TargetGUID;
  //      default:
   //         return ObjectGuid::Empty;
   //     }
 //   }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        if (berserkTimer)
        {
            if (berserkTimer <= diff)
            {
                berserkTimer = 0;
                DoCast(me, SPELL_BERSERK, true);
            }
            else
                berserkTimer -= diff;
        }

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_REND_FLESH:
                DoCast(me, SPELL_REND_FLESH_AURA, true);
                break;
            case EVENT_FOCUSED_GAZE:
                m_TargetGUID.Clear();
                DoCast(me, SPELL_B_MOMENTUM_FILTER, true);
                break;
            case EVENT_OVERWHELM:
                DoCast(me, SPELL_OVERWHELM_AURA, true);
                break;
            case EVENT_ROARING_CACOPHONY:
                DoCast(me, SPELL_ROARING_CACOPHONY_DUMMY_2, true);
                events.RescheduleEvent(EVENT_ROARING_CACOPHONY_2, 20000);
                if (IsMythic())
                    events.RescheduleEvent(EVENT_ACTIVATE_IMAGE, 40000);
                break;
            case EVENT_ROARING_CACOPHONY_2:
                DoCast(me, SPELL_ROARING_CACOPHONY_AURA, true);
                break;
            case EVENT_ACTIVATE_IMAGE:
            {
              //  GuidList* summonList = me->GetSummonList(NPC_NIGHTMARE_IMAGE);
               // if (!summonList->empty())
                //    if (ObjectGuid firstGUID = summonList->front())
                  //      if (auto image = ObjectAccessor::GetCreature(*me, firstGUID))
                    //        image->AI()->DoAction(ACTION_2);
                events.RescheduleEvent(EVENT_ACTIVATE_IMAGE, 40000);
                break;
            }
            }
        }
        DoMeleeAttackIfReady();
    }
};

//100576
struct npc_ursoc_nightmare_image : public ScriptedAI
{
    npc_ursoc_nightmare_image(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
        me->AddUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_ATTACKABLE_1));
    }

    EventMap events;

    void IsSummonedBy(Unit* summoner) override
    {
        DoZoneInCombat(me, 100.0f);
        DoCast(me, SPELL_NIGHTMARE_IMAGE_MORPH, true);
        events.RescheduleEvent(3, 3000);
    }

    void Reset() override {}

    void DoAction(int32 const action) override
    {
        switch (action)
        {
        case 1:
            me->RemoveAurasDueToSpell(SPELL_NIGHTMARE_IMAGE_MORPH);
            DoCast(SPELL_NIGHTMARISH_CACOPHONY);
            events.RescheduleEvent(1, 4000);
            break;
        case 2:
            events.RescheduleEvent(2, 500);
            break;
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
            case 1:
                DoCast(me, SPELL_NIGHTMARE_IMAGE_MORPH, true);
                break;
            case 2:
              //  me->RemoveAreaObject(SPELL_NIGHTMARE_IMAGE_AT);
                me->RemoveAurasDueToSpell(SPELL_NIGHTMARE_IMAGE_MORPH);
                me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_ATTACKABLE_1));
                me->SetReactState(REACT_AGGRESSIVE);
                break;
            case 3:
                DoCast(me, SPELL_NIGHTMARE_IMAGE_AT, true);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

//205272
class spell_ursoc_periodic_energize : public AuraScript
{
    PrepareAuraScript(spell_ursoc_periodic_energize);

    uint8 PowerCount;

    void OnTick(AuraEffect const* aurEff)
    {
        Creature* caster = GetCaster()->ToCreature();
        if (!caster || !caster->IsInCombat())
            return;

        PowerCount = caster->GetPower(POWER_ENERGY);

        if (PowerCount < 100)
            caster->SetPower(POWER_ENERGY, PowerCount + 3);
        else
            caster->AI()->DoAction(ACTION_BARRELING_MOMENTUM);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_ursoc_periodic_energize::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

//199237
class spell_ursoc_trampling_slam : public SpellScript
{
    PrepareSpellScript(spell_ursoc_trampling_slam);

    void DealDamage()
    {
        if (!GetCaster() || !GetHitUnit())
            return;

        float distance = GetCaster()->GetExactDist2d(GetHitUnit());

        if (distance < 100.0f)
            SetHitDamage(GetHitDamage() * (1.0f - (distance / 100.0f)));
        else
            SetHitDamage(GetHitDamage() * 0.1f);
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_ursoc_trampling_slam::DealDamage);
    }
};

//198109
class spell_ursoc_barreling_impact : public SpellScript
{
    PrepareSpellScript(spell_ursoc_barreling_impact);

    void DealDamage()
    {
        if (!GetCaster() || !GetCaster()->IsAIEnabled)
            return;

        uint8 plrCount = GetCaster()->GetMap()->GetPlayersCountExceptGMs();

        if (uint8 hitCount = GetCaster()->GetAI()->GetData(DATA_PLAYER_HITCOUNT))
        {
            uint32 perc = float(float(hitCount) / float(plrCount) * 100.0f);
            if (perc >= 100)
                perc = 90;
            int32 damage = CalculatePct(GetHitDamage(), 100 - perc);
            SetHitDamage(damage);
        }
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_ursoc_barreling_impact::DealDamage);
    }
};

//198099
class spell_ursoc_momentum_filter : public SpellScript
{
    PrepareSpellScript(spell_ursoc_momentum_filter);

    void FilterTargets(WorldObject*& target)
    {
        if (Unit* caster = GetCaster())
        {
            ObjectGuid guid = caster->GetAI()->GetGUID(DATA_MOMENTUM_TARGET);
            if (Player* pTarget = ObjectAccessor::GetPlayer(*caster, guid))
            {
                if (!(Player*)target->IsInBetween(caster, pTarget, 10.0f))
                {
                    target = nullptr;
                }
            }
        }
    }

    void HandleOnHit()
    {
        if (GetCaster() && GetHitUnit())
        {
            GetCaster()->CastSpell(GetHitUnit(), SPELL_MOMENTUM_DEBUFF, true);
            GetCaster()->GetAI()->SetData(DATA_PLAYER_HITCOUNT, 1);
        }
    }

    void Register() override
    {
        OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_ursoc_momentum_filter::FilterTargets, EFFECT_0, TARGET_UNIT_TARGET_ENEMY);
        OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_ursoc_momentum_filter::FilterTargets, EFFECT_1, TARGET_UNIT_TARGET_ENEMY);
        OnHit += SpellHitFn(spell_ursoc_momentum_filter::HandleOnHit);
    }
};

void AddSC_ursoc()
{
    RegisterCreatureAI(boss_ursoc);
    RegisterCreatureAI(npc_ursoc_nightmare_image);
    RegisterAuraScript(spell_ursoc_periodic_energize);
    RegisterSpellScript(spell_ursoc_trampling_slam);
    RegisterSpellScript(spell_ursoc_barreling_impact);
    RegisterSpellScript(spell_ursoc_momentum_filter);
}
