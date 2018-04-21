-- 
DELETE FROM `npc_text` WHERE `ID` IN (18228,18377,21709);
INSERT INTO `npc_text` (`ID`, `text0_0`, `BroadcastTextID0`, `Probability0`, em0_0) VALUES 
(18228, "The Scryer's Tier has a library devoted to training professions.$b$bYou will find the knowledge you seek in the Seer's Library.",52855, 1, 1),
(18377, "I'm afraid Gunny didn't make it, $n.",53446, 1,18),
(21709, "Sorry, I have to set a broken leg on a baby dragon. Can you come back in a few minutes?",49490, 1, 0);
