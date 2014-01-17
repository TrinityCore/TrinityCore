DELETE FROM `creature_text` WHERE `entry` IN (16980,36789,37491,37493,37494,37495);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(16980,0,0,'Intruders have breached the inner sanctum. Hasten the destruction of the green dragon! Leave only bones and sinew for the reanimation!',14,0,0,0,0,17251,'The Lich King - SAY_LICH_KING_INTRO'),
(36789,0,0,'Heroes, lend me your aid. I... I cannot hold them off much longer. You must heal my wounds!',14,0,0,0,0,17064,'Valithria Dreamwalker - SAY_VALITHRIA_ENTER_COMBAT'),
(36789,1,0,'I have opened a portal into the Dream. Your salvation lies within, heroes...',14,0,0,0,0,17068,'Valithria Dreamwalker - SAY_VALITHRIA_DREAM_PORTAL'),
(36789,2,0,'My strength is returning! Press on, heroes!',14,0,0,0,0,17070,'Valithria Dreamwalker - SAY_VALITHRIA_75_PERCENT'),
(36789,3,0,'I will not last much longer!',14,0,0,0,0,17069,'Valithria Dreamwalker - SAY_VALITHRIA_25_PERCENT'),
(36789,4,0,'Forgive me for what I do! I... cannot... stop... ONLY NIGHTMARES REMAIN!',14,0,0,0,0,17072,'Valithria Dreamwalker - SAY_VALITHRIA_DEATH'),
(36789,5,0,'A tragic loss...',14,0,0,0,0,17066,'Valithria Dreamwalker - SAY_VALITHRIA_PLAYER_DEATH'),
(36789,6,0,'FAILURES!',14,0,0,0,0,17067,'Valithria Dreamwalker - SAY_VALITHRIA_BERSERK'),
(36789,7,0,'I am renewed! Ysera grants me the favor to lay these foul creatures to rest!',14,0,0,0,0,17071,'Valithria Dreamwalker - SAY_VALITHRIA_SUCCESS'),
(37491,1,0, 'You miserable fools never did manage to select a decent bat wing.',1,0,0,0,0,16587, 'Captain Arnath - SAY_ARNATH_RESURRECTED'),
(37491,2,0, 'THAT was for bringing me spoiled spider ichor!',1,0,0,0,0,16588, 'Captain Arnath - SAY_ARNATH_KILL'),
(37491,3,0, 'Don''t... let Finklestein use me... for his potions...',1,0,0,0,0,16589, 'Captain Arnath - SAY_ARNATH_SECOND_DEATH'),
(37493,1,0, 'What? This strength...? All of the pain is gone! You... must join me in the eternal embrace of death!',1,0,0,0,0,16811, 'Captain Brandon - SAY_BRANDON_RESURRECTED'),
(37493,2,0, 'It doesn''t hurt anymore, does it?',1,0,0,0,0,16812, 'Captain Brandon - SAY_BRANDON_KILL'),
(37493,3,0, 'I''m sorry...',1,0,0,0,0,16813, 'Captain Brandon - SAY_BRANDON_SECOND_DEATH'),
(37494,1,0, 'No! Why was I denied a death by flame? You must all BURN!',1,0,0,0,0,16845, 'Captain Grondel - SAY_GRONDEL_RESURRECTED'),
(37494,2,0, 'Can you feel the burn?',1,0,0,0,0,16846, 'Captain Grondel - SAY_GRONDEL_KILL'),
(37494,3,0, 'What... have I done? No!',1,0,0,0,0,16847, 'Captain Grondel - SAY_GRONDEL_SECOND_DEATH'),
(37495,1,0, 'There is no escaping the Lich King''s will. Prepare for an explosive encounter!',1,0,0,0,0,16999, 'Captain Rupert - SAY_RUPERT_RESURRECTED'),
(37495,2,0, 'So that''s what happens when you stand too close to a bomb!',1,0,0,0,0,17000, 'Captain Rupert - SAY_RUPERT_KILL'),
(37495,3,0, 'What an... explosive ending!',1,0,0,0,0,17001, 'Captain Rupert - SAY_RUPERT_SECOND_DEATH');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (71948,70588,70602,71946,72031,72032,72033,70921,71032,71078,70933,72706,73843);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,0,71948,0,18,1,37950,0,0,'','Valithria Dreamwalker - Copy Damage on Valithria'),
(13,0,70588,0,18,1,36789,0,0,'','Suppresser - Suppression target Valithria'),
(13,0,70602,0,18,1,36789,0,0,'','Risen Archmage - Corruption target Valithria'),
(13,0,71946,0,18,1,36789,0,0,'','Valithria Dreamwalker - Nightmare Cloud'),
(13,0,72031,0,18,1,36789,0,0,'','Valithria Dreamwalker - Nightmare Cloud'),
(13,0,72032,0,18,1,36789,0,0,'','Valithria Dreamwalker - Nightmare Cloud'),
(13,0,72033,0,18,1,36789,0,0,'','Valithria Dreamwalker - Nightmare Cloud'),
(13,0,70921,0,18,1,22515,0,0,'','The Lich King - Summon Gluttonous Abomination'),
(13,0,71032,0,18,1,22515,0,0,'','The Lich King - Summon Blistering Zombie'),
(13,0,71078,0,18,1,22515,0,0,'','The Lich King - Summon Risen Archmage'),
(13,0,70933,0,18,1,22515,0,0,'','The Lich King - Summon Blazing Skeleton'),
(13,0,72706,0,18,1,0,0,0,'','Valithria Dreamwalker - Achievement Check'),
(13,0,73843,0,18,1,0,0,0,'','Valithria Dreamwalker - Reputation reward');

