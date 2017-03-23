/*
 * Thorim
 */

DELETE FROM `creature_text` WHERE `entry` IN (32865,32872,32873,33196);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
-- Thorim
(32865, 0,0,'Interlopers! You mortals who dare to interfere with my sport will pay... Wait--you...',14,0,100,0,0,15733,33145,'Thorim SAY_AGGRO_1'),
(32865, 1,0,'I remember you... In the mountains... But you... what is this? Where am--',14,0,100,0,0,15734,33270,'Thorim SAY_AGGRO_2'),
(32865, 2,0,'Do not hold back! Destroy them!',14,0,100,0,0,15736,34241,'Thorim SAY_SPECIAL'),
(32865, 3,0,'Impertinent whelps, you dare challenge me atop my pedestal? I will crush you myself!',14,0,100,0,0,15738,33148,'Thorim SAY_JUMPDOWN'),
(32865, 4,0,'Can''t you at least put up a fight!?',14,0,100,0,0,15739,34239,'Thorim SAY_SLAY_1'),
(32865, 4,1,'Pathetic.',14,0,100,0,0,15740,35768,'Thorim SAY_SLAY_2'),
(32865, 5,0,'My patience has reached its limit!',14,0,100,0,0,15741,33365,'Thorim SAY_BERSERK'),
(32865, 6,0,'Failures! Weaklings!',14,0,100,0,0,15742,33274,'Thorim SAY_WIPE'),
(32865, 7,0,'Stay your arms! I yield!',14,0,100,0,0,15743,33948,'Thorim SAY_DEATH'),
(32865, 8,0,'I feel as though I am awakening from a nightmare, but the shadows in this place yet linger.',14,0,100,0,0,15744,33949,'Thorim SAY_END_NORMAL_1'),
(32865, 9,0,'Sif... was Sif here? Impossible--she died by my brother''s hand. A dark nightmare indeed....',14,0,100,0,0,15745,33950,'Thorim SAY_END_NORMAL_2'),
(32865,10,0,'I need time to reflect.... I will aid your cause if you should require it. I owe you at least that much. Farewell.',14,0,100,0,0,15746,33951,'Thorim SAY_END_NORMAL_3'),
(32865,11,0,'You! Fiend! You are not my beloved! Be gone!',14,0,100,0,0,15747,33952,'Thorim SAY_END_HARD_1'),
(32865,12,0,'Behold the hand behind all the evil that has befallen Ulduar, left my kingdom in ruins, corrupted my brother, and slain my wife.',14,0,100,0,0,15748,33953,'Thorim SAY_END_HARD_2'),
(32865,13,0,'And now it falls to you, champions, to avenge us all. The task before you is great, but I will lend you my aid as I am able. You must prevail.',14,0,100,0,0,15749,33954,'Thorim SAY_END_HARD_3'),
-- Runic Colossus
(32872, 0,0,'%s surrounds itself with a crackling Runic Barrier!',41,0,100,0,0,0,33267,'Runic Colossus'),
-- Ancient Rune Giant
(32873, 0,0,'%s fortifies nearby allies with runic might!',41,0,100,0,0,0,33523,'Ancient Rune Giant'),
-- Sif
(33196, 0,0,'Thorim, my lord!  Why else would these invaders have come into your sanctum but to slay you?  They must be stopped!',14,0,100,0,0,15668,33325,'Sif - Start'),
(33196, 1,0,'These pathetic mortals are harmless, beneath my station.  Dispose of them!',14,0,100,0,0,15669,33368,'Sif - Despawn'),
(33196, 2,0,'Impossible!  Lord Thorim, I will bring your foes a frigid death!',14,0,100,0,0,15670,33369,'Sif - Event');

-- Lever SAI
SET @ENTRY := 194264;
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=@ENTRY;
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,0,0,70,0,100,0,2,0,0,0,9,0,0,0,0,0,0,14,34155,0,0,0,0,0,0,'Lever - On Gameobject State Changed - Activate Gameobject');

