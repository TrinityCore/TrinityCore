
-- -------------------------
-- -- Primary Key updates --
-- -------------------------
ALTER TABLE `creature_classlevelstats`
	ADD PRIMARY KEY (`level`, `class`);
	
ALTER TABLE `event_scripts`
	ADD PRIMARY KEY (`id`);

ALTER TABLE `game_event_arena_seasons`
	ADD PRIMARY KEY (`eventEntry`, `season`);

ALTER TABLE `gameobject_scripts`
	ADD PRIMARY KEY (`id`);

ALTER TABLE `playercreateinfo_item`
	ADD PRIMARY KEY (`race`, `class`, `itemid`);

ALTER TABLE `quest_end_scripts`
	ADD PRIMARY KEY (`id`);

ALTER TABLE `quest_start_scripts`
	ADD PRIMARY KEY (`id`);

ALTER TABLE `spell_enchant_proc_data`
	ADD PRIMARY KEY (`entry`);

ALTER TABLE `spell_linked_spell`
	ADD PRIMARY KEY (`spell_trigger`, `spell_effect`, `type`);

ALTER TABLE `spell_script_names`
	ADD PRIMARY KEY (`spell_id`, `ScriptName`);
	
ALTER TABLE `spell_scripts`
	ADD PRIMARY KEY (`id`, `datalong`, `datalong2`);
	
ALTER TABLE `version`
	ADD PRIMARY KEY (`core_version`);
	
ALTER TABLE `waypoint_data`
	ADD PRIMARY KEY (`id`, `point`);