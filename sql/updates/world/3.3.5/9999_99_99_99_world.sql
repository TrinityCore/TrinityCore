DELETE FROM `disables` WHERE `entry`=650 AND `sourceType`=2;
-- Trial of the Champion (Originated from Appled). Thanks to Aokromes for providing sniffs
-- General: 
-- Disabling mmap for Trial of the Champion instance
-- creatures are spawned according to sniffs behind an invisible wall and they don't know how to go through it
-- Edit: Aokromes has pushed this already, but disabled the whole instance in the same commit
-- Updated to work with TDB_full_world_335.20021_2020_02_15.sql

-- DELETE FROM `disables` WHERE `sourceType`=7 AND `entry`= 650;
-- INSERT INTO `disables` (`sourceType`,`entry`) VALUES (7, 650);

DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_black_knight_army_of_the_dead',
'spell_black_knight_deaths_push',
'spell_black_knight_ghoul_explode',
'spell_black_knight_obliterate',
'spell_eadric_hammer_of_righteous',
'spell_eadric_hammer_of_righteous_faceroller',
'spell_paletress_reflective_shield',
'spell_toc5_lightning_arrows',
'spell_toc5_trample_aura');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(67761, 'spell_black_knight_army_of_the_dead'),         -- The Black Knight's Army of the Dead
(67874, 'spell_black_knight_army_of_the_dead'),         -- The Black Knight's Army of the Dead
(66797, 'spell_black_knight_deaths_push'),              -- The Black Knight's Death's Push - cast on announcer
(67751, 'spell_black_knight_ghoul_explode'),            -- The Black Knight's Ghoul Explode
(67725, 'spell_black_knight_obliterate'),               -- The Black Knight's Obliterate
(67883, 'spell_black_knight_obliterate'),               -- The Black Knight's Obliterate
(66867, 'spell_eadric_hammer_of_righteous'),            -- Eadric' Hammer of the Righteous
(66905, 'spell_eadric_hammer_of_righteous_faceroller'), -- Eadric' Hammer of the Righteous - cast by player
(66515, 'spell_paletress_reflective_shield'),           -- Paletress' Reflective Shield
(66083, 'spell_toc5_lightning_arrows'),                 -- Hunter Grand Champion's Lightning Arrows
(67868, 'spell_toc5_trample_aura');                     -- Trial of the Champion vehicles' Trample aura

-- Adding difficulty entries
DELETE FROM `spelldifficulty_dbc` WHERE `id` IN (36176,34941);
INSERT INTO `spelldifficulty_dbc` (`id`,`spellid0`,`spellid1`,`spellid2`,`spellid3`) VALUES
(36176, 36176, 67289, 0, 0),
(34941, 34941, 34942, 0, 0);

-- Eadric and Paletress should not drop item 47197 in heroic mode
-- it drops only from Eadric in normal mode
-- Also item 47947 was missing from Eadric and Paletress in heroic mode
DELETE FROM `reference_loot_template` WHERE `Entry`=12025 AND `Item` IN (47197,47497);
INSERT INTO `reference_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(12025, 47497, 0, 0, 0, 1, 1, 1, 1, '');

-- The Black Knight should not drop item 47560 in normal mode, it drops only in heroic mode
-- Also item 47229 was missing from The Black Knight in normal mode
DELETE FROM `reference_loot_template` WHERE `Entry`=34170 AND `Item` IN (47229, 47560);
INSERT INTO `reference_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(34170, 47229, 0, 0, 0, 1, 1, 1, 1, '');

-- Vehicles:

-- Variables
SET @ARGENT_WARHORSE_GC   := 35644; -- used by Grand Champions in looking for mount phase, cannot be used by players
SET @ARGENT_WARHORSE      := 36557;
SET @ARGENT_BATTLEWORG    := 36558;
SET @ARGENT_BATTLEWORG_GC := 36559; -- used by Grand Champions in looking for mount phase, cannot be used by players

-- Scriptname for cosmetic vehicles
UPDATE `creature_template` SET `ScriptName`='generic_vehicleAI_toc5' WHERE `entry` IN (@ARGENT_BATTLEWORG_GC,@ARGENT_WARHORSE_GC);

UPDATE `creature_template` SET `faction`=14, `npcflag`=16777216, `VehicleId`=529, `speed_walk`=2.5/2.5, `speed_run`=11.0/7.0, `unit_flags`=256, `unit_flags2`=0 WHERE `entry` IN (@ARGENT_WARHORSE_GC,@ARGENT_BATTLEWORG_GC);
UPDATE `creature_template` SET `faction`=35, `npcflag`=16777216, `VehicleId`=486, `speed_walk`=2.5/2.5, `speed_run`=11.0/7.0, `unit_flags`=  0, `unit_flags2`=0 WHERE `entry` IN (@ARGENT_WARHORSE,@ARGENT_BATTLEWORG);

DELETE FROM `creature_template_spell` WHERE `CreatureID` IN (@ARGENT_WARHORSE_GC, @ARGENT_BATTLEWORG_GC);
DELETE FROM `creature_template_spell` WHERE `CreatureID` IN (@ARGENT_WARHORSE, @ARGENT_BATTLEWORG);

