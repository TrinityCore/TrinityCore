/*
 * Thorim
 */

DELETE FROM `creature_text` WHERE `CreatureID` IN (32865,32872,32873,33196);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextID`, `comment`) VALUES
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

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_thorim_blizzard_effect','spell_thorim_frostbolt_volley','spell_thorim_charge_orb','spell_thorim_runic_smash','spell_thorim_stormhammer','spell_thorim_lightning_charge','spell_thorim_stormhammer_sif','spell_thorim_stormhammer_boomerang','spell_thorim_activate_lightning_orb_periodic','spell_iron_ring_guard_impale','spell_thorim_arena_leap');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
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
UPDATE `spell_dbc` SET `SchoolMask`=0 WHERE `Id`=64980;
UPDATE `spelleffect_dbc` SET `EffectImplicitTargetA`=18, `EffectImplicitTargetB`=16, `EffectRadiusIndex`=28, `Effect`=3 WHERE `EffectSpellId`=64980;
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
UPDATE `creature_template` SET `ScriptName`='npc_runic_colossus' WHERE `entry`=32872;
UPDATE `creature_template` SET `ScriptName`='npc_ancient_rune_giant' WHERE `entry`=32873;
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|0x40000000 WHERE `entry` IN (32872, 32873, 33148, 33149);
UPDATE `creature_template` SET `difficulty_entry_1`=33150 WHERE `entry`=32908; -- Swapped Difficulty entry npcs
UPDATE `creature_template` SET `difficulty_entry_1`=33151 WHERE `entry`=32907; -- Caused swapped displayIDs in 25n
UPDATE `creature_template` SET `InhabitType`=4, `flags_extra`=128, `ScriptName`='' WHERE `entry` IN (33140,33141);
UPDATE `creature_template` SET `InhabitType`=4, `flags_extra`=128 WHERE `entry` IN (33378,32879);
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry` IN (32892);
UPDATE `creature_template` SET `faction`=1692 WHERE `entry` IN (32885,32883,33152,33153,32908,33150,32907,33151);
UPDATE `creature_template` SET `faction`=1693 WHERE `entry` IN (32882,33154);
UPDATE `creature_template` SET `speed_walk`=2.5/2.5, `speed_run`=14.0/7.0, `BaseAttackTime`=1500, `RangeAttackTime`=1500, `flags_extra`=`flags_extra`|0x00000200 WHERE `entry` IN (32865,33147);

