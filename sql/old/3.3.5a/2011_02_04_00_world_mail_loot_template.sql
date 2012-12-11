-- Reward from Treats for Greatfather Winter (horde)
SET @MAIL:=118; -- Set in DBC
UPDATE `quest_template` SET `RewMailTemplateId`=@MAIL, `RewMailDelaySecs`=86400 WHERE `entry` IN (6962); -- Set mail delivery
DELETE FROM `mail_loot_template` WHERE `entry`=@MAIL;
INSERT INTO `mail_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(@MAIL,17685,100,1,0,1,1); -- Attach item to mail

-- Reward from Treats for Greatfather Winter (alliance)
SET @MAIL:=102; -- Set in DBC
UPDATE `quest_template` SET `RewMailTemplateId`=@MAIL, `RewMailDelaySecs`=86400 WHERE `entry` IN (7025); -- Set mail delivery
DELETE FROM `mail_loot_template` WHERE `entry`=@MAIL;
INSERT INTO `mail_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(@MAIL,17685,100,1,0,1,1); -- Attach item to mail

-- Reward from Stolen Winter Veil Treats (alliance)
SET @MAIL:=117; -- Set in DBC
UPDATE `quest_template` SET `RewMailTemplateId`=@MAIL, `RewMailDelaySecs`=86400 WHERE `entry` IN (7042); -- Set mail delivery
DELETE FROM `mail_loot_template` WHERE `entry`=@MAIL;
INSERT INTO `mail_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(@MAIL,17712,100,1,0,1,1); -- Attach item to mail

-- Reward from Metzen the Reindeer (alliance)
SET @MAIL:=161; -- Set in DBC
UPDATE `quest_template` SET `RewMailTemplateId`=@MAIL, `RewMailDelaySecs`=86400 WHERE `entry` IN (8762); -- Set mail delivery
DELETE FROM `mail_loot_template` WHERE `entry`=@MAIL;
INSERT INTO `mail_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(@MAIL,21216,100,1,0,1,1); -- Attach item to mail

-- Reward from Metzen the Reindeer (horde)
SET @MAIL:=122; -- Set in DBC
UPDATE `quest_template` SET `RewMailTemplateId`=@MAIL, `RewMailDelaySecs`=86400 WHERE `entry` IN (8746); -- Set mail delivery
DELETE FROM `mail_loot_template` WHERE `entry`=@MAIL;
INSERT INTO `mail_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(@MAIL,21216,100,1,0,1,1); -- Attach item to mail  }}}
