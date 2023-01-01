--
UPDATE `event_scripts` SET `datalong2` = 120000, `x` = 2767.8684, `y` = 3213.0312, `z` = 150.82367, `o` = 4.059925079345703125, `Comment` = "Event (Spell 'Summon Ekkorash' (34992)) - On Event - Summon Creature 'Ekkorash the Inquisitor'" WHERE `id` = 13008;
UPDATE `creature_model_info` SET `BoundingRadius` = 0.6, `CombatReach` = 2 WHERE `DisplayID` = 19525;
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 19493;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 19493 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(19493,0,0,0,54,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Ekkorash the Inquisitor - On Just Summoned - Say Line 0"),
(19493,0,1,0,54,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Ekkorash the Inquisitor - On Just Summoned - Start Attack Summoner"),
(19493,0,2,0,0,0,100,0,15000,20000,15000,20000,0,11,11980,32,0,0,0,0,2,0,0,0,0,0,0,0,0,"Ekkorash the Inquisitor - In Combat - Cast 'Curse of Weakness'"),
(19493,0,3,0,0,0,100,0,8000,11000,18000,23000,0,11,36040,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Ekkorash the Inquisitor - In Combat - Cast 'Fel Flamestrike'");

DELETE FROM `creature_text` WHERE `CreatureID` = 19493;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(19493,0,0,"I told you only to summon me if that stupid elf returned! What's this? No matter, you won't detain me long.",12,0,100,0,0,0,17887,0,"Ekkorash the Inquisitor");
