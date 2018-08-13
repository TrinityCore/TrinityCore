DELETE FROM `smart_scripts` WHERE  `entryorguid`=-21002070 AND `source_type`=0 AND `id`=0 AND `link`=1;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=-21002070 AND `source_type`=0 AND `id`=1 AND `link`=2;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=-21002070 AND `source_type`=0 AND `id`=2 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=-21002070 AND `source_type`=0 AND `id`=3 AND `link`=4;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=-21002070 AND `source_type`=0 AND `id`=4 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=-21002070 AND `source_type`=0 AND `id`=5 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=-21002070 AND `source_type`=0 AND `id`=6 AND `link`=7;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=-21002070 AND `source_type`=0 AND `id`=7 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=-21002070 AND `source_type`=0 AND `id`=8 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=-21002070 AND `source_type`=0 AND `id`=9 AND `link`=10;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=-21002070 AND `source_type`=0 AND `id`=10 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=-21002070 AND `source_type`=0 AND `id`=11 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=-21002069 AND `source_type`=0 AND `id`=0 AND `link`=1;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=-21002069 AND `source_type`=0 AND `id`=1 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=-21002069 AND `source_type`=0 AND `id`=2 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=-21002069 AND `source_type`=0 AND `id`=3 AND `link`=4;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=-21002069 AND `source_type`=0 AND `id`=4 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=-21002069 AND `source_type`=0 AND `id`=5 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=-123586 AND `source_type`=0 AND `id`=0 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=-123584 AND `source_type`=0 AND `id`=0 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=-19412 AND `source_type`=0 AND `id`=0 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=-19402 AND `source_type`=0 AND `id`=0 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=-19361 AND `source_type`=0 AND `id`=0 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=-13579 AND `source_type`=0 AND `id`=0 AND `link`=0;

DELETE FROM `smart_scripts` WHERE  `entryorguid`=0 AND `source_type`=0 AND `id`=0 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=0 AND `source_type`=0 AND `id`=1 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=7222 AND `source_type`=0 AND `id`=0 AND `link`=1;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=7222 AND `source_type`=0 AND `id`=1 AND `link`=2;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=195004 AND `source_type`=0 AND `id`=0 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=215133 AND `source_type`=1 AND `id`=0 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=215133 AND `source_type`=0 AND `id`=1 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=215695 AND `source_type`=1 AND `id`=0 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=215695 AND `source_type`=0 AND `id`=0 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=227291 AND `source_type`=0 AND `id`=0 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=227293 AND `source_type`=0 AND `id`=0 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=239241 AND `source_type`=0 AND `id`=0 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=251766 AND `source_type`=0 AND `id`=0 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=251766 AND `source_type`=0 AND `id`=1 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=1431429 AND `source_type`=0 AND `id`=0 AND `link`=0;

