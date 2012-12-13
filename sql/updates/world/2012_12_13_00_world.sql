DELETE FROM `waypoint_data` WHERE `id`=389230 AND `point`=11 AND `position_z`=21.8886; -- duplicated point with wrong `point`

ALTER TABLE `creature_classlevelstats` ADD PRIMARY KEY (`level`, `class`);
ALTER TABLE `playercreateinfo_item` ADD PRIMARY KEY (`race`, `class`, `itemid`); -- already got (race, class) index
ALTER TABLE `spell_enchant_proc_data` ADD PRIMARY KEY (`entry`);
ALTER TABLE `version` ADD PRIMARY KEY (`core_version`);
ALTER TABLE `waypoint_data` ADD PRIMARY KEY (`id`, `point`);
