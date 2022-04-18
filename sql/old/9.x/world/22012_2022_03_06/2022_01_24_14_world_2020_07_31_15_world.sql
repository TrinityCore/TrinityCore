-- Source: Sniffs & https://www.youtube.com/watch?v=SaSrbxgnyDw

-- Black Knight's Grave
-- Migrate to c_t_a and remove script, everything is handled by AT
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 34735);
UPDATE `creature_template_addon` SET `bytes2` = 1, `auras` = "67549" WHERE `entry` = 34735;
UPDATE `creature_template` SET `AIName` = "" WHERE `entry` = 34735;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 34735 AND `source_type` = 0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 34735 AND `SourceId` = 0;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 5500 AND `source_type` = 2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(5500,2,0,1,46,0,100,0,5500,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Areatrigger (Argent Tournament Grounds) - On Trigger - Store Targetlist"),
(5500,2,1,2,61,0,100,0,0,0,0,0,0,12,35127,4,60000,0,0,0,8,0,0,0,0,8455.797,459.0955,596.1551,1.570796,"Areatrigger (Argent Tournament Grounds) - On Link - Summon Creature 'Cult Assassin'"),
(5500,2,2,3,61,0,100,0,0,0,0,0,0,12,35116,4,60000,0,0,0,8,0,0,0,0,8452.683,459.87674,596.1551,0.872664,"Areatrigger (Argent Tournament Grounds) - On Link - Summon Creature 'Cult Saboteur'"),
-- We can use owner guid but in future it may be updated so there will be no owner
(5500,2,3,0,61,0,100,0,0,0,0,0,0,100,1,0,0,0,0,0,19,35127,20,0,0,0,0,0,0,"Areatrigger (Argent Tournament Grounds) - On Link - Send Target 1 (Cult Assassin)");

DELETE FROM `areatrigger_scripts` WHERE `entry` = 5500;
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(5500,"SmartTrigger");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 5500 AND `SourceId` = 2;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,5500,2,0,9,0,14016,0,0,0,0,0,"","Group 0: Execute SAI (Action 0) if player has taken quest 'The Black Knight's Curse'"),
(22,1,5500,2,0,29,0,35127,100,0,1,0,0,"","Group 0: Execute SAI (Action 0) if alive creature 'Cult Assassin' is not near");

UPDATE `creature_template` SET `unit_flags` = 33536 WHERE `entry` IN (35127,35116);
DELETE FROM `creature_template_addon` WHERE `entry` = 35127;
INSERT INTO `creature_template_addon` (`entry`,`bytes1`,`bytes2`) VALUES
(35127,8,1);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (35127,35116) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 3512700 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(35127,0,0,0,54,0,100,0,0,0,0,0,0,80,3512700,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cult Assassin - On Just Summoned - Run Script"),
(35127,0,1,0,0,0,100,0,1000,2000,7000,8000,0,11,14873,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Cult Assassin - In Combat - Cast 'Sinister Strike'"),
(35127,0,2,0,0,0,100,0,3000,4000,14000,15000,0,11,60842,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Cult Assassin - In Combat - Cast 'Expose Armor'"),
(35127,0,3,0,6,0,100,0,0,0,0,0,0,11,66785,2,0,0,0,0,7,0,0,0,0,0,0,0,0,"Cult Assassin - On Death - Cast 'Black Knight's Grave Credit'"),

(3512700,9,0,0,0,0,100,0,1000,1000,0,0,0,1,0,0,0,0,0,0,19,35116,20,0,0,0,0,0,0,"Cult Assassin - On Script - Say Line 0 (Cult Saboteur)"),
(3512700,9,1,0,0,0,100,0,5000,5000,0,0,0,1,1,0,0,0,0,0,19,35116,20,0,0,0,0,0,0,"Cult Assassin - On Script - Say Line 1 (Cult Saboteur)"),
(3512700,9,2,0,0,0,100,0,5000,5000,0,0,0,45,0,1,0,0,0,0,19,35116,20,0,0,0,0,0,0,"Cult Assassin - On Script - Set Data 0 1 (Cult Saboteur)"),
(3512700,9,3,0,0,0,100,0,1000,1000,0,0,0,1,2,0,0,0,0,0,19,35116,20,0,0,0,0,0,0,"Cult Assassin - On Script - Say Line 2 (Cult Saboteur)"),
(3512700,9,4,0,0,0,100,0,3500,3500,0,0,0,86,62940,0,19,35116,20,0,1,0,0,0,0,0,0,0,0,"Cult Assassin - On Script - Cross Cast 'Teleport' (Cult Saboteur)"),
(3512700,9,5,0,0,0,100,0,0,0,0,0,0,41,3000,0,0,0,0,0,19,35116,20,0,0,0,0,0,0,"Cult Assassin - On Script - Despawn (3000) (Cult Saboteur)"),
(3512700,9,6,0,0,0,100,0,500,500,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cult Assassin - On Script - Remove Flag Standstate Kneel"),
(3512700,9,7,0,0,0,100,0,1000,1000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cult Assassin - On Script - Say Line 0"),
(3512700,9,8,0,0,0,100,0,0,0,0,0,0,17,333,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cult Assassin - On Script - Set Emote State 333"),
(3512700,9,9,0,0,0,100,0,1000,1000,0,0,0,19,256,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cult Assassin - On Script - Remove Flag Immune To Players"),
(3512700,9,10,0,0,0,100,0,0,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cult Assassin - On Script - Set Emote State 0"),
(3512700,9,11,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Cult Assassin - On Script - Start Attacking Stored Target 1"),

(35116,0,0,0,38,0,100,0,0,1,0,0,0,66,0,0,0,0,0,0,19,35127,20,0,0,0,0,0,0,"Cult Saboteur - On Data Set 0 1 - Set Orientation Closest Creature 'Cult Assassin'");

UPDATE `creature_text` SET `comment` = "Cult Saboteur" WHERE `CreatureID` = 35116;
UPDATE `creature_text` SET `comment` = "Cult Assassin" WHERE `CreatureID` = 35127;
UPDATE `creature_text` SET `Emote` = 6 WHERE `CreatureID` = 35116 AND `GroupID` = 0;
UPDATE `creature_text` SET `Emote` = 25 WHERE `CreatureID` = 35116 AND `GroupID` = 2;
