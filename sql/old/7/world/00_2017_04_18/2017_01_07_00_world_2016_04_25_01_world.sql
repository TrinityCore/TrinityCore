DELETE FROM `smart_scripts` WHERE `entryorguid` IN(24161) AND `source_type`=0 AND `id`>4;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(24162,24016) AND `source_type`=0 AND `id`>3;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(24015) AND `source_type`=0 AND `id`>2;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(24161, 0, 5, 6, 11, 0, 100, 0, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Oric the Baleful - On Spawn - Set Immune to combat'),
(24161, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Oric the Baleful - On Spawn - Set Invisible'),
(24161, 0, 7, 8, 38, 0, 100, 1, 1, 1, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Oric the Baleful - On Data Set - Enable combat Immune to combat'),
(24161, 0, 8, 9, 61, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Oric the Baleful - On Data Set - Set visible'),
(24161, 0, 9, 0, 61, 0, 100, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Oric the Baleful - On Data Set - Say'),
(24162, 0, 4, 5, 11, 0, 100, 0, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gunnar Thorvardsson - On Spawn - Set Immune to combat'),
(24162, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gunnar Thorvardsson - On Spawn - Set Invisible'),
(24162, 0, 6, 7, 38, 0, 100, 1, 1, 1, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gunnar Thorvardsson - On Data Set - Enable combat Immune to combat'),
(24162, 0, 7, 8, 61, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gunnar Thorvardsson - On Data Set - Set visible'),
(24162, 0, 8, 0, 61, 0, 100, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gunnar Thorvardsson - On Data Set - Say'),
(24016, 0, 4, 5, 11, 0, 100, 0, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ulf the Bloodletter - On Spawn - Set Immune to combat'),
(24016, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ulf the Bloodletter - On Spawn - Set Invisible'),
(24016, 0, 6, 7, 38, 0, 100, 1, 1, 1, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ulf the Bloodletter - On Data Set - Enable combat Immune to combat'),
(24016, 0, 7, 8, 61, 0, 100, 1, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ulf the Bloodletter - On Data Set - Set visible'),
(24016, 0, 8, 0, 61, 0, 100, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ulf the Bloodletter - On Data Set - Say'),
(24015, 0, 3, 0, 6, 0, 15, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 24161, 0, 0, 0, 0, 0, 0, 'Winterskorn Defender - On Death - Set Data on Oric the Baleful'),
(24015, 0, 4, 0, 6, 0, 15, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 24162, 0, 0, 0, 0, 0, 0, 'Winterskorn Defender - On Death - Set Data on Gunnar Thorvardsson'),
(24015, 0, 5, 0, 6, 0, 15, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 24016, 0, 0, 0, 0, 0, 0, 'Winterskorn Defender - On Death - Set Data on Ulf the Bloodletter');

DELETE FROM `creature_text` WHERE `entry` IN(24161,24162,24016);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(24161, 0, 0, 'Enemies of the Winterskorn, you will be torn limb from limb!', 14, 0, 100, 0, 0, 0, 22867, 0, 'Oric the Baleful'),
(24016, 0, 0, 'Drive this scum from the Vrykul homeland!', 14, 0, 100, 0, 0, 0, 22868, 0, 'Ulf the Bloodletter'),
(24162, 0, 0, 'Gunnar, son of Thorvard, has arrived!  Prepare to meet your demise!', 14, 0, 100, 0, 0, 0, 22863, 0, 'Gunnar Thorvardsson');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN(24161,24162,24016,24015);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 6, 24161, 0, 0, 36, 1, 0, 0, 0, 0, 0, 0, '', 'Only execute SAI if Oric the Baleful alive'),
(22, 5, 24016, 0, 0, 36, 1, 0, 0, 0, 0, 0, 0, '', 'Only execute SAI if Ulf the Bloodletter alive'),
(22, 5, 24162, 0, 0, 36, 1, 0, 0, 0, 0, 0, 0, '', 'Only execute SAI if Gunnar Thorvardsson alive'),
(22, 4, 24015, 0, 0, 9, 0, 11282, 0, 0, 0, 0, 0, '', 'Only execute SAI if player has A Lesson in Fear taken'),
(22, 5, 24015, 0, 0, 9, 0, 11282, 0, 0, 0, 0, 0, '', 'Only execute SAI if player has A Lesson in Fear taken'),
(22, 6, 24015, 0, 0, 9, 0, 11282, 0, 0, 0, 0, 0, '', 'Only execute SAI if player has A Lesson in Fear taken');

UPDATE `smart_scripts` SET `link`=0 WHERE  `entryorguid`=29647 AND `source_type`=0 AND `id`=1 AND `link`=2;
UPDATE `smart_scripts` SET `link`=4 WHERE  `entryorguid`=29884 AND `source_type`=0 AND `id`=3 AND `link`=0;

