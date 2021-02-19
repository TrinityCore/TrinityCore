DELETE FROM `spell_learn_spell` WHERE `entry` IN (87506, 87507, 79682, 87509, 87510, 87511, 87504, 87505, 80388);
INSERT INTO `spell_learn_spell` (`entry`, `SpellID`, `Active`) VALUES
(87506, 86528, 1), -- Mail Specialization (Hunter)
(87507, 86529, 1), -- Mail Specialization (Shaman)
(87509, 86526, 1), -- Plate Specialization (Warrior)
(87510, 86524, 1), -- Plate Specialization (Death Knight)
(87511, 86525, 1), -- Plate Specialization (Paladin)
(87504, 86531, 1), -- Leather Specialization (Rogue)
(87505, 86530, 1), -- Leather Specialization (Druid)
(79682, 93321, 1), -- Control Pet (Hunter)
(80388, 93375, 1); -- Control Demon (Warlock)
