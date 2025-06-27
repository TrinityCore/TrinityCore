-- Susurrus
-- Add sniffed gossip text to menu
DELETE FROM `gossip_menu_option` WHERE `menu_id`  = 7415;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES
(7415, 0, 0, 'I am ready to be flown down to the Exodar.',14010,1,1,0,0,0,0,'',0);

DELETE FROM `npc_text` WHERE `ID` = 8955;
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `BroadcastTextID0`, `lang0`, `Probability0`, `em0_0`, `em0_1`, `em0_2`, `em0_3`, `em0_4`, `em0_5`) VALUES
(8955, 'Are you ready, $n?', '', 14012, 0, 1, 0, 0, 0, 0, 0, 0);

-- Set second gossip in gossip menu
DELETE FROM `gossip_menu` WHERE `entry` = 7415;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(7415, 8954),
(7415, 8955);

-- Migrate NPC to use SmartAI
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 17435;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14, 15) AND `SourceGroup` = 7415;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,7415,8954,0,0,2,0,23843,1,0,1,0,'','Susurrus - Show gossip menu text if player does not have item 23843 in inventory'),
(14,7415,8955,0,0,2,0,23843,1,0,0,0,'','Susurrus - Show gossip menu text if player has item 23843 in inventory'),
(15,7415,0,0,0,2,0,23843,1,0,0,0,'','Susurrus - Show gossip option 0 if player has item 23843 in inventory');

-- Create SmartAI for Susurrus
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 17435);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(17435,0,0,1,62,0,100,0,7415,0,0,0,11,32474,0,0,0,0,0,7,0,0,0,0,0,0,0,'Susurrus - On Gossip Option 0 Selected - Cast Spell 32474'),
(17435,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Susurrus - On Linked Actions - Close Gossip');


-- Protectorate Nether Drake
-- Add sniffed gossip text to menu
DELETE FROM `gossip_menu_option` WHERE `menu_id`  = 8229;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES
(8229, 0, 0, 'I''m ready to fly! Take me up, dragon!',18637,1,1,0,0,0,0,'',0);

-- Migrate NPC to use SmartAI
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 20903;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 8229;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,8229,0,0,0,2,0,29778,1,0,0,0,'','Protectorate Nether Drake - Show gossip option 0 if player has item 23843 in inventory'),
(15,8229,0,0,0,9,0,10438,0,0,0,0,'','Protectorate Nether Drake - Show gossip option 0 if player has quest 10438');
-- Create SmartAI for Protectorate Nether Drake
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 20903);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(20903,0,0,1,62,0,100,0,8229,0,0,0,52,627,0,0,0,0,0,7,0,0,0,0,0,0,0,'Protectorate Nether Drake - On Gossip Option 0 Selected - Init Taxi Path 627'),
(20903,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Protectorate Nether Drake - On Linked Actions - Close Gossip');


-- Veronia
-- Add sniffed gossip text to menu
DELETE FROM `gossip_menu_option` WHERE `menu_id`  = 8082;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES
(8082, 0, 0, 'I''m as ready as I''ll ever be.',17761,1,1,0,0,0,0,'',0);

DELETE FROM `gossip_menu` WHERE `entry` = 8082;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(8082, 9989),
(8082, 9990);

-- Migrate NPC to use SmartAI
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 20162;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup` = 8082;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,8082,9989,0,0,28,0,10652,0,0,1,0,'','Veronia - Show gossip menu text if player does not have quest 10652'),
(14,8082,9990,0,0,28,0,10652,0,0,0,0,'','Veronia - Show gossip menu text if player has quest 10652'),
(15,8082,0,0,0,28,0,10652,0,0,0,0,'','Veronia - Show gossip option 0 if player has quest 10652');
-- Create SmartAI for Veronia
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 20162);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(20162,0,0,1,62,0,100,0,8082,0,0,0,85,34905,0,0,0,0,0,7,0,0,0,0,0,0,0,'Veronia - On Gossip Option 0 Selected - Invoker Cast \'Stealth Flight\''),
(20162,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Veronia - On Linked Actions - Close Gossip');


-- Cassa Crimsonwing
-- Add sniffed gossip text to menu
DELETE FROM `gossip_menu_option` WHERE `menu_id` = 8782;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES
(8782, 0, 0, 'Lady Jaina told me to speak to you about using a gryphon to survey Alcaz Island.',22176,1,1,0,0,0,0,'',0);

-- Migrate NPC to use SmartAI
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 23704;

-- Condition: Gossip menu ID 0 needs quest ID 11142 to be incomplete.
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 15 AND `SourceGroup` = 8782 AND `SourceEntry` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,8782,0,0,0,9,0,11142,0,0,0,0,'','Cassa Crimsonwing - Show gossip option 0 if player has taken quest ID 11142');

-- Create SmartAI for Cassa Crimsonwing
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 23704);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23704,0,0,1,62,0,100,0,8782,0,0,0,11,42295,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cassa Crimsonwing - On Gossip Option 0 Selected - Cast Spell 42295'),
(23704,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cassa Crimsonwing - On Linked Actions - Close Gossip');


-- Brazen
-- Add sniffed gossip text to menu
DELETE FROM `gossip_menu_option` WHERE `menu_id` = 7959;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES
(7959, 0, 0, 'I''m ready to go to Durnholde Keep.',16461,1,1,0,0,0,0,'',0);

DELETE FROM `gossip_menu` WHERE `entry` = 7959;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(7959, 9779),
(7959, 9780);

UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 18725;

-- Condition: On gossip menu click, if item exists, perform linked action 
-- Condition: On gossip menu click, if item exists, perform linked action
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`IN (14, 15) AND `SourceGroup` = 7959;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,7959,9779,0,0,2,0,25853,1,0,0,0,'','Brazen - Show gossip menu text if player has item 25853'),
(14,7959,9780,0,0,2,0,25853,1,0,1,0,'','Brazen - Show gossip menu text if player does not have item 25853'),
(15,7959,0,0,0,2,0,25853,1,0,0,0,'','Brazen - Show gossip option 0 if player has item 25853');

-- Create SmartAI for Brazen
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 18725);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(18725,0,0,1,62,0,100,0,7959,0,0,0,52,534,0,0,0,0,0,7,0,0,0,0,0,0,0,'Brazen - On Gossip Option 0 Selected - Activate Taxi Path 534'),
(18725,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Brazen - On Linked Actions - Close Gossip');
