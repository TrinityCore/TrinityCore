-- Update Promo
UPDATE `creature_template` SET `entry`='1202860', `difficulty_entry_1`='0', `difficulty_entry_2`='0', `difficulty_entry_3`='0', `KillCredit1`='0', `KillCredit2`='0', `modelid1`='75723', `modelid2`='0', `modelid3`='0', `modelid4`='0', `name`='Fallen Avatar', `femaleName`='', `subname`='RenegadosWoW -  Promo', `TitleAlt`='', `IconName`='Directions', `gossip_menu_id`='0', `minlevel`='110', `maxlevel`='110', `HealthScalingExpansion`='-1', `RequiredExpansion`='7', `VignetteID`='0', `faction`='7', `npcflag`='1', `speed_walk`='1', `speed_run`='1.14286', `scale`='0.12', `rank`='0', `dmgschool`='0', `BaseAttackTime`='0', `RangeAttackTime`='0', `BaseVariance`='0', `RangeVariance`='0', `unit_class`='1', `unit_flags`='0', `unit_flags2`='0', `unit_flags3`='0', `dynamicflags`='0', `family`='0', `trainer_type`='0', `trainer_class`='0', `trainer_race`='0', `type`='0', `type_flags`='0', `type_flags2`='0', `lootid`='0', `pickpocketloot`='0', `skinloot`='0', `resistance1`='0', `resistance2`='0', `resistance3`='0', `resistance4`='0', `resistance5`='0', `resistance6`='0', `spell1`='0', `spell2`='0', `spell3`='0', `spell4`='0', `spell5`='0', `spell6`='0', `spell7`='0', `spell8`='0', `VehicleId`='0', `mingold`='0', `maxgold`='0', `AIName`='', `MovementType`='0', `InhabitType`='3', `HoverHeight`='1', `HealthModifier`='1', `HealthModifierExtra`='1', `ManaModifier`='1', `ManaModifierExtra`='1', `ArmorModifier`='1', `DamageModifier`='1', `ExperienceModifier`='1', `RacialLeader`='0', `movementId`='0', `RegenHealth`='0', `mechanic_immune_mask`='0', `flags_extra`='0', `ScriptName`='npc_promotion_blue_equip', `VerifiedBuild`='0' WHERE (`entry`='1202860');

-- Fix Quest Chain Blizzlike accord to Legion 7.3.5
UPDATE `quest_template_addon` SET `ID`='28766', `PrevQuestID`='0', `NextQuestID`='28774' WHERE (`ID`='28766');
UPDATE `quest_template_addon` SET `ID`='28774', `PrevQuestID`='28766', `NextQuestID`='28789' WHERE (`ID`='28774');
UPDATE `quest_template_addon` SET `ID`='28789', `PrevQuestID`='28774', `NextQuestID`='28797' WHERE (`ID`='28789');
UPDATE `quest_template_addon` SET `ID`='28797', `PrevQuestID`='0', `NextQuestID`='28823' WHERE (`ID`='28797');
UPDATE `quest_template_addon` SET `ID`='28813', `PrevQuestID`='28785', `NextQuestID`='0' WHERE (`ID`='28813');
UPDATE `quest_template_addon` SET `ID`='28823', `PrevQuestID`='0', `NextQuestID`='26389' WHERE (`ID`='28823');

UPDATE `quest_template` SET `ID`='28766', `RewardNextQuest`='28774' WHERE (`ID`='28766');
UPDATE `quest_template` SET `ID`='28774', `RewardNextQuest`='28789' WHERE (`ID`='28774');
UPDATE `quest_template` SET `ID`='28789', `RewardNextQuest`='28797' WHERE (`ID`='28789');
UPDATE `quest_template` SET `ID`='28797', `RewardNextQuest`='28823' WHERE (`ID`='28797');
UPDATE `quest_template` SET `ID`='28813', `RewardNextQuest`='0' WHERE (`ID`='28813');
UPDATE `quest_template` SET `ID`='28823', `RewardNextQuest`='26389' WHERE (`ID`='28823');

-- Marshal McBride SAI
SET @MARSHAL_MCBRIDE := 197;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@MARSHAL_MCBRIDE;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@MARSHAL_MCBRIDE AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@MARSHAL_MCBRIDE,0,0,0,19,0,100,0,54,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Marshal McBride - On Quest 'Report to Goldshire' Taken - Say Line 0 (No Repeat)"),
(@MARSHAL_MCBRIDE,0,1,0,11,0,100,0,0,0,0,0,5,483,0,0,0,0,0,1,0,0,0,0,0,0,0,"Marshal McBride - On Respawn - Play Emote 483");

