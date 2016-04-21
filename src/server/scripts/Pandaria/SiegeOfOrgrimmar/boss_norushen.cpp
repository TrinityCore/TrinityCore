////////////////////////////////////////////////////////////////////
///
///    Heroes 2015(C)
///    Coded by DavetheBrave <3
///    Norushen: 100% Progress
////////////////////////////////////////////////////////////////////


#include "siege_of_orgrimmar.h"
#include "MoveSplineInit.h"
#include "Group.h"

/*
General Information: (Icy-veins.com):

p_Difficulty	Amalgam of Corruption	Manifestation of Corruption	Essence of Corruption	Greater Corruption
10-man	261M	1.3M	600K	3M
10-man Heroic	702M	6M	1M	1.3M
25-man	1.1B	900K	675K	???
25-man Heroic	1.95B	1.3M	1M	???
LFR	???M	???	???	???
p_Difficulty	Titanic Corruption	Unleashed Manifestation of Corruption	Unleashed Essence of Corruption
10-man	???	5M	2M
10-man Heroic	6.5M	6M	3.1M
25-man	???	4M	2M
25-man Heroic	???	6M	3.16M
LFR	???	???	???

1.2. Enrage Timer
The fight has a hard enrage timer of 7 minutes, at which point your raid will instantly wipe.
*/

enum eSpells
{
    // Visuals
    SPELL_ALMEGALEM_EMOTE_ROAR        = 34999,
    SPELL_NORUSHEN_LIGHT_CIRCLE       = 149634,
    SPELL_NORUSHEN_LIGHT_TELEPORT     = 145188,
    SPELL_NORUSHEN_SHA_VISUALS        = 145144,
    SPELL_NORUSHEN_FULL_PRE_BOSS_VISUAL = 145143,
    SPELL_NORUSHEN_UNKNOWN_HOLY_PALM    = 145145,
    SPELL_NORUSHEN_SUMMON_BOSS          = 145149,
    SPELL_NORUSHEN_COLOR                = 145140,
    SPELL_NORUSHEN_EXTRACT_CORRUPTION   = 145139,
    SPELL_AMAGALAM_EMERGE               = 120475,
    SPELL_SERENITY_PHASE_MOBS_COSMETIC  = 145571, // Upon summon on real realm.
    // Mechanique
    SPELL_PURIFIED                      = 144452,
    SPELL_CORRUPTION                    = 144421,
    //SPELL_CORRUPTION = 144421,
    SPELL_QUARNTINE_SAFETY_MEASURES     = 145779,
    // Amalgam of Corruption
    SPELL_UNLEASHED_ANGER               = 145212,
    SPELL_SELF_DOUBT                    = 146124,
    SPELL_FUSION                        = 145132,
    SPELL_ICY_FEAR_AURA                 = 145733,
    SPELL_ICY_FEAR_DAMAGE               = 145735,
    SPELL_FRAYED                        = 146179,
    SPELL_BLIND_HATRED_FULL             = 145226,
    SPELL_BLIND_HATRED_DAMAGE           = 145227,
    SPELL_UNLEASHED_MANIFESTATION       = 144739,
    SPELL_FOUL_LINK_AURA                = 149189,
    // Look Within -- Most likely will get hardcoded.
    SPELL_LOOK_WITHIN_VISUAL_BALL       = 144717,
    SPELL_LOOK_WITHIN_PHASEDPS          = 144724,
    SPELL_LOOK_WITHIN_PHASEHEAL         = 144726,
    SPELL_LOOK_WITHIN_PHASETANK         = 144727,
    // DPS
    SPELL_TEST_OF_SERENITY              = 144849,
    SPELL_TEAR_REALITY                  = 144482,
    // -- Essence Of Corruption
    SPELL_EXPEL_CORRUPTION_AREATRIGGER  = 144479,
    SPELL_EXPELLED_CORRUPTION           = 145134,
    // -- Manifestation of Corruption
    SPELL_BURST_OF_ANGER                = 147082,
    SPELL_RESIDUAL_CORRUPTION_DAMAGE    = 145073,
    SPELL_RESIDUAL_CORRUPTION_AURA      = 145074,
    SPELL_SUMMON_MANIFESTATION          = 144739,
    SPELL_SUMMON_ESSENCE                = 144733,
    // Heal
    SPELL_TEST_OF_RELIANCE              = 144850,
    // -- Greater Corruption
    SPELL_DISHEARTENING_LAUGH           = 146707,
    SPELL_BOTTOMLESS_PIT_DUMMY          = 146705,
    SPELL_BOTTOMLESS_DOT                = 146703,
    SPELL_BOTTOMLESS_AREATRIGGER        = 146793,
    SPELL_LINGERING_CORRUPTION          = 144514,
    // Tank
    SPELL_TEST_OF_CONFIDENCE            = 144851,
    // -- Titanic Corruption
    SPELL_TITANIC_SMASH                 = 144628,
    SPELL_TITANIC_CORRUPTION            = 144639,
    SPELL_HURL_CORRUPTION               = 144649,
    SPELL_BURST_OF_CORRUPTION           = 144507,
    SPELL_PIERCING_CORRUPTION           = 144657,
    // -- Manifestation Of Corruption
    SPELL_GREATER_CORRUPTION_SUMMON     = 144980,
    SPELL_TITANIC_CORRUPTION_SUMMON     = 144848,
    SPELL_ESSENCE_OF_CORRUPTION         = 144733,
    SPELL_MANIFESTATION_OF_CORRUPTION   = 144739,
    SPELL_ALMAGLEM_DEBUFF               = 145118,
    // -- Sun Tenderheart
    SPELL_FIRE_BOLT                     = 144522,
    // -- Leven Dawnblade
    SPELL_THREATENING_STRIKES           = 144527,
    SPELL_EXHAUSTED                     = 148424,
    SPELL_DAMAGE_DEALER                 = 144521
};

enum eEvents
{
    // -- Tests
    EVENT_TEST_OF_RELIANCE,
    EVENT_TEST_OF_SERENITY,
    EVENT_TEST_OF_CONFIDENCE,
    // -- Look Within
    EVENT_SPELL_LOOK_WITHIN,
    EVENT_FIRE_BOLT,
    EVENT_TAUNT,
    EVENT_THREATENING_STRIKES,
    EVENT_REACTIVATE_LOOK_WITHIN_TRIGGERS,
    // -- Titanic Corruption
    EVENT_PIERCING_CORRUPTION,
    EVENT_BURST_OF_CORRUPTION,
    EVENT_HURL_CORRUPTION,
    EVENT_TITANIC_SMASH,
    EVENT_CORRUPTION,
    // -- Greater Corruption
    EVENT_LINGERING_CORRUPTION,
    EVENT_BOTTOMLESS_PIT,
    EVENT_DISHEARTNING_LAUGH,
    // -- Amalgam Of Corruption
    EVENT_BLIND_HATRED_DAMAGE,
    EVENT_BLIND_HATRED_FULL,
    EVENT_FRAYED,
    EVENT_ICY_FEAR,
    EVENT_SELF_DOUBT,
    EVENT_UNLEASHED_ANGER,
    EVENT_FUSION,
    // -- Manifestation Of Corruption
    EVENT_BURST_ANGER,
    EVENT_RESIDUAL_CORRUPTION,
    EVENT_TEAR_REALITY,
    // -- Essence of Corruption
    EVENT_EXPEL_CORRUPTION,
    EVENT_QUARNTINE_MEASURES
};

enum eActions
{
    // -- Look Within
    ACTION_LOOK_WITHIN_ACTIVATE,
    ACTION_LOOK_WITHIN_DEACTIVATE,

    // -- Look Within (Spec category)
    ACTION_SUMMON_LOOK_WITHIN_TANK,
    ACTION_SUMMON_LOOK_WITHIN_DPS,
    ACTION_SUMMON_LOOK_WITHIN_HEAL,
    ACTION_COUNT_SERENITY_PHASE_KILLS,

    // -- Encounter Flow
    ACTION_BOOLEANS_BASIC_EVENT,
    ACTION_BOOLEANS_BASIC_EVENT01
};

enum eCreatures
{
    BOSS_AMAGLAM_OF_CORRUPTION                        = 72276,
    CREATURE_BOSS_NORUSHEN                            = 71967,
    CREATURE_LORE_WALKER_CHO                          = 72872,
    CREATURE_TITANIC_CORRUPTION                       = 72051,
    CREATURE_ESSENCE_OF_CORRUPTION                    = 71976,  // Look Within
    CREATURE_UNLEASHED_ESSENCE_OF_CORRUPTION          = 72263,  // Unleahsed Corruption
    CREATURE_MANIFESTATION_OF_CORRUPTION              = 72264,  // Look Within
    CREATURE_UNLEASHED_MANIFESTATION_OF_CORRUPTION    = 71977,  // Unleahsed Corruption
    CREATURE_GREATER_CORRUPTION                       = 72001,
    CREATURE_BLIND_HATRED_TRIGGER                     = 72595,  // Custom
    CREATURE_LOOK_WITHIN_TEST_TRIGGER                 = 765321, // Custom
    CREATURE_ROOK_STONE_TOE                           = 71996,
    CREATURE_SUN_TENDER_HEART                         = 72000,
    CREATURE_LEVEN_DAWN                               = 71995,
    CREATURE_RESIDUAL_CORRUPTION                      = 72550,
    CREATURE_BOTTOMLESS_PIT                           = 954313  // Custom
};

enum eTalks
{
    // -- Norushen
    TALK_NORUSHEN_PRE_WIN01                  = 10, ///< Halt!
    TALK_NORUSHEN_PRE_WIN02                  = 11, ///< No further corruption will enter the Hearth Chamber
    TALK_NORUSHEN_PRE_WIN03                  = 12, ///< You wish to purge the corruption?
    TALK_NORUSHEN_PRE_WIN04                  = 13, ///< Should you pass this door at this door, at this time.. you will fail. You.. all of you are corrupted with the incidious plague known as Pride. You stand tall and pround at top of your accomplishment.. and this will be your downfall. Should you wish to defeat the Corruption.. you first will need to defeat the Corruption within yourself.
    TALK_NORUSHEN_PRE_WIN05                  = 14, ///< Speak to me again when you're prepared to face your inner demons.
    TALK_NORUSHEN_PRE_WIN06                  = 15, ///< Very well, I will create a field to keep your corruption maintained.
    TALK_NORUSHEN_PRE_WIN07                  = 16, ///< Prove yourself worthy, and I will let you pass!
    TALK_NORUSHEN_POST_WIN01                 = 17, ///< The light will not suffer your taint!
    TALK_NORUSHEN_POST_WIN02                 = 18, ///< You have been judged, and proving yourself worthy.. but be warned, what rise beyond will tie your soul to the utmost.. when you're fully prepared, you may enter the chamber.
    TALK_NORUSHEN_SPELL01                    = 19, ///< Look inside yourself and cleanse the Darkness within!
    TALK_NORUSHEN_SPELL02                    = 20, ///< Face your inner demons!
    TALK_NORUSHEN_SPELL03                    = 21, ///< Be purified by the light!
    TALK_NORUSHEN_SPELL04                    = 22, ///< Stand in the light and be judged!
    TALK_NORUSHEN_KILL01                     = 23, ///< Unworthy!
    TALK_NORUSHEN_KILL02                     = 24, ///< Only the pure of heart may pass!
    TALK_NORUSHEN_AGGRO                      = 25, ///< The light cleanses, but it is not gentle, courage yourself and be purified!

    // -- Lorewalker Cho
    TALK_LORE_WALKER_CHO_PRE_FIGHT_INTRO01  = 26, ///< Oh my.. what is this? I am Lorewalker Cho!
    TALK_LORE_WALKER_CHO_PRE_FIGHT_INTRO02  = 27, ///< Further.. corruption? Oh, no we're here to stop the corruption and save Pandaria!
    TALK_LORE_WALKER_CHO_PRE_FIGHT_INTRO03  = 28  ///< Yes.. please let us pass!
};

enum eObjects
{
    GobjectSmallShaWall           = 221602,
    GobjectPrideDoor              = 221446,
    GobjectNorushenDoor           = 221447,
    GobjectLightContainmentFront  = 223142,
    GobjectLightContainmentRight  = 223143,
    GobjectLightContainentBottom  = 223144,
    GobjectLightContainmentLeft   = 223145,
    GobjectLightContainmentTop    = 223146,
    GobjectLightContainmentBack   = 223147,
    GobjectNorushenLoot10         = 10,
    GobjectNorushenLoot10Hc       = 11,
    GobjectNorushenLoot25         = 12,
    GobjectNorushenLoot25Hc       = 13
};

enum eMovementInformed
{
    MOVEMENT_INFORM_LEAVING_BOTTOMLESS_PIT = 1,
};

Position const g_NorushenResetPoint          = { 769.62f,   1008.693f, 356.07f };

Position const g_ChoMovementPostConversation = { 804.78f,   845.828f,  371.16f };

Position const g_AmagalamOfCorruptionSpawn   = { 777.35f,   974.478f,  356.34f, 4.938567f };

Position const g_NorushenTeleport            = { 795.73f,   888.074f,  371.12f, 1.764025f };

Position const g_PrideDoor                   = { 762.31f,   1046.564f, 357.15f, 1.752039f };

Position const g_NorushenDoor                = { 848.50f,   880.338f,  371.80f, 3.368406f };

Position const g_LightContainment[5] =
{
    { 809.661f, 1024.667f, 356.29f, 4.908488f }, /// l_LightContainmentFront01
    { 809.661f, 1024.667f, 356.29f, 4.908488f }, /// l_LightContainmentRight02
    { 809.6614f, 1024.668f, 356.3f, 4.936758f }, /// l_LightContainmentBottom03
    { 745.756f, 919.943f, 356.00f, 4.882205f },  /// l_LightContainmentLeft04
    { 811.42f, 1027.071f, 356.00f, 4.936758f }   /// l_LightContainmentTop05
};

Position const g_BlindRayTrigger[2]          =
{
    { 738.875f, 964.258f, 356.0176f, 6.032867f }, /// Clock wise
    { 815.578f, 978.278f, 356.032f, 3.380130f  }, /// Counter Clockwise
};

Position const g_TestsOrbSpawnLocs[4]        =
{
    { 803.52f, 963.911f, 356.340f, 1.943064f  },
    { 767.16f, 949.509f, 356.340f, 1.719070f  },
    { 751.17f, 984.284f, 356.339f, 0.085333f  },
    { 788.83f, 1000.290f, 356.340f, 4.966589f },
};

Position const g_TitanicCorruption           = {777.48f, 974.323f, 356.340f, 4.895750f};

Position const g_GreaterCorruption           = { 777.48f, 974.323f, 356.340f, 4.895750f};

#define NpcGossipInfo 600
#define FactionFriendly 35
#define FactionHostile 16

uint32 l_GobjectEntries[6] = { GobjectLightContainmentFront, GobjectLightContainmentRight, GobjectLightContainmentTop, GobjectLightContainmentLeft, GobjectLightContainmentBack, GobjectLightContainentBottom };

static void DespawnCreaturesInArea(Creature* p_Me, uint32 p_Entry, bool p_GameObject) /// True - deleting gobjects, false - deleting creatures
{
    if (p_Entry <= 0)
        return;

    if (!p_Me)
        return;

    if (p_GameObject == true)
    {
        if (GameObject* l_GameObject = p_Me->FindNearestGameObject(p_Entry, 300.0f))
        {
            l_GameObject->SetLootState(LootState::GO_READY);
            l_GameObject->UseDoorOrButton(10 * TimeConstants::IN_MILLISECONDS, false, p_Me);
        }
    }
    else
    {
        std::list<Creature*> l_CreatureList;
        GetCreatureListWithEntryInGrid(l_CreatureList, p_Me, p_Entry, 400.0f);
        if (l_CreatureList.empty())
            return;

        for (std::list<Creature*>::iterator iter = l_CreatureList.begin(); iter != l_CreatureList.end(); ++iter)
            (*iter)->DespawnOrUnsummon();
    }
}

