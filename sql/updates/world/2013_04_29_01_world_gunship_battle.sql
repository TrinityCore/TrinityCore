-- Muradin & Saurfang
DELETE FROM `creature_template` WHERE `entry` IN (50004, 50006);
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES
(50004, 0, 0, 0, 0, 0, 11686, 0, 0, 0, 'High Overlord Saurfang', '', '', 0, 80, 80, 2, 1802, 1802, 0, 0, 0, 1, 1, 252, 357, 0, 304, '7.5', 2000, 0, 1, 33554432, 8, 0, 0, 0, 0, 0, 215, 320, 44, 7, 72, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 1000, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 2, '', 12340),
(50006, 0, 0, 0, 0, 0, 11686, 0, 0, 0, 'Muradin Bronzebeard', '', '', 10875, 83, 83, 2, 1802, 1802, 1, 1, '1.14286', 1, 1, 468, 702, 0, 175, '47.2', 2000, 2000, 1, 33554432, 8, 0, 0, 0, 0, 0, 374, 562, 140, 7, 76, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15284, 70309, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 175, 1, 1, 0, 0, 0, 0, 0, 0, 0, 164, 1, 0, 2, '', 12340);

-- Miscs
UPDATE `creature_template` SET `npcflag` = 1 WHERE `entry` IN (36939, 38156, 38637, 38638, 37184);

-- Templates del trash
UPDATE `creature_template` SET `faction_A` = 1801, `faction_H` = 1801, `baseattacktime` = 2000, `rangeattacktime` = 2000, `unit_flags` = 32832, `spell1` = 71339, `spell2` = 70161, `spell3` = 72539, `mechanic_immune_mask` = 73745 WHERE `entry` IN (36968, 38403, 38675, 38676);
UPDATE `creature_template` SET `faction_A` = 1802, `faction_H` = 1802, `baseattacktime` = 2000, `rangeattacktime` = 2000, `unit_flags` = 32832, `spell1` = 71335, `spell2` = 70162, `spell3` = 72566, `mechanic_immune_mask` = 73745 WHERE `entry` IN (36969, 38408, 38689, 38690);

-- Spawn for the sorcerer and the vindicator
DELETE FROM `creature` WHERE `id` IN (37003, 37026);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(200988, 37003, 631, 15, 1, 0, 0, -562.385, 2217.58, 199.969, 3.46228, 86400, 0, 0, 398434, 41690, 0, 0, 0, 0),
(201020, 37026, 631, 15, 1, 0, 0, -571.091, 2219.71, 199.969, 5.06842, 86400, 0, 0, 269600, 91600, 0, 0, 0, 0);

-- Scriptnames
UPDATE `creature_template` SET `ScriptName` = 'npc_muradin_gunship' WHERE `entry` = 36948;
UPDATE `creature_template` SET `ScriptName` = 'npc_saurfang_gunship' WHERE `entry` = 36939;
UPDATE `creature_template` SET `ScriptName` = 'npc_zafod_boombox' WHERE `entry` = 37184;
UPDATE `creature_template` SET `ScriptName` = 'npc_korkron_defender' WHERE `entry` = 37032;
UPDATE `creature_template` SET `ScriptName` = 'npc_korkron_primalist' WHERE `entry` = 37030;
UPDATE `creature_template` SET `ScriptName` = 'npc_skybreaker_vindicator' WHERE `entry` = 37003;
UPDATE `creature_template` SET `ScriptName` = 'npc_skybreaker_protector' WHERE `entry` = 36998;
UPDATE `creature_template` SET `ScriptName` = 'npc_icc_spire_frostwyrm' WHERE `entry` = 37230;
UPDATE `creature_template` SET `ScriptName` = 'npc_korkron_axethrower_rifleman' WHERE `entry` = 36968;
UPDATE `creature_template` SET `ScriptName` = 'npc_korkron_axethrower_rifleman' WHERE `entry` = 36969;
UPDATE `creature_template` SET `ScriptName` = 'npc_mortar_soldier_or_rocketeer', AIName = '' WHERE `entry` = 36982;
UPDATE `creature_template` SET `ScriptName` = 'npc_mortar_soldier_or_rocketeer', AIName = '' WHERE `entry` = 36978;
UPDATE `creature_template` SET `ScriptName` = 'npc_gunship_mage' WHERE `entry` = 37117;
UPDATE `creature_template` SET `ScriptName` = 'npc_gunship_mage' WHERE `entry` = 37116;
UPDATE `creature_template` SET `ScriptName` = 'npc_gunship_trigger' WHERE `entry` = 37547;
UPDATE `creature_template` SET `ScriptName` = 'npc_gunship_portal' WHERE `entry` = 37227;
UPDATE `creature_template` SET `ScriptName` = 'npc_marine_or_reaver' WHERE `entry` = 36957;
UPDATE `creature_template` SET `ScriptName` = 'npc_marine_or_reaver' WHERE `entry` = 36950;
UPDATE `creature_template` SET `ScriptName` = 'npc_sergeant' WHERE `entry` = 36960;
UPDATE `creature_template` SET `ScriptName` = 'npc_sergeant' WHERE `entry` = 36961;
UPDATE `creature_template` SET `ScriptName` = 'npc_gunship_skybreaker' WHERE `entry` = 37540;
UPDATE `creature_template` SET `ScriptName` = 'npc_gunship_orgrimmar' WHERE `entry` = 37215;
UPDATE `creature_template` SET `ScriptName` = 'npc_gunship_cannon' WHERE `entry` = 36838;
UPDATE `creature_template` SET `ScriptName` = 'npc_gunship_cannon' WHERE `entry` = 36839;
UPDATE `gameobject_template` SET `ScriptName` = 'transport_gunship' WHERE `entry` IN (201580, 201812);
UPDATE `item_template` SET ScriptName = 'item_icc_rocket_pack' WHERE entry = 49278;

