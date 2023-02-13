-- those ones haven't any record
DELETE FROM `quest_offer_reward` WHERE `ID` IN(24547, 24548, 24549, 24580 ,24582, 24583, 24588, 24590, 24748, 24749, 24756, 24757);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(24547, 0, 0, 0, 0, 0, 0, 0, 0, "<Highlord Mograine eyes you in silence for a moment.>$b$bYou seem to have endured this leg of your trial admirably, $r.$b$bPray that fate continues to smile upon you in your endeavor...", 0),-- A Feast of Souls (24547)
(24548, 0, 0, 0, 0, 0, 0, 0, 0, "These should suffice, $c.$b$bSpeak to me when Shadow's Edge has been thoroughly empowered and I will attempt its completion.", 0),-- The Splintered Throne (24548)
(24549, 0, 0, 0, 0, 0, 0, 0, 0, "Congratulations, $c.$b$bAgainst insurmountable odds, you have weathered the storm.$b$bI trust that you shall find your reward proportionate to your conviction...", 0),-- Shadowmourne... (24549)
(24580, 0, 0, 0, 0, 0, 0, 0, 0, "Word of your success precedes you, $c. Anub'Rekhan is no more. You did him a great service, $N.", 0),-- Anub'Rekhan Must Die! (24580)
(24582, 0, 0, 0, 0, 0, 0, 0, 0, "Well done, $c. The Scourge military command out of Naxxramas has been thrown into disarray by Razuvious's demise.", 0),-- Instructor Razuvious Must Die! (24582)
(24583, 0, 0, 0, 0, 0, 0, 0, 0, "Children everywhere will sleep easier knowing that Patchwerk is no more.", 0),-- Patchwerk Must Die! (24583)
(24588, 0, 0, 0, 0, 0, 0, 0, 0, "The greatest weakness of Ulduar is its masters' blind faith in their inventions to protect it.", 0),-- XT-002 Deconstructor Must Die! (24588)
(24590, 0, 0, 0, 0, 0, 0, 0, 0, "The Frozen Throne is without its chief guardian thanks to you. Our attacks upon the Lich King's forces will be all the more successful now.", 0),-- Lord Marrowgar Must Die! (24590)
(24748, 0, 0, 0, 0, 0, 0, 0, 0, "So, at last it is done.$b$bMay the people of Azeroth remember our deeds here forevermore. May the sacrifices of so many burn in their hearts eternally. May they never fail to risk mortal peril in the face of great evil.", 0),-- The Lich King's Last Stand (24748)
(24749, 0, 0, 0, 0, 0, 0, 0, 0, "Well done, $c.$b$bThe completion of our work draws near.", 0),-- Unholy Infusion (24749)
(24756, 0, 0, 0, 0, 0, 0, 0, 0, "Well done, $c.$b$bShadowmourne is nearly within reach.", 0),-- Blood Infusion (24756)
(24757, 0, 0, 0, 0, 0, 0, 0, 0, "The axe has drunk its fill, $r, and the forge is nearly ready for the creation of Shadowmourne...", 0);-- Frost Infusion (24757)

-- Sartharion Must Die! (24579)
UPDATE `quest_offer_reward` SET `RewardText`="With Sartharion slain, surely Deathwing and Sinestra's plans are now stalled." WHERE `ID`=24579;
