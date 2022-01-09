-- Speak with Prospector Stonehewer and Speak with Voggah Deathgrip are deprecated
DELETE FROM disables WHERE sourceType=1 AND entry IN (7221, 7222);
INSERT INTO disables (sourceType, entry, flags, COMMENT) VALUES
(1, 7221, 0, "Deprecated quest"),
(1, 7222, 0, "Deprecated quest");

-- The Battle of Alterac and The Battle for Alterac have no prequest
UPDATE `quest_template_addon` SET `NextQuestId`=0 WHERE `ID` IN (7221, 7222);

-- In Defense of Frostwolf is a breadcrumb to Proving Grounds
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=7161 WHERE `ID`=7241;
-- The Sovereign Imperative is a breadcrumb to Proving Grounds
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=7162 WHERE `ID`=7261;

UPDATE `quest_request_items` SET `CompletionText`="<Warmaster Laggrond salutes you.>$B$BIt is your time, $N. You have done much for the Frostwolf Clan and in doing so, earned a place as not only a soldier of Frostwolf but also as a friend.$B$BWell done! Present your initiate's insignia." WHERE `ID`=7163;
UPDATE `quest_request_items` SET `CompletionText`="It is good to see you again, $C. I had not expected you to return. Alas, you have proven yourself a brave and honorable soldier of the Frostwolf.$B$BYour time has come again, $N. You have earned a new ranking and as such, a new insignia denoting this rise in stature.$B$BPresent your insignia." WHERE `ID`=7164;
UPDATE `quest_request_items` SET `CompletionText`="So many slain. Blood drenches the fields. Yet... You live... You have persevered. You have led our armies to many victories. For this, then, soldier, you have earned a new rank.$B$BPresent your insignia." WHERE `ID`=7165;
UPDATE `quest_request_items` SET `CompletionText`="Your radiate command and power, $C. Exalted in the eyes of Frostwolf - the enemy cowers at the mention of your name.$B$BRise, Hero of Frostwolf. Rise and be honored!$B$BPresent your insignia." WHERE `ID`=7166;
UPDATE `quest_request_items` SET `CompletionText`="Drek'Thar sings your praises. Kalimdor is abuzz with tales of your heroics. The Warchief glows - your stalwart defense of our clan has pleased him greatly.$B$BYou have earned the Eye of Command.$B$BPresent your insignia, Commander $N." WHERE `ID`=7167;
UPDATE `quest_request_items` SET `CompletionText`="Let them hear your voice, Commander $N! Let them know fear. Show them what power the Stormpike holds in their rank!" WHERE `ID`=7172;

UPDATE `quest_offer_reward` SET `RewardText`="This new insignia reflects your rank amongst the Frostwolf. Keep it on you at all times.$B$BAnd $C... Die with honor!" WHERE `ID`=7163;
UPDATE `quest_offer_reward` SET `RewardText`="<Warmaster Laggrond roars.>$B$BThey have already begun telling tales of your deeds, soldier. The Stormpike shakes in fear when your name is uttered. Carry on!" WHERE `ID`=7165;
UPDATE `quest_offer_reward` SET `RewardText`="Surely it will be you who carries the Eye of Command!" WHERE `ID`=7171;

UPDATE `quest_template_addon` SET `RequiredMinRepFaction`=729, `RequiredMinRepValue`=3000 WHERE `ID`=7163;
UPDATE `quest_template_addon` SET `PrevQuestID`=7163, `RequiredMinRepFaction`=729, `RequiredMinRepValue`=9000 WHERE `ID`=7164;
UPDATE `quest_template_addon` SET `RequiredMinRepFaction`=729, `RequiredMinRepValue`=42000 WHERE `ID`=7166;
UPDATE `quest_template_addon` SET `RequiredMinRepFaction`=729, `RequiredMinRepValue`=42999 WHERE `ID`=7167;

UPDATE `quest_template_addon` SET `RequiredMinRepFaction`=730, `RequiredMinRepValue`=3000 WHERE `ID`=7168;
UPDATE `quest_template_addon` SET `RequiredMinRepFaction`=730, `RequiredMinRepValue`=9000 WHERE `ID`=7169;
UPDATE `quest_template_addon` SET `RequiredMinRepFaction`=730, `RequiredMinRepValue`=21000 WHERE `ID`=7170;
UPDATE `quest_template_addon` SET `RequiredMinRepFaction`=730, `RequiredMinRepValue`=42000 WHERE `ID`=7171;
UPDATE `quest_template_addon` SET `RequiredMinRepFaction`=730, `RequiredMinRepValue`=42999 WHERE `ID`=7172;

DELETE FROM `quest_template_addon` WHERE `ID`=7165;
INSERT INTO `quest_template_addon` (`ID`, `PrevQuestID`, `RequiredMinRepFaction`, `RequiredMinRepValue`) VALUES
(7165, 7164, 729, 21000);
