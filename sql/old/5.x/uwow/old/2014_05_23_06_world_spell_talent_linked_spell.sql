ALTER TABLE `spell_talent_linked_spell`
ADD `target` tinyint(3) DEFAULT '0' NOT NULL AFTER `type`,
ADD `caster` tinyint(3) DEFAULT '0' NOT NULL AFTER `target`;