-- Thorim Trap Bunny SAI
SET @ENTRY := 33054;
UPDATE `creature_template` SET `AIName`='SmartAI', `flags_extra`=2 WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,10,0,100,0,0,12,17000,17000,11,62241,0,0,0,0,0,1,0,0,0,0,0,0,0,'Thorim Trap Bunny - Within 0-12 Range Out of Combat LoS - Cast Paralytic Field');

SET @ENTRY := 33725;
UPDATE `creature_template` SET `AIName`='SmartAI', `flags_extra`=2 WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,10,0,100,0,0,12,17000,17000,11,63540,0,0,0,0,0,1,0,0,0,0,0,0,0,'Thorim Trap Bunny - Within 0-12 Range Out of Combat LoS - Cast Paralytic Field');

DELETE FROM `spell_script_names` WHERE `spell_id` IN (62577,62603,62576,62602,62580,62604,62016,62057,62058,62042,62184,62466,64767,64909,62184,62331,62418,61934);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(62577,'spell_thorim_blizzard'),
(62603,'spell_thorim_blizzard'),
(62576,'spell_thorim_blizzard_effect'),
(62602,'spell_thorim_blizzard_effect'),
(62580,'spell_thorim_frostbolt_volley'),
(62604,'spell_thorim_frostbolt_volley'),
(62016,'spell_thorim_charge_orb'),
(62057,'spell_thorim_runic_smash'),
(62058,'spell_thorim_runic_smash'),
(62042,'spell_thorim_stormhammer'),
(62466,'spell_thorim_lightning_charge'),
(64767,'spell_thorim_stormhammer_sif'),
(64909,'spell_thorim_stormhammer_boomerang'),
(62184,'spell_thorim_activate_lightning_orb_periodic'),
(62331,'spell_iron_ring_guard_impale'),
(62418,'spell_iron_ring_guard_impale'),
(61934,'spell_thorim_arena_leap');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=62042;
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = -62320;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(-62320, -62398, 0, 'Aura of Celerity - Remove Visual');

-- Add dummy effect to kill credit so it actually selects targets
UPDATE `spell_dbc` SET `EffectImplicitTargetA1`=18, `EffectImplicitTargetB1`=16, `EffectRadiusIndex1`=28, `SchoolMask`=0, `Effect1`=3 WHERE `Id`=64980;
-- Correct attributes (SPELL_ATTR0_HIDE_IN_COMBAT_LOG, SPELL_ATTR2_CAN_TARGET_DEAD, SPELL_ATTR2_CAN_TARGET_NOT_IN_LOS)
UPDATE `spell_dbc` SET `Attributes`=`Attributes`|256, `AttributesEx2`=`AttributesEx2`|1|4 WHERE `Id` IN (64980,64985);

DELETE FROM `spelldifficulty_dbc` WHERE `id` IN (62131,62315,62316,62333,62334,62335,62327,62328,62321,62331,62332,62613,62583,62577,62597,62580);
INSERT INTO `spelldifficulty_dbc` (`id`, `spellid0`, `spellid1`) VALUES
(62131,62131,64390), -- Chain Lightning
(62315,62315,62415), -- Acid Breath
(62316,62316,62417), -- Sweep
(62333,62333,62441), -- Renew
(62334,62334,62442), -- Greater Heal
(62335,62335,62443), -- Holy Smite
(62327,62327,62445), -- Runic Lightning
(62328,62328,62446), -- Runic Mending
(62321,62321,62529), -- Runic Shield
(62331,62331,62418), -- Impale
(62332,62332,62420), -- Shield Smash
(62613,62613,62614), -- Charge
(62583,62583,62601), -- Frostbolt
(62577,62577,62603), -- Blizzard
(62597,62597,62605), -- Frost Nova
(62580,62580,62604); -- Frostbolt Volley

