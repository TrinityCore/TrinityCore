/*
 * Copyright (C) 2014-2015 Warlegend-Project <http://www.warlegend-project.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "throne_of_thunder.h"
#include <array>

//=========================================================
// SQL
/*
    UPDATE creature_template SET ScriptName = "npc_council_event_helper" WHERE entry = 662203;
    UPDATE creature_template SET ScriptName = "boss_frost_king_malakk" WHERE entry = 69131;
    UPDATE creature_template SET ScriptName = "boss_kazrajin" WHERE entry = 69134;
    UPDATE creature_template SET ScriptName = "boss_sul_the_sandcrawler" WHERE entry = 69078;
    UPDATE creature_template SET ScriptName = "boss_high_priestess_marli" WHERE entry = 69132;
    UPDATE creature_template SET ScriptName = "mob_garajals_soul" WHERE entry = 69182;
    UPDATE creature_template SET ScriptName = "mob_quicksand_stalker" WHERE entry = 662205;
    UPDATE creature_template SET ScriptName = "mob_living_sand" WHERE entry = 69153;
    UPDATE creature_template SET ScriptName = "mob_blessed_loa_spirit" WHERE entry = 69480;
    UPDATE creature_template SET ScriptName = "mob_shadowed_loa_spirit" WHERE entry = 69548;
    UPDATE creature_template SET ScriptName = "mob_twisted_fate_helper" WHERE entry = 662204;
    UPDATE creature_template SET ScriptName = "mob_twisted_fate" WHERE entry IN (69740, 69746);
    
    INSERT INTO spell_script_names VALUES
    (136442, "spell_garajal_possessed"),
    (136903, "spell_malakk_frigid_assault"),
    (136917, "spell_malakk_biting_cold"),
    (136922, "spell_malakk_frostbite_periodic"),
    (136990, "spell_malakk_frostbite"),
    (136937, "spell_malakk_frostbite_allies"),
    (137084, "spell_malakk_body_heat"),
    (137117, "spell_kazrajin_reckless_charge"),
    (137149, "spell_kazrajin_overload"),
    (137166, "spell_kazrajin_discharge"),
    (136860, "spell_quicksand_periodic"),
    (136857, "spell_quicksand_entrapped"),
    (136894, "spell_sul_sandstorm"),
    (137203, "spell_marli_summon_blessed_loa_spirit"),
    (137350, "spell_marli_summon_shadowed_loa_spirit"),
    (137891, "spell_marli_twisted_fate_first"),
    (137962, "spell_marli_twisted_fate_second"),
    (137986, "spell_marli_twisted_fate_damages");
*/

//=========================================================
// Spells Analysis


//=========================================================
// Enums


enum eCreatures
{
    NPC_QUICKSAND_STALKER                   = 662205, // Acts like an AT cause Blizzard messed everythin up in this fight...
    MOB_LIVING_SAND                         = 69153, // Summoned when Sandstorm hits a Quicksand
    MOB_BLESSED_LOA_SPIRIT                  = 69480, // Summoned by Mar'li, heals a councillor
    MOB_SHADOWED_LOA_SPIRIT                 = 69548, // Summoned by Mar'li, kills player
    MOB_TWISTED_FATE_FIRST                  = 69740, // First Twisted Fate npc to be summoned, will move toward the second and vice-versa
    MOB_TWISTED_FATE_SECOND                 = 69746, // Second Twisted Fate npc to be summoned
};

enum eSpells
{
    //===============================================
    // Gara'Jal's Soul
    SPELL_LINGERING_PRESENCE                = 136467, // When the spirit of Gara'jal leaves a councillor
    SPELL_POSSESSED                         = 136442, // When the spirit of Gara'jal merges with a councillor (periodic dummy ? Dark Energy maybe)
    SPELL_DARK_POWER                        = 136507, // Damages increase with each cast

    // Soul Fragment
    SPELL_SOUL_FRAGMENT_SELECTOR            = 137645, // Trigger 137641 (AREA_ENTRY ?)
    SPELL_SOUL_FRAGMENT_PERIODIC            = 137641, // Override spells with 137643
    SPELL_SOUL_FRAGMENT_SWITCHER            = 137643, // Trigger 137641
    SPELL_SOUL_FRAGMENT_DUMMY               = 137670, // Maybe visual
    SPELL_SHADOWED_SOUL                     = 137650, // Each time 137641 ticks

    //===============================================
    // Frost King Malakk

    // Frigid Assault
    SPELL_FRIGID_ASSAULT                    = 136904, // Apply trigger auras
    SPELL_FRIGID_ASSAULT_STACK              = 136903, // Stun owner when stacks reach 15
    SPELL_FRIGID_ASSAULT_DAMAGES            = 136911, // Damages
    SPELL_FRIGID_ASSAULT_STUN               = 136910, // When 136903 reaches 15 stacks

    // Biting Cold <=> Frostbite
    SPELL_BITING_COLD                       = 136917, // Main damages (select random target, need AuraScript or SpellScript)
    SPELL_BITING_COLD_PERIODIC_DAMAGES      = 136992, // Periodically trigger 136991
    SPELL_BITING_COLD_ALLY_DAMAGES          = 136991, // Periodic damages to allies
    SPELL_BITING_COLD_PERIODIC_DUMMY        = 137579, // Periodic trigger 137580
    SPELL_BITING_COLD_DUMMY                 = 137580, // Visual maybe ?
    // When Malakk has the possessed aura, Biting Cold turns into Frostbite
    SPELL_FROSTBITE                         = 136990, // Main damages (works like Biting Cold)
    SPELL_FROSTBITE_PERIODIC_DAMAGES        = 136922, // Periodic trigger damages to ally (amount must be multiplied to fit stack amount)
    SPELL_FROSTBITE_ALLY_DAMAGES            = 136937, // Damages to allies
    SPELL_FROSTBITE_SCREEN_EFFECT           = 136926, // Screen effect
    SPELL_FROSTBITE_DUMMY_AURA              = 137575, // Unknown
    // Is there something that can stack ?
    // Bodyheat triggers when Frostbite hits an ally in Heroic
    SPELL_BODY_HEAT                         = 137084, // Triggers 137085 on expire (AuraScript)
    SPELL_CHILLED_TO_THE_BONE               = 137085, // Prevents player from reducing Frostbite amount of nearby players (or only caster ?)

    //===============================================
    // Kazra'jin

    // Reckless Charge
    SPELL_RECKLESS_CHARGE                   = 137117, // Visual on the boss while travelling (launch everything) ("They see me rollin ! FUCK YEAH !")
    SPELL_RECKLESS_CHARGE_GROUND_AT         = 138026, // Visual on the ground while boss is travelling (damage dealer ?)
    SPELL_RECKLESS_CHARGE_SHATTER_GROUND    = 137122, // Final damages + Knock back and visual of rocks appearing around
    SPELL_RECKLESS_CHARGE_UNIQUE_DAMAGES    = 137133, // Damage on unique target (AT ? Kazra'jin ?)
    SPELL_RECKLESS_CHARGE_PRE_PATH          = 000000, // TBF: Visual of dark pools on ground before charge
    // Need black visual on ground before cast

    // Overload
    // When Kazra'jin is empowered, he overloads after performing a Reckless Charge
    SPELL_OVERLOAD                          = 137149, // Dummy aura to handle the strike back (HandleDummyAuraProc ?) (must add UNIT_STATE_STUN manually)
    SPELL_OVERLOAD_DAMAGES                  = 137151, // Damage spell
    SPELL_OVERLOAD_VISUAL                   = 137163, // Visual on caster of spell that triggered mirror effect
    // In Heroic, Overload turns into Discharge
    SPELL_DISCHARGE                         = 137166, // Periodic dummy ? Why ? (must add UNIT_STATE_STUN manually)
    SPELL_DISCHARGE_DAMAGES                 = 136935, // Damage spell
    SPELL_DISCHARGE_VISUAL                  = 137172, // Visual on all players when spell ticks

    //===============================================
    // Sul the Sandcrawler

    SPELL_SAND_BOLT                         = 136189, // Trigger Missile 136190
    SPELL_SAND_BOLT_DAMAGES                 = 136190, // Damages

    // Quicksand (fuckin AT)
    // Quicksand is an AT, but handling the spell with an AT is too complex... we'll use another mechanism,
    SPELL_QUICKSAND_PERIODIC_DAMAGES        = 136860, // Periodic damages to any target within 7 yards : we must handle apply / remove manually
    SPELL_QUICKSAND_AT_VISUAL               = 137572, // Visual 
    SPELL_ENSNARED                          = 136878, // Slow player and stacks; when it reaches 5 stacks, player is Entrapped
    SPELL_ENTRAPPED                         = 136857, // Need to prevent second effect... so annoying

    // Sandstorm
    SPELL_SAND_STORM                        = 136894, // Periodic trigger 136899,
    SPELL_SAND_STORM_DAMAGES                = 136899, // Damages
    SPELL_SAND_STORM_DUMMY_AURA             = 136895, // Maybe visual since it has the same duration as 136894

    //===============================================
    // High Priestess Mar'li

    // Wrath of the Loa
    SPELL_WRATH_OF_THE_LOA                  = 137344,
    SPELL_WRATH_OF_THE_LOA_DARK             = 137347, // When Possessed

    // Loa Spirit <=> Twisted Fate
    SPELL_BLESSED_LOA_SPIRIT                = 137203, // Handle dummy cause Blizzard messed that up
    SPELL_SUMMON_BLESSED_LOA_SPIRIT         = 137200, // Summons 69480
    SPELL_SHADOWED_LOA_SPIRIT               = 137350, // Handle dummy cause Blizzard messed that up (Possessed version of Loa Spirit)
    SPELL_SUMMON_SHADOWED_LOA_SPIRIT        = 137351, // Summons 69548
    // In Heroic, Shadowed Loa Spirit is replaced with Twisted Fate
    SPELL_TWISTED_FATE_PERIODIC             = 137986, // Periodic trigger 137972,
    SPELL_TWISTED_FATE_DAMAGES              = 137972, // Periodic damages while linked AND while not linked (must update value in handler of 137986)
    SPELL_TWISTED_FATE_DUMMY_AURA           = 137964, // Visual maybe ?
    // First npc of Twisted Fate
    SPELL_TWISTED_FATE                      = 137891, // Launch everything (triggers 137893)
    SPELL_TWISTED_FATE_SUMMON_FIRST         = 137893, // Summon the first Twisted Fate
    SPELL_TWISTED_FATE_FORCE_FIRST          = 137943, // Force cast 137950 on self
    SPELL_TWISTED_FATE_CLONE_FIRST          = 137950, // Clone, Dummy, Size... WHAT ELSE ?
    // Second npc of Twisted Fate
    SPELL_TWISTED_FATE_FORCE_SUMMON_SECOND  = 137962, // Trigger 137963 on the most distant player (fuck target)
    SPELL_TWISTED_FATE_SUMMON_SECOND        = 137963, // Summon the second Twisted Fate
    SPELL_TWISTED_FATE_FORCE_SECOND         = 137964, // Force cast 137965 on self
    SPELL_TWISTED_FATE_CLONE_SECOND         = 137965, // Clone, Dummy, Size... WHAT ELSE ?

    //===============================================
    // Summons
    SPELL_FORTIFIED                         = 136864, // Living Sand : On hit by Sandstorm
    SPELL_TREACHEROUS_GROUND                = 137614, // Living Sand : On emerge from reunited Quicksand
    SPELL_BLESSED_GIFT                      = 137303, // Blessed Loa Spirit, heal 5% of Max Health on weakest councillor
    SPELL_BLESSED_TIME_OUT                  = 137204, // Dummy visual for blizz
    SPELL_MARKED_SOUL                       = 137359, // Shadowed Loa Spirit / Player ? Force Loa to follow player
    SPELL_SHADOWED_GIFT                     = 137390, // Instantly kills player (Shadowed Loa Spirit)
    SPELL_SHADOWED_TIME_OUT                 = 137398, // Dummy visual for blizz
    
    //===============================================
    // Visuals
    SPELL_GARA_JALS_SOUL                    = 136423, // NPC Visual
    SPELL_BLESSED_TRANSFORMATION            = 137181, // NPC Visual
    SPELL_SHADOWED_TRANSFORMATION           = 137271, // NPC Visual
    SPELL_GARAJAL_GHOST                     = 000000, // TBF
    
    //===============================================
    // Shared
    SPELL_ZERO_POWER                        = 72242, // Thanks Sungis and Thelt
};


enum eEvents
{
    //===============================================
    // Frost King Malakk
    EVENT_FRIGID_ASSAULT                    = 1,
    EVENT_BITING_COLD                       = 2,
    EVENT_FROSTBITE                         = 3,

    //===============================================
    // Kazra'jin
    EVENT_RECKLESS_CHARGE_PRE_PATH          = 4,
    EVENT_RECKLESS_CHARGE                   = 5,

    //===============================================
    // Sul the Sandcrawler
    EVENT_SAND_BOLT                         = 6,
    EVENT_QUICKSAND                         = 7,
    EVENT_SANDSTORM                         = 8,

    //===============================================
    // High Priestess Mar'li
    EVENT_WRATH_OF_THE_LOA                  = 9,
    EVENT_WRATH_OF_THE_LOA_DARK             = 10,
    EVENT_BLESSED_LOA_SPIRIT                = 11,
    EVENT_SHADOWED_LOA_SPIRIT               = 12,
    EVENT_TWISTED_FATE                      = 13,

    //===============================================
    // Blessed Loa Spirit
    EVENT_BLESSED_GIFT                      = 14,

    //===============================================
    // Shadowed Loa Spiri
    EVENT_SHADOWED_GIFT                     = 15,

    //===============================================
    // Councillots
    EVENT_INCREASE_POWER                    = 16,
    EVENT_DARK_POWER                        = 17,

    //===============================================
    // Quicksand Stalker
    EVENT_QUICKSAND_PERIODIC                = 18, // This only handles apply of the Quicksand damages aura, which handle the rooting by itself
    EVENT_TRY_MERGE                         = 19, // Try merge event is used to merge Quicksand when they are summoend by others Quicksand (only scheduled once)
    
    //===============================================
    // Garajal
    EVENT_SUMMON_SOUL                       = 20,
};


enum eActions
{
    //===============================================
    // Gara'jal
    ACTION_ENTER_COMBAT                     = 0, // Garajal + Garajal's soul
    ACTION_EXIT_COUNCILLOR                  = 1, // Garajal's soul

    //===============================================
    // Council Event Helper
    ACTION_FIGHT_RESET                      = 2,
    ACTION_FIGHT_BEGIN                      = 3,

    //===============================================
    // Councillors
    ACTION_COUNCILLORS_ENTER_COMBAT         = 4, // When one enters combat, everybody else must enter combat
    ACTION_SET_POSSESSED                    = 5, // Initialize the events to possessed phase (called from SpellScript)
    ACTION_SET_UNPOSSESSED                  = 6, // Reset the events to normal (same as for SET_POSSESED)
    ACTION_DARK_POWER                       = 7, // Initialize the Dark Power phase (called from the handler of the periodic dummy aura I assume)