DELETE FROM `creature_template_addon` WHERE `entry` IN (36789,38174,37934,37950,38068,37918,37907,38168,38726,38736,37945,38430,38186,38429,37985,38421);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(36789,0,0x0000000,1,0,'72724 70904'),
(38174,0,0x0000000,1,0,'72724 70904'),
(37934,0,0x0000000,1,0,'70749'),
(37950,0,0x3000000,1,0,''),
(38068,0,0x0000000,1,0,'71085'),
(37918,0,0x0000000,1,0,'70715'),
(37907,0,0x0000000,1,0,'72962'),
(38168,0,0x0000000,1,0,'72962'),
(38726,0,0x0000000,1,0,'72962'),
(38736,0,0x0000000,1,0,'72962'),
(37945,0,0x0000000,1,0,'70763'), -- Dream Portal
(38430,0,0x0000000,1,0,'71994'), -- Nightmare Portal
(38186,0,0x0000000,1,0,'71304'), -- Dream Portal (Pre-effect)
(38429,0,0x0000000,1,0,'71986'), -- Nightmare Portal (Pre-effect)
(37985,0,0x3000000,1,0,'70876'), -- Dream Cloud
(38421,0,0x3000000,1,0,'71939 71970'); -- Nightmre Cloud

UPDATE `creature_template` SET `minlevel`=83,`maxlevel`=83,`exp`=2,`unit_class`=1,`faction_A`=1665,`faction_H`=1665,`unit_flags`=`unit_flags`|33554432,`baseattacktime`=2000,`scale`=1,`InhabitType`=7 WHERE `entry`=37950; -- Valithria Dreamwalker
UPDATE `creature_template` SET `minlevel`=60,`maxlevel`=60,`unit_class`=1,`faction_A`=14,`faction_H`=14,`unit_flags`=`unit_flags`|33554432,`baseattacktime`=2000,`flags_extra`=`flags_extra`|128 WHERE `entry`=38068; -- Mana Void
UPDATE `creature_template` SET `minlevel`=60,`maxlevel`=60,`unit_class`=1,`faction_A`=14,`faction_H`=14,`unit_flags`=`unit_flags`|33554432,`baseattacktime`=2000,`flags_extra`=`flags_extra`|128 WHERE `entry`=37918; -- Column of Frost
UPDATE `creature_template` SET `minlevel`=80,`maxlevel`=80,`exp`=2,`unit_class`=1,`faction_A`=35,`faction_H`=35,`npcflag`=`npcflag`|16777216 WHERE `entry` IN (37945,38430); -- Dream Portal and Nightmare Portal
UPDATE `creature_template` SET `minlevel`=80,`maxlevel`=80,`faction_A`=35,`faction_H`=35,`unit_flags`=`unit_flags`|33554432,`npcflag`=`npcflag`|16777216,`baseattacktime`=2000 WHERE `entry`=38186; -- Dream Portal (Pre-effect)
UPDATE `creature_template` SET `minlevel`=80,`maxlevel`=80,`faction_A`=35,`faction_H`=35,`unit_flags`=`unit_flags`|33554432,`npcflag`=`npcflag`|16777216,`baseattacktime`=2000 WHERE `entry`=38429; -- Nightmare Portal (Pre-effect)
UPDATE `creature_template` SET `minlevel`=80,`maxlevel`=80,`exp`=2,`unit_class`=1,`faction_A`=2022,`faction_H`=2022,`unit_flags`=`unit_flags`|33554432,`baseattacktime`=2000,`InhabitType`=7,`flags_extra`=`flags_extra`|128 WHERE `entry`=37985; -- Dream Cloud
UPDATE `creature_template` SET `minlevel`=80,`maxlevel`=80,`exp`=2,`unit_class`=1,`faction_A`=2022,`faction_H`=2022,`unit_flags`=`unit_flags`|33554432,`baseattacktime`=2000,`InhabitType`=7,`flags_extra`=`flags_extra`|128 WHERE `entry`=38421; -- Nightmare Cloud
UPDATE `creature_template` SET `minlevel`=83,`maxlevel`=83,`exp`=2,`unit_class`=1,`faction_A`=35,`faction_H`=35,`npcflag`=`npcflag`|3,`baseattacktime`=2000,`scale`=1 WHERE `entry`=38589; -- Valithria Dreamwalker (questgiver)

