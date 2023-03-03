delete from spell_loot_template where entry = 124281;
INSERT INTO `spell_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`, `shared`) VALUES 
(124281, 85592, 100, 1, 0, 1, 1, 0);

update creature_template set ScriptName = 'npc_professor_slate' where entry = 59613;

delete from spell_linked_spell where spell_trigger in (-114800,114800,124293,-124293,124294,-124294,124295,-124295);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `caster`, `target`, `hastalent`, `hastalent2`, `chance`, `cooldown`, `type2`, `hitmask`, `learnspell`, `removeMask`, `comment`) VALUES 
(-114800, -124934, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Remove Polyformic Acid Potion'),
(114800, 124934, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Add Polyformic Acid Potion'),
(-124293, -124934, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Remove Polyformic Acid Potion'),
(124293, 124934, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Add Polyformic Acid Potion'),
(-124294, -124934, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Remove Polyformic Acid Potion'),
(124294, 124934, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Add Polyformic Acid Potion'),
(-124295, -124934, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Remove Polyformic Acid Potion'),
(124295, 124934, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Add Polyformic Acid Potion');

delete from creature where id = 59613;
INSERT INTO `creature` (`id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `isActive`) VALUES 
(59613, 1007, 6066, 6066, 262, 1, 0, 0, 101.228, 80.2399, 100.941, 6.25399, 28800, 0, 0, 6500014, 30252, 0, 0, 0, 0, 0, 0);