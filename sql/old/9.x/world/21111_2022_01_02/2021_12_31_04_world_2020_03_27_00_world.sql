-- 
UPDATE `gameobject_template_addon` SET `flags`=16 WHERE `entry`=190225;
UPDATE `gameobject_template` SET `data1`=5 WHERE `entry`=190224;

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=26604 AND `id` IN (2,3,4);
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=2660400;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26604,0,2,0,20,0,100,0,12484,10000,10000,0,80,26604*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Mack Fearsen - On Quest Complete (Scourgekabob) - Action list'),
(26604*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 83, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mack Fearsen - action list - Remove npc flag'),
(26604*100, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mack Fearsen - action list - Say text'),
(26604*100, 9, 2, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mack Fearsen - action list - Say text'),
(26604*100, 9, 3, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mack Fearsen - action list - Say text'),
(26604*100, 9, 4, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mack Fearsen - action list - Say text'),
(26604*100, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 82, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mack Fearsen - action list - Set npc flag'),
(26604, 0, 3, 0, 1, 0, 100, 0, 15000, 20000, 15000, 20000, 5, 92, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mack Fearsen - OOC - Play emote drink');

DELETE FROM `creature_text` WHERE `CreatureID`=26604;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextId`) VALUES 
(26604, 0, 0, 'Shcourged trooolls roashting....', 12, 0, 100, 1, 0, 0, 'Mack Fearsen', 27290),
(26604, 1, 0, '...on an open fire.....', 12, 0, 100, 1, 0, 0, 'Mack Fearsen', 27291),
(26604, 2, 0, 'Mack belches loudly...', 16, 0, 100, 0, 0, 0, 'Mack Fearsen', 27308),
(26604, 3, 0, 'That''s it! Far as I got... Whatd''ya think?', 12, 0, 100, 11, 0, 0, 'Mack Fearsen', 27292);

DELETE FROM `creature_template_addon` WHERE `entry`=26604;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(26604, 0, 0, 0, 1, 0, '35777'); -- 26604 - 35777 - 35777
