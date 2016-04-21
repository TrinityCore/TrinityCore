
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
#include "GridNotifiers.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "siege_of_orgrimmar.h"

Position afterimmersius_cho_spawn[4] =
{
    { 1452.132f, 820.978f, 246.835f, 2.879340f },
    { 1444.54f, 985.199f, 339.831f },
    { 1435.78f, 1038.228f, 340.378f },
    { 1289.39f, 4038.764f, 434.519f },
};

void Fallen_StartProtectors(InstanceScript* instance, Creature* me, Unit* /*target*/)
{
    Creature* rook = instance->instance->GetCreature(instance->GetObjectGuid(DATA_STONE));
    if (rook)
        rook->SetInCombatWithZone();

    Creature* sun = instance->instance->GetCreature(instance->GetObjectGuid(DATA_SUN));
    if (sun)
        sun->SetInCombatWithZone();

    Creature* hu = instance->instance->GetCreature(instance->GetObjectGuid(DATA_HU));
    if (hu)
        hu->SetInCombatWithZone();
}
enum eFGobjects
{
    GOBJECT_CHEST_10_MAN = 135351,
    GOBJECT_CHEST_10_HEROIC = 135352,
    GOBJECT_CHEST_25_MAN = 135353,
    GOBJECT_CHEST_25_HEROIC = 135354,
};
enum eFEvents
{
    // Rook Stonetoe
    EVENT_VENGEFUL_STRIKES = 10,
    EVENT_CORRUPTED_BREW = 11,
    EVENT_CLASH = 12,
    EVENT_CORRUPTION_KICK = 13,
    // Desperate
    EVENT_DEFILED_GROUND = 30,
    EVENT_INFERNO_STRIKE = 31,
    EVENT_CORRUPTION_SHOCK = 32,
    // He Softfoot
    EVENT_GARROTE = 14,
    EVENT_GOUGE = 15,
    EVENT_NOXIOUS_POISION = 16,
    EVENT_INSTANT_POISION = 17,
    // Desperate
    EVENT_MARK_OF_ANGUISH = 33,
    EVENT_SHADOW_WEAKNESS = 34,
    EVENT_DEBILITATION = 35,
    EVENT_CHOOSE_VICTIM = 100,
    // Sun Tenderheart
    EVENT_SHA_FEAR = 18,
    EVENT_SHADOW_WORD_BANE = 19,
    EVENT_CALAMITY = 20,
    // Desperate
    EVENT_DARK_MEDITATION = 36,
    EVENT_DESPAIR_SPAWNS = 37,
    EVENT_DEATH_SITUATION = 38,
    EVENT_BOND_OF_THE_GOLDEN_LOTUS_COUNT = 39,
};
enum eFSpells
{
    SPELL_BOND_OF_THE_GOLDEN_LOTUS = 143497,

    SPELL_VENGFUL_STRIKES_DUMMY = 144437,
    SPELL_VENGFUL_STRIKES_DAMAGE = 144397,
    SPELL_VENGFUL_STRIKES_POSSES_AURA = 144396,
    SPELL_CORRUPTED_BREW_DUMMY = 145608,
    SPELL_CLASH_DUMMY = 143027,
    SPELL_CLASH_DAMAGE_JUMP = 143028,
    SPELL_CLASH_CHARGE = 143030,
    SPELL_CORRUPTION_KICK_AURA = 143007,
    SPELL_CORRUPTION_KICK_DAMAGE = 143009,
    SPELL_CORRUPTION_KICK_DEBUFF = 143010,

    // Stone - desperate measures
    SPELL_DEFILED_GROUND_AURA = 143959,
    SPELL_DEFILED_GROUND_AREA_TRIGGER = 143960,
    SPELL_DEFILED_GROUND_DAMAGE = 143961, // 144357 ?

    SPELL_INFERNO_STRIKE_DUMMY = 143962,

    SPELL_CORRUPTION_SHOCK_DUMMY = 143958,
    SPELL_CORRUPTION_SHOCK_DAMAGE = 144018,
    SPELL_CORRUPTION_SHOCK_MISSILE = 144020,

    SPELL_GOUGE_KNOCKBACK = 143331,
    SPELL_GOUGE_DUMMY = 143330,
    SPELL_GOUGE_DAMAGE = 143301,

    SPELL_GARROTE = 143198,
    SPELL_SHADOWSTEP = 55966,
    SPELL_MARK_OF_ANGUISH_AURA = 143812,
    SPELL_MARK_OF_ANGUISH_DAMAGE = 144365,
    SPELL_MARK_OF_ANGUISH_PLAYER_DOT = 143840,

    SPELL_DEBILLITATION = 147383,
    SPELL_NOXIOUS_POISON_DOT = 143239,
    SPELL_NOXIOUS_POISON_AREA_TRIGGER = 143235,
    SPELL_NOXIOUS_POISON_DAMAGE = 144367,
    SPELL_INSANT_POISON = 143210,

    SPELL_SHA_SEAR = 143423,
    SPELL_SHADOW_WORD_BANE_DOT = 143434,
    SPELL_SHADOW_WORD_BANE_JUMP = 143879,
    SPELL_CALAMITY_DUMMY = 143491,
    SPELL_CALAMITY_DAMAGE = 143493,

    SPELL_DARK_MEDITATION_DUMMY = 143546,
    SPELL_DARK_MEDITATION_TICK = 143559,
    SPELL_DARK_MEDITATION_SHIELD = 143728,
    SPELL_DARK_MEDITATION_VISUAL = 143843,

    SPELL_SHA_CORRUPTION = 120000,
};
enum eFActions
{
    ACTION_GOLDEN_LOTUS = 500,
    ACTION_COUNT_ADDS_DEATH = 501,
    ACTION_DESPERATE_METHOD_ACTIVATE = 502,
    ACTION_DESPERATE_METHOD_DEACTIVATE = 503,
    ACTION_WIN_SITUATION = 504,
};
enum eFTriggers
{

};
enum eFCreatures
{
    CREATURE_EMBODIED_MISERY = 71476,
    CREATURE_EMBODIED_SORROW = 71481,
    CREATURE_EMBODIED_GLOOM = 71477,
    CREATURE_MARK_OF_ANGUISH = 71478,
    CREATURE_DESPAIR_SPAWN = 71712,
};
enum eFTalks
{
    TALK_SUN_AGGRO = 1, // 38413 "Will you success"
    TALK_SUN_DEATH = 2, // 38414 "We return to when we lost our way.. You are... very kind"
    TALK_SUN_INTRO = 3, // 38415 "We only know despair now, a fitting punishment for our failure"
    TALK_SUN_KILL = 4, // 38416 "You too have failed!"
    TALK_SUN_RESET = 5, // 38417 "We'll never find solace"
    TALK_SUN_SPELL_01 = 6, // 38418 "We must redeem the vale"
    TALK_SUN_SPELL_02 = 7, // 38419 "You'll suffer for our failure"
    TALK_SUN_SPELL_03 = 8, // 38420 "Protectors come to my aid!"
    TALK_SUN_SPELL_04 = 9, // 38421 "We'll not forgive our oath"

    TALK_ROOK_AGGRO = 10, // 38176 "Sun.. Hei... Aid me!
    TALK_ROOK_DEATH = 11, // 38177 "Feeling.. better.. now, little friend."
    TALK_ROOK_INTRO = 12, // 38178 "You... Rook.. knows you."
    TALK_ROOK_INTRO2 = 13, // 38720 "Rook... doesn't know.. head's cloudy"
    TALK_ROOK_INTRO3 = 14, // 38722 "Please.. help..."
    TALK_ROOK_KILL = 15, // 38724 "You! are not my friend!"
    TALK_ROOK_SPELL_01 = 16, // 38725 "Brawl! with rook!"
    TALK_ROOK_SPELL_02 = 17, // 38726 "ROOK FIGHT!"
    TALK_ROOK_SPELL_03 = 18, // 38727 "Rook needs... HELPPP!"
    TALK_ROOK_SPELL_04 = 19, // 38728 "Rook... not.. Safe!"

