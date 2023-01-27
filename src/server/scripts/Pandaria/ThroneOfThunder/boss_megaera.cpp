#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "SpellAuras.h"
#include "MapManager.h"
#include "Spell.h"
#include "Vehicle.h"
#include "Cell.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "CreatureTextMgr.h"
#include "Unit.h"
#include "Player.h"
#include "Creature.h"
#include "InstanceScript.h"
#include "Map.h" 
#include "VehicleDefines.h"
#include "SpellInfo.h"
#include <utility>
#include "Group.h"

#include "throne_of_thunder.h"

enum Yells
{
    // Boss
    ANN_RAMPAGE = 0,      // Megaera begins to [Rampage].
    ANN_SUBSIDE                           // Megaera's rage subsides.
};

enum Spells
{
    // Boss
    SPELL_SUBMERGE = 103963, // Submerge visual (when casted makes head submerge).
    SPELL_EMERGE = 139832, // Submerged visual (when removed makes head emerge).

    SPELL_CONCEALING_FOG = 137973, // Dummy on eff 0 for attackable state (body + back head).

    // Rampage - When a head dies.
    SPELL_RAMPAGE = 139458, // Periodic dummy on eff 0 for damage increase on the specific spells (+25% for each extra available head of type).

    SPELL_RAMPAGE_FIRE_CAST = 139433,
    SPELL_RAMPAGE_FROST_CAST = 139440,
    SPELL_RAMPAGE_POISON_CAST = 139504,
    SPELL_RAMPAGE_ARCANE_CAST = 139513,

    SPELL_RAMPAGE_FIRE = 139548, // Flaming Head.
    SPELL_RAMPAGE_FROST = 139549, // Frozen Head.
    SPELL_RAMPAGE_POISON = 139551, // Venomous Head.
    SPELL_RAMPAGE_ARCANE = 139552, // Arcane Head - Heroic only!.

    // Hydra Frenzy.
    SPELL_HYDRA_FRENZY = 139942, // Attack speed increase (others when a head dies, this + heal to full).

    // Elemental Bonds.
    SPELL_ELEMENTAL_BONDS_FIRE = 139586, // 15% dmg increase aura for each additional Flaming Head, on each.
    SPELL_ELEMENTAL_BONDS_FROST = 139587, // 15% dmg increase aura for each additional Frozen Head, on each.
    SPELL_ELEMENTAL_BONDS_VENOM = 139588, // 15% dmg increase aura for each additional Venomous Head, on each.
    SPELL_ELEMENTAL_BONDS_ARCAN = 139589, // 15% dmg increase aura for each additional Arcane Head, on each.

    // Megaera's Rage - When there's no melee target.
    SPELL_MEGAERAS_RAGE_FIRE = 139758, // Flaming Head.
    SPELL_MEGAERAS_RAGE_FROST = 139816, // Frozen Head.
    SPELL_MEGAERAS_RAGE_POISON = 139818, // Venomous Head.
    SPELL_MEGAERAS_RAGE_ARCANE = 139820, // Arcane Head - Heroic only!.

    // Flaming Head
    SPELL_CINDERS = 139822, // When in Concealing Fog. Melts Icy Ground. Pool NPC summoned when removed / every 3 seconds on Heroic.
    SPELL_CINDERS_SUMMON = 139834, // Summons NPC_CINDERS.
    SPELL_CINDERS_AURA = 139835, // Pool npc aura (per. dmg. trigger for 139836).

    SPELL_IGNITE_FLESH = 137729, // Triggers 137330 dmg each sec and SPELL_IGNITE_FLESH_AURA on targets.
    SPELL_IGNITE_FLESH_AURA = 137731, // Periodic damage aura on players hit by main spell.

    // Frozen Head
    // Torrent of Ice : NPC_TORRENT_OF_ICE summoned at player location, follows him having SPELL_TORRENT_OF_ICE_NPC_A. SPELL_TORRENT_OF_ICE cast on it.
    SPELL_TORRENT_OF_ICE = 139866, // When in Concealing Fog. Each sec triggers SPELL_TORRENT_OF_ICE_SUMMON.
    SPELL_TORRENT_OF_ICE_SUMMON = 139870, // Summons NPC_ICY_GROUND.
    SPELL_TORRENT_OF_ICE_TARGET = 139857, // Target aura ("Torrent of Ice is targeting you!").
    SPELL_TORRENT_OF_ICE_NPC_A = 139890, // NPC aura (60k periodic damage).

    SPELL_ICY_GROUND_AURA = 139909, // Periodic damage and slow aura on NPC_ICY_GROUND.
    SPELL_ICY_GROUND_GROW = 140213, // 1% scale increase (Heroic only!). 1 min -> double size. Not good as-is!
    SPELL_ICY_GROUND_VISUAL = 139875, // Triggers SPELL_ICY_GROUND_DUMMY.
    SPELL_ICY_GROUND_DUMMY = 139877, // Check for target and add stacks (SPELL_ICY_GROUND_AURA).

    SPELL_ARCTIC_FREEZE = 139841, // Triggers damage and SPELL_ARCTIC_FREEZE_DUMMY.
    SPELL_ARCTIC_FREEZE_DUMMY = 139843, // Stack checker and adder - 5 stacks = SPELL_ARCTIC_FREEZE_STUN on player.
    SPELL_ARCTIC_FREEZE_STUN = 139844, // 20 sec stun.

    // Venomous Head
    SPELL_ACID_RAIN_SUMMON = 139845, // Summons dummy npc (remove trigger spell)
    SPELL_ACID_RAIN_VISUAL = 139847, // Visual for dummy npc
    SPELL_ACID_RAIN_MISSILE = 139848, // Should target dummy npc only (needs trigger spell added (DAMAGE below))
    SPELL_ACID_RAIN_DAMAGE = 139850, // Damage, needs spellscript for range.

    SPELL_ROT_ARMOR = 139838, // Triggers 139839 per. dmg. + 139840 damage taken debuff. 

    // Arcane Head - Heroic only!
    SPELL_NETHER_TEAR = 140138,

    SPELL_DIFFUSION = 139991, // Triggers per. dmg. and SPELL_DIFFUSION_PER_DUMMY.
    SPELL_DIFFUSION_PER_DUMMY = 139993, // Periodic dummy for 10% health redirect.

    // Nether Wyrm
    SPELL_NETHER_SPIKE = 140178,
    SPELL_SUPPRESSION = 140179,

    SPELL_MEGAERA_ACHIEVEMENT_HANDLER = 140353,
};

enum Npcs
{
    // Boss
    NPC_FLAMING_HEAD = 70212,
    NPC_FROZEN_HEAD = 70235,
    NPC_VENOMOUS_HEAD = 70247,
    NPC_ARCANE_HEAD = 70252, // After flaming head dies - Heroic only!

    // Flaming Head
    NPC_CINDERS = 70432,

    // Frozen Head
    NPC_TORRENT_OF_ICE = 70439,
    NPC_ICY_GROUND = 70446,

    // Arcane Head - Heroic only!
    NPC_NETHER_WYRM = 70507,  // From Nether Tear.
    NPC_NETHER_TEAR = 70506,

    // Venomous Head
    NPC_ACID_RAIN = 70435
};

enum GOs
{
    GO_CACHE_OF_ANCIENT_TREAS = 218805 // Loot chest.
};

enum Events
{
    // Boss
    EVENT_RAMPAGE = 1,
    EVENT_MEGAERAS_RAGE,

    EVENT_SUBMERGE,
    EVENT_EMERGE,
    EVENT_BERSERK,

    EVENT_RELOCATE_HEAD,
    EVENT_REEMERGE_HEAD,
    EVENT_SUBMERGE_HEAD,
    EVENT_START_HEADS,

    // Heads - General
    EVENT_CHECK_MEGAERAS_RAGE,

    // Flaming Head
    EVENT_CINDERS,
    EVENT_IGNITE_FLESH,

    // Frozen Head
    EVENT_TORRENT_OF_ICE,
    EVENT_ARCTIC_FREEZE,
    EVENT_SUMMON_ICY_GROUND,
    EVENT_APPLYSLOW_TO_PLAYERS,

    // Venomous Head
    EVENT_ACID_RAIN,
    EVENT_ROT_ARMOR,

    // Arcane Head - Heroic only!
    EVENT_NETHER_TEAR,
    EVENT_DIFFUSION,
    EVENT_SUMMON_WRYMS,

    // Icy Ground
    EVENT_CHECK_ICY_GROUND_AND_CINDERS,
    EVENT_ICY_GROUND_GROW,

    // Nether Wyrm - From Arcane Head - Heroic only! 
    EVENT_NETHER_SPIKE,
    EVENT_SUPPRESSION,
    EVENT_SUMMON_WRYMS25,
    EVENT_TORRENT_SELECTION,
};

enum Timers
{
    // Boss
    TIMER_BERSERK_H = 600000, // 10 minutes (Heroic).
    TIMER_BERSERK = 780000  // 13 minutes.
};

enum Actions
{
    ACTION_SET_IN_COMBAT = 1,
    ACTION_MEGAERAS_RAGE,
    ACTION_DELAY_EVENTS
};

enum HeadPositions
{
    VENOMOUS_HEAD,
    FROZEN_HEAD,
    FLAMING_HEAD,
    ARCANE_HEAD
};

// Front Head positions.
Position const headPositions[4] =
{
    { 6394.10f, 4497.44f, -210.24f, 1.56f },    // VENOMOUS
    { 6417.99f, 4507.41f, -210.58f, 2.18f },    // FROZEN
    { 6437.47f, 4535.20f, -210.62f, 2.62f },    // FLAMING
    { 6435.48f, 4565.67f, -210.57f, 3.34f }     // ARCANE
};

// Concealing Fog Head positions.
Position const concealingPositions[7] =
{
    { 6457.16f, 4489.78f, -210.032f, 2.46f}, // Middle.

    { 6447.39f, 4481.54f, -210.032f, 2.38f}, // Right.
    { 6436.35f, 4473.30f, -210.032f, 1.79f},
    { 6410.10f, 4471.53f, -210.032f, 1.71f},

    { 6468.27f, 4503.42f, -210.032f, 2.58f}, // Left.
    { 6472.02f, 4524.07f, -210.032f, 2.94f},
    { 6465.45f, 4545.15f, -210.032f, 3.13f},
};

// Front Head orientations.
float headOrientations[2] =
{
    2.29f,                             // Right.
    2.70f                              // Left.
};

// Concealing Fog Head orientations.
float concealingOrientations[7] =
{
    2.46f,                             // Middle.

    2.38f,                             // Right.
    1.79f,
    1.71f,

    2.58f,                             // Left.
    2.94f,
    3.13f
};

class HeadPair
{
private:
    Position position;
    uint64 uiGuid;

public:
    HeadPair(Position pos, uint64 guid) : uiGuid(guid), position(pos) {}

    Position GetPosition() const
    {
        return position;
    }

    uint64 GetGUID() const
    {
        return uiGuid;
    }

    void SetGUID(uint64 _guid)
    {
        uiGuid = _guid;
    }
};

// Megaera spawn / original body position.
Position const bossSpawnPos = { 6442.61f, 4599.18f, -210.032f };

// Megaera 68065.
class boss_megaera : public CreatureScript
{
public:
    boss_megaera() : CreatureScript("boss_megaera") { }

    struct boss_megaeraAI : public BossAI
    {
        boss_megaeraAI(Creature* creature) : BossAI(creature, DATA_MEGAERA)
        {
            instance = creature->GetInstanceScript();
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
        }

        EventMap RPevents;

        InstanceScript* instance;
        uint8 headKills;
        uint8 rampageCount;
        bool isRaging;
        bool isRampaging;
        bool isDead;
        std::vector<std::pair<HeadPair*, bool>> pairv;
        std::pair<uint32, uint32> activeHeadEntries;
        std::list<ObjectGuid> headGuids;

        uint32 remainingHead;
        uint32 killedHeads[4];
        ObjectGuid movingHeadGuid;
        ObjectGuid activeHeadGuid;

        /*** SPECIFIC AI FUNCTIONS ***/

