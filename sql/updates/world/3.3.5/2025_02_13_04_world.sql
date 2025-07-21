-- Quest "The Completed Robe" Intro 

-- Quest flag
UPDATE `quest_template_addon` SET `SpecialFlags`=`SpecialFlags`|2 WHERE `ID`=4786;

-- Menara Voidrender Script
DELETE FROM `smart_scripts` WHERE `entryorguid`=626601 AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6266 AND `id` IN (2,3);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES

(6266,0,2,3,19,0,100,0,4786,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Menara Voidrender - On Quest 'The Completed Robe' Taken - Store Targetlist"),
(6266,0,3,0,61,0,100,0,0,0,0,0,0,80,626601,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Menara Voidrender - On Link - Run Script"),

-- Menara Voidrender Timed List 1
(626601,9,0,0,0,0,100,0,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Menara Voidrender - On Script - Remove Npc Flag Questgiver+Gossip"),
(626601,9,1,0,0,0,100,0,1000,1000,0,0,0,11,16633,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Menara Voidrender - On Script - Cast 'Create Item Visual'"),
(626601,9,2,0,0,0,100,0,7000,7000,0,0,0,15,4786,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Menara Voidrender - On Script - Complete Quest"),
(626601,9,3,0,0,0,100,0,0,0,0,0,0,82,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Menara Voidrender - On Script - Add Npc Flag Questgiver+Gossip");
