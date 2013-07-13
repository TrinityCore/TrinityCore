-- Fix quest A Dire Situation

DELETE FROM `creature_ai_scripts` WHERE `creature_id`=20058;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry`=20058;
DELETE FROM `smart_scripts` WHERE `entryorguid`=20058 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(20058, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 75, 18950, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On spawn - add aura Invisibility and Stealth Detection on self');

DELETE FROM `event_scripts` WHERE `id`=13584;
INSERT INTO `event_scripts` (`id`, `delay`, `command`, `datalong`) VALUES
(13584, 2, 8, 21176);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=36310;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,36310,0,31,1,3,20058,0,0,0,'', "Rina''s Diminution Powder can be used only on Bloodmaul Dire Wolf");
