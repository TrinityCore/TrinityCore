/*
 * Copyright (C) 2012 - 2016 MoPCore
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
 *
 * Dungeon: Stormstout Brewery.
 * Boss: Yan-Zhu the Uncasked.
 */

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "CreatureTextMgr.h"
#include "SpellScript.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "Player.h"
#include "MoveSplineInit.h"
#include "PassiveAI.h"

#include "stormstout_brewery.h"

/*
Intro
    Uncle Gao yells: Yes yes yes! So close! Just a pinch of...oops...
    Uncle Gao yells: Too bitter! Just a drop of honey, and a cane of sugar, and maybe some corn? Yes, more corn!
    Uncle Gao yells: Yes, yes, yes...no, no, no no no! Yes! No! Peppers!
    Uncle Gao yells: Ahh! Help! What is that thing? It doesn't matter, nothing will stop me now, not when I'm so close! Maybe if I don't look at it...?

    // Each text line above corresponds to a spawn. //
    Meteor-like shower. Two Bloated / Stout Brew Alementals spawn in the mid.
    Meteor-like shower. Nine Bubbling / Yeasty Brew Alementals spawn in the mid.
    Meteor-like shower. Four Sudsy / Fizzy Brew Alementals spawn in the mid.
    Meteor-like shower, all 3 above. Boss Yan-zhu the Uncasked spawn in the mid.

Outro
    Uncle Gao says: Is it... can it be???
    * Gao runs over and kneels down by Yan-Zhu's remains and speaks reverently. *
    Uncle Gao says: Such harmony of flavor, such heady aroma! It is...the perfect brew!
    Uncle Gao yells: The name of Stormstout will be sung once again throughout the hills!
    * As he proclaims this, Chen runs into the Tasting Room and over to Yan-Zhu. *
    Chen Stormstout says: Uncle Gao, this brewery was left in your care! What have you done?
    Uncle Gao yells: You again! Don't you see? I have made a name for myself at last: I have brewed perfection!
    * Chen is dismayed with Gao's attitude. *
    Chen Stormstout says: At what cost? The Brewery is trashed! Infested!
    Uncle Gao says: Details, details.
    Chen Stormstout says: And there are Virmen in the main store!
    * Gao walks over to stand behind the stove as Chen follows to stand in front of it. *
    Uncle Gao says: Look, "Chen Stormstout", we can't all be heroes, running from our responsibilities, tromping around the Dread Wastes, saving the world. Some of us are "Artists".
    Chen Stormstout says: I think the brewery might be on fire.
    * Although Chen points this out, Gao's tone is dismissive, even bored. *
    Uncle Gao says: Yes, yes. That happens. 

    Mastery stuff depends on npc's summoned in intro.
    Just a beer thought:
    Weirdly, Bloat mastery should go with Stout abilities, as the adds summoned are Stout / Bloated, and Wheat with Sudsy / Fizzy (top fermented).
    Thus, we will handle them correctly and not how sites / the dungeon journal does, to have a correct selection.

    1. For Brewmastery: Stout
    - First wave of adds selected counts.
        - Bloated Alementals : Bloat.
        - Stout Alementals : Blackout Brew.

    2. For Brewmastery: Ale
    - Second wave of adds selected counts.
        - Yeasty Alementals : Yeasty Brew.
        - Bubbling Alementals : Bubble Shield.

    3. For Brewmastery: Wheat
    - Third wave of adds selected counts.
        - Fizzy Alementals : Carbonation.
        - Sudsy Alementals : Wall of Suds.
*/

enum UncleGaoYells
{
    // Intro / Outro.
    UNCLE_GAO_SAY_INTRO_1    = 0,       // Yes yes yes! So close! Just a pinch of...oops...
    UNCLE_GAO_SAY_INTRO_2,              // Too bitter! Just a drop of honey, and a cane of sugar, and maybe some corn? Yes, more corn!
    UNCLE_GAO_SAY_INTRO_3,              // Yes, yes, yes...no, no, no no no! Yes! No! Peppers!
    UNCLE_GAO_SAY_INTRO_4,              // Ahh! Help! What is that thing? It doesn't matter, nothing will stop me now, not when I'm so close! Maybe if I don't look at it...?

    UNCLE_GAO_SAY_OUTRO_1,              // Is it... can it be???
    UNCLE_GAO_SAY_OUTRO_2,              // Such harmony of flavor, such heady aroma! It is...the perfect brew!
    UNCLE_GAO_SAY_OUTRO_3,              // The name of Stormstout will be sung once again throughout the hills!
    UNCLE_GAO_SAY_OUTRO_4,              // You again! Don't you see? I have made a name for myself at last: I have brewed perfection!
    UNCLE_GAO_SAY_OUTRO_5,              // Details, details.
    UNCLE_GAO_SAY_OUTRO_6,              // Look, "Chen Stormstout", we can't all be heroes, running from our responsibilities, tromping around the Dread Wastes, saving the world. Some of us are "Artists".
    UNCLE_GAO_SAY_OUTRO_7               // Yes, yes. That happens.
};

enum ChenYanzhuYells
{
    // Outro.
    CHEN_SAY_OUTRO_1          = 0,      // Uncle Gao, this brewery was left in your care! What have you done?
    CHEN_SAY_OUTRO_2,                   // At what cost? The Brewery is trashed! Infested!
    CHEN_SAY_OUTRO_3,                   // And there are Virmen in the main store!
    CHEN_SAY_OUTRO_4,                   // I think the brewery might be on fire.
};

enum Effect
{
    EFFECT_0,
    EFFECT_1,
    EFFECT_2,
    EFFECT_3,
};

enum Spells
{
    // Boss
    SPELL_BREW_BOLT           = 114548,
    SPELL_ROOT                = 42716,  // Self root forever, used when Bubble Shield is up.

    // One of two from each category of the following abilities:

    // Brewmastery: Stout.
    SPELL_BLOAT               = 106546, // (1).
    SPELL_BLOAT_DUMMY         = 114929, // Tooltip says "Can use the Bloat ability."
    SPELL_BLOATED             = 106549, // Player aura triggering 106560 Gushing Brew - damage.
    SPELL_BLACKOUT_BREW       = 106851, // (2).
    SPELL_BLACKOUT_BREW_DUMMY = 114930, // Tooltip says "Can use the Blackout Brew ability."
    SPELL_BLACKOUT_DRUNK      = 106857, // At 10 stacks of SPELL_BLACKOUT_BREW.

    // Bremastery: Ale.
    SPELL_BUBBLE_SHIELD       = 106563, // (1).
    SPELL_BUBBLE_SHIELD_DUMMY = 114931, // Tooltip says "Can use the Bubble Shield ability."
    // Summons multiple NPC_YEASTY_BREW_ALEMENTAL_Y (2).
    SPELL_YEASTY_BREW_DUMMY   = 114932, // Tooltip says "Can summon Yeasty Brew minions."

    // Bremastery: Wheat.
    SPELL_CARBONATION         = 115003, // Triggers 114386 damage (1).
    SPELL_CARBONATION_DAMAGE  = 114386, // Triggered by above.
    SPELL_CARBONATION_DUMMY   = 114934, // Tooltip says "Can use the Carbonation ability."
    // Summons multiple NPC_FIZZY_BUBBLE (if uses Carbonation).
    SPELL_FIZZY_BUBBLE_VISUAL = 114458, // Dummy visual for NPC.
    SPELL_FIZZY_BUBBLE        = 114459, // Player fly aura on spellclick.
    // Summons multiple NPC_WALL_OF_SUDS (if uses Wall of Suds) (2).
    SPELL_SUDSY               = 114468, // If uses Wall of Suds. Triggers 114470 multiple Jump height at Jumping. Player aura.
    SPELL_SUDSY_JUMP          = 114470, // Triggered by above.
    SPELL_WALL_OF_SUDS_DUMMY  = 114933, // Tooltip says "Can summon walls of suds."

    // NPCs
    SPELL_YEASTY_BREW_BOLT    = 116155, // Yeasty Brew Alementals can cast a less powerful version of Brew Bolt, inflicting 9750 to 10250 Frost damage.
    SPELL_YEASTY_SUMMON_VIS   = 116259, // Yeasty Brew Alemental spawn visual.
    SPELL_FERMENT             = 106859, // Channeled beam, triggers 114451 - 1% Hp / Mana restore on target.
    SPELL_FERMENT_HEAL        = 114451, // Heal.
    SPELL_WALL_OF_SUDS        = 114467, // Triggers 114466 damage and stun.
    SPELL_WALL_OF_SUDS_DAMAGE = 114466, // Triggered by above.