-- Areatriggers Script
DELETE FROM `areatrigger_scripts` WHERE `entry` IN (5630, 5628);
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(5628,'at_icc_land_frostwyrm'),
(5630,'at_icc_land_frostwyrm');

-- Spell Scripts
DELETE FROM `spell_script_names` WHERE `spell_id` IN (70713, 68645, 69471, 69488, 69402, 70175, 71335, 71339);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
('70713', 'spell_icc_remove_rocket_pack'),
('68645', 'spell_rocket_pack'),
('69471', 'spell_gb_heat_drain'),
('69488', 'spell_gb_overheat_drain'),
('69402', 'spell_gb_incinerating_blast'),
('70175', 'spell_gb_incinerating_blast'),
('71335', 'spell_gb_burning_pitch'),
('71339', 'spell_gb_burning_pitch');

-- Transport
DELETE FROM transports WHERE entry IN (201580, 201581, 201811, 201812);
DELETE FROM creature WHERE id IN (37230, 36838, 36839, 36948, 36939);
DELETE FROM `creature_template_addon` WHERE (`entry`=37547);
UPDATE `creature_template` SET `flags_extra` = 130 WHERE `entry` = 37547;

-- Cannon template
UPDATE `creature_template` SET `exp` = 2, `VehicleId` = 554, `RegenHealth` = 0, `npcflag` = 16777216, `spell1` = 69399, `spell2` = 69401 WHERE entry = 36839;
UPDATE `creature_template` SET `exp` = 2, `VehicleId` = 554, `RegenHealth` = 0, `npcflag` = 16777216, `spell1` = 70172, `spell2` = 70174 WHERE entry = 36838;
DELETE FROM `npc_spellclick_spells` WHERE npc_entry IN (36838, 36839);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`) VALUES
('36838', '46598', '1'),
('36839', '46598', '1');
DELETE FROM `creature_template_addon` WHERE `entry` IN (36838, 36839);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(36838, 0, 0, 0, 1, 0, 69470),
(36839, 0, 0, 0, 1, 0, 69470);
UPDATE `creature_template` SET `difficulty_entry_1` = '38129',`difficulty_entry_2` = '38701', `difficulty_entry_3` = '38702' WHERE `entry` =37215;
UPDATE `creature_template` SET `faction_A` = 35, `faction_H` = 35, `minlevel` = 83, `maxlevel` = 83, `unit_flags` = 4, `flags_extra` = 2, `modelid1` = 1126, `modelid2` = 11686 WHERE `entry` IN (37215, 38129, 38701, 38702, 37540, 38128, 38699, 38700);

-- Fix for Cannons
UPDATE `creature_template` SET `difficulty_entry_1`=0 WHERE `entry`=36839 LIMIT 1;
UPDATE `creature_template` SET `speed_walk`=0 ,`speed_run`=0 WHERE `entry` IN (36839,36838);

-- Spell effects
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 71193 AND `spell_effect` = -71188;
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 71195 AND `spell_effect` = -71193;
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 68645 AND `spell_effect` = 69193;
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 73077 AND `spell_effect` = 69188;
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 73077 AND `spell_effect` = 68721;
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 69193 AND `spell_effect` = 69192;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(71193, -71188, 0, 'Gunship Battle - Veteran removes Experimented'),
(71195, -71193, 0, 'Gunship Battle - Elite removes Veteran'),
(73077, 69188, 2, 'Gunship Battle - Fix visual for Rocket Pack'),
(68645, 69193, 0, 'Gunship Battle - Fix visual for Rocket Pack'),
(69193, 69192, 0, 'Gunship Battle - Cast Rocket Burst when landing with Rocket Pack');

-- Spells
UPDATE `creature_template` SET `unit_flags` = 33554564, `flags_extra` = 2 WHERE `entry` IN (37044, 37041);
UPDATE `creature_template` SET `faction_A` = 1801, `faction_H` = 1801 WHERE `entry` = 37044;
UPDATE `creature_template` SET `faction_A` = 1802, `faction_H` = 1802 WHERE `entry` = 37041;
DELETE FROM `creature_template_addon` WHERE `entry` IN (37044, 37041);
SET @KORKRON := 37044;     -- Kor'kron Battle Standard
SET @SKYBREAKER := 37041;  -- Skybreaker Battle Standard
SET @HSPELL := 69809;
SET @ASPELL := 69808;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@KORKRON, @SKYBREAKER);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (@KORKRON, @SKYBREAKER);
INSERT INTO `smart_scripts`
(`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`)
VALUES
(@KORKRON ,0,0,0,25,0,100,1,0,0,0,0,11,@HSPELL,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Kor''kron Battle Standard - On spawn & reset - Cast spell 69809'),
(@SKYBREAKER,0,0,0,25,0,100,1,0,0,0,0,11,@ASPELL,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Skybreaker Battle Standard - On spawn & reset - Cast spell 69808');

-- Creature Text
SET @MURADIN := 36948;
SET @OVERLORD := 36939;
SET @MURADIN_INVISIBLE := 50006;
SET @OVERLORD_INVISIBLE := 50004;
SET @PRIMALIST := 37030;
SET @INVOKER := 37033;
SET @DEFENDER := 37032;
SET @VINDICATOR := 37003;
SET @SORCERER := 37026;
SET @PROTECTOR := 36998;
SET @FROSTWYRM := 37230;
SET @SOUNDID :=0;

DELETE FROM `creature_text` WHERE `entry` IN (36948, 36939, 37030, 37033, 37032, 37003, 37026, 36998, 37230, 50004, 50006);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@MURADIN_INVISIBLE,  0, 0, 'Move yer jalopy or we''ll blow it out of the sky, orc! The Horde''s got no business here!', 14, 0, 0, 0, 0, 16969, 'Muradin Bronzebeard - INVISIBLE_0'),
(@MURADIN_INVISIBLE,  1, 0, 'Marines, Sergeants, attack!', 14, 0, 0, 0, 0, 16956, 'Muradin Bronzebeard - INVISIBLE_1'),
(@MURADIN,  0, 0, 'Fire up the engines! We got a meetin'' with destiny, lads!', 14, 0, 100, 0, 0, 16962, 'Muradin Bronzebeard - SAY_INTRO_ALLIANCE_0'),
(@MURADIN,  1, 0, 'Hold on to yer hats!', 14, 0, 100, 0, 0, 16963, 'Muradin Bronzebeard - SAY_INTRO_ALLIANCE_1'),
(@MURADIN,  2, 0, 'What in the world is that? Grab me spyglass, crewman!', 14, 0, 100, 0, 0, 16964, 'Muradin Bronzebeard - SAY_INTRO_ALLIANCE_2'),
(@MURADIN,  3, 0, 'By me own beard! HORDE SAILIN'' IN FAST ''N HOT!', 14, 0, 100, 0, 0, 16965, 'Muradin Bronzebeard - SAY_INTRO_ALLIANCE_3'),
(@MURADIN,  4, 0, 'EVASIVE ACTION! MAN THE GUNS!', 14, 0, 100, 0, 0, 16966, 'Muradin Bronzebeard - SAY_INTRO_ALLIANCE_4'),
(@MURADIN,  5, 0, 'Cowardly dogs! Ye blindsided us!', 14, 0, 100, 0, 0, 16967, 'Muradin Bronzebeard - SAY_INTRO_ALLIANCE_5'),
(@MURADIN,  6, 0, 'Not me battle? I dunnae who ye? think ye are, mister, but I got a score to settle with Arthas and yer not gettin'' in me way! FIRE ALL GUNS! FIRE! FIRE!', 14, 0, 100, 0, 0, 16968, 'Muradin Bronzebeard - SAY_INTRO_ALLIANCE_7'),
(@MURADIN,  7, 0, 'Move yer jalopy or we''ll blow it out of the sky, orc! The Horde''s got no business here!', 14, 0, 100, 0, 0, 16969, 'Muradin Bronzebeard - SAY_INTRO_HORDE_3'),
(@MURADIN,  8, 0, 'What''s this then?! Ye won''t be takin'' this son o'' Ironforge''s vessel without a fight!.', 14, 0, 100, 0, 0, 16958, 'Muradin Bronzebeard - SAY_BOARDING_SKYBREAKER_1'),
(@MURADIN,  9, 0, 'Marines, Sergeants, attack!', 14, 0, 100, 0, 0, 16956, 'Muradin Bronzebeard - SAY_BOARDING_ORGRIMS_HAMMER_0'),
(@MURADIN, 10, 0, 'Riflemen, shoot faster!', 14, 0, 100, 0, 0, 16954, 'Muradin Bronzebeard - SAY_NEW_RIFLEMEN_SPAWNED'),
(@MURADIN, 11, 0, 'Mortar team, reload!', 14, 0, 100, 0, 0, 16955, 'Muradin Bronzebeard - SAY_NEW_MORTAR_TEAM_SPAWNED'),
(@MURADIN, 12, 0, 'We''re taking hull damage, get a sorcerer out here to shut down those cannons!', 14, 0, 100, 0, 0, 16957, 'Muradin Bronzebeard - SAY_NEW_MAGE_SPAWNED'),
(@MURADIN, 13, 0, 'Don''t say I didn''t warn ya, scoundrels! Onward, brothers and sisters!', 14, 0, 100, 0, 0, 16959, 'Muradin Bronzebeard - SAY_ALLIANCE_VICTORY'),
(@MURADIN, 14, 0, 'Captain Bartlett, get us out of here! We''re taken too much damage to stay afloat!', 14, 0, 100, 0, 0, 16960, 'Muradin Bronzebeard - SAY_ALLIANCE_DEFEAT'),
(@OVERLORD_INVISIBLE, 0, 0, 'This is not your battle, dwarf. Back down or we will be forced to destroy your ship.', 14, 0, 0, 0, 0, 17093, 'High Overlord Saurfang - INVISIBLE_0'),
(@OVERLORD_INVISIBLE, 1, 0, 'Reavers, Sergeants, attack!', 14, 0, 0, 0, 0, 17081, 'High Overlord Saurfang - INVISIBLE_1'),
(@OVERLORD, 0, 0, 'Rise up, sons and daughters of the Horde! Today we battle a hated enemy of the Horde! LOK''TAR OGAR!', 14, 0, 100, 0, 0, 17087, 'High Overlord Saurfang - SAY_INTRO_HORDE_0'),
(@OVERLORD, 1, 0, 'Kor''kron, take us out!', 14, 0, 100, 0, 0, 17088, 'High Overlord Saurfang - SAY_INTRO_HORDE_1_1'),
(@OVERLORD, 2, 0, 'What is that?! Something approaching in the distance!', 14, 0, 100, 0, 0, 17089, 'High Overlord Saurfang - SAY_INTRO_HORDE_1'),
(@OVERLORD, 3, 0, 'ALLIANCE GUNSHIP! ALL HANDS ON DECK!', 14, 0, 100, 0, 0, 17090, 'High Overlord Saurfang - SAY_INTRO_HORDE_2'),
(@OVERLORD, 4, 0, 'You will know our business soon! KOR''KRON, ANNIHILATE THEM!', 14, 0, 100, 0, 0, 17092, 'High Overlord Saurfang - SAY_INTRO_HORDE_4'),
(@OVERLORD, 5, 0, 'Reavers, Sergeants, attack!', 14, 0, 100, 0, 0, 17081, 'High Overlord Saurfang - SAY_BOARDING_SKYBREAKER_0'),
(@OVERLORD, 6, 0, 'You DARE board my ship? Your death will come swiftly.', 14, 0, 100, 0, 0, 17083, 'High Overlord Saurfang - SAY_BOARDING_ORGRIMS_HAMMER_1'),
(@OVERLORD, 7, 0, 'Axethrowers, hurl faster!', 14, 0, 100, 0, 0, 17079, 'High Overlord Saurfang - SAY_NEW_AXETHROWER_SPAWNED'),
(@OVERLORD, 8, 0, 'Rocketeers, reload!', 14, 0, 100, 0, 0, 17080, 'High Overlord Saurfang - SAY_NEW_ROCKETEERS_SPAWNED'),
(@OVERLORD, 9, 0, 'We''re taking hull damage, get a battle-mage out here to shut down those cannons!', 14, 0, 100, 0, 0, 17082, 'High Overlord Saurfang - SAY_NEW_BATTLE_MAGE_SPAWNED'),
(@OVERLORD, 10, 0, 'The Alliance falter. Onward to the Lich King!', 14, 0, 100, 0, 0, 17084, 'High Overlord Saurfang - SAY_HORDE_VICTORY'),
(@OVERLORD, 11, 0, 'Damage control! Put those fires out! You haven''t seen the last of the Horde!', 14, 0, 100, 0, 0, 17085, 'High Overlord Saurfang - SAY_HORDE_DEFEAT'),
(@OVERLORD, 12, 0, 'This is not your battle, dwarf. Back down or we will be forced to destroy your ship.', 14, 0, 100, 0, 0, 17093, 'High Overlord Saurfang - SAY_INTRO_ALLIANCE_6'),

(@PRIMALIST,0, 0, 'Thank the spirits for you, brothers and sisters. The Skybreaker has already left. Quickly now, to Orgrim''s Hammer! If you leave soon, you may be able to catch them.', 12, 0, 100, 0, 0, @SOUNDID, 'Kor''kron Primalist - SAY_FIRST_SQUAD_RESCUED_HORDE_0'),
(@INVOKER,  0, 0, 'This should be helpin''ya!', 12, 0, 100, 0, 0, @SOUNDID, 'Kor''kron Invoker - SAY_FIRST_SQUAD_RESCUED_HORDE_1'),
(@INVOKER,  1, 0, '%s summons a Kor''kron Battle Standard.', 16, 0, 100, 0, 0, @SOUNDID, 'Kor''kron Invoker - SAY_SUMMON_BATTLE_STANDARD'),
(@DEFENDER, 0, 0, 'Aka''Magosh, brave warriors. The alliance is in great number here.', 12, 0, 100, 0, 0, @SOUNDID, 'Kor''kron Defender - SAY_SECOND_SQUAD_RESCUED_HORDE_0'),
(@DEFENDER, 1, 0, 'Captain Saurfang will be pleased to see you aboard Orgrim''s Hammer. Make haste, we will secure the area until you are ready for take-off.', 12, 0, 100, 0, 0, @SOUNDID, 'Kor''kron Defender - SAY_SECOND_SQUAD_RESCUED_HORDE_1'),
(@DEFENDER, 2, 0, 'A screeching cry pierces the air above!',41, 0, 100, 0, 0, @SOUNDID, 'Frostwyrm - SAY_FROSTWYRM_SUMMON_0'),
(@VINDICATOR, 0, 0, 'Thank goodness you arrived when you did, heroes. Orgrim''s Hammer has already left. Quickly now, to The Skybreaker! If you leave soon, you may be able to catch them.', 12, 0, 100, 0, 0, @SOUNDID, 'Skybreaker Vindicator - SAY_FIRST_SQUAD_RESCUED_ALLIANCE_0'),
(@SORCERER, 0, 0, 'This ought to help!', 12, 0, 100, 0, 0, @SOUNDID, 'Skybreaker Sorcerer - SAY_FIRST_SQUAD_RESCUED_ALLIANCE_1'),
(@SORCERER, 1, 0, '%s summons a Skybreaker Battle Standard.', 16, 0, 100, 0, 0, @SOUNDID, 'Skybreaker Sorcerer - SAY_SUMMON_BATTLE_STANDARD'),
(@PROTECTOR,0, 0, 'You have my thanks. We were outnumbered until you arrived.', 12, 0, 100, 0, 0, @SOUNDID, 'Skybreaker Protector - SAY_SECOND_SQUAD_RESCUED_ALLIANCE_0'),
(@PROTECTOR,1, 0, 'Captain Muradin is waiting aboard The Skybreaker. We''ll secure the area until you are ready for take off.', 12, 0, 100, 0, 0, @SOUNDID, 'Skybreaker Protector - SAY_SECOND_SQUAD_RESCUED_ALLIANCE_1'),
(@PROTECTOR,2, 0, 'Skybreaker infantry, hold position!', 12, 0, 100, 0, 0, @SOUNDID, 'Skybreaker Protector - SAY_SECOND_SQUAD_RESCUED_ALLIANCE_2'),
(@PROTECTOR,3, 0, 'A screeching cry pierces the air above!',41, 0, 100, 0, 0, @SOUNDID, 'Frostwyrm - SAY_FROSTWYRM_SUMMON_0'),
(@FROSTWYRM,0, 0, 'A Spire Frostwyrm lands just before Orgrim''s Hammer.', 16, 0, 100, 0, 0, @SOUNDID, 'Frostwyrm - SAY_FROSTWYRM_LAND_H_1'),
(@FROSTWYRM,1, 0, 'A Spire Frostwyrm lands just before The Skybreaker. ', 16, 0, 100, 0, 0, @SOUNDID, 'Frostwyrm - SAY_FROSTWYRM_LAND_A_2');



-- CONDITIONS
-- Additionnal Conditions (by 2010phenix - https://github.com/2010phenix)
SET @ENTRYA := 37540;
SET @ENTRYH := 37215;
SET @ENTRYA10H := 38128;
SET @ENTRYH10H := 38129;
SET @ENTRYA25 := 38699;
SET @ENTRYH25 := 38701;
SET @ENTRYA25H := 38700;
SET @ENTRYH25H := 38702;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (69400, 70173, 69402, 70175, 70374, 70383, 72959, 69705);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`) VALUES
('13', '69400', '18', '1', @ENTRYA),    -- Horde Cannon (Cannon Blast) set to hit only Skybreaker (effect 2)
('13', '69400', '18', '1', @ENTRYA10H), -- Horde Cannon (Cannon Blast) set to hit only Skybreaker - 10H (effect 2)
('13', '69400', '18', '1', @ENTRYA25),  -- Horde Cannon (Cannon Blast) set to hit only Skybreaker - 25Normal (effect 2)
('13', '69400', '18', '1', @ENTRYA25H), -- Horde Cannon (Cannon Blast) set to hit only Skybreaker -- 25H (effect 2)
('13', '70173', '18', '1', @ENTRYH),    -- Alliance Cannon (Cannon Blast) set to hit only Orgrimms Hammer (effect 2)
('13', '70173', '18', '1', @ENTRYH10H), -- Alliance Cannon (Cannon Blast) set to hit only Orgrimms Hammer 10H (effect 2)
('13', '70173', '18', '1', @ENTRYH25),  -- Alliance Cannon (Cannon Blast) set to hit only Orgrimms Hammer - 25Normal (effect 2)
('13', '70173', '18', '1', @ENTRYH25H), -- Alliance Cannon (Cannon Blast) set to hit only Orgrimms Hammer -- 25H (effect 2)
('13', '69402', '18', '1', @ENTRYA),    -- Horde Cannon (Incinerating Blast) set to hit only Skybreaker (effect 2)
('13', '69402', '18', '1', @ENTRYA10H), -- Horde Cannon (Incinerating Blast) set to hit only Skybreaker 10H(effect 2)
('13', '69402', '18', '1', @ENTRYA25),  -- Horde Cannon (Incinerating Blast) set to hit only Skybreaker - 25Normal (effect 2)
('13', '69402', '18', '1', @ENTRYA25H), -- Horde Cannon (Incinerating Blast) set to hit only Skybreaker -- 25H (effect 2)
('13', '70175', '18', '1', @ENTRYH),    -- Alliance Cannon (Incinerating Blast) set to hit only Orgrimms Hammer (effect 2)
('13', '70175', '18', '1', @ENTRYH10H), -- Alliance Cannon (Incinerating Blast) set to hit only Orgrimms Hammer 10H (effect 2)
('13', '70175', '18', '1', @ENTRYH25),  -- Alliance Cannon (Incinerating Blast) set to hit only Orgrimms Hammer - 25Normal (effect 2)
('13', '70175', '18', '1', @ENTRYH25H), -- Alliance Cannon (Incinerating Blast) set to hit only Orgrimms Hammer -- 25H (effect 2)
('13', '70374', '18', '1', @ENTRYA),    -- Burning Pitch
('13', '70374', '18', '1', @ENTRYA10H), -- Burning Pitch
('13', '70374', '18', '1', @ENTRYA25),  -- Burning Pitch
('13', '70374', '18', '1', @ENTRYA25H), -- Burning Pitch
('13', '70383', '18', '1', @ENTRYH),    -- Burning Pitch
('13', '70383', '18', '1', @ENTRYH10H), -- Burning Pitch
('13', '70383', '18', '1', @ENTRYH25),  -- Burning Pitch
('13', '70383', '18', '1', @ENTRYH25H), -- Burning Pitch
('13', '72959', '18', '1', 0),          -- Achievement (Radius: 50000 yards)
('13', '69705' ,'18', '1', 36838),      -- Gunship Battle - Spell 69705 (Below Zero) target creature 36838
('13', '69705' ,'18', '1', 36839);      -- Gunship Battle - Spell 69705 (Below Zero) target creature 36839

