-- Add gossip texts to menu
DELETE FROM `gossip_menu_option` WHERE `menu_id` = 8718;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES
(8718, 0, 0, 'Yes, I''d love a ride to Blackwind Landing.',21550,1,1,0,0,0,0,'',0);

DELETE FROM `npc_text` WHERE `ID` = 10977;
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `BroadcastTextID0`, `lang0`, `Probability0`, `em0_0`, `em0_1`, `em0_2`, `em0_3`, `em0_4`, `em0_5`) VALUES
(10977, '', 'Hey, comrade.  If you get yourself in good with the Skyguard, I can offer you a direct flight to our base, Blackwind Landing, in the Skethyl Mountains.$B$BDo you like my beautiful nether ray?  It is lovely.', 21547, 0, 1, 0, 1, 0, 6, 0, 0);
-- Other npc_text (10978) is already set in DB

-- Migrate NPC to use SmartAI
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 23413;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14, 15) AND `SourceGroup` = 8718;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,8718,10977,0,0,5,0,1031,224,0,1,0,'','Skyguard Handler Irena - Show gossip menu text below Honored reputation with faction 1031'),
(14,8718,10978,0,0,5,0,1031,224,0,0,0,'','Skyguard Handler Irena - Show gossip menu text above Honored reputation with faction 1031'),
(15,8718,0,0,0,5,0,1031,224,0,0,0,'','Skyguard Handler Irena - Show gossip option 0 if player has reputation Honored or above with faction 1031');

-- Create SmartAI for Skyguard Handler Irena
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 23413);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23413,0,0,1,62,0,100,0,8718,0,0,0,11,41278,0,0,0,0,0,7,0,0,0,0,0,0,0,'Skyguard Handler Irena - On Gossip Option 0 Selected - Cast Spell 41278'),
(23413,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Skyguard Handler Irena - On Linked Actions - Close Gossip');
