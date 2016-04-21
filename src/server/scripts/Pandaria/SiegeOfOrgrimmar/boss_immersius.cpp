/*
* Copyright (C) 2012-2013 JadeCore <http://www.pandashan.com/>
* Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
* Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

#include "GameObjectAI.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "siege_of_orgrimmar.h"

enum eImmersiusSpells
{
    // 1ST phase
    SPELL_SHA_BOLT_COSMETIC = 129067,
    SPELL_SHA_BOLT_DUMMY = 143290,
    SPELL_SHA_BOLT_MISSILE = 143293,
    SPELL_SHA_BOLT_POOL = 143295, // unused
    // DAFUQ IS WRONG WITH INNTELLISESE
    SPELL_SWIRL_DUMMY = 143309,
    SPELL_SWIRL_DAMAGE = 143412,
    SPELL_CORROSIVE_BLAST = 143436,

    SPELL_SEEPING_SHA_CIRCLE = 143281,

    // 2ND PHASE
    SPELL_SHA_RESIUDE = 143459,
    SPELL_CONGEALING = 143540,
    SPELL_PURIFIED_RESIDUE = 143524,

    SPELL_SEEPING_SHA_VISUAL = 143281,
    SPELL_SEEPING_SHA_DAMAGE = 143286,

    SPELL_ERUPTING_SHA = 143498,

    SPELL_SWIRL_CIRCLE_DUMMY = 143410,
    SPELL_SWIRL_CIRCLE_DAMAGE = 143413,

    SPELL_SPLIT_DUMMY = 143020,
    SPELL_SPLIT_SHA_PUDDLE_THROW = 143022,
    SPELL_SPLIT_CONTEMPLATED_THROW = 143024,

    // HEROIC
    SPELL_SWELLING_CORRUPTION_AURA = 143574,
    SPELL_SWELLING_CORRUPTION_SCRIPT = 143578,
    SPELL_SWELLING_CORRUPTION_SUMMON = 143581,

    SPELL_CORRUPTION_DOT = 143579,

    // 2ND PHASE HC
    SPELL_SHA_POOL_EFFECT = 143462,
    SPELL_SHA_POOL_AURA = 143462,
    SPELL_SHA_POOL_PERIODIC_DAMAGE = 143460,
};
enum eImmersiusTriggers
{
    TRIGGER_SHA_POOL = 71611,
    TRIGGER_SHA_BOLT = 71544,
    TRIGGER_SEEPING_SHA = 324252, // custom made
    TRIGGER_SHA_SPAWNS = 324296,// custom made cuz bravery
    TRIGGER_SHA_SWIRL = 435321,
    TRIGGER_SHA_SWIRL_CIRCLE = 254235,
    CREATURE_SHA_POOL_HC = 716112,
};
enum eImmersiusEvents
{
    EVENT_SHA_BOLT = 100,
    EVENT_SWIRL = 101,
    EVENT_CORRSIVE_BLAST = 102,
    EVENT_SEEPING_SHA = 103,
    EVENT_SPLIT_PHASE = 104,
    EVENT_SWIRL_DE = 105,
    EVENT_SPLIT_PHASE_2 = 106,
};
enum eImmersiusActions
{
    ACTION_COUNT_SPLIT_PHASE = 540,
    ACTION_REMOVE_ENERGY = 541,
};
enum eImmersiusGroups
{
    GROUP_TEARS_OF_THE_VALE = 900, // 1ST PHASE
    GROUP_SPLIT = 901, // 2ND PHASE
};
enum eventsos
{
    EVENT_TALK_1 = 20,
    EVENT_TALK_2 = 22,
    EVENT_TALK_3 = 23,
    EVENT_TALK_4 = 24,
    EVENT_TALK_5 = 25,
    EVENT_TALK_6 = 26,
    EVENT_TALK_7 = 27,
    EVENT_TALK_8 = 28,
    EVENT_TALK_9 = 29,
};

Position immersusfrontdoor = { 1442.74f, 861.203f, 248.994f, 3.519956f };
Position immersusbackdoor2 = { 1442.74f, 861.203f, 248.994f, 3.519956f };

Position circleposition[6] =
{
    { 1447.89f, 828.258f, 246.835f },
    { 1384.38f, 799.616f, 246.784f },
    { 1366.21f, 726.288f, 246.834f },
    { 1482.72f, 682.118f, 246.836f },
    { 1513.86f, 780.797f, 246.835f },
    { 1447.89f, 828.258f, 246.835f },
};
enum Talks
{
    // 1st boss
    TALK_1 = 1, // Ah.. we adventure together again, except this time.. I'm afraid circumstances are much.. more die (38120)
    TALK_2 = 2, // Oh.. what has become of the vale? (38121)
    TALK_3 = 3, // The land is scarred.. the everblooming trees and plants wither and die.. as the water from the pools drains away. (38122)
    TALK_4 = 4, // Come.. let us see what other horrors Garrosh has unleashed upon our land. (38123)
    TALK_5 = 5, // Once the Titans used these life-giving waters, to create and shape all life in Pandaria (38124)
    TALK_6 = 6, // It is these waters that kept the water in bloom, they run off into the the Valley of Four Winds.. created the most furtile farms in the whole world! (38125)
    TALK_7 = 7, // And now.. the Melignants of the old gods has menifested themselves into this old waters (38126)
    TALK_8 = 8, // Such a foul.. foul.. thing.. destroy it, before it seeps deep into the soil, and corrupt all of Pandaria! (38127)
    TALK_9 = 9, // Ah.. you have done it, the waters are pure once more. (38128)

    // 2nd boss
    TALK_10 = 10, // Can you feel the life giving energy flow through you? (38129)
    TALK_11 = 11, // It'll take much time for vale to heal, but you have giving us hope (38130)
    TALK_12 = 12, // Can it be?... Oh no.. no! NO! (38131)
    TALK_13 = 13, // The Golden Lotus?! but.. the pledged their life to defend this place!
};

Position immersus_chest = {1440.66f, 817.257f, 246.835f, 4.679507f};

enum chestsgobjectimmersus
{
    tregularimmersus = 221776,
    thcimmersus = 221778,
    tfregularimmersus = 221779,
    tfhcimmersus = 221780,
    tfraidfinderimmersus = 221781,

    walkercho_bro_2 = 321445,
};

Position afterimmersius_cho_spawn_summon =
{
    1452.132f, 820.978f, 246.835f, 2.879340f
};


class boss_immersus : public CreatureScript
{
public:
    boss_immersus() : CreatureScript("boss_immersus") { }

    struct boss_immersusAI : public BossAI
    {
        boss_immersusAI(Creature* creature) : BossAI(creature, DATA_IMMERSUS)
        {
            pInstance = creature->GetInstanceScript();
            intro = false;
        }

        InstanceScript* pInstance;
        EventMap events;

        Creature* target = NULL;

        uint32 swirlcirculation;
        uint32 currentenergy;
        uint32 swirlhit;
        uint32 count;
        uint32 sheepingsha;
        uint32 berserk;
        bool intro;
        bool swirl;
        bool split;
        bool splitphase;
        bool loot;

        void Reset()
        {
            _Reset();
            events.Reset();
            summons.DespawnAll();

            swirl = false;
            splitphase = false;
            split = true;
            loot = false;

            sheepingsha = 1000;
            swirlcirculation = 1000;
            swirlhit = 2000;
            count = 0;
            currentenergy = 0;
            berserk = 60000 * 10;

            target = NULL;

            me->SetDisplayId(49056);
            me->RemoveAllAuras();

            DespawnCreaturesInArea(71642, me);

            me->AddUnitMovementFlag(MOVEMENTFLAG_ROOT);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);

            me->SetPower(POWER_ENERGY, 100);
            me->SetInt32Value(UNIT_FIELD_POWER, 100);
            me->SetMaxPower(POWER_ENERGY, 100);
            me->SetInt32Value(UNIT_FIELD_MAXPOWER, 100);
            me->RemoveFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_REGENERATE_POWER);

            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);

            // health
            switch (me->GetMap()->GetDifficultyID())
            {
            case DIFFICULTY_10_HC:
                me->SetMaxHealth(87000000);
                break;
            case DIFFICULTY_25_HC:
                me->SetMaxHealth(212000000);
                break;
            case DIFFICULTY_25_N:
                me->SetMaxHealth(250000000);
                break;
            case DIFFICULTY_10_N:
                me->SetMaxHealth(62000000);
                break;
            }
        }
        void MoveInLineOfSight(Unit* who)
        {
            if (who && who->IsInWorld() && who->GetTypeId() == TYPEID_PLAYER && me->IsWithinDistInMap(who, 60.0f) && !intro)
            {
                intro = true;

                if (Creature* Cho = pInstance->instance->GetCreature(pInstance->GetObjectGuid((DATA_LORE_WALKER_CHO_01))))
                {
                    Cho->DespawnOrUnsummon(25000);

                    if (Cho->GetAI())
                    Cho->GetAI()->DoAction(ACTION_LAST_TALK_BEFORE_BOSS);
                }
            }
        }
        void JustReachedHome()
        {
            _JustReachedHome();
            summons.DespawnAll();

            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);;
            instance->SetBossState(DATA_IMMERSUS, FAIL);

            DespawnCreaturesInArea(CREATURE_LESSER_SHA_PUDDLE, me);
            DespawnCreaturesInArea(CREATURE_CONTAMINATED_PUDDLE, me);

            if (GameObject* backdoor = pInstance->instance->GetGameObject(pInstance->GetObjectGuid((DATA_BACK_DOOR_IMMERSUS))))
            {
                backdoor->Delete();
            }
            if (GameObject* frontdoor = pInstance->instance->GetGameObject(pInstance->GetObjectGuid((DATA_FRONT_DOOR_IMMERSUS))))
            {
                frontdoor->Delete();
            }
        }
        void EnterCombat(Unit* attacker)
        {
            if (pInstance)
            {
                pInstance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                DoZoneInCombat();
            }

            DespawnCreaturesInArea(CREATURE_LESSER_SHA_PUDDLE, me);
            DespawnCreaturesInArea(CREATURE_CONTAMINATED_PUDDLE, me);
            DespawnCreaturesInArea(342652, me);

            me->SetPower(POWER_ENERGY, 100);
            me->SetInt32Value(UNIT_FIELD_POWER, 100);
            me->SetMaxPower(POWER_ENERGY, 100);
            me->SetInt32Value(UNIT_FIELD_MAXPOWER, 100);

            me->CastSpell(me, SPELL_SEEPING_SHA_CIRCLE);
            me->CastSpell(me, SPELL_SEEPING_SHA_VISUAL);

            if (me->GetMap()->IsHeroic())
            {
                me->AddAura(143574, me);

                if (Aura* aura = me->GetAura(143574))
                {
                    aura->SetStackAmount(100);
                }
            }

            // 1st phase
            events.ScheduleEvent(EVENT_SHA_BOLT, 8000, GROUP_TEARS_OF_THE_VALE);
            events.ScheduleEvent(EVENT_SWIRL, 20000, GROUP_TEARS_OF_THE_VALE);
            events.ScheduleEvent(EVENT_CORRSIVE_BLAST, urand(12000, 14000), GROUP_TEARS_OF_THE_VALE);
        }
        void JustSummoned(Creature* summon)
        {
            summons.Summon(summon);
        }
        void RegeneratePower(Powers power, int32& value)
        {
            int32 val = me->GetPower(POWER_ENERGY);
            value = 0;
            me->SetInt32Value(UNIT_FIELD_POWER, val);
        }
        void DamageTaken(Unit* attacker, uint32& damage)
        {
            if (!me->IsInCombat())
                return;

            if (me->GetHealthPct() <= 15 && split)
            {
                me->CastStop();
                split = false;

                std::list<Creature*> puddles;
                puddles.clear();

                me->GetCreatureListWithEntryInGrid(puddles, TRIGGER_SHA_POOL, 200.0f);

                for (auto itr : puddles)
                {
                    itr->DespawnOrUnsummon(5000);
                    itr->GetMotionMaster()->MovePoint(0, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ());
                }

                events.ScheduleEvent(EVENT_SPLIT_PHASE, 200);
            }
            if (me->GetMap()->IsHeroic())
            {
                if (!splitphase)
                {
                    if (Aura* ptr_Aura = me->GetAura(143574))
                    {
                        if (ptr_Aura->GetStackAmount() > 1)
                        {
                            ptr_Aura->SetStackAmount(ptr_Aura->GetStackAmount() - 1);

                            me->CastSpell(me, 143581);

                            if (attacker && attacker->IsInWorld() && attacker->IsAlive() && attacker->GetTypeId() == TYPEID_PLAYER)
                            {
                                me->CastSpell(attacker, SPELL_CORRUPTION_DOT);
                            }
                        }
                    }
                }
            }
        }
        void SummonedCreatureDespawn(Creature* summon)
        {
            summons.Despawn(summon);
        }
        void DespawnCreaturesInArea(uint32 entry, WorldObject* object)
        {
            std::list<Creature*> creatures;
            GetCreatureListWithEntryInGrid(creatures, object, entry, 300.0f);
            if (creatures.empty())
                return;

            for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
                (*iter)->DespawnOrUnsummon();
        }
        void JustDied(Unit* killer)
        {
            int32 val = me->GetPower(POWER_ENERGY);

            if (!loot)
            {
                if (val <= 0 || currentenergy >= 99)
                {
                    // chest
                    switch (me->GetMap()->GetDifficultyID())
                    {
                    case DIFFICULTY_10_HC:
                        me->SummonGameObject(thcimmersus, immersus_chest.GetPositionX(), immersus_chest.GetPositionY(), immersus_chest.GetPositionZ(), immersus_chest.GetOrientation(), 0, 0, 0, 0, 0);
                        break;
                    case DIFFICULTY_25_HC:
                        me->SummonGameObject(tfhcimmersus, immersus_chest.GetPositionX(), immersus_chest.GetPositionY(), immersus_chest.GetPositionZ(), immersus_chest.GetOrientation(), 0, 0, 0, 0, 0);
                        break;
                    case DIFFICULTY_25_N:
                        me->SummonGameObject(tfregularimmersus, immersus_chest.GetPositionX(), immersus_chest.GetPositionY(), immersus_chest.GetPositionZ(), immersus_chest.GetOrientation(), 0, 0, 0, 0, 0);
                        break;
                    case DIFFICULTY_10_N:
                        me->SummonGameObject(tregularimmersus, immersus_chest.GetPositionX(), immersus_chest.GetPositionY(), immersus_chest.GetPositionZ(), immersus_chest.GetOrientation(), 0, 0, 0, 0, 0);
                        break;
                    }

                    instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);;
                    instance->SetBossState(DATA_IMMERSUS, DONE);


                    me->CombatStop(true);
                    me->getHostileRefManager().clearReferences();
                    me->CombatStop();
                    me->RemoveAllAuras();
                    me->Respawn();
                    me->setFaction(35);
                    me->SetMaxHealth(100000);
                    me->SetHealth(100000);
                    me->SetDisplayId(49807);

                    me->SummonCreature(walkercho_bro_2, afterimmersius_cho_spawn_summon, TEMPSUMMON_MANUAL_DESPAWN);

                    loot = true;

                    std::list<Player*> pl_list;
                    pl_list.clear();

                    me->GetPlayerListInGrid(pl_list, 100.0f);

                    if (pl_list.empty())
                        return;

                  //  CurrencyOnKillEntry const* Curr = sObjectMgr->GetCurrencyOnKillEntry(me->ToCreature()->GetEntry());
                   // if (!Curr)
                     //   return;

                   /* for (auto itr : pl_list)
                    {
                        if (Curr->currencyId1 && Curr->currencyCount1)
                        {
                            if (CurrencyTypesEntry const* entry = sCurrencyTypesStore.LookupEntry(Curr->currencyId1))
                            {
                                if (Curr->currencyId1 == CURRENCY_TYPE_JUSTICE_POINTS)
                                {
                                    if ((itr->GetCurrency(Curr->currencyId1, true) + Curr->currencyCount1) > itr->GetCurrencyTotalCap(entry))
                                    {
                                        uint32 max = itr->GetCurrencyTotalCap(entry);
                                        uint32 lessPoint = max - itr->GetCurrency(Curr->currencyId1, true);
                                        uint32 rest = Curr->currencyCount1 - lessPoint;

                                        itr->ModifyCurrency(Curr->currencyId1, lessPoint);
                                    }
                                    else
                                        itr->ModifyCurrency(Curr->currencyId1, Curr->currencyCount1);
                                }
                                else
                                    itr->ModifyCurrency(Curr->currencyId1, Curr->currencyCount1);
                            }
                        }
                    }*/
                }
            }
        }
        void Swirl()
        {
            // SWIRL
            if (swirl)
            {
                if (me->HasAura(SPELL_SWIRL_DUMMY))
                {
                    if (Creature* trigger = me->FindNearestCreature(254235, 100.0f, true))
                    {
                        me->SetFacingToObject(trigger);

                        std::list<Player*> pl_list_cone;
                        pl_list_cone.clear();

                        me->GetPlayerListInGrid(pl_list_cone, 200.0f);

                        if (pl_list_cone.empty())
                            return;

                        for (auto itr : pl_list_cone)
                        {
                            if (itr->IsWithinDistInMap(trigger, 20.0f))
                            {
                                itr->CastSpell(itr, SPELL_SWIRL_DAMAGE, true);

                                if (Aura* aura = itr->GetAura(SPELL_SWIRL_DAMAGE))
                                    aura->SetDuration(1); // two hits per amplitude, that's bad, need to change it 400 millseconds.
                            }
                        }
                    }
                }
            }
        }
        void SeepingSha()
        {
            std::list<Player*> pl_list_cone;
            me->GetPlayerListInGrid(pl_list_cone, 0.6f);

            if (pl_list_cone.empty())
                return;

            for (auto itr : pl_list_cone)
            {
                itr->CastSpell(itr, SPELL_SEEPING_SHA_DAMAGE);

                if (Aura* aura = itr->GetAura(SPELL_SEEPING_SHA_DAMAGE))
                    aura->SetDuration(1); // two hits per amplitude, that's bad, need to change it 400 millseconds.
            }
        }
        void DoAction(const int32 action)
        {
            switch (action)
            {
            case ACTION_COUNT_SPLIT_PHASE:
                if (!me->IsInCombat())
                    return;

                count++;

                if (count >= 24)
                {
                    events.Reset();
                    me->RemoveAura(143462);
                    me->RemoveAllAuras();

                    DespawnCreaturesInArea(CREATURE_SHA_POOL_HC, me);

                    me->CastSpell(me, SPELL_SEEPING_SHA_CIRCLE);
                    me->CastSpell(me, SPELL_SEEPING_SHA_VISUAL);

                    events.ScheduleEvent(EVENT_SHA_BOLT, 8000, GROUP_TEARS_OF_THE_VALE);
                    events.ScheduleEvent(EVENT_SWIRL, 20000, GROUP_TEARS_OF_THE_VALE);
                    events.ScheduleEvent(EVENT_CORRSIVE_BLAST, urand(12000, 14000), GROUP_TEARS_OF_THE_VALE);
                    events.ScheduleEvent(EVENT_SEEPING_SHA, 10000, GROUP_TEARS_OF_THE_VALE);

                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);


                    int32 val = me->GetPower(POWER_ENERGY);
                    val -= currentenergy;

                    me->SetInt32Value(UNIT_FIELD_POWER, val);

                    uint32 health = me->GetMaxHealth() * 0.01;
                    uint32 newhealth = me->GetMaxHealth() - health;

                    me->SetMaxHealth(newhealth);
                    me->SetHealth(newhealth);

                    if (me->GetMap()->IsHeroic())
                    {
                        me->AddAura(143574, me);

                        if (Aura* aura = me->GetAura(143574))
                        {
                            aura->SetStackAmount(val);
                        }
                    }
                    split = true;
                    splitphase = false;

                    if (!loot)
                    {
                        if (val <= 0 || currentenergy >= 99)
                        {


                            // chest
                            switch (me->GetMap()->GetDifficultyID())
                            {
                            case DIFFICULTY_10_HC:
                                me->SummonGameObject(thcimmersus, immersus_chest.GetPositionX(), immersus_chest.GetPositionY(), immersus_chest.GetPositionZ(), immersus_chest.GetOrientation(), 0, 0, 0, 0, 0);
                                break;
                            case DIFFICULTY_25_HC:
                                me->SummonGameObject(tfhcimmersus, immersus_chest.GetPositionX(), immersus_chest.GetPositionY(), immersus_chest.GetPositionZ(), immersus_chest.GetOrientation(), 0, 0, 0, 0, 0);
                                break;
                            case DIFFICULTY_25_N:
                                me->SummonGameObject(tfregularimmersus, immersus_chest.GetPositionX(), immersus_chest.GetPositionY(), immersus_chest.GetPositionZ(), immersus_chest.GetOrientation(), 0, 0, 0, 0, 0);
                                break;
                            case DIFFICULTY_10_N:
                                me->SummonGameObject(tregularimmersus, immersus_chest.GetPositionX(), immersus_chest.GetPositionY(), immersus_chest.GetPositionZ(), immersus_chest.GetOrientation(), 0, 0, 0, 0, 0);
                                break;
                            }

                            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);;
                            instance->SetBossState(DATA_IMMERSUS, DONE);


                            me->CombatStop(true);
                            me->getHostileRefManager().clearReferences();
                            me->CombatStop();
                            me->RemoveAllAuras();
                            me->Respawn();
                            me->setFaction(35);
                            me->SetMaxHealth(8000);
                            me->SetHealth(8000);
                            me->SetDisplayId(49807);

                            loot = true;
                        }
                    }
                }
                break;
            case ACTION_REMOVE_ENERGY:
                if (!me->IsInCombat())
                    return;

                currentenergy++;

                int32 val = me->GetPower(POWER_ENERGY);
                break;
            }
        }
        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (berserk <= diff)
            {
                me->CastSpell(me, 64238);
                berserk = 32432234;
            }
            else
                berserk -= diff;

            if (swirlhit <= diff)
            {
                Swirl();
                swirlhit = 3000;
            }
            else
                swirlhit -= diff;

            if (sheepingsha <= diff)
            {
                SeepingSha();
                sheepingsha = 4500;
            }
            else
                sheepingsha -= diff;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            switch (events.ExecuteEvent())
            {
            case EVENT_SHA_BOLT:
            {
                me->CastSpell(me, 143290);

                std::list<Player*> pl_list;
                pl_list.clear();

                me->GetPlayerListInGrid(pl_list, 300.0f);

                if (pl_list.empty())
                    return;

                for (auto itr : pl_list)
                {
                    me->CastSpell(itr, SPELL_SHA_BOLT_COSMETIC);
                }

                events.ScheduleEvent(EVENT_SHA_BOLT, 10000, GROUP_TEARS_OF_THE_VALE);
                break;
            }
            case EVENT_SWIRL_DE:
                swirl = false;
                break;
            case EVENT_SWIRL:
            {
                for (int i = 0; i <= 50; i++)
                {
                    Position pos;
                    me->GetRandomNearPosition(100.0f);

                    me->SummonCreature(TRIGGER_SHA_SWIRL, pos, TEMPSUMMON_TIMED_DESPAWN, 30000);
                }
                target = NULL;

                swirl = true;

                uint32 rando;

                if(roll_chance_i(50))
                {
                    rando = 1;
                }
                else
                {
                    rando = 4;
                }

                DespawnCreaturesInArea(TRIGGER_SHA_SWIRL_CIRCLE, me);

                Creature* trigger = me->SummonCreature(TRIGGER_SHA_SWIRL_CIRCLE, circleposition[rando], TEMPSUMMON_MANUAL_DESPAWN);
                target = trigger;

                me->CastSpell(trigger, SPELL_SWIRL_DUMMY);
                events.ScheduleEvent(EVENT_SWIRL_DE, 10000);
                events.ScheduleEvent(EVENT_SWIRL, 40000, GROUP_TEARS_OF_THE_VALE);
                break;
            }
            case EVENT_CORRSIVE_BLAST:
                me->SetFacingToObject(me->GetVictim());


                me->CastSpell(me->GetVictim(), SPELL_CORROSIVE_BLAST);
                events.ScheduleEvent(EVENT_CORRSIVE_BLAST, 42000, GROUP_TEARS_OF_THE_VALE);
                break;
            case EVENT_SEEPING_SHA:
                for (int i = 0; i <= 5; i++)
                {
                    Position pos;
                    me->GetRandomNearPosition(35.0f); // estimated?

                    me->SummonCreature(TRIGGER_SEEPING_SHA, pos, TEMPSUMMON_TIMED_DESPAWN, 20000);
                }
                events.ScheduleEvent(EVENT_SEEPING_SHA, 20000, GROUP_TEARS_OF_THE_VALE);
                break;
                // 2ND PHASE
            case EVENT_SPLIT_PHASE:
                events.ScheduleEvent(EVENT_SPLIT_PHASE_2, 1000);
                split = false;
                splitphase = true;

                me->SetHealth(me->GetMaxHealth());
                DespawnCreaturesInArea(71544, me);

                me->SummonCreature(CREATURE_SHA_POOL_HC, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);

                me->CastSpell(me, SPELL_SPLIT_DUMMY);

                if (Aura* aura = me->GetAura(SPELL_SPLIT_DUMMY))
                {
                    aura->SetDuration(500000);
                }

                events.CancelEvent(EVENT_SPLIT_PHASE);
                break;
            case EVENT_SPLIT_PHASE_2:
                //me->SetDisplayId(11686);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);

                for (int i = 0; i <= 12; i++)
                {
                    me->CastSpell(me, SPELL_SPLIT_SHA_PUDDLE_THROW, true);
                    me->CastSpell(me, SPELL_SPLIT_CONTEMPLATED_THROW, true);
                }

                count = 0;

                events.CancelEvent(EVENT_SPLIT_PHASE);
                events.Reset();
                break;
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_immersusAI(creature);
    }
};
class immersius_spell_sha_bolt_missile : public SpellScriptLoader
{
public:
    immersius_spell_sha_bolt_missile() : SpellScriptLoader("immersius_spell_sha_bolt_missile") { }

