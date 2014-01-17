DELETE FROM `spell_script_names` WHERE `spell_id` = 46485;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(46485,'spell_item_greatmothers_soulcatcher');

DELETE FROM `conditions` WHERE `SourceEntry` IN (46485,46488);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,46485,0,1,31,1,3,26817,0,0,0,'',''),
(13,1,46485,0,1,36,1,0,0,0,1,0,'',''),
(13,1,46488,0,1,31,1,3,26817,0,0,0,'',''),
(13,1,46488,0,1,36,1,0,0,0,1,0,'','');

-- Gnome Soul SAI
SET @ENTRY := 26096;
SET @SPELL_ARCANE_EXPLOSION := 35426;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,54,0,100,0,0,0,0,0,33,@ENTRY,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gnome Soul - On Just Summoned - Quest Credit"),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,25814,10,1,0,0,0,0,"Gnome Soul - On Just Summoned - Set Data Fizzcrank Mechagnome"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,69,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gnome Soul - On Just Summoned - Move to Summoner"),

(@ENTRY,0,3,4,34,0,100,0,1,0,0,0,11,@SPELL_ARCANE_EXPLOSION,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gnome Soul - Reached Summoner - Cast Arcane Explosion Visual"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gnome Soul - Reached Summoner - Forced Despawn");

-- Fizzcrank Mechagnome SAI
SET @ENTRY := 25814;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,1,1,10000,0,0,0,0,0,0,0,0,0,0,0,0,"Fizzcrank Mechagnome - Chance Say on Aggro"),
(@ENTRY,1,0,0,38,0,100,0,1,1,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fizzcrank Mechagnome - On Data Set - Forced Despawn");
