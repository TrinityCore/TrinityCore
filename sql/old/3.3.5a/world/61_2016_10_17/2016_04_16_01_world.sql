SET @OGUID := 78735; -- 20 free guids required
SET @CGUID := 84148; -- 9 free guids required

SET @NPC := @CGUID+1;
SET @PATH := @NPC * 10;

UPDATE `creature_template` SET `difficulty_entry_1`=0 WHERE `entry` IN (25740,25755,25756,25865);
UPDATE `creature_template` SET  `minlevel`=82,`maxlevel`=82, `mechanic_immune_mask`=617299839, `ScriptName`='boss_ahune' WHERE `entry`=25740; -- Ahune
UPDATE `creature_template` SET  `minlevel`=80,`maxlevel`=80, `AIName`='SmartAI' WHERE `entry`=25755; -- Ahunite Hailstone
UPDATE `creature_template` SET  `minlevel`=80,`maxlevel`=80, `AIName`='SmartAI' WHERE `entry`=25756; -- Ahunite Coldwave
UPDATE `creature_template` SET  `minlevel`=80,`maxlevel`=80, `AIName`='SmartAI' WHERE `entry`=25757; -- Ahunite Frostwind
UPDATE `creature_template` SET  `minlevel`=80,`maxlevel`=80, `flags_extra`=`flags_extra`|0x40000000, `mechanic_immune_mask`=617299839, `ScriptName`='npc_frozen_core' WHERE `entry`=25865; -- Frozen Core
UPDATE `creature_template` SET `ScriptName`='npc_ahune_bunny' WHERE `entry`=25745;
UPDATE `creature_template` SET `ScriptName`='npc_earthen_ring_flamecaller' WHERE `entry`=25754;
UPDATE `creature_template` SET `unit_flags`=33554432, `MovementType`=2 WHERE `entry` IN (25964,25965,25966); -- Shaman beam bunny
UPDATE `creature_template` SET `unit_flags`=33554432 WHERE `entry`=26239; -- Ghost of Ahune
UPDATE `creature_template` SET `flags_extra`=128 WHERE `entry`=25985; -- Ahune Ice Spear Bunny
UPDATE `gameobject_template` SET `ScriptName`='go_ahune_ice_stone' WHERE `entry`=187882;
UPDATE `creature` SET `orientation`=2.408554 WHERE `guid`=202734; -- Luma
UPDATE `creature` SET `orientation`=3.804818 WHERE `guid`=202737; -- Flamecaller
UPDATE `creature_template` SET `HealthModifier`=94.5, `unit_flags`=33554688 WHERE `entry`=25865;
UPDATE `creature_template` SET `HealthModifier`=18.8 WHERE `entry`=25755;
UPDATE `creature_template` SET `HealthModifier`=3.538 WHERE `entry`=25756;
UPDATE `creature_template` SET `HealthModifier`=1.5 WHERE `entry`=25757;
UPDATE `creature_template` SET `HealthModifier`=4 WHERE `entry`=40446;
UPDATE `creature_template` SET `InhabitType`=7 WHERE `entry` IN (25964,25965,25966,26190);

DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_ahune_synch_health',
'spell_ice_spear_control_aura',
'spell_slippery_floor_periodic',
'spell_summon_ice_spear_delayer',
'spell_summoning_rhyme_aura',
'spell_ahune_spanky_hands',
'spell_ahune_minion_despawner',
'spell_ice_spear_target_picker',
'spell_ice_bombardment_dest_picker');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(46430, 'spell_ahune_synch_health'),
(46371, 'spell_ice_spear_control_aura'),
(46320, 'spell_slippery_floor_periodic'),
(46878, 'spell_summon_ice_spear_delayer'),
(45926, 'spell_summoning_rhyme_aura'),
(46146, 'spell_ahune_spanky_hands'),
(46843, 'spell_ahune_minion_despawner'),
(46372, 'spell_ice_spear_target_picker'),
(46398, 'spell_ice_bombardment_dest_picker');

