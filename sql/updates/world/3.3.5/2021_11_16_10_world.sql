--
UPDATE `spell_target_position` SET `PositionX` = -204, `PositionY` = 391, `PositionZ` = -11, `VerifiedBuild` = 14007 WHERE `ID` = 34673;

UPDATE `spell_target_position` SET `PositionX` = -185, `PositionY` = 376, `PositionZ` = -15.6, `VerifiedBuild` = 26365 WHERE `ID` = 34681;
UPDATE `spell_target_position` SET `PositionX` = -185, `PositionY` = 376, `PositionZ` = -15.6, `VerifiedBuild` = 26365 WHERE `ID` = 34682;
UPDATE `spell_target_position` SET `PositionX` = -185, `PositionY` = 407, `PositionZ` = -15.6, `VerifiedBuild` = 26365 WHERE `ID` = 34684;
UPDATE `spell_target_position` SET `PositionX` = -185, `PositionY` = 407, `PositionZ` = -15.6, `VerifiedBuild` = 26365 WHERE `ID` = 34685;

UPDATE `creature_model_info` SET `BoundingRadius` = 2, `CombatReach` = 3 WHERE `DisplayID` IN (14112,14213,14214);

-- Their AI requires research
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` IN (19919,19920);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (19919,19920) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(19919,0,0,0,37,0,100,0,0,0,0,0,0,116,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Thorn Lasher - On AI Initialize - Set Corpse Delay"),
(19919,0,1,0,0,0,100,0,3000,5000,10000,10000,0,11,35071,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Thorn Lasher - In Combat - Cast 'Thorn Missiles'"),

(19920,0,0,0,37,0,100,0,0,0,0,0,0,116,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Thorn Flayer - On AI Initialize - Set Corpse Delay"),
(19920,0,1,0,0,0,100,0,3000,5000,10000,10000,0,11,35507,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Thorn Flayer - In Combat - Cast 'Mind Flay'");
