-- No clue why 45 was used as common value for 'big' creatures while wowhead likes 49/50. 45+10%=49.5 (racial passive), however in that
-- case wowhead should show more funny values but it always ignores racial passive. We'll use exactly 50 https://www.wowhead.com/faction=1156/the-ashen-verdict#comments:id=941684:reply=143118
-- Prepatch value can be seen here https://youtu.be/c9S6-I2fk1g?t=70 (75+10%=82.5) (https://www.wowhead.com/faction=1156/the-ashen-verdict#comments:id=941684)
-- Wowhead may be wrong about max standing since few values makes no sense to me and it's too suspicious that only few creatures uses max standing
-- In general wowhead values are logically correct and still valid, however I skipped nearly all new entries(they're too suspicious) and ignored few obviously wrong
-- Since multiple players in retail got exalted in a couple days, any movies are useless, all I got is one Marrowgar from normal. In 10+
-- other movies players receives no reputation so probably it was already exalted
-- Reputation in wowhead was not archived in 2010, at all
-- Bosses gives x2 rep in heroic https://www.wowhead.com/faction=1156/the-ashen-verdict#comments:id=1056006

-- Wrong
DELETE FROM `creature_onkill_reputation` WHERE `creature_id` IN (36791,37934,38508,36619,38711,38712,37125,38159,37949,37890,38369,38485,38472,37695,37919,37782,37886,36968,37117,37032,37033,37149,37031,37030,36957,37029,36982,36960,37146,37034,37035);

-- New
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 2 WHERE `creature_id` = 38184; -- Corrupted Ymirjar
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 50 WHERE `creature_id` = 36880; -- Decaying Colossus
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 50 WHERE `creature_id` = 37655; -- Decaying Colossus (1)
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 50 WHERE `creature_id` = 37531; -- Frostwarden Handler
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 50 WHERE `creature_id` = 38139; -- Frostwarden Handler (1)
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 2 WHERE `creature_id` = 37532; -- Frostwing Whelp
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 2 WHERE `creature_id` = 38151; -- Frostwing Whelp (1)
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 50 WHERE `creature_id` = 38418; -- Val'kyr Herald (1)
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 2 WHERE `creature_id` IN (37132,38125,37127,37134,37133,38126,38130,38131,38132,38133);

DELETE FROM `creature_onkill_reputation` WHERE `creature_id` IN (38185,38137,38134,38362,38197,38198,37023,38104,37217,10404,37533,37534,37544,37545,37025,37098,37038);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `RewOnKillRepFaction2`, `MaxStanding1`, `IsTeamAward1`, `RewOnKillRepValue1`, `MaxStanding2`, `IsTeamAward2`, `RewOnKillRepValue2`, `TeamDependent`) VALUES
(38185, 1156, 0, 7, 0, 2, 0, 0, 0, 0), -- Corrupted Ymirjar (1)
(38137, 1156, 0, 7, 0, 15, 0, 0, 0, 0), -- Frostwarden Sorceress (1)
(38134, 1156, 0, 7, 0, 15, 0, 0, 0, 0), -- Frostwarden Warrior (1)
(38362, 1156, 0, 7, 0, 15, 0, 0, 0, 0), -- Nerub'ar Broodling (1)
(38197, 1156, 0, 7, 0, 15, 0, 0, 0, 0), -- Nerub'ar Champion (1)
(38198, 1156, 0, 7, 0, 15, 0, 0, 0, 0), -- Nerub'ar Webweaver (1)
(37023, 1156, 0, 7, 0, 15, 0, 0, 0, 0), -- Plague Scientist
(38104, 1156, 0, 7, 0, 2, 0, 0, 0, 0), -- Plagued Zombie
(37217, 1156, 0, 7, 0, 150, 0, 0, 0, 0), -- Precious
(10404, 1156, 0, 7, 0, 30, 0, 0, 0, 0), -- Pustulating Horror
(37533, 1156, 0, 7, 0, 150, 0, 0, 0, 0), -- Rimefang
(37534, 1156, 0, 7, 0, 150, 0, 0, 0, 0), -- Spinestalker
(37544, 1156, 0, 7, 0, 15, 0, 0, 0, 0), -- Spire Gargoyle
(37545, 1156, 0, 7, 0, 15, 0, 0, 0, 0), -- Spire Minion
(37025, 1156, 0, 7, 0, 150, 0, 0, 0, 0), -- Stinky
(37098, 1156, 0, 7, 0, 50, 0, 0, 0, 0), -- Val'kyr Herald
(37038, 1156, 0, 7, 0, 15, 0, 0, 0, 0); -- Vengeful Fleshreaper

