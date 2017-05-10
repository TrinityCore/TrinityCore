-- Runtime errors
UPDATE `smart_scripts` SET `link`=0 WHERE  `entryorguid`=1124 AND `source_type`=0 AND `id`=14 AND `link`=15;
UPDATE `smart_scripts` SET `link`=0 WHERE  `entryorguid`=1124 AND `source_type`=0 AND `id`=15 AND `link`=16;
UPDATE `smart_scripts` SET `link`=0 WHERE  `entryorguid`=5710 AND `source_type`=0 AND `id`=1 AND `link`=2;
UPDATE `smart_scripts` SET `link`=0 WHERE  `entryorguid`=5997 AND `source_type`=0 AND `id`=8 AND `link`=9;
UPDATE `smart_scripts` SET `link`=0 WHERE  `entryorguid`=7843 AND `source_type`=0 AND `id`=9 AND `link`=10;
UPDATE `smart_scripts` SET `link`=0 WHERE  `entryorguid`=8564 AND `source_type`=0 AND `id`=12 AND `link`=13;
UPDATE `smart_scripts` SET `link`=0 WHERE  `entryorguid`=10824 AND `source_type`=0 AND `id`=8 AND `link`=9;
UPDATE `smart_scripts` SET `link`=0 WHERE  `entryorguid`=12236 AND `source_type`=0 AND `id`=3 AND `link`=4;
UPDATE `smart_scripts` SET `link`=0 WHERE  `entryorguid`=12236 AND `source_type`=0 AND `id`=4 AND `link`=5;
UPDATE `smart_scripts` SET `link`=0 WHERE  `entryorguid`=12236 AND `source_type`=0 AND `id`=9 AND `link`=10;
UPDATE `smart_scripts` SET `link`=0 WHERE  `entryorguid`=12322 AND `source_type`=0 AND `id`=8 AND `link`=9;
-- Timed action scripts aren't supposed to have links set on them
UPDATE `smart_scripts` SET `link`=0, `event_type`=0 WHERE  `entryorguid`=83600 AND `source_type`=9 AND `id`=1 AND `link`=2;
UPDATE `smart_scripts` SET `link`=0, `event_type`=0 WHERE  `entryorguid`=83600 AND `source_type`=9 AND `id`=2 AND `link`=3;
UPDATE `smart_scripts` SET `event_type`=0 WHERE  `entryorguid`=83600 AND `source_type`=9 AND `id`=3 AND `link`=0;
-- Aforementioned issue about links on timed scripts
UPDATE `smart_scripts` SET `link`=0, `event_type`=0 WHERE  `entryorguid`=305400 AND `source_type`=9 AND `id`=1 AND `link`=2;
UPDATE `smart_scripts` SET `event_type`=0 WHERE  `entryorguid`=305400 AND `source_type`=9 AND `id`=2 AND `link`=0;
-- Missing AI's
UPDATE `creature_template` SET `ScriptName`='SmartAI' WHERE `entry` IN 
(10876,14389,13326,13328,12050,12053,10981,10986,10990,11678,11839,12051,12127,13179,13284,13438,13442,13443,13447,13577,13798,14282,14283,10987,10982,11603,11605,13089,13097,13089);
