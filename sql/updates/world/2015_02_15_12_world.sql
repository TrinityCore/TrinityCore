--
SET @CGUID := 45761;

DELETE FROM `creature` WHERE `id`=26265;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES 
(@CGUID, 26265, 571, 0, 0, 1, 1, 0, 0, 4031.15, 7326.39, 635.972, 4.26247, 300, 0, 0, 1, 0, 0, 0, 0, 0,0);

UPDATE `creature_template` SET  `ScriptName`='', `npcflag`=`npcflag`|1 WHERE `entry`=26206;
-- Keristrasza SAI
SET @ENTRY := 26206;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,9262,0,0,0,11,46772,0,0,0,0,0,7,0,0,0,0,0,0,0,"Keristrasza - On Gossip Option 0 Selected - Cast 'Teleport'"),
(@ENTRY,0,1,0,61,0,100,0,9262,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Keristrasza - On Gossip Option 0 Selected - Close Gossip"),
(@ENTRY,0,2,3,62,0,100,0,9262,1,0,0,11,46824,0,0,0,0,0,7,0,0,0,0,0,0,0,"Keristrasza - On Gossip Option 1 Selected - Cast 'Teleport'"),
(@ENTRY,0,3,0,61,0,100,0,9262,1,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Keristrasza - On Gossip Option 1 Selected - Close Gossip");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9262 AND `SourceEntry` IN (0, 1);
INSERT INTO `conditions` VALUES
(15, 9262, 0, 0, 0, 9, 0, 11957, 0, 0, 0, 0, 0, '', 'Only show gossip if player has quest 11957'),
(15, 9262, 1, 0, 0, 2, 0, 35709, 1, 0, 0, 0, 0, '', 'Only show gossip if player has item 35709');

-- Saragosa's End Invisman SAI
SET @ENTRY := 26265;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,46793,0,0,0,12,26231,5,0,0,0,0,8,0,0,0,4050.19,7329.25,635.97,3.34,"Saragosa's End Invisman - On Spellhit 'Activate Power Focus' - Summon Creature 'Saragosa'"),
(@ENTRY,0,1,0,61,0,100,0,46793,0,0,0,11,46789,0,0,0,0,0,1,0,0,0,0,0,0,0,"Saragosa's End Invisman - On Spellhit 'Activate Power Focus' - Cast 'Blue Power Focus'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=1 AND `SourceEntry`=26265;
INSERT INTO `conditions` VALUES
(22, 1, 26265, 0, 0, 29, 0, 26231, 40, 0, 1, 0, 0, '', 'Only summon Saragosa if there is not already one in range'),
(22, 1, 26265, 0, 0, 29, 0, 26232, 40, 0, 1, 0, 0, '', 'Only summon Saragosa if there is not already one in range');

-- Activate Power Focus (46793)
DELETE FROM `event_scripts` WHERE `id`=17452;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=46793;
INSERT INTO `conditions` VALUES
(13, 1, 46793, 0, 0, 31, 0, 3, 26265, 0, 0, 0, 0, '', 'Target needs to be Saragosa''s End Invisman');

UPDATE `creature_template` SET  `ScriptName`='', `unit_flags`=`unit_flags`|768, `flags_extra`=`flags_extra`|2 WHERE `entry`=26231;
-- Saragosa SAI
SET @ENTRY := 26231;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,6000,6000,0,0,28,46789,0,0,0,0,0,19,26265,40,0,0,0,0,0,"Saragosa - Out of Combat - Remove Aura 'Blue Power Focus' (No Repeat)"),
(@ENTRY,0,1,2,1,0,100,1,12000,12000,0,0,12,26232,1,120000,0,0,0,1,0,0,0,0,0,0,0,"Saragosa - Out of Combat - Summon Creature 'Saragosa' (No Repeat)"),
(@ENTRY,0,2,0,61,0,100,0,12000,12000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Saragosa - Out of Combat - Despawn Instant (No Repeat)");

UPDATE `creature_template` SET  `ScriptName`='', `flags_extra`=`flags_extra`|2 WHERE `entry`=26232;
-- Saragosa SAI
SET @ENTRY := 26232;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,40,3400,6200,11,51779,0,0,0,0,0,2,0,0,0,0,0,0,0,"Saragosa - In Combat - Cast 'Frostfire Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,8500,17500,20100,40100,11,15063,0,0,0,0,0,2,0,0,0,0,0,0,0,"Saragosa - In Combat - Cast 'Frost Nova'");
