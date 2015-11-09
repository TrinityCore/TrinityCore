-- 
UPDATE `creature_template` SET `flags_extra`=2 WHERE `entry`=29639;
UPDATE `creature` SET `MovementType`=0, `spawndist`=0 WHERE `guid`=105166;
UPDATE `creature_addon` SET `auras`=29266 WHERE `guid`=105166;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=29500;
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry` IN (29558, 32520);
UPDATE `creature` SET `MovementType`=0, `spawndist`=0 WHERE `guid`=105243;
UPDATE `creature_addon` SET `auras`=29266 WHERE `guid`=105243;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `Entry` IN (29351, 29358);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (29351, 29358) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(29351,0,0,0,0,0,100,0,2000,5000,7000,9000,11,38621,0,0,0,0,0,2,0,0,0,0,0,0,0,'Niffelem Frost Giant - IC - Cast Debilitating Strike'),
(29358,0,0,0,0,0,100,0,2000,5000,7000,9000,11,61572,0,0,0,0,0,2,0,0,0,0,0,0,0,'Frostworg - IC - Cast Frostbite'),
(29358,0,1,0,0,0,100,0,2000,6000,6000,9000,11,50075,0,0,0,0,0,2,0,0,0,0,0,0,0,'Frostworg - IC - Cast Maim Flesh');
