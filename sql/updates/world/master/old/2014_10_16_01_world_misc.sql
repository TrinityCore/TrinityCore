ALTER TABLE `spell_proc_check`
ADD `specId` int(8) DEFAULT '0' NOT NULL AFTER dmgclass,
ADD `spellAttr0` int(11) DEFAULT '0' NOT NULL AFTER specId;

ALTER TABLE `spell_proc_check`
ADD `targetTypeMask` int(11) DEFAULT '0' NOT NULL AFTER spellAttr0;

ALTER TABLE `spell_proc_check`
ADD `mechanicMask` mediumint(8) DEFAULT '0' NOT NULL AFTER targetTypeMask,
ADD `fromlevel` mediumint(8) DEFAULT '0' NOT NULL AFTER mechanicMask,
ADD `perchp` mediumint(8) DEFAULT '0' NOT NULL AFTER fromlevel;

