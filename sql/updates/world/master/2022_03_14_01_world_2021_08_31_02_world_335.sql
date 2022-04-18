--
UPDATE `gameobject_template` SET `AIName` = 'SmartGameObjectAI' WHERE `entry` = 181054;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 181054 AND `source_type` = 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(181054,1,0,0,60,0,100,0,1000,1000,3000,3000,0,11,27420,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ectoplasmic Distiller Trap - On Update - Cast 'Ectoplasmic Distiller'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 1 AND `SourceEntry` IN (21937,21936,21935);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(1,12178,21937,0,0,1,0,27420,0,0,0,0,0,'',"Group 0: Item 'Scorched Ectoplasm' can be looted if player has aura 'Ectoplasmic Distiller'"),
(1,12179,21937,0,0,1,0,27420,0,0,0,0,0,'',"Group 0: Item 'Scorched Ectoplasm' can be looted if player has aura 'Ectoplasmic Distiller'"),
(1,7523,21936,0,0,1,0,27420,0,0,0,0,0,'',"Group 0: Item 'Frozen Ectoplasm' can be looted if player has aura 'Ectoplasmic Distiller'"),
(1,7524,21936,0,0,1,0,27420,0,0,0,0,0,'',"Group 0: Item 'Frozen Ectoplasm' can be looted if player has aura 'Ectoplasmic Distiller'"),
(1,8538,21935,0,0,1,0,27420,0,0,0,0,0,'',"Group 0: Item 'Stable Ectoplasm' can be looted if player has aura 'Ectoplasmic Distiller'"),
(1,8539,21935,0,0,1,0,27420,0,0,0,0,0,'',"Group 0: Item 'Stable Ectoplasm' can be looted if player has aura 'Ectoplasmic Distiller'"),
(1,8540,21935,0,0,1,0,27420,0,0,0,0,0,'',"Group 0: Item 'Stable Ectoplasm' can be looted if player has aura 'Ectoplasmic Distiller'"),
(1,8541,21935,0,0,1,0,27420,0,0,0,0,0,'',"Group 0: Item 'Stable Ectoplasm' can be looted if player has aura 'Ectoplasmic Distiller'"),
(1,8542,21935,0,0,1,0,27420,0,0,0,0,0,'',"Group 0: Item 'Stable Ectoplasm' can be looted if player has aura 'Ectoplasmic Distiller'");