    //===============================================
    // Kazra'jin
    ACTION_RESET_DAMAGES                    = 8, // Must be called each time the periodic aura ticks

    //===============================================
    // Living Sand
    ACTION_FORTIFY                          = 9,

    //===============================================
    // Twisted Fate Helper
    ACTION_TWISTED_FATE_END_FIGHT           = 10, // Used to deallocate memory

    //===============================================
    // Twisted Fate (common)
    ACTION_OTHER_TWISTED_FATE_DIED          = 11,

    //===============================================
    // Quicksand
    ACTION_CREATE_LIVING_SAND               = 12,
};


enum eMotions
{
    //===============================================
    // Gara'jal
    POINT_COUNCILLOR                        = 0,

    //===============================================
    // Kazra'jin
    POINT_RECKLESS_CHARGE_LAND              = 1, // Position where Kazrajin lands after performing Reckless Charge
    POINT_RECKLESS_CHARGE_PLAYER            = 2, // Position where Kazrajin rolls to after landing from Reckless Charge

    //===============================================
    // Blessed Loa Spirit
    POINT_BLESSED_LOA_SPIRIT_COUNCILLOR     = 3, // Point to identify the councillor the Blessed Loa Spirit is going toward
    // No need to do a point for the Shadowed Loa Spirit since it will not
    // reach the target but only go 6 yards away from him (so we can use MoveFollow)

    //===============================================
    // Twisted Fate (common)
    POINT_MIDDLE                            = 4, // Point representing the middle point on the line formed by the two Twisted Fate
};


enum eHelperStatus
{
    STATUS_RESET                            = 0,
    STATUS_PROGRESS                         = 1,
    STATUS_DONE                             = 2,
};


enum eDatas
{
    DATA_DARK_POWER_COUNT                   = 0,
    DATA_QUICKSAND_MERGE_COUNT              = 1,
    DATA_SHADOWED_LOA_SPIRIT_TARGET_GUID    = 2, // Accessor to get the GUID of the player the Shadowed Loa Spirit will follow
    DATA_BLESSED_LOA_SPIRIT_TARGET_GUID     = 3, // Accessor to get the GUID of the boss the Blessed Loa Spirit will follow
    DATA_TWISTED_FATE_GUID                  = 4, // Accessor to get the GUID of the twisted fate the caller is linked to
    DATA_TWISTED_FATE_OTHER_DIED            = 5, // Accessor to know if one twisted fate has been unlinked from the other
    DATA_RECKLESS_CHARGE_TARGET_GUID        = 6, // Accessor to get the GUID of the player Kazrajin is targetting for the purpose of Reckless Charge
    DATA_DAMAGES_PAST_SEC                   = 7, // Accessor to get the amount of damages Kazrajin received in the last second
};


enum eTalks
{
    //===============================================
    // Malakk
    SAY_MALAKK_POSSESSED                    = 0, // Winter is coming
    SAY_MALAKK_DEATH                        = 1, // Da empire can't fail
    SAY_MALAKK_FROSTBITE_1                  = 2, // Getting cold ?
    SAY_MALAKK_FROSTBITE_2                  = 3, // Freeze
    SAY_MALAKK_KILLED_UNIT_1                = 4, // Death's cold embrace
    SAY_MALAKK_KILLED_UNIT_2                = 5, // Witness da Drakkari's might
    SAY_MALAKK_AGGRO                        = 6, // Ya have met your match, fools (aggro ?)
    
    //===============================================
    // Kazra'jin
    SAY_KAZ_POSSESSED                       = 0, // ????
    SAY_KAZ_DEATH                           = 1, // Da thunder king... promised
    SAY_KAZ_RECKLESS_CHARGE_1               = 2, // Incoming !
    SAY_KAZ_RECKLESS_CHARGE_2               = 3, // Out da way !
    SAY_KAZ_AGGRO                           = 4, // This is gonna hurt
    SAY_KAZ_KILLED_UNIT_1                   = 5, // Ya shouldn't be messin wit da zandalari
    SAY_KAZ_KILLED_UNIT_2                   = 6, // On ya knees
    SAY_KAZ_OVERLOAD_DISCHARGE              = 7, // Schoking !
    
    //===============================================
    // Sul
    SAY_SUL_POSSESSED                       = 0, // I will bury ya all
    SAY_SUL_DEATH                           = 1, // I... return... to... da... sands
    SAY_SUL_SAND_STORM                      = 2, // Da storms approaches
    SAY_SUL_QUICKSAND                       = 3, // Watch yer steps
    SAY_SUL_KILLED_UNIT_1                   = 4, // Da sands are endless
    SAY_SUL_KILLED_UNIT_2                   = 5, // Da first of many
    SAY_SUL_AGGRO                           = 6, // Da sands will consume everything
    
    //===============================================
    // Mar'li
    SAY_MARLI_POSSESSED                     = 0, // Da spritibinder reveals ya soul to me 
    SAY_MARLI_DEATH                         = 1, // Shadra... save... me
    SAY_MARLI_SHADOWED_LOA_SPIRIT_1         = 2, // Succumb to her venom
    SAY_MARLI_SHADOWED_LOA_SPIRIT_2         = 3, // Yer soul belongs to me (Shadowed Loa Spirit ?)
    SAY_MARLI_SHADOWED_LOA_SPIRIT_3         = 4, // Embrace yer desmise
    SAY_MARLI_KILLED_UNIT_1                 = 5, // Another offering to da loa
    SAY_MARLI_KILLED_UNIT_2                 = 6, // She will feast on yer soul
    SAY_MARLI_AGGRO                         = 7, // Death to all who appose da empire 
    
    //===============================================
    // Gara'jal
    SAY_GARAJAL_INTRO                       = 0,
};

//=========================================================
// Helpers


static Creature *GetCouncilEventHelper(WorldObject *pSource)
{
    return ObjectAccessor::GetCreature(*pSource, pSource->GetInstanceScript()->GetObjectGuid(NPC_COUNCIL_EVENT_HELPER));
}

static Creature *GetGarajal(WorldObject *pSource)
{
    return ObjectAccessor::GetCreature(*pSource, pSource->GetInstanceScript()->GetObjectGuid(MOB_GARA_JAL));
}

static Creature *GetGarajalsSoul(WorldObject *pSource)
{
    return ObjectAccessor::GetCreature(*pSource, pSource->GetInstanceScript()->GetObjectGuid(MOB_GARA_JALS_SOUL));
}

static Creature *GetFrostKingMalakk(WorldObject *pSource)
{
    return ObjectAccessor::GetCreature(*pSource, pSource->GetInstanceScript()->GetObjectGuid(BOSS_COUNCIL_FROST_KING_MALAKK));
}

static Creature *GetKazrajin(WorldObject *pSource)
{
    return ObjectAccessor::GetCreature(*pSource, pSource->GetInstanceScript()->GetObjectGuid(BOSS_COUNCIL_KAZRAJIN));
}

static Creature *GetSulTheSandcrawler(WorldObject *pSource)
{
    return ObjectAccessor::GetCreature(*pSource, pSource->GetInstanceScript()->GetObjectGuid(BOSS_COUNCIL_SUL_THE_SANDCRAWLER));
}

static Creature *GetHighPriestessMarli(WorldObject *pSource)
{
    return ObjectAccessor::GetCreature(*pSource, pSource->GetInstanceScript()->GetObjectGuid(BOSS_COUNCIL_HIGH_PRIESTESS_MARLI));
}

static Creature *GetBossByEntry(uint32 uiEntry, WorldObject *pSource)
{
    switch(uiEntry)
    {
    case BOSS_COUNCIL_FROST_KING_MALAKK:
        return GetFrostKingMalakk(pSource);

    case BOSS_COUNCIL_KAZRAJIN:
        return GetKazrajin(pSource);

    case BOSS_COUNCIL_SUL_THE_SANDCRAWLER:
        return GetSulTheSandcrawler(pSource);

    case BOSS_COUNCIL_HIGH_PRIESTESS_MARLI:
        return GetHighPriestessMarli(pSource);

    default:
        return NULL;
    }
}

// Convenient typedef for the accessors
typedef Creature* (*Accessor)(WorldObject *pSource);

static const std::array<uint32, 4> uiBossEntries = {BOSS_COUNCIL_FROST_KING_MALAKK, BOSS_COUNCIL_KAZRAJIN, BOSS_COUNCIL_SUL_THE_SANDCRAWLER, BOSS_COUNCIL_HIGH_PRIESTESS_MARLI};


//=========================================================
// Creature Scripts


// Council Event Helper AI
class npc_council_event_helper : public CreatureScript
{
public:
    npc_council_event_helper() : CreatureScript("npc_council_event_helper") { }

    class npc_council_event_helper_AI : public ScriptedAI
    {
    public:
        npc_council_event_helper_AI(Creature *pCreature) :
            ScriptedAI(pCreature), pInstance(pCreature->GetInstanceScript()), eStatus(STATUS_RESET)
        {
            vDeadCouncillors.clear();
        }

        void Reset()
        {
            ResetEvent();
        }

        void DoAction(int32 iAction)
        {
            switch(iAction)
            {
            // Called from Reset() of every boss
            case ACTION_FIGHT_RESET:
                ResetEvent();
                break;

            // Called from EnterCombat() of every boss
            case ACTION_FIGHT_BEGIN:
                BeginEvent();
                break;

            default:
                break;
            }
        }

        // public to access with dynamic_cast
        void CouncillorDeath(Creature *pCouncillor)
        {
            ASSERT(vDeadCouncillors.find(pCouncillor) == vDeadCouncillors.end());

            vDeadCouncillors.insert(pCouncillor);

            if(vDeadCouncillors.size() == 4)
            {
                pInstance->SetBossState(DATA_COUNCIL_OF_ELDERS, DONE);
                eStatus = STATUS_DONE;

                if(Creature *pTwistedFateHelper = ObjectAccessor::GetCreature(*me, pInstance->GetObjectGuid(NPC_TWISTED_FATE_HELPER)))
                    pTwistedFateHelper->AI()->DoAction(ACTION_TWISTED_FATE_END_FIGHT);
                    
                std::list<Player*> playerList;
                me->GetPlayerListInGrid(playerList, 500.0f);
                
                for(Player *pIter: playerList)
                    pIter->RemoveAurasDueToSpell(SPELL_SHADOWED_SOUL);
            }
        }

    private:
        InstanceScript      *pInstance;
        eHelperStatus       eStatus;
        std::set<Creature*> vDeadCouncillors;

        // Reset the event if not already reset. Send informations to InstanceScript,
        // force dead councillor to respawn, and let Garajal EnterEvadeMode() (really
        // important to call EnterEvadeMode() and not Reset(), Reset() is a subsequent
        // call from EnterEvadeMode().
        void ResetEvent()
        {
            // Return since we are already reset
            if(eStatus == STATUS_RESET)
                return;

            pInstance->SetBossState(DATA_COUNCIL_OF_ELDERS, NOT_STARTED);

            eStatus = STATUS_RESET;

            for(Creature *pIter : vDeadCouncillors)
                pIter->Respawn();

            // Reset Garajal here, to be sure he won't reset four times
            if(Creature *pGarajalSoul = GetGarajalsSoul(me))
                pGarajalSoul->DisappearAndDie();
                
            if(Creature *pGarajal = GetGarajal(me))
                pGarajal->AI()->Reset();

            // Clean zone from summons
            DespawnCreatures();
        }

        // Start the event if not already started: send informations to InstanceScript,
        // put all the boss in combat with zone, and orders Garajal to possess Malakk.
        void BeginEvent()
        {
            // Return if we are already in progress
            if(eStatus == STATUS_PROGRESS)
                return;

            eStatus = STATUS_PROGRESS;

            pInstance->SetBossState(DATA_COUNCIL_OF_ELDERS, IN_PROGRESS);

            if(Creature *pGarajal = GetGarajal(me))
                pGarajal->AI()->DoAction(ACTION_ENTER_COMBAT);

            std::array<Creature*, 4> apCouncillors = {GetFrostKingMalakk(me), GetKazrajin(me), GetSulTheSandcrawler(me), GetHighPriestessMarli(me)};
            for(Creature *pCouncillor: apCouncillors)
            {
                // Do not call DoAction if councillor is already in combat
                if(pCouncillor && !pCouncillor->IsInCombat())
                    pCouncillor->AI()->DoAction(ACTION_COUNCILLORS_ENTER_COMBAT);
            }
        }

        inline void DespawnCreatures() const
        {
            DespawnCreaturesByEntry(NPC_QUICKSAND_STALKER);
            DespawnCreaturesByEntry(MOB_LIVING_SAND);
            DespawnCreaturesByEntry(MOB_BLESSED_LOA_SPIRIT);
            DespawnCreaturesByEntry(MOB_SHADOWED_LOA_SPIRIT);
            DespawnCreaturesByEntry(MOB_TWISTED_FATE_FIRST);
            DespawnCreaturesByEntry(MOB_TWISTED_FATE_SECOND);
        }

        void DespawnCreaturesByEntry(uint32 uiEntry) const
        {
            std::list<Creature*> minionsList;
            GetCreatureListWithEntryInGrid(minionsList, me, uiEntry, 500.0f);

            for(Creature *pMinion: minionsList)
                pMinion->DespawnOrUnsummon();
        }
    };

    CreatureAI *GetAI(Creature *pCreature) const
    {
        return GetThroneOfThunderAI<npc_council_event_helper_AI, Creature>(pCreature);
    }
};
typedef npc_council_event_helper::npc_council_event_helper_AI HelperAI;


// Base class for the councillor's AI (only override common functions)
class boss_council_of_elders_base_AI : public ScriptedAI
{
public:
    boss_council_of_elders_base_AI(Creature *pCreature) :
        ScriptedAI(pCreature), pInstance(pCreature->GetInstanceScript())
    {
        events.Reset();
    }

    // Override Reset to reset the EventMap in one place and force
    // reset of the fight by sending DoAction to the helper.
    // Note: if one boss reset, every other boss need to reset. Otherwise,
    // it would be a very major fail, meaning that a creature can reset while
    // other close creatures are still in combat.
    void Reset()
    {
        if(Creature *pHelper = GetCouncilEventHelper(me))
        {
            if(CreatureAI *pHelperAI = pHelper->AI())
                pHelperAI->DoAction(ACTION_FIGHT_RESET);
        }

        events.Reset();

        me->setPowerType(POWER_ENERGY);
        me->SetMaxPower(POWER_ENERGY, 100);
        me->SetPower(POWER_ENERGY, 0);

        DoCast(me, SPELL_ZERO_POWER);
        uiDarkPowerCount        = 0;
        uiDamageTakenPossessed  = 0;
    }

