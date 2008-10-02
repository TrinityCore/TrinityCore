-- (38398) Reduced Cleave Cost ()
DELETE FROM `spell_affect` WHERE `entry` IN (38398);
INSERT INTO `spell_affect` VALUES (38398, 0, 0x0000000020000000);

-- (40389) Crow Discount ()
DELETE FROM `spell_affect` WHERE `entry` IN (40389);
INSERT INTO `spell_affect` VALUES (40389, 0, 0x0000800000000000);