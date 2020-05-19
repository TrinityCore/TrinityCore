SET @CGUID := 396235;
SET @OGUID := 239773;

-- Template Updates
-- Deathwing
UPDATE `creature_template` SET `ScriptName`= 'boss_madness_of_deathwing' WHERE `entry`= 56173;
UPDATE `creature_template` SET `unit_flags2`= 134250496, `VehicleId`= 1849 WHERE `entry` IN (56173, 57969, 58000, 58001);
-- Deathwing (Health)
UPDATE `creature_template` SET `AIName`= 'NullCreatureAI' WHERE `entry`= 57962;
UPDATE `creature_template` SET `unit_flags`= 33554432, `unit_flags2`= 134250496, `RegenHealth`= 0 WHERE `entry` IN (57962, 57970, 58125, 58126);
-- Limb Tentacles
UPDATE `creature_template` SET `ScriptName`= 'npc_madness_of_deathwing_limb_tentacle' WHERE `entry` IN (56167, 56846, 56168);
UPDATE `creature_template` SET `RegenHealth`= 0 WHERE `entry` IN (56167, 56846, 56168, 57973, 58131, 58132, 57974, 58133, 58134, 57972, 58129, 58130);
-- Deatwhing Wing R
UPDATE `creature_template` SET `unit_flags`= 33554432, `unit_flags2`= 134250496, `VehicleId`= 1954, `ScriptName`= 'npc_madness_of_deathwing_cosmetic_limb' WHERE `entry`= 57695;
-- Deathwing Wing L
UPDATE `creature_template` SET `unit_flags`= 33554432, `unit_flags2`= 134250496, `VehicleId`= 1954, `ScriptName`= 'npc_madness_of_deathwing_cosmetic_limb' WHERE `entry`= 57696;
-- Deathwing Arm R
UPDATE `creature_template` SET `unit_flags`= 33554432, `unit_flags2`= 134250496, `VehicleId`= 1951, `ScriptName`= 'npc_madness_of_deathwing_cosmetic_limb' WHERE `entry`= 57686;
-- Deathwing Arm L
UPDATE `creature_template` SET `unit_flags`= 33554432, `unit_flags2`= 134250496, `VehicleId`= 1951, `ScriptName`= 'npc_madness_of_deathwing_cosmetic_limb' WHERE `entry`= 57694;
-- Cosmetic Tentacle
UPDATE `creature_template` SET `unit_flags`= 33554432, `unit_flags2`= 134217728 WHERE `entry`= 57693;
-- Mutated Corruption
UPDATE `creature_template` SET `ScriptName`= 'npc_madness_of_deathwing_mutated_corruption' WHERE `entry`= 56471;
-- Regenerative Blood
UPDATE `creature_template` SET `ScriptName`= 'npc_madness_of_deathwing_regenerative_blood' WHERE `entry`= 56263;
UPDATE `creature_template` SET `VehicleId` = 1857, `unit_class`= 4, `speed_run`= 1.71428, `unit_flags2`= 134217728 WHERE `entry` IN (56263, 57975, 58135, 58136);
-- Elementium Bolt
UPDATE `creature_template` SET `speed_run`= 7.1428, `RegenHealth`= 0, `ScriptName`= 'npc_madness_of_deathwing_elementium_bolt' WHERE `entry`= 56262;
-- Elementium Fragment
UPDATE `creature_template` SET `ScriptName`= 'npc_mandess_of_deathwing_elementium_fragment' WHERE `entry`= 56724;
UPDATE `creature_template` SET `unit_flags2`= 134217728 WHERE `entry` IN (56724, 57977, 58140, 58141);
-- Elementium Terror
UPDATE `creature_template` SET `ScriptName`= 'npc_mandess_of_deathwing_elementium_terror' WHERE `entry`= 56710;
UPDATE `creature_template` SET `unit_flags2`= 134217728 WHERE `entry` IN (56710, 57971, 58127, 58128);
-- Claw Mark
UPDATE `creature_template` SET `unit_flags2`= 34816, `flags_extra`= 128, `VehicleId`= 1994 WHERE `entry`= 56545;
-- Time Zone Target
UPDATE `creature_template` SET `flags_extra`= 128 WHERE `entry`= 56332;
-- Time Zone
UPDATE `creature_template` SET `flags_extra`= 128 WHERE `entry`= 56311;
-- Crush Target
UPDATE `creature_template` SET `flags_extra`= 128 WHERE `entry`= 56581;
-- Blistering Tentacle
UPDATE `creature_template` SET `AIName`= 'NullCreatureAI' WHERE `entry`= 56188;
UPDATE `creature_template` SET `unit_flags2`= 134217728, `RegenHealth`= 0 WHERE `entry` IN (56188, 57978, 58142, 58143);
-- Thrall
UPDATE `creature_template` SET `unit_flags`= 32768, `npcflag`= 1, `gossip_menu_id`= 13295, `VehicleId`= 1892, `flags_extra`= 512, `ScriptName`= 'npc_madness_of_deathwing_thrall' WHERE `entry`= 56103;
-- Congealing Blood Target
UPDATE `creature_template` SET `flags_extra`= 128 WHERE `entry`= 57788;
-- Hemorrhage Target
UPDATE `creature_template` SET `flags_extra`= 128 WHERE `entry`= 56359;
-- Jump Pad
UPDATE `creature_template` SET `flags_extra`= 128 WHERE `entry`= 56699;
-- Tail Tentacle Target
UPDATE `creature_template` SET `flags_extra`= 128 WHERE `entry`= 56519;
-- Cataclysm Stalker
UPDATE `creature_template` SET `flags_extra`= 128 WHERE `entry`= 56642;
-- Platform
UPDATE `creature_template` SET `flags_extra`= 128 WHERE `entry`= 56307;
-- Travel to Wyrmrest Base
UPDATE `creature_template` SET `flags_extra`= 128 WHERE `entry`= 57882;
-- Travel to the deck of The Skyfire
UPDATE `creature_template` SET `flags_extra`= 128 WHERE `entry`= 57378;
-- Ysera
UPDATE `creature_template` SET `unit_flags`= 320, `ScriptName`= 'npc_madness_of_deathwing_dragon_aspect' WHERE `entry`= 56100;
-- Alexstrasza
UPDATE `creature_template` SET `unit_flags`= 320, `ScriptName`= 'npc_madness_of_deathwing_dragon_aspect' WHERE `entry`= 56099;
-- Nozdormu
UPDATE `creature_template` SET `unit_flags`= 320, `ScriptName`= 'npc_madness_of_deathwing_dragon_aspect' WHERE `entry`= 56102;
-- Kalecgos
UPDATE `creature_template` SET `unit_flags`= 320, `ScriptName`= 'npc_madness_of_deathwing_dragon_aspect' WHERE `entry`= 56101;

