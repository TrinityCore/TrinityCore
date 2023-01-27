-- Т.к. разработчики YTDB не удосужились добавить этот комить, оло работает хз как. так же пришлось перезалить некоторые комиты касательно спавна на тринити.
-- Проблема в основном в фазах.

-- Уаляю обьекты которые спавнятся сами
DELETE FROM `gameobject` WHERE `id` IN (
-- Wall (Not spawned in db)
190219, 190220, 191795, 191796, 191799, 191800, 191801, 191802, 191803, 191804, 191806, 191807, 191808, 191809, 190369, 190370, 190371, 190372, 190374, 190376,
-- Tower of keep (Not spawned in db)
190221, 190373, 190377, 190378,
-- Wall (with passage) (Not spawned in db)
191797, 191798, 191805,
-- South tower (Not spawned in db)
190356, 190357, 190358,
-- Door of forteress (Not spawned in db) GO_WINTERGRASP_FORTRESS_GATE
190375,
-- Last door (Not spawned in db) GO_WINTERGRASP_VAULT_GATE
191810,
-- Колизия
194162, 194323,
-- GO_WINTERGRASP_TITAN_S_RELIC
192829
);
DELETE FROM creature WHERE id in (
30739, 30740, 15214,
31102, 32296, 31101, 39173, 31091, 31151, 31106, 31053, 31107,
31052, 32294, 31051, 39172, 31036, 31153, 31108, 31054, 31109,
28366,28366
);

-- Wintergrasp trash
UPDATE creature SET phaseMask = 256 WHERE id in (30875, 30873, 30872, 30877, 30876, 30849);

--
UPDATE gameobject SET phaseMask = 49 WHERE id in (192032, 192033, 192031, 192029, 192028, 192030);

-- Эти спелы уже используются в этой таблице, по этой причине нужно добавить их в нажу зону, иначе они не будут применяться
DELETE FROM `spell_area` WHERE area = 4197 AND `spell` in (55773, 55774, 56618, 56617, 64576);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES
('55773', '4197', '0', '0', '0', '0', '2', '0', '0', '0'),
('55774', '4197', '0', '0', '0', '0', '2', '0', '0', '0'), 
('64576', '4197', '0', '0', '0', '0', '2', '0', '0', '0');

INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES
(56618, 4538, 0, 0, 0, 0, 2, 1, 64, 11),
(56618, 4539, 0, 0, 0, 0, 2, 1, 64, 11),
(56618, 4611, 0, 0, 0, 0, 2, 1, 64, 11),
(56618, 4612, 0, 0, 0, 0, 2, 1, 64, 11);

INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES
(56617, 4538, 0, 0, 0, 0, 2, 1, 64, 11),
(56617, 4539, 0, 0, 0, 0, 2, 1, 64, 11),
(56617, 4611, 0, 0, 0, 0, 2, 1, 64, 11),
(56617, 4612, 0, 0, 0, 0, 2, 1, 64, 11);
-- SpiritGUides
UPDATE `creature_template` SET faction_H = 83, faction_A = 83, `npcflag` =  '32769', `unit_flags` =  '2147484480', `flags_extra` =  '0' WHERE `entry` in (31841, 31842);
UPDATE `creature_template` SET faction_H = 83, faction_A = 84 WHERE entry = 31842; -- Должен быть такой

-- имммун машинам.
UPDATE `creature_template` SET  `mechanic_immune_mask` =  '888111103' WHERE `entry` =27881;

-- Issue 8054: wintergrasp Tower Cannon
UPDATE `creature_template` SET `unit_flags`=32772 WHERE `entry`=28366;