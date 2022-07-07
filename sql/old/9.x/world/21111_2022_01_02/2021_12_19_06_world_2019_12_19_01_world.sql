-- 
UPDATE `creature_template_addon` SET `auras`=""  WHERE `entry` IN (19913, 40135, 40001, 40673, 40674, 40675, 40670, 40671, 40672, 30444);
UPDATE `creature_template_addon` SET `auras`="25824"  WHERE `entry` IN (15902);
DELETE FROM `creature_template_spell` WHERE `CreatureID` IN (30444) AND `Index` IN (1);
INSERT INTO `creature_template_spell` (`CreatureID`, `Index`, `Spell`) VALUES
(30444, 1 ,56763);

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (19913);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (19913) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(19913,0,0,0,54,0,100,0,0,0,0,0,0,11,39312,0,0,0,0,0,1,0,0,0,0,0,0,0,"Area 52 Spotlight - Just summoned - Cast Cosmetic A-52 Spotlight");
