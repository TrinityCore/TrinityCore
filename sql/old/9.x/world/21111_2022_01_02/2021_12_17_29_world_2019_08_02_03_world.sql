-- 
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry`=27467;
UPDATE `smart_scripts` SET `link`=7 WHERE `entryorguid` IN (27409) AND `source_type`=0 AND `id`=6;
UPDATE `smart_scripts` SET `event_type`=60, `event_param1`=60000, `event_param2`=60000, `event_param3`=60000, `event_param4`=60000, `comment`="Silverbrook Worgen - On update - Despawn" WHERE `entryorguid` IN (27417) AND `source_type`=0 AND `id`=2;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (27409) AND `source_type`=0 AND `id` IN (7,13,14,15,16);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (27467) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (27417) AND `source_type`=0 AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(27409, 0, 7, 13, 61, 0, 100, 512, 0, 0, 0, 0, 41, 5000, 0, 0, 0, 0, 0, 19, 27411, 0, 0, 0, 0, 0, 0, "Ducal's Horse - On Waypoint 103 Reached - Despawn In 5000 ms"),
(27409, 0, 13, 14, 61, 0, 100, 512, 0, 0, 0, 0, 12, 27467, 4, 20000, 0, 0, 0, 8, 0, 0, 0, 3437.23, -2795.77, 201.527, 5.81195, "Ducal's Horse - On Waypoint 103 Reached - Summon creature"),
(27409, 0, 14, 15, 61, 0, 100, 512, 0, 0, 0, 0, 12, 27467, 4, 20000, 0, 0, 0, 8, 0, 0, 0, 3446.18, -2787.37, 201.793, 4.88692, "Ducal's Horse - On Waypoint 103 Reached - Summon creature"),
(27409, 0, 15, 16, 61, 0, 100, 512, 0, 0, 0, 0, 11, 48681, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Ducal's Horse - On Waypoint 103 Reached - cast Summon Silverbrook Worgen"),
(27409, 0, 16, 0, 61, 0, 100, 512, 0, 0, 0, 0, 11, 48681, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Ducal's Horse - On Waypoint 103 Reached - cast Summon Silverbrook Worgen"),
(27467, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 3, 0, 0, 19, 27409, 0, 0, 0, 0, 0, 0, "Amberpine Hunter - On Just summoned - Move to target"),
(27417, 0, 3, 0, 54, 0, 100, 0, 0, 0, 0, 0, 117, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Silverbrook Worgen - On Just summoned - Disable evade");
DELETE FROM `creature_template_addon` WHERE `entry` IN (27467);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `emote`, `bytes1`, `bytes2`, `auras`) VALUES
(27467,0,376,0,2,"");
