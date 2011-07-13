-- Paralytic Spray difficulty entries.
DELETE FROM `spelldifficulty_dbc` WHERE `id` = 3262;
INSERT INTO `spelldifficulty_dbc` VALUES
(3262,66901,67615,67616,67617);

-- Burning Spray difficulty entries.
DELETE FROM `spelldifficulty_dbc` WHERE `id` = 3264;
INSERT INTO `spelldifficulty_dbc` VALUES
(3264,66902,67627,67628,67629);


-- Burning Bile (DoT triggered from 66869) difficulty entries.
DELETE FROM `spelldifficulty_dbc` WHERE `id` = 3263;
INSERT INTO `spelldifficulty_dbc` VALUES
(3263,66870,67621,67622,67623);

-- Self explanatory comment
DELETE FROM spell_linked_spell WHERE `spell_trigger` IN (66901,67615,67616,67617);
INSERT INTO spell_linked_spell VALUES
(66901,66823,0,'Paralitic Toxin proc from Paralitic Spray'),
(67615,67618,0,'Paralitic Toxin proc from Paralitic Spray'),
(67616,67619,0,'Paralitic Toxin proc from Paralitic Spray'),
(67617,67620,0,'Paralitic Toxin proc from Paralitic Spray');

-- 66869 is the AoE wich triggers the burning bile on enemys
DELETE FROM spell_linked_spell WHERE `spell_trigger` IN (66902,67627,67628,67629);
INSERT INTO spell_linked_spell VALUES
(66902,66869,0,'Burning Bile Proc from Burning Spray'),
(67627,66869,0,'Burning Bile Proc from Burning Spray'),
(67628,66869,0,'Burning Bile Proc from Burning Spray'),
(67629,66869,0,'Burning Bile Proc from Burning Spray');
