
DELETE FROM `creature_text` WHERE `entry`=16819 AND `groupid` IN(1,2);
DELETE FROM `creature_text` WHERE `entry`IN(3230,18481,23054);

INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(3230, 0, 0, 'Hellfire Citadel is ours! The source of Illidan\'s fel orc army is no more! Magtheridon has fallen to the might of $n and $g his:her; allies!', 14, 1, 100, 22, 0, 0, 20765, 2, 'Nazgrel to Player'),
(3230, 1, 0, 'The time for us to rise and strike at the fel orcs that remain is now! Do this for your Warchief! Do this for the Horde!', 14, 1, 100, 22, 0, 0, 20766, 2, 'Nazgrel to Player'),
(18481, 0, 0, 'Silence descends upon Shattrath.', 16, 0, 100, 0, 0, 0, 20776, 2, 'A\'dal to Player'),
(18481, 1, 0, '%s\'s thoughts invade your mind.', 16, 0, 100, 0, 0, 0, 20777, 2, 'A\'dal to Player'),
(18481, 2, 0, 'Kael\'thas Sunstrider has been defeated by $n and $g his:her; allies.', 16, 0, 100, 0, 0, 0, 20778, 2, 'A\'dal to Player'),
(18481, 3, 0, 'The time to strike at the remaining blood elves of Tempest Keep is now. Take arms and let A\'dal\'s song of battle empower you!', 16, 0, 100, 0, 0, 0, 20779, 2, 'A\'dal to Player'),
(23054, 0, 0, 'Your monkeys failed to finish the job, naaru. Beaten but alive... The same mistake was not made when we took command of your vessel.', 14, 0, 100, 1, 0, 0, 20792, 0, 'Kael\'thas Sunstrider to Player'),
(23054, 1, 0, 'All for what? Trinkets? You are too late. The preparations have already begun. Soon the master will make his return.', 14, 0, 100, 274, 0, 0, 20793, 0, 'Kael\'thas Sunstrider to Player'),
(23054, 2, 0, 'And there is nothing you or that fool, Illidan, can do to stop me! You have both served me in your own right - unwittingly.', 14, 0, 100, 1, 0, 0, 20794, 0, 'Kael\'thas Sunstrider to Player'),
(23054, 3, 0, 'Lay down your arms and succumb to the might of Kil\'jaeden!', 14, 0, 100, 14, 0, 0, 20796, 0, 'Kael\'thas Sunstrider to Player'),
(16819, 1, 0, 'The feast of corruption is no more! Magtheridon has fallen to the battle prowess of $n and $g his:her; allies! Witness the might of the Alliance! A pit lord commander is destroyed!', 14, 7, 100, 22, 0, 0, 20754, 2, 'Force Commander Danath Trollbane to Player'),
(16819, 2, 0, 'Hear me brothers and sisters-in-arms! The time of our enemies is at an end! We must strike at the fel orcs that remain! Exterminate them like the vermin that they are! Carry with you the favor of the Sons of Lothar!', 14, 7, 100, 22, 0, 0, 20754, 2, 'Force Commander Danath Trollbane to Player');

UPDATE `creature_template` SET `unit_flags`=768, `InhabitType`=4 WHERE  `entry`=23054;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN(3230,23054);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(3230,23054) AND `source_type`=0;

DELETE FROM `smart_scripts` WHERE `entryorguid` =1848100 AND `source_type`=9;

DELETE FROM `smart_scripts` WHERE `entryorguid` =16819 AND `source_type`=0 AND `id`>1;
DELETE FROM `smart_scripts` WHERE `entryorguid` =18481 AND `source_type`=0 AND `id`>2;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3230, 0, 0, 1, 20, 0, 100, 0, 11003, 0, 0, 0, 5, 15, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Nazgrel - On Quest Reward 11003 - Play emote OneShotRoar (15)'),
(3230, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 7000, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Nazgrel - On Quest Reward 11003 - Say Line 0'),
(3230, 0, 2, 0, 52, 0, 100, 0, 0, 3230, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Nazgrel - On Text Over Line 0 - Say Line 1'),
(16819, 0, 2, 0, 20, 0, 100, 0, 11002, 0, 0, 0, 1, 1, 7000, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Force Commander Danath Trollbane - On Quest Reward 11002 - Say Line 1'),
(16819, 0, 3, 0, 52, 0, 100, 0, 1, 16819, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Force Commander Danath Trollbane - On Text Over Line 1 - Say Line 2'),
(23054, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 11, 39966, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Kael''thas Sunstrider - On On Just Summoned - Cast Kael thas Defeated'),
(18481, 0, 3, 4, 20, 0, 100, 0, 11007, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'A Dal - On Quest Reward 11007 - Store Targetlist'),
(18481, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 1848100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'A Dal - On Quest Reward 11007 - Run Script'),
(1848100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'A Dal - Script - Say Line 0'), -- 13:50:41.485 
(1848100, 9, 1, 0, 0, 0, 100, 0, 4500, 4500, 0, 0, 1, 1, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'A Dal - Script - Say Line 1'), -- 13:50:45.907
(1848100, 9, 2, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'A Dal - Script - Say Line 2'), -- 13:50:49.532
(1848100, 9, 3, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'A Dal - Script - Say Line 3'), -- 13:50:54.407
(1848100, 9, 4, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 12, 23054, 1, 50000, 0, 0, 0, 8, 0, 0, 0, -1884.322, 5420.598, -8.42119, 0.4886922, 'A Dal - Script - Summon Kael''thas Sunstrider'), -- 13:50:55.625
(1848100, 9, 5, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 50, 185170, 300, 0, 0, 0, 0, 8, 0, 0, 0, -1891.344, 5417.036, -5.539243, 0.9781476, 'A Dal - Script - The Mark of Kael''Thas'), -- 13:50:59.922
(1848100, 9, 6, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 23054, 0, 0, 0, 0, 0, 0, 'A Dal - Script - Say Line 0 on Kael''thas Sunstrider'), -- 13:51:00.422 
(1848100, 9, 7, 0, 0, 0, 100, 0, 11000, 11000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 23054, 0, 0, 0, 0, 0, 0, 'A Dal - Script - Say Line 1 on Kael''thas Sunstrider'), -- 13:51:11.360 
(1848100, 9, 8, 0, 0, 0, 100, 0, 11000, 11000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, 23054, 0, 0, 0, 0, 0, 0, 'A Dal - Script - Say Line 2 on Kael''thas Sunstrider'), -- 13:51:22.297 
(1848100, 9, 9, 0, 0, 0, 100, 0, 11000, 11000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 19, 23054, 0, 0, 0, 0, 0, 0, 'A Dal - Script - Say Line 2 on Kael''thas Sunstrider'); -- 13:51:33.219 