    class soo_spells : public SpellScript
    {
        PrepareSpellScript(soo_spells);

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (!GetCaster() && !GetHitUnit())
                return;

            int32 calc = 30000;
            GetCaster()->CastCustomSpell(GetHitUnit(), 131376, &calc, NULL, NULL, true, NULL);

            GetHitUnit()->CastSpell(GetHitUnit(), SPELL_SHA_BOLT_MISSILE);
            GetHitUnit()->SummonCreature(TRIGGER_SHA_POOL, GetHitUnit()->GetPositionX(), GetHitUnit()->GetPositionY(), GetHitUnit()->GetPositionZ(), GetHitUnit()->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 25000);
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(soo_spells::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new soo_spells();
    }
};
class immersius_spell_split : public SpellScriptLoader
{
public:
    immersius_spell_split() : SpellScriptLoader("immersius_spell_split") { }

    class soo_spells : public SpellScript
    {
        PrepareSpellScript(soo_spells);

        void HandleScript(SpellEffIndex effIndex)
        {
            PreventHitDefaultEffect(effIndex);

            if (!GetCaster())
                return;
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(soo_spells::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new soo_spells();
    }
};
class immersus_trigger_sha_pool : public CreatureScript
{
public:
    immersus_trigger_sha_pool() : CreatureScript("immersus_trigger_sha_pool") { }