    // cho
    TALK_9 = 20, // Ah.. you have done it, the waters are pure once more. (38128)
    // 2nd boss
    TALK_10 = 21, // Can you feel the life giving energy flow through you? (38129)
    TALK_11 = 22, // It'll take much time for vale to heal, but you have giving us hope (38130)
    TALK_12 = 23, // Can it be?... Oh no.. no! NO! (38131)
    TALK_13 = 24, // The Golden Lotus?! but.. the pledged their life to defend this place! (38132)
    TALK_14 = 25, // Oh.. Rook stonetoe! you remember me! What has happened to you? (38133)
    TALK_15 = 26, // I see.. this Sha energy has trapped their spirits here to endlessely relive their failure, It weads on their despair. (38134)
    TALK_16 = 27, // This is a fate far worse then death.. please.. Heroes, set their souls free! (38135)
};
enum eventsose
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
    EVENT_TALK_10 = 30,
};

Position chestposition = { 1215.03f, 1001.684f, 418.062f, 1.753704f };
/*
class boss_rook;
class boss_hu;
class boss_sun;
*/

Position bubbleaddspos[2] =
{
    { 1219.41f, 1063.98f, 417.963f, 4.609289f },
    { 1236.79f, 1029.65f, 418.076f, 22.54114f },
};

class siege_of_orgrimmar_lorewalker_cho_second_part : public CreatureScript
{
public:
    siege_of_orgrimmar_lorewalker_cho_second_part() : CreatureScript("siege_of_orgrimmar_lorewalker_cho_second_part") { }

    struct soo_triggers : public CreatureAI
    {
        soo_triggers(Creature* creature) : CreatureAI(creature)
        {
            pInstance = creature->GetInstanceScript();
            intro = false;
            eighth = false;
        }

        InstanceScript* pInstance;
        EventMap events;

        bool intro;
        bool eighth;
        uint32 interval;

        void Reset()
        {
            me->setFaction(35);

            me->SetSpeed(MOVE_RUN, 1.6f);
            me->SetReactState(REACT_PASSIVE);

            Talk(TALK_9);

            events.ScheduleEvent(EVENT_TALK_1, 9000);

            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
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
            case EVENT_TALK_3:
            {
                Talk(TALK_12);
                events.ScheduleEvent(EVENT_TALK_4, 8000);
                break;
            }
            case EVENT_TALK_4:
            {
                Talk(TALK_13);
                events.ScheduleEvent(EVENT_TALK_5, 10000);
                break;
            }
            case EVENT_TALK_5:
            {
                if (Creature* stone = pInstance->instance->GetCreature(pInstance->GetObjectGuid(DATA_STONE)))
                {
                    stone->AI()->Talk(TALK_ROOK_INTRO);
                    events.ScheduleEvent(EVENT_TALK_6, 10000);
                    break;
                }
            }
            case EVENT_TALK_6:
            {
                Talk(TALK_14);
                events.ScheduleEvent(EVENT_TALK_7, 15000);
                break;
            }
            case EVENT_TALK_7:
            {
                if (Creature* stone = pInstance->instance->GetCreature(pInstance->GetObjectGuid(DATA_STONE)))
                {
                    stone->AI()->Talk(TALK_ROOK_INTRO2);
                    events.ScheduleEvent(EVENT_TALK_8, 10000);
                    break;
                }
            }
            case EVENT_TALK_8:
            {
                Talk(TALK_15);
                events.ScheduleEvent(EVENT_TALK_9, 10000);
                break;
            }
            case EVENT_TALK_9:
            {
                if (Creature* stone = pInstance->instance->GetCreature(pInstance->GetObjectGuid(DATA_STONE)))
                {
                    stone->AI()->Talk(TALK_ROOK_INTRO3);
                    events.ScheduleEvent(EVENT_TALK_10, 10000);
                    break;
                }
            }
            case EVENT_TALK_10:
            {
                Talk(TALK_16);

                if (Creature* stone = pInstance->instance->GetCreature(pInstance->GetObjectGuid(DATA_STONE)))
                {
                    if (Creature* hue = pInstance->instance->GetCreature(pInstance->GetObjectGuid(DATA_HU)))
                    {
                        if (Creature* sun = pInstance->instance->GetCreature(pInstance->GetObjectGuid(DATA_SUN)))
                        {
                            stone->setFaction(16);
                            hue->setFaction(16);
                            sun->setFaction(16);

                            me->DespawnOrUnsummon(4000);
                        }
                    }
                }
            }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new soo_triggers(creature);
    }
};
class boss_rook : public CreatureScript
{
public:
    boss_rook() : CreatureScript("boss_rook") { }

    struct boss_rook_ai : public BossAI
    {
        boss_rook_ai(Creature* creature) : BossAI(creature, DATA_STONE)
        {
            pInstance = creature->GetInstanceScript();

            me->setFaction(35);
        }

        InstanceScript* pInstance;
        EventMap events;
        bool desperateone, desperatetwo, deathsituation;
        uint32 addsdeathcounting, addsdeathinterval;
        uint32 berserk;

