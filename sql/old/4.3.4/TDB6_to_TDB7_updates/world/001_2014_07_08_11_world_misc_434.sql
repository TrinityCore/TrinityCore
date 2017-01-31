--
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=46293;

UPDATE `gossip_menu_option` SET `option_id`=1, `npc_option_npcflag`=1 WHERE `menu_id`=12104 AND `id`=1;

DELETE FROM `gossip_menu` WHERE `entry`=12104 AND `text_id`=16995;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(12104, 16995);

DELETE FROM `creature_equip_template` WHERE `entry` IN (46293);
INSERT INTO `creature_equip_template` (`entry`, `id`, `itemEntry1`, `itemEntry2`, `itemEntry3`) VALUES
(46293, 1, 31824, 0, 0);

DELETE FROM `spell_target_position` WHERE  `id`=86278 AND `effIndex`=0;
INSERT INTO `spell_target_position` (`id`, `effIndex`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES 
(86278, 0, 0, -5201.42, 477.913, 388.5, 5.2577);

DELETE FROM `smart_scripts` WHERE  `entryorguid`=46293 AND `source_type`=0 AND `id`=0 AND `link`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(46293, 0, 0, 0, 62, 0, 100, 0, 12104, 1, 0, 0, 11, 86278, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Torben Zapblast - On Gossip option select - Cast spell 86278 on player');

DELETE FROM `conditions` WHERE  `SourceTypeOrReferenceId`=15 AND `SourceGroup`=12104;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 12104, 1, 0, 0, 27, 0, 2, 3, 0, 0, 0, 0, '', 'Torben Zapblast - Show gossip option if player is level 2 or higher');
