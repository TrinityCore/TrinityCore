--
DELETE FROM `creature_loot_template` WHERE `Entry` =39049 AND `Item`=52270;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES 
(39049, 52270, 0, 75, 1, 1, 0, 1, 1, NULL); --  Plagued Bruin Hide

DELETE FROM `creature_loot_template` WHERE `Entry` IN (1536, 1537, 1662) AND `Item`=52077;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES 
(1536, 52077, 0, 75, 1, 1, 0, 1, 1, NULL), -- Scarlet Missionary, High
(1537, 52077, 0, 75, 1, 1, 0, 1, 1, NULL), -- Scarlet Zealot, High
(1662, 52077, 0, 100, 1, 1, 0, 1, 1, NULL); -- Captain Perrine, Guaranteed

-- Update Duskbat Pelt drop chance for existing entry
UPDATE `creature_loot_template` SET `Chance`=100 WHERE `Entry` =1553 AND `Item`=2876;
-- Insert missing Embalming Ichor drops
DELETE FROM `creature_loot_template` WHERE `Entry`=1554 AND `Item`=2876;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES 
(1554, 2876, 0, 100, 1, 1, 2, 1, 1, NULL);

-- Update Embalming Ichor drop chances for existing entries
UPDATE `creature_loot_template` SET `Chance`=75 WHERE `Entry` IN (1674, 1941) AND `Item`=2834;
-- Insert missing Embalming Ichor drop
DELETE FROM `creature_loot_template` WHERE `Entry`=1675 AND `Item`=2834;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES 
(1675, 2834, 0, 75, 1, 1, 0, 1, 1, NULL);