DELETE FROM `creature_text` WHERE `entry` IN (25745,25754,25697,40446);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(25745,0,0,'The Earthen Ring\'s Assault Begins.',41,0,100,0,0,0,24930,1,'Ahune Bunny- EMOTE_EARTHEN_ASSAULT'),
(25754,0,0,'Ahune Retreats.  His defenses diminish.',41,0,100,0,0,0,24931,1,'Earthen Ring Flamecaller - EMOTE_RETREAT'),
(25754,1,0,'Ahune will soon resurface.',41,0,100,0,0,0,24932,1,'Earthen Ring Flamecaller - EMOTE_RESURFACE'),
(40446,0,0,'How DARE you! You will not stop the coming of Lord Ahune!',14,0,100,0,0,0,40437,0,'Skar\'this the Summoner'),
(25697,0,0,'The Ice Stone has melted!',14,0,100,0,0,0,24895,0,'Luma Skymother - SAY_PLAYER_1'),
(25697,1,0,'Ahune, your strength grows no more!',14,0,100,0,0,0,24893,0,'Luma Skymother - SAY_PLAYER_2'),
(25697,2,0,'Your frozen reign will not come to pass!',14,0,100,0,0,0,24894,0,'Luma Skymother - SAY_PLAYER_3');

DELETE FROM `gossip_menu` WHERE `entry`=11389;
INSERT INTO `gossip_menu` VALUES
(11389,15864);