        std::list<Creature*> GetActiveHeadList()
        {

            std::list<Creature*> heads;
            GetCreatureListWithEntryInGrid(heads, me, activeHeadEntries.first, 200.f);
            GetCreatureListWithEntryInGrid(heads, me, activeHeadEntries.second, 200.f);

            heads.remove_if([this](Creature const* pCreature) -> bool
                {
                    return pCreature->HasAura(SPELL_CONCEALING_FOG);
                });

            return heads;
        }

        void FillPairVector()
        {

            remainingHead = 0;

            pairv.clear();

            for (uint8 i = 0; i < 7; ++i)
            {
                pairv.push_back(std::make_pair(new HeadPair(concealingPositions[i], 0), false));

                if (i < 4)
                    killedHeads[i] = 0;
            }

            headGuids.clear();
        }

        // Used to add Hydra Frenzy to all heads of a type and heal them.
        void AddHydraFrenzy(uint32 entry)
        {
            std::list<Creature*> heads;

            GetCreatureListWithEntryInGrid(heads, me, entry, 300.0f);

            heads.remove_if([this](Creature const* pCreature) -> bool
                {
                    return !pCreature->IsAlive();
                });

            for (auto pCreature : heads)
            {
                pCreature->SetFullHealth();

                if (!pCreature->HasAura(SPELL_CONCEALING_FOG))
                    pCreature->CastSpell(pCreature, SPELL_HYDRA_FRENZY, true);
            }
        }

        // Used to retrieve number of surplus heads of a certain type (for use in Elemental Bonds aura stacks addition and Rampage damage calculations).
        int32 GetExtraHeadsCount(uint32 entry)
        {
            std::list<Creature*> heads;
            GetCreatureListWithEntryInGrid(heads, me, entry, 300.0f);

            heads.remove_if([this](Creature const* pCreature) -> bool
                {
                    return !pCreature->IsAlive();
                });

            return heads.size() - 1;
        }

        // Used to add Elemental Bonds to all extra heads of a type.
        void AddElementalBonds(uint32 entry)
        {
            std::list<Creature*> heads;

            GetCreatureListWithEntryInGrid(heads, me, entry, 300.0f);

            heads.remove_if([this](Creature const* pCreature) -> bool
                {
                    return !pCreature->IsAlive();
                });

            uint32 spell = 0;
            uint32 offset = 0;

            switch (entry)
            {
            case NPC_VENOMOUS_HEAD:
                spell = SPELL_ELEMENTAL_BONDS_VENOM;
                offset = killedHeads[VENOMOUS_HEAD];
                break;
            case NPC_FROZEN_HEAD:
                spell = SPELL_ELEMENTAL_BONDS_FROST;
                offset = killedHeads[FROZEN_HEAD];
                break;
            case NPC_FLAMING_HEAD:
                spell = SPELL_ELEMENTAL_BONDS_FIRE;
                offset = killedHeads[FLAMING_HEAD];
                break;
            case NPC_ARCANE_HEAD:
                spell = SPELL_ELEMENTAL_BONDS_ARCAN;
                offset = killedHeads[ARCANE_HEAD];
                break;
            }

            for (auto pCreature : heads)
            {
                if (Aura* pAura = pCreature->GetAura(spell))
                {
                    pAura->ModStackAmount(offset - pAura->GetStackAmount());
                }
                else if (Aura* pAura = pCreature->AddAura(spell, pCreature))
                {
                    pAura->ModStackAmount(offset - 1);
                }
            }
        }

        Creature* SpawnNewHead(uint32 uiEntry, bool concealing)
        {
            Position headPos;
            uint8 offset = urand(0, pairv.size() - 1);

            switch (uiEntry)
            {
            case NPC_VENOMOUS_HEAD:
                headPos = headPositions[VENOMOUS_HEAD];
                break;
            case NPC_FROZEN_HEAD:
                headPos = headPositions[FROZEN_HEAD];
                break;
            case NPC_FLAMING_HEAD:
                headPos = headPositions[FLAMING_HEAD];
                break;
            case NPC_ARCANE_HEAD:
                headPos = headPositions[ARCANE_HEAD];
                break;
            default:
                me->GetPosition();
                break;
            }

            if (concealing)
                me->GetPosition();

            if (Creature* pHead = me->SummonCreature(uiEntry, headPos, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 6000))
            {
                if (concealing)
                {
                    bool use_offset = false;

                    std::vector<std::pair<HeadPair*, bool>>::iterator itr = pairv.begin();
                    std::advance(itr, offset);

                    if (!itr->second)
                    {
                        headPos = itr->first->GetPosition();
                        itr->second = true;
                        use_offset = true;
                    }
                    else
                    {
                        itr = pairv.begin();
                        for (; itr != pairv.end(); ++itr)
                        {
                            if (!itr->second)
                            {
                                headPos = itr->first->GetPosition();
                                itr->second = true;
                                break;
                            }
                        }
                    }

                    pHead->NearTeleportTo(headPos.GetPositionX(), headPos.GetPositionY(), headPos.GetPositionZ(), headPos.GetOrientation());
                    //pHead->SetFacingTo(use_offset ? concealingOrientations[offset] : headPos.GetOrientation());
                    me->AddAura(SPELL_CONCEALING_FOG, pHead);
                }
                else
                    pHead->SetFacingTo(headPos.GetOrientation());

                AddElementalBonds(uiEntry);
                return pHead;
            }

            return nullptr;
        }

        void RelocateHead()
        {
            if (Creature* pHead = ObjectAccessor::GetCreature(*me, movingHeadGuid))
            {
                Position headPos;
                switch (pHead->GetEntry())
                {
                case NPC_VENOMOUS_HEAD:
                    headPos = headPositions[VENOMOUS_HEAD];
                    break;
                case NPC_FROZEN_HEAD:
                    headPos = headPositions[FROZEN_HEAD];
                    break;
                case NPC_FLAMING_HEAD:
                    headPos = headPositions[FLAMING_HEAD];
                    break;
                case NPC_ARCANE_HEAD:
                    headPos = headPositions[ARCANE_HEAD];
                    break;
                default:
                    me->GetPosition();
                    break;
                }

                pHead->NearTeleportTo(headPos.GetPositionX(), headPos.GetPositionY(), headPos.GetPositionZ(), headPos.GetOrientation());

                if (Aura* pAura = pHead->GetAura(SPELL_EMERGE))
                {
                    pAura->SetDuration(4000);
                }
                else if (Aura* pAura = pHead->AddAura(SPELL_EMERGE, pHead))
                    pAura->SetDuration(4000);

                pHead->RemoveAurasDueToSpell(SPELL_CONCEALING_FOG);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, pHead);
            }
        }

        void SubmergeHead()
        {
            if (Creature* pHead = ObjectAccessor::GetCreature(*me, activeHeadGuid))
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, pHead);

                pHead->InterruptNonMeleeSpells(true);
                pHead->CastSpell(pHead, SPELL_SUBMERGE);

