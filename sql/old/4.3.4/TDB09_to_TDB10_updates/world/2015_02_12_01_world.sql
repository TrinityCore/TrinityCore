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