    struct soo_triggers : public BossAI
    {
        soo_triggers(Creature* creature) : ScriptedAI(creature)
        {
            pInstance = creature->GetInstanceScript();
        }

        InstanceScript* pInstance;
        EventMap events;

        uint32 interval;

        void Reset()
        {
            interval = 1200;
            me->setFaction(16);

            me->CastSpell(me, SPELL_SHA_POOL_AURA);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
            me->AddUnitMovementFlag(MOVEMENTFLAG_ROOT);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
            me->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_DISABLE_TURN);
        }
        void DamageTaken(Unit* /*attacker*/, uint32& damage)
        {
            damage = 0;
        }
        void UpdateAI(const uint32 diff)
        {
            // damage
            if (interval <= diff)
            {
                std::list<Player*> list_players;
                me->GetPlayerListInGrid(list_players, 1.0f);

                if (list_players.empty())
                    return;

                for (auto itr : list_players)
                {
                    itr->CastSpell(itr, 143460);
                }

                interval = 1200;
            }
            else
                interval -= diff;
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new soo_triggers(creature);
    }
};
class immersus_trigger_sha_swirl_circular : public CreatureScript
{
public:
    immersus_trigger_sha_swirl_circular() : CreatureScript("immersus_trigger_sha_swirl_circular") { }

