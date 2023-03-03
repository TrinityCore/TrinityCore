ALTER TABLE `spell_trigger`
  ADD COLUMN `dummyId` INT(11) DEFAULT 0  NOT NULL AFTER `schoolMask`,
  ADD COLUMN `dummyEffect` INT(11) DEFAULT 0  NOT NULL AFTER `dummyId`;