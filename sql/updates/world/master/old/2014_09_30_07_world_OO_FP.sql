UPDATE `creature` SET `modelid` = '1126', `unit_flags` = '33555200' WHERE id = 71683;

-- poison remove at apply
DELETE FROM `spell_scripts` WHERE id in (143225, 143210);
INSERT INTO `spell_scripts` (`id`, `effIndex`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
('143225', '2', '0', '14', '143210', '1', '0', '0', '0', '0', '0'),
('143210', '2', '0', '14', '143225', '1', '0', '0', '0', '0', '0');

-- gouge
REPLACE INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('143301', 'spell_OO_gouge');

-- garrote
DELETE FROM `spell_area` WHERE `spell` = 143198;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
('143198', '6738', '0', '0', '0', '0', '2', '0', '0', '0');

--
UPDATE `creature_template_addon` SET `auras` = '142872 18950' WHERE `entry` in (71475, 71479, 71480);
UPDATE `creature_template` SET `unit_flags2` = '2048' WHERE `creature_template`.`entry` = 71479; -- 2099200
