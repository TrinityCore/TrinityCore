-- Small fix to pathing for Harrison Jones
UPDATE `waypoint_data` SET `position_y`=1642.853 WHERE `id`=861770 AND `point`=1;

-- Text for Amani'shi Guardian from sniff
DELETE FROM `creature_text` WHERE `entry` IN (23597);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(23597,0,0, 'More intruders! Sound da alarm!',14,0,100,25,0,12104, 'Amani''shi Guardian - Gong Event Say');

-- Spell condition for Cosmetic - Spear Throw
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=43647;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,43647,0,0,31,0,3,24358,0,0,0,0, '', 'Cosmetic - Spear Throw - Harrison Jones');
