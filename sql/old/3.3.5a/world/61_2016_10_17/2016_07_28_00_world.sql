SET @ATTUMEN_UNMOUNTED := 15550;
SET @ATTUMEN_MOUNTED   := 16152;
SET @MIDNIGHT          := 16151;
SET @GMIDNIGHT         := 135159;

DELETE FROM `creature_text` WHERE `entry` IN (@MIDNIGHT, @ATTUMEN_UNMOUNTED, @ATTUMEN_MOUNTED);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(@ATTUMEN_UNMOUNTED, 0, 0, 'It was... inevitable.', 14, 0, 100, 0, 0, 9169, 13460, 0, 'attumen SAY_KILL1'),
(@ATTUMEN_UNMOUNTED, 0, 1, 'Another trophy to add to my collection!', 14, 0, 100, 0, 0, 9300, 15333, 0,'attumen SAY_KILL2'),
(@ATTUMEN_UNMOUNTED, 1, 0, 'Such easy sport.', 14, 0, 100, 0, 0, 9170, 0, 0,'attumen SAY_RANDOM1'),
(@ATTUMEN_UNMOUNTED, 1, 1, 'Amateurs! Do not think you can best me! I kill for a living.', 14, 0, 100, 0, 0, 9304, 0, 0, 'attumen SAY_RANDOM2'),
(@ATTUMEN_UNMOUNTED, 2, 0, 'Weapons are merely a convenience for a warrior of my skill!', 14, 0, 100, 0, 0, 9166, 13490, 0, 'attumen SAY_DISARMED'),
(@ATTUMEN_UNMOUNTED, 3, 0, 'Well done, Midnight!', 14, 0, 100, 0, 0, 9173, 15334, 0, 'attumen SAY_MIDNIGHT_KILL'),
(@ATTUMEN_UNMOUNTED, 4, 0, 'Cowards! Wretches!', 14, 0, 100, 0, 0, 9167, 13459, 0, 'attumen SAY_APPEAR1'),
(@ATTUMEN_UNMOUNTED, 4, 1, 'Who dares attack the steed of the Huntsman?', 14, 0, 100, 0, 0, 9298, 15378, 0, 'attumen SAY_APPEAR2'),
(@ATTUMEN_UNMOUNTED, 4, 2, 'Perhaps you would rather test yourselves against a more formidable opponent?!', 14, 0, 100, 0, 0, 9299, 15379, 0, 'attumen SAY_APPEAR3'),
(@ATTUMEN_UNMOUNTED, 5, 0, 'Come Midnight, let\'s disperse this petty rabble!', 14, 0, 100, 0, 0, 9168, 13456, 0, 'attumen SAY_MOUNT'),

(@ATTUMEN_MOUNTED, 0, 0, 'It was... inevitable.', 14, 0, 100, 0, 0, 9169, 13460, 0, 'attumen SAY_KILL1'),
(@ATTUMEN_MOUNTED, 0, 1, 'Another trophy to add to my collection!', 14, 0, 100, 0, 0, 9300, 15333, 0,'attumen SAY_KILL2'),
(@ATTUMEN_MOUNTED, 1, 0, 'Such easy sport.', 14, 0, 100, 0, 0, 9170, 0, 0,'attumen SAY_RANDOM1'),
(@ATTUMEN_MOUNTED, 1, 1, 'Amateurs! Do not think you can best me! I kill for a living.', 14, 0, 100, 0, 0, 9304, 0, 0, 'attumen SAY_RANDOM2'),
(@ATTUMEN_MOUNTED, 2, 0, 'Weapons are merely a convenience for a warrior of my skill!', 14, 0, 100, 0, 0, 9166, 13490, 0, 'attumen SAY_DISARMED'),
(@ATTUMEN_MOUNTED, 3, 0, 'Always knew... someday I would become... the hunted.', 14, 0, 100, 0, 0, 9165, 13462, 0, 'attumen SAY_DEATH'),

(@MIDNIGHT, 0, 0, '%s calls for her master!', 16, 0, 100, 0, 0, 0, 13439, 0, 'midnight EMOTE_CALL_ATTUMEN'),
(@MIDNIGHT, 1, 0, '%s rushes to her master\'s aid.', 16, 0, 100, 0, 0, 0, 13455, 0, 'midnight EMOTE_MOUNT_UP');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 29770;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 29770, 0, 0, 31, 0, 3, 15550, 0, 0, 0, 0, '', 'Mount spell only hit Attumen the Huntsmen');

DELETE FROM `creature_formations` WHERE `leaderGUID` = 135159;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@GMIDNIGHT, @GMIDNIGHT, 0, 0, 1, 0, 0),
(@GMIDNIGHT, 135828, 0, 0, 1, 0, 0),
(@GMIDNIGHT, 135836, 0, 0, 1, 0, 0),
(@GMIDNIGHT, 135829, 0, 0, 1, 0, 0),
(@GMIDNIGHT, 135839, 0, 0, 1, 0, 0),
(@GMIDNIGHT, 135833, 0, 0, 1, 0, 0),
(@GMIDNIGHT, 135840, 0, 0, 1, 0, 0),
(@GMIDNIGHT, 135834, 0, 0, 1, 0, 0),
(@GMIDNIGHT, 135830, 0, 0, 1, 0, 0),
(@GMIDNIGHT, 135841, 0, 0, 1, 0, 0),
(@GMIDNIGHT, 135842, 0, 0, 1, 0, 0),
(@GMIDNIGHT, 135831, 0, 0, 1, 0, 0),
(@GMIDNIGHT, 135837, 0, 0, 1, 0, 0),
(@GMIDNIGHT, 135838, 0, 0, 1, 0, 0),
(@GMIDNIGHT, 135832, 0, 0, 1, 0, 0), 
(@GMIDNIGHT, 135835, 0, 0, 1, 0, 0);

UPDATE `creature_template` SET `ScriptName` = 'boss_attumen', `lootid` = @ATTUMEN_MOUNTED WHERE `entry` = @ATTUMEN_MOUNTED;
UPDATE `creature_loot_template` SET `entry` = @ATTUMEN_MOUNTED WHERE `entry` = @ATTUMEN_UNMOUNTED;
