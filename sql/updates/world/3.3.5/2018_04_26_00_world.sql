-- 
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (17722,17801) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(17722, 0, 0, 0, 0, 0, 100, 2, 1000, 1000, 2400, 3800, 0, 11, 12675, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Coilfang Sorceress - IC CMC - Cast 'Frostbolt' (Normal Dungeon)"),
(17722, 0, 1, 0, 0, 0, 100, 4, 1000, 1000, 2400, 3800, 0, 11, 37930, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Coilfang Sorceress - IC CMC - Cast 'Frostbolt' (Heroic Dungeon)"),
(17722, 0, 2, 0, 0, 0, 100, 2, 18000, 20000, 25000, 27000, 0, 11, 31581, 1, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "Coilfang Sorceress - In Combat - Cast 'Blizzard' (No Repeat) (Normal Dungeon)"),
(17722, 0, 3, 0, 0, 0, 100, 4, 18000, 20000, 25000, 27000, 0, 11, 39416, 1, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "Coilfang Sorceress - In Combat - Cast 'Blizzard'  (Heroic Dungeon)"),
(17722, 0, 4, 0, 0, 0, 100, 2, 6000, 8000, 15000, 15000, 0, 11, 15063, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Coilfang Sorceress - In Combat - Cast 'Frost Nova'  (Normal Dungeon)"),
(17722, 0, 5, 0, 0, 0, 100, 4, 6000, 8000, 15000, 15000, 0, 11, 15531, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Coilfang Sorceress - In Combat - Cast 'Frost Nova'  (Heroic Dungeon)"),
(17801, 0, 0, 0, 0, 0, 100, 2, 1000, 1000, 4400, 5800, 0, 11, 15234, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Coilfang Siren - IC CMC - Cast 'Lightning Bolt' (Normal Dungeon)"),
(17801, 0, 1, 0, 0, 0, 100, 4, 1000, 1000, 3400, 4800, 0, 11, 37664, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Coilfang Siren - IC CMC - Cast 'Lightning Bolt' (Heroic Dungeon)"),
(17801, 0, 2, 0, 0, 0, 100, 2, 12000, 15000, 15000, 19000, 0, 11, 35106, 1, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "Coilfang Siren - In Combat - Cast 'Arcane Flare'(NormalDungeon)"),
(17801, 0, 3, 0, 0, 0, 100, 4, 9000, 12000, 15000, 17000, 0, 11, 37856, 1, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "Coilfang Siren - In Combat - Cast 'Arcane Flare' (HeroicDungeon)"),
(17801, 0, 4, 0, 0, 0, 100, 6, 9000, 13000, 10000, 14000, 0, 11, 38660, 1, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, "Coilfang Siren - In Combat - Cast 'Fear' (Dungeon)");