-- Update condition by TrinityCore:
DELETE FROM conditions WHERE SourceTypeOrReferenceId=13 AND SourceEntry IN (69400, 70173, 69402, 70175, 70374, 70383, 69705, 72959);
INSERT INTO conditions (SourceTypeOrReferenceId, SourceGroup, SourceEntry, SourceId, ElseGroup, ConditionTypeOrReference, ConditionTarget, ConditionValue1, ConditionValue2, ConditionValue3, NegativeCondition, ErrorTextId, ScriptName, Comment) VALUES
-- Alliance
(13, 3, 69400, 0, 0, 31, 0, 3, 37540, 0, 0, 0, '', NULL),
(13, 1, 70374, 0, 0, 31, 0, 3, 37540, 0, 0, 0, '', NULL),
(13, 3, 69402, 0, 0, 31, 0, 3, 37540, 0, 0, 0, '', NULL),
(13, 1, 69705, 0, 0, 31, 0, 3, 36838, 0, 0, 0, '', NULL),
-- Horde
(13, 3, 70175, 0, 1, 31, 0, 3, 37215, 0, 0, 0, '', NULL),
(13, 1, 70383, 0, 1, 31, 0, 3, 37215, 0, 0, 0, '', NULL),
(13, 3, 70173, 0, 1, 31, 0, 3, 37215, 0, 0, 0, '', NULL),
(13, 1, 69705, 0, 1, 31, 0, 3, 36839, 0, 0, 0, '', NULL);



