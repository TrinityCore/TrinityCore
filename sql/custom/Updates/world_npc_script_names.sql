-- Here are some custom world events, mobs, quest, etc.
-- Argent tournament
--  npc_squire_danny
UPDATE `creature_template` SET `KillCredit1` = 33708 WHERE `entry` = 33707;
UPDATE `creature_template` SET `ScriptName` = 'npc_squire_danny' WHERE `entry` = 33518;
-- npc_argent_champion
UPDATE `creature_template` SET `ScriptName` = 'npc_argent_champion' WHERE `entry` = 33707;
-- npc_ring_champions
UPDATE `creature_template` SET `ScriptName` = 'npc_ring_champions' WHERE `entry` IN (33738,33746,33747,33743,33740,33748,33744,33745,33749,33739);
-- npc_ring_valiants
UPDATE `creature_template` SET `flags_extra` = 0, `AIName` = '', `ScriptName` = 'npc_ring_valiants' WHERE `entry` IN (33384,33306,33285,33382,33383,33558,33564,33561,33562,33559);

-- npc_spring_rabbit for achievement Spring Fling
UPDATE `creature_template` SET `ScriptName` = 'npc_spring_rabbit' WHERE `entry` = 32791;

-- npc_lake_frog
UPDATE `creature_template` SET `ScriptName` = 'npc_lake_frog' WHERE `entry` IN (33211,33224);

