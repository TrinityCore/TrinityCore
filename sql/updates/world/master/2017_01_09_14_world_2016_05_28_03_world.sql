UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry`=22139;
UPDATE `smart_scripts` SET `target_param1`=22139, `target_param2`=100, `action_param2`=64 WHERE `entryorguid`=22138 AND `source_type`=0 AND `id`=0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=38469 AND `ElseGroup`=0;
DELETE FROM `gameobject` WHERE `id`=184750;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (22137);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (22137) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (22138) AND `source_type`=0 AND id IN(1,2);

INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(22137, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 75, 38457, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Summoned Old God - On reset - Add Transparency'),
(22137, 0, 1, 0, 1, 8, 100, 0, 0, 0, 240000, 240000, 50, 184750, 240, 0, 0, 0, 0, 8, 0, 0, 0, -4161.259277, 1985.773804, 59.094448, 6.210211,'Summoned Old God - OOC (Phase 4) - spawn spell focus'),
(22137, 0, 2, 0, 38, 0, 100, 0, 1, 1, 0, 0, 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,'Summoned Old God - On Data Set 1 1 - Increment Phase'),
(22137, 0, 3, 0, 38, 0, 100, 0, 2, 2, 0, 0, 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,'Summoned Old God - On Data Set 2 2 - Set Phase 0'),
(22137, 0, 4, 0, 11, 0, 100, 0, 0, 0, 0, 0, 48, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,'Summoned Old God - On Spawn Set Active'),
(22137, 0, 5, 6, 8, 0, 100, 0, 38482, 0, 0, 0, 33, 22137, 0, 0, 0, 0, 0, 16, 0, 0, 0, 0, 0, 0, 0,'Summoned Old God - On Spellhit - Give Kill Credit'),
(22137, 0, 6, 7, 61, 0, 0, 0, 0, 0, 0, 0, 11, 37281, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,'Summoned Old God - On Spellhit - Cast Infernal Oversouls Wrath'),
(22137, 0, 7, 8, 61, 0, 0, 0, 0, 0, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 19, 22146, 0, 0, 0, 0, 0, 0,'Summoned Old God - On Spellhit - Despawn Summoning Voidstorm'),
(22138, 0, 1, 0, 6, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 22137, 100, 0, 0, 0, 0,0,'Dark Conclave Ritualist - On Death - Set Data'),
(22138, 0, 2, 0, 11, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 19, 22137, 100, 0, 0, 0, 0,0,'Dark Conclave Ritualist - On Respawn - Set Data');

DELETE FROM `conditions` WHERE  `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=37281 AND `SourceId`=0 AND `ElseGroup`IN(2,3);

INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 37281, 0, 2, 31, 0, 3, 22137, 0, 0, 0, 0, '', 'Infernal Oversouls Wrath targets Summoned Old God'),
(13, 1, 37281, 0, 3, 31, 0, 3, 22146, 0, 0, 0, 0, '', 'Infernal Oversouls Wrath targets Summoning Voidstorm');
