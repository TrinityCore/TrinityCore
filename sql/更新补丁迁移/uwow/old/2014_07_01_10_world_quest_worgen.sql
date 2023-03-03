-- After start quest 24904
DELETE FROM  `quest_end_scripts` WHERE  `id` =24902;
UPDATE `quest_template` SET `CompleteScript` = '0' WHERE `Id` = 24902;
DELETE FROM `spell_area` WHERE `spell` in (69486) AND area in (4755);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
('69486', '4755', '24904', '0', '0', '0', '2', '1', '74', '0');