    // Boss intro (Uncle Gao).
    SPELL_BREW_FINALE_DARK  = 128257, // First wave of spawns, Bloated / Stout Alementals. From Left cauldron (first).
    SPELL_DARK_SPAWN_EFF    = 128244, // Visual for first wave spawn.
    SPELL_BREW_FINALE_MED   = 128255, // Second wave of spawns, Yeasty / Bubbling Alementals. From Middle cauldron.
    SPELL_MED_SPAWN_EFF     = 128243, // Visual for second wave spawn.
    SPELL_BREW_FINALE_WHEAT = 128253, // Third wave of spawns, Fizzy / Sudsy Alementals. From Right cauldron (last).
    SPELL_WHEAT_SPAWN_EFF   = 128242  // Visual for third wave spawn.
};

enum Events
{
    // Boss
    EVENT_BREW_BOLT           = 1,

    // Bremastery: Stout.
    EVENT_BLOAT,
    EVENT_BLACKOUT_BREW,

    // Bremastery: Ale.
    EVENT_BUBBLE_SHIELD,
    EVENT_SET_BUBBLE_SHIELD_STACKS,
    EVENT_YEASTY_BREW_ELEMENTALS,

    // Brewmastery: Wheat.
    EVENT_CARBONATION,
    EVENT_WALL_OF_SUDS,

    // NPCs

    // Yeasty Brew Alemental
    EVENT_YEASTY_BREW_BOLT,
    EVENT_FERMENT,

    // Uncle Gao
    EVENT_UNCLE_GAO_SAY_INTRO_1,
    EVENT_UNCLE_GAO_SAY_INTRO_2,
    EVENT_UNCLE_GAO_SAY_INTRO_3,
    EVENT_UNCLE_GAO_SAY_INTRO_4,

    EVENT_UNCLE_GAO_INTRO_1,
    EVENT_UNCLE_GAO_INTRO_2,
    EVENT_UNCLE_GAO_INTRO_3,
    EVENT_UNCLE_GAO_INTRO_4,
    EVENT_UNCLE_GAO_INTRO_5,
    EVENT_UNCLE_GAO_INTRO_6,
    EVENT_UNCLE_GAO_INTRO_7,
    EVENT_UNCLE_GAO_INTRO_8,
    EVENT_UNCLE_GAO_INTRO_9,

    EVENT_UNCLE_GAO_SAY_OUTRO_1,
    EVENT_UNCLE_GAO_SAY_OUTRO_2,
    EVENT_UNCLE_GAO_SAY_OUTRO_3,
    EVENT_UNCLE_GAO_SAY_OUTRO_4,
    EVENT_UNCLE_GAO_SAY_OUTRO_5,
    EVENT_UNCLE_GAO_SAY_OUTRO_6,
    EVENT_UNCLE_GAO_SAY_OUTRO_7,

    EVENT_CHEN_SAY_OUTRO_1,
    EVENT_CHEN_SAY_OUTRO_2,
    EVENT_CHEN_SAY_OUTRO_3,
    EVENT_CHEN_SAY_OUTRO_4,

    EVENT_UNCLE_GAO_OUTRO_1,
    EVENT_UNCLE_GAO_OUTRO_2,
    EVENT_UNCLE_GAO_OUTRO_3,
    EVENT_UNCLE_GAO_OUTRO_4,
    EVENT_UNCLE_GAO_OUTRO_5,
    EVENT_UNCLE_GAO_OUTRO_6,
    EVENT_UNCLE_GAO_OUTRO_7,
    EVENT_UNCLE_GAO_OUTRO_8,
    EVENT_UNCLE_GAO_OUTRO_9,
    EVENT_UNCLE_GAO_OUTRO_10,
    EVENT_UNCLE_GAO_OUTRO_11,
    EVENT_UNCLE_GAO_OUTRO_12
};

enum Abilities
{
    // Brewmastery: Stout.
    ABILITY_BLOAT              = 0,
    ABILITY_BLACKOUT_BREW,

    // Bremastery: Ale.
    ABILITY_BUBBLE_SHIELD,
    ABILITY_YEASTY_BREW_ELEMENTALS,

    // Bremastery: Wheat.
    ABILITY_CARBONATION,
    ABILITY_WALL_OF_SUDS
};

// Uncle Gao actions.
enum Actions
{
    ACTION_START_INTRO      = 0, // Uncle Gao Yanzhu intro start.
    ACTION_START_OUTRO,          // Uncle Gao Yanzhu outro start.
    ACTION_EVADE                 // Uncle Gao evade.
};

// Wall of Suds summon positions.
Position const SudsPositions[4] =
{
    {-734.301f, 1130.030f, 166.660f, 1.843f}, // Top
    {-670.259f, 1190.673f, 166.749f, 3.241f}, // Right
    {-734.301f, 1130.030f, 166.660f, 0.276f}, // Left
    {-670.259f, 1190.673f, 166.749f, 4.988f}, // Bottom
};

// Wall of Suds move positions, inversed from summon ones. L->R and B->U + the other way around.
Position const SudsMovePositions[2] =
{
    {-662.180f, 1150.694f, 166.710f},         // Right and Top go here.
    {-745.371f, 1169.491f, 166.752f},         // Left and Bottom go here.
};

// Cauldron Bunny summon positions.
Position const CauldronPositions[3] =
{
    {-688.800f, 1194.998f, 168.184f, 4.872f}, // Left
    {-683.536f, 1196.037f, 168.590f, 5.009f}, // Mid
    {-677.967f, 1197.104f, 168.590f, 5.021f}, // Right
};

// Uncle Gao move positions for intro / outro.
Position const GaoMovePositions[8] =
{
    // Intro
    {-687.722f, 1190.905f, 166.712f},         // First beer cauldron.
    {-682.627f, 1191.762f, 166.714f},         // Second beer cauldron.
    {-676.919f, 1193.879f, 166.722f},         // Third beer cauldron.

    // Outro
    {-703.178f, 1162.610f, 166.142f},         // Middle of room.
    {-703.221f, 1179.328f, 166.240f},         // To stove 1.
    {-703.380f, 1180.399f, 166.730f},         // To stove 2.
    {-704.285f, 1190.693f, 166.745f},         // To stove 3.
    {-709.437f, 1185.671f, 166.711f},         // To stove 4, arrived.
};

// Chen Stormstout move positions for outro.
Position const ChenMovePositions[4] =
{
    // Outro
    {-682.729f, 1151.606f, 166.730f},         // To middle of room 1.
    {-683.797f, 1152.155f, 166.175f},         // To middle of room 2.
    {-695.625f, 1158.195f, 166.144f},         // To middle of room 3, arrived.
    {-706.771f, 1178.109f, 166.163f},         // To stove, arrived.
};

// Waves summon positions.
Position const AddWavesPositions[15] =
{
    // First wave.
    {-704.550f, 1166.890f, 166.142f, 0.278f},
    {-702.050f, 1158.719f, 166.142f, 0.302f},

    // Second wave.
    {-694.833f, 1165.140f, 166.144f, 0.290f},
    {-697.225f, 1173.010f, 166.148f, 0.247f},
    {-692.408f, 1157.320f, 166.149f, 0.274f},
    {-701.291f, 1154.790f, 166.149f, 0.235f},
    {-703.242f, 1162.760f, 166.143f, 0.238f},
    {-705.262f, 1171.090f, 166.148f, 0.238f},
    {-713.612f, 1168.650f, 166.148f, 0.277f},
    {-711.069f, 1160.770f, 166.143f, 0.277f},
    {-708.717f, 1152.450f, 166.148f, 0.264f},

    // Third wave.
    {-707.747f, 1165.800f, 166.143f, 0.251f},
    {-700.354f, 1167.900f, 166.143f, 0.294f},
    {-697.765f, 1159.970f, 166.143f, 0.266f},
    {-705.626f, 1157.790f, 166.143f, 0.270f},
};

// Uncle Gao 59074.
class npc_uncle_gao : public CreatureScript
{
    public :
        npc_uncle_gao() : CreatureScript("npc_uncle_gao") { }

