#include "throne_of_thunder.h"
#include <array>
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum eCreatures
{
    MOB_LIVING_SAND = 69153, // Summoned when Sandstorm hits a Quicksand
    MOB_BLESSED_LOA_SPIRIT = 69480, // Summoned by Mar'li, heals a councillor
    MOB_SHADOWED_LOA_SPIRIT = 69548, // Summoned by Mar'li, kills player
    MOB_TWISTED_FATE_FIRST = 69740, // First Twisted Fate npc to be summoned, will move toward the second and vice-versa
    MOB_TWISTED_FATE_SECOND = 69746, // Second Twisted Fate npc to be summoned
};
 
enum eSpells
{
    //===============================================
    // Gara'Jal's Soul
    SPELL_LINGERING_PRESENCE = 136467, // When the spirit of Gara'jal leaves a councillor
    SPELL_POSSESSED = 136442, // When the spirit of Gara'jal merges with a councillor (periodic dummy ? Dark Energy maybe)
    SPELL_DARK_POWER = 136507, // Damages increase with each cast

    // Soul Fragment
    SPELL_SOUL_FRAGMENT_SELECTOR = 137645, // Trigger 137641 (AREA_ENTRY ?)
    SPELL_SOUL_FRAGMENT_PERIODIC = 137641, // Override spells with 137643
    SPELL_SOUL_FRAGMENT_SWITCHER = 137643, // Trigger 137641
    SPELL_SOUL_FRAGMENT_DUMMY = 137670, // Maybe visual
    SPELL_SHADOWED_SOUL = 137650, // Each time 137641 ticks

    //===============================================
    // Frost King Malakk

    // Frigid Assault
    SPELL_FRIGID_ASSAULT = 136904, // Apply trigger auras
    SPELL_FRIGID_ASSAULT_STACK = 136903, // Stun owner when stacks reach 15
    SPELL_FRIGID_ASSAULT_DAMAGES = 136911, // Damages
    SPELL_FRIGID_ASSAULT_STUN = 136910, // When 136903 reaches 15 stacks

    // Biting Cold <=> Frostbite
    SPELL_BITING_COLD = 136917, // Main damages (select random target, need AuraScript or SpellScript) ( caster must take this damage as INTIAL , on apply ) 
    SPELL_BITING_COLD_PERIODIC_DAMAGES = 136992, // Periodically trigger 136991 ( caster is immune to this )
    SPELL_BITING_COLD_ALLY_DAMAGES = 136991, // Periodic damages to allies
    SPELL_BITING_COLD_PERIODIC_DUMMY = 137579, // Periodic trigger 137580
    SPELL_BITING_COLD_DUMMY = 137580, // Visual maybe ?
    // When Malakk has the possessed aura, Biting Cold turns into Frostbite
    SPELL_FROSTBITE = 136990, // Main damages (works like Biting Cold)
    SPELL_FROSTBITE_PERIODIC_DAMAGES = 136922, // Periodic trigger damages to ally (amount must be multiplied to fit stack amount)
    SPELL_FROSTBITE_ALLY_DAMAGES = 136937, // Damages to allies
    SPELL_FROSTBITE_SCREEN_EFFECT = 136926, // Screen effect
    SPELL_FROSTBITE_DUMMY_AURA = 137575, // Before Frostbite is applied, a blue arrow should appear 
    SPELL_FROSTBITE_VISUAL = 136936,
    // Is there something that can stack ?
    // Bodyheat triggers when Frostbite hits an ally in Heroic
    SPELL_BODY_HEAT = 137084, // Triggers 137085 on expire (AuraScript)
    SPELL_CHILLED_TO_THE_BONE = 137085, // Prevents player from reducing Frostbite amount of nearby players (or only caster ?)

    //===============================================
    // Kazra'jin

    // Reckless Charge
    // SPELL_RECKLESS_CHARGE                   = 137117, // Visual on the boss while travelling (launch everything) ("They see me rollin ! FUCK YEAH !")
    SPELL_RECKLESS_CHARGE_GROUND_AT = 138026, // Visual on the ground while boss is travelling (damage dealer ?)
    SPELL_RECKLESS_CHARGE_SHATTER_GROUND = 137122, // Final damages + Knock back and visual of rocks appearing around
    SPELL_RECKLESS_CHARGE_UNIQUE_DAMAGES = 137133, // Damage on unique target (AT ? Kazra'jin ?)
    SPELL_RECKLESS_CHARGE_PRE_PATH = 000000, // TBF: Visual of dark pools on ground before charge

    SPELL_RECKLESS_CHARGE = 137107,
    SPELL_RECKLESS_CHARGE_VISUAL = 137117,
    SPELL_RECKLESS_CHARGE_FACE = 137121, // Forces facing towards target
    SPELL_RECKLESS_CHARGE_SOUND = 137131,

    // Need black visual on ground before cast

    // Overload
    // When Kazra'jin is empowered, he overloads after performing a Reckless Charge
    SPELL_OVERLOAD = 137149, // Dummy aura to handle the strike back (HandleDummyAuraProc ?) (must add UNIT_STATE_STUN manually)
    SPELL_OVERLOAD_DAMAGES = 137151, // Damage spell
    SPELL_OVERLOAD_VISUAL = 137163, // Visual on caster of spell that triggered mirror effect
    // In Heroic, Overload turns into Discharge
    SPELL_DISCHARGE = 137166, // Periodic dummy ? Why ? (must add UNIT_STATE_STUN manually)
    SPELL_DISCHARGE_DAMAGES = 136935, // Damage spell
    SPELL_DISCHARGE_VISUAL = 137172, // Visual on all players when spell ticks

    //===============================================
    // Sul the Sandcrawler

    SPELL_SAND_BOLT = 136189, // Trigger Missile 136190
    SPELL_SAND_BOLT_DAMAGES = 136190, // Damages

    // Quicksand (fuckin AT)
    // Quicksand is an AT, but handling the spell with an AT is too complex... we'll use another mechanism,
    SPELL_QUICKSAND_PERIODIC_DAMAGES = 136860, // Periodic damages to any target within 7 yards : we must handle apply / remove manually
    SPELL_QUICKSAND_AT_VISUAL = 137572, // Visual
    SPELL_QUICKSAND_AT_VISUAL_INIT = 136851,
    SPELL_ENSNARED = 136878, // Slow player and stacks; when it reaches 5 stacks, player is Entrapped
    SPELL_ENTRAPPED = 136857, // Need to prevent second effect... so annoying

    // Sandstorm
    SPELL_SAND_STORM = 136894, // Periodic trigger 136899,
    SPELL_SAND_STORM_DAMAGES = 136899, // Damages
    SPELL_SAND_STORM_DUMMY_AURA = 136895, // Maybe visual since it has the same duration as 136894

    //===============================================
    // High Priestess Mar'li

    // Wrath of the Loa
    SPELL_WRATH_OF_THE_LOA = 137344,
    SPELL_WRATH_OF_THE_LOA_DARK = 137347, // When Possessed

    // Loa Spirit <=> Twisted Fate
    SPELL_BLESSED_LOA_SPIRIT = 137203, // Handle dummy cause Blizzard messed that up
    SPELL_SUMMON_BLESSED_LOA_SPIRIT = 137200, // Summons 69480
    SPELL_SHADOWED_LOA_SPIRIT = 137350, // Handle dummy cause Blizzard messed that up (Possessed version of Loa Spirit)
    SPELL_SUMMON_SHADOWED_LOA_SPIRIT = 137351, // Summons 69548
    // In Heroic, Shadowed Loa Spirit is replaced with Twisted Fate
    SPELL_TWISTED_FATE_PERIODIC = 137986, // Periodic trigger 137972,
    SPELL_TWISTED_FATE_DAMAGES = 137972, // Periodic damages while linked AND while not linked (must update value in handler of 137986)
    SPELL_TWISTED_FATE_DUMMY_AURA = 137967, // Visual maybe ?
    // First npc of Twisted Fate
    SPELL_TWISTED_FATE = 137891, // Launch everything (triggers 137893)
    SPELL_TWISTED_FATE_SUMMON_FIRST = 137893, // Summon the first Twisted Fate -> USE THIS INTO EVENT
    SPELL_TWISTED_FATE_FORCE_FIRST = 137943, // Force cast 137950 on self
    SPELL_TWISTED_FATE_CLONE_FIRST = 137950, // Clone, Dummy, Size... WHAT ELSE ?
    // Second npc of Twisted Fate
    SPELL_TWISTED_FATE_FORCE_SUMMON_SECOND = 137962, // Trigger 137963 on the most distant player (fuck target)
    SPELL_TWISTED_FATE_SUMMON_SECOND = 137963, // Summon the second Twisted Fate -> USE THIS INTO EVENT
    SPELL_TWISTED_FATE_FORCE_SECOND = 137964, // Force cast 137965 on self
    SPELL_TWISTED_FATE_CLONE_SECOND = 137965, // Clone, Dummy, Size... WHAT ELSE ?

    //===============================================
    // Summons
    SPELL_FORTIFIED = 136864, // Living Sand : On hit by Sandstorm
    SPELL_TREACHEROUS_GROUND = 137614, // Living Sand : On emerge from reunited Quicksand
    SPELL_TREACHEROUS_GROUND_SIZE = 137629,
    SPELL_BLESSED_GIFT = 137303, // Blessed Loa Spirit, heal 5% of Max Health on weakest councillor
    SPELL_BLESSED_TIME_OUT = 137204, // Dummy visual for blizz
    SPELL_MARKED_SOUL = 137359, // Shadowed Loa Spirit / Player ? Force Loa to follow player
    SPELL_SHADOWED_GIFT = 137390, // Instantly kills player (Shadowed Loa Spirit)
    SPELL_SHADOWED_TIME_OUT = 137398, // Dummy visual for blizz

    //===============================================
    // Visuals
    SPELL_GARA_JALS_SOUL = 136423, // NPC Visual
    SPELL_BLESSED_TRANSFORMATION = 137181, // NPC Visual
    SPELL_SHADOWED_TRANSFORMATION = 137271, // NPC Visual
    SPELL_GARAJAL_GHOST = 000000, // TBF

    //===============================================
    // Shared
    SPELL_ZERO_POWER = 72242,
};


enum eEvents
{
    //===============================================
    // Frost King Malakk
    EVENT_FRIGID_ASSAULT = 1,
    EVENT_BITING_COLD = 2,
    EVENT_FROSTBITE = 3,

    //===============================================
    // Kazra'jin
    EVENT_RECKLESS_CHARGE_PRE_PATH = 4,
    EVENT_RECKLESS_CHARGE = 5,

    //===============================================
    // Sul the Sandcrawler
    EVENT_SAND_BOLT = 6,
    EVENT_QUICKSAND = 7,
    EVENT_SANDSTORM = 8,

    //===============================================
    // High Priestess Mar'li
    EVENT_WRATH_OF_THE_LOA = 9,
    EVENT_WRATH_OF_THE_LOA_DARK = 10,
    EVENT_BLESSED_LOA_SPIRIT = 11,
    EVENT_SHADOWED_LOA_SPIRIT = 12,
    EVENT_TWISTED_FATE = 13,

    //===============================================
    // Blessed Loa Spirit
    EVENT_BLESSED_GIFT = 14,
    EVENT_FROSTBITE_TRUE,
    EVENT_MOVE_COUNCILLOR = 21,
    EVENT_TARGET_A_RANDOM_PLAYER,
    EVENT_MOVE_TO_PLAYER,
    //===============================================
    // Shadowed Loa Spiri
    EVENT_SHADOWED_GIFT = 15,

    //===============================================
    // Councillots
    EVENT_INCREASE_POWER = 16,
    EVENT_DARK_POWER = 17,

    //===============================================
    // Quicksand Stalker
    EVENT_QUICKSAND_PERIODIC = 18, // This only handles apply of the Quicksand damages aura, which handle the rooting by itself
    EVENT_TRY_MERGE = 19, // Try merge event is used to merge Quicksand when they are summoend by others Quicksand (only scheduled once)
    EVENT_ACTIVATE_SAND = 22,

    //===============================================
    // Garajal
    EVENT_SUMMON_SOUL = 20,
    EVENT_TREACHEROUS_GROUND,
    EVENT_CHECK_POSSESED,
    EVENT_RECKLESS_CHARGE_HELPER,
    EVENT_CHECK_NONPOSSESED,
};

enum eActions
{
    //===============================================
    // Gara'jal
    ACTION_ENTER_COMBAT = 0, // Garajal + Garajal's soul
    ACTION_EXIT_COUNCILLOR = 1, // Garajal's soul
    ACTION_FIGHT_RESET = 2,
    ACTION_FIGHT_BEGIN = 3,
    ACTION_COUNCILLOR_DIED = 4,
    ACTION_BOSS_TIMER_START = 5,
    ACTION_BOSS_TIMER_WIPE = 6,
    ACTION_BOSS_TIMER_DONE = 7,

    //===============================================
    // Councillors
    ACTION_COUNCILLORS_ENTER_COMBAT = 4, // When one enters combat, everybody else must enter combat
    ACTION_SET_POSSESSED = 5, // Initialize the events to possessed phase (called from SpellScript)
    ACTION_SET_UNPOSSESSED = 6, // Reset the events to normal (same as for SET_POSSESED)
    ACTION_DARK_POWER = 7, // Initialize the Dark Power phase (called from the handler of the periodic dummy aura I assume)

    //===============================================
    // Kazra'jin
    ACTION_RESET_DAMAGES = 8, // Must be called each time the periodic aura ticks

    //===============================================
    // Living Sand
    ACTION_FORTIFY = 9,

    //===============================================
    // Twisted Fate Helper
    ACTION_TWISTED_FATE_END_FIGHT = 10, // Used to deallocate memory

    //===============================================
    // Twisted Fate (common)
    ACTION_OTHER_TWISTED_FATE_DIED = 11,

    //===============================================
    // Quicksand
    ACTION_CREATE_LIVING_SAND = 12,

    ACTION_I_WAS_INTERRUPTED = 13,
    ACTION_I_WAS_INTERRUPTED_SECOND = 14,
};


enum eMotions
{
    //===============================================
    // Gara'jal
    POINT_COUNCILLOR = 4343,

    //===============================================
    // Kazra'jin
    POINT_RECKLESS_CHARGE_LAND = 5000, // Position where Kazrajin lands after performing Reckless Charge
    POINT_RECKLESS_CHARGE_PLAYER = 6714, // Position where Kazrajin rolls to after landing from Reckless Charge

    //===============================================
    // Blessed Loa Spirit
    POINT_BLESSED_LOA_SPIRIT_COUNCILLOR = 9413, // Point to identify the councillor the Blessed Loa Spirit is going toward
    // No need to do a point for the Shadowed Loa Spirit since it will not
    // reach the target but only go 6 yards away from him (so we can use MoveFollow)

    //===============================================
    // Twisted Fate (common)
    POINT_MIDDLE = 6653, // Point representing the middle point on the line formed by the two Twisted Fate
};


enum eHelperStatus
{
    STATUS_RESET = 0,
    STATUS_PROGRESS = 1,
    STATUS_DONE = 2,
};


enum eDatas
{
    DATA_DARK_POWER_COUNT = 0,
    DATA_QUICKSAND_MERGE_COUNT = 1,
    DATA_SHADOWED_LOA_SPIRIT_TARGET_GUID = 2, // Accessor to get the GUID of the player the Shadowed Loa Spirit will follow
    DATA_BLESSED_LOA_SPIRIT_TARGET_GUID = 3, // Accessor to get the GUID of the boss the Blessed Loa Spirit will follow
    DATA_TWISTED_FATE_GUID = 4, // Accessor to get the GUID of the twisted fate the caller is linked to
    DATA_TWISTED_FATE_OTHER_DIED = 5, // Accessor to know if one twisted fate has been unlinked from the other
    DATA_RECKLESS_CHARGE_TARGET_GUID = 6, // Accessor to get the GUID of the player Kazrajin is targetting for the purpose of Reckless Charge
    DATA_DAMAGES_PAST_SEC = 7, // Accessor to get the amount of damages Kazrajin received in the last second
};


enum eTalks : uint32
{
    TALK_AGGRO = 0,
    TALK_POSSESS = 1,
    TALK_SPECIAL = 2,
    EMOTE_POSSESS = 6,

    // sul
    TALK_SUL_QUICKSAND = 3,
    TALK_SUL_SLAY = 4,
    TALK_SUL_DEATH = 5,
    TALK_SUL_SANDSTORM = 7,

    // malakk
    TALK_MALAKK_SLAY = 3,
    TALK_MALAKK_DEATH = 4,
    TALK_MALAKK_FROSTBITE = 5,

