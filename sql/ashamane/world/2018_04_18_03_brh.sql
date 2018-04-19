UPDATE creature_template SET inhabitType = 4 WHERE entry in (99664, 100759, 103662);
DELETE FROM creature WHERE id = 111706;

UPDATE creature_template SET scriptname = "boss_illysanna_ravencrest" WHERE entry = 98696;
UPDATE creature_template SET scriptname = "npc_soultorn_vanguard" WHERE entry = 100485;
UPDATE creature_template SET scriptname = "npc_risen_arcanist" WHERE entry = 100486;

UPDATE creature_template SET scriptname = "npc_brh_boulder" WHERE entry = 111706;
UPDATE areatrigger_template SET scriptname = "at_brh_boulder" WHERE Id = 12428;

UPDATE creature_template SET scriptname = "boss_smashspite_the_hateful" WHERE entry = 98949;
UPDATE creature_template SET scriptname = "npc_brh_felbat" WHERE entry = 100759;

DELETE FROM spell_script_names WHERE scriptname = "aura_smashspite_brutality";
INSERT INTO spell_script_names VALUES
(198114, "aura_smashspite_brutality");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (196930, 198961, 199368);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTarget`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`) VALUES
(13, 1, 196930, 1, 31, 3, 98542),
(13, 1, 198961, 1, 31, 3, 98965),
(13, 1, 199368, 1, 31, 4, 0);

UPDATE creature_template SET scriptname = "boss_kurtalos_ravencrest" WHERE entry = 98965;
UPDATE creature_template SET scriptname = "npc_kurtalos_whirling_blade" WHERE entry = 100861;
UPDATE areatrigger_template SET scriptname = "at_kurtalos_whirling_blade" WHERE Id = 10185;
UPDATE creature_template SET scriptname = "npc_latosius" WHERE entry = 98970;
UPDATE creature_template SET scriptname = "npc_kurtalos_soul" WHERE entry = 101054;
UPDATE areatrigger_template SET scriptname = "at_dantalionax_cloud_of_hypnosis" WHERE Id = 10200;
UPDATE creature_template SET scriptname = "npc_dantalionax_cloud_of_hypnosis" WHERE entry = 100994;
UPDATE creature_template SET scriptname = "npc_dantalionax_stinging_swarm" WHERE entry = 101008;

DELETE FROM creature WHERE id IN (100861, 101054, 111833);
UPDATE `creature_template` SET `minlevel` = 112 , `maxlevel` = 112 , `faction` = 16 , `BaseAttackTime` = 2000 , `RangeAttackTime` = 2000 , `unit_flags` = 32768 , `unit_flags2` = 2099200 , `type` = 3 WHERE `entry` = 99611; 
UPDATE `creature_template` SET `minlevel` = 112 , `maxlevel` = 112 , `faction` = 16 , `BaseAttackTime` = 2000 , `RangeAttackTime` = 2000 WHERE `entry` IN (101008, 100485, 100486);

DELETE FROM creature_template_addon WHERE entry IN (101008);
INSERT INTO creature_template_addon (`entry`, `auras`) VALUES
(101008, "199160");

DELETE FROM `spell_area` WHERE `spell` = 199368;
INSERT INTO `spell_area` (`spell`, `area`, `flags`) VALUES
(199368, 7805, 2);

UPDATE `areatrigger` SET ScriptName = "" WHERE guid IN (5, 6);
DELETE FROM `areatrigger_teleport` WHERE ID IN (-5, -6);
INSERT INTO `areatrigger_teleport` VALUES
(-5, 5352, "BlackRook Hold entrance"),
(-6, 5353, "BlackRook Hold exit");

UPDATE creature SET orientation = 5.646474 WHERE guid = 21012083;
UPDATE creature SET orientation = 5.925279 WHERE guid = 21012097;
UPDATE creature SET orientation = 2.159289 WHERE guid = 21012096;

UPDATE creature_template SET mechanic_immune_mask = 617299839, flags_extra = 268435456 WHERE entry IN (99611, 98970);

SET @GROUP_ID := 0;
SET @ID := 0;

