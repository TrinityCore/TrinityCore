UPDATE `smart_scripts` SET `event_chance`=100 WHERE  `entryorguid`=26417 AND `source_type`=0 AND `id`=2 AND `link`=3;
UPDATE `smart_scripts` SET `event_chance`=100, `action_type`=87, `action_param2`=2641701, `action_param3`=2641701, `action_param4`=2641701 WHERE  `entryorguid`=26417 AND `source_type`=0 AND `id`=3 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=2641701 AND `source_type`=9 AND `id`=0 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=26417 AND `source_type`=0 AND `id`>3;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=26261 AND `source_type`=0 AND `id`=3 AND `link`=0;
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE  `entry`IN(188264,188288,188289);
DELETE FROM `smart_scripts` WHERE `source_type`=1 AND `entryorguid`IN(188264,188288,188289);
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry`IN(26445);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`IN(26445);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(-109925,-109919,-109926,-109911,-109912,-109910,-109908,-109920,-109913,-109921,-109923,-109909,-109922);

DELETE FROM `conditions` WHERE  `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=46820;
DELETE FROM `conditions` WHERE  `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=47320;

INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 46820, 0, 1, 31, 0, 3, 26264, 0, 0, 0, 0,'', 'Toss Tree - only targets Dummy'),
(13, 1, 47320, 0, 1, 31, 0, 3, 26261, 0, 0, 0, 0,'', 'Toss Boulder 2 - only targets Runed Giant');