    // marli
    TALK_MARLI_SLAY = 3,
    TALK_MARLI_DEATH = 4,
    TALK_MARLI_BLESSED = 5,
    TALK_MARLI_SHADOWED = 7,

    // kazra'jin
    TALK_KAZRAJIN_CHARGE = 3,
    TALK_KAZRAJIN_SLAY = 4,
    TALK_KAZRAJIN_DEATH = 5,
    TALK_KAZRAJIN_OVERLOAD = 7
};

//=========================================================
// Helpers

static Creature* GetGarajal(WorldObject* pSource)
{
    return ObjectAccessor::GetCreature(*pSource, pSource->GetInstanceScript()->GetObjectGuid(MOB_GARA_JAL));
}

static Creature* GetGarajalsSoul(WorldObject* pSource)
{
    return ObjectAccessor::GetCreature(*pSource, pSource->GetInstanceScript()->GetObjectGuid(MOB_GARA_JALS_SOUL));
}

static Creature* GetFrostKingMalakk(WorldObject* pSource)
{
    return ObjectAccessor::GetCreature(*pSource, pSource->GetInstanceScript()->GetObjectGuid(BOSS_COUNCIL_FROST_KING_MALAKK));
}

static Creature* GetKazrajin(WorldObject* pSource)
{
    return ObjectAccessor::GetCreature(*pSource, pSource->GetInstanceScript()->GetObjectGuid(BOSS_COUNCIL_KAZRAJIN));
}

static Creature* GetSulTheSandcrawler(WorldObject* pSource)
{
    return ObjectAccessor::GetCreature(*pSource, pSource->GetInstanceScript()->GetObjectGuid(BOSS_COUNCIL_SUL_THE_SANDCRAWLER));
}

static Creature* GetHighPriestessMarli(WorldObject* pSource)
{
    return ObjectAccessor::GetCreature(*pSource, pSource->GetInstanceScript()->GetObjectGuid(BOSS_COUNCIL_HIGH_PRIESTESS_MARLI));
}

