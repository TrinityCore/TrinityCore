DELETE FROM `spell_learn_spell` WHERE `entry` in ( 108501, 30146);
INSERT INTO `spell_learn_spell` (`entry`, `SpellID`, `ReqSpell`, `Active`) VALUES
-- At learn Grimoire of Service
(108501, 111898, 30146, 1),
(108501, 111897, 0, 1),
(108501, 111896, 0, 1),
(108501, 111895, 0, 1),
(108501, 111859, 0, 1),
-- At learn Summon Felguard and already have Grimoire of Service
(30146, 111898, 108501, 1);