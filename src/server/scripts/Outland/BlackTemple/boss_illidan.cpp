/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

/* ScriptData
SDName: boss_illidan_stormrage
SD%Complete: 90
SDComment: Somewhat of a workaround for Parasitic Shadowfiend, unable to summon GOs for Cage Trap.
SDCategory: Black Temple
EndScriptData */

#include "ScriptPCH.h"
#include "black_temple.h"

#define GETGO(obj, guid)      GameObject* obj = pInstance->instance->GetGameObject(guid)
#define GETUNIT(unit, guid)   Unit* unit = Unit::GetUnit(*me, guid)
#define GETCRE(cre, guid)     Creature* cre = Unit::GetCreature(*me, guid)

/************* Quotes and Sounds ***********************/
// Gossip for when a player clicks Akama
#define GOSSIP_ITEM           "We are ready to face Illidan"

// Yells for/by Akama
#define SAY_AKAMA_BEWARE      "Be wary friends, The Betrayer meditates in the court just beyond."
#define SOUND_AKAMA_BEWARE    11388
#define SAY_AKAMA_MINION      "Come, my minions. Deal with this traitor as he deserves!"
#define SOUND_AKAMA_MINION    11465
#define SAY_AKAMA_LEAVE       "I'll deal with these mongrels. Strike now, friends! Strike at the betrayer!"
#define SOUND_AKAMA_LEAVE     11390

// Self explanatory
const char*  SAY_KILL1        = "Who shall be next to taste my blades?!";
#define SOUND_KILL1           11473
const char*  SAY_KILL2        = "This is too easy!";
#define SOUND_KILL2           11472

// I think I'll fly now and let my subordinates take you on
#define SAY_TAKEOFF           "I will not be touched by rabble such as you!"
#define SOUND_TAKEOFF         11479
#define SAY_SUMMONFLAMES      "Behold the flames of Azzinoth!"
#define SOUND_SUMMONFLAMES    11480

// When casting Eye Blast. Demon Fire will be appear on places that he casts this
#define SAY_EYE_BLAST         "Stare into the eyes of the Betrayer!"
#define SOUND_EYE_BLAST       11481

// kk, I go big, dark and demon on you.
#define SAY_MORPH             "Behold the power... of the demon within!"
#define SOUND_MORPH           11475

// I KILL!
#define SAY_ENRAGE            "You've wasted too much time mortals, now you shall fall!"
#define SOUND_ENRAGE          11474

/************** Spells *************/
// Normal Form
#define SPELL_SHEAR                     37335 // 41032 is bugged, cannot be block/dodge/parry// Reduces Max. Health by 60% for 7 seconds. Can stack 19 times. 1.5f second cast
#define SPELL_FLAME_CRASH               40832 // Summons an invis/unselect passive mob that has an aura of flame in a circle around him.
#define SPELL_DRAW_SOUL                 40904 // 5k Shadow Damage in front of him. Heals Illidan for 100k health (script effect)
#define SPELL_PARASITIC_SHADOWFIEND     41917 // DoT of 3k Shadow every 2 seconds. Lasts 10 seconds. (Script effect: Summon 2 parasites once the debuff has ticked off)
#define SPELL_PARASITIC_SHADOWFIEND2    41914 // Used by Parasitic
#define SPELL_SUMMON_PARASITICS         41915 // Summons 2 Parasitic Shadowfiends on the target. It's supposed to be cast as soon as the Parasitic Shadowfiend debuff is gone, but the spells aren't linked :(
#define SPELL_AGONIZING_FLAMES          40932 // 4k fire damage initial to target and anyone w/i 5 yards. PHASE 3 ONLY
#define SPELL_ENRAGE                    40683 // Increases damage by 50% and attack speed by 30%. 20 seconds, PHASE 5 ONLY
// Flying (Phase 2)
#define SPELL_THROW_GLAIVE              39635 // Throws a glaive on the ground
#define SPELL_THROW_GLAIVE2             39849 // Animation for the above spell
#define SPELL_GLAIVE_RETURNS            39873 // Glaive flies back to Illidan
#define SPELL_FIREBALL                  40598 // 2.5fk-3.5fk damage in 10 yard radius. 2 second cast time.
#define SPELL_DARK_BARRAGE              40585 // 10 second channeled spell, 3k shadow damage per second.
// Demon Form
#define SPELL_DEMON_TRANSFORM_1         40511 // First phase of animations for transforming into Dark Illidan (fall to ground)
#define SPELL_DEMON_TRANSFORM_2         40398 // Second phase of animations (kneel)
#define SPELL_DEMON_TRANSFORM_3         40510 // Final phase of animations (stand up and roar)
#define SPELL_DEMON_FORM                40506 // Transforms into Demon Illidan. Has an Aura of Dread on him.
#define SPELL_SHADOW_BLAST              41078 // 8k - 11k Shadow Damage. Targets highest threat. Has a splash effect, damaging anyone in 20 yards of the target.
#define SPELL_FLAME_BURST               41126 // Hurls fire at entire raid for ~3.5fk damage every 10 seconds. Resistable. (Does not work: Script effect)
#define SPELL_FLAME_BURST_EFFECT        41131 // The actual damage. Have each player cast it on itself (workaround)
// Other Illidan spells
#define SPELL_KNEEL                     39656 // Before beginning encounter, this is how he appears (talking to skully).
#define SPELL_SHADOW_PRISON             40647 // Illidan casts this spell to immobilize entire raid when he summons Maiev.
#define SPELL_DEATH                     41220 // This spell doesn't do anything except stun Illidan and set him on his knees.
#define SPELL_BERSERK                   45078 // Damage increased by 500%, attack speed by 150%
#define SPELL_DUAL_WIELD                42459
//Phase Normal spells
#define SPELL_FLAME_CRASH_EFFECT        40836 // Firey blue ring of circle that the other flame crash summons
#define SPELL_SUMMON_SHADOWDEMON        41117 // Summon four shadowfiends
#define SPELL_SHADOWFIEND_PASSIVE       41913 // Passive aura for shadowfiends
#define SPELL_SHADOW_DEMON_PASSIVE      41079 // Adds the "shadowform" aura to Shadow Demons.
#define SPELL_CONSUME_SOUL              41080 // Once the Shadow Demons reach their target, they use this to kill them
#define SPELL_PARALYZE                  41083 // Shadow Demons cast this on their target
#define SPELL_PURPLE_BEAM               39123 // Purple Beam connecting Shadow Demon to their target
//Phase Flight spells
#define SPELL_AZZINOTH_CHANNEL          39857 // Glaives cast it on Flames. Not sure if this is the right spell.
#define SPELL_EYE_BLAST_TRIGGER         40017 // This summons Demon Form every few seconds and deals ~20k damage in its radius
#define SPELL_EYE_BLAST                 39908 // This does the blue flamey animation.
#define SPELL_BLAZE_EFFECT              40610 // Green flame on the ground, triggers damage (5k) every few seconds
#define SPELL_BLAZE_SUMMON              40637 // Summons the Blaze creature
#define SPELL_DEMON_FIRE                40029 // Blue fire trail left by Eye Blast. Deals 2k per second if players stand on it.
#define SPELL_FLAME_BLAST               40631 // Flames of Azzinoth use this. Frontal cone AoE 7k-9k damage.
#define SPELL_CHARGE                    41581 //40602 // Flames of Azzinoth charges whoever is too far from them. They enrage after this. For simplicity, we'll use the same enrage as Illidan.
#define SPELL_FLAME_ENRAGE              45078
//Akama spells
#define SPELL_AKAMA_DOOR_CHANNEL        41268 // Akama's channel spell on the door before the Temple Summit
#define SPELL_DEATHSWORN_DOOR_CHANNEL   41269 // Olum and Udalo's channel spell on the door before the Temple Summit
#define SPELL_AKAMA_DOOR_FAIL           41271 // Not sure where this is really used...
#define SPELL_HEALING_POTION            40535 // Akama uses this to heal himself to full.
#define SPELL_CHAIN_LIGHTNING           40536 // 6938 to 8062 for 5 targets
//Maiev spells
#define SPELL_CAGE_TRAP_DUMMY           40761 // Put this in DB for cage trap GO.
#define SPELL_CAGED                     40695 // Caged Trap triggers will cast this on Illidan if he is within 3 yards
#define SPELL_CAGE_TRAP_SUMMON          40694 // Summons a Cage Trap GO (bugged) on the ground along with a Cage Trap Disturb Trigger mob (working)
#define SPELL_CAGE_TRAP_BEAM            40713 // 8 Triggers on the ground in an octagon cast spells like this on Illidan 'caging him'
#define SPELL_TELEPORT_VISUAL           41232 // Teleport visual for Maiev
#define SPELL_SHADOW_STRIKE             40685 // 4375 to 5625 every 3 seconds for 12 seconds
#define SPELL_THROW_DAGGER              41152 // 5400 to 6600 damage, need dagger
#define SPELL_FAN_BLADES                39954 // bugged visual

// Other defines
#define CENTER_X            676.740f
#define CENTER_Y            305.297f
#define CENTER_Z            353.192f

#define FLAME_ENRAGE_DISTANCE   30
#define FLAME_CHARGE_DISTANCE   50

#define EQUIP_ID_MAIN_HAND  32837
#define EQUIP_ID_OFF_HAND   32838

/**** Creature Summon and Recognition IDs ****/
enum CreatureEntry
{
    EMPTY                   =       0,
    AKAMA                   =   22990,
    ILLIDAN_STORMRAGE       =   22917,
    BLADE_OF_AZZINOTH       =   22996,
    FLAME_OF_AZZINOTH       =   22997,
    MAIEV_SHADOWSONG        =   23197,
    SHADOW_DEMON            =   23375,
    DEMON_FIRE              =   23069,
    FLAME_CRASH             =   23336,
    ILLIDAN_DOOR_TRIGGER    =   23412,
    SPIRIT_OF_OLUM          =   23411,
    SPIRIT_OF_UDALO         =   23410,
    ILLIDARI_ELITE          =   23226,
    PARASITIC_SHADOWFIEND   =   23498,
    CAGE_TRAP_TRIGGER       =   23292,
};

/*** Phase Names ***/
enum PhaseIllidan
{
    PHASE_ILLIDAN_NULL          =   0,
    PHASE_NORMAL                =   1,
    PHASE_FLIGHT                =   2,
    PHASE_NORMAL_2              =   3,
    PHASE_DEMON                 =   4,
    PHASE_NORMAL_MAIEV          =   5,
    PHASE_TALK_SEQUENCE         =   6,
    PHASE_FLIGHT_SEQUENCE       =   7,
    PHASE_TRANSFORM_SEQUENCE    =   8,
    PHASE_ILLIDAN_MAX           =   9,
};//Maiev uses the same phase

