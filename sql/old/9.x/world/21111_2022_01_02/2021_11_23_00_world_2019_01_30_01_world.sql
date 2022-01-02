-- Gjalerbron Sleep-Watcher (23989)
DELETE FROM `creature_text` WHERE `CreatureID`=23989;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(23989,0,0,"For Ymiron!",12,0,100,0,0,0,22697,0,'Gjalerbron Sleep-Watcher'),
(23989,0,1,"My life for Ymiron!",12,0,100,0,0,0,22702,0,'Gjalerbron Sleep-Watcher'),
(23989,0,2,"You tiny creatures disgust me!",12,0,100,0,0,0,22816,0,'Gjalerbron Sleep-Watcher'),
(23989,0,3,"Look what''s come to play.",12,0,100,0,0,0,22820,0,'Gjalerbron Sleep-Watcher'),
(23989,0,4,"There will be no everlasting life for you!",12,0,100,0,0,0,22822,0,'Gjalerbron Sleep-Watcher'),
(23989,0,5,"Your race is a disease upon the world!",12,0,100,0,0,0,22824,0,'Gjalerbron Sleep-Watcher'),
(23989,0,6,"I will break you!",12,0,100,0,0,0,22823,0,'Gjalerbron Sleep-Watcher'),
(23989,0,7,"YAAARRRGH!",12,0,100,0,0,0,22700,0,'Gjalerbron Sleep-Watcher'),
(23989,0,8,"I will take pleasure in gutting you!",12,0,100,0,0,13533,30498,0,'Gjalerbron Sleep-Watcher'),
(23989,0,9,"I will feed you to the dogs!",12,0,100,0,0,13534,30499,0,'Gjalerbron Sleep-Watcher'),
(23989,0,10,"Your entrails will make a fine necklace.",12,0,100,0,0,13535,30500,0,'Gjalerbron Sleep-Watcher'),
(23989,0,11,"Die, maggot!",12,0,100,0,0,13536,30501,0,'Gjalerbron Sleep-Watcher'),
(23989,0,12,"You come to die!",12,0,100,0,0,13537,30502,0,'Gjalerbron Sleep-Watcher'),
(23989,0,13,"I spit on you!",12,0,100,0,0,13538,30503,0,'Gjalerbron Sleep-Watcher'),
(23989,0,14,"Sniveling pig!",12,0,100,0,0,13539,30504,0,'Gjalerbron Sleep-Watcher'),
(23989,0,15,"Ugglin oo bjorr!",12,0,100,0,0,13540,30505,0,'Gjalerbron Sleep-Watcher'),
(23989,0,16,"Haraak foln!",12,0,100,0,0,13541,30506,0,'Gjalerbron Sleep-Watcher'),
(23989,0,17,"I'll eat your heart!",12,0,100,0,0,13542,30508,0,'Gjalerbron Sleep-Watcher');

DELETE FROM `smart_scripts` WHERE `entryorguid`=23989 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23989,0,2,0,0,0,100,0,8000,10000,18000,22000,0,11,15970,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Gjalerbron Sleep-Watcher - In Combat - Cast 'Sleep'");

-- Gjalerbron Rune-Caster (23990)
DELETE FROM `creature_text` WHERE `CreatureID`=23990;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(23990,0,0,"For Ymiron!",12,0,100,0,0,0,22697,0,'Gjalerbron Rune-Caster'),
(23990,0,1,"My life for Ymiron!",12,0,100,0,0,0,22702,0,'Gjalerbron Rune-Caster'),
(23990,0,2,"You tiny creatures disgust me!",12,0,100,0,0,0,22816,0,'Gjalerbron Rune-Caster'),
(23990,0,3,"Look what''s come to play.",12,0,100,0,0,0,22820,0,'Gjalerbron Rune-Caster'),
(23990,0,4,"There will be no everlasting life for you!",12,0,100,0,0,0,22822,0,'Gjalerbron Rune-Caster'),
(23990,0,5,"Your race is a disease upon the world!",12,0,100,0,0,0,22824,0,'Gjalerbron Rune-Caster'),
(23990,0,6,"I will break you!",12,0,100,0,0,0,22823,0,'Gjalerbron Rune-Caster'),
(23990,0,7,"YAAARRRGH!",12,0,100,0,0,0,22700,0,'Gjalerbron Rune-Caster'),
(23990,0,8,"I will take pleasure in gutting you!",12,0,100,0,0,13533,30498,0,'Gjalerbron Rune-Caster'),
(23990,0,9,"I will feed you to the dogs!",12,0,100,0,0,13534,30499,0,'Gjalerbron Rune-Caster'),
(23990,0,10,"Your entrails will make a fine necklace.",12,0,100,0,0,13535,30500,0,'Gjalerbron Rune-Caster'),
(23990,0,11,"Die, maggot!",12,0,100,0,0,13536,30501,0,'Gjalerbron Rune-Caster'),
(23990,0,12,"You come to die!",12,0,100,0,0,13537,30502,0,'Gjalerbron Rune-Caster'),
(23990,0,13,"I spit on you!",12,0,100,0,0,13538,30503,0,'Gjalerbron Rune-Caster'),
(23990,0,14,"Sniveling pig!",12,0,100,0,0,13539,30504,0,'Gjalerbron Rune-Caster'),
(23990,0,15,"Ugglin oo bjorr!",12,0,100,0,0,13540,30505,0,'Gjalerbron Rune-Caster'),
(23990,0,16,"Haraak foln!",12,0,100,0,0,13541,30506,0,'Gjalerbron Rune-Caster'),
(23990,0,17,"I'll eat your heart!",12,0,100,0,0,13542,30508,0,'Gjalerbron Rune-Caster');

