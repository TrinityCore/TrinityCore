/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2007 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Boss_Hex_Lord_Malacrass
SD%Complete:
SDComment:
SDCategory: Zul'Aman
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "zulaman.h"

#define YELL_AGGRO              "Da shadow gonna fall on you... "
#define SOUND_YELL_AGGRO        12041
#define YELL_SPIRIT_BOLTS       "Your soul gonna bleed!"
#define SOUND_YELL_SPIRIT_BOLTS 12047
#define YELL_DRAIN_POWER        "Darkness comin\' for you"
#define SOUND_YELL_DRAIN_POWER  12046
#define YELL_KILL_ONE           "Dis a nightmare ya don\' wake up from!"
#define SOUND_YELL_KILL_ONE     12043
#define YELL_KILL_TWO           "Azzaga choogo zinn!"
#define SOUND_YELL_KILL_TWO     12044
#define YELL_DEATH              "Dis not... da end of me..."
#define SOUND_YELL_DEATH        12051


enum Creatures
{
    NPC_TEMP_TRIGGER                = 23920
};

enum Spells
{
    SPELL_SPIRIT_BOLTS              = 43383,
    SPELL_DRAIN_POWER               = 44131,
    SPELL_SIPHON_SOUL               = 43501,

    // Druid
    SPELL_DR_THORNS                 = 43420,
    SPELL_DR_LIFEBLOOM              = 43421,
    SPELL_DR_MOONFIRE               = 43545,

    // Hunter
    SPELL_HU_EXPLOSIVE_TRAP         = 43444,
    SPELL_HU_FREEZING_TRAP          = 43447,
    SPELL_HU_SNAKE_TRAP             = 43449,

    // Mage
    SPELL_MG_FIREBALL               = 41383,
    SPELL_MG_FROST_NOVA             = 43426,
    SPELL_MG_ICE_LANCE              = 43427,
    SPELL_MG_FROSTBOLT              = 43428,

    // Paladin
    SPELL_PA_CONSECRATION           = 43429,
    SPELL_PA_AVENGING_WRATH         = 43430,
    SPELL_PA_HOLY_LIGHT             = 43451,

    // Priest
    SPELL_PR_HEAL                   = 41372,
    SPELL_PR_MIND_BLAST             = 41374,
    SPELL_PR_SW_DEATH               = 41375,
    SPELL_PR_PSYCHIC_SCREAM         = 43432,
    SPELL_PR_MIND_CONTROL           = 43550,
    SPELL_PR_PAIN_SUPP              = 44416,

    // Rogue
    SPELL_RO_BLIND                  = 43433,
    SPELL_RO_SLICE_DICE             = 43457,
    SPELL_RO_WOUND_POISON           = 43461,

    // Shaman
    SPELL_SH_CHAIN_LIGHT            = 43435,
    SPELL_SH_FIRE_NOVA              = 43436,
    SPELL_SH_HEALING_WAVE           = 43548,

    // Warlock
    SPELL_WL_CURSE_OF_DOOM          = 43439,
    SPELL_WL_RAIN_OF_FIRE           = 43440,
    SPELL_WL_UNSTABLE_AFFL          = 43522,
    SPELL_WL_UNSTABLE_AFFL_DISPEL   = 43523,

    // Warrior
    SPELL_WR_MORTAL_STRIKE          = 43441,
    SPELL_WR_WHIRLWIND              = 43442,
    SPELL_WR_SPELL_REFLECT          = 43443,

    // Thurg
    SPELL_BLOODLUST                 = 43578,
    SPELL_CLEAVE                    = 15496,

    // Gazakroth
    SPELL_FIREBOLT                  = 43584,

    // Alyson Antille
    SPELL_FLASH_HEAL                = 43575,
    SPELL_DISPEL_MAGIC              = 43577,

    // Lord Raadan
    SPELL_FLAME_BREATH              = 43582,
    SPELL_THUNDERCLAP               = 43583,

    // Darkheart
    SPELL_PSYCHIC_WAIL              = 43590,

    // Slither
    SPELL_VENOM_SPIT                = 43579,

    // Fenstalker
    SPELL_VOLATILE_INFECTION        = 43586,