enum PhaseAkama
{
    PHASE_AKAMA_NULL        =   0,
    PHASE_CHANNEL           =   1,
    PHASE_WALK              =   2,
    PHASE_TALK              =   3,
    PHASE_FIGHT_ILLIDAN     =   4,
    PHASE_FIGHT_MINIONS     =   5,
    PHASE_RETURN            =   6,
};

enum EventIllidan
{
    EVENT_NULL                  =   0,
    EVENT_BERSERK               =   1,
    //normal phase
    EVENT_TAUNT                 =   2,
    EVENT_SHEAR                 =   3,
    EVENT_FLAME_CRASH           =   4,
    EVENT_PARASITIC_SHADOWFIEND =   5,
    EVENT_PARASITE_CHECK        =   6,
    EVENT_DRAW_SOUL             =   7,
    EVENT_AGONIZING_FLAMES      =   8,
    EVENT_TRANSFORM_NORMAL      =   9,
    EVENT_ENRAGE                =   10,
    //flight phase
    EVENT_FIREBALL              =   2,
    EVENT_DARK_BARRAGE          =   3,
    EVENT_EYE_BLAST             =   4,
    EVENT_MOVE_POINT            =   5,
    //demon phase
    EVENT_SHADOW_BLAST          =   2,
    EVENT_FLAME_BURST           =   3,
    EVENT_SHADOWDEMON           =   4,
    EVENT_TRANSFORM_DEMON       =   5,
    //sequence phase
    EVENT_TALK_SEQUENCE         =   2,
    EVENT_FLIGHT_SEQUENCE       =   2,
    EVENT_TRANSFORM_SEQUENCE    =   2,
};

enum EventMaiev
{
    EVENT_MAIEV_NULL            =   0,
    EVENT_MAIEV_STEALTH         =   1,
    EVENT_MAIEV_TAUNT           =   2,
    EVENT_MAIEV_SHADOW_STRIKE   =   3,
    EVENT_MAIEV_THROW_DAGGER    =   4,
    EVENT_MAIEV_TRAP            =   4,
};

static const EventIllidan MaxTimer[9] =
{
    EVENT_NULL,
    EVENT_DRAW_SOUL,
    EVENT_MOVE_POINT,
    EVENT_TRANSFORM_NORMAL,
    EVENT_TRANSFORM_DEMON,
    EVENT_ENRAGE,
    EVENT_TALK_SEQUENCE,
    EVENT_FLIGHT_SEQUENCE,
    EVENT_TRANSFORM_SEQUENCE
};

struct Yells
{
    uint32 sound;
    std::string text;
    uint32 pCreature, timer, emote;
    bool Talk;
};

static const Yells Conversation[22] =
{
    {11463, "Akama... your duplicity is hardly surprising. I should have slaughtered you and your malformed brethren long ago.", ILLIDAN_STORMRAGE, 8000, 0, true},
    {0,     "", ILLIDAN_STORMRAGE, 5000, 396, true},
    {11389, "We've come to end your reign, Illidan. My people and all of Outland shall be free!", AKAMA, 7000, 25, true},
    {0,     "", AKAMA, 5000, 66, true},
    {11464, "Boldly said. But I remain unconvinced.", ILLIDAN_STORMRAGE, 8000, 396, true},
    {11380, "The time has come! The moment is at hand!", AKAMA, 3000, 22, true},
    {0,     "", AKAMA, 2000, 15, true},
    {11466, "You are not prepared!", ILLIDAN_STORMRAGE, 3000, 406, true},
    {0,     "", EMPTY, 1000, 0, true},
    {0,     "", EMPTY, 0, 0, false}, //9
    {11476, "Is this it, mortals? Is this all the fury you can muster?", ILLIDAN_STORMRAGE, 8000, 0, true},
    {11491, "Their fury pales before mine, Illidan. We have some unsettled business between us.", MAIEV_SHADOWSONG, 8000, 5, true},
    {11477, "Maiev... How is this even possible?", ILLIDAN_STORMRAGE, 5000, 1, true},
    {11492, "Ah... my long hunt is finally over. Today, Justice will be done!", MAIEV_SHADOWSONG, 8000, 15, true},
    {11470, "Feel the hatred of ten thousand years!", ILLIDAN_STORMRAGE, 1000, 0, false}, //14
    {11496, "Ahh... It is finished. You are beaten.", MAIEV_SHADOWSONG, 6000, 0, true}, //15
    {11478, "You have won... Maiev...but the huntress... is nothing...without the hunt... you... are nothing... without me..", ILLIDAN_STORMRAGE, 30000, 65, true}, // Emote dead for now. Kill him later
    {11497, "He is right. I feel nothing... I am nothing... Farewell, champions.", MAIEV_SHADOWSONG, 9000, 0, true},
    {11498, "", MAIEV_SHADOWSONG, 5000, 0, true},
    {11498, "", EMPTY, 1000, 0, true}, //19 Maiev disappear
    {11387, "The Light will fill these dismal halls once again. I swear it.", AKAMA, 8000, 0, true},
    {0,     "", EMPTY, 1000, 0, false}//21
};

static const Yells RandomTaunts[4]=
{
    {11467, "I can feel your hatred.", ILLIDAN_STORMRAGE, 0, 0, false},
    {11468, "Give in to your fear!", ILLIDAN_STORMRAGE, 0, 0, false},
    {11469, "You know nothing of power!", ILLIDAN_STORMRAGE, 0, 0, false},
    {11471, "Such... arrogance!", ILLIDAN_STORMRAGE, 0, 0, false}
};

static const Yells MaievTaunts[4]=
{
    {11493, "That is for Naisha!", MAIEV_SHADOWSONG, 0, 0, false},
    {11494, "Bleed as I have bled!", MAIEV_SHADOWSONG, 0, 0, false},
    {11495, "There shall be no prison for you this time!", MAIEV_SHADOWSONG, 0, 0, false},
    {11500, "Meet your end, demon!", MAIEV_SHADOWSONG, 0, 0, false}
};

struct Locations
{
    float x, y, z;
};

static const Locations HoverPosition[4]=
{
    {657.0f, 340.0f, 355.0f},
    {657.0f, 275.0f, 355.0f},
    {705.0f, 275.0f, 355.0f},
    {705.0f, 340.0f, 355.0f}
};

static const Locations GlaivePosition[4]=
{
    {695.105f, 305.303f, 354.256f},
    {659.338f, 305.303f, 354.256f}, //the distance between two glaives is 36
    {700.105f, 305.303f, 354.256f},
    {664.338f, 305.303f, 354.256f}
};

static const Locations EyeBlast[2]=
{
    {677.0f, 350.0f, 354.0f}, //start point, pass through glaive point
    {677.0f, 260.0f, 354.0f}
};

static const Locations AkamaWP[13]=
{
    {770.01f, 304.50f, 312.29f}, // Bottom of the first stairs, at the doors
    {780.66f, 304.50f, 319.74f}, // Top of the first stairs
    {790.13f, 319.68f, 319.76f}, // Bottom of the second stairs (left from the entrance)
    {787.17f, 347.38f, 341.42f}, // Top of the second stairs
    {781.34f, 350.31f, 341.44f}, // Bottom of the third stairs
    {762.60f, 361.06f, 353.60f}, // Top of the third stairs
    {756.35f, 360.52f, 353.27f}, // Before the door-thingy
    {743.82f, 342.21f, 353.00f}, // Somewhere further
    {732.69f, 305.13f, 353.00f}, // In front of Illidan - (8)
    {738.11f, 365.44f, 353.00f}, // in front of the door-thingy (the other one!)
    {792.18f, 366.62f, 341.42f}, // Down the first flight of stairs
    {796.84f, 304.89f, 319.76f}, // Down the second flight of stairs
    {782.01f, 304.55f, 319.76f}  // Final location - back at the initial gates. This is where he will fight the minions! (12)
};
// 755.762f, 304.0747f, 312.1769f -- This is where Akama should be spawned
static const Locations SpiritSpawns[2]=
{
    {755.5426f, 309.9156f, 312.2129f},
    {755.5426f, 298.7923f, 312.0834f}
};

struct Animation // For the demon transformation
{
    uint32 aura, unaura, timer, size, displayid, phase;
    bool equip;
};

static const Animation DemonTransformation[10]=
{
    {SPELL_DEMON_TRANSFORM_1, 0, 1000, 0, 0, 6, true},
    {SPELL_DEMON_TRANSFORM_2, SPELL_DEMON_TRANSFORM_1, 4000, 0, 0, 6, true},
    {0, 0, 3000, 1073741824, 21322, 6, false}, //stunned, cannot cast demon form
    {SPELL_DEMON_TRANSFORM_3, SPELL_DEMON_TRANSFORM_2, 3500, 0, 0, 6, false},
    {SPELL_DEMON_FORM, SPELL_DEMON_TRANSFORM_3, 0, 0, 0, 4, false},
    {SPELL_DEMON_TRANSFORM_1, 0, 1000, 0, 0, 6, false},
    {SPELL_DEMON_TRANSFORM_2, SPELL_DEMON_TRANSFORM_1, 4000, 0, 0, 6, false},
    {0, SPELL_DEMON_FORM, 3000, 1069547520, 21135, 6, false},
    {SPELL_DEMON_TRANSFORM_3, SPELL_DEMON_TRANSFORM_2, 3500, 0, 0, 6, true},
    {0, SPELL_DEMON_TRANSFORM_3, 0, 0, 0, 8, true}
};

#define EMOTE_SETS_GAZE_ON     "sets its gaze on $N!"
#define EMOTE_UNABLE_TO_SUMMON "is unable to summon Maiev Shadowsong and enter Phase 4. Resetting Encounter."

