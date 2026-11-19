ALTER TABLE `spell_learn_spell`
  CHANGE `entry` `entry` INT(10) UNSIGNED NOT NULL DEFAULT '0',
  CHANGE `SpellID` `SpellID` INT(10) UNSIGNED NOT NULL DEFAULT '0';

DELETE FROM `spell_learn_spell` WHERE `entry` IN (86467,87491,87492,87493,87494,87495,87496,87497,87498,87500);
INSERT INTO `spell_learn_spell` (`entry`,`SpellID`,`Active`) VALUES
(86467,86473,1), -- Mage
(87491,86470,1), -- Druid
(87492,86471,1), -- Death Knight
(87493,86472,1), -- Hunter
(87494,86474,1), -- Paladin
(87495,86475,1), -- Priest
(87496,86476,1), -- Rogue
(87497,86477,1), -- Shaman
(87498,86478,1), -- Warlock
(87500,86479,1); -- Warrior
