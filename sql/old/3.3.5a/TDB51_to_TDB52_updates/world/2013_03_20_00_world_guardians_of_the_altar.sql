-- Quest 4901 "Guardians of the Altar"

SET @NPC_RANSHALLA       := 10300;
SET @NPC_PRIESTESS_ELUNE := 12116;
SET @NPC_GUARDIAN_ELUNE  := 12140;
SET @NPC_VOICE_ELUNE     := 12152;

SET @GO_ELUNE_ALTAR      := 177404;
SET @GO_ELUNE_GEM        := 177414;
SET @GO_ELUNE_LIGHT      := 177415;
SET @GO_ELUNE_FIRE       := 177417;
SET @GO_GUID             := 9650; -- Need 7 guids

-- script_texts for the quest
DELETE FROM `creature_text` WHERE `entry` IN (@NPC_RANSHALLA, @NPC_PRIESTESS_ELUNE, @NPC_VOICE_ELUNE);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@NPC_RANSHALLA,0,0, 'Remember, I need your help to properly channel. I will ask you to aid me several times in our path, so please be ready.',12,0,100,0,0,0, 'Ranshalla SAY_QUEST_START'),
(@NPC_RANSHALLA,1,0, 'This blue light... It''s strange. What do you think it means?',12,0,100,25,0,0, 'Ranshalla SAY_ENTER_OWL_THICKET'),
(@NPC_RANSHALLA,2,0, 'We''ve found it!',12,0,100,0,0,0, 'Ranshalla SAY_REACH_TORCH_1'),
(@NPC_RANSHALLA,2,1, 'Please, light this while I am channeling',12,0,100,0,0,0, 'Ranshalla SAY_REACH_TORCH_2'),
(@NPC_RANSHALLA,2,2, 'This is the place. Let''s light it.',12,0,100,0,0,0, 'Ranshalla SAY_REACH_TORCH_3'),
(@NPC_RANSHALLA,3,0, 'Let''s find the next one.',12,0,100,0,0,0, 'Ranshalla SAY_AFTER_TORCH_1'),
(@NPC_RANSHALLA,3,1, 'We must continue on now.',12,0,100,0,0,0, 'Ranshalla SAY_AFTER_TORCH_2'),
(@NPC_RANSHALLA,4,0, 'It is time for the final step; we must activate the altar.',12,0,100,0,0,0, 'Ranshalla SAY_REACH_ALTAR_1'),
(@NPC_RANSHALLA,5,0, 'I will read the words carved into the stone, and you must find a way to light it.',12,0,100,0,0,0, 'Ranshalla SAY_REACH_ALTAR_2'),
(@NPC_RANSHALLA,6,0, 'The altar is glowing! We have done it!',12,0,100,0,0,0, 'Ranshalla SAY_RANSHALLA_ALTAR_1'),
(@NPC_RANSHALLA,7,0, 'What is happening? Look!',12,0,100,0,0,0, 'Ranshalla SAY_RANSHALLA_ALTAR_2'),
(@NPC_PRIESTESS_ELUNE,8,0, 'It has been many years...',12,0,100,0,0,0, 'Priestess of Elune SAY_PRIESTESS_ALTAR_3'),
(@NPC_PRIESTESS_ELUNE,9,0, 'Who has disturbed the altar of the goddess?',12,0,100,0,0,0, 'Priestess of Elune SAY_PRIESTESS_ALTAR_4'),
(@NPC_RANSHALLA,10,0, 'Please, priestesses, forgive us for our intrusion. We do not wish any harm here.',12,0,100,0,0,0, 'Ranshalla SAY_RANSHALLA_ALTAR_5'),
(@NPC_RANSHALLA,11,0, 'We only wish to know why the wildkin guard this area...',12,0,100,0,0,0, 'Ranshalla SAY_RANSHALLA_ALTAR_6'),
(@NPC_PRIESTESS_ELUNE,12,0, 'Enu thora''serador. This is a sacred place.',12,0,100,0,0,0, 'Priestess of Elune SAY_PRIESTESS_ALTAR_7'),
(@NPC_PRIESTESS_ELUNE,13,0, 'We will show you...',12,0,100,0,0,0, 'Priestess of Elune SAY_PRIESTESS_ALTAR_8'),
(@NPC_PRIESTESS_ELUNE,14,0, 'Look above you; thara dormil dorah...',12,0,100,0,0,0, 'Priestess of Elune SAY_PRIESTESS_ALTAR_9'),
(@NPC_PRIESTESS_ELUNE,15,0, 'This gem once allowed direct communication with Elune, herself.',12,0,100,0,0,0, 'Priestess of Elune SAY_PRIESTESS_ALTAR_10'),
(@NPC_PRIESTESS_ELUNE,16,0, 'Through the gem, Elune channeled her infinite wisdom...',12,0,100,0,0,0, 'Priestess of Elune SAY_PRIESTESS_ALTAR_11'),
(@NPC_PRIESTESS_ELUNE,17,0, 'Realizing that the gem needed to be protected, we turned to the goddess herself.',12,0,100,0,0,0, 'Priestess of Elune SAY_PRIESTESS_ALTAR_12'),
(@NPC_PRIESTESS_ELUNE,18,0, 'Soon after, we began to have visions of a creature... A creature with the feathers of an owl, but the will and might of a bear...',12,0,100,0,0,0, 'Priestess of Elune SAY_PRIESTESS_ALTAR_13'),
(@NPC_PRIESTESS_ELUNE,19,0, 'It was on that day that the wildkin were given to us. Fierce guardians, the goddess assigned the wildkin to protect all of her sacred places.',12,0,100,0,0,0, 'Priestess of Elune SAY_PRIESTESS_ALTAR_14'),
(@NPC_VOICE_ELUNE,20,0, 'Anu''dorini Talah, Ru shallora enudoril.',12,0,100,0,0,0, 'Voice of Elune SAY_VOICE_ALTAR_15'),
(@NPC_PRIESTESS_ELUNE,21,0, 'But now, many years later, the wildkin have grown more feral, and without the guidance of the goddess, they are confused...',12,0,100,0,0,0, 'Priestess of Elune SAY_PRIESTESS_ALTAR_16'),
(@NPC_PRIESTESS_ELUNE,22,0, 'Without a purpose, they wander... But many find their way back to the sacred areas that they once were sworn to protect.',12,0,100,0,0,0, 'Priestess of Elune SAY_PRIESTESS_ALTAR_17'),
(@NPC_PRIESTESS_ELUNE,23,0, 'Wildkin are inherently magical; this power was bestowed upon them by the goddess.',12,0,100,0,0,0, 'Priestess of Elune SAY_PRIESTESS_ALTAR_18'),
(@NPC_PRIESTESS_ELUNE,24,0, 'Know that wherever you might find them in the world, they are protecting something of importance, as they were entrusted to do so long ago.',12,0,100,0,0,0, 'Priestess of Elune SAY_PRIESTESS_ALTAR_19'),
(@NPC_PRIESTESS_ELUNE,25,0, 'Please, remember what we have shown you...',12,0,100,0,0,0, 'Priestess of Elune SAY_PRIESTESS_ALTAR_20'),
(@NPC_PRIESTESS_ELUNE,26,0, 'Farewell.',12,0,100,0,0,0, 'Priestess of Elune SAY_PRIESTESS_ALTAR_21'),
(@NPC_RANSHALLA,27,0, 'Thank you for you help, $N. I wish you well in your adventures.',12,0,100,0,0,0, 'Ranshalla SAY_RANSHALLA_END_1'),
(@NPC_RANSHALLA,28,0, 'I want to stay here and reflect on what we have seen. Please see Erelas and tell him what we have learned.',12,0,100,0,0,0, 'Ranshalla SAY_RANSHALLA_END_2'),
(@NPC_RANSHALLA,29,0, '%s begins chanting a strange spell...',16,0,100,0,0,0, 'Ranshalla EMOTE_CHANT_SPELL');

