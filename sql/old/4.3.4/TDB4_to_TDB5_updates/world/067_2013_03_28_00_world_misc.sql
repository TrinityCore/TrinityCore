SET @GOSSIP := 5750;
SET @LOTHOS := 14387;

UPDATE `gossip_menu_option` SET `option_id`=1, `npc_option_npcflag`=1 WHERE `menu_id`=@GOSSIP; -- 4.3.4 (they are 0)

DELETE FROM `smart_scripts` WHERE `entryorguid`=@LOTHOS AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@LOTHOS, 0, 0, 0, 62, 0, 100, 0, @GOSSIP, 0, 0, 0, 11, 25139, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Lothos Riftwaker - On Gossip select - Teleport player');

DELETE FROM `spell_target_position` WHERE `id`=25139;
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES
(25139, 409, 1080, -483, -108, 1); -- Teleport to Molten Core DND