                events.ScheduleEvent(EVENT_REEMERGE_HEAD, 2200);
            }
        }

        void ReEmergeHead()
        {
            if (Creature* pHead = ObjectAccessor::GetCreature(*me, activeHeadGuid))
            {
                if (Aura* pAura = pHead->GetAura(SPELL_EMERGE))
                    pAura->SetDuration(1900);

                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, pHead);
            }
        }

        // Selection of the three starting heads (from those available according to difficulty).
        bool SpawnStartingHeads()
        {
            //if (instance->GetData(TYPE_BELLS_RUNG) < 3)
              //  return false;
            // boss order

            FillPairVector();

            uint32 concealingHead = 0;
            uint32 concealingHeadHeroic = 0;
            uint32 firstHead = 0;
            uint32 secondHead = 0;

            // Select the Concealing Fog head.
            concealingHead = NPC_FLAMING_HEAD;
            concealingHeadHeroic = me->GetMap()->IsHeroic() ? NPC_ARCANE_HEAD : 0;

            // The Concealing Fog head is already selected, select the first front one based on what's left.
            firstHead = NPC_FROZEN_HEAD;

            // The Concealing Fog head and the first front one were already selected, select the third one based on what's left.
            secondHead = NPC_VENOMOUS_HEAD;

            // Now do the checks and spawn them.
            if (!concealingHead || !firstHead || !secondHead)
            {
                // Throw some error or shit.
                //TC_LOG_ERROR("scripts", "Cannot complete SpawnStartingHeads() function on Megaera encounter (TOT) - Head spawns are bad / missing!");
                return false;
            }

            // Summon the front heads.
            if (Creature* fiHead = SpawnNewHead(firstHead, false))
            {
                me->AddAura(SPELL_EMERGE, fiHead);
                fiHead->SetWaterWalking(true);
                fiHead->SetReactState(REACT_DEFENSIVE);
            }

            if (Creature* secHead = SpawnNewHead(secondHead, false))
            {
                me->AddAura(SPELL_EMERGE, secHead);
                secHead->SetWaterWalking(true);
                secHead->SetReactState(REACT_DEFENSIVE);
            }

            // Summon the Concealing Fog head and add the aura to it.
            if (Creature* concealing = SpawnNewHead(concealingHead, true))
            {
                me->AddAura(SPELL_EMERGE, concealing);
                concealing->SetWaterWalking(true);
                concealing->SetReactState(REACT_DEFENSIVE);
            }
            if (concealingHeadHeroic)
            {
                if (Creature* concealing = SpawnNewHead(concealingHeadHeroic, true))
                {
                    me->AddAura(SPELL_EMERGE, concealing);
                    concealing->SetWaterWalking(true);
                    concealing->SetReactState(REACT_DEFENSIVE);
                }
            }

            activeHeadEntries.first = NPC_VENOMOUS_HEAD;
            activeHeadEntries.second = NPC_FROZEN_HEAD;

            return true;
        }

        Creature* FindAliveActiveHead(uint32 entry) const
        {
            std::list<Creature*> heads;
            GetCreatureListWithEntryInGrid(heads, me, entry, 300.f);
            heads.remove_if([this](Creature const* pCreature) -> bool
                {
                    return pCreature->HasAura(SPELL_CONCEALING_FOG);
                });

            if (!heads.empty())
            {
                if (heads.size() > 1)
                    heads.resize(1);

                return heads.front();
            }
            return nullptr;
        }

        // Selection of the next two heads when one dies (from those available according to difficulty).
        void SpawnNextHeads(uint32 deadHead, uint32 nextHead)
        {
            // For sanity... I guess
            if (headKills == 0 || headKills == 7)
                return;

            std::list<Creature*> concealedHeadsNextHead;
            std::list<Creature*> concealedHeadsDeadHead;

            GetCreatureListWithEntryInGrid(concealedHeadsNextHead, me, nextHead, 300.f);
            GetCreatureListWithEntryInGrid(concealedHeadsDeadHead, me, deadHead, 300.f);

            concealedHeadsNextHead.remove_if([this](Creature const* pCreature) -> bool
                {
                    return !pCreature->HasAura(SPELL_CONCEALING_FOG);
                });

            concealedHeadsDeadHead.remove_if([this](Creature const* pCreature) -> bool
                {
                    return !pCreature->HasAura(SPELL_CONCEALING_FOG);
                });

            /*if (!concealedHeadsNextHead.empty())
            {
                if (Creature* pHead = Trinity::Containers::SelectRandomContainerElement(concealedHeadsNextHead))
                {
                    pHead->InterruptNonMeleeSpells(true);
                    pHead->CastSpell(pHead, SPELL_SUBMERGE);
                    movingHeadGuid = pHead->GetGUID();

                    events.ScheduleEvent(EVENT_RELOCATE_HEAD, 2200);

                    for (std::vector<std::pair<HeadPair*, bool>>::iterator itr = pairv.begin(); itr != pairv.end(); ++itr)
                    {
                        if (pHead->GetGUID() == itr->first->GetGUID())
                        {
                            itr->first->SetGUID(0);
                            itr->second = false;
                        }
                    }
                }
            }

            if (Creature* pActiveHead = FindAliveActiveHead(remainingHead))
            {
                activeHeadGuid = pActiveHead->GetGUID();

                events.ScheduleEvent(EVENT_SUBMERGE_HEAD, 2000);
            }*/

            for (uint8 i = 0; i < (concealedHeadsDeadHead.empty() ? 2 : 1); ++i)
            {
                if (Creature* backHead = SpawnNewHead(deadHead, true))
                {
                    if (i == 1)
                        backHead->AI()->SetData(1, 0);

                    if (Aura* pAura = backHead->GetAura(SPELL_EMERGE))
                    {
                        pAura->SetDuration(2000);
                    }
                    else if (Aura* pAura = backHead->AddAura(SPELL_EMERGE, backHead))
                        pAura->SetDuration(2000);

                    backHead->SetWaterWalking(true);
                    backHead->SetReactState(REACT_DEFENSIVE);

                    DoZoneInCombat(backHead, 200.f);
                }
            }
        }

        // Used to remove Encounter frames from all the heads.
        void RemoveSummonFrame(uint32 entry)
        {
            std::list<Creature*> summonsList;
            GetCreatureListWithEntryInGrid(summonsList, me, entry, 200.0f);
            if (!summonsList.empty() && instance)
                for (std::list<Creature*>::iterator summs = summonsList.begin(); summs != summonsList.end(); summs++)
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, (*summs)); // Remove
        }

        // Used to add auras to all heads.
        void AddSummonAura(uint32 spellId, uint32 entry)
        {
            std::list<Creature*> summonsList;
            GetCreatureListWithEntryInGrid(summonsList, me, entry, 200.0f);
            if (!summonsList.empty())
                for (std::list<Creature*>::iterator summs = summonsList.begin(); summs != summonsList.end(); summs++)
                    if ((*summs)->IsAlive())
                        (*summs)->AddAura(spellId, *summs);
        }

        // Used to remove auras from all heads.
        void RemoveSummonAura(uint32 spellId, uint32 entry)
        {
            std::list<Creature*> summonsList;
            GetCreatureListWithEntryInGrid(summonsList, me, entry, 200.0f);
            if (!summonsList.empty())
                for (std::list<Creature*>::iterator summs = summonsList.begin(); summs != summonsList.end(); summs++)
                    if ((*summs)->IsAlive())
                        (*summs)->RemoveAurasDueToSpell(spellId);
        }

        // Used to make all same-type heads cast certain spells.
        void HeadsCastSpell(uint32 spellId, uint32 entry, bool randomTarget = false, bool triggered = false, bool front_only = false, bool concealingFog_select = true)
        {
            std::list<Creature*> summonsList;
            GetCreatureListWithEntryInGrid(summonsList, me, entry, 200.0f);
            if (front_only)
                summonsList.remove_if([this](Creature const* pCreature) -> bool
                    {
                        return pCreature->HasAura(SPELL_CONCEALING_FOG);
                    });

            if (concealingFog_select)
            {
                if (summonsList.size() > 1)
                    summonsList.resize(1);
            }

            if (summonsList.empty())
                return;
            int32 num = urand(2, 3);
            Trinity::Containers::RandomResize(summonsList, (summonsList.size() - num) < 1 ? 1 : (summonsList.size() - num));
            for (std::list<Creature*>::iterator summs = summonsList.begin(); summs != summonsList.end(); summs++)
                if ((*summs)->IsAlive())
                    if (randomTarget)
                    {
                        if (Unit* target = (*summs)->AI()->SelectTarget(SELECT_TARGET_RANDOM, 0, 200.0f, true))
                            (*summs)->CastSpell(target, spellId, triggered);
                    }
                    else
                        (*summs)->CastSpell(*summs, spellId, triggered);
        }

        // Used to despawn all summons having a specific entry.
        void DespawnSummon(uint32 entry)
        {
            std::list<Creature*> summonsList;
            GetCreatureListWithEntryInGrid(summonsList, me, entry, 200.0f);
            if (!summonsList.empty())
                for (std::list<Creature*>::iterator summs = summonsList.begin(); summs != summonsList.end(); summs++)
                    if ((*summs)->IsAlive())
                        (*summs)->DespawnOrUnsummon();
        }

        /*** GENERAL AI FUNCTIONS ***/

        void Reset()
        {
            events.Reset();
            summons.DespawnAll();

            // Set Head kills count (at 7 encounter ends), rampage damage count to 0 (20 max) and Megaera's Rage scheduled to false (check used in head scripts for melee range).
            headKills = 0;
            rampageCount = 0;
            isRaging = false;
            isRampaging = false;
            isDead = false;

            // Main boss body doesn't move.
            me->AddUnitState(UNIT_STATE_ROOT);

            me->AddAura(SPELL_CONCEALING_FOG, me);
            me->SetReactState(REACT_DEFENSIVE);

            if (instance)
                instance->SetBossState(DATA_MEGAERA, NOT_STARTED);

            _Reset();

            RPevents.ScheduleEvent(EVENT_START_HEADS, 10000);
        }

        void EnterCombat(Unit* who)
        {
            // Just Berserk scheduled here, the other events are handled by the specific heads / through happenings (ex. a head dies -> Rampage, etc).
            events.ScheduleEvent(EVENT_BERSERK, (me->GetMap()->IsHeroic() ? TIMER_BERSERK_H : TIMER_BERSERK));

            // Put all heads in combat and send the frames for the front ones.
            if (instance)
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

                if (Creature* firstHead = me->FindNearestCreature(NPC_FROZEN_HEAD, 100.0f, true))
                {
                    firstHead->RemoveAura(SPELL_EMERGE); // submerge aura
                    firstHead->RemoveAura(SPELL_CONCEALING_FOG);
                    firstHead->SetReactState(REACT_AGGRESSIVE);
                    firstHead->AI()->DoZoneInCombat(firstHead, 150.0f);
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, firstHead);
                }
                if (Creature* secondHead = me->FindNearestCreature(NPC_VENOMOUS_HEAD, 100.0f, true))
                {
                    secondHead->RemoveAura(SPELL_EMERGE); // submerge aura
                    secondHead->RemoveAura(SPELL_CONCEALING_FOG);
                    secondHead->SetReactState(REACT_AGGRESSIVE);
                    secondHead->AI()->DoZoneInCombat(secondHead, 150.0f);
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, secondHead);
                }
                if (Creature* concealingHead = me->FindNearestCreature(NPC_FLAMING_HEAD, 100.0f, true))
                {
                    concealingHead->RemoveAura(SPELL_EMERGE); // submerge aura
                    concealingHead->SetReactState(REACT_AGGRESSIVE);
                    concealingHead->AI()->DoZoneInCombat(concealingHead, 150.0f);
                }
                if (me->GetMap()->IsHeroic())
                    if (Creature* concealingHead = me->FindNearestCreature(NPC_ARCANE_HEAD, 100.0f, true))
                    {
                        concealingHead->RemoveAura(SPELL_EMERGE); // submerge aura
                        concealingHead->SetReactState(REACT_AGGRESSIVE);
                        concealingHead->AI()->DoZoneInCombat(concealingHead, 150.0f);
                    }

                instance->SetBossState(DATA_MEGAERA, IN_PROGRESS);
            }

            _EnterCombat();
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_SET_IN_COMBAT:
                me->SetReactState(REACT_AGGRESSIVE);
                DoZoneInCombat(me, 150.0f);
                break;

            case ACTION_MEGAERAS_RAGE:
                events.ScheduleEvent(EVENT_MEGAERAS_RAGE, 3000);
                isRaging = true;
                break;

            default: break;
            }
        };

        void removePossibleHead(std::vector<uint32>& possibleHeads, uint32 head)
        {
            for (std::vector<uint32>::iterator it = possibleHeads.begin(); it != possibleHeads.end(); ++it)
                if (head == *it)
                {
                    possibleHeads.erase(it);
                    return;
                }
        }

        uint32 FindNewHeadEntry(uint32 summonEntry)
        {
            uint32 headEntry = 0;
            std::vector<uint32> possibleHeads;
            possibleHeads.push_back(NPC_FLAMING_HEAD);
            possibleHeads.push_back(NPC_FROZEN_HEAD);
            possibleHeads.push_back(NPC_VENOMOUS_HEAD);
            if (me->GetMap()->IsHeroic())
                possibleHeads.push_back(NPC_ARCANE_HEAD);
            removePossibleHead(possibleHeads, summonEntry);
            if (summonEntry == activeHeadEntries.first)
            {
                removePossibleHead(possibleHeads, activeHeadEntries.second);
                headEntry = Trinity::Containers::SelectRandomContainerElement(possibleHeads);
                activeHeadEntries.first = headEntry;
                remainingHead = activeHeadEntries.second;
            }
            else if (summonEntry == activeHeadEntries.second)
            {
                removePossibleHead(possibleHeads, activeHeadEntries.first);
                headEntry = Trinity::Containers::SelectRandomContainerElement(possibleHeads);
                activeHeadEntries.second = headEntry;
                remainingHead = activeHeadEntries.first;
            }

            return headEntry;
        }

        void EnterEvadeMode(EvadeReason w)
        {
            DespawnSummon(NPC_CINDERS);
            DespawnSummon(NPC_TORRENT_OF_ICE);
            DespawnSummon(NPC_ICY_GROUND);
            DespawnSummon(NPC_NETHER_WYRM);

            me->AddUnitState(UNIT_STATE_EVADE);

            RemoveSummonFrame(NPC_FLAMING_HEAD);
            RemoveSummonFrame(NPC_FROZEN_HEAD);
            RemoveSummonFrame(NPC_VENOMOUS_HEAD);
            if (me->GetMap()->IsHeroic())
                RemoveSummonFrame(NPC_ARCANE_HEAD);

            me->RemoveAllAuras();
            me->DeleteThreatList();
            me->CombatStop(true);
            me->GetMotionMaster()->MovementExpired();
            me->GetMotionMaster()->MoveTargetedHome();

            if (instance)
            {
                instance->SetBossState(DATA_MEGAERA, FAIL);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me); // Remove
            }

            _EnterEvadeMode();
        }

        void JustReachedHome()
        {
            me->ClearUnitState(UNIT_STATE_EVADE);

            // This should take care of everything needed.
            Reset();

            _JustReachedHome();
        }

        void SummonedCreatureDespawn(Creature* pSummoned) override
        {
            summons.Despawn(pSummoned);
        }

        void JustSummoned(Creature* summon)
        {
            summons.Summon(summon);
            summon->setActive(true);

            // The heads cannot move.
            if (summon->GetEntry() == NPC_FLAMING_HEAD || summon->GetEntry() == NPC_FROZEN_HEAD || summon->GetEntry() == NPC_VENOMOUS_HEAD || summon->GetEntry() == NPC_ARCANE_HEAD)
            {
                //headGuids.push_back(summon->GetGUID());
                summon->AddUnitState(UNIT_STATE_ROOT);
            }

            // Take care of putting the newly - spawned heads to fight while in combat.
            if (me->IsInCombat())
                summon->SetInCombatWithZone();
        }

        void SummonedCreatureDies(Creature* summon, Unit* killer)
        {
            uint8 newFrontHeadSpawnPos = 0;

            // Just a sanity check. If headKills = 6 -> gets increased to 7 -> Megaera dead.
            if (headKills < 6 && (summon->GetEntry() == NPC_FLAMING_HEAD || summon->GetEntry() == NPC_FROZEN_HEAD ||
                summon->GetEntry() == NPC_VENOMOUS_HEAD || me->GetMap()->IsHeroic() && summon->GetEntry() == NPC_ARCANE_HEAD))
            {
                summon->SetWaterWalking(true);

                if (instance)
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, summon); // Remove

                // Increase killed heads count.
                ++headKills;

                // Remove 15% health each time a head is killed.
                me->SetHealth(me->GetMaxHealth() - ((0.15 * me->GetMaxHealth()) * headKills));

                // Check the head positions and find the right position on which to summon the new ones.
                uint32 summonEntry = summon->GetEntry();
                uint32 newHeadEntry = FindNewHeadEntry(summonEntry);

                switch (summonEntry)
                {
                case NPC_VENOMOUS_HEAD:
                    killedHeads[VENOMOUS_HEAD] += 1;
                    break;
                case NPC_FROZEN_HEAD:
                    killedHeads[FROZEN_HEAD] += 1;
                    break;
                case NPC_FLAMING_HEAD:
                    killedHeads[FLAMING_HEAD] += 1;
                    break;
                case NPC_ARCANE_HEAD:
                    killedHeads[ARCANE_HEAD] += 1;
                    break;
                }

                // And spawn the next ones.
                SpawnNextHeads(summonEntry, newHeadEntry);

                // Hydra Frenzy - set remaining heads + 1 stacks + heal them.
                AddHydraFrenzy(NPC_FLAMING_HEAD);
                AddHydraFrenzy(NPC_FROZEN_HEAD);
                AddHydraFrenzy(NPC_VENOMOUS_HEAD);
                if (me->GetMap()->IsHeroic())
                    AddHydraFrenzy(NPC_ARCANE_HEAD);

                // A head died - schedule Rampage
                events.ScheduleEvent(EVENT_RAMPAGE, 7500);
                isRampaging = true;
            }
            else
            {
                JustDied(killer);
                me->DespawnOrUnsummon(9000);
            }
        }

        void JustDied(Unit* killer)
        {
            if (isDead)
                return;
            isDead = true;

 
            // Achieve
            me->CastSpell(me, SPELL_MEGAERA_ACHIEVEMENT_HANDLER, true);
            DespawnSummon(NPC_CINDERS);
            DespawnSummon(NPC_TORRENT_OF_ICE);
            DespawnSummon(NPC_ICY_GROUND);
            DespawnSummon(NPC_NETHER_WYRM);

            RemoveSummonFrame(NPC_FLAMING_HEAD);
            RemoveSummonFrame(NPC_FROZEN_HEAD);
            RemoveSummonFrame(NPC_VENOMOUS_HEAD);
            if (me->GetMap()->IsHeroic())
                RemoveSummonFrame(NPC_ARCANE_HEAD);

            if (instance)
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                instance->SetBossState(DATA_MEGAERA, DONE);

            }

            for (SummonList::iterator itr = summons.begin(); itr != summons.end(); ++itr)
            {
                if (Unit* pHead = ObjectAccessor::GetCreature(*me, *itr))
                    me->Kill(pHead);
            }

        }

        bool CheckFlyingHacks()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    if (player->IsAlive())
                    {
                        if (player->IsFlying() && !player->IsGameMaster()) // fuck 'em
                        {
                            player->Kill(player, true);
                            player->GetSession()->KickPlayer();
                        }
                    }
                }
            return true;
        }

        void CheckPlayersInWater()
        {
            std::list<Player*> PlayerList;
            GetPlayerListInGrid(PlayerList, me, 300.0f);
            for (auto player : PlayerList)
                if (player->IsInWater())
                {
                    if (player->getClass() == CLASS_ROGUE)
                    {
                        player->NearTeleportTo(6412.45f, 4531.13f, -209.17f, 0.0f, false);
                        continue;
                    }
                    player->Kill(player);
                }
        }

        void UpdateAI(uint32 diff)
        {
            if (me->IsInCombat())
            {
                CheckFlyingHacks();
                CheckPlayersInWater();
            }

            RPevents.Update(diff);

            switch (RPevents.ExecuteEvent())
            {
            case EVENT_START_HEADS:
                if (!SpawnStartingHeads())
                    RPevents.ScheduleEvent(EVENT_START_HEADS, 5000);
                break;
            }

            if (!UpdateVictim() || !CheckInRoom() || me->HasUnitState(UNIT_STATE_CASTING))
                return;

            /* @ RAGELESS FIXME
            if (instance && instance->IsWipe())
            {
                EnterEvadeMode();
                return;
            }
            */

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_SUBMERGE_HEAD:
                    SubmergeHead();
                    break;
                case EVENT_REEMERGE_HEAD:
                    ReEmergeHead();
                    break;
                case EVENT_RELOCATE_HEAD:
                    RelocateHead();
                    break;
                case EVENT_RAMPAGE:
                    if (rampageCount < 20)
                    {
                        // Check and add the auras.
                        if (!me->HasAura(SPELL_RAMPAGE))
                        {
                            Talk(ANN_RAMPAGE);

                            me->AddAura(SPELL_RAMPAGE, me);

                            AddSummonAura(SPELL_RAMPAGE, NPC_FLAMING_HEAD);
                            AddSummonAura(SPELL_RAMPAGE, NPC_FROZEN_HEAD);
                            AddSummonAura(SPELL_RAMPAGE, NPC_VENOMOUS_HEAD);
                            if (me->GetMap()->IsHeroic())
                                AddSummonAura(SPELL_RAMPAGE, NPC_ARCANE_HEAD);

                            for (std::list<ObjectGuid>::const_iterator itr = headGuids.cbegin(); itr != headGuids.cend(); ++itr)
                            {
                                if (Creature* pHead = ObjectAccessor::GetCreature(*me, (*itr)))
                                {
                                    if (pHead->IsAlive() && pHead->AI())
                                        pHead->AI()->DoAction(ACTION_DELAY_EVENTS);
                                }
                            }
                        }

                        // Have each of the specific heads cast the spell (in order).
                        if (!me->GetMap()->IsHeroic())
                        {
                            if (rampageCount == 0 || rampageCount == 3 || rampageCount == 6 || rampageCount == 9 || rampageCount == 12 || rampageCount == 15 || rampageCount == 18)
                                HeadsCastSpell(SPELL_RAMPAGE_FIRE_CAST, NPC_FLAMING_HEAD, true);
                            if (rampageCount == 1 || rampageCount == 4 || rampageCount == 7 || rampageCount == 10 || rampageCount == 13 || rampageCount == 16 || rampageCount == 19)
                                HeadsCastSpell(SPELL_RAMPAGE_FROST_CAST, NPC_FROZEN_HEAD, true);
                            if (rampageCount == 2 || rampageCount == 5 || rampageCount == 8 || rampageCount == 11 || rampageCount == 14 || rampageCount == 17)
                                HeadsCastSpell(SPELL_RAMPAGE_POISON_CAST, NPC_VENOMOUS_HEAD, true);
                        }
                        else // Heroic!
                        {
                            if (rampageCount == 0 || rampageCount == 4 || rampageCount == 8 || rampageCount == 12 || rampageCount == 16)
                                HeadsCastSpell(SPELL_RAMPAGE_FIRE_CAST, NPC_FLAMING_HEAD, true);
                            if (rampageCount == 1 || rampageCount == 5 || rampageCount == 9 || rampageCount == 13 || rampageCount == 17)
                                HeadsCastSpell(SPELL_RAMPAGE_FROST_CAST, NPC_FROZEN_HEAD, true);
                            if (rampageCount == 2 || rampageCount == 6 || rampageCount == 10 || rampageCount == 14 || rampageCount == 18)
                                HeadsCastSpell(SPELL_RAMPAGE_POISON_CAST, NPC_VENOMOUS_HEAD, true);
                            if (rampageCount == 3 || rampageCount == 7 || rampageCount == 11 || rampageCount == 15 || rampageCount == 19)
                                HeadsCastSpell(SPELL_RAMPAGE_ARCANE_CAST, NPC_ARCANE_HEAD, true);
                        }

                        // Increase the count and reschedule the event.
                        rampageCount++;
                        events.ScheduleEvent(EVENT_RAMPAGE, 1500);
                    }
                    else
                    {
                        // Check and remove the auras.
                        if (me->HasAura(SPELL_RAMPAGE))
                        {
                            Talk(ANN_SUBSIDE);

                            me->RemoveAurasDueToSpell(SPELL_RAMPAGE);

                            RemoveSummonAura(SPELL_RAMPAGE, NPC_FLAMING_HEAD);
                            RemoveSummonAura(SPELL_RAMPAGE, NPC_FROZEN_HEAD);
                            RemoveSummonAura(SPELL_RAMPAGE, NPC_VENOMOUS_HEAD);
                            if (me->GetMap()->IsHeroic())
                                RemoveSummonAura(SPELL_RAMPAGE, NPC_ARCANE_HEAD);
                        }

                        rampageCount = 0;
                        isRampaging = false;
                    }
                    break;

                case EVENT_MEGAERAS_RAGE:
                    if (isRaging)
                    {
                        // Have each of the specific heads cast the spell (in order).
                        HeadsCastSpell(SPELL_MEGAERAS_RAGE_FIRE, NPC_FLAMING_HEAD, true, false, true);
                        HeadsCastSpell(SPELL_MEGAERAS_RAGE_FROST, NPC_FROZEN_HEAD, true, false, true);
                        HeadsCastSpell(SPELL_MEGAERAS_RAGE_POISON, NPC_VENOMOUS_HEAD, true, false, true);
                        if (me->GetMap()->IsHeroic())
                            HeadsCastSpell(SPELL_MEGAERAS_RAGE_ARCANE, NPC_ARCANE_HEAD, true, false, true);

                        isRaging = false;
                    }
                    break;

                case EVENT_BERSERK:
                    DoCast(me, SPELL_BERSERK);
                    HeadsCastSpell(SPELL_BERSERK, NPC_FLAMING_HEAD);
                    HeadsCastSpell(SPELL_BERSERK, NPC_FROZEN_HEAD);
                    HeadsCastSpell(SPELL_BERSERK, NPC_VENOMOUS_HEAD);
                    if (me->GetMap()->IsHeroic())
                        HeadsCastSpell(SPELL_BERSERK, NPC_ARCANE_HEAD);
                    break;

                default: break;
                }
            }

            // No melee from body.
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_megaeraAI(creature);
    }
};