class mob_flame_of_azzinoth : public CreatureScript
{
public:
    mob_flame_of_azzinoth() : CreatureScript("mob_flame_of_azzinoth") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new flame_of_azzinothAI (pCreature);
    }

    struct flame_of_azzinothAI : public ScriptedAI
    {
        flame_of_azzinothAI(Creature *c) : ScriptedAI(c) {}

        uint32 FlameBlastTimer;
        uint32 CheckTimer;
        uint64 GlaiveGUID;

        void Reset()
        {
            FlameBlastTimer = 15000;
            CheckTimer = 5000;
            GlaiveGUID = 0;
        }

        void EnterCombat(Unit * /*who*/) {DoZoneInCombat();}

        void ChargeCheck()
        {
            Unit *pTarget = SelectTarget(SELECT_TARGET_FARTHEST, 0, 200, false);
            if (pTarget && (!me->IsWithinCombatRange(pTarget, FLAME_CHARGE_DISTANCE)))
            {
                me->AddThreat(pTarget, 5000000.0f);
                AttackStart(pTarget);
                DoCast(pTarget, SPELL_CHARGE);
                me->MonsterTextEmote(EMOTE_SETS_GAZE_ON, pTarget->GetGUID());
            }
        }

        void EnrageCheck()
        {
            if (GETUNIT(Glaive, GlaiveGUID))
            {
                if (!me->IsWithinDistInMap(Glaive, FLAME_ENRAGE_DISTANCE))
                {
                    Glaive->InterruptNonMeleeSpells(true);
                    DoCast(me, SPELL_FLAME_ENRAGE, true);
                    DoResetThreat();
                    Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                    if (pTarget && pTarget->isAlive())
                    {
                        me->AddThreat(me->getVictim(), 5000000.0f);
                        AttackStart(me->getVictim());
                    }
                }
                else if (!me->HasAura(SPELL_AZZINOTH_CHANNEL))
                {
                    Glaive->CastSpell(me, SPELL_AZZINOTH_CHANNEL, false);
                    me->RemoveAurasDueToSpell(SPELL_FLAME_ENRAGE);
                }
            }
        }

        void SetGlaiveGUID(uint64 guid){ GlaiveGUID = guid; }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (FlameBlastTimer <= diff)
            {
                DoCast(me->getVictim(), SPELL_BLAZE_SUMMON, true); //appear at victim
                DoCast(me->getVictim(), SPELL_FLAME_BLAST);
                FlameBlastTimer = 15000; //10000 is official-like?
                DoZoneInCombat(); //in case someone is revived
            } else FlameBlastTimer -= diff;

            if (CheckTimer <= diff)
            {
                ChargeCheck();
                EnrageCheck();
                CheckTimer = 1000;
            } else CheckTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

/************************************** Illidan's AI ***************************************/
class boss_illidan_stormrage : public CreatureScript
{
public:
    boss_illidan_stormrage() : CreatureScript("boss_illidan_stormrage") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_illidan_stormrageAI (pCreature);
    }

    struct boss_illidan_stormrageAI : public ScriptedAI
    {
        boss_illidan_stormrageAI(Creature* c) : ScriptedAI(c), Summons(me)
        {
            pInstance = c->GetInstanceScript();
            DoCast(me, SPELL_DUAL_WIELD, true);

            SpellEntry *TempSpell = GET_SPELL(SPELL_SHADOWFIEND_PASSIVE);
            if (TempSpell)
                TempSpell->EffectApplyAuraName[0] = 4; // proc debuff, and summon infinite fiends
        }

        InstanceScript* pInstance;

        PhaseIllidan Phase;
        EventIllidan Event;
        uint32 Timer[EVENT_ENRAGE + 1];

        uint32 TalkCount;
        uint32 TransformCount;
        uint32 FlightCount;

        uint32 HoverPoint;

        uint64 AkamaGUID;
        uint64 MaievGUID;
        uint64 FlameGUID[2];
        uint64 GlaiveGUID[2];

        SummonList Summons;

        void Reset();

        void JustSummoned(Creature* summon);

        void SummonedCreatureDespawn(Creature* summon)
        {
            if (summon->GetCreatureInfo()->Entry == FLAME_OF_AZZINOTH)
            {
                for (uint8 i = 0; i < 2; ++i)
                    if (summon->GetGUID() == FlameGUID[i])
                        FlameGUID[i] = 0;

                if (!FlameGUID[0] && !FlameGUID[1] && Phase != PHASE_ILLIDAN_NULL)
                {
                    me->InterruptNonMeleeSpells(true);
                    EnterPhase(PHASE_FLIGHT_SEQUENCE);
                }
            }
            Summons.Despawn(summon);
        }

        void MovementInform(uint32 /*MovementType*/, uint32 /*Data*/)
        {
            if (FlightCount == 7) //change hover point
            {
                if (me->getVictim())
                {
                    me->SetInFront(me->getVictim());
                    me->StopMoving();
                }
                EnterPhase(PHASE_FLIGHT);
            }
            else // handle flight sequence
                Timer[EVENT_FLIGHT_SEQUENCE] = 1000;
        }

        void EnterCombat(Unit * /*who*/)
        {
            me->setActive(true);
            DoZoneInCombat();
        }

        void AttackStart(Unit *who)
        {
            if (!who || Phase >= PHASE_TALK_SEQUENCE)
                return;

            if (Phase == PHASE_FLIGHT || Phase == PHASE_DEMON)
                AttackStartNoMove(who);
            else
                ScriptedAI::AttackStart(who);
        }

        void MoveInLineOfSight(Unit *) {}

        void JustDied(Unit * /*killer*/)
        {
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

            if (!pInstance)
                return;

            pInstance->SetData(DATA_ILLIDANSTORMRAGEEVENT, DONE); // Completed

            for (uint8 i = DATA_GAMEOBJECT_ILLIDAN_DOOR_R; i < DATA_GAMEOBJECT_ILLIDAN_DOOR_L + 1; ++i)
                pInstance->HandleGameObject(pInstance->GetData64(i), true);
        }

        void KilledUnit(Unit * victim)
        {
            if (victim == me) return;
            // TODO: Find better way to handle emote
            switch (urand(0, 1))
            {
            case 0:
                me->MonsterYell(SAY_KILL1, LANG_UNIVERSAL, victim->GetGUID());
                DoPlaySoundToSet(me, SOUND_KILL1);
                break;
            case 1:
                me->MonsterYell(SAY_KILL2, LANG_UNIVERSAL, victim->GetGUID());
                DoPlaySoundToSet(me, SOUND_KILL2);
                break;
            }
        }

        void DamageTaken(Unit *done_by, uint32 &damage)
        {
            if (damage >= me->GetHealth() && done_by != me)
                damage = 0;
            if (done_by->GetGUID() == MaievGUID)
                done_by->AddThreat(me, -(3*(float)damage)/4); // do not let maiev tank him
        }

        void SpellHit(Unit * /*caster*/, const SpellEntry *spell)
        {
            if (spell->Id == SPELL_GLAIVE_RETURNS) // Re-equip our warblades!
            {
                if (!me->GetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID))
                    SetEquipmentSlots(false, EQUIP_ID_MAIN_HAND, EQUIP_UNEQUIP, EQUIP_NO_CHANGE);
                else
                    SetEquipmentSlots(false, EQUIP_UNEQUIP, EQUIP_ID_OFF_HAND, EQUIP_NO_CHANGE);
                me->SetByteValue(UNIT_FIELD_BYTES_2, 0, SHEATH_STATE_MELEE);
            }
        }

        void DeleteFromThreatList(uint64 TargetGUID)
        {
            for (std::list<HostileReference*>::const_iterator itr = me->getThreatManager().getThreatList().begin(); itr != me->getThreatManager().getThreatList().end(); ++itr)
            {
                if ((*itr)->getUnitGuid() == TargetGUID)
                {
                    (*itr)->removeReference();
                    break;
                }
            }
        }

        void Talk(uint32 count)
        {
            Timer[EVENT_TALK_SEQUENCE] = Conversation[count].timer;

            Creature* pCreature = NULL;
            if (Conversation[count].pCreature == ILLIDAN_STORMRAGE)
                pCreature = me;
            else if (Conversation[count].pCreature == AKAMA)
                pCreature = (Unit::GetCreature((*me), AkamaGUID));
            else if (Conversation[count].pCreature == MAIEV_SHADOWSONG)
                pCreature = (Unit::GetCreature((*me), MaievGUID));

            if (pCreature)
            {
                if (Conversation[count].emote)
                    pCreature->HandleEmoteCommand(Conversation[count].emote); // Make the Creature do some animation!
                if (Conversation[count].text.size())
                    pCreature->MonsterYell(Conversation[count].text.c_str(), LANG_UNIVERSAL, 0); // Have the Creature yell out some text
                if (Conversation[count].sound)
                    DoPlaySoundToSet(pCreature, Conversation[count].sound); // Play some sound on the creature
            }
        }

        void EnterPhase(PhaseIllidan NextPhase)
        {
            DoZoneInCombat();
            switch(NextPhase)
            {
            case PHASE_NORMAL:
            case PHASE_NORMAL_2:
            case PHASE_NORMAL_MAIEV:
                AttackStart(me->getVictim());
                Timer[EVENT_TAUNT] = 32000;
                Timer[EVENT_SHEAR] = 10000 + rand()%15 * 1000;
                Timer[EVENT_FLAME_CRASH] = 20000;
                Timer[EVENT_PARASITIC_SHADOWFIEND] = 25000;
                Timer[EVENT_PARASITE_CHECK] = 0;
                Timer[EVENT_DRAW_SOUL] = 30000;
                if (NextPhase == PHASE_NORMAL)
                    break;
                Timer[EVENT_AGONIZING_FLAMES] = 35000;
                Timer[EVENT_TRANSFORM_NORMAL] = 60000;
                if (NextPhase == PHASE_NORMAL_2)
                    break;
                Timer[EVENT_ENRAGE] = 30000 + rand()%10 * 1000;
                break;
            case PHASE_FLIGHT:
                Timer[EVENT_FIREBALL] = 1000;
                if (!(rand()%4))
                    Timer[EVENT_DARK_BARRAGE] = 10000;
                Timer[EVENT_EYE_BLAST] = 10000 + rand()%15 * 1000;
                Timer[EVENT_MOVE_POINT] = 20000 + rand()%20 * 1000;
                break;
            case PHASE_DEMON:
                Timer[EVENT_SHADOW_BLAST] = 1000;
                Timer[EVENT_FLAME_BURST] = 10000;
                Timer[EVENT_SHADOWDEMON] = 30000;
                Timer[EVENT_TRANSFORM_DEMON] = 60000;
                AttackStart(me->getVictim());
                break;
            case PHASE_TALK_SEQUENCE:
                Timer[EVENT_TALK_SEQUENCE] = 100;
                me->RemoveAllAuras();
                me->InterruptNonMeleeSpells(false);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE + UNIT_FLAG_NOT_SELECTABLE);
                me->GetMotionMaster()->Clear(false);
                me->AttackStop();
                break;
            case PHASE_FLIGHT_SEQUENCE:
                if (Phase == PHASE_NORMAL) //lift off
                {
                    FlightCount = 1;
                    Timer[EVENT_FLIGHT_SEQUENCE] = 1;
                    me->RemoveAllAuras();
                    me->InterruptNonMeleeSpells(false);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    me->GetMotionMaster()->Clear(false);
                    me->AttackStop();
                }
                else //land
                    Timer[EVENT_FLIGHT_SEQUENCE] = 2000;
                break;
            case PHASE_TRANSFORM_SEQUENCE:
                if (Phase == PHASE_DEMON)
                    Timer[EVENT_TRANSFORM_SEQUENCE] = 500;
                else
                {
                    TransformCount = 0;
                    Timer[EVENT_TRANSFORM_SEQUENCE] = 500;
                    me->MonsterYell(SAY_MORPH, LANG_UNIVERSAL, 0);
                    DoPlaySoundToSet(me, SOUND_MORPH);
                }
                me->GetMotionMaster()->Clear();
                me->AttackStop();
                break;
            default:
                break;
            }
            if (MaievGUID)
            {
                GETCRE(Maiev, MaievGUID);
                if (Maiev && Maiev->isAlive())
                    Maiev->AI()->DoAction(NextPhase);
            }
            Phase = NextPhase;
            Event = EVENT_NULL;
        }
        void CastEyeBlast()
        {
            me->InterruptNonMeleeSpells(false);

            me->MonsterYell(SAY_EYE_BLAST, LANG_UNIVERSAL, 0);
            DoPlaySoundToSet(me, SOUND_EYE_BLAST);

            float distx, disty, dist[2];
            for (uint8 i = 0; i < 2; ++i)
            {
                distx = EyeBlast[i].x - HoverPosition[HoverPoint].x;
                disty = EyeBlast[i].y - HoverPosition[HoverPoint].y;
                dist[i] = distx * distx + disty * disty;
            }
            Locations initial = EyeBlast[dist[0] < dist[1] ? 0 : 1];
            for (uint8 i = 0; i < 2; ++i)
            {
                distx = GlaivePosition[i].x - HoverPosition[HoverPoint].x;
                disty = GlaivePosition[i].y - HoverPosition[HoverPoint].y;
                dist[i] = distx * distx + disty * disty;
            }
            Locations final = GlaivePosition[dist[0] < dist[1] ? 0 : 1];

            final.x = 2 * final.x - initial.x;
            final.y = 2 * final.y - initial.y;

            Creature* Trigger = me->SummonCreature(23069, initial.x, initial.y, initial.z, 0, TEMPSUMMON_TIMED_DESPAWN, 13000);
            if (!Trigger) return;

            Trigger->SetSpeed(MOVE_WALK, 3);
            Trigger->AddUnitMovementFlag(MOVEMENTFLAG_WALKING);
            Trigger->GetMotionMaster()->MovePoint(0, final.x, final.y, final.z);

            //Trigger->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->SetUInt64Value(UNIT_FIELD_TARGET, Trigger->GetGUID());
            DoCast(Trigger, SPELL_EYE_BLAST);
        }
        void SummonFlamesOfAzzinoth()
        {
            me->MonsterYell(SAY_SUMMONFLAMES, LANG_UNIVERSAL, 0);
            DoPlaySoundToSet(me, SOUND_SUMMONFLAMES);

            for (uint8 i = 0; i < 2; ++i)
            {
                if (GETUNIT(Glaive, GlaiveGUID[i]))
                {
                    Creature* Flame = me->SummonCreature(FLAME_OF_AZZINOTH, GlaivePosition[i+2].x, GlaivePosition[i+2].y, GlaivePosition[i+2].z, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                    if (Flame)
                    {
                        Flame->setFaction(me->getFaction()); // Just in case the database has it as a different faction
                        Flame->SetMeleeDamageSchool(SPELL_SCHOOL_FIRE);
                        FlameGUID[i] = Flame->GetGUID(); // Record GUID in order to check if they're dead later on to move to the next phase
                        CAST_AI(mob_flame_of_azzinoth::flame_of_azzinothAI, Flame->AI())->SetGlaiveGUID(GlaiveGUID[i]);
                        Glaive->CastSpell(Flame, SPELL_AZZINOTH_CHANNEL, false); // Glaives do some random Beam type channel on it.
                    }
                }
            }
        }
        void SummonMaiev()
        {
            DoCast(me, SPELL_SHADOW_PRISON, true);
            DoCast(me, 40403, true);
            if (!MaievGUID) // If Maiev cannot be summoned, reset the encounter and post some errors to the console.
            {
                EnterEvadeMode();
                me->MonsterTextEmote(EMOTE_UNABLE_TO_SUMMON, 0);
                sLog->outError("SD2 ERROR: Unable to summon Maiev Shadowsong (entry: 23197). Check your database to see if you have the proper SQL for Maiev Shadowsong (entry: 23197)");
            }
        }

        void HandleTalkSequence();

        void HandleFlightSequence()
        {
            switch(FlightCount)
            {
            case 1://lift off
                me->HandleEmoteCommand(EMOTE_ONESHOT_LIFTOFF);
                me->SetUnitMovementFlags(MOVEMENTFLAG_LEVITATING);
                me->StopMoving();
                me->MonsterYell(SAY_TAKEOFF, LANG_UNIVERSAL, 0);
                DoPlaySoundToSet(me, SOUND_TAKEOFF);
                Timer[EVENT_FLIGHT_SEQUENCE] = 3000;
                break;
            case 2://move to center
                me->GetMotionMaster()->MovePoint(0, CENTER_X + 5, CENTER_Y, CENTER_Z); //+5, for SPELL_THROW_GLAIVE bug
                Timer[EVENT_FLIGHT_SEQUENCE] = 0;
                break;
            case 3://throw one glaive
                {
                    uint8 i=1;
                    Creature* Glaive = me->SummonCreature(BLADE_OF_AZZINOTH, GlaivePosition[i].x, GlaivePosition[i].y, GlaivePosition[i].z, 0, TEMPSUMMON_CORPSE_DESPAWN, 0);
                    if (Glaive)
                    {
                        GlaiveGUID[i] = Glaive->GetGUID();
                        Glaive->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        Glaive->SetDisplayId(11686);
                        Glaive->setFaction(me->getFaction());
                        DoCast(Glaive, SPELL_THROW_GLAIVE2);
                    }
                }
                Timer[EVENT_FLIGHT_SEQUENCE] = 700;
                break;
            case 4://throw another
                SetEquipmentSlots(false, EQUIP_UNEQUIP, EQUIP_UNEQUIP, EQUIP_NO_CHANGE);
                {
                    uint8 i=0;
                    Creature* Glaive = me->SummonCreature(BLADE_OF_AZZINOTH, GlaivePosition[i].x, GlaivePosition[i].y, GlaivePosition[i].z, 0, TEMPSUMMON_CORPSE_DESPAWN, 0);
                    if (Glaive)
                    {
                        GlaiveGUID[i] = Glaive->GetGUID();
                        Glaive->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        Glaive->SetDisplayId(11686);
                        Glaive->setFaction(me->getFaction());
                        DoCast(Glaive, SPELL_THROW_GLAIVE, true);
                    }
                }
                Timer[EVENT_FLIGHT_SEQUENCE] = 5000;
                break;
            case 5://summon flames
                SummonFlamesOfAzzinoth();
                Timer[EVENT_FLIGHT_SEQUENCE] = 3000;
                break;
            case 6://fly to hover point
                me->GetMotionMaster()->MovePoint(0, HoverPosition[HoverPoint].x, HoverPosition[HoverPoint].y, HoverPosition[HoverPoint].z);
                Timer[EVENT_FLIGHT_SEQUENCE] = 0;
                break;
            case 7://return to center
                me->GetMotionMaster()->MovePoint(0, CENTER_X, CENTER_Y, CENTER_Z);
                Timer[EVENT_FLIGHT_SEQUENCE] = 0;
                break;
            case 8://glaive return
                for (uint8 i = 0; i < 2; ++i)
                {
                    if (GlaiveGUID[i])
                    {
                        Unit* Glaive = Unit::GetUnit((*me), GlaiveGUID[i]);
                        if (Glaive)
                        {
                            Glaive->CastSpell(me, SPELL_GLAIVE_RETURNS, false); // Make it look like the Glaive flies back up to us
                            Glaive->SetDisplayId(11686); // disappear but not die for now
                        }
                    }
                }
                Timer[EVENT_FLIGHT_SEQUENCE] = 2000;
                break;
            case 9://land
                me->RemoveUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                me->StopMoving();
                me->HandleEmoteCommand(EMOTE_ONESHOT_LAND);
                for (uint8 i = 0; i < 2; ++i)
                {
                    if (GlaiveGUID[i])
                    {
                        if (GETUNIT(Glaive, GlaiveGUID[i]))
                        {
                            Glaive->SetVisible(false);
                            Glaive->setDeathState(JUST_DIED); // Despawn the Glaive
                        }
                        GlaiveGUID[i] = 0;
                    }
                }
                Timer[EVENT_FLIGHT_SEQUENCE] = 2000;
                break;
            case 10://attack
                DoResetThreat();
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE + UNIT_FLAG_NOT_SELECTABLE);
                me->SetByteValue(UNIT_FIELD_BYTES_2, 0, SHEATH_STATE_MELEE);
                EnterPhase(PHASE_NORMAL_2);
                break;
            default:
                break;
            }
            ++FlightCount;
        }

        void HandleTransformSequence()
        {
            if (DemonTransformation[TransformCount].unaura)
                me->RemoveAurasDueToSpell(DemonTransformation[TransformCount].unaura);

            if (DemonTransformation[TransformCount].aura)
                DoCast(me, DemonTransformation[TransformCount].aura, true);

            if (DemonTransformation[TransformCount].displayid)
                me->SetDisplayId(DemonTransformation[TransformCount].displayid); // It's morphin time!

            if (DemonTransformation[TransformCount].equip)
            {
                // Requip warglaives if needed
                SetEquipmentSlots(false, EQUIP_ID_MAIN_HAND, EQUIP_ID_OFF_HAND, EQUIP_NO_CHANGE);
                me->SetByteValue(UNIT_FIELD_BYTES_2, 0, SHEATH_STATE_MELEE);
            }
            else
            {
                // Unequip warglaives if needed
                SetEquipmentSlots(false, EQUIP_UNEQUIP, EQUIP_UNEQUIP, EQUIP_NO_CHANGE);
            }

            switch(TransformCount)
            {
            case 2:
                DoResetThreat();
                break;
            case 4:
                EnterPhase(PHASE_DEMON);
                break;
            case 7:
                DoResetThreat();
                break;
            case 9:
                if (MaievGUID)
                    EnterPhase(PHASE_NORMAL_MAIEV); // Depending on whether we summoned Maiev, we switch to either phase 5 or 3
                else
                    EnterPhase(PHASE_NORMAL_2);
                break;
            default:
                break;
            }
            if (Phase == PHASE_TRANSFORM_SEQUENCE)
                Timer[EVENT_TRANSFORM_SEQUENCE] = DemonTransformation[TransformCount].timer;
            ++TransformCount;
        }

        void UpdateAI(const uint32 diff)
        {
            if ((!UpdateVictim()) && Phase < PHASE_TALK_SEQUENCE)
                return;

            Event = EVENT_NULL;
            for (int32 i = 1; i <= MaxTimer[Phase]; ++i)
            {
                if (Timer[i]) // Event is enabled
                {
                    if (Timer[i] <= diff)
                    {
                        if (!Event) // No event with higher priority
                            Event = (EventIllidan)i;
                    }
                    else Timer[i] -= diff;
                }
            }

            switch(Phase)
            {
            case PHASE_NORMAL:
                if (HealthBelowPct(65))
                    EnterPhase(PHASE_FLIGHT_SEQUENCE);
                break;

            case PHASE_NORMAL_2:
                if (HealthBelowPct(30))
                    EnterPhase(PHASE_TALK_SEQUENCE);
                break;

            case PHASE_NORMAL_MAIEV:
                if (HealthBelowPct(1))
                    EnterPhase(PHASE_TALK_SEQUENCE);
                break;

            case PHASE_TALK_SEQUENCE:
                if (Event == EVENT_TALK_SEQUENCE)
                    HandleTalkSequence();
                break;

            case PHASE_FLIGHT_SEQUENCE:
                if (Event == EVENT_FLIGHT_SEQUENCE)
                    HandleFlightSequence();
                break;

            case PHASE_TRANSFORM_SEQUENCE:
                if (Event == EVENT_TRANSFORM_SEQUENCE)
                    HandleTransformSequence();
                break;
            default:
                break;
            }

            if (me->IsNonMeleeSpellCasted(false))
                return;

            if (Phase == PHASE_NORMAL || Phase == PHASE_NORMAL_2 || (Phase == PHASE_NORMAL_MAIEV && !me->HasAura(SPELL_CAGED)))
            {
                switch(Event)
                {
                    //PHASE_NORMAL
                case EVENT_BERSERK:
                    me->MonsterYell(SAY_ENRAGE, LANG_UNIVERSAL, 0);
                    DoPlaySoundToSet(me, SOUND_ENRAGE);
                    DoCast(me, SPELL_BERSERK, true);
                    Timer[EVENT_BERSERK] = 5000;//The buff actually lasts forever.
                    break;

                case EVENT_TAUNT:
                    {
                        uint32 random = rand()%4;
                        uint32 soundid = RandomTaunts[random].sound;
                        if (RandomTaunts[random].text.size())
                            me->MonsterYell(RandomTaunts[random].text.c_str(), LANG_UNIVERSAL, 0);
                        if (soundid)
                            DoPlaySoundToSet(me, soundid);
                    }
                    Timer[EVENT_TAUNT] = 25000 + rand()%10000;
                    break;

                case EVENT_SHEAR:
                    // no longer exists in 3.0f.2
                    //DoCast(me->getVictim(), SPELL_SHEAR);
                    Timer[EVENT_SHEAR] = 25000 + (rand()%16 * 1000);
                    break;

                case EVENT_FLAME_CRASH:
                    DoCast(me->getVictim(), SPELL_FLAME_CRASH);
                    Timer[EVENT_FLAME_CRASH] = 30000 + rand()%10000;
                    break;

                case EVENT_PARASITIC_SHADOWFIEND:
                    {
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 1, 200, true))
                            DoCast(pTarget, SPELL_PARASITIC_SHADOWFIEND, true);
                        Timer[EVENT_PARASITIC_SHADOWFIEND] = 35000 + rand()%10000;
                    }
                    break;

                case EVENT_PARASITE_CHECK:
                    Timer[EVENT_PARASITE_CHECK] = 0;
                    break;

                case EVENT_DRAW_SOUL:
                    DoCast(me->getVictim(), SPELL_DRAW_SOUL);
                    Timer[EVENT_DRAW_SOUL] = 50000 + rand()%10000;
                    break;

                    //PHASE_NORMAL_2
                case EVENT_AGONIZING_FLAMES:
                    DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0), SPELL_AGONIZING_FLAMES);
                    Timer[EVENT_AGONIZING_FLAMES] = 0;
                    break;

                case EVENT_TRANSFORM_NORMAL:
                    EnterPhase(PHASE_TRANSFORM_SEQUENCE);
                    break;

                    //PHASE_NORMAL_MAIEV
                case EVENT_ENRAGE:
                    DoCast(me, SPELL_ENRAGE);
                    Timer[EVENT_ENRAGE] = 0;
                    break;

                default:
                    break;
                }
                DoMeleeAttackIfReady();
            }

            if (Phase == PHASE_FLIGHT)
            {
                switch(Event)
                {
                case EVENT_FIREBALL:
                    DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0), SPELL_FIREBALL);
                    Timer[EVENT_FIREBALL] = 3000;
                    break;

                case EVENT_DARK_BARRAGE:
                    DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0), SPELL_DARK_BARRAGE);
                    Timer[EVENT_DARK_BARRAGE] = 0;
                    break;

                case EVENT_EYE_BLAST:
                    CastEyeBlast();
                    Timer[EVENT_EYE_BLAST] = 0;
                    break;

                case EVENT_MOVE_POINT:
                    Phase = PHASE_FLIGHT_SEQUENCE;
                    Timer[EVENT_FLIGHT_SEQUENCE] = 0;//do not start Event when changing hover point
                    HoverPoint += (rand()%3 + 1);
                    if (HoverPoint > 3)
                        HoverPoint -= 4;
                    me->GetMotionMaster()->MovePoint(0, HoverPosition[HoverPoint].x, HoverPosition[HoverPoint].y, HoverPosition[HoverPoint].z);
                    break;

                default:
                    break;
                }
            }

            if (Phase == PHASE_DEMON)
            {
                switch(Event)
                {
                case EVENT_SHADOW_BLAST:
                    me->GetMotionMaster()->Clear(false);
                    if (!me->IsWithinDistInMap(me->getVictim(), 50)||!me->IsWithinLOSInMap(me->getVictim()))
                        me->GetMotionMaster()->MoveChase(me->getVictim(), 30);
                    else
                        me->GetMotionMaster()->MoveIdle();
                    DoCast(me->getVictim(), SPELL_SHADOW_BLAST);
                    Timer[EVENT_SHADOW_BLAST] = 4000;
                    break;
                case EVENT_SHADOWDEMON:
                    DoCast(me, SPELL_SUMMON_SHADOWDEMON);
                    Timer[EVENT_SHADOWDEMON] = 0;
                    Timer[EVENT_FLAME_BURST] += 10000;
                    break;
                case EVENT_FLAME_BURST:
                    DoCast(me, SPELL_FLAME_BURST);
                    Timer[EVENT_FLAME_BURST] = 15000;
                    break;
                case EVENT_TRANSFORM_DEMON:
                    EnterPhase(PHASE_TRANSFORM_SEQUENCE);
                    break;
                default:
                    break;
                }
            }
        }
    };

};

