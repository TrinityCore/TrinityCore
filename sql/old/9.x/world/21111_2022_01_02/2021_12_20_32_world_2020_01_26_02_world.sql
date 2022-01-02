UPDATE `creature_template` SET `unit_flags`=536903744, `flags_extra`=0 WHERE `entry`IN (21303,21304,21592,21623);
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`IN (21303,21304);
UPDATE `creature_template_addon` SET `auras`='31261' WHERE  `entry` IN (21303,21304,21592,21623);
UPDATE `creature_template_addon` SET `auras`='29266' WHERE  `entry` IN (21962);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(21303,21304,21395) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(2130400) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(21304, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 0, 80, 2130400, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Warder Corpse - On Aggro - Action list'),
(21303, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 0, 80, 2130400, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Defender Corpse - On Aggro - Action list'),
(21304, 0, 1, 0, 10, 0, 100, 1, 0, 8, 0, 0, 0, 80, 2130400, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Warder Corpse - Ooc los - Action list'),
(21303, 0, 1, 0, 10, 0, 100, 1, 0, 8, 0, 0, 0, 80, 2130400, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Defender Corpse - Ooc los - Action list'),
(2130400, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 11, 36599, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Warder Corpse - Action list - Cast Spell Bloody Explosion'),
(2130400, 9, 1, 0, 0, 0, 100, 0, 100, 100, 0, 0, 0, 11, 36593, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Warder Corpse - Action list - Cast Spell Corpse Burst'),
(2130400, 9, 2, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Warder Corpse - Action list - Despawn'),
(21395, 0, 0, 0, 0, 0, 100, 0, 2000, 4000, 3000, 5000, 0, 11, 36796, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Protean Spawn - In Combat - Cast Acidic Bite'),
(21395, 0, 1, 2, 54, 0, 100, 0, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 40, 0, 0, 0, 0, 0, 0, 0, 'Protean Spawn - on just summoned - Attack'),
(21395, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 11, 36588, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Protean Spawn - on just summoned - cast Bloody Explosion');