// Flaming Head 70212.
class npc_flaming_head_megaera : public CreatureScript
{
public:
    npc_flaming_head_megaera() : CreatureScript("npc_flaming_head_megaera") { }

    struct npc_flaming_head_megaeraAI : public ScriptedAI
    {
        npc_flaming_head_megaeraAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
            SetCombatMovement(false);
            me->ApplySpellImmune(0, IMMUNITY_ID, 108199, true); // Gorefiend's Grasp
            me->ApplySpellImmune(0, IMMUNITY_ID, 31935, true); // Avenger's Shield
        }

        InstanceScript* instance;
        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void DoAction(int32 iAction) override
        {
            if (iAction == ACTION_DELAY_EVENTS)
                events.DelayEvents(20000);
        }

        void JustSummoned(Creature* pSummoned) override
        {
            if (pSummoned)
            {
                if (Aura* pAura = me->GetAura(SPELL_ELEMENTAL_BONDS_FIRE))
                {
                    int32 offset = pAura->GetStackAmount();

                    if (Aura* pAura = me->AddAura(SPELL_ELEMENTAL_BONDS_FIRE, pSummoned))
                        pAura->ModStackAmount(offset - 1);
                }
            }
        }

        void SpellHit(Unit* pCaster, SpellInfo const* pSpell) override
        {
            if (pSpell->Id == SPELL_SUBMERGE)
            {
                if (!me->HasAura(SPELL_EMERGE))
                    me->AddAura(SPELL_EMERGE, me);

                me->RemoveAurasDueToSpell(SPELL_SUBMERGE);
            }
        }

        void SetData(uint32 type, uint32 data)
        {
            if (type == 1)
            {
                events.Reset();
                events.ScheduleEvent(EVENT_CINDERS, 24000, 0, 0);
                events.ScheduleEvent(EVENT_CHECK_MEGAERAS_RAGE, 18900);
                events.ScheduleEvent(EVENT_IGNITE_FLESH, 7000);
            }
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_CHECK_MEGAERAS_RAGE, 18000);
            events.ScheduleEvent(EVENT_CINDERS, urand(10000, 15000));
            events.ScheduleEvent(EVENT_IGNITE_FLESH, 7000);

