/*
* Copyright (C) 2021 ShadowCore
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
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "InstanceScript.h"
#include "SpellAuraEffects.h"
#include "castle_nathria.h"

enum Spells
{
    SPELL_INFUSED = 332535,
    SPELL_DANSE_MACABRE_MOD_DAMAGE_TAKEN = 330959,
    SPELL_DANSE_MACABRE_DUMMY = 328497,
    SPELL_DANSE_MACABRE_CREATE_AT = 328485,//20402
    SPELL_DANSE_MACABRE_AURA = 328495,
    SPELL_DANSE_MACABRE_CREATE_AT_TWO = 344181,//21954
    SPELL_OPRESSIVE_ATMOSPHERE = 334909,
    EVENT_DANSE_MACABRE = 2,

    //Baroness Frieda
    SPELL_DREADBOLT_VOLLEY = 337110,
    SPELL_DRAIN_ESSENCE_CHANNEL = 346654,
    SPELL_DRAIN_ESSENCE_PERIODIC_DAMAGE = 346651,
    SPELL_DRAIN_ESSENCE_MOD_HEALTH = 327773,

    //Prideful Eruption
    SPELL_PRIDEFUL_ERUPTION_CAST = 346657,
    SPELL_PRIDEFUL_ERUPTION_MISSILE = 346661,
    SPELL_PRIDEFUL_ERUPTION_DAMAGE = 346660,
    //Soul Spikes
    SPELL_SOUL_SPIKES_DEBUFF = 346681,
    SPELL_SOUL_SPIKES_PERIODIC_DUMMY = 346762,
    SPELL_SOUL_SPIKES_DAMAGE = 346685,

    //Castellan Niklaus
    SPELL_DUELIST_RISPOSE = 346690,
    SPELL_UNDYING_SHIELD = 346694,

    SPELL_DREDGER_SERVANT = 330978,
    SPELL_THROW_FOOD = 330968,
    SPELL_CASTELLANS_CADRE = 330965,
    SPELL_BERSERK = 26662,

    //Lord Stavros
    SPELL_EVASIVE_LUNGE_DAMAGE = 327610,
    SPELL_EVASIVE_LUNGE_TELEPORT = 327497,
    SPELL_DARK_RECITAL = 331634,
    SPELL_DARK_RECITAL_TRIGGER = 334741,
    SPELL_WALTZ_OF_BLOOD_STUN = 327619,
    SPELL_DANCING_FOOLS = 330964,
    SPELL_VIOLENT_UPROAR = 346303,

    //Heroic
    SPELL_MANIFEST_PAIN_CREATE_AT = 346944, //22212
    SPELL_MANIFEST_PAIN_AT_DAMAGE = 346945,
    SPELL_TWISTED_PAIN = 346939,
    SPELL_TWISTED_PAIN_CREATE_AT_APPLY_AIRA = 346937, //22211
    SPELL_CASTELLANS_FURY = 346934,
    SPELL_TWO_LEFT_FEET = 346932,
    //Mythic
    EVENT_DANCING_FEVER = 1,
    SPELL_DANCING_FEVER_AURA = 347350,

    //Frieda
    ACTION_PRIDEFUL_ERUPTION = 1,
    ACTION_SOUL_SPIKES,
    //Niklaus
    ACTION_DREDGER_SERVANT, // begrudging waiter 
    ACTION_CASTELLANS_CADRE,
    //Lord
    ACTION_WALTZ_OF_BLOOD,
    ACTION_DANCING_FOOLS
};

//166969,166971,166970
struct boss_council_of_blood : public BossAI
{
    boss_council_of_blood(Creature* creature) : BossAI(creature, DATA_COUNCIL_OF_BLOOD) { }

private:
    uint8 deathCount;

    void Reset() override
    {
        BossAI::Reset();
        me->SetPowerType(POWER_ENERGY);
        me->SetMaxPower(POWER_ENERGY, 100);
        me->SetPower(POWER_ENERGY, 100);
        //me->AddAura(AURA_OVERRIDE_POWER_COLOR_DEMONIC);
        me->SetReactState(REACT_AGGRESSIVE);
    }

    Creature* GetBaronessFrieda()
    {
        return me->FindNearestCreature(NPC_BARONESS_FRIEDA, 150.0f, true);
    }

    Creature* GetCastellanNiklaus()
    {
        return me->FindNearestCreature(NPC_BARONESS_FRIEDA, 150.0f, true);
    }

    Creature* GetLordStavros()
    {
        return me->FindNearestCreature(NPC_BARONESS_FRIEDA, 150.0f, true);
    }

    void EnterCombat(Unit* /*who*/) override
    {
        switch (me->GetEntry())
        {
        case NPC_BARONESS_FRIEDA:
            _EnterCombat();
            events.ScheduleEvent(SPELL_OPRESSIVE_ATMOSPHERE, 1s);
            events.ScheduleEvent(SPELL_DREADBOLT_VOLLEY, 5s);
            events.ScheduleEvent(SPELL_DRAIN_ESSENCE_CHANNEL, 12s);
            if (IsMythic())
                events.ScheduleEvent(EVENT_DANCING_FEVER, 6s);
            this->deathCount = 0;
            events.ScheduleEvent(EVENT_DANSE_MACABRE, 30s);
            break;

        case NPC_CASTELLAN_NIKLAUS:
            _EnterCombat();
            events.ScheduleEvent(SPELL_DUELIST_RISPOSE, 5s);
            events.ScheduleEvent(SPELL_UNDYING_SHIELD, 6s);
            break;

        case NPC_LORD_STAVROS:
            _EnterCombat();
            events.ScheduleEvent(SPELL_EVASIVE_LUNGE_TELEPORT, 5s);
            events.ScheduleEvent(SPELL_DARK_RECITAL, 22s);
            break;
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case EVENT_DANSE_MACABRE:
            /*me->AddAura(SPELL_DANSE_MACABRE_MOD_DAMAGE_TAKEN);
            if (Creature* niklaus = GetCastellanNiklaus())
                niklaus->AddAura(SPELL_DANSE_MACABRE_MOD_DAMAGE_TAKEN);
            if (Creature* stavros = GetLordStavros())
                stavros->AddAura(SPELL_DANSE_MACABRE_MOD_DAMAGE_TAKEN);*/
            me->CastSpell(Position(-2098.885f, 6433.119f, 4298.077f, 1.643f), SPELL_DANSE_MACABRE_CREATE_AT, true);
            events.Repeat(60s);
            break;

        case SPELL_OPRESSIVE_ATMOSPHERE:
        {
            std::list<Player*> playerList;
            me->GetPlayerListInGrid(playerList, 150.0f);
            for (Player* targets : playerList)
            {
                me->AddAura(SPELL_OPRESSIVE_ATMOSPHERE, targets);
            }
            events.Repeat(10s);
            break;
        }

        case SPELL_DREADBOLT_VOLLEY:
            DoCastRandom(SPELL_DREADBOLT_VOLLEY, 100.0f, false);
            events.Repeat(20s);
            break;

        case SPELL_DRAIN_ESSENCE_CHANNEL:
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
            {
                me->CastSpell(target, SPELL_DRAIN_ESSENCE_CHANNEL, false);
                me->AddAura(SPELL_DRAIN_ESSENCE_PERIODIC_DAMAGE, target);
                me->AddAura(SPELL_DRAIN_ESSENCE_MOD_HEALTH, target);
            }
            events.Repeat(30s);
            break;

        case SPELL_DUELIST_RISPOSE:
            DoCastVictim(SPELL_DUELIST_RISPOSE, false);
            events.Repeat(20s);
            break;

        case SPELL_UNDYING_SHIELD:
        {
            Position summonPos = me->GetRandomNearPosition(30.0f);
            me->SummonCreature(NPC_DUTIFUL_ATTENDANT, summonPos, TEMPSUMMON_MANUAL_DESPAWN);
            if (Creature* dutiful = me->FindNearestCreature(NPC_DUTIFUL_ATTENDANT, 100.0f, true))
                me->CastSpell(dutiful, SPELL_UNDYING_SHIELD, false);
            events.Repeat(30s);
            break;
        }

         // case SPELL_EVASIVE_LUNGE_TELEPORT:
          //  if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 100.0f, true))
         //   {
           //     me->CastSpell(target, SPELL_EVASIVE_LUNGE_TELEPORT, false);
             //   me->CastSpell(target, SPELL_EVASIVE_LUNGE_DAMAGE, true);
           // }
           // events.Repeat(20s);
           // break;

        case SPELL_DARK_RECITAL:
            me->CastSpell(nullptr, SPELL_DARK_RECITAL, false);
            events.Repeat(30s);
            break;

        case EVENT_DANCING_FEVER:
        {
            UnitList targetList;
            SelectTargetList(targetList, 5, SELECT_TARGET_RANDOM, 150.0f, true);
            for (Unit* targets : targetList)
            {
                me->AddAura(SPELL_DANCING_FEVER_AURA, targets);
                if (Aura* fever = targets->GetAura(SPELL_DANCING_FEVER_AURA))
                    fever->SetStackAmount(3);
            }
            events.Repeat(35s);
            break;
        }

        case SPELL_PRIDEFUL_ERUPTION_CAST:
            me->CastSpell(nullptr, SPELL_PRIDEFUL_ERUPTION_CAST, false);
            events.Repeat(35s);
            break;

         //case SPELL_SOUL_SPIKES_PERIODIC_DUMMY:
          //  if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 100.0f, true))
           // {
             //   me->CastSpell(target, SPELL_SOUL_SPIKES_PERIODIC_DUMMY, false);
               // me->CastSpell(target, SPELL_SOUL_SPIKES_DAMAGE, true);
               // me->CastSpell(target, SPELL_SOUL_SPIKES_DEBUFF, true);
             //}
         //   events.Repeat(40s);
           // break;
        }
    }

    void OnSpellFinished(SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
        case SPELL_DARK_RECITAL:
        {
            std::list<Player*> playerList;
            me->GetPlayerListInGrid(playerList, 150.0f);
            for (Player* targets : playerList)
            {
                me->CastSpell(targets, SPELL_DARK_RECITAL_TRIGGER, true);
            }
            break;
        }
        case SPELL_PRIDEFUL_ERUPTION_CAST:
        {
            std::list<Player*> playerList;
            me->GetPlayerListInGrid(playerList, 150.0f);
            for (Player* targets : playerList)
            {
                me->CastSpell(targets, SPELL_PRIDEFUL_ERUPTION_MISSILE, true);
                me->CastSpell(targets, SPELL_PRIDEFUL_ERUPTION_DAMAGE, true);
            }
            break;
        }
        }
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spellInfo) override
    {
        if (!IsHeroic() || !IsMythic())
            return;

        switch (spellInfo->Id)
        {
        case SPELL_DREADBOLT_VOLLEY:
        case SPELL_DRAIN_ESSENCE_PERIODIC_DAMAGE:
        case SPELL_PRIDEFUL_ERUPTION_DAMAGE:
            if (me->GetEntry() == NPC_BARONESS_FRIEDA)
                me->CastSpell(target->GetPosition(), SPELL_MANIFEST_PAIN_CREATE_AT, true);
            break;
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _JustReachedHome();
        me->NearTeleportTo(me->GetHomePosition());
        me->RemoveAllAreaTriggers();
        _DespawnAtEvade();
    }

    void JustDied(Unit* /*victim*/) override
    {
        switch (me->GetEntry())
        {
        case NPC_BARONESS_FRIEDA:
            deathCount++;
            _JustDied();
            if (IsMythic())
                me->SummonCreature(NPC_AFTERIMAGE_OF_BARONESS_FRIEDA, me->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN);
            //Set full health
            if (Creature* niklaus = GetCastellanNiklaus())
                niklaus->SetFullHealth();
            if (Creature* stavros = GetLordStavros())
                stavros->SetFullHealth();
            break;

        case NPC_CASTELLAN_NIKLAUS:
            deathCount++;
            _JustDied();
            if (IsMythic())
                me->SummonCreature(NPC_AFTERIMAGE_OF_CASTELLAN_NIKLAUS, me->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN);
            //Set full health
            if (Creature* frieda = GetBaronessFrieda())
                frieda->SetFullHealth();
            if (Creature* stavros = GetLordStavros())
                stavros->SetFullHealth();
            break;

        case NPC_LORD_STAVROS:
            deathCount++;
            _JustDied();
            if (IsMythic())
                me->SummonCreature(NPC_AFTERIMAGE_OF_LORD_STAVROS, me->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN);
            //Set full health
            if (Creature* frieda = GetBaronessFrieda())
                frieda->SetFullHealth();
            if (Creature* niklaus = GetCastellanNiklaus())
                niklaus->SetFullHealth();
            break;
        }

        //Frieda
        if (Creature* frieda = GetBaronessFrieda())
            frieda->AI()->DoAction(ACTION_PRIDEFUL_ERUPTION);

        if (Creature* frieda = GetBaronessFrieda())
            if (this->deathCount == 2)
                frieda->AI()->DoAction(ACTION_SOUL_SPIKES);

        //Niklaus
        if (Creature* niklaus = GetCastellanNiklaus())
            niklaus->AI()->DoAction(ACTION_DREDGER_SERVANT);

        if (Creature* niklaus = GetCastellanNiklaus())
            if (this->deathCount == 2)
                niklaus->AI()->DoAction(ACTION_CASTELLANS_CADRE);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
        case ACTION_PRIDEFUL_ERUPTION:
            events.ScheduleEvent(SPELL_PRIDEFUL_ERUPTION_CAST, 3s);
            break;

        case ACTION_SOUL_SPIKES:
            events.ScheduleEvent(SPELL_SOUL_SPIKES_PERIODIC_DUMMY, 3s);
            break;

        case ACTION_DREDGER_SERVANT:
            me->SummonCreature(NPC_BEGRUDGING_WAITER, me->GetRandomNearPosition(30.0f), TEMPSUMMON_MANUAL_DESPAWN);
            break;

        case ACTION_CASTELLANS_CADRE:
            me->SummonCreature(NPC_VETERAN_STONEGUARD, me->GetRandomNearPosition(30.0f), TEMPSUMMON_MANUAL_DESPAWN);
            break;

        case ACTION_WALTZ_OF_BLOOD:
            break;

        case ACTION_DANCING_FOOLS:
            break;
        }
    }
};

