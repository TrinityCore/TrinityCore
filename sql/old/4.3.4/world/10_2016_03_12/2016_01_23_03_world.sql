--
DELETE FROM `spell_loot_template` WHERE `Entry` IN (75183,86615);
INSERT INTO `spell_loot_template` (`Entry`, `Item`, `MinCount`, `MaxCount`) VALUES
(75183, 54464, 8, 11);

INSERT INTO `spell_loot_template` (`Entry`, `Item`) VALUES
(86615, 61987);