            if (Creature* Megaera = me->FindNearestCreature(BOSS_MEGAERA, 200.0f, true))
                if (!Megaera->IsInCombat())
                    Megaera->AI()->DoAction(ACTION_SET_IN_COMBAT);
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING) || me->HasAura(SPELL_EMERGE))
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHECK_MEGAERAS_RAGE:
                    // Must be one of the heads in front.
                    if (!me->HasAura(SPELL_CONCEALING_FOG))
                    {
                        // Find boss and check for melee distance to victim + unscheduled boss action.
                        if (Creature* Megaera = me->FindNearestCreature(BOSS_MEGAERA, 200.0f, true))
                            if (CAST_AI(boss_megaera::boss_megaeraAI, Megaera->AI())->isRampaging == false)
                                if (!me->IsWithinMeleeRange(me->GetVictim()))
                                    DoCast(me->GetVictim(), SPELL_MEGAERAS_RAGE_FIRE);
                    }
                    events.ScheduleEvent(EVENT_CHECK_MEGAERAS_RAGE, 4000);
                    break;

                case EVENT_CINDERS:
                {
                    if (Creature* Megaera = me->FindNearestCreature(BOSS_MEGAERA, 200.0f, true))
                    {
                        if (me->HasAura(SPELL_CONCEALING_FOG) && !me->HasAura(SPELL_EMERGE))
                        {
                            if (CAST_AI(boss_megaera::boss_megaeraAI, Megaera->AI())->isRampaging == false)
                            {
                                std::list<Unit*> targets;
                                SelectTargetList(targets, 5, SELECT_TARGET_RANDOM, 500.0f, true);
                                if (!targets.empty())
                                    if (targets.size() >= 1)
                                        targets.resize(1);

                                for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                                    me->CastSpell((*itr), SPELL_CINDERS);
                            }
                        }
                        //DoCast(me, SPELL_CINDERS);
                        events.ScheduleEvent(EVENT_CINDERS, (me->GetMap()->IsHeroic() ? urand(54000, 60000) : urand(23000, 29000)));
                    }
                    break;
                }
                case EVENT_IGNITE_FLESH:
                    if (Creature* Megaera = me->FindNearestCreature(BOSS_MEGAERA, 200.0f, true))
                    {
                        if (!me->HasAura(SPELL_CONCEALING_FOG) && !me->HasAura(SPELL_EMERGE))
                        {
                            if (CAST_AI(boss_megaera::boss_megaeraAI, Megaera->AI())->isRampaging == false)
                            {
                                //me->SetFacingToObject(me->GetVictim());
                                me->CastSpell(me->GetVictim(), SPELL_IGNITE_FLESH);
                            }
                            events.ScheduleEvent(EVENT_IGNITE_FLESH, 18000);
                        }
                    }
                    break;

                default: break;
                }
            }

            // Can't melee from the fog.
            if (Creature* Megaera = me->FindNearestCreature(BOSS_MEGAERA, 200.0f, true))
                if (!me->HasAura(SPELL_CONCEALING_FOG) && !me->HasAura(SPELL_EMERGE))
                    if (CAST_AI(boss_megaera::boss_megaeraAI, Megaera->AI())->isRampaging == false)
                        DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_flaming_head_megaeraAI(creature);
    }
};

// Frozen Head 70235.
class npc_frozen_head_megaera : public CreatureScript
{
public:
    npc_frozen_head_megaera() : CreatureScript("npc_frozen_head_megaera") { }

    struct npc_frozen_head_megaeraAI : public ScriptedAI
    {
        npc_frozen_head_megaeraAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
            SetCombatMovement(false);
            me->ApplySpellImmune(0, IMMUNITY_ID, 108199, true); // Gorefiend's Grasp
            me->ApplySpellImmune(0, IMMUNITY_ID, 31935, true); // Avenger's Shield
        }

        InstanceScript* instance;
        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void DoAction(int32 iAction) override
        {
            if (iAction == ACTION_DELAY_EVENTS)
                events.DelayEvents(20000);
        }

        void JustSummoned(Creature* pSummoned) override
        {
            if (pSummoned)
            {
                if (Aura* pAura = me->GetAura(SPELL_ELEMENTAL_BONDS_FROST))
                {
                    int32 offset = pAura->GetStackAmount();

                    if (Aura* pAura = me->AddAura(SPELL_ELEMENTAL_BONDS_FROST, pSummoned))
                        pAura->ModStackAmount(offset - 1);
                }
            }
        }

        void SpellHit(Unit* pCaster, SpellInfo const* pSpell) override
        {
            if (pSpell->Id == SPELL_SUBMERGE)
            {
                if (!me->HasAura(SPELL_EMERGE))
                    me->AddAura(SPELL_EMERGE, me);

                me->RemoveAurasDueToSpell(SPELL_SUBMERGE);
            }
        }

        void SetData(uint32 type, uint32 data)
        {
            if (type == 1)
            {
                events.Reset();
                events.ScheduleEvent(EVENT_TORRENT_OF_ICE, 24000, 0, 0);
                events.ScheduleEvent(EVENT_CHECK_MEGAERAS_RAGE, 18900);
                events.ScheduleEvent(EVENT_ARCTIC_FREEZE, urand(7000, 12000));
            }
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_CHECK_MEGAERAS_RAGE, 18900);
            events.ScheduleEvent(EVENT_TORRENT_OF_ICE, 14000);
            events.ScheduleEvent(EVENT_ARCTIC_FREEZE, urand(7000, 12000));

            if (Creature* Megaera = me->FindNearestCreature(BOSS_MEGAERA, 200.0f, true))
                if (!Megaera->IsInCombat())
                    Megaera->AI()->DoAction(ACTION_SET_IN_COMBAT);
        }

        Unit* SelectTorrentOfIceTarget() const
        {
            if (Creature* Megaera = me->FindNearestCreature(BOSS_MEGAERA, 200.0f, true))
            {
                std::list<Creature*> heads = (CAST_AI(boss_megaera::boss_megaeraAI, Megaera->AI())->GetActiveHeadList());
                std::list<Player*> potentials;
                std::list<Player*> backupList;

                GetPlayerListInGrid(potentials, me, 250.f);
                std::copy(std::begin(potentials), std::end(potentials), std::inserter(backupList, std::begin(backupList)));

                potentials.remove_if([this, heads](Player const* pPlayer) -> bool
                    {
                        if (pPlayer->HasAura(SPELL_TORRENT_OF_ICE_TARGET))
                            return true;

                        if (pPlayer->HasAura(SPELL_CINDERS))
                            return true;

                        for (auto pHead : heads)
                        {
                            if (pPlayer->GetExactDist2d(pHead) < 15.f)
                                return true;
                        }

                        return false;
                    });

                if (!potentials.empty())
                    return Trinity::Containers::SelectRandomContainerElement(potentials);

                if (!backupList.empty())
                    return Trinity::Containers::SelectRandomContainerElement(backupList);
            }

            return nullptr;
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING) || me->HasAura(SPELL_EMERGE))
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHECK_MEGAERAS_RAGE:
                    // Must be one of the heads in front.
                    if (!me->HasAura(SPELL_CONCEALING_FOG))
                    {
                        // Find boss and check for melee distance to victim + unscheduled boss action.
                        if (Creature* Megaera = me->FindNearestCreature(BOSS_MEGAERA, 200.0f, true))
                            if (CAST_AI(boss_megaera::boss_megaeraAI, Megaera->AI())->isRampaging == false)
                                if (!me->IsWithinMeleeRange(me->GetVictim()))
                                    DoCast(me->GetVictim(), SPELL_MEGAERAS_RAGE_FROST);
                    }
                    events.ScheduleEvent(EVENT_CHECK_MEGAERAS_RAGE, 4000);
                    break;

                case EVENT_TORRENT_OF_ICE:
                {
                    if (Creature* Megaera = me->FindNearestCreature(BOSS_MEGAERA, 200.0f, true))
                    {
                        if (me->HasAura(SPELL_CONCEALING_FOG) && !me->HasAura(SPELL_EMERGE))
                        {
                            if (CAST_AI(boss_megaera::boss_megaeraAI, Megaera->AI())->isRampaging == false)
                            {
                                std::list<Unit*> targets;
                                SelectTargetList(targets, 5, SELECT_TARGET_RANDOM, 500.0f, true);
                                if (!targets.empty())
                                    if (targets.size() >= 1)
                                        targets.resize(1);

                                for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                                {
                                    me->AddAura(SPELL_TORRENT_OF_ICE_TARGET, (*itr));
                                    if (Creature* torrent = me->SummonCreature(NPC_TORRENT_OF_ICE, (*itr)->GetPositionX(), (*itr)->GetPositionY(), (*itr)->GetPositionZ(), 0.0f, TEMPSUMMON_TIMED_DESPAWN, 12000))
                                    {
                                        torrent->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
                                        torrent->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
                                        torrent->GetMotionMaster()->MoveChase((*itr), 1.0f);
                                        torrent->AI()->AttackStart((*itr));
                                        //if (Aura* pAura = torrent->AddAura(SPELL_TORRENT_OF_ICE_NPC_A, torrent))
                                       //     pAura->SetDuration(9000);
                                        torrent->SetReactState(REACT_PASSIVE);
                                        me->InterruptNonMeleeSpells(true);
                                        me->CastSpell(torrent, SPELL_TORRENT_OF_ICE);
                                        torrent->AddThreat((*itr), 99999999.9f);
                                    }
                                }
                            }
                            events.ScheduleEvent(EVENT_TORRENT_OF_ICE, urand(26000, 30000));
                        }
                    }
                    break;
                }
                case EVENT_ARCTIC_FREEZE:
                    if (Creature* Megaera = me->FindNearestCreature(BOSS_MEGAERA, 200.0f, true))
                    {
                        if (!me->HasAura(SPELL_CONCEALING_FOG) && !me->HasAura(SPELL_EMERGE))
                        {
                            if (CAST_AI(boss_megaera::boss_megaeraAI, Megaera->AI())->isRampaging == false)
                            {
                                //me->SetFacingToObject(me->GetVictim());
                                DoCast(me->GetVictim(), SPELL_ARCTIC_FREEZE);
                            }
                            events.ScheduleEvent(EVENT_ARCTIC_FREEZE, urand(18000, 23000));
                        }
                    }
                    break;

                default: break;
                }
            }

            // Can't melee from the fog.
            if (Creature* Megaera = me->FindNearestCreature(BOSS_MEGAERA, 200.0f, true))
                if (!me->HasAura(SPELL_CONCEALING_FOG) && !me->HasAura(SPELL_EMERGE))
                    if (CAST_AI(boss_megaera::boss_megaeraAI, Megaera->AI())->isRampaging == false)
                        DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_frozen_head_megaeraAI(creature);
    }
};

// Venomous Head 70247.
class npc_venomous_head_megaera : public CreatureScript
{
public:
    npc_venomous_head_megaera() : CreatureScript("npc_venomous_head_megaera") { }

    struct npc_venomous_head_megaeraAI : public ScriptedAI
    {
        npc_venomous_head_megaeraAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
            SetCombatMovement(false);
            me->ApplySpellImmune(0, IMMUNITY_ID, 108199, true); // Gorefiend's Grasp
            me->ApplySpellImmune(0, IMMUNITY_ID, 31935, true); // Avenger's Shield
        }

        InstanceScript* instance;
        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void DoAction(int32 iAction) override
        {
            if (iAction == ACTION_DELAY_EVENTS)
                events.DelayEvents(20000);
        }

        void JustSummoned(Creature* pSummoned) override
        {
            if (pSummoned)
            {
                if (Aura* pAura = me->GetAura(SPELL_ELEMENTAL_BONDS_VENOM))
                {
                    int32 offset = pAura->GetStackAmount();

                    if (Aura* pAura = me->AddAura(SPELL_ELEMENTAL_BONDS_VENOM, pSummoned))
                        pAura->ModStackAmount(offset - 1);
                }
            }
        }

        void SpellHit(Unit* pCaster, SpellInfo const* pSpell) override
        {
            if (pSpell->Id == SPELL_SUBMERGE)
            {
                if (!me->HasAura(SPELL_EMERGE))
                    me->AddAura(SPELL_EMERGE, me);

                me->RemoveAurasDueToSpell(SPELL_SUBMERGE);
            }
        }

        void SetData(uint32 type, uint32 data)
        {
            if (type == 1)
            {
                events.Reset();
                events.ScheduleEvent(EVENT_ACID_RAIN, 27000, 0, 0);
                events.ScheduleEvent(EVENT_CHECK_MEGAERAS_RAGE, 18900);
                events.ScheduleEvent(EVENT_ROT_ARMOR, urand(7000, 12000));
            }
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_CHECK_MEGAERAS_RAGE, 19800);
            events.ScheduleEvent(EVENT_ACID_RAIN, urand(12000, 17000));
            events.ScheduleEvent(EVENT_ROT_ARMOR, urand(10000, 15000));