        struct npc_uncle_gao_AI : public ScriptedAI
        {
            npc_uncle_gao_AI(Creature* creature) : ScriptedAI(creature), summons(me)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;
            EventMap events;
            SummonList summons;
            bool introStarted, outroStarted;
            uint8 RandomStoutAbility;
            uint8 RandomAleAbility;
            uint8 RandomWheatAbility;
            uint8 FirstWaveAddsDead;
            uint8 SecondWaveAddsDead;
            uint8 ThirdWaveAddsDead;

            void InitializeAI()
            {
                if (!me->IsDead())
                    Reset();
            }

            void Reset()
            {
                events.Reset();
                summons.DespawnAll();

                me->SetReactState(REACT_DEFENSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

                introStarted = false;
                outroStarted = false;

                RandomStoutAbility = RAND(ABILITY_BLOAT, ABILITY_BLACKOUT_BREW);
                RandomAleAbility   = RAND(ABILITY_BUBBLE_SHIELD, ABILITY_YEASTY_BREW_ELEMENTALS);
                RandomWheatAbility = RAND(ABILITY_CARBONATION, ABILITY_WALL_OF_SUDS);

                FirstWaveAddsDead = 0;
                SecondWaveAddsDead = 0;
                ThirdWaveAddsDead = 0;

                if (instance)
                    instance->SetData(DATA_YANZHU_THE_UNCASKED_EVENT, NOT_STARTED);
            }

            void EnterEvadeMode()
            {
                me->RemoveAllAuras();
                Reset();
                me->GetMotionMaster()->MoveTargetedHome();
                if (instance)
                    if (GameObject* door = instance->instance->GetGameObject(instance->GetData64(DATA_YAN_ZHU_DOOR)))
                        door->SetGoState(GO_STATE_ACTIVE);

                if (instance)
                    instance->SetData(DATA_YANZHU_THE_UNCASKED_EVENT, FAIL);
            }

            void JustSummoned(Creature* summon)
            {
                summons.Summon(summon);
                summon->setActive(true);

                switch(summon->GetEntry())
                {
                    case NPC_BLOATED_BREW_ALEMENTAL:
                    case NPC_STOUT_BREW_ALEMENTAL:
                        summon->CastSpell(summon, SPELL_DARK_SPAWN_EFF, false);
                        break;

                    case NPC_YEASTY_BREW_ALEMENTAL:
                    case NPC_BUBBLING_BREW_ALEMENTAL:
                        summon->CastSpell(summon, SPELL_MED_SPAWN_EFF, false);
                        break;

                    case NPC_FIZZY_BREW_ALEMENTAL:
                    case NPC_SUDSY_BREW_ALEMENTAL:
                        summon->CastSpell(summon, SPELL_WHEAT_SPAWN_EFF, false);
                        break;

                    default: break;
                }
            }

            void SummonedCreatureDies(Creature* summon, Unit* /*killer*/)
            {
                if (summon->GetEntry() != BOSS_YANZHU_THE_UNCASKED)
                    summons.Despawn(summon);

                switch(summon->GetEntry())
                {
                    case NPC_BLOATED_BREW_ALEMENTAL:
                    case NPC_STOUT_BREW_ALEMENTAL:
                        FirstWaveAddsDead += 1;
                        break;

                    case NPC_YEASTY_BREW_ALEMENTAL:
                    case NPC_BUBBLING_BREW_ALEMENTAL:
                        SecondWaveAddsDead += 1;
                        break;

                    case NPC_FIZZY_BREW_ALEMENTAL:
                    case NPC_SUDSY_BREW_ALEMENTAL:
                        ThirdWaveAddsDead += 1;
                        break;

                    default: break;
                }
            }

            void DoAction(int32 const action)
            {
                if (action == ACTION_START_INTRO && introStarted || action == ACTION_START_OUTRO && outroStarted)
                    return;

                switch (action)
                {
                    // Intro
                    case ACTION_START_INTRO:
                        introStarted = true;
                        events.ScheduleEvent(EVENT_UNCLE_GAO_SAY_INTRO_1, 1000);
                        break;

                    // Outro
                    case ACTION_START_OUTRO:
                        outroStarted = true;
                        events.ScheduleEvent(EVENT_UNCLE_GAO_SAY_OUTRO_1, 1000);
                        break;

                    // Evade
                    case ACTION_EVADE:
                        EnterEvadeMode();
                        break;

                    default: break;
                }
            }

            void UpdateAI(const uint32 diff)
            {
                if (!introStarted && me->FindNearestPlayer(40.0f, true))
                    DoAction(ACTION_START_INTRO);

                if (!introStarted)
                    return;

                if (instance && instance->IsWipe())
                {
                    EnterEvadeMode();
                    return;
                }

                if (FirstWaveAddsDead == 2)
                {
                    events.ScheduleEvent(EVENT_UNCLE_GAO_INTRO_3, 1000);
                    FirstWaveAddsDead = 0;
                }

                if (SecondWaveAddsDead == 9)
                {
                    events.ScheduleEvent(EVENT_UNCLE_GAO_INTRO_6, 1000);
                    SecondWaveAddsDead = 0;
                }

                if (ThirdWaveAddsDead == 4)
                {
                    events.ScheduleEvent(EVENT_UNCLE_GAO_INTRO_9, 1000);
                    ThirdWaveAddsDead = 0;
                }

                events.Update(diff);

                while(uint32 eventId = events.ExecuteEvent())
                {
                    switch(eventId)
                    {
                        // Intro
                        case EVENT_UNCLE_GAO_SAY_INTRO_1:
                            Talk(UNCLE_GAO_SAY_INTRO_1);
                            me->HandleEmote(EMOTE_ONESHOT_EXCLAMATION);
                            for (uint8 i = 0; i < 3; i++)
                                me->SummonCreature(NPC_CAULDRON_BUNNY, CauldronPositions[i], TEMPSUMMON_MANUAL_DESPAWN);
                            me->SummonCreature(NPC_BREW_BUNNY, YanzhuSummonPosition, TEMPSUMMON_MANUAL_DESPAWN);
                            if (instance)
                                if (GameObject* door = instance->instance->GetGameObject(instance->GetData64(DATA_YAN_ZHU_DOOR)))
                                    door->SetGoState(GO_STATE_READY);
                            if (instance)
                                instance->SetData(DATA_YANZHU_THE_UNCASKED_EVENT, IN_PROGRESS);
                            events.ScheduleEvent(EVENT_UNCLE_GAO_INTRO_1, 6000);
                            break;

                        case EVENT_UNCLE_GAO_INTRO_1:
                            if (Creature* bunny = me->FindNearestCreature(NPC_CAULDRON_BUNNY, 10.0f, true))
                                if (Creature* mid = me->FindNearestCreature(NPC_BREW_BUNNY, 100.0f, true))
                                    bunny->CastSpell(mid, SPELL_BREW_FINALE_DARK, false);
                            events.ScheduleEvent(EVENT_UNCLE_GAO_INTRO_2, 5000);
                            break;

                        case EVENT_UNCLE_GAO_INTRO_2:
                            for (uint8 i = 0; i < 2; i++)
                                me->SummonCreature(RandomStoutAbility == ABILITY_BLOAT ? NPC_BLOATED_BREW_ALEMENTAL : NPC_STOUT_BREW_ALEMENTAL, AddWavesPositions[i], TEMPSUMMON_MANUAL_DESPAWN);
                            break;

                            // -- First wave summoned.

                        case EVENT_UNCLE_GAO_INTRO_3:
                            me->GetMotionMaster()->MovePoint(1, GaoMovePositions[1]);
                            events.ScheduleEvent(EVENT_UNCLE_GAO_SAY_INTRO_2, 3000);
                            break;

                        case EVENT_UNCLE_GAO_SAY_INTRO_2:
                            Talk(UNCLE_GAO_SAY_INTRO_2);
                            me->HandleEmote(EMOTE_ONESHOT_EXCLAMATION);
                            me->SetFacingTo(1.723f);
                            events.ScheduleEvent(EVENT_UNCLE_GAO_INTRO_4, 10000);
                            break;

                        case EVENT_UNCLE_GAO_INTRO_4:
                            if (Creature* bunny = me->FindNearestCreature(NPC_CAULDRON_BUNNY, 10.0f, true))
                                if (Creature* mid = me->FindNearestCreature(NPC_BREW_BUNNY, 100.0f, true))
                                    bunny->CastSpell(mid, SPELL_BREW_FINALE_MED, false);
                            events.ScheduleEvent(EVENT_UNCLE_GAO_INTRO_5, 5000);
                            break;

                        case EVENT_UNCLE_GAO_INTRO_5:
                            for (uint8 i = 2; i < 11; i++)
                                me->SummonCreature(RandomAleAbility == ABILITY_BUBBLE_SHIELD ? NPC_BUBBLING_BREW_ALEMENTAL : NPC_YEASTY_BREW_ALEMENTAL, AddWavesPositions[i], TEMPSUMMON_MANUAL_DESPAWN);
                            break;

                            // -- Second wave summoned.

                        case EVENT_UNCLE_GAO_INTRO_6:
                            me->GetMotionMaster()->MovePoint(2, GaoMovePositions[2]);
                            events.ScheduleEvent(EVENT_UNCLE_GAO_SAY_INTRO_3, 3000);
                            break;

                        case EVENT_UNCLE_GAO_SAY_INTRO_3:
                            Talk(UNCLE_GAO_SAY_INTRO_3);
                            me->HandleEmote(EMOTE_ONESHOT_TALK);
                            me->SetFacingTo(1.848f);
                            events.ScheduleEvent(EVENT_UNCLE_GAO_INTRO_7, 8000);
                            break;

                        case EVENT_UNCLE_GAO_INTRO_7:
                            if (Creature* bunny = me->FindNearestCreature(NPC_CAULDRON_BUNNY, 10.0f, true))
                                if (Creature* mid = me->FindNearestCreature(NPC_BREW_BUNNY, 100.0f, true))
                                    bunny->CastSpell(mid, SPELL_BREW_FINALE_WHEAT, false);
                            events.ScheduleEvent(EVENT_UNCLE_GAO_INTRO_8, 5000);
                            break;

                        case EVENT_UNCLE_GAO_INTRO_8:
                            for (uint8 i = 11; i < 15; i++)
                                me->SummonCreature(RandomAleAbility == ABILITY_WALL_OF_SUDS ? NPC_SUDSY_BREW_ALEMENTAL : NPC_FIZZY_BREW_ALEMENTAL, AddWavesPositions[i], TEMPSUMMON_MANUAL_DESPAWN);
                            break;

                            // -- Third wave summoned.

                        case EVENT_UNCLE_GAO_INTRO_9:
                        {
                            if (Creature* mid = me->FindNearestCreature(NPC_BREW_BUNNY, 100.0f, true))
                            {
                                std::list<Creature*> cauldronList;
                                GetCreatureListWithEntryInGrid(cauldronList, me, NPC_CAULDRON_BUNNY, 30.0f);
                                if (!cauldronList.empty())
                                {
                                    for (auto cauldron: cauldronList)
                                    {
                                        if (cauldron = cauldronList.front())
                                            cauldron->CastSpell(mid, SPELL_BREW_FINALE_DARK, false);
                                        else if (cauldron = cauldronList.back())
                                            cauldron->CastSpell(mid, SPELL_BREW_FINALE_WHEAT, false);
                                        else
                                            cauldron->CastSpell(mid, SPELL_BREW_FINALE_MED, false);
                                    }
                                }
                            }
                            events.ScheduleEvent(EVENT_UNCLE_GAO_SAY_INTRO_4, 5000);
                            break;
                        }

                        case EVENT_UNCLE_GAO_SAY_INTRO_4:
                            Talk(UNCLE_GAO_SAY_INTRO_4);
                            me->HandleEmote(EMOTE_ONESHOT_COWER);
                            me->SummonCreature(BOSS_YANZHU_THE_UNCASKED, YanzhuSummonPosition, TEMPSUMMON_MANUAL_DESPAWN);
                            break;

                            // -- Yanzhu the Uncasked summoned.

                        // Outro
                        case EVENT_UNCLE_GAO_SAY_OUTRO_1:
                            Talk(UNCLE_GAO_SAY_OUTRO_1);
                            me->HandleEmote(EMOTE_ONESHOT_QUESTION);

                            if (instance)
                                if (GameObject* door = instance->instance->GetGameObject(instance->GetData64(DATA_YAN_ZHU_DOOR)))
                                    door->SetGoState(GO_STATE_ACTIVE);
                            events.ScheduleEvent(EVENT_UNCLE_GAO_OUTRO_1, 3000);
                            break;

                        case EVENT_UNCLE_GAO_OUTRO_1:
                            me->SetWalk(false);
                            me->GetMotionMaster()->MovePoint(3, GaoMovePositions[3]);
                            events.ScheduleEvent(EVENT_UNCLE_GAO_SAY_OUTRO_2, 8000);
                            break;

                        case EVENT_UNCLE_GAO_SAY_OUTRO_2:
                            Talk(UNCLE_GAO_SAY_OUTRO_2);
                            me->HandleEmote(EMOTE_ONESHOT_KNEEL);
                            events.ScheduleEvent(EVENT_UNCLE_GAO_SAY_OUTRO_3, 8000);
                            break;

                        case EVENT_UNCLE_GAO_SAY_OUTRO_3:
                            Talk(UNCLE_GAO_SAY_OUTRO_3);
                            me->HandleEmote(EMOTE_ONESHOT_CHEER);
                            events.ScheduleEvent(EVENT_UNCLE_GAO_OUTRO_2, 1000);
                            break;

                        case EVENT_UNCLE_GAO_OUTRO_2:
                            if (Creature* Chen = me->SummonCreature(NPC_CHEN_STORMSTOUT_YANZHU, ChenSummonPosition, TEMPSUMMON_MANUAL_DESPAWN))
                                Chen->GetMotionMaster()->MovePoint(1, ChenMovePositions[0]);
                            events.ScheduleEvent(EVENT_UNCLE_GAO_OUTRO_3, 4000);
                            break;

                        case EVENT_UNCLE_GAO_OUTRO_3:
                            if (Creature* Chen = me->FindNearestCreature(NPC_CHEN_STORMSTOUT_YANZHU, 100.0f, true))
                                Chen->GetMotionMaster()->MovePoint(2, ChenMovePositions[1]);
                            events.ScheduleEvent(EVENT_UNCLE_GAO_OUTRO_4, 2000);
                            break;

                        case EVENT_UNCLE_GAO_OUTRO_4:
                            if (Creature* Chen = me->FindNearestCreature(NPC_CHEN_STORMSTOUT_YANZHU, 100.0f, true))
                                Chen->GetMotionMaster()->MovePoint(3, ChenMovePositions[2]);
                            events.ScheduleEvent(EVENT_UNCLE_GAO_OUTRO_5, 4000);
                            break;

                        case EVENT_UNCLE_GAO_OUTRO_5:
                            if (Creature* Chen = me->FindNearestCreature(NPC_CHEN_STORMSTOUT_YANZHU, 100.0f, true))
                            {
                                Chen->SetFacingTo(2.667f);
                                Chen->AI()->Talk(CHEN_SAY_OUTRO_1);
                                Chen->HandleEmote(EMOTE_ONESHOT_EXCLAMATION);
                            }
                            events.ScheduleEvent(EVENT_UNCLE_GAO_SAY_OUTRO_4, 7000);
                            break;

                        case EVENT_UNCLE_GAO_SAY_OUTRO_4:
                            Talk(UNCLE_GAO_SAY_OUTRO_4);
                            me->HandleEmote(EMOTE_ONESHOT_POINT);
                            events.ScheduleEvent(EVENT_UNCLE_GAO_OUTRO_6, 10000);
                            break;

                        case EVENT_UNCLE_GAO_OUTRO_6:
                            if (Creature* Chen = me->FindNearestCreature(NPC_CHEN_STORMSTOUT_YANZHU, 100.0f, true))
                            {
                                Chen->AI()->Talk(CHEN_SAY_OUTRO_2);
                                Chen->HandleEmote(EMOTE_ONESHOT_QUESTION);
                            }
                            events.ScheduleEvent(EVENT_UNCLE_GAO_SAY_OUTRO_5, 6000);
                            break;

                        case EVENT_UNCLE_GAO_SAY_OUTRO_5:
                            Talk(UNCLE_GAO_SAY_OUTRO_5);
                            me->HandleEmote(EMOTE_ONESHOT_TALK);
                            events.ScheduleEvent(EVENT_UNCLE_GAO_OUTRO_7, 3000);
                            break;

                        case EVENT_UNCLE_GAO_OUTRO_7:
                            if (Creature* Chen = me->FindNearestCreature(NPC_CHEN_STORMSTOUT_YANZHU, 100.0f, true))
                            {
                                Chen->AI()->Talk(CHEN_SAY_OUTRO_3);
                                Chen->HandleEmote(EMOTE_ONESHOT_EXCLAMATION);
                            }
                            events.ScheduleEvent(EVENT_UNCLE_GAO_OUTRO_8, 4000);
                            break;

                        case EVENT_UNCLE_GAO_OUTRO_8:
                            me->SetWalk(true);
                            me->GetMotionMaster()->MovePoint(4, GaoMovePositions[4]);
                            events.ScheduleEvent(EVENT_UNCLE_GAO_OUTRO_9, 4000);
                            break;

                        case EVENT_UNCLE_GAO_OUTRO_9:
                            me->GetMotionMaster()->MovePoint(5, GaoMovePositions[5]);
                            events.ScheduleEvent(EVENT_UNCLE_GAO_OUTRO_10, 1500);
                            break;

                        case EVENT_UNCLE_GAO_OUTRO_10:
                            me->GetMotionMaster()->MovePoint(6, GaoMovePositions[6]);
                            if (Creature* Chen = me->FindNearestCreature(NPC_CHEN_STORMSTOUT_YANZHU, 100.0f, true))
                                Chen->GetMotionMaster()->MovePoint(4, ChenMovePositions[3]);
                            events.ScheduleEvent(EVENT_UNCLE_GAO_OUTRO_11, 4000);
                            break;

                        case EVENT_UNCLE_GAO_OUTRO_11:
                            me->GetMotionMaster()->MovePoint(7, GaoMovePositions[7]);
                            events.ScheduleEvent(EVENT_UNCLE_GAO_SAY_OUTRO_6, 4000);
                            break;

                        case EVENT_UNCLE_GAO_SAY_OUTRO_6:
                            me->SetFacingTo(4.992f);
                            if (Creature* Chen = me->FindNearestCreature(NPC_CHEN_STORMSTOUT_YANZHU, 100.0f, true))
                                Chen->SetFacingTo(1.972f);
                            Talk(UNCLE_GAO_SAY_OUTRO_6);
                            me->HandleEmote(EMOTE_ONESHOT_TALK);
                            events.ScheduleEvent(EVENT_UNCLE_GAO_OUTRO_12, 12000);
                            break;

                        case EVENT_UNCLE_GAO_OUTRO_12:
                            if (Creature* Chen = me->FindNearestCreature(NPC_CHEN_STORMSTOUT_YANZHU, 100.0f, true))
                            {
                                Chen->AI()->Talk(CHEN_SAY_OUTRO_4);
                                Chen->HandleEmote(EMOTE_ONESHOT_TALK);
                            }
                            events.ScheduleEvent(EVENT_UNCLE_GAO_SAY_OUTRO_7, 4000);
                            break;

                        case EVENT_UNCLE_GAO_SAY_OUTRO_7:
                            Talk(UNCLE_GAO_SAY_OUTRO_7);
                            me->HandleEmote(EMOTE_ONESHOT_TALK);
                            break;

                        default: break;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_uncle_gao_AI(creature);
        }
};

class boss_yan_zhu_the_uncasked : public CreatureScript
{
    public :
        boss_yan_zhu_the_uncasked() : CreatureScript("boss_yan_zhu_the_uncasked") { }

        struct boss_yan_zhu_the_uncasked_AI : public BossAI
        {
            boss_yan_zhu_the_uncasked_AI(Creature* creature) : BossAI(creature, DATA_YANZHU_THE_UNCASKED_EVENT), summons(me)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;
            EventMap events;
            SummonList summons;
            Creature* uncleGao;
            uint8 BossStoutAbility;
            uint8 BossAleAbility;
            uint8 BossWheatAbility;
            uint8 sudWallsCasts;

            void IsSummonedBy(Unit* summoner)
            {
                uncleGao = summoner->ToCreature();

                events.Reset();
                summons.DespawnAll();

                sudWallsCasts = 0;

                BossStoutAbility = CAST_AI(npc_uncle_gao::npc_uncle_gao_AI, uncleGao->AI())->RandomStoutAbility;
                BossAleAbility   = CAST_AI(npc_uncle_gao::npc_uncle_gao_AI, uncleGao->AI())->RandomAleAbility;
                BossWheatAbility = CAST_AI(npc_uncle_gao::npc_uncle_gao_AI, uncleGao->AI())->RandomWheatAbility;

                // Bremastery: Stout.
                if (BossStoutAbility == ABILITY_BLOAT)
                    me->AddAura(SPELL_BLOAT_DUMMY, me);         // Add the visual tooltip.
                else
                    me->AddAura(SPELL_BLACKOUT_BREW_DUMMY, me); // Add the visual tooltip.

                // Bremastery: Ale.
                if (BossAleAbility == ABILITY_BUBBLE_SHIELD)
                    me->AddAura(SPELL_BUBBLE_SHIELD_DUMMY, me); // Add the visual tooltip.
                else
                    me->AddAura(SPELL_YEASTY_BREW_DUMMY, me);   // Add the visual tooltip.

                // Brewmastery: Wheat.
                if (BossWheatAbility == ABILITY_CARBONATION)
                    me->AddAura(SPELL_CARBONATION_DUMMY, me);   // Add the visual tooltip.
                else
                    me->AddAura(SPELL_WALL_OF_SUDS_DUMMY, me);  // Add the visual tooltip.
            }

            void Reset() { }

            void EnterCombat(Unit* /*who*/)
			{
                if (instance)
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me); // Add

                // Melee range check.
                events.ScheduleEvent(EVENT_BREW_BOLT, 5000);

                // Bremastery: Stout.
                if (BossStoutAbility == ABILITY_BLOAT)
                    events.ScheduleEvent(EVENT_BLOAT, urand(11000, 13000));
                else
                    events.ScheduleEvent(EVENT_BLACKOUT_BREW, urand(9000, 11000));

                // Bremastery: Ale.
                if (BossAleAbility == ABILITY_BUBBLE_SHIELD)
                    events.ScheduleEvent(EVENT_BUBBLE_SHIELD, urand(16000, 19000));
                else
                    events.ScheduleEvent(EVENT_YEASTY_BREW_ELEMENTALS, urand(18000, 20000));

                // Brewmastery: Wheat.
                if (BossWheatAbility == ABILITY_CARBONATION)
                    events.ScheduleEvent(EVENT_CARBONATION, urand(22500, 24500));
                else
                    events.ScheduleEvent(EVENT_WALL_OF_SUDS, urand(25000, 27000));

                _EnterCombat();
            }

            void EnterEvadeMode()
            {
                summons.DespawnAll();
                me->RemoveAllAuras();
                me->DeleteThreatList();
                me->CombatStop(true);

                if (instance)
                {
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me); // Remove

                    if (me->HasAura(SPELL_BLOAT_DUMMY))
                        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_BLOATED);
                    if (me->HasAura(SPELL_BLACKOUT_BREW_DUMMY))
                    {
                        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_BLACKOUT_BREW);
                        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_BLACKOUT_DRUNK);
                    }
                    if (me->HasAura(SPELL_WALL_OF_SUDS_DUMMY))
                        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SUDSY);
                }