static Creature* GetBossByEntry(uint32 uiEntry, WorldObject* pSource)
{
    switch (uiEntry)
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
typedef Creature* (*Accessor)(WorldObject* pSource);

static const std::array<uint32, 4> uiBossEntries = { BOSS_COUNCIL_FROST_KING_MALAKK, BOSS_COUNCIL_KAZRAJIN, BOSS_COUNCIL_SUL_THE_SANDCRAWLER, BOSS_COUNCIL_HIGH_PRIESTESS_MARLI };


//=========================================================
// Creature Scripts

// Base class for the councillor's AI (only override common functions)
class boss_council_of_elders_base_AI : public BossAI
{
public:
    boss_council_of_elders_base_AI(Creature* pCreature) :
        BossAI(pCreature, DATA_COUNCIL_OF_ELDERS), pInstance(pCreature->GetInstanceScript())
    {
        events.Reset();
    }

    EventMap darkPowerEvents;

    // Override Reset to reset the EventMap in one place and force
    // reset of the fight by sending DoAction to the helper.
    // Note: if one boss reset, every other boss need to reset. Otherwise,
    // it would be a very major fail, meaning that a creature can reset while
    // other close creatures are still in combat.
    void Reset()
    {
        pInstance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

        if (Creature* pGarajal = GetGarajal(me))
        {
            if (pGarajal->AI())
                pGarajal->AI()->DoAction(ACTION_FIGHT_RESET);
        }

        events.Reset();
        darkPowerEvents.Reset();

        me->SetPowerType(POWER_ENERGY);
        me->SetMaxPower(POWER_ENERGY, 100);
        me->SetPower(POWER_ENERGY, 0);

        DoCast(me, SPELL_ZERO_POWER);
        uiDarkPowerCount = 0;
        uiDamageTakenPossessed = 0;
    }

    // Override EnterCombat to send the DoAction to the helper
    void EnterCombat(Unit* pAttacker)
    {
        pInstance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

        if (Creature* pGarajal = GetGarajal(me))
        {
            if (pGarajal->AI())
                pGarajal->AI()->DoAction(ACTION_FIGHT_BEGIN);
        }

        Talk(TALK_AGGRO);

        InitStandartEvents();
    }

    void EnterEvadeMode(EvadeReason w)
    {
        me->SetFullHealth();
    }

    // Override DoAction for the generic actions
    void DoAction(int32 iAction)
    {
        switch (iAction)
        {
        case ACTION_COUNCILLORS_ENTER_COMBAT:
            // The call to AttackStart will be kinda useless for some
            // boss since they can't move, which will result in useless
            // call to MoveChase. Anyway, I do not want to recode this
            // function now.
            InitStandartEvents();
            break;

        case ACTION_SET_POSSESSED:
            Talk(TALK_POSSESS);
            Talk(EMOTE_POSSESS);
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

    void DamageTaken(Unit* pAttacker, uint32& ruiAmount)
    {
        // Heroic only shit..
        // if (Aura* pAura = me->GetAura(SPELL_DISCHARGE))

        if (!me->HasAura(SPELL_POSSESSED))
            return;

        uiDamageTakenPossessed += ruiAmount;

        if (uiDamageTakenPossessed >= (float)(me->GetMaxHealth() * 0.25f))
        {
            // No remove when no other councillor alive
            if (IsACouncillorAlive())
            {
                if (Creature* pGarajal = GetGarajalsSoul(me))
                    pGarajal->AI()->DoAction(ACTION_EXIT_COUNCILLOR);
            }
            uiDamageTakenPossessed = 0; // Reset in both case to prevent chain call to IsACouncillorAlive
        }
    }

    void RewardCurrencyAndUpdateState()
    {
    }

    void JustDied(Unit* pKiller)
    {
        pInstance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

        switch (me->GetEntry())
        {
        case BOSS_COUNCIL_FROST_KING_MALAKK:
            Talk(TALK_MALAKK_DEATH);
            break;

        case BOSS_COUNCIL_KAZRAJIN:
            Talk(TALK_KAZRAJIN_DEATH);
            break;

        case BOSS_COUNCIL_SUL_THE_SANDCRAWLER:
            Talk(TALK_SUL_DEATH);
            break;

        case BOSS_COUNCIL_HIGH_PRIESTESS_MARLI:
            Talk(TALK_MARLI_DEATH);
            break;

        default:
            break;
        }

        if (Creature* pGarajal = GetGarajal(me))
        {
            if (CreatureAI* pAI = pGarajal->AI())
            {
                pAI->DoAction(ACTION_COUNCILLOR_DIED);

                if (pAI->GetData(0) < 4)
                    me->ResetLootRecipients();
                else
                    RewardCurrencyAndUpdateState();
            }
        }
    }

    void KilledUnit(Unit* pKilled)
    {
        switch (me->GetEntry())
        {
        case BOSS_COUNCIL_FROST_KING_MALAKK:
            Talk(TALK_MALAKK_SLAY);
            break;

        case BOSS_COUNCIL_KAZRAJIN:
            Talk(TALK_KAZRAJIN_SLAY);
            break;

        case BOSS_COUNCIL_SUL_THE_SANDCRAWLER:
            Talk(TALK_SUL_SLAY);
            break;

        case BOSS_COUNCIL_HIGH_PRIESTESS_MARLI:
            Talk(TALK_MARLI_SLAY);
            break;

        default:
            break;
        }
    }

    // Helper function to prevent removing the possessed aura when no
    // other councillor is alive.
    bool IsACouncillorAlive() const
    {
        Creature* pMalakk = GetFrostKingMalakk(me),
            * pKazrajin = GetKazrajin(me),
            * pSul = GetSulTheSandcrawler(me),
            * pMarli = GetHighPriestessMarli(me);

        // Pointers should not be null
        if (!pMalakk || !pKazrajin || !pSul || !pMarli)
            return false;

        switch (me->GetEntry())
        {
        case BOSS_COUNCIL_FROST_KING_MALAKK:
            return (pKazrajin->IsAlive() || pSul->IsAlive() || pMarli->IsAlive());

        case BOSS_COUNCIL_KAZRAJIN:
            return (pSul->IsAlive() || pMarli->IsAlive() || pMalakk->IsAlive());

        case BOSS_COUNCIL_SUL_THE_SANDCRAWLER:
            return (pMarli->IsAlive() || pMalakk->IsAlive() || pKazrajin->IsAlive());

        case BOSS_COUNCIL_HIGH_PRIESTESS_MARLI:
            return (pMalakk->IsAlive() || pKazrajin->IsAlive() || pSul->IsAlive());

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
    InstanceScript* pInstance;
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
        darkPowerEvents.Reset();
        darkPowerEvents.ScheduleEvent(EVENT_DARK_POWER, 1000);
    }

    uint32 GetPowerTimer() const
    {
        if (Aura* pLingeringPresence = me->GetAura(SPELL_LINGERING_PRESENCE))
        {
            float fReduce = 1 - (pLingeringPresence->GetStackAmount() / 10);
            uint32 uiTimer = (2 * IN_MILLISECONDS) * fReduce;
            return uiTimer;
        }
        else
            return 2 * IN_MILLISECONDS;
    }
};
typedef boss_council_of_elders_base_AI CouncilBaseAI;


struct hasFrostbite : public std::unary_function<Unit*, bool>
{
    hasFrostbite() {}

    bool operator() (const Unit* pTarget)
    {
        return pTarget->HasAura(SPELL_FROSTBITE_DUMMY_AURA);
    }
};

// Frost King Malakk AI
class boss_frost_king_malakk : public CreatureScript
{
public:
    boss_frost_king_malakk() : CreatureScript("boss_frost_king_malakk") { }

    class boss_frost_king_malakk_AI : public CouncilBaseAI
    {
    public:
        boss_frost_king_malakk_AI(Creature* pCreature) :
            CouncilBaseAI(pCreature)
        {

        }

        // No need to override Reset since there is nothing to reset here
        // No need to override EnterCombat since there is nothing to do here

        void UpdateAI(uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;


            darkPowerEvents.Update(uiDiff);
            events.Update(uiDiff);

            switch (darkPowerEvents.ExecuteEvent())
            {
            case EVENT_DARK_POWER:
                DoCast(me, SPELL_DARK_POWER, true);
                ++uiDarkPowerCount;
                darkPowerEvents.ScheduleEvent(EVENT_DARK_POWER, 1 * IN_MILLISECONDS);
                break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 uiEventId = events.ExecuteEvent())
            {
                switch (uiEventId)
                {
                case EVENT_FRIGID_ASSAULT:
                    DoCast(me, SPELL_FRIGID_ASSAULT);
                    events.ScheduleEvent(EVENT_FRIGID_ASSAULT, 35 * IN_MILLISECONDS);
                    break;

                case EVENT_BITING_COLD:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 80.0f, true))
                        me->CastSpell(target, SPELL_BITING_COLD);
                    //DoCastAOE(SPELL_BITING_COLD); // Spell is wierd... handle target selection in SpellScript
                    events.ScheduleEvent(EVENT_BITING_COLD, 45 * IN_MILLISECONDS);
                    break;

                case EVENT_FROSTBITE:
                    Talk(TALK_SPECIAL);
                    //DoCastAOE(SPELL_FROSTBITE); // Handle target selection in SpellScript
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 80.0f, true))
                    {
                        me->AddAura(SPELL_FROSTBITE_DUMMY_AURA, target);
                    }
                    events.ScheduleEvent(EVENT_FROSTBITE_TRUE, 2 * IN_MILLISECONDS);
                    break;
                case EVENT_FROSTBITE_TRUE:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 80.0f, true))
                    {
                        me->CastSpell(target, SPELL_FROSTBITE);
                    }
                    events.ScheduleEvent(EVENT_FROSTBITE, 45 * IN_MILLISECONDS);
                    break;
                case EVENT_INCREASE_POWER:
                    me->ModifyPower(POWER_ENERGY, 3);
                    if (me->GetPower(POWER_ENERGY) < 100)
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
            darkPowerEvents.Reset();
            events.Reset();

            events.ScheduleEvent(EVENT_FRIGID_ASSAULT, 10 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_BITING_COLD, 45 * IN_MILLISECONDS);
        }

        void InitPossessedEvents()
        {
            events.Reset();

            events.ScheduleEvent(EVENT_FRIGID_ASSAULT, 10 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_FROSTBITE, 20 * IN_MILLISECONDS);
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_frost_king_malakk_AI(pCreature);
    }
};

enum FreakzRecklessChargeEvents
{
    EVENT_RECKLESS_CAHRGE_INITIALIZE = 1,
};
// Kazra'jin AI
class boss_kazrajin : public CreatureScript
{
public:
    boss_kazrajin() : CreatureScript("boss_kazrajin") { }

    class boss_kazrajin_AI : public CouncilBaseAI
    {
    public:
        boss_kazrajin_AI(Creature* pCreature) :
            CouncilBaseAI(pCreature), uiDamagesDoneInPastSecs(0)
        {
            //me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
            //SetCombatMovement(false);
        }

        // Override reset to reset the amount of damages received, and the
        // movement flags.
        void Reset()
        {
            uiDamagesDoneInPastSecs = 0;
            events.Reset();

            //me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
            CouncilBaseAI::Reset(); // Finalize Reset
        }

        void CheckPrimaryTarget()
        {
            Unit* myTarget = me->GetVictim();
            // if no target and this function is called it will crash the server, we don't want taht
            if (!myTarget)
                return;
            // work only in combat
            if (me->IsInCombat())
                if (myTarget->IsPet() || myTarget->IsGuardian())
                    me->Kill(myTarget);
        }

        void EnterCombat(Unit*)
        {
            events.ScheduleEvent(EVENT_RECKLESS_CAHRGE_INITIALIZE, 10 * IN_MILLISECONDS);
        }

        void EnterEvadeMode(EvadeReason w)
        {
            me->GetMotionMaster()->Clear();
            me->GetMotionMaster()->MoveTargetedHome();

        }

        void UpdateAI(uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;
            CheckPrimaryTarget();

            darkPowerEvents.Update(uiDiff);
            events.Update(uiDiff);

            switch (darkPowerEvents.ExecuteEvent())
            {
            case EVENT_DARK_POWER:
                DoCast(me, SPELL_DARK_POWER, true);
                ++uiDarkPowerCount;
                darkPowerEvents.ScheduleEvent(EVENT_DARK_POWER, 1 * IN_MILLISECONDS);
                break;
            }

            //if (me->HasUnitState(UNIT_STATE_CASTING))
             //   return;

            while (uint32 uiEventId = events.ExecuteEvent())
            {
                switch (uiEventId)
                {
                case EVENT_RECKLESS_CHARGE_PRE_PATH:
                {
                    if (me->HasAura(SPELL_OVERLOAD) || me->HasAura(SPELL_DISCHARGE))
                    {
                        events.RescheduleEvent(EVENT_RECKLESS_CHARGE_PRE_PATH, 20 * IN_MILLISECONDS);
                        return;
                    }
                    //DoCast(me, SPELL_RECKLESS_CHARGE_PRE_PATH);
                    me->CastSpell(me, SPELL_RECKLESS_CHARGE, true);
                    me->AddAura(137121, me); // script handler
                    if (Unit* player = SelectTarget(SELECT_TARGET_RANDOM))
                    {
                        if (Aura* facing = me->AddAura(SPELL_RECKLESS_CHARGE_FACE, player))
                            facing->SetMaxDuration(6000);
                    }
                    events.ScheduleEvent(EVENT_RECKLESS_CHARGE, 3 * IN_MILLISECONDS);
                    break;
                }

                case EVENT_RECKLESS_CHARGE:
                    events.ScheduleEvent(EVENT_RECKLESS_CHARGE_PRE_PATH, 12 * IN_MILLISECONDS);
                    if (rand() % 10 > 4)
                        Talk(TALK_KAZRAJIN_CHARGE);
                    me->CastSpell(me, SPELL_RECKLESS_CHARGE_VISUAL, true); // Launch everything
                    //events.ScheduleEvent(EVENT_RECKLESS_CHARGE_HELPER, 500, 0, 0);
                    // Summon npcs for the visual of Reckless Charge while travelling ?
                    // Handle next part in MovementInform.
                    break;
                case EVENT_RECKLESS_CHARGE_HELPER:
                {
                    Unit* target = me->GetVictim();
                    if (!target)
                        return;
                    me->CastSpell(target, SPELL_RECKLESS_CHARGE_GROUND_AT);
                    std::ostringstream str;
                    str << "Kazra'jin prepares to cast Reckless Charge on " << target->GetName() << "!";
                    me->TextEmote(str.str().c_str(), target, true);
                    break;
                }
                case EVENT_INCREASE_POWER:
                    if (me->HasAura(SPELL_POSSESSED))
                    {
                        me->ModifyPower(POWER_ENERGY, 3);
                        if (me->GetPower(POWER_ENERGY) < 100)
                            events.ScheduleEvent(EVENT_INCREASE_POWER, GetPowerTimer());
                        else
                            DoAction(ACTION_DARK_POWER);
                    }
                    break;
                case EVENT_RECKLESS_CAHRGE_INITIALIZE:
                {
                    if (me->HasAura(SPELL_DISCHARGE || me->HasAura(SPELL_OVERLOAD)))
                    {
                        events.CancelEvent(EVENT_RECKLESS_CAHRGE_INITIALIZE);
                        events.ScheduleEvent(EVENT_RECKLESS_CAHRGE_INITIALIZE, 10 * IN_MILLISECONDS);
                        break;
                    }
 
                    if (Unit* player = SelectTarget(SELECT_TARGET_RANDOM, 0, 80.0f, true))
                    {
                        me->AddAura(137117, me);
                        std::ostringstream str;
                        str << "Kazra'jin prepares to perform a |cFFF00000|Hspell:137133|h[Reckless Charge]|h|r on " << player->GetName() << "!";
                        me->TextEmote(str.str().c_str(), 0, true);
                        if (rand() % 10 > 4)
                            Talk(TALK_KAZRAJIN_CHARGE);
                        me->GetMotionMaster()->MovePoint(POINT_RECKLESS_CHARGE_LAND, player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(), false);
                    }
                    break;
                }
                default:
                    break;
                }
            }
        }

        void MovementInform(uint32 uiMotionType, uint32 uiMotionPointId)
        {
            if (uiMotionPointId == POINT_RECKLESS_CHARGE_LAND)
            {
                me->RemoveAura(137117);
                events.ScheduleEvent(EVENT_RECKLESS_CAHRGE_INITIALIZE, 10 * IN_MILLISECONDS);
                me->CastSpell(me, 137122); // shatter ground damage + visual
                if (me->HasAura(SPELL_POSSESSED))
                {
                    if (me->GetMap()->IsHeroic())
                        me->CastSpell(me, SPELL_DISCHARGE);
                    else
                    {
                        me->CastSpell(me, SPELL_OVERLOAD);
                    }
                }

            }
        }


        // Override Damage Taken again to handle the Discharge aura.
        /*
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
        }*/

        // Override DoAction again to handle the Discharge Aura.
        /*
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
            return uiDarkPowerCount;
        }*/


    private:
        // Amount of damages received during past seconds in Heroic,
        // cause spell ticks each second, instead of being a permanent
        // dummy. Fuck blizzard's logic.
        uint32 uiDamagesDoneInPastSecs;
        ObjectGuid uiRecklessChargeTargetGUID;
        void InitStandartEvents()
        {
            darkPowerEvents.Reset();
            //events.Reset();

            //events.ScheduleEvent(EVENT_RECKLESS_CAHRGE_INITIALIZE, 10 * IN_MILLISECONDS);
        }

        void InitPossessedEvents()
        {
            //events.Reset();

           //events.ScheduleEvent(EVENT_RECKLESS_CAHRGE_INITIALIZE, 10 * IN_MILLISECONDS);
        }
    };


    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_kazrajin_AI(pCreature);
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
        boss_sul_the_sandcrawler_AI(Creature* pCreature) :
            CouncilBaseAI(pCreature)
        {
        }

        void UpdateAI(uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;


            darkPowerEvents.Update(uiDiff);
            events.Update(uiDiff);

            switch (darkPowerEvents.ExecuteEvent())
            {
            case EVENT_DARK_POWER:
                DoCast(me, SPELL_DARK_POWER, true);
                ++uiDarkPowerCount;
                darkPowerEvents.ScheduleEvent(EVENT_DARK_POWER, 1 * IN_MILLISECONDS);
                break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 uiEventId = events.ExecuteEvent())
            {
                switch (uiEventId)
                {
                case EVENT_SAND_BOLT:
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(pTarget, SPELL_SAND_BOLT);
                    events.ScheduleEvent(EVENT_SAND_BOLT, 4000 + (rand() % 30 * 100));
                    break;

                case EVENT_QUICKSAND:
                {
                    Talk(TALK_SUL_QUICKSAND);
                    std::list<Player*> playerList;
                    std::list<Player*> tempList;
                    me->GetPlayerListInGrid(playerList, 150.f);

                    std::copy(std::begin(playerList), std::end(playerList), std::inserter(tempList, tempList.begin()));

                    playerList.remove_if([this](Player const* pPlayer) -> bool
                        {
                            return this->me->GetExactDist2d(pPlayer) < 15.0f; // Remove players that are closer than 15 yards
                        });

                    // Pick one of the players in the list if not empty
                    if (!playerList.empty())
                    {
                        if (Player* pPlayer = Trinity::Containers::SelectRandomContainerElement<std::list<Player*>>(playerList))
                            me->SummonCreature(MOB_LIVING_SAND, *pPlayer);
                    }
                    else if (!tempList.empty())
                    {
                        if (Player* pPlayer = Trinity::Containers::SelectRandomContainerElement<std::list<Player*>>(tempList))
                            me->SummonCreature(MOB_LIVING_SAND, *pPlayer);
                    }

                    events.ScheduleEvent(EVENT_QUICKSAND, 35 * IN_MILLISECONDS);
                    break;
                }

                case EVENT_SANDSTORM:
                    Talk(TALK_SPECIAL);
                    Talk(TALK_SUL_SANDSTORM);
                    DoCastAOE(SPELL_SAND_STORM);
                    events.ScheduleEvent(EVENT_SANDSTORM, 40 * IN_MILLISECONDS);
                    break;

                case EVENT_INCREASE_POWER:
                    me->ModifyPower(POWER_ENERGY, 3);
                    if (me->GetPower(POWER_ENERGY) < 100)
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
            darkPowerEvents.Reset();
            events.Reset();

            events.ScheduleEvent(EVENT_SAND_BOLT, 5 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_QUICKSAND, 35 * IN_MILLISECONDS);
        }

        void InitPossessedEvents()
        {
            events.Reset();

            events.ScheduleEvent(EVENT_SAND_BOLT, 5 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_QUICKSAND, 35 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_SANDSTORM, 10 * IN_MILLISECONDS);
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_sul_the_sandcrawler_AI(pCreature);
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
        boss_high_priestess_marli_AI(Creature* pCreature) :
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


        void DoAction(int32 action)
        {
            switch (action)
            {
                // normal
            case ACTION_I_WAS_INTERRUPTED:
            {
                events.CancelEvent(EVENT_WRATH_OF_THE_LOA);
                events.RescheduleEvent(EVENT_WRATH_OF_THE_LOA, 4 * IN_MILLISECONDS);
                break;
            }
            // dark phase
            case ACTION_I_WAS_INTERRUPTED_SECOND:
            {
                events.CancelEvent(EVENT_WRATH_OF_THE_LOA_DARK);
                events.RescheduleEvent(EVENT_WRATH_OF_THE_LOA_DARK, 4 * IN_MILLISECONDS);
                break;
            }
            }
        }

        void UpdateAI(uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            darkPowerEvents.Update(uiDiff);
            events.Update(uiDiff);

            switch (darkPowerEvents.ExecuteEvent())
            {
            case EVENT_DARK_POWER:
                DoCast(me, SPELL_DARK_POWER, true);
                ++uiDarkPowerCount;
                darkPowerEvents.ScheduleEvent(EVENT_DARK_POWER, 1 * IN_MILLISECONDS);
                break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 uiEventId = events.ExecuteEvent())
            {
                switch (uiEventId)
                {
                case EVENT_WRATH_OF_THE_LOA:
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM)) // Target is TARGET_UNIT_ENEMY
                        DoCast(pTarget, SPELL_WRATH_OF_THE_LOA);
                    events.ScheduleEvent(EVENT_WRATH_OF_THE_LOA, 3 * IN_MILLISECONDS);
                    break;

                case EVENT_BLESSED_LOA_SPIRIT:
                    // Check that we are not the only left councillor (otherwise it would be cheaty)
                    for (uint8 i = 0; i < 3; ++i)
                    {
                        if (Creature* pCouncillor = GetBossByEntry(uiBossEntries[i], me))
                        {
                            if (pCouncillor->IsAlive())
                            {
                                // Select a target now
                                std::list<Creature*> councillors = { GetFrostKingMalakk(me), GetKazrajin(me), GetSulTheSandcrawler(me) };
                                councillors.remove_if([](Creature const* pCouncil) -> bool { return pCouncil->isDead(); });
                                councillors.sort([](Creature const* first, Creature const* second) -> bool { return first->GetHealthPct() < second->GetHealthPct(); });

                                if (councillors.front())
                                    uiBlessedLoaSpiritBossGUIDs.push_back(councillors.front()->GetGUID());

                                // Cast after having init the list to be sure the guid has been set
                                DoCast(me, SPELL_BLESSED_LOA_SPIRIT);
                                events.ScheduleEvent(EVENT_BLESSED_LOA_SPIRIT, urand(20, 28) * IN_MILLISECONDS);


                                // Get out of the loop and break again; this way, we do not schedule
                                // the event if there is no other boss than Mar'li alive.
                                break;
                            }
                        }
                    }
                    break;

                case EVENT_WRATH_OF_THE_LOA_DARK:
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                        DoCast(pTarget, SPELL_WRATH_OF_THE_LOA_DARK); // Target is TARGET_UNIT_ENEMY
                    events.ScheduleEvent(EVENT_WRATH_OF_THE_LOA_DARK, 3 * IN_MILLISECONDS);
                    break;

                case EVENT_SHADOWED_LOA_SPIRIT:
                {
                    Talk(TALK_SPECIAL);
                    std::list<Player*> playerList;
                    me->GetPlayerListInGrid(playerList, 500.0f);

                    // Remove too close targets (otherwise player would be instantly killed)
                    playerList.remove_if([this](Player const* pPlayer) -> bool
                        {
                            // Instakill triggers when spirit is 6 yards away from player or less
                            // so remove players in a 10 yards range to let the other some time
                            // to try to get to safety.
                            return this->me->GetExactDist2d(pPlayer) <= 20.0f;
                        });

                    // List is empty, reschedule event, and break
                    if (playerList.empty())
                    {
                        events.ScheduleEvent(EVENT_SHADOWED_LOA_SPIRIT, urand(15, 25) * IN_MILLISECONDS);
                        break;
                    }
                    else
                    {
                        // Instead of computing again the player list, we'll send the
                        // guid of a randomly chosen target in the playerList to the
                        // summoned creature.
                        if (Player* pPlayer = Trinity::Containers::SelectRandomContainerElement(playerList))
                            uiShadowedSpiritPlayerGUIDs.push_back(pPlayer->GetGUID());

                        DoCast(me, SPELL_SHADOWED_LOA_SPIRIT);
                        events.ScheduleEvent(EVENT_SHADOWED_LOA_SPIRIT, urand(15, 25) * IN_MILLISECONDS);
                    }
                    break;
                }

                case EVENT_TWISTED_FATE:
                    //DoCastAOE(SPELL_TWISTED_FATE); // Automatically handle target selection in the SpellScript
                    if (Unit* target = SelectTarget(SELECT_TARGET_FARTHEST, 0, 100.0f, true))
                        target->CastSpell(target, SPELL_TWISTED_FATE_SUMMON_FIRST, true);
                    if (Unit* target = SelectTarget(SELECT_TARGET_NEAREST, 0, 30.0f, true))
                        target->CastSpell(target, SPELL_TWISTED_FATE_SUMMON_SECOND);
                    events.ScheduleEvent(EVENT_TWISTED_FATE, 30 * IN_MILLISECONDS);
                    break;

                case EVENT_INCREASE_POWER:
                    me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY) + 3);
                    if (me->GetPower(POWER_ENERGY) == 100)
                        DoAction(ACTION_DARK_POWER);
                    events.ScheduleEvent(EVENT_INCREASE_POWER, 3000, 0, 0);
                    break;
                    // force
                case EVENT_CHECK_POSSESED:
                    events.ScheduleEvent(EVENT_CHECK_POSSESED, 1000, 0, 0);
                    if (me->HasAura(SPELL_POSSESSED))
                        HandleDarkPhase();
                    break;
                case EVENT_CHECK_NONPOSSESED:
                    events.ScheduleEvent(EVENT_CHECK_NONPOSSESED, 1000, 0, 0);
                    if (!me->HasAura(SPELL_POSSESSED))
                        HandleNormalPhase();
                    break;
                default:
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }



        // Override JustDied() handler to clean the lists (it would use memory for nothing)
        void JustDied(Unit* pKiller)
        {
            uiShadowedSpiritPlayerGUIDs.clear();
            uiBlessedLoaSpiritBossGUIDs.clear();

            CouncilBaseAI::JustDied(pKiller);
        }

        void HandleNormalPhase()
        {
            darkPowerEvents.Reset();
            events.Reset();
            events.CancelEvent(EVENT_INCREASE_POWER);
            me->SetPower(POWER_ENERGY, 0);
            events.CancelEvent(EVENT_WRATH_OF_THE_LOA_DARK);
            events.CancelEvent(EVENT_SHADOWED_LOA_SPIRIT);
            events.CancelEvent(EVENT_CHECK_NONPOSSESED);
            events.ScheduleEvent(EVENT_CHECK_POSSESED, 1000, 0, 0);
            events.ScheduleEvent(EVENT_WRATH_OF_THE_LOA, 5 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_BLESSED_LOA_SPIRIT, 25 * IN_MILLISECONDS);
        }

        void HandleDarkPhase()
        {
            events.Reset();
            darkPowerEvents.Reset();
            events.ScheduleEvent(EVENT_INCREASE_POWER, 3000, 0, 0);
            events.ScheduleEvent(EVENT_CHECK_NONPOSSESED, 1000, 0, 0);
            events.ScheduleEvent(EVENT_WRATH_OF_THE_LOA_DARK, 5 * IN_MILLISECONDS);
            if (IsHeroic())
                events.ScheduleEvent(EVENT_TWISTED_FATE, 25 * IN_MILLISECONDS);
            else
                events.ScheduleEvent(EVENT_SHADOWED_LOA_SPIRIT, 20 * IN_MILLISECONDS);
        }

    private:
        // GUIDs of the players that will be chased by a Shadowed Loa Spirit
        // Always select the last in the list when a Shadowed Loa Spirit
        // is summoned.
        std::list<ObjectGuid> uiShadowedSpiritPlayerGUIDs;

        // GUIDS of the boss that will be chased by a Blessed Loa Spirit.
        // Like above, select the last in the list when a Blessed Loa Spirit
        // is summoned.
        std::list<ObjectGuid> uiBlessedLoaSpiritBossGUIDs;

        void InitStandartEvents()
        {
            darkPowerEvents.Reset();
            events.Reset();
            events.CancelEvent(EVENT_INCREASE_POWER);
            me->SetPower(POWER_ENERGY, 0);
            events.CancelEvent(EVENT_WRATH_OF_THE_LOA_DARK);
            events.CancelEvent(EVENT_SHADOWED_LOA_SPIRIT);
            events.ScheduleEvent(EVENT_CHECK_POSSESED, 1000, 0, 0);
            events.ScheduleEvent(EVENT_WRATH_OF_THE_LOA, 5 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_BLESSED_LOA_SPIRIT, 25 * IN_MILLISECONDS);
        }

        // no longer working, don't know why, handled above
        void InitPossessedEvents()
        {
            /*events.Reset();
            events.CancelEvent(EVENT_CHECK_POSSESED);
            events.ScheduleEvent(EVENT_WRATH_OF_THE_LOA_DARK, 5 * IN_MILLISECONDS);
            if(IsHeroic())
                events.ScheduleEvent(EVENT_TWISTED_FATE, 25 * IN_MILLISECONDS);
            else
                events.ScheduleEvent(EVENT_SHADOWED_LOA_SPIRIT, 20 * IN_MILLISECONDS);*/
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_high_priestess_marli_AI(pCreature);
    }
};


// Garajal
class mob_garajal : public CreatureScript
{
public:
    mob_garajal() : CreatureScript("mob_garajal") { }

    struct mob_garajal_AI : public BossAI
    {
        mob_garajal_AI(Creature* pCreature) : BossAI(pCreature, DATA_COUNCIL_OF_ELDERS)
        {
            me->SetReactState(REACT_PASSIVE);
            me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
            events.Reset();
        }

        std::list<ObjectGuid> m_lBossGuids;
        uint32 m_uiDeadCouncillors;

        void Reset() override
        {
        }

        void SetData(uint32 uiType, uint32 uiData) override
        {
            m_uiDeadCouncillors += uiData;
        }

        uint32 GetData(uint32 uiType) const
        {
            return m_uiDeadCouncillors;
        }

        void ResetFight()
        {
            if (instance->GetBossState(DATA_COUNCIL_OF_ELDERS) == NOT_STARTED)
                return;

            //mutex.acquire();

            FillBossGuids(m_lBossGuids);

            instance->SetBossState(DATA_COUNCIL_OF_ELDERS, NOT_STARTED);

            summons.DespawnAll();

            me->SetVisible(true);
            events.Reset();

            for (const ObjectGuid uiGuid : m_lBossGuids)
            {
                if (Creature* pBoss = ObjectAccessor::GetCreature(*me, uiGuid))
                {
                    if (pBoss->IsAlive())
                    {
                        if (pBoss->IsInCombat() && pBoss->AI())
                            pBoss->AI()->EnterEvadeMode(EVADE_REASON_NO_HOSTILES);
                    }
                    else
                    {
                        float x, y, z, o;
                        pBoss->GetHomePosition(x, y, z, o);
                        pBoss->NearTeleportTo(x, y, z, o);
                        pBoss->Respawn();
                        pBoss->SetFacingTo(o);
                    }
                }
            }

            DespawnCreatures();

            //mutex.release();
        }

        void FillBossGuids(std::list<ObjectGuid>& list)
        {
            m_uiDeadCouncillors = 0;

            list.clear();

            list.push_back(instance->GetObjectGuid(BOSS_COUNCIL_FROST_KING_MALAKK));
            list.push_back(instance->GetObjectGuid(BOSS_COUNCIL_HIGH_PRIESTESS_MARLI));
            list.push_back(instance->GetObjectGuid(BOSS_COUNCIL_SUL_THE_SANDCRAWLER));
            list.push_back(instance->GetObjectGuid(BOSS_COUNCIL_KAZRAJIN));
        }

        void FinishFight()
        {
            if (instance->GetBossState(DATA_COUNCIL_OF_ELDERS) != DONE)
                instance->SetBossState(DATA_COUNCIL_OF_ELDERS, DONE);

            /*
            if (IsHeroic())
            {
                if (Creature *pTwistedFateHelper = ObjectAccessor::GetCreature(*me, instance->GetData64(NPC_TWISTED_FATE_HELPER)))
                    pTwistedFateHelper->AI()->DoAction(ACTION_TWISTED_FATE_END_FIGHT);
            }
            */

            /*
            std::list<Player*> playerList;
            me->GetPlayerListInGrid(playerList, 500.0f);

            for (Player *pIter : playerList)
                pIter->RemoveAurasDueToSpell(SPELL_SHADOWED_SOUL); */

                // Something for Gara'jal here I suppose

            summons.DespawnAll();
            DespawnCreatures();
        }

        void BeginFight()
        {
            if (instance->GetBossState(DATA_COUNCIL_OF_ELDERS) == IN_PROGRESS)
                return;

            m_uiDeadCouncillors = 0;

            instance->SetBossState(DATA_COUNCIL_OF_ELDERS, IN_PROGRESS);

            if (Creature* kazrajin = GetKazrajin(me))
                if (kazrajin->HasAura(9454))
                {
                    Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                    for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                        if (Player* player = i->GetSource())
                            if (player->IsAlive())
                                player->Kill(player);
                    return;
                }

            FillBossGuids(m_lBossGuids);

            for (const ObjectGuid uiGuid : m_lBossGuids)
            {
                if (Creature* pBoss = ObjectAccessor::GetCreature(*me, uiGuid))
                {
                    /*
                    if (!pBoss->IsAlive())
                        pBoss->Respawn();
                    */
                    if (!pBoss->IsInCombat() && pBoss->AI())
                    {
                        DoZoneInCombat(pBoss, 150.f);
                        pBoss->AI()->DoAction(ACTION_COUNCILLORS_ENTER_COMBAT);
                    }
                }
            }

            Talk(0);
            me->SetVisible(false);
            if (Creature* pSoul = me->SummonCreature(MOB_GARA_JALS_SOUL, *me))
            {
                pSoul->AI()->DoAction(ACTION_ENTER_COMBAT);
            }
        }

        void RemoveShadowedSoul()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    if (player->HasAura(SPELL_SHADOWED_SOUL))
                        player->RemoveAura(SPELL_SHADOWED_SOUL);
                    // button too here
                    if (player->HasAura(SPELL_SOUL_FRAGMENT_PERIODIC))
                        player->RemoveAura(SPELL_SOUL_FRAGMENT_PERIODIC);
                }
        }

        void DoAction(int32 iAction)
        {
            switch (iAction)
            {
            case ACTION_FIGHT_BEGIN:
                BeginFight();
                if (Creature* pSoul = ObjectAccessor::GetCreature(*me, instance->GetObjectGuid(MOB_GARA_JALS_SOUL)))
                    pSoul->AI()->DoAction(ACTION_BOSS_TIMER_START);
                break;
            case ACTION_FIGHT_RESET:
                if (Creature* pSoul = ObjectAccessor::GetCreature(*me, instance->GetObjectGuid(MOB_GARA_JALS_SOUL)))
                    pSoul->AI()->DoAction(ACTION_BOSS_TIMER_WIPE);
                ResetFight();
                RemoveShadowedSoul();
                break;
            case ACTION_COUNCILLOR_DIED:
                ++m_uiDeadCouncillors;
                if (m_uiDeadCouncillors > 3)
                {
                    if (Creature* pSoul = ObjectAccessor::GetCreature(*me, instance->GetObjectGuid(MOB_GARA_JALS_SOUL)))
                        pSoul->AI()->DoAction(ACTION_BOSS_TIMER_DONE);
                    FinishFight();
                    RemoveShadowedSoul();
                    me->Kill(me);
                }
                else
                    if (Creature* pSoul = ObjectAccessor::GetCreature(*me, instance->GetObjectGuid(MOB_GARA_JALS_SOUL)))
                        pSoul->AI()->DoAction(ACTION_ENTER_COMBAT);
                break;
            default:
                break;
            }
        }

        void JustSummoned(Creature* pSummoned) override
        {
            summons.Summon(pSummoned);
        }

        void SummonedCreatureDespawn(Creature* pSummoned) override
        {
            summons.Despawn(pSummoned);
        }

        inline void DespawnCreatures() const
        {
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

            for (Creature* pMinion : minionsList)
                pMinion->DespawnOrUnsummon();
        }

        void UpdateAI(uint32 uiDiff)
        {
            if (events.Empty())
                return;

            events.Update(uiDiff);

            while (uint32 uiEventId = events.ExecuteEvent())
            {
                switch (uiEventId)
                {
                case EVENT_SUMMON_SOUL:
                    break;

                default:
                    break;
                }
            }
        }
    private:
        EventMap        events;
        InstanceScript* pInstance;
        /*    protected:
                ACE_Recursive_Thread_Mutex mutex;*/

    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_garajal_AI(pCreature);
    }
};