    // Override EnterCombat to send the DoAction to the helper
    void EnterCombat(Unit *pAttacker)
    {
        if(Creature *pHelper = GetCouncilEventHelper(me))
        {
            if(CreatureAI *pHelperAI = pHelper->AI())
                pHelperAI->DoAction(ACTION_FIGHT_BEGIN);
        }
        
        switch(me->GetEntry())
        {
        case BOSS_COUNCIL_FROST_KING_MALAKK:
            Talk(SAY_MALAKK_AGGRO);
            break;
            
        case BOSS_COUNCIL_KAZRAJIN:
            Talk(SAY_KAZ_AGGRO);
            break;
            
        case BOSS_COUNCIL_SUL_THE_SANDCRAWLER:
            Talk(SAY_SUL_AGGRO);
            break;
            
        case BOSS_COUNCIL_HIGH_PRIESTESS_MARLI:
            Talk(SAY_MARLI_AGGRO);
            break;
            
        default:
            break;
        }

        InitStandartEvents();
    }

    // Override DoAction for the generic actions
    void DoAction(int32 iAction)
    {
        switch(iAction)
        {
        case ACTION_COUNCILLORS_ENTER_COMBAT:
            // The call to AttackStart will be kinda useless for some
            // boss since they can't move, which will result in useless
            // call to MoveChase. Anyway, I do not want to recode this
            // function now.
            DoZoneInCombat();
            InitStandartEvents();
            break;

        case ACTION_SET_POSSESSED:
            switch(me->GetEntry())
            {
            case BOSS_COUNCIL_FROST_KING_MALAKK:
                Talk(SAY_MALAKK_POSSESSED);
                break;
                
            case BOSS_COUNCIL_KAZRAJIN:
                Talk(SAY_KAZ_POSSESSED);
                break;
                
            case BOSS_COUNCIL_SUL_THE_SANDCRAWLER:
                Talk(SAY_SUL_POSSESSED);
                break;
                
            case BOSS_COUNCIL_HIGH_PRIESTESS_MARLI:
                Talk(SAY_MARLI_POSSESSED);
                break;
                
            default:
                break;
            }
            InitPossessedEvents();
            events.ScheduleEvent(EVENT_INCREASE_POWER, GetPowerTimer());
            uiDarkPowerCount = 0;
            break;

        case ACTION_SET_UNPOSSESSED:
            me->SetPower(POWER_ENERGY, 0);
            InitStandartEvents();
            uiDarkPowerCount = 0;
            break;

        case ACTION_DARK_POWER:
            InitDarkPower();
            uiDarkPowerCount = 0;
            break;
        }
    }

    void DamageTaken(Unit *pAttacker, uint32 &ruiAmount)
    {
        if(!me->HasAura(SPELL_POSSESSED))
            return;

        uiDamageTakenPossessed += ruiAmount;
        if((float)uiDamageTakenPossessed >= (float)((float)me->GetMaxHealth() * 0.25f))
        {
            // No remove when no other councillor alive
            if(IsACouncillorAlive())
                DoCast(me, SPELL_LINGERING_PRESENCE);
            uiDamageTakenPossessed = 0; // Reset in both case to prevent chain call to IsACouncillorAlive
        }
    }
    
    void JustDied(Unit *pKiller)
    {
        switch(me->GetEntry())
        {
        case BOSS_COUNCIL_FROST_KING_MALAKK:
            Talk(SAY_MALAKK_DEATH);
            break;
            
        case BOSS_COUNCIL_KAZRAJIN:
            Talk(SAY_KAZ_DEATH);
            break;
            
        case BOSS_COUNCIL_SUL_THE_SANDCRAWLER:
            Talk(SAY_SUL_DEATH);
            break;
            
        case BOSS_COUNCIL_HIGH_PRIESTESS_MARLI:
            Talk(SAY_MARLI_DEATH);
            break;
            
        default:
            break;
        }
    }
    
    void KilledUnit(Unit *pKilled)
    {
        switch(me->GetEntry())
        {
        case BOSS_COUNCIL_FROST_KING_MALAKK:
            Talk(RAND<uint8>(SAY_MALAKK_KILLED_UNIT_1, SAY_MALAKK_KILLED_UNIT_2));
            break;
            
        case BOSS_COUNCIL_KAZRAJIN:
            Talk(RAND<uint8>(SAY_KAZ_KILLED_UNIT_1, SAY_KAZ_KILLED_UNIT_2));
            break;
            
        case BOSS_COUNCIL_SUL_THE_SANDCRAWLER:
            Talk(RAND<uint8>(SAY_SUL_KILLED_UNIT_1, SAY_SUL_KILLED_UNIT_2));
            break;
            
        case BOSS_COUNCIL_HIGH_PRIESTESS_MARLI:
            Talk(RAND<uint8>(SAY_MARLI_KILLED_UNIT_1, SAY_MARLI_KILLED_UNIT_2));
            break;
            
        default:
            break;
        }
    }

    // Helper function to prevent removing the possessed aura when no
    // other councillor is alive.
    bool IsACouncillorAlive() const
    {
        Creature    *pMalakk    = GetFrostKingMalakk(me),
                    *pKazrajin  = GetKazrajin(me),
                    *pSul       = GetSulTheSandcrawler(me),
                    *pMarli     = GetHighPriestessMarli(me);

        // Pointers should not be null
        if(!pMalakk || !pKazrajin || !pSul || !pMarli)
            return false;

        switch(me->GetEntry())
        {
        case BOSS_COUNCIL_FROST_KING_MALAKK:
            return (pKazrajin->IsAlive() || pSul->IsAlive() || pMarli->IsAlive());

        case BOSS_COUNCIL_KAZRAJIN:
            return (pSul->IsAlive() || pMarli->IsAlive() || pMalakk->IsAlive());

        case BOSS_COUNCIL_SUL_THE_SANDCRAWLER:
            return (pMarli->IsAlive() || pMalakk->IsAlive() || pKazrajin->IsAlive());

        case BOSS_COUNCIL_HIGH_PRIESTESS_MARLI:
            return (pMalakk->IsAlive()|| pKazrajin->IsAlive() || pSul->IsAlive());

        default:
            return false;
        }
    }
    
    uint32 GetData(uint32 uiIndex) const
    {
        if (uiIndex == DATA_DARK_POWER_COUNT)
            return uiDarkPowerCount;

        return 0;
    }

// Use the protected scope, so we do not have to declare again the same attributes
protected:
    EventMap        events;
    InstanceScript  *pInstance;
    uint32          uiDarkPowerCount; // Internal counter to know the real amount of damages of Dark Power
    // Internal counter to know the amount of damages we have
    // taken since the possession began. When this amount is
    // equal or higher than 25% of our max health point, we
    // get rid of Garajal's Soul.
    uint32          uiDamageTakenPossessed;

    // Virtual methods used to init the events when fight begin
    // or possession begins / ends. Use pure virtual function to
    // be sure everybody overrides it.
    virtual void InitStandartEvents() = 0;
    virtual void InitPossessedEvents() = 0;

    // Method to init the DarkPower event, so there is no need
    // to repeat the same code each time.
    void InitDarkPower()
    {
        events.Reset();
        events.ScheduleEvent(EVENT_DARK_POWER, 1 * IN_MILLISECONDS);
    }
    
    uint32 GetPowerTimer()
    {
        if(Aura *pLingeringPresence = me->GetAura(SPELL_LINGERING_PRESENCE))
        {
            float fReduce   = 1 - (pLingeringPresence->GetStackAmount() / 10);
            uint32 uiTimer  = (2 * IN_MILLISECONDS) * fReduce;
            return uiTimer;
        }
        else
            return 2 * IN_MILLISECONDS;

        return 0;
    }
};
typedef boss_council_of_elders_base_AI CouncilBaseAI;


// Frost King Malakk AI
class boss_frost_king_malakk : public CreatureScript
{
public:
    boss_frost_king_malakk() : CreatureScript("boss_frost_king_malakk") { }

    class boss_frost_king_malakk_AI : public CouncilBaseAI
    {
    public:
        boss_frost_king_malakk_AI(Creature *pCreature) :
            CouncilBaseAI(pCreature)
        {

        }

        // No need to override Reset since there is nothing to reset here
        // No need to override EnterCombat since there is nothing to do here