-- Waypoints for Ranshalla
DELETE FROM `script_waypoint` WHERE `entry`=@NPC_RANSHALLA;
INSERT INTO `script_waypoint` (`entry`,`pointid`,`location_x`,`location_y`,`location_z`,`waittime`,`point_comment`) VALUES
(@NPC_RANSHALLA, 1, 5720.45, -4798.45, 778.23, 0, ''),
(@NPC_RANSHALLA, 2, 5730.22, -4818.34, 777.11, 0, ''),
(@NPC_RANSHALLA, 3, 5728.12, -4835.76, 778.15, 1000, 'SAY_ENTER_OWL_THICKET'),
(@NPC_RANSHALLA, 4, 5718.85, -4865.62, 787.56, 0, ''),
(@NPC_RANSHALLA, 5, 5697.13, -4909.12, 801.53, 0, ''),
(@NPC_RANSHALLA, 6, 5684.20, -4913.75, 801.60, 0, ''),
(@NPC_RANSHALLA, 7, 5674.67, -4915.78, 802.13, 0, ''),
(@NPC_RANSHALLA, 8, 5665.61, -4919.22, 804.85, 0, ''),
(@NPC_RANSHALLA, 9, 5638.22, -4897.58, 804.97, 0, ''),
(@NPC_RANSHALLA, 10, 5632.67, -4892.05, 805.44, 0, 'Cavern 1 - EMOTE_CHANT_SPELL'),
(@NPC_RANSHALLA, 11, 5664.58, -4921.84, 804.91, 0, ''),
(@NPC_RANSHALLA, 12, 5684.21, -4943.81, 802.80, 0, ''),
(@NPC_RANSHALLA, 13, 5724.92, -4983.69, 808.25, 0, ''),
(@NPC_RANSHALLA, 14, 5753.39, -4990.73, 809.84, 0, ''),
(@NPC_RANSHALLA, 15, 5765.62, -4994.89, 809.42, 0, 'Cavern 2 - EMOTE_CHANT_SPELL'),
(@NPC_RANSHALLA, 16, 5724.94, -4983.58, 808.29, 0, ''),
(@NPC_RANSHALLA, 17, 5699.61, -4989.82, 808.03, 0, ''),
(@NPC_RANSHALLA, 18, 5686.80, -5012.17, 807.27, 0, ''),
(@NPC_RANSHALLA, 19, 5691.43, -5037.43, 807.73, 0, ''),
(@NPC_RANSHALLA, 20, 5694.24, -5054.64, 808.85, 0, 'Cavern 3 - EMOTE_CHANT_SPELL'),
(@NPC_RANSHALLA, 21, 5686.88, -5012.18, 807.23, 0, ''),
(@NPC_RANSHALLA, 22, 5664.94, -5001.12, 807.78, 0, ''),
(@NPC_RANSHALLA, 23, 5647.12, -5002.84, 807.54, 0, ''),
(@NPC_RANSHALLA, 24, 5629.23, -5014.88, 807.94, 0, ''),
(@NPC_RANSHALLA, 25, 5611.26, -5025.62, 808.36, 0, 'Cavern 4 - EMOTE_CHANT_SPELL'),
(@NPC_RANSHALLA, 26, 5647.13, -5002.85, 807.57, 0, ''),
(@NPC_RANSHALLA, 27, 5641.12, -4973.22, 809.39, 0, ''),
(@NPC_RANSHALLA, 28, 5622.97, -4953.58, 811.12, 0, ''),
(@NPC_RANSHALLA, 29, 5601.52, -4939.49, 820.77, 0, ''),
(@NPC_RANSHALLA, 30, 5571.87, -4936.22, 831.35, 0, ''),
(@NPC_RANSHALLA, 31, 5543.23, -4933.67, 838.33, 0, ''),
(@NPC_RANSHALLA, 32, 5520.86, -4942.05, 843.02, 0, ''),
(@NPC_RANSHALLA, 33, 5509.15, -4946.31, 849.36, 0, ''),
(@NPC_RANSHALLA, 34, 5498.45, -4950.08, 849.98, 0, ''),
(@NPC_RANSHALLA, 35, 5485.78, -4963.40, 850.43, 0, ''),
(@NPC_RANSHALLA, 36, 5467.92, -4980.67, 851.89, 0, 'Cavern 5 - EMOTE_CHANT_SPELL'),
(@NPC_RANSHALLA, 37, 5498.68, -4950.45, 849.96, 0, ''),
(@NPC_RANSHALLA, 38, 5518.68, -4921.94, 844.65, 0, ''),
(@NPC_RANSHALLA, 39, 5517.66, -4920.82, 845.12, 0, 'SAY_REACH_ALTAR_1'),
(@NPC_RANSHALLA, 40, 5518.38, -4913.47, 845.57, 0, ''),
(@NPC_RANSHALLA, 41, 5511.31, -4913.82, 847.17, 5000, 'light the spotlights'),
(@NPC_RANSHALLA, 42, 5511.31, -4913.82, 847.17, 0, 'start altar cinematic - SAY_RANSHALLA_ALTAR_2'),
(@NPC_RANSHALLA, 43, 5510.47, -4922.38, 846.07, 0, ''),
(@NPC_RANSHALLA, 44, 5517.66, -4920.82, 845.12, 0, 'escort paused'),
(@NPC_RANSHALLA, 45, 5517.6, -4920.8, 845.12, 0, 'dummy to stop despawn');

