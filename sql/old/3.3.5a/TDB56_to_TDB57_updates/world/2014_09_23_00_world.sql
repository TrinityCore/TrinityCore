DELETE FROM `conditions` WHERE  `SourceTypeOrReferenceId`=17 AND  `SourceEntry`=45274;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(17, 0, 45274, 0, 0, 31, 1, 3, 25226, 0, 0, 0, 0, '', 'The King\'s Empty Conch requires target Scalder'),
(17, 0, 45274, 0, 0, 36, 1, 0, 0, 0, 1, 0, 0, '', 'The King\'s Empty Conch requires target is dead');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN(25226,25197);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(25226,25197) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(25226, 0, 0, 0, 9, 0, 100, 0, 0, 20, 10000, 15000, 11, 50257, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Scalder - On Range - Cast Scalding Blast'),
(25226, 0, 1, 0, 9, 0, 100, 0, 0, 3000, 2500, 4000, 11, 32011, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Scalder - On Range - Cast Water Bolt'),
(25197, 0, 0, 0,20, 0, 100, 0, 11571, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'King Mrgl-Mrgl - On Quest Reward (Learning to Communicate) - Say');

DELETE FROM `creature_text` WHERE `entry`=25197;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`,`BroadcastTextID`) VALUES
(25197, 0, 0, 'There, $n, now you will be able to speak with, and understand, the Winterfin murlocs.', 12, 0, 100, 1, 0, 0, 'King Mrgl-Mrgl',24428);
