-- Master Shang Xi should bow when quest "The Disciple's Challenge(29409)" is completed.
-- Doesn't really work right but better than nothing?
UPDATE `quest_template` SET `OfferRewardEmote1` = '1' , `OfferRewardEmote2` = '2' WHERE`Id` = '29409' ;
