delete from creature where id in (56160, 71982);
delete from creature where id = 71992;
INSERT INTO `creature` (`id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `isActive`) VALUES 
(71992, 974, 5861, 5861, 1, 1, 0, 0, -3872.23, 6531.77, 17.8533, 3.72523, 3300, 0, 0, 174454800, 1000, 0, 0, 0, 0, 0, 0);

update creature_template set speed_walk = 2, speed_run = 2, dmg_multiplier = 200, ScriptName = 'boss_darkmoon_moonfang_mother', mechanic_immune_mask = 650854399, flags_extra = 512 where entry = 71992;

update creature_template set AIName = 'SmartAI' where entry = 72038;
delete from smart_scripts where entryorguid = 72038;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(72038, 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 0, 0, 49, 0, 0, 0, 0, 0, 0, 18, 40, 0, 0, 0, 0, 0, 0, 'Just Summon - Attack Start'),
(72038, 0, 1, 0, 0, 0, 100, 0, 9000, 9000, 9000, 9000, 11, 144519, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cast Crippling Bite');

delete from creature_template_addon where entry = 71992;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(71992, 0, 0, 0, 1, 0, '144501');

delete from spell_target_filter where spellId = 144702;
INSERT INTO `spell_target_filter` (`spellId`, `targetId`, `option`, `param1`, `param2`, `param3`, `aura`, `chance`, `effectMask`, `resizeType`, `count`, `maxcount`, `addcount`, `addcaster`, `comments`) VALUES 
(144702, 15, 0, 0, 0, 0, 0, 0, 7, 2, 1, 0, 0, 0, 'Moonfang\'s Tears');

delete from spell_trigger_dummy where spell_id = 144702;
INSERT INTO `spell_trigger_dummy` (`spell_id`, `spell_trigger`, `option`, `target`, `caster`, `targetaura`, `bp0`, `bp1`, `bp2`, `effectmask`, `aura`, `chance`, `group`, `check_spell_id`, `comment`) VALUES 
(144702, 144579, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 'Moonfang\'s Tears');

delete from creature_text where entry = 71992;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES 
(71992, 0, 0, '|Cffff0000BEWARE:|r Moonfang Snarler now prowl the woods!', 41, 0, 0, 0, 0, 0, ''),
(71992, 1, 0, '|Cffff0000BEWARE:|r Moonfang Dreadhowls now prowl the woods!', 41, 0, 0, 0, 0, 0, ''),
(71992, 2, 0, '|Cffff0000BEWARE:|r Den Mother Moonfang has appeared in the woods!', 41, 0, 0, 0, 0, 0, '');

delete from locales_creature_text where entry = 71992;
INSERT INTO `locales_creature_text` (`entry`, `textGroup`, `id`, `text_loc8`) VALUES 
(71992, 0, 0, '|Cffff0000ОСТОРОЖНО:|r Рычуны Лунной волчицы рыщут по лесу!'),
(71992, 1, 0, '|Cffff0000ОСТОРОЖНО:|r Завыватели Лунной волчицы рыщут по лесу!'),
(71992, 2, 0, '|Cffff0000ОСТОРОЖНО:|r В лесу появилась мать стаи Лунная волчица!');

delete from creature_loot_template where entry = 71992;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`, `shared`) VALUES 
(71992, 81194, 50, 0, 0, 2, 4, 0),
(71992, 81212, 50, 0, 0, 2, 4, 0),
(71992, 101570, 10, 0, 0, 1, 1, 0),
(71992, 101571, 10, 0, 0, 1, 1, 0),
(71992, 101675, 10, 0, 0, 1, 1, 0),
(71992, 105891, 50, 0, 0, 1, 1, 0),
(71992, 105898, 10, 0, 0, 1, 1, 0);