DELETE FROM `spell_area` WHERE `spell` IN(52214,50735);

INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
(52214, 3711, 12572, 12572, 0, 0, 2, 1, 74, 11), -- Gods Like Shiny Things 
(52214, 3711, 12704, 12704, 0, 0, 2, 1, 74, 11), -- Appeasing the Great Rainstone 
(50735, 3711, 12532, 12532, 0, 0, 2, 1, 74, 11), -- Flown the Coop! 
(50735, 3711, 12702, 12702, 0, 0, 2, 1, 74, 11); -- Chicken Party! 

DELETE FROM `smart_scripts` WHERE  `entryorguid`=28138 AND `source_type`=0 AND `id`=3 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=28138 AND `source_type`=0 AND `id`=1 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=28138 AND `source_type`=0 AND `id`=2 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=28138 AND `source_type`=0 AND `id`=0 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=28027 AND `source_type`=0 AND `id`=9 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=28027 AND `source_type`=0 AND `id`=10 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=28027 AND `source_type`=0 AND `id`=11 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=28120 AND `source_type`=0 AND `id`=13 AND `link`=0;

UPDATE `smart_scripts` SET `event_flags`=0 WHERE  `entryorguid` IN(28214,28215,28216, 28120, 28121,28122,28362) AND `source_type`=0;
UPDATE `smart_scripts` SET `event_param3`=60000, `event_param4`=60000 WHERE  `entryorguid`=28362 AND `source_type`=0 AND `id`=0 AND `link`=0;

