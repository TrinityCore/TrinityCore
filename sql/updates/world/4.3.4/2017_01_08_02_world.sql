--
-- General Umbriss
UPDATE creature_template SET difficulty_entry_1=48337 WHERE entry=39625;
UPDATE creature_template SET minlevel=86,maxlevel=86,EXP=3,faction=1771,speed_walk=0.888888,speed_run=1.42857,unit_flags=32832,mechanic_immune_mask=8388624 WHERE entry=48337;

DELETE FROM creature_text WHERE entry=39625;
INSERT INTO creature_text VALUES
(39625,0,0,'A million more await my orders. What chance you do have?',14,0,100,0,0,18530,0,0,'SAY_AGGRO'),
(39625,1,0,'Reinforce the front! We are being invaded!',14,0,100,0,0,18536,0,0,'SAY_BOMBING'),
(39625,1,1,'Cover the rear! Alexstrazas brood decimate our rank!',14,0,100,0,0,18537, 0,0, 'SAY_BOMBING'),
(39625,2,0,'Attack you cowardly vermin!',14,0,100,0,0,18535,0,0,'SAY_SUMMON'),
(39625,3,0,'Messy...',14,0,100,0,0,18532,0,0,'SAY_KILL'),
(39625,3,1,'Vermin, your dinner awaits!',14,0,100,0,0,18531,0,0,'SAY_KILL'),
(39625,4,0,'Death, is my only option...',14,0,100,0,0,18531,0,0,'SAY_DEAD'),
(39625,5,0,'|TInterface\Icons\ability_warrior_charge.blp:20|tGeneral Umbriss sets his eyes on |cFFFF0000$n|r and begins to cast |cFFFF0000|Hspell:74670|h[Blitz]|h|r!',41,0,100,0,0,18533,0,0,'EMOTE_BLITZ'),
(39625,6,0,'|TInterface\Icons\spell_nature_earthquake.blp:20|tGeneral Umbriss begins to cast |cFFFF0000|Hspell:74634|h[Ground Siege]|h|r!',41,0,100,0,0,18534,0,0,'EMOTE_GROUND_SIEGE');

-- Ground Siege Stalker
UPDATE creature_template SET flags_extra=130 WHERE entry=40030;

-- Blitz Stalker
UPDATE creature_template SET flags_extra=128 WHERE entry=40040; 

-- Trogg Dweller - Summoned by Boss
UPDATE creature_template SET difficulty_entry_1=48348 WHERE entry=45467;
UPDATE creature_template SET minlevel=84,maxlevel=84,EXP=3,faction=16,speed_walk=2,speed_run=1.42857,mechanic_immune_mask=8388624 WHERE entry=48348;

SET @ENTRY := 45467;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,4500,12000,14000,11,76507,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Claw Puncture');

-- Malignant Trogg  -- Summoned By Boss
UPDATE creature_template SET difficulty_entry_1=48350 WHERE entry=39984;
UPDATE creature_template SET minlevel=84,maxlevel=84,EXP=3,faction=16,speed_walk=2.8,speed_run=1,mechanic_immune_mask=8388624 WHERE entry=48350;

-- Forgemaster Throngus
UPDATE creature_template SET difficulty_entry_1=48702 WHERE entry=40177;
UPDATE creature_template SET minlevel=86,maxlevel=86,EXP=3,faction=1771,speed_walk=2,speed_run=1.42857,unit_flags=64,unit_flags2=67584,VehicleId=733,mechanic_immune_mask=8388624, flags_extra=1 WHERE entry=48702;

