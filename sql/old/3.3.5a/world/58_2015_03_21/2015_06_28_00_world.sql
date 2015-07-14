--
UPDATE `creature` SET `position_x`=1997.263,`position_y`=-3256.643, `position_z`=149.723,`orientation`=6.116 WHERE `guid`=105997;
UPDATE `creature` SET `position_x`=2091.723,`position_y`=-3245.161, `position_z`=161.245,`orientation`=3.312 WHERE `guid`=105998;
DELETE FROM `smart_scripts` WHERE `entryorguid`= -105997 AND `source_type`=0;
UPDATE  `smart_scripts` SET `event_param1`=43892, `action_type`=11, `target_type`=1, `target_param1`=0, `target_param2`=0  WHERE `entryorguid` IN (24439) AND `source_type`=0 AND `id`=1;
UPDATE  `smart_scripts` SET `action_type`=41, `action_param1`=0, `action_param2`=0  WHERE `entryorguid` IN (24439) AND `source_type`=0 AND `id`=4;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN (24439);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,2,24439,0,0, 29,0,15214,1,0,0,0,'','event 1 for 24439 require npc 15214 at 1 yard');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=43770;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(43770,43892,1,'Steel Gate Drop Off Check');

DELETE FROM `creature` WHERE `guid` IN (104706, 104705);
UPDATE `creature` SET `MovementType`=0, `spawndist`=0 WHERE `guid`=104704;
UPDATE `creature_template` SET `npcflag`=16777216 WHERE `entry`=24418;