    // Koragg
    SPELL_COLD_STARE                = 43593,
    SPELL_MIGHTY_BLOW               = 43592

};

#define ORIENT                  1.5696f
#define POS_Y                   921.2795f
#define POS_Z                   33.8883f

static float Pos_X[4] = {112.8827f, 107.8827f, 122.8827f, 127.8827f};

static uint32 AddEntryList[8]=
{
    24240, //Alyson Antille
    24241, //Thurg
    24242, //Slither
    24243, //Lord Raadan
    24244, //Gazakroth
    24245, //Fenstalker
    24246, //Darkheart
    24247  //Koragg
};

enum AbilityTarget
{
    ABILITY_TARGET_SELF = 0,
    ABILITY_TARGET_VICTIM = 1,
    ABILITY_TARGET_ENEMY = 2,
    ABILITY_TARGET_HEAL = 3,
    ABILITY_TARGET_BUFF = 4,
    ABILITY_TARGET_SPECIAL = 5
};

struct PlayerAbilityStruct
{
    uint32 spell;
    AbilityTarget target;
    uint32 cooldown; //FIXME - it's never used
};

static PlayerAbilityStruct PlayerAbility[][3] =
{
    // 1 warrior
    {{SPELL_WR_SPELL_REFLECT, ABILITY_TARGET_SELF, 10000},
    {SPELL_WR_WHIRLWIND, ABILITY_TARGET_SELF, 10000},
    {SPELL_WR_MORTAL_STRIKE, ABILITY_TARGET_VICTIM, 6000}},
    // 2 paladin
    {{SPELL_PA_CONSECRATION, ABILITY_TARGET_SELF, 10000},
    {SPELL_PA_HOLY_LIGHT, ABILITY_TARGET_HEAL, 10000},
    {SPELL_PA_AVENGING_WRATH, ABILITY_TARGET_SELF, 10000}},
    // 3 hunter
    {{SPELL_HU_EXPLOSIVE_TRAP, ABILITY_TARGET_SELF, 10000},
    {SPELL_HU_FREEZING_TRAP, ABILITY_TARGET_SELF, 10000},
    {SPELL_HU_SNAKE_TRAP, ABILITY_TARGET_SELF, 10000}},
    // 4 rogue
    {{SPELL_RO_WOUND_POISON, ABILITY_TARGET_VICTIM, 3000},
    {SPELL_RO_SLICE_DICE, ABILITY_TARGET_SELF, 10000},
    {SPELL_RO_BLIND, ABILITY_TARGET_ENEMY, 10000}},
    // 5 priest
    {{SPELL_PR_PAIN_SUPP, ABILITY_TARGET_HEAL, 10000},
    {SPELL_PR_HEAL, ABILITY_TARGET_HEAL, 10000},
    {SPELL_PR_PSYCHIC_SCREAM, ABILITY_TARGET_SELF, 10000}},
    // 5* shadow priest
    {{SPELL_PR_MIND_CONTROL, ABILITY_TARGET_ENEMY, 15000},
    {SPELL_PR_MIND_BLAST, ABILITY_TARGET_ENEMY, 5000},
    {SPELL_PR_SW_DEATH, ABILITY_TARGET_ENEMY, 10000}},
    // 7 shaman
    {{SPELL_SH_FIRE_NOVA, ABILITY_TARGET_SELF, 10000},
    {SPELL_SH_HEALING_WAVE, ABILITY_TARGET_HEAL, 10000},
    {SPELL_SH_CHAIN_LIGHT, ABILITY_TARGET_ENEMY, 8000}},
    // 8 mage
    {{SPELL_MG_FIREBALL, ABILITY_TARGET_ENEMY, 5000},
    {SPELL_MG_FROSTBOLT, ABILITY_TARGET_ENEMY, 5000},
    {SPELL_MG_ICE_LANCE, ABILITY_TARGET_SPECIAL, 2000}},
    // 9 warlock
    {{SPELL_WL_CURSE_OF_DOOM, ABILITY_TARGET_ENEMY, 10000},
    {SPELL_WL_RAIN_OF_FIRE, ABILITY_TARGET_ENEMY, 10000},
    {SPELL_WL_UNSTABLE_AFFL, ABILITY_TARGET_ENEMY, 10000}},
    // 11 druid
    {{SPELL_DR_LIFEBLOOM, ABILITY_TARGET_HEAL, 10000},
    {SPELL_DR_THORNS, ABILITY_TARGET_SELF, 10000},
    {SPELL_DR_MOONFIRE, ABILITY_TARGET_ENEMY, 8000}}
};

