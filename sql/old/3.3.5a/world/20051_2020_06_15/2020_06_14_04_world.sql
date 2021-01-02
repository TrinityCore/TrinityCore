-- The Scourge Cauldron SAI
SET @ID := 11152;
UPDATE `creature` SET `spawntimesecs` = 30 WHERE `id` = 11152;
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,4,38,0,100,0,0,1,0,0,0,12,11075,1,60000,0,0,0,1,0,0,0,0,0,0,0,0,"The Scourge Cauldron - On Data Set 0 1 - Summon Creature 'Cauldron Lord Bilemaw'"),
(@ID,0,1,4,38,0,100,0,0,2,0,0,0,12,11077,1,60000,0,0,0,1,0,0,0,0,0,0,0,0,"The Scourge Cauldron - On Data Set 0 2 - Summon Creature 'Cauldron Lord Malvinious'"),
(@ID,0,2,4,38,0,100,0,0,3,0,0,0,12,11076,1,60000,0,0,0,1,0,0,0,0,0,0,0,0,"The Scourge Cauldron - On Data Set 0 3 - Summon Creature 'Cauldron Lord Razarch'"),
(@ID,0,3,4,38,0,100,0,0,4,0,0,0,12,11078,1,60000,0,0,0,1,0,0,0,0,0,0,0,0,"The Scourge Cauldron - On Data Set 0 4 - Summon Creature 'Cauldron Lord Soulwrath'"),
(@ID,0,4,0,61,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"The Scourge Cauldron - On Link - Despawn (0)");

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2246,2248,2250,2252,2626,2627,2628,2629,2630,2631,2632,2633,2634,2635,2636,2637) AND `source_type` = 2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(2246,2,0,0,46,0,100,0,2246,0,0,0,0,45,0,1,0,0,0,0,10,45420,11152,0,0,0,0,0,0,"Areatrigger (Felstone Field) - On Trigger - Set Data 0 1 (The Scourge Cauldron)"),
(2248,2,0,0,46,0,100,0,2248,0,0,0,0,45,0,2,0,0,0,0,10,45421,11152,0,0,0,0,0,0,"Areatrigger (Dalson's Tears) - On Trigger - Set Data 0 2 (The Scourge Cauldron)"),
(2250,2,0,0,46,0,100,0,2250,0,0,0,0,45,0,3,0,0,0,0,10,45422,11152,0,0,0,0,0,0,"Areatrigger (Writhing Haunt) - On Trigger - Set Data 0 3 (The Scourge Cauldron)"),
(2252,2,0,0,46,0,100,0,2252,0,0,0,0,45,0,4,0,0,0,0,10,45419,11152,0,0,0,0,0,0,"Areatrigger (Gahrron's Withering) - On Trigger - Set Data 0 4 (The Scourge Cauldron)"),
(2626,2,0,0,46,0,100,0,2626,0,0,0,0,45,0,1,0,0,0,0,10,45420,11152,0,0,0,0,0,0,"Areatrigger (Felstone Field) - On Trigger - Set Data 0 1 (The Scourge Cauldron)"),
(2627,2,0,0,46,0,100,0,2627,0,0,0,0,45,0,1,0,0,0,0,10,45420,11152,0,0,0,0,0,0,"Areatrigger (Felstone Field) - On Trigger - Set Data 0 1 (The Scourge Cauldron)"),
(2628,2,0,0,46,0,100,0,2628,0,0,0,0,45,0,1,0,0,0,0,10,45420,11152,0,0,0,0,0,0,"Areatrigger (Felstone Field) - On Trigger - Set Data 0 1 (The Scourge Cauldron)"),
(2629,2,0,0,46,0,100,0,2629,0,0,0,0,45,0,2,0,0,0,0,10,45421,11152,0,0,0,0,0,0,"Areatrigger (Dalson's Tears) - On Trigger - Set Data 0 2 (The Scourge Cauldron)"),
(2630,2,0,0,46,0,100,0,2630,0,0,0,0,45,0,2,0,0,0,0,10,45421,11152,0,0,0,0,0,0,"Areatrigger (Dalson's Tears) - On Trigger - Set Data 0 2 (The Scourge Cauldron)"),
(2631,2,0,0,46,0,100,0,2631,0,0,0,0,45,0,2,0,0,0,0,10,45421,11152,0,0,0,0,0,0,"Areatrigger (Dalson's Tears) - On Trigger - Set Data 0 2 (The Scourge Cauldron)"),
(2632,2,0,0,46,0,100,0,2632,0,0,0,0,45,0,3,0,0,0,0,10,45422,11152,0,0,0,0,0,0,"Areatrigger (Writhing Haunt) - On Trigger - Set Data 0 3 (The Scourge Cauldron)"),
(2633,2,0,0,46,0,100,0,2633,0,0,0,0,45,0,3,0,0,0,0,10,45422,11152,0,0,0,0,0,0,"Areatrigger (Writhing Haunt) - On Trigger - Set Data 0 3 (The Scourge Cauldron)"),
(2634,2,0,0,46,0,100,0,2634,0,0,0,0,45,0,3,0,0,0,0,10,45422,11152,0,0,0,0,0,0,"Areatrigger (Writhing Haunt) - On Trigger - Set Data 0 3 (The Scourge Cauldron)"),
(2635,2,0,0,46,0,100,0,2635,0,0,0,0,45,0,4,0,0,0,0,10,45419,11152,0,0,0,0,0,0,"Areatrigger (Gahrron's Withering) - On Trigger - Set Data 0 4 (The Scourge Cauldron)"),
(2636,2,0,0,46,0,100,0,2636,0,0,0,0,45,0,4,0,0,0,0,10,45419,11152,0,0,0,0,0,0,"Areatrigger (Gahrron's Withering) - On Trigger - Set Data 0 4 (The Scourge Cauldron)"),
(2637,2,0,0,46,0,100,0,2637,0,0,0,0,45,0,4,0,0,0,0,10,45419,11152,0,0,0,0,0,0,"Areatrigger (Gahrron's Withering) - On Trigger - Set Data 0 4 (The Scourge Cauldron)");

