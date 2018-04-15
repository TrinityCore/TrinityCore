--
UPDATE `creature_template` SET `npcflag`=`npcflag`|2 WHERE `entry` IN (34835,34876,34877,34878,35175,35200,37203);
DELETE FROM `creature_addon` WHERE guid IN (253116,253244,253268,253269,253270);
