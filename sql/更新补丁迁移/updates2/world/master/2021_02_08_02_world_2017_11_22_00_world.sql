-- 
UPDATE `gameobject_template` SET `AIName`="" WHERE `entry` IN (113768, 113769, 113770, 113771, 113772);
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (32784);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (113768, 113769, 113770, 113771, 113772) AND `source_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (32784) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(32784, 0, 0, 0, 54, 0, 20, 0, 0, 0, 0, 0, 85, 61734, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Noblegarden Bunny Controller - On Just summoned - Invoker Cast 'Noblegarden Bunny'");
