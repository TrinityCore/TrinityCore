-- 
DELETE FROM `creature` WHERE `guid` IN (120676);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`) VALUES
(120676, 35477, 0, 1, 1, 0, 1, -8827.98, 515.408, 98.6826, 6.00393, 180, 0, 0, 0, 0, 0);

DELETE FROM `gossip_menu_option` WHERE `MenuID`=10649;
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES
(10649, 0, 0, 'Yes I do!', 35835, 1, 1, 26124);

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=35477;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (35477) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(35477, 0, 0, 1, 62, 0, 100, 0, 10649, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Little Adeline - On gossip select - Close gossip'),
(35477, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 11, 67554, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Little Adeline - On gossip select - Cast Spell Cascade of Petals');