UPDATE `creature_template` SET `ScriptName`='boss_thorim' WHERE `entry`=32865;
UPDATE `creature_template` SET `ScriptName`='npc_sif' WHERE `entry`=33196;
UPDATE `creature_template` SET `ScriptName`='npc_thorim_pre_phase' WHERE `entry` IN (32885,32883,32908,32907,32882,32886);
UPDATE `creature_template` SET `ScriptName`='npc_thorim_arena_phase' WHERE `entry` IN (32876,32904,32878,32877,32874,32875,33110);
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|0x40000000, `ScriptName`='npc_runic_colossus' WHERE `entry`=32872;
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|0x40000000, `ScriptName`='npc_ancient_rune_giant' WHERE `entry`=32873;
UPDATE `creature_template` SET `difficulty_entry_1`=33150 WHERE `entry`=32908; -- Swapped Difficulty entry npcs
UPDATE `creature_template` SET `difficulty_entry_1`=33151 WHERE `entry`=32907; -- Caused swapped displayIDs in 25n
UPDATE `creature_template` SET `InhabitType`=4, `flags_extra`=128, `ScriptName`='' WHERE `entry` IN (33140,33141);
UPDATE `creature_template` SET `InhabitType`=4, `flags_extra`=128 WHERE `entry` IN (33378,32879);
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry` IN (32892);
UPDATE `creature_template` SET `faction`=1692 WHERE `entry` IN (32885,32883,33152,33153,32908,33150,32907,33151);
UPDATE `creature_template` SET `faction`=1693 WHERE `entry` IN (32882,33154);
UPDATE `creature_template` SET `speed_walk`=2.5/2.5, `speed_run`=14.0/7.0, `BaseAttackTime`=1500, `RangeAttackTime`=1500 WHERE `entry` IN (32865,33147);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (62577,62603,62016,62976,63238,64098,62466,62565,62942,64767,62560,61964,61934);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,62577,0,0,31,0,3,32892,0,0,0,'','Thorim - Blizzard'),
(13,1,62603,0,0,31,0,3,32892,0,0,0,'','Thorim - Blizzard'),
(13,1,62016,0,0,31,0,3,33378,0,0,0,'','Thorim - Charge Orb'),
(13,1,62976,0,0,31,0,3,33378,0,0,0,'','Thorim - Lightning Pillar'),
(13,1,62976,0,0,33,0,1,0,0,1,0,'','Thorim - Lightning Pillar'),
(13,1,63238,0,0,31,0,3,33378,0,0,0,'','Thorim - Lightning Pillar'),
(13,1,63238,0,0,33,0,1,0,0,1,0,'','Thorim - Lightning Pillar'),
(13,1,64098,0,0,31,0,3,32865,0,0,0,'','Thorim - Lightning Bolt'),
(13,4,62466,0,0,31,0,3,32780,0,0,0,'','Thorim - Lightning Charge'),
(13,3,62565,0,0,31,0,3,32865,0,0,0,'','Thorim - Touch of Dominion'),
(13,7,62942,0,0,31,0,3,32874,0,0,0,'','Thorim - Runic Fortification'),
(13,7,62942,0,1,31,0,3,32875,0,0,0,'','Thorim - Runic Fortification'),
(13,7,62942,0,2,31,0,3,33110,0,0,0,'','Thorim - Runic Fortification'),
(13,1,64767,0,0,31,0,3,33196,0,0,0,'','Thorim - Stormhammer'),
(13,7,62560,0,0,31,0,3,32876,0,0,0,'','Thorim - Berserk'),
(13,7,62560,0,1,31,0,3,32877,0,0,0,'','Thorim - Berserk'),
(13,7,62560,0,2,31,0,3,32878,0,0,0,'','Thorim - Berserk'),
(13,7,62560,0,3,31,0,3,32904,0,0,0,'','Thorim - Berserk'),
(13,1,61964,0,0,31,0,3,32882,0,0,0,'','Thorim - Circle of Healing'),
(13,1,61964,0,1,31,0,3,32883,0,0,0,'','Thorim - Circle of Healing'),
(13,1,61964,0,2,31,0,3,32885,0,0,0,'','Thorim - Circle of Healing'),
(13,1,61964,0,3,31,0,3,32886,0,0,0,'','Thorim - Circle of Healing'),
(13,1,61964,0,4,31,0,3,32907,0,0,0,'','Thorim - Circle of Healing'),
(13,1,61964,0,5,31,0,3,32908,0,0,0,'','Thorim - Circle of Healing'),
(13,1,61934,0,0,31,0,3,32892,0,0,0,'condition_thorim_arena_leap','Thorim - Leap');

DELETE FROM `disables` WHERE `sourceType`=4 AND `entry` IN (10289,10314,10304,10313,10440,10457,10800,10801);
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES
(4,10800,0,0,0,'Siffed (10 player) - Duplicate'),
(4,10801,0,0,0,'Siffed (25 player) - Duplicate');

DELETE FROM `disables` WHERE `sourceType`=0 AND `entry` IN (62042,64767,45537);
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES
(0, 62042, 64, '', '', 'Stormhammer - Ignore LOS'),
(0, 64767, 64, '', '', 'Stormhammer - Ignore LOS'),
(0, 45537, 64, '', '', 'Lightning Beam Channel - Ignore LOS');

DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (10289,10314,10305,10309,10440,10457,10287,10288,10311,10312);
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`) VALUES
(10289,12,0,0,''), -- Siffed (10 player)
(10314,12,1,0,''), -- Siffed (25 player)

