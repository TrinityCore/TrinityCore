/*
 * This file is part of the CMaNGOS Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef _SPELL_CLASS_MASK_H
#define _SPELL_CLASS_MASK_H

enum ClassFlag
{
    // -- Mage (3)
    CF_MAGE_FIREBALL                        = 0,    // CM0 00000001
    CF_MAGE_FIRE_BLAST                      = 1,    // CM0 00000002
    CF_MAGE_FLAMESTRIKE                     = 2,    // CM0 00000004
    CF_MAGE_FIRE_WARD                       = 3,    // CM0 00000008
    CF_MAGE_SCORCH                          = 4,    // CM0 00000010
    CF_MAGE_FROSTBOLT                       = 5,    // CM0 00000020
    CF_MAGE_FROST_NOVA                      = 6,    // CM0 00000040
    CF_MAGE_BLIZZARD                        = 7,    // CM0 00000080
    CF_MAGE_FROST_WARD                      = 8,    // CM0 00000100
    CF_MAGE_CONE_OF_COLD                    = 9,    // CM0 00000200
    CF_MAGE_ARCANE_INT                      = 10,   // CM0 00000400 Arcane Intellect & Arcane Brilliance
    CF_MAGE_ARCANE_MISSILES_CHANNEL         = 11,   // CM0 00000800
    CF_MAGE_ARCANE_EXPLOSION                = 12,   // CM0 00001000
    CF_MAGE_D_A_MAGIC                       = 13,   // CM0 00002000 Dampen Magic & Amplify Magic
    CF_MAGE_COUNTERSPELL                    = 14,   // CM0 00004000
    CF_MAGE_MANA_SHIELD                     = 15,   // CM0 00008000
    CF_MAGE_BLINK                           = 16,   // CM0 00010000
    CF_MAGE_BLAST_WAVE1                     = 17,   // CM0 00020000
    CF_MAGE_UNK18                           = 18,   // CM0 00040000 Sleep, Polymorph, Counterspell, Arcane Missiles, Arcane Explosion
    CF_MAGE_MISC_FROST                      = 19,   // CM0 00080000 Frost spells
    CF_MAGE_CHILLED                         = 20,   // CM0 00100000 Frost spells with SPELL_AURA_MOD_DECREASE_SPEED
    CF_MAGE_ARCANE_MISSILES                 = 21,   // CM0 00200000
    CF_MAGE_PYROBLAST                       = 22,   // CM0 00400000
    CF_MAGE_BLAST_WAVE2                     = 23,   // CM0 00800000
    CF_MAGE_POLYMORPH                       = 24,   // CM0 01000000
    CF_MAGE_ELEMENTAL_ARMOR                 = 25,   // CM0 02000000 Frost Armor & Ice Armor
    CF_MAGE_EVOCATION                       = 26,   // CM0 04000000
    CF_MAGE_IGNITE                          = 27,   // CM0 08000000
    CF_MAGE_MAGE_ARMOR                      = 28,   // CM0 10000000
    CF_MAGE_UNK29                           = 29,   // CM0 20000000
    CF_MAGE_CONJURE                         = 30,   // CM0 40000000
    CF_MAGE_PORTALS                         = 31,   // CM0 80000000

    // -- Warrior (4)
    CF_WARRIOR_CHARGE                       = 0,    // CM0 00000001
    CF_WARRIOR_HAMSTRING                    = 1,    // CM0 00000002
    CF_WARRIOR_OVERPOWER                    = 2,    // CM0 00000004
    CF_WARRIOR_PUMMEL                       = 3,    // CM0 00000008
    CF_WARRIOR_RECKLESSNESS                 = 4,    // CM0 00000010
    CF_WARRIOR_REND                         = 5,    // CM0 00000020
    CF_WARRIOR_HEROIC_STRIKE                = 6,    // CM0 00000040
    CF_WARRIOR_THUNDER_CLAP                 = 7,    // CM0 00000080
    CF_WARRIOR_BLOODRAGE                    = 8,    // CM0 00000100
    CF_WARRIOR_DISARM                       = 9,    // CM0 00000200
    CF_WARRIOR_REVENGE                      = 10,   // CM0 00000400
    CF_WARRIOR_SHIELD_BASH                  = 11,   // CM0 00000800
    CF_WARRIOR_SHIELD_BLOCK                 = 12,   // CM0 00001000
    CF_WARRIOR_SHIELD_WALL                  = 13,   // CM0 00002000
    CF_WARRIOR_SUNDER_ARMOR                 = 14,   // CM0 00004000
    CF_WARRIOR_TAUNT                        = 15,   // CM0 00008000
    CF_WARRIOR_BATTLE_SHOUT                 = 16,   // CM0 00010000
    CF_WARRIOR_DEMORALIZING_SHOUT           = 17,   // CM0 00020000
    CF_WARRIOR_INTIMIDATING_SHOUT           = 18,   // CM0 00040000
    CF_WARRIOR_CHALLENGING_SHOUT            = 19,   // CM0 00080000
    CF_WARRIOR_INNER_RAGE                   = 20,   // CM0 00100000
    CF_WARRIOR_SLAM                         = 21,   // CM0 00200000
    CF_WARRIOR_CLEAVE                       = 22,   // CM0 00400000
    CF_WARRIOR_STANCES                      = 23,   // CM0 00800000
    CF_WARRIOR_CHARGE_STUN                  = 24,   // CM0 01000000
    CF_WARRIOR_MORTAL_STRIKE                = 25,   // CM0 02000000
    CF_WARRIOR_CONCUSSION_BLOW              = 26,   // CM0 04000000
    CF_WARRIOR_MOCKING_BLOW                 = 27,   // CM0 08000000
    CF_WARRIOR_BERSERKER_RAGE               = 28,   // CM0 10000000
    CF_WARRIOR_EXECUTE                      = 29,   // CM0 20000000
    CF_WARRIOR_INTERCEPT                    = 30,   // CM0 40000000
    CF_WARRIOR_RETALIATION                  = 31,   // CM0 80000000

    CF_WARRIOR_SHIELD_SLAM                  = 32,   // CM1 00000001

    // -- Warlock (5)
    CF_WARLOCK_SHADOW_BOLT                  = 0,    // CM0 00000001
    CF_WARLOCK_CORRUPTION                   = 1,    // CM0 00000002
    CF_WARLOCK_IMMOLATE                     = 2,    // CM0 00000004
    CF_WARLOCK_DRAIN_LIFE                   = 3,    // CM0 00000008
    CF_WARLOCK_DRAIN_MANA                   = 4,    // CM0 00000010
    CF_WARLOCK_RAIN_OF_FIRE                 = 5,    // CM0 00000020
    CF_WARLOCK_HELLFIRE                     = 6,    // CM0 00000040
    CF_WARLOCK_SHADOWBURN                   = 7,    // CM0 00000080
    CF_WARLOCK_SEARING_PAIN                 = 8,    // CM0 00000100
    CF_WARLOCK_CONFLAGRATE                  = 9,    // CM0 00000200
    CF_WARLOCK_CURSE_OF_AGONY               = 10,   // CM0 00000400
    CF_WARLOCK_ENSLAVE_DEMON                = 11,   // CM0 00000800
    CF_WARLOCK_IMP_FIREBOLT                 = 12,   // CM0 00001000
    CF_WARLOCK_SUCCUBUS_LASH_OF_PAIN        = 13,   // CM0 00002000
    CF_WARLOCK_DRAIN_SOUL                   = 14,   // CM0 00004000
    CF_WARLOCK_CURSE_OF_WEAKNESS            = 15,   // CM0 00008000
    CF_WARLOCK_HEALTHSTONE                  = 16,   // CM0 00010000
    CF_WARLOCK_SPELLSTONE                   = 17,   // CM0 00020000
    CF_WARLOCK_LIFE_TAP                     = 18,   // CM0 00040000
    CF_WARLOCK_DEATH_COIL                   = 19,   // CM0 00080000
    CF_WARLOCK_CREATE_STONES                = 20,   // CM0 00100000
    CF_WARLOCK_FIRESTONE_ATTACK             = 21,   // CM0 00200000
    CF_WARLOCK_CURSE_OF_EXHAUSTION          = 22,   // CM0 00400000
    CF_WARLOCK_IMP_BUFFS                    = 23,   // CM0 00800000
    CF_WARLOCK_HEALTH_FUNNEL                = 24,   // CM0 01000000
    CF_WARLOCK_VOIDWALKER_SPELLS            = 25,   // CM0 02000000
    CF_WARLOCK_TAMED_PET_PASSIVE_DAMAGE     = 26,   // CM0 04000000
    CF_WARLOCK_TAMED_PET_PASSIVE_HEALTH     = 27,   // CM0 08000000
    CF_WARLOCK_TAMED_PET_PASSIVE_ENERGY     = 28,   // CM0 10000000
    CF_WARLOCK_SUMMON_SPELLS                = 29,   // CM0 20000000
    CF_WARLOCK_SUCCUBUS_SPELLS              = 30,   // CM0 40000000
    CF_WARLOCK_MISC_DEBUFFS                 = 31,   // CM0 80000000

    CF_WARLOCK_SIPHON_LIFE                  = 32,   // CM1 00000001
    CF_WARLOCK_CURSE_OF_DOOM                = 33,   // CM1 00000002

    // -- Priest (6)
    CF_PRIEST_POWER_WORD_SHIELD             = 0,    // CM0 00000001
    CF_PRIEST_INNER_FIRE                    = 1,    // CM0 00000002
    CF_PRIEST_VAMPIRIC_EMBRACE              = 2,    // CM0 00000004
    CF_PRIEST_POWER_WORD_FORTITUDE          = 3,    // CM0 00000008
    CF_PRIEST_MANA_BURN                     = 4,    // CM0 00000010
    CF_PRIEST_TEST_NPC_RESURRECTION         = 5,    // CM0 00000020
    CF_PRIEST_RENEW                         = 6,    // CM0 00000040
    CF_PRIEST_SMITE                         = 7,    // CM0 00000080
    CF_PRIEST_SHADOW_PROTECTION             = 8,    // CM0 00000100
    CF_PRIEST_PRAYER_OF_HEALING             = 9,    // CM0 00000200
    CF_PRIEST_HEAL                          = 10,   // CM0 00000400
    CF_PRIEST_FLASH_HEAL                    = 11,   // CM0 00000800
    CF_PRIEST_GREATER_HEAL                  = 12,   // CM0 00001000
    CF_PRIEST_MIND_BLAST                    = 13,   // CM0 00002000
    CF_PRIEST_FADE                          = 14,   // CM0 00004000
    CF_PRIEST_SHADOW_WORD_PAIN              = 15,   // CM0 00008000
    CF_PRIEST_PSYCHIC_SCREAM                = 16,   // CM0 00010000
    CF_PRIEST_MIND_CONTROL                  = 17,   // CM0 00020000
    CF_PRIEST_LESSER_HEAL                   = 18,   // CM0 00040000
    CF_PRIEST_TOUCH_OF_WEAKNESS             = 19,   // CM0 00080000
    CF_PRIEST_HOLY_FIRE                     = 20,   // CM0 00100000
    CF_PRIEST_STARSHARDS                    = 21,   // CM0 00200000
    CF_PRIEST_HOLY_NOVA1                    = 22,   // CM0 00400000
    CF_PRIEST_MIND_FLAY                     = 23,   // CM0 00800000
    CF_PRIEST_DESPERATE_PRAYER              = 24,   // CM0 01000000
    CF_PRIEST_DEVOURING_PLAGUE              = 25,   // CM0 02000000
    CF_PRIEST_MIND_VISION                   = 26,   // CM0 04000000
    CF_PRIEST_HOLY_NOVA2                    = 27,   // CM0 08000000
    CF_PRIEST_FLASH_HEAL2                   = 28,   // CM0 10000000
    CF_PRIEST_WEAKENED_SOUL                 = 29,   // CM0 20000000
    CF_PRIEST_MISC1                         = 30,   // CM0 40000000 Ressurection, Shackle Undead, Lightwell
    CF_PRIEST_MISC2                         = 31,   // CM0 80000000

    CF_PRIEST_DISPELLS                       = 32,   // CM1 00000001

    // -- Druid (7)
    CF_DRUID_WRATH                          = 0,    // CM0 00000001
    CF_DRUID_MOONFIRE                       = 1,    // CM0 00000002
    CF_DRUID_STARFIRE                       = 2,    // CM0 00000004
    CF_DRUID_DEMORALIZING_ROAR              = 3,    // CM0 00000008
    CF_DRUID_REJUVENATION                   = 4,    // CM0 00000010
    CF_DRUID_HEALING_TOUCH                  = 5,    // CM0 00000020
    CF_DRUID_REGROWTH                       = 6,    // CM0 00000040
    CF_DRUID_TRANQUILITY                    = 7,    // CM0 00000080
    CF_DRUID_THORNS                         = 8,    // CM0 00000100
    CF_DRUID_ENTANGLING_ROOTS               = 9,    // CM0 00000200
    CF_DRUID_FAERIE_FIRE                    = 10,   // CM0 00000400
    CF_DRUID_MAUL_SWIPE                     = 11,   // CM0 00000800
    CF_DRUID_RAKE_CLAW                      = 12,   // CM0 00001000
    CF_DRUID_BASH                           = 13,   // CM0 00002000
    CF_DRUID_PROWL                          = 14,   // CM0 00004000
    CF_DRUID_SHRED                          = 15,   // CM0 00008000
    CF_DRUID_RAVAGE                         = 16,   // CM0 00010000
    CF_DRUID_POUNCE                         = 17,   // CM0 00020000
    CF_DRUID_MARK_OF_THE_WILD               = 18,   // CM0 00040000
    CF_DRUID_ENRAGE                         = 19,   // CM0 00080000
    CF_DRUID_NATURES_GRASP                  = 20,   // CM0 00100000
    CF_DRUID_INSECT_SWARM                   = 21,   // CM0 00200000
    CF_DRUID_HURRICANE                      = 22,   // CM0 00400000
    CF_DRUID_RIP_BITE                       = 23,   // CM0 00800000 Rip & Ferocious Bite
    CF_DRUID_SOOTHE_HIBERNATE               = 24,   // CM0 01000000 Soothe Animal & Hibernate
    CF_DRUID_TREE_FORM                      = 25,   // CM0 02000000
    CF_DRUID_SHAPESHIFT_FORM_EFFECT         = 26,   // CM0 04000000
    CF_DRUID_CAT_FORM_PASSIVE               = 27,   // CM0 08000000
    CF_DRUID_REBIRTH                        = 28,   // CM0 10000000
    CF_DRUID_MISC_FORMS                     = 29,   // CM0 20000000 Aquatic Form, Travel Form, Moonkin Form, Faerie Dragon Form
    CF_DRUID_BEAR_FORM                      = 30,   // CM0 40000000
    CF_DRUID_CAT_FORM                       = 31,   // CM0 80000000

    CF_DRUID_FERAL_CHARGE                   = 32,   // CM1 00000001
    CF_DRUID_SWIFTMEND                      = 33,   // CM1 00000002
    CF_DRUID_DISPELLS                       = 34,   // CM1 00000004
    CF_DRUID_GROWL                          = 35,   // CM1 00000008

    // -- Rogue (8)
    CF_ROGUE_THROW                          = 0,    // CM0 00000001
    CF_ROGUE_SINISTER_STRIKE                = 1,    // CM0 00000002
    CF_ROGUE_BACKSTAB                       = 2,    // CM0 00000004
    CF_ROGUE_GOUGE                          = 3,    // CM0 00000008
    CF_ROGUE_KICK                           = 4,    // CM0 00000010
    CF_ROGUE_EVASION                        = 5,    // CM0 00000020
    CF_ROGUE_SPRINT                         = 6,    // CM0 00000040
    CF_ROGUE_SAP                            = 7,    // CM0 00000080
    CF_ROGUE_GARROTE                        = 8,    // CM0 00000100
    CF_ROGUE_AMBUSH                         = 9,    // CM0 00000200
    CF_ROGUE_CHEAP_SHOT                     = 10,   // CM0 00000400
    CF_ROGUE_VANISH                         = 11,   // CM0 00000800
    CF_ROGUE_DISTRACT                       = 12,   // CM0 00001000
    CF_ROGUE_INSTANT_POISON                 = 13,   // CM0 00002000
    CF_ROGUE_CRIPPLING_POISON               = 14,   // CM0 00004000
    CF_ROGUE_MIND_NUMBING_POISON            = 15,   // CM0 00008000
    CF_ROGUE_DEADLY_POISON                  = 16,   // CM0 00010000
    CF_ROGUE_EVISCERATE                     = 17,   // CM0 00020000
    CF_ROGUE_SLICE_AND_DICE                 = 18,   // CM0 00040000
    CF_ROGUE_EXPOSE_ARMOR                   = 19,   // CM0 00080000
    CF_ROGUE_RUPTURE                        = 20,   // CM0 00100000
    CF_ROGUE_KIDNEY_SHOT                    = 21,   // CM0 00200000
    CF_ROGUE_STEALTH                        = 22,   // CM0 00400000
    CF_ROGUE_MISC_COMBO_MOVES               = 23,   // CM0 00800000
    CF_ROGUE_BLIND                          = 24,   // CM0 01000000
    CF_ROGUE_HEMORRHAGE                     = 25,   // CM0 02000000
    CF_ROGUE_GHOSTLY_STRIKE                 = 26,   // CM0 04000000
    CF_ROGUE_FEINT                          = 27,   // CM0 08000000
    CF_ROGUE_WOUND_POISON                   = 28,   // CM0 10000000
    CF_ROGUE_UNK29                          = 29,   // CM0 20000000
    CF_ROGUE_MISC1                          = 30,   // CM0 40000000 Blade Furry, Cold Blood, Ghostly Strike, Premeditation, Revealed Flaw
    CF_ROGUE_MISC2                          = 31,   // CM0 80000000 Riposte, Pick Pocket, Disarm Trap, Blind

    // -- Hunter (9)
    CF_HUNTER_SHOOT                         = 0,    // CM0 00000001
    CF_HUNTER_MONGOOSE_RAPTOR               = 1,    // CM0 00000002 Mongoose Bite & Raptor Strike
    CF_HUNTER_FIRE_TRAP_EFFECTS             = 2,    // CM0 00000004 Immolation/Explosive Trap effects
    CF_HUNTER_FREEZING_TRAP_EFFECT          = 3,    // CM0 00000008
    CF_HUNTER_FROST_TRAP_AURA               = 4,    // CM0 00000010
    CF_HUNTER_RAPID_FIRE                    = 5,    // CM0 00000020
    CF_HUNTER_WING_CLIP                     = 6,    // CM0 00000040
    CF_HUNTER_TRAPS                         = 7,    // CM0 00000080
    CF_HUNTER_FEIGN_DEATH                   = 8,    // CM0 00000100
    CF_HUNTER_CONCUSSIVE_SHOT               = 9,    // CM0 00000200
    CF_HUNTER_HUNTERS_MARK                  = 10,   // CM0 00000400
    CF_HUNTER_ARCANE_SHOT                   = 11,   // CM0 00000800
    CF_HUNTER_MULTI_SHOT                    = 12,   // CM0 00001000
    CF_HUNTER_VOLLEY                        = 13,   // CM0 00002000
    CF_HUNTER_SERPENT_STING                 = 14,   // CM0 00004000
    CF_HUNTER_SCORPID_STING                 = 15,   // CM0 00008000
    CF_HUNTER_MISC                          = 16,   // CM0 00010000 Viper Sting, Wyvern Sting, Distracting Shot
    CF_HUNTER_AIMED_SHOT                    = 17,   // CM0 00020000
    CF_HUNTER_SCATTER_SHOT                  = 18,   // CM0 00040000
    CF_HUNTER_ASPECT_OF_THE_MONKEY          = 19,   // CM0 00080000
    CF_HUNTER_ASPECT_OF_THE_HAWK            = 20,   // CM0 00100000
    CF_HUNTER_ASPECT_OF_THE_CHEETAH         = 21,   // CM0 00200000 Aspect of the Cheetah & Aspect of the Pack
    CF_HUNTER_EYES_OF_THE_BEAST             = 22,   // CM0 00400000
    CF_HUNTER_MEND_PET                      = 23,   // CM0 00800000
    CF_HUNTER_REVIVE_PET                    = 24,   // CM0 01000000
    CF_HUNTER_TAMED_PET_PASSIVE_DAMAGE      = 25,   // CM0 02000000
    CF_HUNTER_TAMED_PET_PASSIVE_ARMOR       = 26,   // CM0 04000000
    CF_HUNTER_TAMED_PET_PASSIVE_HEALTH      = 27,   // CM0 08000000
    CF_HUNTER_TAMED_PET_PASSIVE_SPEED       = 28,   // CM0 10000000
    CF_HUNTER_TAMED_PET_PASSIVE_FOCUS       = 29,   // CM0 20000000
    CF_HUNTER_TAMED_PET_PASSIVE_CRIT        = 30,   // CM0 40000000
    CF_HUNTER_TAMED_PET_PASSIVE_FRENZY      = 31,   // CM0 80000000

    // -- Paladin (10)
    CF_PALADIN_RIGHTEOUS_FURY               = 0,    // CM0 00000001
    CF_PALADIN_BLESSING_OF_MIGHT            = 1,    // CM0 00000002 Blessing of Might & Greater Blessing of Might
    CF_PALADIN_REPENTANCE                   = 2,    // CM0 00000004
    CF_PALADIN_RETRIBUTION_AURA             = 3,    // CM0 00000008
    CF_PALADIN_BLESSING_OF_FREEDOM          = 4,    // CM0 00000010
    CF_PALADIN_CONSECRATION                 = 5,    // CM0 00000020
    CF_PALADIN_DEVOTION_AURA                = 6,    // CM0 00000040
    CF_PALADIN_BLESSING_OF_PROTECTION       = 7,    // CM0 00000080
    CF_PALADIN_BLESSING_OF_SALVATION1       = 8,    // CM0 00000100
    CF_PALADIN_SEAL_OF_THE_CRUSADER         = 9,    // CM0 00000200
    CF_PALADIN_JUDGEMENT_OF_RIGHTEOUSNESS   = 10,   // CM0 00000400
    CF_PALADIN_HAMMER_OF_JUSTICE            = 11,   // CM0 00000800
    CF_PALADIN_CLEANSE                      = 12,   // CM0 00001000
    CF_PALADIN_FLASH_OF_LIGHT1              = 13,   // CM0 00002000
    CF_PALADIN_HOLY_LIGHT1                  = 14,   // CM0 00004000
    CF_PALADIN_LAY_ON_HANDS                 = 15,   // CM0 00008000
    CF_PALADIN_BLESSING_OF_WISDOM           = 16,   // CM0 00010000 Blessing of Wisdom & Greater Blessing of Wisdom
    CF_PALADIN_CONCENTRATION_AURA           = 17,   // CM0 00020000
    CF_PALADIN_SEAL_OF_WISDOM_LIGHT         = 18,   // CM0 00040000 Seal of Wisdom & Seal of Light
    CF_PALADIN_JUDGEMENT_OF_WISDOM_LIGHT    = 19,   // CM0 00080000 Judgement of Wisdom & Judgement of Light
    CF_PALADIN_JUDGEMENT_OF_JUSTICE         = 20,   // CM0 00100000
    CF_PALADIN_HOLY_SHOCK                   = 21,   // CM0 00200000
    CF_PALADIN_UNK22                        = 22,   // CM0 00400000
    CF_PALADIN_JUDGEMENT                    = 23,   // CM0 00800000
    CF_PALADIN_BLESSING_OF_KINGS            = 24,   // CM0 01000000 Blessing of Kings & Greater Blessing of Kings
    CF_PALADIN_SEAL_OF_COMMAND              = 25,   // CM0 02000000
    CF_PALADIN_AURAS                        = 26,   // CM0 04000000 Shadow/Fire/Frost Resistance Auras & Sanctity Aura
    CF_PALADIN_SEALS                        = 27,   // CM0 08000000
    CF_PALADIN_BLESSINGS                    = 28,   // CM0 10000000 Most of them aren't used anymore by players
    CF_PALADIN_JUDGEMENT_OF_THE_CRUSADER    = 29,   // CM0 20000000
    CF_PALADIN_FLASH_OF_LIGHT2              = 30,   // CM0 40000000
    CF_PALADIN_HOLY_LIGHT2                  = 31,   // CM0 80000000

    CF_PALADIN_UNK32                        = 32,   // CM1 00000001
    CF_PALADIN_PURIFY_CLEANSE               = 33,   // CM1 00000002 Purify & Cleanse
    CF_PALADIN_JUDGEMENT_OF_COMMAND         = 34,   // CM1 00000004

    // -- Shaman (11)
    CF_SHAMAN_LIGHTNING_BOLT                = 0,    // CM0 00000001
    CF_SHAMAN_CHAIN_LIGHTNING               = 1,    // CM0 00000002
    CF_SHAMAN_MAGMA_TOTEM_ATTACK            = 2,    // CM0 00000004
    CF_SHAMAN_STONECLAW_TOTEM               = 3,    // CM0 00000008
    CF_SHAMAN_SEARING_TOTEM                 = 4,    // CM0 00000010
    CF_SHAMAN_FIRE_NOVA                     = 5,    // CM0 00000020
    CF_SHAMAN_HEALING_WAVE                  = 6,    // CM0 00000040
    CF_SHAMAN_LESSER_HEALING_WAVE           = 7,    // CM0 00000080
    CF_SHAMAN_CHAIN_HEAL                    = 8,    // CM0 00000100
    CF_SHAMAN_REINCARNATION                 = 9,    // CM0 00000200
    CF_SHAMAN_LIGHTNING_SHIELD              = 10,   // CM0 00000400
    CF_SHAMAN_GHOSTWOLF                     = 11,   // CM0 00000800
    CF_SHAMAN_MAGMA_TOTEM                   = 12,   // CM0 00001000
    CF_SHAMAN_HEALING_STREAM                = 13,   // CM0 00002000
    CF_SHAMAN_MANA_SPRING                   = 14,   // CM0 00004000
    CF_SHAMAN_STONESKIN_WINDWALL            = 15,   // CM0 00008000 Stoneskin & Windwall
    CF_SHAMAN_STRENGTH_OF_EARTH             = 16,   // CM0 00010000
    CF_SHAMAN_GRACE_OF_AIR                  = 17,   // CM0 00020000
    CF_SHAMAN_UNK18                         = 18,   // CM0 00040000
    CF_SHAMAN_HEALING_MANA_TOTEM            = 19,   // CM0 00080000 Healing Stream Totem & Mana Spring Totem
    CF_SHAMAN_EARTH_SHOCK                   = 20,   // CM0 00100000
    CF_SHAMAN_FLAMETONGUE_WEAPON            = 21,   // CM0 00200000
    CF_SHAMAN_ROCKBITER_WEAPON              = 22,   // CM0 00400000
    CF_SHAMAN_WINDFURY_WEAPON               = 23,   // CM0 00800000
    CF_SHAMAN_FROSTBRAND_ATTACK             = 24,   // CM0 01000000
    CF_SHAMAN_FLAMETONGUE_ATTACK            = 25,   // CM0 02000000
    CF_SHAMAN_TOTEM_EFFECTS                 = 26,   // CM0 04000000
    CF_SHAMAN_UNK27                         = 27,   // CM0 08000000
    CF_SHAMAN_FLAME_SHOCK                   = 28,   // CM0 10000000
    CF_SHAMAN_TOTEMS                        = 29,   // CM0 20000000 Non-attacking totems
    CF_SHAMAN_FIRE_TOTEM_ATTACK             = 30,   // CM0 40000000
    CF_SHAMAN_FROST_SHOCK                   = 31,   // CM0 80000000

    CF_SHAMAN_EARTHBIND                     = 32,   // CM1 00000001
    CF_SHAMAN_WINDFURY_TOTEM                = 33,   // CM1 00000002
    CF_SHAMAN_FLAMETONGUE_TOTEM             = 34,   // CM1 00000004
    CF_SHAMAN_CURES                         = 35,   // CM1 00000008 Cure Poison & Cure Disease
};

#endif // _SPELL_CLASS_MASK_H
