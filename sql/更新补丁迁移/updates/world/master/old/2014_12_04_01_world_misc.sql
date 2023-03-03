ALTER TABLE `spell_proc_check`
ADD `combopoints` INT(11) DEFAULT '0' NOT NULL AFTER spelltypeMask;

ALTER TABLE `spell_trigger`
ADD `schoolMask` INT(11) DEFAULT '0' NOT NULL AFTER addptype;

ALTER TABLE `spell_trigger`
ADD `addptype` INT(11) DEFAULT '0' NOT NULL AFTER check_spell_id;