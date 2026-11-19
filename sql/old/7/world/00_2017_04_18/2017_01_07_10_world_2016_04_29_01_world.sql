DELETE FROM `vehicle_template_accessory` WHERE `entry`=29460;
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES 
(29460, 29458, 0, 1, "Brunnhildar Drakerider", 8, 0);

UPDATE `npc_spellclick_spells` SET `spell_id`=46598 WHERE `npc_entry`=29460;
