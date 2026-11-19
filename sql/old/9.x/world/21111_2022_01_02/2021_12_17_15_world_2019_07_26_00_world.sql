-- 
DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (26890,26892,26677);
INSERT INTO `creature_template_movement` (`CreatureId`,`Ground`,`Swim`,`Flight`,`Rooted`) VALUES
(26890, 0, 0, 1, 0),
(26892, 0, 0, 1, 0),
(26677, 0, 0, 1, 0);

UPDATE `creature` SET `MovementType` = 0, `spawndist`=0, `spawntimesecs`=4 WHERE `id`=26677;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` IN (26661,26890,26677);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (26661,26890,26677) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2666100,2666101) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(26661, 0, 0, 0, 20, 0, 100, 0, 12047, 30000, 30000, 0, 80, 2666100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zivlix - On quest reward - Action list'),
(2666100, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 26677, 20, 0, 0, 0, 0, 0, 'Zivlix - Action list - Set orientation'),
(2666100, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 5, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zivlix - Action list - play emote'),
(2666100, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 45, 0, 1, 0, 0, 0, 0, 19, 26677, 20, 0, 0, 0, 0, 0, 'Zivlix - Action list - Set Data'),
(2666100, 9, 3, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zivlix - Action list - Say text'),
(2666100, 9, 4, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zivlix - Action list - Say text'),
(2666100, 9, 5, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 69, 1, 0, 0, 0, 0, 0, 8, 0, 0, 0, 4723.84814, 545.35998, 130.311737, 0.416793, 'Zivlix - Action list - Say text'),
(26661, 0, 1, 0, 34, 0, 100, 0, 8, 1, 0, 0, 80, 2666101, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zivlix - On wp reached - Action list'),
(2666101, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0.416793, 'Zivlix - Action list - Set orientation'),
(2666101, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zivlix - Action list - Say text'),
(2666101, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 26890, 3, 16000, 0, 0, 0, 8, 0, 0, 0, 4770.54, 592.455, 150.594, 3.76145, 'Zivlix - Action list - Summon creature'),
(2666101, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 26892, 3, 16000, 0, 0, 0, 8, 0, 0, 0, 4774.345703, 588.58892, 150.593, 3.76145, 'Zivlix - Action list - Summon creature'),
(2666101, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 26892, 3, 16000, 0, 0, 0, 8, 0, 0, 0, 4767.283691, 595.76239, 150.593, 3.76145, 'Zivlix - Action list - Summon creature'),
(2666101, 9, 5, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zivlix - Action list - Say text'),
(2666101, 9, 6, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zivlix - Action list - Evade'),
(2666101, 9, 7, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zivlix - Action list - Say text'),
(26677, 0, 0, 1, 38, 0, 100, 0, 0, 1, 0, 0, 53, 0, 26677, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zivlixs Destruction Machine - On data set - Start waypoint'),
(26677, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 48, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zivlixs Destruction Machine - On data set - Set active'),
(26677, 0, 2, 0, 40, 0, 100, 0, 15, 26677, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zivlixs Destruction Machine - On wp reached - despawn'),
(26890, 0, 0, 0, 1, 0, 100, 1, 6000, 6000, 0, 0, 11, 47328, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mistress of the Coldwind - Ooc - cast Direct Hit!'),
(26890, 0, 1, 0, 1, 0, 100, 1, 12000, 12000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mistress of the Coldwind - Ooc - Say text');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=47328;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 3, 47328, 0, 0, 31, 0, 3, 26677, 0, 0, 0, 0, '', "Direct Hit!");

DELETE FROM `creature_text` WHERE `CreatureId` IN (26661,26890);
INSERT INTO `creature_text` (`CreatureId`, `GroupId`, `ID`, `Text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextId`) VALUES 
(26661, 0, 0, "The control components are working perfectly this time!", 12, 0, 100, 0, 0, 0, 'Zivlix', 25924),
(26661, 1, 0, "Who to test the bomb on? The Harpies? Ha ha... wait... what's that?", 12, 0, 100, 6, 0, 0, 'Zivlix', 25925),
(26890, 0, 0, "You are not welcome in our home. Leave and go find some other land to pillage!", 14, 0, 100, 0, 0, 0, 'Mistress of the Coldwind', 25922),
(26661, 2, 0, "NO! My machine... my bombs! THAT'S IT! Those Harpies are going DOWN!", 12, 0, 100, 5, 0, 0, 'Zivlix', 25926),
(26661, 3, 0, "Talk to Narf. Lets take care of those bird-brains once and for all.", 12, 0, 100, 5, 0, 0, 'Zivlix', 26078);

DELETE FROM `waypoints` WHERE `entry` IN (26677);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(26677,1,4697.046, 567.007 , 124.5144, 'Zivlixs Destruction Machine'),
(26677,2,4664.82 , 589.2839, 126.2644, 'Zivlixs Destruction Machine'),
(26677,3,4667.397, 615.4627, 127.2089, 'Zivlixs Destruction Machine'),
(26677,4,4699.403, 623.2688, 130.9311, 'Zivlixs Destruction Machine'),
(26677,5,4729.83 , 593.533 , 130.2292, 'Zivlixs Destruction Machine'),
(26677,6,4736.569, 546.0275, 135.1181, 'Zivlixs Destruction Machine'),
(26677,7,4729.252, 502.6678, 133.4237, 'Zivlixs Destruction Machine'),
(26677,8,4752.534, 475.1504, 137.7292, 'Zivlixs Destruction Machine'),
(26677,9,4785.31 , 485.7249, 144.8403, 'Zivlixs Destruction Machine'),
(26677,10,4788.394, 514.8828, 139.3682, 'Zivlixs Destruction Machine'),
(26677,11,4773.589, 557.9219, 143.4515, 'Zivlixs Destruction Machine'),
(26677,12,4751.125, 580.1249, 144.9238, 'Zivlixs Destruction Machine'),
(26677,13,4734.583, 613.5748, 163.5244, 'Zivlixs Destruction Machine'),
(26677,14,4730.062, 667.8398, 143.5737, 'Zivlixs Destruction Machine'),
(26677,15,4754.887, 685.1636, 123.7125, 'Zivlixs Destruction Machine');