/// Pre Norushen Basic Event
class basicevent_norushen_player_cosmetic : public BasicEvent
{
public:

    explicit basicevent_norushen_player_cosmetic(Unit* p_Unit, int p_Value) : m_Obj(p_Unit), m_Modifier(p_Value) { }

    bool Execute(uint64 p_CurrTime, uint32 p_Diff)
    {
        if (InstanceScript* l_Instance = m_Obj->GetInstanceScript())
        {
            if (Creature* i_Norushen = l_Instance->instance->GetCreature(l_Instance->GetObjectGuid(eData::DATA_NORUSHEN_BOSS)))
            {
                if (Creature* i_Trigger = l_Instance->instance->GetCreature(l_Instance->GetObjectGuid(eData::DATA_NORUSHEN_TRIGGER))) ///< Controller, responsible for the boss summoning.
                {
                    if (i_Norushen->IsAIEnabled)
                    {
                        //< Calls the visuals
                        std::list<Player*> l_ListPlayers;
                        i_Norushen->GetPlayerListInGrid(l_ListPlayers, 200.0f);
                        if (!l_ListPlayers.empty())
                        {
                            for (auto itr : l_ListPlayers)
                            {
                                if (itr->IsInWorld() && itr->IsAlive())
                                {
                                    itr->CastSpell(i_Trigger, eSpells::SPELL_NORUSHEN_COLOR, true);
                                }
                            }
                        }

                        i_Trigger->m_Events.AddEvent(new basicevent_norushen_player_cosmetic(i_Trigger, 0), i_Trigger->m_Events.CalculateTime(2 * TimeConstants::IN_MILLISECONDS));
                        return true;
                    }
                }
            }
        }

        return true;
    }

private:

    Unit* m_Obj;
    int m_Modifier;
};

/// Phase players back autoamtically
class basicevent_norushen_player_phase_back : public BasicEvent
{
public:

    explicit basicevent_norushen_player_phase_back(uint32 p_Guid, int p_Value) : m_Obj(p_Guid), m_Modifier(p_Value) { }

    bool Execute(uint64 p_CurrTime, uint32 p_Diff)
    {
        if (Player* l_Player = sObjectMgr->GetPlayerByLowGUID(m_Obj))
        {
            l_Player->SetPhaseMask(1, true);
        }
        return true;
    }

private:

    uint32 m_Obj;
    int m_Modifier;
};

/// Phase players back autoamtically
class basicevent_norushen_despawnall : public BasicEvent
{
public:

    explicit basicevent_norushen_despawnall(Creature* me, int p_Value) : m_Obj(me), m_Modifier(p_Value) { }

    bool Execute(uint64 p_CurrTime, uint32 p_Diff)
    {
        uint32 l_Entries[9] = { eCreatures::CREATURE_GREATER_CORRUPTION,
            eCreatures::CREATURE_ESSENCE_OF_CORRUPTION,
            eCreatures::CREATURE_UNLEASHED_ESSENCE_OF_CORRUPTION,
            eCreatures::CREATURE_TITANIC_CORRUPTION,
            eCreatures::CREATURE_MANIFESTATION_OF_CORRUPTION,
            eCreatures::CREATURE_UNLEASHED_MANIFESTATION_OF_CORRUPTION,
            eCreatures::CREATURE_ROOK_STONE_TOE,
            eCreatures::CREATURE_SUN_TENDER_HEART,
            eCreatures::CREATURE_LEVEN_DAWN
        };

        for (uint32 l_I = 0; l_I < 10; l_I++)
            DespawnCreaturesInArea(m_Obj, l_Entries[l_I], false);
        return true;
    }

private:

    Creature* m_Obj;
    int m_Modifier;
};

/// Pre Norushen Basic Event
class pre_norushen_rp : public BasicEvent
{
public:

    explicit pre_norushen_rp(Unit* p_Unit, int p_Value) : m_Obj(p_Unit), m_Modifier(p_Value) { }

    bool Execute(uint64 p_CurrTime, uint32 p_Diff)
    {
        if (InstanceScript* l_Instance = m_Obj->GetInstanceScript())
        {
            if (Creature* i_Norushen = l_Instance->instance->GetCreature(l_Instance->GetObjectGuid(eData::DATA_NORUSHEN_BOSS)))
            {
                if (Creature* i_Cho = l_Instance->instance->GetCreature(l_Instance->GetObjectGuid(eData::DATA_NORUSHEN_CHO)))
                {
                    if (Creature* i_Trigger = l_Instance->instance->GetCreature(l_Instance->GetObjectGuid(eData::DATA_NORUSHEN_TRIGGER))) ///< Controller, responsible for the boss summoning.
                    {
                        if (i_Cho->IsAIEnabled && i_Norushen->IsAIEnabled)
                        {
                            switch (m_Modifier)
                            {
                                // Pre Gossip
                            case 0:
                                i_Trigger->SetFlag(UNIT_FIELD_FLAGS, UnitFlags::UNIT_FLAG_DISABLE_MOVE | UnitFlags::UNIT_FLAG_IMMUNE_TO_PC | UnitFlags::UNIT_FLAG_NON_ATTACKABLE);
                                i_Norushen->AI()->Talk(eTalks::TALK_NORUSHEN_PRE_WIN01);

                                // Summons a controller
                                i_Norushen->SummonCreature(CREATURE_TRIGGER, g_NorushenResetPoint.GetPositionX(), g_NorushenResetPoint.GetPositionY(), g_NorushenResetPoint.GetPositionZ(), g_NorushenResetPoint.GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);
                                i_Norushen->m_Events.AddEvent(new pre_norushen_rp(i_Norushen, 1), i_Norushen->m_Events.CalculateTime(8 * TimeConstants::IN_MILLISECONDS));
                                break;
                            case 1:
                                i_Cho->AI()->Talk(eTalks::TALK_LORE_WALKER_CHO_PRE_FIGHT_INTRO01);
                                i_Cho->GetMotionMaster()->MovePoint(0, 797.451f, 882.302f, 371.114f);
                                i_Cho->m_Events.AddEvent(new pre_norushen_rp(i_Cho, 2), i_Cho->m_Events.CalculateTime(10 * TimeConstants::IN_MILLISECONDS));
                                break;
                            case 2:
                                i_Norushen->AI()->Talk(eTalks::TALK_NORUSHEN_PRE_WIN02);
                                i_Norushen->m_Events.AddEvent(new pre_norushen_rp(i_Norushen, 3), i_Norushen->m_Events.CalculateTime(8 * TimeConstants::IN_MILLISECONDS));
                                break;
                            case 3:
                                i_Cho->AI()->Talk(eTalks::TALK_LORE_WALKER_CHO_PRE_FIGHT_INTRO02);
                                i_Cho->m_Events.AddEvent(new pre_norushen_rp(i_Cho, 4), i_Cho->m_Events.CalculateTime(10 * TimeConstants::IN_MILLISECONDS));
                                break;
                            case 4:
                                i_Norushen->AI()->Talk(eTalks::TALK_NORUSHEN_PRE_WIN03);
                                i_Norushen->m_Events.AddEvent(new pre_norushen_rp(i_Norushen, 5), i_Norushen->m_Events.CalculateTime(8 * TimeConstants::IN_MILLISECONDS));
                                break;
                            case 5:
                                i_Cho->AI()->Talk(eTalks::TALK_LORE_WALKER_CHO_PRE_FIGHT_INTRO03);
                                i_Cho->m_Events.AddEvent(new pre_norushen_rp(i_Cho, 6), i_Cho->m_Events.CalculateTime(10 * TimeConstants::IN_MILLISECONDS));
                                break;
                            case 6:
                                i_Norushen->AI()->Talk(eTalks::TALK_NORUSHEN_PRE_WIN04);
                                i_Norushen->m_Events.AddEvent(new pre_norushen_rp(i_Norushen, 7), i_Norushen->m_Events.CalculateTime(32 * TimeConstants::IN_MILLISECONDS));
                                break;
                            case 7:
                                i_Norushen->AI()->Talk(eTalks::TALK_NORUSHEN_PRE_WIN05);
                                i_Norushen->AI()->DoAction(eActions::ACTION_BOOLEANS_BASIC_EVENT);

                                i_Norushen->m_Events.AddEvent(new pre_norushen_rp(i_Norushen, 8), i_Norushen->m_Events.CalculateTime(8 * TimeConstants::IN_MILLISECONDS));
                                break;
                            case 8:
                                i_Cho->NearTeleportTo(g_ChoMovementPostConversation.GetPositionX(), g_ChoMovementPostConversation.GetPositionY(), g_ChoMovementPostConversation.GetPositionZ(), g_ChoMovementPostConversation.GetOrientation());
                                break;
                                // Post Gossip
                            case 10:
                                i_Norushen->AI()->DoAction(eActions::ACTION_BOOLEANS_BASIC_EVENT01);
                                i_Norushen->AI()->Talk(eTalks::TALK_NORUSHEN_PRE_WIN06);
                                i_Norushen->CastSpell(i_Norushen, eSpells::SPELL_NORUSHEN_LIGHT_TELEPORT, false);

                                i_Norushen->m_Events.AddEvent(new pre_norushen_rp(i_Norushen, 11), i_Norushen->m_Events.CalculateTime(5 * TimeConstants::IN_MILLISECONDS));
                                i_Norushen->m_Events.AddEvent(new pre_norushen_rp(i_Norushen, 9), i_Norushen->m_Events.CalculateTime(3 * TimeConstants::IN_MILLISECONDS));
                                i_Trigger->m_Events.AddEvent(new basicevent_norushen_player_cosmetic(i_Trigger, 0), i_Trigger->m_Events.CalculateTime(1 * TimeConstants::IN_MILLISECONDS));
                                break;
                            case 9:
                                i_Norushen->NearTeleportTo(795.910f, 886.482f, 371.125f, 1.810931f);
                                break;
                            case 11:
                                i_Norushen->CastSpell(g_AmagalamOfCorruptionSpawn.GetPositionX(), g_AmagalamOfCorruptionSpawn.GetPositionY(), g_AmagalamOfCorruptionSpawn.GetPositionZ(), eSpells::SPELL_NORUSHEN_FULL_PRE_BOSS_VISUAL, false);

                                for (uint32 l_I = 0; l_I < 6; l_I++)
                                {
                                    DespawnCreaturesInArea(i_Norushen, l_GobjectEntries[l_I], true); // Activates the doors. (Should be prespawned). [Light containment]
                                }

                                i_Cho->SetFacingToObject(i_Trigger);
                                //i_Norushen->SetFacingToObject(i_Trigger);
                                i_Norushen->m_Events.AddEvent(new pre_norushen_rp(i_Norushen, 12), i_Norushen->m_Events.CalculateTime(15 * TimeConstants::IN_MILLISECONDS));
                                break;
                            case 12:
                                i_Trigger->CastSpell(i_Trigger, eSpells::SPELL_NORUSHEN_SUMMON_BOSS);
                                i_Trigger->m_Events.KillAllEvents(true);
                                break;

                                // Post Boss Kill
                            case 20:
                                //   i_Norushen->AI()->Talk(eTalks::TalkKoramar06);
                                break;
                            case 21:
                                //  i_Norushen->AI()->Talk(eTalks::TalkKoramar06);
                                break;
                            default:
                                break;
                            }
                        }
                    }
                }
            }
        }

        return true;
    }

private:

    Unit* m_Obj;
    int m_Modifier;
};

/// Lorewalker Cho - 72872
class creature_lorewalker_cho_pre_norushen : public CreatureScript
{
public:

    creature_lorewalker_cho_pre_norushen() : CreatureScript("creature_lorewalker_cho_pre_norushen") { }

    struct creature_lorewalker_cho_pre_norushenAI : public ScriptedAI
    {
        creature_lorewalker_cho_pre_norushenAI(Creature* p_Creature) : ScriptedAI(p_Creature)
        {
            m_Instance = p_Creature->GetInstanceScript();
            m_Intro = false;
        }

        InstanceScript* m_Instance;
        bool m_Intro;

        void Reset() override
        {
            me->SetSpeed(UnitMoveType::MOVE_RUN, 0.8f);
        }

        void UpdateAI(const uint32 p_Diff) override
        {
            if (!m_Intro)
            {
                /*if (Player* l_Player = me->FindNearestPlayer(30.0f, true))
                {
                    m_Intro = true;
                    me->m_Events.AddEvent(new pre_norushen_rp(me, 0), me->m_Events.CalculateTime(4 * TimeConstants::IN_MILLISECONDS)); // post gossip
                }*/
            }
        }
    };

    CreatureAI* GetAI(Creature* p_Creature) const override
    {
        return new creature_lorewalker_cho_pre_norushenAI(p_Creature);
    }
};

/// Norushen - 719600
class boss_norushen : public CreatureScript
{
public:

    boss_norushen() : CreatureScript("boss_norushen") { }

    bool OnGossipHello(Player * p_Player, Creature * p_Creature) override
    {
        if (boss_norushenAI* l_LinkAI = CAST_AI(boss_norushenAI, p_Creature->GetAI()))
        {
            if (l_LinkAI->m_Gossip)
            {
                p_Player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Debugging text - start the fight (Summon Almegalem of Corruption)", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                p_Player->SEND_GOSSIP_MENU(1, p_Creature->GetGUID());
            }
        }

        return true;
    }

    bool OnGossipSelect(Player * p_Player, Creature * p_Creature, uint32 p_Sender, uint32 p_Actions) override
    {
        p_Player->PlayerTalkClass->ClearMenus();

        if (p_Sender == GOSSIP_SENDER_MAIN)
        {
            switch (p_Actions)
            {
                case GOSSIP_ACTION_INFO_DEF + 1: // Mall
                    p_Creature->m_Events.AddEvent(new pre_norushen_rp(p_Creature, 10), p_Creature->m_Events.CalculateTime(4 * TimeConstants::IN_MILLISECONDS));
                    break;
            }
        }

        return true;
    }

    struct boss_norushenAI : public BossAI
    {
        boss_norushenAI(Creature* p_Creature) : ScriptedAI(p_Creature)
        {
            m_Instance = p_Creature->GetInstanceScript();

            m_Intro = false;
            m_Gossip = false;
        }

        InstanceScript* m_Instance;
        std::list<uint64> m_WallList;
        bool m_Intro;
        bool m_Gossip;
        bool m_Battle;

        void Reset() override
        {
            events.Reset();
            summons.DespawnAll();

            if (me->isDead())
                me->Respawn(true);

            m_Battle = false;
            me->setFaction(FactionFriendly);
            me->SetReactState(ReactStates::REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UnitFlags::UNIT_FLAG_IMMUNE_TO_NPC | UnitFlags::UNIT_FLAG_NON_ATTACKABLE | UnitFlags::UNIT_FLAG_IMMUNE_TO_NPC);
            me->m_Events.AddEvent(new basicevent_norushen_despawnall(me, 0), me->m_Events.CalculateTime(6 * TimeConstants::IN_MILLISECONDS));
        }