INSERT INTO `creature_template_spell` (`CreatureID`, `Index`, `Spell`, `VerifiedBuild`) VALUES (@ARGENT_WARHORSE, 0, 68505, 12340);
INSERT INTO `creature_template_spell` (`CreatureID`, `Index`, `Spell`, `VerifiedBuild`) VALUES (@ARGENT_WARHORSE, 1, 62575, 12340);
INSERT INTO `creature_template_spell` (`CreatureID`, `Index`, `Spell`, `VerifiedBuild`) VALUES (@ARGENT_WARHORSE, 2, 68282, 12340);
INSERT INTO `creature_template_spell` (`CreatureID`, `Index`, `Spell`, `VerifiedBuild`) VALUES (@ARGENT_WARHORSE, 3, 62552, 12340);

INSERT INTO `creature_template_spell` (`CreatureID`, `Index`, `Spell`, `VerifiedBuild`) VALUES (@ARGENT_BATTLEWORG, 0, 68505, 12340);
INSERT INTO `creature_template_spell` (`CreatureID`, `Index`, `Spell`, `VerifiedBuild`) VALUES (@ARGENT_BATTLEWORG, 1, 62575, 12340);
INSERT INTO `creature_template_spell` (`CreatureID`, `Index`, `Spell`, `VerifiedBuild`) VALUES (@ARGENT_BATTLEWORG, 2, 68282, 12340);
INSERT INTO `creature_template_spell` (`CreatureID`, `Index`, `Spell`, `VerifiedBuild`) VALUES (@ARGENT_BATTLEWORG, 3, 62552, 12340);


DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (@ARGENT_WARHORSE_GC,@ARGENT_WARHORSE,@ARGENT_BATTLEWORG,@ARGENT_BATTLEWORG_GC);
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`cast_flags`,`user_type`) VALUES
(@ARGENT_WARHORSE,   67830, 1, 0),
(@ARGENT_BATTLEWORG, 67830, 1, 0);

DELETE FROM `creature_template_addon` WHERE `entry` IN (@ARGENT_WARHORSE_GC,@ARGENT_WARHORSE,@ARGENT_BATTLEWORG,@ARGENT_BATTLEWORG_GC);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@ARGENT_WARHORSE_GC,   0, 0,   1, 0, '67870'),
(@ARGENT_WARHORSE,      0, 0, 257, 0, '67865'),
(@ARGENT_BATTLEWORG,    0, 0, 257, 0, '67865'),
(@ARGENT_BATTLEWORG_GC, 0, 0,   1, 0, '67870');

-- You should not be able to mount a vehicle if you don't have Argent Lance equipped
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=16 AND `SourceGroup`=0 AND `SourceEntry` IN (@ARGENT_BATTLEWORG,@ARGENT_WARHORSE);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`Comment`) VALUES
(16,0,@ARGENT_BATTLEWORG,0,0,3,0,46106,0,0,'Argent Lance must be equipped in order to mount a vehicle'),
(16,0,@ARGENT_WARHORSE,0,0,3,0,46106,0,0,'Argent Lance must be equipped in order to mount a vehicle');

-- Heralds:

-- Variables
SET @HERALD_H := 35004; -- Jaeren Sunsworn
SET @HERALD_A := 35005; -- Arelas Brightstar
SET @GOSSIP_MENU := 10614; -- same gossip menu used by both heralds

-- Arelas Brightstar had no gossip menu set in database
UPDATE `creature_template` SET `gossip_menu_id`=@GOSSIP_MENU WHERE `entry`=@HERALD_A;

-- Text updates

-- Roleplaying event creature_text data
DELETE FROM `creature_text` WHERE `CreatureID` IN (@HERALD_H,@HERALD_A) AND `groupid` BETWEEN 9 AND 13;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@HERALD_H,  9, 0, "$n has risen to the ranks of champion in our tournament.  We are proud to present $ghim:her; to you today.", 14, 0, 100, 0, 0, 8574, 35304, 2, 'Jaeren Sunsworn - SAY_JAEREN_INTRODUCE_PLAYER_0'),
(@HERALD_H, 10, 0, "Champions on the tournament grounds speak highly of this $c.  Today we present, $n.",                        14, 0, 100, 0, 0, 8574, 35305, 2, 'Jaeren Sunsworn - SAY_JAEREN_INTRODUCE_PLAYER_1'),
(@HERALD_H, 11, 0, "One would be hard pressed to find a more steadfast champion than this $c.  Today we present, $n.",           14, 0, 100, 0, 0, 8574, 35306, 2, 'Jaeren Sunsworn - SAY_JAEREN_INTRODUCE_PLAYER_2'),
(@HERALD_H, 12, 0, "We offer a mighty champion, a capable $c, an honorable $r.  We present, $n.",                                14, 0, 100, 0, 0, 8574, 35307, 2, 'Jaeren Sunsworn - SAY_JAEREN_INTRODUCE_PLAYER_3'),
(@HERALD_H, 13, 0, "Many champions have fallen to the skills displayed by $n.  We are proud to present this formidable $c.",     14, 0, 100, 0, 0, 8574, 35308, 2, 'Jaeren Sunsworn - SAY_JAEREN_INTRODUCE_PLAYER_4'),
(@HERALD_A,  9, 0, "$n has risen to the ranks of champion in our tournament.  We are proud to present $ghim:her; to you today.", 14, 0, 100, 0, 0, 8574, 35304, 2, 'Arelas Brightstar - SAY_ARELAS_INTRODUCE_PLAYER_0'),
(@HERALD_A, 10, 0, "Champions on the tournament grounds speak highly of this $c.  Today we present, $n.",                        14, 0, 100, 0, 0, 8574, 35305, 2, 'Arelas Brightstar - SAY_ARELAS_INTRODUCE_PLAYER_1'),
(@HERALD_A, 11, 0, "One would be hard pressed to find a more steadfast champion than this $c.  Today we present, $n.",           14, 0, 100, 0, 0, 8574, 35306, 2, 'Arelas Brightstar - SAY_ARELAS_INTRODUCE_PLAYER_2'),
(@HERALD_A, 12, 0, "We offer a mighty champion, a capable $c, an honorable $r.  We present, $n.",                                14, 0, 100, 0, 0, 8574, 35307, 2, 'Arelas Brightstar - SAY_ARELAS_INTRODUCE_PLAYER_3'),
(@HERALD_A, 13, 0, "Many champions have fallen to the skills displayed by $n.  We are proud to present this formidable $c.",     14, 0, 100, 0, 0, 8574, 35308, 2, 'Arelas Brightstar - SAY_ARELAS_INTRODUCE_PLAYER_4');