    struct soo_triggers : public ScriptedAI
    {
        soo_triggers(Creature* creature) : ScriptedAI(creature)
        {
            pInstance = creature->GetInstanceScript();
        }

        InstanceScript* pInstance;
        EventMap events;

        uint32 interval;

        void Reset()
        {
            interval = 2000;
            me->setFaction(16);

            events.ScheduleEvent(TALK_1, 2000);

            me->SetSpeed(MOVE_RUN, 3.0f);
            me->SetReactState(REACT_PASSIVE);

            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
            me->GetMotionMaster()->MovePoint(0, circleposition[0].GetPositionX(), circleposition[0].GetPositionY(), circleposition[0].GetPositionZ());
        }
        void DamageTaken(Unit* /*attacker*/, uint32& damage)
        {
            damage = 0;
        }
        void UpdateAI(const uint32 diff)
        {
            events.Update(diff);

            switch (events.ExecuteEvent())
            {
            case EVENT_TALK_1:
            {
                events.ScheduleEvent(TALK_2, 2000);
                me->GetMotionMaster()->MovePoint(1, circleposition[1].GetPositionX(), circleposition[1].GetPositionY(), circleposition[1].GetPositionZ());
                break;
            }
            case EVENT_TALK_2:
            {
                events.ScheduleEvent(TALK_3, 2000);
                me->GetMotionMaster()->MovePoint(1, circleposition[2].GetPositionX(), circleposition[2].GetPositionY(), circleposition[2].GetPositionZ());
                break;
            }
            case EVENT_TALK_3:
            {
                events.ScheduleEvent(TALK_4, 2000);
                me->GetMotionMaster()->MovePoint(1, circleposition[3].GetPositionX(), circleposition[3].GetPositionY(), circleposition[3].GetPositionZ());
                break;
            }
            case EVENT_TALK_4:
            {
                events.ScheduleEvent(TALK_5, 2000);
                me->GetMotionMaster()->MovePoint(1, circleposition[4].GetPositionX(), circleposition[4].GetPositionY(), circleposition[4].GetPositionZ());
                break;
            }
            case EVENT_TALK_5:
            {
                events.ScheduleEvent(TALK_6, 2000);
                me->GetMotionMaster()->MovePoint(1, circleposition[5].GetPositionX(), circleposition[5].GetPositionY(), circleposition[5].GetPositionZ());
                break;
            }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new soo_triggers(creature);
    }
};
class immersus_trigger_swirl_circle : public CreatureScript
{
public:
    immersus_trigger_swirl_circle() : CreatureScript("immersus_trigger_swirl_circle") { }

