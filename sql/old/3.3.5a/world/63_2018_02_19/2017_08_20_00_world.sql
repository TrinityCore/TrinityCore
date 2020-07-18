UPDATE `creature_template` SET `ScriptName`='npc_razorscale_devouring_flame' WHERE `entry`=34188; -- Razorscale Devouring Flame Stalker
DELETE FROM `spelldifficulty_dbc` WHERE  `id` IN (64709,63317,64704,64758,63809); -- Devouring Flame, Flame Breath, Chain Lightning, Lightning Bolt
DELETE FROM `creature_template_addon` WHERE `entry` IN (34188,34189); -- Razorscale Devouring Flame Stalker
