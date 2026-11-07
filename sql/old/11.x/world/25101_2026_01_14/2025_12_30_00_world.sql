DELETE FROM `areatrigger_template` WHERE `Id`=35700 AND `IsCustom`=0;
INSERT INTO `areatrigger_template` (`Id`,`IsCustom`,`Flags`,`ActionSetId`,`ActionSetFlags`,`VerifiedBuild`) VALUES
(35700,0,0,0,0,0);

DELETE FROM `areatrigger_create_properties` WHERE `Id`=33200 AND `IsCustom`=0;
INSERT INTO `areatrigger_create_properties` (`Id`,`IsCustom`,`AreaTriggerId`,`IsAreatriggerCustom`,`Flags`,`MoveCurveId`,`ScaleCurveId`,`MorphCurveId`,`FacingCurveId`,`AnimId`,`AnimKitId`,`DecalPropertiesId`,`SpellForVisuals`,`TimeToTargetScale`,`Speed`,`SpeedIsTime`,`Shape`,`ShapeData0`,`ShapeData1`,`ShapeData2`,`ShapeData3`,`ShapeData4`,`ShapeData5`,`ShapeData6`,`ShapeData7`,`ScriptName`,`VerifiedBuild`) VALUES
(33200,0,35700,0,0,0,0,0,0,-1,0,0,447445,1000,12,0,0,4,4,0,0,0,0,0,0,'areatrigger_pri_entropic_rift',64978);

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_pri_entropic_rift','spell_pri_entropic_rift_aura','spell_pri_entropic_rift_periodic');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(8092,'spell_pri_entropic_rift'),
(263165,'spell_pri_entropic_rift'),
(450193,'spell_pri_entropic_rift_aura'),
(459314,'spell_pri_entropic_rift_periodic');

UPDATE `creature_template` SET `unit_flags3`=0x1000000,`AIName`='SmartAI' WHERE `entry`=223273; -- Entropic Rift
DELETE FROM `smart_scripts` WHERE `entryorguid`=223273 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`Difficulties`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`event_param_string`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`action_param7`,`action_param_string`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_param_string`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(223273,0,0,0,'',86,0,100,0,0,0,0,0,0,'',28,450193,0,0,0,0,0,0,NULL,23,0,0,0,0,NULL,0,0,0,0,'Entropic Rift - remove 450193 from summoner on despawn'),
(223273,0,1,0,'',86,0,100,0,0,0,0,0,0,'',28,459314,0,0,0,0,0,0,NULL,23,0,0,0,0,NULL,0,0,0,0,'Entropic Rift - remove 459314 from summoner on despawn');
