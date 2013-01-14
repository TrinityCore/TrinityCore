-- Boss Anubarak Move Heroic Spell in spelldifficulty
DELETE FROM `spelldifficulty_dbc` WHERE `id` IN (53472,53454);
INSERT INTO `spelldifficulty_dbc`(`id`,`spellid0`,`spellid1`) VALUES
(53472,53472,59433), -- Spell Pound
(53454,53454,59446); -- Spell Impale Damage
