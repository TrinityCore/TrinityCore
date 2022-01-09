-- 
DELETE FROM `creature_template_addon` WHERE `entry` IN(18778,20304);
INSERT INTO `creature_template_addon` (`entry`, `auras`, `visibilityDistanceType`) VALUES (18778, '32460', 3), (20304, '32460', 3);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (32930);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 32930, 0, 31, 3, 18778, 0, 0, '', ""),
(13, 1, 32930, 1, 31, 3, 18493, 83375, 0, '', ""),
(13, 1, 32930, 2, 31, 3, 18493, 83377, 0, '', "");

UPDATE `creature_addon` SET `bytes1`=0, `emote`=375 WHERE `guid` IN (83407,83395);
