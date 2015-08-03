-- Boss Elder Nadox Move Heroic Spell in spelldifficulty
DELETE FROM `spelldifficulty_dbc` WHERE `id` =56130;
INSERT INTO `spelldifficulty_dbc`(`id`,`spellid0`,`spellid1`) VALUES
(56130,56130,59467); -- Brood Plague