struct boss_hexlord_addAI : public ScriptedAI
{
    InstanceScript* instance;

    boss_hexlord_addAI(Creature* creature) : ScriptedAI(creature)
    {
        instance = creature->GetInstanceScript();
    }

    void Reset() override { }

    void EnterCombat(Unit* /*who*/) override
    {
        DoZoneInCombat();
    }

    void UpdateAI(uint32 /*diff*/) override
    {
        if (instance->GetData(DATA_HEXLORDEVENT) != IN_PROGRESS)
        {
            EnterEvadeMode();
            return;
        }

        DoMeleeAttackIfReady();
    }
};

class boss_hexlord_malacrass : public CreatureScript
{
    public:

        boss_hexlord_malacrass()
            : CreatureScript("boss_hexlord_malacrass")
        {
        }

        struct boss_hex_lord_malacrassAI : public ScriptedAI
        {
            boss_hex_lord_malacrassAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
                SelectAddEntry();
                for (uint8 i = 0; i < 4; ++i)
                    AddGUID[i] = 0;
            }

            InstanceScript* instance;

            uint64 AddGUID[4];
            uint32 AddEntry[4];

            uint64 PlayerGUID;

            uint32 SpiritBolts_Timer;
            uint32 DrainPower_Timer;
            uint32 SiphonSoul_Timer;
            uint32 PlayerAbility_Timer;
            uint32 CheckAddState_Timer;
            uint32 ResetTimer;

            uint32 PlayerClass;

