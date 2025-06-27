-- 
DELETE FROM `creature_addon`  WHERE `guid` IN (77155, 77163, 77166, 77168, 77169, 77143, 77144, 77145, 77147, 77150, 77151, 77152, 77153, 70850,70851,70852,70853,70854);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=35190;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition` ,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,35190,0,1,31,0,3,20431,0,0,0,'','Crystal Channel');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (22017) AND `source_type`=0 AND `id`=15;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (19796) AND `source_type`=0 AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(22017, 0, 15, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 35190, 0, 0, 0, 0, 0, 19, 20431, 20, 0, 0, 0, 0, 0, "Eclipsion Spellbinder - On reset - Cast Crystal Channel"),
(19796, 0, 3, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 35190, 0, 0, 0, 0, 0, 19, 20431, 20, 0, 0, 0, 0, 0, "Eclipsion Archmage - On reset - Cast Crystal Channel");

DELETE FROM `creature` WHERE `guid` IN (106327,106350);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(106327, 20431, 530, 0, 0, 1, 1, 0, 0, -4151.47, 1285.95, 66.784, 5.89921, 86400, 0, 0, 42, 0, 0, 0, 0, 0, 0),
(106350, 20431, 530, 0, 0, 1, 1, 0, 0, -4280.86, 1311.67, 66.6485, 0.733038, 86400, 0, 0, 42, 0, 0, 0, 0, 0, 0);
