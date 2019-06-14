-- 
DELETE FROM `smart_scripts` WHERE `entryorguid`=113531 AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(113531, 1, 0, 0, 64, 0, 100, 0, 1, 0, 0, 0, 11, 4170, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Canon - GOSSIP_HELLO - Cast Cannon Ball'),
(113531, 1, 1, 0, 64, 0, 100, 0, 1, 0, 0, 0, 93, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Canon - GOSSIP_HELLO - SEND_GO_CUSTOM_ANIM');
UPDATE `gameobject` SET `phaseMask`=2 WHERE `id`=113529;
