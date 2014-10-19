-- Kara Thricestar SAI
SET @ENTRY := 26602;
UPDATE `creature_template` SET `AIName`='SmartAI', ScriptName= '' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,4,0,100,0,0,0,0,0,12,9526,4,4,0,0,0,1,0,0,0,0,0,0,0,"Kara Thricestar - On Aggro - Summon Enraged Gryphon"),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,12,9526,4,4,0,0,0,1,0,0,0,0,0,0,0,"Kara Thricestar - On Aggro - Summon Enraged Gryphon"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kara Thricestar - On Aggro - Say Line 0"),
(@ENTRY,0,3,0,62,0,100,0,9683,1,0,0,11,51446,0,0,0,0,0,7,0,0,0,0,0,0,0,"Kara Thricestar - On gossip Option select - Cast Fizzcrank Airstrip to Dens of Dying Taxi");
-- Add Gossip Options
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (9683);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`) VALUES
(9683,1,0, 'Kara, I need to be flown out the Dens of Dying to find Bixie.',1,1,0);
-- Add Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9683 AND `SourceEntry`=1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,9683,1,0,0,28,0,11692,0,0,0,0,0, '', 'Gossip Option - Show Option if Player has completed quest 11692');

-- Update Wintergrasp Battle-Mage cpp to remove SmartAI
UPDATE `creature_template` SET `AIName`='' WHERE `entry` IN (32169,32170,35596,35597,35598,35599,35600,35601,35602,35603,35611,35612);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (32169,32170,35596,35597,35598,35599,35600,35601,35602,35603,35611,35612) AND `source_type`=0;
