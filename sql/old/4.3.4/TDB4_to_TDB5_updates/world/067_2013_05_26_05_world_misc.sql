SET @OGUID := 7080;

SET @ARTHAS := 27455;
SET @MURADIN := 27480;
SET @THELZAN := 27851;
SET @ALTAR := 190332;

UPDATE `creature` SET `spawndist`=0,`MovementType`=0 WHERE `id`=@THELZAN;

DELETE FROM `gameobject` WHERE `map`=571 AND `id` IN (192066,192065,192064,190191,@ALTAR);
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES 
(@OGUID,192066,571,1,1,4816.637,-582.2271,163.1873,-1.240983,-0.5743933,0.2897787,-0.5093117,0.5715788,120,0,1),
(@OGUID+1,192065,571,1,1,4816.552,-581.2853,163.0618,1.043091,0.5583439,0.3292217,0.3740091,0.6633116,120,0,1),
(@OGUID+2,192064,571,1,1,4823.089,-581.7293,164.1632,2.408346,-0.3306689,-0.6249218,0.6858006,0.1726511,120,0,1),
(@OGUID+3,190191,571,1,1,4819.284,-583.5658,163.5637,1.343901,0,0,0.6225138,0.7826088,120,0,1),
(@OGUID+4,@ALTAR,571,1,1,4819.374,-583.699,163.5065,1.500983,0,0,0.6819983,0.7313538,120,0,1);

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@THELZAN;
UPDATE `creature_template` SET `InhabitType`=1, `AIName`='SmartAI' WHERE `entry` IN (@MURADIN,@ARTHAS);

DELETE FROM `event_scripts` WHERE `id`=18281;
INSERT INTO `event_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`x`,`y`,`z`,`o`) VALUES
(18281,0,10,@THELZAN,20000,4819.284,-583.5658,163.5637,1.343901);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=49825;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=@THELZAN;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`Comment`) VALUES
(13,1,49825,0,0,31,3,@MURADIN,0,0,0, 'Arthas Calls to Spirits targets Muradin'),
(22,2,@THELZAN,0,0,29,@MURADIN,100,0,1,0, 'SAI activates only if Muradin is not around');

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (@ARTHAS,@MURADIN,@THELZAN);
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid` IN (@ARTHAS*100,@MURADIN*100,@MURADIN*100+1,@THELZAN*100);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ARTHAS,0,0,0,38,0,100,0,0,10,0,0,80,@ARTHAS*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Prince Arthas - On dataset - Run script'),

