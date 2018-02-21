ALTER TABLE `spell_power`
  CHANGE `ManaCost` `ManaCost` INT(11) DEFAULT 0 NOT NULL,
  CHANGE `ManaCostAdditional` `ManaCostAdditional` INT(11) DEFAULT 0 NOT NULL;
