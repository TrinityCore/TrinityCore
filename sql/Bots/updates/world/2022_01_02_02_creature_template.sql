--
SET @BOT_START = 70575;
SET @BOT_END   = 70580;

DELETE FROM `creature_template` WHERE `entry` BETWEEN @BOT_START AND @BOT_END;

INSERT INTO `creature_template`
(`entry`,`difficulty_entry_1`,`difficulty_entry_2`,`difficulty_entry_3`,`KillCredit1`,`KillCredit2`,
`modelid1`,`modelid2`,`modelid3`,`modelid4`,`name`,`subname`,`IconName`,`gossip_menu_id`,`minlevel`,`maxlevel`,`exp`,
`faction`,`npcflag`,`speed_walk`,`speed_run`,`scale`,`rank`,`dmgschool`,`BaseAttackTime`,`RangeAttackTime`,
`unit_class`,`unit_flags`,`unit_flags2`,`dynamicflags`,`family`,`type`,`type_flags`,`lootid`,
`pickpocketloot`,`skinloot`,`PetSpellDataId`,`VehicleId`,`mingold`,`maxgold`,`AIName`,`MovementType`,
`HoverHeight`,`HealthModifier`,`ManaModifier`,`ArmorModifier`,`RacialLeader`,`movementId`,`RegenHealth`,
`mechanic_immune_mask`,`flags_extra`,`ScriptName`,`VerifiedBuild`)
VALUES
('70575','0','0','0','0','0','23277','0','0','0','Prakar','Necromancer Bot','','0','82','82','2','35','1','1.1','1.1','1','1','0','1800','1800','9','0','32','0','0','7','4096','0','0','0','0','0','0','0','','0','1','1','1','1','0','0','0','0','68157552','necromancer_bot','-1'),
('70576','0','0','0','0','0','23277','0','0','0','Rothik','Necromancer Bot','','0','82','82','2','35','1','1.1','1.1','1','1','0','1800','1800','9','0','32','0','0','7','4096','0','0','0','0','0','0','0','','0','1','1','1','1','0','0','0','0','68157552','necromancer_bot','-1'),
('70577','0','0','0','0','0','23277','0','0','0','Hexir','Necromancer Bot','','0','82','82','2','35','1','1.1','1.1','1','1','0','1800','1800','9','0','32','0','0','7','4096','0','0','0','0','0','0','0','','0','1','1','1','1','0','0','0','0','68157552','necromancer_bot','-1'),
('70578','0','0','0','0','0','23277','0','0','0','Fikhar','Necromancer Bot','','0','82','82','2','35','1','1.1','1.1','1','1','0','1800','1800','9','0','32','0','0','7','4096','0','0','0','0','0','0','0','','0','1','1','1','1','0','0','0','0','68157552','necromancer_bot','-1'),
('70579','0','0','0','0','0','23277','0','0','0','Drothum','Necromancer Bot','','0','82','82','2','35','1','1.1','1.1','1','1','0','1800','1800','9','0','32','0','0','7','4096','0','0','0','0','0','0','0','','0','1','1','1','1','0','0','0','0','68157552','necromancer_bot','-1'),
('70580','0','0','0','0','0','200','0','0','0','Skeleton',NULL,'','0','82','82','2','35','0','1.2','1.3','1.1','0','0','2000','2000','1','0','0','0','0','6','4096','0','0','0','0','0','0','0','','0','1','1','1','1','0','0','0','0','135266400','necromancer_pet_bot','-1');
