-- In A Scrap With The Legion (quest ID 10232): add missing end half of RewardText
UPDATE `quest_offer_reward`
 SET `RewardText`="Well, that's good and bad news, now isn't it? We've dealt them a blow, but with the Burning Legion running free all over the Netherstorm - and getting closer to us here - well, I don't know how it's going to go.$B$BI have a feeling that we're going to have to change gears here for a while. Hope you'll be able to help us out, $N."
 WHERE `Id`=10232;