class guidVectorPredicate
{
public:
    guidVectorPredicate(ObjectGuid guid) : _guid(guid) {}

    bool operator()(ObjectGuid uiGuid) const
    {
        return uiGuid == _guid;
    }
private:
    ObjectGuid _guid;
};
// Garajal's Soul
class mob_garajals_soul : public CreatureScript
{
    enum eEvents : uint32
    {
        EVENT_NONE,
        EVENT_POSSESS
    };
public:
    mob_garajals_soul() : CreatureScript("mob_garajals_soul") { }

    class mob_garajals_soul_AI : public ScriptedAI
    {
    public:
        mob_garajals_soul_AI(Creature* pCreature) :
            ScriptedAI(pCreature), pInstance(pCreature->GetInstanceScript()), uiCouncillorEntry(0)
        {
            InitList(m_lBossGuids);
            timersStarted = false;
        }

        EventMap events;
        bool timersStarted;

        void InitList(std::list<ObjectGuid>& list)
        {
            list.push_back(pInstance->GetObjectGuid(BOSS_COUNCIL_FROST_KING_MALAKK));
            list.push_back(pInstance->GetObjectGuid(BOSS_COUNCIL_HIGH_PRIESTESS_MARLI));
            list.push_back(pInstance->GetObjectGuid(BOSS_COUNCIL_SUL_THE_SANDCRAWLER));
            list.push_back(pInstance->GetObjectGuid(BOSS_COUNCIL_KAZRAJIN));
        }

        void Reset()
        {
            events.Reset();
            uiCouncillorEntry = 0;
            me->SetReactState(REACT_PASSIVE);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->AddAura(SPELL_GARA_JALS_SOUL, me);
            me->SetWalk(false);
        }

        void EnterEvadeMode(EvadeReason w)
        {
            uiCouncillorEntry = 0; // Reset councillor entry to prevent bug
            me->GetMotionMaster()->MovementExpired(); // Reset movement so we will not continue to follow a councillor
        }

        bool Possess(Unit* pCreature)
        {
            DoCast(pCreature, SPELL_POSSESSED);
            me->EnterVehicle(pCreature, 0);

            return me->GetVehicle();
        }

        void MovementInform(uint32 uiType, uint32 uiPointId)
        {
            if (uiType != POINT_MOTION_TYPE)
                return;

            if (uiPointId == 1)
            {
                if (Creature* pNextCouncillor = ObjectAccessor::GetCreature(*me, pInstance->GetObjectGuid(uiCouncillorEntry)))
                {
                    if (!Possess(pNextCouncillor))
                        events.ScheduleEvent(EVENT_POSSESS, 200);
                }
            }
        }

        void UpdateAI(uint32 uiDiff)
        {
            if (me->GetVehicle())
                return;

            events.Update(uiDiff);

            switch (events.ExecuteEvent())
            {
            case EVENT_POSSESS:
                if (Creature* pNextCouncillor = GetNextCouncillor(uiCouncillorEntry))
                {
                    uiCouncillorEntry = pNextCouncillor->GetEntry();

                    float fX, fY;
                    GetPositionWithDistInOrientation(me, me->GetExactDist2d(pNextCouncillor) - 5.f, me->GetAngle(pNextCouncillor), fX, fY);

                    me->GetMotionMaster()->Clear(false);
                    me->GetMotionMaster()->MovePoint(1, fX, fY, me->GetPositionZ() + 0.8f);
                }
                else
                    events.ScheduleEvent(EVENT_POSSESS, 300);
            }
        }

        void DoAction(int32 iAction) override
        {
            switch (iAction)
            {
            case ACTION_ENTER_COMBAT:
                // Always possess Malakk first
                events.ScheduleEvent(EVENT_POSSESS, 3000);
                break;

            case ACTION_EXIT_COUNCILLOR:
                // Set Garajal visible again
                DoCast(SPELL_LINGERING_PRESENCE);
                me->ExitVehicle();
                // DoAction may be called after EnterEvadeMode() because possessed boss can reset 
                // after the call. Return to prevent following a new councillor.
                if (!uiCouncillorEntry || CheckBossState())
                    return;

                // In Heroic, each time Garajal is forced out of a councillor, he leaves
                // a Soul Fragment behind. (In fact there is no npc summoned, just a spell
                // cast).
                if (IsHeroic())
                    DoCastAOE(SPELL_SOUL_FRAGMENT_SELECTOR);

                // Select a new councillor
                events.ScheduleEvent(EVENT_POSSESS, 3000);
                break;

            case ACTION_BOSS_TIMER_START:
                if (timersStarted)
                    break;
                timersStarted = true;
    
                break;
            case ACTION_BOSS_TIMER_DONE:
                if (!timersStarted)
                    break;
                timersStarted = false;

                break;
            case ACTION_BOSS_TIMER_WIPE:
                timersStarted = false;
                break;

            default:
                break;
            }
        }

        bool CheckBossState()
        {
            for (ObjectGuid councGuid : m_lBossGuids)
            {
                Creature* pCouncillor = ObjectAccessor::GetCreature(*me, councGuid);

                if (pCouncillor && pCouncillor->IsAlive() && (!pCouncillor->IsInCombat() || pCouncillor->IsInEvadeMode()))
                    return true;
            }

            return false;
        }

    private:
        uint32          uiCouncillorEntry;
        InstanceScript* pInstance;
        std::list<ObjectGuid> m_lBossGuids;