-- More
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 30 WHERE `creature_id` = 37022; -- Blighted Abomination
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 30 WHERE `creature_id` = 38108; -- Blighted Abomination (1)
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 50 WHERE `creature_id` = 37007; -- Deathbound Ward
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 50 WHERE `creature_id` = 38031; -- Deathbound Ward (1)
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 50 WHERE `creature_id` = 36829; -- Deathspeaker High Priest
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 50 WHERE `creature_id` = 38074; -- Deathspeaker High Priest (1)

UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 500 WHERE `creature_id` = 38435; -- Blood-Queen Lana'thel (2)
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 500 WHERE `creature_id` = 38436; -- Blood-Queen Lana'thel (3)
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 500 WHERE `creature_id` = 37505; -- Festergut (2)
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 500 WHERE `creature_id` = 37506; -- Festergut (3)
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 500 WHERE `creature_id` = 38296; -- Lady Deathwhisper (2)
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 500 WHERE `creature_id` = 38297; -- Lady Deathwhisper (3)
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 500 WHERE `creature_id` = 37958; -- Lord Marrowgar (2)
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 500 WHERE `creature_id` = 37959; -- Lord Marrowgar (3)

UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 83 WHERE `creature_id` = 37972; -- Prince Keleseth
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 83 WHERE `creature_id` = 37973; -- Prince Taldaram
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 83 WHERE `creature_id` = 37970; -- Prince Valanar
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 83 WHERE `creature_id` = 38401; -- Prince Valanar (1)
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 165 WHERE `creature_id` = 38784; -- Prince Valanar (2)
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 165 WHERE `creature_id` = 38785; -- Prince Valanar (3)

DELETE FROM `creature_onkill_reputation` WHERE `creature_id` IN (38399,38400,38769,38771,38770,38772);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `RewOnKillRepFaction2`, `MaxStanding1`, `IsTeamAward1`, `RewOnKillRepValue1`, `MaxStanding2`, `IsTeamAward2`, `RewOnKillRepValue2`, `TeamDependent`) VALUES
(38399, 1156, 0, 7, 0, 83, 0, 0, 0, 0), -- Prince Keleseth (1)
(38400, 1156, 0, 7, 0, 83, 0, 0, 0, 0), -- Prince Taldaram (1)
(38769, 1156, 0, 7, 0, 165, 0, 0, 0, 0), -- Prince Keleseth (2)
(38771, 1156, 0, 7, 0, 165, 0, 0, 0, 0), -- Prince Taldaram (2)
(38770, 1156, 0, 7, 0, 165, 0, 0, 0, 0), -- Prince Keleseth (3)
(38772, 1156, 0, 7, 0, 165, 0, 0, 0, 0); -- Prince Taldaram (3)

UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 500 WHERE `creature_id` = 38585; -- Professor Putricide (2)
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 500 WHERE `creature_id` = 38586; -- Professor Putricide (3)
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 500 WHERE `creature_id` = 38549; -- Rotface (2)
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 500 WHERE `creature_id` = 38550; -- Rotface (3)
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 500 WHERE `creature_id` = 38266; -- Sindragosa (2)
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 500 WHERE `creature_id` = 38267; -- Sindragosa (3)
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 3000 WHERE `creature_id` = 39167; -- The Lich King (2)
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 3000 WHERE `creature_id` = 39168; -- The Lich King (3)

DELETE FROM `creature_onkill_reputation` WHERE `creature_id` IN (37230,38444);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `RewOnKillRepFaction2`, `MaxStanding1`, `IsTeamAward1`, `RewOnKillRepValue1`, `MaxStanding2`, `IsTeamAward2`, `RewOnKillRepValue2`, `TeamDependent`) VALUES
(37230, 1156, 0, 7, 0, 50, 0, 0, 0, 0), -- Spire Frostwyrm
(38444, 1156, 0, 7, 0, 50, 0, 0, 0, 0); -- Spire Frostwyrm (1)
