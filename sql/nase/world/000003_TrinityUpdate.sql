-- -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 4149: Not on my watch / [NPC] Lump
UPDATE `smart_scripts` SET `event_param2`=3 WHERE `entryorguid`=18351 AND `event_type`=62;
UPDATE `smart_scripts` SET `event_type`=25 WHERE `entryorguid`=18351 AND `id`=0;
UPDATE `creature_template` SET `unit_flags`=528 WHERE `entry`=18351;
-- -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 4206: Eliminate the Competition
SET @NPC_SIGRID        := 30086; -- Sigrid Iceborn
SET @MENUID_SIGRID     := 9870;
SET @NPC_EFREM         := 30081; -- Efrem the Faithful
SET @MENUID_EFREM      := 9869;
SET @NPC_ONUZUN        := 30180; -- Onu'zun
SET @MENUID_ONUZUN     := 9878;
SET @NPC_TINKY         := 30162; -- Tinky Wickwhistle
SET @MENUID_TINKY      := 9875;
UPDATE `creature_template` SET `npcflag`=1,`unit_flags`=33024,`AIName`='SmartAI' WHERE `entry` IN (@NPC_SIGRID,@NPC_EFREM,@NPC_ONUZUN,@NPC_TINKY);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (@NPC_SIGRID,@NPC_EFREM,@NPC_ONUZUN,@NPC_TINKY);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Sigrid Iceborn
(@NPC_SIGRID,0,0,0,4,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 1 on Aggro'),
(@NPC_SIGRID,0,1,0,4,1,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving on Aggro'),
(@NPC_SIGRID,0,2,0,4,1,100,1,0,0,0,0,11,61168,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw on Aggro'),
(@NPC_SIGRID,0,3,0,9,1,100,0,5,30,3500,4100,11,61168,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw'),
(@NPC_SIGRID,0,4,0,9,1,100,0,30,100,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Moving when not in Throw Range'),
(@NPC_SIGRID,0,5,0,9,1,100,0,9,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving at 15 Yards'),
(@NPC_SIGRID,0,6,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Moving when not in Throw Range'),
(@NPC_SIGRID,0,7,0,9,1,100,0,5,30,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving when in Throw Range'),
(@NPC_SIGRID,0,8,0,0,1,100,0,3000,7000,13000,16700,11,61164,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Impale'),
(@NPC_SIGRID,0,9,0,13,1,100,0,12000,18000,0,0,11,57635,0,0,0,0,0,6,1,0,0,0,0,0,0,'Cast Disengage on Target Spellcast'),
(@NPC_SIGRID,0,10,0,1,0,100,0,500,1000,600000,600000,11,61165,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frostbite Weapon on Spawn'),
(@NPC_SIGRID,0,11,12,62,0,100,0,@MENUID_SIGRID,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'On gossip select - Close gossip'),
(@NPC_SIGRID,0,12,13,61,0,100,0,0,0,0,0,42,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Set invincible'),
(@NPC_SIGRID,0,13,14,61,0,100,0,0,0,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Remove flags 256+512'),
(@NPC_SIGRID,0,14,15,61,0,100,0,0,0,0,0,2,14,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Set faction hostile'),
(@NPC_SIGRID,0,15,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Talk'),
(@NPC_SIGRID,0,16,17,2,0,100,0,0,1,0,0,33,@NPC_SIGRID,0,0,0,0,0,7,0,0,0,0,0,0,0,'On 1 hp - Give killcredit'),
(@NPC_SIGRID,0,17,18,61,0,100,0,0,0,0,0,2,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Restore faction'),
(@NPC_SIGRID,0,18,19,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Talk'),
(@NPC_SIGRID,0,19,0,61,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Evade'),
-- Efrem the Faithful
(@NPC_EFREM,0,0,0,1,0,100,0,500,1000,600000,600000,11,17232,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Devotion Aura on Spawn'),
(@NPC_EFREM,0,1,0,2,0,100,1,0,50,0,0,11,17233,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Lay on Hands at 50% HP'),
(@NPC_EFREM,0,2,0,0,0,100,0,3300,5500,16000,17600,11,14518,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crusader Strike'),
(@NPC_EFREM,0,3,0,0,0,80,0,9900,9900,21000,32000,11,13005,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hammer of Justice'),
(@NPC_EFREM,0,4,5,62,0,100,0,@MENUID_EFREM,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'On gossip select - Close gossip'),
(@NPC_EFREM,0,5,6,61,0,100,0,0,0,0,0,42,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Set invincible'),
(@NPC_EFREM,0,6,7,61,0,100,0,0,0,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Remove flags 256+512'),
(@NPC_EFREM,0,7,8,61,0,100,0,0,0,0,0,2,14,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Set faction hostile'),
(@NPC_EFREM,0,8,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Talk'),
(@NPC_EFREM,0,9,10,2,0,100,0,0,1,0,0,33,@NPC_EFREM,0,0,0,0,0,7,0,0,0,0,0,0,0,'On 1 hp - Give killcredit'),
(@NPC_EFREM,0,10,11,61,0,100,0,0,0,0,0,2,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Restore faction'),
(@NPC_EFREM,0,11,0,61,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Evade'),
-- Onu'zun
(@NPC_ONUZUN,0,0,0,4,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 1 on Aggro'),
(@NPC_ONUZUN,0,1,0,4,1,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving on Aggro'),
(@NPC_ONUZUN,0,2,0,4,1,100,1,0,0,0,0,11,15242,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt on Aggro'),
(@NPC_ONUZUN,0,3,0,9,1,100,0,0,40,3400,4700,11,15242,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@NPC_ONUZUN,0,4,0,9,1,100,0,40,100,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Moving when not in bolt Range'),
(@NPC_ONUZUN,0,5,0,9,1,100,0,10,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving at 15 Yards'),
(@NPC_ONUZUN,0,6,0,9,1,100,0,0,40,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving when in bolt Range'),
(@NPC_ONUZUN,0,7,0,3,1,100,0,0,15,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 2 at 15% Mana'),
(@NPC_ONUZUN,0,8,0,3,2,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Moving at 15% Mana'),
(@NPC_ONUZUN,0,9,0,3,2,100,0,30,100,100,100,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 1 When Mana is above 30%'),
(@NPC_ONUZUN,0,10,0,1,0,100,0,500,1000,600000,600000,11,18100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Armor on Spawn'),
(@NPC_ONUZUN,0,11,0,13,0,100,0,12000,18000,0,0,11,15122,0,0,0,0,0,6,1,0,0,0,0,0,0,'Cast Counterspell on Target Spellcast'),
(@NPC_ONUZUN,0,12,0,0,1,100,0,5000,5000,14500,17800,11,15244,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cone of Cold'),
(@NPC_ONUZUN,0,13,14,62,0,100,0,@MENUID_ONUZUN,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'On gossip select - Close gossip'),
(@NPC_ONUZUN,0,14,15,61,0,100,0,0,0,0,0,42,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Set invincible'),
(@NPC_ONUZUN,0,15,16,61,0,100,0,0,0,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Remove flags 256+512'),
(@NPC_ONUZUN,0,16,17,61,0,100,0,0,0,0,0,2,14,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Set faction hostile'),
(@NPC_ONUZUN,0,17,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Talk'),
(@NPC_ONUZUN,0,18,19,2,0,100,0,0,1,0,0,33,@NPC_ONUZUN,0,0,0,0,0,7,0,0,0,0,0,0,0,'On 1 hp - Give killcredit'),
(@NPC_ONUZUN,0,19,20,61,0,100,0,0,0,0,0,2,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Restore faction'),
(@NPC_ONUZUN,0,20,0,61,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Evade'),
-- Tinky Wickwhistle
(@NPC_TINKY,0,0,0,0,0,100,0,7000,8000,15600,17800,11,61552,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wrench Strike'),
(@NPC_TINKY,0,1,0,0,0,100,0,13000,14000,21300,23400,11,37666,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Heavy Dynamite'),
(@NPC_TINKY,0,2,3,62,0,100,0,@MENUID_TINKY,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'On gossip select - Close gossip'),
(@NPC_TINKY,0,3,4,61,0,100,0,0,0,0,0,42,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Set invincible'),
(@NPC_TINKY,0,4,5,61,0,100,0,0,0,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Remove flags 256+512'),
(@NPC_TINKY,0,5,6,61,0,100,0,0,0,0,0,2,14,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Set faction hostile'),
(@NPC_TINKY,0,6,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Talk'),
(@NPC_TINKY,0,7,8,2,0,100,0,0,1,0,0,33,@NPC_TINKY,0,0,0,0,0,7,0,0,0,0,0,0,0,'On 1 hp - Give killcredit'),
(@NPC_TINKY,0,8,9,61,0,100,0,0,0,0,0,2,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Restore faction'),
(@NPC_TINKY,0,9,10,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Talk'),
(@NPC_TINKY,0,10,0,61,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Evade');
DELETE FROM `creature_text` WHERE `entry` IN (@NPC_SIGRID,@NPC_EFREM,@NPC_ONUZUN,@NPC_TINKY);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@NPC_SIGRID,0,0,'Taste my steel, little $g boy : girl;!',12,0,100,0,0,0,'say'),
(@NPC_SIGRID,1,0,'You fight well, little one. I am bested for now. We will meet again I assure you. When we do I will be better prepared!',12,0,100,66,0,0,'say'),
(@NPC_EFREM,0,0,'You dare to touch ME?! You won''t keep me from proving myself to the Lich King!',12,0,100,0,0,0,'say'),
(@NPC_ONUZUN,0,0,'Onu''zun gonna kill you dead!',12,0,100,0,0,0,'say'),
(@NPC_TINKY,0,0,'Grrrrrrrr! I''ll kneecap ya!',12,0,100,0,0,0,'say'),
(@NPC_TINKY,1,0,'WHEE!!!',12,0,100,0,0,0,'say');
-- -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 4252: Bringing Down the Iron Thane
SET @Thane :=    26405;
SET @Anvil :=    26406;
SET @Guid :=     43467;
SET @Script := 2640600;
SET @Golem :=    29005;
-- Add missing spawns
DELETE FROM `creature` WHERE `id`=@Thane;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`)  VALUES
(@Guid,@Thane ,571,1,1,0,1419,3317.76,-5112.08,300.462,1.78269,300,0,0,12762,3561,0,0,0,0); -- spawn NPC if there isn't, GUID is random
-- SAI for Thane
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@Thane;
UPDATE `creature_template` SET `AIName`='SmartAI',`faction_A`=1954,`faction_H`=1954 WHERE `entry`=@Thane ;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@Thane,@Script);
INSERT INTO `smart_scripts` VALUES
(@Thane,0,0,0,38,0,100,0,0,1,0,0,80,@Script,2,0,0,0,0,1,0,0,0,0,0,0,0,'Thane - On data set 0 1 - Run timed action list'),
(@Thane,0,1,0,1,0,100,0,0,0,20000,20000,75,47922,0,0,0,0,0,1,0,0,0,0,0,0,0,'Iron Thane - OOC - Add Aura'),
(@Thane,0,2,0,0,0,100,0,5000,9000,10000,14000,11,61575,0,0,0,0,0,2,0,0,0,0,0,0,0,'Iron Thane - IC - Cast Furyhammer'),
(@Thane,0,3,0,6,0,100,0,0,0,0,0,28,47923,0,0,0,0,0,19,@Anvil,30,0,0,0,0,0,'Thane - Script action 3 - Remove stun aura from Avil'),
-- Script 0 for Thane
(@Script,9,0,0,0,0,100,0,0,0,0,0,75,47923,0,0,0,0,0,19,@Anvil,30,0,0,0,0,0,'Thane - Script action 0 - Add aura stunned to Anvil'),
(@Script,9,1,0,0,0,100,0,500,500,0,0,28,47922,0,0,0,0,0,1,0,0,0,0,0,0,0,'Thane - Script action 1 - Remove inurnable aura from self'),
(@Script,9,2,0,0,0,100,0,0,0,0,0,45,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Thane - Script action 2 - Data set 0 0'),
(@Script,9,3,0,0,0,100,0,14500,14500,0,0,28,47923,0,0,0,0,0,19,@Anvil,30,0,0,0,0,0,'Thane - Script action 3 - Remove stun aura from Avil');
-- Add SAI for Anvil
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@Anvil;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Anvil;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Anvil;
INSERT INTO `smart_scripts` VALUES
(@Anvil,0,0,0,8,0,100,0,47911,0,0,0,45,0,1,0,0,0,0,19,@Thane,30,0,0,0,0,0,'Anvil - on Spell hit - Data set 0 1 on Thane'),
(@Anvil,0,1,0,0,0,100,0,5000,7500,1200,14500,11,61577,0,0,0,0,0,2,0,0,0,0,0,0,0,'Anvil - IC - Cast Molten Blast');
-- Add npc_spellclick_spells
UPDATE `creature_template` SET `VehicleId`=149,`spell1`=61380,`spell2`=47911 WHERE `entry`=@Golem;
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=@Golem;
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`cast_flags`,`user_type`) VALUES
(@Golem,60944,1,0);
-- Add conditions for npc_spellclick_spells
DELETE FROM `conditions` WHERE `SourceGroup`=@Golem AND `SourceTypeOrReferenceId`=18;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES 
(18,@Golem,60944,0,1,9,0,12199,0,0,0,0,'', 'Player must be on quest 12199'),
(18,@Golem,60944,0,2,9,0,12153,0,0,0,0,'', 'Player must be on quest 12153');
-- Add conditions EMP to hit Anvil /for new condition system/
DELETE FROM `conditions` WHERE `SourceEntry`=47911 AND `SourceTypeOrReferenceId`=13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES 
(13,1,47911,0,0,31,0,3,@Anvil,0,0,0,'', 'EMP can hit only Anvil /rewritten condition/');
-- Add conditions EMP to cast only, if in 10 yards to anvil
DELETE FROM `conditions` WHERE `SourceEntry`=47911 AND `SourceTypeOrReferenceId`=17;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES 
(17,0,47911,0,0,29,0,@Anvil,10,0,0,0,'', 'EMP can cast, if in 10 yards of Anvil');
-- -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 4888: Event after finishing The Dragonforged Hilt quest chain
SET @NPC_MYRALION_SUNBLAZE := 36642;
SET @NPC_CALADIS_BRIGHTSPEAR := 36624;
SET @NPC_SUNREAVER_WAR_MAGE := 36657;
SET @NPC_SILVER_COVENANT_SENTINEL := 36656;
SET @NPC_IMAGE_OF_ALEXTRASZA := 37829;
SET @NPC_IMAGE_OF_ANASTERIAN := 37844;
SET @NPC_IMAGE_OF_THALORIEN := 37828;
SET @NPC_IMAGE_OF_MORLEN := 37845;
SET @NPC_BLOOD_QUEEN_LANA_THEL := 37846;
SET @NPC_QUELDELAR_DUMMY := 37852;
SET @SPELL_FREEZE_GUARDS := 71365;
SET @SPELL_ICY_TOUCH_TRIGGER := 70589;
SET @SPELL_ICY_TOUCH_EFFECT := 70592;
SET @SPELL_THROW_SWORD := 70586;
SET @SPELL_EXPLOSION_DUMMY := 70000; -- Not OK!!
SET @EMOTE_TALK := 1;
SET @EMOTE_BOW := 2;
SET @EMOTE_QUESTION := 6;
SET @EMOTE_KNEE := 16;
SET @EMOTE_POINT := 25;
SET @EMOTE_STAND := 26;
SET @EMOTE_YES := 273;
SET @EMOTE_1H := 375;
SET @EMOTE_2H := 425;
SET @ITEM_QUELDELAR := 49767;
SET @DATA_CUSTOM_ACTION := 50;
SET @DATA_DESPAWN_ACTION := 41;
SET @WP_MYRALION := @NPC_MYRALION_SUNBLAZE;
SET @WP_CALADIS := @NPC_CALADIS_BRIGHTSPEAR;
SET @WP_THALORIEN := @NPC_IMAGE_OF_THALORIEN;
SET @WP_MORLEN := @NPC_IMAGE_OF_MORLEN;
SET @WP_BLOOD_QUEEN_1 := @NPC_BLOOD_QUEEN_LANA_THEL*100;
SET @WP_BLOOD_QUEEN_2 := @NPC_BLOOD_QUEEN_LANA_THEL*100+1;
SET @WP_GUARD_A_1 := @NPC_SILVER_COVENANT_SENTINEL*100;
SET @WP_GUARD_A_2 := @NPC_SILVER_COVENANT_SENTINEL*100+1;
SET @WP_GUARD_H_1 := @NPC_SUNREAVER_WAR_MAGE*100;
SET @WP_GUARD_H_2 := @NPC_SUNREAVER_WAR_MAGE*100+1;
SET @QUEST_RETURN_CALADIS_BRIGHTSPEAR := 24454;
SET @QUEST_RETURN_MYRALION_SUNBLAZE := 24558;
-- Set images as non-selectables
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|33554432 WHERE `entry` IN (@NPC_IMAGE_OF_ALEXTRASZA,@NPC_IMAGE_OF_ANASTERIAN,@NPC_IMAGE_OF_THALORIEN,@NPC_IMAGE_OF_MORLEN);
-- Set Lana'thel as enemy and set OOC_NON_ATTACKABLE
UPDATE `creature_template` SET `faction_A`=16,`faction_H`=16,`unit_flags`=`unit_flags`|256 WHERE `entry`=@NPC_BLOOD_QUEEN_LANA_THEL;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=@SPELL_THROW_SWORD;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,@SPELL_THROW_SWORD,0,18,1,@NPC_QUELDELAR_DUMMY,0,0,'', "Throw Quel'delar on Quel'delar skull");
-- Set Morlen Coldgrip mount
DELETE FROM `creature_template_addon` WHERE (`entry`=@NPC_IMAGE_OF_MORLEN);
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@NPC_IMAGE_OF_MORLEN,0,25280,0,0,0,"");
-- Set AInames
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@NPC_CALADIS_BRIGHTSPEAR,@NPC_MYRALION_SUNBLAZE,@NPC_SILVER_COVENANT_SENTINEL,@NPC_SUNREAVER_WAR_MAGE,@NPC_IMAGE_OF_ALEXTRASZA,@NPC_IMAGE_OF_ANASTERIAN,@NPC_IMAGE_OF_THALORIEN,@NPC_IMAGE_OF_MORLEN,@NPC_BLOOD_QUEEN_LANA_THEL,@NPC_QUELDELAR_DUMMY);
DELETE FROM `smart_scripts` WHERE (`entryorguid` IN (@NPC_MYRALION_SUNBLAZE,@NPC_CALADIS_BRIGHTSPEAR,@NPC_IMAGE_OF_ALEXTRASZA,@NPC_IMAGE_OF_ANASTERIAN,@NPC_IMAGE_OF_THALORIEN,@NPC_IMAGE_OF_MORLEN,@NPC_BLOOD_QUEEN_LANA_THEL,@NPC_QUELDELAR_DUMMY) AND `source_type`=0);
DELETE FROM `smart_scripts` WHERE (`entryorguid` IN (@NPC_MYRALION_SUNBLAZE*100,@NPC_SILVER_COVENANT_SENTINEL*100,@NPC_BLOOD_QUEEN_LANA_THEL*100,@NPC_BLOOD_QUEEN_LANA_THEL*100+1) AND `source_type`=9);
DELETE FROM `smart_scripts` WHERE (`entryorguid` IN (-202775,-202776,-202777,-202778) AND `source_type`=0);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Image of Alextrasza
(@NPC_IMAGE_OF_ALEXTRASZA,0,0,0,38,0,100,0,@EMOTE_TALK,0,0,0,5,@EMOTE_TALK,0,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Alexstrasza (at Quel'delar rest) - Emote Talk on Data Set"),
(@NPC_IMAGE_OF_ALEXTRASZA,0,1,0,38,0,100,0,@EMOTE_POINT,0,0,0,5,@EMOTE_POINT,0,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Alexstrasza (at Quel'delar rest) - Emote Point on Data Set"),
(@NPC_IMAGE_OF_ALEXTRASZA,0,2,0,38,0,100,0,@DATA_CUSTOM_ACTION ,0,0,0,66,0,0,0,0,0,0,19,@NPC_IMAGE_OF_THALORIEN,0,0,0,0,0,0,"Image of Alexstrasza (at Quel'delar rest) - Set Orientation on Data Set"),
(@NPC_IMAGE_OF_ALEXTRASZA,0,3,0,38,0,100,0,@DATA_DESPAWN_ACTION,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Alexstrasza (at Quel'delar rest) - Despawn on Data Set"),
-- Image of Anasterian
(@NPC_IMAGE_OF_ANASTERIAN,0,0,0,38,0,100,0,@EMOTE_TALK,0,0,0,5,@EMOTE_TALK,0,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Anasterian (at Quel'delar rest) - Emote talk on Data Set"),
(@NPC_IMAGE_OF_ANASTERIAN,0,1,0,38,0,100,0,@EMOTE_BOW,0,0,0,5,@EMOTE_BOW,0,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Anasterian (at Quel'delar rest) - Emote bow on Data Set"),
(@NPC_IMAGE_OF_ANASTERIAN,0,2,0,38,0,100,0,@EMOTE_POINT,0,0,0,5,@EMOTE_POINT,0,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Anasterian (at Quel'delar rest) - Emote point on Data Set"),
(@NPC_IMAGE_OF_ANASTERIAN,0,3,0,38,0,100,0,@EMOTE_YES,0,0,0,5,@EMOTE_YES,0,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Anasterian (at Quel'delar rest) - Emote yes on Data Set"),
(@NPC_IMAGE_OF_ANASTERIAN,0,4,0,38,0,100,0,@DATA_CUSTOM_ACTION ,0,0,0,66,0,0,0,0,0,0,19,@NPC_IMAGE_OF_THALORIEN,0,0,0,0,0,0,"Image of Anasterian (at Quel'delar rest) - Set Orientation"),
(@NPC_IMAGE_OF_ANASTERIAN,0,5,0,38,0,100,0,@DATA_DESPAWN_ACTION,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Anasterian (at Quel'delar rest) - Despawn on data set"),
-- Image of Thalorien Dawnseeker
(@NPC_IMAGE_OF_THALORIEN,0,0,0,38,0,100,1,@DATA_CUSTOM_ACTION,0,0,0,53,0,@WP_THALORIEN,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Thalorien Dawnseeker (at Quel'Delar rest) - Move to position on Data set"),
(@NPC_IMAGE_OF_THALORIEN,0,1,0,38,0,100,1,@EMOTE_BOW,0,0,0,5,@EMOTE_BOW,0,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Thalorien Dawnseeker (at Quel'Delar rest) - Emote Bow on Data Set"),
(@NPC_IMAGE_OF_THALORIEN,0,2,0,38,0,100,1,@EMOTE_KNEE,0,0,0,5,@EMOTE_KNEE,0,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Thalorien Dawnseeker (at Quel'Delar rest) - Emote Knee on Data Set"),
(@NPC_IMAGE_OF_THALORIEN,0,3,4,38,0,100,1,@EMOTE_1H,0,0,0,71,0,0,@ITEM_QUELDELAR,0,0,0,1,0,0,0,0,0,0,0,"Image of Thalorien Dawnseeker (at Quel'Delar rest) - Equip Sword Data Set"),
(@NPC_IMAGE_OF_THALORIEN,0,4,0,61,0,100,1,0,0,0,0,17,@EMOTE_1H,0,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Thalorien Dawnseeker (at Quel'Delar rest) - EmoteState 2H on Data Set"),
(@NPC_IMAGE_OF_THALORIEN,0,5,0,38,0,100,1,@DATA_DESPAWN_ACTION,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Thalorien Dawnseeker (at Quel'Delar rest) - Desapwn at data set"),
(@NPC_IMAGE_OF_THALORIEN,0,6,0,38,0,100,1,@DATA_CUSTOM_ACTION+1,0,0,0,71,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Thalorien Dawnseeker (at Quel'Delar rest) - Show now weapon"),
-- Image of Morlen Coldgrip
(@NPC_IMAGE_OF_MORLEN,0,0,0,34,0,100,1,0,1,0,0,54,4000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Morlen Coldgrip - Pause WP on 1st point"),
(@NPC_IMAGE_OF_MORLEN,0,1,0,34,0,100,1,0,2,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Morlen Coldgrip - Despawn on last WP"),
(@NPC_IMAGE_OF_MORLEN,0,2,0,54,0,100,1,0,2,0,0,53,0,@WP_MORLEN,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Morlen Coldgrip - Start WP on spawn"),
-- Blood-Queen Lana'thel
(@NPC_BLOOD_QUEEN_LANA_THEL,0,0,0,54,0,100,1,0,0,0,0,53,0,@WP_BLOOD_QUEEN_1,0,0,0,0,1,0,0,0,0,0,0,0,"Blood Quen Lana'thel (at Quel'delar rest) - Start WP on spawn"),
(@NPC_BLOOD_QUEEN_LANA_THEL,0,1,2,40,0,100,1,1,@WP_BLOOD_QUEEN_1,0,0,80,@NPC_BLOOD_QUEEN_LANA_THEL*100+0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blood Quen Lana'thel (at Quel'delar rest) - Start first part of timed event when reached first point"),
(@NPC_BLOOD_QUEEN_LANA_THEL,0,2,0,61,0,100,0,0,0,0,0,66,0,0,0,0,0,0,19,@NPC_QUELDELAR_DUMMY,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Face to invisible dummy"),
(@NPC_BLOOD_QUEEN_LANA_THEL,0,3,0,40,0,100,1,2,@WP_BLOOD_QUEEN_2,0,0,80,@NPC_BLOOD_QUEEN_LANA_THEL*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blood Quen Lana'thel (at Quel'delar rest) - Start second timed event when reached second point"),
(@NPC_QUELDELAR_DUMMY,0,1,0,8,0,100,0,@SPELL_THROW_SWORD,0,0,0,11,@SPELL_EXPLOSION_DUMMY,1,0,0,0,0,1,0,0,0,0,0,0,0,"Quel'delar dummy (at Quel'delar rest) - Cast shadow explosion when hitten by sword"),
-- Blood-Queen Lana'thel 1st action list
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,0,0,0,0,100,1,3000,3000,0,0,45,@DATA_CUSTOM_ACTION,0,0,0,0,0,9,@NPC_SILVER_COVENANT_SENTINEL,0,20,0,0,0,0,"Blood Quen Lana'thel (at Quel'Delar rest) - Make guards attack her"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,1,0,0,0,100,1,0,0,0,0,45,@DATA_CUSTOM_ACTION,0,0,0,0,0,9,@NPC_SUNREAVER_WAR_MAGE,0,20,0,0,0,0,"Blood Quen Lana'thel (at Quel'Delar rest) - Make guards attack her"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,2,0,0,0,100,1,3000,3000,0,0,1,1,0,0,0,0,0,1,0,0,20,0,0,0,0,"Blood Quen Lana'thel (at Quel'Delar rest) - Say 1"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,3,0,0,0,100,1,3000,3000,0,0,11,@SPELL_FREEZE_GUARDS,0,0,0,0,0,1,0,0,20,0,0,0,0,"Blood Quen Lana'thel (at Quel'Delar rest) - Cast Freeze Guards"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,4,0,0,0,100,1,0,0,0,0,45,@DATA_CUSTOM_ACTION+1,0,0,0,0,0,9,@NPC_SILVER_COVENANT_SENTINEL,0,20,0,0,0,0,"Blood Quen Lana'thel (at Quel'Delar rest) - Freeze guards"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,5,0,0,0,100,1,0,0,0,0,45,@DATA_CUSTOM_ACTION+1,0,0,0,0,0,9,@NPC_SUNREAVER_WAR_MAGE,0,20,0,0,0,0,"Blood Quen Lana'thel (at Quel'Delar rest) - Freeze guards"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,6,0,0,0,100,1,500,500,0,0,1,2,0,0,0,0,0,1,0,0,20,0,0,0,0,"Blood Quen Lana'thel (at Quel'Delar rest) - Say 2"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,7,0,0,0,100,1,4000,4000,0,0,1,3,0,0,0,0,0,1,0,0,20,0,0,0,0,"Blood Quen Lana'thel (at Quel'Delar rest) - Say 3"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,8,0,0,0,100,1,0,0,0,0,12,@NPC_IMAGE_OF_ALEXTRASZA,8,0,0,0,0,8,0,0,0,8120.65,780.068,481.87,6.14516,"Blood Queen Lana'thel (at Quel'Delar rest) - Summon Alextrasza"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,9,0,0,0,100,1,0,0,0,0,12,@NPC_IMAGE_OF_ANASTERIAN,8,0,0,0,0,8,0,0,0,8123.63,780.044,482.066,3.10017,"Blood Queen Lana'thel (at Quel'Delar rest) - Summon Anasterian"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,10,0,0,0,100,1,500,500,0,0,45,@EMOTE_POINT,0,0,0,0,0,19,@NPC_IMAGE_OF_ALEXTRASZA,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Call point talk on Alextrasza"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,11,0,0,0,100,1,100,100,0,0,45,@EMOTE_TALK,0,0,0,0,0,19,@NPC_IMAGE_OF_ALEXTRASZA,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Call emote talk on Alextrasza"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,12,0,0,0,100,1,4000,4000,0,0,5,@EMOTE_POINT,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Emote Point"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,13,0,0,0,100,1,0,0,0,0,45,@EMOTE_BOW,0,0,0,0,0,19,@NPC_IMAGE_OF_ANASTERIAN,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Call emote bow on Anasterian"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,14,0,0,0,100,1,2000,2000,0,0,45,@EMOTE_TALK,0,0,0,0,0,19,@NPC_IMAGE_OF_ALEXTRASZA,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Call emote talk on Alextrasza"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,15,0,0,0,100,1,2000,2000,0,0,45,@EMOTE_YES,0,0,0,0,0,19,@NPC_IMAGE_OF_ANASTERIAN,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Call emote yes on Anasterian"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,16,0,0,0,100,1,2000,2000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Say 4"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,17,0,0,0,100,1,0,0,0,0,12,@NPC_IMAGE_OF_THALORIEN,8,0,0,0,0,8,0,0,0,8125.07,773.643,482.395,1.72804,"Blood Queen Lana'thel (at Quel'Delar rest) - Summon Thalorien"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,18,0,0,0,100,1,500,500,0,0,45,@DATA_CUSTOM_ACTION,0,0,0,0,0,19,@NPC_IMAGE_OF_ALEXTRASZA,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Call set facing to Thalorien on Alextrasza"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,19,0,0,0,100,1,0,0,0,0,45,@DATA_CUSTOM_ACTION,0,0,0,0,0,19,@NPC_IMAGE_OF_ANASTERIAN,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Call set facing to Thalorien on Anasterian"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,20,0,0,0,100,1,1000,1000,0,0,45,@DATA_CUSTOM_ACTION,0,0,0,0,0,19,@NPC_IMAGE_OF_THALORIEN,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Call Thalorien Move"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,21,0,0,0,100,1,3000,3000,0,0,45,@EMOTE_TALK,0,0,0,0,0,19,@NPC_IMAGE_OF_ANASTERIAN,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Call Emote Talk on Anastarian"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,22,0,0,0,100,1,1000,1000,0,0,45,@EMOTE_BOW,0,0,0,0,0,19,@NPC_IMAGE_OF_THALORIEN,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Call Emote Bow on Thalorien"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,23,0,0,0,100,1,1000,1000,0,0,45,@EMOTE_POINT,0,0,0,0,0,19,@NPC_IMAGE_OF_ANASTERIAN,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Call Emote point on Anastarian"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,24,0,0,0,100,1,1000,1000,0,0,45,@EMOTE_KNEE,0,0,0,0,0,19,@NPC_IMAGE_OF_THALORIEN,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Call Emote Knee on Thalorien"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,25,0,0,0,100,1,1000,1000,0,0,45,@DATA_DESPAWN_ACTION,0,0,0,0,0,19,@NPC_IMAGE_OF_ALEXTRASZA,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Despawn Alextrasza"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,26,0,0,0,100,1,1000,1000,0,0,45,@DATA_DESPAWN_ACTION,0,0,0,0,0,19,@NPC_IMAGE_OF_ANASTERIAN,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Despawn Anastarian"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,27,0,0,0,100,1,1000,1000,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Say 5"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,28,0,0,0,100,1,3000,3000,0,0,45,@EMOTE_1H,0,0,0,0,0,19,@NPC_IMAGE_OF_THALORIEN,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Call emote 2h on Thalorien"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,29,0,0,0,100,1,4000,4000,0,0,12,@NPC_IMAGE_OF_MORLEN,8,0,0,0,0,8,0,0,0,8119.94,787.208,481.39,5.00233,"Blood Queen Lana'thel (at Quel'Delar rest) - Summon Morlen Coldgrip"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,30,0,0,0,100,1,2000,2000,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Say 6"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,31,0,0,0,100,1,2000,2000,0,0,86,@SPELL_ICY_TOUCH_TRIGGER,0,19,@NPC_IMAGE_OF_MORLEN,0,0,1,0,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Call cast of Morlen Coldgrip on Thalorien (dummy)"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,32,0,0,0,100,1,1000,1000,0,0,86,@SPELL_ICY_TOUCH_EFFECT,0,19,@NPC_IMAGE_OF_THALORIEN,0,0,1,0,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Call cast of Thalorien (insta self kill)"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,33,0,0,0,100,1,4000,4000,0,0,53,0,@WP_BLOOD_QUEEN_2,0,0,0,0,1,0,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Move to next event point"),
-- Blood-Queen Lana'thel 2nd action list
(@NPC_BLOOD_QUEEN_LANA_THEL*100+1,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,19,@NPC_IMAGE_OF_THALORIEN,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Set facing to Thalorien"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+1,9,1,0,0,0,100,0,2000,2000,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Say 7"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+1,9,2,0,0,0,100,0,1000,1000,0,0,71,0,0,@ITEM_QUELDELAR,0,0,0,1,0,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Equip Sword"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+1,9,3,0,0,0,100,0,0,0,0,0,45,@DATA_CUSTOM_ACTION+1,0,0,0,0,0,19,@NPC_IMAGE_OF_THALORIEN,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Set no weapon visible on Thalorien"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+1,9,4,0,0,0,100,0,7000,7000,0,0,40,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Set no weapon visible"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+1,9,5,0,0,0,100,0,0,0,0,0,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Emote Talk"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+1,9,6,0,0,0,100,0,6000,6000,0,0,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Say 8"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+1,9,7,0,0,0,100,0,8000,8000,0,0,1,9,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Say 9"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+1,9,8,0,0,0,100,0,8000,8000,0,0,1,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Say 10"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+1,9,9,0,0,0,100,0,5000,5000,0,0,11,@SPELL_THROW_SWORD,0,0,0,0,0,19,@NPC_QUELDELAR_DUMMY,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Cast some spell on invisible dummy"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+1,9,10,0,0,0,100,0,4000,4000,0,0,1,11,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Say 11"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+1,9,11,0,0,0,100,0,5000,5000,0,0,45,@DATA_CUSTOM_ACTION,0,0,0,0,0,7,0,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Call reset on the summoner"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+1,9,12,0,0,0,100,1,0,0,0,0,45,@DATA_CUSTOM_ACTION+2,0,0,0,0,0,9,@NPC_SILVER_COVENANT_SENTINEL,0,20,0,0,0,0,"Blood Quen Lana'thel (at Quel'Delar rest) - Unfreeze guards"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+1,9,13,0,0,0,100,1,0,0,0,0,45,@DATA_CUSTOM_ACTION+2,0,0,0,0,0,9,@NPC_SUNREAVER_WAR_MAGE,0,20,0,0,0,0,"Blood Quen Lana'thel (at Quel'Delar rest) - Unfreeze guards"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+1,9,14,0,0,0,100,0,0,0,0,0,45,@DATA_DESPAWN_ACTION,0,0,0,0,0,19,@NPC_IMAGE_OF_THALORIEN,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'elar rest) - Call despawn on Thalorien"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+1,9,15,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Despawn self"),
-- Silver Covenant Guards
(-202776,0,0,1,38,0,100,0,@DATA_CUSTOM_ACTION,0,0,0,53,1,@WP_GUARD_A_1,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Start movement on data set"),
(-202776,0,1,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Set phase 1"),
(-202776,0,2,3,40,1,100,0,1,0,0,0,66,0,0,0,0,0,0,19,@NPC_BLOOD_QUEEN_LANA_THEL,0,0,0,0,0,0,"Silver Covenant Sentinel - Set facing to Lana'thel on reach point"),
(-202776,0,3,4,61,1,100,0,0,0,0,0,17,@EMOTE_2H,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Set attack state"),
(-202776,0,4,5,61,1,100,0,0,0,0,0,55,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Stop WP"),
(-202776,0,5,12,61,1,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Set Phase 2"),
(-202776,0,6,0,38,0,100,0,@DATA_CUSTOM_ACTION+1,0,0,0,75,@SPELL_FREEZE_GUARDS,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Freeze self on Data Set"),
(-202776,0,7,8,38,0,100,0,@DATA_CUSTOM_ACTION+2,0,0,0,28,@SPELL_FREEZE_GUARDS,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Unfreeze self on Data Set"),
(-202776,0,8,0,61,0,100,0,0,0,0,0,80,@NPC_SILVER_COVENANT_SENTINEL*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Create timed event based on action list"),
(-202776,0,9,0,38,0,100,0,@DATA_CUSTOM_ACTION+3,0,0,0,53,0,@WP_GUARD_A_1,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Start movement back on timed event (called from action list)"),
(-202776,0,10,11,40,0,100,0,2,0,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - restore home orientation on reach point"),
(-202776,0,11,0,61,0,100,0,0,0,0,0,17,@EMOTE_STAND,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - restore stand state"),
(-202776,0,12,0,61,1,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Say to Lana'thel"),
(-202775,0,0,1,38,0,100,0,@DATA_CUSTOM_ACTION,0,0,0,53,1,@WP_GUARD_A_2,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Start movement on data set"),
(-202775,0,1,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Set phase 1"),
(-202775,0,2,3,40,1,100,0,1,0,0,0,66,0,0,0,0,0,0,19,@NPC_BLOOD_QUEEN_LANA_THEL,0,0,0,0,0,0,"Silver Covenant Sentinel - Set facing to Lana'thel on reach point"),
(-202775,0,3,4,61,1,100,0,0,0,0,0,17,@EMOTE_2H,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Set attack state"),
(-202775,0,4,5,61,1,100,0,0,0,0,0,55,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Stop WP"),
(-202775,0,5,0,61,1,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Set Phase 2"),
(-202775,0,6,0,38,0,100,0,@DATA_CUSTOM_ACTION+1,0,0,0,75,@SPELL_FREEZE_GUARDS,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Freeze self on Data Set"),
(-202775,0,7,8,38,0,100,0,@DATA_CUSTOM_ACTION+2,0,0,0,28,@SPELL_FREEZE_GUARDS,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Unfreeze self on Data Set"),
(-202775,0,8,0,61,0,100,0,0,0,0,0,80,@NPC_SILVER_COVENANT_SENTINEL*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Create timed event based on action list"),
(-202775,0,9,0,38,0,100,0,@DATA_CUSTOM_ACTION+3,0,0,0,53,0,@WP_GUARD_A_2,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Start movement back on timed event (called from action list)"),
(-202775,0,10,11,40,0,100,0,2,0,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - restore home orientation on reach point"),
(-202775,0,11,0,61,0,100,0,0,0,0,0,17,@EMOTE_STAND,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - restore stand state"),
-- Sunreaver Guards
(-202777,0,0,1,38,0,100,0,@DATA_CUSTOM_ACTION,0,0,0,53,1,@WP_GUARD_H_1,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Start movement on data set"),
(-202777,0,1,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Set phase 1"),
(-202777,0,2,3,40,1,100,0,1,0,0,0,66,0,0,0,0,0,0,19,@NPC_BLOOD_QUEEN_LANA_THEL,0,0,0,0,0,0,"Silver Covenant Sentinel - Set facing to Lana'thel on reach point"),
(-202777,0,3,4,61,1,100,0,0,0,0,0,17,@EMOTE_2H,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Set attack state"),
(-202777,0,4,5,61,1,100,0,0,0,0,0,55,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Stop WP"),
(-202777,0,5,0,61,1,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Set Phase 2"),
(-202777,0,6,0,38,0,100,0,@DATA_CUSTOM_ACTION+1,0,0,0,75,@SPELL_FREEZE_GUARDS,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Freeze self on Data Set"),
(-202777,0,7,8,38,0,100,0,@DATA_CUSTOM_ACTION+2,0,0,0,28,@SPELL_FREEZE_GUARDS,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Unfreeze self on Data Set"),
(-202777,0,8,0,61,0,100,0,0,0,0,0,80,@NPC_SILVER_COVENANT_SENTINEL*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Create timed event based on action list"),
(-202777,0,9,0,38,0,100,0,@DATA_CUSTOM_ACTION+3,0,0,0,53,0,@WP_GUARD_H_1,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Start movement back on timed event (called from action list)"),
(-202777,0,10,11,40,0,100,0,2,0,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - restore home orientation on reach point"),
(-202777,0,11,0,61,0,100,0,0,0,0,0,17,@EMOTE_STAND,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - restore stand state"),
(-202778,0,0,1,38,0,100,0,@DATA_CUSTOM_ACTION,0,0,0,53,1,@WP_GUARD_H_2,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Start movement on data set"),
(-202778,0,1,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Set phase 1"),
(-202778,0,2,3,40,1,100,0,1,0,0,0,66,0,0,0,0,0,0,19,@NPC_BLOOD_QUEEN_LANA_THEL,0,0,0,0,0,0,"Silver Covenant Sentinel - Set facing to Lana'thel on reach point"),
(-202778,0,3,4,61,1,100,0,0,0,0,0,17,@EMOTE_2H,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Set attack state"),
(-202778,0,4,5,61,1,100,0,0,0,0,0,55,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Stop WP"),
(-202778,0,5,0,61,1,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Set Phase 2"),
(-202778,0,6,0,38,0,100,0,@DATA_CUSTOM_ACTION+1,0,0,0,75,@SPELL_FREEZE_GUARDS,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Freeze self on Data Set"),
(-202778,0,7,8,38,0,100,0,@DATA_CUSTOM_ACTION+2,0,0,0,28,@SPELL_FREEZE_GUARDS,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Unfreeze self on Data Set"),
(-202778,0,8,0,61,0,100,0,0,0,0,0,80,@NPC_SILVER_COVENANT_SENTINEL*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Create timed event based on action list"),
(-202778,0,9,0,38,0,100,0,@DATA_CUSTOM_ACTION+3,0,0,0,53,0,@WP_GUARD_H_2,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Start movement back on timed event (called from action list)"),
(-202778,0,10,11,40,0,100,0,2,0,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - restore home orientation on reach point"),
(-202778,0,11,0,61,0,100,0,0,0,0,0,17,@EMOTE_STAND,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - restore stand state"),
-- Timed event for guards
(@NPC_SILVER_COVENANT_SENTINEL*100,9,0,0,0,0,100,0,1000,1000,0,0,45,@DATA_CUSTOM_ACTION+3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Quel'Delar rest - Guards timed return"),
-- Myralion Sunblaze
(@NPC_MYRALION_SUNBLAZE,0,0,1,20,0,100,0,@QUEST_RETURN_MYRALION_SUNBLAZE,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Myralion Sunblaze - remove gossip and qg flag on quest complete"),
(@NPC_MYRALION_SUNBLAZE,0,1,2,61,0,100,0,0,0,0,0,53,0,@WP_MYRALION,0,0,0,0,1,0,0,0,0,0,0,0,"Myralion Sunblaze - Start WP on quest complete"),
(@NPC_MYRALION_SUNBLAZE,0,2,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Myralion Sunblaze - Set phase 1"),
(@NPC_MYRALION_SUNBLAZE,0,3,4,40,1,100,0,1,0,0,0,55,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Myralion Sunblaze - Stop WP on point reached"),
(@NPC_MYRALION_SUNBLAZE,0,4,0,61,1,100,0,0,0,0,0,80,@NPC_MYRALION_SUNBLAZE*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Myralion Sunblaze - Start timed event on point reached"),
(@NPC_MYRALION_SUNBLAZE,0,6,7,38,0,100,0,@DATA_CUSTOM_ACTION,0,0,0,53,0,@WP_MYRALION,0,0,0,0,1,0,0,0,0,0,0,0,"Myralion Sunblaze - WP event on data set"),
(@NPC_MYRALION_SUNBLAZE,0,7,11,61,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Myralion Sunblaze - Set phase on data set"),
(@NPC_MYRALION_SUNBLAZE,0,8,9,40,0,100,0,2,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Myralion Sunblaze - Say 3 event on home reached"),
(@NPC_MYRALION_SUNBLAZE,0,9,10,61,0,100,0,0,0,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Myralion Sunblaze - restore orientation event on home reached"),
(@NPC_MYRALION_SUNBLAZE,0,10,0,61,0,100,0,0,0,0,0,81,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Myralion Sunblaze - restore npc flags event on home reached"),
(@NPC_MYRALION_SUNBLAZE,0,11,0,61,0,100,0,0,0,0,0,43,0,28889,0,0,0,0,1,0,0,0,0,0,0,0,"Myralion Sunblaze - Mount on data set"),
-- Caladis Brightspear
(@NPC_CALADIS_BRIGHTSPEAR,0,0,1,20,0,100,0,@QUEST_RETURN_CALADIS_BRIGHTSPEAR,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Caladis Brightspear - remove gossip and qg flag on quest complete"),
(@NPC_CALADIS_BRIGHTSPEAR,0,1,2,61,0,100,0,0,0,0,0,53,0,@WP_CALADIS,0,0,0,0,1,0,0,0,0,0,0,0,"Caladis Brightspear - Start WP on quest complete"),
(@NPC_CALADIS_BRIGHTSPEAR,0,2,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Caladis Brightspear - Set phase 1"),
(@NPC_CALADIS_BRIGHTSPEAR,0,3,4,40,1,100,0,1,0,0,0,55,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Caladis Brightspear - Stop WP on point reached"),
(@NPC_CALADIS_BRIGHTSPEAR,0,4,0,61,1,100,0,0,0,0,0,80,@NPC_MYRALION_SUNBLAZE*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Caladis Brightspear - Start timed event on point reached"),
(@NPC_CALADIS_BRIGHTSPEAR,0,6,7,38,0,100,0,@DATA_CUSTOM_ACTION,0,0,0,53,0,@WP_CALADIS,0,0,0,0,1,0,0,0,0,0,0,0,"Caladis Brightspear - WP event on data set"),
(@NPC_CALADIS_BRIGHTSPEAR,0,7,11,61,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Caladis Brightspear - Set phase on data set"),
(@NPC_CALADIS_BRIGHTSPEAR,0,8,9,40,0,100,0,2,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Caladis Brightspear - Say 3 event on home reached"),
(@NPC_CALADIS_BRIGHTSPEAR,0,9,10,61,0,100,0,0,0,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Caladis Brightspear - restore orientation event on home reached"),
(@NPC_CALADIS_BRIGHTSPEAR,0,10,0,61,0,100,0,0,0,0,0,81,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Caladis Brightspear - restore npc flags event on home reached"),
(@NPC_CALADIS_BRIGHTSPEAR,0,11,0,61,0,100,0,0,0,0,0,43,0,28888,0,0,0,0,1,0,0,0,0,0,0,0,"Caladis Brightspear - Mount on data set"),
-- Timed event for faction heralds
(@NPC_MYRALION_SUNBLAZE*100,9,0,0,0,0,100,1,1000,1000,0,0,43,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Quel'delar rest faction Herald - Dismount"),
(@NPC_MYRALION_SUNBLAZE*100,9,1,0,0,0,100,1,1000,1000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Quel'delar rest faction Herald - Say 1"),
(@NPC_MYRALION_SUNBLAZE*100,9,2,0,0,0,100,1,0,0,0,0,12,@NPC_BLOOD_QUEEN_LANA_THEL,8,0,0,0,0,8,0,0,0,8102.33,785.112,481.025,5.99244,"Quel'delar rest faction Herald - Summon Lana'thel"),
(@NPC_MYRALION_SUNBLAZE*100,9,3,0,0,0,100,1,8000,8000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Quel'delar rest faction Herald - Say 2");
DELETE FROM `waypoints` WHERE `entry` IN (@WP_MYRALION,@WP_CALADIS,@WP_THALORIEN,@WP_MORLEN,@WP_BLOOD_QUEEN_1,@WP_BLOOD_QUEEN_2,@WP_GUARD_A_1,@WP_GUARD_A_2,@WP_GUARD_H_1,@WP_GUARD_H_2);
INSERT INTO `waypoints`(`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@WP_MYRALION,1,8121.94,776.030,482.114,"Myralion Sunblaze - WP 1"),
(@WP_MYRALION,2,8127.26,766.402,482.579,"Myralion Sunblaze - Home Position"),
(@WP_CALADIS,1,8119.73,783.416,481.623,"Caladis Brightspear - WP 1"),
(@WP_CALADIS,2,8117.69,795.523,481.184,"Caladis Brightspear - Home Position"),
(@WP_THALORIEN,1,8122.35,778.496,482.034,"Image of Thalorien Dawnseeker - WP 1"),
(@WP_MORLEN,1,8121.75,781.096,481.905,"Image of Morlen Coldgrip - WP 1"),
(@WP_MORLEN,2,8124.83,774.881,482.328,"Image of Morlen Coldgrip - WP 2"),
(@WP_BLOOD_QUEEN_1,1,8115.65,780.131,481.611,"Lana'thel Quel'delar rest - WP 1.1"),
(@WP_BLOOD_QUEEN_2,1,8119.96,775.924,482.029,"Lana'thel Quel'delar rest - WP 2.1"),
(@WP_BLOOD_QUEEN_2,2,8124.342,778.9861,482.0804,"Lana'thel Quel'delar rest - WP 2.2"),
(@WP_GUARD_A_1,1,8118.80,783.843,481.567,"Quel'Delar rest guard 2 (GUID: 202776)- WP 1"),
(@WP_GUARD_A_1,2,8123.66,793.745,481.434,"Quel'Delar rest guard 2 (GUID: 202776)- Home Position"),
(@WP_GUARD_A_2,1,8113.40,783.385,481.416,"Quel'Delar rest guard 1 (GUID: 202775)- WP 1"),
(@WP_GUARD_A_2,2,8111.31,794.347,481.059,"Quel'Delar rest guard 1 (GUID: 202775)- Home Position"),
(@WP_GUARD_H_1,1,8112.35,775.095,481.583,"Quel'Delar rest guard 1 (GUID: 202777)- WP 1"),
(@WP_GUARD_H_1,2,8120.10,765.363,482.266,"Quel'Delar rest guard 1 (GUID: 202777)- Home Position"),
(@WP_GUARD_H_2,1,8118.65,775.747,481.973,"Quel'Delar rest guard 2 (GUID: 202778)- WP 1"),
(@WP_GUARD_H_2,2,8130.01,772.465,482.629,"Quel'Delar rest guard 2 (GUID: 202778)- Home Position");
DELETE FROM `creature_text` WHERE `entry` IN (@NPC_MYRALION_SUNBLAZE,@NPC_CALADIS_BRIGHTSPEAR,@NPC_SILVER_COVENANT_SENTINEL,@NPC_BLOOD_QUEEN_LANA_THEL);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@NPC_MYRALION_SUNBLAZE,1,0,"The style of this blade and its markings hinted that it might be a dragonforged sword. At last, we will have our answer.",12,0,100,@EMOTE_TALK,0,16745,"Myralion Sunblaze - Say 1"),
(@NPC_MYRALION_SUNBLAZE,2,0,"After all these years, can it really be --",12,0,100,@EMOTE_QUESTION,0,16746,"Myralion Sunblaze - Say 2"),
(@NPC_MYRALION_SUNBLAZE,3,0,"It falls to us to see Quel'Delar restored for the Sunreavers.",12,0,100,0,0,0,"Myralion Sunblaze - Say 3"),
(@NPC_CALADIS_BRIGHTSPEAR,1,0,"I knew this was a dragonforged blade when I first laid eyes on it.",12,0,100,@EMOTE_TALK,0,16604,"Caladis Brightspear - Say 1"),
(@NPC_CALADIS_BRIGHTSPEAR,2,0,"But can it be? Is this really --",12,0,100,@EMOTE_QUESTION,0,16605,"Caladis Brightspear - Say 2"),
(@NPC_CALADIS_BRIGHTSPEAR,3,0,"I vow that the Silver Covenant will see Quel'Delar restored.",12,0,100,0,0,0,"Caladis Brightspear - Say 3"),
(@NPC_SILVER_COVENANT_SENTINEL,1,0,"You are not welcome here, minion of the Lich King!",12,0,100,0,0,0,"Silver Covenant Sentinel - Say 1"),
(@NPC_BLOOD_QUEEN_LANA_THEL,1,0,"Quel'Delar.",12,0,100,@EMOTE_TALK,0,16808,"Blood Queen Lana'thel - Say 1"),
(@NPC_BLOOD_QUEEN_LANA_THEL,2,0,"Quiet, fools. If I had wished to kill you, you'd already be dead.",12,0,100,0,0,0,"Blood Queen Lana'thel - Say 2"),
(@NPC_BLOOD_QUEEN_LANA_THEL,3,0,"As Quel'Serrar was forged by the dragons and given to the kaldorei, its twin,Quel'Delar was given to my people.",12,0,100,@EMOTE_TALK,0,16809,"Blood Queen Lana'thel - Say 3"),
(@NPC_BLOOD_QUEEN_LANA_THEL,4,0,"The king bestowed the blade upon my friend, Thalorien Dawnseeker.",12,0,100,@EMOTE_TALK,0,16800,"Blood Queen Lana'thel - Say 4"),
(@NPC_BLOOD_QUEEN_LANA_THEL,5,0,"But even Thalorien's skill and Quel'Delar's magic could not save Silvermoon from the might of the Scourge.",12,0,100,@EMOTE_TALK,0,16801,"Blood Queen Lana'thel - Say 5"),
(@NPC_BLOOD_QUEEN_LANA_THEL,6,0,"Thalorien fell before the gates of the Sunwell, buying time for others to escape.",12,0,100,@EMOTE_TALK,0,16802,"Blood Queen Lana'thel - Say 6"),
(@NPC_BLOOD_QUEEN_LANA_THEL,7,0,"After the battle, I recovered the sword from the field. I bore it to Northrend in the service of my prince, seeking to avenge our people's defeat.",12,0,100,@EMOTE_KNEE,0,16803,"Blood Queen Lana'thel - Say 7"),
(@NPC_BLOOD_QUEEN_LANA_THEL,8,0,"Arthas shattered our forces and took the most powerful of us into his service as the San'layn.",12,0,100,@EMOTE_TALK,0,16804,"Blood Queen Lana'thel - Say 8"),
(@NPC_BLOOD_QUEEN_LANA_THEL,9,0,"My memories of Thalorien went cold and so did his blade.",12,0,100,@EMOTE_TALK,0,16805,"Blood Queen Lana'thel - Say 9"),
(@NPC_BLOOD_QUEEN_LANA_THEL,10,0,"It was I who brought Quel'Delar here,to return it to its makers. In breaking the weapon, so did I break its power.",12,0,100,@EMOTE_POINT,0,16806,"Blood Queen Lana'thel - Say 10"),
(@NPC_BLOOD_QUEEN_LANA_THEL,11,0,"Quel'Delar will never serve another!",12,0,100,5,0,16807,"Blood Queen Lana'thel - Say 11");

-- -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Startup Fixes
DELETE FROM `npc_text` WHERE `ID`=12628;
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `lang0`, `prob0`, `em0_0`, `em0_1`, `em0_2`, `em0_3`, `em0_4`, `em0_5`, `text1_0`, `text1_1`, `lang1`, `prob1`, `em1_0`, `em1_1`, `em1_2`, `em1_3`, `em1_4`, `em1_5`, `text2_0`, `text2_1`, `lang2`, `prob2`, `em2_0`, `em2_1`, `em2_2`, `em2_3`, `em2_4`, `em2_5`, `text3_0`, `text3_1`, `lang3`, `prob3`, `em3_0`, `em3_1`, `em3_2`, `em3_3`, `em3_4`, `em3_5`, `text4_0`, `text4_1`, `lang4`, `prob4`, `em4_0`, `em4_1`, `em4_2`, `em4_3`, `em4_4`, `em4_5`, `text5_0`, `text5_1`, `lang5`, `prob5`, `em5_0`, `em5_1`, `em5_2`, `em5_3`, `em5_4`, `em5_5`, `text6_0`, `text6_1`, `lang6`, `prob6`, `em6_0`, `em6_1`, `em6_2`, `em6_3`, `em6_4`, `em6_5`, `text7_0`, `text7_1`, `lang7`, `prob7`, `em7_0`, `em7_1`, `em7_2`, `em7_3`, `em7_4`, `em7_5`, `WDBVerified`) VALUES
(12628, '', 'These infants will live. With love and affection they will grow to be strong members of the Horde, and with time the horrible reminders of their shattered lives will fade.', 0, 1, 396, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 12340);
UPDATE `conditions` SET `ConditionTarget`=0, `ConditionValue1`=47740, `ConditionValue3`=0, `NegativeCondition`=1 WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9456 AND `ConditionTypeOrReference`=1;
-- -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 373: The Binding
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|512 WHERE `entry` IN (5676,5677);
-- -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 1682: Glyph Chasing
DELETE FROM `gossip_menu` WHERE entry IN (6559,6560,6561);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(6559,7770),
(6560,7770),
(6561,7770);
DELETE FROM `gossip_menu_option` WHERE menu_id IN (6559,6560,6561);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES
(6559,0,0, '<Use the transcription device to gather a rubbing.>',1,1,0,0,0,0,NULL),
(6560,0,0, '<Use the transcription device to gather a rubbing.>',1,1,0,0,0,0,NULL),
(6561,0,0, '<Use the transcription device to gather a rubbing.>',1,1,0,0,0,0,NULL);
-- Object SAI
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry` IN (180453,180454,180455);
DELETE FROM `smart_scripts` WHERE entryorguid IN (180453,180454,180455) AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`COMMENT`) VALUES
(180453,1,0,1,62,0,100,0,6561,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'close gossip'),
(180453,1,1,0,61,0,100,1,0,0,0,0,56,20456,1,0,0,0,0,7,0,0,0,0,0,0,0,'additem 20456'),
(180454,1,0,1,62,0,100,0,6560,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'close gossip'),
(180454,1,1,0,61,0,100,1,0,0,0,0,56,20455,1,0,0,0,0,7,0,0,0,0,0,0,0,'additem 20455'),
(180455,1,0,1,62,0,100,0,6559,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'close gossip'),
(180455,1,1,0,61,0,100,1,0,0,0,0,56,20454,1,0,0,0,0,7,0,0,0,0,0,0,0,'additem 20454');
-- -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 3068: On Ruby Wings
-- This will add flying and the abilities to the action bar so the quest is completable using fireball to kill ghouls.
UPDATE `creature_template` SET `spell1`=50430, `spell2`=55987, `spell3`=50348, `InhabitType`=5 WHERE `entry`=27996;
-- -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 3232: Vengeful Souls
-- Spawns based on Sniffed Data:
SET @GUID := 43486; 
DELETE FROM `creature` WHERE `id`=21636;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@GUID+0,21636,530,1,1,0,0,-2898.17,4497.223,-42.86146,2.9147,600,0,0,5914,0,0),
(@GUID+1,21636,530,1,1,0,0,-3013.516,4510.811,-42.86374,5.009095,600,0,0,5914,0,0),
(@GUID+2,21636,530,1,1,0,0,-2974.286,4441.98,-47.21168,1.43117,600,0,0,5914,0,0);
-- -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 3608: Seal of Ascension
-- TODO: The creature skills appear at first 5 slots instead at 1st, 4th, 5th, 6th and 7th as seen in the videos.
DELETE FROM `conditions` WHERE `SourceEntry`=16053;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,16053,0,0,31,0, 3,10321,0,0,0,'','Dominion Of Soul can only target Emberstrife'),
(17,0,16053,0,0,38,1,10,4,0,0,0,'','Emberstrife''s HP must be 10% or less');
-- http://old.wowhead.com/npc=10321#abilities
UPDATE `creature_template` SET `spell1`=0, `spell2`=0, `spell3`=0, `spell4`=16054, `spell5`=9573, `spell6`=8269, `spell7`=40504, `spell8`=0 WHERE `entry`=10321;
-- -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 3656: Hungry Nether Rays
SET @NPC := 23219;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@NPC;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@NPC;
DELETE FROM `smart_scripts` WHERE (`entryorguid`=@NPC AND `source_type`=0);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@NPC,0,1,0,25,0,100,1,0,530,0,0,11,32942,2,0,0,0,0,1,0,0,0,0,0,0,0,'Blackwind Warp Chaser - Respawn - Cast Phasing Invisibility'),
(@NPC,0,2,0,4,0,100,0,0,0,0,0,28,32942,0,0,0,0,0,1,0,0,0,0,0,0,0,'Blackwind Warp Chaser - Aggro - Remove Phasing Invisibility'),
(@NPC,0,3,0,0,0,100,0,3000,6000,4000,7000,11,32739,0,0,0,0,0,5,0,0,0,0,0,0,0,'Blackwind Warp Chaser - Combat - Cast Venomous Bite'),
(@NPC,0,4,0,0,0,100,0,12000,15000,20000,40000,11,32920,0,0,0,0,0,2,0,0,0,0,0,0,0,'Blackwind Warp Chaser - Combat - Cast Warp'),
(@NPC,0,5,0,4,0,100,0,2000,5000,7000,15000,11,37417,1,0,0,0,0,5,0,0,0,0,0,0,0,'Blackwind Warp Chaser - Aggro - Cast Warp Charge'),
(@NPC,0,6,0,6,0,100,0,0,0,0,0,33,23438,0,0,0,0,0,7,0,0,0,0,0,0,0,'Blackwind Warp Chaser - Death - Credit');
DELETE FROM `conditions` WHERE SourceTypeOrReferenceId=22 AND SourceEntry IN(@NPC);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,7,@NPC,0,0,29,0,23439,15,0,0,0, '', 'SAI Trigger Only If Hungry Nether Ray is near the creature when it dies ');
-- -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 3853: The Restless Dead
-- Change condition to target right entry of Reanimated Crusader
UPDATE conditions SET ConditionValue2=30202 WHERE SourceTypeOrReferenceId=13 AND SourceEntry=57806 AND ConditionTypeOrReference=31;
-- Reanimated Crusader SAI
SET @Reanimated_Crusader := 30202;
SET @CreditSpell := 57808;
SET @HolyWater := 57806;
-- ?dd SAI for Reanimated Crusader
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@Reanimated_Crusader;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@Reanimated_Crusader;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Reanimated_Crusader,0,0,1,8,0,100,1,@HolyWater,0,0,0,11,@CreditSpell,0,0,0,0,0,7,0,0,0,0,0,0,0,'Reanimated Crusader - On hit by spell Holy Water - cast Freed Crusader Soul'),
(@Reanimated_Crusader,0,1,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reanimated Crusader - link - force despawn'),
(@Reanimated_Crusader,0,2,0,0,0,100,0,1000,5000,6500,12000,11,32674,0,0,0,0,0,2,0,0,0,0,0,0,0,'Reanimated Crusader - IC - Cast Avenger"s Shield'),
(@Reanimated_Crusader,0,3,0,0,0,100,0,5000,10000,8500,20000,11,58154,0,0,0,0,0,2,0,0,0,0,0,0,0,'Reanimated Crusader - IC - Hammer of Injustice'),
(@Reanimated_Crusader,0,4,0,2,0,100,0,10,90,7000,15000,11,58153,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reanimated Crusader - On health percentage - Cast Unholy Light on self after Hammer of Injustice'),
(@Reanimated_Crusader,0,5,0,14,0,100,0,1000,20,8000,20000,11,58153,0,0,0,0,0,7,0,0,0,0,0,0,0,'Reanimated Crusader - On friendly HP deficit - Cast Unholy Light on allies');
-- -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 1421: Morridune is hostile for Alliance.
-- Morridune data from sniffs
UPDATE `creature_template` SET `gossip_menu_id`=321, `faction_A`=80, `faction_H`=80, `npcflag`=1, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768, `dynamicflags`=0 WHERE `entry`=6729; 
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 1426: Attack on Camp Narache
UPDATE `quest_template` SET `OfferRewardText`='This is quite alarming indeed! But with this information we can call on our brethren from Bloodhoof Village to help thwart the attack. You have saved the lives of many $r, $N.', `RequestItemsText`='You have a look of concern about you,$N. What news do you bring?',`RequiredRaces`=690 WHERE `Id`=24857;
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 1518: Eramas Brightblaze's attack type
-- Set proper damage school type for Eramas Brightblaze
UPDATE `creature_template` SET `dmgschool`=0 WHERE `entry` IN (24554,25550);
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 1520: Banish the Demons
DELETE FROM `creature_ai_scripts` WHERE `creature_id` IN (19973,22327,22201,22195,22204,22392,20557,22291,23322);
UPDATE `creature_template` SET `ainame`='SmartAI' WHERE `entry` IN (19973,22327,22201,22195,22204,22392,20557,22291,23322);
UPDATE `creature_template` SET `flags_extra`=130, `unit_flags`=33554432 WHERE `entry` IN (23322,23327);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (19973,22327,22201,22195,22204,22392,20557,22291,23322);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(19973,0,0,0,8,0,100,1,40825,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'On spell hit - Set phase 1'),
(19973,0,1,0,6,1,100,0,0,0,0,0,33,23327,0,0,0,0,0,16,0,0,0,0,0,0,0, 'On death in phase 1 - give quest credit'),
(20557,0,0,0,8,0,100,1,40825,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'On spell hit - Set phase 1'),
(20557,0,1,0,6,1,100,0,0,0,0,0,33,23327,0,0,0,0,0,16,0,0,0,0,0,0,0, 'On death in phase 1 - give quest credit'),
(20557,0,2,0,4,0,100,0,0,0,0,0,11,22911,0,0,0,0,0,2,0,0,0,0,0,0,0, 'On aggro - cast charge'),
(20557,0,3,0,0,0,100,0,5000,11000,20000,27000,11,36406,0,0,0,0,0,2,0,0,0,0,0,0,0,'In combat - cast breath'),
(22195,0,0,0,8,0,100,1,40825,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'On spell hit - Set phase 1'),
(22195,0,1,0,6,1,100,0,0,0,0,0,33,23327,0,0,0,0,0,16,0,0,0,0,0,0,0, 'On death in phase 1 - give quest credit'),
(22195,0,2,0,0,0,75,0,2500,7500,14000,18000,11,34017,0,0,0,0,0,2,0,0,0,0,0,0,0, 'In combat - cast rain of chaos'),
(22195,0,3,0,0,0,100,0,10100,14100,122000,130000,11,11980,0,0,0,0,0,5,0,0,0,0,0,0,0, 'In combat - cast curse of weakness'),
(22201,0,0,0,8,0,100,1,40825,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'On spell hit - Set phase 1'),
(22201,0,1,0,6,1,100,0,0,0,0,0,33,23327,0,0,0,0,0,16,0,0,0,0,0,0,0, 'On death in phase 1 - give quest credit'),
(22204,0,0,0,8,0,100,1,40825,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'On spell hit - Set phase 1'),
(22204,0,1,0,6,1,100,0,0,0,0,0,33,23327,0,0,0,0,0,16,0,0,0,0,0,0,0, 'On death in phase 1 - give quest credit'),
(22291,0,0,0,8,0,100,1,40825,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'On spell hit - Set phase 1'),
(22291,0,1,0,6,1,100,0,0,0,0,0,33,23327,0,0,0,0,0,16,0,0,0,0,0,0,0, 'On death in phase 1 - give quest credit'),
(22291,0,2,0,0,0,100,0,6300,12800,6300,12800,11,32736,0,0,0,0,0,2,0,0,0,0,0,0,0, 'In combat - cast mortal strike'),
(22327,0,0,0,8,0,100,1,40825,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'On spell hit - Set phase 1'),
(22327,0,1,0,6,1,100,0,0,0,0,0,33,23327,0,0,0,0,0,16,0,0,0,0,0,0,0, 'On death in phase 1 - give quest credit'),
(22392,0,0,0,8,0,100,1,40825,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'On spell hit - Set phase 1'),
(22392,0,1,0,6,1,100,0,0,0,0,0,33,23327,0,0,0,0,0,16,0,0,0,0,0,0,0, 'On death in phase 1 - give quest credit'),
(23322,0,0,1,54,0,100,0,0,0,0,0,11,40849,0,0,0,0,0,1,0,0,0,0,0,0,0, 'On spawn - cast portal'),
(23322,0,1,0,61,0,100,0,0,0,0,0,11,40857,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Link with 0 - cast aura');
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 1843: Old Crystalbark
UPDATE `creature_template` SET `faction_A`=16,`faction_H`=16 WHERE `entry`=32357;
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 1881: The Honored Dead
SET @GUARD := 25342;
SET @WORKER := 25343;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=45474 AND `ConditionTypeOrReference`=36;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (@GUARD,@WORKER) AND `id` IN (2,3);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUARD,0,2,3,8,0,100,0,45474,0,0,0,33,@GUARD,0,0,0,0,0,7,0,0,0,0,0,0,0,'Dead Caravan Guard - On Spellhit - Give Quest Credit'),
(@GUARD,0,3,0,61,0,100,0,0,0,0,0,41,500,0,0,0,0,0,1,0,0,0,0,0,0,0,'Dead Caravan Guard - On Spellhit - Despawn'),
(@WORKER,0,2,3,8,0,100,0,45474,0,0,0,33,@GUARD,0,0,0,0,0,7,0,0,0,0,0,0,0,'Dead Caravan Worker - On Spellhit - Give Quest Credit'),
(@WORKER,0,3,0,61,0,100,0,0,0,0,0,41,500,0,0,0,0,0,1,0,0,0,0,0,0,0,'Dead Caravan Worker - On Spellhit - Despawn');
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 2075: Bring Down Those Shields
UPDATE `creature_template` SET `ainame`='SmartAI' WHERE `entry`=24464;
DELETE FROM `smart_scripts` WHERE `entryorguid` =24464 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(24464,0,1,0,8,0,100,0,50133,0,0,0,28,43874,3,0,0,0,0,1,0,0,0,0,0,0,0,'Scourging Crystal - On Spellhit Scourging Crystal Controller - Remove Scourge Mur''gul Camp: Force Shield Arcane Purple x3 on self');
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 2077 
SET @OGUID := 6024; -- Set by TDB
DELETE FROM gameobject WHERE id IN (190284,190283,186814,186813);
INSERT INTO gameobject (guid,id,map,spawnMask,phaseMask,position_x,position_y,position_z,orientation,rotation0,rotation1,rotation2,rotation3,spawntimesecs,animprogress,state) VALUES
(@OGUID,190284,571,1,1,1595.69,-3905.33,79.7439,0.610864,0,0,0,0,5,0,1),
(@OGUID+1,190283,571,1,1,1597.4,-3903.79,79.702,0,0,0,0,0,60,100,1),
(@OGUID+2,186814,571,1,1,1597.4,-3903.79,79.702,0,0,0,0,0,60,100,1),
(@OGUID+3,186813,571,1,1,1596.3,-3904.79,79.5351,-2.67035,0,0,0,0,5,0,1);
-- SmartAI for nest and creature
UPDATE creature_template SET AIName='SmartAI' WHERE entry=24518;
UPDATE gameobject_template SET AIName='SmartGameObjectAI' WHERE `entry` IN (186814,190283);
DELETE FROM `smart_scripts` WHERE `entryorguid`=24518 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (186814,190283) AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Talonshrike
(24518,0,0,0,38,0,100,0,0,1,0,0,69,0,0,0,0,0,0,8,0,0,0,1597.4,-3903.79,79.702,0.0,'Talonshrike - On notification  - fly to nest'),
(24518,0,1,0,0,0,100,0,5000,5000,10000,12000,11,49865,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,' Talonshrike - In Combat - 5 seconds - Cast Eye Peck'),
(24518,0,2,0,0,0,100,0,3000,3000,5000,7000,11,32909,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,' Talonshrike - In Combat - 3 seonds - Cast Talon Strike'),
-- Talonshrike's Egg
(186814,1,0,0,70,0,100,0,2,0,0,0,45,0,1,0,0,0,0,11,24518,500,0,0.0,0.0,0.0,0.0,'Talonshrikes Egg - On use - Notify Talonshrike'),
(190283,1,0,0,70,0,100,0,2,0,0,0,45,0,1,0,0,0,0,11,24518,500,0,0.0,0.0,0.0,0.0,'Talonshrikes Egg - On use - Notify Talonshrike');
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 2324: Battered Hilt
SET @HC5MANREF=35073;
-- Update loot ids for(Ymirjar Deathbringer,Ymirjar Flamebearer,Ymirjar Skycaller,Ymirjar Wrathbringer,Stonespine Gargoyle) - Same as other ICC 5man hc trash
UPDATE `creature_template` SET `lootid`=100001 WHERE `entry` IN (37641,37642,37643,37644,37622);
DELETE FROM `creature_loot_template` WHERE `entry` IN (37641,37642,37643,37644,37622);
-- Add new ref to ICC 5man hc Trash Ref (0.08 percent is average of values on wowhead 4.16/52)
DELETE FROM `reference_loot_template` WHERE `entry`=@HC5MANREF AND `item` IN(50379,50380);
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(@HC5MANREF,50379,0.08,1,0,1,1), -- Alliance Battered Hilt
(@HC5MANREF,50380,0.08,1,0,1,1); -- Horde Battered Hilt
-- Conditions for Batterd hilt drop
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=10 AND `SourceGroup`=@HC5MANREF;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(10,@HC5MANREF,50379,0,0,6,0,469,0,0,0,0, '', 'Battered Hilt Must Be Alliance'),
(10,@HC5MANREF,50380,0,0,6,0,67, 0,0,0,0, '', 'Battered Hilt Must Be Horde');
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 4363: Crashin' Thrashin' Racer
UPDATE `creature_template` SET `spell1`=49297 WHERE `entry` IN (27664,40281);
UPDATE `creature_template_addon` SET `auras`='49384' WHERE `entry`=27664;
UPDATE `creature_template_addon` SET `auras`='75110' WHERE `entry`=40281;
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 5320: Fields of Grief
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=375;
DELETE FROM `smart_scripts` WHERE `entryorguid`=375 AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(375,1,0,0,70,0,100,0,2,0,0,0,70,120,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Tirisfal Pumpkin - On Use - Respawn/restock after 120s');
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 8408: ICC Trash Mobs Damage
-- Mobs before Sindragosa
UPDATE `creature_template` SET `mindmg`=422, `maxdmg`=586, `attackpower`=642, `dmg_multiplier`=10 WHERE `entry`=37532;
UPDATE `creature_template` SET `mindmg`=422, `maxdmg`=586, `attackpower`=642, `dmg_multiplier`=25 WHERE `entry`=37531;
UPDATE `creature_template` SET `mindmg`=422, `maxdmg`=586, `attackpower`=642, `dmg_multiplier`=20 WHERE `entry`=38151;
UPDATE `creature_template` SET `mindmg`=422, `maxdmg`=586, `attackpower`=642, `dmg_multiplier`=50 WHERE `entry`=38139;
-- Mobs before Dreamwalker
UPDATE `creature_template` SET `dmg_multiplier`=25 WHERE `entry` IN (37133,37134,38125,37132);
UPDATE `creature_template` SET `dmg_multiplier`=50 WHERE `entry` IN (38130,38131,38132,38133);
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 8401: Anatoly will talk
SET @SASHA := 26935;
SET @ANATOLY := 26971;
SET @HORSE := 27626;
SET @TATJANA := 27627;
SET @SPELL_SHOOT := 48815;
SET @SPELL_DART := 49134;
SET @SPELL_PING := 49135;
SET @SPELL_MOUNT_HORSE := 49138;
DELETE FROM `creature` WHERE `guid` IN (118152,118160);
DELETE FROM `creature_text` WHERE `entry` IN (@SASHA,@ANATOLY);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@SASHA,0,0,'I''m old enough to shoot beasts like you right between the eyes... at twice this distance.',12,0,100,0,0,0,'Sasha'),
(@SASHA,1,0,'Don''t you dare talk about my father, monster. He was twice the man you''ll ever be.',12,0,100,0,0,0,'Sasha'),
(@SASHA,2,0,'I''d rather be dead than be one of you! You think you''re still human? You''re... animals!',12,0,100,0,0,0,'Sasha'),
(@SASHA,3,0,'Surprise, you scum!  You''re going to tell me where my sister is or I''ll put a bucketful of truesilver bullets through your wife''s heart.',12,0,100,0,0,0,'Sasha'),
(@SASHA,4,0,'Where is Anya?',12,0,100,0,0,0,'Sasha'),
(@SASHA,5,0,'There is one last thing.  I need to know where Arugal is.',12,0,100,0,0,0,'Sasha'),
(@ANATOLY,0,0,'How old are you, lass?',12,0,100,0,0,0,'Anatoly'),
(@ANATOLY,1,0,'You won''t get away with this, you know? You''re just a kid.',12,0,100,0,0,0,'Anatoly'),
(@ANATOLY,2,0,'Your father was weak, Sasha... he didn''t have the guts to do what had to be done.',12,0,100,0,0,0,'Anatoly'),
(@ANATOLY,3,0,'We''ll all end up serving the Lich King, kid. Better this way than becoming a rotten corpse.',12,0,100,0,0,0,'Anatoly'),
(@ANATOLY,4,0,'Stop!  Do not shoot!  Do not hurt Tatjana!',12,0,100,0,0,0,'Anatoly'),
(@ANATOLY,5,0,'The brat''s held prisoner in the wolf den on the other side of the mountain.  She was to be taken to Arugal.  Are we free to go now?',12,0,100,0,0,0,'Anatoly'),
(@ANATOLY,6,0,'Forgive me, Tatjana... ',12,0,100,0,0,0,'Anatoly'),
(@ANATOLY,7,0,'Nothing you can do can compare to what Arugal can do to us!  I will tear you apart myself!',12,0,100,0,0,0,'Anatoly');
DELETE FROM `vehicle_template_accessory` WHERE `entry`=@HORSE;
INSERT INTO `vehicle_template_accessory` (`entry`,`accessory_entry`,`seat_id`,`minion`,`description`,`summontype`,`summontimer`) VALUES
(@HORSE,@TATJANA,0,0,'Tatjana''s Horse',8,30000);
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=@HORSE;
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`cast_flags`,`user_type`) VALUES
(@HORSE,@SPELL_MOUNT_HORSE,1,0);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (@SPELL_DART,@SPELL_PING);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=@SPELL_SHOOT;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,@SPELL_SHOOT,0,0,31,0,3,@ANATOLY,0,0,0,'','Spell Shoot targets Anatoly'),
(13,1,@SPELL_DART,0,0,31,0,3,@TATJANA,0,0,0,'','Spell Tranquilizer Dart targets Tatjana'),
(13,1,@SPELL_PING,0,0,31,0,3,@HORSE,0,0,0,'','Spell Tatjana Ping effect0 targets Tatjana''s Horse');
UPDATE `creature` SET `spawntimesecs`=60 WHERE `id`=@ANATOLY;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@SASHA,@ANATOLY,@TATJANA);
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@TATJANA;
UPDATE `creature_template` SET `speed_run`=1.28571, `AIName`='SmartAI' WHERE `entry`=@HORSE;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@SASHA,@ANATOLY,@HORSE,@TATJANA) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@SASHA*100,@ANATOLY*100,@ANATOLY*100+1,@ANATOLY*100+2,@ANATOLY*100+3,@ANATOLY*100+4,@HORSE*100) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@SASHA,0,0,3,38,1,100,0,0,1,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Sasha - On data set 0 1 (phase 1) - Say line'),
(@SASHA,0,1,3,38,1,100,0,0,2,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Sasha - On data set 0 2 (phase 1) - Say line'),
(@SASHA,0,2,3,38,1,100,0,0,3,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,'Sasha - On data set 0 3 (phase 1) - Say line'),
(@SASHA,0,3,0,61,1,100,0,0,0,0,0,45,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Sasha - Linked with events 0,1,2 (phase 1) - Set data 0 0'),
(@SASHA,0,4,5,38,0,100,0,0,4,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Sasha - On data set 0 4 - Set event phase 0'),
(@SASHA,0,5,0,61,0,100,0,0,0,0,0,80,@SASHA*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Sasha - On data set 0 4 - Run script'),
(@SASHA,0,6,0,25,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Sasha - On reset - Set event phase 1'),
(@ANATOLY,0,0,0,1,1,100,0,10000,20000,45000,60000,87,@ANATOLY*100+1,@ANATOLY*100+2,@ANATOLY*100+3,@ANATOLY*100+4,0,0,1,0,0,0,0,0,0,0,'Anatoly - On update OOC (phase 1) - Run random script'),
(@ANATOLY,0,1,2,38,0,100,0,0,1,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Anatoly - On data set 0 1 - Set event phase 0'),
(@ANATOLY,0,2,3,61,0,100,0,0,1,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Anatoly - On data set 0 1 - Set run'),
(@ANATOLY,0,3,0,61,0,100,0,0,0,0,0,69,1,0,0,0,0,0,8,0,0,0,4057.442,-4140.824,211.1911,0,'Anatoly - On data set 0 1 - Move to position'),
(@ANATOLY,0,4,5,34,0,100,0,0,1,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Anatoly - On movement inform - Set unit_field_bytes1 (kneel)'),
(@ANATOLY,0,5,0,61,0,100,0,0,0,0,0,80,@ANATOLY*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Anatoly - On movement inform - Run script'),
(@ANATOLY,0,6,0,25,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Anatoly - On reset - Set event phase 1'),
(@HORSE,0,0,0,11,0,100,0,0,0,0,0,28,@SPELL_MOUNT_HORSE,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tatjana''s Horse - On spawn - Remove aura Mount Tatjana''s Horse'),
(@HORSE,0,1,2,8,0,100,0,@SPELL_PING,0,0,0,2,1812,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tatjana''s Horse - On spellhit Tatjana Ping - Set faction'),
(@HORSE,0,2,3,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tatjana''s Horse - On spellhit Tatjana Ping - Stop autoattack'),
(@HORSE,0,3,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tatjana''s Horse - On spellhit Tatjana Ping - Set eventphase 1'),
(@HORSE,0,4,0,8,1,100,0,@SPELL_MOUNT_HORSE,0,0,0,80,@HORSE*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Tatjana''s Horse - On spellhit Mount Tatjana''s Horse (phase 1) - Run script'),
(@HORSE,0,5,6,40,0,100,0,19,0,0,0,28,@SPELL_MOUNT_HORSE,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tatjana''s Horse - On WP 19 reached - Remove aura Mount Tatjana''s Horse'),
(@HORSE,0,6,7,61,0,100,0,0,0,0,0,15,12330,0,0,0,0,0,21,2,0,0,0,0,0,0,'Tatjana''s Horse - On WP 19 reached - Quest credit'),
(@HORSE,0,7,8,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,9,@ANATOLY,0,30,0,0,0,0,'Tatjana''s Horse - On WP 19 reached - Set data 0 1'),
(@HORSE,0,8,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tatjana''s Horse - On WP 19 reached - Despawn'),
(@TATJANA,0,0,0,11,0,100,0,0,0,0,0,11,43671,0,0,0,0,0,9,@HORSE,0,5,0,0,0,0,'Tatjana - On respawn - Spellcast Ride Vehicle'),
(@TATJANA,0,1,2,8,0,100,0,@SPELL_DART,0,0,0,11,@SPELL_PING,2,0,0,0,0,1,0,0,0,0,0,0,0,'Tatjana - On spellhit Tranquilizer Dart - Spellcast Tatjana Ping'),
(@TATJANA,0,2,3,61,0,100,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tatjana - On spellhit Tranquilizer Dart - Set faction'),
(@TATJANA,0,3,0,61,0,100,0,0,0,0,0,18,33024,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tatjana - On spellhit Tranquilizer Dart - Set unit_flags'),
(@TATJANA,0,4,0,0,0,100,0,2000,6000,9000,12000,11,32009,0,0,0,0,0,2,0,0,0,0,0,0,0,'Tatjana - On update IC - Spellcast Cutdown'),
(@TATJANA,0,5,0,38,0,100,0,0,1,0,0,41,15000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tatjana - On data set 0 1 - Despawn after 15 seconds'),
(@SASHA*100,9,0,0,0,0,100,0,0,0,0,0,1,3,0,0,0,0,0,7,0,0,0,0,0,0,0,'Sasha script - Say line'),
(@SASHA*100,9,1,0,0,0,100,0,17000,17000,0,0,1,4,0,0,0,0,0,7,0,0,0,0,0,0,0,'Sasha script - Say line'),
(@SASHA*100,9,2,0,0,0,100,0,16700,16700,0,0,1,5,0,0,0,0,0,7,0,0,0,0,0,0,0,'Sasha script - Say line'),
(@SASHA*100,9,3,0,0,0,100,0,10700,10700,0,0,11,@SPELL_SHOOT,0,0,0,0,0,9,@ANATOLY,0,30,0,0,0,0,'Sasha script - Say line'),
(@SASHA*100,9,4,0,0,0,100,0,60000,60000,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Sasha script - Set event phase 1'),
(@SASHA*100,9,5,0,0,0,100,0,0,0,0,0,45,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Sasha script - Set data 0 0'),
(@ANATOLY*100,9,0,0,0,0,100,0,2400,2400,0,0,45,0,4,0,0,0,0,9,@SASHA,0,30,0,0,0,0,'Anatoly script 0 - Set data 0 4'),
(@ANATOLY*100,9,1,0,0,0,100,0,5000,5000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,'Anatoly script 0 - Say line'),
(@ANATOLY*100,9,2,0,0,0,100,0,16800,16800,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,'Anatoly script 0 - Say line'),
(@ANATOLY*100,9,3,0,0,0,100,0,16800,16800,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,'Anatoly script 0 - Say line'),
(@ANATOLY*100,9,4,0,0,0,100,0,5000,5000,0,0,11,47457,0,0,0,0,0,1,0,0,0,0,0,0,0,'Anatoly script 0 - Spellcast Worgen Transform - Male'),
(@ANATOLY*100,9,5,0,0,0,100,0,0,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Anatoly script 0 - Reset unit_field_bytes1'),
(@ANATOLY*100,9,6,0,0,0,100,0,500,500,0,0,5,53,0,0,0,0,0,1,0,0,0,0,0,0,0,'Anatoly script 0 - Play emote'),
(@ANATOLY*100,9,7,0,0,0,100,0,150,150,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,'Anatoly script 0 - Say line'),
(@ANATOLY*100,9,8,0,0,0,100,0,0,0,0,0,45,0,1,0,0,0,0,9,@TATJANA,0,10,0,0,0,0,'Anatoly script 0 - Set data 0 1'),
(@ANATOLY*100,9,9,0,0,0,100,0,1200,1200,0,0,69,0,0,0,0,0,0,8,0,0,0,4069.991,-4130.805,211.464,0,'Anatoly script 0 - Move to position'),
(@ANATOLY*100,9,10,0,0,0,100,0,15000,15000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Anatoly script 0 - Despawn'),
(@ANATOLY*100+1,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Anatoly script 1 - Say line'),
(@ANATOLY*100+1,9,1,0,0,0,100,0,2000,2000,0,0,45,0,1,0,0,0,0,9,@SASHA,0,20,0,0,0,0,'Anatoly script 1 - Set data 0 1'),
(@ANATOLY*100+2,9,0,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Anatoly script 2 - Say line'),
(@ANATOLY*100+2,9,1,0,0,0,100,0,3500,3500,0,0,45,0,1,0,0,0,0,9,@SASHA,0,20,0,0,0,0,'Anatoly script 2 - Set data 0 1'),
(@ANATOLY*100+3,9,0,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Anatoly script 3 - Say line'),
(@ANATOLY*100+3,9,1,0,0,0,100,0,5000,5000,0,0,45,0,2,0,0,0,0,9,@SASHA,0,20,0,0,0,0,'Anatoly script 3 - Set data 0 1'),
(@ANATOLY*100+4,9,0,0,0,0,100,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Anatoly script 4 - Say line'),
(@ANATOLY*100+4,9,1,0,0,0,100,0,5000,5000,0,0,45,0,3,0,0,0,0,9,@SASHA,0,20,0,0,0,0,'Anatoly script 4 - Set data 0 1'),
(@HORSE*100,9,0,0,0,0,100,0,500,500,0,0,53,1,@HORSE,0,0,0,0,1,0,0,0,0,0,0,0,'Tatjana''s Horse script - Start WP movement');
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 8405: A Sister's Pledge and Hour Of The Worg
SET @SASHA := 26935;
SET @ANYA := 27646;
SET @CAGE := 189977;
DELETE FROM `creature_text` WHERE `entry`=@SASHA AND `groupid` IN (6,7,8);
DELETE FROM `creature_text` WHERE `entry`=@ANYA;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@SASHA,6,0,'Anya!!  You''re all right!',12,0,100,0,0,0,'Sasha'),
(@SASHA,7,0,'Badmoon?  You mean Bloodmoon?',12,0,100,0,0,0,'Sasha'),
(@SASHA,8,0,'Don''t worry, sister... no one can hurt you now.',12,0,100,0,0,0,'Sasha'),
(@ANYA,0,0,'You won''t eat me, will you?',12,0,100,0,0,0,'Anya'),
(@ANYA,1,0,'Sister!  The mean men were going to take me to Badmoon Isle.  They wanted to turn me into one of them.',12,0,100,0,0,0,'Anya'),
(@ANYA,2,0,'That''s what I said!  Badmoon!  Sasha... don''t ever leave me again!  First they took papa, then they took you... I don''t want to be alone with them!',12,0,100,0,0,0,'Anya');

DELETE FROM `creature_ai_scripts` WHERE `creature_id` IN (@ANYA,@SASHA);
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`IN(@ANYA,@SASHA);
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=189977;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@SASHA,@ANYA) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@CAGE AND `source_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@CAGE*100,@SASHA*100+1,@ANYA*100) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Anya
(@ANYA,0,0,1,20,0,100,0,12411,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Anya - On quest A Sister''s Pledge rewarded - Say line'),
(@ANYA,0,1,2,61,0,100,0,0,0,0,0,9,0,0,0,0,0,0,13,189977,0,5,0,0,0,0,'Anya - On quest Anatoly will talk rewarded - Activate GO'),
(@ANYA,0,2,3,61,0,100,0,0,0,0,0,12,@SASHA,3,120000,0,0,0,8,0,0,0,4001.751,-4555.144,196.4673,1.719485,'Anya - On quest Anatoly will talk rewarded - Summon Sasha'),
(@ANYA,0,3,0,61,0,100,0,0,0,0,0,80,@ANYA*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Anya - On quest Anatoly will talk rewarded - Run script'),
-- Sasha
(@SASHA,0,7,0,54,0,100,0,0,0,0,0,53,1,@SASHA,0,0,0,0,1,0,0,0,0,0,0,0,'Sasha - Just summoned - Start WP movement'),
(@SASHA,0,8,9,40,0,100,0,4,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Sasha - On WP 4 reached - Set unit_field_bytes1 (kneel)'),
(@SASHA,0,9,0,61,0,100,0,0,0,0,0,80,@SASHA*100+1,2,0,0,0,0,1,0,0,0,0,0,0,0,'Sasha - On WP 4 reached - Run script'),
-- Cage
(@CAGE,1,0,0,70,0,100,0,0,0,0,0,80,@CAGE*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cage - On GO activated - Run script'),
-- CageScripts
(@CAGE*100,9,0,0,0,0,100,0,10000,10000,0,0,32,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cage script - Reset GO'),
-- SashaScripts
(@SASHA*100+1,9,0,0,0,0,100,0,1000,1000,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,'Sasha - On WP 4 reached - Say line'),
(@SASHA*100+1,9,1,0,0,0,100,0,16800,16800,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,'Sasha - On WP 4 reached - Say line'),
(@SASHA*100+1,9,2,0,0,0,100,0,16900,16900,0,0,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Sasha - On WP 4 reached - Say line'),
-- AnyaScripts
(@ANYA*100,9,0,0,0,0,100,0,1700,1700,0,0,69,0,0,0,0,0,0,8,0,0,0,3996.337,-4516.717,196.3168,0,'Anya script - Move to position'),
(@ANYA*100,9,1,0,0,0,100,0,13300,13300,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Anya script - Say line'),
(@ANYA*100,9,2,0,0,0,100,0,16800,16800,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,'Anya script - Say line'),
(@ANYA*100,9,3,0,0,0,100,0,88000,88000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Anya script - Despawn');
DELETE FROM `waypoints` WHERE `entry`=26935;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(26935,1,4002.467,-4556.807,196.4988,''),
(26935,2,4001.879,-4555.998,196.4988,''),
(26935,3,3997.248,-4525.081,195.3569,''),
(26935,4,3996.828,-4519.888,195.6831,'');
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 8404: An Experienced Guide 
-- Spawn Drom Frostgrip (29751)
DELETE FROM `creature` WHERE `id`=29751;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(42889,29751,571,1,1,26497,0,6951.327,46.35645,795.0692,2.670354,300,0,0,0,0,0,2,537165888,8);
DELETE FROM `creature_template_addon` WHERE `entry`=29751;
INSERT INTO `creature_template_addon` (`entry`,`bytes2`,`auras`) VALUES
(29751,1,'51329');
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 8382: Agmar's Hammer missing gossips
UPDATE `creature_template` SET `gossip_menu_id`=9493 WHERE `entry`=25257; -- Saurfang the Younger
UPDATE `creature_template` SET `gossip_menu_id`=9317 WHERE `entry`=26181; -- Emissary Brighthoof <Tauren Emissary>
UPDATE `creature_template` SET `gossip_menu_id`=9318 WHERE `entry`=26485; -- Orphan Matron Twinbreeze
UPDATE `creature_template` SET `gossip_menu_id`=9437 WHERE `entry`=26504; -- Soar Hawkfury <Stable Master>
UPDATE `creature_template` SET `gossip_menu_id`=9661 WHERE `entry`=26505; -- Doctor Sintar Malefious <Grand Apothecary>
UPDATE `creature_template` SET `gossip_menu_id`=9459 WHERE `entry`=26564; -- Borus Ironbender <Blacksmithing Trainer>
UPDATE `creature_template` SET `gossip_menu_id`=9456, `AIName`='SmartAI' WHERE `entry`=26581; -- Koltira Deathweaver
UPDATE `creature_template` SET `gossip_menu_id`=9432 WHERE `entry`=26618; -- Captain Gort <Kor'kron Guard Captain>
UPDATE `creature_template` SET `gossip_menu_id`=9433 WHERE `entry`=26854; -- Earthwarden Grife
UPDATE `creature_template` SET `gossip_menu_id`=9434 WHERE `entry`=26859; -- Rokhan
UPDATE `creature_template` SET `gossip_menu_id`=9465 WHERE `entry`=26979; -- Kontokanis
UPDATE `creature_template` SET `gossip_menu_id`=9487 WHERE `entry`=27267; -- Quartermaster Bartlett <Blacksmithing Supplies>
UPDATE `creature_template` SET `gossip_menu_id`=9501 WHERE `entry`=27350; -- Agent Skully <Onslaught Caretaker>
UPDATE `creature_template` SET `gossip_menu_id`=9507 WHERE `entry`=27376; -- Deathguard Schneider
UPDATE `creature_template` SET `gossip_menu_id`=9508 WHERE `entry`=27378; -- Senior Scrivener Barriga
UPDATE `creature_template` SET `gossip_menu_id`=9509 WHERE `entry`=27379; -- Engineer Burke
UPDATE `creature_template` SET `gossip_menu_id`=9510 WHERE `entry`=27381; -- Chancellor Amai
UPDATE `creature_template` SET `gossip_menu_id`=9598 WHERE `entry`=27804; -- Golluck Rockfist <Horde Ambassador>
UPDATE `creature_template` SET `gossip_menu_id`=9607, `AIName`='SmartAI' WHERE `entry`=27846; -- Junior Apothecary Lawrence
UPDATE `creature_template` SET `gossip_menu_id`=9821 WHERE `entry`=28057; -- Garmin Herzog <Stable Master>
UPDATE `creature_template` SET `gossip_menu_id`=9950 WHERE `entry`=30373; -- Elder Skywarden
UPDATE `creature_template` SET `gossip_menu_id`=10207 WHERE `entry`=32599; -- Surveyor Hansen
DELETE FROM `gossip_menu` WHERE `entry`=9317 AND `text_id`=12627;
DELETE FROM `gossip_menu` WHERE `entry`=9318 AND `text_id`=12628;
DELETE FROM `gossip_menu` WHERE `entry`=9432 AND `text_id`=12698;
DELETE FROM `gossip_menu` WHERE `entry`=9433 AND `text_id`=12699;
DELETE FROM `gossip_menu` WHERE `entry`=9434 AND `text_id`=12701;
DELETE FROM `gossip_menu` WHERE `entry`=9437 AND `text_id`=12703;
DELETE FROM `gossip_menu` WHERE `entry`=9456 AND `text_id`=12715;
DELETE FROM `gossip_menu` WHERE `entry`=9459 AND `text_id`=12718;
DELETE FROM `gossip_menu` WHERE `entry`=9465 AND `text_id`=12725;
DELETE FROM `gossip_menu` WHERE `entry`=9487 AND `text_id`=12759;
DELETE FROM `gossip_menu` WHERE `entry`=9493 AND `text_id`=12777;
DELETE FROM `gossip_menu` WHERE `entry`=9501 AND `text_id`=12795;
DELETE FROM `gossip_menu` WHERE `entry`=9507 AND `text_id`=12804;
DELETE FROM `gossip_menu` WHERE `entry`=9508 AND `text_id`=12805;
DELETE FROM `gossip_menu` WHERE `entry`=9509 AND `text_id`=12806;
DELETE FROM `gossip_menu` WHERE `entry`=9510 AND `text_id`=12808;
DELETE FROM `gossip_menu` WHERE `entry`=9598 AND `text_id`=12954;
DELETE FROM `gossip_menu` WHERE `entry`=9606 AND `text_id`=12978;
DELETE FROM `gossip_menu` WHERE `entry`=9607 AND `text_id`=12977;
DELETE FROM `gossip_menu` WHERE `entry`=9661 AND `text_id`=13089;
DELETE FROM `gossip_menu` WHERE `entry`=9950 AND `text_id`=7935;
DELETE FROM `gossip_menu` WHERE `entry`=10207 AND `text_id`=14177;
DELETE FROM `gossip_menu` WHERE `entry`=21054; -- existing value not from sniff
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(9317,12627),
(9318,12628),
(9432,12698),
(9433,12699),
(9434,12701),
(9437,12703),
(9456,12715),
(9459,12718),
(9465,12725),
(9487,12759),
(9493,12777),
(9501,12795),
(9507,12804),
(9508,12805),
(9509,12806),
(9510,12808),
(9598,12954),
(9606,12978),
(9607,12977),
(9661,13089),
(9950,7935),
(10207,14177);
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (9437,9456,9459,9487,9607) AND `id`=0;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(9437,0,0,'I wish to make use of the stables.',14,4194304,0,0,0,0,''),
(9456,0,0,'I should return to the world of shades, Koltira. Send me back.',1,1,0,0,0,0,''),
(9459,0,3,'Train me.',5,16,0,0,0,0,''),
(9487,0,1,'Let me browse your goods.',5,16,0,0,0,0,''),
(9607,0,0,'All right, I''ll take this mixture of yours.',1,1,9606,0,0,0,'');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9456;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,9456,0,0,0,9,0,12132,0,0,0,0,'','Koltira Deathweaver show gossip option if player has quest 12132'),
(15,9456,0,0,0,1,47740,0,0,1,0,0,'','Koltira Deathweaver show gossip option if player has not aura World of Shadows');
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (26581,27846) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26581,0,1,0,62,0,100,0,9456,0,0,0,11,47740,0,0,0,0,0,7,0,0,0,0,0,0,0,'Koltira Deathweaver - On gossip option select - Spellcast World of Shadows'),
(26581,0,0,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Koltira Deathweaver - On gossip option select - Close gossip'),
(27846,0,0,0,62,0,100,0,9607,0,0,0,85,49747,0,0,0,0,0,7,0,0,0,0,0,0,0,'Junior Apothecary Lawrence - On gossip option select - Invoker spellcast Create Experimental Mixture');
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 8032: Destroying the Altars
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=57853;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,57853,0,0,31,0,3,30742,0,0,0,'',"Master Summoner's Staff spell implicit target First Summoning Altar"),
(13,1,57853,0,1,31,0,3,30744,0,0,0,'',"Master Summoner's Staff spell implicit target Second Summoning Altar"),
(13,1,57853,0,2,31,0,3,30745,0,0,0,'',"Master Summoner's Staff spell implicit target Third Summoning Altar"),
(13,1,57853,0,3,31,0,3,30950,0,0,0,'',"Master Summoner's Staff spell implicit target Fourth Summoning Altar");
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 7996: Set Required races for some Argent Tournament quests
UPDATE `quest_template` SET `RequiredClasses`=32 WHERE `Id` IN(13812,13788,13863,13864,13814,13793,13813,13791,13795); -- Death Knight Only
UPDATE `quest_template` SET `RequiredClasses`=1503 WHERE `Id` IN(13809,13682,13862,13861,13811,13790,13810,13789,13794); -- non Death Knight
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 7969: Pyroblast Cinnamon Ball (37582), G.N.E.R.D.S. (37583), Soothing Spearmint Candy (37584) & Chewy Fel Taffy (37585) duration fix
UPDATE `item_template` SET `flagsCustom` = 1 WHERE `entry` IN (37582,37583,37584,37585);
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 7964: Hyperspeed Acceleration
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceGroup`=0 AND `SourceEntry`=54758;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES 
(17,0,54758,0,0,7,0,202,375,0,0,0,'','Hyperspeed Acceleration requires 375 Engineering skill');
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 7824: Missing Brewfest Vendors
-- Horde Vendor (Blix Fixwidget <Token Redeemer>) http://www.old.wowhead.com/npc=24495
DELETE FROM `npc_vendor` WHERE `entry` = 24495 AND `item` IN (37737,46707,33863,33862);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `incrtime`, `ExtendedCost`) VALUES 
(24495,0,37737,0,0,2397), -- "Brew of the Month" Club Membership Form (Horde) (200 Brewfest Tokens) http://www.old.wowhead.com/item=37737
(24495,0,46707,0,0,2275), -- Pint-Sized Pink Pachyderm (100 Brewfest Tokens) http://www.old.wowhead.com/item=46707
(24495,0,33863,0,0,2276), -- Brewfest Dress (200 Brewfest Tokens) http://www.old.wowhead.com/item=33863
(24495,0,33862,0,0,2276); -- Brewfest Regalia (200 Brewfest Tokens) http://www.old.wowhead.com/item=33862
-- Alliance Vendor (Belbi Quikswitch <Token Redeemer>) http://www.old.wowhead.com/npc=23710
DELETE FROM `npc_vendor` WHERE `entry` = 23710 AND `item` IN (46707,32233);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `incrtime`, `ExtendedCost`) VALUES 
(23710,0,46707,0,0,2275), -- Pint-Sized Pink Pachyderm (100 Brewfest Tokens) http://www.old.wowhead.com/item=46707
(23710,0,32233,0,0,0); -- Wolpertinger's Tankard http://www.old.wowhead.com/item=32233
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 7823: This One Time, When I Was Drunk... Alliance quest giver fix
UPDATE `gameobject_questrelation` SET `id`=189989 WHERE `quest`=12020;
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 7416: Twilight of the Dawn Runner 
UPDATE `smart_scripts` SET `event_type`=62, `event_param1`=7371, `comment`='Ithania - On gossip select - run timed action list' WHERE (`entryorguid`=17119 AND `source_type`=0 AND `id`=0);
UPDATE `creature_template` SET `gossip_menu_id` = 7371 WHERE `entry` = 17119;
DELETE FROM `gossip_menu` WHERE `entry`=7371 AND `text_id`=8808;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES(7371,8808);
DELETE FROM `gossip_menu_option` WHERE `menu_id`=7371 AND `id`=0;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES
(7371,0,0,'Balandar sent me to get you out of here and pick up his cargo. He is waiting for you in the Brackenwall.',1,1,0,0,0,0,NULL);
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 7301: 
DELETE FROM game_graveyard_zone WHERE ghost_zone = 719;
INSERT INTO game_graveyard_zone (id, ghost_zone, faction) VALUES
(469, 719, 0);
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 7219: The Ashenvale Hunt
UPDATE `creature_template` SET `gossip_menu_id`=4346 WHERE `entry`=12696;
DELETE FROM `gossip_menu` WHERE `entry`=4346 AND `text_id`=5529;
DELETE FROM `gossip_menu` WHERE `entry`=4381 AND `text_id`=5593;
DELETE FROM `gossip_menu` WHERE `entry`=4382 AND `text_id`=5595;
DELETE FROM `gossip_menu` WHERE `entry`=4383 AND `text_id`=5594;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(4346,5529),
(4381,5593),
(4382,5595),
(4383,5594);
DELETE FROM `gossip_menu_option` WHERE `menu_id`=4346 AND `id` IN (0,1,2);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(4346,0,0,"What can you tell to me about the bear - Ursangous?",1,1,4381,0,0,0,NULL),
(4346,1,0,"What can you tell to me about the nightsaber cat - Shadumbra?",1,1,4383,0,0,0,NULL),
(4346,2,0,"What can you tell to me about the hippogryph - Sharptalon?",1,1,4382,0,0,0,NULL);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=4346;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceGroup`=0 AND `SourceEntry`=247;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,4346,0,0,0,8,0,6383,0,0,0,0,'',"Show gossip only if The Ashenvale Hunt (6383) quest is rewarded"),
(15,4346,0,0,0,8,0,23,0,0,1,0,'',"Show gossip only if Ursangous's Paw (23) quest is not rewarded"),
(15,4346,1,0,0,8,0,6383,0,0,0,0,'',"Show gossip only if The Ashenvale Hunt (6383) quest is rewarded"),
(15,4346,1,0,0,8,0,24,0,0,1,0,'',"Show gossip only if Shadumbra's Head (24) quest is not rewarded"),
(15,4346,2,0,0,8,0,6383,0,0,0,0,'',"Show gossip only if The Ashenvale Hunt (6383) quest is rewarded"),
(15,4346,2,0,0,8,0,2,0,0,1,0,'',"Show gossip only if Sharptalon's Claw (2) quest is not rewarded"),
-- Quest The Hunt Completed (247) should only be available once Sharptalon's Claw (2), Ursangous's Paw (23) and Shadumbra's Head (24) quests are rewarded.
(19,0,247,0,1,8,0,2,0,0,0,0,'',"Show quest only if Sharptalon's Claw (2) quest is rewarded AND"),
(19,0,247,0,1,8,0,23,0,0,0,0,'',"Show quest only if Ursangous's Paw (23) quest is rewarded AND"),
(19,0,247,0,1,8,0,24,0,0,0,0,'',"Show quest only if Shadumbra's Head (24) quest is rewarded AND");
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 7079: Corporal Thund Splithoof
DELETE FROM `gossip_menu_option` WHERE (`menu_id`=840 AND `id`=2);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES
(840, 2, 0, 'Hero, I have urgent business with Corporal Splithoof.', 1, 3, 0, 0, 0, 0, ''); -- 7572
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 7155: Aleric Hawkins
DELETE FROM `creature` WHERE `id`=36517;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(43466,36517,0,1,1,0,0,1283,338.9167,-59.9998,0.2443461,120,0,0,1,0,0,0,0,0);
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 7011: Inactive Fel Reaver
DELETE FROM `creature_ai_scripts` WHERE (`creature_id`=22293);
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 22293;
DELETE FROM `smart_scripts` WHERE (`entryorguid`=22293 AND `source_type`=0);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(22293,0,0,0,11,0,100,1,0,0,0,0,11,38757,0,0,0,0,0,1,0,0,0,0,0,0,0,'Inactive Fel Reaver Cast - Fel Reaver Freeze on Self');
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 6959: There Is No Hope
UPDATE `quest_template` SET `Flags`=262282,`RewardItemId1`=28168,`RewardItemCount1`=1,`RewardChoiceItemId1`=28173,`RewardChoiceItemId2`=28169,`RewardChoiceItemId3`=28172,`RewardChoiceItemId4`=28175,`RewardChoiceItemCount1`=1,`RewardChoiceItemCount2`=1,`RewardChoiceItemCount3`=1,`RewardChoiceItemCount4`=1 WHERE `Id`=10172;
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 6212: Merciful Freedom
UPDATE `gameobject_template` SET AIName='SmartGameObjectAI', data2=0, ScriptName='' WHERE `entry` BETWEEN 187854 AND 187868;
UPDATE `gameobject_template` SET AIName='SmartGameObjectAI', data2=0, ScriptName='' WHERE `entry` BETWEEN 187870 AND 187874;
SET @Scourge_Cage :=187854;

DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN 187854 AND 187868;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN 187870 AND 187874;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (18785400,18785500,18785600,18785700,18785800,18785900,18786000,18786100,18786200,18786300,18786400,18786500,18786600,18786700,18786800,18787000,18787100,18787200,18787300,18787400);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- 187854
(@Scourge_Cage,1,0,1,70,0,100,0,2,0,0,0,33,25610,0,0,0,0,0,7,0,0,0,0,0,0,0,'Scourge Cage - Activated - Credit'),
(@Scourge_Cage,1,1,2,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,25610,5,0,0,0,0,0,'Scourge Cage - Linked - Set Data To Scourge Prisoner'),
(@Scourge_Cage,1,2,0,61,0,100,0,0,0,0,0,80,@Scourge_Cage*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Linked - Run Script'),
(@Scourge_Cage*100,9,0,0,0,0,100,0,65000,65000,65000,65000,32,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Script - Reset GameObject'),
-- 187855
(@Scourge_Cage+1,1,0,1,70,0,100,0,2,0,0,0,33,25610,0,0,0,0,0,7,0,0,0,0,0,0,0,'Scourge Cage - Activated - Credit'),
(@Scourge_Cage+1,1,1,2,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,25610,5,0,0,0,0,0,'Scourge Cage - Linked - Set Data To Scourge Prisoner'),
(@Scourge_Cage+1,1,2,0,61,0,100,0,0,0,0,0,80,(@Scourge_Cage+1)*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Linked - Run Script'),
((@Scourge_Cage+1)*100,9,0,0,0,0,100,0,65000,65000,65000,65000,32,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Script - Reset GameObject'),
-- 187856
(@Scourge_Cage+2,1,0,1,70,0,100,0,2,0,0,0,33,25610,0,0,0,0,0,7,0,0,0,0,0,0,0,'Scourge Cage - Activated - Credit'),
(@Scourge_Cage+2,1,1,2,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,25610,5,0,0,0,0,0,'Scourge Cage - Linked - Set Data To Scourge Prisoner'),
(@Scourge_Cage+2,1,2,0,61,0,100,0,0,0,0,0,80,(@Scourge_Cage+2)*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Linked - Run Script'),
((@Scourge_Cage+2)*100,9,0,0,0,0,100,0,65000,65000,65000,65000,32,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Script - Reset GameObject'),
-- 187857
(@Scourge_Cage+3,1,0,1,70,0,100,0,2,0,0,0,33,25610,0,0,0,0,0,7,0,0,0,0,0,0,0,'Scourge Cage - Activated - Credit'),
(@Scourge_Cage+3,1,1,2,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,25610,5,0,0,0,0,0,'Scourge Cage - Linked - Set Data To Scourge Prisoner'),
(@Scourge_Cage+3,1,2,0,61,0,100,0,0,0,0,0,80,(@Scourge_Cage+3)*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Linked - Run Script'),
((@Scourge_Cage+3)*100,9,0,0,0,0,100,0,65000,65000,65000,65000,32,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Script - Reset GameObject'),
-- 187858
(@Scourge_Cage+4,1,0,1,70,0,100,0,2,0,0,0,33,25610,0,0,0,0,0,7,0,0,0,0,0,0,0,'Scourge Cage - Activated - Credit'),
(@Scourge_Cage+4,1,1,2,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,25610,5,0,0,0,0,0,'Scourge Cage - Linked - Set Data To Scourge Prisoner'),
(@Scourge_Cage+4,1,2,0,61,0,100,0,0,0,0,0,80,(@Scourge_Cage+4)*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Linked - Run Script'),
((@Scourge_Cage+4)*100,9,0,0,0,0,100,0,65000,65000,65000,65000,32,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Script - Reset GameObject'),
-- 187859
(@Scourge_Cage+5,1,0,1,70,0,100,0,2,0,0,0,33,25610,0,0,0,0,0,7,0,0,0,0,0,0,0,'Scourge Cage - Activated - Credit'),
(@Scourge_Cage+5,1,1,2,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,25610,5,0,0,0,0,0,'Scourge Cage - Linked - Set Data To Scourge Prisoner'),
(@Scourge_Cage+5,1,2,0,61,0,100,0,0,0,0,0,80,(@Scourge_Cage+5)*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Linked - Run Script'),
((@Scourge_Cage+5)*100,9,0,0,0,0,100,0,65000,65000,65000,65000,32,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Script - Reset GameObject'),
-- 187860
(@Scourge_Cage+6,1,0,1,70,0,100,0,2,0,0,0,33,25610,0,0,0,0,0,7,0,0,0,0,0,0,0,'Scourge Cage - Activated - Credit'),
(@Scourge_Cage+6,1,1,2,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,25610,5,0,0,0,0,0,'Scourge Cage - Linked - Set Data To Scourge Prisoner'),
(@Scourge_Cage+6,1,2,0,61,0,100,0,0,0,0,0,80,(@Scourge_Cage+6)*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Linked - Run Script'),
((@Scourge_Cage+6)*100,9,0,0,0,0,100,0,65000,65000,65000,65000,32,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Script - Reset GameObject'),
-- 187861 
(@Scourge_Cage+7,1,0,1,70,0,100,0,2,0,0,0,33,25610,0,0,0,0,0,7,0,0,0,0,0,0,0,'Scourge Cage - Activated - Credit'),
(@Scourge_Cage+7,1,1,2,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,25610,5,0,0,0,0,0,'Scourge Cage - Linked - Set Data To Scourge Prisoner'),
(@Scourge_Cage+7,1,2,0,61,0,100,0,0,0,0,0,80,(@Scourge_Cage+7)*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Linked - Run Script'),
((@Scourge_Cage+7)*100,9,0,0,0,0,100,0,65000,65000,65000,65000,32,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Script - Reset GameObject'),
-- 187862
(@Scourge_Cage+8,1,0,1,70,0,100,0,2,0,0,0,33,25610,0,0,0,0,0,7,0,0,0,0,0,0,0,'Scourge Cage - Activated - Credit'),
(@Scourge_Cage+8,1,1,2,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,25610,5,0,0,0,0,0,'Scourge Cage - Linked - Set Data To Scourge Prisoner'),
(@Scourge_Cage+8,1,2,0,61,0,100,0,0,0,0,0,80,(@Scourge_Cage+8)*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Linked - Run Script'),
((@Scourge_Cage+8)*100,9,0,0,0,0,100,0,65000,65000,65000,65000,32,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Script - Reset GameObject'),
-- 187863
(@Scourge_Cage+9,1,0,1,70,0,100,0,2,0,0,0,33,25610,0,0,0,0,0,7,0,0,0,0,0,0,0,'Scourge Cage - Activated - Credit'),
(@Scourge_Cage+9,1,1,2,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,25610,5,0,0,0,0,0,'Scourge Cage - Linked - Set Data To Scourge Prisoner'),
(@Scourge_Cage+9,1,2,0,61,0,100,0,0,0,0,0,80,(@Scourge_Cage+9)*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Linked - Run Script'),
((@Scourge_Cage+9)*100,9,0,0,0,0,100,0,65000,65000,65000,65000,32,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Script - Reset GameObject'),
-- 187864
(@Scourge_Cage+10,1,0,1,70,0,100,0,2,0,0,0,33,25610,0,0,0,0,0,7,0,0,0,0,0,0,0,'Scourge Cage - Activated - Credit'),
(@Scourge_Cage+10,1,1,2,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,25610,5,0,0,0,0,0,'Scourge Cage - Linked - Set Data To Scourge Prisoner'),
(@Scourge_Cage+10,1,2,0,61,0,100,0,0,0,0,0,80,(@Scourge_Cage+10)*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Linked - Run Script'),
((@Scourge_Cage+10)*100,9,0,0,0,0,100,0,65000,65000,65000,65000,32,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Script - Reset GameObject'),
-- 187865
(@Scourge_Cage+11,1,0,1,70,0,100,0,2,0,0,0,33,25610,0,0,0,0,0,7,0,0,0,0,0,0,0,'Scourge Cage - Activated - Credit'),
(@Scourge_Cage+11,1,1,2,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,25610,5,0,0,0,0,0,'Scourge Cage - Linked - Set Data To Scourge Prisoner'),
(@Scourge_Cage+11,1,2,0,61,0,100,0,0,0,0,0,80,(@Scourge_Cage+11)*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Linked - Run Script'),
((@Scourge_Cage+11)*100,9,0,0,0,0,100,0,65000,65000,65000,65000,32,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Script - Reset GameObject'),
-- 187866
(@Scourge_Cage+12,1,0,1,70,0,100,0,2,0,0,0,33,25610,0,0,0,0,0,7,0,0,0,0,0,0,0,'Scourge Cage - Activated - Credit'),
(@Scourge_Cage+12,1,1,2,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,25610,5,0,0,0,0,0,'Scourge Cage - Linked - Set Data To Scourge Prisoner'),
(@Scourge_Cage+12,1,2,0,61,0,100,0,0,0,0,0,80,(@Scourge_Cage+12)*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Linked - Run Script'),
((@Scourge_Cage+12)*100,9,0,0,0,0,100,0,65000,65000,65000,65000,32,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Script - Reset GameObject'),
-- 187867
(@Scourge_Cage+13,1,0,1,70,0,100,0,2,0,0,0,33,25610,0,0,0,0,0,7,0,0,0,0,0,0,0,'Scourge Cage - Activated - Credit'),
(@Scourge_Cage+13,1,1,2,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,25610,5,0,0,0,0,0,'Scourge Cage - Linked - Set Data To Scourge Prisoner'),
(@Scourge_Cage+13,1,2,0,61,0,100,0,0,0,0,0,80,(@Scourge_Cage+13)*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Linked - Run Script'),
((@Scourge_Cage+13)*100,9,0,0,0,0,100,0,65000,65000,65000,65000,32,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Script - Reset GameObject'),
-- 187868
(@Scourge_Cage+14,1,0,1,70,0,100,0,2,0,0,0,33,25610,0,0,0,0,0,7,0,0,0,0,0,0,0,'Scourge Cage - Activated - Credit'),
(@Scourge_Cage+14,1,1,2,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,25610,5,0,0,0,0,0,'Scourge Cage - Linked - Set Data To Scourge Prisoner'),
(@Scourge_Cage+14,1,2,0,61,0,100,0,0,0,0,0,80,(@Scourge_Cage+14)*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Linked - Run Script'),
((@Scourge_Cage+14)*100,9,0,0,0,0,100,0,65000,65000,65000,65000,32,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Script - Reset GameObject'),
-- 187870
(@Scourge_Cage+16,1,0,1,70,0,100,0,2,0,0,0,33,25610,0,0,0,0,0,7,0,0,0,0,0,0,0,'Scourge Cage - Activated - Credit'),
(@Scourge_Cage+16,1,1,2,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,25610,5,0,0,0,0,0,'Scourge Cage - Linked - Set Data To Scourge Prisoner'),
(@Scourge_Cage+16,1,2,0,61,0,100,0,0,0,0,0,80,(@Scourge_Cage+16)*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Linked - Run Script'),
((@Scourge_Cage+16)*100,9,0,0,0,0,100,0,65000,65000,65000,65000,32,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Script - Reset GameObject'),
-- 187871
(@Scourge_Cage+17,1,0,1,70,0,100,0,2,0,0,0,33,25610,0,0,0,0,0,7,0,0,0,0,0,0,0,'Scourge Cage - Activated - Credit'),
(@Scourge_Cage+17,1,1,2,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,25610,5,0,0,0,0,0,'Scourge Cage - Linked - Set Data To Scourge Prisoner'),
(@Scourge_Cage+17,1,2,0,61,0,100,0,0,0,0,0,80,(@Scourge_Cage+17)*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Linked - Run Script'),
((@Scourge_Cage+17)*100,9,0,0,0,0,100,0,65000,65000,65000,65000,32,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Script - Reset GameObject'),
-- 187872
(@Scourge_Cage+18,1,0,1,70,0,100,0,2,0,0,0,33,25610,0,0,0,0,0,7,0,0,0,0,0,0,0,'Scourge Cage - Activated - Credit'),
(@Scourge_Cage+18,1,1,2,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,25610,5,0,0,0,0,0,'Scourge Cage - Linked - Set Data To Scourge Prisoner'),
(@Scourge_Cage+18,1,2,0,61,0,100,0,0,0,0,0,80,(@Scourge_Cage+18)*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Linked - Run Script'),
((@Scourge_Cage+18)*100,9,0,0,0,0,100,0,65000,65000,65000,65000,32,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Script - Reset GameObject'),
-- 187873
(@Scourge_Cage+19,1,0,1,70,0,100,0,2,0,0,0,33,25610,0,0,0,0,0,7,0,0,0,0,0,0,0,'Scourge Cage - Activated - Credit'),
(@Scourge_Cage+19,1,1,2,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,25610,5,0,0,0,0,0,'Scourge Cage - Linked - Set Data To Scourge Prisoner'),
(@Scourge_Cage+19,1,2,0,61,0,100,0,0,0,0,0,80,(@Scourge_Cage+19)*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Linked - Run Script'),
((@Scourge_Cage+19)*100,9,0,0,0,0,100,0,65000,65000,65000,65000,32,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Script - Reset GameObject'),
-- 187874
(@Scourge_Cage+20,1,0,1,70,0,100,0,2,0,0,0,33,25610,0,0,0,0,0,7,0,0,0,0,0,0,0,'Scourge Cage - Activated - Credit'),
(@Scourge_Cage+20,1,1,2,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,25610,5,0,0,0,0,0,'Scourge Cage - Linked - Set Data To Scourge Prisoner'),
(@Scourge_Cage+20,1,2,0,61,0,100,0,0,0,0,0,80,(@Scourge_Cage+20)*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Linked - Run Script'),
((@Scourge_Cage+20)*100,9,0,0,0,0,100,0,65000,65000,65000,65000,32,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Script - Reset GameObject');
UPDATE `creature` SET spawntimesecs=0 WHERE id IN(25610);
UPDATE `creature_template` SET AIName='SmartAI', ScriptName='', unit_flags=768 WHERE entry IN(25610);
DELETE FROM `smart_scripts` WHERE entryorguid IN(25610);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25610,0,0,0,10,0,100,0,1,15,15000,30000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Prisoner - Range - Say 0'),
(25610,0,1,0,38,0,100,0,1,1,0,0,1,1,5000,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Prisoner - Data Set - Say 1'),
(25610,0,2,3,52,0,100,0,1,25610,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Prisoner - Data Set - Unseen'),
(25610,0,3,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Prisoner - Linked - Desapwn');
DELETE FROM `conditions` WHERE SourceTypeOrReferenceId=22 AND SourceEntry=25610;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 25610, 0, 0, 9, 0, 11676, 0, 0, 1, 0, '', 'SAI - Help Text Only if Player in Range Have No Quest');
DELETE FROM `creature_text` WHERE entry IN(25610);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(25610, 0, 0, "Don't let them turn me into one of those aberrations!", 12, 0, 100, 1, 0, 0, 'Scourge Prisoner'),
(25610, 0, 1, "Kill me... Kill me now!", 12, 0, 100, 1, 0, 0, 'Scourge Prisoner'),
(25610, 0, 2, "Somebody please... Help...", 12, 0, 100, 1, 0, 0, 'Scourge Prisoner'),
(25610, 0, 3, "Don't let them turn me into one of those aberrations!", 12, 0, 100, 1, 0, 0, 'Scourge Prisoner'),
(25610, 1, 0, "Freedom at last! I must return to Warsong Hold at once!", 12, 0, 100, 1, 0, 0, 'Scourge Prisoner'),
(25610, 1, 1, "I am forever indebted to you, friend.", 12, 0, 100, 1, 0, 0, 'Scourge Prisoner'),
(25610, 1, 2, "Thank you, friend.", 12, 0, 100, 1, 0, 0, 'Scourge Prisoner'),
(25610, 1, 3, "You have my thanks, stranger.", 12, 0, 100, 1, 0, 0, 'Scourge Prisoner');
-- STARTUP FIXES:
DELETE FROM `creature_addon` WHERE `guid`=113585;
UPDATE `creature` SET `spawndist`=0 WHERE `guid`=109406;

-- Darnassus Sentinel
UPDATE `creature_template` SET `gossip_menu_id`=2352 WHERE `entry`=4262;

-- Creature Gossip_menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=2352 AND `text_id`=3016;
DELETE FROM `gossip_menu` WHERE `entry`=2323 AND `text_id`=3018;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(2352, 3016),(2323, 3018);

-- Creature Gossip_menu_option
DELETE FROM `gossip_menu_option` WHERE (`menu_id`=2352 AND `id`=0) OR (`menu_id`=2352 AND `id`=1) OR (`menu_id`=2352 AND `id`=2) OR (`menu_id`=2352 AND `id`=3) OR (`menu_id`=2352 AND `id`=4) OR (`menu_id`=2352 AND `id`=5) OR (`menu_id`=2352 AND `id`=6) OR (`menu_id`=2352 AND `id`=7) OR (`menu_id`=2352 AND `id`=8) OR (`menu_id`=2352 AND `id`=9) OR (`menu_id`=2352 AND `id`=10) OR (`menu_id`=2352 AND `id`=11);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES
(2352, 0, 0, 'Auction House', 1, 1, 3101, 89, 0, 0, ''),
(2352, 1, 0, 'The Bank', 1, 1, 2322, 90, 0, 0, ''),
(2352, 2, 0, 'Hippogryph Master', 1, 1, 2323, 91, 0, 0, ''),
(2352, 3, 0, 'Guild Master', 1, 1, 2324, 92, 0, 0, ''),
(2352, 4, 0, 'The Inn', 1, 1, 2325, 93, 0, 0, ''),
(2352, 5, 0, 'Mailbox', 1, 1, 2326, 94, 0, 0, ''),
(2352, 6, 0, 'Stable Master', 1, 1, 4921, 95, 0, 0, ''),
(2352, 7, 0, 'Weapons Trainer', 1, 1, 3722, 96, 0, 0, ''),
(2352, 8, 0, 'Battlemaster', 1, 1, 8221, 97, 0, 0, ''),
(2352, 9, 0, 'Class Trainer', 1, 1, 2343, 0, 0, 0, ''),
(2352, 10, 0, 'Profession Trainer', 1, 1, 2351, 0, 0, 0, ''),
(2352, 11, 0, 'Lexicon of Power', 1, 1, 10205, 107, 0, 0, '');

-- fix possible chaining issue, remove quest_start_script
UPDATE `quest_template` SET `NextQuestId`=4024,`StartScript`=0 WHERE `Id`=4023;
DELETE FROM `quest_start_scripts` WHERE `id`=4023;
-- Already done in cpp, can be removed
UPDATE `quest_template` SET `StartScript`=0 WHERE `Id` IN (6482,9686,11300); 
DELETE FROM `quest_start_scripts` WHERE `id` IN (6482,9686,11300); 
-- there is no need for external requirement in this case
UPDATE `quest_template` SET `StartScript`=0 WHERE `Id`=10162;
DELETE FROM `quest_start_scripts` WHERE `id`=10162;
-- Change cast spell after 0s to cast on accept (same thing, different table)
UPDATE `quest_template` SET `SourceSpellId`=25201,`StartScript`=0 WHERE `Id`=8305;
DELETE FROM `quest_start_scripts` WHERE `id`=8305;
-- convert quest_start_scripts into SAI;
DELETE FROM `quest_start_scripts` WHERE `id`=2701;
UPDATE `quest_template` SET `StartScript`=0 WHERE `Id`=2701;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=7750;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7750 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(7750,0,0,0,19,0,100,0,2701,0,0,0,70,0,0,0,0,0,0,14,44732,141981,0,0,0,0,0, 'Corporal Thund Splithoof - On Quest Accept - Respawn Spectral Lockbox Particles (GO)'),
(7750,0,1,0,19,0,100,0,2701,0,0,0,70,0,0,0,0,0,0,14,44733,141980,0,0,0,0,0, 'Corporal Thund Splithoof - On Quest Accept - Respawn Spectral Lockbox (GO)');
-- BEWARE: THIS (TEMP) REMOVES SUPPORT FOR QUESTS 434,10985,11108,11198!
DELETE FROM `quest_start_scripts` WHERE `id` IN (434,10985,11108,11198);
UPDATE `quest_template` SET `StartScript`=0 WHERE `Id` IN (434,10985,11108,11198);
DELETE FROM `db_script_string` WHERE `entry` IN (2000000033,2000000034,2000000035,2000000036,2000000037,2000000038,2000000039,2000000040,2000000041);
-- ----------------------------------
-- Creature text conversion part 2 --
-- ----------------------------------
-- razorgore
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1469025 AND -1469022;
DELETE FROM `creature_text` WHERE `entry`=12435;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(12435,0,0,14,8275,100,"razorgore SAY_EGGS_BROKEN1","You'll pay for forcing me to do this."),
(12435,1,0,14,8276,100,"razorgore SAY_EGGS_BROKEN2","Fools! These eggs are more precious than you know."),
(12435,2,0,14,8277,100,"razorgore SAY_EGGS_BROKEN3","No! Not another one! I'll have your heads for this atrocity."),
(12435,3,0,14,8278,100,"razorgore SAY_DEATH","If I fall into the abyss I'll take all of you mortals with me...");

-- nefarian
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1469021 AND -1469007;
DELETE FROM `creature_text` WHERE `entry`=11583;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(11583,0,0,14,8288,100,"nefarian SAY_AGGRO","Well done, my minions. The mortals' courage begins to wane! Now, let's see how they contend with the true Lord of Blackrock Spire!"),
(11583,0,1,14,8289,100,"nefarian SAY_XHEALTH","Enough! Now you vermin shall feel the force of my birthright, the fury of the earth itself."),
(11583,0,2,14,8290,100,"nefarian SAY_SHADOWFLAME","Burn, you wretches! Burn!"),
(11583,1,0,14,8291,100,"nefarian SAY_RAISE_SKELETONS","Impossible! Rise my minions! Serve your master once more!"),
(11583,2,0,14,8293,100,"nefarian SAY_SLAY","Worthless $N! Your friends will join you soon enough!"),
(11583,3,0,14,8292,100,"nefarian SAY_DEATH","This cannot be! I am the Master here! You mortals are nothing to my kind! DO YOU HEAR? NOTHING!"),
(11583,4,0,14,0,100,"nefarian SAY_MAGE","Mages too? You should be more careful when you play with magic..."),
(11583,5,0,14,0,100,"nefarian SAY_WARRIOR","Warriors, I know you can hit harder than that! Let's see it!"),
(11583,6,0,14,0,100,"nefarian SAY_DRUID","Druids and your silly shapeshifting. Let's see it in action!"),
(11583,7,0,14,0,100,"nefarian SAY_PRIEST","Priests! If you're going to keep healing like that, we might as well make it a little more interesting!"),
(11583,8,0,14,0,100,"nefarian SAY_PALADIN","Paladins, I've heard you have many lives. Show me."),
(11583,9,0,14,0,100,"nefarian SAY_SHAMAN","Shamans, show me what your totems can do!"),
(11583,10,0,14,0,100,"nefarian SAY_WARLOCK","Warlocks, you shouldn't be playing with magic you don't understand. See what happens?"),
(11583,11,0,14,0,100,"nefarian SAY_HUNTER","Hunters and your annoying pea-shooters!"),
(11583,12,0,14,0,100,"nefarian SAY_ROGUE","Rogues? Stop hiding and face me!");

-- broodlord
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1469001 AND -1469000;
DELETE FROM `creature_text` WHERE `entry`=12017;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(12017,0,0,14,8286,100,"broodlord SAY_AGGRO","None of your kind should be here! You've doomed only yourselves!"),
(12017,1,0,14,8287,100,"broodlord SAY_LEASH","Clever Mortals but I am not so easily lured away from my sanctum!");

-- flamegor
DELETE FROM `script_texts` WHERE `entry`=-1469031;
DELETE FROM `creature_text` WHERE `entry`=11981;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(11981,0,0,16,0,100,"flamegor EMOTE_FRENZY","%s goes into a frenzy!");

-- chromaggus
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1469003 AND -1469002;
DELETE FROM `creature_text` WHERE `entry`=14020;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(14020,0,0,16,0,100,"chromaggus EMOTE_FRENZY","goes into a killing frenzy!"),
(14020,1,0,16,0,100,"chromaggus EMOTE_SHIMMER","flinches as its skin shimmers.");

-- vaelastrasz
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1469030 AND -1469026;
DELETE FROM `creature_text` WHERE `entry`=13020;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(13020,0,0,14,8281,100,"vaelastrasz SAY_LINE1","Too late...friends. Nefarius' corruption has taken hold. I cannot...control myself."),
(13020,1,0,14,8282,100,"vaelastrasz SAY_LINE2","I beg you Mortals, flee! Flee before I lose all control. The Black Fire rages within my heart. I must release it!"),
(13020,2,0,14,8283,100,"vaelastrasz SAY_LINE3","FLAME! DEATH! DESTRUCTION! COWER MORTALS BEFORE THE WRATH OF LORD....NO! I MUST FIGHT THIS!"),
(13020,3,0,14,8285,100,"vaelastrasz SAY_HALFLIFE","Nefarius' hate has made me stronger than ever before. You should have fled, while you could, mortals! The fury of Blackrock courses through my veins!"),
(13020,4,0,14,8284,100,"vaelastrasz SAY_KILLTARGET","Forgive me $N, your death only adds to my failure.");

-- doctor theolen krastinov
-- No delete query here, it's a generic script text for frenzy emotes.
DELETE FROM `creature_text` WHERE `entry`=11261;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(11261,0,0,16,0,100,"doctor theolen krastinov EMOTE_FRENZY_KILL","%s goes into a killing frenzy!");

-- vectus
-- No delete query here, it's a generic script text for frenzy emotes.
DELETE FROM `creature_text` WHERE `entry`=10432;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(10432,0,0,16,0,100,"vectus EMOTE_FRENZY_KILL","%s goes into a killing frenzy!");

-- galen
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000506 AND -1000500;
DELETE FROM `creature_text` WHERE `entry`=5391;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(5391,0,0,12,0,100,"galen SAY_PERIODIC","Help! Please, You must help me!"),
(5391,1,0,12,0,100,"galen SAY_QUEST_ACCEPTED","Let us leave this place."),
(5391,2,0,12,0,100,"galen SAY_ATTACKED_1","Look out! The $c attacks!"),
(5391,2,1,12,0,100,"galen SAY_ATTACKED_2","Help! I'm under attack!"),
(5391,3,0,12,0,100,"galen SAY_QUEST_COMPLETE","Thank you $N. I will remember you always. You can find my strongbox in my camp, north of Stonard."),
(5391,4,0,16,0,100,"galen EMOTE_WHISPER","%s whispers to $N the secret to opening his strongbox."),
(5391,5,0,16,0,100,"galen EMOTE_DISAPPEAR","%s disappears into the swamp.");

-- smite
DELETE FROM `script_texts` WHERE `entry`=-1036001;
DELETE FROM `creature_text` WHERE `entry`=646;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(646,0,0,14,5777,100,"smite SAY_AGGRO","We're under attack! A vast, ye swabs! Repel the invaders!");

-- crusader
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1609519 AND -1609501;
DELETE FROM `creature_text` WHERE `entry` IN (28939,28610,28940);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
-- Scarlet Preacher
(28939,1,0,12,0,100,"crusader SAY_CRUSADER1","You'll be hanging in the gallows shortly, Scourge fiend!"),
(28939,1,1,12,0,100,"crusader SAY_CRUSADER2","You'll have to kill me, monster! I will tell you NOTHING!"),
(28939,1,2,12,0,100,"crusader SAY_CRUSADER3","You hit like a girl. Honestly. Is that the best you can do?"),
(28939,1,3,12,0,100,"crusader SAY_CRUSADER4","ARGH! You burned my last good tabard!"),
(28939,1,4,12,0,100,"crusader SAY_CRUSADER5","Argh... The pain... The pain is almost as unbearable as the lashings I received in grammar school when I was but a child."),
(28939,1,5,12,0,100,"crusader SAY_CRUSADER6","I used to work for Grand Inquisitor Isillien! Your idea of pain is a normal mid-afternoon for me!"),
(28939,2,0,12,0,100,"break crusader SAY_PERSUADED1","I'll tell you everything! STOP! PLEASE!"),
(28939,3,0,12,0,100,"break crusader SAY_PERSUADED2","We... We have only been told that the \"Crimson Dawn\" is an awakening. You see, the Light speaks to the High General. It is the Light..."),
(28939,4,0,12,0,100,"break crusader SAY_PERSUADED3","The Light that guides us. The movement was set in motion before you came... We... We do as we are told. It is what must be done."),
(28939,5,0,12,0,100,"break crusader SAY_PERSUADED4","I know very little else... The High General chooses who may go and who must stay behind. There's nothing else... You must believe me!"),
(28939,6,0,12,0,100,"break crusader SAY_PERSUADED6","NO! PLEASE! There is one more thing that I forgot to mention... A courier comes soon... From Hearthglen. It..."),
-- Scarlet Crusader
(28940,1,0,12,0,100,"crusader SAY_CRUSADER1","You'll be hanging in the gallows shortly, Scourge fiend!"),
(28940,1,1,12,0,100,"crusader SAY_CRUSADER2","You'll have to kill me, monster! I will tell you NOTHING!"),
(28940,1,2,12,0,100,"crusader SAY_CRUSADER3","You hit like a girl. Honestly. Is that the best you can do?"),
(28940,1,3,12,0,100,"crusader SAY_CRUSADER4","ARGH! You burned my last good tabard!"),
(28940,1,4,12,0,100,"crusader SAY_CRUSADER5","Argh... The pain... The pain is almost as unbearable as the lashings I received in grammar school when I was but a child."),
(28940,1,5,12,0,100,"crusader SAY_CRUSADER6","I used to work for Grand Inquisitor Isillien! Your idea of pain is a normal mid-afternoon for me!"),
(28940,2,0,12,0,100,"break crusader SAY_PERSUADED1","I'll tell you everything! STOP! PLEASE!"),
(28940,3,0,12,0,100,"break crusader SAY_PERSUADED2","We... We have only been told that the \"Crimson Dawn\" is an awakening. You see, the Light speaks to the High General. It is the Light..."),
(28940,4,0,12,0,100,"break crusader SAY_PERSUADED3","The Light that guides us. The movement was set in motion before you came... We... We do as we are told. It is what must be done."),
(28940,5,0,12,0,100,"break crusader SAY_PERSUADED4","I know very little else... The High General chooses who may go and who must stay behind. There's nothing else... You must believe me!"),
(28940,6,0,12,0,100,"break crusader SAY_PERSUADED6","NO! PLEASE! There is one more thing that I forgot to mention... A courier comes soon... From Hearthglen. It..."),
-- Scarlet Marksman
(28610,1,0,12,0,100,"crusader SAY_CRUSADER1","You'll be hanging in the gallows shortly, Scourge fiend!"),
(28610,1,1,12,0,100,"crusader SAY_CRUSADER2","You'll have to kill me, monster! I will tell you NOTHING!"),
(28610,1,2,12,0,100,"crusader SAY_CRUSADER3","You hit like a girl. Honestly. Is that the best you can do?"),
(28610,1,3,12,0,100,"crusader SAY_CRUSADER4","ARGH! You burned my last good tabard!"),
(28610,1,4,12,0,100,"crusader SAY_CRUSADER5","Argh... The pain... The pain is almost as unbearable as the lashings I received in grammar school when I was but a child."),
(28610,1,5,12,0,100,"crusader SAY_CRUSADER6","I used to work for Grand Inquisitor Isillien! Your idea of pain is a normal mid-afternoon for me!"),
(28610,2,0,12,0,100,"break crusader SAY_PERSUADED1","I'll tell you everything! STOP! PLEASE!"),
(28610,3,0,12,0,100,"break crusader SAY_PERSUADED2","We... We have only been told that the \"Crimson Dawn\" is an awakening. You see, the Light speaks to the High General. It is the Light..."),
(28610,4,0,12,0,100,"break crusader SAY_PERSUADED3","The Light that guides us. The movement was set in motion before you came... We... We do as we are told. It is what must be done."),
(28610,5,0,12,0,100,"break crusader SAY_PERSUADED4","I know very little else... The High General chooses who may go and who must stay behind. There's nothing else... You must believe me!"),
(28610,6,0,12,0,100,"break crusader SAY_PERSUADED6","NO! PLEASE! There is one more thing that I forgot to mention... A courier comes soon... From Hearthglen. It...");

-- koltira deathweaver
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1609570 AND -1609561;
DELETE FROM `creature_text` WHERE `entry`=28912;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(28912,0,0,12,0,100,"koltira deathweaver SAY_BREAKOUT1","I'll need to get my runeblade and armor... Just need a little more time."),
(28912,1,0,12,0,100,"koltira deathweaver SAY_BREAKOUT2","I'm still weak, but I think I can get an anti-magic barrier up. Stay inside it or you'll be destroyed by their spells."),
(28912,2,0,12,0,100,"koltira deathweaver SAY_BREAKOUT3","Maintaining this barrier will require all of my concentration. Kill them all!"),
(28912,3,0,12,0,100,"koltira deathweaver SAY_BREAKOUT4","There are more coming. Defend yourself! Don't fall out of the anti-magic field! They'll tear you apart without its protection!"),
(28912,4,0,12,0,100,"koltira deathweaver SAY_BREAKOUT5","I can't keep barrier up much longer... Where is that coward?"),
(28912,5,0,12,0,100,"koltira deathweaver SAY_BREAKOUT6","The High Inquisitor comes! Be ready, death knight! Do not let him draw you out of the protective bounds of my anti-magic field! Kill him and take his head!"),
(28912,6,0,12,0,100,"koltira deathweaver SAY_BREAKOUT7","Stay in the anti-magic field! Make them come to you!"),
(28912,7,0,12,0,100,"koltira deathweaver SAY_BREAKOUT8","The death of the High Inquisitor of New Avalon will not go unnoticed. You need to get out of here at once! Go, before more of them show up. I'll be fine on my own."),
(28912,8,0,12,0,100,"koltira deathweaver SAY_BREAKOUT9","I'll draw their fire, you make your escape behind me."),
(28912,9,0,14,0,100,"koltira deathweaver SAY_BREAKOUT10","Your High Inquisitor is nothing more than a pile of meat, Crusaders! There are none beyond the grasp of the Scourge!");

-- scarlet courier
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1609532 AND -1609531;
DELETE FROM `creature_text` WHERE `entry`=29076;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(29076,0,0,12,0,100,"scarlet courier SAY_TREE1","Hrm, what a strange tree. I must investigate."),
(29076,1,0,12,0,100,"scarlet courier SAY_TREE2","What's this!? This isn't a tree at all! Guards! Guards!");

-- high inquisitor valroth
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1609586 AND -1609581;
DELETE FROM `creature_text` WHERE `entry`=29001;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(29001,0,0,14,0,100,"high inquisitor valroth start","The Crusade will purge your kind from this world!"),
(29001,1,0,14,0,100,"high inquisitor valroth SAY_VALROTH_AGGRO","It seems that I'll need to deal with you myself. The High Inquisitor comes for you, Scourge!"),
(29001,2,0,12,0,100,"high inquisitor valroth SAY_VALROTH_RAND","You have come seeking deliverance? I have come to deliver!"),
(29001,2,1,12,0,100,"high inquisitor valroth SAY_VALROTH_RAND","LIGHT PURGE YOU!"),
(29001,2,2,12,0,100,"high inquisitor valroth SAY_VALROTH_RAND","Coward!"),
(29001,3,0,16,0,100,"high inquisitor valroth SAY_VALROTH_DEATH","High Inquisitor Valroth's remains fall to the ground.");

-- A special surprise
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1609078 AND -1609025;
DELETE FROM `creature_text` WHERE `entry` IN (29032,29061,29065,29067,29068,29070,29074,29072,29073,29071,29053);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
-- Malar Bravehorn
(29032,0,0,12,0,100,"special_surprise SAY_EXEC_START_1","Come to finish the job, have you?"),
(29032,1,0,12,0,100,"special_surprise SAY_EXEC_START_2","Come to finish the job, have ye?"),
(29032,2,0,12,0,100,"special_surprise SAY_EXEC_START_3","Come ta finish da job, mon?"),
(29032,3,0,12,0,100,"special_surprise SAY_EXEC_PROG_1","You'll look me in the eyes when..."),
(29032,4,0,12,0,100,"special_surprise SAY_EXEC_PROG_2","Well this son o' Ironforge would like..."),
(29032,5,0,12,0,100,"special_surprise SAY_EXEC_PROG_3","Ironic, isn't it? To be killed..."),
(29032,6,0,12,0,100,"special_surprise SAY_EXEC_PROG_4","If you'd allow me just one..."),
(29032,7,0,12,0,100,"special_surprise SAY_EXEC_PROG_5","I'd like to stand for..."),
(29032,8,0,12,0,100,"special_surprise SAY_EXEC_PROG_6","I want to die like an orc..."),
(29032,9,0,12,0,100,"special_surprise SAY_EXEC_PROG_7","Dis troll gonna stand for da..."),
(29032,10,0,12,0,100,"special_surprise SAY_EXEC_NAME_1","$N?"),
(29032,11,0,12,0,100,"special_surprise SAY_EXEC_NAME_2","$N? Mon?"),
(29032,12,0,12,0,100,"special_surprise SAY_EXEC_RECOG_1","$N, I'd recognize that face anywhere... What... What have they done to you, $N?"),
(29032,13,0,12,0,100,"special_surprise SAY_EXEC_RECOG_2","$N, I'd recognize those face tentacles anywhere... What... What have they done to you, $N?"),
(29032,14,0,12,0,100,"special_surprise SAY_EXEC_RECOG_3","$N, I'd recognize that face anywhere... What... What have they done to ye, $Glad:lass;?"),
(29032,15,0,12,0,100,"special_surprise SAY_EXEC_RECOG_4","$N, I'd recognize that decay anywhere... What... What have they done to you, $N?"),
(29032,16,0,12,0,100,"special_surprise SAY_EXEC_RECOG_5","$N, I'd recognize those horns anywhere... What have they done to you, $N?"),
(29032,17,0,12,0,100,"special_surprise SAY_EXEC_RECOG_6","$N, I'd recognize dem tusks anywhere... What... What have dey done ta you, mon?"),
(29032,18,0,12,0,100,"special_surprise SAY_EXEC_NOREM_1","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you a draenei!"),
(29032,19,0,12,0,100,"special_surprise SAY_EXEC_NOREM_2","Ye don't remember me, do ye? Blasted Scourge... They've tried to drain ye o' everything that made ye a righteous force o' reckoning. Every last ounce o' good... Everything that made you a $Gson:daughter; of Ironforge!"),
(29032,20,0,12,0,100,"special_surprise SAY_EXEC_NOREM_3","You don't remember me, do you? We were humans once - long, long ago - until Lordaeron fell to the Scourge. Your transformation to a Scourge zombie came shortly after my own. Not long after that, our minds were freed by the Dark Lady."),
(29032,21,0,12,0,100,"special_surprise SAY_EXEC_NOREM_4","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a pint-sized force of reckoning. Every last ounce of good... Everything that made you a gnome!"),
(29032,22,0,12,0,100,"special_surprise SAY_EXEC_NOREM_5","You don't remember me, do you? Blasted Scourge...They've tried to drain of everything that made you a righteous force of reckoning. Every last ounce of good...Everything that made you a human!"),
(29032,23,0,12,0,100,"special_surprise SAY_EXEC_NOREM_6","You don't remember me? When you were a child your mother would leave you in my care while she served at the Temple of the Moon. I held you in my arms and fed you with honey and sheep's milk to calm you until she would return. You were my little angel. Blasted Scourge... What have they done to you, $N?"),
(29032,24,0,12,0,100,"special_surprise SAY_EXEC_NOREM_7","You don't recognize me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you an orc!"),
(29032,25,0,12,0,100,"special_surprise SAY_EXEC_NOREM_8","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you a tauren!"),
(29032,26,0,12,0,100,"special_surprise SAY_EXEC_NOREM_9","You don't remember me, mon? Damn da Scourge! Dey gone ta drain you of everytin dat made ya a mojo masta. Every last ounce of good... Everytin' dat made ya a troll hero, mon!"),
(29032,27,0,12,0,100,"special_surprise SAY_EXEC_THINK_1","A pact was made, $Gbrother:sister;! We vowed vengeance against the Lich King! For what he had done to us! We battled the Scourge as Forsaken, pushing them back into the plaguelands and freeing Tirisfal! You and I were champions of the Forsaken!"),
(29032,28,0,12,0,100,"special_surprise SAY_EXEC_THINK_2","You must remember the splendor of life, $Gbrother:sister;. You were a champion of the Kaldorei once! This isn't you!"),
(29032,29,0,12,0,100,"special_surprise SAY_EXEC_THINK_3","Think, $N. Think back. Try and remember the majestic halls of Silvermoon City, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the sin'dorei once! This isn't you."),
(29032,30,0,12,0,100,"special_surprise SAY_EXEC_THINK_4","Think, $N. Think back. Try and remember the proud mountains of Argus, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the draenei once! This isn't you."),
(29032,31,0,12,0,100,"special_surprise SAY_EXEC_THINK_5","Think, $N. Think back. Try and remember the snow capped mountains o' Dun Morogh! Ye were born there, $Glad:lass;. Remember the splendor o' life, $N! Ye were a champion o' the dwarves once! This isn't ye!"),
(29032,32,0,12,0,100,"special_surprise SAY_EXEC_THINK_6","Think, $N. Think back. Try and remember Gnomeregan before those damned troggs! Remember the feel of an [arclight spanner] $Gbrother:sister;. You were a champion of gnome-kind once! This isn't you."),
(29032,33,0,12,0,100,"special_surprise SAY_EXEC_THINK_7","Think, $N. Think back. Try and remember the hills and valleys of Elwynn, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the Alliance once! This isn't you."),
(29032,34,0,12,0,100,"special_surprise SAY_EXEC_THINK_8","Think, $N. Think back. Try and remember Durotar, $Gbrother:sister;! Remember the sacrifices our heroes made so that we could be free of the blood curse. Harken back to the Valley of Trials, where we were reborn into a world without demonic influence. We found the splendor of life, $N. Together! This isn't you. You were a champion of the Horde once!"),
(29032,35,0,12,0,100,"special_surprise SAY_EXEC_THINK_9","Think, $N. Think back. Try and remember the rolling plains of Mulgore, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the tauren once! This isn't you."),
(29032,36,0,12,0,100,"special_surprise SAY_EXEC_THINK_10","TINK $N. Tink back, mon! We be Darkspear, mon! Bruddas and sistas! Remember when we fought the Zalazane and done took he head and freed da Echo Isles? MON! TINK! You was a champion of da Darkspear trolls!"),
(29032,37,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_1","Listen to me, $N. You must fight against the Lich King's control. He is a monster that wants to see this world - our world - in ruin. Don't let him use you to accomplish his goals. You were once a hero and you can be again. Fight, damn you! Fight his control!"),
(29032,38,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_2","Listen to me, $N Ye must fight against the Lich King's control. He's a monster that wants to see this world - our world - in ruin. Don't let him use ye to accomplish his goals. Ye were once a hero and ye can be again. Fight, damn ye! Fight his control!"),
(29032,39,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_3","Listen to me, $N. You must fight against the Lich King's control. He is a monster that wants to see this world - our world - in ruin. Don't let him use you to accomplish his goals AGAIN. You were once a hero and you can be again. Fight, damn you! Fight his control!"),
(29032,40,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_4","Listen ta me, $Gbrudda:sista;. You must fight against da Lich King's control. He be a monstar dat want ta see dis world - our world - be ruined. Don't let he use you ta accomplish he goals. You be a hero once and you be a hero again! Fight it, mon! Fight he control!"),

(29032,42,0,12,0,100,"special_surprise SAY_EXEC_TIME_1","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Silvermoon. This world is worth saving!"),
(29032,43,0,12,0,100,"special_surprise SAY_EXEC_TIME_2","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Argus. Don't let that happen to this world."),
(29032,44,0,12,0,100,"special_surprise SAY_EXEC_TIME_3","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both $N... For KHAAAAAAAAZZZ MODAAAAAANNNNNN!!!"),
(29032,45,0,12,0,100,"special_surprise SAY_EXEC_TIME_4","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Tirisfal! This world is worth saving!"),
(29032,46,0,12,0,100,"special_surprise SAY_EXEC_TIME_5","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Gnomeregan! This world is worth saving."),
(29032,47,0,12,0,100,"special_surprise SAY_EXEC_TIME_6","There... There's no more time for me. I'm done for. FInish me off, $N. Do it or they'll kill us both. $N...Remember Elwynn. This world is worth saving."),
(29032,48,0,12,0,100,"special_surprise SAY_EXEC_TIME_7","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Teldrassil, our beloved home. This world is worth saving."),
(29032,49,0,12,0,100,"special_surprise SAY_EXEC_TIME_8","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... For the Horde! This world is worth saving."),
(29032,50,0,12,0,100,"special_surprise SAY_EXEC_TIME_9","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Mulgore. This world is worth saving."),
(29032,51,0,12,0,100,"special_surprise SAY_EXEC_TIME_10","Der... Der's no more time for me. I be done for. Finish me off $N. Do it or they'll kill us both. $N... Remember Sen'jin Village, mon! Dis world be worth saving!"),
(29032,52,0,12,0,100,"special_surprise SAY_EXEC_WAITING","Do it, $N! Put me out of my misery!"),
(29032,53,0,16,0,100,"special_surprise EMOTE_DIES","%s dies from his wounds."),
-- Ellen Stanbridge
(29061,0,0,12,0,100,"special_surprise SAY_EXEC_START_1","Come to finish the job, have you?"),
(29061,1,0,12,0,100,"special_surprise SAY_EXEC_START_2","Come to finish the job, have ye?"),
(29061,2,0,12,0,100,"special_surprise SAY_EXEC_START_3","Come ta finish da job, mon?"),
(29061,3,0,12,0,100,"special_surprise SAY_EXEC_PROG_1","You'll look me in the eyes when..."),
(29061,4,0,12,0,100,"special_surprise SAY_EXEC_PROG_2","Well this son o' Ironforge would like..."),
(29061,5,0,12,0,100,"special_surprise SAY_EXEC_PROG_3","Ironic, isn't it? To be killed..."),
(29061,6,0,12,0,100,"special_surprise SAY_EXEC_PROG_4","If you'd allow me just one..."),
(29061,7,0,12,0,100,"special_surprise SAY_EXEC_PROG_5","I'd like to stand for..."),
(29061,8,0,12,0,100,"special_surprise SAY_EXEC_PROG_6","I want to die like an orc..."),
(29061,9,0,12,0,100,"special_surprise SAY_EXEC_PROG_7","Dis troll gonna stand for da..."),
(29061,10,0,12,0,100,"special_surprise SAY_EXEC_NAME_1","$N?"),
(29061,11,0,12,0,100,"special_surprise SAY_EXEC_NAME_2","$N? Mon?"),
(29061,12,0,12,0,100,"special_surprise SAY_EXEC_RECOG_1","$N, I'd recognize that face anywhere... What... What have they done to you, $N?"),
(29061,13,0,12,0,100,"special_surprise SAY_EXEC_RECOG_2","$N, I'd recognize those face tentacles anywhere... What... What have they done to you, $N?"),
(29061,14,0,12,0,100,"special_surprise SAY_EXEC_RECOG_3","$N, I'd recognize that face anywhere... What... What have they done to ye, $Glad:lass;?"),
(29061,15,0,12,0,100,"special_surprise SAY_EXEC_RECOG_4","$N, I'd recognize that decay anywhere... What... What have they done to you, $N?"),
(29061,16,0,12,0,100,"special_surprise SAY_EXEC_RECOG_5","$N, I'd recognize those horns anywhere... What have they done to you, $N?"),
(29061,17,0,12,0,100,"special_surprise SAY_EXEC_RECOG_6","$N, I'd recognize dem tusks anywhere... What... What have dey done ta you, mon?"),
(29061,18,0,12,0,100,"special_surprise SAY_EXEC_NOREM_1","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you a draenei!"),
(29061,19,0,12,0,100,"special_surprise SAY_EXEC_NOREM_2","Ye don't remember me, do ye? Blasted Scourge... They've tried to drain ye o' everything that made ye a righteous force o' reckoning. Every last ounce o' good... Everything that made you a $Gson:daughter; of Ironforge!"),
(29061,20,0,12,0,100,"special_surprise SAY_EXEC_NOREM_3","You don't remember me, do you? We were humans once - long, long ago - until Lordaeron fell to the Scourge. Your transformation to a Scourge zombie came shortly after my own. Not long after that, our minds were freed by the Dark Lady."),
(29061,21,0,12,0,100,"special_surprise SAY_EXEC_NOREM_4","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a pint-sized force of reckoning. Every last ounce of good... Everything that made you a gnome!"),
(29061,22,0,12,0,100,"special_surprise SAY_EXEC_NOREM_5","You don't remember me, do you? Blasted Scourge...They've tried to drain of everything that made you a righteous force of reckoning. Every last ounce of good...Everything that made you a human!"),
(29061,23,0,12,0,100,"special_surprise SAY_EXEC_NOREM_6","You don't remember me? When you were a child your mother would leave you in my care while she served at the Temple of the Moon. I held you in my arms and fed you with honey and sheep's milk to calm you until she would return. You were my little angel. Blasted Scourge... What have they done to you, $N?"),
(29061,24,0,12,0,100,"special_surprise SAY_EXEC_NOREM_7","You don't recognize me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you an orc!"),
(29061,25,0,12,0,100,"special_surprise SAY_EXEC_NOREM_8","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you a tauren!"),
(29061,26,0,12,0,100,"special_surprise SAY_EXEC_NOREM_9","You don't remember me, mon? Damn da Scourge! Dey gone ta drain you of everytin dat made ya a mojo masta. Every last ounce of good... Everytin' dat made ya a troll hero, mon!"),
(29061,27,0,12,0,100,"special_surprise SAY_EXEC_THINK_1","A pact was made, $Gbrother:sister;! We vowed vengeance against the Lich King! For what he had done to us! We battled the Scourge as Forsaken, pushing them back into the plaguelands and freeing Tirisfal! You and I were champions of the Forsaken!"),
(29061,28,0,12,0,100,"special_surprise SAY_EXEC_THINK_2","You must remember the splendor of life, $Gbrother:sister;. You were a champion of the Kaldorei once! This isn't you!"),
(29061,29,0,12,0,100,"special_surprise SAY_EXEC_THINK_3","Think, $N. Think back. Try and remember the majestic halls of Silvermoon City, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the sin'dorei once! This isn't you."),
(29061,30,0,12,0,100,"special_surprise SAY_EXEC_THINK_4","Think, $N. Think back. Try and remember the proud mountains of Argus, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the draenei once! This isn't you."),
(29061,31,0,12,0,100,"special_surprise SAY_EXEC_THINK_5","Think, $N. Think back. Try and remember the snow capped mountains o' Dun Morogh! Ye were born there, $Glad:lass;. Remember the splendor o' life, $N! Ye were a champion o' the dwarves once! This isn't ye!"),
(29061,32,0,12,0,100,"special_surprise SAY_EXEC_THINK_6","Think, $N. Think back. Try and remember Gnomeregan before those damned troggs! Remember the feel of an [arclight spanner] $Gbrother:sister;. You were a champion of gnome-kind once! This isn't you."),
(29061,33,0,12,0,100,"special_surprise SAY_EXEC_THINK_7","Think, $N. Think back. Try and remember the hills and valleys of Elwynn, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the Alliance once! This isn't you."),
(29061,34,0,12,0,100,"special_surprise SAY_EXEC_THINK_8","Think, $N. Think back. Try and remember Durotar, $Gbrother:sister;! Remember the sacrifices our heroes made so that we could be free of the blood curse. Harken back to the Valley of Trials, where we were reborn into a world without demonic influence. We found the splendor of life, $N. Together! This isn't you. You were a champion of the Horde once!"),
(29061,35,0,12,0,100,"special_surprise SAY_EXEC_THINK_9","Think, $N. Think back. Try and remember the rolling plains of Mulgore, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the tauren once! This isn't you."),
(29061,36,0,12,0,100,"special_surprise SAY_EXEC_THINK_10","TINK $N. Tink back, mon! We be Darkspear, mon! Bruddas and sistas! Remember when we fought the Zalazane and done took he head and freed da Echo Isles? MON! TINK! You was a champion of da Darkspear trolls!"),
(29061,37,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_1","Listen to me, $N. You must fight against the Lich King's control. He is a monster that wants to see this world - our world - in ruin. Don't let him use you to accomplish his goals. You were once a hero and you can be again. Fight, damn you! Fight his control!"),
(29061,38,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_2","Listen to me, $N Ye must fight against the Lich King's control. He's a monster that wants to see this world - our world - in ruin. Don't let him use ye to accomplish his goals. Ye were once a hero and ye can be again. Fight, damn ye! Fight his control!"),
(29061,39,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_3","Listen to me, $N. You must fight against the Lich King's control. He is a monster that wants to see this world - our world - in ruin. Don't let him use you to accomplish his goals AGAIN. You were once a hero and you can be again. Fight, damn you! Fight his control!"),
(29061,40,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_4","Listen ta me, $Gbrudda:sista;. You must fight against da Lich King's control. He be a monstar dat want ta see dis world - our world - be ruined. Don't let he use you ta accomplish he goals. You be a hero once and you be a hero again! Fight it, mon! Fight he control!"),
(29061,42,0,12,0,100,"special_surprise SAY_EXEC_TIME_1","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Silvermoon. This world is worth saving!"),
(29061,43,0,12,0,100,"special_surprise SAY_EXEC_TIME_2","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Argus. Don't let that happen to this world."),
(29061,44,0,12,0,100,"special_surprise SAY_EXEC_TIME_3","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both $N... For KHAAAAAAAAZZZ MODAAAAAANNNNNN!!!"),
(29061,45,0,12,0,100,"special_surprise SAY_EXEC_TIME_4","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Tirisfal! This world is worth saving!"),
(29061,46,0,12,0,100,"special_surprise SAY_EXEC_TIME_5","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Gnomeregan! This world is worth saving."),
(29061,47,0,12,0,100,"special_surprise SAY_EXEC_TIME_6","There... There's no more time for me. I'm done for. FInish me off, $N. Do it or they'll kill us both. $N...Remember Elwynn. This world is worth saving."),
(29061,48,0,12,0,100,"special_surprise SAY_EXEC_TIME_7","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Teldrassil, our beloved home. This world is worth saving."),
(29061,49,0,12,0,100,"special_surprise SAY_EXEC_TIME_8","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... For the Horde! This world is worth saving."),
(29061,50,0,12,0,100,"special_surprise SAY_EXEC_TIME_9","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Mulgore. This world is worth saving."),
(29061,51,0,12,0,100,"special_surprise SAY_EXEC_TIME_10","Der... Der's no more time for me. I be done for. Finish me off $N. Do it or they'll kill us both. $N... Remember Sen'jin Village, mon! Dis world be worth saving!"),
(29061,52,0,12,0,100,"special_surprise SAY_EXEC_WAITING","Do it, $N! Put me out of my misery!"),
(29061,53,0,16,0,100,"special_surprise EMOTE_DIES","%s dies from his wounds."),
-- Yazmina Oakenthorn
(29065,0,0,12,0,100,"special_surprise SAY_EXEC_START_1","Come to finish the job, have you?"),
(29065,1,0,12,0,100,"special_surprise SAY_EXEC_START_2","Come to finish the job, have ye?"),
(29065,2,0,12,0,100,"special_surprise SAY_EXEC_START_3","Come ta finish da job, mon?"),
(29065,3,0,12,0,100,"special_surprise SAY_EXEC_PROG_1","You'll look me in the eyes when..."),
(29065,4,0,12,0,100,"special_surprise SAY_EXEC_PROG_2","Well this son o' Ironforge would like..."),
(29065,5,0,12,0,100,"special_surprise SAY_EXEC_PROG_3","Ironic, isn't it? To be killed..."),
(29065,6,0,12,0,100,"special_surprise SAY_EXEC_PROG_4","If you'd allow me just one..."),
(29065,7,0,12,0,100,"special_surprise SAY_EXEC_PROG_5","I'd like to stand for..."),
(29065,8,0,12,0,100,"special_surprise SAY_EXEC_PROG_6","I want to die like an orc..."),
(29065,9,0,12,0,100,"special_surprise SAY_EXEC_PROG_7","Dis troll gonna stand for da..."),
(29065,10,0,12,0,100,"special_surprise SAY_EXEC_NAME_1","$N?"),
(29065,11,0,12,0,100,"special_surprise SAY_EXEC_NAME_2","$N? Mon?"),
(29065,12,0,12,0,100,"special_surprise SAY_EXEC_RECOG_1","$N, I'd recognize that face anywhere... What... What have they done to you, $N?"),
(29065,13,0,12,0,100,"special_surprise SAY_EXEC_RECOG_2","$N, I'd recognize those face tentacles anywhere... What... What have they done to you, $N?"),
(29065,14,0,12,0,100,"special_surprise SAY_EXEC_RECOG_3","$N, I'd recognize that face anywhere... What... What have they done to ye, $Glad:lass;?"),
(29065,15,0,12,0,100,"special_surprise SAY_EXEC_RECOG_4","$N, I'd recognize that decay anywhere... What... What have they done to you, $N?"),
(29065,16,0,12,0,100,"special_surprise SAY_EXEC_RECOG_5","$N, I'd recognize those horns anywhere... What have they done to you, $N?"),
(29065,17,0,12,0,100,"special_surprise SAY_EXEC_RECOG_6","$N, I'd recognize dem tusks anywhere... What... What have dey done ta you, mon?"),
(29065,18,0,12,0,100,"special_surprise SAY_EXEC_NOREM_1","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you a draenei!"),
(29065,19,0,12,0,100,"special_surprise SAY_EXEC_NOREM_2","Ye don't remember me, do ye? Blasted Scourge... They've tried to drain ye o' everything that made ye a righteous force o' reckoning. Every last ounce o' good... Everything that made you a $Gson:daughter; of Ironforge!"),
(29065,20,0,12,0,100,"special_surprise SAY_EXEC_NOREM_3","You don't remember me, do you? We were humans once - long, long ago - until Lordaeron fell to the Scourge. Your transformation to a Scourge zombie came shortly after my own. Not long after that, our minds were freed by the Dark Lady."),
(29065,21,0,12,0,100,"special_surprise SAY_EXEC_NOREM_4","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a pint-sized force of reckoning. Every last ounce of good... Everything that made you a gnome!"),
(29065,22,0,12,0,100,"special_surprise SAY_EXEC_NOREM_5","You don't remember me, do you? Blasted Scourge...They've tried to drain of everything that made you a righteous force of reckoning. Every last ounce of good...Everything that made you a human!"),
(29065,23,0,12,0,100,"special_surprise SAY_EXEC_NOREM_6","You don't remember me? When you were a child your mother would leave you in my care while she served at the Temple of the Moon. I held you in my arms and fed you with honey and sheep's milk to calm you until she would return. You were my little angel. Blasted Scourge... What have they done to you, $N?"),
(29065,24,0,12,0,100,"special_surprise SAY_EXEC_NOREM_7","You don't recognize me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you an orc!"),
(29065,25,0,12,0,100,"special_surprise SAY_EXEC_NOREM_8","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you a tauren!"),
(29065,26,0,12,0,100,"special_surprise SAY_EXEC_NOREM_9","You don't remember me, mon? Damn da Scourge! Dey gone ta drain you of everytin dat made ya a mojo masta. Every last ounce of good... Everytin' dat made ya a troll hero, mon!"),
(29065,27,0,12,0,100,"special_surprise SAY_EXEC_THINK_1","A pact was made, $Gbrother:sister;! We vowed vengeance against the Lich King! For what he had done to us! We battled the Scourge as Forsaken, pushing them back into the plaguelands and freeing Tirisfal! You and I were champions of the Forsaken!"),
(29065,28,0,12,0,100,"special_surprise SAY_EXEC_THINK_2","You must remember the splendor of life, $Gbrother:sister;. You were a champion of the Kaldorei once! This isn't you!"),
(29065,29,0,12,0,100,"special_surprise SAY_EXEC_THINK_3","Think, $N. Think back. Try and remember the majestic halls of Silvermoon City, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the sin'dorei once! This isn't you."),
(29065,30,0,12,0,100,"special_surprise SAY_EXEC_THINK_4","Think, $N. Think back. Try and remember the proud mountains of Argus, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the draenei once! This isn't you."),
(29065,31,0,12,0,100,"special_surprise SAY_EXEC_THINK_5","Think, $N. Think back. Try and remember the snow capped mountains o' Dun Morogh! Ye were born there, $Glad:lass;. Remember the splendor o' life, $N! Ye were a champion o' the dwarves once! This isn't ye!"),
(29065,32,0,12,0,100,"special_surprise SAY_EXEC_THINK_6","Think, $N. Think back. Try and remember Gnomeregan before those damned troggs! Remember the feel of an [arclight spanner] $Gbrother:sister;. You were a champion of gnome-kind once! This isn't you."),
(29065,33,0,12,0,100,"special_surprise SAY_EXEC_THINK_7","Think, $N. Think back. Try and remember the hills and valleys of Elwynn, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the Alliance once! This isn't you."),
(29065,34,0,12,0,100,"special_surprise SAY_EXEC_THINK_8","Think, $N. Think back. Try and remember Durotar, $Gbrother:sister;! Remember the sacrifices our heroes made so that we could be free of the blood curse. Harken back to the Valley of Trials, where we were reborn into a world without demonic influence. We found the splendor of life, $N. Together! This isn't you. You were a champion of the Horde once!"),
(29065,35,0,12,0,100,"special_surprise SAY_EXEC_THINK_9","Think, $N. Think back. Try and remember the rolling plains of Mulgore, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the tauren once! This isn't you."),
(29065,36,0,12,0,100,"special_surprise SAY_EXEC_THINK_10","TINK $N. Tink back, mon! We be Darkspear, mon! Bruddas and sistas! Remember when we fought the Zalazane and done took he head and freed da Echo Isles? MON! TINK! You was a champion of da Darkspear trolls!"),
(29065,37,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_1","Listen to me, $N. You must fight against the Lich King's control. He is a monster that wants to see this world - our world - in ruin. Don't let him use you to accomplish his goals. You were once a hero and you can be again. Fight, damn you! Fight his control!"),
(29065,38,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_2","Listen to me, $N Ye must fight against the Lich King's control. He's a monster that wants to see this world - our world - in ruin. Don't let him use ye to accomplish his goals. Ye were once a hero and ye can be again. Fight, damn ye! Fight his control!"),
(29065,39,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_3","Listen to me, $N. You must fight against the Lich King's control. He is a monster that wants to see this world - our world - in ruin. Don't let him use you to accomplish his goals AGAIN. You were once a hero and you can be again. Fight, damn you! Fight his control!"),
(29065,40,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_4","Listen ta me, $Gbrudda:sista;. You must fight against da Lich King's control. He be a monstar dat want ta see dis world - our world - be ruined. Don't let he use you ta accomplish he goals. You be a hero once and you be a hero again! Fight it, mon! Fight he control!"),
(29065,42,0,12,0,100,"special_surprise SAY_EXEC_TIME_1","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Silvermoon. This world is worth saving!"),
(29065,43,0,12,0,100,"special_surprise SAY_EXEC_TIME_2","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Argus. Don't let that happen to this world."),
(29065,44,0,12,0,100,"special_surprise SAY_EXEC_TIME_3","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both $N... For KHAAAAAAAAZZZ MODAAAAAANNNNNN!!!"),
(29065,45,0,12,0,100,"special_surprise SAY_EXEC_TIME_4","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Tirisfal! This world is worth saving!"),
(29065,46,0,12,0,100,"special_surprise SAY_EXEC_TIME_5","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Gnomeregan! This world is worth saving."),
(29065,47,0,12,0,100,"special_surprise SAY_EXEC_TIME_6","There... There's no more time for me. I'm done for. FInish me off, $N. Do it or they'll kill us both. $N...Remember Elwynn. This world is worth saving."),
(29065,48,0,12,0,100,"special_surprise SAY_EXEC_TIME_7","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Teldrassil, our beloved home. This world is worth saving."),
(29065,49,0,12,0,100,"special_surprise SAY_EXEC_TIME_8","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... For the Horde! This world is worth saving."),
(29065,50,0,12,0,100,"special_surprise SAY_EXEC_TIME_9","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Mulgore. This world is worth saving."),
(29065,51,0,12,0,100,"special_surprise SAY_EXEC_TIME_10","Der... Der's no more time for me. I be done for. Finish me off $N. Do it or they'll kill us both. $N... Remember Sen'jin Village, mon! Dis world be worth saving!"),
(29065,52,0,12,0,100,"special_surprise SAY_EXEC_WAITING","Do it, $N! Put me out of my misery!"),
(29065,53,0,16,0,100,"special_surprise EMOTE_DIES","%s dies from his wounds."),
-- Donovan Pulfrost
(29067,0,0,12,0,100,"special_surprise SAY_EXEC_START_1","Come to finish the job, have you?"),
(29067,1,0,12,0,100,"special_surprise SAY_EXEC_START_2","Come to finish the job, have ye?"),
(29067,2,0,12,0,100,"special_surprise SAY_EXEC_START_3","Come ta finish da job, mon?"),
(29067,3,0,12,0,100,"special_surprise SAY_EXEC_PROG_1","You'll look me in the eyes when..."),
(29067,4,0,12,0,100,"special_surprise SAY_EXEC_PROG_2","Well this son o' Ironforge would like..."),
(29067,5,0,12,0,100,"special_surprise SAY_EXEC_PROG_3","Ironic, isn't it? To be killed..."),
(29067,6,0,12,0,100,"special_surprise SAY_EXEC_PROG_4","If you'd allow me just one..."),
(29067,7,0,12,0,100,"special_surprise SAY_EXEC_PROG_5","I'd like to stand for..."),
(29067,8,0,12,0,100,"special_surprise SAY_EXEC_PROG_6","I want to die like an orc..."),
(29067,9,0,12,0,100,"special_surprise SAY_EXEC_PROG_7","Dis troll gonna stand for da..."),
(29067,10,0,12,0,100,"special_surprise SAY_EXEC_NAME_1","$N?"),
(29067,11,0,12,0,100,"special_surprise SAY_EXEC_NAME_2","$N? Mon?"),
(29067,12,0,12,0,100,"special_surprise SAY_EXEC_RECOG_1","$N, I'd recognize that face anywhere... What... What have they done to you, $N?"),
(29067,13,0,12,0,100,"special_surprise SAY_EXEC_RECOG_2","$N, I'd recognize those face tentacles anywhere... What... What have they done to you, $N?"),
(29067,14,0,12,0,100,"special_surprise SAY_EXEC_RECOG_3","$N, I'd recognize that face anywhere... What... What have they done to ye, $Glad:lass;?"),
(29067,15,0,12,0,100,"special_surprise SAY_EXEC_RECOG_4","$N, I'd recognize that decay anywhere... What... What have they done to you, $N?"),
(29067,16,0,12,0,100,"special_surprise SAY_EXEC_RECOG_5","$N, I'd recognize those horns anywhere... What have they done to you, $N?"),
(29067,17,0,12,0,100,"special_surprise SAY_EXEC_RECOG_6","$N, I'd recognize dem tusks anywhere... What... What have dey done ta you, mon?"),
(29067,18,0,12,0,100,"special_surprise SAY_EXEC_NOREM_1","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you a draenei!"),
(29067,19,0,12,0,100,"special_surprise SAY_EXEC_NOREM_2","Ye don't remember me, do ye? Blasted Scourge... They've tried to drain ye o' everything that made ye a righteous force o' reckoning. Every last ounce o' good... Everything that made you a $Gson:daughter; of Ironforge!"),
(29067,20,0,12,0,100,"special_surprise SAY_EXEC_NOREM_3","You don't remember me, do you? We were humans once - long, long ago - until Lordaeron fell to the Scourge. Your transformation to a Scourge zombie came shortly after my own. Not long after that, our minds were freed by the Dark Lady."),
(29067,21,0,12,0,100,"special_surprise SAY_EXEC_NOREM_4","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a pint-sized force of reckoning. Every last ounce of good... Everything that made you a gnome!"),
(29067,22,0,12,0,100,"special_surprise SAY_EXEC_NOREM_5","You don't remember me, do you? Blasted Scourge...They've tried to drain of everything that made you a righteous force of reckoning. Every last ounce of good...Everything that made you a human!"),
(29067,23,0,12,0,100,"special_surprise SAY_EXEC_NOREM_6","You don't remember me? When you were a child your mother would leave you in my care while she served at the Temple of the Moon. I held you in my arms and fed you with honey and sheep's milk to calm you until she would return. You were my little angel. Blasted Scourge... What have they done to you, $N?"),
(29067,24,0,12,0,100,"special_surprise SAY_EXEC_NOREM_7","You don't recognize me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you an orc!"),
(29067,25,0,12,0,100,"special_surprise SAY_EXEC_NOREM_8","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you a tauren!"),
(29067,26,0,12,0,100,"special_surprise SAY_EXEC_NOREM_9","You don't remember me, mon? Damn da Scourge! Dey gone ta drain you of everytin dat made ya a mojo masta. Every last ounce of good... Everytin' dat made ya a troll hero, mon!"),
(29067,27,0,12,0,100,"special_surprise SAY_EXEC_THINK_1","A pact was made, $Gbrother:sister;! We vowed vengeance against the Lich King! For what he had done to us! We battled the Scourge as Forsaken, pushing them back into the plaguelands and freeing Tirisfal! You and I were champions of the Forsaken!"),
(29067,28,0,12,0,100,"special_surprise SAY_EXEC_THINK_2","You must remember the splendor of life, $Gbrother:sister;. You were a champion of the Kaldorei once! This isn't you!"),
(29067,29,0,12,0,100,"special_surprise SAY_EXEC_THINK_3","Think, $N. Think back. Try and remember the majestic halls of Silvermoon City, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the sin'dorei once! This isn't you."),
(29067,30,0,12,0,100,"special_surprise SAY_EXEC_THINK_4","Think, $N. Think back. Try and remember the proud mountains of Argus, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the draenei once! This isn't you."),
(29067,31,0,12,0,100,"special_surprise SAY_EXEC_THINK_5","Think, $N. Think back. Try and remember the snow capped mountains o' Dun Morogh! Ye were born there, $Glad:lass;. Remember the splendor o' life, $N! Ye were a champion o' the dwarves once! This isn't ye!"),
(29067,32,0,12,0,100,"special_surprise SAY_EXEC_THINK_6","Think, $N. Think back. Try and remember Gnomeregan before those damned troggs! Remember the feel of an [arclight spanner] $Gbrother:sister;. You were a champion of gnome-kind once! This isn't you."),
(29067,33,0,12,0,100,"special_surprise SAY_EXEC_THINK_7","Think, $N. Think back. Try and remember the hills and valleys of Elwynn, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the Alliance once! This isn't you."),
(29067,34,0,12,0,100,"special_surprise SAY_EXEC_THINK_8","Think, $N. Think back. Try and remember Durotar, $Gbrother:sister;! Remember the sacrifices our heroes made so that we could be free of the blood curse. Harken back to the Valley of Trials, where we were reborn into a world without demonic influence. We found the splendor of life, $N. Together! This isn't you. You were a champion of the Horde once!"),
(29067,35,0,12,0,100,"special_surprise SAY_EXEC_THINK_9","Think, $N. Think back. Try and remember the rolling plains of Mulgore, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the tauren once! This isn't you."),
(29067,36,0,12,0,100,"special_surprise SAY_EXEC_THINK_10","TINK $N. Tink back, mon! We be Darkspear, mon! Bruddas and sistas! Remember when we fought the Zalazane and done took he head and freed da Echo Isles? MON! TINK! You was a champion of da Darkspear trolls!"),
(29067,37,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_1","Listen to me, $N. You must fight against the Lich King's control. He is a monster that wants to see this world - our world - in ruin. Don't let him use you to accomplish his goals. You were once a hero and you can be again. Fight, damn you! Fight his control!"),
(29067,38,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_2","Listen to me, $N Ye must fight against the Lich King's control. He's a monster that wants to see this world - our world - in ruin. Don't let him use ye to accomplish his goals. Ye were once a hero and ye can be again. Fight, damn ye! Fight his control!"),
(29067,39,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_3","Listen to me, $N. You must fight against the Lich King's control. He is a monster that wants to see this world - our world - in ruin. Don't let him use you to accomplish his goals AGAIN. You were once a hero and you can be again. Fight, damn you! Fight his control!"),
(29067,40,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_4","Listen ta me, $Gbrudda:sista;. You must fight against da Lich King's control. He be a monstar dat want ta see dis world - our world - be ruined. Don't let he use you ta accomplish he goals. You be a hero once and you be a hero again! Fight it, mon! Fight he control!"),
(29067,42,0,12,0,100,"special_surprise SAY_EXEC_TIME_1","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Silvermoon. This world is worth saving!"),
(29067,43,0,12,0,100,"special_surprise SAY_EXEC_TIME_2","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Argus. Don't let that happen to this world."),
(29067,44,0,12,0,100,"special_surprise SAY_EXEC_TIME_3","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both $N... For KHAAAAAAAAZZZ MODAAAAAANNNNNN!!!"),
(29067,45,0,12,0,100,"special_surprise SAY_EXEC_TIME_4","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Tirisfal! This world is worth saving!"),
(29067,46,0,12,0,100,"special_surprise SAY_EXEC_TIME_5","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Gnomeregan! This world is worth saving."),
(29067,47,0,12,0,100,"special_surprise SAY_EXEC_TIME_6","There... There's no more time for me. I'm done for. FInish me off, $N. Do it or they'll kill us both. $N...Remember Elwynn. This world is worth saving."),
(29067,48,0,12,0,100,"special_surprise SAY_EXEC_TIME_7","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Teldrassil, our beloved home. This world is worth saving."),
(29067,49,0,12,0,100,"special_surprise SAY_EXEC_TIME_8","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... For the Horde! This world is worth saving."),
(29067,50,0,12,0,100,"special_surprise SAY_EXEC_TIME_9","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Mulgore. This world is worth saving."),
(29067,51,0,12,0,100,"special_surprise SAY_EXEC_TIME_10","Der... Der's no more time for me. I be done for. Finish me off $N. Do it or they'll kill us both. $N... Remember Sen'jin Village, mon! Dis world be worth saving!"),
(29067,52,0,12,0,100,"special_surprise SAY_EXEC_WAITING","Do it, $N! Put me out of my misery!"),
(29067,53,0,16,0,100,"special_surprise EMOTE_DIES","%s dies from his wounds."),
-- Goby Blastenheimer
(29068,0,0,12,0,100,"special_surprise SAY_EXEC_START_1","Come to finish the job, have you?"),
(29068,1,0,12,0,100,"special_surprise SAY_EXEC_START_2","Come to finish the job, have ye?"),
(29068,2,0,12,0,100,"special_surprise SAY_EXEC_START_3","Come ta finish da job, mon?"),
(29068,3,0,12,0,100,"special_surprise SAY_EXEC_PROG_1","You'll look me in the eyes when..."),
(29068,4,0,12,0,100,"special_surprise SAY_EXEC_PROG_2","Well this son o' Ironforge would like..."),
(29068,5,0,12,0,100,"special_surprise SAY_EXEC_PROG_3","Ironic, isn't it? To be killed..."),
(29068,6,0,12,0,100,"special_surprise SAY_EXEC_PROG_4","If you'd allow me just one..."),
(29068,7,0,12,0,100,"special_surprise SAY_EXEC_PROG_5","I'd like to stand for..."),
(29068,8,0,12,0,100,"special_surprise SAY_EXEC_PROG_6","I want to die like an orc..."),
(29068,9,0,12,0,100,"special_surprise SAY_EXEC_PROG_7","Dis troll gonna stand for da..."),
(29068,10,0,12,0,100,"special_surprise SAY_EXEC_NAME_1","$N?"),
(29068,11,0,12,0,100,"special_surprise SAY_EXEC_NAME_2","$N? Mon?"),
(29068,12,0,12,0,100,"special_surprise SAY_EXEC_RECOG_1","$N, I'd recognize that face anywhere... What... What have they done to you, $N?"),
(29068,13,0,12,0,100,"special_surprise SAY_EXEC_RECOG_2","$N, I'd recognize those face tentacles anywhere... What... What have they done to you, $N?"),
(29068,14,0,12,0,100,"special_surprise SAY_EXEC_RECOG_3","$N, I'd recognize that face anywhere... What... What have they done to ye, $Glad:lass;?"),
(29068,15,0,12,0,100,"special_surprise SAY_EXEC_RECOG_4","$N, I'd recognize that decay anywhere... What... What have they done to you, $N?"),
(29068,16,0,12,0,100,"special_surprise SAY_EXEC_RECOG_5","$N, I'd recognize those horns anywhere... What have they done to you, $N?"),
(29068,17,0,12,0,100,"special_surprise SAY_EXEC_RECOG_6","$N, I'd recognize dem tusks anywhere... What... What have dey done ta you, mon?"),
(29068,18,0,12,0,100,"special_surprise SAY_EXEC_NOREM_1","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you a draenei!"),
(29068,19,0,12,0,100,"special_surprise SAY_EXEC_NOREM_2","Ye don't remember me, do ye? Blasted Scourge... They've tried to drain ye o' everything that made ye a righteous force o' reckoning. Every last ounce o' good... Everything that made you a $Gson:daughter; of Ironforge!"),
(29068,20,0,12,0,100,"special_surprise SAY_EXEC_NOREM_3","You don't remember me, do you? We were humans once - long, long ago - until Lordaeron fell to the Scourge. Your transformation to a Scourge zombie came shortly after my own. Not long after that, our minds were freed by the Dark Lady."),
(29068,21,0,12,0,100,"special_surprise SAY_EXEC_NOREM_4","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a pint-sized force of reckoning. Every last ounce of good... Everything that made you a gnome!"),
(29068,22,0,12,0,100,"special_surprise SAY_EXEC_NOREM_5","You don't remember me, do you? Blasted Scourge...They've tried to drain of everything that made you a righteous force of reckoning. Every last ounce of good...Everything that made you a human!"),
(29068,23,0,12,0,100,"special_surprise SAY_EXEC_NOREM_6","You don't remember me? When you were a child your mother would leave you in my care while she served at the Temple of the Moon. I held you in my arms and fed you with honey and sheep's milk to calm you until she would return. You were my little angel. Blasted Scourge... What have they done to you, $N?"),
(29068,24,0,12,0,100,"special_surprise SAY_EXEC_NOREM_7","You don't recognize me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you an orc!"),
(29068,25,0,12,0,100,"special_surprise SAY_EXEC_NOREM_8","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you a tauren!"),
(29068,26,0,12,0,100,"special_surprise SAY_EXEC_NOREM_9","You don't remember me, mon? Damn da Scourge! Dey gone ta drain you of everytin dat made ya a mojo masta. Every last ounce of good... Everytin' dat made ya a troll hero, mon!"),
(29068,27,0,12,0,100,"special_surprise SAY_EXEC_THINK_1","A pact was made, $Gbrother:sister;! We vowed vengeance against the Lich King! For what he had done to us! We battled the Scourge as Forsaken, pushing them back into the plaguelands and freeing Tirisfal! You and I were champions of the Forsaken!"),
(29068,28,0,12,0,100,"special_surprise SAY_EXEC_THINK_2","You must remember the splendor of life, $Gbrother:sister;. You were a champion of the Kaldorei once! This isn't you!"),
(29068,29,0,12,0,100,"special_surprise SAY_EXEC_THINK_3","Think, $N. Think back. Try and remember the majestic halls of Silvermoon City, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the sin'dorei once! This isn't you."),
(29068,30,0,12,0,100,"special_surprise SAY_EXEC_THINK_4","Think, $N. Think back. Try and remember the proud mountains of Argus, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the draenei once! This isn't you."),
(29068,31,0,12,0,100,"special_surprise SAY_EXEC_THINK_5","Think, $N. Think back. Try and remember the snow capped mountains o' Dun Morogh! Ye were born there, $Glad:lass;. Remember the splendor o' life, $N! Ye were a champion o' the dwarves once! This isn't ye!"),
(29068,32,0,12,0,100,"special_surprise SAY_EXEC_THINK_6","Think, $N. Think back. Try and remember Gnomeregan before those damned troggs! Remember the feel of an [arclight spanner] $Gbrother:sister;. You were a champion of gnome-kind once! This isn't you."),
(29068,33,0,12,0,100,"special_surprise SAY_EXEC_THINK_7","Think, $N. Think back. Try and remember the hills and valleys of Elwynn, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the Alliance once! This isn't you."),
(29068,34,0,12,0,100,"special_surprise SAY_EXEC_THINK_8","Think, $N. Think back. Try and remember Durotar, $Gbrother:sister;! Remember the sacrifices our heroes made so that we could be free of the blood curse. Harken back to the Valley of Trials, where we were reborn into a world without demonic influence. We found the splendor of life, $N. Together! This isn't you. You were a champion of the Horde once!"),
(29068,35,0,12,0,100,"special_surprise SAY_EXEC_THINK_9","Think, $N. Think back. Try and remember the rolling plains of Mulgore, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the tauren once! This isn't you."),
(29068,36,0,12,0,100,"special_surprise SAY_EXEC_THINK_10","TINK $N. Tink back, mon! We be Darkspear, mon! Bruddas and sistas! Remember when we fought the Zalazane and done took he head and freed da Echo Isles? MON! TINK! You was a champion of da Darkspear trolls!"),
(29068,37,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_1","Listen to me, $N. You must fight against the Lich King's control. He is a monster that wants to see this world - our world - in ruin. Don't let him use you to accomplish his goals. You were once a hero and you can be again. Fight, damn you! Fight his control!"),
(29068,38,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_2","Listen to me, $N Ye must fight against the Lich King's control. He's a monster that wants to see this world - our world - in ruin. Don't let him use ye to accomplish his goals. Ye were once a hero and ye can be again. Fight, damn ye! Fight his control!"),
(29068,39,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_3","Listen to me, $N. You must fight against the Lich King's control. He is a monster that wants to see this world - our world - in ruin. Don't let him use you to accomplish his goals AGAIN. You were once a hero and you can be again. Fight, damn you! Fight his control!"),
(29068,40,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_4","Listen ta me, $Gbrudda:sista;. You must fight against da Lich King's control. He be a monstar dat want ta see dis world - our world - be ruined. Don't let he use you ta accomplish he goals. You be a hero once and you be a hero again! Fight it, mon! Fight he control!"),
(29068,42,0,12,0,100,"special_surprise SAY_EXEC_TIME_1","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Silvermoon. This world is worth saving!"),
(29068,43,0,12,0,100,"special_surprise SAY_EXEC_TIME_2","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Argus. Don't let that happen to this world."),
(29068,44,0,12,0,100,"special_surprise SAY_EXEC_TIME_3","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both $N... For KHAAAAAAAAZZZ MODAAAAAANNNNNN!!!"),
(29068,45,0,12,0,100,"special_surprise SAY_EXEC_TIME_4","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Tirisfal! This world is worth saving!"),
(29068,46,0,12,0,100,"special_surprise SAY_EXEC_TIME_5","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Gnomeregan! This world is worth saving."),
(29068,47,0,12,0,100,"special_surprise SAY_EXEC_TIME_6","There... There's no more time for me. I'm done for. FInish me off, $N. Do it or they'll kill us both. $N...Remember Elwynn. This world is worth saving."),
(29068,48,0,12,0,100,"special_surprise SAY_EXEC_TIME_7","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Teldrassil, our beloved home. This world is worth saving."),
(29068,49,0,12,0,100,"special_surprise SAY_EXEC_TIME_8","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... For the Horde! This world is worth saving."),
(29068,50,0,12,0,100,"special_surprise SAY_EXEC_TIME_9","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Mulgore. This world is worth saving."),
(29068,51,0,12,0,100,"special_surprise SAY_EXEC_TIME_10","Der... Der's no more time for me. I be done for. Finish me off $N. Do it or they'll kill us both. $N... Remember Sen'jin Village, mon! Dis world be worth saving!"),
(29068,52,0,12,0,100,"special_surprise SAY_EXEC_WAITING","Do it, $N! Put me out of my misery!"),
(29068,53,0,16,0,100,"special_surprise EMOTE_DIES","%s dies from his wounds."),
-- Valok the Righteous
(29070,0,0,12,0,100,"special_surprise SAY_EXEC_START_1","Come to finish the job, have you?"),
(29070,1,0,12,0,100,"special_surprise SAY_EXEC_START_2","Come to finish the job, have ye?"),
(29070,2,0,12,0,100,"special_surprise SAY_EXEC_START_3","Come ta finish da job, mon?"),
(29070,3,0,12,0,100,"special_surprise SAY_EXEC_PROG_1","You'll look me in the eyes when..."),
(29070,4,0,12,0,100,"special_surprise SAY_EXEC_PROG_2","Well this son o' Ironforge would like..."),
(29070,5,0,12,0,100,"special_surprise SAY_EXEC_PROG_3","Ironic, isn't it? To be killed..."),
(29070,6,0,12,0,100,"special_surprise SAY_EXEC_PROG_4","If you'd allow me just one..."),
(29070,7,0,12,0,100,"special_surprise SAY_EXEC_PROG_5","I'd like to stand for..."),
(29070,8,0,12,0,100,"special_surprise SAY_EXEC_PROG_6","I want to die like an orc..."),
(29070,9,0,12,0,100,"special_surprise SAY_EXEC_PROG_7","Dis troll gonna stand for da..."),
(29070,10,0,12,0,100,"special_surprise SAY_EXEC_NAME_1","$N?"),
(29070,11,0,12,0,100,"special_surprise SAY_EXEC_NAME_2","$N? Mon?"),
(29070,12,0,12,0,100,"special_surprise SAY_EXEC_RECOG_1","$N, I'd recognize that face anywhere... What... What have they done to you, $N?"),
(29070,13,0,12,0,100,"special_surprise SAY_EXEC_RECOG_2","$N, I'd recognize those face tentacles anywhere... What... What have they done to you, $N?"),
(29070,14,0,12,0,100,"special_surprise SAY_EXEC_RECOG_3","$N, I'd recognize that face anywhere... What... What have they done to ye, $Glad:lass;?"),
(29070,15,0,12,0,100,"special_surprise SAY_EXEC_RECOG_4","$N, I'd recognize that decay anywhere... What... What have they done to you, $N?"),
(29070,16,0,12,0,100,"special_surprise SAY_EXEC_RECOG_5","$N, I'd recognize those horns anywhere... What have they done to you, $N?"),
(29070,17,0,12,0,100,"special_surprise SAY_EXEC_RECOG_6","$N, I'd recognize dem tusks anywhere... What... What have dey done ta you, mon?"),
(29070,18,0,12,0,100,"special_surprise SAY_EXEC_NOREM_1","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you a draenei!"),
(29070,19,0,12,0,100,"special_surprise SAY_EXEC_NOREM_2","Ye don't remember me, do ye? Blasted Scourge... They've tried to drain ye o' everything that made ye a righteous force o' reckoning. Every last ounce o' good... Everything that made you a $Gson:daughter; of Ironforge!"),
(29070,20,0,12,0,100,"special_surprise SAY_EXEC_NOREM_3","You don't remember me, do you? We were humans once - long, long ago - until Lordaeron fell to the Scourge. Your transformation to a Scourge zombie came shortly after my own. Not long after that, our minds were freed by the Dark Lady."),
(29070,21,0,12,0,100,"special_surprise SAY_EXEC_NOREM_4","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a pint-sized force of reckoning. Every last ounce of good... Everything that made you a gnome!"),
(29070,22,0,12,0,100,"special_surprise SAY_EXEC_NOREM_5","You don't remember me, do you? Blasted Scourge...They've tried to drain of everything that made you a righteous force of reckoning. Every last ounce of good...Everything that made you a human!"),
(29070,23,0,12,0,100,"special_surprise SAY_EXEC_NOREM_6","You don't remember me? When you were a child your mother would leave you in my care while she served at the Temple of the Moon. I held you in my arms and fed you with honey and sheep's milk to calm you until she would return. You were my little angel. Blasted Scourge... What have they done to you, $N?"),
(29070,24,0,12,0,100,"special_surprise SAY_EXEC_NOREM_7","You don't recognize me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you an orc!"),
(29070,25,0,12,0,100,"special_surprise SAY_EXEC_NOREM_8","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you a tauren!"),
(29070,26,0,12,0,100,"special_surprise SAY_EXEC_NOREM_9","You don't remember me, mon? Damn da Scourge! Dey gone ta drain you of everytin dat made ya a mojo masta. Every last ounce of good... Everytin' dat made ya a troll hero, mon!"),
(29070,27,0,12,0,100,"special_surprise SAY_EXEC_THINK_1","A pact was made, $Gbrother:sister;! We vowed vengeance against the Lich King! For what he had done to us! We battled the Scourge as Forsaken, pushing them back into the plaguelands and freeing Tirisfal! You and I were champions of the Forsaken!"),
(29070,28,0,12,0,100,"special_surprise SAY_EXEC_THINK_2","You must remember the splendor of life, $Gbrother:sister;. You were a champion of the Kaldorei once! This isn't you!"),
(29070,29,0,12,0,100,"special_surprise SAY_EXEC_THINK_3","Think, $N. Think back. Try and remember the majestic halls of Silvermoon City, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the sin'dorei once! This isn't you."),
(29070,30,0,12,0,100,"special_surprise SAY_EXEC_THINK_4","Think, $N. Think back. Try and remember the proud mountains of Argus, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the draenei once! This isn't you."),
(29070,31,0,12,0,100,"special_surprise SAY_EXEC_THINK_5","Think, $N. Think back. Try and remember the snow capped mountains o' Dun Morogh! Ye were born there, $Glad:lass;. Remember the splendor o' life, $N! Ye were a champion o' the dwarves once! This isn't ye!"),
(29070,32,0,12,0,100,"special_surprise SAY_EXEC_THINK_6","Think, $N. Think back. Try and remember Gnomeregan before those damned troggs! Remember the feel of an [arclight spanner] $Gbrother:sister;. You were a champion of gnome-kind once! This isn't you."),
(29070,33,0,12,0,100,"special_surprise SAY_EXEC_THINK_7","Think, $N. Think back. Try and remember the hills and valleys of Elwynn, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the Alliance once! This isn't you."),
(29070,34,0,12,0,100,"special_surprise SAY_EXEC_THINK_8","Think, $N. Think back. Try and remember Durotar, $Gbrother:sister;! Remember the sacrifices our heroes made so that we could be free of the blood curse. Harken back to the Valley of Trials, where we were reborn into a world without demonic influence. We found the splendor of life, $N. Together! This isn't you. You were a champion of the Horde once!"),
(29070,35,0,12,0,100,"special_surprise SAY_EXEC_THINK_9","Think, $N. Think back. Try and remember the rolling plains of Mulgore, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the tauren once! This isn't you."),
(29070,36,0,12,0,100,"special_surprise SAY_EXEC_THINK_10","TINK $N. Tink back, mon! We be Darkspear, mon! Bruddas and sistas! Remember when we fought the Zalazane and done took he head and freed da Echo Isles? MON! TINK! You was a champion of da Darkspear trolls!"),
(29070,37,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_1","Listen to me, $N. You must fight against the Lich King's control. He is a monster that wants to see this world - our world - in ruin. Don't let him use you to accomplish his goals. You were once a hero and you can be again. Fight, damn you! Fight his control!"),
(29070,38,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_2","Listen to me, $N Ye must fight against the Lich King's control. He's a monster that wants to see this world - our world - in ruin. Don't let him use ye to accomplish his goals. Ye were once a hero and ye can be again. Fight, damn ye! Fight his control!"),
(29070,39,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_3","Listen to me, $N. You must fight against the Lich King's control. He is a monster that wants to see this world - our world - in ruin. Don't let him use you to accomplish his goals AGAIN. You were once a hero and you can be again. Fight, damn you! Fight his control!"),
(29070,40,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_4","Listen ta me, $Gbrudda:sista;. You must fight against da Lich King's control. He be a monstar dat want ta see dis world - our world - be ruined. Don't let he use you ta accomplish he goals. You be a hero once and you be a hero again! Fight it, mon! Fight he control!"),
(29070,42,0,12,0,100,"special_surprise SAY_EXEC_TIME_1","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Silvermoon. This world is worth saving!"),
(29070,43,0,12,0,100,"special_surprise SAY_EXEC_TIME_2","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Argus. Don't let that happen to this world."),
(29070,44,0,12,0,100,"special_surprise SAY_EXEC_TIME_3","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both $N... For KHAAAAAAAAZZZ MODAAAAAANNNNNN!!!"),
(29070,45,0,12,0,100,"special_surprise SAY_EXEC_TIME_4","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Tirisfal! This world is worth saving!"),
(29070,46,0,12,0,100,"special_surprise SAY_EXEC_TIME_5","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Gnomeregan! This world is worth saving."),
(29070,47,0,12,0,100,"special_surprise SAY_EXEC_TIME_6","There... There's no more time for me. I'm done for. FInish me off, $N. Do it or they'll kill us both. $N...Remember Elwynn. This world is worth saving."),
(29070,48,0,12,0,100,"special_surprise SAY_EXEC_TIME_7","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Teldrassil, our beloved home. This world is worth saving."),
(29070,49,0,12,0,100,"special_surprise SAY_EXEC_TIME_8","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... For the Horde! This world is worth saving."),
(29070,50,0,12,0,100,"special_surprise SAY_EXEC_TIME_9","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Mulgore. This world is worth saving."),
(29070,51,0,12,0,100,"special_surprise SAY_EXEC_TIME_10","Der... Der's no more time for me. I be done for. Finish me off $N. Do it or they'll kill us both. $N... Remember Sen'jin Village, mon! Dis world be worth saving!"),
(29070,52,0,12,0,100,"special_surprise SAY_EXEC_WAITING","Do it, $N! Put me out of my misery!"),
(29070,53,0,16,0,100,"special_surprise EMOTE_DIES","%s dies from his wounds."),
-- Lady Eonys
(29074,0,0,12,0,100,"special_surprise SAY_EXEC_START_1","Come to finish the job, have you?"),
(29074,1,0,12,0,100,"special_surprise SAY_EXEC_START_2","Come to finish the job, have ye?"),
(29074,2,0,12,0,100,"special_surprise SAY_EXEC_START_3","Come ta finish da job, mon?"),
(29074,3,0,12,0,100,"special_surprise SAY_EXEC_PROG_1","You'll look me in the eyes when..."),
(29074,4,0,12,0,100,"special_surprise SAY_EXEC_PROG_2","Well this son o' Ironforge would like..."),
(29074,5,0,12,0,100,"special_surprise SAY_EXEC_PROG_3","Ironic, isn't it? To be killed..."),
(29074,6,0,12,0,100,"special_surprise SAY_EXEC_PROG_4","If you'd allow me just one..."),
(29074,7,0,12,0,100,"special_surprise SAY_EXEC_PROG_5","I'd like to stand for..."),
(29074,8,0,12,0,100,"special_surprise SAY_EXEC_PROG_6","I want to die like an orc..."),
(29074,9,0,12,0,100,"special_surprise SAY_EXEC_PROG_7","Dis troll gonna stand for da..."),
(29074,10,0,12,0,100,"special_surprise SAY_EXEC_NAME_1","$N?"),
(29074,11,0,12,0,100,"special_surprise SAY_EXEC_NAME_2","$N? Mon?"),
(29074,12,0,12,0,100,"special_surprise SAY_EXEC_RECOG_1","$N, I'd recognize that face anywhere... What... What have they done to you, $N?"),
(29074,13,0,12,0,100,"special_surprise SAY_EXEC_RECOG_2","$N, I'd recognize those face tentacles anywhere... What... What have they done to you, $N?"),
(29074,14,0,12,0,100,"special_surprise SAY_EXEC_RECOG_3","$N, I'd recognize that face anywhere... What... What have they done to ye, $Glad:lass;?"),
(29074,15,0,12,0,100,"special_surprise SAY_EXEC_RECOG_4","$N, I'd recognize that decay anywhere... What... What have they done to you, $N?"),
(29074,16,0,12,0,100,"special_surprise SAY_EXEC_RECOG_5","$N, I'd recognize those horns anywhere... What have they done to you, $N?"),
(29074,17,0,12,0,100,"special_surprise SAY_EXEC_RECOG_6","$N, I'd recognize dem tusks anywhere... What... What have dey done ta you, mon?"),
(29074,18,0,12,0,100,"special_surprise SAY_EXEC_NOREM_1","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you a draenei!"),
(29074,19,0,12,0,100,"special_surprise SAY_EXEC_NOREM_2","Ye don't remember me, do ye? Blasted Scourge... They've tried to drain ye o' everything that made ye a righteous force o' reckoning. Every last ounce o' good... Everything that made you a $Gson:daughter; of Ironforge!"),
(29074,20,0,12,0,100,"special_surprise SAY_EXEC_NOREM_3","You don't remember me, do you? We were humans once - long, long ago - until Lordaeron fell to the Scourge. Your transformation to a Scourge zombie came shortly after my own. Not long after that, our minds were freed by the Dark Lady."),
(29074,21,0,12,0,100,"special_surprise SAY_EXEC_NOREM_4","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a pint-sized force of reckoning. Every last ounce of good... Everything that made you a gnome!"),
(29074,22,0,12,0,100,"special_surprise SAY_EXEC_NOREM_5","You don't remember me, do you? Blasted Scourge...They've tried to drain of everything that made you a righteous force of reckoning. Every last ounce of good...Everything that made you a human!"),
(29074,23,0,12,0,100,"special_surprise SAY_EXEC_NOREM_6","You don't remember me? When you were a child your mother would leave you in my care while she served at the Temple of the Moon. I held you in my arms and fed you with honey and sheep's milk to calm you until she would return. You were my little angel. Blasted Scourge... What have they done to you, $N?"),
(29074,24,0,12,0,100,"special_surprise SAY_EXEC_NOREM_7","You don't recognize me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you an orc!"),
(29074,25,0,12,0,100,"special_surprise SAY_EXEC_NOREM_8","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you a tauren!"),
(29074,26,0,12,0,100,"special_surprise SAY_EXEC_NOREM_9","You don't remember me, mon? Damn da Scourge! Dey gone ta drain you of everytin dat made ya a mojo masta. Every last ounce of good... Everytin' dat made ya a troll hero, mon!"),
(29074,27,0,12,0,100,"special_surprise SAY_EXEC_THINK_1","A pact was made, $Gbrother:sister;! We vowed vengeance against the Lich King! For what he had done to us! We battled the Scourge as Forsaken, pushing them back into the plaguelands and freeing Tirisfal! You and I were champions of the Forsaken!"),
(29074,28,0,12,0,100,"special_surprise SAY_EXEC_THINK_2","You must remember the splendor of life, $Gbrother:sister;. You were a champion of the Kaldorei once! This isn't you!"),
(29074,29,0,12,0,100,"special_surprise SAY_EXEC_THINK_3","Think, $N. Think back. Try and remember the majestic halls of Silvermoon City, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the sin'dorei once! This isn't you."),
(29074,30,0,12,0,100,"special_surprise SAY_EXEC_THINK_4","Think, $N. Think back. Try and remember the proud mountains of Argus, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the draenei once! This isn't you."),
(29074,31,0,12,0,100,"special_surprise SAY_EXEC_THINK_5","Think, $N. Think back. Try and remember the snow capped mountains o' Dun Morogh! Ye were born there, $Glad:lass;. Remember the splendor o' life, $N! Ye were a champion o' the dwarves once! This isn't ye!"),
(29074,32,0,12,0,100,"special_surprise SAY_EXEC_THINK_6","Think, $N. Think back. Try and remember Gnomeregan before those damned troggs! Remember the feel of an [arclight spanner] $Gbrother:sister;. You were a champion of gnome-kind once! This isn't you."),
(29074,33,0,12,0,100,"special_surprise SAY_EXEC_THINK_7","Think, $N. Think back. Try and remember the hills and valleys of Elwynn, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the Alliance once! This isn't you."),
(29074,34,0,12,0,100,"special_surprise SAY_EXEC_THINK_8","Think, $N. Think back. Try and remember Durotar, $Gbrother:sister;! Remember the sacrifices our heroes made so that we could be free of the blood curse. Harken back to the Valley of Trials, where we were reborn into a world without demonic influence. We found the splendor of life, $N. Together! This isn't you. You were a champion of the Horde once!"),
(29074,35,0,12,0,100,"special_surprise SAY_EXEC_THINK_9","Think, $N. Think back. Try and remember the rolling plains of Mulgore, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the tauren once! This isn't you."),
(29074,36,0,12,0,100,"special_surprise SAY_EXEC_THINK_10","TINK $N. Tink back, mon! We be Darkspear, mon! Bruddas and sistas! Remember when we fought the Zalazane and done took he head and freed da Echo Isles? MON! TINK! You was a champion of da Darkspear trolls!"),
(29074,37,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_1","Listen to me, $N. You must fight against the Lich King's control. He is a monster that wants to see this world - our world - in ruin. Don't let him use you to accomplish his goals. You were once a hero and you can be again. Fight, damn you! Fight his control!"),
(29074,38,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_2","Listen to me, $N Ye must fight against the Lich King's control. He's a monster that wants to see this world - our world - in ruin. Don't let him use ye to accomplish his goals. Ye were once a hero and ye can be again. Fight, damn ye! Fight his control!"),
(29074,39,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_3","Listen to me, $N. You must fight against the Lich King's control. He is a monster that wants to see this world - our world - in ruin. Don't let him use you to accomplish his goals AGAIN. You were once a hero and you can be again. Fight, damn you! Fight his control!"),
(29074,40,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_4","Listen ta me, $Gbrudda:sista;. You must fight against da Lich King's control. He be a monstar dat want ta see dis world - our world - be ruined. Don't let he use you ta accomplish he goals. You be a hero once and you be a hero again! Fight it, mon! Fight he control!"),
(29074,42,0,12,0,100,"special_surprise SAY_EXEC_TIME_1","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Silvermoon. This world is worth saving!"),
(29074,43,0,12,0,100,"special_surprise SAY_EXEC_TIME_2","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Argus. Don't let that happen to this world."),
(29074,44,0,12,0,100,"special_surprise SAY_EXEC_TIME_3","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both $N... For KHAAAAAAAAZZZ MODAAAAAANNNNNN!!!"),
(29074,45,0,12,0,100,"special_surprise SAY_EXEC_TIME_4","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Tirisfal! This world is worth saving!"),
(29074,46,0,12,0,100,"special_surprise SAY_EXEC_TIME_5","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Gnomeregan! This world is worth saving."),
(29074,47,0,12,0,100,"special_surprise SAY_EXEC_TIME_6","There... There's no more time for me. I'm done for. FInish me off, $N. Do it or they'll kill us both. $N...Remember Elwynn. This world is worth saving."),
(29074,48,0,12,0,100,"special_surprise SAY_EXEC_TIME_7","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Teldrassil, our beloved home. This world is worth saving."),
(29074,49,0,12,0,100,"special_surprise SAY_EXEC_TIME_8","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... For the Horde! This world is worth saving."),
(29074,50,0,12,0,100,"special_surprise SAY_EXEC_TIME_9","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Mulgore. This world is worth saving."),
(29074,51,0,12,0,100,"special_surprise SAY_EXEC_TIME_10","Der... Der's no more time for me. I be done for. Finish me off $N. Do it or they'll kill us both. $N... Remember Sen'jin Village, mon! Dis world be worth saving!"),
(29074,52,0,12,0,100,"special_surprise SAY_EXEC_WAITING","Do it, $N! Put me out of my misery!"),
(29074,53,0,16,0,100,"special_surprise EMOTE_DIES","%s dies from his wounds."),
-- Kug Ironjaw
(29072,0,0,12,0,100,"special_surprise SAY_EXEC_START_1","Come to finish the job, have you?"),
(29072,1,0,12,0,100,"special_surprise SAY_EXEC_START_2","Come to finish the job, have ye?"),
(29072,2,0,12,0,100,"special_surprise SAY_EXEC_START_3","Come ta finish da job, mon?"),
(29072,3,0,12,0,100,"special_surprise SAY_EXEC_PROG_1","You'll look me in the eyes when..."),
(29072,4,0,12,0,100,"special_surprise SAY_EXEC_PROG_2","Well this son o' Ironforge would like..."),
(29072,5,0,12,0,100,"special_surprise SAY_EXEC_PROG_3","Ironic, isn't it? To be killed..."),
(29072,6,0,12,0,100,"special_surprise SAY_EXEC_PROG_4","If you'd allow me just one..."),
(29072,7,0,12,0,100,"special_surprise SAY_EXEC_PROG_5","I'd like to stand for..."),
(29072,8,0,12,0,100,"special_surprise SAY_EXEC_PROG_6","I want to die like an orc..."),
(29072,9,0,12,0,100,"special_surprise SAY_EXEC_PROG_7","Dis troll gonna stand for da..."),
(29072,10,0,12,0,100,"special_surprise SAY_EXEC_NAME_1","$N?"),
(29072,11,0,12,0,100,"special_surprise SAY_EXEC_NAME_2","$N? Mon?"),
(29072,12,0,12,0,100,"special_surprise SAY_EXEC_RECOG_1","$N, I'd recognize that face anywhere... What... What have they done to you, $N?"),
(29072,13,0,12,0,100,"special_surprise SAY_EXEC_RECOG_2","$N, I'd recognize those face tentacles anywhere... What... What have they done to you, $N?"),
(29072,14,0,12,0,100,"special_surprise SAY_EXEC_RECOG_3","$N, I'd recognize that face anywhere... What... What have they done to ye, $Glad:lass;?"),
(29072,15,0,12,0,100,"special_surprise SAY_EXEC_RECOG_4","$N, I'd recognize that decay anywhere... What... What have they done to you, $N?"),
(29072,16,0,12,0,100,"special_surprise SAY_EXEC_RECOG_5","$N, I'd recognize those horns anywhere... What have they done to you, $N?"),
(29072,17,0,12,0,100,"special_surprise SAY_EXEC_RECOG_6","$N, I'd recognize dem tusks anywhere... What... What have dey done ta you, mon?"),
(29072,18,0,12,0,100,"special_surprise SAY_EXEC_NOREM_1","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you a draenei!"),
(29072,19,0,12,0,100,"special_surprise SAY_EXEC_NOREM_2","Ye don't remember me, do ye? Blasted Scourge... They've tried to drain ye o' everything that made ye a righteous force o' reckoning. Every last ounce o' good... Everything that made you a $Gson:daughter; of Ironforge!"),
(29072,20,0,12,0,100,"special_surprise SAY_EXEC_NOREM_3","You don't remember me, do you? We were humans once - long, long ago - until Lordaeron fell to the Scourge. Your transformation to a Scourge zombie came shortly after my own. Not long after that, our minds were freed by the Dark Lady."),
(29072,21,0,12,0,100,"special_surprise SAY_EXEC_NOREM_4","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a pint-sized force of reckoning. Every last ounce of good... Everything that made you a gnome!"),
(29072,22,0,12,0,100,"special_surprise SAY_EXEC_NOREM_5","You don't remember me, do you? Blasted Scourge...They've tried to drain of everything that made you a righteous force of reckoning. Every last ounce of good...Everything that made you a human!"),
(29072,23,0,12,0,100,"special_surprise SAY_EXEC_NOREM_6","You don't remember me? When you were a child your mother would leave you in my care while she served at the Temple of the Moon. I held you in my arms and fed you with honey and sheep's milk to calm you until she would return. You were my little angel. Blasted Scourge... What have they done to you, $N?"),
(29072,24,0,12,0,100,"special_surprise SAY_EXEC_NOREM_7","You don't recognize me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you an orc!"),
(29072,25,0,12,0,100,"special_surprise SAY_EXEC_NOREM_8","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you a tauren!"),
(29072,26,0,12,0,100,"special_surprise SAY_EXEC_NOREM_9","You don't remember me, mon? Damn da Scourge! Dey gone ta drain you of everytin dat made ya a mojo masta. Every last ounce of good... Everytin' dat made ya a troll hero, mon!"),
(29072,27,0,12,0,100,"special_surprise SAY_EXEC_THINK_1","A pact was made, $Gbrother:sister;! We vowed vengeance against the Lich King! For what he had done to us! We battled the Scourge as Forsaken, pushing them back into the plaguelands and freeing Tirisfal! You and I were champions of the Forsaken!"),
(29072,28,0,12,0,100,"special_surprise SAY_EXEC_THINK_2","You must remember the splendor of life, $Gbrother:sister;. You were a champion of the Kaldorei once! This isn't you!"),
(29072,29,0,12,0,100,"special_surprise SAY_EXEC_THINK_3","Think, $N. Think back. Try and remember the majestic halls of Silvermoon City, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the sin'dorei once! This isn't you."),
(29072,30,0,12,0,100,"special_surprise SAY_EXEC_THINK_4","Think, $N. Think back. Try and remember the proud mountains of Argus, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the draenei once! This isn't you."),
(29072,31,0,12,0,100,"special_surprise SAY_EXEC_THINK_5","Think, $N. Think back. Try and remember the snow capped mountains o' Dun Morogh! Ye were born there, $Glad:lass;. Remember the splendor o' life, $N! Ye were a champion o' the dwarves once! This isn't ye!"),
(29072,32,0,12,0,100,"special_surprise SAY_EXEC_THINK_6","Think, $N. Think back. Try and remember Gnomeregan before those damned troggs! Remember the feel of an [arclight spanner] $Gbrother:sister;. You were a champion of gnome-kind once! This isn't you."),
(29072,33,0,12,0,100,"special_surprise SAY_EXEC_THINK_7","Think, $N. Think back. Try and remember the hills and valleys of Elwynn, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the Alliance once! This isn't you."),
(29072,34,0,12,0,100,"special_surprise SAY_EXEC_THINK_8","Think, $N. Think back. Try and remember Durotar, $Gbrother:sister;! Remember the sacrifices our heroes made so that we could be free of the blood curse. Harken back to the Valley of Trials, where we were reborn into a world without demonic influence. We found the splendor of life, $N. Together! This isn't you. You were a champion of the Horde once!"),
(29072,35,0,12,0,100,"special_surprise SAY_EXEC_THINK_9","Think, $N. Think back. Try and remember the rolling plains of Mulgore, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the tauren once! This isn't you."),
(29072,36,0,12,0,100,"special_surprise SAY_EXEC_THINK_10","TINK $N. Tink back, mon! We be Darkspear, mon! Bruddas and sistas! Remember when we fought the Zalazane and done took he head and freed da Echo Isles? MON! TINK! You was a champion of da Darkspear trolls!"),
(29072,37,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_1","Listen to me, $N. You must fight against the Lich King's control. He is a monster that wants to see this world - our world - in ruin. Don't let him use you to accomplish his goals. You were once a hero and you can be again. Fight, damn you! Fight his control!"),
(29072,38,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_2","Listen to me, $N Ye must fight against the Lich King's control. He's a monster that wants to see this world - our world - in ruin. Don't let him use ye to accomplish his goals. Ye were once a hero and ye can be again. Fight, damn ye! Fight his control!"),
(29072,39,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_3","Listen to me, $N. You must fight against the Lich King's control. He is a monster that wants to see this world - our world - in ruin. Don't let him use you to accomplish his goals AGAIN. You were once a hero and you can be again. Fight, damn you! Fight his control!"),
(29072,40,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_4","Listen ta me, $Gbrudda:sista;. You must fight against da Lich King's control. He be a monstar dat want ta see dis world - our world - be ruined. Don't let he use you ta accomplish he goals. You be a hero once and you be a hero again! Fight it, mon! Fight he control!"),
(29072,42,0,12,0,100,"special_surprise SAY_EXEC_TIME_1","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Silvermoon. This world is worth saving!"),
(29072,43,0,12,0,100,"special_surprise SAY_EXEC_TIME_2","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Argus. Don't let that happen to this world."),
(29072,44,0,12,0,100,"special_surprise SAY_EXEC_TIME_3","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both $N... For KHAAAAAAAAZZZ MODAAAAAANNNNNN!!!"),
(29072,45,0,12,0,100,"special_surprise SAY_EXEC_TIME_4","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Tirisfal! This world is worth saving!"),
(29072,46,0,12,0,100,"special_surprise SAY_EXEC_TIME_5","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Gnomeregan! This world is worth saving."),
(29072,47,0,12,0,100,"special_surprise SAY_EXEC_TIME_6","There... There's no more time for me. I'm done for. FInish me off, $N. Do it or they'll kill us both. $N...Remember Elwynn. This world is worth saving."),
(29072,48,0,12,0,100,"special_surprise SAY_EXEC_TIME_7","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Teldrassil, our beloved home. This world is worth saving."),
(29072,49,0,12,0,100,"special_surprise SAY_EXEC_TIME_8","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... For the Horde! This world is worth saving."),
(29072,50,0,12,0,100,"special_surprise SAY_EXEC_TIME_9","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Mulgore. This world is worth saving."),
(29072,51,0,12,0,100,"special_surprise SAY_EXEC_TIME_10","Der... Der's no more time for me. I be done for. Finish me off $N. Do it or they'll kill us both. $N... Remember Sen'jin Village, mon! Dis world be worth saving!"),
(29072,52,0,12,0,100,"special_surprise SAY_EXEC_WAITING","Do it, $N! Put me out of my misery!"),
(29072,53,0,16,0,100,"special_surprise EMOTE_DIES","%s dies from his wounds."),
-- Iggy Darktusk
(29073,0,0,12,0,100,"special_surprise SAY_EXEC_START_1","Come to finish the job, have you?"),
(29073,1,0,12,0,100,"special_surprise SAY_EXEC_START_2","Come to finish the job, have ye?"),
(29073,2,0,12,0,100,"special_surprise SAY_EXEC_START_3","Come ta finish da job, mon?"),
(29073,3,0,12,0,100,"special_surprise SAY_EXEC_PROG_1","You'll look me in the eyes when..."),
(29073,4,0,12,0,100,"special_surprise SAY_EXEC_PROG_2","Well this son o' Ironforge would like..."),
(29073,5,0,12,0,100,"special_surprise SAY_EXEC_PROG_3","Ironic, isn't it? To be killed..."),
(29073,6,0,12,0,100,"special_surprise SAY_EXEC_PROG_4","If you'd allow me just one..."),
(29073,7,0,12,0,100,"special_surprise SAY_EXEC_PROG_5","I'd like to stand for..."),
(29073,8,0,12,0,100,"special_surprise SAY_EXEC_PROG_6","I want to die like an orc..."),
(29073,9,0,12,0,100,"special_surprise SAY_EXEC_PROG_7","Dis troll gonna stand for da..."),
(29073,10,0,12,0,100,"special_surprise SAY_EXEC_NAME_1","$N?"),
(29073,11,0,12,0,100,"special_surprise SAY_EXEC_NAME_2","$N? Mon?"),
(29073,12,0,12,0,100,"special_surprise SAY_EXEC_RECOG_1","$N, I'd recognize that face anywhere... What... What have they done to you, $N?"),
(29073,13,0,12,0,100,"special_surprise SAY_EXEC_RECOG_2","$N, I'd recognize those face tentacles anywhere... What... What have they done to you, $N?"),
(29073,14,0,12,0,100,"special_surprise SAY_EXEC_RECOG_3","$N, I'd recognize that face anywhere... What... What have they done to ye, $Glad:lass;?"),
(29073,15,0,12,0,100,"special_surprise SAY_EXEC_RECOG_4","$N, I'd recognize that decay anywhere... What... What have they done to you, $N?"),
(29073,16,0,12,0,100,"special_surprise SAY_EXEC_RECOG_5","$N, I'd recognize those horns anywhere... What have they done to you, $N?"),
(29073,17,0,12,0,100,"special_surprise SAY_EXEC_RECOG_6","$N, I'd recognize dem tusks anywhere... What... What have dey done ta you, mon?"),
(29073,18,0,12,0,100,"special_surprise SAY_EXEC_NOREM_1","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you a draenei!"),
(29073,19,0,12,0,100,"special_surprise SAY_EXEC_NOREM_2","Ye don't remember me, do ye? Blasted Scourge... They've tried to drain ye o' everything that made ye a righteous force o' reckoning. Every last ounce o' good... Everything that made you a $Gson:daughter; of Ironforge!"),
(29073,20,0,12,0,100,"special_surprise SAY_EXEC_NOREM_3","You don't remember me, do you? We were humans once - long, long ago - until Lordaeron fell to the Scourge. Your transformation to a Scourge zombie came shortly after my own. Not long after that, our minds were freed by the Dark Lady."),
(29073,21,0,12,0,100,"special_surprise SAY_EXEC_NOREM_4","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a pint-sized force of reckoning. Every last ounce of good... Everything that made you a gnome!"),
(29073,22,0,12,0,100,"special_surprise SAY_EXEC_NOREM_5","You don't remember me, do you? Blasted Scourge...They've tried to drain of everything that made you a righteous force of reckoning. Every last ounce of good...Everything that made you a human!"),
(29073,23,0,12,0,100,"special_surprise SAY_EXEC_NOREM_6","You don't remember me? When you were a child your mother would leave you in my care while she served at the Temple of the Moon. I held you in my arms and fed you with honey and sheep's milk to calm you until she would return. You were my little angel. Blasted Scourge... What have they done to you, $N?"),
(29073,24,0,12,0,100,"special_surprise SAY_EXEC_NOREM_7","You don't recognize me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you an orc!"),
(29073,25,0,12,0,100,"special_surprise SAY_EXEC_NOREM_8","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you a tauren!"),
(29073,26,0,12,0,100,"special_surprise SAY_EXEC_NOREM_9","You don't remember me, mon? Damn da Scourge! Dey gone ta drain you of everytin dat made ya a mojo masta. Every last ounce of good... Everytin' dat made ya a troll hero, mon!"),
(29073,27,0,12,0,100,"special_surprise SAY_EXEC_THINK_1","A pact was made, $Gbrother:sister;! We vowed vengeance against the Lich King! For what he had done to us! We battled the Scourge as Forsaken, pushing them back into the plaguelands and freeing Tirisfal! You and I were champions of the Forsaken!"),
(29073,28,0,12,0,100,"special_surprise SAY_EXEC_THINK_2","You must remember the splendor of life, $Gbrother:sister;. You were a champion of the Kaldorei once! This isn't you!"),
(29073,29,0,12,0,100,"special_surprise SAY_EXEC_THINK_3","Think, $N. Think back. Try and remember the majestic halls of Silvermoon City, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the sin'dorei once! This isn't you."),
(29073,30,0,12,0,100,"special_surprise SAY_EXEC_THINK_4","Think, $N. Think back. Try and remember the proud mountains of Argus, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the draenei once! This isn't you."),
(29073,31,0,12,0,100,"special_surprise SAY_EXEC_THINK_5","Think, $N. Think back. Try and remember the snow capped mountains o' Dun Morogh! Ye were born there, $Glad:lass;. Remember the splendor o' life, $N! Ye were a champion o' the dwarves once! This isn't ye!"),
(29073,32,0,12,0,100,"special_surprise SAY_EXEC_THINK_6","Think, $N. Think back. Try and remember Gnomeregan before those damned troggs! Remember the feel of an [arclight spanner] $Gbrother:sister;. You were a champion of gnome-kind once! This isn't you."),
(29073,33,0,12,0,100,"special_surprise SAY_EXEC_THINK_7","Think, $N. Think back. Try and remember the hills and valleys of Elwynn, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the Alliance once! This isn't you."),
(29073,34,0,12,0,100,"special_surprise SAY_EXEC_THINK_8","Think, $N. Think back. Try and remember Durotar, $Gbrother:sister;! Remember the sacrifices our heroes made so that we could be free of the blood curse. Harken back to the Valley of Trials, where we were reborn into a world without demonic influence. We found the splendor of life, $N. Together! This isn't you. You were a champion of the Horde once!"),
(29073,35,0,12,0,100,"special_surprise SAY_EXEC_THINK_9","Think, $N. Think back. Try and remember the rolling plains of Mulgore, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the tauren once! This isn't you."),
(29073,36,0,12,0,100,"special_surprise SAY_EXEC_THINK_10","TINK $N. Tink back, mon! We be Darkspear, mon! Bruddas and sistas! Remember when we fought the Zalazane and done took he head and freed da Echo Isles? MON! TINK! You was a champion of da Darkspear trolls!"),
(29073,37,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_1","Listen to me, $N. You must fight against the Lich King's control. He is a monster that wants to see this world - our world - in ruin. Don't let him use you to accomplish his goals. You were once a hero and you can be again. Fight, damn you! Fight his control!"),
(29073,38,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_2","Listen to me, $N Ye must fight against the Lich King's control. He's a monster that wants to see this world - our world - in ruin. Don't let him use ye to accomplish his goals. Ye were once a hero and ye can be again. Fight, damn ye! Fight his control!"),
(29073,39,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_3","Listen to me, $N. You must fight against the Lich King's control. He is a monster that wants to see this world - our world - in ruin. Don't let him use you to accomplish his goals AGAIN. You were once a hero and you can be again. Fight, damn you! Fight his control!"),
(29073,40,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_4","Listen ta me, $Gbrudda:sista;. You must fight against da Lich King's control. He be a monstar dat want ta see dis world - our world - be ruined. Don't let he use you ta accomplish he goals. You be a hero once and you be a hero again! Fight it, mon! Fight he control!"),
(29073,42,0,12,0,100,"special_surprise SAY_EXEC_TIME_1","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Silvermoon. This world is worth saving!"),
(29073,43,0,12,0,100,"special_surprise SAY_EXEC_TIME_2","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Argus. Don't let that happen to this world."),
(29073,44,0,12,0,100,"special_surprise SAY_EXEC_TIME_3","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both $N... For KHAAAAAAAAZZZ MODAAAAAANNNNNN!!!"),
(29073,45,0,12,0,100,"special_surprise SAY_EXEC_TIME_4","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Tirisfal! This world is worth saving!"),
(29073,46,0,12,0,100,"special_surprise SAY_EXEC_TIME_5","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Gnomeregan! This world is worth saving."),
(29073,47,0,12,0,100,"special_surprise SAY_EXEC_TIME_6","There... There's no more time for me. I'm done for. FInish me off, $N. Do it or they'll kill us both. $N...Remember Elwynn. This world is worth saving."),
(29073,48,0,12,0,100,"special_surprise SAY_EXEC_TIME_7","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Teldrassil, our beloved home. This world is worth saving."),
(29073,49,0,12,0,100,"special_surprise SAY_EXEC_TIME_8","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... For the Horde! This world is worth saving."),
(29073,50,0,12,0,100,"special_surprise SAY_EXEC_TIME_9","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Mulgore. This world is worth saving."),
(29073,51,0,12,0,100,"special_surprise SAY_EXEC_TIME_10","Der... Der's no more time for me. I be done for. Finish me off $N. Do it or they'll kill us both. $N... Remember Sen'jin Village, mon! Dis world be worth saving!"),
(29073,52,0,12,0,100,"special_surprise SAY_EXEC_WAITING","Do it, $N! Put me out of my misery!"),
(29073,53,0,16,0,100,"special_surprise EMOTE_DIES","%s dies from his wounds."),
-- Antoine Brack
(29071,0,0,12,0,100,"special_surprise SAY_EXEC_START_1","Come to finish the job, have you?"),
(29071,1,0,12,0,100,"special_surprise SAY_EXEC_START_2","Come to finish the job, have ye?"),
(29071,2,0,12,0,100,"special_surprise SAY_EXEC_START_3","Come ta finish da job, mon?"),
(29071,3,0,12,0,100,"special_surprise SAY_EXEC_PROG_1","You'll look me in the eyes when..."),
(29071,4,0,12,0,100,"special_surprise SAY_EXEC_PROG_2","Well this son o' Ironforge would like..."),
(29071,5,0,12,0,100,"special_surprise SAY_EXEC_PROG_3","Ironic, isn't it? To be killed..."),
(29071,6,0,12,0,100,"special_surprise SAY_EXEC_PROG_4","If you'd allow me just one..."),
(29071,7,0,12,0,100,"special_surprise SAY_EXEC_PROG_5","I'd like to stand for..."),
(29071,8,0,12,0,100,"special_surprise SAY_EXEC_PROG_6","I want to die like an orc..."),
(29071,9,0,12,0,100,"special_surprise SAY_EXEC_PROG_7","Dis troll gonna stand for da..."),
(29071,10,0,12,0,100,"special_surprise SAY_EXEC_NAME_1","$N?"),
(29071,11,0,12,0,100,"special_surprise SAY_EXEC_NAME_2","$N? Mon?"),
(29071,12,0,12,0,100,"special_surprise SAY_EXEC_RECOG_1","$N, I'd recognize that face anywhere... What... What have they done to you, $N?"),
(29071,13,0,12,0,100,"special_surprise SAY_EXEC_RECOG_2","$N, I'd recognize those face tentacles anywhere... What... What have they done to you, $N?"),
(29071,14,0,12,0,100,"special_surprise SAY_EXEC_RECOG_3","$N, I'd recognize that face anywhere... What... What have they done to ye, $Glad:lass;?"),
(29071,15,0,12,0,100,"special_surprise SAY_EXEC_RECOG_4","$N, I'd recognize that decay anywhere... What... What have they done to you, $N?"),
(29071,16,0,12,0,100,"special_surprise SAY_EXEC_RECOG_5","$N, I'd recognize those horns anywhere... What have they done to you, $N?"),
(29071,17,0,12,0,100,"special_surprise SAY_EXEC_RECOG_6","$N, I'd recognize dem tusks anywhere... What... What have dey done ta you, mon?"),
(29071,18,0,12,0,100,"special_surprise SAY_EXEC_NOREM_1","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you a draenei!"),
(29071,19,0,12,0,100,"special_surprise SAY_EXEC_NOREM_2","Ye don't remember me, do ye? Blasted Scourge... They've tried to drain ye o' everything that made ye a righteous force o' reckoning. Every last ounce o' good... Everything that made you a $Gson:daughter; of Ironforge!"),
(29071,20,0,12,0,100,"special_surprise SAY_EXEC_NOREM_3","You don't remember me, do you? We were humans once - long, long ago - until Lordaeron fell to the Scourge. Your transformation to a Scourge zombie came shortly after my own. Not long after that, our minds were freed by the Dark Lady."),
(29071,21,0,12,0,100,"special_surprise SAY_EXEC_NOREM_4","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a pint-sized force of reckoning. Every last ounce of good... Everything that made you a gnome!"),
(29071,22,0,12,0,100,"special_surprise SAY_EXEC_NOREM_5","You don't remember me, do you? Blasted Scourge...They've tried to drain of everything that made you a righteous force of reckoning. Every last ounce of good...Everything that made you a human!"),
(29071,23,0,12,0,100,"special_surprise SAY_EXEC_NOREM_6","You don't remember me? When you were a child your mother would leave you in my care while she served at the Temple of the Moon. I held you in my arms and fed you with honey and sheep's milk to calm you until she would return. You were my little angel. Blasted Scourge... What have they done to you, $N?"),
(29071,24,0,12,0,100,"special_surprise SAY_EXEC_NOREM_7","You don't recognize me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you an orc!"),
(29071,25,0,12,0,100,"special_surprise SAY_EXEC_NOREM_8","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you a tauren!"),
(29071,26,0,12,0,100,"special_surprise SAY_EXEC_NOREM_9","You don't remember me, mon? Damn da Scourge! Dey gone ta drain you of everytin dat made ya a mojo masta. Every last ounce of good... Everytin' dat made ya a troll hero, mon!"),
(29071,27,0,12,0,100,"special_surprise SAY_EXEC_THINK_1","A pact was made, $Gbrother:sister;! We vowed vengeance against the Lich King! For what he had done to us! We battled the Scourge as Forsaken, pushing them back into the plaguelands and freeing Tirisfal! You and I were champions of the Forsaken!"),
(29071,28,0,12,0,100,"special_surprise SAY_EXEC_THINK_2","You must remember the splendor of life, $Gbrother:sister;. You were a champion of the Kaldorei once! This isn't you!"),
(29071,29,0,12,0,100,"special_surprise SAY_EXEC_THINK_3","Think, $N. Think back. Try and remember the majestic halls of Silvermoon City, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the sin'dorei once! This isn't you."),
(29071,30,0,12,0,100,"special_surprise SAY_EXEC_THINK_4","Think, $N. Think back. Try and remember the proud mountains of Argus, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the draenei once! This isn't you."),
(29071,31,0,12,0,100,"special_surprise SAY_EXEC_THINK_5","Think, $N. Think back. Try and remember the snow capped mountains o' Dun Morogh! Ye were born there, $Glad:lass;. Remember the splendor o' life, $N! Ye were a champion o' the dwarves once! This isn't ye!"),
(29071,32,0,12,0,100,"special_surprise SAY_EXEC_THINK_6","Think, $N. Think back. Try and remember Gnomeregan before those damned troggs! Remember the feel of an [arclight spanner] $Gbrother:sister;. You were a champion of gnome-kind once! This isn't you."),
(29071,33,0,12,0,100,"special_surprise SAY_EXEC_THINK_7","Think, $N. Think back. Try and remember the hills and valleys of Elwynn, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the Alliance once! This isn't you."),
(29071,34,0,12,0,100,"special_surprise SAY_EXEC_THINK_8","Think, $N. Think back. Try and remember Durotar, $Gbrother:sister;! Remember the sacrifices our heroes made so that we could be free of the blood curse. Harken back to the Valley of Trials, where we were reborn into a world without demonic influence. We found the splendor of life, $N. Together! This isn't you. You were a champion of the Horde once!"),
(29071,35,0,12,0,100,"special_surprise SAY_EXEC_THINK_9","Think, $N. Think back. Try and remember the rolling plains of Mulgore, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the tauren once! This isn't you."),
(29071,36,0,12,0,100,"special_surprise SAY_EXEC_THINK_10","TINK $N. Tink back, mon! We be Darkspear, mon! Bruddas and sistas! Remember when we fought the Zalazane and done took he head and freed da Echo Isles? MON! TINK! You was a champion of da Darkspear trolls!"),
(29071,37,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_1","Listen to me, $N. You must fight against the Lich King's control. He is a monster that wants to see this world - our world - in ruin. Don't let him use you to accomplish his goals. You were once a hero and you can be again. Fight, damn you! Fight his control!"),
(29071,38,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_2","Listen to me, $N Ye must fight against the Lich King's control. He's a monster that wants to see this world - our world - in ruin. Don't let him use ye to accomplish his goals. Ye were once a hero and ye can be again. Fight, damn ye! Fight his control!"),
(29071,39,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_3","Listen to me, $N. You must fight against the Lich King's control. He is a monster that wants to see this world - our world - in ruin. Don't let him use you to accomplish his goals AGAIN. You were once a hero and you can be again. Fight, damn you! Fight his control!"),
(29071,40,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_4","Listen ta me, $Gbrudda:sista;. You must fight against da Lich King's control. He be a monstar dat want ta see dis world - our world - be ruined. Don't let he use you ta accomplish he goals. You be a hero once and you be a hero again! Fight it, mon! Fight he control!"),
(29071,42,0,12,0,100,"special_surprise SAY_EXEC_TIME_1","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Silvermoon. This world is worth saving!"),
(29071,43,0,12,0,100,"special_surprise SAY_EXEC_TIME_2","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Argus. Don't let that happen to this world."),
(29071,44,0,12,0,100,"special_surprise SAY_EXEC_TIME_3","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both $N... For KHAAAAAAAAZZZ MODAAAAAANNNNNN!!!"),
(29071,45,0,12,0,100,"special_surprise SAY_EXEC_TIME_4","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Tirisfal! This world is worth saving!"),
(29071,46,0,12,0,100,"special_surprise SAY_EXEC_TIME_5","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Gnomeregan! This world is worth saving."),
(29071,47,0,12,0,100,"special_surprise SAY_EXEC_TIME_6","There... There's no more time for me. I'm done for. FInish me off, $N. Do it or they'll kill us both. $N...Remember Elwynn. This world is worth saving."),
(29071,48,0,12,0,100,"special_surprise SAY_EXEC_TIME_7","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Teldrassil, our beloved home. This world is worth saving."),
(29071,49,0,12,0,100,"special_surprise SAY_EXEC_TIME_8","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... For the Horde! This world is worth saving."),
(29071,50,0,12,0,100,"special_surprise SAY_EXEC_TIME_9","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Mulgore. This world is worth saving."),
(29071,51,0,12,0,100,"special_surprise SAY_EXEC_TIME_10","Der... Der's no more time for me. I be done for. Finish me off $N. Do it or they'll kill us both. $N... Remember Sen'jin Village, mon! Dis world be worth saving!"),
(29071,52,0,12,0,100,"special_surprise SAY_EXEC_WAITING","Do it, $N! Put me out of my misery!"),
(29071,53,0,16,0,100,"special_surprise EMOTE_DIES","%s dies from his wounds."),
-- Plaguefist
(29053,41,0,14,0,100,"special_surprise SAY_PLAGUEFIST","What's going on in there? What's taking so long, $N?");

-- Highlord Darion Mograine
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1609286 AND -1609201;
DELETE FROM `creature_text` WHERE `entry` IN (29183,29175,29227,29228,29176,29178,29204,29173);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(29173,0,0,14,14677,100,"Highlord Darion Mograine","Soldiers of the Scourge, stand ready! You will soon be able to unleash your fury upon the Argent Dawn!"),
(29173,1,0,14,14678,100,"Highlord Darion Mograine","The sky weeps at the devastation of sister earth! Soon, tears of blood will rain down upon us!"),
(29173,2,0,14,14681,100,"Highlord Darion Mograine","Death knights of Acherus, the death march begins!"),
(29173,3,0,14,14679,100,"Highlord Darion Mograine","Soldiers of the Scourge, death knights of Acherus, minions of the darkness: hear the call of the Highlord!"),
(29173,4,0,14,14680,100,"Highlord Darion Mograine","RISE!"),
(29173,5,0,14,14682,100,"Highlord Darion Mograine","The skies turn red with the blood of the fallen! The Lich King watches over us, minions! Onward! Leave only ashes and misery in your destructive wake!"),
(29176,6,0,14,0,100,"Korfax, Champion of the Light","Scourge armies approach!"),
(29178,7,0,14,14487,100,"Lord Maxwell Tyrosus","Stand fast, brothers and sisters! The Light will prevail!"),
(29173,8,0,12,14683,100,"Highlord Darion Mograine","Kneel before the Highlord!"),
(29173,8,1,12,14684,100,"Highlord Darion Mograine","You stand no chance!"),
(29173,8,2,12,14685,100,"Highlord Darion Mograine","The Scourge will destroy this place!"),
(29173,8,3,12,14686,100,"Highlord Darion Mograine","Your life is forfeit."),
(29173,8,4,12,14687,100,"Highlord Darion Mograine","Life is meaningless without suffering."),
(29173,8,5,12,14688,100,"Highlord Darion Mograine","How much longer will your forces hold out?"),
(29173,8,6,12,14689,100,"Highlord Darion Mograine","The Argent Dawn is finished!"),
(29173,8,7,12,14690,100,"Highlord Darion Mograine","Spare no one!"),
(29173,8,8,12,14691,100,"Highlord Darion Mograine","What is this?! My... I cannot strike..."),
(29173,8,9,14,14692,100,"Highlord Darion Mograine","Obey me, blade!"),
(29173,8,10,12,14693,100,"Highlord Darion Mograine","You will do as I command! I am in control here!"),
(29173,8,11,12,14694,100,"Highlord Darion Mograine","I can not... the blade fights me."),
(29173,8,12,12,14695,100,"Highlord Darion Mograine","What is happening to me?"),
(29173,8,13,12,14696,100,"Highlord Darion Mograine","Power...wanes..."),
(29173,8,14,12,14697,100,"Highlord Darion Mograine","Ashbringer defies me..."),
(29173,8,15,12,14698,100,"Highlord Darion Mograine","Minions, come to my aid!"),
(29175,24,0,14,14584,100,"Highlord Tirion Fordring","You cannot win, Darion!"),
(29175,25,0,14,14585,100,"Highlord Tirion Fordring","Bring them before the chapel!"),
(29173,26,0,12,14699,100,"Highlord Darion Mograine","Stand down, death knights. We have lost... The Light... This place... No hope..."),
(29175,27,0,12,14586,100,"Highlord Tirion Fordring","Have you learned nothing, boy? You have become all that your father fought against! Like that coward, Arthas, you allowed yourself to be consumed by the darkness...the hate... Feeding upon the misery of those you tortured and killed!"),
(29175,28,0,12,14587,100,"Highlord Tirion Fordring","Your master knows what lies beneath the chapel. It is why he dares not show his face! He's sent you and your death knights to meet their doom, Darion."),
(29175,29,0,12,14588,100,"Highlord Tirion Fordring","What you are feeling right now is the anguish of a thousand lost souls! Souls that you and your master brought here! The Light will tear you apart, Darion!"),
(29173,30,0,12,14700,100,"Highlord Darion Mograine","Save your breath, old man. It might be the last you ever draw."),
(29227,31,0,12,14493,100,"Highlord Alexandros Mograine","My son! My dear, beautiful boy!"),
(29173,32,0,12,14701,100,"Highlord Darion Mograine","Father!"),
(29173,33,0,12,14702,100,"Highlord Darion Mograine","Argh...what...is..."),
(29228,34,0,12,14703,100,"Darion Mograine","Father, you have returned!"),
(29228,35,0,12,14704,100,"Darion Mograine","You have been gone a long time, father. I thought..."),
(29227,36,0,12,14494,100,"Highlord Alexandros Mograine","Nothing could have kept me away from here, Darion. Not from my home and family."),
(29228,37,0,12,14705,100,"Darion Mograine","Father, I wish to join you in the war against the undead. I want to fight! I can sit idle no longer!"),
(29227,38,0,12,14495,100,"Highlord Alexandros Mograine","Darion Mograine, you are barely of age to hold a sword, let alone battle the undead hordes of Lordaeron! I couldn't bear losing you. Even the thought..."),
(29228,39,0,12,14706,100,"Darion Mograine","If I die, father, I would rather it be on my feet, standing in defiance against the undead legions! If I die, father, I die with you!"),
(29227,40,0,12,14496,100,"Highlord Alexandros Mograine","My son, there will come a day when you will command the Ashbringer and, with it, mete justice across this land. I have no doubt that when that day finally comes, you will bring pride to our people and that Lordaeron will be a better place because of you. But, my son, that day is not today."),
(29227,41,0,12,14497,100,"Highlord Alexandros Mograine","Do not forget..."),
(29183,42,0,14,14803,100,"The Lich King","Touching..."),
(29173,43,0,14,14707,100,"Highlord Darion Mograine","You have've betrayed me! You betrayed us all you monster! Face the might of Mograine!"),
(29183,44,0,12,14805,100,"The Lich King","He's mine now..."),
(29183,45,0,12,14804,100,"The Lich King","Pathetic..."),
(29175,46,0,12,14589,100,"Highlord Tirion Fordring","You're a damned monster, Arthas!"),
(29183,47,0,12,14806,100,"The Lich King","You were right, Fordring. I did send them in to die. Their lives are meaningless, but yours..."),
(29183,48,0,12,14807,100,"The Lich King","How simple it was to draw the great Tirion Fordring out of hiding. You've left yourself exposed, paladin. Nothing will save you..."),
(29178,49,0,14,14488,100,"Lord Maxwell Tyrosus","ATTACK!!!"),
(29183,50,0,14,14808,100,"The Lich King","APOCALYPSE!"),
(29173,51,0,12,14708,100,"Highlord Darion Mograine","That day is not today..."),
(29173,52,0,14,14709,100,"Highlord Darion Mograine","Tirion!"),
(29175,53,0,14,14591,100,"Highlord Tirion Fordring","ARTHAS!!!!"),
(29183,54,0,14,14809,100,"The Lich King","What is this?"),
(29175,55,0,14,14592,100,"Highlord Tirion Fordring","Your end."),
(29183,56,0,14,14810,100,"The Lich King","Impossible..."),
(29183,57,0,14,14811,100,"The Lich King","This... isn't... over..."),
(29183,58,0,14,14812,100,"The Lich King","When next we meet it won't be on holy ground, paladin."),
(29175,59,0,12,14593,100,"Highlord Tirion Fordring","Rise, Darion, and listen..."),
(29175,60,0,12,14594,100,"Highlord Tirion Fordring","We have all been witness to a terrible tragedy. The blood of good men has been shed upon this soil! Honorable knights, slain defending their lives - our lives!"),
(29175,61,0,12,14595,100,"Highlord Tirion Fordring","And while such things can never be forgotten, we must remain vigilant in our cause!"),
(29175,62,0,12,14596,100,"Highlord Tirion Fordring","The Lich King must answer for what he has done and must not be allowed to cause further destruction to our world."),
(29175,63,0,12,14597,100,"Highlord Tirion Fordring","I make a promise to you now, brothers and sisters: The Lich King will be defeated! On this day, I call for a union."),
(29175,64,0,12,14598,100,"Highlord Tirion Fordring","The Argent Dawn and the Order of the Silver Hand will come together as one! We will succeed where so many before us have failed!"),
(29175,65,0,12,14599,100,"Highlord Tirion Fordring","We will take the fight to Arthas and tear down the walls of Icecrown!"),
(29175,66,0,14,14600,100,"Highlord Tirion Fordring","The Argent Crusade comes for you, Arthas!"),
(29173,67,0,12,14710,100,"Highlord Darion Mograine","So too do the Knights of the Ebon Blade... While our kind has no place in your world, we will fight to bring an end to the Lich King. This I vow!"),
(29173,68,0,16,0,100,"","Thousands of Scourge rise up at the Highlord's command."),
(29173,69,0,16,0,100,"","The army marches towards Light's Hope Chapel."),
(29173,70,0,16,0,100,"","After over a hundred Defenders of the Light fall, Highlord Tirion Fordring arrives."),
(29204,71,0,16,0,100,"Orbaz","%s flee"),
(29173,72,0,16,0,100,"Highlord Darion Mograine","%s kneels in defeat before Tirion Fordring."),
(29227,73,0,16,0,100,"Highlord Alexandros Mograine","%s arrives."),
(29173,74,0,16,0,100,"Highlord Darion Mograine","%s becomes a shade of his past, and walks up to his father."),
(29228,75,0,16,0,100,"Darion Mograine","%s hugs his father."),
(29173,76,0,16,0,100,"Alexandros","%s disappears, and the Lich King appears."),
(29173,77,0,16,0,100,"Highlord Darion Mograine","%s becomes himself again...and is now angry."),
(29183,78,0,16,0,100,"The Lich King","%s casts a spell on Tirion."),
(29175,79,0,16,0,100,"Highlord Tirion Fordring","%s gasps for air."),
(29183,80,0,16,0,100,"The Lich King","%s casts a powerful spell, killing the Defenders and knocking back the others."),
(29173,81,0,16,0,100,"Highlord Darion Mograine","%s throws the Corrupted Ashbringer to Tirion, who catches it. Tirion becomes awash with Light, and the Ashbringer is cleansed."),
(29173,82,0,16,0,100,"Highlord Darion Mograine","%s collapses."),
(29175,83,0,16,0,100,"Highlord Tirion Fordring","%s charges towards the Lich King, Ashbringer in hand and strikes the Lich King."),
(29183,84,0,16,0,100,"The Lich King","%s disappears. Tirion walks over to where Darion lay"),
(29173,85,0,16,0,100,"","Light washes over the chapel ? the Light of Dawn is uncovered.");

-- grimstone
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1230008 AND -1230003;
DELETE FROM `creature_text` WHERE `entry`=10096;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(10096,0,0,14,0,100,"grimstone SCRIPT_TEXT1","You have been sentenced to death for crimes against the Dark Iron nation!"),
(10096,1,0,14,0,100,"grimstone SCRIPT_TEXT2","The Sons of Thaurissan shall watch you perish in the Ring of the Law!"),
(10096,2,0,14,0,100,"grimstone SCRIPT_TEXT3","Unleash the fury and let it be done!"),
(10096,3,0,14,0,100,"grimstone SCRIPT_TEXT4","Haha! I bet you thought you were done!"),
(10096,4,0,14,0,100,"grimstone SCRIPT_TEXT5","But your real punishment lies ahead."),
(10096,5,0,14,0,100,"grimstone SCRIPT_TEXT6","Good riddance!");

-- rocknot
DELETE FROM `script_texts` WHERE `entry`=-1230000;
DELETE FROM `creature_text` WHERE `entry`=9503;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(9503,0,0,12,0,100,"rocknot SAY_GOT_BEER","Ah, hits the spot!");

-- doctor theolen krastinov
-- No delete query here, it's a generic script text for frenzy emotes.
DELETE FROM `creature_text` WHERE `entry`=9028;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(9028,0,0,16,0,100,"grizzle EMOTE_FRENZY_KILL","%s goes into a killing frenzy!");

-- dagran
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1230002 AND -1230001;
DELETE FROM `creature_text` WHERE `entry`=9019;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(9019,0,0,14,0,100,"dagran SAY_AGGRO","Come to aid the Throne!"),
(9019,1,0,14,0,100,"dagran SAY_SLAY","Hail to the king, baby!");

-- lilatha
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000146 AND -1000140;
DELETE FROM `creature_text` WHERE `entry` IN (16295,16220);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(16295,0,0,12,0,100,"lilatha SAY_START","Let's go."),
(16295,1,0,12,0,100,"lilatha SAY_PROGRESS1","$N, let's use the antechamber to the right."),
(16295,2,0,12,0,100,"lilatha SAY_PROGRESS2","I can see the light at the end of the tunnel!"),
(16295,3,0,12,0,100,"lilatha SAY_PROGRESS3","There's Farstrider Enclave now, $C. Not far to go... Look out! Troll ambush!!"),
(16295,4,0,12,0,100,"lilatha SAY_END1","Thank you for saving my life and bringing me back to safety, $N"),
(16295,5,0,12,0,100,"lilatha SAY_END2","Captain Helios, I've been rescued from the Amani Catacombs. Reporting for duty, sir!"),
(16220,0,0,12,0,100,"lilatha CAPTAIN_ANSWER","Liatha, get someone to look at those injuries. Thank you for bringing her back safely.");

-- stillblade
DELETE FROM `script_texts` WHERE `entry`=-1000193;
DELETE FROM `creature_text` WHERE `entry`=17768;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(17768,0,0,12,0,100,"stillblade SAY_HEAL","Thank you, dear $C, you just saved my life.");

-- stilwell
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000297 AND -1000293;
DELETE FROM `creature_text` WHERE `entry`=6182;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(6182,0,0,12,0,100,"stilwell SAY_DS_START","To the house! Stay close to me, no matter what! I have my gun and ammo there!"),
(6182,1,0,12,0,100,"stilwell SAY_DS_DOWN_1","We showed that one!"),
(6182,2,0,12,0,100,"stilwell SAY_DS_DOWN_2","One more down!"),
(6182,3,0,12,0,100,"stilwell SAY_DS_DOWN_3","We've done it! We won!"),
(6182,4,0,12,0,100,"stilwell SAY_DS_PROLOGUE","Meet me down by the orchard-- I just need to put my gun away.");

-- defias traitor
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000105 AND -1000101;
DELETE FROM `creature_text` WHERE `entry`=467;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(467,0,0,12,0,100,"defias traitor SAY_START","Follow me, $N. I'll take you to the Defias hideout. But you better protect me or I am as good as dead."),
(467,1,0,12,0,100,"defias traitor SAY_PROGRESS","The entrance is hidden here in Moonbrook. Keep your eyes peeled for thieves. They want me dead."),
(467,2,0,12,0,100,"defias traitor SAY_END","You can go tell Stoutmantle this is where the Defias Gang is holed up, $N."),
(467,3,0,12,0,100,"defias traitor SAY_AGGRO_1","%s coming in fast! Prepare to fight!"),
(467,3,1,12,0,100,"defias traitor SAY_AGGRO_2","Help!");

-- vexallus
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1585011 AND -1585007;
DELETE FROM `creature_text` WHERE `entry`=24744;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(24744,0,0,14,12389,100,"vexallus SAY_AGGRO","Drain...life!"),
(24744,1,0,14,12392,100,"vexallus SAY_ENERGY","Un...con...tainable."),
(24744,2,0,14,12390,100,"vexallus SAY_OVERLOAD","Un...leash..."),
(24744,3,0,14,12393,100,"vexallus SAY_KILL","Con...sume."),
(24744,4,0,41,0,100,"vexallus EMOTE_DISCHARGE_ENERGY","%s discharges pure energy!");

-- kaelthas
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1585029 AND -1585023;
DELETE FROM `creature_text` WHERE `entry`=24664;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(24664,0,0,14,12413,100,"kaelthas MT SAY_AGGRO","Don't look so smug! I know what you're thinking, but Tempest Keep was merely a set back. Did you honestly believe I would trust the future to some blind, half-night elf mongrel? Oh no, he was merely an instrument, a stepping stone to a much larger plan! It has all led to this, and this time, you will not interfere!"),
(24664,1,0,14,12415,100,"kaelthas MT SAY_PHOENIX","Vengeance burns!"),
(24664,2,0,14,12417,100,"kaelthas MT SAY_FLAMESTRIKE","Felomin ashal!"),
(24664,3,0,14,12418,100,"kaelthas MT SAY_GRAVITY_LAPSE","I'll turn your world... upside... down..."),
(24664,4,0,14,12419,100,"kaelthas MT SAY_TIRED","Master... grant me strength."),
(24664,5,0,14,12420,100,"kaelthas MT SAY_RECAST_GRAVITY","Do not... get too comfortable."),
(24664,6,0,14,12421,100,"kaelthas MT SAY_DEATH","My demise accomplishes nothing! The Master will have you! You will drown in your own blood! This world shall burn! Aaaghh!");

-- selin
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1585006 AND -1585000;
DELETE FROM `creature_text` WHERE `entry`=24723;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(24723,0,0,14,12378,100,"selin SAY_AGGRO","You only waste my time!"),
(24723,1,0,14,12381,100,"selin SAY_ENERGY","My hunger knows no bounds!"),
(24723,2,0,14,12382,100,"selin SAY_EMPOWERED","Yes! I am a god!"),
(24723,3,0,14,12388,100,"selin SAY_KILL_1","Enough distractions!"),
(24723,3,1,14,12385,100,"selin SAY_KILL_2","I am invincible!"),
(24723,4,0,14,12383,100,"selin SAY_DEATH","No! More... I must have more!"),
(24723,5,0,41,0,100,"selin EMOTE_CRYSTAL","%s begins to channel from the nearby Fel Crystal...");

-- delrissa
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1585022 AND -1585012;
DELETE FROM `creature_text` WHERE `entry`=24560;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(24560,0,0,14,12395,100,"delrissa SAY_AGGRO","Annihilate them!"),
(24560,1,0,14,12398,100,"delrissa LackeyDeath1","Oh, the horror."),
(24560,2,0,14,12400,100,"delrissa LackeyDeath2","Well, aren't you lucky?"),
(24560,3,0,14,12401,100,"delrissa LackeyDeath3","Now I'm getting annoyed."),
(24560,4,0,14,12403,100,"delrissa LackeyDeath4","Lackies be damned! I'll finish you myself!"),
(24560,5,0,14,12405,100,"delrissa PlayerDeath1","I call that a good start."),
(24560,6,0,14,12407,100,"delrissa PlayerDeath2","I could have sworn there were more of you."),
(24560,7,0,14,12409,100,"delrissa PlayerDeath3","Not really much of a group, anymore, is it?"),
(24560,8,0,14,12410,100,"delrissa PlayerDeath4","One is such a lonely number."),
(24560,9,0,14,12411,100,"delrissa PlayerDeath5","It's been a kick, really."),
(24560,10,0,14,12397,100,"delrissa SAY_DEATH","Not what I had... planned...");

-- lord gregor lescovar
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000463 AND -1000457;
DELETE FROM `creature_text` WHERE `entry` IN (1755,7766,1754,1756);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(1756,0,0,12,0,100,"lord gregor lescovar SAY_GUARD_2","Yes, sir!"),
(1754,0,0,12,0,100,"lord gregor lescovar SAY_LESCOVAR_2","It's time for my meditation, leave me."),
(1754,1,0,12,0,100,"lord gregor lescovar SAY_LESCOVAR_3","There you are. What news from Westfall?"),
(1754,2,0,12,0,100,"lord gregor lescovar SAY_LESCOVAR_4","Hmm, it could be that meddle Shaw. I will see what I can discover. Be off with you. I'll contact you again soon."),
(1755,0,0,12,0,100,"lord gregor lescovar SAY_MARZON_1","VanCleef sends word that the plans are underway. But he's hear rumors about someone snooping about."),
(1755,1,0,12,0,100,"lord gregor lescovar SAY_MARZON_2","The Defias shall succeed! No meek adventurer will stop us!"),
(7766,0,0,14,0,100,"lord gregor lescovar SAY_TYRION_2","That's it! That's what you were waiting for! KILL THEM!");

-- tyrion spybot
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000456 AND -1000450 OR `entry`=-1000499;
DELETE FROM `creature_text` WHERE `entry` IN (7766,8856,1756,1754);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(8856,0,0,12,0,100,"tyrion spybot SAY_QUEST_ACCEPT_ATTACK","By your command!"),
(8856,1,0,12,0,100,"tyrion spybot SAY_SPYBOT_1","Good day to you both. I would speak to Lord Lescovar."),
(8856,2,0,12,0,100,"tyrion spybot SAY_SPYBOT_2","Thank you. The Light be with you both."),
(8856,3,0,12,0,100,"tyrion spybot SAY_SPYBOT_3","Milord, your guest has arrived. He awaits your presence."),
(8856,4,0,12,0,100,"tyrion spybot SAY_SPYBOT_4","I shall use the time wisely, milord. Thank you."),
(7766,0,0,12,0,100,"tyrion spybot SAY_TYRION_1","Wait here. Spybot will make Lescovar come out as soon as possible. Be ready! Attack only after you've overheard their conversation."),
(1756,0,0,12,0,100,"tyrion spybot SAY_GUARD_1","Of course. He awaits you in the library."),
(1754,0,0,12,0,100,"tyrion spybot SAY_LESCOVAR_1","Ah, thank you kindly. I will leave you to the library while I tend to this small matter.");

-- rager
DELETE FROM `script_texts` WHERE `entry`=-1409002;
DELETE FROM `creature_text` WHERE `entry`=11988;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(11988,0,0,16,0,100,"core rager EMOTE_LOWHP","%s refuses to die while its master is in trouble.");

-- ragnaros
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1409018 AND -1409008;
DELETE FROM `creature_text` WHERE `entry`=11502;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(11502,0,0,14,8040,100,"ragnaros SAY_SUMMON_MAJ","Behold Ragnaros, the Firelord! He who was ancient when this world was young! Bow before him, mortals! Bow before your ending!"),
(11502,1,0,14,8043,100,"ragnaros SAY_ARRIVAL1_RAG","TOO SOON! YOU HAVE AWAKENED ME TOO SOON, EXECUTUS! WHAT IS THE MEANING OF THIS INTRUSION?"),
(11502,2,0,14,8041,100,"ragnaros SAY_ARRIVAL2_MAJ","These mortal infidels, my lord! They have invaded your sanctum, and seek to steal your secrets!"),
(11502,3,0,14,8044,100,"ragnaros SAY_ARRIVAL3_RAG","FOOL! YOU ALLOWED THESE INSECTS TO RUN RAMPANT THROUGH THE HALLOWED CORE, AND NOW YOU LEAD THEM TO MY VERY LAIR? YOU HAVE FAILED ME, EXECUTUS! JUSTICE SHALL BE MET, INDEED!"),
(11502,4,0,14,8045,100,"ragnaros SAY_ARRIVAL5_RAG","NOW FOR YOU, INSECTS. BOLDLY YOU SAUGHT THE POWER OF RAGNAROS NOW YOU SHALL SEE IT FIRST HAND."),
(11502,5,0,14,8049,100,"ragnaros SAY_REINFORCEMENTS1","COME FORTH, MY SERVANTS! DEFEND YOUR MASTER!"),
(11502,6,0,14,8050,100,"ragnaros SAY_REINFORCEMENTS2","YOU CANNOT DEFEAT THE LIVING FLAME! COME YOU MINIONS OF FIRE! COME FORTH YOU CREATURES OF HATE! YOUR MASTER CALLS!"),
(11502,7,0,14,8046,100,"ragnaros SAY_HAND","BY FIRE BE PURGED!"),
(11502,8,0,14,8047,100,"ragnaros SAY_WRATH","TASTE THE FLAMES OF SULFURON!"),
(11502,9,0,14,8051,100,"ragnaros SAY_KILL","DIE INSECT!"),
(11502,10,0,14,8048,100,"ragnaros SAY_MAGMABURST","MY PATIENCE IS DWINDLING! COME, GNATS, TO YOUR DEATH!");