-- Jaina Proudmoore's texts
DELETE FROM `creature_text` WHERE `CreatureID` = 34992 AND `GroupID` IN (0, 1);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(34992, 0, 0, 'Of course they will.',                 12, 0, 100, 0, 0, 0, 35323, 2, 'Lady Jaina Proudmoore - SAY_JAINA_INTRO_1'),
(34992, 1, 0, "They're worthy fighters, you'll see.", 12, 0, 100, 0, 0, 0, 35329, 2, 'Lady Jaina Proudmoore - SAY_JAINA_INTRO_2');

-- Two of the texts in instance were 'say' instead of 'yell'
UPDATE `creature_text` SET `Type`= 14 WHERE `CreatureID`=@HERALD_A AND `groupid`= 0;
UPDATE `creature_text` SET `Type`= 14 WHERE `CreatureID`=@HERALD_H AND `groupid`= 0;

-- Most of the texts in instance should be zonewide
UPDATE `creature_text` SET `TextRange`=2 WHERE `CreatureID` BETWEEN 34900 AND 34910 AND `GroupID`=0 AND `ID`=0;
UPDATE `creature_text` SET `TextRange`=2 WHERE `CreatureID`=34990 AND `GroupID` BETWEEN 50 AND 53;
UPDATE `creature_text` SET `TextRange`=2 WHERE `CreatureID`=34994;
UPDATE `creature_text` SET `TextRange`=2 WHERE `CreatureID`=34995 AND `GroupID` BETWEEN 50 AND 52;
UPDATE `creature_text` SET `TextRange`=2 WHERE `CreatureID`=34996 AND `GroupID` BETWEEN 50 AND 58 AND `ID`=0;
UPDATE `creature_text` SET `TextRange`=2 WHERE `CreatureID` IN (@HERALD_A,@HERALD_H) AND `GroupID` BETWEEN 0 AND 8 AND `ID`=0;
UPDATE `creature_text` SET `TextRange`=2 WHERE `CreatureID` IN (34657,34701,34702,34703,34705,34883,34887,35569,35570,35571,35572,35617) AND `GroupID`=0 AND `ID`=0;
UPDATE `creature_text` SET `TextRange`=2 WHERE `CreatureID` IN (34928,35119,35451);
UPDATE `creature_text` SET `TextRange`=2 WHERE `BroadcastTextId`=35491;

-- Lesser Champions:

-- Variables
SET @ORC_CHAMP     := 35314;
SET @TROLL_CHAMP   := 35323;
SET @TAUREN_CHAMP  := 35325;
SET @BELF_CHAMP    := 35326;
SET @UNDEAD_CHAMP  := 35327;
SET @HUMAN_CHAMP   := 35328;
SET @DWARF_CHAMP   := 35329;
SET @DRAENEI_CHAMP := 35330;
SET @GNOME_CHAMP   := 35331;
SET @NELF_CHAMP    := 35332;

-- Each lesser champion had passiveAI set and had no scriptname assigned in database
UPDATE `creature_template` SET `AIName`='',`ScriptName`='generic_vehicleAI_toc5' WHERE `entry` IN (@ORC_CHAMP,@TROLL_CHAMP,@TAUREN_CHAMP,@BELF_CHAMP,@UNDEAD_CHAMP,@HUMAN_CHAMP,@DWARF_CHAMP,@DRAENEI_CHAMP,@GNOME_CHAMP,@NELF_CHAMP);

