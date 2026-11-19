UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry`in(23392,23257,23334,23208,23335,22982);


DELETE FROM `creature_text` WHERE `entry` in(23392,23257,23334,23208,23335,22982);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(23392, 0, 0, '$n is an officer and a $g gentleman : gentlewoman;.', 12, 0, 100, 0, 0, 0, 21940, 0, 'Skyguard Stable Master <Stable Master>'),
(23257, 0, 0, 'Look who''s here.  It''s $n, our top gun.', 12, 0, 100, 0, 0, 0, 21885, 0, 'Skyguard Windcharger'),
(23257, 0, 1, '$n, terror of the skies, how are you doing?', 12, 0, 100, 0, 0, 0, 21893, 0, 'Skyguard Windcharger'),
(23257, 0, 2, 'A-TEN-HUT, officer $n on the deck!', 12, 0, 100, 0, 0, 0, 21891, 0, 'Skyguard Windcharger'),
(23257, 0, 3, '$G Mister : Lady; $n, what an unexpected pleasure, $g sir : ma''am;.', 12, 0, 100, 0, 0, 0, 21890, 0, 'Skyguard Windcharger'),
(23257, 0, 4, 'Heh, the skies aren''t so friendly with $n flying them!', 12, 0, 100, 0, 0, 0, 21895, 0, 'Skyguard Windcharger'),
(23257, 0, 5, '$n, you and I should race sometime.', 12, 0, 100, 0, 0, 0, 21937, 0, 'Skyguard Windcharger'),
(23257, 0, 6, '$n, how''s your mount holding up?  Pretty rough up there these days?', 12, 0, 100, 0, 0, 0, 21897, 0, 'Skyguard Windcharger'),
(23334, 0, 0, 'Maybe one day $n will teach us a few of $g his : her; tricks?', 12, 0, 100, 0, 0, 0, 21942, 0, 'Sky Commander Keller'),
(23208, 0, 0, 'Maybe one day $n will teach us a few of $g his : her; tricks?', 12, 0, 100, 0, 0, 0, 21942, 0, 'Skyguard Pyrotechnician'),
(23335, 0, 0, 'You''re a peach!  I''ll make sure that the ray is properly cared for.', 12, 0, 100, 0, 0, 0, 21371, 0, 'Skyguard Khatie'),
(23335, 0, 1, 'Wow!  Thanks for bringing it all the way back here.  You didn''t have to do that.', 12, 0, 100, 0, 0, 0, 21370, 0, 'Skyguard Khatie'),
(22982, 0, 0, '$n, do you feel the need -- the need for speed?', 12, 0, 100, 0, 0, 0, 21886, 0, 'Skyguard Navigator'),
(22982, 0, 1, '$n, how''s your mount holding up?  Pretty rough up there these days?', 12, 0, 100, 0, 0, 0, 21897, 0, 'Skyguard Navigator'),
(22982, 0, 3, 'Heh, the skies aren''t so friendly with $n flying them!', 12, 0, 100, 0, 0, 0, 21895, 0, 'Skyguard Navigator'),
(22982, 0, 4, '$n, terror of the skies, how are you doing?', 12, 0, 100, 0, 0, 0, 21893, 0, 'Skyguard Navigator');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(23392,23257,23334,23208,23335,22982) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(23392, 0, 0, 0, 10, 0, 100, 0, 1, 10, 300000, 300000, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Skyguard Stable Master <Stable Master> - OOC LOS - Say'),
(23257, 0, 0, 0, 10, 0, 100, 0, 1, 10, 150000, 150000, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Skyguard Stable Master - OOC LOS - Say'),
(23334, 0, 0, 0, 10, 0, 100, 0, 1, 10, 300000, 300000, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Sky Commander Keller - OOC LOS - Say'),
(23208, 0, 0, 0, 10, 0, 100, 0, 1, 10, 300000, 300000, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Skyguard Pyrotechnician - OOC LOS - Say'),
(23335, 0, 0, 0, 10, 0, 100, 0, 1, 10, 300000, 300000, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Skyguard Khatie - OOC LOS - Say'),
(22982, 0, 0, 0, 10, 0, 100, 0, 1, 10, 150000, 150000, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Skyguard Navigator - OOC LOS - Say');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN(23392,23257,23334,23208,23335,22982);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 1, 23392, 0, 0, 5, 0, 1031, 128, 0, 0, 0, 0, '', 'requires shatari skyguard exhalted'),
(22, 1, 23257, 0, 0, 5, 0, 1031, 128, 0, 0, 0, 0, '', 'requires shatari skyguard exhalted'),
(22, 1, 23334, 0, 0, 5, 0, 1031, 128, 0, 0, 0, 0, '', 'requires shatari skyguard exhalted'),
(22, 1, 23208, 0, 0, 5, 0, 1031, 128, 0, 0, 0, 0, '', 'requires shatari skyguard exhalted'),
(22, 1, 23335, 0, 0, 28, 0, 11023, 0, 0, 0, 0, 0, '', 'requires Bomb Them Again complete in quest log'),
(22, 1, 23335, 0, 1, 28, 0, 11010, 0, 0, 0, 0, 0, '', 'requires Bombing run complete in quest log'),
(22, 1, 23335, 0, 2, 28, 0, 11102, 0, 0, 0, 0, 0, '', 'requires Bombing run complete in quest log'),
(22, 1, 22982, 0, 0, 5, 0, 1031, 128, 0, 0, 0, 0, '', 'requires shatari skyguard exhalted');
