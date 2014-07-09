-- Chromie -- at start of CoS
SET @SPELL_TRIGGER     := 53435; -- Teleport to CoT Stratholme Phase 4
SET @SPELL_EFFECT      := 53436; -- Teleport to CoT Stratholme Phase 4

DELETE FROM `gossip_menu_option` WHERE `menu_id` = @MENUID5 or `menu_id` = @MENUID1 and `id` = 2;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES
(9586, 2, 0, 'Chromie, you and I both know what\'s going to happen in this time stream. We\'ve seen this all before. Can you just skip us ahead to all the real action?', 39667, 1, 1, 11277, 0, 0, 0, '', 0),
(11277, 0, 0, 'Yes, please!', 32024, 1, 1, 0, 0, 0, 0, '', 0);

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=@SPELL_TRIGGER;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(@SPELL_TRIGGER,@SPELL_EFFECT,1,'Teleport to CoT Stratholme Phase 4');

DELETE FROM `spell_target_position` WHERE `id`=@SPELL_EFFECT;
INSERT INTO `spell_target_position` (`id`,`target_map`,`target_position_x`,`target_position_y`,`target_position_z`,`target_orientation`) VALUES
(@SPELL_EFFECT,595,2071.55,1287.68,141.687,0);

UPDATE `creature_template` SET `ScriptName`='' WHERE `entry`=18338;
