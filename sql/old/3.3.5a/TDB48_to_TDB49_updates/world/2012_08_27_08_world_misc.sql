-- Fire Upon the Waters (12243) quest fix
-- add Fire Upon the Waters Kill Credit Bunny at sail locations
SET @GUID =42887;
DELETE FROM `creature` WHERE `id`=28013;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(@GUID+0,28013,571,1,1,0,0,2488.86,-400.017,19.0803,2.99498,300,0,0,42,0,0,0,33554432,0),
(@GUID+1,28013,571,1,1,0,0,2458.96,-401.066,20.7778,0.108631,300,0,0,42,0,0,0,33554432,0);

-- SAI
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 28013;
DELETE FROM `smart_scripts` WHERE `entryorguid`=28013 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(28013,0,0,0,8,0,100,0,48455,0,0,0,33,28013,0,0,0,0,0,7,0,0,0,0,0,0,0,"Fire Upon the Waters Kill Credit Bunny - On SpellHit Apothecary's Burning Water - Call KilledMonster Fire Upon the Waters Kill Credit Bunny");

-- Ensure spell only works on Fire Upon the Waters Kill Credit Bunny
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=48455;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,48455,0,0,31,0,3,28013,0,0,0,'',"Fire Upon the Waters - spell to Fire Upon the Waters Kill Credit Bunny");

-- add quest item loot to Captain Shely
DELETE FROM `creature_loot_template` WHERE `entry`=27232;
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(27232,37305,-100,1,0,1,1), -- Captain Shely's Rutters
(27232,43851,25,1,0,1,1), -- Fur Clothing Scraps
(27232,33470,10,1,0,1,3), -- Frostweave Cloth
(27232,33443,5,1,0,1,1), -- Sour Goat Cheese
(27232,33444,2,1,0,1,1), -- Pungent Seal Whey
(27232,22829,1,1,0,1,1), -- Super Healing Potion
(27232,45912,0.05,1,0,1,1); -- Book Glyph of Mastery