SET @GUID := 137794;
UPDATE `creature` SET `phaseMask`=`phaseMask`|4 WHERE `id`=36789;
-- Add The Lich King and Green Dragon Combat Trigger to all encounter phases, fixes evading when all players enter portals
UPDATE `creature` SET `phaseMask`=`phaseMask`|16 WHERE `guid` IN (137789,137752);
DELETE FROM `creature` WHERE `id` IN (37950,37985,38421) OR `guid`=137793 OR `guid` BETWEEN @GUID+00 AND @GUID+27;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(1636,37950,631,15,20,0,0,4202.847,2484.917,383.8368,0.00000,604800,0,0,0,0,0,0,0,0,0), -- Valithria Dreamwalker (dream phase)
(137793,22515,631,10,1,0,0,4166.170,2411.520,364.9520,1.57080,120,0,0,0,0,0,0,0,0,0), -- World Trigger
-- Dream Cloud
(@GUID+00,37985,631,3,16,0,0,4155.51,2478.76,382.494,4.97053,30,10,0,0,0,0,1,0,0,0),
(@GUID+01,37985,631,3,16,0,0,4158.75,2494.08,384.334,2.31129,30,10,0,0,0,0,1,0,0,0),
(@GUID+02,37985,631,3,16,0,0,4172.57,2464.47,385.368,3.72021,30,10,0,0,0,0,1,0,0,0),
(@GUID+03,37985,631,3,16,0,0,4173.67,2504.13,386.174,2.67313,30,10,0,0,0,0,1,0,0,0),
(@GUID+04,37985,631,3,16,0,0,4181.62,2514.91,386.374,2.65209,30,10,0,0,0,0,1,0,0,0),
(@GUID+05,37985,631,3,16,0,0,4186.72,2450.97,388.373,4.95968,30,10,0,0,0,0,1,0,0,0),
(@GUID+06,37985,631,3,16,0,0,4200.96,2456.00,387.128,3.58291,30,10,0,0,0,0,1,0,0,0),
(@GUID+07,37985,631,3,16,0,0,4202.23,2508.00,383.985,2.09137,30,10,0,0,0,0,1,0,0,0),
(@GUID+08,37985,631,3,16,0,0,4220.35,2515.16,388.649,2.34469,30,10,0,0,0,0,1,0,0,0),
(@GUID+09,37985,631,3,16,0,0,4222.26,2455.20,385.568,0.00000,30,10,0,0,0,0,1,0,0,0),
(@GUID+10,37985,631,3,16,0,0,4231.61,2464.44,389.011,0.00000,30,10,0,0,0,0,1,0,0,0),
(@GUID+11,37985,631,3,16,0,0,4236.75,2500.62,383.373,5.97527,30,10,0,0,0,0,1,0,0,0),
(@GUID+12,37985,631,3,16,0,0,4243.29,2476.89,386.076,0.00000,30,10,0,0,0,0,1,0,0,0),
(@GUID+13,37985,631,3,16,0,0,4244.83,2493.18,387.677,4.29139,30,10,0,0,0,0,1,0,0,0),
-- Nightmare Cloud
(@GUID+14,38421,631,12,20,0,0,4155.51,2478.76,382.494,4.97053,30,10,0,0,0,0,1,0,0,0),
(@GUID+15,38421,631,12,20,0,0,4158.75,2494.08,384.334,2.31129,30,10,0,0,0,0,1,0,0,0),
(@GUID+16,38421,631,12,20,0,0,4172.57,2464.47,385.368,3.72021,30,10,0,0,0,0,1,0,0,0),
(@GUID+17,38421,631,12,20,0,0,4181.62,2514.91,386.374,2.65209,30,10,0,0,0,0,1,0,0,0),
(@GUID+18,38421,631,12,20,0,0,4200.96,2456.00,387.128,3.58291,30,10,0,0,0,0,1,0,0,0),
(@GUID+19,38421,631,12,20,0,0,4202.23,2508.00,383.985,2.09137,30,10,0,0,0,0,1,0,0,0),
(@GUID+20,38421,631,12,20,0,0,4220.35,2515.16,388.649,2.34469,30,10,0,0,0,0,1,0,0,0),
(@GUID+21,38421,631,12,20,0,0,4222.26,2455.20,385.568,0.00000,30,10,0,0,0,0,1,0,0,0),
(@GUID+22,38421,631,12,20,0,0,4236.75,2500.62,383.373,5.97527,30,10,0,0,0,0,1,0,0,0),
(@GUID+23,38421,631,12,20,0,0,4243.29,2476.89,386.076,0.00000,30,10,0,0,0,0,1,0,0,0);

DELETE FROM `linked_respawn` WHERE `guid`=137789 AND `linkType`=0;
INSERT INTO `linked_respawn` (`guid`,`linkedGuid`,`linkType`) VALUES
(137789,137752,0); -- The Lich King link to Green Dragon Combat Trigger

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (37945,38430,38186,38429);
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`quest_start`,`quest_start_active`,`quest_end`,`cast_flags`,`aura_required`,`aura_forbidden`,`user_type`) VALUES
(37945,70766,0,0,0,3,0,0,0), -- Dream Portal
(38430,70766,0,0,0,3,0,0,0), -- Nightmare Portal
(38186,70766,0,0,0,3,0,0,0), -- Dream Portal (Pre-effect)
(38429,70766,0,0,0,3,0,0,0); -- Nightmare Portal (Pre-effect)

-- Gates should also exist in all phases, prevent players from leaving room
UPDATE `gameobject` SET `phaseMask`=`phaseMask`|16 WHERE `id` IN (201375,201374,201380,201381,201382,201383);
