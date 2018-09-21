--
UPDATE quest_template_addon SET NextQuestID = 11978 WHERE ID = 11979;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (19, 20) AND `SourceEntry` IN (11606, 11611);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19, 0, 11606, 0, 0, 8, 0, 11595, 0, 0, 0, 0, 0, "", "Quest 'Patience is a Virtue that We Don't Need' requires quest 'The Defense of Warsong Hold' rewarded OR"),
(19, 0, 11606, 0, 1, 8, 0, 11596, 0, 0, 0, 0, 0, "", "Quest 'Patience is a Virtue that We Don't Need' requires quest 'The Defense of Warsong Hold' rewarded OR"),
(19, 0, 11606, 0, 2, 8, 0, 11597, 0, 0, 0, 0, 0, "", "Quest 'Patience is a Virtue that We Don't Need' requires quest 'The Defense of Warsong Hold' rewarded"),
(19, 0, 11611, 0, 0, 8, 0, 11595, 0, 0, 0, 0, 0, "", "Quest 'Taken by the Scourge' requires quest 'The Defense of Warsong Hold' rewarded OR"),
(19, 0, 11611, 0, 1, 8, 0, 11596, 0, 0, 0, 0, 0, "", "Quest 'Taken by the Scourge' requires quest 'The Defense of Warsong Hold' rewarded OR"),
(19, 0, 11611, 0, 2, 8, 0, 11597, 0, 0, 0, 0, 0, "", "Quest 'Taken by the Scourge' requires quest 'The Defense of Warsong Hold' rewarded"),

(20, 0, 11606, 0, 0, 8, 0, 11595, 0, 0, 0, 0, 0, "", "Quest mark for 'Patience is a Virtue that We Don't Need' requires quest 'The Defense of Warsong Hold' rewarded OR"),
(20, 0, 11606, 0, 1, 8, 0, 11596, 0, 0, 0, 0, 0, "", "Quest mark for 'Patience is a Virtue that We Don't Need' requires quest 'The Defense of Warsong Hold' rewarded OR"),
(20, 0, 11606, 0, 2, 8, 0, 11597, 0, 0, 0, 0, 0, "", "Quest mark for 'Patience is a Virtue that We Don't Need' requires quest 'The Defense of Warsong Hold' rewarded"),
(20, 0, 11611, 0, 0, 8, 0, 11595, 0, 0, 0, 0, 0, "", "Quest mark for 'Taken by the Scourge' requires quest 'The Defense of Warsong Hold' rewarded OR"),
(20, 0, 11611, 0, 1, 8, 0, 11596, 0, 0, 0, 0, 0, "", "Quest mark for 'Taken by the Scourge' requires quest 'The Defense of Warsong Hold' rewarded OR"),
(20, 0, 11611, 0, 2, 8, 0, 11597, 0, 0, 0, 0, 0, "", "Quest mark for 'Taken by the Scourge' requires quest 'The Defense of Warsong Hold' rewarded");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (19, 20) AND `SourceEntry` IN (11595, 11596, 11597);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19, 0, 11595, 0, 0, 8, 0, 11585, 0, 0, 0, 0, 0, "", "Quest 'The Defense of Warsong Hold' requires quest 'Hellscream's Vigil' rewarded OR"),
(19, 0, 11595, 0, 0, 8, 0, 7784, 0, 0, 0, 0, 0, "", "Quest 'The Defense of Warsong Hold' requires quest 'The Lord of Blackrock' rewarded OR"),
(19, 0, 11595, 0, 1, 8, 0, 11586, 0, 0, 0, 0, 0, "", "Quest 'The Defense of Warsong Hold' requires quest 'Hellscream's Vigil' rewarded"),
(19, 0, 11595, 0, 1, 8, 0, 7784, 0, 0, 0, 0, 0, "", "Quest 'The Defense of Warsong Hold' requires quest 'The Lord of Blackrock' rewarded"),

(19, 0, 11596, 0, 0, 8, 0, 7784, 0, 0, 1, 0, 0, "", "Quest 'The Defense of Warsong Hold' requires quest 'The Lord of Blackrock' NOT rewarded OR"),
(19, 0, 11596, 0, 0, 8, 0, 8743, 0, 0, 1, 0, 0, "", "Quest 'The Defense of Warsong Hold' requires quest 'Bang a Gong' NOT rewarded OR"),
(19, 0, 11596, 0, 0, 8, 0, 11585, 0, 0, 0, 0, 0, "", "Quest 'The Defense of Warsong Hold' requires quest 'Hellscream's Vigil' rewarded OR"),
(19, 0, 11596, 0, 1, 8, 0, 7784, 0, 0, 1, 0, 0, "", "Quest 'The Defense of Warsong Hold' requires quest 'The Lord of Blackrock' NOT rewarded"),
(19, 0, 11596, 0, 1, 8, 0, 8743, 0, 0, 1, 0, 0, "", "Quest 'The Defense of Warsong Hold' requires quest 'Bang a Gong' NOT rewarded"),
(19, 0, 11596, 0, 1, 8, 0, 11586, 0, 0, 0, 0, 0, "", "Quest 'The Defense of Warsong Hold' requires quest 'Hellscream's Vigil' rewarded"),

