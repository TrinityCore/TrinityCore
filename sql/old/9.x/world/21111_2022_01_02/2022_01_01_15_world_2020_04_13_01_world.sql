-- 
UPDATE `creature_template` SET `DamageModifier`=3 WHERE `entry` IN (32352,27900);
DELETE FROM `smart_scripts` WHERE `entryorguid` = 32331 AND `source_type`=0 AND `id` IN (15,16);
DELETE FROM `smart_scripts` WHERE `entryorguid` = 27899 AND `source_type`=0 AND `id` IN (26,27);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(27899, 0, 26, 27, 25, 0, 100, 0, 0, 0, 0, 0, 85, 49889, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, "Future You - On reset - Cross Cast 'Mystery of the Infinite: Future You's Mirror Image Aura' (No Repeat)"),
(27899, 0, 27, 0, 61, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, "Past You - On reset - Set Orientation"),
(32331, 0, 15, 16, 25, 0, 100, 0, 0, 0, 0, 0, 85, 49889, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, "Past You - On reset - Cross Cast 'Mystery of the Infinite: Future You's Mirror Image Aura' (No Repeat)"),
(32331, 0, 16, 0, 61, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, "Past You - On reset - Set Orientation");
