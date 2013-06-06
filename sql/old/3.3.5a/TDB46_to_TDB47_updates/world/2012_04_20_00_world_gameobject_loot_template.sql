SET @Ref := 12002;
DELETE FROM `reference_loot_template` WHERE `entry`=@Ref;
INSERT INTO `reference_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(@Ref,47242,100,1,0,1,1);
DELETE FROM `gameobject_loot_template` WHERE `entry` IN (195668,195667,195666,195665,195672,195671,195670,195669) AND `item`=47242;
DELETE FROM `gameobject_loot_template` WHERE `entry` IN (195668,195667,195666,195665,195672,195671,195670,195669) AND `mincountOrRef` = -@Ref;
INSERT INTO gameobject_loot_template (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(195665,5,100,1,0,-@Ref,4), -- 10 man,50 attempts
(195666,3,100,1,0,-@Ref,4), -- 10 man,45+ attempts
(195667,3,100,1,0,-@Ref,2), -- 10 man,25+ attempts
(195668,1,100,1,0,-@Ref,2), -- 10 man,0+ attempts
(195669,6,100,1,0,-@Ref,4), -- 25 man,50 attempts
(195670,4,100,1,0,-@Ref,4), -- 25 man,45+ attempts
(195671,4,100,1,0,-@Ref,2), -- 25 man,25+ attempts
(195672,2,100,1,0,-@Ref,2); -- 25 man,0+ attempts
