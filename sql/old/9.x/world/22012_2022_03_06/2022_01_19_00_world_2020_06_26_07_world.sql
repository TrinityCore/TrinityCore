--
UPDATE `creature` SET `modelid` = 0 WHERE `modelid`=11686; 
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|128 WHERE entry IN (30090,17459,23398);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-119105) AND `source_type`=0 AND `id`=4;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-119104) AND `source_type`=0 AND `id`=6;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(-119104, 0, 6, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, 3, 0, 11686, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mistwhisper Lightning Cloud - On reset - Morph invisible'),
(-119105, 0, 4, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, 3, 0, 11686, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mistwhisper Lightning Cloud - On reset - Morph invisible');