/********************************** End of Illidan AI ******************************************/

/******* Functions and vars for Akama's AI ******/
class boss_maiev_shadowsong : public CreatureScript
{
public:
    boss_maiev_shadowsong() : CreatureScript("boss_maiev_shadowsong") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_maievAI (pCreature);
    }

    struct boss_maievAI : public ScriptedAI
    {
        boss_maievAI(Creature *c) : ScriptedAI(c) {};

        uint64 IllidanGUID;

        PhaseIllidan Phase;
        EventMaiev Event;
        uint32 Timer[5];
        uint32 MaxTimer;

        void Reset()
        {
            MaxTimer = 0;
            Phase = PHASE_NORMAL_MAIEV;
            IllidanGUID = 0;
            Timer[EVENT_MAIEV_STEALTH] = 0;
            Timer[EVENT_MAIEV_TAUNT] = 22000 + rand()%21 * 1000;
            Timer[EVENT_MAIEV_SHADOW_STRIKE] = 30000;
            SetEquipmentSlots(false, 44850, EQUIP_UNEQUIP, EQUIP_NO_CHANGE);
            me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 2, 45738);
        }

        void EnterCombat(Unit * /*who*/) {}
        void MoveInLineOfSight(Unit * /*who*/) {}
        void EnterEvadeMode() {}
        void GetIllidanGUID(uint64 guid) { IllidanGUID = guid; }

        void DamageTaken(Unit *done_by, uint32 &damage)
        {
            if (done_by->GetGUID() != IllidanGUID)
                damage = 0;
            else
            {
                GETUNIT(Illidan, IllidanGUID);
                if (Illidan && Illidan->getVictim() == me)
                    damage = me->CountPctFromMaxHealth(10);
                if (damage >= me->GetHealth())
                    damage = 0;
            }
        }

        void AttackStart(Unit *who)
        {
            if (!who || Timer[EVENT_MAIEV_STEALTH])
                return;

            if (Phase == PHASE_TALK_SEQUENCE)
                AttackStartNoMove(who);
            else if (Phase == PHASE_DEMON || Phase == PHASE_TRANSFORM_SEQUENCE)
            {
                GETUNIT(Illidan, IllidanGUID);
                if (Illidan && me->IsWithinDistInMap(Illidan, 25))
                    BlinkToPlayer();//Do not let dread aura hurt her.
                AttackStartNoMove(who);
            }
            else
                ScriptedAI::AttackStart(who);
        }

        void DoAction(const int32 param)
        {
            if (param > PHASE_ILLIDAN_NULL && param < PHASE_ILLIDAN_MAX)
                EnterPhase(PhaseIllidan(param));
        }

        void EnterPhase(PhaseIllidan NextPhase)//This is in fact Illidan's phase.
        {
            switch(NextPhase)
            {
            case PHASE_TALK_SEQUENCE:
                if (Timer[EVENT_MAIEV_STEALTH])
                {
                    me->SetFullHealth();
                    me->SetVisible(true);
                    Timer[EVENT_MAIEV_STEALTH] = 0;
                }
                me->InterruptNonMeleeSpells(false);
                me->GetMotionMaster()->Clear(false);
                me->AttackStop();
                me->SetUInt64Value(UNIT_FIELD_TARGET, IllidanGUID);
                MaxTimer = 0;
                break;
            case PHASE_TRANSFORM_SEQUENCE:
                MaxTimer = 4;
                Timer[EVENT_MAIEV_TAUNT] += 10000;
                Timer[EVENT_MAIEV_THROW_DAGGER] = 2000;
                break;
            case PHASE_DEMON:
                break;
            case PHASE_NORMAL_MAIEV:
                MaxTimer = 4;
                Timer[EVENT_MAIEV_TAUNT] += 10000;
                Timer[EVENT_MAIEV_TRAP] = 22000;
                break;
            default:
                break;
            }
            if (Timer[EVENT_MAIEV_STEALTH])
                MaxTimer = 1;
            Phase = NextPhase;
        }

        void BlinkTo(float x, float y, float z)
        {
            me->AttackStop();
            me->InterruptNonMeleeSpells(false);
            me->GetMotionMaster()->Clear(false);
            DoTeleportTo(x, y, z);
            DoCast(me, SPELL_TELEPORT_VISUAL, true);
        }

        void BlinkToPlayer()
        {
            if (GETCRE(Illidan, IllidanGUID))
            {
                Unit *pTarget = Illidan->AI()->SelectTarget(SELECT_TARGET_RANDOM, 0);

                if (!pTarget || !me->IsWithinDistInMap(pTarget, 80) || Illidan->IsWithinDistInMap(pTarget, 20))
                {
                    uint8 pos = rand()%4;
                    BlinkTo(HoverPosition[pos].x, HoverPosition[pos].y, HoverPosition[pos].z);
                }
                else
                {
                    float x, y, z;
                    pTarget->GetPosition(x, y, z);
                    BlinkTo(x, y, z);
                }
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if ((!UpdateVictim())
                && !Timer[EVENT_MAIEV_STEALTH])
                return;

            Event = EVENT_MAIEV_NULL;
            for (uint8 i = 1; i <= MaxTimer; ++i)
                if (Timer[i])
                {
                    if (Timer[i] <= diff)
                        Event = (EventMaiev)i;
                    else Timer[i] -= diff;
                }

                switch(Event)
                {
                case EVENT_MAIEV_STEALTH:
                    {
                        me->SetFullHealth();
                        me->SetVisible(true);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        Timer[EVENT_MAIEV_STEALTH] = 0;
                        BlinkToPlayer();
                        EnterPhase(Phase);
                    }
                    break;
                case EVENT_MAIEV_TAUNT:
                    {
                        uint32 random = rand()%4;
                        uint32 sound = MaievTaunts[random].sound;
                        if (MaievTaunts[random].text.size())
                            me->MonsterYell(MaievTaunts[random].text.c_str(), LANG_UNIVERSAL, 0);
                        DoPlaySoundToSet(me, sound);
                        Timer[EVENT_MAIEV_TAUNT] = 22000 + rand()%21 * 1000;
                    }
                    break;
                case EVENT_MAIEV_SHADOW_STRIKE:
                    DoCast(me->getVictim(), SPELL_SHADOW_STRIKE);
                    Timer[EVENT_MAIEV_SHADOW_STRIKE] = 60000;
                    break;
                case EVENT_MAIEV_TRAP:
                    if (Phase == PHASE_NORMAL_MAIEV)
                    {
                        BlinkToPlayer();
                        DoCast(me, SPELL_CAGE_TRAP_SUMMON);
                        Timer[EVENT_MAIEV_TRAP] = 22000;
                    }
                    else
                    {
                        if (!me->IsWithinDistInMap(me->getVictim(), 40))
                            me->GetMotionMaster()->MoveChase(me->getVictim(), 30);
                        DoCast(me->getVictim(), SPELL_THROW_DAGGER);
                        Timer[EVENT_MAIEV_THROW_DAGGER] = 2000;
                    }
                    break;
                default:
                    break;
                }

                if (HealthBelowPct(50))
                {
                    me->SetVisible(false);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    if (GETCRE(Illidan, IllidanGUID))
                        CAST_AI(boss_illidan_stormrage::boss_illidan_stormrageAI, Illidan->AI())->DeleteFromThreatList(me->GetGUID());
                    me->AttackStop();
                    Timer[EVENT_MAIEV_STEALTH] = 60000; //reappear after 1 minute
                    MaxTimer = 1;
                }

                if (Phase == PHASE_NORMAL_MAIEV)
                    DoMeleeAttackIfReady();
        }
    };

};