DELETE FROM creature_text WHERE entry=40177;
INSERT INTO creature_text VALUES
(40177,0,0,'NO! Throngus get whipped again if he no finish!',14,0,100,0,0,18943,0,0,'SAY_AGGRO'),
(40177,1,0,'Oh, this gonna HURT!',14,0,100,0,0,18949,0,0,'SAY_MACE'),
(40177,2,0,'You not get through defenses!',14,0,100,0,0,18947,0,0,'SAY_SHIELD'),
(40177,3,0,'Throngus SLICE you up!',14,0,100,0,0,18948,0,0,'SAY_SWORDS'),
(40177,4,0,'You break easy!',14,0,100,0,0,18945,0,0,'SAY_KILL'),
(40177,4,1,'Throngus use your corpse on body. Somewhere...',14,0,100,0,0,18944,0,0,'SAY_KILL'),
(40177,5,0,'Death... Good choice. Not best choice maybe, but better than fail and live.',14,0,100,0,0,18946,0,0,'SAY_DEAD'),
(40177,6,0,'|TInterface\Icons\ability_dualwield.blp:20|t%s equips his |cFFFF0000Swords|r and gains |cFFFF0000|Hspell:74981|h[Dual Blades]|h|r!',41,0,100,0,0,0,0,0,'EMOTE_SWORDS'),
(40177,7,0,'|TInterface\Icons\inv_mace_15.blp:20|t%s equips his |cFFFF0000Mace|r and is |cFFFF0000|Hspell:75007|h[Encumbered]|h|r!',41,0,100,0,0,0,0,0,'EMOTE_MACE'),
(40177,8,0,'|TInterface\Icons\inv_shield_76.blp:20|t%s equips his |cFFFF0000Shield|r and gains |cFFFF0000|Hspell:74908|h[Personal Phalanx]|h|r!',41,0,100,0,0,0,0,0,'EMOTE_SHIELD');

-- Lava Patch
DELETE FROM creature_template_addon WHERE entry=48711;
INSERT INTO creature_template_addon VALUES
(48711,0,0,0,0,0,0,0,0,'90752');

-- Cave In 
DELETE FROM creature_template_addon WHERE entry=40228;
INSERT INTO creature_template_addon VALUES
(40228,0,0,0,0,0,0,0,0,'74987');

-- Drahga Shadowburner
UPDATE creature_template SET difficulty_entry_1=48784 WHERE entry=40319;
UPDATE creature_template SET minlevel=86,maxlevel=86,EXP=3,faction=2146,unit_class=2,unit_flags=32832,VehicleId=733,mechanic_immune_mask=8388624, flags_extra=1 WHERE entry=48784;

DELETE FROM creature_text WHERE entry=40319;
INSERT INTO creature_text VALUES
(40319,0,0,'I will burn you from the inside out!',14,0,100,0,0,18610,0,0,'SAY_AGGRO'),
(40319,1,0,'|TInterface\Icons\spell_fire_elemental_totem.blp:20|t%s Summons an |cFFFF6F00|Hspell:75218|h[Invocation of Flame]|h|r!',41,0,100,0,0,0,0,0,'EMOTE_SUMMON'),
(40319,2,0,'INCINERATE THEM, MINIONS!',14,0,100,0,0,18616,0,0,'SAY_SUMMON'),
(40319,2,1,'BY FIRE BE... BURNED!',14,0,100,0,0,18619,0,0,'SAY_SUMMON'),
(40319,3,0,'Dragon, you will do as I command! Catch me!',14,0,100,0,0,18621,0,0,'SAY_JUMP_DOWN'),
(40319,4,0,'You should have come better prepared!',14,0,100,0,0,18945,0,0,'SAY_KILL'),
(40319,5,1,'Valiona, finish them! Avenge me!',14,0,100,0,0,18944,0,0,'SAY_DEAD');

-- Valiona
UPDATE creature_template SET difficulty_entry_1=48801 WHERE entry=40320;
UPDATE creature_template SET minlevel=86,maxlevel=86,EXP=3,faction=2146,speed_run=1.42857,unit_flags=32832,VehicleId=737,mechanic_immune_mask=8388624, flags_extra=1 WHERE entry=48801;