-- Blackrock Spy SAI
SET @BLACKROCK_SPY := 49874;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@BLACKROCK_SPY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@BLACKROCK_SPY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@BLACKROCK_SPY,0,0,0,4,0,70,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Spy - On Aggro - Say Line 0 (No Repeat)"),
(@BLACKROCK_SPY,0,1,0,11,0,50,1,0,0,0,0,11,80676,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Spy - On Respawn - Cast 'Spyglass' (No Repeat)"),
(@BLACKROCK_SPY,0,2,0,11,0,50,1,0,0,0,0,11,92857,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Spy - On Respawn - Cast 'Spying' (No Repeat)");

-- Goblin Assassin SAI
SET @GOBLIN_ASSASSIN := 50039;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@GOBLIN_ASSASSIN;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GOBLIN_ASSASSIN AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GOBLIN_ASSASSIN,0,0,0,4,0,60,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Goblin Assassin - On Aggro - Say Line 0 (No Repeat)"),
(@GOBLIN_ASSASSIN,0,1,0,11,0,100,1,0,0,0,0,11,93046,0,0,0,0,0,1,0,0,0,0,0,0,0,"Goblin Assassin - On Respawn - Cast 'Sneaking' (No Repeat)");

-- Milly Osworth SAI
SET @MILLY_OSWORTH := 9296;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@MILLY_OSWORTH;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@MILLY_OSWORTH AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@MILLY_OSWORTH,0,0,0,19,0,100,0,26391,0,0,0,75,80209,0,0,0,0,0,7,0,0,0,0,0,0,0,"Milly Osworth - On Quest 'Extinguishing Hope' Taken - Add Aura 'Fire Extinguisher'"),
(@MILLY_OSWORTH,0,1,0,20,0,100,0,26391,0,0,0,28,80209,0,0,0,0,0,7,0,0,0,0,0,0,0,"Milly Osworth - On Quest 'Extinguishing Hope' Finished - Remove Aura 'Fire Extinguisher'");

-- Brother Paxton SAI
SET @BROTHER_PAXTON := 951;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@BROTHER_PAXTON;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@BROTHER_PAXTON AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@BROTHER_PAXTON,0,0,0,14,0,100,0,30,40,12000,14000,11,13864,2,0,0,0,0,26,40,0,0,0,0,0,0,"Brother Paxton - Friendly At 30 Health - Cast 'Power Word: Fortitude'"),
(@BROTHER_PAXTON,0,1,0,14,0,100,0,80,40,3000,6000,11,93094,2,0,0,0,0,26,40,0,0,0,0,0,0,"Brother Paxton - Friendly At 80 Health - Cast 'Renew'"),
(@BROTHER_PAXTON,0,2,0,14,0,100,0,70,40,8000,10000,11,93091,2,0,0,0,0,26,40,0,0,0,0,0,0,"Brother Paxton - Friendly At 70 Health - Cast 'Prayer of Healing'"),
(@BROTHER_PAXTON,0,3,0,14,0,100,0,80,40,0,0,1,0,3000,0,0,0,0,1,0,0,0,0,0,0,0,"Brother Paxton - Friendly At 30 Health - Say Line 0"),
(@BROTHER_PAXTON,0,4,0,14,0,100,0,80,40,0,0,1,1,3000,0,0,0,0,1,0,0,0,0,0,0,0,"Brother Paxton - Friendly At 80 Health - Say Line 1"),
(@BROTHER_PAXTON,0,5,0,14,0,100,0,80,40,0,0,1,2,3000,0,0,0,0,1,0,0,0,0,0,0,0,"Brother Paxton - Friendly At 70 Health - Say Line 2");

DELETE FROM `creature_text` WHERE `CreatureID`=951;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
('951', '0', '0', 'Be Healed, Brother!', '12', '0', '0', '0', '0', '0', '0', '0', 'Brother Paxton - SAY'),
('951', '1', '0', 'BY THE LIGHT BE RENEWED!', '12', '0', '0', '0', '0', '0', '0', '0', 'Brother Paxton - SAY'),
('951', '2', '0', 'FIGHT ON, BROTHER!', '12', '0', '0', '0', '0', '0', '0', '0', 'Brother Paxton - SAY');

-- Blackrock Invader SAI
SET @BLACKROCK_INVADER := 42937;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@BLACKROCK_INVADER;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@BLACKROCK_INVADER AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@BLACKROCK_INVADER,0,0,0,4,0,70,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Invader - On Aggro - Say Line 0 (No Repeat)");