-- Lesser Champions should award reputation on kill
DELETE FROM `creature_onkill_reputation` WHERE `creature_id` IN (@ORC_CHAMP,@TROLL_CHAMP,@TAUREN_CHAMP,@BELF_CHAMP,@UNDEAD_CHAMP,@HUMAN_CHAMP,@DWARF_CHAMP,@DRAENEI_CHAMP,@GNOME_CHAMP,@NELF_CHAMP);
INSERT INTO `creature_onkill_reputation` (`creature_id`,`RewOnKillRepFaction1`,`RewOnKillRepFaction2`,`MaxStanding1`,`IsTeamAward1`,`RewOnKillRepValue1`,`MaxStanding2`,`IsTeamAward2`,`RewOnKillRepValue2`,`TeamDependent`) VALUES
(@ORC_CHAMP,    1037, 1052, 7, 0, 5, 7, 0, 5, 1),
(@TROLL_CHAMP,  1037, 1052, 7, 0, 5, 7, 0, 5, 1),
(@TAUREN_CHAMP, 1037, 1052, 7, 0, 5, 7, 0, 5, 1),
(@BELF_CHAMP,   1037, 1052, 7, 0, 5, 7, 0, 5, 1),
(@UNDEAD_CHAMP, 1037, 1052, 7, 0, 5, 7, 0, 5, 1),
(@HUMAN_CHAMP,  1037, 1052, 7, 0, 5, 7, 0, 5, 1),
(@DWARF_CHAMP,  1037, 1052, 7, 0, 5, 7, 0, 5, 1),
(@DRAENEI_CHAMP,1037, 1052, 7, 0, 5, 7, 0, 5, 1),
(@GNOME_CHAMP,  1037, 1052, 7, 0, 5, 7, 0, 5, 1),
(@NELF_CHAMP,   1037, 1052, 7, 0, 5, 7, 0, 5, 1);

-- Grand Champions:

-- Normal mode
SET @MOKRA     := 35572;
SET @ERESSEA   := 35569;
SET @RUNOK     := 35571;
SET @ZULTORE   := 35570;
SET @VISCERI   := 35617;
SET @JACOB     := 34705;
SET @AMBROSE   := 34702;
SET @COLOSOS   := 34701;
SET @JAELYNE   := 34657;
SET @LANA      := 34703;
-- Heroic mode
SET @MOKRA_H   := 36089;
SET @ERESSEA_H := 36085;
SET @RUNOK_H   := 36090;
SET @ZULTORE_H := 36091;
SET @VISCERI_H := 36084;
SET @JACOB_H   := 36088;
SET @AMBROSE_H := 36082;
SET @COLOSOS_H := 36083;
SET @JAELYNE_H := 36086;
SET @LANA_H    := 36087;

-- None of the grand champions had correct unit flags set in database
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|33024 WHERE `entry` IN 
(@MOKRA,@ERESSEA,@RUNOK,@ZULTORE,@VISCERI,@JACOB,@AMBROSE,@COLOSOS,@JAELYNE,@LANA,@MOKRA_H,@ERESSEA_H,@RUNOK_H,@ZULTORE_H,@VISCERI_H,@JACOB_H,@AMBROSE_H,@COLOSOS_H,@JAELYNE_H,@LANA_H);

-- Rogue Champion's Deadly Poison should have 5 second internal cooldown
DELETE FROM `spell_proc` WHERE `SpellId`=67711;
INSERT INTO `spell_proc` (`SpellId`,`Cooldown`) VALUES (67711,5);

-- Rogue Champion's Fan of Knives should also trigger Deadly Poison on each target
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=67706;
INSERT INTO `spell_linked_spell` VALUES
(67706, 67710, 1, 'Rogue Champion - Trigger Deadly Poison on Fan of Knives');

-- Achievement criteria data for achievement IDs 3778, 4018, 4019, 4048, 4049, 4050, 4051, 4052, 4053, 4054, 4055, 4296, 4297, 4298,

SET @CRITERIA_JACOB     := 11420;
SET @CRITERIA_LANA      := 12298;
SET @CRITERIA_COLOSOS   := 12299;
SET @CRITERIA_AMBROSE   := 12300;
SET @CRITERIA_JAELYNE   := 12301;
SET @CRITERIA_MOKRA     := 12302;
SET @CRITERIA_VISCERI   := 12303;
SET @CRITERIA_RUNOK     := 12304;
SET @CRITERIA_ERESSEA   := 12305;
SET @CRITERIA_ZULTORE   := 12306;
SET @CRITERIA_JACOB_H   := 12310;
SET @CRITERIA_LANA_H    := 12311;
SET @CRITERIA_COLOSOS_H := 12312;
SET @CRITERIA_AMBROSE_H := 12313;
SET @CRITERIA_JAELYNE_H := 12314;
SET @CRITERIA_MOKRA_H   := 12318;
SET @CRITERIA_VISCERI_H := 12319;
SET @CRITERIA_RUNOK_H   := 12320;
SET @CRITERIA_ERESSEA_H := 12321;
SET @CRITERIA_ZULTORE_H := 12322;
-- Statistics achievements
SET @CRITERIA_WARRIOR   := 12538;
SET @CRITERIA_HUNTER    := 12540;
SET @CRITERIA_MAGE      := 12542;
SET @CRITERIA_ROGUE     := 12544;
SET @CRITERIA_SHAMAN    := 12546;
SET @CRITERIA_WARRIOR_H := 12539;
SET @CRITERIA_HUNTER_H  := 12541;
SET @CRITERIA_MAGE_H    := 12543;
SET @CRITERIA_ROGUE_H   := 12545;
SET @CRITERIA_SHAMAN_H  := 12547;

-- The Faceroller achievement
DELETE FROM `achievement_criteria_data` WHERE `criteria_id`=11858 AND `type`=11;
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`ScriptName`) VALUES
(11858, 11, 'achievement_eadric_faceroller');

