DELETE FROM `creature_formations` WHERE `memberGUID` NOT IN (SELECT `guid` FROM `creature`);