DELETE FROM `gossip_menu_option` WHERE `menu_id`=11389;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`OptionBroadcastTextID`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`,`BoxBroadcastTextID`) VALUES
(11389,1,0,'Disturb the stone and summon Lord Ahune.',40443,1,1,0,0,0,0,NULL,0);

DELETE FROM `creature_template_addon` WHERE `entry` IN (25740,25755,25865,25985,25952);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(25740, 0, 0, 9, 1, 61976),
(25755, 0, 0, 0, 0, 46542),
(25865, 0, 0, 0, 0, '46810 61976'),
(25985, 0, 0, 0, 0, '75498 46878'),
(25952, 0, 0, 0, 0, 46314);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (46603,46593,46735,45930,45941,46809,46843,46396,46398,46236);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,46603,0,0,31,0,3,26121,0,0,0,0,'',"Spell 'Force Wisp Flight Missile' can  hit 'Wisp Source Bunny'"),
(13,1,46593,0,0,31,0,3,26120,0,0,0,0,'',"Spell 'Wisp Flight Missile and Beam' can hit 'Wisp Dest Bunny'"),
(13,1,46735,0,0,31,0,3,26190,0,0,0,0,'',"Spell 'Spank - Force Bunny To Knock You To' can hit '[PH] Spank Target Bunny'"),
(13,1,45930,0,1,31,0,3,25971,0,0,0,0,'',"Spell 'Ahune - Summoning Rhyme Spell, make bonfire' can hit 'Shaman Bonfire Bunny 000'"),
(13,1,45930,0,2,31,0,3,25972,0,0,0,0,'',"Spell 'Ahune - Summoning Rhyme Spell, make bonfire' can hit 'Shaman Bonfire Bunny 001'"),
(13,1,45930,0,3,31,0,3,25973,0,0,0,0,'',"Spell 'Ahune - Summoning Rhyme Spell, make bonfire' can hit 'Shaman Bonfire Bunny 002'"),
(13,1,45941,0,0,31,0,3,25746,0,0,0,0,'',"Spell 'Summon Ahune's Loot Missile' can hit '[PH] Ahune Loot Loc Bunny'"),
(13,1,46809,0,0,31,0,3,26239,0,0,0,0,'',"Spell 'Make Ahune's Ghost Burst' can hit 'Ghost of Ahune"),
(13,1,46843,0,1,31,0,3,25756,0,0,0,0,'',"Spell 'Minion Despawner' can hit 'Ahunite Coldwave'"),
(13,1,46843,0,2,31,0,3,25757,0,0,0,0,'',"Spell 'Minion Despawner' can hit 'Ahunite Frostwind'"),
(13,1,46843,0,3,31,0,3,25755,0,0,0,0,'',"Spell 'Minion Despawner' can hit 'Ahunite Hailstone'"),
(13,1,46398,0,0,31,0,3,25972,0,0,0,0,'',"Spell 'Ice Bombardment Dest Picker' can hit 'Shaman Bonfire Bunny'"),
(13,1,46396,0,0,31,0,3,25972,0,0,0,0,'',"Spell 'Ice Bombardment' can hit 'Shaman Bonfire Bunny'"),
(13,1,46236,0,1,31,0,3,25971,0,0,0,0,'',"Spell 'Close opening Visual' can hit 'Shaman Bonfire Bunny 000'"),
(13,1,46236,0,2,31,0,3,25972,0,0,0,0,'',"Spell 'Close opening Visual' can hit 'Shaman Bonfire Bunny 001'"),
(13,1,46236,0,3,31,0,3,25973,0,0,0,0,'',"Spell 'Close opening Visual' can hit 'Shaman Bonfire Bunny 002'");

DELETE FROM `disables` WHERE `sourceType`=0 AND `entry` IN (46314,46603,46593,46422);
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES
(0,46314,64,0,0,'Disable LOS for spell Ahune - Slippery Floor Ambient'),
(0,46603,64,0,0,'Disable LOS for spell Force Whisp to Flight'),
(0,46593,64,0,0,'Disable LOS for spell Whisp Flight Missile and Beam'),
(0,46422,64,0,0,'Disable LOS for spell Shamans Look for Opening');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (45947,-45964,45964);
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(45947,45946,2,''),
(-45964,-46333,0,''),
(45964,46333,0,'');

-- Skar'this the Summoner
UPDATE `creature_template` SET  `AIName`='SmartAI' WHERE `entry`=40446;
DELETE FROM `smart_scripts` WHERE `entryorguid`=40446 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(40446,0,0,0,1,0,100,1,0,0,0,0,11,75427,0,0,0,0,0,1,0,0,0,0,0,0,0,'Skar\'this the Summoner - OOC - Cast \'Frost Channelling\''),
(40446,0,1,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Skar\'this the Summoner - On agro - say'),
(40446,0,2,0,0,0,100,0,5000,5000,15000,15000,11,55909,1,0,0,0,0,2,0,0,0,0,0,0,0,'Skar\'this the Summoner - IC - Cast Crashing Wave'),
(40446,0,3,0,0,0,100,0,10000,10000,20000,20000,11,11831,1,0,0,0,0,2,0,0,0,0,0,0,0,'Skar\'this the Summoner - IC - Cast Frost Nova'),
(40446,0,4,0,0,0,100,0,7000,7000,9000,9000,11,15043,0,0,0,0,0,2,0,0,0,0,0,0,0,'Skar\'this the Summoner - IC - Cast Frostbolt');

-- Summon Loot Bunny SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=25746;
DELETE FROM `smart_scripts` WHERE `entryorguid`=25746 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25746,0,0,0,8,0,100,0,45941,0,0,0,11,46891,0,0,0,0,0,1,0,0,0,0,0,0,0,'[PH] Ahune Loot Loc Bunny - On SpellHit - Cast \'Summon Loot\'');

-- [PH] Spank Target Bunny SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=26190;
DELETE FROM `smart_scripts` WHERE `entryorguid`=26190 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26190,0,0,0,8,0,100,0,46735,0,0,0,11,46734,0,0,0,0,0,7,0,0,0,0,0,0,0,'[PH] Spank Target Bunny - On SpellHit \'Spank - Force Bunny To Knock You To\' - Cast \'Knock To\'');

-- Ghost of Ahune
UPDATE `creature_template` SET `AIName`='SmartAI', `flags_extra`='2' WHERE `entry`=26239;
DELETE FROM `smart_scripts` WHERE `entryorguid`=26239 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2623900 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26239,0,0,0,25,0,100,0,0,0,0,0,3,0,11686,0,0,0,0,1,0,0,0,0,0,0,0,'Ghost of Ahune - On Reset - Morph to Model 11686'),
(26239,0,1,0,8,0,100,0,46809,0,4000,4000,80,2623900,2,0,0,0,0,1,0,0,0,0,0,0,0,'Ghost of Ahune - On SpellHit \'Make Ahune\'s Ghost Burst\' - Call Timed ActionList'),
(2623900,9,0,0,0,0,100,0,0,0,0,0,3,0,23707,0,0,0,0,1,0,0,0,0,0,0,0,'Ghost of Ahune - Timed ActionList - Morph to Model 23707'),
(2623900,9,1,0,0,0,100,0,0,0,0,0,11,46786,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ghost of Ahune - Timed ActionList - Cast \'Ahune\'s Ghost Disguise\''),
(2623900,9,2,0,0,0,100,0,2400,2400,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ghost of Ahune - Timed ActionList - Set Visibility Off'),
(2623900,9,3,0,0,0,100,0,500,500,0,0,3,0,11686,0,0,0,0,1,0,0,0,0,0,0,0,'Ghost of Ahune - Timed ActionList - Morph to Model 11686'),
(2623900,9,4,0,0,0,100,0,0,0,0,0,47,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ghost of Ahune - Timed ActionList - Set Visibility On');

-- Wisp Source Bunny SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=26121;
DELETE FROM `smart_scripts` WHERE `entryorguid`=26121 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26121,0,0,1,8,0,100,0,46603,0,0,0,11,46593,0,0,0,0,0,11,26120,100,0,0,0,0,0,'Wisp Source Bunny - On SpellHit \'Force Wisp Flight Missile\' - Cast \'Wisp Flight Missile and Beam\''),
(26121,0,1,0,61,0,100,0,0,0,0,0,41,9000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wisp Source Bunny - On SpellHit \'Force Wisp Flight Missile\' - Despawn in 9s');

-- Wisp Dest Bunny SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=26120;
DELETE FROM `smart_scripts` WHERE `entryorguid`=26120 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26120,0,0,0,8,0,100,0,46593,0,0,0,41,9000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wisp Dest Bunny - On SpellHit \'Wisp Flight Missile and Beam\' - Despawn in 9s');

-- Shaman Beam Bunny SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (25971,25972,25973);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (25971,25972,25973) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25971,0,0,0,8,0,100,0,45930,0,0,0,11,46339,0,0,0,0,0,1,0,0,0,0,0,0,0,'Shaman Beam Bunny 000 - On SpellHit - Cast \'Bonfire Disguise\''),
(25972,0,0,0,8,0,100,0,45930,0,0,0,11,46339,0,0,0,0,0,1,0,0,0,0,0,0,0,'Shaman Beam Bunny 001 - On SpellHit - Cast \'Bonfire Disguise\''),
(25973,0,0,0,8,0,100,0,45930,0,0,0,11,46339,0,0,0,0,0,1,0,0,0,0,0,0,0,'Shaman Beam Bunny 002 - On SpellHit - Cast \'Bonfire Disguise\'');

-- Ahunite Hailstone SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=25755;
DELETE FROM `smart_scripts` WHERE `entryorguid`=25755 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25755,0,0,0,0,0,100,0,6000,8000,6000,8000,11,2676,0,0,0,0,0,2,0,0,0,0,0,0,0,'Ahunite Hailstone - In Combat - Cast \'Pulverize\'');

-- Ahunite Coldwave SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=25756;
DELETE FROM `smart_scripts` WHERE `entryorguid`=25756 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25756,0,0,0,0,0,100,0,5000,7000,6000,8000,11,46406,0,0,0,0,0,2,0,0,0,0,0,0,0,'Ahunite Coldwave - In Combat - Cast \'Bitter Blast\'');

-- Ahunite Frostwind SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=25757;
DELETE FROM `smart_scripts` WHERE `entryorguid`=25757 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25757,0,0,0,54,0,100,0,0,0,0,0,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ahunite Frostwind - On Just Summoned - Cast \'Lightning Shield\''),
(25757,0,1,0,0,0,100,0,2000,2000,5000,7000,11,46568,0,0,0,0,0,18,120,0,0,0,0,0,0,'Ahunite Frostwind - In Combat - Cast \'Wind Buffet\'');

DELETE FROM `item_loot_template` WHERE `entry`=35512;
INSERT INTO `item_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(35512,17202,0,100,0,1,0,2,5,NULL);

