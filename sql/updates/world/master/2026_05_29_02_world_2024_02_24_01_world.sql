-- CompletionText
UPDATE `quest_request_items` SET `CompletionText`= '$BThe "Holly Preserver" machine looks like some sort of still at first, but a careful examination of it reveals some goblin-esque changes to it.  Still, your skill at cooking seems to allow you to understand how the machine works.$B$BThere is already fresh holly in the machine - you simply need to provide some deeprock salt and five gold coins to get the machine working.' WHERE `ID` IN (8763, 8799);

-- reward entries
DELETE FROM `quest_offer_reward` WHERE `ID` IN (8763, 8799);
INSERT INTO `quest_offer_reward` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`RewardText`,`VerifiedBuild`) VALUES
(8763,0,0,0,0,0,0,0,0,"$BThe machine lets off a little rumble and a small amount of steam as it starts working.$B$BIt is not too long thereafter until it stops, heralded by another small jet of steam erupting from it.$B$BA door hatch opens, revealing a batch of preserved holly!$B",12340),
(8799,0,0,0,0,0,0,0,0,"$BThe machine lets off a little rumble and a small amount of steam as it starts working.$B$BIt is not too long thereafter until it stops, heralded by another small jet of steam erupting from it.$B$BA door hatch opens, revealing a batch of preserved holly!$B",12340);