-- creature
UPDATE `creature_template` SET `ScriptName`='npc_ranshalla' WHERE `entry`=@NPC_RANSHALLA;
UPDATE `creature_template` SET `unit_flags`=256 WHERE `entry`=@NPC_GUARDIAN_ELUNE; -- make guardian immune to PCs
-- gameobject
UPDATE `gameobject_template` SET `ScriptName`='go_elune_fire' WHERE `entry` IN (@GO_ELUNE_FIRE, @GO_ELUNE_ALTAR);
UPDATE `gameobject_template` SET `flags`=16 WHERE `entry`=@GO_ELUNE_ALTAR; -- stop people from touching altar early
-- Light and Gem Spawns
DELETE FROM `gameobject` WHERE `id` IN (@GO_ELUNE_GEM, @GO_ELUNE_LIGHT);
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(@GO_GUID+0,@GO_ELUNE_LIGHT,1,1,1,5515.71,-4905.82,846.322,4.62478,0,0,0.737392,-0.675466,-600,255,1),
(@GO_GUID+1,@GO_ELUNE_LIGHT,1,1,1,5505.09,-4909.36,848.961,5.63402,0,0,0.318914,-0.947784,-600,255,1),
(@GO_GUID+2,@GO_ELUNE_LIGHT,1,1,1,5501.69,-4920.04,848.791,0.155868,0,0,0.0778553,0.996965,-600,255,1),
(@GO_GUID+3,@GO_ELUNE_LIGHT,1,1,1,5510.28,-4929.31,845.214,1.62064,0,0,0.724507,0.689267,-600,255,1),
(@GO_GUID+4,@GO_ELUNE_LIGHT,1,1,1,5520.35,-4925.22,843.644,2.13507,0,0,0.876015,0.482283,-600,255,1),
(@GO_GUID+5,@GO_ELUNE_LIGHT,1,1,1,5526.7,-4916.41,843.452,3.01865,0,0,0.998111,0.0614331,-600,255,1),
(@GO_GUID+6,@GO_ELUNE_GEM,1,1,1,5514.49,-4917.57,850.538,2.3911,0,0,0.930417,0.366502,-900,100,1);

-- EFFECT1 for 18953
DELETE FROM `spell_dbc` WHERE `id`=18954;
INSERT INTO `spell_dbc` (`id`, `Attributes`, `CastingTimeIndex`, `ProcChance`, `RangeIndex`, `EquippedItemClass`, `Effect1`, `EffectImplicitTargetA1`, `DmgMultiplier1`, `Comment`) VALUES
(18954, 256, 1, 101, 1, -1, 3, 1, 1, 'Ranshalla Despawn');