DELETE FROM `areatrigger_scripts` WHERE `entry` IN (2246,2248,2250,2252,2626,2627,2628,2629,2630,2631,2632,2633,2634,2635,2636,2637);
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(2246,"SmartTrigger"), -- Felstone Field
(2248,"SmartTrigger"), -- Dalson's Tears
(2250,"SmartTrigger"), -- Writhing Haunt
(2252,"SmartTrigger"), -- Gahrron's Withering
(2626,"SmartTrigger"), -- Felstone Field
(2627,"SmartTrigger"), -- Felstone Field
(2628,"SmartTrigger"), -- Felstone Field
(2629,"SmartTrigger"), -- Dalson's Tears
(2630,"SmartTrigger"), -- Dalson's Tears
(2631,"SmartTrigger"), -- Dalson's Tears
(2632,"SmartTrigger"), -- Writhing Haunt
(2633,"SmartTrigger"), -- Writhing Haunt
(2634,"SmartTrigger"), -- Writhing Haunt
(2635,"SmartTrigger"), -- Gahrron's Withering
(2636,"SmartTrigger"), -- Gahrron's Withering
(2637,"SmartTrigger"); -- Gahrron's Withering

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` IN (2246,2248,2250,2252,2626,2627,2628,2629,2630,2631,2632,2633,2634,2635,2636,2637) AND `SourceId` = 2;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,2246,2,0,9,0,5216,0,0,0,0,0,"","Group 0: Execute SAI (Action 0) if player has taken quest 'Target: Felstone Field (A)'"),
(22,1,2246,2,1,9,0,5229,0,0,0,0,0,"","Group 1: Execute SAI (Action 0) if player has taken quest 'Target: Felstone Field (H)'"),
(22,1,2246,2,0,29,0,11075,100,0,1,0,0,"","Group 0: Execute SAI (Action 0) if creature 'Cauldron Lord Bilemaw' is not near"),
(22,1,2246,2,1,29,0,11075,100,0,1,0,0,"","Group 1: Execute SAI (Action 0) if creature 'Cauldron Lord Bilemaw' is not near"),

(22,1,2248,2,0,9,0,5219,0,0,0,0,0,"","Group 0: Execute SAI (Action 0) if player has taken quest 'Target: Dalson's Tears (A)'"),
(22,1,2248,2,1,9,0,5231,0,0,0,0,0,"","Group 1: Execute SAI (Action 0) if player has taken quest 'Target: Dalson's Tears (H)'"),
(22,1,2248,2,0,29,0,11077,100,0,1,0,0,"","Group 0: Execute SAI (Action 0) if creature 'Cauldron Lord Malvinious' is not near"),
(22,1,2248,2,1,29,0,11077,100,0,1,0,0,"","Group 1: Execute SAI (Action 0) if creature 'Cauldron Lord Malvinious' is not near"),

(22,1,2250,2,0,9,0,5222,0,0,0,0,0,"","Group 0: Execute SAI (Action 0) if player has taken quest 'Target: Writhing Haunt (A)'"),
(22,1,2250,2,1,9,0,5233,0,0,0,0,0,"","Group 1: Execute SAI (Action 0) if player has taken quest 'Target: Writhing Haunt (H)'"),
(22,1,2250,2,0,29,0,11076,100,0,1,0,0,"","Group 0: Execute SAI (Action 0) if creature 'Cauldron Lord Razarch' is not near"),
(22,1,2250,2,1,29,0,11076,100,0,1,0,0,"","Group 1: Execute SAI (Action 0) if creature 'Cauldron Lord Razarch' is not near"),

(22,1,2252,2,0,9,0,5225,0,0,0,0,0,"","Group 0: Execute SAI (Action 0) if player has taken quest 'Target: Gahrron's Withering (A)'"),
(22,1,2252,2,1,9,0,5235,0,0,0,0,0,"","Group 1: Execute SAI (Action 0) if player has taken quest 'Target: Gahrron's Withering (H)'"),
(22,1,2252,2,0,29,0,11078,100,0,1,0,0,"","Group 0: Execute SAI (Action 0) if creature 'Cauldron Lord Soulwrath' is not near"),
(22,1,2252,2,1,29,0,11078,100,0,1,0,0,"","Group 1: Execute SAI (Action 0) if creature 'Cauldron Lord Soulwrath' is not near"),

(22,1,2626,2,0,9,0,5216,0,0,0,0,0,"","Group 0: Execute SAI (Action 0) if player has taken quest 'Target: Felstone Field (A)'"),
(22,1,2626,2,1,9,0,5229,0,0,0,0,0,"","Group 1: Execute SAI (Action 0) if player has taken quest 'Target: Felstone Field (H)'"),
(22,1,2627,2,0,9,0,5216,0,0,0,0,0,"","Group 0: Execute SAI (Action 0) if player has taken quest 'Target: Felstone Field (A)'"),
(22,1,2627,2,1,9,0,5229,0,0,0,0,0,"","Group 1: Execute SAI (Action 0) if player has taken quest 'Target: Felstone Field (H)'"),
(22,1,2628,2,0,9,0,5216,0,0,0,0,0,"","Group 0: Execute SAI (Action 0) if player has taken quest 'Target: Felstone Field (A)'"),
(22,1,2628,2,1,9,0,5229,0,0,0,0,0,"","Group 1: Execute SAI (Action 0) if player has taken quest 'Target: Felstone Field (H)'"),
(22,1,2626,2,0,29,0,11075,100,0,1,0,0,"","Group 0: Execute SAI (Action 0) if creature 'Cauldron Lord Bilemaw' is not near"),
(22,1,2626,2,1,29,0,11075,100,0,1,0,0,"","Group 1: Execute SAI (Action 0) if creature 'Cauldron Lord Bilemaw' is not near"),
(22,1,2627,2,0,29,0,11075,100,0,1,0,0,"","Group 0: Execute SAI (Action 0) if creature 'Cauldron Lord Bilemaw' is not near"),
(22,1,2627,2,1,29,0,11075,100,0,1,0,0,"","Group 1: Execute SAI (Action 0) if creature 'Cauldron Lord Bilemaw' is not near"),
(22,1,2628,2,0,29,0,11075,100,0,1,0,0,"","Group 0: Execute SAI (Action 0) if creature 'Cauldron Lord Bilemaw' is not near"),
(22,1,2628,2,1,29,0,11075,100,0,1,0,0,"","Group 1: Execute SAI (Action 0) if creature 'Cauldron Lord Bilemaw' is not near"),

(22,1,2629,2,0,9,0,5219,0,0,0,0,0,"","Group 0: Execute SAI (Action 0) if player has taken quest 'Target: Dalson's Tears (A)'"),
(22,1,2629,2,1,9,0,5231,0,0,0,0,0,"","Group 1: Execute SAI (Action 0) if player has taken quest 'Target: Dalson's Tears (H)'"),
(22,1,2630,2,0,9,0,5219,0,0,0,0,0,"","Group 0: Execute SAI (Action 0) if player has taken quest 'Target: Dalson's Tears (A)'"),
(22,1,2630,2,1,9,0,5231,0,0,0,0,0,"","Group 1: Execute SAI (Action 0) if player has taken quest 'Target: Dalson's Tears (H)'"),
(22,1,2631,2,0,9,0,5219,0,0,0,0,0,"","Group 0: Execute SAI (Action 0) if player has taken quest 'Target: Dalson's Tears (A)'"),
(22,1,2631,2,1,9,0,5231,0,0,0,0,0,"","Group 1: Execute SAI (Action 0) if player has taken quest 'Target: Dalson's Tears (H)'"),
(22,1,2629,2,0,29,0,11077,100,0,1,0,0,"","Group 0: Execute SAI (Action 0) if creature 'Cauldron Lord Malvinious' is not near"),
(22,1,2629,2,1,29,0,11077,100,0,1,0,0,"","Group 1: Execute SAI (Action 0) if creature 'Cauldron Lord Malvinious' is not near"),
(22,1,2630,2,0,29,0,11077,100,0,1,0,0,"","Group 0: Execute SAI (Action 0) if creature 'Cauldron Lord Malvinious' is not near"),
(22,1,2630,2,1,29,0,11077,100,0,1,0,0,"","Group 1: Execute SAI (Action 0) if creature 'Cauldron Lord Malvinious' is not near"),
(22,1,2631,2,0,29,0,11077,100,0,1,0,0,"","Group 0: Execute SAI (Action 0) if creature 'Cauldron Lord Malvinious' is not near"),
(22,1,2631,2,1,29,0,11077,100,0,1,0,0,"","Group 1: Execute SAI (Action 0) if creature 'Cauldron Lord Malvinious' is not near"),

(22,1,2632,2,0,9,0,5222,0,0,0,0,0,"","Group 0: Execute SAI (Action 0) if player has taken quest 'Target: Writhing Haunt (A)'"),
(22,1,2632,2,1,9,0,5233,0,0,0,0,0,"","Group 1: Execute SAI (Action 0) if player has taken quest 'Target: Writhing Haunt (H)'"),
(22,1,2633,2,0,9,0,5222,0,0,0,0,0,"","Group 0: Execute SAI (Action 0) if player has taken quest 'Target: Writhing Haunt (A)'"),
(22,1,2633,2,1,9,0,5233,0,0,0,0,0,"","Group 1: Execute SAI (Action 0) if player has taken quest 'Target: Writhing Haunt (H)'"),
(22,1,2634,2,0,9,0,5222,0,0,0,0,0,"","Group 0: Execute SAI (Action 0) if player has taken quest 'Target: Writhing Haunt (A)'"),
(22,1,2634,2,1,9,0,5233,0,0,0,0,0,"","Group 1: Execute SAI (Action 0) if player has taken quest 'Target: Writhing Haunt (H)'"),
(22,1,2632,2,0,29,0,11076,100,0,1,0,0,"","Group 0: Execute SAI (Action 0) if creature 'Cauldron Lord Razarch' is not near"),
(22,1,2632,2,1,29,0,11076,100,0,1,0,0,"","Group 1: Execute SAI (Action 0) if creature 'Cauldron Lord Razarch' is not near"),
(22,1,2633,2,0,29,0,11076,100,0,1,0,0,"","Group 0: Execute SAI (Action 0) if creature 'Cauldron Lord Razarch' is not near"),
(22,1,2633,2,1,29,0,11076,100,0,1,0,0,"","Group 1: Execute SAI (Action 0) if creature 'Cauldron Lord Razarch' is not near"),
(22,1,2634,2,0,29,0,11076,100,0,1,0,0,"","Group 0: Execute SAI (Action 0) if creature 'Cauldron Lord Razarch' is not near"),
(22,1,2634,2,1,29,0,11076,100,0,1,0,0,"","Group 1: Execute SAI (Action 0) if creature 'Cauldron Lord Razarch' is not near"),

(22,1,2635,2,0,9,0,5225,0,0,0,0,0,"","Group 0: Execute SAI (Action 0) if player has taken quest 'Target: Gahrron's Withering (A)'"),
(22,1,2635,2,1,9,0,5235,0,0,0,0,0,"","Group 1: Execute SAI (Action 0) if player has taken quest 'Target: Gahrron's Withering (H)'"),
(22,1,2636,2,0,9,0,5225,0,0,0,0,0,"","Group 0: Execute SAI (Action 0) if player has taken quest 'Target: Gahrron's Withering (A)'"),
(22,1,2636,2,1,9,0,5235,0,0,0,0,0,"","Group 1: Execute SAI (Action 0) if player has taken quest 'Target: Gahrron's Withering (H)'"),
(22,1,2637,2,0,9,0,5225,0,0,0,0,0,"","Group 0: Execute SAI (Action 0) if player has taken quest 'Target: Gahrron's Withering (A)'"),
(22,1,2637,2,1,9,0,5235,0,0,0,0,0,"","Group 1: Execute SAI (Action 0) if player has taken quest 'Target: Gahrron's Withering (H)'"),
(22,1,2635,2,0,29,0,11078,100,0,1,0,0,"","Group 0: Execute SAI (Action 0) if creature 'Cauldron Lord Soulwrath' is not near"),
(22,1,2635,2,1,29,0,11078,100,0,1,0,0,"","Group 1: Execute SAI (Action 0) if creature 'Cauldron Lord Soulwrath' is not near"),
(22,1,2636,2,0,29,0,11078,100,0,1,0,0,"","Group 0: Execute SAI (Action 0) if creature 'Cauldron Lord Soulwrath' is not near"),
(22,1,2636,2,1,29,0,11078,100,0,1,0,0,"","Group 1: Execute SAI (Action 0) if creature 'Cauldron Lord Soulwrath' is not near"),
(22,1,2637,2,0,29,0,11078,100,0,1,0,0,"","Group 0: Execute SAI (Action 0) if creature 'Cauldron Lord Soulwrath' is not near"),
(22,1,2637,2,1,29,0,11078,100,0,1,0,0,"","Group 1: Execute SAI (Action 0) if creature 'Cauldron Lord Soulwrath' is not near");
