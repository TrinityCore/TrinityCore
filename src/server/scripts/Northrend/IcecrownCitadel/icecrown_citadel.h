/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#ifndef ICECROWN_CITADEL_H_
#define ICECROWN_CITADEL_H_

#include "SpellScript.h"

#define ICCScriptName "instance_icecrown_citadel"

uint32 const EncounterCount = 12;
uint32 const WeeklyNPCs = 7;
uint32 const MaxHeroicAttempts = 50;
// Defined in boss_sindragosa.cpp
extern Position const SindragosaSpawnPos;

// Shared spells used by more than one script
enum SharedSpells
{
    SPELL_BERSERK               = 26662,
    SPELL_BERSERK2              = 47008,

    // Residue Rendezvous
    SPELL_ORANGE_BLIGHT_RESIDUE = 72144,
    SPELL_GREEN_BLIGHT_RESIDUE  = 72145,
};

enum TeleporterSpells
{
    LIGHT_S_HAMMER_TELEPORT         = 70781,
    ORATORY_OF_THE_DAMNED_TELEPORT  = 70856,
    RAMPART_OF_SKULLS_TELEPORT      = 70857,
    DEATHBRINGER_S_RISE_TELEPORT    = 70858,
    UPPER_SPIRE_TELEPORT            = 70859,
    FROZEN_THRONE_TELEPORT          = 70860,
    SINDRAGOSA_S_LAIR_TELEPORT      = 70861,
};

enum DataTypes
{
    // Encounter States/Boss GUIDs
    DATA_LORD_MARROWGAR             = 0,
    DATA_LADY_DEATHWHISPER          = 1,
    DATA_GUNSHIP_EVENT              = 2,
    DATA_DEATHBRINGER_SAURFANG      = 3,
    DATA_FESTERGUT                  = 4,
    DATA_ROTFACE                    = 5,
    DATA_PROFESSOR_PUTRICIDE        = 6,
    DATA_BLOOD_PRINCE_COUNCIL       = 7,
    DATA_BLOOD_QUEEN_LANA_THEL      = 8,
    DATA_VALITHRIA_DREAMWALKER      = 9,
    DATA_SINDRAGOSA                 = 10,
    DATA_THE_LICH_KING              = 11,

    // Additional data
    DATA_SAURFANG_EVENT_NPC         = 12,
    DATA_BONED_ACHIEVEMENT          = 13,
    DATA_OOZE_DANCE_ACHIEVEMENT     = 14,
    DATA_PUTRICIDE_TABLE            = 15,
    DATA_NAUSEA_ACHIEVEMENT         = 16,
    DATA_ORB_WHISPERER_ACHIEVEMENT  = 17,
    DATA_PRINCE_KELESETH_GUID       = 18,
    DATA_PRINCE_TALDARAM_GUID       = 19,
    DATA_PRINCE_VALANAR_GUID        = 20,
    DATA_BLOOD_PRINCES_CONTROL      = 21,
    DATA_SINDRAGOSA_FROSTWYRMS      = 22,
    DATA_SPINESTALKER               = 23,
    DATA_RIMEFANG                   = 24,
    DATA_COLDFLAME_JETS             = 25,
    DATA_TEAM_IN_INSTANCE           = 26,
    DATA_BLOOD_QUICKENING_STATE     = 27,
    DATA_HEROIC_ATTEMPTS            = 28,
};

enum CreaturesIds
{
    // At Light's Hammer
    NPC_HIGHLORD_TIRION_FORDRING_LH             = 37119,
    NPC_THE_LICH_KING_LH                        = 37181,
    NPC_HIGHLORD_BOLVAR_FORDRAGON_LH            = 37183,
    NPC_KOR_KRON_GENERAL                        = 37189,
    NPC_ALLIANCE_COMMANDER                      = 37190,
    NPC_TORTUNOK                                = 37992,    // Druid Armor H
    NPC_ALANA_MOONSTRIKE                        = 37999,    // Druid Armor A
    NPC_GERARDO_THE_SUAVE                       = 37993,    // Hunter Armor H
    NPC_TALAN_MOONSTRIKE                        = 37998,    // Hunter Armor A
    NPC_UVLUS_BANEFIRE                          = 38284,    // Mage Armor H
    NPC_MALFUS_GRIMFROST                        = 38283,    // Mage Armor A
    NPC_IKFIRUS_THE_VILE                        = 37991,    // Rogue Armor H
    NPC_YILI                                    = 37997,    // Rogue Armor A
    NPC_VOL_GUK                                 = 38841,    // Shaman Armor H
    NPC_JEDEBIA                                 = 38840,    // Shaman Armor A
    NPC_HARAGG_THE_UNSEEN                       = 38181,    // Warlock Armor H
    NPC_NIBY_THE_ALMIGHTY                       = 38182,    // Warlock Armor N
    NPC_GARROSH_HELLSCREAM                      = 39372,
    NPC_KING_VARIAN_WRYNN                       = 39371,

