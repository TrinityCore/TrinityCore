-- Sniffed, reset timer guessed but should be 2 min or more (nothing happened after almost 2 min in sniff)
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 30406;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 30406 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 3040600 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(30406,0,0,0,64,0,100,0,0,0,0,0,0,80,3040600,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bethod Feigr - On Gossip Hello - Run Script"),

(3040600,9,0,0,0,0,100,0,0,0,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bethod Feigr - On Script - Remove Flag Standstate Kneel"),
(3040600,9,1,0,0,0,100,0,2000,2000,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Bethod Feigr - On Script - Set Orientation Invoker"),
(3040600,9,2,0,0,0,100,0,118000,118000,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bethod Feigr - On Script - Set Flag Standstate Kneel"),
(3040600,9,3,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bethod Feigr - On Script - Set Orientation Home Position");

-- Valhalas Vargul SAI
SET @ID := 30250;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,4,0,50,0,0,0,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Valhalas Vargul - On Aggro - Say Line 0"),
(@ID,0,1,0,0,0,100,0,5000,10000,5000,10000,0,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Valhalas Vargul - In Combat - Cast 'Cleave'"),
(@ID,0,2,0,6,0,100,0,0,0,0,0,0,33,30644,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Valhalas Vargul - On Death - Quest Credit 'The Art of Being a Water Terror'");

UPDATE `conditions` SET `SourceGroup` = 3 WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 30250 AND `SourceId` = 0;

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"I will take pleasure in gutting you!",12,0,100,0,0,13533,30498,0,"Valhalas Vargul"),
(@ID,0,1,"I will feed you to the dogs!",12,0,100,0,0,13534,30499,0,"Valhalas Vargul"),
(@ID,0,2,"Your entrails will make a fine necklace.",12,0,100,0,0,13535,30500,0,"Valhalas Vargul"),
(@ID,0,3,"Die, maggot!",12,0,100,0,0,13536,30501,0,"Valhalas Vargul"),
(@ID,0,4,"You come to die!",12,0,100,0,0,13537,30502,0,"Valhalas Vargul"),
(@ID,0,5,"I spit on you!",12,0,100,0,0,13538,30503,0,"Valhalas Vargul"),
(@ID,0,6,"Sniveling pig!",12,0,100,0,0,13539,30504,0,"Valhalas Vargul"),
(@ID,0,7,"Ugglin oo bjorr!",12,0,100,0,0,13540,30505,0,"Valhalas Vargul"),
(@ID,0,8,"Haraak foln!",12,0,100,0,0,13541,30506,0,"Valhalas Vargul"),
(@ID,0,9,"I'll eat your heart!",12,0,100,0,0,13542,30508,0,"Valhalas Vargul");

UPDATE `creature` SET `wander_distance` = 10 WHERE `id` = 30250;
UPDATE `creature` SET `position_x` = 8006.36, `position_y` = 3216.27, `position_z` = 676.195, `orientation` = 3.12414 WHERE `guid` = 121576 AND `id` = 30250;
UPDATE `creature` SET `position_x` = 7958.95, `position_y` = 3261.44, `position_z` = 676.215, `orientation` = 2.46091 WHERE `guid` = 121577 AND `id` = 30250;
UPDATE `creature` SET `position_x` = 7908.82, `position_y` = 3310.99, `position_z` = 654.517, `orientation` = 3.38594 WHERE `guid` = 121578 AND `id` = 30250;
UPDATE `creature` SET `position_x` = 7946.04, `position_y` = 3288.08, `position_z` = 635.423, `orientation` = 4.83456 WHERE `guid` = 121580 AND `id` = 30250;
UPDATE `creature` SET `position_x` = 7986.23, `position_y` = 3296.16, `position_z` = 676.112, `orientation` = 3.91948 WHERE `guid` = 121572 AND `id` = 30250;
UPDATE `creature` SET `position_x` = 7918.7266, `position_y` = 3282.798, `position_z` = 646.3521, `wander_distance` = 0, `MovementType` = 2  WHERE `guid` = 121579 AND `id` = 30250;
UPDATE `creature` SET `wander_distance` = 0, `MovementType` = 0, `unit_flags` = 33587968 WHERE `guid` IN (121557,121545,121555,121549,121547,121550,121558,121563,121548,121544,121546,121556) AND `id` = 30250;

DELETE FROM `creature_addon` WHERE `guid` IN (121579);
INSERT INTO `creature_addon` (`guid`,`path_id`,`auras`) VALUES
(121579,1215790,"56035");

DELETE FROM `waypoint_data` WHERE `id` IN (1215790);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`) VALUES
(1215790,1,7918.7266,3282.798,646.3521),
(1215790,2,7929.69,3272.6643,636.9104),
(1215790,3,7942.2163,3264.7463,632.82355),
(1215790,4,7960.777,3269.438,632.81805),
(1215790,5,7972.6885,3281.974,633.5776),
(1215790,6,7960.777,3269.438,632.81805),
(1215790,7,7942.2163,3264.7463,632.82355),
(1215790,8,7929.8706,3272.4973,636.6773),
(1215790,9,7918.7266,3282.798,646.3521),
(1215790,10,7911.637,3292.9324,654.0225),
(1215790,11,7907.886,3303.795,654.4317),
(1215790,12,7918.481,3313.1116,654.3943),
(1215790,13,7927.686,3309.8938,655.3848),
(1215790,14,7940.56,3299.7756,665.7858),
(1215790,15,7947.455,3288.8455,673.6148),
(1215790,16,7952.213,3274.217,676.14166),
(1215790,17,7950.3804,3261.8418,676.1222),
(1215790,18,7940.184,3247.77,676.13074),
(1215790,19,7950.3804,3261.8418,676.1222),
(1215790,20,7952.213,3274.217,676.14166),
(1215790,21,7947.455,3288.8455,673.6148),
(1215790,22,7940.621,3299.6792,665.8459),
(1215790,23,7927.686,3309.8938,655.3848),
(1215790,24,7918.481,3313.1116,654.3943),
(1215790,25,7907.886,3303.795,654.4317),
(1215790,26,7911.563,3293.1467,654.1227);

DELETE FROM `creature_template_addon` WHERE `entry` = 30250;
INSERT INTO `creature_template_addon` (`entry`,`auras`) VALUES
(30250,"56035");
DELETE FROM `creature_addon` WHERE `guid` IN (121557,121545,121555,121549,121547,121550,121558,121563,121548,121544,121546,121556);
INSERT INTO `creature_addon` (`guid`,`auras`) VALUES
(121557,"29266 56035"),
(121545,"29266 56035"),
(121555,"29266 56035"),
(121549,"29266 56035"),
(121547,"29266 56035"),
(121550,"29266 56035"),
(121558,"29266 56035"),
(121563,"29266 56035"),
(121548,"29266 56035"),
(121544,"29266 56035"),
(121546,"29266 56035"),
(121556,"29266 56035");