        void JustReachedHome() override
        {
            summons.DespawnAll();

            if (m_Instance != nullptr)
            {
                // Reset handling - encounter.
                if (Creature * l_Amagalem = m_Instance->instance->GetCreature(m_Instance->GetObjectGuid(eData::DATA_NORUSHEN_ALMAGLEM_OF_CORRUPTION)))
                {
                    l_Amagalem->DespawnOrUnsummon();
                }

                for (uint32 l_I = 0; l_I < 6; l_I++)
                {
                     DespawnCreaturesInArea(me, l_GobjectEntries[l_I], true); // Deactivates the doors. (Should be prespawned). [Light containment]
                }

                me->NearTeleportTo(779.308f, 969.727f, 356.339f, 4.920256f);
                me->SetFacingTo(4.920256f);
                m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);;
            }
        }

        void DoAction(const int32 p_Action) override
        {
            switch (p_Action)
            {
                case eActions::ACTION_BOOLEANS_BASIC_EVENT:
                    m_Gossip = true;
                    break;
                case eActions::ACTION_BOOLEANS_BASIC_EVENT01:
                {
                    if (!m_Battle)
                        m_Battle = true;

                    if (m_Gossip)
                        m_Gossip = false;
                    break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* p_Creature) const override
    {
        return new boss_norushenAI(p_Creature);
    }
};

/// Amalgam of Corruption - 72276
class boss_amagalad_of_corruption : public CreatureScript
{
public:

    boss_amagalad_of_corruption() : CreatureScript("boss_amagalad_of_corruption") { }

    struct boss_amagalad_of_corruptionAI : public BossAI
    {
        boss_amagalad_of_corruptionAI(Creature* p_Creature) : BossAI(p_Creature, eData::DATA_NORUSHEN_ALMAGLEM_OF_CORRUPTION)
        {
            m_Instance = p_Creature->GetInstanceScript();
            m_Intro = false;
            m_EmergeCosmetic = false;

            EntranceDoorActivation();
        }

        InstanceScript* m_Instance;
        uint32 m_LookWithinPhaseCount;
        uint32 m_FrayedPct;
        uint32 m_FrayedDiff;
        bool m_Intro;
        bool m_EmergeCosmetic;
        bool m_FirstFrayed;

        void Reset() override
        {
            _Reset();
            events.Reset();
            summons.DespawnAll();

            m_FirstFrayed = false;
            m_FrayedPct = 30;
            m_FrayedDiff = 3 * TimeConstants::IN_MILLISECONDS;
            m_LookWithinPhaseCount = 2;
            me->setFaction(16);

            me->NearTeleportTo(778.164f, 973.895f, 356.340f, 4.999618f);
            me->SetFlag(UNIT_FIELD_FLAGS, UnitFlags::UNIT_FLAG_DISABLE_MOVE);

            if (!m_EmergeCosmetic) // Emerge visual
            {
                m_EmergeCosmetic = true;
                me->CastSpell(me, 145571);
                me->CastSpell(me, eSpells::SPELL_AMAGALAM_EMERGE);
            }

            /// Disable all orbs
            std::list<Player*> l_PlayerList;
            me->GetPlayerListInGrid(l_PlayerList, 300.0f);
            if (l_PlayerList.empty())
                return;

            for (auto itr : l_PlayerList)
            {
                if (m_Instance != nullptr)
                {
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::SPELL_PURIFIED);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::SPELL_TEST_OF_SERENITY);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::SPELL_TEST_OF_RELIANCE);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::SPELL_TEST_OF_CONFIDENCE);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::SPELL_CORRUPTION);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::SPELL_LOOK_WITHIN_PHASEDPS);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::SPELL_LOOK_WITHIN_PHASEHEAL);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::SPELL_LOOK_WITHIN_PHASETANK);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::SPELL_SELF_DOUBT);
                }
            }
        }

        void MoveInLineOfSight(Unit* p_Who) override
        {
            if (p_Who && p_Who->IsInWorld() && p_Who->GetTypeId() == TypeID::TYPEID_PLAYER && me->IsWithinDistInMap(p_Who, 60.0f) && !m_Intro)
            {
                m_Intro = true;
            }
        }

        void EntranceDoorActivation() ///< Upon wipe
        {
            if (m_Instance != nullptr)
            {
                // Reset handling - encounter.
                if (GameObject * l_NorushenEntrance = m_Instance->instance->GetGameObject(m_Instance->GetObjectGuid(eData::DATA_NORUSHEN_ENTRANCE)))
                {
                    l_NorushenEntrance->SetLootState(LootState::GO_READY);
                    l_NorushenEntrance->UseDoorOrButton(10 * TimeConstants::IN_MILLISECONDS, false, me);
                }
            }
        }

        void ExitDoorActivation() ///< After boss defeat
        {
            if (m_Instance != nullptr)
            {
                // Reset handling - encounter.
                if (GameObject * l_PrideEntrance = m_Instance->instance->GetGameObject(m_Instance->GetObjectGuid(eData::DATA_PRIDE_ENTRANCE)))
                {
                    l_PrideEntrance->SetLootState(LootState::GO_READY);
                    l_PrideEntrance->UseDoorOrButton(10 * TimeConstants::IN_MILLISECONDS, false, me);
                }
            }
        }

        void SealAlemgalem() // Handles the light containment activation
        {
            for (uint32 l_I = 0; l_I < 6; l_I++)
            {
                DespawnCreaturesInArea(me, l_GobjectEntries[l_I], true); // Activates the doors. (Should be prespawned). [Light containment]
            }
        }

        void ActivateLookWithinTriggers()
        {
            /// Disable all orbs
            std::list<Creature*> l_OrbsList;
            me->GetCreatureListWithEntryInGrid(l_OrbsList, eCreatures::CREATURE_LOOK_WITHIN_TEST_TRIGGER, 200.0f);
            if (l_OrbsList.empty())
                return;

            for (uint8 l_I = 0; l_I < 2; l_I++)
            {
                Creature* l_Trigger = l_OrbsList.back();

                if (l_Trigger && l_Trigger->IsAIEnabled)
                    l_Trigger->GetAI()->DoAction(eActions::ACTION_LOOK_WITHIN_ACTIVATE);

                l_OrbsList.remove(l_Trigger);
            }
        }

        void DeactivateLookWithinTriggers()
        {
            /// Disable all orbs
            std::list<Creature*> l_OrbsList;
            me->GetCreatureListWithEntryInGrid(l_OrbsList, eCreatures::CREATURE_LOOK_WITHIN_TEST_TRIGGER, 200.0f);
            if (l_OrbsList.empty())
                return;

            for (auto itr : l_OrbsList)
            {
                if (itr->IsAIEnabled)
                    itr->AI()->DoAction(eActions::ACTION_LOOK_WITHIN_DEACTIVATE);
            }
        }

        void JustReachedHome() override
        {
            _JustReachedHome();
            summons.DespawnAll();

            DeactivateLookWithinTriggers();
            EntranceDoorActivation();

            if (m_Instance != nullptr)
            {
                // Reset handling - encounter.
                if (Creature * l_Norushen = m_Instance->instance->GetCreature(m_Instance->GetObjectGuid(eData::DATA_NORUSHEN_BOSS)))
                {
                    if (l_Norushen->IsAIEnabled)
                    {
                        if (boss_norushen::boss_norushenAI* l_LinkAI = CAST_AI(boss_norushen::boss_norushenAI, l_Norushen->GetAI()))
                        {
                            if (l_LinkAI->m_Battle)
                                l_LinkAI->m_Battle = false;

                            if (!l_LinkAI->m_Gossip)
                                l_LinkAI->m_Gossip = true;
                        }

                        l_Norushen->CastStop();
                        l_Norushen->AI()->JustReachedHome(); // Forces it.
                    }
                }

                m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::SPELL_PURIFIED);
                m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::SPELL_TEST_OF_SERENITY);
                m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::SPELL_TEST_OF_RELIANCE);
                m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::SPELL_TEST_OF_CONFIDENCE);
                m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::SPELL_CORRUPTION);
                m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);;
                m_Instance->SetBossState(eData::DATA_NORUSHEN_ALMAGLEM_OF_CORRUPTION, EncounterState::FAIL);
            }

            // Sets phase back to the value of 1
            std::list<Player*> l_ListPlayers;
            me->GetPlayerListInGrid(l_ListPlayers, 200.0f);
            if (!l_ListPlayers.empty())
            {
                for (auto itr : l_ListPlayers)
                {
                    itr->SetPhaseMask(1, true);
                }
            }

            uint32 l_Entries[9] = { eCreatures::CREATURE_GREATER_CORRUPTION,
                eCreatures::CREATURE_ESSENCE_OF_CORRUPTION,
                eCreatures::CREATURE_UNLEASHED_ESSENCE_OF_CORRUPTION,
                eCreatures::CREATURE_TITANIC_CORRUPTION,
                eCreatures::CREATURE_MANIFESTATION_OF_CORRUPTION,
                eCreatures::CREATURE_UNLEASHED_MANIFESTATION_OF_CORRUPTION,
                eCreatures::CREATURE_ROOK_STONE_TOE,
                eCreatures::CREATURE_SUN_TENDER_HEART,
                eCreatures::CREATURE_LEVEN_DAWN
            };

            for (uint32 l_I = 0; l_I < 10; l_I++)
                DespawnCreaturesInArea(me, l_Entries[l_I], false);

            me->DespawnOrUnsummon(500);
        }

        void KilledUnit(Unit* p_Who) override
        {
            if (m_Instance != nullptr)
            {
                if (p_Who->GetTypeId() == TypeID::TYPEID_PLAYER)
                {
                    if (Creature * l_Norushen = m_Instance->instance->GetCreature(m_Instance->GetObjectGuid(eData::DATA_NORUSHEN_BOSS)))
                    {
                        if (l_Norushen->IsAIEnabled)
                        {
                            switch (urand(0, 1))
                            {
                                case 0:
                                    l_Norushen->AI()->Talk(eTalks::TALK_NORUSHEN_KILL01);
                                    break;
                                case 1:
                                    l_Norushen->AI()->Talk(eTalks::TALK_NORUSHEN_KILL02);
                                    break;
                            }
                        }
                    }
                }
            }
        }

        void EnterCombat(Unit* p_Attacker) override
        {
            if (m_Instance != nullptr)
            {
                DoZoneInCombat();
                m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_ENGAGE, me);
                m_Instance->SetBossState(eData::DATA_NORUSHEN_ALMAGLEM_OF_CORRUPTION, IN_PROGRESS);
                m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::SPELL_CORRUPTION);

                EntranceDoorActivation();
                ActivateLookWithinTriggers();

                if (Creature * l_Norushen = m_Instance->instance->GetCreature(m_Instance->GetObjectGuid(eData::DATA_NORUSHEN_BOSS)))
                    l_Norushen->AI()->Talk(eTalks::TALK_NORUSHEN_AGGRO);

                // Corruption
                std::list<Player*> l_PlayerList;
                me->GetPlayerListInGrid(l_PlayerList, 250.0f);
                if (l_PlayerList.empty())
                    return;

                for (auto itr : l_PlayerList)
                {
                    itr->CastSpell(itr, eSpells::SPELL_CORRUPTION);
                }
            }

            events.ScheduleEvent(eEvents::EVENT_QUARNTINE_MEASURES, 420000); ///< Wipe - 8 minutes
            events.ScheduleEvent(eEvents::EVENT_BLIND_HATRED_FULL, 8 * TimeConstants::IN_MILLISECONDS);
            events.ScheduleEvent(eEvents::EVENT_UNLEASHED_ANGER, 10 * TimeConstants::IN_MILLISECONDS);
        }

        void DamageTaken(Unit* p_Attacker, uint32& p_Damage) override
        {
            // Handles Frayed mechanism
            if (me->GetHealthPct() <= 50)
            {
                if (!m_FirstFrayed)
                {
                    if (m_Instance != nullptr)
                    {
                        if (Creature * l_Norushen = m_Instance->instance->GetCreature(m_Instance->GetObjectGuid(eData::DATA_NORUSHEN)))
                        {
                            if (l_Norushen->IsAIEnabled)
                                l_Norushen->AI()->Talk(eTalks::TALK_NORUSHEN_SPELL03);
                        }
                    }

                    m_FirstFrayed = true;
                    me->AddAura(eSpells::SPELL_FRAYED, me);

                    Position l_Pos;
                    me->GetRandomNearPosition(15.0f);
                    l_Pos.m_positionZ = me->GetPositionZ();
                    me->SummonCreature(eCreatures::CREATURE_UNLEASHED_MANIFESTATION_OF_CORRUPTION, l_Pos.GetPositionX(), l_Pos.GetPositionY(), l_Pos.GetPositionZ(), l_Pos.GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);
                }
                else
                {
                    if (me->HealthBelowPctDamaged(m_FrayedPct, p_Damage))
                    {
                        if (m_Instance != nullptr)
                        {
                            if (Creature * l_Norushen = m_Instance->instance->GetCreature(m_Instance->GetObjectGuid(eData::DATA_NORUSHEN)))
                            {
                                if (l_Norushen->IsAIEnabled)
                                    l_Norushen->AI()->Talk(eTalks::TALK_NORUSHEN_SPELL02);
                            }
                        }

                        if (Aura* l_Aura = me->GetAura(eSpells::SPELL_FRAYED))
                        {
                            l_Aura->SetStackAmount(l_Aura->GetStackAmount() + 1);
                        }

                        Position l_Pos;
                        me->GetRandomNearPosition(15.0f);
                        l_Pos.m_positionZ = me->GetPositionZ();
                        me->SummonCreature(eCreatures::CREATURE_UNLEASHED_MANIFESTATION_OF_CORRUPTION, l_Pos.GetPositionX(), l_Pos.GetPositionY(), l_Pos.GetPositionZ(), l_Pos.GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);

                        m_FrayedPct -= 10;
                    }
                }
            }
        }

        void JustDied(Unit* p_Killer) override
        {
            summons.DespawnAll();

            if (me->GetMap())
            {
                /// Loot
                switch (me->GetMap()->GetDifficultyID())
                {
                    case DIFFICULTY_10_N:
                        me->SummonGameObject(eObjects::GobjectNorushenLoot10, g_AmagalamOfCorruptionSpawn.GetPositionX(), g_AmagalamOfCorruptionSpawn.GetPositionY(), g_AmagalamOfCorruptionSpawn.GetPositionZ(), g_AmagalamOfCorruptionSpawn.GetOrientation(), 0, 0, 0, 0, 0);
                        break;
                    case DIFFICULTY_10_HC:
                        me->SummonGameObject(eObjects::GobjectNorushenLoot10Hc, g_AmagalamOfCorruptionSpawn.GetPositionX(), g_AmagalamOfCorruptionSpawn.GetPositionY(), g_AmagalamOfCorruptionSpawn.GetPositionZ(), g_AmagalamOfCorruptionSpawn.GetOrientation(), 0, 0, 0, 0, 0);
                        break;
                    case DIFFICULTY_25_N:
                        me->SummonGameObject(eObjects::GobjectNorushenLoot25, g_AmagalamOfCorruptionSpawn.GetPositionX(), g_AmagalamOfCorruptionSpawn.GetPositionY(), g_AmagalamOfCorruptionSpawn.GetPositionZ(), g_AmagalamOfCorruptionSpawn.GetOrientation(), 0, 0, 0, 0, 0);
                        break;
                    case DIFFICULTY_25_HC:
                        me->SummonGameObject(eObjects::GobjectNorushenLoot25Hc, g_AmagalamOfCorruptionSpawn.GetPositionX(), g_AmagalamOfCorruptionSpawn.GetPositionY(), g_AmagalamOfCorruptionSpawn.GetPositionZ(), g_AmagalamOfCorruptionSpawn.GetOrientation(), 0, 0, 0, 0, 0);
                        break;
                }
            }

            if (m_Instance != nullptr)
            {
                SealAlemgalem(); // Despawns the boses
                ExitDoorActivation();
                EntranceDoorActivation();
                DeactivateLookWithinTriggers();

                m_Instance->SetBossState(eData::DATA_NORUSHEN_BOSS, DONE);
                m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::SPELL_PURIFIED);
                m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::SPELL_TEST_OF_SERENITY);
                m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::SPELL_TEST_OF_RELIANCE);
                m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::SPELL_TEST_OF_CONFIDENCE);
                m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::SPELL_CORRUPTION);
                m_Instance->DoRemoveAurasDueToSpellOnPlayers(144724);
                /// Execute RP event pre sha of pride
                me->m_Events.AddEvent(new pre_norushen_rp(me, 20), me->m_Events.CalculateTime(15 * TimeConstants::IN_MILLISECONDS));
            }
        }

        void UpdateAI(const uint32 p_Diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(p_Diff);

            if (m_FrayedDiff <= p_Diff)
            {
                std::list<Player*> l_ListPlayers;
                me->GetPlayerListInGrid(l_ListPlayers, 250.0f);
                if (!l_ListPlayers.empty())
                {
                    me->CastSpell(me, eSpells::SPELL_ICY_FEAR_AURA, true);

                    for (auto itr : l_ListPlayers)
                    {
                        itr->CastSpell(itr, eSpells::SPELL_ICY_FEAR_DAMAGE, true);
                    }
                }

                m_FrayedDiff = 3 * TimeConstants::IN_MILLISECONDS;
            }
            else
                m_FrayedDiff -= p_Diff;

            if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                return;

            if (Unit* l_Victim = me->GetVictim())
            {
                switch (events.ExecuteEvent())
                {
                    case eEvents::EVENT_QUARNTINE_MEASURES:
                    {
                        if (m_Instance != nullptr)
                        {
                            if (Creature * l_Norushen = m_Instance->instance->GetCreature(m_Instance->GetObjectGuid(eData::DATA_NORUSHEN_BOSS)))
                                l_Norushen->CastSpell(me, eSpells::SPELL_QUARNTINE_SAFETY_MEASURES);
                        }
                        break;
                    }
                   case eEvents::EVENT_BLIND_HATRED_FULL:
                       if (m_Instance != nullptr)
                       {
                           if (Creature * l_Norushen = m_Instance->instance->GetCreature(m_Instance->GetObjectGuid(eData::DATA_NORUSHEN)))
                           {
                               if (l_Norushen->IsAIEnabled)
                                   l_Norushen->AI()->Talk(eTalks::TALK_NORUSHEN_SPELL04);
                           }
                       }

                        me->CastSpell(me, eSpells::SPELL_BLIND_HATRED_FULL);
                        events.ScheduleEvent(eEvents::EVENT_BLIND_HATRED_FULL, 60 * TimeConstants::IN_MILLISECONDS);
                        break;
                   case eEvents::EVENT_UNLEASHED_ANGER:
                       me->CastSpell(l_Victim, eSpells::SPELL_UNLEASHED_ANGER);
                       events.ScheduleEvent(eEvents::EVENT_UNLEASHED_ANGER, 10 * TimeConstants::IN_MILLISECONDS);
                       break;
                }

                DoMeleeAttackIfReady();
            }
        }
    };

    CreatureAI* GetAI(Creature* p_Creature) const override
    {
        return new boss_amagalad_of_corruptionAI(p_Creature);
    }
};

