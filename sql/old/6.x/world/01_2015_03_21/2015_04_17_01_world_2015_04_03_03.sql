--
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry` IN (20142, 19918, 20069, 19959);
UPDATE `creature_template` SET `scale`=1.5 WHERE `Entry`=19959;
UPDATE `creature_addon` SET `bytes2`=4097 WHERE `guid` IN (23472, 23473);
UPDATE `creature_addon` SET `auras`="34712" WHERE `guid`=23078;
UPDATE `creature` SET `modelid`=0 WHERE `guid` = 23597;
UPDATE `creature` SET `modelid`=19278 WHERE `guid` = 23459;
UPDATE `creature` SET `modelid`=19282 WHERE `guid` = 23460;
UPDATE `creature` SET `modelid`=19280 WHERE `guid` = 23461;
UPDATE `creature` SET `modelid`=19281 WHERE `guid` = 23462;
DELETE FROM `creature_addon` WHERE `guid` IN (23441, 23428, 23431, 23430, 23434, 23427);
DELETE FROM `creature` WHERE `guid` IN (23428, 23441, 23431, 23430, 23434, 23427);
UPDATE `creature` SET `spawndist`=15 WHERE `id`=19918;

SET @Andormu:= 19932;
SET @Nozari:= 19933;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (19918, @Andormu, @Nozari);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-23440, -23439, -23438, -23437, -23436, -23433, -23432, -23429, -23426, @Nozari, @Nozari*100, 19918*100+1, 19918*100);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Nozari,0,0,0,1,0,100,0,60000,60000,900000,900000,80,@Nozari*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nozari - OOC - Action list"),
(@Nozari*100,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nozari - Action list - Talk"),
(@Nozari*100,9,1,0,0,0,100,0,4000,4000,0,0,1,0,0,0,0,0,0,19,@Andormu,15,0,0,0,0,0,"Nozari - Action list - Talk"),
(@Nozari*100,9,2,0,0,0,100,0,7000,7000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nozari - Action list - Talk"),
(@Nozari*100,9,3,0,0,0,100,0,5000,5000,0,0,1,1,0,0,0,0,0,19,@Andormu,15,0,0,0,0,0,"Nozari - Action list - Talk"),
(@Nozari*100,9,4,0,0,0,100,0,9000,9000,0,0,1,2,0,0,0,0,0,19,@Andormu,15,0,0,0,0,0,"Nozari - Action list - Talk"),
(@Nozari*100,9,5,0,0,0,100,0,7000,7000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nozari - Action list - Talk"),
(@Nozari*100,9,6,0,0,0,100,0,10000,10000,0,0,1,3,0,0,0,0,0,19,@Andormu,15,0,0,0,0,0,"Nozari - Action list - Talk"),
(@Nozari*100,9,7,0,0,0,100,0,8000,8000,0,0,1,4,0,0,0,0,0,19,@Andormu,15,0,0,0,0,0,"Nozari - Action list - Talk"),
(@Nozari*100,9,8,0,0,0,100,0,7000,7000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nozari - Action list - Talk"),
(@Nozari*100,9,9,0,0,0,100,0,5000,5000,0,0,1,5,0,0,0,0,0,19,@Andormu,15,0,0,0,0,0,"Nozari - Action list - Talk"),
(@Nozari*100,9,10,0,0,0,100,0,10000,10000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nozari - Action list - Talk"),
(-23440,0,0,0,1,0,100,0,1200000,1200000,1200000,1200000,53,0,2344000,0,0,0,0,1,0,0,0,0,0,0,0,"Time Watcher - OOC  - Start wp"),
(-23440,0,1,0,40,0,100,0,2,0,0,0,11,34699,0,0,0,0,0,1,0,0,0,0,0,0,0,"Time Watcher - On wp2 - Cast"),
(-23440,0,2,0,58,0,100,0,6,0,0,0,80,19918*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Time Watcher - On wp Ended - Action list"),
(19918*100,9,0,0,0,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Time Watcher - Action list - Set invisible"),
(19918*100,9,1,0,0,0,100,0,5000,5000,0,0,28,34699,0,0,0,0,0,1,0,0,0,0,0,0,0,"Time Watcher - Action list - remove aura"),
(19918*100,9,2,0,0,0,100,0,180000,180000,0,0,47,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Time Watcher - Action list - Set visible"),
(-23440,0,3,0,25,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Time Watcher - On Reset - Set Active On"),
(-23438,0,0,0,1,0,100,0,1800000,1800000,1800000,1800000,53,0,2344000,0,0,0,0,1,0,0,0,0,0,0,0,"Time Watcher - OOC  - Start wp"),
(-23438,0,1,0,40,0,100,0,2,0,0,0,11,34699,0,0,0,0,0,1,0,0,0,0,0,0,0,"Time Watcher - On wp2 - Cast"),
(-23438,0,2,0,58,0,100,0,6,0,0,0,80,19918*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Time Watcher - On wp Ended - Action list"),
(-23438,0,3,0,25,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Time Watcher - On Reset - Set Active On"),
(-23436,0,0,0,1,0,100,0,2200000,2200000,2200000,2200000,53,0,2344000,0,0,0,0,1,0,0,0,0,0,0,0,"Time Watcher - OOC - Start wp"),
(-23436,0,1,0,40,0,100,0,2,0,0,0,11,34699,0,0,0,0,0,1,0,0,0,0,0,0,0,"Time Watcher - On wp2 - Cast"),
(-23436,0,2,0,58,0,100,0,6,0,0,0,80,19918*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Time Watcher - On wp Ended - Action list"),
(-23436,0,3,0,25,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Time Watcher - On Reset - Set Active On"),
(-23433,0,0,0,1,0,100,0,2600000,2600000,2600000,2600000,53,0,2344000,0,0,0,0,1,0,0,0,0,0,0,0,"Time Watcher - OOC - Start wp"),
(-23433,0,1,0,40,0,100,0,2,0,0,0,11,34699,0,0,0,0,0,1,0,0,0,0,0,0,0,"Time Watcher - On wp2 - Cast"),
(-23433,0,2,0,58,0,100,0,6,0,0,0,80,19918*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Time Watcher - On wp Ended - Action list"),
(-23433,0,3,0,25,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Time Watcher - On Reset - Set Active On"),
(-23439,0,0,0,1,0,100,0,1200000,1200000,1200000,1200000,53,1,2344001,0,0,0,0,1,0,0,0,0,0,0,0,"Time Watcher - OOC - Start wp"),
(-23439,0,1,0,40,0,100,0,2,0,0,0,11,34702,0,0,0,0,0,1,0,0,0,0,0,0,0,"Time Watcher - On wp2 - Cast"),
(-23439,0,2,0,58,0,100,0,7,0,0,0,80,19918*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Time Watcher - On wp Ended - Action list"),
(19918*100+1,9,0,0,0,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Time Watcher - Action list - Set invisible"),
(19918*100+1,9,1,0,0,0,100,0,5000,5000,0,0,28,34702,0,0,0,0,0,1,0,0,0,0,0,0,0,"Time Watcher - Action list - remove aura"),
(19918*100+1,9,2,0,0,0,100,0,180000,180000,0,0,47,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Time Watcher - Action list - Set visible"),
(-23439,0,3,0,25,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Time Watcher - On Reset - Set Active On"),
(-23437,0,0,0,1,0,100,0,1800000,1800000,1800000,1800000,53,1,2344001,0,0,0,0,1,0,0,0,0,0,0,0,"Time Watcher - OOC - Start wp"),
(-23437,0,1,0,40,0,100,0,2,0,0,0,11,34702,0,0,0,0,0,1,0,0,0,0,0,0,0,"Time Watcher - On wp2 - Cast"),
(-23437,0,2,0,58,0,100,0,7,0,0,0,80,19918*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Time Watcher - On wp Ended - Action list"),
(-23437,0,3,0,25,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Time Watcher - On Reset - Set Active On"),
(-23432,0,0,0,1,0,100,0,2200000,2200000,2200000,2200000,53,1,2344001,0,0,0,0,1,0,0,0,0,0,0,0,"Time Watcher - OOC - Start wp"),
(-23432,0,1,0,40,0,100,0,2,0,0,0,11,34702,0,0,0,0,0,1,0,0,0,0,0,0,0,"Time Watcher - On wp2 - Cast"),
(-23432,0,2,0,58,0,100,0,7,0,0,0,80,19918*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Time Watcher - On wp Ended - Action list"),
(-23432,0,3,0,25,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Time Watcher - On Reset - Set Active On"),
(-23426,0,0,0,1,0,100,0,2600000,2600000,2600000,2600000,53,1,2344001,0,0,0,0,1,0,0,0,0,0,0,0,"Time Watcher - OOC - Start wp"),
(-23426,0,1,0,40,0,100,0,2,0,0,0,11,34702,0,0,0,0,0,1,0,0,0,0,0,0,0,"Time Watcher - On wp2 - Cast"),
(-23426,0,2,0,58,0,100,0,7,0,0,0,80,19918*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Time Watcher - On wp Ended - Action list"),
(-23426,0,3,0,25,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Time Watcher - On Reset - Set Active On"),
(-23429,0,0,0,1,0,100,0,3000000,3000000,3000000,3000000,53,1,2344001,0,0,0,0,1,0,0,0,0,0,0,0,"Time Watcher - OOC - Start wp"),
(-23429,0,1,0,40,0,100,0,2,0,0,0,11,34702,0,0,0,0,0,1,0,0,0,0,0,0,0,"Time Watcher - On wp2 - Cast"),
(-23429,0,2,0,58,0,100,0,7,0,0,0,80,19918*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Time Watcher - On wp Ended - Action list"),
(-23429,0,3,0,25,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Time Watcher - On Reset - Set Active On");

DELETE FROM `waypoints` WHERE `entry` IN(2344000, 2344001);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(2344000, 1, -8450.692383, -4176.048340, -199.006653, 'Time Watcher'),
(2344000, 2, -8449.390625, -4160.058105, -209.984818, 'Time Watcher'),
(2344000, 3, -8448.969727, -4158.049805, -208.871887, 'Time Watcher'), 
(2344000, 4, -8436.923828, -4107.062012, -209.587540, 'Time Watcher'),
(2344000, 5, -8393.622070, -4071.729736, -209.587540, 'Time Watcher'),
(2344000, 6, -8349.183594, -4058.919189, -209.033203, 'Time Watcher'),
(2344001, 1, -8340.623047, -4344.326172, -199.383408, 'Time Watcher'), 
(2344001, 2, -8314.343750, -4348.677246, -209.548553, 'Time Watcher'), 
(2344001, 3, -8246.214844, -4344.385742, -205.160355, 'Time Watcher'),
(2344001, 4, -8207.163086, -4307.918945, -196.205338, 'Time Watcher'),
(2344001, 5, -8186.439941, -4259.733398, -183.948654, 'Time Watcher'),
(2344001, 6, -8188.971191, -4211.268555, -174.056534, 'Time Watcher'),
(2344001, 7, -8169.538574, -4167.970703, -165.149277, 'Time Watcher');

DELETE FROM `creature_text` WHERE `entry` IN(@Nozari,@Andormu);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(@Nozari, 0, 0, 'Fascinating. What is it, Andormu?', 12, 0, 100, 1, 0, 0,  'Nozari',17541),
(@Nozari, 1, 0, 'Hrm, are they tampering with the timeways?', 12, 0, 100, 1, 0, 0,  'Nozari',17543),
(@Nozari, 2, 0, 'I hate it when you speak to me in that manner. I am your equal in every way, brother. Remember that the next time you are trapped amidst a temporal vortex, crying for help.', 12, 0, 100, 1, 0, 0,  'Nozari',17546),
(@Nozari, 3, 0, 'Shall we?', 12, 0, 100, 1, 0, 0,  'Nozari',17549),
(@Nozari, 4, 0, '%s nods.', 16, 0, 100, 1, 0, 0,  'Nozari',17551),
(@Andormu, 0, 0, 'Something very, very disturbing. We''re starting to see more of them across the timeways.', 12, 0, 100, 1, 0, 0,  'Andormu',17542),
(@Andormu, 1, 0, 'Nozari, I''m not talking about a greedy wizard looking to improve his station in life by making a small adjustment to the past.', 12, 0, 100, 1, 0, 0,  'Andormu',17544),
(@Andormu, 2, 0, 'These beings aren''t giving themselves the winning numbers for the Stormwind lottery, dear.', 12, 0, 100, 1, 0, 0,  'Andormu',17545),
(@Andormu, 3, 0, 'My apologies, Nozari. I have been a bit ''on edge'' as of late. These creatures are attempting to alter the timeways.', 12, 0, 100, 1, 0, 0,  'Andormu',17547),
(@Andormu, 4, 0, 'You do recall the last time that this occurred, yes? Let us hope that the master need not be involved.', 12, 0, 100, 1, 0, 0,  'Andormu',17548),
(@Andormu, 5, 0, 'Absolutely not. We must not place ourselves at risk. With the master away, we are all that is in place to keep the stream intact. Others are due to arrive any moment now. Heroes and adventurers from Azeroth...', 12, 0, 100, 1, 0, 0,  'Andormu',17550);
