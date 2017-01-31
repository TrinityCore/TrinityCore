UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI',`ScriptName`='' WHERE `entry`IN(183877);
DELETE FROM `smart_scripts` WHERE `entryorguid`IN(183877) AND `source_type`=1;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(183877, 1, 0, 0, 62, 0, 100, 1, 8023, 0, 0, 0, 12, 19671, 8, 60000, 0, 0, 0, 8, 0, 0, 0, -351.345, -69.7118, -0.8754317, 4.34587, 'Ethereal Transporter Control Panel - On Gossip Option 0 Selected - Summon Cryo-Engineer Sha heen'),
(183877, 1, 1, 0, 62, 0, 100, 0, 8023, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ethereal Transporter Control Panel - On Gossip Option 0 Selected - Close Gossip');

UPDATE `gossip_menu_option` SET `action_menu_id`=0 WHERE  `menu_id`=8023 AND `id`=0;
