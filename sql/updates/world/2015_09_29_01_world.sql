-- 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=5 AND `SourceEntry`=27626;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 5, 27626, 0, 0, 31, 0, 4, 0, 0, 0, 0, 0, '', 'execute sai only if the player is the summoner');

UPDATE `creature_template` SET `npcflag`=16777216 WHERE `entry`=27626;
UPDATE `npc_spellclick_spells` SET `cast_flags`=1 WHERE `npc_entry`=27626 AND `spell_id`=49138;
DELETE FROM `smart_scripts` WHERE `entryorguid`=27626 AND `source_type`=0 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=27627 AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_phase_mask`=0 WHERE `entryorguid`=27626 AND `source_type`=0 AND `id`=4;
UPDATE `vehicle_template_accessory` SET `minion`=1, `summontype`=5, `summontimer`=0 WHERE `entry`=27626;

UPDATE `smart_scripts` SET `event_param1`=11000, `event_param2`=11000, `action_param1`=61647 WHERE `entryorguid`=2693500 AND `source_type`=9 AND `id`=3;
UPDATE `smart_scripts` SET `event_param1`=3000, `event_param2`=3000, `action_type`=51, `comment`="Anatoly - On Script - Kill self" WHERE `entryorguid`=2697100 AND `source_type`=9 AND `id`=10;
UPDATE `smart_scripts` SET `id`=11 WHERE `entryorguid`=2697100 AND `source_type`=9 AND `id`=10 AND `action_type`=51;
UPDATE `smart_scripts` SET `id`=10 WHERE `entryorguid`=2697100 AND `source_type`=9 AND `id`=9 AND `action_type`=69;
UPDATE `smart_scripts` SET `id`=9 WHERE `entryorguid`=2697100 AND `source_type`=9 AND `id`=8 AND `action_type`=45;
UPDATE `smart_scripts` SET `id`=8 WHERE `entryorguid`=2697100 AND `source_type`=9 AND `id`=7 and `action_type`=1;

DELETE FROM `smart_scripts` WHERE `entryorguid`IN (2697100) AND `source_type`=9 AND `id`= 7;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(2697100,9,7,0,0,0,100,0,0,0,0,0,51,0,0,0,0,0,0,19,27632,20,0,0,0,0,0,"Anatoly - On Script - Kill Tatjana");

DELETE FROM `smart_scripts` WHERE `entryorguid`IN (27626) AND `source_type`=0 AND `id`> 7;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(27626,0,8,9,61,0,100,0,0,0,0,0,11,49162,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tatjana's Horse - On Waypoint 19 Reached - Summon Tatjana"),
(27626,0,9,10,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,19,27627,20,0,0,0,0,0,"Tatjana's Horse - On Waypoint 19 Reached - Despawn"),
(27626,0,10,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tatjana's Horse - On Waypoint 19 Reached - Despawn");

DELETE FROM `smart_scripts` WHERE `entryorguid`IN (27627) AND `source_type`=0 AND `id`= 6;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(27627,0,6,0,8,0,100,0,49134,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tatjana - On Spellhit 'Tranquilizer Dart' - Stop Attack");

DELETE FROM `creature_template_addon` WHERE `entry`=27632;
INSERT INTO `creature_template_addon` (`entry`,`bytes1`,`bytes2`,`auras`) VALUES
(27632,0,0,"49135");
