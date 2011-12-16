-- Sleeping Giants fix by nelegalno
-- Closes https://github.com/TrinityCore/TrinityCore/issues/4243

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 24669;
DELETE FROM `smart_scripts` WHERE (`entryorguid`=24669 AND `source_type`=0);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`,
`event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24669, 0, 0, 1, 8, 0, 100, 0, 44261, 1, 0, 0, 33, 24669, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Dormant Vrykul - Sleeping Giants quest credit'),
(24669, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 37, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dormant Vrykul - Sleeping Giants despawn');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=17 AND (`SourceEntry`=50165 OR `SourceEntry`=44261));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 50165, 0, 19, 24669, 0, 0, 63, '', 'Awakening Rod target limit to Dormant Vrykul'),
(17, 0, 44261, 0, 19, 24669, 0, 0, 63, '', 'Awakening Rod aura target limit to Dormant Vrykul');