-- Quest and quest givers removed in patch 7.0.3
-- Human starting area (Northshire Valley)

-- Marshal Mcbride (197) no longer starts/ends these quests:
DELETE FROM `creature_queststarter` WHERE `id`= 197 AND `quest` IN
(3100,  -- Simple Letter
 3101,  -- Consecrated Letter
 3102,  -- Encrypted Letter
 3103,  -- Hallowed Letter
 3104,  -- Glyphic Letter
 3105,  -- Tainted Letter
26910); -- Etched Letter

DELETE FROM `creature_questender` WHERE `id`= 197 AND `quest` IN
(   7,  -- [DEPRECATED] Kobold Camp Cleanup
   15,  -- [DEPRECATED] Investigate Echo Ridge
   21,  -- [DEPRECATED] Skirmish at Echo Ridge
  783,  -- [DEPRECATED] A Threat Within
14032,  -- Kobold Camp Cleanup [Programming Test]
26392); -- Voucher of Bravery

-- These NPCs no longer start the following obsolete quests:
DELETE FROM `creature_queststarter` WHERE `id` = 198 AND `quest` = 26916; -- Khelden Bremen    <Mage Trainer>,    Quest:Mastering the Arcane
DELETE FROM `creature_queststarter` WHERE `id` = 375 AND `quest` = 26919; -- Priestess Anetta  <Priest Trainer>,  Quest:Learning the Word
DELETE FROM `creature_queststarter` WHERE `id` = 459 AND `quest` = 26914; -- Drusilla La Salle <Warlock Trainer>, Quest:Corruption
DELETE FROM `creature_queststarter` WHERE `id` = 911 AND `quest` = 26913; -- Llane Beshere     <Warrior Trainer>, Quest:Charging into Battle
DELETE FROM `creature_queststarter` WHERE `id` = 915 AND `quest` = 26915; -- Jorik Kerridan    <Rogue Trainer>,   Quest:The Deepest Cut
DELETE FROM `creature_queststarter` WHERE `id` = 925 AND `quest` = 26918; -- Brother Sammuel   <Paladin Trainer>, Quest:The Power of the Light
DELETE FROM `creature_queststarter` WHERE `id`= 43278 AND `quest`= 26917; -- Ashley Bank       <Hunter Trainer>,  Quest:The Hunter's Path

-- These NPCs no longer end the following obsolete quests:
DELETE FROM `creature_questender` WHERE `id` =  198 AND `quest` IN ( 3104,26916); -- Quests:Glyphic Letter,Mastering the Arcane
DELETE FROM `creature_questender` WHERE `id` =  375 AND `quest` IN ( 3103,26919); -- Quests:Hallowed Letter,Learning the Word
DELETE FROM `creature_questender` WHERE `id` =  459 AND `quest` IN ( 1598,3105,26151,26914); -- Quests:The Stolen Tome,Tainted Letter,Dark Letter,Corruption
DELETE FROM `creature_questender` WHERE `id` =  911 AND `quest` IN ( 3100,26913); -- Quests:Simple Letter,Charging into Battle
DELETE FROM `creature_questender` WHERE `id` =  915 AND `quest` IN ( 3102,26915); -- Quests:Encrypted Letter,The Deepest Cut
DELETE FROM `creature_questender` WHERE `id` =  925 AND `quest` IN ( 3101,26918); -- Quests:Consecrated Letter,The Power of the Light
DELETE FROM `creature_questender` WHERE `id`= 43278 AND `quest` IN (26910,26917); -- Quests:

-- These quests are obsolete and need to be disabled:
DELETE FROM `disables` WHERE `sourceType`= 1 AND `entry` IN (3100,3101,3102,3103,3104,3105,26910,26913,26914,26915,26916,26917,26918,26919);
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES
(1,  3100, 0, '', '', 'Obsolete quest: Simple Letter'),
(1,  3101, 0, '', '', 'Obsolete quest: Consecrated Letter'),
(1,  3102, 0, '', '', 'Obsolete quest: Encrypted Letter'),
(1,  3103, 0, '', '', 'Obsolete quest: Hallowed Letter'),
(1,  3104, 0, '', '', 'Obsolete quest: Glyphic Letter'),
(1,  3105, 0, '', '', 'Obsolete quest: Tainted Letter'),
(1, 26910, 0, '', '', 'Obsolete quest: Etched Letter'),
(1, 26913, 0, '', '', 'Obsolete quest: Charging into Battle'),
(1, 26914, 0, '', '', 'Obsolete quest: Corruption'),
(1, 26915, 0, '', '', 'Obsolete quest: The Deepest Cut'),
(1, 26916, 0, '', '', 'Obsolete quest: Mastering the Arcane'),
(1, 26917, 0, '', '', 'Obsolete quest: The Hunter\'s Path'),
(1, 26918, 0, '', '', 'Obsolete quest: The Power of the Light'),
(1, 26919, 0, '', '', 'Obsolete quest: Learning the Word');