                uncleGao->AI()->DoAction(ACTION_EVADE);
            }

            void JustDied(Unit* /*killer*/)
            {
                summons.DespawnAll();

                if (instance)
                {
                    instance->SetData(DATA_YANZHU_THE_UNCASKED_EVENT, DONE);
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me); // Remove

                    if (me->HasAura(SPELL_BLOAT_DUMMY))
                        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_BLOATED);
                    if (me->HasAura(SPELL_BLACKOUT_BREW_DUMMY))
                    {
                        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_BLACKOUT_BREW);
                        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_BLACKOUT_DRUNK);
                    }
                    if (me->HasAura(SPELL_WALL_OF_SUDS_DUMMY))
                        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SUDSY);
                    if (uncleGao)
                        uncleGao->AI()->DoAction(ACTION_START_OUTRO);
                }

                _JustDied();
            }

            void JustSummoned(Creature* summon)
            {
                summons.Summon(summon);
                summon->setActive(true);

		        if (me->isInCombat())
                    summon->SetInCombatWithZone();

                if (summon->GetEntry() == NPC_FIZZY_BUBBLE)
                {
                    summon->SetReactState(REACT_PASSIVE);
                    summon->AddAura(SPELL_FIZZY_BUBBLE_VISUAL, summon);
                    summon->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);

                    summon->SetCanFly(true);
                    summon->SetSpeed(MOVE_WALK, 0.3f);
                    summon->SetSpeed(MOVE_RUN, 0.3f);
                    summon->SetSpeed(MOVE_FLIGHT, 0.3f);

                    float x, y, z;
                    summon->GetClosePoint(x, y, z, summon->GetObjectSize() / 3, 2.0f);
                    summon->GetMotionMaster()->MovePoint(1, x, y, z + 30.0f); // Move up 30y slowly, and disappear.
                    summon->DespawnOrUnsummon(20000);
                }

                if (summon->GetEntry() == NPC_WALL_OF_SUDS)
                {
                    summon->SetReactState(REACT_PASSIVE);
                    summon->AddAura(SPELL_WALL_OF_SUDS, summon);
                    summon->SetFlag(UNIT_NPC_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                    summon->SetSpeed(MOVE_WALK, 1.2f);
                    summon->SetSpeed(MOVE_RUN, 1.2f);
                    summon->DespawnOrUnsummon(8000);
                }
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while(uint32 eventId = events.ExecuteEvent())
                {
                    switch(eventId)
                    {
                        // Melee range check.
                        case EVENT_BREW_BOLT:
                            if (!HasHostileInMeleeRange())
                                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                                    DoCast(target, SPELL_BREW_BOLT);
                            events.ScheduleEvent(EVENT_BREW_BOLT, 2500);
                            break;

                        // Bremastery: Stout.
                        case EVENT_BLOAT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                                DoCast(target, SPELL_BLOAT);
                            events.ScheduleEvent(EVENT_BLOAT, urand(15500, 17500)); // every 14.5 seconds + 2c.
                            break;
                        case EVENT_BLACKOUT_BREW:
                            DoCast(me, SPELL_BLACKOUT_BREW);
                            events.ScheduleEvent(EVENT_BLACKOUT_BREW, urand(10500, 12500)); // every 10.5 seconds + 1c.
                            break;

                        // Bremastery: Ale.
                        case EVENT_BUBBLE_SHIELD:
                            DoCast(me, SPELL_BUBBLE_SHIELD);
                            events.ScheduleEvent(EVENT_SET_BUBBLE_SHIELD_STACKS, 2100); // 2s cast time.
                            events.ScheduleEvent(EVENT_BUBBLE_SHIELD, urand(43000, 45000)); // every 42 seconds + 2c.
                            break;
                        case EVENT_SET_BUBBLE_SHIELD_STACKS:
                            me->AddAura(SPELL_ROOT, me);
                            SpawnInCircle(1.0f, 8, NPC_BUBBLE_SHIELD, TEMPSUMMON_MANUAL_DESPAWN);
                            if (AuraPtr aura = me->GetAura(SPELL_BUBBLE_SHIELD))
					            me->SetAuraStack(SPELL_BUBBLE_SHIELD, me, 8);
                            break;
                        case EVENT_YEASTY_BREW_ELEMENTALS:
                            for (uint8 i = 0; i < 4; i++)
                                me->SummonCreature(NPC_YEASTY_BREW_ALEMENTAL_Y, me->GetPositionX() + frand(-4.0f, 4.0f), me->GetPositionY() + frand(-4.0f, 4.0f), me->GetPositionZ() + 1.0f, me->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);
                            events.ScheduleEvent(EVENT_YEASTY_BREW_ELEMENTALS, urand(69000, 73000)); // every 71 seconds.
                            break;

                        // Brewmastery: Wheat.
                        case EVENT_CARBONATION:
                            DoCast(me, SPELL_CARBONATION);
                            events.ScheduleEvent(EVENT_CARBONATION, urand(66000, 68000)); // every 64 seconds + 3c.
                            break;
                        case EVENT_WALL_OF_SUDS:
                            SummonSuds(sudWallsCasts % 2 == 0 ? true : false);
                            sudWallsCasts++;
                            events.ScheduleEvent(EVENT_WALL_OF_SUDS, urand(70000, 75000)); // every 72.5 seconds.
                            break;

                        default: break;
                    }
                }

                DoMeleeAttackIfReady();
            }

    // Particular AI functions.
    private:
        // Check for pets or players in Melee range.
        bool HasHostileInMeleeRange()
        {
            // Check for tank.
            if (Unit* tank = me->getVictim())
                if (tank->IsWithinDistInMap(me, MELEE_RANGE))
                    return true;

            // Check for pets.
            if (Unit* unit = me->SelectNearbyTarget(NULL, MELEE_RANGE))
                if (unit->isPet())
                    return true;

            // Check for players.
            if (Player* nearPlayer = me->FindNearestPlayer(MELEE_RANGE))
                if (nearPlayer->IsWithinDistInMap(me, MELEE_RANGE))
                    if (!nearPlayer->isGameMaster())
                        return true;

            return false;
        }

        // Used for spawning NPC's in a circle around the caster.
        void SpawnInCircle(float row, uint8 summonNumber, uint32 unitEntry, TempSummonType summonType = TEMPSUMMON_MANUAL_DESPAWN, uint32 despawnTimer = 30000)
        {
            float teta = (2 * M_PI) / summonNumber;

            for (uint8 i = 0 ; i < summonNumber ; i++)
            {
                float x = cos(i * teta) * row + me->GetPositionX();
                float y = sin(teta * i) * row + me->GetPositionY();

                if (summonType = TEMPSUMMON_MANUAL_DESPAWN)
                    me->SummonCreature(unitEntry, x, y, me->GetPositionZ() + 2.0f, 0, summonType);
                else
                    me->SummonCreature(unitEntry, x, y, me->GetPositionZ() + 2.0f, 0, summonType, despawnTimer);
            }
        }

        // Used for moving the Wall of Suds.
        void SudsMove(Creature* sudsWall, float X, float Y, float Z)
        {
            Movement::MoveSplineInit init(sudsWall);
            init.MoveTo(X, Y, Z);
            init.SetOrientationFixed(true);
            init.Launch();
        }

        // Used for summoning the Wall of Suds.
        void SummonSuds(bool right)
        {
            if (right) // Right->Left.
            {
                if (urand(0, 1) == 0) // Bottom->Top.
                {
                    // Need Bottom and Right.
                    if (Creature* sudsBottom = me->SummonCreature(NPC_WALL_OF_SUDS, SudsPositions[3], TEMPSUMMON_MANUAL_DESPAWN))
                    if (Creature* sudsRight  = me->SummonCreature(NPC_WALL_OF_SUDS, SudsPositions[1], TEMPSUMMON_MANUAL_DESPAWN))
                    {
                        SudsMove(sudsBottom, SudsMovePositions[1].GetPositionX(), SudsMovePositions[1].GetPositionY(), SudsMovePositions[1].GetPositionZ());
                        SudsMove(sudsRight, SudsMovePositions[0].GetPositionX(), SudsMovePositions[0].GetPositionY(), SudsMovePositions[0].GetPositionZ());
                    }
				}
                else                  // Top->Bottom.
                {
                    // Need Top and Right.
                    if (Creature* sudsTop = me->SummonCreature(NPC_WALL_OF_SUDS, SudsPositions[0], TEMPSUMMON_MANUAL_DESPAWN))
                    if (Creature* sudsRight  = me->SummonCreature(NPC_WALL_OF_SUDS, SudsPositions[1], TEMPSUMMON_MANUAL_DESPAWN))
                    {
                        SudsMove(sudsTop, SudsMovePositions[0].GetPositionX(), SudsMovePositions[0].GetPositionY(), SudsMovePositions[0].GetPositionZ());
                        SudsMove(sudsRight, SudsMovePositions[0].GetPositionX(), SudsMovePositions[0].GetPositionY(), SudsMovePositions[0].GetPositionZ());
                    }
				}
			}
            else       // Left->Right.
            {
                if (urand(0, 1) == 0) // Bottom->Top.
                {
                    // Need Bottom and Left.
                    if (Creature* sudsBottom = me->SummonCreature(NPC_WALL_OF_SUDS, SudsPositions[3], TEMPSUMMON_MANUAL_DESPAWN))
                    if (Creature* sudsLeft  = me->SummonCreature(NPC_WALL_OF_SUDS, SudsPositions[2], TEMPSUMMON_MANUAL_DESPAWN))
                    {
                        SudsMove(sudsBottom, SudsMovePositions[1].GetPositionX(), SudsMovePositions[1].GetPositionY(), SudsMovePositions[1].GetPositionZ());
                        SudsMove(sudsLeft, SudsMovePositions[1].GetPositionX(), SudsMovePositions[1].GetPositionY(), SudsMovePositions[1].GetPositionZ());
                    }
                }
                else                  // Top->Bottom.
                {
                    // Need Top and Left.
                    if (Creature* sudsTop = me->SummonCreature(NPC_WALL_OF_SUDS, SudsPositions[0], TEMPSUMMON_MANUAL_DESPAWN))
                    if (Creature* sudsLeft  = me->SummonCreature(NPC_WALL_OF_SUDS, SudsPositions[2], TEMPSUMMON_MANUAL_DESPAWN))
                    {
                        SudsMove(sudsTop, SudsMovePositions[0].GetPositionX(), SudsMovePositions[0].GetPositionY(), SudsMovePositions[0].GetPositionZ());
                        SudsMove(sudsLeft, SudsMovePositions[1].GetPositionX(), SudsMovePositions[1].GetPositionY(), SudsMovePositions[1].GetPositionZ());
                    }
                }
			}

            // Add Sudsy aura to players.
            DoCast(me, SPELL_SUDSY);
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_yan_zhu_the_uncasked_AI(creature);
    }
};

