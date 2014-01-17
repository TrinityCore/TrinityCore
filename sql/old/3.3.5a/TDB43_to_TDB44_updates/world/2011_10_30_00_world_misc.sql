-- trigger spawn X: 5672.294 Y: 2520.686 Z: 713.4386 O: 0.9599311 (21:01:58)
-- at 21:04:00 it casts 70663 (Shadownova) (when spellhit by 69922)
-- at 21:04:00 it casts 69956 (Return Tempered Quel'Delar) at player

UPDATE `creature_template` SET `faction_A`=190,`faction_H`=190,`baseattacktime`=2000,`unit_flags`=`unit_flags`|768,`flags_extra`=`flags_extra`|128,`AIName`='SmartAI' WHERE `entry`=37094; -- Crucible of Souls

UPDATE `creature_model_info` SET `bounding_radius`=1.25,`combat_reach`=2.5,`gender`=2 WHERE `modelid`=30822; -- Crucible of Souls

DELETE FROM `creature_template_addon` WHERE `entry`=37094;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(37094,0,0,1,0, '69859'); -- Crucible of Souls (Crucible of Souls Visual)

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=69922;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,0,69922,0,18,1,37094,0,0,'', 'Temper Quel''Delar - Crucible of Souls');

DELETE FROM `smart_scripts` WHERE `entryorguid`=37094 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(37094,0,0,1,8,0,0,0,69922,0,0,0,11,70663,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crucible of Souls - On spellhit by Temper Quel''Delar cast Shadownova'),
(37094,0,1,0,61,0,0,0,69922,0,0,0,11,69956,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Crucible of Souls - On spellhit by Temper Quel''Delar (link) cast Return Tempered Quel''Delar');