-- Stormwind Royal Guard SAI
SET @ENTRY := 42218;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Stormwind Royal Guard - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,4,0,100,0,0,0,0,0,28,78855,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind Royal Guard - On aggro - Remove aura"),
(@ENTRY,0,2,0,34,0,100,0,2,58,0,0,41,0,0,0,0,0,0,11,42218,30,0,0,0,0,0,"Stormwind Royal Guard - On movement informer - despawn all guars");

DELETE FROM creature WHERE guid IN (177929,177930,177931,177932);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES 
('177929', '42218', '0', '0', '0', '1', '0', '0', '0', '0', '-9027.75', '-94.864', '87.1555', '0.732427', '120', '0', '0', '1', '0', '2', '0', '0', '0', '0', '0', '', '0'),
('177930', '42218', '0', '0', '0', '1', '0', '0', '0', '0', '-9027.75', '-91.864', '87.1555', '4.57492', '120', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', '', '0'),
('177931', '42218', '0', '0', '0', '1', '0', '0', '0', '0', '-9024.75', '-94.864', '87.1555', '4.83123', '120', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', '', '0'),
('177932', '42218', '0', '0', '0', '1', '0', '0', '0', '0', '-9024.75', '-91.864', '87.1555', '4.74869', '120', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', '', '0');
DELETE FROM creature_addon WHERE guid IN (177929,177930,177931,177932);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES ('177932', '0', '29284', '0', '1', '0', '0', '0', '0', ''),
('177931', '0', '29284', '0', '1', '0', '0', '0', '0', ''),
('177930', '0', '29284', '0', '1', '0', '0', '0', '0', ''),
('177929', '177929', '29284', '0', '1', '0', '0', '0', '0', '');
DELETE FROM creature_formations WHERE leaderGUID IN (177929,177930,177931,177932);
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
('177929', '177932', '7', '45', '515', '0', '0'),
('177929', '177931', '5', '360', '515', '0', '0'),
('177929', '177930', '5', '90', '515', '0', '0'),
('177929', '177929', '0', '0', '515', '0', '0');
DELETE FROM waypoint_data WHERE id=177929;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
('177929', '1', '-9027.75', '-94.864', '87.1555', '0', '0', '0', '0', '100', '0'),
('177929', '2', '-9025.41', '-92.7514', '87.0844', '0', '0', '0', '0', '100', '0'),
('177929', '3', '-9011.14', '-80.3432', '86.8344', '0', '0', '0', '0', '100', '0'),
('177929', '4', '-9004.32', '-78.1255', '86.4594', '0', '0', '0', '0', '100', '0'),
('177929', '5', '-9004.32', '-78.1268', '86.4594', '0', '0', '0', '0', '100', '0'),
('177929', '6', '-8979.96', '-98.7766', '85.2712', '0', '0', '0', '0', '100', '0'),
('177929', '7', '-8977.58', '-100.851', '85.2484', '0', '0', '0', '0', '100', '0'),
('177929', '8', '-8975.32', '-103.059', '85.0011', '0', '0', '0', '0', '100', '0'),
('177929', '9', '-8964.11', '-108.449', '84.4224', '0', '0', '0', '0', '100', '0'),
('177929', '10', '-8955.01', '-108.69', '83.6622', '0', '0', '0', '0', '100', '0'),
('177929', '11', '-8944.97', '-108.352', '83.3929', '0', '0', '0', '0', '100', '0'),
('177929', '12', '-8931.95', '-110.703', '83.0005', '0', '0', '0', '0', '100', '0'),
('177929', '13', '-8925.22', '-114.375', '82.8318', '0', '0', '0', '0', '100', '0'),
('177929', '14', '-8927.05', '-118.487', '82.3724', '0', '0', '0', '0', '100', '0'),
('177929', '15', '-8930.2', '-120.189', '81.9944', '0', '0', '0', '0', '100', '0'),
('177929', '16', '-8933.51', '-117.611', '82.2821', '0', '0', '0', '0', '100', '0'),
('177929', '17', '-8941.57', '-115.923', '82.7489', '0', '0', '0', '0', '100', '0'),
('177929', '18', '-8963.92', '-116.993', '83.4989', '0', '0', '0', '0', '100', '0'),
('177929', '19', '-8968.14', '-116.302', '83.6517', '0', '0', '0', '0', '100', '0'),
('177929', '20', '-8971.1', '-115.339', '84.0555', '0', '0', '0', '0', '100', '0'),
('177929', '21', '-8974.94', '-113.228', '84.4608', '0', '0', '0', '0', '100', '0'),
('177929', '22', '-9001.17', '-89.4443', '86.0368', '0', '0', '0', '0', '100', '0'),
('177929', '23', '-9004.11', '-86.0687', '86.2094', '0', '0', '0', '0', '100', '0'),
('177929', '24', '-9006.9', '-80.4456', '86.6005', '0', '0', '0', '0', '100', '0'),
('177929', '25', '-9008.31', '-77.6248', '86.7688', '0', '0', '0', '0', '100', '0'),
('177929', '26', '-9009.3', '-73.5518', '86.7636', '0', '0', '0', '0', '100', '0'),
('177929', '27', '-9011.46', '-60.896', '87.2456', '0', '0', '0', '0', '100', '0'),
('177929', '28', '-9012.73', '-48.1005', '87.6206', '0', '0', '0', '0', '100', '0'),
('177929', '29', '-9013.3', '-35.2854', '87.9616', '0', '0', '0', '0', '100', '0'),
('177929', '30', '-9013.35', '-28.9964', '88.3012', '0', '0', '0', '0', '100', '0'),
('177929', '31', '-9017.39', '-6.23786', '88.5912', '0', '0', '0', '0', '100', '0'),
('177929', '32', '-9020.43', '-0.801499', '88.5773', '0', '0', '0', '0', '100', '0'),
('177929', '33', '-9025.78', '0.820422', '88.5469', '0', '0', '0', '0', '100', '0'),
('177929', '34', '-9031.7', '-1.26564', '88.4393', '0', '0', '0', '0', '100', '0'),
('177929', '35', '-9038.2', '-21.1293', '88.295', '0', '0', '0', '0', '100', '0'),
('177929', '36', '-9038.97', '-27.3575', '88.295', '0', '0', '0', '0', '100', '0'),
('177929', '37', '-9042.46', '-42.3284', '88.42', '0', '0', '0', '0', '100', '0'),
('177929', '38', '-9044.33', '-43.3562', '88.42', '0', '0', '0', '0', '100', '0'),
('177929', '39', '-9045.28', '-45.8501', '88.42', '0', '0', '0', '0', '100', '0'),
('177929', '40', '-9042.71', '-51.8031', '88.295', '0', '0', '0', '0', '100', '0'),
('177929', '41', '-9044.65', '-80.6095', '88.4811', '0', '0', '0', '0', '100', '0'),
('177929', '42', '-9046.75', '-81.234', '88.3541', '0', '0', '0', '0', '100', '0'),
('177929', '43', '-9047.74', '-83.3354', '88.3222', '0', '0', '0', '0', '100', '0'),
('177929', '44', '-9046.37', '-87.2763', '88.1166', '0', '0', '0', '0', '100', '0'),
('177929', '45', '-9041.56', '-95.362', '88.0272', '0', '0', '0', '0', '100', '0'),
('177929', '46', '-9040.42', '-95.3387', '88.0272', '0', '0', '0', '0', '100', '0'),
('177929', '47', '-9037.67', '-96.7954', '87.9022', '0', '0', '0', '0', '100', '0'),
('177929', '48', '-9037.22', '-97.7425', '87.9308', '0', '0', '0', '0', '100', '0'),
('177929', '49', '-9030.46', '-97.2966', '87.4594', '0', '0', '0', '0', '100', '0');
