-- Sniffed
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 27798;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (27244,27798) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN 2779800 AND 2779805 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(27244,0,0,0,0,0,100,0,5000,10000,5000,10000,0,11,32909,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Emerald Skytalon - In Combat - Cast 'Talon Strike'"),
(27244,0,1,0,6,0,100,0,0,0,0,0,0,11,49581,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Emerald Skytalon - On Death - Cast 'Circle of Life: Summon Reincarnated Skytalon'"),

(27798,0,0,1,54,0,100,0,0,0,0,0,0,88,2779800,2779805,0,0,0,0,1,0,0,0,0,0,0,0,0,"Reincarnated Skytalon - On Just Summoned - Run Random Script"),
(27798,0,1,2,61,0,100,0,0,0,0,0,0,89,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Reincarnated Skytalon - On Link - Start Random Movement"),
(27798,0,2,0,61,0,100,0,0,0,0,0,0,41,30000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Reincarnated Skytalon - On Link - Delayed Despawn"),

(2779800,9,0,0,0,0,100,0,0,0,0,0,0,75,49577,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Reincarnated Skytalon - On Script - Add Aura 'Circle of Life: Transform into Rabbit'"),
(2779801,9,0,0,0,0,100,0,0,0,0,0,0,75,49578,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Reincarnated Skytalon - On Script - Add Aura 'Circle of Life: Transform into Squirrel'"),
(2779802,9,0,0,0,0,100,0,0,0,0,0,0,75,49579,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Reincarnated Skytalon - On Script - Add Aura 'Circle of Life: Transform into Skunk'"),
(2779803,9,0,0,0,0,100,0,0,0,0,0,0,75,49580,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Reincarnated Skytalon - On Script - Add Aura 'Circle of Life: Transform into Prairie Dog'"),
(2779804,9,0,0,0,0,100,0,0,0,0,0,0,75,49582,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Reincarnated Skytalon - On Script - Add Aura 'Circle of Life: Transform into Fawn'"),
(2779805,9,0,0,0,0,100,0,0,0,0,0,0,75,49583,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Reincarnated Skytalon - On Script - Add Aura 'Circle of Life: Transform into Emerald Skytalon'");

UPDATE `serverside_spell` SET `ProcChance` = 101 WHERE `Id` = 49577; -- Circle of Life: Transform into Rabbit
UPDATE `serverside_spell` SET `ProcChance` = 101 WHERE `Id` = 49578; -- Circle of Life: Transform into Squirrel
UPDATE `serverside_spell` SET `ProcChance` = 101 WHERE `Id` = 49579; -- Circle of Life: Transform into Skunk
UPDATE `serverside_spell` SET `ProcChance` = 101 WHERE `Id` = 49580; -- Circle of Life: Transform into Prairie Dog
UPDATE `serverside_spell` SET `ProcChance` = 101 WHERE `Id` = 49582; -- Circle of Life: Transform into Fawn
UPDATE `serverside_spell` SET `ProcChance` = 101 WHERE `Id` = 49583; -- Circle of Life: Transform into Emerald Skytalon

DELETE FROM `serverside_spell_effect` WHERE `SpellID` IN (49577,49578,49579,49580,49582,49583);
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `Effect`, `EffectAura`, `EffectMiscValue1`, `ImplicitTarget1`) VALUES
(49577, 0, 6, 56, 721, 1),
(49578, 0, 6, 56, 1412, 1),
(49579, 0, 6, 56, 17467, 1),
(49580, 0, 6, 56, 2620, 1),
(49582, 0, 6, 56, 890, 1),
(49583, 0, 6, 56, 27244, 1);