    // Weekly quests
    NPC_INFILTRATOR_MINCHAR                     = 38471,
    NPC_KOR_KRON_LIEUTENANT                     = 38491,
    NPC_SKYBREAKER_LIEUTENANT                   = 38492,
    NPC_ALCHEMIST_ADRIANNA                      = 38501,
    NPC_ALRIN_THE_AGILE                         = 38551,
    NPC_INFILTRATOR_MINCHAR_BQ                  = 38558,
    NPC_MINCHAR_BEAM_STALKER                    = 38557,
    NPC_VALITHRIA_DREAMWALKER_QUEST             = 38589,

    // Lord Marrowgar
    NPC_LORD_MARROWGAR                          = 36612,
    NPC_COLDFLAME                               = 36672,
    NPC_BONE_SPIKE                              = 36619,

    // Lady Deathwhisper
    NPC_LADY_DEATHWHISPER                       = 36855,
    NPC_CULT_FANATIC                            = 37890,
    NPC_DEFORMED_FANATIC                        = 38135,
    NPC_REANIMATED_FANATIC                      = 38009,
    NPC_CULT_ADHERENT                           = 37949,
    NPC_EMPOWERED_ADHERENT                      = 38136,
    NPC_REANIMATED_ADHERENT                     = 38010,
    NPC_VENGEFUL_SHADE                          = 38222,

    // Deathbringer Saurfang
    NPC_DEATHBRINGER_SAURFANG                   = 37813,
    NPC_BLOOD_BEAST                             = 38508,
    NPC_SE_JAINA_PROUDMOORE                     = 37188,    // SE means Saurfang Event
    NPC_SE_MURADIN_BRONZEBEARD                  = 37200,
    NPC_SE_KING_VARIAN_WRYNN                    = 37879,
    NPC_SE_HIGH_OVERLORD_SAURFANG               = 37187,
    NPC_SE_KOR_KRON_REAVER                      = 37920,
    NPC_SE_SKYBREAKER_MARINE                    = 37830,
    NPC_FROST_FREEZE_TRAP                       = 37744,

    // Festergut
    NPC_FESTERGUT                               = 36626,
    NPC_GAS_DUMMY                               = 36659,

    // Rotface
    NPC_ROTFACE                                 = 36627,
    NPC_OOZE_SPRAY_STALKER                      = 37986,
    NPC_PUDDLE_STALKER                          = 37013,
    NPC_UNSTABLE_EXPLOSION_STALKER              = 38107,

    // Professor Putricide
    NPC_PROFESSOR_PUTRICIDE                     = 36678,
    NPC_ABOMINATION_WING_MAD_SCIENTIST_STALKER  = 37824,
    NPC_GROWING_OOZE_PUDDLE                     = 37690,
    NPC_GAS_CLOUD                               = 37562,
    NPC_VOLATILE_OOZE                           = 37697,
    NPC_CHOKING_GAS_BOMB                        = 38159,
    NPC_TEAR_GAS_TARGET_STALKER                 = 38317,
    NPC_MUTATED_ABOMINATION_10                  = 37672,
    NPC_MUTATED_ABOMINATION_25                  = 38285,

    // Blood Prince Council
    NPC_PRINCE_KELESETH                         = 37972,
    NPC_PRINCE_TALDARAM                         = 37973,
    NPC_PRINCE_VALANAR                          = 37970,
    NPC_BLOOD_ORB_CONTROLLER                    = 38008,
    NPC_FLOATING_TRIGGER                        = 30298,
    NPC_DARK_NUCLEUS                            = 38369,
    NPC_BALL_OF_FLAME                           = 38332,
    NPC_BALL_OF_INFERNO_FLAME                   = 38451,
    NPC_KINETIC_BOMB_TARGET                     = 38458,
    NPC_KINETIC_BOMB                            = 38454,
    NPC_SHOCK_VORTEX                            = 38422,

