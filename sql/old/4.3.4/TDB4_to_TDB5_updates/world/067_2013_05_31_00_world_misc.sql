-- DB/Misc: Fix: Prevent chat/spell flood, Prevent summon spells from overwriting.

-- Prevent chat/spell flood
UPDATE `smart_scripts` SET `event_flags`=1 WHERE  `entryorguid`=2358 AND `source_type`=0 AND `id`=9 AND `link`=10;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE  `entryorguid`=2358 AND `source_type`=0 AND `id`=10 AND `link`=0;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE  `entryorguid`=2358 AND `source_type`=0 AND `id`=11 AND `link`=12;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE  `entryorguid`=2358 AND `source_type`=0 AND `id`=12 AND `link`=0;

-- Prevent chat flood / ..run away in fear! / Manually checked one by one! (64 NPC's)
UPDATE `smart_scripts` SET `event_flags` = 1 WHERE `entryorguid` IN (429,453,548,1166,1867,1920,2369,4063,5839,7075,11319,11324,15281,15401,15417,15938,15945,15970,15971,16204) AND `source_type` = 0 AND `id` = 12 AND `link` = 13;
UPDATE `smart_scripts` SET `event_flags` = 1 WHERE `entryorguid` IN (429,453,548,1166,1867,1920,2369,4063,5839,7075,11319,11324,15281,15401,15417,15938,15945,15970,15971,16204) AND `source_type` = 0 AND `id` = 13 AND `link` = 0;
UPDATE `smart_scripts` SET `event_flags` = 1 WHERE `entryorguid` IN (1065,1173,1397,1914,1915,2120,2371,2376,6008,8550,9449,16249,16318,16337) AND `source_type` = 0 AND `id` = 13 AND `link` = 14;
UPDATE `smart_scripts` SET `event_flags` = 1 WHERE `entryorguid` IN (1065,1124,1173,1397,1914,1915,2120,2245,2371,2376,6008,8550,9449,16249,16318,16337) AND `source_type` = 0 AND `id` = 14 AND `link` = 0;
UPDATE `smart_scripts` SET `event_flags` = 1 WHERE `entryorguid` IN (1889,2375,2387,8566,9450,16317,16344,25073) AND `source_type` = 0 AND `id` = 14 AND `link` = 15;
UPDATE `smart_scripts` SET `event_flags` = 1 WHERE `entryorguid` IN (1124,1889,2375,2387,8566,9450,16317,16344,25073) AND `source_type` = 0 AND `id` = 15 AND `link` = 0;
UPDATE `smart_scripts` SET `event_flags` = 1 WHERE `entryorguid` IN (1123,1162,2245,2554,9451,16403) AND `source_type` = 0 AND `id` = 15 AND `link` = 16;
UPDATE `smart_scripts` SET `event_flags` = 1 WHERE `entryorguid` IN (1009,1013,1123,1162,2554,7246,9451,16403) AND `source_type` = 0 AND `id` = 16 AND `link` = 0;
UPDATE `smart_scripts` SET `event_flags` = 1 WHERE `entryorguid` IN (2276,2428,4064,4463,10824,12322) AND `source_type` = 0 AND `id` = 16 AND `link` = 17;
UPDATE `smart_scripts` SET `event_flags` = 1 WHERE `entryorguid` IN (2276,2428,4064,4463,10824,12322) AND `source_type` = 0 AND `id` = 17 AND `link` = 0;
UPDATE `smart_scripts` SET `event_flags` = 1 WHERE `entryorguid` IN (436,4462,17694) AND `source_type` = 0 AND `id` = 17 AND `link` = 18;
UPDATE `smart_scripts` SET `event_flags` = 1 WHERE `entryorguid` IN (436,4462,17694) AND `source_type` = 0 AND `id` = 18 AND `link` = 0;
UPDATE `smart_scripts` SET `event_flags` = 1 WHERE `entryorguid` = 8564 AND `source_type` = 0 AND `id` = 18 AND `link` = 19; -- Ranger - Allow Combat Movement
UPDATE `smart_scripts` SET `event_flags` = 1 WHERE `entryorguid` = 8564 AND `source_type` = 0 AND `id` = 19 AND `link` = 0; -- Ranger - Flee For Assist
UPDATE `smart_scripts` SET `event_flags` = 1 WHERE `entryorguid` = 24683 AND `source_type` = 0 AND `id` = 19 AND `link` = 20; -- Sunblade Mage Guard - Allow Combat Movement
UPDATE `smart_scripts` SET `event_flags` = 1 WHERE `entryorguid` = 24683 AND `source_type` = 0 AND `id` = 20 AND `link` = 0; -- Sunblade Mage Guard - Flee For Assist

-- Prevent summon spells from overwriting each other's cast time, earlier script had wrong timers..
UPDATE `smart_scripts` SET `link`=15 WHERE  `entryorguid`=1124 AND `source_type`=0 AND `id`=14 AND `link`=01;
UPDATE `smart_scripts` SET `event_type`=61, `event_flags`=1 WHERE  `entryorguid`=1124 AND `source_type`=0 AND `id`=15 AND `link`=0;
UPDATE `smart_scripts` SET `event_param1`=9100, `event_param2`=14900 WHERE  `entryorguid`=2358 AND `source_type`=0 AND `id`=9 AND `link`=10;
UPDATE `smart_scripts` SET `event_param1`=4700, `event_param2`=11100 WHERE  `entryorguid`=2358 AND `source_type`=0 AND `id`=11 AND `link`=12;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE  `entryorguid` IN (429,453) AND `source_type`=0 AND `id`=12 AND `link`=13;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE  `entryorguid` IN (1009,1065,1397) AND `source_type`=0 AND `id`=13 AND `link`=14;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE  `entryorguid` IN (1009,1013,1123,2245,2554) AND `source_type`=0 AND `id`=15 AND `link`=16;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE  `entryorguid` = 1009 AND `source_type`=0 AND `id`=14 AND `link`=15;
