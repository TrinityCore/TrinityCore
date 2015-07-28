DELETE FROM `creature_text` WHERE `entry`=26527;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextId`) VALUES
(26527, 0, 0, 'Oh, no! Adventurers, something awful has happened! A colleague of mine has been captured by the Infinite Dragonflight, and they''re doing something horrible to him! Keeping Arthas is still your highest priority, but if you act fast you could help save a Guardian of Time!', 15, 0, 100, 0, 0, 0, 'Chromie', 32670),
(26527, 1, 0, 'Adventurers, you must hurry! The Guardian of Time cannot last for much longer!', 15, 0, 100, 0, 0, 0, 'Chromie', 32678),
(26527, 2, 0, 'I can barely sense the Guardian of Time! His timeline is fading quickly!', 15, 0, 100, 0, 0, 0, 'Chromie', 32679);

DELETE FROM `conditions` WHERE `SourceEntry`=60422;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `Comment`) VALUES
(13, 1, 60422, 0, 0, 31, 1, 3, 32281, 0, 0, 0, 0, 'Corruption of Time (60422) can hit only Guardian of Time');