DELETE FROM creature_text WHERE entry=40320;
INSERT INTO creature_text VALUES
(40320,0,0,'If they do not kill you, I will do it myself!',14,0,100,0,0,18523,0,0,'SAY_VALIONA'),
(40320,1,0,'|TInterface\Icons\spell_fire_twilightflamebreath.blp:20|t%s begins to cast |cFFFF0000|Hspell:90949|h[Devouring Flames]|h|r!',41,0,100,0,0,0,0,0,'EMOTE_DEVOURING_FLAMES'),
(40320,2,0,'I will not die for you, Drahga.',14,0,100,0,0,18524,0,0,'SAY_FLY_AWAY');

-- Invoked Flaming Spirit
UPDATE creature_template SET difficulty_entry_1=48785 WHERE entry=40357;
UPDATE creature_template SET minlevel=84,maxlevel=84,EXP=3,faction=14,mechanic_immune_mask=8388624 WHERE entry=48785;

-- Erudax
UPDATE creature_template SET difficulty_entry_1=48822 WHERE entry=40484;
UPDATE creature_template SET minlevel=87,maxlevel=87,EXP=3,faction=16,speed_run=1.28571,unit_flags=64,unit_flags2=134219776,mechanic_immune_mask=8388624, flags_extra=1 WHERE entry=48822;

DELETE FROM creature_text WHERE entry=40484;
INSERT INTO creature_text VALUES
(40484,0,0,'The darkest days are still ahead!',14,0,100,0,0,18638,0,0,'SAY_AGGRO'),
(40484,1,0,'Come, suffering... Enter, chaos!',14,0,100,0,0,18646,0,0,'SAY_SUMMON'),
(40484,2,0,'F\'lakh ghet! The shadows hunger cannot be sated!',14,0,100,0,0,18644,0,0,'SAY_SHADOW_GALE'),
(40484,3,0,'Ywaq maq oou; ywaq maq ssaggh. Yawq ma shg fhn.',14,0,100,0,0,18641,0,0,'SAY_DEATH'),
(40484,4,0,'More flesh for the offering!',14,0,100,0,0,18640,0,0,'SAY_KILL'),
(40484,4,1,'Erudax cackles maniacally.',16,0,100,0,0,18639,0,0,'SAY_KILL'),
(40484,5,0,'|TInterface\Icons\spell_shadow_shadowfury.blp:20|t%s begins to cast |cFFA043E7|Hspell:75694|h[Shadow Gale]|h|r!',41,0,100,0,0,0,0,0,'SAY_SHADOW_GALE_ANNOUNCE'),
(40484,6,0,'|t%s summons a|cffff0000|h [Twilight Corruption]|r!',41,0,100,0,0,0,0,0,'SAY_TWILIGHT_CORRUPTION_ANNOUNCE'),
(40484,7,0,'|TInterface\Icons\spell_shadow_sacrificialshield.blp:20|t%s begins to cast |cFF006EFD|Hspell:75809|h[Shield of Nightmares]|h|r on the |cFF006EFDFaceless Corruptor!|r',41,0,100,0,0,0,0,0,'EMOTE_SHIELD_OF_NIGHTMARE');

DELETE FROM conditions WHERE SourceTypeOrReferenceId=13 AND SourceGroup=1 AND SourceEntry IN (91086,75664);
INSERT INTO conditions VALUES
(13,1,91086,0,0,31,0,3,40567,0,0,0,0,'','40567 - Immune to 91086'),
(13,1,75664,0,0,31,0,3,40567,0,0,0,0,'','40567 - Immune to 75664');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=75809;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `NegativeCondition`, `Comment`) VALUES
(13,1,75809,0,31,3,40600,0,'Spell 75071 should target 40255'),
(13,1,75809,1,31,3,48844,0,'Spell 75071 should target 40255');

-- Faceless Corruptor (Boss Add First)

UPDATE creature_template SET difficulty_entry_1=48828 WHERE entry=40600;
UPDATE creature_template SET minlevel=84,maxlevel=84,EXP=3,faction=16,mechanic_immune_mask=8388624 WHERE entry=48828;

-- Faceless Corruptor (Boss Second )
UPDATE creature_template SET difficulty_entry_1=48845 WHERE entry=48844;
UPDATE creature_template SET minlevel=84,maxlevel=84,EXP=3,faction=16,mechanic_immune_mask=8388624 WHERE entry=48845;

