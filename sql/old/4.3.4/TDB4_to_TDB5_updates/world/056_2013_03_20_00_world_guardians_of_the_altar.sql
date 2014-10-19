-- Quest 4901 "Guardians of the Altar"

SET @NPC_RANSHALLA       := 10300;
SET @NPC_PRIESTESS_ELUNE := 12116;
SET @NPC_GUARDIAN_ELUNE  := 12140;
SET @NPC_VOICE_ELUNE     := 12152;

SET @GO_ELUNE_ALTAR      := 177404;
SET @GO_ELUNE_GEM        := 177414;
SET @GO_ELUNE_LIGHT      := 177415;
SET @GO_ELUNE_FIRE       := 177417;
-- SET @GO_GUID             := 9650;

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


-- creature
UPDATE `creature_template` SET `ScriptName`='npc_ranshalla' WHERE `entry`=@NPC_RANSHALLA;
UPDATE `creature_template` SET `unit_flags`=256 WHERE `entry`=@NPC_GUARDIAN_ELUNE; -- make guardian immune to PCs
-- gameobject
UPDATE `gameobject_template` SET `ScriptName`='go_elune_fire' WHERE `entry` IN (@GO_ELUNE_FIRE, @GO_ELUNE_ALTAR);
UPDATE `gameobject_template` SET `flags`=16 WHERE `entry`=@GO_ELUNE_ALTAR; -- stop people from touching altar early

-- EFFECT1 for 18953
DELETE FROM `spell_dbc` WHERE `id`=18954;
INSERT INTO `spell_dbc` (`id`, `Attributes`, `CastingTimeIndex`, `ProcChance`, `RangeIndex`, `EquippedItemClass`, `Effect1`, `EffectImplicitTargetA1`, `DmgMultiplier1`, `Comment`) VALUES
(18954, 256, 1, 101, 1, -1, 3, 1, 1, 'Ranshalla Despawn');
