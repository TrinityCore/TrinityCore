-- Remove bleed immunity from some npc
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`&~16384 WHERE `entry` IN (
36, -- Harvest Golem
114, -- Harvest Watcher
32471, -- Griegen
32495, -- Hildana Deathstealer
32501, -- High Thane Jorfus
19166, -- Tempest-Forge Patroller
20040, -- Crystalcore Devastator
20041, -- Crystalcore Sentinel
4952, -- Theramore Combat Dummy
4957); -- Theramore Combat Dummy 4
