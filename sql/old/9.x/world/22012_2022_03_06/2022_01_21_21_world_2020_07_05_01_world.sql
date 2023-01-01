--
UPDATE `creature_template_addon` SET `auras` = "31482" WHERE `entry` IN (17918,20746);

-- Time Keeper SAI (Source: Movies(Spawn & Despawn parts))
SET @ID := 17918;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,54,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Time Keeper - On Just Summoned - Say Line 0"),
(@ID,0,1,0,0,0,100,0,6000,10000,18000,26000,0,11,31478,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Time Keeper - In Combat - Cast 'Sand Breath'"),
(@ID,0,2,0,5,0,100,0,20000,20000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Time Keeper - On Killed Unit - Say Line 1"),
(@ID,0,3,4,8,0,100,0,31483,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Time Keeper - On Spellhit 'Dragon Helper Effect' - Say Line 2"),
(@ID,0,4,0,61,0,100,0,0,0,0,0,0,41,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Time Keeper - On Link - Despawn (3000)");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"There is no time to waste!",12,0,100,0,0,0,15190,0,"Time Keeper"),
(@ID,0,1,"We must hurry!",12,0,100,0,0,0,15191,0,"Time Keeper"),
(@ID,0,2,"We must use this time wisely!",12,0,100,0,0,0,15192,0,"Time Keeper"),
(@ID,1,0,"One less threat to the timeways!",12,0,100,0,0,0,15193,0,"Time Keeper"),
(@ID,2,0,"Victory will be ours!",14,0,100,0,0,0,15194,0,"Time Keeper"),
(@ID,2,1,"Carry on! Victory at all costs!",14,0,100,0,0,0,15195,0,"Time Keeper"),
(@ID,2,2,"Continue the fight! Do not falter!",14,0,100,0,0,0,15196,0,"Time Keeper");