-- Addons
-- Thrall
UPDATE `creature_template_addon` SET `bytes2`= 1 WHERE `entry`= 56103;
-- Alexstrasza
UPDATE `creature_template_addon` SET `bytes1`=50331648, `bytes2`=1, `auras`='105825' WHERE `entry`=56099;
-- Nozdormu
UPDATE `creature_template_addon` SET `bytes1`=50331648, `bytes2`=1, `auras`='105823' WHERE `entry`=56102;
-- Kalecgos
UPDATE `creature_template_addon` SET `bytes1`=50331648, `bytes2`=1, `auras`='106026 106039' WHERE `entry`=56101;
-- Ysera
UPDATE `creature_template_addon` SET `bytes1`=50331648, `bytes2`=1, `auras`='106456 106463' WHERE `entry`=56100;
-- Time Zone
UPDATE `creature_template_addon` SET `auras`= '105831' WHERE `entry`= 56311;
-- Blistering Tentacle
UPDATE `creature_template_addon` SET `aiAnimKit`= 1732, `auras`= '105444' WHERE `entry` IN (56188, 57978, 58142, 58143);
-- Mutated Corruption
UPDATE `creature_template_addon` SET `meleeAnimKit`= 1716, `auras`= '110470' WHERE `entry` IN (56471, 57976, 58137, 58138);
-- Tail Tentacle
UPDATE `creature_template_addon` SET `meleeAnimKit`= 1716 WHERE `entry`= 56844;
-- Regenerative Blood
UPDATE `creature_template_addon` SET `auras`= '105842' WHERE `entry` IN (56263, 57975, 58135, 58136);
-- Claw Mark
UPDATE `creature_template_addon` SET `auras`= '106273' WHERE `entry`= 56545;
-- Elementium Fragment
UPDATE `creature_template_addon` SET `auras`= '106814' WHERE `entry` IN (56724, 57977, 58140, 58141);
-- Elementium Terror
UPDATE `creature_template_addon` SET `auras`= '105842 106728' WHERE `entry` IN (56710, 57971, 58127, 58128);

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_madness_of_deathwing_presence_of_the_aspects',
'spell_madness_of_deathwing_carrying_winds_jump',
'spell_madness_of_deathwing_carrying_winds_triggered',
'spell_madness_of_deathwing_limb_emerge_visual',
'spell_madness_of_deathwing_agonizing_pain',
'spell_madness_of_deathwing_assault_aspects',
'spell_madness_of_deathwing_face_trigger',
'spell_madness_of_deathwing_summon_tail',
'spell_madness_of_deathwing_crush',
'spell_madness_of_deathwing_hemorrhage',
'spell_madness_of_deathwing_hemorrhage_script',
'spell_madness_of_deathwing_regenerative_blood_script',
'spell_madness_of_deathwing_regenerative_blood_periodic',
'spell_madness_of_deathwing_elementium_meteor_script',
'spell_madness_of_deathwing_elementium_meteor_visual',
'spell_madness_of_deathwing_burning_blood',
'spell_madness_of_deathwing_spawn_blistering_tentacles',
'spell_madness_of_deathwing_time_zone',
'spell_madness_of_deathwing_trigger_concentration',
'spell_madness_of_deathwing_concentration',
'spell_madness_of_deathwing_trigger_aspect_buffs',
'spell_madness_of_deathwing_share_health',
'spell_madness_of_deathwing_summon_elementium_terror',
'spell_madness_of_deathwing_summon_impaling_tentacle',
'spell_madness_of_deathwing_shrapnel',
'spell_madness_of_deathwing_fire_dragon_soul',
'spell_madness_of_deathwing_trigger_aspect_yell',
'spell_madness_of_deathwing_fire_dragon_soul_aspects',
'spell_madness_of_deathwing_corrupted_blood_stacker',
'spell_madness_of_deathwing_corrupted_blood',
'spell_madness_of_deathwing_spellweave',
'spell_madness_of_deathwing_elementium_blast',
'spell_madness_of_deathwing_cataclysm');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(106028, 'spell_madness_of_deathwing_presence_of_the_aspects'),
(109571, 'spell_madness_of_deathwing_presence_of_the_aspects'),
(109572, 'spell_madness_of_deathwing_presence_of_the_aspects'),
(109573, 'spell_madness_of_deathwing_presence_of_the_aspects'),
(106027, 'spell_madness_of_deathwing_presence_of_the_aspects'),
(109622, 'spell_madness_of_deathwing_presence_of_the_aspects'),
(109623, 'spell_madness_of_deathwing_presence_of_the_aspects'),
(109624, 'spell_madness_of_deathwing_presence_of_the_aspects'),
(106457, 'spell_madness_of_deathwing_presence_of_the_aspects'),
(109640, 'spell_madness_of_deathwing_presence_of_the_aspects'),
(109641, 'spell_madness_of_deathwing_presence_of_the_aspects'),
(109642, 'spell_madness_of_deathwing_presence_of_the_aspects'),
(106029, 'spell_madness_of_deathwing_presence_of_the_aspects'),
(109606, 'spell_madness_of_deathwing_presence_of_the_aspects'),
(109607, 'spell_madness_of_deathwing_presence_of_the_aspects'),
(109608, 'spell_madness_of_deathwing_presence_of_the_aspects'),
(106671, 'spell_madness_of_deathwing_carrying_winds_jump'),
(106673, 'spell_madness_of_deathwing_carrying_winds_jump'),
(106675, 'spell_madness_of_deathwing_carrying_winds_jump'),
(106677, 'spell_madness_of_deathwing_carrying_winds_jump'),
(106666, 'spell_madness_of_deathwing_carrying_winds_jump'),
(106669, 'spell_madness_of_deathwing_carrying_winds_jump'),
(106664, 'spell_madness_of_deathwing_carrying_winds_triggered'),
(109963, 'spell_madness_of_deathwing_carrying_winds_triggered'),
(109962, 'spell_madness_of_deathwing_carrying_winds_triggered'),
(109961, 'spell_madness_of_deathwing_carrying_winds_triggered'),
(107991, 'spell_madness_of_deathwing_limb_emerge_visual'),
(106548, 'spell_madness_of_deathwing_agonizing_pain'),
(107018, 'spell_madness_of_deathwing_assault_aspects'),
(106513, 'spell_madness_of_deathwing_face_trigger'),
(106239, 'spell_madness_of_deathwing_summon_tail'),
(106382, 'spell_madness_of_deathwing_crush'),
(105853, 'spell_madness_of_deathwing_hemorrhage'),
(105862, 'spell_madness_of_deathwing_hemorrhage_script'),
(105934, 'spell_madness_of_deathwing_regenerative_blood_script'),
(105932, 'spell_madness_of_deathwing_regenerative_blood_periodic'),
(105599, 'spell_madness_of_deathwing_elementium_meteor_script'),
(106242, 'spell_madness_of_deathwing_elementium_meteor_visual'),
(105401, 'spell_madness_of_deathwing_burning_blood'),
(109616, 'spell_madness_of_deathwing_burning_blood'),
(109617, 'spell_madness_of_deathwing_burning_blood'),
(109618, 'spell_madness_of_deathwing_burning_blood'),
(105551, 'spell_madness_of_deathwing_spawn_blistering_tentacles'),
(106919, 'spell_madness_of_deathwing_time_zone'),
(106940, 'spell_madness_of_deathwing_trigger_concentration'),
(106644, 'spell_madness_of_deathwing_concentration'),
(106643, 'spell_madness_of_deathwing_concentration'),
(106641, 'spell_madness_of_deathwing_concentration'),
(106642, 'spell_madness_of_deathwing_concentration'),
(106943, 'spell_madness_of_deathwing_trigger_aspect_buffs'),
(109547, 'spell_madness_of_deathwing_share_health'),
(106765, 'spell_madness_of_deathwing_summon_elementium_terror'),
(106775, 'spell_madness_of_deathwing_summon_impaling_tentacle'),
(109568, 'spell_madness_of_deathwing_summon_impaling_tentacle'),
(109958, 'spell_madness_of_deathwing_summon_impaling_tentacle'),
(109957, 'spell_madness_of_deathwing_summon_impaling_tentacle'),
(106789, 'spell_madness_of_deathwing_shrapnel'),
(110065, 'spell_madness_of_deathwing_fire_dragon_soul'),
(110067, 'spell_madness_of_deathwing_fire_dragon_soul_aspects'),
(109708, 'spell_madness_of_deathwing_trigger_aspect_yell'),
(106843, 'spell_madness_of_deathwing_corrupted_blood_stacker'),
(106834, 'spell_madness_of_deathwing_corrupted_blood'),
(109592, 'spell_madness_of_deathwing_corrupted_blood'),
(109593, 'spell_madness_of_deathwing_corrupted_blood'),
(109594, 'spell_madness_of_deathwing_corrupted_blood'),
(106043, 'spell_madness_of_deathwing_spellweave'),
(109609, 'spell_madness_of_deathwing_spellweave'),
(109610, 'spell_madness_of_deathwing_spellweave'),
(109611, 'spell_madness_of_deathwing_spellweave'),
(105723, 'spell_madness_of_deathwing_elementium_blast'),
(109600, 'spell_madness_of_deathwing_elementium_blast'),
(109601, 'spell_madness_of_deathwing_elementium_blast'),
(109602, 'spell_madness_of_deathwing_elementium_blast'),
(106523, 'spell_madness_of_deathwing_cataclysm'),
(110044, 'spell_madness_of_deathwing_cataclysm'),
(110043, 'spell_madness_of_deathwing_cataclysm'),
(110042, 'spell_madness_of_deathwing_cataclysm');

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry` IN (106672, 106674, 106668, 106670, 106676, 106663, 109547, 106548, 106239, 105853, 105862, 105934, 105937, 110210, 110209, 110208, 105599, 106242, 106919, 105830, 105569, 109576, 109577, 109578, 106644, 106643, 106641, 106642, 109548, 106766, 106776, 106789, 110065, 110067, 109708, 110072, 110077, 110071, 110076, 109971, 106943, 106940, 106761, 106538) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`,  `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 106672, 0, 0, 31, 0, 3, 56699, @CGUID+15, 0, 0, '', 'Carrying Winds - Target Jump Pad'),
(13, 1, 106674, 0, 0, 31, 0, 3, 56699, @CGUID+25, 0, 0, '', 'Carrying Winds - Target Jump Pad'),
(13, 1, 106668, 0, 0, 31, 0, 3, 56699, @CGUID+44, 0, 0, '', 'Carrying Winds - Target Jump Pad'),
(13, 1, 106670, 0, 0, 31, 0, 3, 56699, @CGUID+3, 0, 0, '', 'Carrying Winds - Target Jump Pad'),
(13, 1, 106676, 0, 0, 31, 0, 3, 56699, @CGUID+4, 0, 0, '', 'Carrying Winds - Target Jump Pad'),
(13, 1, 106663, 0, 0, 31, 0, 3, 56699, @CGUID+31, 0, 0, '', 'Carrying Winds - Target Jump Pad'),
(13, 3, 109547, 0, 0, 31, 0, 3, 57962, 0, 0, 0, '', 'Share Health - Target Deathwing'),
(13, 1, 109548, 0, 0, 31, 0, 3, 56173, 0, 0, 0, '', 'Share Health - Target Deathwing'),
(13, 7, 106548, 0, 0, 31, 0, 3, 56173, 0, 0, 0, '', 'Agonizing Pain - Target Deathwing'),
(13, 1, 106239, 0, 0, 31, 0, 3, 56519, 0, 0, 0, '', 'Summon Tail - Target Tail Tentacle Targte'),
(13, 1, 105853, 0, 0, 31, 0, 3, 56307, 0, 0, 0, '', 'Hemorrhage - Target Platform'),
(13, 1, 105862, 0, 0, 31, 0, 3, 56307, 0, 0, 0, '', 'Hemorrhage - Target Platform'),
(13, 1, 105934, 0, 0, 31, 0, 3, 56263, 0, 0, 0, '', 'Regenerative Blood - Target Regenerative Blood'),
(13, 1, 105937, 0, 0, 31, 0, 3, 56263, 0, 0, 0, '', 'Regenerative Blood - Target Regenerative Blood'),
(13, 1, 110210, 0, 0, 31, 0, 3, 56263, 0, 0, 0, '', 'Regenerative Blood - Target Regenerative Blood'),
(13, 1, 110209, 0, 0, 31, 0, 3, 56263, 0, 0, 0, '', 'Regenerative Blood - Target Regenerative Blood'),
(13, 1, 110208, 0, 0, 31, 0, 3, 56263, 0, 0, 0, '', 'Regenerative Blood - Target Regenerative Blood'),
(13, 1, 105599, 0, 0, 31, 0, 3, 56262, 0, 0, 0, '', 'Elementium Meteor - Target Elementium Bolt'),
(13, 1, 106242, 0, 0, 31, 0, 3, 56307, 0, 0, 0, '', 'Elementium Meteor - Target Platform'),
(13, 1, 106919, 0, 0, 31, 0, 3, 56307, 0, 0, 0, '', 'Time Zone - Target Platform'),
(13, 7, 105830, 0, 0, 31, 0, 3, 56263, 0, 0, 0, '', 'Time Zone - Target Regenerative Blood'),
(13, 7, 105830, 0, 1, 31, 0, 3, 56710, 0, 0, 0, '', 'Time Zone - Target Elementium Terror'),
(13, 1, 105569, 0, 0, 31, 0, 3, 56188, 0, 0, 0, '', 'Cauterize - Target Blistering Tentacle'),
(13, 1, 109576, 0, 0, 31, 0, 3, 56188, 0, 0, 0, '', 'Cauterize - Target Blistering Tentacle'),
(13, 1, 109577, 0, 0, 31, 0, 3, 56188, 0, 0, 0, '', 'Cauterize - Target Blistering Tentacle'),
(13, 1, 109578, 0, 0, 31, 0, 3, 56188, 0, 0, 0, '', 'Cauterize - Target Blistering Tentacle'),
(13, 1, 106644, 0, 0, 31, 0, 3, 57696, 0, 0, 0, '', 'Concentration - Target Deathwing Wing L'),
(13, 1, 106643, 0, 0, 31, 0, 3, 57694, 0, 0, 0, '', 'Concentration - Target Deathwing Arm L'),
(13, 1, 106641, 0, 0, 31, 0, 3, 57695, 0, 0, 0, '', 'Concentration - Target Deathwing Wing R'),
(13, 1, 106642, 0, 0, 31, 0, 3, 57686, 0, 0, 0, '', 'Concentration - Target Deathwing Arm R'),
(13, 1, 106766, 0, 0, 31, 0, 3, 56307, @CGUID+5, 0, 0, '', 'Elementium Terror - Target Ysera''s Platform'),
(13, 1, 106776, 0, 0, 31, 0, 3, 56307, @CGUID+5, 0, 0, '', 'Elementium Terror - Target Ysera''s Platform'),
(13, 1, 106789, 0, 0, 31, 0, 3, 56724, 0, 0, 0, '', 'Shrapnel - Target Elementium Fragment'),
(13, 1, 110065, 0, 0, 31, 0, 3, 56173, 0, 0, 0, '', 'Fire Dragon Soul - Target Deathwing'),
(13, 1, 109971, 0, 0, 31, 0, 3, 56694, 0, 0, 0, '', 'Fire Dragon Soul - Target The Dragon Soul'),
(13, 1, 110067, 0, 0, 31, 0, 3, 56100, 0, 0, 0, '', 'Fire Dragon Soul Aspects - Target Ysera'),
(13, 1, 110067, 0, 1, 31, 0, 3, 56102, 0, 0, 0, '', 'Fire Dragon Soul Aspects - Target Nozdormu'),
(13, 1, 110067, 0, 2, 31, 0, 3, 56099, 0, 0, 0, '', 'Fire Dragon Soul Aspects - Target Alexstrasza'),
(13, 1, 110067, 0, 3, 31, 0, 3, 56101, 0, 0, 0, '', 'Fire Dragon Soul Aspects - Target Kalecgos'),
(13, 1, 110072, 0, 0, 31, 0, 3, 56694, 0, 0, 0, '', 'Concentration - Target The Dragon Soul'),
(13, 1, 110077, 0, 1, 31, 0, 3, 56694, 0, 0, 0, '', 'Concentration - Target The Dragon Soul'),
(13, 1, 110071, 0, 2, 31, 0, 3, 56694, 0, 0, 0, '', 'Concentration - Target The Dragon Soul'),
(13, 1, 110076, 0, 3, 31, 0, 3, 56694, 0, 0, 0, '', 'Concentration - Target The Dragon Soul'),
(13, 1, 109708, 0, 0, 31, 0, 3, 56100, 0, 0, 0, '', 'Trigger Aspect Yell - Target Ysera'),
(13, 1, 109708, 0, 1, 31, 0, 3, 56102, 0, 0, 0, '', 'Trigger Aspect Yell - Target Nozdormu'),
(13, 1, 109708, 0, 2, 31, 0, 3, 56099, 0, 0, 0, '', 'Trigger Aspect Yell - Target Alexstrasza'),
(13, 1, 109708, 0, 3, 31, 0, 3, 56101, 0, 0, 0, '', 'Trigger Aspect Yell - Target Kalecgos'),
(13, 1, 106943, 0, 0, 31, 0, 3, 56100, 0, 0, 0, '', 'Trigger Aspect Buffs - Target Ysera'),
(13, 1, 106943, 0, 1, 31, 0, 3, 56102, 0, 0, 0, '', 'Trigger Aspect Buffs - Target Nozdormu'),
(13, 1, 106943, 0, 2, 31, 0, 3, 56099, 0, 0, 0, '', 'Trigger Aspect Buffs - Target Alexstrasza'),
(13, 1, 106943, 0, 3, 31, 0, 3, 56101, 0, 0, 0, '', 'Trigger Aspect Buffs - Target Kalecgos'),
(13, 3, 106940, 0, 0, 31, 0, 3, 56100, 0, 0, 0, '', 'Trigger Concentration - Target Ysera'),
(13, 3, 106940, 0, 1, 31, 0, 3, 56102, 0, 0, 0, '', 'Trigger Concentration - Target Nozdormu'),
(13, 3, 106940, 0, 2, 31, 0, 3, 56099, 0, 0, 0, '', 'Trigger Concentration - Target Alexstrasza'),
(13, 3, 106940, 0, 3, 31, 0, 3, 56101, 0, 0, 0, '', 'Trigger Concentration - Target Kalecgos'),
(13, 1, 106761, 0, 0, 31, 0, 3, 56307, @CGUID+5, 0, 0, '', 'Time Zone - Target Ysera''s Platform'),
(13, 1, 106538, 0, 3, 31, 0, 3, 56642, 0, 0, 0, '', 'Cataclysm - Target Cataclysm Target Stalker');

-- Custom Attributes
DELETE FROM `spell_custom_attr` WHERE `entry` IN (106444, 109631, 109632, 109633);
INSERT INTO `spell_custom_attr` (`entry`, `attributes`) VALUES
-- Impale
(106444, 0x2000),
(109631, 0x2000),
(109632, 0x2000),
(109633, 0x2000);

-- Achievement Rewards
DELETE FROM `achievement_reward` WHERE `ID`= 6116;
INSERT INTO `achievement_reward` (`ID`, `TitleA`, `TitleH`) VALUES
(6116, 287, 287);

-- Spell procs
DELETE FROM `spell_proc` WHERE `SpellId`= 106040;
INSERT INTO `spell_proc` (`SpellId`, `SpellTypeMask`, `SpellPhaseMask`, `Cooldown`) VALUES
(106040, 1, 2, 4000);

-- Area Triggers
DELETE FROM `areatrigger_scripts` WHERE `ScriptName` IN
('at_madness_of_deathwing_carrying_winds_jump',
'at_madness_of_deathwing_carrying_winds_land');

INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(7110, 'at_madness_of_deathwing_carrying_winds_jump'),
(7111, 'at_madness_of_deathwing_carrying_winds_jump'),
(7112, 'at_madness_of_deathwing_carrying_winds_jump'),
(7113, 'at_madness_of_deathwing_carrying_winds_jump'),
(7114, 'at_madness_of_deathwing_carrying_winds_jump'),
(7115, 'at_madness_of_deathwing_carrying_winds_jump'),
(7315, 'at_madness_of_deathwing_carrying_winds_land'),
(7316, 'at_madness_of_deathwing_carrying_winds_land'),
(7317, 'at_madness_of_deathwing_carrying_winds_land'),
(7318, 'at_madness_of_deathwing_carrying_winds_land'),
(7319, 'at_madness_of_deathwing_carrying_winds_land'),
(7320, 'at_madness_of_deathwing_carrying_winds_land');

-- Gossips
UPDATE `gossip_menu_option` SET `OptionNpcFlag`= 1, `OptionType`= 1 WHERE `MenuId`= 13295 AND `OptionIndex`= 0;
UPDATE `gossip_menu_option_box` SET `BoxBroadcastTextId`= 57303 WHERE `MenuId`= 13295 AND `OptionIndex`= 0;

-- Movement
DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (53488, 56519, 56699, 56642, 57788, 56102, 56099, 56126, 56100, 56101, 57882, 57378, 56173, 57962, 56167, 56846, 56168, 57973, 58131, 58132, 57974, 58133, 58134, 57972, 58129, 58130, 57969, 58000, 58001, 57970, 58125, 58126, 56471, 57976, 58137, 58138, 56844, 56262, 56545, 56332, 56311, 56724, 57977, 58140, 58141);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`) VALUES
(53488, 1, 0, 1, 0),
(57378, 1, 0, 1, 0),
(56126, 1, 0, 1, 0),
(57788, 1, 0, 1, 0),
(56519, 1, 0, 1, 0),
(56642, 1, 0, 1, 0),
(56699, 1, 0, 1, 0),
(56102, 1, 0, 1, 0),
(56099, 1, 0, 1, 0),
(56100, 1, 0, 1, 0),
(56101, 1, 0, 1, 0),
(57882, 1, 0, 1, 0),
(56173, 1, 0, 1, 1), -- Deathwing
(57969, 1, 0, 1, 1),
(58000, 1, 0, 1, 1),
(58001, 1, 0, 1, 1),
(57962, 1, 0, 1, 1), -- Deathwing (Health)
(57970, 1, 0, 1, 1),
(58125, 1, 0, 1, 1),
(58126, 1, 0, 1, 1),
(56167, 0, 0, 1, 1), -- Arm Tentacle
(57973, 0, 0, 1, 1),
(58131, 0, 0, 1, 1),
(58132, 0, 0, 1, 1),
(56846, 0, 0, 1, 1), -- Arm Tentacle
(57974, 0, 0, 1, 1),
(58133, 0, 0, 1, 1),
(58134, 0, 0, 1, 1),
(56168, 0, 0, 1, 1), -- Wing Tentacle
(57972, 0, 0, 1, 1),
(58129, 0, 0, 1, 1),
(58130, 0, 0, 1, 1),
(56471, 0, 0, 1, 1), -- Mutated Corruption
(57976, 0, 0, 1, 1),
(58137, 0, 0, 1, 1),
(58138, 0, 0, 1, 1),
(56844, 0, 0, 1, 1), -- Tail Tentacle
(56262, 0, 0, 1, 0), -- Elementium Bolt
(56545, 0, 0, 1, 1), -- Claw Mark
(56332, 0, 0, 1, 1), -- Time Zone Target
(56311, 0, 0, 1, 1), -- Time Zone
(56724, 0, 0, 1, 1), -- Elementium Fragment
(57977, 0, 0, 1, 1),
(58140, 0, 0, 1, 1),
(58141, 0, 0, 1, 1);

