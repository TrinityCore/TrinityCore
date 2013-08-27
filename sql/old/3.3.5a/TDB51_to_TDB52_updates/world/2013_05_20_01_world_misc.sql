-- Prevent multiple template installation tries
UPDATE `smart_scripts` SET `event_type`=37 WHERE `entryorguid` IN (474,881,26257) AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_type`=37 WHERE `entryorguid` IN (18716,18719) AND `source_type`=0 AND `id`=1;

-- Remove not existing event links
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid`=61 AND `id`=0 AND `source_type`=1;
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid`=3594 AND `id`=0 AND `source_type`=0;
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid`=1399 AND `id`=3 AND `source_type`=0;
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid`=305400 AND `id`=0 AND `source_type`=9;

-- Convert EAI to SAI and add conditions to prevent multiple SMART_ACTION_UPDATE_TEMPLATE calls
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=20778;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=20778;

DELETE FROM `smart_scripts` WHERE `entryorguid`=20778 AND `source_type`=0;
INSERT INTO `smart_scripts`(`entryorguid`,`id`,`event_type`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`target_type`,`comment`) VALUES
(20778,0,0,2000,6000,7000,10000,11,36519,32,5,'Void Waste - Cast Toxic Burst'),
(20778,1,8,35686,0,0,0,36,20805,0,1,'Void Waste - Change Entry after (proc) Spell 35686');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=2 AND `SourceEntry`=20778 AND `SourceId`=0;
INSERT INTO `conditions`(`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ConditionTarget`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`NegativeCondition`,`Comment`) VALUE
(22,2,20778,0,1,31,3,20805,1,'Void Waste may not already be transformed to template entry 20805 when trying to update template to 20805');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=20501;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=20501;

DELETE FROM `smart_scripts` WHERE `entryorguid`=20501 AND `source_type`=0;
INSERT INTO `smart_scripts`(`entryorguid`,`id`,`event_type`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`target_type`,`comment`) VALUES
(20501,0,2,0,50,30000,45000,11,36465,0,1,'Seeping Sludge - Cast Seeping Split at 50% HP'),
(20501,1,8,35686,0,0,0,36,20806,0,1,'Seeping Sludge - Change Entry after (proc) Spell 35686'),
(20501,2,11,0,0,0,0,11,35242,0,1,'Seeping Sludge - Darkstalker Birth');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=2 AND `SourceEntry`=20501 AND `SourceId`=0;
INSERT INTO `conditions`(`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ConditionTarget`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`NegativeCondition`,`Comment`) VALUE
(22,2,20501,0,1,31,3,20805,1,'Seeping Sludge may not already be transformed to template entry 20806 when trying to update template to 20806');