//172803,172993,173053
struct npc_afterimage : public ScriptedAI
{
    npc_afterimage(Creature* c) : ScriptedAI(c) { }

    void IsSummonedBy(Unit* summoner) override
    {
        if (summoner->IsInCombat())
            me->AI()->EnterCombat(summoner->GetVictim());

        switch (me->GetEntry())
        {
        case NPC_AFTERIMAGE_OF_BARONESS_FRIEDA:
            DoCastRandom(SPELL_DREADBOLT_VOLLEY, 100.0f, false);
            events.Repeat(20s);
            break;

        case NPC_AFTERIMAGE_OF_CASTELLAN_NIKLAUS:
        {
            Position summonPos = me->GetRandomNearPosition(30.0f);
            me->SummonCreature(NPC_DUTIFUL_ATTENDANT, summonPos, TEMPSUMMON_MANUAL_DESPAWN);
            if (Creature* dutiful = me->FindNearestCreature(NPC_DUTIFUL_ATTENDANT, 100.0f, true))
                me->CastSpell(dutiful, SPELL_UNDYING_SHIELD, false);
            events.Repeat(30s);
            break;
        }
        case NPC_AFTERIMAGE_OF_LORD_STAVROS:
            me->CastSpell(nullptr, SPELL_DARK_RECITAL, false);
            events.Repeat(30s);
            break;
        }
    }
};

//346944
struct at_manifest_pain : public AreaTriggerAI
{
    at_manifest_pain(AreaTrigger* at) : AreaTriggerAI(at) { }

    void OnUnitEnter(Unit* target) override
    {
        if (!target->IsPlayer())
            return;

        if (at->GetCaster())
            at->GetCaster()->AddAura(SPELL_MANIFEST_PAIN_AT_DAMAGE, target);
    }

    void OnUnitExit(Unit* target) override
    {
        if (!target->IsPlayer())
            return;

        if (target->HasAura(SPELL_MANIFEST_PAIN_AT_DAMAGE))
            target->RemoveAura(SPELL_MANIFEST_PAIN_AT_DAMAGE);
    }
};

void AddSC_boss_council_of_blood()
{
    RegisterCreatureAI(boss_council_of_blood);
    RegisterCreatureAI(npc_afterimage);
    RegisterAreaTriggerAI(at_manifest_pain);
}