(10305,11,0,0,'achievement_dont_stand_in_the_lightning'), -- Don't Stand in the Lightning (10 player)
(10305,12,0,0,''),                                        -- Don't Stand in the Lightning (10 player)
(10309,11,0,0,'achievement_dont_stand_in_the_lightning'), -- Don't Stand in the Lightning (25 player)
(10309,12,1,0,''),                                        -- Don't Stand in the Lightning (25 player)

(10440,11,0,0,'achievement_lose_your_illusion'), -- Lose Your Illusion (10 player)
(10440,12,0,0,''),                               -- Lose Your Illusion (10 player)
(10457,11,0,0,'achievement_lose_your_illusion'), -- Lose Your Illusion (25 player)
(10457,12,1,0,''),                               -- Lose Your Illusion (25 player)

(10287,11,0,0,'achievement_i_ll_take_you_all_on'), -- I'll Take You All On (10 player) - Participate in slaying Runic Colossus
(10287,12,0,0,''),
(10288,11,0,0,'achievement_i_ll_take_you_all_on'), -- I'll Take You All On (10 player) - Participate in slaying Ancient Rune Giant
(10288,12,0,0,''),
(10311,11,0,0,'achievement_i_ll_take_you_all_on'), -- I'll Take You All On (25 player) - Participate in slaying Runic Colossus
(10311,12,1,0,''),
(10312,11,0,0,'achievement_i_ll_take_you_all_on'), -- I'll Take You All On (25 player) - Participate in slaying Ancient Rune Giant
(10312,12,1,0,'');

DELETE FROM `creature` WHERE `id` IN (32882,32908,32907,32885,32883,32886); -- PreAdds
DELETE FROM `creature` WHERE `id` IN (32874,32875,33110); -- Colossus, Giant Adds

-- Fix Thorim Controller multi spawns
SET @CGUID:=136446;
DELETE FROM `creature` WHERE `id`=32879;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID, 32879, 603, 3, 1, 2134.774, -262.3073, 428.6936, 1.343904, 7200, 0, 0); -- 32879 (Area: 0) (Auras: 62184 - 62184)

UPDATE `gameobject_template` SET `size`=3 WHERE `entry`=194315;
UPDATE `gameobject_template_addon` SET `faction`=94, `flags`=16 WHERE `entry` IN (194313,194314,194315);