// Bubble Shield 65522.
class npc_bubble_shield_yanzhu : public CreatureScript
{
    public :
        npc_bubble_shield_yanzhu() : CreatureScript("npc_bubble_shield_yanzhu") { }

        struct npc_bubble_shield_yanzhu_AI : public ScriptedAI
        {
            npc_bubble_shield_yanzhu_AI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;
            Creature* bossYanzhu;

            void IsSummonedBy(Unit* summoner)
            {
                if (summoner)
                {
                    bossYanzhu = summoner->ToCreature();
                    me->SetFacingTo(summoner->GetOrientation());
                }
                else
                    bossYanzhu = NULL;

                Reset();
            }

            void Reset()
            {
                me->SetReactState(REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
            }

            void JustDied(Unit* /*killer*/)
            {
                if (bossYanzhu)
                {
                    if (AuraPtr bubble = bossYanzhu->GetAura(SPELL_BUBBLE_SHIELD))
                    {
                        if (bubble->GetStackAmount() > 1)
                            bubble->SetStackAmount(bubble->GetStackAmount() - 1);
                        else
                        {
                            bossYanzhu->RemoveAurasDueToSpell(SPELL_BUBBLE_SHIELD);
                            bossYanzhu->RemoveAurasDueToSpell(SPELL_ROOT);
                        }
                    }
                }
            }

            void UpdateAI(const uint32 diff) { } // No melee.
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_bubble_shield_yanzhu_AI(creature);
        }
};

// Fizzy Bubble 59799.
class npc_fizzy_bubble_yanzhu : public CreatureScript
{
    public:
        npc_fizzy_bubble_yanzhu() : CreatureScript("npc_fizzy_bubble_yanzhu") { }

