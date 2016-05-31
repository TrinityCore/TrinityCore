UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`='' WHERE `entry`=28877;

DELETE FROM `creature_ai_scripts` WHERE `creature_id`=28877;

DELETE FROM `smart_scripts` WHERE `entryorguid`=28877 AND `source_type`=0;
INSERT INTO `smart_scripts`(`entryorguid`,`id`,`link`,`event_type`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`target_type`,`comment`) VALUES
(28877,0,0,0,3000,5000,3000,5000,11,32018,2,'Stormwatcher - In combat - Cast Call Lightning'),
(28877,1,2,8,53145,0,0,0,11,53162,1,'Stormwatcher - On spellhit - Summon Stormwatchers Head'),
(28877,2,0,61,0,0,0,0,41,0,1,'Stormwatcher - Linked with id 1 - Despawn');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=53145;
INSERT INTO `conditions`(`SourceTypeOrReferenceId`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`NegativeCondition`,`Comment`) VALUES
(17,53145,31,1,3,28877,0,'Target needs to be Stormwatcher'),
(17,53145,36,1,0,0,1,'Target needs to be dead');
