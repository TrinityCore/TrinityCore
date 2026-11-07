-- Cleaning up the Grounds (8894)
UPDATE `quest_offer_reward` SET `RewardText`="Well, I suppose that will have to do, now won't it? Thanks for the help, $c. I can only hope to get this mess completely cleaned up before the Magister returns to Duskwither Spire.$B$BTake this pocket change; it's not much but it's all that I have at the moment. Feel free to dispatch a few more of the beasties on your way out, if you'd be so kind." WHERE `ID`=8894;

-- Wretched Ringleader (9076)
UPDATE `quest_offer_reward` SET `RewardText`="You defeated him after all!  Undoubtedly my men softened him up for you.$B$BI jest, $c.  You've done well.  You'll make a name for yourself if you keep your nose clean." WHERE `ID`=9076;

-- Captain Kelisendra's Lost Rutters (8887)
UPDATE `quest_request_items` SET `CompletionText`="Hello, $c, you're a sight for sore eyes. I know, it's crazy for me to be here, what with the anchorage overrun by the Wretched. Velendris and his rangers have sworn to protect me on the condition that I get out of here as soon as I've recovered my cargo.$B$BWhat's that you have there... it looks vaguely familiar?" WHERE `ID`=8887;
UPDATE `quest_offer_reward` SET `RewardText`="Oh you sweet, sweet $c! I had no idea that those disgusting Grimscale murlocs had also pirated away with my navigation rudders! Without them, I would have no chance of navigating the seas again once we retake the anchorage and repair the ship.$B$BThank you very much! Here, take this coin as a sign of my appreciation." WHERE `ID`=8887;
