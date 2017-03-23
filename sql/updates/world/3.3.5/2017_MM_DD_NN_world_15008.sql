/*
 * Thorim
 */

-- todo: immunity runic colossus, rune giant grip and knockback

DELETE FROM `creature_text` WHERE `CreatureID` IN (32865,32872,32873,33196);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextID`, `comment`) VALUES
-- Thorim
(32865, 0,0,'Interlopers! You mortals who dare to interfere with my sport will pay... Wait--you...',14,0,100,0,0,15733,33145,'Thorim SAY_AGGRO_1'),
(32865, 1,0,'I remember you... In the mountains... But you... what is this? Where am--',14,0,100,0,0,15734,33270,'Thorim SAY_AGGRO_2'),
(32865, 2,0,'Behold the power of the storms and despair!',14,0,100,0,0,15735,0,'Thorim SAY_SPECIAL_1'),
(32865, 3,0,'Do not hold back! Destroy them!',14,0,100,0,0,15736,34241,'Thorim SAY_SPECIAL_2'),
(32865, 4,0,'Have you begun to regret your intrusion?',14,0,100,0,0,15737,0,'Thorim SAY_SPECIAL_3'),
(32865, 5,0,'Impertinent whelps, you dare challenge me atop my pedestal? I will crush you myself!',14,0,100,0,0,15738,33148,'Thorim SAY_JUMPDOWN'),
(32865, 6,0,'Can''t you at least put up a fight!?',14,0,100,0,0,15739,34239,'Thorim SAY_SLAY_1'),
(32865, 6,1,'Pathetic.',14,0,100,0,0,15740,35768,'Thorim SAY_SLAY_2'),
(32865, 7,0,'My patience has reached its limit!',14,0,100,0,0,15741,33365,'Thorim SAY_BERSERK'),
(32865, 8,0,'Failures! Weaklings!',14,0,100,0,0,15742,33274,'Thorim SAY_WIPE'),
(32865, 9,0,'Stay your arms! I yield!',14,0,100,0,0,15743,33948,'Thorim SAY_DEATH'),
(32865,10,0,'I feel as though I am awakening from a nightmare, but the shadows in this place yet linger.',14,0,100,0,0,15744,33949,'Thorim SAY_END_NORMAL_1'),
(32865,11,0,'Sif... was Sif here? Impossible--she died by my brother''s hand. A dark nightmare indeed....',14,0,100,0,0,15745,33950,'Thorim SAY_END_NORMAL_2'),
(32865,12,0,'I need time to reflect.... I will aid your cause if you should require it. I owe you at least that much. Farewell.',14,0,100,0,0,15746,33951,'Thorim SAY_END_NORMAL_3'),
(32865,13,0,'You! Fiend! You are not my beloved! Be gone!',14,0,100,0,0,15747,33952,'Thorim SAY_END_HARD_1'),
(32865,14,0,'Behold the hand behind all the evil that has befallen Ulduar, left my kingdom in ruins, corrupted my brother, and slain my wife.',14,0,100,0,0,15748,33953,'Thorim SAY_END_HARD_2'),
(32865,15,0,'And now it falls to you, champions, to avenge us all. The task before you is great, but I will lend you my aid as I am able. You must prevail.',14,0,100,0,0,15749,33954,'Thorim SAY_END_HARD_3'),
-- Runic Colossus
(32872, 0,0,'%s surrounds itself with a crackling Runic Barrier!',41,0,100,0,0,0,33267,'Runic Colossus'),
-- Ancient Rune Giant
(32873, 0,0,'%s fortifies nearby allies with runic might!',41,0,100,0,0,0,33523,'Ancient Rune Giant'),
-- Sif
(33196, 0,0,'Thorim, my lord!  Why else would these invaders have come into your sanctum but to slay you?  They must be stopped!',14,0,100,0,0,15668,33325,'Sif - Start'),
(33196, 1,0,'These pathetic mortals are harmless, beneath my station.  Dispose of them!',14,0,100,0,0,15669,33368,'Sif - Despawn'),
(33196, 2,0,'Impossible!  Lord Thorim, I will bring your foes a frigid death!',14,0,100,0,0,15670,33369,'Sif - Event');

UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=194265;
DELETE FROM `smart_scripts` WHERE `entryorguid`=194265 AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(194265,1,0,0,70,0,100,0,2,0,0,0,9,0,0,0,0,0,0,14,34155,0,0,0,0,0,0, 'Lever - On activate - Activate Dark Iron Portcullis');

DELETE FROM `spell_script_names` WHERE `spell_id` IN (62577,62603,62576,62602,62580,62604,62016,62057,62058,62042,62466,64767);
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
(64767,'spell_thorim_stormhammer_sif');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=62042;

DELETE FROM `spelldifficulty_dbc` WHERE `id` IN (62131,62315,62316,62333,62334,62335,62327,62328,62321,62331,62332,62583,62577,62597,62580);
INSERT INTO `spelldifficulty_dbc` (`id`, `spellid0`, `spellid1`) VALUES
(62131,62131,64390),
(62315,62315,62415),
(62316,62316,62417),
(62333,62333,62441),
(62334,62334,62442),
(62335,62335,62443),
(62327,62327,62445),
(62328,62328,62446),
(62321,62321,62529),
(62331,62331,62418),
(62332,62332,62420),
(62583,62583,62601),
(62577,62577,62603),
(62597,62597,62605),
(62580,62580,62604);

UPDATE `creature_template` SET `InhabitType`=4, `flags_extra`=128, `ScriptName`='' WHERE `entry` IN (33140,33141);
UPDATE `creature_template` SET `InhabitType`=4, `flags_extra`=128 WHERE `entry` IN (33054,33378);
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry` IN (32892);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (62577,62603,62016,62976,63238,64098,62466,62565,62942,64767,62560,61964);
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
(13,1,61964,0,5,31,0,3,32908,0,0,0,'','Thorim - Circle of Healing');

DELETE FROM `disables` WHERE `sourceType`=4 AND `entry` IN (10289,10314,10304,10313,10440,10457,10800,10801);
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES
(4,10800,0,0,0,'Siffed (10 player) - Duplicate'),
(4,10801,0,0,0,'Siffed (25 player) - Duplicate');

DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (10289,10314,10305,10309,10440,10457);
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
(10457,12,1,0,'');                               -- Lose Your Illusion (25 player)

UPDATE `gameobject_template` SET `size`=3 WHERE `entry` IN (194312,194313,194314,194315);
UPDATE `gameobject_template_addon` SET `faction`=94 WHERE `entry` IN (194312,194313,194314,194315);

DELETE FROM `gameobject` WHERE `id` IN (194312,194313,194314,194315);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) values
(360300,194312,603,1,1,2134.948,-286.436,419.5051,1.588249,0,0,0.7132502,0.7009096,-604800,255,1,0),
(360301,194313,603,1,1,2134.948,-286.436,419.5051,1.588249,0,0,0.7132502,0.7009096,-604800,255,1,0),
(360302,194314,603,2,1,2134.948,-286.436,419.5051,1.588249,0,0,0.7132502,0.7009096,-604800,255,1,0),
(360303,194315,603,2,1,2134.948,-286.436,419.5051,1.588249,0,0,0.7132502,0.7009096,-604800,255,1,0);

DELETE FROM `creature` WHERE `id`=32892 AND `position_z` < 425.0;
