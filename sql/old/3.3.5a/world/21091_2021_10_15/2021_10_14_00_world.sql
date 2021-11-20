--
DELETE FROM `creature_equip_template` WHERE `CreatureID` = 18794;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 18794 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN 1879400 AND 1879403 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(18794,0,0,0,25,0,100,0,0,0,0,0,0,11,32958,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cabal Ritualist - On Reset - Cast 'Crystal Channel'"),
(18794,0,1,0,11,0,100,0,0,0,0,0,0,88,1879400,1879403,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cabal Ritualist - On Spawn - Run Random Script"),
(18794,0,2,0,4,0,10,0,0,0,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Cabal Ritualist - On Aggro - Say Line 0"),

(18794,0,3,0,0,1,100,2,0,0,3400,4500,0,11,15497,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Cabal Ritualist - In Combat CMC - Cast 'Frostbolt' (Normal Dungeon) (Phase 1)"),
(18794,0,4,0,0,1,100,4,0,0,3400,4500,0,11,12675,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Cabal Ritualist - In Combat CMC - Cast 'Frostbolt' (Heroic Dungeon) (Phase 1)"),
(18794,0,5,0,0,1,100,2,10000,18000,12100,16900,0,11,15532,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cabal Ritualist - In Combat - Cast 'Frost Nova' (Normal Dungeon) (Phase 1)"),
(18794,0,6,0,0,1,100,4,10000,18000,12100,16900,0,11,15063,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cabal Ritualist - In Combat - Cast 'Frost Nova' (Normal Dungeon) (Phase 1)"),

(18794,0,7,0,0,2,100,2,0,0,5000,5000,0,11,33832,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Cabal Ritualist - In Combat CMC - Cast 'Arcane Missiles' (Normal Dungeon) (Phase 2)"),
(18794,0,8,0,0,2,100,4,0,0,5000,5000,0,11,38263,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Cabal Ritualist - In Combat CMC - Cast 'Arcane Missiles' (Heroic Dungeon) (Phase 2)"),
(18794,0,9,0,0,2,100,0,2400,14300,5200,21700,0,11,33487,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Cabal Ritualist - In Combat - Cast 'Addle Humanoid' (Phase 2)"),

(18794,0,10,0,0,4,100,0,3600,6200,4800,11200,0,11,9574,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Cabal Ritualist - In Combat - Cast 'Flame Buffet' (Phase 3)"),
(18794,0,11,0,0,4,100,2,6100,20200,8400,22900,0,11,20795,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Cabal Ritualist - In Combat - Cast 'Fire Blast' (Normal Dungeon) (Phase 3)"),
(18794,0,12,0,0,4,100,4,6100,20200,8400,22900,0,11,14145,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Cabal Ritualist - In Combat - Cast 'Fire Blast' (Heroic Dungeon) (Phase 3)"),

(18794,0,13,0,0,8,100,0,10000,15000,12100,19300,0,11,12540,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Cabal Ritualist - In Combat - Cast 'Gouge' (Phase 4)"),

(18794,0,14,0,15,0,100,4,15,15000,20000,0,0,11,17201,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Cabal Ritualist - Friendly Crowd Controlled - Cast 'Dispel Magic' (Heroic Dungeon)"),
(18794,0,15,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Cabal Ritualist - Between 0-15% Health - Flee For Assist (No Repeat)"),

(1879400,9,0,0,0,0,100,0,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cabal Ritualist - On Script - Set Event Phase 1"),
(1879400,9,1,0,0,0,100,0,0,0,0,0,0,71,0,1,12421,0,0,0,1,0,0,0,0,0,0,0,0,"Cabal Ritualist - On Script - Set Mainhand Item"),

(1879401,9,0,0,0,0,100,0,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cabal Ritualist - On Script - Set Event Phase 2"),
(1879401,9,1,0,0,0,100,0,0,0,0,0,0,71,0,1,14618,0,0,0,1,0,0,0,0,0,0,0,0,"Cabal Ritualist - On Script - Set Mainhand Item"),

(1879402,9,0,0,0,0,100,0,0,0,0,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cabal Ritualist - On Script - Set Event Phase 3"),
(1879402,9,1,0,0,0,100,0,0,0,0,0,0,71,0,1,13718,0,0,0,1,0,0,0,0,0,0,0,0,"Cabal Ritualist - On Script - Set Mainhand Item"),

(1879403,9,0,0,0,0,100,0,0,0,0,0,0,22,4,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cabal Ritualist - On Script - Set Event Phase 4"),
(1879403,9,1,0,0,0,100,0,0,0,0,0,0,71,0,1,19980,0,0,0,1,0,0,0,0,0,0,0,0,"Cabal Ritualist - On Script - Set Mainhand Item"),
(1879403,9,2,0,0,0,100,0,0,0,0,0,0,71,0,2,0,19980,0,0,1,0,0,0,0,0,0,0,0,"Cabal Ritualist - On Script - Set Offhand Item");

--
DELETE FROM `creature_equip_template` WHERE `CreatureID` = 19167 AND `ID` BETWEEN 2 AND 5;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 19167 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN 1916700 AND 1916703 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(19167,0,0,0,11,0,100,0,0,0,0,0,0,11,35191,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bloodwarder Slayer - On Spawn - Cast 'Arcane Explosion Proc'"),
(19167,0,1,0,4,0,100,0,0,0,0,0,0,88,1916700,1916703,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bloodwarder Slayer - On Aggro - Run Random Script"),
(19167,0,2,0,0,3,100,0,7200,10600,12100,22900,0,11,35189,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Bloodwarder Slayer - In Combat - Cast 'Solar Strike' (Phase 1, 2)"),
(19167,0,3,0,0,12,100,0,7700,7700,10900,21700,0,11,15708,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Bloodwarder Slayer - In Combat - Cast 'Mortal Strike' (Phase 3, 4)"),
(19167,0,4,0,0,0,100,0,9800,22900,10900,26500,0,11,13736,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bloodwarder Slayer - In Combat - Cast 'Whirlwind'"),

(1916700,9,0,0,0,0,100,0,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bloodwarder Slayer - On Script - Set Event Phase 1"),
(1916700,9,1,0,0,0,100,0,0,0,0,0,0,71,0,1,29407,0,0,0,1,0,0,0,0,0,0,0,0,"Bloodwarder Slayer - On Script - Set Mainhand Item"),
(1916700,9,2,0,0,0,100,0,0,0,0,0,0,28,35191,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bloodwarder Slayer - On Script - Remove Aura 'Arcane Explosion Proc'"),
(1916700,9,3,0,0,0,100,0,0,0,0,0,0,11,35192,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bloodwarder Slayer - On Script - Cast 'Melt Armor Proc'"),

(1916701,9,0,0,0,0,100,0,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bloodwarder Slayer - On Script - Set Event Phase 2"),
(1916701,9,1,0,0,0,100,0,0,0,0,0,0,71,0,1,29408,0,0,0,1,0,0,0,0,0,0,0,0,"Bloodwarder Slayer - On Script - Set Mainhand Item"),
(1916701,9,2,0,0,0,100,0,0,0,0,0,0,28,35191,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bloodwarder Slayer - On Script - Remove Aura 'Arcane Explosion Proc'"),
(1916701,9,3,0,0,0,100,0,0,0,0,0,0,11,35193,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bloodwarder Slayer - On Script - Cast 'Seed of Corruption Proc'"),

(1916702,9,0,0,0,0,100,0,0,0,0,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bloodwarder Slayer - On Script - Set Event Phase 3"),
(1916702,9,1,0,0,0,100,0,0,0,0,0,0,71,0,1,29409,0,0,0,1,0,0,0,0,0,0,0,0,"Bloodwarder Slayer - On Script - Set Mainhand Item"),
(1916702,9,2,0,0,0,100,0,0,0,0,0,0,28,35191,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bloodwarder Slayer - On Script - Remove Aura 'Arcane Explosion Proc'"),
(1916702,9,3,0,0,0,100,0,0,0,0,0,0,11,35188,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bloodwarder Slayer - On Script - Cast 'Chilling Touch'"),

(1916703,9,0,0,0,0,100,0,0,0,0,0,0,22,4,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bloodwarder Slayer - On Script - Set Event Phase 4"),
(1916703,9,1,0,0,0,100,0,0,0,0,0,0,71,0,1,29410,0,0,0,1,0,0,0,0,0,0,0,0,"Bloodwarder Slayer - On Script - Set Mainhand Item");

--
DELETE FROM `creature_equip_template` WHERE `CreatureID` = 19510 AND `ID` BETWEEN 2 AND 5;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 19510 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN 1951000 AND 1951003 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(19510,0,0,0,4,0,100,0,0,0,0,0,0,88,1951000,1951003,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bloodwarder Centurion - On Aggro - Run Random Script"),
(19510,0,1,0,0,0,100,0,6200,19300,12100,16900,0,11,35178,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Bloodwarder Centurion - In Combat - Cast 'Shield Bash'"),

(1951000,9,0,0,0,0,100,0,0,0,0,0,0,71,0,1,29403,0,0,0,1,0,0,0,0,0,0,0,0,"Bloodwarder Centurion - On Script - Set Mainhand Item"),
(1951000,9,1,0,0,0,100,0,0,0,0,0,0,11,35186,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bloodwarder Centurion - On Script - Cast 'Melt Armor Proc'"),

(1951001,9,0,0,0,0,100,0,0,0,0,0,0,71,0,1,29404,0,0,0,1,0,0,0,0,0,0,0,0,"Bloodwarder Centurion - On Script - Set Mainhand Item"),
(1951001,9,1,0,0,0,100,0,0,0,0,0,0,11,35187,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bloodwarder Centurion - On Script - Cast 'Arcane Explosion Proc'"),

(1951002,9,0,0,0,0,100,0,0,0,0,0,0,71,0,1,29405,0,0,0,1,0,0,0,0,0,0,0,0,"Bloodwarder Centurion - On Script - Set Mainhand Item"),
(1951002,9,1,0,0,0,100,0,0,0,0,0,0,11,35188,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bloodwarder Centurion - On Script - Cast 'Chilling Touch'"),

(1951003,9,0,0,0,0,100,0,0,0,0,0,0,71,0,1,29406,0,0,0,1,0,0,0,0,0,0,0,0,"Bloodwarder Centurion - On Script - Set Mainhand Item"),
(1951003,9,1,0,0,0,100,0,0,0,0,0,0,11,35184,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bloodwarder Centurion - On Script - Cast 'Unstable Affliction Proc'");
