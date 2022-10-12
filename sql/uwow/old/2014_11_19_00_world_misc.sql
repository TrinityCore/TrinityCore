ALTER TABLE `spell_trigger`
ADD `procEx` INT(11) DEFAULT '0' NOT NULL AFTER procFlags;
ALTER TABLE `spell_linked_spell`
ADD `removeMask` INT(11) DEFAULT '0' NOT NULL AFTER learnspell;
