ALTER TABLE `serverside_spell` ADD `ProcFlags2` int unsigned NOT NULL DEFAULT 0 AFTER `ProcFlags`;
ALTER TABLE `spell_proc` ADD `ProcFlags2` int unsigned NOT NULL DEFAULT 0 AFTER `ProcFlags`;
