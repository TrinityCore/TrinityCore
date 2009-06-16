DELETE FROM `spell_pet_auras` WHERE `spell` IN(56314, 56315, 56316, 56317, 56318);
INSERT INTO `spell_pet_auras` VALUES
(56314,0,57447),
(56315,0,57482),
(56316,0,57453),
(56317,0,57457),
(56318,0,57458);

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN(57447, 57482, 57453, 57457, 57458);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(57447,57485,2,'Kindred Spirits'),
(57482,57484,2,'Kindred Spirits'),
(57453,57483,2,'Kindred Spirits'),
(57457,57482,2,'Kindred Spirits'),
(57458,57475,2,'Kindred Spirits');