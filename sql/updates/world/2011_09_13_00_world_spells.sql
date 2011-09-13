-- Fix Startup Errors
UPDATE `creature_template` SET `exp`=0,`npcflag`=`npcflag`|16777216,`unit_flags`=`unit_flags`|33571584 WHERE `entry`=34111;
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (33139,34111);
INSERT INTO `npc_spellclick_spells`(`npc_entry`,`spell_id`,`quest_start`,`quest_start_active`,`quest_end`,`cast_flags`,`aura_required`,`aura_forbidden`,`user_type`) VALUES
(34111,46598,0,0,0,1,0,0,0),
(33139,46598,0,0,0,1,0,0,0);
 
-- Added Burn to Vehicles for Hard mode Mechanics
-- Thanks to horn for the reminder
-- Burn Secondary Effect from Vehicles
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (65044,65045);
INSERT INTO `conditions`(`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,0,65044,1,18,1,34234,0,0, '', 'Flames to Runeforged Sentry'),
(13,0,65044,2,18,1,33236,0,0, '', 'Flames to Steelforged Defender'),
(13,0,65044,3,18,1,33572,0,0, '', 'Flames to Steelforged Defender'),
(13,0,65044,4,18,1,33237,0,0, '', 'Flames to Ulduar Colossus'),
(13,0,65044,5,18,1,33189,0,0, '', 'Flames to Liquid pyrite'),
(13,0,65044,6,18,1,33090,0,0, '', 'Flames to Pool of Tar'),
(13,0,65044,7,18,1,34161,0,0, '', 'Flames to Mechanostriker 54-A'),
(13,0,65044,8,18,1,33062,0,0, '', 'Flames to Salvaged Chopper'),
(13,0,65044,9,18,1,34045,0,0, '', 'Flames to Salvaged Chopper'),
(13,0,65044,10,18,1,33109,0,0, '', 'Flames to Salvaged Demolisher'),
(13,0,65044,11,18,1,33060,0,0, '', 'Flames to Salvaged Salvaged Siege Engine'),
-- Burn Secondary Effect from Vehicles
(13,0,65045,1,18,1,34234,0,0, '', 'Flames to Runeforged Sentry'),
(13,0,65045,2,18,1,33236,0,0, '', 'Flames to Steelforged Defender'),
(13,0,65045,3,18,1,33572,0,0, '', 'Flames to Steelforged Defender'),
(13,0,65045,4,18,1,33237,0,0, '', 'Flames to Ulduar Colossus'),
(13,0,65045,5,18,1,33189,0,0, '', 'Flames to Liquid pyrite'),
(13,0,65045,6,18,1,33090,0,0, '', 'Flames to Pool of Tar'),
(13,0,65045,7,18,1,34161,0,0, '', 'Flames to Mechanostriker 54-A');
(13,0,65045,8,18,1,33062,0,0, '', 'Flames to Salvaged Chopper'),
(13,0,65045,9,18,1,34045,0,0, '', 'Flames to Salvaged Chopper'),
(13,0,65045,10,18,1,33109,0,0, '', 'Flames to Salvaged Demolisher'),
(13,0,65045,11,18,1,33060,0,0, '', 'Flames to Salvaged Salvaged Siege Engine')
