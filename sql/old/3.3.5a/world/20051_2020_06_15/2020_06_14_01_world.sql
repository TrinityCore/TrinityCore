-- Redeemed Hatchling SAI (Source: https://www.youtube.com/watch?v=zgalBODgYdA)
SET @ID := 22339;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,1,54,0,100,0,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Redeemed Hatchling - On Just Summoned - Set Run Off"),
(@ID,0,1,2,61,0,100,0,0,0,0,0,0,69,1,0,0,0,0,0,19,22340,0,0,0,0,0,0,0,"Redeemed Hatchling - On Link - Move To Closest Creature 'Terokkar Arakkoa Fly Target'"),
(@ID,0,2,0,61,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Redeemed Hatchling - On Link - Say Line 0"),
(@ID,0,3,0,34,0,100,0,8,1,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Redeemed Hatchling - On Reached Point 1 - Despawn (0)");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"The %s flies up through the trees, free of Terokk's corruption.",16,0,100,0,0,0,20136,0,"Redeemed Hatchling");

DELETE FROM `creature_template_movement` WHERE `CreatureId` = 22339;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`) VALUES
(22339,1,0,1,0,0,0);