-- Shadow Gale Trigger
UPDATE creature_template SET flags_extra=130 WHERE entry=40567;

-- Drake Part
DELETE FROM creature WHERE id =42571;

DELETE FROM creature_text WHERE entry = 39294;
INSERT INTO `creature_text` VALUES
(39294, 0, 0, 'Once we are all free, we shall fly with you through Grim Batol!', 12, 0, 100, 0, 0, 0, 0,0,''),
(39294, 1, 0, 'Please champions, rescue my brethran from the Twilight\'s Hammer!', 12, 0, 100, 0, 0, 0, 0,0,''),
(39294, 2, 0, 'Please heroes, help my brothers and we shall assist you!', 12, 0, 100, 0, 0, 0,0,0, ''),
(39294, 3, 0, 'Please! Free the others from their Nets!', 12, 0, 100, 0, 0, 0,0,0, ''),
(39294, 4, 0, 'Thank you for rescuing me, now please aid the rest of my brood!', 12, 0, 100, 0, 0, 0,0,0, ''),
(39294, 5, 0, 'The Twilight Dragonkin must be stopped! Rescue the other Red Dragonflight and we shall assist you!', 12, 0, 100, 0, 0, 0,0,0, ''),
(39294, 6, 0, 'Welcome Friend.  Let\'s ride through Grim Batol and strike a blow against Deathwing that he won\'t soon forget!', 15, 0, 100, 0, 0, 0, 0,0,''),
(39294, 7, 0, '|TInterface\Icons\ability_mage_firestarter.blp:20|tUse |cFFFF0000|Hspell:74040|h[Engulfing Flames]|h|r to destroy the Twilight\'s Hammer!', 42, 0, 100, 0, 0, 0, 0,0,'EMOTE_DRAGONS');

DELETE FROM npc_spellclick_spells WHERE npc_entry = 39294;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES 
(39294, 80343, 1, 0);

UPDATE creature_template SET IconName='vehicleCursor', spell1=74039, InhabitType=4 WHERE entry=39294;

-- Trash

-- Trogg Dweller
UPDATE creature_template SET difficulty_entry_1=48509 WHERE entry=39450;
UPDATE creature_template SET minlevel=84,maxlevel=84,EXP=3,faction=16,speed_run=1.42857,mechanic_immune_mask=8388624 WHERE entry=48509;

SET @ENTRY := 39450;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,4500,12000,14000,11,76507,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Claw Puncture');


-- Azureborne Guardian 
UPDATE creature_template SET difficulty_entry_1=48661 WHERE entry=39854;
UPDATE creature_template SET minlevel=84,maxlevel=84,EXP=3,faction=1771,speed_walk=0.888888,unit_flags=64,unit_flags2=33554432,mechanic_immune_mask=8388624 WHERE entry=48661;