            if (Creature* Megaera = me->FindNearestCreature(BOSS_MEGAERA, 200.0f, true))
                if (!Megaera->IsInCombat())
                    Megaera->AI()->DoAction(ACTION_SET_IN_COMBAT);
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING) || me->HasAura(SPELL_EMERGE))
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHECK_MEGAERAS_RAGE:
                    // Must be one of the heads in front.
                    if (!me->HasAura(SPELL_CONCEALING_FOG))
                    {
                        // Find boss and check for melee distance to victim + unscheduled boss action.
                        if (Creature* Megaera = me->FindNearestCreature(BOSS_MEGAERA, 200.0f, true))
                            if (CAST_AI(boss_megaera::boss_megaeraAI, Megaera->AI())->isRampaging == false)
                                if (!me->IsWithinMeleeRange(me->GetVictim()))
                                    DoCast(me->GetVictim(), SPELL_MEGAERAS_RAGE_POISON);
                    }
                    events.ScheduleEvent(EVENT_CHECK_MEGAERAS_RAGE, 4000);
                    break;

                case EVENT_ACID_RAIN:
                    if (Creature* Megaera = me->FindNearestCreature(BOSS_MEGAERA, 200.0f, true))
                    {
                        if (me->HasAura(SPELL_CONCEALING_FOG) && !me->HasAura(SPELL_EMERGE))
                        {
                            if (CAST_AI(boss_megaera::boss_megaeraAI, Megaera->AI())->isRampaging == false)
                                me->CastSpell(me, SPELL_ACID_RAIN_SUMMON);
                            events.ScheduleEvent(EVENT_ACID_RAIN, (me->GetMap()->IsHeroic() ? urand(54000, 60000) : urand(23000, 29000)));
                        }
                    }
                    break;

                case EVENT_ROT_ARMOR:
                    if (Creature* Megaera = me->FindNearestCreature(BOSS_MEGAERA, 200.0f, true))
                    {
                        if (!me->HasAura(SPELL_CONCEALING_FOG) && !me->HasAura(SPELL_EMERGE))
                        {
                            if (CAST_AI(boss_megaera::boss_megaeraAI, Megaera->AI())->isRampaging == false)
                            {
                                //me->SetFacingToObject(me->GetVictim());
                                DoCast(me->GetVictim(), SPELL_ROT_ARMOR);
                            }
                            events.ScheduleEvent(EVENT_ROT_ARMOR, urand(18000, 23000));
                        }
                    }
                    break;

                default: break;
                }
            }

            // Can't melee from the fog.
            if (Creature* Megaera = me->FindNearestCreature(BOSS_MEGAERA, 200.0f, true))
                if (!me->HasAura(SPELL_CONCEALING_FOG) && !me->HasAura(SPELL_EMERGE))
                    if (CAST_AI(boss_megaera::boss_megaeraAI, Megaera->AI())->isRampaging == false)
                        DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_venomous_head_megaeraAI(creature);
    }
};

// Arcane Head 70252 - Heroic only!
class npc_arcane_head_megaera : public CreatureScript
{
public:
    npc_arcane_head_megaera() : CreatureScript("npc_arcane_head_megaera") { }

    struct npc_arcane_head_megaeraAI : public ScriptedAI
    {
        npc_arcane_head_megaeraAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
            SetCombatMovement(false);
            me->ApplySpellImmune(0, IMMUNITY_ID, 108199, true); // Gorefiend's Grasp
            me->ApplySpellImmune(0, IMMUNITY_ID, 31935, true); // Avenger's Shield
        }

        InstanceScript* instance;
        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void DoAction(int32 iAction) override
        {
            if (iAction == ACTION_DELAY_EVENTS)
                events.DelayEvents(20000);
        }

        void JustSummoned(Creature* pSummoned) override
        {
            if (pSummoned)
            {
                if (Aura* pAura = me->GetAura(SPELL_ELEMENTAL_BONDS_ARCAN))
                {
                    int32 offset = pAura->GetStackAmount();

                    if (Aura* pAura = me->AddAura(SPELL_ELEMENTAL_BONDS_ARCAN, pSummoned))
                        pAura->ModStackAmount(offset - 1);
                }
            }
        }

        void SpellHit(Unit* pCaster, SpellInfo const* pSpell) override
        {
            if (pSpell->Id == SPELL_SUBMERGE)
            {
                if (!me->HasAura(SPELL_EMERGE))
                    me->AddAura(SPELL_EMERGE, me);

                me->RemoveAurasDueToSpell(SPELL_SUBMERGE);
            }
        }

        void SetData(uint32 type, uint32 data)
        {
            if (type == 1)
            {
                events.Reset();
                events.ScheduleEvent(EVENT_NETHER_TEAR, 27000, 0, 0);
                events.ScheduleEvent(EVENT_CHECK_MEGAERAS_RAGE, 18900);
                events.ScheduleEvent(EVENT_DIFFUSION, 7000);
            }
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_CHECK_MEGAERAS_RAGE, 20600);
            events.ScheduleEvent(EVENT_NETHER_TEAR, urand(12000, 17000));
            events.ScheduleEvent(EVENT_DIFFUSION, 7000);

            if (Creature* Megaera = me->FindNearestCreature(BOSS_MEGAERA, 200.0f, true))
                if (!Megaera->IsInCombat())
                    Megaera->AI()->DoAction(ACTION_SET_IN_COMBAT);
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING) || me->HasAura(SPELL_EMERGE))
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHECK_MEGAERAS_RAGE:
                    // Must be one of the heads in front.
                    if (!me->HasAura(SPELL_CONCEALING_FOG))
                    {
                        // Find boss and check for melee distance to victim + unscheduled boss action.
                        if (Creature* Megaera = me->FindNearestCreature(BOSS_MEGAERA, 200.0f, true))
                            if (CAST_AI(boss_megaera::boss_megaeraAI, Megaera->AI())->isRampaging == false)
                                if (!me->IsWithinMeleeRange(me->GetVictim()))
                                    DoCast(me->GetVictim(), SPELL_MEGAERAS_RAGE_ARCANE);
                    }
                    events.ScheduleEvent(EVENT_CHECK_MEGAERAS_RAGE, 4000);
                    break;

                case EVENT_NETHER_TEAR:
                    if (Creature* Megaera = me->FindNearestCreature(BOSS_MEGAERA, 200.0f, true))
                    {
                        if (me->HasAura(SPELL_CONCEALING_FOG) && !me->HasAura(SPELL_EMERGE))
                        {
                            if (CAST_AI(boss_megaera::boss_megaeraAI, Megaera->AI())->isRampaging == false)
                            {
                                std::list<Unit*> targets;
                                SelectTargetList(targets, 5, SELECT_TARGET_RANDOM, 500.0f, true);
                                if (!targets.empty())
                                    if (targets.size() >= 1)
                                        targets.resize(1);

                                for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                                {
                                    me->CastSpell((*itr), 140258, true); // nether tear visual
                                    me->SummonCreature(NPC_NETHER_TEAR, (*itr)->GetPositionX(), (*itr)->GetPositionY(), (*itr)->GetPositionZ(), (*itr)->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 7000);
                                }
                            }
                            events.ScheduleEvent(EVENT_NETHER_TEAR, urand(22000, 27000));
                        }
                    }
                    break;

                case EVENT_DIFFUSION:
                    if (Creature* Megaera = me->FindNearestCreature(BOSS_MEGAERA, 200.0f, true))
                    {
                        if (!me->HasAura(SPELL_CONCEALING_FOG) && !me->HasAura(SPELL_EMERGE))
                        {
                            if (CAST_AI(boss_megaera::boss_megaeraAI, Megaera->AI())->isRampaging == false)
                            {
                                //me->SetFacingToObject(me->GetVictim());
                                me->CastSpell(me->GetVictim(), SPELL_DIFFUSION);
                            }
                            events.ScheduleEvent(EVENT_DIFFUSION, 18000);
                        }
                    }
                    break;

                default: break;
                }
            }

            // Can't melee from the fog.
            if (Creature* Megaera = me->FindNearestCreature(BOSS_MEGAERA, 200.0f, true))
                if (!me->HasAura(SPELL_CONCEALING_FOG) && !me->HasAura(SPELL_EMERGE))
                    if (CAST_AI(boss_megaera::boss_megaeraAI, Megaera->AI())->isRampaging == false)
                        DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_arcane_head_megaeraAI(creature);
    }
};

// Cinders 70432.
class npc_cinders_megaera : public CreatureScript
{
public:
    npc_cinders_megaera() : CreatureScript("npc_cinders_megaera") { }

    struct npc_cinders_megaeraAI : public ScriptedAI
    {
        npc_cinders_megaeraAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        void IsSummonedBy(Unit* /*summoner*/) override
        {
            me->AddAura(SPELL_CINDERS_AURA, me);
        }

        void Reset() override
        {
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->AddUnitState(UNIT_STATE_ROOT);
            me->SetReactState(REACT_PASSIVE);
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_cinders_megaeraAI(creature);
    }
};

// Icy Ground 70446.
class npc_icy_ground_megaera : public CreatureScript
{
public:
    npc_icy_ground_megaera() : CreatureScript("npc_icy_ground_megaera") { }

    struct npc_icy_ground_megaeraAI : public ScriptedAI
    {
        npc_icy_ground_megaeraAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;
        uint8 growTicks;
        bool despawned;

        void IsSummonedBy(Unit* /*summoner*/)
        {
            Reset();
            me->AddAura(SPELL_ICY_GROUND_VISUAL, me);
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE); 
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->AddUnitState(UNIT_STATE_ROOT);
            me->SetReactState(REACT_PASSIVE);
            events.ScheduleEvent(EVENT_APPLYSLOW_TO_PLAYERS, 1000, 0, 0);
            events.ScheduleEvent(EVENT_ICY_GROUND_GROW, 5000);
        }

        void Reset()
        {
            events.Reset();

            growTicks = 0;
            despawned = false;
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                    if (player->GetDistance(me) < 3.0f)
                    {
                        if (player->HasAura(SPELL_CINDERS))
                            me->DespawnOrUnsummon();
                    }

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ICY_GROUND_GROW:
                    if (me->GetMap()->IsHeroic())
                        me->AddAura(SPELL_ICY_GROUND_GROW, me);
                    events.ScheduleEvent(EVENT_ICY_GROUND_GROW, 2000);
                    break;
                case EVENT_APPLYSLOW_TO_PLAYERS:
                {
                    Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                    for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                        if (Player* player = i->GetSource())
                            if (player->GetDistance(me) < 3.0f)
                                if (!player->HasAura(SPELL_ICY_GROUND_AURA)) // don't add aura if player already has it
                                    me->AddAura(SPELL_ICY_GROUND_AURA, player);
                    events.ScheduleEvent(EVENT_APPLYSLOW_TO_PLAYERS, 2000, 0, 0);
                    break;
                }
                }
            }

            // No melee.
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_icy_ground_megaeraAI(creature);
    }
};

class npc_torrent_of_ice : public CreatureScript
{
public:
    npc_torrent_of_ice() : CreatureScript("npc_torrent_of_ice") {}

    struct ai_impl : public ScriptedAI
    {
        ai_impl(Creature* pCreature) : ScriptedAI(pCreature)
        {
        }

        EventMap events;

        void IsSummonedBy(Unit*)
        {
            me->AddAura(42716, me);
            me->DespawnOrUnsummon(12000);
            //events.ScheduleEvent(EVENT_SUMMON_ICY_GROUND, 1000, 0, 0);
            events.ScheduleEvent(EVENT_TORRENT_SELECTION, 2000, 0, 0);
        }

        void UpdateAI(uint32 diff)
        {
            if (Creature* cinders = me->FindNearestCreature(NPC_CINDERS, 5.0f, true))
                cinders->DespawnOrUnsummon();

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_SUMMON_ICY_GROUND:
                    me->SummonCreature(NPC_ICY_GROUND, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 60000);
                    events.ScheduleEvent(EVENT_SUMMON_ICY_GROUND, 2000, 0, 0);
                    break;
                case EVENT_TORRENT_SELECTION:
                {
                    Unit* target = me->GetVictim();
                    if (!target)
                        me->DespawnOrUnsummon();
                    if (Aura* pAura = me->AddAura(SPELL_TORRENT_OF_ICE_NPC_A, me))
                        pAura->SetDuration(9000);
                    me->RemoveAura(42716);
                    me->GetMotionMaster()->MoveChase(target);
                    events.ScheduleEvent(EVENT_SUMMON_ICY_GROUND, 500, 0, 0);
                    break;
                }
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new ai_impl(pCreature);
    }
};

// Nether Wyrm 70507 - From Arcane Head - Heroic only!
class npc_nether_wyrm_megaera : public CreatureScript
{
public:
    npc_nether_wyrm_megaera() : CreatureScript("npc_nether_wyrm_megaera") { }

