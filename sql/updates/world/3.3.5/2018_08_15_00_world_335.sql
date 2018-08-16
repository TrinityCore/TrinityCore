-- 
DELETE FROM `gameobject` WHERE `guid` IN (5111,5117,5122,5126,5131,5140,5144,5155);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(5111, 180867, 1, 7603.94, -2211.17, 471.606, 3.78647, 0, 0, 0.948466, -0.316878, 25, 100, 1),
(5117, 180867, 1, 7575.26, -2238.68, 469.858, 1.03679, 0, 0, 0.495486, 0.868616, 25, 100, 1),
(5122, 180867, 1, 7595.67, -2246.32, 466.965, 1.30382, 0, 0, 0.606707, 0.794925, 25, 100, 1),
(5126, 180867, 1, 7610.97, -2228.92, 468.71, 2.96651, 0, 0, 0.996171, 0.0874282, 25, 100, 1),
(5131, 180867, 1, 7570.31, -2220.8, 473.445, 0.357419, 0, 0, 0.17776, 0.984074, 25, 100, 1),
(5140, 180867, 1, 7585.47, -2205.31, 475.281, 4.91744, 0, 0, 0.631024, -0.775763, 25, 100, 1),
(5144, 180867, 530, -1804.2651, 5492.6840, -12.4278, 5.101903, 0, 0, 0.631024, -0.775763, 25, 100, 1),
(5155, 180867, 530, -1778.0809, 5439.7109, -12.4276, 1.531083, 0, 0, 0.631024, -0.775763, 25, 100, 1);

-- Added target position to each teleport spell in Lunar Festival
DELETE FROM `spell_target_position` WHERE `id` IN (26454, 26452, 26450, 26453, 26456, 26455);
INSERT INTO `spell_target_position` (`ID`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `VerifiedBuild`) VALUES
(26454, 0, -8748.48, 1073.61, 90.4898, 5.03789, 0),  -- To Stormwind
(26452, 0, -4663, -955.663, 500.377, 0.722862, 0),  -- To Ironforge
(26450, 1, 10150.1, 2602, 1330.83, 4.80894, 0),  -- To Darnassus
(26453, 1, 1982.9, -4255.62, 31.6692, 3.31984, 0),  -- To Orgrimmar
(26456, 0, 1642.01, 239.002, 62.5918, 3.02316, 0),  -- To Undercity
(26455, 1, -1031.45, -230.867, 160.14, 3.28358, 0);  -- To Thunderbluff

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=26373 AND `spell_effect`=26448;
DELETE FROM `conditions` WHERE `SourceEntry`=26373 AND `SourceTypeOrReferenceId`=13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 2, 26373, 0, 0, 31, 0, 4, 0, 0, 0, 0, '', 'Lunar Invitation visual on player');

-- Lunar Festival spell focus for teleportaion
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`=180867;
DELETE FROM  `smart_scripts` WHERE `entryorguid` = 180867 AND source_type=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(180867,1,0,0,8,0,100,0,26373,0,1000,1000,85,26448,0,0,0,0,0,7,0,0,0,0,0,0,0,"Lunar Festival - On spell hit  - Cast self teleportation Moonglade"),
(180867,1,1,0,8,0,100,0,26373,0,1000,1000,85,26454,0,0,0,0,0,7,0,0,0,0,0,0,0,"Lunar Festival - On spell hit  - Cast self teleportation Stormwind"),
(180867,1,2,0,8,0,100,0,26373,0,1000,1000,85,26452,0,0,0,0,0,7,0,0,0,0,0,0,0,"Lunar Festival - On spell hit  - Cast self teleportation Ironforge"),
(180867,1,3,0,8,0,100,0,26373,0,1000,1000,85,26450,0,0,0,0,0,7,0,0,0,0,0,0,0,"Lunar Festival - On spell hit  - Cast self teleportation Darnassus"),
(180867,1,4,0,8,0,100,0,26373,0,1000,1000,85,26453,0,0,0,0,0,7,0,0,0,0,0,0,0,"Lunar Festival - On spell hit  - Cast self teleportation Orgrimmar"),
(180867,1,5,0,8,0,100,0,26373,0,1000,1000,85,26456,0,0,0,0,0,7,0,0,0,0,0,0,0,"Lunar Festival - On spell hit  - Cast self teleportation Undercity"),
(180867,1,6,0,8,0,100,0,26373,0,1000,1000,85,26455,0,0,0,0,0,7,0,0,0,0,0,0,0,"Lunar Festival - On spell hit  - Cast self teleportation Thunderbluff");

-- Lunar Festival spell focus for teleportaion
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=180867;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,180867,1,0,29,0,15892,5,0,0,0,'','Lunar Festival Execute sai if near npc 15892'),
(22,1,180867,1,0,6,0,469,0,0,0,0,'','Lunar Festival sai the player Must Be Alliance'),
(22,1,180867,1,1,29,0,15891,5,0,0,0,'','Lunar Festival Execute sai if near npc 15891'),
(22,1,180867,1,1,6,0,67,0,0,0,0,'','Lunar Festival sai the player Must Must Be Horde'),
(22,1,180867,1,2,29,0,15892,5,0,0,0,'','Lunar Festival Execute sai if near npc 15892'),
(22,1,180867,1,2,22,0,571,0,0,0,0,'','Lunar Festival Execute sai if on map 571'),
(22,2,180867,1,0,29,0,15694,5,0,0,0,'','Lunar Festival Execute sai if near npc 15694'),
(22,2,180867,1,0,6,0,469,0,0,0,0,'','Lunar Festival SAI the player Must Be Alliance'),
(22,3,180867,1,0,29,0,15906,5,0,0,0,'','Lunar FestivalExecute sai if near npc 15906'),
(22,3,180867,1,0,6,0,469,0,0,0,0,'','Lunar Festival SAI the player Must Be Alliance'),
(22,4,180867,1,0,29,0,15905,5,0,0,0,'','Lunar Festival Execute sai if near npc 15905'),
(22,4,180867,1,0,6,0,469,0,0,0,0,'','Lunar Festival SAI the player Must Be Alliance'),
(22,5,180867,1,0,29,0,15908,5,0,0,0,'','Lunar Festival Execute sai if near npc 15908'),
(22,5,180867,1,0,6,0,67,0,0,0,0,'','Lunar Festival SAI the player Must Must Be Horde'),
(22,6,180867,1,0,29,0,15907,5,0,0,0,'','Lunar Festival Execute sai if near npc 15907'),
(22,6,180867,1,0,6,0,67,0,0,0,0,'','Lunar Festival SAI the player Must Must Be Horde'),
(22,7,180867,1,0,29,0,15719,5,0,0,0,'','Lunar Festival Execute sai if near npc 15719'),
(22,7,180867,1,0,6,0,67,0,0,0,0,'','Lunar Festival SAI the player Must Must Be Horde');