class npc_akama_illidan : public CreatureScript
{
public:
    npc_akama_illidan() : CreatureScript("npc_akama_illidan") { }

    struct npc_akama_illidanAI : public ScriptedAI
    {
        npc_akama_illidanAI(Creature* c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
            JustCreated = true;
        }
        bool JustCreated;
        InstanceScript* pInstance;

        PhaseAkama Phase;
        bool Event;
        uint32 Timer;

        uint64 IllidanGUID;
        uint64 ChannelGUID;
        uint64 SpiritGUID[2];
        uint64 GateGUID;
        uint64 DoorGUID[2];

        uint32 ChannelCount;
        uint32 WalkCount;
        uint32 TalkCount;
        uint32 Check_Timer;

        void Reset()
        {
            WalkCount = 0;
            if (pInstance)
            {
                pInstance->SetData(DATA_ILLIDANSTORMRAGEEVENT, NOT_STARTED);

                IllidanGUID = pInstance->GetData64(DATA_ILLIDANSTORMRAGE);
                GateGUID = pInstance->GetData64(DATA_GAMEOBJECT_ILLIDAN_GATE);
                DoorGUID[0] = pInstance->GetData64(DATA_GAMEOBJECT_ILLIDAN_DOOR_R);
                DoorGUID[1] = pInstance->GetData64(DATA_GAMEOBJECT_ILLIDAN_DOOR_L);

                if (JustCreated)//close all doors at create
                {
                    pInstance->HandleGameObject(GateGUID, false);

                    for (uint8 i = 0; i < 2; ++i)
                        pInstance->HandleGameObject(DoorGUID[i], false);
                    //JustCreated = false;
                }else
                {//open all doors, raid wiped
                    pInstance->HandleGameObject(GateGUID, true);
                    WalkCount = 1;//skip first wp
                    for (uint8 i = 0; i < 2; ++i)
                        pInstance->HandleGameObject(DoorGUID[i], true);
                }
            }
            else
            {
                IllidanGUID = 0;
                GateGUID = 0;
                DoorGUID[0] = 0;
                DoorGUID[1] = 0;
            }

            ChannelGUID = 0;
            SpiritGUID[0] = 0;
            SpiritGUID[1] = 0;

            Phase = PHASE_AKAMA_NULL;
            Timer = 0;

            ChannelCount = 0;
            TalkCount = 0;
            Check_Timer = 5000;

            KillAllElites();

            me->SetUInt32Value(UNIT_NPC_FLAGS, 0); // Database sometimes has strange values..
            me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            me->setActive(false);
            me->SetVisible(false);
        }

