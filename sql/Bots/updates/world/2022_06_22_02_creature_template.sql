--
SET @BOT_START = 70581;
SET @BOT_END   = 70586;

DELETE FROM `creature_template` WHERE `entry` BETWEEN @BOT_START AND @BOT_END;

INSERT INTO `creature_template`
(`entry`,`difficulty_entry_1`,`difficulty_entry_2`,`difficulty_entry_3`,`KillCredit1`,`KillCredit2`,
`modelid1`,`modelid2`,`modelid3`,`modelid4`,`name`,`subname`,`IconName`,`gossip_menu_id`,`minlevel`,`maxlevel`,`exp`,
`faction`,`npcflag`,`speed_walk`,`speed_run`,`scale`,`rank`,`dmgschool`,`BaseAttackTime`,`RangeAttackTime`,
`BaseVariance`,`RangeVariance`,`unit_class`,`unit_flags`,`unit_flags2`,`dynamicflags`,`family`,`type`,`type_flags`,`lootid`,
`pickpocketloot`,`skinloot`,`PetSpellDataId`,`VehicleId`,`mingold`,`maxgold`,`AIName`,`MovementType`,
`HoverHeight`,`HealthModifier`,`ManaModifier`,`ArmorModifier`,`DamageModifier`,`ExperienceModifier`,`RacialLeader`,`movementId`,`RegenHealth`,
`mechanic_immune_mask`,`spell_school_immune_mask`,`flags_extra`,`ScriptName`,`VerifiedBuild`)
VALUES
('70581','0','0','0','0','0','20748','0','0','0','Kondra','Sea Witch Bot','','0','83','83','2','35','1','1.05','1.05','0.5','2','0','1900','1900','1','1','8','0','32','0','0','7','4096','0','0','0','0','0','0','0','','0','1','1','1','1','1','1','0','0','0','0','0','68157552','sea_witch_bot','-1'),
('70582','0','0','0','0','0','20748','0','0','0','Serpentra','Sea Witch Bot','','0','83','83','2','35','1','1.05','1.05','0.5','2','0','1900','1900','1','1','8','0','32','0','0','7','4096','0','0','0','0','0','0','0','','0','1','1','1','1','1','1','0','0','0','0','0','68157552','sea_witch_bot','-1'),
('70583','0','0','0','0','0','20748','0','0','0','Serena','Sea Witch Bot','','0','83','83','2','35','1','1.05','1.05','0.5','2','0','1900','1900','1','1','8','0','32','0','0','7','4096','0','0','0','0','0','0','0','','0','1','1','1','1','1','1','0','0','0','0','0','68157552','sea_witch_bot','-1'),
('70584','0','0','0','0','0','20748','0','0','0','Asprah','Sea Witch Bot','','0','83','83','2','35','1','1.05','1.05','0.5','2','0','1900','1900','1','1','8','0','32','0','0','7','4096','0','0','0','0','0','0','0','','0','1','1','1','1','1','1','0','0','0','0','0','68157552','sea_witch_bot','-1'),
('70585','0','0','0','0','0','20748','0','0','0','Charib\'dishal','Sea Witch Bot','','0','83','83','2','35','1','1.05','1.05','0.5','2','0','1900','1900','1','1','8','0','32','0','0','7','4096','0','0','0','0','0','0','0','','0','1','1','1','1','1','1','0','0','0','0','0','68157552','sea_witch_bot','-1'),
('70586','0','0','0','0','0','20211','0','0','0','Tornado','','','0','83','83','2','35','0','0.9','0.9','3','1','0','2000','2000','1','1','1','33554432','32768','0','0','4','33554432','0','0','0','0','0','0','0','','0','1','1','1','1','1','1','0','0','0','0','0','671096832','sea_witch_pet_bot','-1');
