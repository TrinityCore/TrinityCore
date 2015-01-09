-- Assign SmartGameObjectAI
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI',`ScriptName`='' WHERE `entry`=181606;

-- SmartGameObjectAI for summoning Aeranas at Haaleshi Altar
DELETE FROM `smart_scripts` WHERE `entryorguid`=181606 AND `source_type`=1;
INSERT INTO `smart_scripts`(`entryorguid`,`source_type`,`id`,`event_type`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`target_type`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(181606,1,0,64,12,17085,4,60000,8,-1321.79,4043.8,116.24,1.25,'Haaleshi Altar - On gossip hello - Summon Aeranas');

-- Aeranas should only be summonened if there is not already one in range
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=181606 AND `SourceId`=1;
INSERT INTO `conditions`(`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`NegativeCondition`,`Comment`) VALUES 
(22,1,181606,1,29,1,17085,50,1,'Haaleshi Altar - Only summon Aeranas if there is not already one in range'),
(22,1,181606,1,28,0,9418,0,0,'Haaleshi Altar - Only summon Aeranas if invoker has completed quest Avruus Orb (Is auto-completed)'); 