DELETE FROM `smart_scripts` WHERE `entryorguid`=23990 AND `source_type`=0 AND `id` IN (2,3,4);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23990,0,2,0,0,0,100,0,1000,3500,8000,15000,0,11,43453,33,0,0,0,0,1,0,0,0,0,0,0,0,0,"Gjalerbron Rune-Caster - In Combat - Cast 'Rune Ward'"),
(23990,0,3,0,0,0,100,0,500,500,3000,3000,0,11,9672,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Gjalerbron Rune-Caster - In Combat - Cast 'Frostbolt'"),
(23990,0,4,0,0,0,100,0,6000,8000,10000,12000,0,11,34787,1,0,0,0,0,2,0,0,0,0,0,0,0,0,"Gjalerbron Rune-Caster - In Combat - Cast 'Freezing Circle'");

-- Gjalerbron Warrior (23991)
DELETE FROM `smart_scripts` WHERE `entryorguid`=23991 AND `source_type`=0 AND `id` IN (2,3);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23991,0,2,0,0,0,100,0,4000,10000,35000,45000,0,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Gjalerbron Warrior - In Combat - Cast 'Demoralizing Shout'"),
(23991,0,3,0,0,0,100,0,7000,10000,17000,20000,0,11,10966,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Gjalerbron Warrior - In Combat - Cast 'Uppercut'");

DELETE FROM `creature_text` WHERE `CreatureID`=23991;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(23991,0,0,"For Ymiron!",12,0,100,0,0,0,22697,0,'Gjalerbron Warrior'),
(23991,0,1,"My life for Ymiron!",12,0,100,0,0,0,22702,0,'Gjalerbron Warrior'),
(23991,0,2,"You tiny creatures disgust me!",12,0,100,0,0,0,22816,0,'Gjalerbron Warrior'),
(23991,0,3,"Look what''s come to play.",12,0,100,0,0,0,22820,0,'Gjalerbron Warrior'),
(23991,0,4,"There will be no everlasting life for you!",12,0,100,0,0,0,22822,0,'Gjalerbron Warrior'),
(23991,0,5,"Your race is a disease upon the world!",12,0,100,0,0,0,22824,0,'Gjalerbron Warrior'),
(23991,0,6,"I will break you!",12,0,100,0,0,0,22823,0,'Gjalerbron Warrior'),
(23991,0,7,"YAAARRRGH!",12,0,100,0,0,0,22700,0,'Gjalerbron Warrior'),
(23991,0,8,"I will take pleasure in gutting you!",12,0,100,0,0,13533,30498,0,'Gjalerbron Warrior'),
(23991,0,9,"I will feed you to the dogs!",12,0,100,0,0,13534,30499,0,'Gjalerbron Warrior'),
(23991,0,10,"Your entrails will make a fine necklace.",12,0,100,0,0,13535,30500,0,'Gjalerbron Warrior'),
(23991,0,11,"Die, maggot!",12,0,100,0,0,13536,30501,0,'Gjalerbron Warrior'),
(23991,0,12,"You come to die!",12,0,100,0,0,13537,30502,0,'Gjalerbron Warrior'),
(23991,0,13,"I spit on you!",12,0,100,0,0,13538,30503,0,'Gjalerbron Warrior'),
(23991,0,14,"Sniveling pig!",12,0,100,0,0,13539,30504,0,'Gjalerbron Warrior'),
(23991,0,15,"Ugglin oo bjorr!",12,0,100,0,0,13540,30505,0,'Gjalerbron Warrior'),
(23991,0,16,"Haraak foln!",12,0,100,0,0,13541,30506,0,'Gjalerbron Warrior'),
(23991,0,17,"I'll eat your heart!",12,0,100,0,0,13542,30508,0,'Gjalerbron Warrior');

-- Fearsome Horror (24073)
DELETE FROM `smart_scripts` WHERE `entryorguid`=24073 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24073,0,1,0,0,0,100,0,2000,6000,7000,10000,0,11,49861,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Fearsome Horror - In Combat - Cast 'Infected Bite'");
