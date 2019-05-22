-- 
UPDATE `spell_target_position` SET `positionX`=-1350.881714, `positionY`=-2739.897705, `positionZ`=61.57 WHERE `id`=9055;
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry` IN (103661,174764);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (103661,174764) AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(174764, 1, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Witherbark Totem Bundle - Just created - activate"),
(103661, 1, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Witherbark Totem Bundle TRAP - Just created - activate"),
(103661, 1, 1, 2, 60, 0, 100, 1, 10000, 10000, 0, 0, 85, 9056, 0, 0, 0, 0, 0, 19, 15214, 5, 0, 0, 0, 0, 0, "Witherbark Totem Bundle TRAP - On update - cast spell"),
(103661, 1, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 20, 174764, 0, 0, 0, 0, 0, 0, "Witherbark Totem Bundle TRAP - On link - Despawn");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 17 AND `SourceEntry` = 9055;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`, `NegativeCondition`) VALUES
(17, 0, 9055, 0, 30, 0, 174764, 30, 0, 0, '', "Create Witherbark Totem Bundle", 1),
(17, 0, 9055, 0, 30, 0, 103662, 30, 0, 0, '', "Create Witherbark Totem Bundle", 1);

DELETE FROM `creature` WHERE `guid` IN (105530)  AND `id`=15214;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(105530, 15214, 0, 0, 0, 1, 1, 0, 0, -1350.881714, -2739.897705, 61.57, 1.65806, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0);