        void UpdateAI(uint32 uiDiff)
        {
            if(!UpdateVictim())
                return;

            events.Update(uiDiff);

            if(me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while(uint32 uiEventId = events.ExecuteEvent())
            {
                switch(uiEventId)
                {
                case EVENT_FRIGID_ASSAULT:
                    DoCast(me, SPELL_FRIGID_ASSAULT);
                    events.ScheduleEvent(EVENT_FRIGID_ASSAULT, urand(15, 35) * IN_MILLISECONDS);
                    break;

                case EVENT_BITING_COLD:
                    DoCastAOE(SPELL_BITING_COLD); // Spell is wierd... handle target selection in SpellScript
                    events.ScheduleEvent(EVENT_BITING_COLD, urand(8, 16) * IN_MILLISECONDS);
                    break;

                case EVENT_FROSTBITE:
                    Talk(RAND<uint8>(SAY_MALAKK_FROSTBITE_1, SAY_MALAKK_FROSTBITE_2));
                    DoCastAOE(SPELL_FROSTBITE); // Handle target selection in SpellScript
                    events.ScheduleEvent(EVENT_FROSTBITE, urand(8, 16) * IN_MILLISECONDS);
                    break;

                case EVENT_DARK_POWER:
                    DoCastAOE(SPELL_DARK_POWER);
                    ++uiDarkPowerCount;
                    events.ScheduleEvent(EVENT_DARK_POWER, 1 * IN_MILLISECONDS);
                    break;
                    
                case EVENT_INCREASE_POWER:
                    me->ModifyPower(POWER_ENERGY, 3);
                    if(me->GetPower(POWER_ENERGY) < 100)
                        events.ScheduleEvent(EVENT_INCREASE_POWER, GetPowerTimer());
                    else
                        DoAction(ACTION_DARK_POWER);
                    break;

                default:
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }

    private:
        void InitStandartEvents()
        {
            events.Reset();

            events.ScheduleEvent(EVENT_FRIGID_ASSAULT, 10 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_BITING_COLD, 15 * IN_MILLISECONDS);
        }

        void InitPossessedEvents()
        {
            events.Reset();

            events.ScheduleEvent(EVENT_FRIGID_ASSAULT, 10 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_FROSTBITE, 15 * IN_MILLISECONDS);
        }
    };

    CreatureAI* GetAI(Creature *pCreature) const
    {
        return GetThroneOfThunderAI<boss_frost_king_malakk_AI, Creature>(pCreature);
    }
};


// Kazra'jin AI
class boss_kazrajin : public CreatureScript
{
public:
    boss_kazrajin() : CreatureScript("boss_kazrajin") { }

    class boss_kazrajin_AI : public CouncilBaseAI
    {
    public:
        boss_kazrajin_AI(Creature *pCreature):
            CouncilBaseAI(pCreature), uiDamagesDoneInPastSecs(0)
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
        }

        // Override reset to reset the amount of damages received, and the
        // movement flags.
        void Reset()
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
            uiDamagesDoneInPastSecs = 0;

            CouncilBaseAI::Reset(); // Finalize Reset
        }

        void UpdateAI(uint32 uiDiff)
        {
            if(!UpdateVictim())
                return;

            events.Update(uiDiff);

            if(me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while(uint32 uiEventId = events.ExecuteEvent())
            {
                switch(uiEventId)
                {
                case EVENT_RECKLESS_CHARGE_PRE_PATH:
                {
                    DoCast(me, SPELL_RECKLESS_CHARGE_PRE_PATH);

                    // Compute a random target
                    std::list<Player*> playerList;
                    me->GetPlayerListInGrid(playerList, 100.0f);
                    // Target must be at a minimal range of 18 yards (not sure)
                    playerList.remove_if([this](Player const* pPlayer) -> bool
                    {
                        return this->me->GetExactDist2d(pPlayer) < 18.0f;
                    });

                    if(!playerList.empty())
                    {
                        if(Player *pTarget = Trinity::Containers::SelectRandomContainerElement(playerList))
                            uiRecklessChargeTargetGUID = pTarget->GetGUID();
                    }

                    events.ScheduleEvent(EVENT_RECKLESS_CHARGE, 5 * IN_MILLISECONDS);
                    break;
                }

                case EVENT_RECKLESS_CHARGE:
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                    Talk(RAND<uint8>(SAY_KAZ_RECKLESS_CHARGE_1, SAY_KAZ_RECKLESS_CHARGE_2));
                    DoCast(me, SPELL_RECKLESS_CHARGE); // Launch everything
                    // Summon npcs for the visual of Reckless Charge while travelling ?
                    // Handle next part in MovementInform.
                    break;

                case EVENT_DARK_POWER:
                    DoCastAOE(SPELL_DARK_POWER);
                    ++uiDarkPowerCount;
                    events.ScheduleEvent(EVENT_DARK_POWER, 1 * IN_MILLISECONDS);
                    break;
                    
                case EVENT_INCREASE_POWER:
                    me->ModifyPower(POWER_ENERGY, 3);
                    if(me->GetPower(POWER_ENERGY) < 100)
                        events.ScheduleEvent(EVENT_INCREASE_POWER, GetPowerTimer());
                    else
                        DoAction(ACTION_DARK_POWER);
                    break;

                default:
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }

        void MovementInform(uint32 uiMotionType, uint32 uiMotionPointId)
        {
            switch(uiMotionType)
            {
            case EFFECT_MOTION_TYPE:
                if(uiMotionPointId == POINT_RECKLESS_CHARGE_LAND)
                {
                    float fX = 0.0f, fY = 0.0f;
                    me->GetMotionMaster()->MovePoint(POINT_RECKLESS_CHARGE_PLAYER, fX, fY, me->GetPositionZ());
                }
                break;

            case POINT_MOTION_TYPE:
                if(uiMotionPointId == POINT_RECKLESS_CHARGE_PLAYER)
                {
                    me->RemoveAura(SPELL_RECKLESS_CHARGE);
                    DoCastAOE(SPELL_RECKLESS_CHARGE_SHATTER_GROUND);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);

                    if(me->HasAura(SPELL_POSSESSED))
                    {
                        Talk(SAY_KAZ_OVERLOAD_DISCHARGE);
                        if(IsHeroic())
                            DoCast(me, SPELL_DISCHARGE);
                        else
                            DoCast(me, SPELL_OVERLOAD);

                        events.ScheduleEvent(EVENT_RECKLESS_CHARGE_PRE_PATH, urand(23, 24) * IN_MILLISECONDS);
                    }
                    else
                        events.ScheduleEvent(EVENT_RECKLESS_CHARGE_PRE_PATH, urand(3, 4) * IN_MILLISECONDS);
                }
                break;

            default:
                break;
            }
        }

        // Override Damage Taken again to handle the Discharge aura.
        void DamageTaken(Unit *pAttacker, uint32 &ruiAmount)
        {
            if(!me->HasAura(SPELL_POSSESSED))
                return;

            if(me->HasAura(SPELL_POSSESSED))
            {
                if(me->HasAura(SPELL_DISCHARGE))
                    uiDamagesDoneInPastSecs += ruiAmount;
            }
            
            uiDamageTakenPossessed += ruiAmount;
            if((float)uiDamageTakenPossessed >= (float)((float)me->GetMaxHealth() * 0.25f))
            {
                // No remove when no other councillor alive
                if(IsACouncillorAlive())
                    DoCast(me, SPELL_LINGERING_PRESENCE);
                uiDamageTakenPossessed = 0; // Reset in both case to prevent chain call to IsACouncillorAlive
            }
        }

        // Override DoAction again to handle the Discharge Aura.
        void DoAction(int32 iAction)
        {
            switch(iAction)
            {
            case ACTION_RESET_DAMAGES:
                uiDamagesDoneInPastSecs = 0;
                break;

            default:
                CouncilBaseAI::DoAction(iAction);
                return;
            }
        }

        uint32 GetData(uint32 uiIndex) const
        {
            if(uiIndex == DATA_DAMAGES_PAST_SEC)
                return uiDamagesDoneInPastSecs;
            else if(uiIndex == DATA_DARK_POWER_COUNT)
                return uiDarkPowerCount;

            return 0;
        }

        uint64 GetGUID(int32 iIndex) const
        {
            if(iIndex == DATA_RECKLESS_CHARGE_TARGET_GUID)
                return uiRecklessChargeTargetGUID;

            return 0;
        }

    private:
        // Amount of damages received during past seconds in Heroic,
        // cause spell ticks each second, instead of being a permanent
        // dummy. Fuck blizzard's logic.
        uint32 uiDamagesDoneInPastSecs;
        uint64 uiRecklessChargeTargetGUID;
        void InitStandartEvents()
        {
            events.Reset();

            events.ScheduleEvent(EVENT_RECKLESS_CHARGE_PRE_PATH, urand(3, 4) * IN_MILLISECONDS);
        }

        void InitPossessedEvents()
        {
            events.Reset();

            events.ScheduleEvent(EVENT_RECKLESS_CHARGE_PRE_PATH, urand(3, 4) * IN_MILLISECONDS);
        }
    };

    CreatureAI *GetAI(Creature *pCreature) const
    {
        return GetThroneOfThunderAI<boss_kazrajin_AI, Creature>(pCreature);
    }
};


// Sul the Sandcrawler AI
class boss_sul_the_sandcrawler : public CreatureScript
{
public:
    boss_sul_the_sandcrawler() : CreatureScript("boss_sul_the_sandcrawler") { }

    class boss_sul_the_sandcrawler_AI : public CouncilBaseAI
    {
    public:
        boss_sul_the_sandcrawler_AI(Creature *pCreature) :
            CouncilBaseAI(pCreature)
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
        }

        void UpdateAI(uint32 uiDiff)
        {
            if(!UpdateVictim())
                return;

            events.Update(uiDiff);

            if(me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while(uint32 uiEventId = events.ExecuteEvent())
            {
                switch(uiEventId)
                {
                case EVENT_SAND_BOLT:
                    if(Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(pTarget, SPELL_SAND_BOLT); 
                    events.ScheduleEvent(EVENT_SAND_BOLT, urand(5, 15) * IN_MILLISECONDS);
                    break;

                case EVENT_QUICKSAND:
                {
                    Talk(SAY_SUL_QUICKSAND);
                    std::list<Player*> playerList;
                    me->GetPlayerListInGrid(playerList, 500.0f);

                    playerList.remove_if([this](Player const* pPlayer) -> bool
                    {
                        return this->me->GetExactDist2d(pPlayer) < 15.0f; // Remove players that are closer than 15 yards
                    });

                    // Pick one of the players in the list if not empty
                    if(!playerList.empty())
                    {
                        if(Player *pPlayer = Trinity::Containers::SelectRandomContainerElement<std::list<Player*>>(playerList))
                            me->SummonCreature(NPC_QUICKSAND_STALKER, *pPlayer);
                    }

                    events.ScheduleEvent(EVENT_QUICKSAND, urand(20, 35) * IN_MILLISECONDS);
                    break;
                }

                case EVENT_SANDSTORM:
                    Talk(SAY_SUL_SAND_STORM);
                    DoCastAOE(SPELL_SAND_STORM);
                    events.ScheduleEvent(EVENT_SANDSTORM, 40 * IN_MILLISECONDS);
                    break;

                case EVENT_DARK_POWER:
                    DoCastAOE(SPELL_DARK_POWER);
                    ++uiDarkPowerCount;
                    events.ScheduleEvent(EVENT_DARK_POWER, 1 * IN_MILLISECONDS);
                    break;
                    
                case EVENT_INCREASE_POWER:
                    me->ModifyPower(POWER_ENERGY, 3);
                    if(me->GetPower(POWER_ENERGY) < 100)
                        events.ScheduleEvent(EVENT_INCREASE_POWER, GetPowerTimer());
                    else
                        DoAction(ACTION_DARK_POWER);
                    break;

                default:
                    break;
                }
            }
        }

    private:
        void InitStandartEvents()
        {
            events.Reset();

            events.ScheduleEvent(EVENT_SAND_BOLT, 5 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_QUICKSAND, 10 * IN_MILLISECONDS);
        }

        void InitPossessedEvents()
        {
            events.Reset();

            events.ScheduleEvent(EVENT_SAND_BOLT, 5 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_SANDSTORM, 40 * IN_MILLISECONDS);
        }
    };

    CreatureAI *GetAI(Creature *pCreature) const
    {
        return GetThroneOfThunderAI<boss_sul_the_sandcrawler_AI, Creature>(pCreature);
    }
};


// High Priestess Mar'li
class boss_high_priestess_marli : public CreatureScript
{
public:
    boss_high_priestess_marli() : CreatureScript("boss_high_priestess_marli") { }

    class boss_high_priestess_marli_AI : public CouncilBaseAI
    {
    public:
        boss_high_priestess_marli_AI(Creature *pCreature) :
            CouncilBaseAI(pCreature)
        {

        }

        // Override Reset() to clean the lists
        void Reset()
        {
            uiShadowedSpiritPlayerGUIDs.clear();
            uiBlessedLoaSpiritBossGUIDs.clear();

            CouncilBaseAI::Reset();
        }

        void UpdateAI(uint32 uiDiff)
        {
            if(!UpdateVictim())
                return;

            events.Update(uiDiff);

            if(me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while(uint32 uiEventId = events.ExecuteEvent())
            {
                switch(uiEventId)
                {
                case EVENT_WRATH_OF_THE_LOA:
                    if(Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM)) // Target is TARGET_UNIT_ENEMY
                        DoCast(pTarget, SPELL_WRATH_OF_THE_LOA);
                    events.ScheduleEvent(EVENT_WRATH_OF_THE_LOA, urand(4, 8) * IN_MILLISECONDS);
                    break;

                case EVENT_BLESSED_LOA_SPIRIT:
                    // Check that we are not the only left councillor (otherwise it would be cheaty)
                    for(uint8 i = 0; i < 3; ++i)
                    {
                       /* if(Creature *pCouncillor = GetBossByEntry(uiBossEntries[i], me->))
                        {
                            if(pCouncillor->IsAlive())
                            {
                                // Select a target now
                                std::list<Creature*> councillors = { GetFrostKingMalakk(me), GetKazrajin(me), GetSulTheSandcrawler(me) };
                                councillors.remove_if([](Creature const* pCouncil) -> bool { return pCouncil->isDead(); });
                                councillors.sort([](Creature const* first, Creature const* second) -> bool { return first->GetHealthPct() < second->GetHealthPct() ;});

                                if(councillors.front())
                                    uiBlessedLoaSpiritBossGUIDs.push_back(councillors.front()->GetGUID().GetEntry());

                                // Cast after having init the list to be sure the guid has been set
                                DoCast(me, SPELL_BLESSED_LOA_SPIRIT);
                                events.ScheduleEvent(EVENT_BLESSED_LOA_SPIRIT, urand(20, 35) * IN_MILLISECONDS);


                                // Get out of the loop and break again; this way, we do not schedule
                                // the event if there is no other boss than Mar'li alive.
                                break;
                            }
                        }*/
                    }
                    break;

                case EVENT_WRATH_OF_THE_LOA_DARK:
                    if(Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                        DoCast(pTarget, SPELL_WRATH_OF_THE_LOA_DARK); // Target is TARGET_UNIT_ENEMY
                    events.ScheduleEvent(EVENT_WRATH_OF_THE_LOA_DARK, urand(3, 6) * IN_MILLISECONDS);
                    break;

                case EVENT_SHADOWED_LOA_SPIRIT:
                {
                    Talk(RAND<uint8>(SAY_MARLI_SHADOWED_LOA_SPIRIT_1, SAY_MARLI_SHADOWED_LOA_SPIRIT_2, SAY_MARLI_SHADOWED_LOA_SPIRIT_3));
                    std::list<Player*> playerList;
                    me->GetPlayerListInGrid(playerList, 500.0f);

                    // Remove too close targets (otherwise player would be instantly killed)
                    playerList.remove_if([this](Player const* pPlayer) -> bool
                    {
                        // Instakill triggers when spirit is 6 yards away from player or less
                        // so remove players in a 10 yards range to let the other some time
                        // to try to get to safety.
                        return this->me->GetExactDist2d(pPlayer) <= 10.0f;
                    });

                    // List is empty, reschedule event, and break
                    if(playerList.empty())
                    {
                        events.ScheduleEvent(EVENT_SHADOWED_LOA_SPIRIT, urand(15, 25) * IN_MILLISECONDS);
                        break;
                    }
                    else
                    {
                        // Instead of computing again the player list, we'll send the
                        // guid of a randomly chosen target in the playerList to the
                        // summoned creature.
                        if(Player *pPlayer = Trinity::Containers::SelectRandomContainerElement(playerList))
                            uiShadowedSpiritPlayerGUIDs.push_back(pPlayer->GetGUID().GetEntry());

                        DoCast(me, SPELL_SHADOWED_LOA_SPIRIT);
                        events.ScheduleEvent(EVENT_SHADOWED_LOA_SPIRIT, urand(15, 25) * IN_MILLISECONDS);
                    }
                    break;
                }

                case EVENT_TWISTED_FATE:
                    DoCastAOE(SPELL_TWISTED_FATE); // Automatically handle target selection in the SpellScript
                    events.ScheduleEvent(EVENT_TWISTED_FATE, urand(10, 20) * IN_MILLISECONDS);
                    break;

                case EVENT_DARK_POWER:
                    DoCastAOE(SPELL_DARK_POWER);
                    ++uiDarkPowerCount;
                    events.ScheduleEvent(EVENT_DARK_POWER, 1 * IN_MILLISECONDS);
                    break;
                    
                case EVENT_INCREASE_POWER:
                    me->ModifyPower(POWER_ENERGY, 3);
                    if(me->GetPower(POWER_ENERGY) < 100)
                        events.ScheduleEvent(EVENT_INCREASE_POWER, GetPowerTimer());
                    else
                        DoAction(ACTION_DARK_POWER);
                    break;

                default:
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }

        // Override function to return the GUIDs of the targets for the Loa Spirits.
        uint64 GetGUID(int32 iIndex) const
        {
            switch(iIndex)
            {
            case DATA_BLESSED_LOA_SPIRIT_TARGET_GUID:
                if(uiBlessedLoaSpiritBossGUIDs.empty())
                    return 0;
                else
                    return uiBlessedLoaSpiritBossGUIDs.back();
                break;

            case DATA_SHADOWED_LOA_SPIRIT_TARGET_GUID:
                if(uiShadowedSpiritPlayerGUIDs.empty())
                    return 0;
                else
                    return uiShadowedSpiritPlayerGUIDs.back();
                break;

            default:
                return 0;
            }
        }

        // Override JustDied() handler to clean the lists (it would use memory for nothing)
        void JustDied(Unit *pKiller)
        {
            uiShadowedSpiritPlayerGUIDs.clear();
            uiBlessedLoaSpiritBossGUIDs.clear();

            CouncilBaseAI::JustDied(pKiller);
        }

    private:
        // GUIDs of the players that will be chased by a Shadowed Loa Spirit
        // Always select the last in the list when a Shadowed Loa Spirit
        // is summoned.
        std::list<uint64> uiShadowedSpiritPlayerGUIDs;

        // GUIDS of the boss that will be chased by a Blessed Loa Spirit.
        // Like above, select the last in the list when a Blessed Loa Spirit
        // is summoned.
        std::list<uint64> uiBlessedLoaSpiritBossGUIDs;

        void InitStandartEvents()
        {
            events.Reset();

            events.ScheduleEvent(EVENT_WRATH_OF_THE_LOA, 5 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_BLESSED_LOA_SPIRIT, 25 * IN_MILLISECONDS);
        }

        void InitPossessedEvents()
        {
            events.Reset();

            events.ScheduleEvent(EVENT_WRATH_OF_THE_LOA_DARK, 5 * IN_MILLISECONDS);
            if(IsHeroic())
                events.ScheduleEvent(EVENT_TWISTED_FATE, 25 * IN_MILLISECONDS);
            else
                events.ScheduleEvent(EVENT_SHADOWED_LOA_SPIRIT, 20 * IN_MILLISECONDS);
        }
    };

    CreatureAI *GetAI(Creature *pCreature) const
    {
        return GetThroneOfThunderAI<boss_high_priestess_marli_AI, Creature>(pCreature);
    }
};


// Garajal
class mob_garajal : public CreatureScript
{
public:
    mob_garajal() : CreatureScript("mob_garajal") { }
    
    class mob_garajal_AI : public ScriptedAI
    {
    public:
        mob_garajal_AI(Creature *pCreature) : 
            ScriptedAI(pCreature), pInstance(pCreature->GetInstanceScript())
        {
            events.Reset();
        }
        
        void Reset()
        {
            me->SetVisible(true);
            DoCast(me, SPELL_GARAJAL_GHOST);
            events.Reset();
        }
        
        void DoAction(int32 iAction)
        {
            switch(iAction)
            {
            case ACTION_ENTER_COMBAT:
                Talk(SAY_GARAJAL_INTRO);
                events.ScheduleEvent(EVENT_SUMMON_SOUL, 3 * IN_MILLISECONDS);
                break;
                
            default:
                break;
            }
        }
        
        void UpdateAI(uint32 uiDiff)
        {
            if(events.Empty())
                return;
                
            events.Update(uiDiff);
            
            while(uint32 uiEventId = events.ExecuteEvent())
            {
                switch(uiEventId)
                {
                case EVENT_SUMMON_SOUL:
                    me->SetVisible(false);
                    if(Creature *pSoul = me->SummonCreature(MOB_GARA_JALS_SOUL, *me))
                    {
                        pSoul->AI()->DoAction(ACTION_ENTER_COMBAT);
                        pInstance->SetData64(MOB_GARA_JALS_SOUL, pSoul->GetGUID().GetEntry());
                    }
                    break;
                    
                default:
                    break;
                }
            }
        }
    private:
        EventMap        events;
        InstanceScript  *pInstance;
    };
    
    CreatureAI *GetAI(Creature *pCreature) const
    {
        return GetThroneOfThunderAI<mob_garajal_AI, Creature>(pCreature);
    }
};


// Garajal's Soul
class mob_garajals_soul : public CreatureScript
{
public:
    mob_garajals_soul() : CreatureScript("mob_garajals_soul") { }

    class mob_garajals_soul_AI : public ScriptedAI
    {
    public:
        mob_garajals_soul_AI(Creature *pCreature) :
            ScriptedAI(pCreature), pInstance(pCreature->GetInstanceScript()), uiCouncillorEntry(0)
        {

        }
        
        void Reset()
        {
            DoCast(me, SPELL_GARA_JALS_SOUL);
        }
        
        void EnterEvadeMode() 
        {
            uiCouncillorEntry = 0; // Reset councillor entry to prevent bug
            me->GetMotionMaster()->MovementExpired(); // Reset movement so we will not continue to follow a councillor
            ScriptedAI::EnterEvadeMode();
        }

        void DoAction(int32 iAction)
        {
            switch(iAction)
            {
            case ACTION_ENTER_COMBAT:
                // Always possess Malakk first
                if(Creature *pMalakk = GetFrostKingMalakk(me))
                {
                    uiCouncillorEntry = pMalakk->GetEntry();
                    me->GetMotionMaster()->MoveFollow(pMalakk, 0.0f, 0.0f);
                }
                break;

            case ACTION_EXIT_COUNCILLOR:
                // Set Garajal visible again
                me->SetVisible(true);
                
                // DoAction may be called after EnterEvadeMode() because possessed boss can reset 
                // after the call. Return to prevent following a new councillor.
                if(!uiCouncillorEntry || CheckBossState())
                    return;

                // In Heroic, each time Garajal is forced out of a councillor, he leaves
                // a Soul Fragment behind. (In fact there is no npc summoned, just a spell
                // cast).
                if(IsHeroic())
                    DoCastAOE(SPELL_SOUL_FRAGMENT_SELECTOR);

                // Select a new councillor
                if(Creature *pNextCouncillor = GetNextCouncillor())
                {                        
                    uiCouncillorEntry = pNextCouncillor->GetEntry();
                    me->GetMotionMaster()->MovementExpired(); // Reset movement to prevent fail
                    me->GetMotionMaster()->MoveFollow(pNextCouncillor, 0.0f, 0.0f);
                }
                break;

            default:
                break;
            }
        }
        
        void UpdateAI(uint32 uiDiff)
        {
            if(!me->IsVisible())
                return;
                    
            if(Creature *pCouncillor = GetBossByEntry(uiCouncillorEntry, me))
            {
                if(me->GetExactDist2d(pCouncillor) <= 5.0f)
                {
                    DoCast(pCouncillor, SPELL_POSSESSED);
                    me->SetVisible(false);
                }
            }
        }
        
        bool CheckBossState()
        {
            std::array<Creature*, 4> aCouncillors = { GetFrostKingMalakk(me), GetKazrajin(me), GetSulTheSandcrawler(me), GetHighPriestessMarli(me) };
            for(auto pCouncillor: aCouncillors)
            {
                if(!pCouncillor->IsInCombat() || pCouncillor->IsInEvadeMode())
                    return true;
            }
            
            return false;
        }

    private:
        uint32          uiCouncillorEntry;
        InstanceScript  *pInstance;

        // Helper function to find the next boss to possess
        Creature *GetNextCouncillor(uint32 uiOriginalEntry = 0)
        {
            // If original entry == councillor entry, then we looped without finding anybody, so stay in
            if(uiOriginalEntry == uiCouncillorEntry)
                return NULL;

            // This is the first call, init original entry with the current councillor entry
            if(!uiOriginalEntry)
                uiOriginalEntry = uiCouncillorEntry;

            // Pointer to the function returning the next possible councillor
            Accessor    pfCurrent = NULL;
            // Entry of the next possible councillor
            uint32      uiNextEntry = 0;
            switch(uiCouncillorEntry)
            {
            case BOSS_COUNCIL_FROST_KING_MALAKK:
                pfCurrent = &GetKazrajin;
                uiNextEntry = BOSS_COUNCIL_KAZRAJIN;
                break;

            case BOSS_COUNCIL_KAZRAJIN:
                pfCurrent = &GetSulTheSandcrawler;
                uiNextEntry = BOSS_COUNCIL_SUL_THE_SANDCRAWLER;
                break;

            case BOSS_COUNCIL_SUL_THE_SANDCRAWLER:
                pfCurrent = &GetHighPriestessMarli;
                uiNextEntry = BOSS_COUNCIL_HIGH_PRIESTESS_MARLI;
                break;

            case BOSS_COUNCIL_HIGH_PRIESTESS_MARLI:
                pfCurrent = &GetFrostKingMalakk;
                uiNextEntry = BOSS_COUNCIL_FROST_KING_MALAKK;
                break;

            default:
                return NULL;
            }

            if(pfCurrent(me) && pfCurrent(me)->IsAlive())
            {
                return pfCurrent(me);
            }
            else
            {
                uiCouncillorEntry = uiNextEntry;
                return GetNextCouncillor(uiOriginalEntry);
            }
        }
    };
    
    CreatureAI *GetAI(Creature *pCreature) const
    {
        return GetThroneOfThunderAI<mob_garajals_soul_AI, Creature>(pCreature);
    }
};


// Quicksand stalker AI
class mob_quicksand_stalker : public CreatureScript
{
public:
    mob_quicksand_stalker() : CreatureScript("mob_quicksand_stalker") { }

    class mob_quicksand_stalker_AI : public ScriptedAI
    {
    public:
        mob_quicksand_stalker_AI(Creature *pCreature) :
            ScriptedAI(pCreature), pInstance(pCreature->GetInstanceScript()), uiMergeCount(0)
        {
            events.Reset();
            me->SetReactState(REACT_PASSIVE);
        }

        void IsSummonedBy(Unit *pSummoner)
        {
            DoCast(me, SPELL_QUICKSAND_AT_VISUAL);
            if(IsHeroic())
            {
                if(me->FindNearestCreature(NPC_QUICKSAND_STALKER, 7.0f) == pSummoner) // Check 7.0f, because uiMergeCount has not been set yet
                {
                    // Schedule time must be less than quicksand periodic event timer,
                    // otherwise we could root player before merging... quite annoying.
                    events.ScheduleEvent(EVENT_TRY_MERGE, 300);
                }
                else
                {
                    // Try to merge first
                    Merge();
                }
            }
            events.ScheduleEvent(EVENT_QUICKSAND_PERIODIC, 500);
        }

        void DoAction(int32 iAction)
        {
            switch(iAction)
            {
            case ACTION_CREATE_LIVING_SAND:
                if(Creature *pLivingSand = me->SummonCreature(MOB_LIVING_SAND, *me))
                    pLivingSand->SetInCombatWithZone();
                break;
                
            default:
                break;
            }
        }

        void UpdateAI(uint32 uiDiff)
        {
            events.Update(uiDiff);

            while(uint32 uiEventId = events.ExecuteEvent())
            {
                switch(uiEventId)
                {
                case EVENT_QUICKSAND_PERIODIC:
                {
                    std::list<Player*> playerList;
                    me->GetPlayerListInGrid(playerList, 7.0f + 7.0f * uiMergeCount);

                    for(Player *pPlayer: playerList)
                    {
                        if(!pPlayer->HasAura(SPELL_QUICKSAND_PERIODIC_DAMAGES, me->GetGUID())) // Caster is relevant here I think cause aura cannot stack
                            DoCast(pPlayer, SPELL_QUICKSAND_PERIODIC_DAMAGES); // Handle the root and cie in the AuraScript
                    }

                    events.ScheduleEvent(EVENT_QUICKSAND_PERIODIC, 500);
                    break;
                }

                case EVENT_TRY_MERGE:
                    Merge();
                    break;

                default:
                    break;
                }
            }
        }

        uint32 GetData(uint32 uiIndex) const
        {
            if(uiIndex == DATA_QUICKSAND_MERGE_COUNT)
                return uiMergeCount;

            return 0;
        }

    private:
        EventMap        events;
        InstanceScript  *pInstance;

        uint32          uiMergeCount;

        // Helper function to merge the Quicksands in Heroic
        void Merge()
        {
            /* In Heroic mode, when two Quicksands are overlaping (the distance between
             * the two stalkers is lower than 7 yards), they merge, resulting in a big
             * Quicksand appearing. I don't know the formula Blizzard used to do this,
             * and I never saw it appear on a video, so I will handle it this way :
             *
             * The summoning position is the middle between the two stalkers. We will summon
             * a stalker and set it's uiMergeCount to the sum of the uiMergeCount of the two
             * merging Quicksands. Then, we will increase it's scale by this number.
             *
             * Exemple: we have a Quicksand A with uiMergeCount = 1 (meaning it merged only once)
             * and this (the this pointer, so this class) one is created let's sat 6 yards from
             * A stalker. We compute the middle position and summon a new Quicksand, we set it's
             * uiMergeCount to this->uiMergeCount (0) + A->uiMergeCount (1) + 1. And then we
             * update the scale.
             *
             * Note: we will not handle multi merging. It would be too complicated, so we will
             * merge with the closest quicksand.
             */

            Creature *pClosestQuicksand = me->FindNearestCreature(NPC_QUICKSAND_STALKER, 7.0f + 7.0f * uiMergeCount); // Use uiMergeCount to compute correct radius

            if(pClosestQuicksand)
            {
                float fMiddleX = (me->GetPositionX() + pClosestQuicksand->GetPositionX()) / 2.0f;
                float fMiddleY = (me->GetPositionY() + pClosestQuicksand->GetPositionY()) / 2.0f;
                float fZ = me->GetPositionZ();

                if(Creature *pNewQuicksand = me->SummonCreature(NPC_QUICKSAND_STALKER, fMiddleX, fMiddleY, fZ))
                {
                    if(mob_quicksand_stalker_AI* pNewQuicksandAI = dynamic_cast<mob_quicksand_stalker_AI*>(pNewQuicksand->AI()))
                    {
                        // We are manipulating an object of the same type, it allows access to the private scope
                        pNewQuicksandAI->uiMergeCount = uiMergeCount + 1;
                        pNewQuicksand->SetObjectScale(pNewQuicksand->GetObjectScale() * pNewQuicksandAI->uiMergeCount);

                        // Remove self and other
                        pClosestQuicksand->DisappearAndDie();
                        me->DisappearAndDie();
                    }
                }
            }
        }
    };

    CreatureAI *GetAI(Creature *pCreature) const
    {
        return GetThroneOfThunderAI<mob_quicksand_stalker_AI, Creature>(pCreature);
    }
};


// Living Sand AI
class mob_living_sand : public CreatureScript
{
public:
    mob_living_sand() : CreatureScript("mob_living_sand") { }

    class mob_living_sand_AI : public ScriptedAI
    {
    public:
        mob_living_sand_AI(Creature *pCreature) :
            ScriptedAI(pCreature), pInstance(pCreature->GetInstanceScript())
        {
        }

        void DoAction(int32 iAction)
        {
            switch(iAction)
            {
            case ACTION_FORTIFY:
                DoCast(me, SPELL_FORTIFIED);
                break;

            default:
                break;
            }
        }

        void JustDied(Unit *pKiller)
        {
            me->SummonCreature(NPC_QUICKSAND_STALKER, *me);
        }

    private:
        InstanceScript  *pInstance;
    };

    CreatureAI *GetAI(Creature *pCreature) const
    {
        return GetThroneOfThunderAI<mob_living_sand_AI, Creature>(pCreature);
    }
};


// Blessed Loa Spirit
class mob_blessed_loa_spirit : public CreatureScript
{
public:
    mob_blessed_loa_spirit() : CreatureScript("mob_blessed_loa_spirit") { }

    class mob_blessed_loa_spirit_AI : public ScriptedAI
    {
    public:
        mob_blessed_loa_spirit_AI(Creature *pCreature) :
            ScriptedAI(pCreature), pInstance(pCreature->GetInstanceScript()), uiTargetGuid(0)
        {
            me->SetReactState(REACT_PASSIVE);
            events.Reset();
        }
        
        void Reset()
        {
            DoCast(me, SPELL_BLESSED_TRANSFORMATION);
        }

        // Override function to be sure there won't be any call to MoveChase (at least in AttackStart)
        void AttackStart(Unit *pTarget) { }

        void IsSummonedBy(Unit *pSummoner)
        {
            if(pSummoner && pSummoner->GetAI())
            {
                uiTargetGuid = pSummoner->GetAI()->GetGUID(DATA_BLESSED_LOA_SPIRIT_TARGET_GUID);
                if(Creature *pCouncillor = ObjectAccessor::GetCreature(*me, GetGUID(uiTargetGuid)))
                    me->GetMotionMaster()->MovePoint(POINT_BLESSED_LOA_SPIRIT_COUNCILLOR, *pCouncillor);

                events.ScheduleEvent(EVENT_BLESSED_GIFT, 20 * IN_MILLISECONDS);
            }
        }

        void UpdateAI(uint32 uiDiff)
        {
//            if(me->GetMotionMaster()->GetCurrentMovementGeneratorType() != POINT_MOTION_TYPE && me->GetMotionMaster()->GetCurrentMovementGeneratorType() != EFFECT_MOTION_TYPE)
//            {
//                /* If movement generator is not POINT_MOTION_TYPE, it might be CHASE_MOTION_TYPE
//                 * Reset the threat list, and reset the Motion Master (since CHASE_MOTION_TYPE
//                 * and POINT_MOTION_TYPE share the same slot, overriding one with another will
//                 * result in an immediate change.
//                 */
//                me->getThreatManager().clearReferences();
//                me->GetMotionMaster()->MovementExpired();
//                if(Creature *pCouncillor = ObjectAccessor::GetCreature(*me, uiTargetGuid))
//                    me->GetMotionMaster()->MovePoint(POINT_BLESSED_LOA_SPIRIT_COUNCILLOR, *pCouncillor);
//            }

            events.Update(uiDiff);

            while(uint32 uiEventId = events.ExecuteEvent())
            {
                switch(uiEventId)
                {
                case EVENT_BLESSED_GIFT:
                    if(Creature *pCouncillor = ObjectAccessor::GetCreature(*me, GetGUID(uiTargetGuid)))
                    {
                        DoCast(me, SPELL_BLESSED_TIME_OUT);
                        me->GetMotionMaster()->MovementExpired();
                        me->GetMotionMaster()->MoveJump(*pCouncillor, 42.0f, 42.0f, EVENT_JUMP);
                    }
                    break;

                default:
                    break;
                }
            }
        }

        void MovementInform(uint32 uiMotionType, uint32 uiMotionPointId)
        {
            switch(uiMotionType)
            {
            case POINT_MOTION_TYPE:
                if(uiMotionPointId == POINT_BLESSED_LOA_SPIRIT_COUNCILLOR)
                {
                    if(Creature *pCouncillor = ObjectAccessor::GetCreature(*me, GetGUID(uiTargetGuid)))
                    {
                        if(me->GetExactDist2d(pCouncillor) <= 3.0f)
                        {
                            DoCast(pCouncillor, SPELL_BLESSED_GIFT);
                            me->DisappearAndDie();
                        }
                        else
                            me->GetMotionMaster()->MovePoint(POINT_BLESSED_LOA_SPIRIT_COUNCILLOR, *pCouncillor);
                    }
                }
                break;

            case EFFECT_MOTION_TYPE:
                if(uiMotionPointId == EVENT_JUMP)
                {
                    if(Creature *pCouncillor = ObjectAccessor::GetCreature(*me, GetGUID(uiTargetGuid)))
                    {
                        DoCast(pCouncillor, SPELL_BLESSED_GIFT);
                        me->DisappearAndDie();
                    }
                }
                break;

            default:
                break;
            }
        }

    private:
        EventMap        events;
        InstanceScript  *pInstance;
        uint64          uiTargetGuid; // GUID of the councillor we are moving toward
    };

    CreatureAI *GetAI(Creature *pCreature) const
    {
        return GetThroneOfThunderAI<mob_blessed_loa_spirit_AI, Creature>(pCreature);
    }
};


// Shadowed Loa Spirit AI
class mob_shadowed_loa_spirit : public CreatureScript
{
public:
    mob_shadowed_loa_spirit() : CreatureScript("mob_shadowed_loa_spirit") { }

    class mob_shadowed_loa_spirit_AI : public ScriptedAI
    {
    public:
        mob_shadowed_loa_spirit_AI(Creature *pCreature) :
            ScriptedAI(pCreature), pInstance(pCreature->GetInstanceScript()), uiTargetGuid(0)
        {
            me->SetReactState(REACT_PASSIVE);
            events.Reset();
        }
        
        void Reset()
        {
            DoCast(me, SPELL_SHADOWED_TRANSFORMATION);
        }

        void IsSummonedBy(Unit *pSummoner)
        {
            if(pSummoner && pSummoner->GetAI())
            {
                uiTargetGuid = pSummoner->GetAI()->GetGUID(DATA_SHADOWED_LOA_SPIRIT_TARGET_GUID);
                if(Player *pPlayer = ObjectAccessor::GetPlayer(*me, GetGUID(uiTargetGuid)))
                {
                    me->GetMotionMaster()->MoveFollow(pPlayer, 0.0f, 0.0f);
                    DoCast(pPlayer, SPELL_MARKED_SOUL);
                }

                events.ScheduleEvent(EVENT_SHADOWED_GIFT, 20 * IN_MILLISECONDS);
            }
        }

        void UpdateAI(uint32 uiDiff)
        {
            Player *pPlayer = ObjectAccessor::GetPlayer(*me, GetGUID(uiTargetGuid));
            if(pPlayer && me->GetExactDist2d(pPlayer) <= 6.0f)
            {
                DoCast(pPlayer, SPELL_SHADOWED_GIFT);
                me->DisappearAndDie();
            }

            events.Update(uiDiff);

            while(uint32 uiEventId = events.ExecuteEvent())
            {
                switch(uiEventId)
                {
                case EVENT_SHADOWED_GIFT:
                    if(Player *pPlayer = ObjectAccessor::GetPlayer(*me, GetGUID(uiTargetGuid)))
                    {
                        DoCast(me, SPELL_SHADOWED_TIME_OUT);
                        me->GetMotionMaster()->MoveJump(*pPlayer, 42.0f, 42.0f, EVENT_JUMP);
                    }
                    break;

                default:
                    break;
                }
            }
        }

        void MovementInform(uint32 uiMotionType, uint32 uiMotionPointId)
        {
            if(uiMotionType == EFFECT_MOTION_TYPE && uiMotionPointId == EVENT_JUMP)
            {
                if(Player *pPlayer = ObjectAccessor::GetPlayer(*me, GetGUID(uiTargetGuid)))
                {
                    DoCast(pPlayer, SPELL_SHADOWED_GIFT);
                    me->DisappearAndDie();
                }
            }
        }
        
        void JustDied(Unit *pKiller)
        {
            if(Player *pPlayer = ObjectAccessor::GetPlayer(*me, GetGUID(uiTargetGuid)))
                pPlayer->RemoveAurasDueToSpell(SPELL_MARKED_SOUL);
        }

    private:
        EventMap        events;
        InstanceScript  *pInstance;
        uint64          uiTargetGuid;
    };

    CreatureAI *GetAI(Creature *pCreature) const
    {
        return GetThroneOfThunderAI<mob_shadowed_loa_spirit_AI, Creature>(pCreature);
    }
};


// Helper to handle Twisted Fate correctly
class mob_twisted_fate_helper : public CreatureScript
{
public:
    mob_twisted_fate_helper() : CreatureScript("mob_twisted_fate_helper") { }

    struct TwistedFate
    {
        uint64 uiFirstPlayerGuid; // Guid of the first player of the Twisted Fate
        uint64 uiSecondPlayerGuid; // Guid of the second player of the Twisted Fate

        uint64 uiFirstTwistedFateGuid; // Guid of the first Twisted Fate
        uint64 uiSecondTwistedFateGuid; // Guid of the second Twisted Fate

        TwistedFate(uint64 uiFirstPlayer, uint64 uiFirstNpc) :
            uiFirstPlayerGuid(0), uiFirstTwistedFateGuid(uiFirstNpc)
        {
            uiSecondPlayerGuid = uiSecondTwistedFateGuid = 0;
        }
    };

    class mob_twisted_fate_helper_AI : public ScriptedAI
    {
    public:
        mob_twisted_fate_helper_AI(Creature *pCreature) :
            ScriptedAI(pCreature), pInstance(pCreature->GetInstanceScript())
        {
            twistedFatesList.clear();
        }
    
        void Reset()
        {
            twistedFatesList.clear();
        }

        void AddTwistedFate(TwistedFate *pFate)
        {
            twistedFatesList.push_back(pFate);
        }

        // Link a player and a twisted fate (only used for the second mob)
        void Link(uint64 uiPlayerGuid, uint64 uiFateGuid)
        {
            if(twistedFatesList.empty())
                return;

            // Link the two twisted fates together == send the guid of the other to each one,
            // init them correctly, start their movement toward each other.
            if(TwistedFate* pFate = twistedFatesList.back())
            {
                pFate->uiSecondPlayerGuid = uiPlayerGuid;
                pFate->uiSecondTwistedFateGuid = uiFateGuid;

                Creature    *pFirst     = ObjectAccessor::GetCreature(*me, GetGUID(pFate->uiFirstTwistedFateGuid)),
                            *pSecond    = ObjectAccessor::GetCreature(*me, GetGUID(pFate->uiSecondTwistedFateGuid));

                if(!pFirst || !pSecond)
                    return;

                // If there are not enough players, remove the creatures
                if(pFate->uiSecondPlayerGuid == pFate->uiFirstPlayerGuid)
                {
                    pFirst->DisappearAndDie();
                    pSecond->DisappearAndDie();
                    return;
                }
                
                pFirst->SetFacingToObject(pSecond);
                // I don't know how they are supposed to behave, so I will just say they meet at the exact middle
                // of the two positions they represent.
                Position const middlePosition = { (pFirst->GetPositionX() + pSecond->GetPositionX()) / 2.0f,
                                                  (pFirst->GetPositionY() + pSecond->GetPositionY()) / 2.0f,
                                                  pFirst->GetPositionZ(), pFirst->GetOrientation() };

                // Send the guid of each to the other
                pFirst->AI()->SetGUID(pSecond->GetGUID(), DATA_TWISTED_FATE_GUID);
                pSecond->AI()->SetGUID(pFirst->GetGUID(), DATA_TWISTED_FATE_GUID);

                // Make them move
                pFirst->GetMotionMaster()->MovePoint(POINT_MIDDLE, middlePosition);
                pSecond->GetMotionMaster()->MovePoint(POINT_MIDDLE, middlePosition);

                // And make them cast their periodic
                pFirst->CastSpell(pFirst, SPELL_TWISTED_FATE_PERIODIC);
                pSecond->CastSpell(pSecond, SPELL_TWISTED_FATE_PERIODIC);
            }
        }

        // Delete a TwistedFate when first and second are dead
        void Unlink(uint64 uiGuid)
        {
            if(twistedFatesList.empty())
                return;

            for(TwistedFate *pFate : twistedFatesList)
            {
                if(pFate->uiFirstTwistedFateGuid == uiGuid || pFate->uiSecondTwistedFateGuid == uiGuid)
                {
                    delete pFate;
                    return;
                }
            }
        }

        void DoAction(int32 iAction)
        {
            switch(iAction)
            {
            // Fight ended, delete dynamically allocated memory
            case ACTION_TWISTED_FATE_END_FIGHT:
                for(auto i: twistedFatesList)
                    delete i;
                break;

            default:
                break;
            }
        }

    private:
        InstanceScript  *pInstance;

        std::list<TwistedFate*> twistedFatesList; // Store dynamically allocated twisted fate helpers
    };

    CreatureAI *GetAI(Creature *pCreature) const
    {
        return GetThroneOfThunderAI<mob_twisted_fate_helper_AI, Creature>(pCreature);
    }
};
typedef mob_twisted_fate_helper::mob_twisted_fate_helper_AI TwistedFateHelperAI;
typedef mob_twisted_fate_helper::TwistedFate TwistedFate_t;


// Twisted Fate AI
class mob_twisted_fate : public CreatureScript
{
public:
    mob_twisted_fate() : CreatureScript("mob_twisted_fate") { }

    class mob_twisted_fate_AI : public ScriptedAI
    {
    public:
        mob_twisted_fate_AI(Creature *pCreature):
            ScriptedAI(pCreature), pInstance(pCreature->GetInstanceScript())
        {
            me->SetReactState(REACT_PASSIVE);
        }

        // Add a new TwistedFate_t to the helper
        void IsSummonedBy(Unit *pSummoner)
        {
            Creature *pHelper = ObjectAccessor::GetCreature(*me, pInstance->GetObjectGuid(NPC_TWISTED_FATE_HELPER));
            if(!pHelper)
            {
                me->DisappearAndDie();
                return;
            }

            TwistedFateHelperAI *pHelperAI = dynamic_cast<TwistedFateHelperAI*>(pHelper->AI());
            if(!pHelperAI)
            {
                me->DisappearAndDie();
                return;
            }

            switch(me->GetEntry())
            {
            // Create a new TwistedFate_t
            case MOB_TWISTED_FATE_FIRST:
                pHelperAI->AddTwistedFate(new TwistedFate_t(pSummoner ? pSummoner->GetGUID() : 0, me->GetGUID()));
                DoCastAOE(SPELL_TWISTED_FATE_FORCE_SUMMON_SECOND); // Force the most distant player to summon the second twisted fate
                break;

            // Finalize it with the second npc and launch everything
            case MOB_TWISTED_FATE_SECOND:
                pHelperAI->Link(pSummoner ? pSummoner->GetGUID().GetEntry() : 0, me->GetGUID().GetEntry());
                break;
            }
        }

        void SetGUID(uint64 uiGuid, int32 uiIndex)
        {
            if(uiIndex == DATA_TWISTED_FATE_GUID)
                uiOtherTwistedFateGuid = uiGuid;
        }

        void JustDied(Unit *pKiller)
        {
            // Do not do something wierd when the other is dead => free memory
            // of the helper.
            if(bOtherTwistedFateDied)
            {
                if(Creature *pHelper = ObjectAccessor::GetCreature(*me, pInstance->GetObjectGuid(NPC_TWISTED_FATE_HELPER)))
                {
                    if(TwistedFateHelperAI *pHelperAI = dynamic_cast<TwistedFateHelperAI*>(pHelper->AI()))
                        pHelperAI->Unlink(me->GetGUID().GetEntry());
                }
            }
            else
            {
                // When a Twisted Fate dies, the other stops and then begins to cast an AOE every 3 seconds
                if(Creature *pOther = ObjectAccessor::GetCreature(*me, GetGUID(uiOtherTwistedFateGuid)))
                    pOther->AI()->DoAction(ACTION_OTHER_TWISTED_FATE_DIED);
            }

        }

        uint32 GetData(uint32 uiIndex) const
        {
            if(uiIndex == DATA_TWISTED_FATE_OTHER_DIED)
                return (uint32)bOtherTwistedFateDied;

            return 0;
        }

        void DoAction(int32 iAction)
        {
            switch(iAction)
            {
            // Stop moving and set bOtherTwistedFateDied to true so the aura script will be able
            // to compute the amount of damages correctly.
            case ACTION_OTHER_TWISTED_FATE_DIED:
                me->StopMoving();
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                bOtherTwistedFateDied = true;
                break;

            default:
                break;
            }
        }

    protected:
        InstanceScript  *pInstance;
        uint64          uiOtherTwistedFateGuid; // Guid of the other twisted fate

        // Boolean to control whenever we are in the linked phase or not,
        // and used to compute correctly the amount of damages of the
        // SPELL_TWISTED_FATE_DAMAGES.
        bool            bOtherTwistedFateDied;
    };

    CreatureAI *GetAI(Creature *pCreature) const
    {
        return GetThroneOfThunderAI<mob_twisted_fate_AI, Creature>(pCreature);
    }
};


//=========================================================
// Spell Scripts


// Possessed
class spell_garajal_possessed : public SpellScriptLoader
{
public:
    spell_garajal_possessed() : SpellScriptLoader("spell_garajal_possessed") { }
    
    class spell_garajal_possessed_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_garajal_possessed_AuraScript);
        
        void HandleApply(AuraEffect const* pAuraEffect, AuraEffectHandleModes eMode)
        {
            if(GetOwner() && GetOwner()->ToCreature())
            {
                Creature *pOwner = GetOwner()->ToCreature();
                pOwner->AI()->DoAction(ACTION_SET_POSSESSED);
            }
        }
        
        void HandleRemove(AuraEffect const* pAuraEffect, AuraEffectHandleModes eMode)
        {
            if(GetOwner())
            {
                if(Creature *pGarajal = GetGarajalsSoul(GetOwner()))
                    pGarajal->AI()->DoAction(ACTION_EXIT_COUNCILLOR);
                    
                if(GetOwner()->ToCreature())
                    GetOwner()->ToCreature()->AI()->DoAction(ACTION_SET_UNPOSSESSED);
            }
        }
        
        /*void HandlePeriodic(AuraEffect const* pAuraEffect)
        {
            if(!GetOwner())
                return;
                
            if(Creature *pOwner = GetOwner()->ToCreature())
            {
                if(pOwner->GetPower(POWER_ENERGY) < 100)
                    pOwner->ModifyPower(POWER_ENERGY, 1);
                    
                if(pOwner->GetPower(POWER_ENERGY) == 100)
                    pOwner->AI()->DoAction(ACTION_DARK_POWER);
            }
        }*/
        
        void Register()
        {
            OnEffectApply       += AuraEffectApplyFn(spell_garajal_possessed_AuraScript::HandleApply, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove      += AuraEffectRemoveFn(spell_garajal_possessed_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
            // OnEffectPeriodic    += AuraEffectPeriodicFn(spell_garajal_possessed_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };
    
    AuraScript *GetAuraScript() const
    {
        return new spell_garajal_possessed_AuraScript();
    }
};


// Frigid Assault
class spell_malakk_frigid_assault : public SpellScriptLoader
{
public:
    spell_malakk_frigid_assault() : SpellScriptLoader("spell_malakk_frigid_assault") { }

    class spell_malakk_frigid_assault_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_malakk_frigid_assault_AuraScript);

        void HandleEffectApply(AuraEffect const* pAuraEffect, AuraEffectHandleModes eMode)
        {
            Player *pOwner;
            if(GetOwner() && GetOwner()->ToPlayer())
            {
                pOwner = GetOwner()->ToPlayer();
                // Stun when stacks reach 15
                if(GetStackAmount() == 15)
                {
                    pOwner->CastSpell(pOwner, SPELL_FRIGID_ASSAULT_STUN, true);
                    Remove(AURA_REMOVE_BY_DEFAULT);
                }
            }
        }

        void Register()
        {
            // BTW: Periodic dummy choice was quite surprising...
            // Note: better to use AfterEffectApply, cause stack amount is not yet set to 15 when OnEffectApply is called
            AfterEffectApply += AuraEffectApplyFn(spell_malakk_frigid_assault_AuraScript::HandleEffectApply, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK); // Indeed, it should be AfterEffectReapply
        }
    };

    AuraScript *GetAuraScript() const
    {
        return new spell_malakk_frigid_assault_AuraScript();
    }
};


// Biting Cold
class spell_malakk_biting_cold : public SpellScriptLoader
{
public:
    spell_malakk_biting_cold() : SpellScriptLoader("spell_malakk_biting_cold") { }

    class spell_malakk_biting_cold_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_malakk_biting_cold_SpellScript);

        void HandleEffectHitTarget(SpellEffIndex effIndex)
        {
            // Since spell selects one random target, there is no way we can handle this another way
            if(Unit *pHit = GetHitUnit())
            {
                if(Unit *pCaster = GetCaster())
                {
                    pCaster->CastSpell(pHit, SPELL_BITING_COLD_PERIODIC_DAMAGES, true);
                    pCaster->CastSpell(pHit, SPELL_BITING_COLD_PERIODIC_DUMMY, true);
                }
            }
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_malakk_biting_cold_SpellScript::HandleEffectHitTarget, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript *GetSpellScript() const
    {
        return new spell_malakk_biting_cold_SpellScript();
    }
};


// Frostbite (Periodic)
class spell_malakk_frostbite_periodic : public SpellScriptLoader
{
public:
    spell_malakk_frostbite_periodic() : SpellScriptLoader("spell_malakk_frostbite_periodic") { }

    class spell_malakk_frostbite_periodic_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_malakk_frostbite_periodic_AuraScript);

        void HandlePeriodic(AuraEffect const* pAuraEffect)
        {
            if(!GetOwner())
                return;

            // Stack amount can be reduced when players are standing close to the owner
            if(Player *pOwner = GetOwner()->ToPlayer())
            {
                std::list<Player*> playerList;
                pOwner->GetPlayerListInGrid(playerList, 4.0f);

                playerList.remove(pOwner); // Remove self
                playerList.remove_if([](Player const* pPlayer) -> bool { return pPlayer->HasAura(SPELL_CHILLED_TO_THE_BONE) ; }); // Remove players with Chilled to the Bone

                uint32 uiReduceAmount = 0;

                switch(pOwner->GetMap()->GetDifficultyID())
                {
                // In 25-man raid, the amount is 1 * number of players within 4 yards
                case DIFFICULTY_25_HC:
                case DIFFICULTY_25_N:
                    uiReduceAmount = playerList.size() > 4 ? 4 : playerList.size();
                    break;

                // Otherwise it is 2 * number of players within 4 yards
                default:
                    uiReduceAmount = playerList.size() > 2 ? 4 : playerList.size() * 2;
                    break;
                }

                // And the amount can't be reduced below 1
                if(GetStackAmount() <= uiReduceAmount) // Indeed, if the update was done in real time, this should never happen
                    SetStackAmount(1);
                else
                    SetStackAmount(5 - uiReduceAmount);
            }
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_malakk_frostbite_periodic_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL_WITH_VALUE);
        }
    };

    AuraScript *GetAuraScript() const
    {
        return new spell_malakk_frostbite_periodic_AuraScript();
    }
};


// Frostbite (main damages)
class spell_malakk_frostbite : public SpellScriptLoader
{
public:
    spell_malakk_frostbite() : SpellScriptLoader("spell_malakk_frostbite") { }

    class spell_malakk_frostbite_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_malakk_frostbite_SpellScript);

        // Handler to select target (cause TARGET_UNIT_SRC_AREA_ENTRY doesn't work fine)
        void SelectTarget(std::list<WorldObject*>& targets)
        {
            targets.clear();
            if(Unit *pCaster = GetCaster())
            {
                std::list<Player*> playerList;
                pCaster->GetPlayerListInGrid(playerList, 500.0f);
                
                if(!playerList.empty())
                    targets.push_back(Trinity::Containers::SelectRandomContainerElement(playerList));
            }
        }
        
        // Handler to apply the visual
        void HandleOnHit(SpellEffIndex eEffIndex)
        {
            if(Unit *pHit = GetHitUnit())
            {
                if(Unit *pCaster = GetCaster())
                {
                    pHit->CastSpell(pHit, SPELL_FROSTBITE_SCREEN_EFFECT, true);
                    pCaster->CastSpell(pHit, SPELL_FROSTBITE_PERIODIC_DAMAGES, true);
                }
            }
        }

        void Register()
        {
            OnObjectAreaTargetSelect    += SpellObjectAreaTargetSelectFn(spell_malakk_frostbite_SpellScript::SelectTarget, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
            OnEffectHitTarget           += SpellEffectFn(spell_malakk_frostbite_SpellScript::HandleOnHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript *GetSpellScript() const
    {
        return new spell_malakk_frostbite_SpellScript();
    }
};

// Frostbite (allies damages)
class spell_malakk_frostbite_allies : public SpellScriptLoader
{
public:
    spell_malakk_frostbite_allies() : SpellScriptLoader("spell_malakk_frostbite_allies") { }

    class spell_malakk_frostbite_allies_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_malakk_frostbite_allies_SpellScript);
        
        void FilterTargets(std::list<WorldObject*>& targets)
        {
            if(!GetCaster())
                return;
                
            targets.remove(GetCaster());
        }
        
        void HandleOnCast()
        {
            // Cast Body Heat on heroic
            if(Unit *pCaster = GetCaster())
            {
                if(pCaster->GetMap()->IsHeroic())
                    pCaster->CastSpell(pCaster, SPELL_BODY_HEAT, true);
            }
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_malakk_frostbite_allies_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
            OnCast += SpellCastFn(spell_malakk_frostbite_allies_SpellScript::HandleOnCast);
        }
    };

    SpellScript *GetSpellScript() const
    {
        return new spell_malakk_frostbite_allies_SpellScript();
    }
};


// Body Heat
class spell_malakk_body_heat : public SpellScriptLoader
{
public:
    spell_malakk_body_heat() : SpellScriptLoader("spell_malakk_body_heat") { }

    class spell_malakk_body_heat_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_malakk_body_heat_SpellScript);

        void SelectTargets(std::list<WorldObject*>& targets)
        {
            std::list<Player*> playerList;
            if(GetCaster())
                GetCaster()->GetPlayerListInGrid(playerList, 4.0f);

            if(!playerList.empty() && playerList.size() > 1)
            {
                targets.clear();
                playerList.remove(GetCaster()->ToPlayer());

                for(Player* iter : playerList)
                    targets.push_back(iter);
            }
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_malakk_body_heat_SpellScript::SelectTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        }
    };

    SpellScript *GetSpellScript() const
    {
        return new spell_malakk_body_heat_SpellScript();
    }

    class spell_malakk_body_heat_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_malakk_body_heat_AuraScript);