UPDATE `creature_template` SET `lootid`=39049 WHERE  `entry`=39049;
DELETE FROM `creature_loot_template` WHERE `Entry`=39049 AND `Item`=52270;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES 
(39049, 52270, 0, 75, 1, 1, 0, 1, 1, NULL);
--  The Shadow Grave
SET @Spell            := 91576; -- Spell to summon
SET @Darnell          := 49141; -- Darnell Gardian
SET @Mordo            := 1568; -- Mordo Quest giver
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Darnell AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Darnell*100  AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Darnell*100+1  AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Darnell*100+2  AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Darnell*100+3  AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Darnell*100+4  AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Mordo  AND `source_type` = 0;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Darnell;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Mordo;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@Mordo, 0, 0, 0, 19, 0, 100, 0, 28608, 0, 0, 0, 85, @Spell, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Mordo - On Quest Accept - Cast Spell To Summon'),
(@Darnell, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 80, @Darnell*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darnell - On spawn - set ReactState Defensive'),
(@Darnell*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darnell - On spawn - Talk1'),
(@Darnell*100, 9, 1, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darnell - On spawn - Talk1'),
(@Darnell*100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 1, @Darnell, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darnell - Action list - Go to point'),
(@Darnell, 0, 1, 0, 40, 0, 100, 0, 4, 0, 0, 0, 80, @Darnell*100+1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darnell - On spawn - set ReactState Defensive'),
(@Darnell*100+1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darnell - On spawn - Talk1'),
(@Darnell, 0, 2, 0, 40, 0, 100, 0, 8, 0, 0, 0, 80, @Darnell*100+2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darnell - On spawn - set ReactState Defensive'),
(@Darnell*100+2, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 54, 4000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darnell - On spawn - Talk1'),
(@Darnell*100+2, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darnell - On spawn - Talk1'),
(@Darnell, 0, 3, 0, 40, 0, 100, 0, 9, 0, 0, 0, 80, @Darnell*100+3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darnell - On spawn - set ReactState Defensive'),
(@Darnell*100+3, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 54, 6000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darnell - On spawn - Talk1'),
(@Darnell*100+3, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darnell - On spawn - Talk1'),
(@Darnell*100+3, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darnell - On spawn - Talk1'),
(@Darnell*100+3, 9, 3, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darnell - On spawn - Talk1'),
(@Darnell*100+3, 9, 4, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Darnell - On spawn - Talk1'),
(@Darnell, 0, 4, 0, 40, 0, 100, 0, 10, 0, 0, 0, 80, @Darnell*100+4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darnell - On spawn - set ReactState Defensive'),
(@Darnell*100+4, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 54, 10000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darnell - On spawn - Talk1'),
(@Darnell*100+4, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darnell - On spawn - Talk1'),
(@Darnell*100+4, 9, 2, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 9, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darnell - On spawn - Talk1'),
(@Darnell, 0, 5, 0, 40, 0, 100, 0, 13, 0, 0, 0, 1, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darnell - On spawn - Talk1'),
(@Darnell, 0, 6, 0, 40, 0, 100, 0, 17, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darnell - On spawn - Despawn'); 

DELETE FROM `waypoints` WHERE `entry`=@Darnell;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@Darnell,1,1683.078003, 1669.579346, 135.687851, 'Darnell'), 
(@Darnell,2,1673.481934, 1663.246216, 138.565262, 'Darnell'),
(@Darnell,3,1663.537109, 1662.785278, 141.851089, 'Darnell'),
(@Darnell,4,1644.768921, 1663.085938, 132.478256, 'Darnell'),
(@Darnell,5,1642.878418, 1668.084351, 131.365952, 'Darnell'),
(@Darnell,6,1642.607422, 1675.931519, 126.932091, 'Darnell'),
(@Darnell,7,1646.881104, 1677.484985, 126.519661, 'Darnell'),
(@Darnell,8,1657.310059, 1677.939941, 120.712003, 'Darnell'),
(@Darnell,9,1664.173340, 1662.718872, 120.719086, 'Darnell'),
(@Darnell,10,1657.310059, 1677.939941, 120.772003, 'Darnell'),
(@Darnell,11,1646.881104, 1677.484985, 126.519661, 'Darnell'),
(@Darnell,12,1642.607422, 1675.931519, 126.932091, 'Darnell'),
(@Darnell,13,1642.878418, 1668.084351, 131.365952, 'Darnell'),
(@Darnell,14,1644.768921, 1663.085938, 132.478256, 'Darnell'),
(@Darnell,15,1663.537109, 1662.785278, 141.851089, 'Darnell'),
(@Darnell,16,1673.481934, 1663.246216, 138.565262, 'Darnell'),
(@Darnell,17,1683.078003, 1669.579346, 135.687851, 'Darnell');

DELETE FROM `creature_text` WHERE`entry`= @Darnell;

INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(@Darnell, 0, 0, 'Greetings, $n.', 12, 0, 100, 0, 0, 0, 'Darnell', 49305),
(@Darnell, 1, 0, 'The Shadow Grave is this way.  Follow me, $n.', 12, 0, 100, 1, 0, 0, 'Darnell', 49295),
(@Darnell, 2, 0, 'This way!', 12, 0, 100, 1, 0, 0, 'Darnell', 49296),
(@Darnell, 3, 0, 'Now, where could those supplies be?', 12, 0, 100, 1, 0, 0, 'Darnell', 49297),
(@Darnell, 4, 0, 'Maybe they''re over here?', 12, 0, 100, 1, 0, 0, 'Darnell', 49298),
(@Darnell, 5, 0, 'Hmm...', 12, 0, 100, 1, 0, 0, 'Darnell', 49299),
(@Darnell, 6, 0, 'No, not over here.', 12, 0, 100, 1, 0, 0, 'Darnell', 49300),
(@Darnell, 7, 0, 'Hey, give me a hand, $n!  I can''t find the supplies that Mordo needed!', 12, 0, 100, 1, 0, 0, 'Darnell', 49301),
(@Darnell, 8, 0, 'Let''s see now... where could they be...', 12, 0, 100, 1, 0, 0, 'Darnell', 49302),
(@Darnell, 9, 0, 'Nice work!  You''ve found them.  Let''s bring these back to Mordo.', 12, 0, 100, 1, 0, 0, 'Darnell', 49303),
(@Darnell, 10, 0, 'I saw someone up there whose jaw fell off.  I wonder if Mordo can fix him up?', 12, 0, 100, 1, 0, 0, 'Darnell', 49304);
--
UPDATE `creature` SET `position_x`=1695.631592, `position_y`=1680.963135, `position_z`=134.870605, `orientation`=2.953877 WHERE  `guid`=325130;

-- Risen Recruit SAI
SET @ENTRY := 50414;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,1,0,0,0,0,53,0,50414,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Recruit - On Reset - Start Waypoint (No Repeat)"),
(@ENTRY,0,1,0,40,0,100,0,1,50414,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Recruit - On Waypoint 1 Reached - Run Script");

DELETE FROM `creature_text` WHERE `entry` IN (1568, 50414);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(1568, 0, 0, 'Let\'s see, I just saw a corpse with a jaw that would fit you', 12, 0, 100, 0, 0, 0, 0, 0, 'Mordo'),
(1568, 1, 0, 'That should do the job. Come back right away if it falls off again.', 12, 0, 100, 0, 0, 0, 0, 0, 'Mordo'),
(50414, 0, 0, 'T-thank you, Under-t-taker.', 12, 0, 100, 0, 0, 0, 0, 0, 'Risen Recruit');

-- Actionlist SAI
SET @ENTRY := 5041400;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,5,16,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Recruit - On Script - Play Emote 16"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,5,69,0,0,0,0,0,19,1568,10,0,0,0,0,0,"Risen Recruit - On Script - Play Emote 69"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,19,1568,10,0,0,0,0,0,"Risen Recruit - On Script - Say Line 0"),
(@ENTRY,9,3,0,0,0,100,0,5000,5000,0,0,5,26,0,0,0,0,0,19,1568,10,0,0,0,0,0,"On Script - Play Emote 26"),
(@ENTRY,9,4,0,0,0,100,0,2000,2000,0,0,5,25,0,0,0,0,0,19,1568,10,0,0,0,0,0,"On Script - Play Emote 25"),
(@ENTRY,9,5,0,0,0,100,0,2000,2000,0,0,1,1,0,0,0,0,0,19,1568,10,0,0,0,0,0,"On Script - Say Line 1"),
(@ENTRY,9,6,0,0,0,100,0,0,0,0,0,5,26,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Play Emote 26"),
(@ENTRY,9,7,0,0,0,100,0,2000,2000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 0"),
(@ENTRY,9,8,0,0,0,100,0,2000,2000,0,0,5,66,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Play Emote 66"),
(@ENTRY,9,9,0,0,0,100,0,3000,3000,0,0,53,0,504140,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Start Waypoint"),
(@ENTRY,9,10,0,0,0,100,0,6000,6000,0,0,41,2000,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Despawn In 2000 ms");

DELETE FROM `waypoints` WHERE `entry` IN (50414, 504140);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(50414, 1, 1691.527100, 1675.772339, 135.228180, 'Risen Recruit'),
(504140, 1, 1700.930054, 1655.510010, 129.171005, 'Risen Recruit');
--
UPDATE `creature` SET `spawntimesecs`=1 WHERE  `guid`=325668;

-- Captured Scarlet Zealot SAI
SET @ENTRY := 1931;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,20,0,100,0,24977,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Scarlet Zealot - On Quest 'Johaan's Experiment' Finished - Run Script"),
(@ENTRY,0,1,0,6,0,100,0,0,0,0,0,41,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Scarlet Zealot - On Just Died - Despawn In 3000 ms");

-- Actionlist SAI
SET @ENTRY := 193100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Scarlet Zealot - On Script - Say Line 0"),
(@ENTRY,9,1,0,0,0,100,0,3000,3000,0,0,11,3287,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Scarlet Zealot - On Script - Cast 'Ghoul Form'"),
(@ENTRY,9,2,0,0,0,100,0,2000,2000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Scarlet Zealot - On Script - Say Line 1"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,89,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Scarlet Zealot - On Script - Start Random Movement"),
(@ENTRY,9,4,0,0,0,100,0,6000,6000,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Scarlet Zealot - On Script - Kill Self");

UPDATE `creature_template_addon` SET `emote`=431 WHERE  `entry`=1931;
-- Holland's Experiment

Set @Nain  :=2211;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Nain;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Nain AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Nain*100 AND `source_type` = 9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@Nain, 0, 0, 0, 20, 0, 100, 0, 24996, 0, 0, 0, 80, @Nain*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Nain - On quest rewarded - action list'),
(@Nain*100, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 21, 10, 0, 0, 0, 0, 0, 0, 'Nain - action list - TALK'),
(@Nain*100, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 37, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Nain - action list - Die');

DELETE FROM `creature_text` WHERE `entry`=@Nain ;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(@Nain, 0, 0, ' I raise my brew and hope to be rid of the likes of you! Cheers, you no good scoundrel, $n!', 12, 0, 100, 1, 0, 0, 'Nain', 576);
--
SET @Tetard   :=38937;
SET @Crispin  :=38978;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Crispin;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Tetard;

DELETE FROM `smart_scripts` WHERE `entryorguid` = @Crispin AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Crispin*100 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Tetard AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Tetard*100 AND `source_type` = 9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@Crispin, 0, 0, 0, 19, 0, 100, 0, 24999, 0, 0, 0, 75, 73134, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Nain - On quest rewarded - action list'),
(@Tetard, 0, 0, 0, 23, 0, 100, 0, 73133, 3, 9999, 9999, 37, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tetard - has aura x3 - Die'),
(@Tetard, 0, 1, 0, 6, 0, 100, 0, 0, 0, 0, 0, 33, @Tetard, 0, 0, 0, 0, 0, 21, 15, 0, 0, 0, 0, 0, 0, 'Tetard - on death - KillCredit'),
(@Crispin, 0, 1, 0, 20, 0, 100, 0, 24999, 0, 0, 0, 28, 73134, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Nain - On quest rewarded - action list');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=73133;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,73133,0,0,31,0,3,@Tetard,0,0,0,0,'','Only Tetard are affected by the spell.');
-- The Grasp Weakens 
SET @Malia:=   39117;
SET @Devlin:=  38980;
SET @Spell:=   73180;
SET @Shadow:=  38981;

DELETE FROM `smart_scripts` WHERE `entryorguid` = @Malia  AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Malia*100  AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Malia*100+1  AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Shadow  AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Devlin  AND `source_type` = 0;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@Malia, @Devlin, @Shadow);

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@Malia, 0, 0, 0, 62, 0, 100, 0, 11156, 0, 0, 0, 80, @Malia*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Malia - On Gossip Select - Actionlist'),
(@Malia*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Malia - Actionlist - Close gossip'),
(@Malia*100, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Malia - Actionlist - Talk1'),  -- 0
(@Malia*100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Malia - On Script - Set React Passive'),
(@Malia*100, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, @Malia, 0, 0, 999990, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Malia - Action list - StartWaypoint'),
(@Malia, 0, 1, 0, 40, 0, 100, 0, 4, 0, 0, 0, 80, @Malia*100+1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Malia - On waypointReached - Actionlist'),
(@Malia*100+1, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Malia - Actionlist - Talk'),
(@Malia*100+1, 9, 2, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Malia - Actionlist - Talk'), 
(@Malia*100+1, 9, 3, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Malia - Actionlist - Talk'),
(@Malia*100+1, 9, 4, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Malia - Actionlist - Talk'), 
(@Malia*100+1, 9, 5, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 12, @Devlin, 1, 111110, 0, 0, 0, 8, 0, 0, 0, 2246.889893, 228.612000, 44.834801, 2.019680, 'Malia - Actionlist - Spawn'), 
(@Malia*100+1, 9, 6, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, @Devlin, 10, 0, 0, 0, 0, 0, 'Malia - Actionlist - Talk'), 
(@Malia*100+1, 9, 7, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, @Devlin, 10, 0, 0, 0, 0, 0, 'Malia - Actionlist - Talk'),
(@Malia*100+1, 9, 8, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, @Devlin, 10, 0, 0, 0, 0, 0, 'Malia - Actionlist - Talk'),
(@Malia*100+1, 9, 9, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 19, @Devlin, 10, 0, 0, 0, 0, 0, 'Malia - Actionlist - Talk'),
(@Malia*100+1, 9, 10, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 19, @Devlin, 10, 0, 0, 0, 0, 0, 'Malia - Actionlist - Talk'),
(@Malia*100+1, 9, 11, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 19, @Devlin, 10, 0, 0, 0, 0, 0, 'Malia - Actionlist - Talk'),
(@Malia*100+1, 9, 12, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 6, 0, 0, 0, 0, 0, 19, @Devlin, 10, 0, 0, 0, 0, 0, 'Malia - Actionlist - Talk'),
(@Malia*100+1, 9, 13, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 19, @Devlin, 10, 0, 0, 0, 0, 0, 'Malia - Actionlist - Despawn'),
(@Malia*100+1, 9, 14, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, @Spell, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Malia - Actionlist - cast to summon'),
(@Malia*100+1, 9, 15, 0, 0, 0, 100, 0, 25000, 25000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Malia - Actionlist - Talk'),
(@Malia*100+1, 9, 16, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Malia - Actionlist - Despawn'),
(@Devlin, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 17, 437, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Devlin - On spawn - StateEmote'),
(@Shadow, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 18, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadow - On spawn - UnitFlag 4'),
(@Shadow, 0, 1, 0, 0, 0, 100, 0, 0, 0, 6000, 6000, 11, 16568, 2, 0, 0, 0, 0, 21, 15, 0, 0, 0, 0, 0, 0, 'Shadow - IC - CastSpell');

UPDATE `creature_template` SET `faction`=14, `minlevel`=10, `maxlevel`=11, `inhabittype`=4 WHERE (`entry`=@Shadow);
UPDATE `creature_template` SET `inhabittype`=4 WHERE (`entry`=@Devlin);
UPDATE `creature_template` SET `gossip_menu_id`=11156, `npcflag`=1 WHERE (`entry`=@Malia);

DELETE FROM `waypoints` WHERE `entry`=@Malia;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@Malia,1, 2240.255615, 233.003922, 34.551388, 'Malia'),
(@Malia,2, 2234.646240, 229.994614, 38.211372, 'Malia'),
(@Malia,3, 2236.925537, 226.070419, 38.245140, 'Malia'),
(@Malia,4, 2243.648193, 228.888794, 41.812122, 'Malia');

UPDATE `npc_text` SET `BroadcastTextID0`=39150 WHERE `ID`=15527;

DELETE FROM `gossip_menu` WHERE `entry`=11156 AND `text_id`=15527;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (11156,15527);

DELETE FROM `gossip_menu_option` WHERE `menu_id` = 11156;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`) VALUES (11156, 0, 0, 'I am ready', 39152, 1, 1);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=11156;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`, `ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,11156,0,0,9,25006,0,0,0,'','Show gossip menu if player accept The Grasp Weakens');

DELETE FROM `creature_text` WHERE `entry` IN (@Devlin, @Malia);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(@Malia, 0, 0, 'Very well. Follow me.', 12, 0, 100, 0, 0, 0, 'Malia', 39153),
(@Malia, 1, 0, 'Now it is time for us to begin.', 12, 0, 100, 1, 0, 0, 'Malia', 39154),
(@Malia, 2, 0, 'Devlin Agamand! Listen to my voice!', 14, 0, 100, 22, 0, 0, 'Malia', 39155),
(@Malia, 3, 0, 'Your mortal remains have been gathered, here in this place where you spent your childhood!', 14, 0, 100, 22, 0, 0, 'Malia', 39156),
(@Malia, 4, 0, 'Resist the Lich King''s will, Devlin! Come to us!', 14, 0, 100, 22, 0, 0, 'Malia', 39157),
(@Malia, 5, 0, 'I had better return to my post. You can find me downstairs if you need anything.', 12, 0, 100, 1, 0, 0, 'Malia', 39158),
(@Devlin, 0, 0, 'What''s going on here?', 12, 0, 100, 0, 0, 0, 'Devlin', 39160),
(@Devlin, 1, 0, 'Wait, am I... home?', 12, 0, 100, 0, 0, 0, 'Devlin', 39161),
(@Devlin, 2, 0, 'You people... what are you doing here? Why are you in my house?', 12, 0, 100, 0, 0, 0, 'Devlin', 39162),
(@Devlin, 3, 0, 'Mother... father... Thurman... where are you?', 12, 0, 100, 0, 0, 0, 'Devlin', 39163),
(@Devlin, 4, 0, 'No... I remember. My family is dead. And so am I.', 12, 0, 100, 0, 0, 0, 'Devlin', 39164),
(@Devlin, 5, 0, 'And my soul.... my soul belongs to the Scourge!', 12, 0, 100, 0, 0, 0, 'Devlin', 39165),
(@Devlin, 6, 0, 'DIE, YOU WRETCHES!', 14, 0, 100, 0, 0, 0, 'Devlin', 39166);
-- Take to the Skies
DELETE FROM `gossip_menu` WHERE `entry`=11152 AND `text_id`=15524;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(11152,15524);

UPDATE `npc_text` SET `BroadcastTextID0`=39129 WHERE `ID`=15524;

UPDATE `gossip_menu_option` SET `OptionBroadcastTextID`=39130, `option_id`=1, `npc_option_npcflag`=8192 WHERE `menu_id`=11152 AND `ID`=1;

UPDATE creature_template SET `AIName`='SmartAI' WHERE `entry`=37915;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 37915 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 37915*100 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(37915, 0, 0, 0, 62, 0, 100, 0, 11152, 0, 0, 0, 80, 37915*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '37915 - On Gossip Select - Actionlist'),
(37915*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, '37915 - Actionlist - Close gossip'),
(37915*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 73442, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, '37915 - Actionlist - cast spell');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=11152;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`, `ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,11152,1,0,9,25012,0,0,0,'','Take to the Skies');
-- Variety is the Spice of Death 24976
SET @Cucumber := 38933; -- Fettered Green Whelpling

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Cucumber;

DELETE FROM `smart_scripts` WHERE `entryorguid` = @Cucumber AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Cucumber*100 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@Cucumber, 0, 0, 0, 73, 0, 100, 0, 0, 0, 0, 0, 80, @Cucumber*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cucumber - On Spell_Clic - add item'),
(@Cucumber*100, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cucumber - On Spell_Clic - Despawn');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceEntry`=73123;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(18,@Cucumber,73123,0,0,9,0,24976,0,0,0,0,'','SpellClic require quest 24976');

UPDATE `creature_template` SET `npcflag`=16777216 WHERE `entry` IN (@Cucumber );

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`= @Cucumber AND `spell_id`= 73123;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(@Cucumber, 73123, 1, 0);
-- A Daughter's Embrace

SET @Scarlet1:=   1538;
SET @Scarlet2:=   1540;
SET @Scarlet3:=   1539;
SET @Scarlet4:=   1537;
SET @Scarlet5:=   1536;
SET @Scarlet6:=   1535;
SET @Lilian:=     39038;
SET @Nova:=       32711;
SET @BodyGuard:=  1660;
SET @Melrache:=   1665;
SET @Benedictus:= 39097;
SET @Jump:=       73308;
SET @Sanders:=    13158;
Set @Summon:=     73306;
Set @Aura:=       73305;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Sanders;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Scarlet1;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Scarlet2;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Scarlet3;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Scarlet4;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Scarlet5;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Scarlet6;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Benedictus;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Melrache;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@BodyGuard;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Lilian;

DELETE FROM `smart_scripts` WHERE `entryorguid` = @Sanders AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Lilian AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Lilian*100 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Lilian*100+1 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @BodyGuard AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @BodyGuard*100 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Melrache AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Melrache*100 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Benedictus AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Benedictus*100 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Scarlet1 AND `source_type` = 0;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Scarlet2;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Scarlet2 AND `source_type` = 0;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Scarlet3;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Scarlet3 AND `source_type` = 0;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Scarlet4;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Scarlet4 AND `source_type` = 0;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Scarlet5;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Scarlet5 AND `source_type` = 0;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Scarlet6;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Scarlet6 AND `source_type` = 0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@Scarlet1, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scarlet - On Aggro - talk'),
(@Scarlet2, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scarlet - On Aggro - talk'),
(@Scarlet3, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scarlet - On Aggro - talk'),
(@Scarlet4, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scarlet - On Aggro - talk'),
(@Scarlet5, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scarlet - On Aggro - talk'),
(@Scarlet6, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scarlet - On Aggro - talk'),
(@Scarlet1, 0, 1, 0, 0, 0, 100, 0, 1000, 1000, 10000, 10000, 11, 64431, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Scarlet1 - IC - CAST'),
(@Scarlet1, 0, 2, 0, 0, 0, 100, 0, 4000, 4000, 18000, 18000, 11, 75967, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Scarlet1 - IC - CAST'),
(@Scarlet2, 0, 1, 0, 0, 0, 100, 0, 1000, 1000, 10000, 10000, 11, 64431, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Scarlet2 - IC - CAST'),
(@Scarlet2, 0, 2, 0, 0, 0, 100, 0, 2000, 2000, 180000, 180000, 11, 7164, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Scarlet2 - IC - CAST'),
(@Scarlet2, 0, 3, 0, 0, 0, 100, 0, 5000, 5000, 8000, 8000, 11, 11972, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Scarlet2 - IC - CAST'),
(@Scarlet3, 0, 1, 0, 0, 0, 100, 0, 1000, 1000, 10000, 10000, 11, 64431, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Scarlet3 - IC - CAST'),
(@Scarlet3, 0, 2, 0, 0, 0, 100, 0, 2000, 2000, 30000, 30000, 11, 12544, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Scarlet3 - IC - CAST'),
(@Scarlet3, 0, 3, 0, 0, 0, 100, 0, 5000, 5000, 5000, 5000, 11, 13322, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Scarlet3 - IC - CAST'),
(@Scarlet4, 0, 1, 0, 0, 0, 100, 0, 5000, 5000, 5000, 5000, 11, 84535, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Scarlet4 - IC - CAST'),
(@Scarlet5, 0, 1, 0, 0, 0, 100, 0, 5000, 5000, 4000, 4000, 11, 9053, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Scarlet5 - IC - CAST'),
(@Scarlet6, 0, 1, 0, 0, 0, 100, 0, 5000, 5000, 5000, 5000, 11, 57846, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Scarlet6 - IC - CAST'),
(@Sanders, 0, 0, 0, 19, 0, 100, 0, 25046, 0, 0, 0, 85, @Summon, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Sanders - On Quest Accept - Summon'),
(@Lilian, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 80, @Lilian*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian - On Spawn - action list'),
(@Lilian*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, @Aura, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sanders - Actionlist - CastSpell'),
(@Lilian*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 8, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Benedictus - actionList - react defensif'),
(@Lilian, 0, 1, 0, 0, 0, 100, 0, 0, 0, 4000, 4000, 11, @Nova, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Shadow - IC - CastSpell'),
(@Lilian, 0, 2, 0, 0, 0, 100, 0, 0, 0, 5000, 5000, 11, 73309, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Shadow - IC - CastSpell'),
(@Lilian, 0, 3, 0, 0, 0, 100, 0, 0, 0, 5000, 5000, 11, @Aura, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadow - IC - CastSpell'),
(@Benedictus, 0, 0, 0, 75, 0, 100, 1, 0, @Lilian, 30, 0, 80, @Benedictus*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Benedictus - On creature distance - action list'),
(@Benedictus*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Benedictus - actionList - reactPassif'),
(@Benedictus*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 18, 256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Benedictus - actionList - UnitFlag'),
(@Melrache, 0, 0, 0, 75, 0, 100, 1, 0, @Lilian, 30, 0, 80, @Melrache*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Benedictus - On creature distance - action list'),
(@Melrache*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Benedictus - actionList - reactPassif'),
(@Melrache*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 18, 256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Benedictus - actionList - UnitFlag'),
(@BodyGuard, 0, 0, 0, 75, 0, 100, 1, 0, @Lilian, 30, 0, 80, @BodyGuard*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Benedictus - On creature distance - action list'),
(@BodyGuard*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Benedictus - actionList - reactPassif'),
(@BodyGuard*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 18, 256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Benedictus - actionList - UnitFlag'),
(@Lilian, 0, 4, 0, 75, 0, 100, 1, 0, @Benedictus, 20, 0, 80, @Lilian*100+1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian - On creature distance - action list'),
(@Lilian*100+1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 3071.607178, -563.239685, 126.717987, 0.647956, 'Lilian - action list - Go to position'),
(@Lilian*100+1, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian - action list - Talk1'),
(@Lilian*100+1, 9, 2, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, @Benedictus, 20, 0, 0, 0, 0, 0, 'Lilian - action list - Talk1'),
(@Lilian*100+1, 9, 3, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian - action list - Talk2'),
(@Lilian*100+1, 9, 4, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 11, @Jump, 2, 0, 0, 0, 0, 19, @BodyGuard, 20, 0, 0, 0, 0, 0, 'Lilian - action list - CastSpell'),
(@Lilian*100+1, 9, 5, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 11, @Nova, 2, 0, 0, 0, 0, 19, @BodyGuard, 20, 0, 0, 0, 0, 0, 'Lilian - action list- CastSpell'),
(@Lilian*100+1, 9, 6, 0, 0, 0, 100, 0, 500, 500, 0, 0, 51, 0, 0, 0, 0, 0, 0, 19, @BodyGuard, 20, 0, 0, 0, 0, 0, 'Lilian - action list - Kill'),
(@Lilian*100+1, 9, 7, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 11, @Jump, 2, 0, 0, 0, 0, 19, @Melrache, 20, 0, 0, 0, 0, 0, 'Lilian - action list - CastSpell'),
(@Lilian*100+1, 9, 8, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 11, @Nova, 2, 0, 0, 0, 0, 19, @Melrache, 20, 0, 0, 0, 0, 0, 'Lilian - action list - CastSpell'),
(@Lilian*100+1, 9, 9, 0, 0, 0, 100, 0, 500, 500, 0, 0, 51, 0, 0, 0, 0, 0, 0, 19, @Melrache, 20, 0, 0, 0, 0, 0, 'Lilian - action list - Kill'),
(@Lilian*100+1, 9, 10, 0, 0, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 3071.607178, -563.239685, 126.717987, 0.647956, 'Lilian - action list - Go to position'),
(@Lilian*100+1, 9, 11, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 3071.607178, -563.239685, 126.717987, 0.647956, 'Lilian - action list - SetOrientation'),
(@Lilian*100+1, 9, 12, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian - action list - Talk 3'),
(@Lilian*100+1, 9, 13, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, @Benedictus, 20, 0, 0, 0, 0, 0, 'Lilian - action list - Talk2'),
(@Lilian*100+1, 9, 14, 0, 0, 0, 100, 0, 3000, 5000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian - action list - talk4'),
(@Lilian*100+1, 9, 15, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian - action list - Talk5'),
(@Lilian*100+1, 9, 16, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, @Benedictus, 20, 0, 0, 0, 0, 0, 'Lilian - action list - Talk3'),
(@Lilian*100+1, 9, 17, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 11, @Jump, 2, 0, 0, 0, 0, 19, @Benedictus, 20, 0, 0, 0, 0, 0, 'Lilian - action list - CastSpell'),
(@Lilian*100+1, 9, 18, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 11, @Nova, 2, 0, 0, 0, 0, 19, @Benedictus, 20, 0, 0, 0, 0, 0, 'Lilian - action list - CastSpell'),
(@Lilian*100+1, 9, 19, 0, 0, 0, 100, 0, 500, 500, 0, 0, 51, 0, 0, 0, 0, 0, 0, 19, @Benedictus, 20, 0, 0, 0, 0, 0, 'Lilian - action list - kill'),
(@Lilian*100+1, 9, 20, 0, 0, 0, 100, 0, 0, 0, 0, 0, 33, 39098, 0, 0, 0, 0, 0, 16, 0, 0, 0, 0, 0, 0, 0, 'Lilian - Actionlist - Credit quest'),
(@Lilian*100+1, 9, 21, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian - action list - talk6'),
(@Lilian*100+1, 9, 22, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian - action list - Despawn');

DELETE FROM `creature_text` WHERE `entry` IN (@Scarlet1, @Scarlet2, @Scarlet3, @Scarlet4, @Scarlet5, @Scarlet6, @Lilian, @Benedictus ) ;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(@Scarlet1, 0, 0, 'The Scarlet Crusade shall smite the wicked and drive evil from these lands!', 12, 0, 100, 0, 0, 0, 'Scarlet1', 2628),
(@Scarlet1, 0, 1, 'There is no escape for you.  The Crusade shall destroy all who carry the Scourge''s taint.', 12, 0, 100, 0, 0, 0, 'Scarlet1', 2626),
(@Scarlet1, 0, 2, 'The Light condemns all who harbor evil. Now you will die!', 12, 0, 100, 0, 0, 0, 'Scarlet1', 2627),
(@Scarlet1, 0, 3, 'You carry the taint of the Scourge. Prepare to enter the Twisting Nether.', 12, 0, 100, 0, 0, 0, 'Scarlet1', 2625),
(@Scarlet2, 0, 0, 'The Scarlet Crusade shall smite the wicked and drive evil from these lands!', 12, 0, 100, 0, 0, 0, 'Scarlet1', 2628),
(@Scarlet2, 0, 1, 'There is no escape for you.  The Crusade shall destroy all who carry the Scourge''s taint.', 12, 0, 100, 0, 0, 0, 'Scarlet1', 2626),
(@Scarlet2, 0, 2, 'The Light condemns all who harbor evil. Now you will die!', 12, 0, 100, 0, 0, 0, 'Scarlet1', 2627),
(@Scarlet2, 0, 3, 'You carry the taint of the Scourge. Prepare to enter the Twisting Nether.', 12, 0, 100, 0, 0, 0, 'Scarlet1', 2625),
(@Scarlet3, 0, 0, 'The Scarlet Crusade shall smite the wicked and drive evil from these lands!', 12, 0, 100, 0, 0, 0, 'Scarlet1', 2628),
(@Scarlet3, 0, 1, 'There is no escape for you.  The Crusade shall destroy all who carry the Scourge''s taint.', 12, 0, 100, 0, 0, 0, 'Scarlet1', 2626),
(@Scarlet3, 0, 2, 'The Light condemns all who harbor evil. Now you will die!', 12, 0, 100, 0, 0, 0, 'Scarlet1', 2627),
(@Scarlet3, 0, 3, 'You carry the taint of the Scourge. Prepare to enter the Twisting Nether.', 12, 0, 100, 0, 0, 0, 'Scarlet1', 2625),
(@Scarlet4, 0, 0, 'The Scarlet Crusade shall smite the wicked and drive evil from these lands!', 12, 0, 100, 0, 0, 0, 'Scarlet1', 2628),
(@Scarlet4, 0, 1, 'There is no escape for you.  The Crusade shall destroy all who carry the Scourge''s taint.', 12, 0, 100, 0, 0, 0, 'Scarlet1', 2626),
(@Scarlet4, 0, 2, 'The Light condemns all who harbor evil. Now you will die!', 12, 0, 100, 0, 0, 0, 'Scarlet1', 2627),
(@Scarlet4, 0, 3, 'You carry the taint of the Scourge. Prepare to enter the Twisting Nether.', 12, 0, 100, 0, 0, 0, 'Scarlet1', 2625),
(@Scarlet5, 0, 0, 'The Scarlet Crusade shall smite the wicked and drive evil from these lands!', 12, 0, 100, 0, 0, 0, 'Scarlet1', 2628),
(@Scarlet5, 0, 1, 'There is no escape for you.  The Crusade shall destroy all who carry the Scourge''s taint.', 12, 0, 100, 0, 0, 0, 'Scarlet1', 2626),
(@Scarlet5, 0, 2, 'The Light condemns all who harbor evil. Now you will die!', 12, 0, 100, 0, 0, 0, 'Scarlet1', 2627),
(@Scarlet5, 0, 3, 'You carry the taint of the Scourge. Prepare to enter the Twisting Nether.', 12, 0, 100, 0, 0, 0, 'Scarlet1', 2625),
(@Scarlet6, 0, 0, 'The Scarlet Crusade shall smite the wicked and drive evil from these lands!', 12, 0, 100, 0, 0, 0, 'Scarlet1', 2628),
(@Scarlet6, 0, 1, 'There is no escape for you.  The Crusade shall destroy all who carry the Scourge''s taint.', 12, 0, 100, 0, 0, 0, 'Scarlet1', 2626),
(@Scarlet6, 0, 2, 'The Light condemns all who harbor evil. Now you will die!', 12, 0, 100, 0, 0, 0, 'Scarlet1', 2627),
(@Scarlet6, 0, 3, 'You carry the taint of the Scourge. Prepare to enter the Twisting Nether.', 12, 0, 100, 0, 0, 0, 'Scarlet1', 2625),
(@Lilian, 0, 0, 'Father!', 12, 0, 100, 0, 0, 0, 'Lilian', 39138),
(@Lilian, 1, 0, 'Shut up.', 12, 0, 100, 0, 0, 0, 'Lilian', 39140),
(@Lilian, 2, 0, 'You raised me to be a killer.  How am I doing, daddy?', 12, 0, 100, 0, 0, 0, 'Lilian', 39141),
(@Lilian, 3, 0, 'But wait... I remember now. You taught me to only kill the undead. So you do want me to kill myself, daddy?', 12, 0, 100, 0, 0, 0, 'Lilian', 39143),
(@Lilian, 4, 0, 'Then again, why kill myself... when I can kill YOU instead!', 12, 0, 100, 0, 0, 0, 'Lilian', 39145),
(@Lilian, 5, 0, 'Thanks for everything... father.', 12, 0, 100, 0, 0, 0, 'Lilian', 39146),
(@Benedictus, 0, 0, 'Lilian... you''re... it''s so nice to see you well.', 12, 0, 100, 0, 0, 0, 'Benedictus', 39139),
(@Benedictus, 1, 0, 'I, ah...', 12, 0, 100, 0, 0, 0, 'Benedictus', 39142),
(@Benedictus, 2, 0, 'Lilian, I...', 12, 0, 100, 0, 0, 0, 'Benedictus', 39144);
-- A Little Oomph
SET @Dithers:=  11057;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Dithers;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Dithers AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@Dithers, 0, 0, 0, 20, 0, 100, 0, 25013, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zealot - On quest rewarded - talk');
DELETE FROM `creature_text` WHERE `entry`=@Dithers ;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(@Dithers, 0, 0, 'Now THAT''s what I call oomph! I wish all our potions did this!', 12, 0, 100, 1, 0, 0, 'Dithers', 44553);
--
SET @ENTRY := 49044;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,19,0,100,0,24959,0,0,0,11,73524,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Agatha - On quest 24959 - cast spell"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,28,73523,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Agatha - Remove aura from the player");

DELETE FROM `spell_area` WHERE spell=65051 and area=5692;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `racemask`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES
(65051, 5692, 0, 28608, 16, 1, 0, 3);
SET @Spell            := 91938; -- Spell to summon
SET @Darnell          := 49337; -- Darnell Gardian
SET @Caice            := 2307;  -- Caice Quest giver
SET @Saltain          := 1740;  -- Deathguard Saltain
SET @Corpse           := 49340; -- Scarlet Corpse

DELETE FROM `smart_scripts` WHERE `entryorguid` = @Darnell AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Darnell*100  AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Darnell*100+1  AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Darnell*100+2  AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Saltain AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Saltain*100  AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Saltain*100+1  AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Caice  AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Caice*100  AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Corpse AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Corpse*100  AND `source_type` = 9;

UPDATE `creature_template` SET `AIName`='SmartAI', `npcflag`=16777216, `VehicleId`= 1392 WHERE `entry`=@Darnell;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@Caice, @Saltain);
UPDATE `creature_template` SET `AIName`='SmartAI', npcflag=0 WHERE `entry`=@Corpse;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@Caice, 0, 0, 0, 19, 0, 100, 0, 25089, 0, 0, 0, 85, @Spell, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Caice - On Quest Accept - Cast Spell To Summon'),
(@Darnell, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 80, @Darnell*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darnell - On spawn - Action list'),
(@Darnell*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darnell - On spawn - set ReactState passif'),
(@Darnell*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darnell - On spawn - Talk1'),
(@Darnell*100, 9, 2, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darnell - On spawn - Talk1'),
(@Darnell*100, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 1, @Darnell, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darnell - Action list - Start wp'),
(@Darnell, 0, 1, 0, 40, 0, 100, 0, 5, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darnell - On spawn - Talk1'),
(@Darnell, 0, 2, 0, 40, 0, 100, 0, 7, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darnell - On spawn - Talk1'),
(@Saltain, 0, 0, 0, 19, 0, 100, 0, 26800, 0, 0, 0, 80, @Saltain*100+1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Saltain - On Quest accept- action list'),
(@Saltain*100+1, 9, 0, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 85, @Spell, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Saltain - Action list - Cast Spell To Summon'), -- 3secs delay to avoid the despawn
(@Darnell, 0, 3, 0, 54, 0, 100, 0, 0, 0, 0, 0, 80, @Darnell*100+1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darnell - On spawn - Action list'),
(@Darnell*100+1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darnell - On spawn - set ReactState passif'),
(@Darnell*100+1, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darnell - On spawn - Talk1'),
(@Darnell*100+1, 9, 2, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darnell - On spawn - Talk1'),
(@Corpse, 0, 0, 0, 75, 0, 100, 1, 0, @Darnell, 3, 0, 80, @Corpse*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Corpse - On DISTANCE_CREATURE - Action list'),
(@Corpse*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 46598, 1, 0, 0, 0, 0, 19, @Darnell, 10, 0, 0, 0, 0, 0, 'Corpse - Action list - cast spell'),
(@Corpse*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 33, @Corpse, 0, 0, 0, 0, 0, 21, 10, 0, 0, 0, 0, 0, 0, 'Corpse - Actionlist - Credit quest'),
(@Saltain, 0, 1, 0, 20, 0, 100, 0, 26800, 0, 0, 0, 80, @Saltain*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Saltain - On Quest rewarded- action list'),
(@Saltain*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 19, @Darnell, 20, 0, 0, 0, 0, 0, 'Saltain - action list - Despawn'),
(@Saltain*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 11, @Corpse, 20, 0, 0, 0, 0, 0, 'Saltain - action list - Despawn'),
(@Saltain, 0, 2, 0, 20, 0, 100, 0, 25089, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 19, @Darnell, 20, 0, 0, 0, 0, 0, 'Saltain - On Quest rewarded - despawn'); 

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=@Darnell;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,4,@Darnell,0,0,9,0,26800,0,0,0,0,'','Event quest 26800'),
(22,1,@Darnell,0,0,9,0,25089,0,0,1,0,'','Event quest 25089'); 

DELETE  FROM `creature_text` WHERE `entry`= @Darnell;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(@Darnell, 0, 0, 'Hello again.', 12, 0, 100, 3, 0, 0, 'Darnell', 49455),
(@Darnell, 1, 0, 'I know the way to Deathknell. Come with me!', 12, 0, 100, 273, 0, 0, 'Darnell', 49456),
(@Darnell, 2, 0, 'Good, you''re still here. Now, where''s Deathguard Saltain?', 12, 0, 100, 1, 0, 0, 'Darnell', 49457),
(@Darnell, 3, 0, 'Ah, here he is.', 12, 0, 100, 1, 0, 0, 'Darnell', 49458),
(@Darnell, 4, 0, 'Let''s get moving, $n. Saltain said that we''d fine some corpses up here.', 12, 0, 100, 1, 0, 0, 'Darnell', 49459),
(@Darnell, 5, 0, 'I think I see some corpses up ahead. Let''s go, $n! You do the searching and fighting. I''ll do the lifting.', 12, 0, 100, 0, 0, 0, 'Darnell', 49460);

DELETE FROM `waypoints` WHERE `entry`=@Darnell;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@Darnell,1,1692.472168, 1653.235474, 130.319809, 'Darnell'), 
(@Darnell,2,1697.396973, 1653.904175, 128.853043, 'Darnell'), 
(@Darnell,3,1721.264160, 1635.621948, 121.329689, 'Darnell'), 
(@Darnell,4,1765.116577, 1602.026978, 109.535789, 'Darnell'), 
(@Darnell,5,1798.010742, 1591.826904, 101.370865, 'Darnell'), 
(@Darnell,6,1847.364136, 1587.727539, 93.158165, 'Darnell'), 
(@Darnell,7,1860.151245, 1601.413208, 94.669510, 'Darnell');
-- The Wakening 24960
SET @Valdred   :=   49231;  
SET @Marshal   :=   49230; 
SET @Lilian    :=   38895;  
SET @Caice     :=   2307;

DELETE FROM `smart_scripts` WHERE `entryorguid` = @Valdred  AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Valdred*100  AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Marshal  AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Marshal*100  AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Lilian  AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Lilian*100  AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Caice  AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Caice*100  AND `source_type` = 9;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Valdred;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Marshal;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Lilian;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Caice;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@Caice, 0, 0, 0, 19, 0, 100, 0, 24960, 0, 0, 0, 80, @Caice*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Caice - On quest accpet - Actionlist'),
(@Caice*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 91876, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Caice - Actionlist - cast spell'),
(@Caice*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 91874, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Caice - Actionlist - Cast spell'),
(@Caice*100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 91873, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Caice - Actionlist - Cast spell'),
(@Valdred, 0, 0, 0, 62, 0, 100, 0, 12489, 0, 0, 0, 80, @Valdred*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Valdred - On Gossip Select - Actionlist'),
(@Valdred*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Valdred - Actionlist - Close gossip'),
(@Valdred*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 33, @Valdred, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Valdred - Actionlist - Credit quest'),
(@Valdred*100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Valdred - Actionlist - Talk1'),
(@Valdred*100, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 28, 68442, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Valdred - Actionlist - remove aura state kneels'),
(@Valdred*100, 9, 4, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 1689.709961, 1674.790039, 135.675003, 0.349066, 'Valdred - Action list - Go to point'),
(@Valdred*100, 9, 5, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Valdred - Actionlist - Talk2'),
(@Valdred*100, 9, 6, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Valdred - Actionlist - Despawn'),
(@Valdred, 0, 1, 0, 54, 0, 100, 0, 0, 0, 0, 0, 75, 68442, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Valdred - On spawn - add aura state kneels'),
(@Marshal, 0, 0, 0, 62, 0, 100, 0, 12486, 0, 0, 0, 80, @Marshal*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Marshal - On Gossip Select - Actionlist'),
(@Marshal*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Marshal - Actionlist - Close gossip'),
(@Marshal*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 33, @Marshal, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Marshal - Actionlist - Credit quest'),
(@Marshal*100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Marshal - Actionlist - Talk1'),
(@Marshal*100, 9, 4, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 1753.036621, 1613.100586, 113.051300, 2.014602, 'Marshal - Action list - Go to point'),
(@Marshal*100, 9, 6, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Marshal - Actionlist - Despawn'),
(@Lilian, 0, 0, 0, 62, 0, 100, 0, 12484, 0, 0, 0, 80, @Lilian*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian - On Gossip Select - Actionlist'),
(@Lilian*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Lilian - Actionlist - Close gossip'),
(@Lilian*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 33, @Lilian, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Lilian - Actionlist - Credit quest'),
(@Lilian*100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian - Actionlist - Talk1'),
(@Lilian*100, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 30, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian - Actionlist - Set state none'),
(@Lilian*100, 9, 4, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 1727.873535, 1629.106567, 118.862335, 5.497842, 'Lilian - Action list - Go to point'),
(@Lilian*100, 9, 6, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian - Actionlist - Despawn'),
(@Lilian, 0, 1, 0, 54, 0, 100, 0, 0, 0, 0, 0, 17, 431, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian - On spawn - set emote state');

UPDATE `creature_template` SET `gossip_menu_id`=12487, `npcflag`=1 WHERE (`entry`=@Valdred);
UPDATE `creature_template` SET `gossip_menu_id`=12485, `npcflag`=1 WHERE (`entry`=@Marshal);
UPDATE `creature_template` SET `gossip_menu_id`=12483, `npcflag`=1 WHERE (`entry`=@Lilian);

-- Valdred
UPDATE `npc_text` SET `BroadcastTextID0`=49348 WHERE `ID`=17569;
UPDATE `npc_text` SET `BroadcastTextID0`=49349 WHERE `ID`=17570;
UPDATE `npc_text` SET `BroadcastTextID0`=49350 WHERE `ID`=17571;

DELETE FROM `gossip_menu` WHERE `entry`=12487 AND `text_id`=17569;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (12487,17569);
DELETE FROM `gossip_menu` WHERE `entry`=12488 AND `text_id`=17570;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (12488,17570);
DELETE FROM `gossip_menu` WHERE `entry`=12489 AND `text_id`=17571;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (12489,17571);

DELETE FROM `gossip_menu_option` WHERE `menu_id` = 12487;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`) VALUES (12487, 0, 0, 'Don''t you remember? You died.', 49352, 1, 1, 12488);

DELETE FROM `gossip_menu_option` WHERE `menu_id` = 12488;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`) VALUES (12488, 0, 0, 'Calm down, Valdred. Undertaker Mordo probably sewed some new ones on for you.', 49353, 1, 1, 12489);

DELETE FROM `gossip_menu_option` WHERE `menu_id` = 12489;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`) VALUES (12489, 0, 0, 'You talk to Undertaker Mordo. He''ll tell you what to do. That''s all I know.', 49354, 1, 1);
-- End Valdred

-- Marshal
UPDATE `npc_text` SET `BroadcastTextID0`=49343 WHERE `ID`=17566;
UPDATE `npc_text` SET `BroadcastTextID0`=49344 WHERE `ID`=17567;

DELETE FROM `gossip_menu` WHERE `entry`=12485 AND `text_id`=17566;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (12485,17566);
DELETE FROM `gossip_menu` WHERE `entry`=12486 AND `text_id`=17567;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (12486,17567);

DELETE FROM `gossip_menu_option` WHERE `menu_id` = 12485;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`) VALUES (12485, 0, 0, 'I''m not here to fight you. I''ve only been asked to speak with you.', 49346, 1, 1, 12486);

DELETE FROM `gossip_menu_option` WHERE `menu_id` = 12486;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`) VALUES (12486, 0, 0, 'You are free to do whatever you like.', 49347, 1, 1);
-- End Marshal

-- Lilian
UPDATE `npc_text` set `BroadcastTextID0`=49334 WHERE `ID`=17564;
UPDATE `npc_text` set `BroadcastTextID0`=49335 WHERE `ID`=17565;

DELETE FROM `gossip_menu` WHERE `entry`=12483 AND `text_id`=17564;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (12483,17564);
DELETE FROM `gossip_menu` WHERE `entry`=12484 AND `text_id`=17565;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (12484,17565);

DELETE FROM `gossip_menu_option` WHERE `menu_id` = 12483;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`) VALUES (12483, 0, 0, 'I''m not an abomination, I''m simply undead. I just want to speak with you.', 49339, 1, 1, 12484);

DELETE FROM `gossip_menu_option` WHERE `menu_id` = 12484;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`) VALUES (12484, 0, 0, 'Lilian, do you realize that you are undead yourself?', 49340, 1, 1);
-- End Lilian

DELETE FROM `creature_text` WHERE `entry` IN (@Valdred, @Marshal, @Lilian);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(@Valdred, 0, 0, 'I see. Well then, let''s get to work, $n! The Dark Lady needs us, right?', 12, 0, 100, 1, 0, 0, 'Valdred', 49351),
(@Valdred, 1, 0, 'Valdred Moray, reporting for duty, sir!', 14, 0, 100, 1, 0, 0, 'Valdred', 49408),
(@Marshal, 0, 0, 'Who are you calling a monster? You''re the monster! I''m just a man who died.', 12, 0, 100, 1, 0, 0, 'Marshal', 49345),
(@Lilian, 0, 0, 'No. You''re lying! My father will protect me!', 12, 0, 100, 0, 0, 0, 'Lilian', 49337);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=12487;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`, `ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,12487,0,0,9,24960,0,0,0,'','Show gossip menu if player accept The_Wakening');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=12485;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`, `ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,12485,0,0,9,24960,0,0,0,'','Show gossip menu if player accept The_Wakening');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=12483;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`, `ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,12483,0,0,9,24960,0,0,0,'','Show gossip menu if player accept The_Wakening');
-- A Scarlet Letter 24979

SET @Lilian:=       38999;
SET @Gebler:=       39002;

DELETE FROM `smart_scripts` WHERE `entryorguid` = @Lilian AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Lilian*100  AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Gebler  AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Gebler*100  AND `source_type` = 9;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Lilian;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Gebler;

DELETE FROM `waypoints` WHERE entry=@Gebler;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@Gebler,1, 2451.679932, 1590.894897, 72.156181, 'Joseph'),
(@Gebler,2, 2447.750977, 1587.760864, 72.156181, 'Joseph'),
(@Gebler,3, 2441.820068, 1590.969360, 72.156181, 'Joseph'),
(@Gebler,4, 2441.470703, 1597.166748, 72.156853, 'Joseph');

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@Lilian, 0, 0, 0, 62, 0, 100, 0, 11136, 0, 0, 0, 80, @Lilian*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian - On Gossip Select - Actionlist'),
(@Lilian*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Lilian - Actionlist - Close gossip'),
(@Lilian*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian - Actionlist - Talk1'),  
(@Lilian*100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 2442.929932, 1600.719971, 72.155197, 3.880454, 'Lilian - action list - set orientation'),
(@Lilian*100, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, @Gebler, 8, 6666, 0, 0, 0, 8, 0, 0, 0, 2444.511719, 1599.778687, 66.572655, 5.399958, 'Lilian - action list - Spawn Gebler'),
(@Lilian*100, 9, 4, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, @Gebler, 30, 0, 0, 0, 0, 0, 'Gebler - Action list - Talk2'),
(@Lilian*100, 9, 5, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian - Actionlist - Talk'),
(@Lilian*100, 9, 6, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, @Gebler, 30, 0, 0, 0, 0, 0, 'Gebler - Action list - Talk2'),
(@Lilian*100, 9, 7, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian - Actionlist - Talk'),
(@Lilian*100, 9, 8, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, @Gebler, 15, 0, 0, 0, 0, 0, 'Gebler - Action list - Talk2'),
(@Lilian*100, 9, 9, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 19, @Gebler, 15, 0, 0, 0, 0, 0, 'Gebler - Action list - Talk2'),
(@Lilian*100, 9, 10, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 11, 73304, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian - Actionlist - cast spell'),
(@Lilian*100, 9, 11, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 11, 73453, 1, 0, 0, 0, 0, 19, @Gebler, 15, 0, 0, 0, 0, 0, 'Lilian - Actionlist - cast spell'),
(@Lilian*100, 9, 12, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 51, 0, 0, 0, 0, 0, 0, 19, @Gebler, 15, 0, 0, 0, 0, 0, 'Lilian - Actionlist - kill'),
(@Lilian*100, 9, 13, 0, 0, 0, 100, 0, 0, 0, 0, 0, 28, 73304, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian - Actionlist - remove aura'),
-- (@Lilian*100, 9, 14, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 2442.929932, 1600.719971, 72.155197, 1.937310, 'Lilian - action list - Go to pos'),
(@Lilian*100, 9, 14, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian - Actionlist - Talk1'),
(@Lilian*100, 9, 15, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian - Actionlist - Talk1'),
(@Lilian*100, 9, 16, 0, 0, 0, 100, 0, 0, 0, 0, 0, 33, @Lilian, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Lilian - Actionlist - Credit quest'),
(@Lilian*100, 9, 17, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian - Actionlist - despawn'),

(@Gebler, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 80,@Gebler*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gebler - On spawn - Action list'),
(@Gebler*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lightfire - On Script - Set React Passive'),
(@Gebler*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 18, 256, 0, 0, 0, 0, 0,1, 0, 0, 0, 0, 0, 0, 0, 'Lightfire - On Script - Set Immune To PC'),
(@Gebler*100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, @Gebler, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gebler - Action list - waypoint');

Delete from `creature_text` where `entry`= @Lilian;
Delete from `creature_text` where `entry`= @Gebler;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(@Lilian, 0, 0, 'Yes, my... wait, be quiet! I hear the lieutenant approaching.', 12, 0, 100, 0, 0, 0, 'Lilian', 39000),
(@Lilian, 1, 0, 'Gebler, you came! What did he say?', 12, 0, 100, 1, 0, 0, 'Lilian', 38994),
(@Lilian, 2, 0, 'What? NO! This can''t be! Gebler, you know me... we were friends once!', 12, 0, 100, 1, 0, 0, 'Lilian', 38996),
(@Lilian, 3, 0, 'Gebler, father, why would you...', 12, 0, 100, 1, 0, 0, 'Lilian', 39001),
(@Lilian, 4, 0, 'The world of the living may have turned its back on me, but I''m no damned Scourge. Just go.', 12, 0, 100, 1, 0, 0, 'Lilian', 38999),
(@Gebler, 0, 0, 'The time has come, my little captive... word has come back from your father.', 12, 0, 100, 0, 0, 0, 'Gebler', 38993),
(@Gebler, 1, 0, 'High Priest Voss denounces you as a daughter. He''s ordered that you be executed immediately.', 12, 0, 100, 1, 0, 0, 'Gebler', 38995),
(@Gebler, 2, 0, 'The High Priest sends his regrets. He had hoped that one day you would be a powerful weapon against our enemies.', 12, 0, 100, 1, 0, 0, 'Gebler', 38997),
(@Gebler, 3, 0, 'Unfortunately, you were too dangerous in life, and you''re far too dangerous in undeath. I will enjoy killing you, you Scourged witch...', 12, 0, 100, 1, 0, 0, 'Gebler', 38998);

UPDATE `creature_template` SET `gossip_menu_id`=11134, npcflag=1 WHERE (`entry`=@Lilian);
-- Lilian
update npc_text set BroadcastTextID0=38985 where `ID`=15487;
update npc_text set BroadcastTextID0=38987 where `ID`=15488;
update npc_text set BroadcastTextID0=38990 where `ID`=15489;

Delete from gossip_menu where `entry`=11134 and `text_id`=15487;
insert into gossip_menu (`entry`, `text_id`) values (11134, 15487);
Delete from gossip_menu where `entry`=11135 and `text_id`=15488;
insert into gossip_menu (`entry`, `text_id`) values (11135,15488);
Delete from gossip_menu where `entry`=11136 and `text_id`=15489;
insert into gossip_menu (`entry`, `text_id`) values (11136,15489);

DELETE FROM `gossip_menu_option` WHERE `menu_id` = 11134;
INSERT INTO `gossip_menu_option` (`menu_id`, id, option_icon, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`) 
VALUES (11134, 0, 0, 'I''m here to rescue you.', 38986, 1, 1, 11135);

DELETE FROM `gossip_menu_option` WHERE `menu_id` = 11135;
INSERT INTO `gossip_menu_option` (`menu_id`, id, option_icon, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`)
VALUES (11135, 0, 0, 'Lilian, you''re one of the Forsaken, like me.  Which brings the question: why did the Scarlet Crusade put you in a cage?  They usually kill the undead on sight.', 38988, 1, 1, 11136);

DELETE FROM `gossip_menu_option` WHERE `menu_id` = 11136;
INSERT INTO `gossip_menu_option` (`menu_id`, id, option_icon, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`) 
VALUES (11136, 0, 0, 'Your father?', 38991, 1, 1);
-- End Lilian
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=11134;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`, `ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,11134,0,0,9,24979,0,0,0,'','Show gossip menu if player accept A Scarlet Letter');

DELETE FROM `creature_loot_template` WHERE `Entry`=1535 AND `Item`=52079;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES 
(1535, 52079, 0, 75, 0, 1, 0, 1, 1, NULL); -- Scarlet Warrior, High
UPDATE `npc_text` SET `BroadcastTextID0`=38980 WHERE `ID`=15486;
DELETE FROM `gossip_menu` WHERE `entry`=11133 AND `text_id`=15486;
INSERT INTO `gossip_menu` (`entry`, `text_id`)  VALUES (11133,15486);
DELETE FROM `gossip_menu_option` WHERE `menu_id` = 11133;
INSERT INTO `gossip_menu_option` (`menu_id`, id, option_icon, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`) VALUES 
(11133, 0, 0, 'You''re not hideous, Lilian... you''re one of us.  Here, look in this mirror, see for yourself.', 38981, 1, 1);

-- Lilian Voss SAI
SET @ENTRY := 38910;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,1,100,0,11133,0,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lilian Voss - On Gossip Option 0 Selected - Run Script (Phase 1)"),
(@ENTRY,0,1,8,61,1,100,0,11133,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Lilian Voss - On Gossip Option 0 Selected - Close Gossip (Phase 1)"),
(@ENTRY,0,2,3,62,2,100,0,11133,0,0,0,80,@ENTRY*100+01,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lilian Voss - On Gossip Option 0 Selected - Run Script (Phase 2)"),
(@ENTRY,0,3,9,61,2,100,0,11133,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Lilian Voss - On Gossip Option 0 Selected - Close Gossip (Phase 2)"),
(@ENTRY,0,4,0,25,0,100,0,0,0,0,0,17,431,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lilian Voss - On Reset - Set Emote State 431"),
(@ENTRY,0,5,0,25,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lilian Voss - On Reset - Set Event Phase 1"),
(@ENTRY,0,6,0,40,0,100,0,11,@ENTRY*100+00,0,0,17,431,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lilian Voss - On Waypoint 11 Reached - Set Emote State 431"),
(@ENTRY,0,7,0,40,0,100,0,11,@ENTRY*100+01,0,0,17,431,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lilian Voss - On Waypoint 11 Reached - Set Emote State 431"),
(@ENTRY,0,8,0,61,0,100,0,11133,0,0,0,85,73210,0,0,0,0,0,7,0,0,0,0,0,0,0,"Lilian Voss - On Gossip Option 0 Selected - Invoker Cast 'Show Mirror' (Phase 1)"),
(@ENTRY,0,9,0,61,0,100,0,11133,0,0,0,85,73210,0,0,0,0,0,7,0,0,0,0,0,0,0,"Lilian Voss - On Gossip Option 0 Selected - Invoker Cast 'Show Mirror' (Phase 1)");

DELETE FROM `creature_text` WHERE `entry`=38910 ;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(38910, 0, 0, 'You don''t understand... I CAN''T be undead! Not me, not now...', 12, 0, 100, 22, 0, 0, 'Lilian', 38982);

-- Actionlist SAI
SET @ENTRY := 3891000;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,17,26,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lilian Voss - On Script - Set Emote State 26"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,2000,2000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lilian Voss - On Script - Say Line 0"),
(@ENTRY,9,2,0,0,0,100,0,2000,2000,2000,2000,33,38910,0,0,0,0,0,17,0,30,0,0,0,0,0,"Lilian Voss - On Script - Quest Credit 'The Truth of the Grave'"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,53,1,3891000,0,0,0,0,1,0,0,0,0,0,0,0,"Lilian Voss - On Script - Start Waypoint"),
(@ENTRY,9,4,0,0,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lilian Voss - On Script - Set Event Phase 2");

-- Actionlist SAI
SET @ENTRY := 3891001;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,17,26,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lilian Voss - On Script - Set Emote State 26"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,2000,2000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lilian Voss - On Script - Say Line 0"),
(@ENTRY,9,2,0,0,0,100,0,2000,2000,2000,2000,33,38910,0,0,0,0,0,17,0,30,0,0,0,0,0,"Lilian Voss - On Script - Quest Credit 'The Truth of the Grave'"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,53,1,3891001,0,0,0,0,1,0,0,0,0,0,0,0,"Lilian Voss - On Script - Start Waypoint"),
(@ENTRY,9,4,0,0,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lilian Voss - On Script - Set Event Phase 1");

DELETE FROM `waypoints` WHERE entry=3891000;
INSERT INTO `waypoints`(entry, pointid, position_x, position_y, position_z) VALUES
(3891000, 1, 1857.42, 1561.47, 99.079),
(3891000, 2, 1864.89, 1574.94, 99.0361),
(3891000, 3, 1868.91, 1575.56, 97.5441),
(3891000, 4, 1875.28, 1574.12, 94.314),
(3891000, 5, 1875.91, 1572.36, 94.314),
(3891000, 6, 1873, 1570.42, 94.314),
(3891000, 7, 1868.25, 1568.28, 94.314),
(3891000, 8, 1864.41, 1567.87, 94.314),
(3891000, 9, 1861.8, 1563.51, 94.3124),
(3891000, 10, 1860.59, 1558.04, 94.782),
(3891000, 11, 1857.21, 1555.61, 94.7926);

DELETE FROM `waypoints` WHERE entry=3891001;
INSERT INTO `waypoints`(entry, pointid, position_x, position_y, position_z) VALUES
(3891001, 11, 1854.83, 1555.63, 99.07),
(3891001, 10, 1857.42, 1561.47, 99.079),
(3891001, 9, 1864.89, 1574.94, 99.0361),
(3891001, 8, 1868.91, 1575.56, 97.5441),
(3891001, 7, 1875.28, 1574.12, 94.314),
(3891001, 6, 1875.91, 1572.36, 94.314),
(3891001, 5, 1873, 1570.42, 94.314),
(3891001, 4, 1868.25, 1568.28, 94.314),
(3891001, 3, 1864.41, 1567.87, 94.314),
(3891001, 2, 1861.8, 1563.51, 94.3124),
(3891001, 1, 1860.59, 1558.04, 94.782);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=11133;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`, `ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,11133,0,0,9,24961,0,0,0,'','Show gossip if player has Quest: the-truth-of-the-grave');
-- Tirisfal Farmhand SAI
SET @ENTRY := 1935;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tirisfal Farmhand - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,1,0,4,0,10,0,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tirisfal Farmhand - On Aggro - Say Line 0");

-- Tirisfal Farmer SAI
SET @ENTRY := 1934;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tirisfal Farmer - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,4000,4500,12000,20000,11,80382,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tirisfal Farmer - In Combat - Cast 'Cast Dirt Toss'"),
(@ENTRY,0,2,0,4,0,10,0,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tirisfal Farmhand - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `entry` IN (1934, 1935);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(1934, 0, 0, 'Get out of my kitchen!', 12, 0, 100, 0, 0, 0, 44544, 0, 'Tirisfal Farmer'),
(1934, 0, 1, 'Get back, $r!', 12, 0, 100, 0, 0, 0, 44542, 0, 'Tirisfal Farmer'),
(1934, 0, 2, 'No, no, no... you took my family, but you won''t take my land!', 12, 0, 100, 0, 0, 0, 44541, 0, 'Tirisfal Farmer'),
(1934, 0, 3, 'Why won''t you leave us alone?', 12, 0, 100, 0, 0, 0, 44543, 0, 'Tirisfal Farmer'),
-- 
(1935, 0, 0, 'Get out of my kitchen!', 12, 0, 100, 0, 0, 0, 44544, 0, 'Tirisfal Farmhand'),
(1935, 0, 1, 'Get back, $r!', 12, 0, 100, 0, 0, 0, 44542, 0, 'Tirisfal Farmhand'),
(1935, 0, 2, 'No, no, no... you took my family, but you won''t take my land!', 12, 0, 100, 0, 0, 0, 44541, 0, 'Tirisfal Farmhand'),
(1935, 0, 3, 'Why won''t you leave us alone?', 12, 0, 100, 0, 0, 0, 44543, 0, 'Tirisfal Farmhand');

-- The Chef SAI
SET @ENTRY := 47405;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,120000,120000,120000,120000,53,0,47405,0,0,0,0,1,0,0,0,0,0,0,0,"The Chef - Out of Combat - Start Waypoint"),
(@ENTRY,0,1,2,40,0,100,0,2,47405,0,0,54,11000,0,0,0,0,0,1,0,0,0,0,0,0,0,"The Chef - On Waypoint 2 Reached - Pause Waypoint"),
(@ENTRY,0,2,0,61,0,100,0,2,47405,0,0,17,233,0,0,0,0,0,1,0,0,0,0,0,0,0,"The Chef - On Waypoint 2 Reached - Set Emote State 233"),
(@ENTRY,0,3,4,40,0,100,0,3,47405,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,"The Chef - On Waypoint 3 Reached - Pause Waypoint"),
(@ENTRY,0,4,0,61,0,100,0,3,47405,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"The Chef - On Waypoint 3 Reached - Set Emote State 69"),
(@ENTRY,0,5,0,40,0,100,0,4,47405,0,0,17,26,0,0,0,0,0,1,0,0,0,0,0,0,0,"The Chef - On Waypoint 4 Reached - Set Emote State 26");

DELETE FROM `waypoints` WHERE `entry`=47405;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(47405, 1, 2259.79, 268.161, 33.6901, 'The Chef'),
(47405, 2, 2259.9, 267.349, 34.3857, 'The Chef'),
(47405, 3, 2260.2, 268.822, 33.6908, 'The Chef'),
(47405, 4, 2257.37, 269.111, 33.6908, 'The Chef');

-- Junior Apothecary Holland SAI
SET @ENTRY := 10665;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,60000,60000,60000,60000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Junior Apothecary Holland - Out of Combat - Say Line 0");

DELETE FROM `creature_text` WHERE `entry`=10665;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(10665, 0, 0, 'What could be taking so long?', 12, 0, 100, 0, 0, 0, 5955, 0, 'Junior Apothecary Holland'),
(10665, 0, 1, 'How long can it take to pick a handful of weeds?', 12, 0, 100, 0, 0, 0, 5956, 0, 'Junior Apothecary Holland'),
(10665, 0, 2, 'At this rate I could have gathered them myself!', 12, 0, 100, 0, 0, 0, 5957, 0, 'Junior Apothecary Holland'),
(10665, 0, 3, 'If you want something done right, do it yourself!', 12, 0, 100, 0, 0, 0, 5958, 0, 'Junior Apothecary Holland'),
(10665, 0, 4, 'As if I had all eternity.', 12, 0, 100, 0, 0, 0, 5959, 0, 'Junior Apothecary Holland'),
(10665, 0, 5, 'Ah, this must be him now... NO?  Bah!', 12, 0, 100, 0, 0, 0,  5960, 0, 'Junior Apothecary Holland'),
(10665, 0, 6, 'Maybe I should have just bought SOME off of Faruza?', 12, 0, 100, 0, 0, 0,  5961, 0, 'Junior Apothecary Holland'),
(10665, 0, 7, 'I had TO go AND requisition an Abomination... an Abomination!', 12, 0, 100, 0, 0, 0,  5962, 0, 'Junior Apothecary Holland');

-- Gina Lang SAI
SET @ENTRY := 5750;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,11,11939,2,0,0,0,0,1,0,0,0,0,0,0,0,"Gina Lang - On Reset - Cast 'Summon Imp'");

-- Apothecary Jerrod
DELETE FROM `gossip_menu` WHERE (`entry`=11144 AND `text_id`=15511);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(11144, 15511); -- 38977

DELETE FROM `gossip_menu_option` WHERE (`menu_id`=11144 AND `id`=0);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `box_coded`, `box_money`, `box_text`) VALUES
(11144, 0, 0, 'Who''s the little guy?', 0, 0, ''); -- 38977

DELETE FROM `creature_template_addon` WHERE `entry`=1548;
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(1548, 0, 0x0, 0x1, ''); -- 1548

-- Scarlet Friar SAI
SET @ENTRY := 1538;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Friar - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,2,0,100,0,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Friar - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,2,0,0,0,100,0,3000,4000,20000,25000,11,75967,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Friar - In Combat - Cast 'Whirlwind'");

-- Captain Vachon SAI
SET @ENTRY := 1664;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Vachon - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,1,0,0,0,100,0,4000,4000,6000,6000,11,79732,0,0,0,0,0,2,0,0,0,0,0,0,0,"Captain Vachon - In Combat - Cast 'Shield Bash'"),
(@ENTRY,0,2,0,0,0,100,0,3000,6000,8000,12000,11,12169,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Vachon - In Combat - Cast 'Shield Block'");

-- Scarlet Vanguard SAI
SET @ENTRY := 1540;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Vanguard - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,2,0,100,0,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Vanguard - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,2,0,4,0,100,0,0,0,0,0,75,7164,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Vanguard - On Aggro - Add Aura 'Defensive Stance'"),
(@ENTRY,0,3,0,0,0,100,0,3000,6000,3000,6000,11,11972,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Vanguard - In Combat - Cast 'Shield Bash'");

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=11194; -- Argent Defender <The Argent Dawn>
DELETE FROM `smart_scripts` WHERE `entryorguid` = 11194 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11194, 0, 0, 0, 0, 0, 100, 0, 1000, 1000, 10000, 10000, 11, 12024, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '11194 - IC - CAST'),
(11194, 0, 1, 0, 0, 0, 100, 0, 5000, 5000, 6000, 6000, 11, 6660, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '11194 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=10356; -- Bayne
DELETE FROM `smart_scripts` WHERE `entryorguid` = 10356 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10356, 0, 0, 0, 0, 0, 100, 0, 5000, 5000, 15000, 15000, 11, 13443, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '10356 - IC - CAST'),
(10356, 0, 1, 0, 0, 0, 100, 0, 3000, 3000, 20000, 20000, 11, 3604, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '10356 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI', `minlevel`=85, `maxlevel`=85 WHERE `entry`=51522; -- Bulwark Dreadguard (not spawned, wrong level and hp)
DELETE FROM `smart_scripts` WHERE `entryorguid` = 51522 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(51522, 0, 0, 0, 0, 0, 100, 0, 1000, 1000, 7000, 7000, 11, 95826, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '51522 - IC - CAST'),
(51522, 0, 1, 0, 0, 0, 100, 0, 5000, 5000, 5000, 5000, 11, 40505, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '51522 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1662; -- Captain Perrine
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1662 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1662, 0, 0, 0, 0, 0, 100, 0, 1000, 1000, 7000, 7000, 11, 12169, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '1662 - IC - CAST'),
(1662, 0, 1, 0, 0, 0, 100, 0, 15000, 15000, 15000, 15000, 11, 3019, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '1662 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1523; -- Cracked Skull Soldier
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1523 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1523, 0, 0, 0, 0, 0, 100, 0, 4000, 4000, 5000, 5000, 11, 84282, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '1523 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1522; -- Darkeye Bonecaster
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1522 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1522, 0, 0, 0, 0, 0, 100, 0, 1000, 1000, 4000, 4000, 11, 13322, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '1522 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1911; -- Deeb
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1911 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1911, 0, 0, 0, 0, 0, 100, 0, 1000, 1000, 4000, 4000, 11, 9532, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '1911 - IC - CAST'),
(1911, 0, 1, 0, 0, 0, 100, 0, 5000, 5000, 6000, 6000, 11, 2607, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '1911 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1936; -- Farmer Solliden
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1936 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1936, 0, 0, 0, 0, 0, 100, 0, 1000, 1000, 5000, 5000, 11, 11976, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '1936 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=10358; -- Fellicent's Shade
DELETE FROM `smart_scripts` WHERE `entryorguid` = 10358 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10358, 0, 0, 0, 0, 0, 100, 0, 1000, 1000, 5000, 5000, 11, 13901, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '10358 - IC - CAST'),
(10358, 0, 1, 0, 0, 0, 100, 0, 5000, 5000, 7000, 7000, 11, 11975, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '10358 - IC - CAST'),
(10358, 0, 2, 0, 0, 0, 100, 0, 1000, 1000, 10000, 10000, 11, 7068, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '10358 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=10666; -- Gordo
DELETE FROM `smart_scripts` WHERE `entryorguid` = 10666 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10666, 0, 0, 0, 0, 0, 100, 0, 1000, 1000, 9000, 9000, 11, 59395, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '10666 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1521; -- Gretchen Dedmar
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1521 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1521, 0, 0, 0, 1, 1, 100, 0, 5000, 5000, 50000, 50000, 5, 18, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '1521 - ooc - play emote'),
(1521, 0, 1, 0, 63, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '1521 - IC - talk');
DELETE FROM creature_text WHERE entry IN (1521);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(1521, 0, 0, 'So cold...', 12, 0, 100, 0, 0, 0, 'Gretchen Dedmar', 39007);

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1527; -- Hungering Dead
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1527 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1527, 0, 0, 0, 0, 0, 100, 0, 1000, 1000, 5000, 5000, 11, 3234, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '1527 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1531; -- Lost Soul
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1531 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1531, 0, 0, 0, 0, 0, 100, 0, 1000, 1000, 8000, 8000, 11, 7713, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '1531 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1753; -- Maggot Eye
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1753 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1753, 0, 0, 0, 0, 0, 100, 0, 1000, 1000, 100000, 100000, 11, 3237, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '1753 - IC - CAST'),
(1753, 0, 1, 0, 0, 0, 100, 0, 3000, 3000, 7000, 7000, 11, 3243, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '1753 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1910; -- Muad
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1910 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1910, 0, 0, 0, 0, 0, 100, 0, 1000, 1000, 6000, 6000, 11, 11824, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '1910 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1688; -- Night Web Matriarch
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1688 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1688, 0, 0, 0, 0, 0, 100, 0, 1000, 1000, 15000, 15000, 11, 11918, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '1688 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1505; -- Night Web Spider
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1505 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1505, 0, 0, 0, 0, 0, 100, 0, 1000, 1000, 15000, 15000, 11, 6751, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '1505 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=39049; -- Plagued Bruin
DELETE FROM `smart_scripts` WHERE `entryorguid` = 39049 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(39049, 0, 0, 0, 0, 0, 100, 0, 1000, 1000, 6000, 6000, 11, 16827, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '39049 - IC - CAST'),
(39049, 0, 1, 0, 0, 0, 100, 0, 5000, 5000, 11000, 11000, 11, 3242, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '39049 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1890; -- Rattlecage Skeleton
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1890 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1890, 0, 0, 0, 0, 0, 100, 0, 1000, 1000, 15000, 15000, 11, 81219, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '1890 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1520; -- Rattlecage Soldier
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1520 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1520, 0, 0, 0, 0, 0, 100, 0, 4000, 4000, 7000, 7000, 11, 84282, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '1520 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1526; -- Ravaged Corpse
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1526 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1526, 0, 0, 0, 0, 0, 100, 0, 4000, 4000, 7000, 7000, 11, 3234, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '1526 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1549; -- Ravenous Darkhound
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1549 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1549, 0, 0, 0, 0, 0, 100, 0, 1000, 1000, 13000, 13000, 11, 82797, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '1549 - IC - CAST'),
(1549, 0, 1, 0, 0, 0, 100, 0, 5000, 5000, 7000, 7000, 11, 17253, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '1549 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1941; -- Rot Hide Graverobber
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1941 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1941, 0, 0, 0, 0, 0, 100, 0, 4000, 4000, 120000, 120000, 11, 3234, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '1941 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1675; -- Rot Hide Mongrel
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1675 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1675, 0, 0, 0, 0, 0, 100, 0, 4000, 4000, 120000, 120000, 11, 3237, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '1675 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1525; -- Rotting Dead
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1525 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1525, 0, 0, 0, 0, 0, 100, 0, 4000, 4000, 8000, 8000, 11, 3234, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '1525 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=4282; -- Scarlet Magician
DELETE FROM `smart_scripts` WHERE `entryorguid` = 4282 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4282, 0, 0, 0, 0, 0, 100, 0, 4000, 4000, 4000, 4000, 11, 9053, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '4282 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1528; -- Shambling Horror
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1528 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1528, 0, 0, 0, 0, 0, 100, 0, 4000, 4000, 8000, 8000, 11, 3234, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '1528 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=10359; -- Sri'skulk
DELETE FROM `smart_scripts` WHERE `entryorguid` = 10359 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10359, 0, 0, 0, 0, 0, 100, 0, 4000, 4000, 15000, 15000, 11, 3583, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '10359 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1533; -- Tormented Spirit
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1533 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1533, 0, 0, 0, 0, 0, 100, 0, 4000, 4000, 13000, 13000, 11, 7713, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '1533 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1545; -- Vile Fin Muckdweller
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1545 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1545, 0, 0, 0, 0, 0, 100, 0, 4000, 4000, 8000, 8000, 11, 7159, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '1545 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1532; -- Wandering Spirit
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1532 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1532, 0, 0, 0, 0, 0, 100, 0, 4000, 4000, 13000, 13000, 11, 7713, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '1532 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1655; -- Nissa Agamand
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1655 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1655, 0, 0, 0, 0, 0, 100, 0, 4000, 4000, 17000, 17000, 11, 51897, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '1532 - IC - CAST'),
(1655, 0, 1, 0, 0, 0, 100, 0, 2000, 2000, 3000, 3000, 11, 28993, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '1532 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1657; -- Devlin Agamand
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1657 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1657, 0, 0, 0, 0, 0, 100, 0, 4000, 4000, 4000, 4000, 11, 34447, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '1657 - IC - CAST'),
(1657, 0, 1, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '1657 - on aggro - Talk');
DELETE FROM creature_text WHERE entry IN (1657);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(1657, 0, 0, 'Here to visit the family? Die, fool!', 12, 0, 100, 0, 0, 0, 'Devlin Agamand', 574),
(1657, 0, 1, 'The Agamand Mills is held by the Scourge, $c. Join us!', 12, 0, 100, 0, 0, 0, 'Devlin Agamand', 575);
UPDATE `creature` SET `spawndist`=5, `MovementType`=1 WHERE  `id` IN (1935, 1934, 1548);

-- scarlet guys
UPDATE `creature` SET `spawndist`=5, `MovementType`=1 WHERE  `id` IN (1935, 1934, 1548);
UPDATE `creature` SET `spawndist`=10, `MovementType`=1 WHERE  `guid` IN (325236, 325228, 325221, 325113, 325115, 325110, 325116, 325214, 325209, 325238, 325237, 325233, 325240, 325239, 325357);

DELETE FROM `creature_template_addon` WHERE `entry` IN (1535);
DELETE FROM `creature_addon` WHERE `guid` IN (325213, 325211, 325212, 325210, 325235, 325234);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(325234, 0, 0, 0, 1, 418, ''),
(325235, 0, 0, 0, 1, 418, ''),
-- sleep
(325210, 0, 0, 3, 1, 0, ''),
(325212, 0, 0, 3, 1, 0, ''),
-- kneel
(325211, 0, 0, 8, 1, 0, ''),
(325213, 0, 0, 8, 1, 0, '');

-- talking guys
UPDATE `creature_template_addon` SET `emote`=1 WHERE `entry` IN (48612, 48614, 48613, 48616, 48618, 48615);

-- Deathguard Swollow
UPDATE `creature_template_addon` SET `path_id`=391960 WHERE  `entry`=39196;
UPDATE `creature` SET `MovementType`=2 WHERE  `guid`=325669;
DELETE FROM `waypoint_data` WHERE `id`=391960;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(391960, 1, 2243.38, 1014.55, 36.9146, 0, 0, 0, 0, 100, 0),
(391960, 2, 2254, 1021.82, 36.4536, 0, 0, 0, 0, 100, 0),
(391960, 3, 2260.91, 1010.9, 36.4385, 0, 0, 0, 0, 100, 0),
(391960, 4, 2251.37, 1003.8, 36.5095, 0, 0, 0, 0, 100, 0);

-- Gordo
UPDATE `creature_template_addon` SET `path_id`=3256280 WHERE  `entry`=10666;
UPDATE `creature` SET `MovementType`=2 WHERE  `guid`=325628;
DELETE FROM `waypoint_data` WHERE `id`=3256280;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(3256280, 1, 2220.16, 1034.98, 35.4363, 0, 0, 0, 0, 100, 0),
(3256280, 2, 2215.4, 1034.4, 35.4941, 0, 0, 0, 0, 100, 0),
(3256280, 3, 2210.6, 1032.61, 35.5099, 0, 0, 0, 0, 100, 0),
(3256280, 4, 2212.62, 1038.43, 34.859, 0, 0, 0, 0, 100, 0),
(3256280, 5, 2211.79, 1034.79, 35.322, 0, 0, 0, 0, 100, 0),
(3256280, 6, 2212.88, 1038.84, 34.8025, 0, 0, 0, 0, 100, 0),
(3256280, 7, 2211.61, 1034.22, 35.3814, 0, 0, 0, 0, 100, 0),
(3256280, 8, 2217.5, 1035.07, 35.4439, 0, 0, 0, 0, 100, 0),
(3256280, 9, 2222.84, 1034.61, 35.5158, 0, 0, 0, 0, 100, 0),
(3256280, 10, 2228.76, 1032.47, 35.7824, 0, 0, 0, 0, 100, 0),
(3256280, 11, 2239.25, 1024.1, 36.4546, 0, 0, 0, 0, 100, 0),
(3256280, 12, 2243.63, 1018.43, 36.6652, 0, 0, 0, 0, 100, 0),
(3256280, 13, 2243.18, 1004.55, 36.5792, 0, 0, 0, 0, 100, 0),
(3256280, 14, 2232.18, 994.276, 36.727, 0, 0, 0, 0, 100, 0),
(3256280, 15, 2241.75, 1006.5, 36.6768, 0, 0, 0, 0, 100, 0),
(3256280, 16, 2243.38, 1017.61, 36.7298, 0, 0, 0, 0, 100, 0),
(3256280, 17, 2240.62, 1023.92, 36.4588, 0, 0, 0, 0, 100, 0),
(3256280, 18, 2226.9, 1033.25, 35.6483, 0, 0, 0, 0, 100, 0);

-- apothecary Johaan
UPDATE `creature_template_addon` SET `emote`=69 WHERE  `entry`=1518;

-- old dogs, 
UPDATE `creature` SET `spawndist`=5, `MovementType`=1 WHERE  `id` IN (1935, 1548);

-- Sahvan Bloodshadow
UPDATE `creature_template_addon` SET `path_id`=3263920 WHERE  `entry`=2314;
UPDATE `creature` SET `MovementType`=2 WHERE  `guid`=326392;
DELETE FROM `waypoint_data` WHERE `id`=3263920;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(3263920, 1, 2370.84, 398.24, 37.7116, 0, 0, 0, 0, 100, 0),
(3263920, 2, 2370.96, 397.113, 37.7004, 0, 10000, 0, 0, 100, 0),
(3263920, 3, 2357.77, 397.081, 36.1473, 0, 0, 0, 0, 100, 0),
(3263920, 4, 2346.2, 396.934, 34.3625, 0, 0, 0, 0, 100, 0),
(3263920, 5, 2330.81, 397.436, 33.6671, 0, 0, 0, 0, 100, 0),
(3263920, 6, 2314.83, 397.266, 33.8284, 0, 0, 0, 0, 100, 0),
(3263920, 7, 2286.51, 395.088, 34.04, 0, 0, 0, 0, 100, 0),
(3263920, 8, 2283.19, 389.599, 34.1145, 0, 0, 0, 0, 100, 0),
(3263920, 9, 2284.4, 366.985, 34.0099, 0, 0, 0, 0, 100, 0),
(3263920, 10, 2285.11, 355.211, 33.4897, 0, 0, 0, 0, 100, 0),
(3263920, 11, 2276.64, 329.606, 33.4725, 0, 0, 0, 0, 100, 0),
(3263920, 12, 2267.65, 309.841, 33.39, 0, 0, 0, 0, 100, 0),
(3263920, 13, 2261.81, 294.095, 33.5874, 0, 0, 0, 0, 100, 0),
(3263920, 14, 2255.37, 279.841, 33.6177, 0, 0, 0, 0, 100, 0),
(3263920, 15, 2251.42, 271.001, 33.6544, 0, 0, 0, 0, 100, 0),
(3263920, 16, 2246.26, 255.368, 33.5888, 0, 0, 0, 0, 100, 0),
(3263920, 17, 2246.4, 256.044, 33.5888, 0, 35000, 0, 0, 100, 0),
(3263920, 18, 2249.04, 265.982, 33.5274, 0, 0, 0, 0, 100, 0),
(3263920, 19, 2251.42, 269.81, 33.6628, 0, 0, 0, 0, 100, 0),
(3263920, 20, 2254.47, 269.633, 33.6891, 0, 6000, 0, 0, 100, 0),
(3263920, 21, 2258.93, 281.805, 33.6868, 0, 0, 0, 0, 100, 0),
(3263920, 22, 2263.5, 294.315, 33.6907, 0, 0, 0, 0, 100, 0),
(3263920, 23, 2273.85, 320.603, 33.4459, 0, 0, 0, 0, 100, 0),
(3263920, 24, 2270.71, 329.529, 33.5747, 0, 0, 0, 0, 100, 0),
(3263920, 25, 2267.91, 329.632, 33.5747, 0, 6000, 0, 0, 100, 0),
(3263920, 26, 2273.2, 336.752, 33.516, 0, 0, 0, 0, 100, 0),
(3263920, 27, 2282.98, 348.796, 33.4146, 0, 0, 0, 0, 100, 0),
(3263920, 28, 2284, 367.676, 34.0457, 0, 0, 0, 0, 100, 0),
(3263920, 29, 2283.6, 389.49, 34.1162, 0, 0, 0, 0, 100, 0),
(3263920, 30, 2286.63, 395.716, 34.0437, 0, 0, 0, 0, 100, 0),
(3263920, 31, 2314.79, 397.905, 33.8502, 0, 0, 0, 0, 100, 0),
(3263920, 32, 2342.56, 397.335, 33.8829, 0, 0, 0, 0, 100, 0),
(3263920, 33, 2362.75, 397.583, 37.0283, 0, 0, 0, 0, 100, 0);

UPDATE `creature_template_addon` SET `path_id`=3267980 WHERE  `entry`=1738;
UPDATE `creature` SET `MovementType`=2 WHERE  `guid`=326798;
DELETE FROM `waypoint_data` WHERE `id`=3267980;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(3267980, 1, 2208.81, 255.006, 33.5904, 0, 20000, 0, 0, 100, 0),
(3267980, 2, 2204.52, 246.84, 33.8546, 0, 0, 0, 0, 100, 0),
(3267980, 3, 2187.11, 235.962, 35.7584, 0, 0, 0, 0, 100, 0),
(3267980, 4, 2163.87, 217.6, 41.1689, 0, 0, 0, 0, 100, 0),
(3267980, 5, 2161.54, 184.956, 42.2037, 0, 0, 0, 0, 100, 0),
(3267980, 6, 2159.69, 180.296, 41.8648, 0, 0, 0, 0, 100, 0),
(3267980, 7, 2142.63, 168.91, 38.9447, 0, 0, 0, 0, 100, 0),
(3267980, 8, 2115.97, 157.508, 36.3402, 0, 0, 0, 0, 100, 0),
(3267980, 9, 2109.29, 155.459, 35.9326, 0, 0, 0, 0, 100, 0),
(3267980, 10, 2086.22, 153.437, 34.7756, 0, 0, 0, 0, 100, 0),
(3267980, 11, 2068.77, 153.353, 34.0094, 0, 0, 0, 0, 100, 0),
(3267980, 12, 2049.71, 160.292, 33.7197, 0, 15000, 0, 0, 100, 0),
(3267980, 13, 2064.74, 154.845, 33.8402, 0, 0, 0, 0, 100, 0),
(3267980, 14, 2081.87, 153.482, 34.5686, 0, 0, 0, 0, 100, 0),
(3267980, 15, 2101.45, 154.372, 35.5246, 0, 0, 0, 0, 100, 0),
(3267980, 16, 2126.23, 162.268, 37.3845, 0, 0, 0, 0, 100, 0),
(3267980, 17, 2152.1, 174.657, 40.5715, 0, 0, 0, 0, 100, 0),
(3267980, 18, 2159.02, 180.437, 41.7866, 0, 0, 0, 0, 100, 0),
(3267980, 19, 2161.63, 205.745, 42.6787, 0, 0, 0, 0, 100, 0),
(3267980, 20, 2162.9, 213.743, 41.7645, 0, 0, 0, 0, 100, 0),
(3267980, 21, 2166.28, 219.463, 40.6148, 0, 0, 0, 0, 100, 0),
(3267980, 22, 2185.87, 235.122, 35.971, 0, 0, 0, 0, 100, 0),
(3267980, 23, 2213.15, 251.347, 33.5752, 0, 0, 0, 0, 100, 0),
(3267980, 24, 2210.77, 256.311, 33.5751, 0, 0, 0, 0, 100, 0);

UPDATE `creature_template_addon` SET `path_id`=3261580 WHERE  `entry`=3547;
UPDATE `creature` SET `MovementType`=2 WHERE  `guid`=326158;
DELETE FROM `waypoint_data` WHERE `id`=3261580;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(3261580, 1, 2282.96, 390.353, 34.1148, 0, 0, 0, 0, 100, 0),
(3261580, 2, 2283.21, 366.093, 33.9823, 0, 0, 0, 0, 100, 0),
(3261580, 3, 2277.23, 340.521, 33.5585, 0, 0, 0, 0, 100, 0),
(3261580, 4, 2271.72, 320.467, 33.5215, 0, 0, 0, 0, 100, 0),
(3261580, 5, 2259.02, 296.954, 33.4113, 0, 0, 0, 0, 100, 0),
(3261580, 6, 2246.64, 283.456, 33.3787, 0, 0, 0, 0, 100, 0),
(3261580, 7, 2234.61, 278.976, 33.5738, 0, 0, 0, 0, 100, 0),
(3261580, 8, 2221.18, 265.665, 33.5843, 0, 0, 0, 0, 100, 0),
(3261580, 9, 2202.13, 246.259, 34.1629, 0, 0, 0, 0, 100, 0),
(3261580, 10, 2185.68, 237.15, 35.9575, 0, 0, 0, 0, 100, 0),
(3261580, 11, 2183.74, 233.823, 36.373, 0, 0, 0, 0, 100, 0),
(3261580, 12, 2188.96, 235.069, 35.5176, 0, 0, 0, 0, 100, 0),
(3261580, 13, 2209.74, 247.37, 33.5862, 0, 0, 0, 0, 100, 0),
(3261580, 14, 2230.87, 259.763, 33.5739, 0, 0, 0, 0, 100, 0),
(3261580, 15, 2245.32, 261.246, 33.4651, 0, 0, 0, 0, 100, 0),
(3261580, 16, 2249.1, 279.006, 33.3799, 0, 0, 0, 0, 100, 0),
(3261580, 17, 2261.92, 297.294, 33.5376, 0, 0, 0, 0, 100, 0),
(3261580, 18, 2272.11, 319.848, 33.476, 0, 0, 0, 0, 100, 0),
(3261580, 19, 2279.31, 344.857, 33.5522, 0, 0, 0, 0, 100, 0),
(3261580, 20, 2283.87, 366.326, 33.9772, 0, 0, 0, 0, 100, 0),
(3261580, 21, 2284.53, 390.846, 34.1125, 0, 0, 0, 0, 100, 0),
(3261580, 22, 2287.03, 395.704, 34.0355, 0, 0, 0, 0, 100, 0),
(3261580, 23, 2315.81, 396.56, 33.7449, 0, 0, 0, 0, 100, 0),
(3261580, 24, 2331.1, 395.938, 33.6668, 0, 0, 0, 0, 100, 0),
(3261580, 25, 2337.62, 392.279, 33.6673, 0, 0, 0, 0, 100, 0),
(3261580, 26, 2360.04, 359.752, 37.9193, 0, 0, 0, 0, 100, 0),
(3261580, 27, 2361.54, 352.919, 37.9542, 0, 0, 0, 0, 100, 0),
(3261580, 28, 2362.89, 351.553, 37.9576, 0, 0, 0, 0, 100, 0),
(3261580, 29, 2357.26, 365.273, 37.3017, 0, 0, 0, 0, 100, 0),
(3261580, 30, 2353.16, 375.067, 35.6998, 0, 0, 0, 0, 100, 0),
(3261580, 31, 2336.31, 398.609, 33.667, 0, 0, 0, 0, 100, 0),
(3261580, 32, 2317.42, 398.008, 33.667, 0, 0, 0, 0, 100, 0),
(3261580, 33, 2287.33, 396.612, 34.0165, 0, 0, 0, 0, 100, 0),
(3261580, 34, 2282.92, 397.991, 34.0191, 0, 0, 0, 0, 100, 0),
(3261580, 35, 2278.45, 412.452, 33.8723, 0, 0, 0, 0, 100, 0),
(3261580, 36, 2277.29, 427.822, 33.94, 0, 0, 0, 0, 100, 0),
(3261580, 37, 2274.43, 430.901, 33.9814, 0, 0, 0, 0, 100, 0),
(3261580, 38, 2274.19, 425.889, 33.9729, 0, 0, 0, 0, 100, 0),
(3261580, 39, 2278.26, 412.01, 33.8726, 0, 0, 0, 0, 100, 0);

UPDATE `creature_template_addon` SET `path_id`=3263940 WHERE  `entry`=1742;
UPDATE `creature` SET `MovementType`=2 WHERE  `guid`=326394;
DELETE FROM `waypoint_data` WHERE `id`=3263940;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(3263940, 1, 2427.29, 343.707, 34.6791, 0, 120000, 0, 0, 100, 0),
(3263940, 2, 2424.49, 357.788, 33.8811, 0, 0, 0, 0, 100, 0),
(3263940, 3, 2414.58, 366.685, 33.9739, 0, 0, 0, 0, 100, 0),
(3263940, 4, 2403.27, 382.786, 33.8938, 0, 0, 0, 0, 100, 0),
(3263940, 5, 2393.81, 402.025, 33.8906, 0, 0, 0, 0, 100, 0),
(3263940, 6, 2388.06, 416.934, 33.8906, 0, 0, 0, 0, 100, 0),
(3263940, 7, 2384.33, 422.386, 33.9003, 0, 0, 0, 0, 100, 0),
(3263940, 8, 2377.16, 427.586, 34.0532, 0, 0, 0, 0, 100, 0),
(3263940, 9, 2369.87, 430.024, 33.6414, 0, 0, 0, 0, 100, 0),
(3263940, 10, 2366.1, 431.249, 33.5516, 0, 0, 0, 0, 100, 0),
(3263940, 11, 2362.42, 428.377, 33.5516, 0, 0, 0, 0, 100, 0),
(3263940, 12, 2357.18, 428.15, 33.436, 0, 0, 0, 0, 100, 0),
(3263940, 13, 2352.71, 429.819, 33.3357, 0, 0, 0, 0, 100, 0),
(3263940, 14, 2341.59, 418.001, 33.6679, 0, 0, 0, 0, 100, 0),
(3263940, 15, 2340.03, 413.245, 33.6676, 0, 0, 0, 0, 100, 0),
(3263940, 16, 2338.77, 401.993, 33.6676, 0, 0, 0, 0, 100, 0),
(3263940, 17, 2334.18, 397.699, 33.6676, 0, 0, 0, 0, 100, 0),
(3263940, 18, 2317.49, 397.706, 33.6676, 0, 0, 0, 0, 100, 0),
(3263940, 19, 2293.24, 396.714, 34.0162, 0, 0, 0, 0, 100, 0),
(3263940, 20, 2290.19, 392.574, 34.0859, 0, 0, 0, 0, 100, 0),
(3263940, 21, 2289.16, 393.135, 34.0749, 0, 120000, 0, 0, 100, 0),
(3263940, 40, 2424.49, 357.788, 33.8811, 0, 0, 0, 0, 100, 0),
(3263940, 39, 2414.58, 366.685, 33.9739, 0, 0, 0, 0, 100, 0),
(3263940, 38, 2403.27, 382.786, 33.8938, 0, 0, 0, 0, 100, 0),
(3263940, 37, 2393.81, 402.025, 33.8906, 0, 0, 0, 0, 100, 0),
(3263940, 36, 2388.06, 416.934, 33.8906, 0, 0, 0, 0, 100, 0),
(3263940, 35, 2384.33, 422.386, 33.9003, 0, 0, 0, 0, 100, 0),
(3263940, 34, 2377.16, 427.586, 34.0532, 0, 0, 0, 0, 100, 0),
(3263940, 33, 2369.87, 430.024, 33.6414, 0, 0, 0, 0, 100, 0),
(3263940, 32, 2366.1, 431.249, 33.5516, 0, 0, 0, 0, 100, 0),
(3263940, 31, 2362.42, 428.377, 33.5516, 0, 0, 0, 0, 100, 0),
(3263940, 30, 2357.18, 428.15, 33.436, 0, 0, 0, 0, 100, 0),
(3263940, 29, 2352.71, 429.819, 33.3357, 0, 0, 0, 0, 100, 0),
(3263940, 28, 2341.59, 418.001, 33.6679, 0, 0, 0, 0, 100, 0),
(3263940, 27, 2340.03, 413.245, 33.6676, 0, 0, 0, 0, 100, 0),
(3263940, 26, 2338.77, 401.993, 33.6676, 0, 0, 0, 0, 100, 0),
(3263940, 25, 2334.18, 397.699, 33.6676, 0, 0, 0, 0, 100, 0),
(3263940, 24, 2317.49, 397.706, 33.6676, 0, 0, 0, 0, 100, 0),
(3263940, 23, 2293.24, 396.714, 34.0162, 0, 0, 0, 0, 100, 0),
(3263940, 22, 2290.19, 392.574, 34.0859, 0, 0, 0, 0, 100, 0);

--  rndmmovement for bats and zombies
UPDATE `creature` SET `spawndist`=7, `MovementType`=1 WHERE  `id` IN (2311, 1526, 1525, 1553, 1547, 10357);
UPDATE `creature_template_addon` SET `emote`=233 WHERE  `entry`=2135;
UPDATE `creature_template_addon` SET `emote`=69 WHERE  `entry`=1499; -- Magister Sevren
UPDATE `creature` SET `spawndist`=10, `MovementType`=1 WHERE `id` IN (53526, 620, 1527, 39049, 1520, 1549, 1674, 1941, 1530, 1536, 4281, 4283, 4282, 1528, 51964, 51965, 51961, 1554, 1555, 1545, 1543, 1544, 1541, 1534, 1532, 1531, 1522, 1523, 1656, 1675, 1529);

UPDATE `creature_template_addon` SET `path_id`=3257150 WHERE  `entry`=1533;
UPDATE `creature` SET `MovementType`=2 WHERE  `guid`=325715;
DELETE FROM `waypoint_data` WHERE `id`=3257150;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(3257150, 1, 2745.419922, 978.708984, 109.392998, 0, 0, 0, 0, 100, 0),
(3257150, 2, 2765.810059, 993.661743, 109.732834, 0, 0, 0, 0, 100, 0),
(3257150, 3, 2774.722900, 1021.454529, 108.534164, 0, 0, 0, 0, 100, 0),
(3257150, 4, 2777.558838, 1045.788696, 108.904297, 0, 0, 0, 0, 100, 0),
(3257150, 5, 2794.649170, 1049.257568, 110.820305, 0, 0, 0, 0, 100, 0),
(3257150, 6, 2814.373047, 1046.770996, 110.820305, 0, 0, 0, 0, 100, 0),
(3257150, 7, 2839.627197, 1051.084717, 111.511284, 0, 0, 0, 0, 100, 0),
(3257150, 8, 2886.339600, 1065.823364, 105.970253, 0, 0, 0, 0, 100, 0),
(3257150, 9, 2891.578613, 1055.620850, 105.705093, 0, 0, 0, 0, 100, 0),
(3257150, 10, 2895.504150, 1029.036011, 107.049751, 0, 0, 0, 0, 100, 0),
(3257150, 11, 2898.632813, 979.230530, 113.568359, 0, 0, 0, 0, 100, 0),
(3257150, 12, 2899.541260, 957.061768, 115.106735, 0, 0, 0, 0, 100, 0),
(3257150, 13, 2908.080078, 932.908630, 114.917854, 0, 0, 0, 0, 100, 0),
(3257150, 14, 2905.685791, 923.912354, 114.982185, 0, 0, 0, 0, 100, 0),
(3257150, 15, 2893.146240, 913.490784, 114.658241, 0, 0, 0, 0, 100, 0),
(3257150, 16, 2855.242432, 880.518799, 112.352898, 0, 0, 0, 0, 100, 0),
(3257150, 17, 2826.591553, 864.780823, 111.842575, 0, 0, 0, 0, 100, 0),
(3257150, 18, 2802.163330, 864.498779, 111.841164, 0, 0, 0, 0, 100, 0),
(3257150, 19, 2773.511475, 880.237610, 111.774582, 0, 0, 0, 0, 100, 0),
(3257150, 20, 2752.895996, 899.921692, 111.763412, 0, 0, 0, 0, 100, 0),
(3257150, 21, 2736.951904, 942.523987, 109.499664, 0, 0, 0, 0, 100, 0),
(3257150, 22, 2734.885498, 956.346741, 109.242607, 0, 0, 0, 0, 100, 0),
(3257150, 23, 2737.154541, 972.515198, 109.242020, 0, 0, 0, 0, 100, 0);

UPDATE `creature_template_addon` SET `path_id`=3257480 WHERE  `entry`=5725;
UPDATE `creature` SET `MovementType`=2 WHERE  `guid`=325748;
DELETE FROM `waypoint_data` WHERE `id`=3257480;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(3257480, 1, 2129.376709, 953.351624, 29.058704, 0, 0, 0, 0, 100, 0),
(3257480, 2, 2104.569580, 878.170593, 32.416527, 0, 0, 0, 0, 100, 0),
(3257480, 3, 2093.044434, 813.923157, 33.563000, 0, 0, 0, 0, 100, 0),
(3257480, 4, 2093.758057, 767.299744, 33.564106, 0, 0, 0, 0, 100, 0),
(3257480, 5, 2101.969971, 750.510376, 33.560898, 0, 0, 0, 0, 100, 0),
(3257480, 6, 2167.280518, 694.103760, 33.355125, 0, 0, 0, 0, 100, 0),
(3257480, 7, 2180.792480, 682.982788, 33.393795, 0, 0, 0, 0, 100, 0),
(3257480, 8, 2239.743652, 601.869629, 33.333622, 0, 0, 0, 0, 100, 0),
(3257480, 9, 2261.292969, 541.476624, 33.534515, 0, 0, 0, 0, 100, 0),
(3257480, 10, 2255.469482, 505.762604, 34.113213, 0, 0, 0, 0, 100, 0),
(3257480, 11, 2275.757813, 426.780182, 33.952923, 0, 0, 0, 0, 100, 0),
(3257480, 12, 2283.910156, 385.661133, 34.126793, 0, 0, 0, 0, 100, 0),
(3257480, 13, 2285.265381, 348.391113, 33.624481, 0, 0, 0, 0, 100, 0),
(3257480, 14, 2273.001953, 315.611206, 33.431656, 0, 0, 0, 0, 100, 0),
(3257480, 15, 2255.712402, 290.769836, 33.507896, 0, 0, 0, 0, 100, 0),
(3257480, 16, 2232.237549, 275.507813, 33.573711, 0, 0, 0, 0, 100, 0),
(3257480, 17, 2207.864746, 248.755692, 33.631718, 0, 0, 0, 0, 100, 0),
(3257480, 18, 2173.530518, 226.758133, 38.763466, 0, 0, 0, 0, 100, 0),
(3257480, 19, 2164.428711, 214.597580, 41.493935, 0, 0, 0, 0, 100, 0),
(3257480, 20, 2160.420410, 183.353714, 41.991291, 0, 0, 0, 0, 100, 0),
(3257480, 21, 2143.672607, 170.800919, 39.302605, 0, 0, 0, 0, 100, 0),
(3257480, 22, 2120.702393, 159.453781, 36.839264, 0, 0, 0, 0, 100, 0),
(3257480, 23, 2090.853027, 153.441589, 34.950005, 0, 0, 0, 0, 100, 0),
(3257480, 24, 2067.516357, 154.855606, 33.928402, 0, 0, 0, 0, 100, 0),
(3257480, 25, 2045.528687, 162.187668, 33.877983, 0, 0, 0, 0, 100, 0),
(3257480, 26, 2067.516357, 154.855606, 33.928402, 0, 0, 0, 0, 100, 0),
(3257480, 27, 2090.853027, 153.441589, 34.950005, 0, 0, 0, 0, 100, 0),
(3257480, 28, 2120.702393, 159.453781, 36.839264, 0, 0, 0, 0, 100, 0),
(3257480, 29, 2143.672607, 170.800919, 39.302605, 0, 0, 0, 0, 100, 0),
(3257480, 30, 2160.420410, 183.353714, 41.991291, 0, 0, 0, 0, 100, 0),
(3257480, 31, 2164.428711, 214.597580, 41.493935, 0, 0, 0, 0, 100, 0),
(3257480, 32, 2173.530518, 226.758133, 38.763466, 0, 0, 0, 0, 100, 0),
(3257480, 33, 2207.864746, 248.755692, 33.631718, 0, 0, 0, 0, 100, 0),
(3257480, 34, 2232.237549, 275.507813, 33.573711, 0, 0, 0, 0, 100, 0),
(3257480, 35, 2255.712402, 290.769836, 33.507896, 0, 0, 0, 0, 100, 0),
(3257480, 36, 2273.001953, 315.611206, 33.431656, 0, 0, 0, 0, 100, 0),
(3257480, 37, 2285.265381, 348.391113, 33.624481, 0, 0, 0, 0, 100, 0),
(3257480, 38, 2283.910156, 385.661133, 34.126793, 0, 0, 0, 0, 100, 0),
(3257480, 39, 2275.757813, 426.780182, 33.952923, 0, 0, 0, 0, 100, 0),
(3257480, 40, 2255.469482, 505.762604, 34.113213, 0, 0, 0, 0, 100, 0),
(3257480, 41, 2261.292969, 541.476624, 33.534515, 0, 0, 0, 0, 100, 0),
(3257480, 42, 2239.743652, 601.869629, 33.333622, 0, 0, 0, 0, 100, 0),
(3257480, 43, 2180.792480, 682.982788, 33.393795, 0, 0, 0, 0, 100, 0),
(3257480, 44, 2167.280518, 694.103760, 33.355125, 0, 0, 0, 0, 100, 0),
(3257480, 45, 2101.969971, 750.510376, 33.560898, 0, 0, 0, 0, 100, 0),
(3257480, 46, 2093.758057, 767.299744, 33.564106, 0, 0, 0, 0, 100, 0),
(3257480, 47, 2093.044434, 813.923157, 33.563000, 0, 0, 0, 0, 100, 0),
(3257480, 48, 2104.569580, 878.170593, 32.416527, 0, 0, 0, 0, 100, 0),
(3257480, 49, 2129.376709, 953.351624, 29.058704, 0, 0, 0, 0, 100, 0),
(3257480, 50, 2187.656250, 1044.816895, 29.563383, 0, 0, 0, 0, 100, 0);

-- Pathing for  Entry: 11194 'TDB FORMAT' 
SET @NPC := 327599;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1752.673,`position_y`=-714.7821,`position_z`=60.37662 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1752.673,-714.7821,60.37662,0,0,0,0,100,0),
(@PATH,2,1736.573,-714.5442,60.15818,0,0,0,0,100,0),
(@PATH,3,1714.988,-712.9315,55.49191,0,0,0,0,100,0),
(@PATH,4,1724.267,-713.0399,59.70621,0,0,0,0,100,0),
(@PATH,5,1725.058,-713.2177,59.80788,0,0,0,0,100,0),
(@PATH,6,1736.737,-714.7726,60.35667,0,0,0,0,100,0),
(@PATH,7,1752.949,-714.8248,60.39524,0,0,0,0,100,0),
(@PATH,8,1773.094,-713.1844,60.37144,0,0,0,0,100,0),
(@PATH,9,1788.519,-725.1661,59.74324,0,0,0,0,100,0),
(@PATH,10,1786.503,-723.2821,60.24324,0,0,0,0,100,0),
(@PATH,11,1784.11,-721.4037,60.33015,0,0,0,0,100,0),
(@PATH,12,1772.887,-713.1495,60.40531,0,0,0,0,100,0),
(@PATH,13,1752.611,-714.7417,60.37502,0,0,0,0,100,0),
(@PATH,14,1736.492,-714.5533,60.16143,0,0,0,0,100,0);
-- 0x1C091000000AEE80000032000056BB7C .go 1752.673 -714.7821 60.37662

-- Pathing for  Entry: 1532 'TDB FORMAT' 
SET @NPC := 327430;
SET @PATH := 3274301;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1983.394,`position_y`=-440.334,`position_z`=34.99339 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH, 1, 1983.83, -440.439, 34.5588, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 1984.13, -450.935, 34.5257, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 1984.43, -464.378, 34.5257, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 1975.09, -468.146, 34.5254, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 1962.36, -467.938, 34.5404, 0, 0, 0, 0, 100, 0),
(@PATH, 6, 1973.33, -468.258, 34.5264, 0, 0, 0, 0, 100, 0),
(@PATH, 7, 1973.45, -460.909, 34.8547, 0, 0, 0, 0, 100, 0),
(@PATH, 8, 1973.53, -451.908, 35.399, 0, 0, 0, 0, 100, 0),
(@PATH, 9, 1973.74, -443.041, 35.3663, 0, 0, 0, 0, 100, 0),
(@PATH, 10, 1968.77, -441.308, 35.4524, 0, 0, 0, 0, 100, 0),
(@PATH, 11, 1954.79, -440.639, 35.4524, 0, 0, 0, 0, 100, 0),
(@PATH, 12, 1950.82, -452.504, 35.4524, 0, 0, 0, 0, 100, 0),
(@PATH, 13, 1951.18, -442.234, 35.4524, 0, 0, 0, 0, 100, 0),
(@PATH, 14, 1951.18, -442.234, 35.4524, 0, 0, 0, 0, 100, 0),
(@PATH, 15, 1959.46, -440.023, 35.4524, 0, 0, 0, 0, 100, 0),
(@PATH, 16, 1972.76, -440.347, 35.4217, 0, 0, 0, 0, 100, 0),
(@PATH, 17, 1973.34, -449.776, 35.3569, 0, 0, 0, 0, 100, 0),
(@PATH, 18, 1973.39, -467.986, 34.5252, 0, 0, 0, 0, 100, 0),
(@PATH, 19, 1962.42, -467.647, 34.542, 0, 0, 0, 0, 100, 0),
(@PATH, 20, 1970.81, -467.957, 34.5254, 0, 0, 0, 0, 100, 0),
(@PATH, 21, 1984.59, -468.076, 34.5258, 0, 0, 0, 0, 100, 0),
(@PATH, 22, 1984.27, -458.512, 34.5258, 0, 0, 0, 0, 100, 0),
(@PATH, 23, 1983.38, -434.471, 35.0653, 0, 0, 0, 0, 100, 0),
(@PATH, 24, 1992.01, -434.073, 35.079, 0, 0, 0, 0, 100, 0),
(@PATH, 25, 2012.88, -433.101, 35.2828, 0, 0, 0, 0, 100, 0),
(@PATH, 26, 2020.33, -432.45, 35.3943, 0, 0, 0, 0, 100, 0),
(@PATH, 27, 2018.74, -417.005, 35.4527, 0, 0, 0, 0, 100, 0),
(@PATH, 28, 2017.34, -403.076, 35.4527, 0, 0, 0, 0, 100, 0),
(@PATH, 29, 2015.86, -387.374, 35.4527, 0, 0, 0, 0, 100, 0),
(@PATH, 30, 2015.94, -394.957, 35.4524, 0, 0, 0, 0, 100, 0),
(@PATH, 31, 2015.71, -415.956, 35.4524, 0, 0, 0, 0, 100, 0),
(@PATH, 32, 2015.53, -433.021, 35.3335, 0, 0, 0, 0, 100, 0),
(@PATH, 33, 2006.09, -433.57, 35.1885, 0, 0, 0, 0, 100, 0),
(@PATH, 34, 1985.2, -434.455, 35.0481, 0, 0, 0, 0, 100, 0);
-- 0x1C09100000017F0000003200005A1B7B .go 1983.394 -440.334 34.99339

-- Pathing for  Entry: 1532 'TDB FORMAT' 
SET @NPC := 325927;
SET @PATH := 325927 * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH, 1, 1798.26, 645.24, 39.4603, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 1801.42, 626.89, 38.652, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 1798.85, 617.852, 39.0081, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 1794.84, 609.532, 39.5333, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 1808.04, 604.461, 40.8277, 0, 0, 0, 0, 100, 0),
(@PATH, 6, 1824.14, 601.482, 42.2416, 0, 0, 0, 0, 100, 0),
(@PATH, 7, 1816.72, 618.558, 39.0602, 0, 0, 0, 0, 100, 0),
(@PATH, 8, 1807.09, 637.378, 37.9439, 0, 0, 0, 0, 100, 0),
(@PATH, 9, 1800.27, 654.705, 39.4252, 0, 0, 0, 0, 100, 0),
(@PATH, 10, 1792.63, 669.352, 41.8409, 0, 0, 0, 0, 100, 0),
(@PATH, 11, 1784.72, 683.692, 43.249, 0, 0, 0, 0, 100, 0),
(@PATH, 12, 1790.96, 668.699, 42.2061, 0, 0, 0, 0, 100, 0),
(@PATH, 13, 1796.48, 653.429, 40.0754, 0, 0, 0, 0, 100, 0);

-- Gretchen Dedmar SAI
SET @ENTRY := 1521;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,24988,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gretchen Dedmar - On Quest 'The Chill of Death' Taken - Say Line 0"),
(@ENTRY,0,1,0,20,0,100,0,24988,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gretchen Dedmar - On Quest 'The Chill of Death' Finished - Say Line 1");

DELETE FROM `creature_text` WHERE `entry`=1521;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(1521, 0, 0, 'Save me from the cold!', 12, 0, 100, 0, 0, 0, 39007, 0, 'Gretchen Dedmar'),
(1521, 1, 0, 'So cold...', 12, 0, 100, 0, 0, 0, 39009, 0, 'Gretchen Dedmar');

-- Pathing for  Entry: 1502 'TDB FORMAT' 
SET @NPC := 325265;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1932.444,`position_y`=1590.943,`position_z`=83.48648 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1932.444,1590.943,83.48648,0,0,0,0,100,0),
(@PATH,2,1942.309,1594.998,83.16008,0,0,0,0,100,0),
(@PATH,3,1951.316,1592.373,82.46585,0,0,0,0,100,0),
(@PATH,4,1974.542,1581.481,80.87744,0,0,0,0,100,0),
(@PATH,5,1988.139,1571.806,79.64528,0,0,0,0,100,0),
(@PATH,6,1998.26,1554.868,78.61601,0,0,0,0,100,0),
(@PATH,7,1999.297,1542.252,77.75618,0,0,0,0,100,0),
(@PATH,8,1991.584,1533.699,81.62056,0,0,0,0,100,0),
(@PATH,9,1992.814,1522.747,79.55931,0,0,0,0,100,0),
(@PATH,10,1998.614,1515.133,76.91168,0,0,0,0,100,0),
(@PATH,11,2003.37,1499.574,73.11504,0,0,0,0,100,0),
(@PATH,12,1986.435,1493.605,83.25249,0,0,0,0,100,0),
(@PATH,13,1969.808,1482.992,83.57193,0,0,0,0,100,0),
(@PATH,14,1965.593,1480.195,82.77003,0,0,0,0,100,0),
(@PATH,15,1965.535,1480.957,82.68534,0,0,0,0,100,0),
(@PATH,16,1964.197,1480.759,82.74674,0,0,0,0,100,0),
(@PATH,17,1964.256,1479.309,82.39164,0,0,0,0,100,0),
(@PATH,18,1965.723,1480.622,82.60502,0,0,0,0,100,0),
(@PATH,19,1964.204,1479.569,82.46037,0,0,0,0,100,0),
(@PATH,20,1964.442,1479.825,82.49308,0,0,0,0,100,0),
(@PATH,21,1966.99,1478.805,81.97617,0,0,0,0,100,0),
(@PATH,22,1962.672,1480.034,82.67216,0,0,0,0,100,0),
(@PATH,23,1965.086,1480.569,82.59452,0,0,0,0,100,0),
(@PATH,24,1966.052,1480.834,82.6558,0,0,0,0,100,0),
(@PATH,25,1965.037,1480.308,82.53764,0,0,0,0,100,0),
(@PATH,26,1963.071,1478.826,82.15226,0,0,0,0,100,0),
(@PATH,27,1964.471,1478.97,82.16947,0,0,0,0,100,0),
(@PATH,28,1962.914,1478.641,82.39225,0,0,0,0,100,0),
(@PATH,29,1965.018,1478.875,82.15812,0,0,0,0,100,0),
(@PATH,30,1963.611,1479.624,82.54459,0,0,0,0,100,0),
(@PATH,31,1964.935,1479.779,82.42277,0,0,0,0,100,0),
(@PATH,32,1965.74,1480.748,82.63529,0,0,0,0,100,0),
(@PATH,33,1962.509,1479.685,82.63041,0,0,0,0,100,0),
(@PATH,34,1899.472,1506.11,89.18507,0,0,0,0,100,0),
(@PATH,35,1964.129,1482.499,83.14286,0,0,0,0,100,0),
(@PATH,36,1962.953,1480.367,82.7122,0,0,0,0,100,0),
(@PATH,37,1962.84,1482.145,82.92545,0,0,0,0,100,0),
(@PATH,38,1951.722,1476.789,80.07114,0,0,0,0,100,0),
(@PATH,39,1966.133,1497.141,87.51283,0,0,0,0,100,0),
(@PATH,40,1962.49,1502.687,88.28194,0,0,0,0,100,0),
(@PATH,41,1931.024,1520.287,87.80495,0,0,0,0,100,0),
(@PATH,42,1919.053,1526.27,87.28525,0,0,0,0,100,0),
(@PATH,43,1931.345,1572.519,84.00304,0,0,0,0,100,0),
(@PATH,44,1932.618,1590.822,83.50961,0,0,0,0,100,0),
(@PATH,45,1942.247,1594.761,83.02557,0,0,0,0,100,0),
(@PATH,46,1951.132,1592.334,82.47534,0,0,0,0,100,0);
-- 0x1C0910000001778000003200005A37D1 .go 1932.444 1590.943 83.48648

-- Pathing for  Entry: 1540 'TDB FORMAT' 
SET @NPC := 327390;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2868.919,`position_y`=-497.5436,`position_z`=101.3836 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2868.919,-497.5436,101.3836,0,0,0,0,100,0),
(@PATH,2,2858.415,-487.3856,100.1744,0,0,0,0,100,0),
(@PATH,3,2856.972,-486.0324,99.78797,0,0,0,0,100,0),
(@PATH,4,2843.022,-484.7172,99.42996,0,0,0,0,100,0),
(@PATH,5,2859.987,-484.1879,99.72915,0,0,0,0,100,0),
(@PATH,6,2866.828,-492.3687,100.8656,0,0,0,0,100,0),
(@PATH,7,2877.11,-515.8617,103.5658,0,0,0,0,100,0),
(@PATH,8,2882.539,-528.3811,106.7998,0,0,0,0,100,0),
(@PATH,9,2886.53,-532.085,106.4599,0,0,0,0,100,0),
(@PATH,10,2892.335,-533.3361,106.1121,0,0,0,0,100,0),
(@PATH,11,2892.335,-533.3361,106.1121,3,0,0,0,100,0),
(@PATH,14,2877.11,-515.8617,103.5658,0,0,0,0,100,0),
(@PATH,13,2882.539,-528.3811,106.7998,0,0,0,0,100,0),
(@PATH,12,2886.53,-532.085,106.4599,0,0,0,0,100,0);
-- 0x20091000000181000000320001DA3C6A .go 2868.919 -497.5436 101.3836

UPDATE `creature` SET `spawndist`=5, `MovementType`=1 WHERE  `guid` IN (325165, 325283, 325169);
UPDATE `creature` SET `spawndist`=10, `MovementType`=1 WHERE  `id` IN (1504, 1512, 1509, 1508, 1513); 
UPDATE `creature` SET `spawndist`=5, `MovementType`=1 WHERE  `id` IN (1505);
UPDATE `creature` SET `spawndist`=10, `MovementType`=1 WHERE `id` IN (4075, 1501); 
-- rndmmovement for zombies and spiders
UPDATE `creature_template` SET `flags_extra`=128 WHERE  `entry` IN (41200, 50373); -- make some triggers invisible

-- Arthura WPs
UPDATE `creature_template_addon` SET `path_id`=3250850 WHERE  `entry`=49129;
UPDATE `creature` SET `MovementType`=2 WHERE  `guid`=325085;
UPDATE `creature_template` SET `InhabitType`=4 WHERE  `entry`=49129;
DELETE FROM `waypoint_data` WHERE `id`=3250850;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(3250850, 1, 1724.74, 1656.3, 129.965, 0, 0, 0, 0, 100, 0),
(3250850, 2, 1715.78, 1653.78, 130.575, 0, 0, 0, 0, 100, 0),
(3250850, 3, 1708.85, 1655.94, 131.917, 0, 0, 0, 0, 100, 0),
(3250850, 4, 1703.59, 1662.75, 135.131, 0, 0, 0, 0, 100, 0),
(3250850, 5, 1707.63, 1669.57, 135.622, 0, 0, 0, 0, 100, 0),
(3250850, 6, 1712.76, 1678.44, 135.328, 0, 0, 0, 0, 100, 0),
(3250850, 7, 1714.48, 1680.85, 136.947, 0, 0, 0, 0, 100, 0),
(3250850, 8, 1721.21, 1690.48, 133.867, 0, 0, 0, 0, 100, 0),
(3250850, 9, 1723.79, 1682.86, 133.7, 0, 0, 0, 0, 100, 0),
(3250850, 10, 1729.12, 1660.73, 129.921, 0, 0, 0, 0, 100, 0),
(3250850, 11, 1730.36, 1651.11, 126.577, 0, 0, 0, 0, 100, 0),
(3250850, 12, 1730.8, 1645.58, 125.786, 0, 0, 0, 0, 100, 0),
(3250850, 13, 1730, 1639.18, 123.389, 0, 0, 0, 0, 100, 0),
(3250850, 14, 1733.74, 1645.03, 125.108, 0, 0, 0, 0, 100, 0),
(3250850, 15, 1737.1, 1651.43, 124.676, 0, 0, 0, 0, 100, 0),
(3250850, 16, 1741.5, 1665.87, 125.012, 0, 0, 0, 0, 100, 0),
(3250850, 17, 1741.39, 1668.2, 125.692, 0, 0, 0, 0, 100, 0),
(3250850, 18, 1736.75, 1671.43, 128.104, 0, 0, 0, 0, 100, 0),
(3250850, 19, 1730.89, 1668.52, 128.597, 0, 0, 0, 0, 100, 0),
(3250850, 20, 1729.21, 1661.78, 128.619, 0, 0, 0, 0, 100, 0);

-- Deathguard Philip WPs
DELETE FROM `creature_addon` WHERE `guid`=325281;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(325281, 325281*10, 0, 0, 0, 0, NULL);
UPDATE `creature` SET `MovementType`=2 WHERE  `guid`=325281;
DELETE FROM `waypoint_data` WHERE `id`=3252810;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(3252810, 1, 1864.6, 1588.79, 91.9528, 0, 0, 0, 0, 100, 0),
(3252810, 2, 1847.66, 1589.92, 93.1893, 0, 0, 0, 0, 100, 0),
(3252810, 3, 1830.08, 1590.87, 94.212, 0, 0, 0, 0, 100, 0),
(3252810, 4, 1827.76, 1591.13, 94.4932, 0, 0, 0, 0, 100, 0),
(3252810, 5, 1819.76, 1583.46, 95.7617, 0, 0, 0, 0, 100, 0),
(3252810, 6, 1820.29, 1583.7, 95.7512, 0, 12000, 0, 0, 100, 0),
(3252810, 7, 1818.45, 1577.18, 95.6734, 0, 0, 0, 0, 100, 0),
(3252810, 8, 1819.62, 1570.64, 95.651, 0, 0, 0, 0, 100, 0),
(3252810, 9, 1822.82, 1566.62, 95.6222, 0, 0, 0, 0, 100, 0),
(3252810, 10, 1828.65, 1565.43, 95.6222, 0, 12000, 0, 0, 100, 0),
(3252810, 11, 1830.56, 1577.89, 95.6222, 0, 0, 0, 0, 100, 0),
(3252810, 12, 1834.52, 1583.09, 94.5435, 0, 0, 0, 0, 100, 0),
(3252810, 13, 1835.25, 1586.03, 94.0295, 0, 0, 0, 0, 100, 0),
(3252810, 14, 1838.26, 1584.23, 94.2382, 0, 0, 0, 0, 100, 0),
(3252810, 15, 1840.03, 1583.26, 94.3261, 0, 0, 0, 0, 100, 0),
(3252810, 16, 1845.7, 1580.89, 94.6471, 0, 0, 0, 0, 100, 0),
(3252810, 17, 1848.39, 1562.46, 94.9115, 0, 12000, 0, 0, 100, 0),
(3252810, 18, 1849.56, 1571.14, 94.8565, 0, 0, 0, 0, 100, 0),
(3252810, 19, 1852.94, 1584.25, 93.2881, 0, 0, 0, 0, 100, 0),
(3252810, 20, 1864.81, 1587.66, 91.9009, 0, 0, 0, 0, 100, 0),
(3252810, 21, 1880.22, 1588.26, 90.1211, 0, 12000, 0, 0, 100, 0);

-- maquell Ebenwood
DELETE FROM `creature_addon` WHERE `guid`=325147;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(325147, 325147*10, 0, 0, 0, 0, NULL);
UPDATE `creature` SET `MovementType`=2 WHERE  `guid`=325147;
DELETE FROM `waypoint_data` WHERE `id`=3251470;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(3251470, 1, 1843.27, 1622.26, 96.934, 0, 0, 0, 0, 100, 0),
(3251470, 2, 1843.45, 1612.01, 96.9644, 0, 0, 0, 0, 100, 0),
(3251470, 3, 1843.54, 1606.17, 94.574, 0, 0, 0, 0, 100, 0),
(3251470, 4, 1843.69, 1597.78, 94.1531, 0, 0, 0, 0, 100, 0),
(3251470, 5, 1844.31, 1593.87, 93.54, 0, 0, 0, 0, 100, 0),
(3251470, 6, 1845.34, 1590.53, 93.2546, 0, 0, 0, 0, 100, 0),
(3251470, 7, 1848.22, 1589, 93.1615, 0, 0, 0, 0, 100, 0),
(3251470, 8, 1852.06, 1588.81, 92.9397, 0, 0, 0, 0, 100, 0),
(3251470, 9, 1861.31, 1588.43, 92.3485, 0, 9000, 0, 0, 100, 0),
(3251470, 10, 1860.1, 1582.73, 92.8286, 0, 0, 0, 0, 100, 0),
(3251470, 11, 1860.84, 1575.64, 94.313, 0, 0, 0, 0, 100, 0),
(3251470, 12, 1856.11, 1574.85, 94.313, 0, 0, 0, 0, 100, 0),
(3251470, 13, 1856.81, 1574.82, 94.313, 0, 20000, 0, 0, 100, 0),
(3251470, 14, 1860.65, 1575.1, 94.313, 0, 0, 0, 0, 100, 0),
(3251470, 15, 1859.94, 1581.8, 92.9871, 0, 0, 0, 0, 100, 0),
(3251470, 16, 1861.89, 1587.26, 92.2626, 0, 6000, 0, 0, 100, 0),
(3251470, 17, 1850.55, 1589.45, 93.0564, 0, 0, 0, 0, 100, 0),
(3251470, 18, 1844.98, 1590.98, 93.2717, 0, 0, 0, 0, 100, 0),
(3251470, 19, 1843.93, 1599.2, 94.3924, 0, 0, 0, 0, 100, 0),
(3251470, 20, 1843.22, 1607.13, 94.7863, 0, 0, 0, 0, 100, 0),
(3251470, 21, 1843.16, 1612.26, 96.9614, 0, 0, 0, 0, 100, 0),
(3251470, 22, 1843.17, 1622.76, 96.9337, 0, 0, 0, 0, 100, 0),
(3251470, 23, 1842.95, 1633.85, 96.9337, 0, 10000, 0, 0, 100, 0);

UPDATE `creature` SET `spawndist`=5, `MovementType`=1 WHERE  `id` IN (1502, 1890);
UPDATE `creature` SET `spawndist`=5, `MovementType`=1 WHERE  `guid` IN (325165, 325283, 325169);
UPDATE `creature` SET `position_x`=1911.95031, `position_y`=1586.911, `position_z`=85.2499, `orientation`=3.1770, `spawntimesecs`=60 WHERE  `guid`=325170;

-- Rattlecage Skeleton SAI
SET @GUID := -325170;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1890;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,25,0,100,0,0,0,0,0,53,0,325170,0,0,0,0,1,0,0,0,0,0,0,0,"Rattlecage Skeleton - On Reset - Start Waypoint"),
(@GUID,0,1,0,40,0,100,0,2,325170,0,0,49,0,0,0,0,0,0,19,1736,50,0,0,0,0,0,"Rattlecage Skeleton - On Waypoint 2 Reached - Start Attacking"),
(@GUID,0,2,0,0,0,100,0,2000,2000,15000,15000,75,81219,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rattlecage Skeleton - In Combat - Add Aura 'Battle Shout'"),
(@GUID,0,3,0,8,0,100,0,95826,0,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rattlecage Skeleton - On Spellhit 'Shoot' - Kill Self");

-- Wretched Ghoul SAI
SET @GUID := -325271;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1502;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,25,0,100,0,0,0,0,0,53,0,325170,0,0,0,0,1,0,0,0,0,0,0,0,"Wretched Ghoul - On Reset - Start Waypoint"),
(@GUID,0,1,3,40,0,100,0,2,325170,0,0,49,0,0,0,0,0,0,19,1736,50,0,0,0,0,0,"Wretched Ghoul - On Waypoint 2 Reached - Start Attacking"),
(@GUID,0,2,0,8,0,100,0,95826,0,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wretched Ghoul - On Spellhit 'Shoot' - Kill Self"),
(@GUID,0,3,0,61,0,100,0,2,325170,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wretched Ghoul - On Waypoint 2 Reached - Kill Self");

DELETE FROM `waypoints` WHERE `entry`=325170;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(325170, 1, 1900.452393, 1586.791138, 86.948174, ''),
(325170, 2, 1884.441, 1587.978, 89.5357, '');

-- Deathguard Randolph SAI
SET @ENTRY := 1736;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,2000,2000,3000,11,95826,66,0,0,0,0,2,0,0,0,0,0,0,0,"Deathguard Randolph - In Combat - Cast '<Spell not found!>'"),
(@ENTRY,0,1,0,25,0,100,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathguard Randolph - On Reset - Set Reactstate Aggressive");

UPDATE `creature` SET `spawndist`=10, `MovementType`=1 WHERE `id` IN (53526, 620, 1527, 39049, 1520, 1549, 1674, 1941, 1530, 1536, 4281, 4283, 4282, 1528, 51964, 51965, 51961, 1554, 1555, 1545, 1543, 1544, 1541, 1534, 1532, 1531, 1522, 1523, 1656, 1675, 1529);

UPDATE `creature_template_addon` SET `path_id`=3257150 WHERE  `entry`=1533;
UPDATE `creature` SET `MovementType`=2 WHERE  `guid`=325715;
DELETE FROM `waypoint_data` WHERE `id`=3257150;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(3257150, 1, 2745.419922, 978.708984, 109.392998, 0, 0, 0, 0, 100, 0),
(3257150, 2, 2765.810059, 993.661743, 109.732834, 0, 0, 0, 0, 100, 0),
(3257150, 3, 2774.722900, 1021.454529, 108.534164, 0, 0, 0, 0, 100, 0),
(3257150, 4, 2777.558838, 1045.788696, 108.904297, 0, 0, 0, 0, 100, 0),
(3257150, 5, 2794.649170, 1049.257568, 110.820305, 0, 0, 0, 0, 100, 0),
(3257150, 6, 2814.373047, 1046.770996, 110.820305, 0, 0, 0, 0, 100, 0),
(3257150, 7, 2839.627197, 1051.084717, 111.511284, 0, 0, 0, 0, 100, 0),
(3257150, 8, 2886.339600, 1065.823364, 105.970253, 0, 0, 0, 0, 100, 0),
(3257150, 9, 2891.578613, 1055.620850, 105.705093, 0, 0, 0, 0, 100, 0),
(3257150, 10, 2895.504150, 1029.036011, 107.049751, 0, 0, 0, 0, 100, 0),
(3257150, 11, 2898.632813, 979.230530, 113.568359, 0, 0, 0, 0, 100, 0),
(3257150, 12, 2899.541260, 957.061768, 115.106735, 0, 0, 0, 0, 100, 0),
(3257150, 13, 2908.080078, 932.908630, 114.917854, 0, 0, 0, 0, 100, 0),
(3257150, 14, 2905.685791, 923.912354, 114.982185, 0, 0, 0, 0, 100, 0),
(3257150, 15, 2893.146240, 913.490784, 114.658241, 0, 0, 0, 0, 100, 0),
(3257150, 16, 2855.242432, 880.518799, 112.352898, 0, 0, 0, 0, 100, 0),
(3257150, 17, 2826.591553, 864.780823, 111.842575, 0, 0, 0, 0, 100, 0),
(3257150, 18, 2802.163330, 864.498779, 111.841164, 0, 0, 0, 0, 100, 0),
(3257150, 19, 2773.511475, 880.237610, 111.774582, 0, 0, 0, 0, 100, 0),
(3257150, 20, 2752.895996, 899.921692, 111.763412, 0, 0, 0, 0, 100, 0),
(3257150, 21, 2736.951904, 942.523987, 109.499664, 0, 0, 0, 0, 100, 0),
(3257150, 22, 2734.885498, 956.346741, 109.242607, 0, 0, 0, 0, 100, 0),
(3257150, 23, 2737.154541, 972.515198, 109.242020, 0, 0, 0, 0, 100, 0);

UPDATE `creature_template_addon` SET `path_id`=3257480 WHERE  `entry`=5725;
UPDATE `creature` SET `MovementType`=2 WHERE  `guid`=325748;
DELETE FROM `waypoint_data` WHERE `id`=3257480;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(3257480, 1, 2129.376709, 953.351624, 29.058704, 0, 0, 0, 0, 100, 0),
(3257480, 2, 2104.569580, 878.170593, 32.416527, 0, 0, 0, 0, 100, 0),
(3257480, 3, 2093.044434, 813.923157, 33.563000, 0, 0, 0, 0, 100, 0),
(3257480, 4, 2093.758057, 767.299744, 33.564106, 0, 0, 0, 0, 100, 0),
(3257480, 5, 2101.969971, 750.510376, 33.560898, 0, 0, 0, 0, 100, 0),
(3257480, 6, 2167.280518, 694.103760, 33.355125, 0, 0, 0, 0, 100, 0),
(3257480, 7, 2180.792480, 682.982788, 33.393795, 0, 0, 0, 0, 100, 0),
(3257480, 8, 2239.743652, 601.869629, 33.333622, 0, 0, 0, 0, 100, 0),
(3257480, 9, 2261.292969, 541.476624, 33.534515, 0, 0, 0, 0, 100, 0),
(3257480, 10, 2255.469482, 505.762604, 34.113213, 0, 0, 0, 0, 100, 0),
(3257480, 11, 2275.757813, 426.780182, 33.952923, 0, 0, 0, 0, 100, 0),
(3257480, 12, 2283.910156, 385.661133, 34.126793, 0, 0, 0, 0, 100, 0),
(3257480, 13, 2285.265381, 348.391113, 33.624481, 0, 0, 0, 0, 100, 0),
(3257480, 14, 2273.001953, 315.611206, 33.431656, 0, 0, 0, 0, 100, 0),
(3257480, 15, 2255.712402, 290.769836, 33.507896, 0, 0, 0, 0, 100, 0),
(3257480, 16, 2232.237549, 275.507813, 33.573711, 0, 0, 0, 0, 100, 0),
(3257480, 17, 2207.864746, 248.755692, 33.631718, 0, 0, 0, 0, 100, 0),
(3257480, 18, 2173.530518, 226.758133, 38.763466, 0, 0, 0, 0, 100, 0),
(3257480, 19, 2164.428711, 214.597580, 41.493935, 0, 0, 0, 0, 100, 0),
(3257480, 20, 2160.420410, 183.353714, 41.991291, 0, 0, 0, 0, 100, 0),
(3257480, 21, 2143.672607, 170.800919, 39.302605, 0, 0, 0, 0, 100, 0),
(3257480, 22, 2120.702393, 159.453781, 36.839264, 0, 0, 0, 0, 100, 0),
(3257480, 23, 2090.853027, 153.441589, 34.950005, 0, 0, 0, 0, 100, 0),
(3257480, 24, 2067.516357, 154.855606, 33.928402, 0, 0, 0, 0, 100, 0),
(3257480, 25, 2045.528687, 162.187668, 33.877983, 0, 0, 0, 0, 100, 0),
(3257480, 26, 2067.516357, 154.855606, 33.928402, 0, 0, 0, 0, 100, 0),
(3257480, 27, 2090.853027, 153.441589, 34.950005, 0, 0, 0, 0, 100, 0),
(3257480, 28, 2120.702393, 159.453781, 36.839264, 0, 0, 0, 0, 100, 0),
(3257480, 29, 2143.672607, 170.800919, 39.302605, 0, 0, 0, 0, 100, 0),
(3257480, 30, 2160.420410, 183.353714, 41.991291, 0, 0, 0, 0, 100, 0),
(3257480, 31, 2164.428711, 214.597580, 41.493935, 0, 0, 0, 0, 100, 0),
(3257480, 32, 2173.530518, 226.758133, 38.763466, 0, 0, 0, 0, 100, 0),
(3257480, 33, 2207.864746, 248.755692, 33.631718, 0, 0, 0, 0, 100, 0),
(3257480, 34, 2232.237549, 275.507813, 33.573711, 0, 0, 0, 0, 100, 0),
(3257480, 35, 2255.712402, 290.769836, 33.507896, 0, 0, 0, 0, 100, 0),
(3257480, 36, 2273.001953, 315.611206, 33.431656, 0, 0, 0, 0, 100, 0),
(3257480, 37, 2285.265381, 348.391113, 33.624481, 0, 0, 0, 0, 100, 0),
(3257480, 38, 2283.910156, 385.661133, 34.126793, 0, 0, 0, 0, 100, 0),
(3257480, 39, 2275.757813, 426.780182, 33.952923, 0, 0, 0, 0, 100, 0),
(3257480, 40, 2255.469482, 505.762604, 34.113213, 0, 0, 0, 0, 100, 0),
(3257480, 41, 2261.292969, 541.476624, 33.534515, 0, 0, 0, 0, 100, 0),
(3257480, 42, 2239.743652, 601.869629, 33.333622, 0, 0, 0, 0, 100, 0),
(3257480, 43, 2180.792480, 682.982788, 33.393795, 0, 0, 0, 0, 100, 0),
(3257480, 44, 2167.280518, 694.103760, 33.355125, 0, 0, 0, 0, 100, 0),
(3257480, 45, 2101.969971, 750.510376, 33.560898, 0, 0, 0, 0, 100, 0),
(3257480, 46, 2093.758057, 767.299744, 33.564106, 0, 0, 0, 0, 100, 0),
(3257480, 47, 2093.044434, 813.923157, 33.563000, 0, 0, 0, 0, 100, 0),
(3257480, 48, 2104.569580, 878.170593, 32.416527, 0, 0, 0, 0, 100, 0),
(3257480, 49, 2129.376709, 953.351624, 29.058704, 0, 0, 0, 0, 100, 0),
(3257480, 50, 2187.656250, 1044.816895, 29.563383, 0, 0, 0, 0, 100, 0);
--
SET @Deathguards:= 44795;
SET @CreditKill := 44175;
SET @Dummy      := 44794;

UPDATE `creature_template` SET `AIName`='SmartAI', `scriptName`='' WHERE `entry`=@Dummy;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@Deathguards, @CreditKill);

DELETE FROM `smart_scripts` WHERE `entryorguid` = @Dummy  AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Dummy*100  AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Deathguards  AND `source_type` = 0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@Deathguards, 0, 0, 0, 8, 0, 100, 0, 2061, 0, 0, 0, 33, @CreditKill, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Deathguards - On spellHit - CreditKill'), -- Priest
(@Dummy, 0, 0, 0, 8, 0, 100, 0, 56641, 0, 0, 0, 33, @CreditKill, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Dummy - On spellHit - CreditKill'), -- hunter
(@Dummy, 0, 1, 0, 8, 0, 100, 0, 5143, 0, 0, 0, 33, @CreditKill, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Dummy - On spellHit - CreditKill'), -- Mage
(@Dummy, 0, 2, 0, 8, 0, 100, 0, 2098, 0, 0, 0, 33, @CreditKill, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Dummy - On spellHit - CreditKill'), -- Rogue
(@Dummy, 0, 3, 0, 8, 0, 100, 0, 348, 0, 0, 0, 33, @CreditKill, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Dummy - On spellHit - CreditKill'), -- Warlock
(@Dummy, 0, 4, 0, 8, 0, 100, 0, 100, 0, 0, 0, 33, @CreditKill, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Dummy - On spellHit - CreditKill'), -- Warrior
(@Dummy, 0, 5, 0, 25, 0, 100, 0, 0, 0, 0, 0, 80, @Dummy*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dummy - On reset - action list'),
(@Dummy*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, ' Argent - action list - react passif'),
(@Dummy*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 42, 0, 100, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, ' Argent - action list - set invinsible');
--
UPDATE `gossip_menu_option` SET `option_id`=5, `npc_option_npcflag`=32 WHERE `menu_id`=10684;
-- Marie Allen (General Goods Vendor)
UPDATE `gossip_menu_option` SET `option_id`=3,`npc_option_npcflag`=128 WHERE `menu_id`=10841;
-- Gerard Walthorn
UPDATE `gossip_menu_option` SET `option_id`=3,`npc_option_npcflag`=128 WHERE `menu_id`=10842;
--
DELETE FROM `creature_equip_template` WHERE `entry` IN (38781,38363,37694,36458,37067,35175);
INSERT INTO `creature_equip_template` (`entry`, `id`, `itemEntry1`, `itemEntry2`, `itemEntry3`, `VerifiedBuild`) VALUES
(38781, 1, 2714, 0, 0, 0),
(38363, 1, 0, 0, 34034, 0),
(37694, 1, 2901, 0, 0, 0),
(36458, 1, 25646, 0, 0, 0),
(37067, 1, 2695, 0, 0, 0),
(35175, 1, 2202, 0, 0, 0);
-- Wild Vortex SAI
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 45912;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 45912 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(45912, 0, 0, 0, 0, 0, 100, 0, 1600, 1600, 2500, 2500, 11, 88032, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Wild Vortex - In Combat - Cast 'Lightning Bolt'"),
(45912, 0, 1, 0, 8, 0, 10, 0, 0, 0, 5000, 10000, 11, 88010, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Wild Vortex - On SpellHit - Cast 'Cyclone'"),
(45912, 0, 2, 0, 13, 0, 50, 0, 5000, 10000, 0, 0, 11, 88029, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Wild Vortex - On Target SpellCast - Cast 'Wind Shock'");

-- Gust Soldier SAI
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 45477;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 45477 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(45477, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 11, 87930, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Gust Soldier - On Aggro - Cast 'Charge'"),
(45477, 0, 1, 0, 0, 0, 100, 0, 8000, 12000, 8000, 12000, 11, 87923, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gust Soldier - In Combat - Cast 'Wind Blast'"),
(45477, 0, 2, 0, 0, 0, 100, 0, 20000, 25000, 20000, 25000, 11, 87933, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gust Soldier - In Combat - Cast 'Air Nova'");

-- Armored Mistral SAI
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 45915;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 45915 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(45915, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 11, 88057, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gust Soldier - On Aggro - Cast 'Rising Winds'"),
(45915, 0, 1, 0, 0, 0, 100, 0, 10000, 12000, 8000, 12000, 11, 88061, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gust Soldier - In Combat - Cast 'Gale Strike'"),
(45915, 0, 2, 0, 0, 0, 100, 0, 12000, 15000, 12000, 15000, 11, 88055, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gust Soldier - In Combat - Cast 'Storm Surge'");

-- Cloud Prince SAI
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 45917;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 45917 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(45917, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 11, 88081, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Cloud Prince - On Aggro - Cast 'Whipping Winds'"),
(45917, 0, 1, 0, 0, 0, 100, 0, 5000, 10000, 5000, 10000, 11, 88073, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "Cloud Prince - In Combat - Cast 'Starfall'"),
(45917, 0, 2, 0, 0, 0, 100, 0, 10000, 15000, 10000, 15000, 11, 88075, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "Cloud Prince - In Combat - Cast 'Typhoon'");

-- Whipping Wind SAI 
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 47238;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 47238 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(47238, 0, 0, 0, 0, 0, 100, 0, 0, 0, 1500, 1500, 11, 88080, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Whipping Wind - In Combat - Cast 'Lightning Bolt'");

-- Turbulent Squall
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 45924;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 45924 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(45924, 0, 0, 0, 0, 0, 100, 0, 5000, 8000, 12000, 20000, 11, 88175, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Turbulent Squall - In Combat - Cast 'Asphyxiate'"),
(45924, 0, 1, 0, 0, 0, 100, 0, 10000, 15000, 5000, 15000, 11, 88170, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Turbulent Squall - In Combat - Cast 'Cloudburst'"),
(45924, 0, 2, 0, 0, 0, 100, 0, 5000, 20000, 20000, 25000, 11, 88171, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "Turbulent Squall - In Combat - Cast 'Hurricane'");

-- Empyrean Assassin
DELETE FROM `creature_template_addon` WHERE `entry` = 45922;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(45922, 0, 0, 0, 1, 0, '88184');

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 45922;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 45922 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(45922, 0, 0, 0, 0, 0, 100, 0, 20000, 20000, 20000, 20000, 11, 88182, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Empyrean Assassin - In Combat - Cast 'Vapor Form'");

-- Executor of the Caliph SAI
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 45928;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 45928 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(45928, 0, 0, 0, 0, 0, 100, 0, 6000, 6000, 6000, 6000, 11, 78660, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Executor of the Caliph - In Combat - Cast 'Devastate'"),
(45928, 0, 1, 0, 0, 0, 100, 0, 15000, 18000, 15000, 18000, 11, 87759, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Executor of the Caliph - In Combat - Cast 'Shockwave'"),
(45928, 0, 2, 0, 0, 0, 100, 0, 20000, 25000, 20000, 25000, 11, 87761, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Executor of the Caliph - In Combat - Cast 'Rally'");

-- Minister of Air SAI
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 45930;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 45930 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(45930, 0, 0, 0, 0, 0, 100, 0, 0, 0, 6000, 6000, 11, 87762, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Minister of Air - In Combat - Cast 'Lightning Lash'"),
(45930, 0, 1, 0, 0, 0, 100, 0, 12000, 18000, 12000, 18000, 11, 87768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Minister of Air - In Combat - Cast 'Lightning Nova'");

-- Servant of Asaad SAI
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 45926;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 45926 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(45926, 0, 0, 0, 0, 0, 100, 0, 6000, 6000, 6000, 6000, 11, 87771, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Servant of Asaad - In Combat - Cast 'Crusader Strike'"),
(45926, 0, 1, 0, 0, 0, 100, 0, 14000, 14000, 12000, 12000, 11, 58127, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Servant of Asaad - In Combat - Cast 'Divine Storm'"),
(45926, 0, 2, 0, 0, 0, 100, 0, 32000, 35000, 32000, 35000, 11, 87772, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Servant of Asaad - In Combat - Cast 'Hand of Protection'");

-- Temple Adept SAI
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 45935;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 45935 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(45935, 0, 0, 0, 0, 0, 100, 0, 500, 1000, 4000, 6000, 11, 88959, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Temple Adept - In Combat - Cast 'Holy Smite'"),
(45935, 0, 1, 0, 0, 0, 100, 0, 3000, 5000, 8000, 10000, 11, 87779, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Temple Adept - In Combat - Cast 'Greater Heal'"),
(45935, 0, 2, 0, 0, 0, 100, 0, 10000, 10000, 12000, 12000, 11, 87780, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Temple Adept - In Combat - Cast 'Desperate Speed'");
--
UPDATE `gameobject_loot_template` SET `QuestRequired`=1 WHERE `entry`=27260 AND `item`=46700;
--
UPDATE `gossip_menu_option` SET `option_id`=4, `npc_option_npcflag`=8192 WHERE `menu_id`=6944;
-- Ancestral Guardian SAI
SET @ENTRY := 48518;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,13500,14200,11,86085,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ancestral Guardian - Combat - Cast Mutilate");

-- Dark Ritualist Zakahn SAI
SET @ENTRY := 49148;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,12400,13500,11,9081,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Ritualist Zakahn - Range 0 to 8 - Cast Shadow Bolt Volley"),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,91614,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Ritualist Zakahn - Aggro - Cast Zakahn's Serpents"),
(@ENTRY,0,2,0,1,0,100,1,1000,1000,1000,1000,11,68797,2,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Ritualist Zakahn - OOC - Cast Aura (No Repeat)");

-- Akma'hat SAI
SET @ENTRY := 50063;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,9000,9000,22000,22000,11,94946,0,0,0,0,0,1,0,0,0,0,0,0,0,"Akma'hat - Combat - Cast 'Fury of the Sands'"),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,19500,27300,11,93578,0,0,0,0,0,1,0,0,0,0,0,0,0,"Akma'hat - Combat - Cast 'Sands of Time'"),
(@ENTRY,0,2,0,9,0,100,0,0,8,15800,18300,11,94968,0,0,0,0,0,2,0,0,0,0,0,0,0,"Akma'hat - Range 0 to 8 - Cast 'Shockwave'"),
(@ENTRY,0,3,0,2,0,100,1,0,40,0,0,11,93561,0,0,0,0,0,1,0,0,0,0,0,0,0,"Akma'hat - @40%HP - Cast 'Stone Mantle'");

-- Armagedillo SAI
SET @ENTRY := 50065;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,500,1000,5000,15000,11,93598,1,0,0,0,0,5,0,0,0,0,0,0,0,"Armagedillo - Combat - Cast 'Spiked Charge'"),
(@ENTRY,0,1,0,0,0,100,0,8000,12000,9000,15000,11,93592,1,0,0,0,0,2,0,0,0,0,0,0,0,"Armagedillo - Combat - Cast 'Dillogeddon'"),
(@ENTRY,0,2,0,0,0,100,0,6000,8000,6000,10000,11,93590,1,0,0,0,0,2,0,0,0,0,0,0,0,"Armagedillo - Combat - Cast 'Flame Breath'");

-- Oasis Crocolisk SAI
SET @ENTRY := 51675;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4000,12900,14700,11,48287,0,0,0,0,0,2,0,0,0,0,0,0,0,"Oasis Crocolisk - Combat - Cast 'Powerful Bite'"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,87228,0,0,0,0,0,1,0,0,0,0,0,0,0,"Oasis Crocolisk - @30%HP - Cast 'Thick Hide'");

-- Ferndweller Wasp SAI
SET @ENTRY := 51712;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,34392,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ferndweller Wasp - @30%HP - Cast 'Stinger Rage'"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ferndweller Wasp - @30%HP - Say Text 0");

-- Longstrider Gazelle SAI
SET @ENTRY := 51713;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,12000,13000,11,32019,0,0,0,0,0,2,0,0,0,0,0,0,0,"Longstrider Gazelle - Combat - Cast Gore");