(19, 0, 11597, 0, 0, 8, 0, 8743, 0, 0, 0, 0, 0, "", "Quest 'The Defense of Warsong Hold' requires quest 'Bang a Gong' rewarded OR"),
(19, 0, 11597, 0, 0, 8, 0, 11585, 0, 0, 0, 0, 0, "", "Quest 'The Defense of Warsong Hold' requires quest 'Hellscream's Vigil' rewarded OR"),
(19, 0, 11597, 0, 1, 8, 0, 8743, 0, 0, 0, 0, 0, "", "Quest 'The Defense of Warsong Hold' requires quest 'Bang a Gong' rewarded"),
(19, 0, 11597, 0, 1, 8, 0, 11586, 0, 0, 0, 0, 0, "", "Quest 'The Defense of Warsong Hold' requires quest 'Hellscream's Vigil' rewarded OR"),


(20, 0, 11595, 0, 0, 8, 0, 11585, 0, 0, 0, 0, 0, "", "Quest mark for 'The Defense of Warsong Hold' requires quest 'Hellscream's Vigil' rewarded OR"),
(20, 0, 11595, 0, 0, 8, 0, 7784, 0, 0, 0, 0, 0, "", "Quest mark for 'The Defense of Warsong Hold' requires quest 'The Lord of Blackrock' rewarded OR"),
(20, 0, 11595, 0, 1, 8, 0, 11586, 0, 0, 0, 0, 0, "", "Quest mark for 'The Defense of Warsong Hold' requires quest 'Hellscream's Vigil' rewarded"),
(20, 0, 11595, 0, 1, 8, 0, 7784, 0, 0, 0, 0, 0, "", "Quest mark for 'The Defense of Warsong Hold' requires quest 'The Lord of Blackrock' rewarded"),

(20, 0, 11596, 0, 0, 8, 0, 7784, 0, 0, 1, 0, 0, "", "Quest mark for 'The Defense of Warsong Hold' requires quest 'The Lord of Blackrock' NOT rewarded OR"),
(20, 0, 11596, 0, 0, 8, 0, 8743, 0, 0, 1, 0, 0, "", "Quest mark for 'The Defense of Warsong Hold' requires quest 'Bang a Gong' NOT rewarded OR"),
(20, 0, 11596, 0, 0, 8, 0, 11585, 0, 0, 0, 0, 0, "", "Quest mark for 'The Defense of Warsong Hold' requires quest 'Hellscream's Vigil' rewarded OR"),
(20, 0, 11596, 0, 1, 8, 0, 7784, 0, 0, 1, 0, 0, "", "Quest mark for 'The Defense of Warsong Hold' requires quest 'The Lord of Blackrock' NOT rewarded"),
(20, 0, 11596, 0, 1, 8, 0, 8743, 0, 0, 1, 0, 0, "", "Quest mark for 'The Defense of Warsong Hold' requires quest 'Bang a Gong' NOT rewarded"),
(20, 0, 11596, 0, 1, 8, 0, 11586, 0, 0, 0, 0, 0, "", "Quest mark for 'The Defense of Warsong Hold' requires quest 'Hellscream's Vigil' rewarded"),

(20, 0, 11597, 0, 0, 8, 0, 8743, 0, 0, 0, 0, 0, "", "Quest mark for 'The Defense of Warsong Hold' requires quest 'Bang a Gong' rewarded OR"),
(20, 0, 11597, 0, 0, 8, 0, 11585, 0, 0, 0, 0, 0, "", "Quest mark for 'The Defense of Warsong Hold' requires quest 'Hellscream's Vigil' rewarded OR"),
(20, 0, 11597, 0, 1, 8, 0, 8743, 0, 0, 0, 0, 0, "", "Quest mark for 'The Defense of Warsong Hold' requires quest 'Bang a Gong' rewarded"),
(20, 0, 11597, 0, 1, 8, 0, 11586, 0, 0, 0, 0, 0, "", "Quest mark for 'The Defense of Warsong Hold' requires quest 'Hellscream's Vigil' rewarded");
