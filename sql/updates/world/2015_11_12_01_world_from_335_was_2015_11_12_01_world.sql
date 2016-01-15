-- creature (2 entries)
SET @CGUID = 49818;
-- gameobject (2 entries)
SET @OGUID = 5747;

-- ensure spell data for difficulties is there
DELETE FROM `spelldifficulty_dbc` WHERE `id` IN (28134,28135,28167);
INSERT INTO `spelldifficulty_dbc` (`id`,`spellid0`,`spellid1`,`spellid2`,`spellid3`) VALUES
(28134,54529,28134,0,0), -- Stalagg - Power Surge (yes, these are supposed to be backwards)
(28135,28135,54528,0,0), -- Feugen - Static Field
(28167,28167,54531,0,0); -- Thaddius - Chain Lightning

-- magnetic pull
DELETE FROM `spell_scripts` WHERE `id`=54517;
DELETE FROM `spell_script_names` WHERE `spell_id`=54517;
INSERT INTO `spell_script_names` (`spell_id`,`scriptname`) VALUES (54517,"spell_thaddius_magnetic_pull");

-- thaddius
UPDATE `creature_template` set `unit_flags`=64 WHERE `entry`=15928;
UPDATE `creature` set `MovementType`=0 WHERE `id`=15928;

-- tesla coil
UPDATE `creature_template` set `inhabittype`=4,`unit_flags`=33554688,`unit_flags2`=2048,`ScriptName`="npc_tesla",`MovementType`=0,`flags_extra`=0 WHERE `entry`=16218;
DELETE FROM `creature_addon` WHERE `guid` IN (select `guid` from `creature` WHERE `id` = 16218);
DELETE FROM `creature` WHERE `id` = 16218;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`movementtype`,`VerifiedBuild`) VALUES
(@CGUID+0,16218,533,3,1,3527.807,-2952.382,319.3258,3.909538,0,0,0,0),
(@CGUID+1,16218,533,3,1,3487.762,-2911.198,319.4061,3.909538,0,0,0,0);
INSERT INTO `creature_addon` (`guid`,`auras`) VALUES
(@CGUID+0,28109),
(@CGUID+1,28097);

-- tesla coil search trigger range (index 30 is 500 yards)
UPDATE `spell_dbc` set `AttributesEx2`=0 WHERE `Id` IN (28098,28110);
DELETE FROM `spelleffect_dbc` WHERE `Id` IN (28098,28110);
INSERT INTO `spelleffect_dbc` (`Id`,`EffectRadiusIndex`,`EffectSpellId`,`EffectIndex`) VALUES
(28098,30,0,0),
(28110,30,0,0);

-- tesla coil search ignores LoS
DELETE FROM `disables` WHERE `sourceType`=0 AND `entry` IN (28096,28098,28110,28111);
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`comment`) VALUES
(0,28098,64,"Stalagg Tesla Periodic - Ignore LoS"),
(0,28096,64,"Stalagg Tesla Visual - Ignore LoS"),
(0,28110,64,"Feugen Tesla Periodic - Ignore LoS"),
(0,28111,64,"Feugen Tesla Visual - Ignore LoS");
-- tesla coil shock visual needs implicit target
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (28096,28111,28159);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`Comment`) VALUES
(13,1,28096,0,0,31,0,3,15929,0,0,"Stalagg Chain Visual - Target Stalagg"),
(13,1,28111,0,0,31,0,3,15930,0,0,"Feugen Chain Visual - Target Feugen"),
(13,1,28159,0,0,31,0,3,15928,0,0,"Thaddius Shock Visual - Target Thaddius");

-- tesla coil visual
DELETE FROM `gameobject` WHERE `id` IN (181477,181478);
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`VerifiedBuild`) VALUES
(@OGUID+0,181477,533,3,1,3527.94,-2952.263,318.8983,3.141593,0,0,-1,0,0,0),
(@OGUID+1,181478,533,3,1,3487.324,-2911.383,318.8983,3.141593,0,0,-1,0,0,0);

-- polarity shift scripts
DELETE FROM `spell_scripts` WHERE `id` IN (28059,28062,28084,28085,28089,29659,29660);
DELETE FROM `spell_script_names` WHERE `spell_id` IN (28059,28062,28084,28085,28089,29659,29660);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(28062,"spell_thaddius_polarity_charge"),
(28085,"spell_thaddius_polarity_charge"),
(28089,"spell_thaddius_polarity_shift");

-- shocking! achievement
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (7604,7605);
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`) VALUES
(7604,11,0,0,"achievement_thaddius_shocking"),
(7604,12,0,0,""),
(7605,11,0,0,"achievement_thaddius_shocking"),
(7605,12,1,0,"");

-- move 20% trigger rate for "killed target" texts from script to DB
UPDATE `creature_text` set `probability`=20 WHERE `entry`=15929 AND `groupid`=1;
UPDATE `creature_text` set `probability`=20 WHERE `entry`=15930 AND `groupid`=1;
UPDATE `creature_text` set `probability`=20 WHERE `entry`=15928 AND `groupid`=2;

-- add missing creature_text entries for thaddius, feugen, stalagg and tesla coil
DELETE FROM `creature_text` WHERE `entry`=15928 AND `groupid`=6;
DELETE FROM `creature_text` WHERE `entry` IN (15929,15930) AND `groupid` IN (3,4);
DELETE FROM `creature_text` WHERE `entry`=16218;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`probability`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(15928,6,0,"The polarity has shifted!",41,100,32324,3,"Thaddius EMOTE_POLARITY_SHIFTED"),
(15929,3,0,"%s dies.",16,100,10453,3,"Stalagg EMOTE_FEIGN_DEATH"),
(15930,3,0,"%s dies.",16,100,10453,3,"Feugen EMOTE_FEIGN_DEATH"),
(15929,4,0,"%s is jolted back to life!",16,100,12155,3,"Stalagg EMOTE_FEIGN_REVIVE"),
(15930,4,0,"%s is jolted back to life!",16,100,12155,3,"Feugen EMOTE_FEIGN_REVIVE"),
(16218,0,0,"%s loses its link!",41,100,12156,3,"Tesla Coil EMOTE_TESLA_LINK_BREAKS"),
(16218,1,0,"%s overloads!",41,100,12178,3,"Tesla Coil EMOTE_TESLA_OVERLOAD");


-- trigger when entering thaddius' room
DELETE FROM `areatrigger_scripts` WHERE `entry`=4113;
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(4113,"at_thaddius_entrance");