-- These criterias are missing creature checks
DELETE FROM `achievement_criteria_data` WHERE `type`=1 AND `criteria_id` IN (@CRITERIA_JACOB,@CRITERIA_LANA,@CRITERIA_COLOSOS,@CRITERIA_AMBROSE,@CRITERIA_JAELYNE,@CRITERIA_MOKRA,@CRITERIA_VISCERI,@CRITERIA_RUNOK,@CRITERIA_ERESSEA,@CRITERIA_ZULTORE,@CRITERIA_JACOB_H,@CRITERIA_LANA_H,@CRITERIA_COLOSOS_H,@CRITERIA_AMBROSE_H,@CRITERIA_JAELYNE_H,@CRITERIA_MOKRA_H,@CRITERIA_VISCERI_H,@CRITERIA_RUNOK_H,@CRITERIA_ERESSEA_H,@CRITERIA_ZULTORE_H);
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`) VALUES
(@CRITERIA_JACOB,     1, @JACOB),
(@CRITERIA_LANA,      1, @LANA),
(@CRITERIA_COLOSOS,   1, @COLOSOS),
(@CRITERIA_AMBROSE,   1, @AMBROSE),
(@CRITERIA_JAELYNE,   1, @JAELYNE),
(@CRITERIA_MOKRA,     1, @MOKRA),
(@CRITERIA_VISCERI,   1, @VISCERI),
(@CRITERIA_RUNOK,     1, @RUNOK),
(@CRITERIA_ERESSEA,   1, @ERESSEA),
(@CRITERIA_ZULTORE,   1, @ZULTORE),
(@CRITERIA_JACOB_H,   1, @JACOB),
(@CRITERIA_LANA_H,    1, @LANA),
(@CRITERIA_COLOSOS_H, 1, @COLOSOS),
(@CRITERIA_AMBROSE_H, 1, @AMBROSE),
(@CRITERIA_JAELYNE_H, 1, @JAELYNE),
(@CRITERIA_MOKRA_H,   1, @MOKRA),
(@CRITERIA_VISCERI_H, 1, @VISCERI),
(@CRITERIA_RUNOK_H,   1, @RUNOK),
(@CRITERIA_ERESSEA_H, 1, @ERESSEA),
(@CRITERIA_ZULTORE_H, 1, @ZULTORE);

-- Statistics achievements are also missing creature checks, but as criterias are same on both horde and alliance,
-- and we can only check for one creature entry, we must use core script to check for two entries
-- Also we remove heroic checks from database, they are handled in the script
DELETE FROM `achievement_criteria_data` WHERE `type`=11 AND `criteria_id` IN (@CRITERIA_WARRIOR,@CRITERIA_HUNTER,@CRITERIA_MAGE,@CRITERIA_ROGUE,@CRITERIA_SHAMAN,@CRITERIA_WARRIOR_H,@CRITERIA_HUNTER_H,@CRITERIA_MAGE_H,@CRITERIA_ROGUE_H,@CRITERIA_SHAMAN_H);
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`ScriptName`) VALUES
(@CRITERIA_WARRIOR,  11,'achievement_victories_over_war_champion'),
(@CRITERIA_HUNTER,   11,'achievement_victories_over_hun_champion'),
(@CRITERIA_MAGE,     11,'achievement_victories_over_mag_champion'),
(@CRITERIA_ROGUE,    11,'achievement_victories_over_rog_champion'),
(@CRITERIA_SHAMAN,   11,'achievement_victories_over_sha_champion'),
(@CRITERIA_WARRIOR_H,11,'achievement_victories_over_war_champion_h'),
(@CRITERIA_HUNTER_H, 11,'achievement_victories_over_hun_champion_h'),
(@CRITERIA_MAGE_H,   11,'achievement_victories_over_mag_champion_h'),
(@CRITERIA_ROGUE_H,  11,'achievement_victories_over_rog_champion_h'),
(@CRITERIA_SHAMAN_H, 11,'achievement_victories_over_sha_champion_h');

-- Argent Champion:

-- Thrash mobs are missing reputation data and money drop

SET @ARGENT_MONK           := 35305;
SET @ARGENT_MONK_H         := 35306;
SET @ARGENT_PRIESTESS      := 35307;
SET @ARGENT_PRIESTESS_H    := 35308;
SET @ARGENT_LIGHTWIELDER   := 35309;
SET @ARGENT_LIGHTWIELDER_H := 35310;

UPDATE `creature_template` SET `mingold`=3821,`maxgold`=9521 WHERE `entry` IN (@ARGENT_MONK,@ARGENT_PRIESTESS,@ARGENT_LIGHTWIELDER);
UPDATE `creature_template` SET `mingold`=11529,`maxgold`=17291 WHERE `entry` IN (@ARGENT_MONK_H,@ARGENT_PRIESTESS_H,@ARGENT_LIGHTWIELDER_H);

DELETE FROM `creature_onkill_reputation` WHERE `creature_id` IN (@ARGENT_MONK,@ARGENT_PRIESTESS,@ARGENT_LIGHTWIELDER,@ARGENT_MONK_H,@ARGENT_PRIESTESS_H,@ARGENT_LIGHTWIELDER_H);
INSERT INTO `creature_onkill_reputation` (`creature_id`,`RewOnKillRepFaction1`,`RewOnKillRepFaction2`,`MaxStanding1`,`IsTeamAward1`,`RewOnKillRepValue1`,`MaxStanding2`,`IsTeamAward2`,`RewOnKillRepValue2`,`TeamDependent`) VALUES
(@ARGENT_MONK,           1037, 1052, 7, 0,  5, 7, 0,  5, 1),
(@ARGENT_PRIESTESS,      1037, 1052, 7, 0,  5, 7, 0,  5, 1),
(@ARGENT_LIGHTWIELDER,   1037, 1052, 7, 0,  5, 7, 0,  5, 1),
(@ARGENT_MONK_H,         1037, 1052, 7, 0, 10, 7, 0, 10, 1),
(@ARGENT_PRIESTESS_H,    1037, 1052, 7, 0, 10, 7, 0, 10, 1),
(@ARGENT_LIGHTWIELDER_H, 1037, 1052, 7, 0, 10, 7, 0, 10, 1);

-- Scriptname for Argent Priestess' Fountain of Light
UPDATE `creature_template` SET `ScriptName`='npc_fountain_of_light' WHERE `entry`=35311;

-- Adding aura 'Light Rain' (no SPELL_CAST found in sniff)
DELETE FROM `creature_template_addon` WHERE `entry`=35311;
INSERT INTO `creature_template_addon` (`entry`,`auras`) VALUES
(35311, '67196');

-- Achievement criteria data for achievement id 3802

SET @CRITERIA_HOGGER     := 11863;
SET @CRITERIA_VANCLEEF   := 11904;
SET @CRITERIA_MUTANUS    := 11905;
SET @CRITERIA_HEROD      := 11906;
SET @CRITERIA_LUCIFRON   := 11907;
SET @CRITERIA_THUNDERAAN := 11908;
SET @CRITERIA_CHROMAGGUS := 11909;
SET @CRITERIA_HAKKAR     := 11910;
SET @CRITERIA_VEKNILASH  := 11911;
SET @CRITERIA_KALITHRESH := 11912;
SET @CRITERIA_MALCHEZAAR := 11913;
SET @CRITERIA_GRUUL      := 11914;
SET @CRITERIA_VASHJ      := 11915;
SET @CRITERIA_ARCHIMONDE := 11916;
SET @CRITERIA_ILLIDAN    := 11917;
SET @CRITERIA_DELRISSA   := 11918;
SET @CRITERIA_MURU       := 11919;
SET @CRITERIA_INGVAR     := 11920;
SET @CRITERIA_CYANIGOSA  := 11921;
SET @CRITERIA_ECK        := 11922;
SET @CRITERIA_ONYXIA     := 11923;
SET @CRITERIA_HEIGAN     := 11924;
SET @CRITERIA_IGNIS      := 11925;
SET @CRITERIA_VEZAX      := 11926;
SET @CRITERIA_ALGALON    := 11927;

DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (@CRITERIA_HOGGER,@CRITERIA_VANCLEEF,@CRITERIA_MUTANUS,@CRITERIA_HEROD,@CRITERIA_LUCIFRON,@CRITERIA_THUNDERAAN,@CRITERIA_CHROMAGGUS,@CRITERIA_HAKKAR,@CRITERIA_VEKNILASH,@CRITERIA_KALITHRESH,@CRITERIA_MALCHEZAAR,@CRITERIA_GRUUL,@CRITERIA_VASHJ,@CRITERIA_ARCHIMONDE,@CRITERIA_ILLIDAN,@CRITERIA_DELRISSA,@CRITERIA_MURU,@CRITERIA_INGVAR,@CRITERIA_CYANIGOSA,@CRITERIA_ECK,@CRITERIA_ONYXIA,@CRITERIA_HEIGAN,@CRITERIA_IGNIS,@CRITERIA_VEZAX,@CRITERIA_ALGALON);
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`ScriptName`) VALUES
(@CRITERIA_HOGGER,     11, 'achievement_argent_confessor_hogger'),
(@CRITERIA_VANCLEEF,   11, 'achievement_argent_confessor_vancleef'),
(@CRITERIA_MUTANUS,    11, 'achievement_argent_confessor_mutanus'),
(@CRITERIA_HEROD,      11, 'achievement_argent_confessor_herod'),
(@CRITERIA_LUCIFRON,   11, 'achievement_argent_confessor_lucifron'),
(@CRITERIA_THUNDERAAN, 11, 'achievement_argent_confessor_thunderaan'),
(@CRITERIA_CHROMAGGUS, 11, 'achievement_argent_confessor_chromaggus'),
(@CRITERIA_HAKKAR,     11, 'achievement_argent_confessor_hakkar'),
(@CRITERIA_VEKNILASH,  11, 'achievement_argent_confessor_veknilash'),
(@CRITERIA_KALITHRESH, 11, 'achievement_argent_confessor_kalithresh'),
(@CRITERIA_MALCHEZAAR, 11, 'achievement_argent_confessor_malchezaar'),
(@CRITERIA_GRUUL,      11, 'achievement_argent_confessor_gruul'),
(@CRITERIA_VASHJ,      11, 'achievement_argent_confessor_vashj'),
(@CRITERIA_ARCHIMONDE, 11, 'achievement_argent_confessor_archimonde'),
(@CRITERIA_ILLIDAN,    11, 'achievement_argent_confessor_illidan'),
(@CRITERIA_DELRISSA,   11, 'achievement_argent_confessor_delrissa'),
(@CRITERIA_MURU,       11, 'achievement_argent_confessor_muru'),
(@CRITERIA_INGVAR,     11, 'achievement_argent_confessor_ingvar'),
(@CRITERIA_CYANIGOSA,  11, 'achievement_argent_confessor_cyanigosa'),
(@CRITERIA_ECK,        11, 'achievement_argent_confessor_eck'),
(@CRITERIA_ONYXIA,     11, 'achievement_argent_confessor_onyxia'),
(@CRITERIA_HEIGAN,     11, 'achievement_argent_confessor_heigan'),
(@CRITERIA_IGNIS,      11, 'achievement_argent_confessor_ignis'),
(@CRITERIA_VEZAX,      11, 'achievement_argent_confessor_vezax'),
(@CRITERIA_ALGALON,    11, 'achievement_argent_confessor_algalon');

-- Correcting Paletress' speed values on heroic mode
UPDATE `creature_template` SET `speed_walk`=2,`speed_run`=1.42857 WHERE `entry`=35517;

-- Correcting Paletress' mechanic immunities (she is interruptable)
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`|617299839 WHERE `entry` IN (34928,35517);

