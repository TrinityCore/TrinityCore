UPDATE `creature_template` SET `flags_extra`=0 WHERE  `entry`=37826;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN(37832,37878);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 1, 37832, 0, 0, 29, 1, 37857, 100, 0, 1, 0, 0, '', 'Lich King Stun Bunny only Trigger if there is no spawn of the Lich King within 100 Yards'),
(22, 1, 37832, 0, 0, 29, 1, 37893, 100, 0, 1, 0, 0, '', 'Lich King Stun Bunny only Trigger if there is no spawn of Vegard within 100 Yards'),
(22, 1, 37832, 0, 0, 29, 1, 37976, 100, 0, 1, 0, 0, '', 'Lich King Stun Bunny only Trigger if there is no spawn of Vegard within 100 Yards'),
(22, 1, 37832, 0, 0, 30, 1, 201922, 100, 0, 1, 0, 0, '', 'Lich King Stun Bunny only Trigger if there is no spawn of Lights Vengence within 100 Yards'),
(22, 1, 37832, 0, 0, 30, 1, 201844, 100, 0, 1, 0, 0, '', 'Lich King Stun Bunny only Trigger if there is no spawn of Lights Vengence within 100 Yards'),
(22, 1, 37878, 0, 0, 29, 1, 37881, 2, 0, 1, 0, 0, '', 'AOD Impact Bunny only Trigger if there is no spawn of Wrethed Ghoul within 2 yards'),
(22, 2, 37878, 0, 0, 29, 1, 37881, 2, 0, 1, 0, 0, '', 'AOD Impact Bunny only Trigger if there is no spawn of Wrethed Ghoul within 2 yards');
