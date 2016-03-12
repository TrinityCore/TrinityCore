-- UPDATE `spell_dbc` SET `Effect1`=28,`EffectMiscValueB1`=64 WHERE  `Id`  IN(38922,38928);
UPDATE `spelleffect_dbc` SET `Effect`=28,`EffectMiscValueB`=64 WHERE `EffectSpellId` IN(38922,38928);

DELETE FROM `smart_scripts` WHERE `entryorguid`=21251 AND `source_type`=0 AND `id`>6;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(2125100,2125101,2125102,2125103) AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(21251, 0, 7, 0, 11, 0, 100, 0, 0, 0, 0, 0, 42, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Underbog Colossus - On Spawn - Set Invincibility HP'),
(21251, 0, 8, 0, 2, 0, 100, 1, 0, 1, 0, 0, 87, 2125100, 2125101, 2125102, 2125103, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Underbog Colossus - On Less than 1% HP - Run Random Script'),
(2125100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 38718, 3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Underbog Colossus - Script 1 - Cast \'Toxic Pool\' '),
(2125100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 37, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Underbog Colossus - Script 1 - Die'),
(2125101, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 38922, 3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Underbog Colossus - Script 2 - Cast \'Summon Colossus Lurkers\' '),
(2125101, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 37, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Underbog Colossus - Script 2 - Die'),
(2125102, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 38928, 3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Underbog Colossus - Script 3 - Cast \'Summon Colossus Ragers\' '),
(2125102, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 37, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Underbog Colossus - Script 3 - Die'),
(2125103, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 37, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Underbog Colossus - Script 4 - Die');