    struct npc_nether_wyrm_megaeraAI : public ScriptedAI
    {
        npc_nether_wyrm_megaeraAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;

        void IsSummonedBy(Unit* /*summoner*/)
        {
            Reset();
        }

        void Reset()
        {
            events.Reset();
            DoZoneInCombat(me, 150.0f);

            events.ScheduleEvent(EVENT_NETHER_SPIKE, urand(3000, 7000));
            events.ScheduleEvent(EVENT_SUPPRESSION, urand(9000, 14000));
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_NETHER_SPIKE:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                        DoCast(target, SPELL_NETHER_SPIKE);
                    events.ScheduleEvent(EVENT_NETHER_SPIKE, urand(7000, 11000));
                    break;

                case EVENT_SUPPRESSION:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                        DoCast(target, SPELL_SUPPRESSION);
                    events.ScheduleEvent(EVENT_SUPPRESSION, urand(18000, 23000));
                    break;

                default: break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_nether_wyrm_megaeraAI(creature);
    }
};

// Concealing Fog - 137973.
class spell_concealing_fog_megaera : public SpellScriptLoader
{
public:
    spell_concealing_fog_megaera() : SpellScriptLoader("spell_concealing_fog_megaera") { }

    class spell_concealing_fog_megaera_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_concealing_fog_megaera_AuraScript);

        void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetTarget();
            if (!caster || !target)
                return;

            target->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
        }

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetTarget();
            if (!caster || !target)
                return;

            target->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
        }

        void Register()
        {
            OnEffectApply += AuraEffectApplyFn(spell_concealing_fog_megaera_AuraScript::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(spell_concealing_fog_megaera_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_concealing_fog_megaera_AuraScript();
    }
};

// Rampage - Flaming Head 139548 (damage).
class spell_rampage_flaming_head_megaera : public SpellScriptLoader
{
public:
    spell_rampage_flaming_head_megaera() : SpellScriptLoader("spell_rampage_flaming_head_megaera") { }

    class spell_rampage_flaming_head_megaera_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_rampage_flaming_head_megaera_SpellScript);

        void CalculateDamage(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (!caster->ToCreature())
                return;

            if (caster->ToCreature()->GetEntry() != NPC_FLAMING_HEAD)
                return;

            Creature* Megaera = caster->FindNearestCreature(BOSS_MEGAERA, 200.0f, true);
            if (!Megaera)
                return;

            int32 extraHeads = CAST_AI(boss_megaera::boss_megaeraAI, Megaera->AI())->GetExtraHeadsCount(NPC_FLAMING_HEAD);
            //SetHitDamage(int32(GetHitDamage() + ((GetHitDamage() / 4) * extraHeads))); // Increases by 25% for each extra head.
            if (Megaera->GetMap()->IsHeroic()) // check if boss is on heroic map, if yes the % should be 35% else 25% on normal
            {
                uint32 damage = GetHitDamage();
                AddPct(damage, 35 * extraHeads);
                SetHitDamage(damage);
            }
            else
            {
                uint32 damage = GetHitDamage();
                AddPct(damage, 25 * extraHeads);
                SetHitDamage(damage);
            }
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_rampage_flaming_head_megaera_SpellScript::CalculateDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_rampage_flaming_head_megaera_SpellScript();
    }
};

// Rampage - Frozen Head 139549 (damage).
class spell_rampage_frozen_head_megaera : public SpellScriptLoader
{
public:
    spell_rampage_frozen_head_megaera() : SpellScriptLoader("spell_rampage_frozen_head_megaera") { }

    class spell_rampage_frozen_head_megaera_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_rampage_frozen_head_megaera_SpellScript);

        void CalculateDamage(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (!caster->ToCreature())
                return;

            if (caster->ToCreature()->GetEntry() != NPC_FROZEN_HEAD)
                return;

            Creature* Megaera = caster->FindNearestCreature(BOSS_MEGAERA, 200.0f, true);
            if (!Megaera)
                return;

            int32 extraHeads = CAST_AI(boss_megaera::boss_megaeraAI, Megaera->AI())->GetExtraHeadsCount(NPC_FROZEN_HEAD);
            //SetHitDamage(int32(GetHitDamage() + ((GetHitDamage() / 4) * extraHeads))); // Increases by 25% for each extra head.
            if (Megaera->GetMap()->IsHeroic()) // check if boss is on heroic map, if yes the % should be 35% else 25% on normal
            {
                uint32 damage = GetHitDamage();
                AddPct(damage, 35 * extraHeads);
                SetHitDamage(damage);
            }
            else
            {
                uint32 damage = GetHitDamage();
                AddPct(damage, 25 * extraHeads);
                SetHitDamage(damage);
            }
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_rampage_frozen_head_megaera_SpellScript::CalculateDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_rampage_frozen_head_megaera_SpellScript();
    }
};

// Rampage - Venomous Head 139551 (damage).
class spell_rampage_venomous_head_megaera : public SpellScriptLoader
{
public:
    spell_rampage_venomous_head_megaera() : SpellScriptLoader("spell_rampage_venomous_head_megaera") { }

    class spell_rampage_venomous_head_megaera_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_rampage_venomous_head_megaera_SpellScript);

        void CalculateDamage(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (!caster->ToCreature())
                return;

            if (caster->ToCreature()->GetEntry() != NPC_VENOMOUS_HEAD)
                return;

            Creature* Megaera = caster->FindNearestCreature(BOSS_MEGAERA, 200.0f, true);
            if (!Megaera)
                return;

            int32 extraHeads = CAST_AI(boss_megaera::boss_megaeraAI, Megaera->AI())->GetExtraHeadsCount(NPC_VENOMOUS_HEAD);
            //SetHitDamage(int32(GetHitDamage() + ((GetHitDamage() / 4) * extraHeads))); // Increases by 25% for each extra head.
            if (Megaera->GetMap()->IsHeroic()) // check if boss is on heroic map, if yes the % should be 35% else 25% on normal
            {
                uint32 damage = GetHitDamage();
                AddPct(damage, 35 * extraHeads);
                SetHitDamage(damage);
            }
            else
            {
                uint32 damage = GetHitDamage();
                AddPct(damage, 25 * extraHeads);
                SetHitDamage(damage);
            }
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_rampage_venomous_head_megaera_SpellScript::CalculateDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_rampage_venomous_head_megaera_SpellScript();
    }
};

// Rampage - Arcane Head 139552 (damage) - Heroic only!
class spell_rampage_arcane_head_megaera : public SpellScriptLoader
{
public:
    spell_rampage_arcane_head_megaera() : SpellScriptLoader("spell_rampage_arcane_head_megaera") { }

    class spell_rampage_arcane_head_megaera_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_rampage_arcane_head_megaera_SpellScript);

        void CalculateDamage(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (!caster->ToCreature())
                return;

            if (caster->ToCreature()->GetEntry() != NPC_ARCANE_HEAD)
                return;

            Creature* Megaera = caster->FindNearestCreature(BOSS_MEGAERA, 200.0f, true);
            if (!Megaera)
                return;

            int32 extraHeads = CAST_AI(boss_megaera::boss_megaeraAI, Megaera->AI())->GetExtraHeadsCount(NPC_ARCANE_HEAD);
            //SetHitDamage(int32(GetHitDamage() + ((GetHitDamage() / caster->GetMap()->IsHeroic() ? 35.0f : 25.0f ) * extraHeads))); // Increases by 25% for each extra head.
            if (Megaera->GetMap()->IsHeroic()) // check if boss is on heroic map, if yes the % should be 35% else 25% on normal
            {
                uint32 damage = GetHitDamage();
                AddPct(damage, 35 * extraHeads);
                SetHitDamage(damage);
            }
            else
            {
                uint32 damage = GetHitDamage();
                AddPct(damage, 25 * extraHeads);
                SetHitDamage(damage);
            }
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_rampage_arcane_head_megaera_SpellScript::CalculateDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_rampage_arcane_head_megaera_SpellScript();
    }
};

// Cinders - 139822.
class spell_cinders_megaera : public SpellScriptLoader
{
public:
    spell_cinders_megaera() : SpellScriptLoader("spell_cinders_megaera") { }

    class spell_impl : public SpellScript
    {
        PrepareSpellScript(spell_impl);

        void SelectTargets(std::list<WorldObject*>& targets)
        {
            targets.remove_if([this](WorldObject* target) -> bool
                {
                    return target->ToPlayer() && !target->ToPlayer()->HasAura(SPELL_TORRENT_OF_ICE_TARGET);
                });
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_impl::SelectTargets, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_impl::SelectTargets, EFFECT_1, SPELL_EFFECT_APPLY_AURA);
        }
    };

    class spell_cinders_megaera_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_cinders_megaera_AuraScript);

        void OnTick(AuraEffect const* aurEff)
        {
            Unit* caster = GetCaster();
            Unit* target = GetTarget()->ToPlayer();

            if (!caster || !target)
                return;
            if (Creature* icy = target->FindNearestCreature(NPC_ICY_GROUND, 5.0f, true))
                icy->DespawnOrUnsummon();
            // NPC is spawned every 3 seconds (so 3 ticks, 1 ticks / sec) on Heroic diff.
            if (!caster->GetMap()->IsHeroic())
                return;

            if (aurEff->GetTickNumber() % 3 == 0)
                target->CastSpell(target, SPELL_CINDERS_SUMMON, true);
        }

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetTarget()->ToPlayer();

            if (!caster || !target)
                return;

            // NPC is spawned on aura removal on Normal diff.
            if (caster->GetMap()->IsHeroic())
                return;

            target->CastSpell(target, SPELL_CINDERS_SUMMON, true);
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_cinders_megaera_AuraScript::OnTick, EFFECT_1, SPELL_AURA_PERIODIC_DAMAGE);
            OnEffectRemove += AuraEffectRemoveFn(spell_cinders_megaera_AuraScript::OnRemove, EFFECT_1, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_impl();
    }

    AuraScript* GetAuraScript() const
    {
        return new spell_cinders_megaera_AuraScript();
    }
};

// Arctic Freeze (stack checker) - 139843.
class spell_arctic_freeze_megaera : public SpellScriptLoader
{
public:
    spell_arctic_freeze_megaera() : SpellScriptLoader("spell_arctic_freeze_megaera") { }

    class spell_arctic_freeze_megaera_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_arctic_freeze_megaera_AuraScript);

            void OnPeriodic(AuraEffect const* aurEff)
        {
            Unit* caster = GetCaster();
            Unit* target = GetTarget();

            if (!caster || !target)
                return;

            // Check aura stacks for stun apply.
            if (Aura* arcticFreeze = target->GetAura(SPELL_ARCTIC_FREEZE_DUMMY))
            {
                int32 stacks = arcticFreeze->GetStackAmount();

                // Stack handling.
                if (stacks >= 5 && !target->HasAura(SPELL_ARCTIC_FREEZE_STUN))
                {
                    target->RemoveAurasDueToSpell(SPELL_ARCTIC_FREEZE_DUMMY);
                    caster->AddAura(SPELL_ARCTIC_FREEZE_STUN, target);
                }
            }
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_arctic_freeze_megaera_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_arctic_freeze_megaera_AuraScript();
    }
};

// Acid Glob (Acid Rain dummy) - 134343.
class spell_acid_glob_megaera : public SpellScriptLoader
{
public:
    spell_acid_glob_megaera() : SpellScriptLoader("spell_acid_glob_megaera") { }

    class spell_acid_glob_megaera_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_acid_glob_megaera_SpellScript);

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();

            if (!caster)
                return;

            if (!caster->ToCreature())
                return;
            /*
            // The aura is 3 seconds long, and this is triggered each sec. So if not heroic, we should remove the main aura after this first cast.
            if (Unit* target = caster->ToCreature()->AI()->SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                caster->CastSpell(target, SPELL_ACID_GLOB_MISSILE, true);
            if (!caster->GetMap()->IsHeroic())
                caster->RemoveAurasDueToSpell(SPELL_ACID_RAIN);*/
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_acid_glob_megaera_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_acid_glob_megaera_SpellScript();
    }
};

