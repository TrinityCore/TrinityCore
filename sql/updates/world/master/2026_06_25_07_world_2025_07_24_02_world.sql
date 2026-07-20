--
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (23957,23972) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2395700,2397200,2395701,2397201) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(23957,0,0,0,8,0,100,0,43076,0,0,0,0,80,2395700,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Westguard Cannon Credit Trigger East - On Spellhit 'Mark Cannon' - Run Script"),
(23957,0,1,0,8,0,100,0,43078,0,0,0,0,80,2395701,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Westguard Cannon Credit Trigger East - On Spellhit 'Vengeance Landing Cannonfire' - Run Script"),

(2395700,9,0,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Westguard Cannon Credit Trigger East - On Script - Say Line 0"),
(2395700,9,1,0,0,0,100,0,0,0,0,0,0,33,23957,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Westguard Cannon Credit Trigger East - On Script - Quest Credit 'Guide Our Sights'"),
(2395700,9,2,0,0,0,100,0,5000,5000,0,0,0,45,0,1,0,0,0,0,10,120360,0,0,0,0,0,0,0,"Westguard Cannon Credit Trigger East - On Script - Set Data 0 1 (Vengeance Landing Cannon Controller)"),

(2395701,9,0,0,0,0,100,0,0,0,0,0,0,11,43080,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Westguard Cannon Credit Trigger East - On Script - Cast 'Quest - Howling Fjord - Guide Our Sights - FX Master'"),

(23972,0,0,0,8,0,100,0,43076,0,0,0,0,80,2397200,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Westguard Cannon Credit Trigger West - On Spellhit 'Mark Cannon' - Run Script"),
(23972,0,1,0,8,0,100,0,43079,0,0,0,0,80,2397201,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Westguard Cannon Credit Trigger West - On Spellhit 'Vengeance Landing Cannonfire' - Run Script"),

(2397200,9,0,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Westguard Cannon Credit Trigger West - On Script - Say Line 0"),
(2397200,9,1,0,0,0,100,0,0,0,0,0,0,33,23972,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Westguard Cannon Credit Trigger West - On Script - Quest Credit 'Guide Our Sights'"),
(2397200,9,2,0,0,0,100,0,5000,5000,0,0,0,45,0,2,0,0,0,0,10,120353,0,0,0,0,0,0,0,"Westguard Cannon Credit Trigger West - On Script - Set Data 0 2 (Vengeance Landing Cannon Controller)"),

(2397201,9,0,0,0,0,100,0,0,0,0,0,0,11,43080,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Westguard Cannon Credit Trigger West - On Script - Cast 'Quest - Howling Fjord - Guide Our Sights - FX Master'");

DELETE FROM `smart_scripts` WHERE `entryorguid` = 23805 AND `source_type` = 0 AND `id` IN (1,2);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(23805,0,1,0,38,0,100,0,0,1,0,0,0,11,43078,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Vengeance Landing Cannon Controller - On Data Set 0 1 - Cast 'Vengeance Landing Cannonfire'"),
(23805,0,2,0,38,0,100,0,0,2,0,0,0,11,43079,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Vengeance Landing Cannon Controller - On Data Set 0 2 - Cast 'Vengeance Landing Cannonfire'");

DELETE FROM `creature_text` WHERE `CreatureID` IN (23957,23972);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(23957,0,0,"Cannonfire rings off in the distance, followed by the sound of a whistling cannonball coming from above.",16,0,100,0,0,0,22784,0,"Westguard Cannon Credit Trigger East"),
(23972,0,0,"Cannonfire rings off in the distance, followed by the sound of a whistling cannonball coming from above.",16,0,100,0,0,0,22784,0,"Westguard Cannon Credit Trigger West");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (43078,43079,43080);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,43078,0,0,31,0,3,23957,0,0,0,0,"","Group 0: Spell 'Vengeance Landing Cannonfire' (Effect 0) targets creature 'Westguard Cannon Credit Trigger East'"),
(13,1,43079,0,0,31,0,3,23972,0,0,0,0,"","Group 0: Spell 'Vengeance Landing Cannonfire' (Effect 0) targets creature 'Westguard Cannon Credit Trigger West'"),

(13,4,43080,0,0,31,0,5,186391,0,0,0,0,"","Group 0: Spell 'Quest - Howling Fjord - Guide Our Sights - FX Master' (Effect 2) targets object 'Westguard Cannon'");

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_fjord_guide_our_sights_fx_master';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(43080, 'spell_fjord_guide_our_sights_fx_master');
