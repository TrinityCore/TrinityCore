-- Cleanup
DELETE FROM `spell_affect` WHERE `entry` IN (28787);

-- Correct data
DELETE FROM `spell_affect` WHERE `entry` IN (37878,37879,37880);
INSERT INTO `spell_affect` VALUES 
(37878, 0, 0, 0x00, 0, 0, 0, 0x00000010000000F0, 0),
(37879, 0, 0, 0x00, 0, 0, 0, 0x00000000C0006000, 0),
(37880, 0, 0, 0x00, 0, 0, 0, 0x0000000411041E40, 0);
