--
SET @Hira :=31238;

UPDATE creature_template SET ScriptName='', `AIName`='SmartAI', InhabitType=4 WHERE entry=@Hira;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=10723;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`, `ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,10723,1,0,27,80,3,0,0,'','Show gossip menu if player''s level 80 or higher'),
(15,10723,1,0,25,54197,0,0,0,'','Show gossip menu if player has lerned 54197');

DELETE FROM `smart_scripts` WHERE `entryorguid` = @Hira AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Hira*100 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Hira*100+1 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@Hira, 0, 0, 0, 1, 0, 100, 0, 600000, 600000, 600000, 600000, 80, @Hira*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hira - OOC - actionlist'),
(@Hira*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hira - actionlist - talk (emote)'),
(@Hira*100, 9, 1, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hira - actionlist - talk'),
(@Hira*100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 18, 33554432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hira - actionlist - set UNIT_FLAG_NOT_SELECTABLE'),
(@Hira*100, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 1, @Hira, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hira - actionlist - start wp'),
(@Hira,0 ,1 ,0 ,40 ,0 ,100 ,0, 11, 0, 0, 0 ,80, @Hira*100+1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ruul the Darkener - way point reached - Re action list'),
(@Hira*100+1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 5815.272, 473.4902, 658.7961, 4.660029, 'Hira - actionlist - SET Orientation'),
(@Hira*100+1, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 19, 33554432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hira - actionlist - remove UNIT_FLAG_NOT_SELECTABLE');

DELETE FROM `waypoints` WHERE `entry`=@Hira;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@Hira,1,5806.834, 475.4562, 661.3664, 'Hira Snowdawn WP'),
(@Hira,2,5792.614, 466.3004, 662.0329, 'Hira Snowdawn WP'),
(@Hira,3,5786.764, 450.582, 662.5331, 'Hira Snowdawn WP'),
(@Hira,4,5791.111, 434.2068, 665.3663, 'Hira Snowdawn WP'),
(@Hira,5,5804.108, 423.6482, 665.6719, 'Hira Snowdawn WP'),
(@Hira,6,5821.129, 422.7363, 665.1718, 'Hira Snowdawn WP'),
(@Hira,7,5835.191, 431.9838, 663.9774, 'Hira Snowdawn WP'),
(@Hira,8,5841.177, 447.7776, 662.783, 'Hira Snowdawn WP'),
(@Hira,9,5836.82, 464.0104, 661.894, 'Hira Snowdawn WP'),
(@Hira,10,5823.853, 474.5901, 661.3664, 'Hira Snowdawn WP'),
(@Hira,11,5815.272, 473.4902, 658.7961, 'Hira Snowdawn WP');

DELETE FROM `creature_text` WHERE `entry` IN (@Hira);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(@Hira, 0, 0, 'Come, Cloudwing. Let''s do a lap.', 12, 0, 100, 0, 0, 0, 'Hira Snowdawn', 32247),
(@Hira, 0, 1, 'Feeling as restless as I am, Cloudwing? Then let us fly!', 12, 0, 100, 0, 0, 0, 'Hira Snowdawn', 32252),
(@Hira, 0, 2, 'I''m bored, Cloudwing. Go, go!', 12, 0, 100, 0, 0, 0, 'Hira Snowdawn', 32251),
(@Hira, 1, 0, '%s sighs softly and rolls her shoulders.', 16, 0, 100, 0, 0, 0, 'Hira Snowdawn', 32249),
(@Hira, 1, 1, '%s looks around Krasus'' Landing, bored.', 16, 0, 100, 0, 0, 0, 'Hira Snowdawn', 32244),
(@Hira, 1, 2, '%s yawns quietly into the palm of her hand.', 16, 0, 100, 0, 0, 0, 'Hira Snowdawn', 32245);