    struct soo_triggers : public ScriptedAI
    {
        soo_triggers(Creature* creature) : ScriptedAI(creature)
        {
            pInstance = creature->GetInstanceScript();
        }

        InstanceScript* pInstance;
        EventMap events;

        uint32 interval;
        uint32 move;

        void Reset()
        {
            interval = 3000;
            move = 1000;
            me->setFaction(16);

            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
            me->CastSpell(me, SPELL_SWIRL_CIRCLE_DUMMY);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
            me->AddUnitMovementFlag(MOVEMENTFLAG_ROOT);
            me->SetReactState(REACT_PASSIVE);
        }
        void DamageTaken(Unit* /*attacker*/, uint32& damage)
        {
            damage = 0;
        }
        void UpdateAI(const uint32 diff)
        {
            if (interval <= diff)
            {
                me->CastSpell(me, 147181);

                interval = 8000;
            }
            else
                interval -= diff;
            /*
            // damage
            if (interval <= diff)
            {
                std::list<Player*> list_players;
                list_players.clear();

                me->GetPlayerListInGrid(list_players, 1.0f);

                if (list_players.empty())
                    return;

                for (auto itr : list_players)
                {
                    itr->CastSpell(itr, SPELL_SWIRL_CIRCLE_DAMAGE);

                    if (AuraPtr aura = itr->GetAura(SPELL_SWIRL_CIRCLE_DAMAGE))
                        aura->SetDuration(1);
                }

                interval = 1000;
            }
            else
                interval -= diff;

            if (move <= diff)
            {
                me->GetMotionMaster()->MoveRandom(30.0f);
                move = 3500;
            }
            else
                move -= diff;
                */
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new soo_triggers(creature);
    }
};
class immersus_creature_contaminated_puddle : public CreatureScript
{
public:
    immersus_creature_contaminated_puddle() : CreatureScript("immersus_creature_contaminated_puddle") { }

