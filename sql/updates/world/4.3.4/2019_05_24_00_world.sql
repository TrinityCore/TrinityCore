-- Phase Schnottz''s Landing

DELETE FROM `phase_area` WHERE `AreaId`=5602;
INSERT INTO `phase_area` (`AreaId`,`PhaseId`,`Comment`) VALUES
(5602,313, 'Schnottz''s Landing phase up to quest 27950 rewarded'),
(5602,312, 'Schnottz''s Landing phase while quest 27950 taken'),
(5602,315, 'Schnottz''s Landing phase after quest 27950 rewarded'),
(5602,324, 'Schnottz''s Landing phase after quest 28002 rewarded'),
(5602,325, 'Schnottz''s Landing phase after quest 27990 Completed');

-- Condition for source Phase condition type Quest not taken
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=313 AND `SourceEntry`=5602 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 313, 5602, 0, 1, 8, 0, 27950, 0, 0, 1, 0, 0, '', 'Set Phase to 313 for area 5602 if quest Gobbles! has not been rewarded.'),
(26, 313, 5602, 0, 1, 1, 0, 88111, 0, 0, 1, 0, 0, '', 'Set Phase to 313 for area 5602 if player does not hav aura Phase Player.');

-- Condition for source Phase condition type Quest not taken
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=312 AND `SourceEntry`=5602 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 312, 5602, 0, 0, 1, 0, 88111, 0, 0, 0, 0, 0, '', 'Set Phase to 312 for area 5602 if player has aura Phase Player.');

-- Condition for source Phase condition type Quest rewarded
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=315 AND `SourceEntry`=5602 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 315, 5602, 0, 1, 8, 0, 27950, 0, 0, 0, 0, 0, '', 'Set Phase to 315 for area 5602 if quest Gobbles! has been rewarded.'),
(26, 315, 5602, 0, 1, 8, 0, 28002, 0, 0, 1, 0, 0, '', 'Set Phase to 315 for area 5602 if quest Crisis Management has not been rewarded.');

-- Condition for source Phase condition type Quest rewarded
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=324 AND `SourceEntry`=5602 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 324, 5602, 0, 0, 8, 0, 28002, 0, 0, 0, 0, 0, '', 'Set Phase to 324 for area 5602 if quest Crisis Management has been rewarded.');

-- Phase Schnottz''s Hostel

DELETE FROM `phase_area` WHERE `AreaId`=5700;
INSERT INTO `phase_area` (`AreaId`,`PhaseId`,`Comment`) VALUES
(5700,313, 'Schnottz''s Hostel phase up to quest 27950 rewarded'),
(5700,315, 'Schnottz''s Hostel phase after quest 27950 rewarded'),
(5700,324, 'Schnottz''s Hostel phase after quest 28002 rewarded');

-- Condition for source Phase condition type Quest not taken
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=313 AND `SourceEntry`=5700 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 313, 5700, 0, 1, 8, 0, 27950, 0, 0, 1, 0, 0, '', 'Set Phase to 313 for area 5700 if quest Gobbles! has not been rewarded.'),
(26, 313, 5700, 0, 1, 1, 0, 88111, 0, 0, 1, 0, 0, '', 'Set Phase to 313 for area 5700 if player does not hav aura Phase Player.');

-- Condition for source Phase condition type Quest rewarded
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=315 AND `SourceEntry`=5700 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 315, 5700, 0, 1, 8, 0, 27950, 0, 0, 0, 0, 0, '', 'Set Phase to 315 for area 5700 if quest Gobbles! has been rewarded.'),
(26, 315, 5700, 0, 1, 8, 0, 28002, 0, 0, 1, 0, 0, '', 'Set Phase to 315 for area 5700 if quest Crisis Management has not been rewarded.');

-- Condition for source Phase condition type Quest rewarded
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=324 AND `SourceEntry`=5700 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 324, 5700, 0, 0, 8, 0, 28002, 0, 0, 0, 0, 0, '', 'Set Phase to 324 for area 5700 if quest Crisis Management has been rewarded.');

-- Fix some creature phasing

-- Fix phasing for Commander Schnottz, Schnottz's Bodyguard, Belloc Brightblade, Arcane Guest Registry
UPDATE `creature` SET `PhaseId`=0,`PhaseGroup`=532 WHERE `id` IN (47159,47191,47193,47670,47982,48273,48959,49525,49528,47732,47452,47455,47772);
UPDATE `creature` SET `PhaseId`=0,`PhaseGroup`=528 WHERE `id` IN (47546);
UPDATE `creature` SET `PhaseId`=313 WHERE `id` IN (47291);
UPDATE `creature` SET `PhaseId`=313 WHERE `guid` IN (266594,266598,266601,266604,266606,266607,266612,387450);
UPDATE `gameobject` SET `PhaseId`=0,`PhaseGroup`=532 WHERE `guid` IN (206301);
UPDATE `creature_template` SET `flags_extra`=2 WHERE `entry`=47546;

-- Add missing gameobject
DELETE FROM `gameobject` WHERE `guid`=200889;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`phaseMask`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`,`ScriptName`,`VerifiedBuild`) VALUES
(200889,205384,1,0,0,1,0,1,0,532,-1,-10723.6,817.3871,1.11733,3.141593,0,0,-1,0,120,255,1, '', 0);
