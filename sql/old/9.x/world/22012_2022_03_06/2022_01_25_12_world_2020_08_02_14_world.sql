--
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (26727,26770,26942,27122,27177,27259,27289,27357,27358,27508,27603,27635,27636,27639,27653,27687,27732,27805,27826,27898,27965) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26727,0,0,0,0,0,100,1,0,0,0,0,0,31,1,3,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mage Hunter Ascendant - In Combat - Set Random Phase (1-3) (No Repeat)"),

(26727,0,1,0,0,1,100,2,0,0,2400,3800,0,11,12466,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Mage Hunter Ascendant - In Combat CMC - Cast 'Fireball' (Phase 1) (Normal Dungeon)"),
(26727,0,2,0,0,1,100,4,0,0,2400,3800,0,11,17290,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Mage Hunter Ascendant - In Combat CMC - Cast 'Fireball' (Phase 1) (Heroic Dungeon)"),
(26727,0,3,0,0,1,100,2,7000,9000,15000,28000,0,11,36808,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Mage Hunter Ascendant - In Combat - Cast 'Rain of Fire' (Phase 1) (Normal Dungeon)"),
(26727,0,4,0,0,1,100,4,7000,9000,15000,28000,0,11,39376,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Mage Hunter Ascendant - In Combat - Cast 'Rain of Fire' (Phase 1) (Heroic Dungeon)"),
(26727,0,5,0,0,1,100,0,4000,6000,12000,18000,0,11,47784,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mage Hunter Ascendant - In Combat - Cast 'Immolation Trap' (Phase 1)"),

(26727,0,6,0,0,2,100,2,0,0,2400,3800,0,11,12737,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Mage Hunter Ascendant - In Combat CMC - Cast 'Frostbolt' (Phase 2) (Normal Dungeon)"),
(26727,0,7,0,0,2,100,4,0,0,2400,3800,0,11,56837,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Mage Hunter Ascendant - In Combat CMC - Cast 'Frostbolt' (Phase 2) (Heroic Dungeon)"),
(26727,0,8,0,0,2,100,2,10000,12000,11000,15000,0,11,15244,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mage Hunter Ascendant - In Combat - Cast 'Cone of Cold' (Phase 2) (Normal Dungeon)"),
(26727,0,9,0,0,2,100,4,10000,12000,11000,15000,0,11,38384,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mage Hunter Ascendant - In Combat - Cast 'Cone of Cold' (Phase 2) (Heroic Dungeon)"),
(26727,0,10,0,0,2,100,0,7000,9000,11000,18000,0,11,55040,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mage Hunter Ascendant - In Combat - Cast 'Freezing Trap' (Phase 2)"),

(26727,0,11,0,0,4,100,2,4000,6000,8000,11000,0,11,34933,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mage Hunter Ascendant - In Combat - Cast 'Arcane Explosion' (Phase 4) (Normal Dungeon)"),
(26727,0,12,0,0,4,100,4,4000,6000,8000,11000,0,11,56825,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mage Hunter Ascendant - In Combat - Cast 'Arcane Explosion' (Phase 4) (Heroic Dungeon)"),
(26727,0,13,0,0,4,100,2,1000,1200,60000,60000,0,11,50182,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mage Hunter Ascendant - In Combat - Cast 'Aura of Arcane Haste' (Phase 4) (Normal Dungeon)"),
(26727,0,14,0,0,4,100,4,1000,1200,60000,60000,0,11,56827,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mage Hunter Ascendant - In Combat - Cast 'Aura of Arcane Haste' (Phase 4) (Heroic Dungeon)"),
(26727,0,15,0,0,4,100,0,9000,14000,19000,22000,0,11,13323,1,0,0,0,0,6,0,0,0,0,0,0,0,0,"Mage Hunter Ascendant - In Combat - Cast 'Polymorph' (Phase 4)"),
(26727,0,16,0,0,4,100,0,8000,9000,9000,15000,0,11,47789,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mage Hunter Ascendant - In Combat - Cast 'Arcane Trap' (Phase 4)"),

(26770,0,0,0,0,0,100,0,0,0,3400,4800,0,11,13878,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Tivax the Breaker - In Combat CMC - Cast 'Scorch'"),
(26770,0,1,0,0,0,100,0,5000,7000,9000,12000,0,11,20795,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Tivax the Breaker - In Combat - Cast 'Fire Blast'"),

(26942,0,0,0,1,0,100,1,0,0,0,0,0,11,45491,0,0,0,0,0,19,27180,10,0,0,0,0,0,0,"Decrepit Necromancer - Out of Combat - Cast 'Necrotic Purple Beam' (No Repeat)"),
(26942,0,1,0,0,0,100,0,0,0,3400,4800,0,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Decrepit Necromancer - In Combat CMC - Cast 'Shadow Bolt' (No Repeat)"),
(26942,0,2,0,0,0,100,0,7000,10000,16000,20000,0,11,50659,1,0,0,0,0,2,0,0,0,0,0,0,0,0,"Decrepit Necromancer - In Combat - Cast 'Conversion Beam'"),

(27122,0,0,0,0,0,100,0,0,0,3400,4800,0,11,12739,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Overseer Deathgaze - In Combat CMC - Cast 'Shadow Bolt'"),
(27122,0,1,0,0,0,100,0,9000,14000,15000,18000,0,11,50659,1,0,0,0,0,2,0,0,0,0,0,0,0,0,"Overseer Deathgaze - In Combat - Cast 'Conversion Beam'"),
-- No CMC
(27177,0,0,0,0,0,100,0,5000,9000,7000,13000,0,11,32018,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Iron Rune Overseer - In Combat - Cast 'Call Lightning'"),
(27177,0,1,2,8,0,100,1,48046,0,0,0,0,11,48047,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Iron Rune Overseer - On Spellhit 'Use Camera' - Cast 'Iron Dwarf Snapshot Credit' (No Repeat)"),
(27177,0,2,0,61,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Iron Rune Overseer - On Link - Despawn Instant"),
-- No CMC
(27259,0,0,0,1,0,100,0,5000,8000,5000,8000,0,11,48213,0,0,0,0,0,19,26785,25,0,0,0,0,0,0,"Dragonflayer Flamebinder - Out of Combat - Cast 'Dragonflayer Crone Fire'"),
(27259,0,1,0,0,0,100,0,8000,12000,16000,19000,0,11,52208,1,0,0,0,0,5,0,0,0,0,0,0,0,0,"Dragonflayer Flamebinder - In Combat - Cast 'Flame Patch'"),
(27259,0,2,0,0,0,100,0,5000,10000,12000,19000,0,11,52209,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Dragonflayer Flamebinder - In Combat - Cast 'Incite Flames'"),

(27289,0,0,0,0,0,100,0,0,0,3400,4800,0,11,51287,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Naxxramas Necrolord - In Combat CMC - Cast 'Chaos Bolt'"),

(27357,0,0,0,0,0,100,0,0,0,6000,8500,0,11,50740,64,0,0,0,0,5,0,0,0,0,0,0,0,0,"Onslaught Raven Archon - In Combat CMC - Cast 'Raven Flock'"),
(27357,0,1,0,2,0,100,0,0,30,19000,23000,0,11,50743,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Onslaught Raven Archon - Between 0-30% Health - Cast 'Unholy Frenzy'"),

(27358,0,0,0,0,0,100,0,0,0,7000,10000,0,11,51431,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Burning Depths Necromancer - In Combat CMC - Cast 'Power Release'"),

(27508,0,0,0,0,0,100,0,0,0,3800,4500,0,11,51339,64,0,0,0,0,5,0,0,0,0,0,0,0,0,"Necrolord Amarion - In Combat CMC - Cast 'Decimate'"),

(27603,0,0,0,0,0,100,0,0,0,3400,4800,0,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Angrathar Necrolord - In Combat CMC - Cast 'Shadow Bolt'"),
-- No CMC
(27635,0,0,0,0,0,100,2,7000,12000,14000,22000,0,11,50702,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Azure Spellbinder - In Combat - Cast 'Arcane Volley' (Normal Dungeon)"),
(27635,0,1,0,0,0,100,4,7000,12000,14000,22000,0,11,59212,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Azure Spellbinder - In Combat - Cast 'Arcane Volley' (Heroic Dungeon)"),
(27635,0,2,0,0,0,100,2,6000,9000,9000,12000,0,11,38047,1,0,0,0,0,5,0,0,0,0,0,0,0,0,"Azure Spellbinder - In Combat - Cast 'Mind Warp' (Normal Dungeon)"),
(27635,0,3,0,0,0,100,4,6000,9000,9000,12000,0,11,50566,1,0,0,0,0,5,0,0,0,0,0,0,0,0,"Azure Spellbinder - In Combat - Cast 'Mind Warp' (Heroic Dungeon)"),
(27635,0,4,0,0,0,100,0,9000,12000,4000,8000,0,11,50572,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Azure Spellbinder - In Combat - Cast 'Power Sap'"),

(27636,0,0,0,0,0,100,2,0,0,4000,6000,0,11,50705,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Azure Ley-Whelp - In Combat CMC - Cast 'Arcane Bolt' (Normal Dungeon)"),
(27636,0,1,0,0,0,100,4,0,0,4000,6000,0,11,59210,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Azure Ley-Whelp - In Combat CMC - Cast 'Arcane Bolt' (Heroic Dungeon)"),
-- No CMC
(27639,0,0,0,1,0,100,1,1000,1000,0,0,0,11,51518,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ring-Lord Sorceress - Out of Combat - Cast 'Nexus Energy Cosmetic' (No Repeat)"),
(27639,0,1,0,0,0,100,2,15000,19000,15000,19000,0,11,50715,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Ring-Lord Sorceress - In Combat - Cast 'Blizzard' (Normal Dungeon)"),
(27639,0,2,0,0,0,100,4,15000,19000,15000,19000,0,11,59278,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Ring-Lord Sorceress - In Combat - Cast 'Blizzard' (Heroic Dungeon)"),
(27639,0,3,0,0,0,100,2,9000,12000,15000,18000,0,11,16102,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Ring-Lord Sorceress - In Combat - Cast 'Flamestrike' (Normal Dungeon)"),
(27639,0,4,0,0,0,100,4,9000,12000,15000,18000,0,11,61402,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Ring-Lord Sorceress - In Combat - Cast 'Flamestrike' (Heroic Dungeon)"),

(27653,0,0,0,0,0,100,2,0,0,3400,4800,0,11,37924,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Phantasmal Water - In Combat CMC - Cast 'Water Bolt Volley' (Normal Dungeon)"),
(27653,0,1,0,0,0,100,4,0,0,3400,4800,0,11,59266,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Phantasmal Water - In Combat CMC - Cast 'Water Bolt Volley' (Heroic Dungeon)"),

(27687,0,0,0,0,0,100,0,0,0,3400,4800,0,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Frigid Necromancer Attacker - In Combat CMC - Cast 'Shadow Bolt'"),
(27687,0,1,0,0,0,100,0,2000,4000,60000,70000,0,11,50324,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Frigid Necromancer Attacker - In Combat - Cast 'Bone Armor'"),

(27732,0,0,0,0,0,100,2,0,0,5000,7000,0,11,15537,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Master Necromancer - In Combat CMC - Cast 'Shadow Bolt' (Normal Dungeon)"),
(27732,0,1,0,0,0,100,4,0,0,5000,7000,0,11,61558,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Master Necromancer - In Combat CMC - Cast 'Shadow Bolt' (Heroic Dungeon)"),
(27732,0,2,0,0,0,100,0,5000,9000,90000,180000,0,11,52611,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Master Necromancer - In Combat - Cast 'Summon Skeletons'"),

(27805,0,0,0,0,0,100,0,0,0,3400,4800,0,11,20298,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Necrolord Horus - In Combat CMC - Cast 'Shadow Bolt'"),
(27805,0,1,0,0,0,100,0,4000,8000,9000,12000,0,11,51340,32,0,0,0,0,5,0,0,0,0,0,0,0,0,"Necrolord Horus - In Combat - Cast 'Curse of Impotence'"),

(27826,0,0,0,0,0,100,0,0,0,3400,4800,0,11,20298,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Necrolord X'avius - In Combat CMC - Cast 'Shadow Bolt'"),
(27826,0,1,0,0,0,100,0,9000,12000,15000,18000,0,11,51337,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Necrolord X'avius - In Combat - Cast 'Shadowflame'"),

(27898,0,0,0,0,0,100,0,0,0,3400,4700,0,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Infinite Chrono-Magus - In Combat CMC - Cast 'Shadow Bolt'"),
(27898,0,1,0,0,0,100,0,8000,8000,12000,14000,0,11,38085,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Infinite Chrono-Magus - In Combat - Cast 'Shadow Blast'"),
-- No CMC
(27965,0,0,0,1,0,100,0,2000,2000,4000,4000,0,11,50563,0,0,0,0,0,19,28055,50,0,0,0,0,0,0,"Dark Rune Shaper - Out of Combat - Cast 'Carve Stone'"),
(27965,0,1,0,0,0,100,2,9000,13000,9000,13000,0,11,51496,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Dark Rune Shaper - In Combat - Cast 'Chiseling Ray' (Normal Dungeon)"),
(27965,0,2,0,0,0,100,4,9000,13000,9000,13000,0,11,59034,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Dark Rune Shaper - In Combat - Cast 'Chiseling Ray' (Heroic Dungeon)");