DELETE FROM `item_loot_template` WHERE `Entry`=54536;
INSERT INTO `item_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(54536, 54806, 0, 3, 0, 1, 0, 1, 1),
(54536, 23247, 0, 100, 0, 1, 1, 5, 10),
(54536, 53641, 0, 3, 0, 1, 0, 1, 1);

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID AND @CGUID+8;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(@CGUID,25745,547,1,1,0,0,-96.64146,-230.8864,4.780959,1.413717,300,0,0,1,1,0,0,0,0), -- [PH] Ahune Summon Loc Bunny
(@CGUID+1,25964,547,1,1,0,0,-90.00211,-224.9285,-1.378754,2.956095,300,0,0,1,1,2,0,0,0), -- Shaman Beam Bunny 000
(@CGUID+2,25965,547,1,1,0,0,-97.39627,-223.761,-1.494899,0.9130945,300,0,0,1,1,2,0,0,0), -- Shaman Beam Bunny 001
(@CGUID+3,25966,547,1,1,0,0,-103.3054,-224.0149,0.5259815,5.676991,300,0,0,1,1,2,0,0,0), -- Shaman Beam Bunny 002
(@CGUID+4,26190,547,1,1,0,0,-95.33572,-207.4834,16.28742,4.904375,300,0,0,1,1,0,0,0,0), -- [PH] Spank Target Bunny
(@CGUID+5,25952,547,1,1,0,0,-96.64146,-230.8864,4.780959,1.413717,300,0,0,1,1,0,0,0,0), -- Slippery Floor Bunny
(@CGUID+6,25952,547,1,1,0,0,-69.83901,-162.474,-2.303646,2.513274,300,0,0,1,1,0,0,0,0), -- Slippery Floor Bunny
(@CGUID+7,26239,547,1,1,0,0,-99.10214,-233.1872,-1.22297,1.466077,300,0,0,1,1,0,0,0,0), -- Ghost of Ahune
(@CGUID+8,25746,547,1,1,0,0,-96.8723,-212.8425,-1.149142,4.153883,300,0,0,1,1,0,0,0,0); -- [PH] Ahune Loot Loc Bunny

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID AND @OGUID+19;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 187882, 547, 0, 0, 1, 1, -69.90455, -162.2449, -2.366563, 2.426008, 0, 0, 0.9366722, 0.3502074, 120, 255, 1,0), -- Icestone
(@OGUID+1, 188067, 547, 0, 0, 1, 1,-79.397, -219.7025, -4.042892, -2.199115, 0, 0, -0.8910065, 0.4539906, 120, 255, 1, 0), -- Ice Block
(@OGUID+2, 188067, 547, 0, 0, 1, 1, -115.5985, -162.7724, -1.924025, -0.5585039, 0, 0, -0.2756367, 0.9612619, 120, 255, 1, 0), -- Ice Block
(@OGUID+3, 188067, 547, 0, 0, 1, 1, -71.89625, -145.4974, -1.551813, -1.954766, 0, 0, -0.8290367, 0.5591941, 120, 255, 1, 0), -- Ice Block
(@OGUID+4, 188067, 547, 0, 0, 1, 1, -49.27251, -168.9859, -1.898811, 2.007128, 0, 0, 0.8433914, 0.5372996, 120, 255, 1, 0), -- Ice Block
(@OGUID+5, 188067, 547, 0, 0, 1, 1, -75.95139, -182.771, -4.882017, -1.151916, 0, 0, -0.5446386, 0.8386708, 120, 255, 1, 0), -- Ice Block
(@OGUID+6, 188067, 547, 0, 0, 1, 1, -83.52528, -172.1806, -3.816522, 0.01745246, 0, 0, 0.00872612, 0.9999619, 120, 255, 1, 0), -- Ice Block
(@OGUID+7, 188067, 547, 0, 0, 1, 1, -83.52528, -217.3293, -3.0728, -0.4886912, 0, 0, -0.2419214, 0.9702958, 120, 255, 1, 0), -- Ice Block
(@OGUID+8, 188072, 547, 0, 0, 1, 1, -71.48915, -160.7316, -4.18569, -0.4188786, 0, 0, -0.2079115, 0.9781476, 120, 255, 1, 0), -- Ice Stone Mount
(@OGUID+9, 188072, 547, 0, 0, 1, 1, -69.21773, -163.491, -2.044773, 2.967041, 0, 0, 0.9961939, 0.08716504, 120, 255, 1, 0), -- Ice Stone Mount
(@OGUID+10, 188072, 547, 0, 0, 1, 1, -71.82486, -164.475, -3.962982, -0.9250239, 0, 0, -0.4461975, 0.8949345, 120, 255, 1, 0), -- Ice Stone Mount
(@OGUID+11, 188072, 547, 0, 0, 1, 1, -69.20837, -160.345, -4.25643, 1.850049, 0, 0, 0.7986355, 0.601815, 120, 255, 1, 0), -- Ice Stone Mount
(@OGUID+12, 188073, 547, 0, 0, 1, 1, -89.75205, -113.5002, -2.709442, 0.453785, 0, 0, 0.2249508, 0.9743701, 120, 255, 1, 0), -- Ahune Bonfire
(@OGUID+13, 188073, 547, 0, 0, 1, 1,-114.9574, -117.3017, -2.71, 2.007128, 0, 0, 0.8433914, 0.5372996, 120, 255, 1, 0), -- Ahune Bonfire
(@OGUID+14, 188142, 547, 0, 0, 1, 1,  -74.65959, -243.8125, -2.735999, 2.216565, 0, 0, 0.8949337, 0.4461992, 120, 255, 1, 0), -- Ice Block, Big
(@OGUID+15, 188142, 547, 0, 0, 1, 1, -72.75314, -185.1547, -4.930593, 0.157079, 0, 0, 0.07845879, 0.9969174, 120, 255, 1, 0), -- Ice Block, Big
(@OGUID+16, 188142, 547, 0, 0, 1, 1, -103.7134, -245.5041, -1.377881, -1.291542, 0, 0, -0.6018143, 0.7986361, 120, 255, 1, 0), -- Ice Block, Big
(@OGUID+17, 188142, 547, 0, 0, 1, 1, -118.9196, -204.8023, -1.504161, 1.919862, 0, 0, 0.8191519, 0.5735767, 120, 255, 1, 0), -- Ice Block, Big
(@OGUID+18, 188142, 547, 0, 0, 1, 1, -117.3857, -165.9649, -2.018646, 0.5585039, 0, 0, 0.2756367, 0.9612619, 120, 255, 1, 0), -- Ice Block, Big
(@OGUID+19, 188142, 547, 0, 0, 1, 1, -75.42784, -221.16, -2.882941, 0.4886912, 0, 0, 0.2419214, 0.9702958, 120, 255, 1, 0); -- Ice Block, Big

DELETE FROM `creature_addon` WHERE `guid` IN (@NPC,@NPC+1,@NPC+2);
INSERT INTO `creature_addon` (`guid`,`path_id`) VALUES
(@NPC,@PATH),
(@NPC+1,@PATH+10),
(@NPC+2,@PATH+20);

DELETE FROM `waypoint_data` WHERE `id` IN (@PATH,@PATH+10,@PATH+20);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-107.1537,-233.7247,27.1834,0,0,0,100,0),
(@PATH,2,-109.4618,-232.0907,25.12787,0,0,0,100,0),
(@PATH,3,-109.4792,-229.4328,20.98899,0,0,0,100,0),
(@PATH,4,-105.9522,-226.8887,17.26674,0,0,0,100,0),
(@PATH,5,-101.0044,-224.8914,16.04452,0,0,0,100,0),
(@PATH,6,-96.82773,-225.9608,15.73896,0,0,0,100,0),
(@PATH,7,-92.59879,-227.0505,15.54452,0,0,0,100,0),
(@PATH,8,-90.07465,-229.0938,16.58224,0,0,0,100,0),
(@PATH,9,-88.24558,-231.7715,22.47455,0,0,0,100,0),
(@PATH,10,-91.0969,-232.6422,24.65563,0,0,0,100,0),
(@PATH,11,-97.20647,-234.4709,28.46118,0,0,0,100,0),
(@PATH,12,-101.5825,-234.9054,29.35008,0,0,0,100,0),

(@PATH+10,1,-109.4618,-232.0907,25.12787,0,0,0,100,0),
(@PATH+10,2,-109.4792,-229.4328,20.98899,0,0,0,100,0),
(@PATH+10,3,-105.9522,-226.8887,17.26674,0,0,0,100,0),
(@PATH+10,4,-101.0044,-224.8914,16.04452,0,0,0,100,0),
(@PATH+10,5,-96.82773,-225.9608,15.73896,0,0,0,100,0),
(@PATH+10,6,-92.59879,-227.0505,15.54452,0,0,0,100,0),
(@PATH+10,7,-90.07465,-229.0938,16.58224,0,0,0,100,0),
(@PATH+10,8,-88.24558,-231.7715,22.47455,0,0,0,100,0),
(@PATH+10,9,-91.0969,-232.6422,24.65563,0,0,0,100,0),
(@PATH+10,10,-97.20647,-234.4709,28.46118,0,0,0,100,0),
(@PATH+10,11,-101.5825,-234.9054,29.35008,0,0,0,100,0),
(@PATH+10,12,-107.1537,-233.7247,27.1834,0,0,0,100,0),

(@PATH+20,1,-97.20647,-234.4709,28.46118,0,0,0,100,0),
(@PATH+20,2,-101.5825,-234.9054,29.35008,0,0,0,100,0),
(@PATH+20,3,-107.1537,-233.7247,27.1834,0,0,0,100,0),
(@PATH+20,4,-109.4618,-232.0907,25.12787,0,0,0,100,0),
(@PATH+20,5,-109.4792,-229.4328,20.98899,0,0,0,100,0),
(@PATH+20,6,-105.9522,-226.8887,17.26674,0,0,0,100,0),
(@PATH+20,7,-101.0044,-224.8914,16.04452,0,0,0,100,0),
(@PATH+20,8,-96.82773,-225.9608,15.73896,0,0,0,100,0),
(@PATH+20,9,-92.59879,-227.0505,15.54452,0,0,0,100,0),
(@PATH+20,10,-90.07465,-229.0938,16.58224,0,0,0,100,0),
(@PATH+20,11,-88.24558,-231.7715,22.47455,0,0,0,100,0),
(@PATH+20,12,-91.0969,-232.6422,24.65563,0,0,0,100,0);

DELETE FROM `game_event_creature` WHERE `guid` BETWEEN @CGUID AND @CGUID+8 AND `eventEntry`=1;
INSERT INTO `game_event_creature` (`eventEntry`,`guid`) VALUES
(1,@CGUID),
(1,@CGUID+1),
(1,@CGUID+2),
(1,@CGUID+3),
(1,@CGUID+4),
(1,@CGUID+5),
(1,@CGUID+6),
(1,@CGUID+7),
(1,@CGUID+8);

DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN @OGUID AND @OGUID+19 AND `eventEntry`=1;
INSERT INTO `game_event_gameobject` (`eventEntry`,`guid`) VALUES
(1,@OGUID),
(1,@OGUID+1),
(1,@OGUID+2),
(1,@OGUID+3),
(1,@OGUID+4),
(1,@OGUID+5),
(1,@OGUID+6),
(1,@OGUID+7),
(1,@OGUID+8),
(1,@OGUID+9),
(1,@OGUID+10),
(1,@OGUID+11),
(1,@OGUID+12),
(1,@OGUID+13),
(1,@OGUID+14),
(1,@OGUID+15),
(1,@OGUID+16),
(1,@OGUID+17),
(1,@OGUID+18),
(1,@OGUID+19);