        void HandleEffectRemove(AuraEffect const* pAuraEffect, AuraEffectHandleModes eMode)
        {
            if(!GetOwner())
                return;

            if(Player *pOwner = GetOwner()->ToPlayer())
                pOwner->CastSpell(pOwner, SPELL_CHILLED_TO_THE_BONE, true);
        }

        void Register()
        {
            OnEffectRemove += AuraEffectRemoveFn(spell_malakk_body_heat_AuraScript::HandleEffectRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript *GetAuraScript() const
    {
        return new spell_malakk_body_heat_AuraScript();
    }
};


// Reckless Charge
class spell_kazrajin_reckless_charge : public SpellScriptLoader
{
public:
    spell_kazrajin_reckless_charge() : SpellScriptLoader("spell_kazrajin_reckless_charge") { }

    class spell_kazrajin_reckless_charge_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_kazrajin_reckless_charge_SpellScript);

        void HandleCast()
        {
            if(Unit *pCaster = GetCaster())
            {
                if(Creature *pKazrajin = pCaster->ToCreature())
                {
                    if(Player *pChargeTarget = ObjectAccessor::GetPlayer(*pKazrajin, pKazrajin->AI()->GetGUID(DATA_RECKLESS_CHARGE_TARGET_GUID)))
                    {
                        // Compute position of landing
                        float fDist = pKazrajin->GetExactDist2d(pChargeTarget) - 5.0f; // Remove 5 yards to continue rolling
                        float fAngle = pKazrajin->GetOrientation();
                        float fX=0.0f, fY=0.0f;
                        //GetPositionWithDistInOrientation(pKazrajin, fDist, fAngle, fX, fY);


                        pKazrajin->GetMotionMaster()->MoveJump(fX, fY, pChargeTarget->GetPositionZ(), 22.0f, 9.0f, POINT_RECKLESS_CHARGE_LAND);
                    }
                }
            }
        }

        void Register()
        {
            AfterCast += SpellCastFn(spell_kazrajin_reckless_charge_SpellScript::HandleCast);
        }
    };

