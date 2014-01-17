-- Kalaran Windblade: SAI
DELETE FROM `smart_scripts` WHERE `entryorguid`=8479 AND `source_type`=0;
INSERT INTO `smart_scripts`(`entryorguid`,`id`,`link`,`event_type`,`event_param1`,`event_param2`,`action_type`,`action_param1`,`target_type`,`comment`) VALUES 
(8479,0,1,62,1321,0,26,3441,7,'Kalaran Windblade - On gossip select - Quest credit'),
(8479,1,0,61,0,0,72,0,7,'Kalaran Windblade - On gossip select - Close gossip'),
(8479,2,3,62,1323,2,11,19797,7,'Kalaran Windblade - On gossip select - Cast 19797'),
(8479,3,0,61,0,0,72,0,7,'Kalaran Windblade - On gossip select - Close gossip'),
(8479,4,0,62,1323,3,80,847900,1,'Kalaran Windblade - On gossip select - Run script');

-- Kalaran Windblade: SAI action list
DELETE FROM `smart_scripts` WHERE `entryorguid`=847900 AND `source_type`=9;
INSERT INTO `smart_scripts`(`entryorguid`,`source_type`,`id`,`event_param1`,`event_param2`,`action_type`,`action_param1`,`target_type`,`comment`) VALUES
(847900,9,0,0,0,72,0,7,'Kalaran Windblade - Action 0 - Close gossip'),
(847900,9,1,0,0,83,3,1,'Kalaran Windblade - Action 1 - Remove NPC flags'),
(847900,9,2,1000,1000,1,0,1,'Kalaran Windblade - Action 2 - Say 0'),
(847900,9,3,1000,1000,17,69,1,'Kalaran Windblade - Action 3 - Emote state use standing'),
(847900,9,4,60000,60000,17,0,1,'Kalaran Windblade - Action 4 - Emote state none'),
(847900,9,5,1000,1000,15,3453,7,'Kalaran Windblade - Action 5 - Give quest credit'),
(847900,9,6,1000,1000,82,3,1,'Kalaran Windblade - Action 6 - Add NPC flags');

-- Kalaran Windblade: Creature text
DELETE FROM `creature_text` WHERE `entry`=8479;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`text`,`type`,`probability`,`comment`) VALUE 
(8479,0,0,'Be patient, $N. The torch is almost complete.',12,100,'Kalaran Windblade - Smart AI');

-- Captured Mountaineer: SAI 
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=2211;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2211 AND `source_type`=0;
INSERT INTO `smart_scripts`(`entryorguid`,`id`,`event_type`,`event_param1`,`action_type`,`action_param1`,`action_param2`,`target_type`,`comment`) VALUE
(2211,0,20,492,80,221100,2,1,'Captured Mountaineer - On quest reward - Start timed action list');

-- Captured Mountaineer: SAI action list
DELETE FROM `smart_scripts` WHERE `entryorguid`=221100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`event_param1`,`event_param2`,`action_type`,`action_param1`,`target_type`,`comment`) VALUES
(221100,9,0,1000,1000,1,0,1,'Captured Mountaineer - Action 0 - Say 0'),
(221100,9,1,4000,4000,37,0,1,'Captured Mountaineer - Action 2 - Suicide');

-- Captured Mountaineer: Creature text
DELETE FROM `creature_text` WHERE `entry`=2211;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`probability`,`emote`,`comment`) VALUE
(2211,0,0,'I raise my brew and hope to be rid of the likes of you! Cheers, you no good scoundrel, $N!',12,100,7,'Captured Mountaineer - Reward quest 492');