    // Blood-Queen Lana'thel
    NPC_BLOOD_QUEEN_LANA_THEL                   = 37955,

    // Sindragosa
    NPC_SINDRAGOSA                              = 36853,
    NPC_SPINESTALKER                            = 37534,
    NPC_RIMEFANG                                = 37533,
    NPC_FROSTWARDEN_HANDLER                     = 37531,
    NPC_FROSTWING_WHELP                         = 37532,
    NPC_ICY_BLAST                               = 38223,
    NPC_FROST_BOMB                              = 37186,
    NPC_ICE_TOMB                                = 36980,
};

enum GameObjectsIds
{
    // Lord Marrogar
    GO_DOODAD_ICECROWN_ICEWALL02            = 201910,
    GO_ICEWALL                              = 201911,
    GO_LORD_MARROWGAR_S_ENTRANCE            = 201857,

    // Lady Deathwhisper
    GO_ORATORY_OF_THE_DAMNED_ENTRANCE       = 201563,
    GO_LADY_DEATHWHISPER_ELEVATOR           = 202220,

    // Deathbringer Saurfang
    GO_SAURFANG_S_DOOR                      = 201825,
    GO_DEATHBRINGER_S_CACHE_10N             = 202239,
    GO_DEATHBRINGER_S_CACHE_25N             = 202240,
    GO_DEATHBRINGER_S_CACHE_10H             = 202238,
    GO_DEATHBRINGER_S_CACHE_25H             = 202241,
    GO_SCOURGE_TRANSPORTER_SAURFANG         = 202244,

    // Professor Putricide
    GO_ORANGE_PLAGUE_MONSTER_ENTRANCE       = 201371,
    GO_GREEN_PLAGUE_MONSTER_ENTRANCE        = 201370,
    GO_SCIENTIST_AIRLOCK_DOOR_COLLISION     = 201612,
    GO_SCIENTIST_AIRLOCK_DOOR_ORANGE        = 201613,
    GO_SCIENTIST_AIRLOCK_DOOR_GREEN         = 201614,
    GO_DOODAD_ICECROWN_ORANGETUBES02        = 201617,
    GO_DOODAD_ICECROWN_GREENTUBES02         = 201618,
    GO_SCIENTIST_ENTRANCE                   = 201372,
    GO_DRINK_ME                             = 201584,
    GO_PLAGUE_SIGIL                         = 202182,

    // Blood Prince Council
    GO_CRIMSON_HALL_DOOR                    = 201376,
    GO_BLOOD_ELF_COUNCIL_DOOR               = 201378,
    GO_BLOOD_ELF_COUNCIL_DOOR_RIGHT         = 201377,

    // Blood-Queen Lana'thel
    GO_DOODAD_ICECROWN_BLOODPRINCE_DOOR_01  = 201746,
    GO_DOODAD_ICECROWN_GRATE_01             = 201755,
    GO_BLOODWING_SIGIL                      = 202183,

    // Valithria Dreamwalker
    GO_GREEN_DRAGON_BOSS_ENTRANCE           = 201375,
    GO_GREEN_DRAGON_BOSS_EXIT               = 201374,

    // Sindragosa
    GO_SINDRAGOSA_ENTRANCE_DOOR             = 201373,
    GO_SINDRAGOSA_SHORTCUT_ENTRANCE_DOOR    = 201369,
    GO_SINDRAGOSA_SHORTCUT_EXIT_DOOR        = 201379,
    GO_ICE_WALL                             = 202396,
    GO_ICE_BLOCK                            = 201722,
    GO_SIGIL_OF_THE_FROSTWING               = 202181,
};

enum AchievementCriteriaIds
{
    // Lord Marrowgar
    CRITERIA_BONED_10N                  = 12775,
    CRITERIA_BONED_25N                  = 12962,
    CRITERIA_BONED_10H                  = 13393,
    CRITERIA_BONED_25H                  = 13394,

    // Rotface
    CRITERIA_DANCES_WITH_OOZES_10N      = 12984,
    CRITERIA_DANCES_WITH_OOZES_25N      = 12966,
    CRITERIA_DANCES_WITH_OOZES_10H      = 12985,
    CRITERIA_DANCES_WITH_OOZES_25H      = 12983,

