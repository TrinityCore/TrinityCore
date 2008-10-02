-- revert to original specialflags + flag 4 for mangos support, script no longer needed for quest
UPDATE `quest_template` SET `SpecialFlags`= 140 WHERE `entry` IN (10040, 10041);
UPDATE `creature_template` SET `ScriptName` = '' WHERE `entry` IN (18716, 18717, 18719);
-- gossip only, key to searing gorge discussion
UPDATE `creature_template` SET `ScriptName` = 'npc_mountaineer_pebblebitty' WHERE `entry` = 3836;
