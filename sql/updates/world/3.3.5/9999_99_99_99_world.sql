
DELETE FROM `spell_custom_attr` WHERE `entry` IN(63124) AND `attributes`=131072;
INSERT INTO `spell_custom_attr` VALUES (63124, 131072); -- quest There's Something About the Squire (13654)

DELETE FROM `spell_custom_attr` WHERE `entry` IN(63293, 68873, 70324, 64619) AND `attributes`=4;
INSERT INTO `spell_custom_attr` VALUES (63293, 4); -- Mimiron - spinning damage
INSERT INTO `spell_custom_attr` VALUES (68873, 4); -- Wailing Souls
INSERT INTO `spell_custom_attr` VALUES (70324, 4); -- Wailing Souls
INSERT INTO `spell_custom_attr` VALUES (64619, 4); -- Ulduar, Mimiron, Emergency Fire Bot, Water Spray

DELETE FROM `spell_custom_attr` WHERE `entry` IN(66809, 67331, 66765, 67333) AND `attributes`=8;
INSERT INTO `spell_custom_attr` VALUES (66809, 8); -- Meteor Fists
INSERT INTO `spell_custom_attr` VALUES (67331, 8); -- Meteor Fists
INSERT INTO `spell_custom_attr` VALUES (66765, 8); -- Meteor Fists
INSERT INTO `spell_custom_attr` VALUES (67333, 8); -- Meteor Fists

DELETE FROM `spell_custom_attr` WHERE `entry` IN(66378, 67097, 67098, 67099, 64125, 64126, 72409, 72447, 72448, 72449, 62775) AND `attributes`=32768;
INSERT INTO `spell_custom_attr` VALUES (66378, 32768); -- Trial of the Crusader, Jaraxxus, Shivan Slash
INSERT INTO `spell_custom_attr` VALUES (67097, 32768); -- Trial of the Crusader, Jaraxxus, Shivan Slash
INSERT INTO `spell_custom_attr` VALUES (67098, 32768); -- Trial of the Crusader, Jaraxxus, Shivan Slash
INSERT INTO `spell_custom_attr` VALUES (67099, 32768); -- Trial of the Crusader, Jaraxxus, Shivan Slash
INSERT INTO `spell_custom_attr` VALUES (64125, 32768); -- Ulduar, Yogg-Saron, Squeeze
INSERT INTO `spell_custom_attr` VALUES (64126, 32768); -- Ulduar, Yogg-Saron, Squeeze
INSERT INTO `spell_custom_attr` VALUES (72409, 32768); -- Rune of Blood (Deathbringer Saurfang)
INSERT INTO `spell_custom_attr` VALUES (72447, 32768); -- Rune of Blood (Deathbringer Saurfang)
INSERT INTO `spell_custom_attr` VALUES (72448, 32768); -- Rune of Blood (Deathbringer Saurfang)
INSERT INTO `spell_custom_attr` VALUES (72449, 32768); -- Rune of Blood (Deathbringer Saurfang)
INSERT INTO `spell_custom_attr` VALUES (62775, 32768); -- Ulduar: XT-002 Tympanic Tamparum

DELETE FROM `spell_custom_attr` WHERE `entry` IN(45145) AND `attributes`=1048576;
INSERT INTO `spell_custom_attr` VALUES (45145, 1048576); -- Snake Trap Effect
