-- The Lost Mistwhisper Treasure (12575)
SET @TARTEK                     := 28105;
SET @ZEPTEK                     := 28399;
SET @HC_RIDE                    := 46598;
SET @TRIGGER                    := 5030;
SET @SPEARBORNBUNNY             := 28457;
-- REF 6710.741, 5154.322, -19.3981
-- REF 6712.461, 5136.462, -19.3981

-- Propper phasing 
DELETE FROM `spell_area` WHERE `spell` = 52217;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
(52217, 4306, 12574, 0, 0, 0, 2, 1, 74, 64),
(52217, 4308, 12574, 0, 0, 0, 2, 1, 74, 64);

-- Needs one waypoint for passenger removal
DELETE FROM `waypoints` WHERE `entry`=@ZEPTEK;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ZEPTEK, 1, 6712.461, 5136.462, -19.3981, 'Zeptek the Destroyer');

-- Criteria linked with involved relation
DELETE FROM `areatrigger_involvedrelation` WHERE `id` = @TRIGGER;
INSERT INTO `areatrigger_involvedrelation` (`id`,`quest`) VALUES
(@TRIGGER,12575);

DELETE FROM `areatrigger_scripts` WHERE `entry` = @TRIGGER;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(@TRIGGER,'SmartTrigger');

DELETE FROM `smart_scripts` WHERE `entryorguid` =@TRIGGER AND `source_type`=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@TRIGGER,2,0,0,46,0,100,0,@TRIGGER,0,0,0,45,1,1,0,0,0,0,10,99764,@SPEARBORNBUNNY,0,0,0,0,0,"On Trigger - Set Data");

DELETE FROM `smart_scripts` WHERE `entryorguid` =@SPEARBORNBUNNY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@SPEARBORNBUNNY,0,0,0,10,0,100,0,1,200,10000,10000,11,51642,2,0,0,0,0,7,0,0,0,0,0,0,0,'Spearborn Encampment Bunny - On update OOC - Spellcast Spearborn Encampment Aura'),
(@SPEARBORNBUNNY,0,1,2,38,0,100,0,1,1,300000,300000,45,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Spearborn Encampment Bunny - On Data Set - Set Data'),
(@SPEARBORNBUNNY,0,2,0,61,0,100,0,0,0,0,0,12,@TARTEK,1,300000,0,0,0,8,0,0,0,6709.02, 5169.21, -20.8878, 4.91029, 'Spearborn Encampment Bunny - Linked with Previous Event - Spawn Warlord Tartek');

DELETE FROM `creature` WHERE `id`=@TARTEK;
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@TARTEK;
DELETE FROM `creature_ai_scripts` WHERE `creature_id` =@TARTEK; 
DELETE FROM `smart_scripts` WHERE `entryorguid` =@TARTEK;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@TARTEK,0,0,1,11,0,100,0,0,0,0,0,2,2061,0,0,0,0,0,1,0,0,0,0,0,0,0,'Warlord Tartek - On Spawn - Set Faction'),
(@TARTEK,0,1,2,61,0,100,0,0,0,0,0,18,756,0,0,0,0,0,1,0,0,0,0,0,0,0,'Warlord Tartek - On Link - Set Unattackable Flags'),
(@TARTEK,0,2,3,61,0,100,0,0,0,0,0,12,@ZEPTEK,1,100000,0,0,0,1,0,0,0,0,0,0,0,'Warlord Tartek - On Link - Summon Zeptek'),
(@TARTEK,0,3,4,61,0,100,0,0,0,0,0,11,@HC_RIDE,2,0,0,0,0,11,@ZEPTEK,10,0,0,0,0,0,'Warlord Tartek - On Link - Ride Zeptek'),
(@TARTEK,0,4,5,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Warlord Tartek - On Link - Say 0'),
(@TARTEK,0,5,0,4,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Warlord Tartek - On Aggro - Say 1'),
(@TARTEK,0,6,0,8,0,100,0,@HC_RIDE,0,0,0,19,756,0,0,0,0,0,1,0,0,0,0,0,0,0,'Warlord Tartek - On Data set - Remove Unattackable Flags'),
-- Combat
(@TARTEK,0,7,0,9,0,100,0,5000,8000,5000,8000,11,29426,2,0,0,0,0,1,0,0,0,0,0,0,0,'Warlord Tartek - IC - Cast Heroic Strike'),
(@TARTEK,0,8,0,0,0,100,0,5000,15000,5000,15000,11,35429,2,0,0,0,0,1,0,0,0,0,0,0,0,'Warlord Tartek - IC - Cast Sweeping Strikes'),
(@TARTEK,0,9,0,0,0,100,0,6000,15000,6000,15000,11,15572,2,0,0,0,0,2,0,0,0,0,0,0,0,'Warlord Tartek - IC - Cast Sunder Armor'),
-- Credit
(@TARTEK,0,10,11,6,0,100,0,0,0,0,0,45,1,1,0,0,0,0,9,28121,0,50,0,0,0,0, 'Warlord Tartek - On Death - Set Data Jaloot'), -- If spawned by player, will say text.
(@TARTEK,0,11,0,61,0,100,0,0,0,0,0,15,12575,0,0,0,0,0,7,0,0,0,0,0,0,0,'Warlord Tartek - On Link - Call area explored or event happens');

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@ZEPTEK;
DELETE FROM `creature_ai_scripts` WHERE `creature_id` =@ZEPTEK; 
DELETE FROM `smart_scripts` WHERE `entryorguid` =@ZEPTEK;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ZEPTEK,0,0,1,11,0,100,0,0,0,0,0,2,2061,0,0,0,0,0,1,0,0,0,0,0,0,0,'Zeptik The Destroyer - On Spawn - Set Faction'),
(@ZEPTEK,0,1,0,61,0,100,0,0,0,0,0,53,1,@ZEPTEK,0,0,0,0,1,0,0,0,0,0,0,0,'Zeptik The Destroyer  - On Link - Start WP'),
(@ZEPTEK,0,2,3,40,0,100,0,1,0,0,0,11,@HC_RIDE,0,0,0,0,0,11,@TARTEK,20,0,0,0,0,0,'Zeptik The Destroyer - ON WP reached - Dismount Tartek'),
(@ZEPTEK,0,3,4,61,0,100,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Zeptik The Destroyer - OnLink - Summon New Zeptek'),
(@ZEPTEK,0,4,0,61,0,100,0,0,0,0,0,28,@HC_RIDE,0,0,0,0,0,1,0,0,0,0,0,0,0,'Zeptik The Destroyer - On LInk - Attack Closest Player');

DELETE FROM `creature_equip_template` WHERE `entry` =@TARTEK;
INSERT INTO `creature_equip_template` (`entry`, `id`, `itemEntry1`, `itemEntry2`, `itemEntry3`) VALUES
(@TARTEK, 1, 5305, 0, 0);

DELETE FROM `creature_text` WHERE `entry` =@TARTEK;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(@TARTEK, 0, 0, 'My treasure! You no steal from Tartek, dumb big-tongue traitor thing.', 14, 0, 100, 0, 0, 0, 'Warlord Tartek'),
(@TARTEK, 1, 0, 'Tartek and nasty dragon going to kill you! You so dumb.', 14, 0, 100, 0, 0, 0, 'Warlord Tartek');
-- Needs special flags 2 for external event
UPDATE `quest_template` SET `SpecialFlags`=2 WHERE  `Id`=12575;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=@TRIGGER AND `SourceId`=2;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,@TRIGGER,2,0,9,0,12575,0,0,0,0,'','Trigger only activates if player is on the Lost Mistwhisper Treasure');
