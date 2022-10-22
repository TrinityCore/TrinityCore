--
DELETE FROM `smart_scripts` WHERE `entryorguid` = 5108 AND `source_type` = 2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(5108,2,0,1,46,0,100,0,5108,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Areatrigger (The Stormwright's Shelf) - On Trigger - Store Targetlist"),
(5108,2,1,2,61,0,100,0,0,0,0,0,0,100,1,0,0,0,0,0,19,29079,0,0,0,0,0,0,0,"Areatrigger (The Stormwright's Shelf) - On Link - Send Target 1 (Shrine of the Tempest)"),
(5108,2,2,0,61,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,19,29079,0,0,0,0,0,0,0,"Areatrigger (The Stormwright's Shelf) - On Link - Set Data 0 1 (Shrine of the Tempest)");

DELETE FROM `areatrigger_scripts` WHERE `entry` = 5108;
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(5108,"SmartTrigger");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 5108 AND `SourceId` = 2;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,5108,2,0,9,0,12741,0,0,0,0,0,"","Group 0: Execute SAI (Action 0) if player has taken quest 'Strength of the Tempest'");

DELETE FROM `smart_scripts` WHERE `entryorguid` = 29079 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(29079,0,0,0,38,0,100,0,0,1,0,0,0,11,53062,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Shrine of the Tempest - On Data Set 0 1 - Cast 'Lightning Strike'");

DELETE FROM `spell_scripts` WHERE `id` = 53062;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_sholazar_lightning_strike';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(53062,'spell_sholazar_lightning_strike');

--
DELETE FROM `spell_scripts` WHERE `id` = 51071;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_sholazar_flight_to_sholazar';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(51071,'spell_sholazar_flight_to_sholazar');

DELETE FROM `creature_text` WHERE `CreatureID` = 28192;

-- Yes, it is unrealistic that other 8 will be used
DELETE FROM `spell_scripts` WHERE `id` IN (53341,53343);
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_chapter1_runeforging_credit';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(53323,'spell_chapter1_runeforging_credit'),
(53331,'spell_chapter1_runeforging_credit'),
(53341,'spell_chapter1_runeforging_credit'),
(53342,'spell_chapter1_runeforging_credit'),
(53343,'spell_chapter1_runeforging_credit'),
(53344,'spell_chapter1_runeforging_credit'),
(54446,'spell_chapter1_runeforging_credit'),
(54447,'spell_chapter1_runeforging_credit'),
(62158,'spell_chapter1_runeforging_credit'),
(70164,'spell_chapter1_runeforging_credit');

-- Already scripted.
DELETE FROM `spell_scripts` WHERE `id` IN (40904,44997);
