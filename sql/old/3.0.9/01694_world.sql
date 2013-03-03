-- Sanctified Wrath
INSERT INTO `spell_proc_event` VALUES (57318, 0x00, 10, 0x00000000, 0x00002000, 0x00000000, 0x00004000, 0x00000000, 0.000000, 0.000000, 6);
INSERT INTO `spell_proc_event` VALUES (53375, 0x00, 10, 0x00000000, 0x00002000, 0x00000000, 0x00004000, 0x00000000, 0.000000, 0.000000, 6);

-- Star Sinner
DELETE FROM `spell_proc_event` WHERE `entry` IN (54738);
INSERT INTO `spell_proc_event`  VALUES (54738, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002, 0.000000, 0.000000, 45);

-- Tentacles
DELETE FROM `spell_proc_event` WHERE `entry` IN (61618);
INSERT INTO `spell_proc_event`  VALUES (61618, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 45);

-- Demonic Sacrifice
DELETE FROM `spell_bonus_data` WHERE `entry` = 18790;
INSERT INTO `spell_bonus_data` (`entry`,`direct_bonus`,`dot_bonus`,`ap_bonus`,`comments`) VALUES
('18790','0','0','0','Warlock - Fel Stamina');
