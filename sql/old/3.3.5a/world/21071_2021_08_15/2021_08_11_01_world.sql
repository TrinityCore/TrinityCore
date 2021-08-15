--
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6644; -- Favor Amongst the Brotherhood, Lava Core
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6642; -- Favor Amongst the Brotherhood, Dark Iron Ore
UPDATE `quest_offer_reward` SET `Emote3`=1 WHERE `ID`=3385; -- The Undermarket
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=7737; -- Gaining Even More Acceptance
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=13662; -- Gaining Acceptance
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=8241; -- Restoring Fiery Flux Supplies via Iron
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=8242; -- Restoring Fiery Flux Supplies via Heavy Leather
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=7736; -- Restoring Fiery Flux Supplies via Kingsblood
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=3462; -- Squire Maltrake
UPDATE `quest_offer_reward` SET `Emote2`=1 WHERE `ID`=3453; -- The Torch of Retribution
UPDATE `quest_offer_reward` SET `Emote2`=1 WHERE `ID`=3452; -- The Flame's Casing
UPDATE `quest_offer_reward` SET `Emote1`=0 WHERE `ID`=7722; -- What the Flux?
UPDATE `quest_offer_reward` SET `Emote1`=0 WHERE `ID`=7702; -- Kill 'Em With Sleep Deprivation
UPDATE `quest_offer_reward` SET `Emote2`=1, `Emote3`=1, `EmoteDelay1`=1000, `EmoteDelay2`=500 WHERE `ID`=3442; -- The Flawless Flame
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=21 WHERE `ID`=7728; -- STOLEN: Smithing Tuyere and Lookout's Spyglass
UPDATE `quest_offer_reward` SET `Emote1`=0 WHERE `ID`=7729; -- JOB OPPORTUNITY: Culling the Competition
UPDATE `quest_offer_reward` SET `Emote1`=0 WHERE `ID`=3441; -- Divine Retribution

UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=3368; -- Suntara Stones
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=3385; -- The Undermarket
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=13662; -- Gaining Acceptance
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=4449; -- Caught!
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=8242; -- Restoring Fiery Flux Supplies via Heavy Leather
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=7702; -- Kill 'Em With Sleep Deprivation
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=3442; -- The Flawless Flame

UPDATE `creature_template` SET `npcflag`=0 WHERE `entry`=7865; -- Wildhammer Sentry
UPDATE `creature_template` SET `npcflag`=0 WHERE `entry`=2602; -- Ruul Onestone
UPDATE `creature_template` SET `minlevel`=8 WHERE `entry`=2326; -- Thamner Pol
UPDATE `creature_template` SET `ManaModifier`=1 WHERE `entry`=2602; -- Ruul Onestone

UPDATE `page_text` SET `VerifiedBuild`=12340 WHERE `ID`=1556; -- 1556
UPDATE `page_text` SET `VerifiedBuild`=12340 WHERE `ID`=1554; -- 1554
UPDATE `page_text` SET `VerifiedBuild`=12340 WHERE `ID`=1553; -- 1553
UPDATE `page_text` SET `VerifiedBuild`=12340 WHERE `ID`=1552; -- 1552
UPDATE `page_text` SET `VerifiedBuild`=12340 WHERE `ID`=1551; -- 1551
