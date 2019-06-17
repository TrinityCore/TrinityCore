-- Phasing
DELETE FROM `spell_area` WHERE `spell`=70193 AND `area`=4092;
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_end`,`aura_spell`,`racemask`,`gender`,`autocast`,`quest_start_status`,`quest_end_status`) VALUES
(70193,4092,24535,0,0,0,2,1,10,0),
(70193,4092,24563,0,0,0,2,1,10,0);

-- Thalorien Dawnseekers Remains
UPDATE `creature` SET `phaseMask`=2049,`position_x`=11792.01,`position_y`=-7065.793,`position_z`=25.94043,`orientation`=5.009095 WHERE `guid`=950;
UPDATE `creature_template` SET `gossip_menu_id`=10908,`ScriptName`='npc_thalorien_dawnseeker' WHERE `entry`=37552;
DELETE FROM `creature_template_addon` WHERE `entry`=37552;
INSERT INTO `creature_template_addon` (`entry`,`bytes2`,`auras`) VALUES (37552,1,'29266');

DELETE FROM `gossip_menu` WHERE `MenuID` IN (10908,37552);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`) VALUES (10908, 15155);
DELETE FROM `gossip_menu_option` WHERE `MenuID`=10908;
INSERT INTO `gossip_menu_option` (`MenuID`,`OptionID`,`OptionIcon`,`OptionText`,`OptionBroadcastTextID`,`OptionType`,`OptionNpcFlag`,`ActionMenuID`,`ActionPoiID`,`BoxCoded`,`BoxMoney`,`BoxText`,`BoxBroadcastTextID`,`VerifiedBuild`) VALUES
(10908,0,0,"Examine the remains.",37149,1,1,0,0,0,0,"",0,0);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 15 AND `SourceGroup`= 10908;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,10908,0,0,0,9,0,24535,0,0,0,0,0,'','Show gossip option if 24535 is incomplete'),
(15,10908,0,0,1,9,0,24563,0,0,0,0,0,'','Show gossip option if 24563 is incomplete');

DELETE FROM `gameobject` WHERE `guid`=9008 AND `id`=201718;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(9008,201718,530,1,2049,11791.83,-7065.792,24.60784,0,0,0,0,1,120,255,1);

-- Thalorien Dawnseeker
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`='' WHERE `entry`=37205;
DELETE FROM `smart_scripts` WHERE `entryorguid`=37205 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(37205,0,0,0,0,0,100,0,5000,7000,15000,15000,11,67541,3,0,0,0,0,2,0,0,0,0,0,0,0,"Thalorien Dawnseeker - In Combat - Cast 'Bladestorm'"),
(37205,0,1,0,0,0,100,0,2000,2000,13000,13000,11,67542,2,0,0,0,0,2,0,0,0,0,0,0,0,"Thalorien Dawnseeker - In Combat - Cast 'Mortal Strike'"),
(37205,0,2,0,0,0,100,0,19000,19000,19000,19000,11,67716,2,0,0,0,0,1,0,0,0,0,0,0,0,"Thalorien Dawnseeker - In Combat - Cast 'Whirlwind'"),
(37205,0,3,0,0,0,100,0,1000,1000,8000,8000,11,57846,2,0,0,0,0,2,0,0,0,0,0,0,0,"Thalorien Dawnseeker - In Combat - Cast 'Heroic Strike'");

DELETE FROM `creature_text` WHERE `CreatureID`=37205;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(37205,0,0,"We must defend the Sunwell from the enemy at all costs.",12,0,100,1,0,16769,37154,0,'Thalorien Dawnseeker'),
(37205,1,0,"I am ordering you to withdraw to the Sunwell proper to help prepare the defenses.",12,0,100,25,0,16770,37155,0,'Thalorien Dawnseeker'),
(37205,2,0,"I will make my stand here and buy you as much time as I am able. Use it well and make our prince proud.",12,0,100,1,0,16771,37156,0,'Thalorien Dawnseeker'),
(37205,3,0,"It has been a great honor to fight beside you in defense of our land and our people.",12,0,100,2,0,16772,37157,0,'Thalorien Dawnseeker'),
(37205,4,0,"You, stranger... you are not one of my soldiers. Will you stay and stand with me to face the enemy?",12,0,100,0,0,16773,37158,0,'Thalorien Dawnseeker'),
(37205,5,0,"Listen well, Scourge defilers. None of you will reach the Sunwell so long as I stand!",14,0,100,53,0,16774,37159,0,'Thalorien Dawnseeker'),
(37205,6,0,"I... I wasn't meant to survive this attack.",12,0,100,6,0,16775,37196,0,'Thalorien Dawnseeker'),
(37205,7,0,"Why has this happened? Why have you come here?",12,0,100,1,0,16776,37197,0,'Thalorien Dawnseeker'),
(37205,8,0,"It's Quel'Delar! You possess the sword!",12,0,100,6,0,16777,37198,0,'Thalorien Dawnseeker'),
(37205,9,0,"I don't know how, but the blade has chosen you to be its new wielder. Take it with my blessing, and wield it against the Scourge as I once did.",12,0,100,0,0,16778,37199,0,'Thalorien Dawnseeker');

-- Summons
DELETE FROM `creature_summon_groups` WHERE `summonerId`=37552;
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`) VALUES
-- Sunwell Defender
(37552,0,1,37211,11803.44,-7076.203,25.94271,2.495821,3,39000),
(37552,0,1,37211,11805.87,-7072.606,25.54664,2.426008,3,39000),
(37552,0,1,37211,11802.07,-7077.963,26.17188,2.460914,3,39000),
(37552,0,1,37211,11800.65,-7079.646,26.29167,2.460914,3,39000),
(37552,0,1,37211,11804.64,-7074.424,25.72049,2.443461,3,39000),
(37552,0,1,37211,11801.76,-7075.037,26.12346,2.426008,3,36000),
(37552,0,1,37211,11804.1,-7071.374,25.45528,2.426008,3,36000),
(37552,0,1,37211,11800.45,-7076.835,26.12346,2.443461,3,36000),
(37552,0,1,37211,11799.08,-7078.556,26.12346,2.530727,3,36000),
(37552,0,1,37211,11802.92,-7073.224,25.64548,2.426008,3,36000),
-- Scourge Zombie
(37552,0,2,37538,11768.14,-7062.753,24.6553,6.248279,6,2000),
(37552,0,2,37538,11768.26,-7068.285,24.51112,6.265732,6,2000),
(37552,0,2,37538,11768.17,-7057.224,25.08242,6.230825,6,2000),
(37552,0,2,37538,11768.31,-7065.476,24.54401,6.230825,6,2000),
(37552,0,2,37538,11768.05,-7059.979,24.87183,6.248279,6,2000),
-- Ghoul Invader
(37552,0,3,37539,11763.44,-7071.172,24.90278,0.05235988,6,2000),
(37552,0,3,37539,11763.43,-7066.899,25.26042,0.08726646,6,2000),
(37552,0,3,37539,11763.57,-7054.385,25.70313,0.122173,6,2000),
(37552,0,3,37539,11763.31,-7062.83,25.18662,0.01745329,6,2000),
(37552,0,3,37539,11763.42,-7058.622,25.33854,0.05235988,6,2000),
-- Crypt Raider
(37552,0,4,37541,11758.34,-7062.776,25.16488,6.248279,6,2000),
(37552,0,4,37541,11757.5,-7056.007,26.01496,6.248279,6,2000),
(37552,0,4,37541,11758.1,-7069.712,25.32423,6.248279,6,2000);

