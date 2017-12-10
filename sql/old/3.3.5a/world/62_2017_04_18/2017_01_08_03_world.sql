-- 
UPDATE `gameobject_template` SET `Data0`=1505 WHERE `entry`=188112;
DELETE FROM `gameobject_template` WHERE `entry`=300184;
DELETE FROM `gameobject` WHERE `id`=300184;
SET @ENTRY := 26161;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,1,46574,0,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Farshire Grain Credit - On Spellhit 'Burn Grain' - Action list"),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,33,26161,0,0,0,0,0,7,0,0,0,0,0,0,0,"Farshire Grain Credit - Action list - Quest Credit 'Take No Chances'"),
(@ENTRY*100,9,1,0,0,0,100,0,5000,5000,0,0,99,3,0,0,0,0,0,20,188112,10,0,0,0,0,0,"Farshire Grain Credit - Action list - Set loot state to Despawn gob"),
(@ENTRY*100,9,2,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Farshire Grain Credit - Action list - Despawn");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=46574;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 3, 46574, 0, 0, 31, 0, 3, 26161, 0, 0, 0, 0, '', 'Spell effect on Farshire Grain Credit');
