DELETE FROM `smart_scripts` WHERE `entryorguid` IN (33974) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(33974,0,0,2,62,0,100,0,10402,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Valis Windchaser - Say text when option clicked'),
(33974,0,1,2,62,0,100,0,10401,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Valis Windchaser - ay text when option clicked'),
(33974,0,2,3,61,0,100,0,0,0,0,0,11,64115,0,0,0,0,0,7,0,0,0,0,0,0,0,'Valis Windchaser - Give Credit'),
(33974,0,3,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Valis Windchaser - Close Gossip');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN (33974);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=10402 AND `SourceEntry` IN (14438,14453);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`, `NegativeCondition`) VALUES
(14,10402,14438,0,0,1,63034,0,0,0,'','Valis Windchaser show different menu if player mounted',0),
(14,10402,14438,0,0,9,13838,0,0,0,'','Valis Windchaser show different menu if player has the quest',0),
(14,10402,14438,0,1,1,63034,0,0,0,'','Valis Windchaser show different menu if player mounted',0),
(14,10402,14438,0,1,9,13835,0,0,0,'','Valis Windchaser show different menu if player has the quest',0),
(14,10402,14453,0,0,1,63034,0,0,0,'','Valis Windchaser show different menu if player mounted',1),
(14,10402,14453,0,0,9,13838,0,0,0,'','Valis Windchaser show different menu if player has the quest',1),
(14,10402,14453,0,1,1,63034,0,0,0,'','Valis Windchaser show different menu if player mounted',1),
(14,10402,14453,0,1,9,13835,0,0,0,'','Valis Windchaser show different menu if player has the quest',1);


DELETE FROM `smart_scripts` WHERE `entryorguid` IN (33972) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(33972,0,0,2,62,0,100,0,10400,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Rugan Steelbelly - Send text when option clicked'),
(33972,0,1,2,62,0,100,0,10399,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Rugan Steelbelly - Send text when option clicked'),
(33972,0,2,3,61,0,100,0,0,0,0,0,11,64114,0,0,0,0,0,7,0,0,0,0,0,0,0,'Rugan Steelbelly - Give Credit'),
(33972,0,3,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Rugan Steelbelly - Close Gossip');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN (33972);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=10400 AND `SourceEntry` IN (14436,14455);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`, `NegativeCondition`) VALUES
(14,10400,14436,0,0,1,63034,0,0,0,'','Rugan Steelbelly show different menu if player mounted',0),
(14,10400,14436,0,0,9,13839,0,0,0,'','Rugan Steelbelly show different menu if player has the quest',0),
(14,10400,14436,0,1,1,63034,0,0,0,'','Rugan Steelbelly show different menu if player mounted',0),
(14,10400,14436,0,1,9,13837,0,0,0,'','Rugan Steelbelly show different menu if player has the quest',0),
(14,10400,14455,0,0,1,63034,0,0,0,'','Rugan Steelbelly show different menu if player mounted',1),
(14,10400,14455,0,0,9,13839,0,0,0,'','Rugan Steelbelly show different menu if player has the quest',1),
(14,10400,14455,0,1,1,63034,0,0,0,'','Rugan Steelbelly show different menu if player mounted',1),
(14,10400,14455,0,1,9,13837,0,0,0,'','Rugan Steelbelly show different menu if player has the quest',1);


DELETE FROM `smart_scripts` WHERE `entryorguid` IN (33973) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(33973,0,0,2,62,0,100,0,10398,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Jeran Lockwood  - Send text when option clicked'),
(33973,0,1,2,62,0,100,0,10397,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Jeran Lockwood  - Send text when option clicked'),
(33973,0,2,3,61,0,100,0,0,0,0,0,11,64113,0,0,0,0,0,7,0,0,0,0,0,0,0,'Jeran Lockwood  - Give Credit'),
(33973,0,3,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Jeran Lockwood  - Close Gossip');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN (33973);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=10398 AND `SourceEntry` IN (14431,14453);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`, `NegativeCondition`) VALUES
(14,10398,14431,0,0,1,63034,0,0,0,'','Jeran Lockwood show different menu if player mounted',0),
(14,10398,14431,0,0,9,13828,0,0,0,'','Jeran Lockwood show different menu if player has the quest',0),
(14,10398,14431,0,1,1,63034,0,0,0,'','Jeran Lockwood show different menu if player mounted',0),
(14,10398,14431,0,1,9,13829,0,0,0,'','Jeran Lockwood show different menu if player has the quest',0),
(14,10398,14453,0,0,1,63034,0,0,0,'','Jeran Lockwood show different menu if player mounted',1),
(14,10398,14453,0,0,9,13828,0,0,0,'','Jeran Lockwood show different menu if player has the quest',1),
(14,10398,14453,0,1,1,63034,0,0,0,'','Jeran Lockwood show different menu if player mounted',1),
(14,10398,14453,0,1,9,13829,0,0,0,'','Jeran Lockwood show different menu if player has the quest',1);
