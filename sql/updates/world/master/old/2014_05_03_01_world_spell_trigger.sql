ALTER TABLE `spell_trigger`
ADD `group` tinyint(3) DEFAULT '0' NOT NULL AFTER chance;
ALTER TABLE `spell_trigger_dummy`
ADD `group` tinyint(3) DEFAULT '0' NOT NULL AFTER chance;
