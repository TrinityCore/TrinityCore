SET @SisterSvalna := 37126; -- Sister Svalna

CALL `sp_get_ref_id`('RAID_CRE',@Reference);
SET @RefSisterSvalna := @Reference+1;

DELETE FROM `creature_loot_template` WHERE `entry`=@SisterSvalna;
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(@SisterSvalna,49426,100,1,0,1,1),-- Sister Svalna dropping 1 Emblem of Frost
(@SisterSvalna,1,100,1,0,-@RefSisterSvalna,1);

DELETE FROM `reference_loot_template` WHERE `entry`=@RefSisterSvalna;
INSERT INTO `reference_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(@RefSisterSvalna,50452,6,1,1,1,1), -- Wodin's Lucky Necklace
(@RefSisterSvalna,50453,5,1,1,1,1); -- Ring of Rotting Sinew

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=10 AND `SourceGroup`=@RefSisterSvalna;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(10,@RefSisterSvalna,50452,0,0,19,0,3,0,0,0,0,'', 'Wodin''s Lucky Necklace only 25 heroic'),
(10,@RefSisterSvalna,50453,0,0,19,0,3,0,0,0,0,'', 'Ring of Rotting Sinew only 25 heroic');