        // Do not call reset in Akama's evade mode, as this will stop him from summoning minions after he kills the first bit
        void EnterEvadeMode()
        {
            me->RemoveAllAuras();
            me->DeleteThreatList();
            me->CombatStop(true);
        }

        void EnterCombat(Unit * /*who*/) {}
        void MoveInLineOfSight(Unit* /*who*/) {}

        void MovementInform(uint32 MovementType, uint32 /*Data*/)
        {
            if (MovementType == POINT_MOTION_TYPE)
                Timer = 1;
        }

        void DamageTaken(Unit *done_by, uint32 &damage)
        {
            if (damage > me->GetHealth() || done_by->GetGUID() != IllidanGUID)
                damage = 0;
        }

        void KillAllElites()
        {
            std::list<HostileReference*>& threatList = me->getThreatManager().getThreatList();
            std::vector<Unit*> eliteList;
            for (std::list<HostileReference*>::const_iterator itr = threatList.begin(); itr != threatList.end(); ++itr)
            {
                Unit* pUnit = Unit::GetUnit((*me), (*itr)->getUnitGuid());
                if (pUnit && pUnit->GetEntry() == ILLIDARI_ELITE)
                    eliteList.push_back(pUnit);
            }
            for (std::vector<Unit*>::const_iterator itr = eliteList.begin(); itr != eliteList.end(); ++itr)
                (*itr)->setDeathState(JUST_DIED);
            EnterEvadeMode();
        }

        void BeginTalk()
        {
            if (!pInstance)
                return;

            pInstance->SetData(DATA_ILLIDANSTORMRAGEEVENT, IN_PROGRESS);
            for (uint8 i = 0; i < 2; ++i)
                pInstance->HandleGameObject(DoorGUID[i], false);
            if (GETCRE(Illidan, IllidanGUID))
            {
                Illidan->RemoveAurasDueToSpell(SPELL_KNEEL);
                me->SetInFront(Illidan);
                Illidan->SetInFront(me);
                me->GetMotionMaster()->MoveIdle();
                Illidan->GetMotionMaster()->MoveIdle();
                CAST_AI(boss_illidan_stormrage::boss_illidan_stormrageAI, Illidan->AI())->AkamaGUID = me->GetGUID();
                CAST_AI(boss_illidan_stormrage::boss_illidan_stormrageAI, Illidan->AI())->EnterPhase(PHASE_TALK_SEQUENCE);
            }
        }

        void BeginChannel()
        {
            me->setActive(true);
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            if (!JustCreated)
                return;
            float x, y, z;
            if (GETGO(Gate, GateGUID))
                Gate->GetPosition(x, y, z);
            else
                return;//if door not spawned, don't crash server

            if (Creature* Channel = me->SummonCreature(ILLIDAN_DOOR_TRIGGER, x, y, z+5, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 360000))
            {
                ChannelGUID = Channel->GetGUID();
                Channel->SetDisplayId(11686); // Invisible but spell visuals can still be seen.
                DoCast(Channel, SPELL_AKAMA_DOOR_FAIL);
            }

            for (uint8 i = 0; i < 2; ++i)
                if (Creature* Spirit = me->SummonCreature(i ? SPIRIT_OF_OLUM : SPIRIT_OF_UDALO, SpiritSpawns[i].x, SpiritSpawns[i].y, SpiritSpawns[i].z, 0, TEMPSUMMON_TIMED_DESPAWN, 20000))
                {
                    Spirit->SetVisible(false);
                    SpiritGUID[i] = Spirit->GetGUID();
                }
        }

        void BeginWalk()
        {
            me->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
            me->SetSpeed(MOVE_RUN, 1.0f);
            me->GetMotionMaster()->MovePoint(0, AkamaWP[WalkCount].x, AkamaWP[WalkCount].y, AkamaWP[WalkCount].z);
        }

        void EnterPhase(PhaseAkama NextPhase)
        {
            if (!pInstance)
                return;
            switch(NextPhase)
            {
            case PHASE_CHANNEL:
                BeginChannel();
                Timer = 5000;
                ChannelCount = 0;
                break;
            case PHASE_WALK:
                if (Phase == PHASE_CHANNEL)
                    WalkCount = 0;
                else if (Phase == PHASE_TALK)
                {
                    if (GETCRE(Illidan, IllidanGUID))
                        CAST_AI(boss_illidan_stormrage::boss_illidan_stormrageAI, Illidan->AI())->DeleteFromThreatList(me->GetGUID());
                    EnterEvadeMode();
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    ++WalkCount;
                }
                JustCreated = false;
                BeginWalk();
                Timer = 0;
                break;
            case PHASE_TALK:
                if (Phase == PHASE_WALK)
                {
                    BeginTalk();
                    Timer = 0;
                }
                else if (Phase == PHASE_FIGHT_ILLIDAN)
                {
                    Timer = 1;
                    TalkCount = 0;
                }
                break;
            case PHASE_FIGHT_ILLIDAN:
                if (GETUNIT(Illidan, IllidanGUID))
                {
                    me->AddThreat(Illidan, 10000000.0f);
                    me->GetMotionMaster()->MoveChase(Illidan);
                }
                Timer = 30000; //chain lightning
                break;
            case PHASE_FIGHT_MINIONS:
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                Timer = 10000 + rand()%6000;//summon minion
                break;
            case PHASE_RETURN:
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                KillAllElites();
                WalkCount = 0;
                BeginWalk();
                Timer = 1;
                break;
            default:
                break;
            }
            Phase = NextPhase;
            Event = false;
        }

