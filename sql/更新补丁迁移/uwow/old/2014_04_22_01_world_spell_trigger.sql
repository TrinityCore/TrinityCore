ALTER TABLE `spell_trigger`
ADD `chance` mediumint(8) DEFAULT '0' NOT NULL AFTER aura;
ALTER TABLE `spell_trigger_dummy`
ADD `chance` mediumint(8) DEFAULT '0' NOT NULL AFTER aura;