    SpellScript *GetSpellScript() const
    {
        return new spell_kazrajin_reckless_charge_SpellScript();
    }
};


// Overload
class spell_kazrajin_overload : public SpellScriptLoader
{
public:
    spell_kazrajin_overload() : SpellScriptLoader("spell_kazrajin_overload") { }

    class spell_kazrajin_overload_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_kazrajin_overload_AuraScript);

        void HandleEffectApply(AuraEffect const* pAuraEffect, AuraEffectHandleModes eMode)
        {
            if(!GetOwner())
                return;

            // Stunned on aura apply
            if(Creature *pOwner = GetOwner()->ToCreature())
                pOwner->SetControlled(true, UNIT_STATE_STUNNED);
        }

        void HandleOnProc(ProcEventInfo& rProcInfo)
        {
            if(Unit *pCaster = rProcInfo.GetActor())
            {
                if(!rProcInfo.GetDamageInfo())
                    return;

                int32 uiDamages = rProcInfo.GetDamageInfo()->GetDamage() * 0.4f; // 40% of damages returned to the player

                if(Unit *pVictim = rProcInfo.GetActionTarget())
                {
                   // pVictim->CastCustomSpell(pCaster, SPELL_OVERLOAD_DAMAGES, &uiDamages, NULL, NULL, NULL, NULL, NULL, true);
                    pVictim->CastSpell(pCaster, SPELL_OVERLOAD_DAMAGES, true);
                    pVictim->CastSpell(pCaster, SPELL_OVERLOAD_VISUAL, true);
                }
            }
        }