            void Reset() override
            {
                instance->SetData(DATA_HEXLORDEVENT, NOT_STARTED);

                SpiritBolts_Timer = 20000;
                DrainPower_Timer = 60000;
                SiphonSoul_Timer = 100000;
                PlayerAbility_Timer = 99999;
                CheckAddState_Timer = 5000;
                ResetTimer = 5000;

                SpawnAdds();

                me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID, 46916);
                me->SetByteValue(UNIT_FIELD_BYTES_2, 0, SHEATH_STATE_MELEE);
            }

            void EnterCombat(Unit* /*who*/) override
            {
                instance->SetData(DATA_HEXLORDEVENT, IN_PROGRESS);

                DoZoneInCombat();
                me->MonsterYell(YELL_AGGRO, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(me, SOUND_YELL_AGGRO);

                for (uint8 i = 0; i < 4; ++i)
                {
                    Creature* creature = Unit::GetCreature(*me, AddGUID[i]);
                    if (creature && creature->IsAlive())
                        creature->AI()->AttackStart(me->GetVictim());
                    else
                    {
                        EnterEvadeMode();
                        break;
                    }
                }
            }

            void KilledUnit(Unit* /*victim*/) override
            {
                switch (urand(0, 1))
                {
                    case 0:
                        me->MonsterYell(YELL_KILL_ONE, LANG_UNIVERSAL, NULL);
                        DoPlaySoundToSet(me, SOUND_YELL_KILL_ONE);
                        break;
                    case 1:
                        me->MonsterYell(YELL_KILL_TWO, LANG_UNIVERSAL, NULL);
                        DoPlaySoundToSet(me, SOUND_YELL_KILL_TWO);
                        break;
                }
            }

            void JustDied(Unit* /*killer*/) override
            {
                instance->SetData(DATA_HEXLORDEVENT, DONE);

                me->MonsterYell(YELL_DEATH, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(me, SOUND_YELL_DEATH);

                for (uint8 i = 0; i < 4; ++i)
                {
                    Unit* Temp = Unit::GetUnit(*me, AddGUID[i]);
                    if (Temp && Temp->IsAlive())
                        Temp->DealDamage(Temp, Temp->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                }
            }

            void SelectAddEntry()
            {
                std::vector<uint32> AddList;

                for (uint8 i = 0; i < 8; ++i)
                    AddList.push_back(AddEntryList[i]);

                while (AddList.size() > 4)
                    AddList.erase(AddList.begin()+rand()%AddList.size());

                uint8 i = 0;
                for (std::vector<uint32>::const_iterator itr = AddList.begin(); itr != AddList.end(); ++itr, ++i)
                    AddEntry[i] = *itr;
            }

            void SpawnAdds()
            {
                for (uint8 i = 0; i < 4; ++i)
                {
                    Creature* creature = (Unit::GetCreature((*me), AddGUID[i]));
                    if (!creature || !creature->IsAlive())
                    {
                        if (creature) creature->setDeathState(DEAD);
                        creature = me->SummonCreature(AddEntry[i], Pos_X[i], POS_Y, POS_Z, ORIENT, TEMPSUMMON_DEAD_DESPAWN, 0);
                        if (creature) AddGUID[i] = creature->GetGUID();
                    }
                    else
                    {
                        creature->AI()->EnterEvadeMode();
                        creature->SetPosition(Pos_X[i], POS_Y, POS_Z, ORIENT);
                        creature->StopMoving();
                    }
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (ResetTimer <= diff)
                {
                    if (me->IsWithinDist3d(119.223f, 1035.45f, 29.4481f, 10))
                    {
                        EnterEvadeMode();
                        return;
                    }
                    ResetTimer = 5000;
                } else ResetTimer -= diff;

                if (CheckAddState_Timer <= diff)
                {
                    for (uint8 i = 0; i < 4; ++i)
                        if (Creature* temp = Unit::GetCreature(*me, AddGUID[i]))
                            if (temp->IsAlive() && !temp->GetVictim())
                                temp->AI()->AttackStart(me->GetVictim());

                    CheckAddState_Timer = 5000;
                } else CheckAddState_Timer -= diff;

                if (DrainPower_Timer <= diff)
                {
                    DoCast(me, SPELL_DRAIN_POWER, true);
                    me->MonsterYell(YELL_DRAIN_POWER, LANG_UNIVERSAL, NULL);
                    DoPlaySoundToSet(me, SOUND_YELL_DRAIN_POWER);
                    DrainPower_Timer = urand(40000, 55000);    // must cast in 60 sec, or buff/debuff will disappear
                } else DrainPower_Timer -= diff;

                if (SpiritBolts_Timer <= diff)
                {
                    if (DrainPower_Timer < 12000)    // channel 10 sec
                        SpiritBolts_Timer = 13000;   // cast drain power first
                    else
                    {
                        DoCast(me, SPELL_SPIRIT_BOLTS, false);
                        me->MonsterYell(YELL_SPIRIT_BOLTS, LANG_UNIVERSAL, NULL);
                        DoPlaySoundToSet(me, SOUND_YELL_SPIRIT_BOLTS);
                        SpiritBolts_Timer = 40000;
                        SiphonSoul_Timer = 10000;    // ready to drain
                        PlayerAbility_Timer = 99999;
                    }
                } else SpiritBolts_Timer -= diff;

                if (SiphonSoul_Timer <= diff)
                {
                    Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 70, true);
                    Unit* trigger = DoSpawnCreature(NPC_TEMP_TRIGGER, 0, 0, 0, 0, TEMPSUMMON_TIMED_DESPAWN, 30000);
                    if (!target || !trigger)
                    {
                        EnterEvadeMode();
                        return;
                    }
                    else
                    {
                        trigger->SetDisplayId(11686);
                        trigger->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        trigger->CastSpell(target, SPELL_SIPHON_SOUL, true);
                        trigger->GetMotionMaster()->MoveChase(me);

                        //DoCast(target, SPELL_SIPHON_SOUL, true);
                        //me->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, target->GetGUID());
                        //me->SetUInt32Value(UNIT_CHANNEL_SPELL, SPELL_SIPHON_SOUL);

                        PlayerGUID = target->GetGUID();
                        PlayerAbility_Timer = urand(8000, 10000);
                        PlayerClass = target->getClass() - 1;

                        if (PlayerClass == CLASS_DRUID-1)
                            PlayerClass = CLASS_DRUID;
                        else if (PlayerClass == CLASS_PRIEST-1 && target->HasSpell(15473))
                            PlayerClass = CLASS_PRIEST; // shadow priest

                        SiphonSoul_Timer = 99999;   // buff lasts 30 sec
                    }
                } else SiphonSoul_Timer -= diff;

                if (PlayerAbility_Timer <= diff)
                {
                    //Unit* target = Unit::GetUnit(*me, PlayerGUID);
                    //if (target && target->IsAlive())
                    //{
                        UseAbility();
                        PlayerAbility_Timer = urand(8000, 10000);
                    //}
                } else PlayerAbility_Timer -= diff;

                DoMeleeAttackIfReady();
            }

            void UseAbility()
            {
                uint8 random = urand(0, 2);
                Unit* target = NULL;
                switch (PlayerAbility[PlayerClass][random].target)
                {
                    case ABILITY_TARGET_SELF:
                        target = me;
                        break;
                    case ABILITY_TARGET_VICTIM:
                        target = me->GetVictim();
                        break;
                    case ABILITY_TARGET_ENEMY:
                    default:
                        target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true);
                        break;
                    case ABILITY_TARGET_HEAL:
                        target = DoSelectLowestHpFriendly(50, 0);
                        break;
                    case ABILITY_TARGET_BUFF:
                        {
                            std::list<Creature*> templist = DoFindFriendlyMissingBuff(50, PlayerAbility[PlayerClass][random].spell);
                            if (!templist.empty())
                                target = *(templist.begin());
                        }
                        break;
                }
                if (target)
                    DoCast(target, PlayerAbility[PlayerClass][random].spell, false);
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetInstanceAI<boss_hex_lord_malacrassAI>(creature);
        }
};

class boss_thurg : public CreatureScript
{
    public:

        boss_thurg()
            : CreatureScript("boss_thurg")
        {
        }

        struct boss_thurgAI : public boss_hexlord_addAI
        {

            boss_thurgAI(Creature* creature) : boss_hexlord_addAI(creature) { }

            uint32 bloodlust_timer;
            uint32 cleave_timer;

            void Reset() override
            {
                bloodlust_timer = 15000;
                cleave_timer = 10000;

                boss_hexlord_addAI::Reset();
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (bloodlust_timer <= diff)
                {
                    std::list<Creature*> templist = DoFindFriendlyMissingBuff(50, SPELL_BLOODLUST);
                    if (!templist.empty())
                    {
                        if (Unit* target = *(templist.begin()))
                            DoCast(target, SPELL_BLOODLUST, false);
                    }
                    bloodlust_timer = 12000;
                } else bloodlust_timer -= diff;

                if (cleave_timer <= diff)
                {
                    DoCastVictim(SPELL_CLEAVE, false);
                    cleave_timer = 12000; //3 sec cast
                } else cleave_timer -= diff;

                boss_hexlord_addAI::UpdateAI(diff);
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetInstanceAI<boss_thurgAI>(creature);
        }
};

class boss_alyson_antille : public CreatureScript
{
    public:

        boss_alyson_antille()
            : CreatureScript("boss_alyson_antille")
        {
        }

        struct boss_alyson_antilleAI : public boss_hexlord_addAI
        {
            //Holy Priest
            boss_alyson_antilleAI(Creature* creature) : boss_hexlord_addAI(creature) { }

            uint32 flashheal_timer;
            uint32 dispelmagic_timer;

            void Reset() override
            {
                flashheal_timer = 2500;
                dispelmagic_timer = 10000;

                //AcquireGUID();

                boss_hexlord_addAI::Reset();
            }

            void AttackStart(Unit* who) override
            {
                if (!who)
                    return;

                if (who->isTargetableForAttack())
                {
                    if (me->Attack(who, false))
                    {
                        me->GetMotionMaster()->MoveChase(who, 20);
                        me->AddThreat(who, 0.0f);
                    }
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (flashheal_timer <= diff)
                {
                    Unit* target = DoSelectLowestHpFriendly(99, 30000);
                    if (target)
                    {
                        if (target->IsWithinDistInMap(me, 50))
                            DoCast(target, SPELL_FLASH_HEAL, false);
                        else
                        {
                            // bugged
                            //me->GetMotionMaster()->Clear();
                            //me->GetMotionMaster()->MoveChase(target, 20);
                        }
                    }
                    else
                    {
                        if (urand(0, 1))
                            target = DoSelectLowestHpFriendly(50, 0);
                        else
                            target = SelectTarget(SELECT_TARGET_RANDOM, 0);
                        if (target)
                            DoCast(target, SPELL_DISPEL_MAGIC, false);
                    }
                    flashheal_timer = 2500;
                } else flashheal_timer -= diff;

                /*if (dispelmagic_timer <= diff)
                {
                if (urand(0, 1))
                {
                    Unit* target = SelectTarget();

                    DoCast(target, SPELL_DISPEL_MAGIC, false);
                }
                else
                    me->CastSpell(SelectUnit(SELECT_TARGET_RANDOM, 0), SPELL_DISPEL_MAGIC, false);

                dispelmagic_timer = 12000;
                } else dispelmagic_timer -= diff;*/

                boss_hexlord_addAI::UpdateAI(diff);
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetInstanceAI<boss_alyson_antilleAI>(creature);
        }
};

struct boss_gazakrothAI : public boss_hexlord_addAI
{
    boss_gazakrothAI(Creature* creature) : boss_hexlord_addAI(creature)  { }

    uint32 firebolt_timer;

    void Reset() override
    {
        firebolt_timer = 2000;
        boss_hexlord_addAI::Reset();
    }

    void AttackStart(Unit* who) override
    {
        if (!who)
            return;

        if (who->isTargetableForAttack())
        {
            if (me->Attack(who, false))
            {
                me->GetMotionMaster()->MoveChase(who, 20);
                me->AddThreat(who, 0.0f);
            }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        if (firebolt_timer <= diff)
        {
            DoCastVictim(SPELL_FIREBOLT, false);
            firebolt_timer = 700;
        } else firebolt_timer -= diff;

        boss_hexlord_addAI::UpdateAI(diff);
    }
};

class boss_lord_raadan : public CreatureScript
{
    public:

        boss_lord_raadan()
            : CreatureScript("boss_lord_raadan")
        {
        }

        struct boss_lord_raadanAI : public boss_hexlord_addAI
        {
            boss_lord_raadanAI(Creature* creature) : boss_hexlord_addAI(creature)  { }

            uint32 flamebreath_timer;
            uint32 thunderclap_timer;

            void Reset() override
            {
                flamebreath_timer = 8000;
                thunderclap_timer = 13000;

                boss_hexlord_addAI::Reset();

            }
            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (thunderclap_timer <= diff)
                {
                    DoCastVictim(SPELL_THUNDERCLAP, false);
                    thunderclap_timer = 12000;
                } else thunderclap_timer -= diff;

                if (flamebreath_timer <= diff)
                {
                    DoCastVictim(SPELL_FLAME_BREATH, false);
                    flamebreath_timer = 12000;
                } else flamebreath_timer -= diff;

                boss_hexlord_addAI::UpdateAI(diff);
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetInstanceAI<boss_lord_raadanAI>(creature);
        }
};

class boss_darkheart : public CreatureScript
{
    public:

        boss_darkheart()
            : CreatureScript("boss_darkheart")
        {
        }

        struct boss_darkheartAI : public boss_hexlord_addAI
        {
            boss_darkheartAI(Creature* creature) : boss_hexlord_addAI(creature)  { }

            uint32 psychicwail_timer;

            void Reset() override
            {
                psychicwail_timer = 8000;
                boss_hexlord_addAI::Reset();
            }
            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (psychicwail_timer <= diff)
                {
                    DoCastVictim(SPELL_PSYCHIC_WAIL, false);
                    psychicwail_timer = 12000;
                } else psychicwail_timer -= diff;

                boss_hexlord_addAI::UpdateAI(diff);
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetInstanceAI<boss_darkheartAI>(creature);
        }
};


class boss_slither : public CreatureScript
{
    public:

        boss_slither()
            : CreatureScript("boss_slither")
        {
        }

        struct boss_slitherAI : public boss_hexlord_addAI
        {
            boss_slitherAI(Creature* creature) : boss_hexlord_addAI(creature) { }

            uint32 venomspit_timer;

            void Reset() override
            {
                venomspit_timer = 5000;
                boss_hexlord_addAI::Reset();
            }

            void AttackStart(Unit* who) override
            {
                if (!who)
                    return;

                if (who->isTargetableForAttack())
                {
                    if (me->Attack(who, false))
                    {
                        me->GetMotionMaster()->MoveChase(who, 20);
                        me->AddThreat(who, 0.0f);
                    }
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (venomspit_timer <= diff)
                {
                    if (Unit* victim = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                        DoCast(victim, SPELL_VENOM_SPIT, false);
                    venomspit_timer = 2500;
                } else venomspit_timer -= diff;

                boss_hexlord_addAI::UpdateAI(diff);
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetInstanceAI<boss_slitherAI>(creature);
        }
};

class boss_fenstalker : public CreatureScript
{
    public:

        boss_fenstalker()
            : CreatureScript("boss_fenstalker")
        {
        }

        struct boss_fenstalkerAI : public boss_hexlord_addAI
        {
            boss_fenstalkerAI(Creature* creature) : boss_hexlord_addAI(creature) { }

            uint32 volatileinf_timer;

            void Reset() override
            {
                volatileinf_timer = 15000;
                boss_hexlord_addAI::Reset();

            }
            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (volatileinf_timer <= diff)
                {
                    // core bug
                    if (me->GetVictim())
                        me->EnsureVictim()->CastSpell(me->GetVictim(), SPELL_VOLATILE_INFECTION, false);
                    volatileinf_timer = 12000;
                } else volatileinf_timer -= diff;

                boss_hexlord_addAI::UpdateAI(diff);
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetInstanceAI<boss_fenstalkerAI>(creature);
        }
};

class boss_koragg : public CreatureScript
{
    public:

        boss_koragg()
            : CreatureScript("boss_koragg")
        {
        }

        struct boss_koraggAI : public boss_hexlord_addAI
        {
            boss_koraggAI(Creature* creature) : boss_hexlord_addAI(creature) { }

            uint32 coldstare_timer;
            uint32 mightyblow_timer;

            void Reset() override
            {
                coldstare_timer = 15000;
                mightyblow_timer = 10000;
                boss_hexlord_addAI::Reset();

            }
            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (mightyblow_timer <= diff)
                {
                    DoCastVictim(SPELL_MIGHTY_BLOW, false);
                    mightyblow_timer = 12000;
                }
                if (coldstare_timer <= diff)
                {
                    if (Unit* victim = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                        DoCast(victim, SPELL_COLD_STARE, false);
                    coldstare_timer = 12000;
                }

                boss_hexlord_addAI::UpdateAI(diff);
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetInstanceAI<boss_koraggAI>(creature);
        }
};

class spell_hexlord_unstable_affliction : public SpellScriptLoader
{
    public:
        spell_hexlord_unstable_affliction() : SpellScriptLoader("spell_hexlord_unstable_affliction") { }

        class spell_hexlord_unstable_affliction_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_hexlord_unstable_affliction_AuraScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_WL_UNSTABLE_AFFL_DISPEL))
                    return false;
                return true;
            }

            void HandleDispel(DispelInfo* dispelInfo)
            {
                if (Unit* caster = GetCaster())
                    caster->CastSpell(dispelInfo->GetDispeller(), SPELL_WL_UNSTABLE_AFFL_DISPEL, true, NULL, GetEffect(EFFECT_0));
            }

            void Register() override
            {
                AfterDispel += AuraDispelFn(spell_hexlord_unstable_affliction_AuraScript::HandleDispel);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_hexlord_unstable_affliction_AuraScript();
        }
};

void AddSC_boss_hex_lord_malacrass()
{
    new boss_hexlord_malacrass();
    new boss_thurg();
    // new boss_gazakroth();
    new boss_lord_raadan();
    new boss_darkheart();
    new boss_slither();
    new boss_fenstalker();
    new boss_koragg();
    new boss_alyson_antille();
    new spell_hexlord_unstable_affliction();
}