-- Vehicle Accessories
DELETE FROM `vehicle_template_accessory` WHERE `entry` IN (56173, 56103);
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(56173, 57962, 5, 1, 'Deathwing - Deathwing', 8, 0), -- Deathwing - Deathwing
(56173, 57686, 0, 1, 'Deathwing - Deathwing Arm R', 8, 0), -- Deathwing - Deathwing Arm R
(56173, 57694, 1, 1, 'Deathwing - Deathwing Arm L', 8, 0), -- Deathwing - Deathwing Arm L
(56173, 57696, 4, 1, 'Deathwing - Deathwing Wing L', 8, 0), -- Deathwing - Deathwing Wing L
(56173, 57695, 3, 1, 'Deathwing - Deathwing Wing R', 8, 0), -- Deathwing - Deathwing Wing R
(56103, 56694, 0, 1, 'Thrall - The Dragon Soul', 8, 0); -- Thrall - The Dragon Soul

-- Vehicle Seat Addon
DELETE FROM `vehicle_seat_addon` WHERE `SeatEntry`= 10472;
INSERT INTO `vehicle_seat_addon` (`SeatEntry`, `ExitParamX`, `ExitParamY`, `ExitParamZ`, `ExitParamO`, `ExitParamValue`) VALUES
(10472, -11929.83,  12035.63, 35.45797, 2.164208, 2);

