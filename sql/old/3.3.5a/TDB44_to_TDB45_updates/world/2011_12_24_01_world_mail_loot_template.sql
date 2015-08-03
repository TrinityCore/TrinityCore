-- Reward from Treats for Greatfather Winter (horde)
SET @mail:=102; -- Set in DBC
UPDATE quest_template SET RewardMailTemplateId=@mail, RewardMailDelay=86400 WHERE Id IN (6962); -- Set mail delivery
DELETE FROM mail_loot_template WHERE entry=@mail;
INSERT INTO mail_loot_template (entry,item,ChanceOrQuestChance,lootmode,groupid,mincountOrRef,maxcount) VALUES
(@mail,17685,100,1,0,1,1); -- Attach item to mail

-- Reward from Treats for Greatfather Winter (alliance)
SET @mail:=118; -- Set in DBC
UPDATE quest_template SET RewardMailTemplateId=@mail, RewardMailDelay=86400 WHERE Id IN (7025); -- Set mail delivery
DELETE FROM mail_loot_template WHERE entry=@mail;
INSERT INTO mail_loot_template (entry,item,ChanceOrQuestChance,lootmode,groupid,mincountOrRef,maxcount) VALUES
(@mail,17685,100,1,0,1,1); -- Attach item to mail

-- Reward from Stolen Winter Veil Treats (horde)
SET @mail:=108; -- Set in DBC
UPDATE quest_template SET RewardMailTemplateId=@mail, RewardMailDelay=86400 WHERE Id IN (6963); -- Set mail delivery
DELETE FROM mail_loot_template WHERE entry=@mail;
INSERT INTO mail_loot_template (entry,item,ChanceOrQuestChance,lootmode,groupid,mincountOrRef,maxcount) VALUES
(@mail,17712,100,1,0,1,1); -- Attach item to mail

-- Reward from Stolen Winter Veil Treats (alliance)
SET @mail:=117; -- Set in DBC
UPDATE quest_template SET RewardMailTemplateId=@mail, RewardMailDelay=86400 WHERE Id IN (7042); -- Set mail delivery
DELETE FROM mail_loot_template WHERE entry=@mail;
INSERT INTO mail_loot_template (entry,item,ChanceOrQuestChance,lootmode,groupid,mincountOrRef,maxcount) VALUES
(@mail,17712,100,1,0,1,1); -- Attach item to mail

-- Reward from Metzen the Reindeer (horde)
SET @mail:=122; -- Set in DBC
UPDATE quest_template SET RewardMailTemplateId=@mail, RewardMailDelay=86400 WHERE Id IN (8746); -- Set mail delivery
DELETE FROM mail_loot_template WHERE entry=@mail;
INSERT INTO mail_loot_template (entry,item,ChanceOrQuestChance,lootmode,groupid,mincountOrRef,maxcount) VALUES
(@mail,21216,100,1,0,1,1); -- Attach item to mail

-- Reward from Metzen the Reindeer (alliance)
SET @mail:=161; -- Set in DBC
UPDATE quest_template SET RewardMailTemplateId=@mail, RewardMailDelay=86400 WHERE Id IN (8762); -- Set mail delivery
DELETE FROM mail_loot_template WHERE entry=@mail;
INSERT INTO mail_loot_template (entry,item,ChanceOrQuestChance,lootmode,groupid,mincountOrRef,maxcount) VALUES
(@mail,21216,100,1,0,1,1); -- Attach item to mail
