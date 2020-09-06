-- Adjust reputation amount given after killing members of Gelkis / Magram Clan Centaur
-- +20 and -100 instead of +100 and -500
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 20, `RewOnKillRepValue2` = -100 WHERE `RewOnKillRepFaction1` IN (92,93);