        struct npc_fizzy_bubble_yanzhuAI : public PassiveAI
        {
            npc_fizzy_bubble_yanzhuAI(Creature* creature) : PassiveAI(creature) { }

            void OnSpellClick(Unit* clicker)
            {
                clicker->AddAura(SPELL_FIZZY_BUBBLE, clicker);
                me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                me->DespawnOrUnsummon(100);
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_fizzy_bubble_yanzhuAI(creature);
        }
};

// Yeasty Brew Alemental 66413.
class npc_yeasty_brew_elemental_yanzhu : public CreatureScript
{
    public :
        npc_yeasty_brew_elemental_yanzhu() : CreatureScript("npc_yeasty_brew_elemental_yanzhu") { }

        struct npc_yeasty_brew_elemental_yanzhu_AI : public ScriptedAI
        {
            npc_yeasty_brew_elemental_yanzhu_AI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
            }

            EventMap events;
            InstanceScript* instance;

            void IsSummonedBy(Unit* summoner)
            {
                DoCast(me, SPELL_YEASTY_SUMMON_VIS);
                Reset();
            }

            void Reset()
            {
                events.Reset();
                events.ScheduleEvent(EVENT_YEASTY_BREW_BOLT, urand(2000, 5500));
                events.ScheduleEvent(EVENT_FERMENT, urand(8000, 19000));
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while(uint32 eventId = events.ExecuteEvent())
                {
                    switch(eventId)
                    {
                        case EVENT_YEASTY_BREW_BOLT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                                DoCast(target, SPELL_YEASTY_BREW_BOLT);
                            events.ScheduleEvent(EVENT_YEASTY_BREW_BOLT, 3000);
                            break;

                        case EVENT_FERMENT:
                            if (Creature* yanzhu = me->FindNearestCreature(BOSS_YANZHU_THE_UNCASKED, 100.0f, true))
                                DoCast(yanzhu, SPELL_FERMENT);
                            events.ScheduleEvent(EVENT_FERMENT, urand(21000, 32000));
                            break;
                    }
                }
                // No melee.
            }
        };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_yeasty_brew_elemental_yanzhu_AI(creature);
    }
};