SET @THORIM_BLIZZARD_BUNNY := 136515;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (62577,62603,62016,62976,63238,64098,62466,62565,62942,64767,62560,61964,61934);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 62577, 0, 0, 31, 0, 3, 32892, @THORIM_BLIZZARD_BUNNY, 0, 0, 0, '', 'Spell Blizzard (effect 0) will hit the potential target of the spell if target is unit Thorim Event Bunny guid 136515.'),
(13, 1, 62603, 0, 0, 31, 0, 3, 32892, @THORIM_BLIZZARD_BUNNY, 0, 0, 0, '', 'Spell Blizzard (effect 0) will hit the potential target of the spell if target is unit Thorim Event Bunny guid 136515.'),
(13, 1, 62016, 0, 0, 31, 0, 3, 33378, 0, 0, 0, 0, '', 'Spell Charge Orb (effect 0) will hit the potential target of the spell if target is unit Thunder Orb.'),
(13, 1, 62976, 0, 0, 31, 0, 3, 33378, 0, 0, 0, 0, '', 'Spell Lightning Pillar (effect 0) will hit the potential target of the spell if target is unit Thunder Orb.'),
(13, 1, 62976, 0, 0, 33, 0, 1, 0, 0, 1, 0, 0, '', 'Spell Lightning Pillar (effect 0) will hit the potential target of the spell if target is not the same as condition target.'),
(13, 1, 63238, 0, 0, 31, 0, 3, 33378, 0, 0, 0, 0, '', 'Spell Lightning Pillar (effect 0) will hit the potential target of the spell if target is unit Thunder Orb.'),
(13, 1, 63238, 0, 0, 33, 0, 1, 0, 0, 1, 0, 0, '', 'Spell Lightning Pillar (effect 0) will hit the potential target of the spell if target is not the same as condition target.'),
(13, 1, 64098, 0, 0, 31, 0, 3, 32865, 0, 0, 0, 0, '', 'Spell Lightning Bolt (effect 0) will hit the potential target of the spell if target is unit Thorim.'),
(13, 4, 62466, 0, 0, 31, 0, 3, 32780, 0, 0, 0, 0, '', 'Spell Lightning Charge (effect 2) will hit the potential target of the spell if target is unit Invisible Stalker (All Phases).'),
(13, 3, 62565, 0, 0, 31, 0, 3, 32865, 0, 0, 0, 0, '', 'Spell Touch of Dominion (effects 0 & 1) will hit the potential target of the spell if target is unit Thorim.'),
(13, 7, 62942, 0, 0, 31, 0, 3, 32874, 0, 0, 0, 0, '', 'Spell Runic Fortification (effect 0 & 1 & 2) will hit the potential target of the spell if target is unit Iron Ring Guard.'),
(13, 7, 62942, 0, 1, 31, 0, 3, 32875, 0, 0, 0, 0, '', 'Spell Runic Fortification (effect 0 & 1 & 2) will hit the potential target of the spell if target is unit Iron Honor Guard.'),
(13, 7, 62942, 0, 2, 31, 0, 3, 33110, 0, 0, 0, 0, '', 'Spell Runic Fortification (effect 0 & 1 & 2) will hit the potential target of the spell if target is unit Dark Rune Acolyte.'),
(13, 1, 64767, 0, 0, 31, 0, 3, 33196, 0, 0, 0, 0, '', 'Spell Stormhammer (effect 0) will hit the potential target of the spell if target is unit Sif.'),
(13, 7, 62560, 0, 0, 31, 0, 3, 32876, 0, 0, 0, 0, '', 'Spell Berserk (effect 0 & 1 & 2) will hit the potential target of the spell if target is unit Dark Rune Champion.'),
(13, 7, 62560, 0, 1, 31, 0, 3, 32877, 0, 0, 0, 0, '', 'Spell Berserk (effect 0 & 1 & 2) will hit the potential target of the spell if target is unit Dark Rune Warbringer.'),
(13, 7, 62560, 0, 2, 31, 0, 3, 32878, 0, 0, 0, 0, '', 'Spell Berserk (effect 0 & 1 & 2) will hit the potential target of the spell if target is unit Dark Rune Evoker.'),
(13, 7, 62560, 0, 3, 31, 0, 3, 32904, 0, 0, 0, 0, '', 'Spell Berserk (effect 0 & 1 & 2) will hit the potential target of the spell if target is unit Dark Rune Commoner.'),
(13, 1, 61964, 0, 0, 31, 0, 3, 32882, 0, 0, 0, 0, '', 'Spell Circle of Healing (effect 0) will hit the potential target of the spell if target is unit Jormungar Behemoth.'),
(13, 1, 61964, 0, 1, 31, 0, 3, 32883, 0, 0, 0, 0, '', 'Spell Circle of Healing (effect 0) will hit the potential target of the spell if target is unit Captured Mercenary Soldier.'),
(13, 1, 61964, 0, 2, 31, 0, 3, 32885, 0, 0, 0, 0, '', 'Spell Circle of Healing (effect 0) will hit the potential target of the spell if target is unit Captured Mercenary Soldier.'),
(13, 1, 61964, 0, 3, 31, 0, 3, 32886, 0, 0, 0, 0, '', 'Spell Circle of Healing (effect 0) will hit the potential target of the spell if target is unit Dark Rune Acolyte.'),
(13, 1, 61964, 0, 4, 31, 0, 3, 32907, 0, 0, 0, 0, '', 'Spell Circle of Healing (effect 0) will hit the potential target of the spell if target is unit Captured Mercenary Captain.'),
(13, 1, 61964, 0, 5, 31, 0, 3, 32908, 0, 0, 0, 0, '', 'Spell Circle of Healing (effect 0) will hit the potential target of the spell if target is unit Captured Mercenary Captain.'),
(13, 1, 61934, 0, 0, 31, 0, 3, 32892, 0, 0, 0, 0, 'condition_thorim_arena_leap', 'Spell Leap (effect 0) will hit the potential target of the spell if target is unit Thorim Event Bunny.'),
(13, 1, 61934, 0, 0, 31, 0, 3, 32892, @THORIM_BLIZZARD_BUNNY, 1, 0, 0, '', 'Spell Leap (effect 0) will hit the potential target of the spell if target is not unit Thorim Event Bunny guid 136515.');

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
SET @PATH := @THORIM_BLIZZARD_BUNNY * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2148.425,`position_y`=-276.7478,`position_z`=419.5923 WHERE `guid`=@THORIM_BLIZZARD_BUNNY;
DELETE FROM `creature_addon` WHERE `guid`=@THORIM_BLIZZARD_BUNNY;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@THORIM_BLIZZARD_BUNNY,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2148.425,-276.7478,419.5923,0,0,0,0,100,0),
(@PATH,2,2145.229,-278.5732,419.6016,0,0,0,0,100,0),
(@PATH,3,2142.105,-280.7194,419.5932,0,0,0,0,100,0),
(@PATH,4,2138.419,-281.2838,419.5999,0,0,0,0,100,0),
(@PATH,5,2134.843,-281.9885,419.5996,0,0,0,0,100,0),
(@PATH,6,2131.128,-281.278,419.5985,0,0,0,0,100,0),
(@PATH,7,2127.415,-280.8166,419.5875,0,0,0,0,100,0),
(@PATH,8,2124.459,-278.4777,419.6088,0,0,0,0,100,0),
(@PATH,9,2121.098,-276.7148,419.5924,0,0,0,0,100,0),
(@PATH,10,2119.281,-273.4217,419.6069,0,0,0,0,100,0),
(@PATH,11,2116.933,-270.4605,419.5851,0,0,0,0,100,0),
(@PATH,12,2116.359,-266.7142,419.6042,0,0,0,0,100,0),
(@PATH,13,2115.436,-263.0562,419.5847,0,0,0,0,100,0),
(@PATH,14,2116.543,-259.411,419.6082,0,0,0,0,100,0),
(@PATH,15,2116.943,-255.605,419.5851,0,0,0,0,100,0),
(@PATH,16,2119.377,-252.7493,419.6096,0,0,0,0,100,0),
(@PATH,17,2121.183,-249.3546,419.5858,0,0,0,0,100,0),
(@PATH,18,2124.49,-247.5925,419.6089,0,0,0,0,100,0),
(@PATH,19,2127.329,-245.1714,419.5925,0,0,0,0,100,0),
(@PATH,20,2131.097,-244.8609,419.6089,0,0,0,0,100,0),
(@PATH,21,2134.792,-243.7036,419.585,0,0,0,0,100,0),
(@PATH,22,2138.466,-244.3162,419.5979,0,0,0,0,100,0),
(@PATH,23,2142.386,-244.7266,419.5746,0,0,0,0,100,0),
(@PATH,24,2145.455,-247.1502,419.5968,0,0,0,0,100,0),
(@PATH,25,2148.564,-249.0781,419.5791,0,0,0,0,100,0),
(@PATH,26,2150.63,-252.4069,419.598,0,0,0,0,100,0),
(@PATH,27,2153.104,-255.5907,419.5758,0,0,0,0,100,0),
(@PATH,28,2153.286,-259.4698,419.6053,0,0,0,0,100,0),
(@PATH,29,2154.193,-263.0425,419.6039,0,0,0,0,100,0),
(@PATH,30,2153.279,-266.768,419.6026,0,0,0,0,100,0),
(@PATH,31,2152.758,-270.5462,419.5822,0,0,0,0,100,0),
(@PATH,32,2150.38,-273.4614,419.605,0,0,0,0,100,0);
