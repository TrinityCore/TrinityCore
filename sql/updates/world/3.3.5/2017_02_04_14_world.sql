
DELETE FROM `spell_custom_attr` WHERE `entry` IN (63124) AND `attributes`= 131072;
INSERT INTO `spell_custom_attr` VALUES (63124, 131072); -- quest "There's Something About the Squire" (13654)

DELETE FROM `spell_custom_attr` WHERE `entry` IN (63293, 68873, 70324, 64619) AND `attributes`= 4;
INSERT INTO `spell_custom_attr` VALUES
(63293, 4), -- Mimiron - spinning damage
(68873, 4), -- Wailing Souls
(70324, 4), -- Wailing Souls
(64619, 4); -- Ulduar, Mimiron, Emergency Fire Bot, Water Spray

DELETE FROM `spell_custom_attr` WHERE `entry` IN (66809, 67331, 66765, 67333) AND `attributes`=8;
INSERT INTO `spell_custom_attr` VALUES
(66809, 8), -- Meteor Fists
(67331, 8), -- Meteor Fists
(66765, 8), -- Meteor Fists
(67333, 8); -- Meteor Fists

DELETE FROM `spell_custom_attr` WHERE `entry` IN (66378, 67097, 67098, 67099, 64125, 64126, 72409, 72447, 72448, 72449, 62775) AND `attributes`=32768;
INSERT INTO `spell_custom_attr` VALUES
(66378, 32768), -- Trial of the Crusader, Jaraxxus, Shivan Slash
(67097, 32768), -- Trial of the Crusader, Jaraxxus, Shivan Slash
(67098, 32768), -- Trial of the Crusader, Jaraxxus, Shivan Slash
(67099, 32768), -- Trial of the Crusader, Jaraxxus, Shivan Slash
(64125, 32768), -- Ulduar, Yogg-Saron, Squeeze
(64126, 32768), -- Ulduar, Yogg-Saron, Squeeze
(72409, 32768), -- Rune of Blood (Deathbringer Saurfang)
(72447, 32768), -- Rune of Blood (Deathbringer Saurfang)
(72448, 32768), -- Rune of Blood (Deathbringer Saurfang)
(72449, 32768), -- Rune of Blood (Deathbringer Saurfang)
(62775, 32768); -- Ulduar: XT-002 Tympanic Tamparum

DELETE FROM `spell_custom_attr` WHERE `entry` IN (45145) AND `attributes`= 1048576;
INSERT INTO `spell_custom_attr` VALUES (45145, 1048576); -- Snake Trap Effect
