UPDATE `gameobject_template` SET `flags`=0 WHERE `entry`=209441;
UPDATE `gossip_menu_option` SET `option_id`=1, `npc_option_npcflag`=1 WHERE `menu_id`=13321;

DELETE FROM `gossip_menu` WHERE (`entry`=13053 AND `text_id`=18851) OR (`entry`=13321 AND `text_id`=18848);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(13053, 18851), -- Nozdormu
(13321, 18848); -- Time Transit Device

-- Todo - Only -- 102564 missing for portals
DELETE FROM `spell_target_position` WHERE `id` IN (102126, 102579, 103868, 104761, 104764);
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES
(102126, 938, 3027.33, 515.127, 21.7765, 0.0459022), -- Teleport to Blue Dragonshrine
(102579, 938, 3827.66, 1103.65, 84.1375, 4.50164), -- Teleport to Ruby Dragonshrine
(103868, 938, 4347.06, 1298.96, 149.113, 0.781391), -- Teleport to Black Dragonshrine
(104761, 938, 2949.47, 69.0454, 9.21076, 3.1861), -- Teleport to Emerald Dragonshrine
(104764, 938, 4038.72, -358.382, 121.664, 5.49428); -- Teleport to Bronze Dragonshrine