DELETE FROM `vehicle_seat_addon` WHERE `SeatEntry` IN (10699);
INSERT INTO `vehicle_seat_addon` (`SeatEntry`, `SeatOffsetX`, `SeatOffsetY`, `SeatOffsetZ`, `SeatOffsetO`) VALUES
(10699, 263.0887, 15.0095, 100.1493, 0); -- Deathwing - Seat 5

-- Spellclicks
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (56173, 56103);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(56173, 46598, 1, 0),
(56103, 46598, 1, 0);

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` IN (56173, 56099, 56100, 56101, 56102, 56167, 56846, 56168, 56103);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
-- Deathwing
(56173, 0, 0, 'You have done NOTHING. I will tear your world APART.', 14, 0, 100, 0, 0, 26527, 55860, 'Deathwing - Aggro'),
(56173, 1, 0, '|TInterface\\Icons\\ability_deathwing_assualtaspects.blp:20|t%s begins to cast |cFFFF0000|Hspell:107018|h[Assault Aspects]|h|r!', 41, 0, 100, 0, 0, 0, 55853, 'Deathwing - Announce Assault Aspects'),
(56173, 2, 0, '|TInterface\\Icons\\ability_deathwing_assualtaspects.blp:20|t%s assaults |cFF04FC32|Hspell:107018|h[Ysera]|h|r!', 41, 0, 100, 0, 0, 0, 55850, 'Deathwing - Announce Assault Ysera'),
(56173, 3, 0, '|TInterface\\Icons\\ability_deathwing_assualtaspects.blp:20|t%s assaults |cFF5858FA|Hspell:107018|h[Kalecgos]|h|r!', 41, 0, 100, 0, 0, 0, 55851, 'Deathwing - Announce Assault Kalecgos'),
(56173, 4, 0, '|TInterface\\Icons\\ability_deathwing_assualtaspects.blp:20|t%s assaults |cFFFFFF00|Hspell:107018|h[Nozdormu]|h|r!', 41, 0, 100, 0, 0, 0, 55849, 'Deathwing - Announce Assault Nozdormu'),
(56173, 5, 0, '|TInterface\\Icons\\ability_deathwing_assualtaspects.blp:20|t%s assaults |cFFFF0000|Hspell:107018|h[Alexstrasza]|h|r!', 41, 0, 100, 0, 0, 0, 55848, 'Deathwing - Announce Assault Alexstrasza'),
(56173, 6, 0, '|TInterface\\Icons\\ability_deathwing_cataclysm.blp:20|t%s begins to cast |cFFFF0000|Hspell:106523|h[Cataclysm]|h|r! Stop Him!', 41, 0, 100, 0, 0, 0, 55535, 'Deathwing - Announce Cataclysm'),
(56173, 7, 0, '|TInterface\\Icons\\spell_fire_moltenblood.blp:20|t%s begins to |cFFFF0000|Hspell:105863|h[Hemorrhage]|h|r!', 41, 0, 100, 0, 0, 0, 55023, 'Deathwing - Announce Hemorrhage'),
(56173, 8, 0, '|TInterface\\Icons\\spell_fire_meteorstorm.blp:20|t%s begins to cast |cFFFF0000|Hspell:105651|h[Elementium Bolt]|h|r!', 41, 0, 100, 0, 0, 0, 55826, 'Deathwing - Announce Elementium Bolt'),
(56173, 9, 0, 'There is no shelter from my fury!', 14, 0, 100, 0, 0, 26354, 73802, 'Deathwing - Elementium Bolt 1'),
(56173, 9, 1, 'The sea will swallow your smoldering remains.', 14, 0, 100, 0, 0, 26356, 55781, 'Deathwing - Elementium Bolt 2'),
(56173, 9, 2, 'Your armor means nothing, your faith even less.', 14, 0, 100, 0, 0, 26355, 55780, 'Deathwing - Elementium Bolt 3'),
(56173, 10, 0, 'I AM DEATHWING, THE DESTROYER, THE END OF ALL THINGS, INEVITABLE, INDOMITABLE; I AM THE CATACLYSM!', 14, 0, 100, 0, 0, 26348, 55785, 'Deathwing - Slump'),
(56173, 11, 0, '|TInterface\\Icons\\inv_stave_2h_deathwingraiddw_d_01.blp:20|t%s falls forward, get to |cFF04FC32Ysera\'s|r platform!', 41, 0, 100, 0, 0, 0, 56720, 'Deathwing - Announce Slump'),
-- Limb Tentacles
(56167, 0, 0, '|TInterface\\Icons\\ability_warrior_bloodnova.blp:20|tThe %s is injured and sprouts |cFFFE9A2EBlistering Tentacles|r!', 41, 0, 100, 0, 0, 0, 54846, 'Limbt Tentacle - Announce Blistering Tentacles'),
(56846, 0, 0, '|TInterface\\Icons\\ability_warrior_bloodnova.blp:20|tThe %s is injured and sprouts |cFFFE9A2EBlistering Tentacles|r!', 41, 0, 100, 0, 0, 0, 54846, 'Limbt Tentacle - Announce Blistering Tentacles'),
(56168, 0, 0, '|TInterface\\Icons\\ability_warrior_bloodnova.blp:20|tThe %s is injured and sprouts |cFFFE9A2EBlistering Tentacles|r!', 41, 0, 100, 0, 0, 0, 54846, 'Limbt Tentacle - Announce Blistering Tentacles'),
-- Alextsrasza
(56099, 0, 0, 'I will cleanse whatever corruption I can; my fire will not harm you.', 14, 0, 100, 0, 0, 26498, 56772, 'Alexstrasza - Introduce Ability'),
(56099, 1, 0, 'No! Such power! Deathwing''s summoning of the final Cataclysm will destroy all life on Azeroth. Quickly, we must interrupt him!', 14, 0, 100, 0, 0, 26500, 55773, 'Alexstrasza - Cataclysm'),
(56099, 2, 0, 'He\'s completely mad!!', 14, 0, 100, 0, 0, 26499, 56774, 'Alexstrasza - Phase 2'),
(56099, 3, 0, 'Excellent work. The fire of my heart glows with a brilliant purity unmatched; every spark of it I will channel into the Dragon Soul.', 14, 0, 100, 0, 0, 26497, 56773, 'Alexstrasza - Charge Dragon Soul'),
-- Ysera
(56100, 0, 0, 'I will bring you closer to the Emerald Dream. Seek safety there when the fight becomes too intense.', 14, 0, 100, 0, 0, 26142, 56776, 'Ysera - Introduce Ability'),
(56100, 1, 0, 'Deathwing is conjuring the final Cataclysm; even the Emerald Dream trembles. If we are to stop the spell, we must attack him together.', 14, 0, 100, 0, 0, 26144, 56781, 'Ysera - Cataclysm'),
(56100, 2, 0, 'Such rage I have never seen...', 14, 0, 100, 0, 0, 26143, 56777, 'Ysera - Phase 2'),
(56100, 3, 0, 'We are one step closer. The unknowable, transcendent power of the Emerald Dream I now give unto the Dragon Soul.', 14, 0, 100, 0, 0, 26141, 56775, 'Ysera - Charge Dragon Soul'),
-- Kalecgos
(56101, 0, 0, 'I will charge you with arcane energy to blast your foes.', 14, 0, 100, 0, 0, 26259, 56752, 'Kalecgos - Introduce Ability'),
(56101, 1, 0, 'The Destroyer is gathering all his might for a blow that will split the world. Attack him, now! We must stop the final Cataclysm!', 14, 0, 100, 0, 0, 26261, 55776, 'Kalecgos - Cataclysm'),
(56101, 2, 0, 'Is he... coming apart?', 14, 0, 100, 0, 0, 26260, 56753, 'Kalecgos - Phase 2'),
(56101, 3, 0, 'Well done! I will realign the flow of mana and fill the Dragon Soul with all my arcane might.', 14, 0, 100, 0, 0, 26258, 56751, 'Kalecgos - Charge Dragon Soul'),
-- Nozdormu
(56102, 0, 0, 'I will slow the Destroyer''s attacks when I can.', 14, 0, 100, 0, 0, 25949, 55786, 'Nozdormu - Introduce Ability'),
(56102, 1, 0, 'Hurry, heroes. In mere moments Deathwing''s Cataclysm will complete what he begun and end the world. Join me in the attack, now!', 14, 0, 100, 0, 0, 25951, 55774, 'Nozdormu - Cataclysm'),
(56102, 2, 0, 'Press the attack, heroes.', 14, 0, 100, 0, 0, 25950, 56770, 'Nozdormu - Phase 2'),
(56102, 3, 0, 'It is time. I will expend everything to bind every thread here, now, around the Dragon Soul. What comes to pass will NEVER be undone.', 14, 0, 100, 0, 0, 26600, 56769, 'Nozdormu - Charge Dragon Soul'),
-- Thrall
(56103, 0, 0, 'It is done; at last the Destroyer has met his end. Now, we can begin to heal our world.', 14, 0, 100, 0, 0, 25901, 55768, 'Thrall - Pre Fight'),
(56103, 1, 0, 'Aspects! Aid the heroes as best you can.', 14, 0, 100, 0, 0, 25895, 56737, 'Thrall - Saay Phase Two');

UPDATE `creature_text` SET `TextRange`= 1 WHERE `CreatureID` IN (56173, 56167, 56099, 56100, 56101, 56102);

-- Model Info
UPDATE `creature_model_info` SET `CombatReach`= 28, `BoundingRadius`= 2 WHERE `DisplayID`= 39405;
UPDATE `creature_model_info` SET `CombatReach`= 8, `BoundingRadius`= 0.25 WHERE `DisplayID`= 39347;
UPDATE `creature_model_info` SET `CombatReach`= 45, `BoundingRadius`= 0.5 WHERE `DisplayID`= 39947;

-- Spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+69;
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+69;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 53488, 967, 5892, 5893, 15, 1, 0, 374, 0, 0, -12116.92, 12170.92, -2.650913, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Summon Enabler Stalker (Area: The Maelstrom - Difficulty: 0) (Auras: 109247 - Presence of the Dragon Soul, 99201 - Summon Enabler)
(@CGUID+1, 53488, 967, 5892, 5893, 15, 1, 0, 374, 0, 0, -12098.57, 12160.6, -2.65092, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Summon Enabler Stalker (Area: The Maelstrom - Difficulty: 0) (Auras: 109247 - Presence of the Dragon Soul, 99201 - Summon Enabler)
(@CGUID+2, 53488, 967, 5892, 5893, 15, 1, 0, 374, 0, 0, -12079.91, 12150.8, -2.65092, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Summon Enabler Stalker (Area: The Maelstrom - Difficulty: 0) (Auras: 109247 - Presence of the Dragon Soul, 99201 - Summon Enabler)
(@CGUID+3, 56699, 967, 5892, 5893, 15, 1, 0, 374, 0, 0, -12087.5, 12165.71, -2.650913, 1.082104, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Jump Pad (Area: The Maelstrom - Difficulty: 0)
(@CGUID+4, 56699, 967, 5892, 5893, 15, 1, 0, 374, 0, 0, -12099.64, 12152.82, -2.65092, 1.082104, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Jump Pad (Area: The Maelstrom - Difficulty: 0)
(@CGUID+5, 56307, 967, 5892, 5893, 15, 1, 0, 374, 0, 0, -12111.44, 12169.91, -2.650916, 5.689773, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Platform (Area: The Maelstrom - Difficulty: 0) (Auras: )
(@CGUID+6, 57788, 967, 5892, 5893, 15, 1, 169, 0, 0, 0, -12128.51, 12171.41, -2.650913, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Congealing Blood Target (Area: The Maelstrom - Difficulty: 0)
(@CGUID+7, 53488, 967, 5892, 5893, 15, 1, 0, 374, 0, 0, -12031.41, 12221.06, -6.068901, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Summon Enabler Stalker (Area: The Maelstrom - Difficulty: 0) (Auras: 109247 - Presence of the Dragon Soul, 99201 - Summon Enabler)
(@CGUID+8, 56642, 967, 5892, 5893, 15, 1, 169, 0, 0, 0, -12120.56, 12133.38, -19.57082, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Cataclysm Stalker (Area: The Maelstrom - Difficulty: 0)
(@CGUID+9, 53488, 967, 5892, 5893, 15, 1, 0, 374, 0, 0, -12046.92, 12234.78, -6.068901, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Summon Enabler Stalker (Area: The Maelstrom - Difficulty: 0) (Auras: 109247 - Presence of the Dragon Soul, 99201 - Summon Enabler)
(@CGUID+10, 57882, 967, 5892, 5893, 15, 1, 0, 374, 0, 0, -12128.2, 12181.18, 0.3175833, 5.585053, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Travel to Wyrmrest Base (Area: The Maelstrom - Difficulty: 0) (Auras: 108227 - Teleport Visual - Disabled, 108203 - Teleport Visual - Active)
(@CGUID+11, 56642, 967, 5892, 5893, 15, 1, 169, 0, 0, 0, -12032.57, 12175.48, -5.714281, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Cataclysm Stalker (Area: The Maelstrom - Difficulty: 0)
(@CGUID+12, 57788, 967, 5892, 5893, 15, 1, 169, 0, 0, 0, -12083.2, 12173.7, -4.719368, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Congealing Blood Target (Area: The Maelstrom - Difficulty: 0)
(@CGUID+13, 53488, 967, 5892, 5893, 15, 1, 0, 374, 0, 0, -12140.5, 12082.68, 2.39029, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Summon Enabler Stalker (Area: The Maelstrom - Difficulty: 0) (Auras: 109247 - Presence of the Dragon Soul, 99201 - Summon Enabler)
(@CGUID+14, 57378, 967, 5892, 5893, 15, 1, 0, 374, 0, 0, -12132.63, 12172.89, 0.3175833, 5.77704, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Travel to the deck of The Skyfire (Area: The Maelstrom - Difficulty: 0) (Auras: 108227 - Teleport Visual - Disabled, 108203 - Teleport Visual - Active)
(@CGUID+15, 56699, 967, 5892, 5893, 15, 1, 0, 374, 0, 0, -12047.93, 12213.88, -5.942781, 4.782202, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Jump Pad (Area: The Maelstrom - Difficulty: 0)
(@CGUID+16, 57788, 967, 5892, 5893, 15, 1, 169, 0, 0, 0, -12075.18, 12133.7, -2.65092, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Congealing Blood Target (Area: The Maelstrom - Difficulty: 0)
(@CGUID+17, 57788, 967, 5892, 5893, 15, 1, 169, 0, 0, 0, -12099.08, 12142.67, -2.65092, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Congealing Blood Target (Area: The Maelstrom - Difficulty: 0)
(@CGUID+18, 53488, 967, 5892, 5893, 15, 1, 0, 374, 0, 0, -12020.94, 12210.8, -6.068901, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Summon Enabler Stalker (Area: The Maelstrom - Difficulty: 0) (Auras: 109247 - Presence of the Dragon Soul, 99201 - Summon Enabler)
(@CGUID+19, 57788, 967, 5892, 5893, 15, 1, 169, 0, 0, 0, -12117.79, 12155.29, -2.65092, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Congealing Blood Target (Area: The Maelstrom - Difficulty: 0)
(@CGUID+20, 56103, 967, 5892, 5893, 15, 1, 169, 0, 0, 0, -12074.33, 12159.48, -2.650913, 2.844887, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Thrall (Area: The Maelstrom - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+21, 53488, 967, 5892, 5893, 15, 1, 0, 374, 0, 0, -12119.09, 12074.42, 2.390291, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Summon Enabler Stalker (Area: The Maelstrom - Difficulty: 0) (Auras: 109247 - Presence of the Dragon Soul, 99201 - Summon Enabler)
(@CGUID+22, 56307, 967, 5892, 5893, 15, 1, 0, 374, 0, 0, -12040.33, 12232.46, -6.068902, 5.51524, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Platform (Area: The Maelstrom - Difficulty: 0) (Auras: )
(@CGUID+23, 56100, 967, 5892, 5893, 15, 1, 169, 0, 0, 0, -12157.36, 12212.52, 36.01524, 5.759586, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Ysera (Area: The Maelstrom - Difficulty: 0) (Auras: 106456 - Ysera's Presence, 106463 - The Dreamer) (possible waypoints or random movement)
(@CGUID+24, 56642, 967, 5892, 5893, 15, 1, 169, 0, 0, 0, -12037.97, 12099.33, -32.49138, 0.1396263, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Cataclysm Stalker (Area: The Maelstrom - Difficulty: 0)
(@CGUID+25, 56699, 967, 5892, 5893, 15, 1, 0, 374, 0, 0, -12118.42, 12084.9, 2.390293, 1.082104, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Jump Pad (Area: The Maelstrom - Difficulty: 0)
(@CGUID+26, 53488, 967, 5892, 5893, 15, 1, 0, 374, 0, 0, -12100.41, 12072.44, 2.390291, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Summon Enabler Stalker (Area: The Maelstrom - Difficulty: 0) (Auras: 109247 - Presence of the Dragon Soul, 99201 - Summon Enabler)
(@CGUID+27, 56307, 967, 5892, 5893, 15, 1, 0, 374, 0, 0, -12139.36, 12080.59, 2.390289, 5.794493, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Platform (Area: The Maelstrom - Difficulty: 0) (Auras: )
(@CGUID+28, 56101, 967, 5892, 5893, 15, 1, 169, 0, 0, 0, -12224.83, 12128.53, 68.96001, 5.846853, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kalecgos (Area: The Maelstrom - Difficulty: 0) (Auras: 106026 - Kalecgos' Presence, 106039 - Spellweaver) (possible waypoints or random movement)
(@CGUID+29, 56642, 967, 5892, 5893, 15, 1, 169, 0, 0, 0, -12245.54, 12321.76, 1.596802, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Cataclysm Stalker (Area: The Maelstrom - Difficulty: 0)
(@CGUID+30, 56642, 967, 5892, 5893, 15, 1, 169, 0, 0, 0, -12070.19, 12020.37, -53.17715, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Cataclysm Stalker (Area: The Maelstrom - Difficulty: 0)
(@CGUID+31, 56699, 967, 5892, 5893, 15, 1, 0, 374, 0, 0, -12023.02, 12228.5, -6.068902, 1.082104, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Jump Pad (Area: The Maelstrom - Difficulty: 0)
(@CGUID+32, 56642, 967, 5892, 5893, 15, 1, 169, 0, 0, 0, -12313.38, 12207.58, -10.49461, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Cataclysm Stalker (Area: The Maelstrom - Difficulty: 0)
(@CGUID+33, 56642, 967, 5892, 5893, 15, 1, 169, 0, 0, 0, -12222.05, 12108.45, 9.211418, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Cataclysm Stalker (Area: The Maelstrom - Difficulty: 0)
(@CGUID+34, 56642, 967, 5892, 5893, 15, 1, 169, 0, 0, 0, -11902.55, 12187.86, -36.58665, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Cataclysm Stalker (Area: The Maelstrom - Difficulty: 0)
(@CGUID+35, 56642, 967, 5892, 5893, 15, 1, 169, 0, 0, 0, -11964.7, 12212.82, -26.10259, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Cataclysm Stalker (Area: The Maelstrom - Difficulty: 0)
(@CGUID+36, 56642, 967, 5892, 5893, 15, 1, 169, 0, 0, 0, -12020.5, 12299.67, -27.89029, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Cataclysm Stalker (Area: The Maelstrom - Difficulty: 0)
(@CGUID+37, 56642, 967, 5892, 5893, 15, 1, 169, 0, 0, 0, -12166.1, 12385.22, 2.22749, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Cataclysm Stalker (Area: The Maelstrom - Difficulty: 0)
(@CGUID+38, 56102, 967, 5892, 5893, 15, 1, 169, 0, 0, 0, -12093.81, 12311.97, 43.228, 5.427974, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Nozdormu (Area: The Maelstrom - Difficulty: 0) (Auras: 105823 - Nozdormu's Presence) (possible waypoints or random movement)
(@CGUID+39, 56642, 967, 5892, 5893, 15, 1, 169, 0, 0, 0, -12158.22, 12048.96, -26.88116, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Cataclysm Stalker (Area: The Maelstrom - Difficulty: 0)
(@CGUID+40, 56642, 967, 5892, 5893, 15, 1, 169, 0, 0, 0, -12067.77, 12040.92, -29.82544, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Cataclysm Stalker (Area: The Maelstrom - Difficulty: 0)
(@CGUID+41, 56642, 967, 5892, 5893, 15, 1, 169, 0, 0, 0, -11923.36, 12298.35, 1.383957, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Cataclysm Stalker (Area: The Maelstrom - Difficulty: 0)
(@CGUID+42, 56642, 967, 5892, 5893, 15, 1, 169, 0, 0, 0, -12210.96, 12033.6, 73.0329, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Cataclysm Stalker (Area: The Maelstrom - Difficulty: 0)
(@CGUID+43, 56099, 967, 5892, 5893, 15, 1, 169, 0, 0, 0, -11957.31, 12338.35, 38.93643, 5.061455, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Alexstrasza (Area: The Maelstrom - Difficulty: 0) (Auras: 105825 - Alexstrasza's Presence) (possible waypoints or random movement)
(@CGUID+44, 56699, 967, 5892, 5893, 15, 1, 0, 374, 0, 0, -11972.8, 12272.76, 1.383957, 4.014257, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Jump Pad (Area: The Maelstrom - Difficulty: 0)
(@CGUID+45, 56307, 967, 5892, 5893, 15, 1, 0, 374, 0, 0, -11960.45, 12288.48, 1.383957, 4.921828, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Platform (Area: The Maelstrom - Difficulty: 0) (Auras: )
(@CGUID+46, 56642, 967, 5892, 5893, 15, 1, 169, 0, 0, 0, -11691.89, 12003.74, 12.16883, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Cataclysm Stalker (Area: The Maelstrom - Difficulty: 0)
(@CGUID+47, 56642, 967, 5892, 5893, 15, 1, 169, 0, 0, 0, -11969.56, 12428.65, -9.830806, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Cataclysm Stalker (Area: The Maelstrom - Difficulty: 0)
(@CGUID+48, 56642, 967, 5892, 5893, 15, 1, 169, 0, 0, 0, -11903.43, 12283.83, 49.89705, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Cataclysm Stalker (Area: The Maelstrom - Difficulty: 0)
(@CGUID+49, 56126, 967, 5892, 5893, 15, 1, 169, 0, 0, 0, -1815.5, -2408.23, 343.8793, 0.4712389, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Target Dummy (Area: The Maelstrom - Difficulty: 0) (Auras: 109247 - Presence of the Dragon Soul)
(@CGUID+50, 56642, 967, 5892, 5893, 15, 1, 169, 0, 0, 0, -12311.08, 12354.16, 38.14534, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Cataclysm Stalker (Area: The Maelstrom - Difficulty: 0)
(@CGUID+51, 56642, 967, 5892, 5893, 15, 1, 169, 0, 0, 0, -12071.36, 12491.06, -10.69453, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Cataclysm Stalker (Area: The Maelstrom - Difficulty: 0)
(@CGUID+52, 56642, 967, 5892, 5893, 15, 1, 169, 0, 0, 0, -12167.89, 12415.39, 25.07364, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Cataclysm Stalker (Area: The Maelstrom - Difficulty: 0)
(@CGUID+53, 56642, 967, 5892, 5893, 15, 1, 169, 0, 0, 0, -12374.24, 12266.4, 9.704861, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Cataclysm Stalker (Area: The Maelstrom - Difficulty: 0)
(@CGUID+54, 56519, 967, 5892, 5893, 15, 1, 169, 0, 0, 0, -12139.71, 12165.99, -6.672815, 6.091199, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Tail Tentacle Target (Area: The Maelstrom - Difficulty: 0)
(@CGUID+55, 56519, 967, 5892, 5893, 15, 1, 169, 0, 0, 0, -12107.37, 12201.94, -5.407307, 5.166174, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Tail Tentacle Target (Area: The Maelstrom - Difficulty: 0)
(@CGUID+56, 56519, 967, 5892, 5893, 15, 1, 169, 0, 0, 0, -12082.41, 12227.6, -7.630992, 0.3316126, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Tail Tentacle Target (Area: The Maelstrom - Difficulty: 0)
(@CGUID+57, 56519, 967, 5892, 5893, 15, 1, 169, 0, 0, 0, -12028.85, 12265.57, -6.354803, 4.13643, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Tail Tentacle Target (Area: The Maelstrom - Difficulty: 0)
(@CGUID+58, 53488, 967, 5892, 5893, 15, 1, 0, 374, 0, 0, -11958.05, 12264.98, 1.383957, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Summon Enabler Stalker (Area: The Maelstrom - Difficulty: 0) (Auras: 109247 - Presence of the Dragon Soul, 99201 - Summon Enabler)
(@CGUID+59, 53488, 967, 5892, 5893, 15, 1, 0, 374, 0, 0, -11960.33, 12283.85, 1.383958, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Summon Enabler Stalker (Area: The Maelstrom - Difficulty: 0) (Auras: 109247 - Presence of the Dragon Soul, 99201 - Summon Enabler)
(@CGUID+60, 53488, 967, 5892, 5893, 15, 1, 0, 374, 0, 0, -11950.15, 12250.48, 1.383959, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Summon Enabler Stalker (Area: The Maelstrom - Difficulty: 0) (Auras: 109247 - Presence of the Dragon Soul, 99201 - Summon Enabler)
(@CGUID+61, 56519, 967, 5892, 5893, 15, 1, 169, 0, 0, 0, -11993.29, 12286.31, -2.664478, 5.916666, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Tail Tentacle Target (Area: The Maelstrom - Difficulty: 0)
(@CGUID+62, 56519, 967, 5892, 5893, 15, 1, 169, 0, 0, 0, -11929.17, 12297.82, -2.252743, 4.380776, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Tail Tentacle Target (Area: The Maelstrom - Difficulty: 0)
(@CGUID+63, 56519, 967, 5892, 5893, 15, 1, 169, 0, 0, 0, -12160.9, 12057.04, 2.390291, 0.7330383, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Tail Tentacle Target (Area: The Maelstrom - Difficulty: 0)
-- Outro spawns
(@CGUID+64, 58211, 967, 5892, 5893, 15, 1, 173, 0, 0, 0, -12066.06, 12150.39, -2.650913, 3.054326, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Aggra (Area: The Maelstrom - Difficulty: 0)
(@CGUID+65, 58210, 967, 5892, 5893, 15, 1, 173, 0, 0, 0, -12069.18, 12159.9, -2.650913, 5.235988, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kalecgos (Area: The Maelstrom - Difficulty: 0)
(@CGUID+66, 58207, 967, 5892, 5893, 15, 1, 173, 0, 0, 0, -12077.35, 12152.27, -2.65092, 6.003932, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Alexstrasza (Area: The Maelstrom - Difficulty: 0)
(@CGUID+67, 58232, 967, 5892, 5893, 15, 1, 173, 0, 0, 0, -12067.72, 12146.38, -2.650914, 3.054326, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Thrall (Area: The Maelstrom - Difficulty: 0)
(@CGUID+68, 58209, 967, 5892, 5893, 15, 1, 173, 0, 0, 0, -12073.81, 12156.58, -2.650914, 5.550147, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Ysera (Area: The Maelstrom - Difficulty: 0)
(@CGUID+69, 58208, 967, 5892, 5893, 15, 1, 173, 0, 0, 0, -12078.41, 12147.46, -2.65092, 0.1745329, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595); -- Nozdormu (Area: The Maelstrom - Difficulty: 0)

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+3;
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+3;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+1, 210147, 967, 5892, 5960, 15, 169, 0, -11890.66, 12286.22, -7.097955, 5.750861, 0, 0, -0.263031, 0.9647874, 7200, 255, 1, 15595), -- Dragon Soul - Deathwing - Lightning Object 4 (Area: Deathwing - Difficulty: 0)
(@OGUID+2, 210151, 967, 5892, 5960, 15, 169, 0, -12078.56, 12023.13, -25.95958, 5.585054, 0, 0, -0.34202, 0.9396927, 7200, 255, 1, 15595), -- Dragon Soul - Deathwing - Lightning Object 1 (Area: Deathwing - Difficulty: 0)
(@OGUID+3, 210150, 967, 5892, 5893, 15, 169, 0, -11717.32, 11946.83, -103.3597, 2.687807, 0, 0, 0.97437, 0.2249513, 7200, 255, 1, 15595); -- Dragon Soul - Deathwing - Lightning Object 2 (Area: The Maelstrom - Difficulty: 0)
