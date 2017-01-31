-- The Battle For Crusaders' Pinnacle (13141)

SET @SPELL_ITEM_BANNER      := 58013; -- Plant Blessed Banner
SET @SPELL_TORCH            := 58121;
SET @SPELL_TORCH_EFFECT     := 58125;

SET @NPC_BLESSED_BANNER     := 30891; -- Blessed Banner of the Crusade
SET @NPC_CRUSADER_DALFORS   := 31003; -- Crusader Lord Dalfors
SET @NPC_BATTLE_PRIEST      := 30919; -- Argent Battle-priest
SET @NPC_MASON              := 30900; -- Argent Mason
SET @NPC_TORCH_DUMMY        := 31004; -- (Wave 0) Torch Dummy
SET @NPC_LK                 := 31013; -- The Lich King
SET @NPC_CAPTAIN            := 30986;
SET @NPC_DRUDGE             := 30984;
SET @NPC_PLAGEBRINGER       := 30987;
SET @NPC_HALOF              := 30989;

SET @EVENT_SCRIPT           := 20082;

DELETE FROM `spell_target_position` WHERE `id`=@SPELL_ITEM_BANNER;
INSERT INTO `spell_target_position` (`id`,`target_map`,`target_position_x`,`target_position_y`,`target_position_z`,`target_orientation`) VALUES
(@SPELL_ITEM_BANNER,571,6418.42,422.97,511.11,0);

UPDATE `creature_template` SET `faction_A`=2140,`faction_H`=2140,`ScriptName`='npc_blessed_banner' WHERE `entry`=@NPC_BLESSED_BANNER;
UPDATE `creature_template` SET `faction_A`=2131,`faction_H`=2131,`AIName`='SmartAI',`unit_flags`=32768,`equipment_id`=@NPC_CRUSADER_DALFORS WHERE `entry`=@NPC_CRUSADER_DALFORS;
UPDATE `creature_template` SET `faction_A`=2131,`faction_H`=2131,`AIName`='SmartAI',`unit_flags`=32768,`equipment_id`=@NPC_BATTLE_PRIEST WHERE `entry`=@NPC_BATTLE_PRIEST;
UPDATE `creature_template` SET `faction_A`=2070,`faction_H`=2070,`unit_flags`=32768,`AIName`='SmartAI',`equipment_id`=@NPC_MASON WHERE `entry`=@NPC_MASON;
UPDATE `creature_template` SET `unit_flags`=33554432,`InhabitType`=4,`AIName`='SmartAI',`flags_extra`=128 WHERE `entry`=@NPC_TORCH_DUMMY;
UPDATE `creature_template` SET `unit_flags`=33554432,`flags_extra`=128 WHERE `entry`=@NPC_LK;
UPDATE `creature_template` SET `faction_A`=2068,`faction_H`=2068,`unit_flags`=32768,`AIName`='SmartAI' WHERE `entry`=@NPC_CAPTAIN;
UPDATE `creature_template` SET `faction_A`=2068,`faction_H`=2068,`unit_flags`=32768,`AIName`='SmartAI' WHERE `entry`=@NPC_DRUDGE;
UPDATE `creature_template` SET `faction_A`=2068,`faction_H`=2068,`unit_flags`=32768,`AIName`='SmartAI' WHERE `entry`=@NPC_PLAGEBRINGER;
UPDATE `creature_template` SET `faction_A`=2068,`faction_H`=2068,`unit_flags`=32768 WHERE `entry`=@NPC_HALOF;

DELETE FROM `creature_template_addon` WHERE `entry` IN (@NPC_BLESSED_BANNER,@NPC_CRUSADER_DALFORS,@NPC_BATTLE_PRIEST,@NPC_MASON);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(@NPC_BLESSED_BANNER, 0, 0x0, 0x1, '58026'), -- Blessing of the Crusade
(@NPC_CRUSADER_DALFORS,2786,0x0,0x1,'58110'), -- Threat Pulse
(@NPC_BATTLE_PRIEST,0,0x0,0x1,'58110'), -- Threat Pulse
(@NPC_MASON,0,0x0,0x1,'');

