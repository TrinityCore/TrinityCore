--
DELETE FROM `creature_queststarter` WHERE `quest` IN (615, 8551);
UPDATE `quest_template` SET `AllowableRaces`=0 WHERE `ID`=614;
