ALTER TABLE `spell_linked_spell`
ADD `caster` tinyint(3) DEFAULT '0' NOT NULL AFTER type,
ADD `target` tinyint(3) DEFAULT '0' NOT NULL AFTER caster;
