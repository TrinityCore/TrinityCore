UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=31887;
DELETE FROM `smart_scripts` WHERE `entryorguid`=31887 AND `source_type`=0;
INSERT INTO `smart_scripts`(`entryorguid`,`id`,`link`,`event_type`,`event_param1`,`action_type`,`action_param1`,`action_param2`,`target_type`,`comment`) VALUES
(31887,0,1,8,59925,88,3188700,3188702,1,'Ebon Blade Marker - On spell hit of Construct Barricade - Call random actionlist'),
(31887,1,2,61,0,33,31887,0,7,'Ebon Blade Marker - On spell hit of Construct Barricade - Give quest credit'),
(31887,2,0,61,0,41,0,0,1,'Ebon Blade Marker - On spell hit of Construct Barricade - Despawn');

DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN 3188700 AND 3188702 AND `source_type`=9;
INSERT INTO `smart_scripts`(`entryorguid`,`source_type`,`action_type`,`action_param1`,`target_type`,`comment`) VALUES
(3188700,9,11,59922,1,'Ebon Blade Marker - Actionlist - Cast Summon Barricade A'),
(3188701,9,11,59923,1,'Ebon Blade Marker - Actionlist - Cast Summon Barricade B'),
(3188702,9,11,59924,1,'Ebon Blade Marker - Actionlist - Cast Summon Barricade C');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=59925;
INSERT INTO `conditions`(`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`Comment`) VALUE
(13,1,59925,31,3,31887,'Construct Barricade - Target must be Ebon Blade Marker');

UPDATE `creature_addon` INNER JOIN `creature` ON `creature`.`guid`=`creature_addon`.`guid` SET `auras`='59919' WHERE `id`=31887;
UPDATE `creature` SET `MovementType`=0,`spawndist`=0 WHERE `id`=31887;