DELETE FROM `creature_text` WHERE `CreatureID` IN (98542, 98696, 98706, 98792, 98810, 98900, 98949, 98965, 98970, 99857);
INSERT INTO `creature_text` (`CreatureID`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(98542, 200,         @ID+0, 'Consume! Devour!', 14, 0, 100, 0, 0, 54518, 0, 'Amalgam of Souls'),
(98542, 201,         @ID+0, 'The harvest has come!', 14, 0, 100, 0, 0, 54516, 0, 'Amalgam of Souls to Player'),
(98542, 0,           @ID+0, 'Leave this meager vessel, and join us...', 14, 0, 100, 0, 0, 54564, 0, 'Amalgam of Souls to Player'),
(98542, 202,         @ID+0, 'I feed on your essence...', 14, 0, 100, 0, 0, 54522, 0, 'Amalgam of Souls'),

(98696, 200,         @ID+0, 'We will bury you here, fools.', 14, 0, 100, 0, 0, 54515, 0, 'Illysanna Ravencrest'),
(98696, 201,         @ID+0, 'You can not escape.', 14, 0, 100, 0, 0, 54561, 0, 'Illysanna Ravencrest to Player'),
(98696, @GROUP_ID+0, @ID+0, 'The hunt is eternal...', 14, 0, 100, 0, 0, 54513, 0, 'Illysanna Ravencrest'),
(98696, 202,         @ID+0, 'No! I can see now... betrayed...', 14, 0, 100, 0, 0, 54514, 0, 'Illysanna Ravencrest to Player'),

(98706, @GROUP_ID+0, @ID+0, 'Brothers and Sisters, the invaders come for us. Repel them! Attack!', 14, 0, 100, 0, 0, 0, 0, 'Commander Shemdah''sohn to Risen Archer'),

(98792, @GROUP_ID+0, @ID+0, 'Ha! We''ll get ''em wit'' these big rocks!', 14, 0, 100, 0, 0, 0, 0, 'Wyrmtongue Scavenger to Player'),
(98792, @GROUP_ID+1, @ID+0, 'Ahh! They coming! RUN!', 14, 0, 100, 0, 0, 0, 0, 'Wyrmtongue Scavenger to Player'),
(98792, @GROUP_ID+2, @ID+0, 'Graa.... Ooh... oooWAAAAAHHHH!!!!', 14, 0, 100, 0, 0, 0, 0, 'Wyrmtongue Scavenger to Player'),
(98792, @GROUP_ID+3, @ID+0, 'AHHH! WE SORRY! WE PROMISE!', 14, 0, 100, 0, 0, 0, 0, 'Wyrmtongue Scavenger to Player'),

(98810, @GROUP_ID+0, @ID+0, '%s becomes enraged!', 16, 0, 100, 0, 0, 0, 0, 'Wrathguard Bladelord'),

(98900, @GROUP_ID+0, @ID+0, 'Ok! We definitely got ''em this time!', 14, 0, 100, 0, 0, 0, 0, 'Wyrmtongue Trickster to Player'),

(98949, 200,         @ID+0, 'I will paint this keep with your blood!', 14, 0, 100, 0, 0, 54504, 0, 'Smashspite the Hateful'),
(98949, 201,         @ID+0, 'Tremble beneath me.', 14, 0, 100, 0, 0, 54501, 0, 'Smashspite the Hateful'),
(98949, 202,         @ID+0, 'But... I can''t... lose...', 14, 0, 100, 0, 0, 54636, 0, 'Smashspite the Hateful to Player'),

(98965, 200,         @ID+0, 'Fiends, you shall never have our world!', 14, 0, 100, 0, 0, 54536, 0, 'Kur''talos Ravencrest'),
(98965, 0,           @ID+0, 'I shall cleave you in twain!', 14, 0, 100, 0, 0, 54526, 0, 'Kur''talos Ravencrest to Player'),

(98970, @GROUP_ID+0, @ID+0, 'Burn away!', 14, 0, 100, 0, 0, 54539, 0, 'Latosius'),

(99857, @GROUP_ID+0, @ID+0, 'I... understand now. You... you must find Kur''talos. You must put a stop to this.', 12, 0, 100, 0, 0, 54558, 0, 'Lord Etheldrin Ravencrest to Player');

UPDATE `creature_template` SET `flags_extra` = 128 WHERE (entry = 103662);