        void HandleEffectRemove(AuraEffect const* pAuraEffect, AuraEffectHandleModes eMode)
        {
            if(!GetOwner())
                return;

            // Unstunned on aura remove
            if(Creature *pOwner = GetOwner()->ToCreature())
                pOwner->SetControlled(false, UNIT_STATE_STUNNED);
        }

        void Register()
        {
            // Note: there is no stunning spell, I'm quite sure of that... even if
            // it is really wierd.
            OnEffectApply   += AuraEffectApplyFn(spell_kazrajin_overload_AuraScript::HandleEffectApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnProc          += AuraProcFn(spell_kazrajin_overload_AuraScript::HandleOnProc);
            OnEffectRemove  += AuraEffectRemoveFn(spell_kazrajin_overload_AuraScript::HandleEffectRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript *GetAuraScript() const
    {
        return new spell_kazrajin_overload_AuraScript();
    }
};


// Discharge
class spell_kazrajin_discharge : public SpellScriptLoader
{
public:
    spell_kazrajin_discharge() : SpellScriptLoader("spell_kazrajin_discharge") { }

    class spell_kazrajin_discharge_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_kazrajin_discharge_AuraScript);

        void HandleEffectApply(AuraEffect const* pAuraEffect, AuraEffectHandleModes eMode)
        {
            if(!GetOwner())
                return;

            // Stunned on aura apply
            if(Creature *pOwner = GetOwner()->ToCreature())
                pOwner->SetControlled(true, UNIT_STATE_STUNNED);
        }

        void HandlePeriodic(AuraEffect const* pAuraEffect)
        {
            if(!GetOwner())
                return;

            if(Creature *pOwner = GetOwner()->ToCreature())
            {
                int32 uiDamagesInPastSecs = (int32)pOwner->AI()->GetData(DATA_DAMAGES_PAST_SEC) * 0.05f; // 5% of damages taken in past sec
                pOwner->AI()->DoAction(ACTION_RESET_DAMAGES);

               // pOwner->CastCustomSpell(pOwner, SPELL_DISCHARGE_DAMAGES, &uiDamagesInPastSecs, NULL, NULL, NULL, NULL, NULL, true);
                pOwner->AI()->DoCastAOE(SPELL_DISCHARGE_VISUAL);
            }
        }

        void HandleEffectRemove(AuraEffect const* pAuraEffect, AuraEffectHandleModes eMode)
        {
            if(!GetOwner())
                return;

            // Unstunned on aura remove
            if(Creature *pOwner = GetOwner()->ToCreature())
                pOwner->SetControlled(false, UNIT_STATE_STUNNED);
        }

        void Register()
        {
            OnEffectApply       += AuraEffectApplyFn(spell_kazrajin_discharge_AuraScript::HandleEffectApply, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectPeriodic    += AuraEffectPeriodicFn(spell_kazrajin_discharge_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            OnEffectRemove      += AuraEffectRemoveFn(spell_kazrajin_discharge_AuraScript::HandleEffectRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript *GetAuraScript() const
    {
        return new spell_kazrajin_discharge_AuraScript();
    }
};


// Ensnared / Entrapped (the most fucked up spell ever made in WoW) (handled through Quicksand)
class spell_quicksand_periodic : public SpellScriptLoader
{
public:
    spell_quicksand_periodic() : SpellScriptLoader("spell_quicksand_periodic") { }

    class spell_quicksand_periodic_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_quicksand_periodic_AuraScript);

        void HandlePeriodic(AuraEffect const* pAuraEffect)
        {
            if(!GetOwner())
                return;

            // Handle Entrapped / Ensnared with the periodic effect, it's quite easier
            if(Player *pOwner = GetOwner()->ToPlayer())
            {
                std::list<Creature*> quicksandsList;
                pOwner->GetCreatureListWithEntryInGrid(quicksandsList, NPC_QUICKSAND_STALKER, 400.0f);
               // quicksandsList.sort(Trinity::DistanceCompareOrderPred(pOwner, true));

                // Remove quicksands that are not so close
                quicksandsList.remove_if([pOwner](Creature const* quicksand) -> bool
                {
                    if(CreatureAI *pAI = quicksand->AI())
                    {
                        float fRadius = pAI->GetData(DATA_QUICKSAND_MERGE_COUNT) * 7.0f + 7.0f;
                        return pOwner->GetExactDist2d(quicksand) >= fRadius;
                    }

                    return false;
                });

                // If there are no quicksands near, remove aura and return (using Remove(AURA_REMOVE_BY_DEFAULT) to prevent crash, instead of pOwner->RemoveAura(GetId()))
                if(quicksandsList.empty())
                {
                    Remove(AURA_REMOVE_BY_DEFAULT);
                    return;
                }

                // Else, force player to cast spell on self, so aura won't stack in many instances
                // (because target is TARGET_UNIT_CASTER, so annoying). Handle everything in here,
                // because it is simpler, even if not really beautiful...
                for(Creature *pQuicksand: quicksandsList)
                {
                    // Do not ensnare the player if it is already entrapped
                    if(pOwner->HasAura(SPELL_ENTRAPPED))
                        return;
                    
                    if(Aura *pEnsnared = pOwner->GetAura(SPELL_ENSNARED))
                    {
                        if(pEnsnared->GetStackAmount() < 4)
                        {
                            pOwner->CastSpell(pOwner, SPELL_ENSNARED, false);
                        }
                        else if(pEnsnared->GetStackAmount() == 4)
                        {
                            pOwner->CastSpell(pOwner, SPELL_ENSNARED, false); // Five stack
                            pOwner->CastSpell(pOwner, SPELL_ENTRAPPED, false);
                        }
                        // No else, so we won't multi entrap the player
                    }
                    else
                        pOwner->CastSpell(pOwner, SPELL_ENSNARED, true);
                }
            }
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_quicksand_periodic_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
        }
    };

    AuraScript *GetAuraScript() const
    {
        return new spell_quicksand_periodic_AuraScript();
    }
}; 


// Entrapped
class spell_quicksand_entrapped : public SpellScriptLoader
{
public:
    spell_quicksand_entrapped() : SpellScriptLoader("spell_quicksand_entrapped") { }

    class spell_quicksand_entrapped_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_quicksand_entrapped_SpellScript);

        void HandleAdditionalSpell(SpellEffIndex eEffIndex)
        {
            PreventHitDefaultEffect(eEffIndex);
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_quicksand_entrapped_SpellScript::HandleAdditionalSpell, EFFECT_1, SPELL_EFFECT_TRIGGER_SPELL);
        }
    };

    SpellScript *GetSpellScript() const
    {
        return new spell_quicksand_entrapped_SpellScript();
    }
};


// Sandstorm
class spell_sul_sandstorm : public SpellScriptLoader
{
public:
    spell_sul_sandstorm() : SpellScriptLoader("spell_sul_sandstorm") { }

