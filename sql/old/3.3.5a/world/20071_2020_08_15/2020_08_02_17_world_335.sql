--
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (5711,5715,13096,13099,13540,13541,13542,13546,13547,13548,15281,15401,15405,15417,15418,15970,15971,16249,16294,16307,16308,16311,16358,16362,16397,16522,17870,18583,19136,19830,20163,20887,21370,21730,24656,24815,26413,26607,26655,26722,27963) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(5711,0,0,0,0,0,100,0,0,0,3400,4800,0,11,12471,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Ogom the Wretched - In Combat CMC - Cast 'Shadow Bolt'"),
(5711,0,1,0,0,0,100,0,9100,15200,37900,57700,0,11,11639,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Ogom the Wretched - In Combat - Cast 'Shadow Word: Pain'"),
(5711,0,2,0,0,0,100,0,54300,54300,20700,26200,0,11,12493,33,0,0,0,0,5,0,0,0,0,0,0,0,0,"Ogom the Wretched - In Combat - Cast 'Curse of Weakness'"),

(5715,0,0,0,1,0,100,1,1000,1000,0,0,0,11,12790,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hukku - Out of Combat - Cast 'Hukku's Guardians' (No Repeat)"),
(5715,0,1,0,0,0,100,0,0,0,3400,4800,0,11,12471,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Hukku - In Combat CMC - Cast 'Shadow Bolt'"),
(5715,0,2,0,9,0,100,0,0,30,16400,29900,0,11,9081,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Hukku - Within 0-30 Range - Cast 'Shadow Bolt Volley'"),
(5715,0,3,0,0,0,100,0,9400,18200,21200,31300,0,11,12279,32,0,0,0,0,5,0,0,0,0,0,0,0,0,"Hukku - In Combat - Cast 'Curse of Blood'"),

(13096,0,0,0,1,0,100,0,1000,1000,1800000,1800000,0,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Coldmine Explorer - Out of Combat - Cast 'Frost Armor'"),
(13096,0,1,0,0,0,100,0,0,0,3400,4800,0,11,15242,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Coldmine Explorer - In Combat CMC - Cast 'Fireball'"),
(13096,0,2,0,0,0,100,0,9000,13000,10000,15000,0,11,14145,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Coldmine Explorer - In Combat - Cast 'Fire Blast'"),
(13096,0,3,0,0,0,100,0,15000,19000,16000,21000,0,11,15244,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Coldmine Explorer - In Combat - Cast 'Cone of Cold'"),

(13099,0,0,0,1,0,100,0,1000,1000,1800000,1800000,0,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Irondeep Explorer - Out of Combat - Cast 'Frost Armor'"),
(13099,0,1,0,0,0,100,0,0,0,3400,4800,0,11,15242,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Irondeep Explorer - In Combat CMC - Cast 'Fireball'"),
(13099,0,2,0,0,0,100,0,9000,13000,10000,15000,0,11,14145,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Irondeep Explorer - In Combat - Cast 'Fire Blast'"),
(13099,0,3,0,0,0,100,0,15000,19000,16000,21000,0,11,15244,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Irondeep Explorer - In Combat - Cast 'Cone of Cold'"),

(13540,0,0,0,1,0,100,0,1000,1000,1800000,1800000,0,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Seasoned Irondeep Explorer - Out of Combat - Cast 'Frost Armor'"),
(13540,0,1,0,0,0,100,0,0,0,3400,4800,0,11,15242,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Seasoned Irondeep Explorer - In Combat CMC - Cast 'Fireball'"),
(13540,0,2,0,0,0,100,0,9000,13000,10000,15000,0,11,14145,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Seasoned Irondeep Explorer - In Combat - Cast 'Fire Blast'"),
(13540,0,3,0,0,0,100,0,15000,19000,16000,21000,0,11,15244,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Seasoned Irondeep Explorer - In Combat - Cast 'Cone of Cold'"),

(13541,0,0,0,1,0,100,0,1000,1000,1800000,1800000,0,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Veteran Irondeep Explorer - Out of Combat - Cast 'Frost Armor'"),
(13541,0,1,0,0,0,100,0,0,0,3400,4800,0,11,15242,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Veteran Irondeep Explorer - In Combat CMC - Cast 'Fireball'"),
(13541,0,2,0,0,0,100,0,9000,13000,10000,15000,0,11,14145,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Veteran Irondeep Explorer - In Combat - Cast 'Fire Blast'"),
(13541,0,3,0,0,0,100,0,15000,19000,16000,21000,0,11,15244,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Veteran Irondeep Explorer - In Combat - Cast 'Cone of Cold'"),

(13542,0,0,0,1,0,100,0,1000,1000,1800000,1800000,0,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Champion Irondeep Explorer - Out of Combat - Cast 'Frost Armor'"),
(13542,0,1,0,0,0,100,0,0,0,3400,4800,0,11,15242,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Champion Irondeep Explorer - In Combat CMC - Cast 'Fireball'"),
(13542,0,2,0,0,0,100,0,9000,13000,10000,15000,0,11,14145,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Champion Irondeep Explorer - In Combat - Cast 'Fire Blast'"),
(13542,0,3,0,0,0,100,0,15000,19000,16000,21000,0,11,15244,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Champion Irondeep Explorer - In Combat - Cast 'Cone of Cold'"),

(13546,0,0,0,1,0,100,0,1000,1000,1800000,1800000,0,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Seasoned Coldmine Explorer - Out of Combat - Cast 'Frost Armor'"),
(13546,0,1,0,0,0,100,0,0,0,3400,4800,0,11,15242,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Seasoned Coldmine Explorer - In Combat CMC - Cast 'Fireball'"),
(13546,0,2,0,0,0,100,0,9000,13000,10000,15000,0,11,14145,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Seasoned Coldmine Explorer - In Combat - Cast 'Fire Blast'"),
(13546,0,3,0,0,0,100,0,15000,19000,16000,21000,0,11,15244,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Seasoned Coldmine Explorer - In Combat - Cast 'Cone of Cold'"),

(13547,0,0,0,1,0,100,0,1000,1000,1800000,1800000,0,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Veteran Coldmine Explorer - Out of Combat - Cast 'Frost Armor'"),
(13547,0,1,0,0,0,100,0,0,0,3400,4800,0,11,15242,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Veteran Coldmine Explorer - In Combat CMC - Cast 'Fireball'"),
(13547,0,2,0,0,0,100,0,9000,13000,10000,15000,0,11,14145,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Veteran Coldmine Explorer - In Combat - Cast 'Fire Blast'"),
(13547,0,3,0,0,0,100,0,15000,19000,16000,21000,0,11,15244,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Veteran Coldmine Explorer - In Combat - Cast 'Cone of Cold'"),

(13548,0,0,0,1,0,100,0,1000,1000,1800000,1800000,0,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Champion Coldmine Explorer - Out of Combat - Cast 'Frost Armor'"),
(13548,0,1,0,0,0,100,0,0,0,3400,4800,0,11,15242,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Champion Coldmine Explorer - In Combat CMC - Cast 'Fireball'"),
(13548,0,2,0,0,0,100,0,9000,13000,10000,15000,0,11,14145,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Champion Coldmine Explorer - In Combat - Cast 'Fire Blast'"),
(13548,0,3,0,0,0,100,0,15000,19000,16000,21000,0,11,15244,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Champion Coldmine Explorer - In Combat - Cast 'Cone of Cold'"),

(15281,0,0,0,0,0,100,0,0,0,3400,4800,0,11,20811,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Lanthan Perilon - In Combat CMC - Cast 'Fireball'"),
(15281,0,1,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lanthan Perilon - Between 0-15% Health - Flee For Assist (No Repeat)"),

(15401,0,0,0,0,0,100,0,0,0,3400,4800,0,11,20811,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Ley-Keeper Velania - In Combat CMC - Cast 'Fireball'"),
(15401,0,1,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Ley-Keeper Velania - Between 0-15% Health - Flee For Assist (No Repeat)"),

(15405,0,0,0,0,0,100,0,0,0,3400,4800,0,11,20811,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Ley-Keeper Caidanis - In Combat CMC - Cast 'Fireball'"),
(15405,0,1,0,2,0,100,1,0,15,0,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Ley-Keeper Caidanis - Between 0-15% Health - Flee For Assist (No Repeat)"),

(15417,0,0,0,0,0,100,0,0,0,3400,4800,0,11,20811,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Velan Brightoak - In Combat CMC - Cast 'Fireball'"),
(15417,0,1,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Velan Brightoak - Between 0-15% Health - Flee For Assist (No Repeat)"),

(15418,0,0,0,0,0,100,0,0,0,3400,4800,0,11,20811,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Magister Jaronis - In Combat CMC - Cast 'Fireball'"),
(15418,0,1,0,2,0,100,1,0,15,0,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Magister Jaronis - Between 0-15% Health - Flee For Assist (No Repeat)"),

(15970,0,0,0,0,0,100,0,0,0,3400,4800,0,11,20811,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Instructor Antheol - In Combat CMC - Cast 'Fireball'"),
(15970,0,1,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Instructor Antheol - Between 0-15% Health - Flee For Assist (No Repeat)"),

(15971,0,0,0,0,0,100,0,0,0,3400,4800,0,11,20811,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Silvermoon Apprentice - In Combat CMC - Cast 'Fireball'"),
(15971,0,1,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Silvermoon Apprentice - Between 0-15% Health - Flee For Assist (No Repeat)"),

(16249,0,0,0,0,0,100,0,0,0,3400,4800,0,11,20792,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Masophet the Black - In Combat CMC - Cast 'Frostbolt'"),
(16249,0,1,0,0,0,100,0,12000,15000,9000,13000,0,11,16568,1,0,0,0,0,2,0,0,0,0,0,0,0,0,"Masophet the Black - In Combat - Cast 'Mind Flay'"),
(16249,0,2,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Masophet the Black - Between 0-15% Health - Flee For Assist (No Repeat)"),

(16294,0,0,0,0,0,100,0,0,0,4700,5200,0,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Aldaron the Reckless - In Combat CMC - Cast 'Fireball'"),
(16294,0,1,0,2,0,100,1,0,15,0,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Aldaron the Reckless - Between 0-15% Health - Flee For Assist (No Repeat)"),

(16307,0,0,0,0,0,100,0,0,0,3400,4800,0,11,20793,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Deathcage Scryer - In Combat CMC - Cast 'Fireball'"),

(16308,0,0,0,0,0,100,0,0,0,3400,4800,0,11,20792,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Deathcage Sorcerer - In Combat CMC - Cast 'Frostbolt'"),
(16308,0,1,0,9,0,100,0,0,8,11000,16000,0,11,12748,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathcage Sorcerer - Within 0-8 Range - Cast 'Frost Nova'"),

(16311,0,0,0,0,0,100,0,0,0,3400,4800,0,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Phantasmal Watcher - In Combat CMC - Cast 'Shadow Bolt'"),

(16358,0,0,0,0,0,100,0,0,0,3400,4800,0,11,20802,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Kel'gash the Wicked - In Combat CMC - Cast 'Lightning Bolt'"),
(16358,0,1,0,9,0,100,0,0,30,9000,13000,0,11,28900,1,0,0,0,0,5,0,0,0,0,0,0,0,0,"Kel'gash the Wicked - Within 0-30 Range - Cast 'Chain Lightning'"),
(16358,0,2,0,0,0,100,0,7000,10000,15000,22000,0,11,7289,32,0,0,0,0,5,0,0,0,0,0,0,0,0,"Kel'gash the Wicked - In Combat - Cast 'Shrink'"),

(16362,0,0,0,0,0,100,0,0,0,3400,4800,0,11,20811,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Runewarden Deryan - In Combat CMC - Cast 'Fireball'"),
(16362,0,1,0,2,0,100,1,0,15,0,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Runewarden Deryan - Between 0-15% Health - Flee For Assist (No Repeat)"),

(16397,0,0,0,0,0,100,0,0,0,3400,4800,0,11,20811,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Ardeyn Riverwind - In Combat CMC - Cast 'Fireball'"),
(16397,0,1,0,2,0,100,1,0,15,0,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Ardeyn Riverwind - Between 0-15% Health - Flee For Assist (No Repeat)"),

(16522,0,0,0,25,0,100,0,0,0,0,0,0,11,31515,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Surveyor Candress - On Reset - Cast 'Red Beam'"),
(16522,0,1,0,4,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Surveyor Candress - On Aggro - Say Line 0"),
(16522,0,2,0,0,0,100,0,0,0,3400,4800,0,11,9487,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Surveyor Candress - In Combat CMC - Cast 'Fireball'"),

(17870,0,0,0,0,0,100,0,0,0,4000,5500,0,11,39337,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Angered Nether-wraith - In Combat CMC - Cast 'Arcane Bolt'"),
(17870,0,1,0,0,0,100,0,13000,16000,12000,17000,0,11,38205,1,0,0,0,0,2,0,0,0,0,0,0,0,0,"Angered Nether-wraith - In Combat - Cast 'Shadow Blast'"),

(18583,0,0,0,0,0,100,0,0,0,2400,3800,0,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Lisaile Fireweaver - In Combat CMC - Cast 'Fireball'"),
(18583,0,1,0,0,0,100,0,6000,10000,10000,16000,0,11,12470,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lisaile Fireweaver - In Combat - Cast 'Fire Nova'"),
(18583,0,2,0,2,0,100,1,0,30,0,0,0,11,32932,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lisaile Fireweaver - Between 0-30% Health - Cast 'Sun Shield' (No Repeat)"),
(18583,0,3,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lisaile Fireweaver - Between 0-15% Health - Flee For Assist (No Repeat)"),

(19136,0,0,0,0,0,100,0,0,0,2400,3800,0,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Flamewaker Imp - In Combat CMC - Cast 'Fireball'"),

(19830,0,0,0,0,0,100,0,0,0,3400,4800,0,11,35853,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Arcanist Ardonis - In Combat CMC - Cast 'Chain Fireball'"),
(19830,0,1,0,9,0,100,0,0,8,12000,15000,0,11,33860,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Arcanist Ardonis - Within 0-8 Range - Cast 'Arcane Explosion'"),

(20163,0,0,0,0,0,100,0,0,0,3400,4800,0,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Ambassador Solannas - In Combat CMC - Cast 'Fireball'"),
(20163,0,1,0,9,0,100,0,0,8,9000,15000,0,11,11831,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ambassador Solannas - Within 0-8 Range - Cast 'Frost Nova'"),

(20887,0,0,0,0,0,100,0,0,0,2400,3800,0,11,36227,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Deathforge Imp - In Combat CMC - Cast 'Firebolt'"),

(21370,0,0,0,0,0,100,0,0,0,2400,3800,0,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Ethereal Nethermancer - In Combat CMC - Cast 'Shadow Bolt'"),
(21370,0,1,0,2,0,100,1,0,50,0,0,0,11,17173,1,0,0,0,0,2,0,0,0,0,0,0,0,0,"Ethereal Nethermancer - Between 0-50% Health - Cast 'Drain Life' (No Repeat)"),

(21730,0,0,0,0,0,100,0,0,0,2400,3800,0,11,38669,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Alluvion - In Combat CMC - Cast 'Water Bolt'"),
(21730,0,1,0,0,0,100,0,4000,8000,14000,18000,0,11,15063,1,0,0,0,0,2,0,0,0,0,0,0,0,0,"Alluvion - In Combat - Cast 'Frost Nova'"),

(24656,0,0,0,0,0,100,0,0,0,2400,3800,0,11,44164,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Fizzle - In Combat CMC - Cast 'Firebolt'"),

(24815,0,0,0,0,0,100,2,0,0,3400,4800,0,11,44577,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Sunblade Imp - In Combat CMC - Cast 'Firebolt' (Normal Dungeon)"),
(24815,0,1,0,0,0,100,4,0,0,3400,4800,0,11,46044,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Sunblade Imp - In Combat CMC - Cast 'Firebolt' (Heroic Dungeon)"),

(26413,0,0,0,0,0,100,0,0,0,3400,4800,0,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Anub'ar Dreadweaver - In Combat CMC - Cast 'Shadow Bolt'"),
(26413,0,1,0,0,0,100,0,6000,9000,9000,14000,0,11,32063,33,0,0,0,0,5,0,0,0,0,0,0,0,0,"Anub'ar Dreadweaver - In Combat - Cast 'Corruption'"),

(26607,0,0,0,0,0,100,0,0,0,3400,4800,0,11,21971,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Anub'ar Blightbeast - In Combat CMC - Cast 'Poison Bolt'"),
(26607,0,1,0,0,0,100,0,9000,12000,20000,24000,0,11,47443,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Anub'ar Blightbeast - In Combat - Cast 'Blighted Shriek'"),

(26655,0,0,0,0,0,100,0,0,0,3400,4800,0,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"High Cultist Zangus - In Combat CMC - Cast 'Shadow Bolt'"),
(26655,0,1,0,2,0,100,0,0,30,120000,125000,0,11,51605,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"High Cultist Zangus - Between 0-30% Health - Cast 'Zeal'"),

(26722,0,0,0,0,0,100,2,0,0,3400,4800,0,11,15530,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Azure Magus - In Combat CMC - Cast 'Frostbolt' (Normal Dungeon)"),
(26722,0,1,0,0,0,100,4,0,0,3400,4800,0,11,56775,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Azure Magus - In Combat CMC - Cast 'Frostbolt' (Heroic Dungeon)"),
(26722,0,2,0,0,0,100,2,9000,11000,9000,15000,0,11,37132,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Azure Magus - In Combat - Cast 'Arcane Shock' (Normal Dungeon)"),
(26722,0,3,0,0,0,100,4,9000,11000,9000,15000,0,11,56776,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Azure Magus - In Combat - Cast 'Arcane Shock' (Heroic Dungeon)"),

(27963,0,0,0,0,0,100,2,0,0,3400,4800,0,11,15801,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Dark Rune Theurgist - In Combat CMC - Cast 'Lightning Bolt' (Normal Dungeon)"),
(27963,0,1,0,0,0,100,4,0,0,3400,4800,0,11,35010,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Dark Rune Theurgist - In Combat CMC - Cast 'Lightning Bolt' (Heroic Dungeon)"),
(27963,0,2,0,0,0,100,2,9000,12000,9000,12000,0,11,53167,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Dark Rune Theurgist - In Combat - Cast 'Forked Lightning' (Normal Dungeon)"),
(27963,0,3,0,0,0,100,4,9000,12000,9000,12000,0,11,59152,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Dark Rune Theurgist - In Combat - Cast 'Forked Lightning' (Heroic Dungeon)"),
(27963,0,4,0,9,0,100,1,0,5,0,0,0,11,51484,33,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dark Rune Theurgist - Within 0-5 Range - Cast 'Iron Might' (No Repeat)");
