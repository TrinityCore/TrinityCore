-- spawn
DELETE FROM `creature` WHERE `id` in (35999, 67378, 37676, 49131);

-- quest aura
DELETE FROM `spell_area` WHERE `spell` = 67435 AND area = 4768;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
('67435', '4768', '14123', '0', '0', '0', '2', '1', '10', '11');

-- q14109 spell phase(59073)
UPDATE `quest_template` SET `RewardSpell` = '0' WHERE `Id` = 14109;

-- q14113/14153 spell phase 59074
DELETE  FROM `quest_start_scripts` WHERE `id` = 43 AND datalong = 66908;
UPDATE `quest_template` SET `RewardSpell` = '0' WHERE `Id` in (14113,14153);
DELETE FROM `spell_area` WHERE `spell` in (59073, 66908) AND area = 4765;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
('59073', '4765', '14113', '0', '0', '0', '2', '1', '10', '11'),
('59073', '4765', '14153', '0', '0', '0', '2', '1', '10', '11'),
('66908', '4765', '14113', '0', '0', '0', '2', '1', '10', '11'),
('66908', '4765', '14153', '0', '0', '0', '2', '1', '10', '11');