        void Reset()
        {
            events.Reset();

            berserk = 60000 * 10;

            desperateone = false;
            desperatetwo = false;
            deathsituation = false;
            addsdeathcounting = 0;
            addsdeathinterval = 7000;

            me->CastSpell(me, SPELL_SHA_CORRUPTION);

            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_GARROTE);
            me->setFaction(16);

            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
            me->SetReactState(REACT_AGGRESSIVE);
            me->RemoveUnitMovementFlag(MOVEMENTFLAG_ROOT);
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
        void JustReachedHome()
        {
            _JustReachedHome();

            DespawnCreaturesInArea(CREATURE_EMBODIED_MISERY, me);
            DespawnCreaturesInArea(CREATURE_EMBODIED_SORROW, me);
            DespawnCreaturesInArea(CREATURE_EMBODIED_GLOOM, me);
            DespawnCreaturesInArea(CREATURE_MARK_OF_ANGUISH, me);
            DespawnCreaturesInArea(CREATURE_DESPAIR_SPAWN, me);

            me->GetMotionMaster()->MovePoint(0, me->GetHomePosition().GetPositionX(), me->GetHomePosition().GetPositionY(), me->GetHomePosition().GetPositionZ());

            if (pInstance)
            {
                pInstance->SetBossState(DATA_FALLEN_PROTECTORS, FAIL);

                pInstance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

                Creature* sun = pInstance->instance->GetCreature(pInstance->GetObjectGuid(DATA_SUN));
                Creature* hu = pInstance->instance->GetCreature(pInstance->GetObjectGuid(DATA_HU));

                if (sun && hu)
                {
                    me->Respawn();
                    me->GetMotionMaster()->MovePoint(0, me->GetHomePosition().GetPositionX(), me->GetHomePosition().GetPositionY(), me->GetHomePosition().GetPositionZ());
                    me->RemoveAllAuras();

                    sun->Respawn();
                    sun->GetMotionMaster()->MovePoint(0, sun->GetHomePosition().GetPositionX(), sun->GetHomePosition().GetPositionY(), sun->GetHomePosition().GetPositionZ());
                    sun->RemoveAllAuras();

                    hu->Respawn();
                    hu->GetMotionMaster()->MovePoint(0, hu->GetHomePosition().GetPositionX(), hu->GetHomePosition().GetPositionY(), hu->GetHomePosition().GetPositionZ());
                    hu->RemoveAllAuras();
                }
            }
        }
        void EnterCombat(Unit* attacker)
        {
            if (pInstance)
            {
                Fallen_StartProtectors(pInstance, me, attacker);
                pInstance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                DoZoneInCombat();

                Talk(TALK_ROOK_AGGRO);

                events.ScheduleEvent(EVENT_CLASH, 16000);
                events.ScheduleEvent(EVENT_VENGEFUL_STRIKES, 14000);
                events.ScheduleEvent(EVENT_CORRUPTED_BREW, urand(8000, 10000));
            }
        }
        void JustSummoned(Creature* summon)
        {
            summons.Summon(summon);
        }
        void SummonedCreatureDespawn(Creature* summon)
        {
            summons.Despawn(summon);
        }
        void JustDied(Unit* killer)
        {
            Talk(TALK_ROOK_DEATH);

            if (pInstance)
            {
                pInstance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

                Creature* sun = pInstance->instance->GetCreature(pInstance->GetObjectGuid(DATA_SUN));
                Creature* hu = pInstance->instance->GetCreature(pInstance->GetObjectGuid(DATA_HU));

                if (sun && hu)
                {
                    sun->setFaction(35);
                    hu->setFaction(35);
                    me->setFaction(35);

                    me->CombatStop(true);
                    sun->CombatStop(true);
                    hu->CombatStop(true);
                    sun->getHostileRefManager().clearReferences();
                    hu->getHostileRefManager().clearReferences();
                    me->getHostileRefManager().clearReferences();

                    me->SetHealth(me->GetMaxHealth());
                    sun->SetHealth(sun->GetMaxHealth());
                    hu->SetHealth(hu->GetMaxHealth());

                    me->RemoveAura(SPELL_SHA_CORRUPTION);
                    sun->RemoveAura(SPELL_SHA_CORRUPTION);
                    hu->RemoveAura(SPELL_SHA_CORRUPTION);

                    // loot
                    switch (me->GetMap()->GetDifficultyID())
                    {
                    case DIFFICULTY_10_N:
                        me->SummonGameObject(GOBJECT_CHEST_10_MAN, chestposition.GetPositionX(), chestposition.GetPositionY(), chestposition.GetPositionZ(), chestposition.GetOrientation(), 0, 0, 0, 0, 0);
                        break;
                    case DIFFICULTY_10_HC:
                        me->SummonGameObject(GOBJECT_CHEST_10_HEROIC, chestposition.GetPositionX(), chestposition.GetPositionY(), chestposition.GetPositionZ(), chestposition.GetOrientation(), 0, 0, 0, 0, 0);
                        break;
                    case DIFFICULTY_25_N:
                        me->SummonGameObject(GOBJECT_CHEST_25_MAN, chestposition.GetPositionX(), chestposition.GetPositionY(), chestposition.GetPositionZ(), chestposition.GetOrientation(), 0, 0, 0, 0, 0);
                        break;
                    case DIFFICULTY_25_HC:
                        me->SummonGameObject(GOBJECT_CHEST_25_HEROIC, chestposition.GetPositionX(), chestposition.GetPositionY(), chestposition.GetPositionZ(), chestposition.GetOrientation(), 0, 0, 0, 0, 0);
                        break;

                    }

                    std::list<Player*> pl_list;
                    pl_list.clear();

                    me->GetPlayerListInGrid(pl_list, 100.0f);

                    if (pl_list.empty())
                        return;

                    /*CurrencyOnKillEntry const* Curr = sObjectMgr->GetCurrencyOnKillEntry(me->ToCreature()->GetEntry());
                    if (!Curr)
                        return;

                    for (auto itr : pl_list)
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

                    pInstance->SetBossState(DATA_FALLEN_PROTECTORS, DONE);
                    _JustDied();
                }
                else
                {
                    me->SetLootRecipient(NULL);
                }
            }
        }
        void DoAction(const int32 action)
        {
            switch (action)
            {
            case ACTION_DESPERATE_METHOD_ACTIVATE:
            {
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                me->SetReactState(REACT_PASSIVE);
                me->AddUnitMovementFlag(MOVEMENTFLAG_ROOT);

                events.Reset();

                int32 entries[3] = { CREATURE_EMBODIED_MISERY, CREATURE_EMBODIED_SORROW, CREATURE_EMBODIED_GLOOM };
                addsdeathcounting = 0;

                for (int i = 0; i < 3; i++)
                {
                    Position pos;
                    me->GetRandomNearPosition(20.0f);

                    me->SummonCreature(entries[i],pos, TEMPSUMMON_DEAD_DESPAWN);
                }
                break;
            }
            case ACTION_DESPERATE_METHOD_DEACTIVATE:
            {
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                me->SetReactState(REACT_AGGRESSIVE);
                me->RemoveExtraUnitMovementFlag(MOVEMENTFLAG_ROOT);

                events.ScheduleEvent(EVENT_VENGEFUL_STRIKES, 14000);
                events.ScheduleEvent(EVENT_CLASH, 16000);
                events.ScheduleEvent(EVENT_CORRUPTED_BREW, urand(8000, 10000));

                addsdeathcounting = 0;
                break;
            }
            case ACTION_COUNT_ADDS_DEATH:
            {
                addsdeathcounting++;

                if (addsdeathcounting >= 3)
                {
                    addsdeathcounting = 0;
                    DoAction(ACTION_DESPERATE_METHOD_DEACTIVATE);
                }
                break;
            }
            }
        }
        void DamageTaken(Unit* /*attacker*/, uint32& damage)
        {
            if (me->GetHealthPct() <= 66 && !desperateone)
            {
                DoAction(ACTION_DESPERATE_METHOD_ACTIVATE);
                desperateone = true;
            }
            if (me->GetHealthPct() <= 33 && !desperatetwo)
            {
                DoAction(ACTION_DESPERATE_METHOD_ACTIVATE);
                desperatetwo = true;
            }
            if (me->GetHealthPct() <= 10 && !deathsituation)
            {
                me->CastSpell(me, SPELL_BOND_OF_THE_GOLDEN_LOTUS);
                deathsituation = true;
                addsdeathinterval = 9000;

                events.Reset();

                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                events.ScheduleEvent(EVENT_BOND_OF_THE_GOLDEN_LOTUS_COUNT, 15000);
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

            if (deathsituation)
            {
                if (Creature* stone = pInstance->instance->GetCreature(pInstance->GetObjectGuid(DATA_STONE)))
                {
                    if (Creature* hue = pInstance->instance->GetCreature(pInstance->GetObjectGuid(DATA_HU)))
                    {
                        if (Creature* sun = pInstance->instance->GetCreature(pInstance->GetObjectGuid(DATA_SUN)))
                        {
                            if ((stone->HasUnitState(UNIT_STATE_CASTING) && stone->GetHealthPct() <= 10)
                                && (sun->HasUnitState(UNIT_STATE_CASTING) && sun->GetHealthPct() <= 10
                                && (hue->HasUnitState(UNIT_STATE_CASTING) && hue->GetHealthPct() <= 10)))
                            {
                                stone->AI()->JustDied(stone);
                            }
                        }
                    }
                }
            }

            if (me->HasUnitState(UNIT_STATE_CASTING) || me->GetCurrentSpell(CURRENT_CHANNELED_SPELL))
                return;

            events.Update(diff);

            switch (events.ExecuteEvent())
            {
            case EVENT_BOND_OF_THE_GOLDEN_LOTUS_COUNT:
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                me->SetReactState(REACT_AGGRESSIVE);
                me->RemoveExtraUnitMovementFlag(MOVEMENTFLAG_ROOT);

                events.ScheduleEvent(EVENT_VENGEFUL_STRIKES, 14000);
                events.ScheduleEvent(EVENT_CLASH, 16000);
                events.ScheduleEvent(EVENT_CORRUPTED_BREW, urand(8000, 10000));

                deathsituation = false;
                break;
            case EVENT_VENGEFUL_STRIKES:
                Talk(TALK_ROOK_SPELL_01);

                me->CastSpell(me->GetVictim(), SPELL_VENGFUL_STRIKES_POSSES_AURA);
                events.ScheduleEvent(EVENT_VENGEFUL_STRIKES, 14000);
                break;
            case EVENT_CORRUPTED_BREW:
                if (Unit* random = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                {
                    me->CastSpell(random, SPELL_CORRUPTED_BREW_DUMMY);
                }

                events.ScheduleEvent(EVENT_CORRUPTED_BREW, urand(8000, 10000));
                break;
            case EVENT_CLASH:
            {
                std::list<Player*> pl_rand_list;
                pl_rand_list.clear();

                me->GetPlayerListInGrid(pl_rand_list, 100.0f);

                if (pl_rand_list.empty())
                    return;

                Talk(TALK_ROOK_SPELL_02);

                /*
                forward: x += 1.569, y += 5.74
                backward:x-= 1.494, y += 5.46
                */

                std::list<Player*>::const_iterator it = pl_rand_list.begin();
                std::advance(it, urand(0, pl_rand_list.size() - 1));

                std::list<Player*>::const_iterator it2 = pl_rand_list.begin();
                std::advance(it2, urand(0, pl_rand_list.size() - 1));

                (*it)->GetMotionMaster()->MoveCharge(me->GetPositionX() + 1.569, me->GetPositionY() + 5.74, me->GetPositionZ(), 28.0f);
                (*it2)->GetMotionMaster()->MoveCharge(me->GetPositionX() - 1.569, me->GetPositionY() - 5.74, me->GetPositionZ(), 28.0f);

                events.ScheduleEvent(EVENT_CLASH, 26000);
                events.ScheduleEvent(EVENT_CORRUPTION_KICK, 2000);
                break;
            }
            case EVENT_CORRUPTION_KICK:
                Talk(TALK_ROOK_SPELL_03);

                me->CastSpell(me, SPELL_CORRUPTION_KICK_AURA);
                break;
            default:
                break;
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_rook_ai(creature);
    }
};
class boss_hu : public CreatureScript
{
public:
    boss_hu() : CreatureScript("boss_hu") { }

    struct boss_hu_ai : public BossAI
    {
        boss_hu_ai(Creature* creature) : BossAI(creature, DATA_HU)
        {
            pInstance = creature->GetInstanceScript();

            me->setFaction(35);
        }

        InstanceScript* pInstance;
        EventMap events;
        bool desperateone, desperatetwo, deathsituation;
        uint32 addsdeathcounting, addsdeathinterval, berserk;

        void Reset()
        {
            events.Reset();

            desperateone = false;
            desperatetwo = false;
            deathsituation = false;
            addsdeathcounting = 0;
            addsdeathinterval = 7000;

            berserk = 60000 * 10;

            me->setFaction(16);

            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_GARROTE);
            me->AddAura(SPELL_SHA_CORRUPTION, me);

            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
            me->SetReactState(REACT_AGGRESSIVE);
            me->RemoveUnitMovementFlag(MOVEMENTFLAG_ROOT);
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
        void JustReachedHome()
        {
            _JustReachedHome();

            if (pInstance)
            {
                pInstance->SetBossState(DATA_FALLEN_PROTECTORS, FAIL);

                pInstance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

                Creature* sun = pInstance->instance->GetCreature(pInstance->GetObjectGuid(DATA_SUN));
                Creature* stone = pInstance->instance->GetCreature(pInstance->GetObjectGuid(DATA_STONE));

                me->GetMotionMaster()->MovePoint(0, me->GetHomePosition().GetPositionX(), me->GetHomePosition().GetPositionY(), me->GetHomePosition().GetPositionZ());

                if (sun && stone)
                {
                    me->Respawn();
                    me->GetMotionMaster()->MovePoint(0, me->GetHomePosition().GetPositionX(), me->GetHomePosition().GetPositionY(), me->GetHomePosition().GetPositionZ());
                    me->RemoveAllAuras();

                    sun->Respawn();
                    sun->RemoveAllAuras();

                    stone->Respawn();
                    stone->GetMotionMaster()->MovePoint(0, stone->GetHomePosition().GetPositionX(), stone->GetHomePosition().GetPositionY(), stone->GetHomePosition().GetPositionZ());
                    stone->RemoveAllAuras();
                }
            }
        }
        void EnterCombat(Unit* attacker)
        {
            if (pInstance)
            {
                Fallen_StartProtectors(pInstance, me, attacker);
                pInstance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                DoZoneInCombat();

                events.ScheduleEvent(EVENT_GOUGE, 16000);
                events.ScheduleEvent(EVENT_GARROTE, 14000);
                events.ScheduleEvent(EVENT_NOXIOUS_POISION, urand(8000, 10000));
                events.ScheduleEvent(EVENT_INSTANT_POISION, urand(8000, 10000));

                std::list<Player*> pl_rand_list;
                pl_rand_list.clear();

                me->GetPlayerListInGrid(pl_rand_list, 100.0f);

                if (pl_rand_list.empty())
                    return;

                for (auto itr : pl_rand_list)
                {
                    if (!itr->HasSpell(143842))
                        itr->LearnSpell(143842, true);
                }
            }
        }
        void JustSummoned(Creature* summon)
        {
            summons.Summon(summon);
        }
        void SummonedCreatureDespawn(Creature* summon)
        {
            summons.Despawn(summon);
        }
        void JustDied(Unit* killer)
        {
            if (pInstance)
            {
                pInstance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

                Creature* sun = pInstance->instance->GetCreature(pInstance->GetObjectGuid(DATA_SUN));
                Creature* stone = pInstance->instance->GetCreature(pInstance->GetObjectGuid(DATA_STONE));

                if (sun && stone)
                {
                    sun->setFaction(35);
                    stone->setFaction(35);
                    me->setFaction(35);

                    me->CombatStop(true);
                    sun->CombatStop(true);
                    stone->CombatStop(true);
                    sun->getHostileRefManager().clearReferences();
                    stone->getHostileRefManager().clearReferences();
                    me->getHostileRefManager().clearReferences();

                    me->SetHealth(me->GetMaxHealth());
                    sun->SetHealth(sun->GetMaxHealth());
                    stone->SetHealth(stone->GetMaxHealth());

                    me->RemoveAura(SPELL_SHA_CORRUPTION);
                    sun->RemoveAura(SPELL_SHA_CORRUPTION);
                    stone->RemoveAura(SPELL_SHA_CORRUPTION);

                    /*
                    // loot
                    switch (me->GetMap()->GetDifficulty())
                    {
                    case MAN10_DIFFICULTY:
                    me->SummonGameObject(GOBJECT_CHEST_10_MAN, chestposition.GetPositionX(), chestposition.GetPositionY(), chestposition.GetPositionZ(), chestposition.GetOrientation(), 0, 0, 0, 0, 0);
                    break;
                    case MAN10_HEROIC_DIFFICULTY:
                    me->SummonGameObject(GOBJECT_CHEST_10_HEROIC, chestposition.GetPositionX(), chestposition.GetPositionY(), chestposition.GetPositionZ(), chestposition.GetOrientation(), 0, 0, 0, 0, 0);
                    break;
                    case MAN25_DIFFICULTY:
                    me->SummonGameObject(GOBJECT_CHEST_25_MAN, chestposition.GetPositionX(), chestposition.GetPositionY(), chestposition.GetPositionZ(), chestposition.GetOrientation(), 0, 0, 0, 0, 0);
                    break;
                    case MAN25_HEROIC_DIFFICULTY:
                    me->SummonGameObject(GOBJECT_CHEST_25_HEROIC, chestposition.GetPositionX(), chestposition.GetPositionY(), chestposition.GetPositionZ(), chestposition.GetOrientation(), 0, 0, 0, 0, 0);
                    break;
                    }
                    */

                    pInstance->SetBossState(DATA_FALLEN_PROTECTORS, DONE);
                    _JustDied();
                }
                else
                {
                    me->SetLootRecipient(NULL);
                }
            }
        }
        void DoAction(const int32 action)
        {
            switch (action)
            {
            case ACTION_DESPERATE_METHOD_ACTIVATE:
            {
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                me->SetReactState(REACT_PASSIVE);
                me->AddUnitMovementFlag(MOVEMENTFLAG_ROOT);

                events.Reset();

                DespawnCreaturesInArea(CREATURE_MARK_OF_ANGUISH, me);

                Position pos;
                me->GetRandomNearPosition(30.0f);
                me->SummonCreature(CREATURE_MARK_OF_ANGUISH, pos, TEMPSUMMON_MANUAL_DESPAWN);
                break;
            }
            case ACTION_DESPERATE_METHOD_DEACTIVATE:
            {
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                me->SetReactState(REACT_AGGRESSIVE);
                me->RemoveExtraUnitMovementFlag(MOVEMENTFLAG_ROOT);

                DespawnCreaturesInArea(CREATURE_MARK_OF_ANGUISH, me);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_GARROTE);

                events.ScheduleEvent(EVENT_GARROTE, urand(15000, 19000));
                events.ScheduleEvent(EVENT_GOUGE, urand(10000, 14000));
                events.ScheduleEvent(EVENT_NOXIOUS_POISION, 20000);
                events.ScheduleEvent(EVENT_INSTANT_POISION, 40000);

                me->RemoveAllAuras();

                addsdeathcounting = 0;
                break;
            }
            }
        }
        void DamageTaken(Unit* /*attacker*/, uint32& damage)
        {
            if (me->GetHealthPct() <= 66 && !desperateone)
            {
                DoAction(ACTION_DESPERATE_METHOD_ACTIVATE);
                desperateone = true;
            }
            if (me->GetHealthPct() <= 33 && !desperatetwo)
            {
                DoAction(ACTION_DESPERATE_METHOD_ACTIVATE);
                desperatetwo = true;

                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                me->SetReactState(REACT_PASSIVE);
                me->AddUnitMovementFlag(MOVEMENTFLAG_ROOT);
            }
            if (me->GetHealthPct() <= 10 && !deathsituation)
            {
                me->CastSpell(me, SPELL_BOND_OF_THE_GOLDEN_LOTUS);
                deathsituation = true;
                addsdeathinterval = 9000;

                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                events.ScheduleEvent(EVENT_BOND_OF_THE_GOLDEN_LOTUS_COUNT, 14000);
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

            if (deathsituation)
            {
                if (Creature* stone = pInstance->instance->GetCreature(pInstance->GetObjectGuid(DATA_STONE)))
                {
                    if (Creature* hue = pInstance->instance->GetCreature(pInstance->GetObjectGuid(DATA_HU)))
                    {
                        if (Creature* sun = pInstance->instance->GetCreature(pInstance->GetObjectGuid(DATA_SUN)))
                        {
                            if ((stone->HasUnitState(UNIT_STATE_CASTING) && stone->GetHealthPct() <= 10)
                                && (sun->HasUnitState(UNIT_STATE_CASTING) && sun->GetHealthPct() <= 10
                                && (hue->HasUnitState(UNIT_STATE_CASTING) && hue->GetHealthPct() <= 10)))
                            {
                                stone->AI()->JustDied(stone);
                            }
                        }
                    }
                }
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);

            switch (events.ExecuteEvent())
            {
            case EVENT_BOND_OF_THE_GOLDEN_LOTUS_COUNT:
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                me->SetReactState(REACT_AGGRESSIVE);
                me->RemoveExtraUnitMovementFlag(MOVEMENTFLAG_ROOT);

                events.ScheduleEvent(EVENT_GOUGE, 16000);
                events.ScheduleEvent(EVENT_GARROTE, 14000);
                events.ScheduleEvent(EVENT_NOXIOUS_POISION, urand(8000, 10000));
                events.ScheduleEvent(EVENT_INSTANT_POISION, urand(8000, 10000));

                deathsituation = false;
                break;
            case EVENT_GOUGE:
                me->CastSpell(me->GetVictim(), SPELL_GOUGE_DUMMY);
                me->getHostileRefManager().deleteReference(me->GetVictim());

                events.ScheduleEvent(EVENT_GOUGE, urand(10000, 14000));
                break;
            case EVENT_GARROTE:
                if (Unit* random = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0F, true))
                {
                    me->CastSpell(random, SPELL_SHADOWSTEP);
                    me->CastSpell(random, SPELL_GARROTE, true);
                }
                events.ScheduleEvent(EVENT_GARROTE, urand(15000, 19000));
                break;
            case EVENT_NOXIOUS_POISION:
                me->RemoveAura(143239);
                me->RemoveAura(143210);

                me->CastSpell(me, SPELL_NOXIOUS_POISON_DOT);
                events.ScheduleEvent(EVENT_NOXIOUS_POISION, 20000);
                break;
            case EVENT_INSTANT_POISION:
                me->RemoveAura(143239);
                me->RemoveAura(143210);

                me->CastSpell(me, SPELL_INSANT_POISON);
                events.ScheduleEvent(EVENT_INSTANT_POISION, 40000);
                break;
            default:
                break;
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_hu_ai(creature);
    }
};
class boss_sun : public CreatureScript
{
public:
    boss_sun() : CreatureScript("boss_sun") { }

    struct boss_sun_ai : public BossAI
    {
        boss_sun_ai(Creature* creature) : BossAI(creature, DATA_SUN)
        {
            pInstance = creature->GetInstanceScript();
            me->setFaction(35);
        }

        InstanceScript* pInstance;
        EventMap events;
        bool desperateone, desperatetwo, deathsituation, bubble;
        uint32 bubblecounting, addsdeathcounting, addsdeathinterval, berserk;

        void Reset()
        {
            events.Reset();

            desperateone = false;
            desperatetwo = false;
            deathsituation = false;
            bubble = false;

            berserk = 60000 * 10;

            bubblecounting = 500;
            addsdeathcounting = 0;
            addsdeathinterval = 0;

            me->setFaction(16);

            me->CastSpell(me, SPELL_SHA_CORRUPTION);

            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
            me->SetReactState(REACT_AGGRESSIVE);
            me->AddUnitMovementFlag(MOVEMENTFLAG_ROOT);
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
        void JustReachedHome()
        {
            _JustReachedHome();

            Talk(TALK_SUN_RESET);

            if (pInstance)
            {
                pInstance->SetBossState(DATA_FALLEN_PROTECTORS, FAIL);

                pInstance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

                Creature* stone = pInstance->instance->GetCreature(pInstance->GetObjectGuid(DATA_STONE));
                Creature* hu = pInstance->instance->GetCreature(pInstance->GetObjectGuid(DATA_HU));

                me->GetMotionMaster()->MovePoint(0, me->GetHomePosition().GetPositionX(), me->GetHomePosition().GetPositionY(), me->GetHomePosition().GetPositionZ());

                if (stone && hu)
                {
                    me->Respawn();
                    me->RemoveAllAuras();

                    stone->Respawn();
                    stone->GetMotionMaster()->MovePoint(0, stone->GetHomePosition().GetPositionX(), stone->GetHomePosition().GetPositionY(), stone->GetHomePosition().GetPositionZ());
                    stone->RemoveAllAuras();

                    hu->Respawn();
                    hu->GetMotionMaster()->MovePoint(0, hu->GetHomePosition().GetPositionX(), hu->GetHomePosition().GetPositionY(), hu->GetHomePosition().GetPositionZ());
                    hu->RemoveAllAuras();
                }
            }
        }
        void EnterCombat(Unit* attacker)
        {
            if (pInstance)
            {
                Fallen_StartProtectors(pInstance, me, attacker);
                pInstance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                DoZoneInCombat();

                Talk(TALK_SUN_AGGRO);

                events.ScheduleEvent(EVENT_SHA_FEAR, 16000);
                events.ScheduleEvent(EVENT_SHADOW_WORD_BANE, 22000);
                events.ScheduleEvent(EVENT_CALAMITY, urand(8000, 10000));
            }
        }
        void JustSummoned(Creature* summon)
        {
            summons.Summon(summon);
        }
        void SummonedCreatureDespawn(Creature* summon)
        {
            summons.Despawn(summon);
        }
        void JustDied(Unit* killer)
        {
            Talk(TALK_SUN_DEATH);

            if (pInstance)
            {
                pInstance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

                Creature* stone = pInstance->instance->GetCreature(pInstance->GetObjectGuid(DATA_STONE));
                Creature* hu = pInstance->instance->GetCreature(pInstance->GetObjectGuid(DATA_HU));

                if (stone && hu)
                {
                    stone->setFaction(35);
                    hu->setFaction(35);
                    me->setFaction(35);

                    me->CombatStop(true);
                    stone->CombatStop(true);
                    hu->CombatStop(true);
                    stone->getHostileRefManager().clearReferences();
                    hu->getHostileRefManager().clearReferences();
                    me->getHostileRefManager().clearReferences();

                    me->SetHealth(me->GetMaxHealth());
                    stone->SetHealth(stone->GetMaxHealth());
                    hu->SetHealth(hu->GetMaxHealth());

                    me->RemoveAura(SPELL_SHA_CORRUPTION);
                    stone->RemoveAura(SPELL_SHA_CORRUPTION);
                    hu->RemoveAura(SPELL_SHA_CORRUPTION);

                    /*
                    // loot
                    switch (me->GetMap()->GetDifficulty())
                    {
                    case MAN10_DIFFICULTY:
                    me->SummonGameObject(GOBJECT_CHEST_10_MAN, chestposition.GetPositionX(), chestposition.GetPositionY(), chestposition.GetPositionZ(), chestposition.GetOrientation(), 0, 0, 0, 0, 0);
                    break;
                    case MAN10_HEROIC_DIFFICULTY:
                    me->SummonGameObject(GOBJECT_CHEST_10_HEROIC, chestposition.GetPositionX(), chestposition.GetPositionY(), chestposition.GetPositionZ(), chestposition.GetOrientation(), 0, 0, 0, 0, 0);
                    break;
                    case MAN25_DIFFICULTY:
                    me->SummonGameObject(GOBJECT_CHEST_25_MAN, chestposition.GetPositionX(), chestposition.GetPositionY(), chestposition.GetPositionZ(), chestposition.GetOrientation(), 0, 0, 0, 0, 0);
                    break;
                    case MAN25_HEROIC_DIFFICULTY:
                    me->SummonGameObject(GOBJECT_CHEST_25_HEROIC, chestposition.GetPositionX(), chestposition.GetPositionY(), chestposition.GetPositionZ(), chestposition.GetOrientation(), 0, 0, 0, 0, 0);
                    break;
                    }
                    */

                    pInstance->SetBossState(DATA_FALLEN_PROTECTORS, DONE);
                    _JustDied();
                }
                else
                {
                    me->SetLootRecipient(NULL);
                }
            }
        }
        void DoAction(const int32 action)
        {
            switch (action)
            {
            case ACTION_DESPERATE_METHOD_ACTIVATE:
            {
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                me->SetReactState(REACT_PASSIVE);

                Talk(TALK_SUN_SPELL_03);

                events.Reset();
                me->CastSpell(me, SPELL_DARK_MEDITATION_VISUAL);
                bubble = true;

                for (int i = 0; i < 10; i++)
                {

                    if (roll_chance_i(50))
                        me->SummonCreature(CREATURE_DESPAIR_SPAWN, bubbleaddspos[0], TEMPSUMMON_DEAD_DESPAWN);
                    else
                        me->SummonCreature(CREATURE_DESPAIR_SPAWN, bubbleaddspos[1], TEMPSUMMON_DEAD_DESPAWN);
                }

                bubblecounting = 500;
                addsdeathcounting = 0;
                break;
            }
            case ACTION_DESPERATE_METHOD_DEACTIVATE:
            {
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                me->SetReactState(REACT_AGGRESSIVE);

                bubble = false;

                events.Reset();

                me->CastSpell(me, SPELL_SHA_CORRUPTION);
                events.ScheduleEvent(EVENT_SHA_FEAR, 16000);
                events.ScheduleEvent(EVENT_SHADOW_WORD_BANE, 14000);
                events.ScheduleEvent(EVENT_CALAMITY, urand(8000, 10000));
                DespawnCreaturesInArea(CREATURE_DESPAIR_SPAWN, me);
                me->RemoveAllAuras();

                addsdeathcounting = 0;
                break;
            }
            case ACTION_COUNT_ADDS_DEATH:
            {
                addsdeathcounting++;

                if (addsdeathcounting >= 8)
                {
                    DoAction(ACTION_DESPERATE_METHOD_DEACTIVATE);
                }
                break;
            }
            }
        }
        void DamageTaken(Unit* /*attacker*/, uint32& damage)
        {
            if (me->GetHealthPct() <= 66 && !desperateone)
            {
                DoAction(ACTION_DESPERATE_METHOD_ACTIVATE);
                desperateone = true;

                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                me->SetReactState(REACT_PASSIVE);
                me->AddUnitMovementFlag(MOVEMENTFLAG_ROOT);
            }
            if (me->GetHealthPct() <= 33 && !desperatetwo)
            {
                DoAction(ACTION_DESPERATE_METHOD_ACTIVATE);
                desperatetwo = true;

                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                me->SetReactState(REACT_PASSIVE);
                me->AddUnitMovementFlag(MOVEMENTFLAG_ROOT);
            }
            if (me->GetHealthPct() <= 10 && !deathsituation)
            {
                me->CastSpell(me, SPELL_BOND_OF_THE_GOLDEN_LOTUS);
                deathsituation = true;
                addsdeathinterval = 9000;

                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                events.ScheduleEvent(EVENT_BOND_OF_THE_GOLDEN_LOTUS_COUNT, 14000);
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

            if (deathsituation)
            {
                if (Creature* stone = pInstance->instance->GetCreature(pInstance->GetObjectGuid(DATA_STONE)))
                {
                    if (Creature* hue = pInstance->instance->GetCreature(pInstance->GetObjectGuid(DATA_HU)))
                    {
                        if (Creature* sun = pInstance->instance->GetCreature(pInstance->GetObjectGuid(DATA_SUN)))
                        {
                            if ((stone->HasUnitState(UNIT_STATE_CASTING) && stone->GetHealthPct() <= 10)
                                && (sun->HasUnitState(UNIT_STATE_CASTING) && sun->GetHealthPct() <= 10
                                && (hue->HasUnitState(UNIT_STATE_CASTING) && hue->GetHealthPct() <= 10)))
                            {
                                stone->AI()->JustDied(stone);
                            }
                        }
                    }
                }
            }

            if (bubble)
            {
                if (bubblecounting <= diff)
                {
                    std::list<Player*> pl_list;
                    pl_list.clear();

                    me->GetPlayerListInGrid(pl_list, 100.0f);

                    for (auto itr : pl_list)
                    {
                        if (itr->IsWithinDistInMap(me, 8.0f))
                        {
                            SpellInfo const* spell = sSpellMgr->GetSpellInfo(SPELL_DARK_MEDITATION_TICK);

                            if (spell)
                            {
                                int32 damage = spell->GetEffect(EFFECT_0)->BasePoints * 0.65;

                                itr->CastCustomSpell(itr, spell->Id, &damage, NULL, NULL, true, NULL);
                            }
                        }
                        else
                            itr->CastSpell(itr, SPELL_DARK_MEDITATION_TICK);
                    }

                    bubblecounting = 500;
                }
                else
                    bubblecounting -= diff;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);


            switch (events.ExecuteEvent())
            {
            case EVENT_BOND_OF_THE_GOLDEN_LOTUS_COUNT:
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                me->SetReactState(REACT_AGGRESSIVE);
                me->RemoveExtraUnitMovementFlag(MOVEMENTFLAG_ROOT);

                events.ScheduleEvent(EVENT_SHA_FEAR, 16000);
                events.ScheduleEvent(EVENT_SHADOW_WORD_BANE, 14000);
                events.ScheduleEvent(EVENT_CALAMITY, urand(8000, 10000));

                deathsituation = false;
                break;
            case EVENT_SHA_FEAR:
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                    me->CastSpell(target, SPELL_SHA_SEAR);

                events.ScheduleEvent(EVENT_SHA_FEAR, 8000);
                break;
            case EVENT_SHADOW_WORD_BANE:
                Talk(TALK_SUN_SPELL_01);

                for (int i = 0; i < 3; i++)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                        me->CastSpell(target, SPELL_SHADOW_WORD_BANE_DOT);
                }

                events.ScheduleEvent(EVENT_SHADOW_WORD_BANE, 22000);
                break;
            case EVENT_CALAMITY:
                Talk(TALK_SUN_SPELL_04);

                me->CastSpell(me, SPELL_CALAMITY_DUMMY);
                events.ScheduleEvent(EVENT_CALAMITY, 34000);
                break;
            default:
                break;
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_sun_ai(creature);
    }
};
class creature_mark_of_anguish : public CreatureScript
{
public:
    creature_mark_of_anguish() : CreatureScript("creature_mark_of_anguish") { }

    struct creature_mark_of_anguishAI : public ScriptedAI
    {
        creature_mark_of_anguishAI(Creature* creature) : ScriptedAI(creature)
        {
            pInstance = creature->GetInstanceScript();
        }

        InstanceScript* pInstance;
        EventMap events;

        void Reset()
        {
            me->CastSpell(me, SPELL_SHA_CORRUPTION);
            me->setFaction(16);
            DoZoneInCombat();

            events.ScheduleEvent(EVENT_CHOOSE_VICTIM, 1000);
        }
        void OnAddThreat(Unit* victim, float& fThreat, SpellSchoolMask /*schoolMask*/, SpellInfo const* /*threatSpell*/)
        {
            fThreat = 0;
            return;
        }
        void JustDied(Unit* killer)
        {
            if (Creature* stone = pInstance->instance->GetCreature(pInstance->GetObjectGuid(DATA_HU)))
                stone->GetAI()->DoAction(ACTION_DESPERATE_METHOD_DEACTIVATE);

            me->DespawnOrUnsummon(3000);
        }
        void KilledUnit(Unit* who)
        {
            events.ScheduleEvent(EVENT_CHOOSE_VICTIM, 1000);
        }
        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);

            switch (events.ExecuteEvent())
            {
            case EVENT_CHOOSE_VICTIM:
            {
                std::list<Player*> pl_list;

                pl_list.clear();

                me->GetPlayerListInGrid(pl_list, 100.0f);

                if (pl_list.empty())
                    return;

                std::list<Player*>::const_iterator it = pl_list.begin();
                std::advance(it, urand(0, pl_list.size() - 1));

                me->CastSpell((*it), SPELL_MARK_OF_ANGUISH_PLAYER_DOT);
                break;
            }
            default:
                break;
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new creature_mark_of_anguishAI(creature);
    }
};
class spell_mark_of_anguish_periodic_damage : public SpellScriptLoader
{
public:
    spell_mark_of_anguish_periodic_damage() : SpellScriptLoader("spell_mark_of_anguish_periodic_damage") { }

    class spell_mark_of_anguish_periodic_damage_aura_script : public AuraScript
    {
        PrepareAuraScript(spell_mark_of_anguish_periodic_damage_aura_script);

        //        void OnTick(constAuraEffectPtr /*aurEff*/)
        // {
        //  if (Unit* unit = GetTarget())
        //  {
        //      if (Aura* aura = GetTarget()->GetAura(144176))
        //      {
        //          SpellInfo const* info = sSpellMgr->GetSpellInfo(144365);
        //
        //          if (!info)
        //              return;
        //
        //          uint32 basepoints = info->GetEffect(EFFECT_0)->BasePoints;
        //          uint32 stacksize = aura->GetStackAmount();
        //          int32 calc = basepoints + (basepoints + float(stacksize / 100));
        //
        //          unit->CastCustomSpell(unit, 144365, &calc, NULL, NULL, true, NULL);
        //      }
        //      else
        //      {
        //          GetTarget()->CastSpell(GetTarget(), 144176);
        //      }
        //
        //      // hack fix of debilitation
        //      if (!unit->HasAura(147383))
        //          unit->AddAura(147383, unit);
        //  }
        //        }

        void Register()
        {
         //   OnEffectPeriodic += AuraEffectPeriodicFn(spell_mark_of_anguish_periodic_damage_aura_script::OnTick, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_mark_of_anguish_periodic_damage_aura_script();
    }
};
class creature_embodied_despair : public CreatureScript
{
public:
    creature_embodied_despair() : CreatureScript("creature_embodied_despair") { }

    struct creature_embodied_despair_ai : public ScriptedAI
    {
        creature_embodied_despair_ai(Creature* creature) : ScriptedAI(creature)
        {
            pInstance = creature->GetInstanceScript();
        }

        InstanceScript* pInstance;
        EventMap events;

        void Reset()
        {
        }
        void JustDied(Unit* killer)
        {
            if (Creature* stone = pInstance->instance->GetCreature(pInstance->GetObjectGuid(DATA_SUN)))
                stone->GetAI()->DoAction(ACTION_COUNT_ADDS_DEATH);
        }
        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);

            switch (events.ExecuteEvent())
            {
            default:
                break;
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new creature_embodied_despair_ai(creature);
    }
};
class creature_embodied_misery : public CreatureScript
{
public:
    creature_embodied_misery() : CreatureScript("creature_embodied_misery") { }

    struct creature_embodied_misery_ai : public ScriptedAI
    {
        creature_embodied_misery_ai(Creature* creature) : ScriptedAI(creature)
        {
            pInstance = creature->GetInstanceScript();
        }

        InstanceScript* pInstance;
        EventMap events;

        void Reset()
        {
        }
        void EnterCombat(Unit* attacker)
        {
            if (pInstance)
            {
                DoZoneInCombat();

                events.ScheduleEvent(EVENT_DEFILED_GROUND, urand(8000, 12000));
            }
        }
        void JustDied(Unit* killer)
        {
            if (Creature* stone = pInstance->instance->GetCreature(pInstance->GetObjectGuid(DATA_STONE)))
                stone->GetAI()->DoAction(ACTION_COUNT_ADDS_DEATH);

            me->DespawnOrUnsummon(3000);
        }
        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);

            switch (events.ExecuteEvent())
            {
            case EVENT_DEFILED_GROUND:
                // me->CastSpell(me, SPELL_DEFILED_GROUND_AREA_TRIGGER);
                events.ScheduleEvent(EVENT_DEFILED_GROUND, urand(8000, 12000));
                break;
            default:
                break;
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new creature_embodied_misery_ai(creature);
    }
};
class creature_embodied_sorrow : public CreatureScript
{
public:
    creature_embodied_sorrow() : CreatureScript("creature_embodied_sorrow") { }

    struct creature_embodied_sorrow_ai : public ScriptedAI
    {
        creature_embodied_sorrow_ai(Creature* creature) : ScriptedAI(creature)
        {
            pInstance = creature->GetInstanceScript();
        }

        InstanceScript* pInstance;
        EventMap events;

        void Reset()
        {
        }
        void EnterCombat(Unit* attacker)
        {
            if (pInstance)
            {
                DoZoneInCombat();

                events.ScheduleEvent(EVENT_INFERNO_STRIKE, 4000);
            }
        }
        void JustDied(Unit* killer)
        {
            if (Creature* stone = pInstance->instance->GetCreature(pInstance->GetObjectGuid(DATA_STONE)))
                stone->GetAI()->DoAction(ACTION_COUNT_ADDS_DEATH);

            me->DespawnOrUnsummon(3000);
        }
        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);

            switch (events.ExecuteEvent())
            {
            case EVENT_INFERNO_STRIKE:
                me->CastSpell(me->GetVictim(), SPELL_INFERNO_STRIKE_DUMMY);
                events.ScheduleEvent(EVENT_INFERNO_STRIKE, 16000);
                break;
            default:
                break;
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new creature_embodied_sorrow_ai(creature);
    }
};
class creature_embodied_gloom : public CreatureScript
{
public:
    creature_embodied_gloom() : CreatureScript("creature_embodied_gloom") { }

    struct creature_embodied_gloom_ai : public ScriptedAI
    {
        creature_embodied_gloom_ai(Creature* creature) : ScriptedAI(creature)
        {
            pInstance = creature->GetInstanceScript();
        }

        InstanceScript* pInstance;
        EventMap events;

        void Reset()
        {
        }
        void EnterCombat(Unit* attacker)
        {
            if (pInstance)
            {
                DoZoneInCombat();

                events.ScheduleEvent(EVENT_CORRUPTION_SHOCK, 4000);
            }
        }
        void JustDied(Unit* killer)
        {
            if (Creature* stone = pInstance->instance->GetCreature(pInstance->GetObjectGuid(DATA_STONE)))
                stone->GetAI()->DoAction(ACTION_COUNT_ADDS_DEATH);

            me->DespawnOrUnsummon(3000);
        }
        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);

            switch (events.ExecuteEvent())
            {
            case EVENT_CORRUPTION_SHOCK:
                me->CastSpell(me, SPELL_CORRUPTION_SHOCK_DUMMY);
                events.ScheduleEvent(EVENT_CORRUPTION_SHOCK, 10000);
                break;
            default:
                break;
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new creature_embodied_gloom_ai(creature);
    }
};
class spell_corruption_shock : public SpellScriptLoader
{
public:
    spell_corruption_shock() : SpellScriptLoader("spell_corruption_shock") { }

    class spell_corruption_shock_spell_script : public SpellScript
    {
        PrepareSpellScript(spell_corruption_shock_spell_script);

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (!GetCaster())
                return;

            std::list<Player*> pl_list;

            pl_list.clear();

            GetCaster()->GetPlayerListInGrid(pl_list, 100.0f);

            if (pl_list.empty())
                return;

            if (pl_list.size() >= 4)
            {
                std::list<Player*>::const_iterator it = pl_list.begin();
                std::advance(it, urand(0, pl_list.size() - 4));

                GetCaster()->CastSpell((*it), SPELL_CORRUPTION_SHOCK_MISSILE);
            }
            else
            {
                std::list<Player*>::const_iterator it = pl_list.begin();
                std::advance(it, urand(0, pl_list.size() - 1));

                GetCaster()->CastSpell((*it), SPELL_CORRUPTION_SHOCK_MISSILE);
            }
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_corruption_shock_spell_script::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_corruption_shock_spell_script();
    }
};
class spell_garrote_dummy : public SpellScriptLoader
{
public:
    spell_garrote_dummy() : SpellScriptLoader("spell_garrote_dummy") { }

    class spell_garrote_dummy_spell_script : public SpellScript
    {
        PrepareSpellScript(spell_garrote_dummy_spell_script);

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (!GetCaster() || !GetHitUnit())
                return;

            if (GetHitUnit()->isInFront(GetCaster(), M_PI))
            {
                GetCaster()->AddAura(SPELL_GOUGE_DAMAGE, GetHitUnit());
            }
            else
            {
                GetHitUnit()->CastSpell(GetHitUnit(), SPELL_GOUGE_KNOCKBACK);
            }
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_garrote_dummy_spell_script::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_garrote_dummy_spell_script();
    }
};
class spell_mark_of_anguish_transfer_player : public SpellScriptLoader
{
public:
    spell_mark_of_anguish_transfer_player() : SpellScriptLoader("spell_mark_of_anguish_transfer_player") { }

    class spell_garrote_dummy_spell_script : public SpellScript
    {
        PrepareSpellScript(spell_garrote_dummy_spell_script);

        SpellCastResult CheckTarget()
        {
            if (!GetCaster())
                return SPELL_FAILED_DONT_REPORT;

            if (GetExplTargetUnit())
            {
                if (GetExplTargetUnit()->GetTypeId() == TYPEID_PLAYER)
                    return SPELL_CAST_OK;

                if (GetCaster()->HasAura(143840))
                    return SPELL_CAST_OK;
            }
            return SPELL_FAILED_DONT_REPORT;
        }
        void OnCastT()
        {
            if (!GetCaster() || !GetHitUnit())
                return;

            if (GetCaster()->HasAura(143840))
            {
                GetCaster()->RemoveAura(143840);

                if (GetHitUnit())
                {
                    if (Creature* hu = GetHitUnit()->FindNearestCreature(CREATURE_MARK_OF_ANGUISH, 300.0F, true))
                    {
                        if (boss_hu::boss_hu_ai* huai = CAST_AI(boss_hu::boss_hu_ai, hu->GetAI()))
                        {
                            hu->GetMotionMaster()->MoveJump(GetHitUnit()->GetPositionX() + 2, GetHitUnit()->GetPositionY() + 3, GetHitUnit()->GetPositionZ(), 45.0F, 15.0F, 10.0F);

                            hu->CastSpell(GetHitUnit(), SPELL_MARK_OF_ANGUISH_PLAYER_DOT);
                        }
                    }
                }
            }
        }

        void Register()
        {
            OnCheckCast += SpellCheckCastFn(spell_garrote_dummy_spell_script::CheckTarget);
            OnCast += SpellCastFn(spell_garrote_dummy_spell_script::OnCastT);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_garrote_dummy_spell_script();
    }
};
class spell_shadow_word_bane : public SpellScriptLoader
{
public:
    spell_shadow_word_bane() : SpellScriptLoader("spell_shadow_word_bane") { }

    class spell_shadow_word_baneAI : public AuraScript {
        PrepareAuraScript(spell_shadow_word_baneAI);

        int32 cooldownPer;

        void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
        {
            if (!GetTarget())
                return;

            if (GetTarget()->GetTypeId() != TYPEID_PLAYER)
                return;

            if (!GetCaster())
                return;

            if (Unit* target = GetCaster()->GetAI()->SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0F, true))
                GetCaster()->CastSpell(target, SPELL_SHADOW_WORD_BANE_DOT);

        }
        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_shadow_word_baneAI::HandleEffectProc, EFFECT_1, SPELL_AURA_PERIODIC_DAMAGE);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_shadow_word_baneAI();
    }
};
class spell_calamity : public SpellScriptLoader
{
public:
    spell_calamity() : SpellScriptLoader("spell_calamity") { }

    class spell_calamity_spell_script : public SpellScript
    {
        PrepareSpellScript(spell_calamity_spell_script);

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (!GetCaster())
                return;

            std::list<Player*> pl_list;
            pl_list.clear();

            GetCaster()->GetPlayerListInGrid(pl_list, 100.0f);

            if (pl_list.empty())
                return;

            for (auto itr : pl_list)
            {
                itr->CastSpell(itr, SPELL_CALAMITY_DAMAGE);
            }
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_calamity_spell_script::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_calamity_spell_script();
    }
};
void AddSC_fallen_protectors()
{
    new siege_of_orgrimmar_lorewalker_cho_second_part();

    new boss_rook();
    new boss_sun();
    new boss_hu();
    new creature_embodied_despair();
    new creature_embodied_gloom();
    new creature_embodied_misery();
    new creature_embodied_sorrow();
    new creature_mark_of_anguish();
    new spell_corruption_shock();
    new spell_calamity();
    new spell_shadow_word_bane();
    new spell_mark_of_anguish_transfer_player();
    new spell_garrote_dummy();
    new spell_mark_of_anguish_periodic_damage();
};