SET @OGUID := 3926; -- 4 free guids
DELETE FROM `gameobject` WHERE `id` IN (194312,194313,194314,194315);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) values
(@OGUID+0,194312,603,1,1,2134.948,-286.436,419.5051,1.588249,0,0,0.7132502,0.7009096,-2592000,255,1,0),
(@OGUID+1,194313,603,1,1,2134.948,-286.436,419.5051,1.588249,0,0,0.7132502,0.7009096,-2592000,255,1,0),
(@OGUID+2,194314,603,2,1,2134.948,-286.436,419.5051,1.588249,0,0,0.7132502,0.7009096,-2592000,255,1,0),
(@OGUID+3,194315,603,2,1,2134.948,-286.436,419.5051,1.588249,0,0,0.7132502,0.7009096,-2592000,255,1,0);

UPDATE `gameobject_loot_template` SET `LootMode`=1 WHERE `Entry`=27074;
DELETE FROM `gameobject_loot_template` WHERE `Entry` IN (26955,26956);
INSERT INTO `gameobject_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(26955,1,34372,100,0,1,0,1,1,'Thorim25 HM - normal mode loot'),
(26955,2,12033,100,0,1,0,1,2,'Thorim25 HM - T8.5 tokens'),
(26955,3,34154,10,0,1,0,1,1,'Thorim25 HM - Random Ulduar craft recipe'),
(26955,45038,0,18,0,1,0,1,1,'Thorim25 HM - Val''anyr fragment'),
(26955,45087,0,10,0,1,0,1,1,'Thorim25 HM - Runed Orb'),
(26955,45470,0,0,0,1,1,1,1,'Thorim25 HM - Wisdom''s Hold'),
(26955,45471,0,0,0,1,1,1,1,'Thorim25 HM - Fate''s Clutch'),
(26955,45472,0,0,0,1,1,1,1,'Thorim25 HM - Warhelm of the Champion'),
(26955,45473,0,0,0,1,1,1,1,'Thorim25 HM - Embrace of the Gladiator'),
(26955,45474,0,0,0,1,1,1,1,'Thorim25 HM - Pauldrons of the Combatant'),
(26955,45570,0,0,0,1,1,1,1,'Thorim25 HM - Skyforge Crossbow'),
(26955,45817,0,100,1,1,0,1,1,'Thorim25 HM - Thorim''s Sigil'),
(26955,47241,0,100,0,1,0,1,1,'Thorim25 HM - Emblem of Triumph'),

(26956,1,34372,100,0,1,0,1,1,'Thorim25 - normal mode loot'),
(26956,2,12033,100,0,1,0,1,2,'Thorim25 - T8.5 tokens'),
(26956,3,34154,10,0,1,0,1,1,'Thorim25 - Random Ulduar craft recipe'),
(26956,45038,0,8,0,1,0,1,1,'Thorim25 - Val''anyr fragment'),
(26956,45087,0,10,0,1,0,1,1,'Thorim25 - Runed Orb'),
(26956,47241,0,100,0,1,0,1,1,'Thorim25 - Emblem of Triumph');

-- Pathing for Thorim Event Bunny Entry: 32892 'TDB FORMAT'
SET @NPC := 136515;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2148.897,`position_y`=-275.9974,`position_z`=419.3439 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2148.897,-275.9974,419.3439,0,0,0,0,100,0),
(@PATH,2,2145.938,-277.1342,419.3507,0,0,0,0,100,0),
(@PATH,3,2144.745,-279.1382,419.3436,0,0,0,0,100,0),
(@PATH,4,2140.348,-279.9147,419.3507,0,0,0,0,100,0),
(@PATH,5,2136.403,-281.768,419.3484,0,0,0,0,100,0),
(@PATH,6,2133.335,-281.1665,419.3492,0,0,0,0,100,0),
(@PATH,7,2128.253,-281.3306,419.3441,0,0,0,0,100,0),
(@PATH,8,2127.796,-279.1284,419.3536,0,0,0,0,100,0),
(@PATH,9,2122.361,-277.8073,419.3463,0,0,0,0,100,0),
(@PATH,10,2121.191,-274.8436,419.3546,0,0,0,0,100,0),
(@PATH,11,2118.086,-272.7617,419.3416,0,0,0,0,100,0),
(@PATH,12,2118.571,-269.8189,419.3556,0,0,0,0,100,0),
(@PATH,13,2115.764,-264.8972,419.3406,0,0,0,0,100,0),
(@PATH,14,2116.771,-261.8505,419.3524,0,0,0,0,100,0),
(@PATH,15,2116.042,-258.7443,419.337,0,0,0,0,100,0),
(@PATH,16,2118.695,-256.6291,419.3586,0,0,0,0,100,0),
(@PATH,17,2119.729,-250.9486,419.3421,0,0,0,0,100,0),
(@PATH,18,2122.991,-249.8431,419.3552,0,0,0,0,100,0),
(@PATH,19,2124.468,-246.9001,419.3406,0,0,0,0,100,0),
(@PATH,20,2127.68,-247.2872,419.3582,0,0,0,0,100,0),
(@PATH,21,2132.824,-244.104,419.3432,0,0,0,0,100,0),
(@PATH,22,2137.135,-244.6497,419.3533,0,0,0,0,100,0),
(@PATH,23,2139.536,-244.2479,419.3305,0,0,0,0,100,0),
(@PATH,24,2141.305,-246.7072,419.3468,0,0,0,0,100,0),
(@PATH,25,2147.173,-248.2035,419.332,0,0,0,0,100,0),
(@PATH,26,2148.169,-251.0119,419.3453,0,0,0,0,100,0),
(@PATH,27,2151.137,-252.9195,419.3279,0,0,0,0,100,0),
(@PATH,28,2152.166,-258.0995,419.3453,0,0,0,0,100,0),
(@PATH,29,2153.929,-261.2107,419.3445,0,0,0,0,100,0),
(@PATH,30,2152.584,-263.5718,419.3539,0,0,0,0,100,0),
(@PATH,31,2153.444,-266.6717,419.3431,0,0,0,0,100,0),
(@PATH,32,2150.696,-271.5853,419.3486,0,0,0,0,100,0),
(@PATH,33,2149.729,-275.3406,419.3407,0,0,0,0,100,0),
(@PATH,34,2146.703,-276.1875,419.3526,0,0,0,0,100,0),
(@PATH,35,2142.371,-280.3057,419.3431,0,0,0,0,100,0),
(@PATH,36,2140.033,-280.4717,419.3516,0,0,0,0,100,0),
(@PATH,37,2137.437,-281.6862,419.3474,0,0,0,0,100,0),
(@PATH,38,2134.343,-280.8165,419.3492,0,0,0,0,100,0),
(@PATH,39,2129.271,-281.3747,419.3436,0,0,0,0,100,0),
(@PATH,40,2125.816,-279.0063,419.3518,0,0,0,0,100,0),
(@PATH,41,2121.522,-277.1325,419.3434,0,0,0,0,100,0),
(@PATH,42,2121.912,-275.3407,419.3569,0,0,0,0,100,0),
(@PATH,43,2118.654,-273.4102,419.3394,0,0,0,0,100,0),
(@PATH,44,2117.199,-268.2845,419.3498,0,0,0,0,100,0),
(@PATH,45,2115.841,-265.8998,419.338,0,0,0,0,100,0),
(@PATH,46,2117.146,-262.8446,419.355,0,0,0,0,100,0),
(@PATH,47,2115.978,-259.4841,419.3357,0,0,0,0,100,0),
(@PATH,48,2118.809,-254.888,419.3531,0,0,0,0,100,0),
(@PATH,49,2119.41,-251.5731,419.3389,0,0,0,0,100,0),
(@PATH,50,2122.509,-250.7787,419.3583,0,0,0,0,100,0),
(@PATH,51,2126.886,-245.9888,419.3408,0,0,0,0,100,0),
(@PATH,52,2129.464,-246.1551,419.355,0,0,0,0,100,0),
(@PATH,53,2131.827,-244.1449,419.341,0,0,0,0,100,0),
(@PATH,54,2136.154,-245.0502,419.3534,0,0,0,0,100,0),
(@PATH,55,2141.549,-244.8058,419.3344,0,0,0,0,100,0),
(@PATH,56,2143.05,-246.821,419.3423,0,0,0,0,100,0),
(@PATH,57,2146.519,-247.6339,419.329,0,0,0,0,100,0),
(@PATH,58,2147.463,-250.4655,419.3469,0,0,0,0,100,0),
(@PATH,59,2152.402,-254.7494,419.3326,0,0,0,0,100,0),
(@PATH,60,2151.59,-257.1805,419.3482,0,0,0,0,100,0),
(@PATH,61,2153.904,-260.1767,419.3406,0,0,0,0,100,0),
(@PATH,62,2153.267,-266.0408,419.351,0,0,0,0,100,0),
(@PATH,63,2153.278,-268.3502,419.3428,0,0,0,0,100,0),
(@PATH,64,2150.773,-270.5245,419.3516,0,0,0,0,100,0),
(@PATH,65,2150.336,-274.403,419.3373,0,0,0,0,100,0),
(@PATH,66,2145.726,-277.9905,419.3491,0,0,0,0,100,0),
(@PATH,67,2144.136,-279.593,419.3446,0,0,0,0,100,0),
(@PATH,68,2139.525,-280.3837,419.3511,0,0,0,0,100,0),
(@PATH,69,2138.497,-281.338,419.3466,0,0,0,0,100,0),
(@PATH,70,2131.909,-281.2193,419.3486,0,0,0,0,100,0),
(@PATH,71,2129.595,-281.2527,419.3445,0,0,0,0,100,0),
(@PATH,72,2126.887,-279.0773,419.3529,0,0,0,0,100,0),
(@PATH,73,2122.223,-277.9893,419.3402,0,0,0,0,100,0),
(@PATH,74,2119.887,-274.1609,419.3559,0,0,0,0,100,0),
(@PATH,75,2117.644,-271.9137,419.3447,0,0,0,0,100,0),
(@PATH,76,2118.074,-269.2574,419.3533,0,0,0,0,100,0),
(@PATH,77,2115.933,-266.7501,419.3349,0,0,0,0,100,0),
(@PATH,78,2116.676,-261.2225,419.3504,0,0,0,0,100,0),
(@PATH,79,2116.155,-258.1213,419.3394,0,0,0,0,100,0),
(@PATH,80,2118.745,-255.9958,419.3568,0,0,0,0,100,0),
(@PATH,81,2118.806,-252.5486,419.3358,0,0,0,0,100,0),
(@PATH,82,2123.463,-249.1763,419.3523,0,0,0,0,100,0),
(@PATH,83,2125.129,-246.4309,419.3435,0,0,0,0,100,0),
(@PATH,84,2128.552,-246.7562,419.3574,0,0,0,0,100,0),
(@PATH,85,2131.045,-244.2006,419.3389,0,0,0,0,100,0),
(@PATH,86,2136.584,-244.7589,419.3531,0,0,0,0,100,0),
(@PATH,87,2140.503,-244.3258,419.3321,0,0,0,0,100,0),
(@PATH,88,2142.273,-246.7659,419.3455,0,0,0,0,100,0),
(@PATH,89,2148.052,-249.1342,419.3279,0,0,0,0,100,0),
(@PATH,90,2148.786,-251.4895,419.3432,0,0,0,0,100,0),
(@PATH,91,2151.625,-253.8036,419.3301,0,0,0,0,100,0),
(@PATH,92,2151.014,-256.5103,419.3511,0,0,0,0,100,0);
-- 0xF130807C000057CC .go 2148.897 -275.9974 419.3439
