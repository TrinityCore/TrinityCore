-- Missing Wintergrasp Battle-Mage spawns
SET @GUID := 304;
DELETE FROM `creature` WHERE `guid` BETWEEN @GUID AND @GUID+2;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@GUID,35597,530,1,1,0,1,-1977.80212,5267.618,-41.65557,4.3982296,300,0,0,1,1,0),
(@GUID+1,35611,0,1,1,0,1,1333.57642,320.9896,-63.6309357,2.8972466,300,0,0,1,1,0),
(@GUID+2,35612,530,1,1,0,1,9855.403,-7578.021,20.61899,1.78023577,300,0,0,1,1,0);

-- Fix up Wintergrasp Battle-Mages
UPDATE `creature` SET `modelid`=0,`equipment_id`=1,`spawntimesecs`=300,`curhealth`=1,`curmana`=1 WHERE `id` IN (SELECT `entry` FROM `creature_template` WHERE `subname`='Wintergrasp Battle-Mage');
UPDATE `creature_template` SET `gossip_menu_id`=10662 WHERE `entry` IN (35597,35602,35612);
UPDATE `creature_template` SET `gossip_menu_id`=10666 WHERE `entry` IN (35596,35598);
UPDATE `creature_template` SET `faction_A`=2123, `faction_H`=2123 WHERE `entry` IN (35603,35611,35612);
UPDATE `creature_template` SET `baseattacktime`=2000 WHERE `entry` IN (35600,35601,35602,35603,35611,35612);
UPDATE `creature_template` SET `npcflag`=1, `unit_flags`=33600, `flags_extra`=0 WHERE `subname`= 'Wintergrasp Battle-Mage';
DELETE FROM `creature_equip_template` WHERE `entry`=35603 AND `id`=2;
DELETE FROM `creature_equip_template` WHERE `entry`=35601;
INSERT INTO `creature_equip_template` (`entry`,`id`,`itemEntry1`,`itemEntry2`,`itemEntry3`) VALUES (35601,1,30423,0,0);
-- Add Gossip
DELETE FROM `gossip_menu` WHERE `entry` IN (10662,10666);
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(10662,14775),(10662,14777),(10662,14781),(10662,14782),(10662,14790),(10662,14791),
(10666,14775),(10666,14777),(10666,14781),(10666,14782),(10666,14790),(10666,14791);
-- Add Gossip Options
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (10662);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`) VALUES
(10662,0,19, 'Queue for Wintergrasp.',12,1,1048576);

-- Arcanist Braedin SAI
SET @ENTRY := 32169;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,0,0,1800000,1800000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arcanist Braedin - Out of Combat - Cast Frost Armor");

-- Magister Surdiel SAI
SET @ENTRY := 32170;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,0,0,1800000,1800000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magister Surdiel - Out of Combat - Cast Frost Armor");

-- Arcanist Iramhir SAI
SET @ENTRY := 35596;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,0,0,1800000,1800000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arcanist Iramhir - Out of Combat - Cast Frost Armor");

-- Magistrix Aldessia SAI
SET @ENTRY := 35597;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,0,0,1800000,1800000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magistrix Aldessia - Out of Combat - Cast Frost Armor");

-- Arcanist Paharin SAI
SET @ENTRY := 35598;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,0,0,1800000,1800000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arcanist Paharin - Out of Combat - Cast Frost Armor");

-- Arcanist Dulial SAI
SET @ENTRY := 35599;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,0,0,1800000,1800000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arcanist Dulial - Out of Combat - Cast Frost Armor");

-- Arcanist Laniria SAI
SET @ENTRY := 35600;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,0,0,1800000,1800000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arcanist Laniria - Out of Combat - Cast Frost Armor");

-- Arcanist Nazalia SAI
SET @ENTRY := 35601;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,0,0,1800000,1800000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arcanist Nazalia - Out of Combat - Cast Frost Armor");

-- Magister Savarin SAI
SET @ENTRY := 35602;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,0,0,1800000,1800000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magister Savarin - Out of Combat - Cast Frost Armor");

-- Magister Dalhyr SAI
SET @ENTRY := 35603;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,0,0,1800000,1800000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magister Dalhyr - Out of Combat - Cast Frost Armor");

-- Magistrix Erembria SAI
SET @ENTRY := 35611;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,0,0,1800000,1800000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magistrix Erembria - Out of Combat - Cast Frost Armor");

-- Magistrix Caradess SAI
SET @ENTRY := 35612;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,0,0,1800000,1800000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magistrix Caradess - Out of Combat - Cast Frost Armor");
