-- Instance: Scholomance
-- Achiev: Sanguinarian
update creature_template set ScriptName = 'npc_krastinovian_carver' where entry = 59368;

delete from conditions where SourceTypeOrReferenceId = 13 and SourceEntry = 114148;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 114148, 0, 0, 31, 0, 3, 59368, 0, 0, 0, '', NULL);

delete from spell_script_names where spell_id = 114148;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(114148, 'spell_boiling_bloodthirst');

-- Instance: Temple of the Jade Serpent
-- Achiev: Seeds of Doubt
delete from spell_linked_spell where spell_trigger in (123916, -123916);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `caster`, `target`, `hastalent`, `hastalent2`, `chance`, `cooldown`, `type2`, `hitmask`, `learnspell`, `removeMask`, `comment`) VALUES 
(-123916, -123944, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Remove Seed of Doubt'),
(123916, 123944, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Add Seed of Doubt');

-- Instance: Stormstout Brewery
-- Achiev: Ling-Ting's Herbal Journey
update creature_template set iconname = 'openhand', npcflag = 16777216, scriptName = 'npc_golden_hopling' where entry = 59824;

delete from creature_template_addon where entry = 59824;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(59824, 0, 0, 0, 1, 0, '116320');

delete from npc_spellclick_spells where npc_entry = 59824;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES 
(59824, 68742, 1, 0);

delete from achievement_reward where entry = 6402;
INSERT INTO `achievement_reward` (`entry`, `title_A`, `title_H`, `learnSpell`, `item`, `sender`, `subject`, `text`, `ScriptName`) VALUES 
(6402, 0, 0, 0, 86562, 59822, 'I have something for you there!', 'Hello there dear!\r\n\r\nThis little guy was scratching at the door after you left. I think he\'s taken quite a liking to you.\r\n\r\nDo come visit the brewery again some time. I just made more cookies!\r\n\r\n--Auntie Stormstout', '');

delete from locales_achievement_reward where entry = 6402;
INSERT INTO `locales_achievement_reward` (`entry`, `subject_loc8`, `text_loc8`) VALUES 
(6402, 'У меня для тебя кое-что есть!', 'Привет, дорогуша!\r\n\r\nКогда ты уехал, этот малыш места себе не находил, все скребся в дверь и смотрел на дорогу. Похоже, он к тебе привязался!\r\n\r\nПриезжай на Пивоварню в любое время, я как раз испекла еще печений! \r\n\r\nТетушка Буйный Портер');

DELETE FROM creature WHERE id = 59824;
INSERT INTO `creature` (`id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(59824, 961, 262, 2, -702.3351, 1088.125, 147.281, 4.371929, 7200, 0, 0),
(59824, 961, 262, 2, -735.8542, 1359.377, 119.1935, 2.533171, 7200, 0, 0), 
(59824, 961, 262, 2, -774.3055, 1364.851, 119.1984, 5.913837, 7200, 0, 0), 
(59824, 961, 262, 2, -703.4583, 1162.688, 166.2248, 0.3300541, 7200, 0, 0),
(59824, 961, 262, 2, -795.2136, 1409.252, 126.8822, 4.406052, 7200, 0, 0), 
(59824, 961, 262, 2, -778.691, 1335.87, 163.0314, 5.548455, 7200, 0, 0),
(59824, 961, 262, 2, -763.2413, 1432.13, 139.6627, 4.663653, 7200, 0, 0),
(59824, 961, 262, 2, -739.3038, 1331.889, 119.6079, 1.995667, 7200, 0, 0), 
(59824, 961, 262, 2, -697.2465, 1135.785, 139.2102, 2.564154, 7200, 0, 0), 
(59824, 961, 262, 2, -732.5295, 1285.599, 116.3787, 5.288466, 7200, 0, 0), 
(59824, 961, 262, 2, -657.4879, 1153.031, 166.8036, 2.421127, 7200, 0, 0), 
(59824, 961, 262, 2, -737.868, 1388.668, 146.7875, 4.110898, 7200, 0, 0),
(59824, 961, 262, 2, -791.7014, 1347.113, 147.6496, 5.817901, 7200, 0, 0), 
(59824, 961, 262, 2, -626.7552, 1199.292, 139.2381, 3.835662, 7200, 0, 0), 
(59824, 961, 262, 2, -702.3941, 1187.082, 139.2443, 5.474517, 7200, 0, 0), 
(59824, 961, 262, 2, -777.1858, 1276.661, 146.772, 5.631907, 7200, 0, 0),
(59824, 961, 262, 2, -748.9132, 1288.259, 116.1868, 2.010789, 7200, 0, 0), 
(59824, 961, 262, 2, -781.658, 1399.847, 126.8927, 3.877881, 7200, 0, 0),
(59824, 961, 262, 2, -791.0486, 1366.351, 119.1984, 6.024597, 7200, 0, 0), 
(59824, 961, 262, 2, -647.3542, 1242.648, 154.8862, 2.153525, 7200, 0, 0), 
(59824, 961, 262, 2, -778.5174, 1409.75, 139.6627, 6.137878, 7200, 0, 0),
(59824, 961, 262, 2, -762.3768, 1334.431, 119.1893, 0.5593464, 7200, 0, 0),
(59824, 961, 262, 2, -722.5695, 1275.991, 116.1913, 3.405236, 7200, 0, 0), 
(59824, 961, 262, 2, -748.868, 1133.599, 167.4304, 0.9915923, 7200, 0, 0), 
(59824, 961, 262, 2, -698.6389, 1320.543, 162.7709, 2.908736, 7200, 0, 0), 
(59824, 961, 262, 2, -743.4479, 1373.849, 119.1935, 5.522852, 7200, 0, 0), 
(59824, 961, 262, 2, -703.9271, 1206.064, 167.4732, 0.7137655, 7200, 0, 0),
(59824, 961, 262, 2, -791.408, 1272.825, 146.7646, 3.196976, 7200, 0, 0),
(59824, 961, 262, 2, -722.2535, 1322.733, 146.7039, 4.979095, 7200, 0, 0), 
(59824, 961, 262, 2, -758.7239, 1165.62, 139.1972, 5.749815, 7200, 0, 0);
