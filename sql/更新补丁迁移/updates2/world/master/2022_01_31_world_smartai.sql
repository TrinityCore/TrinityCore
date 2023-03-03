UPDATE `creature` SET `spawndist` = 3, `MovementType` = 1 WHERE `id` = 36719;
UPDATE `creature_template` SET `InhabitType` = 1 WHERE `entry` = 36719;
UPDATE `creature` SET `PhaseId`=169 WHERE `PhaseId`=170 AND `map`=648 and `zoneId`=4720;
UPDATE `gameobject` SET `PhaseId`=169 WHERE `PhaseId`=170 AND`map`=648 and `zoneId`=4720;

-- Juvenile Squallhunter <Brood of Nithogg>
SET @ENTRY := 107258;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,187482,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Lightning Breath');