// Bloat 106546.
class spell_yanzhu_bloat : public SpellScriptLoader
{
    public:
        spell_yanzhu_bloat() :  SpellScriptLoader("spell_yanzhu_bloat") { }

        class spell_yanzhu_bloat_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_yanzhu_bloat_AuraScript);

            void OnApply(constAuraEffectPtr /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (GetCaster() && GetTarget())
                {
                    if (Unit* target = GetTarget())
                    {
                        // Summon 2 Bloated Stalkers that enter the player turned into a vehicle by the aura, and cast on the sides.
                        for (uint8 i = 0; i < 2; i++)
                        {
                            if (Creature* bloatStalker = GetCaster()->SummonCreature(NPC_BLOATED_STALKER, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0, TEMPSUMMON_MANUAL_DESPAWN))
                            {
                                if (AuraPtr bloat = GetCaster()->AddAura(SPELL_BLOATED, bloatStalker))
                                {
                                    bloat->SetMaxDuration(GetMaxDuration());
                                    bloat->SetDuration(GetDuration());
                                }
                                bloatStalker->SetReactState(REACT_PASSIVE);
                                bloatStalker->DespawnOrUnsummon(31000);
                                bloatStalker->EnterVehicle(target); // Enter player.
                                bloatStalker->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                            }
                        }
                    }
                }
            }

            void Register()
            {
                OnEffectApply += AuraEffectApplyFn(spell_yanzhu_bloat_AuraScript::OnApply, EFFECT_0, SPELL_AURA_MOD_SCALE, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_yanzhu_bloat_AuraScript();
        }
};

// Gushing Brew (Bloated trigger spell) 106560.
class spell_yanzhu_gushing_brew : public SpellScriptLoader
{
    public:
        spell_yanzhu_gushing_brew() : SpellScriptLoader("spell_yanzhu_gushing_brew") { }

        class spell_yanzhu_gushing_brew_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_yanzhu_gushing_brew_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (!GetCaster() || targets.empty())
                    return;

                Map* map = GetCaster()->GetMap();
                if (map && map->IsDungeon())
                {
                    targets.clear();
                    std::list<Player*> playerList;
                    Map::PlayerList const& players = map->GetPlayers();
                    for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                        if (Player* player = itr->getSource())
                            if (GetCaster()->isInFront(player, M_PI / 3))
                                targets.push_back(player);
                }
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_yanzhu_gushing_brew_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_CONE_ENTRY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_yanzhu_gushing_brew_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_CONE_ENTRY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_yanzhu_gushing_brew_SpellScript::FilterTargets, EFFECT_2, TARGET_UNIT_CONE_ENTRY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_yanzhu_gushing_brew_SpellScript();
        }
};

// Blackout Brew 106851.
class spell_yanzhu_blackout_brew : public SpellScriptLoader
{
    public :
        spell_yanzhu_blackout_brew() : SpellScriptLoader("spell_yanzhu_blackout_brew") { }

