-- Valves
UPDATE `gameobject` SET `spawntimesecs`=300,`animprogress`=100,`state`=1 WHERE `guid`=151895;
UPDATE `gameobject` SET `spawntimesecs`=300,`animprogress`=100 WHERE `guid`=221;

-- Max Blasto: Spawn point
UPDATE `event_scripts` SET `x`=4029.0,`y`=4883.078,`z`=-12.71482,`o`=1.310609 WHERE `id`=17207 AND `command`=10 AND `datalong`=25832;
-- Max Blasto: SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=25832;
DELETE FROM `smart_scripts` WHERE `entryorguid`=25832 AND `source_type`=0;
INSERT INTO `smart_scripts`(`entryorguid`,`id`,`event_type`,`action_type`,`action_param1`,`target_type`,`target_param1`,`comment`) VALUE
(25832,0,54,49,0,21,20,'Max Blasto - Just summoned - Start attack'),
(25832,1,4,1,0,0,0,'Max Blasto - On aggro - Say');
-- Max Blasto: Texts
DELETE FROM `creature_text` WHERE `entry`=25832;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`text`,`type`,`probability`,`comment`) VALUE
(25832,0,0,'I am the herald of Mechazod. You will be decursed!',12,100,'Max Blasto - Just summoned'); -- Proofed from video: https://www.youtube.com/watch?v=-hi6a70U3gM

-- The Grinder: Spawn point
UPDATE `event_scripts` SET `x`=3781.2,`y`=4832.596,`z`=-13.04141,`o`=5.141372 WHERE `id`=17208 AND `command`=10 AND `datalong`=25833;
-- The Grinder: SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=25833;
DELETE FROM `smart_scripts` WHERE `entryorguid`=25833 AND `source_type`=0;
INSERT INTO `smart_scripts`(`entryorguid`,`id`,`event_type`,`action_type`,`action_param1`,`target_type`,`target_param1`,`comment`) VALUE
(25833,0,54,49,0,21,20,'The Grinder - Just summoned - Start attack'),
(25833,1,4,1,0,0,0,'The Grinder - On aggro - Say');
-- The Grinder: Texts
DELETE FROM `creature_text` WHERE `entry`=25833;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`text`,`type`,`probability`,`comment`) VALUE
(25833,0,0,'Your meddling is at an end. Mechazod will relieve your curse once I am done with you.',12,100,'The Grinder - Just summoned');

-- ED-210: Spawn point
UPDATE `event_scripts` SET `x`=4208.38,`y`=4807.071,`z`=-12.7529,`o`=5.809316 WHERE `id`=16909 AND `command`=10 AND `datalong`=25831;
-- ED-210: SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=25831;
DELETE FROM `smart_scripts` WHERE `entryorguid`=25831 AND `source_type`=0;
INSERT INTO `smart_scripts`(`entryorguid`,`id`,`event_type`,`action_type`,`action_param1`,`target_type`,`target_param1`,`comment`) VALUE
(25831,0,54,49,0,21,20,'ED-210 - Just summoned - Start attack'),
(25831,1,4,1,0,0,0,'ED-210 - On aggro - Say');
-- ED-210: Texts
DELETE FROM `creature_text` WHERE `entry`=25831;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`text`,`type`,`probability`,`comment`) VALUE
(25831,0,0,'ED-210 online!',12,100,'ED-210 - Just summoned');

-- Twonky: Spawn point
UPDATE `event_scripts` SET `x`=4118.113,`y`=5087.803,`z`=-1.433036,`o`=2.253069 WHERE `id`=16904 AND `command`=10 AND `datalong`=25830;
-- Twonky: SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=25830;
DELETE FROM `smart_scripts` WHERE `entryorguid`=25830 AND `source_type`=0;
INSERT INTO `smart_scripts`(`entryorguid`,`id`,`event_type`,`action_type`,`action_param1`,`target_type`,`target_param1`,`comment`) VALUE
(25830,0,54,49,0,21,20,'Twonky - Just summoned - Start attack'),
(25830,1,4,1,0,0,0,'Twonky - On aggro - Say');
-- Twonky: Texts
DELETE FROM `creature_text` WHERE `entry`=25830;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`text`,`type`,`probability`,`comment`) VALUE
(25830,0,0,'Twonky!',12,100,'Twonky - On aggro');