        // Helper function to find the next boss to possess
        Creature* GetNextCouncillor(uint32 uiOriginalEntry = 0)
        {
            uint32      uiNextEntry = 0;
            float       fHealthNumber = 0.f;

            if (Creature* pGarajal = GetGarajal(me))
            {
                // We're the only councillor alive, no need to perform this check
                if (pGarajal->AI()->GetData(0) > 3)
                {
                    return NULL;
                }
            }

            // This is the first call, init original entry with the current councillor entry
            if (!uiOriginalEntry)
            {
                if (Creature* pMalakk = GetFrostKingMalakk(me))
                {
                    uiCouncillorEntry = BOSS_COUNCIL_FROST_KING_MALAKK;
                    return pMalakk;
                }
            }

            std::list<ObjectGuid> tempList;
            InitList(tempList);

            tempList.remove_if(guidVectorPredicate(pInstance->GetObjectGuid(uiCouncillorEntry)));
            for (auto const pGuid : tempList)
            {
                if (Creature* pCreature = ObjectAccessor::GetCreature(*me, pGuid))
                {
                    if (pCreature->IsAlive())
                    {
                        if (fHealthNumber < pCreature->GetHealthPct())
                        {
                            fHealthNumber = pCreature->GetHealthPct();
                            uiNextEntry = pCreature->GetEntry();
                        }
                    }
                }
            }

            if (Creature* pCreature = ObjectAccessor::GetCreature(*me, pInstance->GetObjectGuid(uiNextEntry)))
                return pCreature;

            return NULL;
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_garajals_soul_AI(pCreature);
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
        mob_living_sand_AI(Creature* pCreature) :
            ScriptedAI(pCreature), pInstance(pCreature->GetInstanceScript())
        {
        }

        EventMap events;

        void IsSummonedBy(Unit* pSummoner) override
        {
            me->AddAura(SPELL_QUICKSAND_AT_VISUAL_INIT, me);
            Initialize();
        }

        void Reset() override
        {
            events.Reset();
        }

        void Initialize()
        {
            me->RemoveAurasDueToSpell(SPELL_FORTIFIED);
            me->SetHealth(me->GetMaxHealth());
            me->SetReactState(REACT_PASSIVE);
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->AddUnitState(UNIT_STATE_ROOT);
            me->GetMotionMaster()->MovementExpired();
            me->GetMotionMaster()->MoveIdle();
            if (me->GetMap()->IsHeroic())
                me->AddAura(137629, me);
            events.ScheduleEvent(EVENT_QUICKSAND_PERIODIC, 1500);
        }

        void DoAction(int32 iAction) override
        {
            switch (iAction)
            {
            case ACTION_CREATE_LIVING_SAND:
                if (!me->HasAura(SPELL_QUICKSAND_AT_VISUAL) && !me->HasAura(SPELL_QUICKSAND_AT_VISUAL_INIT))
                {
                    DoCast(me, SPELL_FORTIFIED, true);
                }
                else
                {
                    me->RemoveAura(SPELL_QUICKSAND_AT_VISUAL_INIT);
                    me->RemoveAura(SPELL_QUICKSAND_AT_VISUAL);
                    //me->RemoveAllAuras();
                    events.ScheduleEvent(EVENT_ACTIVATE_SAND, 4000);
                    events.CancelEvent(EVENT_QUICKSAND_PERIODIC);
                }
                break;
            default:
                break;
            }
        }

        void UpdateAI(uint32 uiDiff)
        {
            events.Update(uiDiff);

            while (uint32 uiEventId = events.ExecuteEvent())
            {
                switch (uiEventId)
                {
                case EVENT_QUICKSAND_PERIODIC:
                {
                    std::list<Player*> playerList;
                    me->GetPlayerListInGrid(playerList, 100.f);

                    for (Player* pPlayer : playerList)
                    {
                        if (pPlayer->GetExactDist2d(me) < (7.4f + 1.0f))
                        {
                            if (Aura* pAura = pPlayer->GetAura(SPELL_QUICKSAND_PERIODIC_DAMAGES, me->GetGUID()))
                            {
                                pAura->RefreshDuration();
                            }
                            else
                                me->AddAura(SPELL_QUICKSAND_PERIODIC_DAMAGES, pPlayer);
                        }
                        else
                            pPlayer->RemoveAura(SPELL_QUICKSAND_PERIODIC_DAMAGES, me->GetGUID(), 0, AURA_REMOVE_BY_EXPIRE);
                        // Handle the root and cie in the AuraScript
                    }
                }
                events.ScheduleEvent(EVENT_QUICKSAND_PERIODIC, 500);
                break;
                case EVENT_ACTIVATE_SAND:
                    me->RemoveAura(SPELL_TREACHEROUS_GROUND);
                    me->RemoveAura(SPELL_TREACHEROUS_GROUND_SIZE);
                    if (me->HasAura(137629))
                        me->RemoveAura(137629);
                    //SET_SPEED(1.0f);
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                    me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                    me->ClearUnitState(UNIT_STATE_ROOT);
                    if (!me->IsInCombat())
                        DoZoneInCombat(me, 100.f);
                    else if (me->GetVictim())
                        me->GetMotionMaster()->MoveChase(me->GetVictim());
                    else if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        AttackStart(pTarget);
                    break;
                }
            }

            if (me->HasUnitState(UNIT_STATE_ROOT) || !UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

        void DamageTaken(Unit* pDealer, uint32& uiDamage)
        {
            if (me->HasUnitState(UNIT_STATE_ROOT))
            {
                uiDamage = 0;
                return;
            }

            if (uiDamage >= me->GetHealth())
            {
                uiDamage = 0;
                DoCast(me, SPELL_QUICKSAND_AT_VISUAL, true);
                Initialize();
            }
        }

    private:
        InstanceScript* pInstance;
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_living_sand_AI(pCreature);
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
        mob_blessed_loa_spirit_AI(Creature* pCreature) :
            ScriptedAI(pCreature), pInstance(pCreature->GetInstanceScript())
        {
            me->SetReactState(REACT_PASSIVE);
            me->ApplySpellImmune(0, IMMUNITY_ID, 108199, true); // Gorefiend's Grasp
            events.Reset();
            //me->SetSpeed(MOVE_RUN, 0.5f, true);
            //me->SetSpeed(MOVE_WALK, 0.5f, true);
        }

        void InitList(std::list<ObjectGuid>& list)
        {
            list.push_back(pInstance->GetObjectGuid(BOSS_COUNCIL_FROST_KING_MALAKK));
            //list.push_back(pInstance->GetData64(BOSS_COUNCIL_HIGH_PRIESTESS_MARLI));
            list.push_back(pInstance->GetObjectGuid(BOSS_COUNCIL_SUL_THE_SANDCRAWLER));
            list.push_back(pInstance->GetObjectGuid(BOSS_COUNCIL_KAZRAJIN));
        }

        void Reset() override
        {
            DoCast(me, SPELL_BLESSED_TRANSFORMATION);
        }

        // Override function to be sure there won't be any call to MoveChase (at least in AttackStart)
        void AttackStart(Unit* pTarget) { }

        void IsSummonedBy(Unit* pSummoner) override
        {
            HandleTargetSelection();
        }

        void JustDied(Unit* /*pkiller*/) override
        {
            me->DespawnOrUnsummon(5000);
        }

        void Move()
        {
            if (Creature* pCouncillor = ObjectAccessor::GetCreature(*me, uiTargetGuid))
                me->GetMotionMaster()->MovePoint(POINT_BLESSED_LOA_SPIRIT_COUNCILLOR, *pCouncillor);
            else
                HandleTargetSelection();
        }

        void HandleTargetSelection()
        {
            float fHealthNumber = 100.f;
            std::list<ObjectGuid> tempList;

            InitList(tempList);

            for (auto const pGuid : tempList)
            {
                if (Creature* pCreature = ObjectAccessor::GetCreature(*me, pGuid))
                {
                    if (!pCreature->IsAlive())
                        continue;

                    if (fHealthNumber >= pCreature->GetHealthPct())
                    {
                        fHealthNumber = pCreature->GetHealthPct();
                        uiTargetGuid = pGuid;
                    }
                }
            }

            events.RescheduleEvent(EVENT_BLESSED_GIFT, 20 * IN_MILLISECONDS);
            events.RescheduleEvent(EVENT_MOVE_COUNCILLOR, 500);
        }

        void UpdateAI(uint32 uiDiff)
        {
            events.Update(uiDiff);

            while (uint32 uiEventId = events.ExecuteEvent())
            {
                switch (uiEventId)
                {
                case EVENT_MOVE_COUNCILLOR:
                    Move();
                    break;
                case EVENT_BLESSED_GIFT:
                    if (Creature* pCouncillor = ObjectAccessor::GetCreature(*me, uiTargetGuid))
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

        void MovementInform(uint32 uiMotionType, uint32 uiMotionPointId) override
        {
            switch (uiMotionType)
            {
            case POINT_MOTION_TYPE:
                if (uiMotionPointId == POINT_BLESSED_LOA_SPIRIT_COUNCILLOR)
                {
                    if (Creature* pCouncillor = ObjectAccessor::GetCreature(*me, uiTargetGuid))
                    {
                        if (me->GetExactDist2d(pCouncillor) <= 5.f)
                        {
                            DoCast(pCouncillor, SPELL_BLESSED_GIFT);
                            me->DisappearAndDie();
                        }
                        else
                            events.RescheduleEvent(EVENT_MOVE_COUNCILLOR, 200);
                    }
                }
                break;

            case EFFECT_MOTION_TYPE:
                if (uiMotionPointId == EVENT_JUMP)
                {
                    if (Creature* pCouncillor = ObjectAccessor::GetCreature(*me, uiTargetGuid))
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
        InstanceScript* pInstance;
        ObjectGuid          uiTargetGuid; // GUID of the councillor we are moving toward
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_blessed_loa_spirit_AI(pCreature);
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
        mob_shadowed_loa_spirit_AI(Creature* pCreature) : ScriptedAI(pCreature), pInstance(pCreature->GetInstanceScript())
        {
        }

        void Reset() override
        {
            DoCast(me, SPELL_SHADOWED_TRANSFORMATION);
        }

        // Override function to be sure there won't be any call to MoveChase (at least in AttackStart)
        void AttackStart(Unit* pTarget) { }

        void IsSummonedBy(Unit* pSummoner) override
        {
            me->ApplySpellImmune(0, IMMUNITY_ID, 108199, true); // Gorefiend's Grasp
            events.ScheduleEvent(EVENT_TARGET_A_RANDOM_PLAYER, 1500, 0, 0);
            //HandleTargetSelection();
        }

        // no longer used, i'm using my scripts
        /*void Move()
        {
            if (Player *pTarget = ObjectAccessor::GetPlayer(*me, uiTargetGuid))
            {
                if (pTarget->IsAlive())
                {
                    Position pos;
                    pTarget->GetPosition(&pos);
                    me->GetMotionMaster()->MovePoint(POINT_BLESSED_LOA_SPIRIT_COUNCILLOR, pos);
                    events.ScheduleEvent(EVENT_MOVE_COUNCILLOR, 500);
                }
                else
                {
                    if (Aura* pAura = pTarget->GetAura(SPELL_MARKED_SOUL, me->GetGUID()))
                        pAura->Remove(AURA_REMOVE_BY_DEATH);

                    HandleTargetSelection();
                }
            }
            else
                HandleTargetSelection();
        }

        void HandleTargetSelection()
        {
            //DoCast(SPELL_MARKED_SOUL);

            std::list<Player*> players;
            GetPlayerListInGrid(players, me, 300.f);

            if (!players.empty())
            {
                for (auto const pPlayer : players)
                {
                    SetTargetGuid(pPlayer->GetGUID());
                    me->AddAura(SPELL_MARKED_SOUL, pPlayer);
                    me->AddThreat(pPlayer, 9999999999.9f);
                    break;
                }
            }

            events.Reset();
            events.ScheduleEvent(EVENT_MOVE_COUNCILLOR, 500);
            events.ScheduleEvent(EVENT_SHADOWED_GIFT, 20 * IN_MILLISECONDS);
        }

        void SetTargetGuid(uint64 guid)
        {
            uiTargetGuid = guid;
        }*/

        void SetGUID(ObjectGuid guid, int32 id = 0)
        {
            playerGuid = guid;
        }

        void UpdateAI(uint32 uiDiff)
        {
            events.Update(uiDiff);

            while (uint32 uiEventId = events.ExecuteEvent())
            {
                switch (uiEventId)
                {
                    //case EVENT_MOVE_COUNCILLOR:
                   //     Move();
                   //     break;
                case EVENT_TARGET_A_RANDOM_PLAYER:
                {
                    if (Unit* player = SelectTarget(SELECT_TARGET_RANDOM, 0, 80.0f, true))
                    {
                        me->AddAura(SPELL_MARKED_SOUL, player);
                        me->AI()->AttackStart(player);
                        //playerGuid = player->GetGUID();
                        me->AddThreat(player, 999999999.9f);
                        events.ScheduleEvent(EVENT_SHADOWED_GIFT, 20 * IN_MILLISECONDS);
                        events.ScheduleEvent(EVENT_MOVE_TO_PLAYER, 1000, 0, 0);
                        break;
                    }
                }
                case EVENT_MOVE_TO_PLAYER:
                {
                    if (Unit* target = me->GetVictim())
                    {
                        if (!target || target->isDead())
                        {
                            me->DespawnOrUnsummon();
                            return;
                        }

                        if (me->GetDistance(target) < 4.0f)
                        {
                            DoCast(target, SPELL_SHADOWED_GIFT, true);
                            if (Player* player = ObjectAccessor::FindPlayer(playerGuid))
                            {
                                player->RemoveAurasDueToSpell(SPELL_MARKED_SOUL);
                            }
                        }
                        me->Kill(target, true);
                        me->Kill(me);
                    }
                    events.ScheduleEvent(EVENT_MOVE_TO_PLAYER, 1000, 0, 0);
                    break;
                }
                case EVENT_SHADOWED_GIFT:
                    if (Player* player = ObjectAccessor::FindPlayer(playerGuid))
                    {
                        if (player->IsAlive())
                        {
                            DoCast(me, SPELL_SHADOWED_TIME_OUT);
                            me->GetMotionMaster()->MovementExpired();
                            me->GetMotionMaster()->MoveJump(*player, 42.0f, 42.0f, 5050);
                            return;
                        }
                    }
                    // HandleTargetSelection();
                    break;

                default:
                    break;
                }
            }
        }

        void MovementInform(uint32 uiMotionType, uint32 uiMotionPointId) override
        {
            // no longer used POINT_BLOSSED_LOA_SPIRIT_CONCILOR for this AI, handled in updateAI via event
            if (uiMotionPointId == POINT_BLESSED_LOA_SPIRIT_COUNCILLOR)
            {
                if (Player* player = ObjectAccessor::FindPlayer(playerGuid))
                {
                    if (me->GetExactDist2d(player) <= 6.f && player->IsAlive())
                    {
                        DoCast(player, SPELL_SHADOWED_GIFT, true);
                        player->RemoveAurasDueToSpell(SPELL_MARKED_SOUL);
                        me->DisappearAndDie();
                        me->Kill(player, true);
                    }
                    else
                        events.RescheduleEvent(EVENT_MOVE_COUNCILLOR, 200);
                }
            }

            if (uiMotionPointId == 5050)
            {
                if (Player* player = ObjectAccessor::FindPlayer(playerGuid))
                {
                    DoCast(player, SPELL_SHADOWED_GIFT);
                    player->RemoveAurasDueToSpell(SPELL_MARKED_SOUL);
                    me->DisappearAndDie();
                    me->Kill(player, true);
                }
            }

        }

        void JustDied(Unit* pKiller) override
        {
            if (Player* player = ObjectAccessor::FindPlayer(playerGuid))
            {
                player->RemoveAurasDueToSpell(137422);
            }

            me->DespawnOrUnsummon(5000);
        }

    private:
        EventMap        events;
        InstanceScript* pInstance;
        ObjectGuid          playerGuid; // GUID of the councillor we are moving toward
    };


    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_shadowed_loa_spirit_AI(pCreature);
    }
};


// Helper to handle Twisted Fate correctly
class mob_twisted_fate_helper : public CreatureScript
{
public:
    mob_twisted_fate_helper() : CreatureScript("mob_twisted_fate_helper") { }

    struct TwistedFate
    {
        ObjectGuid uiFirstPlayerGuid; // Guid of the first player of the Twisted Fate
        ObjectGuid uiSecondPlayerGuid; // Guid of the second player of the Twisted Fate

        ObjectGuid uiFirstTwistedFateGuid; // Guid of the first Twisted Fate
        ObjectGuid uiSecondTwistedFateGuid; // Guid of the second Twisted Fate

    };

    class mob_twisted_fate_helper_AI : public ScriptedAI
    {
    public:
        mob_twisted_fate_helper_AI(Creature* pCreature) :
            ScriptedAI(pCreature), pInstance(pCreature->GetInstanceScript())
        {
            twistedFatesList.clear();
        }

        void Reset() override
        {
            twistedFatesList.clear();
        }

        void AddTwistedFate(TwistedFate* pFate)
        {
            twistedFatesList.push_back(pFate);
        }

        // Link a player and a twisted fate (only used for the second mob)
        void Link(ObjectGuid uiPlayerGuid, ObjectGuid uiFateGuid)
        {
            if (twistedFatesList.empty())
                return;

            // Link the two twisted fates together == send the guid of the other to each one,
            // init them correctly, start their movement toward each other.
            if (TwistedFate* pFate = twistedFatesList.back())
            {
                pFate->uiSecondPlayerGuid = uiPlayerGuid;
                pFate->uiSecondTwistedFateGuid = uiFateGuid;

                Creature* pFirst = ObjectAccessor::GetCreature(*me, pFate->uiFirstTwistedFateGuid),
                    * pSecond = ObjectAccessor::GetCreature(*me, pFate->uiSecondTwistedFateGuid);

                if (!pFirst || !pSecond)
                    return;

                // If there are not enough players, remove the creatures
                if (pFate->uiSecondPlayerGuid == pFate->uiFirstPlayerGuid)
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
        void Unlink(ObjectGuid uiGuid)
        {
            if (twistedFatesList.empty())
                return;

            for (TwistedFate* pFate : twistedFatesList)
            {
                if (pFate->uiFirstTwistedFateGuid == uiGuid || pFate->uiSecondTwistedFateGuid == uiGuid)
                {
                    delete pFate;
                    return;
                }
            }
        }

        void DoAction(int32 iAction) override
        {
            switch (iAction)
            {
                // Fight ended, delete dynamically allocated memory
            case ACTION_TWISTED_FATE_END_FIGHT:
                for (auto i : twistedFatesList)
                    delete i;
                break;

            default:
                break;
            }
        }

    private:
        InstanceScript* pInstance;

        std::list<TwistedFate*> twistedFatesList; // Store dynamically allocated twisted fate helpers
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_twisted_fate_helper_AI(pCreature);
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
        mob_twisted_fate_AI(Creature* pCreature) :
            ScriptedAI(pCreature), pInstance(pCreature->GetInstanceScript())
        {
            me->SetReactState(REACT_PASSIVE);
        }

        // Add a new TwistedFate_t to the helper
        void IsSummonedBy(Unit* pSummoner) override
        {
            Creature* pHelper = ObjectAccessor::GetCreature(*me, pInstance->GetObjectGuid(NPC_TWISTED_FATE_HELPER));
            if (!pHelper)
            {
                me->DisappearAndDie();
                return;
            }

            TwistedFateHelperAI* pHelperAI = dynamic_cast<TwistedFateHelperAI*>(pHelper->AI());
            if (!pHelperAI)
            {
                me->DisappearAndDie();
                return;
            }

            switch (me->GetEntry())
            {
                // Create a new TwistedFate_t
            case MOB_TWISTED_FATE_FIRST:
                //pHelperAI->AddTwistedFate(new TwistedFate_t(pSummoner ? pSummoner->GetGUID() : ObjectGuid(nullptr), me->GetGUID()));
                DoCastAOE(SPELL_TWISTED_FATE_FORCE_SUMMON_SECOND); // Force the most distant player to summon the second twisted fate
                break;

                // Finalize it with the second npc and launch everything
            case MOB_TWISTED_FATE_SECOND:
                //pHelperAI->Link(pSummoner ? pSummoner->GetGUID(), me->GetGUID());
                break;
            }
        }

        void SetGUID(ObjectGuid uiGuid, int32 uiIndex) override
        {
            if (uiIndex == DATA_TWISTED_FATE_GUID)
                uiOtherTwistedFateGuid = uiGuid;
        }

        void JustDied(Unit* pKiller) override
        {
            // Do not do something wierd when the other is dead => free memory
            // of the helper.
            if (bOtherTwistedFateDied)
            {
                if (Creature* pHelper = ObjectAccessor::GetCreature(*me, pInstance->GetObjectGuid(NPC_TWISTED_FATE_HELPER)))
                {
                    if (TwistedFateHelperAI* pHelperAI = dynamic_cast<TwistedFateHelperAI*>(pHelper->AI()))
                        pHelperAI->Unlink(me->GetGUID());
                }
            }
            else
            {
                // When a Twisted Fate dies, the other stops and then begins to cast an AOE every 3 seconds
                if (Creature* pOther = ObjectAccessor::GetCreature(*me, uiOtherTwistedFateGuid))
                    pOther->AI()->DoAction(ACTION_OTHER_TWISTED_FATE_DIED);
            }

        }

        uint32 GetData(uint32 uiIndex) const
        {
            if (uiIndex == DATA_TWISTED_FATE_OTHER_DIED)
                return (uint32)bOtherTwistedFateDied;

            return 0;
        }

        void DoAction(int32 iAction) override
        {
            switch (iAction)
            {
                // Stop moving and set bOtherTwistedFateDied to true so the aura script will be able
                // to compute the amount of damages correctly.
            case ACTION_OTHER_TWISTED_FATE_DIED:
                me->StopMoving();
                bOtherTwistedFateDied = true;
                break;

            default:
                break;
            }
        }

    protected:
        InstanceScript* pInstance;
        ObjectGuid          uiOtherTwistedFateGuid; // Guid of the other twisted fate

        // Boolean to control whenever we are in the linked phase or not,
        // and used to compute correctly the amount of damages of the
        // SPELL_TWISTED_FATE_DAMAGES.
        bool            bOtherTwistedFateDied;
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_twisted_fate_AI(pCreature);
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
            if (GetOwner() && GetOwner()->ToCreature())
            {
                Creature* pOwner = GetOwner()->ToCreature();
                pOwner->AI()->DoAction(ACTION_SET_POSSESSED);
            }
        }

        void HandleRemove(AuraEffect const* pAuraEffect, AuraEffectHandleModes eMode)
        {
            if (GetOwner())
            {
                if (GetOwner()->ToCreature())
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
            OnEffectApply += AuraEffectApplyFn(spell_garajal_possessed_AuraScript::HandleApply, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(spell_garajal_possessed_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
            // OnEffectPeriodic    += AuraEffectPeriodicFn(spell_garajal_possessed_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const
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
            Player* pOwner;
            if (GetOwner() && GetOwner()->ToPlayer())
            {
                pOwner = GetOwner()->ToPlayer();
                // Stun when stacks reach 15
                if (GetStackAmount() == 15)
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

    AuraScript* GetAuraScript() const
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
        PrepareSpellScript(spell_malakk_biting_cold_SpellScript)

            void HandleEffectHitTarget(SpellEffIndex effIndex)
        {
            // Since spell selects one random target, there is no way we can handle this another way
            if (Unit* pHit = GetHitUnit())
            {
                if (Unit* pCaster = GetCaster())
                {
                    pCaster->CastSpell(pHit, SPELL_BITING_COLD_PERIODIC_DAMAGES, true);
                    pCaster->CastSpell(pHit, SPELL_BITING_COLD_PERIODIC_DUMMY, true);
                }
            }
        }

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            Unit* caster = GetCaster();

            if (!caster || targets.empty())
                return;

            // Remove specific specs
            for (std::list<WorldObject*>::iterator itr = targets.begin(); itr != targets.end();)
            {
                if (Player* player = (*itr)->ToPlayer())
                {
                    // Check specs
                    uint32 spec = player->GetSpecializationId();
                    bool checkSpec = false;

                    switch (spec)
                    {
                    case TALENT_SPEC_DRUID_BEAR:
                    case TALENT_SPEC_PALADIN_PROTECTION:
                    case TALENT_SPEC_WARRIOR_PROTECTION:
                    case TALENT_SPEC_DEATHKNIGHT_BLOOD:
                    case TALENT_SPEC_MONK_BREWMASTER:
                        checkSpec = true;
                        break;
                    }

                    if (checkSpec)
                    {
                        targets.erase(itr++);
                        continue;
                    }
                }
                ++itr;
            }
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_malakk_biting_cold_SpellScript::HandleEffectHitTarget, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            //OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_malakk_biting_cold_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_TARGET_ANY);
        }
    };

    SpellScript* GetSpellScript() const
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
            if (!GetOwner())
                return;

            // Stack amount can be reduced when players are standing close to the owner
            if (Player* pOwner = GetOwner()->ToPlayer())
            {
                std::list<Player*> playerList;
                pOwner->GetPlayerListInGrid(playerList, 4.0f);

                playerList.remove(pOwner); // Remove self
                playerList.remove_if([](Player const* pPlayer) -> bool { return pPlayer->HasAura(SPELL_CHILLED_TO_THE_BONE); }); // Remove players with Chilled to the Bone

                uint32 uiReduceAmount = 0;

                switch (pOwner->GetMap()->GetDifficultyID())
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
                if (GetStackAmount() <= uiReduceAmount) // Indeed, if the update was done in real time, this should never happen
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

    AuraScript* GetAuraScript() const
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
        PrepareSpellScript(spell_malakk_frostbite_SpellScript)

            // Handler to select target (cause TARGET_UNIT_SRC_AREA_ENTRY doesn't work fine)
            void SelectTarget(std::list<WorldObject*>& targets)
        {
            targets.clear();
            if (Unit* pCaster = GetCaster())
            {
                std::list<Player*> playerList;
                pCaster->GetPlayerListInGrid(playerList, 500.0f);

                if (!playerList.empty())
                    targets.push_back(Trinity::Containers::SelectRandomContainerElement(playerList));
            }
        }

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            Unit* caster = GetCaster();

            if (!caster || targets.empty())
                return;

            // Remove specific specs
            for (std::list<WorldObject*>::iterator itr = targets.begin(); itr != targets.end();)
            {
                if (Player* player = (*itr)->ToPlayer())
                {
                    // Check specs
                    uint32 spec = player->GetSpecializationId();
                    bool checkSpec = false;

                    switch (spec)
                    {
                    case TALENT_SPEC_DRUID_BEAR:
                    case TALENT_SPEC_DRUID_CAT:
                    case TALENT_SPEC_WARRIOR_FURY:
                    case TALENT_SPEC_WARRIOR_ARMS:
                    case TALENT_SPEC_PALADIN_PROTECTION:
                    case TALENT_SPEC_PALADIN_RETRIBUTION:
                    case TALENT_SPEC_WARRIOR_PROTECTION:
                    case TALENT_SPEC_DEATHKNIGHT_UNHOLY:
                    case TALENT_SPEC_DEATHKNIGHT_FROST:
                    case TALENT_SPEC_DEATHKNIGHT_BLOOD:
                    case TALENT_SPEC_ROGUE_SUBTLETY:
                    case TALENT_SPEC_ROGUE_COMBAT:
                    case TALENT_SPEC_ROGUE_ASSASSINATION:
                    case TALENT_SPEC_HUNTER_MARKSMAN:
                    case TALENT_SPEC_HUNTER_SURVIVAL:
                    case TALENT_SPEC_HUNTER_BEASTMASTER:
                    case TALENT_SPEC_MONK_BREWMASTER:
                    case TALENT_SPEC_MONK_BATTLEDANCER:
                    case TALENT_SPEC_SHAMAN_ENHANCEMENT:
                        checkSpec = true;
                        break;
                    }

                    if (checkSpec)
                    {
                        targets.erase(itr++);
                        continue;
                    }
                }
                ++itr;
            }
        }

        // Handler to apply the visual
        void HandleOnHit(SpellEffIndex eEffIndex)
        {
            if (Unit* pHit = GetHitUnit())
            {
                if (Unit* pCaster = GetCaster())
                {
                    pHit->CastSpell(pHit, SPELL_FROSTBITE_SCREEN_EFFECT, true);
                    pCaster->CastSpell(pHit, SPELL_FROSTBITE_PERIODIC_DAMAGES, true);

                    if (pCaster->ToCreature()->AI())
                        pCaster->ToCreature()->AI()->Talk(TALK_MALAKK_FROSTBITE, pHit);
                }
            }
        }

        void Register()
        {
            //OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_malakk_frostbite_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
            //OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_malakk_frostbite_SpellScript::SelectTarget, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
            OnEffectHitTarget += SpellEffectFn(spell_malakk_frostbite_SpellScript::HandleOnHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const
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
        PrepareSpellScript(spell_malakk_frostbite_allies_SpellScript)

            void FilterTargets(std::list<WorldObject*>& targets)
        {
            targets.remove_if(notPlayerPredicate());
        }

        int32 value;

        bool Load()
        {
            if (GetCaster())
            {
                value = GetCaster()->GetMap()->IsHeroic() ? 60000 : 22000;
                return true;
            }
            return false;
        }

        void HandleEffectHitTarget(SpellEffIndex eff_idx)
        {
            Unit* pTarget = GetHitUnit();
            Unit* pCaster = GetCaster();

            if (!pTarget || !pCaster)
                return;

            if (Aura* pAura = pCaster->GetAura(SPELL_FROSTBITE_PERIODIC_DAMAGES))
            {
                SetHitDamage(GetHitDamage() + pAura->GetStackAmount() * value);
            }
        }

        void HandleOnCast()
        {
            // Cast Body Heat on heroic
            if (Unit* pCaster = GetCaster())
            {
                if (pCaster->GetMap()->IsHeroic())
                {
                    pCaster->CastSpell(pCaster, SPELL_BODY_HEAT, true);
                }
            }
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_malakk_frostbite_allies_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
            OnEffectHitTarget += SpellEffectFn(spell_malakk_frostbite_allies_SpellScript::HandleEffectHitTarget, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            OnCast += SpellCastFn(spell_malakk_frostbite_allies_SpellScript::HandleOnCast);
        }
    };

    SpellScript* GetSpellScript() const
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
        PrepareSpellScript(spell_malakk_body_heat_SpellScript)

            void SelectTargets(std::list<WorldObject*>& targets)
        {
            std::list<Player*> playerList;
            if (GetCaster())
                GetCaster()->GetPlayerListInGrid(playerList, 4.0f);

            if (!playerList.empty() && playerList.size() > 1)
            {
                targets.clear();
                playerList.remove(GetCaster()->ToPlayer());

                for (Player* iter : playerList)
                    targets.push_back(iter);
            }
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_malakk_body_heat_SpellScript::SelectTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_malakk_body_heat_SpellScript();
    }

    class spell_malakk_body_heat_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_malakk_body_heat_AuraScript);

        void HandleEffectRemove(AuraEffect const* pAuraEffect, AuraEffectHandleModes eMode)
        {
            if (!GetOwner())
                return;

            if (Player* pOwner = GetOwner()->ToPlayer())
                pOwner->CastSpell(pOwner, SPELL_CHILLED_TO_THE_BONE, true);
        }

        void Register()
        {
            OnEffectRemove += AuraEffectRemoveFn(spell_malakk_body_heat_AuraScript::HandleEffectRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
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
        PrepareSpellScript(spell_kazrajin_reckless_charge_SpellScript)

            void HandleCast(SpellEffIndex eff_idx)
        {
            if (Unit* pCaster = GetCaster())
            {
                if (Creature* pKazrajin = pCaster->ToCreature())
                {
                    std::list<Player*> players;
                    GetPlayerListInGrid(players, pKazrajin, 100.f);

                    for (auto const pPlayer : players)
                    {
                        if (!pPlayer->HasAura(SPELL_RECKLESS_CHARGE_FACE))
                            continue;
                        pKazrajin->CastSpell(pKazrajin, SPELL_RECKLESS_CHARGE_SOUND, true);
                        pPlayer->RemoveAurasDueToSpell(SPELL_RECKLESS_CHARGE_FACE);
                        // Compute position of landing
                        float fDist = pKazrajin->GetExactDist2d(pPlayer) - 3.f; // Remove 5 yards to continue rolling
                        float fAngle = pKazrajin->GetAngle(pPlayer);
                        float fX, fY;
                        GetPositionWithDistInOrientation(pKazrajin, fDist, fAngle, fX, fY);

                        uint8 m_pointCount = ((uint8)fDist / 3) + 1;

                        for (uint8 i = 0; i < m_pointCount; ++i)
                        {
                            float x, y;
                            GetPositionWithDistInOrientation(pKazrajin, fDist - (i * 3), fAngle, x, y);
                            pKazrajin->CastSpell(x, y, pKazrajin->GetPositionZ() + 0.8f, NULL, true);
                        }

                        if (pKazrajin->HasUnitState(UNIT_STATE_ROOT))
                            pKazrajin->ClearUnitState(UNIT_STATE_ROOT);
                        pKazrajin->GetMotionMaster()->MoveCharge(fX, fY, pPlayer->GetPositionZ(), 42.f, POINT_RECKLESS_CHARGE_LAND);
                    }
                }
            }
        }

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            Unit* caster = GetCaster();

            if (!caster || targets.empty())
                return;

            // Remove specific specs
            for (std::list<WorldObject*>::iterator itr = targets.begin(); itr != targets.end();)
            {
                if (Player* player = (*itr)->ToPlayer())
                {
                    // Check specs
                    uint32 spec = player->GetSpecializationId();
                    bool checkSpec = false;

                    switch (spec)
                    {
                    case TALENT_SPEC_DRUID_BEAR:
                    case TALENT_SPEC_DRUID_CAT:
                    case TALENT_SPEC_WARRIOR_FURY:
                    case TALENT_SPEC_WARRIOR_ARMS:
                    case TALENT_SPEC_PALADIN_PROTECTION:
                    case TALENT_SPEC_PALADIN_RETRIBUTION:
                    case TALENT_SPEC_WARRIOR_PROTECTION:
                    case TALENT_SPEC_DEATHKNIGHT_UNHOLY:
                    case TALENT_SPEC_DEATHKNIGHT_FROST:
                    case TALENT_SPEC_DEATHKNIGHT_BLOOD:
                    case TALENT_SPEC_ROGUE_SUBTLETY:
                    case TALENT_SPEC_ROGUE_COMBAT:
                    case TALENT_SPEC_ROGUE_ASSASSINATION:
                    case TALENT_SPEC_HUNTER_MARKSMAN:
                    case TALENT_SPEC_HUNTER_SURVIVAL:
                    case TALENT_SPEC_HUNTER_BEASTMASTER:
                    case TALENT_SPEC_MONK_BREWMASTER:
                    case TALENT_SPEC_MONK_BATTLEDANCER:
                    case TALENT_SPEC_SHAMAN_ENHANCEMENT:
                        checkSpec = true;
                        break;
                    }

                    if (checkSpec)
                    {
                        targets.erase(itr++);
                        continue;
                    }
                }
                ++itr;
            }
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_kazrajin_reckless_charge_SpellScript::HandleCast, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_kazrajin_reckless_charge_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_CASTER);
        }
    };

    class spell_kazrajin_reckless_charge_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_kazrajin_reckless_charge_AuraScript);

            void HandleApply(AuraEffect const* pAuraEffect, AuraEffectHandleModes eMode)
        {
            GetCaster()->AddAura(137121, GetCaster());
        }

        void HandleRemove(AuraEffect const* AuraEffct, AuraEffectHandleModes mode)
        {
            GetCaster()->RemoveAura(137121);
            GetCaster()->RemoveAurasDueToSpell(137117);
            // EXTRA FUCKING CHECKs 
            if (GetCaster()->HasAura(137117))
                GetCaster()->RemoveAura(137117);
        }

        void Register()
        {
            OnEffectApply += AuraEffectApplyFn(spell_kazrajin_reckless_charge_AuraScript::HandleApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(spell_kazrajin_reckless_charge_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_kazrajin_reckless_charge_AuraScript();
    }

    SpellScript* GetSpellScript() const
    {
        return new spell_kazrajin_reckless_charge_SpellScript();
    }
};

class withinRangePredicate
{
public:
    withinRangePredicate(Unit* _caster) : caster(_caster) {}

    bool operator()(WorldObject* target) const
    {
        if (target && target->GetExactDist2d(caster) < 9.f)
            return true;
        return false;
    }

private:
    Unit* caster;
};

class spell_kazrajin_reckless_charge_targeting : public SpellScriptLoader
{
public:
    spell_kazrajin_reckless_charge_targeting() : SpellScriptLoader("spell_kazrajin_reckless_charge_targeting") {}

    class spell_impl : public SpellScript
    {
        PrepareSpellScript(spell_impl);

        void SelectTargets(std::list<WorldObject*>& targets)
        {
            std::list<WorldObject*>tempTargets;
            std::copy(std::begin(targets), std::end(targets), std::inserter(tempTargets, tempTargets.begin()));

            if (Unit* caster = GetCaster())
            {
                targets.remove_if(withinRangePredicate(caster));
            }

            if (targets.size() > 1)
                Trinity::Containers::RandomResize(targets, 1);
            else if (targets.empty())
                std::copy(std::begin(tempTargets), std::end(tempTargets), std::inserter(targets, targets.begin()));
        }

        void HandleEffectHitTarget(SpellEffIndex eff_idx)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();

            if (!caster || !target)
                return;

            caster->AddAura(SPELL_RECKLESS_CHARGE_FACE, target);
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_impl::SelectTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            OnEffectHitTarget += SpellEffectFn(spell_impl::HandleEffectHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_impl();
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
            if (!GetOwner())
                return;

            // Stunned on aura apply
            if (Creature* pOwner = GetOwner()->ToCreature())
            {
                pOwner->AddUnitState(UNIT_STATE_ROOT);
                pOwner->SetControlled(true, UNIT_STATE_STUNNED);
            }
        }

        void HandleOnProc(const AuraEffect* aurEff, ProcEventInfo& eventInfo)
        {
            if (Unit* pCaster = eventInfo.GetActor())
            {
                if (!eventInfo.GetDamageInfo())
                    return;

                int32 uiDamages = eventInfo.GetDamageInfo()->GetDamage() * 0.4f; // 40% of damages returned to the player

                if (Unit* pVictim = eventInfo.GetActionTarget())
                {
                    pVictim->CastCustomSpell(pCaster, SPELL_OVERLOAD_DAMAGES, &uiDamages, NULL, NULL, true);
                    pVictim->CastSpell(pCaster, SPELL_OVERLOAD_VISUAL, true);
                }
            }
        }

        void HandleEffectRemove(AuraEffect const* pAuraEffect, AuraEffectHandleModes eMode)
        {
            if (!GetOwner())
                return;

            // Unstunned on aura remove
            if (Creature* pOwner = GetOwner()->ToCreature())
            {
                pOwner->ClearUnitState(UNIT_STATE_ROOT);
                pOwner->SetControlled(false, UNIT_STATE_STUNNED);
            }
        }

        void Register()
        {
            // Note: there is no stunning spell, I'm quite sure of that... even if
            // it is really wierd.
            OnEffectApply += AuraEffectApplyFn(spell_kazrajin_overload_AuraScript::HandleEffectApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectProc += AuraEffectProcFn(spell_kazrajin_overload_AuraScript::HandleOnProc, EFFECT_0, SPELL_AURA_DUMMY);
            OnEffectRemove += AuraEffectRemoveFn(spell_kazrajin_overload_AuraScript::HandleEffectRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
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
            if (!GetOwner())
                return;

            // Stunned on aura apply
            if (Creature* pOwner = GetOwner()->ToCreature())
                pOwner->SetControlled(true, UNIT_STATE_STUNNED);
        }

        // omg this shit isn't working, made a new (WORKING) one below
        void HandlePeriodic(AuraEffect const* pAuraEffect)
        {
            if (!GetOwner())
                return;

            if (Creature* pOwner = GetOwner()->ToCreature())
            {
                int32 uiDamagesInPastSecs = (int32)pOwner->AI()->GetData(DATA_DAMAGES_PAST_SEC) * 0.05f; // 5% of damages taken in past sec
                int32 uiDamagesInPastSecsHEROIC = (int32)pOwner->AI()->GetData(DATA_DAMAGES_PAST_SEC) * 0.10f; // 10%
                pOwner->AI()->DoAction(ACTION_RESET_DAMAGES);
                if (pOwner->GetMap()->IsHeroic())
                    pOwner->CastCustomSpell(pOwner, SPELL_DISCHARGE_DAMAGES, &uiDamagesInPastSecsHEROIC, NULL, NULL, true);
                else
                    pOwner->CastCustomSpell(pOwner, SPELL_DISCHARGE_DAMAGES, &uiDamagesInPastSecs, NULL, NULL, true);
                pOwner->AI()->DoCastAOE(SPELL_DISCHARGE_VISUAL);
            }
        }

        void OnProc(const AuraEffect* aurEff, ProcEventInfo& eventInfo)
        {
            Unit* caster = eventInfo.GetActor();
            Unit* target = eventInfo.GetActionTarget();

            if (!caster || !target)
                return;

            int32 damage = eventInfo.GetDamageInfo()->GetDamage() * 0.05f; //5% normal
            int32 damageHeroic = eventInfo.GetDamageInfo()->GetDamage() * 0.10f; //10% heroic

            if (caster->GetMap()->IsHeroic())
                target->CastCustomSpell(caster, SPELL_DISCHARGE_DAMAGES, &damageHeroic, NULL, NULL, true);
            else
                target->CastCustomSpell(caster, SPELL_DISCHARGE_DAMAGES, &damage, NULL, NULL, true);

            //target->CastSpell(caster, SPELL_DISCHARGE_VISUAL, true); //visual target to caster because caster has no target when is stunned
        }

        void HandleEffectRemove(AuraEffect const* pAuraEffect, AuraEffectHandleModes eMode)
        {
            if (!GetOwner())
                return;

            // Unstunned on aura remove
            if (Creature* pOwner = GetOwner()->ToCreature())
                pOwner->SetControlled(false, UNIT_STATE_STUNNED);
        }

        void Register()
        {
            OnEffectApply += AuraEffectApplyFn(spell_kazrajin_discharge_AuraScript::HandleEffectApply, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
            //OnEffectPeriodic += AuraEffectPeriodicFn(spell_kazrajin_discharge_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            OnEffectRemove += AuraEffectRemoveFn(spell_kazrajin_discharge_AuraScript::HandleEffectRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectProc += AuraEffectProcFn(spell_kazrajin_discharge_AuraScript::OnProc, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const
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
            Unit* caster = GetCaster();
            Unit* pTarget = GetOwner()->ToUnit();

            if (!caster || !pTarget)
                return;

            if (Aura* pAura = pTarget->GetAura(SPELL_ENSNARED))
            {
                if (pAura->GetCasterGUID() == caster->GetGUID())
                {
                    pAura->ModStackAmount(1);
                    if (pAura->GetStackAmount() >= 5)
                    {
                        caster->AddAura(SPELL_ENTRAPPED, pTarget);
                        pAura->Remove();
                    }
                }
            }
            else if (!pTarget->HasAura(SPELL_ENTRAPPED))
                caster->AddAura(SPELL_ENSNARED, pTarget);
        }

        void HandleOnRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            Unit* caster = GetCaster();
            Unit* pTarget = GetOwner()->ToUnit();

            if (!caster || !pTarget)
                return;

            pTarget->RemoveAura(SPELL_ENSNARED, caster->GetGUID());

        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_quicksand_periodic_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
            OnEffectRemove += AuraEffectRemoveFn(spell_quicksand_periodic_AuraScript::HandleOnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
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
            //OnEffectHitTarget += SpellEffectFn(spell_quicksand_entrapped_SpellScript::HandleAdditionalSpell, EFFECT_1, SPELL_EFFECT_203); MISSING SPELL_EFFECT_203 FROM FREAKZ FILES
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_quicksand_entrapped_SpellScript();
    }
};


// Sandstorm
class spell_sul_sandstorm : public SpellScriptLoader
{
    enum : uint32
    {
        SANDSTORM_VISUAL = 136895
    };
public:
    spell_sul_sandstorm() : SpellScriptLoader("spell_sul_sandstorm") { }

    class spell_sul_sandstorm_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_sul_sandstorm_SpellScript);

            void HandleAfterCast()
        {
            if (Unit* pCaster = GetCaster())
            {
                pCaster->AddAura(SANDSTORM_VISUAL, pCaster);

                //std::list<Creature*> quicksandsList;
                std::list<Creature*> livingSandsList;

                //pCaster->GetCreatureListWithEntryInGrid(quicksandsList, NPC_QUICKSAND_STALKER, 500.0f);
                pCaster->GetCreatureListWithEntryInGrid(livingSandsList, MOB_LIVING_SAND, 500.0f);

                /*
                for (Creature *pQuicksand : quicksandsList)
                pQuicksand->AI()->DoAction(ACTION_CREATE_LIVING_SAND);*/

                for (Creature* pLivingSand : livingSandsList)
                    pLivingSand->AI()->DoAction(ACTION_CREATE_LIVING_SAND);
            }
        }

        void Register()
        {
            AfterCast += SpellCastFn(spell_sul_sandstorm_SpellScript::HandleAfterCast);
        }
    };

    SpellScript* GetSpellScript() const
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
        PrepareSpellScript(spell_marli_summon_blessed_loa_spirit_SpellScript)

            void HandleDummy(SpellEffIndex eEffIndex)
        {
            if (Unit* pCaster = GetCaster())
            {
                pCaster->CastSpell(pCaster, SPELL_SUMMON_BLESSED_LOA_SPIRIT, false);

                if (pCaster->ToCreature()->AI())
                    pCaster->ToCreature()->AI()->Talk(TALK_MARLI_BLESSED);
            }
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_marli_summon_blessed_loa_spirit_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
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
        PrepareSpellScript(spell_marli_summon_shadowed_loa_spirit_SpellScript)

            void HandleDummy(SpellEffIndex eEffIndex)
        {
            if (Unit* pCaster = GetCaster())
            {
                pCaster->CastSpell(pCaster, SPELL_SUMMON_SHADOWED_LOA_SPIRIT, false);

                if (pCaster->ToCreature()->AI())
                    pCaster->ToCreature()->AI()->Talk(TALK_MARLI_SHADOWED);
            }
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_marli_summon_shadowed_loa_spirit_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_marli_summon_shadowed_loa_spirit_SpellScript();
    }
};


// Twisted Fate (first) OLD: 137891 NEW: 137893
class spell_marli_twisted_fate_first : public SpellScriptLoader
{
public:
    spell_marli_twisted_fate_first() : SpellScriptLoader("spell_marli_twisted_fate_first") { }

    class spell_marli_twisted_fate_first_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_marli_twisted_fate_first_SpellScript);

            void SelectTarget(std::list<WorldObject*>& targets)
        {
            if (!GetCaster())
                return;

            // Select one random player...
            std::list<Player*> playerList;
            GetCaster()->GetPlayerListInGrid(playerList, 500.0f);
            if (!playerList.empty())
            {
                if (targets.size() > 1)
                    Trinity::Containers::RandomResize(targets, 1);
            }
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_marli_twisted_fate_first_SpellScript::SelectTarget, EFFECT_0, TARGET_SRC_CASTER);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_marli_twisted_fate_first_SpellScript();
    }
};


// Twisted Fate (second) OLD: 137962 NEW: 137963
class spell_marli_twisted_fate_second : public SpellScriptLoader
{
public:
    spell_marli_twisted_fate_second() : SpellScriptLoader("spell_marli_twisted_fate_second") { }

    class spell_marli_twisted_fate_second_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_marli_twisted_fate_second_SpellScript);

            void SelectTarget(std::list<WorldObject*>& targets)
        {
            if (!GetCaster())
                return;

            // Select one random player...
            std::list<Player*> playerList;
            GetCaster()->GetPlayerListInGrid(playerList, 500.0f);
            if (!playerList.empty())
            {
                if (targets.size() > 1)
                    Trinity::Containers::RandomResize(targets, 1);
            }
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_marli_twisted_fate_second_SpellScript::SelectTarget, EFFECT_0, TARGET_SRC_CASTER);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_marli_twisted_fate_second_SpellScript();
    }
};

#define MAX_DIST 50.0f

// Twisted Fate (Periodic Damages)
class spell_marli_twisted_fate_damages : public SpellScriptLoader
{
public:
    spell_marli_twisted_fate_damages() : SpellScriptLoader("spell_marli_twisted_fate_damages") { }

    /*class spell_marli_twisted_fate_damages_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_marli_twisted_fate_damages_AuraScript);


        void CalculateAmount(AuraEffect const* pAuraEffect, int32 &ruiAmount, bool &rbCanBeRecalculated)
        {
            if (!GetOwner())
                return;

            if (Creature *pOwner = GetOwner()->ToCreature())
            {
                if (Creature *pTwistedFateTarget = pOwner->FindNearestCreature(MOB_TWISTED_FATE_SECOND, 500.0f, true))
                {
                    if (pTwistedFateTarget->IsAlive())
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
           // DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_marli_twisted_fate_damages_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL_WITH_VALUE);
        }
    };*/

    class spell_marli_twisted_fate_damages_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_marli_twisted_fate_damages_SpellScript);

        void DealDamage()
        {
            if (Unit* caster = GetCaster())
            {
                if (Creature* pTwistedFateTarget = caster->FindNearestCreature(MOB_TWISTED_FATE_SECOND, 500.0f, true))
                {
                    float distance = caster->GetExactDist2d(pTwistedFateTarget);
                    if (!pTwistedFateTarget)
                        return;
                    uint32 mindmg = 0, maxdmg = 0;

                    switch (caster->GetMap()->GetDifficultyID())
                    {
                    case DIFFICULTY_10_HC:
                    case DIFFICULTY_25_HC:
                        mindmg = 50000;
                        maxdmg = 100000;
                        break;
                    }

                    if (distance > MAX_DIST)
                        distance = MAX_DIST;

                    SetHitDamage(((mindmg / -MAX_DIST) * distance) + maxdmg);
                }
            }
        }

        void Register()
        {
            OnHit += SpellHitFn(spell_marli_twisted_fate_damages_SpellScript::DealDamage);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_marli_twisted_fate_damages_SpellScript();
    }

    /*AuraScript *GetAuraScript() const
    {
        return new spell_marli_twisted_fate_damages_AuraScript();
    }*/
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
            if (Unit* pUnit = GetCaster())
            {
                if (Creature* pCaster = pUnit->ToCreature())
                {
                    if (CreatureAI* pAI = pCaster->AI())
                    {
                        SetHitDamage(1.1f * 1.0f);
                    }
                }
            }
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_dark_power_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const
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
        PrepareSpellScript(spell_soul_fragment_target_selector_SpellScript)

            void SelectTarget(std::list<WorldObject*>& targets)
        {
            if (!GetCaster())
                return;

            std::list<Player*> playerList;
            GetCaster()->GetPlayerListInGrid(playerList, 500.0f);

            if (!playerList.empty())
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

    SpellScript* GetSpellScript() const
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

        void HandleAfterCast()
        {
            Unit* caster = GetCaster();

            caster->RemoveAura(SPELL_SOUL_FRAGMENT_PERIODIC);
        }

        void HandleOnHit()
        {
            Unit* target = GetHitUnit();

            target->AddAura(SPELL_SOUL_FRAGMENT_PERIODIC, target);
        }

        void Register()
        {
            AfterCast += SpellCastFn(spell_soul_fragment_switcher_SpellScript::HandleAfterCast);
            OnHit += SpellHitFn(spell_soul_fragment_switcher_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_soul_fragment_switcher_SpellScript();
    }
};

class distancePredicate
{
private:
    Unit* caster;
public:
    distancePredicate(Unit* _caster) : caster(_caster) {}

    bool operator()(WorldObject* target) const
    {
        return target->GetExactDist2d(caster) < 15.f;
    }
};

class spell_marked_soul : public SpellScriptLoader
{
public:
    spell_marked_soul() : SpellScriptLoader("spell_marked_soul") {}

    class spell_impl : public SpellScript
    {
        PrepareSpellScript(spell_impl);

        void SelectTargets(std::list<WorldObject*>& targets)
        {
            std::list<WorldObject*> tempTargets;
            targets.remove_if(notPlayerPredicate());
            std::copy(std::begin(targets), std::end(targets), std::inserter(tempTargets, tempTargets.begin()));
            targets.remove_if(distancePredicate(GetCaster()));

            if (!targets.empty())
            {
                if (targets.size() > 1)
                    Trinity::Containers::RandomResize(targets, 1);
            }
            else
            {
                std::copy(std::begin(tempTargets), std::end(tempTargets), std::inserter(targets, targets.begin()));

                if (targets.size() > 1)
                    Trinity::Containers::RandomResize(targets, 1);
            }
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_impl::SelectTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_impl();
    }
};

class correctGuidPredicate
{
private:
    ObjectGuid casterGuid;
public:
    correctGuidPredicate(ObjectGuid guid) : casterGuid(guid) {}

    bool operator()(WorldObject* target) const
    {
        if (target)
        {
            return !target->ToUnit()->HasAura(SPELL_MARKED_SOUL, casterGuid);
        }
        return false;
    }
};

// 137121 
class bfa_spell_reckless_charge_initialize : public SpellScriptLoader
{
public:
    bfa_spell_reckless_charge_initialize() : SpellScriptLoader("bfa_spell_reckless_charge_initialize") { }

    class bfa_spell_reckless_charge_initialize_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_reckless_charge_initialize_AuraScript);

            void HandleApply(AuraEffect const* pAuraEffect, AuraEffectHandleModes eMode)
        {
            if (!GetCaster())
                return;

            GetCaster()->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, true);
        }

        void HandleRemove(AuraEffect const* AuraEffct, AuraEffectHandleModes mode)
        {
            if (!GetCaster())
                return;

            GetCaster()->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, false);
            GetCaster()->CastSpell(GetCaster(), SPELL_RECKLESS_CHARGE_SHATTER_GROUND, true);

            if (GetCaster()->HasAura(SPELL_POSSESSED))
            {
                if (GetCaster()->GetMap()->IsHeroic())
                    GetCaster()->CastSpell(GetCaster(), SPELL_DISCHARGE);
                else
                {
                    GetCaster()->CastSpell(GetCaster(), SPELL_OVERLOAD);
                }
            }
        }

        void HandlePeriodic(AuraEffect const* aurEff)
        {
            if (!GetCaster())
                return;

            GetCaster()->CastSpell(GetCaster(), SPELL_RECKLESS_CHARGE_GROUND_AT, true);
            GetCaster()->CastSpell(GetCaster(), SPELL_RECKLESS_CHARGE_UNIQUE_DAMAGES, true);
        }

        void Register()
        {
            OnEffectApply += AuraEffectApplyFn(bfa_spell_reckless_charge_initialize_AuraScript::HandleApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(bfa_spell_reckless_charge_initialize_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectPeriodic += AuraEffectPeriodicFn(bfa_spell_reckless_charge_initialize_AuraScript::HandlePeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY); // CUSTOM FREAKZ DBC
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_reckless_charge_initialize_AuraScript();
    }
};

// 137579
class bfa_spell_biting_cold_immunities : public SpellScriptLoader
{
public:
    bfa_spell_biting_cold_immunities() : SpellScriptLoader("bfa_spell_biting_cold_immunities") { }

    class bfa_spell_biting_cold_immunities_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_biting_cold_immunities_AuraScript);

        void HandleApply(AuraEffect const* pAuraEffect, AuraEffectHandleModes eMode)
        {
            Unit* caster = GetCaster();
            Unit* target = GetTarget()->ToPlayer();
            if (!caster || !target)
                return;
            //target->CastSpell(target, SPELL_BITING_COLD, true);
            target->ApplySpellImmune(0, IMMUNITY_ID, 136991, true);
        }

        void HandleRemove(AuraEffect const* AuraEffct, AuraEffectHandleModes mode)
        {
            Unit* caster = GetCaster();
            Unit* target = GetTarget()->ToPlayer();
            if (!caster || !target)
                return;
            GetCaster()->ApplySpellImmune(0, IMMUNITY_ID, 136991, false);
        }

        void Register()
        {
            OnEffectApply += AuraEffectApplyFn(bfa_spell_biting_cold_immunities_AuraScript::HandleApply, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(bfa_spell_biting_cold_immunities_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_biting_cold_immunities_AuraScript();
    }
};

// Removed the old Twisted Fate npc script because I don't understand a word and I prefer doing it myself easy and fast

// fuck that shit, i'm making my own enumerations here

enum TwistedFateEvents
{
    EVENT_LINK_FATES = 1,
    EVENT_CAST_DAMAGE_BOTH,
    EVENT_CAST_DAMAGE_SOLO,
};

enum TwistedFateActions
{
    ACTION_TWISTED_DIED = 16,
};

class bfa_npc_twisted_fate_first : public CreatureScript
{
public:
    bfa_npc_twisted_fate_first() : CreatureScript("bfa_npc_twisted_fate_first") { }

    class bfa_npc_twisted_fate_firstAI : public ScriptedAI
    {
    public:
        bfa_npc_twisted_fate_firstAI(Creature* creature) : ScriptedAI(creature)
        {
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_THREAT, true);
            me->SetSpeed(MOVE_WALK, 0.6f);
            me->SetSpeed(MOVE_RUN, 0.6f);
        }

        EventMap events; // for possible events
        ObjectGuid playerGuid;

        void Reset()
        {
            events.Reset();
        }

        void IsSummonedBy(Unit* summoner)
        {
            events.ScheduleEvent(EVENT_LINK_FATES, 1000, 0, 0);
        }

        void JustDied(Unit*)
        {
            AlertOtherFates();
        }

        void AlertOtherFates()
        {
            std::list<Creature*> cList;
            me->GetCreatureListWithEntryInGrid(cList, MOB_TWISTED_FATE_SECOND, 500.0f);
            if (!cList.empty())
                for (std::list<Creature*>::const_iterator itr = cList.begin(); itr != cList.end(); ++itr)
                    (*itr)->AI()->DoAction(ACTION_TWISTED_DIED);
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_TWISTED_DIED:
            {
                //events.CancelEvent(EVENT_CAST_DAMAGE_BOTH);
                //events.ScheduleEvent(EVENT_CAST_DAMAGE_SOLO, 500, 0, 0);
                me->StopMoving();
                me->AddUnitState(UNIT_STATE_ROOT);
                break;
            }
            }
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_LINK_FATES: // and also make them move towards each other
                {
                    if (Creature* secondFate = me->FindNearestCreature(MOB_TWISTED_FATE_SECOND, 555.0f, true))
                    {
                        me->SetFacingToObject(secondFate);
                        me->AI()->AttackStart(secondFate);
                        me->AddThreat(secondFate, 999999999.9f);
                        me->GetMotionMaster()->MoveFollow(secondFate, 0.0f, 0.0f);
                        events.ScheduleEvent(EVENT_CAST_DAMAGE_BOTH, 500, 0, 0);
                        break;
                    }
                }
                case EVENT_CAST_DAMAGE_BOTH:
                {
                    me->CastSpell(me, 137972, true);
                    events.ScheduleEvent(EVENT_CAST_DAMAGE_BOTH, 3000, 0, 0);
                    break;
                }
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_twisted_fate_firstAI(creature);
    }
};

class bfa_npc_twisted_fate_second : public CreatureScript
{
public:
    bfa_npc_twisted_fate_second() : CreatureScript("bfa_npc_twisted_fate_second") { }

    class bfa_npc_twisted_fate_secondAI : public ScriptedAI
    {
    public:
        bfa_npc_twisted_fate_secondAI(Creature* creature) : ScriptedAI(creature)
        {
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_THREAT, true);
            me->SetSpeed(MOVE_WALK, 0.6f);
            me->SetSpeed(MOVE_RUN, 0.6f);
        }

        EventMap events; // for possible events
        ObjectGuid playerGuid;

        void Reset()
        {
            events.Reset();
        }

        void IsSummonedBy(Unit* summoner)
        {
            events.ScheduleEvent(EVENT_LINK_FATES, 1000, 0, 0);
        }

        void JustDied(Unit*)
        {
            AlertOtherFates();
        }

        void AlertOtherFates()
        {
            std::list<Creature*> cList;
            me->GetCreatureListWithEntryInGrid(cList, MOB_TWISTED_FATE_FIRST, 500.0f);
            if (!cList.empty())
                for (std::list<Creature*>::const_iterator itr = cList.begin(); itr != cList.end(); ++itr)
                    (*itr)->AI()->DoAction(ACTION_TWISTED_DIED);
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_TWISTED_DIED:
            {
                //events.CancelEvent(EVENT_CAST_DAMAGE_BOTH);
                //events.ScheduleEvent(EVENT_CAST_DAMAGE_SOLO, 500, 0, 0);
                me->StopMoving();
                break;
            }
            }
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_LINK_FATES: // and also make them move towards each other
                {
                    if (Creature* fristFate = me->FindNearestCreature(MOB_TWISTED_FATE_FIRST, 555.0f, true))
                    {
                        me->SetFacingToObject(fristFate);
                        me->AI()->AttackStart(fristFate);
                        me->AddThreat(fristFate, 999999999.9f);
                        me->GetMotionMaster()->MoveFollow(fristFate, 0.0f, 0.0f);
                        events.ScheduleEvent(EVENT_CAST_DAMAGE_BOTH, 500, 0, 0);
                        break;
                    }
                }
                case EVENT_CAST_DAMAGE_BOTH:
                {
                    me->CastSpell(me, 137972, true);
                    events.ScheduleEvent(EVENT_CAST_DAMAGE_BOTH, 3000, 0, 0);
                    break;
                }
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_twisted_fate_secondAI(creature);
    }
};

// 137629
class bfa_spell_treacherous_ground : public SpellScriptLoader
{
public:
    bfa_spell_treacherous_ground() : SpellScriptLoader("bfa_spell_treacherous_ground") { }

    class bfa_spell_treacherous_ground_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_treacherous_ground_AuraScript);

        void OnPeriodic(AuraEffect const* aurEff)
        {
            Unit* caster = GetCaster();

            std::list<Creature*> cList;
            caster->GetCreatureListWithEntryInGrid(cList, MOB_LIVING_SAND, 8.0f);
            if (!cList.empty())
                for (std::list<Creature*>::const_iterator itr = cList.begin(); itr != cList.end(); ++itr)
                {
                    // Don't count self
                    if ((*itr) == caster)
                        continue;

                    if ((*itr)->GetDistance(caster) < 7.0f && (*itr)->IsAlive()) // check if also alive because we will kill them to not re-add 1 stack from the same living sand
                    {
                        caster->AddAura(SPELL_TREACHEROUS_GROUND, caster);
                        caster->AddAura(SPELL_TREACHEROUS_GROUND_SIZE, caster);
                        (*itr)->Kill((*itr));
                    }
                }
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(bfa_spell_treacherous_ground_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }

    private:
        uint32 stacks;
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_treacherous_ground_AuraScript();
    }
};

// 137085
class bfa_spell_chilled_to_the_bone : public SpellScriptLoader
{
public:
    bfa_spell_chilled_to_the_bone() : SpellScriptLoader("bfa_spell_chilled_to_the_bone") { }

    class bfa_spell_chilled_to_the_bone_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_chilled_to_the_bone_AuraScript);

        void HandleApply(AuraEffect const* pAuraEffect, AuraEffectHandleModes eMode)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;
            caster->ApplySpellImmune(0, IMMUNITY_ID, 137084, true); // Body Heat
        }

        void HandleRemove(AuraEffect const* AuraEffct, AuraEffectHandleModes mode)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;
            caster->ApplySpellImmune(0, IMMUNITY_ID, 137084, false); // Body Heat
        }

        void Register()
        {
            OnEffectApply += AuraEffectApplyFn(bfa_spell_chilled_to_the_bone_AuraScript::HandleApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(bfa_spell_chilled_to_the_bone_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_chilled_to_the_bone_AuraScript();
    }
};

// 137641; called for 137650 stacks. This already works fine be Shadowed Soul stacks are removed because its apply aura script ( main spell ) and we will fix this via spell scrips & dbc files
class bfa_spell_soul_fragment_shadowed_soul : public SpellScriptLoader
{
public:
    bfa_spell_soul_fragment_shadowed_soul() : SpellScriptLoader("bfa_spell_soul_fragment_shadowed_soul") { }

    class bfa_spell_soul_fragment_shadowed_soul_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_soul_fragment_shadowed_soul_AuraScript);

        void HandleApply(AuraEffect const* pAuraEffect, AuraEffectHandleModes eMode)
        {
            Unit* caster = GetCaster();
            caster->AddAura(SPELL_SHADOWED_SOUL, caster);
        }

        void OnPeriodic(AuraEffect const* aurEff)
        {
            Unit* caster = GetCaster();

            caster->AddAura(SPELL_SHADOWED_SOUL, caster);
        }

        void Register()
        {
            OnEffectApply += AuraEffectApplyFn(bfa_spell_soul_fragment_shadowed_soul_AuraScript::HandleApply, EFFECT_0, SPELL_AURA_OVERRIDE_SPELLS, AURA_EFFECT_HANDLE_REAL);
            OnEffectPeriodic += AuraEffectPeriodicFn(bfa_spell_soul_fragment_shadowed_soul_AuraScript::OnPeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DAMAGE);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_soul_fragment_shadowed_soul_AuraScript();
    }
};

// Reckless Charge immunities ( some failsafes ) - 137124 ( main spell )
class bfa_spell_reckless_charge_failsafe : public SpellScriptLoader
{
public:
    bfa_spell_reckless_charge_failsafe() : SpellScriptLoader("bfa_spell_reckless_charge_failsafe") { }

    class bfa_spell_reckless_charge_failsafe_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_reckless_charge_failsafe_AuraScript);

        void HandleApply(AuraEffect const* pAuraEffect, AuraEffectHandleModes eMode)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;
            caster->ApplySpellImmune(0, IMMUNITY_ID, 137122, true);
            caster->ApplySpellImmune(0, IMMUNITY_ID, 137133, true);
        }

        void HandleRemove(AuraEffect const* AuraEffct, AuraEffectHandleModes mode)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;
            caster->ApplySpellImmune(0, IMMUNITY_ID, 137122, false);
            caster->ApplySpellImmune(0, IMMUNITY_ID, 137133, false);
        }

        void Register()
        {
            OnEffectApply += AuraEffectApplyFn(bfa_spell_reckless_charge_failsafe_AuraScript::HandleApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(bfa_spell_reckless_charge_failsafe_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_reckless_charge_failsafe_AuraScript();
    }
};

// Reckless Charge - 137122, 137133
class bfa_spell_reckless_charge_spell_onhit_script : public SpellScriptLoader
{
public:
    bfa_spell_reckless_charge_spell_onhit_script() : SpellScriptLoader("bfa_spell_reckless_charge_spell_onhit_script") { }

    class bfa_spell_reckless_charge_spell_onhit_script_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_reckless_charge_spell_onhit_script_SpellScript);

        void HandleOnHit()
        {
            if (Unit* pHit = GetHitUnit())
            {
                if (Unit* pCaster = GetCaster())
                {
                    pCaster->CastSpell(pHit, 137124, true);
                }
            }
        }

        void Register()
        {
            OnHit += SpellHitFn(bfa_spell_reckless_charge_spell_onhit_script_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_reckless_charge_spell_onhit_script_SpellScript();
    }
};

// 136922
class spell_malakk_frostbite_visual : public SpellScriptLoader
{
public:
    spell_malakk_frostbite_visual() : SpellScriptLoader("spell_malakk_frostbite_visual") { }

    class spell_malakk_frostbite_visual_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_malakk_frostbite_visual_AuraScript);

            void VisualPeriodic(AuraEffect const* pAuraEffect)
        {
            Unit* target = GetTarget()->ToPlayer();

            if (!target)
                return;

            target->CastSpell(target, SPELL_FROSTBITE_VISUAL, true);
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_malakk_frostbite_visual_AuraScript::VisualPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL_WITH_VALUE);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_malakk_frostbite_visual_AuraScript();
    }
};

void AddSC_boss_council_of_elders()
{
    new boss_frost_king_malakk();
    new boss_kazrajin();
    new boss_sul_the_sandcrawler();
    new boss_high_priestess_marli();
    new mob_garajal();
    new mob_garajals_soul();
    new mob_living_sand();
    new mob_blessed_loa_spirit();
    new mob_shadowed_loa_spirit();
    //new mob_twisted_fate_helper();
    //new mob_twisted_fate();
    new spell_garajal_possessed();
    new spell_malakk_frigid_assault();
    new spell_malakk_biting_cold();
    new spell_malakk_frostbite();
    new spell_malakk_frostbite_periodic();
    new spell_malakk_frostbite_allies();
    new spell_malakk_body_heat();
    //new spell_kazrajin_reckless_charge();
    new spell_kazrajin_reckless_charge_targeting();
    new spell_kazrajin_overload();
    new spell_kazrajin_discharge();
    new spell_quicksand_periodic();
    new spell_quicksand_entrapped();
    new spell_sul_sandstorm();
    new spell_marli_summon_blessed_loa_spirit();
    new spell_marli_summon_shadowed_loa_spirit();
    new spell_marli_twisted_fate_first();
    new spell_marli_twisted_fate_second();
    new spell_marli_twisted_fate_damages();
    new spell_dark_power();
    new spell_soul_fragment_target_selector();
    new spell_soul_fragment_switcher();
    new spell_marked_soul();
    new bfa_spell_reckless_charge_initialize();
    new bfa_spell_biting_cold_immunities();
    new bfa_npc_twisted_fate_second();
    new bfa_npc_twisted_fate_first();
    new bfa_spell_treacherous_ground();
    new bfa_spell_chilled_to_the_bone();
    new bfa_spell_soul_fragment_shadowed_soul();
    new bfa_spell_reckless_charge_spell_onhit_script();
    new bfa_spell_reckless_charge_failsafe();
    new spell_malakk_frostbite_visual();
}