-- Paletress' Memory adds are missing mechanic immunities
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`|650854271 WHERE `entry`=34942 OR `entry` BETWEEN 35028 AND 35052 OR `entry` BETWEEN 35519 AND 35525 OR `entry` BETWEEN 35527 AND 35544;

-- Correcting Eadric' mechanic immunities
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`|650854271 WHERE `entry` IN (35119,35518);

-- Eadric' Vengeance spell should have internal cooldown and procChance
-- Proc spell should properly be removed on successful melee crit
DELETE FROM `spell_proc` WHERE `SpellId` IN (66865,66889);
INSERT INTO `spell_proc` (`SpellId`,`ProcFlags`,`HitMask`,`Chance`,`Cooldown`) VALUES 
(66865, 4, 0, 20, 10),
(66889, 4, 2,  0,  0);

-- Also the proc spell of Vengeance should not remove original aura
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=66889 AND `spell_effect`=-66865;

-- Player casted Hammer of the Righteous to Eadric should remove the dummy aura from player on cast
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=66905 AND `spell_effect`=-66904;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(66905, -66904, 0, 'Eadric - Remove dummy aura from player on cast');

-- The Black Knight:

SET @KNIGHT         := 35451;
SET @KNIGHT_H       := 35490;
SET @KNIGHT_VEHICLE := 35491;
SET @RISEN_CHAMP    := 35590;
SET @RISEN_CHAMP_H  := 35717;