-- Morlen Coldgrip
UPDATE creature_template SET `unit_flags`=256+512,`AIName`='SmartAI' WHERE `entry`=37542;
DELETE FROM `smart_scripts` WHERE `entryorguid`=37542 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(37542,0,0,0,0,0,100,0,2000,3000,9000,10000,11,50688,0,0,0,0,0,2,0,0,0,0,0,0,0,"Morlen Coldgrip - In Combat - Cast 'Plague Strike'");

DELETE FROM `creature_text` WHERE `CreatureID`=37542;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(37542,0,0,"You will fall as your lands and your city have before you. My lord will win a great victory here, and none will remember your name!",14,0,100,25,0,0,37160,0,'Morlen Coldgrip'),
(37542,1,0,"Forward!",14,0,100,25,0,0,37162,0,'Morlen Coldgrip'),
(37542,2,0,"Ghouls, slay this patheric high elf!",14,0,100,25,0,0,37301,0,'Morlen Coldgrip'),
(37542,3,0,"You will fall before the might of the Scourge. Crypt raiders, attack!",14,0,100,25,0,0,37302,0,'Morlen Coldgrip'),
(37542,4,0,"I shall kill you myself!",14,0,100,0,0,0,37167,0,'Morlen Coldgrip');

-- Scourge Zombie
UPDATE creature_template SET `unit_flags`=256+512,`AIName`='SmartAI' WHERE `entry`=37538;
DELETE FROM `smart_scripts` WHERE `entryorguid`=37538 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(37538,0,0,0,0,0,100,0,1000,2000,9000,10000,11,49861,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scourge Zombie - In Combat - Cast 'Infected Bite'");

-- Ghoul Invader
UPDATE creature_template SET `unit_flags`=256+512,`AIName`='SmartAI' WHERE `entry`=37539;
DELETE FROM `smart_scripts` WHERE `entryorguid`=37539 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(37539,0,0,0,0,0,100,0,1000,2000,9000,10000,11,38056,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scourge Zombie - In Combat - Cast 'Flesh Rip'");

-- Crypt Raider
UPDATE creature_template SET `unit_flags`=256+512,`AIName`='SmartAI' WHERE `entry`=37541;
DELETE FROM `smart_scripts` WHERE `entryorguid`=37541 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(37541,0,0,0,4,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crypt Raider - Disable Combat Movement"),
(37541,0,1,0,0,0,100,0,1000,2000,4000,5000,11,31600,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crypt Raider - In Combat - Cast 'Crypt Scarabs'");