-- Loot templates
-- Fix by TrinityCore
-- Set Variables
SET @Gunship10N := 28057; -- Data1 for 201872 & 202177
SET @Gunship10H := 28045; -- Data1 for 201873 & 202178
SET @Gunship25N := 28072; -- Data1 for 201874 & 202179
SET @Gunship25H := 28090; -- Data1 for 201875 & 202180
SET @emblem := 49426; -- Emblem of Frost
SET @SfShard := 50274; -- Shadowfrost Shard
SET @PriSar := 49908; -- Primordial Saronite
-- Dug up the old references i created for UP34:
SET @Ref10J := 34329;
SET @Ref25J := 34251;
SET @RefJ10H := 34263;
SET @RefJ25H := 34275;

-- Gunship_Armory10N_reference
DELETE FROM `reference_loot_template` WHERE `entry` IN (@Ref10J,@Ref25J,@RefJ10H,@RefJ25H);
INSERT INTO `reference_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(@Ref10J,50791,0,1,1,1,1), -- Saronite Gargoyle Cloak
(@Ref10J,50795,0,1,1,1,1), -- Cord of Dark Suffering
(@Ref10J,50794,0,1,1,1,1), -- Neverending Winter
(@Ref10J,50787,0,1,1,1,1), -- Frost Giant's Cleaver
(@Ref10J,50793,0,1,1,1,1), -- Midnight Sun
(@Ref10J,50788,0,1,1,1,1), -- Bone Drake's Enameled Boots
(@Ref10J,50792,0,1,1,1,1), -- Pauldrons of Lost Hope
(@Ref10J,50340,0,1,1,1,1), -- Muradin's Spyglass
(@Ref10J,50797,0,1,1,1,1), -- Ice-Reinforced Vrykul Helm
(@Ref10J,50790,0,1,1,1,1), -- Abomination's Bloody Ring
(@Ref10J,50789,0,1,1,1,1), -- Icecrown Rampart Bracers
(@Ref10J,50796,0,1,1,1,1), -- Bracers of Pale Illumination
-- Gunship_Armory25N_reference
(@Ref25J,50011,0,1,1,1,1), -- Gunship Captain's Mittens
(@Ref25J,50002,0,1,1,1,1), -- Polar Bear Claw Bracers
(@Ref25J,50006,0,1,1,1,1), -- Corp'rethar Ceremonial Crown
(@Ref25J,50010,0,1,1,1,1), -- Waistband of Righteous Fury
(@Ref25J,50003,0,1,1,1,1), -- Boneguard Commander's Pauldrons
(@Ref25J,50000,0,1,1,1,1), -- Scourge Hunter's Vambraces
(@Ref25J,50359,0,1,1,1,1), -- Althor's Abacus
(@Ref25J,50352,0,1,1,1,1), -- Corpse Tongue Coin
(@Ref25J,49999,0,1,1,1,1), -- Skeleton Lord's Circle
(@Ref25J,50009,0,1,1,1,1), -- Boots of Unnatural Growth
(@Ref25J,50008,0,1,1,1,1), -- Ring of Rapid Ascent
(@Ref25J,49998,0,1,1,1,1), -- Shadowvault Slayer's Cloak
(@Ref25J,50005,0,1,1,1,1), -- Amulet of the Silent Eulogy
(@Ref25J,50411,0,1,1,1,1), -- Scourgeborne Waraxe
(@Ref25J,50001,0,1,1,1,1), -- Ikfirus's Sack of Wonder
-- Gunship_Armory10H_reference
(@RefJ10H,51912,0,1,1,1,1), -- Saronite Gargoyle Cloak (heroic)
(@RefJ10H,51908,0,1,1,1,1), -- Cord of Dark Suffering (heroic)
(@RefJ10H,51909,0,1,1,1,1), -- Neverending Winter (heroic)
(@RefJ10H,51916,0,1,1,1,1), -- Frost Giant's Cleaver (heroic)
(@RefJ10H,51910,0,1,1,1,1), -- Midnight Sun (heroic)
(@RefJ10H,51915,0,1,1,1,1), -- Bone Drake's Enameled Boots (heroic)
(@RefJ10H,51911,0,1,1,1,1), -- Pauldrons of Lost Hope (heroic)
(@RefJ10H,50345,0,1,1,1,1), -- Muradin's Spyglass (heroic)
(@RefJ10H,51906,0,1,1,1,1), -- Ice-Reinforced Vrykul Helm (heroic)
(@RefJ10H,51913,0,1,1,1,1), -- Abomination's Bloody Ring (heroic)
(@RefJ10H,51914,0,1,1,1,1), -- Icecrown Rampart Bracers (heroic)
(@RefJ10H,51907,0,1,1,1,1), -- Bracers of Pale Illumination (heroic)
-- Gunship_Armory25H_reference
(@RefJ25H,50663,0,1,1,1,1), -- Gunship Captain's Mittens (heroic)
(@RefJ25H,50659,0,1,1,1,1), -- Polar Bear Claw Bracers (heroic)
(@RefJ25H,50661,0,1,1,1,1), -- Corp'rethar Ceremonial Crown (heroic)
(@RefJ25H,50667,0,1,1,1,1), -- Waistband of Righteous Fury (heroic)
(@RefJ25H,50660,0,1,1,1,1), -- Boneguard Commander's Pauldrons (heroic)
(@RefJ25H,50655,0,1,1,1,1), -- Scourge Hunter's Vambraces (heroic)
(@RefJ25H,50366,0,1,1,1,1), -- Althor's Abacus (heroic)
(@RefJ25H,50349,0,1,1,1,1), -- Corpse Tongue Coin (heroic)
(@RefJ25H,50657,0,1,1,1,1), -- Skeleton Lord's Circle (heroic)
(@RefJ25H,50665,0,1,1,1,1), -- Boots of Unnatural Growth (heroic)
(@RefJ25H,50664,0,1,1,1,1), -- Ring of Rapid Ascent (heroic)
(@RefJ25H,50653,0,1,1,1,1), -- Shadowvault Slayer's Cloak (heroic)
(@RefJ25H,50658,0,1,1,1,1), -- Amulet of the Silent Eulogy (heroic)
(@RefJ25H,50654,0,1,1,1,1), -- Scourgeborne Waraxe (heroic)
(@RefJ25H,50656,0,1,1,1,1); -- Ikfirus's Sack of Wonder (heroic)

-- Bind the refs to the objects
DELETE FROM `gameobject_loot_template` WHERE `entry` IN (@Gunship10N,@Gunship10H,@Gunship25N,@Gunship25H);
INSERT INTO `gameobject_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- Gunship10N
(@Gunship10N,@emblem,100,1,0,2,2), -- Gunship Armory 2xemblems 10N
(@Gunship10N,1,100,1,0,-@Ref10J,2), -- 2 from reference 10Normal
-- Gunship25N
(@Gunship25N,@emblem,100,1,0,2,2), -- Gunship Armory 2xemblems 25N
(@Gunship25N,1,100,1,0,-@Ref25J,2), -- 3 from reference 25Normal
(@Gunship25N,@SfShard,-35,1,0,1,1), -- Shadowfrost Shard @ 38% chance
(@Gunship25N,@PriSar,38,1,0,1,1), -- Primordial Saronite @ 10% chance
-- Gunship10H
(@Gunship10H,@emblem,100,1,0,2,2), -- Gunship Armory 2xemblems 10H
(@Gunship10H,1,100,1,0,-@RefJ10H,2), -- 2 from reference 10Heroic
(@Gunship10H,@PriSar,38,1,0,1,1), -- Primordial Saronite @ 38% chance
-- Gunship25H
(@Gunship25H,@emblem,100,1,0,2,2), -- Gunship Armory 2xemblems 25H
(@Gunship25H,1,100,1,0,-@RefJ25H,2), -- 3 from reference 25Heroic
(@Gunship25H,@SfShard,-75,1,0,1,1), -- Shadowfrost Shard @ 75% chance
(@Gunship25H,@PriSar,50,1,0,1,1); -- Primordial Saronite @ 50% chance

