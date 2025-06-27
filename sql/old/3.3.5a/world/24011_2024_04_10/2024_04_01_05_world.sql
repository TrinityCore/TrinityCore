-- Returning the Lost Satchel
UPDATE `quest_offer_reward` SET `Emote1`=2,`Emote2`=1 WHERE `ID`=5724;

-- Searching for the Lost Satchel
UPDATE `quest_details` SET `Emote2`=1 WHERE `ID`=5722;

-- The Barrens Oases
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=886;

-- Rites of the Earthmother
UPDATE `quest_offer_reward` SET `Emote2`=21 WHERE `ID`=776;

-- A Sacred Burial
UPDATE `quest_request_items` SET `EmoteOnComplete`=5 WHERE `ID`=833;

-- The Ravaged Caravan
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=749;

-- Kyle's Gone Missing!
UPDATE `quest_details` SET `Emote1`=5,`Emote2`=1,`Emote3`=1,`Emote4`=1 WHERE `ID`=11129;
UPDATE `quest_request_items` SET `EmoteOnComplete`=6,`EmoteOnIncomplete`=6 WHERE `ID`=11129;
UPDATE `quest_offer_reward` SET `Emote1`=4,`Emote2`=1,`Emote3`=1 WHERE `ID`=11129;

-- Dangers of the Windfury
UPDATE `quest_details` SET `Emote1`=2,`Emote3`=1 WHERE `ID`=743;
