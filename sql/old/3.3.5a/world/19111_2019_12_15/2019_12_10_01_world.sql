-- 
DELETE FROM `creature` WHERE `guid` IN (120598,120599);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`) VALUES
(120598, 32738, 571, 1, 1, 0, 0, 5846.0029, 877.936, 846.3367, 1.485737, 300, 0, 0, 0, 0, 0),
(120599, 32740, 571, 1, 1, 0, 0, 5863.8427, 871.6867, 846.337, 0.865273, 300, 0, 0, 0, 0, 0);

DELETE FROM `creature_text` WHERE `CreatureID` IN (32738,32740);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(32738, 0, 0,"The view up here is amazing!", 12, 0, 100, 0, 0, 0, 33031, 0, 'Kat Sunflower'),
(32738, 0, 1,"Too bad I left my light feathers at home... Slow Fall would work perfect here!", 12, 0, 100, 0, 0, 0, 33032, 0, 'Kat Sunflower'),
(32740, 0, 0,"The view up here is amazing!", 12, 0, 100, 0, 0, 0, 33031, 0, 'Archmage Rheaume'),
(32740, 0, 1,"Too bad I left my light feathers at home... Slow Fall would work perfect here!", 12, 0, 100, 0, 0, 0, 33032, 0, 'Archmage Rheaume');

UPDATE `creature_template` SET `flags_extra`=`flags_extra`|32768 WHERE `entry` IN (27175);
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (32738,32740);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (32738,32740) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(32738, 0, 0, 0, 1, 0, 100, 0, 1000, 60000, 300000, 840000, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Kat Sunflower - OOC - Say text'),
(32740, 0, 0, 0, 1, 0, 100, 0, 1000, 60000, 300000, 840000, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Archmage Rheaume - OOC - Say text');
