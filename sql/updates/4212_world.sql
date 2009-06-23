ALTER TABLE spell_pet_auras ADD effectId TINYINT( 3 ) UNSIGNED NOT NULL AFTER spell;
 
ALTER TABLE spell_pet_auras DROP PRIMARY KEY, ADD PRIMARY KEY(spell,effectId,pet);
 
INSERT INTO spell_pet_auras VALUES
(56314, 0, 0, 57447),
(56314, 1, 0, 57485),
(56315, 0, 0, 57452),
(56315, 1, 0, 57484),
(56316, 0, 0, 57453),
(56316, 1, 0, 57483),
(56317, 0, 0, 57457),
(56317, 1, 0, 57482),
(56318, 0, 0, 57458),
(56318, 1, 0, 57475);

DELETE FROM spell_linked_spell where `spell_trigger` in (57447,57482,57453, 57457, 57458);
