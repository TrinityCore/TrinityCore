UPDATE creature_template SET npcflag=3,ainame='SmartAI' WHERE entry=171789;
UPDATE creature_template SET npcflag=1,ainame='SmartAI' WHERE entry=176554;
UPDATE creature_template SET npcflag=3 WHERE entry=169076;

replace into creature_queststarter (id, quest) values
(171789,60545);

replace into creature_questender (id, quest) values
(169076,60545),
(169076,61874);

replace into smart_scripts (entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, event_param5, event_param_string, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_param1, target_param2, target_param3, target_x, target_y, target_z, target_o, comment) values
('171789','0','0','0','64','0','100','0','0','0','0','0','0','','33','171789','0','0','0','0','0','7','0','0','0','0','0','0','0','Primera mision SL, NPCs'),
('176554','0','0','0','64','0','100','0','0','0','0','0','0','','33','176554','0','0','0','0','0','7','0','0','0','0','0','0','0','Primera mision SL, NPCs'),
('171039','0','0','0','73','0','100','1','0','0','0','0','0','','33','171039','0','0','0','0','0','7','0','0','0','0','0','0','0','Portal Archerus - killcredit 171039'),
('170749','0','0','0','73','0','100','1','0','0','0','0','0','','33','170749','0','0','0','0','0','7','0','0','0','0','0','0','0','icc 9.0.2 - killcredit 170749');


replace  into `creature_template`(`entry`,`difficulty_entry_1`,`difficulty_entry_2`,`difficulty_entry_3`,`KillCredit1`,`KillCredit2`,`name`,`femaleName`,`subname`,`TitleAlt`,`IconName`,`gossip_menu_id`,`minlevel`,`maxlevel`,`HealthScalingExpansion`,`RequiredExpansion`,`VignetteID`,`faction`,`npcflag`,`speed_walk`,`speed_run`,`scale`,`rank`,`dmgschool`,`BaseAttackTime`,`RangeAttackTime`,`BaseVariance`,`RangeVariance`,`unit_class`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`family`,`trainer_class`,`type`,`type_flags`,`type_flags2`,`lootid`,`pickpocketloot`,`skinloot`,`resistance1`,`resistance2`,`resistance3`,`resistance4`,`resistance5`,`resistance6`,`spell1`,`spell2`,`spell3`,`spell4`,`spell5`,`spell6`,`spell7`,`spell8`,`VehicleId`,`mingold`,`maxgold`,`AIName`,`MovementType`,`InhabitType`,`HoverHeight`,`HealthModifier`,`HealthModifierExtra`,`ManaModifier`,`ManaModifierExtra`,`ArmorModifier`,`DamageModifier`,`ExperienceModifier`,`RacialLeader`,`movementId`,`WidgetSetID`,`WidgetSetUnitConditionID`,`RegenHealth`,`mechanic_immune_mask`,`flags_extra`,`ScriptName`,`VerifiedBuild`) values 
(171789,0,0,0,0,0,'High Inquisitor Whitemane','','Horseman of the Ebon Blade',NULL,NULL,0,1,1,7,0,0,35,3,1,1.14286,1,0,0,0,0,1,1,2,0,0,0,0,0,0,7,4096,67125248,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'SmartAI',0,3,1,15,1,1,1,1,1,1,0,0,0,0,1,0,0,'',36949),
(176554,0,0,0,0,0,'Highlord Darion Mograine','','Horseman of the Ebon Blade',NULL,NULL,0,60,60,7,0,0,35,1,1,1.14286,1,1,0,0,0,1,1,2,0,0,0,0,0,0,7,0,16384,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'SmartAI',0,3,1,25,1,25,1,1,1,1,0,0,0,0,1,0,0,'',36949);


replace  into `creature`(`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnDifficulties`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) values 
(6000000000046949,171789,0,0,0,'0',0,0,0,-1,0,0,-8489.23,387.079,115.845,2.10871,300,0,0,409,0,0,0,0,0,0,0,'',0),
(6000000000046950,176554,0,0,0,'0',0,0,0,-1,0,0,-8486.96,388.907,115.846,2.27374,300,0,0,294789,0,0,0,0,0,0,0,'',0);

update `creature_template` set npcflag=16777216,ainame='SmartAI' where entry in (171039,170749);

replace into `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) values
('171039','241483','1','0'),
('170749','336360','1','0');

delete from spell_target_position where ID in (241483,336360);

replace into `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) values
('241483','0','2222','4125','7886.89','4971.34','36949');
-- ('336360','0','2147','529.42','-2124.78','840.85','36949'); portal in archerus to icc dont watch

replace into `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) values
('6000000000046955','171039','0','0','0','0','0','0','0','-1','0','0','-8483.44','384.161','115.857','2.22549','300','0','0','27','0','0','0','0','0','0','0','','0');

replace into `game_tele` (`id`, `position_x`, `position_y`, `position_z`, `orientation`, `map`, `name`) values
('5000','4125','7886.89','4971.34','5.39962','2222','campañashadowlands'),
('5001','-604.652','2211.56','550.514','6.25176','2297','newarcherus');

replace into `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) values
('6000000000046959','169076','2222','0','0','0','0','0','0','-1','0','0','4139.06','7896.5','4971.13','4.51278','300','0','0','16380','0','0','0','0','0','0','0','','0'),
('60000000000025241','171039','1','0','0','0','0','0','0','-1','0','0','1582.55','-4348.47','21.1791','5.10989','300','0','0','27','0','0','0','0','0','0','0','','0'),
('60000000000025242','176554','1','0','0','0','0','0','0','-1','0','0','1586.67','-4350.86','21.1202','5.03504','300','0','0','294789','0','0','0','0','0','0','0','','0'); 

delete from quest_objectives where questid  in (60545,61874);

replace into `quest_objectives` (`ID`, `QuestID`, `Type`, `Order`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `ProgressBarWeight`, `Description`, `VerifiedBuild`) values
('406745','60545','0','1','2','171039','1','0','0','0','Take the Death Gate to Acherus','36949'),
-- ('406744','60545','0','0','0','171789','1','2','0','0',NULL,'0'),
-- ('405017','60545','0','2','0','170749','1','0','0','0','Take the teleporter to the Frozen Throne','36949');

-- ('406783','61874','14','0','1','87225','1','0','0','0','Learn about your leaders\' fate','36949'),
('406784','61874','0','1','2','171039','1','0','0','0','Take the Death Gate to Acherus','36949');
-- ('406785','61874','0','2','0','170749','1','2','0','0','Take the teleporter to the Frozen Throne','36949');