DELETE FROM `smart_scripts` WHERE `entryorguid`IN (314,391,1013,2345,2719,3448,4052,7337,7915,11441,11492,14322,15146,16409,16522,16876,17371,17725,17826,17892,18261,18450,18455,18539,18638,18870,18995,19456,19527,21218,21644,22844,22874,23030,23196,23285,23507,23527,23528,23529,23530,23531,25397,25398,25399,25599,27959,28557,30146,30461,32720,32888,33356);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(314, 0, 2, 0, 0, 0, 100, 0, 2100, 2900, 12500, 36300, '', 11, 11831, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Eliza - In Combat - Cast Frost Nova'),
(314, 0, 3, 0, 0, 0, 100, 0, 4100, 6400, 72300, 72300, '', 11, 3107, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Eliza - In Combat - Cast Summon Eliza\'s Guard'),
(314, 0, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, '', 11, 20819, 64, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Eliza - In Combat CMC - Cast Frostbolt'),
(314, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Eliza - On Aggro - Say Line 0'),
(391, 0, 1, 0, 0, 0, 100, 0, 12000, 15000, 27000, 35000, '', 11, 78542, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Old Murk-Eye - In Combat - Cast \'Splash\''),
(391, 0, 0, 0, 0, 0, 100, 0, 2000, 3000, 12000, 14000, '', 11, 80555, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Old Murk-Eye - In Combat - Cast \'Sonic Spear\''),
(391, 0, 2, 3, 2, 0, 100, 1, 0, 30, 0, 0, '', 11, 8599, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Old Murk-Eye - Between 0-30% Health - Cast \'Enrage\' (No Repeat)'),
(391, 0, 3, 0, 61, 0, 100, 1, 0, 30, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Old Murk-Eye - Between 0-30% Health - Say Line 0 (No Repeat)'),
(1013, 0, 0, 0, 4, 0, 15, 1, 0, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mosshide Mystic - On Aggro - Say Line 0'),
(1013, 0, 1, 0, 0, 0, 100, 0, 0, 0, 3300, 5100, '', 11, 9532, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Mosshide Mystic - In Combat CMC - Cast \'Lightning Bolt\''),
(1013, 0, 2, 0, 0, 0, 30, 1, 14400, 14400, 0, 0, '', 11, 11436, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Mosshide Mystic - In Combat - Cast \'Slow\''),
(1013, 0, 3, 0, 74, 0, 80, 1, 0, 40, 0, 0, '', 11, 11986, 1, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 'Mosshide Mystic - On Friendly Between 0-40% Health - Cast \'Healing Wave\''),
(1013, 0, 4, 0, 2, 0, 100, 1, 16, 30, 0, 0, '', 11, 3288, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mosshide Mystic - Between 16-30% Health - Cast \'Moss Hide\''),
(1013, 0, 5, 0, 2, 0, 100, 513, 0, 15, 0, 0, '', 28, 3288, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mosshide Mystic - Between 0-15% Health - Remove Aura \'Moss Hide\''),
(1013, 0, 6, 0, 2, 0, 100, 1, 0, 15, 0, 0, '', 25, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mosshide Mystic - Between 0-15% Health - Flee For Assist (No Repeat)'),
(2345, 0, 2, 0, 2, 0, 100, 1, 0, 30, 0, 0, '', 25, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dun Garok Rifleman - Between 0-30% Health - Flee For Assist'),
(2345, 0, 1, 0, 0, 0, 100, 0, 12000, 18000, 30000, 30000, '', 11, 6685, 1, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Dun Garok Rifleman - In Combat - Cast \'Piercing Shot\''),
(2345, 0, 0, 0, 0, 0, 100, 0, 0, 0, 2300, 3900, '', 11, 6660, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Dun Garok Rifleman - In Combat CMC - Cast \'Shoot\''),
(2719, 0, 2, 0, 2, 0, 100, 1, 0, 50, 0, 0, '', 39, 15, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dustbelcher Lord - Between 0-50% Health - Call For Help (No Repeat)'),
(2719, 0, 1, 0, 0, 0, 100, 0, 6600, 18700, 30800, 32400, '', 11, 13730, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dustbelcher Lord - In Combat - Cast \'Demoralizing Shout\''),
(2719, 0, 0, 0, 0, 0, 100, 0, 7800, 12100, 11200, 30000, '', 11, 9128, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dustbelcher Lord - In Combat - Cast \'Battle Shout\''),
(3448, 0, 0, 0, 20, 0, 100, 0, 880, 0, 0, 0, '', 80, 344800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tonga Runetotem - On Quest \'Altered Beings\' Finished - Run Script'),
(4052, 0, 0, 0, 0, 0, 100, 0, 0, 0, 3400, 4700, '', 11, 9739, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cenarion Druid - In Combat - Cast \'Wrath\''),
(4052, 0, 1, 0, 2, 0, 100, 1, 0, 30, 0, 0, '', 11, 5759, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cenarion Druid - Between 0-30% Health - Cast \'Cat Form\' (No Repeat)'),
(7337, 0, 4, 0, 2, 0, 100, 3, 0, 15, 0, 0, '', 25, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Death\'s Head Necromancer - Between 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)'),
(7337, 0, 3, 0, 0, 0, 100, 2, 8000, 15000, 18000, 25000, '', 11, 11443, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Death\'s Head Necromancer - In Combat - Cast \'Cripple\' (Normal Dungeon)'),
(7337, 0, 2, 0, 0, 0, 100, 2, 0, 0, 2400, 3800, '', 11, 9613, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Death\'s Head Necromancer - In Combat CMC - Cast \'Shadow Bolt\' (Normal Dungeon)'),
(7337, 0, 1, 0, 4, 0, 100, 3, 0, 0, 0, 0, '', 11, 11445, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Death\'s Head Necromancer - On Aggro - Cast \'Bone Armor\' (No Repeat) (Normal Dungeon)'),
(7337, 0, 0, 0, 1, 0, 100, 3, 1000, 1000, 0, 0, '', 11, 12420, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Death\'s Head Necromancer - Out of Combat - Cast \'Summon Skeletal Servant\' (Normal Dungeon)'),
(7915, 0, 0, 0, 0, 0, 100, 3, 0, 0, 15000, 15000, '', 11, 11504, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Walking Bomb - In Combat - Cast \'Walking Bomb Effect\' (No Repeat) (Normal Dungeon)'),
(11441, 0, 0, 0, 4, 0, 10, 3, 0, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Gordok Brute - On Aggro - Say Line 0 (No Repeat)'),
(11441, 0, 1, 0, 0, 0, 100, 2, 4000, 8000, 12000, 15000, '', 11, 18072, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Gordok Brute - In Combat - Cast \'Uppercut\' (No Repeat)'),
(11441, 0, 2, 0, 0, 0, 100, 2, 3000, 7000, 10000, 12000, '', 11, 15615, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Gordok Brute - In Combat - Cast \'Pummel\' (No Repeat)'),
(11441, 0, 3, 0, 0, 0, 100, 2, 10000, 18000, 15000, 18000, '', 11, 22572, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Gordok Brute - In Combat - Cast \'Bruising Blow\' (No Repeat)'),
(11441, 0, 4, 5, 2, 0, 100, 3, 0, 30, 0, 0, '', 11, 15716, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gordok Brute - Between 0-30% Health - Cast \'Enrage\' (No Repeat) (Normal Dungeon)'),
(11441, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, '', 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gordok Brute - Between 0-30% Health - Say Line 1 (No Repeat) (Normal Dungeon)'),
(11441, 0, 6, 0, 1, 0, 100, 0, 3000, 3000, 5000, 10000, '', 10, 1, 11, 391, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gordok Brute - Out of Combat - Play Random Emote (1, 11, 391)'),
(11492, 0, 0, 0, 4, 0, 100, 515, 0, 0, 0, 0, '', 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Alzzin the Wildshaper - On Aggro - Increment Phase By 1 (Phase 1) (No Repeat) (Normal Dungeon)'),
(11492, 0, 1, 0, 0, 1, 100, 2, 4000, 8000, 14000, 18000, '', 11, 22691, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Alzzin the Wildshaper - In Combat - Cast \'Disarm\' (Phase 1) (No Repeat) (Normal Dungeon)'),
(11492, 0, 2, 0, 0, 1, 100, 2, 2000, 5000, 15000, 20000, '', 11, 22661, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Alzzin the Wildshaper - In Combat - Cast \'Enervate\' (Phase 1) (No Repeat) (Normal Dungeon)'),
(11492, 0, 3, 0, 0, 1, 100, 2, 10000, 12000, 12000, 16000, '', 11, 10101, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Alzzin the Wildshaper - In Combat - Cast \'Knock Away\' (Phase 1) (No Repeat) (Normal Dungeon)'),
(11492, 0, 4, 5, 2, 1, 100, 3, 0, 80, 0, 0, '', 11, 22660, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Alzzin the Wildshaper - Between 0-80% Health - Cast \'Dire Wolf Form\' (Phase 1) (No Repeat) (Normal Dungeon)'),
(11492, 0, 5, 0, 61, 1, 100, 512, 0, 0, 0, 0, '', 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Alzzin the Wildshaper - Between 0-80% Health - Increment Phase By 1 (Phase 1) (No Repeat) (Normal Dungeon)'),
(11492, 0, 6, 0, 0, 2, 100, 2, 2000, 5000, 3000, 6000, '', 11, 19319, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Alzzin the Wildshaper - In Combat - Cast \'Vicious Bite\' (Phase 1) (No Repeat) (Normal Dungeon)'),
(11492, 0, 7, 0, 0, 2, 100, 2, 4000, 8000, 20000, 25000, '', 11, 22689, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Alzzin the Wildshaper - In Combat - Cast \'Mangle\' (Phase 1) (No Repeat) (Normal Dungeon)'),
(11492, 0, 8, 9, 2, 2, 100, 3, 0, 60, 0, 0, '', 11, 22688, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Alzzin the Wildshaper - Between 0-60% Health - Cast \'Tree Form\' (Phase 2) (No Repeat) (Normal Dungeon)'),
(11492, 0, 9, 0, 61, 2, 100, 512, 0, 0, 0, 0, '', 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Alzzin the Wildshaper - Between 0-60% Health - Increment Phase By 1 (Phase 2) (No Repeat) (Normal Dungeon)'),
(11492, 0, 10, 0, 0, 0, 100, 2, 1000, 3000, 3000, 6000, '', 11, 22128, 32, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Alzzin the Wildshaper - In Combat - Cast \'Thorns\' (Phase 2) (No Repeat) (Normal Dungeon)'),
(11492, 0, 11, 0, 0, 0, 100, 2, 2000, 4000, 5000, 10000, '', 11, 22662, 32, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Alzzin the Wildshaper - In Combat - Cast \'Wither\' (Phase 2) (No Repeat) (Normal Dungeon)'),
(11492, 0, 12, 0, 0, 0, 100, 2, 7000, 10000, 9000, 14000, '', 11, 7948, 33, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Alzzin the Wildshaper - In Combat - Cast \'Wild Regeneration\' (Phase 2) (No Repeat) (Normal Dungeon)'),
(11492, 0, 13, 14, 2, 0, 100, 515, 0, 40, 0, 0, '', 28, 22688, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Alzzin the Wildshaper - Between 0-40% Health - Remove Aura \'Tree Form\' (No Repeat) (Normal Dungeon)'),
(11492, 0, 14, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 23, 0, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Alzzin the Wildshaper - Between 0-40% Health - Decrement Phase By 2 (No Repeat) (Normal Dungeon)'),
(14322, 0, 0, 0, 0, 0, 100, 2, 2000, 6000, 7000, 10000, '', 11, 15577, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Stomper Kreeg - In Combat - Cast \'Whirlwind\' (Normal Dungeon)'),
(14322, 0, 1, 0, 0, 0, 100, 2, 7000, 12000, 15000, 22000, '', 11, 22833, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stomper Kreeg - In Combat - Cast \'Booze Spit\' (Normal Dungeon)'),
(14322, 0, 2, 0, 0, 0, 100, 2, 12000, 15000, 12000, 16000, '', 11, 16740, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stomper Kreeg - In Combat - Cast \'War Stomp\' (Normal Dungeon)'),
(14322, 0, 3, 4, 2, 0, 100, 3, 0, 30, 0, 0, '', 11, 8269, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stomper Kreeg - Between 0-30% Health - Cast \'Frenzy\' (No Repeat) (Normal Dungeon)'),
(14322, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stomper Kreeg - Between 0-30% Health - Say Line 0 (No Repeat) (Normal Dungeon)'),
(14322, 0, 5, 0, 2, 0, 100, 3, 0, 15, 0, 0, '', 11, 22835, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stomper Kreeg - Between 0-15% Health - Cast \'Drunken Rage\' (No Repeat) (Normal Dungeon)'),
(14322, 0, 6, 0, 1, 0, 100, 512, 1000, 1000, 20000, 20000, '', 80, 1432200, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stomper Kreeg - Out of Combat - Run Script'),
(15146, 0, 2, 0, 0, 0, 100, 2, 3000, 4000, 8000, 8000, '', 11, 24616, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Mad Voidwalker - In Combat - Cast \'Shadow Shock\' (Normal Dungeon)'),
(15146, 0, 1, 0, 0, 0, 100, 2, 7000, 9000, 11000, 13000, '', 11, 24614, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Mad Voidwalker - In Combat - Cast \'Consuming Shadows\' (Normal Dungeon)'),
(15146, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, '', 89, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mad Voidwalker - On Respawn - Start Random Movement'),
(15146, 0, 3, 0, 1, 0, 100, 512, 0, 0, 0, 0, '', 41, 180000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mad Voidwalker - Out of Combat - Despawn In 180000 ms'),
(16409, 0, 0, 0, 0, 0, 70, 2, 17000, 17000, 17000, 17000, '', 11, 29582, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 'Phantom Guest - In Combat - Cast \'Throw\' (No Repeat)'),
(16409, 0, 1, 0, 0, 0, 70, 2, 20000, 20000, 20000, 20000, '', 11, 29580, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Phantom Guest - In Combat - Cast \'Heal\' (No Repeat)'),
(16409, 0, 2, 0, 0, 0, 70, 2, 13000, 13000, 13000, 13000, '', 11, 29583, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Phantom Guest - In Combat - Cast \'Impale\' (No Repeat)'),
(16409, 0, 3, 0, 0, 0, 70, 2, 22000, 22000, 22000, 22000, '', 11, 29928, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Phantom Guest - In Combat - Cast \'Immolate\' (No Repeat)'),
(16409, 0, 4, 0, 0, 0, 70, 2, 30000, 30000, 30000, 30000, '', 11, 29492, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Phantom Guest - In Combat - Cast \'Searing Pain\' (No Repeat)'),
(16409, 0, 5, 0, 0, 0, 70, 2, 45000, 45000, 45000, 45000, '', 11, 29930, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Phantom Guest - In Combat - Cast \'Curse of Agony\' (No Repeat)'),
(16409, 0, 6, 0, 6, 0, 10, 0, 0, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Phantom Guest - On Just Died - Say Line 0 (No Repeat)'),
(16409, 0, 7, 0, 4, 0, 10, 0, 0, 0, 0, 0, '', 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Phantom Guest - On Aggro - Talk'),
(16522, 0, 0, 0, 0, 0, 100, 0, 0, 0, 3400, 4700, '', 11, 9053, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Surveyor Candress - In Combat - Cast \'Fireball\''),
(16522, 0, 2, 0, 25, 0, 100, 0, 0, 0, 0, 0, '', 11, 31515, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Surveyor Candress - On Reset - Cast \'Red Beam\''),
(16522, 0, 1, 0, 4, 0, 61, 1, 0, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Surveyor Candress - On Aggro - Say Line 0 (No Repeat)'),
(16876, 0, 0, 0, 0, 0, 100, 0, 2000, 4000, 5000, 8000, '', 11, 34113, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Bonechewer Mutant - In Combat - Cast \'Bonechewer Bite\' (No Repeat)'),
(16876, 0, 1, 0, 2, 0, 100, 1, 0, 50, 0, 0, '', 11, 8599, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bonechewer Mutant - Between 0-50% Health - Cast \'Enrage\' (No Repeat)'),
(16876, 0, 2, 3, 2, 0, 100, 1, 0, 20, 0, 0, '', 11, 34114, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bonechewer Mutant - Between 0-20% Health - Cast \'Instability\' (No Repeat)'),
(16876, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bonechewer Mutant - Between 0-20% Health - Say Line 0 (No Repeat)'),
(17371, 0, 0, 0, 1, 0, 100, 519, 0, 0, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadowmoon Warlock - Out of Combat - Disable Combat Movement'),
(17371, 0, 1, 2, 4, 0, 100, 0, 0, 0, 0, 0, '', 11, 12739, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Shadowmoon Warlock - On Aggro - Cast \'Shadow Bolt\''),
(17371, 0, 2, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadowmoon Warlock - On Aggro - Increment Phase By 1'),
(17371, 0, 3, 0, 9, 0, 100, 2, 0, 40, 3300, 4900, '', 11, 12739, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Shadowmoon Warlock - Within 0-40 Range - Cast \'Shadow Bolt\''),
(17371, 0, 4, 5, 4, 0, 100, 0, 0, 0, 0, 0, '', 11, 15472, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Shadowmoon Warlock - On Aggro - Cast \'Shadow Bolt\''),
(17371, 0, 5, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadowmoon Warlock - On Aggro - Increment Phase By 1'),
(17371, 0, 6, 0, 9, 0, 100, 4, 0, 40, 3300, 4900, '', 11, 15472, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Shadowmoon Warlock - Within 0-40 Range - Cast \'Shadow Bolt\''),
(17371, 0, 7, 8, 3, 0, 100, 512, 0, 15, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadowmoon Warlock - Between 0-15% Mana - Enable Combat Movement'),
(17371, 0, 8, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadowmoon Warlock - Between 0-15% Mana - Increment Phase By 1'),
(17371, 0, 9, 0, 9, 0, 100, 519, 35, 80, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadowmoon Warlock - Within 35-80 Range - Enable Combat Movement'),
(17371, 0, 10, 0, 9, 0, 100, 519, 5, 15, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadowmoon Warlock - Within 5-15 Range - Disable Combat Movement'),
(17371, 0, 11, 0, 9, 0, 100, 519, 0, 5, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadowmoon Warlock - Within 0-5 Range - Enable Combat Movement'),
(17371, 0, 12, 0, 3, 0, 100, 518, 30, 100, 100, 100, '', 23, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadowmoon Warlock - Between 30-100% Mana - Decrement Phase By 1'),
(17371, 0, 13, 0, 0, 0, 100, 2, 1100, 7800, 14800, 30100, '', 11, 32197, 33, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Shadowmoon Warlock - In Combat - Cast \'Corruption\''),
(17371, 0, 14, 0, 0, 0, 100, 4, 1100, 7800, 14800, 30100, '', 11, 37113, 33, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Shadowmoon Warlock - In Combat - Cast \'Corruption\''),
(17371, 0, 15, 0, 0, 0, 100, 6, 6600, 10700, 14900, 14900, '', 11, 13338, 33, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Shadowmoon Warlock - In Combat - Cast \'Curse of Tongues\''),
(17725, 0, 0, 1, 4, 0, 100, 7, 0, 0, 0, 0, '', 11, 34161, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Underbog Lurker - On Aggro - Cast \'Wild Growth\' (No Repeat) (Dungeon)'),
(17725, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Underbog Lurker - On Aggro - Say Line 0 (No Repeat) (Dungeon)'),
(17725, 0, 2, 3, 0, 0, 100, 519, 5800, 10800, 0, 0, '', 28, 89344, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Underbog Lurker - In Combat - Remove Aura \'Living Spirit\' (No Repeat) (Dungeon)'),
(17725, 0, 3, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Underbog Lurker - In Combat - Say Line 1 (No Repeat) (Dungeon)'),
(17826, 0, 1, 0, 0, 0, 100, 6, 35000, 38000, 30000, 40000, '', 11, 18813, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Swamplord Musel\'ek - In Combat - Cast \'Knock Away\' (No Repeat) (Dungeon)'),
(17826, 0, 2, 0, 0, 0, 100, 6, 500, 1000, 2300, 3900, '', 11, 22907, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Swamplord Musel\'ek - In Combat - Cast \'Shoot\' (No Repeat) (Dungeon)'),
(17826, 0, 3, 0, 0, 0, 100, 6, 4000, 8000, 12000, 16000, '', 11, 31615, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 'Swamplord Musel\'ek - In Combat - Cast \'Hunter\'s Mark\' (No Repeat) (Dungeon)'),
(17826, 0, 4, 0, 0, 0, 100, 6, 4000, 8000, 12000, 16000, '', 11, 31946, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Swamplord Musel\'ek - In Combat - Cast \'Throw Freezing Trap\' (No Repeat) (Dungeon)'),
(17826, 0, 5, 6, 0, 0, 100, 6, 12500, 21500, 20000, 30000, '', 11, 31623, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Swamplord Musel\'ek - In Combat - Cast \'Aimed Shot\' (Dungeon)'),
(17826, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, '', 40, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Swamplord Musel\'ek - In Combat - Set Sheath Ranged (Dungeon)'),
(17826, 0, 7, 8, 0, 0, 100, 6, 12500, 21500, 20000, 30000, '', 11, 34974, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Swamplord Musel\'ek - In Combat - Cast \'Multi-Shot\' (Dungeon)'),
(17826, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, '', 40, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Swamplord Musel\'ek - In Combat - Set Sheath Ranged (Dungeon)'),
(17826, 0, 9, 0, 4, 0, 100, 6, 0, 0, 0, 0, '', 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Swamplord Musel\'ek - On Aggro - Say Line 1 (Dungeon)'),
(17826, 0, 10, 0, 5, 0, 100, 6, 5, 5000, 5000, 1, '', 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Swamplord Musel\'ek - On Killed Unit - Say Line 2 (Dungeon)'),
(17826, 0, 11, 12, 6, 0, 100, 6, 0, 0, 0, 0, '', 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Swamplord Musel\'ek - On Just Died - Say Line 3 (Dungeon)'),
(17826, 0, 12, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 45, 0, 1, 0, 0, 0, 0, 19, 17827, 100, 0, 0, 0, 0, 0, 'Swamplord Musel\'ek - On Just Died - Set Data 0 1 (Dungeon)'),
(17826, 0, 13, 14, 38, 0, 100, 518, 0, 1, 0, 0, '', 70, 0, 0, 0, 0, 0, 0, 19, 17827, 100, 1, 0, 0, 0, 0, 'Swamplord Musel\'ek - On Data Set 0 1 - Respawn Closest Creature \'Claw\' (Dungeon)'),
(17826, 0, 14, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Swamplord Musel\'ek - On Data Set 0 1 - Say Line 0 (Dungeon)'),
(17892, 0, 0, 0, 1, 0, 100, 519, 0, 0, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Infinite Chronomancer - Out of Combat - Disable Combat Movement (Phase 1) (No Repeat)'),
(17892, 0, 1, 0, 1, 0, 100, 7, 1000, 1000, 0, 0, '', 11, 31326, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Infinite Chronomancer - Out of Combat - Cast \'Corrupt Medivh\' (Phase 1) (No Repeat)'),
(17892, 0, 2, 0, 0, 0, 20, 7, 0, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Infinite Chronomancer - In Combat - Say Line 0 (Phase 1) (No Repeat)'),
(17892, 0, 3, 0, 4, 0, 100, 519, 0, 0, 0, 0, '', 28, 31326, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Infinite Chronomancer - On Aggro - Remove Aura \'Corrupt Medivh\' (Phase 1) (No Repeat)'),
(17892, 0, 4, 0, 4, 0, 100, 519, 0, 0, 0, 0, '', 30, 1, 1, 3, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Infinite Chronomancer - On Aggro - Set Random Phase(1, 1, 3) (Phase 1) (No Repeat)'),
(17892, 0, 5, 8, 4, 2, 100, 3, 0, 0, 0, 0, '', 11, 15497, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Infinite Chronomancer - On Aggro - Cast \'Frostbolt\' (Phase 2) (No Repeat) (Normal Dungeon)'),
(17892, 0, 6, 7, 9, 2, 100, 2, 0, 40, 2900, 5400, '', 11, 15497, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Infinite Chronomancer - Within 0-40 Range - Cast \'Frostbolt\' (Phase 2) (No Repeat) (Normal Dungeon)'),
(17892, 0, 7, 0, 61, 2, 100, 3, 0, 0, 0, 0, '', 11, 12675, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Infinite Chronomancer - On Aggro - Cast \'Frostbolt\' (Phase 2) (No Repeat) (Normal Dungeon)'),
(17892, 0, 8, 0, 61, 2, 100, 512, 0, 0, 0, 0, '', 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Infinite Chronomancer - On Aggro - Increment Phase By 1 (Phase 2) (No Repeat) (Normal Dungeon)'),
(17892, 0, 9, 0, 9, 2, 100, 4, 0, 40, 2900, 5400, '', 11, 12675, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Infinite Chronomancer - Within 0-40 Range - Cast \'Frostbolt\' (Phase 2) (No Repeat) (Normal Dungeon)'),
(17892, 0, 10, 11, 3, 2, 100, 519, 0, 15, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Infinite Chronomancer - Between 0-15% Mana - Enable Combat Movement (Phase 2) (No Repeat) (Dungeon)'),
(17892, 0, 11, 0, 61, 2, 100, 512, 0, 0, 0, 0, '', 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Infinite Chronomancer - Between 0-15% Mana - Increment Phase By 1 (Phase 2) (No Repeat) (Dungeon)'),
(17892, 0, 12, 0, 9, 2, 100, 519, 35, 80, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Infinite Chronomancer - Within 35-80 Range - Enable Combat Movement (Phase 2) (No Repeat) (Dungeon)'),
(17892, 0, 13, 0, 9, 2, 100, 519, 5, 15, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Infinite Chronomancer - Within 5-15 Range - Disable Combat Movement (Phase 2) (No Repeat) (Dungeon)'),
(17892, 0, 14, 0, 9, 2, 100, 519, 0, 5, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Infinite Chronomancer - Within 0-5 Range - Enable Combat Movement (Phase 2) (No Repeat) (Dungeon)'),
(17892, 0, 15, 0, 0, 2, 100, 2, 3700, 12900, 33800, 39800, '', 11, 15063, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Infinite Chronomancer - In Combat - Cast \'Frost Nova\' (Phase 2) (No Repeat) (Dungeon)'),
(17892, 0, 16, 0, 0, 2, 100, 4, 3600, 8300, 22200, 25700, '', 11, 15531, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Infinite Chronomancer - In Combat - Cast \'Frost Nova\' (Phase 2) (No Repeat) (Dungeon)'),
(17892, 0, 17, 0, 3, 4, 100, 518, 30, 100, 100, 100, '', 23, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Infinite Chronomancer - Between 30-100% Mana - Decrement Phase By 1 (Phase 2) (No Repeat) (Dungeon)'),
(17892, 0, 18, 21, 4, 8, 100, 3, 0, 0, 0, 0, '', 11, 15124, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Infinite Chronomancer - On Aggro - Cast \'Arcane Bolt\' (Phase 8) (No Repeat) (Normal Dungeon)'),
(17892, 0, 19, 20, 9, 8, 100, 2, 0, 40, 2900, 5400, '', 11, 15124, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Infinite Chronomancer - Within 0-40 Range - Cast \'Arcane Bolt\' (Phase 8) (No Repeat) (Normal Dungeon)'),
(17892, 0, 20, 0, 61, 8, 100, 0, 0, 0, 0, 0, '', 11, 15230, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Infinite Chronomancer - On Aggro - Cast \'Arcane Bolt\' (Phase 8) (No Repeat) (Normal Dungeon)'),
(17892, 0, 21, 0, 61, 8, 100, 512, 0, 0, 0, 0, '', 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Infinite Chronomancer - On Aggro - Increment Phase By 1 (Phase 8) (No Repeat) (Normal Dungeon)'),
(17892, 0, 22, 0, 9, 8, 100, 4, 0, 40, 1200, 3400, '', 11, 15230, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Infinite Chronomancer - Within 0-40 Range - Cast \'Arcane Bolt\' (Phase 8) (No Repeat) (Normal Dungeon)'),
(17892, 0, 23, 24, 3, 8, 100, 519, 0, 15, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Infinite Chronomancer - Between 0-15% Mana - Enable Combat Movement (Phase 8) (No Repeat) (Dungeon)'),
(17892, 0, 24, 0, 61, 8, 100, 512, 0, 0, 0, 0, '', 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Infinite Chronomancer - Between 0-15% Mana - Increment Phase By 1 (Phase 8) (No Repeat) (Dungeon)'),
(17892, 0, 25, 0, 9, 8, 100, 519, 35, 80, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Infinite Chronomancer - Within 35-80 Range - Enable Combat Movement (Phase 8) (No Repeat) (Dungeon)'),
(17892, 0, 26, 0, 9, 8, 100, 519, 5, 15, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Infinite Chronomancer - Within 5-15 Range - Disable Combat Movement (Phase 8) (No Repeat) (Dungeon)'),
(17892, 0, 27, 0, 9, 8, 100, 519, 0, 5, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Infinite Chronomancer - Within 0-5 Range - Enable Combat Movement (Phase 8) (No Repeat) (Dungeon)'),
(17892, 0, 28, 0, 0, 8, 100, 2, 8600, 18200, 9500, 10100, '', 11, 33860, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Infinite Chronomancer - In Combat - Cast \'Arcane Explosion\' (Phase 8) (No Repeat) (Dungeon)'),
(17892, 0, 29, 0, 0, 8, 100, 2, 8600, 18200, 8000, 10100, '', 11, 33623, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Infinite Chronomancer - In Combat - Cast \'Arcane Explosion\' (Phase 8) (No Repeat) (Dungeon)'),
(17892, 0, 30, 0, 3, 0, 100, 518, 30, 100, 100, 100, '', 23, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Infinite Chronomancer - Between 30-100% Mana - Decrement Phase By 1 (Phase 8) (No Repeat) (Dungeon)'),
(17892, 0, 31, 0, 7, 0, 100, 519, 0, 0, 0, 0, '', 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Infinite Chronomancer - On Evade - Set Event Phase 0 (Phase 8) (No Repeat) (Dungeon)'),
(17892, 0, 32, 0, 7, 0, 100, 7, 0, 0, 0, 0, '', 11, 31326, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Infinite Chronomancer - On Evade - Cast \'Corrupt Medivh\' (Phase 8) (No Repeat) (Dungeon)'),
(18261, 0, 0, 0, 1, 0, 100, 1, 0, 0, 0, 0, '', 11, 32281, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lantresor of the Blade - Out of Combat - Cast \'Burning Blade Blademaster\' (Phase 1) (No Repeat)'),
(18261, 0, 1, 3, 62, 0, 100, 512, 7676, 0, 0, 0, '', 26, 10108, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Lantresor of the Blade - On Gossip Option 0 Selected - Quest Credit \'Diplomatic Measures\''),
(18261, 0, 2, 3, 62, 0, 100, 512, 7676, 0, 0, 0, '', 26, 10107, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Lantresor of the Blade - On Gossip Option 0 Selected - Quest Credit \'Diplomatic Measures\''),
(18261, 0, 3, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Lantresor of the Blade - On Gossip Option 0 Selected - Close Gossip'),
(18450, 0, 0, 0, 1, 0, 100, 513, 0, 0, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shienor Sorcerer - Out of Combat - Disable Combat Movement (No Repeat)'),
(18450, 0, 1, 0, 0, 0, 100, 1, 0, 0, 0, 0, '', 11, 32924, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shienor Sorcerer - In Combat - Cast \'Power of Kran\'aish\' (No Repeat)'),
(18450, 0, 2, 3, 4, 0, 100, 1, 0, 0, 0, 0, '', 11, 26098, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Shienor Sorcerer - On Aggro - Cast \'Lightning Bolt\' (No Repeat)'),
(18450, 0, 3, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shienor Sorcerer - On Aggro - Increment Phase By 1 (No Repeat)'),
(18450, 0, 4, 0, 9, 1, 100, 0, 0, 40, 2400, 3800, '', 11, 26098, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Shienor Sorcerer - Within 0-40 Range - Cast \'Lightning Bolt\' (No Repeat)'),
(18450, 0, 5, 6, 3, 1, 100, 513, 0, 15, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shienor Sorcerer - Between 0-15% Mana - Enable Combat Movement (Phase 1) (No Repeat)'),
(18450, 0, 6, 0, 61, 1, 100, 512, 0, 0, 0, 0, '', 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shienor Sorcerer - Between 0-15% Mana - Increment Phase By 1 (Phase 1) (No Repeat)'),
(18450, 0, 7, 0, 9, 1, 100, 513, 35, 80, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shienor Sorcerer - Within 35-80 Range - Enable Combat Movement (Phase 1) (No Repeat)'),
(18450, 0, 8, 0, 9, 1, 100, 513, 5, 15, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shienor Sorcerer - Within 5-15 Range - Disable Combat Movement (Phase 1) (No Repeat)'),
(18450, 0, 9, 0, 9, 1, 100, 513, 0, 5, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shienor Sorcerer - Within 0-5 Range - Enable Combat Movement (Phase 1) (No Repeat)'),
(18450, 0, 10, 0, 3, 4, 100, 512, 30, 100, 100, 100, '', 23, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shienor Sorcerer - Between 30-100% Mana - Decrement Phase By 1 (Phase 1) (No Repeat)'),
(18450, 0, 11, 0, 0, 0, 100, 0, 6000, 10000, 12000, 16000, '', 11, 32907, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Shienor Sorcerer - In Combat - Cast \'Arakkoa Blast\' (Phase 1) (No Repeat)'),
(18450, 0, 12, 0, 0, 0, 100, 0, 10000, 14000, 18000, 25000, '', 11, 6728, 1, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 'Shienor Sorcerer - In Combat - Cast \'Enveloping Winds\' (Phase 1) (No Repeat)'),
(18450, 0, 13, 14, 2, 0, 100, 513, 0, 15, 0, 0, '', 22, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shienor Sorcerer - Between 0-15% Health - Set Event Phase 3 (No Repeat)'),
(18450, 0, 14, 15, 61, 0, 100, 512, 0, 0, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shienor Sorcerer - Between 0-15% Health - Enable Combat Movement (No Repeat)'),
(18450, 0, 15, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 25, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Shienor Sorcerer - Between 0-15% Health - Flee For Assist (No Repeat)'),
(18455, 0, 0, 0, 4, 0, 100, 1, 0, 0, 0, 0, '', 11, 32924, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shalassi Oracle - On Aggro - Cast \'Power of Kran\'aish\' (No Repeat)'),
(18455, 0, 1, 0, 0, 0, 100, 0, 5000, 7000, 7000, 11000, '', 11, 32907, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Shalassi Oracle - In Combat - Cast \'Arakkoa Blast\' (No Repeat)'),
(18455, 0, 2, 0, 0, 0, 100, 0, 2000, 4000, 40000, 45000, '', 11, 6535, 1, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Shalassi Oracle - In Combat - Cast \'Lightning Cloud\' (No Repeat)'),
(18455, 0, 3, 0, 0, 0, 100, 0, 8000, 11000, 13000, 16000, '', 11, 12058, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Shalassi Oracle - In Combat - Cast \'Chain Lightning\' (No Repeat)'),
(18455, 0, 4, 0, 0, 0, 100, 0, 12000, 14000, 13000, 16000, '', 11, 11824, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Shalassi Oracle - In Combat - Cast \'Shock\' (No Repeat)'),
(18539, 0, 0, 0, 1, 0, 100, 513, 0, 0, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ashkaz - Out of Combat - Disable Combat Movement (Phase 2)'),
(18539, 0, 1, 0, 0, 0, 100, 1, 0, 0, 0, 0, '', 11, 32924, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ashkaz - In Combat - Cast \'Power of Kran\'aish\' (Phase 2)'),
(18539, 0, 2, 3, 4, 0, 100, 1, 0, 0, 0, 0, '', 11, 26098, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Ashkaz - On Aggro - Cast \'Lightning Bolt\' (No Repeat)'),
(18539, 0, 3, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ashkaz - On Aggro - Increment Phase By 1 (No Repeat)'),
(18539, 0, 4, 0, 9, 1, 100, 0, 0, 40, 2400, 3800, '', 11, 26098, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Ashkaz - Within 0-40 Range - Cast \'Lightning Bolt\' (No Repeat)'),
(18539, 0, 5, 6, 3, 1, 100, 513, 0, 15, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ashkaz - Between 0-15% Mana - Enable Combat Movement (Phase 1) (No Repeat)'),
(18539, 0, 6, 0, 61, 1, 100, 512, 0, 0, 0, 0, '', 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ashkaz - Between 0-15% Mana - Increment Phase By 1 (Phase 1) (No Repeat)'),
(18539, 0, 7, 0, 9, 1, 100, 513, 35, 80, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ashkaz - Within 35-80 Range - Enable Combat Movement (Phase 1) (No Repeat)'),
(18539, 0, 8, 0, 9, 1, 100, 513, 5, 15, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ashkaz - Within 5-15 Range - Disable Combat Movement (Phase 1) (No Repeat)'),
(18539, 0, 9, 0, 9, 1, 100, 513, 0, 5, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ashkaz - Within 0-5 Range - Enable Combat Movement (Phase 1) (No Repeat)'),
(18539, 0, 10, 0, 3, 2, 100, 512, 30, 100, 100, 100, '', 23, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ashkaz - Between 30-100% Mana - Decrement Phase By 1 (Phase 1) (No Repeat)'),
(18539, 0, 11, 0, 0, 0, 100, 0, 6000, 10000, 12000, 16000, '', 11, 32907, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Ashkaz - In Combat - Cast \'Arakkoa Blast\' (Phase 1) (No Repeat)'),
(18539, 0, 12, 0, 0, 0, 100, 0, 10000, 14000, 18000, 25000, '', 11, 6728, 1, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 'Ashkaz - In Combat - Cast \'Enveloping Winds\' (Phase 1) (No Repeat)'),
(18539, 0, 13, 14, 2, 0, 100, 513, 0, 15, 0, 0, '', 22, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ashkaz - Between 0-15% Health - Set Event Phase 3 (No Repeat)'),
(18539, 0, 14, 15, 61, 0, 100, 513, 0, 15, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ashkaz - Between 0-15% Health - Enable Combat Movement (No Repeat)'),
(18539, 0, 15, 0, 61, 0, 100, 513, 0, 15, 0, 0, '', 25, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Ashkaz - Between 0-15% Health - Flee For Assist (No Repeat)'),
(18638, 0, 0, 0, 1, 0, 100, 519, 0, 0, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cabal Zealot - Out of Combat - Disable Combat Movement (Phase 1) (No Repeat) (Dungeon)'),
(18638, 0, 1, 2, 4, 0, 100, 3, 0, 0, 0, 0, '', 11, 12471, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cabal Zealot - On Aggro - Cast \'Shadow Bolt\' (No Repeat) (Normal Dungeon)'),
(18638, 0, 2, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cabal Zealot - On Aggro - Increment Phase By 1 (No Repeat) (Normal Dungeon)'),
(18638, 0, 3, 0, 9, 1, 100, 2, 0, 40, 2400, 3800, '', 11, 12471, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cabal Zealot - Within 0-40 Range - Cast \'Shadow Bolt\' (No Repeat) (Normal Dungeon)'),
(18638, 0, 4, 5, 4, 0, 100, 5, 0, 0, 0, 0, '', 11, 15472, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cabal Zealot - On Aggro - Cast \'Shadow Bolt\' (No Repeat) (Heroic Dungeon)'),
(18638, 0, 5, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cabal Zealot - On Aggro - Increment Phase By 1 (No Repeat) (Heroic Dungeon)'),
(18638, 0, 6, 0, 9, 1, 100, 4, 0, 40, 2400, 3800, '', 11, 15472, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cabal Zealot - Within 0-40 Range - Cast \'Shadow Bolt\' (No Repeat) (Heroic Dungeon)'),
(18638, 0, 7, 8, 3, 1, 100, 519, 0, 15, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cabal Zealot - Between 0-15% Mana - Enable Combat Movement (Phase 1) (No Repeat) (Dungeon)'),
(18638, 0, 8, 0, 61, 1, 100, 512, 0, 0, 0, 0, '', 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cabal Zealot - Between 0-15% Mana - Increment Phase By 1 (Phase 1) (No Repeat) (Dungeon)'),
(18638, 0, 9, 0, 9, 1, 100, 519, 35, 80, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cabal Zealot - Within 35-80 Range - Enable Combat Movement (Phase 1) (No Repeat) (Dungeon)'),
(18638, 0, 10, 0, 9, 1, 100, 519, 5, 15, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cabal Zealot - Within 5-15 Range - Disable Combat Movement (Phase 1) (No Repeat) (Dungeon)'),
(18638, 0, 11, 0, 9, 1, 100, 519, 0, 5, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cabal Zealot - Within 0-5 Range - Enable Combat Movement (Phase 1) (No Repeat) (Dungeon)'),
(18638, 0, 12, 0, 3, 2, 100, 518, 30, 100, 100, 100, '', 23, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cabal Zealot - Between 30-100% Mana - Decrement Phase By 1 (Phase 1) (No Repeat) (Dungeon)'),
(18638, 0, 13, 14, 2, 0, 100, 519, 0, 20, 0, 0, '', 22, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cabal Zealot - Between 0-20% Health - Set Event Phase 3 (No Repeat) (Dungeon)'),
(18638, 0, 14, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 11, 33499, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cabal Zealot - Between 0-20% Health - Cast \'Shape of the Beast\' (No Repeat) (Dungeon)'),
(18870, 0, 0, 0, 11, 0, 100, 1, 0, 0, 0, 0, '', 11, 34302, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - On Respawn - Cast \'Coalesce\' (No Repeat)'),
(18870, 0, 1, 0, 0, 0, 100, 519, 0, 0, 0, 0, '', 30, 1, 2, 3, 4, 5, 6, 1, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - In Combat - Set Random Phase(1, 2, 3, 4, 5, 6) (No Repeat)'),
(18870, 0, 2, 3, 8, 0, 100, 1, 0, 2, 0, 0, '', 11, 34336, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - On Spellhit - Cast \'Damage Reduction: Holy\' (No Repeat)'),
(18870, 0, 3, 4, 61, 0, 100, 512, 0, 0, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - On Spellhit - Disable Combat Movement (No Repeat)'),
(18870, 0, 4, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - On Spellhit - Set Event Phase 1 (No Repeat)'),
(18870, 0, 5, 6, 8, 0, 100, 1, 0, 4, 0, 0, '', 11, 34333, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - On Spellhit - Cast \'Damage Reduction: Fire\' (No Repeat)'),
(18870, 0, 6, 7, 61, 0, 100, 512, 0, 0, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - On Spellhit - Disable Combat Movement (No Repeat)'),
(18870, 0, 7, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - On Spellhit - Set Event Phase 2 (No Repeat)'),
(18870, 0, 8, 9, 8, 0, 100, 1, 0, 8, 0, 0, '', 11, 34335, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - On Spellhit - Cast \'Damage Reduction: Nature\' (No Repeat)'),
(18870, 0, 9, 10, 61, 0, 100, 512, 0, 0, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - On Spellhit - Disable Combat Movement (No Repeat)'),
(18870, 0, 10, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 22, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - On Spellhit - Set Event Phase 3 (No Repeat)'),
(18870, 0, 11, 12, 8, 0, 100, 1, 0, 16, 0, 0, '', 11, 34334, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - On Spellhit - Cast \'Damage Reduction: Frost\' (No Repeat)'),
(18870, 0, 12, 13, 61, 0, 100, 512, 0, 0, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - On Spellhit - Disable Combat Movement (No Repeat)'),
(18870, 0, 13, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 22, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - On Spellhit - Set Event Phase 4 (No Repeat)'),
(18870, 0, 14, 15, 8, 0, 100, 1, 0, 32, 0, 0, '', 11, 34338, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - On Spellhit - Cast \'Damage Reduction: Shadow\' (No Repeat)'),
(18870, 0, 15, 16, 61, 0, 100, 512, 0, 0, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - On Spellhit - Disable Combat Movement (No Repeat)'),
(18870, 0, 16, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 22, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - On Spellhit - Set Event Phase 5 (No Repeat)'),
(18870, 0, 17, 18, 8, 0, 100, 1, 0, 64, 0, 0, '', 11, 34331, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - On Spellhit - Cast \'Damage Reduction: Arcane\' (No Repeat)'),
(18870, 0, 18, 19, 61, 0, 100, 512, 0, 0, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - On Spellhit - Disable Combat Movement (No Repeat)'),
(18870, 0, 19, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 22, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - On Spellhit - Set Event Phase 6 (No Repeat)'),
(18870, 0, 20, 0, 9, 1, 100, 0, 0, 40, 2000, 3000, '', 11, 34346, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - Within 0-40 Range - Cast \'Holy Bolt\' (No Repeat)'),
(18870, 0, 21, 22, 3, 1, 100, 513, 0, 15, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - Between 0-15% Mana - Enable Combat Movement (Phase 1) (No Repeat)'),
(18870, 0, 22, 0, 61, 1, 100, 512, 0, 0, 0, 0, '', 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - Between 0-15% Mana - Increment Phase By 1 (Phase 1) (No Repeat)'),
(18870, 0, 23, 0, 9, 1, 100, 512, 35, 80, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - Within 35-80 Range - Enable Combat Movement (Phase 1) (No Repeat)'),
(18870, 0, 24, 0, 9, 1, 100, 512, 5, 15, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - Within 5-15 Range - Disable Combat Movement (Phase 1) (No Repeat)'),
(18870, 0, 25, 0, 9, 1, 100, 512, 0, 5, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - Within 0-5 Range - Enable Combat Movement (Phase 1) (No Repeat)'),
(18870, 0, 26, 0, 9, 2, 100, 0, 0, 40, 2000, 3000, '', 11, 34348, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - Within 0-40 Range - Cast \'Fireball\' (Phase 1) (No Repeat)'),
(18870, 0, 27, 28, 3, 2, 100, 513, 0, 15, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - Between 0-15% Mana - Enable Combat Movement (Phase 2) (No Repeat)'),
(18870, 0, 28, 0, 61, 2, 100, 513, 0, 15, 0, 0, '', 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - Between 0-15% Mana - Increment Phase By 1 (Phase 2) (No Repeat)'),
(18870, 0, 29, 0, 9, 2, 100, 512, 35, 80, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - Within 35-80 Range - Enable Combat Movement (Phase 2) (No Repeat)'),
(18870, 0, 30, 0, 9, 2, 100, 512, 5, 15, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - Within 5-15 Range - Disable Combat Movement (Phase 2) (No Repeat)'),
(18870, 0, 31, 0, 9, 2, 100, 512, 0, 5, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - Within 0-5 Range - Enable Combat Movement (Phase 2) (No Repeat)'),
(18870, 0, 32, 0, 9, 4, 100, 0, 0, 40, 2000, 3000, '', 11, 34345, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - Within 0-40 Range - Cast \'Lightning Bolt\' (Phase 2) (No Repeat)'),
(18870, 0, 33, 34, 3, 4, 100, 513, 0, 15, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - Between 0-15% Mana - Enable Combat Movement (Phase 4) (No Repeat)'),
(18870, 0, 34, 0, 61, 4, 100, 512, 0, 0, 0, 0, '', 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - Between 0-15% Mana - Increment Phase By 1 (Phase 4) (No Repeat)'),
(18870, 0, 35, 0, 9, 4, 100, 512, 35, 80, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - Within 35-80 Range - Enable Combat Movement (Phase 4) (No Repeat)'),
(18870, 0, 36, 0, 9, 4, 100, 512, 5, 15, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - Within 5-15 Range - Disable Combat Movement (Phase 4) (No Repeat)'),
(18870, 0, 37, 0, 9, 4, 100, 512, 0, 5, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - Within 0-5 Range - Enable Combat Movement (Phase 4) (No Repeat)'),
(18870, 0, 38, 0, 9, 8, 100, 0, 0, 40, 2000, 3000, '', 11, 34347, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - Within 0-40 Range - Cast \'Frostbolt\' (Phase 4) (No Repeat)'),
(18870, 0, 39, 40, 3, 8, 100, 513, 0, 15, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - Between 0-15% Mana - Enable Combat Movement (Phase 8) (No Repeat)'),
(18870, 0, 40, 0, 61, 8, 100, 512, 0, 0, 0, 0, '', 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - Between 0-15% Mana - Increment Phase By 1 (Phase 8) (No Repeat)'),
(18870, 0, 41, 0, 9, 8, 100, 512, 35, 80, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - Within 35-80 Range - Enable Combat Movement (Phase 8) (No Repeat)'),
(18870, 0, 42, 0, 9, 8, 100, 512, 5, 15, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - Within 5-15 Range - Disable Combat Movement (Phase 8) (No Repeat)'),
(18870, 0, 43, 0, 9, 8, 100, 512, 0, 5, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - Within 0-5 Range - Enable Combat Movement (Phase 8) (No Repeat)'),
(18870, 0, 44, 0, 9, 16, 100, 0, 0, 40, 2000, 3000, '', 11, 34344, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - Within 0-40 Range - Cast \'Shadow Bolt\' (Phase 8) (No Repeat)'),
(18870, 0, 45, 46, 3, 16, 100, 513, 0, 15, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - Between 0-15% Mana - Enable Combat Movement (Phase 16) (No Repeat)'),
(18870, 0, 46, 0, 61, 16, 100, 512, 0, 0, 0, 0, '', 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - Between 0-15% Mana - Increment Phase By 1 (Phase 16) (No Repeat)'),
(18870, 0, 47, 0, 9, 16, 100, 512, 35, 80, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - Within 35-80 Range - Enable Combat Movement (Phase 16) (No Repeat)'),
(18870, 0, 48, 0, 9, 16, 100, 512, 5, 15, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - Within 5-15 Range - Disable Combat Movement (Phase 16) (No Repeat)'),
(18870, 0, 49, 0, 9, 16, 100, 512, 0, 5, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - Within 0-5 Range - Enable Combat Movement (Phase 16) (No Repeat)'),
(18870, 0, 50, 0, 9, 32, 100, 0, 0, 30, 2400, 3800, '', 11, 34447, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - Within 0-30 Range - Cast \'Arcane Missiles\' (Phase 16) (No Repeat)'),
(18870, 0, 51, 52, 3, 32, 100, 513, 0, 15, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - Between 0-15% Mana - Enable Combat Movement (Phase 32) (No Repeat)'),
(18870, 0, 52, 0, 61, 32, 100, 513, 0, 15, 0, 0, '', 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - Between 0-15% Mana - Increment Phase By 1 (Phase 32) (No Repeat)'),
(18870, 0, 53, 0, 9, 32, 100, 512, 25, 80, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - Within 25-80 Range - Enable Combat Movement (Phase 32) (No Repeat)'),
(18870, 0, 54, 0, 9, 32, 100, 512, 5, 15, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - Within 5-15 Range - Disable Combat Movement (Phase 32) (No Repeat)'),
(18870, 0, 55, 0, 9, 32, 100, 512, 0, 5, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - Within 0-5 Range - Enable Combat Movement (Phase 32) (No Repeat)'),
(18870, 0, 56, 0, 0, 0, 100, 0, 9000, 13000, 14000, 18000, '', 11, 22884, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Voidshrieker - In Combat - Cast \'Psychic Scream\' (Phase 32) (No Repeat)'),
(18995, 0, 0, 0, 1, 0, 100, 519, 0, 0, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Infinite Vanquisher - Out of Combat - Disable Combat Movement (No Repeat)'),
(18995, 0, 1, 0, 1, 0, 100, 7, 1000, 1000, 0, 0, '', 11, 31326, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Infinite Vanquisher - Out of Combat - Cast \'Corrupt Medivh\' (No Repeat)'),
(18995, 0, 2, 3, 4, 0, 100, 3, 0, 0, 0, 0, '', 11, 12739, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Infinite Vanquisher - On Aggro - Cast \'Shadow Bolt\' (No Repeat) (Normal Dungeon)'),
(18995, 0, 3, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Infinite Vanquisher - On Aggro - Increment Phase By 1 (No Repeat) (Normal Dungeon)'),
(18995, 0, 4, 0, 9, 1, 100, 2, 0, 40, 3500, 4700, '', 11, 12739, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Infinite Vanquisher - Within 0-40 Range - Cast \'Shadow Bolt\' (No Repeat) (Normal Dungeon)'),
(18995, 0, 5, 6, 4, 0, 100, 5, 0, 0, 0, 0, '', 11, 15472, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Infinite Vanquisher - On Aggro - Cast \'Shadow Bolt\' (No Repeat) (Heroic Dungeon)'),
(18995, 0, 6, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Infinite Vanquisher - On Aggro - Increment Phase By 1 (No Repeat) (Heroic Dungeon)'),
(18995, 0, 7, 0, 9, 1, 100, 4, 0, 40, 3500, 4700, '', 11, 15472, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Infinite Vanquisher - Within 0-40 Range - Cast \'Shadow Bolt\' (No Repeat) (Heroic Dungeon)'),
(18995, 0, 8, 9, 3, 1, 100, 519, 0, 15, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Infinite Vanquisher - Between 0-15% Mana - Enable Combat Movement (Phase 1) (No Repeat) (Dungeon)'),
(18995, 0, 9, 0, 61, 1, 100, 512, 0, 0, 0, 0, '', 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Infinite Vanquisher - Between 0-15% Mana - Increment Phase By 1 (Phase 1) (No Repeat) (Dungeon)'),
(18995, 0, 10, 0, 9, 1, 100, 519, 35, 80, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Infinite Vanquisher - Within 35-80 Range - Enable Combat Movement (Phase 1) (No Repeat) (Dungeon)'),
(18995, 0, 11, 0, 9, 1, 100, 519, 5, 15, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Infinite Vanquisher - Within 5-15 Range - Disable Combat Movement (Phase 1) (No Repeat) (Dungeon)'),
(18995, 0, 12, 0, 9, 1, 100, 519, 0, 5, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Infinite Vanquisher - Within 0-5 Range - Enable Combat Movement (Phase 1) (No Repeat) (Dungeon)'),
(18995, 0, 13, 0, 0, 0, 100, 2, 7500, 9000, 2400, 5500, '', 11, 15241, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Infinite Vanquisher - In Combat - Cast \'Scorch\' (Phase 1) (No Repeat) (Dungeon)'),
(18995, 0, 14, 0, 0, 0, 100, 4, 7500, 9000, 2400, 5500, '', 11, 36807, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Infinite Vanquisher - In Combat - Cast \'Scorch\' (Phase 1) (No Repeat) (Dungeon)'),
(18995, 0, 15, 0, 0, 0, 100, 2, 5900, 6000, 5900, 6000, '', 11, 13341, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Infinite Vanquisher - In Combat - Cast \'Fire Blast\' (Phase 1) (No Repeat) (Dungeon)'),
(18995, 0, 16, 0, 0, 0, 100, 4, 5900, 6000, 5900, 6000, '', 11, 38526, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Infinite Vanquisher - In Combat - Cast \'Fire Blast\' (Phase 1) (No Repeat) (Dungeon)'),
(18995, 0, 17, 0, 3, 0, 100, 518, 30, 100, 100, 100, '', 23, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Infinite Vanquisher - Between 30-100% Mana - Decrement Phase By 1 (Phase 1) (No Repeat) (Dungeon)'),
(18995, 0, 18, 0, 7, 0, 100, 7, 0, 0, 0, 0, '', 11, 31326, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Infinite Vanquisher - On Evade - Cast \'Corrupt Medivh\' (Phase 1) (No Repeat) (Dungeon)'),
(19456, 0, 4, 5, 61, 0, 100, 512, 0, 0, 0, 0, '', 2, 35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Whitebark\'s Spirit - Between 0-30% Health - Set Faction 35 (No Repeat)'),
(19456, 0, 5, 6, 61, 0, 100, 512, 0, 0, 0, 0, '', 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Whitebark\'s Spirit - Between 0-30% Health - Say Line 1 (No Repeat)'),
(19456, 0, 6, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Whitebark\'s Spirit - Between 0-30% Health - Evade (No Repeat)'),
(19456, 0, 7, 0, 0, 0, 100, 0, 2500, 5500, 12000, 14500, '', 11, 31287, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Whitebark\'s Spirit - In Combat - Cast \'Entangling Roots\' (No Repeat)'),
(19456, 0, 3, 4, 61, 0, 100, 512, 0, 0, 0, 0, '', 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Whitebark\'s Spirit - Between 0-30% Health - Set Home Position (No Repeat)'),
(19456, 0, 2, 3, 2, 0, 100, 512, 24, 26, 120000, 120000, '', 102, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Whitebark\'s Spirit - Between 24-26% Health - Set Health Regeneration Off'),
(19456, 0, 1, 0, 4, 0, 100, 1, 0, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Whitebark\'s Spirit - On Aggro - Say Line 0'),
(19456, 0, 0, 0, 54, 0, 100, 512, 0, 0, 0, 0, '', 42, 0, 25, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Whitebark\'s Spirit - On Just Summoned - Set Invincibility Hp 25%'),
(19456, 0, 8, 0, 0, 0, 100, 0, 7500, 7500, 9500, 16000, '', 11, 11442, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Whitebark\'s Spirit - In Combat - Cast \'Withered Touch\''),
(19456, 0, 9, 0, 1, 0, 100, 512, 60000, 60000, 60000, 60000, '', 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Whitebark\'s Spirit - Out of Combat - Despawn Instant'),
(19527, 0, 0, 0, 4, 0, 100, 512, 0, 0, 0, 0, '', 11, 34524, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vacillating Voidcaller - On Just Summoned - Cast Elemental Response'),
(19527, 0, 1, 0, 2, 0, 100, 1, 0, 10, 0, 0, '', 11, 34842, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vacillating Voidcaller - On Less than 10% HP - Cast De-Materialize'),
(19527, 0, 2, 0, 8, 0, 100, 512, 34842, 0, 0, 0, '', 41, 0, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vacillating Voidcaller - On Spellhit De-Materialize  - Despawn'),
(19527, 0, 3, 0, 4, 0, 100, 512, 0, 0, 0, 0, '', 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vacillating Voidcaller - On Agro - Set Phase 1'),
(19527, 0, 4, 17, 8, 1, 100, 512, 0, 2, 0, 0, '', 11, 34336, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vacillating Voidcaller - On Spellhit (Holy) (Phase 1) - Cast Damage Reduction: Holy'),
(19527, 0, 5, 18, 8, 1, 100, 512, 0, 4, 0, 0, '', 11, 34333, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vacillating Voidcaller - On Spellhit (Fire) (Phase 1) - Cast Damage Reduction: Fire'),
(19527, 0, 6, 19, 8, 1, 100, 512, 0, 8, 0, 0, '', 11, 34335, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vacillating Voidcaller - On Spellhit (Nature)(Phase 1) - Cast Damage Reduction: Nature'),
(19527, 0, 7, 20, 8, 1, 100, 512, 0, 16, 0, 0, '', 11, 34334, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vacillating Voidcaller - On Spellhit (Frost) (Phase 1) - Cast Damage Reduction: Frost'),
(19527, 0, 8, 21, 8, 1, 100, 512, 0, 32, 0, 0, '', 11, 34338, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vacillating Voidcaller - On Spellhit (Shadow) (Phase 1)  - Cast Damage Reduction: Shadow'),
(19527, 0, 9, 22, 8, 1, 100, 512, 0, 64, 0, 0, '', 11, 34331, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vacillating Voidcaller - On Spellhit (Arcane) (Phase 1)  - Cast Damage Reduction: Arcane'),
(19527, 0, 10, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vacillating Voidcaller - Link - Set Phase 2'),
(19527, 0, 11, 0, 0, 2, 100, 0, 0, 0, 2000, 3000, '', 11, 34348, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Vacillating Voidcaller - IC (Phase 2)  - Cast Fireball'),
(19527, 0, 12, 0, 0, 2, 100, 0, 0, 0, 5000, 6000, '', 11, 34446, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Vacillating Voidcaller - IC (Phase 2)  - Cast Arcane Missiles'),
(19527, 0, 13, 0, 0, 2, 100, 0, 0, 0, 2000, 3000, '', 11, 34347, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Vacillating Voidcaller - IC (Phase 2)  - Cast Frost Bolt'),
(19527, 0, 14, 0, 0, 2, 100, 0, 0, 0, 2000, 3000, '', 11, 34346, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Vacillating Voidcaller - IC (Phase 2)  - Cast Holy Bolt'),
(19527, 0, 15, 0, 0, 2, 100, 0, 0, 0, 2000, 3000, '', 11, 34345, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Vacillating Voidcaller - IC (Phase 2)  - Cast Lightning Bolt'),
(19527, 0, 16, 0, 0, 2, 100, 0, 0, 0, 2000, 3000, '', 11, 34344, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Vacillating Voidcaller - IC (Phase 2)  - Cast Shadow Bolt'),
(19527, 0, 17, 10, 61, 0, 100, 512, 0, 0, 0, 0, '', 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vacillating Voidcaller - On Spellhit (Holy) (Phase 1) - Say'),
(19527, 0, 18, 10, 61, 0, 100, 512, 0, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vacillating Voidcaller - On Spellhit (Fire) (Phase 1) - Say'),
(19527, 0, 19, 10, 61, 0, 100, 512, 0, 0, 0, 0, '', 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vacillating Voidcaller - On Spellhit (Nature)(Phase 1) - Say'),
(19527, 0, 20, 10, 61, 0, 100, 512, 0, 0, 0, 0, '', 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vacillating Voidcaller - On Spellhit (Frost) (Phase 1) - Say'),
(19527, 0, 21, 10, 61, 0, 100, 512, 0, 0, 0, 0, '', 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vacillating Voidcaller - On Spellhit (Shadow) (Phase 1)  - Say'),
(19527, 0, 22, 10, 61, 0, 100, 512, 0, 0, 0, 0, '', 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vacillating Voidcaller - On Spellhit (Arcane) (Phase 1)  - Say'),
(21218, 0, 0, 0, 0, 0, 100, 2, 8500, 8500, 12700, 12700, '', 11, 38572, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Vashj\'ir Honor Guard - In Combat - Cast \'Mortal Cleave\' (Phase 1) (No Repeat)'),
(21218, 0, 1, 0, 0, 0, 100, 2, 13600, 13600, 8700, 14000, '', 11, 38576, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Vashj\'ir Honor Guard - In Combat - Cast \'Knockback\' (Phase 1) (No Repeat)'),
(21218, 0, 2, 3, 2, 0, 100, 3, 0, 50, 0, 0, '', 11, 38947, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vashj\'ir Honor Guard - Between 0-50% Health - Cast \'Frenzy\' (No Repeat) (Normal Dungeon)'),
(21218, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vashj\'ir Honor Guard - Between 0-50% Health - Say Line 0 (No Repeat) (Normal Dungeon)'),
(21644, 0, 0, 0, 0, 0, 100, 0, 1000, 3000, 9000, 14000, '', 11, 13730, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Skettis Wing Guard - In Combat - Cast \'Demoralizing Shout\''),
(21644, 0, 1, 0, 0, 0, 100, 0, 4000, 7000, 7000, 12000, '', 11, 35321, 33, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Skettis Wing Guard - In Combat - Cast \'Gushing Wound\''),
(21644, 0, 2, 0, 0, 0, 100, 0, 6000, 9000, 11000, 16000, '', 11, 40546, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Skettis Wing Guard - In Combat - Cast \'Retaliation\''),
(21644, 0, 3, 4, 2, 0, 100, 1, 0, 30, 0, 0, '', 11, 8599, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Skettis Wing Guard - Between 0-30% Health - Cast \'Enrage\' (No Repeat)'),
(21644, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Skettis Wing Guard - Between 0-30% Health - Say Line 0 (No Repeat)'),
(22844, 0, 0, 0, 0, 0, 85, 2, 19000, 19000, 18000, 18000, '', 11, 15284, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Ashtongue Battlelord - In Combat - Cast \'Cleave\' (Phase 1) (No Repeat)'),
(22844, 0, 1, 0, 0, 0, 90, 2, 6000, 6000, 20000, 20000, '', 11, 32588, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Ashtongue Battlelord - In Combat - Cast \'Concussion Blow\' (Phase 1) (No Repeat)'),
(22844, 0, 2, 0, 0, 0, 85, 2, 15000, 15000, 22000, 22000, '', 11, 41182, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Ashtongue Battlelord - In Combat - Cast \'Concussive Throw\' (Phase 1) (No Repeat)'),
(22844, 0, 3, 4, 2, 0, 100, 3, 0, 30, 0, 0, '', 11, 34970, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ashtongue Battlelord - Between 0-30% Health - Cast \'Frenzy\' (No Repeat) (Normal Dungeon)'),
(22844, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ashtongue Battlelord - Between 0-30% Health - Say Line 0 (No Repeat) (Normal Dungeon)'),
(22874, 0, 0, 0, 4, 0, 100, 3, 100, 0, 0, 0, '', 11, 40084, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Coilskar Harpooner - On Aggro - Cast \'Harpooner\'s Mark\' (No Repeat) (Normal Dungeon)'),
(22874, 0, 1, 0, 0, 0, 100, 2, 100, 100, 15000, 30000, '', 11, 40083, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Coilskar Harpooner - In Combat - Cast \'Spear Throw\' (No Repeat) (Normal Dungeon)'),
(22874, 0, 2, 0, 0, 0, 100, 2, 20000, 20000, 35000, 55000, '', 11, 40082, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Coilskar Harpooner - In Combat - Cast \'Hooked Net\' (No Repeat) (Normal Dungeon)'),
(23030, 0, 1, 0, 0, 0, 100, 514, 0, 0, 0, 0, '', 19, 33554432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dragonmaw Sky Stalker - In Combat - Remove Flag Not Selectable (Phase 1) (No Repeat)'),
(23030, 0, 0, 0, 6, 0, 100, 514, 0, 0, 0, 0, '', 43, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dragonmaw Sky Stalker - On Just Died - Dismount (Phase 1) (No Repeat)'),
(23030, 0, 2, 0, 9, 0, 100, 2, 5, 41, 15800, 15800, '', 11, 40872, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Dragonmaw Sky Stalker - Within 5-41 Range - Cast \'Immolation Arrow\' (Phase 1) (No Repeat)'),
(23030, 0, 3, 0, 9, 0, 100, 2, 5, 41, 9800, 9800, '', 11, 40873, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Dragonmaw Sky Stalker - Within 5-41 Range - Cast \'Shoot\' (Phase 1) (No Repeat)'),
(23196, 0, 0, 0, 0, 0, 100, 2, 1000, 1000, 25000, 45000, '', 11, 41277, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Bonechewer Behemoth - In Combat - Cast \'Fiery Comet\''),
(23196, 0, 1, 0, 0, 0, 100, 2, 15000, 15000, 30000, 40000, '', 11, 41274, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Bonechewer Behemoth - In Combat - Cast \'Fel Stomp\''),
(23196, 0, 2, 3, 2, 0, 100, 3, 0, 30, 0, 0, '', 11, 40743, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bonechewer Behemoth - Between 0-30% Health - Cast \'Frenzy\' (No Repeat) (Normal Dungeon)'),
(23196, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bonechewer Behemoth - Between 0-30% Health - Say Line 0 (No Repeat) (Normal Dungeon)'),
(23196, 0, 4, 0, 4, 0, 100, 3, 0, 0, 0, 0, '', 11, 41272, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Bonechewer Behemoth - On Aggro - Cast \'Behemoth Charge\' (No Repeat) (Normal Dungeon)'),
(23285, 0, 0, 1, 1, 0, 100, 1, 0, 0, 0, 0, '', 11, 29147, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Nethermine Burster - Out of Combat - Cast \'Tunnel Bore Passive\' (No Repeat)'),
(23285, 0, 1, 0, 61, 0, 100, 513, 0, 0, 0, 0, '', 18, 33554434, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Nethermine Burster - Out of Combat - Set Flags Not Attackable & Not Selectable (No Repeat)'),
(23285, 0, 2, 3, 0, 0, 100, 513, 0, 0, 0, 0, '', 28, 29147, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Nethermine Burster - In Combat - Remove Aura \'Tunnel Bore Passive\' (No Repeat)'),
(23285, 0, 3, 4, 61, 0, 100, 512, 0, 0, 0, 0, '', 19, 33554434, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Nethermine Burster - In Combat - Remove Flags Not Attackable & Not Selectable (No Repeat)'),
(23285, 0, 4, 5, 61, 0, 100, 512, 0, 0, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Nethermine Burster - In Combat - Disable Combat Movement (No Repeat)'),
(23285, 0, 5, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Nethermine Burster - In Combat - Set Event Phase 1 (No Repeat)'),
(23285, 0, 6, 7, 0, 1, 100, 0, 1000, 1000, 2100, 4500, '', 11, 31747, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Nethermine Burster - In Combat - Cast \'Poison\' (Phase 1)'),
(23285, 0, 7, 0, 61, 1, 100, 512, 0, 0, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Nethermine Burster - In Combat - Disable Combat Movement (Phase 1)'),
(23285, 0, 8, 0, 0, 1, 100, 0, 20400, 20400, 45000, 50000, '', 11, 32738, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Nethermine Burster - In Combat - Cast \'Bore\' (Phase 1)'),
(23285, 0, 9, 10, 9, 1, 100, 0, 20, 60, 0, 0, '', 11, 29147, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Nethermine Burster - Within 20-60 Range - Cast \'Tunnel Bore Passive\' (Phase 1)'),
(23285, 0, 10, 11, 61, 1, 100, 512, 0, 0, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Nethermine Burster - Within 20-60 Range - Enable Combat Movement (Phase 1)'),
(23285, 0, 11, 0, 61, 1, 100, 512, 0, 0, 0, 0, '', 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Nethermine Burster - Within 20-60 Range - Set Event Phase 2 (Phase 1)'),
(23285, 0, 12, 13, 9, 2, 100, 512, 0, 8, 0, 0, '', 28, 29147, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Nethermine Burster - Within 0-8 Range - Remove Aura \'Tunnel Bore Passive\' (Phase 2)'),
(23285, 0, 13, 14, 61, 2, 100, 512, 0, 0, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Nethermine Burster - Within 0-8 Range - Disable Combat Movement (Phase 2)'),
(23285, 0, 14, 15, 61, 2, 100, 512, 0, 8, 0, 0, '', 19, 33554434, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Nethermine Burster - Within 0-8 Range - Remove Flags Not Attackable & Not Selectable (Phase 2)'),
(23285, 0, 15, 0, 61, 2, 100, 512, 0, 0, 0, 0, '', 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Nethermine Burster - Within 0-8 Range - Set Event Phase 1 (Phase 2)'),
(23285, 0, 16, 0, 2, 0, 100, 513, 0, 10, 0, 0, '', 11, 32714, 3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Nethermine Burster - Between 0-10% Health - Cast \'Enrage\' (Phase 2)'),
(23507, 0, 0, 1, 8, 0, 100, 512, 44654, 0, 0, 0, '', 33, 23507, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Elwynn Pink Elekk - On Spellhit \'Elekk Dispersion Ray - Kill Credit\' - Quest Credit \'Pink Elekks On Parade\''),
(23507, 0, 1, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Elwynn Pink Elekk - On Spellhit \'Elekk Dispersion Ray - Kill Credit\' - Despawn Instant'),
(23527, 0, 0, 1, 8, 0, 100, 512, 44654, 0, 0, 0, '', 33, 23527, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Teldrassil Pink Elekk - On Spellhit \'Elekk Dispersion Ray - Kill Credit\' - Quest Credit \'Pink Elekks On Parade\''),
(23527, 0, 1, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Teldrassil Pink Elekk - On Spellhit \'Elekk Dispersion Ray - Kill Credit\' - Despawn Instant'),
(23528, 0, 0, 1, 8, 0, 100, 512, 44654, 0, 0, 0, '', 33, 23528, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Azuremyst Pink Elekk - On Spellhit \'Elekk Dispersion Ray - Kill Credit\' - Quest Credit \'Pink Elekks On Parade\''),
(23528, 0, 1, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Azuremyst Pink Elekk - On Spellhit \'Elekk Dispersion Ray - Kill Credit\' - Despawn Instant'),
(23529, 0, 0, 1, 8, 0, 100, 512, 44654, 0, 0, 0, '', 33, 23529, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Mulgore Pink Elekk - On Spellhit \'Elekk Dispersion Ray - Kill Credit\' - Quest Credit \'Pink Elekks On Parade\''),
(23529, 0, 1, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mulgore Pink Elekk - On Spellhit \'Elekk Dispersion Ray - Kill Credit\' - Despawn Instant'),
(23530, 0, 0, 1, 8, 0, 100, 512, 44654, 0, 0, 0, '', 33, 23530, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Tirisfal Pink Elekk - On Spellhit \'Elekk Dispersion Ray - Kill Credit\' - Quest Credit \'Pink Elekks On Parade\''),
(23530, 0, 1, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tirisfal Pink Elekk - On Spellhit \'Elekk Dispersion Ray - Kill Credit\' - Despawn Instant'),
(23531, 0, 0, 1, 8, 0, 100, 512, 44654, 0, 0, 0, '', 33, 23531, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Eversong Pink Elekk - On Spellhit \'Elekk Dispersion Ray - Kill Credit\' - Quest Credit \'Pink Elekks On Parade\''),
(23531, 0, 1, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Eversong Pink Elekk - On Spellhit \'Elekk Dispersion Ray - Kill Credit\' - Despawn Instant'),
(25397, 0, 0, 1, 8, 0, 100, 513, 45536, 0, 0, 0, '', 33, 25397, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Elder Kesuk - On Spellhit \'Complete Ancestor Ritual\' - Quest Credit \'Leading the Ancestors Home\''),
(25397, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, '', 11, 33345, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Elder Kesuk - On Spellhit \'Complete Ancestor Ritual\' - Cast Yellow Banish State '),
(25397, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, '', 3, 0, 28320, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Elder Kesuk - On Spellhit \'Complete Ancestor Ritual\' - Change Modelid '),
(25397, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, '', 114, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 18, 0, 'Elder Kesuk - On Spellhit \'Complete Ancestor Ritual\' - Change Modelid '),
(25397, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, '', 41, 5000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Elder Kesuk - On Spellhit \'Complete Ancestor Ritual\' - Change Modelid '),
(25398, 0, 0, 1, 8, 0, 100, 513, 45536, 0, 0, 0, '', 33, 25398, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Elder Sagani - On Spellhit \'Complete Ancestor Ritual\' - Quest Credit \'Leading the Ancestors Home\''),
(25398, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, '', 11, 33345, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Elder Sagani - On Spellhit \'Complete Ancestor Ritual\' - Cast Yellow Banish State '),
(25398, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, '', 3, 0, 28320, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Elder Sagani - On Spellhit \'Complete Ancestor Ritual\' - Change Modelid '),
(25398, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, '', 114, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 18, 0, 'Elder Sagani - On Spellhit \'Complete Ancestor Ritual\' - Change Modelid '),
(25398, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, '', 41, 5000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Elder Sagani - On Spellhit \'Complete Ancestor Ritual\' - Change Modelid '),
(25399, 0, 0, 1, 8, 0, 100, 513, 45536, 0, 0, 0, '', 33, 25399, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Elder Takret - On Spellhit \'Complete Ancestor Ritual\' - Quest Credit \'Leading the Ancestors Home\''),
(25399, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, '', 11, 33345, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Elder Takret - On Spellhit \'Complete Ancestor Ritual\' - Cast Yellow Banish State '),
(25399, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, '', 3, 0, 28320, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Elder Takret - On Spellhit \'Complete Ancestor Ritual\' - Change Modelid '),
(25399, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, '', 114, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 18, 0, 'Elder Takret - On Spellhit \'Complete Ancestor Ritual\' - Change Modelid '),
(25399, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, '', 41, 5000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Elder Takret - On Spellhit \'Complete Ancestor Ritual\' - Change Modelid '),
(25599, 0, 0, 0, 11, 0, 100, 3, 0, 0, 0, 0, '', 11, 45769, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cataclysm Hound - On Respawn - Cast \'Sunwell Radiance\''),
(25599, 0, 1, 0, 0, 0, 100, 2, 15000, 15000, 20000, 35000, '', 11, 46292, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cataclysm Hound - In Combat - Cast \'Cataclysm Breath\''),
(25599, 0, 2, 0, 2, 0, 100, 3, 0, 20, 0, 0, '', 11, 47399, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cataclysm Hound - Between 0-20% Health - Cast \'Enrage\''),
(27959, 0, 0, 1, 54, 0, 100, 512, 0, 0, 0, 0, '', 11, 41408, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Your Inner Turmoil - On Just Summoned - Cast \'Shadowform\''),
(27959, 0, 1, 2, 61, 0, 100, 512, 0, 0, 0, 0, '', 85, 50218, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Your Inner Turmoil - On Just Summoned - Invoker Cast \'The Cleansing: Your Inner Turmoil\'s Mirror Image Aura\''),
(27959, 0, 2, 3, 61, 0, 100, 512, 0, 0, 0, 0, '', 85, 41054, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Your Inner Turmoil - On Just Summoned - Invoker Cast \'Copy Weapon\''),
(27959, 0, 3, 4, 61, 0, 100, 512, 0, 0, 0, 0, '', 85, 41055, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Your Inner Turmoil - On Just Summoned - Invoker Cast \'Copy Weapon\''),
(27959, 0, 4, 5, 61, 0, 100, 512, 0, 0, 0, 0, '', 85, 45205, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Your Inner Turmoil - On Just Summoned - Invoker Cast \'Copy Offhand Weapon\''),
(27959, 0, 5, 6, 61, 0, 100, 512, 0, 0, 0, 0, '', 85, 45206, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Your Inner Turmoil - On Just Summoned - Invoker Cast \'Copy Off-hand Weapon\''),
(27959, 0, 6, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 80, 2795900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Your Inner Turmoil - On Just Summoned - Run Script'),
(27959, 0, 7, 0, 2, 0, 100, 1, 0, 50, 0, 0, '', 1, 2, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Your Inner Turmoil - Between 0-50% Health - Say Line 2'),
(27959, 0, 8, 9, 6, 0, 100, 1, 0, 0, 0, 0, '', 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Your Inner Turmoil - On Just Died - Say Line 3 (No Repeat)'),
(27959, 0, 9, 10, 61, 0, 100, 513, 0, 0, 0, 0, '', 3, 0, 11686, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Your Inner Turmoil - On Just Died - Morph To Model 11686 (No Repeat)'),
(27959, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, '', 75, 50237, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Your Inner Turmoil - On Just Died - Add Aura \'Slow Fall\' (No Repeat)'),
(28557, 0, 0, 0, 2, 0, 100, 1, 0, 20, 1, 1, '', 1, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Scarlet Peasant - Between 0-20% Health - Say Line 0 (Phase 1) (No Repeat) (Dungeon)'),
(30146, 0, 4, 5, 1, 2, 100, 1, 0, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Exhausted Vrykul - Out of Combat - Say Line 0 (Phase 2) (No Repeat)'),
(30146, 0, 3, 0, 61, 1, 100, 512, 0, 0, 0, 0, '', 31, 2, 3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Exhausted Vrykul - Out of Combat - Set Phase Random Between 2-3 (Phase 2) (No Repeat)'),
(30146, 0, 1, 0, 1, 1, 100, 512, 0, 0, 0, 0, '', 90, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Exhausted Vrykul - Out of Combat - Set Flag Standstate Sit Down (Phase 2) (No Repeat)'),
(30146, 0, 2, 3, 8, 1, 100, 512, 56033, 0, 0, 0, '', 33, 29886, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Exhausted Vrykul - On Spellhit \'Disciplining Rod\' - Quest Credit \'Discipline\' (Phase 1)'),
(30146, 0, 6, 0, 61, 2, 100, 512, 0, 0, 0, 0, '', 49, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Exhausted Vrykul - On Spellhit \'Disciplining Rod\' - Start Attacking (Phase 1)'),
(30146, 0, 5, 6, 61, 2, 100, 512, 0, 0, 0, 0, '', 91, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Exhausted Vrykul - On Spellhit \'Disciplining Rod\' - Remove Flag Standstate Sit Down (Phase 1)'),
(30146, 0, 0, 0, 25, 0, 100, 513, 0, 0, 0, 0, '', 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Exhausted Vrykul - On Reset - Set Event Phase 1 (Phase 1)'),
(30146, 0, 7, 8, 1, 4, 100, 1, 0, 0, 0, 0, '', 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Exhausted Vrykul - Out of Combat - Say Line 1 (Phase 4) (No Repeat)'),
(30146, 0, 8, 9, 61, 4, 100, 512, 0, 0, 0, 0, '', 91, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Exhausted Vrykul - Out of Combat - Remove Flag Standstate Sit Down (Phase 4) (No Repeat)'),
(30146, 0, 9, 10, 61, 4, 100, 512, 0, 0, 0, 0, '', 114, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 6, 0, 0, 'Exhausted Vrykul - Out of Combat - Move Forward 6 Yards (Phase 4) (No Repeat)'),
(30146, 0, 10, 0, 61, 4, 100, 512, 0, 0, 0, 0, '', 17, 233, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Exhausted Vrykul - Out of Combat - Set Emote State 233 (Phase 4) (No Repeat)'),
(30146, 0, 11, 0, 1, 4, 100, 513, 60000, 60000, 0, 0, '', 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Exhausted Vrykul - Out of Combat - Despawn Instant (Phase 4) (No Repeat)'),
(30146, 0, 12, 0, 2, 0, 100, 1, 0, 30, 0, 0, '', 11, 57395, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Exhausted Vrykul - Between 0-30% Health - Cast \'Desperate Blow\' (Phase 4) (No Repeat)'),
(30461, 0, 0, 0, 54, 0, 100, 512, 0, 0, 0, 0, '', 53, 1, 30461, 0, 13051, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Veranus - On Just Summoned - Start Waypoint'),
(30461, 0, 1, 2, 58, 0, 100, 512, 1, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Veranus - On Waypoint Finished - Say Line 0'),
(30461, 0, 2, 3, 61, 0, 100, 512, 1, 0, 0, 0, '', 33, 30461, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Veranus - On Waypoint Finished - Quest Credit \'Territorial Trespass\''),
(30461, 0, 3, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 12, 30462, 8, 0, 0, 0, 0, 8, 0, 0, 0, 7096.86, -904.658, 1119.9, 2.33874, 'Veranus - On Waypoint Finished - Summon Creature \'Thorim\''),
(30461, 0, 4, 5, 38, 0, 100, 512, 1, 1, 0, 0, '', 114, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 100, 0, 0, 'Veranus - On Data Set 1 1 - Move Forward 100 Yards'),
(30461, 0, 5, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 41, 10000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Veranus - On Data Set 1 1 - Despawn In 10000 ms'),
(32720, 0, 0, 1, 25, 0, 100, 512, 0, 0, 0, 0, '', 71, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Violetta - On Reset - Change Equipment'),
(32720, 0, 1, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 88, 3272000, 3272001, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Violetta - On Reset - Run Random Script'),
(32720, 0, 2, 0, 40, 1, 100, 512, 8, 0, 0, 0, '', 80, 3272002, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Violetta - On Waypoint 8 Reached - Run Script'),
(32720, 0, 3, 0, 40, 2, 100, 512, 8, 0, 0, 0, '', 80, 3272003, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Violetta - On Waypoint 8 Reached - Run Script'),
(32720, 0, 4, 0, 58, 0, 100, 512, 0, 0, 0, 0, '', 41, 10000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Violetta - On Waypoint Finished - Despawn In 10000 ms'),
(32888, 0, 0, 0, 0, 0, 100, 0, 0, 0, 3400, 4700, '', 11, 75019, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Twilight Fanatic - In Combat - Cast \'Twilight\'s Wrath\''),
(32888, 0, 1, 0, 2, 0, 100, 1, 0, 15, 0, 0, '', 25, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Twilight Fanatic - Between 0-15% Health - Flee For Assist (No Repeat)'),
(32888, 0, 2, 3, 0, 0, 100, 0, 5000, 6000, 35000, 40000, '', 11, 75021, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Twilight Fanatic - In Combat - Cast \'Prismatic Gaze\''),
(32888, 0, 3, 0, 61, 0, 35, 1, 5000, 6000, 35000, 40000, '', 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Twilight Fanatic - In Combat - Say Line 1'),
(33356, 0, 0, 0, 0, 0, 100, 0, 0, 0, 3400, 4700, '', 11, 32707, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Orux Thrice-Damned - In Combat - Cast \'Incinerate\''),
(33356, 0, 1, 0, 1, 0, 100, 1, 3000, 5000, 0, 0, '', 11, 11939, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Orux Thrice-Damned - Out of Combat - Cast \'Summon Imp\' (No Repeat)'),
(33356, 0, 2, 0, 1, 0, 100, 1, 7000, 9000, 0, 0, '', 11, 62856, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Orux Thrice-Damned - Out of Combat - Cast \'Detect Invisibility\' (No Repeat)'),
(33356, 0, 3, 0, 0, 0, 100, 512, 7000, 8000, 17000, 22000, '', 11, 11962, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Orux Thrice-Damned - In Combat - Cast \'Immolate\''),
(33356, 0, 4, 5, 1, 0, 100, 0, 500, 500, 20000, 35000, '', 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Orux Thrice-Damned - Out of Combat - Say Line 0'),
(33356, 0, 5, 0, 61, 0, 100, 1, 500, 500, 20000, 35000, '', 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Orux Thrice-Damned - Out of Combat - Say Line 1');

REPLACE INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(16409, 1, 1, 'A feast fit for royalty!', 0, 0, 100, 0, 0, 0, 0, 0, ''),
(23685, 1, 1, 'Glup glup glup...', 0, 0, 100, 0, 0, 0, 0, 0, ''),
(23685, 1, 1, 'Pink eleks? Hey...?', 0, 0, 100, 0, 0, 0, 0, 0, ''),
(23685, 1, 1, 'The best beer...!', 0, 0, 100, 0, 0, 0, 0, 0, ''),
(23685, 1, 1, 'Waitress, more beer!', 0, 0, 100, 0, 0, 0, 0, 0, ''),
(23698, 0, 0, 'Beeeeer...!', 0, 0, 100, 0, 0, 0, 0, 0, ''),
(23698, 1, 1, 'More beer...', 0, 0, 100, 0, 0, 0, 0, 0, ''),
(24536, 0, 0, 'All will be consumed.', 0, 0, 100, 0, 0, 0, 0, 0, ''),
(24536, 0, 0, 'The end is near.', 0, 0, 100, 0, 0, 0, 0, 0, ''),
(24536, 1, 1, 'And in the ruin we will laugh.', 0, 0, 100, 0, 0, 0, 0, 0, ''),
(24536, 1, 1, 'Nobody can be saved.', 0, 0, 100, 0, 0, 0, 0, 0, ''),
(33569, 0, 0, 'Fire!!', 1, 0, 100, 0, 0, 0, 0, 0, ''),
(33569, 1, 1, 'Kill her!!', 1, 0, 100, 0, 0, 0, 0, 0, ''),
(39062, 0, 0, 'Get in the pit and show us your stuff, boy.', 0, 0, 100, 0, 0, 0, 0, 0, ''),
(39062, 0, 0, 'Get in the pit and show us your stuff, girl.', 0, 0, 100, 0, 0, 0, 0, 0, ''),
(75729, 0, 0, 'My soul burns.', 0, 0, 100, 0, 0, 0, 0, 0, ''),
(75729, 1, 1, 'My soul will devour your ashes.', 0, 0, 100, 0, 0, 0, 0, 0, ''),
(77693, 3, 3, 'Nyami awaits you in the western ritual chamber, champions.', 0, 0, 100, 0, 0, 0, 0, 0, ''),
(79796, 0, 0, 'Help!', 0, 0, 100, 0, 0, 0, 0, 0, ''),
(79799, 0, 0, 'Piety...', 0, 0, 100, 0, 0, 0, 0, 0, '');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (61,1124,1487,2245,3502,3594,3616,3691,3696,3845,3926,5251,5953,6649,7606,7843,7956,8147,8151,8154,11488,12322,12856,12864,14347,14715,14753,17725,17729,17820,18094,22231,23619,23623,23624,23625,23626,23636,23664,23751,23752,23753,23859,24841,25145,26200,26543,26701,26787,28132,28156,28580,28882,29820,29836,33071,33419,34177,34204,34208,34309,34419,35161,35312,35880,36624,36636,36642,36660,36708,36815,36890,36942,37212,37548,38017,38070,38912,38942,39261,39268,39317,39946,39972,40069,41641,43325,45410,45438,47434,48312,48314,48316,55418,57875,57877,57890,83600,164885,164886,164887,164888,171939,171942,173284,173324,173327,174594,174595,174596,174597,174598,174599,174600,174601,174602,174603,174604,174605,174606,174607,174608,174684,174686,174708,174709,174712,174713,305400);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(61, 1, 0, 0, 20, 0, 100, 0, 231, 0, 0, 0, '', 12, 3301, 1, 15000, 0, 0, 0, 8, 0, 0, 0, -10238.2, 353.725, 50.9208, 2.723, 'A Weathered Grave - On Quest \'A Daughter\'s Love\' Finished - Summon Creature \'Morgan Ladimore\' (Phase 1)'),
(61, 0, 0, 0, 4, 0, 40, 1, 0, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Thuros Lightfingers - On Aggro - Say Line 0 (Phase 1)'),
(1124, 0, 4, 0, 2, 0, 100, 1, 0, 15, 0, 0, '', 25, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Frostmane Headhunter - Between 0-15% Health - Flee For Assist (No Repeat)'),
(1124, 0, 3, 0, 0, 0, 100, 0, 0, 0, 180000, 186200, '', 11, 11980, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Frostmane Shadowcaster - In Combat - Cast \'Curse of Weakness\''),
(1124, 0, 2, 0, 0, 0, 100, 0, 500, 500, 3400, 6400, '', 11, 20791, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Frostmane Shadowcaster - In Combat CMC - Cast \'Shadow Bolt\''),
(1124, 0, 1, 0, 4, 0, 15, 0, 0, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Frostmane Shadowcaster - On Aggro - Say Line 0'),
(1124, 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 1800000, 1800000, '', 11, 20798, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Frostmane Shadowcaster - Out of Combat - Cast \'Demon Skin\''),
(1487, 0, 1, 0, 0, 0, 100, 0, 0, 3200, 21100, 42100, '', 11, 6533, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Splinter Fist Enslaver - In Combat - Cast \'Net\''),
(1487, 0, 0, 0, 0, 0, 100, 0, 0, 0, 3400, 5100, '', 11, 10277, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Splinter Fist Enslaver - In Combat CMC - Cast \'Throw\''),
(2245, 0, 2, 0, 2, 0, 100, 1, 0, 15, 0, 0, '', 25, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Syndicate Saboteur - Between 0-15% Health - Flee For Assist (No Repeat)'),
(2245, 0, 1, 0, 0, 0, 100, 0, 7400, 10200, 14500, 26900, '', 11, 6980, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Syndicate Saboteur - In Combat - Cast \'Fire Shot\''),
(2245, 0, 0, 0, 0, 0, 100, 0, 0, 0, 2500, 5900, '', 11, 6660, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Syndicate Saboteur - In Combat CMC - Cast \'Shoot\''),
(3502, 0, 0, 0, 0, 0, 100, 0, 0, 0, 2300, 3900, '', 11, 23337, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Ratchet Bruiser - In Combat - Cast \'Shoot\''),
(3502, 0, 1, 0, 9, 0, 100, 0, 0, 20, 9000, 12000, '', 11, 12024, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Ratchet Bruiser - Within 0-20 Range - Cast \'Net\''),
(3594, 0, 0, 0, 20, 0, 100, 0, 3118, 0, 0, 0, '', 5, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Frahun Shadewhisper - On Quest \'Encrypted Sigil\' Finished - Play Emote 1'),
(3616, 0, 0, 1, 20, 0, 100, 0, 950, 0, 0, 0, '', 80, 361600, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Onu - On Quest \'Return to Onu\' Finished - Run Script'),
(3691, 0, 0, 0, 0, 0, 100, 0, 0, 0, 2300, 3900, '', 11, 16100, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Raene Wolfrunner - In Combat - Cast \'Shoot\''),
(3691, 0, 1, 0, 9, 0, 100, 512, 0, 20, 8000, 9000, '', 11, 6533, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Raene Wolfrunner - Within 0-20 Range - Cast \'Net\''),
(3691, 0, 2, 0, 9, 0, 100, 512, 5, 30, 12000, 19000, '', 11, 15495, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Raene Wolfrunner - Within 5-30 Range - Cast \'Explosive Shot\''),
(3691, 0, 3, 0, 9, 0, 100, 512, 5, 30, 22000, 27000, '', 11, 22908, 2, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 'Raene Wolfrunner - Within 5-30 Range - Cast \'Volley\''),
(3691, 0, 6, 0, 62, 0, 100, 0, 5502, 0, 0, 0, '', 11, 22227, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Raene Wolfrunner - On Gossip Select - Cast spell \'Create Dartol\'s Rod\''),
(3696, 0, 0, 0, 0, 0, 100, 0, 0, 0, 2300, 3900, '', 11, 6660, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Ran Bloodtooth - In Combat - Cast \'Shoot\''),
(3696, 0, 1, 2, 2, 0, 100, 1, 0, 15, 0, 0, '', 25, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ran Bloodtooth - Between 0-15% Health - Flee For Assist (No Repeat)'),
(3696, 0, 2, 0, 61, 0, 100, 1, 0, 15, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ran Bloodtooth - Between 0-15% Health - Say Line 0 (No Repeat)'),
(3696, 0, 3, 0, 9, 0, 100, 512, 0, 5, 15000, 25000, '', 11, 78842, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Ran Bloodtooth - Within 0-5 Range - Cast \'Carnivorous Bite\''),
(3696, 0, 4, 0, 9, 0, 100, 512, 5, 30, 9000, 22000, '', 11, 78841, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Ran Bloodtooth - Within 5-30 Range - Cast \'Aimed Shot\''),
(3696, 0, 5, 0, 2, 0, 100, 1, 0, 30, 0, 0, '', 11, 8599, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ran Bloodtooth - Between 0-30% Health - Cast \'Enrage\' (No Repeat)'),
(3696, 0, 6, 0, 2, 0, 100, 1, 0, 30, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ran Bloodtooth - Between 0-30% Health - Say Line 0 (No Repeat)'),
(3845, 0, 2, 0, 9, 0, 100, 512, 5, 15, 15000, 22000, '', 11, 23601, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Shindrell Swiftfire - Within 5-15 Range - Cast \'Scatter Shot\''),
(3845, 0, 1, 0, 9, 0, 100, 512, 0, 5, 22000, 25000, '', 11, 32908, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Shindrell Swiftfire - Within 0-5 Range - Cast \'Wing Clip\''),
(3845, 0, 0, 0, 0, 0, 100, 0, 0, 0, 2300, 3900, '', 11, 15547, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Shindrell Swiftfire - In Combat - Cast \'Shoot\''),
(3926, 0, 3, 0, 9, 0, 100, 512, 5, 30, 14000, 19000, '', 11, 78754, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Thistlefur Pathfinder - Within 5-30 Range - Cast \'Arcane Shot\''),
(3926, 0, 0, 0, 0, 0, 100, 0, 0, 0, 2300, 3900, '', 11, 6660, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Thistlefur Pathfinder - In Combat - Cast \'Shoot\''),
(3926, 0, 1, 0, 2, 0, 100, 1, 0, 15, 0, 0, '', 25, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Thistlefur Pathfinder - Between 0-15% Health - Flee For Assist (No Repeat)'),
(3926, 0, 2, 0, 11, 0, 100, 1, 0, 0, 0, 0, '', 11, 6813, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Thistlefur Pathfinder - On Respawn - Cast \'Coat of Thistlefur\' (No Repeat)'),
(5251, 0, 0, 1, 4, 0, 100, 513, 0, 0, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Woodpaw Trapper - On Aggro - Disable Combat Movement (No Repeat)'),
(5251, 0, 1, 2, 61, 0, 100, 513, 0, 0, 0, 0, '', 11, 6660, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Woodpaw Trapper - On Aggro - Cast \'Shoot\' (No Repeat)'),
(5251, 0, 2, 3, 61, 0, 100, 513, 0, 0, 0, 0, '', 20, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Woodpaw Trapper - On Aggro - Stop Attacking (No Repeat)'),
(5251, 0, 3, 0, 61, 0, 100, 513, 0, 0, 0, 0, '', 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Woodpaw Trapper - On Aggro - Set Event Phase 1 (No Repeat)'),
(5251, 0, 4, 5, 9, 1, 100, 0, 5, 30, 2300, 3900, '', 11, 6660, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Woodpaw Trapper - Within 5-30 Range - Cast \'Shoot\' (Phase 1)'),
(5251, 0, 5, 0, 61, 1, 100, 0, 5, 30, 2300, 3900, '', 40, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Woodpaw Trapper - Within 5-30 Range - Set Sheath Ranged (Phase 1)'),
(5251, 0, 6, 7, 9, 1, 100, 512, 30, 80, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Woodpaw Trapper - Within 30-80 Range - Enable Combat Movement (Phase 1)'),
(5251, 0, 7, 0, 61, 1, 100, 512, 30, 80, 0, 0, '', 20, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Woodpaw Trapper - Within 30-80 Range - Start Attacking (Phase 1)'),
(5251, 0, 8, 9, 9, 1, 100, 512, 0, 10, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Woodpaw Trapper - Within 0-10 Range - Enable Combat Movement (Phase 1)'),
(5251, 0, 9, 10, 61, 1, 100, 512, 0, 10, 0, 0, '', 40, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Woodpaw Trapper - Within 0-10 Range - Set Sheath Melee (Phase 1)'),
(5251, 0, 10, 0, 61, 1, 100, 512, 0, 10, 0, 0, '', 20, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Woodpaw Trapper - Within 0-10 Range - Start Attacking (Phase 1)'),
(5251, 0, 11, 12, 9, 1, 100, 512, 11, 25, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Woodpaw Trapper - Within 11-25 Range - Disable Combat Movement (Phase 1)'),
(5251, 0, 12, 13, 61, 1, 100, 512, 11, 25, 0, 0, '', 20, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Woodpaw Trapper - Within 11-25 Range - Stop Attacking (Phase 1)'),
(5251, 0, 13, 0, 61, 1, 100, 512, 11, 25, 0, 0, '', 40, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Woodpaw Trapper - Within 11-25 Range - Set Sheath Ranged (Phase 1)'),
(5251, 0, 14, 15, 7, 1, 100, 1, 0, 0, 0, 0, '', 40, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Woodpaw Trapper - On Evade - Set Sheath Melee (Phase 1) (No Repeat)'),
(5251, 0, 15, 0, 61, 1, 100, 513, 0, 0, 0, 0, '', 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Woodpaw Trapper - On Evade - Set Event Phase 0 (Phase 1) (No Repeat)'),
(5251, 0, 16, 0, 2, 1, 100, 513, 0, 15, 0, 0, '', 22, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Woodpaw Trapper - Between 0-15% Health - Set Event Phase 2 (Phase 1) (No Repeat)'),
(5251, 0, 17, 0, 2, 2, 100, 1, 0, 15, 0, 0, '', 25, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Woodpaw Trapper - Between 0-15% Health - Flee For Assist (Phase 2) (No Repeat)'),
(5251, 0, 18, 19, 7, 2, 100, 1, 0, 0, 0, 0, '', 40, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Woodpaw Trapper - On Evade - Set Sheath Melee (Phase 2) (No Repeat)'),
(5251, 0, 19, 0, 61, 2, 100, 513, 0, 0, 0, 0, '', 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Woodpaw Trapper - On Evade - Set Event Phase 0 (Phase 2) (No Repeat)'),
(5251, 0, 22, 5, 9, 1, 100, 0, 5, 30, 18000, 19000, '', 11, 80009, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Woodpaw Trapper - Within 5-30 Range - Cast \'Serpent Sting\' (Phase 1)'),
(5251, 0, 23, 5, 9, 1, 100, 0, 0, 5, 33000, 35000, '', 11, 80018, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Woodpaw Trapper - Within 0-5 Range - Cast \'Frost Trap\' (Phase 1)'),
(5953, 0, 0, 0, 0, 0, 100, 0, 0, 0, 2300, 3900, '', 11, 95826, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Razor Hill Grunt - In Combat - Cast \'Shoot\''),
(5953, 0, 1, 0, 2, 0, 100, 1, 0, 30, 0, 0, '', 11, 8599, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Razor Hill Grunt - Between 0-30% Health - Cast \'Enrage\' (No Repeat)'),
(5953, 0, 2, 0, 2, 0, 100, 1, 0, 30, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Razor Hill Grunt - Between 0-30% Health - Say Line 0 (No Repeat)'),
(5953, 0, 3, 0, 9, 0, 100, 0, 0, 5, 14000, 19000, '', 11, 40505, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Razor Hill Grunt - Within 0-5 Range - Cast \'Cleave\''),
(6649, 0, 2, 0, 9, 0, 100, 0, 5, 30, 12000, 18000, '', 11, 15495, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Lady Sesspira - Within 5-30 Range - Cast \'Explosive Shot\''),
(6649, 0, 1, 0, 2, 0, 100, 1, 0, 15, 0, 0, '', 25, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Sesspira - Between 0-15% Health - Flee For Assist (No Repeat)'),
(6649, 0, 0, 0, 0, 0, 100, 0, 0, 0, 2300, 3900, '', 11, 15547, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Lady Sesspira - In Combat - Cast \'Shoot\''),
(6649, 0, 3, 0, 0, 0, 100, 0, 4000, 7000, 15000, 22000, '', 11, 20299, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Lady Sesspira - In Combat - Cast \'Forked Lightning\''),
(7606, 0, 3, 0, 0, 0, 80, 2, 8000, 10000, 15000, 18250, '', 11, 11990, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Oro Eyegouge - In Combat - Cast \'Rain of Fire\' (Normal Dungeon)'),
(7606, 0, 2, 0, 0, 0, 80, 2, 5000, 7000, 23000, 27000, '', 11, 11962, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Oro Eyegouge - In Combat - Cast \'Immolate\' (Normal Dungeon)'),
(7606, 0, 0, 0, 4, 0, 100, 3, 0, 0, 0, 0, '', 11, 12741, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Oro Eyegouge - On Aggro - Cast \'Curse of Weakness\' (No Repeat) (Normal Dungeon)'),
(7606, 0, 1, 0, 0, 0, 100, 2, 0, 0, 2400, 3800, '', 11, 9613, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Oro Eyegouge - In Combat CMC - Cast \'Shadow Bolt\' (Normal Dungeon)'),
(7843, 0, 5, 0, 2, 0, 100, 1, 0, 15, 0, 0, '', 25, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gnomeregan Evacuee - Between 0-15% Health - Flee For Assist (No Repeat)'),
(7843, 0, 4, 0, 2, 0, 100, 0, 0, 30, 30000, 45000, '', 11, 29580, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gnomeregan Evacuee - Between 0-30% Health - Cast \'Heal\''),
(7843, 0, 3, 0, 0, 0, 100, 0, 7000, 9000, 13000, 16000, '', 11, 25712, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Gnomeregan Evacuee - In Combat - Cast \'Heroic Strike\''),
(7843, 0, 2, 0, 9, 0, 100, 0, 0, 5, 17000, 23000, '', 11, 9080, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Gnomeregan Evacuee - Within 0-5 Range - Cast \'Hamstring\''),
(7843, 0, 1, 0, 0, 0, 100, 0, 0, 0, 2300, 3900, '', 11, 6660, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Gnomeregan Evacuee - In Combat CMC - Cast \'Shoot\''),
(7843, 0, 0, 0, 1, 0, 100, 1, 1000, 1000, 0, 0, '', 11, 7165, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gnomeregan Evacuee - Out of Combat - Cast \'Battle Stance\''),
(7956, 0, 0, 1, 4, 0, 100, 513, 0, 0, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Kindal Moonweaver - On Aggro - Disable Combat Movement (No Repeat)'),
(7956, 0, 1, 2, 61, 0, 100, 513, 0, 0, 0, 0, '', 11, 6660, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Kindal Moonweaver - On Aggro - Cast \'Shoot\' (No Repeat)'),
(7956, 0, 2, 3, 61, 0, 100, 513, 0, 0, 0, 0, '', 20, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Kindal Moonweaver - On Aggro - Stop Attacking (No Repeat)'),
(7956, 0, 3, 0, 61, 0, 100, 513, 0, 0, 0, 0, '', 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Kindal Moonweaver - On Aggro - Set Event Phase 1 (No Repeat)'),
(7956, 0, 4, 5, 9, 1, 100, 0, 5, 30, 2300, 3900, '', 11, 6660, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Kindal Moonweaver - Within 5-30 Range - Cast \'Shoot\' (Phase 1)'),
(7956, 0, 5, 0, 61, 1, 100, 0, 5, 30, 2300, 3900, '', 40, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Kindal Moonweaver - Within 5-30 Range - Set Sheath Ranged (Phase 1)'),
(7956, 0, 6, 7, 9, 1, 100, 512, 30, 80, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Kindal Moonweaver - Within 30-80 Range - Enable Combat Movement (Phase 1)'),
(7956, 0, 7, 0, 61, 1, 100, 512, 30, 80, 0, 0, '', 20, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Kindal Moonweaver - Within 30-80 Range - Start Attacking (Phase 1)'),
(7956, 0, 8, 9, 9, 1, 100, 512, 0, 10, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Kindal Moonweaver - Within 0-10 Range - Enable Combat Movement (Phase 1)'),
(7956, 0, 9, 10, 61, 1, 100, 512, 0, 10, 0, 0, '', 40, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Kindal Moonweaver - Within 0-10 Range - Set Sheath Melee (Phase 1)'),
(7956, 0, 10, 0, 61, 1, 100, 512, 0, 10, 0, 0, '', 20, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Kindal Moonweaver - Within 0-10 Range - Start Attacking (Phase 1)'),
(7956, 0, 11, 12, 9, 1, 100, 512, 11, 25, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Kindal Moonweaver - Within 11-25 Range - Disable Combat Movement (Phase 1)'),
(7956, 0, 12, 13, 61, 1, 100, 512, 11, 25, 0, 0, '', 20, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Kindal Moonweaver - Within 11-25 Range - Stop Attacking (Phase 1)'),
(7956, 0, 13, 0, 61, 1, 100, 512, 11, 25, 0, 0, '', 40, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Kindal Moonweaver - Within 11-25 Range - Set Sheath Ranged (Phase 1)'),
(7956, 0, 14, 15, 7, 1, 100, 1, 0, 0, 0, 0, '', 40, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Kindal Moonweaver - On Evade - Set Sheath Melee (Phase 1) (No Repeat)'),
(7956, 0, 15, 0, 61, 1, 100, 513, 0, 0, 0, 0, '', 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Kindal Moonweaver - On Evade - Set Event Phase 0 (Phase 1) (No Repeat)'),
(7956, 0, 16, 5, 9, 1, 100, 0, 5, 30, 19000, 22000, '', 11, 14443, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Kindal Moonweaver - Within 5-30 Range - Cast \'Multi-Shot\' (Phase 1)'),
(8147, 0, 0, 1, 4, 0, 100, 513, 0, 0, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Camp Mojache Brave - On Aggro - Disable Combat Movement (No Repeat)'),
(8147, 0, 1, 2, 61, 0, 100, 513, 0, 0, 0, 0, '', 11, 95826, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Camp Mojache Brave - On Aggro - Cast \'Shoot\' (No Repeat)'),
(8147, 0, 2, 3, 61, 0, 100, 513, 0, 0, 0, 0, '', 20, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Camp Mojache Brave - On Aggro - Stop Attacking (No Repeat)'),
(8147, 0, 3, 0, 61, 0, 100, 513, 0, 0, 0, 0, '', 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Camp Mojache Brave - On Aggro - Set Event Phase 1 (No Repeat)'),
(8147, 0, 4, 5, 9, 1, 100, 0, 5, 30, 2300, 3900, '', 11, 95826, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Camp Mojache Brave - Within 5-30 Range - Cast \'Shoot\' (Phase 1)'),
(8147, 0, 5, 0, 61, 1, 100, 0, 5, 30, 2300, 3900, '', 40, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Camp Mojache Brave - Within 5-30 Range - Set Sheath Ranged (Phase 1)'),
(8147, 0, 6, 7, 9, 1, 100, 512, 30, 80, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Camp Mojache Brave - Within 30-80 Range - Enable Combat Movement (Phase 1)'),
(8147, 0, 7, 0, 61, 1, 100, 512, 30, 80, 0, 0, '', 20, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Camp Mojache Brave - Within 30-80 Range - Start Attacking (Phase 1)'),
(8147, 0, 8, 9, 9, 1, 100, 512, 0, 10, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Camp Mojache Brave - Within 0-10 Range - Enable Combat Movement (Phase 1)'),
(8147, 0, 9, 10, 61, 1, 100, 512, 0, 10, 0, 0, '', 40, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Camp Mojache Brave - Within 0-10 Range - Set Sheath Melee (Phase 1)'),
(8147, 0, 10, 0, 61, 1, 100, 512, 0, 10, 0, 0, '', 20, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Camp Mojache Brave - Within 0-10 Range - Start Attacking (Phase 1)'),
(8147, 0, 11, 12, 9, 1, 100, 512, 11, 25, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Camp Mojache Brave - Within 11-25 Range - Disable Combat Movement (Phase 1)'),
(8147, 0, 12, 13, 61, 1, 100, 512, 11, 25, 0, 0, '', 20, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Camp Mojache Brave - Within 11-25 Range - Stop Attacking (Phase 1)'),
(8147, 0, 13, 0, 61, 1, 100, 512, 11, 25, 0, 0, '', 40, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Camp Mojache Brave - Within 11-25 Range - Set Sheath Ranged (Phase 1)'),
(8147, 0, 14, 15, 7, 1, 100, 1, 0, 0, 0, 0, '', 40, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Camp Mojache Brave - On Evade - Set Sheath Melee (Phase 1) (No Repeat)'),
(8147, 0, 15, 0, 61, 1, 100, 513, 0, 0, 0, 0, '', 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Camp Mojache Brave - On Evade - Set Event Phase 0 (Phase 1) (No Repeat)'),
(8147, 0, 16, 5, 9, 1, 100, 0, 0, 5, 9000, 11000, '', 11, 40505, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Camp Mojache Brave - Within 0-5 Range - Cast \'Cleave\' (Phase 1)'),
(8151, 0, 0, 0, 0, 0, 100, 0, 0, 0, 2300, 3900, '', 11, 95826, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Nijel\'s Point Guard - In Combat - Cast \'Shoot\''),
(8151, 0, 1, 0, 9, 0, 100, 0, 0, 5, 11000, 17000, '', 11, 12170, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Nijel\'s Point Guard - Within 0-5 Range - Cast \'Revenge\''),
(8151, 0, 2, 0, 9, 0, 100, 0, 0, 4, 19000, 22000, '', 11, 12169, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Nijel\'s Point Guard - Within 0-4 Range - Cast \'Shield Block\''),
(8154, 0, 0, 0, 0, 0, 100, 0, 0, 0, 2300, 3900, '', 11, 95826, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Ghost Walker Brave - In Combat - Cast \'Shoot\''),
(8154, 0, 1, 0, 9, 0, 100, 0, 0, 5, 12000, 15000, '', 11, 40505, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Ghost Walker Brave - Within 0-5 Range - Cast \'Cleave\''),
(11488, 0, 0, 0, 0, 0, 100, 2, 7000, 12000, 60000, 65000, '', 11, 22908, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Illyanna Ravenoak - In Combat - Cast \'Volley\' (Phase 1) (No Repeat) (Normal Dungeon)'),
(11488, 0, 1, 0, 0, 0, 100, 2, 1000, 3000, 6000, 9000, '', 11, 22940, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Illyanna Ravenoak - In Combat - Cast \'Arcane Blast\' (Phase 1) (No Repeat) (Normal Dungeon)'),
(11488, 0, 2, 0, 0, 0, 100, 2, 5000, 9000, 12000, 15000, '', 11, 22914, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Illyanna Ravenoak - In Combat - Cast \'Concussive Shot\' (Phase 1) (No Repeat) (Normal Dungeon)'),
(11488, 0, 3, 0, 0, 0, 100, 2, 3000, 5000, 25000, 35000, '', 11, 22910, 32, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Illyanna Ravenoak - In Combat - Cast \'Immolation Trap\' (Phase 1) (No Repeat) (Normal Dungeon)'),
(12322, 0, 3, 0, 2, 0, 100, 1, 0, 15, 0, 0, '', 25, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Quel\'Lithien Protector - 0-15% Health - Flee For Assist (No Repeat)'),
(12322, 0, 2, 0, 9, 0, 100, 0, 0, 5, 8000, 13000, '', 11, 11978, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Quel\'Lithien Protector - 0-5 Range - Cast \'Kick\''),
(12322, 0, 1, 0, 9, 0, 100, 0, 0, 5, 5000, 7000, '', 11, 12057, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Quel\'Lithien Protector - 0-5 Range - Cast \'Strike\''),
(12322, 0, 0, 0, 0, 0, 100, 0, 0, 0, 2300, 3900, '', 11, 15547, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Quel\'Lithien Protector - Combat CMC - Cast \'Shoot\''),
(12856, 0, 2, 0, 9, 0, 100, 0, 0, 5, 7100, 15300, '', 11, 8646, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Ashenvale Outrunner - Within 0-5 Range - Cast \'Snap Kick\''),
(12856, 0, 1, 0, 9, 0, 100, 0, 5, 30, 35900, 52300, '', 11, 18545, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Ashenvale Outrunner - Within 5-30 Range - Cast \'Scorpid Sting\''),
(12856, 0, 0, 0, 0, 0, 100, 0, 0, 0, 2300, 3900, '', 11, 6660, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Ashenvale Outrunner - Combat CMC - Cast \'Shoot\''),
(12864, 0, 0, 0, 0, 0, 100, 0, 0, 0, 2300, 3900, '', 11, 6660, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Warsong Outrider - In Combat - Cast \'Shoot\''),
(12864, 0, 1, 0, 9, 0, 100, 0, 5, 30, 24000, 35000, '', 11, 18545, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Warsong Outrider - Within 5-30 Range - Cast \'Scorpid Sting\''),
(14347, 0, 0, 0, 62, 0, 100, 0, 5704, 0, 0, 0, '', 85, 22958, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Highlord Demitrian - On Gossip Complete - Cast Summon Vessel of Rebirth DND'),
(14347, 0, 1, 0, 20, 0, 100, 0, 7786, 0, 0, 0, '', 12, 14435, 6, 60000, 0, 0, 0, 8, 0, 0, 0, -6241.77, 1717.14, 4.25042, 0.680879, 'Highlord Demitrian - On Quest Thunderaan the Windseeker Finished - Summon Creature Prince Thunderaan at XYZO'),
(14715, 0, 1, 0, 9, 0, 100, 512, 0, 5, 12000, 22000, '', 11, 15496, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Silverwing Elite - Within 0-5 Range - Cast \'Cleave\''),
(14715, 0, 0, 0, 0, 0, 100, 0, 0, 0, 2300, 3900, '', 11, 15620, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Silverwing Elite - In Combat - Cast \'Shoot\''),
(14753, 0, 4, 0, 9, 0, 100, 512, 0, 20, 5000, 9000, '', 11, 6533, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Illiyana Moonblaze - Within 0-20 Range - Cast \'Net\''),
(14753, 0, 5, 0, 2, 0, 100, 1, 0, 30, 0, 0, '', 11, 3019, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Illiyana Moonblaze - Between 0-30% Health - Cast \'Frenzy\' (No Repeat)'),
(14753, 0, 6, 0, 2, 0, 100, 1, 0, 30, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Illiyana Moonblaze - Between 0-30% Health - Say Line 0 (No Repeat)'),
(14753, 0, 3, 0, 9, 0, 100, 512, 5, 30, 22000, 27000, '', 11, 21390, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Illiyana Moonblaze - Within 5-30 Range - Cast \'Multi-Shot\''),
(14753, 0, 2, 0, 61, 0, 100, 1, 0, 15, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Illiyana Moonblaze - Between 0-15% Health - Say Line 0 (No Repeat)'),
(14753, 0, 1, 2, 2, 0, 100, 1, 0, 15, 0, 0, '', 25, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Illiyana Moonblaze - Between 0-15% Health - Flee For Assist (No Repeat)'),
(14753, 0, 0, 0, 0, 0, 100, 0, 0, 0, 2300, 3900, '', 11, 22907, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Illiyana Moonblaze - In Combat - Cast \'Shoot\''),
(17725, 0, 0, 1, 4, 0, 100, 7, 0, 0, 0, 0, '', 11, 34161, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Underbog Lurker - On Aggro - Cast \'Wild Growth\' (No Repeat) (Dungeon)'),
(17725, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Underbog Lurker - On Aggro - Say Line 0 (No Repeat) (Dungeon)'),
(17725, 0, 2, 3, 0, 0, 100, 519, 5800, 10800, 0, 0, '', 28, 34151, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Underbog Lurker - In Combat - Remove Aura \'Living Spirit\' (No Repeat) (Dungeon)'),
(17725, 0, 3, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Underbog Lurker - In Combat - Say Line 1 (No Repeat) (Dungeon)'),
(17729, 0, 0, 1, 1, 0, 100, 519, 0, 0, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Murkblood Spearman - Out of Combat - Disable Combat Movement (No Repeat) (Dungeon)'),
(17729, 0, 1, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 20, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Murkblood Spearman - Out of Combat - Stop Attacking (No Repeat) (Dungeon)'),
(17729, 0, 2, 3, 4, 0, 100, 3, 0, 0, 0, 0, '', 11, 22887, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Murkblood Spearman - On Aggro - Cast \'Throw\' (No Repeat) (Normal Dungeon)'),
(17729, 0, 3, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Murkblood Spearman - On Aggro - Increment Phase By 1 (No Repeat) (Normal Dungeon)'),
(17729, 0, 4, 5, 9, 0, 100, 2, 5, 30, 2100, 3500, '', 11, 22887, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Murkblood Spearman - Within 5-30 Range - Cast \'Throw\' (Normal Dungeon)'),
(17729, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, '', 40, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Murkblood Spearman - Within 5-30 Range - Set Sheath Ranged (Normal Dungeon)'),
(17729, 0, 6, 7, 4, 0, 100, 5, 0, 0, 0, 0, '', 11, 40317, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Murkblood Spearman - On Aggro - Cast \'Throw\' (No Repeat) (Heroic Dungeon)'),
(17729, 0, 7, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Murkblood Spearman - On Aggro - Increment Phase By 1 (No Repeat) (Heroic Dungeon)'),
(17729, 0, 8, 9, 9, 0, 100, 4, 5, 30, 2100, 3500, '', 11, 40317, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Murkblood Spearman - Within 5-30 Range - Cast \'Throw\' (Heroic Dungeon)'),
(17729, 0, 9, 0, 61, 0, 100, 0, 0, 0, 0, 0, '', 40, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Murkblood Spearman - Within 5-30 Range - Set Sheath Ranged (Heroic Dungeon)'),
(17729, 0, 10, 11, 9, 0, 100, 519, 25, 80, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Murkblood Spearman - Within 25-80 Range - Enable Combat Movement (No Repeat) (Dungeon)'),
(17729, 0, 11, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 20, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Murkblood Spearman - Within 25-80 Range - Start Attacking (No Repeat) (Dungeon)'),
(17729, 0, 12, 13, 9, 0, 100, 519, 0, 5, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Murkblood Spearman - Within 0-5 Range - Enable Combat Movement (No Repeat) (Dungeon)'),
(17729, 0, 13, 14, 61, 0, 100, 512, 0, 0, 0, 0, '', 40, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Murkblood Spearman - Within 0-5 Range - Set Sheath Melee (No Repeat) (Dungeon)'),
(17729, 0, 14, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 20, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Murkblood Spearman - Within 0-5 Range - Start Attacking (No Repeat) (Dungeon)'),
(17729, 0, 15, 16, 9, 0, 100, 512, 0, 0, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Murkblood Spearman - Within 0-0 Range - Disable Combat Movement'),
(17729, 0, 16, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 20, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Murkblood Spearman - Within 0-0 Range - Stop Attacking'),
(17729, 0, 17, 18, 0, 0, 100, 2, 8800, 13600, 8200, 13300, '', 11, 31407, 1, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Murkblood Spearman - In Combat - Cast \'Viper Sting\' (Normal Dungeon)'),
(17729, 0, 18, 0, 61, 0, 100, 0, 0, 0, 0, 0, '', 40, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Murkblood Spearman - In Combat - Set Sheath Ranged (Normal Dungeon)'),
(17729, 0, 19, 20, 0, 0, 100, 4, 8800, 13600, 8200, 13300, '', 11, 39413, 1, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Murkblood Spearman - In Combat - Cast \'Viper Sting\' (Heroic Dungeon)'),
(17729, 0, 20, 0, 61, 0, 100, 0, 0, 0, 0, 0, '', 40, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Murkblood Spearman - In Combat - Set Sheath Ranged (Heroic Dungeon)'),
(17729, 0, 21, 22, 2, 0, 100, 7, 0, 30, 0, 0, '', 11, 8599, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Murkblood Spearman - Between 0-30% Health - Cast \'Enrage\' (No Repeat) (Dungeon)'),
(17729, 0, 22, 0, 61, 0, 100, 0, 0, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Murkblood Spearman - Between 0-30% Health - Say Line 0 (No Repeat) (Dungeon)'),
(17729, 0, 23, 0, 7, 0, 100, 7, 0, 0, 0, 0, '', 40, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Murkblood Spearman - On Evade - Set Sheath Melee (No Repeat) (Dungeon)'),
(17820, 0, 4, 0, 2, 0, 100, 7, 0, 15, 0, 0, '', 25, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Durnholde Rifleman - Between 0-15% Health - Flee For Assist (No Repeat) (Dungeon)'),
(17820, 0, 3, 0, 9, 0, 100, 4, 5, 30, 9000, 15000, '', 11, 38383, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Durnholde Rifleman - Within 5-30 Range - Cast \'Multi-Shot\' (Heroic Dungeon)'),
(17820, 0, 2, 0, 9, 0, 100, 2, 5, 30, 9000, 15000, '', 11, 31942, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Durnholde Rifleman - Within 5-30 Range - Cast \'Multi-Shot\' (Normal Dungeon)'),
(17820, 0, 1, 0, 0, 0, 100, 4, 0, 0, 2300, 5000, '', 11, 22907, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Durnholde Rifleman - In Combat CMC - Cast \'Shoot\' (Heroic Dungeon)'),
(17820, 0, 0, 0, 0, 0, 100, 2, 0, 0, 2300, 5000, '', 11, 16100, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Durnholde Rifleman - In Combat CMC - Cast \'Shoot\' (Normal Dungeon)'),
(18094, 0, 0, 1, 1, 0, 100, 519, 0, 0, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tarren Mill Lookout - Out of Combat - Disable Combat Movement (No Repeat) (Dungeon)'),
(18094, 0, 1, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 20, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tarren Mill Lookout - Out of Combat - Stop Attacking (No Repeat) (Dungeon)'),
(18094, 0, 2, 3, 4, 0, 100, 3, 0, 0, 0, 0, '', 11, 15620, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Tarren Mill Lookout - On Aggro - Cast \'Shoot\' (No Repeat) (Normal Dungeon)'),
(18094, 0, 3, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tarren Mill Lookout - On Aggro - Increment Phase By 1 (No Repeat) (Normal Dungeon)'),
(18094, 0, 4, 5, 9, 1, 100, 2, 5, 30, 2300, 5000, '', 11, 15620, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Tarren Mill Lookout - Within 5-30 Range - Cast \'Shoot\' (Phase 1) (Normal Dungeon)'),
(18094, 0, 5, 0, 61, 1, 100, 0, 0, 0, 0, 0, '', 40, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tarren Mill Lookout - Within 5-30 Range - Set Sheath Ranged (Phase 1) (Normal Dungeon)'),
(18094, 0, 6, 7, 4, 0, 100, 5, 0, 0, 0, 0, '', 11, 16100, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Tarren Mill Lookout - On Aggro - Cast \'Shoot\' (No Repeat) (Heroic Dungeon)'),
(18094, 0, 7, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tarren Mill Lookout - On Aggro - Increment Phase By 1 (No Repeat) (Heroic Dungeon)'),
(18094, 0, 8, 9, 9, 1, 100, 4, 5, 30, 2300, 5000, '', 11, 16100, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Tarren Mill Lookout - Within 5-30 Range - Cast \'Shoot\' (Phase 1) (Heroic Dungeon)'),
(18094, 0, 9, 0, 61, 1, 100, 0, 0, 0, 0, 0, '', 40, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tarren Mill Lookout - Within 5-30 Range - Set Sheath Ranged (Phase 1) (Heroic Dungeon)'),
(18094, 0, 10, 11, 9, 1, 100, 519, 25, 80, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tarren Mill Lookout - Within 25-80 Range - Enable Combat Movement (Phase 1) (No Repeat) (Dungeon)'),
(18094, 0, 11, 0, 61, 1, 100, 512, 0, 0, 0, 0, '', 20, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tarren Mill Lookout - Within 25-80 Range - Start Attacking (Phase 1) (No Repeat) (Dungeon)'),
(18094, 0, 12, 13, 9, 1, 100, 519, 0, 5, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tarren Mill Lookout - Within 0-5 Range - Enable Combat Movement (Phase 1) (No Repeat) (Dungeon)'),
(18094, 0, 13, 14, 61, 1, 100, 512, 0, 0, 0, 0, '', 40, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tarren Mill Lookout - Within 0-5 Range - Set Sheath Melee (Phase 1) (No Repeat) (Dungeon)'),
(18094, 0, 14, 0, 61, 1, 100, 512, 0, 0, 0, 0, '', 20, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tarren Mill Lookout - Within 0-5 Range - Start Attacking (Phase 1) (No Repeat) (Dungeon)'),
(18094, 0, 15, 16, 9, 1, 100, 519, 5, 15, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tarren Mill Lookout - Within 5-15 Range - Disable Combat Movement (Phase 1) (No Repeat) (Dungeon)'),
(18094, 0, 16, 0, 61, 1, 100, 512, 0, 0, 0, 0, '', 20, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tarren Mill Lookout - Within 5-15 Range - Stop Attacking (Phase 1) (No Repeat) (Dungeon)'),
(18094, 0, 17, 18, 0, 1, 100, 6, 14000, 19000, 14000, 19000, '', 11, 17174, 1, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Tarren Mill Lookout - In Combat - Cast \'Concussive Shot\' (Phase 1) (Dungeon)'),
(18094, 0, 18, 0, 61, 1, 100, 0, 0, 0, 0, 0, '', 40, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tarren Mill Lookout - In Combat - Set Sheath Ranged (Phase 1) (Dungeon)'),
(18094, 0, 19, 20, 0, 1, 100, 6, 8000, 11000, 17000, 21000, '', 11, 35511, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Tarren Mill Lookout - In Combat - Cast \'Serpent Sting\' (Phase 1) (Dungeon)'),
(18094, 0, 20, 0, 61, 1, 100, 0, 0, 0, 0, 0, '', 40, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tarren Mill Lookout - In Combat - Set Sheath Ranged (Phase 1) (Dungeon)'),
(18094, 0, 21, 22, 2, 0, 100, 519, 0, 15, 0, 0, '', 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tarren Mill Lookout - Between 0-15% Health - Increment Phase By 1 (No Repeat) (Dungeon)'),
(18094, 0, 22, 23, 61, 0, 100, 512, 0, 0, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tarren Mill Lookout - Between 0-15% Health - Enable Combat Movement (No Repeat) (Dungeon)'),
(18094, 0, 23, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 25, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Tarren Mill Lookout - Between 0-15% Health - Flee For Assist (No Repeat) (Dungeon)'),
(18094, 0, 24, 0, 7, 0, 100, 7, 0, 0, 0, 0, '', 40, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tarren Mill Lookout - On Evade - Set Sheath Melee (No Repeat) (Dungeon)'),
(22231, 0, 0, 0, 20, 0, 100, 512, 10813, 0, 0, 0, '', 28, 38495, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Zezzak - On Quest \'The Eyes of Grillok\' Finished - Remove Aura \'Eye of Grillok\''),
(23619, 0, 0, 0, 1, 0, 100, 1, 28000, 28000, 0, 0, '', 11, 42505, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bergrisst - Out of Combat - Cast \'L70ETC Flare Effect\''),
(23619, 0, 1, 0, 1, 0, 100, 0, 28000, 28000, 0, 0, '', 11, 37718, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bergrisst - Out of Combat - Cast \'Clear Target Auras\''),
(23619, 0, 2, 0, 1, 0, 100, 1, 36500, 36500, 0, 0, '', 5, 402, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bergrisst - Out of Combat - Play Emote 402'),
(23619, 0, 3, 0, 1, 0, 100, 1, 42505, 42505, 0, 0, '', 5, 403, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bergrisst - Out of Combat - Play Emote 403'),
(23619, 0, 4, 0, 1, 0, 100, 1, 80500, 80500, 0, 0, '', 5, 404, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bergrisst - Out of Combat - Play Emote 404'),
(23619, 0, 5, 0, 1, 0, 100, 1, 94000, 94000, 0, 0, '', 5, 405, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bergrisst - Out of Combat - Play Emote 405'),
(23619, 0, 6, 0, 1, 0, 100, 1, 113500, 113500, 0, 0, '', 5, 402, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bergrisst - Out of Combat - Play Emote 402'),
(23619, 0, 7, 0, 1, 0, 100, 1, 137100, 137100, 0, 0, '', 5, 403, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bergrisst - Out of Combat - Play Emote 403'),
(23619, 0, 8, 0, 1, 0, 100, 1, 149000, 149000, 0, 0, '', 11, 34126, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bergrisst - Out of Combat - Cast \'Spotlight\''),
(23619, 0, 9, 0, 1, 0, 100, 1, 158300, 158300, 0, 0, '', 5, 404, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bergrisst - Out of Combat - Play Emote 404'),
(23619, 0, 10, 0, 1, 0, 100, 1, 172700, 172700, 0, 0, '', 5, 405, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bergrisst - Out of Combat - Play Emote 405'),
(23619, 0, 11, 0, 1, 0, 100, 1, 197500, 197500, 0, 0, '', 5, 402, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bergrisst - Out of Combat - Play Emote 402'),
(23619, 0, 12, 0, 1, 0, 100, 1, 213000, 213000, 0, 0, '', 11, 41347, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bergrisst - Out of Combat - Cast \'Spotlight\''),
(23619, 0, 13, 0, 1, 0, 100, 1, 220500, 220500, 0, 0, '', 5, 403, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bergrisst - Out of Combat - Play Emote 403'),
(23619, 0, 14, 0, 1, 0, 100, 1, 240500, 240500, 0, 0, '', 5, 404, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bergrisst - Out of Combat - Play Emote 404'),
(23619, 0, 15, 0, 1, 0, 100, 1, 256500, 256500, 0, 0, '', 5, 405, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bergrisst - Out of Combat - Play Emote 405'),
(23619, 0, 16, 0, 1, 0, 100, 1, 275500, 275500, 0, 0, '', 5, 402, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bergrisst - Out of Combat - Play Emote 402'),
(23619, 0, 17, 0, 1, 0, 100, 1, 280000, 280000, 0, 0, '', 11, 42505, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bergrisst - Out of Combat - Cast \'L70ETC Flare Effect\''),
(23619, 0, 18, 0, 1, 0, 100, 1, 280800, 280800, 0, 0, '', 11, 16380, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bergrisst - Out of Combat - Cast \'Greater Invisibility\''),
(23623, 0, 0, 0, 1, 0, 100, 1, 24000, 24000, 0, 0, '', 11, 37718, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Chief Thunder-Skins - Out of Combat - Cast \'Clear Target Auras\''),
(23623, 0, 1, 0, 1, 0, 100, 1, 24000, 24000, 0, 0, '', 11, 42505, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Chief Thunder-Skins - Out of Combat - Cast \'L70ETC Flare Effect\''),
(23623, 0, 2, 0, 1, 0, 100, 1, 34200, 34200, 0, 0, '', 5, 402, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Chief Thunder-Skins - Out of Combat - Play Emote 402'),
(23623, 0, 3, 0, 1, 0, 100, 1, 48700, 48700, 0, 0, '', 5, 403, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Chief Thunder-Skins - Out of Combat - Play Emote 403'),
(23623, 0, 4, 0, 1, 0, 100, 1, 61000, 61000, 0, 0, '', 5, 404, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Chief Thunder-Skins - Out of Combat - Play Emote 404'),
(23623, 0, 5, 0, 1, 0, 100, 1, 73000, 73000, 0, 0, '', 5, 405, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Chief Thunder-Skins - Out of Combat - Play Emote 405'),
(23623, 0, 6, 0, 1, 0, 100, 1, 95700, 95700, 0, 0, '', 5, 402, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Chief Thunder-Skins - Out of Combat - Play Emote 402'),
(23623, 0, 7, 0, 1, 0, 100, 1, 120100, 120100, 0, 0, '', 5, 404, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Chief Thunder-Skins - Out of Combat - Play Emote 404'),
(23623, 0, 8, 0, 1, 0, 100, 1, 132000, 132000, 0, 0, '', 5, 405, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Chief Thunder-Skins - Out of Combat - Play Emote 405'),
(23623, 0, 9, 0, 1, 0, 100, 1, 152500, 152500, 0, 0, '', 5, 402, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Chief Thunder-Skins - Out of Combat - Play Emote 402'),
(23623, 0, 10, 0, 1, 0, 100, 1, 165600, 165600, 0, 0, '', 5, 403, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Chief Thunder-Skins - Out of Combat - Play Emote 403'),
(23623, 0, 11, 0, 1, 0, 100, 1, 178900, 178900, 0, 0, '', 5, 404, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Chief Thunder-Skins - Out of Combat - Play Emote 404'),
(23623, 0, 12, 0, 1, 0, 100, 1, 190300, 190300, 0, 0, '', 5, 405, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Chief Thunder-Skins - Out of Combat - Play Emote 405'),
(23623, 0, 13, 0, 1, 0, 100, 1, 209800, 209800, 0, 0, '', 5, 402, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Chief Thunder-Skins - Out of Combat - Play Emote 402'),
(23623, 0, 14, 0, 1, 0, 100, 1, 223600, 223600, 0, 0, '', 5, 403, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Chief Thunder-Skins - Out of Combat - Play Emote 403'),
(23623, 0, 15, 0, 1, 0, 100, 1, 237000, 237000, 0, 0, '', 5, 404, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Chief Thunder-Skins - Out of Combat - Play Emote 404'),
(23623, 0, 16, 0, 1, 0, 100, 1, 251300, 251300, 0, 0, '', 5, 405, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Chief Thunder-Skins - Out of Combat - Play Emote 405'),
(23623, 0, 17, 0, 1, 0, 100, 1, 271400, 271400, 0, 0, '', 5, 402, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Chief Thunder-Skins - Out of Combat - Play Emote 402'),
(23623, 0, 18, 0, 1, 0, 100, 1, 280000, 280000, 0, 0, '', 11, 42505, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Chief Thunder-Skins - Out of Combat - Cast \'L70ETC Flare Effect\''),
(23623, 0, 19, 0, 1, 0, 100, 1, 280800, 280800, 0, 0, '', 11, 16380, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Chief Thunder-Skins - Out of Combat - Cast \'Greater Invisibility\''),
(23624, 0, 0, 0, 1, 0, 100, 1, 13000, 13000, 0, 0, '', 11, 37718, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mai\'Kyl - Out of Combat - Cast \'Clear Target Auras\''),
(23624, 0, 1, 0, 1, 0, 100, 1, 13000, 13000, 0, 0, '', 11, 42505, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mai\'Kyl - Out of Combat - Cast \'L70ETC Flare Effect\''),
(23624, 0, 2, 0, 1, 0, 100, 1, 24700, 24700, 0, 0, '', 5, 402, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mai\'Kyl - Out of Combat - Play Emote 402'),
(23624, 0, 3, 0, 1, 0, 100, 1, 38600, 38600, 0, 0, '', 5, 403, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mai\'Kyl - Out of Combat - Play Emote 403'),
(23624, 0, 4, 0, 1, 0, 100, 1, 52700, 52700, 0, 0, '', 5, 404, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mai\'Kyl - Out of Combat - Play Emote 404'),
(23624, 0, 5, 0, 1, 0, 100, 1, 73700, 73700, 0, 0, '', 5, 402, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mai\'Kyl - Out of Combat - Play Emote 402'),
(23624, 0, 6, 0, 1, 0, 100, 1, 90000, 90000, 0, 0, '', 5, 403, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mai\'Kyl - Out of Combat - Play Emote 403'),
(23624, 0, 7, 0, 1, 0, 100, 1, 105200, 105200, 0, 0, '', 5, 404, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mai\'Kyl - Out of Combat - Play Emote 404'),
(23624, 0, 8, 0, 1, 0, 100, 1, 108000, 108000, 0, 0, '', 5, 402, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mai\'Kyl - Out of Combat - Play Emote 402'),
(23624, 0, 9, 0, 1, 0, 100, 1, 146400, 146400, 0, 0, '', 5, 403, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mai\'Kyl - Out of Combat - Play Emote 403'),
(23624, 0, 10, 0, 1, 0, 100, 1, 160000, 160000, 0, 0, '', 5, 404, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mai\'Kyl - Out of Combat - Play Emote 404'),
(23624, 0, 11, 0, 1, 0, 100, 1, 182000, 182000, 0, 0, '', 5, 402, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mai\'Kyl - Out of Combat - Play Emote 402'),
(23624, 0, 12, 0, 1, 0, 100, 1, 199400, 199400, 0, 0, '', 5, 403, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mai\'Kyl - Out of Combat - Play Emote 403'),
(23624, 0, 13, 0, 1, 0, 100, 1, 215200, 215200, 0, 0, '', 5, 404, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mai\'Kyl - Out of Combat - Play Emote 404'),
(23624, 0, 14, 0, 1, 0, 100, 1, 234700, 234700, 0, 0, '', 5, 402, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mai\'Kyl - Out of Combat - Play Emote 402'),
(23624, 0, 15, 0, 1, 0, 100, 1, 251200, 251200, 0, 0, '', 5, 403, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mai\'Kyl - Out of Combat - Play Emote 403'),
(23624, 0, 16, 0, 1, 0, 100, 1, 265400, 265400, 0, 0, '', 5, 404, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mai\'Kyl - Out of Combat - Play Emote 404'),
(23624, 0, 17, 0, 1, 0, 100, 1, 280000, 280000, 0, 0, '', 11, 42505, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mai\'Kyl - Out of Combat - Cast \'L70ETC Flare Effect\''),
(23624, 0, 18, 0, 1, 0, 100, 1, 280800, 280800, 0, 0, '', 11, 16380, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mai\'Kyl - Out of Combat - Cast \'Greater Invisibility\''),
(23625, 0, 0, 0, 1, 0, 100, 1, 10000, 10000, 0, 0, '', 11, 37718, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Samuro - Out of Combat - Cast \'Clear Target Auras\''),
(23625, 0, 1, 0, 1, 0, 100, 1, 10000, 10000, 0, 0, '', 11, 42505, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Samuro - Out of Combat - Cast \'L70ETC Flare Effect\''),
(23625, 0, 2, 0, 1, 0, 100, 1, 29400, 29400, 0, 0, '', 5, 403, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Samuro - Out of Combat - Play Emote 403'),
(23625, 0, 3, 0, 1, 0, 100, 1, 49500, 49500, 0, 0, '', 5, 404, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Samuro - Out of Combat - Play Emote 404'),
(23625, 0, 4, 0, 1, 0, 100, 1, 72000, 72000, 0, 0, '', 5, 405, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Samuro - Out of Combat - Play Emote 405'),
(23625, 0, 5, 0, 1, 0, 100, 1, 86400, 86400, 0, 0, '', 5, 406, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Samuro - Out of Combat - Play Emote 406'),
(23625, 0, 6, 0, 1, 0, 100, 1, 95200, 95200, 0, 0, '', 5, 407, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Samuro - Out of Combat - Play Emote 407'),
(23625, 0, 7, 0, 1, 0, 100, 1, 117400, 117400, 0, 0, '', 5, 402, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Samuro - Out of Combat - Play Emote 402'),
(23625, 0, 8, 0, 1, 0, 100, 1, 124500, 124500, 0, 0, '', 11, 42510, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Samuro - Out of Combat - Cast \'L70ETC Call Lightning\''),
(23625, 0, 9, 0, 1, 0, 100, 1, 128400, 128400, 0, 0, '', 5, 403, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Samuro - Out of Combat - Play Emote 403'),
(23625, 0, 10, 0, 1, 0, 100, 1, 148000, 148000, 0, 0, '', 5, 404, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Samuro - Out of Combat - Play Emote 404'),
(23625, 0, 11, 0, 1, 0, 100, 1, 171800, 171800, 0, 0, '', 5, 405, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Samuro - Out of Combat - Play Emote 405'),
(23625, 0, 12, 0, 1, 0, 100, 1, 184500, 184500, 0, 0, '', 5, 406, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Samuro - Out of Combat - Play Emote 406'),
(23625, 0, 13, 0, 1, 0, 100, 1, 196100, 196100, 0, 0, '', 5, 407, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Samuro - Out of Combat - Play Emote 407'),
(23625, 0, 14, 0, 1, 0, 100, 1, 227500, 227500, 0, 0, '', 5, 403, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Samuro - Out of Combat - Play Emote 403'),
(23625, 0, 15, 0, 1, 0, 100, 1, 246300, 246300, 0, 0, '', 5, 404, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Samuro - Out of Combat - Play Emote 404'),
(23625, 0, 16, 0, 1, 0, 100, 1, 272800, 272800, 0, 0, '', 5, 405, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Samuro - Out of Combat - Play Emote 405'),
(23625, 0, 17, 0, 1, 0, 100, 1, 280000, 280000, 0, 0, '', 11, 42505, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Samuro - Out of Combat - Cast \'L70ETC Flare Effect\''),
(23625, 0, 18, 0, 1, 0, 100, 1, 280800, 280800, 0, 0, '', 11, 16380, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Samuro - Out of Combat - Cast \'Greater Invisibility\''),
(23626, 0, 0, 0, 1, 0, 100, 1, 13000, 13000, 0, 0, '', 11, 37718, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sig Nicious - Out of Combat - Cast \'Clear Target Auras\''),
(23626, 0, 1, 0, 1, 0, 100, 1, 13000, 13000, 0, 0, '', 11, 42505, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sig Nicious - Out of Combat - Cast \'L70ETC Flare Effect\''),
(23626, 0, 2, 0, 1, 0, 100, 1, 22700, 22700, 0, 0, '', 5, 402, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sig Nicious - Out of Combat - Play Emote 402'),
(23626, 0, 3, 0, 1, 0, 100, 1, 38600, 38600, 0, 0, '', 5, 403, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sig Nicious - Out of Combat - Play Emote 403'),
(23626, 0, 4, 0, 1, 0, 100, 1, 49700, 49700, 0, 0, '', 5, 404, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sig Nicious - Out of Combat - Play Emote 404'),
(23626, 0, 5, 0, 1, 0, 100, 1, 63600, 63600, 0, 0, '', 5, 405, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sig Nicious - Out of Combat - Play Emote 405'),
(23626, 0, 6, 0, 1, 0, 100, 1, 89700, 89700, 0, 0, '', 5, 402, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sig Nicious - Out of Combat - Play Emote 402'),
(23626, 0, 7, 0, 1, 0, 100, 1, 102600, 102600, 0, 0, '', 5, 403, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sig Nicious - Out of Combat - Play Emote 403'),
(23626, 0, 8, 0, 1, 0, 100, 1, 114900, 114900, 0, 0, '', 5, 404, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sig Nicious - Out of Combat - Play Emote 404'),
(23626, 0, 9, 0, 1, 0, 100, 1, 129500, 129500, 0, 0, '', 5, 405, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sig Nicious - Out of Combat - Play Emote 405'),
(23626, 0, 10, 0, 1, 0, 100, 1, 155800, 155800, 0, 0, '', 5, 402, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sig Nicious - Out of Combat - Play Emote 402'),
(23626, 0, 11, 0, 1, 0, 100, 1, 170800, 170800, 0, 0, '', 5, 403, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sig Nicious - Out of Combat - Play Emote 403'),
(23626, 0, 12, 0, 1, 0, 100, 1, 182300, 182300, 0, 0, '', 5, 404, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sig Nicious - Out of Combat - Play Emote 404'),
(23626, 0, 13, 0, 1, 0, 100, 1, 196100, 196100, 0, 0, '', 5, 405, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sig Nicious - Out of Combat - Play Emote 405'),
(23626, 0, 14, 0, 1, 0, 100, 1, 223500, 223500, 0, 0, '', 5, 402, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sig Nicious - Out of Combat - Play Emote 402'),
(23626, 0, 15, 0, 1, 0, 100, 1, 239200, 239200, 0, 0, '', 5, 403, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sig Nicious - Out of Combat - Play Emote 403'),
(23626, 0, 16, 0, 1, 0, 100, 1, 251000, 251000, 0, 0, '', 5, 404, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sig Nicious - Out of Combat - Play Emote 404'),
(23626, 0, 17, 0, 1, 0, 100, 1, 264600, 264600, 0, 0, '', 5, 405, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sig Nicious - Out of Combat - Play Emote 405'),
(23626, 0, 18, 0, 1, 0, 100, 1, 280000, 280000, 0, 0, '', 11, 42505, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sig Nicious - Out of Combat - Cast \'L70ETC Flare Effect\''),
(23626, 0, 19, 0, 1, 0, 100, 1, 280800, 280800, 0, 0, '', 11, 16380, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sig Nicious - Out of Combat - Cast \'Greater Invisibility\''),
(23636, 0, 0, 0, 0, 0, 100, 0, 0, 0, 2300, 3900, '', 11, 23337, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Mudsprocket Bruiser - In Combat - Cast \'Shoot\''),
(23636, 0, 1, 0, 9, 0, 100, 0, 0, 20, 8000, 9000, '', 11, 12024, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Mudsprocket Bruiser - Within 0-20 Range - Cast \'Net\''),
(23664, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, '', 11, 43037, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Winterskorn Warrior - On Spellhit \'Dismembering Corpse\' - Cast \'Gruesome, But Necessary: Kill Credit\''),
(23664, 0, 2, 0, 0, 0, 100, 0, 1000, 15000, 7200, 35000, '', 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Winterskorn Warrior - In Combat - Say Line 0'),
(23664, 0, 3, 0, 1, 0, 100, 0, 0, 60000, 15000, 70000, '', 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Winterskorn Warrior - Out of Combat - Say Line 1'),
(23664, 0, 0, 1, 8, 0, 100, 0, 43036, 0, 0, 0, '', 11, 43059, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Winterskorn Warrior - On Spellhit \'Dismembering Corpse\' - Cast \'Gruesome, But Necessary: Vrykul On Dismember\''),
(23751, 0, 0, 0, 8, 0, 100, 512, 42356, 0, 0, 0, '', 33, 23751, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'North Tent - On Spellhit \'Burn Direhorn Post\' - Quest Credit \'Raze Direhorn Post!\''),
(23752, 0, 0, 0, 8, 0, 100, 512, 42356, 0, 0, 0, '', 33, 23752, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Northeast Tent - On Spellhit \'Burn Direhorn Post\' - Quest Credit \'Raze Direhorn Post!\''),
(23753, 0, 0, 0, 8, 0, 100, 512, 42356, 0, 0, 0, '', 33, 23753, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'East Tent - On Spellhit \'Burn Direhorn Post\' - Quest Credit \'Raze Direhorn Post!\''),
(23859, 0, 0, 0, 4, 0, 100, 512, 0, 0, 0, 0, '', 80, 2385900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Greer Orehammer - On Aggro - Run Script'),
(23859, 0, 1, 2, 62, 0, 100, 512, 9546, 2, 0, 0, '', 56, 33634, 10, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Greer Orehammer - On Gossip Option 1 Selected - Add Item \'Orehammer\'s Precision Bombs\' 10 Times'),
(23859, 0, 2, 3, 61, 0, 100, 512, 0, 0, 0, 0, '', 52, 745, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Greer Orehammer - On Gossip Option 1 Selected - Cast \'High Commander Halford Wyrmbane: Westguard Keep to Wintergarde Keep Taxi\''),
(23859, 0, 3, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Greer Orehammer - On Gossip Option 1 Selected - Close Gossip'),
(23859, 0, 4, 5, 62, 0, 100, 0, 9546, 1, 0, 0, '', 11, 48862, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Greer Orehammer - On gossip select - Invoker spellcast'),
(23859, 0, 5, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Greer Orehammer - On gossip select - Close gossip'),
(24841, 0, 0, 0, 0, 0, 100, 0, 0, 0, 2300, 3900, '', 11, 23337, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Marine Halters - In Combat - Cast \'Shoot\''),
(24841, 0, 1, 0, 9, 0, 100, 0, 0, 20, 9000, 11000, '', 11, 12024, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Marine Halters - Within 0-20 Range - Cast \'Net\''),
(25145, 0, 1, 0, 9, 0, 100, 0, 0, 20, 8000, 13000, '', 11, 12024, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Budd\'s Bodyguard - Within 0-20 Range - Cast \'Net\''),
(25145, 0, 0, 0, 0, 0, 100, 0, 0, 0, 2300, 3900, '', 11, 23337, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Budd\'s Bodyguard - In Combat CMC - Cast \'Shoot\''),
(26200, 0, 1, 2, 61, 0, 100, 512, 0, 0, 0, 0, '', 11, 46773, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Snowfall Glade Pup - Between 0-30% Health - Cast \'Planning for the Future: Create Snowfall Glade Pup\''),
(26200, 0, 0, 1, 8, 0, 100, 512, 39996, 0, 0, 0, '', 11, 65208, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Snowfall Glade Pup - On Spellhit \'40yd Dummy\' - Cast \'Self Stun\''),
(26200, 0, 2, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Snowfall Glade Pup - On Spellhit \'40yd Dummy\' - Despawn Instant'),
(26543, 0, 0, 0, 19, 0, 100, 0, 12042, 0, 0, 0, '', 11, 47308, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Image of Drakuru - On Quest \'Heart of the Ancients\' Taken - Cast \'Strip Detect Drakuru 02\''),
(26701, 0, 0, 0, 19, 0, 100, 0, 12068, 0, 0, 0, '', 11, 47403, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Image of Drakuru - On Quest \'Voices From the Dust\' Taken - Cast \'Strip Detect Drakuru 03\''),
(26787, 0, 0, 0, 19, 0, 100, 0, 12238, 0, 0, 0, '', 11, 48417, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Image of Drakuru - On Quest \'Cleansing Drak\'Tharon\' Taken - Cast \'Strip Detect Drakuru 04\''),
(28132, 0, 4, 0, 0, 0, 100, 4, 9000, 14000, 22000, 26000, '', 11, 50762, 1, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Don Carlos - In Combat - Cast \'Net\' (Heroic Dungeon)'),
(28132, 0, 3, 0, 0, 0, 100, 2, 9000, 14000, 22000, 26000, '', 11, 12024, 1, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Don Carlos - In Combat - Cast \'Net\' (Normal Dungeon)'),
(28132, 0, 2, 0, 0, 0, 100, 4, 0, 0, 2300, 5000, '', 11, 16496, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Don Carlos - Combat CMC - Cast \'Shoot\' (Heroic Dungeon)'),
(28132, 0, 1, 0, 0, 0, 100, 2, 0, 0, 2300, 5000, '', 11, 16100, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Don Carlos - Combat CMC - Cast \'Shoot\' (Normal Dungeon)'),
(28132, 0, 0, 0, 1, 0, 100, 7, 1000, 1000, 0, 0, '', 11, 50736, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Don Carlos - Out of Combat - Cast \'Summon Guerrero\' (No Repeat) (Dungeon)'),
(28156, 0, 0, 1, 8, 0, 100, 1, 51276, 0, 0, 0, '', 11, 59216, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Defeated Argent Footman - On Spellhit \'Incinerate Corpse\' - Cast \'Burning Corpse\''),
(28156, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, '', 11, 51279, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Defeated Argent Footman - On Spellhit - Cast \'Defeated Argent Footman KC\''),
(28156, 0, 2, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 41, 10000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Defeated Argent Footman - On Spellhit - Despawn'),
(28580, 0, 6, 0, 9, 0, 100, 6, 0, 5, 6000, 9000, '', 11, 61507, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hardened Steel Skycaller - 0-5 Range - Cast \'Disengage\' (Dungeon)'),
(28580, 0, 5, 0, 0, 0, 100, 4, 7000, 12000, 12000, 18000, '', 11, 59147, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Hardened Steel Skycaller - Combat - Cast \'Impact Multi-Shot\' (Heroic Dungeon)'),
(28580, 0, 4, 0, 0, 0, 100, 4, 9000, 12000, 15000, 20000, '', 11, 59148, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Hardened Steel Skycaller - Combat - Cast \'Impact Shot\' (Heroic Dungeon)'),
(28580, 0, 3, 0, 0, 0, 100, 2, 7000, 12000, 12000, 18000, '', 11, 52755, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Hardened Steel Skycaller - Combat - Cast \'Impact Multi-Shot\' (Normal Dungeon)'),
(28580, 0, 2, 0, 0, 0, 100, 2, 9000, 12000, 15000, 20000, '', 11, 52754, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Hardened Steel Skycaller - Combat - Cast \'Impact Shot\' (Normal Dungeon)'),
(28580, 0, 1, 0, 0, 0, 100, 4, 0, 0, 2300, 5000, '', 11, 61515, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Hardened Steel Skycaller - Combat CMC - Cast \'Shoot\' (Heroic Dungeon)'),
(28580, 0, 0, 0, 0, 0, 100, 2, 0, 0, 2300, 5000, '', 11, 16100, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Hardened Steel Skycaller - Combat CMC - Cast \'Shoot\' (Normal Dungeon)'),
(28882, 0, 0, 0, 11, 0, 100, 1, 0, 0, 0, 0, '', 11, 54647, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Enchanted Tiki Warrior - On Respawn - Cast \'Spirit Burn\''),
(28882, 0, 1, 0, 0, 0, 100, 0, 9000, 21000, 12000, 24000, '', 11, 54657, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Enchanted Tiki Warrior - In Combat - Cast \'Incorporeal\''),
(29820, 0, 6, 0, 2, 0, 100, 6, 0, 30, 12000, 15000, '', 11, 31567, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Drakkari God Hunter - 0-30% Health - Cast \'Deterrence\' (Dungeon)'),
(29820, 0, 5, 0, 0, 0, 100, 6, 18000, 21000, 19000, 23000, '', 11, 55625, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Drakkari God Hunter - Combat - Cast \'Tranquillizing Shot\' (Dungeon)'),
(29820, 0, 4, 0, 0, 0, 100, 6, 3000, 5000, 33000, 37000, '', 11, 55798, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Drakkari God Hunter - Combat - Cast \'Flare\' (Dungeon)'),
(29820, 0, 3, 0, 0, 0, 100, 4, 7000, 10000, 12000, 15000, '', 11, 58973, 1, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Drakkari God Hunter - Combat - Cast \'Arcane Shot\' (Heroic Dungeon)'),
(29820, 0, 2, 0, 0, 0, 100, 2, 7000, 10000, 12000, 15000, '', 11, 55624, 1, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Drakkari God Hunter - Combat - Cast \'Arcane Shot\' (Normal Dungeon)'),
(29820, 0, 1, 0, 0, 0, 100, 4, 0, 0, 2300, 5000, '', 11, 59146, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Drakkari God Hunter - Combat CMC - Cast \'Shoot\' (Heroic Dungeon)'),
(29820, 0, 0, 0, 0, 0, 100, 2, 0, 0, 2300, 5000, '', 11, 35946, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Drakkari God Hunter - Combat CMC - Cast \'Shoot\' (Normal Dungeon)'),
(29836, 0, 3, 0, 0, 0, 100, 4, 12000, 15000, 16000, 22000, '', 11, 58967, 33, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 'Drakkari Battle Rider - Combat - Cast \'Poisoned Spear\' (Heroic Dungeon)'),
(29836, 0, 2, 0, 0, 0, 100, 2, 12000, 15000, 16000, 22000, '', 11, 55521, 33, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 'Drakkari Battle Rider - Combat - Cast \'Poisoned Spear\' (Normal Dungeon)'),
(29836, 0, 1, 0, 0, 0, 100, 4, 0, 0, 5000, 7000, '', 11, 58966, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Drakkari Battle Rider - Combat CMC - Cast \'Throw\' (Heroic Dungeon)'),
(29836, 0, 0, 0, 0, 0, 100, 2, 0, 0, 5000, 7000, '', 11, 55348, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Drakkari Battle Rider - Combat CMC - Cast \'Throw\' (Normal Dungeon)'),
(33071, 0, 0, 0, 0, 0, 100, 0, 0, 0, 2300, 3900, '', 11, 64041, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Shatterspear Raider - In Combat - Cast \'Throw Spear\''),
(33071, 0, 1, 0, 2, 0, 100, 1, 0, 15, 0, 0, '', 25, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shatterspear Raider - Between 0-15% Health - Flee For Assist (No Repeat)'),
(33071, 0, 2, 0, 9, 0, 100, 512, 5, 30, 12000, 17000, '', 11, 79444, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Shatterspear Raider - Within 5-30 Range - Cast \'Impale\''),
(33419, 0, 0, 0, 4, 0, 100, 513, 0, 0, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tendril from Below - On Aggro - Disable Combat Movement (No Repeat)'),
(33419, 0, 2, 0, 0, 0, 100, 512, 7000, 8000, 28000, 35000, '', 11, 78751, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Tendril from Below - In Combat - Cast \'Mind Flay\''),
(33419, 0, 1, 0, 0, 0, 100, 512, 2000, 3000, 12000, 19000, '', 11, 62975, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Tendril from Below - In Combat - Cast \'Shadow Bolt\''),
(34177, 0, 0, 0, 0, 0, 100, 0, 0, 0, 2300, 3900, '', 11, 6660, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Ashenvale Scout - In Combat - Cast \'Shoot\''),
(34177, 0, 1, 0, 2, 0, 100, 1, 0, 15, 0, 0, '', 25, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ashenvale Scout - Between 0-15% Health - Flee For Assist (No Repeat)'),
(34177, 0, 2, 0, 9, 0, 100, 512, 5, 30, 12000, 15000, '', 11, 78754, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Ashenvale Scout - Within 5-30 Range - Cast \'Arcane Shot\''),
(34177, 0, 3, 0, 9, 0, 100, 512, 0, 5, 35000, 40000, '', 11, 78578, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ashenvale Scout - Within 0-5 Range - Cast \'Immolation Trap\''),
(34177, 0, 4, 0, 0, 0, 100, 1, 12000, 14000, 0, 0, '', 11, 78894, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Ashenvale Scout - In Combat - Cast \'Leaping Cleave\' (No Repeat)'),
(34204, 0, 0, 0, 0, 0, 100, 0, 0, 0, 2300, 3900, '', 11, 6660, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Protector Arminon - In Combat - Cast \'Shoot\''),
(34204, 0, 1, 0, 2, 0, 100, 1, 0, 15, 0, 0, '', 25, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Protector Arminon - Between 0-15% Health - Flee For Assist (No Repeat)'),
(34204, 0, 2, 0, 9, 0, 100, 512, 5, 30, 12000, 15000, '', 11, 22822, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Protector Arminon - Within 5-30 Range - Cast \'Starshards\''),
(34204, 0, 3, 0, 9, 0, 100, 512, 0, 5, 25000, 28000, '', 11, 78828, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Protector Arminon - Within 0-5 Range - Cast \'Bladestorm\''),
(34204, 0, 4, 0, 0, 0, 100, 1, 12000, 14000, 0, 0, '', 11, 78894, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Protector Arminon - In Combat - Cast \'Leaping Cleave\' (No Repeat)'),
(34204, 0, 5, 0, 0, 0, 100, 512, 8000, 9000, 300000, 300000, '', 11, 78823, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Protector Arminon - In Combat - Cast \'Commanding Shout\''),
(34208, 0, 0, 0, 0, 0, 100, 0, 0, 0, 2300, 3900, '', 11, 6660, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Protector Endolar - In Combat - Cast \'Shoot\''),
(34208, 0, 1, 0, 2, 0, 100, 1, 0, 15, 0, 0, '', 25, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Protector Endolar - Between 0-15% Health - Flee For Assist (No Repeat)'),
(34208, 0, 2, 0, 9, 0, 100, 512, 5, 30, 12000, 15000, '', 11, 22822, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Protector Endolar - Within 5-30 Range - Cast \'Starshards\''),
(34208, 0, 3, 0, 9, 0, 100, 512, 0, 5, 25000, 28000, '', 11, 78828, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Protector Endolar - Within 0-5 Range - Cast \'Bladestorm\''),
(34208, 0, 4, 0, 0, 0, 100, 1, 12000, 14000, 0, 0, '', 11, 78894, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Protector Endolar - In Combat - Cast \'Leaping Cleave\' (No Repeat)'),
(34208, 0, 5, 0, 0, 0, 100, 512, 8000, 9000, 300000, 300000, '', 11, 78823, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Protector Endolar - In Combat - Cast \'Commanding Shout\''),
(34309, 0, 0, 0, 0, 0, 100, 0, 0, 0, 2300, 3900, '', 11, 64041, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Shatterspear Raider - In Combat - Cast \'Throw Spear\''),
(34309, 0, 1, 0, 2, 0, 100, 1, 0, 15, 0, 0, '', 25, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shatterspear Raider - Between 0-15% Health - Flee For Assist (No Repeat)'),
(34309, 0, 2, 0, 9, 0, 100, 512, 5, 30, 12000, 17000, '', 11, 79444, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Shatterspear Raider - Within 5-30 Range - Cast \'Impale\''),
(34419, 0, 0, 0, 0, 0, 100, 0, 0, 0, 2300, 3900, '', 11, 6660, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Astranaar Skirmisher - In Combat - Cast \'Shoot\''),
(34419, 0, 1, 0, 2, 0, 100, 1, 0, 15, 0, 0, '', 25, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Astranaar Skirmisher - Between 0-15% Health - Flee For Assist (No Repeat)'),
(34419, 0, 2, 0, 9, 0, 100, 512, 5, 30, 12000, 15000, '', 11, 78754, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Astranaar Skirmisher - Within 5-30 Range - Cast \'Arcane Shot\''),
(34419, 0, 3, 0, 9, 0, 100, 512, 0, 5, 35000, 40000, '', 11, 78578, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Astranaar Skirmisher - Within 0-5 Range - Cast \'Immolation Trap\''),
(34419, 0, 4, 0, 2, 0, 100, 0, 0, 50, 14000, 15000, '', 11, 78826, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Astranaar Skirmisher - Between 0-50% Health - Cast \'Evasion\''),
(35161, 0, 0, 0, 4, 0, 100, 1, 0, 0, 0, 0, '', 11, 22120, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Krom\'gar Warrior - On Aggro - Cast \'Charge\' (No Repeat)'),
(35161, 0, 1, 0, 0, 0, 100, 0, 4000, 6000, 15000, 22000, '', 11, 81500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Krom\'gar Warrior - In Combat - Cast \'War Stomp\''),
(35312, 0, 0, 0, 0, 0, 100, 0, 0, 0, 2300, 3900, '', 11, 6660, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Talrendis Saboteur - In Combat - Cast \'Shoot\''),
(35312, 0, 1, 0, 2, 0, 100, 1, 0, 15, 0, 0, '', 25, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Talrendis Saboteur - Between 0-15% Health - Flee For Assist (No Repeat)'),
(35312, 0, 2, 0, 9, 0, 100, 0, 0, 5, 12000, 15000, '', 11, 11971, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Talrendis Saboteur - Within 0-5 Range - Cast \'Sunder Armor\''),
(35312, 0, 3, 0, 9, 0, 100, 0, 5, 30, 17000, 24000, '', 11, 67301, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Talrendis Saboteur - Within 5-30 Range - Cast \'Fire Shot\''),
(35880, 0, 0, 0, 0, 0, 100, 0, 0, 0, 2300, 3900, '', 11, 6660, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Lady Silisthra - In Combat - Cast \'Shoot\''),
(35880, 0, 1, 0, 2, 0, 100, 1, 0, 15, 0, 0, '', 25, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Silisthra - Between 0-15% Health - Flee For Assist (No Repeat)'),
(35880, 0, 2, 0, 9, 0, 100, 0, 5, 30, 12000, 18000, '', 11, 15495, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Lady Silisthra - Within 5-30 Range - Cast \'Explosive Shot\''),
(35880, 0, 3, 0, 0, 0, 100, 0, 4000, 7000, 15000, 22000, '', 11, 20299, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Lady Silisthra - In Combat - Cast \'Forked Lightning\''),
(35880, 0, 4, 0, 9, 0, 100, 0, 5, 30, 9000, 26000, '', 11, 12551, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Lady Silisthra - Within 5-30 Range - Cast \'Frost Shot\''),
(35880, 0, 5, 0, 1, 0, 100, 0, 500, 1000, 600000, 600000, '', 11, 15507, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Silisthra - Out of Combat - Cast \'Lightning Shield\''),
(35880, 0, 6, 0, 16, 0, 100, 0, 15507, 1, 15000, 30000, '', 11, 15507, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Silisthra - On Friendly Unit Missing Buff \'Lightning Shield\' - Cast \'Lightning Shield\''),
(36624, 0, 7, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 81, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Caladis Brightspear - On Data Set 0 3 - Set Npc Flag Questgiver (No Repeat) (Dungeon)'),
(36624, 0, 6, 7, 61, 0, 100, 512, 0, 0, 0, 0, '', 66, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Caladis Brightspear - On Data Set 0 3 - Set Orientation Home Position (No Repeat) (Dungeon)'),
(36624, 0, 5, 6, 40, 0, 100, 0, 2, 0, 0, 0, '', 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Caladis Brightspear - On Waypoint 2 Reached - Say Line 3'),
(36624, 0, 4, 0, 38, 0, 100, 512, 50, 0, 0, 0, '', 43, 0, 28888, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Caladis Brightspear - On Data Set 50 0 - Mount To Model 28888'),
(36624, 0, 3, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 80, 3662400, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Caladis Brightspear - On Waypoint 2 Reached - Run Script'),
(36624, 0, 2, 3, 40, 0, 100, 512, 1, 0, 0, 0, '', 54, 10000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Caladis Brightspear - On Waypoint 1 Reached - Pause Waypoint'),
(36624, 0, 1, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 53, 0, 36624, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Caladis Brightspear - On Waypoint 1 Reached - Start Waypoint'),
(36624, 0, 0, 1, 20, 0, 100, 512, 24454, 0, 0, 0, '', 83, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Caladis Brightspear - On Quest \'Return To Caladis Brightspear\' Finished - Remove Npc Flag Questgiver'),
(36636, 0, 0, 0, 0, 0, 100, 0, 0, 0, 2300, 3900, '', 11, 15547, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Twilight Dragon Hunter - In Combat - Cast \'Shoot\''),
(36636, 0, 1, 0, 9, 0, 100, 0, 0, 5, 42000, 45000, '', 11, 78578, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Twilight Dragon Hunter - Within 0-5 Range - Cast \'Immolation Trap\''),
(36642, 0, 7, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 81, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Myralion Sunblaze - On Quest \'Return To Caladis Brightspear\' Finished - Set Npc Flag Questgiver'),
(36642, 0, 6, 7, 61, 0, 100, 512, 0, 0, 0, 0, '', 66, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Myralion Sunblaze - On Quest \'Return To Caladis Brightspear\' Finished - Set Orientation Home Position'),
(36642, 0, 5, 6, 40, 0, 100, 0, 2, 0, 0, 0, '', 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Myralion Sunblaze - On Waypoint 2 Reached - Say Line 3'),
(36642, 0, 4, 0, 38, 0, 100, 512, 50, 0, 0, 0, '', 43, 0, 28889, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Myralion Sunblaze - On Data Set 50 0 - Mount To Model 28889'),
(36642, 0, 3, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 80, 3664200, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Myralion Sunblaze - On Waypoint 2 Reached - Run Script'),
(36642, 0, 2, 3, 40, 0, 100, 512, 1, 0, 0, 0, '', 54, 10000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Myralion Sunblaze - On Waypoint 1 Reached - Pause Waypoint'),
(36642, 0, 1, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 53, 0, 36642, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Myralion Sunblaze - On Waypoint 1 Reached - Start Waypoint'),
(36642, 0, 0, 1, 20, 0, 100, 512, 24558, 0, 0, 0, '', 83, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Myralion Sunblaze - On Quest \'Return To Myralion Sunblaze\' Finished - Remove Npc Flag Questgiver'),
(36660, 0, 0, 0, 0, 0, 100, 0, 0, 0, 2300, 3900, '', 11, 6660, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Talrendis Marksman - In Combat - Cast \'Shoot\''),
(36660, 0, 1, 0, 2, 0, 100, 1, 0, 15, 0, 0, '', 25, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Talrendis Marksman - Between 0-15% Health - Flee For Assist (No Repeat)'),
(36660, 0, 2, 0, 9, 0, 100, 0, 0, 5, 8000, 12000, '', 11, 81001, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Talrendis Marksman - Within 0-5 Range - Cast \'Side Kick\''),
(36708, 0, 0, 0, 0, 0, 100, 0, 0, 0, 2300, 3900, '', 11, 81655, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Bristleback Gun Thief - In Combat - Cast \'Shoot\''),
(36708, 0, 1, 0, 9, 0, 100, 0, 5, 30, 12000, 18000, '', 11, 81654, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Bristleback Gun Thief - Within 5-30 Range - Cast \'Clumsy Shot\''),
(36708, 0, 2, 0, 11, 0, 100, 1, 0, 0, 0, 0, '', 11, 81653, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bristleback Gun Thief - On Respawn - Cast \'Bristleback\' (No Repeat)'),
(36815, 0, 0, 0, 0, 0, 100, 0, 0, 0, 2300, 3900, '', 11, 95826, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Valormok Grunt - In Combat - Cast \'Shoot\''),
(36815, 0, 1, 0, 9, 0, 100, 0, 0, 5, 9000, 11000, '', 11, 40505, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Valormok Grunt - Within 0-5 Range - Cast \'Cleave\''),
(36815, 0, 2, 3, 2, 0, 100, 1, 0, 30, 0, 0, '', 11, 8599, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Valormok Grunt - Between 0-30% Health - Cast \'Enrage\' (No Repeat)'),
(36815, 0, 3, 0, 61, 0, 100, 1, 0, 30, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Valormok Grunt - Between 0-30% Health - Say Line 0 (No Repeat)'),
(36890, 0, 0, 0, 4, 0, 100, 513, 0, 0, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Talrendis Glaive Thrower - On Aggro - Disable Combat Movement (No Repeat)'),
(36890, 0, 1, 0, 0, 0, 100, 0, 2000, 3000, 5000, 5000, '', 11, 69517, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Talrendis Glaive Thrower - In Combat - Cast \'Throw Glaive\''),
(36942, 0, 0, 0, 0, 0, 100, 512, 0, 0, 2300, 3900, '', 11, 70092, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Fledgling Brave - In Combat - Cast \'Shoot Gun\''),
(36942, 0, 1, 0, 9, 0, 100, 512, 0, 5, 7000, 9000, '', 11, 81502, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Fledgling Brave - Within 0-5 Range - Cast \'Cleave\''),
(36942, 0, 2, 0, 9, 0, 100, 512, 0, 5, 17000, 22000, '', 11, 81500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fledgling Brave - Within 0-5 Range - Cast \'War Stomp\''),
(37212, 0, 0, 0, 4, 0, 100, 513, 0, 0, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bramblescar Growth - On Aggro - Disable Combat Movement (No Repeat)'),
(37548, 0, 0, 0, 4, 0, 100, 513, 0, 0, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grasping Overgrowth - On Aggro - Disable Combat Movement (No Repeat)'),
(38017, 0, 0, 1, 38, 0, 100, 512, 0, 1, 0, 0, '', 80, 3801700, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Kalecgos - On Data Set 0 1 - Run Script'),
(38017, 0, 1, 0, 61, 0, 100, 512, 0, 2, 0, 0, '', 80, 3801701, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Kalecgos - On Data Set 0 1 - Run Script'),
(38017, 0, 2, 3, 40, 0, 100, 512, 1, 38017, 0, 0, '', 54, 30000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Kalecgos - On Waypoint 1 Reached - Pause Waypoint'),
(38017, 0, 3, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 66, 0, 0, 0, 0, 0, 0, 9, 27990, 0, 15, 0, 0, 0, 0, 'Kalecgos - On Waypoint 1 Reached - Set Orientation Closest Creature \'Krasus\''),
(38017, 0, 4, 5, 40, 0, 100, 512, 2, 38017, 0, 0, '', 55, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Kalecgos - On Waypoint 2 Reached - Stop Waypoint'),
(38017, 0, 5, 0, 61, 0, 100, 512, 0, 0, 0, 0, '', 66, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Kalecgos - On Waypoint 2 Reached - Set Orientation Home Position'),
(38070, 0, 0, 0, 0, 0, 100, 0, 0, 0, 2300, 3900, '', 11, 95826, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Desolation Guard - In Combat - Cast \'Shoot\''),
(38070, 0, 1, 0, 9, 0, 100, 0, 0, 5, 9000, 12000, '', 11, 40505, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Desolation Guard - Within 0-5 Range - Cast \'Cleave\''),
(38912, 0, 0, 0, 4, 0, 100, 513, 0, 0, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ferocious Jungle Vine - On Aggro - Disable Combat Movement (No Repeat)'),
(38942, 0, 0, 0, 4, 0, 100, 513, 0, 0, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Merciless Jungle Vine - On Aggro - Disable Combat Movement (No Repeat)'),
(39261, 0, 0, 0, 0, 0, 100, 0, 0, 0, 2300, 3900, '', 11, 6660, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Northwatch Ranger - In Combat - Cast \'Shoot\''),
(39261, 0, 1, 0, 9, 0, 100, 0, 5, 30, 15000, 18000, '', 11, 78754, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Northwatch Ranger - Within 5-30 Range - Cast \'Arcane Shot\''),
(39261, 0, 2, 0, 9, 0, 100, 0, 0, 10, 60000, 65000, '', 11, 78578, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Northwatch Ranger - Within 0-10 Range - Cast \'Immolation Trap\''),
(39268, 0, 0, 0, 0, 0, 100, 0, 0, 0, 2300, 3900, '', 11, 6660, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Northwatch Sharpshooter - In Combat - Cast \'Shoot\''),
(39268, 0, 1, 0, 9, 0, 100, 0, 5, 30, 18000, 21000, '', 11, 79721, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Northwatch Sharpshooter - Within 5-30 Range - Cast \'Explosive Shot\''),
(39268, 0, 2, 0, 9, 0, 100, 0, 5, 30, 35000, 45000, '', 11, 79719, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Northwatch Sharpshooter - Within 5-30 Range - Cast \'Pinpoint\''),
(39317, 0, 0, 0, 0, 0, 100, 0, 0, 0, 2300, 3900, '', 11, 6660, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Northwatch Scout - In Combat - Cast \'Shoot\''),
(39317, 0, 1, 0, 11, 0, 100, 1, 0, 0, 0, 0, '', 11, 58506, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Northwatch Scout - On Respawn - Cast \'Stealth\' (No Repeat)'),
(39317, 0, 2, 0, 7, 0, 100, 1, 0, 0, 0, 0, '', 11, 58506, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Northwatch Scout - On Evade - Cast \'Stealth\' (No Repeat)'),
(39317, 0, 3, 0, 9, 0, 100, 0, 0, 10, 15000, 22000, '', 11, 79584, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Northwatch Scout - Within 0-10 Range - Cast \'Fan of Knives\''),
(39946, 0, 0, 1, 4, 0, 100, 513, 0, 0, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Caryssia Moonhunter - On Aggro - Disable Combat Movement (No Repeat)'),
(39946, 0, 1, 2, 61, 0, 100, 513, 0, 0, 0, 0, '', 11, 95826, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Caryssia Moonhunter - On Aggro - Cast \'Shoot\' (No Repeat)'),
(39946, 0, 2, 3, 61, 0, 100, 513, 0, 0, 0, 0, '', 20, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Caryssia Moonhunter - On Aggro - Stop Attacking (No Repeat)'),
(39946, 0, 3, 0, 61, 0, 100, 513, 0, 0, 0, 0, '', 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Caryssia Moonhunter - On Aggro - Set Event Phase 1 (No Repeat)'),
(39946, 0, 4, 5, 9, 1, 100, 0, 5, 30, 2300, 3900, '', 11, 95826, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Caryssia Moonhunter - Within 5-30 Range - Cast \'Shoot\' (Phase 1)'),
(39946, 0, 5, 0, 61, 1, 100, 0, 5, 30, 2300, 3900, '', 40, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Caryssia Moonhunter - Within 5-30 Range - Set Sheath Ranged (Phase 1)'),
(39946, 0, 6, 7, 9, 1, 100, 512, 30, 80, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Caryssia Moonhunter - Within 30-80 Range - Enable Combat Movement (Phase 1)'),
(39946, 0, 7, 0, 61, 1, 100, 512, 30, 80, 0, 0, '', 20, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Caryssia Moonhunter - Within 30-80 Range - Start Attacking (Phase 1)'),
(39946, 0, 8, 9, 9, 1, 100, 512, 0, 10, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Caryssia Moonhunter - Within 0-10 Range - Enable Combat Movement (Phase 1)'),
(39946, 0, 9, 10, 61, 1, 100, 512, 0, 10, 0, 0, '', 40, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Caryssia Moonhunter - Within 0-10 Range - Set Sheath Melee (Phase 1)'),
(39946, 0, 10, 0, 61, 1, 100, 512, 0, 10, 0, 0, '', 20, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Caryssia Moonhunter - Within 0-10 Range - Start Attacking (Phase 1)'),
(39946, 0, 11, 12, 9, 1, 100, 512, 11, 25, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Caryssia Moonhunter - Within 11-25 Range - Disable Combat Movement (Phase 1)'),
(39946, 0, 12, 13, 61, 1, 100, 512, 11, 25, 0, 0, '', 20, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Caryssia Moonhunter - Within 11-25 Range - Stop Attacking (Phase 1)'),
(39946, 0, 13, 0, 61, 1, 100, 512, 11, 25, 0, 0, '', 40, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Caryssia Moonhunter - Within 11-25 Range - Set Sheath Ranged (Phase 1)'),
(39946, 0, 14, 15, 7, 1, 100, 1, 0, 0, 0, 0, '', 40, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Caryssia Moonhunter - On Evade - Set Sheath Melee (Phase 1) (No Repeat)'),
(39946, 0, 15, 0, 61, 1, 100, 513, 0, 0, 0, 0, '', 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Caryssia Moonhunter - On Evade - Set Event Phase 0 (Phase 1) (No Repeat)'),
(39946, 0, 16, 5, 9, 1, 100, 0, 0, 5, 9000, 11000, '', 11, 40505, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Caryssia Moonhunter - Within 0-5 Range - Cast \'Cleave\' (Phase 1)'),
(39946, 0, 17, 0, 0, 1, 100, 0, 5000, 8000, 35000, 36000, '', 11, 13730, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Caryssia Moonhunter - In Combat - Cast \'Demoralizing Shout\' (Phase 1)'),
(39946, 0, 18, 0, 0, 1, 100, 0, 6000, 9000, 120000, 125000, '', 11, 32064, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Caryssia Moonhunter - In Combat - Cast \'Battle Shout\' (Phase 1)'),
(39946, 0, 19, 0, 11, 0, 100, 1, 0, 0, 0, 0, '', 11, 7165, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Caryssia Moonhunter - On Respawn - Cast \'Battle Stance\' (No Repeat)'),
(39972, 0, 0, 1, 4, 0, 100, 513, 0, 0, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Feralas Sentinel - On Aggro - Disable Combat Movement (No Repeat)'),
(39972, 0, 1, 2, 61, 0, 100, 513, 0, 0, 0, 0, '', 11, 74613, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Feralas Sentinel - On Aggro - Cast \'Shoot\' (No Repeat)'),
(39972, 0, 2, 3, 61, 0, 100, 513, 0, 0, 0, 0, '', 20, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Feralas Sentinel - On Aggro - Stop Attacking (No Repeat)'),
(39972, 0, 3, 0, 61, 0, 100, 513, 0, 0, 0, 0, '', 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Feralas Sentinel - On Aggro - Set Event Phase 1 (No Repeat)'),
(39972, 0, 4, 5, 9, 1, 100, 0, 5, 30, 2300, 3900, '', 11, 74613, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Feralas Sentinel - Within 5-30 Range - Cast \'Shoot\' (Phase 1)'),
(39972, 0, 5, 0, 61, 1, 100, 0, 5, 30, 2300, 3900, '', 40, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Feralas Sentinel - Within 5-30 Range - Set Sheath Ranged (Phase 1)'),
(39972, 0, 6, 7, 9, 1, 100, 512, 30, 80, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Feralas Sentinel - Within 30-80 Range - Enable Combat Movement (Phase 1)'),
(39972, 0, 7, 0, 61, 1, 100, 512, 30, 80, 0, 0, '', 20, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Feralas Sentinel - Within 30-80 Range - Start Attacking (Phase 1)'),
(39972, 0, 8, 9, 9, 1, 100, 512, 0, 10, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Feralas Sentinel - Within 0-10 Range - Enable Combat Movement (Phase 1)'),
(39972, 0, 9, 10, 61, 1, 100, 512, 0, 10, 0, 0, '', 40, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Feralas Sentinel - Within 0-10 Range - Set Sheath Melee (Phase 1)'),
(39972, 0, 10, 0, 61, 1, 100, 512, 0, 10, 0, 0, '', 20, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Feralas Sentinel - Within 0-10 Range - Start Attacking (Phase 1)'),
(39972, 0, 11, 12, 9, 1, 100, 512, 11, 25, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Feralas Sentinel - Within 11-25 Range - Disable Combat Movement (Phase 1)'),
(39972, 0, 12, 13, 61, 1, 100, 512, 11, 25, 0, 0, '', 20, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Feralas Sentinel - Within 11-25 Range - Stop Attacking (Phase 1)'),
(39972, 0, 13, 0, 61, 1, 100, 512, 11, 25, 0, 0, '', 40, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Feralas Sentinel - Within 11-25 Range - Set Sheath Ranged (Phase 1)'),
(39972, 0, 14, 15, 7, 1, 100, 1, 0, 0, 0, 0, '', 40, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Feralas Sentinel - On Evade - Set Sheath Melee (Phase 1) (No Repeat)'),
(39972, 0, 15, 0, 61, 1, 100, 513, 0, 0, 0, 0, '', 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Feralas Sentinel - On Evade - Set Event Phase 0 (Phase 1) (No Repeat)'),
(39972, 0, 16, 5, 9, 1, 100, 0, 0, 5, 9000, 11000, '', 11, 15496, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Feralas Sentinel - Within 0-5 Range - Cast \'Cleave\' (Phase 1)'),
(40069, 0, 0, 1, 4, 0, 100, 513, 0, 0, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Horde Poacher - On Aggro - Disable Combat Movement (No Repeat)'),
(40069, 0, 1, 2, 61, 0, 100, 513, 0, 0, 0, 0, '', 11, 6660, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Horde Poacher - On Aggro - Cast \'Shoot\' (No Repeat)'),
(40069, 0, 2, 3, 61, 0, 100, 513, 0, 0, 0, 0, '', 20, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Horde Poacher - On Aggro - Stop Attacking (No Repeat)'),
(40069, 0, 3, 0, 61, 0, 100, 513, 0, 0, 0, 0, '', 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Horde Poacher - On Aggro - Set Event Phase 1 (No Repeat)'),
(40069, 0, 4, 5, 9, 1, 100, 0, 5, 30, 2300, 3900, '', 11, 6660, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Horde Poacher - Within 5-30 Range - Cast \'Shoot\' (Phase 1)'),
(40069, 0, 5, 0, 61, 1, 100, 0, 5, 30, 2300, 3900, '', 40, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Horde Poacher - Within 5-30 Range - Set Sheath Ranged (Phase 1)'),
(40069, 0, 6, 7, 9, 1, 100, 512, 30, 80, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Horde Poacher - Within 30-80 Range - Enable Combat Movement (Phase 1)'),
(40069, 0, 7, 0, 61, 1, 100, 512, 30, 80, 0, 0, '', 20, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Horde Poacher - Within 30-80 Range - Start Attacking (Phase 1)'),
(40069, 0, 8, 9, 9, 1, 100, 512, 0, 10, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Horde Poacher - Within 0-10 Range - Enable Combat Movement (Phase 1)'),
(40069, 0, 9, 10, 61, 1, 100, 512, 0, 10, 0, 0, '', 40, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Horde Poacher - Within 0-10 Range - Set Sheath Melee (Phase 1)'),
(40069, 0, 10, 0, 61, 1, 100, 512, 0, 10, 0, 0, '', 20, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Horde Poacher - Within 0-10 Range - Start Attacking (Phase 1)'),
(40069, 0, 11, 12, 9, 1, 100, 512, 11, 25, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Horde Poacher - Within 11-25 Range - Disable Combat Movement (Phase 1)'),
(40069, 0, 12, 13, 61, 1, 100, 512, 11, 25, 0, 0, '', 20, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Horde Poacher - Within 11-25 Range - Stop Attacking (Phase 1)'),
(40069, 0, 13, 0, 61, 1, 100, 512, 11, 25, 0, 0, '', 40, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Horde Poacher - Within 11-25 Range - Set Sheath Ranged (Phase 1)'),
(40069, 0, 14, 15, 7, 1, 100, 1, 0, 0, 0, 0, '', 40, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Horde Poacher - On Evade - Set Sheath Melee (Phase 1) (No Repeat)'),
(40069, 0, 15, 0, 61, 1, 100, 513, 0, 0, 0, 0, '', 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Horde Poacher - On Evade - Set Event Phase 0 (Phase 1) (No Repeat)'),
(40069, 0, 16, 0, 2, 1, 100, 513, 0, 15, 0, 0, '', 22, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Horde Poacher - Between 0-15% Health - Set Event Phase 2 (Phase 1) (No Repeat)'),
(40069, 0, 17, 0, 2, 2, 100, 1, 0, 15, 0, 0, '', 25, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Horde Poacher - Between 0-15% Health - Flee For Assist (Phase 2) (No Repeat)'),
(40069, 0, 18, 19, 7, 2, 100, 1, 0, 0, 0, 0, '', 40, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Horde Poacher - On Evade - Set Sheath Melee (Phase 2) (No Repeat)'),
(40069, 0, 19, 0, 61, 2, 100, 513, 0, 0, 0, 0, '', 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Horde Poacher - On Evade - Set Event Phase 0 (Phase 2) (No Repeat)'),
(40069, 0, 21, 5, 9, 1, 100, 0, 5, 30, 15000, 18000, '', 11, 78841, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Horde Poacher - Within 5-30 Range - Cast \'Aimed Shot\' (Phase 1)'),
(40069, 0, 22, 5, 9, 1, 100, 0, 0, 20, 8000, 9000, '', 11, 6533, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Horde Poacher - Within 0-20 Range - Cast \'Net\' (Phase 1)'),
(41641, 0, 0, 1, 4, 0, 100, 513, 0, 0, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stop Moving on Aggro'),
(41641, 0, 1, 0, 0, 0, 100, 512, 2000, 3000, 12000, 19000, '', 11, 78331, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cast Shadow Bolt'),
(43325, 0, 1, 0, 0, 0, 100, 0, 0, 0, 2300, 3900, '', 11, 80944, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Rockjaw Fungus-Flinger - In Combat - Cast \'Fling Fungus\''),
(43325, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, '', 28, 77831, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rockjaw Fungus-Flinger - Aggro - Remove Aura \'Trogg Sleep\''),
(43325, 0, 2, 0, 9, 0, 100, 0, 10, 20, 17000, 22000, '', 11, 87347, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Rockjaw Fungus-Flinger - Within 10-20 Range - Cast \'Poisonous Mushroom\''),
(45410, 0, 0, 1, 4, 0, 100, 513, 0, 0, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Elder Stormhoof - On Aggro - Disable Combat Movement (No Repeat)'),
(45410, 0, 1, 2, 61, 0, 100, 513, 0, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Elder Stormhoof - On Aggro - Say Line 0 (No Repeat)'),
(45410, 0, 2, 0, 61, 0, 100, 513, 0, 0, 0, 0, '', 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Elder Stormhoof - On Aggro - Set Event Phase 1 (No Repeat)'),
(45410, 0, 3, 0, 0, 1, 100, 0, 3000, 4500, 25000, 27000, '', 11, 85862, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Elder Stormhoof - In Combat - Cast \'Mortar Being Fired\' (Phase 1)'),
(45410, 0, 4, 5, 2, 1, 100, 513, 0, 75, 0, 0, '', 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Elder Stormhoof - Between 0-75% Health - Set Event Phase 2 (Phase 1) (No Repeat)'),
(45410, 0, 5, 6, 61, 1, 100, 513, 0, 75, 0, 0, '', 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Elder Stormhoof - Between 0-75% Health - Say Line 1 (Phase 1) (No Repeat)'),
(45410, 0, 6, 7, 61, 1, 100, 513, 0, 75, 0, 0, '', 11, 85695, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Elder Stormhoof - Between 0-75% Health - Cast \'Commune With Spirits\' (Phase 1) (No Repeat)'),
(45410, 0, 7, 0, 61, 1, 100, 513, 0, 75, 0, 0, '', 11, 85709, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Elder Stormhoof - Between 0-75% Health - Cast \'Blessed by Fire\' (Phase 1) (No Repeat)'),
(45410, 0, 8, 0, 0, 2, 100, 0, 6000, 8000, 33000, 36000, '', 11, 85714, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Elder Stormhoof - In Combat - Cast \'Lava Burst\' (Phase 2)'),
(45410, 0, 9, 0, 0, 2, 100, 0, 12000, 16000, 19000, 21000, '', 11, 85718, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Elder Stormhoof - In Combat - Cast \'Firebloom\' (Phase 2)'),
(45410, 0, 10, 11, 2, 2, 100, 513, 0, 50, 0, 0, '', 22, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Elder Stormhoof - Between 0-50% Health - Set Event Phase 4 (Phase 2) (No Repeat)'),
(45410, 0, 11, 12, 61, 2, 100, 513, 0, 50, 0, 0, '', 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Elder Stormhoof - Between 0-50% Health - Say Line 2 (Phase 2) (No Repeat)'),
(45410, 0, 12, 13, 61, 2, 100, 513, 0, 50, 0, 0, '', 11, 85707, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Elder Stormhoof - Between 0-50% Health - Cast \'Commune With Spirits\' (Phase 2) (No Repeat)'),
(45410, 0, 13, 0, 61, 2, 100, 513, 0, 50, 0, 0, '', 11, 85711, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Elder Stormhoof - Between 0-50% Health - Cast \'Blessed by Air\' (Phase 2) (No Repeat)'),
(45410, 0, 14, 0, 0, 4, 100, 0, 2000, 4500, 12000, 15000, '', 11, 85715, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Elder Stormhoof - In Combat - Cast \'Chain Lightning\' (Phase 4)'),
(45410, 0, 15, 0, 6, 4, 100, 1, 0, 0, 0, 0, '', 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Elder Stormhoof - On Just Died - Say Line 3 (Phase 4) (No Repeat)'),
(45438, 0, 0, 1, 4, 0, 100, 1, 0, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Arnak Grimtotem - On Aggro - Say Line 0 (No Repeat)'),
(45438, 0, 1, 2, 61, 0, 100, 1, 0, 0, 0, 0, '', 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Arnak Grimtotem - On Aggro - Say Line 1 (No Repeat)'),
(45438, 0, 2, 0, 61, 0, 100, 1, 0, 0, 0, 0, '', 11, 85812, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Arnak Grimtotem - On Aggro - Cast \'Chieftan\'s Call\' (No Repeat)'),
(45438, 0, 3, 4, 2, 0, 100, 1, 0, 55, 0, 0, '', 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Arnak Grimtotem - Between 0-55% Health - Say Line 2 (No Repeat)'),
(45438, 0, 4, 0, 61, 0, 100, 1, 0, 55, 0, 0, '', 11, 85814, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Arnak Grimtotem - Between 0-55% Health - Cast \'Chieftan\'s Call\' (No Repeat)'),
(45438, 0, 5, 6, 2, 0, 100, 1, 0, 25, 0, 0, '', 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Arnak Grimtotem - Between 0-25% Health - Say Line 3 (No Repeat)'),
(45438, 0, 6, 0, 61, 0, 100, 1, 0, 25, 0, 0, '', 11, 85815, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Arnak Grimtotem - Between 0-25% Health - Cast \'Chieftan\'s Call\' (No Repeat)'),
(45438, 0, 7, 0, 6, 0, 100, 1, 0, 0, 0, 0, '', 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Arnak Grimtotem - On Just Died - Say Line 4 (No Repeat)'),
(45438, 0, 8, 0, 0, 0, 100, 0, 5000, 6000, 120000, 125000, '', 11, 80983, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Arnak Grimtotem - In Combat - Cast \'Commanding Shout\''),
(45438, 0, 9, 0, 0, 0, 100, 0, 9000, 15000, 25000, 26000, '', 11, 11977, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Arnak Grimtotem - In Combat - Cast \'Rend\''),
(45438, 0, 10, 0, 0, 0, 100, 0, 6500, 16500, 9900, 19500, '', 11, 83639, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Arnak Grimtotem - In Combat - Cast \'Bloodbath\''),
(47434, 0, 0, 0, 0, 0, 100, 0, 0, 0, 2300, 3900, '', 11, 6660, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Iron Summit Guard - In Combat - Cast \'Shoot\''),
(47434, 0, 1, 0, 2, 0, 100, 1, 0, 15, 0, 0, '', 25, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Iron Summit Guard - Between 0-15% Health - Flee For Assist (No Repeat)'),
(47434, 0, 2, 0, 9, 0, 100, 0, 0, 20, 8000, 9000, '', 11, 12024, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Iron Summit Guard - Within 0-20 Range - Cast \'Net\''),
(48312, 0, 3, 0, 0, 0, 100, 0, 5000, 8000, 12000, 15000, '', 11, 15245, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cast Shadow Bolt Volley'),
(48312, 0, 2, 0, 2, 0, 100, 512, 0, 40, 22000, 25000, '', 11, 17173, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cast Drain Life at 40% HP'),
(48312, 0, 1, 0, 1, 0, 100, 1, 3000, 5000, 0, 0, '', 11, 30842, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cast Summon Felhunter on Spawn'),
(48312, 0, 0, 0, 1, 0, 100, 0, 500, 1000, 600000, 600000, '', 11, 13787, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cast Demon Armor on Spawn'),
(48314, 0, 3, 0, 4, 0, 100, 1, 0, 0, 0, 0, '', 11, 32064, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cast Battle Shout on Aggro'),
(48314, 0, 0, 0, 0, 0, 100, 0, 8000, 8000, 18000, 22000, '', 11, 11977, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cast Rend'),
(48314, 0, 1, 0, 0, 0, 100, 0, 4000, 4000, 12000, 17000, '', 11, 79881, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cast Slam'),
(48314, 0, 2, 0, 2, 0, 100, 512, 0, 60, 22000, 25000, '', 11, 79877, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cast Bloodthirst at 60% HP'),
(48316, 0, 0, 0, 0, 0, 100, 0, 5000, 6000, 12000, 13000, '', 11, 32736, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cast Mortal Strike'),
(48316, 0, 1, 0, 0, 0, 100, 0, 8000, 8000, 14000, 18000, '', 11, 9080, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cast Hamstring'),
(55418, 0, 0, 0, 0, 0, 100, 30, 5000, 7000, 14000, 18000, '', 11, 109396, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 'Claw of Go\'rath - In Combat - Cast \'Ooze Spit\' (Dungeon & Raid)'),
(55418, 0, 1, 0, 0, 0, 100, 30, 4000, 4000, 18000, 22000, '', 11, 104377, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Claw of Go\'rath - In Combat - Cast \'Black Blood of Go\'rath\' (Dungeon & Raid)'),
(55418, 0, 2, 0, 4, 0, 100, 543, 0, 0, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Claw of Go\'rath - On Aggro - Disable Combat Movement (No Repeat) (Dungeon & Raid)'),
(57875, 0, 0, 0, 4, 0, 100, 543, 0, 0, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Eye of Go\'rath - On Aggro - Disable Combat Movement (No Repeat) (Dungeon & Raid)'),
(57875, 0, 1, 0, 0, 0, 100, 30, 7000, 9000, 18000, 20000, '', 11, 109391, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 'Eye of Go\'rath - In Combat - Cast \'Shadow Gaze\' (Dungeon & Raid)'),
(57877, 0, 0, 0, 4, 0, 100, 543, 0, 0, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Flail of Go\'rath - On Aggro - Disable Combat Movement (No Repeat) (Dungeon & Raid)'),
(57877, 0, 1, 0, 0, 0, 100, 30, 2000, 4500, 12000, 13000, '', 11, 110102, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Flail of Go\'rath - In Combat - Cast \'Sludge Spew\' (Dungeon & Raid)'),
(57877, 0, 2, 0, 0, 0, 100, 30, 9000, 9000, 25000, 27000, '', 11, 109199, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Flail of Go\'rath - In Combat - Cast \'Wild Flail\' (Dungeon & Raid)'),
(57890, 0, 0, 0, 0, 0, 100, 542, 5000, 7000, 14000, 18000, '', 11, 109396, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 'Claw of Go\'rath - In Combat - Cast \'Ooze Spit\' (Dungeon & Raid)'),
(57890, 0, 1, 0, 0, 0, 100, 542, 7000, 10000, 15000, 30000, '', 11, 109197, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Claw of Go\'rath - In Combat - Cast \'Tentacle Toss\' (Dungeon & Raid)'),
(57890, 0, 2, 0, 4, 0, 100, 543, 0, 0, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Claw of Go\'rath - On Aggro - Disable Combat Movement (No Repeat) (Dungeon & Raid)'),
(83600, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, '', 1, 0, 2000, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Durnan Furcutter - On Script - Say Line 0'),
(83600, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, '', 5, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Durnan Furcutter - On Script - Play Emote 7'),
(83600, 9, 2, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, '', 1, 1, 12000, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Durnan Furcutter - On Script - Say Line 0'),
(83600, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, '', 5, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Durnan Furcutter - On Script - Play Emote 0'),
(164885, 1, 0, 0, 20, 0, 100, 0, 4119, 0, 0, 0, '', 70, 5000, 0, 0, 0, 0, 0, 14, 17641, 0, 0, 0, 0, 0, 0, 'Corrupted Night Dragon - On Quest \'Corrupted Night Dragon\' Finished - Respawn Closest Gameobject \'Cleansed Night Dragon\''),
(164886, 1, 0, 0, 20, 0, 100, 0, 2523, 0, 0, 0, '', 70, 5000, 0, 0, 0, 0, 0, 14, 48876, 0, 0, 0, 0, 0, 0, 'Corrupted Songflower - On Quest \'Corrupted Songflower\' Finished - Respawn Closest Gameobject \'Cleansed Songflower\''),
(164887, 1, 0, 0, 20, 0, 100, 0, 996, 0, 0, 0, '', 70, 5000, 0, 0, 0, 0, 0, 14, 48878, 0, 0, 0, 0, 0, 0, 'Corrupted Windblossom - On Quest \'Corrupted Windblossom\' Finished - Respawn Closest Gameobject \'Cleansed Windblossom\''),
(164888, 1, 0, 0, 20, 0, 100, 0, 4117, 0, 0, 0, '', 70, 5000, 0, 0, 0, 0, 0, 14, 48881, 0, 0, 0, 0, 0, 0, 'Corrupted Whipper Root - On Quest \'Corrupted Whipper Root\' Finished - Respawn Closest Gameobject \'Cleansed Whipper Root\''),
(171939, 1, 0, 0, 20, 0, 100, 0, 2878, 0, 0, 0, '', 70, 5000, 0, 0, 0, 0, 0, 14, 48877, 0, 0, 0, 0, 0, 0, 'Corrupted Songflower - On Quest \'Corrupted Songflower\' Finished - Respawn Closest Gameobject \'Cleansed Songflower\''),
(171942, 1, 0, 0, 20, 0, 100, 0, 3363, 0, 0, 0, '', 70, 5000, 0, 0, 0, 0, 0, 14, 48892, 0, 0, 0, 0, 0, 0, 'Corrupted Songflower - On Quest \'Corrupted Songflower\' Finished - Respawn Closest Gameobject \'Cleansed Songflower\''),
(173284, 1, 0, 0, 20, 0, 100, 0, 4443, 0, 0, 0, '', 70, 5000, 0, 0, 0, 0, 0, 14, 44882, 0, 0, 0, 0, 0, 0, 'Corrupted Whipper Root - On Quest \'Corrupted Whipper Root\' Finished - Respawn Closest Gameobject \'Cozy Fire\''),
(173324, 1, 0, 0, 20, 0, 100, 0, 4448, 0, 0, 0, '', 70, 5000, 0, 0, 0, 0, 0, 14, 48874, 0, 0, 0, 0, 0, 0, 'Corrupted Night Dragon - On Quest \'Corrupted Night Dragon\' Finished - Respawn Closest Gameobject \'Cleansed Night Dragon\''),
(173327, 1, 0, 0, 20, 0, 100, 0, 998, 0, 0, 0, '', 70, 5000, 0, 0, 0, 0, 0, 14, 48879, 0, 0, 0, 0, 0, 0, 'Corrupted Windblossom - On Quest \'Corrupted Windblossom\' Finished - Respawn Closest Gameobject \'Cleansed Windblossom\''),
(174594, 1, 0, 0, 20, 0, 100, 0, 4113, 0, 0, 0, '', 70, 5000, 0, 0, 0, 0, 0, 14, 48893, 0, 0, 0, 0, 0, 0, 'Corrupted Songflower - On Quest \'Corrupted Songflower\' Finished - Respawn Closest Gameobject \'Cleansed Songflower\''),
(174595, 1, 0, 0, 20, 0, 100, 0, 4114, 0, 0, 0, '', 70, 5000, 0, 0, 0, 0, 0, 14, 48894, 0, 0, 0, 0, 0, 0, 'Corrupted Songflower - On Quest \'Corrupted Songflower\' Finished - Respawn Closest Gameobject \'Cleansed Songflower\''),
(174596, 1, 0, 0, 20, 0, 100, 0, 4116, 0, 0, 0, '', 70, 5000, 0, 0, 0, 0, 0, 14, 48895, 0, 0, 0, 0, 0, 0, 'Corrupted Songflower - On Quest \'Corrupted Songflower\' Finished - Respawn Closest Gameobject \'Cleansed Songflower\''),
(174597, 1, 0, 0, 20, 0, 100, 0, 4118, 0, 0, 0, '', 70, 5000, 0, 0, 0, 0, 0, 14, 18207, 0, 0, 0, 0, 0, 0, 'Corrupted Songflower - On Quest \'Corrupted Songflower\' Finished - Respawn Closest Gameobject \'Cleansed Songflower\''),
(174598, 1, 0, 0, 20, 0, 100, 0, 4401, 0, 0, 0, '', 70, 5000, 0, 0, 0, 0, 0, 14, 48896, 0, 0, 0, 0, 0, 0, 'Corrupted Songflower - On Quest \'Corrupted Songflower\' Finished - Respawn Closest Gameobject \'Cleansed Songflower\''),
(174599, 1, 0, 0, 20, 0, 100, 0, 1514, 0, 0, 0, '', 70, 5000, 0, 0, 0, 0, 0, 14, 48880, 0, 0, 0, 0, 0, 0, 'Corrupted Windblossom - On Quest \'Corrupted Windblossom\' Finished - Respawn Closest Gameobject \'Cleansed Windblossom\''),
(174600, 1, 0, 0, 20, 0, 100, 0, 4115, 0, 0, 0, '', 70, 5000, 0, 0, 0, 0, 0, 14, 48887, 0, 0, 0, 0, 0, 0, 'Corrupted Windblossom - On Quest \'Corrupted Windblossom\' Finished - Respawn Closest Gameobject \'Cleansed Windblossom\''),
(174601, 1, 0, 0, 20, 0, 100, 0, 4221, 0, 0, 0, '', 70, 5000, 0, 0, 0, 0, 0, 14, 48888, 0, 0, 0, 0, 0, 0, 'Corrupted Windblossom - On Quest \'Corrupted Windblossom\' Finished - Respawn Closest Gameobject \'Cleansed Windblossom\''),
(174602, 1, 0, 0, 20, 0, 100, 0, 4222, 0, 0, 0, '', 70, 5000, 0, 0, 0, 0, 0, 14, 48889, 0, 0, 0, 0, 0, 0, 'Corrupted Windblossom - On Quest \'Corrupted Windblossom\' Finished - Respawn Closest Gameobject \'Cleansed Windblossom\''),
(174603, 1, 0, 0, 20, 0, 100, 0, 4343, 0, 0, 0, '', 70, 5000, 0, 0, 0, 0, 0, 14, 48890, 0, 0, 0, 0, 0, 0, 'Corrupted Windblossom - On Quest \'Corrupted Windblossom\' Finished - Respawn Closest Gameobject \'Cleansed Windblossom\''),
(174604, 1, 0, 0, 20, 0, 100, 0, 4403, 0, 0, 0, '', 70, 5000, 0, 0, 0, 0, 0, 14, 48891, 0, 0, 0, 0, 0, 0, 'Corrupted Windblossom - On Quest \'Corrupted Windblossom\' Finished - Respawn Closest Gameobject \'Cleansed Windblossom\''),
(174605, 1, 0, 0, 20, 0, 100, 0, 4444, 0, 0, 0, '', 70, 5000, 0, 0, 0, 0, 0, 14, 48883, 0, 0, 0, 0, 0, 0, 'Corrupted Whipper Root - On Quest \'Corrupted Whipper Root\' Finished - Respawn Closest Gameobject \'Cleansed Whipper Root\''),
(174606, 1, 0, 0, 20, 0, 100, 0, 4445, 0, 0, 0, '', 70, 5000, 0, 0, 0, 0, 0, 14, 48884, 0, 0, 0, 0, 0, 0, 'Corrupted Whipper Root - On Quest \'Corrupted Whipper Root\' Finished - Respawn Closest Gameobject \'Cleansed Whipper Root\''),
(174607, 1, 0, 0, 20, 0, 100, 0, 4446, 0, 0, 0, '', 70, 5000, 0, 0, 0, 0, 0, 14, 48885, 0, 0, 0, 0, 0, 0, 'Corrupted Whipper Root - On Quest \'Corrupted Whipper Root\' Finished - Respawn Closest Gameobject \'Cleansed Whipper Root\''),
(174608, 1, 0, 0, 20, 0, 100, 0, 4462, 0, 0, 0, '', 70, 5000, 0, 0, 0, 0, 0, 14, 48875, 0, 0, 0, 0, 0, 0, 'Corrupted Night Dragon - On Quest \'Corrupted Night Dragon\' Finished - Respawn Closest Gameobject \'Cleansed Night Dragon\''),
(174684, 1, 0, 0, 20, 0, 100, 0, 4447, 0, 0, 0, '', 70, 5000, 0, 0, 0, 0, 0, 14, 48873, 0, 0, 0, 0, 0, 0, 'Corrupted Night Dragon - On Quest \'Corrupted Night Dragon\' Finished - Respawn Closest Gameobject \'Cleansed Night Dragon\''),
(174686, 1, 0, 0, 20, 0, 100, 0, 4461, 0, 0, 0, '', 70, 5000, 0, 0, 0, 0, 0, 14, 48886, 0, 0, 0, 0, 0, 0, 'Corrupted Whipper Root - On Quest \'Corrupted Whipper Root\' Finished - Respawn Closest Gameobject \'Cleansed Whipper Root\''),
(174708, 1, 0, 0, 20, 0, 100, 0, 4466, 0, 0, 0, '', 70, 5000, 0, 0, 0, 0, 0, 14, 48897, 0, 0, 0, 0, 0, 0, 'Corrupted Windblossom - On Quest \'Corrupted Windblossom\' Finished - Respawn Closest Gameobject \'Cleansed Windblossom\''),
(174709, 1, 0, 0, 20, 0, 100, 0, 4467, 0, 0, 0, '', 70, 5000, 0, 0, 0, 0, 0, 14, 48899, 0, 0, 0, 0, 0, 0, 'Corrupted Windblossom - On Quest \'Corrupted Windblossom\' Finished - Respawn Closest Gameobject \'Cleansed Windblossom\''),
(174712, 1, 0, 0, 20, 0, 100, 0, 4464, 0, 0, 0, '', 70, 5000, 0, 0, 0, 0, 0, 14, 48898, 0, 0, 0, 0, 0, 0, 'Corrupted Songflower - On Quest \'Corrupted Songflower\' Finished - Respawn Closest Gameobject \'Cleansed Songflower\''),
(174713, 1, 0, 0, 20, 0, 100, 0, 4465, 0, 0, 0, '', 70, 5000, 0, 0, 0, 0, 0, 14, 48900, 0, 0, 0, 0, 0, 0, 'Corrupted Songflower - On Quest \'Corrupted Songflower\' Finished - Respawn Closest Gameobject \'Cleansed Songflower\''),
(305400, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zarlman Two-Moons - On Script - Say Line 0'),
(305400, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, '', 11, 5026, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zarlman Two-Moons - On Script - Cast \'Create Water of the Seers\''),
(305400, 9, 2, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, '', 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zarlman Two-Moons - On Script - Say Line 1');

UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=-21002065 AND `source_type`=0 AND `id`=1 AND `link`=2;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=-112625 AND `source_type`=0 AND `id`=1 AND `link`=0;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=-112623 AND `source_type`=0 AND `id`=0 AND `link`=1;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=-102845 AND `source_type`=0 AND `id`=0 AND `link`=1;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=-102844 AND `source_type`=0 AND `id`=0 AND `link`=1;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=2487 AND `source_type`=0 AND `id`=0 AND `link`=1;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=3679 AND `source_type`=0 AND `id`=0 AND `link`=1;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=4422 AND `source_type`=0 AND `id`=1 AND `link`=3;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=6221 AND `source_type`=0 AND `id`=9 AND `link`=10;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=6221 AND `source_type`=0 AND `id`=9 AND `link`=10;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=6221 AND `source_type`=0 AND `id`=19 AND `link`=20;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=7849 AND `source_type`=0 AND `id`=0 AND `link`=1;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=8895 AND `source_type`=0 AND `id`=5 AND `link`=0;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=8895 AND `source_type`=0 AND `id`=3 AND `link`=14;
UPDATE `smart_scripts` SET `id`='5' WHERE  `entryorguid`=8895 AND `source_type`=0 AND `id`=6 AND `link`=0;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=10556 AND `source_type`=0 AND `id`=0 AND `link`=1;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=18683 AND `source_type`=0 AND `id`=10 AND `link`=2;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=18683 AND `source_type`=0 AND `id`=21 AND `link`=2;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=18683 AND `source_type`=0 AND `id`=32 AND `link`=2;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=18683 AND `source_type`=0 AND `id`=43 AND `link`=2;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=18683 AND `source_type`=0 AND `id`=54 AND `link`=2;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=18683 AND `source_type`=0 AND `id`=65 AND `link`=2;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=18683 AND `source_type`=0 AND `id`=11 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=18683 AND `source_type`=0 AND `id`=22 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=18683 AND `source_type`=0 AND `id`=33 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=18683 AND `source_type`=0 AND `id`=44 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=18683 AND `source_type`=0 AND `id`=55 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=18683 AND `source_type`=0 AND `id`=66 AND `link`=0;

DELETE FROM `smart_scripts` WHERE `entryorguid`=18683;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(18683, 0, 0, 0, 11, 0, 100, 1, 0, 0, 0, 0, '', 30, 1, 2, 3, 4, 5, 6, 1, 0, 0, 0, 0, 0, 0, 0, 'Random Phase on Spawn'),
(18683, 0, 1, 0, 4, 1, 100, 1, 0, 0, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stop Moving on Aggro'),
(18683, 0, 2, 0, 4, 1, 100, 1, 0, 0, 0, 0, '', 11, 34447, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cast Arcane Missiles on Aggro'),
(18683, 0, 3, 0, 9, 1, 100, 0, 0, 40, 3400, 4700, '', 11, 34447, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cast Arcane Missiles'),
(18683, 0, 4, 0, 9, 1, 100, 0, 40, 100, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Start Moving when not in Arcane Missiles Range'),
(18683, 0, 5, 0, 9, 1, 100, 0, 10, 15, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stop Moving at 15 Yards'),
(18683, 0, 6, 0, 9, 1, 100, 0, 0, 40, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stop Moving when in Arcane Missiles Range'),
(18683, 0, 7, 0, 1, 1, 100, 1, 2000, 2000, 0, 0, '', 11, 34331, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cast Damage Reduction: Arcane OOC'),
(18683, 0, 8, 0, 3, 1, 100, 0, 0, 15, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Start Moving at 15% Mana'),
(18683, 0, 9, 0, 2, 1, 100, 1, 0, 10, 0, 0, '', 11, 34233, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cast Collapse at 10% HP'),
(18683, 0, 10, 0, 6, 1, 100, 1, 0, 0, 0, 0, '', 11, 34234, 3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cast Collapse on Death'),
(18683, 0, 11, 0, 4, 2, 100, 1, 0, 0, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stop Moving on Aggro'),
(18683, 0, 12, 0, 4, 2, 100, 1, 0, 0, 0, 0, '', 11, 34348, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cast Arcane Missiles on Aggro'),
(18683, 0, 13, 0, 9, 2, 100, 0, 0, 40, 3400, 4700, '', 11, 34348, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cast Fireball'),
(18683, 0, 14, 0, 9, 2, 100, 0, 40, 100, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Start Moving when not in Fireball Range'),
(18683, 0, 15, 0, 9, 2, 100, 0, 10, 15, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stop Moving at 15 Yards'),
(18683, 0, 16, 0, 9, 2, 100, 0, 0, 40, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stop Moving when in Fireball Range'),
(18683, 0, 17, 0, 1, 2, 100, 1, 2000, 2000, 0, 0, '', 11, 34333, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cast Damage Reduction: Fire OOC'),
(18683, 0, 18, 0, 3, 2, 100, 0, 0, 15, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Start Moving at 15% Mana'),
(18683, 0, 19, 0, 2, 2, 100, 1, 0, 10, 0, 0, '', 11, 34233, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cast Collapse at 10% HP'),
(18683, 0, 20, 0, 6, 2, 100, 1, 0, 0, 0, 0, '', 11, 34234, 3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cast Collapse on Death'),
(18683, 0, 21, 0, 4, 3, 100, 1, 0, 0, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stop Moving on Aggro'),
(18683, 0, 22, 0, 4, 3, 100, 1, 0, 0, 0, 0, '', 11, 34347, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cast Frostbolt on Aggro'),
(18683, 0, 23, 0, 9, 3, 100, 0, 0, 40, 3400, 4700, '', 11, 34347, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cast Frostbolt'),
(18683, 0, 24, 0, 9, 3, 100, 0, 40, 100, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Start Moving when not in Frostbolt Range'),
(18683, 0, 25, 0, 9, 3, 100, 0, 10, 15, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stop Moving at 15 Yards'),
(18683, 0, 26, 0, 9, 3, 100, 0, 0, 40, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stop Moving when in Frostbolt Range'),
(18683, 0, 27, 0, 1, 3, 100, 1, 2000, 2000, 0, 0, '', 11, 34334, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cast Damage Reduction: Frost OOC'),
(18683, 0, 28, 0, 3, 3, 100, 0, 0, 15, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Start Moving at 15% Mana'),
(18683, 0, 29, 0, 2, 3, 100, 1, 0, 10, 0, 0, '', 11, 34233, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cast Collapse at 10% HP'),
(18683, 0, 30, 0, 6, 3, 100, 1, 0, 0, 0, 0, '', 11, 34234, 3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cast Collapse on Death'),
(18683, 0, 31, 0, 4, 4, 100, 1, 0, 0, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stop Moving on Aggro'),
(18683, 0, 32, 0, 4, 4, 100, 1, 0, 0, 0, 0, '', 11, 34346, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cast Holy Bolt on Aggro'),
(18683, 0, 33, 0, 9, 4, 100, 0, 0, 40, 3400, 4700, '', 11, 34346, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cast Holy Bolt'),
(18683, 0, 34, 0, 9, 4, 100, 0, 40, 100, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Start Moving when not in Holy Bolt Range'),
(18683, 0, 35, 0, 9, 4, 100, 0, 10, 15, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stop Moving at 15 Yards'),
(18683, 0, 36, 0, 9, 4, 100, 0, 0, 40, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stop Moving when in Holy Bolt Range'),
(18683, 0, 37, 0, 1, 4, 100, 1, 2000, 2000, 0, 0, '', 11, 34336, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cast Damage Reduction: Holy OOC'),
(18683, 0, 38, 0, 3, 4, 100, 0, 0, 15, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Start Moving at 15% Mana'),
(18683, 0, 39, 0, 2, 4, 100, 1, 0, 10, 0, 0, '', 11, 34233, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cast Collapse at 10% HP'),
(18683, 0, 40, 0, 6, 4, 100, 1, 0, 0, 0, 0, '', 11, 34234, 3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cast Collapse on Death'),
(18683, 0, 41, 0, 4, 5, 100, 1, 0, 0, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stop Moving on Aggro'),
(18683, 0, 42, 0, 4, 5, 100, 1, 0, 0, 0, 0, '', 11, 34345, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cast Lightning Bolt on Aggro'),
(18683, 0, 43, 0, 9, 5, 100, 0, 0, 40, 3400, 4700, '', 11, 34345, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cast Lightning Bolt'),
(18683, 0, 44, 0, 9, 5, 100, 0, 40, 100, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Start Moving when not in Lightning Bolt Range'),
(18683, 0, 45, 0, 9, 5, 100, 0, 10, 15, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stop Moving at 15 Yards'),
(18683, 0, 46, 0, 9, 5, 100, 0, 0, 40, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stop Moving when in Lightning Bolt Range'),
(18683, 0, 47, 0, 1, 5, 100, 1, 2000, 2000, 0, 0, '', 11, 34335, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cast Damage Reduction: Nature OOC'),
(18683, 0, 48, 0, 3, 5, 100, 0, 0, 15, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Start Moving at 15% Mana'),
(18683, 0, 49, 0, 2, 5, 100, 1, 0, 10, 0, 0, '', 11, 34233, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cast Collapse at 10% HP'),
(18683, 0, 50, 0, 6, 5, 100, 1, 0, 0, 0, 0, '', 11, 34234, 3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cast Collapse on Death'),
(18683, 0, 51, 0, 4, 6, 100, 1, 0, 0, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stop Moving on Aggro'),
(18683, 0, 52, 0, 4, 6, 100, 1, 0, 0, 0, 0, '', 11, 34344, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cast Shadow Bolt on Aggro'),
(18683, 0, 53, 0, 9, 6, 100, 0, 0, 40, 3400, 4700, '', 11, 34344, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cast Shadow Bolt'),
(18683, 0, 54, 0, 9, 6, 100, 0, 40, 100, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Start Moving when not in Shadow Bolt Range'),
(18683, 0, 55, 0, 9, 6, 100, 0, 10, 15, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stop Moving at 15 Yards'),
(18683, 0, 56, 0, 9, 6, 100, 0, 0, 40, 0, 0, '', 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stop Moving when in Shadow Bolt Range'),
(18683, 0, 57, 0, 1, 6, 100, 1, 2000, 2000, 0, 0, '', 11, 34338, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cast Damage Reduction: Shadow OOC'),
(18683, 0, 58, 0, 3, 6, 100, 0, 0, 15, 0, 0, '', 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Start Moving at 15% Mana'),
(18683, 0, 59, 0, 2, 6, 100, 1, 0, 10, 0, 0, '', 11, 34233, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cast Collapse at 10% HP'),
(18683, 0, 60, 0, 6, 6, 100, 1, 0, 0, 0, 0, '', 11, 34234, 3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cast Collapse on Death');

UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=19449 AND `source_type`=0 AND `id`=1 AND `link`=17;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=19449 AND `source_type`=0 AND `id`=2 AND `link`=0;
UPDATE `smart_scripts` SET `id`='2' WHERE  `entryorguid`=19449 AND `source_type`=0 AND `id`=3 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=19580 AND `source_type`=0 AND `id`=1 AND `link`=2;
UPDATE `smart_scripts` SET `id`='1' WHERE  `entryorguid`=19580 AND `source_type`=0 AND `id`=2 AND `link`=0;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=20859 AND `source_type`=0 AND `id`=2 AND `link`=5;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=20859 AND `source_type`=0 AND `id`=3 AND `link`=5;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=20859 AND `source_type`=0 AND `id`=4 AND `link`=5;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=20859 AND `source_type`=0 AND `id`=6 AND `link`=5;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=26917 AND `source_type`=0 AND `id`=0 AND `link`=1;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=38409 AND `source_type`=0 AND `id`=1 AND `link`=2;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=38805 AND `source_type`=0 AND `id`=1 AND `link`=2;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=38988 AND `source_type`=0 AND `id`=0 AND `link`=1;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=39582 AND `source_type`=0 AND `id`=1 AND `link`=2;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=39582 AND `source_type`=0 AND `id`=3 AND `link`=4;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=39582 AND `source_type`=0 AND `id`=5 AND `link`=6;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=43042 AND `source_type`=0 AND `id`=0 AND `link`=1;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=43572 AND `source_type`=0 AND `id`=0 AND `link`=1;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=44427 AND `source_type`=0 AND `id`=0 AND `link`=1;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=45162 AND `source_type`=0 AND `id`=0 AND `link`=1;
UPDATE `smart_scripts` SET `id`='0' WHERE  `entryorguid`=45162 AND `source_type`=0 AND `id`=1 AND `link`=2;
UPDATE `smart_scripts` SET `id`='1' WHERE  `entryorguid`=45162 AND `source_type`=0 AND `id`=2 AND `link`=0;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=46503 AND `source_type`=0 AND `id`=0 AND `link`=1;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=46768 AND `source_type`=0 AND `id`=0 AND `link`=1;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=46769 AND `source_type`=0 AND `id`=0 AND `link`=1;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=46881 AND `source_type`=0 AND `id`=1 AND `link`=2;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=46882 AND `source_type`=0 AND `id`=1 AND `link`=2;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=48705 AND `source_type`=0 AND `id`=0 AND `link`=1;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=49635 AND `source_type`=0 AND `id`=0 AND `link`=1;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=53129 AND `source_type`=0 AND `id`=0 AND `link`=1;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=53130 AND `source_type`=0 AND `id`=0 AND `link`=1;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=55556 AND `source_type`=0 AND `id`=3 AND `link`=0;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=55556 AND `source_type`=0 AND `id`=2 AND `link`=4;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=59986 AND `source_type`=0 AND `id`=21 AND `link`=22;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=76446 AND `source_type`=0 AND `id`=1 AND `link`=2;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=79521 AND `source_type`=0 AND `id`=3 AND `link`=4;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=79896 AND `source_type`=0 AND `id`=1 AND `link`=2;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=82489 AND `source_type`=0 AND `id`=1 AND `link`=2;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=82491 AND `source_type`=0 AND `id`=1 AND `link`=2;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=82492 AND `source_type`=0 AND `id`=1 AND `link`=2;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=82901 AND `source_type`=0 AND `id`=1 AND `link`=2;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=82909 AND `source_type`=0 AND `id`=1 AND `link`=2;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=84223 AND `source_type`=0 AND `id`=1 AND `link`=2;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=84372 AND `source_type`=0 AND `id`=1 AND `link`=2;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=86697 AND `source_type`=0 AND `id`=2 AND `link`=3;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=86697 AND `source_type`=0 AND `id`=12 AND `link`=13;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=86697 AND `source_type`=0 AND `id`=22 AND `link`=23;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=86697 AND `source_type`=0 AND `id`=32 AND `link`=33;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=86697 AND `source_type`=0 AND `id`=42 AND `link`=43;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=88125 AND `source_type`=0 AND `id`=3 AND `link`=4;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=88229 AND `source_type`=0 AND `id`=1 AND `link`=2;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=100018 AND `source_type`=0 AND `id`=3 AND `link`=1;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=86697 AND `source_type`=0 AND `id`=11 AND `link`=11;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=17725 AND `source_type`=0 AND `id`=2 AND `link`=3;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=17725 AND `source_type`=0 AND `id`=3 AND `link`=0;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=3616 AND `source_type`=0 AND `id`=0 AND `link`=1;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=19580 AND `source_type`=0 AND `id`=1 AND `link`=0;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=38409 AND `source_type`=0 AND `id`=0 AND `link`=1;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=41641 AND `source_type`=0 AND `id`=0 AND `link`=1;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=45162 AND `source_type`=0 AND `id`=0 AND `link`=2;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=45162 AND `source_type`=0 AND `id`=1 AND `link`=0;
UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=86697 AND `source_type`=0 AND `id`=10 AND `link`=11;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=86697 AND `source_type`=0 AND `id`=12 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=86697 AND `source_type`=0 AND `id`=11 AND `link`=0;
UPDATE `smart_scripts` SET `action_param1`='89344' WHERE  `entryorguid`=14347 AND `source_type`=0 AND `id`=0 AND `link`=0;
UPDATE `smart_scripts` SET `action_param1`='89344' WHERE  `entryorguid`=17725 AND `source_type`=0 AND `id`=2 AND `link`=0;
UPDATE `smart_scripts` SET `action_param1`='89344' WHERE  `entryorguid`=23619 AND `source_type`=0 AND `id`=1 AND `link`=0;
UPDATE `smart_scripts` SET `action_param1`='89344' WHERE  `entryorguid`=23623 AND `source_type`=0 AND `id`=0 AND `link`=0;
UPDATE `smart_scripts` SET `action_param1`='89344' WHERE  `entryorguid`=23624 AND `source_type`=0 AND `id`=0 AND `link`=0;
UPDATE `smart_scripts` SET `action_param1`='89344' WHERE  `entryorguid`=23625 AND `source_type`=0 AND `id`=0 AND `link`=0;
UPDATE `smart_scripts` SET `action_param1`='89344' WHERE  `entryorguid`=23626 AND `source_type`=0 AND `id`=0 AND `link`=0;

DELETE FROM `smart_scripts` WHERE  `entryorguid`=-10638345 AND `id`=0 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=-10638344 AND `id`=0 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=-10638343 AND `id`=0 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=-10638342 AND `id`=0 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=-10638341 AND `id`=0 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=-10638340 AND `id`=0 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=-10638339 AND `id`=0 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=-10638337 AND `id`=0 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=-10599226 AND `id`=0 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=-10592263 AND `id`=0 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=-117070 AND `id`=0 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=8284 AND `id`=0 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=33507 AND `id`=1 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=34007 AND `id`=0 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=34007 AND `id`=9 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=37198 AND `id`=0 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=42736 AND `id`=0 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=43571 AND `id`=0 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=43919 AND `id`=0 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=43920 AND `id`=0 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=43921 AND `id`=0 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=45963 AND `id`=1 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=72814 AND `id`=0 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=74225 AND `id`=0 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=76268 AND `id`=2 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=76278 AND `id`=3 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=76290 AND `id`=1 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=76290 AND `id`=6 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=76290 AND `id`=0 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=76400 AND `id`=0 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=76669 AND `id`=0 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=76670 AND `id`=0 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=76720 AND `id`=0 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=76721 AND `id`=0 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=76759 AND `id`=5 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=77312 AND `id`=0 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=78580 AND `id`=0 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=78617 AND `id`=1 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=78816 AND `id`=0 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=79521 AND `id`=1 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=79521 AND `id`=4 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=80251 AND `id`=1 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=80481 AND `id`=1 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=80656 AND `id`=0 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=80894 AND `id`=2 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=80903 AND `id`=2 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=80906 AND `id`=2 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=81416 AND `id`=1 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=81567 AND `id`=2 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=81717 AND `id`=5 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=82321 AND `id`=0 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=82518 AND `id`=0 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=82545 AND `id`=2 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=82611 AND `id`=15 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=84443 AND `id`=6 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=85059 AND `id`=6 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=85063 AND `id`=1 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=85793 AND `id`=0 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=86671 AND `id`=1 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=86680 AND `id`=1 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=90383 AND `id`=0 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=100006 AND `id`=1 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=2448400 AND `id`=0 AND `action_type`=53;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=2448401 AND `id`=0 AND `action_type`=53;

UPDATE `smart_scripts` SET `link`='0' WHERE  `entryorguid`=6221 AND `source_type`=0 AND `id`=18 AND `link`=19;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=86697 AND `source_type`=0 AND `id`=11 AND `link`=0;
DELETE FROM .`smart_scripts` WHERE  `entryorguid`=86697 AND `source_type`=0 AND `id`=11 AND `link`=12;

UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=-204361 AND `source_type`=0 AND `id`=0 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=24170 AND `source_type`=0 AND `id`=1 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=24238 AND `source_type`=0 AND `id`=2 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=26773 AND `source_type`=0 AND `id`=0 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=26831 AND `source_type`=0 AND `id`=0 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=28595 AND `source_type`=0 AND `id`=0 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=33736 AND `source_type`=0 AND `id`=0 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=36472 AND `source_type`=0 AND `id`=0 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=38190 AND `source_type`=9 AND `id`=1 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=39730 AND `source_type`=0 AND `id`=1 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=39736 AND `source_type`=0 AND `id`=1 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=39737 AND `source_type`=0 AND `id`=1 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=39738 AND `source_type`=0 AND `id`=1 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=42384 AND `source_type`=0 AND `id`=0 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=42384 AND `source_type`=0 AND `id`=2 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=42391 AND `source_type`=0 AND `id`=0 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=42391 AND `source_type`=0 AND `id`=2 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=47707 AND `source_type`=0 AND `id`=1 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=52553 AND `source_type`=0 AND `id`=0 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=53566 AND `source_type`=0 AND `id`=1 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=54870 AND `source_type`=0 AND `id`=1 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=55141 AND `source_type`=0 AND `id`=0 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=55146 AND `source_type`=0 AND `id`=0 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=55162 AND `source_type`=0 AND `id`=0 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=55170 AND `source_type`=0 AND `id`=0 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=55267 AND `source_type`=0 AND `id`=0 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=55567 AND `source_type`=9 AND `id`=1 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=55789 AND `source_type`=0 AND `id`=0 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=56336 AND `source_type`=0 AND `id`=0 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=56340 AND `source_type`=0 AND `id`=0 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=56477 AND `source_type`=0 AND `id`=0 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=56478 AND `source_type`=0 AND `id`=0 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=63058 AND `source_type`=0 AND `id`=0 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=63059 AND `source_type`=0 AND `id`=0 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=65910 AND `source_type`=0 AND `id`=0 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=66220 AND `source_type`=0 AND `id`=0 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=66564 AND `source_type`=0 AND `id`=0 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=76290 AND `source_type`=9 AND `id`=3 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=76617 AND `source_type`=9 AND `id`=2 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=76782 AND `source_type`=0 AND `id`=1 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=77413 AND `source_type`=0 AND `id`=2 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=78659 AND `source_type`=0 AND `id`=0 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=80166 AND `source_type`=0 AND `id`=0 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=80481 AND `source_type`=0 AND `id`=0 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=80481 AND `source_type`=0 AND `id`=3 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=80481 AND `source_type`=9 AND `id`=33 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=80595 AND `source_type`=0 AND `id`=1 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=80817 AND `source_type`=0 AND `id`=0 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=81033 AND `source_type`=0 AND `id`=0 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=81034 AND `source_type`=0 AND `id`=0 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=81404 AND `source_type`=0 AND `id`=1 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=81414 AND `source_type`=0 AND `id`=1 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=81567 AND `source_type`=9 AND `id`=0 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=82489 AND `source_type`=0 AND `id`=1 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=82491 AND `source_type`=0 AND `id`=1 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=82492 AND `source_type`=0 AND `id`=1 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=83823 AND `source_type`=0 AND `id`=1 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=84176 AND `source_type`=0 AND `id`=0 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=85091 AND `source_type`=9 AND `id`=1 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=85106 AND `source_type`=9 AND `id`=3 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=90267 AND `source_type`=0 AND `id`=0 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=90644 AND `source_type`=0 AND `id`=0 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=90644 AND `source_type`=0 AND `id`=1 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=92804 AND `source_type`=0 AND `id`=0 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=93956 AND `source_type`=0 AND `id`=0 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=99032 AND `source_type`=0 AND `id`=0 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=100003 AND `source_type`=9 AND `id`=1 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=110557 AND `source_type`=0 AND `id`=0 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=111719 AND `source_type`=0 AND `id`=0 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=121676 AND `source_type`=0 AND `id`=1 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=127271 AND `source_type`=0 AND `id`=1 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=212969 AND `source_type`=1 AND `id`=0 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=233369 AND `source_type`=1 AND `id`=0 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=233664 AND `source_type`=1 AND `id`=0 AND `action_type`=11;
UPDATE `smart_scripts` SET `action_param2`='2', `action_param3`='18', `action_param4`='35', `target_type`='1', `target_param1`='0' WHERE  `entryorguid`=242279 AND `source_type`=1 AND `id`=0 AND `action_type`=11;

