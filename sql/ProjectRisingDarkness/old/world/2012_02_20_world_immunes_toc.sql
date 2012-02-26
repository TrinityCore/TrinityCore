-- Immunes for bosses in TOC.
-- SELECT  `entry` ,  `difficulty_entry_1` ,  `difficulty_entry_2` ,  `difficulty_entry_3` FROM  `creature_template` WHERE  `entry`IN ( 37697,37562)

UPDATE `creature_template` SET `mechanic_immune_mask` = `mechanic_immune_mask`|1|2|4|8|16|32|64|128|256|512|1024|2048|4096|8192|65536|131072|524288|1048576|4194304|8388608|33554432|67108864|536870912 WHERE `entry` IN 
(35144,35511,35512,35513,  -- Acidmaw
 34799,35514,35515,35516,  -- Dreadscale
 34797,35447,35558,35449,  -- Icehowl
 34813,35265,35266,35267,  -- Infernal Volcano
 34825,35278,35279,35280,  -- Nether Portal
 34497,35350,35351,35352,  -- Fjola Lightbane
 34496,35347,35348,35349,  -- Eydis Darkbane
 34564,34566,35615,35616); -- Anubarak

UPDATE `creature_template` SET `mechanic_immune_mask` = `mechanic_immune_mask`|1|2|8|16|32|64|128|256|512|1024|2048|4096|8192|65536|131072|524288|1048576|4194304|8388608|33554432|67108864|536870912 WHERE `entry` IN 
(34796,35438,35439,35440); -- Gormok

UPDATE `creature_template` SET `mechanic_immune_mask` = `mechanic_immune_mask`|1|2|4|8|16|32|64|128|256|512|1024|2048|4096|8192|65536|131072|524288|1048576|4194304|8388608|67108864|536870912 WHERE `entry` IN 
(34780,35216,35268,35269); -- Jaraxxus