        void HandleTalkSequence()
        {
            switch(TalkCount)
            {
            case 0:
                if (GETCRE(Illidan, IllidanGUID))
                {
                    CAST_AI(boss_illidan_stormrage::boss_illidan_stormrageAI, Illidan->AI())->Timer[EVENT_TAUNT] += 30000;
                    Illidan->MonsterYell(SAY_AKAMA_MINION, LANG_UNIVERSAL, 0);
                    DoPlaySoundToSet(Illidan, SOUND_AKAMA_MINION);
                }
                Timer = 8000;
                break;
            case 1:
                me->MonsterYell(SAY_AKAMA_LEAVE, LANG_UNIVERSAL, 0);
                DoPlaySoundToSet(me, SOUND_AKAMA_LEAVE);
                Timer = 3000;
                break;
            case 2:
                EnterPhase(PHASE_WALK);
                break;
            }
            ++TalkCount;
        }

        void HandleChannelSequence()
        {
            Unit* Channel = NULL, *Spirit[2];
            if (ChannelCount <= 5)
            {
                Channel = Unit::GetUnit((*me), ChannelGUID);
                Spirit[0] = Unit::GetUnit((*me), SpiritGUID[0]);
                Spirit[1] = Unit::GetUnit((*me), SpiritGUID[1]);
                if (!Channel || !Spirit[0] || !Spirit[1])
                    return;
            }

            switch(ChannelCount)
            {
            case 0: // channel failed
                me->InterruptNonMeleeSpells(true);
                Timer = 2000;
                break;
            case 1: // spirit appear
                Spirit[0]->SetVisible(true);
                Spirit[1]->SetVisible(true);
                Timer = 2000;
                break;
            case 2: // spirit help
                DoCast(Channel, SPELL_AKAMA_DOOR_CHANNEL);
                Spirit[0]->CastSpell(Channel, SPELL_DEATHSWORN_DOOR_CHANNEL, false);
                Spirit[1]->CastSpell(Channel, SPELL_DEATHSWORN_DOOR_CHANNEL, false);
                Timer = 5000;
                break;
            case 3: //open the gate
                me->InterruptNonMeleeSpells(true);
                Spirit[0]->InterruptNonMeleeSpells(true);
                Spirit[1]->InterruptNonMeleeSpells(true);
                if (pInstance)
                    pInstance->HandleGameObject(GateGUID, true);
                Timer = 2000;
                break;
            case 4:
                me->HandleEmoteCommand(EMOTE_ONESHOT_SALUTE);
                Timer = 2000;
                break;
            case 5:
                me->MonsterYell(SAY_AKAMA_BEWARE, LANG_UNIVERSAL, 0);
                DoPlaySoundToSet(me, SOUND_AKAMA_BEWARE);
                Channel->setDeathState(JUST_DIED);
                Spirit[0]->SetVisible(false);
                Spirit[1]->SetVisible(false);
                Timer = 3000;
                break;
            case 6:
                EnterPhase(PHASE_WALK);
                break;
            default:
                break;
            }
            ++ChannelCount;
        }

        void HandleWalkSequence()
        {
            switch(WalkCount)
            {
            case 6:
                for (uint8 i = 0; i < 2; ++i)
                    if (pInstance)
                        pInstance->HandleGameObject(DoorGUID[i], true);
                break;
            case 8:
                if (Phase == PHASE_WALK)
                    EnterPhase(PHASE_TALK);
                else
                    EnterPhase(PHASE_FIGHT_ILLIDAN);
                break;
            case 12:
                EnterPhase(PHASE_FIGHT_MINIONS);
                break;
            }

            if (Phase == PHASE_WALK)
            {
                Timer = 0;
                ++WalkCount;
                me->GetMotionMaster()->MovePoint(WalkCount, AkamaWP[WalkCount].x, AkamaWP[WalkCount].y, AkamaWP[WalkCount].z);
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (!me->IsVisible())
            {
                if (Check_Timer <= diff)
                {
                    if (pInstance && pInstance->GetData(DATA_ILLIDARICOUNCILEVENT) == DONE)
                        me->SetVisible(true);

                    Check_Timer = 5000;
                } else Check_Timer -= diff;
            }
            Event = false;
            if (Timer)
            {
                if (Timer <= diff)
                    Event = true;
                else Timer -= diff;
            }

            if (Event)
            {
                switch(Phase)
                {
                case PHASE_CHANNEL:
                    if (JustCreated)
                        HandleChannelSequence();
                    else{
                        EnterPhase(PHASE_WALK);
                    }
                    break;
                case PHASE_TALK:
                    HandleTalkSequence();
                    break;
                case PHASE_WALK:
                case PHASE_RETURN:
                    HandleWalkSequence();
                    break;
                case PHASE_FIGHT_ILLIDAN:
                    {
                        GETUNIT(Illidan, IllidanGUID);
                        if (Illidan && Illidan->HealthBelowPct(90))
                            EnterPhase(PHASE_TALK);
                        else
                        {
                            DoCast(me->getVictim(), SPELL_CHAIN_LIGHTNING);
                            Timer = 30000;
                        }
                    }
                    break;
                case PHASE_FIGHT_MINIONS:
                    {
                        float x, y, z;
                        me->GetPosition(x, y, z);
                        Creature* Elite = me->SummonCreature(ILLIDARI_ELITE, x+rand()%10, y+rand()%10, z, 0, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 30000);
                        //Creature* Elite = me->SummonCreature(ILLIDARI_ELITE, x, y, z, 0, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 30000);
                        if (Elite)
                        {
                            Elite->AI()->AttackStart(me);
                            Elite->AddThreat(me, 1000000.0f);
                            AttackStart(Elite);
                            me->AddThreat(Elite, 1000000.0f);
                        }
                        Timer = 10000 + rand()%6000;
                        GETUNIT(Illidan, IllidanGUID);
                        if (Illidan && Illidan->HealthBelowPct(10))
                            EnterPhase(PHASE_RETURN);
                    }
                    break;
                default:
                    break;
                }
            }

            if (!UpdateVictim())
                return;

            if (HealthBelowPct(20))
                DoCast(me, SPELL_HEALING_POTION);

            DoMeleeAttackIfReady();
        }
    };

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        if (uiAction == GOSSIP_ACTION_INFO_DEF) // Time to begin the Event
        {
            pPlayer->CLOSE_GOSSIP_MENU();
            CAST_AI(npc_akama_illidan::npc_akama_illidanAI, pCreature->AI())->EnterPhase(PHASE_CHANNEL);
        }
        return true;
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
        pPlayer->SEND_GOSSIP_MENU(10465, pCreature->GetGUID());

        return true;
    }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_akama_illidanAI(pCreature);
    }

};

void boss_illidan_stormrage::boss_illidan_stormrageAI::Reset()
{
    if (pInstance)
        pInstance->SetData(DATA_ILLIDANSTORMRAGEEVENT, NOT_STARTED);

    if (AkamaGUID)
    {
        if (GETCRE(Akama, AkamaGUID))
        {
            if (!Akama->isAlive())
                Akama->Respawn();
            else
            {
                CAST_AI(npc_akama_illidan::npc_akama_illidanAI, Akama->AI())->EnterEvadeMode();
                Akama->GetMotionMaster()->MoveTargetedHome();
                CAST_AI(npc_akama_illidan::npc_akama_illidanAI, Akama->AI())->Reset();
            }
        }
        AkamaGUID = 0;
    }

    MaievGUID = 0;
    for (uint8 i = 0; i < 2; ++i)
    {
        FlameGUID[i] = 0;
        GlaiveGUID[i] = 0;
    }

    Phase = PHASE_ILLIDAN_NULL;
    Event = EVENT_NULL;
    Timer[EVENT_BERSERK] = 1500000;

    HoverPoint = 0;
    TalkCount = 0;
    FlightCount = 0;
    TransformCount = 0;

    me->SetDisplayId(21135);
    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
    SetEquipmentSlots(false, EQUIP_UNEQUIP, EQUIP_UNEQUIP, EQUIP_NO_CHANGE);
    me->RemoveUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
    me->setActive(false);
    Summons.DespawnAll();
}

void boss_illidan_stormrage::boss_illidan_stormrageAI::JustSummoned(Creature* summon)
{
    Summons.Summon(summon);
    switch(summon->GetEntry())
    {
    case PARASITIC_SHADOWFIEND:
        {
            if (Phase == PHASE_TALK_SEQUENCE)
            {
                summon->SetVisible(false);
                summon->setDeathState(JUST_DIED);
                return;
            }
            Unit *pTarget = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 999, true);
            if (!pTarget || pTarget->HasAura(SPELL_PARASITIC_SHADOWFIEND)
                || pTarget->HasAura(SPELL_PARASITIC_SHADOWFIEND2))
                pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 999, true);
            if (pTarget)
                summon->AI()->AttackStart(pTarget);
        }
        break;
    case SHADOW_DEMON:
        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 999, true)) // only on players.
        {
            summon->AddThreat(pTarget, 5000000.0f);
            summon->AI()->AttackStart(pTarget);
        }
        break;
    case MAIEV_SHADOWSONG:
        {
            summon->SetVisible(false); // Leave her invisible until she has to talk
            summon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            MaievGUID = summon->GetGUID();
            CAST_AI(boss_maiev_shadowsong::boss_maievAI, summon->AI())->GetIllidanGUID(me->GetGUID());
            summon->AI()->DoAction(PHASE_TALK_SEQUENCE);
        }
        break;
    case FLAME_OF_AZZINOTH:
        {
            summon->AI()->AttackStart(summon->SelectNearestTarget(999));
        }
        break;
    default:
        break;
    }
}

