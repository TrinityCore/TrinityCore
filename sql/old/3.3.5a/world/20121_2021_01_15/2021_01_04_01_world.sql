--
UPDATE `creature_model_info` SET `BoundingRadius` = 0.24894997, `CombatReach` = 0.97499996 WHERE `DisplayID` = 19271;
UPDATE `creature_template` SET `speed_walk` = 1, `unit_flags` = 64 WHERE `entry` = 19938;

DELETE FROM `creature_template_movement` WHERE `CreatureId` = 19938;
INSERT INTO `creature_template_movement` (`CreatureId`,`Ground`,`Swim`,`Flight`,`Rooted`,`Chase`,`Random`) VALUES
(19938,1,1,1,0,0,0);

DELETE FROM `event_scripts` WHERE `id` = 12857;
INSERT INTO `event_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`,`Comment`) VALUES
(12857,0,10,19938,10000,0,2248.316,2228.0325,138.87404,1.710422635078430175,"Event (Spell 'Scrying Spell' (34717)) - On Event - Summon Creature 'Image of Commander Sarannis'"),
(12857,0,9,30029,10,0,0,0,0,0,"Event (Spell 'Scrying Spell' (34717)) - On Event - Respawn Gameobject 'Scrying Aura'");

DELETE FROM `gameobject` WHERE `guid` = 30029 AND `id` = 184119;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(30029, 184119, 530, 1, 1, 2248.22705078125, 2228.125, 137.0018463134765625, -2.14675283432006835, 0, 0, -0.87881660461425781, 0.477159708738327026, -1, 255, 1, 14007);

-- Image of Commander Sarannis SAI
SET @ID := 19938;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID*100+0 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,54,0,100,0,0,0,0,0,0,80,@ID*100+0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Image of Commander Sarannis - On Just Summoned - Run Script"),

(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Image of Commander Sarannis - On Script - Say Line 0"),
(@ID*100+0,9,1,0,0,0,100,0,5000,5000,0,0,0,1,1,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Image of Commander Sarannis - On Script - Say Line 1"),
(@ID*100+0,9,2,0,0,0,100,0,0,0,0,0,0,33,19938,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Image of Commander Sarannis - On Script - Quest Credit 'Finding the Keymaster'");

DELETE FROM `creature_text` WHERE `CreatureID` = 19938;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(19938,0,0,"A flickering image of a female blood elf commander appears. From the surroundings, you can tell she must be inside Tempest Keep.",16,0,100,1,0,0,17529,0,"Image of Commander Sarannis"),
(19938,1,0,"The blood elf doesn't appear to be a magister, but perhaps she holds something that is the key to the tower's curse.",16,0,100,25,0,0,17530,0,"Image of Commander Sarannis");
