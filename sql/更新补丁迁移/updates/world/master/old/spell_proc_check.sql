ALTER TABLE `spell_proc_check`
ADD `powertype` tinyint(3) UNSIGNED DEFAULT '0' NOT NULL AFTER effectmask,
ADD `dmgclass` tinyint(3) UNSIGNED DEFAULT '0' NOT NULL AFTER powertype;