SET @Twins := 34329; 
SET @emblem := 49426;
DELETE FROM `reference_loot_template` WHERE `entry`=@Twins;
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(@Twins,47296,0,1,1,1,1), -- Greaves of Ruthless Judgment
(@Twins,47297,0,1,1,1,1), -- The Executioner's Vice
(@Twins,47298,0,1,1,1,1), -- Armguards of the Shieldmaiden
(@Twins,47299,0,1,1,1,1), -- Belt of the Pitiless Killer
(@Twins,47300,0,1,1,1,1), -- Gouge of the Frigid Heart
(@Twins,47301,0,1,1,1,1), -- Skyweaver Vestments
(@Twins,47302,0,1,1,1,1), -- Twin's Pact
(@Twins,47303,0,1,1,1,1), -- Death's Choice
(@Twins,47304,0,1,1,1,1), -- Legplates of Ascension
(@Twins,47305,0,1,1,1,1); -- Legionnaire's Gorget
SET @Gunship10N := 28057; -- Data1 for 201872 & 202177
SET @Ref10J := 12036;
-- Gunship_Armory10N_reference
DELETE FROM `reference_loot_template` WHERE `entry`=@Ref10J;
INSERT INTO `reference_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(@Ref10J,50791,0,1,1,1,1), -- Saronite Gargoyle Cloak
(@Ref10J,50795,0,1,1,1,1), -- Cord of Dark Suffering
(@Ref10J,50794,0,1,1,1,1), -- Neverending Winter
(@Ref10J,50787,0,1,1,1,1), -- Frost Giant's Cleaver
(@Ref10J,50793,0,1,1,1,1), -- Midnight Sun
(@Ref10J,50788,0,1,1,1,1), -- Bone Drake's Enameled Boots
(@Ref10J,50792,0,1,1,1,1), -- Pauldrons of Lost Hope
(@Ref10J,50340,0,1,1,1,1), -- Muradin's Spyglass
(@Ref10J,50797,0,1,1,1,1), -- Ice-Reinforced Vrykul Helm
(@Ref10J,50790,0,1,1,1,1), -- Abomination's Bloody Ring
(@Ref10J,50789,0,1,1,1,1), -- Icecrown Rampart Bracers
(@Ref10J,50796,0,1,1,1,1); -- Bracers of Pale Illumination
-- Bind the refs to the objects
DELETE FROM `gameobject_loot_template` WHERE `entry`=@Gunship10N;
INSERT INTO `gameobject_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- Gunship10N
(@Gunship10N,@emblem,100,1,0,2,2), -- Gunship Armory 2xemblems 10N
(@Gunship10N,1,100,1,0,-@Ref10J,2); -- 2 from reference 10Normal

