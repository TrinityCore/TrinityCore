-- 
UPDATE `creature` SET `position_x` = 5800.89, `position_y` = -985.82, `position_z` = 409.78, `spawntimesecs`=10 WHERE `id` = 14467;
DELETE FROM `creature_addon` WHERE `guid` IN (39715);
DELETE FROM `creature_template_addon` WHERE `entry`=14467;
INSERT INTO `creature_template_addon` (`entry`, `bytes2`,`auras`) VALUES
(14467, 0, '58951'); 
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|768  WHERE `entry` IN (14467);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (14467) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(14467, 0, 0, 1, 38, 0, 100, 0, 1, 1, 30000, 30000, 0, 28, 58951, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Kroshius - On data set - remove aura"),
(14467, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Kroshius - On data set - Remove Flags Immune To Players & Immune To NPC's"),
(14467, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Kroshius - On data set - say line"),
(14467, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 16, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Kroshius - On data set - Set Faction 16"),
(14467, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Kroshius - On data set - Set eventphase 1"),
(14467, 0, 5, 0, 0, 0, 100, 0, 5000, 8000, 9000, 12000, 0, 11, 10101, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Kroshius - In Combat - Cast 'Knock Away'"),
(14467, 0, 6, 7, 1, 1, 100, 0, 30000, 30000, 30000, 30000, 0, 11, 58951, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Kroshius - Ooc - Cast 'feign death'"),
(14467, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Kroshius - Ooc - add Flags Immune To Players & Immune To NPC's"),
(14467, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Kroshius - Ooc - Set eventphase 0"),
(14467, 0, 9, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, 11, 58951, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Kroshius - On reset - Cast spell");

SET @GUID := 7078;
DELETE FROM `gameobject` WHERE `guid`=@GUID;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `ScriptName`, `VerifiedBuild`) VALUES
(@GUID,179676,1,0,0,1,1,5800.89,-985.82,409.78,2.24779,-0,-0,-0.90179,-0.432175,-20,255,1,"",0);

DELETE FROM `event_scripts` WHERE `id` IN (8328);
INSERT INTO `event_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES
(8328,0,9,@GUID,30,0,0,0,0,0);

UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`=179676;
DELETE FROM `smart_scripts` WHERE `entryorguid`=179676 AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(179676,1,0,0,70,0,100,0,1,0,0,0,0,45,1,1,0,0,0,0,19,14467,0,0,0,0,0,0,"Fel Fire - On State Changed - Set Data");