-- The Black Knight's vehicle must have flight inhabit type
REPLACE INTO `creature_template_movement` (`Ground`, `Swim` ,`Flight`,`CreatureID`) VALUES (1,1,1,@KNIGHT_VEHICLE);

-- Risen Champion is missing scriptname
UPDATE `creature_template` SET `ScriptName`='npc_risen_ghoul' WHERE `entry`=@RISEN_CHAMP;

-- Risen Champions (not Risen Herald) and The Black Knight should award reputation on kill
DELETE FROM `creature_onkill_reputation` WHERE `creature_id` IN (@RISEN_CHAMP,@RISEN_CHAMP_H,@KNIGHT,@KNIGHT_H);
INSERT INTO `creature_onkill_reputation` (`creature_id`,`RewOnKillRepFaction1`,`RewOnKillRepFaction2`,`MaxStanding1`,`IsTeamAward1`,`RewOnKillRepValue1`,`MaxStanding2`,`IsTeamAward2`,`RewOnKillRepValue2`,`TeamDependent`) VALUES
(@RISEN_CHAMP,   1037, 1052, 7, 0,   5, 7, 0,   5, 1),
(@RISEN_CHAMP_H, 1037, 1052, 7, 0,  10, 7, 0,  10, 1),
(@KNIGHT,        1037, 1052, 7, 0, 195, 7, 0, 195, 1),
(@KNIGHT_H,      1037, 1052, 7, 0, 390, 7, 0, 390, 1);