UPDATE`smart_scripts` SET `action_param1`=47320,`comment`='Grizzly Hills Giant - Out of Combat - Cast \'Toss Boulder 2\'' WHERE  `entryorguid`=26261 AND `source_type`=0 AND `id`=2 AND `link`=0;
UPDATE `smart_scripts` SET `event_param3`=12000, `event_param4`=21000 WHERE  `entryorguid`=26261 AND `source_type`=0 AND `id`=2 AND `link`=0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(2641701, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 36, 26872, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Runed Giant - On Script 2 - Change entry to Weakened Giant'),
(26417, 0, 4, 0, 75, 0, 100, 0, 0, 26261, 30, 0, 49, 0, 0, 0, 0, 0, 0, 19, 26261, 0, 0, 0, 0, 0, 0, 'Runed Giant - On Grizzly Hills Giant within 20 yards - Attack Grizzly Hills Giant'),
(26261, 0, 3, 0, 75, 0, 100, 0, 0, 26417, 30, 0, 49, 0, 0, 0, 0, 0, 0, 19, 26417, 0, 0, 0, 0, 0, 0, 'Grizzly Hills Giant - On Runed Giant in Range - Attack Runed Giant'),
(188264, 1, 0, 1, 70, 0, 100, 0, 2, 0, 0, 0, 12, 26445, 1, 1000, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'First Rune Plate - On Gossip Hello - Summon Rune Plate'),
(188264, 1, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 26445, 0, 0, 0, 0, 0, 0, 'First Rune Plate - On Gossip Hello - Set Data on Rune Plate'),
(188288, 1, 0, 1, 70, 0, 100, 0, 2, 0, 0, 0, 12, 26445, 1, 1000, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Second Rune Plate - On Gossip Hello - Summon Rune Plate'),
(188288, 1, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 19, 26445, 0, 0, 0, 0, 0, 0, 'Second Rune Plate - On Gossip Hello - Set Data on Rune Plate'),
(188289, 1, 0, 1, 70, 0, 100, 0, 2, 0, 0, 0, 12, 26445, 1, 1000, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Third Rune Plate - On Gossip Hello - Summon Rune Plate'),
(188289, 1, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 45, 3, 3, 0, 0, 0, 0, 19, 26445, 0, 0, 0, 0, 0, 0, 'Third Rune Plate - On Gossip Hello - Set Data on Rune Plate'),
(26445, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 84, 0, 0, 0, 0, 0, 0, 21, 10, 0, 0, 0, 0, 0, 0, 'Rune Plate - On Data Set - Simple Talk Group 0'),
(26445, 0, 1, 0, 38, 0, 100, 0, 2, 2, 0, 0, 84, 1, 0, 0, 0, 0, 0, 21, 10, 0, 0, 0, 0, 0, 0, 'Rune Plate - On Data Set - Simple Talk Group 1'),
(26445, 0, 2, 0, 38, 0, 100, 0, 3, 3, 0, 0, 84, 2, 0, 0, 0, 0, 0, 21, 10, 0, 0, 0, 0, 0, 0, 'Rune Plate - On Data Set - Simple Talk Group 2'),
(-109925, 0, 0, 0, 1, 0, 100, 0, 2000, 5000, 5000, 8000, 11, 46815, 0, 0, 0, 0, 0, 19, 26264, 85, 0, 0, 0, 0, 0, 'Grizzly Hills Giant - Out of Combat - Cast \'Toss Boulder\''),
(-109925, 0, 1, 0, 1, 0, 100, 0, 8000, 20000, 10000, 28000, 11, 46820, 0, 0, 0, 0, 0, 19, 26264, 85, 0, 0, 0, 0, 0, 'Grizzly Hills Giant - Out of Combat - Cast \'Toss Tree\''),
(-109919, 0, 0, 0, 1, 0, 100, 0, 2000, 5000, 5000, 8000, 11, 46815, 0, 0, 0, 0, 0, 19, 26264, 85, 0, 0, 0, 0, 0, 'Grizzly Hills Giant - Out of Combat - Cast \'Toss Boulder\''),
(-109919, 0, 1, 0, 1, 0, 100, 0, 8000, 20000, 10000, 28000, 11, 46820, 0, 0, 0, 0, 0, 19, 26264, 85, 0, 0, 0, 0, 0, 'Grizzly Hills Giant - Out of Combat - Cast \'Toss Tree\''),
(-109926, 0, 0, 0, 1, 0, 100, 0, 2000, 5000, 5000, 8000, 11, 46815, 0, 0, 0, 0, 0, 19, 26264, 85, 0, 0, 0, 0, 0, 'Grizzly Hills Giant - Out of Combat - Cast \'Toss Boulder\''),
(-109926, 0, 1, 0, 1, 0, 100, 0, 8000, 20000, 10000, 28000, 11, 46820, 0, 0, 0, 0, 0, 19, 26264, 85, 0, 0, 0, 0, 0, 'Grizzly Hills Giant - Out of Combat - Cast \'Toss Tree\''),
(-109911, 0, 0, 0, 1, 0, 100, 0, 2000, 5000, 5000, 8000, 11, 46815, 0, 0, 0, 0, 0, 19, 26264, 85, 0, 0, 0, 0, 0, 'Grizzly Hills Giant - Out of Combat - Cast \'Toss Boulder\''),
(-109911, 0, 1, 0, 1, 0, 100, 0, 8000, 20000, 10000, 28000, 11, 46820, 0, 0, 0, 0, 0, 19, 26264, 85, 0, 0, 0, 0, 0, 'Grizzly Hills Giant - Out of Combat - Cast \'Toss Tree\''),
(-109912, 0, 0, 0, 1, 0, 100, 0, 2000, 5000, 5000, 8000, 11, 46815, 0, 0, 0, 0, 0, 19, 26264, 85, 0, 0, 0, 0, 0, 'Grizzly Hills Giant - Out of Combat - Cast \'Toss Boulder\''),
(-109912, 0, 1, 0, 1, 0, 100, 0, 8000, 20000, 10000, 28000, 11, 46820, 0, 0, 0, 0, 0, 19, 26264, 85, 0, 0, 0, 0, 0, 'Grizzly Hills Giant - Out of Combat - Cast \'Toss Tree\''),
(-109910, 0, 0, 0, 1, 0, 100, 0, 2000, 5000, 5000, 8000, 11, 46815, 0, 0, 0, 0, 0, 19, 26264, 85, 0, 0, 0, 0, 0, 'Grizzly Hills Giant - Out of Combat - Cast \'Toss Boulder\''),
(-109910, 0, 1, 0, 1, 0, 100, 0, 8000, 20000, 10000, 28000, 11, 46820, 0, 0, 0, 0, 0, 19, 26264, 85, 0, 0, 0, 0, 0, 'Grizzly Hills Giant - Out of Combat - Cast \'Toss Tree\''),
(-109908, 0, 0, 0, 1, 0, 100, 0, 2000, 5000, 5000, 8000, 11, 46815, 0, 0, 0, 0, 0, 19, 26264, 85, 0, 0, 0, 0, 0, 'Grizzly Hills Giant - Out of Combat - Cast \'Toss Boulder\''),
(-109908, 0, 1, 0, 1, 0, 100, 0, 8000, 20000, 10000, 28000, 11, 46820, 0, 0, 0, 0, 0, 19, 26264, 85, 0, 0, 0, 0, 0, 'Grizzly Hills Giant - Out of Combat - Cast \'Toss Tree\''),
(-109920, 0, 0, 0, 1, 0, 100, 0, 2000, 5000, 5000, 8000, 11, 46815, 0, 0, 0, 0, 0, 19, 26264, 85, 0, 0, 0, 0, 0, 'Grizzly Hills Giant - Out of Combat - Cast \'Toss Boulder\''),
(-109920, 0, 1, 0, 1, 0, 100, 0, 8000, 20000, 10000, 28000, 11, 46820, 0, 0, 0, 0, 0, 19, 26264, 85, 0, 0, 0, 0, 0, 'Grizzly Hills Giant - Out of Combat - Cast \'Toss Tree\''),
(-109913, 0, 0, 0, 1, 0, 100, 0, 2000, 5000, 5000, 8000, 11, 46815, 0, 0, 0, 0, 0, 19, 26264, 85, 0, 0, 0, 0, 0, 'Grizzly Hills Giant - Out of Combat - Cast \'Toss Boulder\''),
(-109913, 0, 1, 0, 1, 0, 100, 0, 8000, 20000, 10000, 28000, 11, 46820, 0, 0, 0, 0, 0, 19, 26264, 85, 0, 0, 0, 0, 0, 'Grizzly Hills Giant - Out of Combat - Cast \'Toss Tree\''),
(-109921, 0, 0, 0, 1, 0, 100, 0, 2000, 5000, 5000, 8000, 11, 46815, 0, 0, 0, 0, 0, 19, 26264, 85, 0, 0, 0, 0, 0, 'Grizzly Hills Giant - Out of Combat - Cast \'Toss Boulder\''),
(-109921, 0, 1, 0, 1, 0, 100, 0, 8000, 20000, 10000, 28000, 11, 46820, 0, 0, 0, 0, 0, 19, 26264, 85, 0, 0, 0, 0, 0, 'Grizzly Hills Giant - Out of Combat - Cast \'Toss Tree\''),
(-109923, 0, 0, 0, 1, 0, 100, 0, 2000, 5000, 5000, 8000, 11, 46815, 0, 0, 0, 0, 0, 19, 26264, 85, 0, 0, 0, 0, 0, 'Grizzly Hills Giant - Out of Combat - Cast \'Toss Boulder\''),
(-109923, 0, 1, 0, 1, 0, 100, 0, 8000, 20000, 10000, 28000, 11, 46820, 0, 0, 0, 0, 0, 19, 26264, 85, 0, 0, 0, 0, 0, 'Grizzly Hills Giant - Out of Combat - Cast \'Toss Tree\''),
(-109909, 0, 0, 0, 1, 0, 100, 0, 2000, 5000, 5000, 8000, 11, 46815, 0, 0, 0, 0, 0, 19, 26264, 85, 0, 0, 0, 0, 0, 'Grizzly Hills Giant - Out of Combat - Cast \'Toss Boulder\''),
(-109909, 0, 1, 0, 1, 0, 100, 0, 8000, 20000, 10000, 28000, 11, 46820, 0, 0, 0, 0, 0, 19, 26264, 85, 0, 0, 0, 0, 0, 'Grizzly Hills Giant - Out of Combat - Cast \'Toss Tree\''),
(-109922, 0, 0, 0, 1, 0, 100, 0, 2000, 5000, 5000, 8000, 11, 46815, 0, 0, 0, 0, 0, 19, 26264, 85, 0, 0, 0, 0, 0, 'Grizzly Hills Giant - Out of Combat - Cast \'Toss Boulder\''),
(-109922, 0, 1, 0, 1, 0, 100, 0, 8000, 20000, 10000, 28000, 11, 46820, 0, 0, 0, 0, 0, 19, 26264, 85, 0, 0, 0, 0, 0, 'Grizzly Hills Giant - Out of Combat - Cast \'Toss Tree\'');

DELETE FROM `creature_text` WHERE `entry` in(26445);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(26445, 0, 0, 'Shall return to the cradle of iron and stone.', 12, 0, 100, 0, 0, 0, 25686, 'Rune Plate'),
(26445, 1, 0, 'Return to Ulduar, nestled in the embrace of the storm.', 12, 0, 100, 0, 0, 0, 25688, 'Rune Plate'),
(26445, 2, 0, 'Greatest of the Maker''s children, arise and claim your birthright.', 12, 0, 100, 0, 0, 0, 25690, 'Rune Plate');