(@MURADIN,0,0,0,38,0,100,0,0,10,0,0,80,@MURADIN*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Muradin - On dataset - Run script'),
(@MURADIN,0,1,0,8,0,100,0,49825,0,0,0,80,@MURADIN*100+1,2,0,0,0,0,1,0,0,0,0,0,0,0,'Muradin - On spellhit - Run script'),

(@THELZAN,0,0,0,54,0,100,0,0,0,0,0,3,0,17200,0,0,0,0,1,0,0,0,0,0,0,0,'Thel''zan Spell Dummy - Just summoned - Run script'),
(@THELZAN,0,1,0,54,0,100,0,0,0,0,0,80,@THELZAN*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Thel''zan Spell Dummy - Just summoned - Run script'),

(@ARTHAS*100,9,0,0,0,0,100,0,0,0,0,0,45,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Prince Arthas - Script - reset data 0'),
(@ARTHAS*100,9,1,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,4820.175,-581.226,163.6158,0,'Prince Arthas - Script - moveto'),
(@ARTHAS*100,9,2,0,0,0,100,0,8000,8000,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,'Prince Arthas - Script - say 6'),
(@ARTHAS*100,9,3,0,0,0,100,0,6000,6000,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,'Prince Arthas - Script - say 7'),
(@ARTHAS*100,9,4,0,0,0,100,0,6000,6000,0,0,11,49824,0,0,0,0,0,1,0,0,0,0,0,0,0,'Prince Arthas - Script - Spellcast Arthas Calls to Spirits'),
(@ARTHAS*100,9,5,0,0,0,100,0,10000,10000,0,0,69,0,0,0,0,0,0,8,0,0,0,4819.658,-582.5223,163.752,0,'Prince Arthas - Script - moveto'),
(@ARTHAS*100,9,6,0,0,0,100,0,0,0,0,0,71,0,7,0,0,0,0,1,0,0,0,0,0,0,0,'Prince Arthas - Script - Change weapon'),
(@ARTHAS*100,9,7,0,0,0,100,0,1000,1000,0,0,5,397,0,0,0,0,0,1,0,0,0,0,0,0,0,'Prince Arthas - Script - Emote OneShotPointNoSheathe'),
(@ARTHAS*100,9,8,0,0,0,100,0,0,0,0,0,71,0,7,33350,0,0,0,1,0,0,0,0,0,0,0,'Prince Arthas - Script - Change weapon'),
(@ARTHAS*100,9,9,0,0,0,100,0,0,0,0,0,9,0,0,0,0,0,0,20,@ALTAR,5,0,0,0,0,0,'Prince Arthas - Script - Activate Altar'),
(@ARTHAS*100,9,10,0,0,0,100,0,4000,4000,0,0,69,0,0,0,0,0,0,8,0,0,0,4814.56,-577.2604,162.2522,0,'Prince Arthas - Script - moveto'),
(@ARTHAS*100,9,11,0,0,0,100,0,3500,3500,0,0,5,15,0,0,0,0,0,1,0,0,0,0,0,0,0,'Prince Arthas - Script - Emote OneShotRoar'),
(@ARTHAS*100,9,12,0,0,0,100,0,4000,4000,0,0,53,1,@ARTHAS,0,0,0,0,1,0,0,0,0,0,0,0,'Prince Arthas - Script - Start WP movement'),

(@MURADIN*100,9,0,0,0,0,100,0,0,0,0,0,45,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Muradin - Script - reset data 0'),
(@MURADIN*100,9,1,0,0,0,100,0,500,500,0,0,69,0,0,0,0,0,0,8,0,0,0,4818.622,-582.4843,163.5883,0,'Muradin - Script - moveto'),
(@MURADIN*100,9,2,0,0,0,100,0,2000,2000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.305801,'Muradin - Script - turnto'),
(@MURADIN*100,9,3,0,0,0,100,0,1000,1000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Muradin - Script - say 2'),
(@MURADIN*100,9,4,0,0,0,100,0,500,500,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Muradin - Script - kneel'),
(@MURADIN*100,9,5,0,0,0,100,0,15000,15000,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Muradin - Script - stand'),
(@MURADIN*100,9,6,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,19,@ARTHAS,10,0,0,0,0,0,'Muradin - Script - turnto Prince Arthas'),
(@MURADIN*100,9,7,0,0,0,100,0,2000,2000,0,0,5,274,0,0,0,0,0,1,0,0,0,0,0,0,0,'Muradin - Script - Emote no'),
(@MURADIN*100,9,8,0,0,0,100,0,2500,2500,0,0,5,5,0,0,0,0,0,1,0,0,0,0,0,0,0,'Muradin - Script - Emote Exclamation'),
(@MURADIN*100,9,9,0,0,0,100,0,7000,7000,0,0,69,0,0,0,0,0,0,8,0,0,0,4817.42,-581.4944,163.2614,0,'Muradin - Script - moveto'),
(@MURADIN*100,9,10,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,19,@ARTHAS,10,0,0,0,0,0,'Muradin - Script - turnto Prince Arthas'),
(@MURADIN*100,9,11,0,0,0,100,0,1500,1500,0,0,1,5,0,0,0,0,0,19,@ARTHAS,10,0,0,0,0,0,'Muradin - Script - Prince Arthas say 5'),
(@MURADIN*100,9,12,0,0,0,100,0,5000,5000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Muradin - Script - say 3'),
(@MURADIN*100,9,13,0,0,0,100,0,0,0,0,0,45,0,10,0,0,0,0,19,@ARTHAS,10,0,0,0,0,0,'Muradin - Script - set data 0 10 on Prince Arthas'),
(@MURADIN*100,9,14,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.323254,'Muradin - Script - turnto'),

(@MURADIN*100+1,9,0,0,0,0,100,0,0,0,0,0,40,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Muradin - Script - Set sheath'),
(@MURADIN*100+1,9,1,0,0,0,100,0,0,0,0,0,18,1,1,0,0,0,0,1,0,0,0,0,0,0,0,'Muradin - Script - Set unit_flag2'),
(@MURADIN*100+1,9,2,0,0,0,100,0,13000,13000,0,0,19,1,1,0,0,0,0,1,0,0,0,0,0,0,0,'Muradin - Script - Remove unit_flag2'),
(@MURADIN*100+1,9,3,0,0,0,100,0,500,500,0,0,17,64,0,0,0,0,0,1,0,0,0,0,0,0,0,'Muradin - Script - emotestate stun'),
(@MURADIN*100+1,9,4,0,0,0,100,0,5000,5000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,'Muradin - Script - say 4'),
(@MURADIN*100+1,9,5,0,0,0,100,0,3000,3000,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,'Muradin - Script - say 5'),
(@MURADIN*100+1,9,6,0,0,0,100,0,4000,4000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Muradin - Script - emotestate none'),
(@MURADIN*100+1,9,7,0,0,0,100,0,1000,1000,0,0,11,49829,3,0,0,0,0,1,0,0,0,0,0,0,0,'Muradin - Script - Spellcast Frostmourne Cavern Quest Credit'),
(@MURADIN*100+1,9,8,0,0,0,100,0,0,0,0,0,53,1,@MURADIN,0,0,0,0,1,0,0,0,0,0,0,0,'Muradin - Script - Start WP movement'),

(@THELZAN*100,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Thel''zan Spell Dummy - Script - Say 0'),
(@THELZAN*100,9,1,0,0,0,100,0,0,0,0,0,11,33271,0,0,0,0,0,1,0,0,0,0,0,0,0,'Thel''zan Spell Dummy - Script - Spellcast Internal Shake Camera w/ rumble sound'),
(@THELZAN*100,9,2,0,0,0,100,0,7000,7000,0,0,12,@MURADIN,3,116000,0,0,0,8,0,0,0,4817.494,-579.6047,163.0956,5.102134,'Thel''zan Spell Dummy - Script - Summon Muradin'),
(@THELZAN*100,9,3,0,0,0,100,0,0,0,0,0,12,@ARTHAS,3,102000,0,0,0,8,0,0,0,4821.529,-579.8818,163.5944,4.167512,'Thel''zan Spell Dummy - Script - Summon Prince Arthas'),
(@THELZAN*100,9,4,0,0,0,100,0,0,0,0,0,9,0,0,0,0,0,0,20,@ALTAR,5,0,0,0,0,0,'Thel''zan Spell Dummy - Script - set data 0 10 on Frostmourne Altar'),
(@THELZAN*100,9,5,0,0,0,100,0,3000,3000,0,0,1,4,0,0,0,0,0,19,@ARTHAS,10,0,0,0,0,0,'Thel''zan Spell Dummy - Script - Prince Arthas Say 4'),
(@THELZAN*100,9,6,0,0,0,100,0,3000,3000,0,0,5,25,0,0,0,0,0,19,@ARTHAS,10,0,0,0,0,0,'Thel''zan Spell Dummy - Script - Prince Arthas Emote Point'),
(@THELZAN*100,9,7,0,0,0,100,0,3500,3500,0,0,45,0,10,0,0,0,0,19,@MURADIN,10,0,0,0,0,0,'Thel''zan Spell Dummy - Script - Set data 0 10 on Muradin');

DELETE FROM `waypoints` WHERE `entry` IN (@ARTHAS,@MURADIN);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ARTHAS,1,4793.066,-571.0735,160.8400, 'Prince Arthas'),
(@ARTHAS,2,4772.816,-566.8235,162.2605, 'Prince Arthas'),
(@ARTHAS,3,4759.816,-568.5735,164.2808, 'Prince Arthas'),
(@ARTHAS,4,4743.573,-564.3865,166.2362, 'Prince Arthas'),
(@MURADIN,1,4797.722,-576.3405,160.1779, 'Muradin'),
(@MURADIN,2,4770.222,-575.5905,162.9453, 'Muradin'),
(@MURADIN,3,4757.972,-575.0905,164.5265, 'Muradin'),
(@MURADIN,4,4753.972,-572.8405,165.1388, 'Muradin'),
(@MURADIN,5,4749.972,-569.5905,165.7607, 'Muradin'),
(@MURADIN,6,4748.024,-566.1866,165.7932, 'Muradin');

DELETE FROM `creature_text` WHERE `entry` IN (@ARTHAS,@MURADIN,@THELZAN);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ARTHAS,0,0, 'Captain, why are the guards not at their posts?',12,0,100,6,0,12725, 'Prince Arthas'),
(@ARTHAS,1,0, 'Uther had my troops recalled? Damn it! If my warriors abandon me, I''ll never defeat Mal''Ganis. The ships must be burned before the men reach the shore!',12,0,100,5,0,12726, 'Prince Arthas'),
(@ARTHAS,2,0, 'Burned down to their frames! No one goes home until our job here is done!',12,0,100,15,0,12727, 'Prince Arthas'),
(@ARTHAS,3,0, 'Spare me, Muradin. You weren''t there to see what Mal''Ganis did to my homeland.',12,0,100,1,0,12728, 'Prince Arthas'),
(@ARTHAS,4,0, 'Behold, Muradin, our salvation, Frostmourne.',12,0,100,1,0,12729, 'Prince Arthas'),
(@ARTHAS,5,0, 'I would gladly bear any curse to save my homeland.',12,0,100,1,0,12730, 'Prince Arthas'),
(@ARTHAS,6,0, 'Damn the men! Nothing shall prevent me from having my revenge, old friend. Not even you.',12,0,100,5,0,12731, 'Prince Arthas'),
(@ARTHAS,7,0, 'Now, I call out to the spirits of this place. I will give anything or pay any price, if only you will help me save my people.',12,0,100,396,0,12732, 'Prince Arthas'),
(@MURADIN,0,0, 'Isn''t that a bit much, lad?',12,0,100,6,0,12733, 'Muradin'),
(@MURADIN,1,0, 'You lied to your men and betrayed the mercenaries who fought for you. What''s happening to you, Arthas? Is vengeance all that''s important to you?',12,0,100,1,0,12734, 'Muradin'),
(@MURADIN,2,0, 'Hold, lad. There''s an inscription on the dais. It''s a warning. It says, "Whomsoever takes up this blade shall wield power eternal. Just as the blade rends flesh, so must power scar the spirit." Oh, I should''ve known. The blade is cursed! Let''s get the hell out of here!',12,0,100,0,0,12735, 'Muradin'),
(@MURADIN,3,0, 'Leave it be, Arthas. Forget this business and lead your men home.',12,0,100,396,0,12736, 'Muradin'),
(@MURADIN,4,0, 'O'' my head... Wh... Where am I?',12,0,100,0,0,0, 'Muradin'),
(@MURADIN,5,0, 'Who... Who am I?',12,0,100,0,0,0, 'Muradin'),
(@THELZAN,0,0, 'The walls of Frostmourne Cavern shudder and shake.',41,0,100,0,0,0, 'Thel''zan Spell Dummy');