void boss_illidan_stormrage::boss_illidan_stormrageAI::HandleTalkSequence()
{
    switch(TalkCount)
    {
    case 0:
        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        break;
    case 8:
        // Equip our warglaives!
        SetEquipmentSlots(false, EQUIP_ID_MAIN_HAND, EQUIP_ID_OFF_HAND, EQUIP_NO_CHANGE);
        me->SetByteValue(UNIT_FIELD_BYTES_2, 0, SHEATH_STATE_MELEE);
        me->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
        break;
    case 9:
        if (GETCRE(Akama, AkamaGUID))
        {
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE + UNIT_FLAG_NOT_SELECTABLE);
            me->AddThreat(Akama, 100.0f);
            CAST_AI(npc_akama_illidan::npc_akama_illidanAI, Akama->AI())->EnterPhase(PHASE_FIGHT_ILLIDAN);
            EnterPhase(PHASE_NORMAL);
        }
        break;
    case 10:
        SummonMaiev();
        break;
    case 11:
        if (GETUNIT(Maiev, MaievGUID))
        {
            Maiev->SetVisible(true); // Maiev is now visible
            Maiev->CastSpell(Maiev, SPELL_TELEPORT_VISUAL, true); // onoz she looks like she teleported!
            Maiev->SetInFront(me); // Have her face us
            me->SetInFront(Maiev); // Face her, so it's not rude =P
            Maiev->GetMotionMaster()->MoveIdle();
            me->GetMotionMaster()->MoveIdle();
        }
        break;
    case 14:
        if (GETCRE(Maiev, MaievGUID))
        {
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE + UNIT_FLAG_NOT_SELECTABLE);
            Maiev->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE + UNIT_FLAG_NOT_SELECTABLE);
            Maiev->AddThreat(me, 10000000.0f); // Have Maiev add a lot of threat on us so that players don't pull her off if they damage her via AOE
            Maiev->AI()->AttackStart(me); // Force Maiev to attack us.
            EnterPhase(PHASE_NORMAL_MAIEV);
        }
        break;
    case 15:
        DoCast(me, SPELL_DEATH); // Animate his kneeling + stun him
        Summons.DespawnAll();
        break;
    case 17:
        if (GETUNIT(Akama, AkamaGUID))
        {
            if (!me->IsWithinDistInMap(Akama, 15))
            {
                float x, y, z;
                me->GetPosition(x, y, z);
                x += 10; y += 10;
                Akama->GetMotionMaster()->Clear(false);
                //Akama->GetMotionMaster()->MoveIdle();
                Akama->GetMap()->CreatureRelocation(me, x, y, z, 0.0f);
                Akama->SendMonsterMove(x, y, z, 0, MOVEMENTFLAG_NONE, 0);//Illidan must not die until Akama arrives.
                Akama->GetMotionMaster()->MoveChase(me);
            }
        }
        break;
    case 19: // Make Maiev leave
        if (GETUNIT(Maiev, MaievGUID))
        {
            Maiev->CastSpell(Maiev, SPELL_TELEPORT_VISUAL, true);
            Maiev->setDeathState(JUST_DIED);
            me->SetUInt32Value(UNIT_FIELD_BYTES_1, UNIT_STAND_STATE_DEAD);
        }
        break;
    case 21: // Kill ourself.
        me->DealDamage(me, me->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
        break;
    default:
        break;
    }
    if (Phase == PHASE_TALK_SEQUENCE)
        Talk(TalkCount); // This function does most of the talking
    ++TalkCount;
}

class mob_cage_trap_trigger : public CreatureScript
{
public:
    mob_cage_trap_trigger() : CreatureScript("mob_cage_trap_trigger") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new cage_trap_triggerAI (pCreature);
    }

    struct cage_trap_triggerAI : public ScriptedAI
    {
        cage_trap_triggerAI(Creature *c) : ScriptedAI(c) {}

        uint64 IllidanGUID;
        uint32 DespawnTimer;

        bool Active;
        bool SummonedBeams;

        void Reset()
        {
            IllidanGUID = 0;

            Active = false;
            SummonedBeams = false;

            DespawnTimer = 0;

            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        }

        void EnterCombat(Unit * /*who*/){}

        void MoveInLineOfSight(Unit *who)
        {
            if (!Active)
                return;

            if (who && (who->GetTypeId() != TYPEID_PLAYER))
            {
                if (who->GetEntry() == ILLIDAN_STORMRAGE) // Check if who is Illidan
                {
                    if (!IllidanGUID && me->IsWithinDistInMap(who, 3) && (!who->HasAura(SPELL_CAGED)))
                    {
                        IllidanGUID = who->GetGUID();
                        who->CastSpell(who, SPELL_CAGED, true);
                        DespawnTimer = 5000;
                        if (who->HasAura(SPELL_ENRAGE))
                            who->RemoveAurasDueToSpell(SPELL_ENRAGE); // Dispel his enrage
                        //if (GameObject* CageTrap = pInstance->instance->GetGameObject(pInstance->GetData64(CageTrapGUID)))
                        //    CageTrap->SetLootState(GO_JUST_DEACTIVATED);
                    }
                }
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (DespawnTimer)
            {
                if (DespawnTimer <= diff)
                    me->DealDamage(me, me->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                else DespawnTimer -= diff;
            }

                //if (IllidanGUID && !SummonedBeams)
                //{
                //    if (Unit* Illidan = Unit::GetUnit(*me, IllidanGUID)
                //    {
                //        //TODO: Find proper spells and properly apply 'caged' Illidan effect
                //    }
                //}
        }
    };

};

class gameobject_cage_trap : public GameObjectScript
{
public:
    gameobject_cage_trap() : GameObjectScript("gameobject_cage_trap") { }

    bool OnGossipHello(Player* pPlayer, GameObject* pGo)
    {
        float x, y, z;
        pPlayer->GetPosition(x, y, z);

        // Grid search for nearest live Creature of entry 23304 within 10 yards
        if (Creature* pTrigger = pGo->FindNearestCreature(23304, 10.0f))
            CAST_AI(mob_cage_trap_trigger::cage_trap_triggerAI, pTrigger->AI())->Active = true;
        pGo->SetGoState(GO_STATE_ACTIVE);
        return true;
    }

};

class mob_shadow_demon : public CreatureScript
{
public:
    mob_shadow_demon() : CreatureScript("mob_shadow_demon") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new shadow_demonAI (pCreature);
    }

    struct shadow_demonAI : public ScriptedAI
    {
        shadow_demonAI(Creature *c) : ScriptedAI(c) {}

        uint64 TargetGUID;

        void EnterCombat(Unit * /*who*/) {DoZoneInCombat();}

        void Reset()
        {
            TargetGUID = 0;
            DoCast(me, SPELL_SHADOW_DEMON_PASSIVE, true);
        }

        void JustDied(Unit * /*killer*/)
        {
            if (Unit *pTarget = Unit::GetUnit((*me), TargetGUID))
                pTarget->RemoveAurasDueToSpell(SPELL_PARALYZE);
        }

        void UpdateAI(const uint32 /*diff*/)
        {
            if (!UpdateVictim()) return;

            if (me->getVictim()->GetTypeId() != TYPEID_PLAYER) return; // Only cast the below on players.

            if (!me->getVictim()->HasAura(SPELL_PARALYZE))
            {
                TargetGUID = me->getVictim()->GetGUID();
                me->AddThreat(me->getVictim(), 10000000.0f);
                DoCast(me->getVictim(), SPELL_PURPLE_BEAM, true);
                DoCast(me->getVictim(), SPELL_PARALYZE, true);
            }
            // Kill our target if we're very close.
            if (me->IsWithinDistInMap(me->getVictim(), 3))
                DoCast(me->getVictim(), SPELL_CONSUME_SOUL);
        }
    };

};

class mob_blade_of_azzinoth : public CreatureScript
{
public:
    mob_blade_of_azzinoth() : CreatureScript("mob_blade_of_azzinoth") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new blade_of_azzinothAI (pCreature);
    }

    struct blade_of_azzinothAI : public NullCreatureAI
    {
        blade_of_azzinothAI(Creature* c) : NullCreatureAI(c) {}

        void SpellHit(Unit * /*caster*/, const SpellEntry *spell)
        {
            if (spell->Id == SPELL_THROW_GLAIVE2 || spell->Id == SPELL_THROW_GLAIVE)
                me->SetDisplayId(21431);//appear when hit by Illidan's glaive
        }
    };

};

class mob_parasitic_shadowfiend : public CreatureScript
{
public:
    mob_parasitic_shadowfiend() : CreatureScript("mob_parasitic_shadowfiend") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_parasitic_shadowfiendAI (pCreature);
    }

    // Shadowfiends interact with Illidan, setting more targets in Illidan's hashmap
    struct mob_parasitic_shadowfiendAI : public ScriptedAI
    {
        mob_parasitic_shadowfiendAI(Creature* c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
        }

        InstanceScript* pInstance;
        uint64 IllidanGUID;
        uint32 CheckTimer;

        void Reset()
        {
            if (pInstance)
                IllidanGUID = pInstance->GetData64(DATA_ILLIDANSTORMRAGE);
            else
                IllidanGUID = 0;

            CheckTimer = 5000;
            DoCast(me, SPELL_SHADOWFIEND_PASSIVE, true);
        }

        void EnterCombat(Unit* /*who*/) { DoZoneInCombat(); }

        void DoMeleeAttackIfReady()
        {
            if (me->isAttackReady() && me->IsWithinMeleeRange(me->getVictim()))
            {
                if (!me->getVictim()->HasAura(SPELL_PARASITIC_SHADOWFIEND)
                    && !me->getVictim()->HasAura(SPELL_PARASITIC_SHADOWFIEND2))
                {
                    if (Creature* illidan = Unit::GetCreature((*me), IllidanGUID))//summon only in 1. phase
                        if (CAST_AI(boss_illidan_stormrage::boss_illidan_stormrageAI, illidan->AI())->Phase == PHASE_NORMAL)
                            me->CastSpell(me->getVictim(), SPELL_PARASITIC_SHADOWFIEND2, true, 0, 0, IllidanGUID); //do not stack
                }
                me->AttackerStateUpdate(me->getVictim());
                me->resetAttackTimer();
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (!me->getVictim())
            {
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 999, true))
                    AttackStart(pTarget);
                else
                {
                    me->SetVisible(false);
                    me->setDeathState(JUST_DIED);
                    return;
                }
            }

            if (CheckTimer <= diff)
            {
                GETUNIT(Illidan, IllidanGUID);
                if (!Illidan || CAST_CRE(Illidan)->IsInEvadeMode())
                {
                    me->SetVisible(false);
                    me->setDeathState(JUST_DIED);
                    return;
                } else CheckTimer = 5000;
            } else CheckTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_illidan()
{
    new boss_illidan_stormrage();
    new npc_akama_illidan();
    new boss_maiev_shadowsong();
    new mob_flame_of_azzinoth();
    new mob_blade_of_azzinoth();
    new gameobject_cage_trap();
    new mob_cage_trap_trigger();
    new mob_shadow_demon();
    new mob_parasitic_shadowfiend();
}