    // Professor Putricide
    CRITERIA_NAUSEA_10N                 = 12987,
    CRITERIA_NAUSEA_25N                 = 12968,
    CRITERIA_NAUSEA_10H                 = 12988,
    CRITERIA_NAUSEA_25H                 = 12981,

    // Blood Prince Council
    CRITERIA_ORB_WHISPERER_10N          = 13033,
    CRITERIA_ORB_WHISPERER_25N          = 12969,
    CRITERIA_ORB_WHISPERER_10H          = 13034,
    CRITERIA_ORB_WHISPERER_25H          = 13032,

    // Blood-Queen Lana'thel
    CRITERIA_KILL_LANA_THEL_10M         = 13340,
    CRITERIA_KILL_LANA_THEL_25M         = 13360,
    CRITERIA_ONCE_BITTEN_TWICE_SHY_10N  = 12780,
    CRITERIA_ONCE_BITTEN_TWICE_SHY_25N  = 13012,
    CRITERIA_ONCE_BITTEN_TWICE_SHY_10V  = 13011,
    CRITERIA_ONCE_BITTEN_TWICE_SHY_25V  = 13013,
};

enum SharedActions
{
    // Coldflame Traps
    ACTION_STOP_TRAPS           = -377440,

    // Festergut
    ACTION_FESTERGUT_COMBAT     = -366260,
    ACTION_FESTERGUT_GAS        = -366261,
    ACTION_FESTERGUT_DEATH      = -366262,

    // Rotface
    ACTION_ROTFACE_COMBAT       = -366270,
    ACTION_ROTFACE_OOZE         = -366271,
    ACTION_ROTFACE_DEATH        = -366272,
    ACTION_CHANGE_PHASE         = -366780,

    // Blood-Queen Lana'thel
    ACTION_KILL_MINCHAR         = -379550,

    // Sindragosa
    ACTION_START_FROSTWYRM      = -368530,
    ACTION_TRIGGER_ASPHYXIATION = -368531,
};

enum WeekliesICC
{
    QUEST_DEPROGRAMMING_10                  = 24869,
    QUEST_DEPROGRAMMING_25                  = 24875,
    QUEST_SECURING_THE_RAMPARTS_10          = 24870,
    QUEST_SECURING_THE_RAMPARTS_25          = 24877,
    QUEST_RESIDUE_RENDEZVOUS_10             = 24873,
    QUEST_RESIDUE_RENDEZVOUS_25             = 24878,
    QUEST_BLOOD_QUICKENING_10               = 24874,
    QUEST_BLOOD_QUICKENING_25               = 24879,
    QUEST_RESPITE_FOR_A_TORNMENTED_SOUL_10  = 24872,
    QUEST_RESPITE_FOR_A_TORNMENTED_SOUL_25  = 24880,
};

enum WorldStatesICC
{
    WORLDSTATE_SHOW_TIMER           = 4903,
    WORLDSTATE_EXECUTION_TIME       = 4904,
    WORLDSTATE_SHOW_ATTEMPTS        = 4940,
    WORLDSTATE_ATTEMPTS_REMAINING   = 4941,
    WORLDSTATE_ATTEMPTS_MAX         = 4942,
};

class spell_trigger_spell_from_caster : public SpellScriptLoader
{
    public:
        spell_trigger_spell_from_caster(char const* scriptName, uint32 triggerId) : SpellScriptLoader(scriptName), _triggerId(triggerId) { }

        class spell_trigger_spell_from_caster_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_trigger_spell_from_caster_SpellScript);

        public:
            spell_trigger_spell_from_caster_SpellScript(uint32 triggerId) : SpellScript(), _triggerId(triggerId) { }

            bool Validate(SpellEntry const* /*spell*/)
            {
                if (!sSpellStore.LookupEntry(_triggerId))
                    return false;
                return true;
            }

            void HandleTrigger()
            {
                GetCaster()->CastSpell(GetHitUnit(), _triggerId, true);
            }

            void Register()
            {
                AfterHit += SpellHitFn(spell_trigger_spell_from_caster_SpellScript::HandleTrigger);
            }

            uint32 _triggerId;
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_trigger_spell_from_caster_SpellScript(_triggerId);
        }

    private:
        uint32 _triggerId;
};

#endif // ICECROWN_CITADEL_H_