DELETE FROM `creature_equip_template` WHERE `entry` IN (@NPC_CRUSADER_DALFORS,@NPC_BATTLE_PRIEST,@NPC_MASON);
INSERT INTO `creature_equip_template` (`entry`,`itemEntry1`,`itemEntry2`,`itemEntry3`) VALUES
(@NPC_CRUSADER_DALFORS,39290,40596,0),
(@NPC_BATTLE_PRIEST,42544,42543,0),
(@NPC_MASON,1906,2081,0);

DELETE FROM `creature_text` WHERE `entry` IN (@NPC_BLESSED_BANNER,@NPC_CRUSADER_DALFORS,@NPC_LK);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@NPC_BLESSED_BANNER,0,0,'The Blessed Banner of the Crusade has been planted.\n Defend the banner from all attackers!',41,0,100,0,0,0,'Blessed Banner of the Crusade'),
(@NPC_CRUSADER_DALFORS,0,0,'BY THE LIGHT! Those damned monsters! Look at what they''ve done to our people!',12,0,100,5,0,0,'Crusader Lord Dalfors'),
(@NPC_CRUSADER_DALFORS,1,0,'Burn it down, boys. Burn it all down.',12,0,100,1,0,0,'Crusader Lord Dalfors'),
(@NPC_CRUSADER_DALFORS,2,0,'Let ''em come. They''ll pay for what they''ve done!',12,0,100,1,0,0,'Crusader Lord Dalfors'),
(@NPC_CRUSADER_DALFORS,3,0,'We''ve done it, lads! We''ve taken the pinnacle from the Scourge! Report to Father Gustav at once and tell him the good news! We''re gonna get to buildin'' and settin'' up! Go!',14,0,100,71,0,0,'Crusader Lord Dalfors'),
(@NPC_LK,0,0,'Leave no survivors!',14,0,100,0,0,14793,'The Lich King'),
(@NPC_LK,1,0,'Cower before my terrible creations!',14,0,100,0,0,14800,'The Lich King'),
(@NPC_LK,2,0,'Feast my children! Feast upon the flesh of the living!',14,0,100,0,0,14801,'The Lich King'),
(@NPC_LK,3,0,'Lay down your arms and surrender your souls!',14,0,100,0,0,14802,'The Lich King');