    class spell_sul_sandstorm_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_sul_sandstorm_SpellScript);

        void HandleAfterCast()
        {
            if(Unit *pCaster = GetCaster())
            {
                std::list<Creature*> quicksandsList;
                std::list<Creature*> livingSandsList;

                pCaster->GetCreatureListWithEntryInGrid(quicksandsList, NPC_QUICKSAND_STALKER, 500.0f);
                pCaster->GetCreatureListWithEntryInGrid(livingSandsList, MOB_LIVING_SAND, 500.0f);

                for(Creature *pQuicksand: quicksandsList)
                    pQuicksand->AI()->DoAction(ACTION_CREATE_LIVING_SAND);

                for(Creature *pLivingSand : livingSandsList)
                    pLivingSand->AI()->DoAction(ACTION_FORTIFY);
            }
        }

        void Register()
        {
            AfterCast += SpellCastFn(spell_sul_sandstorm_SpellScript::HandleAfterCast);
        }
    };

    SpellScript *GetSpellScript() const
    {
        return new spell_sul_sandstorm_SpellScript();
    }
};


// Summon Blessed Loa Spirit
class spell_marli_summon_blessed_loa_spirit : public SpellScriptLoader
{
public:
    spell_marli_summon_blessed_loa_spirit() : SpellScriptLoader("spell_marli_summon_blessed_loa_spirit") { }

    class spell_marli_summon_blessed_loa_spirit_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_marli_summon_blessed_loa_spirit_SpellScript);

        void HandleDummy(SpellEffIndex eEffIndex)
        {
            if(Unit *pCaster = GetCaster())
                pCaster->CastSpell(pCaster, SPELL_SUMMON_BLESSED_LOA_SPIRIT, false);
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_marli_summon_blessed_loa_spirit_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript *GetSpellScript() const
    {
        return new spell_marli_summon_blessed_loa_spirit_SpellScript();
    }
};


// Summon Shadowed Loa Spirit
class spell_marli_summon_shadowed_loa_spirit : public SpellScriptLoader
{
public:
    spell_marli_summon_shadowed_loa_spirit() : SpellScriptLoader("spell_marli_summon_shadowed_loa_spirit") { }

    class spell_marli_summon_shadowed_loa_spirit_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_marli_summon_shadowed_loa_spirit_SpellScript);

        void HandleDummy(SpellEffIndex eEffIndex)
        {
            if(Unit *pCaster = GetCaster())
                pCaster->CastSpell(pCaster, SPELL_SUMMON_SHADOWED_LOA_SPIRIT, false);
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_marli_summon_shadowed_loa_spirit_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript *GetSpellScript() const
    {
        return new spell_marli_summon_shadowed_loa_spirit_SpellScript();
    }
};


// Twisted Fate (first)
class spell_marli_twisted_fate_first : public SpellScriptLoader
{
public:
    spell_marli_twisted_fate_first() : SpellScriptLoader("spell_marli_twisted_fate_first") { }

    class spell_marli_twisted_fate_first_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_marli_twisted_fate_first_SpellScript);

        void SelectTarget(std::list<WorldObject*>& targets)
        {
            if(!GetCaster())
                return;

            // Select one random player...
            std::list<Player*> playerList;
            GetCaster()->GetPlayerListInGrid(playerList, 500.0f);
            if(!playerList.empty())
            {
                targets.clear();
                targets.push_back(Trinity::Containers::SelectRandomContainerElement(playerList));
            }
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_marli_twisted_fate_first_SpellScript::SelectTarget, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        }
    };

    SpellScript *GetSpellScript() const
    {
        return new spell_marli_twisted_fate_first_SpellScript();
    }
};


// Twisted Fate (second)
class spell_marli_twisted_fate_second : public SpellScriptLoader
{
public:
    spell_marli_twisted_fate_second() : SpellScriptLoader("spell_marli_twisted_fate_second") { }

    class spell_marli_twisted_fate_second_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_marli_twisted_fate_second_SpellScript);

        void SelectTarget(std::list<WorldObject*>& targets)
        {
            if(!GetCaster())
                return;

            // Find the fathest player
            std::list<Player*> playerList;
            GetCaster()->GetPlayerListInGrid(playerList, 500.0f);
            //playerList.sort(Trinity::DistanceCompareOrderPred(GetCaster(), false));

            if(!playerList.empty() && playerList.front())
            {
                targets.clear();
                targets.push_back(playerList.front());
            }
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_marli_twisted_fate_second_SpellScript::SelectTarget, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        }
    };

    SpellScript *GetSpellScript() const
    {
        return new spell_marli_twisted_fate_second_SpellScript();
    }
};


// Twisted Fate (Periodic Damages)
class spell_marli_twisted_fate_damages : public SpellScriptLoader
{
public:
    spell_marli_twisted_fate_damages() : SpellScriptLoader("spell_marli_twisted_fate_damages") { }
    
    class spell_marli_twisted_fate_damages_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_marli_twisted_fate_damages_AuraScript);
        
        void CalculateAmount(AuraEffect const* pAuraEffect, int32 &ruiAmount, bool &rbCanBeRecalculated)
        {
            if(!GetOwner())
                return;
            
            if(Creature *pOwner = GetOwner()->ToCreature())
            {
                if(Creature *pTwistedFateTarget = ObjectAccessor::GetCreature(*pOwner, pOwner->AI()->GetGUID(DATA_TWISTED_FATE_GUID)))
                {
                    if(pTwistedFateTarget->IsAlive())
                    {
                        // The max amount is 250000, but it reduces the father the twisted fates are from
                        // each other. Let's say the maximum dist between them is 55 yards. If we want this
                        // to be pseudo linear, we'll say that with each yard between the twisted fates, we'll
                        // reduce this amount by 100 / 55. 
                        float fDist = pOwner->GetExactDist2d(pTwistedFateTarget);
                        ruiAmount = 250000 - CalculatePct(250000, fDist * 100 / 55);
                    }
                }
            }
        }
        
        void Register()
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_marli_twisted_fate_damages_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL_WITH_VALUE);
        }
    };
    
    AuraScript *GetAuraScript() const
    {
        return new spell_marli_twisted_fate_damages_AuraScript();
    }
};


// Dark Power
class spell_dark_power : public SpellScriptLoader
{
public:
    spell_dark_power() : SpellScriptLoader("spell_dark_power") { }
    
    class spell_dark_power_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dark_power_SpellScript);
        
        void HandleHitTarget(SpellEffIndex eEffectIndex)
        {
            if(Unit *pUnit = GetCaster())
            {
                if(Creature *pCaster = pUnit->ToCreature())
                {
                    if(CreatureAI *pAI = pCaster->AI())
                    {
                        uint32 const uiDarkPowerCount   = pAI->GetData(DATA_DARK_POWER_COUNT);
                        int32 iCustomValue              = GetSpellInfo()->GetEffect(eEffectIndex)->BasePoints;
                        
                        // Add 10% for each stack of Dark Power
                        for(uint32 i = 0; i < uiDarkPowerCount; ++i)
                            iCustomValue *= 1.1f;
                            
                        SetHitDamage(iCustomValue);
                    }
                }
            }
        }
        
        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_dark_power_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };
    
    SpellScript *GetSpellScript() const
    {
        return new spell_dark_power_SpellScript();
    }
};


// Soul Fragment Target Selector
class spell_soul_fragment_target_selector : public SpellScriptLoader
{
public:
    spell_soul_fragment_target_selector() : SpellScriptLoader("spell_soul_fragment_target_selector") { }
    
    class spell_soul_fragment_target_selector_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_soul_fragment_target_selector_SpellScript);
        
        void SelectTarget(std::list<WorldObject*>& targets)
        {
            if(!GetCaster())
                return;
                
            std::list<Player*> playerList;
            GetCaster()->GetPlayerListInGrid(playerList, 500.0f);
            
            if(!playerList.empty())
            {
                targets.clear();
                targets.push_back(Trinity::Containers::SelectRandomContainerElement(playerList));
            }
        }
        
        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_soul_fragment_target_selector_SpellScript::SelectTarget, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        }
    };
    
    SpellScript *GetSpellScript() const
    {
        return new spell_soul_fragment_target_selector_SpellScript();
    }
};


// Soul Fragment Switcher
class spell_soul_fragment_switcher : public SpellScriptLoader
{
public:
    spell_soul_fragment_switcher() : SpellScriptLoader("spell_soul_fragment_switcher") { }
    
    class spell_soul_fragment_switcher_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_soul_fragment_switcher_SpellScript);
        
        void HandleHitTarget(SpellEffIndex eEffIndex)
        {
            if(Unit *pCaster = GetCaster())
            {
                if(Aura *pSoulFragment = pCaster->GetAura(SPELL_SOUL_FRAGMENT_PERIODIC))
                    pSoulFragment->Remove();
            }
        }
        
        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_soul_fragment_switcher_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_FORCE_CAST);
        }
    };
    
    SpellScript *GetSpellScript() const
    {
        return new spell_soul_fragment_switcher_SpellScript();
    }
};

void AddSC_boss_council_of_elders()
{
    // Creatures
    //==========================================================
    // Boss
    new npc_council_event_helper();
    new boss_frost_king_malakk();
    new boss_kazrajin();
    new boss_sul_the_sandcrawler();
    new boss_high_priestess_marli();
    new mob_garajal();
    new mob_garajals_soul();

    //==========================================================
    // Summons
    new mob_quicksand_stalker();
    new mob_living_sand();
    new mob_blessed_loa_spirit();
    new mob_shadowed_loa_spirit();
    new mob_twisted_fate_helper();
    new mob_twisted_fate();

    // Spells
    //==========================================================
    // Garajal
    new spell_garajal_possessed();
    
    //==========================================================
    // Malakk
    new spell_malakk_frigid_assault();
    new spell_malakk_biting_cold();
    new spell_malakk_frostbite();
    new spell_malakk_frostbite_periodic();
    new spell_malakk_frostbite_allies();
    new spell_malakk_body_heat();

    //==========================================================
    // Kazrajin
    new spell_kazrajin_reckless_charge();
    new spell_kazrajin_overload();
    new spell_kazrajin_discharge();

    //==========================================================
    // Sul / Quicksand
    new spell_quicksand_periodic();
    new spell_quicksand_entrapped();
    new spell_sul_sandstorm();

    //==========================================================
    // High Priestess Marli
    new spell_marli_summon_blessed_loa_spirit();
    new spell_marli_summon_shadowed_loa_spirit();
    new spell_marli_twisted_fate_first();
    new spell_marli_twisted_fate_second();
    new spell_marli_twisted_fate_damages();
    
    //==========================================================
    // Others
    new spell_dark_power();
    new spell_soul_fragment_target_selector();
    new spell_soul_fragment_switcher();
}
