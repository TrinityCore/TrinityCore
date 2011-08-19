ALTER TABLE `spell_dbc`
  ADD COLUMN `Stances` int(10) unsigned NOT NULL DEFAULT '0' AFTER `AttributesEx5`,
  ADD COLUMN `StancesNot` int(10) unsigned NOT NULL DEFAULT '0' AFTER `Stances`;
