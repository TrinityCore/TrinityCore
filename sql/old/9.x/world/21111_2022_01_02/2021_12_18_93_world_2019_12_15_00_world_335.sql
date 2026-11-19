-- 
UPDATE `creature` SET `position_z`=12.259 WHERE `id`=23907;
UPDATE `smart_scripts` SET  `event_param1`=16000,`event_param2`=16000 WHERE `entryorguid`=23900 AND `source_type`=0 AND `id`=2;
UPDATE `smart_scripts` SET  `action_param1`=768 WHERE `entryorguid`=2389900 AND `source_type`=9 AND `id`=2;
UPDATE `smart_scripts` SET  `action_param1`=768 WHERE `entryorguid`=23899 AND `source_type`=0 AND `id`=2;
UPDATE `creature_template_movement` SET `Ground`=1 WHERE `CreatureID`=23899;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (23899) AND `source_type`=0 AND `id`=5;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(23899,0,5,0,40,0,100,0,1,23899,0,0,103,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tethyr - Waypoint reached - Root');
UPDATE `creature_template` SET `flags_extra`=64 WHERE `entry` IN (23899);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=42578;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition` ,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,42578,0,0,31,0,3,23907,0,0,0,'','Cannon Blast');

DELETE FROM `creature_template_addon` WHERE `entry`=23900;
INSERT INTO `creature_template_addon` (`entry`, `bytes2`, `emote`) VALUES (23900,2,384);

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 42578;
DELETE FROM `spell_script_names` WHERE `ScriptName`="spell_gen_cannon_blast";
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(42578, "spell_gen_cannon_blast");
