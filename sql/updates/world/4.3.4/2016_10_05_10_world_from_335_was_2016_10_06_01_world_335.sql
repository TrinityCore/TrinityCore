--
/*
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid`=3692 AND `id`=11;

UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=3694;
DELETE FROM `gossip_menu` WHERE `entry`=10268;
DELETE FROM `npc_text` WHERE `id`=14259;

UPDATE `smart_scripts` SET `link`=5 WHERE `entryorguid`=11711 AND `id`=2;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11711 AND `id`=5;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11711, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 83, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Sentinel Aynasha - On Quest 'One Shot. One Kill.' accepted - Remove Questgiver flag");
*/