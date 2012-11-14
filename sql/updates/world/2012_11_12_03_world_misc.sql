-- Fix Jormungar Tunneler
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=26467;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=26467;
DELETE FROM `smart_scripts` WHERE `entryorguid`=26467 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26467,0,0,0,11,0,100,0,0,0,0,0,11,47677,0,0,0,0,0,1,0,0,0,0,0,0,0,'Jormungar Tunneler - On spawn - Spellcast Jormungar Tunnel Passive'),
(26467,0,1,0,21,0,100,0,0,0,0,0,11,47677,0,0,0,0,0,1,0,0,0,0,0,0,0,'Jormungar Tunneler - On reached homeposition - Spellcast Jormungar Tunnel Passive'),
(26467,0,2,0,1,0,100,0,3000,5000,15000,18000,11,51879,0,0,0,0,0,2,0,0,0,0,0,0,0,'Jormungar Tunneler - On update (IC) - Spellcast Corrode Flesh'),
(26467,0,3,0,4,0,100,0,0,0,0,0,28,47677,0,0,0,0,0,1,0,0,0,0,0,0,0,'Jormungar Tunneler - On aggro - Remove Jormungar Tunnel Passive');
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Update Fjord Hawk: Lots of these had incorrect movement.
DELETE FROM `creature_addon` WHERE `guid` IN (112058,112059,112088,112089,112091,112114,112115,112141,112142,112149,112150,112151,112152,112153,112154,112155,112156,112157,112158);
INSERT INTO `creature_addon` (`guid`,`mount`,`bytes1`,`bytes2`,`auras`) VALUES
(112058,0,1,1,''),(112059,0,1,1,''),(112088,0,1,1,''),
(112089,0,1,1,''),(112091,0,1,1,''),(112114,0,1,1,''),
(112115,0,1,1,''),(112141,0,1,1,''),(112142,0,1,1,''),
(112149,0,1,1,''),(112150,0,1,1,''),(112151,0,1,1,''),
(112152,0,1,1,''),(112153,0,1,1,''),(112154,0,1,1,''),
(112155,0,1,1,''),(112156,0,1,1,''),(112157,0,1,1,''),(112158,0,1,1,'');
UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE `guid` IN (112058,112059,112088,112089,112091,112114,112115,112141,112142,112149,112150,112151,112152,112153,112154,112155,112156,112157,112158);
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- SAI for Lashers
UPDATE `creature_addon` SET `bytes1`=0 WHERE `guid` BETWEEN 88228 AND 88237;
UPDATE `creature_addon` SET `bytes1`=0 WHERE `guid` BETWEEN 131438 AND 131457;
UPDATE `creature_addon` SET `auras`='' WHERE `guid`=131452;
UPDATE `creature_addon` SET `bytes1`=0 WHERE `guid` IN (106897,106898,106899,106900,106902,106903,106909,106910,106911,106912,106913,106914,106915,106916,106917,106918);
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`IN(27254,30845,34300);
DELETE FROM `creature_ai_scripts` WHERE `creature_id`IN(27254,30845,34300);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (27254,30845,34300) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Emerald Lasher
(27254,0,0,2,11,0,100,0,0,0,0,0,90,9,0,0,0,0,0,1,0,0,0,0,0,0,0,'Emerald Lasher - On spawn - Set unitfield_bytes1 9 (submerged)'),
(27254,0,1,2,21,0,100,0,0,0,0,0,90,9,0,0,0,0,0,1,0,0,0,0,0,0,0,'Emerald Lasher - On reached homeposition - Set unitfield_bytes1 9 (submerged)'),
(27254,0,2,0,61,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Emerald Lasher - Linked with event 0 or 1 - Disable combat movement'),
(27254,0,3,0,4,0,100,0,0,0,0,0,11,37752,0,0,0,0,0,1,0,0,0,0,0,0,0,'Emerald Lasher - On aggro - Spellcast Stand'),
(27254,0,4,0,0,0,100,0,1500,1500,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Emerald Lasher - On update (IC) - Enable combat movement'),
(27254,0,5,0,0,0,100,0,4000,7000,9000,13000,11,51901,0,0,0,0,0,2,0,0,0,0,0,0,0,'Emerald Lasher - On update (IC) - Spellcast Dream Lash'),
-- Living Lasher
(30845,0,0,2,11,0,100,0,0,0,0,0,90,9,0,0,0,0,0,1,0,0,0,0,0,0,0,'Living Lasher - On spawn - Set unitfield_bytes1 9 (submerged)'),
(30845,0,1,2,21,0,100,0,0,0,0,0,90,9,0,0,0,0,0,1,0,0,0,0,0,0,0,'Living Lasher - On reached homeposition - Set unitfield_bytes1 9 (submerged)'),
(30845,0,2,0,61,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Living Lasher - Linked with event 0 or 1 - Disable combat movement'),
(30845,0,3,0,4,0,100,0,0,0,0,0,11,37752,0,0,0,0,0,1,0,0,0,0,0,0,0,'Living Lasher - On aggro - Spellcast Stand'),
(30845,0,4,0,0,0,100,0,1500,1500,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Living Lasher - On update (IC) - Enable combat movement'),
(30845,0,5,0,0,0,100,0,4000,7000,9000,13000,11,51901,0,0,0,0,0,2,0,0,0,0,0,0,0,'Living Lasher - On update (IC) - Spellcast Dream Lash'),
-- 34300 Mature Lasher
(34300,0,0,2,11,0,100,0,0,0,0,0,90,9,0,0,0,0,0,1,0,0,0,0,0,0,0,'Mature Lasher - On spawn - Set unitfield_bytes1 9 (submerged)'),
(34300,0,1,2,21,0,100,0,0,0,0,0,90,9,0,0,0,0,0,1,0,0,0,0,0,0,0,'Mature Lasher - On reached homeposition - Set unitfield_bytes1 9 (submerged)'),
(34300,0,2,0,61,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Mature Lasher - Linked with event 0 or 1 - Disable combat movement'),
(34300,0,3,0,4,0,100,0,0,0,0,0,11,37752,0,0,0,0,0,1,0,0,0,0,0,0,0,'Mature Lasher - On aggro - Spellcast Stand'),
(34300,0,4,0,0,0,100,0,1500,1500,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Mature Lasher - On update (IC) - Enable combat movement'),
(34300,0,5,0,0,0,100,0,4000,7000,9000,13000,11,51901,0,0,0,0,0,2,0,0,0,0,0,0,0,'Mature Lasher - On update (IC) - Spellcast Dream Lash');
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Secrets of the Scourge
UPDATE `quest_template` SET `PrevQuestId`=0 WHERE `Id`=12312;
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Icehorn updates from sniffs
UPDATE `creature_template` SET `speed_run`=0.9920629, `rank`=4, `unit_flags`=32832, `family`=43, `type_flags`=65537 WHERE `entry`=32361;
DELETE FROM `creature_template_addon` WHERE `entry`=32361;
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(32361,0,0,1,'60915');
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Dragonblight optical improvements
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (27203,30058);
UPDATE `creature_template` SET `inhabitType`=4 WHERE `entry`=30078;
UPDATE `creature_addon` SET `auras`='' WHERE `guid` IN (131075,131077);
UPDATE `creature_addon` SET `auras`='42048' WHERE `guid`=131066;
UPDATE `creature_addon` SET `auras`='42049' WHERE `guid`=106614;
UPDATE `creature_addon` SET `auras`='42050' WHERE `guid`=131068;
UPDATE `creature_addon` SET `auras`='42051' WHERE `guid`=106634;
UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE `id` IN (27222,27223,30078);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-102199,-105487,-105488,-105489,-105495,-131055,-131056,-131058,-131059) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-102199,0,0,0,25,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Onslaught Footman - On reset - Set event phase 1'),
(-102199,0,1,2,1,1,100,0,2000,2000,12000,14000,11,48115,0,0,0,0,0,19,27222,30,0,0,0,0,0,'Onslaught Footman - On OOC update (phase 1) - Spellcast Shoot on Archery Target'),
(-102199,0,2,0,61,1,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Onslaught Footman - On OOC update (phase 1) - Set event phase 2'),
(-102199,0,3,4,1,2,100,0,16000,18000,16000,18000,11,48117,0,0,0,0,0,19,27223,30,0,0,0,0,0,'Onslaught Footman - On OOC update (phase 2) - Spellcast Shoot on Archery Target'),
(-102199,0,4,0,61,2,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Onslaught Footman - On OOC update (phase 2) - Set event phase 4'),
(-105487,0,0,0,1,0,100,0,2000,2000,0,0,11,55840,0,0,0,0,0,10,107492,0,0,0,0,0,0,'Warden of the Chamber - On reset - Spellcast Blue Wyrmrest Warden Beam'),
(-105488,0,0,0,1,0,100,0,2000,2000,0,0,11,55841,0,0,0,0,0,10,107491,0,0,0,0,0,0,'Warden of the Chamber - On reset - Spellcast Yellow Wyrmrest Warden Beam'),
(-105489,0,0,0,1,0,100,0,2000,2000,0,0,11,55841,0,0,0,0,0,10,107491,0,0,0,0,0,0,'Warden of the Chamber - On reset - Spellcast Yellow Wyrmrest Warden Beam'),
(-105495,0,0,0,1,0,100,0,2000,2000,0,0,11,55840,0,0,0,0,0,10,107492,0,0,0,0,0,0,'Warden of the Chamber - On reset - Spellcast Blue Wyrmrest Warden Beam'),
(-131055,0,0,0,1,0,100,0,2000,2000,0,0,11,55838,0,0,0,0,0,10,131075,0,0,0,0,0,0,'Warden of the Chamber - On reset - Spellcast Green Wyrmrest Warden Beam'),
(-131056,0,0,0,1,0,100,0,2000,2000,0,0,11,55824,0,0,0,0,0,10,131077,0,0,0,0,0,0,'Warden of the Chamber - On reset - Spellcast Red Wyrmrest Warden Beam'),
(-131058,0,0,0,1,0,100,0,2000,2000,0,0,11,55838,0,0,0,0,0,10,131075,0,0,0,0,0,0,'Warden of the Chamber - On reset - Spellcast Green Wyrmrest Warden Beam'),
(-131059,0,0,0,1,0,100,0,2000,2000,0,0,11,55824,0,0,0,0,0,10,131077,0,0,0,0,0,0,'Warden of the Chamber - On reset - Spellcast Red Wyrmrest Warden Beam');
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Borean Tundra visual improvement and missing spawn
SET @GOGUID :=356; -- need 1 set by TDB
SET @GUID :=43460; -- need 3 set by TDB
DELETE FROM `gameobject` WHERE `guid`=@GOGUID;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(@GOGUID,187879,571,1,1,4207.366,4056.894,91.62077,2.792518,0,0,0.984807,0.1736523,300,100,1);
DELETE FROM `creature` WHERE `guid` in (@GUID+0,@GUID+1,@GUID+2);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(@GUID+0,24021,571,1,1,21999,0,4207.475,4056.687,93.53715,2.094395,300,0,0,42,0,0,0,0,0),
(@GUID+1,23837,571,1,1,11686,0,4207.471,4056.705,93.66189,3.979351,300,0,0,42,0,0,0,0,0),
(@GUID+2,24957,571,1,1,0,0,4200.877,4056.888,92.28766,6.25263,300,0,0,7185,7196,0,0,0,0);
DELETE FROM `smart_scripts` WHERE `entryorguid`=24957 AND `source_type`=0 AND `id` IN (1,3);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(24957,0,1,0,11,0,100,0,0,0,0,0,11,45820,0,0,0,0,0,9,24021,0,30,0,0,0,0,'Cult Plaguebringer - On spawn - Spellcast Plague Cauldron Beam'),
(24957,0,3,0,21,0,100,0,0,0,0,0,11,45820,0,0,0,0,0,9,24021,0,30,0,0,0,0,'Cult Plaguebringer - On reached homeposition - Spellcast Plague Cauldron Beam');
UPDATE `creature_addon` SET `auras`='45797' WHERE `guid` IN (98730,115941);
DELETE FROM `creature_addon` WHERE `guid` IN (@GUID+0,@GUID+1);
INSERT INTO `creature_addon` (`guid`,`mount`,`bytes1`,`bytes2`,`auras`) VALUES
(@GUID+0,0,0,1,'45797'),
(@GUID+1,0,0,1,'45797');