    struct soo_triggers : public ScriptedAI
    {
        soo_triggers(Creature* creature) : ScriptedAI(creature)
        {
            Instance = creature->GetInstanceScript();
        }

        InstanceScript* Instance;
        EventMap events;

        uint32 interval;
        uint32 move;
        bool reached;
        bool health;

        void Reset()
        {
            interval = 5000;
            move = 1000;
            me->setFaction(35);
            me->SetSpeed(MOVE_RUN, 0.4f);

            me->SetReactState(REACT_PASSIVE);
            me->RemoveFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_REGENERATE_POWER);
            reached = false;
            health = false;

            // health
            switch (me->GetMap()->GetDifficultyID())
            {
            case DIFFICULTY_10_HC:
                me->SetMaxHealth(548000);
                break;
            case DIFFICULTY_25_HC:
                me->SetMaxHealth(750000);
                break;
            case DIFFICULTY_25_N:
                me->SetMaxHealth(1000000);
                break;
            }

            me->SetHealth(me->GetMaxHealth() * 0.10);
        }
        void JustDied(Unit* /*killer*/) override
        {
            if (Creature* immersius = Instance->instance->GetCreature(Instance->GetObjectGuid(DATA_IMMERSUS)))
            {
                immersius->AI()->DoAction(ACTION_COUNT_SPLIT_PHASE);
            }
        }
        void UpdateAI(const uint32 diff)
        {
            if (Creature* immersius = Instance->instance->GetCreature(Instance->GetObjectGuid(DATA_IMMERSUS)))
                if (!immersius->IsInCombat())
                    return;

            if (Creature* immersius = Instance->instance->GetCreature(Instance->GetObjectGuid(DATA_IMMERSUS)))
            {
                if (immersius->IsWithinDistInMap(me, 5.0))
                {
                    if (!reached)
                    {
                        me->DespawnOrUnsummon(4000);

                        immersius->AI()->DoAction(ACTION_COUNT_SPLIT_PHASE);

                        if (me->GetHealth() == me->GetMaxHealth())
                        {
                            immersius->AI()->DoAction(ACTION_REMOVE_ENERGY);
                        }

                        reached = true;
                    }
                }
            }

            // Congealing effect.
            if (Aura* aura = me->GetAura(143540))
            {
                int32 pct = float(me->GetHealthPct());

                switch (pct)
                {
                case 10:
                    aura->SetStackAmount(1);
                    break;
                case 20:
                    aura->SetStackAmount(2);
                    break;
                case 30:
                    aura->SetStackAmount(3);
                    break;
                case 40:
                    aura->SetStackAmount(4);
                    break;
                case 50:
                    aura->SetStackAmount(5);
                    break;
                case 60:
                    aura->SetStackAmount(6);
                    break;
                case 70:
                    aura->SetStackAmount(7);
                    break;
                case 80:
                    aura->SetStackAmount(8);
                    break;
                case 90:
                    aura->SetStackAmount(9);
                    break;
                }
            }

            if (!health)
            {
                if (me->GetHealth() == me->GetMaxHealth())
                {
                    std::list<Player*> pl_list;
                    me->GetPlayerListInGrid(pl_list, 200.0f);

                    if (pl_list.empty())
                        return;

                    for (auto itr : pl_list)
                    {
                        itr->CastSpell(itr, SPELL_PURIFIED_RESIDUE);
                    }

                    health = true;
                }
            }

            if (!me->isMoving())
                if (Creature* immersius = Instance->instance->GetCreature(Instance->GetObjectGuid(DATA_IMMERSUS)))
                    me->GetMotionMaster()->MovePoint(0, immersius->GetPositionX(), immersius->GetPositionY(), immersius->GetPositionZ());

        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new soo_triggers(creature);
    }
};
class immersus_creature_sha_puddle : public CreatureScript
{
public:
    immersus_creature_sha_puddle() : CreatureScript("immersus_creature_sha_puddle") { }