DELETE FROM `creature_addon` WHERE `guid` IN (83459,78383,81170,81165,81531);
DELETE FROM `gameobject_loot_template` WHERE `entry` IN (28045,28057,28072,28090);
DELETE FROM `reference_loot_template` WHERE `entry` IN (34329,12036,34251,34263,34275);

-- Make Muradin and Saufangs unattackable and unable to attack players (All difficulty modes)
UPDATE `creature_template` SET `unit_flags`=2, `flags_extra`=2 WHERE `entry`=36948;
UPDATE `creature_template` SET `unit_flags`=2, `flags_extra`=2 WHERE `entry`=36939;
UPDATE `creature_template` SET `unit_flags`=2, `flags_extra`=2 WHERE `entry`=38156;
UPDATE `creature_template` SET `unit_flags`=2, `flags_extra`=2 WHERE `entry`=38638;
UPDATE `creature_template` SET `unit_flags`=2, `flags_extra`=2 WHERE `entry`=38637;
UPDATE `creature_template` SET `unit_flags`=2, `flags_extra`=2 WHERE `entry`=38157;
UPDATE `creature_template` SET `unit_flags`=2, `flags_extra`=2 WHERE `entry`=38639;
UPDATE `creature_template` SET `unit_flags`=2, `flags_extra`=2 WHERE `entry`=38640;

-- Prevent players from exploiting the Rocket pack item outside of raid
UPDATE `item_template` SET `area` = 4812 WHERE `entry` = 49278;
UPDATE `item_template` SET `map` = 631 WHERE `entry` = 49278;
