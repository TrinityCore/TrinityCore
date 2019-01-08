-- Add lvl 60 reward
INSERT INTO `achievement_reward`
(`ID`,
`TitleA`,
`TitleH`,
`ItemID`,
`Sender`,
`Subject`,
`Body`,
`MailTemplateID`)
VALUES
(11,
0,
0,
38301,
18756,
'My new friend',
'I am so proud of you!$B$B It is so amazing to get you among my friends. This little gift is for our next party.$B$Bkissy kissy!',
0);

-- add lvl 60 reward translate
INSERT into `achievement_reward_locale`
(`ID`,
`Locale`,
`Subject`,
`Body`)
VALUES(
11,
'frFR',
'Coucou',
'Je suis si fier de toi! $B$B C''est incroyable de t''avoir parmi mes amis. Voici un petit présent pour notre prochaine fête.$B$BBisous bisou.');


-- talent reward for group and dungeon quest without daily
UPDATE `quest_template`
SET `RewardTalents` = 1
WHERE `QuestInfoID` IN (1, 81) AND `RewardTalents` = 0 AND `QuestType` != 1 AND `Flags` != 4096
AND ID NOT IN (4606,4605,4604, 4603, 4602, 4601, 2952, 2951);


-- talent reward for class quest without daily
UPDATE `quest_template`
SET `RewardTalents` = 1
WHERE `QuestSortID` IN (-61, -81, -82, -141, -161, -162, -261, -262, -263, -372)
AND `RewardTalents` = 0 AND `MinLevel` > 9 AND `Flags` != 4096;

-- remove price for no experience npcs
UPDATE `gossip_menu_option`
SET `BoxMoney` = 0
WHERE `MenuID` = 10638
