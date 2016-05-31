-- Fix quests Borrowed Technology, The Solution Solution /Daily/, Volatility, Volatility /Daily/
-- thanks to genjush for corrections on wrong quest ids
SET @Skytalon := 31583; -- Frostbrood Skytalon
SET @Decoy := 31578; -- Armored Decoy
SET @QuestCredit := 59329; -- Fake Soldier Kill Credit
SET @Stun := 59292; -- Freeze animation to look like Decoy
SET @Explosion := 59335; -- The spell that should kill Skytalon and Decoy
SET @Summon := 59303; -- Summon Skyatalon
SET @Immolation := 54690; -- Skytalon burning animation spell
SET @Grab := 59318;
SET @Bunny := 31630;
SET @PingBunny := 59375; -- Skytalon cast on accessory bunny to tell it to explode after 6 seconds
SET @Script := @Bunny * 100; -- Explosion bunny timed action list

-- Set inhabit type only 4 to Explosion Bunny that is a vehicle accessory of the Skytalon, otherwise it falls and add "Smart_AI"
UPDATE `creature_template` SET `InhabitType`=4,`AIName`='SmartAI',`flags_extra`=flags_extra|128 WHERE `entry`=@Bunny;
UPDATE `creature_template` SET `unit_flags`=unit_flags|0x00000100|0x00008000,`faction_A`=974,`faction_H`=974,`vehicleId`=279,`InhabitType`=4,`AIName`='',`ScriptName`='npc_frostbrood_skytalon',`HoverHeight`=5 WHERE `entry`=@Skytalon;
UPDATE `creature_template` SET `unit_flags`=unit_flags|0x00000100|0x00008000,`faction_A`=190,`faction_H`=190,`AIName`='SmartAI' WHERE `entry`=@Decoy;

-- Add missing equipment
DELETE FROM `creature_equip_template` WHERE `entry`=@Decoy;
INSERT INTO `creature_equip_template` (`entry`,`id`,`itemEntry1`,`itemEntry2`,`itemEntry3`) VALUES
(@Decoy,1,21573,0,0); -- Armored Decoy -> Monster - Sword, 1H Alliance PvP

-- Add creature_addon data
DELETE FROM `creature_template_addon` WHERE `entry`=@Skytalon;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(@Skytalon,0,0,50331648,1,0, '60534');

-- Insert spell_script names
DELETE FROM `spell_script_names` WHERE `spell_id` IN (@Grab,@Summon);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(@Grab, 'spell_q13291_q13292_q13239_q13261_frostbrood_skytalon_grab_decoy'),
(@Summon, 'spell_q13291_q13292_q13239_q13261_armored_decoy_summon_skytalon');

-- Quests relations
UPDATE `quest_template` SET `PrevQuestId`=13290,`NextQuestId`=13383 WHERE `id`=13291; -- Borrowed Technology
UPDATE `quest_template` SET `PrevQuestId`=13291,`NextQuestId`=0 WHERE `id`=13292; -- The Solution Solution /Daily/
UPDATE `quest_template` SET `PrevQuestId`=13238,`NextQuestId`=13379 WHERE `id`=13239; -- Volatility
UPDATE `quest_template` SET `PrevQuestId`=13329,`NextQuestId`=0 WHERE `id`=13261; -- Volatiliy /Daily/

-- Add SAI support for Explosion bunny and Decoy
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (@Bunny,@Decoy);
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@Script;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Bunny,0,0,0,8,0,100,0,@PingBunny,0,0,0,80,@Script,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Explosion Bunny - On hit by ping bunny - Start timed action list'),
(@Script,9,0,0,0,0,100,0,6000,6000,0,0,11,@Explosion,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Explosion Bunny - Action 0 - Cast explosion on self'),
(@Decoy,0,0,1,54,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Armored Decoy - On just summoned - Store invoker /since target summoner fails/'),
(@Decoy,0,1,2,61,0,100,0,0,0,0,0,11,@Stun,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Armored Decoy - Linked - Cast Freeze animation on self'),
(@Decoy,0,2,0,61,0,100,0,0,0,0,0,11,@Summon,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Armored Decoy - Linked - Cast summon Skytalon behind'),
(@Decoy,0,3,0,8,0,100,0,@Explosion,0,0,0,11,@QuestCredit,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Armored Decoy - On hit by explosion - Cast kill credit to stored target');

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (@Explosion,@PingBunny);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,@Explosion,0,0,31,0,3,@Decoy,0,0,0,0,'', 'Explosion Bunny can hit Armored Decoy'),
(13,1,@Explosion,0,1,31,0,3,@Skytalon,0,0,0,0,'', 'Explosion Bunny can hit Skytalon'),
(13,1,@PingBunny,0,0,31,0,3,@Bunny,0,0,0,0,'', 'Ping Bunny can hit only Explosion Bunny');
