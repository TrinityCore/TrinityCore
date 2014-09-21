-- [Q] [H] Catch the Wild Wolpertinger!
-- Alliance version already had this
DELETE FROM `creature_queststarter` WHERE `id`=24657 AND `quest`=11431;
INSERT INTO `creature_queststarter` (`id`,`quest`) VALUES (24657,11431);
DELETE FROM `creature_questender` WHERE `id`=24657 AND `quest`=11431;
INSERT INTO `creature_questender` (`id`,`quest`) VALUES (24657,11431);

-- [Q] [A/H] Did Someone Say "Souvenir?" (removed in 2.4.3) & Say, There Wouldn't Happen to be a Souvenir This Year, Would There?
DELETE FROM `creature_queststarter` WHERE `quest` IN (11321,11413,12193);
DELETE FROM `creature_questender` WHERE `quest` IN (11321,11413);

-- [Q] [A/H] Save Brewfest! should have pre-req Welcome to Brewfest!
UPDATE `quest_template` SET `PrevQuestId`=11442 WHERE `id`=12318;

-- [Q] [A/H] Save Brewfest! - removed in 2.4.3
DELETE FROM `creature_queststarter` WHERE `quest`=12318;
DELETE FROM `creature_questender` WHERE `quest`=12318;

-- [Q] [A] Direbrew's Dire Brew - removed PrevQuestId in 2010
-- Horde version already had this
UPDATE `quest_template` SET `PrevQuestId`=0 WHERE `id`=12491;

-- Misc.
UPDATE `creature_template_addon` SET `auras`='43905' WHERE `entry`=23698; -- Drunken Brewfest Reveler
UPDATE `creature_template` SET `AIName`='' WHERE `entry`=23698; -- Drunken Brewfest Reveler
UPDATE `creature` SET `spawntimesecs`=450 WHERE `id`=24484; -- Brewfest Reveler had 12 hour respawntime ...

-- Send a mail on quest complete "Brew of the Month Club" - there is no wait time so we won't use RewMailDelaySecs
-- Alliance quest missed quest texts
SET @MAIL_A := 209;
SET @MAIL_H := 210;
UPDATE `quest_template` SET `RewardMailTemplateId`=0 WHERE `id`=12278; -- old "Brew of the Month Club" quests
UPDATE `quest_template` SET `RewardMailTemplateId`=0 WHERE `id`=12306; -- old "Brew of the Month Club" quests
UPDATE `quest_template` SET `RewardMailTemplateId`=@MAIL_A,`OfferRewardText`="Your paperwork looks to be in order. Welcome to the club, $N!$B$BYou can expect to get our mail at the start of every month. If you like what you got, stop by and we can sell you some more. This is the club that keeps on giving.",`RequestItemsText`="Do you have your membership forms filled out?" WHERE `id`=12420;
UPDATE `quest_template` SET `RewardMailTemplateId`=@MAIL_H WHERE `id`=12421;

-- Ray'ma and Larkin were also finishing quest no longer available within the game.
DELETE FROM `creature_questender` WHERE `quest` IN (12278,12306); -- old "Brew of the Month Club" quests
DELETE FROM `creature_questender` WHERE `id`=27489 AND `quest`=12421;
INSERT INTO `creature_questender` (`id`,`quest`) VALUES (27489,12421);

-- Insert missing Wolpertinger's Tankard
DELETE FROM `npc_vendor` WHERE `item`=32233;
INSERT INTO `npc_vendor` (`entry`,`slot`,`item`,`maxcount`,`incrtime`,`ExtendedCost`) VALUES
(23710,0,32233,0,0,0), -- Belbi Quikswitch
(27478,0,32233,0,0,0), -- Larkin Thunderbrew
(24495,0,32233,0,0,0), -- Blix Fixwidget
(27489,0,32233,0,0,0); -- Ray'ma
