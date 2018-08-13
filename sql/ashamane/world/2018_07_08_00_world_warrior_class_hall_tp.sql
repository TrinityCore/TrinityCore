-- Link the gossip menu to the creature
UPDATE `creature_template` SET `gossip_menu_id`=18724 WHERE `entry`=96679; -- Aerylia

UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=0 WHERE (`MenuId`=18724 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=0 WHERE (`MenuId`=18724 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=0 WHERE (`MenuId`=18724 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=0 WHERE (`MenuId`=18724 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=0 WHERE (`MenuId`=18724 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=0 WHERE (`MenuId`=18724 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=0 WHERE (`MenuId`=18724 AND `OptionIndex`=8);

UPDATE `gossip_menu_option` SET `OptionType`=1, `OptionNpcFlag`=1 WHERE `MenuId`=18724;

DELETE FROM `spell_script_names` WHERE `spell_id` IN (191473, 225220, 225163, 225115, 205813, 225233, 241928);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(191473, 'spell_class_hall_warrior_jump_exit'),
(225220, 'spell_class_hall_warrior_jump_exit'),
(225163, 'spell_class_hall_warrior_jump_exit'),
(225115, 'spell_class_hall_warrior_jump_exit'),
(205813, 'spell_class_hall_warrior_jump_exit'),
(225233, 'spell_class_hall_warrior_jump_exit'),
(241928, 'spell_class_hall_warrior_jump_exit');

DELETE FROM `spell_script_names` WHERE `spell_id` IN (191474, 225219, 225162, 225114, 205814, 225232, 241931);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(191474, 'spell_class_hall_warrior_jump_teleport'),
(225219, 'spell_class_hall_warrior_jump_teleport'),
(225162, 'spell_class_hall_warrior_jump_teleport'),
(225114, 'spell_class_hall_warrior_jump_teleport'),
(205814, 'spell_class_hall_warrior_jump_teleport'),
(225232, 'spell_class_hall_warrior_jump_teleport'),
(241931, 'spell_class_hall_warrior_jump_teleport');

UPDATE `creature_template` SET `ScriptName` = 'npc_class_hall_warrior_aerylia' WHERE `entry`=96679;
