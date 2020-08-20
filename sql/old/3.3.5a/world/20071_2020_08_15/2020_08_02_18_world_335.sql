-- Sunblade Magister - Enchantment of Spell Haste
UPDATE `creature_addon` SET `auras` = "44604" WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 24685);
UPDATE `creature_template_addon` SET `auras` = "44604" WHERE `entry` = 24685;
UPDATE `creature_template_addon` SET `auras` = "44604" WHERE `entry` = 25569;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (26670,13197,13236,14327,14349,16810,18114,18450,18539,18541,18685,19643,19657,20135,24685) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26670,0,0,0,0,0,100,2,0,0,5000,8000,0,11,48854,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - In Combat CMC - Cast 'Shoot' (Normal Dungeon)"),
(26670,0,1,0,0,0,100,4,0,0,5000,8000,0,11,59241,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - In Combat CMC - Cast 'Shoot' (Heroic Dungeon)"),
(26670,0,2,0,0,0,100,2,9000,14000,22000,26000,0,11,48871,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - In Combat - Cast 'Aimed Shot' (Normal Dungeon)"),
(26670,0,3,0,0,0,100,4,9000,14000,22000,26000,0,11,59243,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - In Combat - Cast 'Aimed Shot' (Heroic Dungeon)"),
(26670,0,4,0,0,0,100,2,14000,17000,24000,27000,0,11,48872,1,0,0,0,0,6,0,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - In Combat - Cast 'Multi-Shot' (Normal Dungeon)"),
(26670,0,5,0,0,0,100,4,14000,17000,24000,27000,0,11,59244,1,0,0,0,0,6,0,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - In Combat - Cast 'Multi-Shot' (Heroic Dungeon)"),

(13197,0,0,0,0,0,100,0,0,0,2400,3800,0,11,15230,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Fel Lash - In Combat CMC - Cast 'Arcane Bolt'"),
(13197,0,1,0,0,0,100,0,9000,15000,11000,16000,0,11,22271,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Fel Lash - In Combat - Cast 'Arcane Explosion'"),

(13236,0,0,0,0,0,100,0,0,0,3400,4800,0,11,15234,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Primalist Thurloga - In Combat CMC - Cast 'Lightning Bolt'"),
(13236,0,1,0,0,0,100,0,9000,13000,11000,15000,0,11,16006,1,0,0,0,0,2,0,0,0,0,0,0,0,0,"Primalist Thurloga - In Combat - Cast 'Chain Lightning'"),
(13236,0,2,0,0,0,100,0,7000,8000,14000,17000,0,11,15616,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Primalist Thurloga - In Combat - Cast 'Flame Shock'"),
(13236,0,3,0,2,0,100,0,0,50,48000,60000,0,11,15786,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Primalist Thurloga - Between 0-50% Health - Cast 'Earthbind Totem'"),
(13236,0,4,0,2,0,100,0,0,30,15000,22000,0,11,15982,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Primalist Thurloga - Between 0-30% Health - Cast 'Healing Wave'"),

(14327,0,0,0,0,0,100,0,0,0,4800,6800,0,11,22709,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Lethtendris - In Combat CMC - Cast 'Void Bolt'"),
(14327,0,1,0,0,0,100,0,7000,12000,25000,30000,0,11,12742,1,0,0,0,0,5,0,0,0,0,0,0,0,0,"Lethtendris - In Combat - Cast 'Immolate'"),
(14327,0,2,0,0,0,100,0,8000,13000,13000,18000,0,11,17228,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Lethtendris - In Combat - Cast 'Shadow Bolt Volley'"),
(14327,0,3,0,0,0,100,0,2000,9000,15000,35000,0,11,16247,33,0,0,0,0,2,0,0,0,0,0,0,0,0,"Lethtendris - In Combat - Cast 'Curse of Thorns'"),
(14327,0,4,0,0,0,100,0,9000,12000,18000,22000,0,11,13338,33,0,0,0,0,6,0,0,0,0,0,0,0,0,"Lethtendris - In Combat - Cast 'Curse of Tongues'"),

(14349,0,0,0,0,0,100,0,0,0,2400,3800,0,11,15228,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Pimgib - In Combat CMC - Cast 'Fireball'"),
(14349,0,1,0,0,0,100,0,8000,12000,11000,15000,0,11,16046,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Pimgib - In Combat - Cast 'Blast Wave'"),
(14349,0,2,0,0,0,100,0,5000,7000,14000,19000,0,11,22713,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Pimgib - In Combat - Cast 'Flame Buffet'"),
(14349,0,3,0,2,0,100,0,0,50,30000,30000,0,11,22710,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Pimgib - Between 0-50% Health - Cast 'Enlarge'"),

(16810,0,0,0,0,0,100,0,0,0,2400,3800,0,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Bonechewer Backbreaker - In Combat CMC - Cast 'Shadow Bolt'"),
(16810,0,1,0,0,0,100,0,7000,11000,9000,14000,0,11,16583,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Bonechewer Backbreaker - In Combat - Cast 'Shadow Shock'"),
(16810,0,2,0,2,0,100,0,0,30,30000,30000,0,11,6742,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bonechewer Backbreaker - Between 0-30% Health - Cast 'Bloodlust'"),
-- Lightning Shield - Out of Combat instead On Aggro
(18114,0,0,0,1,0,100,0,1000,1000,30000,30000,0,11,12550,32,0,0,0,0,1,0,0,0,0,0,0,0,0,"Feralfen Mystic - Out of Combat - Cast 'Lightning Shield'"),
(18114,0,1,0,0,0,100,0,0,0,2400,3800,0,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Feralfen Mystic - In Combat CMC - Cast 'Lightning Bolt'"),
(18114,0,2,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Feralfen Mystic - Between 0-15% Health - Flee For Assist (No Repeat)"),
-- Power of Kran'aish - Out of Combat instead On Aggro, they doesn't flee
(18450,0,0,0,1,0,100,0,1000,1000,30000,30000,0,11,32924,32,0,0,0,0,1,0,0,0,0,0,0,0,0,"Shienor Sorcerer - Out of Combat - Cast 'Power of Kran'aish'"),
(18450,0,1,0,0,0,100,0,0,0,2400,3800,0,11,26098,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Shienor Sorcerer - In Combat CMC - Cast 'Lightning Bolt'"),
(18450,0,2,0,0,0,100,0,6000,10000,12000,16000,0,11,32907,1,0,0,0,0,2,0,0,0,0,0,0,0,0,"Shienor Sorcerer - In Combat - Cast 'Arakkoa Blast'"),
(18450,0,3,0,0,0,100,0,10000,14000,18000,25000,0,11,6728,1,0,0,0,0,6,0,0,0,0,0,0,0,0,"Shienor Sorcerer - In Combat - Cast 'Enveloping Winds'"),
-- Power of Kran'aish - Out of Combat instead On Aggro, he doesn't flee
(18539,0,0,0,1,0,100,0,1000,1000,30000,30000,0,11,32924,32,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ashkaz - Out of Combat - Cast 'Power of Kran'aish'"),
(18539,0,1,0,0,0,100,0,0,0,2400,3800,0,11,26098,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Ashkaz - In Combat CMC - Cast 'Lightning Bolt'"),
(18539,0,2,0,0,0,100,0,6000,10000,12000,16000,0,11,32907,1,0,0,0,0,2,0,0,0,0,0,0,0,0,"Ashkaz - In Combat - Cast 'Arakkoa Blast'"),
(18539,0,3,0,0,0,100,0,10000,14000,18000,25000,0,11,6728,1,0,0,0,0,6,0,0,0,0,0,0,0,0,"Ashkaz - In Combat - Cast 'Enveloping Winds'"),
-- Power of Kran'aish - Out of Combat instead On Aggro, he doesn't flee
(18541,0,0,0,1,0,100,0,1000,1000,30000,30000,0,11,32924,32,0,0,0,0,1,0,0,0,0,0,0,0,0,"Urdak - Out of Combat - Cast 'Power of Kran'aish'"),
(18541,0,1,0,0,0,100,0,0,0,2400,3800,0,11,26098,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Urdak - In Combat CMC - Cast 'Lightning Bolt'"),
(18541,0,2,0,0,0,100,0,6000,10000,12000,16000,0,11,32907,1,0,0,0,0,2,0,0,0,0,0,0,0,0,"Urdak - In Combat - Cast 'Arakkoa Blast'"),
(18541,0,3,0,0,0,100,0,10000,14000,18000,25000,0,11,6728,1,0,0,0,0,6,0,0,0,0,0,0,0,0,"Urdak - In Combat - Cast 'Enveloping Winds'"),

(18685,0,0,0,1,0,100,0,1000,1000,1800000,1800000,0,11,13787,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Okrek - Out of Combat - Cast 'Demon Armor'"),
(18685,0,1,0,0,0,100,0,0,0,2400,3800,0,11,14034,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Okrek - In Combat CMC - Cast 'Fireball'"),
(18685,0,2,0,0,0,100,0,8500,12000,12000,18000,0,11,32711,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Okrek - In Combat - Cast 'Shadow Nova'"),
(18685,0,3,0,0,0,100,0,6000,8000,6000,10000,0,11,12471,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Okrek - In Combat - Cast 'Shadow Bolt'"),

(19643,0,0,0,1,0,100,0,1000,1000,600000,600000,0,11,35917,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sunfury Astromancer - Out of Combat - Cast 'Fiery Intellect'"),
(19643,0,1,0,0,0,100,0,0,0,4500,6000,0,11,38391,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Sunfury Astromancer - In Combat CMC - Cast 'Scorch'"),
(19643,0,2,0,9,0,100,0,0,30,12000,16000,0,11,35914,1,0,0,0,0,5,0,0,0,0,0,0,0,0,"Sunfury Astromancer - Within 0-30 Range - Cast 'Astral Focus'"),

(19657,0,0,0,0,0,100,0,0,0,3400,4800,0,11,19816,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Summoner Kanthin - In Combat CMC - Cast 'Fireball'"),
(19657,0,1,0,9,0,100,0,0,8,12000,16000,0,11,11831,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Summoner Kanthin - Within 0-8 Range - Cast 'Frost Nova'"),
(19657,0,2,0,0,0,100,0,10000,14000,18000,21000,0,11,17273,1,0,0,0,0,5,0,0,0,0,0,0,0,0,"Summoner Kanthin - In Combat - Cast 'Pyroblast'"),

(20135,0,0,0,1,0,100,0,1000,1000,600000,600000,0,11,35917,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sunfury Arch Mage - Out of Combat - Cast 'Fiery Intellect'"),
(20135,0,1,0,0,0,100,0,0,0,4500,6000,0,11,20823,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Sunfury Arch Mage - In Combat CMC - Cast 'Fireball'"),
(20135,0,2,0,9,0,100,0,0,8,11000,15000,0,11,11831,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sunfury Arch Mage - Within 0-8 Range - Cast 'Frost Nova'"),
-- Experimental only because it will be too powerful without melee
-- and ranged phase (currently cannot be implemented properly)
-- because creature receives +10% to haste after each sucessful cast
-- and on retail if creature is in melee range it casts main spell less often
-- and if not in melee range, it spams main spell
-- In this case without melee phase creature will spam Frostbolts really fast
(24685,0,0,0,9,0,100,2,5,40,1,1,0,11,44606,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Sunblade Magister - Within 5-40 Range - Cast 'Frostbolt' (Normal Dungeon)"),
(24685,0,1,0,9,0,100,4,5,40,1,1,0,11,46035,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Sunblade Magister - Within 5-40 Range - Cast 'Frostbolt' (Heroic Dungeon)"),
(24685,0,2,0,0,0,100,2,8000,11000,17000,27000,0,11,44644,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sunblade Magister - In Combat - Cast 'Arcane Nova' (Normal Dungeon)"),
(24685,0,3,0,0,0,100,4,8000,11000,15000,21000,0,11,46036,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sunblade Magister - In Combat - Cast 'Arcane Nova' (Heroic Dungeon)"),
(24685,0,4,6,9,0,100,2,0,5,3000,7000,0,11,44606,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Sunblade Magister - Within 0-5 Range - Cast 'Frostbolt' (Normal Dungeon)"),
(24685,0,5,6,9,0,100,4,0,5,3000,7000,0,11,46035,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Sunblade Magister - Within 0-5 Range - Cast 'Frostbolt' (Heroic Dungeon)"),
(24685,0,6,0,61,0,100,0,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sunblade Magister - On Link - Enable Combat Movement");
