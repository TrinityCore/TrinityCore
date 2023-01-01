-- There is a chance it was added in Cata but in that case gossip menu too was added in Cata since gossip
-- text id is 33066 and gossip option id is 33065. So both should be added or both should be removed
DELETE FROM `gossip_menu_option` WHERE `MenuID` = 10219;
INSERT INTO `gossip_menu_option` (`MenuID`,`OptionID`,`OptionIcon`,`OptionText`,`OptionBroadcastTextID`,`OptionType`,`OptionNpcFlag`,`ActionMenuID`,`ActionPoiID`,`BoxCoded`,`BoxMoney`,`BoxText`,`BoxBroadcastTextID`,`VerifiedBuild`) VALUES
(10219,0,0,"Place Avruu's Orb on the altar.",33065,1,0,0,0,0,0,"",0,14007);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 10219;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,10219,0,0,0,47,0,9418,10,0,0,0,0,"","Group 0: Show Gossip Option 0 if quest 'Avruu's Orb' is taken");

UPDATE `smart_scripts` SET `target_x` = -1323.9098, `target_y` = 4042.4487, `target_z` = 116.62573, `target_o` = 0.296705961227416992 WHERE `entryorguid` = 181606 AND `source_type` = 1 AND `id` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 181606 AND `source_type` = 1 AND `id` > 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(181606,1,1,2,62,0,100,0,10219,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Haal'eshi Altar - On Gossip Option 0 Selected - Store Targetlist"),
(181606,1,2,3,61,0,100,0,0,0,0,0,0,100,1,0,0,0,0,0,19,17085,0,0,0,0,0,0,0,"Haal'eshi Altar - On Link - Send Target 1 (Aeranas)"),
(181606,1,3,4,61,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,19,17085,0,0,0,0,0,0,0,"Haal'eshi Altar - On Link - Set Data 0 1 (Aeranas)"),
(181606,1,4,0,61,0,100,0,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Haal'eshi Altar - On Link - Close Gossip");

UPDATE `creature_text` SET `comment` = "Aeranas" WHERE `CreatureID` = 17085;
UPDATE `creature_template` SET `speed_walk` = 1.4, `speed_run` = 1.42857142857, `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 17085;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 17085 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1708500,1708501,1708502) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(17085,0,0,0,63,0,100,0,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Aeranas - On Just Created - Remove NPC Flag Questgiver"),
(17085,0,1,0,63,0,100,0,0,0,0,0,0,42,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Aeranas - On Just Created - Set Invincibility HP 1"),
(17085,0,2,0,0,0,100,0,5000,5000,10000,10000,0,11,12553,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Aeranas - In Combat - Cast 'Shock'"),
(17085,0,3,0,0,0,100,0,9000,9000,25000,25000,0,11,15535,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Aeranas - In Combat - Cast 'Enveloping Winds'"),

(17085,0,4,0,38,0,100,257,0,1,0,0,0,80,1708500,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Aeranas - On Data Set 0 1 - Run Script (No Repeat) (No Reset)"),

(1708500,9,0,0,0,0,100,0,2000,2000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Aeranas - On Script - Say Line 0"),
(1708500,9,1,0,0,0,100,0,6000,6000,0,0,0,2,14,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Aeranas - On Script - Set Faction 14"),
(1708500,9,2,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Aeranas - On Script - Start Attack Stored Target 1"),

(17085,0,5,0,2,0,100,1,0,30,0,0,0,80,1708501,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Aeranas - Between 0-30% Health - Run Script (No Repeat)"),
-- This part should be more complex
(1708501,9,0,0,0,0,100,0,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Aeranas - On Script - Set Event Phase 1"),
(1708501,9,1,0,0,0,100,0,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Aeranas - On Script - Set Faction 35"),
(1708501,9,2,0,0,0,100,0,0,0,0,0,0,27,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Aeranas - On Script - Stop Combat"),

(17085,0,6,0,21,1,100,0,0,0,0,0,0,80,1708502,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Aeranas - On Reached Home - Run Script (Phase 1)"),

(1708502,9,0,0,0,0,100,0,2000,2000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Aeranas - On Script - Say Line 1"),
(1708502,9,1,0,0,0,100,0,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Aeranas - On Script - Add NPC Flag Questgiver");
