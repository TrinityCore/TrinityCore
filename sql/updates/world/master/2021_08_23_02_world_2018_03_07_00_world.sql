-- Veil Skith: Darkstone of Terokk
UPDATE `creature` SET `MovementType`=0, `spawndist`=0 WHERE `guid`=65930;
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry` IN (22288);
DELETE FROM `disables` WHERE `sourceType`=0 AND `entry` IN (38729,38736);
UPDATE `conditions` SET `SourceGroup`=1 WHERE `SourceEntry` IN (38729) AND `SourceTypeOrReferenceId`=13 AND `ConditionValue2`=185191;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (38729) AND `ConditionValue2`=22288;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (38736) AND `ConditionValue1`=185191;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,4,38729,0,0, 31,0,3,22288,0,0,0,'',''),
(13,1,38736,0,0, 30,0,185191,15,0,0,0,'','');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=22288;
DELETE FROM `smart_scripts` WHERE (`entryorguid`=22288 AND `source_type`=0);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(22288, 0, 0, 0, 8, 0, 100, 0, 38729, 0, 5000, 5000, 41, 0, 30, 0, 0, 0, 0, 20, 185191, 5, 0, 0, 0, 0, 0, "Terokk target - on spellhit - despawn gob");
