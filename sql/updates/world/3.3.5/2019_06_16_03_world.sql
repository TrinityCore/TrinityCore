-- 
UPDATE `spell_dbc` SET `RangeIndex`=1, `EffectImplicitTargetA1`=18, `EffectImplicitTargetA2`=18, `EffectRadiusIndex1`=0, `EffectRadiusIndex2`=0 WHERE `id` IN (11756);
UPDATE `spell_dbc` SET `RangeIndex`=1, `EffectImplicitTargetA1`=18, `EffectRadiusIndex1`=0, `EffectRadiusIndex2`=0 WHERE `id` IN (19394);

UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry` IN (144064);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (144064) AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(144064,1,0,0,70,0,100,0,3,0,0,0,41,0,0,0,0,0,0,20,177683,4,0,0,0,0,0, "Gordunni Dirt Mound - In loot state 3 - Despawn visual gob");

UPDATE `smart_scripts` SET `event_param2`=0 WHERE `entryorguid`=17214 AND `source_type`=0 AND `id`=1;
UPDATE `smart_scripts` SET `event_param2`=0 WHERE `entryorguid`=17215 AND `source_type`=0 AND `id`=4;
UPDATE `smart_scripts` SET `event_param2`=0 WHERE `entryorguid`=32423 AND `source_type`=0 AND `id`=0;
