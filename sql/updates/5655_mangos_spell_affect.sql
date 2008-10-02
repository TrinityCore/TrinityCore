-- (46090) Brutal Idol of Steadfastness ()
DELETE FROM `spell_affect` WHERE `entry` IN (46090);
INSERT INTO `spell_affect` VALUES (46090, 0, 0, 0x0000000000000002, 0);

-- (46100) Brutal Idol of Tenacity ()
DELETE FROM `spell_affect` WHERE `entry` IN (46100);
INSERT INTO `spell_affect` VALUES (46100, 0, 0, 0x0000001000000000, 0);

-- (46088) Brutall Idol of Resolve ()
DELETE FROM `spell_affect` WHERE `entry` IN (46088);
INSERT INTO `spell_affect` VALUES (46088, 0, 0, 0x0000044000000000, 0);

-- (46091) Brutal Libram of Fortitude ()
DELETE FROM `spell_affect` WHERE `entry` IN (46091);
INSERT INTO `spell_affect` VALUES (46091, 0, 0, 0x0000000000800000, 0);

-- (46095) Brutal Libram of Vengeance ()
DELETE FROM `spell_affect` WHERE `entry` IN (46095);
INSERT INTO `spell_affect` VALUES (46095, 0, 0, 0x0000004000000000, 0);

-- (46851) Holy Shock Bonus ()
DELETE FROM `spell_affect` WHERE `entry` IN (46851);
INSERT INTO `spell_affect` VALUES (46851, 0, 0, 0x0001000000000000, 0);

-- (46096) Brutal Totem of Indomitability ()
DELETE FROM `spell_affect` WHERE `entry` IN (46096);
INSERT INTO `spell_affect` VALUES (46096, 0, 0, 0x0000001000000000, 0);

-- (46097) Brutal Totem of Survival ()
DELETE FROM `spell_affect` WHERE `entry` IN (46097);
INSERT INTO `spell_affect` VALUES (46097, 0, 0, 0x0000000090100000, 0);

-- By triggers
DELETE FROM `spell_affect` WHERE `entry` IN (31569);
DELETE FROM `spell_affect` WHERE `entry` IN (31570);
-- By dummy
DELETE FROM `spell_affect` WHERE `entry` IN (28830);
DELETE FROM `spell_affect` WHERE `entry` IN (33695);
DELETE FROM `spell_affect` WHERE `entry` IN (37182);