-- Correcting The Black Knight's mechanic immunities
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`|650854271 WHERE `entry` IN (@KNIGHT,@KNIGHT_H);

-- The Black Knight should have money drop
UPDATE `creature_template` SET `mingold`= 4921,`maxgold`=10294 WHERE `entry`=@KNIGHT;
UPDATE `creature_template` SET `mingold`=14691,`maxgold`=21952 WHERE `entry`=@KNIGHT_H;

-- Achievement criteria script for achievement id 3804
DELETE FROM `achievement_criteria_data` WHERE `type` IN (11, 18) AND `criteria_id`=11789;
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`ScriptName`) VALUES
(11789, 11, 'achievement_ive_had_worse');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (66905, 66798, 67751);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13, 7, 66905, 0, 0, 31, 0, 3, 35119, 0, 0, 0, 0, '', "Hammer of the Righteous (Eadric the Pure)"),
(13, 1, 66798, 0, 0, 31, 0, 3, 35004, 0, 0, 0, 0, '', "Death's Respite (The Black Knight)"),
(13, 1, 66798, 0, 1, 31, 0, 3, 35005, 0, 0, 0, 0, '', "Death's Respite (The Black Knight)"),
(13, 7, 67751, 0, 0, 31, 0, 3, 35590, 0, 0, 0, 0, '', "Ghoul Explode (The Black Knight)"),
(13, 7, 67751, 0, 0,  1, 0, 67751, 0, 0, 1, 0, 0, '', "Ghoul Explode (The Black Knight)");

-- Gossip Menu GM options added to DB, the regular ones were already there... Please review....
DELETE FROM `gossip_menu_option` WHERE `MenuID`=@GOSSIP_MENU AND `OptionID` IN (4, 5, 6, 7, 8);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(@GOSSIP_MENU, 4, 0, '[GM] Start Grand Champions encounter, unskipped roleplaying', 0, 1, 1, 0, 0, 0, 0, '', 0, 0),
(@GOSSIP_MENU, 5, 0, '[GM] Start Grand Champions encounter, skipped roleplaying', 0, 1, 1, 0, 0, 0, 0, '', 0, 0),
(@GOSSIP_MENU, 6, 0, '[GM] Start Eadric the Pure encounter', 0, 1, 1, 0, 0, 0, 0, '', 0, 0),
(@GOSSIP_MENU, 7, 0, '[GM] Start Argent Confessor Paletress encounter', 0, 1, 1, 0, 0, 0, 0, '', 0, 0),
(@GOSSIP_MENU, 8, 0, '[GM] Start The Black Knight encounter', 0, 1, 1, 0, 0, 0, 0, '', 0, 0);
-- Death knight mount speed fixed.
UPDATE `creature_template` SET `speed_run` = '11.71429', `speed_walk` = 10 WHERE `creature_template`.`entry` = 35491;


-- death knight mount waypoints
DELETE FROM `waypoint_data` WHERE `id` = @KNIGHT_VEHICLE*10;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES (@KNIGHT_VEHICLE*10, 0, 766.99, 657.16, 457.43, 0, 0, 2, 0, 100, 0);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES (@KNIGHT_VEHICLE*10, 1, 747.28, 659.71, 440.49, 0, 0, 2, 0, 100, 0);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES (@KNIGHT_VEHICLE*10, 2, 730.03, 639.59, 428.16, 0, 0, 2, 0, 100, 0);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES (@KNIGHT_VEHICLE*10, 3, 721.13, 621.49, 423.16, 0, 0, 2, 0, 100, 0);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES (@KNIGHT_VEHICLE*10, 4, 731.72, 599.81, 421.99, 0, 0, 2, 0, 100, 0);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES (@KNIGHT_VEHICLE*10, 5, 753.71, 591.09, 420.63, 0, 0, 2, 0, 100, 0);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES (@KNIGHT_VEHICLE*10, 6, 776.53, 597.52, 418.05, 0, 0, 2, 0, 100, 0);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES (@KNIGHT_VEHICLE*10, 7, 787.38, 617.07, 417.49, 0, 0, 2, 0, 100, 0);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES (@KNIGHT_VEHICLE*10, 8, 777.06, 636.98, 416.57, 0, 0, 2, 0, 100, 0);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES (@KNIGHT_VEHICLE*10, 9, 760.6, 642.12, 414.71, 0, 0, 2, 0, 100, 0);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES (@KNIGHT_VEHICLE*10, 10, 752.58, 632.35, 411.63, 0, 0, 2, 0, 100, 0);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES (@KNIGHT_VEHICLE*10, 11, 748.89, 633.61, 415.24, 0, 0, 2, 0, 100, 0);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES (@KNIGHT_VEHICLE*10, 12, 740.42, 636.31, 418.32, 0, 0, 2, 0, 100, 0);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES (@KNIGHT_VEHICLE*10, 13, 727.49, 637.4, 422.24, 0, 0, 2, 0, 100, 0);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES (@KNIGHT_VEHICLE*10, 14, 716.59, 617.99, 422.24, 0, 0, 2, 0, 100, 0);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES (@KNIGHT_VEHICLE*10, 15, 727.18, 599.29, 422.24, 0, 0, 2, 0, 100, 0);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES (@KNIGHT_VEHICLE*10, 16, 746.63, 587.77, 422.24, 0, 0, 2, 0, 100, 0);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES (@KNIGHT_VEHICLE*10, 17, 765.6, 599.52, 422.24, 0, 0, 2, 0, 100, 0);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES (@KNIGHT_VEHICLE*10, 18, 777.01, 618.79, 422.24, 0, 0, 2, 0, 100, 0);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES (@KNIGHT_VEHICLE*10, 19, 761.84, 642.18, 422.24, 0, 0, 2, 0, 100, 0);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES (@KNIGHT_VEHICLE*10, 20, 746.09, 670.33, 429.68, 0, 0, 2, 0, 100, 0);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES (@KNIGHT_VEHICLE*10, 21, 748.02, 728.22, 466.68, 0, 0, 2, 0, 100, 0);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES (@KNIGHT_VEHICLE*10, 22, 779.44, 797.49, 477.79, 0, 0, 2, 0, 100, 0);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES (@KNIGHT_VEHICLE*10, 23, 859.14, 807.98, 477.79, 0, 0, 2, 0, 100, 0);

UPDATE `creature_template` SET `movementId` = @KNIGHT_VEHICLE*10 WHERE `creature_template`.`entry` = @KNIGHT_VEHICLE;
