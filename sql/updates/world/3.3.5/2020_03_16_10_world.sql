-- Tamed Battleboar will be summoned now instead of being prespawned
DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 4530);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4530, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, 11, 8274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Razorfen Handler - On Reset - Cast \'Summon Tamed Battleboar\''),
(4530, 0, 1, 0, 9, 0, 100, 0, 0, 30, 2300, 3900, 0, 11, 6660, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Razorfen Handler - Within 0-30 Range - Cast \'Shoot\''),
(4530, 0, 2, 0, 2, 0, 100, 1, 0, 15, 0, 0, 0, 25, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Razorfen Handler - Between 0-15% Health - Flee For Assist (No Repeat)');

-- SAI correction for Razorfen Beast Trainer 4531
-- Tamed Battleboar will be summoned now instead of being prespawned
DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 4531);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4531, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, 11, 8274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Razorfen Beast Trainer - On Reset - Cast \'Summon Tamed Battleboar\''),
(4531, 0, 1, 0, 0, 0, 100, 0, 0, 30, 2300, 3900, 0, 11, 6660, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Razorfen Beast Trainer - Within 0-30 Range - Cast \'Shoot\''),
(4531, 0, 2, 0, 0, 0, 100, 0, 0, 30, 4000, 6000, 0, 11, 6984, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Razorfen Beast Trainer - Within 0-30 Range - Cast \'Frost Shot\'');

-- deleting their prespawned battleboars
DELETE FROM `creature` WHERE `guid` IN (87295,87308,87298,87369,87376) AND `id`=4535;