SET @ENTRY := 39854;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,3000,12000,13000,11,76394,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Curse of the Azureborne'),
(@ENTRY,0,1,0,0,0,100,6,5000,5000,15000,15000,11,76378,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Infusion');

UPDATE creature_template SET difficulty_entry_1=40294 WHERE entry=48862;
UPDATE creature_template SET minlevel=84,maxlevel=84,EXP=3,faction=1771,mechanic_immune_mask=8388624 WHERE entry=40294;

-- Azureborne Seer 
UPDATE creature_template SET difficulty_entry_1=48745 WHERE entry=39855;
UPDATE creature_template SET minlevel=84,maxlevel=84,EXP=3,faction=1771,speed_walk=0.888888,unit_class=8,unit_flags=64,unit_flags2=33554432,mechanic_immune_mask=8388624 WHERE entry=48745;

SET @ENTRY := 39855;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,4500,9000,11000,11,76369,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Twilight Bolt'),
(@ENTRY,0,1,0,2,0,100,7,0,20,0,0,11,76370,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Warped Twilight at 20% HP'),
(@ENTRY,0,2,0,2,0,100,7,0,40,0,0,11,76340,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Twisted Arcane at 40% HP');

UPDATE creature_template SET difficulty_entry_1=48746 WHERE entry=40291;
UPDATE creature_template SET minlevel=84,maxlevel=84,EXP=3,faction=1771,speed_walk=0.888888,unit_class=8,unit_flags=64,unit_flags2=33554432,mechanic_immune_mask=8388624 WHERE entry=48746;


-- Crimsonborne Guardian 
UPDATE creature_template SET difficulty_entry_1=48654 WHERE entry=39381;
UPDATE creature_template SET minlevel=84,maxlevel=84,EXP=3,faction=1771,speed_walk=0.888888,unit_flags=64,unit_flags2=33554432,mechanic_immune_mask=8388624 WHERE entry=48654;

SET @ENTRY := 39381;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,11,76404,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crimson Charge on Aggro'),
(@ENTRY,0,1,0,0,0,100,6,4000,6000,14000,16000,11,76409,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crimson Shockwave');

UPDATE creature_template SET difficulty_entry_1=48657 WHERE entry=40293;
UPDATE creature_template SET minlevel=84,maxlevel=84,EXP=3,faction=1771,mechanic_immune_mask=8388624 WHERE entry=48657;

-- Twilight Earthshaper 
UPDATE creature_template SET difficulty_entry_1=48595 WHERE entry=39890;
UPDATE creature_template SET minlevel=84,maxlevel=84,EXP=3,faction=1771,unit_class=8,unit_flags=32832,unit_flags2=0,mechanic_immune_mask=8388624 WHERE entry=48595;

SET @ENTRY := 39890;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,4500,12000,12000,11,76603,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Earth Spike'),
(@ENTRY,0,1,0,2,0,100,6,0,55,30000,32000,11,76596,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stone Skin at 55% HP'),
(@ENTRY,0,2,0,1,0,100,7,3000,5000,0,0,11,74552,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Rock Elemental on Spawn');

-- Twilight Armsmaster
UPDATE creature_template SET difficulty_entry_1=48611 WHERE entry=41073;
UPDATE creature_template SET minlevel=84,maxlevel=84,EXP=3,faction=1771,unit_flags=64,unit_flags2=0,mechanic_immune_mask=8388624 WHERE entry=48611;

SET @ENTRY := 41073;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,5,8000,11000,11,76727,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Strike on Close'),
(@ENTRY,0,1,0,0,0,100,6,5000,7000,15000,18000,11,76729,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flurry of Blows');

UPDATE creature_template SET difficulty_entry_1=48610 WHERE entry=40306;
UPDATE creature_template SET minlevel=84,maxlevel=84,EXP=3,faction=1771,unit_flags=64,unit_flags2=0,mechanic_immune_mask=8388624 WHERE entry=48610;


-- Twilight Stormbreaker 
UPDATE creature_template SET difficulty_entry_1=48597 WHERE entry=39962;
UPDATE creature_template SET minlevel=84,maxlevel=84,EXP=3,faction=1771,unit_class=8,unit_flags=32832,unit_flags2=0,mechanic_immune_mask=8388624 WHERE entry=48597;

SET @ENTRY := 39962;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,0,0,3400,4700,11,76720,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Water Bolt'),
(@ENTRY,0,1,0,2,0,100,6,0,55,20000,25000,11,90522,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Water Shell at 55% HP'),
(@ENTRY,0,2,0,1,0,100,7,3000,5000,0,0,11,74561,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Water Spirit on Spawn');

-- Twilight Enforcer
UPDATE creature_template SET difficulty_entry_1=48666 WHERE entry=39956;
UPDATE creature_template SET minlevel=84,maxlevel=84,EXP=3,faction=1771,unit_flags=64,unit_flags2=33554432,mechanic_immune_mask=8388624 WHERE entry=48666;

SET @ENTRY := 39956;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,5,15000,16000,11,76411,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Meat Grinder on Close');
--