        class spell_yanzhu_blackout_brew_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_yanzhu_blackout_brew_SpellScript)

            void HandleOnHit()
            {
                if (!GetHitUnit())
                    return;

                if (AuraPtr blackoutBrew = GetHitUnit()->GetAura(SPELL_BLACKOUT_BREW)) // Get the aura.
                {
                    if (blackoutBrew->GetStackAmount() < 7) // Adds 3 so must check for 6 or less.
                        blackoutBrew->SetStackAmount(blackoutBrew->GetStackAmount() + 2); // Add 3 stacks. 1 is already added from the aura so we add 2 more.
                    else
                    {
                        GetHitUnit()->AddAura(SPELL_BLACKOUT_DRUNK, GetHitUnit()); // Stun the player.
                        GetHitUnit()->RemoveAurasDueToSpell(SPELL_BLACKOUT_BREW); // Remove all the aura stacks.
                    }
                }
            }

            void Register()
            {
                OnHit += SpellHitFn(spell_yanzhu_blackout_brew_SpellScript::HandleOnHit);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_yanzhu_blackout_brew_SpellScript();
        }

        class spell_yanzhu_blackout_brew_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_yanzhu_blackout_brew_AuraScript)

            void OnPeriodic(constAuraEffectPtr /*aurEff*/)
            {
                if (!GetCaster() || !GetTarget())
                    return;

                // Remove a stack if the player is moving or jumping (Jumping checked by MOVEMENTFLAG_FALLING and PositionZ compared to boss one plus a small margin).
                if (GetTarget()->IsMoving() || GetTarget()->HasUnitMovementFlag(MOVEMENTFLAG_FALLING) || GetTarget()->GetPositionZ() > GetCaster()->GetPositionZ() + 0.6f)
                    if (AuraPtr blackoutBrew = GetTarget()->GetAura(SPELL_BLACKOUT_BREW)) // Get the aura.
                        if (blackoutBrew->GetStackAmount() > 1)
                            blackoutBrew->SetStackAmount(blackoutBrew->GetStackAmount() - 1); // Remove a stack till the base one is left.
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_yanzhu_blackout_brew_AuraScript::OnPeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_yanzhu_blackout_brew_AuraScript();
        }
};

// Ferment 106859.
class spell_yeasty_alemental_ferment : public SpellScriptLoader
{
    public:
        spell_yeasty_alemental_ferment() : SpellScriptLoader("spell_yeasty_alemental_ferment") { }

        class spell_yeasty_alemental_ferment_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_yeasty_alemental_ferment_AuraScript);

            void HandlePeriodicTick(constAuraEffectPtr /*aurEff*/)
            {
                PreventDefaultAction();

                if (Unit* caster = GetCaster())
                {
	                if (Creature* Yanzhu = caster->FindNearestCreature(BOSS_YANZHU_THE_UNCASKED, 100.0f, true))
                    {
                        std::list<Player*> playerTargetsList;
                        Map::PlayerList const &PlayerList = caster->GetMap()->GetPlayers();
                        if (!PlayerList.isEmpty())
                            for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                                if (Player* player = i->getSource())
                                    if (player->IsInBetween(caster, Yanzhu, 1.5f)) // Check for players between the npc and the boss.
                                        playerTargetsList.push_back(player);

                        if (!playerTargetsList.empty()) // If the list is not empty select only the nearest player in line with the boss.
                        {
                            playerTargetsList.sort(MoPCore::ObjectDistanceOrderPred(caster));
                            playerTargetsList.resize(1);
                            caster->CastSpell(playerTargetsList.front(), SPELL_FERMENT_HEAL, true);
                        }
                        else
                            caster->CastSpell(Yanzhu, SPELL_FERMENT_HEAL, true);
                    }
                }
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_yeasty_alemental_ferment_AuraScript::HandlePeriodicTick, EFFECT_1, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_yeasty_alemental_ferment_AuraScript();
        }
};

// Carbonation 115003 - Summon Fizzy Bubbles script.
class spell_yanzhu_carbonation : public SpellScriptLoader
{
    public:
        spell_yanzhu_carbonation() : SpellScriptLoader("spell_yanzhu_carbonation") { }

        class spell_yanzhu_carbonation_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_yanzhu_carbonation_AuraScript)

            void PeriodicTick(constAuraEffectPtr /*aurEff*/)
            {
                if (Unit* caster = GetCaster())
                    for (uint8 i = 0; i < 2; i++)
                        caster->SummonCreature(NPC_FIZZY_BUBBLE, caster->GetPositionX() + frand(-13.0f, 13.0f), caster->GetPositionY() + frand(-13.0f, 13.0f), caster->GetPositionZ() + 1.0f,  caster->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_yanzhu_carbonation_AuraScript::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_yanzhu_carbonation_AuraScript();
        }
};

// Carbonation 114386 - Damage.
class spell_yanzhu_carbonation_damage : public SpellScriptLoader
{
    public:
        spell_yanzhu_carbonation_damage() : SpellScriptLoader("spell_yanzhu_carbonation_damage") { }

        class spell_yanzhu_carbonation_damage_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_yanzhu_carbonation_damage_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (!GetCaster() || targets.empty())
                    return;

				Map* map = GetCaster()->GetMap();
				if (map && map->IsDungeon())
				{
					targets.clear();
					std::list<Player*> playerList;
					Map::PlayerList const& players = map->GetPlayers();
					for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
						if (Player* player = itr->getSource())
							if (!(player->HasAura(SPELL_FIZZY_BUBBLE) && player->GetPositionZ() > GetCaster()->GetPositionZ() + 1.5f))
								targets.push_back(player);
				}
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_yanzhu_carbonation_damage_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_yanzhu_carbonation_damage_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_yanzhu_carbonation_damage_SpellScript();
        }
};

// Wall of Suds 114467.
class spell_wall_of_suds : public SpellScriptLoader
{
    public:
        spell_wall_of_suds() : SpellScriptLoader("spell_wall_of_suds") { }

        class spell_wall_of_suds_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_wall_of_suds_AuraScript);

            void HandlePeriodicTick(constAuraEffectPtr /*aurEff*/)
            {
                PreventDefaultAction();

                if (Unit* caster = GetCaster())
                {
                    Map::PlayerList const &PlayerList = caster->GetMap()->GetPlayers();
                    if (!PlayerList.isEmpty())
                        for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                            if (Player* player = i->getSource())
                                if (caster->isInFront(player, M_PI / 5) && !player->HasUnitMovementFlag(MOVEMENTFLAG_FALLING) && player->GetPositionZ() <= caster->GetPositionZ() + 0.6f)
                                    caster->CastSpell(player, SPELL_WALL_OF_SUDS_DAMAGE, true);
                }
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_wall_of_suds_AuraScript::HandlePeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_wall_of_suds_AuraScript();
        }
};

// Sudsy 114468 - Player Jump aura script.
class spell_yanzhu_sudsy : public SpellScriptLoader
{
    public:
        spell_yanzhu_sudsy() : SpellScriptLoader("spell_yanzhu_sudsy") { }

        class spell_yanzhu_sudsy_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_yanzhu_sudsy_AuraScript);

            bool jumpedHigh;

            bool Load()
            {
                jumpedHigh = false;
                return true;
            }

            void HandlePeriodicTick(constAuraEffectPtr /*aurEff*/)
            {
                PreventDefaultAction();

                Unit* caster = GetCaster();
                Unit* target = GetTarget();
                if (!caster || !target)
                    return;

                if (target->HasUnitMovementFlag(MOVEMENTFLAG_FALLING) && !jumpedHigh)
                {
                    target->CastSpell(target, SPELL_SUDSY_JUMP, true);
                    jumpedHigh = true;
			    }

                if (!target->HasUnitMovementFlag(MOVEMENTFLAG_FALLING) && target->IsMoving() && jumpedHigh)
                    jumpedHigh = false;
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_yanzhu_sudsy_AuraScript::HandlePeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_yanzhu_sudsy_AuraScript();
        }
};

void AddSC_boss_yan_zhu_the_uncasked()
{
    new npc_uncle_gao();
    new boss_yan_zhu_the_uncasked();
    new npc_bubble_shield_yanzhu();
    new npc_fizzy_bubble_yanzhu();
    new npc_yeasty_brew_elemental_yanzhu();
    new spell_yanzhu_bloat();
    new spell_yanzhu_gushing_brew();
    new spell_yanzhu_blackout_brew();
    new spell_yeasty_alemental_ferment();
    new spell_yanzhu_carbonation();
    new spell_yanzhu_carbonation_damage();
    new spell_wall_of_suds();
    new spell_yanzhu_sudsy();
}
