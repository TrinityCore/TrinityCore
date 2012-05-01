DELETE FROM `creature_template` WHERE `entry` IN (99119, 99120, 99121, 99122);
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES
(99119, 0, 0, 0, 0, 0, 4877, 0, 0, 0, 'Мастер Чо', 'Mortal Kombat', NULL, 0, 80, 80, 0, 35, 35, 1, 1, 1.14286, 1.5, 0, 4, 5, 0, 30, 1, 2000, 0, 1, 0, 0, 0, 0, 0, 0, 0, 2, 3, 100, 7, 0, 38, 38, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 7, '', 1, 3, 1, 1, 1, 0, 752, 0, 0, 0, 0, 0, 100, 1, 0, 0, 0, 'mk_arena_master', NULL),
(99120, 0, 0, 0, 0, 0, 11686, 0, 0, 0, 'Damage Bonus', 'Increase Damage Done', NULL, 0, 80, 80, 0, 16, 16, 0, 1, 1.14286, 1, 0, 4, 5, 0, 30, 1, 2000, 0, 1, 0, 0, 0, 0, 0, 0, 0, 2, 3, 100, 7, 0, 38, 38, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 7, '', 1, 3, 1, 1, 1, 0, 752, 0, 0, 0, 0, 0, 100, 1, 0, 0, 0, 'npc_mk_bonus', NULL),
(99121, 0, 0, 0, 0, 0, 11686, 0, 0, 0, 'Mana Bonus', 'Increase Mana', NULL, 0, 80, 80, 0, 16, 16, 0, 1, 1.14286, 1, 0, 4, 5, 0, 30, 1, 2000, 0, 1, 0, 0, 0, 0, 0, 0, 0, 2, 3, 100, 7, 0, 38, 38, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 7, '', 1, 3, 1, 1, 1, 0, 752, 0, 0, 0, 0, 0, 100, 1, 0, 0, 0, 'npc_mk_bonus', NULL),
(99122, 0, 0, 0, 0, 0, 11686, 0, 0, 0, 'Health Bonus', 'Restore Health', NULL, 0, 80, 80, 0, 16, 16, 0, 1, 1.14286, 1, 0, 4, 5, 0, 30, 1, 2000, 0, 1, 0, 0, 0, 0, 0, 0, 0, 2, 3, 100, 7, 0, 38, 38, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 7, '', 1, 3, 1, 1, 1, 0, 752, 0, 0, 0, 0, 0, 100, 1, 0, 0, 0, 'npc_mk_bonus', NULL);

DELETE FROM `creature` WHERE `id` = '99119';
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(497805, 99119, 0, 1, 1, 0, 0, -13203.5, 275.29, 35, 4.24, 300, 0, 0, 5342, 0, 0, 0, 0, 0),
(497806, 99119, 0, 1, 1, 0, 0, -13217.3, 231.509, 37.1628, 1.39565, 300, 0, 0, 5342, 0, 0, 0, 6, 0);

-- MK Arena Teams
DELETE FROM `script_texts` WHERE `npc_entry`= 99119;
INSERT INTO `script_texts` (`npc_entry`, `entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`, `sound`, `type`, `language`, `emote`, `comment`) VALUES
(99119, -1500016, 'Отрекшиеся', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 1, 0, 0, 'MK Team 16'),
(99119, -1500015, 'Легион нубяшек', NULL, NULL, NULL, NULL, NULL, NULL, NULL, 'Легион нубяшек', 0, 1, 0, 0, 'MK Team 15'),
(99119, -1500014, 'Орден Тирисфальских лесов', NULL, NULL, NULL, NULL, NULL, NULL, NULL, 'Орден Тирисфальских лесов', 0, 1, 0, 0, 'MK Team 14'),
(99119, -1500013, 'Клан Черной горы', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 1, 0, 0, 'MK Team 13'),
(99119, -1500012, 'Клан Песни Войны', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 1, 0, 0, 'MK Team 12'),
(99119, -1500011, 'Лорды террора', NULL, NULL, NULL, NULL, NULL, NULL, NULL, 'Лорды террора', 0, 1, 0, 0, 'MK Team 11'),
(99119, -1500010, 'Клан Призрачной Луны', NULL, NULL, NULL, NULL, NULL, NULL, NULL, 'Клан Призрачной Луны', 0, 1, 0, 0, 'MK Team 10'),
(99119, -1500009, 'Маги из Кирин Тора', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 1, 0, 0, 'MK Team 9'),
(99119, -1500008, 'Воины из Лордерона', NULL, NULL, NULL, NULL, NULL, NULL, NULL, 'Воины Лордерона', 0, 1, 0, 0, 'MK Team 8'),
(99119, -1500007, 'Чернокнижники из Совета Теней', NULL, NULL, NULL, NULL, NULL, NULL, NULL, 'Чернокнижники Совета Теней', 0, 1, 0, 0, 'MK Team 7'),
(99119, -1500006, 'Рыцари смерти', NULL, NULL, NULL, NULL, NULL, NULL, NULL, 'Рыцари смерти', 0, 1, 0, 0, 'MK Team 6'),
(99119, -1500005, 'Совет Теней', NULL, NULL, NULL, NULL, NULL, NULL, NULL, 'Совет Теней', 0, 1, 0, 0, 'MK Team 5'),
(99119, -1500004, 'Орден Серебряной Длани', NULL, NULL, NULL, NULL, NULL, NULL, NULL, 'Орден Серебряной Длани', 0, 1, 0, 0, 'MK Team 4'),
(99119, -1500003, 'Альянс Лордерона', NULL, NULL, NULL, NULL, NULL, NULL, NULL, 'Альянс Лордерона', 0, 1, 0, 0, 'MK Team 3'),
(99119, -1500002, 'Пылающий Легион', NULL, NULL, NULL, NULL, NULL, NULL, NULL, 'Пылающий Легион', 0, 1, 0, 0, 'MK Team 2'),
(99119, -1500001, 'Братство Темной Гавани', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 1, 0, 0, 'MK Team 1'),
(99119, -1500000, 'Команда не найдена!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, 'Команда не найдена!', 0, 1, 0, 0, 'MK Team 0');
