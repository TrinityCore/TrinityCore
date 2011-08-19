-- Remove watch flag (1) from characters that are watching a faction from the opposing team
-- since r5857, these factions will no longer be flagged for watching if they are from the opposing team
-- all we need to do is clean up the data from when it was still bugged.
-- NOTE: running this may take a while depending on the size of your character database
UPDATE `character_reputation` SET `flags` = `flags` &~ 1 WHERE `guid` IN (SELECT `guid` from `characters` WHERE `race` IN(3,7,1,4,11)) AND `faction` IN(1052,1067,1124,947);
UPDATE `character_reputation` SET `flags` = `flags` &~ 1 WHERE `guid` IN (SELECT `guid` from `characters` WHERE `race` IN(2,6,8,5,10)) AND `faction` IN(1126,946,978);