class spell_icy_ground_dummy : public SpellScriptLoader
{
public:
    spell_icy_ground_dummy() : SpellScriptLoader("spell_icy_ground_dummy") {}

    class spell_impl : public SpellScript
    {
        PrepareSpellScript(spell_impl);

        void HandleEffectHitTarget(SpellEffIndex /*eff_idx*/)
        {
            if (Creature* pCreature = GetHitCreature())
                pCreature->DespawnOrUnsummon(500);
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_impl::HandleEffectHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_impl();
    }
};

class spell_megaera_submerged : public SpellScriptLoader
{
public:
    spell_megaera_submerged() : SpellScriptLoader("spell_megaera_submerged") {}

    class aura_impl : public AuraScript
    {
        PrepareAuraScript(aura_impl);

        void HandleOnApply(AuraEffect const* /*aureff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* target = GetOwner()->ToUnit())
                target->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
        }

        void HandleOnRemove(AuraEffect const* /*aureff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* target = GetOwner()->ToUnit())
                if (!target->HasAura(SPELL_CONCEALING_FOG) && !target->HasAura(137064))
                    target->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
        }

        void Register()
        {
            OnEffectApply += AuraEffectApplyFn(aura_impl::HandleOnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(aura_impl::HandleOnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new aura_impl();
    }
};


// 139845
class spell_acid_rain_summon : public SpellScriptLoader
{
public:
    spell_acid_rain_summon() : SpellScriptLoader("spell_acid_rain_summon") {}

    class spell_impl : public SpellScript
    {
        PrepareSpellScript(spell_impl);

        void SelectTargets(std::list<WorldObject*>& targets)
        {
            targets.remove_if(notPlayerPredicate());

            Trinity::Containers::RandomResize(targets, GetCaster()->GetMap()->IsHeroic() ? 3 : 1);

            /*if (Unit* pCaster = GetCaster())
            {
                /*uint32 max_targets = pCaster->GetMap()->IsHeroic() ? 3 : 1;

                if (targets.size() > max_targets)
                    Trinity::Containers::RandomResizeList(targets, max_targets);
                sWorld->SendWorldText(3, "asd");
            }*/
        }

        void HandleEffectHitTarget(SpellEffIndex /*eff_idx*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();

            if (!caster || !target)
                return;

            if (Creature* pRain = caster->SummonCreature(NPC_ACID_RAIN, *target, TEMPSUMMON_TIMED_DESPAWN, 5000))
            {
                caster->AddAura(SPELL_ACID_RAIN_VISUAL, pRain);
                caster->CastSpell(pRain, SPELL_ACID_RAIN_MISSILE, true);
            }
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_impl::SelectTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
            OnEffectHitTarget += SpellEffectFn(spell_impl::HandleEffectHitTarget, EFFECT_0, SPELL_EFFECT_FORCE_CAST);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_impl();
    }
};

class isFriendlyPredicate
{
private:
    Unit* caster;
public:
    isFriendlyPredicate(Unit* _caster) : caster(_caster) {}

    bool operator()(WorldObject* target) const
    {
        return target->ToUnit() && target->ToUnit()->IsFriendlyTo(caster);
    }
};

class spell_acid_rain_missile : public SpellScriptLoader
{
public:
    spell_acid_rain_missile() : SpellScriptLoader("spell_acid_rain_missile") {}

    class spell_impl : public SpellScript
    {
        PrepareSpellScript(spell_impl);

        void HandleEffectHit(SpellEffIndex /*eff_idx*/)
        {
            Position pos;

            GetHitUnit()->GetPosition();

            if (Creature* pTrigger = GetCaster()->SummonCreature(66305, pos, TEMPSUMMON_TIMED_DESPAWN, 2000))
            {
                std::list<Creature*> acidRains;
                GetCreatureListWithEntryInGrid(acidRains, pTrigger, NPC_ACID_RAIN, 2.f);

                for (auto pAcidRain : acidRains)
                {
                    if (pAcidRain->HasAura(SPELL_ACID_RAIN_VISUAL, GetCaster()->GetGUID()))
                    {
                        pAcidRain->CastSpell(pAcidRain, SPELL_ACID_RAIN_DAMAGE, true);
                        pAcidRain->DespawnOrUnsummon(5000);
                        pAcidRain->RemoveAurasDueToSpell(SPELL_ACID_RAIN_VISUAL);
                        break;
                    }
                }
            }
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_impl::HandleEffectHit, EFFECT_0, SPELL_EFFECT_TRIGGER_MISSILE);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_impl();
    }
};

#define SAFE_DISTANCE 30.0f
// 139850
class spell_acid_rain_damage : public SpellScriptLoader
{
public:
    spell_acid_rain_damage() : SpellScriptLoader("spell_acid_rain_damage") {}

    class spell_impl : public SpellScript
    {
        PrepareSpellScript(spell_impl);

        void SelectTargets(std::list<WorldObject*>& targets)
        {
            if (Unit* caster = GetCaster())
            {
                targets.remove_if(isFriendlyPredicate(GetCaster()));

                std::list<Creature*> acidRains;
                GetCreatureListWithEntryInGrid(acidRains, caster, NPC_ACID_RAIN, 220.f);

                for (auto pCreature : acidRains)
                {
                    if (Aura* pAura = pCreature->GetAura(SPELL_ACID_RAIN_VISUAL, caster->GetGUID()))
                        targets.push_back((WorldObject*)pCreature);
                }
            }
        }

        void HandleEffectHitTarget(SpellEffIndex /*eff_idx*/)
        {
            if (Unit* caster = GetCaster())
            {
                if (Unit* target = GetHitUnit())
                {
                    float distance = caster->GetExactDist2d(target);
                    uint32 mindmg = 0, maxdmg = 0;

                    switch (caster->GetMap()->GetDifficultyID())
                    {
                    case DIFFICULTY_10_N:
                        mindmg = 300000;
                        maxdmg = 400000;
                        break;
                    case DIFFICULTY_25_N:
                        mindmg = 300000;
                        maxdmg = 400000;
                        break;
                    case DIFFICULTY_10_HC:
                        mindmg = 400000;
                        maxdmg = 500000;
                        break;
                    case DIFFICULTY_25_HC:
                        mindmg = 400000;
                        maxdmg = 500000;
                        break;
                    }

                    if (distance > SAFE_DISTANCE)
                        distance = SAFE_DISTANCE;

                    SetHitDamage(((mindmg / -SAFE_DISTANCE) * distance) + maxdmg);
                }
            }
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_impl::SelectTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
            OnEffectHitTarget += SpellEffectFn(spell_impl::HandleEffectHitTarget, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_impl();
    }
};

// Flaming Rampage - 139433
class bfa_spell_flaming_rampage : public SpellScriptLoader
{
public:
    bfa_spell_flaming_rampage() : SpellScriptLoader("bfa_spell_flaming_rampage") { }

    class bfa_spell_flaming_rampage_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_flaming_rampage_SpellScript)

            void OnHit()
        {
            if (Unit* caster = GetCaster())
            {
                if (!caster)
                    return;

                if (Unit* target = caster->GetVictim())
                {
                    if (!target)
                        return;
                    caster->CastSpell(target, SPELL_RAMPAGE_FIRE);
                }
            }
        }

        void Register()
        {
            AfterHit += SpellHitFn(bfa_spell_flaming_rampage_SpellScript::OnHit);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_flaming_rampage_SpellScript();
    }
};

// Arcane Rampage - 139513
class bfa_spell_arcane_rampage : public SpellScriptLoader
{
public:
    bfa_spell_arcane_rampage() : SpellScriptLoader("bfa_spell_arcane_rampage") { }

    class bfa_spell_arcane_rampage_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_arcane_rampage_SpellScript)

            void OnHit()
        {
            if (Unit* caster = GetCaster())
            {
                if (!caster)
                    return;

                if (Unit* target = caster->GetVictim())
                {
                    if (!target)
                        return;
                    caster->CastSpell(target, SPELL_RAMPAGE_ARCANE);
                }
            }
        }

        void Register()
        {
            AfterHit += SpellHitFn(bfa_spell_arcane_rampage_SpellScript::OnHit);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_arcane_rampage_SpellScript();
    }
};

// Frozen Rampage - 139440
class bfa_spell_frozen_rampage : public SpellScriptLoader
{
public:
    bfa_spell_frozen_rampage() : SpellScriptLoader("bfa_spell_frozen_rampage") { }

    class bfa_spell_frozen_rampage_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_frozen_rampage_SpellScript)

            void OnHit()
        {
            if (Unit* caster = GetCaster())
            {
                if (!caster)
                    return;

                if (Unit* target = caster->GetVictim())
                {
                    if (!target)
                        return;
                    caster->CastSpell(target, SPELL_RAMPAGE_FROST);
                }
            }
        }

        void Register()
        {
            AfterHit += SpellHitFn(bfa_spell_frozen_rampage_SpellScript::OnHit);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_frozen_rampage_SpellScript();
    }
};

// Venomous Rampage - 139504
class bfa_spell_venomous_rampage : public SpellScriptLoader
{
public:
    bfa_spell_venomous_rampage() : SpellScriptLoader("bfa_spell_venomous_rampage") { }

    class bfa_spell_venomous_rampage_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_venomous_rampage_SpellScript)

            void OnHit()
        {
            if (Unit* caster = GetCaster())
            {
                if (!caster)
                    return;

                if (Unit* target = caster->GetVictim())
                {
                    if (!target)
                        return;

                    caster->CastSpell(target, SPELL_RAMPAGE_POISON);
                }
            }
        }
        void Register()
        {
            AfterHit += SpellHitFn(bfa_spell_venomous_rampage_SpellScript::OnHit);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_venomous_rampage_SpellScript();
    }
};

class bfa_npc_nether_tear : public CreatureScript
{
public:
    bfa_npc_nether_tear() : CreatureScript("bfa_npc_nether_tear") {}

    struct ai_impl : public ScriptedAI
    {
        ai_impl(Creature* pCreature) : ScriptedAI(pCreature)
        {
        }

        EventMap events;

        void IsSummonedBy(Unit*)
        {
            switch (me->GetMap()->GetDifficultyID())
            {
            case DIFFICULTY_10_HC:
            case DIFFICULTY_10_N:
                events.ScheduleEvent(EVENT_SUMMON_WRYMS, 3000, 0, 0);
                break;
            case DIFFICULTY_25_HC:
            case DIFFICULTY_25_N:
                events.ScheduleEvent(EVENT_SUMMON_WRYMS25, 1000, 0, 0);
                break;
            }
            me->DespawnOrUnsummon(7000);
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_SUMMON_WRYMS:
                    me->SummonCreature(NPC_NETHER_WYRM, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_DEAD_DESPAWN);
                    events.ScheduleEvent(EVENT_SUMMON_WRYMS, 3000, 0, 0);
                    break;
                case EVENT_SUMMON_WRYMS25:
                    me->SummonCreature(NPC_NETHER_WYRM, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_DEAD_DESPAWN);
                    events.ScheduleEvent(EVENT_SUMMON_WRYMS25, 1000, 0, 0);
                    break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new ai_impl(pCreature);
    }
};

void AddSC_boss_megaera()
{
    new boss_megaera();
    new npc_flaming_head_megaera();
    new npc_frozen_head_megaera();
    new npc_venomous_head_megaera();
    new npc_arcane_head_megaera();
    new npc_cinders_megaera();
    new npc_icy_ground_megaera();
    new npc_torrent_of_ice();
    new npc_nether_wyrm_megaera();
    new spell_concealing_fog_megaera();
    new spell_rampage_flaming_head_megaera();
    new spell_rampage_frozen_head_megaera();
    new spell_rampage_venomous_head_megaera();
    new spell_rampage_arcane_head_megaera();
    new spell_cinders_megaera();
    new spell_arctic_freeze_megaera();
    new spell_acid_glob_megaera();
    new spell_icy_ground_dummy();
    new spell_megaera_submerged();
    new spell_acid_rain_summon();
    new spell_acid_rain_missile();
    new spell_acid_rain_damage();

    new bfa_npc_nether_tear;

    new bfa_spell_arcane_rampage;
    new bfa_spell_flaming_rampage;
    new bfa_spell_frozen_rampage;
    new bfa_spell_venomous_rampage;
}