/// Blind Hatred - 145227
class BlindingHatredSelector
{
public:

    BlindingHatredSelector(Unit* p_Caster, Unit* p_CutterCaster) : _p_Caster(p_Caster), _p_CutterCaster(p_CutterCaster) {}

    bool operator()(WorldObject* p_Unit) const
    {
        return !p_Unit->IsInBetween(_p_Caster, _p_CutterCaster, 1.0f);
    }

private:

    Unit* _p_Caster;
    Unit* _p_CutterCaster;
};

/// Blind Hatred Trigger - 72595
class creature_blind_hatred_trigger : public CreatureScript
{
public:

    creature_blind_hatred_trigger() : CreatureScript("creature_blind_hatred_trigger") { }

    struct creature_blind_hatred_triggerAI : public BossAI
    {
        creature_blind_hatred_triggerAI(Creature* creature) : ScriptedAI(creature)
        {
            m_Instance = me->GetInstanceScript();
        }

        InstanceScript* m_Instance;
        uint32 m_DamageDiff;
        bool m_Clockwise;

        void Reset() override
        {
            events.Reset();
            m_Clockwise = true;
            m_DamageDiff = 2 * TimeConstants::IN_MILLISECONDS;

            switch (urand(0, 1))
            {
                case 0: // Clock wise
                    m_Clockwise = true;
                    me->NearTeleportTo(g_BlindRayTrigger[0].GetPositionX(), g_BlindRayTrigger[0].GetPositionY(), g_BlindRayTrigger[0].GetPositionZ(), g_BlindRayTrigger[0].GetOrientation(), true);
                    break;
                case 1: // Counter Clock Wise
                    m_Clockwise = false;
                    me->NearTeleportTo(g_BlindRayTrigger[1].GetPositionX(), g_BlindRayTrigger[1].GetPositionY(), g_BlindRayTrigger[1].GetPositionZ(), g_BlindRayTrigger[1].GetOrientation(), true);
                    break;
            }

            me->SetDisplayId(11686);
            me->setFaction(FactionHostile);
            me->SetCanFly(true);
            me->SetDisableGravity(true);
            me->SetSpeed(UnitMoveType::MOVE_RUN, 2.0f);

            Movement::MoveSplineInit init(*me);
            FillCirclePath(g_AmagalamOfCorruptionSpawn, me->GetDistance2d(g_AmagalamOfCorruptionSpawn.GetPositionX(), g_AmagalamOfCorruptionSpawn.GetPositionY()), me->GetPositionZ(), init.Path(), m_Clockwise);
            init.SetWalk(true);
            init.SetCyclic();
            init.Launch();

            me->SetReactState(ReactStates::REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UnitFlags::UNIT_FLAG_IMMUNE_TO_PC | UnitFlags::UNIT_FLAG_IMMUNE_TO_NPC | UnitFlags::UNIT_FLAG_NON_ATTACKABLE | UnitFlags::UNIT_FLAG_NOT_SELECTABLE);
        }

        void UpdateAI(uint32 const p_Diff) override
        {
            if (m_Instance == nullptr)
                return;

            if (m_DamageDiff <= p_Diff)
            {
                std::list<Player*> l_ListPlayers;
                me->GetPlayerListInGrid(l_ListPlayers, 100.0f);

                if (l_ListPlayers.empty())
                    return;

                for (auto itr : l_ListPlayers)
                {
                    // Reset handling - encounter.
                    if (Creature* l_Almegalem = m_Instance->instance->GetCreature(m_Instance->GetObjectGuid(eData::DATA_NORUSHEN_ALMAGLEM_OF_CORRUPTION)))
                    {
                        if (itr->IsInBetween(l_Almegalem, me, 4.0f))
                            itr->CastSpell(itr, eSpells::SPELL_BLIND_HATRED_DAMAGE, true);
                    }
                }

                m_DamageDiff = 500;
            }
            else
                m_DamageDiff -= p_Diff;
        }

        void FillCirclePath(Position const& p_CenterPos, float p_Radius, float p_Z, Movement::PointsArray& p_Path, bool p_Clockwise)
        {
            float step = p_Clockwise ? -M_PI / 8.0f : M_PI / 8.0f;
            float angle = p_CenterPos.GetAngle(me->GetPositionX(), me->GetPositionY());
            float radius = p_Radius * 1.4142;

            for (uint8 i = 0; i < 16; angle += step, ++i)
            {
                G3D::Vector3 l_Point;
                l_Point.x = p_CenterPos.GetPositionX() + radius * cosf(angle);
                l_Point.y = p_CenterPos.GetPositionY() + radius * sinf(angle);
                l_Point.z = 356.340f;
                p_Path.push_back(l_Point);
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new creature_blind_hatred_triggerAI(creature);
    }
};

/// Look Within - 765321
class creature_look_within_trigger : public CreatureScript
{
public:

    creature_look_within_trigger() : CreatureScript("creature_look_within_trigger") { }

    bool OnGossipHello(Player* p_Player, Creature * p_Creature)
    {
        if (InstanceScript* l_Instance = p_Creature->GetInstanceScript())
        {
            if (p_Player->HasAura(eSpells::SPELL_PURIFIED)) // Doesn't work on purified targets
                return false;

            // Reset handling - encounter.
            if (Creature* l_Almegalem = l_Instance->instance->GetCreature(l_Instance->GetObjectGuid(eData::DATA_NORUSHEN_ALMAGLEM_OF_CORRUPTION)))
            {
                if (creature_look_within_triggerAI* l_MelinkAI = CAST_AI(creature_look_within_triggerAI, p_Creature->GetAI())) // Look Within AI link
                {
                    if (boss_amagalad_of_corruption::boss_amagalad_of_corruptionAI* l_AlmaglemlinkAI = CAST_AI(boss_amagalad_of_corruption::boss_amagalad_of_corruptionAI, l_Almegalem->GetAI())) // Look Within AI link
                    {
                        if (l_MelinkAI->m_PlayerGUID == 0)
                        {
                            /*if (p_Creature->IsAIEnabled)
                            {
                                l_MelinkAI->m_PlayerGUID = p_Player->GetGUID();
                                l_MelinkAI->m_OriginalPhasemask = p_Player->GetPhaseMask();
                                p_Player->SetPhaseMask(l_AlmaglemlinkAI->m_LookWithinPhaseCount, true);

                                if (p_Player->GetRoleForGroup(p_Player->GetSpecializationId(p_Player->GetActiveTalentGroup())) == ROLES_TANK)
                                {
                                    p_Creature->GetAI()->DoAction(eActions::ACTION_SUMMON_LOOK_WITHIN_TANK);
                                }
                                else if (p_Player->GetRoleForGroup(p_Player->GetSpecializationId(p_Player->GetActiveTalentGroup())) == ROLES_HEALER)
                                {
                                    p_Creature->GetAI()->DoAction(eActions::ACTION_SUMMON_LOOK_WITHIN_HEAL);
                                }
                                else
                                {
                                    p_Creature->GetAI()->DoAction(eActions::ACTION_SUMMON_LOOK_WITHIN_DPS);
                                }


                                l_AlmaglemlinkAI->m_LookWithinPhaseCount += 2;
                                printf("m_PhaseCount  = %u", l_AlmaglemlinkAI->m_LookWithinPhaseCount);
                                p_Player->m_Events.AddEvent(new basicevent_norushen_player_phase_back(p_Player->GetGUIDLow(), 0), p_Player->m_Events.CalculateTime(61 * TimeConstants::IN_MILLISECONDS));
                                printf("works");
                                return true;
                            }*/
                        }
                        else
                            return false;
                    }
                }
            }
        }
        return true;
    }

    struct creature_look_within_triggerAI : public BossAI
    {
        creature_look_within_triggerAI(Creature* p_Creature) : ScriptedAI(p_Creature)
        {
            m_Instance = p_Creature->GetInstanceScript();
        }

        InstanceScript* m_Instance;
        uint64 m_PlayerGUID;
        uint32 m_OriginalPhasemask;
        uint8 m_SerenityPhaseDeath;

        void Reset() override
        {
            events.Reset();

            m_PlayerGUID = 0;
            m_OriginalPhasemask = 2;
            m_SerenityPhaseDeath = 0;

            me->setFaction(FactionFriendly);
            me->SetReactState(ReactStates::REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UnitFlags::UNIT_FLAG_IMMUNE_TO_NPC | UnitFlags::UNIT_FLAG_NON_ATTACKABLE | UnitFlags::UNIT_FLAG_DISABLE_MOVE);
            me->SetFlag(UNIT_FIELD_FLAGS_2, UnitFlags2::UNIT_FLAG2_DISABLE_TURN);
        }

        void JustSummoned(Creature* p_Summon) override
        {
            summons.Summon(p_Summon);
        }