    struct soo_triggers : public ScriptedAI
    {
        soo_triggers(Creature* creature) : ScriptedAI(creature)
        {
            Instance = creature->GetInstanceScript();
        }

        InstanceScript* Instance;
        EventMap events;

        uint32 interval;
        uint32 move;
        bool reached;

        void Reset()
        {
            interval = 5000;
            move = 1000;
            me->setFaction(16);
            me->SetSpeed(MOVE_RUN, 0.4f);
            me->SetReactState(REACT_PASSIVE);
            reached = false;

            // health
            switch (me->GetMap()->GetDifficultyID())
            {
            case DIFFICULTY_10_HC:
                me->SetMaxHealth(515000);
                break;
            case DIFFICULTY_25_HC:
                me->SetMaxHealth(1000000);
                break;
            case DIFFICULTY_25_N:
                me->SetMaxHealth(632000);
                break;
            }
        }
        void JustDied(Unit* /*killer*/) override
        {
            if (Creature* immersius = Instance->instance->GetCreature(Instance->GetObjectGuid(DATA_IMMERSUS)))
            {
                if (!immersius->IsInCombat())
                    return;

                immersius->AI()->DoAction(ACTION_COUNT_SPLIT_PHASE);
                immersius->AI()->DoAction(ACTION_REMOVE_ENERGY);

                std::list<Player*> players;
                players.clear();

                me->GetPlayerListInGrid(players, 300.0f);

                if (players.empty())
                    return;

                for (auto itr : players)
                {
                    if (!itr->HasAura(SPELL_SHA_RESIUDE))
                    {
                        itr->AddAura(SPELL_SHA_RESIUDE, itr);
                    }
                    else
                    {
                        Aura* aura = itr->GetAura(SPELL_SHA_RESIUDE);

                        if (aura)
                        {
                            aura->SetStackAmount(aura->GetStackAmount() + 1);
                        }
                    }
                }
            }
        }
        void DamageTaken(Unit* attacker, uint32& damage)
        {
            if (attacker && attacker->IsInWater())
            {
                if (attacker->HasAura(143459))
                {
                    if (Aura* aura = me->GetAura(143459))
                    {
                        if (aura->GetStackAmount() > 1)
                        {
                            damage = damage + (damage * (0.25 * aura->GetStackAmount()));
                        }
                        else
                        {
                            damage = damage + (damage * 0.25);
                        }
                    }
                }
            }
        }
        void UpdateAI(const uint32 diff)
        {
            if (Creature* immersius = Instance->instance->GetCreature(Instance->GetObjectGuid(DATA_IMMERSUS)))
                if (immersius->IsWithinDistInMap(me, 5.0))
                {
                    if (!reached)
                    {
                        me->DespawnOrUnsummon(4000);
                        immersius->AI()->DoAction(ACTION_COUNT_SPLIT_PHASE);
                        reached = true;

                        if (immersius->IsInCombat())
                        immersius->CastSpell(immersius, SPELL_ERUPTING_SHA);
                    }
                }

            if (!me->isMoving())
                if (Creature* immersius = Instance->instance->GetCreature(Instance->GetObjectGuid(DATA_IMMERSUS)))
                    me->GetMotionMaster()->MovePoint(0, immersius->GetPositionX(), immersius->GetPositionY(), immersius->GetPositionZ());
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new soo_triggers(creature);
    }
};
class immersus_creature_sha_pool_heroic : public CreatureScript
{
public:
    immersus_creature_sha_pool_heroic() : CreatureScript("immersus_creature_sha_pool_heroic") { }