DELETE FROM `event_scripts` WHERE `id`=@EVENT_SCRIPT;
INSERT INTO `event_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `x`, `y`, `z`, `o`) VALUES
(@EVENT_SCRIPT,0,10,@NPC_BLESSED_BANNER,600000,6418.422,422.9706,511.1964,5.8119);

SET @CGUID  := 85714; -- need 18 (85714<->85731)
DELETE FROM `creature` WHERE `id` IN (@NPC_TORCH_DUMMY,@NPC_LK);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`MovementType`) VALUES
(@CGUID+0,@NPC_TORCH_DUMMY,571,1,128,6405.316,431.9516,518.2324,0.296706,120,0,0),
(@CGUID+1,@NPC_TORCH_DUMMY,571,1,128,6408.057,424.2077,511.3653,1.256637,120,0,0),
(@CGUID+2,@NPC_TORCH_DUMMY,571,1,128,6371.181,452.4539,513.5053,1.204277,120,0,0),
(@CGUID+3,@NPC_TORCH_DUMMY,571,1,128,6391.331,460.3002,511.3657,1.745329,120,0,0),
(@CGUID+4,@NPC_TORCH_DUMMY,571,1,128,6393.723,427.9692,538.7354,1.692969,120,0,0),
(@CGUID+5,@NPC_TORCH_DUMMY,571,1,128,6374.808,445.4873,517.7629,4.031711,120,0,0),
(@CGUID+6,@NPC_TORCH_DUMMY,571,1,128,6382.271,451.9008,537.9304,1.32645,120,0,0),
(@CGUID+7,@NPC_TORCH_DUMMY,571,1,128,6366.836,459.1225,530.3361,0.7330383,120,0,0),
(@CGUID+8,@NPC_TORCH_DUMMY,571,1,128,6372.479,447.4598,511.3725,0.2443461,120,0,0),
(@CGUID+9,@NPC_TORCH_DUMMY,571,1,128,6394.698,427.4731,523.7177,1.850049,120,0,0),
(@CGUID+10,@NPC_TORCH_DUMMY,571,1,128,6367.246,459.7583,518.8009,3.857178,120,0,0),
(@CGUID+11,@NPC_TORCH_DUMMY,571,1,128,6396.961,432.8676,533.744,3.176499,120,0,0),
(@CGUID+12,@NPC_TORCH_DUMMY,571,1,128,6403.202,464.2955,535.6572,3.857178,120,0,0),
(@CGUID+13,@NPC_TORCH_DUMMY,571,1,128,6401.721,464.4387,543.1727,2.199115,120,0,0),
(@CGUID+14,@NPC_TORCH_DUMMY,571,1,128,6392.169,475.7449,512.7209,0.6283185,120,0,0),
(@CGUID+15,@NPC_TORCH_DUMMY,571,1,128,6397.238,475.2313,529.652,4.328416,120,0,0),
(@CGUID+16,@NPC_TORCH_DUMMY,571,1,128,6389.221,474.0008,511.365,1.553343,120,0,0),
(@CGUID+17,@NPC_LK,571,1,128,6389.73,451.2743,513.3198,1.32645,120,0,0);

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (@NPC_TORCH_DUMMY,@NPC_MASON);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC_TORCH_DUMMY,0,0,0,8,0,100,0,@SPELL_TORCH,0,0,0,11,@SPELL_TORCH_EFFECT,0,0,0,0,0,1,0,0,0,0,0,0,0,'On spellhit - Cast Torch Visual'),
(@NPC_MASON,0,0,0,38,0,100,0,1,1,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'On data - Set phase 1'),
(@NPC_MASON,0,1,0,60,1,100,0,0,10000,10000,20000,11,@SPELL_TORCH,0,0,0,0,0,1,0,0,0,0,0,0,0,'On update - Cast spell Torch');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=13 AND `SourceEntry`=@SPELL_TORCH) OR (`SourceTypeOrReferenceId`=17 AND `SourceEntry`=@SPELL_ITEM_BANNER);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,@SPELL_TORCH,0,0,31,0,3,@NPC_TORCH_DUMMY,0,0,0,'','Spell Torch targets Torch Dummy'),
(17,0,@SPELL_ITEM_BANNER,0,0,29,0,@NPC_BLESSED_BANNER,10,0,1,0,'','Cast Plant Blessed Banner if no banner is already spawned.');

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (@NPC_CRUSADER_DALFORS,@NPC_BATTLE_PRIEST,@NPC_CAPTAIN,@NPC_DRUDGE,@NPC_PLAGEBRINGER);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Crusader Lord Dalfors
(@NPC_CRUSADER_DALFORS,0,0,0,2,0,100,1,0,50,0,0,11,58053,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Holy Light at 50% HP'),
(@NPC_CRUSADER_DALFORS,0,1,0,0,0,100,0,5000,8000,23000,29000,11,37554,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield'),
-- Argent Battle-priest
(@NPC_BATTLE_PRIEST,0,0,0,1,0,100,0,500,1000,600000,600000,11,58054,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blessing of Kings on Spawn'),
(@NPC_BATTLE_PRIEST,0,1,0,2,0,100,1,0,50,0,0,11,58053,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Holy Light at 50% HP'),
(@NPC_BATTLE_PRIEST,0,2,0,14,0,100,0,50000,10,20000,30000,11,58053,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Holy Light on Friendlies'),
-- Reanimated Captain
(@NPC_CAPTAIN,0,0,0,4,0,100,1,0,0,0,0,11,32674,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Avenger''s Shield on Aggro'),
(@NPC_CAPTAIN,0,1,0,0,0,100,0,5000,5000,17800,19800,11,58154,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hammer of Injustice'),
(@NPC_CAPTAIN,0,2,0,2,0,100,1,0,45,0,0,11,58153,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Unholy Light at 45% HP'),
(@NPC_CAPTAIN,0,3,0,14,0,100,0,4000,10,20000,30000,11,58153,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Unholy Light on Friendlies'),
-- Scourge Drudge
(@NPC_DRUDGE,0,0,0,0,0,100,0,5000,5000,11300,14500,11,51917,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave'),
(@NPC_DRUDGE,0,1,0,0,0,100,0,7000,9000,17800,20200,11,49678,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flesh Rot'),
-- Hideous Plaguebringer
(@NPC_PLAGEBRINGER,0,0,0,0,0,100,0,3400,4600,11400,16500,11,38761,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcing Smash');
