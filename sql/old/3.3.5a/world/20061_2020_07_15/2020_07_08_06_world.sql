-- 
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (13358,13359,14390,14715,14733,14753,15641,16344,16403,17439,18113,18452,18457,19707,19779,20207,21650,21719,22331,23339,24082,24696,26295,26356,26434,26779,26801,26802,27117,27351,27560,27576,27588,27633,27844) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(13358,0,0,0,0,0,100,0,0,0,2300,3900,0,11,22121,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Stormpike Bowman - In Combat CMC - Cast 'Shoot'"),

(13359,0,0,0,0,0,100,0,0,0,2300,3900,0,11,22121,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Frostwolf Bowman - In Combat CMC - Cast 'Shoot'"),

(14390,0,0,0,0,0,100,0,0,0,2300,3900,0,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Expeditionary Mountaineer - In Combat CMC - Cast 'Shoot'"),

(14715,0,0,0,0,0,100,0,0,0,2300,4800,0,11,15620,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Silverwing Elite - In Combat CMC - Cast 'Shoot'"),
(14715,0,1,0,9,0,100,0,0,5,6100,15900,0,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Silverwing Elite - Within 0-5 Range - Cast 'Cleave'"),
(14715,0,2,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Silverwing Elite - Between 0-15% Health - Flee For Assist (No Repeat)"),

(14733,0,0,0,0,0,100,0,0,0,2300,3900,0,11,15620,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Sentinel Farsong - In Combat CMC - Cast 'Shoot'"),
(14733,0,1,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Sentinel Farsong - Between 0-15% Health - Flee For Assist (No Repeat)"),

(14753,0,0,0,0,0,100,0,0,0,2300,3900,0,11,22907,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Illiyana Moonblaze - In Combat CMC - Cast 'Shoot'"),
(14753,0,1,0,9,0,100,0,0,20,12000,15000,0,11,6533,1,0,0,0,0,2,0,0,0,0,0,0,0,0,"Illiyana Moonblaze - Within 0-20 Range - Cast 'Net'"),
(14753,0,2,0,2,0,100,0,0,30,40000,40000,0,11,3019,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Illiyana Moonblaze - Between 0-30% Health - Cast 'Frenzy'"),
(14753,0,3,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Illiyana Moonblaze - Between 0-15% Health - Flee For Assist (No Repeat)"),

(15641,0,0,0,0,0,100,0,0,0,2300,3900,0,11,10277,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Amani Axe Thrower - In Combat CMC - Cast 'Throw'"),

(16344,0,0,0,0,0,100,0,0,0,2300,3900,0,11,10277,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Shadowpine Headhunter - In Combat CMC - Cast 'Throw'"),
(16344,0,1,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Shadowpine Headhunter - Between 0-15% Health - Flee For Assist (No Repeat)"),

(16403,0,0,0,0,0,100,0,0,0,2300,3900,0,11,10277,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Withered Grimscale - In Combat CMC - Cast 'Throw'"),
(16403,0,1,0,9,0,100,0,0,5,16000,28000,0,11,7901,32,0,0,0,0,5,0,0,0,0,0,0,0,0,"Withered Grimscale - Within 0-5 Range - Cast 'Decayed Agility'"),
(16403,0,2,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Withered Grimscale - Between 0-15% Health - Flee For Assist (No Repeat)"),

(17439,0,0,0,0,0,100,0,0,0,2300,3900,0,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Stillpine Hunter - In Combat CMC - Cast 'Shoot'"),
(17439,0,1,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Stillpine Hunter - Between 0-15% Health - Flee For Assist (No Repeat)"),

(18113,0,0,0,1,0,100,1,1000,1000,0,0,0,11,32060,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Feralfen Hunter - Out of Combat - Cast 'Summon Sporebat' (No Repeat)"),
(18113,0,1,0,0,0,100,0,0,0,2300,3900,0,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Feralfen Hunter - In Combat CMC - Cast 'Shoot'"),
(18113,0,2,0,0,0,100,0,4000,8000,18000,24000,0,11,31975,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Feralfen Hunter - In Combat - Cast 'Serpent Sting'"),
(18113,0,3,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Feralfen Hunter - Between 0-15% Health - Flee For Assist (No Repeat)"),

(18452,0,0,0,0,0,100,0,0,0,2300,3900,0,11,10277,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Skithian Dreadhawk - In Combat CMC - Cast 'Throw'"),
(18452,0,1,0,0,0,100,0,5000,8000,14000,18000,0,11,32908,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Skithian Dreadhawk - In Combat - Cast 'Wing Clip'"),
(18452,0,2,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Skithian Dreadhawk - Between 0-15% Health - Flee For Assist (No Repeat)"),

(18457,0,0,0,0,0,100,0,0,0,2300,3900,0,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Tuurem Hunter - In Combat CMC - Cast 'Shoot'"),
(18457,0,1,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Tuurem Hunter - Between 0-15% Health - Flee For Assist (No Repeat)"),

(19707,0,0,0,0,0,100,0,0,0,2300,3900,0,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Sunfury Archer - In Combat CMC - Cast 'Shoot'"),
(19707,0,1,0,9,0,100,0,10,40,9000,12000,0,11,37847,1,0,0,0,0,2,0,0,0,0,0,0,0,0,"Sunfury Archer - Within 10-40 Range - Cast 'Immolation Arrow'"),
(19707,0,2,0,9,0,100,0,0,20,12000,15000,0,11,12024,1,0,0,0,0,2,0,0,0,0,0,0,0,0,"Sunfury Archer - Within 0-20 Range - Cast 'Net'"),
(19707,0,3,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Sunfury Archer - Between 0-15% Health - Flee For Assist (No Repeat)"),

(19779,0,0,0,0,0,100,0,0,0,2300,3900,0,11,36645,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Sunfury Geologist - In Combat CMC - Cast 'Throw Rock'"),
(19779,0,1,0,9,0,100,0,0,5,5000,9000,0,11,35918,32,0,0,0,0,2,0,0,0,0,0,0,0,0,"Sunfury Geologist - Within 0-5 Range - Cast 'Puncture Armor'"),
(19779,0,2,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Sunfury Geologist - Between 0-15% Health - Flee For Assist (No Repeat)"),

(20207,0,0,0,1,0,100,0,5000,5000,10000,70000,0,11,33796,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sunfury Bowman - Out of Combat - Cast 'Shoot Bow'"),
(20207,0,1,0,0,0,100,0,0,0,2300,3900,0,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Sunfury Bowman - In Combat CMC - Cast 'Shoot'"),
(20207,0,2,0,9,0,100,0,10,40,7000,9000,0,11,37847,1,0,0,0,0,2,0,0,0,0,0,0,0,0,"Sunfury Bowman - Within 10-40 Range - Cast 'Immolation Arrow'"),
(20207,0,3,0,9,0,100,0,0,20,12000,15000,0,11,12024,1,0,0,0,0,2,0,0,0,0,0,0,0,0,"Sunfury Bowman - Within 0-20 Range - Cast 'Net'"),
(20207,0,4,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Sunfury Bowman - Between 0-15% Health - Flee For Assist (No Repeat)"),

(21650,0,0,0,0,0,100,0,0,0,2300,3900,0,11,10277,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Skettis Talonite - In Combat CMC - Cast 'Throw'"),
(21650,0,1,0,0,0,100,0,6000,10000,9000,14000,0,11,11428,1,0,0,0,0,2,0,0,0,0,0,0,0,0,"Skettis Talonite - In Combat - Cast 'Knockdown'"),

(21719,0,0,0,0,0,100,0,0,0,2200,3800,0,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Dragonmaw Drake-Rider - In Combat CMC - Cast 'Shoot'"),
(21719,0,1,0,0,0,100,0,4000,6000,12000,16000,0,11,38859,32,0,0,0,0,5,0,0,0,0,0,0,0,0,"Dragonmaw Drake-Rider - In Combat - Cast 'Serpent Sting'"),
(21719,0,2,0,6,0,100,0,0,0,0,0,0,11,38341,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dragonmaw Drake-Rider - On Death - Cast 'Summon Enslaved Netherdrake'"),

(22331,0,0,0,0,0,100,0,0,0,2300,3900,0,11,38858,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Dragonmaw Elite - In Combat CMC - Cast 'Shoot'"),
(22331,0,1,0,0,0,100,0,6000,9000,12000,16000,0,11,38861,1,0,0,0,0,5,0,0,0,0,0,0,0,0,"Dragonmaw Elite - In Combat - Cast 'Aimed Shot'"),
(22331,0,2,0,0,0,100,0,4000,6000,12000,16000,0,11,38859,32,0,0,0,0,5,0,0,0,0,0,0,0,0,"Dragonmaw Elite - In Combat - Cast 'Serpent Sting'"),
(22331,0,3,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Dragonmaw Elite - Between 0-15% Health - Flee For Assist (No Repeat)"),

(23339,0,0,0,0,0,100,0,0,0,3900,5900,0,11,41169,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Illidari Heartseeker - In Combat CMC - Cast 'Shoot'"),
(23339,0,1,0,0,0,100,0,7000,11000,19000,25000,0,11,41173,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Illidari Heartseeker - In Combat - Cast 'Rapid Shot'"),
(23339,0,2,0,0,0,100,0,45000,60000,60000,75000,0,11,41171,1,0,0,0,0,2,0,0,0,0,0,0,0,0,"Illidari Heartseeker - In Combat - Cast 'Skeleton Shot'"),
(23339,0,3,0,2,0,100,1,0,50,0,0,0,11,41170,1,0,0,0,0,2,0,0,0,0,0,0,0,0,"Illidari Heartseeker - Between 0-50% Health - Cast 'Curse of the Bleakheart' (No Repeat)"),

(24082,0,0,0,0,0,100,2,0,0,2300,5000,0,11,54983,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Proto-Drake Handler - In Combat CMC - Cast 'Throw' (Normal Dungeon)"),
(24082,0,1,0,0,0,100,4,0,0,2300,5000,0,11,59696,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Proto-Drake Handler - In Combat CMC - Cast 'Throw' (Heroic Dungeon)"),
(24082,0,2,0,0,0,100,2,2000,3000,8000,9500,0,11,38621,1,0,0,0,0,2,0,0,0,0,0,0,0,0,"Proto-Drake Handler - In Combat - Cast 'Debilitating Strike' (Normal Dungeon)"),
(24082,0,3,0,0,0,100,4,2000,3000,8000,9500,0,11,59695,1,0,0,0,0,2,0,0,0,0,0,0,0,0,"Proto-Drake Handler - In Combat - Cast 'Debilitating Strike' (Heroic Dungeon)"),
(24082,0,4,0,16,0,100,2,43664,100,15000,21000,0,11,43664,32,0,0,0,0,7,0,0,0,0,0,0,0,0,"Proto-Drake Handler - On Friendly Unit Missing Buff 'Unholy Rage' - Cast 'Unholy Rage' (Normal Dungeon)"),
(24082,0,5,0,16,0,100,4,59694,100,15000,21000,0,11,59694,32,0,0,0,0,7,0,0,0,0,0,0,0,0,"Proto-Drake Handler - On Friendly Unit Missing Buff 'Unholy Rage' - Cast 'Unholy Rage' (Heroic Dungeon)"),

(24696,0,0,0,0,0,100,2,0,0,2300,5000,0,11,35946,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Coilskar Witch - In Combat CMC - Cast 'Shoot' (Normal Dungeon)"),
(24696,0,1,0,0,0,100,4,0,0,2300,5000,0,11,22907,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Coilskar Witch - In Combat CMC - Cast 'Shoot' (Heroic Dungeon)"),
(24696,0,2,0,0,0,100,2,3700,7000,15000,20000,0,11,20299,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Coilskar Witch - In Combat - Cast 'Forked Lightning' (Normal Dungeon)"),
(24696,0,3,0,0,0,100,4,3700,7000,15000,20000,0,11,46150,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Coilskar Witch - In Combat - Cast 'Forked Lightning' (Heroic Dungeon)"),
(24696,0,4,0,2,0,100,2,0,50,70000,85000,0,11,17741,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Coilskar Witch - Between 0-50% Health - Cast 'Mana Shield' (Normal Dungeon)"),
(24696,0,5,0,2,0,100,4,0,50,62000,70000,0,11,46151,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Coilskar Witch - Between 0-50% Health - Cast 'Mana Shield' (Heroic Dungeon)"),
(24696,0,6,0,9,0,100,0,0,50,8000,15000,0,11,44639,1,0,0,0,0,2,0,0,0,0,0,0,0,0,"Coilskar Witch - Within 0-50 Range - Cast 'Frost Arrow'"),

(26295,0,0,0,0,0,100,0,0,0,2300,3900,0,11,38556,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Magnataur Patriarch - In Combat CMC - Cast 'Throw'"),

(26356,0,0,0,0,0,100,0,0,0,2300,3900,0,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Redfang Hunter - In Combat CMC - Cast 'Shoot'"),
(26356,0,1,0,9,0,100,0,0,20,11000,16000,0,11,12024,1,0,0,0,0,2,0,0,0,0,0,0,0,0,"Redfang Hunter - Within 0-20 Range - Cast 'Net'"),
(26356,0,2,0,9,0,100,0,0,5,4000,7000,0,11,30639,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Redfang Hunter - Within 0-5 Range - Cast 'Carnivorous Bite'"),
(26356,0,3,0,6,0,100,0,0,0,0,0,0,11,47034,39,0,0,0,0,2,0,0,0,0,0,0,0,0,"Redfang Hunter - On Death - Cast 'Frostpaw Ally'"),

(26434,0,0,0,0,0,100,0,0,0,2300,3900,0,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Frostpaw Trapper - In Combat CMC - Cast 'Shoot'"),
(26434,0,1,0,0,0,100,0,9000,14000,9000,14000,0,11,30614,1,0,0,0,0,5,0,0,0,0,0,0,0,0,"Frostpaw Trapper - In Combat - Cast 'Aimed Shot'"),
(26434,0,2,0,9,0,100,0,0,5,11000,15000,0,11,32908,1,0,0,0,0,2,0,0,0,0,0,0,0,0,"Frostpaw Trapper - Within 0-5 Range - Cast 'Wing Clip'"),
(26434,0,3,0,6,0,100,0,0,0,0,0,0,11,47033,39,0,0,0,0,2,0,0,0,0,0,0,0,0,"Frostpaw Trapper - On Death - Cast 'Redfang Ally'"),

(26779,0,0,0,0,0,100,0,0,0,2300,3900,0,11,15620,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"7th Legion Wyrm Hunter - In Combat CMC - Cast 'Shoot'"),

(26801,0,0,0,4,0,100,0,0,0,0,0,0,28,47543,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Horde Ranger - On Aggro - Remove Aura 'Frozen Prison'"),
(26801,0,1,0,0,0,100,2,0,0,2300,3800,0,11,15620,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Horde Ranger - In Combat CMC - Cast 'Shoot' (Normal Dungeon)"),
(26801,0,2,0,0,0,100,4,0,0,2300,3800,0,11,22907,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Horde Ranger - In Combat CMC - Cast 'Shoot' (Heroic Dungeon)"),
(26801,0,3,0,9,0,100,2,5,45,9500,10000,0,11,47777,1,0,0,0,0,2,0,0,0,0,0,0,0,0,"Horde Ranger - Within 5-45 Range - Cast 'Incendiary Shot' (Normal Dungeon)"),
(26801,0,4,0,9,0,100,4,5,45,9500,10000,0,11,56933,1,0,0,0,0,2,0,0,0,0,0,0,0,0,"Horde Ranger - Within 5-45 Range - Cast 'Incendiary Shot' (Heroic Dungeon)"),
(26801,0,5,0,0,0,100,0,12000,15000,16100,19000,0,11,48191,5,0,0,0,0,1,0,0,0,0,0,0,0,0,"Horde Ranger - In Combat - Cast 'Rapid Shot'"),

(26802,0,0,0,4,0,100,0,0,0,0,0,0,28,47543,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Alliance Ranger - On Aggro - Remove Aura 'Frozen Prison'"),
(26802,0,1,0,0,0,100,2,0,0,2300,3800,0,11,15620,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Alliance Ranger - In Combat CMC - Cast 'Shoot' (Normal Dungeon)"),
(26802,0,2,0,0,0,100,4,0,0,2300,3800,0,11,22907,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Alliance Ranger - In Combat CMC - Cast 'Shoot' (Heroic Dungeon)"),
(26802,0,3,0,9,0,100,2,5,45,9500,10000,0,11,47777,1,0,0,0,0,2,0,0,0,0,0,0,0,0,"Alliance Ranger - Within 5-45 Range - Cast 'Incendiary Shot' (Normal Dungeon)"),
(26802,0,4,0,9,0,100,4,5,45,9500,10000,0,11,56933,1,0,0,0,0,2,0,0,0,0,0,0,0,0,"Alliance Ranger - Within 5-45 Range - Cast 'Incendiary Shot' (Heroic Dungeon)"),
(26802,0,5,0,0,0,100,0,12000,15000,16100,19000,0,11,48191,5,0,0,0,0,1,0,0,0,0,0,0,0,0,"Alliance Ranger - In Combat - Cast 'Rapid Shot'"),

(27117,0,0,0,0,0,100,0,0,0,2300,3900,0,11,15547,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Amberpine Scout - In Combat CMC - Cast 'Shoot'"),
(27117,0,1,0,9,0,100,0,0,5,9000,12000,0,11,35918,33,0,0,0,0,2,0,0,0,0,0,0,0,0,"Amberpine Scout - Within 0-5 Range - Cast 'Puncture Armor'"),
(27117,0,2,0,2,0,100,0,0,30,12000,20000,0,11,31567,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Amberpine Scout - Between 0-30% Health - Cast 'Deterrence'"),

(27351,0,0,0,0,0,100,0,0,0,2300,3900,0,11,15547,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Argent Crusade Rifleman - In Combat CMC - Cast 'Shoot'"),

(27560,0,0,0,0,0,100,0,0,0,2300,3900,0,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Darkspear Spear Thrower - In Combat CMC - Cast 'Shoot'"),
(27560,0,1,0,9,0,100,0,0,20,9000,14000,0,11,12024,1,0,0,0,0,2,0,0,0,0,0,0,0,0,"Darkspear Spear Thrower - Within 0-20 Range - Cast 'Net'"),

(27576,0,0,0,0,0,100,0,0,0,2300,3900,0,11,15547,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Fordragon Sentinel - In Combat CMC - Cast 'Shoot'"),
(27576,0,1,0,0,0,100,0,9000,16000,18000,24000,0,11,49481,1,0,0,0,0,5,0,0,0,0,0,0,0,0,"Fordragon Sentinel - In Combat - Cast 'Glaive Throw'"),

(27588,0,0,0,0,0,100,0,0,0,2300,3900,0,11,50092,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"7th Legion Elite - In Combat CMC - Cast 'Shoot'"),
(27588,0,1,0,9,0,100,0,0,20,9000,12000,0,11,62312,1,0,0,0,0,2,0,0,0,0,0,0,0,0,"7th Legion Elite - Within 0-20 Range - Cast 'Net'"),

(27633,0,0,0,0,0,100,2,0,0,5000,7000,0,11,51454,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Azure Inquisitor - In Combat CMC - Cast 'Throw' (Normal Dungeon)"),
(27633,0,1,0,0,0,100,4,0,0,5000,7000,0,11,59209,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Azure Inquisitor - In Combat CMC - Cast 'Throw' (Heroic Dungeon)"),
(27633,0,2,0,0,0,100,0,4000,7000,9000,12000,0,11,50573,1,0,0,0,0,2,0,0,0,0,0,0,0,0,"Azure Inquisitor - In Combat - Cast 'Arcane Cleave'"),
(27633,0,3,0,9,0,100,0,0,10,14000,20000,0,11,50690,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Azure Inquisitor - Within 0-10 Range - Cast 'Immobilizing Field'"),

(27844,0,0,0,0,0,100,0,0,0,2300,3900,0,11,15620,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Legion Commander Tyralion - In Combat CMC - Cast 'Shoot'");
