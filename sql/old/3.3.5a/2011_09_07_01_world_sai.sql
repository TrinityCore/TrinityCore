DELETE FROM `gossip_menu` WHERE `entry`=2211 AND `text_id`=2850;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(2211, 2850);

UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=160445;

DELETE FROM `smart_scripts` WHERE `entryorguid`=160445 AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(160445, 1, 0, 0, 64, 0, 100, 0, 0, 0, 0, 0, 12, 9136, 1, 60*1000, 0, 0, 0, 8, 0, 0, 0, -7917.378906, -2610.533936, 221.123123, 5.040257, 'Sha''ni Proudtusk''s Remains - On gossip hello summon Sha''ni Proudtusk');
-- Need a way to prevent spamming this action.