    struct soo_triggers : public BossAI
    {
        soo_triggers(Creature* creature) : ScriptedAI(creature)
        {
            Instance = creature->GetInstanceScript();
        }

        InstanceScript* Instance;
        EventMap events;

        uint32 size;
        uint32 damage;
        bool reached;

        void Reset()
        {
            damage = 4000;
            size = 2500;

            me->CastSpell(me, SPELL_SHA_POOL_AURA);
            me->setFaction(16);
            me->SetReactState(REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);

            me->SetObjectScale(10.0f);
        }
        void UpdateAI(const uint32 diff)
        {
            float radius = 5;
            float scale = me->GetObjectSize();

            radius += scale;

            if (damage <= diff)
            {
                std::list<Player*> list_p;

                list_p.clear();
                me->GetPlayerListInGrid(list_p, radius);

                if (list_p.empty())
                    return;

                for (auto itr : list_p)
                {
                    me->CastSpell(itr, SPELL_SHA_POOL_PERIODIC_DAMAGE);
                }

                damage = urand(3500, 6000);
            }
            else
                damage -= diff;

        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new soo_triggers(creature);
    }
};
class immersus_creature_swelling_creature : public CreatureScript
{
public:
    immersus_creature_swelling_creature() : CreatureScript("immersus_creature_swelling_creature") { }

    struct soo_triggers : public ScriptedAI
    {
        soo_triggers(Creature* creature) : ScriptedAI(creature)
        {
            Instance = creature->GetInstanceScript();
        }

        InstanceScript* Instance;
        EventMap events;

        uint32 size;
        uint32 damage;
        bool reached;

        void Reset()
        {
            me->SetReactState(REACT_AGGRESSIVE);
            me->setFaction(16);

           /* if (Player* nearest = me->Get me->FindNearestPlayer(200, true))
            {
                me->GetMotionMaster()->MovePoint(0, nearest->GetPositionX(), nearest->GetPositionY(), nearest->GetPositionZ());
            }*/
        }
        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new soo_triggers(creature);
    }
};
class damage_bool_to_remove_boss
{
public:
    explicit damage_bool_to_remove_boss(WorldObject* _caster) : caster(_caster) { }
    bool operator() (WorldObject* unit)
    {
        if (unit->GetTypeId() == TYPEID_PLAYER)
            return false;

        return true;
    }

private:
    WorldObject* caster;
};
class spell_sha_erupting_damage : public SpellScriptLoader
{
public:
    spell_sha_erupting_damage() : SpellScriptLoader("spell_sha_erupting_damage") { }

    class spell_sha_erupting_damage_spell_script : public SpellScript
    {
        PrepareSpellScript(spell_sha_erupting_damage_spell_script);

        void CorrectTargets(std::list<WorldObject*>& targets)
        {
            if (targets.empty())
                return;

            if (!GetCaster())
                return;

            for (auto itr : targets)
            {
                if (itr->GetEntry() == BOSS_IMMERSUS)
                    targets.remove(itr);
            }
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_erupting_damage_spell_script::CorrectTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_erupting_damage_spell_script::CorrectTargets, EFFECT_0, TARGET_SRC_CASTER);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_sha_erupting_damage_spell_script();
    }
};
class spell_swirl_target : public SpellScriptLoader
{
public:
    spell_swirl_target() : SpellScriptLoader("spell_swirl_target") { }

    class spell_swirl_target_spell_script : public SpellScript
    {
        PrepareSpellScript(spell_swirl_target_spell_script);

        void CorrectTargets(std::list<WorldObject*>& targets)
        {
            if (targets.empty())
                return;

            targets.clear();

            if (Creature* trigger = GetCaster()->FindNearestCreature(254235, 300.0F, true))
                targets.push_back(trigger);
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_swirl_target_spell_script::CorrectTargets, EFFECT_0, TARGET_UNIT_NEARBY_ENTRY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_swirl_target_spell_script();
    }
};

void AddSC_immersus()
{
    // boss
    new boss_immersus();

    // creatures
    new immersus_creature_sha_puddle();
    new immersus_creature_contaminated_puddle();
    new immersus_creature_sha_pool_heroic();
    new immersus_creature_swelling_creature();

    new spell_swirl_target();
    new spell_sha_erupting_damage();

    // spells
    new immersius_spell_split();
    new immersius_spell_sha_bolt_missile();

    // triggers
    new immersus_trigger_swirl_circle();
    new immersus_trigger_sha_pool();
    new immersus_trigger_sha_swirl_circular();
}
