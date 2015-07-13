--
UPDATE `creature_text` SET `type`=14 WHERE `Entry` IN (31397) AND `id` IN (5, 6, 7);
UPDATE `smart_scripts` SET `action_type`=83, `action_param1`=1, `target_type`=1, `comment`="Saronite Mine Slave - On Script - remove npc flag"  WHERE `entryorguid` IN (3139700) AND `source_type`=9 AND `id` IN (1);
UPDATE `smart_scripts` SET `action_type`=87, `action_param1`=3139700, `action_param2`=3139701  WHERE `entryorguid` IN (31397) AND `source_type`=0 AND `id` IN (0);
DELETE FROM `smart_scripts` WHERE `entryorguid`=3139701 AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3139700 AND `source_type`=9 AND `id`>2;
DELETE FROM `smart_scripts` WHERE `entryorguid`=31397 AND `source_type`=0 AND `id`>0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(3139701, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Saronite Mine Slave  - action list - close gossip'),
(3139701, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 2, 14, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Saronite Mine Slave  - action list - set faction'),
(3139701, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Saronite Mine Slave  - action list - say text1'),
(3139701, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Saronite Mine Slave  - action list - Attack'),
(3139701, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 8599, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Saronite Mine Slave  - action list - cast Enrage'),
(31397, 0, 1, 0, 0, 0, 100, 0, 1000, 1000, 14000, 14000, 11, 3148, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Saronite Mine Slave  - IC - cast Head Crack'),
(31397, 0, 2, 0, 1, 0, 15, 0, 10000, 30000, 50000, 70000, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Saronite Mine Slave  - OOC - Say text2'),
(3139700, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 7027.581543, 1894.517334, 529.414001, 0, 'Saronite Mine Slave  - action list - move to pos'),
(3139700, 9, 4, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Saronite Mine Slave  - action list - despawn');

DELETE FROM `creature_text` WHERE `entry` IN(31397) AND `groupid`=1;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(31397,1,0,'Please, no more.',12,1,100,0,0,0,'Saronite Mine Slave', 32506),
(31397,1,1,'Hit me again and you''ll regret it!',12,1,100,0,0,0,'Saronite Mine Slave', 32507),
(31397,1,2,'Ow!',12,1,100,0,0,0,'Saronite Mine Slave', 32508),
(31397,1,3,'I''m sorry. I''ll work harder.',12,1,100,0,0,0,'Saronite Mine Slave', 32509),
(31397,1,4,'Soon the master will reclaim me!',12,1,100,0,0,0,'Saronite Mine Slave', 32510);
