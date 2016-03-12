--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=16 AND `SourceEntry`=4163;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(16,0,26813,0,0,23,0,4163,0,0,0,0,'','Dismount player from Kor''kron War Rider when not in intended zone(Icemist Village)');

UPDATE `creature_template` SET `InhabitType`=5, `npcflag`=16777216 WHERE `entry`=26813;
DELETE FROM `creature_template_addon` WHERE `entry`=26813;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(26813, 0, 0, 33554432, 0, 0, '55971');