        void DoAction(const int32 p_Action) override
        {
            switch (p_Action)
            {
                case eActions::ACTION_COUNT_SERENITY_PHASE_KILLS:
                    m_SerenityPhaseDeath = m_SerenityPhaseDeath - 1;

                    if (m_SerenityPhaseDeath <= 0)
                    {
                        if (m_PlayerGUID != 0)
                        {
                            if (Player* l_Player = ObjectAccessor::GetPlayer(*me, GetGUID(m_PlayerGUID)))
                            {
                                l_Player->AddAura(eSpells::SPELL_PURIFIED, l_Player);
                                l_Player->SetPhaseMask(1, true);
                                l_Player->RemoveAura(eSpells::SPELL_TEST_OF_SERENITY);
                                l_Player->RemoveAura(eSpells::SPELL_LOOK_WITHIN_PHASEDPS);
                                DoAction(ACTION_LOOK_WITHIN_ACTIVATE);
                            }
                        }
                    }
                    break;
                // Upon gossip with trigger, it'll remove all visuals and apply temporary flags - and it'll be reactivated once again through an event. Instead of despawning them and spawning them like a mongos.
                case eActions::ACTION_LOOK_WITHIN_DEACTIVATE:
                    me->SetFlag(UNIT_FIELD_FLAGS, UnitFlags::UNIT_FLAG_IMMUNE_TO_PC | UnitFlags::UNIT_FLAG_IMMUNE_TO_NPC | UnitFlags::UNIT_FLAG_NOT_SELECTABLE);
                    me->RemoveAura(eSpells::SPELL_LOOK_WITHIN_VISUAL_BALL);

                    if (m_PlayerGUID != 0)
                    {
                        if (Player* l_Player = ObjectAccessor::GetPlayer(*me, GetGUID(m_PlayerGUID)))
                        {
                            me->SetPhaseMask(l_Player->GetPhaseMask(), true);
                        }
                    }

                    events.ScheduleEvent(eEvents::EVENT_REACTIVATE_LOOK_WITHIN_TRIGGERS, 100 * TimeConstants::IN_MILLISECONDS);
                    break;
                case eActions::ACTION_LOOK_WITHIN_ACTIVATE:
                    m_PlayerGUID = 0;
                    m_SerenityPhaseDeath = 0;
                    m_OriginalPhasemask = 1;
                    me->SetPhaseMask(1, true);

                    me->RemoveFlag(UNIT_FIELD_FLAGS, UnitFlags::UNIT_FLAG_IMMUNE_TO_PC | UnitFlags::UNIT_FLAG_IMMUNE_TO_NPC | UnitFlags::UNIT_FLAG_NOT_SELECTABLE);
                    me->AddAura(eSpells::SPELL_LOOK_WITHIN_VISUAL_BALL, me);
                    break;
                case eActions::ACTION_SUMMON_LOOK_WITHIN_TANK:
                {
                    if (m_PlayerGUID != 0)
                    {
                        if (Player* l_Player = ObjectAccessor::GetPlayer(*me, GetGUID(m_PlayerGUID)))
                        {
                            if (Creature* Titanic = l_Player->SummonCreature(eCreatures::CREATURE_TITANIC_CORRUPTION, g_AmagalamOfCorruptionSpawn, TEMPSUMMON_TIMED_DESPAWN, 60 * TimeConstants::IN_MILLISECONDS))
                            {
                                if (Titanic->IsAIEnabled)
                                    Titanic->AI()->SetGUID(me->GetGUID());

                                l_Player->AddAura(eSpells::SPELL_LOOK_WITHIN_PHASETANK, l_Player);
                                l_Player->AddAura(eSpells::SPELL_TEST_OF_CONFIDENCE, l_Player);
                                Titanic->SetPhaseMask(l_Player->GetPhaseMask(), true);
                            }
                        }
                    }

                    DoAction(eActions::ACTION_LOOK_WITHIN_DEACTIVATE);
                    break;
                }
                case eActions::ACTION_SUMMON_LOOK_WITHIN_HEAL:
                {
                    if (m_PlayerGUID != 0)
                    {
                        if (Player* l_Player = ObjectAccessor::GetPlayer(*me, GetGUID(m_PlayerGUID)))
                        {
                            uint32 l_Entries[3] = { CREATURE_SUN_TENDER_HEART, CREATURE_ROOK_STONE_TOE, CREATURE_LEVEN_DAWN };

                            for (uint8 l_I = 0; l_I < 4; l_I++)
                                DespawnCreaturesInArea(me, l_Entries[l_I], false);

                            if (Creature* l_GreaterCorruption = l_Player->SummonCreature(eCreatures::CREATURE_GREATER_CORRUPTION, g_AmagalamOfCorruptionSpawn, TempSummonType::TEMPSUMMON_TIMED_DESPAWN, 60 * TimeConstants::IN_MILLISECONDS))
                            {
                                if (l_GreaterCorruption->IsAIEnabled)
                                    l_GreaterCorruption->AI()->SetGUID(me->GetGUID());

                                for (uint32 l_I = 0; l_I < 3; l_I++)
                                {
                                    if (Creature * l_Pandaren = l_Player->SummonCreature(l_Entries[l_I], l_Player->GetPositionX(), l_Player->GetPositionY(), l_Player->GetPositionZ(), l_Player->GetOrientation(), TempSummonType::TEMPSUMMON_TIMED_DESPAWN, 60 * TimeConstants::IN_MILLISECONDS))
                                    {
                                        l_Pandaren->Attack(l_GreaterCorruption, true);
                                        l_Pandaren->SetPhaseMask(l_Player->GetPhaseMask(), true);
                                    }
                                }

                                l_GreaterCorruption->SetPhaseMask(l_Player->GetPhaseMask(), true);
                            }

                            l_Player->AddAura(eSpells::SPELL_TEST_OF_RELIANCE, l_Player);
                            l_Player->AddAura(eSpells::SPELL_LOOK_WITHIN_PHASEHEAL, l_Player);
                        }
                    }

                    DoAction(eActions::ACTION_LOOK_WITHIN_DEACTIVATE);
                    break;
                }
                case eActions::ACTION_SUMMON_LOOK_WITHIN_DPS:
                {
                    if (m_PlayerGUID != 0)
                    {
                        if (Player* l_Player = ObjectAccessor::GetPlayer(*me, GetGUID(m_PlayerGUID)))
                        {
                            if (l_Player->HasAura(eSpells::SPELL_CORRUPTION))
                            {

                                if (Aura* l_Aura = l_Player->GetAura(eSpells::SPELL_CORRUPTION))
                                {
                                    int32 bp = l_Aura->GetEffect(0)->GetBaseAmount();
                                    int32 l_ArtificalPower = bp;

                                    printf("1bp = %u", l_ArtificalPower);

                                    if (l_ArtificalPower > 100)
                                        l_ArtificalPower = 100;

                                    while (l_ArtificalPower > 40)
                                    {
                                        m_SerenityPhaseDeath++;
                                        l_ArtificalPower -= 40;

                                        printf("2bp = %u", l_ArtificalPower);

                                        Position l_Pos = *me;
                                        me->SummonCreature(eCreatures::CREATURE_MANIFESTATION_OF_CORRUPTION, g_AmagalamOfCorruptionSpawn, TEMPSUMMON_TIMED_DESPAWN, 58 * TimeConstants::IN_MILLISECONDS);
                                    }

                                    printf("3bp = %u", l_ArtificalPower);

                                    while (l_ArtificalPower > 15)
                                    {
                                        m_SerenityPhaseDeath++;
                                        l_ArtificalPower -= 15;

                                        printf("4bp = %u", l_ArtificalPower);

                                        Position l_Pos = *me;
                                        me->SummonCreature(eCreatures::CREATURE_ESSENCE_OF_CORRUPTION, g_AmagalamOfCorruptionSpawn, TEMPSUMMON_TIMED_DESPAWN, 58 * TimeConstants::IN_MILLISECONDS);
                                    }

                                    printf("5bp = %u", l_ArtificalPower);
                                    }

                                // Stupid loop, i know, not my fault.. while doesn't really work.
                                if (Aura* l_Aura = l_Player->GetAura(eSpells::SPELL_CORRUPTION))
                                {
                                    int32 bp = l_Aura->GetEffect(0)->GetBaseAmount();
                                    int32 l_ArtificalPower = bp;

                                    for (uint8 i = 0; i <= 3; i++)
                                    {
                                        if (l_ArtificalPower > 40)
                                        {
                                            l_ArtificalPower -= 40;
                                            m_SerenityPhaseDeath++;
                                            Position l_Pos = *me;

                                            if (Creature* l_Manifestation = me->SummonCreature(eCreatures::CREATURE_MANIFESTATION_OF_CORRUPTION, g_AmagalamOfCorruptionSpawn, TEMPSUMMON_TIMED_DESPAWN, 58 * TimeConstants::IN_MILLISECONDS))
                                            {
                                                l_Manifestation->SetPhaseMask(l_Player->GetPhaseMask(), true);

                                                if (l_Manifestation->IsAIEnabled)
                                                    l_Manifestation->AI()->SetGUID(me->GetGUID());
                                            }
                                        }
                                        else if (l_ArtificalPower > 14)
                                        {
                                            l_ArtificalPower -= 15;
                                            m_SerenityPhaseDeath++;
                                            Position l_Pos = *me;

                                            if (Creature* Essence = me->SummonCreature(eCreatures::CREATURE_ESSENCE_OF_CORRUPTION, g_AmagalamOfCorruptionSpawn, TEMPSUMMON_TIMED_DESPAWN, 58 * TimeConstants::IN_MILLISECONDS))
                                            {
                                                Essence->SetPhaseMask(l_Player->GetPhaseMask(), true);

                                                if (Essence->IsAIEnabled)
                                                    Essence->AI()->SetGUID(me->GetGUID());
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }

                    DoAction(eActions::ACTION_LOOK_WITHIN_DEACTIVATE);
                    break;
                }
            }
        }

        void UpdateAI(const uint32 p_Diff) override
        {
            if (m_Instance == nullptr)
                return;

            /// Unleahsed Corruption - Hardcoded, summons the same npc on the normal realm whenever it's being killed in the test of serenity (dps only)
            if (Creature * l_Almegalem = m_Instance->instance->GetCreature(m_Instance->GetObjectGuid(eData::DATA_NORUSHEN_ALMAGLEM_OF_CORRUPTION)))
            {
                if (!l_Almegalem->IsInCombat())
                    return;

                events.Update(p_Diff);

                switch (events.ExecuteEvent())
                {
                    case eEvents::EVENT_REACTIVATE_LOOK_WITHIN_TRIGGERS:
                        m_PlayerGUID = 0;
                        m_OriginalPhasemask = 1;
                        m_SerenityPhaseDeath = 0;

                        me->RemoveFlag(UNIT_FIELD_FLAGS, UnitFlags::UNIT_FLAG_IMMUNE_TO_PC | UnitFlags::UNIT_FLAG_IMMUNE_TO_NPC | UnitFlags::UNIT_FLAG_NOT_SELECTABLE);
                        me->AddAura(eSpells::SPELL_LOOK_WITHIN_VISUAL_BALL, me);
                        break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new creature_look_within_triggerAI(creature);
    }
};

/// Test of Confidence - 72051 (Tank)
class creature_titanic_corruption : public CreatureScript
{
public:

    creature_titanic_corruption() : CreatureScript("creature_titanic_corruption") { }

    struct creature_look_within_triggerAI : public BossAI
    {
        creature_look_within_triggerAI(Creature* p_Creature) : ScriptedAI(p_Creature), m_Guid(0)
        {
            m_Instance = p_Creature->GetInstanceScript();
        }

        InstanceScript* m_Instance;
        uint32 m_SucceedDiff;
        uint64 m_Guid;
        bool m_Succeed;

        void Reset() override
        {
            events.Reset();
            me->setFaction(FactionHostile);
            me->SetInCombatWithZone();
            me->AddUnitMovementFlag(MovementFlags::MOVEMENTFLAG_ROOT);
            me->SetFlag(UNIT_FIELD_FLAGS, UnitFlags::UNIT_FLAG_DISABLE_MOVE);

            m_Succeed = false;
            m_SucceedDiff = 59 * TimeConstants::IN_MILLISECONDS;
        }

        void SetGUID(uint64 guid, int32 /*param*/) override
        {
            m_Guid = guid;
        }

        void EnterCombat(Unit* p_Attacker) override
        {
            events.ScheduleEvent(eEvents::EVENT_CORRUPTION, 2 * TimeConstants::IN_MILLISECONDS);
            events.ScheduleEvent(eEvents::EVENT_TITANIC_SMASH, urand(8 * TimeConstants::IN_MILLISECONDS, 12 * TimeConstants::IN_MILLISECONDS));
            events.ScheduleEvent(eEvents::EVENT_HURL_CORRUPTION, 20 * TimeConstants::IN_MILLISECONDS);
            events.ScheduleEvent(eEvents::EVENT_BURST_OF_CORRUPTION, 30 * TimeConstants::IN_MILLISECONDS);
            events.ScheduleEvent(eEvents::EVENT_PIERCING_CORRUPTION, 17 * TimeConstants::IN_MILLISECONDS);
        }

        void JustDied(Unit* p_Killer) override
        {
            if (!m_Succeed)
            {
                if (m_Instance != nullptr)
                {
                    if (TempSummon* l_Tempo = me->ToTempSummon())
                    {
                        if (Unit* l_Summoner = l_Tempo->GetSummoner())
                        {
                            if (Player* l_SummonerPlayer = ObjectAccessor::GetPlayer(*me, l_Summoner->GetGUID()))
                            {
                                if (l_SummonerPlayer->HasAura(eSpells::SPELL_TITANIC_CORRUPTION))
                                {
                                    if (Aura* l_Aura = l_SummonerPlayer->GetAura(eSpells::SPELL_TITANIC_CORRUPTION))
                                    {
                                        l_SummonerPlayer->SetPower(Powers(POWER_ALTERNATE_POWER), 0);
                                    }

                                        l_SummonerPlayer->RemoveAura(eSpells::SPELL_LOOK_WITHIN_PHASETANK);
                                        l_SummonerPlayer->RemoveAura(eSpells::SPELL_TEST_OF_CONFIDENCE);
                                        l_SummonerPlayer->SetPhaseMask(1, true);
                                        l_SummonerPlayer->m_Events.KillAllEvents(true); /// stops set original phase from overlapping on other phases
                                        l_SummonerPlayer->AddAura(eSpells::SPELL_PURIFIED, l_SummonerPlayer);

                                        m_Succeed = true;

                                        if (Creature* l_LookWithin = ObjectAccessor::GetCreature(*me, GetGUID(m_Guid)))
                                        {
                                            if (l_LookWithin->IsAIEnabled)
                                                l_LookWithin->GetAI()->DoAction(eActions::ACTION_LOOK_WITHIN_ACTIVATE);
                                        }
                                }
                            }
                        }
                    }
                }
            }

            me->DespawnOrUnsummon(1000);
        }

        void DamageTaken(Unit* p_Attacker, uint32& p_Damage) override
        {
            if (p_Damage && p_Damage > 0)
            {
                if (m_Instance != nullptr)
                {
                    if (Creature * l_Almegalem = m_Instance->instance->GetCreature(m_Instance->GetObjectGuid(eData::DATA_NORUSHEN_ALMAGLEM_OF_CORRUPTION)))
                        p_Attacker->DealDamage(l_Almegalem, p_Damage);
                }
            }
        }

        void UpdateAI(const uint32 p_Diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(p_Diff);

            // Test of Confidence wining conditions is to survive.
            if (!m_Succeed)
            {
                if (m_SucceedDiff <= p_Diff)
                {
                    if (m_Instance != nullptr)
                    {
                        /// Test succeed only if tank survives
                        if (TempSummon* l_Tempo = me->ToTempSummon())
                        {
                            if (Unit* l_Summoner = l_Tempo->GetSummoner())
                            {
                                if (Player* l_SummonerPlayer = ObjectAccessor::GetPlayer(*me, l_Summoner->GetGUID()))
                                {
                                    l_SummonerPlayer->SetPower(Powers(POWER_ALTERNATE_POWER), 0);

                                    l_SummonerPlayer->RemoveAura(eSpells::SPELL_TEST_OF_CONFIDENCE);
                                    l_SummonerPlayer->RemoveAura(eSpells::SPELL_LOOK_WITHIN_PHASETANK);
                                    l_SummonerPlayer->m_Events.KillAllEvents(true); /// stops set original phase from overlapping on other phases
                                    l_SummonerPlayer->SetPhaseMask(1, true);

                                    m_Succeed = true;

                                    if (Creature* l_LookWithin = ObjectAccessor::GetCreature(*me, GetGUID(m_Guid)))
                                    {
                                        if (l_LookWithin->IsAIEnabled)
                                            l_LookWithin->GetAI()->DoAction(eActions::ACTION_LOOK_WITHIN_ACTIVATE);
                                    }
                               }
                            }
                        }
                    }

                    me->DespawnOrUnsummon(1000);
                }
                else
                    m_SucceedDiff -= p_Diff;
            }

            if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                return;

            if (Unit* l_Target = me->GetVictim())
            {
                switch (events.ExecuteEvent())
                {
                    case eEvents::EVENT_TITANIC_SMASH:
                        me->CastSpell(l_Target, eSpells::SPELL_TITANIC_SMASH);
                        events.ScheduleEvent(EVENT_TITANIC_SMASH, urand(8 * TimeConstants::IN_MILLISECONDS, 12 * TimeConstants::IN_MILLISECONDS));
                        break;
                    case eEvents::EVENT_HURL_CORRUPTION:
                        me->CastSpell(l_Target, eSpells::SPELL_HURL_CORRUPTION);
                        events.ScheduleEvent(EVENT_HURL_CORRUPTION, 45 * TimeConstants::IN_MILLISECONDS);
                        break;
                    case eEvents::EVENT_BURST_OF_CORRUPTION:
                        me->CastSpell(me, eSpells::SPELL_BURST_OF_CORRUPTION);
                        events.ScheduleEvent(EVENT_BURST_OF_CORRUPTION, 20 * TimeConstants::IN_MILLISECONDS);
                        break;
                    case eEvents::EVENT_PIERCING_CORRUPTION:
                        me->CastSpell(l_Target, eSpells::SPELL_PIERCING_CORRUPTION);
                        events.ScheduleEvent(EVENT_PIERCING_CORRUPTION, 28 * TimeConstants::IN_MILLISECONDS);
                        break;
                    case eEvents::EVENT_CORRUPTION:
                        me->CastSpell(l_Target, eSpells::SPELL_TITANIC_CORRUPTION);
                        events.ScheduleEvent(EVENT_CORRUPTION, 28 * TimeConstants::IN_MILLISECONDS);
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* p_Creature) const override
    {
        return new creature_look_within_triggerAI(p_Creature);
    }
};

/// Test of Reliance - 72001 (Healer)
class creature_greater_corruption : public CreatureScript
{
public:

    creature_greater_corruption() : CreatureScript("creature_greater_corruption") { }

    struct creature_look_within_triggerAI : public BossAI
    {
        creature_look_within_triggerAI(Creature* p_Creature) : ScriptedAI(p_Creature), m_Guid(0)
        {
            m_Instance = p_Creature->GetInstanceScript();
        }

        InstanceScript* m_Instance;
        uint32 m_SucceedDiff;
        uint64 m_Guid;
        bool m_Succeed;

        void Reset() override
        {
            events.Reset();
            me->setFaction(FactionHostile);
            me->SetInCombatWithZone();
            me->AddUnitMovementFlag(MovementFlags::MOVEMENTFLAG_ROOT);
            me->SetFlag(UNIT_FIELD_FLAGS, UnitFlags::UNIT_FLAG_DISABLE_MOVE);
            m_SucceedDiff = 59 * TimeConstants::IN_MILLISECONDS;
            m_Succeed = false;
        }

        void SetGUID(uint64 guid, int32 /*param*/) override
        {
            m_Guid = guid;
        }

        void EnterCombat(Unit* p_Attacker) override
        {
            events.ScheduleEvent(eEvents::EVENT_DISHEARTNING_LAUGH, 8 * TimeConstants::IN_MILLISECONDS);
            events.ScheduleEvent(eEvents::EVENT_LINGERING_CORRUPTION, 20 * TimeConstants::IN_MILLISECONDS);
            events.ScheduleEvent(eEvents::EVENT_BOTTOMLESS_PIT, 30 * TimeConstants::IN_MILLISECONDS);
        }

        void JustDied(Unit* p_Killer) override
        {
            if (!m_Succeed)
            {
                if (m_Instance != nullptr)
                {
                    if (TempSummon* l_Tempo = me->ToTempSummon())
                    {
                        if (Unit* l_Summoner = l_Tempo->GetSummoner())
                        {
                            if (Player* l_SummonerPlayer = ObjectAccessor::GetPlayer(*me, l_Summoner->GetGUID()))
                            {
                                l_SummonerPlayer->SetPower(Powers(POWER_ALTERNATE_POWER), 0);

                                l_SummonerPlayer->RemoveAura(eSpells::SPELL_LOOK_WITHIN_PHASEHEAL);
                                l_SummonerPlayer->RemoveAura(eSpells::SPELL_TEST_OF_RELIANCE);
                                l_SummonerPlayer->SetPhaseMask(1, true);
                                l_SummonerPlayer->m_Events.KillAllEvents(true); /// stops set original phase from overlapping on other phases
                                l_SummonerPlayer->AddAura(eSpells::SPELL_PURIFIED, l_SummonerPlayer);

                                m_Succeed = true;


                                if (Creature* l_LookWithin = ObjectAccessor::GetCreature(*me, GetGUID(m_Guid)))
                                {
                                    if (l_LookWithin->IsAIEnabled)
                                        l_LookWithin->GetAI()->DoAction(eActions::ACTION_LOOK_WITHIN_ACTIVATE);
                                }
                            }
                        }
                    }
                }
            }

            me->DespawnOrUnsummon(500);
        }

        void DamageTaken(Unit* p_Attacker, uint32& p_Damage) override
        {
            if (p_Damage && p_Damage > 0)
            {
                if (m_Instance != nullptr)
                {
                    if (Creature * l_Almegalem = m_Instance->instance->GetCreature(m_Instance->GetObjectGuid(eData::DATA_NORUSHEN_ALMAGLEM_OF_CORRUPTION)))
                        p_Attacker->DealDamage(l_Almegalem, p_Damage);
                }
            }
        }

        void UpdateAI(const uint32 p_Diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(p_Diff);

            // Test of Reliance wining conditions is to survive.
            if (!m_Succeed)
            {
                if (m_SucceedDiff <= p_Diff)
                {
                    if (m_Instance != nullptr)
                    {
                        /// Test succeed only if tank survives
                        if (TempSummon* l_Tempo = me->ToTempSummon())
                        {
                            if (Unit* l_Summoner = l_Tempo->GetSummoner())
                            {
                                if (Player* l_SummonerPlayer = ObjectAccessor::GetPlayer(*me, l_Summoner->GetGUID()))
                                {
                                    l_SummonerPlayer->SetPower(Powers(POWER_ALTERNATE_POWER), 0);

                                    l_SummonerPlayer->RemoveAura(eSpells::SPELL_TEST_OF_RELIANCE);
                                    l_SummonerPlayer->RemoveAura(eSpells::SPELL_LOOK_WITHIN_PHASEHEAL);
                                    l_SummonerPlayer->SetPhaseMask(1, true);
                                    l_SummonerPlayer->m_Events.KillAllEvents(true); /// stops set original phase from overlapping on other phases

                                    m_Succeed = true;

                                    uint32 l_Entries[3] = { CREATURE_SUN_TENDER_HEART, CREATURE_ROOK_STONE_TOE, CREATURE_LEVEN_DAWN };

                                    for (uint32 l_I = 0; l_I <= 3; l_I++)
                                    {
                                        DespawnCreaturesInArea(me, l_Entries[l_I], false);
                                    }

                                    me->DespawnOrUnsummon(500);

                                    if (Creature* l_LookWithin = ObjectAccessor::GetCreature(*me, GetGUID(m_Guid)))
                                    {
                                        if (l_LookWithin->IsAIEnabled)
                                            l_LookWithin->GetAI()->DoAction(eActions::ACTION_LOOK_WITHIN_ACTIVATE);
                                    }
                                }
                            }
                        }
                    }
                }
                else
                    m_SucceedDiff -= p_Diff;
            }

            if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                return;

            if (Unit* l_Target = me->GetVictim())
            {
                switch (events.ExecuteEvent())
                {
                    case eEvents::EVENT_DISHEARTNING_LAUGH:
                        DoCast(eSpells::SPELL_DISHEARTENING_LAUGH);
                        events.ScheduleEvent(eEvents::EVENT_DISHEARTNING_LAUGH, 20 * TimeConstants::IN_MILLISECONDS);
                        break;
                    case eEvents::EVENT_LINGERING_CORRUPTION:
                        if (Unit* l_RandomTarget = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 100.0f, true))
                            me->CastSpell(l_RandomTarget, eSpells::SPELL_LINGERING_CORRUPTION);

                        events.ScheduleEvent(eEvents::EVENT_LINGERING_CORRUPTION, 15 * TimeConstants::IN_MILLISECONDS);
                        break;
                    case eEvents::EVENT_BOTTOMLESS_PIT:
                        events.ScheduleEvent(eEvents::EVENT_BOTTOMLESS_PIT, 50 * TimeConstants::IN_MILLISECONDS);
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new creature_look_within_triggerAI(creature);
    }
};

/// Manifestation of Corruption - 72264 [Look Within]
class creature_norushen_manifestation_of_corruption : public CreatureScript
{
public:

    creature_norushen_manifestation_of_corruption() : CreatureScript("creature_norushen_manifestation_of_corruption") { }

    struct creature_norushen_manifestation_of_corruptionAI : public BossAI
    {
        creature_norushen_manifestation_of_corruptionAI(Creature* p_Creature) : ScriptedAI(p_Creature), m_Guid(0)
        {
            m_Instance = p_Creature->GetInstanceScript();
        }

        InstanceScript* m_Instance;
        uint64 m_Guid;

        void Reset() override
        {
            events.Reset();
            me->setFaction(FactionHostile);
        }

        void SetGUID(uint64 guid, int32 /*param*/) override
        {
            m_Guid = guid;
        }

        void JustDied(Unit* p_Killer) override
        {
            if (m_Instance != nullptr)
            {
                if (Creature* l_Manifestation = p_Killer->SummonCreature(eCreatures::CREATURE_UNLEASHED_MANIFESTATION_OF_CORRUPTION, *p_Killer, TEMPSUMMON_MANUAL_DESPAWN))
                    l_Manifestation->SetPhaseMask(1, true);

                if (Creature* l_LookWithinTrigger = ObjectAccessor::GetCreature(*me, GetGUID(m_Guid)))
                {
                    if (l_LookWithinTrigger->IsAIEnabled)
                        l_LookWithinTrigger->GetAI()->DoAction(eActions::ACTION_COUNT_SERENITY_PHASE_KILLS);
                }

                /// If time passes, summons a manifestation of corruption
                if (TempSummon* l_Tempo = me->ToTempSummon())
                {
                    if (Unit* l_Summoner = l_Tempo->GetSummoner())
                    {
                        if (Player* l_SummonerPlayer = ObjectAccessor::GetPlayer(*me, l_Summoner->GetGUID()))
                        {
                            if (Aura* l_Aura = l_SummonerPlayer->GetAura(eSpells::SPELL_CORRUPTION))
                            {
                                int32 bp = l_Aura->GetEffect(0)->GetBaseAmount();
                                uint32 m_calc = bp - 40;

                                l_SummonerPlayer->SetPower(Powers(POWER_ALTERNATE_POWER), m_calc);

                                if (bp < 0)
                                    l_SummonerPlayer->SetPower(Powers(POWER_ALTERNATE_POWER), 0);
                            }
                        }
                    }
                }
            }

            me->DespawnOrUnsummon(500);
        }

        void EnterCombat(Unit* p_Attacker) override
        {
            events.ScheduleEvent(eEvents::EVENT_TEAR_REALITY, urand(8 * TimeConstants::IN_MILLISECONDS, 15 * TimeConstants::IN_MILLISECONDS));
        }

        void DamageTaken(Unit* p_Attacker, uint32& p_Damage) override
        {
            if (p_Attacker)
            {
                if (p_Damage && p_Damage > 0)
                {
                    if (m_Instance != nullptr)
                    {
                        if (Creature * l_Almegalem = m_Instance->instance->GetCreature(m_Instance->GetObjectGuid(eData::DATA_NORUSHEN_ALMAGLEM_OF_CORRUPTION)))
                            p_Attacker->DealDamage(l_Almegalem, p_Damage);
                    }
                }
            }
        }

        void UpdateAI(const uint32 p_Diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(p_Diff);

            if (Unit* l_Target = me->GetVictim())
            {
                switch (events.ExecuteEvent())
                {
                    case eEvents::EVENT_TEAR_REALITY:
                            me->CastSpell(l_Target, eSpells::SPELL_TEAR_REALITY);
                            events.ScheduleEvent(eEvents::EVENT_TEAR_REALITY, urand(8 * TimeConstants::IN_MILLISECONDS, 12 * TimeConstants::IN_MILLISECONDS));
                            break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new creature_norushen_manifestation_of_corruptionAI(creature);
    }
};

/// Essence of Corruption - 71976 [Look Within]
class creature_norushen_essnece_of_corruption : public CreatureScript
{
public:

    creature_norushen_essnece_of_corruption() : CreatureScript("creature_norushen_essnece_of_corruption") { }

    struct creature_norushen_essnece_of_corruptionAI : public BossAI
    {
        creature_norushen_essnece_of_corruptionAI(Creature* p_Creature) : ScriptedAI(p_Creature), m_Guid(0)
        {
            m_Instance = p_Creature->GetInstanceScript();
        }

        InstanceScript* m_Instance;
        uint64 m_Guid;

        void Reset() override
        {
            events.Reset();

            me->setFaction(FactionHostile);
            me->CastSpell(me, eSpells::SPELL_SERENITY_PHASE_MOBS_COSMETIC);
        }

        void SetGUID(uint64 guid, int32 /*param*/) override
        {
            m_Guid = guid;
        }

        void EnterCombat(Unit* p_Attacker) override
        {
            events.ScheduleEvent(eEvents::EVENT_EXPEL_CORRUPTION, urand(6 * TimeConstants::IN_MILLISECONDS, 8 * TimeConstants::IN_MILLISECONDS));
        }

        void DamageTaken(Unit* p_Attacker, uint32& p_Damage) override
        {
            if (p_Attacker)
            {
                if (p_Damage && p_Damage > 0)
                {
                    if (m_Instance != nullptr)
                    {
                        if (Creature * l_Almegalem = m_Instance->instance->GetCreature(m_Instance->GetObjectGuid(eData::DATA_NORUSHEN_ALMAGLEM_OF_CORRUPTION)))
                            p_Attacker->DealDamage(l_Almegalem, p_Damage);
                    }
                }
            }
        }

        void JustDied(Unit* p_Killer) override
        {
            if (m_Instance != nullptr)
            {
                if (TempSummon* l_Tempo = me->ToTempSummon())
                {
                    if (Unit* l_Summoner = l_Tempo->GetSummoner())
                    {
                        if (Player* l_SummonerPlayer = ObjectAccessor::GetPlayer(*me, l_Summoner->GetGUID()))
                        {
                            if (Aura* l_Aura = l_SummonerPlayer->GetAura(eSpells::SPELL_CORRUPTION))
                            {
                                int32 bp = l_Aura->GetEffect(0)->GetBaseAmount();
                                uint32 m_calc = bp - 15;

                                l_SummonerPlayer->SetPower(Powers(POWER_ALTERNATE_POWER), m_calc);

                                if (bp < 0)
                                    l_SummonerPlayer->SetPower(Powers(POWER_ALTERNATE_POWER), 0);

                                if (Creature* l_LookWithinTrigger = ObjectAccessor::GetCreature(*me, GetGUID(m_Guid)))
                                {
                                    if (l_LookWithinTrigger->IsAIEnabled)
                                        l_LookWithinTrigger->GetAI()->DoAction(eActions::ACTION_COUNT_SERENITY_PHASE_KILLS);
                                }
                            }
                        }
                    }
                }

                if (Creature* l_Essence = p_Killer->SummonCreature(eCreatures::CREATURE_UNLEASHED_ESSENCE_OF_CORRUPTION, *p_Killer, TEMPSUMMON_MANUAL_DESPAWN))
                    l_Essence->SetPhaseMask(1, true);
            }
                me->DespawnOrUnsummon(500);
        }

        void UpdateAI(const uint32 p_Diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(p_Diff);

            if (Unit* l_Target = me->GetVictim())
            {
                switch (events.ExecuteEvent())
                {
                    case eEvents::EVENT_EXPEL_CORRUPTION:
                        me->CastSpell(l_Target, eSpells::SPELL_EXPELLED_CORRUPTION);
                        events.ScheduleEvent(eEvents::EVENT_EXPEL_CORRUPTION, urand(6 * TimeConstants::IN_MILLISECONDS, 8 * TimeConstants::IN_MILLISECONDS));
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* p_Creature) const override
    {
        return new creature_norushen_essnece_of_corruptionAI(p_Creature);
    }
};

/// Manifestation of Corruption - 71977 [Normal]
class creature_norushen_manifestation_of_corruption_non_test : public CreatureScript
{
public:

    creature_norushen_manifestation_of_corruption_non_test() : CreatureScript("creature_norushen_manifestation_of_corruption_non_test") { }

    struct creature_norushen_manifestation_of_corruptionAI : public BossAI
    {
        creature_norushen_manifestation_of_corruptionAI(Creature* p_Creature) : ScriptedAI(p_Creature)
        {
            m_Instance = p_Creature->GetInstanceScript();
        }

        InstanceScript* m_Instance;
        uint32 m_DiffVisual;
        uint32 m_OriginalDisplayId;
        bool m_VisualHappen;

        void Reset() override
        {
            events.Reset();
            DoZoneInCombat();
            me->setFaction(FactionHostile);


            m_OriginalDisplayId = me->GetDisplayId();
            me->SetReactState(ReactStates::REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UnitFlags::UNIT_FLAG_DISABLE_MOVE | UnitFlags::UNIT_FLAG_IMMUNE_TO_PC | UnitFlags::UNIT_FLAG_IMMUNE_TO_NPC | UnitFlags::UNIT_FLAG_NON_ATTACKABLE);
            me->CastSpell(me, eSpells::SPELL_SERENITY_PHASE_MOBS_COSMETIC, true);
            m_VisualHappen = false;
            me->SetDisplayId(11686);
            if (m_Instance != nullptr)
            {
                if (Creature * l_Trigger = m_Instance->instance->GetCreature(m_Instance->GetObjectGuid(eData::DATA_NORUSHEN_ALMAGLEM_OF_CORRUPTION)))
                {
                    l_Trigger->CastSpell(me, eSpells::SPELL_NORUSHEN_COLOR, true);

                    m_VisualHappen = true;
                    m_DiffVisual = 6 * TimeConstants::IN_MILLISECONDS;
                }
            }

        }

        void EnterCombat(Unit* p_Attacker) override
        {
            events.ScheduleEvent(eEvents::EVENT_BURST_ANGER, 2 * TimeConstants::IN_MILLISECONDS);
        }

        void JustDied(Unit* p_Killer) override
        {
            if (Creature* l_Residual = p_Killer->SummonCreature(eCreatures::CREATURE_RESIDUAL_CORRUPTION, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TempSummonType::TEMPSUMMON_MANUAL_DESPAWN))
                l_Residual->SetPhaseMask(1, true);
        }

        void UpdateAI(const uint32 p_Diff) override
        {

            if (m_VisualHappen)
            {
                if (m_DiffVisual <= p_Diff)
                {
                    m_VisualHappen = true;

                    me->SetDisplayId(m_OriginalDisplayId);
                    me->SetReactState(ReactStates::REACT_AGGRESSIVE);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UnitFlags::UNIT_FLAG_IMMUNE_TO_PC | UnitFlags::UNIT_FLAG_IMMUNE_TO_NPC | UnitFlags::UNIT_FLAG_NON_ATTACKABLE);
                }
                else
                    m_DiffVisual -= p_Diff;
            }


            if (!UpdateVictim())
                return;

            events.Update(p_Diff);

            if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                return;

            if (Unit* l_Target = me->GetVictim())
            {
                switch (events.ExecuteEvent())
                {
                    case eEvents::EVENT_BURST_ANGER:
                        me->CastSpell(l_Target, eSpells::SPELL_BURST_OF_ANGER, false);
                        events.ScheduleEvent(eEvents::EVENT_BURST_ANGER, 2 * TimeConstants::IN_MILLISECONDS);
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new creature_norushen_manifestation_of_corruptionAI(creature);
    }
};

/// Essence of Corruption - 71976 [Normal]
class creature_norushen_essnece_of_corruption_non_test : public CreatureScript
{
public:

    creature_norushen_essnece_of_corruption_non_test() : CreatureScript("creature_norushen_essnece_of_corruption_non_test") { }

    struct creature_norushen_essnece_of_corruptionAI : public BossAI
    {
        creature_norushen_essnece_of_corruptionAI(Creature* p_Creature) : ScriptedAI(p_Creature)
        {
            m_Instance = p_Creature->GetInstanceScript();
        }

        InstanceScript* m_Instance;

        void Reset() override
        {
            events.Reset();
            me->setFaction(FactionHostile);
            me->SetInCombatWithZone();
            me->CastSpell(me, eSpells::SPELL_SERENITY_PHASE_MOBS_COSMETIC);
        }

        void EnterCombat(Unit* p_Attacker) override
        {
            if (m_Instance != nullptr)
            {
                if (Creature * l_Almegalem = m_Instance->instance->GetCreature(m_Instance->GetObjectGuid(eData::DATA_NORUSHEN_ALMAGLEM_OF_CORRUPTION)))
                {
                    me->CastSpell(l_Almegalem, eSpells::SPELL_FOUL_LINK_AURA);
                }
            }

            events.ScheduleEvent(eEvents::EVENT_EXPEL_CORRUPTION, urand(6 * TimeConstants::IN_MILLISECONDS, 8 * TimeConstants::IN_MILLISECONDS));
        }

        void UpdateAI(const uint32 p_Diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(p_Diff);

            if (Unit* l_Target = me->GetVictim())
            {
                switch (events.ExecuteEvent())
                {
                    case eEvents::EVENT_EXPEL_CORRUPTION:
                        me->CastSpell(l_Target, 145134); // Expelled Corruption
                        events.ScheduleEvent(eEvents::EVENT_EXPEL_CORRUPTION, urand(6 * TimeConstants::IN_MILLISECONDS, 8 * TimeConstants::IN_MILLISECONDS));
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new creature_norushen_essnece_of_corruptionAI(creature);
    }
};

/// Leven Dawnblade - 71995
class creature_norushen_leven : public CreatureScript
{
public:

    creature_norushen_leven() : CreatureScript("creature_norushen_leven") { }

    struct creature_norushen_levenAI : public BossAI
    {
        creature_norushen_levenAI(Creature* p_Creature) : ScriptedAI(p_Creature)
        {
            m_Instance = p_Creature->GetInstanceScript();
        }

        InstanceScript* m_Instance;
        uint64 m_BottomLessPitGUID;
        bool m_Moved;
        bool m_Exhausted;

        void Reset() override
        {
            events.Reset();
            m_Moved = false;
            m_Exhausted = true;
            m_BottomLessPitGUID = 0;

            if (Creature* l_GreaterCorruption = me->FindNearestCreature(eCreatures::CREATURE_GREATER_CORRUPTION, 100.0f, true))
            {
                if (me->IsAIEnabled)
                    me->AI()->AttackStart(l_GreaterCorruption);

                ///< Initial threat upon reset
                me->AddThreat(l_GreaterCorruption, 2000.0f);
            }

            // Sets to player's faction
            if (TempSummon* l_Tempo = me->ToTempSummon())
            {
                if (Unit* l_Summoner = l_Tempo->GetSummoner())
                {
                    if (Player* l_SummonerPlayer = ObjectAccessor::GetPlayer(*me, l_Summoner->GetGUID()))
                    {
                        me->setFaction(l_SummonerPlayer->getFaction());
                    }
                }
            }

            me->ClearUnitState(UnitState::UNIT_STATE_CANNOT_AUTOATTACK);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UnitFlags::UNIT_FLAG_IMMUNE_TO_NPC | UnitFlags::UNIT_FLAG_IMMUNE_TO_PC);
            me->RemoveFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_REGENERATE_POWER);
            me->AddAura(eSpells::SPELL_DAMAGE_DEALER, me);
            me->SetReactState(ReactStates::REACT_AGGRESSIVE);
            ///< Pandas starts with 0.25% of their health
            me->SetMaxHealth(me->GetMaxHealth() * 0.35f);
            me->SetHealth(me->GetHealth() * 0.35f);
        }

        void EnterCombat(Unit* p_Attacker) override
        {
            events.ScheduleEvent(eEvents::EVENT_THREATENING_STRIKES, 2 * TimeConstants::IN_MILLISECONDS);
        }

        void MovementInform(uint32 p_Type, uint32 p_Id)
        {
            if (p_Id == eMovementInformed::MOVEMENT_INFORM_LEAVING_BOTTOMLESS_PIT)
            {
                if (m_BottomLessPitGUID != 0)
                {
                    if (Creature* l_NearestBottomLessPit = ObjectAccessor::GetCreature(*me, GetGUID(m_BottomLessPitGUID)))
                    {
                        if (me->IsWithinDistInMap(l_NearestBottomLessPit, 1.2f))
                        {
                            m_Moved = true;
                        }
                        else
                        {
                            m_Moved = true;
                            m_BottomLessPitGUID = true;
                        }
                    }
                }
            }
        }

        void DamageTaken(Unit* p_Attacker, uint32& p_Damage) override
        {
            if (m_Exhausted)
            {
                if (me->GetHealthPct() <= 10)
                {
                    m_Exhausted = false;

                    me->AddAura(eSpells::SPELL_EXHAUSTED, me);
                    me->getHostileRefManager().clearReferences();
                    me->SetReactState(ReactStates::REACT_PASSIVE);
                    me->SetFlag(UNIT_FIELD_FLAGS, UnitFlags::UNIT_FLAG_DISABLE_MOVE | UnitFlags::UNIT_FLAG_IMMUNE_TO_PC | UnitFlags::UNIT_FLAG_IMMUNE_TO_NPC | UnitFlags::UNIT_FLAG_NON_ATTACKABLE);
                }
            }
        }

        void UpdateAI(const uint32 p_Diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(p_Diff);

            if (!m_Moved)
            {
                if (Creature* l_NearestBottomLessPit = me->FindNearestCreature(eCreatures::CREATURE_BOTTOMLESS_PIT, 1.5f, true))
                {
                    m_Moved = true;

                    Position l_Position;
                    l_NearestBottomLessPit->GetPosition();
                    me->GetRandomNearPosition(2.0f);

                    m_BottomLessPitGUID = l_NearestBottomLessPit->GetGUID();

                    me->GetMotionMaster()->MovePoint(eMovementInformed::MOVEMENT_INFORM_LEAVING_BOTTOMLESS_PIT, l_Position);
                }
            }

            if (Creature* l_GreaterCorruption = me->FindNearestCreature(eCreatures::CREATURE_GREATER_CORRUPTION, 100.0f, true))
            {
                ///< Applies threats
                me->AddThreat(l_GreaterCorruption, 2000.0f);
            }

            switch (events.ExecuteEvent())
            {
                case eEvents::EVENT_THREATENING_STRIKES:
                {
                    if (Creature* l_GreaterCorruption = me->FindNearestCreature(eCreatures::CREATURE_GREATER_CORRUPTION, 100.0f, true))
                    {
                        me->CastSpell(l_GreaterCorruption, eSpells::SPELL_THREATENING_STRIKES);
                        events.ScheduleEvent(eEvents::EVENT_THREATENING_STRIKES, 2 * TimeConstants::IN_MILLISECONDS);
                        break;
                    }
                }
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new creature_norushen_levenAI(creature);
    }
};

/// Rook Stonetoe - 71995
class creature_norushen_rook : public CreatureScript
{
public:

    creature_norushen_rook() : CreatureScript("creature_norushen_rook") { }

    struct creature_norushen_rookAI : public BossAI
    {
        creature_norushen_rookAI(Creature* p_Creature) : ScriptedAI(p_Creature)
        {
            m_Instance = p_Creature->GetInstanceScript();
        }

        InstanceScript* m_Instance;
        uint64 m_BottomLessPitGUID;
        bool m_Moved;
        bool m_Exhausted;

        void Reset() override
        {
            events.Reset();
            m_Moved = false;
            m_Exhausted = true;
            m_BottomLessPitGUID = 0;

            if (Creature* l_GreaterCorruption = me->FindNearestCreature(eCreatures::CREATURE_GREATER_CORRUPTION, 100.0f, true))
            {
                if (me->IsAIEnabled)
                    me->AI()->AttackStart(l_GreaterCorruption);
            }

            // Sets to player's faction
            if (TempSummon* l_Tempo = me->ToTempSummon())
            {
                if (Unit* l_Summoner = l_Tempo->GetSummoner())
                {
                    if (Player* l_SummonerPlayer = ObjectAccessor::GetPlayer(*me, l_Summoner->GetGUID()))
                    {
                        me->setFaction(l_SummonerPlayer->getFaction());
                    }
                }
            }

            me->ClearUnitState(UnitState::UNIT_STATE_CANNOT_AUTOATTACK);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UnitFlags::UNIT_FLAG_IMMUNE_TO_NPC | UnitFlags::UNIT_FLAG_IMMUNE_TO_PC);
            me->RemoveFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_REGENERATE_POWER);
            me->AddAura(eSpells::SPELL_DAMAGE_DEALER, me);
            me->SetReactState(ReactStates::REACT_AGGRESSIVE);
            ///< Pandas starts with 0.25% of their health
            me->SetMaxHealth(me->GetMaxHealth() * 0.25f);
            me->SetHealth(me->GetHealth() * 0.25f);
        }

        void MovementInform(uint32 type, uint32 id)
        {
            if (id == eMovementInformed::MOVEMENT_INFORM_LEAVING_BOTTOMLESS_PIT)
            {
                if (m_BottomLessPitGUID != 0)
                {
                    if (Creature* l_NearestBottomLessPit = ObjectAccessor::GetCreature(*me, GetGUID(m_BottomLessPitGUID)))
                    {
                        if (me->IsWithinDistInMap(l_NearestBottomLessPit, 1.2f))
                        {
                            m_Moved = true;
                        }
                        else
                        {
                            m_Moved = true;
                            m_BottomLessPitGUID = true;
                        }
                    }
                }
            }
        }

        void DamageTaken(Unit* p_Attacker, uint32& p_Damage) override
        {
            if (m_Exhausted)
            {
                if (me->GetHealthPct() <= 8)
                {
                    m_Exhausted = false;

                    me->AddAura(eSpells::SPELL_EXHAUSTED, me);
                    me->getHostileRefManager().clearReferences();
                    me->SetFlag(UNIT_FIELD_FLAGS, UnitFlags::UNIT_FLAG_DISABLE_MOVE | UnitFlags::UNIT_FLAG_IMMUNE_TO_PC | UnitFlags::UNIT_FLAG_IMMUNE_TO_NPC | UnitFlags::UNIT_FLAG_NON_ATTACKABLE);
                }
            }
        }

        void UpdateAI(const uint32 p_Diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(p_Diff);

            if (!m_Moved)
            {
                if (Creature* l_NearestBottomLessPit = me->FindNearestCreature(eCreatures::CREATURE_BOTTOMLESS_PIT, 1.5f, true))
                {
                    m_Moved = true;

                    Position l_Position;
                    l_NearestBottomLessPit->GetPosition();
                    me->GetRandomNearPosition(2.0f);

                    m_BottomLessPitGUID = l_NearestBottomLessPit->GetGUID();

                    me->GetMotionMaster()->MovePoint(eMovementInformed::MOVEMENT_INFORM_LEAVING_BOTTOMLESS_PIT, l_Position);
                }
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new creature_norushen_rookAI(creature);
    }
};

/// Sun Tenderheart - 72000
class creature_norushen_sun : public CreatureScript
{
public:

    creature_norushen_sun() : CreatureScript("creature_norushen_sun") { }

    struct creature_norushen_sunAI : public BossAI
    {
        creature_norushen_sunAI(Creature* p_Creature) : ScriptedAI(p_Creature)
        {
            m_Instance = p_Creature->GetInstanceScript();
        }

        InstanceScript* m_Instance;
        uint64 m_BottomLessPitGUID;
        bool m_Exhausted;
        bool m_Moved;

        void Reset() override
        {
            events.Reset();
            m_Moved = false;
            m_Exhausted = true;
            m_BottomLessPitGUID = 0;

            if (Creature* l_GreaterCorruption = me->FindNearestCreature(eCreatures::CREATURE_GREATER_CORRUPTION, 100.0f, true))
            {
                if (me->IsAIEnabled)
                    me->AI()->AttackStart(l_GreaterCorruption);
            }

            // Sets to player's faction
            if (TempSummon* l_Tempo = me->ToTempSummon())
            {
                if (Unit* l_Summoner = l_Tempo->GetSummoner())
                {
                    if (Player* l_SummonerPlayer = ObjectAccessor::GetPlayer(*me, l_Summoner->GetGUID()))
                    {
                        me->setFaction(l_SummonerPlayer->getFaction());
                    }
                }
            }

            me->ClearUnitState(UnitState::UNIT_STATE_CANNOT_AUTOATTACK);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UnitFlags::UNIT_FLAG_IMMUNE_TO_NPC | UnitFlags::UNIT_FLAG_IMMUNE_TO_PC);
            me->RemoveFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_REGENERATE_POWER);
            me->AddAura(eSpells::SPELL_DAMAGE_DEALER, me);
            me->SetReactState(ReactStates::REACT_AGGRESSIVE);
            ///< Pandas starts with 0.25% of their health
            me->SetMaxHealth(me->GetMaxHealth() * 0.25f);
            me->SetHealth(me->GetHealth() * 0.25f);
        }

        void EnterCombat(Unit* p_Attacker) override
        {
            events.ScheduleEvent(eEvents::EVENT_FIRE_BOLT, 500);
        }

        void MovementInform(uint32 type, uint32 id)
        {
            if (id == eMovementInformed::MOVEMENT_INFORM_LEAVING_BOTTOMLESS_PIT)
            {
                if (m_BottomLessPitGUID != 0)
                {
                    if (Creature* l_NearestBottomLessPit = ObjectAccessor::GetCreature(*me, GetGUID(m_BottomLessPitGUID)))
                    {
                        if (me->IsWithinDistInMap(l_NearestBottomLessPit, 1.2f))
                        {
                            m_Moved = true;
                        }
                        else
                        {
                            m_Moved = true;
                            m_BottomLessPitGUID = true;
                        }
                    }
                }
            }
        }

        void DamageTaken(Unit* p_Attacker, uint32& p_Damage) override
        {
            if (m_Exhausted)
            {
                if (me->GetHealthPct() <= 10)
                {
                    m_Exhausted = false;

                    me->AddAura(eSpells::SPELL_EXHAUSTED, me);
                    me->getHostileRefManager().clearReferences();
                    me->SetFlag(UNIT_FIELD_FLAGS, UnitFlags::UNIT_FLAG_DISABLE_MOVE | UnitFlags::UNIT_FLAG_IMMUNE_TO_PC | UnitFlags::UNIT_FLAG_IMMUNE_TO_NPC | UnitFlags::UNIT_FLAG_NON_ATTACKABLE);
                }
            }
        }

        void UpdateAI(const uint32 p_Diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(p_Diff);

            if (!m_Moved)
            {
                if (Creature* l_NearestBottomLessPit = me->FindNearestCreature(eCreatures::CREATURE_BOTTOMLESS_PIT, 1.5f, true))
                {
                    m_Moved = true;

                    Position l_Position;
                    l_NearestBottomLessPit->GetPosition();
                    me->GetRandomNearPosition(2.0f);

                    m_BottomLessPitGUID = l_NearestBottomLessPit->GetGUID();

                    me->GetMotionMaster()->MovePoint(eMovementInformed::MOVEMENT_INFORM_LEAVING_BOTTOMLESS_PIT, l_Position);
                }
            }

            if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                return;

            switch (events.ExecuteEvent())
            {
                case eEvents::EVENT_FIRE_BOLT:
                {
                    if (Creature* l_GreaterCorruption = me->FindNearestCreature(eCreatures::CREATURE_GREATER_CORRUPTION, 100.0f, true))
                    {
                        me->CastSpell(l_GreaterCorruption, eSpells::SPELL_FIRE_BOLT);
                        events.ScheduleEvent(eEvents::EVENT_FIRE_BOLT, 2700);
                        break;
                    }
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* p_Creature) const override
    {
        return new creature_norushen_sunAI(p_Creature);
    }
};

/// Residual Corruption - 72550
class creature_residual_corruption : public CreatureScript
{
public:

    creature_residual_corruption() : CreatureScript("creature_residual_corruption") { }

    struct creature_residual_corruptionAI : public BossAI
    {
        creature_residual_corruptionAI(Creature* p_Creature) : ScriptedAI(p_Creature)
        {
            m_Instance = p_Creature->GetInstanceScript();
        }

        InstanceScript* m_Instance;
        uint32 m_IntervalDiff;
        bool m_Used;

        void Reset() override
        {
            events.Reset();

            m_Used = false;
            me->setFaction(FactionHostile);
            me->SetReactState(ReactStates::REACT_PASSIVE);
            m_IntervalDiff = 2 * TimeConstants::IN_MILLISECONDS;
            me->AddAura(eSpells::SPELL_RESIDUAL_CORRUPTION_AURA, me);
            me->SetFlag(UNIT_FIELD_FLAGS, UnitFlags::UNIT_FLAG_DISABLE_MOVE | UnitFlags::UNIT_FLAG_IMMUNE_TO_NPC | UnitFlags::UNIT_FLAG_NOT_SELECTABLE | UnitFlags::UNIT_FLAG_NON_ATTACKABLE);
        }

        void UpdateAI(const uint32 p_Diff) override
        {
            // Hack visual
            if (m_IntervalDiff <= p_Diff)
            {
                me->CastSpell(me, 144479, true); // Visual
                m_IntervalDiff = 2 * TimeConstants::IN_MILLISECONDS;
            }
            else
                m_IntervalDiff -= p_Diff;

            if (m_Instance != nullptr)
            {
                if (!m_Used)
                {
                    if (Player* l_Nearest = me->GetVictim())
                    {
                        if (Aura* l_Aura = l_Nearest->GetAura(eSpells::SPELL_CORRUPTION))
                        {
                            if (me->GetMap())
                            {
                                m_Used = true;

                                if (me->GetMap()->GetDifficultyID() == DIFFICULTY_10_N || me->GetMap()->GetDifficultyID() == DIFFICULTY_NONE)
                                {
                                    int32 bp = l_Aura->GetEffect(0)->GetBaseAmount();
                                    bp += 40;

                                    l_Nearest->SetPower(Powers(POWER_ALTERNATE_POWER), bp);
                                    l_Nearest->RemoveAura(eSpells::SPELL_PURIFIED);

                                    if (bp > 100)
                                        l_Nearest->SetPower(Powers(POWER_ALTERNATE_POWER), 100);
                                }

                                me->DespawnOrUnsummon(500);
                            }
                        }
                    }
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* p_Creature) const override
    {
        return new creature_residual_corruptionAI(p_Creature);
    }
};

/// Icy Fear - 145735
class spell_norushen_icy_fear : public SpellScriptLoader
{
public:
    spell_norushen_icy_fear() : SpellScriptLoader("spell_norushen_icy_fear") { }

    class spell_norushen_icy_fear_AuraScript : public SpellScript
    {
        PrepareSpellScript(spell_norushen_icy_fear_AuraScript);

        void HandleOnHit()
        {
            if (!GetHitUnit())
                return;

            if (GetHitUnit()->HasAura(eSpells::SPELL_CORRUPTION))
            {
                if (Aura* l_Aura = GetHitUnit()->GetAura(eSpells::SPELL_CORRUPTION))
                {
                    if (InstanceScript* l_Instance = GetHitUnit()->GetInstanceScript())
                    {
                        if (Creature* l_Amagalem = l_Instance->instance->GetCreature(l_Instance->GetObjectGuid(eData::DATA_NORUSHEN_ALMAGLEM_OF_CORRUPTION))) ///< Controller, responsible for the boss summoning.
                        {
                            int32 bp = l_Amagalem->GetHealthPct();

                            if (SpellInfo const* l_Info = sSpellMgr->GetSpellInfo(eSpells::SPELL_ICY_FEAR_DAMAGE))
                            {
                                if (bp <= 0)
                                    return;

                                int l_Damage = 100000;
                                int l_Calc = l_Damage * (2-bp/100.0f);

                                SetHitDamage(l_Calc);
                            }
                        }
                    }
                }
            }
        }

        void Register()
        {
            OnHit += SpellHitFn(spell_norushen_icy_fear_AuraScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_norushen_icy_fear_AuraScript();
    }
};

/// Unleashed Anger - 145212
class spell_norushen_unleahsed_anger : public SpellScriptLoader
{
public:
    spell_norushen_unleahsed_anger() : SpellScriptLoader("spell_norushen_unleahsed_anger") { }

    class spell_norushen_unleahsed_anger_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_norushen_unleahsed_anger_SpellScript);

        void OnHitSetDamage()
        {
            if (GetHitUnit())
            {
                // Self Doubt
                if (GetHitUnit()->HasAura(eSpells::SPELL_SELF_DOUBT))
                {
                    Aura* l_Aura = GetHitUnit()->GetAura(eSpells::SPELL_SELF_DOUBT);

                    if (l_Aura)
                    {
                        // Damage Calculation
                        int l_Damage = GetHitDamage() + (0.4f * l_Aura->GetStackAmount());
                        SetHitDamage(l_Damage);

                        l_Aura->SetStackAmount(l_Aura->GetStackAmount() + 1);
                    }
                }
                else
                    GetHitUnit()->AddAura(eSpells::SPELL_SELF_DOUBT, GetHitUnit());
            }
        }

        void Register()
        {
            OnHit += SpellHitFn(spell_norushen_unleahsed_anger_SpellScript::OnHitSetDamage/*, SpellEffIndex::EFFECT_0, Targets::TARGET_UNIT_SRC_AREA_ENEMY*/);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_norushen_unleahsed_anger_SpellScript();
    }
};

/// Blind Hatred - 145227
class spell_norushen_blind_hatred_target : public SpellScriptLoader
{
public:
    spell_norushen_blind_hatred_target() : SpellScriptLoader("spell_norushen_blind_hatred_target") { }

    class spell_norushen_blind_hatred_target_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_norushen_blind_hatred_target_SpellScript);

        void FilterTargets(std::list<WorldObject*>& p_Targets)
        {
            if (!GetCaster())
                return;

            p_Targets.clear();

            InstanceScript* l_Instance = GetCaster()->GetInstanceScript();

            if (l_Instance == nullptr)
                return;

            std::list<Player*> l_ListPlayers;
            GetCaster()->GetPlayerListInGrid(l_ListPlayers, 200.0f);
            if (l_ListPlayers.empty())
                return;

            for (auto itr : l_ListPlayers)
            {
                if (Creature* l_Amagalem = l_Instance->instance->GetCreature(l_Instance->GetObjectGuid(eData::DATA_NORUSHEN_ALMAGLEM_OF_CORRUPTION))) ///< Controller, responsible for the boss summoning.
                {
                    if (Creature* l_BlindHatredTrigger = l_Amagalem->FindNearestCreature(eCreatures::CREATURE_BLIND_HATRED_TRIGGER, 200.0f, true))
                    {
                        if (itr->IsInBetween(l_BlindHatredTrigger, l_Amagalem, 2.0f))
                            p_Targets.push_back(itr);
                    }
                }
            }
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_norushen_blind_hatred_target_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_norushen_blind_hatred_target_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENTRY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_norushen_blind_hatred_target_SpellScript();
    }
};

/// Extract Corruption - 145140
class spell_norushen_extract_corruption : public SpellScriptLoader
{
public:
    spell_norushen_extract_corruption() : SpellScriptLoader("spell_norushen_extract_corruption") { }

    class spell_norushen_extract_corruption_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_norushen_extract_corruption_SpellScript);

        void FilterTargets(std::list<WorldObject*>& p_Targets)
        {
            if (!GetCaster())
                return;

            p_Targets.clear();

            InstanceScript* l_Instance = GetCaster()->GetInstanceScript();

            if (l_Instance == nullptr)
                return;

            if (Creature* l_Trigger = l_Instance->instance->GetCreature(l_Instance->GetObjectGuid(eData::DATA_NORUSHEN_TRIGGER))) ///< Controller, responsible for the boss summoning.
            {
                p_Targets.push_back(l_Trigger->ToUnit()); // Searches for the trigger and loads it as the main target for all parallel effects.
            }
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_norushen_extract_corruption_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_TARGET_ANY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_norushen_extract_corruption_SpellScript();
    }
};

// Residual Corruption - 145073
/// Burst of Anger - 147082
class spell_norushen_src_spells_aoe_filter : public SpellScriptLoader
{
public:
    spell_norushen_src_spells_aoe_filter() : SpellScriptLoader("spell_norushen_src_spells_aoe_filter") { }

    class spell_norushen_src_spells_aoe_filter_spell_Script : public SpellScript
    {
        PrepareSpellScript(spell_norushen_src_spells_aoe_filter_spell_Script);

        void FilterTargets(std::list<WorldObject*>& p_Targets)
        {
            if (!GetCaster())
                return;

            p_Targets.clear();

            InstanceScript* l_Instance = GetCaster()->GetInstanceScript();

            if (l_Instance == nullptr)
                return;

            std::list<Player*> l_ListPlayers;
            GetCaster()->GetPlayerListInGrid(l_ListPlayers, 200.0f);
            if (l_ListPlayers.empty())
                return;

            for (auto itr : l_ListPlayers)
            {
                p_Targets.push_back(itr->ToUnit());
            }
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_norushen_src_spells_aoe_filter_spell_Script::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_norushen_src_spells_aoe_filter_spell_Script::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENTRY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_norushen_src_spells_aoe_filter_spell_Script();
    }
};

/// Blind Hatred - 145613
class spell_norushen_blind_hatred_beam_filter : public SpellScriptLoader
{
public:
    spell_norushen_blind_hatred_beam_filter() : SpellScriptLoader("spell_norushen_blind_hatred_beam_filter") { }

    class spell_norushen_blind_hatred_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_norushen_blind_hatred_SpellScript);

        void FilterTargets(std::list<WorldObject*>& p_Targets)
        {
            if (!GetCaster())
                return;

            if (GetCaster()->GetEntry() == 72776)
                return;

            p_Targets.clear();
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_norushen_blind_hatred_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_NEARBY_ENTRY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_norushen_blind_hatred_SpellScript();
    }
};

/// Blind Hatred - 145226
class spell_norushen_blind_hatred_beam : public SpellScriptLoader
{
public:
    spell_norushen_blind_hatred_beam() : SpellScriptLoader("spell_norushen_blind_hatred_beam") { }

    class spell_norushen_blind_hatred_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_norushen_blind_hatred_SpellScript);

        void OnAfterCast()
        {
            if (!GetCaster())
                return;

            if (InstanceScript* l_Instance = GetCaster()->GetInstanceScript())
            {
                if (Creature * l_Almegalem = l_Instance->instance->GetCreature(l_Instance->GetObjectGuid(eData::DATA_NORUSHEN_ALMAGLEM_OF_CORRUPTION)))
                {
                    if (Creature* l_Trigger = l_Instance->instance->GetCreature(l_Instance->GetObjectGuid(eData::DATA_NORUSHEN_TRIGGER)))
                    {
                        if (l_Almegalem != GetCaster())
                            return;

                        l_Almegalem->CastStop();

                        if (Creature* l_BlindHatred = l_Almegalem->SummonCreature(eCreatures::CREATURE_BLIND_HATRED_TRIGGER, l_Almegalem->GetPositionX(), l_Almegalem->GetPositionY(), l_Almegalem->GetPositionZ(), l_Almegalem->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 29 * TimeConstants::IN_MILLISECONDS))
                            l_Trigger->CastSpell(l_BlindHatred, eSpells::SPELL_BLIND_HATRED_FULL, true);
                    }
                }
            }
        }

        void Register()
        {
            AfterCast += SpellCastFn(spell_norushen_blind_hatred_SpellScript::OnAfterCast);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_norushen_blind_hatred_SpellScript();
    }
};

void AddSC_norushen()
{
    new boss_norushen();
    new boss_amagalad_of_corruption();
    new creature_lorewalker_cho_pre_norushen();
    new creature_norushen_manifestation_of_corruption();
    new creature_norushen_manifestation_of_corruption_non_test();
    new creature_norushen_essnece_of_corruption_non_test();
    new creature_norushen_essnece_of_corruption();
    new creature_residual_corruption();
    new creature_blind_hatred_trigger();
    new creature_look_within_trigger();
    new creature_titanic_corruption();
    new creature_greater_corruption();
    new creature_norushen_sun();
    new creature_norushen_rook();
    new creature_norushen_leven();
    new spell_norushen_icy_fear();
    new spell_norushen_unleahsed_anger();
    new spell_norushen_extract_corruption();
    new spell_norushen_blind_hatred_beam();
    new spell_norushen_src_spells_aoe_filter();
    new spell_norushen_blind_hatred_beam_filter();
}
