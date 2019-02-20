-- DB/Quest: Call the Headless Horseman
UPDATE `quest_offer_reward` SET `RewardText` = 'Will you lay the candle down and call the Headless Horseman from his doomed rest?' WHERE `ID` = 11405;
UPDATE `quest_request_items` SET `CompletionText` = 'This dirt has been recently disturbed. Earthworms lie in the topsoil, squirming to escape the dark depths beneath them.' WHERE `ID` = 11405;
