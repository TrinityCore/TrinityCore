ALTER TABLE `creature_classlevelstats` ADD PRIMARY KEY (`level`, `class`);
ALTER TABLE `playercreateinfo_item` ADD PRIMARY KEY (`race`, `class`, `itemid`); -- already got (race, class) index
ALTER TABLE `spell_enchant_proc_data` ADD PRIMARY KEY (`entry`);
ALTER TABLE `version` ADD PRIMARY KEY (`core_version`);
